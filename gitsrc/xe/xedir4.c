//*CID://+vb70R~:                             update#=  256;       //~vb70R~
//*************************************************************    //~v690I~
//*xedir4.c                                                        //~v690I~
//* description                                                    //~v690I~
//*************************************************************    //~v690I~
//vb70:161211 (Bug) dirlist crash when filename is locale and having slink is utf8//~vb70I~
//vb43:160717 ulib:v6E0:(W32)chk printable by iswprint for dbcs    //~vb43I~
//vb2p:160203 LNX compiler warning                                 //~vb2pI~
//vb2o:160203 try to malloc UDHname for performance(#ifndef MMM)   //~vb2oI~
//vb14:150613 0x00 is set for rename field display for U8-LC mixed string, set '.' for visibility//~vb14I~
//vb10:150327 for performance, UDHnameW malloc only when over limit size//~vb10I~
//vaz8:150109 C4244 except ULPTR and ULONG                         //~vaz8I~
//vawv:140610 (W32UNICODE)for ftp,enclose utf8 membname on UDHname //~vawvI~
//vawn:140605 (BUG)ddfmt display err for renamesv at cmd comp(getmixedstr fail to recover utf8 and display dbcs)//~vawnI~
//vaw2:140524 confirm pslinkW!=0(ulib dose not alloc for slinkWctr=0)//~vaw2I~
//vavJ:140403 (BUG)UDH alias was not set for path;dlcgetfullnamealias failed.//~vavJI~
//vavF:140401 (W32UNICODE)green pos on renamefld(utf ascii mix)    //~vavFI~
//vavd:140421 (Win;BUG of vava) did not nameW for path entry of dirlist//~vavdI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vav9:140410 (Win)unicode support(UD fmt string,_MAX_PATH changes)//~vav9I~
//vav4:140404 select dlcmd for utf8 subdir should apply fnm encoding determined on the dir list//~vav4I~
//vauE:140316 (Win)use ddfmt for dirlist;On cmd-prompt with setcp=65001,f2l dosenot change length but Windows display line shrinked//~vauEI~
//            use ddfmt to set USDfdata                            //~vauEI~
//vauD:140315 (Win BUG)Ctl+W(copyword to cmdline) from dirlist;keep original u8/lc and ignore kbd mode.//~vauDI~
//vauB:140315 (Win)Alt+W/Ctl+W on dirlist;u8 membername on dir list by fnu8 option,but string is treated by lc by env:lc on windows//~vauBI~
//vau1:140225 (LNX)all by ddfmt on psd(same as old for ascii only) //~vau1I~
//            that is simple for the case dbcs membername was renamed to utf8 name(need to back to cv to utf8 for membername)//~vau1I~
//vau0:140223 (LNX:BUG)utf8 filename on dirlist,filename locale:de is invalid if f2l on locale=ja_jp//~vau0I~
//            use ddfmt to set USDfdata                            //~vau0I~
//vand:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~vandI~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vagz:120917 (BUG)S+F10(display file desc on dirlist) abend by xeutfgetlocalestr did not chk outbuff size//~vagzI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafg:120616 for VC6:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafgI~
//va1q:091107 compchkm                                             //~va1qI~
//va1d:091101_(UTF8:BUG) edirlist edscription dispay size is short when F2l is done//~va1dI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          conv descname to locale if utf8                        //~va00I~
//v777:071204*EUC hankana chk(2byte but 1 column) hankana input not avail on rh9 but on fc5//~v777I~
//v720:061116 3270:listds fail by 'sys1.*' because sys1.duplex has no dsorg recfm//~v718I~
//            trate as special file for SYS1.VMASTCAT(VSAM) etc    //~v718I~
//v718:061003 dirlist description for remotefile is not supported(ignore option)//~v718I~
//v693:060423 (BUG)when scr resized,remains previous image         //~v693I~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//*************************************************************    //~v690I~
#include <time.h>                                                  //~v690I~
#include <stdio.h>                                                 //~v690I~
#include <stddef.h>                                                //~v690I~
#include <stdlib.h>                                                //~v690I~
#include <ctype.h>                                                 //~v690I~
#include <string.h>                                                //~v690I~
#ifdef UNX                                                         //~v690I~
	#include <sys/stat.h>                                          //~v690I~
#else  //!UNX                                                      //~v690I~
#ifdef DOS                                                         //~v690I~
#else                                                              //~v690I~
	#ifdef W32                                                     //~v690I~
    	#include <dos.h>                                           //~v690I~
		#include <windows.h>                                       //~v690I~
	#else                                                          //~v690I~
	#endif                                                         //~v690I~
#endif                                                             //~v690I~
#endif //!UNX                                                      //~v690I~
//*******************************************************          //~v690I~
#include <ulib.h>                                                  //~v690I~
#include <uerr.h>                                                  //~v690I~
#include <uque.h>                                                  //~v690I~
#include <ufile.h>                                                 //~v690I~
#include <ualloc.h>                                                //~v690I~
#include <ustring.h>                                               //~v690I~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include <udbcschk.h>                                              //~va00I~//~va1cR~
#include <utf.h>                                                   //~vau1I~
#include <utf22.h>                                                 //~vavaI~
#endif                                                             //~va1qI~
                                                                   //~v690I~
#ifdef UNX                                                         //~v690I~
	#include <uunxsub.h>                                           //~v690I~
#endif //UNX                                                       //~v690I~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include <utf.h>                                           //~v690I~//~va00R~
#include <utrace.h>                                                //~va00I~
#endif //UTF8SUPPH                                                 //~va00I~//~va1qM~
#include <ufilew.h>                                                //~vavaI~
                                                                   //~vavaI~
                                                                   //~v690I~
#include "xe.h"                                                    //~v690I~
#include "xescr.h"                                                 //~v690I~
#include "xefunc.h"                                                //~v690I~
#include "xefile.h"                                                //~v690I~
#include "xepan.h"                                                 //~v690I~
#include "xedir.h"                                                 //~v690I~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xedir2.h"                                                //~va00I~//~va1cR~
#endif                                                             //~va1qI~
#include "xedir3.h"                                                //~v690I~
#include "xedir4.h"                                                //~v690I~
#include "xedlcmd.h"                                               //~v690R~
#include "xedlcmd2.h"                                              //~v690I~
#include "xesub.h"                                                 //~v690I~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xefsub.h"                                            //~va00I~
	#include "xeutf.h"                                             //~va00I~
	#include "xeutf2.h"                                            //~vau0I~
#endif                                                             //~va00I~
#include "xecsr.h"                                                 //~v777I~
#include "xefsubw.h"                                               //~vavFI~
//**************************************************************** //~v690I~
int dirgetdescfromfile(char *Pfpath,char *Pbuff,int Pbufflen);     //~v690I~
int dirdescdbcschk(char *Pdesc,char *Pdbcs,int Plen);              //~v690I~
int dirgetstream(char *Pfpath,char *Pbuff,int Pbufflen);           //~v690R~
//#ifdef LNX                                                         //~vau1I~//~vauER~
	char *dirgetdescDDFMT(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PUDIRLH Ppdh,char *Pdesc,int Pdesclen);//~vau1I~
