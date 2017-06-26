//*CID://+vb4yR~:                             update#=  451;       //~vb4yR~
//*************************************************************
//*xefile6.c  *                                                    //~va00R~
//* tab                                                            //~v0bzR~
//*************************************************************
//vb4y:160814 set same attr to UNICOMB UNPR altch for edit panel as dirlist//~vb4yI~
//vb3x:160621 ffff is treated as dbcsspace on dirlist. tabdisplay set dbcs space to ffff/()//~vb3xI~
//vb3u:160620 del vb3t;set to FF cause altch translation           //~vb3vI~
//vb3t:160619 set altch for ctlch also when unprintable by ini file for utf8 file//~vb3tI~
//vb3q:160617 (BUG)dbcsspace dispchar should be fix to ffff(apply assign by ini file to LC file only)//~vb3qI~
//vb3n:160616 (BUG)altch of DBCSSPACE color is not green at 1st time for utf8 file//~vb3nI~
//vb2S:160325 by ulib:v6C0,noncaracter ucs(ffff,fffe,fdd0-fdef) is unprintable ucs(2 column) like as LNNX, del vb2R//~vb2SI~
//vb2R:160325 display noncharacter ucs(ffff,fffe,fdd0-fdef) as unprintable sbcs//~vb2RI~
//            it is not displayed when ligature mode               //~vb2RI~
//vb28:160116 (BUG)display spilit utf8 by lineattr                 //~vb28I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vamF:131119 (BUG)"xpr **/***" fails by "input fmt err" for vhex utf,fold at 0x0a for lc file.//~vamFI~
//vajn:130815 (BUG)copy non-ebc line into ebc file say cv error if dbcs found//~vajnI~
//vajm:130815 (BUG)tab:09-->ebc:05 require XEEBCO_CVCTL for copy line non-ebc to ebc file//~vajmI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf8I~
//vaf8:120607 (WTL)Bug found by vs2010exp(used uninitialized variable)//~vaf8I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va80:100917 (WXEXXE)print ebcfile by ucs                         //~va80I~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va7v:100825 accept sbcs->dbcs for ebc to utf8 copy               //~va7xR~
//va7u:100823 EBC:handle support to file input(Copy/Move/Paste)    //~va7uI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va74:100806 (BUG:WXE)reset va6v; write by locale code to use font codepage on setupdialog//~va74I~
//                     currentrly l2uany use base locale           //~va74I~
//va70:000701 LP64 option support                                  //~va70I~
//va6C:100716 (BUG)display altch for dbcs space even when tab off if bin mode//~va6CR~
//                 v20U modifyed, but display tab only(unpdisp ch changed to ff, it cause line corruption)//~va6CI~
//va6v:100626 (WXE)use textoutW for locale code (more printable for any font slected)//~va6vI~//~va6CR~
//va6t:100625 (BUG:UCS2) tabdisplay abend when dbcs split at eol   //~va6tI~//~va6CR~
//va6s:100625 (BUG:UCS4) ovf ucs4(>=0x020000) 2nd by te displayed by green(1st is yellow)//~va6sI~//~va6CR~
//va6d:100620 b2m may expand line (hankana-->euc)                  //~va6dI~
//va6c:100619 add SOSI option -S{i|r|d} to REP/CRE/APP/SAV/COP/MOV cmd//~va6cI~
//va5L:100523 (w)xpr cmd;print SO/SI by "?"                        //~va5LI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va48:100402 for xprint alt char(0xff) is invalid                 //~va48I~
//va47:100401 va46 for LNX                                         //~va47I~
//va46:100331 not use ctrl char for tab and tab padding,but use xff as default//~va46I~
//va44:100329 to print 0x14 glyph(q:0xb6),ulib replace dbcsspace to alt char when tab on//~va44I~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va3e:100207 (LNX)Console version:to display combine char is not stable. add 3rd option to set unprintable. by A+":"//~va3eI~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va2j:100104 (BUG)binfile xp ***;sjis dbcs is 82a0 is printed as unprintable  (a0 rep by "." as unprintable)//~va2jI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20R~
//            setdbcstbl by DDfmt                                  //~va20R~
//            tabdisplay for DDfmt                                 //~va20R~
//            tabexpand  for DDfmt                                 //~va20I~
//va1G:091118 (UTF8)add UTF8 trans err char Find/Change function   //~va1GI~
//va1E:091116 optionaly(default) keep original value when UTF8 code err at load//~va1EI~
//va1q:091107 compchkm                                             //~va1qI~
//va1e:091101_(UTF8) retry by lc for f2l err at load if no CPU8 option specified//~va1eI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va15:091023_DBCS space chk for other than japanese               //~va15I~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8                                  //~va00I~
//          Copy:CPxx option  COPy/MOVe fnm [CPU8] [IE]            //~va00I~
//          display UTF8 cv err by "?"                             //~va00I~
//          ignore translation err for utility result file(parm to edit_file2)//~va00I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v79y:080915 (BUG)syntaxh position invalid when copy line between different tabctr//~v79yI~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v73v:070127 (BUG)tab dose not back to part of dbcs 2nd byte after prev byte is changed to dbcs 1st byte by (v)hex mode//~v73vI~
//            so,undo v73k.(AIX/LNX is set UDBCSCHK_HKDBERR if 2nd byte err.So WIN,DOS,OS/2 set HKDBERR only when 2nd byte is tab.//~v73vI~
//v73q:070121*(BUG)for the line oom contain tab,after del omm contains imm data by shiftback//~v73qI~
//v73m:070116 (BUG)del insert invalid char when tab exit after del point//~v73mI~
//v73k:070116 (BUG)x09 of DBCS 2nd byte should not treate as TAB   //~v73kI~
//v73g:070112 (BUG)margin chk is not correct when rep char by TAB using vhex mode//~v73gI~
//v73c:070110*(BUG)imtabexp parm len=0 should not be margin(access over boundary at filetabexp)//~v73cR~
//v71U:061112 (BUG)accept insert in short(<mergin) record of margined file//~v71UI~
//            even if result is over margin but overflow is space only//~v71UI~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert.(split xecap.c to xecap2.c)//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnDel+Ins//~v66fI~
//v61x:050308 xprint for binfile(rep to "." from crlf etc ctlchar) //~v61xI~
//v50j:021230 cv cmd:ajust conv err pos by tab expand              //~v50jI~
//v50f:021229 (BUG)tab disappear by cv cmd                         //~v50fI~
//v44a:011202 (BUG)hex input replace another tab char to space     //~v44aI~
//v43y:011122 7bit dump mode                                       //~v43yI~
//v21m:010114 LINUX support:rigid euc chk to avoid screen destroy  //~v21mI~
//v21k:010113 LINUX support:dbcs ctl should be under kon even if euc//~v21kI~
//v21i:010113 LINUX support:euc code dbcs support                  //~v21iI~
//v20U:001119 display tab and dbcs space when binary mode          //~v20UI~
//v106:981212 no tab expand when binaly file                       //~v106I~
//v0hQ:980429 (BUG)filetabcler clear next 09(it may be winNT malloc len on hdr)//~v0hQI~
//            under NT issue area destroy at ufree.                //~v0hQI~
//v0hJ:980418 support "tab clear" cmd                              //~v0hJM~
//v0ev:970922 abondan /v0ep/v0er/v0es/v0eu;                        //~v0evI~
//            use filetabexp2(expand in mergin only)               //~v0evI~
//v0bz:970728 if last is tab,expandlen over mergin cause expand err.//~v0bzI~
//            but it can be cut in mergin and set cid on normal pos.//~v0bzI~
//v0bb:970726 limit tabctr max 12,and tab expand limit chk         //~v0bbI~
//v0b3:970723 clear tab when shift,it is easy to expectate.        //~v0b3I~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -expand pre chk(split file2 to file6)
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318R~
#include <utrace.h>                                                //~v06yI~
#include <ualloc.h>
#include <udbcschk.h>                                              //~v21mI~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include <utf.h>                                                   //~va15I~
#endif                                                             //~va1qI~
#ifdef UTF8UCS2                                                    //~va20I~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvebc.h>                                                //~va50I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#ifdef UTF8SUPPH                                                   //~va00I~
#include "xefile12.h"                                              //~va00R~
#endif                                                             //~va00I~
#include "xefile42.h"                                              //~va00I~
#include "xefile5.h"                                               //~va6cI~
#include "xefile6.h"
#include "xeundo.h"                                                //~v0hJI~
#include "xesub.h"                                                 //~v0avI~
#include "xegbl.h"                                                 //~v21iI~
#include "xesyn.h"                                                 //~v79yI~
#ifdef UTF8SUPPH                                                   //~va00I~
	#include "xeopt.h"                                             //~va00R~
	#include "xeutf.h"                                             //~va00I~
	#include "xefunc.h"                                            //~va00I~
	#include "xefcmd2.h"                                           //~va1GI~
#endif                                                             //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
	#include "xeutf2.h"                                            //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
//#define DBCSSPACE1    0x81    //dbcs space first byte            //~v21iR~
//#define DBCSSPACE2    0x40    //dbcs space second byte           //~v21iR~
//**************************************************************** //~v0bbI~
static int Smerginoffs=0;                                          //~v43yR~
static char Sdbcsspace[2];                                         //~va15I~
static int Shandle;     //EBCDIC handle                            //~va79I~
//**************************************************************** //~v0evI~
int filetabexpanderr(void);                                        //~v0bbI~
#ifdef UTF8SUPPH                                                   //~va00I~
//	int filecvf2lsetdbcs(int Popt,PUFILEH Ppfh,PULINEH Pplh);      //~va1cR~
  	int filecvf2lsetdbcs(int Popt,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen);//~va1cR~
#ifdef UTF8UCS2                                                    //~va20I~
  	#define FCF2LO_F2DD   0x01  //F2DD                             //~va20I~
#endif                                                             //~va20I~
#endif                                                             //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int filecvebcplh(int Popt,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen);//~va50I~
#define FCEPO_SOSIDEL  0x01                                        //~va6cI~
#define FCEPO_SOSIINS  0x02                                        //~va6cI~
#define FCEPO_SOSIREP  0x04                                        //~va6cI~
#define FCEPO_BIN      0x08   //no translation mode                //~va7xI~
//int filecvb2m(int Popt,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen);   //~va50I~//~va79R~
int filecvb2m(int Popt,int Phandle,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen);//~va79I~
int filecvm2b(int Popt,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen);   //~va50I~
#define FCVEO_F2B         0x01                                     //~va50I~
#define FCVEO_L2B         0x02                                     //~va50I~
#define FCVEO_B2DD        0x04                                     //~va50I~
#define FCVEO_B2L         0x08                                     //~va50I~
#define FCVEO_INITDBCST   0x10                                     //~va50I~
#define FCVEO_ERRREP      0x20                                     //~va50R~
#define FCVEO_SOSIREP     0x40                                     //~va6cI~
#define FCVEO_SOSIINS     0x80                                     //~va6cI~
#define FCVEO_SOSIDEL   0x0100                                     //~va6cI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
static int Scopycmdopt;	//FSOC_xxxx from copy cmd parameter option //~va6cR~
//****************************************************************
//!filechktabdbcs                                               //~v04dR~
//*full line tab chk and expand                                 //~4C30R~
//*parm1:PUCLIENTWE
//*rc   :0:tab expanded,4:no tab or already expanded for FIND cmd//~5102R~
//*     :UALLOC_FAILED if storage shortage                      //~v04dI~
//****************************************************************
int filechktabdbcs(PULINEH Pplh)                                //~5102R~
{
	int len,tabskip,rc;                                         //~v04dR~
    PUFILEH pfh;                                                   //~v106I~
    int optebcplh;                                                 //~va6cI~
//************************
    pfh=UGETPFH(Pplh);                                             //~v106I~
    if (!(tabskip=pfh->UFHtabskip))                                //~v8@2R~
    {                                                              //~v8@2I~
    	tabskip=max(Gfiletabskip,1);                               //~v8@2R~
    	pfh->UFHtabskip=(UCHAR)tabskip;                            //~v8@2I~
    }                                                              //~v8@2I~
  if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                            //~v106I~
    tabskip=1;                                                     //~v106I~
//else                                                             //~v8@2R~
//  tabskip=max(Gfiletabskip,1);                                   //~v8@2R~
	len=Pplh->ULHlen;                                           //~5102I~
	if (UCBITCHK(Pplh->ULHflag2,ULHF2TABCHKED))	//not first time
	{
		if (UCBITCHK(Pplh->ULHflag2,ULHF2TABFOUND))//once tab detected
		{
			if (Pplh->ULHtabskip==tabskip)	//tabskip not changed
				return 4;		//no need setdbcs               //~5102R~
			if (rc=filetabexp(1,Pplh,0,&len),rc)//re-expand     //~v04dR~
			{                                                   //~5102I~
                if (rc==UALLOC_FAILED)                          //~v04dI~
                	return UALLOC_FAILED;                       //~v04dI~
				UCBITOFF(Pplh->ULHflag2,ULHF2TABFOUND);	//reset tab exist//~5102I~
				return 4;                                       //~5102I~
			}                                                   //~5102I~
    IFDEF_SYNSUPP(                                                 //~v79yI~
        	SYN_INVALIDATE_PLH(Pplh);                              //~v79yR~
    		SYN_INVALIDATE_PFH(pfh);                               //~v79yI~
			)                                                      //~v79yI~
		}
		else	//no tab detected
			return 4;                                           //~4C30R~
	}
	else
	{                                                           //~5102I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
		optebcplh=0;                                               //~va6cI~
        if (Scopycmdopt & FSOC_SOSI_REP)                           //~va6cI~
	  		optebcplh|=FCEPO_SOSIREP;                              //~va6cI~
        else                                                       //~va6cI~
        if (Scopycmdopt & FSOC_SOSI_DEL)                           //~va6cI~
	  		optebcplh|=FCEPO_SOSIDEL;                              //~va6cI~
        else                                                       //~va6cI~
        if (Scopycmdopt & FSOC_SOSI_INS)                           //~va6cI~
	  		optebcplh|=FCEPO_SOSIINS;                              //~va6cI~
        if (Scopycmdopt & FSOC_BIN)                                //~va7xI~
	  		optebcplh|=FCEPO_BIN;    //no translation mode         //~va7xI~
	  if (PFH_ISEBC(pfh))	//tgt ebc                              //~va50R~
      {                                                            //~va50I~
//  	filecvebcplh(0,pfh,Pplh,&len);                             //~va50I~//~va6cR~
    	filecvebcplh(optebcplh,pfh,Pplh,&len);                     //~va6cI~
		UCBITON(Pplh->ULHflag2,ULHF2TABCHKED);//not first time     //~va50I~
      }                                                            //~va50I~
      else                                                         //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
      {//!ebc                                                      //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
       if (UCBITCHK(Pplh->ULHflag5,ULHF5COPYCVB2)) //copy source is ebc//~va50I~
       {                                                           //~va50I~
//  	filecvebcplh(0,pfh,Pplh,&len);                             //~va50I~//~va6cR~
    	filecvebcplh(optebcplh,pfh,Pplh,&len);                     //~va6cI~
		UCBITON(Pplh->ULHflag2,ULHF2TABCHKED);//not first time     //~va50I~
       }                                                           //~va50I~
       else                                                        //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
       {//!B2                                                      //~va50I~
		if (!Pplh->ULHdbcs)	//not yet created dbcstbl           //~5102R~
		{                                                       //~5102I~
          {                                                        //~va20I~
			Pplh->ULHdbcs=UALLOCC(1,(UINT)Pplh->ULHbufflen);    //~v04dR~
		    UALLOCCHK(Pplh->ULHdbcs,UALLOC_FAILED);   //return 0 if storage shortage//~v04dI~
          }                                                        //~va20I~
//  		setdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,len);           //~v09YR~
//  		filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,len);       //~v44aR~
#ifdef UTF8SUPPH                                                   //~va00I~
		  if (FILEUTF8MODE(pfh))                                   //~va00I~
          {                                                        //~va00I~
          	if (UCBITCHK(Pplh->ULHflag5,ULHF5COPYCVL2F)) //copy source requires F2L//~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
//*locale-->utf8                                                   //~va20I~
    			filecvl2dd(0,pfh,Pplh);//	setup ddfmt            //~va20I~
#else                                                              //~va20I~
	    		filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,len,0);//no chk tab//~va00I~
#endif                                                             //~va20I~
            else                                                   //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
//*utf8-->utf8                                                     //~va20I~
    			filecvf2lsetdbcs(FCF2LO_F2DD,pfh,Pplh,&len);//len may be expanded by GB18030//~va20I~
#else                                                              //~va20I~
//  			filecvf2lsetdbcs(0,pfh,Pplh);                      //~va1cR~
    			filecvf2lsetdbcs(0,pfh,Pplh,&len);//len may be expanded by GB18030//~va1cR~
#endif                                                             //~va20I~
          }                                                        //~va00I~
          else                                                     //~va00I~
          if (UCBITCHK(Pplh->ULHflag5,ULHF5COPYCVF2L)) //copy source requires F2L//~va00I~
//*utf8-->locale                                                   //~va20I~
//			filecvf2lsetdbcs(0,pfh,Pplh);                          //~va1cR~
  			filecvf2lsetdbcs(0,pfh,Pplh,&len);                     //~va1cR~
          else                                                     //~va00I~
//*locale-->locale                                                 //~va20I~
#endif                                                             //~va00I~
    		filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,len,0);//no chk tab//~v44aI~
		}                                                       //~5102I~
       }//!B2                                                      //~va50I~
		if (rc=filetabexp(0,Pplh,0,&len),rc)//initial           //~v04dR~
        {                                                       //~v04dI~
            if (rc==UALLOC_FAILED)                              //~v04dI~
               	return UALLOC_FAILED;                           //~v04dI~
			return 4;                                       //~5102I~
        }                                                       //~v04dI~
      }//!ebc                                                      //~va50I~
	}//not tab chked                                            //~5102I~
	return 0;                                                   //~4C30R~
}//filechktabdbcs                                               //~5102R~
//**************************************************************** //~va6cI~
//!filechktabdbcs2                                                 //~va6cI~
//   filechktabdbcs for copy cmd:file to screen                    //~va7uR~
//**************************************************************** //~va6cI~
int filechktabdbcs2(int Popt,int Pcopyopt,PULINEH Pplh)            //~va6cI~
{                                                                  //~va6cI~
	int rc;                                                        //~va6cI~
//****************                                                 //~va6cI~
    Scopycmdopt=Pcopyopt;	//parm to filecvebcplh                 //~va6cR~
    if (Pcopyopt & FSOC_EBCHANDLEP)                                 //~va7tI~//~va7uI~
    	Shandle=FSOC_GETHANDLE(Pcopyopt);                            //~va7tI~//~va7uI~
	rc=filechktabdbcs(Pplh);                                       //~va6cR~
    Shandle=0;                                                     //~va7uI~
	Scopycmdopt=0;                                                 //~va6cR~
    return rc;                                                     //~va6cR~
}//filechktabdbcs2                                                 //~va6cI~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
//!filechkutf8encoding                                             //~va00I~
// chk utf8 encoding for all line                                  //~va00I~
// rc:4:cv err,8:cv err under not forced by cpu8 parm, UALLOC_FAILED//~va00R~
//**************************************************************** //~va00I~
int filechkutf8encoding(int Popt,PUCLIENTWE Ppcw,int Pbinopt,PUFILEH Ppfh)//~va00R~
{                                                                  //~va00I~
	PULINEH plh;                                                   //~va00I~
//  int rc=0,rc2,/*opt,*/lineno=0,errlineno=0,utf8lineno;          //~vaf8R~
    int rc=0,rc2,/*opt,*/lineno=0,errlineno=0,utf8lineno=0;        //~vaa7I~
#ifdef AAA                                                         //~va00I~
    int len,lenlc;                                                 //~va00I~
    char *pdata,*outlc;                                            //~va00M~
#endif                                                             //~va00I~
	PFUNCTBL pft;                                                  //~va00R~
//****************************                                     //~va00I~
	if (!FILEUTF8MODE(Ppfh))                                       //~va00R~
    	return 0;                                                  //~va00I~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))	//bin mode             //~va00I~
    {                                                              //~va00I~
		if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8P))    //CPU8 parm    //~va00I~
			uerrmsg("%s option ignored for binary file",0,         //~va00R~
    		    		MODE_UTF8);                                //~va00R~
		UCBITOFF(Ppfh->UFHflag8,UFHF8UTF8|UFHF8UTF8P);    //CPU8 parm//~va00I~
        return 1;                                                  //~va00R~
    }                                                              //~va00I~
