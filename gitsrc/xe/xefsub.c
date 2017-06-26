//*CID://+vb7eR~:                             update#=  309;       //+vb7eR~
//*************************************************************
//* xefsub.c
//*************************************************************
//vb7e:170108 FTP crash by longname                                //+vb7eI~
//vb70:161211 (Bug) dirlist crash when filename is locale and having slink is utf8//~vb70I~
//vb06:150313 (BUG)others for \\.\; change strategy(del vb03 to vb05),set to UFHfilename without \\.\ ;//~vb06R~
//vazq:150113 use ulib ufseek/uftell                               //~vazqI~
//vazk:150113 (BUG)RECFM=V MF header;should not replace original recordid//~vazkI~
//vazg:150112 (BUG)lrecl overflow chk was not done                 //~vazgI~
//vazf:150112 (BUG)update of RECFM=V corrupts record over length>9999//~vazfI~
//vazb:150111 diaplay err description for write err at save        //~vazbI~
//vaz0:150105 BUG:offset value is long for fseek error msg         //~vaz0I~
//vawh:140603 vawd is invalid(after open with output option,the file is null)//~vawhI~
//vawd:140602 del reopen bkup when permission err(may be UAC protected)//~vawhI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavcI~
//vav9:140410 (Win)unicode support(UD fmt string,_MAX_PATH changes)//~vav9I~
//vav2:140401 (BUG)on UNC dirlist,localte cmd fail by invalid path //~vav2I~
//vaua:140306 getmixwdword output dddata and dddbcs                //~vauaI~
//vajk:130812 (BUG)for handle!=0 ebc file;invalid transration from ebc to locale(handle parameter=0)//~vajkI~
//vajb:130804 vhdr len for utf8 code len                           //~vajbI~
//vaj1:130721 (BUG)drop line with length=0 when END cmd with /MR option//~vaj1I~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW})         //~vaj0I~
//vag1:120724 (Axe)warning no write permisson from unod for sdcard(permission 075)//~vag1I~
//		      sdcard group is sdcard_rm and manifest permission set application groupid to it//~vag1I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vac1:120204 (SMB)smb node support                                //~vac1I~
//va81:100920 (WXEXXE)print ebcfile by ucs for alos wxp **/*** option//~va81I~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va7t:100823 EBC:handle support to file output(save/rep/..)       //~va7tI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6Q:100722 Fxx+/MxR is output lrecl and not input lrecl         //~va6QI~
//va6D:100719 EBC eol 0x15 support                                 //~va6DR~
//va6c:100619 add SOSI option -S{i|r|d} to REP/CRE/APP/SAV/COP/MOV cmd//~va6cI~
//va68:100618 expand when LRECL is changed for record mode         //~va68I~
//va61:100602 allow binaly opend file translation;b2l/b2u          //~va61I~
//va60:100602 allow binaly opend file translation;l2b              //~va50I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            fsub.c :cv ddfmt->utf8 before write                  //~va20I~
//va1E:091116 optionaly(default) keep original value when UTF8 code err at load//~va1EI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va10:091008!(XXE) treate input string as UTF8 or LOCALE for a line//~va10I~
//                      Mixed string word by word                  //~va10I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          header line filename cv f2l                            //~va00I~
//          save option "IE"(ignore translation err)               //~va00I~
//v92n:080802 (UTF)add  [cplc|cpu8] option for save cmd            //~v92nI~//~va00I~
//v76Y:071107 (BUG)use copy for bkup at save;rename could not recover attr(Unx) and change creation date(Win/Unx)//~v76XI~
//v76X:071107 save option [NB|BK]                                  //~v76XI~
//v76z:070820 NB(no bkup) option to bypass rename at save          //~v76zI~
//v76y:070820 (LNX:BUG)write permission err msg for MDOS disk      //~v76yI~
//v76x:070820 keep bkup by rename for the case abend at save       //~v76xI~
//v72B:061205 3270:like rsh,use =6 panel as TSO terminal screen "tso "tostid TSO"/Exit//~v72BI~
//v71W:061113 DROP EOF for TSO file                                //~v71WI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v70z:060904 3270 ftp support                                     //~v70zI~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//v66i:051023 (WXE)C & P;if no Clipboard data on Windows CB,get data from ::CB//~v66iI~
//v66f:051021 (BUG)A+F9 abend when A+F7 on same excludeline and pos1>pos2//~v66fI~
//v57m:040526 (BUG)parmission warining issued for new file;should chk parent dir//~v57mI~
//v55X:040318 (!UNX)update permission warning(read only chk)       //~v55XI~
//v55P:040318 (UNX)update permission warning                       //~v55PI~
//v54U:040125 move updatechk sub to xefsub(used by OS/2 DOS)       //~v54RI~
//v54R:040125 find cmd:max record pos search by max pos parm       //~v54RI~
//v54p:040106 (FTP)uftpisremote interface changed                  //~v54pI~
//v542:031223 (WIN,UNX)remote file edit/save                       //~v542I~
//v53Z:031223 (WIN,UNX)ftp support;no vfat alias(always long)      //~v53ZI~
//v50t:030112 (BUG)mac eolid=4 but eollen=1,offset calc miss       //~v50tI~
//v50e:021229 dbcs conv cont line support                          //~v50eI~
//v49c:020629 (BUG)repword dbcs set should continue to eol if right boundary changed//~v49cI~
//v49b:020623 support *= for not only "(i)x all" but also "(i)find","change"//~v49bI~
//v48o:020518 (UNX)mdos disk readonly when for edit end            //~v48oI~
//v48c:020429 (UNX)edit/browse mdos disk support                   //~v48cI~
//v47X:020413 mac file support(eol=0x0d) /Mm                       //~v47XI~
//v453:011208 (BUG)dbcs tbl set to not dbcs when word rep split dbcs//~v453I~
//			   after reple word it may yet dbcs                    //~v453I~
//v44a:011202 (BUG)hex input replace another tab char to space     //~v44aI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v21n:010114 LINUX support:wordrep may dsetroy dbcs conbination   //~v21nI~
//v214:001126 LINUX support:no eof processing;ufgets now return eof id as data.//~v214I~
//            no eofchk and eofwrite required under unix.          //~v214I~
//v213:001126 deney v20B:no automaticaly delete EOFID.It should be binary mode.//~v213I~
//v20B:001103 drop EOF when write mode=unix text                   //~v20BI~
//v19L:000925 LINUX support(permission err msg for fopen)          //~v19LI~
//v180:000820 (BUG)dont write eof when binary update               //~v180I~
//v179:000501 (BUG)when n line join is overflow,errmsg "Already one of split line"//~v179I~
//            So,join to split last line.                          //~v179I~
//v178:000430 renum support for lineno hex mode                    //~v178I~
//v13j:991029 (BUG)It should not be end when close err by disk space shortage.//~v13jI~
//            chk also close err(flush err) at save then notify and wait.//~v13jI~
//v0i0:980429 lcmd skip/bandle support                             //~v0i0I~
//v0fo:971106 (GCC:W32)ugetvfatalias new option parm               //~v0foI~
//v0fm:971103 new function to set filename and alias to ufh        //~v0fmI~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//            fileofchk by last read 1a for bin mode          fsub //~v09YI~
//v09x:970525:system/hidden update reject under os/2,issue errmsg  //~v09xI~
//v08s:961207:(DOS:BUG)eof(x1a)drop,it can be easyly checked by feof for all(dos,win,os2)//~v08sI~
//v08q:961123:edit partial file(continued from v08l)-err msg by ufileapierr//~v08qI~
//v08r:961201:chk read only attr when reopen at save               //~v08rI~
//v085:961024:W95 VC                                               //~v085I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v054:951014:freopen faile if once freopen failed even if after closed//~v054I~
//            another open(errno=9:EISOPEN)                     //~v054I~
//            change freopen to fclose + fopen                  //~v054I~
//v047:950924:file output err(disk full)->close err/reopen err  //~v047I~
//*950318 xefsub from xesub
//*950102 tab display by space for screen print
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>                                                //~v66fI~
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                              //~5503M~
//*************************************************************
#ifdef DOS
    #include <dos.h>                                               //~v08sI~
#else
	#ifdef W32                                                     //~v08sI~
        #include <dos.h>                                           //~v08sI~
        #include <windows.h>                                       //~vavcI~
    #else                                                          //~v08sI~
    #define INCL_BASE                                              //~v76YR~
    #include <os2.h>                                               //~v76YR~
	#endif                                                         //~v08sI~
#endif
#ifdef UNX                                                         //~v55PI~
    #include <sys/stat.h>                                          //~v55PI~
#endif                                                             //~v55PI~
//*******************************************************
#include <ulib.h>
#include <ualloc.h>                                                //~v50eI~
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318I~
#include <ufile2.h>                                                //~v76xI~
#include <ufile3.h>                                                //~v76XI~
#include <ufile5.h>	//ugetvfatalias                                //~v0fmR~
#include <ufemsg.h>                                                //~v08sI~
#include <utrace.h>                                                //~v08qI~
#include <ustring.h>                                               //~v0fmI~
#include <udbcschk.h>                                              //~v453I~
#include <uftp.h>                                                  //~v542I~
#include <ufile4.h>                                                //~v690I~
#include <u3270.h>                                                 //~v717I~
#ifdef UNX                                                         //~v55PI~
	#include <uunxsub.h>                                           //~v55PI~
#endif                                                             //~v55PI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include <utf.h>                                           //~v55PI~//~va00I~
#endif                                                             //~v55PI~//~va00I~
#include <ucvebc.h>                                                //~va68I~
#include <ucvext.h>                                                //~va7LI~
#include <ucvebc4.h>                                               //~va7LI~
#include <ufilew.h>                                                //~vb06I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"                                              //~5318R~
#include "xefile.h"                                             //~5318I~
#include "xefile6.h"                                               //~v50eI~
#include "xefsub.h"
#include "xesub.h"                                                 //~v13jI~
#include "xeftp.h"                                                 //~v542I~
#include "xedir.h"                                                 //~v717I~
#include "xetso.h"                                               //~v70zI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xefile5.h"                                           //~va00R~
	#include "xeutf.h"                                             //~va00I~
