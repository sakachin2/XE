//*CID://+vau1R~:                             update#=  506;       //~vau1R~
//***********************************************************
//* xff  : find file by timestamp/size top nn entry
//***********************************************************
//vau1:250706 uerrmsg_init missing.(No dbcs errmsg)                //~vau1I~
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//vaa2:160424 Lnx64 compiler warning(FDATE/FTIME)                  //~vaa2I~
//vaa1:160418 Lnx64 compiler warning                               //~vaa1I~
//vaa0:160417 Lnx compiler warning                                 //~vaa0I~
//va77:131127 xff v1.7 add function to search wild card name(/bw)  //~va77I~
//va75:130622 xff v1.6 list also slink err entry                   //~va75I~
//va74:130622 xff v1.6 (BUG)-Bl print attr of slink itself when verbose//~va74I~
//va71:130618 (W32)dirwalk support windows slink/junction/mountpoint//~va71I~
//va6d:120808 xff v1.6 print time stamp by 1 sec unit              //~va6dI~
//va6a:120803 Warning "int to USHORT"                              //~va6aI~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va58:111217 compiler warning,uninitialized                       //~va58I~
//va3g:071107 xff: v1.5 ctime is not creation time but change time //~va3gI~
//va30:061227 xff v1.4:filesize>4GB support                        //~va30I~
//va1H 041226 xff:v1.3(BUG) of Va1G;date equal option cannot select file//~va1HI~
//va1G 041214 xff:v1.2 99 for mm,ss to ignore mm,ss for srch by =time stamp//~va1HR~
//021214 xfg:v1.2 v125 no performance up effect by setting curdir  //~va1HR~
//021214 xff v129 v1.1 no performance up effect by setting curdir  //~v129R~
//021210 xff v128 v1.1 filename mask support                       //~v128I~
//021210 xff v127 v1.1 support wildcard specification(mask for top dir)//~v127I~
//021204 xff v126 v1.1 (BUG)not output memory trace for alloc at parmchk//~v126I~
//021203 xff v125 v1.1 performance tuning(for stat call by udirlist)//~v126R~
//021009 xff v124 v1.1 (UNX)no slink err msg option(/Nm)(u#395)    //~v122I~
//020809 xff v123 v1.1 add function of simbolic link search        //~v123R~
//020809 xff v122 v1.1 chng parm fmt(selction parm is /b)          //~v122R~
//020805 xff v121 v1.1 (BUG)filename search err for DBCS filename  //~v121I~
//020805 xff v120 v1.1 (BUG)for fname search,miss to chk dir name  //~v120I~
//020724 xff v119 v1.1 =ts support                                 //~v119I~
//020724 xff v118 v1.1 support filename search by wild card        //~v118R~
//020724 xff v117 v1.1 TOPMASK is for xds only                     //~v117I~
//020714 xff v116 v1.1 (UNX)symbolic link skip option              //~v116I~
//020714 xff v115 v1.1 support special file                        //~v115I~
//020710 xff v114 v1.1 support /all (list all file)                //~v114I~
//020707 xff v113 v1.1 support /d[nn] option(search subdir depth)  //~v113I~
//020706 xff v112 v1.1 (AIX)storage shortage when / (ROOT)(BUG of udirwalk)//~v112R~
//020704 xff v111 v1.1 not found msg twice;not found msg for root  //~v111I~
//xff.c  *v1.1 *020704 v101 (!UNX) "*:"(all drive) support at up#230//~v112R~
//***********************************************************
#define VER "V1.9"   //version                                     //~vaa0R~//~vau1R~
#define PGM "xff"
//**********************************************/
//*parm  : dir name
//*        /Lx depth level
//*        /Lx depth level
//*r.c   : 0 :normal,else err
//**********************************************/
//*
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX
	#include <sys/stat.h>                                          //~v116I~
#else
#endif

#ifdef DOS
#else
  	#ifdef W32
    	#include <dos.h>
    	#include <windows.h>
  	#else
  	#endif
#endif

//*********************************************************************
#include <ulib.h>
#include <uque.h>
#include <ufile.h>
#include <uerr.h>
#include <ualloc.h>
#include <ufile4.h>
#include <ufile5.h>                                                //~v118I~
#include <ustring.h>
#include <uedit.h>
#include <udbcschk.h>                                              //~v121I~
#include <ucalc2.h>                                                //~va30I~
#include <ufile2.h>                                                //~va77I~
#include <ufile3.h>                                                //~va6dI~
#include <uedit2.h>                                                //~vaa2I~
#ifndef UNX                                                        //~v101I~
	#include <udos2.h>                                             //~v101I~
#endif                                                             //~v101I~
//*********************************************************************
typedef struct _FILESTACK{                        //file hdr
                           UQUEE     FSqelem;
                           UQUEH     FSsameqh;
                           ULONG     FScompkey;                    //~v100R~
#ifdef LFSSUPP                                                     //~va30I~
                           FILESZT   FScompkeysz;                  //~va30R~
#endif                                                             //~va30I~
                    	   UDIRLIST  FSudirlist;
                    	   char      FSfpath[_MAX_PATH];           //~v100I~
                         }  FILESTACK,  *PFILESTACK;
#define FILESTACKSZ (sizeof(FILESTACK))
typedef struct _PARMFNMSTACK{                        //file hdr
                           	UQUEE     PFNqelem;
                    	   	char      PFNname[_MAX_PATH];
                         	}  PARMFNMSTACK,  *PPARMFNMSTACK;
#define PARMFNMSTACKSZ (sizeof(PARMFNMSTACK))
//*********************************************************************//~v112I~
//*********************************************************************
#define HELPMSG         uerrhelpmsg(stdout,stderr,
#define MAXDEPTH        20
#define TODAYID         '.'                                        //~v119I~
#define MAXSTACK         10
#define MAXSTACK2       0x7fff                                     //~v100I~
#define SELECT_BY_NAME  'N'                                        //~v118I~
#define SELECT_BY_SIZE  'S'
#define SELECT_BY_ATIME 'A'
#define SELECT_BY_MTIME 'M'
#define SELECT_BY_CTIME 'C'
#define SELECT_WILDCARD 'W'                                        //~va77I~
#define SELECT_ALL      '*'                                        //~v114I~
//#ifdef UNX                                                         //~v123I~//~va74R~
#if defined(W32)||defined(UNX)                                     //~va71I~//~va74I~
	#define SELECT_ALL_SLINK 'L'     //symbolic link search        //~v123R~
#endif                                                             //~v123I~
#ifndef UNX                                                        //~v101R~
	#define DRIVE_ALL  "*:"                                        //~v101R~
#endif                                                             //~v101R~

#ifdef AIX                                                         //~v100R~
	#define FDT2ULONG(fdate,ftime) \
		((ULONG)( (  (   (ULONG)(*(int*)(ULONG)(&(fdate)))  )<<16)  \
		        |        (ULONG)(*(int*)(ULONG)(&(ftime)))        ))//~v100I~
#else                                                              //~v100I~
//  #define FDT2ULONG(fdate,ftime)                                 //~va66R~
//  	((ULONG)( (  (   (ULONG)(*(USHORT*)(ULONG)(&(fdate)))  )<<16)//~va66R~
//  	        |        (ULONG)(*(USHORT*)(ULONG)(&(ftime)))        ))//~va66R~
#ifdef W32                                                         //~va77I~
    #define FDT2ULONG(fdate,ftime) \
        ((ULONG)( (  (   (ULONG)(*(USHORT*)(ULPTR)(&(fdate)))  )<<16)  \
                |        (ULONG)(*(USHORT*)(ULPTR)(&(ftime)))        ))//~va66I~
#else                                                              //~va77I~
    #define FDT2ULONG(fdate,ftime) \
        ((ULONG)( (  (FDATE2USHORT(fdate))<<16)  \
                | (  (FTIME2USHORT(ftime)))        ))              //~va77R~
#endif                                                             //~va77I~
#endif                                                             //~v100I~
//*********************************************************************
static char *Spgm=PGM,*Sver=VER;
static char *Sselparm="m";                                         //~v100R~
static UQUEH  Sfilestack;	 //qhdr of FILESTACK
static UQUEH  Spfnmstack;	 //parmfnm stack
static ULONG  Sprintlimit;
#ifdef LFSSUPP                                                     //~va30I~
	static FILESZT Sprintlimitsz;                                  //~va30I~
#endif                                                             //~va30I~
static ULONG  Sparmlimit=0;             //max select count         //~v100I~
static int    Sselectid=SELECT_BY_MTIME;     //file select option
static int    Sselectidsw=0;                                       //~v118I~
static int    Schkctr=0;      //file select option
static int    Sprintctr=0;      //file name select match           //~v118I~
static int    Sskipdirsw=0;   //dir skip
static LONG   Smaxstack=MAXSTACK;     //max select count
static int    Sverbosesw=0;
static int    Sdepth=32767;             //serach subdir option     //~v113I~
static int    Slowsw=0;
static int    Ssamesw=0;		//same date file select            //~v119I~
static int    Ssamesw2=0; //1:ignore min of hhmmss,2:ignore ss,3:all match//~va1GR~
static int    Sparmsec1=0;	//odd second sw                        //~v100R~
static int    Stestsw=0;	//malloc debug                         //~v116I~
static char  *Snamestr=0;   //name search                          //~v118R~
static char   Snamedbcs[_MAX_PATH];   //name search                //~v126R~
static int    Snamewildsw=0;  //wildcard filename srch             //~v118I~
static int    Scasesw=0;    //case sensitive; default:No           //~v118I~
static char  *Sfilemask="";                                        //~v128I~
#if defined(W32)||defined(UNX)                                     //~va71I~
	static int    Sskipslinksw=0; //slink skip option              //~va71I~
#endif                                                             //~va71I~
#ifdef UNX                                                         //~v116I~
//  static int    Sskipslinksw=0; //slink skip option              //~v116R~//~va71R~
  #ifdef LNX                                                       //~v125I~
	static int  Scdsw=0;                                           //~v125I~
  #else                                                            //~v125I~
	static int  Scdsw=0;                                           //~v129R~
  #endif                                                           //~v125I~
#endif                                                             //~v116I~
static	char Spgmver[18];                                          //~vau1I~
//************************************
void parmchk(int,char *[]);
int pstatchk(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,
                                int Pdepth,void *Pdata,int *Prc);
int paddstack(PUDIRLIST Ppudirlist,char *Pdir,ULONG Pcompkey);     //~v100R~
void putresult(void);
void pprtszts(PFILESTACK Ppsf);
#if defined(W32)||defined(UNX)                                     //~va71I~//~va74I~
	void pprtszts_slink(PFILESTACK Ppfs);                          //~va74I~
#endif                                                             //~va74I~
#ifdef UNX
	char *peditts(time_t Ptm,char *Peditout);
	int  xfftime2dosfiletime(ULONG Ptime,ULONG *Ppdosdatetime);    //~v100R~
#else   //!UNX
	char *peditts(FDATE Pdate,FTIME Ptime,char *Peditout);         //~v100R~
	void xffalldrive(PPARMFNMSTACK Ppfnm);                         //~v101R~
#endif
#ifdef W32                                                         //~v100I~
    char *pedittsfiletime(FILETIME *Ppftm,char *Peditout);         //~v100I~
    ULONG xfffiletime2dosfiletime(FILETIME *Ppftm);                //~v100I~
#endif                                                             //~v100I~
void help(void);
void optionerr(char *type,char* value);
int getnum(char *Pdata,int *Ppi1,int *Ppi2,int *Ppi3);
int xffsettime(ULONG *Pts,int Phh,int Pmm,int Pss);
int xffsetdate(ULONG *Pts,int Pyy,int Pmm,int Pdd);
int xffcompul(ULONG Pul1,ULONG Pul2);
#ifdef LFSSUPP                                                     //~va30I~
	int xffcompfsz(FILESZT Plimit,FILESZT Pfsz);                   //~va30R~