//  opt=XEUTFCVO_CPLC;  //utf-->lc                                 //~va00I~//~vaa7R~
	for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~va00R~
	{                                                              //~va00I~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~va00I~
        	continue;                                              //~va00I~
		if (plh->ULHdbcs)	//already chked if SPF                 //~va00I~
        	continue;                                              //~va00I~
        lineno++;                                                  //~va00I~
#ifdef AAA                                                         //~va00I~
        pdata=plh->ULHdata;                                        //~va00I~
        len=plh->ULHlen;                                           //~va00I~
        outlc=0;	//out to internal buff                         //~va00I~
		rc2=xeutf_cvdata(opt,pdata,len,&outlc,&lenlc);             //~va00I~
        if (rc2==XEUTFCVRC_ALLASCII)                               //~va00M~
        	continue;                                              //~va00M~
#else                                                              //~va00I~
        UCBITON(plh->ULHflag5,ULHF5LOADCV);	//parm to filechktabdbcs//~va00I~
		rc2=filechktabdbcs(plh);	//translate and expand at init for find cmd//~va00I~
        UCBITOFF(plh->ULHflag5,ULHF5LOADCV);	//parm to filechktabdbcs//~va00I~
#endif                                                             //~va00I~
        if (rc2==UALLOC_FAILED)                                    //~va00I~
            return rc2;                                            //~va00I~
        if (UCBITCHK(plh->ULHflag5,ULHF5LOADCVERR))	//f2l err      //~va00I~
        {                                                          //~va00I~
        	rc=4;                                                  //~va00I~
            errlineno++;                                           //~va00I~
        }                                                          //~va00I~
        else                                                       //~va00I~
        if (UCBITCHK(plh->ULHflag5,ULHF5LOADCVUTF8))	//f2l err  //~va00I~
        {                                                          //~va00I~
            utf8lineno++;                                          //~va00I~
        }                                                          //~va00I~
	}//all line                                                    //~va00I~
    if (errlineno)                                                 //~va00R~
    {                                                              //~va00I~
        UCBITON(Ppfh->UFHflag10,UFHF10UTF8LOADERR);                //~va00I~
//    	if (!(Popt & FCU8EO_NOMSG))  //rc should be set                               //~va00R~//~va1eR~
//      {                                                          //~va00I~//~va1eR~
        	if (Pbinopt & UFCFBROWSE)                              //~va00I~
            {                                                      //~va00I~
//              if (UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8P))    //CPU8 parm//~va00R~
    	            uerrmsgcat("UTF8 trans err(%d/%d lines). Search by \"F *e\".",//~va00R~
    	                       "UTF8変換エラー(%d/%d行)。\"F *e\"で探せます。",//~va00R~
                                errlineno,lineno);                 //~va00R~
//              else                                               //~va00R~
//              {                                                  //~va00R~
//                  rc=8;                                          //~va00R~
//                  uerrmsgcat("UTF8 trans err(%d/%d lines). Use %s/%s option to open.",//~va00R~
//                             "UTF8変換エラー(%d/%d行)。開くには %s か %s オプションを指定する。",//~va00R~
//                              errlineno,lineno,MODE_UTF8,MODE_LOCALE);//~va00R~
//              }                                                  //~va00R~
            }                                                      //~va00I~
            else                                                   //~va00I~
            {                                                      //~va00I~
    			if (Popt & FCU8EO_IE                               //~va00I~
                ||  UCBITCHK(Ppfh->UFHflag10,UFHF10UTF8IE))    //ignore cv err//~va00R~
	              if (Gutfmode2 & GUM2_KEEPIFCVERR)   //cv err byte is kept untranslated//~va1EI~
                  {                                                //~va1EI~
                    uerrmsgcat("UTF8 trans err(%d/%d lines). Error chars are shown by '%c' (byte code is kept). Search the error by \"F *e\" or \"F %s\".",//~va1ER~//~va1GR~
                               "UTF8変換エラー(%d/%d行)。エラーはバイトコードはそのまま、'%c' で\x95\\示。エラーは\"F *e\" か \"F %s\" で探せます",//~va1ER~//~va1GR~
                                errlineno,lineno,XEUTF_ERRREPCH_F2LFILE,SRCHIDS_UTF8ECH);//~va1EI~//~va1GR~
                  }                                                //~va1EI~
                  else                                             //~va1EI~
                  {                                                //~va1EI~
                    uerrmsgcat("UTF8 trans err(%d/%d lines). It will be replaced to '%c' if saved after modified. Search the error lines by \"F *e\".",//~va00R~//~va1qR~
                               "UTF8変換エラー(%d/%d行)。更新して保存すると '%c' に置換されます。エラー行は\"F *e\"で探せます",//~va00R~//~va1qR~
                                errlineno,lineno,XEUTF_ERRREPCH_F2LFILE);//~va00R~
                  }//cv to "?" if err                              //~va1EI~
                else              //by env                         //~va00R~
                {                                                  //~va00R~
                    rc=8;                                          //~va00R~
					if (UCBITCHK(Ppcw->UCWflag2,UCWF2SELECTCMD)	//parm to fileoptionchk//~va00I~
                	&&  (pft=Ppcw->UCWpfunct,pft!=0)               //~va00I~
					&&  (pft->FTfuncid!=FUNCID_SELECT)             //~va00I~
                	)                                              //~va00I~
                    	uerrmsgcat("UTF8 trans err(%d/%d lines). Use Open line cmd with \"%s\" option.",//~va00I~
                        	       "UTF8変換エラー(%d/%d行)。開くには \"%s\" オプションつき Open 行コマンド使用。",//~va00I~
                            	    errlineno,lineno,MODE_IE);     //~va00I~
                	else                                           //~va00I~
                    	uerrmsgcat("UTF8 trans err(%d/%d lines). Use \"%s %s\" or \"%s\" option to open.",//~va00R~
                        	       "UTF8変換エラー(%d/%d行)。開くには \"%s %s\" か \"%s\" オプションを指定する。",//~va00R~
                            	    errlineno,lineno,MODE_UTF8,MODE_IE,MODE_LOCALE);//~va00R~
                }                                                  //~va00R~
//          }                                                      //~va00I~//~va1eR~
		}		                                                   //~va00R~
    }                                                              //~va00I~
    return rc;                                                     //~va00I~
}//filechkutf8encoding                                             //~va00I~
//**************************************************************** //~va00I~
//!filecvl2f                                                       //~va00I~
//*translate plhdata from utf8 to locale code and setup dbcstbl    //~va00I~
//* under the condition ULHdbcs allocated                          //~va00I~
//*rc   :0x01:not all ascii,02:contain dbcs,04 contains err ch     //~va00R~
//		 0x08:bin file                                             //~va00I~
//       UALLOC_FAILED                                             //~va00I~
//**************************************************************** //~va00I~
//int filecvf2lsetdbcs(int Popt,PUFILEH Ppfh,PULINEH Pplh)         //~va1cR~
int filecvf2lsetdbcs(int Popt,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen)//~va1cR~
{                                                                  //~va00I~
	int len,lenlc,opt,rc;                                          //~va00R~
    UCHAR *plc,*pdbcs,*pdata;                                       //~va00R~//~va50R~
    UCHAR *pcd;                                                     //~va1cR~//~va50R~
//************************                                         //~va00I~
	len=Pplh->ULHlen;                                              //~va00I~
    pdata=Pplh->ULHdata;                                           //~va00I~
    pdbcs=Pplh->ULHdbcs;                                           //~va00M~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))  //bin file             //~va00I~
    {                                                              //~va00I~
    	filesetdbcstbl(pdata,pdbcs,len,0);//no chk tab             //~va00I~
        rc=8;                                                      //~va00I~
    }                                                              //~va00I~
    else                                                           //~va00I~
    {                                                              //~va00I~
        plc=0;              //get and return work                  //~va00R~
        pcd=0;              //get and return work                  //~va1cR~
        opt=0;                                                     //~va00M~
//      if (UCBITCHK(Pplh->ULHflag5,ULHF5LOADCV)	//at initial load load//~va00R~
//      &&  !UCBITCHK(Ppfh->UFHflag8,UFHF8UTF8P)	//not CPU8 parm but env is utf8//~va00R~
//      )                                                          //~va00R~
//          opt|=XEUTFF2LO_KEEPIFCVERR;                            //~va00R~
//      rc=xeutf_cvf2lsetdbcs(opt,pdata,len,&plc,pdbcs,&lenlc);    //~va1cR~
        opt|=XEUTFF2LO_SAVECVERRCH;	//keep org value for trans err char//~va1ER~
#ifdef UTF8UCS2                                                    //~va20R~
  	  if (Popt & FCF2LO_F2DD)   //F2DD                             //~va20R~
        opt|=XEUTFF2LO_DDFMT;  		//maintenance by DD fmt        //~va20R~
#endif                                                             //~va20R~
        rc=xeutf_cvf2lsetdbcs(opt,pdata,len,&plc,&pcd,&lenlc);     //~va1cR~
        if (rc==UALLOC_FAILED)                                     //~va00R~
            return rc;                                             //~va00R~
        if (rc)    //not all ascii                                 //~va00R~
        {                                                          //~va00I~
        	if (rc & XEUTFF2LRC_ERRKEPTORG)	//8                    //~va00R~
            {                                                      //~va1cR~
            	lenlc=len;	//no conversion(leave original line data)//~va00R~
//            	memcpy(pdbcs,pcd,len);	//cvf2lsetdbcs set it      //~va1cR~//~vb28R~
              	memcpy(pdbcs,pcd,(size_t)len);	//cvf2lsetdbcs set it//~vb28I~
            }                                                      //~va1cR~
            else                                                   //~va00I~
            {                                                      //~va1cR~
                if (lenlc>len)  //expanded by f2l                  //~va1cR~
                {                                                  //~va1cR~
					if (fileexpandbuff(Pplh,lenlc)==UALLOC_FAILED)	//expand if buff over//~va1cR~
        				return UALLOC_FAILED;                      //~va1cR~
                    pdata=Pplh->ULHdata;                           //~va1cR~
                    pdbcs=Pplh->ULHdbcs;                           //~va1cR~
                }                                                  //~va1cR~
//          	memcpy(pdata,plc,lenlc);                           //~va00R~//~vb28R~
            	memcpy(pdata,plc,(size_t)lenlc);                   //~vb28I~
//          	memcpy(pdbcs,pcd,lenlc);                           //~va1cR~//~vb28R~
            	memcpy(pdbcs,pcd,(size_t)lenlc);                   //~vb28I~
            }                                                      //~va1cR~
            if (rc & XEUTFF2LRC_ERR)	//conversion err           //~va00I~
            {                                                      //~va00I~
				filesetlineerr(Pplh);                              //~va00I~
				UCBITON(Pplh->ULHflag5,ULHF5LOADCVERR);            //~va00M~
            }                                                      //~va00I~
            if (rc & XEUTFF2LRC_UTF8)   //contains utf8 code       //~va00I~
				UCBITON(Pplh->ULHflag5,ULHF5LOADCVUTF8);           //~va00R~
        }                                                          //~va00I~
        else	//all ascii                                        //~va1cR~
//          memset(pdbcs,0,len);	//cvf2lsetdbcs set it          //~va1cR~//~vb28R~
            memset(pdbcs,0,(size_t)len);	//cvf2lsetdbcs set it  //~vb28I~
    	Pplh->ULHlen=lenlc;                                        //~va00R~
    }                                                              //~va00I~
    UTRACED("filecvf2lsetdbcs",Pplh->ULHdata,Pplh->ULHlen);        //~va1cR~
    if (Ppnewlen)                                                  //~va1cR~
    	*Ppnewlen=Pplh->ULHlen;                                    //~va1cR~
    return rc;                                                     //~va00R~
}//filecvf2lsetdbcs                                                //~va00R~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************************** //~va20I~
//!filecvl2dd                                                      //~va20I~
//*translate plhdata from locale to ddfmt                          //~va20I~
//* under the condition ULHdbcs allocated;length may expand when sbcs by locale is dbcs by utf8//~va20I~
//       UALLOC_FAILED                                             //~va20I~
//**************************************************************** //~va20I~
int filecvl2dd(int Popt,PUFILEH Ppfh,PULINEH Pplh)                 //~va20I~
{                                                                  //~va20I~
	int rc,ulhlen,ddlen;                                           //~va20I~
    UCHAR *pdata,*pdbcs,*pdd,*pcd;                                 //~va20I~
//************************                                         //~va20I~
	pdata=Pplh->ULHdata;                                           //~va20I~
	pdbcs=Pplh->ULHdbcs;                                           //~va20I~
    ulhlen=Pplh->ULHlen;                                           //~va20I~
    UTRACED("filecvl2dd inp data",pdata,ulhlen);                   //~va20I~//~va2jR~
    UTRACED("filecvl2dd inp dbcs",pdbcs,ulhlen);                   //~va20I~//~va2jR~
	rc=xeutfcvl2dd(0,pdata,ulhlen,&pdd,&pcd,&ddlen);               //~va20I~
    if (rc==UALLOC_FAILED)                                         //~va20I~
    	return rc;                                                 //~va20I~
	if (ddlen>Pplh->ULHbufflen)                                    //~va20I~
    {                                                              //~va20I~
		if (fileexpandbuff(Pplh,ddlen)==UALLOC_FAILED)	//expand if buff over//~va20I~
        	return UALLOC_FAILED;                                  //~va20I~
		pdata=Pplh->ULHdata;                                       //~va20I~
		pdbcs=Pplh->ULHdbcs;                                       //~va20I~
    }                                                              //~va20I~
    memcpy(pdata,pdd,(UINT)ddlen);                                 //~va20I~
    memcpy(pdbcs,pcd,(UINT)ddlen);                                 //~va20I~
    Pplh->ULHlen=ddlen;                                            //~va20I~
    UTRACED("filecvl2dd out data",pdata,ddlen);                    //~va20I~
    UTRACED("filecvl2dd out dbcs",pdbcs,ddlen);                    //~va20I~
    return rc;                                                     //~va20I~
}//filecvl2dd                                                      //~va20I~
//**************************************************************** //~va20I~
//!line translation between utf8/ebc file and non utf8 file            //~va20I~//~va7uR~
//*parm 1:start plh                                                //~va20I~
//*parm 2:end plh                                                  //~va20I~
//*return:none                                                     //~va20I~
//**************************************************************** //~va20I~
//int filecvaftercopy(int Popt,PUFILEH Ppfh,PULINEH Pplh)            //~va20I~//~va79R~
int filecvaftercopy(int Popt,PUFILEH Ppfh,PULINEH Pplh,PUFILEH Ppfhs)//~va79I~
{                                                                  //~va20I~
//	int rc=0,u8len,rc2,ulhlen;                                     //~vaf9R~
  	int rc=0,u8len=0,rc2,ulhlen;                                   //~vaf9I~
    UCHAR *pdata,*pdbcs,*pu8=0;                                    //~vaf9R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**************                                                   //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	pdata=Pplh->ULHdata;                                           //~va20I~
	pdbcs=Pplh->ULHdbcs;                                           //~va20I~
	ulhlen=Pplh->ULHlen;                                           //~va20I~
	if (UCBITCHK(Pplh->ULHflag2,ULHF2TABCHKED))	//dbcs exist       //~va20I~
    {                                                              //~va20I~
		UCBITOFF(Pplh->ULHflag2,ULHF2TABCHKED);	//refresh at filechktabdbcs//~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
  	  if (!swebcfile)                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
      {                                                            //~va50I~
		ulhlen-=sub_restoretabdroppad(0,pdata,pdbcs,ulhlen);//move tabid to data to re-evaluate tab expand//~va20R~
		Pplh->ULHlen=ulhlen;                                       //~va20R~
      }                                                            //~va50I~
    }                                                              //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (!swebcfile && !(Popt & FCVACO_B2))  //source is cpu8;dd fmt  //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
  {                                                                //~va50I~
	if (Popt & FCVACO_DD2L)  //copy utf8 to locale                 //~va20I~
    {                                                              //~va20I~
		rc2=xeutfcvdd2f(0,pdata,pdbcs,ulhlen,&pu8,&u8len,0/*outdbcs*/);         //~va20I~//~va2jR~
    	if (rc2==UALLOC_FAILED)                                    //~va20I~
    		return rc2;                                            //~va20I~
        if (rc2)	//cverr                                        //~va20I~
        	rc=4;                                                  //~va20I~
    }                                                              //~va20I~
    if (pdbcs)                                                     //~va20I~
    {                                                              //~va20I~
    	ufree(pdbcs);	//for filechktabdbcs call                  //~va20R~
    	Pplh->ULHdbcs=pdbcs=0;                                     //~va20R~
    }                                                              //~va20I~
	if (Popt & FCVACO_DD2L)  //copy utf8 to locale                 //~va20I~
    {                                                              //~va20I~
		if (u8len>Pplh->ULHbufflen)                                //~va20I~
    	{                                                          //~va20I~
			if (fileexpandbuff(Pplh,u8len)==UALLOC_FAILED)	//expand if buff over//~va20I~
        		return UALLOC_FAILED;                              //~va20I~
    	}                                                          //~va20I~
        memcpy(Pplh->ULHdata,pu8,(UINT)u8len);                     //~va20R~
        Pplh->ULHlen=ulhlen=u8len;                                 //~va20I~
    }                                                              //~va20I~
  }//not ebc file                                                  //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
	if (Popt & FCVACO_B2)  //source is cpu8;dd fmt                 //~va50M~
		UCBITON(Pplh->ULHflag5,ULHF5COPYCVB2);                     //~va50M~
    else                                                           //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
	if (Popt & FCVACO_DD2L)  //source is cpu8;dd fmt               //~va20R~
		UCBITON(Pplh->ULHflag5,ULHF5COPYCVF2L);                    //~va20I~
    else                                                           //~va20I~
		UCBITON(Pplh->ULHflag5,ULHF5COPYCVL2F);                    //~va20I~
    Shandle=Ppfhs->UFHhandle;   //parm to filecvebcplh             //~va79I~
    rc2=filechktabdbcs(Pplh);   //translate and expand at init for find cmd//~va20I~
    Shandle=0;                                                     //~va79I~
    if (rc2==UALLOC_FAILED)                                        //~va20I~
        return rc2;                                                //~va20I~
    UCBITOFF(Pplh->ULHflag5,ULHF5COPYCVF2L|ULHF5COPYCVL2F); //used //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	UCBITOFF(Pplh->ULHflag5,ULHF5COPYCVB2);                        //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (UCBITCHK(Pplh->ULHflag5,ULHF5LOADCVERR)) //f2l err         //~va20I~
    {                                                              //~va20I~
		filesetlineerr(Pplh);                                      //~va20I~
        rc=4;	//stop copy operation                              //~va20I~
    }                                                              //~va20I~
    return rc;                                                     //~va20I~
}//filecvaftercopy                                                 //~va20I~
#endif//UTF8UCS2                                                   //~va20I~
#endif                                                             //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//**************************************************************** //~va50I~
//!line translation -->ebcdic                                      //~va50I~
//*return:UALLOC_FAILED,1:cv err                                   //~va50R~
//**************************************************************** //~va50I~
int filecvm2b(int Popt,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen)    //~va50I~
{                                                                  //~va50I~
	int rc,len,opt,newlen;                                         //~va50R~
    UCHAR *pdata,*pdbcs;                                           //~va50R~
    int handle;                                                    //~va79I~
//*************                                                    //~va50I~
	handle=Ppfh->UFHhandle; //tgt EBC handle                       //~va79R~
	len=Pplh->ULHlen;                                              //~va50R~
    UTRACED("filecvm2b inp data",Pplh->ULHdata,len);               //~va50I~
    if (Popt & FCVEO_F2B)                                          //~va50I~
		opt=XEEBCO_DD2B;                                           //~va50R~
    else                                                           //~va50I~
		opt=XEEBCO_L2B;                                            //~va50I~
    if (Popt & FCVEO_INITDBCST)                                    //~va50I~
		opt|=XEEBCO_INITDBCST;                                     //~va50R~
    if (Popt & FCVEO_SOSIREP)   //cmd option                       //~va6cI~
		opt|=XEEBCO_SOSICMDR;                                      //~va6cI~
    else                                                           //~va6cI~
    if (Popt & FCVEO_SOSIINS)   //cmd option                       //~va6cI~
		opt|=XEEBCO_SOSICMDI;                                      //~va6cI~
	opt|=XEEBCO_CVCTL;  //tab(0x09)-->ebc:0x05                     //~vajmI~
//  rc=xeebc_m2bsetdbcs(opt,Pplh->ULHdata,Pplh->ULHdbcs,len,&pdata,&pdbcs,&newlen);//~va50R~//~va79R~
    rc=xeebc_m2bsetdbcs(opt,handle,Pplh->ULHdata,Pplh->ULHdbcs,len,&pdata,&pdbcs,&newlen);//~va79I~
    if (newlen>Pplh->ULHbufflen)                                   //~va50I~
		if (fileexpandbuff(Pplh,newlen)==UALLOC_FAILED)	//expand if buff over//~va50I~
        	return UALLOC_FAILED;                                  //~va50I~
//  memcpy(Pplh->ULHdata,pdata,newlen);                            //~va50I~//~vb28R~
    memcpy(Pplh->ULHdata,pdata,(size_t)newlen);                    //~vb28I~
//  memcpy(Pplh->ULHdbcs,pdbcs,newlen);                            //~va50I~//~vb28R~
    memcpy(Pplh->ULHdbcs,pdbcs,(size_t)newlen);                    //~vb28I~
    Pplh->ULHlen=newlen;                                           //~va50I~
    if (Ppnewlen)                                                  //~va50I~
    	*Ppnewlen=newlen;                                          //~va50I~
    UTRACED("filecv 2b out data",Pplh->ULHdata,newlen);            //~va50I~
    UTRACED("filecv 2b out dbcs",Pplh->ULHdbcs,newlen);            //~va50I~
    return rc;                                                     //~va50R~
}//filecvm2b                                                       //~va50I~
//**************************************************************** //~va50I~
//!line translation <--ebcdic                                      //~va50I~
//*return:UALLOC_FAILED                                            //~va50I~
//**************************************************************** //~va50I~
//int filecvb2m(int Popt,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen)    //~va50I~//~va79R~
int filecvb2m(int Popt,int Phandle,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen)//~va79I~
{                                                                  //~va50I~
	int rc,len,opt;                                                //~va50R~
    UCHAR *pdata,*pdbcs;                                           //~va50R~
    int newlen;                                                    //~va6dI~
//*************                                                    //~va50I~
	len=Pplh->ULHlen;                                              //~va50R~
    UTRACED("filecvb2m inp data",Pplh->ULHdata,len);               //~va50I~
    if (Popt & FCVEO_B2DD)                                         //~va50I~
//  	opt=XEEBCO_B2DD|XEEBCO_SOSI2SPACE;                         //~va50R~//~va7vR~
    	opt=XEEBCO_B2DD|XEEBCO_SOSI2SPACE|XEEBCO_DBCSUCSOK;        //~va7vI~
    else                                                           //~va50I~
//  	opt=XEEBCO_B2L|XEEBCO_SOSI2SPACE;                          //~va50R~//~va6cR~
    	opt=XEEBCO_B2L|XEEBCO_SOSI2SPACE|XEEBCO_SETF2LERR;    //keep org value//~va6cR~
    if (Popt & FCVEO_ERRREP)  //rep by errch when trans err ebc->u8/lc//~va50R~
		opt|=XEEBCO_ERRREP;                                        //~va50R~
    if (Popt & FCVEO_SOSIREP)   //cmd option                       //~va6cI~
		opt|=XEEBCO_SOSICMDR;                                      //~va6cI~
    else                                                           //~va6cI~
    if (Popt & FCVEO_SOSIDEL)   //cmd option                       //~va6cI~
		opt|=XEEBCO_SOSICMDD;                                      //~va6cI~
	opt|=XEEBCO_CVCTL;                                             //~va7uI~
    pdata=pdbcs=0;	//request return                               //~va50I~
//  rc=xeebc_b2msetdbcs(opt,Pplh->ULHdata,0/*dbcs*/,len,&pdata,&pdbcs,0/*outlen*/);//~va50R~//~va6dR~
//  rc=xeebc_b2msetdbcs(opt,Pplh->ULHdata,0/*dbcs*/,len,&pdata,&pdbcs,&newlen);//~va6dI~//~va79R~
    rc=xeebc_b2msetdbcs(opt,Phandle,Pplh->ULHdata,0/*dbcs*/,len,&pdata,&pdbcs,&newlen);//~va79R~
    UALLOCCHKRC(rc);                                               //~va6dI~
    if (newlen>Pplh->ULHbufflen)                                   //~va6dI~
		if (fileexpandbuff(Pplh,newlen)==UALLOC_FAILED)	//expand if buff over//~va6dI~
        	return UALLOC_FAILED;                                  //~va6dI~
    len=newlen;                                                    //~va6dI~
//  memcpy(Pplh->ULHdata,pdata,len);                               //~va50R~//~vb28R~
    memcpy(Pplh->ULHdata,pdata,(size_t)len);                       //~vb28I~
//  memcpy(Pplh->ULHdbcs,pdbcs,len);                               //~va50R~//~vb28R~
    memcpy(Pplh->ULHdbcs,pdbcs,(size_t)len);                       //~vb28I~
    if (Ppnewlen)                                                  //~va50I~
    	*Ppnewlen=len;                                             //~va50R~
    Pplh->ULHlen=newlen;                                           //~va6dI~
    UTRACED("filecv b2m out data",Pplh->ULHdata,len);              //~va50R~
    UTRACED("filecv b2m out dbcs",Pplh->ULHdbcs,len);              //~va50R~
    return rc;                                                     //~va50R~
}//filecvb2m                                                       //~va50I~
//**************************************************************** //~va7uI~
//!line translation ebcdic<--ebcdic  (codepage change)             //~va7uI~
//*return:UALLOC_FAILED                                            //~va7uI~
//**************************************************************** //~va7uI~
int filecvb2b(int Popt,int Psrchandle,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen)//~va7uR~
{                                                                  //~va7uI~
	int rc,len,newlen,opt,tgthandle;                               //~va7uR~
    UCHAR *pdata,*pdbcs;                                           //~va7uI~
//*************                                                    //~va7uI~
	tgthandle=Ppfh->UFHhandle;                                     //~va7uR~
	len=Pplh->ULHlen;                                              //~va7uI~
    UTRACED("filecvb2b inp data",Pplh->ULHdata,len);               //~va7uI~
    UTRACED("filecvb2b inp data",Pplh->ULHdbcs,len);               //~va7uI~
    opt=0;                                                         //~va7uI~
//  if (Popt & FCVEO_ERRREP)  //rep by errch when trans err ebc->u8/lc//~va7uR~
//  	opt|=XEEBCO_ERRREP;                                        //~va7uR~
//  opt|=XEEBCO_CVCTL|XEEBCO_SETF2LERR;    //req set F2LERR to ucvebc3_dd2b//~va7uR~//~va7LR~
    opt|=XEEBCO_CVCTL;    //dont set f2lerr to ebc dbcstbl,use it only on psd at tabdiplay//~va7LI~
	rc=xeebc_b2b(opt,Psrchandle,tgthandle,Pplh->ULHdata,Pplh->ULHdbcs,len,&pdata,&pdbcs,&newlen);//~va7uR~
    UALLOCCHKRC(rc);                                               //~va7uI~
    if (newlen>Pplh->ULHbufflen)                                   //~va7uI~
		if (fileexpandbuff(Pplh,newlen)==UALLOC_FAILED)	//expand if buff over//~va7uI~
        	return UALLOC_FAILED;                                  //~va7uI~
    len=newlen;                                                    //~va7uI~
//  memcpy(Pplh->ULHdata,pdata,len);                               //~va7uI~//~vb28R~
    memcpy(Pplh->ULHdata,pdata,(size_t)len);                       //~vb28I~
//  memcpy(Pplh->ULHdbcs,pdbcs,len);                               //~va7uI~//~vb28R~
    memcpy(Pplh->ULHdbcs,pdbcs,(size_t)len);                       //~vb28I~
    Pplh->ULHlen=len;                                              //~va7uI~
    if (Ppnewlen)                                                  //~va7uI~
    	*Ppnewlen=len;                                             //~va7uI~
    UTRACED("filecv b2b out data",Pplh->ULHdata,len);              //~va7uI~
    UTRACED("filecv b2b out dbcs",Pplh->ULHdbcs,len);              //~va7uI~
    return rc;                                                     //~va7uI~
}//filecvb2b                                                       //~va7uI~
//**************************************************************** //~va50I~
//!line translation between ebc and utf8/locale                    //~va50I~
//*parm 1:start plh                                                //~va50I~
//*parm 2:end plh                                                  //~va50I~
//*return:UALLOC_FAILED                                            //~va50R~
//**************************************************************** //~va50I~
int filecvebcplh(int Popt,PUFILEH Ppfh,PULINEH Pplh,int *Ppnewlen) //~va50I~
{                                                                  //~va50I~
	int rc,len,opt=0,rc2=0;                                        //~va50R~
    int optsetdbcst;                                               //~va7xI~
//*************                                                    //~va50I~
	len=Pplh->ULHlen;                                              //~va50R~
    UCBITOFF(Pplh->ULHflag5,ULHF5LOADCVERR); //f2l err             //~va50I~
    for (;;)                                                       //~va50I~
    {                                                              //~va50I~
        if (!Pplh->ULHdbcs) //initial for l2b case                 //~va50I~
        {                                                          //~va50I~
            Pplh->ULHdbcs=UALLOCC(1,(UINT)Pplh->ULHbufflen);       //~va50I~
            UALLOCCHK(Pplh->ULHdbcs,UALLOC_FAILED);   //return 0 if storage shortage//~va50I~
            opt|=FCVEO_INITDBCST;                                  //~va50I~
        }                                                          //~va50I~
        if (PFH_ISEBC(Ppfh))                                       //~va50R~
        {                                                          //~va50R~
	  	  if (Popt & FCEPO_BIN)    //no translation mode           //~va7xI~
          {                                                        //~va7xI~
            optsetdbcst=FSDT_EBC;                                  //~va7xR~
            if (opt & FCVEO_INITDBCST)	//calloc                   //~va7xI~
            	optsetdbcst|=FSDT_CALLOC;                          //~va7xI~
            rc=filesetdbcstblplh(optsetdbcst,Ppfh,Pplh,0/*pos*/,len);//set dbcstbl for ebc//~va7xI~
          }                                                        //~va7xI~
          else                                                     //~va7xI~
          {                                                        //~va7xI~
            if (opt & FCVEO_INITDBCST)                             //~va50R~
            {                                                      //~va50R~
                if (UCBITCHK(Pplh->ULHflag5,ULHF5COPYCMD)) //copy cmd source is ebc//~va50R~
                {                                                  //~va50I~
                	if (UCBITCHK(Pplh->ULHflag5,ULHF5COPYCVF2L)) //copy cmd source is utf8//~va50I~
                    {                                              //~vajnI~
                    	rc2=filecvf2lsetdbcs(FCF2LO_F2DD,Ppfh,Pplh,&len);//utf8-->DD fmt//~va50I~
                        rc2&=~(XEUTFF2LRC_UTF8|XEUTFF2LRC_DBCS);	//not err//~vajnI~
                    }                                              //~vajnI~
                }                                                  //~va50I~
                else                                               //~va50R~
                {                                                  //~va50I~
//                  rc=filesetdbcstblplh(FSDT_EBC,Ppfh,Pplh,0/*pos*/,len);//set dbcstbl for ebc//~va50R~//~va7xR~
                    rc=filesetdbcstblplh(FSDT_EBC|FSDT_CALLOC,Ppfh,Pplh,0/*pos*/,len);//set dbcstbl for ebc//~va7xI~
                    break;                                         //~va50I~
                }                                                  //~va50I~
            }                                                      //~va50R~
            if (UCBITCHK(Pplh->ULHflag5,ULHF5COPYCVB2)) //copy cmd source is ebc//~va50R~
            {                                                      //~va7uI~
              if (Shandle!=Ppfh->UFHhandle) //handle change        //~va7uI~
                rc=filecvb2b(0,Shandle,Ppfh,Pplh,&len);//set dbcstbl for ebc//~va7uI~
              else                                                 //~va7uI~
                rc=filesetdbcstblplh(FSDT_EBC,Ppfh,Pplh,0/*pos*/,len);//set dbcstbl for ebc//~va50R~
            }                                                      //~va7uI~
            else                                                   //~va50R~
            {                                                      //~va50R~
            	if (Popt & FCEPO_SOSIREP)   //replace boundary space//~va6cI~
                    opt|=FCVEO_SOSIREP;                            //~va6cI~
                else                                               //~va6cI~
            	if (Popt & FCEPO_SOSIINS)   //insert so/si         //~va6cR~
                    opt|=FCVEO_SOSIINS;                            //~va6cI~
                if (UCBITCHK(Pplh->ULHflag5,ULHF5COPYCVF2L)) //copy cmd source is utf8//~va50R~
                {                                                  //~va50R~
                    opt|=FCVEO_F2B;                                //~va50R~
                    rc=filecvm2b(opt,Ppfh,Pplh,Ppnewlen);//        //~va50R~
                }                                                  //~va50R~
                else    //not copycmd                              //~va50R~
                if (UCBITCHK(Pplh->ULHflag5,ULHF5COPYCVL2F)) //copy cmd source is locale//~va50R~
                {                                                  //~va50R~
                    opt|=FCVEO_L2B;                                //~va50R~
                    rc=filecvm2b(opt,Ppfh,Pplh,Ppnewlen);//        //~va50R~
                }                                                  //~va50R~
                else    //not copycmd                              //~va50R~
                    rc=filesetdbcstblplh(FSDT_EBC,Ppfh,Pplh,0/*pos*/,len);//set dbcstbl for ebc//~va50R~
            }                                                      //~va50R~
          }//!bin mode                                             //~va7xI~
        }                                                          //~va50R~
        else    //COPYCBB2 is on;copy cmd tgt is not ebc,src is ebc//~va50R~
        {                                                          //~va50R~
            if (Popt & FCEPO_SOSIREP)   //replace by space         //~va6cI~
                opt|=FCVEO_SOSIREP;                                //~va6cI~
            else                                                   //~va6cI~
            if (Popt & FCEPO_SOSIDEL)   //delete so/si             //~va6cR~
                opt|=FCVEO_SOSIDEL;                                //~va6cI~
            opt|=FCVEO_ERRREP;  //rep by errch when trans err ebc->u8/lc//~va50R~
            if (FILEUTF8MODE(Ppfh))//ebc to utf8                   //~va50R~
                opt|=FCVEO_B2DD;                                   //~va50R~
            else                                                   //~va50R~
                opt|=FCVEO_B2L;                                    //~va50R~
//          rc=filecvb2m(opt,Ppfh,Pplh,Ppnewlen);//                //~va50R~//~va79R~
            rc=filecvb2m(opt,Shandle,Ppfh,Pplh,Ppnewlen);//        //~va79I~
        }                                                          //~va50R~
        break;                                                     //~va50I~
    }//for                                                         //~va50I~
    rc|=rc2;	//f2dd rc                                          //~va50I~//~va6cR~
    if (rc)                                                        //~va50I~
    {                                                              //~va6cI~
    	UCBITON(Pplh->ULHflag5,ULHF5LOADCVERR); //f2l err          //~va50I~
		filesetlineerr(Pplh);         //for "f *e" errline search  //~va6cI~
    }                                                              //~va6cI~
    return rc;                                                     //~va50I~
}//filecvebcplh                                                    //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//****************************************************************
//!filetabexp                                                   //~v04dR~
//*expand tab
//*parm1:opt 0:init,1:re-expand                                 //~5102R~
//*parm2:plh                                                    //~5102I~
//*parm3:column                                                 //~5102I~
//*parm4:len                                                    //~5102I~
//*rc   :0:tab detected,4:no tab detected or UALLOC_FAILED      //~v04dR~
//****************************************************************
int filetabexp(int Preexpsw,PULINEH Pplh,int Pcol,int *Plen)    //~5102R~
{
	int ii,len,reslen;
	int tabskip;
    int binsw;                                                     //~v106I~
	UCHAR *pc,*pco=0,*pc2,*pcd,*pcdo=0,*pcd2;                      //~vaf9R~
	UCHAR *pc2e;			//limit addr                           //~v0bbI~
    PUFILEH pfh;                                                   //~v106I~
//    int dbcs2ndsw;                                               //~v73vR~
#ifdef UTF8UCS2                                                    //~va20R~
    int swutf8file;                                                //~va20R~
#endif                                                             //~va20R~
//*****************
    pfh=UGETPFH(Pplh);                                             //~v106I~
  if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                            //~v106I~
  {                                                                //~v106I~
    tabskip=1;                                                     //~v106I~
    binsw=1;                                                       //~v106I~
  }	                                                               //~v106I~
  else                                                             //~v106I~
  {                                                                //~v106I~
    binsw=0;                                                       //~v106I~
//  tabskip=max(Gfiletabskip,1);                                   //~v8@2R~
    tabskip=max(pfh->UFHtabskip,1);                                //~v8@2I~
  }                                                                //~v106I~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
#endif                                                             //~va20I~
	UCBITON(Pplh->ULHflag2,ULHF2TABCHKED);//not first time      //~5102I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
    if (PFH_ISEBC(pfh))                                            //~va50I~
    	return 4; //no tab detected                                //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
	pc2=Gfilebuff;                                              //~5102R~
    pc2e=Gfilebuff+GFILEBUFFSZ-TABCTRMAX;                          //~v0bbR~
	pcd2=Gfilebuff2;                                            //~5102I~
	pc=Pplh->ULHdata+Pcol;                                      //~5102R~
	pcd=Pplh->ULHdbcs+Pcol;                                     //~5102I~
	reslen=*Plen;                                        //~5102R~
	while(reslen)                                               //~4C23R~
	{
		pco=pc;
		pcdo=pcd;                                               //~5102I~
		if (Preexpsw)                                           //~5102I~
		{                                                       //~5102I~
//*memchr on dbcstbl                                               //~va20I~
//!ebc                                                             //~va50I~
			if (!(pcd=memchr(pcd,TABCHAR,(UINT)reslen)))        //~5102I~
				break;                                          //~5102I~
//			len=(int)((ULONG)pcd-(ULONG)pcdo);                 //~4C23R~//~vafkR~
			len=(int)((ULPTR)pcd-(ULPTR)pcdo);                     //~vafkI~
			pc+=len;
//            dbcs2ndsw=0;                                         //~v73vR~
		}                                                       //~5102I~
		else    
		{                                                //~5102I~
#ifdef UTF8UCS2                                                    //~va20I~
//!ebc                                                             //~va50I~
//  		if (!(pc=UTF_MEMCHR(swutf8file,pc,pcd,TABCHAR,(UINT)reslen)))//~va20I~//~vb28R~
    		if (!(pc=UTF_MEMCHR(swutf8file,pc,pcd,TABCHAR,reslen)))//~vb28I~
#else                                                              //~va20I~
			if (!(pc=memchr(pc,TABCHAR,(UINT)reslen)))          //~5102R~
#endif                                                             //~va20I~
				break;                                          //~5102R~
//			len=(int)((ULONG)pc-(ULONG)pco);                    //~4C23R~//~vafkR~
			len=(int)((ULPTR)pc-(ULPTR)pco);                       //~vafkI~
			pcd+=len;
//            dbcs2ndsw=(*pcd==DBCS2NDCHAR);                       //~v73vR~
		}
        if (pc2+len>pc2e)				//buff overflow            //~v0bbI~
			return filetabexpanderr();                             //~v0bbI~
		memcpy(pc2,pco,(UINT)len);                              //~4C23R~
		memcpy(pcd2,pcdo,(UINT)len);                            //~5102I~
		pc2+=len;                                               //~4C23R~
		pcd2+=len;                                              //~5102I~
        reslen-=len;                                            //~4C23I~
//      if (dbcs2ndsw)                                             //~v73vR~
//      {                                                          //~v73vR~
//        *pc2++=*pc++;                                            //~v73vR~
//        *pcd2++=*pcd++;                                          //~v73vR~
//        reslen--;                                                //~v73vR~
//      }                                                          //~v73vR~
//      else                                                       //~v73vR~
//      {                                                          //~v73vR~
//!ebc                                                             //~va50I~
		*pc2++=' ';                                             //~5102R~
		pc++;				//skip tab char                     //~4C23R~
		*pcd2++=TABCHAR;                                        //~5102I~
		pcd++;				//skip tab char                     //~5102I~
        reslen--;                                               //~4C23I~
//  	ii=TABSKIPCTR((int)((ULONG)pc2-(ULONG)Gfilebuff-1+Pcol));  //~v106R~
//  	ii=TABSKIPCTR2(binsw,(int)((ULONG)pc2-(ULONG)Gfilebuff-1+Pcol));//~v8@2R~
//    	ii=TABSKIPCTR2F(binsw,tabskip,(int)((ULONG)pc2-(ULONG)Gfilebuff-1+Pcol));//~v8@2I~//~vafkR~
//  	ii=TABSKIPCTR2F(binsw,tabskip,(int)((ULPTR)pc2-(ULPTR)Gfilebuff-1+Pcol));//~vafkI~//~vb28R~
    	ii=TABSKIPCTR2F(binsw,tabskip,((int)((ULPTR)pc2-(ULPTR)Gfilebuff)-1+Pcol));//~vb28I~
        				//0 if binfile                             //~v106I~
		for (;ii>0;ii--)                                        //~4C23R~
		{                                                       //~5102I~
//!ebc                                                             //~va50I~
			*pc2++=' ';                                         //~5102R~
			*pcd2++=TABPADCHAR;                                 //~5102I~
		}                                                       //~5102I~
		if (Preexpsw)                                           //~5102I~
			while(reslen && *pcd==TABPADCHAR)	//drop previous tab advance char//~5102I~
			{                                                   //~5102I~
				pc++;                                           //~5102I~
				pcd++;                                          //~5102I~
				reslen--;                                       //~5102I~
			}                                                   //~5102I~
//      }//not tab                                                 //~v73vR~
	}//end of string
	if (pc2==Gfilebuff)	//no tab detected                       //~5102R~
		return 4;
	memcpy(pc2,pco,(UINT)reslen);	//last residual             //~4C23R~
	memcpy(pcd2,pcdo,(UINT)reslen);	//last residual             //~5102I~
//	*Plen=len=(int)((ULONG)pc2-(ULONG)Gfilebuff)+reslen;        //~5102R~//~vafkR~
	*Plen=len=(int)((ULPTR)pc2-(ULPTR)Gfilebuff)+reslen;           //~vafkI~
                                                                //~5102I~
	Pplh->ULHtabskip=tabskip;	//not first,tabskip when checked//~5102I~
	UCBITON(Pplh->ULHflag2,ULHF2TABFOUND);	//chk at file write //~5102I~
	if (Smerginoffs)//from fileimtabexp                            //~v0evR~
    {                                                              //~v0evI~
        if (len>Smerginoffs)                                       //~v0evR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//*retuned if ebc file                                             //~va50I~
        	setobtabdbcs(0,0,Gfilebuff,Gfilebuff2,len,Smerginoffs,len-Smerginoffs);//~va50I~
#else                                                              //~va50I~
        	setobtabdbcs(Gfilebuff,Gfilebuff2,len,Smerginoffs,len-Smerginoffs);//~v0evR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        else                                                       //~v73mI~
        {                                                          //~v73mI~
//!ebc                                                             //~va50I~
            memset(Gfilebuff+len,' ',(UINT)(Smerginoffs-len));//fill space(shorten case)//~v73mR~
            memset(Gfilebuff2+len,0,(UINT)(Smerginoffs-len));      //~v73mR~
        }                                                          //~v73mI~
    	len=Smerginoffs;                                           //~v0evR~
	}                                                              //~v0evI~
    else                                                           //~v0evM~
    {                                                              //~v0evI~
	if (Pcol+len>Pplh->ULHbufflen)                                 //~v08bI~
		if (fileexpandbuff(Pplh,Pcol+len)==UALLOC_FAILED)	//expand if buff over//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
	Pplh->ULHlen=Pcol+len;                                         //~v0evR~
    }                                                              //~v0evI~
	memcpy(Pplh->ULHdata+Pcol,Gfilebuff,(UINT)len);	//all record//~5102I~
	memcpy(Pplh->ULHdbcs+Pcol,Gfilebuff2,(UINT)len);	//all record//~5102I~
	return 0;
}//filetabexp
                                                                //~5102I~
