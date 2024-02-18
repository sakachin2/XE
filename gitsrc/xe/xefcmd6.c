//*CID://+vc61R~:                             update#=  871;       //+vc61R~
//*************************************************************    
//*xefcmd6.c*                                                      //~v78rR~
//**file cmd:PROfile                                               //~v78rI~
//**file cmd:ASSociate                                             //~v78rI~
//**file cmd:Rotate  ROT { R | L | X | Y | RX | LX | RJ | LJ } [NX] [TAIL] [n-m] [.lab1 .lab2]//~v511R~
//** NX: x,y,rj,lj only                                            //~v511R~
//*************************************************************    
//vc61 2023/08/04 (Bug) Uri to file path failes when space embedding//+vc61I~
//vbs6:201026 profile COL cmd for dir, "col on dir" follows dir setting//~vbs6I~
//vb7m:170116 profile filename is too long over 255(CreateFile failes with GetLastError()=123(name syntax err)//~vb7mI~
//vb7b:170105 (Bug by vb57)profile record is out of profile dir    //~vb7bI~
//vb79:170104 _MAX_PATH overflowchk for profile record             //~vb79I~
//vb71:161212 Win10 compiler warning                               //~vb71I~
//vb57:160911 (Bug)Invalid name format for profile record when "." is included in UD fmt//~vb57I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vb2C:160221 W32 compiler warning                                 //~vb2CI~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//            ext name may followex by UD_NOTLC                    //~vavaI~
//vajh:130812 (BUG)record mode file;tab was replaced to space like as spf fixlrecl file//~vajhI~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW})         //~vaj0I~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6i:100622 COPY cmd;chk CPxx profile of copy source file        //~va79R~
//va67:100618 (BUG) it was forced margin==lrecl from profile       //~va67I~
//va5U:100526 update profile by edit cmd with P[0|1] option        //~va5UI~
//va5P:100524 (BUG)rot LJ;missing  dbcs split clear at right boundary//~va5PI~
//va5M:100523 (BUG)rot rj cmd did not clear dbcstbl for utf8 file  //~va5MI~
//va51:100415 Record mode file option                              
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va18:091026_rotate rj/lj clears hkdbcserr                        //~va18I~
//va0s:090909_assume CPxx profile from of dir record as not cmd line parm//~va0sR~
//va0r:090909_(BUG)profile record filename is invalid for wildcard(open err msg at write)//~va0rI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8                                  //~va00I~
//v79m:080824 (BUG)profiel pathname miss last "'" at save path profile//~v8@LI~
//v8@L:080701 3270:profile filename for TSO should be uppercase for LINUX//~v8@LI~
//v8@F:080629 3270:NUMSTD consideration when SJIS=>EBC translation(SO/SI insert case)//~v8@FI~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v78L:080506 profile deal with not LFN drive                      //~v78LI~
//v78J:080504 (BUG)profile cmd operand chk error                   //~v78JI~
//v78H:080504 (BUG)profile cmd 3270 path record dsname             //~v78HI~
//v78w:080402*(UTF8)profile function                               //~v78wI~//~va00I~
//v78r:080326 profile function                                     //~v78rI~
//v76H:070906*(BUG)rot lj ignore tail option if len==pos2          //~v76HI~
//v76G:070906*(BUG)rot abend if range specified over max lrecl     //~v76GI~
//v76F:070906*ROT cdm:DBCSAL/DBCSRL:dbcs align Left/Right option for R(X)/L(X) method//~v76FI~
//v76p:070628 compare remote file support                          //~v76pI~
//v652:050712 (BUG)assoc cmd;chk dcmdfullpath fail(may fail for remote file)//~v652I~
//v64v:050708 (LNX)openwith support(! lcmd & ASS cmd)              //~v64vI~
//v564:040328 (WIN)ASSociate command same as ! lcmd                //~v564I~
//v54G:040121 (BUG)abend when curtop xline is deleted.rotate cmd also abend by same reason//~v54GI~
//v52h:030830 DOS linkerr                                          //~v52hR~
//v52d:030821 (BUG)rotate rj generate invalid line.                //~v52dI~
//v511:030302 new rotate cmd                                       
//*************************************************************    
#include <time.h>                                                  
#include <stdio.h>                                                 
#include <stddef.h>                                                
#include <stdlib.h>                                                
#include <ctype.h>                                                 
#include <string.h>                                                
#include <errno.h>                                                 //~v78rI~
                                                                   
#ifdef DOS                                                         
  #ifdef DPMI                 //DPMI version                       //~v78LI~
    #include <unistd.h>       //unlink                             //~v78LI~
  #endif                                                           //~v78LI~
#else                                                              
#endif                                                             
#ifdef W32                                                         //~v78rI~
	#include <io.h>    		//for _A_SUBDIR etc                    //~v78rI~
#endif                                                             //~v78rI~
#ifdef UNX                                                         //~v78rI~
    #include <unistd.h>                                            //~v78rI~
#endif                                                             //~v78rI~
//*******************************************************          
#include <ulib.h>                                                  
#include <uque.h>                                                  
#include <uerr.h>                                                  
#include <uparse.h>                                                
#include <ufile.h>                                                 
#include <ufile2.h>                                                //~v78rI~
#include <ufile4.h>                                                //~v78LI~
#include <ufile5.h>                                                //~vaj0I~
#include <ualloc.h>                                                
#include <uedit.h>                                                 
#include <ustring.h>                                               
#include <uftp.h>                                                  //~v76pI~
#include <ufemsg.h>                                                //~v78rI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include <udbcschk.h>                                              //~vva1cR~//~va1cR~
#include <utrace.h>                                                //~vva1cI~//~va1cR~
#endif                                                             //~va1qI~
#ifdef UTF8SUPPH                                                   //~va20I~
#include <utf22.h>                                                //~vva1cI~//~va20I~
#endif                                                             //~va20I~
#include <ucvext.h>                                                //~vva1cI~//~va79I~
#include <ucvebc.h>                                                //~vva1cI~//~va50I~
#include <ucvebc4.h>                                                //~vva1cI~//~va79I~
#include <ufilew.h>                                                //~vavaI~
                                                                   
#include "xe.h"                                                    
#include "xescr.h"                                                 
#include "xefile.h"                                                
#include "xefile42.h"                                              //~v78rI~
#include "xefile5.h"                                               //~vaj0I~
#include "xefile6.h"                                               
#include "xefcmd.h"                                                
#include "xefcmd22.h"                                              
#include "xefcmd3.h"                                               
#include "xefcmd6.h"                                               
#include "xelcmd.h"                                                
#include "xelcmd2.h"                                               //~v54GI~
#include "xeerr.h"                                                 
#include "xeundo.h"                                                
#include "xesub.h"                                                 
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xesub2.h"                                                //~va18I~
#endif                                                             //~va1qI~
#include "xefsub.h"                                                
#include "xefunc.h"                                                
#include "xepan.h"                                                 //~v564I~
#include "xedir.h"                                                 //~v564I~
#include "xedcmd.h"                                                //~v564R~
#include "xedlcmd.h"                                               //~v564I~
#include "xedlcmd6.h"                                              //~v564I~
#include "xesyn.h"                                                 //~v78rI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xechar12.h"                                              //~va18I~
#endif                                                             //~va1qI~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************          
//**************************************************************** 
#define ROTOPT_RTYPE    0x00ff        //rtype mask                 //~v511R~
#define ROTOPT_RJUST    0x0100        //dbcs found                 //~v511I~
#define ROTOPT_DBCS     0x0200        //dbcs found                 //~v511R~
#define ROTOPT_TAILCUT  0x0400        //tail cut option            //~v511R~
#define ROTOPT_AJRANGE  0x0800        //ajust range parm           //~v511I~
#define ROTOPT_NX       0x1000        //for not excluded only      //~v511R~
#define ROTOPT_REV      0x2000        //for LX                     //~v511R~
#define ROTOPT_DBCSAR   0x4000        //DBCS align right for R(X)/L(X)//~v76FI~
#define ROTOPT_DBCSAL   0x8000        //DBCS align left  for R(X)/L(X)//~v76FI~
#define ROTOPT_CHSZMASK 0x030000      //DBCS szmask                //~vva1cI~//~va1cR~
                                                                   
#define MAXLABEL      2                                            
                                                                   //~v78rI~
#define PROF_SUBDIR  "profile"                                     //~v78rM~
#define PROF_83FNM   "profile.%c"                                  //~v78LR~
#define PROF_DELM    '_'            //path delm                    //~v78rM~
#define PROF_DELM2   '~'            //replace "."                  //~v78rR~
#define PROF_DELM3   '='            //replace " "                  //~v78rR~
//**************************************************************** //~v78rI~
#define PROF_NUMEDIT       "ZZZZZZZZZ9"                            //~v78rM~
#define PROF_NUMFLDSZ      10                                      //~v78rI~
                                                                   //~v78rI~
typedef struct _PROFILE{    //profile record                       //~v78rR~
#define PROF_ON         '1'                                        //~v78rR~
#define PROF_OFF        '0'                                        //~v78rR~
                        char PROFver[2];              //0-1        //~v78rR~
//#define PROF_VERSION    "01"                                       //~v78rR~//~va79R~
#define PROF_VERSION    "02"                                       //~va79I~
#define PROF_VERSION01  "01"                                       //~va79I~
#define PROF_VERSION02  "02"                                       //~va79I~
                        char PROFsynopen;             //2          //~v78rR~
#define PROF_SYNOPEN   'S'                                         //~v78rR~
#define PROF_SYNNOOPEN 's'                                         //~v78rR~
                        char PROFsynenter;            //3          //~v78rR~
#define PROF_SYNENTER   'U'                                        //~v78rR~
#define PROF_SYNENTERA  'A'                                        //~v78rR~
#define PROF_SYNNOENTER 'e'                                        //~v78rI~
                        char PROFsynlang[MAX_SYNTYPE];   //4-10    //~v78rR~
                        char PROFbnds1[PROF_NUMFLDSZ];   //11-20   //~v78rR~
                        char PROFbnds2[PROF_NUMFLDSZ];   //21-30   //~v78rR~
                        char PROFvhex;    //hex cmd;vhex mode  31  //~v78rR~
#define PROF_VHEXON    'X'      //expliitly on                     //~v78rI~
#define PROF_VHEXOFF   'x'      //explicitly off                   //~v78rI~
                        char PROFcols;    //hex cmd;vhex mode 32   //~v78rI~
#define PROF_COLSON    'L'      //expliitly on                     //~v78rI~
#define PROF_COLSOFF   'l'      //explicitly off                   //~v78rI~
#define PROF_COLSDEF   'd'      //default cols                     //~v78rI~
                        char PROFcolstype[MAXCOLSTYPNM]; //cols type 33-39//~v78rI~
                        char PROFcp;    //file codepage   40       //~v78rI~
#define PROF_CPUTF8    'U'       //utf8                            //~v78rR~
#define PROF_CPLOCALE  'L'       //locale                          //~v78rR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
#define PROF_CPEBC     'E'       //ebcdic                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//                      char PROFrsv[22];                          //~v78rI~//~va51R~
                        char PROFrecordmode;         //41          //~va51R~
#define PROF_RECORDMODE 'R'                                        //~va51R~
#define PROF_RECORDMODEV 'V'                                       //~vaj0M~
//                      char PROFrsv[21];            //42-62       //~va51R~//~vaj0R~
                        char PROFvfmt[4];            //42-45       //~vaj0R~
                        char PROFvfmtdelm;           //46          //~vaj0R~
                        char PROFrsv[16];            //47-62       //~vaj0I~
                        char PROFcaps;               //63          //~v78rR~
#define PROF_CAPSON    'C'      //expliitly on                     //~v78rR~
#define PROF_CAPSOFF   'c'      //explicitly off                   //~v78rI~
                        char PROFbyprofcmd[1];  //start of by prof cmd 64//~v78rR~
                        char PROFnumstd;         //65                  //~v78rR~
#define PROF_NUMSTD        'N'                                     //~v78rI~
#define PROF_NONUMSTD      'n'                                     //~v78rI~
                        char PROFoomprot;       //66                   //~v78rR~
#define PROF_OOMPROT       '1'                                     //~v78rR~
#define PROF_OOMNOPROT     '0'                                     //~v78rR~
                        char PROFnumcob;       //67                    //~v78rR~
#define PROF_NUMCOB        'C'                                     //~v78rR~
#define PROF_NUMCOBK       'K'                                     //~v78rR~
#define PROF_NUMNOCOB      'b'                                     //~v78rI~
                        char PROFtabclear;      //68                   //~v78rI~
#define PROF_TABCLEAR      'T'                                     //~v78rI~
#define PROF_NOTABCLEAR    't'                                     //~v78rI~
                                                                   //~v78rI~
                        char PROFlrecl[PROF_NUMFLDSZ];    //69-78         //~v78rR~
#define PROF_FIXLRECL      'F'                                     //~vaj0I~
                        char PROFmargin[PROF_NUMFLDSZ];   //79-88         //~v78rI~
//                      char PROFFrsv2[22];                        //~v8@2R~
                        char PROFtabctr[2];               //89-90         //~v8@2I~
//                      char PROFFrsv2[20];               //91-110         //~v8@2I~//~vagER~
                        char PROFfncp;  //file name codepage   91  //~vagEI~
#define PROF_FNCPUTF8    'U'       //utf8                          //~vagEI~
#define PROF_FNCPLOCALE  'L'       //locale                        //~vagEI~
                        char PROFFrsv2[19];               //92-110 //~vagEI~
#define PROFILESZV1 (offsetof(PROFILE,PROFcvname))                 //~va79I~
#define PROFV2AREA(ppf) ((ppf)->PROFcvname)                        //~va79R~
                        char PROFcvname[MAX_CSNAMESZ];    //111-170(60)//~va79R~
                        } PROFILE,*PPROFILE;                       //~v78rR~
#define PROFILESZ sizeof(PROFILE)                                  //~v78rI~
//#define PROFBYPROFCMDSZ (PROFILESZ-offsetof(PROFILE,PROFbyprofcmd))//~v78rI~//~va79R~
//#define PROF_MAXSZ  (PROFILESZ+2)                                  //~v78rR~//~va79R~
//*for 8.3 filename env profile is recorded all in a file          //~v78LR~
typedef struct _PROFQE{    //profile record                        //~v78LR~
                        UQUEE PRQEqe;                              //~v78LR~
                        int   PRQEnamelen; //offset to delm(\t)    //~v78LR~
                        char  PRQEbuff[1];                         //~v78LR~
                     } PROFQE,*PPROFQE;                            //~v78LR~
#define PROFQESZ sizeof(PROFQE)                                    //~v78LR~
//**************************************************************** //~v511I~
                                                                   //~v511I~
#ifdef DOSDOS                                                      //~v511I~
#else                                                              //~v511I~
//static UCHAR *Swordtbl="R\0L\0X\0Y\0LX\0RX\0RJ\0LJ\0RSV1\0TAIL\0NX\0";//~v76FR~
static UCHAR *Swordtbl="R\0L\0X\0Y\0LX\0RX\0RJ\0LJ\0RSV1\0TAIL\0NX\0DBCSAR\0DBCSAL\0";//~v76FI~
static UCHAR *Srottype;                                            //~v511I~
static long  Sjpos1,Sjpos2;                                        //~v511I~
#endif                                                             //~v511I~
                                                                   //~v511I~
//**************************************************************** 
int fcmdrotateopdchk(PUCLIENTWE Ppcw,UCHAR Pplabt[][ULHLINENOSZ+1],int *Pplabctr,int *Popt);
int fcmdrotatemain(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplhs,PULINEH Pplhe,int Popt);
int fcmdrotaterl(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplhs,PULINEH Pplhe,int Popt,
					UCHAR *Ppwk,int Plinectr,int Pcharctr);        
int fcmdrotatey(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplhs,PULINEH Pplhe,int Popt,UCHAR *Ppwk,int Pmaxlen);//~v511R~
int fcmdrotatex(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplhs,PULINEH Pplhe,int Popt,int Plinectr);//~v511R~
int fcmdajr(int Popt,PULINEH Pplh,char *Ppwk,int Pmaxlen,int *Pplen);//~v511I~
                                                                   //~v78rI~