void dirdescdbcschkDDFMT(char *Pdesc,int Plen);                    //~vau1R~
//#endif                                                             //~vau1M~//~vauER~
#ifdef W32UNICODE                                                  //~vavaI~
int dirsetnameW(int Popt,PUDIRLIST Ppudl,PUDIRLH Ppdh);            //~vavaI~
#endif                                                             //~vavaI~
//**************************************************************** //~6418M~
//func_desc_dir                                                    //~6418M~
// toggle file description display(on DirList only)                //~6418M~
//*parm1:pcw                                                       //~6418M~
//*ret  :rc                                                        //~6418M~
//**************************************************************** //~6418M~
int func_desc_dir(PUCLIENTWE Ppcw)                                 //~6418M~
{                                                                  //~6418M~
	PUFILEC pfc;                                                   //~6418M~
	PUFILEH pfh;                                                   //~6418M~
//****************************                                     //~6418M~
    pfc=Ppcw->UCWpfc;                                              //~6418M~
	pfh=pfc->UFCpfh;                                               //~6418M~
#ifdef FTPSUPP                                                     //~v690R~
    if (FILEISREMOTE(pfh))                                         //~6418M~
    {                                                              //~6418M~
    	uerrmsg("DisplayFileDescription dose not support remote file",//~6418M~
        		"ファイル説明\x95\\示はリモートファイルをサポートしていません");//~6418M~
        return 4;                                                  //~6418M~
    }                                                              //~6418M~
#endif                                                             //~6418M~
    if (UCBITCHK(pfh->UFHflag7,UFHF7DESC))	//in that mode         //~v690R~
    {                                                              //~6418M~
    	UCBITOFF(pfh->UFHflag7,UFHF7DESC);	//normal size/timestamp display mode//~v690R~
    	uerrmsg("Reset FileDescriptionDisplay mode",               //~6418M~
        		"ファイル説明\x95\\示モードを解除。");             //~6418M~
    }                                                              //~6418M~
    else                                                           //~6418M~
    {                                                              //~6418M~
    	UCBITON(pfh->UFHflag7,UFHF7DESC);	//normal size/timestamp display mode//~v690R~
    	uerrmsg("Set FileDescriptionDisplay mode",                 //~6418M~
        		"ファイル説明\x95\\示モードに設定。");             //~6418M~
    }                                                              //~6418M~
    scrfulldraw(Ppcw);  //draw if another split screen exist       //~v690I~
//  dirddresetallsub(Ppcw,pfh);				//request line reset draw//~v693R~
    dirddresetallsub(DDRESET_DESC,Ppcw,pfh);				//request line reset draw//~v693I~
    return 0;                                                      //~6418M~
}//func_desc_dir                                                   //~6418M~
//**************************************************************** //~6418M~
//setup each file description for dirlist entry                    //~6418M~
//return description string                                        //~v690R~
//**************************************************************** //~6418M~
char *dirgetdesc(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PUDIRLH Ppdh)//~v690R~
{                                                                  //~6418M~
    char   fpath[_MAX_PATH];                                       //~v690R~
#ifdef UTF8SUPPH                                                   //~va1dI~
//  char   desc[UDIRLDSZ*UTF8_MAXCHARSZMAX];                       //~va1dI~//~vagzR~
    char   desc[UDIRLDSZ];                                         //~vagzR~
#else                                                              //~va1dI~
    char   desc[UDIRLDSZ];                                         //~v690I~
#endif                                                             //~va1dI~
    char   dbcswk[UDIRLDSZ];                                       //~v690R~
#ifdef UTF8SUPPH                                                   //~va00I~
    int  descwidth;                                                //~va00R~
//  char descwk[UDIRLDSZ];                                         //~va00R~//~va1cR~
    char descwk[UDIRLDSZ*MAX_MBCSLENLC];                           //~va00I~//~va1cR~
    char *plc;                                                     //~va00R~
#endif                                                             //~va00I~
    char   *pdesc;                                                 //~v690I~
    int desclen=0,maxdesclen=UDDDESCSZ;                            //~v690R~
//*****************                                                //~6418M~
    if (FILEISREMOTE(Ppfh))                                        //~v718R~
        return 0;                                                  //~v718I~
    if (UCBITCHK(Ppdh->UDHupdatetype,UDHUTNOTEXIST))	//deleted or moved or renamed//~6418M~
    	return 0;                                                  //~6418M~
    pdesc=Ppdh->UDHpdesc;                                          //~v690I~
    if (pdesc)                                                     //~v690I~
        if (!UCBITCHK(Ppdh->UDHflag2,UDHF2REFRESH))	//not refresh req//~v690I~
	        return pdesc;                                          //~v690R~
    UCBITOFF(Ppdh->UDHflag2,UDHF2REFRESH);	//refreshed            //~v690I~
    if (dlcgetfullname(Ppdh,fpath))                                //~6418M~
    	return 0;                                                  //~6418M~
	if (UCBITCHK(Ppfh->UFHflag7,UFHF7NTFS))	//drive is ntfs        //~v690R~
		desclen=dirgetstream(fpath,desc,maxdesclen+1);             //~v690R~
    if (!desclen && Ppdh->UDHtype!=UDHTFILE)	//dir etc          //~6418M~
		return 0;                                                  //~6418M~
    if (!desclen)			//no stream data                       //~6418M~
    {                                                              //~6418M~
//#ifdef UNX                                                       //~v720R~
#ifdef FTPSUPP                                                     //~v720R~
    	if (Ppdh->UDHattr & FILE_SPECIAL)                          //~6418M~
        {	                                                       //~6418M~
        	strcpy(desc,"Special File");                           //~6418M~
//          desclen=strlen(desc);                                  //~6418M~//~vb2pR~
            desclen=(int)strlen(desc);                             //~vb2pI~
        }                                                          //~6418M~
        else                                                       //~6418M~
        {                                                          //~6418M~
#endif                                                             //~6418M~
//  		*(desc+UDDDESCSZ)=0;	//null term                    //~v690I~//~vagzR~
    		*(desc+sizeof(desc)-1)=0;	//null term                //~vagzR~
#ifdef UTF8SUPPH                                                   //~va1dI~
			desclen=dirgetdescfromfile(fpath,desc,sizeof(desc));	//get description from file line//~va1dI~
#else                                                              //~va1dI~
			desclen=dirgetdescfromfile(fpath,desc,maxdesclen+1);	//get description from file line//~v690R~
#endif                                                             //~va1dI~
//#ifdef UNX                                                       //~v720R~
#ifdef FTPSUPP                                                     //~v720I~
        }                                                          //~6418M~
#endif                                                             //~6418M~
    }                                                              //~6418M~
//#ifdef LNX                                                         //~vau1I~//~vauER~
    if ((Gotheropt & GOTHERO_DDFMTDL))                             //~vau1I~
		return dirgetdescDDFMT(Ppcw,Ppfh,Pplh,Ppdh,desc,desclen);  //~vau1R~
//#endif                                                             //~vau1R~//~vauER~
    if (desclen)                                                   //~v690R~
#ifdef UTF8SUPPH                                                   //~va00I~
    {                                                              //~va00I~
	    plc=xeutf_getlocalestr(desc,desclen,descwk,sizeof(descwk),&descwidth,0/*charwidth*/);//~va00R~
		if (XEUTFGLRC_ISF2L(plc)) /*utf8->locale conversion done*/ //~va00R~
        {                                                          //~va00I~
        	UCBITON(Ppdh->UDHflag3,UDHF3DESCATTR);                 //~va00I~
//          desclen=descwidth;                                     //~va00R~//~va1cR~
//          memcpy(desc,descwk,(UINT)descwidth);                   //~va00I~//~va1cR~
            desclen=min(descwidth,maxdesclen);                     //~va00I~//~va1cR~
            memcpy(desc,descwk,(UINT)desclen);                     //~va00I~//~va1cR~
        }                                                          //~va00I~
        else                                                       //~va00I~
        {                                                          //~va1dI~
            desclen=min(desclen,maxdesclen);	//cut over read for utf8 string chk//~va1dR~
        	UCBITOFF(Ppdh->UDHflag3,UDHF3DESCATTR);                //~va00I~
        }                                                          //~va1dI~
#endif                                                             //~va00I~
	    desclen=dirdescdbcschk(desc,dbcswk,desclen);	//dbcs split ,ctl char rep//~v690R~
#ifdef UTF8SUPPH                                                   //~va00I~
	}                                                              //~va00I~
#endif                                                             //~va00I~
    if (!pdesc) //initial                                          //~v690R~
    {                                                              //~6418M~
    	Ppdh->UDHpdesc=pdesc=umalloc(UDDDESCSZ+1);                 //~6418M~
        if (!pdesc)  	//malloc failed                            //~6418M~
        	return 0;                                              //~6418M~
    }                                                              //~6418M~
    Ppdh->UDHdesclen=desclen;	//net length                       //~v690I~
    if (desclen)                                                   //~v690I~
	    memcpy(pdesc,desc,(UINT)desclen);                          //~v690R~
//  if ((UINT)desclen<UDDDESCSZ)                                   //~v690R~//~vb2pR~
    if (desclen<UDDDESCSZ)                                         //~vb2pI~
	    memset(pdesc+desclen,' ',(UINT)(UDDDESCSZ-desclen));       //~v690I~
    desclen=UDDDESCSZ;                                             //~v690I~
    *(pdesc+desclen)=0;                                            //~v690I~
    return pdesc;                                                  //~v690R~
}//dirgetdesc                                                      //~v690R~
//#ifdef LNX                                                         //~vau1I~//~vauER~
//**************************************************************** //~vau1I~
//setup each file description for dirlist entry by ddfmt           //~vau1I~
//return description string                                        //~vau1I~
//**************************************************************** //~vau1I~
char *dirgetdescDDFMT(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PUDIRLH Ppdh,char *Pdesc,int Pdesclen)//~vau1I~
{                                                                  //~vau1I~
    UCHAR   *pdesc,*pdddata=NULL,*pdddbcs=NULL;                    //~vauER~
//  char   dbcswk[UDDDESCSZ];                                      //~vauER~
    char   dbcswk[UDIRLDSZ];                                       //~vauEI~
    int opt,rc2,rc,desclen,readlen,lendd;                          //~vau1R~
//*****************                                                //~vau1I~
    UCBITOFF(Ppdh->UDHflag3,UDHF3DESCATTR);                        //~vau1I~
    UCBITOFF(Ppdh->UDHflag4,(UDHF4DESCU8|UDHF4DESCLC));            //~vau1I~
    pdesc=Ppdh->UDHpdesc;                                          //~vau1I~
    desclen=min(Pdesclen,(int)UDDDESCSZ);                          //~vauER~
    if (desclen)                                                   //~vau1R~
    {                                                              //~vau1I~
		opt=UTFCVO_EOLSPLITOK;  //allow last char cut by length    //~vau1I~
  		rc2=utfisvalidutf8(opt,Pdesc,desclen,dbcswk,0/*chof*/,&readlen,0/*ucscnt*/,NULL);//~vau1R~
    	if (rc2==UTFIVURC_ALLASCII)  //2                           //~vau1I~
        {                                                          //~vau1I~
	    	desclen=dirdescdbcschk(Pdesc,dbcswk,desclen);	//dbcs split ,ctl char rep//~vau1I~
        	pdddata=Pdesc;                                         //~vau1I~
            pdddbcs=dbcswk;                                        //~vau1I~
        }                                                          //~vau1I~
        else                                                       //~vau1I~
    	if (rc2==UTFIVURC_VALIDUTF)  //1                           //~vau1I~
        {                                                          //~vau1I~
			dirdescdbcschkDDFMT(Pdesc,readlen);                    //~vau1I~
	    	opt=0;                                                 //~vau1I~
			rc=xeutf_cvf2dd(opt,Pdesc,readlen,&pdddata,&pdddbcs,&lendd);//~vau1I~
    		if (rc==UALLOC_FAILED)                                 //~vau1I~
    			return NULL;                                       //~vau1I~
        	UCBITON(Ppdh->UDHflag3,UDHF3DESCATTR);	//set attr     //~vau1R~
		    UCBITON(Ppdh->UDHflag4,UDHF4DESCU8);                   //~vau1I~
            desclen=lendd;                                         //~vau1I~
        }                                                          //~vau1I~
        else	//locale                                           //~vau1I~
        {                                                          //~vau1I~
	    	desclen=dirdescdbcschk(Pdesc,dbcswk,desclen);	//dbcs split ,ctl char rep//~vau1M~
    		opt=0;                                                 //~vau1I~
			rc=xeutfcvl2dd(opt,Pdesc,desclen,&pdddata,&pdddbcs,&lendd);//~vau1R~
    		if (rc==UALLOC_FAILED)                                 //~vau1I~
    			return NULL;                                       //~vau1I~
		    UCBITON(Ppdh->UDHflag4,UDHF4DESCLC);                   //~vau1I~
            desclen=min(lendd,(int)UDDDESCSZ);                     //~vauER~
        }                                                          //~vau1I~
	}                                                              //~vau1I~
    if (!pdesc) //initial                                          //~vau1I~
    {                                                              //~vau1I~
    	Ppdh->UDHpdesc=pdesc=umalloc(UDDDESCSZ*2);                 //~vau1R~
        if (!pdesc)  	//malloc failed                            //~vau1I~
        	return NULL;                                           //~vau1R~
    }                                                              //~vau1I~
    Ppdh->UDHdesclen=desclen;	//net length                       //~vau1I~
    UTRACEP("dirgetdescDDFMT desclen=%d\n",desclen);               //~vau1I~
    if (desclen)                                                   //~vau1I~
    {                                                              //~vau1I~
	    memcpy(pdesc,pdddata,(UINT)desclen);                       //~vau1R~
	    memcpy(pdesc+UDDDESCSZ,pdddbcs,(UINT)desclen);             //~vau1R~
    }                                                              //~vau1I~
//  if ((UINT)desclen<UDDDESCSZ)                                   //~vau1I~//~vb2pR~
    if (desclen<UDDDESCSZ)                                         //~vb2pI~
    {                                                              //~vau1I~
	    memset(pdesc+desclen,' ',(UINT)(UDDDESCSZ-desclen));       //~vau1I~
	    memset(pdesc+UDDDESCSZ+desclen,0,(UINT)(UDDDESCSZ-desclen));//~vau1R~
    }                                                              //~vau1I~
    desclen=UDDDESCSZ;                                             //~vau1I~
    return pdesc;                                                  //~vau1I~
}//dirgetdescDDFMT                                                 //~vau1I~
//#endif  //LNX                                                      //~vau1I~//~vauER~
//**************************************************************** //~v690M~
//read stream data as file description                             //~v690M~
//return description string len                                    //~v690M~
//**************************************************************** //~v690M~
int dirgetstream(char *Pfpath,char *Pbuff,int Pbufflen)            //~v690I~
{                                                                  //~v690M~
#ifndef W32                                                        //~v690I~
	return 0;                                                      //~v690I~
#else                                                              //~v690I~
static char Sstreamname[]={XESTREAMNAME};                          //~v690R~
    HANDLE  hStream;                                               //~v690M~
	char snm[_MAX_PATH+32];                                        //~v690M~
    int outmaxlen,readlen;                                         //~v690M~
    DWORD dwlen;                                                   //~vafgI~
//*********************************                                //~v690M~
	outmaxlen=Pbufflen-1;                                          //~v690M~
    *(Pbuff+outmaxlen)=0;	//strz                                 //~v690M~
    *Pbuff=':';                                                    //~v690I~
    outmaxlen--;                                                   //~v690I~
	sprintf(snm,"%s:%s",Pfpath,Sstreamname);                       //~v690M~
    hStream=CreateFile(snm,GENERIC_READ,FILE_SHARE_READ,NULL,      //~v690M~
                            OPEN_EXISTING,0,NULL);                 //~v690M~
    if( hStream==INVALID_HANDLE_VALUE )                            //~v690M~
    	return 0;	//no stream                                    //~v690M~
//  ReadFile(hStream,Pbuff+1,outmaxlen,&readlen,NULL);             //~v690R~//~vafgR~
    ReadFile(hStream,Pbuff+1,(DWORD)outmaxlen,&dwlen,NULL);        //~vafgI~
    readlen=(int)dwlen;                                            //~vafgI~
    *(Pbuff+1+readlen)=0;                                          //~v690R~
    CloseHandle(hStream);                                          //~v690M~
    return readlen+1;                                              //~v690R~
#endif                                                             //~v690M~
}//dirgetstream                                                    //~v690M~
//**************************************************************** //~6418M~
//setup each file description for dirlist entry                    //~6418M~
//return description string len                                    //~v690R~
//**************************************************************** //~6418M~
int dirgetdescfromfile(char *Pfpath,char *Pbuff,int Pbufflen)      //~v690R~
{                                                                  //~6418M~
	FILE *fh;                                                      //~v690I~
	char buff[DESCRIPTIONRANGE],*pc,*pce;                          //~v690R~
static  char Sdescid[]={DESCRIPTIONID};                            //~v690I~
	int fsz,outlenmax,len,ch;                                      //~v690R~
#ifdef UTF8SUPPH                                                   //~va1dI~
    int binsw;                                                     //~va1dI~
#endif                                                             //~va1dI~
//***************************                                      //~v690I~
	outlenmax=Pbufflen-1;                                          //~v690I~
    *(Pbuff+outlenmax)=0;	//set null term                        //~v690R~
	fh=fopen(Pfpath,"rb");                                         //~v690I~
    if (!fh)                                                       //~v690I~
    {                                                              //~v690I~
    	strncpy(Pbuff,"Cannot Open",(UINT)Pbufflen);               //~v693R~
        return (int)strlen(Pbuff);                                 //~v690I~
    }                                                              //~v690I~
    fsz=(int)fread(buff,1,DESCRIPTIONRANGE,fh);                    //~v693R~
    pc=umemmem(buff,Sdescid,(UINT)fsz,sizeof(Sdescid)-1);          //~v693R~
    if (pc)                                                        //~v690I~
    	pc+=sizeof(Sdescid)-1;                                     //~v690I~
    else                                                           //~v690I~
    {                                                              //~v690I~
        for (pc=buff,pce=pc+fsz;pc<pce;pc++)	//skip top null line//~v690R~
        {                                                          //~v690I~
        	ch=*pc;                                                //~v690I~
    		if (ch!=' '&&ch!='\t'&&ch!='\r'&&ch!='\n')             //~v690R~
            	break;                                             //~v690I~
        }                                                          //~v690I~
    }                                                              //~v690I~
//  len=(int)(fsz-((ULONG)pc-(ULONG)buff));                        //~v693R~//~vafkR~
//  len=(int)(fsz-((ULPTR)pc-(ULPTR)buff));                        //~vafkI~//~vb2pR~
    len=fsz-PTRDIFF(pc,buff);                                      //~vb2pI~
    len=min(outlenmax,len);                                        //~v690R~
    memcpy(Pbuff,pc,(UINT)len);                                    //~v693R~
#ifdef UTF8SUPPH                                                   //~va1dI~
    binsw=memchr(Pbuff,0,(UINT)len)!=0;                            //~va1dI~
  if (!binsw)                                                      //~va1dI~
#endif                                                             //~va1dI~
  {                                                                //~va1dI~
    if (pc=memchr(Pbuff,'\r',(UINT)len),pc)  //MAC or PC  (x0d)    //~v690R~
//      len=(int)((ULONG)pc-(ULONG)Pbuff);                         //~v693R~//~vafkR~
        len=(int)((ULPTR)pc-(ULPTR)Pbuff);                         //~vafkI~
    else                                                           //~v690I~
    if (pc=umemrchr(Pbuff,'\n',(UINT)len),pc)  //UNIX       (x0a)  //~v690R~
//      len=(int)((ULONG)pc-(ULONG)Pbuff);                         //~v693R~//~vafkR~
        len=(int)((ULPTR)pc-(ULPTR)Pbuff);                         //~vafkI~
  }                                                                //~va1dI~
    fclose(fh);                                                    //~v690I~
    return len;                                                    //~v690R~
}//dirgetdescfromfile                                              //~v690R~
//**************************************************************** //~v690I~
//rep ctl char by "." with chk DBCS                                //~v690R~
//return description string len                                    //~v690I~
//**************************************************************** //~v690I~
int dirdescdbcschk(char *Pdesc,char *Pdbcs,int Plen)               //~v690I~
{                                                                  //~v690I~
	int len;                                                       //~v690I~
    char *pc,*pcd,*pce;                                            //~v690I~
//***************************                                      //~v690I~
	len=Plen;                                                      //~v690I~
#ifdef UTF8SUPPH                                                   //~va00I~//~va1cR~
	dirsetdbcstbl(0,Pdesc,Pdbcs,Plen);	//dbcs split char is fully dbcserr//~va00I~//~va1cR~
#else                                                              //~va00I~//~va1cR~
	setdbcstbl(Pdesc,Pdbcs,Plen);                                  //~v690I~
#endif                                                             //~va00I~//~va1cR~
    for (pc=Pdesc,pcd=Pdbcs,pce=pc+len;pc<pce;pc++,pcd++)          //~v690I~
    {                                                              //~v690I~
    	switch(*pcd)                                               //~v690I~
        {                                                          //~v690I~
        case DBCS1STCHAR:	//end with first byte                  //~v690I~
  		case DBCS2NDCHAR:	//start with second byte               //~v690I~
#ifdef UTF8SUPPH                                                   //~va00I~//~va1cR~
  		case UDBCSCHK_DBCSPAD:	//gb4 intermediate                 //~va00I~//~va1cR~
#endif                                                             //~va00I~//~va1cR~
            break;                                                 //~v690I~
        default:                                                   //~v690I~
            if (*pcd)       //UDBCSCHK_HKDBCSERR                   //~v690I~
            	*pc='.';	//rep by period                        //~v690I~
            else                                                   //~v690I~
#ifdef UTF8SUPPH                                                   //~va00I~
        	if (*pc<0x20 //ctl char                                //~va00R~//~va1cR~
            ||  !UDBCSCHK_ISPRINT(*pc)                             //~va00I~//~va1cR~
            )                                                      //~va00I~//~va1cR~
#else                                                              //~va00R~
        	if (*pc<0x20||*pc>0x7f) //not ascii                    //~v690R~
#endif                                                             //~va00I~
            	*pc='.';	//rep by period                        //~v690I~
        }                                                          //~v690I~
    }                                                              //~v690I~
#ifdef UTF8SUPPH                                                   //~va00I~//~va1cR~
//dirsetdbcstbl set HKDBCSERR for split dbcs                       //~va00I~//~va1cR~
#else                                                              //~va00I~//~va1cR~
    if (*(pcd-1)==DBCS1STCHAR)	//dbcs split                       //~v690I~
    {                                                              //~v690I~
    	len--;                                                     //~v690I~
    	*(pc-1)=0;                                                 //~v690R~
    }                                                              //~v690I~
#endif                                                             //~va00I~//~va1cR~
    return len;                                                    //~v690I~
}//dirdescdbcschk                                                  //~v690I~
//#ifdef LNX                                                         //~vau1I~//~vauER~
//**************************************************************** //~vau1I~
//rep ctl char of utf8 str by "."                                  //~vau1I~
//**************************************************************** //~vau1I~
void dirdescdbcschkDDFMT(char *Pdesc,int Plen)                     //~vau1R~
{                                                                  //~vau1I~
	int len;                                                       //~vau1I~
    char *pc,*pce;                                                 //~vau1I~
//***************************                                      //~vau1I~
	len=Plen;                                                      //~vau1I~
    for (pc=Pdesc,pce=pc+len;pc<pce;pc++)                          //~vau1I~
    {                                                              //~vau1I~
    	if (*pc<0x20) //ctl char                                   //~vau1I~
            	*pc='.';	//rep by period                        //~vau1I~
    }                                                              //~vau1I~
}//dirdescdbcschkDDFMT                                             //~vau1I~
//#endif                                                             //~vau1I~//~vauER~
#ifdef UTF8SUPPH                                                   //~va00I~
//**********************************************************************//~va00I~
// set utf8name for sort by utf8name seq                           //~va00I~
// ret:UALLOC_FAILED(utf8 inf cleared but pudirlist is not free)   //~va00I~
//**********************************************************************//~va00I~
//int dirsetlocalename(int Popt,PUDIRLIST Ppudl,PUDIRLH Ppdh)        //~va00I~//~vagER~
int dirsetlocalename(int Popt,PUDIRLIST Ppudl,PUFILEH Ppfh,PUDIRLH Ppdh)//~vagEI~
{                                                                  //~va00I~
    int flag=UDHF3U8SET,rc,rc2,outlen,srclen;                      //~va00R~
    char *pmemb;                                                   //~va00R~
    int opt;                                                       //~vagEI~
    int opt2;                                                      //~vb70R~
//***********************                                          //~va00I~
    if (!strcmp(Ppdh->UDHname,".") || !strcmp(Ppdh->UDHname,".."))	//pathname resolved entry//~va00R~
        return 0;        //set later from setlocalenameforpath     //~va00I~
#ifdef W32UNICODE                                                  //~vavaI~
	if (rc2=dirsetnameW(0,Ppudl,Ppdh))                             //~vavaI~
    	return rc2;	//alloc err                                    //~vavaI~
  if ((Ppudl->ffb3otherflag & FFB3OF_SUBCHFNAME) && Ppudl->nameWctr)//~vavaI~
  {                                                                //~vavaI~
	dirsetddfmtname(DSDFO_MEMBNAME|DSDFO_UTF16,Ppdh,(char*)Ppudl->nameW,Ppudl->nameWctr);//~vavaI~
	flag|=UDHF3U8LC;  //originaly locale code                      //~vavaI~
    Ppdh->UDHflag5|=UDHF5SUBCHFNAME;                               //~vavaI~
    opt=0;  //uninit warning                                       //~vaw2I~
  }                                                                //~vavaI~
  else                                                             //~vavaI~
#endif                                                             //~vavaI~
  {                                                                //~vavaI~
    pmemb=Ppudl->name;                                             //~va00I~
//  srclen=strlen(pmemb);                                          //~va00I~//~vb2pR~
    srclen=(int)strlen(pmemb);                                     //~vb2pI~
    opt=0;                                                         //~vagEI~
	if (Popt & DIRSLNO_FNMEMB)  //from dirsetlocalenameforpath;apply member FN option//~vav4I~
    {                                                              //~vav4I~
    	if (UCBITCHK(Ppfh->UFHflag13,UFHF13SELECTFNU8))            //~vav4I~
	        opt|=FSUBF2LO_FNU8;   //select utf8 for filename encoding if both utf8 and locale is valid//~vav4I~
        else                                                       //~vav4I~
	        opt|=FSUBF2LO_FNLC;   //select localecode for filename encoding if both utf8 and locale is valid//~vav4I~
    }                                                              //~vav4I~
    else                                                           //~vav4I~
    if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNU8))                      //~vagER~
        opt|=FSUBF2LO_FNU8;   //select utf8 for filename encoding if both utf8 and locale is valid//~vagEI~
    else                                                           //~vagEI~
    if (UCBITCHK(Ppfh->UFHflag12,UFHF12FNLC))                      //~vagER~
        opt|=FSUBF2LO_FNLC;   //select localecode for filename encoding if both utf8 and locale is valid//~vagEI~