#endif                                                             //~va00I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
int xefsubresetcsrplhsub(PUCLIENTWE Ppcw,PULINEH Pplh);            //~v66fM~
int filewrite_recordmode(int Popt,PUFILEH Ppfh,void *Pbuff,size_t Plen);//~va68I~
#define FWRMO_ADJLRECL     0x0100                                  //~va68I~
#define FWRMO_2EBC         0x0200                                  //~va68I~
//*******************************************************          //~v66fI~
static PULINEH Splhstop=0;                                         //~v542R~
static UCHAR *Sbkupfnm=0;                                          //~v76xI~
static int Svbuffsz,Svbuffszmax,Sswvhdr;                           //~vajbR~
static char *Svbuff;                                               //~vajbI~
//*******************************************************          //~v76xI~
//*file re-open with bkup by rename                                //~v76xI~
//* parm1:UFILEH ptr                                               //~v76xI~
//* parm2:new open option char string                              //~v76xI~
//*******************************************************          //~v76xI~
FILE *filebkupreopen(int Popt,PUFILEH Ppfh,UCHAR *Ppopt,UCHAR *Pbkupfnm)//~v76xI~
{                                                                  //~v76xI~
	FILE *fh;                                                      //~v76xI~
    int procctr,ronlyctr,delctr,pathlen;                           //~v76xR~
    UCHAR prefix[_MAX_PATH],pathnm[_MAX_PATH],*pfnm;               //~v76xR~
#if defined(DOS)||defined(OS2)	//8.3 filename                     //~v76xI~
    UCHAR *pc;                                                     //~v76xI~
#endif                                                             //~v76xI~
//****************************                                     //~v76xI~
	if (Popt & FBRO_DELETE)                                        //~v76xR~
    {                                                              //~v76xI~
    	if (*Pbkupfnm)                                             //~v76yR~
    		uxdelete(Pbkupfnm,UXDELDIR,UXDELFORCE,&procctr,&ronlyctr,&delctr);//~v76yR~
        return 0;                                                  //~v76xI~
    }                                                              //~v76xI~
#ifdef UTF8SUPPH                                                   //~va00I~
	if (Popt & FBRO_RESTORE)    //restore when write err(cvu8 err etc)//~va00I~
    {                                                              //~va00I~
    	if (*Pbkupfnm)                                             //~va00I~
        {                                                          //~va00I~
    		pfnm=FILELOCALCOPYNAME(Ppfh);                          //~va00M~
			if (Ppfh->UFHhfile)                                    //~va00I~
    		{                                                      //~va00I~
	    		if (!fileclose(pfnm,Ppfh->UFHhfile))               //~va00I~
					Ppfh->UFHhfile=0;                              //~va00I~
            }                                                      //~va00I~
	        uxcopy(Pbkupfnm,pfnm,DCPY_EXISTING,FILE_NORMAL); //copy bkup->org file//~va00R~
        }                                                          //~va00I~
        return 0;                                                  //~va00I~
    }                                                              //~va00I~
#endif                                                             //~va00I~
    *Pbkupfnm=0;                                                   //~v76xI~
    pfnm=Ppfh->UFHfilename;                                        //~v76xI~
    Sbkupfnm=Pbkupfnm;                                             //~v76xI~
    if (Popt & FBRO_NB)                                            //~v76XI~
    	Sbkupfnm=0;		//no bkup                                  //~v76XI~
    else                                                           //~v76XI~
#ifdef UNX                                                         //~v76xI~
	if (UCBITCHK(Ppfh->UFHflag5,UFHF5MDOS))//original is mdos disk //~v76xI~
    	Sbkupfnm=0;		//no bkup                                  //~v76xI~
    else                                                           //~v76xI~
#else                                                              //~v76xI~
	if (FDFILE(pfnm))                                              //~v76xI~
    	Sbkupfnm=0;		//no bkup                                  //~v76xI~
    else                                                           //~v76xI~
#endif                                                             //~v76xI~
	if (UCBITCHK(Ppfh->UFHflag8,UFHF8NOBKSV))                      //~v76zR~
    {                                                              //~v76XI~
      if (!(Popt & FBRO_BK))                                       //~v76XI~
    	Sbkupfnm=0;		//no bkup                                  //~v76zR~
    }                                                              //~v76XI~
    else                                                           //~v76zR~
	if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))                           //~v76xR~
    	Sbkupfnm=0;		//no bkup                                  //~v76xI~
    else                                                           //~v76xI~
    if (FILEISREMOTE(Ppfh))                                        //~v76xR~
    	Sbkupfnm=0;		//no bkup                                  //~v76xI~
                                                                   //~v76xI~
    if (Sbkupfnm)	//do bakup                                     //~v76xI~
    {                                                              //~v76xI~
    	pathlen=PATHLEN(pfnm);                                     //~v76xR~
//      if (ROOTDIR(pfnm))                                         //~v76xR~
    	    memcpy(pathnm,pfnm,(UINT)pathlen);                     //~v76xR~
//      else                                                       //~v76xR~
//          memcpy(pathnm,pfnm,(UINT)(pathlen-1));                 //~v76xR~
        *(pathnm+pathlen)=0;                                       //~v76xI~
		strcpy(prefix,pfnm+pathlen);                               //~v76xR~
#if defined(DOS)||defined(OS2)	//8.3 filename                     //~v76xI~
		if (pc=strchr(prefix,'.'),pc)                              //~v76xI~
        	*(pc+1)=0;                                             //~v76xI~
#else                                                              //~v76xI~
		strcat(prefix,".");                                        //~v76xI~
#endif                                                             //~v76xI~
		if (!utempnam(pathnm,prefix,Pbkupfnm))                     //~v76xI~
        	Sbkupfnm=0;	//no bkup                                  //~v76xI~
    }                                                              //~v76xI~
	fh=filereopen(Ppfh,Ppopt);                                     //~v76xI~
    Sbkupfnm=0;                                                    //~v76xI~
	return fh;                                                     //~v76xI~
}//filebkupreopen                                                  //~v76xI~
//*******************************************************
//*file re-open
//* parm1:UFILEH ptr
//* parm2:new open option char string
//*******************************************************
FILE *filereopen(PUFILEH Ppfh,UCHAR *Ppopt)
{
	FILE *fh;
    FILEFINDBUF3 fstat3;                                           //~v08rI~
    int rc;                                                        //~v08rI~
    char *pc;                                                      //~v08rI~
    char *fnm;                                                     //~v48cI~
//****************************
    fnm=FILELOCALCOPYNAME(Ppfh);                                   //~v542I~
#ifdef UNX                                                         //~v48cI~
	if (UCBITCHK(Ppfh->UFHflag5,UFHF5MDOS))//original is mdos disk //~v48cI~
    {                                                              //~v48oI~
    	if (!ufstat(fnm,&fstat3))                                  //~v48oI~
        	if (fstat3.attrFile & FILE_READONLY)                   //~v48oI~
            {                                                      //~v48oI~
				uerrmsg("%s(\"%s\") ReOpen failed(ReadOnly)",      //~v48oI~
			    		"%s(\"%s\") 再オープンエラー(ReadOnly)",   //~v48oI~
							Ppfh->UFHfilename,Ppopt);              //~v48oR~
                return 0;                                          //~v48oI~
            }                                                      //~v48oI~
    	fnm=Ppfh->UFHalias;                                        //~v48cI~
    }                                                              //~v48oI~
#endif                                                             //~v48cI~
                                                                //~v047I~
//	if (!(fh=freopen(Ppfh->UFHfilename,Ppopt,Ppfh->UFHhfile)))  //~v054I~
	if (Ppfh->UFHhfile)                                         //~v054I~
    {                                                              //~v542I~
//  	if (!fclose(Ppfh->UFHhfile))                               //~v13jR~
    	if (!fileclose(Ppfh->UFHfilename,Ppfh->UFHhfile))          //~v13jI~
			Ppfh->UFHhfile=0;                                   //~v054I~
		else                                                       //~v13jI~
        	return 0;                                              //~v13jR~
    }                                                              //~v542I~
//    if (Sbkupfnm)                                                //~vawdR~
//    {                                                            //~vawdR~
////#if defined(UNX) || defined(W32)                               //~vawdR~
////        if (urename2(fnm,Sbkupfnm,0))   //unx tempnam create the file(avoid dupname err)//~vawdR~
////#else                                                          //~vawdR~
////        if (urename(fnm,Sbkupfnm,0))    //unx tempnam create the file(avoid dupname err)//~vawdR~
////#endif                                                         //~vawdR~
//        if (uxcopy(fnm,Sbkupfnm,DCPY_EXISTING,FILE_NORMAL))      //~vawdR~
//            *Sbkupfnm=0;    //avoid delete                       //~vawdR~
//    }                                                            //~vawdR~
    if (Sbkupfnm)                                                  //~vawhI~
    {                                                              //~vawhI~
        if (uxcopy(fnm,Sbkupfnm,DCPY_EXISTING,FILE_NORMAL))        //~vawhI~
            *Sbkupfnm=0;    //avoid delete                         //~vawhI~
    }                                                              //~vawhI~
//  if (!(fh=fopen(Ppfh->UFHfilename,Ppopt)))                      //~v48cI~
    if (!(fh=fopen(fnm,Ppopt)))                                    //~v48cR~
    {                                                              //~v08rI~
    	rc=errno;                                                  //~v08rI~
    	pc="";                                                     //~v09xI~
#ifdef UNX                                                         //~v19LI~
      if (errno==EACCES)                                           //~v19LI~
    	pc=",Permission";                                          //~v19LI~
      else                                                         //~v19LI~
      {                                                            //~v19LI~
#endif //UNX                                                       //~v19LI~
//  	if (!ufstat(Ppfh->UFHfilename,&fstat3))                    //~v48cR~
    	if (!ufstat(fnm,&fstat3))                                  //~v48cI~
        {                                                          //~v09xI~
        	if (fstat3.attrFile & FILE_READONLY)                   //~v09xR~
				pc=",ReadOnly";                                    //~v09xR~
    	    else                                                   //~v09xR~
	        	if (fstat3.attrFile & (FILE_HIDDEN|FILE_SYSTEM))   //~v09xI~
					pc=",System or Hidden";                        //~v09xI~
        }                                                          //~v09xI~
#ifdef W32                                                         //~vawdI~
		if (!*pc)                                                  //~vawdI~
			if (rc==EACCES)                                        //~vawdI~
    			pc=",Permission";                                  //~vawdI~
#endif                                                             //~vawdI~
#ifdef UNX                                                         //~v19LI~
      }//EACCES                                                    //~v19LI~
#endif //UNX                                                       //~v19LI~
        if (rc==EACCES)                                            //~vawdR~
        {                                                          //~vawdI~
			uerrmsg("%s(\"%s\") ReOpen failed(errno=%d)%s. Save to other folder if you want.",//~vawdI~
			    	"%s(\"%s\") 再オープンエラー(errno=%d)%s. 必要なら他のフォルダーに保存してください",//~vawdI~
			    		Ppfh->UFHfilename,Ppopt,rc,pc);            //~vawdI~
            if (Sbkupfnm)                                          //~vawhI~
            {                                                      //~vawhI~
//*FIXME on linux   ::FIXED                                        //~vawhR~
				filebkupreopen(FBRO_DELETE,Ppfh,0,Sbkupfnm);       //~vawhI~
                *Sbkupfnm=0;    //avoid delete                     //~vawhI~
          	}                                                      //~vawhI~
                                                                   //~vawdI~
        }                                                          //~vawdI~
        else                                                       //~vawdI~
		uerrmsg("%s(\"%s\") ReOpen failed(errno=%d)%s",            //~v08qR~
			    "%s(\"%s\") 再オープンエラー(errno=%d)%s",Ppfh->UFHfilename,Ppopt,rc,pc);//~v08qR~
//      Sbkupfnm=0;                                                //~vawdI~//~vawhR~
	}                                                              //~v08rI~
    else                                                        //~v047I~
    {                                                              //~vawdI~
		Ppfh->UFHhfile=fh;                                      //~v047R~
//        if (Sbkupfnm)                                              //~vawdR~//~vawhR~
//        {                                                          //~vawdR~//~vawhR~
//            if (uxcopy(fnm,Sbkupfnm,DCPY_EXISTING,FILE_NORMAL))    //~vawdR~//~vawhR~
//                *Sbkupfnm=0;    //avoid delete                     //~vawdR~//~vawhR~
//        }                                                          //~vawdR~//~vawhR~
    }                                                              //~vawdI~
	return fh;
}
//*******************************************************
//*file seek
//*******************************************************
int fileseek(PUFILEH Ppfh,FPOST Ppos,int Popt)
{
	int rc;
//****************************
//#ifdef W32                                                       //~vazqR~
//  #ifdef LFSSUPP                                                 //~vazqR~
//    if ((rc=_fseeki64(Ppfh->UFHhfile,Ppos,Popt),rc))    //position//~vazqR~
//  #else                                                          //~vazqR~
//    if ((rc=fseek(Ppfh->UFHhfile,Ppos,Popt),rc))    //position   //~vazqR~
//  #endif                                                         //~vazqR~
//#else                                                            //~vazqR~
//    if ((rc=fseek(Ppfh->UFHhfile,Ppos,Popt),rc))    //position   //~vazqR~
//#endif                                                           //~vazqR~
    if ((rc=ufseek(Ppfh->UFHhfile,Ppos,Popt),rc))    //position    //~vazqI~
//  	uerrmsg("%s fseek(opt=%d,pos=%d) failed,rc=%d,errno=%d",   //~vaz0R~
//				"%s fseek (%d から %d の位置) の失敗,rc=%d,errno=%d",//~vaz0R~
//  			Ppfh->UFHfilename,Popt,Ppos,rc,errno);             //~vaz0I~
    	uerrmsg("%s fseek(opt=%d,pos=%" FILESZ_EDIT "d=0x%" FILESZ_EDIT "x) failed,rc=%d,errno=%d",//~vaz0R~
  				"%s fseek (%d から %" FILESZ_EDIT "d=0x%" FILESZ_EDIT "x の位置) の失敗,rc=%d,errno=%d",//~vaz0R~
    			Ppfh->UFHfilename,Popt,Ppos,Ppos,rc,errno);        //~vaz0I~
	return rc;
}//fileseek
                                                                //~5502I~
//*******************************************************          //~v08qI~
//*file read                                                       //~v08qI~
//*parm1:pfh                                                       //~v08qI~
//*parm2:buffer                                                    //~v08qI~
//*parm3:request len                                               //~v08qI~
//*parm4:output read len                                           //~v08qI~
//*rc   :0:ok,1:eof,4:err                                          //~v08qI~
//*******************************************************          //~v08qI~
int fileread(PUFILEH Ppfh,void *Pbuff,size_t Preqlen,size_t *Ppreadlen)//~v08qR~
{                                                                  //~v08qI~
	int err;                                                       //~v08qI~
//****************************                                     //~v08qI~
  	if ((*Ppreadlen=fread(Pbuff,1,Preqlen,Ppfh->UFHhfile))!=Preqlen)//~v08qI~
	{                                                              //~v08qI~
		err=errno;    	                                           //~v08qI~
        if (feof(Ppfh->UFHhfile))                                  //~v08qI~
        	return 1;                                              //~v08qI~
        ufileapierr("read by fread",Ppfh->UFHfilename,err);        //~v08qI~
		return 4;                                                  //~v08qI~
	}                                                              //~v08qI~
	return 0;                                                      //~v08qI~
}//fileread                                                        //~v08qI~
                                                                   //~v08qI~
