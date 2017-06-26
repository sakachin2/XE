//*CID://+va9ER~:                             update#=  281;       //+va9ER~
//***********************************************************
//* xads : access NTFS alternative data stream
//***********************************************************
//va9E:160404 compiler warning win64                               //+va9EI~
//va9p:150529 xads v1.1 parm count error(by xuerpck)               //~va9pI~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va2g:060422 xads:1.0 ADS access tool(New)                        //~va2gI~
//***********************************************************

#define VER "V1.1"   //version                                     //~va9pR~
#define PGM "xads"

//**********************************************/
//*parm  :/l[s] dir/file/wildcard                      list all ads name and size to stdout
//        /r[s] dir/file/wildcard  [out-dir/out-file]  read ads and write to file/stdout
//*       /w[f] dir/file/wildcard  ["text"/file]       update ads from text/file
//*       s:subdir process
//*r.c   : 0 :normal,else err
//**********************************************/
//*
#include <windows.h>
#include <dos.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

//*********************************************************************
#include <ulib.h>
#include <ufile.h>
#include <uerr.h>
#include <ualloc.h>
#include <ufile4.h>
#include <ustring.h>
#include <uedit.h>
#include <uque.h>
#include <ucalc2.h>
#include <ucvucs.h>
#include <utrace.h>
//*********************************************************************
#define HELPMSG         uerrhelpmsg(stdout,stderr,
#define MAXDEPTH        256
#define MAXSTDOLEN     1024     //limit count of ads output to stdout
#define STREAMTYPEDATA ":$DATA"

typedef struct _PARMFNMSTACK{                        //file hdr
                           	UQUEE     PFNqelem;
                    	   	char      PFNname[_MAX_PATH];
                         	}  PARMFNMSTACK,  *PPARMFNMSTACK;
#define PARMFNMSTACKSZ (sizeof(PARMFNMSTACK))

typedef struct _ADSINFO{                        //file hdr
                        UQUEE     ADSIqelem;
                    	DWORD     ADSIszhigh;
                    	DWORD     ADSIszlow;
                    	int       ADSIstreamnamelen;
                    	char      ADSIstreamname[1];
                }  ADSINFO,*PADSINFO;
#define ADSINFOSZ (sizeof(ADSINFO))
//*********************************************************************
static char *Spgm=PGM,*Sver=VER;
static int Soper=0;        //L/R/W
static int Sparmopt=0;
#define  PARM_SUBDIR           0x01
#define  PARM_TEXTSTRING       0x02
#define  PARM_NOLIMIT          0x04  //limit to output to stdout
#define  PARM_1DIR           0x0100
#define  PARM_1ROOT          0x0200
#define  PARM_1WILD          0x0400
#define  PARM_1WRITENEW      0x0800
#define  PARM_1ADS           0x1000
#define  PARM_2DIR         0x010000
#define  PARM_2ROOT        0x020000
#define  PARM_2WRITESTDO   0x080000

static char *Sparm1,*Sparm2;
static int   Sdepth=1;
static int Sadscount=0,Ssearchcount=0,Serrcount=0;
static DWORD Stotadsszhigh=0,Stotadsszlow=0;
static FILE *Sfhout;

//************************************
void parmchk(int,char *[]);
int chkfiletype(char *Pfnm,char *Pfpath);
void help(void);
void optionerr(char *type,char* value);
int editdwnum(int Popt,DWORD Phigh,DWORD Plow,char *Pnumstr,int Poutlen);
int writeads(char *Padsname,char *Psrc);
int dirproc(void);
int getads(char *Pbasename,char *Poutdir,PADSINFO Ppadsi);
int enumads(char *Pfnm,UQUEH *Ppqhadsi);
int getadscb(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,
                                int Pdepth,void *Pdata,int *Prc);
int pathrep(char *Poutpath,char *Pinppath);
int repcolon(char *Pinp,char *Pout);
int readads(char *Pstream,char *Poutfnm,FILE *Pfh,int Pmaxlen,DWORD *Pszhigh,DWORD *Pszlow);