//**************************************************************** //~v0evI~
//!fileimtabexp                                                    //~v0evI~
//*parm1:plh                                                       //~v0evI~
//*parm2:column                                                    //~v0evI~
//*parm3:expand chk len,out:expanded len(optional)                 //~v0evR~
//*parm4:mergin                                                    //~v0evI~
//*rc   :0:tab detected,4:no tab detected                          //~v0evR~
//**************************************************************** //~v0evI~
int fileimtabexp(PULINEH Pplh,int Pcol,int *Pplen,int Pmergin)     //~v0evR~
{                                                                  //~v0evI~
	int rc;                                                        //~v0evI~
    int len;                                                       //~v0evI~
//************************                                         //~v0evI~
	Smerginoffs=Pmergin-Pcol;                                      //~v0evR~
    if (Smerginoffs<=0) //for safety,currentry called when Pcol<Pmergin//~v73cR~
        return 0;                                                  //~v73cR~
    if (Pplen)                                                     //~v0evI~
    	len=*Pplen;                                                //~v0evI~
    else                                                           //~v0evI~
//  	len=Pmergin;                                               //~v73cR~
    	len=Smerginoffs;	//filetabexp access beyond dbcs area   //~v73cR~
	rc=filetabexp(1,Pplh,Pcol,&len);                               //~v0evR~
	Smerginoffs=0;                                                 //~v0evR~
    if (Pplen)                                                     //~v0evI~
    	*Pplen=len;                                                //~v0evI~
    return rc;                                                     //~v0evI~
}                                                                  //~v0evI~
//fileimtabexp                                                     //~v0evI~
//**************************************************************** //~v0avI~
//!filegettabexplen                                                //~v0avR~
//*calculate tab expand length                                     //~v0avI~
//*parm1:plh                                                       //~v0avI~
//*parm2:offset                                                    //~v0avI~
//*parm3:adddata                                                   //~v0avR~
//*parm4:addlen                                                    //~v0avI~
//*parm5:dellen                                                    //~v0avI~
//*parm6:reclen to see without last tab                            //~v0bzR~
//*rc   :add length ,0 if addlen<=dellen and no tab data           //~v0avR~
//**************************************************************** //~v0avI~
#ifdef UTF8UCS2                                                    //~va20I~
int filegettabexplen(PULINEH Pplh,int Pcol,char *Padddata,char *Padddbcs/*dd fmt for u8 file*/,//~va20I~
#else                                                              //~va20I~
int filegettabexplen(PULINEH Pplh,int Pcol,char *Padddata,         //~v0bzR~
#endif                                                             //~va20I~
					int Paddlen,int Pdellen,int Plen)              //~v0bzR~
{                                                                  //~v0avI~
	int len,reslen,cpos,addlen,addskip;                            //~v0avR~
    int tabskip;                                                   //~v8@2I~
	UCHAR *pcd,*pcdo,*pc,*pco;                                     //~v0avR~
//  int tabsw=0;                                                   //~v0bzR~
    int binsw;                                                     //~v106I~
    PUFILEH pfh;                                                   //~v106I~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
//*****************                                                //~v0avI~
    pfh=UGETPFH(Pplh);                                             //~v106I~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
#endif                                                             //~va20I~
    tabskip=pfh->UFHtabskip;                                       //~v8@2I~
  if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                            //~v106I~
    binsw=1;                                                       //~v106I~
  else                                                             //~v106I~
    binsw=0;                                                       //~v106I~
    addlen=Paddlen-Pdellen;                                        //~v0avR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	if (PFH_ISEBC(pfh))                                            //~va50I~
        return addlen;                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*isrt data                                                       //~v0avI~
    cpos=Pcol;                                                     //~v0avM~
    if (Padddata)	//data specified                               //~v0avI~
    {                                                              //~v0avI~
    	pc=Padddata;                                               //~v0avR~
        reslen=Paddlen;                                            //~v0avR~
    	while(reslen)                                              //~v0avR~
    	{                                                          //~v0avR~
    		pco=pc;                                                //~v0avR~
#ifdef UTF8UCS2                                                    //~va20I~
    		pcd=XEUTF_PC2PCD(Padddbcs,pc,Padddata);                //~va20I~
//!ebc                                                             //~va50I~
    		if (!(pc=UTF_MEMCHR(swutf8file&&Padddbcs,pc,pcd,TABCHAR,reslen)))//~va20R~
#else                                                              //~va20I~
    		if (!(pc=memchr(pc,TABCHAR,(UINT)reslen)))             //~v0avR~
#endif                                                             //~va20I~
            {                                                      //~v0avR~
            	cpos+=reslen;                                      //~v0avR~
    			break;                                             //~v0avR~
    		}                                                      //~v0avR~
//          tabsw=1;                                               //~v0bzR~
    		pc++;				//skip tab char                    //~v0avR~
//    		len=(int)((ULONG)pc-(ULONG)pco);                       //~v0avR~//~vafkR~
    		len=(int)((ULPTR)pc-(ULPTR)pco);                       //~vafkI~
    		cpos+=len;                                             //~v0avR~
            reslen-=len;                                           //~v0avR~
//  		addskip=TABSKIPCTR(cpos-1);                            //~v106R~
//    		addskip=TABSKIPCTR2(binsw,cpos-1);                     //~v8@2R~
      		addskip=TABSKIPCTR2F(binsw,tabskip,cpos-1);            //~v8@2R~
    		addlen+=addskip;                                       //~v0avR~
            cpos+=addskip;                                         //~v0avR~
    	}//end of string                                           //~v0avR~
    }                                                              //~v0avI~
    else	//for ")" lcmd no data,but all space                   //~v0avI~
    	cpos+=Paddlen;	//has no tab                               //~v0avI~
//  if (!tabsw && Paddlen<=Pdellen)	//no expand occur              //~v0bzR~
//  	return 0;                                                  //~v0bzR~
//*after isrt data                                                 //~v0avR~
	pcd=Pplh->ULHdbcs+Pcol+Pdellen;	//assume pad char rep to space //~v0avM~
//  reslen=Pplh->ULHlen-Pcol-Pdellen;                              //~v0bzR~
    reslen=Plen-Pcol-Pdellen;                                      //~v0bzI~
	while(reslen>0)                                                //~v0avR~
	{                                                              //~v0avI~
		pcdo=pcd;                                                  //~v0avI~
//*memchr on dbcstbl                                               //~va20I~
//!ebc                                                             //~va50I~
		if (!(pcd=memchr(pcd,TABCHAR,(UINT)reslen)))               //~v0avI~
			break;                                                 //~v0avI~
		pcd++;				//skip tab char                        //~v0avI~
//		len=(int)((ULONG)pcd-(ULONG)pcdo);                         //~v0avI~//~vafkR~
		len=(int)((ULPTR)pcd-(ULPTR)pcdo);                         //~vafkI~
		cpos+=len;                                                 //~v0avI~
        reslen-=len;                                               //~v0avI~
//  	addskip=TABSKIPCTR(cpos-1);                                //~v106R~
//  	addskip=TABSKIPCTR2(binsw,cpos-1);                         //~v8@2R~
    	addskip=TABSKIPCTR2F(binsw,tabskip,cpos-1);                //~v8@2I~
        cpos+=addskip;                                             //~v0avM~
		while(reslen && *pcd==TABPADCHAR)	//drop previous tab advance char//~v0avI~
		{                                                          //~v0avI~
			pcd++;                                                 //~v0avI~
			reslen--;                                              //~v0avI~
            addskip--;                                             //~v0avR~
		}                                                          //~v0avI~
        if (!addskip)	//no more len change                       //~v0bzR~
        	break;                                                 //~v0bzR~
        addlen+=addskip;                                           //~v0avI~
	}//end of string                                               //~v0avI~
	return addlen;                                                 //~v0avI~
}//filegettabexplen                                                //~v0avR~
//**************************************************************** //~v73gI~
//!filegettabexplenhex                                             //~va50R~
//*filegettabexplenhex is not called for utf8 file from chrfldedit(MERGIN_HEX is off)//~va20I~
//*filegettabexplenhex is not called for ebc file from chrfldedit(MERGIN_HEX is off)//~va50I~
//ret:rc addlen if short rec expanded                              //~v73gI~
//**************************************************************** //~v73gI~
int filegettabexplenhex(int Popt,PULINEH Pplh,int Pcol,char *Padddata,int Paddlen,int Pdellen,//~v73gI~
							int Pmargin,int *Ppaddlen)             //~v73gI~
{                                                                  //~v73gI~
    int binsw,reslen,rc,cpos,addskip,mode,addch,addlen;     //~v73gR~
    int tabskip;                                                   //~v8@2I~
    PUFILEH pfh;                                                   //~v73gI~
    UCHAR *pc,*pcd,*pc2,*pcd2;                                     //~v73gI~
//*****************                                                //~v73gI~
    pfh=UGETPFH(Pplh);                                             //~v73gI~
    tabskip=pfh->UFHtabskip;                                       //~v8@2I~
  	if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                          //~v73gI~
    	binsw=1;                                                   //~v73gI~
  	else                                                           //~v73gI~
    	binsw=0;                                                   //~v73gI~
	pc2=Gfilebuff;                                                 //~v73gI~
	pcd2=Gfilebuff2;                                               //~v73gI~
//  oomlen=max(0,Pplh->ULHlen-Pmargin);                            //~v73gI~
    memcpy(pc2,Pplh->ULHdata,(UINT)Pmargin);                             //~v73gI~
    memcpy(pcd2,Pplh->ULHdbcs,(UINT)Pmargin);                            //~v73gI~
    if (Paddlen)                                                   //~v73gI~
    {                                                              //~v73gI~
	    if (Pdellen)                                               //~v73gI~
	    	mode=UDBTH_REP;                                        //~v73gI~
        else                                                       //~v73gI~
	    	mode=UDBTH_INS;                                        //~v73gI~
        addch=*Padddata;                                           //~v73gI~
    }                                                              //~v73gI~
    else                                                           //~v73gI~
    {                                                              //~v73gI~
	    mode=UDBTH_DEL;                                            //~v73gI~
        addch=0;                                                   //~v73gI~
    }                                                              //~v73gI~
//  rc=updatedbcstblhex(mode,pc2,pcd2,Pmargin,Pcol,addch,&addlen);//create dbcstbl//~v73qR~
	rc=updatedbcstblhex(mode,pc2,pcd2,Pmargin,Pcol,addch,&addlen,0);//create dbcstbl//~v73qI~
    cpos=Pcol;                                                     //~v73gI~
    if (rc)	//dbcs split                                           //~v73gI~
    	cpos--;                                                    //~v73gI~
    pc=pc2+cpos;                                                   //~v73gI~
    pcd=pcd2+cpos;                                                 //~v73gR~
    reslen=Pmargin+addlen-cpos;                                    //~v73gI~
    rc=0;                                                          //~v73gI~
    for (;reslen>0;pc++,pcd++,reslen--,cpos++)                     //~v73gR~
    {                                                              //~v73gI~
        if (Pmargin && cpos>=Pmargin)                              //~v73gR~
        {                                                          //~v73gI~
            rc|=1;                                                 //~v73gI~
//*filegettabexplenhex is not called for utf8 file,nand ebcfile    //~va50R~
            if (*pc!=' ')                                          //~v73gR~
            	rc=4;                                              //~v73gI~
        }                                                          //~v73gI~
//!ebc                                                             //~va50I~
    	if (*pcd==TABCHAR)                                         //~v73gI~
        {                                                          //~v73gI~
//      	addskip=TABSKIPCTR2(binsw,cpos);                       //~v8@2R~
        	addskip=TABSKIPCTR2F(binsw,tabskip,cpos);              //~v8@2R~
            cpos+=addskip;                                         //~v73gR~
        }                                                          //~v73gI~
    }                                                              //~v73gI~
    if (Ppaddlen)                                                  //~v73gR~
    {                                                              //~v73gI~
    	if (cpos<Pmargin)                                          //~v73gI~
        	addlen=Pplh->ULHlen-cpos;                              //~v73gI~
        else                                                       //~v73gI~
        	addlen=0;                                              //~v73gI~
    	*Ppaddlen=addlen;                                          //~v73gR~
    }                                                              //~v73gI~
    return rc;                                                     //~v73gI~
}//filegettabexplenhex                                             //~v73gI~
//**************************************************************** //~v71UI~
//!filegettabexplenofmargined                                      //~v71UI~
//*calculate tab expand length and chk margin overflow of non space/tab char//~v71UI~
//*parm1:plh                                                       //~v71UI~
//*parm2:offset (assumed in margin)                                //~v71UR~
//*parm3:adddata                                                   //~v71UI~
//*parm4:addlen                                                    //~v71UI~
//*parm5:dellen                                                    //~v71UI~
//*parm6:reclen to see without last tab                            //~v71UI~
//*rc   :4:marginoverflow,1:overflow but tab/space only            //~v71UR~
//**************************************************************** //~v71UI~
int filegettabexplenofmargined(int Popt,int Pmargin,PULINEH Pplh,int Pcol,char *Padddata,//~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
					char *Padddbcs,                                //~va20I~
#endif                                                             //~va20I~
					int Paddlen,int Pdellen,int Plen,int *Ppaddlen)//~v71UI~
{                                                                  //~v71UI~
	int reslen,cpos,addlen,addskip;                                //~v71UR~
    int tabskip;                                                   //~v8@2I~
	UCHAR *pcd,*pc,*pcm;                                           //~v71UR~
    int binsw,rc=0;                                                //~v71UI~
    PUFILEH pfh;                                                   //~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************                                                //~v71UI~
    if (Popt & MERGIN_HEX) //not char boundary                     //~v73gR~
		return filegettabexplenhex(Popt,Pplh,Pcol,Padddata,Paddlen,Pdellen,Pmargin,Ppaddlen);//~v73gR~
    pfh=UGETPFH(Pplh);                                             //~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(pfh);                                  //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD                                                    //~va50I~
    swebcfile=PFH_ISEBC(pfh);                                      //~va50R~
#endif //UTF8EBCD                                                  //~va50I~
    tabskip=pfh->UFHtabskip;                                       //~v8@2I~
  if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                            //~v71UI~
    binsw=1;                                                       //~v71UI~
  else                                                             //~v71UI~
    binsw=0;                                                       //~v71UI~
    addlen=Paddlen-Pdellen;                                        //~v71UI~
//*isrt data                                                       //~v71UI~
    cpos=Pcol;                                                     //~v71UI~
    if (Padddata)	//data specified                               //~v71UI~
    {                                                              //~v71UI~
    	pc=Padddata;                                               //~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
    	pcd=Padddbcs;                                              //~va20I~
#endif                                                             //~va20I~
        reslen=Paddlen;                                            //~v71UI~
    	while(reslen)                                              //~v71UI~
    	{                                                          //~v71UI~
            if (cpos>=Pmargin)                                     //~v71UI~
            {                                                      //~v71UI~
            	rc|=1;                                             //~v71UI~
#ifdef UTF8EBCD                                                    //~va50I~
    	      if (swebcfile)                                       //~va50R~
              {                                                    //~va50I~
            	if (!UCVEBC_ISSPACE(*pc,*pcd))                     //~va50I~
                	rc=4;                                          //~va50I~
              }                                                    //~va50I~
              else                                                 //~va50I~
#endif //UTF8EBCD                                                  //~va50I~
              {                                                    //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
//!ebc                                                             //~va50I~
            	if (UTF_ne(Padddbcs,*pc,*pcd,TABCHAR) && UTF_ne(Padddbcs,*pc,*pcd,' '))//~va20I~
#else                                                              //~va20I~
            	if (*pc!=TABCHAR && *pc!=' ')                      //~v71UI~
#endif                                                             //~va20I~
                	rc=4;                                          //~v71UI~
              }                                                    //~va50I~
            }                                                      //~v71UI~
    		pc++;				//skip tab char                    //~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
    		pcd++;                                                 //~va20I~
#endif                                                             //~va20I~
    		cpos++;                                                //~v71UI~
            reslen--;                                              //~v71UI~
#ifdef UTF8EBCD                                                    //~va50I~
    	  if (!swebcfile)                                          //~va50R~
#endif //UTF8EBCD                                                  //~va50I~
          {//!ebc                                                  //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
//!ebc                                                             //~va50I~
            if (UTF_eq(Padddbcs,*(pc-1),*(pcd-1),TABCHAR))         //~va20I~
#else                                                              //~va20I~
            if (*(pc-1)==TABCHAR)                                  //~v71UI~
#endif                                                             //~va20I~
            {                                                      //~v71UI~
//      		addskip=TABSKIPCTR2(binsw,cpos-1);                 //~v8@2R~
        		addskip=TABSKIPCTR2F(binsw,tabskip,cpos-1);        //~v8@2R~
    			addlen+=addskip;                                   //~v71UI~
            	cpos+=addskip;                                     //~v71UI~
            }                                                      //~v71UI~
          }//!ebc                                                  //~va50I~
    	}//end of string                                           //~v71UI~
    }                                                              //~v71UI~
    else	//for ")" lcmd no data,but all space                   //~v71UI~
    	cpos+=Paddlen;	//has no tab                               //~v71UI~
//*after isrt data                                                 //~v71UI~
	pc=Pplh->ULHdata+Pcol+Pdellen;	//assume pad char rep to space //~v71UI~
	pcd=Pplh->ULHdbcs+Pcol+Pdellen;	//assume pad char rep to space //~v71UI~
    reslen=Plen-Pcol-Pdellen;                                      //~v71UI~
	if (Pmargin<Plen)	//already margin data exist                //~v71UI~
    	pcm=Pplh->ULHdata+Pmargin; 	//margin top addr              //~v71UI~
    else                                                           //~v71UI~
		pcm=0;                                                     //~v71UI~
	while(reslen>0)                                                //~v71UI~
	{                                                              //~v71UI~
        if (cpos>=Pmargin)                                         //~v71UI~
        {                                                          //~v71UI~
            rc|=1;                                                 //~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD                                                //~va50I~
            if (UCVEBCUTF_nespace(swebcfile,swutf8file,*pc,*pcd))  //~va50I~
	#else                                                          //~va50I~
            if (UTF_nespace(swutf8file,*pc,*pcd))                  //~va20R~
	#endif //UTF8EBCD                                              //~va50I~
#else                                                              //~va20I~
            if (*pc!=' ')                                          //~v71UI~
#endif                                                             //~va20I~
                if (!pcm||pc<pcm)	//no chk for original margin data//~v71UI~
                rc=4;                                              //~v71UI~
        }                                                          //~v71UI~
		pc++;				//skip tab char                        //~v71UR~
		pcd++;				//skip tab char                        //~v71UI~
		cpos++;                                                    //~v71UI~
        reslen--;                                                  //~v71UI~
#ifdef UTF8EBCD                                                    //~va50I~
      if (!swebcfile)                                              //~va50R~
#endif //UTF8EBCD                                                  //~va50I~
      {//!ebc                                                      //~va50I~
		if (*(pcd-1)==TABCHAR)                                     //~v71UI~
        {                                                          //~v71UI~
//  		addskip=TABSKIPCTR2(binsw,cpos-1);                     //~v8@2R~
    		addskip=TABSKIPCTR2F(binsw,tabskip,cpos-1);            //~v8@2I~
        	cpos+=addskip;                                         //~v71UI~
			while(reslen && *pcd==TABPADCHAR)	//drop previous tab advance char//~v71UI~
			{                                                      //~v71UI~
            	pc++;                                              //~v71UI~
				pcd++;                                             //~v71UI~
				reslen--;                                          //~v71UI~
            	addskip--;                                         //~v71UI~
			}                                                      //~v71UI~
	        addlen+=addskip;                                       //~v71UI~
        }                                                          //~v71UI~
      }//!ebc                                                      //~va50I~
	}//end of string                                               //~v71UI~
    if (Ppaddlen)        //optional                                //~v71UI~
	    *Ppaddlen=addlen;                                          //~v71UR~
    if (rc>=4)                                                     //~v71UI~
    	return 4;                                                  //~v71UI~
	return rc;                                                     //~v71UI~
}//filegettabexplenofmargined                                      //~v71UI~
#ifdef UTF8SUPPH                                                   //~va15I~
//**************************************************************** //~va15I~
// getdbcsspace                                                    //~va15I~
//*rc   :err                                                       //~va15I~
//**************************************************************** //~va15I~
int getdbcsspace(char *Ppdbcsspace)                                //~va15I~
{                                                                  //~va15I~
//#define UNICODE_IDEOGRAPHIC_SPACE  0x3000	//u-3000(e38080) ->8140(sjis),a1a1(gb18030,ko_kr)//~va15I~//~vamFR~
	char dbcsspace[MAX_MBCSLEN];                                   //~va15I~
    int dbcssz;                                                    //~va15I~
//*****************                                                //~va15I~
//	if (utfcvu2lany1mb(0,UNICODE_IDEOGRAPHIC_SPACE,dbcsspace,&dbcssz))//~va15I~//~va44R~
	if (utfcvu2lany1mb(0,DBCSSPACE_UCS,dbcsspace,&dbcssz))         //~va44I~
    	return 4;                                                  //~va15I~
    if (dbcssz!=2)                                                 //~va15I~
    	return 4;                                                  //~va15I~
	memcpy(Ppdbcsspace,dbcsspace,2);                               //~va15I~
UTRACEP("getdbcsspace %02x%02x\n",dbcsspace[0],dbcsspace[1]);      //~va15I~
    return 0;                                                      //~va15I~
}//getdbcsspace                                                    //~va15I~
#endif                                                             //~va15I~
//****************************************************************
// tabdisplay
//*display tab char,dbcs space if japanese mode                 //~5502R~
//*parm1:sd data                                                //~5102I~
//*parm2:sd dbcs                                                //~5102I~
//*parm3:len                                                    //~5102I~
//*rc   :1 tab/dbcs space  detected,0:not detected              //~5502R~
//****************************************************************
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int tabdisplay(PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Pbinsw)//~va50I~
#else                                                              //~va50I~
int tabdisplay(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Pbinsw)      //~v20UR~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
{                                                               //~5502R~
	int len,reslen,rc;                                          //~5502R~
    int asciisw;                                                   //~v43yI~
    int dbcsspace1,dbcsspace2;                                     //~v21iI~
	UCHAR *pc,*pcd;                       //~5102R~
#ifdef UTF8UCS2                                                    //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	PUFILEH pfh;                                                   //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
    int tdopt;                                                     //~va20R~
    UCHAR dbcsid;                                                  //~va20I~
#endif                                                             //~va20R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
	int width4;                                                    //~va3xR~
#endif                                                             //~va3xI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebc=0;                                                   //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
    int optxpr;                                                    //~va47I~
//    int altch;                                                     //~vb3tR~//~vb3vR~
//    UWUCS ucssbcs;                                                 //~vb2RI~//~vb2SR~
//*****************
//*unprintable char                                                //~v09UI~
UTRACED("tabdisplay plhdata",Pplh->ULHdata,Pplh->ULHlen);          //~va50I~
UTRACED("tabdisplay plhdbcs",Pplh->ULHdbcs,Pplh->ULHlen);          //~va50I~
UTRACED("tabdisplay data in",Pdata,Plen);                          //~va46I~
UTRACED("tabdisplay dbcs in",Pdbcs,Plen);                          //~va46I~
#ifdef UTF8UCS2                                                    //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    tdopt=Pbinsw;                                                  //~va50I~
#else                                                              //~va50I~
    tdopt=Pbinsw & ~FILETDO_BINSWMASK;                             //~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    Pbinsw&=FILETDO_BINSWMASK;                                     //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	pfh=UGETPFH(Pplh);                                             //~va50I~
  	if (PFH_ISEBC(pfh)                                             //~va50R~
  	&&  Pplh->ULHtype==ULHTDATA	//file data                        //~va50R~
  	)                                                              //~va50R~
  	{                                                              //~va50R~
		xeebc_b2mpsd(0,Pplh,Pdata,Pdbcs,Plen,tdopt); //preprocess(cv ebc to mb)//~va50R~
    	swebc=1;                                                   //~va50R~
		if (XEEBC_ISDDFMTPSD())    //output dd fmt on psd          //~va50I~
	  		tdopt|=FILETDO_UTF8;                                   //~va50I~
  	}                                                              //~va50R~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
#endif                                                             //~va20R~
    rc=0;                                                          //~v09UI~
	pc=Pdata;                                                      //~v09UI~
	pcd=Pdbcs;                                                     //~v09UI~
	reslen=Plen;                                                   //~v09UI~
    asciisw=(Pbinsw && UCBITCHK(Gopt4,GOPT47BIT));	//if ASCII on  //~v43yR~
	if (tdopt & FILETDO_UTF8)	//UTF8 file                        //~va47I~
        optxpr=UTFGVACO_GETDD;                                     //~va47I~
    else                                                           //~va47I~
        optxpr=UTFGVACO_GETLC;                                     //~va47I~
	if (tdopt & FILETDO_UTF8)	//UTF8 file                        //~vb28I~
    {                                                              //~vb28I~
    	if (UDBCSCHK_DBCS2NDU(*pcd))	//split at left            //~vb28I~
        	rc=1;//celldraw                                        //~vb28I~
    }                                                              //~vb28I~
    else                                                           //~vb28I~
    {                                                              //~vb28I~
    	if (UDBCSCHK_DBCSNOT1ST_L(*pcd))	//split at left,dbcs 2nd or pad//~vb28R~
        	rc=1;//celldraw                                        //~vb28I~
    }                                                              //~vb28I~
//  for(;reslen;reslen--,pc++,pcd++)                               //~va6tR~
    for(;reslen>0;reslen--,pc++,pcd++)                             //~va6tI~
    {                                                              //~v09UI~
#ifdef UTF8UCS2                                                    //~va20R~
	  if (tdopt & FILETDO_UTF8)	//UTF8 file                        //~va20R~
      {                                                            //~va20R~
        dbcsid=*pcd;                                               //~va20I~
    	if (!UDBCSCHK_ISUCSSBCS(dbcsid))	//not sbcs             //~va20R~
        {                                                          //~va20R~
    		if (UDBCSCHK_DBCS1STUCS2NW(dbcsid))//wide dbcs or narrow dbcs//~va20R~
        	{                                                      //~va20R~
				if (UCBITCHK(Gopt,GOPTTABDISPLAY))//tab on         //~va20I~
                {                                                  //~va20I~
                    if (*pc==(DBCSSPACE_UCS>>8)                    //~va20R~
                    &&  reslen>1 && *(pc+1)==(DBCSSPACE_UCS&0xff)  //~va20R~
                    )                                              //~va20R~
                    {                                              //~va20R~
//#ifdef XXE                                                         //~va2jI~//~va47R~
//                      if (tdopt & FILETDO_PRINT)    //rep at xxe   //~va2jI~//~va47R~
//#endif                                                             //~va2jI~//~va47R~
                        if (!(tdopt & FILETDO_PRINTGUI))	//GUI print print dbcs space//~va46I~
                                                                     //~va2jI~//~va47R~
                        {                                            //~va2jI~//~va47R~
//                        *pc=Gunpdispchar[3];                       //~va20R~//~va47R~//~vb3qR~
//                        *(pc+1)=Gunpdispchar[3];                   //~va20R~//~va47R~//~vb3qR~
//*use DEFAULT_ALTCH(0xff) to reset to altch at ulib               //~vb3xR~
//#ifndef SSS                                                      //~vb3xR~
//                         if (tdopt & FILETDO_PRINT)  //xpr cmd,else leave as u-3000/NP1+NP2//~vb3xR~
//#endif                                                           //~vb3xR~
                         {                                         //~vb3xI~
                          *pc=DEFAULT_ALTCH;                       //~vb3qI~
                          *(pc+1)=DEFAULT_ALTCH;                   //~vb3qI~
                         }                                         //~vb3xI~
                        }                                            //~va2jI~//~va47R~
						if (tdopt & FILETDO_PRINT)	//UTF8 file    //~va20I~
                        {                                          //~va20I~
//                      	*pcd=DISPLINEATTRID;//display by lineno fld attr//~va20R~//~va47R~
//                      	*(pcd+1)=DISPLINEATTRID;//display by lineno fld attr//~va20R~//~va47R~
                            if (*pc==DEFAULT_ALTCH                 //~va47I~
							&& utfgetvisiblealtchprint(UTFGVACO_DBCSSPACE|optxpr,DEFAULT_ALTCH,pc,pcd)!=1)//~va47I~
                            {                                      //~va47I~
				          		*pc=XEUTF_ERRREPCH_NPUCS;          //~va47I~
				          		*(pc+1)=XEUTF_ERRREPCH_NPUCSW;     //~va47I~
	          					*pcd=0;                            //~va47I~
                            }                                      //~va47I~
                            else                                   //~va47I~
                            	*(pc+1)=*pc;                       //~va47I~
							*(pcd+1)=*pcd;                         //~va47I~
                        }                                          //~va20I~
#ifdef SSS                                                         //~vb3xI~
                        else                                       //~va20I~
                        {                                          //~va20I~
                        	*pcd=UDBCSCHK_NPUCS1;	//for csr step dbcs//~va20I~
                        	*(pcd+1)=UDBCSCHK_NPUCS2;//            //~va20I~
                        }                                          //~va20I~
#endif //SSS                                                       //~vb3xI~
			            rc=1;   //do setlineattr for set green     //~vb3nI~
                    }                                              //~va20R~
                }                                                  //~va20I~
        		pc++; 	//skip more 1 byte                         //~va20R~
            	pcd++;                                             //~va20R~
                reslen--;                                          //~va6sI~
        	}                                                      //~va20R~
        	else                                                   //~va20R~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
    		if (UDBCSCHK_ISUCSOVF1ST(dbcsid) && reslen>1)//ucs4    //~va3xI~
            {                                                      //~va3xI~
                xeutfddwidth4(0,pc,pcd,0/*ucs*/,&width4);          //~va3xR~
                if (width4<=0)	//unprintable                      //~va3xR~
                {                                                  //~va3xI~
	          		*pc++=XEUTF_ERRREPCH_NPUCS ; // ':'      //hex code is ucs//~va3xI~
                	*pcd++=UDBCSCHK_NPUCS1;	//for csr step dbcs    //~va3xI~
	          		*pc=XEUTF_ERRREPCH_NPUCSW ; // ';'      //hex code is ucs//~va3xI~
                    *pcd=UDBCSCHK_NPUCS2;//                        //~va3xI~
                    reslen--;                                      //~va3xI~
                }                                                  //~va3xI~
                else                                               //~va6sI~
                {                                                  //~va6sI~
        			pc++; 	//skip more 1 byte                     //~va6sI~
            		pcd++;                                         //~va6sI~
                	reslen--;                                      //~va6sI~
                }                                                  //~va6sI~
            }                                                      //~va3xI~
        	else                                                   //~va3xI~
    		if (reslen==1 && UDBCSCHK_DBCS1STU(dbcsid))//ucs4 split right//~vb28R~
            {                                                      //~vb28I~
            	rc=1;	//no change *pc and *pcd,but celldraw to draw split half by line attr//~vb28R~
            }                                                      //~vb28I~
        	else                                                   //~vb28I~
#endif                                                             //~va3xI~
            {                                                      //~va20R~
                if (dbcsid==UDBCSCHK_HKDBCSERR)                    //~va20R~
                {                                                  //~va20R~
        			*pc=Gunpdispchar[0];	//displayable char     //~va20R~
//  				if (tdopt & FILETDO_PRINT //xprint             //~va46I~
    				if ((tdopt & (FILETDO_PRINT|FILETDO_PRINTGUI)) //xpr *** with tab on and GUI binfile print//~va46I~
                    &&  *pc==DEFAULT_ALTCH)                        //~va47I~
						utfgetvisiblealtchprint(UTFGVACO_UNP|optxpr,DEFAULT_ALTCH,pc,pcd);//~va47I~
					*pcd=DISPLINEATTRID;//display by lineno fld attr//~va20R~
            		rc=1;                                          //~va20R~
                }                                                  //~va20R~
                else                                               //~va20R~
                if (dbcsid==UDBCSCHK_F2LERR)                       //~va20R~
                {                                                  //~va20R~
          			*pc=XEUTF_ERRREPCH_F2LFILE ; // '?'      //hex code is original value//~va20R~
					*pcd=DISPLINEATTRID;//display by lineno fld attr//~va20R~
            		rc=1;                                          //~va20R~
                }                                                  //~va20R~
                else                                               //~va20R~
                if (dbcsid==UDBCSCHK_NPUCS1||dbcsid==UDBCSCHK_NPUCS2)//~va20R~
                {                                                  //~va20R~
                	if (dbcsid==UDBCSCHK_NPUCS1)                   //~va20I~
	          			*pc=XEUTF_ERRREPCH_NPUCS ; // ':'      //hex code is ucs//~va20R~
                    else                                           //~va20I~
	          			*pc=XEUTF_ERRREPCH_NPUCSW ; // ';'      //hex code is ucs//~va20I~
					if (tdopt & FILETDO_PRINT)	//UTF8 file        //~va20I~
						*pcd=DISPLINEATTRID;//display as sbcs      //~va20R~
            		rc=1;                                          //~va20R~
                }                                                  //~va20R~
//#ifndef XXE                                                      //~va20R~
//                else                                             //~va20R~
//                if (dbcsid==UDBCSCHK_NPUCS1W||dbcsid==UDBCSCHK_NPUCS2W)//~va20R~
//                {                                                //~va20R~
//                    *pc=XEUTF_ERRREPCH_NPUCSW ; // ';'      //hex code is ucs//~va20R~
//                    *pcd=DISPLINEATTRID;//display by lineno fld attr//~va20R~
//                    rc=1;                                        //~va20R~
//                }                                                //~va20R~
//#endif                                                           //~va20R~
                else                                               //~va20R~
        		if(Gunpdispchartbl[*pc]   	//unprintable          //~va20R~
//#ifdef UTF8UCS4                                                    //~va3xR~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
                && !UDBCSCHK_DBCS2NDUCS2NWO(dbcsid)  //set "." by setdbcssplit2,=func_draw//~va3xI~
#else                                                              //~va3xI~
                && !UDBCSCHK_DBCS2NDUCS2NW(dbcsid)  //set "." by setdbcssplit2,=func_draw//~va20R~
#endif                                                             //~va3xI~
                )                                                  //~va20I~
        		{                                                  //~va20R~
//                  if (*pc<0x20  //ctlchar                          //~vb3tR~//~vb3vR~
//                  && (altch=UTF_GETALTCH_CTL(*pc))>0)              //~vb3tR~//~vb3vR~
//                  {                                                //~vb3tR~//~vb3vR~
//                    UTRACEP("%s:unprintable ucs=%02x,altch=%04x,dbcsid=%02x\n",UTT,*pc,altch,dbcsid);//~vb3tR~//~vb3uR~//~vb3vR~
//                  }                                                //~vb3tR~//~vb3vR~
//                  else                                             //~vb3tR~//~vb3vR~
//                  {                                                //~vb3tR~//~vb3vR~
        			*pc=Gunpdispchar[0];	//displayable char     //~va20R~
//  				if (tdopt & FILETDO_PRINT //xprint             //~va46I~
    				if ((tdopt & (FILETDO_PRINT|FILETDO_PRINTGUI)) //xpr *** with tab on and GUI binfile print//~va46I~
                    &&  *pc==DEFAULT_ALTCH)                        //~va47I~
						utfgetvisiblealtchprint(UTFGVACO_UNP|optxpr,DEFAULT_ALTCH,pc,pcd);//~va47I~
					*pcd=DISPLINEATTRID;//display by lineno fld attr//~va20R~
            		rc=1;                                          //~va20R~
//                  }                                                //~vb3tR~//~vb3vR~
        		}                                                  //~va20R~
                else                                               //~va46I~
                if (*pc<0x20 && !dbcsid	//ascii ctl char           //~va46I~
    			&&  (tdopt & FILETDO_PRINTGUI) //xpr *** with tab on and GUI binfile print//~va46I~
                )                                                  //~va46I~
					utfgetvisiblealtchprint(optxpr,*pc,pc,pcd);	//rep if altch defined for 0x1b etc//~va46I~
                                                                   //~va46I~
            }                                                      //~va20R~
        }//SBCS utf8                                               //~va20R~
//#ifndef WXEXXE                                                     //~va30R~//~va3eR~
        else    //SBCS                                             //~va30I~
        {                                                          //~va30I~
//            ucssbcs=UTF_GETUCSSBCS(pc,pcd);                        //~vb2RI~//~vb2SR~
//            if (UCSIS_NONCHARACTER(ucssbcs))                       //~vb2RI~//~vb2SR~
//            {                                                      //~vb2RI~//~vb2SR~
//                *pc=XEUTF_ERRREPCH_NPUCS ; // ':'      //hex code is ucs//~vb2RI~//~vb2SR~
//                *pcd=DISPLINEATTRID;//display as sbcs              //~vb2RI~//~vb2SR~
//                rc=1;   //call setlineattr                         //~vb2RI~//~vb2SR~
//            }                                                      //~vb2RI~//~vb2SR~
//            else                                                   //~vb2RI~//~vb2SR~
//          if (UDBCSCHK_ISUCSWIDTH0(dbcsid) && UTF_COMBINEMODE())//display padding//~va30I~//~va3eR~
            if (UDBCSCHK_ISUCSWIDTH0(dbcsid)                       //~va3eI~
            &&  (UTF_COMBINEMODE()||(Goptopt3 & GOPT3_COMBINENP))   //display unprintable//~va3eR~
            )                                                      //~va3eI~
            {                                                      //~va3eI~
#ifdef AAA  //set replace by altch at file23.c                     //+vb4yR~
              	if (Goptopt3 & GOPT3_COMBINENP)	//display unprintable//~va3eI~
              	{                                                  //~va3eI~
	          		*pc=XEUTF_ERRREPCH_NPUCS ; // ':'      //hex code is ucs//~va3eI~
					*pcd=DISPLINEATTRID;//display as sbcs          //~va3eI~
              	}                                                  //~va3eI~
#endif                                                             //~vb4yI~
            	rc=1;	//call setlineattr                         //~va30I~
            }                                                      //~va3eI~
        }                                                          //~va30I~
//#endif WXEXXE                                                             //~va30I~//~va3eR~
      }//CPU8                                                      //~va20R~
      else                                                         //~va20R~
#endif                                                             //~va20R~
      {//locale file                                               //~va20R~
        if (asciisw && *pc>=0x80)                                  //~v43yR~
        {                                                          //~v43yI~
        	*pc=Gunpdispchar[0];	//displayable char             //~v43yI~
//  		if (tdopt & FILETDO_PRINT //xprint                     //~va46I~
    		if ((tdopt & (FILETDO_PRINT|FILETDO_PRINTGUI)) //xpr *** with tab on and GUI binfile print//~va46I~
            &&  *pc==DEFAULT_ALTCH)                                //~va47I~
				utfgetvisiblealtchprint(UTFGVACO_UNP|optxpr,DEFAULT_ALTCH,pc,pcd);//~va47I~
			*pcd=DISPLINEATTRID;//display by lineno fld attr       //~v43yI~
            rc=1;                                                  //~v43yI~
        }                                                          //~v43yI~
        else                                                       //~v43yI~
        if (reslen==1 && UDBCSCHK_DBCSNOTEND_L(*pcd))//LCDBCS split at right//~vb28R~
        {                                                          //~vb28I~
            rc=1;   //no change *pc and *pcd,but celldraw to draw split half by line attr//~vb28I~
        }                                                          //~vb28I~
        else                                                       //~vb28I~
#ifdef UTF8SUPPH                                                   //~va1EI~
        if (*pcd==UDBCSCHK_F2LERR)	//f2l trans err original byte code//~va1EI~
        {                                                          //~va1EI~
          	*pc=XEUTF_ERRREPCH_F2LFILE ; // '?'      //f2l err replace on plh//~va1EI~
			*pcd=DISPLINEATTRID;//display by lineno fld attr       //~va1EI~
            rc=1;                                                  //~va1EI~
        }                                                          //~va1EI~
        else                                                       //~va1EI~
#endif                                                             //~va1EI~
//      if (*pcd==NULLCHARIDDBCS	//null is always special       //~v0a1R~
//      || (Gunpdispchartbl[*pc]   	//unprintable                  //~v0a1R~
//#ifdef UNX                                                       //~v73vR~
        if (*pcd==UDBCSCHK_HKDBCSERR)	//invalid dbcs hankata conbination//~v21mI~
        {                                                          //~v21mI~
#ifdef UTF8SUPPH                                                   //~va00I~
          if (*pc!=XEUTF_ERRREPCH_F2LFILE ) // '?'      //f2l err replace on plh//~va00I~
#endif                                                             //~va00I~
        	*pc=Gunpdispchar[0];	//displayable char             //~v21mI~
//  		if (tdopt & FILETDO_PRINT //xprint                     //~va46I~
    		if ((tdopt & (FILETDO_PRINT|FILETDO_PRINTGUI)) //xpr *** with tab on and GUI binfile print//~va46I~
            &&  *pc==DEFAULT_ALTCH)                                //~va47I~
				utfgetvisiblealtchprint(UTFGVACO_UNP|optxpr,DEFAULT_ALTCH,pc,pcd);//~va47I~
			*pcd=DISPLINEATTRID;//display by lineno fld attr       //~v21mI~
            rc=1;                                                  //~v21mI~
        }                                                          //~v21mI~
        else                                                       //~v21mI~
//#endif                                                           //~v73vR~
//      if((Gunpdispchartbl[*pc]   	//unprintable                  //~va6vR~
        if((  (  Gunpdispchartbl[*pc]   	//unprintable          //~va6vI~
#ifdef AAA                                                         //~va6CR~
              || !UDBCSCHK_ISPRINT(*pc)     //unprintable by converter//~va6vI~
#else                                                              //~va6CI~
    #ifndef WXE //wxe adjust by setup dialog codepage              //~va74I~
              || (*pc>0x20 && !UDBCSCHK_ISPRINT(*pc)) //unprintable by converter//~va6CI~
    #endif                                                         //~va74I~
#endif                                                             //~va6CI~
              )                                                    //~va6vI~
#ifdef UTF8SUPPH                                                   //~va1cR~
            && !UDBCSCHK_DBCSCOLS(*pcd)))//not dbcs column(1st,pad,2nd)//~va1cR~
#else                                                              //~va1cR~
            && *pcd!=DBCS1STCHAR                                   //~v09UI~
            && *pcd!=DBCS2NDCHAR))	//no DBCS under english mode   //~v09UR~
#endif                                                             //~va1cR~
        {                                                          //~v09UR~
        	*pc=Gunpdispchar[0];	//displayable char             //~v09UR~
//  		if (tdopt & FILETDO_PRINT //xprint                     //~va46M~
    		if ((tdopt & (FILETDO_PRINT|FILETDO_PRINTGUI)) //xpr *** with tab on and GUI binfile print//~va46M~
            &&  *pc==DEFAULT_ALTCH)                                //~va47I~
				utfgetvisiblealtchprint(UTFGVACO_UNP|optxpr,DEFAULT_ALTCH,pc,pcd);//~va47I~
			*pcd=DISPLINEATTRID;//display by lineno fld attr       //~v09UR~
            rc=1;                                                  //~v09UR~
        }                                                          //~v09UR~
        else                                                       //~va46I~
        if (*pc<0x20 && !*pcd	//ascii ctl char                   //~va46I~
    	&&  (tdopt & FILETDO_PRINTGUI) //xpr *** with tab on and GUI binfile print//~va46I~
        )                                                          //~va46I~
			utfgetvisiblealtchprint(optxpr,*pc,pc,pcd);	//rep if altch defined for 0x1b etc//~va46I~
      }                                                            //~va20R~
	}//ascii mode or else                                          //~va20R~