#endif                                                             //~va30I~
//int xffwildselect(PUDIRLIST Ppudirlist);                         //~v120R~
int xffwildselect(char *Pfnm);                                     //~v120I~
int srchwildname(char *Pdir,char *Pfilemask,int Pdepth);           //~va77I~
//*********************************************************************
//* parm    :dir-name,/options
//* return 0:
//*********************************************************************
int main(int parmc,char *parmp[])
{
    int dwopt;                                                     //~v100R~
    int applrc=0,filectr,totrc=0,pathlen;                            //~v127R~//~va64R~
    PPARMFNMSTACK pfnm;
    PPARMFNMSTACK pfnmo;                                           //~v112I~
    PUDIRLIST pudirlist;                                           //~v127R~
    UCHAR dirpath[_MAX_PATH];                                      //~v100I~
    UCHAR dirmask[_MAX_PATH];                                      //~v127I~
    int opt=0;                                                     //~vau1I~
//**********************************
#ifdef DPMI                                     //DPMI version
    putenv("LFN=Y");                 //need for ufileisvfat
    ufileisvfat(ISVFAT_FORCE);      //force vfat
#endif                      //DPMI or not
//**********************************
	sprintf(Spgmver,"%s:%s:",PGM,VER);                             //+vau1R~
	opt=UDCWCIO_INTERNAL;	//bypass UDBCSCHK_EXPLICIT and utfucsmapinit(0);//~vau1I~
    udbcschk_wcinit(opt,0);                                        //~va6//~vau1I~
  	uerrmsg_init(Spgmver,stdout,0);//default color                 //~vau1I~
	uerrexit_init(Spgmver,stdout,0,0,0);//no mapfile,no exit,no exit parm//~vau1I~
    parmchk(parmc,parmp);
    if (Stestsw)                                                   //~v126R~//~va77R~
        ualloc_init(UALLOC_TRACE,"xff.mtr");                       //~v126R~//~va77R~
    if (Slowsw)		//reverse order
		Sprintlimit=(ULONG)-1;
    else
		Sprintlimit=0;
#ifdef LFSSUPP                                                     //~va30I~
    if (Slowsw)		//reverse order                                //~va30I~
		Sprintlimitsz=FILESZ_MAX;                                  //~va30I~
    else                                                           //~va30I~
		Sprintlimitsz=0;                                           //~va30I~
#endif                                                             //~va30I~
//*navigate
    dwopt=UDIRWALK_NOMSG            //no err msg
//  		|UDIRWALK_DIRCALL       //callback by each dir
			|UDIRWALK_FILECALL      //callback by each file
//  		|UDIRWALK_EMPTYCALL     //callback for empty dir
//  		|UDIRWALK_EOLCALL       //callback for end of list
//  		|UDIRWALK_TOPMASK       //callback for end of list     //~v117R~
//          |UDIRWALK_SORT_NAME     //sort by name
            |UDIRWALK_LISTSLINKERR  //list also slinkerr           //~va75R~
            ;
    if (!Sskipdirsw)
    	dwopt|=UDIRWALK_DIRCALL;
#ifdef UNX                                                         //~v116M~
    if (Scdsw)                                                     //~v125I~
		dwopt|=UDIRWALK_TEMPCD;       //change dir for udirlist performance//~v125I~
#endif                                                             //~va71I~
#if defined(W32)||defined(UNX)                                     //~va71I~
	if (Sskipslinksw)                                              //~v116I~
    	dwopt|=UDIRWALK_SKIPSLINK;                                 //~v116I~
#endif                                                             //~v116M~

//  for (pfnm=UDEQ(UQUE_TOP,&Spfnmstack,0);pfnm;pfnm=UGETQNEXT(pfnm))	//enq to before of next low//~v112R~
    for (pfnm=UDEQ(UQUE_TOP,&Spfnmstack,0);pfnm;                   //~v112I~
				pfnmo=pfnm,pfnm=UGETQNEXT(pfnm),ufree(pfnmo))	//enq to before of next low//~v112I~
    {
  	  	if (Sselectid==SELECT_WILDCARD)                            //~va77I~
        {                                                          //~va77I~
    		srchwildname(pfnm->PFNname,Sfilemask,Sdepth);          //~va77R~
            continue;                                              //~va77I~
        }                                                          //~va77I~
		strcpy(dirpath,pfnm->PFNname);           //top dirname     //~v127M~
        pathlen=PATHLEN(dirpath);                                  //~v127M~
        if (WILDCARD(dirpath+pathlen))                             //~v127M~
        {                                                          //~v127M~
			strcpy(dirmask,dirpath+pathlen);                       //~v127M~
            *(dirpath+pathlen)=0;                //drop wildcard   //~v127M~
            if (!ROOTDIR(dirpath))                                 //~v127M~
                *(dirpath+pathlen-1)=0;          //drop \\;        //~v127M~
            dwopt|=UDIRWALK_TOPMASK;      //select dir only for top level//~v127M~
        }                                                          //~v127M~
        else                                                       //~v127M~
        {                                                          //~v127M~
        	*dirmask=0;                                            //~v127M~
            dwopt&=~UDIRWALK_TOPMASK;      //select dir only for top level//~v127M~
//process file entry                                               //~v127I~
#ifndef UNX                                                        //~v127R~
      if (!ROOTDIR2(pfnm->PFNname))                                //~v127R~
      {                                                            //~v127R~
#endif                                                             //~v127R~
#ifdef UNX                                                         //~v127R~
        filectr=udirlist(pfnm->PFNname,FILE_ALLSP,&pudirlist,0);    //no sort//~v127R~
#else                                                              //~v127R~
        filectr=udirlist(pfnm->PFNname,FILE_ALL,&pudirlist,0);  //no sort//~v127R~
#endif                                                             //~v127R~
        if (filectr<=0)                                            //~v127R~
            continue;                                              //~v127R~
        if (filectr==1)                                            //~v127R~
            if (!(pudirlist->attr & FILE_DIRECTORY))               //~v127R~
            {                                                      //~v127R~
                strcpy(dirpath,pfnm->PFNname);                     //~v127R~
                pathlen=PATHLEN(dirpath);                          //~v127R~
                if (pathlen>0)                                     //~v127R~
                {                                                  //~v127R~
                    *(dirpath+pathlen)=0;                          //~v127R~
                    if (!ROOTDIR(dirpath))                         //~v127R~
                        *(dirpath+pathlen-1)=0;                    //~v127R~
                }                                                  //~v127R~
                pstatchk(dirpath,pfnm->PFNname,pudirlist,1,0,&applrc);//~v127R~
                ufree(pudirlist);                                  //~v127R~
                continue;                                          //~v127R~
            }                                                      //~v127R~
        if (pudirlist)                                             //~v127R~
            ufree(pudirlist);                                      //~v127R~
#ifndef UNX                                                        //~v127R~
      }//not rootdir                                               //~v127R~
#endif                                                             //~v127R~
        }//not wildcard                                            //~v127I~
    	totrc+=udirwalk(dwopt,
//  				pfnm->PFNname,           //top dirname         //~v127R~
    				dirpath,                 //top dirname         //~v127I~
//  				"",				//no dir mask                  //~v127R~
    				dirmask,		//no dir mask                  //~v127I~
//  				"",				//no file mask                 //~v128R~
    				Sfilemask,				//file mask            //~v128I~
#ifdef UNX                                                         //~v115R~
					FILE_ALLSP-FILE_DIRECTORY,		//attr mask    //~v115I~
#else                                                              //~v115I~
					FILE_ALL-FILE_DIRECTORY,		//attr mask
#endif                                                             //~v115I~
//                  32767,  		//stop depth,half max          //~v113R~
                    Sdepth, 		//stop depth,default is half max//~v113I~
					pstatchk,		//callback function
					0,				//user data
					&applrc);
    }
 if (Sselectid!=SELECT_WILDCARD)                                   //~va77I~
 {                                                                 //~va77I~
//if (Sselectid!=SELECT_ALL && Sselectid!=SELECT_BY_NAME)          //~v123R~
  if (Sselectid!=SELECT_ALL && Sselectid!=SELECT_BY_NAME           //~v123I~
//#ifdef UNX                                                         //~v123I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
  &&  Sselectid!=SELECT_ALL_SLINK)                                 //~v123I~
#else                                                              //~v123I~
     )                                                             //~v123I~
#endif                                                             //~v123I~
	putresult();
 }                                                                 //~va77I~
    printf("%s:%s:==%c== End of process (%cb%s); %d of %d printed.\n",//~v126R~
				Spgm,Sver,OSTYPE,CMDFLAG_PREFIX,Sselparm,Sprintctr,Schkctr);//~v118R~
	if (Stestsw)                                                   //~v116R~
	    ualloc_chk(UAC_MSG);                                       //~v116R~
	ARMXSUB_CLOSE(PGM);	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//~vas3I~
    return max(applrc,totrc);
}//end main
//**********************************************************************//~va77I~
int printwildname(UCHAR *Pdir,UCHAR *Pfullpath,PUDIRLIST Ppudirlist,void *Pparm)//~va77R~
{                                                                  //~va77I~
	FILESTACK stack;                                               //~va77I~
//  PWCPARMWC puparm;                                              //~va77R~
    char slinkid;                                                  //~va77I~
    ULONG compval,compkey;                                         //~va77I~
//**************************                                       //~va77I~
//  puparm=(PWCPARMWC)Pparm;                                       //~va77R~
    if (!Pfullpath) //dir entry                                //~3B26I~//~v6q0M~//~va77I~
    	sprintf(stack.FSfpath,"%s",Pdir);                          //~va77R~
    else                                                           //~va77I~
    	strcpy(stack.FSfpath,Pfullpath);                           //~va77R~
    if (Ppudirlist->attr & FILE_DIRECTORY)                         //~va77R~
    	strcat(stack.FSfpath,DIR_SEPS);                            //~va77R~
    memcpy(&stack.FSudirlist,Ppudirlist,sizeof(UDIRLIST));	       //~va77R~
#ifdef UNX                                                         //~va77I~
    compkey=(ULONG)Ppudirlist->mtime;                              //~va77I~
    xfftime2dosfiletime(compkey,&compval);                         //~va77I~
#else                                                              //~va77I~
    #ifdef W32                                                     //~va77I~
        compval=xfffiletime2dosfiletime(&Ppudirlist->ftLastWriteTime);//~va77I~
    #else                                                          //~va77I~
        compval=FDT2ULONG(Ppudirlist->date,Ppudirlist->time);      //~va77I~
    #endif                                                         //~va77I~
    	compkey=compval;                                           //~va77I~
#endif                                                             //~va77I~
    stack.FScompkey=compkey;                                       //~va77R~
    stack.FScompkeysz=Ppudirlist->size;                            //~va77R~
    Sprintctr++;                                                   //~va77M~
    printf("--% 4d : ",Sprintctr);                                 //~va77R~
	pprtszts(&stack);                                              //~va77I~
#if defined(W32)||defined(UNX)                                     //~va77I~
    if (FILE_ISSLINK(Ppudirlist->attr))                            //~va77R~
    	slinkid='@';                                               //~va77I~
    else                                                           //~va77I~
        slinkid=' ';                                               //~va77I~
	#ifdef W32                                                     //~va77I~
      if (FILE_IS_WILDNAME(Ppudirlist->attr))//alias exists        //~va77I~
    	printf(" : %c%s (alias:%s)\n",slinkid,stack.FSfpath,Ppudirlist->alias);//~va77I~
      else                                                         //~va77I~
    	printf(" : %c%s (No 8.3 alias name)\n",slinkid,stack.FSfpath);//~va77R~
	#else                                                          //~va77I~
    	printf(" : %c%s\n",slinkid,stack.FSfpath);                 //~va77R~
	#endif                                                         //~va77I~
#else                                                              //~va77I~
    printf(" : %s\n",pfs->FSfpath);                                //~va77R~
#endif                                                             //~va77I~
    return 0;                                                      //~va77I~
}//printwildname                                                   //~va77I~
//**********************************************************************//~va77I~
int srchwildname(char *Pdir,char *Pfilemask,int Pdepth)            //~va77R~
{                                                                  //~va77I~
	int opt,ctr;                                                   //~va77R~
    WCPARMWC uparm;                                                //~va77I~
//************************                                         //~va77I~
    opt=WCWCO_MSG|WCWCO_DEPTH|WCWCO_XFF|WCWCO_DIGBYALIAS;          //~va77R~
    if (*Pfilemask)                                                //~va77I~
    {                                                              //~va77I~
	    opt|=WCWCO_FILEMASK;                                       //~va77I~
	    strcpy(uparm.wcfilemask,Pfilemask);                        //~va77R~
    }                                                              //~va77I~
	Gufile_opt|=GFILEOPT_NOWILDERRMSG ;  //skip filename invalid warning for wildname//~va77I~
    uparm.wcopt=opt;                                               //~va77I~
    uparm.wcdepth=Pdepth;                                          //~va77I~
    uparm.wcpfunc=printwildname;                                   //~va77I~
    Gufile_opt|=GFILEOPT_WILDCARDNAMEOK;    //set wildname member on udirlist//~va77I~
	ufilechkwildmemb(Pdir,&uparm);                                 //~va77R~
    ctr=uparm.wcctr;                                               //~va77I~
    Schkctr+=uparm.wcchkctr;                                       //~va77R~
    return ctr;                                                    //~va77I~
}//srchwildname                                                    //~va77I~
//**********************************************************************
//* pstatchk
//*  select file by fstat data
//*  parm1:dir name
//*  parm2:fullpathname,0 if dir entry,or empty call
//*  parm3:PUDIRLIST,0 if empty entry
//*  parm4:depth
//*  parm5:appl data
//*  parm6:appl rc area
//*  return:0:continue walk,else stop walk
//**********************************************************************
int pstatchk(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,
                                int Pdepth,void *Pdata,int *Prc)
{
    int comp;
    int sec1=0;                                                    //~v100I~
#ifdef LFSSUPP                                                     //~va30I~
    FILESZT compvalsz,compkeysz;                                   //~va30R~
#endif                                                             //~va30I~
    ULONG compval=0,compkey;                                         //~v100R~//~va64R~
	FILESTACK allfs;                                               //~v114R~
    int noenqsw=0,sidsv;                                           //~v118I~
    int rc;                                                        //~v120I~
    char dirname[_MAX_PATH];                                       //~v120I~
//**************************
    compkey=0;                                                     //~va58I~
#ifdef LFSSUPP                                                     //~va58I~
    compvalsz=0;compkeysz=0;                                       //~va58I~
#endif                                                             //~va58I~
//printf("depth=%d:dir=%s,fullpath=%s\n",Pdepth,Pdir,((Pfullpath==(char*)(-1))?0:Pfullpath));
//printf("a=%08x c=%08x m=%08x, %s\n",Ppudirlist->atime,Ppudirlist->ctime,Ppudirlist->mtime,Ppudirlist->name);
//printf("dir=%s,name=%s\n",Pdir,Ppudirlist->name);                //~v100R~
//printf("pudirlist=%08x,len=%08x,dir=%s  %s\n",Ppudirlist,*((ULONG*)(void*)Ppudirlist-1),Pdir,Ppudirlist->name);//~v112R~
    if (!Pfullpath)	//dir entry
    {                                                              //~v120I~
    	strcpy(dirname,Ppudirlist->name);                          //~v120I~
    	*Ppudirlist->name=0;		//set later
    }                                                              //~v120I~
    Schkctr++;
//get compare ulong value                                          //~v100I~
    switch(Sselectid)                                              //~v100I~
    {                                                              //~v100I~
    case SELECT_BY_SIZE:       //select by file size               //~v100I~
#ifdef LFSSUPP                                                     //~va30I~
        compvalsz=Ppudirlist->size;                                //~va30R~
    	compkeysz=compvalsz;                                       //~va30R~
#else                                                              //~va30I~
        compval=(ULONG)Ppudirlist->size;                           //~v100I~
    	compkey=compval;                                           //~v100R~
#endif                                                             //~va30I~
        break;                                                     //~v100I~
    case SELECT_BY_MTIME:       //select by file size              //~v100I~
    case SELECT_ALL:            //for pprtszts                     //~v118I~
//#ifdef UNX                                                         //~v123I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
    case SELECT_ALL_SLINK:      //list all slink                   //~v123I~
#endif                                                             //~v123I~
    case SELECT_BY_NAME:       //select by file name               //~v118I~
        if (Sselectid==SELECT_ALL)                                 //~v118I~
    		noenqsw=1;                                             //~v118I~
        else                                                       //~v118I~
//#ifdef UNX                                                         //~v123I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
        if (Sselectid==SELECT_ALL_SLINK)                           //~v123I~
        {                                                          //~v123I~
//      	if (*Ppudirlist->slink)                                //~va77R~
        	if (Ppudirlist->pslink                                 //~va77I~
        	&&  *Ppudirlist->pslink)                               //~va77I~
		    	noenqsw=2;      //no enq but slink print           //~v123I~
            else                                                   //~v123I~
		    	noenqsw=-1;     //no enq skip print                //~v123I~
        }                                                          //~v123I~
        else                                                       //~v123I~
#endif                                                             //~v123I~
        if (Sselectid==SELECT_BY_NAME)                             //~v118I~
        {                                                          //~v120I~
//          if (xffwildselect(Ppudirlist)<=0)   //0 if wildcard match,1:unmatch//~v120R~
            if (!Pfullpath) //dir entry                            //~v120R~
                rc=xffwildselect(dirname);  //0 if wildcard match,1:unmatch//~v120R~
            else                                                   //~v120R~
                rc=xffwildselect(Ppudirlist->name);  //0 if wildcard match,1:unmatch//~v120R~
            if (rc<=0)                                             //~v120R~
                noenqsw=1;                                         //~v118I~
            else                                                   //~v118I~
                noenqsw=-1;                                        //~v118I~
        }//search by name                                          //~v120I~
#ifdef UNX                                                         //~v100I~
        compkey=(ULONG)Ppudirlist->mtime;                          //~v100R~
        sec1   =xfftime2dosfiletime(compkey,&compval);             //~v100R~
#else                                                              //~v100I~
    #ifdef W32                                                     //~v100I~
        compval=xfffiletime2dosfiletime(&Ppudirlist->ftLastWriteTime);//~v100R~
    #else                                                          //~v100I~
        compval=FDT2ULONG(Ppudirlist->date,Ppudirlist->time);      //~v100I~
    #endif                                                         //~v100I~
    	compkey=compval;                                           //~v100R~
#endif                                                             //~v100I~
        break;                                                     //~v100I~
#ifdef DOS                                                         //~v100I~
#else                                                              //~v100I~
    case SELECT_BY_ATIME:       //select by file size              //~v100I~
	#ifdef UNX                                                     //~v100I~
        compkey=(ULONG)Ppudirlist->atime;                          //~v100R~
        sec1=xfftime2dosfiletime(compkey,&compval);                //~v100R~
	#else                                                          //~v100I~
    	#ifdef W32                                                 //~v100I~
        compval=xfffiletime2dosfiletime(&Ppudirlist->ftLastAccessTime);//~v100R~
    	#else                                                      //~v100I~
        compval=FDT2ULONG(Ppudirlist->adate,Ppudirlist->atime);    //~v100I~
    	#endif                                                     //~v100I~
    	compkey=compval;                                           //~v100R~
	#endif                                                         //~v100I~
        break;                                                     //~v100I~
    case SELECT_BY_CTIME:       //select by file size              //~v100I~
	#ifdef UNX                                                     //~v100I~
        compkey=(ULONG)Ppudirlist->ctime;                          //~v100R~
        sec1=xfftime2dosfiletime(compkey,&compval);                //~v100R~
	#else                                                          //~v100I~
    	#ifdef W32                                                 //~v100I~
        compval=xfffiletime2dosfiletime(&Ppudirlist->ftCreationTime);//~v100R~
    	#else                                                      //~v100I~
        compval=FDT2ULONG(Ppudirlist->cdate,Ppudirlist->ctime);    //~v100I~
    	#endif                                                     //~v100I~
    	compkey=compval;                                           //~v100R~
	#endif  //!UNX                                                 //~v100I~
        break;                                                     //~v100I~
#endif  //not DOS                                                  //~v100I~
    }                                                              //~v100I~
  if (!noenqsw)      //all or by name                              //~v118I~
	if (Sparmlimit)	//limit specified                              //~v100R~
    {                                                              //~v100I~
      if (Ssamesw)	//select same date only                        //~v119I~
      {                                                            //~v119I~
      	comp=(int)((Sparmlimit>>16)-(compval>>16));	//compare date only//~va1GR~
        if (comp)                                                  //~v119I~
        	return 0;		//date unmatch                         //~v119I~
      }                                                            //~v119I~
      else                                                         //~v119I~
      if (Ssamesw2)	//time compare                                 //~va1GI~
      {                                                            //~va1GI~
          if (Ssamesw2==1)  //same hh                              //~va1GR~
            	comp=(int)((Sparmlimit>>11)-(compval>>11));    //drop mm(6) and twosec(5)//~va1GR~
          else                                                     //~va1GR~
          if (Ssamesw2==2)  //same hhmm(ignore sec)                //~va1GR~
            	comp=(int)((Sparmlimit>>5)-(compval>>5));  //compare date,hhmm//~va1GR~
          else                                                     //~va1GI~
            	comp=(int)(Sparmlimit-compval);  //compare date,hhmmss//~va1GR~
          if (comp) 	//unmatch                                  //~va1GI~
            	return 0;       //date unmatch                     //~va1GI~
      }                                                            //~va1GI~
      else                                                         //~va1GI~
      {                                                            //~v119I~
#ifdef LFSSUPP                                                     //~va30I~
       if (Sselectid==SELECT_BY_SIZE)       //select by file size  //~va30I~
    		comp=xffcompfsz((FILESZT)Sparmlimit,compvalsz);        //~va30R~
       else                                                        //~va30I~
       {                                                           //~va30I~
#endif                                                             //~va30I~
		if (Sparmlimit==compval)                                   //~v100I~
//  		comp=xffcompul((Sparmlimit<<1)+Sparmsec1,(compval<<1)+sec1);//~v100I~//~vaa0R~
    		comp=xffcompul((Sparmlimit<<1)+(ULONG)Sparmsec1,(compval<<1)+(ULONG)sec1);//~vaa0I~
        else                                                       //~v100I~
	    	comp=xffcompul(Sparmlimit,compval);                    //~v100I~
#ifdef LFSSUPP                                                     //~va30I~
       }	//not ny size                                          //~va30I~
#endif                                                             //~va30I~
//printf("comp=%d,lim=%08x,compval=%08x\n",comp,Sparmlimit,compval);//~v100R~
    	if (Slowsw)		//reverse order
    		comp=-comp;
    	if (comp>0)
    		return 0;		//bypass
      }//not same date search                                      //~v119I~
    }//limit specified
//if (Sselectid==SELECT_ALL)                                       //~v118R~
  if (noenqsw)      //all or by name                               //~v118R~
  {                                                                //~v114I~
   if (noenqsw>0)   //print required                               //~v118R~
   {                                                               //~v118I~
    Sprintctr++;                                                   //~v118I~
    memcpy(&allfs.FSudirlist,Ppudirlist,sizeof(UDIRLIST));         //~v114R~
    strcpy(allfs.FSfpath,Pdir);                                    //~v114I~
    if (!ROOTDIR(Pdir))                                            //~v114I~
    	strcat(allfs.FSfpath,DIR_SEPS);                            //~v114I~
    strcat(allfs.FSfpath,Ppudirlist->name);                        //~v114I~
    if (Sverbosesw)                                                //~v114I~
    {                                                              //~va74I~
        pprtszts(&allfs);                                          //~v114I~
    }                                                              //~va74I~
    else                                                           //~v114I~
    {                                                              //~v114I~
     if (noenqsw!=2)	//not slink print                          //~v123I~
     {                                                             //~v123I~
#ifdef LFSSUPP                                                     //~va30I~
    	allfs.FScompkeysz=Ppudirlist->size;                        //~va30I~
#else                                                              //~va30I~
    	allfs.FScompkey=(ULONG)Ppudirlist->size;                   //~v114R~
#endif                                                             //~va30I~
        sidsv=Sselectid;                                           //~v118M~
        Sselectid=SELECT_BY_SIZE;                                  //~v114R~
        pprtszts(&allfs);                                          //~v114R~
        printf(", ");                                              //~v114R~
        allfs.FScompkey=compkey;    //mod time                     //~v114R~
        Sselectid=SELECT_BY_MTIME;                                 //~v114R~
        pprtszts(&allfs);                                          //~v114R~
//      Sselectid=SELECT_ALL;                                      //~v118R~
        Sselectid=sidsv;                                           //~v118I~
      }                                                            //~v123I~
    }                                                              //~v114I~
//#ifdef UNX                                                         //~v123I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
    if (noenqsw==2)	//slink print                                  //~v123I~
    {                                                              //~va74I~
        pprtszts_slink(&allfs);                                    //~va74M~
//  printf(" : %s --> %s\n",allfs.FSfpath,allfs.FSudirlist.slink); //~va77R~
    printf(" : %s --> %s\n",allfs.FSfpath,allfs.FSudirlist.pslink);//~va77I~
    }                                                              //~va74I~
    else                                                           //~v123I~
#endif                                                             //~v123I~
    printf(" : %s\n",allfs.FSfpath);                               //~v114I~
   }//noenqsw==1                                                   //~v118I~
  }                                                                //~v114I~
  else                                                             //~v114I~
  {                                                                //~v114I~
//chk with previous max/min
#ifdef LFSSUPP                                                     //~va30I~
   if (Sselectid==SELECT_BY_SIZE)       //select by file size      //~va30I~
   	comp=xffcompfsz(Sprintlimitsz,compkeysz);                      //~va30I~
   else                                                            //~va30I~
#endif                                                             //~va30I~
    comp=xffcompul(Sprintlimit,compkey);   //over previous max     //~v100R~
    if (Slowsw)		//reverse order
    	comp=-comp;
    if (comp<=0)
    	paddstack(Ppudirlist,Pdir,compkey);                        //~v100R~
  }//not ALL                                                       //~v114I~
	return 0;			//continue walk
}//pstatchk
//**********************************************************************//~v118I~
//* xffwildselect                                                  //~v118I~
//*  parm1:filename(without path)                                  //~v120R~
//*  return:-1:wildcard match,0:exact match,1:unmatch              //~v118I~
//**********************************************************************//~v118I~
//int xffwildselect(PUDIRLIST Ppudirlist)                          //~v120R~
int xffwildselect(char *Pfnm)                                      //~v120I~
{                                                                  //~v118I~
	char *fnm;                                                     //~v118I~
    int  rc;                                                       //~v118I~
    int  wcopt;                                                    //~v121I~
//  UCHAR targetname[_MAX_PATH];                                   //~v121R~
//**************************                                       //~v118I~
//  fnm=Ppudirlist->name;		//filename                         //~v120R~
    fnm=Pfnm;               	//filename                         //~v120I~
//    if (Snamewildsw)                                             //~v121R~
//        ufileeditname(fnm,Snamestr,targetname);                  //~v121R~
//    else                                                         //~v121R~
//        strcpy(targetname,Snamestr);                             //~v121R~
//    if (Scasesw)                                                 //~v121R~
//        rc=strcmp(targetname,fnm);                               //~v121R~
//    else                                                         //~v121R~
//        rc=stricmp(targetname,fnm);                              //~v121R~
    wcopt=UFWC_DOS_DEFAULT | UFWC_CASE_DEFAULT | UFWC_0BYTE;       //~v121I~
    if (Scasesw)                                                   //~v121I~
    	wcopt|=UFWC_CASE;   //case sencitive                       //~v121I~
    else                                                           //~v121I~
    	wcopt&=~UFWC_CASE;  //case insensitive                     //~v121I~
    rc=ufilewildcomp(wcopt,fnm,Snamestr,Snamedbcs);                //~v121R~
    if (!rc)	//match                                            //~v118I~
    	if (Snamewildsw)                                           //~v118I~
    		rc=-1;      //wildcard match                           //~v118I~
        else                                                       //~v118I~
        	rc=0;		//exact match                              //~v118I~
    else                                                           //~v118I~
    	rc=1;			//unmatch                                  //~v118I~
    return rc;                                                     //~v118I~
}//xffwildselect                                                   //~v118I~
//**********************************************************************
//* paddstack
//*  parm1:PUDIRLIST
//*  parm2:dirname to generate fullpath
//*  return:0
//**********************************************************************
int paddstack(PUDIRLIST Ppudirlist,char *Pdir,ULONG Pcompkey)      //~v100R~
{
	PFILESTACK pfs,pfsnext,newpfs,pfsdel;
    int  qectr,comp;
//**************************
//printf("addstack:dir=%s,name=%s \n",Pdir,Ppudirlist->name);      //~v100R~
//  newpfs=ucalloc(FILESTACKSZ,1);                                 //~v111R~
    newpfs=ucalloc(1,FILESTACKSZ);                                 //~v111I~
//printf("=newpfs=%08x \n",newpfs);                                //~v100R~
    if (!newpfs)                                                   //~v100I~
        uerrexit("Storage shortage!!",0);                          //~v100I~
	newpfs->FScompkey=Pcompkey;	//compare key                      //~v100R~
#ifdef LFSSUPP                                                     //~va30I~
	newpfs->FScompkeysz=Ppudirlist->size;	//size compare key     //~va30I~
#endif                                                             //~va30I~
    memcpy(&newpfs->FSudirlist,Ppudirlist,sizeof(UDIRLIST));
    strcpy(newpfs->FSfpath,Pdir);                                  //~v100R~
    if (!ROOTDIR(Pdir))
    	strcat(newpfs->FSfpath,DIR_SEPS);                          //~v100R~
    strcat(newpfs->FSfpath,Ppudirlist->name);                      //~v100R~
    comp=-1;    //for 1st time enq
    for (pfs=UGETQTOP(&Sfilestack);pfs;pfs=UGETQNEXT(pfs))
    {
//printf("comp pfs=%08x a=%08x c=%08x m=%08x, %s\n",pfs,pfs->FSudirlist.atime,pfs->FSudirlist.ctime,pfs->FSudirlist.mtime,pfs->FSfpath);//~v100R~
#ifdef LFSSUPP                                                     //~va30I~
       if (Sselectid==SELECT_BY_SIZE)       //select by file size  //~va30I~
    	comp=xffcompfsz(pfs->FScompkeysz,newpfs->FScompkeysz);     //~va30I~
       else                                                        //~va30I~
#endif                                                             //~va30I~
        comp=xffcompul(pfs->FScompkey,Pcompkey);   //smaller than prev//~v100R~
    	if (Slowsw)		//reverse order
    		comp=-comp;
    	if (comp<=0)   //new large
        	break;
    }
    if (comp<0 || !pfs)
    {
        if (pfs)        //not 1st time
//  		qectr=UENQENT(UQUE_BEF,pfs,newpfs);	//enq to before of next low//~vaa1R~
    		qectr=(int)UENQENT(UQUE_BEF,pfs,newpfs);	//enq to before of next low//~vaa1I~
        else
//  		qectr=UENQ(UQUE_END,&Sfilestack,newpfs);	//enq to before of next low//~vaa1R~
    		qectr=(int)UENQ(UQUE_END,&Sfilestack,newpfs);	//enq to before of next low//~vaa1I~
//printf("enq bef  qectr=%d/\n",qectr,Smaxstack);                  //~v100R~
        if (qectr>Smaxstack)
        {
	    	pfsdel=UDEQ(UQUE_END,&Sfilestack,0);	//enq to before of next low
//printf("deq %s\n",pfsdel->FSfpath);                              //~v100R~
            while(pfsnext=UDEQ(UQUE_TOP,&pfsdel->FSsameqh,0),pfsnext)   //not 1st same chain
            {
//printf("deq %s\n",pfsnext->FSfpath);                             //~v100R~
            	ufree(pfsnext);
            }
            ufree(pfsdel);
            pfs=UGETQEND(&Sfilestack); 	//new last
#ifdef LFSSUPP                                                     //~va30I~
       	  if (Sselectid==SELECT_BY_SIZE)       //select by file size//~va30I~
    	    Sprintlimitsz=pfs->FScompkeysz;                        //~va30I~
       else                                                        //~va30I~
#endif                                                             //~va30I~
	        Sprintlimit=pfs->FScompkey;                            //~v100R~
        }//ctr exceeded
    }
    else		//same value
    {
//printf("enq same ,pfs=%08x\n",pfs);                              //~v100R~
	    UENQ(UQUE_END,&(pfs->FSsameqh),newpfs);	//enq to same value que
    }
	return 0;			//continue walk
}//paddstack
//**********************************************************************
//* putresult
//*  return:none
//**********************************************************************
void putresult(void)
{
	PFILESTACK pfs,pfsnext;
	PFILESTACK pfso;                                               //~v112I~
    int ii,selsw=0;                                                //~v100R~
//#ifdef UNX                                                         //~v116I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
    char slinkid;                                                  //~v116I~
#endif                                                             //~v116I~
//**************************
//  for (ii=0,pfs=UGETQTOP(&Sfilestack);pfs;ii++,pfs=UGETQNEXT(pfs))//~v112R~
	for (ii=0,pfs=UGETQTOP(&Sfilestack);pfs;ii++,                  //~v112I~
					pfso=pfs,pfs=UGETQNEXT(pfs),ufree(pfso))       //~v112I~
    {
    	selsw=1;                                                   //~v100I~
    	printf("--% 4d : ",ii+1);
    	Sprintctr++;                                               //~v118I~
        pprtszts(pfs);
//#ifdef UNX                                                         //~v116I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
//      if (S_ISLNK(FILE_GETMODE(pfs->FSudirlist.attr)))           //~v116I~//~va71R~
        if (FILE_ISSLINK(pfs->FSudirlist.attr))                    //~va71I~
            slinkid='@';                                           //~v116I~
        else                                                       //~v116I~
            slinkid=' ';                                           //~v116I~
        printf(" : %c%s\n",slinkid,pfs->FSfpath);                  //~v116R~
#else                                                              //~v116I~
        printf(" : %s\n",pfs->FSfpath);                            //~v100R~
#endif                                                             //~v116I~
//  	for (pfsnext=UGETQTOP(&pfs->FSsameqh);pfsnext;pfsnext=UGETQNEXT(pfsnext))	//not 1st same chain//~v112R~
    	for (pfsnext=UGETQTOP(&pfs->FSsameqh);pfsnext;             //~v112I~
					pfso=pfsnext,pfsnext=UGETQNEXT(pfsnext),ufree(pfso))	//not 1st same chain//~v112I~
        {
            printf("       : " );
    		Sprintctr++;                                           //~v118I~
            pprtszts(pfsnext);
//#ifdef UNX                                                         //~v116I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
//          if (S_ISLNK(FILE_GETMODE(pfsnext->FSudirlist.attr)))   //~v116I~//~va71R~
            if (FILE_ISSLINK(pfsnext->FSudirlist.attr))            //~va71I~
            	slinkid='@';                                       //~v116I~
            else                                                   //~v116I~
            	slinkid=' ';                                       //~v116I~
            printf(" : %c%s\n",slinkid,pfsnext->FSfpath);          //~v116I~
#else                                                              //~v116I~
            printf(" : %s\n",pfsnext->FSfpath);                    //~v100R~
#endif                                                             //~v116I~
        }
    }
//if (Sselectid!=SELECT_ALL)                                       //~v118R~
    if (!selsw)                                                    //~v100I~
    	printf("No file selected.\n");                             //~v100R~
    return;
}//putresult
//**********************************************************************
//* pprtszts
//* print timestamp,size
//*  parm1:PUSTACKFILE
//*  return:none
//**********************************************************************
void pprtszts(PFILESTACK Ppfs)
{
//  UCHAR editfsz[16];                                             //~va30R~
    UCHAR editfsz[32];                                             //~va30I~
	UCHAR editts [3][32];
    ULONG compkey;                                                 //~v100I~
#ifdef UNX                                                         //~v100I~
#else                                                              //~v100I~
    USHORT usdt,ustm;                                              //~v100I~
#endif                                                             //~v100I~
#ifdef LFSSUPP                                                     //~va30I~
	FILESZT compkeysz;                                             //~va30I~
#endif                                                             //~va30I~
//**************************
    compkey=Ppfs->FScompkey;                                       //~v100I~
#ifdef LFSSUPP                                                     //~va30R~
    compkeysz=Ppfs->FScompkeysz;                                   //~va30I~
#endif                                                             //~va30I~
	if (Sverbosesw)
    {
#ifdef LFSSUPP                                                     //~va30R~
	  if (Ppfs->FSudirlist.size>>32)                               //~va30I~
	    bc_dweditnum64(0/*functype*/,'Z'/*Pconvtype*/,Ppfs->FSudirlist.size,editfsz);//~va30I~
      else                                                         //~va30I~
    	unumedit((ULONG)(Ppfs->FSudirlist.size),"z,zzz,zzz,zz9",editfsz);//~va30I~
#else                                                              //~va30I~
    	unumedit(Ppfs->FSudirlist.size,"z,zzz,zzz,zz9",editfsz);
#endif                                                             //~va30M~
#ifdef UNX
        peditts(Ppfs->FSudirlist.mtime,editts[0]);
        peditts(Ppfs->FSudirlist.ctime,editts[1]);
        peditts(Ppfs->FSudirlist.atime,editts[2]);
#else
	#ifdef W32
        pedittsfiletime(&Ppfs->FSudirlist.ftLastWriteTime,editts[0]);//~v100R~
    #else
        peditts(Ppfs->FSudirlist.date,Ppfs->FSudirlist.time,editts[0]);
    #endif
    #ifdef DOS
    #else
		#ifdef W32
        	pedittsfiletime(&Ppfs->FSudirlist.ftCreationTime,editts[1]);//~v100R~
        #else
	        peditts(Ppfs->FSudirlist.cdate,Ppfs->FSudirlist.ctime,editts[1]);
        #endif
		#ifdef W32
        	pedittsfiletime(&Ppfs->FSudirlist.ftLastAccessTime,editts[2]);//~v100R~
        #else
	        peditts(Ppfs->FSudirlist.adate,Ppfs->FSudirlist.atime,editts[2]);
        #endif
    #endif
#endif
#ifdef DOS                                                         //~v100R~
        printf("%c=%s, %c=%s",
        		SELECT_BY_SIZE,editfsz,
        		SELECT_BY_MTIME,editts[0]);
#else                                                              //~v100R~
        printf("%c=%s, %c=%s, %c=%s, %c=%s",
        		SELECT_BY_SIZE,editfsz,
        		SELECT_BY_MTIME,editts[0],
        		SELECT_BY_CTIME,editts[1],
        		SELECT_BY_ATIME,editts[2]);
#endif                                                             //~v100R~
    }
    else    //not verbose                                          //~v100R~
    {
        switch (Sselectid)                                         //~v100R~
        {
        case SELECT_BY_SIZE:       //select by file size
#ifdef LFSSUPP                                                     //~va30R~
	  	  if (compkeysz>>32)                                       //~va30I~
	         bc_dweditnum64(0/*functype*/,'Z'/*Pconvtype*/,compkeysz,editfsz);//~va30I~
          else                                                     //~va30I~
            unumedit((ULONG)compkeysz,"z,zzz,zzz,zz9",editfsz);    //~va30R~
#else                                                              //~va30I~
            unumedit(compkey,"z,zzz,zzz,zz9",editfsz);             //~v100R~
#endif                                                             //~va30I~
            printf("%c=%s",Sselectid,editfsz);
            break;
        default:
#ifdef UNX                                                         //~v100I~
//          peditts(compkey,editts[0]);                            //~v100I~//~vaa0R~
            peditts((time_t)compkey,editts[0]);                    //~vaa0I~
#else                                                              //~v100I~
            usdt=(USHORT)(compkey>>16);                            //~v100R~
			ustm=(USHORT)(compkey & 0xffff);                       //~v100I~
//          peditts(*(FDATE*)(ULONG)&usdt,*(FTIME*)(ULONG)&ustm,editts[0]);//~v100R~//~va66R~
	#ifdef W32                                                     //~va6dI~
        	pedittsfiletime(&Ppfs->FSudirlist.ftLastWriteTime,editts[0]);//~va6dI~
    #else                                                          //~va6dI~
            peditts(*(FDATE*)(ULPTR)&usdt,*(FTIME*)(ULPTR)&ustm,editts[0]);//~va66I~
    #endif                                                         //~va6dI~
#endif                                                             //~v100I~
            printf("%c=%s",Sselectid,editts[0]);
        }
    }//not verbose                                                 //~v100R~
    return;
}//pprtszts
//**********************************************************************//~va74I~
//* print slink target                                             //~va74I~
//**********************************************************************//~va74I~
void pprtszts_slink(PFILESTACK Ppfs)                               //~va74I~
{                                                                  //~va74I~
    UCHAR editfsz[32];                                             //~va74I~
	UCHAR editts [1][32];                                          //~va74I~
//**************************                                       //~va74I~
#ifdef LFSSUPP                                                     //~va74I~
	  if (Ppfs->FSudirlist.slinksize>>32)                          //~va74I~
	    bc_dweditnum64(0/*functype*/,'Z'/*Pconvtype*/,Ppfs->FSudirlist.slinksize,editfsz);//~va74I~
      else                                                         //~va74I~
    	unumedit((ULONG)(Ppfs->FSudirlist.slinksize),"z,zzz,zzz,zz9",editfsz);//~va74I~
#else                                                              //~va74I~
    	unumedit(Ppfs->FSudirlist.slinksize,"z,zzz,zzz,zz9",editfsz);//~va74I~
#endif                                                             //~va74I~
#ifdef UNX                                                         //~va74I~
        peditts(Ppfs->FSudirlist.slinkmtime,editts[0]);            //~va74I~
#else                                                              //~va74I~
        peditts(Ppfs->FSudirlist.slinkfdate,Ppfs->FSudirlist.slinkftime,editts[0]);//~va74I~
#endif                                                             //~va74I~
        printf("%c=%s, %c=%s",                                     //~va74I~
        		SELECT_BY_SIZE,editfsz,                            //~va74I~
        		SELECT_BY_MTIME,editts[0]);                        //~va74R~
    return;                                                        //~va74I~
}//pprtszts_slink                                                  //~va74I~
#ifdef UNX
//**********************************************************************
//* peditts
//* print timestamp
//*  parm1:timestamp
//*  parm2:output edit timestamp area addr
//**********************************************************************
char *peditts(time_t Ptm,char *Peditout)
{
struct    tm* ptm;       //date and time
//**************************
	if (Ptm)
    {
        ptm=localtime(&Ptm);    //date and time
        sprintf(Peditout,"%02d-%02d-%02d  %02d:%02d:%02d",
            (int)ptm->tm_year+1900,
            (int)ptm->tm_mon+1,
            (int)ptm->tm_mday,
            (int)ptm->tm_hour,
            (int)ptm->tm_min,
            (int)ptm->tm_sec);
    }
    else
    	*Peditout=0;
    return Peditout;
}//peditts
#else   //!UNX
//**********************************************************************
//* peditts
//* print timestamp
//*  parm1:timestamp
//*  parm2:output edit timestamp area addr
//**********************************************************************
char *peditts(FDATE Pdate,FTIME Ptime,char *Peditout)
{
//**************************
//  if (*(USHORT*)(ULONG)&Pdate || *(USHORT*)(ULONG)&Ptime)        //~v100R~
//  {                                                              //~v100R~
		ufdateedit(Pdate,"YY-MM-DD  ",Peditout);    //date and time
		uftimeedit(Ptime,"HH:MM:SS",Peditout+10);    //date and time
//  }                                                              //~v100R~
//  else                                                           //~v100R~
//  	*Peditout=0;                                               //~v100R~
    return Peditout;
}//peditts
#endif  //!UNX
                                                                   //~v100I~