//*********************************************************************
//main
//*********************************************************************
int main(int parmc,char *parmp[])
{
	int rc;
//************************
    parmchk(parmc,parmp);
    if (Soper=='W')		//write ADS
    	rc=writeads(Sparm1,Sparm2);
    else
    	rc=dirproc(); 		//walk dir for List/Read
//  printf("%s:%s:==%c== End of '%c' process for %s ==\n",Spgm,Sver,OSTYPE,Soper,Sparm1);
    return rc;
}//end main
//*********************************************************************
//*dirwalk for List/Read ADS
//*********************************************************************
int dirproc(void)
{
    int dwopt,rc,applrc;
    int pathlen;
    char dirmask[_MAX_PATH];
    char editwk[20];	//terabyte size
//**********************************
//*navigate
	if (Sparmopt & PARM_1WILD && Sdepth==0)
    	Sdepth=1;
	if (!(Sparmopt & PARM_1DIR) || Sdepth==0)	//not dir or chk dir itself
    {
    	if (Sparmopt & PARM_1ADS)	//ads name specified
			return getads(Sparm1,Sparm1,0);
		rc=getadscb(Sparm1,Sparm1,0,0,0,&rc);
    }
    else
    {
        dwopt=UDIRWALK_NOMSG            //no err msg
                |UDIRWALK_DIRCALL       //callback by each dir
                |UDIRWALK_FILECALL      //callback by each file
                |UDIRWALK_SORT_NAME     //sort by name
                ;
        pathlen=PATHLEN(Sparm1);
        if (WILDCARD(Sparm1+pathlen))
        {
            strcpy(dirmask,Sparm1+pathlen); //without \\;
            *(Sparm1+pathlen)=0;                //drop wildcard
            if (!ROOTDIR(Sparm1))
                *(Sparm1+pathlen-1)=0;          //drop \\;
            dwopt|=UDIRWALK_TOPMASK;      //select dir only for top level
        }
        else
            *dirmask=0;
//printf("dirwalk parm1=%s,mask=%s\n",Sparm1,dirmask);
        rc=udirwalk(dwopt,
                        Sparm1,           //top dirname
                        dirmask,         //dir mask (top dir only)
                        "",              //file mask
                        FILE_ALL,       //attr mask
                        Sdepth,          //stop depth,half max
                        getadscb,       //callback function
                        0,              //user data
                        &applrc);
    }
	editdwnum(1,Stotadsszhigh,Stotadsszlow,editwk,sizeof(editwk));//right justify
    printf("\n%d ADS found out of %d file/dir. error=%d,total size=%s.\n",
    		Sadscount,Ssearchcount,Serrcount,editwk);
    return rc;
}//dirproc
//**********************************************************************
//* callback from dirwalk for List/Read
//*  parm1:dir name
//*  parm2:fullpathname,0 if dir entry,or empty call
//*  parm3:PUDIRLIST,0 if empty entry
//*  parm4:depth
//*  parm5:appl data
//*  parm6:appl rc area
//*  return:0:continue walk,else stop walk
//**********************************************************************
int getadscb(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,
                                int Pdepth,void *Pdata,int *Prc)
{
    int rc,adsctr;
    char *fnm;
    UQUEH qhadsi;
    PADSINFO padsi;
    char editwk[20];
//static Swildtopskip=0;                                           //~va66R~
static int Swildtopskip=0;                                         //~va66I~
//**************************
    if (Sparmopt & PARM_1WILD)
	    if (!Swildtopskip)   //1st entry
        {
        	Swildtopskip=1;
            return 0;
        }
	Ssearchcount++;
	if (Pfullpath) //file entry
    	fnm=Pfullpath;
    else
    {
    	fnm=Pdir;
    }
//printf("cb fpath=%s,dir=%s\n",Pfullpath,Pdir);
    memset(&qhadsi,0,sizeof(qhadsi));
    rc=enumads(fnm,&qhadsi);
    if (rc)
    {
    	Serrcount++;
        return 0;
    }
    adsctr=UGETQCTR(&qhadsi);
    if (!adsctr)
        return 0;
    Sadscount+=adsctr;
    for (padsi=UGETQTOP(&qhadsi);padsi;padsi=UGETQNEXT(padsi))
    {
    	DWORD_ADD(Stotadsszhigh,Stotadsszlow,padsi->ADSIszhigh,padsi->ADSIszlow);
    	if (Soper=='R')
        {
        	rc=getads(fnm,Sparm2,padsi);
            if (rc)
		    	Serrcount++;
        }
        else
        {
			editdwnum(1,padsi->ADSIszhigh,padsi->ADSIszlow,editwk,sizeof(editwk));//right justify
            printf("[%s] %s%s\n",editwk,fnm,padsi->ADSIstreamname);
        }
    }
    uqufree(&qhadsi);
	return 0;			//continue walk
}//getadscb
//**********************************************************************
//*enumerate stream name
//*rc:rc
//**********************************************************************
int enumads(char *Pfnm,UQUEH *Ppqhadsi)
{
    HANDLE  hStream;
    WIN32_STREAM_ID *psid;
    ULONG context=0;	//kept for backup loop
    DWORD hdrsz,readlen,totreadhigh=0,totreadlow=0,streamidlen;
    DWORD seekhigh,seeklow;
    PADSINFO padsinfo;
    char buff[_MAX_PATH+_MAX_PATH];
    char sjisname[_MAX_PATH];
    int rc=0,chklen,sjisnamelen,errctr,fnmlen;
//*************************
//UTRACEP("enum of %s\n",Pfnm);
	fnmlen=strlen(Pfnm);
    memset(Ppqhadsi,0,sizeof(UQUEH));	//output que clear
    hStream=CreateFile(Pfnm,
						GENERIC_READ,	//read/write
                        FILE_SHARE_READ,	//share mode ,allow read share
						NULL,				//security
						OPEN_EXISTING,      //fail if not exist
                        FILE_FLAG_BACKUP_SEMANTICS, //attr/flag ,open for backup/restore
						NULL);				//template handle
    if (hStream==INVALID_HANDLE_VALUE)
    {
    	uerrmsg("enum ADS:%s open failed,rc=%d.",0,
					Pfnm,GetLastError());
        return 4;
    }
    hdrsz=offsetof(WIN32_STREAM_ID,cStreamName);
//  psid=(WIN32_STREAM_ID*)(ULONG)buff;                            //~va66R~
    psid=(WIN32_STREAM_ID*)(ULPTR)buff;                            //~va66I~
    for (;;)
    {
    	rc=BackupRead(hStream,
						buff,
						hdrsz,
                        &readlen,
						FALSE,        //Abort BackupRead
						FALSE,        //ACL process
//						(void*)(ULONG)(&context));                 //~va66R~
						(void*)(ULPTR)(&context));                 //~va66I~
//UTRACEP("hdr read rc=%d,readlen=%d/%d\n",rc,readlen,hdrsz);
//UTRACED("hdr",buff,hdrsz);
        if (!readlen)	//eof
        {
        	rc=0;
            break;
        }
        if (!rc||readlen!=hdrsz)    //failed
        {
            uerrmsg("enum ADS:%s header read failed at offset(high-low) x\"%08x-%08x\",rc=%d\n",0,
//  				Pfnm,totreadhigh,totreadlow);                  //~va9pR~
    				Pfnm,totreadhigh,totreadlow,rc);               //~va9pI~
            rc=4;
            break;
        }
        DWORD_ADD(totreadhigh,totreadlow,0,readlen);
//UTRACEP("streamidlen=%d,streamsz=%08x-%08x\n",psid->dwStreamNameSize,psid->Size.HighPart,psid->Size.LowPart);
		streamidlen=psid->dwStreamNameSize;
        if (streamidlen)
        {
        	rc=BackupRead(hStream,
							buff+hdrsz,
							streamidlen,
                            &readlen,
							FALSE,        //Abort BackupRead
							FALSE,        //ACL process
//							(void*)(ULONG)(&context));             //~va66R~
							(void*)(ULPTR)(&context));             //~va66I~
            if (!rc||readlen!=streamidlen)    //failed
            {
                uerrmsg("enumADS:%s header stream name read failed at offset(high-low) x\"%08x-%08x\",rc=%d\n",0,
//                      Pfnm,totreadhigh,totreadlow);              //~va9pR~
                        Pfnm,totreadhigh,totreadlow,rc);           //~va9pI~
                rc=4;
                break;
            }
	        DWORD_ADD(totreadhigh,totreadlow,0,readlen);
//UTRACED("name",buff+hdrsz,readlen);
			ucvsucs2sjis(0,UCVUCS_LE,buff+hdrsz,streamidlen,sjisname,sizeof(sjisname),&chklen,&sjisnamelen,&errctr);
                        //convert from ucs to sjis;Name is of the format ":NAME:$DATA\0"
            if (sjisnamelen>6 && !memcmp(sjisname+sjisnamelen-6,STREAMTYPEDATA,6))
            {
            	sjisnamelen-=6;
            	*(sjisname+sjisnamelen)=0;
            }
//enq adsinfo
            padsinfo=ucalloc(1,ADSINFOSZ+sjisnamelen);
            padsinfo->ADSIszhigh=psid->Size.HighPart;
            padsinfo->ADSIszlow=psid->Size.LowPart;
            padsinfo->ADSIstreamnamelen=sjisnamelen;
            memcpy(padsinfo->ADSIstreamname,sjisname,(UINT)sjisnamelen);
//UTRACEP("streamname=%s\n",padsinfo->ADSIstreamname);
            UENQ(UQUE_END,Ppqhadsi,padsinfo);
        }//contain streamid

        if (psid->Size.LowPart||psid->Size.HighPart)
        {
            rc=BackupSeek(hStream,
                            psid->Size.LowPart,
                            psid->Size.HighPart,
                            &seeklow,
                            &seekhigh,
//                          (void*)(ULONG)(&context));             //~va66R~
                            (void*)(ULPTR)(&context));             //~va66I~
            if (!rc)
            {
                uerrmsg("enumADS:%s seek failed at offset(high-low) x\"%08x-%08x\", seeksize=%08x-%08x;rc=%d\n",0,
                        Pfnm,totreadhigh,totreadlow,psid->Size.HighPart,psid->Size.LowPart,GetLastError());
                rc=4;
                break;
            }
	        DWORD_ADD(totreadhigh,totreadlow,0,readlen);
        }
    }//until eof
    CloseHandle(hStream);
    return rc;
}//enumstream
//**********************************************************************
//*setup for ads copy
//*p1:basename or adsname(for Read parm1 is adsname case)
//*p2:out dir name , "" if stdout
//*p3:enum info or 0 if p1 is adsname
//*rc:rc
//**********************************************************************
int getads(char *Pbasename,char *Poutdir,PADSINFO Ppadsi)
{
    int rc=0,orgpathlen,len,readmax=0;
    char adsname[_MAX_PATH+_MAX_PATH];
    char outfnm[_MAX_PATH+_MAX_PATH];
    char streamname[_MAX_PATH],*pc;
    DWORD szhigh,szlow;
    char hdrline[80+_MAX_PATH];
    char editwk[20];	//terabyte size
    FILE *fhout;
//*************************
	orgpathlen=PATHLEN(Sparm1);
	strcpy(adsname,Pbasename);
	if (Ppadsi)	//basename!=adsname
    {
        pc=Ppadsi->ADSIstreamname;
    	strcat(adsname,pc);
    }
    else
    {
        pc=strchr(Pbasename+2,':');
     	if (!pc)
        	return 4;
	}
    if (repcolon(pc,streamname))       //replace ":" to ".."
    	uerrmsg("stream name is invalid as filename;output filename ajusted(%s).",0,
 				streamname);
    if (Sparmopt & PARM_2WRITESTDO)
    {
    	fhout=stdout;
        strcpy(outfnm,"stdout");
        if (!(Sparmopt & PARM_NOLIMIT))
        	readmax=MAXSTDOLEN;
    }
    else
    {
        if (Sparmopt & PARM_2DIR) //output to dir
        {
            len=strlen(Poutdir);
            memcpy(outfnm,Poutdir,len);
            if (!(Sparmopt & PARM_2ROOT))   //output to dir
                *(outfnm+len++)='\\';
            pathrep(outfnm+len,Pbasename+orgpathlen);    //replace path seperator \ to .
            strcat(outfnm,streamname);
        }
        else        //output to file
            strcpy(outfnm,Poutdir);
        fhout=Sfhout;
        if (!fhout)
        {
            fhout=fopen(outfnm,"wb");
            if (!fhout)
            {
                uerrmsg("output file open failed(%s),rc=%d.",0,
                            outfnm,errno);
                return 4;
            }
            Sfhout=fhout;
        }
    }
    if (!(Sparmopt & PARM_2DIR)) //output to dir
    {
    	if (Ppadsi)	//parm1 is not adsname
        {
			editdwnum(1,Ppadsi->ADSIszhigh,Ppadsi->ADSIszlow,editwk,sizeof(editwk));//right justify
            len=sprintf(hdrline,"\n[%s] %s\n",editwk,adsname);
        	fwrite(hdrline,1,len,fhout);
        }
    }
	rc=readads(adsname,outfnm,fhout,readmax,&szhigh,&szlow);
    if (Sparmopt & PARM_2DIR) //output to dir
    {
    	Sfhout=0;
        fclose(fhout);
    }
    return rc;
}//getads
//**********************************************************************
//*copy stream to normal file
//*rc:rc
//**********************************************************************
int readads(char *Pstream,char *Poutfnm,FILE *Pfh,int Preadmax,DWORD *Pszhigh,DWORD *Pszlow)
{
#define BUFFSZ 65536
    HANDLE  hStream;
    DWORD outlen,readlen,writelen,totreadhigh=0,totreadlow=0,totwritehigh=0,totwritelow=0;
    char buff[BUFFSZ];
    int rc=0,outlimitsw=0;
//*************************
    hStream=CreateFile(Pstream,
                       GENERIC_READ, 	//access mode read/write
                       FILE_SHARE_READ,  //share mode,allow read share
                       NULL,       		 //security
                       OPEN_EXISTING,   //fail if not exist
                       0,                //file attr and flag
                       NULL );          //template file handle
    if (hStream==INVALID_HANDLE_VALUE)
    {
    	uerrmsg("%s open failed,rc=%d.",0,
					Pstream,GetLastError());
        return 4;
    }
    for (;;)
    {
        rc=ReadFile(hStream,
                    buff,
                    sizeof(buff),
                    &readlen,
                    NULL);  //overwrap(async read)
        if (!rc)    //failed
        {
            uerrmsg("%s read failed at offset(high-low)=x\"%08x-%08x\",rc=%d.",0,
                        Pstream,totreadhigh,totreadlow,GetLastError());

			rc=4;
            break;
        }
        DWORD_ADD(totreadhigh,totreadlow,0,readlen);
        if (!outlimitsw)
        {
        	if (Preadmax && totwritelow+readlen>(UINT)Preadmax)
            {
            	outlimitsw=1;
                outlen=Preadmax-totwritelow;
            }
            else
            	outlen=readlen;
            writelen=fwrite(buff,1,outlen,Pfh);
            DWORD_ADD(totwritehigh,totwritelow,0,outlen);
            if (writelen!=outlen)
            {
                uerrmsg("Write to %s failed at offset(high-low)=x\"%08x-%08x\",rc=%d.",0,
                            Poutfnm,totwritehigh,totwritelow,GetLastError());
                rc=4;
                break;
            }
            if (outlimitsw)
            	uerrmsg("\nstdout output is stopped by limit of %d,use /F option to full output",
                		"\n標準出力への出力は%d までです、全部出力する場合は/F オプションを指定してください。",
						Preadmax);
        }
        if (!readlen)	//eof
        {
        	rc=0;
        	break;
        }
    }
    CloseHandle(hStream);
    *Pszhigh=totwritehigh;
    *Pszlow=totwritelow;
    return rc;
}//readads
//**********************************************************************
//*copy stream to normal file
//*rc:rc
//**********************************************************************
int writeads(char *Padsname,char *Psrc)
{
#define BUFFSZ 65536
    HANDLE  hStream;
    FILE   *fhinp;
    DWORD textlen,readlen,writelen,totwritehigh=0,totwritelow=0;
    char buff[BUFFSZ];
    char editwk[20];	//terabyte size
    int rc=0;
//*************************
    hStream=CreateFile(Padsname,
                       GENERIC_WRITE, 	//access mode read/write
                       FILE_SHARE_READ,  //share mode,allow read share
                       NULL,       		 //security
                       OPEN_ALWAYS,      //create if not exist
                       0,                //file attr and flag
                       NULL );          //template file handle
    if (hStream==INVALID_HANDLE_VALUE)
    {
    	uerrmsg("writeADS:%s open failed,rc=%d.",0,
					Padsname,GetLastError());
        return 4;
    }
    if (Sparmopt & PARM_TEXTSTRING)	//write text string
    {
		textlen=strlen(Psrc);  //request size
    	rc=WriteFile(hStream,
						Psrc,
						textlen,  //request size
						&writelen,  //written size
						NULL);		//overwrap
//printf("write text rc=%d len=%d,written=%d\n",rc,textlen,writelen);
        if (!rc)	//failed
        {
            uerrmsg("writeADS:%s text write failed,rc=%d.",0,
                        Padsname,GetLastError());

			rc=4;
        }
        else
        {
        	rc=0;
            DWORD_ADD(totwritehigh,totwritelow,0,textlen);
        }
    }
    else
    {
        fhinp=fopen(Psrc,"rb");
        if (!fhinp)
        {
            uerrmsg("writeADS:%s open failed,rc=%d.",0,
                        Psrc,errno);
            return 4;
        }
        for (;;)
        {
            readlen=fread(buff,1,BUFFSZ,fhinp);
            if (!readlen)
            {
            	rc=0;
            	break;
            }
            rc=WriteFile(hStream,
                            buff,
                            readlen,  //request size
                            &writelen,  //written size
                            NULL);      //overwrap
            if (!rc)    //failed
            {
                uerrmsg("writeADS:%s write failed at offset(high-low)=x\"%08x-%08x\",rc=%d.",0,
                            Padsname,totwritehigh,totwritelow,GetLastError());

                rc=4;
                break;
            }
            DWORD_ADD(totwritehigh,totwritelow,0,readlen);
        }
	    fclose(fhinp);
    }
    CloseHandle(hStream);
	editdwnum(1,totwritehigh,totwritelow,editwk,sizeof(editwk));//right justify
    uerrmsg("Written to ADS:[%s] %s\n",0,
             editwk,Padsname);
    return rc;
}//writeads
//**********************************************************************
//*edit dword number
//**********************************************************************
int editdwnum(int Popt,DWORD Phigh,DWORD Plow,char *Pnumstr,int Poutlen)
{
    ULONG dweditwk[3];
    char  numstr[32];
    int rc,len;
//*******************************
	Poutlen--;	//for last 0
    dweditwk[0]=Phigh;
	dweditwk[1]=0;
    dweditwk[2]=Plow;
//  bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,dweditwk,numstr);  //~va64R~
    bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,(long*)dweditwk,numstr);//~va64I~
    len=strlen(numstr);
    if (len<Poutlen)
    {
    	if (Popt & 1)	//right justify
        {
		    memset(Pnumstr,' ',Poutlen-len);
    		memcpy(Pnumstr+Poutlen-len,numstr,len);
	    	*(Pnumstr+Poutlen)=0;
        }
        else
        	strcpy(Pnumstr,numstr);
        rc=0;
    }
    else
    {
    	memcpy(Pnumstr,numstr+len-Poutlen,Poutlen);
    	*(Pnumstr+Poutlen)=0;
        rc=4;	//overflow
    }
    return rc;
}//editdwnum
//**********************************************************************
//*output filename generation(replace path seperator \ by .)
//**********************************************************************
int pathrep(char *Poutpath,char *Pinppath)
{
	char *pc,*pc2,*pco;
    int rc=0,len;
//*******************************
	for (pc=Pinppath,pco=Poutpath;;)
    {
		pc2=ustrchr2(pc,'\\');	//search \ except dbcs 2nd byte
    	if (!pc2)
        {
    	    len=strlen(pc);
        	memcpy(pco,pc,len);
            pco+=len;
        	break;
        }
//      len=(ULONG)pc2-(ULONG)pc;                                  //~va66R~
//      len=(ULPTR)pc2-(ULPTR)pc;                                  //~va66I~//+va9ER~
        len=(int)((ULPTR)pc2-(ULPTR)pc);                           //+va9EI~
        memcpy(pco,pc,len);
        pco+=len;
        *pco++='_';
        *pco++='_';
        pc=pc2+1;
    }
    *pco=0;
    return rc;
}//pathrep
//**********************************************************************
//*output filename generation(replace path seperator \ by .)
//**********************************************************************
int repcolon(char *Pinp,char *Pout)
{
	char *pc,*pco;
    int rc=0;
//*******************************
	for (pc=Pinp,pco=Pout;*pc;pc++)
    {
		if (*pc==':')
        {
        	*pco++='.';
        	*pco++='.';
        }
        else
            if (*pc<' ')
            {
                *pco++='.';
                rc=4;
            }
            else
	        	*pco++=*pc;
    }
    *pco=0;
    return rc;
}//repcolon
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
static char Sfpath1[_MAX_PATH+_MAX_PATH];	//ADS name
static char Sfpath2[_MAX_PATH];
	char fpathwk[_MAX_PATH];
    unsigned char c;
    char *cptr,*cptr0,*pc;
    int parmno,rc,len;
    int posparmno=0; //parm count work
