//*CID://+vbyxR~:                             update#=  754;       //~vbyxR~
//*************************************************************
//*ufiledoc.c                                                      //~v59nR~//~v77aR~
//*************************************************************
//vbyx:230725 ARM:alternative of vbyr. drop copytemp but rep // by real path if available://~vbyxI~
//vc5r 2023/07/25 try /sdcard for realpath for api<30              //~vc5rR~
//v786:230724 ARM:try to set env:PWD by cd for file parameter of tools//~v786I~
//v77Z:230718 ARM;support CD to shared storage                     //~v77ZI~
//v77S:230705 chk exist for copytemp to avoid invalidargumentexception//~v77SI~
//vc5c 2023/07/04 display directory set to access by ACTION_OPEN_DOCUMENT_TREE//~vc5cI~
//v77M:230627 (Bug)native opendir is available by addtitional condition of permission over API30//~v77MI~
//           ufilepdoc.c                                           //~v77MI~
//v77B:230612 ARM;warning by audroidstudio compiler                //~v77BI~
//v77z:230530 >=API30, support shared storage for cmd parameter. by v77W, replace sortpath by real path name on cmd parm.//~v77zI~
//v77x 230520 return null for wildcard opendir using path like as linux(opendirFD return null by exception as following//~v77xI~
//            java.lang.IllegalArgumentException: Failed to determine if primary:Axe/* is child of primary:Axe: java.io.FileNotFoundException: Missing file for primary:Axe/* at /storage/emulated/0/Axe/*//~v77xI~
//v77w:230519 uri-->path is avalable from api30(android11:R) and readdir using fd gotten by openDescriptor returns null//~v77wI~
//vbyh:230514 (ARM)dlcmd "=" support for external storage          //~vbyhI~
//v77r:230507 ARM:issue invalid shortpath name msg                 //~v77rI~
//v77n:230430 ARM:SecurityExceptin for statDoc for //Axe/.. by "e //Axe". skip stat for //root/..//~v77nI~
//v77m:230429 ARM:try stat(fpath) by fstat(fd) for ufstat          //~v77mI~
//v77i:230427 ARM;opendir/readdir by fd(parcelFileDescriptor.detachFd)//~v77iI~
//v77h:230424 ARM;copy                                             //~v77hI~
//v77g:230424 ARM;rename                                           //~v77gI~
//v77f:230424 ARM;rmdir                                            //~v77fI~
//v77e:230424 ARM;try fd for opendir/readdir                       //~v77eI~
//v77d:230423 ARM;delete                                           //~v77cI~
//v77c:230422 ARM;mkdir                                            //~v77cI~
//v77b:230415 ARM;edit file                                        //~v77bI~
//v77a:230415 split ufile1l to ufiledoc                            //~v77aI~
//v779:230414 update v777,set uri at ulib fro shortpath            //~v779I~
//v777:230403 ARM;udirlistFD                                       //~v777I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>                                                //~v77aI~
//*******************************************************
#include <ulib.h>
#include <ulibarm.h>                                               //~v77bI~
#include <uque.h>                                                  //~v59nI~
#include <ufile.h>
#include <ufile1l.h>                                               //~0901R~
#include <ufiledoc.h>                                              //~v77aI~
#include <uerr.h>
#include <ufemsg.h>
#include <uparse.h>
#include <ustring.h>
#include <utrace.h>
#include <uunxsub.h>
#include <ualloc.h>                                                //~v50GI~
#include <ustring.h>                                               //~v6B5I~
#include <ulibarm.h>                                               //~v70bI~
#include <uftp.h>                                                  //~v77aI~
	#include <jnic2ju.h>                                           //~v777I~
	#include <jnia.h>                                              //~v77zI~
//*******************************************************
	static int SdirFD=-1;                                          //~v777I~
    #define CTR_MEMBERDATA  5 //name,size,modified,attr                //~vby4R~//~v777I~
    #define IDXDATA_NAME     0                                         //~vby4I~//~v777I~
    #define IDXDATA_SIZE     1                                         //~vby4I~//~v777I~
    #define IDXDATA_MODIFIED 2                                         //~vby4I~//~v777I~
    #define IDXDATA_ATTR     3                                         //~vby4I~//~v777I~
    #define IDXDATA_FLAGS    4                                         //~vby4I~//~v777I~
	int selectDocByName(int Popt,char *Pname,char *PstrUri);       //~v777R~
	static 	UQUEH  *Spqhsp;		//q of SHORTPATH in fcmd7                       //~vba2I~//~v779I~
//  char *SopenDocBuffer,*SopenDocPath;                            //~v77bR~
//  int SoptRC,SopenDocBufferLen,SopenDocBufferOffs;               //~v77bR~
//    FILE *SopenDocPrivateFH;                                     //~v77bR~
	static UQUEH  	Sdochq;		//q of DOC_HANDLE                  //~v77bR~
	static UQUEH  	SdochqRealpath;		//q of real fullpath for API>=30//~v77zI~
	static int Serr_udirlist;                                      //~v77dI~
	static int SctrCopyTemp;                                       //~vbyhI~
	#define MAX_COPYTEMP 10                                        //~vbyhR~
	static char* SfnmCopyTemp[MAX_COPYTEMP];                       //~vbyhI~
	static UCHAR ScdShared[_MAX_PATH];        //last is not '/'    //~v7ZZR~//~v77ZM~
	static UCHAR ScdSharedReal[_MAX_PATH];        //last is not '/'//~vc5rR~
//*******************************************************
	void setufstat(FILEFINDBUF3 *Ppffb3,PUDIRLIST Ppudl);          //~v777R~
	int showErrDoc(int Perr,char *Pfnm,int Prc);                   //~v777I~
	char *getShortpathUri(char *Pshortpath);                       //~v779R~
	int ufile_spcomp(PUQUEE Ppqe,PVOID Ppname);                    //~v777I~
	int ufile_spcompRealpath(PUQUEE Ppqe,PVOID Ppname);            //~v77zI~
	int callc2j_udirlistDoc(int Popt,char *PdirName,char *PstrUri,unsigned Pattr,PUDIRLIST*Pppudirlist,int *Pperr);//~v77eI~
	PDIRENT ufiledoc_readdir_native(DIR *Ppdirh);                  //~v77iR~
	int ufiledoc_closedir_native(DIR *Ppdirh);                     //~v77iI~
	char *getShortpathRoot(char *Pshortpath,char *Proot);          //~v77zI~