#ifdef W32UNICODE                                                  //~vavcI~
//FIXME remote was set?:FIXED                                      //~vavcI~//~vaw2R~
	if (FILEISREMOTE(Ppfh))                                        //~vavcI~
        opt|=FSUBF2LO_REMOTE;   //select localecode for filename encoding if both utf8 and locale is valid//~vavcI~
#endif                                                             //~vavcI~
//  if (rc2=fsubf2l(FSUBF2LO_ALLOC|FSUBF2LO_ALLOCFULLSZ|FSUBF2LO_FREEIFNZ,pmemb,srclen,0/*locale out*/,&(Ppdh->UDHnamef2l),&rc,&outlen),rc2)//~va00R~//~vagER~
#ifdef MMM                                                         //~vb2oI~
    if (rc2=fsubf2l(FSUBF2LO_ALLOC|FSUBF2LO_ALLOCFULLSZ|FSUBF2LO_FREEIFNZ|opt,pmemb,srclen,0/*locale out*/,&(Ppdh->UDHnamef2l),&rc,&outlen),rc2)//~vagEI~
    	return rc2;                                                //~va00I~
#else                                                              //~vb2oI~
    if (rc2=fsubf2l(FSUBF2LO_ALLOC/*|FSUBF2LO_ALLOCFULLSZ*/|FSUBF2LO_FREEIFNZ|opt,pmemb,srclen,0/*locale out*/,&(Ppdh->UDHnamef2l),&rc,&outlen),rc2)//~vb2oI~
    	return rc2;                                                //~vb2oI~
    Ppdh->UDHnamef2lstrlen=outlen; //strlen                        //~vb2oI~
