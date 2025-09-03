//*CID://+vau1R~:                             update#=  174;       //~vau1R~
//***********************************************************      //~v000I~
//* XDS  : display directory size                                  //~v000I~
//***********************************************************      //~v000I~
//vau1:250706 uerrmsg_init missing.(No dbcs errmsg)                //~vau1I~
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//vae0:170206 xds v1.11 invalid filename fmt msg for unprintable utf8;if not UD_MODE, ufullpath call _fullpath//~vae0I~
//                      it drops UD_NOTLC. SET_UDMODE is required. //~vae0I~
//vaa0:160417 Lnx compiler warning                                 //~vaa0I~
//va71:130618 (W32)dirwalk support windows slink/junction/mountpoint//~va71I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va58:111217 compiler warning,uninitialized                       //~va58I~
//va4s:110129 xds:1.8 (BUG) errmsg "dword and dword" for %calc     //~va4sI~
//va4r:100902 xds:1.7 (BUG) useage % err when aval>4GB(Dword)      //~va4rI~
//va48:081011 ugetdiskfree interface changed for UNC(\\...) filename support//~va48I~
//061227 va30:v1.5 filesize>4GB support                            //~va30I~
//021214 xds:v1.4 v151 no performance up effect by setting curdir  //~v151I~
//021214 xds:v1.4 v150 no dir sort for performance                 //~v151R~
//021210 xds:v1.4 v149 wildcard apply also to top level file(same as unx shell expansion)//~v149I~
//021207 xds:v1.4 v148 (UNX)performance tuning(udirlist stat call at curdir)//~v148I~
//021009 xds:v1.4 v147 (UNX)skip slink errmsg option(/Nm)(u#125)   //~v147R~
//020811 xds:v1.4 v146 (!UNX)display free space only option (/u)   //~v146I~
//020803 xds:v1.4 v145 (!UNX)display free space                    //~v145I~
//020727 xds:v1.4 v144 size edit max 999GB                         //~v144I~
//020725 xds:v1.4 v143 multi dir parm support                      //~v142I~
//020723 xds:v1.4 v142 add filemask option                         //~v142I~
//                    (dir mask is specified on dirname parm)      //~v142I~
//020711 xds:v1.4 v141 option to skip slink                        //~v141I~
//020710 xds:v1.4 v140 more large MAXDEPTH and chk overflow        //~v140I~
//xds.c v1.30 *020217 wildcard support                             //~v120I~
//xds.c v1.20 *011015 UNX support                                  //~v120I~
//xds.c  *v1.1 *000423 v001 modify help msg                        //~v001I~
//***********************************************************      //~v000I~
                                                                   //~v000I~
#define VER "V1.12"   //version                                     //~va30R~//~va48R~//~va4rR~//~va71R~//~vaa0R~//~vae0R~//~vau1R~
#define PGM "xds"                                                  //~v120R~
                                                                   //~v000I~
//**********************************************/                  //~v000I~
//*parm  : dir name                                                //~v000I~
//*        /Lx depth level                                         //~v000I~
//*        /Lx depth level                                         //~v000I~
//*r.c   : 0 :normal,else err                                      //~v000I~
//**********************************************/                  //~v000I~
//*                                                                //~v000I~
#include <time.h>                                                  //~v000I~
#include <stdio.h>                                                 //~v000I~
#include <stdlib.h>                                                //~v000I~
#include <ctype.h>                                                 //~v000I~
#include <string.h>                                                //~v000I~
#ifdef UNX                                                         //~v120I~
	#include <sys/stat.h>                                          //~v141I~
#else                                                              //~v120I~
#include <conio.h>                                                 //~v000I~
#endif                                                             //~v120I~
                                                                   //~v000I~
#ifdef DOS                                                         //~v000I~
	#include <dos.h>                                               //~v000I~
#else                                                              //~v000I~
  #ifdef W32                                                       //~v000I~
	#include <dos.h>                                               //~v000I~
  #else                                                            //~v000I~
  #endif                                                           //~v000I~
#endif                                                             //~v000I~
                                                                   //~v000I~
//*********************************************************************//~v000I~
#include <ulib.h>                                                  //~v000I~
#include <ufile.h>                                                 //~v000I~
#include <uerr.h>                                                  //~v000I~
#include <ualloc.h>                                                //~v000I~
#include <ufile4.h>                                                //~v000I~
#include <ustring.h>                                               //~v000I~
#include <uedit.h>                                                 //~v000I~
#include <uque.h>                                                  //~v143R~
#include <ucalc.h>                                                 //~va4rI~
#include <ucalc2.h>                                                //~v144I~
#ifndef UNX                                                        //~v143I~
	#include <udos2.h>                                             //~v143I~
#endif                                                             //~v143I~
#include <utrace.h>                                                //~va71I~
#include <udbcschk.h>                                              //+vau1R~
//*********************************************************************//~v000I~
#define HELPMSG         uerrhelpmsg(stdout,stderr,                 //~v000I~
//#define MAXDEPTH        20                                       //~v140R~
#define MAXDEPTH        256                                        //~v140R~
                                                                   //~v000I~
typedef struct _PARMFNMSTACK{                        //file hdr    //~v143R~
                           	UQUEE     PFNqelem;                    //~v143R~
                    	   	char      PFNname[_MAX_PATH];          //~v143R~
                         	}  PARMFNMSTACK,  *PPARMFNMSTACK;      //~v143R~
#define PARMFNMSTACKSZ (sizeof(PARMFNMSTACK))                      //~v143R~
#ifndef UNX                                                        //~v143I~
	#define DRIVE_ALL  "*:"                                        //~v143I~
