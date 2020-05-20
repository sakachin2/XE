//*CID://+vbq4R~:                             update#=  195;       //~vbq4R~
//*************************************************************
//*xedir.c                                                      //~5821R~
//* exec fname panel,end,cancel                                 //~v020R~
//*************************************************************
//vbq4:200515 (Bug)exe cmd abend at cmderr() when last is end cmd because it free Ppcw. have to chk UCWF3EXECMD on dir also//~vbq4I~
//vb80:170205 reduce dirlist sz                                    //~vb7hI~
//vb7h:170114 (BUG)0c4 when shortname is too long(UDHalias overflow)//~vb7hI~
//vb78:170104 dirload crash:appended \* to get dirlist overflow _MAX_MAT//~vb78I~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2q:160204 (Win:BUG)alias was not set for rootdir,so when opt LFN=off, select cmd fail by invalid fullpath name//~vb2qI~
//vb2o:160203 try to malloc UDHname for performance(#ifndef MMM)   //~vb2oI~
//vb11:150327 set nameW for root(it was not set by ufstat because rc=2 for rooot)//~vb11I~
//vb10:150327 for performance, UDHnameW malloc only when over limit size//~vb10I~
//vb06:150313 (BUG)others for \\.\; change strategy(del vb03 to vb05),set to UFHfilename without \\.\ ;//~vb06R~
//vb04:150313 (BUG)dirlist path level is +3 by \\.\ ptrfix for reserved name when it is adir//~vb04I~
//vay3:140819 (Bug)0c4 because no slink when member was changed to newly have slink//~vay3I~
//vavd:140421 (Win;BUG of vava) did not nameW for path entry of dirlist//~vavdI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vauE:140316 (Win)use ddfmt for dirlist;On cmd-prompt with setcp=65001,f2l dosenot change length but Windows display line shrinked//~vauEI~
//            use ddfmt to set USDfdata                            //~vauEI~
//vauD:140315 (Win BUG)Ctl+W(copyword to cmdline) from dirlist;keep original u8/lc and ignore kbd mode.//~vauDI~
//vau0:140223 (LNX:BUG)utf8 filename on dirlist,filename locale:de is invalid if f2l on locale=ja_jp//~vau0I~
//            use ddfmt to set USDfdata                            //~vau0I~
//vand:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~vandI~
//vaiv:130610 (LNX)slink copy like as W32                          //~vaivI~
//vait:130610 Junction/symlink support                             //~vaitI~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vac3:120210 (FTP:BUG)psftp losses uid/gid when dir list entry is updated (uid display mode)//~vac3I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          conv descname to locale if utf8                        //~va00I~
//          rename/move.. by filename of the codepage              //~va00I~
//          save CPxx to profile                                   //~va00I~
//v7am:081209 (BUG)wildcard mask not displayed for UNC name        //~v7amI~
//v7ak:081208 cause newfile if UNC name is netaddr only (missing share folder)//~v7akI~
//v7ae:081112 (BUG)time stamp of "." of dirlist is not same as of the dir//~v7aeI~
//v7ab:081107 (Win)remote filename convention support(\\ipaddr\...)//~v7abI~
//v731:061226 filesize>4GB support                                 //~v731I~
//v72r:061129 3270:initialy lineno display for TSO SPF             //~v717I~
//v717:060926 3270:dirlist support                                 //~v717I~
//v716:060926 3270:"listds" cmd to chk file exist/dsorg            //~v716I~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v59T:041207 dirlist resizeing                                    //~v59TI~
//v57f:040521 dirlist sort;dlcmd "-" with /ox option:x:Size,t:Time,n:Name//~v57fI~
//v55h:040214 (FTP)uid/gid display for remote file                 //~v55hI~
//v556:040202 (FTP:BUG)dir list attr is set to 0000 after remote file update//~v556I~
//v54m:040105 (FTP)update dir list file time when once browsed     //~v54mI~
//v54k:040105 (UNX,FTP)dirlist:display slink attr when expanded bt f11//~v54kI~
//v54e:040104 (UNX,FTP)dirlist:display slink size/ts when expanded bt f11//~v54eI~
//v540:031223 (WIN,UNX)set dir sepc on ufh                         //~v540I~
//v53Z:031223 (WIN,UNX)ftp support;no vfat alias(always long)      //~v53ZI~
//v53Q:031103 ftp support(4 byte udirlist attr for ! UNX);ulib:v59e//~v53QI~
//v51A:030711 abend when start screen size is narrow               //~v51AI~
//v500:021123 (WXE:BUG)dir list hdr line width is too short when screen is wide//~v500I~
//v500:021116 (WXE)dir plh length should not by scrwidth           //~v500I~
//v49g:020713 (UNX)list special file also to dir list(fifo.socket,char/blk device)//~v49gI~
//v48n:020518 (LNX)mdos support file name is not 8.3/              //~v48nI~
//v48e:020501 (UNX)mdos file name is 8.3 case insensitive          //~v48eI~
//v40t:010616 LNX:slink name display                               //~v40tI~
//v19X:000928 LINUX support(save uid/gid on UFILEH/UDIRH)          //~v19XI~
//v19V:000928 LINUX support("*" mean all member,"*.*" require intermediate ".";//~v19VI~
//            under windows those are same effect)                 //~v19VI~
//            udirlist use ufileeditname(of windows logic),so no bad effect but correct//~v19VI~
//v19u:000923 LINUX support(dir list by longfilename fmt(not 8.3)) //~v19uI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v137:991003 scroll down when reached to bottom line by field full on dir list//~v137I~
//v11z:990821 support filename=* (last closed file) on cmd line    //~v11zI~
//v10r:990327 display lineno on dir list,accum size/line cnt to dir line//~v10rI~
//v0k1:980919 (BUG)windows allow filename ".aaa" or "..aaa"        //~v0k1I~
//v0fr:971109 dir list sort by fully for longname                  //~v0frI~
//v0fo:971106 (GCC:W32)ugetvfatalias new option parm               //~v0feI~
//v0fe:971019 (w95/GCC)deney v0fd;copy etc need keep long filename.//~v0fdI~
//                     long name and short name is kept.           //~v0fdI~
//v0fd:971018 (w95/GCC)udhname is long or short,but only one of them is needed.//~v0fdI~
//v0fb:971018 UFHshortname for W95/GCC for path display on dirlist //~v0faI~
//v0fa:971017 fatname from udhalias for w95/gcc under no LFN mode  //~v0faI~
//v0f0:971010 long filename support                                //~v0f0I~
//            dir.c     ;hpfs id on pfh                            //~v0f0I~
//                      ;win95 lfn                                 //~v0f0I~
//v09z:970425:dir upctr tell to parent dir list                    //~v09zR~
//v09y:970525:(BUG)need view Q when del dir line,if not ABEND      //~v09yR~
//v08c:961104:(BUG)capreset must be executed before plh free       //~v08cI~
//                 must be call not from deqcw but from end/cancel //~v08cI~
//v085:961024:W95 VC                                               //~v085I~
//v081:960906:(BUG)free err when storage shortage at dirload       //~v081I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07q:960720:(BUG)root dir may contain .. or . entry when dosfind //~v07qI~
//            g:\ has no .. or . but r:\ has .. and .              //~v07qI~
//v07l:960713:(BUG)also for other than PATHLEn(strpbrk,strchr etc) //~v07lI~
//v05P:960120:(BUG)-(expand) dose'nt update tyep,caused "it is dir" msg//~v05PI~
//            for type is file on list (but actualy dir)        //~v05PI~
//v05K:960107:path id(:) for also edit/bowse dir                //~v05KI~
//v05G:960105:update time stamp of dir list when edit saved(add to v04j)//~v05GI~
//            change interface of dlcgetfullname(plc-->pdh parm)//~v05GI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v048:950924:dir renum from current line(performance)          //~v048I~
//v046:950923:view dir lcmd(dlcmd q)                            //~v046I~
//v03u:950903:rename data save(free it when plhfree)            //~5903I~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~5827I~
//            lcmd input from other side of same pfc.           //~5827I~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~5827I~
//*v030:950709:dir2                                             //~v030I~
//*v020:950610:new dir support                                  //~v030R~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
	#ifdef W32                                                     //~v085I~
    	#include <dos.h>                                           //~v085I~
//  	#include <windows.h>                                       //~v085I~
	#else                                                          //~v085I~
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
	#endif                                                         //~v085I~
#endif
#ifdef LNX                                                         //~v54mI~
    #include <sys/stat.h>                                          //~v54mI~
#endif                                                             //~v54mI~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>
#include <ufile.h>
#include <ufile4.h>                                                //~v0f0I~
#include <ufile5.h>     //ugetvfatalias                            //~v0faI~
#include <ustring.h>                                               //~v07lR~
#include <uftp.h>                                                  //~v54mI~
#include <utrace.h>                                                //~vb2oI~
//#include <ufilew.h>                                                //~vb04I~//~vb06R~

#include "xe.h"
#include "xescr.h"
#include "xecsr.h"                                                 //~v137I~
#include "xefile.h"
#include "xefile2.h"                                            //~v020I~
#include "xefile3.h"                                               //~v137I~
#ifdef UTF8SUPPH                                                   //~va00I~
#include "xefile5.h"                                               //~va00I~
#endif                                                             //~va00I~
#include "xedir.h"
#include "xedir2.h"
#ifdef UTF8SUPPH                                                   //~va00I~
#include "xedir4.h"                                                //~va00I~
#endif                                                             //~va00I~
#include "xepan.h"
#include "xesub.h"                                              //~5812I~
#include "xecap.h"                                                 //~v08cI~
#include "xeini3.h"                                                //~v11zI~
#include "xefunc.h"                                                //~v137I~
#include "xefunc2.h"                                               //+vbq4I~
#include "xetso.h"                                                 //~v716I~
//****************************************************************
int dirclosefree(PUFILEC Ppfc);
PULINEH diralloclh(UCHAR Ptype,int Pdatalen);
int dirplhfail(PUDIRLIST Ppudirlist);                           //~v04dI~
void dirfree(PUFILEH Ppfh);
//int dirlvlfname(UCHAR *Pfullpath,int Plevel,UCHAR *Pfname,int *Plen);//~v540R~
//int dirlvlfname(PUFILEH Ppfh,UCHAR *Pfullpath,int Plevel,UCHAR *Pfname,int *Plen);//~v540I~//~vb7hR~
int dirlvlfname(PUFILEH Ppfh,UCHAR *Pfullpath,int Plevel,UCHAR *Pfname,size_t Pbuffsz,int *Plen);//~vb7hI~
int dirlvlfname0(PUFILEH Ppfh,int Plevel,PUDIRLH Ppdh,int *Plen);  //~v0feI~
//int dirgetfstat(UCHAR *Ppathname,int Plevel,PUDIRLIST Ppudirlist);//~v540R~
//int dirgetfstat(PUFILEH Ppfh,UCHAR *Ppathname,int Plevel,PUDIRLIST Ppudirlist);//~v540I~//~v7abR~
//int dirgetfstat(int Popt,PUFILEH Ppfh,UCHAR *Ppathname,int Plevel,PUDIRLIST Ppudirlist);//~v7abI~//~vavdR~
//#define DGFSO_PATH    0x01     //fstat for intermediate path       //~v7abI~//~vavdR~
//****************************************************************
//****************************************************************//~5820M~
// func_end_dir                                                 //~5820M~
//* end command                                                 //~5820M~
//*ret  :0,-1(quit)                                             //~5820M~
//****************************************************************//~5820M~
int func_end_dir(PUCLIENTWE Ppcw)                               //~5820M~
{                                                               //~5820M~
	int rc;                                                     //~5820M~
	PUFILEC pfc;                                                //~5820M~
	PUFILEH pfh;                                                   //~v09zI~
//***************                                               //~5820M~
	if (UCBITCHK(Ppcw->UCWflag3,UCWF3EXECMD))	//execmd owner     //~vbq4I~
    	return funcerrexecmdinprog();  //dont free pcw             //~vbq4I~
	rc=0;                                                       //~5820M~
	pfc=Ppcw->UCWpfc;                                           //~5820M~
	pfh=pfc->UFCpfh;                                               //~v09zI~
    if (pfh->UFHupctr)                                             //~v09zR~
        UCBITON(pfc->UFCflag,UFCFENDSAVE);  //tellto dlcmddeqpfc   //~v09zR~
	inisavelastfile(pfc);                                          //~v11zI~
	dirclosefree(pfc);                                          //~5820M~
	if (!filepopup(Ppcw))	//no stacked client                 //~5820M~
		return -1;			//quit                              //~5820M~
	return rc;                                                  //~5820M~
}//func_end_dir                                                 //~5820M~
                                                                //~5820M~
