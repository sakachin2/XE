//CID://+va15R~:                                                   //~va15R~
//*************************************************************
//*xft.c                                                           //~v101R~
//* func call tree list                                            //~v101R~
//*************************************************************
//*va15:031103 xft:v1.1:ftp support(4 byte udirlist attr for ! UNX)//~va15I~
//011019 v103 by xuerpck tool(uerrmsg parm chk)                    //~v103I~
//011018 v102 function to exclude function of DEBUG etc            //~v102R~
//011016 v101 UNX support(no EISOPEN defined)                      //~v101I~
//*************************************************************    //~v101I~
//#define TEST                                                     //~v102R~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
    #ifdef DPMI					//DPMI version
        #include <errno.h>
    #else                       //not DPMI
    #endif                      //DPMI or not
#else
  #ifdef W32
	#include <dos.h>
	#include <windows.h>
  #else
    #include <errno.h>
    #define INCL_BASE
    #include <os2.h>
  #endif
#endif
//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <ufile5.h>
#include <uparse.h>
#include <uedit.h>
#include <ufemsg.h>
#include <ustring.h>
#include <udbcschk.h>

#include "xft.h"
//*******************************************************
    int Gerrsw;
    int Gxftdbcssw;                                                //~0709I~
#define MAX_EXCLUDEFUNC  50                                        //~v102M~
    UCHAR *Gexcludefunc[MAX_EXCLUDEFUNC];                          //~v102I~
    int    Gexcludefuncno=0;                                       //~v102I~
//*******************************************************
static	char Spgmver[16];
#define MAX_FILENM   50                                            //~0708I~
static	UCHAR *Sparmfnm[MAX_FILENM];                               //~0708R~
static int    Sfilenmno=0;                                         //~v101R~
static	UCHAR *Sfuncnm=0;                                          //~v101R~
static  int Suerrmsgopt=0;                                         //~v101R~
static  int Soption=OPT_STMT|OPT_PARCHI|OPT_PMACRO|OPT_DEFMAC|OPT_INDEX1|OPT_PHIGH;//~0720R~
static UCHAR Sbuff[MAXLINEDATA];
#define MAX_EXCLUDE  50                                            //~0708I~
static UCHAR *Sexcludefnm[MAX_EXCLUDE];                            //~0708I~
static int    Sexcludeno=0;                                        //~v101R~
//**********************************
int fileload(UCHAR *Ppfile,PUFILEH *Pppfh);
void parmproc0(int Pparmc,char *Pparmp[]);
void parmproc(int Pparmc,char *Pparmp[]);
int fileproc(UCHAR *Pfnm);
void help(void);
void titlemsg(void);
int filefind(UCHAR *Ppfile,UCHAR *Pfullpath,FILEFINDBUF3 *Ppfstat3,
			 int Pmsgopt);
#define FFMSG   	0
#define FFNONFMSG   1
#define FFNODIRMSG  2

void ufilesetfhfilename(PUFILEH Ppfh,char *Plongname);
int dirload(PUFILEH Ppfh);
int fileclosefree2(PUFILEH Ppfh);
void filefree(PUFILEH Ppfh);
int filegetline(UCHAR *Pfilename,FILE *Phfile,long Pline,PULINEH *Ppplh,
				PUFILEH Ppfh);
FILE *fileopen(UCHAR *Ppfile,UCHAR *Ppopt);
int fileclose(UCHAR *Pfile,FILE* Pfh);
PULINEH filealloclh(UCHAR Ptype,int Pdatalen);
int dirsetdata(UCHAR *Ppathname,PUDIRLIST Ppudirlist,PUFILEH Ppfh);
char *filefullpath(char *Pfullpath,char *Pfilename,size_t Plen);
int filefindopen(UCHAR *Ppfile,UCHAR *Pfullpath,FILEFINDBUF3 *Ppfstat3,
				FILE** Pphfile);