#endif                                                             //~v143I~
//*********************************************************************//~v000I~
static char *Spgm=PGM,*Sver=VER;                                   //~v000I~
static char Sdirnm[_MAX_PATH];                                     //~v000R~
static char Sfilemask[_MAX_PATH]={0};                              //~v120R~
static char Sdirmask[_MAX_PATH];                                   //~v142I~
static int  Sparmdepth=0;                                          //~v000R~
static int  Sparmdepthsw=0;  	// -l parm specified               //~v143I~
static int  Smultifilesw=0;                                        //~v143R~
#ifdef ULIB64                                                      //~vaa0R~
static UINT4 Sdirsz[MAXDEPTH+1];                                   //~vaa0M~
static UINT4 Sfilesz[MAXDEPTH+1];                                  //~vaa0M~
static UINT4 Sdirsz_high[MAXDEPTH+1];                              //~vaa0M~
static UINT4 Sfilesz_high[MAXDEPTH+1];                             //~vaa0M~
#else                                                              //~vaa0M~
//static ULONG Sdirsz[MAXDEPTH+1];                                   //~v140R~//~vaa0R~
//static ULONG Sfilesz[MAXDEPTH+1];                                  //~v140R~//~vaa0R~
//static ULONG Sdirsz_high[MAXDEPTH+1];                              //~v144I~//~vaa0R~
//static ULONG Sfilesz_high[MAXDEPTH+1];                             //~v144I~//~vaa0R~
static LONG Sdirsz[MAXDEPTH+1];                                    //~vaa0I~
static LONG Sfilesz[MAXDEPTH+1];                                   //~vaa0I~
static LONG Sdirsz_high[MAXDEPTH+1];                               //~vaa0I~
static LONG Sfilesz_high[MAXDEPTH+1];                              //~vaa0I~
#endif                                                             //~vaa0I~
static UQUEH  Spfnmstack;	 //parmfnm stack                       //~v143R~
//#ifdef UNX                                                         //~v141I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
static int  Sskipslinksw=1; //skip symbolic link                   //~v141I~
static int  Sslinkfilectr=0;                                       //~v141R~
static int  Sslinkdirctr=0;                                        //~v141I~
#endif                                                             //~va71I~
#ifdef UNX                                                         //~va71I~
  #ifdef LNX                                                       //~v149I~
	static int  Scdsw=0;                                           //~v149I~
  #else                                                            //~v149I~
	static int  Scdsw=0;                                           //~v151R~
  #endif                                                           //~v149I~
#endif                                                             //~v141I~
static int Susagesw=0;                                             //~v146I~
static	char Spgmver[18];                                          //~vau1I~
//************************************                             //~v000I~
void parmchk(int,char *[]);                                        //~v000I~
int psizechk(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,      //~v000I~
                                int Pdepth,void *Pdata,int *Prc);  //~v000I~
