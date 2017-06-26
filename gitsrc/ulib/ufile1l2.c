//*CID://+v6J0R~:                             update#=  218;       //~v6J0R~
//*************************************************************
//*ufile1l2.c                                                      //~v50GR~
//*************************************************************
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6E4:160719 (ARM)cpl err for mdos disk                           //~v6E4I~
//v6D3:160424 specify mdir date format by MTOOLS_DATE_STRING=mm-dd-yyyy//~v6D3I~
//v6D2:160423 LNX compiler warning for bitmask assignment(FDATE,FTIE)//~v6D2I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6qa:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~v6qaI~
//v6h9:120612 (FC5)avoid uninitialized variable warning by gcc 4.1.1 on FC5(copile optio -Ox is required also)//~v6h9I~
//v6b1:110705 try list wildcard membername                         //~v6b1I~
//v56n:020711 (UNX:BUG) xff loop by FIFO file.it is slink,so not chked.//~v56nI~
//v565:020703 (UNX:BUG) xfs fail by disk full for FD when cluster size>1.//~v565R~
//v563:020702 (AIX)filename set to notsupported msg                //~v563I~
//v562:020702 (AIX:BUG)if subdir has no member,dir list creation err//~v55qI~
//v55q:020521 (AIX)dosdir -ald .abc return no notfound msg(treated as cur dir)//~v55qI~
//v55o:020518 (UNX)errno msg for each not by uproc                 //~v55oI~
//v55n:020503 (AIX)disket support                                  //~v55nI~
//v55k:020501 (TL)mdir abend whe -f option specified               //~v55kI~
//v55f:020429 (UNX)mcd(cd for mdos disk) support                   //~v55fI~
//v55e:020428 (UNX)set errno ENOSPC for disk full of mdos disk     //~v55eI~
//v55b:020428 (UNX:BUG)time stamp by mdir may be h:mm fmt if before 10 o'clock.//~v55bI~
//v558:020427 (UNX:BUG)mtools may write err msg(not found etc) to stdout(for ex mdir)//~v558I~
//v557:020427 (UNX)disket support(mren) for rename file            //~v557I~
//v538:020322 (LNX)mdos disk support;mkdir rmdir;attrib            //~v538I~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
                                                                   //~v6b1I~
#include <dirent.h>                                                //~v6b1I~
//*******************************************************
#include <ulib.h>
#include <ufile.h>
#include <ufile1l.h>                                               //~v50GI~
#include <ufile1l2.h>                                              //~v50GI~
#include <uerr.h>
#include <ustring.h>
#include <ualloc.h>                                                //~v50GI~
#include <uproc.h>                                                 //~v50GI~
#include <uedit2.h>                                                //~v6D2I~
#include <udos2.h>                                                 //~v6D3I~
//*******************************************************
#ifdef AIX                                                         //~v55nI~
                                                                   //~v55nI~
    #define CMD_DOSDIR_AL    "dosdir -al    %s" //all,long         //~v55nR~
    #define CMD_DOSDIR_ALD   "dosdir -ald   %s" //all,long,dir itself//~v55nR~
    #define CMD_DOSDIR_V     "dosdir -v"          //format info    //~v55nR~
	#define ATTRIB_FLDWIDTH 6                                      //~v55nI~
                                                                   //~v55nI~
#else                                                              //~v55nI~
                                                                   //~v55nI~
#define CMD_MCD        "mcd"       //cur dir                       //~v50GI~
#define CMD_MCD2       "mcd %s"    //cd on disket                  //~v55fI~
#ifdef LNXLC2     //turbo linux                                    //~v55kI~
	#define CMD_MDIR       "mdir -a \"%s\"" //all,freesize info    //~v55kI~
#else                                                              //~v55kI~
#define CMD_MDIR       "mdir -af \"%s\"" //all,no freesize info    //~v50GR~
#endif                                                             //~v55kI~
#define CMD_MDIR2      "mdir %c:"       //dir list all             //~v50GI~
#define CMD_MINFO      "minfo %c:"       //minfo                   //~v50GR~
#define CMD_MATTRIB    "mattrib \"%s\""		//display attrib       //~v50GR~
#define CMD_MATTRIB2   "mattrib \"%s%s\""		//display attrib   //~v50GI~
#define ATTRIB_FLDWIDTH 12                                         //~v50GI~
                                                                   //~v55nI~
#endif                                                             //~v55nI~
static int Smdosflag;                                              //~v6D3I~
#define MDOSF_DATE_STRING  0x01   //issued setenv(MTOOLS_DATESTRING=mm-dd-yyyy)//~v6D3I~
//*******************************************************
int ufilegetmdosattr(FILEFINDBUF3 *Ppffb3,char *Pstdorec);         //~v50GR~
#ifdef AIX                                                         //~v55nI~
	int ufilegetmdosdl(PUDIRLIST *Pppudl,char **Pstdo,int Pstdoctr,PUDIRLIST Ppudlself,PUDIRLIST Ppudlparent);//~v55nR~
	int ugetmonth(char *Pmonth);                                   //~v55nI~
#else                                                              //~v55nI~
int ufilegetmdosdl(PUDIRLIST *Pppudl,char **Pstdo,int Pstdoctr,int *Ppdirsw);//~v50GR~
#endif                                                             //~v55nI~
int ufilegetmdosattrlist(PUDIRLIST Ppudl,char **Pstdo,int Pstdoctr);//~v50GI~
//int ufilemdoscmd(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr);//~v538R~
int ufilegetnum(char *Ppc,int Plen,int *Ppint);                    //~v50GI~
#ifdef AIX                                                         //~v55nI~
int ufilenoentrychk(char **Pstdo,int Pstdoctr);                    //~v55qI~
#else                                                              //~v55nI~
int uminfo(UCHAR *Pfnm,struct statfs *Ppsfs);                      //~v50GI~
#endif                                                             //~v55nI~
int ufilemdoserrchk(char *Prec);                                   //~v55oR~
//*******************************************************          //~v6D3I~
int mtoolsinit()                                                   //~v6D3I~
{                                                                  //~v6D3I~
	udos_setenv(0,"MTOOLS_DATE_STRING","mm-dd-yyyy");              //~v6D3I~
    return 0;                                                      //~v6D3I~
}//mtoolsinit                                                      //~v6D3I~
//*******************************************************          //~v50GI~
//*get file(not wildcard) status(size,time stmp) for disket file   //~v50GI~
//*parm 1:file name                                                //~v50GI~
//*parm 2:output file info addr(optional)                          //~v50GI~
//*******************************************************          //~v50GI~
unsigned int ufstat_mdos(char *Ppfile,FILEFINDBUF3 *Ppffb3)        //~v50GI~
{                                                                  //~v50GI~
#ifdef AIX                                                         //~v55nI~
#else                                                              //~v55nI~
    int dirsw;                                                     //~v55nM~
#endif                                                             //~v55nI~
    int rc,pathlen,rc2;                                            //~v55nR~
    int stdoctr;                                                   //~v55nR~
    char **stdo;                                                   //~v50GR~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v50GR~
    UCHAR pathname[_MAX_PATH+32];                                  //~v55nI~
	FILEFINDBUF3 ffb3,*pffb3;                                      //~v538R~
    PUDIRLIST pudl;                                                //~v538I~
//*********************************                                //~v50GI~
	if (!(pffb3=Ppffb3))                                           //~v538I~
    	pffb3=&ffb3;		//for covenience                       //~v538I~
    memset(pffb3,0,sizeof(FILEFINDBUF3));                          //~v538I~
    pffb3->attrFile|=FILE_MDOSDISK;     //init                     //~v538I~
    if (MDOSROOTDIR(Ppfile))		//root dir,no info returned by mdir//~v538I~
    {                                                              //~v538I~
	    pffb3->attrFile|=FILE_DIRECTORY;     //init                //~v538I~
	    strcpy(pffb3->achName,Ppfile);                             //~v538I~
        return 0;                                                  //~v538I~
    }                                                              //~v538I~
//mdir                                                             //~v538I~
#ifdef AIX                                                         //~v55nI~
    sprintf(mtoolscmd,CMD_DOSDIR_ALD,Ppfile+3);//drop a:/          //~v55nR~
#else                                                              //~v55nI~
    sprintf(mtoolscmd,CMD_MDIR,Ppfile);                            //~v538I~
#endif                                                             //~v55nI~
//  rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,&stdo,0,&stdoctr,0);	//get stdout/stderr//~v558R~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG|MDCO_CHKSTDO,	//chk stdout also//~v55oR~
						mtoolscmd,&stdo,0,&stdoctr,0);	//get stdout/stderr//~v558I~