//****************************************************************//~5820M~
// func_cancel_dir                                              //~5820M~
//*cancel command                                               //~5820M~
//*ret  :0,-1(quit)                                             //~5820M~
//****************************************************************//~5820M~
int func_cancel_dir(PUCLIENTWE Ppcw)                            //~5820M~
{                                                               //~5820M~
	PUFILEC pfc;                                                //~5820M~
	PUFILEH pfh;                                                   //~v09zI~
//***************                                               //~5820M~
	if (UCBITCHK(Ppcw->UCWflag3,UCWF3EXECMD))	//execmd owner     //~vbq4I~
    	return funcerrexecmdinprog();  //dont free pcw             //~vbq4I~
	pfc=Ppcw->UCWpfc;                                           //~5820M~
	pfh=pfc->UFCpfh;                                               //~v09zI~
    if (pfh->UFHupctr)                                             //~v09zM~
        UCBITON(pfc->UFCflag,UFCFENDSAVE);  //tellto dlcmddeqpfc   //~v09zM~
	inisavelastfile(pfc);                                          //~v11zI~
	dirclosefree(pfc);			//free lineh/undoh              //~5820M~
	if (!filepopup(Ppcw))	//no stacked client                 //~5820M~
		return -1;			//quit                              //~5820M~
	return 0;                                                   //~5820M~
}//func_cancel_dir                                                 //~v11zR~
                                                                //~5820M~