//*******************************************************
//*file write
//*parm1:pfh                                                       //~v08qI~
//*parm2:buffer                                                    //~v08qI~
//*parm3:req len                                                   //~v08qI~
//*rc   :0:ok,else:errno                                           //~v08qI~
//*******************************************************
int filewrite(PUFILEH Ppfh,void *Pbuff,size_t Plen)                //~v08qR~
{
//****************************
    UTRACED("filewrite",Pbuff,(int)Plen);                          //~vb06R~
  	if (Plen!=(int)fwrite(Pbuff,1,(unsigned int)Plen,Ppfh->UFHhfile))//~v085R~
	{
//  	uerrmsg("%s write failed",                                 //~v08qR~
//				"%s 出力エラ－",                                   //~v08qR~
//  			Ppfh->UFHfilename);                                //~v08qR~
//      ufileapierr("write by fwrite",Ppfh->UFHfilename,errno);    //~vazbR~
        ufileapierr_str("write by fwrite",Ppfh->UFHfilename,errno);//~vazbI~
		return errno;
	}
	return 0;
}//filewrite
                                                                //~5502I~
//*******************************************************          //~va68I~
int savefiledata(int Popt,char *Pbuff,int Plen)                    //~vajbI~
{                                                                  //~vajbI~
	int buffsz;                                                    //~vajbI~
    char *newbuff;                                                 //~vajbI~
//************************************                             //~vajbI~
	buffsz=Svbuffsz+Plen;                                          //~vajbI~
    if (buffsz>Svbuffszmax)                                        //~vajbI~
    {                                                              //~vajbI~
//  	newbuff=malloc(buffsz);                                    //~vb06R~
    	newbuff=malloc((size_t)buffsz);                            //~vb06I~
//      memcpy(newbuff,Svbuff,Svbuffsz);                           //~vb06R~
        memcpy(newbuff,Svbuff,(size_t)Svbuffsz);                   //~vb06I~
        if (Svbuff)                                                //~vajbI~
	        free(Svbuff);                                          //~vajbR~
        Svbuff=newbuff;                                            //~vajbI~
        Svbuffszmax=buffsz;                                        //~vajbI~
    }                                                              //~vajbI~
//  memcpy(Svbuff+Svbuffsz,Pbuff,Plen);                            //~vb06R~
    memcpy(Svbuff+Svbuffsz,Pbuff,(size_t)Plen);                    //~vb06I~
    Svbuffsz+=Plen;                                                //~vajbR~
    return Svbuffsz;                                               //~vajbI~
}//savefiledata                                                    //~vajbI~
//*******************************************************          //~va68I~
int filewrite_recordmode(int Popt,PUFILEH Ppfh,void *Pbuff,size_t Plen)//~va68I~
{                                                                  //~va68I~
	int rc,lrecl,reslen,paddlen=0,len;                             //~vac1R~
    #define WKSPACESZ 256                                          //~va68I~
    UCHAR *pc,wkspace[WKSPACESZ];                                  //~va68I~
//****************************                                     //~va68I~
  if (UCBITCHK(Ppfh->UFHflag11,UFHF11WRECORD)                      //~va6QR~
  &&  !UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD)                      //~va6QR~
  )                                                                //~va6QI~
  	lrecl=Ppfh->UFHlreclout;                                       //~va6QR~
  else                                                             //~va6QI~
	lrecl=Ppfh->UFHlrecl;                                          //~va68I~
	if (!(Popt & FWRMO_ADJLRECL)                                   //~va68I~
    ||  !lrecl                                                     //~va68I~
    ||  UCBITCHK(Ppfh->UFHflag4,UFHF4BIN)	//bynary mode          //~va68I~
    )                                                              //~va68I~
    {                                                              //~vajbI~
        if (Sswvhdr)                                               //~vajbI~
        {	                                                       //~vajbI~
//      	savefiledata(0,Pbuff,Plen);                            //~vb06R~
        	savefiledata(0,Pbuff,(int)Plen);                       //~vb06R~
            return 0;                                              //~vajbI~
        }                                                          //~vajbI~
		return filewrite(Ppfh,Pbuff,Plen);                         //~va68I~
    }                                                              //~vajbI~
    rc=0;                                                          //~va68I~
    paddlen=lrecl;   //if Plen==0,paddlen is not set in the next loop//~vaj1I~
//  for (pc=Pbuff,reslen=Plen;reslen>0;)                           //~vb06R~
    for (pc=Pbuff,reslen=(int)Plen;reslen>0;)                      //~vb06I~
    {                                                              //~va68I~
    	len=min(reslen,lrecl);                                     //~va68I~
      if (Sswvhdr)                                                 //~vajbI~
        savefiledata(0,pc,len);                                    //~vajbI~
      else                                                         //~vajbI~
//  	rc|=filewrite(Ppfh,pc,len);                                //~vb06R~
    	rc|=filewrite(Ppfh,pc,(size_t)len);                        //~vb06I~
        pc+=len;                                                   //~va68I~
        paddlen=lrecl-len;                                         //~va68I~
        reslen-=len;                                               //~va68I~
    }                                                              //~va68I~
    if (paddlen>0)                                                 //~va68I~
    {                                                              //~va68I~
    	len=min(paddlen,WKSPACESZ);                                //~va68R~
//      memset(wkspace,UWHICH((Popt & FWRMO_2EBC),CHAR_EBC_SPACE,' '),len);//~vb06R~
        memset(wkspace,UWHICH((Popt & FWRMO_2EBC),CHAR_EBC_SPACE,' '),(size_t)len);//~vb06I~
        for (pc=wkspace,reslen=paddlen;reslen>0;)                  //~va68R~
        {                                                          //~va68I~
            len=min(reslen,WKSPACESZ);                             //~va68I~
          if (Sswvhdr)                                             //~vajbI~
        	savefiledata(0,pc,len);                                //~vajbI~
      	  else                                                     //~vajbI~
//          rc|=filewrite(Ppfh,pc,len);                            //~vb06R~
            rc|=filewrite(Ppfh,pc,(size_t)len);                    //~vb06I~
            reslen-=len;                                           //~va68I~
        }                                                          //~va68I~
    }                                                              //~va68I~
	return rc;                                                     //~va68I~
}//filewrite_recordmode                                            //~va68I~
                                                                   //~va68I~
//*******************************************************       //~5502I~
//*file eof write                                               //~5502I~
//*parm1:Pfh                                                    //~5502I~
//*retn :none                                                   //~5502I~
//*******************************************************       //~5502I~
//void fileeofwrite(PUFILEH Ppfh)                                  //~v13jR~
int  fileeofwrite(PUFILEH Ppfh)                                    //~v13jI~
{                                                               //~5502I~
#ifdef UNX                                                         //~v214I~
    return 0;                                                      //~v214I~
#else  //!UNX                                                      //~v214I~
static UCHAR eof[1]={EOFCHAR};                                  //~5502R~
//****************************                                  //~5502I~
	if (UCBITCHK(Gopt2,GOPT2EOFDROP))	//never write           //~5502I~
//     	return;                                                    //~v13jR~
       	return 0;                                                  //~v13jI~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~v180I~
       	return 0;                                                  //~v180I~
	if (UCBITCHK(Ppfh->UFHflag13,UFHF13WV))	//recfm=V              //~vaj0I~
       	return 0;                                                  //~vaj0I~
	if (UCBITCHK(Ppfh->UFHflag6,UFHF6WTEXTMAC)) //mac type write   //~v47XR~
       	return 0;                                                  //~v47XI~
//  if (UCBITCHK(Ppfh->UFHflag3,UFHF3WTEXTUNIX))                   //~v213R~
//     	return 0;                                                  //~v213R~
#ifdef FTPSUPP                                                     //~v71WI~
	if (FILEISTSO(Ppfh))                                           //~v71WI~
       	return 0;                                                  //~v71WI~
#endif                                                             //~v71WI~
	if (!UCBITCHK(Gopt2,GOPT2EOFWRITE)	//same as input         //~5502R~
   	&&  !UCBITCHK(Ppfh->UFHflag,UFHFEOFEXIST))//input has no eof//~5502R~
//  		return;	//for new file,set by GOPT2EOFWIFNEW at filechkeof//~v13jR~
    		return 0;	//for new file,set by GOPT2EOFWIFNEW at filechkeof//~v13jI~
  return                                                           //~v13jI~
    filewrite(Ppfh,eof,1);				//write EOF             //~5502R~
//  return;                                                        //~v13jR~
#endif //!UNX                                                      //~v214I~
}//fileeofwrite                                                 //~5502I~
//*******************************************************          //~vaj0I~
//*write variable record length header                             //~vaj0I~
//*rc:992=lrecl over                                               //~vazgI~
//*******************************************************          //~vaj0I~
int  filewriteVRH(PUFILEH Ppfh,PULINEH Pplh)                       //~vaj0I~
{                                                                  //~vaj0I~
 	int len,vfmt,rtype,wlen=4;                                     //~vaj0R~
    int rc;                                                        //~vajbI~
    int chklen=0,maxlen=0;                                         //~vazgI~
    char hdr[4];                                                   //~vaj0I~
//  PULINEH plh;                                                   //~vaj0I~//~vajbR~
//****************************                                     //~vaj0I~
//  if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT2))	//cont line        //~vazfR~
    if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1))	//not last line of cont lines//~vazfI~
    	return 0;                                                  //~vaj0I~
//    len=Pplh->ULHlen;                                              //~vaj0I~//~vajbR~
//    if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1))   //cont line        //~vaj0I~//~vajbR~
//    {                                                              //~vaj0I~//~vajbR~
//        for(plh=Pplh;plh=UGETQNEXT(plh),plh;)                      //~vaj0R~//~vajbR~
//        {                                                          //~vaj0I~//~vajbR~
//            if (plh->ULHtype!=ULHTDATA) //file data                //~vaj0I~//~vajbR~
//                continue;                                          //~vaj0I~//~vajbR~
//            if (!UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))   //cont line//~vaj0R~//~vajbR~
//                break;                                             //~vaj0I~//~vajbR~
//            len+=plh->ULHlen;                                      //~vaj0I~//~vajbR~
//        }                                                          //~vaj0I~//~vajbR~
//    }                                                              //~vaj0I~//~vajbR~
	len=Svbuffsz;                                                  //~vajbR~
    vfmt=Ppfh->UFHvfmt;                                            //~vaj0I~
    switch(vfmt)                                               //~v6m0I~//~vaj0I~
    {                                                          //~v6m0I~//~vaj0I~
    case UFGETS_VFMT_HWDATA:                                   //~v6m0I~//~vaj0I~
        chklen=len;                                                //~vazgI~
		maxlen=MAXLRECLV;                                          //~vazgI~
        wlen=2;                                                    //~vaj0I~
        break;                                                 //~v6m0I~//~vaj0I~
    case UFGETS_VFMT_HW:                                       //~v6m0I~//~vaj0I~
        chklen=len;                                                //~vazgI~
		maxlen=MAXLRECLV;                                          //~vazgI~
    	len+=2;                                                    //~vaj0I~
        wlen=2;                                                    //~vaj0I~
        break;                                                 //~v6m0I~//~vaj0I~
    case UFGETS_VFMT_FWDATA:                                   //~v6m0I~//~vaj0I~
        break;                                                 //~v6m0I~//~vaj0I~
    case UFGETS_VFMT_FW:                                       //~v6m0I~//~vaj0I~
    	len+=4;                                                    //~vaj0I~
        break;                                                 //~v6m0I~//~vaj0I~
    case UFGETS_VFMT_RDW:                                      //~v6m0I~//~vaj0I~
        chklen=len;                                                //~vazgI~
		maxlen=MAXLRECLV;                                          //~vazgI~
    	len+=4;                                                    //~vaj0I~
        len<<=16;		//llllzzzz                                 //~vaj0R~
        break;                                                 //~v6m0I~//~vaj0I~
    case UFGETS_VFMT_MFH2:                                      //~v6m0I~//~vaj0R~
        chklen=len;                                                //~vazgI~
		maxlen=0x0fff;    //12bit                                  //~vazgI~
        wlen=2;                                                    //~vaj0I~
        rtype=Pplh->ULHmflinetype;                                 //~vaj0I~
//      if (!rtype)                                                //~vazkR~
//          rtype=UFGETS_MFHRT_NORMALUD;    //normal user data     //~vazkR~
        len|=(rtype<<(8+4));    //top 4 bit:record type            //~vaj0I~
        break;  //missing                                          //~vazkI~
    case UFGETS_VFMT_MFH4:                                         //~vaj0I~
        rtype=Pplh->ULHmflinetype;                                 //~vaj0I~
//      if (!rtype)                                                //~vazkR~
//          rtype=UFGETS_MFHRT_NORMALUD;    //normal user data     //~vazkR~
        len|=(rtype<<(24+4));    //top 4 bit:record type           //~vaj0I~
        break;                                                 //~v6m0I~//~vaj0I~
    }                                                          //~v6m0I~//~vaj0I~
    if (maxlen && chklen>maxlen)                                   //~vazgI~
    {                                                              //~vazgI~
    	uerrmsg("RECFM=V %d'th record, length(%d) overflow(>%d)",  //~vazgI~
    	        "RECFM=V の 第 %d レコードの レコード長(%d) が制限(>%d)を超えています",//~vazgI~
                Pplh->ULHlinenor,chklen,maxlen);                   //~vazgR~
        Svbuffsz=0;                                                //~vazgI~
        return FCWRC_VOVF;  //overflow                             //~vazgI~
    }                                                              //~vazgI~
    if (wlen==2)                                                   //~vaj0I~
	    UUS2BESTR(len,hdr);                                        //~vaj0R~
    else                                                           //~vaj0I~
	    UUL42BESTR(len,hdr);                                       //~vaj0R~
