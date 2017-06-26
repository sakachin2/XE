//*CID://+vb30R~:                             update#=  120;       //+vb30R~
//*************************************************************
//*xefile4.c*                                                      //~v0enR~
//**changeid,cid clear/shift                                       //~v0drR~
//*************************************************************
//vb30:160411 (LNX)Compiler warning                                //+vb30I~
//vazm:150113 set file margin=4095 for recfm=v,MF maxlrecl=4095    //~vazmI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va7J:100904 avoid topline cid option err("CID" was found on topline at tail of the line")//~va7JI~
//va7d:100818 (BUG)updatectr of topline was not updated for enc file when option=( is missing//~va7dI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            file4.c :memcmp for CID                              //~va20I~
//                     ascii cid only for utf8 file                //~va20I~
//v79U:081028 CID append mode                                      //~v79UI~
//v71Z:061114 v71Y miss set version number in the following case   //~v71ZI~
//            for SPF err file opened by en,update then "renum force" because SPFNUMOK set by renum at undo.//~v71ZI~
//v52m:030903 add .java to cid groupe C(allow ext over 3 byte)     //~v42mI~
//v427:010922 filecidlrecl when cidpos==numfld                     //~v427I~
//v423:010918 cidpos=numfld                                        //~v423I~
//v422:010918 (BUG)spf long record written after topline cid err at save is corrected//~v422I~
//            This is by v413.                                     //~v422I~
//            For topline deleted case,keep previous margin/spfpos value//~v422I~
//v421:010918 set default cidpos to 63 for spf file                //~v421I~
//v41h:010806 option effective sequence:topline>cmd option>default //~v41hR~
//v414:010728 EC/ENC/BC/BNC/SC/SNC cmd add for cobol               //~v414I~
//v10Y:990606 support input range by hex offset value(/NXxxx-Xxxx) for edit/browsw cmd//~v10YI~
//            (lineno is couted from 1 even if offset!=0)          //~v10YI~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v10LI~
//v10B:990411 cid for margin file when line width specified.       //~v10BI~
//            if in-margin case give up to set cid,else search cid from last//~v10BI~
//v10z:990411 (BUG)pos of cid for split last line is too far.      //~v10zI~
//            it should consider prev split continued line length. //~v10zI~
//            (But probrem remain in the case cid is spritted or on prev line,//~v10zI~
//            new cid dose not replace but added.)                 //~v10zI~
//v10d:981218 if bin,no cid set                                    //~v10dI~
//v0j6:980720 GCC warning                                          //~v0ifI~
//v0if:980620 pfk cmd support(set mergin MAXCOLUMN)                //~v0ifI~
//v0en:970920 default mergin no consideration for cid pos(all yellow)//~v0enI~
//v0ej:970915 search oom only if cidpos>mergin for mergined file   //~v0ejI~
//v0ef:970915 return ren same lensw instead of contlen             //~v0efI~
//v0ed:970915 generaly search cid in mergin if cidpos<mergin not only for spffile.//~v0edI~
//v0ea:970915 (BUG) of v0df;Scontle cout when !=' '                //~v0e5I~
//v0e6:970915 Also for mergin file with in-mergin cid like as spf file,//~v0e5I~
//            chk/set cid in mergin.                               //~v0e5I~
//v0e5:970914 cid for valid line of spf err file                   //~v0e5I~
//v0dy:970914 search cid in mergin for also spferr file err line   //~v0dyI~
//v0dx:970914 split fileclear from xefile4.c                       //~v0dxI~
//v0du:970909 for performance,use flag once chked spfnumok         //~v0duI~
//            set on when chked,reset when line update or insert.  //~v0duI~
//v0dt:970908 (BUG)cid shift/clear miss if ulhlen==mergin          //~v0dtI~
//v0ds:970908 (BUG)cid shift drop away cid when short rec on mergin file//~v0dsI~
//v0dr:970908 (BUG)cid shift to left remain old value when in mergin ope.//~v0drI~
//v0dn:970907 (BUG)cont and spfline fld drop by cid shift cmd      //~v0dnI~
//v0dk:970907 (BUG)cid not set if cont exist.(see also v0df)       //~v0dnR~
//v0df:970831 (BUG)cid not set if cont exist.(see also v0d3)       //~v0dfI~
//v0da:970831 (BUG)spf flag was set for cb file when CID header line is capped//~v0daI~
//v0d3:970818 (BUG)cont column dropped when copy                   //~v0d3I~
//v0cz:970818 null cid //+NONE~R                                   //~v0czI~
//v0cp:970813 csr set for cid clear/shift                          //~v0cpI~
//v0cn:970813 RENUM undo support(move filerenum from xefile to xefile12)//~v0cnI~
//v0cm:970812 NUM VER subcmd(reset spf version)                    //~v0cmI~
//v0cl:970811 spf NUM field support                                //~v0clI~
//v0ck:970811 search cid regardless mergin for cid clear/shift     //~v0ckI~
//v0cj:970811 8 byte cid=//~dateR(no postfix"~",support cid header only)//~v0cjI~
//v0ci:970810 (BUG)cid clear abend(oldpos is last cidpos)          //~v0ccI~
//v0cc:970803 filegetcidlen return last cidpos                     //~v0ccI~
//v0cb:970802 split allow for long rec even if at out of mergin    //~v0cbI~
//            EOL   allow for long rec even if at out of mergin    //~v0cbI~
//            if mergin=cidpos=topcidpos remain cid                //~v0cbI~
//            else same as no mergin specified                     //~v0cbI~
//v0c9:970802 filecidlrecl return len in mergin and before cidpos  //~v0c8I~
//            (cid pos is fixed if mergin specified.and it is for continuation column)//~v0c8I~
//v0c8:970802 filecidlrecl return len in mergin if cidps<mergin    //~v0c8I~
//v0c5:970802 cid set column fix when mergin specified(miss if data exist,//~v0c5I~
//            but cid previously exist override it.)               //~v0c5I~
//v0c2:970728 simple principle.do not touch/move out of mergin     //~v0c2I~
//            if mergin not specified,last space is not dropped    //~v0c2I~
//v0c1:970728 errornous cid shift when 2 continuous cid            //~v0c1I~
//v0bv:970728 split file4-->file42                                 //~v0bvI~
//v0be:970725 filemerginchk return lrecl witoutcid(change over v0b7)//~v0beI~
//v0bb:970726 limit tabctr max 12,and tab expand limit chk         //~v0bbI~
//v0b8:970725 keep cid pos when shift left if cid shift into mergin//~v0b8I~
//v0b7:970725 filemerginchk return avail space(last data to mergin)//~v0b7I~
//v0b3:970723 clear tab when shift,it is easy to expectate.        //~v0b3I~
//v0ax:970720 (BUG)cid pos remain after "#cidpos" clear(use ustrlen by strlen)//~v0axI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -filetoplinecid return rc                             //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
//v0a1:970705:NULL data accept as 0x00.and change str___ to mem___ //~v0a1I~
//v09G:970614:remain fix CID effect even if first line deleted     //~v09GI~
//v09F:970614:CID postfix support                                  //~v09FI~
//            (change CIDTBL fmt,cidfmt conatin only prefix and postfix)//~v09FI~
//v09r:970521:arbitaly CID type by first line                      //~v09rI~
//            -UFILEH has pos info.                                //~v09rI~
//            -filecidtypechk return cidtbl ptr not but cid for get pos//~v09rI~
//            -filegetcid parm 0:always chk first line,2 chk if sline==0//~v09rI~
//v09q:970521:allow DATE type cid                                  //~v09qI~
//v095:970405:DPMI version                                         //~v095I~
//            -structure init type chk(0 for char arry is err)     //~v095I~
//            -type chk char * and UCHAR *                         //~v095I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07l:960713:(BUG)also for other than PATHLEN(strpbrk,strchr etc) //~v07lI~
//v06C:960407:CID pos default for num=4                               //~v06CI~
//v06r:960325:cid pos for lineno field len =4 as default        //~v06rI~
//            and support CID shift(colomn re-arange)                 //~v06rI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//v03y:950903:pfh path name length for dir entry matching       //~v03yI~
//*v038:950723:bug of v014(addlen calc,bug from before v014)    //~v038I~
//*v031:950712:fixed cid variable apart from Scidtbl(alternative of v021)//~v021I~
//*v021:950710:consider null fixed cid                          //~v021I~
//*v017:950701:fixed cid change  //CID:-->CID:                  //~5701I~
//*v015:950624:ini parm fixed cid                               //~v015I~
//*v014:950624:bug:when save not displayed line after copy file //~v014R~
//*v012:950611:fixed CID                                        //~v014I~
//************************************************************* //~5611I~
//*950528 doc type                                              //~5528I~
//*       cid set position for each type                        //~5528I~
//*950102 tab display by space for hardcopy                     //~5102I~
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
#include <ualloc.h>
#include <uque.h>
#include <ustring.h>                                            //~4C19I~
#include <uedit.h>                                                 //~v0avI~
#include <ufile.h>                                              //~5318I~
#include <ufile5.h>                                                //~vazmI~
#ifdef UTF8UCS2                                                    //~va20I~
#include <udbcschk.h>                                              //~va20R~
#include <utf22.h>                                                 //~va20I~
#endif                                                             //~va20I~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va79I~
#include <utrace.h>                                                //~va50I~
                                                                //~4C19I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v0clI~
#include "xefile4.h"                                            //~5122I~
#include "xefile42.h"                                              //~v0bvI~
#include "xefile6.h"                                               //~v0avI~
#include "xefile7.h"                                               //~v0ifI~
#include "xelcmd4.h"                                               //~v0b8R~
#include "xefunc.h"
#include "xeundo.h"                                             //~5225I~
#include "xechar.h"                                                //~v0avI~
#include "xesub.h"                                                 //~v0bvI~
#ifdef UTF8UCS2                                                    //~va20I~
#include "xesub2.h"                                                //~va20I~
#include "xeutf2.h"                                                //~va20I~
#endif                                                             //~va20I~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************
#define CIDENCLOSER   '~'                                       //~5130R~
#define CIDCURUPDATE  '+'                                       //~5130I~
#define CIDPOSPREFIX  '#'                                          //~v09rI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  #define CIDENCLOSER_EBC   Scidencloser_ebc     //'~' use cp037(a0 by cp290(kana))//~va50R~//~va79R~
    #define CIDENCLOSER_EBC(handle) UCVEBCH_A2B(handle,CIDENCLOSER)  //'~' use cp037(a0 by cp290(kana))//~va79I~
//  #define CIDCURUPDATE_EBC  0x4e        //'+'                    //~va50I~//~va79R~
    #define CIDCURUPDATE_EBC(handle) UCVEBCH_A2B(handle,CIDCURUPDATE)  //'~' use cp037(a0 by cp290(kana))//~va79I~
static 	UCHAR Supdateid_ebc[]="\xd9\xc9\xd4";//"RIM" by ebc	//repl/insert/move//~va50R~
//static 	UCHAR Scidencloser_ebc;    //'~'-->0xa1 by cp037, 0xa0 by cp290(kana)//~va50I~//~va79R~
#endif                                                             //~va50I~
//#define CIDNUMFLDID   'N'                                        //~v0bvR~
static 	UCHAR Supdateid[]="RIM";	//repl/insert/move          //~5131I~
//static 	UCHAR Scid_c[]={'/','/',CIDCURUPDATE,'%','d','%','1','X',//~v09FR~
//						'%','0','2','d','R',CIDENCLOSER,0};        //~v09FR~
//static 	UCHAR Scid_a[]={';',';',CIDCURUPDATE,'%','d','%','1','X',//~v09FR~
//						'%','0','2','d','R',CIDENCLOSER,0};        //~v09FR~
//static 	UCHAR Scid_d[]={'|','|',CIDCURUPDATE,'%','d','%','1','X',//~v09FR~
//						'%','0','2','d','R',CIDENCLOSER,0};//doc file//~v09FR~
//static 	UCHAR Scid_o[]={' ',' ',CIDCURUPDATE,'%','d','%','1','X',//~v09FR~
//						'%','0','2','d','R',CIDENCLOSER,0,0,0};//others//~v09FR~
static 	UCHAR Sciddatefmt[]={CIDCURUPDATE,'%','d','%','1','X',     //~v09FI~
						'%','0','2','d','R',CIDENCLOSER,0};        //~v09FI~
//static 	UCHAR Sdatecid[LINECIDLEN];                                //~v79UI~//~va50R~
static 	UCHAR Sdatecid[LINECIDLEN+1];                              //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
static 	UCHAR Sdatecid_ebc[LINECIDLEN+1];                          //~va50I~
#endif                                                             //~va50I~
//static UCHAR Sexttbl_c[]="C\0H\0CPP\0HPP\0";                     //~v42mR~
static UCHAR Sexttbl_c[]="C\0H\0CPP\0HPP\0JAVA\0";                 //~v42mI~
static UCHAR Sexttbl_a[]="ASM\0";                               //~5310R~
static UCHAR Sexttbl_d[]="DOC\0ME\0";              
static UCHAR Sexttbl_o[]="OTHER THAN ELSE\0";                      //~v09rI~
static CIDTBL Scidtbl[MAXCIDTBL+1]=                                //~v09rR~
//  	{{UFHCIDTYPEC	,80-ULHLINENOSZ-LINECIDLEN+1,Sexttbl_c,Scid_c},//~v06rR~
//       {UFHCIDTYPEASM	,80-ULHLINENOSZ-LINECIDLEN+1,Sexttbl_a,Scid_a},//~v06rR~
//  	{{UFHCIDTYPEC	,80-ULHLINENOSZ5-LINECIDLEN+1,Sexttbl_c,Scid_c},//~v09FR~
    	{{UFHCIDTYPEC	,80-ULHLINENOSZ5-LINECIDLEN+1,"//",Sexttbl_c},//~v09FI~
//       {UFHCIDTYPEASM	,80-ULHLINENOSZ5-LINECIDLEN+1,Sexttbl_a,Scid_a},//~v09FR~
         {UFHCIDTYPEASM	,80-ULHLINENOSZ5-LINECIDLEN+1,";;",Sexttbl_a},//~v09FI~
//       {UFHCIDTYPEDOC	,80-ULHLINENOSZ-2           ,Sexttbl_d,Scid_d},//~v09FR~
         {UFHCIDTYPEDOC	,80-ULHLINENOSZ-2           ,"||",Sexttbl_d},//~v09FI~
//  	0};                                                        //~v095R~
//  	{0,0,0,0}};                                                //~v0ifR~
    	{0,0,"",0}};                                               //~v0ifI~