//****************************************************************
//!dirload
//*read file and create file hdr(enq line data)
//*parm1:pcw
//*parm2:pfh
//*rc   :rc UALLOC_FAILED if storage shortage                   //~v04dR~
//****************************************************************
int dirload(PUCLIENTWE Ppcw,PUFILEH Ppfh)
{
    UCHAR   *pc;                                                //~5812R~
//  UCHAR   dirname[_MAX_PATH]; //for udirlist                     //~vb78R~
    UCHAR   dirname[_MAX_PATH+8]; //for udirlist                   //~vb78I~
	PUDIRLIST pudirlist,pudirlist0;                             //~v030R~
	int  	filectr,ii,dirlevel;                                //~v030R~
    int pos;                                                       //~v540I~
#if defined(W32) || defined(DPMI)                                  //~v0feI~
    int shortlen;                                                  //~v0faI~
#endif                                                             //~v0feI~
	PULINEH plh,plht;                                           //~5812R~
#ifdef FTPSUPP                                                     //~v72rI~
	PULINEH plhc=0;                                                //~v72rI~
#endif                                                             //~v72rI~
	PUDIRLH pdh,pdhp=0,pdhc=0;                                  //~v030I~
//  UDIRLIST udirlwk;                                           //~5812I~//~vandR~
//  UDIRLIST_WK(udirlwk,wkslinkname);                              //~vandI~//~vb80R~
    UDIRLIST_WK(udirlwk,wkname,wknamew,wkslinkname);               //~vb80R~
static char Sfhdrline[]="********** TOP OF LIST *";             //~v030I~
static char Sftrlline[]="********** END OF LIST *";             //~v020R~
static char Stlineno []="*****|";                               //~v048R~
//****************************
//    if (UCBITCHK(Ppfh->UFHflag7,UFHF7TSO))                       //~v716R~
//    {                                                            //~v716R~
//        uerrmsg("Dirlist for TSO PDS is not supported yet",0);   //~v716R~
//        return 4;                                                //~v716R~
//    }                                                            //~v716R~
    strcpy(dirname,Ppfh->UFHfilename);	//long name                //~v0feR~
#ifdef OS2                                                         //~v0fdR~
    if (ufileishpfs(*dirname))                                     //~v0faM~
        UCBITON(Ppfh->UFHflag4,UFHF4LFN);  //hpfs drive            //~v0faR~
#endif                                                             //~v0faM~
#if defined(W32) || defined(DPMI)                                  //~v0faI~
  if (FILEISREMOTE(Ppfh))                                          //~v53ZR~
  	UCBITON(Ppfh->UFHflag4,UFHF4LFN);  //no alias for remote(use long filename)//~v53ZI~
  else                                                             //~v53ZI~
  {                                                                //~v53ZI~
    shortlen=ugetvfatalias(UGVFA_WILDCARD,dirname,Ppfh->UFHshortname,sizeof(Ppfh->UFHshortname));//~v0feR~
    if (!shortlen || shortlen>=(int)sizeof(Ppfh->UFHshortname))    //~v0faR~
    	return 4;                                                  //~v0faI~
	if (!UCBITCHK(Gopt3,GOPT3W95ALIAS))                            //~v0feR~
        UCBITON(Ppfh->UFHflag4,UFHF4LFN);  //hpfs drive            //~v0faI~
  }                                                                //~v53ZI~
#endif                                                             //~v0faI~
#ifdef UNX                                                         //~v19uI~
 #ifdef AIX                                                        //~v48nI~
  if (!UCBITCHK(Ppfh->UFHflag5,UFHF5MDOS))//not mdos disk          //~v48eI~
 #endif      //LNX support long name for mdos disk                 //~v48nI~
    UCBITON(Ppfh->UFHflag4,UFHF4LFN);  //not 8.3 fmt               //~v19uI~
#endif                                                             //~v19uI~
    if (!strpbrk(dirname,"*?"))//not wild card                  //~5813R~
    {                                                              //~v53QI~
#ifdef FTPSUPP                                                     //~v717I~
      if (!FILEISTSO(Ppfh))                                        //~v716R~
      {                                                            //~v716I~
#endif                                                             //~v717I~
        if (PATHLEN(dirname)==(int)strlen(dirname))//not dbcs 2nd byte//~v085R~
//        	strcat(dirname,"*.*");                                 //~v19VR~
          	strcat(dirname,DIR_ALLMEMB);	//*(UNIX) or *.*(OTHER)//~v19VI~
        else                                                    //~v030I~
        {                                                          //~v540I~
//        	strcat(dirname,"\\*.*");                               //~v19aR~
//        	strcat(dirname,DIR_SEPS "*.*");                        //~v19VR~
//        	strcat(dirname,DIR_SEPS DIR_ALLMEMB);                  //~v540R~
            pos=(int)strlen(dirname);                              //~v57fR~
            *(dirname+pos++)=Ppfh->UFHdirsepc;                     //~v540I~
            strcpy(dirname+pos,DIR_ALLMEMB);                       //~v540I~
        }                                                          //~v540I~
#ifdef FTPSUPP                                                     //~v717I~
      }                                                            //~v716I~
#endif                                                             //~v717I~
    }//not wild                                                    //~v53QI~
                                                                //~v030I~
	filectr=dirgetlist(Ppfh,dirname,0,&pudirlist0);//name seq or longfname seq//~v0frR~
    if (filectr<0)	//err
    	return 4;
	dirlevel=(int)Ppfh->UFHlevel;                               //~5813R~
//top line
//#ifdef WXE                                                       //~v51AR~
//  plht=plh=diralloclh(ULHTHDR,UDIRLDSZ);                         //~v500R~
    plht=plh=diralloclh(ULHTHDR,MAXCOLUMN);                        //~v500I~
//#else                                                            //~v51AR~
//	plht=plh=diralloclh(ULHTHDR,Gscrwidth-UDHLINENOSZ);            //~v51AR~
//#endif                                                           //~v51AR~
    UALLOCCHK(plh,dirplhfail(pudirlist0));                      //~v04dI~
	pc=plh->ULHdata;
//#ifdef WXE                                                       //~v51AR~
  	memset(pc,'*',MAXCOLUMN);		//clear by '*'                 //~v500I~
//#else                                                            //~v51AR~
//  	memset(pc,'*',(UINT)(Gscrwidth-UDHLINENOSZ));		//clear by '*'//~v51AR~
//#endif                                                           //~v51AR~
	memcpy(pc,Sfhdrline,strlen(Sfhdrline)-1);	//except last null
	strcpy(plh->ULHlineno,Stlineno);                            //~v030R~
	UENQ(UQUE_END,&Ppfh->UFHlineque,plh);                       //~v020R~

//enq parent entry for root/wild card case                      //~5812I~
//  if (*pudirlist0->name!='.'  	//no cd/parent entry           //~v0k1I~
	if ((   strcmp(pudirlist0->name,".")      //not current        //~v0k1I~
	     && strcmp(pudirlist0->name,"..")  )  //and not parent     //~v0k1I~
    ||  !dirlevel)                  //root dir                     //~v07qI~
    {                                                           //~5812I~
//  	memset(&udirlwk,0,UDIRLISTSZ);                          //~5812R~//~vandR~
//  	UDIRLIST_WK_INIT(udirlwk,wkslinkname);                     //~vandI~//~vb80R~
    	UDIRLIST_WK_INIT(udirlwk,wkname,wknamew,wkslinkname);      //~vb80R~
//      dirgetfstat(dirname,dirlevel,&udirlwk);	//set fstat3 of cd //~v540R~
#ifdef FTPSUPP                                                     //~v717I~
      if (FILEISTSO(Ppfh))                                         //~v717I~
      {                                                            //~v717I~
        if (UCBITCHK(Ppfh->UFHflag7,UFHF7PDSMEMBER))//mebername wildcard//~v717R~
        {                                                          //~v717I~
//        	Ppfh->UFHattr=pudirlist0->attr&~FILE_PDSMEMB;          //~vb06R~
          	Ppfh->UFHattr=pudirlist0->attr&(ULONG)(~FILE_PDSMEMB); //~vb06I~
        	udirlwk.attr=Ppfh->UFHattr|FILE_DIRECTORY;             //~v717R~
        	udirlwk.srcattr=pudirlist0->srcattr;	//lrecl/blksz  //~v717R~
        }                                                          //~v717I~
        else                                                       //~v717I~
        {                                                          //~v717I~
//      	Ppfh->UFHattr=(pudirlist0->attr|FILE_DSNPATH)&~(FILE_DIRECTORY|FILE_PO|FILE_PS);//~vb06R~
        	Ppfh->UFHattr=(pudirlist0->attr|FILE_DSNPATH)&(ULONG)(~(FILE_DIRECTORY|FILE_PO|FILE_PS));//~vb06I~
        	udirlwk.attr=Ppfh->UFHattr;                            //~v717I~
        }                                                          //~v717I~
      }                                                            //~v717I~
      else                                                         //~v717I~
#endif                                                             //~v717I~
//      dirgetfstat(Ppfh,dirname,dirlevel,&udirlwk);	//set fstat3 of cd//~v540I~//~v7abR~
        dirgetfstat(0,Ppfh,dirname,dirlevel,&udirlwk);	//set fstat3 of cd//~v7abI~
//  	strcpy(udirlwk.name,".");	//current dir               //~5812R~//~vb80R~
    	udirlist_setname(0,&udirlwk,".",0);	//current dir          //~vb80R~
		plh=dirsetdata(dirlevel,&udirlwk,Ppfh);                    //~v0fdR~
	    UALLOCCHK(plh,dirplhfail(pudirlist0));                  //~v04dI~
		pdh=UGETPDH(plh);                                       //~5812I~
#ifdef FTPSUPP                                                     //~v72rI~
        if (FILEISTSO(Ppfh))                                       //~v72rI~
    	    if (pdh->UDHattr & FILE_SPFDS)                         //~v72rI~
	    		UCBITON(pdh->UDHflag2,UDHF2DISPLC);	//initialy line count display//~v72rI~
#endif                                                             //~v72rI~
//#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~//~v7amR~
//      if (!WIN_ISREMOTEPATH(Ppfh->UFHfilename)) //avoid set rename field with widlcard name//~v7abR~//~v7amR~
//#endif                                                             //~v7abI~//~v7amR~
        pdh->UDHtype=UDHTDIREXPMASK;//set to DIREXP at draw     //~5812I~
//   	dirlvlfname(dirname,dirlevel,pdh->UDHname,0);              //~v0feR~
     	dirlvlfname0(Ppfh,dirlevel,pdh,0);                         //~v0feI~
		UENQ(UQUE_END,&Ppfh->UFHlineque,plh);                   //~5812I~
        pdhc=pdh;	//parent of member                          //~5812I~
#ifdef FTPSUPP                                                     //~v72rI~
        plhc=plh;	//parent of member                             //~v72rI~
#endif                                                             //~v72rI~
	}//no cd/parent entry                                       //~5812I~
    else    //parent entry on first                             //~5812I~
    {                                                           //~5812I~
//      dirgetfstat(dirname,dirlevel-1,pudirlist0);	//set fstat3 of pd//~v540R~
#ifdef FTPSUPP                                                     //~v717I~
      if (!FILEISTSO(Ppfh))                                        //~v717R~
#endif                                                             //~v717I~
//      dirgetfstat(Ppfh,dirname,dirlevel-1,pudirlist0);	//set fstat3 of pd//~v540I~//~v7abR~
        dirgetfstat(DGFSO_PATH,     //fstat for intermediate path  //~v7abI~
                    Ppfh,dirname,dirlevel-1,pudirlist0);	//set fstat3 of pd//~v7abI~
//  	strcpy(pudirlist0->name,"..");	//yet need ..           //~5812R~//~vb80R~
    	udirlist_setname(0,pudirlist0,"..",0);	//yet need ..      //~vb80R~
    }                                                           //~5812I~
//enq file data
	for (ii=0,pudirlist=pudirlist0;ii<filectr;ii++,pudirlist++)	//until eof/err//~v030R~
	{
		if (!dirlevel					//root dir                 //~v07qI~
//  	&&  *pudirlist->name=='.')		//parent or self           //~v0k1I~
	    && (  !strcmp(pudirlist->name,".")      //current          //~v0k1I~
	       || !strcmp(pudirlist->name,"..")  ) )//or parent        //~v0k1R~
			continue;					//already inseted entr     //~v07qR~
	    if (!strcmp(pudirlist->name,"."))     //timestamp of "." os not of the dir//~v7aeR~
        {                                                          //~v7aeI~
            pudirlist->date=Ppfh->UFHfiledate;                     //~v7aeI~
            pudirlist->time=Ppfh->UFHfiletime;                     //~v7aeI~
        }                                                          //~v7aeI~
		plh=dirsetdata(dirlevel,pudirlist,Ppfh);                   //~v0fdR~
		UALLOCCHK(plh,dirplhfail(pudirlist0));                  //~v04dI~
		pdh=UGETPDH(plh);                                       //~v030I~
#ifdef FTPSUPP                                                     //~v72rR~
        if (FILEISTSO(Ppfh))                                       //~v72rI~
    	    if (pdh->UDHattr & FILE_SPFDS)                         //~v72rR~
	    		UCBITON(pdh->UDHflag2,UDHF2DISPLC);	//initialy line count display//~v72rR~
#endif                                                             //~v717I~
		if ((int)pdh->UDHlevel<dirlevel)	//parent            //~5815R~
	    {                                                       //~v030I~
	    	pdhp=pdh;					//parent pdh            //~v030I~
//          dirlvlfname(dirname,pdh->UDHlevel,pdh->UDHname,0);     //~v0feR~
            dirlvlfname0(Ppfh,pdh->UDHlevel,pdh,0);                //~v0feI~
    	}                                                       //~v030I~
        else                                                    //~v030I~
			if ((int)pdh->UDHlevel==dirlevel)	//cur dir       //~5815R~
	        {                                                   //~v030I~
		    	pdhc=pdh;					//parent pdh        //~v030I~
#ifdef FTPSUPP                                                     //~v72rI~
        		plhc=plh;	//parent of member                     //~v72rI~
#endif                                                             //~v72rI~
				pdh->UDHdirptr=pdhp;	//parent                //~v030I~
//              dirlvlfname(dirname,pdh->UDHlevel,pdh->UDHname,0); //~v0feR~
    	        dirlvlfname0(Ppfh,pdh->UDHlevel,pdh,0);            //~v0feI~
    	    }                                                   //~v030I~
            else						//member                //~v030I~
            {                                                      //~v10rI~
				pdh->UDHdirptr=pdhc;	//parent                //~v030I~
                if (pdhc)                                          //~v10rI~
                	pdhc->UDHsize+=pdh->UDHsize;                   //~v10rI~
#ifdef FTPSUPP                                                     //~v72rI~
        		if (FILEISTSO(Ppfh))                               //~v72rI~
                	if (plhc)                                      //~v72rI~
                    {                                              //~v72rI~
                		plhc->ULHlinenow+=plh->ULHlinenow;	//linectr//~v72rI~
    					UCBITON(pdhc->UDHflag2,UDHF2LCGOTTEN);     //~v72rI~
                    }                                              //~v72rI~
#endif                                                             //~v72rI~
            }                                                      //~v10rI~
                                                                //~v030I~
		UENQ(UQUE_END,&Ppfh->UFHlineque,plh);                   //~v020R~
	}
//*enq path file name                                            //~5812I~//~vavdR~
    if (pdhp)		//parent inserted                           //~5812R~
    	dirlevel--;	//insert parent of parent                   //~5812I~
    else                                                        //~5812I~
        pdhp=pdhc;  //child pdh                                 //~5812I~
	for (ii=dirlevel;ii;ii--)                                   //~5812I~
    {                                                           //~5812I~
//  	memset(&udirlwk,0,UDIRLISTSZ);                          //~5812R~//~vandR~
//  	UDIRLIST_WK_INIT(udirlwk,wkslinkname);                     //~vandI~//~vb80R~
    	UDIRLIST_WK_INIT(udirlwk,wkname,wknamew,wkslinkname);      //~vb80R~
//      dirgetfstat(dirname,ii-1,&udirlwk);	//set fstat3 of parent //~v540R~
#ifdef FTPSUPP                                                     //~v717I~
      if (FILEISTSO(Ppfh))                                         //~v717R~
      	udirlwk.attr=Ppfh->UFHattr|FILE_DSNPATH;                   //~v717R~
      else                                                         //~v717I~
#endif                                                             //~v717I~
//      dirgetfstat(Ppfh,dirname,ii-1,&udirlwk);	//set fstat3 of parent//~v540I~//~v7abR~
        dirgetfstat(DGFSO_PATH,     //fstat for intermediate path  //~v7abI~
                    Ppfh,dirname,ii-1,&udirlwk);	//set fstat3 of parent//~v7abI~
//  	strcpy(udirlwk.name,"..");	//parent dir id             //~5812R~//~vb80R~
    	udirlist_setname(0,&udirlwk,"..",0);	//parent dir id    //~vb80R~
		plh=dirsetdata(ii,&udirlwk,Ppfh);                          //~v0fdR~
		UALLOCCHK(plh,dirplhfail(pudirlist0));                  //~v04dI~
		pdh=UGETPDH(plh);                                       //~5812R~
//   	dirlvlfname(dirname,ii-1,pdh->UDHname,0);                  //~v0feR~
    	dirlvlfname0(Ppfh,ii-1,pdh,0);                             //~v0feI~
		UENQENT(UQUE_AFT,plht,plh);	//after top of line         //~5812R~
        pdhp->UDHdirptr=pdh;    //parent ptr                    //~5812I~
        pdhp=pdh;    			//new chile                     //~5812I~
	}                                                           //~5812I~

//end of line
//#ifdef WXE                                                       //~v51AR~
//  plh=diralloclh(ULHTHDR,UDIRLDSZ);                              //~v500R~
    plh=diralloclh(ULHTHDR,MAXCOLUMN);                             //~v500I~
//#else                                                            //~v51AR~
//	plh=diralloclh(ULHTHDR,Gscrwidth-UDHLINENOSZ);                 //~v51AR~
//#endif                                                           //~v51AR~
	UALLOCCHK(plh,dirplhfail(pudirlist0));                      //~v04dI~
	pc=plh->ULHdata;
//#ifdef WXE                                                       //~v51AR~
  	memset(pc,'*',MAXCOLUMN);		//clear by '*'                 //~v500I~
//#else                                                            //~v51AR~
// 	memset(pc,'*',(UINT)(Gscrwidth-UDHLINENOSZ));		//clear by '*'//~v51AR~
//#endif                                                           //~v51AR~
	memcpy(pc,Sftrlline,strlen(Sftrlline)-1);	//except last null
	strcpy(plh->ULHlineno,Stlineno);                            //~v030I~
	UENQ(UQUE_END,&Ppfh->UFHlineque,plh);                       //~v020R~

    dirrenum(plht);     //renumbering from top                  //~v048R~
//  ufree(pudirlist0);                                             //~vandR~
    UDIRLIST_FREE(pudirlist0);                                     //~vandI~
#ifdef UTF8SUPPH                                                   //~va00I~
    fileupdateprofile(0,Ppcw,Ppfh);                                //~va00I~
#endif                                                             //~va00I~
	return 0;
}//dirload
                                                                //~v04dI~