int dirgetlist(PUFILEH Ppfh,UCHAR *Pfilemask,UINT Popt,PUDIRLIST *Pppudirlist);
//*******************************************************
//*main
//*******************************************************
int main(int parmc,char *parmp[])
{
    int ii;                                                        //~0708I~
//****************************
	sprintf(Spgmver,"%s:%s ",PGMID,VERSION);
    Gxftdbcssw=udbcschkcp();                                       //~0709I~
	uerrmsg_init(Spgmver,stdout,0);//msg to stdout
	uerrexit_init(Spgmver,stdout,0,0,0);//stdout only,no pathmsg
	uerrexit_optinit(UERREXIT_BELL);	//force beep from uerrexit
	parmproc0(parmc,parmp);	//get parm from exe parm
	parmproc(parmc,parmp);	//get parm from exe parm
	titlemsg();
    printf("=====  ");                                             //~0722I~
    for (ii=0;ii<parmc;ii++)	//print parm                       //~0722I~
        printf(" %s ",parmp[ii]);                                  //~0722R~
    printf(" =====\n");                                            //~0722R~
    for (ii=0;ii<Sfilenmno;ii++)                                   //~0708I~
		if (fileproc(Sparmfnm[ii]))                                //~0708R~
    		return 4;                                              //~0708R~
	if (setchipar())
    	return 4;
	if (listfunc(Soption,Sfuncnm))
    	return 4;
	titlemsg();
    if (Gerrsw)
        ubell();
	return 0;
}//main
//************************************************
//*get wkdir,ini process parameter
//************************************************
void parmproc0(int Pparmc,char *Pparmp[])
{
	int parmno;
	char *cptr,ch;
//********************
    if (Pparmc==1)
    {
		help();
        exit(1);
    }
	for (parmno=1;parmno<Pparmc;parmno++)
	{
		cptr=Pparmp[parmno];
#ifdef UNX                                                         //~v101I~
	  	if(*cptr=='-')                                             //~v101I~
#else                                                              //~v101I~
	  	if(*cptr=='/'||*cptr=='-')
        #endif                                                     //~v101I~
	  	{//option
	   		ch=*(++cptr);                      //first option byte
	    	if (*(++cptr)==':')               // /o:x format
	      		cptr++;                         //skip :
   			switch(toupper(ch))       //option
	    	{
//**************************
//* terminater   //
//**************************
#ifdef UNX                                                         //~v101I~
	    	case '-':                                              //~v101I~
#else                                                              //~v101I~
	    	case '/':
#endif                                                             //~v101I~
                parmno=Pparmc;  //loop exit
	      		break;
//**************************
//* help msg      /H*
//**************************
	    	case '?':
	    	case 'H':
				help();
	      		exit(4);
	      		break;
//**************************
//* set option     */Y
//**************************
	    	case 'Y':
				while (*cptr)
				{
	    			switch (toupper(*cptr))
    	  			{
	      			case '9':   //japanese errmsg if avail
						Suerrmsgopt=(Suerrmsgopt & ~UERR_FORCE_ENGLISH);
                        Gxftdbcssw=1;                              //~0709I~
	        			break;
	      			case 'T':
						Soption|=OPT_TEST;
	        			break;
	      			}//switch by /Yx
		  			cptr++;
      			}//until strlen
      			break;
//**************************
//* reset option     */N
//**************************
    		case 'N':
		  		while (*cptr)
		  		{
		    		switch (toupper(*cptr))
   		 	  		{
	      			case '9':   //no japanese errmsg(force english)
						Suerrmsgopt=(Suerrmsgopt|UERR_FORCE_ENGLISH);
                        Gxftdbcssw=0;                              //~0709I~
	        			break;
	      			case 'T':
						Soption&=~OPT_TEST;
	        			break;
	      			}//switch by /Nx
		  			cptr++;
      			}//until strlen
      			break;
            }//kwd parm
		}//option
	}//for all parm
	return;
}//parmproc0
//************************************************
//*parameter process
//************************************************
void parmproc(int Pparmc,char *Pparmp[])
{
	int parmno;                                                    //~0708R~
	char *cptr,ch;
//********************
	for (parmno=1;parmno<Pparmc;parmno++)
	{
		cptr=Pparmp[parmno];
	  	if(*cptr=='/'||*cptr=='-')
	  	{//option
	   		ch=*(++cptr);                      //first option byte
	    	if (*(++cptr)==':')               // /o:x format
	      	cptr++;                         //skip :
   			switch(toupper(ch))       //option
	    	{
//**************************
//* terminater   //
//**************************
	    	case '/':
                parmno=Pparmc;  //loop exit
	      		break;
//**************************
//* /C  chi-par list funcname                                      //~0709R~
//**************************
	    	case 'C':
            	Soption|=OPT_CHIPAR;
                if (*cptr)
                	Sfuncnm=cptr;
	      		break;
//**************************                                       //~v102R~
//* exclude func /F                                                //~v102R~
//**************************                                       //~v102R~
	    	case 'F':                                              //~v102R~
                if (*cptr)                                         //~v102R~
                {                                                  //~v102R~
                	if (Gexcludefuncno>=MAX_EXCLUDEFUNC)           //~v102R~
						uerrexit("Too many exclude funcname(max=%d)",//~v102R~
									"除外関数指定が多過ぎる(最大%d)",//~v102R~
									MAX_EXCLUDEFUNC);              //~v102R~
					Gexcludefunc[Gexcludefuncno++]=cptr;           //~v102R~
                }                                                  //~v102R~
	      		break;                                             //~v102R~
//**************************                                       //~0715I~
//* /I  indexlevel                                                 //~0715I~
//**************************                                       //~0715I~
	    	case 'I':                                              //~0715I~
            	Soption &=~(OPT_INDEX1|OPT_INDEX2);                //~0715I~
            	switch(*cptr)                                      //~0715I~
                {                                                  //~0715I~
//                  break;                                         //~v101R~
                case '0':                                          //~0715I~
                    break;                                         //~0715I~
                case 0:                                            //~0715I~
                case '1':                                          //~0715I~
    	        	Soption |=OPT_INDEX1;                          //~0715I~
                    break;                                         //~0715I~
                case '2':                                          //~0715I~
    	        	Soption |=OPT_INDEX2;                          //~0715I~
                    break;                                         //~0715I~
                default:                                           //~0715I~
                    uerrexit("Index option parm err(%s)",          //~0715I~
                                "トグル設定パラメータエラー(%s)",  //~0715I~
                                cptr);                             //~0715I~
                }                                                  //~0715I~
	      		break;                                             //~0715I~
//**************************                                       //~0708I~
//* exclude file /X                                                //~0708I~
//**************************                                       //~0708I~
	    	case 'X':                                              //~0708I~
                if (*cptr)                                         //~0708I~
                {                                                  //~0708I~
                	if (Sexcludeno>=MAX_EXCLUDE)                   //~0708I~
						uerrexit("Too many exclude filename(max=%d)",//~0708I~
									"除外ファイル指定が多過ぎる(最大%d)",//~0708I~
									MAX_EXCLUDE);                  //~0708I~
					Sexcludefnm[Sexcludeno++]=cptr;                //~0708I~
                }                                                  //~0708I~
	      		break;                                             //~0708I~
//**************************
//* set option     */Y
//**************************
	    	case 'Y':
				while (*cptr)
				{
	    			switch (toupper(*cptr))
    	  			{
          			case '9':   //japanese errmsg if avail
            			break;
          			case '#':   //print macro at first             //~0708I~
						Soption|=OPT_PMACRO;                       //~0708M~
            			break;                                     //~0708M~
          			case 'A':   //expand all function on child-parent//~0715I~
						Soption|=OPT_CPALL;                        //~0715I~
            			break;                                     //~0715I~
          			case 'C':   //chipar
						Soption|=OPT_CHIPAR;
            			break;
          			case 'D':   //#define macro proccess           //~0709I~
						Soption|=OPT_DEFMAC;                       //~0709I~
            			break;                                     //~0709I~
          			case 'E':   //print extern on chi-par list     //~0709I~
						Soption|=OPT_PEXTERN;                      //~0709I~
            			break;                                     //~0709I~
          			case 'H':   //function at highest call level   //~0708I~
						Soption|=OPT_PHIGH;                        //~0708I~
            			break;                                     //~0708I~
          			case 'P':   //prototype/parm print
						Soption|=OPT_PARCHI;
            			break;
          			case 'S':   //prototype/parm print
						Soption|=OPT_STMT;
            			break;
          			case 'T':   //test
            			break;
	      			default:
						uerrexit("Toggle Set parm err(%s)",
									"トグル設定パラメータエラー(%s)",
									Pparmp[parmno]);
	      			}//switch by /Yx
		  			cptr++;
      			}//until strlen
      			break;
//**************************
//* reset option     */N
//**************************
    		case 'N':
		  		while (*cptr)
		  		{
		    		switch (toupper(*cptr))
   		 	  		{
          			case '9':   //no japanese errmsg(force english)
            			break;
          			case '#':   //print macro at first             //~0708I~
						Soption&=~OPT_PMACRO;                      //~0708M~
            			break;                                     //~0708M~
          			case 'A':   //expand all function on child-parent//~0715I~
						Soption&=~OPT_CPALL;                       //~0715I~
            			break;                                     //~0715I~
          			case 'C':   //chipar
						Soption&=~OPT_CHIPAR;
            			break;
          			case 'D':   //#define macro proccess           //~0709I~
						Soption&=~OPT_DEFMAC;                      //~0709I~
            			break;                                     //~0709I~
          			case 'E':   //print extern on chi-par list     //~0709I~
						Soption&=~OPT_PEXTERN;                     //~0709I~
            			break;                                     //~0709I~
          			case 'H':   //function at highest call level   //~0708I~
						Soption&=~OPT_PHIGH;                       //~0708I~
            			break;                                     //~0708I~
          			case 'P':   //prototype/parm print
						Soption&=~OPT_PARCHI;
            			break;
          			case 'S':   //prototype/parm print
						Soption&=~OPT_STMT;
            			break;
          			case 'T':   //no japanese errmsg(force english)
            			break;
	      			default:
						uerrexit("Toggle Reset parm err(%s)",
									"トグル設定解除パラメータエラー(%s)",
									Pparmp[parmno]);
	      			}//switch by /Nx
		  			cptr++;
      			}//until strlen
      			break;
//**************************
//* option err             *
//**************************
			default:                           //not option
                uerrexit("Invalid option(%s)",
                            "パラメータエラー(%s)",
                            Pparmp[parmno]);
    		}//switch  by first option byte
		}//option
		else	//not / or -
		{//positional parmno
            if (Sfilenmno>=MAX_FILENM)                             //~0708I~
				uerrexit("Too many filename(max=%d)",              //~0708I~
							"ファイル指定が多過ぎる(最大%d)",      //~0708I~
							MAX_FILENM);                           //~0708I~
			Sparmfnm[Sfilenmno++]=cptr;                            //~0708I~
		}//option or posparm
	}//for all parm
	return;
}//parmproc
//****************************************************************
// fileproc
//*search file on fileq(load and enq if not exist)
//*parm1:file name
//*rc   :0-ok 4:file load err
//****************************************************************
int fileproc(UCHAR *Pfnm)
{
    PULINEH plh;
	int rc;
	UFILEH *pfh;
    UCHAR  *fname;
//*********************************
    if (!(fname=Pfnm))//pparseout 1st parm
    	uerrexit("Specify filename",
    			"ファイル名を指定して下さい");

	if (rc=fileload(fname,&pfh),rc)
		return rc;
    if (pfh->UFHtype==UFHTDIR)   //dir type pfh
        return 0;

	if (rc=filesrchfunc(pfh,Soption),rc)
		return rc;
//recover org data(swap to line without comment)
	for (plh=UGETQTOP(&pfh->UFHlineque);plh;plh=UGETQNEXT(plh))
    {
    	memcpy(Sbuff,plh->ULHdata,(UINT)plh->ULHlen);
    	memcpy(plh->ULHdata,plh->ULHdata+plh->ULHlen+1,(UINT)plh->ULHlen);
    	memcpy(plh->ULHdata+plh->ULHlen+1,Sbuff,(UINT)plh->ULHlen);
    }

	return 0;
}//fileproc