//static Sgetcidlen; //parm to filegetcidlen from filecidlrecl     //~v0c8R~
static int Stopcidpos;		//parm from filecidlrecl to filegetcidlen//~v414R~
static int Slastcidpos;	//parm from filecidlrecl to filegetcidlen  //~v414R~
static int Scidchklen;   		//parm from filecidlrecl to filegetcidlen//~v414R~
static char Slrecl2sw;                                             //~v0cbI~
static char Sjoinsw=0;                                             //~v71ZR~
static char Slrecl3sw;                                             //~v0czI~
static int  Scopylen;                                              //~v0efR~
//*******************************************************
//void filetoplinecid(PUFILEH Ppfh);                               //~v0avR~
int filetoplinecid(PUFILEH Ppfh);                                  //~v0avI~
void filecidbyext(PUFILEH Ppfh,int Popt,UCHAR *Ppostfix);          //~v09FR~
CIDTBL *filecidprefixchk(UCHAR *Pprefix);                          //~v09FR~
//int filetoplinelrecl(PUFILEH Ppfh,PULINEH Pplh);                 //~v0bvR~
//int  filegetcidlen(PULINEH Pplh,PUFILEH Ppfh,int *Plrecl,int *Ptoppos);//~v0cbR~
int filechkcid(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Pcidpos);    //~v79UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  int fileiscid_ebc(char *Pcidfmt,char *Pcid,int Pcidlen);       //~va50I~//~va79R~
    int fileiscid_ebc(int Phandle,char *Pcidfmt,char *Pcid,int Pcidlen);//~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//****************************************************************//~5528I~
// filegetcidtbl                                                //~5528I~
//*get cid tbl addr                                             //~5528I~
//*parm:none                                                    //~5528I~
//*return:cid tbl addr                                          //~5528I~
//****************************************************************//~5528I~
CIDTBL *filegetcidtbl(void)                                     //~5528I~
{                                                               //~5528I~
//*****************************                                 //~5528I~
    return Scidtbl;                                             //~5528I~
}//filegetcidtbl                                                //~5528I~
                                                                //~5528I~
//****************************************************************//~5528I~
// filecidterm                                                  //~5528I~
//*free malloced cid table extention tbl                        //~5528I~
//*parm:none                                                    //~5528I~
//*return:cid tbl addr                                          //~5528I~
//****************************************************************//~5528I~
void filecidterm(void)                                          //~5528I~
{                                                               //~5528I~
    int ii;                                                     //~5528I~
    UCHAR *pc;                                                  //~5528I~
//*****************************                                 //~5528I~
	for (ii=0;ii<MAXCIDTBL;ii++)//last is fixed cid             //~v021R~
    	if (pc=Scidtbl[ii].CIDTmalloc,pc)                       //~5528R~
        	ufree(pc);                                          //~5528I~
    return;                                                     //~5528I~
}//filecidterm                                                  //~5528I~
                                                                //~5528I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//**************************************************************** //~va50I~
// filegetcid_ebc                                                  //~va50I~
//*return:0:ok,4:file header line cid err                          //~va50I~
//**************************************************************** //~va50I~
//int filegetcid_ebcsub(int Popt,UCHAR *Pcid,UCHAR *Pcidebc,int Plen)//~va50R~//~va79R~
int filegetcid_ebcsub(int Popt,int Phandle,UCHAR *Pcid,UCHAR *Pcidebc,int Plen)//~va79I~
{                                                                  //~va50I~
//************                                                     //~va50I~
//  memcpy(Pcidebc,Pcid,Plen);                                     //~va50R~//+vb30R~
    memcpy(Pcidebc,Pcid,(size_t)Plen);                             //+vb30I~
//  ucvebc_a2bfld(0,Pcidebc,0/*inplace*/,Plen);                    //~va50R~//~va79R~
    ucvebc_a2bfld(0,Phandle,Pcidebc,0/*inplace*/,Plen);            //~va79I~
#ifdef AAA                                                         //~va50I~
    if (Plen>=LINECIDLEN)	//contains last encloser               //~va50R~
    	*(Pcidebc+LINECIDLEN-1)=CIDENCLOSER_EBC;	//"~" codepoint is not fixed on EBC//~va50R~
#endif                                                             //~va50I~
    return 0;                                                      //~va50R~
}//filegetcid_ebc                                                  //~va50I~
//**************************************************************** //~va50I~
// filegetcid_ebc                                                  //~va50I~
//*return:0:ok,4:file header line cid err                          //~va50I~
//**************************************************************** //~va50I~
int filegetcid_ebc(int Popt,PUFILEH Ppfh)                          //~va50I~
{                                                                  //~va50I~
	char *pc;                                                      //~va50I~
//************                                                     //~va50I~
	pc=Ppfh->UFHcid;                                               //~va50I~
    if (!*pc)                                                      //~va50I~
    	return 0;                                                  //~va50I~
//  filegetcid_ebcsub(Popt,pc,Ppfh->UFHcidebc,Ppfh->UFHcidlen);    //~va50I~//~va79R~
    filegetcid_ebcsub(Popt,Ppfh->UFHhandle,pc,Ppfh->UFHcidebc,Ppfh->UFHcidlen);//~va79I~
    return 1;                                                      //~va50I~
}//filegetcid_ebc                                                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//****************************************************************
// filegetcid
//*create change id on pfh                                      //~5225I~
//*parm1:PUFILEH
//*parm2:req type                                                  //~v09FI~
//       0:chk 1st line                                            //~v09FI~
//       1:for cid cmd,save current,set by UFHcidtype set by cmd(on,clear,shift)//~v09FI~
//       2:chk 1st line if sline==0                                //~v09FI~
//       3:for cid cmd,restore saved by req type=1(clear,shift)    //~v09FI~
//*parm3:postfix string(for req type=1 only)                       //~v09FI~
//*parm4:optional output cid ptr                                   //~v0avI~
//*return:0:ok,4:file header line cid err                          //~v0avR~
//****************************************************************
int filegetcid(PUFILEH Ppfh,int Popt,UCHAR *Ppostfix,UCHAR **Ppcid)//~v0avR~
{
//static UCHAR  Scid[LINECIDLEN+1];                                //~v09FR~
    UCHAR  cidwk[LINECIDLENMAX+1];                                 //~v09FI~
	struct tm* plocaltime;       //local time
	time_t stck;                 //stck value
	UCHAR  *pc;                                                 //~5308R~
//  int cidtype;                                                   //~v09rR~
//  CIDTBL *pcidtbl;                                               //~v09FR~
    int hdrcidsw;                                                  //~v09FI~
    int rc;                                                        //~v0avI~
    int cidlen8;                                                   //~v0cjI~
    int handle;                                                    //~va79I~
//*****************************
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	handle=Ppfh->UFHhandle;                                        //~va79I~
//  if (!Scidencloser_ebc)       //char differ by handle           //~va50I~//~va79R~
//  	Scidencloser_ebc=EBC_A2B(CIDENCLOSER);                     //~va50R~//~va79R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (!Ppfh->UFHcidtype)	//first time at open                   //~v09FR~
    {                                                              //~v0avR~
//  	if (!(pc=strpbrk(Ppfh->UFHfilename+Ppfh->UFHpathlen,"."))	//has no extention//~v09FR~
//      ||	!(cidtype=filecidtypechk(++pc,1)))		//invalid ext name//~v09rR~
//      ||	!(pcidtbl=filecidtypechk(++pc,1)))		//invalid ext name//~v09FR~
//      	Ppfh->UFHcidtype=UFHCIDTYPEERR;                        //~v09FR~
//      else                                                       //~v09FR~
//      {                                                          //~v09FR~
//      	Ppfh->UFHcidtype=(UCHAR)cidtype;                       //~v09rR~
//      	Ppfh->UFHcidtype=pcidtbl->CIDTid;   //cid              //~v09FR~
//      	Ppfh->UFHcidpos=pcidtbl->CIDTpos;   //cid position     //~v09FR~
//      }                                                          //~v09FR~
        filecidbyext(Ppfh,0,0);                                    //~v09FR~
   	}//first time                                                  //~v0avR~
//  if (!Popt)	//v012 not by cid cmd                              //~v09rR~
    if (!Popt 	//force 1st line chk                               //~v09FR~
//  ||  (Popt==2 && !Ppfh->UFHsline))//1st line chk if sline==0    //~v10YR~
    ||  (Popt==2 && !Ppfh->UFHsline && !Ppfh->UFHslinepos))//1st line chk if sline==0//~v10YI~
    {                                                              //~v09FI~
        hdrcidsw=UCBITCHK(Ppfh->UFHflag2,UFHF2HDRLINECID);         //~v09FR~
        rc=                                                        //~v0avI~
	    filetoplinecid(Ppfh);   //v012                          //~5611I~
        if (hdrcidsw                                               //~v09FI~
		&&  !UCBITCHK(Ppfh->UFHflag2,UFHF2HDRLINECID))	//hdr line cleared//~v09FI~
	        filecidbyext(Ppfh,0,0);	//reset by filetype            //~v09FR~
		if (rc>=8)	//err                                          //~v0avI~
        	return 4;                                              //~v0avI~
    }                                                              //~v09FI~
    else                                                           //~v09FI~
    	if (Popt==1||Popt==3)	//called by fcmd3 when cid on,clear,shift//~v09FR~
	        filecidbyext(Ppfh,Popt,Ppostfix);	//reset by UFHcidtype//~v09FR~
                                                                //~5308I~
//setup cid                                                     //~5308R~
    if (Ppfh->UFHcidtype==UFHCIDTYPEERR)                        //~5310R~
    	pc=0;                                                   //~5310M~
    else                                                        //~5310I~
    {                                                           //~5308I~
    	if (UCBITCHK(Ppfh->UFHflag2,UFHF2FIXEDCID))//v012       //~5611R~
            pc=Ppfh->UFHcid;	//v012                          //~5611I~
        else									//v012          //~5611I~
        {                                     //v012            //~5611I~
//  	pcidtbl=Scidtbl+(int)Ppfh->UFHcidtype-1;                   //~v09FR~
    	time(&stck);                                            //~5308R~
    	plocaltime=localtime(&stck);                            //~5308R~
//    	sprintf(cidwk,pcidtbl->CIDTcidfmt,                         //~v09FR~
      	sprintf(cidwk,Sciddatefmt,                                 //~v09FI~
    			plocaltime->tm_year%10,                         //~5310R~
    			plocaltime->tm_mon+1,                           //~5310R~
    			plocaltime->tm_mday);                           //~5310R~
		strcpy(Sdatecid,cidwk);	//to compare lastcid is current    //~v79UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  	filegetcid_ebcsub(0,Sdatecid,Sdatecid_ebc,strlen(Sdatecid));//~va50I~//~va79R~
//  	filegetcid_ebcsub(0,handle,Sdatecid,Sdatecid_ebc,strlen(Sdatecid));//~va79I~//+vb30R~
    	filegetcid_ebcsub(0,handle,Sdatecid,Sdatecid_ebc,(int)strlen(Sdatecid));//+vb30I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//v012	if (Popt)                                               //~5611R~
//v012  {                                                       //~5611R~
//  	    strcpy(Ppfh->UFHcid,cidwk);    //crear for retrn       //~v09FR~
//  	    memcpy(Ppfh->UFHcid+LINEPREFIXLEN,cidwk,LINECIDLEN-LINEPREFIXLEN);//postfix may continue//~v0cjI~
            cidlen8=LINECIDLEN-LINEPREFIXLEN;//postfix may continue//~v0cjI~
			if (Ppfh->UFHcidlen<LINECIDLEN)//8 byte cid            //~v0cjI~
	            cidlen8--;                                         //~v0cjI~
    	    memcpy(Ppfh->UFHcid+LINEPREFIXLEN,cidwk,(UINT)cidlen8);//postfix may continue//~v0cjR~
            pc=Ppfh->UFHcid;                                    //~5308R~
//v012	}                                                       //~5611R~
//v012  else                                                    //~5611R~
//v012		pc=Scid;                                            //~5611R~
        }//v012                                                 //~5611I~
	}//not err                                                  //~5310I~
    if (UCBITCHK(Ppfh->UFHflag,UFHFCIDOFF)	//cid off cmd       //~5308M~
    || 	(!UCBITCHK(Ppfh->UFHflag,UFHFCIDON)	//no on cmd            //~v414R~
      &&UCBITCHK(Gopt2,GOPT2NOCID)))	//default is no cid        //~v414R~
		pc=0;	//id of no cid                                  //~5310R~
//  return pc;                                                     //~v0avR~
    if (Ppcid)          //optional output                          //~v0avI~
        *Ppcid=pc;                                                 //~v0avI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	if (PFH_ISEBC(Ppfh))                                           //~va50I~
    	filegetcid_ebc(0,Ppfh);	//set by ebc to search cid on plh  //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    return 0;                                                      //~v0avI~
}//filegetcid