//void putsize(char *Pdir,int Pdepth,ULONG Pdirsz,ULONG Pfilesz);  //~v144R~
void putsize(char *Pdir,int Pdepth);                               //~v144I~
void help(void);                                                   //~v000I~
void optionerr(char *type,char* value);                            //~v000I~
void ustackfnm(char *Pfnm);                                        //~v143R~
//*********************************************************************//~v000I~
//* parm    :dir-name,/options                                     //~v000I~
//* return 0:                                                      //~v000I~
//*********************************************************************//~v000I~
int main(int parmc,char *parmp[])                                  //~v000I~
{                                                                  //~v000I~
    int dwopt,rc,applrc=0;    //rc=0 for the case Susage                                       //~v000R~//~va64R~
    int pathlen;                                                   //~v120I~
	PPARMFNMSTACK pfnm,pfnmo;                                      //~v143R~
//  char filemask[_MAX_PATH];                                      //~v142R~
#ifndef UNX                                                        //~v145M~
	int drvid,userate;                                             //~v145R~
    long drvfreesz[26][2],drvsz[26][2]; //for A:-->Z:              //~v151R~
    long clustersz;                                                //~v145M~
	UDISKINFO udiskinfo;                                           //~v145M~
//  ULONG dweditwk[3],divider;                                     //~va4rR~
//  ULONG dweditwk[3],dweditwk1[4],dweditwk2[4];                   //~va4rI~//~va64R~
    long dweditwk[3],dweditwk1[4],dweditwk2[4];                    //~va64I~
    char size1[32],size2[32];                                      //~v145M~
#endif                                                             //~v145M~
    int opt;                                                       //~vau1I~
//**********************************                               //~v000I~
//* main                                                           //~v000I~
//**********************************                               //~v000I~
#ifdef W32UNICODE                                                  //~vae0I~
    SET_UDMODE();  //filename by UD format                         //~vae0I~
#endif                                                             //~vae0I~
    rc=0;       //compiler warning,uninitialized                   //~va58I~
#ifdef DPMI                                     //DPMI version     //~v000I~
    putenv("LFN=Y");                 //need for ufileisvfat        //~v000I~
        ufileisvfat(ISVFAT_FORCE);      //force vfat               //~v000I~
#endif                      //DPMI or not                          //~v000I~
//**********************************                               //~v000I~
	sprintf(Spgmver,"%s:%s:",Spgm,Sver);                           //~vau1R~
	opt=UDCWCIO_INTERNAL;	//bypass UDBCSCHK_EXPLICIT and utfucsmapinit(0);//~vau1I~
    udbcschk_wcinit(opt,0);                                        //~va6//~vau1I~
  	uerrmsg_init(Spgmver,stdout,0);//default color                 //~vau1I~
	uerrexit_init(Spgmver,stdout,0,0,0);//no mapfile,no exit,no exit parm//~vau1I~
    parmchk(parmc,parmp);                                          //~v000I~
    if (UGETQCTR(&Spfnmstack)>1)                                   //~v143R~
    	Smultifilesw=1;                                            //~v143R~
    if (Smultifilesw && !Sparmdepth && !Sparmdepthsw)//parm depth not specified//~v143R~
    	Sparmdepth=1;	                                           //~v143I~
#ifndef UNX                                                        //~v145I~
	for (drvid=0;drvid<26;drvid++)                                 //~v145R~
    	drvfreesz[drvid][0]=-1;		//init                         //~v145R~
#endif                                                             //~v145I~
 if (!Susagesw)	//not usage only                                   //~v146I~
 {                                                                 //~v146I~
//printf("       dir-size       of files  dir name\n");            //~va30R~
//printf(" -------------- --------------  ----------------------------------------------\n");//~va30R~
  printf("           dir-size         file total  dir name\n");    //~va30I~
  printf(" ------------------ ------------------  --------------------------------------\n");//~va30I~
 }                                                                 //~v146I~
  for (pfnm=UDEQ(UQUE_TOP,&Spfnmstack,0);pfnm;                     //~v143R~
				pfnmo=pfnm,pfnm=UGETQNEXT(pfnm),ufree(pfnmo))   //enq to before of next low//~v143R~
  {                                                                //~v143R~
  	strcpy(Sdirnm,pfnm->PFNname);                                  //~v143R~
#ifndef UNX                                                        //~v145I~
    drvid=toupper(*Sdirnm)-'A';                                    //~v145I~
    if (drvfreesz[drvid][0]==-1)	//not yet                      //~v145R~
    {                                                              //~v145I~
//  	if (rc=ugetdiskfree(*Sdirnm,&udiskinfo),!rc)               //~v145R~//~va48R~
    	if (rc=ugetdiskfree(Sdirnm,&udiskinfo),!rc)                //~va48I~
        {                                                          //~v145I~
            clustersz=(long)udiskinfo.bytes_per_sector*(long)udiskinfo.sectors_per_cluster;//~v145I~
//printf ("clustersz=%d,sectersz=%d,sectno=%d,avail=%d,total=%d\n",//~v145R~
//          clustersz,                                             //~v145R~
//          udiskinfo.bytes_per_sector,udiskinfo.sectors_per_cluster,//~v145R~
//          udiskinfo.avail_clusters,                              //~v145R~
//          udiskinfo.total_clusters);                             //~v145R~
    		dweditwk[0]=0;                                         //~v145I~
            dweditwk[1]=(long)udiskinfo.avail_clusters;            //~v145R~
            ucalc_dwmult(dweditwk,clustersz);                      //~v145I~
    		drvfreesz[drvid][0]=dweditwk[0];                       //~v145I~
    		drvfreesz[drvid][1]=dweditwk[1];                       //~v145I~
    		dweditwk[0]=0;                                         //~v145I~
            dweditwk[1]=(long)udiskinfo.total_clusters;            //~v145R~
            ucalc_dwmult(dweditwk,clustersz);                      //~v145I~
    		drvsz[drvid][0]=dweditwk[0];                           //~v145I~
    		drvsz[drvid][1]=dweditwk[1];                           //~v145I~
        }                                                          //~v145I~
    }                                                              //~v145I~
#endif                                                             //~v145I~
//*navigate                                                        //~v000I~
    dwopt=UDIRWALK_NOMSG            //no err msg                   //~v000I~
    		|UDIRWALK_DIRCALL       //callback by each dir         //~v000R~
			|UDIRWALK_FILECALL      //callback by each file        //~v000I~
			|UDIRWALK_EMPTYCALL     //callback for empty dir       //~v000I~
			|UDIRWALK_EOLCALL       //callback for end of list     //~v000I~
//  		|UDIRWALK_TOPMASK       //callback for end of list     //~v142R~
//          |UDIRWALK_SORT_NAME;    //sort by name                 //~v150R~
            ;                       //sort by name                 //~v150I~
#ifdef UNX                                                         //~v149M~
    if (Scdsw)                                                     //~v149I~
		dwopt|=UDIRWALK_TEMPCD;       //change dir for udirlist performance//~v149R~
#endif                                                             //~v149M~
    pathlen=PATHLEN(Sdirnm);                                       //~v120I~
    if (WILDCARD(Sdirnm+pathlen))                                  //~v120R~
    {                                                              //~v120I~
//      strcpy(Sfilemask,Sdirnm+pathlen-1);	//with \\;             //~v142R~
//      strcpy(filemask,Sdirnm+pathlen);	//without \\;          //~v142R~
        strcpy(Sdirmask,Sdirnm+pathlen);	//without \\;          //~v142R~
        *(Sdirnm+pathlen)=0;				//drop wildcard        //~v120I~
        if (ROOTDIR(Sdirnm))                                       //~v120I~
//      	strcpy(Sfilemask,filemask);   //drop \\ for concatination//~v142R~
        	;                                                      //~v142I~
        else                                                       //~v120I~
	        *(Sdirnm+pathlen-1)=0;			//drop \\;             //~v120I~
        dwopt|=UDIRWALK_TOPMASK;      //select dir only for top level//~v142R~
    }                                                              //~v120I~
    else                                                           //~v120I~
//  	*filemask=0;                                               //~v142R~
    	*Sdirmask=0;                                               //~v142R~
//printf("dir=%s,file=%s\n",Sdirmask,Sfilemask);                   //~v142R~
   if (!Susagesw)	//not usage only                               //~v146I~
   {                                                               //~v146I~
    rc=udirwalk(dwopt,                                             //~v000R~
					Sdirnm,           //top dirname                //~v000R~
//  				"",				//no dir mask  	               //~v120R~
//  				filemask,   	//dir mask                     //~v142R~
    				Sdirmask,   	//dir mask                     //~v142R~
//  				"",				//no file mask                 //~v120R~
//  				filemask,   	//file mask                    //~v142R~
    				Sfilemask,   	//file mask                    //~v142I~
					FILE_ALL-FILE_DIRECTORY,		//attr mask    //~v000R~
                    32767,  		//stop depth,half max          //~v000R~
					psizechk,		//callback function            //~v000I~
					0,				//user data                    //~v000I~
					&applrc);                                      //~v000I~
    psizechk(Sdirnm,0/*fullpath*/,0/*pudirlist*/,0/*depth*/,0/*data*/,&applrc);//up to top dir//~v120R~
   }                                                               //~v146I~
                                                                   //~v000I~
  }//all dirname                                                   //~v143R~
   if (!Susagesw)	//not usage only                               //~v146I~
    if (Smultifilesw)                                              //~v143R~
//  	putsize("== Multi-dir total ==",0,Sdirsz[0],Sfilesz[0]);    //print//~v144R~
    	putsize("== Multi-dir total ==",0);    //print             //~v144I~
//  printf(" -------------- --------------  ----------------------------------------------\n");//~v145R~
//  printf("       dir-size       of files  dir name\n");          //~v145R~
//#ifdef UNX                                                         //~v141I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
  if (Sslinkdirctr||Sslinkfilectr)                                 //~v142I~
  {                                                                //~va30I~
  	if (Sskipslinksw)                                              //~v141I~
//    	printf("*** S-link %d dir, %d file ignored.\n",Sslinkdirctr,Sslinkfilectr);//~v141R~//~va71R~
      	printf("*** Valid Symlink(%d dirs, %d files) ware ignored.\n",Sslinkdirctr,Sslinkfilectr);//~va71I~
  	else                                                           //~v141I~
//    	printf("*** S-link %d dir, %d file included.\n",Sslinkdirctr,Sslinkfilectr);//~v141I~//~va71R~
      	printf("*** Including Valid Symlink %d dirs, %d files.\n",Sslinkdirctr,Sslinkfilectr);//~va71I~
  }                                                                //~va30I~
#endif                                                             //~va71I~
#ifdef UNX                                                         //~va71I~
#else                                                              //~v145I~
//  printf("\n      free size     total size  usage\n");           //~va30R~
//  printf(" -------------- --------------  ----------------------------------------------\n");//~va30R~
    printf("\n          free size         total size  usage\n");   //~va30I~
    printf(" ------------------ ------------------  --------------------------------------\n");//~va30I~
	for (drvid=0;drvid<26;drvid++)                                 //~v145R~
        if (drvfreesz[drvid][0]!=-1)   //not yet                   //~v145R~
        {                                                          //~v145I~
    		dweditwk[0]=drvfreesz[drvid][0];                       //~v145I~
		    dweditwk[1]=0;                                         //~v145I~
    		dweditwk[2]=drvfreesz[drvid][1];    //3word data for bc_dweditnum//~v145I~
    		bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,dweditwk,size1);//~v145I~
    		dweditwk[0]=drvsz[drvid][0];                           //~v145I~
		    dweditwk[1]=0;                                         //~v145I~
    		dweditwk[2]=drvsz[drvid][1];    //3word data for bc_dweditnum//~v145I~
    		bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,dweditwk,size2);//~v145I~