//	return  filewrite(Ppfh,hdr,wlen);				//write len hdr//~vaj0I~//~vajbR~
//  rc=filewrite(Ppfh,hdr,wlen);				//write len hdr    //~vb06R~
    rc=filewrite(Ppfh,hdr,(size_t)wlen);				//write len hdr//~vb06I~
    if (Svbuffsz)                                                  //~vajbI~
    {   wlen=Svbuffsz;                                             //~vajbI~
        Svbuffsz=0;                                                //~vajbI~
        if (!rc)                                                   //~vajbI~
//    		rc+=filewrite(Ppfh,Svbuff,wlen);				//write len hdr//~vb06R~
      		rc+=filewrite(Ppfh,Svbuff,(size_t)wlen);				//write len hdr//~vb06I~
    }                                                              //~vajbI~
  	return rc;                                                     //~vajbR~
}//filewriteVRH                                                    //~vazgR~
#ifdef UTF8SUPPH                                                   //~v92nI~//~va00I~
//*******************************************************          //~v92nI~//~va00I~
//*file write with UTF8<->locale conversion                        //~v92nI~//~va00I~
//*      keep cv err char                                          //~va1EI~
//*rc   :0:ok,else:errno,991:cvf2l err                                            //~v92nI~//~va00R~
//*******************************************************          //~v92nI~//~va00I~
//int filecvwrite(int Popt,PUFILEH Ppfh,PULINEH Pplh,char *Pbuff,size_t Plen)     //~v92nI~//~va00R~//~va1ER~
int filecvwrite(int Popt,PUFILEH Ppfh,PULINEH Pplh,UCHAR *Pbuff,size_t Plen,UCHAR *Pdbcs,int Pdbcstblen)//~va1EI~//~va50R~
{                                                                  //~v92nI~//~va00I~
	int cvsw=0,rc,len;                                             //~v92nR~//~va00I~
    UCHAR *pbuff;                                                   //~v92nI~//~va00I~//~va50R~
#ifdef UTF8SUPPH                                                   //~va00I~
    UCHAR *pdbcs;                                                   //~va00I~//~va50R~
#endif                                                             //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int cvebcsw=0,rc2;                                             //~va50R~
    int handle;                                                    //~va79R~
    int newhandle;                                                 //~va7tI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	int opt=0;                                                     //~va68I~
//****************************                                     //~v92nI~//~va00I~
//	if (UCBITCHK(Ppfh->UFHflag13,UFHF13WV))                        //~vajbI~
//      filewriteVRH(Ppfh,Pplh);    //variable record header       //~vaj0I~//~vajbI~
  	if (Popt & FSOC_FILESAVE && UCBITCHK(Ppfh->UFHflag13,UFHF13WV))//~vajbR~
        Sswvhdr=1;                                                 //~vajbI~
    else                                                           //~vajbI~
        Sswvhdr=0;                                                 //~vajbI~
	if (Popt & FSOC_ADJLRECL)	//called from filesave normal data to another file//~va68I~
    	if (   UCBITCHK(Ppfh->UFHflag11,UFHF11WRECORD)             //~va68I~
    	   || (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD) && !UCBITCHK(Ppfh->UFHflag6,UFHF6EOLCHNG))//~va68I~
        )                                                          //~va68I~
        opt|=FWRMO_ADJLRECL;                                       //~va68R~
#ifdef UTF8SUPPH                                                   //~va00I~
//  pdbcs=Pplh->ULHdbcs;                                           //~va1ER~
    pdbcs=Pdbcs;                                                   //~va1EI~
    handle=Ppfh->UFHhandle;                                        //~va79R~
    newhandle=0;	//default:cfg converter                        //~va7tI~
    if (Popt & FSOC_EBCHANDLEP)                                    //~va7tI~
    	newhandle=FSOC_GETHANDLE(Popt);                            //~va7tI~
  if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))	//bynary mode          //~va00R~
#endif                                                             //~va00I~
  {                                                                //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (PFH_ISEBC(Ppfh))    //from ebc file                        //~va50I~
    {                                                              //~va50I~
        if (!newhandle) //not cpeb parm                            //~vajkI~
	    	newhandle=handle;		//trans from old handle for B2F,B2L//~vajkR~
		if (Popt & FSOC_CPU8)  //write by utf8   code              //~va50I~
        	cvebcsw=XEEBCO_B2F;            //ebc->utf8             //~va50R~
        else                                                       //~va50I~
		if (Popt & FSOC_CPLC)  //write by utf8   code              //~va50I~
        	cvebcsw=XEEBCO_B2L;            //ebc->locale;          //~va50R~
        else                                                       //~va68I~
        {                                                          //~va7tI~
		    if (Popt & FSOC_EBCHANDLEP && newhandle!=handle)       //~va7tI~
            {                                                      //~va7tI~
        		cvebcsw=XEEBCO_B2B;            //ebc->ebc(codepage change)//~va7tI~
                newhandle=(newhandle<<8)|handle;                   //~va7tI~
            }                                                      //~va7tI~
        	opt|=FWRMO_2EBC;                                       //~va68I~
        }                                                          //~va7tI~
    }                                                              //~va50I~
    else                                                           //~va50I~
	if (Popt & FSOC_CPEB)  //cpeb optiion                          //~va50I~
    {                                                              //~va50I~
    	if (FILEUTF8MODE(Ppfh))         //original is utf8         //~va50I~
        	cvebcsw=XEEBCO_DD2B;         //ddfmt->ebc              //~va50R~
        else                                                       //~va50I~
        	cvebcsw=XEEBCO_L2B;         //locale->ebc              //~va50R~
        opt|=FWRMO_2EBC;                                           //~va68R~
    }                                                              //~va50I~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	if (Popt & FSOC_CPLC)  //write by locale code                  //~v92nI~//~va00R~
    {                                                              //~v92nI~//~va00I~
    	if (FILEUTF8MODE(Ppfh))         //original is utf8                           //~v92nI~//~va00R~
        {                                                          //~va20I~
#ifdef UTF8UCS2    //dd2l required                                 //~va20R~
        	cvsw=XEUTFCVO_CPLCUCS2;            //locale<--ucs2     //~va20I~
#else                                                              //~va20I~
#ifdef UTF8SUPPH                                                   //~va00I~
         if (!pdbcs)		//utf8 is left                         //~va00R~
#endif                                                             //~va00I~
        	cvsw=XEUTFCVO_CPLC;            //utf8->locale          //~v92nR~//~va00I~
#endif                                                             //~va20M~
        }                                                          //~va20I~
    }                                                              //~v92nI~//~va00I~
    else                                                           //~v92nI~//~va00I~
	if (Popt & FSOC_CPU8)  //write by utf8   code                  //~v92nI~//~va00R~
    {                                                              //~v92nI~//~va00I~
    	if (!FILEUTF8MODE(Ppfh))                                   //~v92nI~//~va00I~
        	cvsw=XEUTFCVO_CPU8;            //utf8<-locale          //~v92nI~//~va00I~
#ifdef UTF8SUPPH                                                   //~va00M~
        else    	//org is utf8                                  //~va00I~
        	if (pdbcs)				//f2l done                     //~va00I~
            {                                                      //~va20I~
    #ifdef UTF8UCS2                                                //~va20I~
	        	cvsw=XEUTFCVO_CPU8UCS2;          //utf8<-ucs2      //~va20R~
    #else                                                          //~va20I~
	        	cvsw=XEUTFCVO_CPU8;            //utf8<-locale      //~va00I~
    #endif                                                         //~va20I~
            }                                                      //~va20I~
#endif                                                             //~va00M~
    }                                                              //~v92nI~//~va00I~
#ifdef FTPSUPP                                                     //~v92nI~//~va00I~
    else                                                           //~v92nI~//~va00I~
    {                                                              //~v92nI~//~va00I~
    	if (FILEISTSO(Ppfh))                                       //~v92nI~//~va00I~
//  		if (FILEUTF8MODE(Ppfh)) //utf8-->tso                               //~v92nI~//~va00R~
//      		cvsw=XEUTFCVO_CPLC;            //utf8->locale      //~v92nI~//~va00R~
            ;                                                      //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
		else		//Not TSO,conversion not specified             //~va00I~
        {                                                          //~va00I~
    		if (FILEUTF8MODE(Ppfh))	//orig is utf8                 //~va00I~
         		if (pdbcs)				//f2l done                 //~va00R~
                {                                                  //~va20I~
    #ifdef UTF8UCS2                                                //~va20I~
	        		cvsw=XEUTFCVO_CPU8UCS2;          //utf8<-ucs2  //~va20I~
    #else                                                          //~va20I~
        			cvsw=XEUTFCVO_CPU8;            //back to utf8  //~va00I~
    #endif                                                         //~va20I~
                }                                                  //~va20I~
        }                                                          //~va00I~
#endif                                                             //~va00I~
    }//no cv parm                                                              //~v92nI~//~va00R~
#endif	//FTPSUPP                                                             //~v92nI~//~va00R~
  }                                                                //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  else                                                             //~va60R~
  {//binfile                                                       //~va60R~
    if (PFH_ISEBC(Ppfh))    //from ebc file                        //~va61I~
    {                                                              //~va61I~
        if (!newhandle) //not cpeb parm                            //~vajkI~
	    	newhandle=handle;		//trans from old handle for B2F,B2L//~vajkR~
		if (Popt & FSOC_CPU8)  //write by utf8   code              //~va61I~
        	cvebcsw=XEEBCO_B2F|XEEBCO_BIN;            //ebc->utf8  //~va61I~
        else                                                       //~va61I~
		if (Popt & FSOC_CPLC)  //write by utf8   code              //~va61I~
        	cvebcsw=XEEBCO_B2L|XEEBCO_BIN;            //ebc->locale;//~va61I~
        else	                                                   //~va7tI~
		if (Popt & FSOC_EBCHANDLEP && newhandle!=handle)           //~va7tI~
        {                                                          //~va7tI~
        	cvebcsw=XEEBCO_B2B|XEEBCO_BIN;            //ebc->ebc(codepage change)//~va7tI~
            newhandle=(newhandle<<8)|handle;                       //~va7tI~
        }                                                          //~va7tI~
    }                                                              //~va61I~
    else                                                           //~va61I~
	if (Popt & FSOC_CPEB)  //L2B                                   //~va60R~
    {                                                              //~va60R~
        cvebcsw=XEEBCO_L2B|XEEBCO_BIN; //no dbcs consideration     //~va60R~
    }                                                              //~va60R~
  }                                                                //~va60R~
    if (cvebcsw)        //ddfmt->ebc                               //~va50I~
    {                                                              //~va50I~
        cvebcsw|=XEEBCO_ERRREP;                                    //~va50I~
        if (Popt & FSOC_EOL2)                                      //~va50I~
        	cvebcsw|=XEEBCO_EOL2;                                  //~va50M~
        else                                                       //~va50I~
        if (Popt & FSOC_EOL1)                                      //~va50R~
        	cvebcsw|=XEEBCO_EOL1;                                  //~va50I~
        if (!(cvebcsw & XEEBCO_BIN))          //not bin file       //~va6cR~
        {                                                          //~va6cI~
			if (Popt & FSOC_SOSI_DEL)	//SOSI delete              //~va6cR~
            	cvebcsw|=XEEBCO_SOSICMDD;                          //~va6cR~
            else                                                   //~va6cI~
			if (Popt & FSOC_SOSI_REP)	//SOSI delete              //~va6cR~
            	cvebcsw|=XEEBCO_SOSICMDR;                          //~va6cR~
            else                                                   //~va6cI~
			if (Popt & FSOC_SOSI_INS)	//SOSI delete              //~va6cR~
            	cvebcsw|=XEEBCO_SOSICMDI;                          //~va6cR~
    	}                                                          //~va6cI~
//      rc2=xeebc_cvdatawb(cvebcsw,Pbuff,Plen,&pbuff,&len,Pdbcs,Pdbcstblen);//~va50R~//~va79R~
//      rc2=xeebc_cvdatawb(cvebcsw,newhandle,Pbuff,Plen,&pbuff,&len,Pdbcs,Pdbcstblen);//~vb06R~
        rc2=xeebc_cvdatawb(cvebcsw,newhandle,Pbuff,(int)Plen,&pbuff,&len,Pdbcs,Pdbcstblen);//~vb06I~
        if (Popt & FSOC_ERRREP)                                    //~va50I~
            rc2=0;                                                 //~va50I~
//      rc=filewrite(Ppfh,pbuff,len);                              //~va68R~
//      rc=filewrite_recordmode(opt,Ppfh,pbuff,len);               //~vb06R~
        rc=filewrite_recordmode(opt,Ppfh,pbuff,(size_t)len);       //~vb06I~
        if (!rc && rc2)                                            //~va50I~
			rc=FCWRC_CVERR;                                        //~va50R~
    }                                                              //~va50I~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	if (cvsw)                                                      //~v92nR~//~va00I~
	{                                                              //~v92nI~//~va00I~
      if (Pdbcstblen)                                              //~va1EI~
      {                                                            //~va1EI~
#ifdef UTF8UCS2                                                    //~va20I~
        if (cvsw & XEUTFCVO_CPLCUCS2            //locale<--ucs2    //~va20I~
        &&  Popt & FSOC_ERRREP                 //IE option specified//~va20I~
		)                                                          //~va20I~
	        cvsw|=XEUTFCVO_ERRREPQM; //rep by "?"                  //~va20I~
        else                                                       //~va20I~
#endif                                                             //~va20I~
		if (Gutfmode2 & GUM2_KEEPIFCVERR)                          //~va1EI~
        	cvsw|=XEUTFCVO_NOERRREP; //keep org byte               //~va1EI~
        else                                                       //~va1EI~
	        cvsw|=XEUTFCVO_ERRREPQM; //rep by "?"                  //~va1EI~
//      rc=xeutf_cvdatawb(cvsw,Pbuff,Plen,&pbuff,&len,Pdbcs,Pdbcstblen);//~vb06R~
        rc=xeutf_cvdatawb(cvsw,Pbuff,(int)Plen,&pbuff,&len,Pdbcs,Pdbcstblen);//~vb06I~
UTRACEP("filecvwrite cvdatawb rc=%d,inplen=%d,dbcstlen=%d,outlen=%d\n",rc,Plen,Pdbcstblen,len);//~va1ER~
UTRACED("filecvwrite inp",Pbuff,(int)Plen);                        //~vb06R~
UTRACED("filecvwrite dbcs",Pdbcs,Pdbcstblen);                      //~va1ER~
      }                                                            //~va1EI~
      else                                                         //~va1EI~
      {                                                            //~va1EI~
        cvsw|=XEUTFCVO_ERRREPQM; //rep by "?"                      //~va00R~
//      rc=xeutf_cvdata(cvsw,Pbuff,Plen,&pbuff,&len);              //~v92nR~//~vb06R~
        rc=xeutf_cvdata(cvsw,Pbuff,(int)Plen,&pbuff,&len);         //~vb06I~
UTRACEP("filecvwrite cvdata rc=%d,inplen=%d,outlen=%d\n",rc,Plen,len);//~va1EI~
      }                                                            //~va1EI~
UTRACED("filecvwrite out",pbuff,len);                              //~va1EI~
        if (rc)                                                    //~va00I~
            if (Popt & FSOC_ERRREP)                                //~va00R~
	            rc=0;                                              //~va00I~
        if (!rc)                                                   //~v92nI~//~va00I~
//      	rc=filewrite(Ppfh,pbuff,len);                          //~v92nR~//~va68R~
//      	rc=filewrite_recordmode(opt,Ppfh,pbuff,len);           //~vb06R~
        	rc=filewrite_recordmode(opt,Ppfh,pbuff,(size_t)len);   //~vb06I~
        else                                                       //~va00I~
        {                                                          //~va00I~
//  		UCBITON(Ppfh->UFHflag10,UFHF10UTF8SAVEERR);	//bynary mode//~va00R~
//      	rc=filewrite(Ppfh,pbuff,len);                          //~va68R~
//      	rc=filewrite_recordmode(opt,Ppfh,pbuff,len);           //~vb06R~
        	rc=filewrite_recordmode(opt,Ppfh,pbuff,(size_t)len);   //~vb06I~
            if (!rc)                                               //~va00I~
		        rc=FCWRC_CVERR;                                    //~va00R~
        }                                                          //~va00I~
	}                                                              //~v92nI~//~va00I~
    else                                                           //~v92nI~//~va00I~