//**************************************************************** //~v09FI~
// filecidbyext                                                    //~v09FI~
//*set cid by file extention                                       //~v09FI~
//*parm1:PUFILEH                                                   //~v09FI~
//*parm2:force type option(0:use extention,1:use UFHcidtype)       //~v09FI~
//*parm3:optional postfix for req type=1 only                      //~v09FI~
//*return:none                                                     //~v09FI~
//**************************************************************** //~v09FI~
void filecidbyext(PUFILEH Ppfh,int Popt,UCHAR *Ppostfix)           //~v09FR~
{                                                                  //~v09FI~
	UCHAR  *pc;                                                    //~v09FI~
	CIDTBL *pcidtbl=NULL;                                               //~v09FI~//~vaf9R~
static  char Scidtypesv,Scidpossv,Sfixidsv,Scidlen;                //~v09FR~
static  char Scidsv[sizeof(Ppfh->UFHcid)];                         //~v09FR~
//*************************                                        //~v09FI~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))  //bin file             //~v10dI~
    {                                                              //~v10dI~
    	Ppfh->UFHcidtype=UFHCIDTYPEERR;                            //~v10dI~
        return;                                                    //~v10dI~
    }                                                              //~v10dI~
  	if (Popt==3)                                                   //~v09FI~
    {                                                              //~v09FI~
        Ppfh->UFHcidtype=Scidtypesv;                               //~v09FI~
        Ppfh->UFHcidpos=Scidpossv;                                 //~v09FI~
        Ppfh->UFHcidlen=Scidlen;                                   //~v09FI~
        memcpy(Ppfh->UFHcid,Scidsv,sizeof(Ppfh->UFHcid));          //~v09FI~
		UCBITON(Ppfh->UFHflag2,Sfixidsv);                          //~v09FR~
        return;                                                    //~v09FI~
	}                                                              //~v09FI~
  	if (Popt==1)	                                               //~v09FR~
    {                                                              //~v09FI~
        Scidtypesv=Ppfh->UFHcidtype;                               //~v09FI~
        Scidpossv=Ppfh->UFHcidpos;                                 //~v09FI~
        Scidlen=Ppfh->UFHcidlen;                                   //~v09FI~
        memcpy(Scidsv,Ppfh->UFHcid,sizeof(Ppfh->UFHcid));          //~v09FI~
        Sfixidsv=(char)UCBITCHK(Ppfh->UFHflag2,UFHF2FIXEDCID|UFHF2HDRLINECID);//~v09FI~
		UCBITOFF(Ppfh->UFHflag2,UFHF2FIXEDCID|UFHF2HDRLINECID);    //~v09FR~
    	pcidtbl=Scidtbl+(int)Ppfh->UFHcidtype-1;                   //~v09FI~
	}                                                              //~v09FI~
  if (!Popt                                                        //~v09FI~
  && (                                                             //~v09FI~
	    !(pc=strpbrk(Ppfh->UFHfilename+Ppfh->UFHpathlen,"."))	//has no extention//~v09FR~
    ||	!(pcidtbl=filecidtypechk(++pc,1)))		//invalid ext name //~v09FI~
     )                                                             //~v09FR~
    	Ppfh->UFHcidtype=UFHCIDTYPEERR;                            //~v09FI~
    else                                                           //~v09FI~
    {                                                              //~v09FI~
    	Ppfh->UFHcidtype=pcidtbl->CIDTid;   //cid                  //~v09FI~
    	Ppfh->UFHcidpos=pcidtbl->CIDTpos;   //cid position         //~v09FI~
    	Ppfh->UFHcidlen=(UCHAR)(LINECIDLEN                         //~v09FR~
                       +strlen(pcidtbl->CIDTcidfmt+LINEPREFIXLEN));			//default cidlen//~v09FR~
    	strcpy(Ppfh->UFHcid,pcidtbl->CIDTcidfmt);	//defualt      //~v09FI~
    	strcpy(Ppfh->UFHcid+LINECIDLEN,pcidtbl->CIDTcidfmt+LINEPREFIXLEN);	//defualt//~v09FI~
        if (Popt==1 && Ppostfix && *Ppostfix)                      //~v09FI~
        {                                                          //~v09FI~
	    	Ppfh->UFHcidlen=(UCHAR)(LINECIDLEN+strlen(Ppostfix));  //~v09FR~
    		strcpy(Ppfh->UFHcid+LINECIDLEN,Ppostfix);	//defualt  //~v09FI~
        }                                                          //~v09FI~
    }                                                              //~v09FI~
    return;                                                        //~v09FI~
}//filecidbyext                                                    //~v09FI~
//****************************************************************//~5611I~
// filetoplinecid v012                                          //~5611I~
//*chk topline cid req fmt   "Fixed-CID:xx+xxxxx~               //~5611I~
//*parm1:PUFILEH                                                //~5611I~
//*return:rc 0:ok,4:no topline cid,8 err                           //~v0avR~
//****************************************************************//~5611I~
//void filetoplinecid(PUFILEH Ppfh)                                //~v0avR~
int filetoplinecid(PUFILEH Ppfh)                                   //~v0avI~
{                                                               //~5611I~
    int pos;                                                       //~v09rI~
    int defaultpossw=0;                                            //~v421I~
    int postfixlen,linecidlen;                                     //~v09FI~
	CIDTBL *pcidtbl;                                            //~5611I~
    PULINEH plh;                                                //~5611I~
    UCHAR *pc;                                                  //~5611I~
    UCHAR *pc2;                                                    //~v09FI~
#ifdef UTF8UCS2                                                    //~va20I~
    UCHAR *pcd,*pcd0;                                              //~va20R~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    UCHAR *pc0,*pc00=NULL,*pcd00=NULL;                                       //~va50R~//~vaf9R~
    int swebcfile,rc2,upctrpos,upctrlen;                           //~va50R~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************************                                 //~5611I~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
    handle=Ppfh->UFHhandle;                                        //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//init for each call                                               //~v0avM~
  if (!UCBITCHK(Ppfh->UFHflag4,UFHF4SPFCMD))  // /Mn option        //~v41hI~
  {                                                                //~v41hI~
//  Ppfh->UFHspfpos=0;                                             //~v422R~
  if (!Ppfh->UFHlrecl) //initial                                   //~v422I~
    Ppfh->UFHlrecl=MAXLINEDATA;                                    //~v0avI~
//  Ppfh->UFHmergin=(USHORT)(MAXLINEDATA-LINECIDLENMAX);           //~v0enR~
  if (!Ppfh->UFHmergin) //initial                                  //~v422I~
  {                                                                //~vazmI~
   if (Ppfh->UFHvfmt==UFGETS_VFMT_MFH2) //2 byte mfh record header //~vazmI~
    Ppfh->UFHmergin=(USHORT)VFMT_MAXLEN_MFH2;                      //~vazmI~
   else                                                            //~vazmI~
    Ppfh->UFHmergin=(USHORT)MAXLINEDATA;                           //~v0enI~
  }                                                                //~vazmI~
                                                                   //~v0avI~
//  UCBITOFF(Ppfh->UFHflag2,UFHF2HDRLINECID);	//no cid on hdr line//~v09GR~
//  UCBITOFF(Ppfh->UFHflag2,UFHF2HDRLINECID|UFHF2FIXEDCID);	//no cid on hdr line//~v0c2R~
//  UCBITOFF(Ppfh->UFHflag2,                                       //~v422R~
//  			UFHF2HDRLINECID|UFHF2FIXEDCID|UFHF2MERGIN|UFHF2MERGINCID);	//no cid on hdr line//~v422R~
  }                                                                //~v41hI~
    UCBITOFF(Ppfh->UFHflag2,UFHF2HDRLINECID|UFHF2FIXEDCID|UFHF2MERGINCID);	//no cid on hdr line//~v422I~
    if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))  //bin file             //~v10dI~
    {                                                              //~v10dI~
		Ppfh->UFHcidtype=UFHCIDTYPEERR;                            //~v10dI~
        return 4;                                                  //~v10dI~
	}                                                              //~v10dI~
                                                                   //~v10dI~
  	if (UCBITCHK(Ppfh->UFHflag,UFHFWORKDIRFILE))  //cb or so       //~v0daI~
    {                                                              //~v0daI~
		Ppfh->UFHcidtype=UFHCIDTYPEERR;                            //~v0daI~
        return 4;                                                  //~v0daI~
	}                                                              //~v0daI~
//    if (UCBITCHK(Ppfh->UFHflag4,UFHF4SPFCMD))  // /Mn option     //~v41hR~
//    {                                           //same as cid=NONE//~v41hR~
//        Ppfh->UFHcidtype=UFHCIDTYPEERR;                          //~v41hR~
//        Ppfh->UFHcidlen=0;                                       //~v41hR~
//        Ppfh->UFHcidpos=0;                                       //~v41hR~
//        *Ppfh->UFHcid=0;                                         //~v41hR~
//        filedefaultspf(Ppfh);                   //SPF setting as default//~v41hR~
//    }                                                            //~v41hR~
//  if (UGETQCTR(&Ppfh->UFHlineque)<=2)	//no data                  //~v0clR~
//    	return 4;    	                                           //~v0clR~
    plh=UGETQTOP(&Ppfh->UFHlineque);		//hdr               //~5611R~
    if (!plh)                                                      //~v0clI~
      	return 4;                                                  //~v0clI~
    plh=UGETQNEXT(plh);					//2nd                      //~v0clR~
    if (!plh)                                                      //~v0clI~
      	return 4;                                                  //~v0clI~
    if (plh->ULHtype==ULHTEXCLUDE)      //2nd excluded             //~v0clI~
        plh=UGETQNEXT(plh);             //next of excluded         //~v0clI~
    if (plh->ULHtype!=ULHTDATA)         //2nd line                 //~v0clI~
      	return 4;                                                  //~v0clI~
    if (!*Gfixcidid)	//nullify at ini                        //~v031R~
		return 4;                                                  //~v0avR~
//  if (!(pc=ustrnstri(plh->ULHdata,Gfixcidid,(UINT)plh->ULHlen)))//case insense//~v0a1R~
#ifdef UTF8UCS2                                                    //~va20I~
    pcd=pcd0=plh->ULHdbcs;                                         //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    pc0=plh->ULHdata;                                              //~va50I~
  	if (swebcfile)                                                 //~va50I~
  	{                                                              //~va50I~
    	pc0=pcd0=0;	//request set temp area addr                   //~va50I~
//  	if (xeebc_b2msetdbcs(0,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,&pc0,&pcd0,0/*outlen*/))//~va50R~//~va79R~
    	if (xeebc_b2msetdbcs(0,handle,plh->ULHdata,plh->ULHdbcs,plh->ULHlen,&pc0,&pcd0,0/*outlen*/))//~va79I~
        	return 4;	//UALLOC_FAILED                            //~va50I~
        pcd=pcd0;                                                  //~va50I~
  	}                                                              //~va50I~
  #endif //UTF8EBCD raw ebcdic file support                        //~va50I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    if (!(pc=UTF_umemstri(swutf8file && pcd0,pc0,pcd,Gfixcidid,0/*keydbcs*/,plh->ULHlen)))//case insense//~va50I~
  #else                                                            //~va50I~
    if (!(pc=UTF_umemstri(swutf8file && pcd0,plh->ULHdata,pcd,Gfixcidid,0/*keydbcs*/,plh->ULHlen)))//case insense//~va20R~
  #endif                                                           //~va50I~
#else                                                              //~va20I~
    if (!(pc=umemstri(plh->ULHdata,Gfixcidid,(UINT)plh->ULHlen)))//case insense//~v0a1I~
#endif                                                             //~va20I~
		return 4;                                                  //~v0avR~
//  if (((ULONG)pc-(ULONG)pc0)>=MAX_CIDPOS)                        //~va7JI~//~vafkR~
    if (((ULPTR)pc-(ULPTR)pc0)>=MAX_CIDPOS)                        //~vafkI~
		return 4;                                                  //~va7JI~
    pc+=strlen(Gfixcidid);                                      //~v031R~
//  pos=(int)strlen(pc);                                           //~v0axR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  pos=(int)(plh->ULHlen-((ULONG)pc-(ULONG)pc0));	//residual len //~va50I~//~vafkR~
//  pos=(int)(plh->ULHlen-((ULPTR)pc-(ULPTR)pc0));	//residual len //~vafkI~//+vb30R~
    pos=plh->ULHlen-PTRDIFF(pc,pc0);	//residual len             //+vb30I~
#else                                                              //~va50I~
    pos=(int)(plh->ULHlen-((ULONG)pc-(ULONG)plh->ULHdata));	//residual len//~v0axR~
#endif                                                             //~va50I~
    postfixlen=-1;			//for 8 byte cid                       //~v0cjI~