//calc %                                                           //~v145I~
			if (!drvfreesz[drvid][0] && !drvfreesz[drvid][1])      //~v151R~
            	userate=100;                                       //~v145I~
            else                                                   //~v145I~
            {                                                      //~v145I~
                dweditwk[0]=drvsz[drvid][0];                       //~v145R~
                dweditwk[1]=drvsz[drvid][1];    //3word data for bc_dweditnum//~v145R~
                ucalc_dwdiv(dweditwk,100);                         //~v145R~
//              divider=dweditwk[1];                               //~v145R~//~va4rR~
				bc_dw2numfmt(0,dweditwk2,dweditwk);                //~va4rI~
                dweditwk[0]=drvfreesz[drvid][0];                   //~v145R~//~va4rR~
                dweditwk[1]=drvfreesz[drvid][1];    //3word data for bc_dweditnum//~v145R~//~va4rR~
//              ucalc_dwdiv(dweditwk,divider);                     //~v145I~//~va4rR~
				bc_dw2numfmt(0,dweditwk1,dweditwk);                //~va4rI~
//  			bc_dwbinop(0,'/',dweditwk1,dweditwk2);             //~va4rR~//~va4sR~
    			ucalc_binop(0,'/',dweditwk1,dweditwk2);            //~va4sR~
//              dweditwk[1]=dweditwk1[2];                          //~va4rI~//~va4sR~
				bc_numfmt2dw(0,dweditwk1,dweditwk);                //~va4sI~
            	userate=100-(int)dweditwk[1];                      //~v145R~
            }                                                      //~v145I~
//  		printf("%15s%15s  %c: %3d %% use\n",size1,size2,'A'+drvid,userate);//~va30R~
    		printf("%19s%19s  %c: %3d %% use\n",size1,size2,'A'+drvid,userate);//~va30I~
        }                                                          //~v145I~