//****************************************************************//~v04dI~
//!dirplhfail                                                   //~v04dI~
//*free udirlist and return rc                                  //~v04dI~
//*parm1:pudirlist                                              //~v04dI~
//*ret  :UALLOC_FAILED                                          //~v04dI~
//****************************************************************//~v04dI~
int dirplhfail(PUDIRLIST Ppudirlist)                            //~v04dI~
{                                                               //~v04dI~
//  ufree(Ppudirlist);                                          //~v04dI~//~vandR~
    UDIRLIST_FREE(Ppudirlist);                                     //~vandI~
    return UALLOC_FAILED;                                       //~v04dI~
}//                                                             //~v04dI~

//****************************************************************//~v030I~
//!dirgetlist                                                   //~v030I~
//*create sorted dirlist(parent,current then other)             //~v030I~
//*parm1:pfh                                                       //~v0frR~
//*parm2:filename and mask                                         //~v0frI~
//*parm3:option(select file type)                                  //~v0frR~
//*parm4:pudirlist ptr                                             //~v0frR~
//*ret  :file ctr or -1(if err)                                 //~v030I~
//****************************************************************//~v030I~
int dirgetlist(PUFILEH Ppfh,UCHAR *Pfilemask,UINT Popt,PUDIRLIST *Pppudirlist)//~v0frR~
{                                                               //~v030I~
	UINT    option;                                             //~v030I~
    int 	filectr,ii;                                         //~v030I~
	PUDIRLIST pudirlist,pudirlist0;                             //~v030I~
//  UDIRLIST udirlwk;                                           //~v030M~//~vb80R~
    int sortorder;                                                 //~v0frI~
//****************************                                  //~v030I~
    sortorder=(int)((Popt & DGLO_SORTOPT)>>8);                     //~v57fR~
//  Popt &=~DGLO_SORTOPT;	//drop sort option parm                //~vb06R~
//  Popt &=(ULONG)(~DGLO_SORTOPT);	//drop sort option parm        //~vb06I~//~vb2ER~
    Popt &=(UINT)(~DGLO_SORTOPT);	//drop sort option parm        //~vb2EI~
	if (!(option=Popt))                                         //~v030R~
#ifdef UNX                                                         //~v49gI~
		option=FILE_ALLSP;      //include also special file        //~v49gI~
#else                                                              //~v49gI~
		option=FILE_NORMAL                                      //~v030I~
       	  		| FILE_READONLY                                 //~v030I~
         		| FILE_HIDDEN                                   //~v030I~
         		| FILE_SYSTEM                                   //~v030I~
         		| FILE_DIRECTORY                                //~v030I~
         		| FILE_ARCHIVED;                                //~v030I~
#endif                                                             //~v49gI~
//#if !defined(DOS) || defined(DPMI)                               //~v0k1R~
  if (sortorder)//default use                                      //~v57fR~
  {                                                                //~v57fI~
    if (sortorder & UDHSOREVERSE)                                  //~v57fI~
        sortorder=-(sortorder & ~UDHSOREVERSE);                    //~v57fI~
  }                                                                //~v57fI~
  else                                                             //~v57fI~
  {                                                                //~v57fI~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4LFN))  //lfn                  //~v0frI~
    	sortorder='L';                                             //~v0frI~
	else                                                           //~v0frI~
//#endif                                                           //~v0k1R~
    	sortorder='N';                                             //~v0frI~
  }                                                                //~v57fI~
//  printf("sortorder=%c\n",sortorder);                            //~v0k1R~
//  filectr=udirlist(Pfilemask,option,&pudirlist,'N');//name seq   //~v0frR~
    filectr=udirlist(Pfilemask,option,&pudirlist,sortorder);//name seq//~v0frI~
    if (filectr<0)	//err                                       //~v030I~
    	return -1;                                              //~v030I~
	pudirlist0=pudirlist;   //save top                          //~v030I~
//  move parent to top                                          //~v030I~
	for (ii=0;ii<filectr;ii++,pudirlist++)	//until eof/err     //~v030I~
		if (!strcmp(pudirlist->name,".."))                      //~v030I~
			break;                                              //~v030I~
	if (ii<filectr && ii)	//found and not top                 //~v030I~
    {                                                           //~v030I~
//  	udirlwk=*pudirlist0;   	//save top                      //~v030I~//~vb80R~
//  	*pudirlist0=*pudirlist; //top is parent                 //~v030I~//~vb80R~
//  	*pudirlist=udirlwk;         //second is current         //~v030I~//~vb80R~
    	ufile_udirlist_swap(0,pudirlist,pudirlist0); //second is current//~vb80R~
    }                                                           //~v030I~
    *Pppudirlist=pudirlist0;                                    //~v030R~
	return filectr;   //restore                                 //~v030I~
}//dirgetlist                                                   //~v030I~
//****************************************************************//~5812I~
//!dirgetfstat                                                  //~5812I~
//*get dir fstat3                                               //~5812I~
//*parm1:path name                                              //~5812I~
//*parm2:dir level                                              //~5812R~
//*parm3:pudirlist ptr                                          //~5812I~
//*ret  :rc                                                     //~5812I~
//****************************************************************//~5812I~
//int dirgetfstat(PUFILEH Ppfh,UCHAR *Ppathname,int Plevel,PUDIRLIST Ppudirlist)//~v540R~//~v7abR~
int dirgetfstat(int Popt,PUFILEH Ppfh,UCHAR *Ppathname,int Plevel,PUDIRLIST Ppudirlist)//~v7abI~
{                                                               //~5812I~
	FILEFINDBUF3 fstat3;                                        //~5812I~
    int len,rc;                                                 //~5812I~
    UCHAR  delmsv;                                              //~5812I~
    int opt=FFNODIRMSG;                                            //~v7abI~
#ifdef W32                                                         //~vb11I~
    int swroot;                                                    //~vb11I~
    UWCH wkwch[8];                                                 //~vb7hI~
#endif                                                             //~vb11I~
//****************************                                  //~5812I~
//  dirlvlfname(Ppathname,Plevel,0,&len);//get path len            //~v540R~
//  dirlvlfname(Ppfh,Ppathname,Plevel,0,&len);//get path len       //~v540I~//~vb7hR~
    dirlvlfname(Ppfh,Ppathname,Plevel,0/*no output*/,0/*buffsz*/,&len);//get path len//~vb7hI~
    delmsv=*(Ppathname+len);                                    //~5812I~
    *(Ppathname+len)=0;                                         //~5812I~
#ifdef W32                                                         //~vb11I~
    swroot=ROOTDIR(Ppathname);                                     //~vb11I~
#endif                                                             //~vb11I~
//  rc=filefind(Ppathname,0,&fstat3,FFNODIRMSG);                //~5812R~//~v7abR~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abI~
    if (Popt && DGFSO_PATH     //fstat for intermediate path       //~v7abI~
    &&  WIN_ISREMOTEPATH(Ppathname))                               //~v7abI~
//  	opt|=FFNONFMSG;                                            //~v7abR~//~v7akR~
    	opt|=FFNORPATHER;                                          //~v7akI~
#endif                                                             //~v7abI~
//#ifdef W32                                                         //~vb04I~//~vb06R~
//  if (!Plevel && IS_RESERVED_NAME(Ppathname))                      //~vb04R~//~vb06R~
//  {                                                                //~vb04I~//~vb06R~
//    rc=filefind(Ppathname+RESERVED_NAMEID_CTR,0,&fstat3,opt);      //~vb04R~//~vb06R~
//  }                                                                //~vb04I~//~vb06R~
//  else                                                             //~vb04I~//~vb06R~
//#endif                                                             //~vb04I~//~vb06R~
//  {                                                                //~vb04I~//~vb06R~
    rc=filefind(Ppathname,0,&fstat3,opt);                          //~v7abI~
    *(Ppathname+len)=delmsv;                                    //~5812I~
//  }                                                                //~vb04I~//~vb06R~
	if (rc!=16)	//not dir                                       //~5812I~
    	return 4;                                               //~5812I~
#if defined(W32) || defined(DPMI)                                  //~v0feR~
	strncpy(Ppudirlist->alias,fstat3.achName,sizeof(Ppudirlist->alias));//alias//~v0f0R~
//  strncpy(Ppudirlist->name,fstat3.cFileName,sizeof(Ppudirlist->name));//lfn//~v0f0R~//~vb80R~
    udirlist_setname(0,Ppudirlist,fstat3.cFileName,sizeof(fstat3.cFileName));//lfn//~vb80R~
#ifdef W32UNICODE                                                  //~vavdI~
    Ppudirlist->ffb3otherflag=fstat3.otherflag;                    //~vavdI~
    Ppudirlist->nameWctr=fstat3.cFileNameWctr;                     //~vavdI~
    Ppudirlist->aliasWctr=fstat3.achNameWctr;                      //~vavdI~
//  memcpyWctr(Ppudirlist->nameW,fstat3.cFileNameW,Ppudirlist->nameWctr);//~vavdR~//~vb80R~
    udirlist_setnameW(0,Ppudirlist,fstat3.cFileNameW,fstat3.cFileNameWctr);//~vb80R~
    memcpyWctr(Ppudirlist->aliasW,fstat3.achNameW,strctrW(fstat3.achNameW));//~vavdR~//~vb80R~
    if (swroot)                                                    //~vb11R~
    {                                                              //~vb11I~
//      UmemcpyZ(Ppudirlist->name,Ppathname,3); //later replaced by ".."//~vb11R~
	    Ppudirlist->nameWctr=3;                                    //~vb11I~
//      umemcpyZ_ASCII2W(Ppudirlist->nameW,Ppathname,3);           //~vb11I~//~vb80R~
        umemcpyZ_ASCII2W(wkwch,Ppathname,3);    //strWZ            //~vb80R~
        udirlist_setnameW(0,Ppudirlist,wkwch,3);                   //~vb80R~
        UmemcpyZ(Ppudirlist->alias,Ppathname,3);                   //~vb2qI~
        umemcpyZ_ASCII2W(Ppudirlist->aliasW,Ppathname,3);          //~vb2qI~
    }                                                              //~vb11I~
#endif                                                             //~vavdI~
#else                                                              //~v0f0I~
//  strcpy(Ppudirlist->name,fstat3.achName);                    //~5812I~//~vb80R~
    udirlist_setname(0,Ppudirlist,fstat3.achName,sizeof(fstat3.achName));//~vb80R~
#endif                                                             //~v0f0I~
#ifdef UNX                                                         //~v19XI~
	Ppudirlist->fsid=fstat3.fsid;                                  //~v19XI~
	Ppudirlist->inode=fstat3.inode;                                //~vaa0I~
	Ppudirlist->uid =fstat3.uid;                                   //~v19XI~
	Ppudirlist->gid =fstat3.gid;                                   //~v19XI~
	Ppudirlist->attr=fstat3.attrFile;                              //~v19XI~
#else                                                              //~v19XI~
//  Ppudirlist->attr=(char)fstat3.attrFile;                        //~v53QR~
    Ppudirlist->attr=(ULONG)fstat3.attrFile;                       //~v53QI~
#endif //UNX                                                       //~v19XI~
	Ppudirlist->time=fstat3.ftimeLastWrite;                     //~5812I~
	Ppudirlist->date=fstat3.fdateLastWrite;                     //~5812I~
	Ppudirlist->size=fstat3.cbFile;                             //~5812I~
	return 0;                                                   //~5812I~
}//dirgetfstat                                                  //~5812I~
                                                                //~5812I~