//*ascii chk of cid will be done later                             //~va20I~
    if ((pos>LINECIDLEN              //enough len                  //~v0cjR~
	&&  *(pc+2)==CIDCURUPDATE                                      //~v09rR~
	&&  memchr(Supdateid,*(pc+LINECIDLEN-2),3)	//update id RIM    //~v0cjI~
	&&  *(pc+LINECIDLEN-1)==CIDENCLOSER                         //~5611R~
//  &&  *(pc+LINECIDLEN)==':')                                     //~v09FR~
//  &&  (pc2=strchr(pc+LINECIDLEN,':'),pc2)                        //~v0axR~
    &&  (pc2=memchr(pc+LINECIDLEN,':',(UINT)(pos-LINECIDLEN)),pc2) //~v0axI~
//  &&  ((postfixlen=(int)((ULONG)pc2-(ULONG)pc-LINECIDLEN))       //~v09FR~//~vafkR~
    &&  ((postfixlen=(int)((ULPTR)pc2-(ULPTR)pc-LINECIDLEN))       //~vafkI~
        <=(LINECIDLENMAX-LINECIDLEN)))                             //~v0cjR~
    ||                                                             //~v0cjI~
        (pos>=LINECIDLEN              //enough len                 //~v0cjI~
	&&  *(pc+2)==CIDCURUPDATE                                      //~v0cjI~
	&&  memchr(Supdateid,*(pc+LINECIDLEN-2),3)	//update id RIM    //~v0cjI~
	&&  *(pc+LINECIDLEN-1)==':'))                                  //~v0cjI~
    {                                                           //~5611I~
    	UCBITON(Ppfh->UFHflag2,UFHF2HDRLINECID);	//no cid on hdr line//~v0czM~
#ifdef UTF8UCS2                                                    //~va20I~
		if (pcd0)                                                  //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    		pcd=XEUTF_PC2PCD(pcd0,pc+3,pc0);                       //~va50I~
    #else                                                          //~va50I~
    		pcd=XEUTF_PC2PCD(pcd0,pc+3,plh->ULHdata);              //~va20I~
    #endif                                                         //~va50I~
      if (!XESUB_memicmp(swutf8file && pcd0,pc+3,pcd,"NONE",0,4))  //~va20R~
#else                                                              //~va20I~
      if (!memicmp(pc+3,"NONE",4))                                  //~v0czI~
#endif                                                             //~va20I~
      {                                                            //~v0czI~
        Ppfh->UFHcidtype=UFHCIDTYPEERR;                            //~v0czI~
    	Ppfh->UFHcidlen=0;                                         //~v0czI~
        Ppfh->UFHcidpos=0;                                         //~v0czI~
        *Ppfh->UFHcid=0;                                           //~v0czI~
      }                                                            //~v0czI~
      else  //not none                                             //~v0czI~
      {                                                            //~v0czI~
    	linecidlen=LINECIDLEN+postfixlen;                          //~v09FR~
    	Ppfh->UFHcidlen=(UCHAR)linecidlen;                         //~v09FI~
//      if (*(pc+linecidlen+1)==CIDPOSPREFIX)                      //~v0axR~
        if (pos>linecidlen+1                                       //~v0axI~
        &&  *(pc+linecidlen+1)==CIDPOSPREFIX)                      //~v0axI~
        {                                                          //~v09rI~
//          pos=atoi(pc+linecidlen+2);                             //~v0axR~
#ifdef UTF8UCS2                                                    //~va20I~
            if (pcd0)                                              //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
				pcd=XEUTF_PC2PCD(pcd0,pc+linecidlen+2,pc0);        //~va50I~
    #else                                                          //~va50I~
				pcd=XEUTF_PC2PCD(pcd0,pc+linecidlen+2,plh->ULHdata);//~va20R~
    #endif                                                         //~va50I~
            pos=UTF_uatoin(swutf8file && pcd0,pc+linecidlen+2,pcd,pos-linecidlen-2);//~va20R~
#else                                                              //~va20I~
            pos=uatoin(pc+linecidlen+2,pos-linecidlen-2);          //~v0axI~
#endif                                                             //~va20I~
            if (pos>256 || pos<0)                                  //~v09rR~
            {                                                      //~v09rI~
        		uerrmsg("CID column parm on 1st line must be 1-->256",//~v09rR~
        				"1行目のCID桁位置指定の値は1から256迄です");//~v09rR~
				pos=1;                                             //~v09rR~
			}                                                      //~v09rI~
        }                                                          //~v09rI~
        else                                                       //~v09rI~
        	pos=0;		//id of not specified                      //~v09rR~
//  	for (pcidtbl=Scidtbl,ii=0;ii<MAXCIDTBL;pcidtbl++,ii++)     //~v09FR~
//  		if (pcidtbl->CIDTid)	//defined                      //~v09FR~
//  	 		if (!memcmp(pcidtbl->CIDTcidfmt,pc,2))	//defined  //~v09FR~
//  	    		break;                                         //~v09FR~
//  	if (ii==MAXCIDTBL)	//not defined                          //~v09FR~
    	if (!(pcidtbl=filecidprefixchk(pc)))	//not defined      //~v09FI~
        {                                                          //~v09rI~
//  		return;    	                                           //~v09rR~
	        Ppfh->UFHcidtype=UFHCIDTYPEOTHER;                      //~v09rI~
            Scidtbl[UFHCIDTYPEOTHER-1].CIDTexttbl=Sexttbl_o;       //~v09rI~
//          Scidtbl[UFHCIDTYPEOTHER-1].CIDTcidfmt=Scid_o;	//temporary//~v09FR~
            strcpy(Scidtbl[UFHCIDTYPEOTHER-1].CIDTcidfmt,"  ");	//temporary//~v09FR~
//          memcpy(Scid_o,pc,2);	//temporary                    //~v09FR~
        	if (pos)     //pos parm exist                          //~v09rR~
        		Ppfh->UFHcidpos=(char)(pos-1);                     //~v09rR~
        	else                                                   //~v09rI~
            {                                                      //~v421I~
        		Ppfh->UFHcidpos=0;                                 //~v09rI~
                defaultpossw=1;                                    //~v421I~
            }                                                      //~v421I~
        }                                                          //~v09rI~
        else                                                       //~v09rI~
        {                                                          //~v09rI~
        Ppfh->UFHcidtype=pcidtbl->CIDTid;                       //~5611I~
        	if (pos)     //pos parm exist                          //~v09rR~
        		Ppfh->UFHcidpos=(char)(pos-1);                     //~v09rR~
        	else                                                   //~v09rI~
            {                                                      //~v421I~
        		Ppfh->UFHcidpos=pcidtbl->CIDTpos;                  //~v09rR~
                defaultpossw=1;                                    //~v421I~
            }                                                      //~v421I~
        }                                                          //~v09rI~
//*later ascii chk will be done                                    //~va20I~
      if (memicmp(pc+3,"DATE",4))                                  //~v09qM~
//    {                                                            //~v09FR~
    	UCBITON(Ppfh->UFHflag2,UFHF2FIXEDCID);                  //~5611I~
        memcpy(Ppfh->UFHcid,pc,LINECIDLEN);                     //~5611I~
        *(Ppfh->UFHcid+LINECIDLEN-2)='R';                       //~5611I~
//    }                                                            //~v09FR~
//    else          //Fixed-CID:xx+DATEr~                          //~v09FR~
//    {                                                            //~v09FR~
//  	UCBITOFF(Ppfh->UFHflag2,UFHF2FIXEDCID);                    //~v09GR~
//      memset(Ppfh->UFHcid,0,LINECIDLEN);  //clear previous set   //~v09FR~
//      memset(Ppfh->UFHcid,0,sizeof(Ppfh->UFHcid));  //clear previous set//~v09FR~
//    }                                                            //~v09FR~
//      if (postfixlen)                                            //~v0cjR~
        if (postfixlen>0)	//not 8byte cid and has postfix        //~v0cjI~
        {                                                          //~va20I~
			memcpy(Ppfh->UFHcid+LINECIDLEN,pc+LINECIDLEN,(UINT)postfixlen);  //clear previous set//~v09FM~
        }                                                          //~va20I~
		*(Ppfh->UFHcid+LINECIDLEN+postfixlen)=0;  //string         //~v09FM~
#ifdef UTF8UCS2                                                    //~va20I~
		if (swutf8file)                                            //~va20R~
        {                                                          //~va20I~
        	pcd=plh->ULHdbcs;                                      //~va20I~
            if (pcd)    //not yet setup at fileload,chked at save  //~va20I~
            {                                                      //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//              pcd+=(ULONG)pc-(ULONG)pc0;                         //~va50I~//~vafkR~
                pcd+=(ULPTR)pc-(ULPTR)pc0;                         //~vafkI~
    #else                                                          //~va50I~
                pcd+=(ULONG)pc-(ULONG)(plh->ULHdata);              //~va20R~
    #endif                                                         //~va50I~
                if (!utfddisasciistr(0,pc,pcd,LINECIDLEN+postfixlen)) //compare ascii//~va20R~
                {                                                  //~va20R~
                    uerrmsg("CID on 1st line format error(it should be ascii for UTF8 file)",//~va20R~
                            "1行目のCID指定形式の誤り(UTF8ファイルはasciiのみOK)");//~va20R~
                            return 8;                              //~va20R~
                }                                                  //~va20R~
            }                                                      //~va20I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
      }//NONE or else                                              //~v0czI~
//fixed pos cid                                                    //~v0avI~
//  	if (filetoplinelrecl(Ppfh,plh,default)>=8)	//err          //~v421R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    	if (swebcfile)                                             //~va50I~
        {                                                          //~va50I~
    		pc00=plh->ULHdata;                                     //~va50I~
    		pcd00=plh->ULHdbcs;                                    //~va50I~
        	plh->ULHdata=pc0;                                      //~va50I~
        	plh->ULHdbcs=pcd0;                                     //~va50I~
                                                                   //~va50I~
        }                                                          //~va50I~
        upctrpos=0;                                                //~va50I~
    	rc2=filetoplinelrecl(Ppfh,plh,defaultpossw,&upctrpos);     //~va50R~
    	if (swebcfile)                                             //~va50I~
        {                                                          //~va50I~
    		plh->ULHdata=pc00;                                     //~va50I~
    		plh->ULHdbcs=pcd00;                                    //~va50I~
//  		if (!rc2 && UCBITCHK(Ppfh->UFHflag5,UFHF5TLUCTR))	//updatecr update req//~va7dR~
    		if (rc2<8 && UCBITCHK(Ppfh->UFHflag5,UFHF5TLUCTR))	//rc=4:is not err;updatecr update req//~va7dI~
            {                                                      //~va50I~
            	upctrlen=upctrpos&0xff;                            //~va50I~
                upctrpos>>=8;                                      //~va50I~
//              ucvebc_a2bfld(0,pc0+upctrpos,pc00+upctrpos,upctrlen);	//cv upctr m2b//~va50R~//~va79R~
                ucvebc_a2bfld(0,handle,pc0+upctrpos,pc00+upctrpos,upctrlen);	//cv upctr m2b//~va79I~
            }	                                                   //~va50I~
        }                                                          //~va50I~
    	if (rc2>=8)	//err                                          //~va50I~
    #else                                                          //~va50I~
    	if (filetoplinelrecl(Ppfh,plh,defaultpossw)>=8)	//err      //~v421I~
    #endif                                                         //~va50I~
        	return 8;                                              //~v0avI~
   	}//cid on top line                                          //~5611I~
    else                                                           //~v09rI~
    {                                                              //~v0avI~
		uerrmsg("CID on 1st line format error.",                    //~v09rI~//~va20R~
			"1行目のCID指定形式の誤り。");                           //~v09rI~//~va20R~
        return 8;                                                  //~v0avI~
    }                                                              //~v0avI~
	return 0;                                                      //~v0avR~
}//filetoplinecid                                               //~5611I~
                                                                //~5611I~