//*************************
    if (parmc<2 || *parmp[1]=='?')
    {
      	help();
      	exit(0);
    }
//*******************************
//* parm process                *
//*******************************
    for (parmno=1;parmno<parmc;parmno++)
    {
        cptr=cptr0=parmp[parmno];
        if(*cptr=='/')
        {//option
        	for (;;)
            {
                c=*(++cptr);                      //first option byte
                if (!c)
                	break;
                switch(toupper(c))             //option
                {
                case '?':           //cmd string start
                case 'H':           //apply to file
                    help();
                    exit(0);
                    break;
                case 'L':           //apply to file
                    Soper='L';
                    break;
                case 'R':           //apply to file
                    Soper='R';
                    break;
                case 'W':           //apply to file
                    Soper='W';
                    break;
                case 'S':           //apply to file
                	if ((len=unumlen(cptr+1,0,strlen(cptr+1)))>0)
                    {
	                	Sdepth=atoi(cptr+1);
                        cptr+=len;
                    }
                    else
                    	Sdepth=32767;
                    Sparmopt|=PARM_SUBDIR;
                    break;
                case 'T':           //apply to file
                    Sparmopt|=PARM_TEXTSTRING;
                    break;
                case 'F':           //apply to file
                    Sparmopt|=PARM_NOLIMIT;  //limit to output to stdout
                    break;
                case 'Y':           //toggle on
                    for (;;)
                    {
                        c=*(++cptr);
                        if (!c)
                        {
                        	cptr--;
                            break;
                        }
                        switch(toupper(c))
                        {
                        case '9':       //dbcs sw
                            UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                            UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs
                            break;
                        default:                           //not option
                            optionerr("Yes/No option",cptr0);
                        }
                    }
                    break;
                case 'N':           //toggle on
                    for (;;)
                    {
                        c=*(++cptr);
                        if (!c)
                        {
                        	cptr--;
                            break;
                        }
                        switch(toupper(c))
                        {
                        case '9':       //dbcs sw
                            UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                            UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs
                            break;
                        default:                           //not option
                            optionerr("Yes/No option",cptr0);
                        }
                    }
                    break;
                default:                           //not option
                    uerrexit("undefined option parm(%s)\n",
                             "未定義パラメータ(%s)\n",
                              cptr0);
                }//switch  by first option byte
            }
            continue;
		}//option
//pos parm
        posparmno++;
        switch (posparmno)
        {
//**************************
//* top dir                *
//**************************
        case  1:          //first parm
            Sparm1=cptr0;
            break;
        case  2:          //first parm
            Sparm2=cptr0;
            break;
        default:
            uerrexit("too many positional parameter(%s)\n",
                     "多過ぎる の定位置パラメータ(%s)\n",
                     cptr0);
        }//switch by parmno
	}//for all parm
    if (!posparmno)
    	uerrexit("Missing base-name(L/R) not ADS-name(W) parameter\n",
            	 "base-name(L/R)ないしADS-name(W)を指定して下さい");