#ifdef W32                                                         //~v100I~
//**********************************************************************//~v100M~
//* pedittsfiletime                                                //~v100I~
//* print timestamp                                                //~v100M~
//*  parm1:timestamp                                               //~v100M~
//*  parm2:output edit timestamp area addr                         //~v100M~
//**********************************************************************//~v100M~
char *pedittsfiletime(FILETIME *Ppftm,char *Peditout)              //~v100I~
{                                                                  //~v100M~
	FDATE fdate;                                                   //~v100M~
	FTIME ftime;                                                   //~v100M~
    FILETIME lft;                                                  //~v100M~
    int oddsec;                                                    //~va6dI~
//**************************                                       //~v100M~
    FileTimeToLocalFileTime(Ppftm,&lft);                           //~v100M~
//	if (FileTimeToDosDateTime(&lft,(USHORT*)(ULONG)&fdate,(USHORT*)(ULONG)&ftime))//~v100M~//~va66R~
    if (filetime2dosdatetime(&lft,(USHORT*)(ULPTR)&fdate,(USHORT*)(ULPTR)&ftime,&oddsec))//~va66I~//~va6dR~
    {                                                              //~v100M~
		ufdateedit(fdate,"YY-MM-DD  ",Peditout);    //date and time//~v100M~
//		uftimeedit(ftime,"HH:MM:SS",Peditout+10);    //date and time//~v100M~//~va6dR~
  		uftimeedit_1sec(ftime,"HH:MM:SS",Peditout+10,oddsec);    //date and time//~va6dI~
    }                                                              //~v100M~
    else                                                           //~v100M~
    	*Peditout=0;                                               //~v100M~
    return Peditout;                                               //~v100M~
}//pedittsfiletime                                                 //~v100I~
#endif	//W32                                                      //~v100I~
//**********************************************************************
//* comp ulong
//*parm1:
//*return:ULONG fdate/ftime
//**********************************************************************
int xffcompul(ULONG Pul1,ULONG Pul2)
{
	int rc;
//******************
    if (Pul1>Pul2)
    	rc=1;
    else
    if (Pul1<Pul2)
    	rc=-1;
    else
    	rc=0;
//printf("comptswin:rc=%d,%08lx-%08lx\n",rc,Pul1,Pul2);
	return rc;
}//xffcompul
#ifdef LFSSUPP                                                     //~va30I~
//**********************************************************************//~va30I~
//* comp ulong                                                     //~va30I~
//*parm1:                                                          //~va30I~
//*return:ULONG fdate/ftime                                        //~va30I~
//**********************************************************************//~va30I~
int xffcompfsz(FILESZT Plimit,FILESZT Pfsz)                        //~va30R~
{                                                                  //~va30I~
	int rc;                                                        //~va30I~
//******************                                               //~va30I~
	if ((FILESZT)Plimit==Pfsz)                                     //~va30I~
    	rc=0;                                                      //~va30I~
    else                                                           //~va30I~
    if ((FILESZT)Plimit<Pfsz)                                      //~va30I~
    	rc=-1;                                                     //~va30I~
    else                                                           //~va30I~
    	rc=1;                                                      //~va30I~
    return rc;                                                     //~va30I~
}//xffcompfsz                                                      //~va30I~
#endif                                                             //~va30I~
#ifdef UNX
//**********************************************************************
//* conv time to dosfiletime
//*parm1:ulong sec from 1970
//*return:ULONG fdate/ftime
//**********************************************************************
int xfftime2dosfiletime(ULONG Ptime,ULONG *Ppdosdatetime)          //~v100R~
{
    struct    tm* ptm;       //date and time
    FDATE fdt;
    FTIME ftm;
    long  ptime;                                                   //~v100R~
//**************
//  ptime=Ptime;                                                   //~v100R~//~vaa0R~
    ptime=(long)Ptime;                                             //~vaa0I~
    ptm=localtime(&ptime);                                         //~v100I~
//#ifdef AIX                                                         //~v100I~//~vaa2R~
//    fdt.dummy=0;                                                   //~v100R~//~vaa2R~
//#endif                                                             //~v100I~//~vaa2R~
//  fdt.year =ptm->tm_year-80;  	//unix:~1900,dos:~1980         //~v100I~//~vaa2R~
//  fdt.month=ptm->tm_mon+1;                                       //~vaa2R~
//  fdt.day  =ptm->tm_mday;                                        //~vaa2R~
    ueditsetfdateUSHORT(0,ptm->tm_year-80,ptm->tm_mon+1,ptm->tm_mday,&fdt);//~vaa2I~
//#ifdef AIX                                                         //~v100I~//~vaa2R~
//    ftm.dummy=0;                                                   //~v100I~//~vaa2R~
//#endif                                                             //~v100I~//~vaa2R~
//  ftm.hours  =ptm->tm_hour;                                      //~vaa2R~
//  ftm.minutes=ptm->tm_min;                                       //~vaa2R~
//  ftm.twosecs=ptm->tm_sec/2;                                     //~vaa2R~
    ueditsetftimeUSHORT(0,ptm->tm_hour,ptm->tm_min,ptm->tm_sec/2,&ftm);//~vaa2I~
    *Ppdosdatetime=FDT2ULONG(fdt,ftm);                             //~v100R~
    return ptm->tm_sec%2;                                          //~v100I~
}//xfftime2dosfiletime
#else
#ifdef W32
//**********************************************************************
//*conv FILETIME to DosDateTime
//**********************************************************************
ULONG xfffiletime2dosfiletime(FILETIME *Ppftm)                     //~v100R~
{
	USHORT fdate;
	USHORT ftime;
    FILETIME lft;
//*************************
    FileTimeToLocalFileTime(Ppftm,&lft);
//  FileTimeToDosDateTime(&lft,&fdate,&ftime);                     //~va6dR~
    filetime2dosdatetime(&lft,&fdate,&ftime,0/*Ppoddsec*/);        //~va6dI~
	return FDT2ULONG(fdate,ftime);
}//xfffiletime2dosfiletime                                         //~v100R~
#else	//DOS,OS/2
#endif
#endif