UTRACED("tabdisplay notab data out",Pdata,Plen);                   //~va6tI~
UTRACED("tabdisplay notab dbcs out",Pdbcs,Plen);                   //~va6tI~
UTRACEP("%s:return 1 rc=%d\n",UTT,rc);                             //~vb28I~
  if (!Pbinsw)        //text file                                  //~v20UI~
	if (!UCBITCHK(Gopt,GOPTTABDISPLAY))                            //~v09UI~
    	return rc;                                                 //~v09UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (!swebc)	//processed tab at xeebc                           //~va50I~
#endif //UTF8EBCS raw ebcdic file support                          //~va50I~
  {                                                                //~va50I~
    pc=Pdata;                                                         //~v06bI~
	pcd=Pdbcs;
	reslen=Plen;
//first tab pad char caused by scroll                                 //~v06bI~
	while(reslen && *pcd==TABPADCHAR)//tab advance char               //~v06bI~
	{                                                                 //~v06bI~
	  if (tdopt & FILETDO_PRINT //xprint                           //~va47I~
      &&  Gfiletabdisp2==DEFAULT_ALTCH)                            //~va47I~
      {                                                            //~va47I~
		utfgetvisiblealtchprint(UTFGVACO_TABPAD|optxpr,DEFAULT_ALTCH,pc,pcd);//~va47I~
        pc++;                                                      //~va47I~
      }                                                            //~va47I~
      else                                                         //~va47I~
		*pc++=Gfiletabdisp2;                                          //~v06bI~
    	pcd++;                                                     //~v09UR~
		reslen--;                                                     //~v06bI~
	}                                                                 //~v06bI~
//repl tabs start from tab char                                       //~v06bI~
	while(reslen)                                               //~4C23R~
	{
//search on pcd                                                    //~va50I~
//!ebc                                                             //~va50I~
		if (!(pcd=memchr(pcd,TABCHAR,(UINT)reslen)))        //~5102I~
			break;                                          //~5102I~
//		len=(int)((ULONG)pcd-(ULONG)Pdbcs);                 //~4C23R~//~vafkR~
		len=(int)((ULPTR)pcd-(ULPTR)Pdbcs);                        //~vafkI~
        reslen=Plen-len;                                     //~4C23I~
		pc=Pdata+len;
	  if (tdopt & FILETDO_PRINT //xprint                           //~va47I~
      &&  Gfiletabdisp1==DEFAULT_ALTCH)                            //~va47I~
      {                                                            //~va47I~
		utfgetvisiblealtchprint(UTFGVACO_TAB|optxpr,DEFAULT_ALTCH,pc,pcd);//~va47I~
        pc++;                                                      //~va47I~
      }                                                            //~va47I~
      else                                                         //~va47I~
		*pc++=Gfiletabdisp1;	//skip tab char                //~4C23R~
    	pcd++;				//skip tab char                        //~v09UR~
        reslen--;                                               //~4C23I~
		while(reslen && *pcd==TABPADCHAR)//tab advance char//~5102I~
		{                                                   //~5102I~
	  	  if (tdopt & FILETDO_PRINT //xprint                       //~va47I~
          &&  Gfiletabdisp2==DEFAULT_ALTCH)                        //~va47I~
          {                                                        //~va47I~
		    utfgetvisiblealtchprint(UTFGVACO_TABPAD|optxpr,DEFAULT_ALTCH,pc,pcd);//~va47I~
            pc++;                                                  //~va47I~
          }                                                        //~va47I~
          else                                                     //~va47I~
			*pc++=Gfiletabdisp2;                          //~5102I~
    		pcd++;                                                 //~v09UR~
			reslen--;                                       //~5102I~
		}                                                   //~5102I~
	}//end of string
//  rc=reslen!=Plen;                                               //~v09UR~
    rc+=(reslen!=Plen);                                            //~v09UI~
  }//!ebc                                                          //~va50I~