int fcmdprofhelp(PUCLIENTWE Ppcw);                                 //~v78rI~
int fcmdprofcurstat(PUFILEH Ppfh,char *Pbuff);                     //~v78rI~
int fcmdprofshowstat(PUCLIENTWE Ppcw,PUFILEH Ppfh);                //~v78rR~
int fcmdprofstat(PUFILEH Ppfh,char *Pbuff);                        //~v78rI~
int fcmdprofinitrecord(PPROFILE Ppprof);                           //~v78rI~
//int fcmdprofgetprofilerecord(PUFILEH Ppfh,PPROFILE Ppprof);        //~v78rI~//~va0sR~
int fcmdprofgetprofilerecord(PUFILEH Ppfh,PPROFILE Ppprof,PPROFILE Ppproffile);//~va0sI~
int fcmdprofreadrecord(int Popt,char *Pfnm,PPROFILE Ppprofile);    //~v78rR~
#define FCPRRO_MSG      0x01      //errmsg issue                   //~v78rI~
#define FCPRRO_DEL      0x10      //errmsg issue                   //~v78LR~
#define FCPRRO_GET      0x20      //errmsg issue                   //~v78LR~
#define FCPRRO_PUT      0x40      //errmsg issue                   //~v78LR~
int fcmdprofgetfnm(int Popt,char *Pinpfnm,char *Poutfnm,char *Poutdirextfnm,char *Poutextfnm,int *Pppathlen);//~v78rI~
#define FCPRRO_TSO      0x01      //tso file                       //~v78HI~
#define FCPRRO_WRITE    0x02      //write profile record           //~va0rI~
int fcmdprofmergerecord(PPROFILE Ppprof1,PPROFILE Ppprofile2);     //~v78rI~
int fcmdprofshowrecord(char *Ptype,PPROFILE Ppprof);               //~v78rI~
int fcmdprofwriterecord(char *Pfnm,PPROFILE Ppprof);               //~v78rR~
int fcmdprofupdaterecordcmd(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PPROFILE Ppprof,char *Popd,int Popdno);//~v78rR~
int fcmdprof83wd(void);                                            //~v78LR~
int fcmdprof83io(int Popt,char *Pfnm,PPROFILE Ppprofile);          //~v78LR~
PPROFQE fcmdprof83q(int Popt,char *Pbuff,int Plen);                //~v78LR~
int fcmdprof83ioread(int Popt,char *Pfnm);                         //~v78LI~
PPROFQE fcmdprof83iosrch(int Popt,char *Pprofname,int Pprofnamelen);//~v78LI~
int fcmdprofgetfnmShort(int Popt,char *Pinpfnm,char *Poutfnm,char *Poutpdirfnm,int *Pppathlen,int Pposfnm);//~vb7mI~
//**************************************************************** 
// sort on optional label range                                    
//*rc   :0                                                         
//**************************************************************** 
int func_rotate(PUCLIENTWE Ppcw)                                   
{                                                                  
#ifdef DOSDOS                                                      
    return errnotsupported("ROTate","DOS version");                
#else                                                              
	UCHAR labt[MAXLABEL][ULHLINENOSZ+1];//label opd from/to        
    PUFILEH pfh;                                                   
    PULINEH plhs,plhe;                                             
    PUFILEC pfc;                                                   
    int rc,labctr,opt;                                             
//*********************************                                
	if (!Ppcw->UCWparm)		//operand                              
    {                                                              
//      uerrmsg("ROT { R | L | X | Y | RX | LX | RJ | LJ } [NX] [TAIL] [n-m] [.lab1 .lab2]",0);//~v76FR~
        uerrmsg("ROT { R | L | X | Y | RX | LX | RJ | LJ } [DBCSAR | DBCSAL] [NX] [TAIL] [n-m] [.lab1 .lab2]",0);//~v76FI~
        return 0;                                                  
    }                                                              
	pfc=Ppcw->UCWpfc;                                              
    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                         
		return errbrowsemode();                                    
	pfh=pfc->UFCpfh;                                               
    if (pfh->UFHtype==UFHTKFI)	//menu opt file                    
    	return 4;                                                  
	memset(labt,0,sizeof(labt));		//for null term            
	if (fcmdrotateopdchk(Ppcw,labt,&labctr,&opt))                  
    	return 4;                                                  
	if (rc=fcmdgetabrange(Ppcw,pfh,labt,labctr,&plhs,&plhe,1),rc) //1:plh2 is next plh
    	return rc;	//may 1:no bell                                
	rc=fcmdrotatemain(Ppcw,pfh,plhs,plhe,opt);                     
    return rc;                                                     
#endif                                                             
}//func_rotate                                                     //~v511R~
#ifdef DOSDOS                                                      
#else                                                              
//**************************************************************** 
//!fcmdrotateopdchk                                                
//  SORT n-m[/[r][c][i] ... (max5) [.lab1 .lab2]                   
//* parm1 :pcw                                                     
//* parm2 :label output                                            
//* parm3 :key range output                                        
//* parm4 :label ctr                                               
//* parm5 :key ctr                                                 
//* return:rc                                                      
//**************************************************************** 
int fcmdrotateopdchk(PUCLIENTWE Ppcw,UCHAR Pplabt[][ULHLINENOSZ+1],int *Pplabctr,int *Ppopt)
{                                                                  
    char *pc,*plabt;                                               
    int labctr=0,ropt=0,rtype=0,opdno,ii,opid,rc;                  //~v511R~
//*********************************                                
    opdno=Ppcw->UCWopdno;           //funccmd created already      
    pc=Ppcw->UCWopdpot;                                            
    plabt=&Pplabt[0][0];                                           
	for (ii=0;ii<opdno;ii++,pc=pc+strlen(pc)+1)   //next opd addr  
    {                                                              
        if (*pc==ULCCMDLABEL)  //lebel specified                   
        {                                                          
            if (labctr==MAXLABEL)                                  
                return fcmdlabelerr("Too many");                   
            strncpy(plabt,pc,ULHLINENOSZ);                         
            plabt+=ULHLINENOSZ+1;                                  
            labctr++;                                              
            continue;                                              
		}                                                          
        if (*pc>='0' && *pc<='9')                                  //~v511I~
        {                                                          //~v511I~
			rc=ugetnumrange(pc,&Sjpos1,&Sjpos2);                   //~v511R~
			if (rc!=1 || Sjpos1>=Sjpos2)                           //~v511R~
    	    	return errinvalid(pc);                             //~v511I~
            Sjpos1--;                                              //~v511I~
			ropt|=ROTOPT_AJRANGE;                                  //~v511I~
            continue;                                              //~v511I~
        }                                                          //~v511I~
 		switch(opid=wordtblisrch(pc,Swordtbl),opid)                
        {                                                          
        case 0:	//err                                              
        	return errinvalid(pc);                                 
        case 1: //R                                                
        case 2: //L                                                
        case 3: //X                                                //~v511R~
        case 4: //Y                                                //~v511R~
            Srottype=pc;                                           //~v511I~
            rtype=opid;                                            
            break;                                                 
        case 5: //LX                                               //~v511I~
            Srottype=pc;                                           //~v511I~
            rtype=2;    //left                                     //~v511I~
            ropt|=ROTOPT_REV;                                      //~v511I~
            break;                                                 //~v511I~
        case 6: //RX                                               //~v511I~
            Srottype=pc;                                           //~v511I~
            rtype=1;    //left                                     //~v511I~
            ropt|=ROTOPT_REV;                                      //~v511I~
            break;                                                 //~v511I~
        case 7: //RJ                                               //~v511R~
            Srottype=pc;                                           //~v511I~
            ropt|=ROTOPT_RJUST;                                    //~v511I~
            rtype=5;                                               //~v511I~
            break;                                                 
        case 8: //LJ                                               //~v511R~
            Srottype=pc;                                           //~v511I~
            ropt&=~ROTOPT_RJUST;                                   //~v511I~
            rtype=5;                                               //~v511I~
            break;                                                 
        case 9: //????                                             //~v511R~
        	return errinvalid(pc);                                 //~v511I~
        case 10: //TAILCUT                                         //~v511R~
            ropt|=ROTOPT_TAILCUT;                                  //~v511I~
            break;                                                 //~v511I~
        case 11: //NX                                              //~v511R~
            ropt|=ROTOPT_NX;  //not excluded only                  //~v511R~
            break;                                                 //~v511I~
        case 12: //DBCSAR                                          //~v76FM~
            ropt|=ROTOPT_DBCSAR;  //dbcs align right               //~v76FM~
            break;                                                 //~v76FI~
        case 13: //DBCSAL                                          //~v76FI~
            ropt|=ROTOPT_DBCSAL;  //dbcs align left                //~v76FI~
            break;                                                 //~v76FI~
        }                                                          
	}//opdno loop                                                  
    if (labctr && (labctr!=MAXLABEL))                              
        return fcmdlabelerr("label count=0 or 2");                 
    if (!rtype)                                                    
    {                                                              
        uerrmsg("No rotation type option",                         
                "回転タイプ指定なし");                             
		return 4;                                                  
    }                                                              
    if (ropt & ROTOPT_NX)  //not excluded only                     //~v511I~
    	if (rtype<=2)                                              //~v511I~
        	return errconflict("NX",0);                            //~v511I~
    if (ropt & ROTOPT_AJRANGE)  //not excluded only                //~v511I~
    	if (rtype!=5)                                              //~v511I~
        	return errconflict("colomn-range",0);                  //~v511I~
	*Ppopt=rtype|ropt;                                             
	*Pplabctr=labctr;                                              
    return 0;                                                      
}//fcmdrotateopdchk                                                
#endif                                                             //~v52hR~
//**************************************************************** 
//!fcmdgetabrange                                                  
//* get line range from label                                      
//*parm1 :pcw                                                      
//*parm2 :pfh                                                      
//*parm3 :labt                                                     
//*parm4 :labtctr(!=0)                                             
//*parm5 :output strat plh                                         
//*parm6 :output end plh                                           
//*parm7 :opt for fcmdgetlabelrange                                
//*rc   :0:ok,1:lab not found 2nd time,4:notfound 1st time or label err
//**************************************************************** 
int fcmdgetabrange(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Pplabt[][ULHLINENOSZ+1],
						int Plabctr,PULINEH *Ppplhs,PULINEH *Ppplhe,int Popt)
{                                                                  
    PULINEH plht[MAXLABEL],plh1,plh2;                              
    int rc;                                                        
//***************                                                  
    rc=fcmdgetlabelrange(Ppfh,Plabctr,Pplabt,plht,Popt);//not drop cmd
	if (!Plabctr)                                                  
    {                                                              
        plh1=UGETQTOP(&Ppfh->UFHlineque);//search from first       
        plh2=UGETQEND(&Ppfh->UFHlineque);//search from first       
    }                                                              
    else                                                           
    {                                                              
            plh1=plht[0];                                          
            plh2=plht[1];                                          
    }                                                              
    *Ppplhs=plh1;                                                  
    *Ppplhe=plh2;                                                  
	if (rc==2)		//2 for no bell by fcmdgetlabelrange           
    	rc=1;                                                      
    return rc;       //has label                                   
}//fcmdgetabrange                                                  
#ifdef DOSDOS                                                      //~v52hR~
#else                                                              //~v52hR~
//**************************************************************** 
// rotate line                                                     
//*parm1 :pcw                                                      
//*parm2 :pfh                                                      
//*parm3 :start plh                                                
//*parm4 :end   plh                                                
//*parm5 :option                                                   
//*return:rc                                                       
//**************************************************************** 
int fcmdrotatemain(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplhs,PULINEH Pplhe,int Popt)
{                                                                  
	PULINEH plh;                                                   //~v511R~
    int linectr=0,maxchar,dbcssw=0,sbcssw=0,maxlen;                //~v511R~
    int rc=0,rtype,opt,len,ii,nxsw,djwklen;                          //~v511R~//~vaf9R~
    UCHAR *pwk,*pdbcs;                                             //~v511R~
    int dbcsasw;                                                   //~v76FI~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~
    int chsz,chszmax=1;                                            //~vva1cR~//~va1cR~
#endif                                                             //~vva1cI~//~va1cR~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1qI~
    int dbcsid;                                                    //~va1qI~
#endif                                                             //~vva1cI~//~va1qI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	rtype=Popt & ROTOPT_RTYPE;                                     
	nxsw=(Popt & ROTOPT_NX);                                       //~v511I~
//count line                                                       
	plh=Pplhs;                                                     
    dbcsasw=Popt & (ROTOPT_DBCSAR|ROTOPT_DBCSAL);//dbcs align req  //~v76FR~
    for (maxlen=0,plh=Pplhs;plh && plh!=Pplhe;plh=UGETQNEXT(plh))  //~v511R~
	{                                                              
        if (plh->ULHtype!=ULHTDATA)                                
        	continue;                                              
		if (nxsw                                                   //~v511I~
		&&  UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))                 //~v511I~
        	continue;                                              //~v511I~
        if (!plh->ULHdbcs)  //not once displayed                   
            if ((rc=filechktabdbcs(plh))==UALLOC_FAILED)//expand data len
                return UALLOC_FAILED;                              
        if (UCBITCHK(plh->ULHflag2,ULHF2SPLIT1|ULHF2SPLIT2))       
        {                                                          
            uerrmsg("Cannot rotate file with split line",          
                    "分割行のあるファイルは回転できません");       
            return 4;                                              
        }                                                          
        len=plh->ULHlen;                                           
        if (rtype<=2)	//rot r/l                                  
        {                                                          
            pdbcs=plh->ULHdbcs;                                    //~v511I~
#ifdef UTF8SUPPH                                                   //~vva1cR~//~va1cR~
            for (ii=0,maxchar=0,chsz=1;ii<len;ii++,pdbcs++)        //~vva1cR~//~va1cR~
            {                                                      //~vva1cI~//~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
                dbcsid=*pdbcs;                                     //~va20R~
                if (UDBCSCHK_DBCS2NDLU(dbcsid)) //locale and ucs   //~va20R~
#else                                                              //~va20R~
                if (*pdbcs==UDBCSCHK_DBCS2ND)                      //~vva1cI~//~va1cR~
#endif                                                             //~va20R~
                {                                                  //~vva1cI~//~va1cR~
                	chsz++;                                        //~vva1cR~//~va1cR~
                	chszmax=max(chszmax,chsz);                     //~vva1cI~//~va1cR~
                }                                                  //~vva1cI~//~va1cR~
                else                                               //~vva1cI~//~va1cR~
                if (*pdbcs==UDBCSCHK_DBCSPAD)                      //~vva1cI~//~va1cR~
                {                                                  //~vva1cI~//~va1cR~
                	chsz++;                                        //~vva1cI~//~va1cR~
                }                                                  //~vva1cI~//~va1cR~
                else                                               //~vva1cI~//~va1cR~
                {                                                  //~vva1cI~//~va1cR~
                    chsz=1;                                        //~vva1cI~//~va1cR~
                    maxchar++;                                     //~vva1cI~//~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
                    if (UDBCSCHK_DBCS1STLU(dbcsid)) //locale and ucs//~va20R~
#else                                                              //~va20R~
                    if (*pdbcs==DBCS1STCHAR)                       //~vva1cI~//~va1cR~
#endif                                                             //~va20R~
                        dbcssw=1;                                  //~vva1cI~//~va1cR~
                    else                                           //~vva1cI~//~va1cR~
                        sbcssw=1;                                  //~vva1cI~//~va1cR~
                }                                                  //~vva1cI~//~va1cR~
            }    	                                               //~vva1cI~//~va1cR~
UTRACEP("fcmdrotatemain chszmax=%d\n",chszmax);                    //~vva1cR~//~va1cR~
#else                                                              //~vva1cI~//~va1cR~
            for (ii=0,maxchar=0;ii<len;ii++,pdbcs++,maxchar++)     //~v511R~
                if (*pdbcs==DBCS1STCHAR)                           
                {                                                  
                    dbcssw=1;                                      
                    ii++;                                          
                    pdbcs++;                                       //~v511I~
                }                                                  
                else                                               //~v511I~
                if (*pdbcs!=DBCS2NDCHAR)                           //~v511I~
                    sbcssw=1;                                      //~v511I~
#endif                                                             //~vva1cI~//~va1cR~
        }                                                          
        else                                                       
        	maxchar=len;                                           
        if (maxlen<maxchar)                                        
            maxlen=maxchar;                                        
        linectr++;                                                 
	}//                                                            
    opt=Popt;                                                      
    if (rtype<=2)	//R or L                                       
    {                                                              
    	if (dbcssw)                                                
        {                                                          
            opt|=ROTOPT_DBCS;                                      
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~
            opt|=((chszmax-1)<<16)&ROTOPT_CHSZMASK;    //1(dbcs),2(ss3),3(gb4)//~vva1cR~//~va1cR~
			len=linectr*chszmax*maxlen;  //box width=linectr*chsz,height=maxlen//~vva1cR~//~va1cR~
#else                                                              //~vva1cI~//~va1cR~
			len=(linectr+linectr)*maxlen;                          //~v511I~
#endif                                                             //~vva1cI~//~va1cR~
        }                                                          
        else                                                       //~v511I~
			len=linectr*maxlen;                                    //~v511R~
    }                                                              
    else                                                           
    {                                                              //~v76GI~
//  	maxlen=max(maxlen,Sjpos2);                                 //~v76GI~//~vb2ER~
    	maxlen=max(maxlen,(int)Sjpos2);                            //~vb2EI~
    	len=maxlen;                                                
    }                                                              //~v76GI~
    len<<=1;            //pdbcs                                    
//  djwklen=maxlen*sizeof(int);                                    //~v511R~//~vb2DR~
    djwklen=maxlen*(int)sizeof(int);                               //~vb2DI~
	pwk=umalloc((UINT)(len+djwklen));                              //~v511R~
    UALLOCCHK(pwk,UALLOC_FAILED);                                  