#endif                                                             //~vb2oI~
    switch(rc)                                                     //~va00I~
    {                                                              //~va00I~
    case UTFGUSRC_ALLASCII:                                        //~va00I~
//*=0=!(XEUTFGUMRC_UTF8|XEUTFGU8MRC_LC)                            //~vavdI~
//FIXME test:FIXED                                                 //~vavdI~//~vaw2R~
        break;                                                     //~va00I~
    case UTFGUSRC_ALLUTF8:  //f2l done                             //~va00I~
//*=1=XEUTFGU8MRC_UTF8                                             //~vavdI~
//FIXME test:      no PATH on Win except FTP,intercepted by SUBCH                                        //~vavdI~//~vaw2R~//~vawnR~
        flag|=UDHF3U8UTF;      //memberbname is all utf8           //~va00R~
#ifdef W32UNICODE                                                  //~vawvI~
		if (FILEISREMOTE(Ppfh))                                    //~vawvI~
        {                                                          //~vawvI~
            char *pud;                                             //~vawvI~
			pud=Ppdh->UDHname; //output UD str                     //~vawvR~
#ifdef MMM                                                         //~vb2oI~
        	ufilecvencloseu8(0,UD_UTF8WC,pmemb,srclen,&pud,sizeof(Ppdh->UDHname),NULL/*outlen*/);//~vawvR~
#else                                                              //~vb2oI~
        	ufilecvencloseu8(0,UD_UTF8WC,pmemb,srclen,&pud,Ppdh->UDHnamebuffsz,NULL/*outlen*/);//UDHname buffer has allowance of UD fmt//~vb2oI~
#endif                                                             //~vb2oI~
            pmemb=pud;                                             //~vawvI~
        }                                                          //~vawvI~
#endif                                                             //~vawvI~
//#ifdef LNX                                                         //~vau0I~//~vauER~
		dirsetddfmtname(DSDFO_MEMBNAME,Ppdh,pmemb,srclen);	       //~vau0R~
//#endif                                                             //~vau0I~//~vauER~
        break;                                                     //~va00I~
    default:    //lc conv done                                     //~va00I~
//*=2=XEUTFGU8MRC_LC                                               //~vavdI~
//FIXME test:FIXED                                                 //~vavdI~//~vaw2R~
        flag|=UDHF3U8LC;  //originaly locale code                  //~va00I~
//#ifdef LNX                                                         //~vau0I~//~vauER~
#ifdef W32UNICODE                                                  //~vavaM~
  	  if (Ppudl->nameWctr)	//by original code                     //~vav0I~//~vavaI~
    	dirsetddfmtname(DSDFO_MEMBNAME|DSDFO_UTF16,Ppdh,(char*)Ppudl->nameW,Ppudl->nameWctr);//~vavaM~
      else                                                         //~vavaM~
#endif                                                             //~vavaM~
//  	dirsetddfmtname(DSDFO_MEMBNAME|DSDFO_L2DD,Ppdh,pmemb,srclen);//~vb14R~
      {                                                            //~vb14I~
        opt2=opt; //save                                           //~vb70M~
    	opt=DSDFO_MEMBNAME|DSDFO_L2DD|DSDFO_ERRREP;                //~vb14I~
    	dirsetddfmtname(opt,Ppdh,pmemb,srclen);                    //~vb14I~
        opt=opt2; //restore                                        //~vb70R~
      }                                                            //~vb14I~
//#endif                                                             //~vau0I~//~vauER~
    }                                                              //~va00I~