//****************************************************************
// filesetcid
//*set cid to line
//* called only when cid is avail from xefile.c filesave        //~5528I~
//*parm1:pfh                                                    //~5310R~
//*parm2:plh                                                    //~5310I~
//*parm3:output data buff addr                                  //~5310R~
//*parm4:output dbcs buff addr                                  //~5310R~
//*parm5:cid patern                                             //~v014R~
//*parm6:added len field                                        //~v014R~
//*return:rc 0:no cid changed 1:cid changed(data copy occuerd)
//*          UALLOC_FAILED if storage shortage                  //~v04dI~
//****************************************************************
int  filesetcid(PUFILEH Ppfh,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,//~v014R~
				UCHAR *Pcid,int *Paddlen,int Psplittotlen)         //~v10zR~
{
static UCHAR  Stabspace[2]={" "};                               //~5102I~
	int addlen=0,len,reclen;                                    //~v014R~
	UCHAR *pc,*pdata;
	UCHAR *pdbcs;                                                  //~v0clI~
//	UCHAR *postfix;                                                //~v0cjR~
	int pos,gpos;                                               //~5528R~
    int gpos0;                                                     //~v0c5I~
	int linecidlen;                                                //~v0cjR~
//	int postfixlen;                                                //~v0cjI~
    int lastcidpos,cutlen;                                         //~v0clR~
    int skipsw;                                                    //~v0clI~
    int netdatalen=0;                                                //~v0clI~//~vaf9R~
//  int spfsw;                                                     //~v0e5R~
    int inmergincidsw;                                             //~v0e5I~
    int onnumcidsw;                                                //~v423I~
    int cpossv,marginsv,splitcpos,splitmargin;                     //~v10BR~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//*****************************
#ifdef UTF8UCS2                                                    //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD                                                    //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
    handle=Ppfh->UFHhandle;                                        //~va79I~
#endif                                                             //~va50I~
	*Paddlen=0;
	pdata=Pplh->ULHdata;
    reclen=Pplh->ULHlen;                                        //~v014I~
    linecidlen=Ppfh->UFHcidlen;                                    //~v09FI~
//  postfixlen=linecidlen-(LINECIDLEN-1); //contain encloser       //~v0cjR~
//  postfix=Pcid+LINECIDLEN-1;                                     //~v0cjR~
//  spfsw=UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);   //~v0e5R~
//  if (spfsw)                                                     //~v0e5R~
//  	spfsw=fileisvalidspfline(Ppfh,Pplh,0);                     //~v0e5R~
    inmergincidsw=(UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN)            //~v0e5I~
                  && (Ppfh->UFHcidpos<Ppfh->UFHmergin));           //~v0e5R~
    onnumcidsw=(UCBITCHK(Ppfh->UFHflag2,UFHF2MERGINCID)            //~v423R~
                  && Ppfh->UFHspfpos); //cid on numfld             //~v423R~
 if (onnumcidsw)	//not cid on numfld                            //~v423R~
 	lastcidpos=Ppfh->UFHmergin;                                    //~v423I~
 else                                                              //~v423I~
 {                                                                 //~v423I~
//  filegetcidlen2(Pplh,Ppfh,&netdatalen,0,&lastcidpos);//netlen=topcidpos=0//~v0e5R~
  if (Psplittotlen)                                                //~v10BR~
  {                          		//margin should be ignored to search cid//~v10BI~
    marginsv=Ppfh->UFHmergin;                                      //~v10BI~
    cpossv  =Ppfh->UFHcidpos;                                      //~v10BI~
    if ((splitcpos=cpossv-Psplittotlen)<0)		//pos in last rec  //~v10BR~
    	splitcpos=0;                                               //~v10BI~
    if ((splitmargin=marginsv-Psplittotlen)<0)		//pos in last rec//~v10BR~
    	splitmargin=0;                                             //~v10BI~
    Ppfh->UFHmergin=(USHORT)splitmargin;                           //~v10BR~
    Ppfh->UFHcidpos=(UCHAR)splitcpos;                              //~v10BR~
	filegetcidlen(Pplh,Ppfh,&netdatalen,0,&lastcidpos);//search margin range as concat line//~v10BR~
    Ppfh->UFHmergin=(USHORT)marginsv;                              //~v10BR~
    Ppfh->UFHcidpos=(UCHAR)cpossv;                                 //~v10BR~
  }                                                                //~v10BI~
  else                                                             //~v10BI~
    filegetcidlen(Pplh,Ppfh,&netdatalen,0,&lastcidpos);//netlen=topcidpos=0//~v0e5I~
    if (Ppfh->UFHcidtype==UFHCIDTYPEC)  //c type                //~5310R~
//      if (pc=ustrnrchr(pdata,'\\',(UINT)reclen),pc) //may continue sign//~v0a1R~
//      if (pc==(UCHAR*)ustrnrchr2(pdata,'\\',reclen)) //SBCS '\'  //~v0a1R~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        if (pc=                                                    //~va50I~
        	  UWHICH(swebcfile,	                                   //~va50R~
//  			(UCHAR*)ucvebc_umemrchr(UCVEBCO_A2B,pdata,Pplh->ULHdbcs,'\\',reclen),//~va50I~//~va79R~
    			(UCHAR*)ucvebc_umemrchr(UCVEBCO_A2B,handle,pdata,Pplh->ULHdbcs,'\\',reclen),//~va79I~
				(UCHAR*)UTF_umemrchr2(swutf8file,pdata,Pplh->ULHdbcs,'\\',reclen)//~va50I~
                   ),                                              //~va50R~
			pc) //SBCS '\'                                         //~va50I~
	#else                                                          //~va50I~
        if (pc=(UCHAR*)UTF_umemrchr2(swutf8file,pdata,Pplh->ULHdbcs,'\\',reclen),pc) //SBCS '\'//~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
//      if (pc=(UCHAR*)umemrchr2(swutf8file,pdata,'\\',(UINT)reclen),pc) //SBCS '\'//~v0a1R~//~va20R~
        if (pc=(UCHAR*)umemrchr2(pdata,'\\',(UINT)reclen),pc) //SBCS '\'//~va20I~
#endif                                                             //~va20I~
   	 	{                                                       //~5310R~
// 		 	len=(int)(reclen-((ULONG)pc-(ULONG)pdata)-1);//no char after//~v014R~//~vafkR~
//  	 	len=(int)(reclen-((ULPTR)pc-(ULPTR)pdata)-1);//no char after//~vafkI~//+vb30R~
    	 	len=reclen-PTRDIFF(pc,pdata)-1;//no char after         //+vb30I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
    		if (UWHICH(swebcfile,                                  //~va50I~
					(int)ucvebc_umemspnc(UCVEBCO_STRN,pc+1,XEUTF_PC2PCD(Pplh->ULHdbcs,pc+1,pdata),CHAR_EBC_SPACE,len)==len,//no significant cha after//~va50R~
					(int)UTF_ustrnspn(swutf8file,pc+1,XEUTF_PC2PCD(Pplh->ULHdbcs,pc+1,pdata),Stabspace,len)==len//no significant cha after//~va50R~
                      )                                            //~va50I~
               )                                                   //~va50I~
	#else                                                          //~va50I~
    		if ((int)UTF_ustrnspn(swutf8file,pc+1,XEUTF_PC2PCD(Pplh->ULHdbcs,pc+1,pdata),Stabspace,len)==len)//no significant cha after//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
    		if ((int)ustrnspn(pc+1,Stabspace,(UINT)len)==len)//no significant cha after//~v0a1R~
#endif                                                             //~va20I~
        	   	return 0;                                       //~5310R~
   		}//line continuation                                    //~5310R~
 }//not cid on spfnum fld                                          //~v423I~
	pc=pdata+reclen;								//buff end  //~v014R~
	if (!Pplh->ULHupctr 	//not updated                       //~5225R~
    ||  UCBITCHK(Pplh->ULHflag,ULHFCIDCLEAR) //update is cid clear only//~v0cmR~
    ||  UCBITCHK(Pplh->ULHflag4,ULHF4REPRENUM) //update is cid clear only//~v71ZI~
    ||  UCBITCHK(Pplh->ULHflag3,ULHF3SETSPFVER)) //update is ver set only//~v0cmI~
	{                                                           //~5130I~
//reset current update id                                       //~5225I~
//  	if (reclen>=linecidlen			//can contain cid          //~v0cjR~
//  	&&  *(pc-1)==CIDENCLOSER		//last byte of cid         //~v09FR~
//  	&&  !memcmp(pc-postfixlen,postfix,(UINT)postfixlen)//postfix match//~v0cjR~
//  	&&  !memcmp(pc-linecidlen,Pcid,3))//latest update cid      //~v0cjR~
//*after cid fmt is confirmed as all ascii at filegetcidlen        //~va20I~
    	if (lastcidpos						//cid contain          //~v0cjI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  	&&  *(pdata+lastcidpos+2)==UCVEBC_CONST(swebcfile,CIDCURUPDATE))//latest update cid//~va50I~//~va79R~
    	&&  *(pdata+lastcidpos+2)==UWHICH(swebcfile,CIDCURUPDATE_EBC(handle),CIDCURUPDATE))//latest update cid//~va79R~
#else                                                              //~va50I~
    	&&  *(pdata+lastcidpos+2)==CIDCURUPDATE)//latest update cid//~v0cjR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		{                                                       //~5130I~
			memcpy(Pdata,pdata,(UINT)reclen);	//original data //~v014R~
			if (Pplh->ULHdbcs)	//not once displayed 
				memcpy(Pdbcs,Pplh->ULHdbcs,(UINT)reclen);	//original data//~v014R~
//  		*(Pdata+reclen-linecidlen+2)=CIDENCLOSER;//reset latest update cid//~v0cjR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  		*(Pdata+lastcidpos+2)=UCVEBC_CONST(swebcfile,CIDENCLOSER);//reset latest update cid//~va50I~//~va79R~
//  		*(Pdata+lastcidpos+2)=UWHICH(swebcfile,CIDENCLOSER_EBC(handle),CIDENCLOSER);//reset latest update cid//~va79R~//+vb30R~
    		*(Pdata+lastcidpos+2)=(UCHAR)UWHICH(swebcfile,CIDENCLOSER_EBC(handle),CIDENCLOSER);//reset latest update cid//+vb30I~
#else                                                              //~va50I~
			*(Pdata+lastcidpos+2)=CIDENCLOSER;//reset latest update cid//~v0cjI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
           	return 1;                                           //~5130I~
		}                                                       //~5130I~
		return 0;		//no copy data write from org data//~5130I~
	}	//not updated line                                      //~5130I~
	if (!Pplh->ULHdbcs)	//not once displayed                    //~5122I~
    {                                                           //~v014I~
		if (filechktabdbcs(Pplh)==UALLOC_FAILED)//expand data len//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
		pdata=Pplh->ULHdata;//buff may changed(expanded)        //~v014I~
        addlen=Pplh->ULHlen-reclen;                             //~v014R~
        reclen=Pplh->ULHlen;	//expanded len                  //~v014R~
		pc=pdata+reclen;		//buff end,buff may changed     //~v014R~
    }                                                           //~v014I~
	pdbcs=Pplh->ULHdbcs;                                           //~v0clI~
                                                                   //~v0clI~
  if (onnumcidsw)	//cid on spfnum fld                            //~v423I~
  {                                                                //~v423I~
    	netdatalen=Ppfh->UFHspfpos;                                //~v423I~
        cutlen=reclen-netdatalen;	//margin length                //~v423I~
        if (cutlen>0)                                              //~v423I~
        {                                                          //~v423I~
        	reclen-=cutlen;                                        //~v423I~
        	addlen-=cutlen;                                        //~v423I~
        }                                                          //~v423I~
        else                  	//shorter than spfpos              //~v423I~
        	netdatalen=reclen;                                     //~v423I~
  }                                                                //~v423I~
  else 	//not num                                                  //~v423I~
  {                                                                //~v423I~
//  if (reclen>=linecidlen			//can contain cid              //~v0cjR~
//  &&  *(pc-1)==CIDENCLOSER	//last byte of cli                 //~v09FR~
//  &&  !memcmp(pc-postfixlen,postfix,(UINT)postfixlen)//postfix match//~v0cjR~
//  &&  !memcmp(pc-linecidlen,Pcid,2)                              //~v0cjR~
//  &&  memchr(Supdateid,*(pc-postfixlen-1),3))                    //~v0cjR~
//	if (!spfsw)	                                                   //~v0e5R~
  	if (!inmergincidsw)                                              //~v0e5I~
    {                                                              //~v79UI~
    	if (lastcidpos) 					//cid contain          //~v79UI~
		{                                                          //~v79UI~
        	if (filechkcid(0,Ppfh,Pplh,lastcidpos))	//not same cid append//~v79UI~//+v79UR~//~v79UR~
            {                                                      //~v79UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//              *(Pplh->ULHdata+lastcidpos+2)=UCVEBC_CONST(swebcfile,CIDENCLOSER);//reset latest update cid//~va50I~//~va79R~
//              *(Pplh->ULHdata+lastcidpos+2)=UWHICH(swebcfile,CIDENCLOSER_EBC(handle),CIDENCLOSER);//reset latest update cid//~va79I~//+vb30R~
                *(Pplh->ULHdata+lastcidpos+2)=(UCHAR)UWHICH(swebcfile,CIDENCLOSER_EBC(handle),CIDENCLOSER);//reset latest update cid//+vb30I~
#else                                                              //~va50I~
                *(Pplh->ULHdata+lastcidpos+2)=CIDENCLOSER;//reset latest update cid//~v79UR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            	lastcidpos=0;                                      //~v79UI~
            }                                                      //~v79UI~
        }                                                          //~v79UI~
    	if (lastcidpos) 					//cid contain              //~v0cjI~
		{
//cut/expand to move cid to good position                       //~4C23I~
//  		addlen=-linecidlen;		//once cut cid                     //~v09FR~
//  		addlen-=linecidlen;		//once cut cid                     //~v0cjR~
//      	reclen-=linecidlen;                                        //~v0cjR~
        	cutlen=reclen-lastcidpos;                                  //~v0cjR~
    		addlen-=cutlen;		//once cut cid                         //~v0cjI~
        	reclen-=cutlen;                                            //~v0cjI~
    	}                                                           //~4C23I~
    }                                                              //~v79UI~
  }//not cid on spfnumfld                                          //~v423I~