#ifdef AIX                                                         //~v55qI~
	if (!rc)                                                       //~v55qI~
    	rc=ufilenoentrychk(stdo,stdoctr);                          //~v55qI~
#endif                                                             //~v55qI~
    if (rc)                                                        //~v538I~
    {                                                              //~v538I~
    	if (stdo)                                                  //~v538I~
        	ufree(stdo);                                           //~v538I~
        if (rc==ENOENT)                                            //~v55nI~
        {                                                          //~v55nI~
		    pathlen=PATHLEN(Ppfile);                               //~v55nI~
            if (pathlen>0)                                         //~v55nI~
	        {                                                      //~v55nI~
        	    memcpy(pathname,Ppfile,(UINT)pathlen);             //~v55nI~
     	       	*(pathname+pathlen)=0;                             //~v55nR~
    			if (!MDOSROOTDIR(pathname))		//root dir,no info returned by mdir//~v55nM~
                {                                                  //~v55nI~
     	       		*(pathname+pathlen-1)=0;                       //~v55nI~
//    				rc2=ufstat_mdos(pathname,&ffb3);               //~v55nR~//~v6D0R~
      				rc2=(int)ufstat_mdos(pathname,&ffb3);          //~v6D0R~
            		if (rc2==ENOENT)                               //~v55nI~
                		rc=ENOTDIR;                                //~v55nI~
                }                                                  //~v55nI~
	        }                                                      //~v55nI~
        }                                                          //~v55nI~
//    	return rc;                                                 //~v538I~//~v6D0R~
      	return (unsigned)rc;                                       //~v6D0R~
    }                                                              //~v538I~
  	if (!Ppffb3)   //output not requested                          //~v538I~
    {                                                              //~v538M~
		ufree(stdo);                                               //~v538M~
        return 0;	                                               //~v538M~
    }                                                              //~v538M~
#ifdef AIX                                                         //~v55nI~
    rc=ufilegetmdosdl(&pudl,stdo,stdoctr,0,0);                     //~v55nR~
#else                                                              //~v55nI~
    rc=ufilegetmdosdl(&pudl,stdo,stdoctr,&dirsw);                  //~v538I~
#endif                                                             //~v55nI~
	ufree(stdo);                                                   //~v538I~
    if (rc)                                                        //~v538I~
//  	return rc;                                                 //~v538I~//~v6D0R~
    	return (unsigned)rc;                                       //~v6D0R~
#ifdef AIX                                                         //~v55nI~
#else                                                              //~v55nI~
    if (dirsw)                                                     //~v538I~
		pffb3->attrFile|=FILE_DIRECTORY;     //directory           //~v538I~
#endif                                                             //~v55nI~
//pudirlist to ffb3                                                //~v538I~
	strcpy(pffb3->achName,pudl->name);                             //~v538I~
	pffb3->cbFile=pudl->size;                                      //~v538I~
	pffb3->fdateLastWrite=pudl->date;                              //~v538I~
	pffb3->ftimeLastWrite=pudl->time;                              //~v538I~
//*                                                                //~v538I~
#ifdef AIX	                                                       //~v55nI~
	Ppffb3->attrFile|=pudl->attr;	//ufilegetmdosdl can set attr by dosdir cmd//~v55nR~
    rc=0;                                                          //~v55nI~
//  ufree(pudl);                                                   //~v55nI~//~v6qaR~
    UDIRLIST_FREE(pudl);                                           //~v6qaI~
#else                                                              //~v55nI~
//  ufree(pudl);                                                   //~v55nI~//~v6qaR~
    UDIRLIST_FREE(pudl);                                           //~v6qaI~
    sprintf(mtoolscmd,CMD_MATTRIB,Ppfile);                         //~v50GR~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,&stdo,0,0,0);	//get stdout/stderr//~v55oR~
    if (rc)                                                        //~v50GI~
    {                                                              //~v538I~
    	if (stdo)                                                  //~v538I~
	        ufree(stdo);                                           //~v538R~
//  	return rc;                                                 //~v50GR~//~v6D0R~
    	return (unsigned)rc;                                       //~v6D0R~
    }                                                              //~v538I~
	rc=ufilegetmdosattr(Ppffb3,*stdo);                             //~v538R~
	ufree(stdo);                                                   //~v538R~
#endif                                                             //~v55nI~
//  return rc;                                                     //~v50GI~//~v6D0R~
    return (unsigned)rc;                                           //~v6D0R~
}//ufstat_mdos                                                     //~v50GI~
//**********************************************************************//~v50GI~
// get disket file attr                                            //~v50GI~
// parm1  :file name                                               //~v50GI~
// parm2  :output statbuff                                         //~v50GI~
// parm3  :stdout line buff                                        //~v50GI~
// parm4  :stderr line buff                                        //~v50GI~
// return :r.c                                                     //~v50GI~
//**********************************************************************//~v50GI~
int ufilegetmdosattr(FILEFINDBUF3 *Ppffb3,char *Pstdorec)          //~v50GR~
{                                                                  //~v50GI~
	char *pc;                                                      //~v50GI~
    int  ii;                                                       //~v50GI~
    ULONG attr=0;                                                  //~v50GR~
//*********************************                                //~v50GI~
	for (pc=Pstdorec,ii=0;ii<ATTRIB_FLDWIDTH;ii++,pc++)            //~v50GR~
    {                                                              //~v50GI~
#ifdef AIX                                                         //~v55nI~
        if (*pc==']')                                              //~v55nI~
        	break;                                                 //~v55nM~
#endif                                                             //~v55nI~
    	switch(*pc)                                                //~v50GI~
        {                                                          //~v50GI~
        case ' ':                                                  //~v50GR~
        	break;                                                 //~v50GI~
        case 'A':                                                  //~v50GR~
        	attr|=FILE_ARCHIVED;                                   //~v50GI~
        	break;                                                 //~v50GI~
        case 'R':                                                  //~v50GR~
        	attr|=FILE_READONLY;                                   //~v50GI~
        	break;                                                 //~v50GI~
        case 'S':                                                  //~v50GR~
        	attr|=FILE_SYSTEM;                                     //~v50GI~
        	break;                                                 //~v50GI~
        case 'H':                                                  //~v50GR~
        	attr|=FILE_HIDDEN;                                     //~v50GI~
        	break;                                                 //~v50GI~
#ifdef AIX                                                         //~v55nI~
        case 'D':                                                  //~v55nI~
        	attr|=FILE_DIRECTORY;                                  //~v55nI~
        	break;                                                 //~v55nI~
#endif                                                             //~v55nI~
        }                                                          //~v50GI~
    }                                                              //~v50GI~
    Ppffb3->attrFile|=attr;                                        //~v50GI~
	return 0;                                                      //~v50GI~
}//ufilegetmdosattr                                                //~v50GI~
//**********************************************************************//~v50GI~
// find first for msdos discket(create udirlist)                   //~v50GR~
// parm1  :file name                                               //~v50GI~
// parm2  :HDIR ptr(actualy pudir lis)                             //~v55nR~
// return :r.c                                                     //~v50GI~
//**********************************************************************//~v50GI~
unsigned uopendir_mdos(char *Ppfname,PUDIRLIST *Pppudl)            //~v55nR~
{                                                                  //~v50GI~
    unsigned rc;                                                   //~v50GI~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v50GI~
    PUDIRLIST pudl;                                                //~v50GR~
    char **stdo;                                                   //~v55nR~
    int stdoctr;                                                   //~v55nI~
#ifdef AIX                                                         //~v55nI~
static PUDIRLIST Scurpudl=0,Sparentpudl=0;	//read dir memb        //~v55nR~
static int Sintcallsw=0;                                           //~v55nI~
	int  len,rootsw,pathlen;                                       //~v55nR~
    UCHAR fpathwk[_MAX_PATH];                                      //~v55nI~
#else                                                              //~v55nI~
    char *pwc;                                                     //~v55nI~
    int dirsw;                                                     //~v55nR~
#endif                                                             //~v55nI~
//*********************************                                //~v6D3I~
	if (!(Smdosflag & MDOSF_DATE_STRING))   //issued setenv(MTOOLS_DATESTRING=mm-dd-yyyy)//~v6D3R~
    {                                                              //~v6D3I~
		Smdosflag|=MDOSF_DATE_STRING;                              //~v6D3I~
        mtoolsinit();                                              //~v6D3I~
    }                                                              //~v6D3I~
	*Pppudl=0; 	//init                                             //~v50GR~
//get filename list                                                //~v50GI~
#ifdef AIX                                                         //~v55nI~
    rootsw=MDOSROOTDIR(Ppfname);                                   //~v55nI~
    len=(int)strlen(Ppfname);                                      //~v55nR~
    memcpy(fpathwk,Ppfname,(UINT)len);                             //~v55nI~
    *(fpathwk+len)=0;	                                           //~v55nI~
    if (!rootsw && *(fpathwk+len-1)==DIR_SEPC)                     //~v55nR~
    {                                                              //~v55nI~
    	len--;                                                     //~v55nI~
    	*(fpathwk+len)=0;	//drop last / for avoid dosdir err     //~v55nR~
    }                                                              //~v55nI~
	if (rootsw || Sintcallsw==2)	//2nd call for member          //~v55nR~
    	sprintf(mtoolscmd,CMD_DOSDIR_AL,fpathwk+3); //drop a:/     //~v55nM~
    else                                                           //~v55nI~
    	sprintf(mtoolscmd,CMD_DOSDIR_ALD,fpathwk+3); //drop a:/    //~v55nM~
#else                                                              //~v55nI~
    sprintf(mtoolscmd,CMD_MDIR,Ppfname);                           //~v50GR~
#endif                                                             //~v55nI~
//  rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,&stdo,0,&stdoctr,0);	//get stdout/stderr//~v558R~
//  rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG|MDCO_CHKSTDO,        //~v558I~//~v6D0R~
    rc=(unsigned)ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG|MDCO_CHKSTDO,//~v6D0R~
				mtoolscmd,&stdo,0,&stdoctr,0);	//get stdout/stderr//~v558I~