#ifdef LNX                                                         //~v21iI~
//  if (!UCBITCHK(Gunxflag,GUNX_EUC))                              //~v21kR~
//  if ((Gunxflag & (GUNX_EUC|GUNX_KON))!=(GUNX_EUC|GUNX_KON))     //~v79zR~
    if (!XE_ISDBCSKONJ())	//not japanese on KON avail terminal   //~v79zR~
    {                                                              //~va15I~
#ifdef UTF8SUPPH                                                   //~va15I~
        if (!Sdbcsspace[1])	//first time                           //~va15I~
        {                                                          //~va15I~
        	if (getdbcsspace(Sdbcsspace))	//failed               //~va15I~
            {                                                      //~va15I~
		        Sdbcsspace[1]=1;	//errid,try only once          //~va15I~
                return rc;                                         //~va15I~
            }                                                      //~va15I~
        }                                                          //~va15I~
        if (!Sdbcsspace[0])	//u2l failed                           //~va15I~
	    	return rc;                                             //~va15I~
    	dbcsspace1=Sdbcsspace[0];   //dbcs space first byte        //~va15I~
    	dbcsspace2=Sdbcsspace[1];   //dbcs space second byte       //~va15I~
#else                                                              //~va15I~
    	return rc;                                                 //~v21iI~
#endif                                                             //~va15I~
	}                                                              //~va15I~
    else                                                           //~va15I~
    {                                                              //~va15I~
    dbcsspace1=0xa1;   //dbcs space first byte                     //~v21iI~
    dbcsspace2=0xa1;   //dbcs space second byte                    //~v21iI~
	}                                                              //~va15I~