//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
    unsigned char c,chsv;    //read char                           //~v100R~
    char *cptr,*cptr0;         //char ptr work
    int limitsw=0,levelsw=0,timesw=0,datesw=0;                     //~v100R~
    int  parmno,ii,jj,kk,len,rc; //parm count work
    long numval; //parm count work
    int posparmno=0; //parm count work
	PPARMFNMSTACK 	pnewpfnm;
    char ppwd[_MAX_PATH];                                          //~v118M~
    char ctimewk[8];                                               //~v119I~
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
#ifdef UNX
        if(*cptr=='-')
#else
        if(*cptr=='/'||*cptr=='-')
#endif
        {//option
        	c=*(++cptr);                      //first option byte
            switch(toupper(c))             //option
            {
//**************************
//* cmd string     /?      *
//**************************
            case '?':           //cmd string start
            case 'H':           //apply to file
                help();
                exit(0);
                break;
            case 'D':           //depth                            //~v113I~
                Sdepth=atoi(cptr+1);                               //~v113R~
                break;                                             //~v113I~
//#ifdef DOS                                                       //~v122R~
//#else                                                            //~v122R~
//            case 'A':           //by access time                 //~v122R~
//            case 'C':           //by status change time          //~v122R~
//#endif                                                           //~v122R~
//            case 'F':           //by name                        //~v122R~
//            case 'M':           //by modified time               //~v122R~
//            case 'S':           //by fileszie                    //~v122R~
            case 'B':           //By                               //~v122R~
                c=*(++cptr);         //skip b                      //~v123R~
                if (Sselectidsw)                                   //~v118R~
                    uerrexit("Duplicated selection type parm",0);  //~v118I~
                Sselectidsw=1;                                     //~v118I~
            	Sselparm=cptr;
    	        switch(toupper(c))             //option
        	    {
#ifdef DOS                                                         //~v100I~
#else                                                              //~v100I~
	            case 'A':           //by access time
                  if (!stricmp(cptr,"ALL"))                        //~v114I~
                	Sselectid=SELECT_ALL;                          //~v114I~
                  else                                             //~v114I~
                	Sselectid=SELECT_BY_ATIME;
                    break;
	            case 'C':           //by access time
                	Sselectid=SELECT_BY_CTIME;
                    break;
#endif                                                             //~v100I~
//              case 'F':           //by name                      //~v122R~
                case 'N':           //by name                      //~v122I~
                	Sselectid=SELECT_BY_NAME;                      //~v118R~
                    Snamestr=cptr+1;                               //~v118R~
                    if (!*Snamestr)                                //~v118R~
                        optionerr("filename",cptr0);               //~v118I~
                    Snamewildsw=WILDCARD(Snamestr)!=0;             //~v118R~
                    len=(int)strlen(Snamestr);                     //~v121I~
//                  Snamedbcs=umalloc((UINT)len);                  //~v126R~
        			usetdbcstbl(USDT_CODE_DEFAULT,Snamestr,Snamedbcs,len);//~v121R~
                    break;                                         //~v118I~
    	        case 'M':           //by modified time
                	Sselectid=SELECT_BY_MTIME;
                    break;
        	    case 'S':           //by fileszie
                	Sselectid=SELECT_BY_SIZE;
                    break;
//#ifdef UNX                                                         //~v123I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
                case 'L':                                          //~v123I~
                	Sselectid=SELECT_ALL_SLINK;                    //~v123R~
                    break;                                         //~v123I~
#endif                                                             //~v123I~
                case 'W':                                          //~va77I~
                	Sselectid=SELECT_WILDCARD;                     //~va77I~
                    break;                                         //~va77I~
                default:                                           //~v123I~
                    optionerr("Select option",cptr0);              //~v123I~
                }
                if (Sselectid==SELECT_ALL)                         //~v114I~
                	break;                                         //~v114I~
                if (Sselectid==SELECT_BY_NAME)                     //~v118I~
                	break;                                         //~v118I~
                cptr++;
                if (*cptr=='-')
                {
                	Slowsw=1;
                    cptr++;
                }
                if (*cptr=='=')                                    //~v119I~
                {                                                  //~v119I~
                	if (Sselectid!=SELECT_BY_MTIME                 //~v119I~
                	&&  Sselectid!=SELECT_BY_ATIME                 //~v119I~
                	&&  Sselectid!=SELECT_BY_CTIME)                //~v119I~
                        uerrexit("\"=\" is valid with date specification.",0);//~v119I~
                	Ssamesw=1;                                     //~v119I~
                    cptr++;                                        //~v119I~
                }                                                  //~v119I~
                if (*cptr)		//sz or ts parm
                {
                    limitsw=1;                                     //~v100I~
                    len=(int)strlen(cptr);
                    if (Sselectid==SELECT_BY_SIZE)             //option
                    {
                    	Sparmlimit=(ULONG)atol(cptr);              //~v100R~
                        if (unumlen(cptr,0,len)!=len)
                        {                                          //~va1GI~
                        	if (unumlen(cptr,0,len)!=len-1)
                                optionerr("filesize",cptr0);
                        	else
                            {
                                c=(UCHAR)toupper(*(cptr+len-1));
                                switch(c)
                                {
                                case 'M':
                                    Sparmlimit*=1024;              //~v100R~
                                    Sparmlimit*=1024;              //~v100R~
                                    break;
                                case 'K':
                                    Sparmlimit*=1024;              //~v100R~
                                    break;
                                default:
	                                optionerr("filesize",cptr0);
                                }//size unit
                            }//numlen
                        }//len                                     //~va1GI~
                    }//size
                    else
                    {
                      if (*cptr==TODAYID && *(cptr+1)==0)	//today//~v119R~
                      {                                            //~v119I~
	                    datesw=1;   //asume date specified         //~v119I~
						utimeedit("YYMMDD",ctimewk);               //~v119I~
					    getnum(ctimewk,&ii,&jj,&kk);               //~v119I~
                        xffsetdate(&Sparmlimit,ii,jj,kk);          //~v119I~
                      }                                            //~v119I~
                      else                                         //~v119I~
                      {                                            //~v119I~
                        if (len!=6 && len!=13)
        					optionerr("ts parm",cptr);
                        chsv=*(cptr+6);                            //~v100R~
                        *(cptr+6)=0;                               //~v100I~
				        rc=getnum(cptr,&ii,&jj,&kk);
        				if (rc)
        					optionerr("Date parm",cptr);
                        if (xffsetdate(&Sparmlimit,ii,jj,kk))      //~v100R~
        					optionerr("Date parm",cptr);
                        datesw=1;                                  //~v100I~
                        if (len>6)
                        {
//                      	if (Ssamesw)                           //~va1GR~
//                          	uerrexit("specify date only with \"=\".",0);//~va1GR~
				        	rc=getnum(cptr+7,&ii,&jj,&kk);
        					if (rc)
        						optionerr("Date parm",cptr);
                            timesw=1;                              //~v100I~
                        }
                        else
                        	ii=jj=kk=0;
                        if (Ssamesw)                               //~va1GI~
                        {                                          //~va1GI~
                        	if (ii==99)                            //~va1GI~
                                ii=jj=kk=0;                        //~va1GI~
                            else                                   //~va1GI~
                        	if (jj==99)                            //~va1GI~
                            {                                      //~va1GI~
                                Ssamesw=0;                         //~va1GR~
                            	Ssamesw2=1;//ignore mmss           //~va1GI~
                                jj=kk=0;                           //~va1GI~
                            }                                      //~va1GI~
                            else                                   //~va1GI~
                            if (kk==99)                            //~va1GR~
                            {                                      //~va1GR~
                                Ssamesw=0;                         //~va1GR~
                                Ssamesw2=2;//ignore ss             //~va1GR~
                                kk=0;                              //~va1GR~
                            }                                      //~va1GR~
                            else                                   //~va1GI~
                            {                                      //~va1GI~
                              if (timesw)//time parm               //~va1HI~
                              {                                    //~va1HI~
                                Ssamesw=0;                         //~va1GI~
                                Ssamesw2=3;//match hhmmss          //~va1GI~
                              }                                    //~va1HI~
                            }                                      //~va1GI~
                        }                                          //~va1GI~
                        if (xffsettime(&Sparmlimit,ii,jj,kk))      //~v100R~
        					optionerr("Date parm",cptr);
                        Sparmsec1=kk%2;                            //~v100R~
                        *(cptr+6)=chsv;                            //~v100I~
                      }// "." or else                              //~v119I~
                    }
                }
                break;
            case 'F':           //by fileszie                      //~v128I~
                Sfilemask=cptr+1;                                  //~v128I~
                break;                                             //~v128I~
            case 'L':           //by fileszie
                levelsw=1;                                         //~v100I~
                numval=atol(cptr+1);
                if (numval>0)
                	Smaxstack=numval;
                break;
            case 'V':           //by fileszie
                Sverbosesw=1;
                break;
//**************************
//* yes    option  /Y      *
//**************************
            case 'Y':           //toggle on
                for (;;)
                {
                    c=*(++cptr);
                    if (!c)
                        break;
                    switch(toupper(c))
                    {
#ifdef DOS                                                         //~v118I~
#else                                                              //~v118I~
                    case 'C':       //case sensitive               //~v118I~
                        Scasesw=1;                                 //~v118I~
                        break;                                     //~v118I~
#endif                                                             //~v118I~
                    case 'D':       //no dir
                        Sskipdirsw=0;
                        break;
//#ifdef UNX                                                         //~v116I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
                    case 'M':       //no dir                       //~v122I~
                      	Gufile_opt&=~GFILEOPT_NOSLINKERRMSG;       //~v122I~
                        break;                                     //~v122I~
#endif                                                             //~va71I~
#ifdef UNX                                                         //~va71I~
                    case 'P':   //cd for udirlist performance up   //~v125I~
                      	Scdsw=1;                                   //~v125I~
                        break;                                     //~v125I~
#endif                                                             //~va71I~
#if defined(W32)||defined(UNX)                                     //~va71I~
                    case 'S':       //no dir                       //~v116I~
                        Sskipslinksw=0;                            //~v116R~
                        break;                                     //~v116I~
#endif                                                             //~v116I~
                    case 'T':       //no dir                       //~v116I~
                        Stestsw=1;                                 //~v116I~
						ualloc_init(UALLOC_TRACE,"xff.mtr");       //~v126I~
                        break;                                     //~v116I~
                    case '9':       //dbcs sw
                        UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
                        UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs
                        break;
                    default:                           //not option
                        optionerr("Yes/No option",cptr0);
                    }
                }
                break;
//**************************
//* no     option  /N      *
//**************************
            case 'N':           //toggle on
                for (;;)
                {
                    c=*(++cptr);
                    if (!c)
                        break;
                    switch(toupper(c))
                    {
#ifdef DOS                                                         //~v118I~
#else                                                              //~v118I~
                    case 'C':       //case sensitive               //~v118I~
                        Scasesw=0;                                 //~v118I~
                        break;                                     //~v118I~
#endif                                                             //~v118I~
                    case 'D':       //no dir
                        Sskipdirsw=1;
                        break;
//#ifdef UNX                                                         //~v116I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
                    case 'M':       //no dir                       //~v122I~
                      	Gufile_opt|= GFILEOPT_NOSLINKERRMSG;       //~v122I~
                        break;                                     //~v122I~
#endif                                                             //~va71I~
#ifdef UNX                                                         //~va71I~
                    case 'P':   //cd for udirlist performance up   //~v125I~
                      	Scdsw=0;                                   //~v125I~
                        break;                                     //~v125I~
#endif                                                             //~va71I~
#if defined(W32)||defined(UNX)                                     //~va71I~
                    case 'S':       //no dir                       //~v116I~
                        Sskipslinksw=1;                            //~v116R~
                        break;                                     //~v116I~
#endif                                                             //~v116I~
                    case 'T':       //no dir                       //~v116I~
                        Stestsw=0;                                 //~v116I~
                        break;                                     //~v116I~
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
            continue;
		}//option
//pos parm
        posparmno++;
//  	pnewpfnm=ucalloc(PARMFNMSTACKSZ,1);                        //~v111R~
    	pnewpfnm=ucalloc(1,PARMFNMSTACKSZ);                        //~v111I~
        strcpy(pnewpfnm->PFNname,cptr0);
#ifndef UNX                                                        //~v101R~
      if (!memcmp(pnewpfnm->PFNname,DRIVE_ALL,sizeof(DRIVE_ALL)-1))//~v112R~
         xffalldrive(pnewpfnm);                                    //~v101R~
      else                                                         //~v101R~
      {                                                            //~v101R~
#endif                                                             //~v101R~
		if (!ufullpath(pnewpfnm->PFNname,cptr0,sizeof(pnewpfnm->PFNname)))
    		exit(8);
    	UENQ(UQUE_END,&Spfnmstack,pnewpfnm);	//enq to before of next low//~v100R~
#ifndef UNX                                                        //~v101R~
      }                                                            //~v101R~
#endif                                                             //~v101R~
	}//for all parm
//chk more
    if (!posparmno)
    	uerrexit("dir-name parameter is required\n",
            	 "ディレクトリー名を指定して下さい");
    if (limitsw && !levelsw)//limit parm without level parm        //~v100I~
		Smaxstack=MAXSTACK2;                                       //~v100I~
    if (datesw && !timesw)	//no time parm                         //~v100R~
    	if (Slowsw)	//reverse                                      //~v100I~
        {                                                          //~v100I~
        	xffsettime(&Sparmlimit,23,59,59); //set max time       //~v100R~
            Sparmsec1=1;                                           //~v100I~
//printf("Sparmlimit %08x\n",Sparmlimit);                          //~v100R~
        }                                                          //~v100I~
//log                                                              //~v118I~
    printf("*** %s ",Spgm);                                        //~v121R~
    for (parmno=1;parmno<parmc;parmno++)                           //~v118I~
        printf(" %s",parmp[parmno]);                               //~v118R~
    printf(" *** cd=%s\n",ugetcwd(ppwd));                          //~v118R~
}//parmchk
#ifndef UNX                                                        //~v101R~
//*********************************************************************//~v101R~
//* xffalldrive                                                    //~v101R~
//*  replace *: to C: etc and enq to parm filename list            //~v101R~
//*parm1:PPARMFNMSTACK of current parm                             //~v101R~
//*return:none                                                     //~v101R~
//*********************************************************************//~v101R~
void xffalldrive(PPARMFNMSTACK Ppfnm)                              //~v101R~
{                                                                  //~v101R~
	PPARMFNMSTACK 	pnewpfnm;                                      //~v101R~
    char didlist[26];                                              //~v101I~
    int ii,didctr;                                                 //~v101R~
//******************************                                   //~v101R~
	didctr=ugetdriveidlist(UDDC_FIXED,didlist);                    //~v101R~
    for (ii=0;ii<didctr;ii++)                                      //~v101R~
    {                                                              //~v101R~
        *(Ppfnm->PFNname)=didlist[ii];  //a:                       //~v101R~
//      pnewpfnm=ucalloc(PARMFNMSTACKSZ,1);                        //~v111R~
        pnewpfnm=ucalloc(1,PARMFNMSTACKSZ);                        //~v111I~
        if (!ufullpath(pnewpfnm->PFNname,Ppfnm->PFNname,sizeof(pnewpfnm->PFNname)))//~v101R~
            exit(8);                                               //~v101R~
//printf("%s\n",Ppfnm->PFNname);                                   //~v118R~
        UENQ(UQUE_END,&Spfnmstack,pnewpfnm);    //enq to before of next low//~v101R~
    }                                                              //~v101R~
    ufree(Ppfnm);                                                  //~v101R~
    return;                                                        //~v101R~
}//xffalldrive                                                     //~v101R~
#endif                                                             //~v101R~
//**********************************************************************
//* generate FDATE
//*parm1:output ULONG(FDATE/FTIME) addr
//*parm2:yy
//*parm3:mm
//*parm4:dd
//*return:rc;
//**********************************************************************
int xffsetdate(ULONG *Pts,int Pyy,int Pmm,int Pdd)
{
    FDATE fdt;
    FTIME ftm;                                                     //~v100R~
    int rc=0;
    int yy,mm,dd;                                                  //~vaa2I~
//**************
    memset(&ftm,0,sizeof(ftm));                                    //~v100I~
    if (Pyy<80)
//      fdt.year =(USHORT)(2000-1980+Pyy);                         //~va6aR~//~vaa2R~
        yy=2000-1980+Pyy;                                          //~vaa2I~
    else
//      fdt.year =(USHORT)(Pyy-80);                                //~va6aR~//~vaa2R~
        yy=Pyy-80;                                                 //~vaa2I~
    if (Pmm>=1 && Pmm<=12)
//  	fdt.month=(USHORT)Pmm;                                     //~va6aR~//~vaa2R~
    	mm=Pmm;                                                    //~vaa2I~
    else
    {                                                              //~va77I~
//  	fdt.month=1;    //for compiler warning:not init            //~va77I~//~vaa2R~
    	mm=1;    //for compiler warning:not init                   //~vaa2I~
    	rc=4;
    }                                                              //~va77I~
    if (Pdd>=1 && Pdd<=31)
//  	fdt.day  =(USHORT)Pdd;                                     //~va6aR~//~vaa2R~
    	dd=Pdd;                                                    //~vaa2I~
    else
    {                                                              //~va77I~
//  	fdt.day=1;    //for compiler warning:not init              //~va77I~//~vaa2R~
    	dd=1;    //for compiler warning:not init                   //~vaa2I~
    	rc=4;
    }                                                              //~va77I~
    ueditsetfdateUSHORT(0,yy,mm,dd,&fdt);                          //~vaa2I~
    *Pts=*Pts|FDT2ULONG(fdt,ftm);
//printf("xffsetdate %08x yy=%d,mm=%d,dd=%d\n",*Pts,Pyy,Pmm,Pdd);  //~v100R~
    return rc;
}//xffsetdate
//**********************************************************************
//* generate FTIME
//*parm1:output ULONG(FDATE/FTIME) addr
//*parm2:yy
//*parm3:mm
//*parm4:dd
//*return:rc;
//**********************************************************************
int xffsettime(ULONG *Pts,int Phh,int Pmm,int Pss)
{
    FTIME ftm={0};                                                 //~va64R~
    FDATE fdt;                                                     //~v100R~
    int rc=0;
    int hh=0,mm=0,ss=0;                                            //~vaa2I~
//**************
    memset(&fdt,0,sizeof(fdt));                                    //~v100I~
    if (Phh>=0 && Phh<=23)
//      ftm.hours  =(USHORT)Phh;                                   //~va6aR~//~vaa2R~
        hh=Phh;                                                    //~vaa2I~
    else
    	rc=4;
    if (Pmm>=0 && Pmm<=59)
//      ftm.minutes=(USHORT)Pmm;                                   //~va6aR~//~vaa2R~
        mm=Pmm;                                                    //~vaa2I~
    else
    	rc=4;
    if (Pss>=0 && Pss<=59)
//      ftm.twosecs=(USHORT)(Pss/2);                               //~va6aR~//~vaa2R~
        ss=Pss/2;                                                  //~vaa2I~
    else
    	rc=4;
    ueditsetftimeUSHORT(0,hh,mm,ss,&ftm);                          //~vaa2I~
    *Pts=*Pts|FDT2ULONG(fdt,ftm);
//printf("xffsettime %08x %d,%d,%d\n",*Pts,Phh,Pmm,Pss);           //~v100R~
    return rc;
}//xffsettime
//**********************************************************************
//* get 3 int value
//*parm1:parm string
//*parm2:out int area1
//*parm3:out int area1
//*parm4:out int area1
//*return:rc;
//**********************************************************************
int getnum(char *Pdata,int *Ppi1,int *Ppi2,int *Ppi3)
{
    int len,i1,i2,i3;
//****************
    len=(int)strlen(Pdata);
    switch(len)
    {
    case 1:           //"0"
    	if (*Pdata!='0')
        	return 4;
        i1=i2=i3=0;
    	break;
    case 4:           //"hhmm"
		if (unumlen(Pdata  ,0,4)!=4)
	    	return 4;
		i1=uatoin(Pdata,  2);
		i2=uatoin(Pdata+2,2);
		i3=0;
    	break;
    case 5:           //"hh:mm"
		if (unumlen(Pdata  ,0,2)!=2
		||  *(Pdata+2)!=':'
    	||  unumlen(Pdata+3,0,2)!=2)
    		return 4;
		i1=uatoin(Pdata,  2);
		i2=uatoin(Pdata+3,2);
		i3=0;
    	break;
    case 6:           //"yymmdd"
		if (unumlen(Pdata  ,0,6)!=6)
	    	return 4;
		i1=uatoin(Pdata,  2);
		i2=uatoin(Pdata+2,2);
		i3=uatoin(Pdata+4,2);
    	break;
    case 8:           //"yy:mm:dd"
		if (unumlen(Pdata  ,0,2)!=2
    	||  unumlen(Pdata+3,0,2)!=2
    	||  unumlen(Pdata+6,0,2)!=2)
    		return 4;
		i1=uatoin(Pdata,  2);
		i2=uatoin(Pdata+3,2);
		i3=uatoin(Pdata+6,2);
    	break;
	default:
    	return 4;
	}
	*Ppi1=i1;
	*Ppi2=i2;
	*Ppi3=i3;
    return 0;
}//getnum
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
#ifdef UNX                                                         //~v119I~
#else                                                              //~v119I~
    char manyparmmsg[256];                                         //~v119I~
#endif                                                             //~v119I~
//*******************
        HELPMSG
"%s : %s=(%c)= File Find by Timestamp or Size.\n",
"%s : %s=(%c)= ファイル サーチ by タイムスタンプ,サイズ\n",
                Spgm,Sver,OSTYPE);
        HELPMSG