//  gpos=Scidtbl[Ppfh->UFHcidtype-1].CIDTpos;                      //~v09rR~
//  gpos0=                                                         //~v10zR~
//  gpos=Ppfh->UFHcidpos;                                          //~v10zR~
    if ((gpos=Ppfh->UFHcidpos-Psplittotlen)<0)                     //~v10zI~
    	gpos=0;                                                    //~v10zI~
    gpos0=gpos;                                                    //~v10zI~
    skipsw=0;                                                      //~v0clI~
	if (reclen>gpos)                                            //~v014R~
	{                                                           //~4C23R~
//    if (spfsw)                                                   //~v0e5R~
      if (inmergincidsw)                                           //~v0e5I~
      {                                                            //~v0clI~
        addlen=0;                                                  //~v0clI~
        memcpy(Pdata,pdata,(UINT)reclen); //original data          //~v0clI~
        memcpy(Pdbcs,pdbcs,(UINT)reclen); //original data          //~v0clI~
      	if (netdatalen>gpos0)                                      //~v0clI~
            skipsw=1;	//no cid set                               //~v0clI~
        else                                                       //~v0clI~
            if (lastcidpos)                                        //~v0clI~
	        {                                                      //~v0clI~
    	        cutlen=lastcidpos+linecidlen-netdatalen;           //~v0clR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	    UCVEBC_memset_space(swebcfile,Pdata+netdatalen,(UINT)cutlen);//~va50I~
#else                                                              //~va50I~
        	    memset(Pdata+netdatalen,' ',(UINT)cutlen);         //~v0clR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            	memset(Pdbcs+netdatalen,0,(UINT)cutlen);           //~v0clR~
			}                                                      //~v0clR~
      }//spf file                                                  //~v0clI~
      else                                                         //~v0clI~
      {                                                            //~v0clI~
//  	pos=(int)ustrnrspn(pdata+gpos,Stabspace,(UINT)(reclen-gpos));//~v0a1R~
//  	pos++;                                                     //~v0a1R~
//  	gpos+=pos;		//cid set pos                              //~v0a1R~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
      if (swebcfile)                                               //~va50I~
    	pos=(int)ucvebc_umemrspnc(0,pdata+gpos,XEUTF_PC2PCD(Pplh->ULHdbcs,pdata+gpos,Pplh->ULHdata),CHAR_EBC_SPACE,reclen-gpos);//~va50R~
      else                                                         //~va50I~
    #endif                                                         //~va50I~
    	pos=(int)UTF_umemrspn(swutf8file,pdata+gpos,XEUTF_PC2PCD(Pplh->ULHdbcs,pdata+gpos,Pplh->ULHdata),Stabspace,reclen-gpos);//~va20R~
#else                                                              //~va20I~
    	pos=(int)umemrspn(pdata+gpos,Stabspace,(UINT)(reclen-gpos));//~v0a1I~
#endif                                                             //~va20I~
    	gpos=reclen-pos;//cid set pos                              //~v0a1I~
//        if (UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN)   //mergin specified//~v0e5R~
//        &&  reclen==Pplh->ULHlen    //not cid once dropped       //~v0e5R~
//        &&  gpos!=gpos0)       //data on gpos area               //~v0e5R~
//        {                                                        //~v0e5R~
////          return 0;                                            //~v0e5R~
//            addlen=0;                                            //~v0e5R~
//            skipsw=1;                                            //~v0e5R~
//            memcpy(Pdata,pdata,(UINT)reclen); //original data    //~v0e5R~
//            memcpy(Pdbcs,Pplh->ULHdbcs,(UINT)reclen); //original data//~v0e5R~
//        }                                                        //~v0e5R~
//        else                                                     //~v0e5R~
//        {                                                        //~v0e5R~
		addlen+=gpos-reclen+linecidlen;                            //~v09FR~
		memcpy(Pdata,pdata,(UINT)gpos);	//original data
		memcpy(Pdbcs,Pplh->ULHdbcs,(UINT)gpos);	//original data
		memset(Pdbcs+gpos,0,(UINT)linecidlen);	//expanded         //~v09FR~
//        }                                                        //~v0e5R~
      }//spf or else                                               //~v0clI~
	}
//gpos over netdatalen(cid on numfld case is contained)            //~v423I~
	else                                                        //~4C23R~
	{                                                          //~4C17R~
		addlen+=gpos-reclen+linecidlen;	//expanded len             //~v09FR~
		memcpy(Pdata,pdata,(UINT)reclen);	//original data     //~v014R~
		memcpy(Pdbcs,Pplh->ULHdbcs,(UINT)reclen);	//original data//~v014R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		UCVEBC_memset_space(swebcfile,Pdata+reclen,(UINT)(gpos-reclen));//~va50I~
#else                                                              //~va50I~
		memset(Pdata+reclen,' ',(UINT)(gpos-reclen));           //~v014R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		memset(Pdbcs+reclen,0,(UINT)(gpos-reclen+linecidlen));	//expanded//~v09FR~
	}                                                           //~4C23R~
  if (!skipsw)                                                     //~v0clI~
  {                                                                //~v0clI~
//  if (gpos+linecidlen>MAXLINEDATA)	//overflow                 //~v0bbR~
    if (gpos+linecidlen>GFILEBUFFSZ)	//overflow                 //~v0bbI~
		addlen-=linecidlen;                                        //~v09FR~
	else                                                        //~5107I~
	{                                                           //~5107I~
//  	strcpy(pc=Pdata+gpos,Pcid);                                //~v0clR~
    	memcpy(pc=Pdata+gpos,Pcid,(UINT)linecidlen);               //~v0clI~
		if (UCBITCHK(Pplh->ULHflag2,ULHF2INSERT))               //~5131I~
        {                                                          //~v71ZI~
			if (UCBITCHK(Pplh->ULHflag,ULHFMOVE))               //~5131I~
				*(pc+7)='M';	//moved and not updated         //~5131I~
			else                                                //~5131I~
				*(pc+7)='I';	//inserted or updated after move//~5131R~
        }                                                          //~v71ZI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		if (swebcfile)                                             //~va50I~
        {                                                          //~va50I~
//  		ucvebc_a2bfld(0,pc,0,linecidlen);  //cv to ebc in the place//~va50R~//~va79R~
    		ucvebc_a2bfld(0,handle,pc,0,linecidlen);  //cv to ebc in the place//~va79I~
#ifdef AAA	//not fix but use A2B                                  //~va50R~
            if (linecidlen>=LINECIDLEN)	//contains is encloser     //~va50R~
	    		*(pc+LINECIDLEN-1)=CIDENCLOSER_EBC;	//"~" codepoint is not fixed on EBC//~va50R~
#endif                                                             //~va50I~
        }                                                          //~va50I~
#endif                                                             //~va50I~
                                                                   //~va50I~
	}                                                           //~5107I~
  }//!skipsw                                                       //~v0clI~
//    if (UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK)) //num cid ok     //~v0czR~
//    {                                                            //~v0czR~
//        reclen=Pplh->ULHlen;    //save over filesetspfnum        //~v0czR~
//        Pplh->ULHlen+=addlen;                                    //~v0czR~
//        addlen+=filesetspfnum(Ppfh,Pplh,Pdata,Pdbcs,0);//ver from pfh//~v0czR~
//        Pplh->ULHlen=reclen;    //save over filesetspfnum        //~v0czR~
//    }                                                            //~v0czR~
	*Paddlen=addlen;
	return 1;
}//filesetcid
                                                              //~4C17I~
//************************************************************//~4C17I~
// filecidlrecl                                                 //~5130R~
//*get lrecl excepted cid(in mergin if mergin specified)           //~v0c8R~
//*parm1:plh                                                  //~4C17I~
//*parm2:pfh                                                    //~5225R~
//*return:lrecl except cid and preceding space                  //~5130R~
//************************************************************//~4C17I~
int  filecidlrecl(PULINEH Pplh,PUFILEH Ppfh)                    //~5225R~
{                                                             //~4C17I~
	int len;                                                    //~5130R~
	int len0;                                                      //~v0efI~
	int linecidlen;                                                //~v0cjR~
//    int postfixlen;                                              //~v0cjI~
	UCHAR *pc;                                                  //~5225R~
//  UCHAR *pc2,*pc0;    //last cid pos from endpos                 //~v0c8R~
    UCHAR *pc0;    //last cid pos from endpos                      //~v0c8I~
//    UCHAR *postfix;                                              //~v0cjR~
    int mergin;                                                    //~v0c8R~
    int cidpos0;                                                   //~v0c8I~
//  int lastpos;                                                   //~v0clR~
    int contlen;                                                   //~v0clI~
    int spfsw;                                                     //~v0czI~
    int spfsw2;                                                    //~v0edR~
    int spfsw3=0;                                                    //~v0efI~//~vaf9R~
    int cidinmerginsw;                                             //~v0edI~
    int onnumcidsw;                                                //~v427I~
    int cidoomsw;                                                  //~v0ejI~
    int merginsw;                                                  //~v0ejI~
    int contsw;                                                    //~v0efI~
#ifdef UTF8UCS2                                                    //~va20I~
	UCHAR *pcd,*pcd0;                                              //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	int handle;                                                    //~va79I~
//*****************************                               //~4C17I~
    Stopcidpos=0;  //parm to filegetcidlen                         //~v0c8R~
    Slastcidpos=0;  //parm to filegetcidlen                        //~v0ccI~
    Scopylen=0;      //cont data exist sw                          //~v0efR~
    pc0=Pplh->ULHdata;	//top                                      //~v0c8I~
#ifdef UTF8UCS2                                                    //~va20I~
    pcd0=pcd=Pplh->ULHdbcs;	//top                                  //~va20I~
    swutf8file=FILEUTF8MODE(Ppfh);                                 //~va20I~
#endif                                                             //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PFH_ISEBC(Ppfh);                                     //~va50I~
    handle=Ppfh->UFHhandle;                                        //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    len0=                                                          //~v0efI~
	len=Pplh->ULHlen;                                            //~4C17I~
UTRACED("cidlrecl inp data",pc0,len0);                             //~va50I~
UTRACEDIFNZ("cidlrecl inp dbcs",pcd0,len0);                        //~va50R~
	linecidlen=Ppfh->UFHcidlen;                                    //~v09FI~
	mergin=Ppfh->UFHmergin;                                        //~v0czM~
    cidpos0=Ppfh->UFHcidpos;                                       //~v0edM~
  	spfsw=UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK);                  //~v0czI~
  	spfsw2=UCBITCHK(Ppfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);  //~v0edR~
    merginsw=UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN);                 //~v0ejR~
    cidinmerginsw=(merginsw && cidpos0<mergin);                    //~v0ejI~
    cidoomsw=(merginsw && cidpos0>=mergin && !Slrecl2sw);          //~v0ejI~
    onnumcidsw=(UCBITCHK(Ppfh->UFHflag2,UFHF2MERGINCID)            //~v427I~
                  && Ppfh->UFHspfpos); //cid on numfld             //~v427I~
  	if (onnumcidsw)   //cid on clo72                               //~v427I~
  	{                                                              //~v427I~
        Scopylen=min(mergin,len);                                  //~v427I~
#ifdef UTF8UCS2                                                    //~va20I~
//*UFHF2MERGINCID is on not for EN by for EC(COB with cid at col 73-80(8byte cid))//~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//*pcd is optional for ebc file                                    //~va50I~
        Scopylen-=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,Scopylen);	//net date in margin//~va50I~
#else                                                              //~va50I~
        Scopylen-=(int)UTF_umemrspnc(swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,' ',Scopylen);	//net date in margin//~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#else                                                              //~va20I~
        Scopylen-=(int)umemrspnc(Pplh->ULHdata,' ',(UINT)Scopylen);	//net date in margin//~v427I~
#endif                                                             //~va20I~
        Scidchklen=mergin+linecidlen;                              //~v427I~
#ifdef UTF8UCS2                                                    //~va20I~
		if (pcd0)	//dbcs is always set for utf8 file             //~va20I~
        	pcd=pcd0+mergin;                                       //~va20I~
#endif                                                             //~va20I~
        if (len>=Scidchklen                                        //~v427R~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	    && UWHICH(swebcfile,                                       //~va50I~
//  				fileiscid_ebc(Ppfh->UFHcidebc,pc0+mergin,linecidlen),//~va50I~//~va79R~
    				fileiscid_ebc(handle,Ppfh->UFHcidebc,pc0+mergin,linecidlen),//~va79I~
					fileiscid(Ppfh->UFHcid,pc0+mergin,pcd,linecidlen)//~va50I~
                 )                                                 //~va50I~
        )                                                          //~va50I~
#else                                                              //~va50I~
	    && fileiscid(Ppfh->UFHcid,pc0+mergin,pcd,linecidlen))      //~va20I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#else                                                              //~va20I~
	    && fileiscid(Ppfh->UFHcid,pc0+mergin,linecidlen))          //~v427I~
#endif                                                             //~va20I~
            Stopcidpos=Slastcidpos=mergin;                         //~v427I~
        return Scopylen;                                           //~v427I~
  	}                                                              //~v427I~
    if (!linecidlen)		//no cid file                          //~v0clI~
    {                                                              //~v0czI~
    	if (spfsw                                                  //~v0czI~
      	||  Slrecl3sw)        //drop traler space                  //~v0czR~
      	{                                                          //~v0czR~
	    	if (UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN)               //~v0czR~
	    	&&  len>mergin)		                                   //~v0czR~
        		len=mergin;                                        //~v0czR~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	len-=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,len);//~va50R~
#else                                                              //~va50I~
        	len-=(int)UTF_umemrspnc(swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,' ',len);//~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#else                                                              //~va20I~
        	len-=(int)umemrspnc(Pplh->ULHdata,' ',(UINT)len);      //~v0czR~
#endif                                                             //~va20I~
      	}                                                          //~v0czR~
        else                                                       //~v71ZI~
        if (Sjoinsw)                                               //~v71ZI~
        {                                                          //~v71ZI~
	    	if (UCBITCHK(Ppfh->UFHflag7,UFHF7FIXLRECL))            //~v71ZI~
#ifdef UTF8UCS2                                                    //~va20I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    	    	len-=(int)UCVEBCUTF_umemrspnc_space(swebcfile,swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,len);//~va50R~
#else                                                              //~va50I~
    	    	len-=(int)UTF_umemrspnc(swutf8file,Pplh->ULHdata,Pplh->ULHdbcs,' ',len);//~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#else                                                              //~va20I~
    	    	len-=(int)umemrspnc(Pplh->ULHdata,' ',(UINT)len);  //~v71ZI~
#endif                                                             //~va20I~
        }                                                          //~v71ZI~
        Scopylen=len;                                              //~v0efI~
    	return len;                                                //~v0clI~
    }                                                              //~v0czI~