#ifdef AIX                                                         //~v55qI~
	if (!rc)                                                       //~v55qI~
    	rc=ufilenoentrychk(stdo,stdoctr);                          //~v55qI~
#endif                                                             //~v55qI~
    if (rc)                                                        //~v50GI~
    {                                                              //~v538I~
    	if (stdo)                                                  //~v538I~
        	ufree(stdo);                                           //~v538I~
    	return rc;                                                 //~v50GI~
    }                                                              //~v538I~
#ifdef AIX                                                         //~v55nI~
    if (Sintcallsw==2)                                             //~v55nI~
    	rc=ufilegetmdosdl(&pudl,stdo,stdoctr,Scurpudl,Sparentpudl);//~v55nI~
    else                                                           //~v55nI~
    	rc=ufilegetmdosdl(&pudl,stdo,stdoctr,0,0);                 //~v55nI~
#else                                                              //~v55nI~
//  rc=ufilegetmdosdl(&pudl,stdo,stdoctr,&dirsw);                  //~v50GR~//~v6D0R~
    rc=(unsigned)ufilegetmdosdl(&pudl,stdo,stdoctr,&dirsw);        //~v6D0R~
#endif                                                             //~v55nI~
	ufree(stdo);                                                   //~v50GR~
    if (rc)                                                        //~v50GI~
    	return rc;                                                 //~v50GI~
#ifdef AIX                                                         //~v55nI~
    if (!Sintcallsw && !rootsw) //1st call                         //~v55nR~
        if (pudl->attr & FILE_DIRECTORY) //target is dir           //~v55nI~
        {                                                          //~v55nI~
        	Sintcallsw=1;                                          //~v55nI~
            Scurpudl=pudl;                                         //~v55nM~
        	Sparentpudl=0;                                         //~v55nI~
            pathlen=PATHLEN(fpathwk);                              //~v55nR~
            if (pathlen>0)                                         //~v55nR~
            {                                                      //~v55nR~
                *(fpathwk+pathlen)=0;                              //~v55nR~
                if (!MDOSROOTDIR(fpathwk))                         //~v55nR~
                    uopendir_mdos(fpathwk,&Sparentpudl); //parent attr//~v55nR~
            }                                                      //~v55nR~
        	Sintcallsw=2;                                          //~v55nI~
			rc=uopendir_mdos(Ppfname,&pudl); //dir itself and member//~v55nR~
            if (rc)     //no member                                //~v562R~
    			ufilegetmdosdl(&pudl,0,0,Scurpudl,Sparentpudl);    //~v562R~
        	Sintcallsw=0;                                          //~v55nI~
        }                                                          //~v55nI~
#endif                                                             //~v55nI~
    *Pppudl=pudl;                                                  //~v50GR~
#ifdef AIX                                                         //~v55nI~
#else                                                              //~v55nI~
//get attr                                                         //~v50GI~
	if (dirsw                                                      //~v50GI~
    &&  *(Ppfname+strlen(Ppfname)-1)!=DIR_SEPC)                    //~v50GI~
    	pwc="/" DIR_ALLMEMB;                                       //~v50GI~
    else                                                           //~v50GI~
    	pwc="";                                                    //~v50GI~
    sprintf(mtoolscmd,CMD_MATTRIB2,Ppfname,pwc);                   //~v50GR~
//  rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,&stdo,0,&stdoctr,0);	//get stdout/stderr//~v50GR~//~v6D0R~
    rc=(unsigned)ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,&stdo,0,&stdoctr,0);	//get stdout/stderr//~v6D0R~
    if (rc)                                                        //~v50GI~
    {                                                              //~v538I~
    	if (stdo)                                                  //~v538I~
        	ufree(stdo);                                           //~v538I~
    	return rc;                                                 //~v50GI~
    }                                                              //~v538I~
    ufilegetmdosattrlist(pudl,stdo,stdoctr);                       //~v50GI~
	ufree(stdo);                                                   //~v50GI~