//combination chk
//printf("op=%c opt=%x\n",Soper,Sparmopt);
	switch(Soper)
    {
    case 'L':       //list
    case 'R':       //read
    	if (Sparmopt & PARM_TEXTSTRING)
	        uerrexit("%cT option is valid only for Write operation\n",
    	             "%cT オプションはWrite操作でのみ有効\n",
				CMDFLAG_PREFIX);
    	break;
    case 'W':
    	if (Sparmopt & PARM_SUBDIR)
	        uerrexit("%cS option is invalid for Write operation\n",
    	             "%cS オプションはWrite操作では無効\n",
				CMDFLAG_PREFIX);
    	break;
    default:
        uerrexit("Missing operation mode(L or R or W)\n",
                 "操作モード(L/W/R)の指定がありません\n");
    }
//1st parameter chk
	switch(Soper)
    {
    case 'L':       //list
    case 'R':       //read
        if (pc=strchr(Sparm1+2,':'),pc)
        {
            if (Soper=='R')
                Sparmopt|=PARM_1ADS;
            else
                uerrexit("ADS name(%s) is not valid for List operation.\n",
                         "ADS名(%s)は List操作では指定できません。",
                        Sparm1);
            *pc=0;           //recover later
        }
        rc=chkfiletype(Sparm1,Sfpath1); //get fullpath and file type
        switch(rc)
        {
        case 1: //not found
	        uerrexit("%s not found.\n",
    	             "%s が見つかりません。",
						Sparm1);
            break;
        case 2: //dir
            Sparmopt|=PARM_1DIR;
            break;
        case 3: //root dir
            Sparmopt|=PARM_1DIR|PARM_1ROOT;
            break;
        case 4: //wildcard
            Sparmopt|=PARM_1DIR|PARM_1WILD;
            break;
        }
        if (pc)                  //adsname
        {
        	*(Sfpath1+strlen(Sfpath1))=':';
            strcat(Sfpath1,pc+1);
        }
        Sparm1=Sfpath1;
        break;
    case 'W':
//path name chk
    	pc=strchr(Sparm1+2,':');
        if (!pc)
            uerrexit("%s has no stream name required for Write operation.\n",
                     "%s にWrite操作で必要なストリーム名の指定がありません。",Sparm1);
//      len=(ULONG)pc-(ULONG)Sparm1;                               //~va66R~
//      len=(ULPTR)pc-(ULPTR)Sparm1;                               //~va66I~//+va9ER~
        len=(int)((ULPTR)pc-(ULPTR)Sparm1);                        //+va9EI~
        len=min(len,sizeof(fpathwk));
        memcpy(fpathwk,Sparm1,(UINT)len);
        *(fpathwk+len)=0;
        if (WILDCARD(fpathwk))		//for the case path not found
            uerrexit("%s is invalid for Write operation(Wildcard).\n",
                     "%s が無効です(Write操作でワイルドカード使用)",Sparm1);
        rc=chkfiletype(fpathwk,Sfpath1); //get fullpath and file type
        switch(rc)
        {
        case 1: //not found
            Sparmopt|=PARM_1WRITENEW;	//write to new file
            break;
        }
        strcat(Sfpath1,pc);	//fpath ADS name
    	break;
    }

    if (ufileisntfs(*Sfpath1)!=1)
        uerrexit("%s is not on NTFS filesystem",
                "%s は NTFS ファイルシステム上にありません。",
                    Sfpath1);