#else                                                              //~v21iI~
	if (!UCBITCHK(Gscrstatus,GSCRSDBCS))                        //~5502I~
    {                                                              //~va15I~
#ifdef UTF8SUPPH                                                   //~va15I~
        if (!Sdbcsspace[1])	//first time                           //~va15I~
        {                                                          //~va15I~
        	if (getdbcsspace(Sdbcsspace))	//failed               //~va15I~
            {                                                      //~va15I~
		        Sdbcsspace[1]=1;	//errid,try only once          //~va15I~
                return rc;                                         //~va15I~
            }                                                      //~va15I~
        }                                                          //~va15I~
        if (!Sdbcsspace[0])	//u2l failed                           //~va15I~
	    	return rc;                                             //~va15I~
    	dbcsspace1=Sdbcsspace[0];   //dbcs space first byte        //~va15I~
    	dbcsspace2=Sdbcsspace[1];   //dbcs space second byte       //~va15I~
#else                                                              //~va15I~
    	return rc;                                              //~5502I~
#endif                                                             //~va15I~
    }                                                              //~va15I~
    else                                                           //~va15I~
    {                                                              //~va15I~
    dbcsspace1=0x81;   //dbcs space first byte                     //~v21iI~
    dbcsspace2=0x40;   //dbcs space second byte                    //~v21iI~
    }                                                              //~va15I~