//****************************************************************
//!dirsetdata
//* alloc and setup dir line data                               //~5819R~
//*parm1:dir level                                              //~v030R~
//*parm2:pudirlist                                              //~v030R~
//*parm3:pfh                                                       //~v0fdI~
//*retrn:plh or 0 if storage shortage                           //~v04dR~
//****************************************************************
PULINEH dirsetdata(int Plevel,PUDIRLIST Ppudirlist,PUFILEH Ppfh)   //~v0fdR~
{
	PULINEH plh;
	PUDIRLH pdh;
#ifdef FTPSUPP                                                     //~v54eI~
    char *pc;                                                      //~v54eI~
#endif                                                             //~v54eI~
	int slinklen;                                                  //~vandI~
//****************************
//#ifdef WXE                                                       //~v51AR~
//  plh=diralloclh(ULHTDATA,UDIRLDSZ);                             //~v59TR~
    plh=diralloclh(ULHTDATA,MAXCOLUMN);//for expansion             //~v59TR~
//#else                                                            //~v51AR~
//  plh=diralloclh(ULHTDATA,Gscrwidth-UDHLINENOSZ);                //~v51AR~
//#endif                                                           //~v51AR~
    UALLOCCHK(plh,0);	//return 0 if storage shortage          //~v04dR~
	pdh=UGETPDH(plh);
                                                                //~5812I~
#ifdef MMM                                                         //~vb2oI~
    memcpy(pdh->UDHname,Ppudirlist->name,sizeof(pdh->UDHname));    //~v0fdR~
#else                                                              //~vb2oI~
    dirupdatename(0/*realloc if buffsz increased*/,pdh,Ppudirlist->name,0/*strz*/);//~vb2oI~
#endif                                                             //~vb2oI~
#if defined(W32) || defined(DPMI)                                  //~v0feR~
	memcpy(pdh->UDHalias,Ppudirlist->alias,sizeof(pdh->UDHalias)); //~v0feR~
#endif                                                             //~v0feR~
//#ifdef UNX                                                       //~v54eR~
#ifdef FTPSUPP                                                     //~v54eI~
//  if (*Ppudirlist->slink)                                        //~v40tI~//~vandR~
    if (Ppudirlist->pslink && *Ppudirlist->pslink)                 //~vandR~
    {                                                              //~v40tI~
//  	pdh->UDHslink=umalloc(sizeof(Ppudirlist->slink));          //~v54eR~
//  	pdh->UDHslink=umalloc(sizeof(Ppudirlist->slink)+1+MAXUNAMESZ+1+MAXGNAMESZ+1);//~v54eI~//~vandR~
//  	slinklen=strlen(Ppudirlist->pslink);                       //~vb06R~
    	slinklen=(int)strlen(Ppudirlist->pslink);                  //~vb06I~
//  	pdh->UDHslink=umalloc(slinklen+1+MAXUNAMESZ+1+MAXGNAMESZ+1);//~vandI~//~vauDR~
//  	pdh->UDHslink=umalloc(slinklen+1);                         //~vb06R~
    	pdh->UDHslink=umalloc((size_t)slinklen+1);                 //~vb06I~
    	UALLOCCHK(pdh->UDHslink,0);                                //~v40tR~
//  	memcpy(pdh->UDHslink,Ppudirlist->slink,sizeof(Ppudirlist->slink));//~v40tR~//~vandR~
//		UmemcpyZ(pdh->UDHslink,Ppudirlist->pslink,slinklen);       //~vb06R~
  		UmemcpyZ(pdh->UDHslink,Ppudirlist->pslink,(size_t)slinklen);//~vb06I~
//      pc=pdh->UDHslink+sizeof(Ppudirlist->slink)+1;              //~v54eI~//~vandR~
//      pc=pdh->UDHslink+slinklen+1;                               //~vandI~//~vauDR~
    	pc=umalloc(MAXUNAMESZ+1+MAXGNAMESZ+1);                     //~vauDI~
    	UALLOCCHK(pc,0);                                           //~vauDI~
    	memcpy(pc,Ppudirlist->slinkuname,MAXUNAMESZ+1);            //~v54eI~
    	pdh->UDHslinkuname=pc;                                     //~v54eI~
        pc+=MAXUNAMESZ+1;                                          //~v54eI~
    	memcpy(pc,Ppudirlist->slinkgname,MAXGNAMESZ+1);            //~v54eI~
    	pdh->UDHslinkgname=pc;                                     //~v54eI~
    }                                                              //~v40tI~
#endif                                                             //~v40tI~
#ifdef UTF8SUPPH                                                   //~va00I~
//  dirsetlocalename(0,Ppudirlist,pdh);                            //~va00R~//~vagER~
    dirsetlocalename(0,Ppudirlist,Ppfh,pdh);                       //~vagEI~
#endif                                                             //~va00I~
    dirsetdatasub(pdh,Ppudirlist);                              //~5819I~
                                                                //~5812I~
//  if (memcmp(pdh->UDHname,"..",2))	//not parent               //~v0k1I~
    if (strcmp(pdh->UDHname,".."))	//not parent                   //~v0k1R~
    {                                                           //~v030I~
//  	if (*pdh->UDHname=='.')		//current                      //~v0k1I~
    	if (!strcmp(pdh->UDHname,"."))//current                    //~v0k1R~
        {                                                       //~v030I~
			pdh->UDHlevel=(UCHAR)Plevel;	//cur dir           //~5813R~
//  		pdh->UDHtype=UDHTDIREXP;//expanded                  //~v05KR~
			pdh->UDHtype=UDHTPARENT;//path                      //~v05KI~
		}                                                       //~v030I~
		else                                                    //~v030I~
        {                                                       //~v030I~
			pdh->UDHlevel=(UCHAR)(Plevel+1);	//file level    //~5813R~
		}                                                       //~v030I~
    }                                                           //~v030I~
	else                                                        //~v030I~
    {                                                           //~v030I~
		pdh->UDHlevel=(UCHAR)(Plevel-1);	//parent level      //~5813R~
		pdh->UDHtype=UDHTPARENT;                                //~v030I~
    }                                                           //~v030I~

	return plh;
}//dirsetdata

//****************************************************************//~5819I~
//!dirsetdatasub                                                //~5819I~
//* setup dir line data                                         //~5819I~
//*parm1:pdh                                                    //~5819I~
//*parm2:pudirlist                                              //~5819I~
//*retrn:none                                                   //~5819I~
//****************************************************************//~5819I~
void dirsetdatasub(PUDIRLH Ppdh,PUDIRLIST Ppudirlist)           //~5819I~
{                                                               //~5819I~
#ifdef FTPSUPP                                                     //~v72rI~
	PULINEH plh;                                                   //~v72rI~
#endif //FTPSUPP                                                   //~v72rI~
//#ifdef W32                                                       //~vaivR~
#if defined(W32)||defined(UNX)                                     //~vaivI~
	char *oldslink,*newslink,*pc;                                  //~vaitI~
#endif                                                             //~vaitI~
    int slinklen;                                                  //~vandI~
//****************************                                  //~5819I~
	Ppdh->UDHattr=Ppudirlist->attr;                             //~5819I~
	Ppdh->UDHsize=Ppudirlist->size;                             //~5819I~
	Ppdh->UDHdate=Ppudirlist->date;                             //~5819I~
	Ppdh->UDHtime=Ppudirlist->time;                             //~5819I~
                                                                   //~v19XI~
#ifdef UNX                                                         //~v19XI~
	Ppdh->UDHfsid=Ppudirlist->fsid;                                //~v19XI~
	Ppdh->UDHinode=Ppudirlist->inode;                              //~vaa0I~
	Ppdh->UDHuid =Ppudirlist->uid ;                                //~v19XI~
	Ppdh->UDHgid =Ppudirlist->gid ;                                //~v19XI~
#endif //UNX                                                       //~v19XI~
#ifdef FTPSUPP                                                     //~v54eI~
	Ppdh->UDHslinksize=Ppudirlist->slinksize;                      //~v54eI~
	Ppdh->UDHslinkdate=Ppudirlist->slinkfdate;                     //~v54eR~
	Ppdh->UDHslinktime=Ppudirlist->slinkftime;                     //~v54eR~
	Ppdh->UDHslinkattr=Ppudirlist->srcattr;                        //~v54kI~
//#ifdef W32                                                       //~vaivR~
#if defined(W32)||defined(UNX)                                     //~vaivI~
//  if (*Ppudirlist->slink)                                        //~vaitI~//~vandR~
    if (Ppudirlist->pslink && *Ppudirlist->pslink)                 //~vandR~
//      if (!Ppdh->UDHslink || stricmp(Ppudirlist->slink,Ppdh->UDHslink))	//slink name changed//~vaitI~//~vandR~
//      if (!Ppdh->UDHslink || stricmp(Ppudirlist->pslink,Ppdh->UDHslink))	//slink name changed//~vandI~//~vauDR~
//#ifdef LNX                                                       //~vauER~
        if (!Ppdh->UDHslink || strcmp(Ppudirlist->pslink,Ppdh->UDHslink))	//case sensitive,slink name changed//~vauDI~
//#else                                                            //~vauER~
//        if (!Ppdh->UDHslink                                      //~vauER~
//        ||  !(  !stricmp(Ppudirlist->pslink,Ppdh->UDHslink) //slink name not changed//~vauER~
//             ||  (Ppdh->UDHslinknameu8 && !stricmp(Ppudirlist->pslink,Ppdh->UDHslinknameu8))    //same as before f2l//~vauER~
//             )                                                   //~vauER~
//           )                                                     //~vauER~
//#endif                                                           //~vauER~
        {                                                          //~vaitI~
            oldslink=Ppdh->UDHslink;                               //~vaitI~
//          newslink=umalloc(sizeof(Ppudirlist->slink)+1+MAXUNAMESZ+1+MAXGNAMESZ+1);//~vaitI~//~vandR~
//  		slinklen=strlen(Ppudirlist->pslink);                   //~vb06R~
    		slinklen=(int)strlen(Ppudirlist->pslink);              //~vb06I~
//          newslink=umalloc(slinklen+1+MAXUNAMESZ+1+MAXGNAMESZ+1);//~vandI~//~vauDR~
//          newslink=umalloc(slinklen+1); //another chunk for ugname//~vb06R~
            newslink=umalloc((size_t)slinklen+1); //another chunk for ugname//~vb06I~
            if (!newslink)                                         //~vaitR~
            	return;                                            //~vaitI~
//          memcpy(newslink,Ppudirlist->slink,sizeof(Ppudirlist->slink));//~vaitI~//~vandR~
//          UmemcpyZ(newslink,Ppudirlist->pslink,slinklen);        //~vb06R~
            UmemcpyZ(newslink,Ppudirlist->pslink,(size_t)slinklen);//~vb06I~
//          pc=newslink+sizeof(Ppudirlist->slink)+1;               //~vaitI~//~vandR~
//          pc=newslink+slinklen+1;                                //~vandI~//~vauDR~
            pc=Ppdh->UDHslinkuname;                                //~vauDI~
            if (!pc)	//old status is not havving slink          //~vay3I~
            {                                                      //~vay3I~
    			pc=umalloc(MAXUNAMESZ+1+MAXGNAMESZ+1);             //~vay3I~
            	if (!pc)                                           //~vay3I~
	            	return;                                        //~vay3I~
    			Ppdh->UDHslinkuname=pc;                            //~vay3R~
    		    pc+=MAXUNAMESZ+1;                                  //~vay3I~
	    		Ppdh->UDHslinkgname=pc;                            //~vay3R~
            }                                                      //~vay3I~
            memcpy(pc,Ppudirlist->slinkuname,MAXUNAMESZ+1);        //~vaitI~
//          Ppdh->UDHslinkuname=pc;                                //~vaitR~//~vauDR~
//          pc+=MAXUNAMESZ+1;                                      //~vaitI~//~vauDR~
            pc=Ppdh->UDHslinkgname;                                //~vauDI~
            memcpy(pc,Ppudirlist->slinkgname,MAXGNAMESZ+1);        //~vaitI~
//          Ppdh->UDHslinkgname=pc;                                //~vaitR~//~vauDR~
            Ppdh->UDHslink=newslink;                               //~vaitR~
            if (oldslink)                                          //~vaitI~
	            ufree(oldslink);                                   //~vaitI~
    		dirsetlocalename(0,Ppudirlist,(PUFILEH)UGETDIRPLH(Ppdh),Ppdh);    //f2l//~vauDR~
        }                                                          //~vaitI~
#endif                                                             //~vaitI~
    if (Ppudirlist->attr & FILE_REMOTE)                            //~v55hR~
    {                                                              //~v55hI~
		memcpy(Ppdh->UDHuname,Ppudirlist->uname,sizeof(Ppdh->UDHuname));//~v55hR~
		memcpy(Ppdh->UDHgname,Ppudirlist->gname,sizeof(Ppdh->UDHgname));//~v55hR~
	    if (Ppudirlist->attr & FILE_TSO)                           //~v72rI~
        {                                                          //~v72rI~
		    plh=UGETDIRPLH(Ppdh);        //re-draw dir id          //~v72rI~
            if (Ppudirlist->attr & FILE_SPF)    //spf info exist   //~v72rI~
            {                                                      //~v72rI~
//              plh->ULHlinenow=Ppdh->UDHslinksize;                //~v731R~
                plh->ULHlinenow=(LONG)Ppdh->UDHslinksize;          //~v731I~
                UCBITON(Ppdh->UDHflag2,UDHF2LCGOTTEN);             //~v72rI~
            }                                                      //~v72rI~
            else                                                   //~v72rI~
            {                                                      //~v72rI~
                UCBITOFF(Ppdh->UDHflag2,UDHF2LCGOTTEN);            //~v72rI~
                plh->ULHlinenow=0;                                 //~v72rI~
            }                                                      //~v72rI~
        }                                                          //~v72rI~
    }                                                              //~v55hI~
#endif //FTPSUPP                                                   //~v54eI~
                                                                   //~v19XI~
	UCBITOFF(Ppdh->UDHflag,UDHFDDSETUP);	//request line make //~5906I~
//  if (UCBITCHK(Ppdh->UDHattr,FILE_DIRECTORY))                    //~v53QR~
    if (Ppdh->UDHattr & FILE_DIRECTORY)                            //~v53QI~
		Ppdh->UDHtype=UDHTDIR;                                  //~v05PR~
	else                                                        //~v05PI~
		Ppdh->UDHtype=UDHTFILE;                                 //~v05PR~
    return;                                                     //~5819I~
}//dirsetdatasub                                                //~v05GR~
                                                                //~5819I~