UTRACEP("fcmdrotate ,mallocsz=%d\n",len+djwklen);                  //~vva1cI~//~va1cR~
//  len>>=1;                                                       //~v54GR~
    len=(int)((UINT)len>>1);                                       //~v54GI~
                                                                   
    if (rtype<=2)	//R or L                                       
    {                                                              
        memset(pwk,0,(UINT)djwklen);     //data                    //~v511R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	UCVEBC_memset_space(swebcfile,pwk+djwklen,(UINT)len);     //data//~va50I~
#else                                                              //~va50I~
    	memset(pwk+djwklen,' ',(UINT)len);     //data              //~v511R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    	memset(pwk+djwklen+len,0,(UINT)len);   //dbcs              //~v511R~
    }                                                              
    UPCTRREQ(Ppfh);         //write at save                        //~v511M~
    switch(rtype)                                                  
    {                                                              
   	case 1:	//R                                                    
   	case 2:	//L                                                    
    	if (linectr>MAXLINEDATA)                                   //~v511I~
        {                                                          //~v511I~
        	uerrmsg("Too many line(max=%d)",                       //~v511I~
            		"回転は最大 %d 行まで",                        //~v511I~
                    MAXLINEDATA);                                  //~v511I~
            break;                                                 //~v511I~
        }                                                          //~v511I~
		rc=fcmdrotaterl(Ppcw,Ppfh,Pplhs,Pplhe,opt,pwk,linectr,maxlen);
        if (!rc)                                                   //~v511I~
          if (!dbcsasw)                                            //~v76FI~
        	if (dbcssw && sbcssw)                                  //~v511I~
            {                                                      //~v76FI~
//          	uerrmsg("SBCS and DBCS mixed",                     //~v76FR~
//              		"SBCS と DBCS が混合");                    //~v76FR~
            	uerrmsg("Note.SBCS and DBCS mixed(try DBCSAR/DBCSAL option)",//~v76FI~
                		"注。SBCS と DBCS が混合(DBCSAR/DBCSALを試して見て下さい)");//~v76FI~
                rc=1;                                              //~v76FI~
            }                                                      //~v76FI~
        break;                                                     
    case 3:                                                        
		rc=fcmdrotatex(Ppcw,Ppfh,Pplhs,Pplhe,opt,linectr);         //~v511R~
        break;                                                     
    case 4:                                                        
		rc=fcmdrotatey(Ppcw,Ppfh,Pplhs,Pplhe,opt,pwk,maxlen);      //~v511R~
        break;                                                     
    case 5:                                                        //~v511I~
    case 6:                                                        //~v511I~
		rc=fcmdrotatey(Ppcw,Ppfh,Pplhs,Pplhe,opt,pwk,maxlen);      //~v511I~
        break;                                                     //~v511I~
    }                                                              
    UPCTRREQ(Ppfh);         //write at save                        
    ufree(pwk);                                                    
    if (!rc)                                                       //~v511I~
    	uerrmsg("ROT %s Completed",                                //~v511R~
                "ROT %s 完了",                                     //~v511R~
				Srottype);                                         //~v511R~
	return rc;                                                     
}//fcmdrotatemain                                                  
//**************************************************************** 
// rotate right/left                                               
//*parm1 :pcw                                                      
//*parm2 :pfh                                                      
//*parm3 :start plh                                                
//*parm4 :end   plh                                                
//*parm5 :option                                                   
//*parm6 :work                                                     
//*parm7 :rotate range line ctr                                    
//*parm8 :rotate range width(char ctr)                             //~v511R~
//*return:rc                                                       
//**************************************************************** 
int fcmdrotaterl(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplhs,PULINEH Pplhe,int Popt,
					UCHAR *Ppwk,int Plinectr,int Pmaxcol)          //~v511R~
{                                                                  
	PULINEH plh;                                                   
    UCHAR   *pwk,*pdata,*pdbcs,*pc;                                
    int ii,rc=0,rtype,dbcssw,linectr,dbcsoffs,len,isrtctr,offs,tailcutsw;//~v511R~
    int outwidth,revsw,charctr,*pdjwk0,*pdjwk,outrow,lineoffs,bottomupsw;//~v511R~
    int maxwidth,djoffs;                                           //~v511R~
    int dbcsarsw,dbcsalsw,dbcsasw;                                 //~v76FI~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~
    int chszmax,chsz,padlen,nextstep;                              //~vva1cI~//~va1cR~
#endif                                                             //~vva1cI~//~va1cR~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1qI~
    int dbcsid;                                                    //~va1qI~
#endif                                                             //~vva1cI~//~va1qI~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~vva1cI~//~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
#endif                                                             //~vva1cI~//~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	rtype=Popt & ROTOPT_RTYPE;                                     
	dbcssw=(Popt & ROTOPT_DBCS)!=0;                                
    dbcsarsw=dbcssw && (Popt & ROTOPT_DBCSAR);                     //~v76FI~
    dbcsalsw=dbcssw && (Popt & ROTOPT_DBCSAL);                     //~v76FI~
    dbcsasw=dbcsarsw||dbcsalsw;                                    //~v76FI~
	tailcutsw=(Popt & ROTOPT_TAILCUT);                             //~v511I~
	revsw=(Popt & ROTOPT_REV);                                     //~v511I~
    if (rtype==1)       //rotate right                             //~v511I~
        if (revsw)      //RX                                       //~v511I~
            bottomupsw=1;                                          //~v511I~
        else                                                       //~v511I~
            bottomupsw=0;                                          //~v511I~
    else                                                           //~v511I~
        if (revsw)      //LX                                       //~v511I~
            bottomupsw=0;                                          //~v511I~
        else                                                       //~v511I~
            bottomupsw=1;                                          //~v511I~
    pwk=Ppwk;                       //data                         
    pdjwk0=(int*)(void*)pwk;                                       //~v511R~
//  pwk+=Pmaxcol*sizeof(int);                                      //~v511R~//~vb2DR~
    pwk+=Pmaxcol*(int)sizeof(int);                                 //~vb2DI~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~
    chszmax=((Popt & ROTOPT_CHSZMASK)>>16)+1; //1-4;               //~vva1cI~//~va1cR~
    outwidth=(Plinectr*chszmax);                                   //~vva1cI~//~va1cR~
#else                                                              //~vva1cI~//~va1cR~
    outwidth=(Plinectr<<dbcssw);                                   //~v511I~
#endif                                                             //~vva1cI~//~va1cR~
    dbcsoffs=outwidth*Pmaxcol;	//dbcs                             //~v511R~
UTRACEP("fcmdrotaterl chszmax=%d,outwidth=%d,dbcsoffs=%d\n",chszmax,outwidth,dbcsoffs);//~vva1cI~//~va1cR~
    for (linectr=0,plh=Pplhs;plh && plh!=Pplhe;plh=UGETQNEXT(plh)) //~v511R~
    {                                                              //~v511R~
        if (plh->ULHtype!=ULHTDATA)                                //~v511R~
            continue;                                              //~v511R~
        pdata=plh->ULHdata;                                        //~v511R~
        pdbcs=plh->ULHdbcs;                                        //~v511R~
        len=plh->ULHlen;                                           //~v511R~
        for (ii=0,charctr=0;charctr<Pmaxcol;ii++,pdata++,pdbcs++)  //~v511R~
        {                                                          //~v511R~
            if (bottomupsw)                                        //~v511R~
                outrow=Pmaxcol-charctr-1;                          //~v511R~
            else                                                   //~v511R~
                outrow=charctr;                                    //~v511R~
            lineoffs=outrow*outwidth;                              //~v511R~
            pdjwk=pdjwk0+outrow;                                   //~v511R~
            offs=*pdjwk;                                           //~v511I~
            if (rtype==1)       //rj                               //~v511R~
            	offs=outwidth-offs;                                //~v511R~
	   		pc=pwk+lineoffs+offs;                                  //~v511I~
#ifdef UTF8SUPPH                                                   //~vva1cM~//~va1cR~
		  if (chszmax>UDBCSCHK_DBCSSZ)                             //~vva1cI~//~va1cR~
          {                                                        //~vva1cI~//~va1cR~
            if (ii<len)                                            //~vva1cI~//~va1cR~
            {                                                      //~vva1cI~//~va1cR~
                if (dbcssw && *pdbcs==DBCS1STCHAR)                 //~vva1cI~//~va1cR~
                {                                                  //~vva1cI~//~va1cR~
                    chsz=XESUB_DBCSSPLITCTR(pdbcs,len-ii,0);       //~vva1cM~//~va1cR~
                    padlen=chszmax-chsz;                           //~vva1cM~//~va1cR~
                    UTRACEP("chcnt=%d,chsz=%d,padlen=%d\n",ii,chsz,padlen);//~vva1cM~//~va1cR~
                    if (rtype==1)       //rot R:set back from right end//~vva1cM~//~va1cR~
                    	pc-=chszmax;    //output char box start addr//~vva1cM~//~va1cR~
                    if (rtype==1)       //rot R:set back from right end//~vva1cM~//~va1cR~
                    {                                              //~vva1cM~//~va1cR~
                  		if (!dbcsalsw)	//left align               //~vva1cM~//~va1cR~
	                        pc+=padlen;                            //~vva1cM~//~va1cR~
                    }                                              //~vva1cM~//~va1cR~
                    else                //rot L:set from left end  //~vva1cM~//~va1cR~
                    {                                              //~vva1cM~//~va1cR~
                  		if (dbcsarsw)	//right align              //~vva1cM~//~va1cR~
                        	pc+=padlen;       //skip 1 space       //~vva1cM~//~va1cR~
                    }                                              //~vva1cM~//~va1cR~
                    memcpy(pc,pdata,(UINT)chsz);                   //~vva1cM~//~va1cR~
                    memcpy(pc+dbcsoffs,pdbcs,(UINT)chsz);          //~vva1cM~//~va1cR~
                    nextstep=chsz-1;                               //~vva1cM~//~va1cR~
                    pdata+=nextstep;                               //~vva1cM~//~va1cR~
                    pdbcs+=nextstep;                               //~vva1cM~//~va1cR~
                    ii+=nextstep;                                  //~vva1cM~//~va1cR~
                    *pdjwk+=chszmax;//byte count of new output line//~vva1cI~//~va1cR~
                }                                                  //~vva1cI~//~va1cR~
                else	//sbcs                                     //~vva1cI~//~va1cR~
                {                                                  //~vva1cI~//~va1cR~
                  if (dbcsasw)          //2 column for also sbcs   //~vva1cI~//~va1cR~
                  {                                                //~vva1cI~//~va1cR~
                    if (rtype==1)       //rot R:set back from right end//~vva1cM~//~va1cR~
                    {                                              //~vva1cM~//~va1cR~
                  		if (dbcsalsw)	//left align               //~vva1cM~//~va1cR~
                        	pc-=chszmax;                           //~vva1cM~//~va1cR~
                        else                                       //~vva1cM~//~va1cR~
	                        pc--;                                  //~vva1cM~//~va1cR~
                    }                                              //~vva1cM~//~va1cR~
                    else                //rot L:set from left end  //~vva1cM~//~va1cR~
                    {                                              //~vva1cM~//~va1cR~
                  		if (dbcsarsw)	//right align              //~vva1cM~//~va1cR~
                        	pc+=chszmax-1;       //skip 1 space    //~vva1cM~//~va1cR~
                    }                                              //~vva1cM~//~va1cR~
                    *pc=*pdata;                                    //~vva1cM~//~va1cR~
                    *pdjwk+=chszmax;                               //~vva1cM~//~va1cR~
                  }//align                                         //~vva1cI~//~va1cR~
                  else                                             //~vva1cI~//~va1cR~
                  {                                                //~vva1cI~//~va1cR~
                    if (rtype==1)       //rj                       //~vva1cI~//~va1cR~
                        pc--;                                      //~vva1cI~//~va1cR~
                    *pc=*pdata;                                    //~vva1cI~//~va1cR~
                    *pdjwk+=1;                                     //~vva1cI~//~va1cR~
                  }                                                //~vva1cI~//~va1cR~
                }//sbcs                                            //~vva1cI~//~va1cR~
            }//not short line                                      //~vva1cI~//~va1cR~
            else	//short line                                   //~vva1cI~//~va1cR~
            {                                                      //~vva1cI~//~va1cR~
              if (dbcsasw)          //2 column for also sbcs       //~vva1cI~//~va1cR~
                *pdjwk+=chszmax;                                   //~vva1cI~//~va1cR~
              else                                                 //~vva1cI~//~va1cR~
                *pdjwk+=1;                                         //~vva1cI~//~va1cR~
            }                                                      //~vva1cI~//~va1cR~
          }                                                        //~vva1cI~//~va1cR~
          else //dbcssz<=2                                         //~vva1cI~//~va1cR~
#endif                                                             //~vva1cM~//~va1cR~
          {                                                        //~vva1cI~//~va1cR~
            if (ii<len)                                            //~v511R~
            {                                                      //~va20I~
#ifdef UTF8UCS2                                                    //~va20R~
				dbcsid=*pdbcs;                                     //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416     //FIXME test surrogate:FIXED                 //~vaw1R~
                if (dbcssw && UDBCSCHK_DBCS1STU(dbcsid))	//also for ucs4//~va3xI~
#else                                                              //~va3xI~
                if (dbcssw && UDBCSCHK_DBCS1STUCS2NWP(dbcsid))     //~va20R~
#endif                                                             //~va3xI~
                {                                                  //~va20R~
                    if (rtype==1)       //rj                       //~va20R~
                        pc-=2;                                     //~va20R~
                    *pc=*pdata++;                                  //~va20R~
                    pdbcs++;                                       //~va20R~
//                  *((pc++)+dbcsoffs)=dbcsid;                     //~va20R~//~vb2CR~
                    *((pc++)+dbcsoffs)=(UCHAR)dbcsid;              //~vb2CR~
                    *pc=*pdata;                                    //~va20R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
                    *(pc+dbcsoffs)=*pdbcs;                         //~va3xR~
#else                                                              //~va3xI~
                    *(pc+dbcsoffs)=dbcsid+1;                       //~va20R~
#endif                                                             //~va3xI~
                    ii++;                                          //~va20R~
                    *pdjwk+=2;                                     //~va20R~
                }                                                  //~va20R~
                else                    //sbcs                     //~va20R~
#endif                                                             //~va20R~
                if (dbcssw && *pdbcs==DBCS1STCHAR)                 //~v511I~
                {                                                  //~v511R~
                    if (rtype==1)       //rj                       //~v511R~
                        pc-=2;                                     //~v511R~
                    *pc=*pdata++;                                  //~v511R~
                    pdbcs++;                                       //~v511R~
                    *((pc++)+dbcsoffs)=DBCS1STCHAR;                //~v511R~
                    *pc=*pdata;                                    //~v511R~
                    *(pc+dbcsoffs)=DBCS2NDCHAR;                    //~v511R~
                    ii++;                                          //~v511R~
                    *pdjwk+=2;                                     //~v511R~
                }                                                  //~v511R~
                else                    //sbcs                     //~v511R~
                {                                                  //~v511R~
                  if (dbcsasw)          //2 column for also sbcs   //~v76FI~
                  {                                                //~v76FI~
                    if (rtype==1)       //set back from right end  //~v76FI~
                    {                                              //~v76FI~
                        pc--;                                      //~v76FI~
                  		if (dbcsalsw)	//left align               //~v76FI~
                        	pc--;                                  //~v76FI~
                    }                                              //~v76FI~
                    else                //set from left end        //~v76FI~
                    {                                              //~v76FI~
                  		if (dbcsarsw)	//right align              //~v76FI~
                        	pc++;       //skip 1 space             //~v76FI~
                    }                                              //~v76FI~
                    *pc=*pdata;                                    //~v76FI~
                    *pdjwk+=2;                                     //~v76FI~
                  }                                                //~v76FI~
                  else                                             //~v76FI~
                  {                                                //~v76FI~
                    if (rtype==1)       //rj                       //~v511R~
                        pc--;                                      //~v511R~
                    *pc=*pdata;                                    //~v511R~
                    *pdjwk+=1;                                     //~v511R~
                  }                                                //~v76FI~
#ifdef UTF8UCS2                                                    //~va20I~
                  if (UDBCSCHK_ISUCSSBCSER(dbcsid))                //~va20R~
//                  *(pc+dbcsoffs)=dbcsid;                         //~va20I~//~vb2CR~
                    *(pc+dbcsoffs)=(UCHAR)dbcsid;                  //~vb2CR~
#endif                                                             //~va20I~
                }                                                  //~v511R~
            }                                                      //~va20I~
            else	//short line                                   //~v511I~
            {                                                      //~v76FI~
              if (dbcsasw)          //2 column for also sbcs       //~v76FI~
                *pdjwk+=2;                                         //~v76FI~
              else                                                 //~v76FI~
                *pdjwk+=1;                                         //~v511I~
            }                                                      //~v76FI~
          }//dbbcssz<=2                                            //~vva1cI~//~va1cR~
            charctr++;                                             //~v511R~
        }//a line data                                             //~v511R~
        linectr++;                                                 //~v511R~
    }//all line                                                    //~v511R~
//update file                                                      
	djoffs=0;                                                      //~v511I~
    for (ii=0,maxwidth=0,pdjwk=pdjwk0;ii<Pmaxcol;ii++,pdjwk++)     //~v511R~
        if (maxwidth<*pdjwk)                                       //~v511R~
            maxwidth=*pdjwk;                                       //~v511R~
    if (rtype==1)   //rotate right                                 //~v511R~
        djoffs=outwidth-maxwidth;                                  //~v511R~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);	//after curtop changed chk //~v511I~
    for (linectr=0,plh=Pplhs;plh && plh!=Pplhe;plh=UGETQNEXT(plh)) 
	{                                                              
        if (plh->ULHtype!=ULHTDATA)                                
        	continue;                                              
        pdata=pwk+linectr*outwidth+djoffs;                         //~v511R~
        pdbcs=pdata+dbcsoffs;                                      
        len=maxwidth;                                              //~v511I~
        if (linectr<Pmaxcol)	//rep range of tall box            //~v511R~
        {                                                          
        	if (tailcutsw)                                         //~v511I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	        	len-=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,pdata,pdbcs,len);//~va50I~
    #else                                                          //~va50I~
	        	len-=(int)UTF_umemrspnc(swutf8file,pdata,pdbcs,' ',len);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
	        	len-=(int)umemrspnc(pdata,' ',(UINT)len);          //~v52dR~
#endif                                                             //~va20I~
        	rc=fcmdlineupdate(Ppcw,plh,pdata,pdbcs,len);           
            if (rc)                                                
            	break;                                             
        }                                                          
        else                                                       
        {                                                          //~v54GI~
			lcmddelresetcurtop(Ppcw,plh);	//maint pfccurtop      //~v54GI~
//*undo del,no dbcstbl chng                                        //~va5PI~
			if (rc=undoupdate(Ppcw,plh,UUHTDEL),rc)//deq and prep for undo
            	break;	//UALLOC_FAILED                            
        }                                                          //~v54GI~
        linectr++;                                                 
	}//all plh                                                     
    if (rc)//expand data len                                       
    	return rc;                                                 
    plh=UGETQPREV(Pplhe);//before eof line                         //~v511R~
    if (isrtctr=Pmaxcol-Plinectr,isrtctr>0)	//isrt required(wide box)//~v511R~
    {                                                              
        pdata=pwk+Plinectr*outwidth;                               //~v511R~
    	for (ii=0;ii<isrtctr;ii++,pdata+=outwidth)                 //~v511R~
        {                                                          
        	pc=pdata+djoffs;                                       //~v511I~
	        len=maxwidth;                                          //~v511I~
    		if (tailcutsw)                                         //~v511I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        		len-=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,pc,pc+dbcsoffs,len);//~va50I~
	#else                                                          //~va50I~
        		len-=(int)UTF_umemrspnc(swutf8file,pc,pc+dbcsoffs,' ',len);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        		len-=(int)umemrspnc(pc,' ',(UINT)len);             //~v52dR~
#endif                                                             //~va20I~
			rc=fcmdisrtlinedbcs(Ppcw,plh,pc,pc+dbcsoffs,len);      //~v511R~
            if (rc)                                                //~v511I~
            	break;                                             //~v511I~
            plh=UGETQNEXT(plh);     //isrted line                  
        }                                                          
    }                                                              
	return rc;                                                     //~v511R~
}//fcmdrotaterl                                                    
//**************************************************************** 
// rotate horizontal (around axis x=n)                             //~vva1cR~//~va1cR~
//*parm1 :pcw                                                      
//*parm2 :pfh                                                      
//*parm3 :start plh                                                
//*parm4 :end   plh                                                
//*parm5 :option                                                   
//*parm6 :work                                                     
//*parm7 :maxlen                                                   
//*return:rc                                                       
//**************************************************************** 
int fcmdrotatey(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplhs,PULINEH Pplhe,int Popt,UCHAR *Ppwk,int Pmaxlen)//~v511R~
{                                                                  
	PULINEH plh;                                                   
    UCHAR   *pwk,*pdata,*pdbcs,*pc;                                
    int ii,rc=0,rjust,dbcsoffs,len,rpos,tailcutsw,nxsw,justsw,shiftlen;//~v511R~
    int ajrsw;                                                     //~v511I~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~
    int chsz,nextstep;                                             //~vva1cI~//~va1cR~
#endif                                                             //~vva1cI~//~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
    int dbcsid,swutf8file;                                         //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	justsw=((Popt & ROTOPT_RTYPE)==5);                             //~v511I~
	rjust=(Popt & ROTOPT_RJUST);                                   //~v511R~
	tailcutsw=(Popt & ROTOPT_TAILCUT);                             //~v511I~
	nxsw=(Popt & ROTOPT_NX);                                       //~v511I~
	ajrsw=(Popt & ROTOPT_AJRANGE);                                 //~v511R~
    dbcsoffs=Pmaxlen;                                              
    pwk=Ppwk;                       //data                         
//update file                                                      
    for (plh=Pplhs;plh && plh!=Pplhe;plh=UGETQNEXT(plh))           
	{                                                              
        if (plh->ULHtype!=ULHTDATA)                                
        	continue;                                              
        if (nxsw)                                                  //~v511R~
			if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))             //~v511I~
            	continue;                                          //~v511I~
        if (ajrsw)                                                 //~v511I~
            fcmdajr(Popt,plh,pwk,Pmaxlen,&len);                    //~v511I~
        else                                                       //~v511I~
        {                                                          //~v511I~
            pdata=plh->ULHdata;                                    //~v511R~
            pdbcs=plh->ULHdbcs;                                    //~v511R~
            len=plh->ULHlen;                                       //~v511R~
            memset(pwk+Pmaxlen,0,(UINT)Pmaxlen);                   //~v511R~
            if (justsw)         //rj or lj                         //~v511R~
            {                                                      //~v511R~
                if (rjust)       //ajust right                     //~v511R~
                {                                                  //~v511R~
#ifdef UTF8UCS2     //ROT RJ                                       //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    rpos=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,pdata,pdbcs,len);//~va50I~
    #else                                                          //~va50I~
                    rpos=(int)UTF_umemrspnc(swutf8file,pdata,pdbcs,' ',len);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    rpos=(int)umemrspnc(pdata,' ',(UINT)len);      //~v52dR~
#endif                                                             //~va20I~
                    shiftlen=len-rpos;                             //~v511R~
                    rpos+=(Pmaxlen-len);    //ajust to maxlen record//~v52dI~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    UCVEBC_memset_space(swebcfile,pwk,(UINT)rpos); //~va50I~
    #else                                                          //~va50I~
                    memset(pwk,' ',(UINT)rpos);                    //~v511R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
                    memcpy(pwk+rpos,pdata,(UINT)shiftlen);         //~v511R~
                    pc=pwk+dbcsoffs+rpos;                          //~v511R~
                    len=Pmaxlen;                                   //~v511R~
                    if (tailcutsw && shiftlen==0)                  //~v511R~
                        len=0;                                     //~v511R~
                    else                                           //~v511R~
                        len=Pmaxlen;                               //~v511R~
                }                                                  //~v511R~
                else                                               //~v511R~
                {                                                  //~v511R~
#ifdef UTF8UCS2     //ROT LJ                                       //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    rpos=(int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,pdata,pdbcs,len);//~va50I~
    #else                                                          //~va50I~
                    rpos=(int)UTF_umemspnc(swutf8file,pdata,pdbcs,' ',len);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    rpos=(int)umemspnc(pdata,' ',(UINT)len);       //~v52dR~
#endif                                                             //~va20I~
                    shiftlen=len-rpos;                             //~v511R~
                    memcpy(pwk,pdata+rpos,(UINT)shiftlen);         //~v511R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    UCVEBC_memset_space(swebcfile,pwk+shiftlen,(UINT)(Pmaxlen-shiftlen));//~va50I~
    #else                                                          //~va50I~
                    memset(pwk+shiftlen,' ',(UINT)(Pmaxlen-shiftlen));//~v511R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
                    pdbcs+=rpos;                                   //~v511R~
                    pc=pwk+dbcsoffs;                               //~v511R~
                    rpos=shiftlen;                                 //~v511R~
                    if (tailcutsw)                                 //~v511R~
#ifdef UTF8UCS2     //ROT RJ                                       //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                        len=rpos-(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,pwk,pdbcs,rpos);//~va50I~
    #else                                                          //~va50I~
                        len=rpos-(int)UTF_umemrspnc(swutf8file,pwk,pdbcs,' ',rpos);//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                        len=rpos-(int)umemrspnc(pwk,' ',(UINT)rpos);//~v52dR~
#endif                                                             //~va20I~
                }                                                  //~v511R~
                for (ii=0;ii<shiftlen;ii++,pdbcs++,pc++)           //~v511R~
                {                                                  //~v511R~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~
#else                                                              //~vva1cI~//~va1cR~
                    if (*pdbcs==DBCS1STCHAR)                       //~v511R~
                    {                                              //~v511R~
                        pdbcs++;                                   //~v511R~
                        *pc++=DBCS1STCHAR;                         //~v511R~
                        *pc=DBCS2NDCHAR;                           //~v511R~
                        ii++;                                      //~v511R~
                    }                                              //~v511R~
                    else                                           //~va18R~
#endif                                                             //~vva1cI~//~va1cR~
//*TABCHAR is never set on dbcstbl for ebcfile                     //~va5PI~
                    if (*pdbcs!=TABCHAR && *pdbcs!=TABPADCHAR)     //~va18R~
                        *pc=*pdbcs;                                //~va18R~
                }                                                  //~v511R~
            }                                                      //~v511R~
            else    //rotate                                       //~v511R~
            {                                                      //~v511R~
                rpos=len;                                          //~v511R~
                pc=pwk+(rpos-1);                                   //~v511R~
                for (ii=0;ii<len;ii++,pdata++,pdbcs++,pc--)        //~v511R~
                {                                                  //~v511R~
#ifdef UTF8UCS2                                                    //~va20R~
					dbcsid=*pdbcs;                                 //~va20R~
                    if (UDBCSCHK_DBCS1STLU(dbcsid))//locale and ucs//~va20R~
#else                                                              //~va20R~
                    if (*pdbcs==DBCS1STCHAR)                       //~v511R~
#endif                                                             //~va20R~
                    {                                              //~v511R~
#ifdef UTF8SUPPH                                                   //~vva1cI~//~va1cR~
                    	chsz=XESUB_DBCSSPLITCTR(pdbcs,len-ii,0); //dbcs char size//~vva1cI~//~va1cR~
                        nextstep=chsz-1;                           //~vva1cI~//~va1cR~
                        memcpy(pc-nextstep,pdata,(UINT)chsz);      //~vva1cR~//~va1cR~
                        memcpy(pc+dbcsoffs-nextstep,pdbcs,(UINT)chsz);//~vva1cR~//~va1cR~
                        pdata+=nextstep;                           //~vva1cI~//~va1cR~
                        pdbcs+=nextstep;                           //~vva1cI~//~va1cR~
                        pc-=nextstep;                              //~vva1cI~//~va1cR~
                        ii+=nextstep;                              //~vva1cI~//~va1cR~
#else                                                              //~vva1cI~//~va1cR~
                        *(pc-1)=*pdata++;       //1st byte         //~v511R~
                        pdbcs++;                                   //~v511R~
                        *(pc-1+dbcsoffs)=DBCS1STCHAR;              //~v511R~
                        *pc=*pdata;                                //~v511R~
                        *((pc--)+dbcsoffs)=DBCS2NDCHAR;            //~v511R~
                        ii++;                                      //~v511R~
#endif                                                             //~vva1cR~//~va1cR~
                    }                                              //~v511R~
                    else                    //sbcs                 //~v511R~
                    {                                              //~va18I~
                        *pc=*pdata;                                //~v511R~
#ifdef UTF8UCS2                                                    //~va20I~
                        if (UDBCSCHK_ISUCSSBCSER(dbcsid))//sbcs and f2lerr//~va20R~
//                      	*(pc+dbcsoffs)=dbcsid;                 //~va20I~//~vb2CR~
                        	*(pc+dbcsoffs)=(UCHAR)dbcsid;          //~vb2CR~
                        else                                       //~va20I~
#endif                                                             //~va20I~
//*TABCHAR is never set on dbcstbl for ebcfile                     //~va5PI~
	                    if (*pdbcs!=TABCHAR && *pdbcs!=TABPADCHAR) //~va18I~
	                        *(pc+dbcsoffs)=*pdbcs;                 //~va18I~
                    }                                              //~va18I~
                }                                                  //~v511R~
                if (tailcutsw)                                     //~v511R~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
                    len=rpos-(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,pwk,pwk+dbcsoffs,rpos);//~va50I~
    #else                                                          //~va50I~
                    len=rpos-(int)UTF_umemrspnc(swutf8file,pwk,pwk+dbcsoffs,' ',rpos);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
                    len=rpos-(int)umemrspnc(pwk,' ',(UINT)rpos);   //~v52dR~
#endif                                                             //~va20I~
                else                                               //~v511R~
                    len=rpos;                                      //~v511R~
            }//rotate                                              //~v511R~
        }                                                          //~v511I~
        rc=fcmdlineupdate(Ppcw,plh,pwk,pwk+dbcsoffs,len);          
        if (rc)                                                    
            break;                                                 
	}//all plh                                                     
    return rc;                                                     
}//fcmdrotatey                                                     //~v511R~
//**************************************************************** //~v511I~
// range taype shift r/l                                           //~v511I~
//*parm1 :opt                                                      //~v511I~
//*parm2 :plh                                                      //~v511I~
//*parm3 :work                                                     //~v511I~
//*parm4 :worklen                                                  //~v511I~
//*parm5 :output line length                                       //~v511I~
//*return:rc                                                       //~v511I~
//**************************************************************** //~v511I~
int fcmdajr(int Popt,PULINEH Pplh,char *Ppwk,int Pmaxlen,int *Pplen)//~v511I~
{                                                                  //~v511I~
    UCHAR   *pwk,*pdata,*pdbcs,*pc;                                //~v511I~
    int /*ii,*/rjust,len,rpos,tailcutsw,shiftlen,outlen,inppos,outpos,cutlen,width;//~va18R~
/*    int dbcssw1;*/                                               //~va18R~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                //~v511I~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=PLHUTF8MODE(Pplh);                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PLH_ISEBC(Pplh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	rjust=(Popt & ROTOPT_RJUST);                                   //~v511I~
	tailcutsw=(Popt & ROTOPT_TAILCUT);                             //~v511I~
    pwk=Ppwk;                       //data                         //~v511I~
    pdata=Pplh->ULHdata;                                           //~v511R~
    pdbcs=Pplh->ULHdbcs;                                           //~v511R~
    len=Pplh->ULHlen;                                              //~v511R~
    memcpy(pwk,pdata,(UINT)len);                                   //~v511R~
    memcpy(pwk+Pmaxlen,pdbcs,(UINT)len);                           //~v511I~
#ifdef UTF8SUPPH                                                   //~va18I~
#else                                                              //~va18I~
    for (ii=0,pc=pwk+Pmaxlen;ii<len;ii++,pdbcs++,pc++)             //~v511I~
    	if (*pdbcs==DBCS1STCHAR)                                   //~v511I~
        	*pc=DBCS1STCHAR;                                       //~v511I~
        else                                                       //~v511I~
    	if (*pdbcs==DBCS2NDCHAR)                                   //~v511I~
        	*pc=DBCS2NDCHAR;                                       //~v511I~
#endif                                                             //~va18I~
    pdbcs=Pplh->ULHdbcs;                                           //~v511I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50R~
    UCVEBC_memset_space(swebcfile,pwk+len,(UINT)(Pmaxlen-len));    //~va50R~
#else                                                              //~va50R~
    memset(pwk+len,' ',(UINT)(Pmaxlen-len));                       //~v511I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50R~
    memset(pwk+Pmaxlen+len,0,(UINT)(Pmaxlen-len));                 //~v511I~
    outlen=len; //no change                                        //~v511I~
//  width=Sjpos2-Sjpos1;                                           //~v511I~//~vb2ER~
    width=(int)(Sjpos2-Sjpos1);                                    //~vb2EI~
    if (len<=Sjpos1)	//no data in the range                     //~v511I~
    {                                                              //~v511I~
    	if (!tailcutsw)                                            //~v511I~
//      	outlen=Sjpos2;                                         //~v511I~//~vb2ER~
        	outlen=(int)Sjpos2;                                    //~vb2EI~
    }                                                              //~v511I~
    else                                                           //~v511I~
    {                                                              //~v511I~
	    if (len<Sjpos2)	//short data                               //~v511I~
//  		shiftlen=len-Sjpos1;                                   //~v511I~//~vb2ER~
    		shiftlen=len-(int)Sjpos1;                              //~vb2EI~
        else                                                       //~v511I~
        	shiftlen=width;                                        //~v511R~
        if (rjust)       //ajust right                             //~v511I~
        {                                                          //~v511I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	cutlen=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,pdata+Sjpos1,pdbcs+Sjpos1,shiftlen);//~va50R~
    #else                                                          //~va50I~
        	cutlen=(int)UTF_umemrspnc(swutf8file,pdata+Sjpos1,pdbcs+Sjpos1,' ',shiftlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	cutlen=(int)umemrspnc(pdata+Sjpos1,' ',(UINT)shiftlen);//~v52dR~
#endif                                                             //~va20I~
        	shiftlen-=cutlen;                                      //~v511I~
#ifdef UTF8SUPPH                                                   //~va18I~
//  		if (cutlen)	//shift occures                            //~va18I~//~va5MR~
    		if (cutlen||len<Sjpos2)	//shift occures                //~va5MI~
            {                                                      //~va18I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//      		setobtabdbcs(swebcfile,0,pwk,pwk+Pmaxlen,len,Sjpos1,shiftlen);	//clear tab/dbcs of out of range//~va50I~//~vb2ER~
        		setobtabdbcs(swebcfile,0,pwk,pwk+Pmaxlen,len,(int)Sjpos1,shiftlen);	//clear tab/dbcs of out of range//~vb2EI~
#else                                                              //~va50I~
        		setobtabdbcs(pwk,pwk+Pmaxlen,len,Sjpos1,shiftlen);	//clear tab/dbcs of out of range//~va18I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//  	        memset(pwk+Pmaxlen+Sjpos1,0,width);	//dbcs clear   //~va18I~//~vb2DR~
    	        memset(pwk+Pmaxlen+Sjpos1,0,(size_t)width);	//dbcs clear//~vb2DI~
        	}                                                      //~va18I~
#endif                                                             //~va18I~
//          inppos=Sjpos1;                                         //~v511I~//~vb2ER~
            inppos=(int)Sjpos1;                                    //~vb2EI~
//          outpos=Sjpos2-shiftlen;	//out pos                      //~v511I~//~vb2ER~
            outpos=(int)Sjpos2-shiftlen;	//out pos              //~vb2EI~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	        UCVEBC_memset_space(swebcfile,pwk+Sjpos1,(UINT)(width-shiftlen));//~va50I~
    #else                                                          //~va50I~
	        memset(pwk+Sjpos1,' ',(UINT)(width-shiftlen));         //~v511I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
	        memcpy(pwk+outpos,pdata+inppos,(UINT)shiftlen);        //~v511I~
        }                                                          //~v511I~
        else	//ljust                                            //~v511I~
        {                                                          //~v511I~
#ifdef UTF8UCS2     //ROT LJ                                       //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      	cutlen=(int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,pdata+Sjpos1,pdbcs+Sjpos1,(UINT)shiftlen);//~va50I~//~vb2DR~
        	cutlen=(int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,pdata+Sjpos1,pdbcs+Sjpos1,shiftlen);//~vb2DI~
    #else                                                          //~va50I~
        	cutlen=(int)UTF_umemspnc(swutf8file,pdata+Sjpos1,pdbcs+Sjpos1,' ',(UINT)shiftlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	cutlen=(int)umemspnc(pdata+Sjpos1,' ',(UINT)shiftlen); //~v52dR~
#endif                                                             //~va20I~
//      	shiftlen-=cutlen;//move update shiftlen to after setdbcssplit     //~v511I~//~va5PR~
#ifdef UTF8SUPPH                                                   //~va18I~
			if (cutlen)	//shift occures                            //~va18I~
            {                                                      //~va18I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//      		setobtabdbcs(swebcfile,0,pwk,pwk+Pmaxlen,len,Sjpos1,shiftlen);	//clear tab/dbcs of out of range//~va50I~//~vb2ER~
        		setobtabdbcs(swebcfile,0,pwk,pwk+Pmaxlen,len,(int)Sjpos1,shiftlen);	//clear tab/dbcs of out of range//~vb2EI~
    #else                                                          //~va50I~
        		setobtabdbcs(pwk,pwk+Pmaxlen,len,Sjpos1,shiftlen);	//clear tab/dbcs of out of range//~va18I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
//		        memset(pwk+Pmaxlen+Sjpos1,0,width);	//dbcs clear   //~va18I~//~vb2DR~
  		        memset(pwk+Pmaxlen+Sjpos1,0,(size_t)width);	//dbcs clear//~vb2DI~
        	}                                                      //~va18I~
#endif                                                             //~va18I~
        	shiftlen-=cutlen;                                      //~va5PI~
//          inppos=Sjpos1+cutlen;                                  //~v511I~//~vb2ER~
            inppos=(int)Sjpos1+cutlen;                             //~vb2EI~
//          outpos=Sjpos1;                                         //~v511I~//~vb2ER~
            outpos=(int)Sjpos1;                                    //~vb2EI~
	        memcpy(pwk+outpos,pdata+inppos,(UINT)shiftlen);        //~v511I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	        UCVEBC_memset_space(swebcfile,pwk+outpos+shiftlen,(UINT)(width-shiftlen));//~va50I~
    #else                                                          //~va50I~
	        memset(pwk+outpos+shiftlen,' ',(UINT)(width-shiftlen));//~v511I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
        }                                                          //~v511I~
    	if (tailcutsw)                                             //~v511I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	shiftlen-=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,pdata+inppos,pdbcs+inppos,shiftlen);//~va50I~
    #else                                                          //~va50I~
        	shiftlen-=(int)UTF_umemrspnc(swutf8file,pdata+inppos,pdbcs+inppos,' ',shiftlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	shiftlen-=(int)umemrspnc(pdata+inppos,' ',(UINT)shiftlen);//~v52dR~
#endif                                                             //~va20I~
        rpos=outpos+shiftlen;                                      //~v511I~
        pdbcs+=inppos;                                             //~v511I~
        pc=pwk+Pmaxlen+outpos;                                     //~v511I~
#ifdef UTF8SUPPH                                                   //~va18I~
//      memcpy(pc,pdbcs,shiftlen);                                 //~va18I~//~vb2DR~
        memcpy(pc,pdbcs,(size_t)shiftlen);                         //~vb2DI~
        chartabclear(pc,shiftlen);                                 //~va18I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        xesub_setdbcssplit(swebcfile,0/*plh*/,pwk+outpos,pc,shiftlen,' ');//clear both inner boundary split dbcs//~va50I~
    #else                                                          //~va50I~
        setdbcssplit(pwk+outpos,pc,shiftlen,' ');//clear both inner boundary split dbcs//~va18I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va18I~
        dbcssw1=0;                                                 //~v511I~
        for (ii=0;ii<shiftlen;ii++,pdbcs++,pc++)                   //~v511I~
        {                                                          //~v511I~
            if (*pdbcs==DBCS1STCHAR)                               //~v511R~
            {                                                      //~v511I~
            	if (ii==shiftlen-1	//last dbcs split              //~v511I~
                &&  outpos+shiftlen!=Sjpos2)                       //~v511I~
                {                                                  //~v511I~
//*!UTF8SUPPH                                                      //~va50I~
                    *(pwk+outpos+ii)=' ';                          //~v511I~
                    *(pwk+Sjpos2)=' ';                             //~v511M~
                    *(pwk+Pmaxlen+Sjpos2)=0;                       //~v511I~
                }                                                  //~v511I~
                else                                               //~v511I~
                {                                                  //~v511I~
            		dbcssw1=1;                                     //~v511I~
                	*pc=DBCS1STCHAR;                               //~v511R~
                }                                                  //~v511I~
            }                                                      //~v511I~
            else                                                   //~v511I~
            if (*pdbcs==DBCS2NDCHAR)                               //~v511I~
            {                                                      //~v511I~
            	if (!dbcssw1	//after 1st byte                   //~v511I~
                &&  inppos!=outpos)                                //~v511I~
                {                                                  //~v511I~
//*!UTF8SUPPH                                                      //~va50I~
                    *(pwk+outpos)=' ';                             //~v511I~
                    *(pwk+Sjpos1-1)=' ';                           //~v511I~
                    *(pwk+Pmaxlen+Sjpos1-1)=0;                     //~v511R~
                }                                                  //~v511I~
                else                                               //~v511I~
	                *pc=DBCS2NDCHAR;                               //~v511I~
            }                                                      //~v511I~
        }                                                          //~v511I~
#endif                                                             //~va18I~
//      if (len<Sjpos2)	//short data                               //~v76HR~
        if (len<=Sjpos2)	//short data                           //~v76HI~
        {                                                          //~v511I~
	    	if (tailcutsw)                                         //~v511I~
        		outlen=rpos;                                       //~v511I~
            else                                                   //~v511I~
//          	outlen=Sjpos2;                                     //~v511I~//~vb2ER~
            	outlen=(int)Sjpos2;                                //~vb2EI~
        }                                                          //~v511I~
    }                                                              //~v511I~
    *Pplen=outlen;                                                 //~v511I~
    return 0;                                                      //~v511I~
}//fcmdajr                                                         //~v511I~
//**************************************************************** 
// rotate virtical                                                 
//*parm1 :pcw                                                      
//*parm2 :pfh                                                      
//*parm3 :start plh                                                
//*parm4 :end   plh                                                
//*parm5 :option                                                   
//*parm6 :linectr                                                  
//*return:rc                                                       
//**************************************************************** 
int fcmdrotatex(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplhs,PULINEH Pplhe,int Popt,int Plinectr)//~v511R~
{                                                                  
	PULINEH plh,plhback,plhnext=0,plhbackprev;                     //~v511R~
    UCHAR   *pdata,*pdbcs;                                         
//  int rc,swapctr=0,maxswap,len,bufflen,nxsw,tailcutsw;           //~v511R~//~vaf9R~
    int rc=0,swapctr=0,maxswap,len,bufflen,nxsw,tailcutsw;         //~vaf9I~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*********************************                                
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	tailcutsw=(Popt & ROTOPT_TAILCUT);                             //~v511I~
	nxsw=(Popt & ROTOPT_NX);                                       //~v511I~
    maxswap=(int)((UINT)Plinectr>>1);                              //~v652R~
    plhbackprev=UGETQPREV(Pplhe);                                  //~v511R~
//update file                                                      
    for (plh=Pplhs,swapctr=0;swapctr<maxswap && plh;plh=plhnext)   //~v511R~
	{                                                              
	    plhnext=UGETQNEXT(plh);                                    //~v511I~
        if (plh->ULHtype!=ULHTDATA)                                
        	continue;                                              
        if (nxsw)                                                  //~v511R~
			if (UCBITCHK(plh->ULHflag2,ULHF2EXCLUDED))             //~v511I~
            	continue;                                          //~v511I~
        for (plhback=plhbackprev;plhback;plhback=UGETQPREV(plhback))//~v511R~
        	if (plhback->ULHtype==ULHTDATA)                        //~v511R~
		        if (!nxsw                                          //~v511R~
				||  !UCBITCHK(plhback->ULHflag2,ULHF2EXCLUDED))    //~v511R~
            		break;                                         //~v511R~
		plhbackprev=UGETQPREV(plhback);                            //~v511I~
//*exchange line data only,no dbcstbl chng                         //~va5PI~
        if ((rc=undoupdate(Ppcw,plh,UUHTREP))==UALLOC_FAILED)   //prepare undo and update process
            break;                                                 
        if ((rc=undoupdate(Ppcw,plhback,UUHTREP))==UALLOC_FAILED)   //prepare undo and update process
            break;                                                 
//swap                                                             
        pdata  =plh->ULHdata;                                      
        pdbcs  =plh->ULHdbcs;                                      
        bufflen=plh->ULHbufflen;                                   
        len    =plh->ULHlen;                                       
        plh->ULHdata   =plhback->ULHdata;                          
        plh->ULHdbcs   =plhback->ULHdbcs;                          
        plh->ULHbufflen=plhback->ULHbufflen;                       
        plh->ULHlen    =plhback->ULHlen;                           
        if (tailcutsw)                                             //~v511I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	plh->ULHlen-=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,plh->ULHdata,plh->ULHdbcs,plh->ULHlen);//~va50I~
    #else                                                          //~va50I~
        	plh->ULHlen-=(int)UTF_umemrspnc(swutf8file,plh->ULHdata,plh->ULHdbcs,' ',plh->ULHlen);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	plh->ULHlen-=(int)umemrspnc(plh->ULHdata,' ',(UINT)(plh->ULHlen));//~v52dR~
#endif                                                             //~va20I~
        plhback->ULHdata   =pdata;                                 
        plhback->ULHdbcs   =pdbcs;                                 
        plhback->ULHbufflen=bufflen;                               
        if (tailcutsw)                                             //~v511I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	len-=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,pdata,pdbcs,len);//~va50R~
    #else                                                          //~va50I~
        	len-=(int)UTF_umemrspnc(swutf8file,pdata,pdbcs,' ',len);//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	len-=(int)umemrspnc(pdata,' ',(UINT)len);              //~v52dR~
#endif                                                             //~va20I~
        plhback->ULHlen    =len;                                   
        swapctr++;                                                 
	}//half of all plh                                             //~v511R~
    return rc;                                                     
}//fcmdrotatex                                                     //~v511R~
//**************************************************************** 
// line update with data/dbcs                                      
//*parm1 :pcw                                                      
//*parm2 :plh                                                      
//*parm3 :data                                                     
//*parm4 :dbcs                                                     
//*parm5 :len                                                      
//*return:rc                                                       
//**************************************************************** 
int fcmdlineupdate(PUCLIENTWE Ppcw,PULINEH Pplh,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen)
{                                                                  
//******************************                                   
	if (Pplh->ULHbufflen<Plen)                                     
    	if (fileexpandbuff(Pplh,Plen)==UALLOC_FAILED)      //expand buff
    	    return UALLOC_FAILED;                                  
    if (Pplh->ULHlen==Plen)                                        //~v511I~
    {                                                              //~v511I~
    	if (!memcmp(Pplh->ULHdata,Ppdata,(UINT)Plen)               //~v511I~
    	&&  !memcmp(Pplh->ULHdbcs,Ppdbcs,(UINT)Plen))              //~v511I~
        	return 0;                                              //~v511I~
    }                                                              //~v511I~
//*ebc_setdbcstbl later                                            //~va5PI~
    if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)    //prepare undo and update process
    	return UALLOC_FAILED;                                      
    memcpy(Pplh->ULHdata,Ppdata,(UINT)Plen);                       
    memcpy(Pplh->ULHdbcs,Ppdbcs,(UINT)Plen);                       
    Pplh->ULHlen=Plen;                                             
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  	if (PLH_ISEBC(Pplh))                                           //~va50I~
		xeebc_setdbcstblplh(0,0/*pfh*/,Pplh,0/*ULHlen*/);          //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    return 0;                                                      
}//fcmdlineupdate                                                  
#endif //not DOSDOS                                                
//#ifdef W32                                                       //~v64vR~
#if defined(W32)||defined(LNX)                                     //~v64vI~
//**************************************************************** //~v564I~
// sort on optional label range                                    //~v564I~
//*rc   :0                                                         //~v564I~
//**************************************************************** //~v564I~
int func_openwith(PUCLIENTWE Ppcw)                                 //~v564I~
{                                                                  //~v564I~
	char *pc;                                                      //~v564I~
	char *pc2;                                                     //~v652I~
    int rc;                                                        //~v564I~
    char fpath[_MAX_PATH];                                         //~v564I~
//*********************************                                //~v564I~
	if (!(pc=Ppcw->UCWparm))		//operand                      //~v564I~
    {                                                              //~v564I~
        uerrmsg("ASS filename",0);                                 //~v564R~
        return 0;                                                  //~v564I~
    }                                                              //~v564I~
    pc2=                                                           //~v652I~
    dcmdfullpath(Ppcw,fpath,pc);                                   //~v564I~
    if (!pc2)                                                      //~v652I~
    {                                                              //~v652I~
    	uerrmsg("%s is invalid(remote is not supported)",0,        //~v652I~
				pc);                                               //~v652I~
    	return 4;                                                  //~v652I~
    }                                                              //~v652I~
#ifdef ARM                                                         //+vc61I~
    rc=dlcmdopenwithsub(Ppcw,fpath,0L);                            //+vc61I~
#else                                                              //+vc61I~
    rc=dlcmdopenwithsub(Ppcw,fpath);                               //~v564R~
#endif                                                             //+vc61I~
    if (!rc)                                                       //~v564I~
    	uerrmsg("Associate command accepted for %s",0,             //~v564R~
				pc);                                               //~v564I~
    return rc;                                                     //~v564I~
}//func_openwith                                                   //~v564I~
#endif                                                             //~v564I~
//**************************************************************** //~v78rI~
// profile cmd                                                     //~v78rI~
//*rc   :0                                                         //~v78rI~
//**************************************************************** //~v78rI~
int func_profile(PUCLIENTWE Ppcw)                                  //~v78rI~
{                                                                  //~v78rI~
    PUFILEH pfh;                                                   //~v78rI~
	char *pc;                                                      //~v78rI~
    int rc=0;                                                      //~v78LI~
//*********************************                                //~v78rI~
	if (Ppcw->UCWtype!=UCWTMENU                                    //~v78rI~
    &&  Ppcw->UCWmenuopt!=PANMOCMD)                                //~v78rI~
    	pfh=UGETPFHFROMPCW(Ppcw);                                  //~v78rI~
    else                                                           //~v78rI~
    	pfh=0;                                                     //~v78rI~
	pc=Ppcw->UCWparm;                                              //~v78rI~
	if (pc && *pc=='?')                                            //~v78rI~
        return fcmdprofhelp(Ppcw);                                 //~v78rR~
    if (!pc)                     //no opd                          //~v78rR~
    {                                                              //~v78rI~
		if (pfh && (!pfh->UFHtype||pfh->UFHtype==UFHTDIR))	//display current file/dir profile//~v78rR~
    		rc=fcmdprofshowstat(Ppcw,pfh);                         //~v78LR~
        else                                                       //~v78rI~
	        return fcmdprofhelp(Ppcw);                             //~v78rR~
    }                                                              //~v78rI~
    else                                                           //~v78rI~
		if (pfh)                                                   //~v78rI~
    		rc=fcmdprofshowstat(Ppcw,pfh);                         //~v78LR~
        else                                                       //~v78rI~
	        return fcmdprofhelp(Ppcw);                             //~v78rI~
	fcmdprof83q(4,0,0);		//free 83q                             //~v78LI~
    return rc;                                                     //~v78LR~
}//func_profile                                                    //~v78rI~
//**************************************************************** //~v78rI~
// profile cmd help                                                //~v78rI~
//*rc   :0                                                         //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofhelp(PUCLIENTWE Ppcw)                                  //~v78rI~
{                                                                  //~v78rI~
    uerrmsg("PRO [{? | * | path | ext}] "                          //~v78rR~
                " [SAVE|RESET] [ALL|"                              //~v78rR~
                " [NUMFLD]"                                        //~v78rR~
                " [TAB]"                                           //~v78rR~
                " [SYN]"                                           //~v78rI~
                "]"                                                //~v78rI~
                ,0);                                               //~v78rI~
    return 0;                                                      //~v78rI~
}//fcmdprofhelp                                                    //~v78rI~
//**************************************************************** //~v78rI~
// display profile record                                          //~vaj0R~
//*rc   :0                                                         //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofshowstat(PUCLIENTWE Ppcw,PUFILEH Ppfh)                 //~v78rR~
{                                                                  //~v78rI~
	PROFILE prof;                                                  //~v78rR~
	char  fpath[_MAX_PATH],fpathext[_MAX_PATH],fpathpdir[_MAX_PATH],*pc,*pctype,*pfnm;//~v78rR~
	char profmsg[512];                                             //~v78rI~
    int pathlen,opdno,rc,opt=0;                                    //~v78rR~
//*************************************                            //~v78rI~
    pctype=pc=Ppcw->UCWopdpot;                                     //~v78rR~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v78rI~
    if (opdno>0)                                                   //~v78rI~
    {                                                              //~v78rI~
		pfnm=Ppfh->UFHfilename;                                    //~v78rI~
//  	if (fcmdprofgetfnm(0,pfnm,fpath,fpathpdir,fpathext,&pathlen))//~v78HR~
		opt=(FCPRRO_TSO)*(UCBITCHK(Ppfh->UFHflag7,UFHF7TSO)!=0);   //~v78HI~
    	if (fcmdprofgetfnm(opt,pfnm,fpath,fpathpdir,fpathext,&pathlen))//~v78HI~
    		return 4;                                              //~v78rI~
        opt=FPURO_FILE;                                            //~v78rI~
        if (!stricmp(pc,"EXT"))                                    //~v78rR~
        {                                                          //~v78rI~
            pfnm=fpathext;                                         //~v78rM~
            if (!*pfnm)                                            //~v78rI~
				return fcmdproferrnoext(Ppfh->UFHfilename);        //~v78rI~
            opt=FPURO_EXT;                                         //~v78rI~
        }                                                          //~v78rI~
        else                                                       //~v78rI~
        if (!stricmp(pc,"PATH"))                                   //~v78rR~
        {                                                          //~v78rI~
            pfnm=fpathpdir;                                        //~v78rR~
            opt=FPURO_PATH;                                        //~v78rI~
        }                                                          //~v78rI~
        else                                                       //~v78rI~
        if (!stricmp(pc,"*"))                                      //~v78rR~
            pfnm=fpath;                                            //~v78rI~
        else                                                       //~v78rI~
        {                                                          //~v78rI~
        	pctype="*";                                            //~v78rR~
            pfnm=fpath;                                            //~v78rI~
        }                                                          //~v78rI~
        if (pc==pctype) //1st opd file type                        //~v78rI~
        {                                                          //~v78rI~
            pc+=strlen(pc)+1;                                      //~v78rI~
            opdno--;                                               //~v78rI~
        }                                                          //~v78rI~
		rc=fcmdprofreadrecord(FCPRRO_MSG,pfnm,&prof);              //~v78rR~
        if (opdno)    //set request                                //~v78rR~
        {                                                          //~v78rI~
            if (fcmdprofupdaterecordcmd(opt,Ppcw,Ppfh,&prof,pc,opdno))//~v78rR~
            	return 4;                                          //~v78rI~
			if (fcmdprofwriterecord(pfnm,&prof))                   //~v78rI~
            	return 4;                                          //~v78rI~
            uerrmsg("ProfileRecordType:%s was saved",0,            //~v78LR~
            		pctype);                                       //~v78rR~
        }                                                          //~v78rI~
        else                                                       //~v78rI~
        {                                                          //~v78rI~
	        if (rc)        //4:not found,1:version err             //~v78rI~
    	    	return 4;                                          //~v78rI~
			fcmdprofshowrecord(pctype,&prof);                      //~v78rR~
        }                                                          //~v78rI~
        return 0;                                                  //~v78rI~
    }                                                              //~v78rI~
	fcmdprofcurstat(Ppfh,profmsg);                                 //~v78rR~
    uerrmsg(profmsg,0);                                            //~v78rR~
    return 0;                                                      //~v78rI~
}//fcmdprofshowstat                                                //~v78rR~
//**************************************************************** //~v78rI~
// show profile record                                             //~v78rI~
//*rc   :0                                                         //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofshowrecord(char *Pptype,PPROFILE Ppprof)               //~v78rR~
{                                                                  //~v78rI~
	int ii;                                                        //~v78rI~
	char profmsg[512];                                             //~v78rI~
	char synlang[MAX_SYNTYPE],*pc;                                 //~v78rI~
	char colstype[MAXCOLSTYPNM+1];                                 //~v78rR~
    char lrecl[16],bnds1[16],bnds2[16],margin[16];                 //~v78rR~
    char tabctr[4];                                                //~v8@2I~
    char *pc2;                                                     //~vaj0R~
    int len;                                                       //~vaj0I~
#define NOTDEFINED "_"                                             //~v78rR~
//*************************************                            //~v78rI~
  if (Ppprof->PROFrecordmode==PROF_RECORDMODEV)                    //~vaj0I~
  {                                                                //~vaj0I~
    sprintf(lrecl,"%c",Ppprof->PROFrecordmode);                    //~vaj0I~
    pc=Ppprof->PROFvfmt;                                           //~vaj0R~
    len=sizeof(Ppprof->PROFvfmt);                                  //~vaj0I~
//  pc2=memchr(pc,' ',len);                                        //~vaj0R~//~vb2DR~
    pc2=memchr(pc,' ',(size_t)len);                                //~vb2DI~
    if (pc2)                                                       //~vaj0I~
    	len=PTRDIFF(pc2,pc);                                       //~vaj0I~
    sprintf(margin,"%*.*s",len,len,pc);                            //~vaj0I~
  }                                                                //~vaj0I~
  else                                                             //~vaj0I~
  {                                                                //~vaj0I~
	if (*(Ppprof->PROFlrecl+PROF_NUMFLDSZ-1)==' ')                 //~v78rR~
    	strcpy(lrecl,NOTDEFINED);                                  //~v78rM~
    else                                                           //~v78rI~
//  	sprintf(lrecl,"%d",uatoin(Ppprof->PROFlrecl,PROF_NUMFLDSZ));//~v78rR~//~va51R~
    	sprintf(lrecl,"%c%d",Ppprof->PROFrecordmode,uatoin(Ppprof->PROFlrecl,PROF_NUMFLDSZ));//~va51R~
	if (*(Ppprof->PROFmargin+PROF_NUMFLDSZ-1)==' ')                //~v78rI~
    	strcpy(margin,NOTDEFINED);                                 //~v78rI~
    else                                                           //~v78rI~
    	sprintf(margin,"%d",uatoin(Ppprof->PROFmargin,PROF_NUMFLDSZ));//~v78rI~
  }                                                                //~vaj0I~
	if (*(Ppprof->PROFbnds1+PROF_NUMFLDSZ-1)==' ')                 //~v78rR~
    	strcpy(bnds1,NOTDEFINED);                                  //~v78rM~
    else                                                           //~v78rI~
    	sprintf(bnds1,"%d",uatoin(Ppprof->PROFbnds1,PROF_NUMFLDSZ));//~v78rR~
	if (*(Ppprof->PROFbnds2+PROF_NUMFLDSZ-1)==' ')                 //~v78rR~
    	strcpy(bnds2,NOTDEFINED);                                  //~v78rM~
    else                                                           //~v78rI~
    	sprintf(bnds2,"%d",uatoin(Ppprof->PROFbnds2,PROF_NUMFLDSZ));//~v78rR~
    for (pc=Ppprof->PROFsynlang,ii=0;ii<MAX_SYNTYPE && *pc!=' ';pc++,ii++)//~v78rI~
    	synlang[ii]=*pc;                                           //~v78rI~
    synlang[ii]=0;                                                 //~v78rI~
    if (Ppprof->PROFcols==PROF_COLSDEF)                            //~v78rR~
    	strcpy(colstype,"Default");                                //~v78rI~
    else                                                           //~v78rI~
	    umemtrim(UMTO_1ST,Ppprof->PROFcolstype,MAXCOLSTYPNM,' ',colstype,0);//~v78rR~
    UmemcpyZ(tabctr,Ppprof->PROFtabctr,sizeof(Ppprof->PROFtabctr));//~v8@2I~
	sprintf(profmsg,"CAPS:%s, HEX:%s, NUM=%s, P%s, NUMCOB=%s, TABCLEAR=%s, LRECL=%s-%s, BNDSL=%s, BNDSR=%s, "//~v78rR~
                    "TABCTR=%s, "                                  //~v8@2I~
                    "COLS=%s(%s), "                                //~v78rI~
#ifdef UTF8SUPPH                                                   //~v78wI~//~va00R~
                    "CP=%s, "                                      //~v78wI~//~va00I~
#endif                                                             //~v78wI~//~va00I~
                    "FNCP=%s, "                                    //~vagEI~
                    "SYNOPEN=%s, "                                 //~v78rI~
	                "SYNENTER=%s, SYNLANG=%s"                      //~v78rR~
        	,((Ppprof->PROFcaps==PROF_CAPSON)?"ON":                //~v78rI~
        	   ((Ppprof->PROFcaps==PROF_CAPSOFF)?"OFF":NOTDEFINED))//~v78rI~
        	,((Ppprof->PROFvhex==PROF_VHEXON)?"ON":                //~v78rI~
        	   ((Ppprof->PROFvhex==PROF_VHEXOFF)?"OFF":NOTDEFINED))//~v78rI~
            ,((Ppprof->PROFnumstd==PROF_NUMSTD)?"STD":             //~v78rR~
               ((Ppprof->PROFnumstd==PROF_NONUMSTD)?"NO":NOTDEFINED))//~v78rI~
            ,((Ppprof->PROFoomprot==PROF_OOMPROT)?"1":             //~v78rR~
        	   ((Ppprof->PROFoomprot==PROF_OOMNOPROT)?"0":NOTDEFINED))//~v78rR~
            ,((Ppprof->PROFnumcob==PROF_NUMCOBK)?"SPACE":          //~v78rR~
        	   ((Ppprof->PROFnumcob==PROF_NUMCOB)?"ON":            //~v78rR~
        	   	((Ppprof->PROFnumcob==PROF_NUMNOCOB)?"OFF":NOTDEFINED)))//~v78rR~
            ,((Ppprof->PROFtabclear==PROF_TABCLEAR)?"ON":          //~v78rR~
               ((Ppprof->PROFtabclear==PROF_NOTABCLEAR)?"OFF":NOTDEFINED))//~v78rI~
            ,(lrecl)                                               //~v78rI~
            ,(margin)                                              //~v78rI~
            ,(bnds1)                                               //~v78rI~
            ,(bnds2)                                               //~v78rI~
            ,(tabctr)                                              //~v8@2I~
            ,(((Ppprof->PROFcols==PROF_COLSON||Ppprof->PROFcols==PROF_COLSDEF))?"ON"://~v78rR~
               ((Ppprof->PROFcols==PROF_COLSOFF)?"OFF":NOTDEFINED))//~v78rI~
            ,(colstype)                                            //~v78rI~
#ifdef UTF8SUPPH                                                   //~v78wI~//~va00R~
            ,((Ppprof->PROFcp==PROF_CPUTF8)?"UTF8":                //~v78wI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
               ((Ppprof->PROFcp==PROF_CPEBC)?"EBCDIC":             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
               ((Ppprof->PROFcp==PROF_CPLOCALE)?"LOCALE":"ASIS"))  //~v78wR~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
             )                                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~v78wI~//~va00I~
            ,((Ppprof->PROFfncp==PROF_FNCPUTF8)?"UTF8":            //~vagEI~
               ((Ppprof->PROFfncp==PROF_FNCPLOCALE)?"LOCALE":NOTDEFINED))//~vagEI~
            ,((Ppprof->PROFsynopen==PROF_SYNOPEN)?"ON":            //~v78rR~
               ((Ppprof->PROFsynopen==PROF_SYNNOOPEN)?"OFF":NOTDEFINED))//~v78rI~
            ,((Ppprof->PROFsynenter==PROF_SYNENTERA)?"AllLine":    //~v78rR~
        	   ((Ppprof->PROFsynenter==PROF_SYNENTER)?"UpdatedLine":NOTDEFINED))//~v78rI~
            ,((*synlang)?synlang:NOTDEFINED)                       //~v78rI~
             );                                                    //~v78rI~
    uerrmsg("ProfileRecord:%s: %s",0,                              //~v78rR~
				Pptype,profmsg);                                   //~v78rR~
    return 0;                                                      //~v78rI~
}//fcmdprofshowrecord                                              //~v78rI~
//**************************************************************** //~v78rI~
// sort on optional label range                                    //~v78rI~
//*rc   :0                                                         //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofcurstat(PUFILEH Ppfh,char *Pbuff)                      //~v78rR~
{                                                                  //~v78rI~
#define SETPROFSTAT(pc,stat) strcpy(pc,stat),pc+=sizeof(stat)-1    //~v78rI~
	char *pc;                                                      //~v78rI~
	char  *vfmtstr,mfhsize[8];                                     //~vaj0R~
    int vfmt;                                                      //~vaj0I~
//*************************************                            //~v78rI~
	pc=Pbuff;                                                      //~v78rI~
    *pc=0;                                                         //~v78rI~
	if (Ppfh->UFHsynflag  & UFHSF_ON)                              //~v78rI~
    	SETPROFSTAT(pc," SYN=ON");                                 //~v78rI~
    if (Ppfh->UFHsynflag  & UFHSF_ENTERONUPDATELINEONLY)           //~v78rR~
        SETPROFSTAT(pc," SYNENTER=Upd");                           //~v78rR~
    else                                                           //~v78rR~
    if (Ppfh->UFHsynflag  & UFHSF_ENTERON)                         //~v78rR~
        SETPROFSTAT(pc," SYNENTER=All");                           //~v78rR~
    if (*Ppfh->UFHsyntype)                                         //~v78rI~
    {                                                              //~v78rI~
    	pc+=sprintf(pc," SYNLANG=%s",Ppfh->UFHsyntype);            //~v78rI~
    }                                                              //~v78rI~
	if (UCBITCHK(Ppfh->UFHflag8,UFHF8CAPSON))                      //~v78rI~
    	SETPROFSTAT(pc," CAP=ON");                                 //~v78rI~
    else                                                           //~v78rI~
    	SETPROFSTAT(pc," CAP=OFF");                                //~v78rI~
    if (Ppfh->UFHspfpos)                                           //~v78rR~
    {                                                              //~v78rI~
    	if (!UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM))              //~v78rI~
    		SETPROFSTAT(pc," NUMSTD");                             //~v78rR~
    }                                                              //~v78rI~
    if (Ppfh->UFHmergin && Ppfh->UFHmergin!=MAXLINEDATA)           //~v78rR~
    {                                                              //~v78rI~
    	if (UCBITCHK(Ppfh->UFHflag3,UFHF3OOMNOPROT))               //~v78rI~
    		SETPROFSTAT(pc," P0");                                 //~v78rI~
        else                                                       //~v78rI~
    		SETPROFSTAT(pc," P1");                                 //~v78rI~
    }                                                              //~v78rI~
	if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB))                         //~v78rI~
    {                                                              //~v78rI~
		if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB2))                    //~v78rI~
    		SETPROFSTAT(pc," NUMCOB=SPACE");                       //~v78rI~
        else                                                       //~v78rI~
    		SETPROFSTAT(pc," NUMCOB=ON");                          //~v78rI~
    }                                                              //~v78rI~
	if (UCBITCHK(Ppfh->UFHflag5,UFHF5DROPTAB))                     //~v78rI~
    {                                                              //~v78rI~
    	SETPROFSTAT(pc," TABCLEAR");                               //~v78rI~
    }                                                              //~v78rI~