//      rc=filewrite(Ppfh,Pbuff,Plen);                             //~v92nI~//~va68R~
        rc=filewrite_recordmode(opt,Ppfh,Pbuff,Plen);              //~va68I~
    if (Sswvhdr)                                                   //~vajbI~
      rc=                                                          //~vazgI~
		filewriteVRH(Ppfh,Pplh);    //variable record header       //~vajbI~
	return rc;                                                     //~v92nI~//~va00I~
}//filecvwrite                                                     //~v92nI~//~va00I~
//*******************************************************          //~va81I~
//*file write with ebcdic file for xprint **/***                   //~va81I~
//*rc=1:rep EOL to "." (for text mode not /Me or bin file/record mode)//~va81R~
//*rc=4:write err                                                  //~va81I~
//*******************************************************          //~va81I~
int filecvwrite_ebcxpwk(int Popt,PUFILEH Ppfh,UCHAR *Pbuff,size_t Plen)//~va81I~
{                                                                  //~va81I~
	UCHAR *pc,*pce;                                                //~va81I~
    int rc=0;                                                      //~va81R~
//****************************                                     //~va81I~
	for (pc=Pbuff,pce=pc+Plen;pc<pce;pc++)                         //~va81I~
    {                                                              //~va81I~
    	if (*pc==EBC_NL)                                           //~va81I~
        {                                                          //~va81I~
        	rc=1;                                                  //~va81I~
        	*pc=CHAR_EBC_SUB;	//0x3f                             //~va81R~
        }                                                          //~va81I~
    }                                                              //~va81I~
    if (filewrite(Ppfh,Pbuff,Plen))                                //~va81R~
    	return 4;                                                  //~va81I~
	return rc;                                                     //~va81R~
}//filecvwrite_ebcxpwk                                             //~va81I~
#endif                                                             //~v92nI~//~va00I~
//****************************************************************//~5503M~
// fileeofchk                                                   //~5503I~
//* try read eof id ^z(0x1a)                                    //~5503M~
//*parm1:pfj                                                    //~5503M~
//*retrn:rc 0:ok ,4:err                                         //~5503M~
//****************************************************************//~5503M~
int fileeofchk(PUFILEH Ppfh)                                    //~5503I~
{                                                               //~5503M~
#ifdef UNX                                                         //~v214I~
#else  //!UNX                                                      //~v214I~
	UCHAR buff[2];                                              //~5503M~
    size_t len;                                                    //~v08qI~
//****************                                              //~5503M~
	UCBITOFF(Ppfh->UFHflag,UFHFEOFEXIST);	//clear once        //~5503I~
	if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))	//new file          //~5503M~
    {                                                           //~5503M~
		if (UCBITCHK(Gopt2,GOPT2EOFWIFNEW))	//as input,write eif if NEW//~5503M~
			UCBITON(Ppfh->UFHflag,UFHFEOFEXIST);	//write eof //~5503M~
    	return 0;                                               //~5503M~
	}                                                           //~5503M~
    if (!Ppfh->UFHsize)		//size 0,no EOF                     //~5503M~
    	return 0;                                               //~5503M~
                                                                //~5503M~
//*OS/2 *  return 0a if read pos is 0d or 0a                    //~5503I~
//*OS/2 *  read err(len=0) if read pos is 1a and errno=0x1d=29=EPASTEOF//~5503I~
//*DOS  *  return 0a if read pos is 0d                          //~5503I~
//*DOS  *  read err(le=0) if read pos is 0a or 1a and no errno set//~5503I~
    if (fileseek(Ppfh,(FPOST)(Ppfh->UFHsize-1),SEEK_SET))       //~5503M~
    {                                                              //~v08qI~
//      UTRACEP("rc=4,fileseek-1 rc=%d",errno);                    //~v08sR~
    	return 4;                                               //~5503M~
    }                                                              //~v08qI~
    if (len=fread(buff,1,1,Ppfh->UFHhfile),len) //read ok          //~v08qR~
    {                                                              //~v08qI~
//      UTRACED("rc=0,fread-1",buff,(int)len);                     //~v08sR~
        if (UCBITCHK(Ppfh->UFHflag3,UFHF3RBIN))//bin mode open     //~v09YR~
            if (*buff==0x1a)                                       //~v09YI~
				UCBITON(Ppfh->UFHflag,UFHFEOFEXIST);               //~v09YI~
		return 0;		//no EOF                                //~5503I~
    }                                                              //~v08qI~
    else                                                           //~v08qI~
    {                                                              //~v09YI~
        if (UCBITCHK(Ppfh->UFHflag3,UFHF3RBIN))//bin mode open     //~v09YR~
	    	return 4;		//ioerr                                //~v09YI~
        if (!feof(Ppfh->UFHhfile))//last 1a cause eof when text mode//~v08sR~
        {                                                          //~v08sI~
//			UTRACEP("ioe ,fread-1 rc=%d\n",errno);                 //~v08sR~
	    	return 4;		//ioerr                                //~v08sI~
		}                                                          //~v08sI~
	}//read fail                                                   //~v09YI~
//     	UTRACEP("eof ,fread-1 rc=%d\n",errno);                     //~v08sI~
////#ifdef DOS                                                     //~v08sR~
//#if defined(DOS) || defined(W32)                                 //~v08sR~
//*last byte read err by 0a of 0d0a or 1a	                    //~5503I~
//    if (fileseek(Ppfh,(FPOST)(Ppfh->UFHsize-2),SEEK_SET))        //~v08sR~
//    {                                                            //~v08sR~
//        UTRACEP("rc=4,fileseek-2 rc=%d",errno);                  //~v08sR~
//    	return 4;                                                  //~v08sR~
//    }                                                            //~v08sR~
//    if (len=fread(buff,1,1,Ppfh->UFHhfile)) //read ok            //~v08sR~
//    {                                                            //~v08sR~
//        UTRACED("rc==0,fread-2",buff,len);                       //~v08sR~
//        if (*buff=='\n')                                         //~v08sR~
//			return 0;		//last 2 byte is 0d0a                  //~v08sR~
//	}                                                              //~v08sR~
//    else                                                         //~v08sR~
//        if (feof(Ppfh->UFHhfile))                                //~v08sR~
//    	    UTRACEP("eof ,fread rc=%d\n",errno);                   //~v08sR~
//        else                                                     //~v08sR~
//        	UTRACEP("ioe ,fread rc=%d\n",errno);                   //~v08sR~
//		else//read ok	 -->311a case                           //~5503I~
//	else	//read err -->0d0a1a case                           //~5503I~
//#else                                                            //~v08sR~
//    if (errno!=EPASTEOF)                                         //~v08sR~
//	{                                                              //~v08sR~
//		uerrmsg("%s read test for eof failed(rc=%d)",              //~v08sR~
//				"%s のI/Oエラー(EOFチェック),rc=%d",               //~v08sR~
//				Ppfh->UFHfilename,errno);                          //~v08sR~
//    	return 4;                                                  //~v08sR~
//	}                                                              //~v08sR~
//#endif                                                           //~v08sR~
	UCBITON(Ppfh->UFHflag,UFHFEOFEXIST);                        //~5503I~
#endif //!UNX                                                      //~v214I~
	return 0;                                                   //~5503M~
}//fileeofchk                                                   //~5503I~
                                                                //~5503M~