"fmt  : %s [%coptions] directory [directory...]\n",
"形式 : %s [%coptions] directory [directory...]\n",
                Spgm,CMDFLAG_PREFIX);
        HELPMSG
"  directory :search in this directory.\n",
"  directory 探索ディレクトリー名\n");
#ifndef UNX                                                        //~v101R~
        HELPMSG                                                    //~v101R~
"             \"*:\" means all fixed drive.\n",                    //~v101R~
"             \"*:\" で全固定ドライブを意味する。\n");             //~v101R~
#endif                                                             //~v101R~
        HELPMSG
"  options   :\n",                                                 //~v118R~
"  options   :\n");                                                //~v118R~
        HELPMSG                                                    //~v114I~
"    %cball      :List all file.(For redirect to grep).\n",        //~v121R~
"    %cball      :全ファイルをリストする。(grepにリダイレクトして使う時など)。\n",//~va30R~
				CMDFLAG_PREFIX);                                   //~v114I~
//#ifdef UNX                                                         //~v123I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
        HELPMSG                                                    //~v123I~
//"    %cbl        :List symbolic link.(attr is of slink source)\n", //~v123R~//~va71R~
//"    %cbl        :シンボリックリンクをリストする。属性はリンク\x83\\ースを\x95\\示。\n",//~v123R~//~va71R~
"    %cbl        :List symbolic link.(attr is of slink target)\n", //~va71I~
"    %cbl        :シンボリックリンクをリストする。属性はリンク先を\x95\\示。\n",//~va71I~
				CMDFLAG_PREFIX);                                   //~v123I~