//****************************************************************
// fileload
//*read file and create file hdr(enq line data)
//*parm1:file name
//*parm2:open option
//*parm3:ptr to file hdr
//*rc   :0-ok 4:file load err or UALLOC_FAILED
//****************************************************************
int fileload(UCHAR *Pfname,PUFILEH *Pppfh)
{
	int  	rc;
	LONG 	lineno;
	PUFILEH pfh;
	ULINEH 	*plh;
	FILEFINDBUF3 fstat3;     				//output from DosFindxxxx
	FILE *hfile;
    UCHAR fpath[_MAX_PATH];                                        //+va15R~
//****************************
	*Pppfh=pfh=UALLOCC(1,UFILEHSZ);
    if (!pfh)
    	errmalloc("FileHdr");
	memcpy(pfh->UFHcbid,UFHCBID,4);		//acronym
    rc=filefindopen(Pfname,fpath,&fstat3,&hfile);                  //+va15R~
	switch(rc)
	{
	case 0:
		break;
	case 2:	//directory
        pfh->UFHtype=UFHTDIR;   //dir type pfh
		break;
	default:	//not found/open err
		ufree(pfh);
		return rc;
	}
    ufilesetfhfilename(pfh,fpath);                                 //+va15R~
//file attr
	pfh->UFHsize	=fstat3.cbFile;			//file size
	pfh->UFHfiledate=fstat3.fdateLastWrite;//file date
	pfh->UFHfiletime=fstat3.ftimeLastWrite;//file time
	pfh->UFHattr    =(char)fstat3.attrFile;//file time
    if (pfh->UFHtype==UFHTDIR)   //dir type pfh
    {
        if (rc=dirload(pfh),rc)
    		fileclosefree2(pfh);	//close and free pfh
        return rc;
    }
	pfh->UFHhfile=hfile;

//top line
	lineno=0;
	
//enq file data
    plh=0;
    for (;;)    //until eof/err
    {
        ++lineno;
        if (filegetline(Pfname,hfile,lineno,&plh,pfh))
            break;
        if (!plh)//skipline
            continue;
        UENQ(UQUE_END,&pfh->UFHlineque,plh);
    }//until eof
    if (rc>0)   //i/o err
    {
        fileclosefree2(pfh);    //close and free pfh
        return rc;
    }
//end of line
	return 0;
}//fileload