//2nd parameter chk
	switch(Soper)
    {
    case 'L':       //list
    	if (Sparm2)
	    	uerrexit("2nd parameter(%s) is invalid for List operation\n",
    	        	 "第２パラメータ(%s) は List操作では無効です",Sparm2);
    	break;
    case 'R':       //read
        if (!Sparm2)
        	Sparmopt|=PARM_2WRITESTDO;
        else
        {
 	       if (WILDCARD(Sparm2))		//for the case path not found
    	        uerrexit("%s is invalid(Read output is wildcard).\n",
        	             "%s が無効です(Read操作の出力先でワイルドカード使用)",Sparm2);
            rc=chkfiletype(Sparm2,Sfpath2); //get fullpath and file type
            switch(rc)
            {
            case 2: //dir
                Sparmopt|=PARM_2DIR;
                break;
            case 3: //root dir
                Sparmopt|=PARM_2DIR|PARM_2ROOT;
                break;
            case 4: //wildcard
                uerrexit("%s is invalid(Wildcard output of Read operation)\n",
                         "%s が無効です(Read操作の出力先がワイルドカード)",Sparm2);
                break;
            }
        }
    	break;
    case 'W':       //write
        if (!Sparm2)
        	uerrexit("Missing Write source(filename or TextString) specification",
            		"Write操作のソース(ファイル名か文字列)がありません。");
    	if (!(Sparmopt & PARM_TEXTSTRING))
        {
 	       if (WILDCARD(Sparm2))		//for the case path not found
    	        uerrexit("%s is invalid(Write input is wildcard).\n",
        	             "%s が無効です(Write操作の入力元でワイルドカード使用)",Sparm2);
            rc=chkfiletype(Sparm2,Sfpath2); //get fullpath and file type
            switch(rc)
            {
            case 1: //not found
	            uerrexit("%s not found.\n",
    	                 "%s が見つかりません。",Sparm2);
                break;
            case 2: //dir
            case 3: //root dir
	            uerrexit("%s is invaid(Write source is not file).\n",
    	                 "%s が無効です(Write操作のソースがファイルでない)。",Sparm2);
                break;
            }
        }
    	break;
    }