#endif                                                             //~v123I~
        HELPMSG                                                    //~v118I~
"    %cbnName    :Case-insensitive search by name. Name:wild card allowed.\n",//~v121R~
"    %cbnName    :大文字小文字区別なしの名前で探す。Name:ワイルドカード指定可\x94\\。\n",//~v121R~
				CMDFLAG_PREFIX);                                   //~v118I~
#ifdef DOS
#else
	#ifdef OS2
        HELPMSG
"    %cba[[-|=]ts] :search by access time.(avail for HPFS only).\n",//~v122R~
"    %cba[[-|=]ts] :アクセスタイムで探す。(HPFSでのみ有効)。\n",   //~v122R~
				CMDFLAG_PREFIX);
    #else
        HELPMSG
"    %cba[[-|=]ts] :search by access time.\n",                     //~v122R~
"    %cba[[-|=]ts] :アクセスタイムで探す。\n",                     //~v122R~
				CMDFLAG_PREFIX);
    #endif
#endif
//#ifdef AIX                                                       //~va3gR~
#ifdef UNX                                                         //~va3gI~
        HELPMSG
"    %cbc[[-|=]ts] :search by status change time\n",               //~v122R~
"    %cbc[[-|=]ts] :ステータス変更タイムで探す。\n",               //~v122R~
				CMDFLAG_PREFIX);