//  contlen=len-(cidpos0+linecidlen);  //cont field exist ?        //~v0e5R~
//	if (spfsw2                                                       //~v0edR~
//	&& (fileisvalidspfline(Ppfh,Pplh,0) || len<=mergin))//no update line spf flag//~v0edR~
  	if ((spfsw2                                                    //~v0edI~
  	     && (spfsw3=(fileisvalidspfline(Ppfh,Pplh,0) || len<=mergin))!=0)//no update line spf flag//~v0efR~
  	|| (cidinmerginsw && !Slrecl2sw))	//not req search from last //~v0edR~
  	{                                                                //~v0clI~
    	if (len>mergin)                                                //~v0clI~
        	len=mergin;    //end addr                                  //~v0clI~
    	contlen=len-(cidpos0+linecidlen); //cont field exist ?         //~v0dkR~
    	pc=pc0+len-linecidlen;                                         //~v0clI~
        contsw=0;                                                  //~v0efI~
    	for (;contlen>0;contlen--,pc--,len--)                          //~v0clI~
    	{                                                              //~v0d3I~
#ifdef UTF8UCS2                                                    //~va20I~
			if (pcd0)	//dbcs is always set for utf8 file         //~va20I~
//        		pcd=pcd0+((ULONG)pc-(ULONG)pc0);                   //~va20I~//~vafkR~
        		pcd=pcd0+((ULPTR)pc-(ULPTR)pc0);                   //~vafkI~
#endif                                                             //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50R~
	        if (UWHICH(swebcfile,                                  //~va50I~
//      	    		fileiscid_ebc(Ppfh->UFHcidebc,pc,linecidlen),//~va50R~//~va79R~
        	    		fileiscid_ebc(handle,Ppfh->UFHcidebc,pc,linecidlen),//~va79I~
	    	    		fileiscid(Ppfh->UFHcid,pc,pcd,linecidlen)  //~va50R~
                      )                                            //~va50I~
			)                                                      //~va50R~
	#else                                                          //~va50R~
	    	if (fileiscid(Ppfh->UFHcid,pc,pcd,linecidlen))         //~va20I~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50R~
#else                                                              //~va20I~
	    	if (fileiscid(Ppfh->UFHcid,pc,linecidlen))                 //~v0clI~
#endif                                                             //~va20I~
        		break;                                                 //~v0clI~
//      	if (*(pc+linecidlen-1)) //non space cont line              //~v0e5R~
#ifdef UTF8UCS2                                                    //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        	if (UCVEBCUTF_nespace(swebcfile,swutf8file,*(pc+linecidlen-1),*(pcd+linecidlen-1))) //non space cont line//~va50I~
	#else                                                          //~va50I~
        	if (UTF_nespace(swutf8file,*(pc+linecidlen-1),*(pcd+linecidlen-1))) //non space cont line//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        	if (*(pc+linecidlen-1)!=' ') //non space cont line         //~v0e5I~
#endif                                                             //~va20I~
//          	break;                                                 //~v0dfR~
//          	Scontlen++;  //cont data after cid                 //~v0efR~
            	contsw=1;  //cont data after cid                   //~v0efI~
    	}                                                              //~v0d3I~
        if (spfsw2 && spfsw3)   //spf file, ok or short line       //~v0efR~
        {                                                          //~v0efI~
        	if (contsw) 	//cont detected                        //~v0efR~
				Scopylen=mergin;        //copy with cont fld       //~v0efR~
		}                                                          //~v0efI~
        else                                                       //~v0efI~
            if (len0>mergin)                                       //~v0efR~
            	Scopylen=len0;		//fullcopy                     //~v0efI~
  	}//spf file	                                                   //~v0clI~
//    else                                                         //~v0efR~
//        if (!Slrecl2sw) //not from filecidlrecl2(regardless mergin)//~v0efR~
//            if (UCBITCHK(Ppfh->UFHflag2,UFHF2MERGIN))            //~v0efR~
//            {                                                    //~v0efR~
//                if (cidpos0!=mergin)    //cid in mergin          //~v0efR~
////                  cidpos0+=linecidlen;//cid end addr           //~v0efR~
//                    cidpos0=mergin;//cid end addr                //~v0efR~
//                if (len>cidpos0)                                 //~v0efR~
//                    len=cidpos0;    //end addr                   //~v0efR~
//            }                                                    //~v0efR~
    Scidchklen=len;               //chk length                     //~v0c8I~
//    postfixlen=linecidlen-(LINECIDLEN-1);                        //~v0cjR~
//    postfix=Ppfh->UFHcid+LINECIDLEN-1;                           //~v0cjR~
	pc=Pplh->ULHdata+len-1;                                     //~5130R~
                                                                   //~v0c8I~
//ignore last space,tab                                            //~v0c8I~
#ifdef UTF8UCS2                                                    //~va20I~
    pcd=XEUTF_PC2PCD(pcd0,pc,Pplh->ULHdata);                       //~va20I~
#endif                                                             //~va20I~
    for (;len;len--,pc--)   //search non space                     //~v0c8I~
    {                                                              //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
		pcd--;                                                     //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
        if (UCVEBCUTF_nespacetab(swebcfile,swutf8file,*pc,*(pcd+1)))//~va50I~
	#else                                                          //~va50I~
        if (UTF_nespace(swutf8file,*pc,*(pcd+1)) && UTF_ne(swutf8file,*pc,*(pcd+1),TABCHAR))//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
        if (*pc!=' ' && *pc!=TABCHAR)                              //~v0c8I~
#endif                                                             //~va20I~
            break;                                                 //~v0c8I~
                                                                   //~va20I~
    }                                                              //~va20I~
                                                                   //~v0c8I~
#ifdef UTF8UCS2                                                    //~va20I~
			if (pcd0)	//dbcs is always set for utf8 file         //~va20I~
//        		pcd=pcd0+((ULONG)pc-(ULONG)pc0)-linecidlen+1;      //~va20R~//~vafkR~
        		pcd=pcd0+((ULPTR)pc-(ULPTR)pc0)-linecidlen+1;      //~vafkI~
#endif                                                             //~va20I~
	while (len>=linecidlen   	//can contain cid                  //~v09FR~
//  &&  !memcmp(pc-linecidlen+1,Ppfh->UFHcid,2)                    //~v0cjR~
//  &&  memchr(Supdateid,*(pc-1),3)                                //~v09FR~
//  &&  memchr(Supdateid,*(pc-postfixlen),3)                       //~v0cjR~
//  &&  *pc==CIDENCLOSER)	//already cid                          //~v09FR~
//  &&  !memcmp(pc-postfixlen+1,postfix,(UINT)postfixlen))//postfix match//~v0cjR~
#ifdef UTF8UCS2                                                    //~va20I~
  #ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
	&& UWHICH(swebcfile,                                           //~va50I~
//  	fileiscid_ebc(Ppfh->UFHcidebc,pc-linecidlen+1,linecidlen),//postfix match//~va50I~//~va79R~
    	fileiscid_ebc(handle,Ppfh->UFHcidebc,pc-linecidlen+1,linecidlen),//postfix match//~va79I~
        (pcd=(pcd0 ? XEUTF_PC2PCD(pcd0,pc-linecidlen+1,pc0) : 0),  //~va50I~
			fileiscid(Ppfh->UFHcid,pc-linecidlen+1,pcd,linecidlen))//postfix match//~va50I~
             )                                                     //~va50I~
        )                                                          //~va50I~
  #else                                                            //~va50I~
    &&  (pcd=(pcd0 ? XEUTF_PC2PCD(pcd0,pc-linecidlen+1,pc0) : 0),  //~va20R~
			fileiscid(Ppfh->UFHcid,pc-linecidlen+1,pcd,linecidlen))//postfix match//~va20R~
        )                                                          //~va20I~
  #endif                                                           //~va50I~
#else                                                              //~va20I~
    &&  fileiscid(Ppfh->UFHcid,pc-linecidlen+1,linecidlen))//postfix match//~v0cjR~
#endif                                                             //~va20I~
	{                                                           //~4C17I~
    	if (cidoomsw)                                              //~v0ejI~
        	if (len-linecidlen<mergin)                             //~v0ejI~
            	break;                                             //~v0ejI~
		len-=linecidlen;		//cut previous cid                 //~v09FR~
		pc-=linecidlen;      //space search start                  //~v09FR~
//	    Stopcidpos=(int)((ULONG)(pc+1)-(ULONG)pc0);    //output to filegetcidlen//~v0c8R~//~vafkR~
	    Stopcidpos=(int)((ULPTR)(pc+1)-(ULPTR)pc0);    //output to filegetcidlen//~vafkI~
	    if (!Slastcidpos)                                          //~v0ccI~
			Slastcidpos=Stopcidpos;                                //~v0ccI~
#ifdef UTF8UCS2                                                    //~va20I~
    pcd=XEUTF_PC2PCD(pcd0,pc,pc0);                                 //~va20R~
#endif                                                             //~va20I~
        for (;len;len--,pc--)	//search non space              //~4C17I~
        {                                                          //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
			pcd--;                                                 //~va20I~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
         	if (UCVEBCUTF_nespacetab(swebcfile,swutf8file,*pc,*(pcd+1)))//~va50R~
    #else                                                          //~va50I~
         	if (UTF_nespace(swutf8file,*pc,*(pcd+1)) && UTF_ne(swutf8file,*pc,*(pcd+1),TABCHAR))//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20I~
         	if (*pc!=' ' && *pc!=TABCHAR)                       //~5225R~
#endif                                                             //~va20I~
				break;                                        //~4C17I~
        }                                                          //~va20I~
	}                                                       //~4C17I~
    if (!Scopylen)                                                 //~v0efI~
    	Scopylen=len;                                              //~v0efI~
	return len;                                                 //~5130I~
}//filecidlrecl                                                 //~5130R~
                                                                //~5225I~
//************************************************************     //~v0c8R~
// filegetcidlen                                                   //~v0c8R~
//*get last cidpos (in mergin if mergin specified)                 //~v0c8R~
//*parm1:plh                                                       //~v0c8R~
//*parm2:pfh                                                       //~v0c8R~
//*parm3:optional output cidlrecl                                  //~v0c8R~
//*parm4:optional output top cid pos                               //~v0c8I~
//*parm5:optional output last cid pos                              //~v0ccI~
//*return:cidlen                                                   //~v0c8R~
//************************************************************     //~v0c8R~
int  filegetcidlen(PULINEH Pplh,PUFILEH Ppfh,int *Plrecl,int *Ptopcidpos,int *Plastcidpos)//~v0ccR~
{                                                                  //~v0c8R~
    int lrecl;                                                     //~v0c8R~
    int cidlen;                                                    //~v0c8I~
//*****************************                                    //~v0c8R~
    lrecl=filecidlrecl(Pplh,Ppfh);                                 //~v0c8R~
    if (Plrecl)                                                    //~v0c8R~
        *Plrecl=lrecl;                                             //~v0c8R~
    if (Ptopcidpos)                                                //~v0ccR~
        *Ptopcidpos=Stopcidpos;                                    //~v0ccR~
    if (Plastcidpos)                                               //~v0ccI~
        *Plastcidpos=Slastcidpos;                                  //~v0ccI~
	if (Stopcidpos)                                                //~v0c8I~
    	cidlen=Scidchklen-Stopcidpos;                              //~v0c8R~
	else                                                           //~v0c8I~
    	cidlen=0;                                                  //~v0c8I~
    return cidlen;                                                 //~v0c8R~
}//filegetcidlen                                                   //~v0c8R~
                                                                   //~v0cbI~
//************************************************************     //~v0cbI~
// filecidlrecl2                                                   //~v0cbI~
//*get lrecl excepted cid from end of record ignoreing mergin      //~v0cbI~
//*parm1:plh                                                       //~v0cbI~
//*parm2:pfh                                                       //~v0cbI~
//*return:lrecl except cid and preceding space                     //~v0cbI~
//************************************************************     //~v0cbI~
int  filecidlrecl2(PULINEH Pplh,PUFILEH Ppfh)                      //~v0cbI~
{                                                                  //~v0cbI~
	int netlen;                                                    //~v0cbI~
//*****************************                                    //~v0cbI~
    Slrecl2sw=1;                                                   //~v0cbI~
    Sjoinsw=1;                                                     //~v71ZI~
    netlen=filecidlrecl(Pplh,Ppfh);                                //~v0cbR~
    Slrecl2sw=0;                                                   //~v0cbI~
    Sjoinsw=0;                                                     //~v71ZI~
    return netlen;                                                 //~v0cbI~
}//filecidlrecl2                                                   //~v0cbI~
                                                                   //~v0cbI~
//************************************************************     //~v0cbI~
// filegetcidlen2                                                  //~v0cbI~
//*get last cidpos (from end regardless mergin specification)      //~v0cbI~
//*parm1:plh                                                       //~v0cbI~
//*parm2:pfh                                                       //~v0cbI~
//*parm3:optional output cidlrecl                                  //~v0cbI~
//*parm4:optional output top  cid pos                              //~v0ccR~
//*parm5:optional output last cid pos                              //~v0ccI~
//*return:cidlen                                                   //~v0cbI~
//************************************************************     //~v0cbI~
int  filegetcidlen2(PULINEH Pplh,PUFILEH Ppfh,int *Plrecl,int *Ptopcidpos,int *Plastcidpos)//~v0ccR~
{                                                                  //~v0cbI~
	int cidlen;                                                    //~v0cbI~
//*****************************                                    //~v0cbI~
    Slrecl2sw=1;                                                   //~v0cbI~
	cidlen=filegetcidlen(Pplh,Ppfh,Plrecl,Ptopcidpos,Plastcidpos); //~v0ccR~
    Slrecl2sw=0;                                                   //~v0cbI~
    return cidlen;                                                 //~v0cbI~
}//filegetcidlen2                                                  //~v0cbI~
                                                                   //~v0cbI~