//****************************************************************//~v05GI~
//!dirsetdatasub2                                               //~v05GI~
//* setup dir line data from fstat3(called from dlcmdresetdata) //~v05GR~
//*parm1:pdh                                                    //~v05GI~
//*parm2:pfstat3                                                //~v05GI~
//*retrn:none                                                   //~v05GI~
//****************************************************************//~v05GI~
void dirsetdatasub2(PUDIRLH Ppdh,FILEFINDBUF3 *Ppfstat3)        //~v05GI~
{                                                               //~v05GI~
//  UDIRLIST udirlwk;                                           //~v05GI~//~vandR~
//  UDIRLIST_WK(udirlwk,wkslinkname);                              //~vandI~//~vb80R~
    UDIRLIST_WK(udirlwk,wkname,wknamew,wkslinkname);               //~vb80R~
//****************************                                  //~v05GI~
//  UDIRLIST_WK_INIT(udirlwk,wkslinkname);                         //~vandI~//~vb80R~
    UDIRLIST_WK_INIT(udirlwk,wkname,wknamew,wkslinkname);          //~vb80R~
#ifdef UNX                                                         //~v19XI~
	udirlwk.fsid=Ppfstat3->fsid;                                   //~v19XI~
	udirlwk.inode=Ppfstat3->inode;                                 //~vaa0I~
	udirlwk.uid =Ppfstat3->uid;                                    //~v19XI~
	udirlwk.gid =Ppfstat3->gid;                                    //~v19XI~
	udirlwk.attr=Ppfstat3->attrFile;                               //~v19XI~
#else                                                              //~v19XI~
//  udirlwk.attr=(char)Ppfstat3->attrFile;                         //~v556R~
    udirlwk.attr=Ppfstat3->attrFile;  //ULONG                      //~v556I~
#endif                                                             //~v19XI~
#ifdef FTPSUPP                                                     //~v556I~
	udirlwk.slinksize=Ppfstat3->slinksize;                         //~v556I~
	udirlwk.slinkfdate=Ppfstat3->slinkfdate;                       //~v556R~
	udirlwk.slinkftime=Ppfstat3->slinkftime;                       //~v556R~
	udirlwk.srcattr=Ppfstat3->srcattr;                             //~v556R~
	memcpy(udirlwk.uname,Ppfstat3->uname,sizeof(udirlwk.uname));   //~vac3R~
	memcpy(udirlwk.gname,Ppfstat3->gname,sizeof(udirlwk.gname));   //~vac3R~
//  memcpy(udirlwk.slink,Ppfstat3->slink,sizeof(udirlwk.slink));   //~vaitR~//~vandR~
    memcpy(wkslinkname,Ppfstat3->slink,sizeof(wkslinkname));       //~vandR~
#ifdef UNX      //smbclient(Unix only)show uid/gid                 //~vac3I~
	udirlwk.uid=Ppfstat3->uid;                                     //~vac3I~
	udirlwk.gid=Ppfstat3->gid;                                     //~vac3I~
#endif                                                             //~vac3I~
#endif //FTPSUPP                                                   //~v556I~
	udirlwk.size=Ppfstat3->cbFile;                              //~v05GR~
	udirlwk.date=Ppfstat3->fdateLastWrite;                      //~v05GR~
	udirlwk.time=Ppfstat3->ftimeLastWrite;                      //~v05GR~
	dirsetdatasub(Ppdh,&udirlwk);                               //~v05GR~
    return;                                                     //~v05GI~
}//dirsetdatasub2                                               //~v05GI~
                                                                //~v05GI~
#ifdef FTPSUPP                                                     //~v54mR~
//**************************************************************** //~v54mR~
//!dirresetftpfiletime                                             //~v54mR~
//* update dirlist filetime for remote file                        //~v54mR~
//*parm1:pdh                                                       //~v54mR~
//*parm2:pfh                                                       //~v54mR~
//*retrn:none                                                      //~v54mR~
//**************************************************************** //~v54mR~
void dirresetftpfiletime(PUDIRLH Ppdh,PUFILEH Ppfh)                //~v54mR~
{                                                                  //~v54mR~
//****************************                                     //~v54mR~
    if (FILEISSLINK(Ppfh->UFHattr))                                //~v54mR~
    {                                                              //~v54mR~
		Ppdh->UDHslinkdate=Ppfh->UFHfiledate;                      //~v54mR~
		Ppdh->UDHslinktime=Ppfh->UFHfiletime;                      //~v54mR~
    }                                                              //~v54mR~
    else                                                           //~v54mR~
    {                                                              //~v54mR~
		Ppdh->UDHdate=Ppfh->UFHfiledate;                           //~v54mR~
		Ppdh->UDHtime=Ppfh->UFHfiletime;                           //~v54mR~
    }                                                              //~v54mR~
	UCBITOFF(Ppdh->UDHflag,UDHFDDSETUP);	//request line make    //~v54mR~
    return;                                                        //~v54mR~
}//dirresetftpfiletime                                             //~v54mR~
#endif                                                             //~v54mR~
//****************************************************************
//!dirclosefree
//*close and free UFILEH/ULINEH/UDIRLH
//*parm:UFILEC
//*rc   :open count
//****************************************************************
int dirclosefree(PUFILEC Ppfc)
{
    PUFILEH pfh;
    PUCLIENTWE pcw;                                                //~v08cI~
//****************************
	pcw=Ppfc->UFCpcw;		//mother                               //~v08cI~
    if (pcw==Gcappcw)   //current block pcw                        //~v08cI~
		capreset(0);    //crear Gcappcw                            //~v08cI~
    if (pcw==Gcapcbpcw) //clipboard pcw                            //~v08cI~
		Gcapcbpcw=0;    //crear hidden pcw                         //~v08cI~
	pfh=Ppfc->UFCpfh;
	if (UCBITCHK(Ppfc->UFCflag,UFCFBROWSE))	//browse mode
		pfh->UFHbrowsepcw[Gscrcurclient]=0;
	else
		pfh->UFHeditpcw=0;
	return dirclosefree2(pfh);                                     //~v081I~
}//dirclosefree                                                    //~v081I~

//**************************************************************** //~v081I~
//!dirclosefree2                                                   //~v081I~
//*close and free UFILEH/ULINEH/UDIRLH                             //~v081I~
//*parm:UFILEH                                                     //~v081I~
//*rc   :open count                                                //~v081I~
//**************************************************************** //~v081I~
int dirclosefree2(PUFILEH Ppfh)                                    //~v081I~
{                                                                  //~v081I~
	int  	openctr;                                               //~v081M~
//****************************                                     //~v081I~
	if (openctr=--Ppfh->UFHopenctr,openctr)		//other open client exist//~v081R~
		return openctr;
//line data
	dirfree(Ppfh);			//free all data                        //~v081R~
//free pfh                                                      //~5827R~
    filefreepfh(Ppfh);                                             //~v081R~
	return 0;
}//dirclosefree2                                                   //~v081R~