//****************************************************************
// filefindopen
//* fstat and open
//*parm1:file name for err msg
//*parm2:file status area ptr
//*parm3:open opt(UFCFBROWSE(1),0(edit),x7f(new open)
//*      0x0100 (binnary mode) 0x0200(append mode)
//*parm4:output FILE * ptr
//*parm5:filefind msg option
//*retrn:rc 0:ok ,1:new file,2:dir,4:not found(read open) 8:path err
//*         12:full path err 16:open err
//****************************************************************
int filefindopen(UCHAR *Ppfile,UCHAR *Pfullpath,FILEFINDBUF3 *Ppfstat3,
				FILE** Pphfile)
{
	int rc;
	char *openopt="r";
    int rbsw;
//****************
	*Pphfile=0;			//clear for intermediate return
    rbsw=0;
	if (rc=filefind(Ppfile,Pfullpath,Ppfstat3,FFNODIRMSG),rc)	//no need fullpath name
	{
    	if (rc==16 || rc==20)	//dir,wild card
        	return 2;
		if (rc>4)
			return rc;
        uerrexit("%s is not found",
                "%s が見つかりません",Ppfile);
	}
	else				//file found
    {
        if (rbsw)
            openopt="rb";
	}
	if (!(*Pphfile=fileopen(Ppfile,openopt)))      	//open
		return 16;
	return 0;
}//filefindopen