#endif                                                             //~v141M~
    printf("%s:%s:==%c== End of process (filemask:%s) ==\n",Spgm,Sver,OSTYPE,Sfilemask);//~v142R~
	ARMXSUB_CLOSE(PGM);	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//~vas3I~
    return max(applrc,rc);                                         //~v000R~
}//end main                                                        //~v000I~
//**********************************************************************//~v000I~
//* psizechk                                                       //~v000I~
//*  parm1:dir name                                                //~v000I~
//*  parm2:fullpathname,0 if dir entry,or empty call               //~v000I~
//*  parm3:PUDIRLIST,0 if empty entry                              //~v000I~
//*  parm4:depth                                                   //~v000I~
//*  parm5:appl data                                               //~v000I~
//*  parm6:appl rc area                                            //~v000I~
//*  return:0:continue walk,else stop walk                         //~v000I~
//**********************************************************************//~v000I~
int psizechk(char *Pdir,char *Pfullpath,UDIRLIST *Ppudirlist,      //~v000I~
                                int Pdepth,void *Pdata,int *Prc)   //~v000I~
{                                                                  //~v000I~
    int depth;                                                     //~v140I~
//#ifdef UNX                                                         //~v141I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
    int slinksw;                                                   //~v141I~
#endif                                                             //~v141I~
//**************************                                       //~v000I~
	if (Smultifilesw)                                              //~v143R~
    	Pdepth++;                                                  //~v143R~
//printf("depth=%d:dir=%s,fullpath=%s\n",Pdepth,Pdir,((Pfullpath==(char*)(-1))?0:Pfullpath));//~v000R~
//printf("prevdepth=%d:prevdir=%s\n",Sprevdepth,Sprevdir);         //~v000R~
//	if (Pfullpath==(char *)(-1))	//end of list                  //~v000R~//~va66R~
	if (Pfullpath==(char *)(ULPTR)(-1))	//end of list              //~va66I~
    {                                                              //~v000I~
//printf("-1:depth=%d\n",Pdepth);                                  //~v140R~
		if (Sparmdepth>=Pdepth)                                    //~v000R~
//  		putsize(Pdir,Pdepth,Sdirsz[Pdepth],Sfilesz[Pdepth]);	//print//~v144R~
    		putsize(Pdir,Pdepth);	//print                        //~v144I~
		if (Pdepth)                                                //~v000I~
          if (Pdepth<=MAXDEPTH)                                    //~v140I~
          {                                                        //~v144I~
//          Sdirsz[Pdepth-1]+=Sfilesz[Pdepth]+Sdirsz[Pdepth];      //~v144R~
            DWORD_ADD(Sdirsz_high[Pdepth-1],Sdirsz[Pdepth-1],      //~v144I~
                      Sdirsz_high[Pdepth],Sdirsz[Pdepth]);         //~v144I~
            DWORD_ADD(Sdirsz_high[Pdepth-1],Sdirsz[Pdepth-1],      //~v144I~
                      Sfilesz_high[Pdepth],Sfilesz[Pdepth]);       //~v144I~
          }                                                        //~v144I~
    }                                                              //~v000I~
    else                                                           //~v000I~
    {                                                              //~v140I~
//#ifdef UNX                                                         //~v141I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
        if (Ppudirlist) //not last entry                           //~v141I~
//			slinksw=S_ISLNK(FILE_GETMODE(Ppudirlist->attr));       //~v141R~//~va71R~
  			slinksw=FILE_ISSLINK(Ppudirlist->attr);                //~va71I~
        else                                                       //~v141I~
        	slinksw=0;                                             //~v141I~
#endif                                                             //~v141I~
	 	if (Pfullpath) //file entry                                //~v000R~
    	{                                                          //~v000R~
//#ifdef UNX                                                         //~v141I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
		 if (slinksw)                                              //~v141R~
           	Sslinkfilectr++;                                       //~v141R~
		 if (!Sskipslinksw || !slinksw)                            //~v141R~
         {                                                         //~v141I~
#endif                                                             //~v141I~
          if (Pdepth>MAXDEPTH)                                     //~v140I~
            depth=MAXDEPTH;                                        //~v140R~
          else                                                     //~v140I~
           if (Pdepth)                                             //~v140R~
            depth=Pdepth-1;                                        //~v140I~
           else              //for the case logic err              //~v140R~
            depth=0;                                               //~v140I~
//  		Sfilesz[Pdepth-1]+=Ppudirlist->size;	//file of parent dir//~v140R~
//  		Sfilesz[depth]+=Ppudirlist->size;	//file of parent dir//~v144R~
#ifdef LFSSUPP                                                     //~va30I~
            DWORD_ADD(Sfilesz_high[depth],Sfilesz[depth],          //~va30I~
                      ((Ppudirlist->size)>>32),(ULONG)(Ppudirlist->size));	//file of parent dir//~va30R~
#else                                                              //~va30I~
            DWORD_ADD(Sfilesz_high[depth],Sfilesz[depth],          //~v144R~
                      0,(ULONG)(Ppudirlist->size));	//file of parent dir//~v144I~
#endif                                                             //~va30I~
//			UTRACEP("level=%d,%d,file=%s add +%ld\n",Pdepth,depth,Pfullpath,depth,Ppudirlist->size);//~v140R~//~va71R~
//#ifdef UNX                                                         //~v141I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
         }//not slink                                              //~v141I~
#endif                                                             //~v141I~
		}                                                          //~v000R~
        else	//dir entry                                        //~v000I~
        {                                                          //~v000I~
//  		UTRACEP("level=%d,dir=%s\n",Pdepth,Pdir);              //~va71R~
//#ifdef UNX                                                         //~v141R~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
		 	if (slinksw)                                           //~v141I~
           		Sslinkdirctr++;                                    //~v141I~
		 	if (Sskipslinksw && slinksw)	//slink dir skip       //~v141I~
				return UDIRWALK_URC_SKIPDIR; //user requested skip this dir//~v141I~
#endif                                                             //~v141I~
          if (Pdepth<=MAXDEPTH)                                    //~v140R~
          {                                                        //~v140I~
        	Sfilesz[Pdepth]=0;                                     //~v000I~
            Sdirsz[Pdepth]=0;                                      //~v000I~
        	Sfilesz_high[Pdepth]=0;                                //~v144I~
            Sdirsz_high[Pdepth]=0;                                 //~v144I~
          }                                                        //~v140I~
        }                                                          //~v000I~
    }                                                              //~v140I~
	return 0;			//continue walk                            //~v000I~
}//psizechk                                                        //~v000I~
//**********************************************************************//~v000I~
//* putsize                                                        //~v000I~
//*  parm1:dirname                                                 //~v000I~
//*  parm2:dir level                                               //~v000I~
//*  return:none                                                   //~v000I~
//**********************************************************************//~v000I~
//void putsize(char *Pdir,int Pdepth,ULONG Pdirsz,ULONG Pfilesz)   //~v144R~
void putsize(char *Pdir,int Pdepth)                                //~v144I~
{                                                                  //~v000I~
    int depth;                                                     //~v000I~
    char indent1[128];                                             //~v000R~
//  char indent2[128];                                             //~v000R~
    char size1[32];                                                //~v144R~
    char size2[32],*dirseps;                                       //~v144R~
    char *pmask;                                                   //~v120I~
#ifdef ULIB64                                                      //~vaa0I~
    UINT4 fdsz[2];                                                 //~vaa0I~
#else                                                              //~vaa0I~
//  ULONG fdsz[2];                                                 //~v145R~//~vaa0R~
    LONG  fdsz[2];                                                 //~vaa0I~
#endif                                                             //~vaa0I~
    LONG  dweditwk[3];                                             //~v145I~
//**************************                                       //~v000I~
	depth=min(Pdepth+1,MAXDEPTH)*2;                                //~v000R~
//  sprintf(indent1,"%%s%%s%% %ds%%-s\n",depth);                   //~v120R~
//  sprintf(indent1,"%%s%%s%% %ds%%-s%%-s\n",depth);               //~v142R~
//  sprintf(indent1,"%%s%%s%% %ds%%-s%c%%-s\n",depth,DIR_SEPC);    //~v144R~
//  sprintf(indent1,"%%15s%%15s%% %ds%%-s%%s%%-s\n",depth);        //~va30R~
    sprintf(indent1,"%%19s%%19s%% %ds%%-s%%s%%-s\n",depth);        //~va30I~
//  sprintf(indent2,"%% %ds    %%s (file total=%%s)\n",depth);     //~v000R~
//printf("fmt=%s,%s\n",indent1,indent2);                           //~v000R~
//  unumedit(Pdirsz+Pfilesz,"z,zzz,zzz,zz9",size1);                //~v144R~
//  unumedit(Pfilesz,"z,zzz,zzz,zz9",size2);                       //~v144I~
    fdsz[0]=Sdirsz_high[Pdepth];                                   //~v144I~
    fdsz[1]=Sdirsz[Pdepth],                                        //~v144I~
    DWORD_ADD(fdsz[0],fdsz[1],Sfilesz_high[Pdepth],Sfilesz[Pdepth]);//~v144I~
    dweditwk[0]=fdsz[0];                                           //~v144I~
    dweditwk[1]=0;                                                 //~v144I~
    dweditwk[2]=fdsz[1];    //3word data for bc_dweditnum          //~v144I~
    bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,dweditwk,size1);   //~v144R~
    dweditwk[0]=Sfilesz_high[Pdepth];                              //~v144I~
    dweditwk[1]=0;                                                 //~v144I~
    dweditwk[2]=Sfilesz[Pdepth];    //3word data for bc_dweditnum  //~v144I~
    bc_dweditnum(0/*functype*/,'Z'/*Pconvtype*/,dweditwk,size2);   //~v144R~