//***********************************************************
//!diralloclh
//*allocate ULINEH,UDIRLH and data buff
//*parm1:line type
//*parm2:data length
//*retrn:ULINEH addr or 0 if storage shortage                   //~v04dR~
//***********************************************************
PULINEH diralloclh(UCHAR Ptype,int Pdatalen)
{
	PULINEH plh;
	PUDIRLH pdh;                                                //~v020I~
	int bufflen,len;                                            //~v020R~
#ifdef UTF8SUPPH                                                   //~va0GI~
	int utf8wksz;                                                  //~va0GI~
    char *pc;                                                      //~va0GI~
#endif                                                             //~va0GI~
//***************
//  len=ULINEHSZ+UDIRLHSZ+Pdatalen*2;                              //~vb06R~
    len=(int)(ULINEHSZ+UDIRLHSZ)+Pdatalen*2;                       //~vb06I~
#ifdef UTF8SUPPH                                                   //~va0GI~
    utf8wksz=UDHRENAME_CODETYPESZ+UDHRENAME_UTF8SZ;                //~va0GI~
    len+=utf8wksz;                                                 //~va0GI~
#endif                                                             //~va0GI~
	bufflen=uallocsz((UINT)len);
	plh=UALLOCC(1,(UINT)bufflen);                               //~v04dR~
    UALLOCCHK(plh,0);   //return 0 if storage shortage          //~v04dI~
	memcpy(plh->ULHcbid,ULHCBID,4);
	plh->ULHtype=Ptype;				//line type
	plh->ULHlen=Pdatalen;

    pdh=UGETPDH(plh);
	memcpy(pdh->UDHcbid,UDHCBID,4);

	plh->ULHdata=(UCHAR*)(PVOID)pdh+UDIRLHSZ;
#ifdef UTF8SUPPH                                                   //~va0GI~
	bufflen-=utf8wksz;                                             //~va0GI~
#endif                                                             //~va0GI~
//  bufflen=(bufflen-ULINEHSZ-UDIRLHSZ)/2;                         //~vb06R~
    bufflen=(bufflen-(int)ULINEHSZ-(int)UDIRLHSZ)/2;               //~vb06I~
	plh->ULHdbcs=plh->ULHdata+bufflen;
	plh->ULHbufflen=bufflen;
#ifdef UTF8SUPPH                                                   //~va0GI~
	pc=plh->ULHdbcs+bufflen;	//utf8wk top                       //~va0GI~
    pdh->UDHrename_codetype=pc;                                    //~va0GI~
    pc+=UDHRENAME_CODETYPESZ;                                      //~va0GI~
    pdh->UDHrename_utf8=pc;                                        //~va0GI~
#endif                                                             //~va0GI~
	return plh;
}//diralloclh

//****************************************************************
//!dirfree
//*free all ULINEH entry
//*parm1:PUFILEH
//*void
//****************************************************************
void dirfree(PUFILEH Ppfh)
{
	UQUEH   *pqh;
	PULINEH plh;
//  PUDIRLH pdh;                                                   //~v09yR~
//  int     deqc=0;	//avoid compile warning                        //~v09yR~
//******************
	pqh=&Ppfh->UFHlineque;
	while (plh=UDEQ(UQUE_TOP,pqh,0),plh)	//dequed
//  {                                                              //~v09yR~
//      pdh=UGETPDH(plh);                                          //~v09yR~
//      while(UDEQ(UQUE_TOP,&pdh->UDHviewqh,0)) deqc++;            //~v09yR~
		dirfreeplh(plh);                                        //~v020R~
//  }                                                              //~v09yR~
	return;
}//dirfree

//****************************************************************
//!dirfreeplh
//*free line entry
//*parm1:PULINEH
//*void
//****************************************************************
void dirfreeplh(PULINEH Pplh)
{
    UCHAR *pc;                                                  //~5903I~
    PUDIRLH pdh;                                                   //~v09yR~
    int     deqc=0;	//avoid compile warning                        //~v09yR~
//************************************                          //~5903I~
    pdh=UGETPDH(Pplh);                                             //~v09yR~
    while(UDEQ(UQUE_TOP,&pdh->UDHviewqh,0)) deqc++;                //~v09yR~
	if (pc=pdh->UDHrenamesv,pc)                                    //~v09yR~
    	ufree(pc);                                              //~5903I~
#ifdef UTF8SUPPH                                                   //~va00I~
    UFREEIFNZ(pdh->UDHrenamesvbyutf8)                              //~va00R~
    UFREEIFNZ(pdh->UDHnamef2l)                                     //~va00R~
//#ifdef LNX                                                         //~vau0I~//~vauER~
    UFREEIFNZ(pdh->UDHnameddfmt)                                   //~vau0I~
    UFREEIFNZ(pdh->UDHslinkddfmt)                                  //~vau0I~
    UFREEIFNZ(pdh->UDHrenameddfmt)                                 //~vau0I~
#ifdef W32UNICODE                                                  //~vav0I~//~vavaI~
  if (pdh->UDHnameW!=pdh->UDHnameWshort)    //malloc if over 15 char//~vb10I~
    UFREEIFNZ(pdh->UDHnameW)                                       //~vav0I~//~vavaI~
#endif                                                             //~vav0I~//~vavaI~
//#else                                                              //~vau0I~//~vauER~
//    UFREEIFNZ(pdh->UDHslinknameu8)                                 //~vau0I~//~vauER~
//#endif                                                             //~vau0I~//~vauER~
#endif                                                             //~va00I~
#ifdef MMM                                                         //~vb2oI~
#else                                                              //~vb2oI~
    UFREEIFNZ(pdh->UDHname)   //split from UDHslink                //~vb2oI~
#endif                                                             //~vb2oI~
    UFREEIFNZ(pdh->UDHslinkuname)   //split from UDHslink          //~vauDI~
	if (pc=pdh->UDHpdesc,pc)     //file descriotion set            //~v690R~
    	ufree(pc);                                                 //~v690I~
//#ifdef UNX                                                       //~v54eR~
#ifdef FTPSUPP                                                     //~v54eI~
	if (pc=pdh->UDHslink,pc)   //slink name                        //~v40tI~
    	ufree(pc);                                                 //~v40tI~
#endif                                                             //~v40tI~
	ufree(Pplh);
}//dirfreeplh

//**************************************************************** //~v0feI~
// dirlvlfname0                                                    //~v0feI~
// get filename of the level from full path name                   //~v0feI~
//*parm1 :pfh                                                      //~v0feI~
//*parm2 :level                                                    //~v0feI~
//*parm3 :pdh(optional)                                            //~v0feI~
//*parm4 :output fullpath len(option)                              //~v0feI~
//*ret   :rc                                                       //~v0feI~
//**************************************************************** //~v0feI~
int dirlvlfname0(PUFILEH Ppfh,int Plevel,PUDIRLH Ppdh,int *Plen)   //~v0feI~
{                                                                  //~v0feI~
    UCHAR *pc;                                                     //~v0feI~
    int   rc;                                                      //~v0feI~
#ifdef MMM                                                         //~vb2oI~
#else                                                              //~vb2oI~
    UCHAR UDHname[UDHNAME_MAXSZ];                                  //~vb2oR~
#endif                                                             //~vb2oI~
//*******************                                              //~v0feI~
	pc=0;                                                          //~v0feI~
	if (Ppdh)                                                      //~v0feR~
    {                                                              //~v7abI~
#ifdef MMM                                                         //~vb2oI~
    	pc=Ppdh->UDHname;                                          //~v0feR~
        memset(pc,0,sizeof(Ppdh->UDHname));  //confirm strncpy     //~v7abR~
#else                                                              //~vb2oI~
    	pc=UDHname;                                                //~vb2oI~
        memset(pc,0,sizeof(UDHname));  //confirm strncpy           //~vb2oI~
#endif                                                             //~vb2oI~
    }                                                              //~v7abI~
//  rc=dirlvlfname(Ppfh->UFHfilename,Plevel,pc,Plen);              //~v540R~
//  rc=dirlvlfname(Ppfh,Ppfh->UFHfilename,Plevel,pc,Plen);         //~v540I~//~vb7hR~
    rc=dirlvlfname(Ppfh,Ppfh->UFHfilename,Plevel,pc,sizeof(UDHname),Plen);//~vb7hI~
#ifdef MMM                                                         //~vb2oI~
#else                                                              //~vb2oI~
	if (Ppdh)                                                      //~vb2oI~
		dirupdatename(0,Ppdh,pc,0/*srclen*/);  //confirm strncpy   //~vb2oI~
#endif                                                             //~vb2oI~
#if defined(W32) || defined(DPMI)                                  //~v0feI~
 #ifdef FTPSUPP                                                    //~v717I~
  if (!FILEISTSO(Ppfh))                                            //~v716I~
  {                                                                //~v716I~
 #endif                                                            //~v717I~
	pc=0;                                                          //~vb7hI~
	if (Ppdh)                                                      //~v0feR~
    	pc=Ppdh->UDHalias;                                         //~v0feR~
	if (!rc)                                                       //~v0feI~
    {                                                              //~v7abI~
        if (pc)                                                    //~v7abI~
        	memset(pc,0,sizeof(Ppdh->UDHalias));  //confirm strncpy//~v7abR~
//  	rc=dirlvlfname(Ppfh->UFHshortname,Plevel,pc,Plen);//get alias//~v540R~
//  	rc=dirlvlfname(Ppfh,Ppfh->UFHshortname,Plevel,pc,Plen);//get alias//~v540I~//~vb7hR~
    	rc=dirlvlfname(Ppfh,Ppfh->UFHshortname,Plevel,pc,sizeof(Ppdh->UDHalias),Plen);//get alias//~vb7hI~
    }                                                              //~v7abI~
 #ifdef FTPSUPP                                                    //~v717I~
  }                                                                //~v716I~
 #endif                                                            //~v717I~
#endif                                                             //~v0feI~
	return rc;                                                     //~v0feI~
}//dirlvlfname0                                                    //~v0feI~
//****************************************************************//~5812I~
// dirlvlfname                                                  //~5812I~
// get filename of the level from full path name                //~5812I~
//*parm1 :fullpath name                                         //~5812I~
//*parm2 :level                                                 //~5812I~
//*parm3 :output file name(option)                              //~5812R~
//*parm4 :output fullpath len(option)                           //~5812I~
//*ret   :rc                                                    //~5812I~
//****************************************************************//~5812I~
//int dirlvlfname(UCHAR *Pfullpath,int Plevel,UCHAR *Pfname,int *Plen)//~v540R~
//int dirlvlfname(PUFILEH Ppfh,UCHAR *Pfullpath,int Plevel,UCHAR *Pfname,int *Plen)//~v540I~//~vb7hR~
int dirlvlfname(PUFILEH Ppfh,UCHAR *Pfullpath,int Plevel,UCHAR *Pfname,size_t Pbuffsz,int *Plen)//~vb7hI~
{                                                               //~5812I~
    UCHAR *pc,*pc2;                                                //~v07lR~
    int   ii;                                                   //~5812I~
    UINT  len;                                                  //~5812I~
    char  dirsepc;                                                 //~v540I~
//    int swreservename=0;                                           //~vb04I~//~vb06R~
//*******************                                           //~5812I~
#ifdef FTPSUPP                                                     //~v717I~
    if (FILEISTSO(Ppfh))                                           //~v716I~
    	return xetsolvlfname(Ppfh,Pfullpath,Plevel,Pfname,Plen);   //~v716I~
#endif                                                             //~v717I~
	dirsepc=Ppfh->UFHdirsepc;                                      //~v540I~
	if (!Plevel)	//req root;                                 //~5812I~
    {                                                           //~5812I~
//  	if (!(pc=strchr(Pfullpath,'\\')))                          //~v19aR~
//  	if (!(pc=strchr(Pfullpath,DIR_SEPC)))                      //~v540R~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abM~
      if (WIN_ISREMOTEPATH(Pfullpath))                   //~v7abI~//~v7acR~//~v7abI~
      {                                                            //~v7abI~
    	if (!(pc=strchr(Pfullpath+2,dirsepc)))                     //~v7abI~
        	return 4;                                              //~v7abI~
      }                                                            //~v7abI~
      else                                                         //~v7abM~
#endif                                                             //~v7abM~
//#ifdef W32               //\\.\     prefix for reserved name       //~vb04M~//~vb06R~
//     if (IS_RESERVED_NAME(Pfullpath))                              //~vb04M~//~vb06R~
//     {                                                             //~vb04M~//~vb06R~
//        if (!(pc=strchr(Pfullpath+RESERVED_NAMEID_CTR,dirsepc)))   //~vb04M~//~vb06R~
//            return 4;                                              //~vb04M~//~vb06R~
//        swreservename=1;                                           //~vb04I~//~vb06R~
//     }                                                             //~vb04M~//~vb06R~
//     else                                                          //~vb04M~//~vb06R~
//#endif                                                             //~vb04M~//~vb06R~
    	if (!(pc=strchr(Pfullpath,dirsepc)))                       //~v540I~
        	return 4;                                           //~5812I~
//  	len=(UINT)((ULONG)pc-(ULONG)Pfullpath+1);               //~5815R~//~vafkR~
    	len=(UINT)((ULPTR)pc-(ULPTR)Pfullpath+1);                  //~vafkI~
        pc=Pfullpath;                                           //~5812I~
        if (Plen)                                               //~5812I~
	        *Plen=(int)len;                                     //~5812R~
	}                                                           //~5812I~
    else                                                        //~5812I~
    {                                                           //~5812I~
//  	for (ii=0,pc=Pfullpath;ii<Plevel;ii++,pc++)                //~v07lR~
//  		if (!(pc=strchr(pc,'\\')))                             //~v07lR~
//      		return 4;                                          //~v07lI~
#ifdef WINREMOTESUPP     //\\xxx\yy support                        //~v7abM~
      if (WIN_ISREMOTEPATH(Pfullpath))                             //~v7abI~
      {                                                            //~v7abI~
    	for (ii=0,pc=Pfullpath+2;ii<Plevel;ii++,pc++)              //~v7abI~
    		if (!(pc=ustrchr2(pc,dirsepc)))	//search '\' not dbcs 2nd byte//~v7abI~
        		return 4;                                          //~v7abI~
      }                                                            //~v7abI~
      else                                                         //~v7abI~
#endif                                                             //~v7abM~
//#ifdef W32               //\\.\     prefix for reserved name       //~vb04I~//~vb06R~
//      if (IS_RESERVED_NAME(Pfullpath))                             //~vb04I~//~vb06R~
//      {                                                            //~vb04I~//~vb06R~
//        for (ii=0,pc=Pfullpath+RESERVED_NAMEID_CTR;ii<Plevel;ii++,pc++)//~vb04I~//~vb06R~
//            if (!(pc=ustrchr2(pc,dirsepc))) //search '\' not dbcs 2nd byte//~vb04I~//~vb06R~
//                return 4;                                          //~vb04I~//~vb06R~
//      }                                                            //~vb04I~//~vb06R~
//      else                                                         //~vb04I~//~vb06R~
//#endif                                                             //~vb04I~//~vb06R~
    	for (ii=0,pc=Pfullpath;ii<Plevel;ii++,pc++)                //~v07lI~
//  		if (!(pc=ustrchr2(pc,'\\')))	//search '\' not dbcs 2nd byte//~v19aR~
//  		if (!(pc=ustrchr2(pc,DIR_SEPC)))	//search '\' not dbcs 2nd byte//~v540R~
    		if (!(pc=ustrchr2(pc,dirsepc)))	//search '\' not dbcs 2nd byte//~v540I~
        		return 4;                                          //~v07lI~
//  	if (!(pc2=strchr(pc,'\\')))                                //~v07lR~
//  	if (!(pc2=ustrchr2(pc,'\\')))                              //~v19aR~
//  	if (!(pc2=ustrchr2(pc,DIR_SEPC)))                          //~v540R~
    	if (!(pc2=ustrchr2(pc,dirsepc)))                           //~v540I~
        {                                                       //~5813I~
//        	len=strlen(pc);                                     //~5812I~//~vb2ER~
          	len=(UINT)strlen(pc);                                  //~vb2EI~
    	    if (Plen)                                           //~5813I~
	    	    *Plen=(int)strlen(Pfullpath);                   //~5813R~
        }                                                       //~5813I~
		else                                                    //~5812I~
        {                                                       //~5813I~
//  		len=(UINT)((ULONG)pc2-(ULONG)pc);                   //~5815R~//~vafkR~
    		len=(UINT)((ULPTR)pc2-(ULPTR)pc);                      //~vafkI~
    	    if (Plen)                                           //~5813I~
//      	    *Plen=(int)((ULONG)pc2-(ULONG)Pfullpath);       //~5813I~//~vafkR~
        	    *Plen=(int)((ULPTR)pc2-(ULPTR)Pfullpath);          //~vafkI~
        }                                                       //~5813I~
		if (len>MAXFILENAME)                                    //~5812I~
        	return 4;                                           //~5812I~
	}                                                           //~5812I~
    if (Pfname)                                                 //~5812I~
    {                                                           //~5812I~
//        if (swreservename && !Plevel)                              //~vb04I~//~vb06R~
//        {                                                          //~vb04I~//~vb06R~
//            pc+=RESERVED_NAMEID_CTR;                               //~vb04I~//~vb06R~
//            len-=RESERVED_NAMEID_CTR;                              //~vb04I~//~vb06R~
//        }                                                          //~vb04I~//~vb06R~
		len=min((UINT)Pbuffsz-1,len);                              //~vb7hR~
    	memcpy(Pfname,pc,len);                                  //~5812M~
    	*(Pfname+len)=0;                                        //~5812R~
	}                                                           //~5812I~
    UTRACEP("%s:fpath=%s,level=%d,lvlname=%s\n",UTT,Pfullpath,Plevel,Pfname);//~vb7hI~
    return 0;                                                   //~5812I~
}//dirlvlfname                                                  //~5812I~
                                                                //~5820I~