////*******************************************************        //~v77bR~
//void *pdh2handle(PDOC_HANDLE Pdh)                                //~v77bR~
//{                                                                //~v77bR~
//    unsigned long ul=(unsigned long)Pdh;                         //~v77bR~
//    ul|=DOCFH_SIGN;                                              //~v77bR~
//    UTRACEP("%s:pdh=%p,handle=%p\n",UTT,Pdh,ul);                 //~v77bR~
//    return (void*)ul;                                            //~v77bR~
//}                                                                //~v77bR~
////*******************************************************        //~v77bR~
//void *handle2pdh(void *Phandle)                                  //~v77bR~
//{                                                                //~v77bR~
//    unsigned long ul=(unsigned long)Phandle;                     //~v77bR~
//    ul&=~DOCFH_SIGN;                                             //~v77bR~
//    UTRACEP("%s:phandle=%p,pdh=%p\n",UTT,Phandle,ul);            //~v77bR~
//    return (void*)ul;                                            //~v77bR~
//}                                                                //~v77bR~
////*******************************************************        //~v77bR~
//PDOC_HANDLE *scanDocHandle(void *Phandle)                        //~v77bR~
//{                                                                //~v77bR~
//    if (!Phandle)                                                //~v77bR~
//        return 0;                                                //~v77bR~
//    PDOC_HANDLE pdh=handle2pdh(Phandle);                         //~v77bR~
//    UTRACEP("%s:handle=%p,pdh=%p\n",UTT,Phandle,pdh);            //~v77bR~
//    return pdh;                                                  //~v77bR~
//}                                                                //~v77bR~
//*******************************************************          //~v77bI~
void freeDocHandle(void *Pdh)                                      //~v77bI~
{                                                                  //~v77bI~
	UTRACEP("%s:pdh=%p\n",UTT,Pdh);                                //~v77bI~
	if (!Pdh)                                                      //~v77bI~
    	return;                                                    //~v77bI~
    PDOC_HANDLE pdh=(PDOC_HANDLE)Pdh;                               //~v77bI~
    UFREEIFNZ(pdh->buffer);                              //~v77bR~
    pdh->buffer=0;                                       //~v77bI~
    UFREEIFNZ(pdh->pde);                                           //~v77dI~
    pdh->pde=0;                                                    //~v77dI~
//  UFREEIFNZ(pdh->fpath);                                         //~v77bR~
//  UFREEIFNZ(pdh); keep accessible after close                    //~v77bI~
}                                                                  //~v77bI~
//*******************************************************          //~v77bI~
PDOC_HANDLE enqDocHandle(int PoptRC,char *Pbuffer,int PbufferLen,char *Pfpath,char *PstrUri,FILE* PprivateFH)//~v77bR~//~v77dR~
{                                                                  //~v77bI~
    PDOC_HANDLE pdh;                                               //~v77bI~
//**************                                                   //~v77bI~
	pdh=ucalloc(1,DOC_HANDLESZ);                                   //~v77bI~
 // pdh->handle=pdh2handle(pdh);                                   //~v77bR~
    strcpy(pdh->acronym,DOCH_ACRONYM);                             //~v77bI~
    pdh->optRC=PoptRC;                                             //~v77bI~
  if (PoptRC & ROPT_OPENDIRFD)	//          0x0100    //emulate DIRH(opendir/readdir:dirent),buff is udirlist//~v77iI~
  	pdh->pdir=(void*)(Pbuffer);                                    //~v77iR~
  else                                                             //~v77iI~
    pdh->buffer=Pbuffer;                       //~v77bR~           //~v77dR~
  if (PoptRC & ROPT_OPENDIRFD)	//          0x0100    //emulate DIRH(opendir/readdir:dirent),buff is udirlist//~v77eI~
    pdh->fd=PbufferLen;                                            //~v77eI~
  else                                                             //~v77eI~
    pdh->bufferLen=PbufferLen;//~v77bI~
    pdh->fpath=ustrdup(0,Pfpath,0);                                //~v77bR~
    pdh->strUri=ustrdup(0,PstrUri,0);                              //~v77bR~
    pdh->privateFH=PprivateFH;                                     //~v77bI~
//  if (PoptRC & (ROPT_OPENDIR|ROPT_OPENDIRFD))	//          0x0100    //emulate DIRH(opendir/readdir:dirent),buff is udirlist//~v77dI~//~v77eR~//~v77iR~
    if (PoptRC & (ROPT_OPENDIR))	//          0x0100    //emulate DIRH(opendir/readdir:dirent),buff is udirlist//~v77iI~
		pdh->pde=ucalloc(1,sizeof(DIRENT));                        //~v77dI~
	UENQ(UQUE_TOP,&Sdochq,pdh);                             //~5118R~//~v77bI~
	UTRACEP("%s:pdh=%p,optRC=0x%x,buff=%p,buffLen=%d,fd=%d,fpath=%s,strUri=%s,privateFH=%p\n",UTT,pdh,PoptRC,Pbuffer,pdh->bufferLen,pdh->fd,Pfpath,PstrUri,PprivateFH);//~v77bR~//~v77dR~//~v77eR~
    return pdh;                                                    //~v77bI~
}                                                                  //~v77bI~
//*******************************************************          //~v77zI~
PDOC_HANDLE enqDocHandleRealpath(int PoptRC,char *Pfpath,char *Prpath,char *PstrUri)//~v77zI~
{                                                                  //~v77zI~
    PDOC_HANDLE pdh;                                               //~v77zI~
    char root[256];                                                //~v77zI~
//**************                                                   //~v77zI~
	pdh=ucalloc(1,DOC_HANDLESZ);                                   //~v77zI~
    strcpy(pdh->acronym,DOCH_ACRONYM);                             //~v77zI~
    pdh->optRC=PoptRC;                                             //~v77zI~
	getShortpathRoot(Pfpath,root);                                  //~v77zI~
    pdh->fpath=ustrdup(0,root,0);                                  //~v77zI~
  if (PoptRC & ROPT_REALPATH29)                                    //~vc5rR~
    pdh->rpath29=ustrdup(0,Prpath,0);                              //~vc5rR~
  else                                                             //~vc5rR~
    pdh->rpath=ustrdup(0,Prpath,0);                                //~v77zI~
    pdh->strUri=ustrdup(0,PstrUri,0);                              //~v77zI~
	UENQ(UQUE_TOP,&SdochqRealpath,pdh);                            //~v77zI~
	UTRACEP("%s:pdh=%p,optRC=0x%x,fpath=%s,strUri=%s,rpath=%s,rpath29=%s\n",UTT,pdh,PoptRC,Pfpath,PstrUri,Prpath,pdh->rpath29);//~v77zR~//~vc5rR~
    return pdh;                                                    //~v77zI~
}                                                                  //~v77zI~
//*******************************************************          //~v77zI~
int ufile_isGrantedAllFiles()                                      //~v77zI~
{                                                                  //~v77zI~
	int rc=0;                                                      //~v77zI~
   	if (GarmApiLevel>=30) //android11                              //~v77zI~
		rc=(GaxeStatus & AXES_GRANT_ALLFILES)!=0;                  //~v77zR~
	UTRACEP("%s:rc=%d,apiLevel=%d\n",UTT,rc,GarmApiLevel);         //~v77zR~
    return rc;
}                                                                  //~v77zI~
//*******************************************************          //~vbyxI~
//*rc=1 if api<30 || ALLFILES                                      //~vbyxI~
//*******************************************************          //~vbyxI~
int ufile_isGrantedMemberAccess()                                  //~vbyxI~
{                                                                  //~vbyxI~
	int rc=1;                                                      //~vbyxI~
   	if (GarmApiLevel>=30) //android11                              //~vbyxI~
		rc=(GaxeStatus & AXES_GRANT_ALLFILES)!=0;                  //~vbyxI~
	UTRACEP("%s:rc=%d,apiLevel=%d\n",UTT,rc,GarmApiLevel);         //~vbyxI~
    return rc;                                                     //~vbyxI~
}                                                                  //~vbyxI~
//*******************************************************          //~vc5rR~
//*get realpath                                                    //~vc5rR~
//*rc=0:success                                                    //~vbyxI~
//*******************************************************          //~vc5rR~
int ufile_getRealpath29(char *Pshortpath,char *Prpath,char *PstrUri)//~vc5rR~
{                                                                  //~vc5rR~
	PDOC_HANDLE pdh;                                               //~vc5rR~
    char root[_MAX_PATH],*rpath;                                         //~vc5rR~//~vbyxR~
    int rc=4;                                                      //~vc5rR~
//******************                                               //~vc5rR~
	UTRACEP("%s:shortpath=%s,strUri=%s,api=%d\n",UTT,Pshortpath,PstrUri,GarmApiLevel);//~vc5rR~
    *Prpath=0;                                                     //~vc5rR~
	getShortpathRoot(Pshortpath,root);                             //~vc5rR~
    pdh = uqscan(UQUE_TOP, &SdochqRealpath,ufile_spcompRealpath,root);   //search by root prefix//~vc5rR~
    if (pdh)                                                       //~vc5rR~
    {                                                              //~vc5rR~
        rpath=pdh->rpath29;                                        //~vc5rR~
        if (rpath)                                                 //~vc5rR~
        {                                                          //~vc5rR~
	        strcpy(Prpath,rpath);                                  //~vc5rR~
        	rc=0;                                                  //~vc5rR~
        }                                                          //~vc5rR~
    }                                                              //~vc5rR~
	UTRACEP("%s:rc=%d,shortpath=%s,realpath=%s\n",UTT,rc,Pshortpath,Prpath);//~vc5rR~
    return rc;                                                     //~vc5rR~
}                                                                  //~vc5rR~
//*******************************************************          //~v77zI~
//*get realpath                                                    //~v77zI~
//*******************************************************          //~v77zI~
int ufile_getRealpath(char *Pshortpath,char *Prpath,char *PstrUri) //~v77zR~
{                                                                  //~v77zI~
	char *rpath=0;                                                 //~v77zI~
	PDOC_HANDLE pdh;                                                //~v77zI~
    char root[256];                                                //~v77zI~
    char *strUri;                                                  //~v77zI~
    int rc;                                                        //~v77zI~
//******************                                               //~v77zI~
	UTRACEP("%s:shortpath=%s,api=%d\n",UTT,Pshortpath,GarmApiLevel);//~v77zI~
    *Prpath=0;                                                     //~v77ZI~
   	if (GarmApiLevel<30) //android11                               //~v77zR~
    {                                                              //~v77ZI~
//  	return 0;                                               //~v77zI~//~vc5rR~
		if (!ufile_getRealpath29(Pshortpath,Prpath,PstrUri))       //~vc5rR~
        	return 0;                                              //~vc5rR~
    }                                                              //~v77ZI~
//  if (!ufile_isGrantedAllFiles())                                //~v77zI~//~v77wR~
//  	return 0;                                                  //~v77zI~//~v77wR~
	getShortpathRoot(Pshortpath,root);                              //~v77zI~
    pdh = uqscan(UQUE_TOP, &SdochqRealpath,ufile_spcompRealpath,root);   //search by root prefix//~v77zR~
    if (pdh)                                                       //~v77zR~
    {                                                              //~v77zI~
        rpath=pdh->rpath;                                          //~v77zR~
        strcpy(Prpath,rpath);                                      //~v77zI~
		UTRACEP("%s:after uqscan realpath=%s,rc=%d\n",UTT,rpath);  //~v77zI~
        rc=0;                                                      //~v77zI~
    }                                                              //~v77zI~
    else                                                           //~v77zI~
    {                                                              //~v77zI~
    	if (PstrUri)                                               //~v77zI~
        	strUri=PstrUri;                                         //~v77zI~
        else                                                       //~v77zI~
			strUri=getShortpathUri(root);                    //~v77zI~
        if (strUri==0)                                             //~v77zI~
        	return 0;                                              //~v77zI~
		rc=c2j_getDocPath(0,root,strUri,Prpath);                   //~v77zI~
		UTRACEP("%s:after c2j_getDocPath path=%s,rc=%d\n",UTT,Prpath,rc);//~v77zI~
      if (rc==ROPT_REALPATH29)	//api<30; assumed //sp is on /sdcard/sp//~vc5rR~
      {                                                            //~vc5rR~
		enqDocHandleRealpath(ROPT_REALPATH29,root,Prpath,strUri);  //~vc5rR~
        rc=0;                                                      //+vbyxI~
      }                                                            //~vc5rR~
      else                                                         //~vc5rR~
      if (!rc)                                                     //~v77wI~
      {                                                            //~v77wI~
		enqDocHandleRealpath(0,root,Prpath,strUri);                //~v77zI~
        if (!ufile_isGrantedAllFiles())                            //~v77wI~
        	uerrmsg("Warning: Permission-AllFiles is currently OFF",//~v77wI~
        			"警告：すべてのファイルのアクセスは現在不許可の設定です");//~v77wI~
    	return 0;                                                  //~v77wI~
      }                                                            //~v77wI~
    }                                                              //~v77zI~
	UTRACEP("%s:rc=%d,shortpath=%s,realpath=%s\n",UTT,rc,Pshortpath,Prpath);//~v77zR~
    return rc;                                                     //~v77zI~
}                                                                  //~v77zI~
//*******************************************************          //~v77ZI~
//*get realpath                                                    //~v77ZI~
//*for utime and set PWD for tools                                 //~vc5rR~
//*******************************************************          //~v77ZI~
int ufile_getRealFullpath(char *Pfnm,char *Prpath)                 //~v77ZI~
{                                                                  //~v77ZI~
    char root[_MAX_PATH],*dirname,*strUri;                         //~v77ZI~
    int rc=4;                                                      //~v77ZI~
//******************                                               //~v77ZI~
	UTRACEP("%s:shortpath=%s,api=%d\n",UTT,Pfnm,GarmApiLevel);     //~v77ZI~
    *Prpath=0;                                                     //~v77ZI~
	strUri=getShortpathUri(Pfnm);                                  //~v77ZM~
    ufile_getRealpath(Pfnm,root,strUri);                          //~v77ZI~
    if (*root)                                                     //~v77ZI~
    {                                                              //~v77ZI~
    	dirname=strchr(Pfnm+PREFIX_ARM_SHARE_LEN,'/');             //~v77ZR~
    	if (dirname)                                               //~v77ZI~
	    	sprintf(Prpath,"%s%s",root,dirname);                   //~v77ZI~
    	else                                                       //~v77ZI~
	    	strcpy(Prpath,root);                                   //~v77ZI~
        rc=0;                                                      //~v77ZI~
    }                                                              //~v77ZI~
	UTRACEP("%s:rc=%d,realpath=%s\n",UTT,rc,Prpath);               //~v77ZI~
    return rc;                                                     //~v77ZI~
}                                                                  //~v77ZI~
//**************************************************************** //~v77zI~
int ufile_spcompRealpath(PUQUEE Ppqe,PVOID Ppname)                 //~v77zI~
{                                                                  //~v77zI~
    PDOC_HANDLE pdh;                                                //~v77zI~
    char *pname;                                                   //~v77zI~
//**********************************                               //~v77zI~
    pdh=(PDOC_HANDLE)Ppqe;                                          //~v77zI~
    pname=(char *)Ppname;                                          //~v77zI~
	return strcmp(pdh->fpath,pname)!=0;                            //~v77zI~
}//ufile_spcomp                                                    //~v77zI~
//*******************************************************          //~v77rI~
int errinvalispname(char *Pfpath,int rc)                           //~v77rI~
{                                                                  //~v77rI~
	uerrmsg("Invalis shortpath name(%s), chk it by \"SP edit\" cmd, or try \"SP refresh\".",//~v77rI~//~vbyhR~
	        "ショートパス指定の誤り(%s), \"SP edit\" コマンドで確認してください。\"SP refresh\"も試してください。 ",//~v77rI~//~vbyhR~
            Pfpath);                                               //~v77rI~
    return rc;                                                     //~v77rI~
}                                                                  //~v77rI~
//*******************************************************          //~v77bI~
int call_c2j_fcloseDoc(PDOC_HANDLE Ppdh)                          //~v77bI~
{                                                                  //~v77bI~
	int rc;                                                        //~v77bI~
//*************	                                                   //~v77bI~
    rc=c2j_fcloseDoc(Ppdh->optRC,Ppdh->fpath);                     //~v77bI~
    UTRACEP("%s:returned c2j_closeDoc fpath=%s,rc=%d\n",UTT,Ppdh->fpath,rc);//~v77bI~
    return rc;                                                     //~v77bI~
}                                                                  //~v77bI~
//*******************************************************          //~v77bI~
int ufile_closeDoc(void *Phandle)                                  //~v77bR~
{                                                                  //~v77bI~
    PDOC_HANDLE pdh;                                               //~v77bI~
    int rc=0;                                                      //~v77bI~
//**************                                                   //~v77bI~
	UTRACEP("%s:handle=%p\n",UTT,Phandle);                         //~v77bR~
    pdh=(PDOC_HANDLE)(Phandle);                                       //~v77bI~
    if (UGETQHDR(pdh)) //confirm enqed for i/o err etc         //~v04dI~//~v77bI~
		UDEQ(UQUE_ENT,0,pdh);                                     //~v78cR~//~v77bI~
    rc=call_c2j_fcloseDoc(pdh);                                    //~v77bI~
    if (pdh->privateFH)                                            //~v77bI~
    	rc=fclose(pdh->privateFH);                                 //~v77bR~
    pdh->swClosed=1;                                               //~v77bM~
    freeDocHandle(pdh);	//dont free structure itself;          //~v77bI~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v77bI~
    return rc;                                                     //~v77bI~
}                                                                  //~v77bI~
int ufile_closeDocDir(void *Phandle)                              //~v77dI~//~v77iR~
{                                                                  //~v77dI~
    PDOC_HANDLE pdh;                                               //~v77dI~
    int rc=0;                                                      //~v77dI~
//**************                                                   //~v77dI~
	UTRACEP("%s:handle=%p\n",UTT,Phandle);                         //~v77dI~
    pdh=(PDOC_HANDLE)(Phandle);                                    //~v77dI~
    if (UGETQHDR(pdh)) //confirm enqed for i/o err etc             //~v77dI~
		UDEQ(UQUE_ENT,0,pdh);                                      //~v77dI~
    if (pdh->optRC & ROPT_OPENDIRFD)	//          0x0100    //emulate DIRH(opendir/readdir:dirent),buff is udirlist//~v77iI~
		ufiledoc_closedir_native((DIR*)(pdh->pdir));               //~v77iR~
//  rc=call_c2j_fcloseDoc(pdh);                                    //~v77dI~
//  if (pdh->privateFH)                                            //~v77dI~
//  	rc=fclose(pdh->privateFH);                                 //~v77dI~
    pdh->swClosed=1;                                               //~v77dI~
    freeDocHandle(pdh);	//dont free structure itself;              //~v77dI~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v77dI~
    return rc;                                                     //~v77dI~
}                                                                  //~v77dI~
//*******************************************************          //~v777I~
unsigned int callc2j_ufstatDoc(char* PshortPath,char *PstrUri,int Ppathlen,int PswWildcard,FILEFINDBUF3 *Ppffb3)//~v777R~
{                                                                  //~v777I~
	int rc,opt;                                                    //~v777R~
    PUDIRLIST pudl;                                                //~v777I~
//*********************************                                //~v777I~
	UTRACEP("%s:shortPath=%s,strUri=%s,pathlen=%d,swWildcard=%d\n",UTT,PshortPath,PstrUri,Ppathlen,PswWildcard);//~v777R~
    memset(Ppffb3,0,sizeof(FILEFINDBUF3));                         //~v777R~
    opt=C2JUFSO_UFSTAT;                                            //~v777I~
    if (PswWildcard)                                               //~v777I~
    	opt|=C2JUFSO_WILDCARD;                                     //~v777I~
    rc=c2j_ufstatDoc(opt,PshortPath,PstrUri,Ppathlen,&pudl);       //~v777R~
	UTRACEP("%s:c2j returned rc=%d\n",UTT,rc);                     //~v777R~
	UTRACED("ufstatDoc udirlist",pudl,UDIRLISTSZ);                           //~v777I~//~v77dR~
    if (rc)                                                        //~v777I~
    {                                                              //~v777I~
//  	rc=showErrDoc(rc,PshortPath,rc);	//0 if empty           //~v777R~//~v77eR~
//      if (rc)                                                    //~v777I~//~v77eR~
        	return rc;                                             //~v777I~
    }                                                              //~v777I~
	setufstat(Ppffb3,pudl);                                         //~v777R~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v777I~
    return 0;                                                      //~v777I~
}//callc2j_ufstatDoc                                               //~v777R~
//******************************************************************//~v77eI~
//unsigned int ufstatDoc(char *Ppfile,FILEFINDBUF3 *Ppffb3)          //~v777I~//~v77eR~
//called with !PswFindFirst is 0 only                              //~v77ZI~
//*******************************************************************//~v77ZI~
unsigned int ufstatDoc(char *Ppfile,FILEFINDBUF3 *Ppffb3,int PswFindFirst)//~v77eI~
{                                                                  //~v777I~
    FILEFINDBUF3 ft,*pft;                                               //~v777I~
//  int pathlen,rc,lenShortpath;                                                //~v777I~//~v779R~
    int pathlen,rc;                                                //~v779I~
//  char shortPath[_MAX_PATH];                                     //~v777I~//~v779R~
    int swWildname;                                                //~v777I~//~v77eR~
    char *pstrUri;                                                 //~v777I~
    int err;                                                       //~v77eR~
    PUDIRLIST pudl;                                                //~v77eI~
//*********************************                                //~v777I~
	UTRACEP("%s:Ppfile=%s,swFindFirst=%d\n",UTT,Ppfile,PswFindFirst);                          //~v777I~//~v77eR~
    if (!(pft=Ppffb3))  //optional parm                            //~v777I~
        pft=&ft;                        //use internal work        //~v777I~
//  lenShortpath=parseDocPath(Ppfile/* //alias:struri */,shortPath,&pstrUri);//~v779R~
//  if (lenShortpath<=0)                                           //~v779R~
//  	return -1;                                                 //~v779R~
  	pstrUri=getShortpathUri(Ppfile);                               //~v779R~
    if (!pstrUri)                                                  //~v779R~
    {                                                              //~v779I~
    	return ERROR_PATH_NOT_FOUND;                               //~v779R~
    }                                                              //~v779I~
//  pathlen=upathlenDoc(0,pstrUri,0/*outRootpathlen*/,0/*output swRoot*/,0/*output prefixlen*/,0/*Palias*/);//~v777R~//~v77eR~
//  if (pathlen<0)    //no / found(not fullpath name)              //~v777R~//~v77eR~
//      pathlen=0;                                                 //~v777R~//~v77eR~
//  swWildname=WILDCARD(pstrUri+pathlen)!=NULL;                    //~v777R~//~v77eR~
    pathlen=PATHLEN(Ppfile);                                       //~v77eI~
    if (pathlen<0)    //no / found(not fullpath name)              //~v77eI~
        pathlen=0;                                                 //~v77eI~
    swWildname=WILDCARD(Ppfile+pathlen)!=NULL;                     //~v77eI~
    if (PswFindFirst && swWildname)                                //~v77eI~
    {                                                              //~v77eI~
		UTRACEP("%s:call dirlist by wildcard Ppfile=%s\n",UTT,Ppfile);//~v77eI~
		callc2j_udirlistDoc(0,Ppfile,pstrUri,FILE_ALL,&pudl,&err); //~v77eI~
        if (!err)                                                  //~v77eI~
        {                                                          //~v77eI~
			setufstat(Ppffb3,pudl);                                //~v77eI~
        	if (pudl)                                              //~v77eI~
        		ufree(pudl);                                       //~v77eI~
        }                                                          //~v77eI~
        return err;                                                //~v77eI~
    }                                                              //~v77eI~
//  rc=callc2j_ufstatDoc(shortPath,pstrUri,pathlen,swwildname,pft);//~v777R~
    rc=callc2j_ufstatDoc(Ppfile,pstrUri,pathlen,swWildname,pft);   //~v777I~
    if (rc)                                                        //~v777R~
    {                                                              //~v777I~
        if(rc!=ENOENT && rc!=ENOTDIR) //not found or no more file  //~v777R~
            return (unsigned)ufileapierr("lstat",Ppfile,rc);       //~v777R~
        return (unsigned)rc;                                       //~v777I~
    }                                                              //~v777I~
    return 0;                                                      //~v777I~
}//ufstatDoc                                                       //~v777I~
//**********************************************************************//~v77mI~
int ufile_statDoc(char *Pfpath,void *Ppstatbuff)                   //~v77mR~
{                                                                  //~v77mI~
    char *strUri;                                                  //~v77mI~
    int rc=0;                                                  //~v77mI~
	int err;                                             //~v77mI~
	struct stat *pstatbuff;                                        //~v77mI~
 //***********************                                          //~v77mI~
	UTRACEP("%s:fpath=%s\n",UTT,Pfpath);                           //~v77mI~
	pstatbuff=(struct stat*)Ppstatbuff;                            //~v77mI~
	strUri=getShortpathUri(Pfpath);                                //~v77mI~
    if (!strUri)                                                   //~v77mI~
    {                                                              //~v77mI~
	    UTRACEP("%s:invalid name fpath=%s\n",UTT,Pfpath);          //~v77mI~
        errno=errinvalispname(Pfpath,EINVAL);                      //~v77rI~
    	return -1;                                                 //~v77mI~
    }                                                              //~v77mI~
    int fd;                                                        //~v77mI~
    errno=0;                                                       //~v77mI~
	err=c2j_statDoc(0,Pfpath,strUri,&fd);                          //~v77mI~
    if (!err)                                                      //~v77mI~
    {                                                              //~v77mI~
		UTRACEP("%s:before fstat fd=%d,fpath=%s\n",UTT,fd,Pfpath); //~v77mI~
        errno=0;                                                   //~v77mI~
		rc=fstat(fd,pstatbuff);                                    //~v77mR~
        if (rc)                                                    //~v77mI~
        	err=errno;                                             //~v77mI~
		UTRACEP("%s:after fstat errno=%d,fd=%d,fpath=%s\n",UTT,err,fd,Pfpath);//~v77mI~
		UTRACED("statbuff",Ppstatbuff,sizeof(struct stat));        //~v77mR~
    }                                                              //~v77mI~
    UTRACEP("%s:returned exit fpath=%s,err=%d\n",UTT,Pfpath,err);  //~v77mI~
    errno=err;                                                      //~v77mI~
    return err?-1:0;                                               //~v77mI~
}                                                                  //~v77mI~
//*******************************************************          //~v777I~
//*get udirlis by dirFD; not used                                  //~v777R~
//******************************************************           //~v777I~
int udirlistFD(int Popt,char *Palias,char* Ppath,char *Pstruri,int PdirFD,unsigned Pattr,PUDIRLIST*Pppudirlist,int Psorttype)//~v777I~
{                                                                  //~v777I~
	int rc;                                                        //~v777I~
    char wkfnm[_MAX_PATH];                                         //~v777I~
//*********************                                            //~v777I~
	sprintf(wkfnm,"%s(%s)",Palias,Ppath);                          //~v777I~
	SdirFD=PdirFD;                                                 //~v777I~
	if (Popt & UDL_NOMSG)                                           //~v777R~
		rc=udirlistnomsg(wkfnm,Pattr,Pppudirlist,Psorttype);	//callback udosfindfirst/udosfindnext//~v777R~
    else                                                           //~v777I~
		rc=udirlist(wkfnm,Pattr,Pppudirlist,Psorttype);            //~v777R~
	SdirFD=-1;                                                     //~v777I~
    return rc;                                                     //~v777I~
}//udirlistFD                                                      //~v777I~
//******************************************************           //~v777I~
int callc2j_udirlistDoc(int Popt,char *PdirName,char *PstrUri,unsigned Pattr,PUDIRLIST*Pppudirlist,int *Pperr)//~v777R~
{                                                                  //~v777I~
	int ctr;                                                       //~v777I~
//**********************                                           //~v777I~
	UTRACEP("%s:opt=0x%x,dirName=%s,strUri=%s,attr=0x%x\n",UTT,Popt,PdirName,PstrUri,Pattr);//~v777R~
    ctr=c2j_udirlistDoc(Popt,PdirName,PstrUri,Pattr,Pppudirlist/*output of parseMemberData*/,Pperr);//~v777R~
    if (ctr>=0)                                                    //~v777R~
		UTRACED("udirlist",*Pppudirlist,(ctr+1)*UDIRLISTSZ);       //~v777R~
    return ctr;                                                    //~v777I~
}                                                                  //~v777I~
//*******************************************************          //~v777M~
int showErrDoc(int Perr,char *Pfnm,int Prc)                        //~v777R~
{                                                                  //~v777M~
	UTRACEP("%s:err=%d,fnm=%s\n",UTT,Perr,Pfnm);                   //~v777R~
    int rc=Prc;                                                    //~v777I~
    if (Perr==ENOENT)                                              //~v777I~
   		rc=ufilenotfound(Pfnm,rc);                                 //~v777R~
    else                                                           //~v777I~
    if (Perr==ERROR_PATH_NOT_FOUND)                                  //~v777I~
   		rc=ufilepatherr(Pfnm,rc);                                  //~v777R~
    else                                                           //~v777I~
    if (Perr==EPERM)                                               //~v777I~
   		rc=ufilenopermission("OpenDocument",Pfnm,rc);              //~v777R~
    else                                                           //~v777I~
    if (Perr==ENOTDIR)                                             //~v777I~
   		rc=ufilenotdir(Pfnm,rc);                                   //~v777R~
    else                                                           //~v777I~
    if (Perr==EINVAL)                                              //~v777I~
   		rc=ufileErrInvalidName(rc,Pfnm);                           //~v777R~
    else                                                           //~v777I~
    if (Perr==ERROR_NO_MORE_FILES)                                   //~v777R~
   		rc=ufileerrnoentry(Pfnm,0);                                //~v777R~
    else                                                           //~v777I~
    if (Perr==EINTR)                                               //~v777I~
   		rc=ufileapierr("DocumentProcess",Pfnm,rc);                 //~v777I~
    else                                                           //~v77bI~
    if (Perr==EISDIR)                                              //~v77bI~
   		rc=ufileerrdir(Pfnm,rc);                                   //~v77bI~
    else                                                           //~v777I~
   		rc=ufileapierr("JavaProcess",Pfnm,rc);                     //~v777I~
	UTRACEP("%s:rc%d,err=%d,fnm=%s\n",UTT,rc,Perr,Pfnm);           //~v777I~
    return rc;                                                     //~v777I~
}                                                                  //~v777I~
//*******************************************************          //~v777I~
int udirlistDoc(int Popt,char *Pfpath,unsigned Pattr,PUDIRLIST*Pppudirlist,int PsortType)//~v777I~
{                                                                  //~v777I~
//	int ctr,lenalias;                                              //~v777R~
  	int ctr;                                                       //~v777I~
    PUDIRLIST pudl;                                                //~v777I~
//  char dirName[_MAX_PATH];                                       //~v777R~
    char *dirName;                                                 //~v777I~
    char *pstrUri;                                                 //~v777I~
    int err;                                                       //~v777I~
//*********************                                            //~v777M~
	UTRACEP("%s:fpath=%s,att=0x%x,sortType=%c\n",UTT,Pfpath,Pattr,PsortType);//~v777R~
    Serr_udirlist=0;                                               //~v77dI~
//	lenalias=parseDocPath(Pfpath,dirName,&pstrUri);                //~v779R~
//  if (lenalias<=0)                                               //~v779R~
//    	return -1;                                                 //~v779R~
	dirName=Pfpath;                                                //~v779R~
  	pstrUri=getShortpathUri(dirName);                              //~v779R~
    if (!pstrUri)                                                  //~v779R~
    {                                                              //~v779I~
    	err=showErrDoc(ERROR_PATH_NOT_FOUND,dirName,-1);           //~v779I~
    }                                                              //~v779I~
    *Pppudirlist=0;                                                //~v779R~
	ctr=callc2j_udirlistDoc(Popt,dirName,pstrUri,Pattr,&pudl,&err);//~v777R~
    if (err)                                                       //~v777I~
    {                                                              //~v777I~
    	err=showErrDoc(err,dirName,-1);                            //~v777R~
        Serr_udirlist=err;                                         //~v77dI~
        if (err)                                                   //~v777I~
        	return -1;                                             //~v777I~
    }                                                              //~v777I~
    if (ctr)                                                       //~v777R~
      if (PsortType)                                               //~v77dI~
		udirlistsort(PsortType,pudl,ctr);                          //~v777R~
	*Pppudirlist=pudl;                                             //~v777I~
	UTRACED("pudirlist",pudl,UDIRLISTSZ*ctr);                      //~v777I~
	UTRACEP("%s:exit rc=ctr=%d\n",UTT,ctr);                        //~v777M~
    return ctr;                                                    //~v777R~
}//udirlistDoc                                                     //~v777M~
//**************************************************************** //~vby4I~//~v777M~
void settimeudirlist(PUDIRLIST Ppudirlist,char *Pmodified)          //~vby4I~//~v777R~
{                                                                  //~vby4I~//~v777M~
	long ts=atol(Pmodified)/1000; //unit:seconds                   //~vby4R~//~v777M~
    Ppudirlist->mtime=ts;                                          //~vby4I~//~v777M~
    ufilegetftime(&(Ppudirlist->time),&(Ppudirlist->date),ts);     //~vby4I~//~v777M~
	UTRACEP("%s:mtime=%ld,fdate=0x%x,ftime=0x%x\n",UTT,Ppudirlist->mtime,Ppudirlist->date,Ppudirlist->time);//~vby4R~//~v777M~
}                                                                  //~vby4I~//~v777M~
                                                                 //~v777I~