//****************************************************************
// filegetline
//* 1 line get
//*parm1:file name for err msg
//*parm2:file handle for i/o
//*parm3:lineno 
//*parm4:output plh addr or 0 if not plh alloc requied
//*parm5:file read binary mode option
//*parm6:pfh
//*retrn:rc 0:ok ,8:i/o err, -1:eof
//****************************************************************
int filegetline(UCHAR *Pfilename,FILE *Phfile,long Pline,PULINEH *Ppplh,
				PUFILEH Ppfh)
{
		PULINEH plh;
       	int len;
//****************************
	*Ppplh=0;
    if (!fgets(Sbuff,MAXLINEDATA,Phfile))
    {                                                              //~va15I~
    	if (ferror(Phfile))
		{
            ufileapierr("read by fgets",Pfilename,errno);
			return 8;
		}
		else
			return -1;		//eof
    }                                                              //~va15I~
    len=(int)strlen(Sbuff);
    if (!len)
    	return 0;
    if (len==MAXLINEDATA-1)
    	uerrexit("%s record-no %ld is too long(max %d)",           //~v103R~
    			"%s 第 %ld レコード,制限長(%dバイト)オーバー",     //~v103R~
                Pfilename,Pline,MAXLINEDATA);	                   //~v103R~
	if (*(Sbuff+len-1)=='\n')
    {
        len--;
    	*(Sbuff+len)=0;
    }
    if (!len)
    	return 0;
	plh=filealloclh(0,len);
	plh->ULHlinenor=Pline;
	memcpy(plh->ULHdata,Sbuff,(UINT)len);
	memcpy(plh->ULHdata+1+len,Sbuff,(UINT)len);//duplicate for precompile chk
	*Ppplh=plh;
	return 0;
}//filegetline

//****************************************************************
//* deq and free pfh
//* parm:pfh
//* ret :none
//****************************************************************
void filefreepfh(PUFILEH Ppfh)
{
//***************
    if (UGETQHDR(Ppfh)) //confirm enqed for i/o err etc
		UDEQ(UQUE_ENT,0,Ppfh);;
	ufree(Ppfh);;
    return;
}//filefreepfh
//***********************************************************
// filealloclh
//*allocate ULINEH and data buff
//*parm1:line type
//*parm2:data length
//*retrn:ULINEH addr or 0 if storage shortage
//***********************************************************
PULINEH filealloclh(UCHAR Ptype,int Pdatalen)
{
	PULINEH plh;
//***************	
	plh=UALLOCC(1,(UINT)(ULINEHSZ+Pdatalen+1+Pdatalen));	//padd last null
    if (!plh)
    	errmalloc("LineData buffer");
	memcpy(plh->ULHcbid,ULHCBID,4);
	plh->ULHtype=Ptype;				//line type
	plh->ULHlen=Pdatalen;
	plh->ULHdata=(UCHAR*)(void*)plh+ULINEHSZ;
	return plh;
}//filealloclh
//****************************************************************
// filefreeplh
//*free line entry
//*parm1:PULINEH
//*parm2:option to free entry   1:free entry 0,free data only
//*void
//****************************************************************
void filefreeplh(PULINEH Pplh,int Popt)
{
	if (Popt)
		ufree(Pplh);
}//filefreeplh
//****************************************************************
//!fileclosefree2
//*close and free UFILEH/ULINEH
//*parm:UFILEH
//*rc   :open count
//****************************************************************
int fileclosefree2(PUFILEH Ppfh)
{
//****************************
	if (Ppfh->UFHhfile)
		fileclose(Ppfh->UFHfilename,Ppfh->UFHhfile);//fclose
//line data
	filefree(Ppfh);			//free all plh
    filefreepfh(Ppfh);           //deq and free pfh
	return 0;
}//fileclosefree2
//****************************************************************
//!filefree
//*free all ULINEH entry
//*parm1:PUFILEH
//*void
//****************************************************************
void filefree(PUFILEH Ppfh)
{
	UQUEH   *pqh;
	PULINEH plh;
//******************
	pqh=&Ppfh->UFHlineque;
	while (plh=UDEQ(UQUE_TOP,pqh,0),plh)	//dequed
		filefreeplh(plh,1);
	return;
}//filefree

//******************************************************************
// @@@@ dir @@@@ ***************************************************
//****************************************************************
//****************************************************************
//****************************************************************
//!dirload
//*read file and create file hdr(enq line data)
//*parm1:pcw
//*parm2:pfh
//*rc   :rc UALLOC_FAILED if storage shortage
//****************************************************************
int dirload(PUFILEH Ppfh)
{
	UCHAR   dirname[_MAX_PATH]; //for udirlist
	PUDIRLIST pudirlist,pudirlist0;
	int  	filectr,ii,jj,rc,pathlen;                              //~0708R~
//****************************
    strcpy(dirname,Ppfh->UFHfilename);	//long name
    if (!strpbrk(dirname,"*?"))//not wild card
    {                                                              //~va15I~
        if (PATHLEN(dirname)==(int)strlen(dirname))//not dbcs 2nd byte
          	strcat(dirname,"*.*");
        else
//        	strcat(dirname,"\\*.*");                               //~v101R~
          	strcat(dirname,DIR_SEPS "*.*");                        //~v101I~
    }                                                              //~va15I~


    pathlen=PATHLEN(dirname);
	filectr=dirgetlist(Ppfh,dirname,0,&pudirlist0);//name seq or longfname seq
    if (filectr<0)	//err
    	return 4;
	*(dirname+pathlen)=0;
	for (ii=0,pudirlist=pudirlist0;ii<filectr;ii++,pudirlist++)	//until eof/err
	{
	    if (  !strcmp(pudirlist->name,".")      //current
	       || !strcmp(pudirlist->name,"..")  )//or parent
			continue;					//already inseted entr
//  	if (UCBITCHK(pudirlist->attr,FILE_DIRECTORY))              //~va15R~
    	if (pudirlist->attr & FILE_DIRECTORY)                      //~va15I~
        	continue;
        for (jj=0;jj<Sexcludeno;jj++)	//search exclude list      //~0708I~
        {                                                          //~0708I~
        	if (!Sexcludefnm[jj])                                  //~0708I~
            	break;                                             //~0708I~
        	if (!stricmp(Sexcludefnm[jj],pudirlist->name))         //~0708R~
            	break;                                             //~0708I~
        }                                                          //~0708I~
        if (jj<Sexcludeno)	//matched                              //~0708I~
        	continue;                                              //~0708I~
		if (rc=dirsetdata(dirname,pudirlist,Ppfh),rc)
        	return rc;
	}
    ufree(pudirlist0);
	return 0;
}//dirload