//**************************************************
//*getdisplayline
//* get next/prev display(not excluded) line
//*parm 1:plh
//*parm 2:count(if >0 forward,if <0 backward)
//*parm 3:output actual step count(option)
//*return:plh or 0
//**************************************************
PULINEH getdisplayline(PULINEH Pplh,int Pstep,int *Ppstep)
{
	int step=0,outstep=0;
	PULINEH plh;
//********************
	plh=Pplh;
	if (Pstep<0)
	{
		while (plh=UGETQPREV(plh),plh)
        {                                                          //~v0i0I~
 			if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))
				if (--step==Pstep)
					break;
            if (plh==Splhstop)                                     //~v0i0I~
                break;                                             //~v0i0I~
        }                                                          //~v0i0I~
		outstep=-step;
	}
	else		//forward
		if (Pstep>0)
		{
			while (plh=UGETQNEXT(plh),plh)
            {                                                      //~v0i0I~
 				if (!UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))
					if (++step==Pstep)
						break;
        	    if (plh==Splhstop)                                 //~v0i0I~
    	            break;                                         //~v0i0I~
	        }                                                      //~v0i0I~
			outstep=step;
		}
	if (Ppstep)
		*Ppstep=outstep;
    return plh;
}//getdisplayline

//**************************************************               //~v0i0I~
//*getdisplayline2                                                 //~v0i0I~
//* get next/prev display(not excluded) line with stopper          //~v0i0I~
//*parm 1:plh                                                      //~v0i0I~
//*parm 2:count(if >0 forward,if <0 backward)                      //~v0i0I~
//*parm 3:plh stopper                                              //~v0i0I~
//*parm 4:output actual step count(option)                         //~v0i0I~
//*return:plh or 0                                                 //~v0i0I~
//**************************************************               //~v0i0I~
PULINEH getdisplayline2(PULINEH Pplh,int Pstep,PULINEH Pplhstop,int *Ppstep)//~v0i0I~
{                                                                  //~v0i0I~
	PULINEH plh;                                                   //~v0i0I~
//********************                                             //~v0i0I~
    if (Pplh==Pplhstop)                                            //~v0i0I~
    {                                                              //~v0i0I~
    	if (Ppstep)                                                //~v0i0I~
        	*Ppstep=1;                                             //~v0i0I~
        return Pplh;                                               //~v0i0I~
	}                                                              //~v0i0I~
	Splhstop=Pplhstop;                                             //~v0i0I~
	plh=getdisplayline(Pplh,Pstep,Ppstep);                         //~v0i0I~
	Splhstop=0;                                                    //~v0i0I~
    return plh;                                                    //~v0i0I~
}//getdisplayline2                                                 //~v0i0I~
                                                                   //~v0i0I~
//**************************************************
//*lineseqchk
//* sequence chk 2 plh lineno+suffix
//*parm 1:plh1
//*parm 2:plh2
//*return:<0:plh1<plh2, 0:plh1=plh2, >0:plh1>plh2
//**************************************************
long lineseqchk(PULINEH Pplh1,PULINEH Pplh2)
{
	long rc;
//********************
	if (rc=(int)(Pplh1->ULHlinenor-Pplh2->ULHlinenor),rc)
		return rc;
	if (rc=(int)(Pplh1->ULHsuffix-Pplh2->ULHsuffix),rc)
		return rc;
    if (Pplh1==Pplh2)                                              //~v66fI~
        return 0;                                                  //~v66fI~
	if(Pplh1->ULHtype==ULHTEXCLUDE)
		return (long)-1;
	if(Pplh2->ULHtype==ULHTEXCLUDE)
		return (long)1;
	return (long)0;
}//lineseqchk

//**************************************************               //~v0fmI~
//*ufilesetfhfilename                                              //~v0fmI~
//* set filename to ufh,and also to shortname fow dpmi/w95         //~v0fmI~
//* for remote file;set local filename and remote flag             //~v542I~
//*parm 1:pfh                                                      //~v0fmI~
//*parm 2:longname                                                 //~v0fmI~
//*return:0,4:longname                                             //+vb7eR~
//**************************************************               //~v0fmI~
//void ufilesetfhfilename(PUFILEH Ppfh,char *Plongname)            //~v542R~
int ufilesetfhfilename(PUFILEH Ppfh,char *Plongname)               //~v542I~
{                                                                  //~v0fmI~
#ifdef FTPSUPP                                                     //~v54pR~
	PUFTPHOST puftph;                                              //~v54pR~
#endif                                                             //~v54pR~
//********************                                             //~v0fmI~
	UTRACEP("%s:inp filename=%s\n",UTT,Plongname);                 //~vb06I~
#ifdef W32                                                         //~vb06I~
  	ufilesetfhfilename_reservedname(0,Ppfh,Plongname);             //~vb06R~
#else                                                              //~vb06I~
  	ustrncpyz(Ppfh->UFHfilename,Plongname,sizeof(Ppfh->UFHfilename));//~v0fmI~
#endif                                                             //~vb06M~
#ifdef W32                                                         //~vawhI~
    UCBITOFF(Ppfh->UFHflag13,UFHF13REMOTEUNC);                     //~vav2R~
#endif                                                             //~vawhI~
#ifdef FTPSUPP                                                     //~v542M~
    if (uftpisremote(Plongname,&puftph)) //remote hostname prefix exist//~v54pR~
    {                                                              //~v542M~
        Ppfh->UFHdirsepc=FTP_DIR_SEPC;                             //~v542M~
        UCBITON(Ppfh->UFHflag6,UFHF6REMOTE);                       //~v542M~
//  	xeftpgetwdfname(Plongname,Ppfh->UFHftpwdfnm);              //~v70zR~
//  	xeftpgetwdfname(puftph,Plongname,Ppfh->UFHftpwdfnm);       //~v70zI~//+vb7eR~
    	if (xeftpgetwdfname(puftph,Plongname,Ppfh->UFHftpwdfnm,sizeof(Ppfh->UFHftpwdfnm))<0)//+vb7eI~
        	return 4;                                              //+vb7eI~
        Ppfh->UFHpuftph=puftph;                                    //~v54pR~
        if (UFTPHISTSO(puftph))                                    //~v70zI~
        {                                                          //~v70zI~
    	    UCBITON(Ppfh->UFHflag7,UFHF7TSO);                      //~v70zI~
	        Ppfh->UFHdirsepc=DSN_SEPC;                             //~v717I~
            if (strchr(Plongname,'('))                             //~v70zI~
	    	    UCBITON(Ppfh->UFHflag7,UFHF7PDSMEMBER);            //~v70zI~
            strupr(Ppfh->UFHfilename+puftph->UFTPHhostnmlen+1);    //~v717R~
        }                                                          //~v70zI~
        else                                                       //~va81I~
        if (UFTPH_ISSMB(puftph))                                   //~vac1R~
        {                                                          //~vac1R~
    	    UCBITON(Ppfh->UFHflag12,UFHF12SMB);                    //~vac1R~
            if (puftph->UFTPHflag & UFTPHFRWIN)                    //~vac1R~
	    	    UCBITON(Ppfh->UFHflag12,UFHF12RWIN);               //~vac1R~
        }                                                          //~vac1R~
    }                                                              //~v542M~
    else                                                           //~v542I~
    {                                                              //~v542I~
    	*Ppfh->UFHftpwdfnm=0;                                      //~v542I~
#endif                                                             //~v542M~
        UCBITOFF(Ppfh->UFHflag6,UFHF6REMOTE);                      //~v542I~
    	UCBITOFF(Ppfh->UFHflag12,UFHF12SMB|UFHF12RWIN);            //~vac1R~
        Ppfh->UFHdirsepc=DIR_SEPC;                                 //~v542M~
#ifdef W32                                                         //~vav2I~
		if (WIN_ISREMOTEPATH(Plongname))                           //~vav2I~
    		UCBITON(Ppfh->UFHflag13,UFHF13REMOTEUNC);              //~vav2R~
#endif                                                             //~vav2I~
#ifdef FTPSUPP                                                     //~v542I~
    }                                                              //~v542I~
#endif                                                             //~v542I~
#if defined(DPMI) || defined(W32)                                  //~v0fmI~
  #ifdef W32                                                       //~v53ZI~
   if (!FILEISREMOTE(Ppfh))                                        //~v53ZI~
  #endif                                                           //~v53ZI~
    ugetvfatalias(UGVFA_WILDCARD|UGVFA_NEW,	//may wildcard or new file//~v0foR~
		Plongname,Ppfh->UFHshortname,sizeof(Ppfh->UFHshortname));  //~v0foI~
#endif                                                             //~v0fmI~
    if (ufileisntfs(*Ppfh->UFHfilename)==1)                        //~v690I~
        UCBITON(Ppfh->UFHflag7,UFHF7NTFS);                         //~v690I~
    else                                                           //~v690I~
        UCBITOFF(Ppfh->UFHflag7,UFHF7NTFS);                        //~v690I~
#ifdef ARM                                                         //~vag1I~
    if (isonsdpath(Ppfh->UFHfilename))                             //~vag1I~
        UCBITON(Ppfh->UFHflag9,UFHF9SDCARD);                       //~vag1I~
#endif                                                             //~vag1I~
	UTRACEP("%s:UFHfilename=%s\n",UTT,Ppfh->UFHfilename);          //~vb06I~
	return 0;                                                      //~v542R~
}//ufilesetfhfilename                                              //~v0fmI~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************               //~v0fmI~//~va00I~
//*fsubf2l                                                         //~va00I~
//* get locale string for dirlist member name                      //~vauaR~
//*return:0,UALLOC_FAILED                                                        //~v542R~//~va00R~
//**************************************************               //~v0fmI~//~va00I~
int fsubf2l(int Popt,UCHAR *Ppfnm,int Plen,UCHAR *Ppfnmlc,UCHAR **Pppfnmlc,int *Ppflag,int *Ppoutlen)//~va00R~
{                                                                  //~v0fmI~//~va00I~
    int  flag,outlen,srclen,len;                                   //~va00R~
//  char wknamebylocale[_MAX_PATH],*pc;                            //~va1cR~
//  char wknamebylocale[_MAX_PATH*UTF8_F2LMAXRATE],*pc;            //~va1cR~//~vav9R~
    char wknamebylocale[_MAX_PATHF2L],*pc;                         //~vav9I~
    int opt;                                                       //~va10I~
//****************************                                     //~va00I~
	if (!(srclen=Plen))                                            //~va00I~
//  	srclen=strlen(Ppfnm);                                      //~vb06R~
    	srclen=(int)strlen(Ppfnm);                                 //~vb06I~
    UTRACED("fsubf2l inp",Ppfnm,srclen);                           //~vauaI~
//  flag=utfgetutf8str(UTFGUSO_OUTSTRZ|UTFGUSO_CVF2L|UTFGUSO_NOL2F,Ppfnm,srclen,wknamebylocale,0/*dbcs*/,0/*chof*/,0/*readlen*/,&outlen,0/*charwidth*/);//~va00R~//~va10R~
	opt=XEUTFGLPNO_STRZ|XEUTFGLPNO_MEMBNAME;                       //~va10R~
    if (Popt & FSUBF2LO_FNU8)                                      //~vag1I~
        opt|=XEUTFGLPNO_FNU8;                                      //~vag1I~
    else                                                           //~vag1I~
    if (Popt & FSUBF2LO_FNLC)                                      //~vag1I~
        opt|=XEUTFGLPNO_FNLC;                                      //~vag1I~
#ifdef W32UNICODE                                                  //~vavcI~
    if (Popt & FSUBF2LO_REMOTE)                                    //~vavcI~
        opt|=XEUTFGLPNO_REMOTE;                                    //~vavcI~
#endif                                                             //~vavcI~
//*no XEUTFGLPNO_LCWIDTHBYDDWIDTH  required because ctout is NULL  //~vauaI~
//  flag=xeutf_getlocalepathname(opt,Ppfnm,srclen,wknamebylocale,0/*pct*/,sizeof(wknamebylocale),&outlen);//~vauaR~
    flag=xeutf_getlocalepathname(opt,Ppfnm,srclen,wknamebylocale,0/*pct*/,sizeof(wknamebylocale),&outlen,NULL/*dddata*/,NULL/*dddbcs*/,NULL/*ddcode*/,0/*ddbuffsz*/,NULL/*pddlen*/);//~vauaI~
    if (flag==UALLOC_FAILED)                                       //~va10I~
    	return flag;                                               //~va10I~
    UTRACED("fsubf2l lc ",wknamebylocale,outlen);                  //~vauaI~
    if (Ppflag)                                                    //~va00I~
    	*Ppflag=flag;                                              //~va00I~
//  if (flag & UTFGUSRC_ALLUTF8)  //f2l done                       //~va00R~//~va10R~
    if (flag & XEUTFGU8MRC_UTF8)  //utf8 detected                  //~va10I~
    {                                                              //~va00I~
    	if (Popt & FSUBF2LO_ALLOC)	//malloc required              //~va00I~
        {                                                          //~va00I~
            if (Popt & FSUBF2LO_FREEIFNZ)   //malloc required      //~va00I~
            {                                                      //~va00I~
                pc=*Pppfnmlc;                                      //~va00I~
                UFREEIFNZ(pc)                                      //~va00I~
                *Pppfnmlc=0;                                       //~va00I~
            }                                                      //~va00I~
        	if (Popt & FSUBF2LO_ALLOCFULLSZ)                       //~va00I~
	        	len=_MAX_PATH;	//full size for memcpy             //~va00I~
            else                                                   //~va00I~
	        	len=outlen;                                        //~va00I~
//      	pc=UcALLOC(len+1);	//full size for memcpy             //~vb06R~
        	pc=UcALLOC((size_t)len+1);	//full size for memcpy     //~vb06I~
        	UALLOCCHK(pc,UALLOC_FAILED);                           //~va00I~
        	memcpy(pc,wknamebylocale,(UINT)outlen);                //~va00R~
          if (Pppfnmlc) //for safety                               //~vb70I~
            *Pppfnmlc=pc;                                          //~va00I~
        }                                                          //~va00I~
        else                                                       //~va00I~
        	memcpy(Ppfnmlc,wknamebylocale,(UINT)outlen+1);         //~va00I~
        if (Ppoutlen)                                              //~va00I~
        	*Ppoutlen=outlen;                                      //~va00I~
    }                                                              //~va00I~
    return 0;                                                      //~va00I~
}//fsubf2l                                                         //~va00I~
#endif                                                             //~va00I~
//**************************************************               //~v178I~
//*fsubseteolid                                                    //~v178I~
//* set end-of-line id from pfh                                    //~v178I~
//*parm 1:pfh                                                      //~v178I~
//*parm 2:optional plh when split chk required,if splitted set no eol//~v178R~
//*parm 3:optional output area                                     //~v178I~
//*return:none                                                     //~v178I~
//**************************************************               //~v178I~
int fsubseteolid(PUFILEH Ppfh,PULINEH Pplh,char *Pout)             //~v178R~
{                                                                  //~v178I~
	int eollen=0;                                                  //~v178I~
//********************                                             //~v178I~
    if (!UCBITCHK(Ppfh->UFHflag4,UFHF4BIN)) //text mode            //~v178R~
    {                                                              //~v178I~
      if (!(Pplh && UCBITCHK(Pplh->ULHflag4,ULHF4NOEOL)))//skip write eol at save//~v66iI~
      {                                                            //~v66iI~
    	if (!Pplh || !UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1))//not splitted rec//~v178I~
        {                                                          //~v178I~
          if (UCBITCHK(Ppfh->UFHflag11,UFHF11WTEXTEBC))   //write mode MAC//~va6DM~
          {                                                        //~va6DI~
            if (Pout)                                              //~va6DI~
          		*Pout++=EBC_NL;                                    //~va6DR~
            eollen=UFGETS_EOLID_EBC-1;   //+1=8                    //~va6DR~
          }                                                        //~va6DI~
          else                                                     //~va6DM~
          if (UCBITCHK(Ppfh->UFHflag6,UFHF6WTEXTMAC))   //write mode MAC//~v47XI~
          {                                                        //~v47XI~
                if (Pout)                                          //~v47XI~
                    *Pout++=0x0d;                                  //~v47XI~
                eollen=3;   //+1=4                                 //~v50tI~
          }                                                        //~v47XI~
          else                                                     //~v47XI~
          {                                                        //~v47XI~
            if (UCBITCHK(Ppfh->UFHflag3,UFHF3WTEXTPC))   //write mode PC//~v178R~
            {                                                      //~v178R~
                if (Pout)                                          //~v178R~
                    *Pout++=0x0d;                                  //~v178R~
                eollen++;                                          //~v178R~
            }                                                      //~v178R~
            if (Pout)                                              //~v178R~
                *Pout++=0x0a;                                      //~v178R~
          }                                                        //~v47XI~
            eollen++;                                              //~v178R~
        }                                                          //~v178I~
      }//no eol write                                              //~v66iI~
	}                                                              //~v178I~
    return eollen;                                                 //~v178I~
}//fsubseteolid                                                    //~v178I~
//**************************************************               //~v179I~
//*fsubnextlineoversplit                                           //~v179I~
//* advance line(count 1 for split lines as all,excluded line is also 1 line)//~v179R~
//*parm 1:1:ignore excluded line                                   //~v179I~
//*parm 2:current plh                                              //~v179I~
//*parm 3:advance step(1:next line,0:end of concatenated line)     //~v179R~
//*parm 4:optional stop plh(this is ok but cannot over this)       //~v179R~
//*return:plh,0 when overed stop plh                               //~v179R~
//**************************************************               //~v179I~
PULINEH fsubnextlineoversplit(int Popt,PULINEH Pplh,int Pstep,PULINEH Pplhstop)//~v179R~
{                                                                  //~v179I~
	int ii,stopsw=0;                                               //~v179R~
	PULINEH plh;                                                   //~v179R~
//********************                                             //~v179I~
    for (ii=0,plh=Pplh ; plh ; plh=UGETQNEXT(plh))                 //~v179R~
    {                                                              //~v179I~
    	if (stopsw)                                                //~v179I~
        	return 0;                                              //~v179I~
		if (plh==Pplhstop)                                         //~v179R~
        	stopsw=1;		//reached to last                      //~v179R~
//search end                                                       //~v179I~
		if (!Pstep)		//advance to end of concatinated line      //~v179I~
        {                                                          //~v179I~
            if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))//has next     //~v179I~
                continue;                                          //~v179I~
            break;                                                 //~v179I~
        }                                                          //~v179I~