//**************************************************************** //~vby4I~//~v777M~
//*rc;ctr list                                                     //~vby4I~//~v777M~
//**************************************************************** //~vby4I~//~v777M~
void setudirlist(PUDIRLIST Ppudirlist,char **Ppdata,int *PlenData)  //~vby4I~//~v777R~
{                                                                  //~vby4I~//~v777M~
	char *pname,*psize,*pmod,*pattr,*pflags;                               //~vby4I~//~v777M~
    pname=Ppdata[IDXDATA_NAME];                                   //~vby4I~//~v777M~
    psize=Ppdata[IDXDATA_SIZE];                                   //~vby4I~//~v777M~
    pmod=Ppdata[IDXDATA_MODIFIED];                                //~vby4I~//~v777M~
    pattr=Ppdata[IDXDATA_ATTR];                                   //~vby4I~//~v777M~
    pflags=Ppdata[IDXDATA_FLAGS];                                  //~vby4I~//~v777M~
	UTRACEP("%s:setudirlist name=%s,size=%s,mod=%s,attr=%s,flags=%s\n",UTT,pname,psize,pmod,pattr,pflags);//~vby4R~//~v777M~
	udirlist_setname(0,Ppudirlist,pname,(size_t)PlenData[IDXDATA_NAME]);//~vby4I~//~v777M~
	Ppudirlist->size=atol(psize);                                  //~vby4I~//~v777M~
	settimeudirlist(Ppudirlist,pmod);	//time_t,FDATE & FTIME     //~vby4I~//~v777M~
	Ppudirlist->attr=atoi(pattr);                                  //~vby4I~//~v777M~
	Ppudirlist->docFlags=atoi(pflags);                              //~vby4I~//~v777M~
	Ppudirlist->otherflag|=UDLOF_ARMDOC;		//             0x0020     //*share document file//~vby4I~//~v777M~
	UTRACEP("%s:setudirlist name=%s,size=%ld,Fdate=0x%x,Ftime=0x%x,attr=0x%x,docFlags=0x%x\n",UTT,Ppudirlist->name,Ppudirlist->size,Ppudirlist->date,Ppudirlist->time,Ppudirlist->attr,Ppudirlist->docFlags);//~vby4R~//~v777M~
	UTRACED("udirlist",Ppudirlist,UDIRLISTSZ);                     //~v777R~
}                                                                  //~vby4I~//~v777M~
//**************************************************************** //~v777I~
void setufstat(FILEFINDBUF3 *Ppffb3,PUDIRLIST Ppudl)                //~v777R~
{                                                                  //~v777I~
	UTRACED("setufstat Ppudl",Ppudl,UDIRLISTSZ);                   //~v777I~
	strcpy(Ppffb3->achName,Ppudl->name);                            //~v777R~
	Ppffb3->cbFile=Ppudl->size;                                     //~v777R~
	Ppffb3->fdateLastWrite=Ppudl->date;                             //~v777I~
	Ppffb3->ftimeLastWrite=Ppudl->time;                             //~v777I~
	Ppffb3->mtime=Ppudl->mtime;                                     //~v777R~
	Ppffb3->attrFile=Ppudl->attr;                                  //~v777R~
	Ppffb3->docFlags=Ppudl->docFlags;                              //~v777R~
	Ppffb3->otherflag=Ppudl->otherflag;		//             0x0020     //*share document file//~v777R~
	UTRACEP("%s:setufstat name=%s,size=%ld,Fdate=0x%x,Ftime=0x%x,attr=0x%x,docFlags=0x%x\n",UTT,Ppffb3->achName,Ppffb3->cbFile,Ppffb3->fdateLastWrite,Ppffb3->ftimeLastWrite,Ppffb3->attrFile,Ppffb3->docFlags);//~v777I~
}                                                                  //~v777I~
//**************************************************************** //~vby4I~//~v777M~
//*callback from c2j_udirlistDoc, set udirlist                     //~vby4I~//~v777R~
//**************************************************************** //~vby4I~//~v777M~
int parseMemberData(char *PmemberData,int PlenData,int Popt,char *PnameDir,char *PstrUri,unsigned Pattr,UDIRLIST **Pppudirlist)//~vby4R~//~v777R~
{                                                                  //~vby4I~//~v777M~
    PUDIRLIST pudirlist,pudirlist0;                                           //~vby4I~//~v777M~
    int len,ctrList=0,swErr=0,reslen,ii,ctrSelected=0;                           //~vby4R~//~v777R~
    char *pc,*pc2,*pdata[CTR_MEMBERDATA];                          //~vby4I~//~v777M~
    int lendata[CTR_MEMBERDATA];                                  //~vby4I~//~v777M~
//****************************                                     //~vby4I~//~v777M~
	UTRACEP("%s:PnameDir=%s,attr=0x%x\n",UTT,PnameDir,Pattr);               //~vby4R~//~v777R~
	UTRACED("parseMemberdata",PmemberData,PlenData);               //~v777I~
    for (pc=PmemberData,reslen=PlenData;reslen>0;)                 //~vby4R~//~v777M~
    {                                                              //~vby4I~//~v777M~
    	for (ii=0;ii<CTR_MEMBERDATA;ii++)	//name,size,modified,attr//~vby4R~//~v777M~
        {                                                          //~vby4I~//~v777M~
    		if (!reslen)                                           //~vby4I~//~v777M~
        		break;                                             //~vby4I~//~v777M~
    		pc2=memchr(pc,',',reslen);                            //~vby4I~//~v777M~
        	if (!pc2)                                              //~vby4R~//~v777M~
        		break;                                             //~vby4I~//~v777M~
			UTRACEP("%s:ii=%d,pc=%s,pc2=%s\n",UTT,ii,pc,pc2);      //~vby4I~//~v777M~
            pdata[ii]=pc;                                          //~vby4I~//~v777M~
            len=PTRDIFF(pc2,pc);                                   //~vby4I~//~v777M~
            lendata[ii]=len;                                       //~vby4I~//~v777M~
            reslen-=len+1;                                         //~vby4I~//~v777M~
            pc=pc2+1;                                              //~vby4I~//~v777M~
        }                                                          //~vby4I~//~v777M~
    	if (ii!=CTR_MEMBERDATA)	//name,size,modified,attr          //~vby4I~//~v777M~
        {                                                          //~vby4I~//~v777M~
			UTRACEP("%s:err by data ctr =%d is not multiple of %d,\n",UTT,ii,CTR_MEMBERDATA);//~vby4R~//~v777M~
        	swErr=1;                                               //~vby4I~//~v777M~
        	break;                                                 //~vby4I~//~v777M~
        }                                                          //~vby4I~//~v777M~
        ctrList++;                                                 //~vby4I~//~v777M~
    }                                                              //~vby4I~//~v777M~
	UTRACEP("%s:ctrList=%d,swErr=%d\n",UTT,ctrList,swErr);                 //~vby4I~//~v777M~
    if (swErr)                                                     //~vby4I~//~v777M~
    	return -1;                                                 //~vby4I~//~v777M~
    pudirlist0=ucalloc(ctrList+1,UDIRLISTSZ);                      //~vby4I~//~v777M~
    pudirlist=pudirlist0;                                          //~vby4I~//~v777M~
                                                                   //~v777I~
    for (pc=PmemberData,reslen=PlenData;reslen>0;)                 //~vby4R~//~v777M~
    {                                                              //~vby4I~//~v777M~
    	for (ii=0;ii<CTR_MEMBERDATA;ii++)	//name,size,modified,attr//~vby4R~//~v777M~
        {                                                          //~vby4I~//~v777M~
    		if (!reslen)                                           //~vby4I~//~v777M~
        		break;                                             //~vby4I~//~v777M~
    		pc2=memchr(pc,',',reslen);                            //~vby4I~//~v777M~
        	if (!pc2)                                              //~vby4R~//~v777M~
        		break;                                             //~vby4I~//~v777M~
            pdata[ii]=pc;                                          //~vby4I~//~v777M~
            len=PTRDIFF(pc2,pc);                                   //~vby4I~//~v777M~
            lendata[ii]=len;                                       //~vby4I~//~v777M~
            reslen-=len+1;                                         //~vby4I~//~v777M~
            *pc2=0;		//strz                                     //~vby4I~//~v777M~
            pc=pc2+1;                                              //~vby4I~//~v777M~
        }                                                          //~vby4I~//~v777M~
    	if ((Popt & C2JUFSO_UFSTAT)==0)                            //~v777M~
	        if (selectDocByName(Popt,pdata[IDXDATA_NAME],PstrUri))       //~vby4I~//~v777R~
    	    	continue;                                              //~vby4I~//~v777M~
    	setudirlist(pudirlist,pdata,lendata);                      //~vby4R~//~v777M~
        pudirlist++;                                               //~vby4I~//~v777M~
        ctrSelected++;                                             //~v777I~
    }                                                              //~vby4I~//~v777M~
	UTRACEP("%s:ctrSelected=%d,ctrList=%d\n",UTT,ctrSelected,ctrList);//~v777I~
    if (ctrSelected<ctrList)                                       //~v777I~
    {                                                              //~v777I~
    	ctrList=ctrSelected;                                       //~v777I~
        memset(pudirlist0+ctrSelected,0,UDIRLISTSZ);	//keep stopper//~v777I~
    }                                                              //~v777I~
    if (swErr)                                                     //~vby4I~//~v777M~
    	ctrList=-1;                                                    //~vby4I~//~v777M~
	*Pppudirlist=pudirlist0;                                       //~v777I~
	UTRACEP("%s:exit rc=ctrList=%d\n",UTT,ctrList);                            //~vby4I~//~v777M~
	return ctrList;                                                     //~vby4I~//~v777M~
}                                                                  //~vby4I~//~v777M~
//**********************************************************************//~v777I~
int selectDocByName(int Popt,char *Pname,char *PstrUri)            //~v777R~
{                                                                  //~v777I~
	int rc=0,pathlen;                                              //~v777R~
//***********************                                          //~v777I~
	UTRACEP("%s:dirname=%s,strUri=%s,Pattr=0x%x,udirlist->name=%s\n",UTT,Pname,PstrUri);//~v777R~
	pathlen=PATHLEN_DOC(PstrUri);                                  //~v777I~
    if (pathlen<0)                                                 //~v777R~
    	pathlen=0;                                                 //~v777I~
    if (WILDCARD(PstrUri+pathlen))  //opendir fail if wild card    //~v777R~
		if (!ufilelnxwildselect(Pname,PstrUri+pathlen,0/*mdossw*/)) //unmatch//~v777R~
        	rc=4;                                                  //~v777I~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v777I~
    return rc;                                                     //~v777I~
}//selectDocByName                                                 //~v777R~
//**********************************************************************//~v777I~
//* as full path, //alias:content://com.android.../tree/primary%3AAxe%2FAxesub//~v777I~
//*                                                            (:)   (/)//~v777I~
//**********************************************************************//~v777I~
int makeDocPath(char *Palias/* start by '//' */,char *PstrUri,char *Pfpath)//~v777R~
{                                                                  //~v777I~
//***********************                                          //~v777I~
	int len=sprintf(Pfpath,"%s%c%s",Palias,SEP_ARM_SHARE,PstrUri); //~v777R~
	UTRACEP("%s:alias=%s,strUri=%s,flath=%s\n",UTT,Palias,PstrUri,Pfpath);//~v777I~
    return len;                                                    //~v777R~
}//makeDocPath                                                     //~v777R~
//**********************************************************************//~v777I~
int parseDocPath(char *Pfpath/* //alias:struri */,char *Palias,char **PppstrUri)//~v777R~
{
    int offs;//~v777I~
//***********************                                          //~v777I~
	char *pc=strchr(Pfpath,SEP_ARM_SHARE); //":"                   //~v777R~
    if (pc)                                                        //~v777I~
    {                                                              //~v777I~
    	offs=PTRDIFF(pc,Pfpath);                                    //~v777I~
        pc++;	//strUri                                           //~v777I~
    }                                                              //~v777I~
    else                                                           //~v777I~
    	offs=-1;                                                   //~v777I~
    *PppstrUri=pc;                                                 //~v777I~
    if (Palias)                                                    //~v777I~
    	if (offs>0)                                                //~v777I~
        {                                                          //~v777I~
        	char *pc2;                                             //~v777I~
            pc2=ustrstri(Pfpath+offs,SEP_ARM_SHARE_PATH);   //"%3A"//~v777R~
            if (pc2)                                               //~v777I~
            {                                                      //~v777I~
	    		sprintf(Palias,"%s%s",PREFIX_ARM_SHARE,pc2+sizeof(SEP_ARM_SHARE_PATH)-1);//~v777R~
				UTRACEP("%s:alias=%s\n",UTT,Palias);               //~v777I~
            }                                                      //~v777I~
            else                                                   //~v777I~
            {                                                      //~v777I~
            	*Palias=0;                                         //~v777I~
				UTRACEP("%s:alias set failed by %s not found\n",UTT,SEP_ARM_SHARE_PATH);//~v777I~
            }                                                      //~v777I~
        }                                                          //~v777I~
	UTRACEP("%s:Pfpath=%s,struri=%s\n",UTT,Pfpath,pc);             //~v777R~
    return offs;                                                   //~v777I~
}//udirlistsub                                                     //~v777I~
//*******************************************************          //~v777I~
//*rootPathlen:up to end of first name after "%3A"(:) or ":"       //~v777R~
//*swRoot:1 if no subdir after root                                //~v777I~
//*rootPathlen:up to subdirname after "/" or "%2F"                 //~v777I~
//*******************************************************          //~v777I~
int upathlenDoc(int Popt,char *Pfilename,int *Pproot,int *PpswRoot,int *PplenPrefix,char *Palias)//~v777R~
{                                                                  //~v777I~
    char *pc1,*pc2,*pc3,*pc,*pc4;                                  //~v777R~
    int rc,rootPathlen,swRoot=0,lenPrefix;                         //~v777R~
//*********************************                                //~v777I~
  	pc1=ustrstri(Pfilename,SEP_ARM_SHARE_PATH);    //%3A           //~v777R~
  	pc2=strrchr(Pfilename,SEP_ARM_SHARE);            //":"         //~v777R~
    if (pc1)                                                       //~v777I~
    {                                                              //~v777I~
  		if (pc1>pc2)                                               //~v777I~
  			pc=pc1+sizeof(SEP_ARM_SHARE_PATH)-1;                   //~v777R~
        else                                                       //~v777I~
        	pc=pc2+1;                                              //~v777R~
    }                                                              //~v777I~
    else                                                           //~v777I~
    {                                                              //~v777I~
    	if (pc2)                                                   //~v777I~
	    	pc=pc2+1;                                              //~v777R~
        else                                                       //~v777I~
        	pc=0;                                                  //~v777I~
    }                                                              //~v777I~
    if (!pc)//shortpath fmt like //SP/subdir                       //~v777R~
    {                                                              //~v777I~
        pc=Pfilename+sizeof(PREFIX_ARM_SHARE)-1;                   //~v777I~
//    	pc3=strchr(pc,FTP_DIR_SEPC);               // "/"          //~v777I~//~v77aR~
      	pc3=strchr(pc,DIR_SEPC);               // "/"              //~v77aI~
        swRoot=pc3==0;                                             //~v777I~
        if (swRoot)                                                //~v777I~
        {                                                          //~v777I~
	        rootPathlen=(int)strlen(Pfilename);                    //~v777I~
            rc=rootPathlen;                                        //~v777I~
        }                                                          //~v777I~
        else                                                       //~v777I~
        {                                                          //~v777I~
	        rootPathlen=PTRDIFF(pc3,Pfilename)+1;                  //~v777I~
//	    	pc4=strrchr(pc3,FTP_DIR_SEPC);               // "/"    //~v777I~//~v77aR~
  	    	pc4=strrchr(pc3,DIR_SEPC);               // "/"        //~v77aI~
            rc=PTRDIFF(pc3,Pfilename)+1;                           //~v777I~
        }                                                          //~v777I~
    	if (Pproot)                                                //~v777I~
        	*Pproot=rootPathlen;                                   //~v777I~
    	if (PpswRoot)                                              //~v777I~
        	*PpswRoot=swRoot;                                      //~v777I~
    	if (PplenPrefix)                                           //~v777I~
        	*PplenPrefix=0;                                        //~v777I~
		UTRACEP("%s:shortPath pattern swRoot=%d,rootPathlen=%d,rc=pathlen=%d,fnm=%s,path=%s\n",UTT,swRoot,rootPathlen,rc,Pfilename,pc);//~v777I~
    }                                                              //~v777I~
    else                                                           //~v777I~
    {                                                              //~v777I~
    	lenPrefix=PTRDIFF(pc,Pfilename);                           //~v777I~
	  	pc4=ustrstri(pc,SEP_ARM_SHARE_PATH_SUBDIR);    //%2A       //~v777I~
        if (!pc4)                                                  //~v777I~
//    		pc4=strchr(pc,FTP_DIR_SEPC);                           //~v777R~//~v77aR~
      		pc4=strchr(pc,DIR_SEPC);                               //~v77aI~
        if (!pc4)                                                  //~v777I~
        {                                                          //~v777I~
        	rootPathlen=(int)strlen(Pfilename);                    //~v777I~
            swRoot=1;                                              //~v777I~
        }                                                          //~v777I~
        else                                                       //~v777I~
        {                                                          //~v777I~
//        	rootPathlen=PTRDIFF(pc4,Pfilename)+(*pc4==FTP_DIR_SEPC ? 1 : (int)sizeof(SEP_ARM_SHARE_PATH_SUBDIR)-1);//~v777R~//~v77aR~
          	rootPathlen=PTRDIFF(pc4,Pfilename)+(*pc4==DIR_SEPC ? 1 : (int)sizeof(SEP_ARM_SHARE_PATH_SUBDIR)-1);//~v77aI~
        }                                                          //~v777I~
    	if (Pproot)                                                //~v777M~
        	*Pproot=rootPathlen;                                   //~v777M~
    	if (PpswRoot)                                              //~v777M~
        	*PpswRoot=swRoot;                                      //~v777M~
    	if (PplenPrefix)                                           //~v777I~
        	*PplenPrefix=lenPrefix;                                //~v777I~
		UTRACEP("%s:rootPathlen=%d,swRoot=%d\n",UTT,rootPathlen,swRoot);//~v777R~
	  	pc3=ustrrstri(pc,SEP_ARM_SHARE_PATH_SUBDIR);    //%2A      //~v777I~
        if (!pc3)                                                  //~v777I~
//    		pc3=strrchr(pc,FTP_DIR_SEPC);               // "/"     //~v777I~//~v77aR~
      		pc3=strrchr(pc,DIR_SEPC);               // "/"         //~v77aI~
        if (pc3)                                                   //~v777I~
	    	rc=PTRDIFF(pc3,Pfilename)+1;                           //~v777R~
        else                                                       //~v777I~
	    	rc=PTRDIFF(pc,Pfilename);                              //~v777I~
        if (Palias)                                                //~v777I~
        {                                                          //~v777I~
//      	char *pc5;	                                           //~v777R~
//          pc5=strchr(Pfilename,SEP_ARM_SHARE);     //":"         //~v777R~
//          if (pc5)                                               //~v777R~
            {                                                      //~v777R~
//          	UmemcpyZ(Palias,Pfilename,PTRDIFF(pc5,Pfilename)); //~v777R~
            	sprintf(Palias,"%s%s",PREFIX_ARM_SHARE,pc);         //~v777I~
    			UTRACEP("%s:alias=%s\n",UTT,Palias);               //~v777R~
            }                                                      //~v777I~
        }                                                          //~v777I~
		UTRACEP("%s:subdir=%s\n",UTT,pc3);                         //~v777I~
    }                                                              //~v777I~
	UTRACEP("%s:pathlen=%d,fnm=%s,path=%s\n",UTT,rc,Pfilename,pc); //~v777R~
    return rc;                                                     //~v777I~
}//upathlenDoc                                                     //~v777I~
//*******************************************************          //~vc5cI~
void notifyallsp()                                                 //~vc5cI~
{                                                                  //~vc5cI~
	char allsp[4096];                                              //~vc5cI~
	PSHORTPATH psp;                                                //~vc5cI~
//***********************                                          //~vc5cI~
	UTRACEP("%s,qctr=%d\n",UTT,UGETQCTR(Spqhsp));                  //~vc5cR~
    *allsp=0;                                                      //~vc5cI~
    for (psp=UGETQTOP(Spqhsp);psp;psp=UGETQNEXT(psp))              //~vc5cR~
    {                                                              //~vc5cI~
		UTRACEP("%s,USPpname=%s\n",UTT,psp->USPpname);             //~vc5cI~
    	if (!memcmp(psp->USPpname,PREFIX_ARM_SHARE,PREFIX_ARM_SHARE_LEN))                 //~vbyeI~//~vc5cI~
        {                                                          //~vc5cI~
            if (*allsp)                                            //~vc5cI~
                strcat(allsp,", ");                                 //~vc5cI~
        	strcat(allsp,psp->USPpname);                           //~vc5cI~
        }                                                          //~vc5cI~
    }                                                              //~vc5cI~
    if (*allsp)                                                    //~vc5cI~
	    c2j_notifyAllSP(allsp);                                     //~vc5c6I~
}                                                                  //~vc5cI~
//*******************************************************          //~vc5cI~
//*from xefcmd7 at "sp add //"                                     //~vc5cI~
//*******************************************************          //~vc5cI~
void ufiledoc_notify_sp_changed()                                  //~vc5cI~
{                                                                  //~vc5cI~
	UTRACEP("%s\n",UTT);                                           //~vc5cI~
    notifyallsp();  //to USAF                                      //~vc5cI~
}                                                                  //~vc5cI~
//*******************************************************          //~vc5cI~
//*from xefcmd7                                                    //~vc5cI~
//*******************************************************          //~v779R~
void ufile_notify_shortpath(UQUEH  *Ppqhsp)                        //~v779R~
{                                                                  //~v779R~
	UTRACEP("%s:qhsp=%p\n",UTT,Ppqhsp);                            //~v779R~
	Spqhsp=Ppqhsp;                                                 //~v779R~
    notifyallsp();  //to USAF                                      //~vc5cI~
}                                                                  //~v779R~
//*******************************************************          //~v779R~
//*get top uri by alias part of fpath                              //~v77bI~
//*******************************************************          //~v77bI~
char *ufile_getShortpathUri(char *Pshortpath)                      //~v779R~
{                                                                  //~v779R~
	char *strUri=0;                                                //~v779R~
	PSHORTPATH psp;                                                //~v779R~
//******************                                               //~v779R~
    if (Spqhsp)                                                    //~v779R~
    {                                                              //~v779R~
    	psp = uqscan(UQUE_TOP, Spqhsp,ufile_spcomp,Pshortpath);   //search by root prefix//~v779R~
        if (psp)                                                   //~v779R~
	        strUri=psp->USPppath;                                  //~v779R~
    }                                                              //~v779R~
	UTRACEP("%s:shortpath=%s,uri=%s\n",UTT,Pshortpath,strUri);     //~v779R~
	return strUri;                                                 //~v779R~
}                                                                  //~v779R~
//**************************************************************** //~v779R~
int ufile_spcomp(PUQUEE Ppqe,PVOID Ppname)                         //~v779R~
{                                                                  //~v779R~
    PSHORTPATH psp;                                                //~v779R~
    char *pname;                                                   //~v779R~
//**********************************                               //~v779R~
    psp=(PSHORTPATH)Ppqe;                                          //~v779R~
    pname=(char *)Ppname;                                          //~v779R~
	return strcmp(psp->USPpname,pname)!=0;                         //~v779R~
}//ufile_spcomp                                                    //~v779R~
//**********************************************************************//~v77zI~
char *getShortpathRoot(char *Pshortpath,char *Proot)               //~v77zI~
{                                                                  //~v77zI~
    char *pc;                                 //~v77zI~
//***********************                                          //~v77zI~
	pc=strchr(Pshortpath+PREFIX_ARM_SHARE_LEN,DIR_SEPC);           //~v77zI~
    if (pc)                                                        //~v77zI~
    {                                                              //~v77zI~
    	UmemcpyZ(Proot,Pshortpath,PTRDIFF(pc,Pshortpath));         //~v77zI~
    }                                                              //~v77zI~
    else                                                           //~v77zI~
    	strcpy(Proot,Pshortpath);                                  //~v77zI~
	UTRACEP("%s:Pshortpath=%s,root=%s\n",UTT,Pshortpath,Proot);    //~v77zI~
	return Proot;                                                  //~v77zI~
}                                                                  //~v77zI~
//**********************************************************************//~v77zI~
int getShortpathRootLen(char *Pshortpath)                          //~v77zR~
{                                                                  //~v77zI~
    char *pc;                                                      //~v77zI~
    int len;                                                        //~v77zI~
//***********************                                          //~v77zI~
	pc=strchr(Pshortpath+PREFIX_ARM_SHARE_LEN,DIR_SEPC);           //~v77zI~
    if (pc)                                                        //~v77zI~
    {                                                              //~v77zI~
    	len=PTRDIFF(pc,Pshortpath);                                //~v77zI~
    }                                                              //~v77zI~
    else                                                           //~v77zI~
    	len=(int)strlen(Pshortpath);                               //~v77zI~
	UTRACEP("%s:Pshortpath=%s,len=%d\n",UTT,Pshortpath,len);       //~v77zI~
	return len;                                                    //~v77zI~
}                                                                  //~v77zI~
//**********************************************************************//~v777I~
char *getShortpathUri(char *Pshortpath)                            //~v779R~
{                                                                  //~v779R~
	char *strUri=0;                                                //~v779R~
    char *pc,shortpath[_MAX_PATH];                                 //~v779I~
//***********************                                          //~v779R~
	pc=strchr(Pshortpath+PREFIX_ARM_SHARE_LEN,DIR_SEPC);           //~v779I~
    if (pc)                                                        //~v779I~
    {                                                              //~v779I~
    	UmemcpyZ(shortpath,Pshortpath,PTRDIFF(pc,Pshortpath));     //~v779I~
        pc=shortpath;                                              //~v779I~
    }                                                              //~v779I~
    else                                                           //~v779I~
    	pc=Pshortpath;                                             //~v779I~
	strUri=ufile_getShortpathUri(pc);                              //~v779R~
    if (strUri)                                                    //~v779R~
    {                                                              //~v779R~
    	strUri=strchr(strUri,SEP_ARM_SHARE);	//":"              //~v779R~
        if (strUri)                                                //~v779I~
        	strUri++;	//skip ":"                                 //~v779I~
    }                                                              //~v779R~
	UTRACEP("%s:Pshortpath=%s,strUri=%s\n",UTT,Pshortpath,strUri); //~v779R~
    return strUri;                                                 //~v779R~
}//getShortpathUri                                                 //~v779R~
//**********************************************************************//~v77bI~
int ufile_openDoc(int Popt,char *Pfpath,char *Popenopt,FILE **Ppfh)//~v77bR~
{                                                                  //~v77bI~
	int opt=0,rc=0,bufflen;                                        //~v77bR~
    char *pbuff,*ptempDir,*pstrUri;                                //~v77bR~
    int  optRC;                                                    //~v77bR~
    char fpathTemp[_MAX_PATH];                                     //~v77bI~
    PDOC_HANDLE pdh;                                               //~v77bI~
//***********************                                          //~v77bI~
	UTRACEP("%s:opt=0x%x,fpath=%s,openOpt=%s\n",UTT,Popt,Pfpath,Popenopt);//~v77bR~
    *Ppfh=0;                                                       //~v77bI~
//  SoptRC=0;                                                      //~v77bI~
//  if (SopenDocBuffer)                                            //~v77bR~
//  	ufree(SopenDocBuffer);                                     //~v77bR~
//  SopenDocBuffer=0;                                              //~v77bR~
//  if (SopenDocPath)                                              //~v77bR~
//  	ufree(SopenDocPath);                                       //~v77bR~
//  SopenDocPath=0;                                                //~v77bR~
	pstrUri=getShortpathUri(Pfpath);                               //~v77bI~
    if (!pstrUri)                                                  //~v77bI~
		return ERROR_PATH_NOT_FOUND;                               //~v77bI~
    opt=Popt & ~(ROPT_BINARY|ROPT_INPUT|ROPT_APPEND);              //~v77bI~
    if (strchr(Popenopt,'b'))                                      //~v77bI~
    	opt|=ROPT_BINARY;                                          //~v77bI~
    if (strchr(Popenopt,'r'))                                      //~v77bI~
    	opt|=ROPT_INPUT;                                           //~v77bI~
    if (strchr(Popenopt,'a'))                                      //~v77bI~
    	opt|=ROPT_APPEND;                                          //~v77bI~
    if (opt & ROPT_INPUT)                                          //~v77bR~
    {                                                              //~v77bI~
        ptempDir=gettempnampath(0);                                //~v77bR~
	    sprintf(fpathTemp,"%s/%s",ptempDir,Pfpath+PATHLEN_DOC(Pfpath));//~v77bR~
    	rc=c2j_openDoc(opt,Pfpath,pstrUri,fpathTemp,&pbuff,&bufflen,&optRC);//~v77bR~
		UTRACEP("%s:returned c2j_openDoc rc=%d,fpath=%s,optrc=0x%x\n",UTT,rc,Pfpath,optRC);//~v77bI~
        if (rc)                                                    //~v77bI~
        	return rc;                                             //~v77bI~
//      SoptRC=optRC;                                              //~v77bR~
        if (optRC & ROPT_STRING)	//returned full content by buffer//~v77bR~
        {                                                          //~v77bI~
//      	SopenDocBuffer=pbuff;                                  //~v77bR~
//      	SopenDocBufferLen=bufflen;                             //~v77bR~
//      	SopenDocBufferOffs=0;                                  //~v77bR~
//          *Ppfh=(FILE*)(DOCFH_STRING);                           //~v77bR~
			pdh=enqDocHandle(optRC,pbuff,bufflen,Pfpath,pstrUri,0/*privateFILEH*/);//~v77bR~
			UTRACEP("%s:returned c2j_openDoc return buffer bufflen=%d\n",UTT,bufflen);//~v77bR~
        }                                                          //~v77bI~
        else                                                       //~v77bI~
        if (optRC & ROPT_OPEN)      //read line by following READLINE request//~v77bR~
        {                                                          //~v77bI~
//        	SopenDocPath=umalloc(strlen(Pfpath));                  //~v77bR~
//          strcpy(SopenDocPath,Pfpath);                           //~v77bR~
//          *Ppfh=(FILE*)(DOCFH_OPEN);                             //~v77bR~
			pdh=enqDocHandle(optRC,0/*buffer*/,0,Pfpath,pstrUri,0/*privateFILE*/);//~v77bR~
			UTRACEP("%s:returned c2j_openDoc INPUT returned Opened \n",UTT);//~v77bR~
        }                                                          //~v77bI~
        else	//                                                 //~v77bR~
        {                                                          //~v77bI~
//          SopenDocPrivateFH=fopen(fpathTemp,Popenopt);           //~v77bR~
            FILE *fh=fopen(fpathTemp,Popenopt);                    //~v77bI~
//          *Ppfh=SopenDocPrivateFH;                               //~v77bR~
			pdh=enqDocHandle(optRC,0/*buffer*/,0,Pfpath,pstrUri,fh);//~v77bR~
			UTRACEP("%s:returned c2j_openDoc returned copyprivate FHprivate=%p,fnm=%s\n",UTT,fh,fpathTemp);//~v77bR~
        }                                                          //~v77bI~
        *Ppfh=(FILE*)pdh;                                          //~v77bR~
    }                                                              //~v77bI~
    else	//output                                               //~v77bI~
    {                                                              //~v77bI~
//        ptempDir=gettempnampath(0);                              //~v77bI~
//        sprintf(fpathTemp,"%s/%s",ptempDir,Pfpath+PATHLEN_DOC(Pfpath));//~v77bI~
    	rc=c2j_openDoc(opt,Pfpath,pstrUri,""/*fpathTemp*/,&pbuff,&bufflen,&optRC);//~v77bR~
		UTRACEP("%s:returned c2j_openDoc rc=%d,fpath=%s,optrc=0x%x\n",UTT,rc,Pfpath,optRC);//~v77bI~
        if (rc)                                                    //~v77bI~
        	return rc;                                             //~v77bI~
		pdh=enqDocHandle(optRC,0/*buffer*/,0,Pfpath,pstrUri,0/*privateFILE*/);//~v77bI~
		UTRACEP("%s:returned c2j_openDoc OUTPUT returned Opened \n",UTT);//~v77bI~
        *Ppfh=(FILE*)pdh;                                          //~v77bI~
    }                                                              //~v77bI~
	UTRACEP("%s:exit rc=%d,*Ppfh=%p\n",UTT,rc,*Ppfh);              //~v77bR~
    return rc;                                                     //~v77bI~
}//ufile_OpenDoc                                                   //~v77bR~
//**********************************************************************//~vbyhI~
char* makeTempname(char *Pfpath,char *Pmemb)                       //~vbyhR~
{                                                                  //~vbyhI~
	char ch,*pc,*pco;                                              //~vbyhI~
	for (pc=Pfpath,pco=Pmemb;*pc;pc++,pco++)                       //~vbyhI~
    {                                                              //~vbyhI~
    	ch=*pc;                                                    //~vbyhI~
    	if (ch=='/' || ch==' ')                                    //~vbyhI~
        	*pco='_';                                              //~vbyhR~
        else                                                       //~vbyhI~
        	*pco=ch;                                               //~vbyhR~
    }                                                              //~vbyhI~
    *pco=0;                                                        //~vbyhI~
	UTRACEP("%s:Pfpath=%s,Pmemb=%s\n",UTT,Pfpath,Pmemb);               //~vbyhI~//~v77ZR~
    return Pmemb;                                                  //~vbyhI~
}                                                                  //~vbyhI~
//**********************************************************************//~vbyhI~
int ufile_clearCopyTemp()                                          //~vbyhI~
{                                                                  //~vbyhI~
	int ii,rc=0;                                                   //~vbyhI~
	char *pcopy;                                                   //~vbyhI~
//***********************                                          //~vbyhI~
	UTRACEP("%s:SctrCopyTemp=%d\n",UTT,SctrCopyTemp);              //~vbyhI~
    for (ii=0;ii<SctrCopyTemp;ii++)                                //~vbyhI~
    {                                                              //~vbyhI~
    	pcopy=SfnmCopyTemp[ii];                                    //~vbyhI~
		UTRACEP("%s:temp=%s\n",UTT,pcopy);                         //~vbyhI~
        rc+=unlink(pcopy);                                         //~vbyhI~
        ufree(pcopy);                                              //~vbyhI~
    }                                                              //~vbyhI~
    SctrCopyTemp=0;                                                //~vbyhI~
    return rc;                                                     //~vbyhI~
}//ufile_clearCopyTemp                                             //~vbyhI~
//**********************************************************************//~vbyhI~
void ufile_stackCopyTemp(char *Pfnm)                               //~vbyhI~
{                                                                  //~vbyhI~
	UINT len;                                                      //~vbyhR~
	char *pc;                                                      //~vbyhI~
//***********************                                          //~vbyhI~
	UTRACEP("%s:,SctrCopyTemp=%d,fnm=%s\n",UTT,SctrCopyTemp,Pfnm); //~vbyhI~
    if (SctrCopyTemp<MAX_COPYTEMP)                                 //~vbyhI~
    {                                                              //~vbyhI~
    	len=strlen(Pfnm);                                          //~vbyhI~
        pc=umalloc(len+1);                                         //~vbyhI~
        strcpy(pc,Pfnm);                                           //~vbyhI~
    	SfnmCopyTemp[SctrCopyTemp++]=pc;                           //~vbyhI~
    }                                                              //~vbyhI~
}//ufile_clearCopyTemp                                             //~vbyhI~
//**********************************************************************//~vbyhI~
int ufile_getCopyTemp(int Popt,char *Pfpath,char *Ptempfnm)        //~vbyhI~
{                                                                  //~vbyhI~
	int opt=0,rc=0,bufflen;                                        //~vbyhI~
    char *pbuff,*ptempDir,*pstrUri;                                //~vbyhI~
    int  optRC;                                                    //~vbyhI~
    char tempMember[_MAX_PATH];                                    //~vbyhR~
    FILEFINDBUF3 ft;                                               //~v77SR~
    int pathlen;                                                   //~v77SI~
//***********************                                          //~vbyhI~
	UTRACEP("%s:opt=0x%x,fpath=%s\n",UTT,Popt,Pfpath);             //~vbyhI~
	if (Popt & UFGCTO_INIT)                                        //~vbyhI~
    {                                                              //~vbyhI~
		ufile_clearCopyTemp();                                     //~vbyhI~
        return 0;                                                  //~vbyhI~
    }                                                              //~vbyhI~
	pstrUri=getShortpathUri(Pfpath);                               //~vbyhI~
    if (!pstrUri)                                                  //~vbyhI~
		return ERROR_PATH_NOT_FOUND;                               //~vbyhI~
    pathlen=PATHLEN(Pfpath);                                       //~v77SI~
    rc=callc2j_ufstatDoc(Pfpath,pstrUri,pathlen,0/*swWildname*/,&ft);//~v77SR~
    if (rc)                                                        //~v77SI~
    {                                                              //~v77SI~
		UTRACEP("%s:err exit rc=%d,fpath=%s,temp=%s\n",UTT,rc,Pfpath,Ptempfnm);//~v77SI~
    	return rc;                                                 //~v77SI~
    }                                                              //~v77SI~
    opt|=ROPT_BINARY|ROPT_INPUT|ROPT_COPYPRIVATE;                  //~vbyhR~
    ptempDir=gettempnampath(0);                                    //~vbyhI~
	sprintf(Ptempfnm,"%s/%s",ptempDir,makeTempname(Pfpath,tempMember));//~vbyhR~
    rc=c2j_openDoc(opt,Pfpath,pstrUri,Ptempfnm,&pbuff,&bufflen,&optRC);//~vbyhR~
    if (!rc)                                                       //~vbyhI~
		ufile_stackCopyTemp(Ptempfnm);                             //~vbyhR~
	UTRACEP("%s:returned c2j_openDoc rc=%d,fpath=%s,optrc=0x%x\n",UTT,rc,Pfpath,optRC);//~vbyhI~
	UTRACEP("%s:exit rc=%d,fpath=%s,temp=%s\n",UTT,rc,Pfpath,Ptempfnm);//~vbyhR~
    return rc;                                                     //~vbyhI~
}//ufile_getCopyTemp                                               //~vbyhI~
////**********************************************************************//~v77bR~
//void ufile_openDocResult(char *Pfpath,int Popt,int PrcOpt,char *Pbuff/*utf8str or byte[]*/,int Plen)//~v77bR~
//{                                                                //~v77bR~
////***********************                                        //~v77bR~
//    UTRACEP("%s:Pfpath=%s,opt=0x%x,rcOpt=0x%x,buff=%p,len=%d\n",UTT,Pfpath,Popt,PrcOpt,Pbuff,Plen);//~v77bR~
//    if (Pbuff)                                                   //~v77bR~
//        UTRACED("Pbuff",Pbuff,Plen);                             //~v77bR~
//    UTRACEP("%s:exit \n",UTT);                                   //~v77bR~
//}//ufile_openDocResult                                           //~v77bR~
//**********************************************************************//~v77bI~
char *ufile_fgetsDoc(char *Pbuff,int Pbuffsz,void *Phandle)        //~v77bR~
{                                                                  //~v77bI~
//  int rc,opt,len,offs;                                           //~v77bR~//~v77BR~
    int rc,    len,offs;                                           //~v77BI~
    char *pc,*pbuffRC=0,*psrc;                          //~v77bR~
    PDOC_HANDLE pdh;                                                //~v77bR~
//***********************                                          //~v77bI~
	UTRACEP("%s:handle=%p\n",UTT,Phandle);                         //~v77bR~
    pdh=(PDOC_HANDLE)Phandle;                                       //~v77bR~
    if (pdh->swClosed)                                             //~v77bI~
    {                                                              //~v77bI~
    	pdh->err=EBADF;                                            //~v77bI~
        return 0;                                                  //~v77bR~
    }                                                              //~v77bI~
    if (pdh->optRC & ROPT_STRING)   //returned full content by buffer  //~v77bR~
    {                                                              //~v77bR~
        UTRACEP("%s:opt String  offs=%d,size=%d\n",UTT,pdh->bufferOffs,pdh->bufferLen);//~v77bR~
        psrc=pdh->buffer;                                //~v77bI~ //~v77dR~
//      if (SopenDocBufferOffs>=SopenDocBufferLen)                 //~v77bR~
        if (pdh->bufferOffs>=pdh->bufferLen)                       //~v77bI~
        {                                                          //~v77bR~
            rc=0;  //EOF                                           //~v77bR~
        }                                                          //~v77bR~
        else                                                       //~v77bR~
        {                                                          //~v77bR~
//          pc=strchr(SopenDocBuffer+SopenDocBufferOffs,'\n');     //~v77bR~
            pc=strchr(psrc+pdh->bufferOffs,'\n');                  //~v77bR~
            if (pc)                                                //~v77bR~
            {                                                      //~v77bR~
//              offs=PTRDIFF(pc,SopenDocBufferOffs)+1;             //~v77bR~
                offs=PTRDIFF(pc,psrc)+1;                    //~v77bI~
//              len=offs-SopenDocBufferOffs;                       //~v77bR~
                len=offs-pdh->bufferOffs;                          //~v77bI~
//              UmemcpyZ(Pbuff,SopenDocBuffer+SopenDocBufferOffs,len);//~v77bR~
                UmemcpyZ(Pbuff,psrc+pdh->bufferOffs,len);          //~v77bR~
//              SopenDocBufferOffs=offs;                           //~v77bR~
                pdh->bufferOffs=offs;                              //~v77bI~
            }                                                      //~v77bR~
            else                                                   //~v77bR~
            {                                                      //~v77bR~
//              len=(int)strlen(SopenDocBuffer+SopenDocBufferOffs);//~v77bR~
                len=(int)strlen(psrc+pdh->bufferOffs);             //~v77bR~
//              UmemcpyZ(Pbuff,SopenDocBuffer+SopenDocBufferOffs,len);//~v77bR~
                UmemcpyZ(Pbuff,psrc+pdh->bufferOffs,len);          //~v77bR~
//              SopenDocBufferOffs=SopenDocBufferLen;              //~v77bR~
                pdh->bufferOffs=pdh->bufferLen;                    //~v77bI~
            }                                                      //~v77bR~
            pbuffRC=Pbuff;                                         //~v77bI~
        }                                                          //~v77bR~
        UTRACEP("%s:opt String pbuffRC=%p\n",UTT,pbuffRC);         //~v77bR~
    }                                                              //~v77bR~
    else                                                           //~v77bR~
    if (pdh->optRC & ROPT_OPEN)      //read line by following READLINE request//~v77bR~
    {                                                              //~v77bR~
//      opt=ROPT_READLINE;                                         //~v77bR~//~v77BR~
//      rc=c2j_readDoc(SoptRC|ROPT_READLINE,SopenDocPath,&pbuff,&bufflen);//~v77bR~
        rc=c2j_fgetsDoc(pdh->optRC,pdh->fpath,Pbuff,Pbuffsz);      //~v77bR~
        if (!rc)                                                   //~v77bI~
	        pbuffRC=Pbuff;                                         //~v77bI~
        UTRACEP("%s:returned c2j_fgetsDoc fpath=%s,pbuffRC=%p\n",UTT,pdh->fpath,pbuffRC);//~v77bR~
    }                                                              //~v77bR~
    else               //read from localcopy                       //~v77bR~
    {                                                              //~v77bR~
//      pc=fgets(Pbuff,Pbuffsz,SopenDocPrivateFH);                 //~v77bR~
        pbuffRC=fgets(Pbuff,Pbuffsz,pdh->privateFH);               //~v77bR~
        UTRACEP("%s:COPYPRIVATE read privateFile=%s,line=%s\n",UTT,pdh->privateFH,pbuffRC);//~v77bR~
    }                                                              //~v77bR~
    return pbuffRC;                                                //~v77bR~
}//ufile_fgetsDoc                                                  //~v77bR~
//**********************************************************************//~v77bI~
UINT ufile_freadDoc(void *Pbuff,UINT Pbuffsz,UINT Pctr,void *Phandle)              //~v77bR~
{                                                                  //~v77bI~
	int rc,reslen,reqlen,copylen,readlen=0;                        //~v77bR~
    PDOC_HANDLE pdh;                                               //~v77bI~
//***********************                                          //~v77bI~
	reqlen=(int)(Pbuffsz*Pctr);                                    //~v77bI~
    pdh=(PDOC_HANDLE)Phandle;                                      //~v77bI~
	UTRACEP("%s:handle=%p,reqLen=%d,opt=0x%x\n",UTT,Phandle,reqlen,pdh->optRC);//~v77bI~
    if (pdh->swClosed)                                             //~v77bI~
    {                                                              //~v77bI~
    	pdh->err=EBADF;                                            //~v77bI~
        return -1;                                                 //~v77bI~
    }                                                              //~v77bI~
    if (pdh->optRC & ROPT_STRING)   //returned full content by buffer//~v77bI~
    {                                                              //~v77bI~
        UTRACEP("%s:opt String  offs=%d,size=%d\n",UTT,pdh->bufferOffs,pdh->bufferLen);//~v77bI~
        if (pdh->bufferOffs>=pdh->bufferLen)                       //~v77bI~
        {                                                          //~v77bI~
            rc=-1;  //EOF                                          //~v77bI~
        }                                                          //~v77bI~
        else                                                       //~v77bI~
        {                                                          //~v77bI~
        	reslen=pdh->bufferLen-pdh->bufferOffs;                 //~v77bI~
            if (reslen<reqlen)                                     //~v77bI~
            	copylen=reslen;                                    //~v77bI~
            else                                                   //~v77bI~
            	copylen=reqlen;                                    //~v77bI~
            memcpy(Pbuff,pdh->buffer+pdh->bufferOffs,(UINT)copylen);//~v77bR~//~v77dR~
            pdh->bufferOffs+=copylen;                              //~v77bI~
            rc=copylen;                                            //~v77bI~
        }                                                          //~v77bI~
        UTRACEP("%s:opt String rc=%d\n",UTT,rc);                   //~v77bI~
    }                                                              //~v77bI~
    else                                                           //~v77bI~
    if (pdh->optRC & ROPT_OPEN)      //read line by following READLINE request//~v77bI~
    {                                                              //~v77bI~
        rc=c2j_freadDoc(pdh->optRC,pdh->fpath,Pbuff,reqlen,&readlen);//~v77bR~
        UTRACEP("%s:returned c2j_freadDoc fpath=%s,rc=%d,reqlen=%d\n",UTT,pdh->fpath,rc,reqlen);//~v77bI~
    }                                                              //~v77bI~
    else               //read from localcopy                       //~v77bI~
    {                                                              //~v77bI~
        readlen=fread(Pbuff,Pbuffsz,Pctr,pdh->privateFH);          //~v77bR~
        rc=errno;                                                  //~v77bI~
        UTRACEP("%s:COPYPRIVATE read privateFile=%s,line=%s\n",UTT,pdh->privateFH,rc);//~v77bI~
    }                                                              //~v77bI~
    pdh->err=rc;                                                   //~v77bI~
	UTRACEP("%s:exit rc=%d,err=%d\n",UTT,readlen,rc);              //~v77bI~
    return readlen;                                                //~v77bR~
}//ufile_freadDoc                                                  //~v77bI~
//**********************************************************************//~v77bI~
size_t ufile_fwriteDoc(void *Pbuff,size_t Psize,size_t Pctr,void *Phandle)//~v77bI~
{                                                                  //~v77bI~
	int rc,reqlen,writelen=0;                                      //~v77bR~
    PDOC_HANDLE pdh;                                               //~v77bI~
//***********************                                          //~v77bI~
	reqlen=(int)(Psize*Pctr);                                      //~v77bR~
    pdh=(PDOC_HANDLE)Phandle;                                      //~v77bI~
	UTRACEP("%s:handle=%p,reqLen=%d,opt=0x%x\n",UTT,Phandle,reqlen,pdh->optRC);//~v77bI~
    if (pdh->swClosed)                                             //~v77bI~
    {                                                              //~v77bI~
    	rc=EINVAL;                                                 //~v77bI~
        writelen=0;                                                //~v77bI~
    }                                                              //~v77bI~
    if (pdh->optRC & ROPT_OPEN)      //read line by following READLINE request//~v77bI~
    {                                                              //~v77bI~
        rc=c2j_fwriteDoc(pdh->optRC,pdh->fpath,Pbuff,reqlen,&writelen);//~v77bR~
        UTRACEP("%s:returned c2j_fwriteDoc fpath=%s,rc=%d,reqlen=%d\n",UTT,pdh->fpath,rc,reqlen);//~v77bI~
    }                                                              //~v77bI~
    else               //read from localcopy                       //~v77bI~
    {                                                              //~v77bI~
        writelen=fwrite(Pbuff,Psize,Pctr,pdh->privateFH);          //~v77bI~
        rc=errno;                                                  //~v77bI~
        UTRACEP("%s:COPYPRIVATE write privateFile=%s,line=%s\n",UTT,pdh->privateFH,rc);//~v77bI~
    }                                                              //~v77bI~
    pdh->err=rc;                                                   //~v77bI~
	UTRACEP("%s:exit rc=%d,err=%d\n",UTT,writelen,pdh->err);       //~v77bI~
    return writelen;                                               //~v77bI~
}                                                                  //~v77bI~
//**********************************************************************//~v77bI~
int ufile_mkdirDoc(char *Pfpath,mode_t Pmode)                      //~v77cR~
{                                                                  //~v77cR~
    char *strUri;
    int rc;//~v77bI~
//***********************                                          //~v77cR~
	UTRACEP("%s:path=%s\n",UTT,Pfpath);                            //~v77cR~
	strUri=getShortpathUri(Pfpath);                                //~v77cR~
    if (!strUri)                                                   //~v77cR~
    {                                                              //~v77cR~
	    UTRACEP("%s:invalid name fpath=%s\n",UTT,Pfpath);          //~v77cR~
    	errno=EINVAL;                                              //~v77cR~
    	return -1;                                                 //~v77cR~
    }                                                              //~v77cR~
    rc=c2j_mkdirDoc(0,Pfpath,strUri);                              //~v77cR~
    UTRACEP("%s:returned c2j_mkdirDoc fpath=%s,rc=%d\n",UTT,Pfpath,rc);//~v77cR~
    if (rc)                                                        //~v77cR~
    {                                                              //~v77cR~
    	errno=rc;                                                  //~v77cR~
        rc=-1;                                                     //~v77cR~
    }                                                              //~v77cR~
    return rc;                                                     //~v77cR~
}                                                                  //~v77cR~
//**********************************************************************//~v77fI~
//*return errno                                                    //~v77fI~
//**********************************************************************//~v77fI~
int ufile_rmdirDoc(char *Pfpath)                                   //~v77fI~
{                                                                  //~v77fI~
    char *strUri;                                                  //~v77fI~
    int rc;                                                        //~v77fI~
//***********************                                          //~v77fI~
	UTRACEP("%s:path=%s\n",UTT,Pfpath);                            //~v77fI~
	strUri=getShortpathUri(Pfpath);                                //~v77fI~
    if (!strUri)                                                   //~v77fI~
    {                                                              //~v77fI~
	    UTRACEP("%s:invalid name fpath=%s\n",UTT,Pfpath);          //~v77fI~
    	return EINVAL;                                            //~v77fI~
    }                                                              //~v77fI~
    rc=c2j_rmdirDoc(0,Pfpath,strUri);                              //~v77fI~
    UTRACEP("%s:returned c2j_rmdirDoc fpath=%s,rc=%d\n",UTT,Pfpath,rc);//~v77fI~
    return rc;                                                     //~v77fI~
}                                                                  //~v77fI~
//**********************************************************************//~v77dI~
int ufile_unlinkDoc(char *Pfpath)                                  //~v77dI~
{                                                                  //~v77dI~
    char *strUri;                                                  //~v77dI~
    int rc;                                                        //~v77dI~
//***********************                                          //~v77dI~
	UTRACEP("%s:path=%s\n",UTT,Pfpath);                            //~v77dI~
	strUri=getShortpathUri(Pfpath);                                //~v77dI~
    if (!strUri)                                                   //~v77dI~
    {                                                              //~v77dI~
	    UTRACEP("%s:invalid name fpath=%s\n",UTT,Pfpath);          //~v77dI~
    	errno=EINVAL;                                              //~v77dI~
    	return -1;                                                 //~v77dI~
    }                                                              //~v77dI~
    rc=c2j_unlinkDoc(0,Pfpath,strUri);                             //~v77dR~
    UTRACEP("%s:returned c2j_unlinkDoc fpath=%s,rc=%d\n",UTT,Pfpath,rc);//~v77dI~
    if (rc)                                                        //~v77dI~
    {                                                              //~v77dI~
    	errno=rc;                                                  //~v77dI~
        rc=-1;                                                     //~v77dI~
    }                                                              //~v77dI~
    return rc;                                                     //~v77dI~
}                                                                  //~v77dI~
//**********************************************************************//~v77gI~
//*return errno                                                    //~v77gI~
//**********************************************************************//~v77gI~
int ufile_renameDoc(char *Pold,char *Pnew)                         //~v77gI~
{                                                                  //~v77gI~
    char *strUri;                                                  //~v77gI~
    int rc;                                                        //~v77gI~
//***********************                                          //~v77gI~
	UTRACEP("%s:old=%s,new=%s\n",UTT,Pold,Pnew);                   //~v77gI~
	strUri=getShortpathUri(Pold);                                  //~v77gI~
    if (!strUri)                                                   //~v77gI~
    {                                                              //~v77gI~
	    UTRACEP("%s:invalid name old=%s\n",UTT,Pold);              //~v77gI~
    	errno=EINVAL;                                              //~v77gI~
    	return -1;                                                 //~v77gI~
    }                                                              //~v77gI~
    rc=c2j_renameDoc(0,Pold,strUri,Pnew);	///errno               //~v77gR~
    UTRACEP("%s:returned c2j_renameDoc rc=%d,old=%s,new=%s\n",UTT,rc,Pold,Pnew);//~v77gI~
    return rc;                                                     //~v77gI~
}                                                                  //~v77gI~
//**********************************************************************//~v77hI~
int ufile_copyDoc(int Popt,char *Psrc,char *Ptgt)                  //~v77hI~
{                                                                  //~v77hI~
    char *strUriS=0,*strUriT=0;                                    //~v77hR~
    int rc=0,errT,errS;                                            //~v77hR~
    char wkpath[_MAX_PATH*3];                                      //~v77hR~
//***********************                                          //~v77hI~
	UTRACEP("%s:opt=0x%x,src=%s,tgt=%s\n",UTT,Popt,Psrc,Ptgt);     //~v77hI~
    if (IS_DOCPATH(Psrc))                                          //~v77hI~
    {                                                              //~v77hI~
		strUriS=getShortpathUri(Psrc);                             //~v77hI~
	    if (!strUriS)                                              //~v77hI~
    	{                                                          //~v77hI~
	    	UTRACEP("%s:invalid src fpath=%s\n",UTT,Psrc);         //~v77hI~
			return showErrDoc(EINVAL,Psrc,-1);                      //~v77hI~
    	}                                                          //~v77hI~
    }                                                              //~v77hI~
    if (IS_DOCPATH(Ptgt))                                          //~v77hI~
    {                                                              //~v77hI~
		strUriT=getShortpathUri(Ptgt);                             //~v77hI~
	    if (!strUriT)                                              //~v77hI~
    	{                                                          //~v77hI~
	    	UTRACEP("%s:invalid tgt fpath=%s\n",UTT,Ptgt);        //~v77hI~
			return showErrDoc(EINVAL,Ptgt,-1);                      //~v77hI~
    	}                                                          //~v77hI~
    }                                                              //~v77hI~
    rc=c2j_copyDoc(Popt,Psrc,strUriS,Ptgt,strUriT,&errS,&errT);    //~v77hI~
    if (rc)                                                        //~v77hI~
    {                                                              //~v77hI~
    	if (errS)                                                  //~v77hI~
			return showErrDoc(errS,Psrc,-1);                        //~v77hI~
    	if (errT)                                                  //~v77hI~
			return showErrDoc(errT,Ptgt,-1);                        //~v77hI~
        sprintf(wkpath,"copy %s to %s",Psrc,Ptgt);                 //~v77hI~
		return showErrDoc(EINTR,wkpath,-1);                //~v77hR~
    }                                                              //~v77hI~
    UTRACEP("%s:exit success src=%s,tgt=%s\n",UTT,Psrc,Ptgt);      //~v77hI~
    return 0;                                                      //~v77hI~
}                                                                  //~v77hI~
//**********************************************************************//~v77wI~
int ufile_opendirDoc30(int Popt,char *Pfpath,char *PstrUri,DIR **Pphdir)//~v77wI~
{                                                                  //~v77wI~
    DIR *pdir;                                                     //~v77wI~
    int rc;                                                        //~v77wI~
    char path[_MAX_PATH];                                          //~v77wI~
    char fpath[_MAX_PATH],*dirname;                                //~v77wI~
//***********************                                          //~v77wI~
	UTRACEP("%s:fpath=%s,strUri=%s\n",UTT,Pfpath,PstrUri);         //~v77wI~
    if (WILDCARD(Pfpath))                                          //~v77xI~
    	return ENOENT;                                             //~v77xI~
//  rc=c2j_getDocPath(Popt,Pfpath,PstrUri,path);                    //~v77wR~//~v77zR~
  	rc=ufile_getRealpath(Pfpath,path,PstrUri);                     //~v77zI~
    if (rc)                                                        //~v77wR~
    	return rc;                                                 //~v77wI~
    errno=0;                                                       //~v77wI~
    dirname=strchr(Pfpath+PREFIX_ARM_SHARE_LEN,'/');               //~v77wI~
    if (dirname)                                                   //~v77wI~
	    sprintf(fpath,"%s%s",path,dirname);                        //~v77wI~
    else                                                           //~v77wI~
	    strcpy(fpath,path);                                        //~v77wI~
	pdir=opendir(fpath);                                           //~v77wR~
    rc=errno;                                                      //~v77wI~
	UTRACEP("%s:after opendir fpath=%s,rc(errno)=%d,pdir=%p\n",UTT,fpath,rc,pdir);//~v77wR~
    *Pphdir=pdir;                                                  //~v77wI~
    return rc;                                                     //~v77wI~
    UTRACEP("%s:returned exit fpath=%s,rc=%d,hdir=%p\n",UTT,Pfpath,rc,*Pphdir);//~v77wI~
    return rc;                                                     //~v77wI~
}                                                                  //~v77wI~
//**********************************************************************//~v77MI~
//*API30 in not allfiles permission                                //~v77MI~
//*!! not used                                                     //~v77SI~
//**********************************************************************//~v77MI~
int ufile_opendirDoc30_dirlist(int Popt,char *Pfpath,char *PstrUri,DIR **Pphdir)//~v77MI~
{                                                                  //~v77MI~
    PUDIRLIST pudl;
	PDOC_HANDLE pdh=0;                                             //~v77MI~
    int rc,ctr;//~v77MI~
    char fpath[_MAX_PATH],*pfpath;                                 //~v77MI~
//*******************************                                  //~v77MI~
    UTRACEP("%s:returned fpath=%s,strUri=%s\n",UTT,Pfpath,PstrUri);//~v77MI~
    int pathlen=PATHLEN(Pfpath);                                   //~v77MI~
    if (pathlen<0)    //no / found(not fullpath name)              //~v77MI~
        pathlen=0;                                                 //~v77MI~
    int swWildname=WILDCARD(Pfpath+pathlen)!=NULL;                 //~v77MI~
    Serr_udirlist=c2j_ufstatDoc(0,Pfpath,PstrUri,pathlen,&pudl);   //~v77MI~
    if (!Serr_udirlist && pudl)                                    //~v77MI~
    {                                                              //~v77MI~
    	if  (pudl->attr & FILE_DIRECTORY)                          //~v77MI~
        	ctr=1;                                                 //~v77MI~
        else                                                       //~v77MI~
        {                                                          //~v77MI~
            ctr=0;                                                 //~v77MI~
        	Serr_udirlist=ENOTDIR;                                 //~v77MI~
        }                                                          //~v77MI~
    }                                                              //~v77MI~
    else                                                           //~v77MI~
    	ctr=0;                                                     //~v77MI~
    if (ctr>0)                                                     //~v77MI~
    {                                                              //~v77MI~
		if (swWildname)                                            //~v77MI~
        {                                                          //~v77MI~
        	strcpy(fpath,Pfpath);                                  //~v77MI~
        	*(fpath+pathlen-1)=0;                                  //~v77MI~
            pfpath=fpath;                                          //~v77MI~
        }                                                          //~v77MI~
        else                                                       //~v77MI~
    	if (*(Pfpath+strlen(Pfpath)-1)=='/')                       //~v77MI~
        {                                                          //~v77MI~
        	strcpy(fpath,Pfpath);                                  //~v77MI~
        	*(fpath+strlen(Pfpath)-1)=0;                           //~v77MI~
            pfpath=fpath;                                          //~v77MI~
        }                                                          //~v77MI~
        else                                                       //~v77MI~
        	pfpath=Pfpath;                                         //~v77MI~
	    UTRACEP("%s:not wild fpath=%s\n",UTT,pfpath);              //~v77MI~
		ctr=udirlistDoc(UDL_NOMSG,pfpath,FILE_ALL,&pudl,0/*PsortType*/);//~v77MI~
    }                                                              //~v77MI~
    if (ctr>0)                                                     //~v77MI~
		pdh=enqDocHandle(ROPT_OPENDIR,(char*)pudl/*buffer*/,ctr*UDIRLISTSZ,Pfpath,PstrUri,0/*privateFILE*/);//~v77MR~
    rc=Serr_udirlist;                                              //~v77MI~
//	*Pphdir=pdh;                                                   //~v77MR~
  	*Pphdir=(DIR*)(void*)pdh;                                      //~v77MI~
    UTRACEP("%s:returned exit fpath=%s,rc=%d,hdir=%p\n",UTT,Pfpath,rc,*Pphdir);//~v77MI~
    return rc;
  }                                                                //~v77MI~