//  printf("parmchk opt=%x\n",Sparmopt);
}//parmchk
//*********************************************************************
//* chk file-spec parm
//* rc:0:file,1:not found;2:dir,3:root dir,4:wildcard
//*********************************************************************
int chkfiletype(char *Pfnm,char *Pfpath)
{
	FILEFINDBUF3 fstat3;
//********************************
	if (!ufullpath(Pfpath,Pfnm,_MAX_PATH))
    	exit(4);
//printf("fpath %s->%s\n",Pfnm,Pfpath);
    if (ROOTDIR(Pfpath))
    	return 3;
    if (ufstat(Pfpath,&fstat3))
    	return 1;
    if (WILDCARD(Pfpath))
    	return 4;
    if (fstat3.attrFile & FILE_DIRECTORY)
    	return 2;
    return 0;    //file
}//chkpath
//**********************************************************************
//* write option err msg  v3.8a
//**********************************************************************
void optionerr(char *type,char* value)
{
        uerrexit("invalid %s option parm value(%s)\n",
                         "%s の値(%s)の誤り\n",
                        type,value);
}//optionerr
//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
//*******************
        HELPMSG
"%s : %s=(%c)= Access to NTFS ADS(Alternative Data Stream).\n",
"%s : %s=(%c)= NTFSファイルシステムのADS(Alternative Data Stream)アクセス。\n",
                Spgm,Sver,OSTYPE);
        HELPMSG