//    printf(indent1," ",Pdir);                                    //~v000I~
//  printf(indent1,size1,size2," ",Pdir);                          //~v120R~
	if (Pdepth)                                                    //~v120R~
    	pmask="";                                                  //~v120M~
    else            //top level                                    //~v120R~
//  	pmask=Sfilemask;                                           //~v142R~
    	pmask=Sdirmask;                                            //~v142I~
    if (ROOTDIR(Pdir) && !*pmask)                                  //~v144I~
    	dirseps="";                                                //~v144R~
    else                                                           //~v144I~
        if (!Pdepth && Smultifilesw)                               //~v144I~
	    	dirseps="";                                            //~v144R~
        else                                                       //~v144I~
	    	dirseps=DIR_SEPS;                                      //~v144R~
//  printf(indent1,size1,size2," ",Pdir,pmask);                    //~v144R~
    printf(indent1,size1,size2," ",Pdir,dirseps,pmask);            //~v144R~
    return;                                                        //~v000I~
}//putsize                                                         //~v000I~
//**********************************************************************//~v000I~
//*parameter chk                                                   //~v000I~
//**********************************************************************//~v000I~
void parmchk(int parmc,char *parmp[])                              //~v000I~
{                                                                  //~v000I~
    unsigned char c;    //read char                                //~v000I~
    char *cptr,*cptr0;         //char ptr work                     //~v143R~
    int parmno; //parm count work                                  //~v000I~
    int posparmno=0; //parm count work                             //~v000I~
//*************************                                        //~v000I~
    if (parmc<2 || *parmp[1]=='?')                                 //~v000I~
    {                                                              //~v000I~
      help();                                                      //~v000I~
      exit(0);                                                     //~v000I~
    }                                                              //~v000I~
//*******************************                                  //~v000I~
//* parm process                *                                  //~v000I~
//*******************************                                  //~v000I~
    for (parmno=1;parmno<parmc;parmno++)                           //~v000I~
    {                                                              //~v000I~
        cptr=cptr0=parmp[parmno];                                  //~v000I~
#ifdef UNX                                                         //~v120I~
        if(*cptr=='-')                                             //~v120I~
#else                                                              //~v120I~
        if(*cptr=='/'||*cptr=='-')                                 //~v000I~
#endif                                                             //~v120I~
        {//option                                                  //~v000I~
        	c=*(++cptr);                      //first option byte  //~v000I~
            switch(toupper(c))             //option                //~v000I~
            {                                                      //~v000I~
//**************************                                       //~v000I~
//* cmd string     /?      *                                       //~v000I~
//**************************                                       //~v000I~
            case '?':           //cmd string start                 //~v000I~
            case 'H':           //apply to file                    //~v000I~
                help();                                            //~v000I~
                exit(0);                                           //~v000I~
                break;                                             //~v000I~
//**************************                                       //~v142I~
//* cmd string     /F      *                                       //~v142I~
//**************************                                       //~v142I~
            case 'F':           //apply to file                    //~v142I~
                strcpy(Sfilemask,cptr+1);                          //~v142I~
                break;                                             //~v142I~
//**************************                                       //~v000I~
//* stop dir level /L      *                                       //~v000I~
//**************************                                       //~v000I~
            case 'L':           //apply to file                    //~v000I~
                Sparmdepth=atoi(++cptr);                           //~v000R~
                Sparmdepthsw=1;                                    //~v143I~
                if (Sparmdepth>MAXDEPTH)                           //~v140I~
                	uerrexit("Maxdepth should be <=%d",0,          //~v140R~
								MAXDEPTH);                         //~v140I~
                break;                                             //~v000I~
//**************************                                       //~v000I~
//* stop dir level /S      *                                       //~v000I~
//**************************                                       //~v000I~
            case 'S':           //apply to file                    //~v000I~
//              Sparmdepth=32767;                                  //~v140R~
                Sparmdepth=MAXDEPTH;                               //~v140I~
                break;                                             //~v000I~
#ifndef UNX                                                        //~v146I~
//**************************                                       //~v146I~
//* stop dir level /U      *                                       //~v146I~
//**************************                                       //~v146I~
            case 'U':           //usage only                       //~v146I~
                Susagesw=1;                                        //~v146I~
                break;                                             //~v146I~
#endif                                                             //~v146I~
//**************************                                       //~v000I~
//* yes    option  /Y      *                                       //~v000I~
//**************************                                       //~v000I~
            case 'Y':           //toggle on                        //~v000I~
                for (;;)                                           //~v000I~
                {                                                  //~v000I~
                    c=*(++cptr);                                   //~v000I~
                    if (!c)                                        //~v000I~
                        break;                                     //~v000I~
                    switch(toupper(c))                             //~v000I~
                    {                                              //~v000I~
                    case '9':       //dbcs sw                      //~v000I~
                                        UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set//~v000I~
                                        UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs//~v000I~
                                break;                             //~v000I~
#ifdef UNX                                                         //~v141I~
                    case 'C':   //cd for udirlist performance up   //~v149I~
                      	Scdsw=1;                                   //~v149I~
                        break;                                     //~v149I~
#endif                                                             //~va71I~
#if defined(W32)||defined(UNX)                                     //~va71I~
                    case 'M':   //symbolic link process            //~v147I~
                      	Gufile_opt&=~GFILEOPT_NOSLINKERRMSG;       //~v147M~
                        break;                                     //~v147I~
                    case 'S':   //symbolic link process            //~v141I~
                        Sskipslinksw=0;                            //~v141I~
                        break;                                     //~v141I~
#endif                                                             //~v141I~
                    default:                           //not option//~v000I~
                                optionerr("Yes/No option",cptr0);  //~v000I~
                    }                                              //~v000I~
                }                                                  //~v000I~
                break;                                             //~v000I~
//**************************                                       //~v000I~
//* no     option  /N      *                                       //~v000I~
//**************************                                       //~v000I~
            case 'N':           //toggle on                        //~v000I~
                for (;;)                                           //~v000I~
                {                                                  //~v000I~
                    c=*(++cptr);                                   //~v000I~
                    if (!c)                                        //~v000I~
                        break;                                     //~v000I~
                    switch(toupper(c))                             //~v000I~
                    {                                              //~v000I~
                    case '9':       //dbcs sw                      //~v000I~
                                        UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set//~v000I~
                                        UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs//~v000I~
                                break;                             //~v000I~
#ifdef UNX                                                         //~v141I~
                    case 'C':   //cd for udirlist performance up   //~v149I~
                      	Scdsw=0;                                   //~v149I~
                        break;                                     //~v149I~
#endif                                                             //~va71I~
#if defined(W32)||defined(UNX)                                     //~va71I~
                    case 'M':   //symbolic link process            //~v147I~
                      	Gufile_opt|= GFILEOPT_NOSLINKERRMSG;       //~v147I~
                        break;                                     //~v147I~
                    case 'S':   //no symbolic link process         //~v141I~
                        Sskipslinksw=1;                            //~v141I~
                        break;                                     //~v141I~
#endif                                                             //~v141I~
                    default:                           //not option//~v000I~
                                optionerr("Yes/No option",cptr0);  //~v000I~
                	}                                              //~v000I~
                }                                                  //~v000I~
                break;                                             //~v000I~
            default:                           //not option        //~v000I~
                uerrexit("undefined option parm(%s)\n",            //~v000I~
                                        "未定義パラメータ(%s)\n",  //~v000I~
                                                cptr0);            //~v000I~
            }//switch  by first option byte                        //~v000I~
            continue;                                              //~v000I~
		}//option                                                  //~v000I~
//pos parm                                                         //~v000I~
        posparmno++;                                               //~v000I~
//        switch (posparmno)                                       //~v143R~
//        {                                                        //~v143R~
////**************************                                     //~v143R~
////* top dir                *                                     //~v143R~
////**************************                                     //~v143R~
//        case  1:          //first parm                           //~v143R~
//            dirnm=cptr0;                                         //~v143R~
//            break;                                               //~v143R~
////************************************                           //~v143R~
//        default:                                                 //~v143R~
//            uerrexit("too many %s positional parameter(%s)\n",   //~v143R~
//                                 "多過ぎる %s の定位置パラメータ(%s)\n",//~v143R~
//                                                Spgm,cptr0);     //~v143R~
//        }//switch by parmno                                      //~v143R~
        ustackfnm(cptr0);                                          //~v143R~
	}//for all parm                                                //~v000I~
//chk more                                                         //~v000I~
    if (!posparmno)                                                //~v000I~
    	uerrexit("dir-name parameter is required\n",               //~v000I~
            	 "ディレクトリー名を指定して下さい");              //~v000I~
//  if (!ufullpath(Sdirnm,dirnm,sizeof(Sdirnm)))                   //~v143R~
//  	exit(8);                                                   //~v143R~
}//parmchk                                                         //~v000I~
//*********************************************************************//~v142I~
//* ustackfnm                                                      //~v143R~
//*  stack dirname                                                 //~v143R~
//*parm1:parm dir name                                             //~v143R~
//*return:none                                                     //~v143R~
//*********************************************************************//~v142I~
void ustackfnm(char *Pfnm)                                         //~v143R~
{                                                                  //~v143R~
	PPARMFNMSTACK 	pnewpfnm;                                      //~v143R~
    char fnm[_MAX_PATH];                                           //~v143R~
#ifndef UNX                                                        //~v144I~
    char didlist[26];                                              //~v144M~
    int ii,didctr;                                                 //~v143R~
#endif                                                             //~v144I~
//******************************                                   //~v143R~
    strcpy(fnm,Pfnm);                                              //~v143R~
#ifndef UNX                                                        //~v143R~
    if (!memcmp(Pfnm,DRIVE_ALL,sizeof(DRIVE_ALL)-1))               //~v143R~
    {                                                              //~v143R~
		didctr=ugetdriveidlist(UDDC_FIXED,didlist);                //~v143R~
    	for (ii=0;ii<didctr;ii++)                                  //~v143R~
    	{                                                          //~v143R~
        	*fnm=didlist[ii];  //a:                                //~v143R~
        	pnewpfnm=ucalloc(1,PARMFNMSTACKSZ);                    //~v143R~
        	if (!ufullpath(pnewpfnm->PFNname,fnm,sizeof(pnewpfnm->PFNname)))//~v143R~
            	exit(8);                                           //~v143R~
        	UENQ(UQUE_END,&Spfnmstack,pnewpfnm);    //enq to before of next low//~v143R~
    	}                                                          //~v143R~
        return;                                                    //~v143R~
    }//*: support                                                  //~v143R~
#endif                                                             //~v143R~
    pnewpfnm=ucalloc(1,PARMFNMSTACKSZ);                            //~v143R~
//  strcpy(pnewpfnm->PFNname,fnm);                                 //~v145R~
    if (!ufullpath(pnewpfnm->PFNname,fnm,sizeof(pnewpfnm->PFNname)))//~v145I~
        exit(8);                                                   //~v145I~
    UENQ(UQUE_END,&Spfnmstack,pnewpfnm);    //enq to before of next low//~v143R~
    return;                                                        //~v143R~
}//ustackfnm                                                       //~v143R~
//**********************************************************************//~v000I~
//* write option err msg  v3.8a                                    //~v000I~
//**********************************************************************//~v000I~
void optionerr(char *type,char* value)                             //~v000I~
{                                                                  //~v000I~
        uerrexit("invalid %s option parm value(%s)\n",             //~v000I~
                         "%s の値(%s)の誤り\n",                    //~v000I~
                        type,value);                               //~v000I~
}//optionerr                                                       //~v000I~
//**********************************************************************//~v000I~
//* write help msg                                                 //~v000I~
//**********************************************************************//~v000I~
void help(void)                                                    //~v000I~
{                                                                  //~v000I~
//*******************                                              //~v000I~
        HELPMSG                                                    //~v000I~
"%s : %s=(%c)= Display directory size.\n",                         //~v001R~
//"%s :=(%c)= ディレクトリーサイズ\x95\\表示\n",                   //~v000R~
"%s : %s=(%c)= ディレクトリーサイズ\x95\\示\n",                    //~v001R~
                Spgm,Sver,OSTYPE);                                 //~v001R~
        HELPMSG                                                    //~v000I~