#endif                                                             //~v21iI~
//*dbcs space display                                           //~5502I~
	pc=Pdata;                                                   //~5502I~
	reslen=Plen;                                                //~5502I~
#ifdef UTF8UCS2                                                    //~va20I~
  if (!(tdopt & FILETDO_UTF8))	//not UTF8 file                    //~va20I~
#endif                                                             //~va20I~
   if (!(tdopt & FILETDO_PRINTGUI)) //GUI binfile print            //~va46I~
	while(reslen)                                               //~5502I~
	{                                                           //~5502I~
//  	if (!(pc=memchr(pc,DBCSSPACE1,(UINT)reslen)))              //~v21iR~
//*search on localefile                                            //~va50R~
    	if (!(pc=memchr(pc,dbcsspace1,(UINT)reslen)))              //~v21iI~
			break;                                              //~5502I~
//		reslen=Plen-(int)((ULONG)pc-(ULONG)Pdata);              //~5502R~//~vafkR~
		reslen=Plen-(int)((ULPTR)pc-(ULPTR)Pdata);                 //~vafkI~
//  	if (--reslen && *(++pc)==DBCSSPACE2)                       //~v21iR~
		if (--reslen && *(++pc)==dbcsspace2)                       //~v21iI~
        {                                                       //~5502I~
	  	  if (tdopt & FILETDO_PRINT //xprint                       //~va47I~
          &&  Gunpdispchar[3]==DEFAULT_ALTCH)                      //~va47I~
          {                                                        //~va47I~
		    utfgetvisiblealtchprint(UTFGVACO_DBCSSPACE|optxpr,DEFAULT_ALTCH,pc,0/*out pcd*/);//~va47I~
			*(pc-1)=*pc;                                           //~va47I~
			pc++;                                                  //~va47I~
          }                                                        //~va47I~
          else                                                     //~va47I~
          {                                                        //~va47I~
	       if (UCBITCHK(Gopt,GOPTTABDISPLAY))//for binfile,viom translate unp if bin file
           {
			*(pc-1)=Gunpdispchar[3];                               //~v09XR~
			*pc++=Gunpdispchar[3];                                 //~v09XR~
           }
          }                                                        //~va47I~
	        reslen--;                                           //~5502I~
            rc=1;                                               //~5502I~
		}                                                       //~5502I~
	}//end of string                                            //~5502I~
UTRACED("tabdisplay data out",Pdata,Plen);                         //~va6sR~
UTRACED("tabdisplay dbcs out",Pdbcs,Plen);                                        //~v79zI~//~va3xR~//~va6sR~
UTRACEP("%s:return 2 rc=%d\n",UTT,rc);                             //~vb28R~
	return rc;                                                  //~5502R~
}//tabdisplay
                                                                //~5102I~