#else
  #ifdef DOS
  #else
	#ifdef OS2
        HELPMSG
"    %cbc[[-|=]ts] :search by creation time.(avail for HPFS only).\n",//~v122R~
"    %cbc[[-|=]ts] :作成タイムで探す。(HPFSでのみ有効)。\n",       //~v122R~
				CMDFLAG_PREFIX);
    #else
        HELPMSG
"    %cbc[[-|=]ts] :search by creation time\n",                    //~v122R~
"    %cbc[[-|=]ts] :作成タイムで探す。\n",                         //~v122R~
				CMDFLAG_PREFIX);
    #endif
  #endif
#endif
        HELPMSG
"    %cbm[[-|=]ts] :search by data modified time\n",               //~v122R~
"    %cbm[[-|=]ts] :変更タイムで探す。\n",                         //~v122R~
				CMDFLAG_PREFIX);
        HELPMSG
"    %cbs[[-]sz] :search by file size\n",                          //~v122R~
"    %cbs[[-]sz] :ファイルサイズで探す。\n",                       //~v122R~
				CMDFLAG_PREFIX);
        HELPMSG                                                    //~va77I~
"    %cbw        :search wildcard(*/?) name\n",                    //~va77R~
"    %cbw        :ワイルドカード(*/?)を含む名前を探す。\n",        //~va77I~
				CMDFLAG_PREFIX);                                   //~va77I~
        HELPMSG