//****************************************************************
//!dirgetlist
//*create sorted dirlist(parent,current then other)
//*parm1:pfh
//*parm2:filename and mask
//*parm3:option(select file type)
//*parm4:pudirlist ptr
//*ret  :file ctr or -1(if err)
//****************************************************************
int dirgetlist(PUFILEH Ppfh,UCHAR *Pfilemask,UINT Popt,PUDIRLIST *Pppudirlist)
{
	UINT    option;
    int 	filectr;
	PUDIRLIST pudirlist;
    int sortorder;
//****************************
	if (!(option=Popt))
		option=FILE_NORMAL
       	  		| FILE_READONLY
         		| FILE_HIDDEN
         		| FILE_SYSTEM
         		| FILE_DIRECTORY
         		| FILE_ARCHIVED;
    sortorder='L';
    filectr=udirlist(Pfilemask,option,&pudirlist,sortorder);//name seq
    if (filectr<0)	//err
    	return -1;
    *Pppudirlist=pudirlist;
	return filectr;   //restore
}//dirgetlist
//****************************************************************
//!dirsetdata
//* alloc and setup dir line data
//*parm1:dirname
//*parm2:pudirlist
//*parm3:pfh
//*retrn:plh or 0 if storage shortage
//****************************************************************
int dirsetdata(UCHAR *Ppathname,PUDIRLIST Ppudirlist,PUFILEH Ppfh)
{
	UCHAR fname[_MAX_PATH];
    int rc,len;
//****************************
    strcpy(fname,Ppathname);
    len=(int)strlen(fname);
//  if (*(fname+len-1)!='\\')                                      //~v101R~
    if (*(fname+len-1)!=DIR_SEPC)                                  //~v101I~
//  	*(fname+len++)='\\';                                       //~v101R~
    	*(fname+len++)=DIR_SEPC;                                   //~v101I~
    strcpy(fname+len,Ppudirlist->name);
#if defined(W32) || defined(DPMI)
//    strcpy(fname+len,Ppudirlist->alias);
#endif
    rc=fileproc(fname);
	return rc;
}//dirsetdata
//*******************************************************
//*file find
//* parm1:filename
//* parm2:output fullpath area(option,if null filename must fullpath)
//* parm3:output fstat3 area(option)
//* parm4:option to output errmsg 0:err msg 1:bypass not found msg
//* retrn:rc 0:found, 4:not found, 8:path not found, 12:fullpath err
//*          16:it is dir 20:wildcard
//*******************************************************
int filefind(UCHAR *Ppfile,UCHAR *Pfullpath,FILEFINDBUF3 *Ppfstat3,
			 int Pmsgopt)
{
	FILEFINDBUF3 fstat3;
	FILEFINDBUF3 *pfstat3;
	UCHAR *filename;
	int rc,rootsw=0;
//****************************
	if (Pfullpath)		//fullpath required
	{
		if (!filefullpath(Pfullpath,Ppfile,_MAX_PATH))//fullpath name
	    	return 12;
		filename=Pfullpath;
	}
	else
		filename=Ppfile;
//  if (!strcmp(filename+1,":\\"))	//root                         //~v101R~
    if (ROOTDIR(filename))	//root                                 //~v101I~
       	rootsw=1;
	if (!(pfstat3=Ppfstat3))
		pfstat3=&fstat3;
    if (strpbrk(filename,"*?"))	//wild card
    {
        if (!(Pmsgopt & FFNODIRMSG))
			uerrmsg("wild card is invalid",
					"ワイルドカードは無効です");
		return 20;				//wild card
	}
	if (rc=(int)ufstat(filename,pfstat3),rc)		//not found
	{
		if (rc==ERROR_PATH_NOT_FOUND)
		{
			uerrmsg("%s,invalid path",
					"%s のパスが見つかりません",filename);
			return 8;
		}
		if (rootsw)
			pfstat3->attrFile |=FILE_DIRECTORY;  //directory
        else
        {
        if (!(Pmsgopt & FFNONFMSG))
			uerrmsg("%s is not found",
					"%s が見つかりません",filename);
			return 4;
        }
	}
	if (pfstat3->attrFile & FILE_DIRECTORY)  //directory
    {
        if (!(Pmsgopt & FFNODIRMSG))
			uerrmsg("%s is directory",
					"%s はディレクトリーです",filename);
    	return 16;
	}

	return 0;
}//filefind