UTRACEP("dirsetlocalename fsubf2l-rc=%d pudl=%s,pdhf2l=%s\n",rc,pmemb,Ppdh->UDHnamef2l);//~va00I~//~vauDR~
  }//subchrc                                                       //~vavaI~
//  pmemb=Ppudl->slink;                                            //~va00I~//~vandR~
    pmemb=Ppudl->pslink;                                           //~vandI~
//  if (*pmemb)                                                    //~va00I~//~vandR~
    if (pmemb && *pmemb)                                           //~vandI~
    {                                                              //~va00I~
#ifdef W32UNICODE                                                  //~vavaI~
	  if ((Ppudl->ffb3otherflag & FFB3OF_SUBCHSLINK))              //~vavaI~
      {                                                            //~vavaI~
		dirsetddfmtname(DSDFO_SLINKNAME|DSDFO_UTF16,Ppdh,(char*)Ppudl->pslinkW,Ppudl->pslinkWctr);//~vavaI~
	    flag|=UDHF3U8LCSL;  //originaly locale code                //~vavaI~
	    Ppdh->UDHflag5|=UDHF5SUBCHSLINK;                           //~vavaI~
      }                                                            //~vavaI~
	  else                                                         //~vavaI~
#endif                                                             //~vavaI~
      {                                                            //~vavaI~
//      srclen=strlen(pmemb);                                      //~va00I~//~vb2pR~
        srclen=(int)strlen(pmemb);                                 //~vb2pI~
//#ifdef LNX                                                         //~vau1I~//~vauER~
		{//do not change original code(getwordslink use original code)//~vau1R~
//          char wklc[_MAX_PATH*UTF8_F2LMAXRATE];                  //~vau1I~//~vav9R~
            char wklc[_MAX_PATHF2L];                               //~vav9I~
    		rc2=fsubf2l(opt,pmemb,srclen,wklc,NULL/*Pplc,not used when alloc/free optiion off*/,&rc,&outlen);//~vau1R~
	    	if (rc2)                                               //~vau1I~
	    		return rc2;                                        //~vau1I~
        }                                                          //~vau1I~
//#else                                                              //~vau1I~//~vauER~
////      if (rc2=fsubf2l(FSUBF2LO_ALLOC|FSUBF2LO_FREEIFNZ,pmemb,srclen,0/*localeout*/,&(Ppdh->UDHslink),&rc,&outlen),rc2)//~va00R~//~vagER~//~vauER~
//        if (rc2=fsubf2l(FSUBF2LO_ALLOC|FSUBF2LO_FREEIFNZ|opt,pmemb,srclen,0/*localeout*/,&(Ppdh->UDHslink),&rc,&outlen),rc2)//~vagEI~//~vauER~
//            return rc2;                                            //~va00I~//~vauER~
//#endif                                                             //~vau1I~//~vauER~
//        switch(rc)                                                 //~va00I~//~vavaR~
//        {                                                          //~va00I~//~vavaR~
//        case UTFGUSRC_ALLASCII:                                    //~va00I~//~vavaR~
//            break;                                                 //~va00I~//~vavaR~
//        case UTFGUSRC_ALLUTF8:                                     //~va00I~//~vavaR~
		  if (rc & XEUTFGU8MRC_UTF8) //  0x01                      //~vavaR~
          {                                                        //~vavaI~
	        flag|=UDHF3U8UTFSL;      //memberbname is all utf8     //~va00R~
//#ifdef LNX                                                         //~vau0I~//~vauER~
			dirsetddfmtname(DSDFO_SLINKNAME,Ppdh,pmemb,srclen);    //~vau0R~
//#else                                                              //~vauBI~//~vauER~
//            Ppdh->UDHslinknameu8len=0;                             //~vauBI~//~vauER~
//            UFREEIFNZ(Ppdh->UDHslinknameu8);                       //~vauBI~//~vauER~
//            Ppdh->UDHslinknameu8=umalloc(srclen+1);                //~vauBR~//~vauER~
//            if (Ppdh->UDHslinknameu8)                              //~vauBI~//~vauER~
//            {//save original name for Ctl+W/Alt+W                  //~vauBI~//~vauER~
//                UmemcpyZ(Ppdh->UDHslinknameu8,pmemb,srclen);       //~vauBR~//~vauER~
//                Ppdh->UDHslinknameu8len=srclen;                    //~vauBI~//~vauER~
//            }                                                      //~vauBI~//~vauER~
//#endif                                                             //~vau0I~//~vauER~
//            break;                                                 //~va00I~//~vavaR~
          }                                                        //~vavaI~
//        default:    //name by locale code                          //~va00I~//~vavaR~
          else                                                     //~vavaI~
		  if (rc & XEUTFGU8MRC_LC)   //0x02                        //~vavaR~
          {                                                        //~vavaI~
	        flag|=UDHF3U8LCSL;  //originaly locale code            //~va00I~
//#ifdef LNX                                                         //~vau0I~//~vauER~
			dirsetddfmtname(DSDFO_SLINKNAME|DSDFO_L2DD,Ppdh,pmemb,srclen);//~vau0I~
          }                                                        //~vavaI~
//#endif                                                             //~vau0I~//~vauER~
//        }                                                          //~va00I~//~vavaR~
      }//subchrc                                                   //~vavaI~
    }                                                              //~va00I~