#endif                                                             //~v55nI~
    return 0;                                                      //~v50GI~
}//uopendir_mdos                                                   //~v55nR~
//**********************************************************************//~v50GM~
// find next msdos disket drive                                    //~v50GM~
// parm1  :filename                                                //~v50GM~
// parm2  :found file info                                         //~v50GM~
// return :r.c  0:found 4:no more file else errno                  //~v50GM~
//**********************************************************************//~v50GM~
unsigned ureaddir_mdos(PUDIRLIST *Pppudl,char *Ppath,int Ppathlen,ULONG Pattr,//~v55nR~
							FILEFINDBUF3 *Ppfstat3)                //~v50GM~
{                                                                  //~v50GM~
    int    rc=0;                                                   //~v50GM~
    PUDIRLIST pudl;                                                //~v50GM~
	char fpath[_MAX_PATH];                                         //~v50GI~
//*********************************                                //~v50GM~
//  memcpy(fpath,Ppath,Ppathlen);                                  //~v50GI~//~v6D0R~
    memcpy(fpath,Ppath,(size_t)Ppathlen);                          //~v6D0R~
    if (Ppathlen >0 && *(fpath+Ppathlen-1)!='/')                   //~v50GI~
        *(fpath+Ppathlen++)='/';                                   //~v50GR~
    memset(Ppfstat3,0,sizeof(FILEFINDBUF3));                       //~v50GI~
	for (pudl=*Pppudl;;pudl++)	//current pos                      //~v50GR~
    {                                                              //~v50GM~
//  	if (!*pudl->name)	//last entry                           //~v50GM~//~v6J0R~
    	if (!pudl->name)	//last entry                           //~v6J0I~
        {                                                          //~v50GM~
            rc=ERROR_NO_MORE_FILES;                                //~v50GM~
            *Pppudl=pudl;                                          //~v50GI~
            break;                                                 //~v50GM~
        }                                                          //~v50GM~
	    strcpy(fpath+Ppathlen,pudl->name);                         //~v50GR~
//      Ppfstat3->attrFile=pudl->attr;                             //~v56nR~
        Ppfstat3->attrFile=pudl->attr|FILE_MDOSDISK;               //~v56nI~
//      if (ufilelnxattrselect(Ppfstat3->attrFile,Pattr))    //attr match//~v56nR~
        if (ufilelnxattrselect(Ppfstat3->attrFile,0,Pattr))    //attr match//~v56nI~
        {                                                          //~v50GI~
	        strcpy(Ppfstat3->achName,pudl->name);                  //~v50GR~
	        Ppfstat3->cbFile=pudl->size;                           //~v50GI~
	        Ppfstat3->fdateLastWrite=pudl->date;                   //~v50GR~
	        Ppfstat3->ftimeLastWrite=pudl->time;                   //~v50GR~
            *Pppudl=pudl+1;                                        //~v50GI~
            break;                                                 //~v50GM~
        }                                                          //~v50GI~
    }                                                              //~v50GM~
//  return rc;                                                     //~v50GM~//~v6D0R~
    return (unsigned)rc;                                           //~v6D0R~
}//ureaddir_mdos                                                   //~v55nR~
#ifdef AIX                                                         //~v55nI~
//**********************************************************************//~v55nI~
// find first for msdos disket(create udirlist)                    //~v55nI~
// parm1  :output pudirlist                                        //~v55nI~
// parm2  :dosdir cmd stdout list                                  //~v55nI~
// parm3  :dosdir cmd stdout line counter                          //~v55nI~
// parm4  :top dir info by -d option                               //~v55nR~
// return :r.c                                                     //~v55nI~
//**********************************************************************//~v55nI~
int ufilegetmdosdl(PUDIRLIST *Pppudl,char **Pstdo,int Pstdoctr,    //~v55nR~
						PUDIRLIST Ppudlself,PUDIRLIST Ppudlparent) //~v55nI~
{                                                                  //~v55nI~
	char **ppc,*rec,*pc,*pfnm,*psz,*pdtm,*pdtd,*pdty,*ptm,*pattr;  //~v55nR~
    int  ii,fldno,len;                                             //~v55nI~
    PUDIRLIST pudl,pudl0;                                          //~v55nI~
	FILEFINDBUF3  ffb3;                                            //~v55nI~
//*********************************                                //~v55nI~
	len=(Pstdoctr+3)*sizeof(UDIRLIST);	//last null                //~v55nR~
	pudl=pudl0=ucalloc((UINT)len,1);	//last null                //~v55nI~
    if (!pudl)                                                     //~v55nI~
    	return UALLOC_FAILED;                                      //~v55nI~
    if (Ppudlself) //setup "." and ".." entry                      //~v55nR~
    {                                                              //~v55nI~
//      *pudl=*Ppudlself;                                          //~v55nR~//~v6qaR~
        UDIRLIST_COPY(pudl,Ppudlself);                             //~v6qaI~
//      ufree(Ppudlself);                                          //~v55nR~//~v6qaR~
        UDIRLIST_FREE(Ppudlself);                                  //~v6qaR~
//      strncpy(pudl->name,".",sizeof(pudl->name));  //cur path entry//~v55nR~//~v6J0R~
    	udirlist_setname(0,pudl,".",0/*use strlen*/);              //~v6J0R~
        pudl++;                                                    //~v55nR~
    	if (Ppudlparent)                                           //~v55nI~
        {                                                          //~v55nI~
//        	*pudl=*Ppudlparent;		//parent dir info              //~v55nI~//~v6qaR~
          	UDIRLIST_COPY(pudl,Ppudlparent);		//parent dir info//~v6qaI~
//          ufree(Ppudlparent);                                    //~v55nI~//~v6qaR~
            UDIRLIST_FREE(Ppudlparent);                            //~v6qaR~
        }                                                          //~v55nI~
        else                                                       //~v55nI~
//      	*pudl=*(pudl-1);                                       //+v6J0R~
          	UDIRLIST_COPY(pudl,(pudl-1));		//parent dir info  //+v6J0I~
//      strncpy(pudl->name,"..",sizeof(pudl->name));  //cur path entry//~v55nI~//~v6J0R~
    	udirlist_setname(0,pudl,"..",0/*use strlen*/);             //~v6J0R~
        pudl++;                                                    //~v55nI~
    }                                                              //~v55nI~
//  for (ppc=Pstdo,ii=0;*ppc && ii<Pstdoctr-1;ppc++,ii++)          //~v562R~
    for (ppc=Pstdo,ii=0;ii<Pstdoctr-1 && *ppc;ppc++,ii++)          //~v562R~
    {                                                              //~v55nI~
        rec=*ppc;		//recird ptr                               //~v55nR~
//process a line                                                   //~v55nI~
        pattr=0;            //may missing attr fld                 //~v55nI~
		for (fldno=0,pc=rec;;)                                     //~v55nI~
        {                                                          //~v55nI~
            switch(fldno)                                          //~v55nI~
            {                                                      //~v55nI~
            case 0:                                                //~v55nI~
            	pfnm=pc;                                           //~v55nI~
                break;                                             //~v55nI~
            case 1:                                                //~v55nI~
            	psz=pc;         //size                             //~v55nI~
                break;                                             //~v55nI~
            case 2:                                                //~v55nI~
            	pdtm=pc; 		//May 01 2002                      //~v55nI~
                break;                                             //~v55nI~
            case 3:                                                //~v55nI~
            	pdtd=pc; 		//May 01 2002                      //~v55nI~
                break;                                             //~v55nI~
            case 4:                                                //~v55nI~
            	pdty=pc; 		//May 01 2002                      //~v55nI~
                break;                                             //~v55nI~
            case 5:             //hh:mm:ss                         //~v55nI~
            	ptm=pc;                                            //~v55nI~
                break;                                             //~v55nI~
            case 6:             //[DRHS]                           //~v55nI~
            	pattr=pc;                                          //~v55nI~
                break;                                             //~v55nI~
            }                                                      //~v55nI~
            fldno++;                                               //~v55nI~
            if (fldno==7)   //long filename                        //~v55nI~
                break;                                             //~v55nI~
            for (;*pc;pc++)                                        //~v55nI~
            	if (*pc==' ')                                      //~v55nI~
                    break;                                         //~v55nI~
            for (;*pc;pc++)                                        //~v55nI~
            	if (*pc==' ')                                      //~v55nI~
                    *pc=0;                                         //~v55nI~
                else                                               //~v55nI~
                    break;                                         //~v55nI~
            if (!*pc)                                              //~v55nI~
            	break;                                             //~v55nI~
        }//line char                                               //~v55nI~
        if (fldno<6)    //attr may missing                         //~v55nR~
        	break;                                                 //~v55nI~
//setup udirlist                                                   //~v55nI~
//      strcpy(pudl->name,pfnm);                                   //~v55nI~//~v6J0R~
        udirlist_setname(0,pudl,pfnm,0/*use *strlen*/);	           //~v6J0I~
        pudl->size=atol(psz);                                      //~v55nI~
        pudl->date.month=ugetmonth(pdtm);                          //~v55nI~
        pudl->date.day=atoi(pdtd);                                 //~v55nI~
        pudl->date.year=atoi(pdty)-1980;                           //~v55nI~
        pudl->time.hours=atoi(ptm);                                //~v55nI~
        pudl->time.minutes=atoi(ptm+3);                            //~v55nI~
        pudl->time.twosecs=atoi(ptm+6)/2;                          //~v55nI~
                                                                   //~v55nI~
		ffb3.attrFile=0;                                           //~v55nI~
        if (pattr) 	//attr fld exist                               //~v55nI~
        {                                                          //~v55nI~
			ufilegetmdosattr(&ffb3,pattr+1);                       //~v55nR~
			pudl->attr=(UCHAR)ffb3.attrFile;                       //~v55nR~
        }                                                          //~v55nI~
		pudl++;                                                    //~v55nI~
    }                                                              //~v55nI~
    *Pppudl=pudl0;                                                 //~v55nI~
    return 0;                                                      //~v55nI~
}//ufilegetmdosdl                                                  //~v55nI~
//**********************************************************************//~v55nI~
// return :month(01-12)                                            //~v55nI~
//**********************************************************************//~v55nI~
int ugetmonth(char *Pmonth)                                        //~v55nI~
{                                                                  //~v55nI~
	int ii;                                                        //~v55nI~
static char *Smonthtb[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul",//~v55nI~
                         "Aug","Sep","Oct","Nov","Dec"};           //~v55nI~
//******************                                               //~v55nI~
    for (ii=0;ii<12;ii++)                                          //~v55nI~
        if (!memicmp(Pmonth,Smonthtb[ii],3))                       //~v55nI~
        	return ii+1;                                           //~v55nI~
	return 0;                                                      //~v55nI~
}//ugetmonth                                                       //~v55nI~
#else	//!aix                                                     //~v55nI~
//**********************************************************************//~v50GI~
// find first for msdos discket(create udirlist)                   //~v50GI~
// parm1  :file name                                               //~v50GI~
// parm2  :HDIR ptr,if no contention,specify 0.for dos specify always 0//~v50GI~
// parm3  :search file attribute                                   //~v50GI~
// parm4  :found file info                                         //~v50GI~
// return :r.c                                                     //~v50GI~
//**********************************************************************//~v50GI~
int ufilegetmdosdl(PUDIRLIST *Pppudl,char **Pstdo,int Pstdoctr,int *Ppdirsw)//~v50GR~
{                                                                  //~v50GI~
	char **ppc,*rec,*pc,*pc2,*pfnm=NULL,*plfn,*psz=NULL,*pdt=NULL,*ptm=NULL,*pext=NULL;//~v6h9R~
    int  ii,hdrsw=0,fldno,rc=0,len;                                //~v50GR~
    PUDIRLIST pudl,pudl0;                                          //~v50GR~
    int mm;                                                        //~v6D3R~
//*********************************                                //~v50GI~
	*Ppdirsw=0;                                                    //~v50GI~
//  len=(Pstdoctr+1)*sizeof(UDIRLIST);	//last null                //~v50GR~//~v6D0R~
    len=(Pstdoctr+1)*(int)sizeof(UDIRLIST);	//last null            //~v6D0R~
	pudl=pudl0=ucalloc((UINT)len,1);	//last null                //~v50GR~
    if (!pudl)                                                     //~v50GR~
    	return UALLOC_FAILED;                                      //~v50GI~
	for (ppc=Pstdo,ii=0,hdrsw=0;*ppc;ppc++,ii++)                   //~v50GI~
    {                                                              //~v50GI~
        rec=*ppc;		//recird ptr                               //~v50GI~
        if (*rec)	//null line                                    //~v50GI~
        {                                                          //~v50GI~
        	if (!hdrsw)	//not yet skipped hdr part                 //~v50GI~
            	continue;                                          //~v50GI~
        }                                                          //~v50GI~
        else		//null line                                    //~v50GI~
        	if (!hdrsw)                                            //~v50GI~
            {                                                      //~v50GI~
            	hdrsw=1;                                           //~v50GI~
                continue;                                          //~v50GI~
            }                                                      //~v50GI~
        if (*rec==' ')	//file ctr line                            //~v50GI~
        	break;                                                 //~v50GI~
//process a line                                                   //~v50GI~
		plfn=0;		//for DOS (not win lfn)                        //~v50GR~
		for (fldno=0,pc=rec;;)                                     //~v50GR~
        {                                                          //~v50GI~
            switch(fldno)                                          //~v50GI~
            {                                                      //~v50GI~
            case 0:                                                //~v50GI~
            	pfnm=pc;                                           //~v50GR~
                for (pc2=pc+8;pc2>pc;pc2--) //get basename         //~v50GR~
                    if (*pc2==' ')                                 //~v50GI~
                        *pc2=0;                                    //~v50GI~
                    else                                           //~v50GI~
                        break;                                     //~v50GI~
                pext=pc+9;                                         //~v50GI~
                for (pc2=pext+2;pc2>=pext;pc2--)                 //ext//~v50GI~
                    if (*pc2==' ')                                 //~v50GI~
                        *pc2=0;                                    //~v50GI~
                    else                                           //~v50GI~
                        break;                                     //~v50GI~
                pc=pext+3;                                         //~v50GI~
                break;                                             //~v50GI~
            case 1:                                                //~v50GI~
            	psz=pc;         //size or <DIR>                    //~v50GI~
                break;                                             //~v50GI~
            case 2:                                                //~v50GI~
            	pdt=pc; 		//mm-dd-yyyy                       //~v50GI~
                break;                                             //~v50GI~
            case 3:                                                //~v50GI~
            	ptm=pc;                                            //~v50GI~
                break;                                             //~v50GI~
            case 4:                                                //~v50GI~
            	plfn=pc;                                           //~v50GI~
                break;                                             //~v50GI~
            }                                                      //~v50GI~
            fldno++;                                               //~v50GM~
            if (fldno==5)   //long filename                        //~v50GI~
                break;                                             //~v50GI~
            for (;*pc;pc++)                                        //~v50GI~
            	if (*pc==' ')                                      //~v50GR~
                    break;                                         //~v50GR~
            for (;*pc;pc++)                                        //~v50GI~
            	if (*pc==' ')                                      //~v50GI~
                    *pc=0;                                         //~v50GI~
                else                                               //~v50GI~
                    break;                                         //~v50GI~
            if (!*pc)                                              //~v50GI~
            	break;                                             //~v50GI~
        }//line char                                               //~v50GI~
        if (fldno<4)                                               //~v50GR~
        	break;                                                 //~v50GI~
//setup udirlist                                                   //~v50GI~
		if (plfn)                                                  //~v50GI~
//      	strcpy(pudl->name,plfn);                               //~v50GR~//~v6J0R~
            udirlist_setname(0,pudl,plfn,0/*use *strlen*/);        //~v6J0I~
        else                                                       //~v50GI~
        {                                                          //~v50GI~
//      	strcpy(pudl->name,pfnm);                               //~v50GR~//~v6J0R~
            udirlist_setname(0,pudl,pfnm,0/*use *strlen*/);        //~v6J0I~
            if (*pext)                                             //~v50GR~
            {                                                      //~v50GI~
//          	strcat(pudl->name,".");                            //~v50GI~//~v6J0R~
//          	strcat(pudl->name,pext);                           //~v50GI~//~v6J0I~
        	    udirlist_setname_cat(0,pudl,".");                  //~v6J0I~
        	    udirlist_setname_cat(0,pudl,pext);                 //~v6J0R~
            }                                                      //~v50GI~
        }                                                          //~v50GI~
        if (!strcmp(pudl->name,".")		//cur                      //~v50GI~
        ||  !strcmp(pudl->name,".."))   //parent                   //~v50GI~
        	*Ppdirsw=1;                                            //~v50GI~
        if (!strcmp(psz,"<DIR>"))                                  //~v50GI~
        	pudl->attr|=FILE_DIRECTORY;                            //~v50GR~
        else                                                       //~v50GI~
        	pudl->size=atol(psz);                                  //~v50GI~
//      pudl->date.month=atoi(pdt);                                //~v50GI~//~v6D2R~
//      pudl->date.day=atoi(pdt+3);                                //~v50GI~//~v6D2R~
//      pudl->date.year=atoi(pdt+6)-1980;                          //~v50GI~//~v6D2R~
        ueditsetfdateUSHORT(0,atoi(pdt+6)-1980,atoi(pdt),atoi(pdt+3),&pudl->date);//~v6D2R~
//      pudl->time.hours=atoi(ptm);                                //~v50GI~//~v6D2R~
      if (*(ptm+1)==':')                                           //~v55bI~
//      pudl->time.minutes=atoi(ptm+2);                            //~v55bI~//~v6D2R~
        mm=atoi(ptm+2);                                            //~v6D2I~
      else                                                         //~v55bI~
//      pudl->time.minutes=atoi(ptm+3);                            //~v50GI~//~v6D2R~
        mm=atoi(ptm+3);                                            //~v6D2I~
        ueditsetftimeUSHORT(0,atoi(ptm),mm,0/*ss*/,&pudl->time);   //~v6D2I~
//*                                                                //~v50GI~
		pudl++;                                                    //~v50GI~
    }                                                              //~v50GI~
    if (rc)                                                        //~v50GI~
    {                                                              //~v50GI~
//  	ufree(pudl0);                                              //~v50GR~//~v6qaR~
    	UDIRLIST_FREE(pudl0);                                      //~v6qaI~
//      if (pot)                                                   //~v538R~
//      	ufree(pot);                                            //~v538R~
        pudl0=0;                                                   //~v50GR~
    }                                                              //~v50GI~
    *Pppudl=pudl0;                                                 //~v50GR~
    return rc;                                                     //~v50GI~
}//ufilegetmdosdl                                                  //~v50GI~
#endif	//lnx                                                      //~v55nI~
#ifdef AIX                                                         //~v55nI~
#else   //lnx                                                      //~v55nI~
//**********************************************************************//~v50GI~
// find first for msdos discket(create udirlist)                   //~v50GI~
// parm1  :dir list                                                //~v50GI~
// parm2  :mattrib cmd stdout                                      //~v50GI~
// parm3  :line ctr                                                //~v50GI~
// return :r.c                                                     //~v50GI~
//**********************************************************************//~v50GI~
int ufilegetmdosattrlist(PUDIRLIST Ppudl,char **Pstdo,int Pstdoctr)//~v50GI~
{                                                                  //~v50GI~
	char **ppc,*rec,*pfn;                                          //~v50GR~
    PUDIRLIST pudl;                                                //~v50GI~
    FILEFINDBUF3 ffb3;                                             //~v50GR~
    int pathlen;                                                   //~v50GI~
//*********************************                                //~v50GI~
	for (ppc=Pstdo;*ppc;ppc++)                                     //~v50GI~
    {                                                              //~v50GI~
        rec=*ppc;		//recird ptr                               //~v50GI~
        if (!*rec)	//null line                                    //~v50GR~
        	continue;                                              //~v50GI~
        for (pfn=rec+ATTRIB_FLDWIDTH;*pfn;pfn++)                   //~v50GR~
        	if (*pfn!=' ')                                         //~v50GI~
            	break;                                             //~v50GI~
        if ((pathlen=PATHLEN(pfn))<0)                              //~v50GI~
        	pathlen=0;			//no path                          //~v50GI~
        pfn+=pathlen;                                              //~v50GI~
    	ffb3.attrFile=FILE_MDOSDISK;     //init                    //~v50GR~
    	ufilegetmdosattr(&ffb3,rec);                               //~v50GR~
        if (!*pfn)  //root dir                                     //~v56nI~
        {                                                          //~v56nI~
            Ppudl->attr|=ffb3.attrFile;                            //~v56nI~
		    return 0;                                              //~v56nI~
        }                                                          //~v56nI~
		for (pudl=Ppudl;;pudl++)	//current pos                  //~v50GI~
        {                                                          //~v50GI~
//  		if (!*pudl->name)	//last entry                       //~v50GI~//~v6J0R~
    		if (!pudl->name)	//last entry                       //~v6J0I~
            	break;                                             //~v50GI~
			if (!stricmp(pfn,pudl->name))	                       //~v50GI~
            {                                                      //~v50GI~
            	pudl->attr|=ffb3.attrFile;                         //~v50GR~
                break;                                             //~v50GI~
            }                                                      //~v50GI~
        }//udirlist                                                //~v50GI~
    }//mattrib line                                                //~v50GI~
    return 0;                                                      //~v50GI~
}//ufilegetmdosattrlist                                            //~v50GI~
#endif	//lnx                                                      //~v55nI~
//**********************************************************************//~v50GI~
// find first for msdos discket(create udirlist)                   //~v50GI~
// parm1  :file name                                               //~v50GI~
// return :1:diffferent drive 4: err                               //~v50GR~
//**********************************************************************//~v50GI~
int ugetcwd_mdos(UCHAR *Pfnm)                                      //~v50GR~
{                                                                  //~v50GI~
#ifdef AIX   //always return root                                  //~v55nR~
    *(Pfnm+2)=DIR_SEPC;                                            //~v55nI~
    *(Pfnm+3)=0;                                                   //~v55nI~
	return 0;                                                      //~v55nR~
#else                                                              //~v55nI~
    int rc,stdoctr;                                                //~v50GR~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v50GI~
    char **stdo;                                                   //~v50GR~
//*********************************                                //~v50GI~
    sprintf(mtoolscmd,CMD_MCD);                                    //~v50GI~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,&stdo,0,&stdoctr,0);	//get stdout/stderr//~v50GR~
    if (rc)                                                        //~v50GI~
    {                                                              //~v538I~
    	if (stdo)                                                  //~v538I~
        	ufree(stdo);                                           //~v538I~
    	return rc;                                                 //~v50GR~
    }                                                              //~v538I~
    if (toupper(**stdo)==toupper(*Pfnm))	//mtool hold only one drive path//~v50GI~
    {                                                              //~v50GI~
		strcpy(Pfnm,*stdo);                                        //~v50GR~
        rc=0;                                                      //~v50GI~
    }                                                              //~v50GI~
    else                                                           //~v50GI~
    {                                                              //~v50GI~
    	*(Pfnm+2)='/';  //set root                                 //~v50GI~
    	*(Pfnm+3)=0;                                               //~v50GI~
    	rc=1;                                                      //~v50GI~
    }                                                              //~v50GI~
	ufree(stdo);                                                   //~v50GI~
    return rc;                                                     //~v50GR~
#endif                                                             //~v55nI~
}//ugetcwd_mdos                                                    //~v50GR~
//**********************************************************************//~v55fI~
// change dir on disket                                            //~v55fI~
// mcd allow only one path on mdos dis(no path on each drive a: or b:)//~v55fI~
// parm1  :file name                                               //~v55fI~
// return :4: err                                                  //~v55fI~
//**********************************************************************//~v55fI~
int uchdir_mdos(UCHAR *Pfnm)                                       //~v55fI~
{                                                                  //~v55fI~
#ifdef AIX                                                         //~v55nI~
	return ufileerrmdosnotsupported("CD",Pfnm);                    //~v563R~
#else                                                              //~v55nI~
    int rc;                                                        //~v55fI~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v55fI~
//*********************************                                //~v55fI~
    sprintf(mtoolscmd,CMD_MCD2,Pfnm);                              //~v55fR~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,0,0,0,0);  //~v55fI~
    if (rc)                                                        //~v55fI~
    	return 4;                                                  //~v55fI~
    return 0;                                                      //~v55fI~
#endif                                                             //~v55nI~
}//uchdir_mdos                                                     //~v55fI~
#ifdef AIX                                                         //~v55nI~
//**********************************************************************//~v55nI~
// statfs(disk info)                                               //~v55nI~
// parm1  :file name                                               //~v55nI~
// parm2  :output statfs                                           //~v55nI~
// return :errno                                                   //~v55nI~
//**********************************************************************//~v55nI~
int ustatfs_mdos(UCHAR *Pfnm,struct statfs *Ppsfs)                 //~v55nI~
{                                                                  //~v55nI~
    int ii,rc,sectsz=512,sectno=2880,freesz=0,stdoctr;             //~v55nI~
    int clustsz;                                                   //~v565I~
    char **stdo,**ppc,*rec=0,*pce;                                 //~v55nI~
//*********************************                                //~v55nI~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,CMD_DOSDIR_V,&stdo,0,&stdoctr,0);	//get stdout/stderr//~v55nI~
    if (rc)                                                        //~v55nI~
    {                                                              //~v55nI~
    	if (stdo)                                                  //~v55nI~
        	ufree(stdo);                                           //~v55nI~
    	return rc;                                                 //~v55nI~
    }                                                              //~v55nI~
	for (ppc=stdo,ii=0;*ppc && ii<stdoctr;ppc++,ii++)              //~v55nR~
    {                                                              //~v55nI~
        rec=*ppc;		//recird ptr                               //~v55nI~
        pce=rec+strlen(rec);                                       //~v55nI~
        if (ii==1)	//2nd line; Disk data: 512 bytes...            //~v55nI~
            ufilegetnum(rec,(int)((ULONG)pce-(ULONG)rec),&sectsz); //~v55nI~
        else                                                       //~v55nI~
        if (ii==2)	//3rd line; Disk partition size: 2880 sectors...//~v55nI~
            ufilegetnum(rec,(int)((ULONG)pce-(ULONG)rec),&sectno); //~v55nI~
        else                                                       //~v565I~
        if (ii==3)	//4th line; Cluster size: 2 sectors...         //~v565I~
            ufilegetnum(rec,(int)((ULONG)pce-(ULONG)rec),&clustsz);//~v565I~
	}//line char                                                   //~v55nI~
    if (rec)                                                       //~v55nI~
    	ufilegetnum(rec,(int)((ULONG)pce-(ULONG)rec),&freesz);     //~v55nI~
	ufree(stdo);                                                   //~v55nI~
    if (!sectsz)                                                   //~v55nI~
    	sectsz=512;                                                //~v55nI~
    if (!clustsz)                                                  //~v565I~
    	clustsz=1;                                                 //~v565I~
//  Ppsfs->f_blocks=sectno;                                        //~v565R~
//  Ppsfs->f_bsize=sectsz;                                         //~v565R~
//  Ppsfs->f_bavail=freesz/sectsz;                                 //~v565R~
    Ppsfs->f_blocks=sectno/clustsz;                                //~v565I~
    Ppsfs->f_bsize=sectsz*clustsz;                                 //~v565I~
    Ppsfs->f_bavail=freesz/sectsz/clustsz;                         //~v565I~
    return 0;                                                      //~v55nI~
}//ustatfs_mdos                                                    //~v55nI~
//***************************************************************  //~v55nI~
//*get 1st number from dosdir line                                 //~v55nI~
//***************************************************************  //~v55nI~
int ufilegetnum(char *Ppc,int Plen,int *Ppint)                     //~v55nI~
{                                                                  //~v55nI~
	int ii;                                                        //~v55nI~
    char *pc;                                                      //~v55nI~
//******************************                                   //~v55nI~
    *Ppint=0;                                                      //~v55nI~
    for (pc=Ppc,ii=0;ii<Plen;pc++,ii++) //for space embeding       //~v55nI~
        if (*pc>='0' && *pc<='9')                                  //~v55nI~
        {                                                          //~v55nI~
        	*Ppint=atoi(pc);                                       //~v55nI~
            return 0;                                              //~v55nI~
        }                                                          //~v55nI~
    return 4;                                                      //~v55nI~
}//ufilegetnum                                                     //~v55nI~
#else	//lnx                                                      //~v55nI~
//**********************************************************************//~v50GI~
// statfs(disk info)                                               //~v50GI~
// parm1  :file name                                               //~v50GI~
// parm2  :output statfs                                           //~v50GI~
// return :errno                                                   //~v50GI~
//**********************************************************************//~v50GI~
int ustatfs_mdos(UCHAR *Pfnm,struct statfs *Ppsfs)                 //~v50GI~
{                                                                  //~v50GI~
    int ii,rc,freesz=0;                                            //~v50GR~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v50GI~
    char **stdo,**ppc,*rec,*pc;                                    //~v50GR~
//*********************************                                //~v50GI~
	memset(Ppsfs,0,sizeof(struct statfs));                         //~v50GR~
    if (rc=uminfo(Pfnm,Ppsfs),rc)                                  //~v50GI~
    	return rc;                                                 //~v50GI~
    sprintf(mtoolscmd,CMD_MDIR2,*Pfnm);                            //~v50GR~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,&stdo,0,0,0);	//get stdout/stderr//~v50GI~
    if (rc)                                                        //~v50GI~
    {                                                              //~v538I~
    	if (stdo)                                                  //~v538I~
        	ufree(stdo);                                           //~v538I~
    	return rc;                                                 //~v50GI~
    }                                                              //~v538I~
	for (ppc=stdo,ii=0;*ppc;ppc++,ii++)                            //~v50GR~
    {                                                              //~v50GI~
        rec=*ppc;		//recird ptr                               //~v50GI~
        if (!*rec)	//null line                                    //~v50GI~
            continue;                                              //~v50GR~
        if (pc=strstr(rec,"bytes free"),pc)                        //~v50GI~
            if (!ufilegetnum(rec,(int)((ULONG)pc-(ULONG)rec),&freesz))//~v50GR~
            	break;                                             //~v50GI~
	}//line char                                                   //~v50GI~
	ufree(stdo);                                                   //~v50GI~
//  Ppsfs->f_bavail=freesz/Ppsfs->f_bsize;                         //~v50GR~//~v6D0R~
#ifdef ARM                                                         //~v6E4I~
    Ppsfs->f_bavail=freesz/Ppsfs->f_bsize;                         //~v6E4I~
#else                                                              //~v6E4I~
    Ppsfs->f_bavail=(__fsblkcnt64_t)(freesz/Ppsfs->f_bsize);       //~v6D0R~
#endif                                                             //~v6E4I~
    return 0;                                                      //~v50GI~
}//ustatfs_mdos                                                    //~v50GI~
//**********************************************************************//~v50GI~
// get drive info for mdos disk                                    //~v50GI~
// parm1  :file name                                               //~v50GI~
// parm2  :output statfs(blocksz=cluster size,blockno=cluster no)  //~v565R~
// return :errno                                                   //~v50GI~
//**********************************************************************//~v50GI~
int uminfo(UCHAR *Pfnm,struct statfs *Ppsfs)                       //~v50GI~
{                                                                  //~v50GI~
    int ii,rc,sectsz=0,sectno=0;                                   //~v50GR~
    int clustsz=0;                                                 //~v565I~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v50GI~
    char **stdo,**ppc,*rec,*pc,*pce;                               //~v50GI~
static char Ssectsz[]="sector size:";                              //~v50GI~
static char Sclustsz[]="cluster size:";                            //~v565I~
static char Ssectno[]="small size:";                               //~v50GI~
//*********************************                                //~v50GI~
    sprintf(mtoolscmd,CMD_MINFO,*Pfnm);                            //~v50GI~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,&stdo,0,0,0);	//get stdout/stderr//~v50GI~
    if (rc)                                                        //~v50GI~
    {                                                              //~v538I~
    	if (stdo)                                                  //~v538I~
        	ufree(stdo);                                           //~v538I~
    	return rc;                                                 //~v50GI~
    }                                                              //~v538I~
	for (ppc=stdo,ii=0;*ppc;ppc++,ii++)                            //~v50GI~
    {                                                              //~v50GI~
        rec=*ppc;		//recird ptr                               //~v50GI~
        pce=rec+strlen(rec);                                       //~v50GR~
        if (!*rec)	//null line                                    //~v50GI~
            continue;                                              //~v50GI~
        else                                                       //~v50GI~
        if (pc=strstr(rec,Ssectsz),pc)                             //~v50GI~
            ufilegetnum(pc+sizeof(Ssectsz),(int)((ULONG)pce-(ULONG)pc-sizeof(Ssectsz)),&sectsz);//~v50GR~
        else		//null line                                    //~v50GI~
        if (pc=strstr(rec,Sclustsz),pc)                            //~v565I~
            ufilegetnum(pc+sizeof(Sclustsz),(int)((ULONG)pce-(ULONG)pc-sizeof(Sclustsz)),&clustsz);//~v565I~
        else		//null line                                    //~v565I~
        if (pc=strstr(rec,Ssectno),pc)                             //~v50GI~
        {                                                          //~v50GI~
            ufilegetnum(pc+sizeof(Ssectno),(int)((ULONG)pce-(ULONG)pc-sizeof(Ssectno)),&sectno);//~v50GR~
            break;                                                 //~v50GI~
        }                                                          //~v50GI~
	}//line char                                                   //~v50GI~
	ufree(stdo);                                                   //~v50GI~
    if (!sectsz)                                                   //~v50GI~
    	sectsz=512;                                                //~v50GI~
    if (!clustsz)                                                  //~v565I~
    	clustsz=1;                                                 //~v565I~
//  Ppsfs->f_blocks=sectno;                                        //~v565R~
//  Ppsfs->f_blocks=sectno/clustsz;                                //~v565I~//~v6D0R~
#ifdef ARM                                                         //~v6E4I~
    Ppsfs->f_blocks=sectno/clustsz;                                //~v6E4I~
#else                                                              //~v6E4I~
    Ppsfs->f_blocks=(__fsblkcnt64_t)(sectno/clustsz);              //~v6D0R~
#endif                                                             //~v6E4I~
//  Ppsfs->f_bsize=sectsz;                                         //~v565R~
    Ppsfs->f_bsize=sectsz*clustsz;                                 //~v565I~
    return 0;                                                      //~v50GI~
}//uminfo                                                          //~v55nR~
//***************************************************************  //~v50GI~
//*get number from space embeding string                           //~v50GI~
//***************************************************************  //~v50GI~
int ufilegetnum(char *Ppc,int Plen,int *Ppint)                     //~v50GI~
{                                                                  //~v50GI~
	int ii,jj=0;                                                   //~v50GI~
    char *pc,numwk[12];                                            //~v50GR~
//******************************                                   //~v50GI~
    for (pc=Ppc,ii=0;ii<Plen;pc++,ii++) //for space embeding       //~v50GR~
    	if (*pc==' ')                                              //~v50GI~
        	continue;                                              //~v50GI~
        else                                                       //~v50GI~
        if (*pc>='0' && *pc<='9')                                  //~v50GI~
        {                                                          //~v50GI~
        	if (jj==10)                                            //~v50GI~
            	return 4;                                          //~v50GI~
            numwk[jj++]=*pc;                                       //~v50GI~
        }                                                          //~v50GI~
        else                                                       //~v50GI~
        	break;                                                 //~v50GR~
    numwk[jj]=0;                                                   //~v50GI~
    *Ppint=atoi(numwk);                                            //~v50GI~
    return 0;                                                      //~v50GI~
}//ufilegetnum                                                     //~v50GI~
#endif                                                             //~v55nI~
//**********************************************************************//~v50GI~
// interface to usystem_redirect                                   //~v50GI~
// parm1  :file name                                               //~v50GI~
// return :4:err,5(IOE),1:stderr freed                             //~v50GI~
//**********************************************************************//~v50GI~
int ufilemdoscmd(int Popt,char *Pcmd,char ***Pstdo,char ***Pstde,int *Pstdoctr,int *Pstdectr)//~v50GI~
{                                                                  //~v50GI~
	int rc,rc2;                                                    //~v558R~
    int stdochksw;                                                 //~v55oR~
    char **pstde,**ppc,**pstdo;                                    //~v558R~
//********************                                             //~v50GI~
    stdochksw=Popt & MDCO_CHKSTDO;                                 //~v558I~
//  nomsgsw=Popt & MDCO_NOMSG;                                     //~v55oR~
    Popt &= ~MDCO_CHKSTDO;  //reset my flag,residual is for usystem2 func//~v558I~
	if (Pstdo)                                                     //~v538I~
    	*Pstdo=0;                                                  //~v538I~
	if (Pstde)                                                     //~v538I~
    	*Pstde=0;                                                  //~v538I~
	if (Pstdoctr)                                                  //~v538I~
    	*Pstdoctr=0;                                               //~v538I~
	if (Pstdectr)                                                  //~v538I~
    	*Pstdectr=0;                                               //~v538I~
//  rc=usystem_redirect(Popt,Pcmd,Pstdo,&pstde,Pstdoctr,Pstdectr); //~v558R~
    rc=usystem_redirect(Popt,Pcmd,&pstdo,&pstde,Pstdoctr,Pstdectr);//~v558I~
    if (rc>1)     	                                               //~v50GR~
    	return rc;                                                 //~v50GI~
  if (!stdochksw)   //no stdout chk required                       //~v558R~
    if (!rc)                                                       //~v50GI~
    {                                                              //~v50GI~
	  	if (Pstdo) 	//return required                              //~v558I~
    		*Pstdo=pstdo;                                          //~v558I~
  		else                                                       //~v558I~
    		ufree(pstdo);                                          //~v558I~
        ufree(pstde);                                              //~v50GI~
    	return 0;                                                  //~v50GI~
    }                                                              //~v50GI~
  if (rc==1)	//stderr line output                               //~v558I~
  {                                                                //~v558I~
//rc=1 stderr exist                                                //~v50GI~
//  if (Pstde) 	//return required                                  //~v538R~
//  {	                                                           //~v538R~
//  	*Pstde=pstde;                                              //~v538R~
//  	errno=rc;                                                  //~v538R~
//      return rc;                                                 //~v538R~
//  }                                                              //~v538R~
//chk std err and set rc                                           //~v50GI~
	for (ppc=pstde;*ppc;ppc++)                                     //~v50GI~
    {                                                              //~v50GI~
//        rec=*ppc;       //recird ptr                             //~v558R~
//        if (strstr(rec,"Cannot")                                 //~v558R~
//        ||  strstr(rec,"Can't"))                                 //~v558R~
//        {                                                        //~v558R~
//            rc=EIO;                                              //~v558R~
//            break;                                               //~v558R~
//        }                                                        //~v558R~
//        if (strstr(rec,"not a directory"))                       //~v558R~
//        {                                                        //~v558R~
//            rc=ENOTDIR;                                          //~v558R~
//            break;                                               //~v558R~
//        }                                                        //~v558R~
//        if (strstr(rec,"not found"))                             //~v558R~
//        {                                                        //~v558R~
//            rc=ENOENT;                                           //~v558R~
//            break;                                               //~v558R~
//        }                                                        //~v558R~
//        if (strstr(rec,"No such file"))                          //~v558R~
//        {                                                        //~v558R~
//            rc=ENOENT;                                           //~v558R~
//            break;                                               //~v558R~
//        }                                                        //~v558R~
//        if (strstr(rec,"non empty"))                             //~v558R~
//        {                                                        //~v558R~
//            rc=ENOTEMPTY;                                        //~v558R~
//            break;                                               //~v558R~
//        }                                                        //~v558R~
//        if (strstr(rec,"across different drive"))                //~v558R~
//        {                                                        //~v558R~
//            rc=EXDEV;                                            //~v558R~
//            break;                                               //~v558R~
//        }                                                        //~v558R~
		rc2=ufilemdoserrchk(*ppc);                                 //~v55oR~
        if (rc2)                                                   //~v558I~
        {	                                                       //~v558I~
        	rc=rc2;                                                //~v558I~
            break;                                                 //~v558I~
        }                                                          //~v558I~
    }//stderr line                                                 //~v50GI~
  }//stderr exist                                                  //~v558I~
  if (Pstde) 	//return required                                  //~v538I~
    *Pstde=pstde;                                                  //~v538I~
  else                                                             //~v538I~
    ufree(pstde);                                                  //~v50GR~
  	if (stdochksw)   //no stdout chk required                      //~v558R~
		for (ppc=pstdo;*ppc;ppc++)                                 //~v558I~
    	{                                                          //~v558I~
			rc2=ufilemdoserrchk(*ppc);                             //~v55oR~
    	    if (rc2)                                               //~v558I~
        	{                                                      //~v558I~
        		rc=rc2;                                            //~v558I~
            	break;                                             //~v558I~
        	}                                                      //~v558I~
	    }//stdout line                                             //~v558I~
  	if (Pstdo) 	//return required                                  //~v558I~
    	*Pstdo=pstdo;                                              //~v558R~
  	else                                                           //~v558I~
    	ufree(pstdo);                                              //~v558I~
    errno=rc;                                                      //~v538I~
    return rc;                                                     //~v50GI~
}//ufilemdoscmd                                                    //~v50GI~
//**********************************************************************//~v558I~
int ufilemdoserrchk(char *Prec)                                    //~v55oR~
{                                                                  //~v558I~
	int rc=0;                                                      //~v558I~
//********************                                             //~v558I~
#ifdef AIX                                                         //~v55nI~
    if (strstr(Prec,"見つかりません")                              //~v55nI~
    ||  strstr(Prec,"Can't locate"))                               //~v55nI~
        rc=ENOENT;                                                 //~v55nI~
    if (strstr(Prec,"オープンできません")                          //~v55nI~
    ||  strstr(Prec,"Unable to open"))                             //~v55nI~
        rc=ENOENT;                                                 //~v55nI~
    if (strstr(Prec,"スペースが不足")                              //~v55nI~
    ||  strstr(Prec,"Insufficient disk space"))                    //~v55nI~
        rc=ENOSPC;                                                 //~v55nI~
//  if (rc)                                                        //~v55oR~
//      if (!(Popt & MDCO_NOMSG))                                  //~v55oR~
//  		uerrmsg("%s",                                          //~v55oR~
//      			"%s",                                          //~v55oR~
//              	Prec);                                         //~v55oR~
#else                                                              //~v55nI~
    if (strstr(Prec,"Cannot")                                      //~v558I~
    ||  strstr(Prec,"Can't"))                                      //~v558I~
        rc=EIO;                                                    //~v558I~
    if (strstr(Prec,"not a directory"))                            //~v558I~
        rc=ENOTDIR;                                                //~v558I~
    if (strstr(Prec,"not found"))                                  //~v558I~
        rc=ENOENT;                                                 //~v558I~
    if (strstr(Prec,"No such file"))                               //~v558I~
        rc=ENOENT;                                                 //~v558I~
    if (strstr(Prec,"non empty"))                                  //~v558I~
        rc=ENOTEMPTY;                                              //~v558I~
    if (strstr(Prec,"across different drive"))                     //~v558I~
        rc=EXDEV;                                                  //~v558I~
    if (strstr(Prec,"Disk full"))                                  //~v55eI~
        rc=ENOSPC;                                                 //~v55eI~
    if (strstr(Prec,"Permission"))                                 //~v55nI~
        rc=EACCES;                                                 //~v55nI~
#endif                                                             //~v55nI~
    return rc;                                                     //~v558I~
}//ufilemdoserrchk                                                 //~v558I~
#ifdef AIX                                                         //~v55nI~
//**********************************************************************//~v55nI~
int ufileerrmdosnotsupported(char *Pcmd,char *Pfnm)                //~v563R~
{                                                                  //~v55nI~
    uerrmsg("%s is not supported for AIX floppy drive (%s).",0,    //~v563R~
				Pcmd,Pfnm);                                        //~v563R~
    errno=ENOSYS;                                                  //~v55nI~
    return ENOSYS;	//not implemented                              //~v55nR~
}                                                                  //~v55nI~
//**********************************************************************//~v55qI~
int ufilenoentrychk(char **Pstdo,int Pstdoctr)                     //~v55qI~
{                                                                  //~v55qI~
//********************                                             //~v55qI~
	if (Pstdoctr!=1)                                               //~v55qR~
    	return 0;                                                  //~v55qI~
    if (strstr(*Pstdo,"バイトの空き領域")                          //~v55qI~
    ||  strstr(*Pstdo,"Free space:"))                              //~v55qR~
    {                                                              //~v55qI~
        errno=ENOENT;                                              //~v55qI~
        return ENOENT;                                             //~v55qI~
    }                                                              //~v55qI~
    return 0;                                                      //~v55qI~
}//ufilenoentrychk                                                 //~v55qI~
#endif                                                             //~v55nI~