//**************************************************
//*ufilesetfhfilename
//* set filename to ufh,and also to shortname fow dpmi/w95
//*parm 1:pfh
//*parm 2:longname
//*return:none
//**************************************************
void ufilesetfhfilename(PUFILEH Ppfh,char *Plongname)
{
//********************
  	ustrncpyz(Ppfh->UFHfilename,Plongname,sizeof(Ppfh->UFHfilename));
#if defined(DPMI) || defined(W32)
    ugetvfatalias(UGVFA_WILDCARD|UGVFA_NEW,	//may wildcard or new file
		Plongname,Ppfh->UFHshortname,sizeof(Ppfh->UFHshortname));
#endif
	return;
}//ufilesetfhfilename
//*******************************************************
//*file open
//*******************************************************
FILE *fileopen(UCHAR *Ppfile,UCHAR *Ppopt)
{
	FILE *fh;
    FILEFINDBUF3 fstat3;
    char *pc;
//****************************
	if (!(fh=fopen(Ppfile,Ppopt)))
    {
    	if (!ufstat(Ppfile,&fstat3)
        && fstat3.attrFile & FILE_READONLY)
			pc=",ReadOnly";
        else
        	pc="";
#ifndef UNX                                                        //~v101I~
#ifdef DOS
#else
	#ifdef W32
	#else
    	if (errno==EISOPEN)	//open by other
    		uerrexit("%s(\"%s\") is already opened on other session",
    			    "%s(\"%s\") は他でオープン中",Ppfile,Ppopt);
        else
	#endif
#endif
#endif                                                             //~v101I~
		uerrexit("%s(\"%s\") Open failed(errno=%d)%s",
			    "%s(\"%s\") オープンエラー(errno=%d)%s",Ppfile,Ppopt,errno,pc);
    }
	return fh;
}//fileopen
//*******************************************************
//*file close
//*parm1:filename
//*parm2:FILE*
//*return:rc
//*******************************************************
int fileclose(UCHAR *Pfile,FILE* Pfh)
{
//****************************
	if (fclose(Pfh))
    {
		uerrexit("%s Close failed,rc=%d",
			    	"%s クローズ エラー,rc=%d",
					Pfile,errno);
        return 4;
    }
	return 0;
}//fileclose
//*******************************************************
//*get file fullpath name
//*parm 1:output full pth mame
//*parm 2:input partial filename
//*parm 3:output buff len
//*return:output buff addr or NULL if err
//*******************************************************
char *filefullpath(char *Pfullpath,char *Pfilename,size_t Plen)
{
    UCHAR *pc;
//***************************
    pc=ufullpath(Pfullpath,Pfilename,Plen);
	return pc;
}//filefullpath

//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
#define HELPMSG uerrhelpmsg(stdout,stderr,
//*******************
    uerrmsg_init(0,stdout,Suerrmsgopt);//msg to stdout
    uerrexit_init(0,stdout,0,0,0);//stdout only,no pathmsg

	HELPMSG "format ========: %s filespec [%coption %c...] [filespec ...] \n",//~v101R~
			" 形式  ========: %s [%cオプション %c...] [ファイル名] [ファイル名...]\n",//~v101R~
			PGMID,CMDFLAG_PREFIX,CMDFLAG_PREFIX);                  //~v101R~
	HELPMSG " filespec      :C source-filename, wild cared or directory name.\n",//~0708R~