//  if (UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL))                    //~v78rI~//~vaj0R~
    if (!UCBITCHK(Ppfh->UFHflag13,UFHF13RV))                       //~vajhI~
    if (Ppfh->UFHlrecl)                                            //~vaj0I~
    {                                                              //~vaj0I~
//      pc+=sprintf(pc," LRECL=%d",Ppfh->UFHlrecl);                //~v78rI~//~va51R~
//      pc+=sprintf(pc," LRECL=%c%d",(UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD)?PROF_RECORDMODE:' '),Ppfh->UFHlrecl);//~va51R~//~vaj0R~
        char modelrecl;                                            //~vaj0R~
		if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))                //~vaj0I~
			modelrecl=PROF_RECORDMODE;                             //~vaj0I~
        else                                                       //~vaj0I~
		if (UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL))                //~vaj0I~
			modelrecl=PROF_FIXLRECL;                               //~vaj0R~
        else                                                       //~vaj0I~
        	modelrecl=' ';                                         //~vaj0R~
        pc+=sprintf(pc," LRECL=%c%d",modelrecl,Ppfh->UFHlrecl);    //~vaj0R~
    }                                                              //~vaj0I~
    if (UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN))                      //~vaj0I~
        pc+=sprintf(pc," M%d",Ppfh->UFHmergin);                    //~vaj0R~
    if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV))                        //~vaj0I~
    {                                                              //~vaj0I~
        vfmt=Ppfh->UFHvfmt;                                        //~vaj0R~
        vfmtstr=ufile5getVfmtstr(0,vfmt);                          //~vaj0R~
        if (vfmt==UFGETS_VFMT_MFH2)                                //~vaj0R~
        	strcpy(mfhsize,"(2)");                                 //~vaj0R~
        else                                                       //~vaj0I~
        if (vfmt==UFGETS_VFMT_MFH4)                                //~vaj0R~
        	strcpy(mfhsize,"(4)");                                 //~vaj0R~
        else                                                       //~vaj0I~
        	*mfhsize=0;                                            //~vaj0R~
        pc+=sprintf(pc," VFMT=%s%s",vfmtstr,mfhsize);              //~vaj0R~
    }                                                              //~vaj0I~
    if (Ppfh->UFHbndscol1)                                         //~v78rI~
        pc+=sprintf(pc," BNDL=%d",Ppfh->UFHbndscol1);              //~v78rI~
    if (Ppfh->UFHbndscol2)                                         //~v78rI~
        pc+=sprintf(pc," BNDR=%d",Ppfh->UFHbndscol2);              //~v78rI~
	pc+=sprintf(pc," TAB=%d",Ppfh->UFHtabskip);                    //~v8@2R~
    return 0;                                                      //~v78rI~
}//fcmdprofcurstat                                                 //~v78rR~
//**************************************************************** //~va6iI~
// fcmdgetprof by filename                                         //~va6iI~
//**************************************************************** //~va6iI~
int fcmdprofgetprofilebyfilename(int Popt,PUCLIENTWE Ppcw,char *Pfnm,PUFILEH /*output dummy*/Ppfh,long *Ppsetflag)//~va6iR~
{                                                                  //~va6iI~
    long  setflag;                                                 //~va6iI~
    int rc;                                                        //~va6iI~
//*********************                                            //~va6iI~
	memset(Ppfh,0,sizeof(UFILEH));                              //~va57I~//~va6iI~
    if (!dcmdfullpath(Ppcw,Ppfh->UFHfilename,Pfnm))                //~va6iR~
    	return 4;                                                  //~va6iI~
	rc=fcmdprofgetprofile(0,Ppfh,&setflag);             //~va50I~  //~va6iR~
    if (Ppsetflag)                                                 //~va6iI~
    	*Ppsetflag=setflag;                                        //~va6iI~
    UTRACEP("fcmdproggetprofilebyfilename rc=%d,fnm=%s->%s,setflag=%08x\n",rc,Pfnm,Ppfh->UFHfilename,setflag);//~va6iR~
    return rc;                                                     //~va6iI~
}//fcmdprofgetprofilebyfilename                                    //~va6iI~
//**************************************************************** //~v78rI~
// fcmdgetprof                                                     //~v78rI~
//*get profile specification                                       //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofgetprofile(int Popt,PUFILEH Ppfh,long *Ppsetflag)      //~v78rR~
{                                                                  //~v78rI~
    PROFILE prof;                                                  //~v78rM~
    PROFILE proffile;                                              //~va0sI~
    char  *pc;                                                     //~v78rR~
    int rc,ii,numval;                                              //~v78rR~
//  long setflag=0;                                                //~v8@FR~
    long setflag=FPURO_PROFILE; //once accessed profile            //~v8@FI~
    int spfsw=0;                                                   //~v78rI~
    int lrecl;                                                     //~va67I~
    UCHAR cvname[MAX_CSNAMESZ];                                    //~va79I~
    int handle;                                                    //~va79I~
    int vfmttype;                                                  //~vaj0I~
//************                                                     //~v78rI~
//	rc=fcmdprofgetprofilerecord(Ppfh,&prof);                       //~v78rI~//~va0sR~
	rc=fcmdprofgetprofilerecord(Ppfh,&prof,&proffile);             //~va0sI~
    if (!rc)	//profilerecord gotten                             //~v78rI~
    {                                                              //~v78rI~
        if (prof.PROFsynopen!=' ')                                 //~v78rR~
        {                                                          //~v78rI~
        	setflag|=FPURO_SYNOPEN;                                //~v78rI~
        	if (prof.PROFsynopen==PROF_SYNOPEN)                    //~v78rI~
            	Ppfh->UFHsynflag|=UFHSF_ON;                        //~v78rR~
            else                                                   //~v78rI~
        	if (prof.PROFsynopen==PROF_SYNNOOPEN)                  //~v78rI~
	        	setflag|=FPURO_SYNOFF;                             //~v78rI~
        }                                                          //~v78rI~
        if (prof.PROFsynenter!=' ')                                //~v78rR~
        {                                                          //~v78rI~
        	setflag|=FPURO_SYNENTER;                               //~v78rI~
        	if (prof.PROFsynenter==PROF_SYNENTER)                  //~v78rI~
				Ppfh->UFHsynflag|=UFHSF_ENTERONUPDATELINEONLY;     //~v78rR~
        	else                                                   //~v78rR~
        	if (prof.PROFsynenter==PROF_SYNENTERA)                 //~v78rR~
				Ppfh->UFHsynflag|=UFHSF_ENTERON;                   //~v78rR~
        }                                                          //~v78rI~
        if (*prof.PROFsynlang!=' ')                                //~v78rI~
        {                                                          //~v78rI~
        	setflag|=FPURO_SYNLANG;                                //~v78rI~
        	for (pc=prof.PROFsynlang,ii=0;ii<MAX_SYNTYPE && *pc!=' ';pc++,ii++)//~v78rI~
            	Ppfh->UFHsyntype[ii]=*pc;                          //~v78rI~
        }                                                          //~v78rI~
        if (prof.PROFcaps!=' ')                                    //~v78rR~
        {                                                          //~v78rI~
        	setflag|=FPURO_CAPS;                                   //~v78rI~
        	if (prof.PROFcaps==PROF_CAPSON)                        //~v78rR~
				UCBITON(Ppfh->UFHflag8,UFHF8CAPSON);               //~v78rR~
        }                                                          //~v78rI~
        if (prof.PROFvhex!=' ')                                    //~v78rI~
        {                                                          //~v78rI~
        	setflag|=FPURO_VHEX;                                   //~v78rI~
        	if (prof.PROFvhex==PROF_VHEXON)                        //~v78rI~
				UCBITON(Ppfh->UFHflag6,UFHF6VHEXPARM);  //virtical hex display//~v78rI~
        }                                                          //~v78rI~
        if (prof.PROFcols==PROF_COLSON)                            //~v78rR~
        {                                                          //~v78rI~
        	setflag|=FPURO_COLS;                                   //~v78rI~
//          umemtrim(UMTO_1ST,prof.PROFcolstype,MAXCOLSTYPNM,' ',Ppfh->UFHcolstype,0);//~vbs6R~
        }                                                          //~v78rI~
        else                                                       //~v78rI~
        if (prof.PROFcols==PROF_COLSDEF)                           //~v78rI~
        {                                                          //~v78rI~
        	setflag|=FPURO_COLS|FPURO_COLSDEF;                     //~v78rI~
        }                                                          //~v78rI~
        umemtrim(UMTO_1ST,prof.PROFcolstype,MAXCOLSTYPNM,' ',Ppfh->UFHcolstype,0);//~vbs6I~
        if (*prof.PROFtabctr!=' ')                                 //~v8@2I~
        {                                                          //~v8@2I~
        	setflag|=FPURO_TABCTR;                                 //~v8@2I~
			Ppfh->UFHtabskip=(UCHAR)uatoin(prof.PROFtabctr,(int)sizeof(prof.PROFtabctr));//~v79mR~
        }                                                          //~v8@2I~
		if (!Ppfh->UFHtabskip)                                     //~v8@2I~
    		Ppfh->UFHtabskip=(UCHAR)Gfiletabskip;                  //~v79mR~
		if (!Ppfh->UFHtabskip)                                     //~v8@2I~
    		Ppfh->UFHtabskip=1;  //TABSKIPCOUNT;	//default 4;   //~v8@2I~
#ifdef UTF8SUPPH                                                   //~v78wI~//~va00R~
	  if (!(Popt & FPURO_CP))//no cp option specified              //~v78wI~//~va00I~
      {                                                            //~v78wI~//~va00I~
        if (prof.PROFcp!=' ')                                      //~v78wI~//~va00I~
        {                                                          //~v78wI~//~va00I~
        	setflag|=FPURO_CP;                                     //~v78wR~//~va00I~
        	if (prof.PROFcp==PROF_CPUTF8)                          //~v78wI~//~va00I~
				UCBITON(Ppfh->UFHflag8,UFHF8UTF8|UFHF8UTF8P);  //explicit utf8//~v78wI~//~va00I~
            else                                                   //~v78wI~//~va00I~
        	if (prof.PROFcp==PROF_CPLOCALE)                        //~v78wR~//~va00I~
				UCBITON(Ppfh->UFHflag8,UFHF8UTF8P);  //explicit non utf8//~v78wI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            else                                                   //~va50I~
        	if (prof.PROFcp==PROF_CPEBC)                           //~va50I~
				UCBITON(Ppfh->UFHflag10,UFHF10EBC|UFHF10EBCP);  //explicitly ebc//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            if (proffile.PROFcp==' ')                              //~va0sR~
            {                                                      //~va50I~
				UCBITOFF(Ppfh->UFHflag8,UFHF8UTF8P);  //not explicit//~va0sI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				UCBITOFF(Ppfh->UFHflag10,UFHF10EBCP);  //explicit ebc off//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            }                                                      //~va50I~
        }                                                          //~v78wI~//~va00I~
      }                                                            //~v78wI~//~va00I~
	  	if (!(Popt & FPURO_CVNAME))//no cvname option specified    //~va79I~
      	{                                                          //~va79I~
        	if (prof.PROFcp==PROF_CPEBC)                           //~va79I~
      			if (prof.PROFcvname[0]!=' ')                       //~va79I~
                {                                                  //~va79M~
                	memcpy(cvname,prof.PROFcvname,MAX_CSNAMESZ);   //~va79I~
                    pc=memchr(cvname,' ',MAX_CSNAMESZ);            //~va79R~
                    if (pc)                                        //~va79M~
                    {                                              //~va79M~
                    	*pc=0;                                     //~va79M~
                		if (!ucvebc4_createhandle(0,cvname,&handle))//~va79M~
                        {                                          //~va79I~
                        	Ppfh->UFHhandle=handle;                //~va79M~
        					setflag|=FPURO_CVNAME;                 //~va79I~
                        }                                          //~va79I~
                    }                                              //~va79M~
                }                                                  //~va79M~
		}                                                          //~va79I~
#endif                                                             //~v78wI~//~va00I~
	  if (!(Popt & FPURO_FNCP))//no cp option specified            //~vagEI~
      {                                                            //~vagEI~
        if (prof.PROFfncp!=' ')                                    //~vagEI~
        {                                                          //~vagEI~
        	setflag|=FPURO_FNCP;                                   //~vagEI~
        	if (prof.PROFfncp==PROF_FNCPUTF8)                      //~vagEI~
				UCBITON(Ppfh->UFHflag12,UFHF12FNU8);  //explicit utf8//~vagEI~
            else                                                   //~vagEI~
        	if (prof.PROFfncp==PROF_FNCPLOCALE)                    //~vagEI~
				UCBITON(Ppfh->UFHflag12,UFHF12FNLC);  //explicit non utf8//~vagEI~
        }                                                          //~vagEI~
      }                                                            //~vagEI~
	  if (!(Popt & FPURO_NUMSTD))//nonum option not specified on edit cmd//~v78rR~
      {                                                            //~v78rI~
        if (prof.PROFnumstd!=' ')                                  //~v78rR~
        {                                                          //~v78rI~
        	setflag|=FPURO_NUMSTD;                                 //~v78rI~
        	if (prof.PROFnumstd==PROF_NUMSTD)                      //~v78rI~
                spfsw=1;                                           //~v78rI~
        }                                                          //~v78rI~
      }//nonum option                                              //~v78rI~
	  if (!(Popt & FPURO_NUMCOB))//nonum option not specified on edit cmd//~v78rR~
      {                                                            //~v78rI~
        if (prof.PROFnumcob!=' ')                                  //~v78rM~
        {                                                          //~v78rM~
        	setflag|=FPURO_NUMCOB;                                 //~v78rM~
            setflag|=FPURO_NUMSTD;  //assume also cobnum           //~v78rI~
          if (prof.PROFnumcob!=PROF_NUMNOCOB)//explicitly not cobol//~v78rI~
          {                                                        //~v78rI~
            if (prof.PROFnumcob==PROF_NUMCOB)                      //~v78rM~
                UCBITON(Ppfh->UFHflag5,UFHF5COB);                  //~v78rM~
            else         //cobk                                    //~v78rR~
                UCBITON(Ppfh->UFHflag5,UFHF5COB|UFHF5COB2);        //~v78rM~
            if (prof.PROFnumstd!=PROF_NUMSTD)   //no NUM std       //~v78rI~
                UCBITON(Ppfh->UFHflag5,UFHF5NOAUTONUM); //col73-80 not use//~v78rI~
            spfsw=1;                                               //~v78rI~
          }                                                        //~v78rI~
        }                                                          //~v78rM~
      }//nonum option                                              //~v78rI~
        if (spfsw)                                                 //~v78rI~
        	filedefaultspf(Ppfh);                                  //~v78rI~
        if (prof.PROFoomprot!=' ')                                 //~v78rI~
        {                                                          //~v78rI~
        	setflag|=FPURO_OOMNOPROT;                              //~v78rI~
            if (prof.PROFoomprot==PROF_OOMNOPROT)                  //~v78rR~
                UCBITON(Ppfh->UFHflag3,UFHF3OOMNOPROT);            //~v78rI~
        }                                                          //~v78rI~
        if (prof.PROFtabclear!=' ')                                //~v78rR~
        {                                                          //~v78rI~
            setflag|=FPURO_TABCLEAR;                               ///~v78rI~
            if (prof.PROFtabclear==PROF_TABCLEAR)                  //~v78rI~
                UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);                  ///~v78rR~
        }                                                          //~v78rI~
        lrecl=                                                     //~va67I~
        numval=uatoin(prof.PROFlrecl,PROF_NUMFLDSZ);               //~v78rR~
	  if (!(Popt & FPURO_LRECL))//F0 option not specified on edit cmd//~v78rR~
      {                                                            //~v78rI~
        if (numval)                                                //~v78rI~
        {                                                          //~v78rI~
        	setflag|=FPURO_LRECL;                                  //~v78rI~
            Ppfh->UFHlrecl=(USHORT)numval;                         //~v78LR~
            UCBITON(Ppfh->UFHflag7,UFHF7FIXLRECL);                 //~v78rI~
		    UCBITON(Ppfh->UFHflag2,UFHF2MERGIN);                   //~v78rI~
	        numval=uatoin(prof.PROFmargin,PROF_NUMFLDSZ);          //~v78rI~
            Ppfh->UFHmergin=(USHORT)numval;                        //~v78LR~
            if (prof.PROFtabclear!=PROF_NOTABCLEAR)                //~v78rI~
        	  if (prof.PROFrecordmode!=PROF_RECORDMODE)	//tabskip=1 by record mode,no need to drop tab//~vajhI~
				UCBITON(Ppfh->UFHflag5,UFHF5DROPTAB);	//tab clear at save//~v78rI~
        }                                                          //~v78rI~
      }//edit option                                               //~v78rI~
        numval=lrecl;                                              //~va67I~
	  if (!(Popt & FPURO_RECORD))//F0 option not specified on edit cmd//~va51I~
      {                                                            //~va51I~
//      if (prof.PROFrecordmode!=' ' && numval)                    //~va51I~//~vaj0R~
        if (prof.PROFrecordmode==PROF_RECORDMODE && numval)        //~vaj0I~
        {                                                          //~va51I~
        	setflag|=FPURO_LRECL|FPURO_RECORD;                     //~va51I~
            Ppfh->UFHlrecl=(USHORT)numval;                         //~va51I~
            UCBITON(Ppfh->UFHflag7,UFHF7FIXLRECL);                 //~va51I~
		    UCBITON(Ppfh->UFHflag2,UFHF2MERGIN);                   //~va51I~
	        numval=uatoin(prof.PROFmargin,PROF_NUMFLDSZ);          //~va51I~
            Ppfh->UFHmergin=(USHORT)numval;                        //~va51I~
            UCBITON(Ppfh->UFHflag10,UFHF10RECORD);  //tab clear at save//~va51I~
        }                                                          //~va51I~
      }//edit option                                               //~va51I~
	  if (!(Popt & FPURO_RECORDV))// -Fvfmt option not specified on edit cmd//~vaj0R~
      {                                                            //~vaj0I~
        if (prof.PROFrecordmode==PROF_RECORDMODEV)                 //~vaj0R~
        {                                                          //~vaj0I~
    		if (!xefile5getparmlreclV(0,prof.PROFvfmt,&vfmttype))  //~vaj0I~
            {                                                      //~vaj0I~
        		setflag|=FPURO_RECORDV;                            //~vaj0I~
            	UCBITON(Ppfh->UFHflag13,UFHF13RV);                 //~vaj0I~
//          	Ppfh->UFHvfmt=-vfmttype;                           //~vaj0R~//~vb2CR~
            	Ppfh->UFHvfmt=(UCHAR)(-vfmttype);                  //~vb2CR~
            }                                                      //~vaj0I~
        }                                                          //~vaj0I~
      }//edit option                                               //~vaj0I~
        if (prof.PROFbnds1[PROF_NUMFLDSZ-1]!=' ')	//no value set //~v78rR~
        {                                                          //~v78rI~
            setflag|=FPURO_BNDS;                                   //~v78rI~
            numval=uatoin(prof.PROFbnds1,PROF_NUMFLDSZ);           //~v78rR~
            if (numval>0)                                          //~v78rR~
                Ppfh->UFHbndscol1=numval;                          //~v78rR~
            numval=uatoin(prof.PROFbnds2,PROF_NUMFLDSZ);           //~v78rR~
            if (numval>0)                                          //~v78rR~
                Ppfh->UFHbndscol2=numval;                          //~v78rR~
        }                                                          //~v78rI~
    }                                                              //~v78rI~
    if (Ppsetflag)                                                 //~v78rI~
    	*Ppsetflag=setflag;                                        //~v78rR~
	fcmdprof83q(4,0,0);		//free 83q                             //~v78LI~
    return rc;                                                     //~v78rI~
}//fcmdprofgetprofile                                              //~v78rI~
//**************************************************************** //~v78rM~
// fcmdprofgetprofilerecord                                        //~v78rI~
//  merge profile record                                           //~v78rI~
//**************************************************************** //~v78rM~
//int fcmdprofgetprofilerecord(PUFILEH Ppfh,PPROFILE Ppprof)         //~v78rI~//~va0sR~
int fcmdprofgetprofilerecord(PUFILEH Ppfh,PPROFILE Ppprof,PPROFILE Ppproffile)//~va0sI~
{                                                                  //~v78rM~
	char  fpath[_MAX_PATH],*pfnm;                                  //~v78rM~
	char  fpathext[_MAX_PATH];                                     //~v78rM~
	char  fpathpdir[_MAX_PATH];                                    //~v78rI~
    int pathlen,rc=0,rc1,rc2,rc3;                                  //~v78rR~
    PROFILE prof1,prof2,prof3;                                     //~v78rR~
    int opt;                                                       //~v78HI~
//************                                                     //~v78rM~
	pfnm=Ppfh->UFHfilename;                                        //~v78rI~
//  if (fcmdprofgetfnm(0,pfnm,fpath,fpathpdir,fpathext,&pathlen))  //~v78HR~
	opt=(FCPRRO_TSO)*(UCBITCHK(Ppfh->UFHflag7,UFHF7TSO)!=0);       //~v78HI~
    if (fcmdprofgetfnm(opt,pfnm,fpath,fpathpdir,fpathext,&pathlen))//~v78HI~
    	return 4;                                                  //~v78rI~
    memset(Ppproffile,' ',sizeof(prof1));	//if filerecord not found//~va0sI~
  if (WILDCARD(fpath))                                             //~va0rI~
  	rc1=4;                                                         //~va0rI~
  else                                                             //~va0rI~
	rc1=fcmdprofreadrecord(0,fpath,&prof1);   //fire record found  //~v78rR~
    if (!rc1)                                                      //~va0sI~
        memcpy(Ppproffile,&prof1,sizeof(prof1));	//return file record//~va0sM~
    if (pathlen)                                                   //~v78rI~
		rc2=fcmdprofreadrecord(0,fpathpdir,&prof2);                //~v78rR~
    else                                                           //~v78rI~
    	rc2=4;                                                     //~v78rI~
    if (*fpathext)                                                 //~v78rI~
		rc3=fcmdprofreadrecord(0,fpathext,&prof3);                 //~v78rR~
    else                                                           //~v78rI~
    	rc3=4;                                                     //~v78rR~
	if (!rc1)                                                      //~v78rI~
    {                                                              //~v78rI~
    	if (!rc2)                                                  //~v78rI~
			fcmdprofmergerecord(&prof1,&prof2);                    //~v78rR~
    }                                                              //~v78rI~
    else                                                           //~v78rI~
    {                                                              //~v78rI~
    	if (!rc2)                                                  //~v78rI~
            memcpy(&prof1,&prof2,PROFILESZ);                       //~v78rR~
        else                                                       //~v78rI~
            rc=4;                                                  //~v78rI~
    }                                                              //~v78rI~
    if (rc)	// no prof1 & no prof2                                 //~v78rI~
    {                                                              //~v78rI~
    	if (!rc3)   //ext record                                   //~v78rI~
        {                                                          //~v78rI~
            memcpy(&prof1,&prof3,PROFILESZ);                       //~v78rI~
            rc=0;                                                  //~v78rI~
        }                                                          //~v78rI~
    }                                                              //~v78rI~
    else                                                           //~v78rI~
    {                                                              //~v78rI~
    	if (!rc3)                                                  //~v78rI~
			fcmdprofmergerecord(&prof1,&prof3);                    //~v78rI~
    }                                                              //~v78rI~
    memcpy(Ppprof,&prof1,PROFILESZ);                               //~v78rI~
    return rc;                                                     //~v78rI~
}//fcmdprofgetprofilerecord                                        //~v78rI~
//**************************************************************** //~v78rI~
// fcmdprofmergerecord                                             //~v78rR~
//*read profile data                                               //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofmergerecord(PPROFILE Ppprof1,PPROFILE Ppprof2)         //~v78rR~
{                                                                  //~v78rI~
	char margerecordmode;                                          //~vaj0I~
//****************************                                     //~vaj0I~
    if (Ppprof1->PROFsynopen==' ')                                 //~v78rI~
        Ppprof1->PROFsynopen=Ppprof2->PROFsynopen;                 //~v78rI~
    if (Ppprof1->PROFsynenter==' ')                                //~v78rI~
        Ppprof1->PROFsynenter=Ppprof2->PROFsynenter;               //~v78rI~
    if (*Ppprof1->PROFsynlang==' ')                                //~v78rI~
        memcpy(Ppprof1->PROFsynlang,Ppprof2->PROFsynlang,sizeof(Ppprof1->PROFsynlang));//~v78rI~
    if (Ppprof1->PROFcaps==' ')                                    //~v78rI~
        Ppprof1->PROFcaps=Ppprof2->PROFcaps;                       //~v78rI~
    if (Ppprof1->PROFvhex==' ')                                    //~v78rI~
        Ppprof1->PROFvhex=Ppprof2->PROFvhex;                       //~v78rI~
    if (Ppprof1->PROFcols==' ')                                    //~v78rI~
        Ppprof1->PROFcols=Ppprof2->PROFcols;                       //~v78rI~
    if (Ppprof1->PROFcolstype[0]==' ')                             //~v78rI~
      if (Ppprof2->PROFcols==PROF_COLSON)	//dir is col on        //~vbs6I~
        memcpy(Ppprof1->PROFcolstype,Ppprof2->PROFcolstype,MAXCOLSTYPNM);//~v78rR~
#ifdef UTF8SUPPH                                                   //~v78wR~//~va00R~
    if (Ppprof1->PROFcp==' ')                                      //~v78wI~//~va00I~
        Ppprof1->PROFcp=Ppprof2->PROFcp;                           //~v78wI~//~va00I~
#endif                                                             //~v78wR~//~va00I~
    if (Ppprof1->PROFfncp==' ')                                    //~vagEI~
        Ppprof1->PROFfncp=Ppprof2->PROFfncp;                       //~vagEI~
    if (Ppprof1->PROFnumstd==' ')                                  //~v78rI~
        Ppprof1->PROFnumstd=Ppprof2->PROFnumstd;                   //~v78rI~
    if (Ppprof1->PROFtabclear==' ')                                //~v78rI~
        Ppprof1->PROFtabclear=Ppprof2->PROFtabclear;               //~v78rI~
    if (*Ppprof1->PROFtabctr==' ')                                 //~v8@2I~
        memcpy(Ppprof1->PROFtabctr,Ppprof2->PROFtabctr,sizeof(Ppprof1->PROFtabctr));//~v8@2I~
    if (Ppprof1->PROFoomprot==' ')                                 //~v78rI~
        Ppprof1->PROFoomprot=Ppprof2->PROFoomprot;                 //~v78rI~
    if (Ppprof1->PROFnumcob==' ')                                  //~v78rI~
        Ppprof1->PROFnumcob=Ppprof2->PROFnumcob;                   //~v78rI~
    margerecordmode=0;              //exclusive control for 'R' and 'V'//~vaj0I~
    if (Ppprof1->PROFrecordmode==' ')                              //~vaj0I~
        margerecordmode=Ppprof2->PROFrecordmode;                   //~vaj0I~
  if (margerecordmode!=PROF_RECORDMODEV)	//not recfm=V          //~vaj0I~
    if (Ppprof1->PROFlrecl[PROF_NUMFLDSZ-1]==' ')                  //~v78rR~
        memcpy(Ppprof1->PROFlrecl,Ppprof2->PROFlrecl,PROF_NUMFLDSZ);//~v78rR~
    if (Ppprof1->PROFrecordmode==' ')                              //~va51R~
        Ppprof1->PROFrecordmode=Ppprof2->PROFrecordmode;           //~va51R~
  if (margerecordmode==PROF_RECORDMODEV)	//recfm=V              //~vaj0R~
    if (*Ppprof1->PROFvfmt==' ')                                   //~vaj0I~
        memcpy(Ppprof1->PROFvfmt,Ppprof2->PROFvfmt,sizeof(Ppprof1->PROFvfmt));//~vaj0I~
  if (margerecordmode!=PROF_RECORDMODEV)	//not recfm=V          //~vaj0I~
  {                                                                //~vaj0I~
    if (Ppprof1->PROFmargin[PROF_NUMFLDSZ-1]==' ')                 //~v78rI~
        memcpy(Ppprof1->PROFmargin,Ppprof2->PROFmargin,PROF_NUMFLDSZ);//~v78rI~
  }                                                                //~vaj0I~
    if (Ppprof1->PROFbnds1[PROF_NUMFLDSZ-1]==' ')                  //~v78rR~
        memcpy(Ppprof1->PROFbnds1,Ppprof2->PROFbnds1,PROF_NUMFLDSZ);//~v78rR~
    if (Ppprof1->PROFbnds2[PROF_NUMFLDSZ-1]==' ')                  //~v78rR~
        memcpy(Ppprof1->PROFbnds2,Ppprof2->PROFbnds2,PROF_NUMFLDSZ);//~v78rR~
    return 0;                                                      //~v78rI~
}//fcmdprofmergerecord                                             //~v78rI~
//**************************************************************** //~v78rI~
// fcmdprofupdaterecord                                            //~v78rR~
//*read profile data                                               //~v78rI~
//*rc:1:no ext,4 err                                               //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofupdaterecord(ULONG Popt,char *Pfnm,char *Pstrval,int Pintval1,int Pintval2)//~v78rR~
{                                                                  //~v78rI~
	char  fpath[_MAX_PATH],*pfnm;                                  //~v78rR~
	char  fpathext[_MAX_PATH],numeditwk[16];                       //~v78rR~
    PROFILE prof;                                                  //~v78rI~
    int len,rc,funcid;                                             //~v78rR~
    int handle;                                                    //~va79I~
	char  *pcvname;                                                //~va79I~
	char  *vfmtstr;                                                //~vaj0I~
    int vfmt;                                                      //~vaj0I~
//************                                                     //~v78rI~
//  if (fcmdprofgetfnm(0,Pfnm,fpath,0,fpathext,0/*out pathlen*/))  //~va0rR~
    if (fcmdprofgetfnm(FCPRRO_WRITE,Pfnm,fpath,0,fpathext,0/*out pathlen*/))//~va0rI~
    	return 4;                                                  //~v78rI~
    if (Popt & FPURO_EXT)                                          //~v78rI~
    {                                                              //~v78rI~
    	pfnm=fpathext;                                             //~v78rI~
        if (!*pfnm)                                                //~v78rI~
        	return 1;                                              //~v78rI~
    }                                                              //~v78rI~
    else                                                           //~v78rI~
    if (*Pfnm=='.')	//extname                                      //~v78rR~
    	pfnm=fpathext;                                             //~v78rR~
    else                                                           //~v78rI~
    	pfnm=fpath;                                                //~v78rI~
	if (fcmdprofreadrecord(0,pfnm,&prof))	//not found            //~v78rR~
    	fcmdprofinitrecord(&prof);                                 //~v78rR~
    funcid=(int)(Popt & FPURO_FUNCMASK);                           //~v78LR~
    switch(funcid)                                                 //~v78rI~
    {                                                              //~v78rI~
    case FPURO_CAPS:                                               //~v78rR~
    	if (Pintval1==1)   //on                                    //~v78rR~
        	prof.PROFcaps=PROF_CAPSON;                             //~v78rR~
        else            //off                                      //~v78rI~
    	if (Pintval1==0)                                           //~v78rR~
        	prof.PROFcaps=PROF_CAPSOFF;                            //~v78rI~
        else              //reset                                  //~v78rR~
        	prof.PROFcaps=' ';                                     //~v78rR~
        break;                                                     //~v78rI~
    case FPURO_VHEX:                                               //~v78rI~
    	if (Pintval1==1)   //on                                    //~v78rI~
        	prof.PROFvhex=PROF_VHEXON;                             //~v78rI~
        else            //off                                      //~v78rI~
    	if (Pintval1==0)                                           //~v78rI~
        	prof.PROFvhex=PROF_VHEXOFF;                            //~v78rI~
        else              //reset                                  //~v78rI~
        	prof.PROFvhex=' ';                                     //~v78rI~
        break;                                                     //~v78rI~
    case FPURO_COLS:                                               //~v78rI~
        memset(prof.PROFcolstype,' ',MAXCOLSTYPNM);                //~v78rI~
    	if (Pintval1==1)   //on                                    //~v78rI~
        {                                                          //~v78rI~
            if (Pstrval)    //null for default                     //~v78rI~
            {                                                      //~v78rI~
	        	prof.PROFcols=PROF_COLSON;                         //~v78rI~
                len=(int)strlen(Pstrval);                          //~v78LR~
                len=min(len,MAXCOLSTYPNM);                         //~v78rI~
                memcpy(prof.PROFcolstype,Pstrval,(UINT)len);       //~v78rI~
            }                                                      //~v78rI~
            else                                                   //~v78rI~
            {                                                      //~v78rI~
	        	prof.PROFcols=PROF_COLSDEF;                        //~v78rI~
            }                                                      //~v78rI~
        }                                                          //~v78rI~
        else            //off                                      //~v78rI~
    	if (Pintval1==0)                                           //~v78rI~
        	prof.PROFcols=PROF_COLSOFF;                            //~v78rI~
        else              //reset                                  //~v78rI~
        	prof.PROFcols=' ';                                     //~v78rI~
        break;                                                     //~v78rI~
#ifdef UTF8SUPPH                                                   //~v78wI~//~va00R~
    case FPURO_CP:                                                 //~v78wI~//~va00I~
    	handle=Pintval2;                                           //~va79I~
    	if (Pintval1==1)                                           //~v78wI~//~va00I~
	        prof.PROFcp=PROF_CPUTF8;                               //~v78wI~//~va00I~
        else                                                       //~v78wI~//~va00I~
    	if (Pintval1==-1)                                          //~v78wI~//~va00I~
	        prof.PROFcp=PROF_CPLOCALE;                             //~v78wI~//~va00I~
        else                                                       //~v78wI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	if (Pintval1==-2)                                          //~va50I~
        {                                                          //~va79I~
	        prof.PROFcp=PROF_CPEBC;                                //~va50I~
            memset(prof.PROFcvname,' ',MAX_CSNAMESZ);              //~va79I~
            if (handle)                                            //~va79I~
            {                                                      //~va79I~
                pcvname=ucvebc4_getcvname(0,handle);               //~va79I~
                if (pcvname)                                       //~va79I~
                    memcpy(prof.PROFcvname,pcvname,strlen(pcvname));//~va79I~
            }                                                      //~va79I~
        }                                                          //~va79I~
        else                                                       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	        prof.PROFcp=' ';                                       //~v78wR~//~va00I~
        break;                                                     //~v78wI~//~va00I~
#endif                                                             //~v78wI~//~va00I~
    case FPURO_FNCP:                                               //~vagEI~
    	if (Pintval1==1)                                           //~vagEI~
	        prof.PROFfncp=PROF_FNCPUTF8;                           //~vagEI~
        else                                                       //~vagEI~
    	if (Pintval1==-1)                                          //~vagEI~
	        prof.PROFfncp=PROF_FNCPLOCALE;                         //~vagEI~
        else                                                       //~vagEI~
	        prof.PROFfncp=' ';                                     //~vagEI~
        break;                                                     //~vagEI~
	case FPURO_TABCTR:                                             //~v8@2I~
        if (Pintval1<=0)                                           //~v8@2I~
            memset(prof.PROFtabctr,' ',sizeof(prof.PROFtabctr));   //~v8@2I~
        else                                                       //~v8@2I~
        {                                                          //~v8@2I~
            sprintf(numeditwk,"%02d",Pintval1);                    //~v8@2I~
            memcpy(prof.PROFtabctr,numeditwk,sizeof(prof.PROFtabctr));//~v8@2I~
        }                                                          //~v8@2I~
        break;                                                     //~v8@2I~
	case FPURO_BNDS:                                               //~v78rI~
        if (Pintval1<0)                                            //~v78rI~
        {                                                          //~v78rI~
            memset(prof.PROFbnds1,' ',PROF_NUMFLDSZ);              //~v78rR~
            memset(prof.PROFbnds2,' ',PROF_NUMFLDSZ);              //~v78rR~
        }                                                          //~v78rI~
        else                                                       //~v78rI~
        {                                                          //~v78rI~
            unumedit((ULONG)Pintval1,PROF_NUMEDIT,numeditwk);      //~v78rR~
            memcpy(prof.PROFbnds1,numeditwk,PROF_NUMFLDSZ);        //~v78rR~
            unumedit((ULONG)Pintval2,PROF_NUMEDIT,numeditwk);      //~v78rR~
            memcpy(prof.PROFbnds2,numeditwk,PROF_NUMFLDSZ);        //~v78rR~
        }                                                          //~v78rI~
        break;                                                     //~v78rI~
	case FPURO_SYNOPEN:                                            //~v78rI~
    	if (Pintval1)                                              //~v78rI~
        	prof.PROFsynopen=PROF_SYNOPEN;                         //~v78rR~
        else                                                       //~v78rI~
        	prof.PROFsynopen=PROF_SYNNOOPEN;                       //~v78rR~
        if (Pstrval)                                               //~v78rI~
        {                                                          //~v78rI~
        	memset(prof.PROFsynlang,' ',sizeof(prof.PROFsynlang)); //~v78rI~
        	len=(int)strlen(Pstrval);                              //~v78LR~
//        	len=min(len,sizeof(prof.PROFsynlang));                 //~v78rI~//~vb2DR~
          	len=min(len,(int)sizeof(prof.PROFsynlang));            //~vb2DI~
        	memcpy(prof.PROFsynlang,Pstrval,(UINT)len);            //~v78rI~
        }                                                          //~v78rI~
        break;                                                     //~v78rI~
	case FPURO_SYNENTER:                                           //~v78rI~
    	if (Pintval1)                                              //~v78rI~
        	if (Pintval2)           //all                          //~v78rI~
        		prof.PROFsynenter=PROF_SYNENTERA;                  //~v78rR~
            else                                                   //~v78rI~
        		prof.PROFsynenter=PROF_SYNENTER;                   //~v78rR~
        else                                                       //~v78rI~
        	prof.PROFsynenter=' ';                                 //~v78rR~
        break;                                                     //~v78rI~
	case FPURO_RECORD:                                             //~va51I~
    	if (Pintval1)                                              //~va51I~
        	prof.PROFrecordmode=PROF_RECORDMODE;                   //~va51I~
        else                                                       //~va51I~
        	prof.PROFrecordmode=' ';                               //~va51I~
        unumedit((ULONG)(Pintval2>>16),PROF_NUMEDIT,numeditwk);    //~va51I~
        memcpy(prof.PROFlrecl,numeditwk,PROF_NUMFLDSZ);            //~va51I~
        unumedit((ULONG)(Pintval2&0xffff),PROF_NUMEDIT,numeditwk); //~va51I~
        memcpy(prof.PROFmargin,numeditwk,PROF_NUMFLDSZ);           //~va51I~
        memset(prof.PROFvfmt,' ',PROF_NUMFLDSZ);                   //~vaj0I~
        break;                                                     //~va51I~
	case FPURO_RECORDV:                                            //~vaj0I~
        prof.PROFrecordmode=PROF_RECORDMODEV;                      //~vaj0R~
        vfmt=Pintval2;                                             //~vaj0R~
        memset(prof.PROFvfmt,' ',sizeof(prof.PROFvfmt));           //~vaj0R~
        vfmtstr=ufile5getVfmtstr(0,vfmt);                          //~vaj0R~
        memcpy(prof.PROFvfmt,vfmtstr,strlen(vfmtstr));             //~vaj0I~
        memset(prof.PROFlrecl,' ',PROF_NUMFLDSZ);                  //~vaj0I~
        memset(prof.PROFmargin,' ',PROF_NUMFLDSZ);                 //~vaj0I~
        break;                                                     //~vaj0I~
	case FPURO_OOMNOPROT:                                          //~va5UR~
    	if (Pintval1)                                              //~va5UI~
        	prof.PROFoomprot=PROF_OOMPROT;                         //~va5UR~
        else                                                       //~va5UI~
        	prof.PROFoomprot=PROF_OOMNOPROT;                       //~va5UI~
        break;                                                     //~va5UI~
    }                                                              //~v78rI~
	if (fcmdprofwriterecord(pfnm,&prof))                           //~v78rI~
    	rc=4;                                                      //~v78rI~
    else                                                           //~v78rI~
    	rc=0;                                                      //~v78rI~
    return rc;                                                     //~v78rR~
}//fcmdputprofrecord                                               //~v78rI~
//**************************************************************** //~v78rI~
// fcmdprofupdaterecordcmd                                         //~v78rR~
//*read profile data                                               //~v78rI~
//*rc:1:no ext,4 err                                               //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofupdaterecordcmd(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PPROFILE Ppprof,char *Popd,int Popdno)//~v78rR~
{                                                                  //~v78rI~
    PUFILEC pfc;                                                   //~v78rI~
    int  ii,procopdctr,allsw=0,len;                                //~v78rR~
    char numeditwk[16],*pc;                                        //~v78rR~
    int  errsw;                                                    //~v78JI~
    char *vfmtstr;                                                 //~vaj0I~
//************                                                     //~v78rI~
    for (ii=0,procopdctr=0,pc=Popd;ii<Popdno;ii++,pc+=strlen(pc)+1)//~v78rR~
    {                                                              //~v78rI~
        errsw=1;                                                   //~v78JM~
//TC/NOTC                                                          //~v78rI~
        if (!stricmp(pc,"SAVE"))                                   //~v78rR~
        {                                                          //~v78rI~
            errsw=0;                                               //~v78JI~
            if (ii+1<Popdno)    //more operand                     //~v78rI~
            	continue;                                          //~v78rR~
            allsw=1;                                               //~v78rI~
        }                                                          //~v78rI~
        procopdctr++;                                              //~v78rI~
        if (!stricmp(pc,"RESET"))                                  //~v78rI~
        {                                                          //~v78rI~
            errsw=0;                                               //~v78JI~
        	allsw=0;                                               //~v78rI~
//          memset(Ppprof->PROFbyprofcmd,' ',PROFBYPROFCMDSZ);     //~v78rR~
    	 	memset(Ppprof,' ',PROFILESZ);                          //~v78rI~
            continue;                                              //~v78rI~
        }                                                          //~v78rI~
        if (!stricmp(pc,"ALL"))                                    //~v78rI~
        {                                                          //~v78JI~
            errsw=0;                                               //~v78JI~
            allsw=1;                                               //~v78rI~
        }                                                          //~v78JI~
//      if (allsw||!stricmp(pc,"TAB"))                             //~v8@2R~
        if (allsw||!stricmp(pc,"TABCLEAR"))                        //~v8@2I~
        {                                                          //~v78rR~
            if (!stricmp(pc,"TAB"))                                //~v78JI~
            	errsw=0;                                           //~v78JI~
            if (UCBITCHK(Ppfh->UFHflag5,UFHF5DROPTAB))  //tab clear at save//~v78rR~
                Ppprof->PROFtabclear=PROF_TABCLEAR;                //~v78rR~
            else                                                   //~v78rR~
            	if (Popt & FPURO_FILE)                             //~v78rI~
	                Ppprof->PROFtabclear=PROF_NOTABCLEAR;          //~v78rR~
                else                  //default profile            //~v78rI~
	                Ppprof->PROFtabclear=' ';                      //~v78rI~
        }                                                          //~v78rR~
        if (allsw||!stricmp(pc,"TABCTR"))                          //~v8@2I~
        {                                                          //~v8@2I~
            if (Ppfh->UFHtabskip)  //tab clear at save             //~v8@2I~
            {                                                      //~v8@2I~
                sprintf(numeditwk,"%02d",(int)Ppfh->UFHtabskip);   //~v8@2I~
	            memcpy(Ppprof->PROFtabctr,numeditwk,sizeof(Ppprof->PROFtabctr));//~v8@2I~
            }                                                      //~v8@2I~
            else                                                   //~v8@2I~
	            memset(Ppprof->PROFtabctr,' ',sizeof(Ppprof->PROFtabctr));//~v8@2I~
        }                                                          //~v8@2I~
        if (allsw||!stricmp(pc,"COLS"))                            //~v78rI~
        {                                                          //~v78rI~
            if (!stricmp(pc,"COLS"))                               //~v78JI~
            	errsw=0;                                           //~v78JI~
            pfc=Ppcw->UCWpfc;                                      //~v78rM~
            if (Ppcw->UCWfilehdrlineno>FILEHDRLINENO)  //tab clear at save//~v78rR~
            {                                                      //~v78rI~
            	if (UCBITCHK(pfc->UFCflag2,UFCF2NOTDEFCOLS))       //~v78rI~
                	Ppprof->PROFcols=PROF_COLSON;                  //~v78rR~
                else                                               //~v78rI~
                	Ppprof->PROFcols=PROF_COLSDEF;                 //~v78rI~
            }                                                      //~v78rI~
            else                                                   //~v78rI~
            	if (Popt & FPURO_FILE)                             //~v78rI~
	                Ppprof->PROFcols=PROF_COLSOFF;                 //~v78rI~
                else                  //default profile            //~v78rI~
	                Ppprof->PROFcols=' ';                          //~v78rI~
            memset(Ppprof->PROFcolstype,' ',MAXCOLSTYPNM);         //~v78rI~
            if (UCBITCHK(pfc->UFCflag2,UFCF2NOTDEFCOLS))           //~v78rR~
            {                                                      //~v78rI~
        		len=(int)strlen(pfc->UFCcolstype);                 //~v78rR~
        		memcpy(Ppprof->PROFcolstype,pfc->UFCcolstype,(UINT)len);//~v78rR~
            }                                                      //~v78rI~
        }                                                          //~v78rI~
#ifdef AAA  //already written at cmd                               //~vagEI~
#ifdef UTF8SUPPH                                                   //~v78wI~//~va00R~
        if (allsw||!stricmp(pc,"CP"))                              //~v78wI~//~va00I~
        {                                                          //~v78wI~//~va00I~
            if (!stricmp(pc,"CP"))                                 //~v78JI~//~va00I~
            	errsw=0;                                           //~v78JI~//~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
            if (UCBITCHK(Ppfh->UFHflag10,UFHF10EBC))               //~va50I~
	        	Ppprof->PROFcp=PROF_CPEBC;                         //~va50I~
            else                                                   //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8))                //~v78wR~//~va00I~
	        	Ppprof->PROFcp=PROF_CPUTF8;                        //~v78wI~//~va00I~
            else                                                   //~v78wI~//~va00I~
            if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8P))               //~v78wI~//~va00I~
	        	Ppprof->PROFcp=PROF_CPLOCALE;                      //~v78wI~//~va00I~
            else                                                   //~v78wI~//~va00I~
	        	Ppprof->PROFcp=' ';                                //~v78wI~//~va00I~
        }                                                          //~v78wI~//~va00I~