//  Ppdh->UDHflag3=flag;                                           //~vaz8R~
    Ppdh->UDHflag3=(UCHAR)flag;                                    //~vaz8I~
    return 0;                                                      //~va00I~
}//dirsetlocalename                                                //~va00I~
//**************************************************************** //~vavdI~
void dirgetfstatforpath(int Popt,PUFILEH Ppfh,PUDIRLH Ppdh,PUDIRLIST Ppudl)//~vavdI~
{                                                                  //~vavdI~
	int dirlevel;                                                  //~vavdI~
    char fpath[_MAX_PATH];;                                        //~vavdI~
//****************************                                     //~vavdI~
	if (FILEISREMOTE(Ppfh))                                        //~vavdR~
    	return;                                                    //~vavdI~
    dirlevel=Ppdh->UDHlevel;                                       //~vavdI~
    strcpy(fpath,Ppfh->UFHfilename);	//long name                //~vavdI~
    dirgetfstat(DGFSO_PATH,     //fstat for intermediate path      //~vavdI~
               Ppfh,fpath,dirlevel,Ppudl);	//set fstat3 of parent //~vavdI~
}//dirgetfstatforpath                                              //~vavdI~
//**************************************************************** //~va00M~
//!dirsetutf8nameforpath                                           //~va00M~
//* setup to display member name by utf8 for path entry            //~va00M~
//*retrn	0,UALLOC_FAILED for path entry                         //~va00M~
//**************************************************************** //~va00M~
//int dirsetlocalenameforpath(PUDIRLH Ppdh)                          //~va00R~//~vagER~
int dirsetlocalenameforpath(PUFILEH Ppfh,PUDIRLH Ppdh)             //~vagEI~
{                                                                  //~va00M~
//	UDIRLIST udlwk;                                                //~va00M~//~vandR~
//	UDIRLIST_WK(udlwk,wkslinkname);                                //~vandI~//~vb70R~
  	UDIRLIST_WK(udlwk,wkname,wknamew,wkslinkname);                 //~vb70I~
    int rc;                                                        //~va00M~
    int lenfpath,lenfnm,opt=0;                                     //~vav4I~
    char *pfpath,*pfnm;                                            //~vav4I~
//****************************                                     //~va00M~
//  memset(&udlwk,0,sizeof(udlwk));                                //~va00M~//~vandR~
//  UDIRLIST_WK_INIT(udlwk,wkslinkname);                           //~vandR~//+vb70R~
    UDIRLIST_WK_INIT(udlwk,wkname,wknamew,wkslinkname);            //+vb70I~
//  strcpy(udlwk.name,Ppdh->UDHname);                              //~va00M~//~vb70R~
    udirlist_setname(0,&udlwk,Ppdh->UDHname,0);                    //~vb70I~
#ifdef W32UNICODE                                                  //~vavdI~
    dirgetfstatforpath(0,Ppfh,Ppdh,&udlwk);                        //~vavdR~
#endif                                                             //~vavdI~
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13SELECTFNU8|UFHF13SELECTFNLC))//~vav4I~
    {                                                              //~vav4I~
    	pfpath=Ppfh->UFHfilename;                                  //~vav4I~
        pfnm=Ppdh->UDHname;                                        //~vav4I~
//  	lenfpath=strlen(pfpath);                                   //~vav4I~//~vb2pR~
    	lenfpath=(int)strlen(pfpath);                              //~vb2pI~
//  	lenfnm=strlen(pfnm);                                       //~vav4I~//~vb2pR~
    	lenfnm=(int)strlen(pfnm);                                  //~vb2pI~
//  	if (lenfpath>lenfnm && !memicmp(pfnm,pfpath+lenfpath-lenfnm,lenfnm))//~vav4I~//~vb2pR~
    	if (lenfpath>lenfnm && !memicmp(pfnm,pfpath+lenfpath-lenfnm,(UINT)lenfnm))//~vb2pI~
        {                                                          //~vav4I~
			opt=DIRSLNO_FNMEMB;// 0x01 //apply member FN option    //~vav4I~
        }                                                          //~vav4I~
    }                                                              //~vav4I~
#ifdef W32UNICODE                                                  //~vaw2I~
    memcpy(Ppdh->UDHalias,udlwk.alias,sizeof(Ppdh->UDHalias));     //~vavJR~