//step down                                                        //~v179I~
        if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))//has prev         //~v179R~
        	continue;                                              //~v179I~
        if ((Popt & FSNL_DISPLINE) && UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))//ignore excluded//~v179R~
        	continue;                                              //~v179I~
        if (plh!=Pplh)	//not start line                           //~v179I~
        {                                                          //~v179I~
	        ii++;                                                  //~v179R~
            if (ii==Pstep)                                         //~v179I~
            	break;                                             //~v179I~
		}                                                          //~v179I~
    }                                                              //~v179I~
    return plh;                                                    //~v179R~
}//fsubnextlineoversplit                                           //~v179I~
//*******************************************************          //~v21nM~
//*dbcs tbl output for file client area only                       //~v21nM~
//*parm1:plh                                                       //~v21nM~
//*parm2:replaced data pos                                         //~v21nM~
//*parm3:replaced data dbcs pos                                    //~v21nM~
//*parm4:old data len                                              //~v21nM~
//*parm5:new data len                                              //~v21nM~
//*******************************************************          //~v21nM~
void filerepwordsetdbcstbl(PULINEH Pplh,UCHAR *Ppdata,UCHAR *Ppdbcs,int Polen,int Pnlen)//~v21nM~
{                                                                  //~v21nM~
    int len,pos1,pos2;                                             //~v21nM~
    char *pdbcs0;                                                  //~v21nI~
//***************                                                  //~v21nM~
	len=Pplh->ULHlen;                                              //~v21nM~
	pdbcs0=Pplh->ULHdbcs;                                          //~v21nR~
//	pos1=(int)((ULONG)Ppdbcs-(ULONG)pdbcs0);                       //~v40bR~//~vafkR~
	pos1=(int)((ULPTR)Ppdbcs-(ULPTR)pdbcs0);                       //~vafkI~
	pos2=pos1+Pnlen;                                               //~v21nM~
//  setobdbcserr(pdbcs0,len,pos1,pos2);//set outbound dbcs err     //~v49bR~
//*called for ebc file from wordrep                                //~va50I~
    setobdbcserr(0,pdbcs0,len,pos1,pos2);//set outbound dbcs err   //~v49bR~
    if (pos1 && *(pdbcs0+pos1-1)==UDBCSCHK_HKDBCSERR)   //prev 2nd byte replaced//~v453I~
    {                                                              //~v453I~
    	Ppdata--;                                                  //~v453R~
		Ppdbcs--;                                                  //~v453R~
		Pnlen++;                                                   //~v453I~
    }                                                              //~v453I~
    if (pos2 <len && *(pdbcs0+pos2)==UDBCSCHK_HKDBCSERR)   //next 1st byte replaced//~v453I~
//  	Pnlen++;                                                   //~v49cR~
    	Pnlen+=(len-pos2);                                         //~v49cI~
//  filesetdbcstbl(Ppdata,Ppdbcs,Pnlen);                           //~v44aR~
    filesetdbcstbl(Ppdata,Ppdbcs,Pnlen,0);//ignore tab,fcmd process later//~v44aR~
    return;                                                        //~v21nM~
}//filerepwordsetdbcstbl                                           //~v21nM~
//*************************************************************    //~v50eI~
//*get max record size split and cont (may before tab expand)      //~v50eR~
//*ret :rc                                                         //~v50eI~
//*************************************************************    //~v50eI~
int fsubgetmaxlen(int Popt,PUFILEH Ppfh,int *Ppmaxlen,int *Ppmaxcont)//~v50eR~
{                                                                  //~v50eI~
	PULINEH plh;                                                   //~v50eI~
    int maxlen=0,maxcont=0,len,contlen=0;                          //~v50tR~
//***********************                                          //~v50eI~
  if (Ppfh->UFHmaxlrecl)	//already calc and not updated after   //~v54RI~
  {	                                                               //~v54RI~
  	maxlen=Ppfh->UFHmaxlinewidth;	//line width                   //~v54RI~
  	maxcont=Ppfh->UFHmaxlrecl;		//contline summed length       //~v54RI~
  }                                                                //~v54RI~
  else	                                                           //~v54RI~
  {                                                                //~v54RI~
	for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~v50eI~
    {                                                              //~v50eI~
        if (plh->ULHtype!=ULHTDATA)                                //~v50eI~
            continue;                                              //~v50eI~
        if (Popt & FSGML_TABEXP)                                   //~v50eI~
	        if (!plh->ULHdbcs)  //not once displayed               //~v50eI~
	            if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v50eI~
                	return UALLOC_FAILED;                          //~v50eI~
        len=plh->ULHlen;                                           //~v50eI~
        if (maxlen<len)                                            //~v50eI~
            maxlen=len;                                            //~v50eI~
        if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT2))	//2nd line     //~v50eR~
        	contlen+=len;                                          //~v50eI~
        else                                                       //~v50eI~
        	contlen=len;                                           //~v50eR~
        if (maxcont<contlen)                                       //~v50eR~
        	maxcont=contlen;                                       //~v50eI~
    }                                                              //~v50eI~
  	Ppfh->UFHmaxlinewidth=(USHORT)maxlen;	//line width           //~v54RR~
  	Ppfh->UFHmaxlrecl=(USHORT)maxcont;		//contline summed length//~v54RR~
  }//calc chk                                                      //~v54RI~
  if (Ppmaxcont)                                                   //~v54RI~
    *Ppmaxcont=maxcont;                                            //~v50eR~
  if (Ppmaxlen)                                                    //~v54RI~
    *Ppmaxlen=maxlen;                                              //~v50eI~
    return 0;                                                      //~v50eI~
}//fsubgetmaxlen                                                   //~v50eI~
//**************************************************************** //~v54RI~
//* file update chk at save                                        //~v54RI~
//* retrn:rc UALLOC_FAILED or 4                                    //~v54RI~
//**************************************************************** //~v54RI~
int xefsubupdatechk(PUCLIENTWE Ppcw,PUFILEH Ppfh)                  //~v54RI~
{                                                                  //~v54RI~
	FILEFINDBUF3 fstat3;                                           //~v54RI~
	char tfnm[_MAX_PATH];                                          //~v54RR~
    int rc;                                                        //~v54RR~
#ifdef FTPSUPP                                                     //~v70zI~
	PUFTPHOST puftph;                                              //~v70zI~
#endif                                                             //~v70zI~
//*****************                                                //~v54RI~
#ifdef FTPSUPP                                                     //~v70zI~
  if (!UCBITCHK(Ppfh->UFHflag6,UFHF6RLOGIN))                       //~v72BI~
  {                                                                //~v72BI~
    puftph=Ppfh->UFHpuftph;                                        //~v70zI~
    if (UFTPHISTSO(puftph))   //host is tso                        //~v70zR~
    	return xetsoupdatechk(Ppcw,Ppfh);                          //~v70zR~
  }                                                                //~v72BI~
#endif                                                             //~v70zI~
	strcpy(tfnm,Ppfh->UFHfilename);                                //~v54RI~
    rc=(int)ufstat(tfnm,&fstat3);                                  //~v54RR~
    if (rc)                                                        //~v54RI~
    {                                                              //~v54RI~
        if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))                       //~v54RI~
            rc=0;//ok if not exist                                 //~v54RI~
    }                                                              //~v54RI~
    else    //found                                                //~v54RI~
    {                                                              //~v54RI~
        if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))                       //~v54RI~
            rc=1;//someone saved                                   //~v54RI~
        else                                                       //~v54RI~