//**********************************************************************//~v77dI~
//*if >=API30(A11-R)                                               //~v77SI~
//*  if AllFiles ON                                                //~v77SI~
//*    	openDirDoc30: getRealPath && opendir(path)                 //~v77SI~
//*  else                                                          //~v77SI~
//*  	udirlistDoc:  get dirlist and returns 1 by 1 for readdir(ROPT_OPENDIR)//~v77SI~
//*else                                                            //~v77SI~
//*  c2j_openDirDoc(&fd)                                           //~v77SI~
//*  issue native readdir for each readdir(ROPT_OPENDIRFD)         //~v77SI~
//**********************************************************************//~v77SI~
int ufile_opendirDoc(char *Pfpath,void **Pphdir)                   //~v77dR~//~v77eR~
{                                                                  //~v77dI~
    char *strUri;                                                  //~v77dI~
    int rc=0,ctr;                                                    //~v77dI~//~v77eR~
	PDOC_HANDLE pdh=0;
    PUDIRLIST pudl;//~v77dI~
    int pathlen,swWildname;                                        //~v77eI~
    char fpath[_MAX_PATH],*pfpath;                             //~v77eI~
//***********************                                          //~v77dI~
	UTRACEP("%s:GarmApiLevel=%d,fpath=%s\n",UTT,GarmApiLevel,Pfpath);                           //~v77dI~//~v77xR~
    *Pphdir=0;                                                     //~v77wI~
	strUri=getShortpathUri(Pfpath);                                //~v77dI~
    if (!strUri)                                                   //~v77dI~
    {                                                              //~v77dI~
	    UTRACEP("%s:invalid name fpath=%s\n",UTT,Pfpath);          //~v77dI~
    	errno=EINVAL;                                              //~v77dI~
    	return -1;                                                 //~v77dI~
    }                                                              //~v77dI~
//if (1)                                                           //~v77iR~//~v77MR~
//{                                                                //~v77eI~//~v77MR~
    DIR *pdir;                                                     //~v77eM~
    pdir=0;                                                        //~v77wI~
   if (GarmApiLevel>=30) //android11                          //~v77wR~//~v77xR~//~v77MR~
   {                                                               //~v77wI~
     if (ufile_isGrantedAllFiles())                                //~v77MI~
     {                                                             //~v77MI~
		rc=ufile_opendirDoc30(0,Pfpath,strUri,&pdir);	//rc:errno         //~v77wI~
//   }                                                             //~v77MR~
//   else                                                          //~v77MR~
//   {                                                             //~v77MR~
//  	rc=ufile_opendirDoc30_dirlist(0,Pfpath,strUri,&pdir);	//rc:errno//~v77MR~
//   }                                                             //~v77MR~
		UTRACEP("%s:after opendirDoc30 rc=%d,pdir=%p\n",UTT,rc,pdir);//~v77wR~
        *Pphdir=pdir;                                              //~v77wI~
        return rc;                                                 //~v77wI~
     }                                                             //~v77MI~
     //*else goto 30dirlist                                        //~v77MI~
   }                                                               //~v77wI~
   else                                                            //~v77wI~
   {                                                               //~v77wI~
//* api<30                                                         //~v77MI~
    int fd;                                                        //~v77eM~
	rc=c2j_opendirDoc(0,Pfpath,strUri,&fd);                        //~v77eI~
    if (!rc)                                                       //~v77eI~
    {                                                              //~v77eI~
		UTRACEP("%s:before fdopen fd=%d,fpath=%s\n",UTT,fd,Pfpath);//~v77eI~
        if (0)                                                     //~v77hI~
        {                                                          //~v77eI~
        	FILE *fhdir;                                           //~v77eI~
            char dirbuff[1024];                                    //~v77eI~
            int rc2;                                               //~v77eI~
            errno=0;                                               //~v77eI~
			fhdir=fdopen(fd,"r");                                             //~v77eR~//~v77SR~
			UTRACEP("%s:after  fdopen fhdir=%p,errno=%d\n",UTT,fhdir,errno);//~v77eI~//~v77iR~
            errno=0;                                               //~v77eI~
        	rc2=fread(dirbuff,1024,1,fhdir);                       //~v77eI~
			UTRACEP("%s:before fdopendir fd=%d,rc=%d,errno=%d\n",UTT,fd,rc2,errno);//~v77eR~
			UTRACED("dirbuff",dirbuff,rc2);                        //~v77eI~
        }                                                          //~v77eI~
		UTRACEP("%s:before fdopendir fd=%d,fpath=%s\n",UTT,fd,Pfpath);//~v77eR~
        errno=0;                                                   //~v77hI~
		pdir=fdopendir(fd);                                        //~v77eI~
        if (!pdir)                                                 //~v77eI~
        {                                                          //~v77eI~
        	rc=errno;                                              //~v77eI~
			UTRACEP("%s:after  fdopendir Failed errno=%d,fpath=%s\n",UTT,rc,Pfpath);      //~v77hI~//~v77iR~
        }                                                          //~v77eI~
        else                                                       //~v77eI~
        {                                                          //~v77eI~
			UTRACEP("%s:after  fdopendir pdir=%p,fpath=%s\n",UTT,pdir,Pfpath);//~v77iR~
//            PDIRENT pde;                                           //~v77hI~//~v77iR~
//            errno=0;                                               //~v77hI~//~v77iR~
//            pde=readdir(pdir);                                     //~v77hI~//~v77iR~
//            if (!pde)                                              //~v77hI~//~v77iR~
//            {                                                      //~v77hI~//~v77iR~
//                rc=errno;                                          //~v77hI~//~v77iR~
//                UTRACEP("%s:before fdopendir errno=%d\n",UTT,rc);  //~v77hI~//~v77iR~
//            }                                                      //~v77hI~//~v77iR~
//            else                                                   //~v77hI~//~v77iR~
//                UTRACEP("%s:d_name=%s\n",UTT,pde->d_name);         //~v77hR~//~v77iR~
			pdh=enqDocHandle(ROPT_OPENDIRFD,(char*)(void*)pdir/*buffer*/,fd/*bufflen*/,Pfpath,strUri,0/*privateFILE*/);//~v77eR~//~v77iR~
        }                                                          //~v77eI~
    }                                                              //~v77eI~
  	*Pphdir=pdh;                                                   //~v77MI~
    UTRACEP("%s:returned exit fpath=%s,rc=%d,hdir=%p\n",UTT,Pfpath,rc,*Pphdir);//~v77MI~
    return rc;                                                     //~v77MI~
   }//apilevel<30                                                  //~v77wI~
//}                                                                //~v77eI~//~v77MR~
//else                                                             //~v77eI~//~v77MR~
//{                                                                //~v77eI~//~v77MR~
//*30dirlist                                                       //~v77MI~
    UTRACEP("%s:apilevel>=30 and !AllFiles\n",UTT);                //~v77MI~
    pathlen=PATHLEN(Pfpath);                                       //~v77eI~
    if (pathlen<0)    //no / found(not fullpath name)              //~v77eI~
        pathlen=0;                                                 //~v77eI~
    swWildname=WILDCARD(Pfpath+pathlen)!=NULL;                     //~v77eI~//~v77fR~
//  if (swWildname)                                                //~v77eI~//~v77fR~
//  {                                                              //~v77eI~//~v77fR~
    	Serr_udirlist=c2j_ufstatDoc(0,Pfpath,strUri,pathlen,&pudl);//~v77eI~
        if (!Serr_udirlist && pudl)                                //~v77eI~
          if  (pudl->attr & FILE_DIRECTORY)                        //~v77fI~
        	ctr=1;                                                 //~v77eI~
          else                                                     //~v77fI~
          {                                                        //~v77fI~
            ctr=0;                                                 //~v77fI~
        	Serr_udirlist=ENOTDIR;                                 //~v77fI~
          }                                                        //~v77fI~
        else                                                       //~v77eI~
        	ctr=0;                                                 //~v77eI~
//  }                                                              //~v77eI~//~v77fR~
//  else                                                           //~v77eI~//~v77fR~
    if (ctr>0)                                                     //~v77fI~
    {                                                              //~v77eI~
		if (swWildname)                                            //~v77fI~
        {                                                          //~v77fI~
        	strcpy(fpath,Pfpath);                                  //~v77fI~
        	*(fpath+pathlen-1)=0;                                  //~v77fI~
            pfpath=fpath;                                          //~v77fI~
        }                                                          //~v77fI~
        else                                                       //~v77fI~
    	if (*(Pfpath+strlen(Pfpath)-1)=='/')                 //~v77eR~//~v77fR~
        {                                                          //~v77eI~
        	strcpy(fpath,Pfpath);                                  //~v77fI~
        	*(fpath+strlen(Pfpath)-1)=0;                           //~v77fI~
            pfpath=fpath;                                          //~v77eI~
        }                                                          //~v77eI~
        else                                                       //~v77eI~
        	pfpath=Pfpath;                                         //~v77eI~
	    UTRACEP("%s:not wild fpath=%s\n",UTT,pfpath);              //~v77eI~
	ctr=udirlistDoc(UDL_NOMSG,pfpath,FILE_ALL,&pudl,0/*PsortType*/);//~v77dI~//~v77eR~
    }                                                              //~v77eI~
    if (ctr>0)                                                     //~v77dI~
		pdh=enqDocHandle(ROPT_OPENDIR,(char*)pudl/*buffer*/,ctr*UDIRLISTSZ,Pfpath,strUri,0/*privateFILE*/);//~v77dR~//~v77eR~
    rc=Serr_udirlist;                                              //~v77dI~
    UTRACEP("%s:returned fpath=%s,rc=%d,ctr=%d\n",UTT,Pfpath,rc,ctr);//~v77eR~
//} //else (1)                                                     //~v77eI~//~v77MR~
  	*Pphdir=pdh;                                             //~v77eI~
    UTRACEP("%s:returned exit fpath=%s,rc=%d,hdir=%p\n",UTT,Pfpath,rc,*Pphdir);//~v77dR~//~v77eR~
    return rc;                                                     //~v77dI~
}                                                                  //~v77dI~
//**********************************************************************//~v77nI~
//*chk ".." for root                                               //~v77nI~
//**********************************************************************//~v77nI~
int isParentOfRoot(PDOC_HANDLE Ppdh,PDIRENT Ppde)                  //~v77nI~
{                                                                  //~v77nI~
	int rc=0;                                                      //~v77nI~
    char *pc;                                                      //~v77nI~
//***********************                                          //~v77nI~
    if (!strcmp(Ppde->d_name,".."))                                 //~v77nI~
    {                                                              //~v77nI~
    	pc=strchr(Ppdh->fpath+PREFIX_ARM_SHARE_LEN,'/');           //~v77nI~
        if (!pc || !*(pc+1))                                       //~v77nI~
        	rc=1;                                                  //~v77nI~
    }                                                              //~v77nI~
	UTRACEP("%s:rc=%d,fpath=%s,d_name=%s\n",UTT,rc,Ppdh->fpath,Ppde->d_name);//~v77nR~
    return rc;                                                     //~v77nI~
}                                                                  //~v77nI~
//**********************************************************************//~v77dI~
PDIRENT ufile_readdirDoc(void *Ppdir)                              //~v77dR~
{                                                                  //~v77dI~
    int ctr,offs,buffsz;                                           //~v77dR~
    PDOC_HANDLE pdh;
    PDIRENT pde;//~v77dI~
  	DIR *pdir;                                                     //~v77eR~
//***********************                                          //~v77dI~
	UTRACEP("%s:Pphdir=%p\n",UTT,Ppdir);                          //~v77dI~
    pdh=(PDOC_HANDLE)Ppdir;                                        //~v77dR~
  if (pdh->optRC & ROPT_OPENDIRFD)//        0x0200    //opendir using fd//~v77eI~
  {                                                                //~v77eI~
  	pdir=(DIR*)(pdh->pdir);                                                //~v77eR~//~v77iR~
	UTRACEP("%s:pdir=%p\n",UTT,pdir);                              //~v77eI~
   for (;;)                                                        //~v77nI~
   {                                                               //~v77nI~
    errno=0;                                                       //~v77eI~
    pde=ufiledoc_readdir_native(pdir);                                      //~v77eR~//~v77iR~
    pdh->err=errno;                                                //~v77eI~
    if (pde)                                                       //~v77eI~
    {                                                              //~v77eI~
		UTRACED("pde",pde,sizeof(DIRENT));                         //~v77eI~
// 		memcpy(pdh->pde,pde,sizeof(DIRENT));                       //~v77eI~//~v77iR~
//  	pde=pdh->pde;                                              //~v77eI~//~v77iR~
	    if (!isParentOfRoot(pdh,pde))	                           //~v77nI~
        	break;                                                 //~v77nI~
    }                                                              //~v77eI~
    else                                                           //~v77nI~
     break;                                                        //~v77nI~
   }                                                               //~v77nI~
  }                                                                //~v77eI~
  else                                                             //~v77eI~
  {                                                                //~v77eI~
	UTRACED("pdh",pdh,DOC_HANDLESZ);                             //~v77dI~//~v77eR~
    PUDIRLIST pudl=(PUDIRLIST)pdh->buffer;                         //~v77dI~
    offs=pdh->bufferOffs;                                          //~v77dI~
    ctr=offs/UDIRLISTSZ;                                           //~v77dI~
    buffsz=pdh->bufferLen;                                         //~v77dI~//~v77eM~
    pudl+=ctr;                                                     //~v77dI~
	UTRACED("pudl",pudl,UDIRLISTSZ);                            //~v77dI~//~v77eR~
    pde=0;                                                         //~v77eI~
    if (offs<buffsz)                                               //~v77dI~
    {                                                              //~v77dI~
	    pde=pdh->pde;                                                  //~v77dI~//~v77eI~
        memset(pde,0,sizeof(DIRENT));                              //~v77dR~
	    strcpy(pde->d_name,pudl->name);                            //~v77dI~
		UTRACED("%s:dirent",pde->d_name,sizeof(pde->d_name));          //~v77dI~
	    pdh->bufferOffs+=UDIRLISTSZ;                                //~v77dI~//~v77eR~
	    UTRACED("pde",pde,sizeof(DIRENT));                         //~v77eI~
    }                                                              //~v77dI~
  }                                                                //~v77eI~
    UTRACEP("%s:returned pde=%p,pdh->err(errno)=%d\n",UTT,pde,pdh->err);                       //~v77eR~//~vbyhR~
    return pde;                                                    //~v77dI~
}                                                                  //~v77dI~
//**********************************************************************//~v77ZI~
char *ufiledoc_cwd(unsigned char *Pbuff)                           //~v77ZI~
{                                                                  //~v77ZI~
	char *rc=0;                                                    //~v77ZI~
	if (*ScdShared)                                                //~v77ZI~
    {                                                              //~v77ZI~
    	strcpy(Pbuff,ScdShared);                                   //~v77ZI~
        rc=Pbuff;                                                  //~v77ZI~
    }                                                              //~v77ZI~
	UTRACEP("%s:rc=%s,ScdShared=%s\n",UTT,rc,ScdShared);           //~v77ZI~
    return rc;                                                     //~v77ZI~
}                                                                  //~v77ZI~
//**********************************************************************//~vc5rR~
char *ufiledoc_cwdReal(unsigned char *Pbuff)                       //~vc5rR~
{                                                                  //~vc5rR~
	char *rc=0;                                                    //~vc5rR~
	if (*ScdShared && *ScdSharedReal)                              //~vc5rR~
    {                                                              //~vc5rR~
    	strcpy(Pbuff,ScdSharedReal);                               //~vc5rR~
        rc=Pbuff;                                                  //~vc5rR~
    }                                                              //~vc5rR~
	UTRACEP("%s:rc=%s,ScdShared=%s,ScdSharedReal=%s\n",UTT,rc,ScdShared,ScdSharedReal);//~vc5rR~
    return rc;                                                     //~vc5rR~
}                                                                  //~vc5rR~
//**********************************************************************//~v77ZI~
int ufiledoc_chdir(int Popt,unsigned char *Ppath,int *Pprc)        //~v77ZI~
{                                                                  //~v77ZI~
	FILEFINDBUF3 ffb3;                                             //~v77ZI~
    int rc;                                                        //~v77ZR~
    *Pprc=0;                                                       //~v77ZI~
	UTRACEP("%s:entry path=%s,ScdShared=%s\n",UTT,Ppath,ScdShared);//~v77ZI~
	*ScdSharedReal=0;                                              //~vc5rR~
  	if (!IS_DOCPATH(Ppath))                                        //~v77ZI~
    {                                                              //~v77ZI~
		*ScdShared=0;                                              //~v77ZI~
        return 0;                                                  //~v77ZI~
    }                                                              //~v77ZI~
    rc=1;                                                          //~v77ZI~
	if (ufstatDoc(Ppath,&ffb3,0/*PswFindFirst*/))                  //~v77ZR~
    	*Pprc=ENOENT;                                              //~v77ZI~
    else                                                           //~v77ZI~
    if (!(ffb3.attrFile & FILE_DIRECTORY))                         //~v77ZI~
    	*Pprc=ENOTDIR;                                             //~v77ZI~
    else                                                           //~v77ZI~
    {                                                              //~v77ZI~
    	strcpy(ScdShared,Ppath);                                   //~v77ZI~
        if (*(ScdShared+strlen(ScdShared)-1)=='/')                 //~v77ZI~
	        *(ScdShared+strlen(ScdShared)-1)=0;                    //~v77ZI~
    }                                                              //~v77ZI~
    if (!(Popt & UCHD_NOMSG))		//not no errmsg option         //~v77ZI~
    	if (*Pprc)                                                 //~v77ZI~
	        uerrmsg("Set current directory failed for %s(rc=%d)",  //~v77ZI~
                "現行ディレクトリー設定の失敗(%s,rc=%d)",          //~v77ZI~
                Ppath,*Pprc);                                      //~v77ZI~
	ufiledoc_setArmPWD(Popt,Ppath);                                //~v786I~
	UTRACEP("%s:rc=%d,*Pprc=%d,ScdShared=%s\n",UTT,rc,*Pprc,ScdShared);//~v77ZI~
    return rc;                                                     //~v77ZI~
}                                                                  //~v77ZI~
//**********************************************************************//~v786I~
int ufiledoc_setArmPWD(int Popt,unsigned char *Ppath)              //~v786I~
{                                                                  //~v786I~
	char *path=0;                                                  //~v786I~
    int rc=0,rc2,len;                                                  //~v786I~//~vc5rR~
    char root[_MAX_PATH],*pwd=0;                                   //~v786I~
//***********************************************                  //~v786I~
	UTRACEP("%s:entry path=%s\n",UTT,Ppath);                       //~v786I~
  	if (!IS_DOCPATH(Ppath))                                        //~v786I~
        path=Ppath;                                                //~v786I~
    else                                                           //~v786I~
    {                                                              //~v786I~
		if (!ufile_getRealFullpath(Ppath,root))                    //~v786R~
        	path=root;                                             //~v786I~
    }                                                              //~v786I~
    if (path)                                                      //~v786I~
    {                                                              //~v786I~
    	len=(int)strlen(path)+8;                                   //~v786I~
        pwd=umalloc(len);                                          //~v786I~
        sprintf(pwd,"PWD=%s",path);                                //~v786I~
		putenv(pwd);                           //~vc1pR~           //~v786I~
        errno=0;                                                   //~vc5rR~
        rc2=chdir(path);                                           //~vc5rR~
        if (rc2)                                                   //~vc5rR~
        {                                                          //~vc5rR~
        	rc2=errno;                                             //~vc5rR~
	        uerrmsg("Set current directory failed for %s of %s(rc=%d)",//~vc5rR~
    	            "現行ディレクトリー設定の失敗(%s,rc=%d)",      //~vc5rR~
        	        path,Ppath,rc2);                               //~vc5rR~
	        rc=rc2;                                                //~vc5rR~
        }                                                          //~vc5rR~
        else                                                       //~vc5rR~
			strcpy(ScdSharedReal,path);                            //~vc5rR~
		UTRACEP("%s:rc2=%d,chdir path=%s,errno=%d\n",UTT,rc2,path,errno);//~vc5rR~
    }                                                              //~v786I~
	UTRACEP("%s:rc=%d,putenv=%s\n",UTT,rc,pwd);                    //~v786R~
    return rc;                                                     //~v786I~
}                                                                  //~v786I~
//**********************************************************************//~v77ZI~
//*set target document timestamp                                   //~v77ZI~
//*success for api>=30 for shortpath                               //~v77ZI~
//**********************************************************************//~v77ZI~
int ufiledoc_utimes(char *Pfnm,struct timeval *Ptv)                //~v77ZI~
{                                                                  //~v77ZI~
    char rpath[_MAX_PATH];                                         //~v77ZR~
    int rc=EINTR;                                                  //~v77ZI~
//******************************                                   //~v77ZI~
	UTRACEP("%s:entry fnm=%s,mtime=0x%lx,atime=0x%lx\n",UTT,Pfnm,Ptv[1],Ptv[0]);//~v77ZI~
    ufile_getRealFullpath(Pfnm,rpath);                             //~v77ZR~
    if (*rpath)                                                    //~v77ZR~
    {                                                              //~v77ZR~
        UTRACEP("%s:utimes rpath=%s\n",UTT,rpath);                 //~v77ZR~
        if (!utimes(rpath,Ptv))       //success                    //~v77ZR~
            rc=errno;                                              //~v77ZR~
    }                                                              //~v77ZR~
    else                                                           //~v77ZR~
        rc=0;   //not supported for documentfile except AllFiles   //~v77ZR~
	UTRACEP("%s:rc=%d\n",UTT,rc);                                  //~v77ZI~
    return rc;                                                     //~v77ZI~
}                                                                  //~v77ZI~
//**********************************************************************//~v77bI~
int ufiledoc_fclose(FILE *Pfh)                                      //~v77bR~
{                                                                  //~v77bI~
    PDOC_HANDLE pdh;                                               //~v77bI~
    int rc,ern;                                                     //~v77hI~
    int fno;                                                       //~v77hI~
//**************                                                   //~v77bI~
    UTRACEP("%s:pfh=%p\n",UTT,Pfh);                                //~v77bI~
    if (IS_DOCFH(Pfh))                                             //~v77bI~
    {                                                              //~v77bI~
	    UTRACEP("%s:fcloseDoc Pfh=%p\n",UTT,Pfh);                  //~v77hI~
	    pdh=(PDOC_HANDLE)Pfh;                                      //~v77bI~
		return ufile_closeDoc(pdh);                                //~v77bI~
	}                                                              //~v77bI~
#undef fclose                                                      //~v77bI~
	errno=0;                                                       //~v77hI~
    fno=fileno(Pfh);                                               //~v77hI~
	rc=fclose(Pfh);                                            //~v77bR~//~v77hR~
    ern=errno;                                                     //~v77hI~
    UTRACEP("%s:os fclose rc=%d,errno=%d,fh=%p,fileno=%d\n",UTT,rc,ern,Pfh,fno);//~v77hR~
    errno=ern;                                                     //~v77hI~
	return rc;                                                     //~v77hI~
}                                                                  //~v77bI~
//**********************************************************************//~v77bI~
int ufiledoc_ferror(FILE *Pfh)                                     //~v77bI~
{                                                                  //~v77bI~
    PDOC_HANDLE pdh;                                               //~v77bI~
//**************                                                   //~v77bI~
    UTRACEP("%s:pfh=%p\n",UTT,Pfh);                                //~v77bI~
    if (IS_DOCFH(Pfh))                                             //~v77bI~
    {                                                              //~v77bI~
	    pdh=(PDOC_HANDLE)Pfh;                                      //~v77bI~
		return 	pdh->err;                                          //~v77bI~
	}                                                              //~v77bI~
#undef ferror                                                      //~v77bI~
	return ferror(Pfh);                                            //~v77bI~//~v77hR~
}                                                                  //~v77bI~
//**********************************************************************//~v77bI~
size_t ufiledoc_fread(void *Pbuff,size_t Psize,size_t Pctr,FILE *Pfh)//~v77bI~
{                                                                  //~v77bI~
//**************                                                   //~v77bI~
    UTRACEP("%s:pfh=%p\n",UTT,Pfh);                                //~v77bI~
    if (IS_DOCFH(Pfh))                                             //~v77bI~
		return ufile_freadDoc(Pbuff,Psize,Pctr,Pfh);             //~v77bI~
#undef fread                                                       //~v77bI~
//  UTRACEP("%s:os fread pfh=%p,fileno=%d\n",UTT,Pfh,fileno(Pfh)); //~v77hR~
	return fread(Pbuff,Psize,Pctr,Pfh);                            //~v77bI~
}                                                                  //~v77bI~
//**********************************************************************//~v77dI~
char *ufiledoc_fgets(char *Pbuff,int Plen,FILE *Pfh)               //~v77bR~
{                                                                  //~v77bI~
//**************                                                   //~v77bI~
    UTRACEP("%s:pfh=%p\n",UTT,Pfh);                                //~v77bI~
    if (IS_DOCFH(Pfh))                                             //~v77bI~
		return ufile_fgetsDoc(Pbuff,Plen,Pfh);                     //~v77bI~
#undef fgets                                                       //~v77bR~
	return fgets(Pbuff,Plen,Pfh);                                  //~v77bR~
}                                                                  //~v77bI~
//**********************************************************************//~v77bI~//~v77dM~
int ufiledoc_closedir(void *Ppdirh)                                //~v77dI~
{                                                                  //~v77dI~
    PDOC_HANDLE pdh;                                               //~v77dI~
//**************                                                   //~v77dI~
    UTRACEP("%s:Ppdirh=%p\n",UTT,Ppdirh);                          //~v77dI~
    if (IS_DOCFH(Ppdirh))                                          //~v77dI~
    {                                                              //~v77dI~
	    pdh=(PDOC_HANDLE)Ppdirh;                                   //~v77dI~
		return ufile_closeDocDir(pdh);                            //~v77dI~//~v77iR~
	}                                                              //~v77dI~
	return ufiledoc_closedir_native((DIR*)Ppdirh);                 //~v77iI~
}                                                                  //~v77dI~
//**********************************************************************//~v77iI~
int ufiledoc_closedir_native(DIR *Ppdirh)                          //~v77iI~
{                                                                  //~v77iI~
    UTRACEP("%s:Ppdirh=%p\n",UTT,Ppdirh);                          //~v77iI~
#undef closedir                                                    //~v77dI~//~v77iM~
	return closedir((DIR*)Ppdirh);                                 //~v77iI~
}                                                                  //~v77iI~
//**********************************************************************//~v77iI~
PDIRENT ufiledoc_readdir(void *Ppdirh)                             //~v77iR~
{                                                                  //~v77iI~
    PDOC_HANDLE pdh;                                               //~v77iI~
//**************                                                   //~v77iI~
    UTRACEP("%s:Ppdirh=%p\n",UTT,Ppdirh);                          //~v77iI~
    if (IS_DOCFH(Ppdirh))                                          //~v77iI~
    {                                                              //~v77iI~
	    pdh=(PDOC_HANDLE)Ppdirh;                                   //~v77iI~
		return ufile_readdirDoc(pdh);                              //~v77iR~
	}                                                              //~v77iI~
	return ufiledoc_readdir_native((DIR*)Ppdirh);                  //~v77iI~
}                                                                  //~v77iI~
//**********************************************************************//~v77iI~
PDIRENT ufiledoc_readdir_native(DIR *Ppdirh)                       //~v77iR~
{                                                                  //~v77iI~
    UTRACEP("%s:Ppdirh=%p\n",UTT,Ppdirh);                          //~v77iI~
#undef readdir                                                     //~v77iI~
	return readdir((DIR*)Ppdirh);                                  //~v77iI~
}                                                                  //~v77iI~