#endif                                                             //~vaw2I~
//  rc=dirsetlocalename(0,&udlwk,Ppdh);                            //~va00M~//~vagER~
//  rc=dirsetlocalename(0,&udlwk,Ppfh,Ppdh);                       //~vagEI~//~vav4R~
    rc=dirsetlocalename(opt,&udlwk,Ppfh,Ppdh);                     //~vav4I~
    UTRACED("udlwk",&udlwk,sizeof(udlwk));                         //~vb10R~
    return rc;                                                     //~va00M~
}//dirsetlocalenameforpath                                         //~va00M~
#endif                                                             //~va00I~
//**************************************************               //~v777I~
//* csr move acording CSD option using UCWkeytype                  //~v777I~
//* parm1:pcw                                                      //~v777I~
//**************************************************               //~v777I~
int dircharcsr(PUCLIENTWE Ppcw)                                    //~v777I~
{                                                                  //~v777I~
	int 	rc=0;                                                  //~v777I~
	int 	step;                                                  //~v777I~
//****************************                                     //~v777I~
    if (Ppcw->UCWreason==UCWREASON_CSRBYKEYTYPE)                   //~v777I~
    	step=Ppcw->UCWkeytype;                                     //~v777I~
    else                                                           //~v777I~
    	step=0;                                                    //~v777I~
    if (step>1)                                                    //~v777I~
        if (Ppcw->UCWrcsrx+step>=Ppcw->UCWwidth)                   //~v777I~
            rc=4;                                                  //~v777I~
        else                                                       //~v777I~
          	csronthefld(Ppcw,Ppcw->UCWrcsry,FROMLEFT,Ppcw->UCWrcsrx+step);//~v777I~
    else                                                           //~v777I~
    	csrcharright(Ppcw);//cursor move after draw                //~v777I~
	return rc;                                                     //~v777I~
}//dircharcsr                                                      //~v777I~
//#ifdef LNX                                                         //~vau0I~//~vauER~
//**********************************************************************//~vau0I~
// set ddfmt for utf8 string filename                              //~vau0I~
// Putf8 is ucs2 for W32                                           //~vavaI~
//**********************************************************************//~vau0I~
int dirsetddfmtname(int Popt,PUDIRLH Ppdh,char *Putf8,int Plen)    //~vau0R~
{                                                                  //~vau0I~
    int rc,lenu8,lendd,len;                                        //~vau0R~
    UCHAR *putf8,*pdddata,*pdddbcs,*pc,*oldpc=NULL;                //~vau0R~
    int opt;                                                       //~vau0I~
#ifdef W32                                                         //~vavaI~
    char wkdddata[_MAX_PATH],wkdddbcs[_MAX_PATH];                  //~vavaI~
    int swu8=0;                                                    //~vavaI~
#endif                                                             //~vavaI~
//***********************                                          //~vau0I~
	if (!Putf8)                                                    //~vaw2I~
    	return 0;                                                  //~vaw2I~
    UTRACEP("dirsetddfmtname opt=%x,len=%d\n",Popt,Plen);          //~vau0I~
    if (!(Gotheropt & GOTHERO_DDFMTDL))                            //~vau0I~
    	return 0;                                                  //~vau0I~
#ifdef W32UNICODE                                                  //~vavaI~
  if (Popt & DSDFO_UTF16)                                          //~vavaI~
  {                                                                //~vavaI~
//  utf162dd(0,(PUWCH)Putf8,Plen,wkdddata,wkdddbcs,sizeof(wkdddata),&lendd);//~vavaI~//~vb43R~
    opt=U162DO_CHKDBCSPRINT;   //   0x01    //chk iswprint for dbcs//~vb43I~
    opt=0;  //@@@@test                                             //~vb43I~
    utf162dd(opt,(PUWCH)Putf8,Plen,wkdddata,wkdddbcs,sizeof(wkdddata),&lendd);//~vb43I~
    pdddata=wkdddata;                                              //~vavaI~
    pdddbcs=wkdddbcs;                                              //~vavaI~
  }                                                                //~vavaI~
  else                                                             //~vavaI~
#endif                                                             //~vavaI~
#ifdef LNX                                                         //~vawnI~
  if (Popt & DSDFO_DDFMT)                                          //~vawnI~
  {                                                                //~vawnI~
    pdddata=Putf8;                                                 //~vawnI~
    pdddbcs=Putf8+Plen;                                            //~vawnI~
    lendd=Plen;                                                    //~vawnI~
  }                                                                //~vawnI~
  else                                                             //~vawnI~
#endif                                                             //~vawnI~
  {                                                                //~vavaI~
	putf8=Putf8;                                                   //~vau0R~
    lenu8=Plen;                                                    //~vau0I~
    UTRACEP("dirsetddfmtname dhname=%s\n",putf8);                  //~vau0R~
    if (Popt & DSDFO_L2DD)                                         //~vau0I~
    {                                                              //~vau0I~
    	opt=0;                                                     //~vau0I~
		if (Popt & DSDFO_ERRREP) //0x40   //rep by '.' when l2f err//~vb14I~
    		opt|=XEUTFCVL2DDO_ERRREP; //      0x01  //rep by '.' if l2f err//~vb14I~
		rc=xeutfcvl2dd(opt,putf8,lenu8,&pdddata,&pdddbcs,&lendd);  //~vau0I~
    	if (rc>(UTFCVFDRC_UTF8|UTFCVRC_DBCS))                      //~vau0I~
        {                                                          //~vb14R~
		  if (!(Popt & DSDFO_ERRREP)) //0x40   //rep by '.' when l2f err//~vb14I~
          {                                                        //~vb14I~
            oldpc=Ppdh->UDHrenameddfmt;                            //~vb14R~
            if (oldpc)                                             //~vb14R~
            {                                                      //~vb14I~
                ufree(oldpc);  //apply setdbcstblDDFMT at xedir2   //~vb14R~
            	Ppdh->UDHrenameddfmtlen=0;                         //~vb14R~
            }                                                      //~vb14I~
    		return rc;                                             //~vau0I~
          }                                                        //~vb14I~
        }                                                          //~vb10I~
    }                                                              //~vau0I~
    else                                                           //~vau0I~
    {                                                              //~vau0I~
    	opt=0;                                                     //~vau0R~
#ifdef W32UNICODE                                                  //~vavaI~
//        swu8=1;                                                    //~vavaI~//~vavFR~
//        if (*Putf8==UD_NOTLC)                                      //~vavaI~//~vavFR~
//        {                                                          //~vavaI~//~vavFR~
//            swu8=2;                                                //~vavaI~//~vavFR~
//            putf8+=2;                                               //~vavaI~//~vavdR~//~vavFR~
//            lenu8-=3;                                              //~vavaI~//~vavFR~
//        }                                                          //~vavaI~//~vavFR~
	  if (memchr(putf8,UD_NOTLC,lenu8))                            //~vavFI~
      {                                                            //~vavFI~
	    pdddata=wkdddata;                                          //~vavFI~
    	pdddbcs=wkdddbcs;                                          //~vavFI~
		rc=fsubw_UD2DD(opt,putf8,lenu8,pdddata,pdddbcs,sizeof(wkdddata),&lendd);//~vavFR~
    	if (rc)                                                    //~vavFI~
    		return rc;                                             //~vavFI~
      }                                                            //~vavFI~
      else                                                         //~vavFI~
#endif                                                             //~vavaI~//~vavFR~
      {                                                            //~vavFI~
		rc=xeutf_cvf2dd(opt,putf8,lenu8,&pdddata,&pdddbcs,&lendd); //~vau0R~
    	if (rc>(UTFCVFDRC_UTF8|UTFCVRC_DBCS))                      //~vau0R~
    		return rc;                                             //~vau0R~
//#ifdef W32UNICODE                                                  //~vavaI~//~vavFR~
//        if (swu8==2)                                               //~vavaI~//~vavFR~
//        {                                                          //~vavaI~//~vavFR~
//            putf8-=2;                                               //~vavaI~//~vavdR~//~vavFR~
//            lenu8+=3;                                              //~vavaI~//~vavFR~
//        }                                                          //~vavaI~//~vavFR~
//#endif                                                             //~vavaI~//~vavFR~
      }                                                            //~vavFI~
    }                                                              //~vau0I~
 }                                                                 //~vavaI~
    len=lendd*2;                                                   //~vau0I~
//  pc=umalloc(len);                                               //~vau0R~//~vb2pR~
    pc=umalloc((size_t)len);                                       //~vb2pI~
	UALLOCCHK(pc,UALLOC_FAILED);                                   //~vau0I~
//  memcpy(pc,pdddata,lendd);                                      //~vau0R~//~vb2pR~
    memcpy(pc,pdddata,(size_t)lendd);                              //~vb2pI~
//  memcpy(pc+lendd,pdddbcs,lendd);                                //~vau0R~//~vb2pR~
    memcpy(pc+lendd,pdddbcs,(size_t)lendd);                        //~vb2pI~
	if (Popt & DSDFO_MEMBNAME)                                     //~vau0I~
    {                                                              //~vau0I~
    	oldpc=Ppdh->UDHnameddfmt;                                  //~vau0R~
    	Ppdh->UDHnameddfmt=pc;                                     //~vau0I~
        Ppdh->UDHnameddfmtlen=lendd;                               //~vau0I~
#ifdef W32UNICODE                                                  //~vavaI~
		if (swu8==1)	//utf8                                     //~vavaI~
        {                                                          //~vavaI~
            char *pu8;                                             //~vavaR~
            pu8=Ppdh->UDHname;                                     //~vavaI~
//      	ufilecvencloseu8(0,Putf8,Plen,&pu8,sizeof(Ppdh->UDHname),NULL/*outlen*/);//~vavaR~//~vavcR~
          if (UCBITCHK(Ppdh->UDHflag5,UDHF5SUBCHFNAME))            //~vavcI~
#ifdef MMM                                                         //~vb2oI~
        	ufilecvencloseu8(0,UD_UTF8WCSUBC,Putf8,Plen,&pu8,sizeof(Ppdh->UDHname),NULL/*outlen*/);//~vavcI~
#else                                                              //~vb2oI~
        	ufilecvencloseu8(0,UD_UTF8WCSUBC,Putf8,Plen,&pu8,Ppdh->UDHnamebuffsz,NULL/*outlen*/);//~vb2oI~
#endif                                                             //~vb2oI~
        }                                                          //~vavaI~
#endif                                                             //~vavaI~
    }                                                              //~vau0I~
    else                                                           //~vau0I~
	if (Popt & DSDFO_SLINKNAME)                                    //~vau0I~
    {                                                              //~vau0I~
    	oldpc=Ppdh->UDHslinkddfmt;                                 //~vau0R~
    	Ppdh->UDHslinkddfmt=pc;                                    //~vau0I~
        Ppdh->UDHslinkddfmtlen=lendd;                              //~vau0I~
#ifdef W32UNICODE                                                  //~vavaI~
		if (swu8==1)	//utf8                                     //~vavaI~
        {                                                          //~vavcI~
//      	ufilecvencloseu8(UFCEUO_PTR,Putf8,Plen,&Ppdh->UDHslink,0,NULL/*outlen*/);//~vavaR~//~vavcR~
          if (UCBITCHK(Ppdh->UDHflag5,UDHF5SUBCHSLINK))            //~vavcI~
              ufilecvencloseu8(UFCEUO_PTR,UD_UTF8WCSUBC,Putf8,Plen,&Ppdh->UDHslink,0,NULL/*outlen*/);//~vavcI~
        }                                                          //~vavcI~
#endif                                                             //~vavaI~
    }                                                              //~vau0I~
    else                                                           //~vau0I~
	if (Popt & DSDFO_RENAME)                                       //~vau0I~
    {                                                              //~vau0I~
    	oldpc=Ppdh->UDHrenameddfmt;                                //~vau0R~
    	Ppdh->UDHrenameddfmt=pc;                                   //~vau0I~
        Ppdh->UDHrenameddfmtlen=lendd;                             //~vau0R~
    }                                                              //~vau0I~
    if (oldpc)                                                     //~vau0I~
    	ufree(oldpc);                                              //~vau0I~
	UTRACED("dirsetddfmtname data",pdddata,lendd);                 //~vau0I~
	UTRACED("dirsetddfmtname dbcs",pdddbcs,lendd);                 //~vau0I~
    return 0;                                                      //~vau0I~
}//dirsetddfmtname                                                 //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
#ifdef W32UNICODE                                                  //~vavaI~
//**********************************************************************//~vavaI~
// set ucs2 name                                                   //~vavaI~
// rc:UALLOC_FAILED                                                //~vavaI~
//**********************************************************************//~vavaI~
int dirsetnameW(int Popt,PUDIRLIST Ppudl,PUDIRLH Ppdh)             //~vavaI~
{                                                                  //~vavaI~
    int ctr;                                                       //~vavaI~
    UWCH *pw,*psrc;                                                //~vavaI~
//***********************                                          //~vavaI~
    ctr=Ppudl->nameWctr;                                           //~vavaI~
    UTRACEP("%s opt=%x,ctr=%d,name=%s\n",UTT,Popt,ctr,Ppdh->UDHname);                        //~vavaI~//~vb10R~
    if (!ctr)                                                      //~vavaI~
    {                                                              //~vb10I~
        Ppdh->UDHnameWshort[0]=0;                                  //~vb10R~
    	return 0;                                                  //~vavaI~
    }                                                              //~vb10I~
    psrc=Ppudl->nameW;                                             //~vavaI~
  if (ctr<=UDHNAMEWSHORT_MAXCTR)                                   //~vb10I~
  {                                                                //~vb10I~
    pw=Ppdh->UDHnameWshort;                                        //~vb10I~
    UmemcpyZWctr(pw,psrc,ctr);                                     //~vb10R~
    UTRACED("out(short)",pw,ctr2szW(ctr));                                //~vavaI~//~vb10I~
  }                                                                //~vb10I~
  else                                                             //~vb10I~
  {                                                                //~vb10I~
    memdupW(&pw,psrc,ctr+1);                                       //~vavaI~
	UALLOCCHK(pw,UALLOC_FAILED);                                   //~vavaI~
    UTRACED("out(long)",pw,ctr2szW(ctr));                          //~vb10I~
  }                                                                //~vb10I~
    Ppdh->UDHnameW=pw;                                             //~vavaI~
    Ppdh->UDHnameWctr=ctr;                                         //~vavaI~
    return 0;                                                      //~vavaI~
}//dirsetnameW                                                     //~vavaI~
#endif //W32UNICODE                                                //~vavaI~
#ifdef LNX                                                         //~vawnI~
//**********************************************************************//~vawnI~
// set ddfmt for UDHrename_codetype                                //~vawnI~
//**********************************************************************//~vawnI~
//#ifdef HHH                                                       //~vawnR~
//int dirsetddfmtname_renamesv(int Popt,PULINEH Pplh,char *Putf8,int Plen,char *Pct,char *Pdatalc)//~vawnR~
//#else                                                            //~vawnR~
int dirsetddfmtname_renamesv(int Popt,PULINEH Pplh,char *Putf8,int Plen,char *Pct,int Plclen)//~vawnI~
//#endif                                                           //~vawnR~
{                                                                  //~vawnI~
	PUDIRLH pdh;                                                   //~vawnI~
	UCHAR *pdddata,*pdddbcs,*pc;                                   //~vawnR~
    int opt,buffsz,ddlen,rc=0,ctlen,rc2;                           //~vawnR~
//**********************                                           //~vawnI~
	UTRACED("pu8",Putf8,Plen);                                     //~vawnI~
    pdh=UGETPDH(Pplh);                                             //~vawnI~
//#ifdef HHH                                                       //~vawnR~
//    ctlen=strlen(pdh->UDHrenamesv);                              //~vawnR~
//    memcpy(Pdatalc,pdh->UDHrenamesv,ctlen+1);                    //~vawnR~
//#else                                                            //~vawnR~
	ctlen=Plclen;                                                  //~vawnR~
//#endif                                                           //~vawnR~
	opt=0;                                                         //~vawnI~
    buffsz=ctlen;                                                  //~vawnR~
	rc2=xeutfcvlf2dd_updatect(opt,Putf8,Plen,NULL/*Pdbcs*/,Pct,ctlen,&pdddata,&pdddbcs,buffsz,&ddlen);//~vawnR~
    if (rc2==UALLOC_FAILED)                                        //~vawnI~
    	return rc2;                                                //~vawnI~
    if (rc2 & XEUTFF2LRC_UTF8)                                     //~vawnR~
        rc=XEUTFGU8MRC_UTF8;                                       //~vawnI~
    else                                                           //~vawnI~
//  if (memchr(Pct,XEUTFCT_LC,ctlen))                              //~vawnR~//~vb2pR~
    if (memchr(Pct,XEUTFCT_LC,(size_t)ctlen))                      //~vb2pI~
        rc=XEUTFGU8MRC_LC;    //not all ascii                      //~vawnR~
	opt=DSDFO_DDFMT|DSDFO_RENAME;                                  //~vawnI~
//  pc=umalloc(ddlen*2+1);                                         //~vawnI~//~vb2pR~
    pc=umalloc((size_t)(ddlen*2+1));                               //~vb2pI~
	UALLOCCHK(pc,UALLOC_FAILED);                                   //~vawnI~
//  memcpy(pc,pdddata,ddlen);                                      //~vawnI~//~vb2pR~
    memcpy(pc,pdddata,(size_t)ddlen);                              //~vb2pI~
//  memcpy(pc+ddlen,pdddbcs,ddlen);                                //~vawnI~//~vb2pR~
    memcpy(pc+ddlen,pdddbcs,(size_t)ddlen);                        //~vb2pI~
	UTRACED("dddata+dbcs",pc,ddlen*2);                             //~vawnI~
	dirsetddfmtname(opt,pdh,pc,ddlen);                             //~vawnR~
    ufree(pc);                                                     //~vawnI~
    return rc;                                                     //~vawnR~
}//dirsetddfmtname_renamesv                                        //~vawnI~
#endif                                                             //~vawnI~