#endif                                                             //~v78wI~//~va00I~
#endif      //AAA                                                  //~vagEI~
        if (allsw||!stricmp(pc,"SYN"))                             //~v78rI~
        {                                                          //~v78rI~
            if (!stricmp(pc,"SYN"))                                //~v78JI~
            	errsw=0;                                           //~v78JI~
            if (Ppfh->UFHsynflag & UFHSF_ON)                       //~v78rR~
	        	Ppprof->PROFsynopen=PROF_SYNOPEN;                  //~v78rI~
            else                                                   //~v78rI~
            	if (Popt & FPURO_FILE)                             //~v78rI~
		        	Ppprof->PROFsynopen=PROF_SYNNOOPEN;            //~v78rR~
                else                                               //~v78rI~
		        	Ppprof->PROFsynopen=' ';                       //~v78rI~
			if (Ppfh->UFHsynflag & UFHSF_ENTERONUPDATELINEONLY)    //~v78rI~
	        	Ppprof->PROFsynenter=PROF_SYNENTER;                //~v78rR~
            else                                                   //~v78rI~
			if (Ppfh->UFHsynflag & UFHSF_ENTERON)                  //~v78rI~
        		Ppprof->PROFsynenter=PROF_SYNENTERA;               //~v78rR~
            else                                                   //~v78rI~
            	if (Popt & FPURO_FILE)                             //~v78rI~
        			Ppprof->PROFsynenter=PROF_SYNNOENTER;          //~v78rR~
                else                                               //~v78rI~
        			Ppprof->PROFsynenter=' ';                      //~v78rI~
            memset(Ppprof->PROFsynlang,' ',sizeof(Ppprof->PROFsynlang));//~v78rR~
		    if (*Ppfh->UFHsyntype)                                 //~v78rI~
            {                                                      //~v78rI~
        		len=(int)strlen(Ppfh->UFHsyntype);                 //~v78rI~
        		memcpy(Ppprof->PROFsynlang,Ppfh->UFHsyntype,(UINT)len);//~v78rR~
        	}                                                      //~v78rI~
        }                                                          //~v78rI~
        if (allsw||!stricmp(pc,"NUMFLD"))                          //~v78rR~
        {                                                          //~v78rR~
            if (!stricmp(pc,"NUMFLD"))                             //~v78JI~
            	errsw=0;                                           //~v78JI~
//NUMCOB                                                           //~v78rI~
            if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB2))                //~v78rR~
                Ppprof->PROFnumcob=PROF_NUMCOBK;                   //~v78rR~
            else                                                   //~v78rR~
            if (UCBITCHK(Ppfh->UFHflag5,UFHF5COB))                 //~v78rR~
                Ppprof->PROFnumcob=PROF_NUMCOB;                    //~v78rR~
            else                                                   //~v78rR~
            	if (Popt & FPURO_FILE)                             //~v78rI~
	                Ppprof->PROFnumcob=PROF_NUMNOCOB;              //~v78rR~
                else                                               //~v78rI~
	                Ppprof->PROFnumcob=' ';                        //~v78rI~