//  		" ファイル名    :C ソースファイル名(ワイルドカード 或は ディレクトリー名も可)\n");//~v101R~
    		" ファイル名    :C \x83\\ースファイル名(ワイルドカード 或は ディレクトリー名も可)\n");//~v101I~
	HELPMSG "                multiple filespec is avail.\n",       //~0708R~
			"                複数指定も可。\n");                   //~0708R~
	HELPMSG " option        :see following(case insensitive,no seq,last effective if dup)\n",
			" オプション    :以下を参照,大文字小文字の区別なし,順不同,重複は最後が有効\n");
	HELPMSG
			"  %cC[funcnm]   :List child->parent relation (of specified function).\n",//~v101R~
			"  %cC[funcnm]   :(指定の関数の)子ー親 関係リスとする.\n",//~v101R~
					CMDFLAG_PREFIX);                               //~v101R~
	HELPMSG                                                        //~v102R~
			"  %cFfuncname   :func name to be excluded.(for debug,trace func etc).\n",//~v102R~
			"  %cFfuncname   :Debug,trace関数など除外する関数名の指定.\n",//~v102R~
					CMDFLAG_PREFIX);                               //~v102R~
	HELPMSG                                                        //~v102I~
			"                Use multiple %cF to exclude members.\n",//~v102R~
			"                複数ある時は一つづつ %cF 指定する。\n",//~v102R~
					CMDFLAG_PREFIX);                               //~v102I~
	HELPMSG                                                        //~0715M~
			"  %cI[0|1|2]    :Index print level.(default=%cI1)\n", //~v101R~
			"  %cI[0|1|2]    :関数インデックスリストの出力レベル。(省略値=%cI1)\n",//~v101R~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~v101I~
	HELPMSG                                                        //~0715I~
			"                0:No index print, 1:expanded function only, 2:all function\n",//~0715I~
			"                0:インデックスリスト出力なし、1:展開関数のみ、2:全関数。\n");//~0715I~
	HELPMSG                                                        //~0708I~
			"  %cXmembername :member name to be excluded to process wild card/directory.\n",//~v101R~
			"  %cXmembername :ワイルドカード/ディレクトリー指定の時,除外ファイル名.\n",//~v101R~
					CMDFLAG_PREFIX);                               //~v101I~
	HELPMSG                                                        //~0708I~
			"                Use multiple %cX to exclude members.\n",//~v101R~
			"                複数ある時は一つづつ %cX 指定する。\n",//~v101R~
					CMDFLAG_PREFIX);                               //~v101I~
	HELPMSG
			"  %cYopts,%cNopts:Other toggle option string. Default is in the parentheses.\n",//~v101R~
			"  %cYopts,%cNopts:オン/オフ タイプのその他オプション文字列. ( )内は省略値\n",//~v101R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v101R~
	HELPMSG                                                        //~0708M~
			"          # (Y):List at first MACRO functions.\n",    //~0708I~
			"          # (Y):マクロを最初にまとめてリスﾄする。\n");//~0708I~
	HELPMSG                                                        //~0715I~
			"          a (N):On child->parent list,expand All function.\n",//~0715I~
			"          a (N):子ー親リストで全ての関数を展開する。\n");//~0715I~
	HELPMSG                                                        //~0715I~
			"                %cNa means expansion only at 1st appearance of the relation.\n",//~v101R~
			"                %cNa の時その子ー親関係の最初の\x95\\示の時にだけ展開する。\n",//~v101R~
						CMDFLAG_PREFIX);                           //~v101R~
	HELPMSG
			"          c (N):List child->parent relation\n",
			"          c (N):関数の 子ー親 関係をリストする。\n"); //~0709R~
	HELPMSG                                                        //~0709I~
			"          d (Y):Process #define macro.\n",            //~0709R~
			"          d (Y):#define マクロを処理する。\n");       //~0709R~
	HELPMSG                                                        //~0709I~
			"          e (N):Print external function on Child-Parent list.\n",//~0709I~
			"          e (N):子ー親 関係リストに外部関数も出力する。\n");//~0709I~
	HELPMSG                                                        //~0708I~
			"          h (Y):On parent-child list,expand sub-function at Highest call level.\n",//~0720R~
			"          h (Y):親ー子リストで子関数を最も浅いコールレベルで展開する。\n");//~0720R~
	HELPMSG                                                        //~0708I~
			"                %cNh means expansion at 1st appearance.\n",//~v101R~
			"                %cNh の時最初にコールされた時に展開する。\n",//~v101R~
						CMDFLAG_PREFIX);                           //~v101R~
	HELPMSG
			"          p (Y):List parent->child relation\n",
			"          p (Y):関数の 親ー子 関係をリストする.\n");
	HELPMSG
			"          s (Y):Print function definition/call stmt in child-parent list.\n",
			"          s (Y):関数定義部や 子ー親 リストの コール文の印刷.\n");
	HELPMSG "  Sample       : %s %cI2 %cYc dir1%c*.c dir1%cinclude%c*.h\n",//~v101R~
			"  入力例       : %s %cI2 %cYc dir1%c*.c dir1%cinclude%c*.h\n",//~v101R~
				PGMID,CMDFLAG_PREFIX,CMDFLAG_PREFIX,DIR_SEPC,DIR_SEPC,DIR_SEPC);//~v101R~
    HELPMSG                                                        //~v102I~
            " "," ");                                              //~v102I~
	titlemsg();
	return;
}//help
//**********************************************************************
//* write title msg                                                //~0708R~
//**********************************************************************
void titlemsg(void)
{
	uerrmsg_init(Spgmver,stdout,Suerrmsgopt);//msg to stdout       //~0715R~
	uerrmsg("(%c) === C function tree (%s) ============== By Touchiku =====",//~0715R~
//  		"(%c) === C 関数構造リスト(%s) ============== By 東竹工 凡 ====",//~v101R~
    		"(%c) === C 関数\x8d\\造リスト(%s) ============== By 東竹工 凡 ====",//~v101I~
            OSTYPE,__DATE__);
	return;
}//titlemsg
//**********************************************************************
//* malloc err msg                                                 //~0708R~
//**********************************************************************
void errmalloc(UCHAR *Pstate)
{
	uerrexit("Storage shortage(%s)",0,
				Pstate);
	return;
}//titlemsg