//**************************************************************** //~va80I~
// tabdisplay for xprint ebcdic file by TextoutW                   //~va80I~
//*change ctl char to "."                                          //~va80I~
//*rc                                                              //~va80I~
//**************************************************************** //~va80I~
int tabdisplayforxprebcbyucs(int Popt,int Phandle,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Poffs,int Plen)//~va80R~
{                                                                  //~va80I~
	int rc=0,reslen,opt=0,outlen;                                  //~va80R~
	UCHAR *pc,*pcd,altch='.';                                      //~va80I~
    UCHAR *poutdata,*poutdbcs;                                     //~va80R~
//*****************                                                //~va80I~
//*unprintable char                                                //~va80I~
UTRACEP("tabdisplayforxprebcbyucs opt=%08x,offs=%d\n",Popt,Poffs); //~va80R~
UTRACED("tabdisplayforxprbyucs",Pdata,Plen);                       //~va80R~
UTRACED("tabdisplayforxprbyucs",Pdbcs,Plen);                       //~va80R~
	pc=Pdata;                                                      //~va80I~
	pcd=Pdbcs;                                                     //~va80I~
    opt|=XEEBCO_B2DD|XEEBCO_SETF2LERR|XEEBCO_ERRREP2;              //~va80R~
    if (Popt & TDXPO_TEXT)	//not bin file                         //~va80R~
    	opt|=XEEBCO_ERRREP|XEEBCO_SOSI2SPACE;                      //~va80R~
    else      //bin file                                           //~va80I~
		opt|=XEEBCO_ERRREP|XEEBCO_BIN|XEEBCO_CVCTL;                //~va80R~
    poutdbcs=0;	//request return                                   //~va80I~
    if (Popt & TDXPO_EBCSPLITCHK)	//dbcschk as whole line the copy split//~va80I~
    {                                                              //~va80I~
    	xeebc_b2msetdbcs(opt,Phandle,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,&poutdata,&poutdbcs,&outlen);//~va80R~
//		memcpy(pc,poutdata+Poffs,Plen);                            //~va80I~//~vb28R~
  		memcpy(pc,poutdata+Poffs,(size_t)Plen);                    //~vb28I~
//  	memcpy(pcd,poutdbcs+Poffs,Plen);                           //~va80I~//~vb28R~
    	memcpy(pcd,poutdbcs+Poffs,(size_t)Plen);                   //~vb28I~
        if (*pcd==UDBCSCHK_DBCS2ND)                                //~va80I~
        	*pcd=UDBCSCHK_F2LERR;                                  //~va80I~
        if (*(pcd+Plen-1)==UDBCSCHK_DBCS1ST)                       //~va80I~
        	*(pcd+Plen-1)=UDBCSCHK_F2LERR;                         //~va80I~
    }                                                              //~va80I~
    else                                                           //~va80I~
    {                                                              //~va80I~
    	xeebc_b2msetdbcs(opt,Phandle,Pdata,Pdbcs,Plen,&poutdata,&poutdbcs,&outlen);//~va80R~
//  	memcpy(pc,poutdata,Plen);                                  //~va80R~//~vb28R~
    	memcpy(pc,poutdata,(size_t)Plen);                          //~vb28I~
//  	memcpy(pcd,poutdbcs,Plen);                                 //~va80R~//~vb28R~
    	memcpy(pcd,poutdbcs,(size_t)Plen);                         //~vb28I~
    }                                                              //~va80I~
    reslen=min(Plen,outlen);                                       //~va80R~
	for(;reslen;reslen--,pc++,pcd++)                               //~va80I~
    {                                                              //~va80I~
//*no TABCHAR on dbcstbl for ebcfile                               //~va80I~
		if (!*pcd                                                  //~va80I~
		&&   (  *pc==TABCHAR                                       //~va80R~
        	  ||*pc==0x00                                          //~va80I~
        	  ||*pc==0x0d                                          //~va80R~
        	  ||*pc==0x0a                                          //~va80I~
             )                                                     //~va80I~
        )                                                          //~va80I~
        {                                                          //~va80I~
        	*pc=altch;	//displayable char                         //~va80I~
            rc=1;                                                  //~va80I~
        }                                                          //~va80I~
        else                                                       //~va80I~
        if (*pcd==UDBCSCHK_F2LERR)	//f2l trans err original byte code//~va80I~
        {                                                          //~va80I~
        	*pc=altch;	//displayable char                         //~va80I~
            *pcd=0;                                                //~va80I~
            rc=1;                                                  //~va80I~
        }                                                          //~va80I~
	}                                                              //~va80I~
    UTRACED("tabdisplayforxprebcbyucs out data",Pdata,Plen);       //~va80I~
    UTRACED("tabdisplayforxprebcbyucs out dbcs",Pdbcs,Plen);       //~va80I~
	return rc;                                                     //~va80I~
}//tabdisplayforxprebcbyucs                                        //~va80I~
//**************************************************************** //~v61xI~
// tabdisplay for xprint                                           //~v61xI~
// from file12 for binfile only                                    //~va20I~
//*change ctl char to "."                                          //~v61xI~
//*rc                                                              //~v61xI~
//**************************************************************** //~v61xI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int tabdisplayforxpr(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~va50I~
#else                                                              //~va50I~
int tabdisplayforxpr(UCHAR *Pdata,UCHAR *Pdbcs,int Plen)           //~v61xI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
{                                                                  //~v61xI~
	int rc=0,asciisw,reslen;                                       //~v61xR~
	UCHAR *pc,*pcd,altch='.';                                      //~v61xI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int opt=0,outlen;                                                //~va50I~//~va80R~
    UCHAR *poutdata;                                               //~va50R~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************                                                //~v61xI~
//*unprintable char                                                //~v61xI~
UTRACED("tabdisplayforxpr",Pdata,Plen);                            //~va5LI~
	pc=Pdata;                                                      //~v61xI~
	pcd=Pdbcs;                                                     //~v61xI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	handle=UGETPFH(Pplh)->UFHhandle;                               //~va79I~
	if (PLH_ISEBC(Pplh))                                           //~va50I~
    {                                                              //~va50I~
        if (Popt & TDXPO_EBCBYUCS)                                 //~va80R~
			return tabdisplayforxprebcbyucs(Popt,handle,Pplh,Pdata,Pdbcs,0,Plen);//~va80R~
    	if (Popt & TDXPO_TEXT)                                     //~va50I~
    	  if (Popt & TDXPO_TEXTFILE)	//from wxe                 //~va5LI~
    		opt|=XEEBCO_ERRREP|XEEBCO_SOSI2SPACE;                   //~va5LI~//~va80R~
          else //scr print from xe/wxe                             //~va5LR~
    		opt|=XEEBCO_ERRREP|XEEBCO_SOSIREPQP;                    //~va5LR~//~va80R~
        else                                                       //~va50I~
			opt|=XEEBCO_ERRREP|XEEBCO_BIN;                          //~va50R~//~va80R~
//  	xeebc_b2msetdbcs(opt,Pdata,Pdbcs,Plen,&poutdata,0/*outdbcs*/,&outlen);//~va50R~//~va79R~
    	xeebc_b2msetdbcs(opt,handle,Pdata,Pdbcs,Plen,&poutdata,0/*outdbcs*/,&outlen);//~va79I~
//		memcpy(pc,poutdata,Plen);                                  //~va50I~//~vb28R~
  		memcpy(pc,poutdata,(size_t)Plen);                          //~vb28I~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    asciisw=UCBITCHK(Gopt4,GOPT47BIT);	//if ASCII on              //~v61xI~
    reslen=Plen;                                                   //~v61xI~
	for(;reslen;reslen--,pc++,pcd++)                               //~v61xI~
    {                                                              //~v61xI~
        if (asciisw && *pc>=0x80)                                  //~v61xI~
        {                                                          //~v61xI~
        	*pc=altch;                                             //~v61xI~
            rc=1;                                                  //~v61xI~
        }                                                          //~v61xI~
        else                                                       //~v61xI~
//*no TABCHAR on dbcstbl for ebcfile                               //~va50I~
        if (*pcd==TABCHAR)                                         //~v61xI~
        {                                                          //~v61xI~
        	*pc=altch;	//displayable char                         //~v61xI~
            rc=1;                                                  //~v61xI~
        }                                                          //~v61xI~
#ifdef UTF8SUPPH                                                   //~va1EI~
        if (*pcd==UDBCSCHK_F2LERR)	//f2l trans err original byte code//~va1EI~
        {                                                          //~va1EI~
        	*pc=altch;	//displayable char                         //~va1EI~
            rc=1;                                                  //~va1EI~
        }                                                          //~va1EI~
        else                                                       //~va1EI~
#endif                                                             //~va1EI~
//#ifdef UNX                                                       //~v73vR~
        if (*pcd==UDBCSCHK_HKDBCSERR)	//invalid dbcs hankata conbination//~v61xI~
        {                                                          //~v61xI~
        	*pc=altch;	//displayable char                         //~v61xI~
            rc=1;                                                  //~v61xI~
        }                                                          //~v61xI~
        else                                                       //~v61xI~
//#endif                                                           //~v73vR~
//*after b2m translated                                            //~va50I~
        if(*pc<' ')   	//unprintable                              //~v61xI~
        {                                                          //~v61xI~
        	*pc=altch;                                             //~v61xI~
            rc=1;                                                  //~v61xI~
        }                                                          //~v61xI~
        else                                                       //~v61xI~
//      if(Gunpdispchartbl[*pc])  	//unprintable                  //~v61xR~//~va2jR~
        if(Gunpdispchartbl[*pc]                                    //~va2jI~
        && !UDBCSCHK_DBCSCOLS(*pcd)                                //~va2jR~
        )                                                          //~va2jI~
        {                                                          //~v61xI~
        	*pc=altch;                                             //~v61xI~
            rc=1;                                                  //~v61xI~
        }                                                          //~v61xI~
	}                                                              //~v61xI~
	return rc;                                                     //~v61xI~
}//tabdisplayforxpr                                                //~v61xI~
//**************************************************************** //~vamFI~
// tabdisplay for xprint except ebc file                           //~vamFI~
//*change 0d/0a/09 to "."                                          //~vamFI~
//**************************************************************** //~vamFI~
int tabdisplayforxprrecord(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~vamFI~
{                                                                  //~vamFI~
	int rc=0,ch,chd,reslen;                                        //~vamFR~
	UCHAR *pc,*pcd,altch='.';                                      //~vamFI~
//*****************                                                //~vamFI~
UTRACED("tabdisplayforxprrecord",Pdata,Plen);                      //~vamFI~
	pc=Pdata;                                                      //~vamFI~
	pcd=Pdbcs;                                                     //~vamFI~
    reslen=Plen;                                                   //~vamFI~
	for(;reslen;reslen--,pc++,pcd++)                               //~vamFI~
    {                                                              //~vamFI~
    	ch=*pc;                                                    //~vamFR~
    	chd=*pcd;                                                  //~vamFI~
        if((ch==0x0a||ch==0x0d) && !chd)  //sbcs                   //~vamFR~
        {                                                          //~vamFI~
        	*pc=altch;                                             //~vamFI~
            rc=1;                                                  //~vamFI~
        }                                                          //~vamFI~
        if(ch==' ' && chd==TABCHAR)                                //~vamFI~
        {                                                          //~vamFI~
        	*pc=altch;                                             //~vamFI~
            rc=1;                                                  //~vamFI~
        }                                                          //~vamFI~
	}                                                              //~vamFI~
	return rc;                                                     //~vamFI~
}//tabdisplayforxprrecord                                          //~vamFI~
#ifdef UTF8UCS2                                                                   //~v61xI~//~va30R~
//**************************************************************** //~va20I~
// tabdisplay for wxeprint of utf8 file                            //~va20I~
// from wxexei2 for utf8 file(text)                                //~va20I~
//*rc                                                              //~va20I~
//**************************************************************** //~va20I~
int tabdisplayforxpru8(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen)//~va20I~
{                                                                  //~va20I~
	int /*asciisw,*/reslen,dbcsid,ch;                             //~va20I~//~va2jR~//~vaa7R~
	UCHAR *pc,*pcd,altch='.';                                      //~va20I~
//*****************                                                //~va20I~
	pc=Pdata;                                                      //~va20I~
	pcd=Pdbcs;                                                     //~va20I~
//  asciisw=UCBITCHK(Gopt4,GOPT47BIT);	//if ASCII on              //~va20I~//~vaa7R~
    reslen=Plen;                                                   //~va20I~
	for(;reslen;reslen--,pc++,pcd++)                               //~va20I~
    {                                                              //~va20I~
        ch=*pc;                                                    //~va20I~
        dbcsid=*pcd;                                               //~va20I~
//        if (asciisw)      //for binfile only                      //~va20I~//~va2jR~
//        {                                                          //~va20I~//~va2jR~
//            if (dbcsid || !UTF8ISASCII(ch))                        //~va20I~//~va2jR~
//                *pc=altch;                                         //~va20I~//~va2jR~
//            continue;                                              //~va20I~//~va2jR~
//        }                                                          //~va20I~//~va2jR~
    	if (UDBCSCHK_ISUCSSBCS(dbcsid))	//not sbcs                 //~va20I~
        	continue;                                              //~va20I~
                                                                   //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416     //FIXME test surrogate :FIXED                //~vaw1R~
    	if (UDBCSCHK_DBCS1STU(dbcsid))//wide dbcs or narrow dbcs   //~va3xI~
#else                                                              //~va3xI~
    	if (UDBCSCHK_DBCS1STUCS2NWP(dbcsid))//wide dbcs or narrow dbcs//~va20I~
#endif                                                             //~va3xI~
        {                                                          //~va20I~
        	pc++; 	//skip more 1 byte                             //~va20I~
           	pcd++;                                                 //~va20I~
        }                                                          //~va20I~
        else                                                       //~va20I~
//utf8file                                                         //~va50I~
        if (dbcsid==TABCHAR)                                       //~va20I~
        	*pc=altch;	//displayable char                         //~va20I~
        else                                                       //~va20I~
        if (dbcsid==UDBCSCHK_F2LERR)	//f2l trans err original byte code//~va20I~
        	*pc=altch;	//displayable char                         //~va20I~
        else                                                       //~va20I~
//*utf8                                                            //~va50I~
        if(ch<' ')   	//unprintable                              //~va20I~
        	*pc=altch;                                             //~va20I~
        else                                                       //~va20I~
        if(Gunpdispchartbl[ch])  	//unprintable                  //~va20I~
        	*pc=altch;                                             //~va20I~
	}                                                              //~va20I~
	return 0;                                                      //~va20I~
}//tabdisplayforxpru8                                              //~va20I~
#endif                                                                   //~va20I~//~va30R~
//**************************************************************** //~v0avM~
//!filetabclear                                                    //~v0b3R~
//   clear all tab                                                 //~v0b3R~
//*parm1:PULINEH                                                   //~v0b3R~
//*rc   :none                                                      //~v0b3R~
//**************************************************************** //~v0avM~
void filetabclear(PULINEH Pplh)                                    //~v0b3R~
{                                                                  //~v0avM~
	UCHAR *pcd;                                                    //~v0avM~
	UCHAR *pcdw;                                                   //~v0hQI~
	int len;                                                       //~v0b3R~
//********************	                                           //~v0avM~
//	len=Pplh->ULHlen;                                              //~v0b3R~
//	offs=0;                                                        //~v0b3R~
//	if (Pleft)		//left shift,drop top tab efect                //~v0b3R~
//	{                                                              //~v0b3R~
//		for (pc=Pplh->ULHdbcs;len;len--,pc++,offs++)               //~v0b3R~
//			if (*pc==TABPADCHAR)                                   //~v0b3R~
//				*pc=0;				//reset cut tab char efect     //~v0b3R~
//			else                                                   //~v0b3R~
//                break;                                           //~v0b3R~
//	}                                                              //~v0b3R~
//    else	//right shift                                          //~v0b3R~
//    	if (len)		//drop right tab on boundary               //~v0b3R~
//		{                                                          //~v0b3R~
//    		pcd=Pplh->ULHdbcs+len-1;                               //~v0b3R~
//            if ((*pcd==TABCHAR	&&  !TABSKIPCTR(len-1))        //~v0b3R~
//            ||   *pcd==TABPADCHAR)                               //~v0b3R~
//    			for (;len;len--,pcd--)                             //~v0b3R~
//                {                                                //~v0b3R~
//        			if (*pcd==TABCHAR)                             //~v0b3R~
//                    {                                            //~v0b3R~
//        				*pcd=0;				//reset cut tab char efect//~v0b3R~
//                        break;                                   //~v0b3R~
//                    }                                            //~v0b3R~
//                    else                                         //~v0b3R~
//	        			if (*pcd!=TABPADCHAR)                      //~v0b3R~
//    	                    break;                                 //~v0b3R~
//        			*pcd=0;				//reset cut tab char efect //~v0b3R~
//                }                                                //~v0b3R~
//    	}                                                          //~v0b3R~
//	if (filetabexp(1,Pplh,offs,&len)==UALLOC_FAILED)	//re ajust //~v0b3I~
//    	return UALLOC_FAILED;                                      //~v0b3I~
  	len=Pplh->ULHlen;                                              //~v0b3I~
  	pcd=Pplh->ULHdbcs;                                             //~v0b3I~
    while(len)                                                     //~v0b3I~
    {                                                              //~v0b3I~
        pcdw=pcd;           //save start addr                      //~v0hQI~
//*on pcd                                                          //~va50I~
        pcd=memchr(pcd,TABCHAR,(UINT)len);                         //~v0b3R~
        if (!pcd)                                                  //~v0b3I~
        	break;                                                 //~v0b3I~
		*pcd++=0;                                                  //~v0b3I~
//      len-=(int)((ULONG)pcd-(ULONG)pcdw);                        //~v0hQR~//~vafkR~
        len-=(int)((ULPTR)pcd-(ULPTR)pcdw);                        //~vafkI~
  		for (;len;len--,pcd++)                                     //~v0b3I~
  			if (*pcd==TABPADCHAR)                                  //~v0b3I~
  				*pcd=0;				//reset cut tab char efect     //~v0b3I~
  			else                                                   //~v0b3I~
                  break;                                           //~v0b3I~
    }                                                              //~v0b3I~
	UCBITOFF(Pplh->ULHflag2,ULHF2TABFOUND);	//no tab exist         //~v0b3I~
    return;                                                        //~v0b3I~
}//filetabclear                                                    //~v0b3R~
                                                                   //~v0avM~
//************************************************************     //~v0hJM~
// filetabclearall                                                 //~v0hJM~
//*clear all tab                                                   //~v0hJM~
//*parm1:pcw                                                       //~v0hJM~
//*return:rc                                                       //~v0hJM~
//************************************************************     //~v0hJM~
int filetabclearall(PUCLIENTWE Ppcw)                               //~v0hJM~
{                                                                  //~v0hJM~
	PUFILEC pfc;                                                   //~v0hJM~
	PUFILEH pfh;                                                   //~v0hJM~
	PULINEH plh;                                                   //~v0hJM~
    int rc;                                                        //~v0hJM~
//*****************************                                    //~v0hJM~
	pfc=Ppcw->UCWpfc;                                              //~v0hJM~
	pfh=pfc->UFCpfh;                                               //~v0hJM~
    if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                          //~v0hJM~
    {                                                              //~v0hJM~
    	uerrmsg("Cannot clear TAB for binary file",                //~v0hJM~
    			"バイナリーファイルはタブクリアー出来ません");     //~va00I~
		return 4;                                                  //~v0hJM~
    }                                                              //~v0hJM~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (PFH_ISEBC(pfh))                                            //~va50I~
    {                                                              //~va50I~
    	uerrmsg("Cannot clear TAB for EBCDIC file",                //~va50I~
    			"EBCDICファイルはタブクリアー出来ません");         //~va50I~
		return 4;                                                  //~va50I~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    UPCTRREQ(pfh);         //write at save                         //~v0hJM~
    rc=0;                                                          //~v0hJM~
	for (plh=UGETQTOP(&pfh->UFHlineque);plh;plh=UGETQNEXT(plh))    //~v0hJM~
	{                                                              //~v0hJM~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~v0hJM~
        	continue;                                              //~v0hJM~
                                                                   //~v0hJM~
        if (!plh->ULHdbcs)	//not yet expanded                     //~v0hJM~
        	if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v0hJM~
            	return UALLOC_FAILED;                              //~v0hJM~
                                                                   //~v0hJM~
        if (UCBITCHK(plh->ULHflag2,ULHF2TABFOUND))                 //~v0hJM~
        {                                                          //~v0hJM~
			if (rc=undoupdate(Ppcw,plh,UUHTREP),rc)	//prepare undo and update process//~v0hJM~
            	break;                                             //~v0hJM~
        	filetabclear(plh);                                     //~v0hJM~
		}                                                          //~v0hJM~
	}//all line	                                                   //~v0hJM~
    UPCTRREQ(pfh);         //write at save                         //~v0hJM~
    if (!rc)                                                       //~v0hJM~
    	uerrmsg("All tab is replaced by space(tab skip=%d)",       //~v0hJM~
    			"タブをクリアー(tab skip=%d)",                     //~va00I~
//         		Gfiletabskip);                                     //~v8@2R~
           		pfh->UFHtabskip);                                  //~v8@2I~
    return rc;                                                     //~v0hJM~
}//filetabclearall                                                 //~v0hJM~
//**************************************************************** //~v50fI~
//!filetabrestore                                                  //~v50fI~
//*restore tab as record data                                      //~v50fI~
//*parm1:pfh                                                       //~v50fI~
//*parm2:plh                                                       //~v50fI~
//*parm3:out area                                                  //~v50fI~
//*parm4:out area len                                              //~v50fI~
//*parm5:out len                                                   //~v50fI~
//*parm4:len                                                       //~v50fI~
//*rc   :0:tab reduced,1:not yet expanded,2:no tab detected,8:outbuff overflow//~v50fI~
//**************************************************************** //~v50fI~
int filetabrestore(PUFILEH Ppfh,PULINEH Pplh,UCHAR *Poutbuff,int Poutbufflen,int *Ppoutlen)//~v50fR~
{                                                                  //~v50fI~
	int   len,reslen,rc;                                           //~v50jR~
	UCHAR *pc,*pcout,*pcoute,*pcd,*pcdo;                           //~v50fR~
//*****************                                                //~v50fI~
    if (!Pplh->ULHdbcs)	//not yet expanded                         //~v50fI~
    	return FTRRC_NOTYETEXPANDED;		//not yet expanded     //~v50fI~
	pcout=Poutbuff;                                                //~v50fI~
    pcoute=Poutbuff+Poutbufflen;                                   //~v50fI~
	pc=Pplh->ULHdata;                                              //~v50fI~
	pcd=Pplh->ULHdbcs;                                             //~v50fI~
	reslen=Pplh->ULHlen;                                           //~v50fI~
	rc=FTRRC_NOTABDETECTED;                                        //~v50fI~
	while(reslen)                                                  //~v50fI~
	{                                                              //~v50fI~
		pcdo=pcd;                                                  //~v50fI~
//*on pcd                                                          //~va50I~
		if (pcd=memchr(pcd,TABCHAR,(UINT)reslen),pcd)              //~v50fR~
        {                                                          //~v50fI~
	        rc=FTRRC_TABDETECTED;                                  //~v50fR~
//			len=(int)((ULONG)pcd-(ULONG)pcdo);                     //~v50fR~//~vafkR~
			len=(int)((ULPTR)pcd-(ULPTR)pcdo);                     //~vafkI~
        }                                                          //~v50fI~
        else                                                       //~v50fI~
        	len=reslen;                                            //~v50fI~
	    if (rc==FTRRC_TABDETECTED)	//once tab detected            //~v50fI~
        {                                                          //~v50fI~
            if (pcout+len+1>pcoute)             //buff overflow    //~v50fR~
            {                                                      //~v50fR~
                rc=FTRRC_BUFFOVERFLOW;                             //~v50fR~
                break;                                             //~v50fR~
            }                                                      //~v50fR~
            memcpy(pcout,pc,(UINT)len);                            //~v50fR~
            pcout+=len;                                            //~v50fR~
        }                                                          //~v50fI~
        if (!pcd)	//no more tab                                  //~v50fI~
        	break;                                                 //~v50fI~
//*required for x2B cvcmd                                          //~va50I~
		*pcout++=TABCHAR;                                          //~v50fI~
		pcd++;				//skip tab char                        //~v50fI~
		pc+=len+1;                                                 //~v50fI~
        reslen-=len+1;                                             //~v50fI~
//skip tab pad                                                     //~v50fI~
        while(reslen && *pcd==TABPADCHAR)   //drop previous tab advance char//~v50fI~
        {                                                          //~v50fI~
        	pc++;                                                  //~v50fI~
            pcd++;                                                 //~v50fI~
            reslen--;                                              //~v50fI~
        }                                                          //~v50fI~
	}//end of string                                               //~v50fI~
//  *Ppoutlen=(int)((ULONG)pcout-(UINT)Poutbuff);                  //~va70R~
//  *Ppoutlen=(int)((ULONG)pcout-(ULONG)Poutbuff);                 //~va70I~//~vafkR~
    *Ppoutlen=(int)((ULPTR)pcout-(ULPTR)Poutbuff);                 //~vafkI~
	return rc;                                                     //~v50fI~
}//filetabrestore                                                  //~v50fI~
//**************************************************************** //~v50jI~
//!filegettabexplensub                                             //~v50jI~
//*calculate tab expand length                                     //~v50jI~
//*parm1:bin file sw                                               //~v50jI~
//*parm2:data containing tab                                       //~v50jI~
//*parm3:data len                                                  //~v50jI~
//*rc   :new len                                                   //~v50jI~
//**************************************************************** //~v50jI~
//int filetgettabexplensub(int Pbinsw,char *Pdata,int Plen)        //~v8@2R~
int filetgettabexplensub(int Pbinsw,char *Pdata,int Plen,int Ptabskip)//~v8@2I~
{                                                                  //~v50jI~
	int len,reslen,cpos=0,addskip;                                 //~v50jI~
	UCHAR *pc,*pco;                                                //~v50jI~
//*****************                                                //~v50jI~
  	for (reslen=Plen,pc=Pdata;reslen>0;)                           //~v50jI~
	{                                                              //~v50jI~
    	pco=pc;                                                    //~v50jI~
//*on pcd                                                          //~va50I~
//*from fcmd5 cv:not supported on ebc file                         //~va50I~
		if (!(pc=memchr(pc,TABCHAR,(UINT)reslen)))                 //~v50jI~
        {                                                          //~v50jI~
        	cpos+=reslen;                                          //~v50jI~
			break;                                                 //~v50jI~
        }                                                          //~v50jI~
		pc++;				//skip tab char                        //~v50jI~
//		len=(int)((ULONG)pc-(ULONG)pco);                           //~v50jI~//~vafkR~
		len=(int)((ULPTR)pc-(ULPTR)pco);                           //~vafkI~
		cpos+=len;                                                 //~v50jI~
        reslen-=len;                                               //~v50jI~
//  	addskip=TABSKIPCTR2(Pbinsw,cpos-1);                        //~v8@2R~
    	addskip=TABSKIPCTR2F(Pbinsw,Ptabskip,cpos-1);              //~v8@2R~
        cpos+=addskip;                                             //~v50jI~
	}//end of string                                               //~v50jI~
	return cpos;                                                   //~v50jI~
}//filegettabexplensub                                             //~v50jI~
//*******************************************************          //~v66fI~
//*reset tabexpansion by tabctr change                             //~v66fI~
//*parm  :none                                                     //~v66fI~
//*return:none                                                     //~v66fI~
//*******************************************************          //~v66fI~
int filepfhchktabdbcs(PUFILEH Ppfh)                                //~v66fR~
{                                                                  //~v66fI~
	PULINEH plh;                                                   //~v66fI~
//***************************                                      //~v66fI~
    for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))   //~v66fI~
    {                                                              //~v66fI~
        if (plh->ULHtype!=ULHTDATA) //not file data                //~v66fI~
            continue;                                              //~v66fI~
        if (!plh->ULHdbcs) //not yet expanded                      //~v66fI~
       		if (filechktabdbcs(plh)==UALLOC_FAILED)//expand data len//~v66fI~
            	return UALLOC_FAILED;                              //~v66fI~
    }//all plh                                                     //~v66fI~
	return 0;                                                      //~v66fI~
}//filepfhchktabdbcs                                               //~v66fI~
//**************************************************************** //~v0bbI~
// filetabexpanderr                                                //~v0bbI~
//*tab expand failed                                               //~v0bbI~
//*parm:none                                                       //~v0bbI~
//*rc  :UALLOC_FAILED                                              //~v0bbI~
//**************************************************************** //~v0bbI~
int filetabexpanderr(void)                                         //~v0bbI~
{                                                                  //~v0bbI~
//*******************                                              //~v0bbI~
	uerrmsg("Cannot expand tab,Change tab ctr",                    //~v0bbI~
			"タブ拡張出来ません,タブ桁数を小さくして下さい");      //~va00I~
	return UALLOC_FAILED;                                          //~v0bbI~
}//filetabexpanderr                                                //~v0bbI~