//NUMSTD                                                           //~v78rI~
            if (UCBITCHK(Ppfh->UFHflag7,UFHF7NONUMOPT))            //~v78rR~
                Ppprof->PROFnumstd=PROF_NONUMSTD;                  //~v78rR~
            else                                                   //~v78rR~
            if (Ppfh->UFHspfpos)                                   //~v78rR~
            {                                                      //~v78rR~
                if (UCBITCHK(Ppfh->UFHflag5,UFHF5NOAUTONUM))       //~v78rR~
                    Ppprof->PROFnumstd=PROF_NONUMSTD;              //~v78rR~
                else                                               //~v78rR~
                    Ppprof->PROFnumstd=PROF_NUMSTD;                //~v78rR~
            }                                                      //~v78rR~
            else                                                   //~v78rR~
            	if (Popt & FPURO_FILE)                             //~v78rI~
	                Ppprof->PROFnumstd=PROF_NONUMSTD;              //~v78rR~
                else                                               //~v78rI~
	                Ppprof->PROFnumstd=' ';                        //~v78rI~
//P0/P1                                                            //~v78rI~
            if (UCBITCHK(Ppfh->UFHflag3,UFHF3OOMNOPROT))           //~v78rR~
                Ppprof->PROFoomprot=PROF_OOMNOPROT;                //~v78rR~
            else                                                   //~v78rR~
            	if (Popt & FPURO_FILE)                             //~v78rI~
	                Ppprof->PROFoomprot=PROF_OOMPROT;              //~v78rR~
                else                                               //~v78rI~
	                Ppprof->PROFoomprot=' ';                       //~v78rI~