"fmt  : %s [%coptions] dir-name [ dir-name ...]\n",                //~v143R~
"形式 : %s [%coptions] dir-name [ dir-name ...]\n",                //~v143R~
                Spgm,CMDFLAG_PREFIX);                              //~v120R~
        HELPMSG                                                    //~v000I~
"  dir-name  :target which size is displayed. \".\" is current-dir.\n",//~v143R~
"  dir-name  :ディレクトリー名。　\".\"で現行ディレクトリー。\n"); //~v143R~
#ifndef UNX                                                        //~v143I~
        HELPMSG                                                    //~v143I~
"             \"*:\" means all fixed drive.\n",                    //~v143I~
"             \"*:\" で全固定ドライブを意味する。\n");             //~v143I~
#endif                                                             //~v143I~
        HELPMSG                                                    //~v142I~
//"             Wildcard mask is applyed to top sub-dir-name only.\n",//~v149R~
//"             ワイルドカード指定は最上位のサブDirにのみ適用されます。\n");//~v149R~
"             Wildcard mask is applyed to top level(dir and file) only.\n",//~v149I~
"             ワイルドカード指定は最上位(DirとFile)にのみ適用されます。\n");//~v149I~
        HELPMSG                                                    //~v001I~
"  options   :\n",                                                 //~v001I~
"  options   :\n");                                                //~v001I~
        HELPMSG                                                    //~v142I~