"fmt  : %s [%coptions] {base-name | ADS-name} [ file-spec | \"TextString\"]\n",
"形式 : %s [%coptions] {base-name | ADS-name} [ file-spec | \"TextString\"]\n",
                Spgm,CMDFLAG_PREFIX);
        HELPMSG
"  base-name :file/dir/wildcard of NTFS filesystem for List/Read operation.\n",
"  base-name :List/Read操作でNTFSのファイル/ディレクトリー/ワイルドカード指定。\n");
        HELPMSG
"             Wildcard required for all directory member.\n",
"             ディレクトリーの全メンバーを調べるにはワイルドカード指定が必要。\n");
        HELPMSG
"  ADS-name  :ADS name for Write operation. file-spec:stream-name format.\n",
"  ADS-name  :Write操作の時のADS名。ファイル名:ストリーム名 形式。\n");
        HELPMSG
"  file-spec :input/output file-spec for Read/Write operaetion.\n",
"  file-spec :Read/Write操作の時の入力/出力指定。\n");
        HELPMSG
"  TextString:ADS contents to be written for Write operaetion.\n",
"  TextString:Write操作の時のADS出力内容を直接指定する。\n");
        HELPMSG
"  options   :\n",
"  options   :\n");
        HELPMSG
"     %cL :List all ADS name and size of the directory/file.\n",
"     %cL :List操作。ファイル/ディレクトリーの全ADSの名前とサイズをリストアップ。\n",
				CMDFLAG_PREFIX);
        HELPMSG