//************************************************************     //~v0efI~
// filegetcidlenc                                                  //~v0efI~
//*return copylen additional to filegetcidlen                      //~v0efI~
//*parm1:plh                                                       //~v0efI~
//*parm2:pfh                                                       //~v0efI~
//*parm3:optional output cidlrecl                                  //~v0efI~
//*parm4:optional output top  cid pos                              //~v0efI~
//*parm5:optional output last cid pos                              //~v0efI~
//*parm6:optional output copy len                                  //~v0efI~
//*return:cidlen                                                   //~v0efI~
//************************************************************     //~v0efI~
int  filegetcidlenc(PULINEH Pplh,PUFILEH Ppfh,int *Plrecl,int *Ptopcidpos,int *Plastcidpos,//~v0efI~
					int *Pcopylen)                                 //~v0efI~
{                                                                  //~v0efI~
	int cidlen;                                                    //~v0efI~
//*****************************                                    //~v0efI~
	cidlen=filegetcidlen(Pplh,Ppfh,Plrecl,Ptopcidpos,Plastcidpos); //~v0efI~
    if (Pcopylen)                                                  //~v0efI~
    	*Pcopylen=Scopylen;                                        //~v0efI~
    return cidlen;                                                 //~v0efI~
}//filegetcidlenc                                                  //~v0efI~
                                                                   //~v0efI~
//************************************************************     //~v0czI~
// filecidlrecl3                                                   //~v0czI~
//*same as filecidlrecl except ignore last space when no cid file  //~v0czI~
//*parm1:plh                                                       //~v0czI~
//*parm2:pfh                                                       //~v0czI~
//*return:lrecl except cid and preceding space                     //~v0czI~
//************************************************************     //~v0czI~
int  filecidlrecl3(PULINEH Pplh,PUFILEH Ppfh)                      //~v0czI~
{                                                                  //~v0czI~
	int netlen;                                                    //~v0czI~
//*****************************                                    //~v0czI~
    Slrecl3sw=1;                                                   //~v0czI~
    netlen=filecidlrecl(Pplh,Ppfh);                                //~v0czI~
    Slrecl3sw=0;                                                   //~v0czI~
    return netlen;                                                 //~v0czI~
}//filecidlrecl3                                                   //~v0czI~
                                                                   //~v0czI~
//************************************************************  //~5308I~
// filecidtypechk                                               //~5308I~
//*clear all line cid                                           //~5308I~
//*parm1:type string                                            //~5308I~
//*parm2:alias option 0:no chk alias,but chk prefix                //~v09FR~
//                    1:allow alias(chk all extention list)        //~v09FI~
//*return:cidtbl addr or 0                                         //~v09rR~
//************************************************************  //~5308I~
//int filecidtypechk(UCHAR *Ptype,int Palias)                      //~v09rR~
CIDTBL *filecidtypechk(UCHAR *Ptype,int Palias)                    //~v09rI~
{                                                               //~5308I~
	int extno=0,ii;                                               //~5528R~//~vaf9R~
	CIDTBL *pcidtbl;                                            //~5308I~
//*****************************                                 //~5308I~
	for (pcidtbl=Scidtbl,ii=0;ii<MAXCIDTBL;pcidtbl++,ii++)      //~5528R~
    	if (pcidtbl->CIDTid)	//defined                       //~5528I~
	 		if (extno=wordtblisrch(Ptype,pcidtbl->CIDTexttbl),extno)//~5528R~
    	    	break;                                          //~5528R~
                                                                //~5308I~
	if (!extno 					//not found                     //~5308I~
	||  (!Palias && extno!=1))	//req no alias but found alias     //~v414R~
    {                                                              //~v09FI~
    	if (!Palias)			//no alias chk                     //~v09FI~
        	return filecidprefixchk(Ptype);	//defined prefix?      //~v09FI~
    	return 0;				//err                           //~5308I~
    }                                                              //~v09FI~
//  return pcidtbl->CIDTid;                                        //~v09rR~
    return pcidtbl;                                                //~v09rI~
}//filecidtypechk

//************************************************************     //~v09FI~
// filecidprefixchk                                                //~v09FI~
// chk prefix for CID                                              //~v09FI~
//*parm1:prefix string                                             //~v09FI~
//*return:cidtbl addr or 0                                         //~v09FI~
//************************************************************     //~v09FI~
CIDTBL *filecidprefixchk(UCHAR *Pprefix)                           //~v09FR~
{                                                                  //~v09FI~
	int ii;                                                        //~v09FI~
	CIDTBL *pcidtbl;                                               //~v09FI~
//*****************************                                    //~v09FI~
	for (pcidtbl=Scidtbl,ii=0;ii<MAXCIDTBL;pcidtbl++,ii++)         //~v09FI~
		if (pcidtbl->CIDTid)	//defined                          //~v09FI~
	 		if (!memcmp(pcidtbl->CIDTcidfmt,Pprefix,LINEPREFIXLEN))	//defined//~v09FR~
	    		return pcidtbl;                                    //~v09FI~
	return 0;//err                                                 //~v09FI~
}//filecidprefixchk                                                //~v09FR~
//************************************************************
// filegetcidtype
//*parm1:pfh
//*return:cid type string
//************************************************************
UCHAR *filegetcidtype(PUFILEH Ppfh)
{
static UCHAR Scidtyp[3+1+2+1];    //ext,postfix                    //~v09FI~
//*****************************
    if (Ppfh->UFHcidtype==UFHCIDTYPEERR)
    	return "NOT DEFINED";
//  return Scidtbl[(int)Ppfh->UFHcidtype-1].CIDTexttbl;            //~v09FR~
	strcpy(Scidtyp,Scidtbl[(int)Ppfh->UFHcidtype-1].CIDTexttbl);   //~v09FI~
//  if (Ppfh->UFHcidlen!=LINECIDLEN)	//has postfix              //~v0cjR~
    if (Ppfh->UFHcidlen>LINECIDLEN)	//has postfix                  //~v0cjI~
    {                                                              //~v09FI~
    	strcat(Scidtyp,",");                                       //~v09FI~
    	strcat(Scidtyp,Ppfh->UFHcid+LINECIDLEN);                   //~v09FI~
    }                                                              //~v09FI~
    return Scidtyp;                                                //~v09FI~
}//filegetcidtype
                                                                   //~v0clI~
//************************************************************     //~v0clM~
// filechkcidfmt                                                   //~v0clM~
//*parm1:cid format                                                //~v0clM~
//*parm2:cid to be chk                                             //~v0clM~
//*parm3:cid len                                                   //~v0clM~
//*return:3rd byte of cid('+'/'-') or 0 if not cid                 //~v0clM~
//************************************************************     //~v0clM~
#ifdef UTF8UCS2                                                    //~va20I~
int fileiscid(char *Pcidfmt,char *Pcid,char *Pdbcs,int Pcidlen)    //~va20I~
#else                                                              //~va20I~
int fileiscid(char *Pcidfmt,char *Pcid,int Pcidlen)                //~v0clM~
#endif                                                             //~va20I~
{                                                                  //~v0clM~
	int postfixlen;                                                //~v0clM~
//*****************************                                    //~v0clM~
#ifdef UTF8UCS2                                                    //~va20I~
	if (Pdbcs && utfchkdd(0,Pdbcs,Pcidlen))	//utf8 encoded cid is not allowed//~va20R~
    	return 0;                                                  //~va20I~
#endif                                                             //~va20M~
	if (memcmp(Pcid,Pcidfmt,2))	//top 2 byte                       //~v0clM~
    	return 0;                                                  //~v0clM~
    if (*(Pcid+2)!=CIDENCLOSER                                     //~v0clM~
    &&  *(Pcid+2)!=CIDCURUPDATE)                                   //~v0clM~
        return 0;                                                  //~v0clM~
//*Pcid is confirmed as ascii                                      //~va20I~
	if (!memchr(Supdateid,*(Pcid+LINECIDLEN-2),3))	//update id RIM//~v0clM~
    	return 0;                                                  //~v0clM~
	if (Pcidlen<LINECIDLEN)		//8 byte cid                       //~v0clM~
    	return -1;                                                 //~v0clM~
    if (*(Pcid+LINECIDLEN-1)!=CIDENCLOSER)                         //~v0clM~
        return 0;                                                  //~v0clM~
    if ((postfixlen=Pcidlen-LINECIDLEN)>0)                         //~v0clM~
        if (memcmp(Pcid+LINECIDLEN,Pcidfmt+LINECIDLEN,(UINT)postfixlen))//postfix unmatch//~v0clM~
            return 0;                                              //~v0clM~
	return 1;                                                      //~v0clM~
}//fileiscid                                                       //~v0clM~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//************************************************************     //~va50I~
// fileiscid_ebc                                                   //~va50I~
//************************************************************     //~va50I~
//int fileiscid_ebc(char *Pcidfmt,char *Pcid,int Pcidlen)            //~va50I~//~va79R~
int fileiscid_ebc(int Phandle,char *Pcidfmt,char *Pcid,int Pcidlen)//~va79I~
{                                                                  //~va50I~
	int postfixlen;                                                //~va50I~
//*****************************                                    //~va50I~
	if (memcmp(Pcid,Pcidfmt,2))	//top 2 byte                       //~va50I~
    	return 0;                                                  //~va50I~
//  if (*(Pcid+2)!=CIDENCLOSER_EBC                                 //~va50I~//~va79R~
//  &&  *(Pcid+2)!=CIDCURUPDATE_EBC)                               //~va50I~//~va79R~
    if (*(Pcid+2)!=CIDENCLOSER_EBC(Phandle)                        //~va79I~
    &&  *(Pcid+2)!=CIDCURUPDATE_EBC(Phandle))                      //~va79I~
        return 0;                                                  //~va50I~
//*Pcid is confirmed as ascii                                      //~va50I~
	if (!memchr(Supdateid_ebc,*(Pcid+LINECIDLEN-2),3))	//update id RIM//~va50I~
    	return 0;                                                  //~va50I~
	if (Pcidlen<LINECIDLEN)		//8 byte cid                       //~va50I~
    	return -1;                                                 //~va50I~
//  if (*(Pcid+LINECIDLEN-1)!=CIDENCLOSER_EBC)                     //~va50I~//~va79R~
    if (*(Pcid+LINECIDLEN-1)!=CIDENCLOSER_EBC(Phandle))            //~va79I~
        return 0;                                                  //~va50I~
    if ((postfixlen=Pcidlen-LINECIDLEN)>0)                         //~va50I~
        if (memcmp(Pcid+LINECIDLEN,Pcidfmt+LINECIDLEN,(UINT)postfixlen))//postfix unmatch//~va50I~
            return 0;                                              //~va50I~
	return 1;                                                      //~va50I~
}//fileiscid_ebd                                                   //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//************************************************************     //~v79UI~
// filechkcid                                                      //~v79UI~
// chk cid is same as current(prefix/postfiex is already checked validity)//~v79UI~
//*return:0:same,1:not same                                        //~v79UI~//~v79UR~
//************************************************************     //~v79UI~
int filechkcid(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Pcidpos)     //~v79UI~
{                                                                  //~v79UI~
	int rc;                                                        //~v79UI~
	CHAR *pc;                                                      //~v79UI~
#ifdef UTF8UCS2                                                    //~va20I~
	UCHAR *pcd;                                                    //~va20I~
#endif                                                             //~va20I~
//*****************************                                    //~v79UI~
    if (UCBITCHK(Ppfh->UFHflag9,UFHF9CIDAPPENDN))//not append mode //~v79UI~
    	return 0;                                                  //~v79UI~
    if (!UCBITCHK(Gopt5,GOPT5CIDAPPEND)   //not append mode        //~v79UR~
    &&  !UCBITCHK(Ppfh->UFHflag9,UFHF9CIDAPPEND))//not append mode //~v79UR~
    	return 0;                                                  //~v79UI~
	pc=Pplh->ULHdata+Pcidpos+3;         // xxxx of //+xxxxR~ fmt   //~v79UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (PFH_ISEBC(Ppfh))                                             //~va50R~
  {                                                                //~va50I~
    if (UCBITCHK(Ppfh->UFHflag2,UFHF2FIXEDCID))	//not date fmt     //~va50I~
    	rc=memcmp(Ppfh->UFHcidebc+3,pc,4)!=0;                      //~va50I~
    else                                                           //~va50I~
    	rc=memcmp(Sdatecid_ebc+1,pc,4)!=0;                         //~va50I~
  }                                                                //~va50I~
  else                                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
  {//!ebc                                                          //~va50I~
#ifdef UTF8UCS2                                                    //~va20I~
	pcd=Pplh->ULHdbcs;                                             //~va20I~
    if (pcd)                                                       //~va20I~
    {                                                              //~va20I~
		pcd+=Pcidpos+3;         // xxxx of //+xxxxR~ fmt           //~va20I~
		if (utfchkdd(0,pcd,4))	//utf8 encoded cid is not allowed  //~va20I~
        	return 1;                                              //~va20I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
    if (UCBITCHK(Ppfh->UFHflag2,UFHF2FIXEDCID))	//not date fmt     //~v79UI~
    	rc=memcmp(Ppfh->UFHcid+3,pc,4)!=0;                           //~v79UI~//~v79UR~
    else                                                           //~v79UI~
    	rc=memcmp(Sdatecid+1,pc,4)!=0;                                 //~v79UR~//~v79UR~
  }//!ebc                                                          //~va50I~
	return rc;                                                     //~v79UI~
}//filechkcid                                                      //~v79UI~