"    %cFfmask :Wildcard mask for filename selection(default is *).\n",//~v142I~
"    %cFfmask :ファイル名を選択するためのワイルドカードマスク(省略値は * )。\n",//~v142I~
				CMDFLAG_PREFIX);                                   //~v142I~
        HELPMSG                                                    //~v000I~
"    %cLlevel :sub-directory depth to be displayed.default is 0.\n",//~v140R~
//"    /Llevel :表示するサブディレクトリーの深さ。省略値は 0。\n");//~v001R~
"    %cLlevel :\x95\\示するサブディレクトリーの深さ。省略値は 0。\n",//~v140R~
				CMDFLAG_PREFIX);                                   //~v140R~
        HELPMSG                                                    //~v000I~
"    %cS      :Same as /L%d\n",                                    //~v140R~
//"    /S      :表示するディレクトリーの深さを%dに設定。\n");      //~v140R~
"    %cS      :/L%d に同じ。\n",                                   //~v140R~
				CMDFLAG_PREFIX,MAXDEPTH);                          //~v140R~
#ifndef UNX                                                        //~v146I~
        HELPMSG                                                    //~v146I~
"    %cU      :display disk Usage only.\n",                        //~v146I~
"    %cU      :ディスク使用率のみを\x95\\示。\n",                  //~v146I~
				CMDFLAG_PREFIX);                                   //~v146I~
#endif                                                             //~v146I~
//#ifdef UNX                                                         //~v141I~//~va71R~
#if defined(W32)||defined(UNX)                                     //~va71I~
        HELPMSG                                                    //~v147M~
"    %cNm     :No symbolic link err msg.\n",                       //~v147I~
"    %cNm     :シンボリックリンクエラーMsgを出力しない。\n",       //~v147I~
				CMDFLAG_PREFIX);                                   //~v147M~
        HELPMSG                                                    //~v141I~
"    %cYs     :Count also symbolic link file.\n",                  //~v141I~
"    %cYs     :シンボリックリンクファイルも含める\n",              //~v141R~
				CMDFLAG_PREFIX);                                   //~v141I~
#endif                                                             //~v141I~
	return;                                                        //~v000I~
}//help                                                            //~v000I~