#ifdef FTPSUPP                                                     //~v54RI~
        if (*fstat3.slink)                                         //~v54RI~
            rc=memcmp(&(fstat3.slinkfdate),&(Ppfh->UFHfiledate),sizeof(FDATE))//~v54RI~
              |memcmp(&(fstat3.slinkftime),&(Ppfh->UFHfiletime),sizeof(FTIME));//~v54RI~
        else                                                       //~v54RI~
#endif                                                             //~v54RI~
            rc=memcmp(&(fstat3.fdateLastWrite),&(Ppfh->UFHfiledate),sizeof(FDATE))//~v54RI~
              |memcmp(&(fstat3.ftimeLastWrite),&(Ppfh->UFHfiletime),sizeof(FTIME));//~v54RI~
    }                                                              //~v54RI~
    if (rc)                                                        //~v54RI~
    {                                                              //~v54RI~
        uerrmsg("%s is changed",0,                                 //~v54RI~
                tfnm);                                             //~v54RI~
        return 8;                                                  //~v54RI~
    }                                                              //~v54RI~
    return 0;                                                      //~v54RI~
}//xefsubupdatechk                                                 //~v54RR~
#ifdef UNX                                                         //~v55PI~
//**************************************************************** //~v55PI~
//* file write permission chk                                      //~v55PI~
//* retrn:rc 0:ok,4:permission err,8:new create permission err,1:remote/err is not chked//~v57mR~
//**************************************************************** //~v55PI~
int xefsubwritepermissionchk(PUFILEH Ppfh)                         //~v55PI~
{                                                                  //~v55PI~
	uid_t uid;                                                     //~v55PI~
	gid_t gid;                                                     //~v55PI~
	uid_t fuid;                                                    //~v57mI~
	gid_t fgid;                                                    //~v57mI~
//  int mode,rc;                                                   //~vb06R~
    ULONG mode;                                                    //~vb06I~
    int rc;                                                        //~vb06I~
    char fpath[_MAX_PATH];                                         //~v57mI~
	FILEFINDBUF3 ffb3;                                             //~v57mI~
    int newsw;                                                     //~v57mI~
//*****************                                                //~v55PI~
    if (FILEISREMOTE(Ppfh))                                        //~v55PI~
        return 1;                                                  //~v55PI~
	if (UCBITCHK(Ppfh->UFHflag5,UFHF5MDOS))//original is mdos disk //~v76yI~
        return 0;                                                  //~v76yI~
    ugetugid(&uid,&gid);                                           //~v55PI~
  if (UCBITCHK(Ppfh->UFHflag,UFHFNEW))                             //~v57mR~
  {                                                                //~v57mR~
    	newsw=1;                                                   //~v57mI~
        strcpy(fpath,Ppfh->UFHfilename);                           //~v57mI~
    	rc=ufilegetpathdir(fpath,fpath);                           //~v57mR~
        if (rc>1)                                                  //~v57mI~
        	return 1;	//not chked                                //~v57mI~
        if (rc==1)//root                                           //~v57mI~
        {                                                          //~v57mI~
            mode=ROOT_MODE;                                        //~v57mI~
            fuid=ROOT_UID;                                         //~v57mI~
            fgid=ROOT_GID;                                         //~v57mI~
        }                                                          //~v57mI~
        else                                                       //~v57mI~
        {                                                          //~v57mI~
            ufstat(fpath,&ffb3);                                   //~v57mR~
            if (FILEISSLINK(ffb3.attrFile))                        //~v57mR~
            {                                                      //~v57mR~
                mode=FILE_GETMODE(ffb3.srcattr);                   //~v57mR~
                fuid=ffb3.slinkuid;                                //~v57mR~
                fgid=ffb3.slinkgid;                                //~v57mR~
            }                                                      //~v57mR~
            else                                                   //~v57mR~
            {                                                      //~v57mR~
                mode=FILE_GETMODE(ffb3.attrFile);                  //~v57mR~
                fuid=ffb3.uid;                                     //~v57mR~
                fgid=ffb3.gid;                                     //~v57mR~
            }                                                      //~v57mR~
        }                                                          //~v57mI~
  }                                                                //~v57mR~
  else                                                             //~v57mR~
  {                                                                //~v57mR~
    	newsw=0;                                                   //~v57mI~
    if (FILEISSLINK(Ppfh->UFHattr))                                //~v55PI~
    	mode=FILE_GETMODE(Ppfh->UFHsrcattr);                       //~v55PI~
    else                                                           //~v55PI~
	    mode=FILE_GETMODE(Ppfh->UFHattr);                          //~v55PR~
    fuid=Ppfh->UFHuid;                                             //~v57mI~
    fgid=Ppfh->UFHgid;                                             //~v57mI~
  }                                                                //~v57mR~
    if (!uid)	//root user                                        //~v55PI~
    	return 0;                                                  //~v55PI~
  if (newsw)                                                       //~v57mI~
    rc=8;                                                          //~v57mI~
  else                                                             //~v57mI~
    rc=4;	//no permission                                        //~v55PI~
//  if (uid==Ppfh->UFHuid)	//owner                                //~v57mR~
#ifdef ARM                                                         //~vag1I~
    if (mode & S_IWGRP                                             //~vag1I~
    &   UCBITCHK(Ppfh->UFHflag9,UFHF9SDCARD))                      //~vag1R~
        rc=0;                                                      //~vag1I~
    else                                                           //~vag1I~
#endif                                                             //~vag1I~
    if (uid==fuid)	//owner                                        //~v57mI~
    {                                                              //~v55PI~
      if (!newsw || (mode & S_IXUSR))                              //~v57mI~
    	if (mode & S_IWUSR)                                        //~v55PI~
        	rc=0;                                                  //~v55PI~
    }                                                              //~v55PI~
    else                                                           //~v55PI~
//  if (gid==Ppfh->UFHgid)	//owner group                          //~v57mR~
    if (gid==fgid)	//owner group                                  //~v57mI~
    {                                                              //~v55PI~
      if (!newsw || (mode & S_IXGRP))                              //~v57mI~
    	if (mode & S_IWGRP)                                        //~v55PI~
        	rc=0;                                                  //~v55PI~
    }                                                              //~v55PI~
    else                                                           //~v55PI~
    {                                                              //~v55PI~
      if (!newsw || (mode & S_IXOTH))                              //~v57mI~
    	if (mode & S_IWOTH)                                        //~v55PI~
        	rc=0;                                                  //~v55PI~
    }                                                              //~v55PI~
    return rc;                                                     //~v55PI~
}//xefsubwritepermissionchk                                        //~v55PI~
#else                                                              //~v55XI~
//**************************************************************** //~v55XI~
//* file write permission chk                                      //~v55XI~
//* retrn:rc 0:ok,4:permission err,1:remote is not chked           //~v55XI~
//**************************************************************** //~v55XI~
int xefsubwritepermissionchk(PUFILEH Ppfh)                         //~v55XI~
{                                                                  //~v55XI~
//*****************                                                //~v55XI~
    if (FILEISREMOTE(Ppfh))                                        //~v55XI~
        return 1;                                                  //~v55XI~
    if (Ppfh->UFHattr & FILE_READONLY)                             //~v55XI~
    	return 4;                                                  //~v55XI~
    return 0;                                                      //~v55XI~
}//xefsubwritepermissionchk                                        //~v55XI~
#endif                                                             //~v55PI~
//**************************************************************** //~v66fI~
//* reset UFcsrplh for deleted plh                                 //~v66fI~
//* rc:1:reset done, 0:deleted plh is not on the UFCcsrplh,-1:err(plh is dequed)//~v66fI~
//**************************************************************** //~v66fI~
int xefsubresetcsrplh(PUCLIENTWE Ppcw,PULINEH Pplh)                //~v66fI~
{                                                                  //~v66fI~
	PUFILEH pfh;                                                   //~v66fI~
    int rc;                                                        //~v66fI~
//*****************                                                //~v66fI~
	if (Ppcw)                                                      //~v66fI~
		rc=xefsubresetcsrplhsub(Ppcw,Pplh);                        //~v66fI~
    else                                                           //~v66fI~
    {                                                              //~v66fI~
    	pfh=UGETPFH(Pplh);                                         //~v66fR~
        if (!pfh)                                                  //~v66fI~
        	return -1;	//plh dequed                               //~v66fI~
		rc=xefsubresetcsrplhsub(pfh->UFHeditpcw,Pplh);             //~v66fI~
		rc|=xefsubresetcsrplhsub(pfh->UFHbrowsepcw[0],Pplh);       //~v66fI~
		rc|=xefsubresetcsrplhsub(pfh->UFHbrowsepcw[1],Pplh);       //~v66fI~
    }                                                              //~v66fI~
    return rc;                                                     //~v66fI~
}//xefsubresetcsrplh                                               //~v66fI~
//**************************************************************** //~v66fI~
//**************************************************************** //~v66fI~
int xefsubresetcsrplhsub(PUCLIENTWE Ppcw,PULINEH Pplh)             //~v66fI~
{                                                                  //~v66fI~
	PUFILEC pfc;                                                   //~v66fI~
//*****************                                                //~v66fI~
	if (Ppcw)                                                      //~v66fI~
    {                                                              //~v66fI~
        pfc=Ppcw->UCWpfc;                                          //~v66fI~
        if (pfc->UFCcsrplh==Pplh)                                  //~v66fI~
        {                                                          //~v66fI~
            pfc->UFCcsrplh=0;                                      //~v66fI~
            return 1;                                              //~v66fI~
        }                                                          //~v66fI~
    }                                                              //~v66fI~
    return 0;                                                      //~v66fI~
}//xefsubresetcsrplhsub                                            //~v66fI~
//*************************************************************    //~va7LI~
//*reset ebcdic dbcstbl from EBC cmd and undo                      //~va7LI~
//*************************************************************    //~va7LI~
int fsubresetebcdbcstbl(int Popt,int Poldhandle,PUCLIENTWE Ppcw,PUFILEH Ppfh)//~va7LI~
{                                                                  //~va7LI~
	PULINEH plh;                                                   //~va7LI~
    int b2bopt,newhandle,len;                                      //~va7LR~
//***********************                                          //~va7LI~
	newhandle=Ppfh->UFHhandle;                                     //~va7LI~
    b2bopt=FSDT_B2B;                                               //~va7LI~
	if (UCVEBCH_HANDLE_ISDBCSCV(newhandle))                        //~va7LI~
    	b2bopt|=FSDT_TGTDBCS;                                      //~va7LI~
	if (UCVEBCH_HANDLE_ISDBCSCV(Poldhandle))                       //~va7LI~
    	b2bopt|=FSDT_SRCDBCS;    //for filesetdbcstblplh_handle    //~va7LI~
    if (!(b2bopt & (FSDT_TGTDBCS|FSDT_SRCDBCS)))	//both sbcs    //~va7LR~
    	return 0;                                                  //~va7LI~
	for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~va7LI~
    {                                                              //~va7LI~
        if (plh->ULHtype!=ULHTDATA)                                //~va7LI~
            continue;                                              //~va7LI~
	    if (!plh->ULHdbcs)  //not once displayed                   //~va7LI~
        	continue;                                              //~va7LI~
        len=plh->ULHlen;                                           //~va7LI~
		filesetdbcstblplh_handle(b2bopt,newhandle,Ppfh,plh,0/*pos*/,len);//~va7LI~
    }                                                              //~va7LI~
    return 0;                                                      //~va7LI~
}//fsubresetebcdbcstbl                                             //~va7LI~
//********************************************************************//~vb06I~
#ifdef W32                                                         //~vb06I~
int ufilesetfhfilename_reservedname(int Popt,PUFILEH Ppfh,char *Pfpath)//~vb06I~
{                                                                  //~vb06I~
	int rc;                                                        //~vb06R~
//*********************                                            //~vb06I~
  	if (IS_RESERVED_NAME(Pfpath))                                  //~vb06I~
  	{                                                              //~vb06I~
    	UCBITON(Ppfh->UFHflag13,UFHF13RESERVEDNAME);               //~vb06I~
  		ustrncpyz(Ppfh->UFHfilename,Pfpath+RESERVED_NAMEID_CTR,sizeof(Ppfh->UFHfilename));//~vb06I~
        rc=1;                                                      //~vb06I~
  	}                                                              //~vb06I~
    else                                                           //~vb06I~
    {                                                              //~vb06I~
	    UCBITOFF(Ppfh->UFHflag13,UFHF13RESERVEDNAME);              //~vb06I~
  		ustrncpyz(Ppfh->UFHfilename,Pfpath,sizeof(Ppfh->UFHfilename));//~vb06I~
        rc=0;                                                      //~vb06I~
    }                                                              //~vb06I~
    return rc;                                                     //~vb06I~
}//ufilesetfhfilename_reservedname                                 //~vb06I~
#endif                                                             //~vb06I~