//****************************************************************//~5820I~
//!dirrenum                                                     //~5820I~
//*renumber dir list line number                                //~5820I~
//*parm1:plh of base(start from next of this plh)               //~v048R~
//*ret  :none                                                   //~5820I~
//****************************************************************//~5820I~
void dirrenum(PULINEH Pplh)                                     //~v048R~
{                                                               //~5820I~
    LONG    lineno;                                             //~v048R~
//****************************                                  //~5820I~
    lineno=Pplh->ULHlinenor;                                    //~v048R~
	while (Pplh=UGETQNEXT(Pplh),Pplh)                           //~v048R~
    	Pplh->ULHlinenor=++lineno;                              //~v048R~
	return;                                                     //~5820I~
}//dirrenum                                                     //~5820R~
//**************************************************************** //~v137I~
//!dirnexttab                                                      //~v137I~
//*next tab may scroll down                                        //~v137I~
//*parm1:pcw                                                       //~v137I~
//*ret  :rc of nexttab_pan                                         //~v137I~
//**************************************************************** //~v137I~
int dirnexttab(PUCLIENTWE Ppcw)                                    //~v137I~
{                                                                  //~v137I~
//****************************                                     //~v137I~
    for (;;)                                                       //~v137I~
    {                                                              //~v137I~
    	if (!CSRONFILELINE_COLS(Ppcw))	//cmd line                 //~v137I~
        	break;                                                 //~v137I~
    	if (Ppcw->UCWrcsry+1!=Ppcw->UCWheight)//not last line      //~v137I~
        	break;                                                 //~v137I~
		if (!csrnexttaboftheline(Ppcw))	//field on the same line   //~v137R~
            return 0;                                              //~v137I~
        filepgdownhalf(Ppcw);   //scroll down                      //~v137R~
    }                                                              //~v137I~
	return func_nexttab_pan(Ppcw);	//csr set to next field        //~v137I~
}//dirnexttab                                                      //~v137I~
#ifdef MMM                                                         //~vb2oI~
#else                                                              //~vb2oI~
//**************************************************************** //~vb2oI~
//*malloc area then update UDHname                                 //~vb2oI~
//**************************************************************** //~vb2oI~
int dirupdatename(int Popt,PUDIRLH Ppdh,char *Psrc,int Psrclen)    //~vb2oR~
{                                                                  //~vb2oI~
	int len,swfree=0,rc=0,buffsz;                                  //~vb2oI~
    UCHAR *pc;                                                     //~vb2oR~
//*********************                                            //~vb2oI~
	UTRACEP("%s:opt=%x,srclen=%d,Psrc=%s\n",UTT,Popt,Psrclen,Psrc);             //~vb2oI~//~vb7hR~
    if (Popt & DUNO_MEMSET)                                        //~vb2oI~
    {                                                              //~vb2oI~
    	pc=Ppdh->UDHname;                                          //~vb2oI~
        buffsz=Ppdh->UDHnamebuffsz;                                //~vb2oI~
        if (pc)                                                    //~vb2oI~
        	memset(pc,0,(size_t)buffsz);                           //~vb2oI~
        return 0;                                                  //~vb2oR~
    }                                                              //~vb2oI~
    if (!(len=Psrclen))                                            //~vb2oI~
    	len=(int)strlen(Psrc);                                     //~vb2oR~
#ifdef W32                                                         //~vb2oI~
    buffsz=len+3+1;  //3:ud fmt allowance                          //~vb2oR~
#else                                                              //~vb2oI~
    buffsz=len+1;	//strz                                         //~vb2oI~
#endif                                                             //~vb2oI~
    if (Popt & DUNO_ALLOCNEW) //  0x01   //alloacte new area even if new string is short//~vb2oI~
	    swfree=1;                                                  //~vb2oI~
    else                                                           //~vb2oI~
    	if (buffsz>Ppdh->UDHnamebuffsz)                            //~vb2oI~
		    swfree=2;                                              //~vb2oI~
    if (swfree)                                                    //~vb2oI~
    {                                                              //~vb2oI~
    	pc=umalloc((size_t)buffsz);                                //~vb2oI~
    	if (!pc)                                                   //~vb2oI~
    		rc=UALLOC_FAILED;                                      //~vb2oI~
    }                                                              //~vb2oI~
    else                                                           //~vb2oI~
        pc=0;                                                      //~vb2oI~
    if (!rc)                                                       //~vb2oI~
    {                                                              //~vb2oI~
    	if (swfree)	//to be free                                   //~vb2oI~
        {                                                          //~vb2oI~
			UTRACEP("%s:old buffsz=%d,old name=%s\n",UTT,Ppdh->UDHnamebuffsz,Ppdh->UDHname);//~vb2oI~//~vb7hR~
		    UFREEIFNZ(Ppdh->UDHname);                              //~vb2oI~
            Ppdh->UDHname=pc;                                      //~vb2oI~
            Ppdh->UDHnamebuffsz=buffsz;                            //~vb2oI~
        }                                                          //~vb2oI~
        memcpy(Ppdh->UDHname,Psrc,(size_t)len);                    //~vb2oR~
        buffsz=Ppdh->UDHnamebuffsz;                                //~vb2oI~
        if (buffsz>len) //strncpy                                  //~vb2oI~
        	memset(Ppdh->UDHname+len,0,(size_t)(buffsz-len));;     //~vb2oI~
    }                                                              //~vb2oI~
	UTRACEP("%s:rc=%x,srclen=%d,swfree=%d,new buffsz=%d,name=%s\n",UTT,rc,len,swfree,Ppdh->UDHnamebuffsz,Ppdh->UDHname);//~vb2oI~
    return rc;                                                     //~vb2oI~
}//dirupdatename                                                   //~vb2oI~
#endif                                                             //~vb2oI~