"     %cR :Read ADS then write to the file-spec specified. default is stdout.\n",
"     %cR :Read操作。ADSの内容を読みfile-specに書き出す。省略値は標準出力。\n",
				CMDFLAG_PREFIX);
        HELPMSG
"         If output file-spec is directory,member are created for each ADS.\n",
"         file-specがディレクトリーの場合、各ADSに対応してメンバーが作られる。\n",
				CMDFLAG_PREFIX);
        HELPMSG
"     %cW :Write to the ADS from file-spec or TextString.\n",
"     %cW :Write操作。file-specのファイルの内容かTextStringをADSに書き出す。\n",
				CMDFLAG_PREFIX);
        HELPMSG
"         ADS size is not be shorten. (To delete ADS,copy to not NTFS).\n",
"         ADSのサイズは縮小出来ません。(削除するにはNTFS以外にcopyする。)\n",
				CMDFLAG_PREFIX);
        HELPMSG
"     %cT :For Write operation,input is not file-spec but TextString.\n",
"     %cT :Write操作の入力はfile-specでなくTextStringであることの指定。\n",
				CMDFLAG_PREFIX);
        HELPMSG
"     %cSn:n:subdirectory search depth for List/Read.\n",
"     %cSn:n:List/Read操作でのサブディレクトリー探索の深さ。\n",
				CMDFLAG_PREFIX);
        HELPMSG
"         S0:directory itself, S:all descendant. default is S1.\n",
"         S0でそのディレクトリー自身、Sのみは末端まで。省略値はS1。\n",
				CMDFLAG_PREFIX);
        HELPMSG
"     %cF :For Read,write whole of the ADS. for stdout,default limit is %d.\n",
"     %cF :Read操作でADSの全体を出力する。標準出力の場合省略値では%dまで。\n",
				CMDFLAG_PREFIX,MAXSTDOLEN);
        HELPMSG
"ex)%s %cLs0 dir1; %s %crs . outdir; %s %cr d:\\*.doc; %s %cr file1:stream1;\n",
"例)%s %cLs0 dir1; %s %crs . outdir; %s %cr d:\\*.doc; %s %cr file1:stream1;\n",
				Spgm,CMDFLAG_PREFIX,Spgm,CMDFLAG_PREFIX,Spgm,CMDFLAG_PREFIX,Spgm,CMDFLAG_PREFIX);
        HELPMSG
"   %s %cw file1:str1:$DATA doc.txt; %s %cwt file1:str2 \"descriptions\";\n",
"   %s %cw file1:str1:$DATA doc.txt; %s %cwt file1:str2 \"説明文\";\n",
				Spgm,CMDFLAG_PREFIX,Spgm,CMDFLAG_PREFIX);
	return;
}//help