"                default is %cbm. ts is yymmdd[:hhmmss] format time sttamp.\n",//~v121R~
"                省略値は %cbm。ts は yymmdd[:hhmmss] 形式のタイムスタンプ。\n",//~v121R~
				CMDFLAG_PREFIX);
        HELPMSG                                                    //~v119M~
"                Use \"%c\" for today's date.\n",                  //~v119R~
"                当日日付は　ts に \"%c\" を指定するとよい。\n",   //~v119R~
					TODAYID);                                      //~v119I~
        HELPMSG
"                sz is nn[K|M] format size. \n",                   //~v119R~
"                sz は nn[K|M] 形式のファイルサイズ。\n");         //~v119R~
        HELPMSG
"                With \"-\",list ascending order of files with lower than it.\n",//~v119R~
"                \"-\" 付きの時、指定値以下のファイルの昇順出力。\n");//~v119R~
//        HELPMSG                                                  //~va1GI~
//"                With \"=\",list descending order of files with same date as it.\n",//~va1GI~
//"                \"=\" 付きの時、日付が一致するファイルの降順出力。\n");//~va1GI~
        HELPMSG                                                    //~v119I~
"                With \"=\",list descending order of same hh if mm=99,\n",//~va1GR~
"                \"=\" 付きの時、mm=99で時間が一致、ss=99で時分が一致、\n");//~va1GR~
        HELPMSG                                                    //~va1GI~
"                same hhmm if ss=99, same date with no hhmmss.\n", //~va1GI~
"                hhmmss指定なしで、日付が一致するファイルの降順出力。\n");//~va1GR~
        HELPMSG                                                    //~v119M~
"                Without \"-\"/\"=\",descending order of files with larger than it.\n",//~v119R~
"                \"-\"/\"=\" 無しのとき、指定値以上のファイルを降順出力。\n");//~v119R~
        HELPMSG
"                list top or bottom(-) entry if no ts/sz specified.\n",
"                ts/sz指定の無いときは、上位あるいは下位(-)を\x95\\示。\n");//~v119R~
        HELPMSG                                                    //~v113I~
"    %cd[nn]    :subdir search Depth. 1 means no subdir search. default is %d.\n",//~v113R~
"    %cd[nn]    :探索サブ Dirの深さ。1 でサブ Dirは探索しない。省略値は %d。\n",//~v113R~
				CMDFLAG_PREFIX,Sdepth);                            //~v113I~
        HELPMSG                                                    //~v128I~
"    %cFmask    :file name wildcard selection.\n",                 //~v128I~
"    %cFmask    :ファイル名選択のワイルドカード。\n",              //~v128I~
				CMDFLAG_PREFIX);                                   //~v128I~
        HELPMSG                                                    //~v123M~
"    %cLnn      :List max nn entry. default is %d w/o ts/sz,%d with ts/sz.\n",//~v123M~
"    %cLnn      :最大 nn 個をリスト。省略値は ts/szの指定無で %d、有で %d。\n",//~v123M~
				CMDFLAG_PREFIX,MAXSTACK,MAXSTACK2);                //~v123M~
        HELPMSG
"    %cv        :Verbose\n",
"    %cv        :ファイル情報詳細出力。\n",
				CMDFLAG_PREFIX);
        HELPMSG
"    %cNd       :skip for directory.\n",
"    %cNd       :ディレクトリーは対象外とする。\n",
				CMDFLAG_PREFIX);
//#ifdef UNX                                                         //~v116I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
        HELPMSG                                                    //~v122I~
"    %cNm       :No symbolic link err msg.\n",                     //~v122I~
"    %cNm       :シンボリックリンクエラーMsgを出力しない。\n",     //~v122I~
				CMDFLAG_PREFIX);                                   //~v122I~
        HELPMSG                                                    //~v116I~
"    %cNs       :skip symbolic link.\n",                           //~v116I~
"    %cNs       :シンボリックリンクはバイパス。\n",                //~v116I~
				CMDFLAG_PREFIX);                                   //~v116I~
#endif                                                             //~v116I~
#ifdef DOS                                                         //~v118I~
#else                                                              //~v118I~
        HELPMSG                                                    //~v118I~
"    %cYc       :Name search(%cbn) with Case-sensitiveness.\n",    //~v122R~
"    %cYc       :名前による探索(%cbn)を大文字小文字区別有りで行う。\n",//~v122R~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~v118I~
#endif                                                             //~v118I~
#ifdef UNX
        HELPMSG                                                    //~v119M~
"(Sample  )  %s . ; %s . %cbm=%c ; %s %cbs2m %cvar ; %s %cbndb2inst*.conf /usr\n",//~v122R~
"(サンプル)  %s . ; %s . %cbm=%c ; %s %cbs2m %cvar ; %s %cbndb2inst*.conf /usr\n",//~v122R~
				Spgm,Spgm,CMDFLAG_PREFIX,TODAYID,Spgm,CMDFLAG_PREFIX,DIR_SEPC,Spgm,CMDFLAG_PREFIX);//~v119R~
#else
                                                                   //~v119I~
	    sprintf(manyparmmsg,"%s %cbm *: ; %s %cbnconfig.* c:%c",   //~v122R~
				Spgm,CMDFLAG_PREFIX,Spgm,CMDFLAG_PREFIX,DIR_SEPC); //~v119I~
        HELPMSG                                                    //~v119I~
"(ex) %s . ; %s . %cbm=%c ; %s %cbs2m c:%cvar ; %s\n",             //~v122R~
"(例) %s . ; %s . %cbm=%c ; %s %cbs2m c:%cvar ; %s\n",             //~v122R~
				Spgm,Spgm,CMDFLAG_PREFIX,TODAYID,Spgm,CMDFLAG_PREFIX,DIR_SEPC,manyparmmsg);//~v119R~
#endif
	return;
}//help