//Fnn-mm                                                           //~v78rR~
            Ppprof->PROFrecordmode=' ';                            //~va51I~
            if (UCBITCHK(Ppfh->UFHflag13,UFHF13RV)) //read recfm=V //~vaj0M~
            {                                                      //~vaj0I~
            	Ppprof->PROFrecordmode=PROF_RECORDMODEV;           //~vaj0M~
        		memset(Ppprof->PROFvfmt,' ',sizeof(Ppprof->PROFvfmt));//~vaj0R~
        		vfmtstr=ufile5getVfmtstr(0,Ppfh->UFHvfmt);         //~vaj0R~
        		memcpy(Ppprof->PROFvfmt,vfmtstr,strlen(vfmtstr));  //~vaj0R~
            }                                                      //~vaj0I~
            else                                                   //~vaj0M~
            if (UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL))            //~v78rR~
            {                                                      //~v78rR~
                unumedit((ULONG)Ppfh->UFHlrecl,PROF_NUMEDIT,numeditwk);//~v78rR~
                memcpy(Ppprof->PROFlrecl,numeditwk,PROF_NUMFLDSZ); //~v78rR~
                unumedit((ULONG)Ppfh->UFHmergin,PROF_NUMEDIT,numeditwk);//~v78rR~
                memcpy(Ppprof->PROFmargin,numeditwk,PROF_NUMFLDSZ);//~v78rR~
                if (UCBITCHK(Ppfh->UFHflag10,UFHF10RECORD))        //~va51I~
                    Ppprof->PROFrecordmode=PROF_RECORDMODE;        //~va51I~
            }                                                      //~v78rR~
            else                                                   //~v78rR~
            {                                                      //~v78rI~
                memset(Ppprof->PROFlrecl,' ',PROF_NUMFLDSZ);       //~v78rR~
                memset(Ppprof->PROFmargin,' ',PROF_NUMFLDSZ);      //~v78rI~
            }                                                      //~v78rI~
            if (UCBITCHK(Ppfh->UFHflag7,UFHF7NOFIXOPT)) //reset fix//~v78rR~
            {                                                      //~v78rR~
                unumedit(0,PROF_NUMEDIT,numeditwk);                //~v78rR~
                memcpy(Ppprof->PROFlrecl,numeditwk,PROF_NUMFLDSZ); //~v78rR~
                memcpy(Ppprof->PROFmargin,numeditwk,PROF_NUMFLDSZ);//~v78rR~
            }                                                      //~v78rR~
        }                                                          //~v78rR~
        if (errsw)                                                 //~v78JR~
            return errinvalid(pc);                                 //~v78JI~
    }//for                                                         //~v78rI~
    if (!procopdctr&&!allsw)                                       //~v78rR~
    	return errmissing();                                       //~v78rR~
    return 0;                                                      //~v78rI~
}//fcmdprofupdaterecordcmd                                         //~v78rI~
//**************************************************************** //~v78rI~
// fcmdprofwriterecord                                             //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofwriterecord(char *Pfnm,PPROFILE Ppprof)                //~v78rR~
{                                                                  //~v78rI~
	FILE *fh;                                                      //~v78rI~
    int len,rc=0;                                                  //~v78rR~
//*************************                                        //~v78rI~
    len=PROFILESZ-sizeof(Ppprof->PROFver);                         //~v78rI~
//*profile record is not utf8 file                                 //~va20I~
    if (umemspnc(Ppprof->PROFver+sizeof(Ppprof->PROFver),' ',(UINT)len)==(UINT)len)	//all space//~v78rR~
    {                                                              //~v78rI~
      if (fcmdprof83wd())                                          //~v78JI~
        rc=fcmdprof83io(FCPRRO_DEL,Pfnm,0);                        //~v78JR~
      else                                                         //~v78JI~
      {                                                            //~v78JI~
    	if (unlink(Pfnm))                                          //~v78rI~
        	if (errno!=ENOENT)                                     //~v78rI~
		    	rc=ufileapierr("unlink",Pfnm,errno);               //~v78rI~
      }                                                            //~v78JI~
        return rc;                                                 //~v78rI~
    }                                                              //~v78rI~
    memcpy(Ppprof->PROFver,PROF_VERSION,sizeof(Ppprof->PROFver));  //~v78LR~
  if (fcmdprof83wd())                                              //~v78LR~
    rc=fcmdprof83io(FCPRRO_PUT,Pfnm,Ppprof);                       //~v78LR~
  else                                                             //~v78LR~
  {                                                                //~v78LR~
    fh=fopen(Pfnm,"w");                                            //~v78rR~
    if (!fh)                                                       //~v78rI~
    	return ufileapierr("fopen",Pfnm,errno);                    //~v78rI~
//  memcpy(Ppprof->PROFver,PROF_VERSION,sizeof(Ppprof->PROFver));  //~v78JR~
    len=(int)fwrite(Ppprof,1,PROFILESZ,fh);                        //~v78LR~
    if (len!=PROFILESZ)                                            //~v78rR~
    	rc=ufileapierr("fwrite",Pfnm,errno);                       //~v78rI~
    fclose(fh);                                                    //~v78rI~
  }                                                                //~v78LR~
    return rc;                                                     //~v78rI~
}//fcmdprofwriterecord                                             //~v78rI~
//**************************************************************** //~v78rI~
// fcmdprofgetfnm                                                  //~v78rI~
//*get profile data filename                                       //~v78rR~
//*rc:4 err:mkdir fail                                             //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofgetfnm(int Popt,char *Pinpfnm,char *Poutfnm,char *Poutpdirfnm,char *Poutextfnm,int *Pppathlen)//~v78rR~
{                                                                  //~v78rI~
	char  fpath[_MAX_PATH+_MAX_PATH];                              //~v78rR~
	char  *pinpfnm;                                                //~vb57R~
	char  fpathext[_MAX_PATH+_MAX_PATH],*pci,*pco,*plastext=0,*plastpath=0;//~v78rI~
	char  fpathpdir[_MAX_PATH+_MAX_PATH];                          //~v78rR~
    int len,pathlen;                                               //~v78rR~
#ifdef W32UNICODE                                                  //~vb57I~
    int outlen;                                                    //~vb57I~
	char  fpathUD[_MAX_PATH+_MAX_PATH],*plastextention;            //~vb57I~
#endif                                                             //~vb57I~
    int lastquotesw=0;                                             //~v79mR~
    FILEFINDBUF3 fstat3;                                           //~v78rI~
#ifdef FTPSUPP                                                     //~v79mI~
    PUFTPHOST puftph;                                              //~v8@LR~
    int tsosw;                                                     //~v8@LI~
#endif                                                             //~v79mI~
#ifdef W32                                                         //~vb7mI~
	int posfnm;                                                    //~vb7mI~
#endif                                                             //~vb7mI~
//************                                                     //~v78rI~
#ifdef FTPSUPP                                                     //~v79mI~
	tsosw=(Popt & FCPRRO_TSO);                                     //~v8@LI~
    if (!tsosw)                                                    //~v8@LI~
        tsosw=(uftpisremote(Pinpfnm,&puftph) && UFTPHISTSO(puftph));//~v8@LI~
#endif                                                             //~v79mI~
	if (Popt & FCPRRO_WRITE)                                       //~va0rI~
    	if (WILDCARD(Pinpfnm))                                     //~va0rI~
        	return 4;                                              //~va0rI~
	len=sprintf(fpath,"%s%s",Gworkdir,PROF_SUBDIR);                //~v78rR~
    if (ufstat(fpath,&fstat3))                                     //~v78rI~
    {                                                              //~v78rI~
        if (umkdir(fpath))                                         //~v78rR~
        	return 4;                                              //~v78rI~
    }                                                              //~v78rI~
    else                                                           //~v78rI~
    {                                                              //~v78rI~
        if (!(fstat3.attrFile & FILE_DIRECTORY))                   //~v78rI~
        {                                                          //~v78rI~
            uerrmsg("same name file exist as profile work dir(%s)",0,//~v78rI~
                    fpath);                                        //~v78rI~
            return 4;                                              //~v78rI~
        }                                                          //~v78rI~
    }                                                              //~v78rI~
//#ifdef W32UNICODE                                                //~vb7bR~
    *(fpath+len++)=DIR_SEPC;                                       //~v78rI~
#ifdef W32                                                         //~vb7mI~
    posfnm=len;                                                    //~vb7mI~
#endif                                                             //~vb7mI~
#ifdef W32UNICODE                                                  //~vb7bI~
    if (ufilesplitUDbyLastExtention(0,Pinpfnm,0/*len by strlen*/,fpathUD,sizeof(fpathUD),&outlen,&plastextention)==1)//~vb57R~
    	pinpfnm=fpathUD;                                           //~vb57I~
    else                                                           //~vb57I~
#endif                                                             //~vb57I~
        pinpfnm=Pinpfnm;                                           //~vb57I~
//  for (pco=fpath+len,pci=Pinpfnm;*pci;pci++)                     //~vb57R~
    for (pco=fpath+len,pci=pinpfnm;*pci;pci++)                     //~vb57I~
    {                                                              //~v78rI~
    	if (*pci==DIR_SEPC                                         //~v78rI~
#ifdef FTPSUPP                                                     //~v78rI~
			||*pci==FTP_DIR_SEPC                                   //~v78rR~
//          ||( (Popt & FCPRRO_TSO) && *pci=='(' )                 //~v8@LR~
            ||( (tsosw) && *pci=='(' )                             //~v8@LI~
#endif                                                             //~v78rI~
#ifndef UNX                                                        //~v78rI~
			||*pci==':'                                            //~v78rI~
#endif                                                             //~v78rI~
		)                                                          //~v78rI~
        {                                                          //~v78rI~
            plastpath=pco;                                         //~v78rM~
        	*pco++=PROF_DELM;                                      //~v78rI~
            plastext=0;                                            //~v78rI~
        }                                                          //~v78rI~
        else                                                       //~v78rI~
        {                                                          //~v78rI~
         	if (*pci=='.')                                         //~v78rI~
            {                                                      //~v78rI~
            	plastext=pci;                                      //~v78rI~
                *pco++=PROF_DELM2;                                 //~v78rI~
            }                                                      //~v78rI~
            else                                                   //~v78rI~
         	if (*pci==' ')                                         //~v78rI~
	        	*pco++=PROF_DELM3;                                 //~v78rI~
            else                                                   //~v78rI~
	        	*pco++=*pci;                                       //~v78rR~
        }                                                          //~v78rI~
    }                                                              //~v78rI~
    *pco=0;                                                        //~v78rI~
#ifdef FTPSUPP                                                     //~v79mI~
	if (tsosw)                                                     //~v8@LR~
    {                                                              //~v79mR~
        strupr(fpath+len);                                         //~v8@LR~
        lastquotesw=(*(pci-1)=='\'');                              //~v79mR~
    }                                                              //~v79mR~
#endif                                                             //~v79mI~
    strncpy(Poutfnm,fpath,_MAX_PATH);                              //~v78rI~
    if (strlen(fpath)>=_MAX_PATH)                                  //~vb79I~
        return 4;                                                  //~vb79I~
    if (plastpath)                                                 //~v78rI~
//    	pathlen=(int)((ULONG)plastpath-(ULONG)fpath);              //~v78rI~//~vafkR~
    	pathlen=(int)((ULPTR)plastpath-(ULPTR)fpath);              //~vafkI~
    else                                                           //~v78rI~
    	pathlen=0;                                                 //~v78rI~
    if (Pppathlen)                                                 //~v78rI~
//	    *Pppathlen=pathlen;                                        //~v79mR~
  	    *Pppathlen=pathlen+lastquotesw;                            //~v79mR~
    if (Poutextfnm)                                                //~v78rI~
    {                                                              //~v78rI~
    	if (plastext)	//filename has extention                   //~v78rI~
        {                                                          //~v78rI~
        	memcpy(fpathext,fpath,(UINT)len);	//prof subdir      //~v78rI~
            pco=fpathext+len;                                      //~v78rI~
            len=(int)strlen(plastext);                             //~v78rI~
//#ifdef W32UNICODE  // ufilesplitUDbyLastExtention do good        //~vb57R~
//            if (len && *(plastext+len-1)==UD_NOTLC) //enclosing UTF8SUBC//~vb57R~
//                len--;                                           //~vb57R~
//#endif                                                           //~vb57R~
        	memcpy(pco,plastext,(UINT)len);                        //~v78rR~
            pco+=len;                                              //~v78rI~
            *pco++=PROF_DELM;                                      //~v78rI~
            *pco=0;                                                //~v78rI~
		    strncpy(Poutextfnm,fpathext,_MAX_PATH);                //~v78rI~
        }                                                          //~v78rI~
        else                                                       //~v78rI~
		    *Poutextfnm=0;                                         //~v78rI~
    }                                                              //~v78rI~
    if (Poutpdirfnm)                                               //~v78rR~
    {                                                              //~v78rI~
    	if (plastpath)	//input contains path                      //~v78rR~
        {                                                          //~v78rI~
            memcpy(fpathpdir,fpath,(UINT)pathlen);    //profdir+filepath//~v78rR~
            if (lastquotesw) //tso last "'"                        //~v79mR~
            	*(fpathpdir+pathlen++)='\'';                       //~v79mR~
            *(fpathpdir+pathlen)=0;                                //~v78rI~
            strncpy(Poutpdirfnm,fpathpdir,_MAX_PATH);              //~v78rR~
        }                                                          //~v78rI~
        else                                                       //~v78rI~
            *Poutpdirfnm=0;                                        //~v78rR~
    }                                                              //~v78rI~
#ifdef W32                                                         //~vb7mI~
    if (!tsosw)                                                    //~vb7mI~
    	fcmdprofgetfnmShort(Popt,pinpfnm,Poutfnm,Poutpdirfnm,Pppathlen,posfnm);//~vb7mR~
#endif                                                             //~vb7mI~
    return 0;                                                      //~v78rI~
}//fcmdprofgetfnm                                                  //~v78rI~
#ifdef W32                                                         //~vb7mI~
//**************************************************************** //~v78rI~//~vb7mI~
// fcmdprofgetfnm                                                  //~v78rI~//~vb7mI~
//*get profile data filename                                       //~v78rR~//~vb7mI~
//*rc:4 err:mkdir fail                                             //~v78rI~//~vb7mI~
//**************************************************************** //~v78rI~//~vb7mI~
int fcmdprofgetfnmShort(int Popt,char *Pinpfnm,char *Poutfnm,char *Poutpdirfnm,int *Pppathlen,int Pposfnm)//~v78rR~//~vb7mR~
{                                                                  //~v78rI~//~vb7mI~
//  char  fpath[_MAX_PATH+_MAX_PATH];                              //~v78rR~//~vb7mR~
	char  *pinpfnm;                                                //~vb57R~//~vb7mR~
    char  *pci,*pco/*,*plastext=0*/,*plastpath=0;                  //~vb7mR~
    int len,pathlen;                                               //~v78rR~//~vb7mI~
    char wkshortpath[_MAX_PATH],*profname;                         //~vb7mR~
    int lenshortfpath;                                             //~vb7mR~
//************                                                     //~v78rI~//~vb7mI~
//    tsosw=(Popt & FCPRRO_TSO);                                     //~v8@LI~//~vb7mR~
//    if (!tsosw)                                                    //~v8@LI~//~vb7mR~
//        tsosw=(uftpisremote(Pinpfnm,&puftph) && UFTPHISTSO(puftph));//~v8@LI~//~vb7mR~
//    if (Popt & FCPRRO_WRITE)                                       //~va0rI~//~vb7mR~
//        if (WILDCARD(Pinpfnm))                                     //~va0rI~//~vb7mR~
//            return 4;                                              //~va0rI~//~vb7mR~
//    len=sprintf(fpath,"%s%s",Gworkdir,PROF_SUBDIR);                //~v78rR~//~vb7mR~
//    if (ufstat(fpath,&fstat3))                                     //~v78rI~//~vb7mR~
//    {                                                              //~v78rI~//~vb7mR~
//        if (umkdir(fpath))                                         //~v78rR~//~vb7mR~
//            return 4;                                              //~v78rI~//~vb7mR~
//    }                                                              //~v78rI~//~vb7mR~
//    else                                                           //~v78rI~//~vb7mR~
//    {                                                              //~v78rI~//~vb7mR~
//        if (!(fstat3.attrFile & FILE_DIRECTORY))                   //~v78rI~//~vb7mR~
//        {                                                          //~v78rI~//~vb7mR~
//            uerrmsg("same name file exist as profile work dir(%s)",0,//~v78rI~//~vb7mR~
//                    fpath);                                        //~v78rI~//~vb7mR~
//            return 4;                                              //~v78rI~//~vb7mR~
//        }                                                          //~v78rI~//~vb7mR~
//    }                                                              //~v78rI~//~vb7mR~
//    *(fpath+len++)=DIR_SEPC;                                       //~v78rI~//~vb7mR~
//    posfnm=len;                                                  //~vb7mR~
//    if (ufilesplitUDbyLastExtention(0,Pinpfnm,0/*len by strlen*/,fpathUD,sizeof(fpathUD),&outlen,&plastextention)==1)//~vb57R~//~vb7mR~
//        pinpfnm=fpathUD;                                           //~vb57I~//~vb7mR~
//    else                                                           //~vb57I~//~vb7mR~
//        pinpfnm=Pinpfnm;                                           //~vb57I~//~vb7mR~
    pinpfnm=Pinpfnm;                                               //~vb7mI~
    profname=Poutfnm+Pposfnm;                                      //~vb7mR~
    len=(int)strlen(profname);                                     //~vb7mR~
	if (len<MAXFILENAMEZWC)    //char count <256(<=255)            //~vb7mI~
    	return 0;              //no need                           //~vb7mI~
	lenshortfpath=ugetshortpathname(pinpfnm,wkshortpath,sizeof(wkshortpath));//~vb7mR~
	UTRACEP("%s:uGetShortPathName rc=ctr=%d\n",UTT,lenshortfpath); //~vb7mI~
    if (!lenshortfpath)                                            //~vb7mR~
    	return 0;                                                  //~vb7mI~
    if (lenshortfpath>=MAXFILENAMEZWC)    //not effective          //~vb7mI~
    	return 0;                                                  //~vb7mI~
	UTRACED("shortname",wkshortpath,lenshortfpath);                //~vb7mR~
    pinpfnm=wkshortpath;                                           //~vb7mR~
//  for (pco=fpath+len,pci=pinpfnm;*pci;pci++)                     //~vb57I~//~vb7mR~
    for (pco=profname,pci=pinpfnm;*pci;pci++)                      //~vb7mI~
    {                                                              //~v78rI~//~vb7mI~
    	if (*pci==DIR_SEPC                                         //~v78rI~//~vb7mI~
			||*pci==FTP_DIR_SEPC                                   //~v78rR~//~vb7mI~
//            ||( (tsosw) && *pci=='(' )                             //~v8@LI~//~vb7mR~
//#ifndef UNX                                                        //~v78rI~//~vb7mR~
			||*pci==':'                                            //~v78rI~//~vb7mI~
//#endif                                                             //~v78rI~//~vb7mR~
		)                                                          //~v78rI~//~vb7mI~
        {                                                          //~v78rI~//~vb7mI~
            plastpath=pco;                                         //~v78rM~//~vb7mI~
        	*pco++=PROF_DELM;                                      //~v78rI~//~vb7mI~
//          plastext=0;                                            //~v78rI~//~vb7mR~
        }                                                          //~v78rI~//~vb7mI~
        else                                                       //~v78rI~//~vb7mI~
        {                                                          //~v78rI~//~vb7mI~
         	if (*pci=='.')                                         //~v78rI~//~vb7mI~
            {                                                      //~v78rI~//~vb7mI~
//          	plastext=pci;                                      //~v78rI~//~vb7mR~
                *pco++=PROF_DELM2;                                 //~v78rI~//~vb7mI~
            }                                                      //~v78rI~//~vb7mI~
            else                                                   //~v78rI~//~vb7mI~
         	if (*pci==' ')                                         //~v78rI~//~vb7mI~
	        	*pco++=PROF_DELM3;                                 //~v78rI~//~vb7mI~
            else                                                   //~v78rI~//~vb7mI~
	        	*pco++=*pci;                                       //~v78rR~//~vb7mI~
        }                                                          //~v78rI~//~vb7mI~
    }                                                              //~v78rI~//~vb7mI~
    *pco=0;                                                        //~v78rI~//~vb7mI~
//    if (tsosw)                                                     //~v8@LR~//~vb7mR~
//    {                                                              //~v79mR~//~vb7mR~
//        strupr(fpath+len);                                         //~v8@LR~//~vb7mR~
//        lastquotesw=(*(pci-1)=='\'');                              //~v79mR~//~vb7mR~
//    }                                                              //~v79mR~//~vb7mR~
//    strncpy(Poutfnm,fpath,_MAX_PATH);                              //~v78rI~//~vb7mR~
//    if (strlen(fpath)>=_MAX_PATH)                                  //~vb79I~//~vb7mR~
//        return 4;                                                  //~vb79I~//~vb7mR~
    if (plastpath)                                                 //~v78rI~//~vb7mI~
//    	pathlen=(int)((ULPTR)plastpath-(ULPTR)fpath);              //~vafkI~//~vb7mR~
    	pathlen=PTRDIFF(plastpath,Poutfnm);                        //~vb7mI~
    else                                                           //~v78rI~//~vb7mI~
    	pathlen=0;                                                 //~v78rI~//~vb7mI~
    if (Pppathlen)                                                 //~v78rI~//~vb7mI~
//  	    *Pppathlen=pathlen+lastquotesw;                            //~v79mR~//~vb7mR~
  	    *Pppathlen=pathlen;                                        //~vb7mI~
//    if (Poutextfnm)                                                //~v78rI~//~vb7mR~
//    {                                                              //~v78rI~//~vb7mR~
//        if (plastext)   //filename has extention                   //~v78rI~//~vb7mR~
//        {                                                          //~v78rI~//~vb7mR~
//            memcpy(fpathext,fpath,(UINT)len);   //prof subdir      //~v78rI~//~vb7mR~
//            pco=fpathext+len;                                      //~v78rI~//~vb7mR~
//            len=(int)strlen(plastext);                             //~v78rI~//~vb7mR~
//            memcpy(pco,plastext,(UINT)len);                        //~v78rR~//~vb7mR~
//            pco+=len;                                              //~v78rI~//~vb7mR~
//            *pco++=PROF_DELM;                                      //~v78rI~//~vb7mR~
//            *pco=0;                                                //~v78rI~//~vb7mR~
//            strncpy(Poutextfnm,fpathext,_MAX_PATH);                //~v78rI~//~vb7mR~
//        }                                                          //~v78rI~//~vb7mR~
//        else                                                       //~v78rI~//~vb7mR~
//            *Poutextfnm=0;                                         //~v78rI~//~vb7mR~
//    }                                                              //~v78rI~//~vb7mR~
    if (Poutpdirfnm)                                               //~v78rR~//~vb7mI~
    {                                                              //~v78rI~//~vb7mI~
    	len=(int)strlen(Poutpdirfnm);                              //~vb7mR~
      if (len>=MAXFILENAMEZWC)    //not effective                  //~vb7mI~
      {                                                            //~vb7mI~
    	if (plastpath)	//input contains path                      //~v78rR~//~vb7mI~
        {                                                          //~v78rI~//~vb7mI~
//          memcpy(fpathpdir,fpath,(UINT)pathlen);    //profdir+filepath//~v78rR~//~vb7mR~
//            if (lastquotesw) //tso last "'"                        //~v79mR~//~vb7mR~
//                *(fpathpdir+pathlen++)='\'';                       //~v79mR~//~vb7mR~
//          *(fpathpdir+pathlen)=0;                                //~v78rI~//~vb7mR~
//          strncpy(Poutpdirfnm,fpathpdir,_MAX_PATH);              //~v78rR~//~vb7mR~
            UmemcpyZ(Poutpdirfnm,Poutfnm,(size_t)pathlen);         //~vb7mR~
        }                                                          //~v78rI~//~vb7mI~
        else                                                       //~v78rI~//~vb7mI~
            *Poutpdirfnm=0;                                        //~v78rR~//~vb7mI~
      }                                                            //~vb7mI~
    }                                                              //~v78rI~//~vb7mI~
    return 0;                                                      //~v78rI~//~vb7mI~
}//fcmdprofgetfnmShort                                                  //~v78rI~//~vb7mR~
#endif                                                             //~vb7mI~
//**************************************************************** //~v78rI~
// fcmdprofreadrecord                                              //~v78rR~
//*read profile data                                               //~v78rI~
//*rc=4:not found,1:version err                                    //~v78rI~
//**************************************************************** //~v78rI~
int fcmdprofreadrecord(int Popt,char *Pfnm,PPROFILE Ppprofile)     //~v78rR~
{                                                                  //~v78rI~
    FILE *fh;                                                      //~v78rI~
    int len,rc=0;                                                  //~v78rR~
//****************                                                 //~v78rI~
    memset(Ppprofile,' ',PROFILESZ);                               //~v78rM~
  if (fcmdprof83wd())                                              //~v78LR~
    rc=fcmdprof83io(Popt|FCPRRO_GET,Pfnm,Ppprofile);               //~v78LR~
  else                                                             //~v78LR~
  {                                                                //~v78LR~
    fh=fopen(Pfnm,"r");                                            //~v78rI~
    if (!fh)                                                       //~v78rI~
    {                                                              //~v78rI~
    	if (Popt & FCPRRO_MSG)                                     //~v78rI~
        	uerrmsg("profile record(%s) not found",0,              //~v78rM~
            		Pfnm);                                         //~v78rR~
    	return 4;                                                  //~v78rI~
    }                                                              //~v78rI~
    len=(int)fread(Ppprofile,1,PROFILESZ,fh);                      //~v78LR~
//  if (len>=PROFILESZV1                                           //~vb71R~
    if (len>=(int)PROFILESZV1                                      //~vb71I~
	&& !memcmp(Ppprofile->PROFver,PROF_VERSION01,sizeof(Ppprofile->PROFver))//~va79I~
    )                                                              //~va79I~
    {                                                              //~va79I~
        ;                                                          //~va79I~
    }                                                              //~va79I~
    else                                                           //~va79I~
    if ((len!=PROFILESZ)                                           //~v78rR~
    ||  memcmp(Ppprofile->PROFver,PROF_VERSION,sizeof(Ppprofile->PROFver)))//~v78rI~
    {                                                              //~v78rI~
    	if (Popt & FCPRRO_MSG)                                     //~v78rI~
        	uerrmsg("profile record(%s) length err(old version)",0,//~v78rI~
            		Pfnm);                                         //~v78rR~
    	rc=1;                                                      //~v78rR~
    }                                                              //~v78rI~
    fclose(fh);                                                    //~v78rI~
  }                                                                //~v78LR~
    return rc;                                                     //~v78rI~
}//fcmdprofreadrecord                                              //~v78rR~
//**************************************************************** //~v78rM~
// fcmdprofinitrecord                                              //~v78rI~
//**************************************************************** //~v78rM~
int fcmdprofinitrecord(PPROFILE Ppprof)                            //~v78rI~
{                                                                  //~v78rI~
//****************                                                 //~v78rM~
	memset(Ppprof,' ',PROFILESZ);                                  //~v78rR~
    memcpy(Ppprof->PROFver,PROF_VERSION,sizeof(Ppprof->PROFver));  //~v78rR~
    return 0;                                                      //~v78rI~
}//fcmdgetprofrecord                                               //~v78rM~
//**************************************************************** //~v78LR~
// fcmdprof83wd                                                    //~v78LR~
//   chk workdir is LFN: rc=1:8.3filename                          //~v78LR~
//**************************************************************** //~v78LR~
int fcmdprof83wd(void)                                             //~v78LR~
{                                                                  //~v78LR~
    int rc;                                                        //~v78LR~
#ifdef OS2                                                         //~v78LR~
    static int Snothpfs=-1;                                        //~v78LR~
#endif                                                             //~v78LR~
//**************                                                   //~v78LR~
#ifdef DOS                                                         //~v78LR~
    rc=1;                                                          //~v78LR~
#else                                                              //~v78LR~
    #ifdef OS2                                                     //~v78LR~
        if (Snothpfs<0) //not yet chked                            //~v78LR~
            rc=Snothpfs=(ufileishpfs(*Gworkdir)!=1);               //~v78LR~
        else                                                       //~v78LR~
            rc=Snothpfs;                                           //~v78LR~
    #else                                                          //~v78LR~
#ifndef AAA                                                        //~v78LR~
        rc=0;     //LFN                                            //~v78LR~
#else                                                              //~v78LR~
        rc=1;     //not LFN test                                   //~v78LR~
#endif                                                             //~v78LR~
    #endif                                                         //~v78LR~
#endif                                                             //~v78LR~
    return rc;                                                     //~v78LR~
}//fcmdprof83                                                      //~v78LR~
//**************************************************************** //~v78LR~
// fcmdprof83io                                                    //~v78LR~
//   read/write profile record under 8.3 filename environment      //~v78LR~
//**************************************************************** //~v78LR~
int fcmdprof83io(int Popt,char *Pfnm,PPROFILE Ppprofile)           //~v78LR~
{                                                                  //~v78LR~
    FILE *fh;                                                      //~v78LR~
    int rc,pathlen,swfound=0,proflen;                              //~v78LR~
    char proffnm[_MAX_PATH],*profname,*pc;                         //~v78LR~
    char buff[_MAX_PATH+PROFILESZ];                                //~v78LR~
    PPROFQE pprofqe,pprofqefound;                                  //~v78LR~
//************************                                         //~v78LR~
    pathlen=PATHLEN(Pfnm);                                         //~v78LR~
    if (pathlen<=0)                                                //~v78LR~
        return 4;      //internal err                              //~v78LR~
    profname=Pfnm+pathlen;                                         //~v78LR~
    proflen=(int)strlen(profname); //profile record name length    //~v78LR~
    memcpy(proffnm,Pfnm,(UINT)pathlen);                            //~v78LR~
    sprintf(proffnm+pathlen,PROF_83FNM,OSTYPE); //  "profile.%c"   //~v78LR~
    if (!fcmdprof83q(3,0,0))	//no record                        //~v78LI~
    {                                                              //~v78LI~
		rc=fcmdprof83ioread(0,proffnm);                            //~v78LI~
        if (rc==UALLOC_FAILED)                                     //~v78LI~
        	return UALLOC_FAILED;                                  //~v78LI~
    }                                                              //~v78LI~
    pprofqe=fcmdprof83iosrch(0,profname,proflen);                  //~v78LR~
    if (Popt & FCPRRO_GET)                                         //~v78LR~
    {                                                              //~v78LR~
        if (!pprofqe)                                              //~v78LR~
        {                                                          //~v78LR~
            if (Popt & FCPRRO_MSG)                                 //~v78LR~
                uerrmsg("profile record(%s) not found in %s",0,    //~v78LR~
                    profname,proffnm);                             //~v78LR~
            rc=4;                                                  //~v78LR~
        }                                                          //~v78LR~
        else                                                       //~v78LI~
        {                                                          //~v78LI~
        	memcpy(Ppprofile,pprofqe->PRQEbuff+pprofqe->PRQEnamelen+1,PROFILESZ);//~v78LR~
            rc=0;                                                  //~v78LI~
        }                                                          //~v78LI~
        return rc;                                                 //~v78LR~
    }                                                              //~v78LR~
    fh=fopen(proffnm,"w");                                         //~v78LR~
    if (!fh)                                                       //~v78LR~
        return ufileapierr("fopen",proffnm,errno);                 //~v78LR~
    swfound=(pprofqe!=0);                                          //~v78LI~
    pprofqefound=pprofqe;                                          //~v78LI~
    for (;;)                                                       //~v78LR~
    {                                                              //~v78LR~
        if (!swfound)  //new record                                //~v78LR~
        {                                                          //~v78LI~
            pprofqe=0;                                             //~v78LR~
            swfound=2;	//enq                                      //~v78LI~
        }                                                          //~v78LI~
        else                                                       //~v78LR~
        {                                                          //~v78LR~
            pprofqe=fcmdprof83q(2/*deq*/,0,0);                     //~v78LR~
            if (!pprofqe)                                          //~v78LR~
                break;                                             //~v78LR~
        }                                                          //~v78LR~
        if (swfound==2 || pprofqe==pprofqefound)    //profilename matched//~v78LR~
        {                                                          //~v78LR~
            if ((Popt & FCPRRO_DEL))                               //~v78LR~
            {                                                      //~v78LI~
		       	swfound=3;                                         //~v78LI~
            	continue;                                          //~v78LI~
            }                                                      //~v78LI~
            if (swfound==2) //new                                  //~v78LR~
            {                                                      //~v78LR~
                memcpy(buff,profname,(UINT)proflen);               //~v78LR~
                pc=buff+proflen;                                   //~v78LR~
                *pc++='\t';                                        //~v78LR~
            }                                                      //~v78LR~
            else                                                   //~v78LR~
            {                                                      //~v78LR~
                memcpy(buff,pprofqe->PRQEbuff,(UINT)(pprofqe->PRQEnamelen+1));//~v78LR~
                pc=buff+pprofqe->PRQEnamelen+1;                    //~v78LR~
            }                                                      //~v78LR~
            memcpy(pc,Ppprofile,PROFILESZ);                        //~v78LR~
            pc+=PROFILESZ;                                         //~v78LR~
            *pc++='\n';                                            //~v78LR~
            *pc=0;                                                 //~v78LR~
            pc=buff;                                               //~v78LR~
        	swfound=3;                                             //~v78LI~
        }                                                          //~v78LR~
        else                                                       //~v78LR~
            pc=pprofqe->PRQEbuff;                                  //~v78LR~
        if (*pc!=0xff)  //dummy entry                              //~v78LI~
        {                                                          //~v78LI~
            rc=fputs(pc,fh);                                       //~v78LR~
#ifdef DOSDOS     //dos native                                     //~v78LI~
            if (rc)                                                //~v78LI~
#else                                                              //~v78LI~
            if (rc==-1)                                            //~v78LI~
#endif                                                             //~v78LI~
            {                                                      //~v78LR~
                ufree(pprofqe); //dequed entry                     //~v78LI~
                rc=ufileapierr("fputs",proffnm,errno);             //~v78LR~
                break;                                             //~v78LR~
            }                                                      //~v78LR~
        }                                                          //~v78LI~
        if (pprofqe)                                               //~v78LR~
            ufree(pprofqe);                                        //~v78LR~
    }                                                              //~v78LR~
    fcmdprof83q(4,0,0);		//free 83q for io err case             //~v78LR~
    fclose(fh);                                                    //~v78LR~
    return 0;                                                      //~v78LR~
}//fcmdprof83io                                                    //~v78LR~
//**************************************************************** //~v78LI~
// fcmdprof83io                                                    //~v78LI~
//   read/write profile record under 8.3 filename environment      //~v78LI~
//**************************************************************** //~v78LI~
int fcmdprof83ioread(int Popt,char *Pfnm)                          //~v78LI~
{                                                                  //~v78LI~
    FILE *fh;                                                      //~v78LI~
    int rc=0,len,nmlen;                                            //~v78LI~
    char buff[_MAX_PATH+PROFILESZ],*pc;                            //~v78LI~
    PPROFQE pprofqe;                                               //~v78LI~
//************************                                         //~v78LI~
    fh=fopen(Pfnm,"r");                                            //~v78LI~
    if (fh)                                                        //~v78LI~
    {                                                              //~v78LI~
        for (;;)                                                   //~v78LI~
        {                                                          //~v78LI~
            if (!fgets(buff,sizeof(buff),fh))                      //~v78LI~
                break;                                             //~v78LI~
            len=(int)strlen(buff);                                 //~v78LR~
            pc=strchr(buff,'\t');                                  //~v78LR~
            if (!pc)                                               //~v78LI~
            	continue;                                          //~v78LI~
//          nmlen=(int)((ULONG)pc-(ULONG)buff);                    //~v78LR~//~vafkR~
            nmlen=(int)((ULPTR)pc-(ULPTR)buff);                    //~vafkI~
            if (len-nmlen-1-1<PROFILESZ)                           //~v78LR~
            	continue;                                          //~v78LI~
            pprofqe=fcmdprof83q(1/*enq*/,buff,len);                //~v78LI~
	        UALLOCCHK(pprofqe,UALLOC_FAILED);                      //~v78LI~
            pprofqe->PRQEnamelen=nmlen;                            //~v78LR~
        }                                                          //~v78LI~
        fclose(fh);                                                //~v78LI~
    }//open ok                                                     //~v78LI~
    if (!fcmdprof83q(3,0,0))	//no record                        //~v78LI~
    {                                                              //~v78LI~
        pprofqe=fcmdprof83q(1/*enq*/,"\xff",1);  //enq dummy entry //~v78LI~
        UALLOCCHK(pprofqe,UALLOC_FAILED);                          //~v78LI~
        rc=1;                                                      //~v78LI~
    }                                                              //~v78LI~
    return rc;                                                     //~v78LI~
}//fcmdprof83ioread                                                //~v78LI~
//**************************************************************** //~v78LI~
// fcmdprof83iosrch                                                //~v78LI~
//   read/write profile record under 8.3 filename environment      //~v78LI~
//**************************************************************** //~v78LI~
PPROFQE fcmdprof83iosrch(int Popt,char *Pprofname,int Pprofnamelen)//~v78LI~
{                                                                  //~v78LI~
    PPROFQE pprofqe;                                               //~v78LI~
//************************                                         //~v78LI~
	pprofqe=fcmdprof83q(3,0,0);	//qtop                             //~v78LI~
    for (;pprofqe;pprofqe=UGETQNEXT(pprofqe))                      //~v78LR~
    {                                                              //~v78LI~
    	if (Pprofnamelen==pprofqe->PRQEnamelen                     //~v78LI~
        &&  *(pprofqe->PRQEbuff+Pprofnamelen)=='\t'                //~v78LR~
        &&  !memicmp(pprofqe->PRQEbuff,Pprofname,(UINT)Pprofnamelen)) //incase for gcc or os2//~v78LR~
        {                                                          //~v78LI~
			fcmdprof83q(5/*reenq to top*/,pprofqe->PRQEbuff,0);    //~v78LI~
        	return pprofqe;                                        //~v78LI~
        }                                                          //~v78LI~
    }                                                              //~v78LI~
    return 0;                                                      //~v78LI~
}//fcmdprof83io                                                    //~v78LI~
//**************************************************************** //~v78LR~
// fcmdprof83q                                                     //~v78LR~
//   enq/deq profile record for update                             //~v78LR~
//**************************************************************** //~v78LR~
PPROFQE fcmdprof83q(int Popt,char *Pbuff,int Plen)                 //~v78LR~
{                                                                  //~v78LR~
static UQUEH Sprofqh;                                              //~v78LR~
    int len;                                                       //~v78LR~
    PPROFQE pprofqe=NULL;                                               //~v78LR~//~vaf9R~
//************************                                         //~v78LR~
    switch (Popt)                                                  //~v78LR~
    {                                                              //~v78LR~
    case 1:          //enq                                         //~v78LI~
//      len=PROFQESZ+Plen;                                         //~v78LR~//~vb2DR~
        len=(int)PROFQESZ+Plen;                                    //~vb2DI~
        pprofqe=(PPROFQE)umalloc((UINT)len);                       //~v78LR~
        UALLOCCHK(pprofqe,0);                                      //~v78LR~
        memset(pprofqe,0,PROFQESZ);                                //~v78LR~
        memcpy(pprofqe->PRQEbuff,Pbuff,(UINT)Plen+1);   //last null//~v78LR~
        UENQ(UQUE_END,&Sprofqh,pprofqe);                           //~v78LR~
        break;                                                     //~v78LI~
    case 2:         //deq                                          //~v78LR~
        pprofqe=UDEQ(UQUE_TOP,&Sprofqh,0);                         //~v78LR~
        break;                                                     //~v78LI~
    case 3:         //chk                                          //~v78LI~
        pprofqe=UGETQTOP(&Sprofqh);                                //~v78LI~
        break;                                                     //~v78LI~
    case 4:         //free all                                     //~v78LI~
        UQUFREE(&Sprofqh);                                         //~v78LR~
        pprofqe=0;                                                 //~v78LI~
        break;                                                     //~v78LI~
    case 5:         //reenq to top                                 //~v78LI~
//      pprofqe=(PPROFQE)((ULONG)Pbuff-offsetof(PROFQE,PRQEbuff)); //~v78LR~//~vafkR~
        pprofqe=(PPROFQE)((ULPTR)Pbuff-offsetof(PROFQE,PRQEbuff)); //~vafkI~
        UDEQ(UQUE_ENT,&Sprofqh,pprofqe);                           //~v78LR~
        UENQ(UQUE_TOP,&Sprofqh,pprofqe);  //re-enq to top          //~v78LI~
        break;                                                     //~v78LI~
    }                                                              //~v78LI~
    return pprofqe;                                                //~v78LR~
}//fcmdprof83q                                                     //~v78LR~
//**************************************************************** //~v78rI~
// errmsg:has no ext name                                          //~v78rI~
//**************************************************************** //~v78rI~
int fcmdproferrnoext(char *Pfnm)                                   //~v78rI~
{                                                                  //~v78rI~
	uerrmsg("%s has no extension name",                            //~v78rI~
    		"%s には拡張子がありません",                           //~v78rI~
             Pfnm);                                                //~v78rI~
	return 4;                                                      //~v78rI~
}//fcmdproferrnoext                                                //~v78rI~
