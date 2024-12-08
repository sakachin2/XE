//*CID://+vb85R~:                             update#=  227;       //+vb85R~
//*************************************************************
//*xeundo.c*                                                    //~v04dR~
//**undo
//*************************************************************
//vb85:170216 (BUG)plh remains on UFHcmdline with ULHFCMDLINE on. and cuse lcmd error//~vb85I~
//vb2E:160229 LNX64 compiler warning                               //~vb2EI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vb23:160110 (BUG)mixuse of ULHFCURCAP(0x40) and ULHF4REPRENUM(0x40)//~va23I~
//            1).A+m(cap move) on spf file;ULHflag ULHF4REPRENUM(=ULHFCURCAP) on//~va23I~
//            2).char update on the line;UUHFREPRENUM on           //~va23I~
//            3)S+F1(undo);ULHF4REPRENUM on because UUHFREPRENUM on//~va23I~
//            4)save spf file;spf number field was not renumbered  //~va23I~
//vak5:130816 compiler warning;set but not used                    //~vak5I~
//vagx:120915 (BUG)re-appear unchained plhlinecmd when undo->redo of inserted line with line cmd//~vagxI~
//vagh:120824 REDO test on also Linux                              //~vaghI~
//vag3:120814 (BUG)"renum f" loose line spf err when undo          //~vag3I~
//vag2:120811 REDo suupport                                        //~vag2I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va36:100203 (BUG)can not save to itself if file update was whole undoed after once saved//~va36I~
//v9@8:080717 3270:fs mode del excluded line                       //~v9@8I~
//v78S:080606 continuede insert line mode by lcmd "i"              //~v78SI~
//v78y:080413 performance down by v74r("del x all" is slow)        //~v78yI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v761:070529 split tail cmd:del continued line if all space       //~v761I~
//v74r:070220 (BUG)undo csr line positioning invalid at undo confirmation//~v74rI~
//            C&P region paste generate Ins & Del undosdata in the same undoctr.//~v74rI~
//            postion to inserted line by splitline is deleted by last join operation.//~v74rI~
//v724:061118 (BUG)ABEND by join lcmd;access of deleted line cause ABEND//~v724R~
//v71Z:061114 v71Y miss set version number in the following case   //~v71ZI~
//            for SPF err file opened by en,update then "renum force" because SPFNUMOK set by renum at undo.//~v71ZI~
//v650:050710 (BUG)cap data not saved because upctr is not upped   //~v650I~
//v58d:040828 del v58c;no undo data is compiled more by v585       //~v58cI~
//v58c:040828 undo cmd:cb option to close undo file                //~v58cR~
//v585:040823 cap performance up;skip undo data save when clipboard repl//~v585I~
//v57m:040526 (BUG)parmission warining issued for new file;should chk parent dir//~v57mI~
//v55X:040318 (!UNX)update permission warning(read only chk)       //~v55XI~
//v55P:040318 (UNX)update permission warning                       //~v55PI~
//v54R:040125 find cmd:max record pos search by max pos parm       //~v54RI~
//v54H:040121 (BUG)abend undo of insert when del line is cur top of split another scr//~v54HI~
//v51r:030608 undo free option for memory shortage                 //~v51rI~
//v45A:011222 (BUG)not  maintained split flag when split line partialy deleted//~v45AI~
//v45z:011222 same logic CURUPDATE and CURUPDATE for clear reverse(see v45v)//~v45zI~
//v45w:011216 (BUG)setmaxver is thru undoprep so upctr is not updated//~v45wI~
//v45v:011216 (BUG)unpdate line reverse remain after undo the replace//~v45vI~
//            because there is no triger to redraw,3CURUPDATE flag is already reset//~v45vI~
//            3CURUPDATE set when lhupctr=fhupctr and reset when lhupctr!=fhupctr//~v45vI~
//            with setting fdraw flag;not requierd when undo prepare//~v45vI~
//            it is draw time condition.                           //~v45vI~
//v45u:011216 num cutoff cmd to split continued line               //~v45uI~
//v42t:011009 keep COB status over num clear                       //~v42tI~
//v42s:011009 NOAUTONUM status should not be changed by num clear cmd.//~v42rI~
//v42r:011009 (BUG)num clear ignored at save                       //~v42iI~
//v42i:011002 set spfnum at save for suffix overflow line to avoid line update flag(*u search)//~v42iI~
//v420:010918 cob fld num clear option;num clear cob               //~v40FI~
//v40F:010709 COB support:num clear(clear col72-80)                //~v40FI~
//v40p:010603 add x *= (exclude same as above line)                //~v40pI~
//v192:000902 LINUX support(un-init var usage warning)             //~v192I~
//v178:000430 renum support for lineno hex mode                    //~v178I~
//v158:000404 (BUG)when cap boundary plh is freed by undo which is inserted line,//~v158I~
//            Ssortplh is not now on plh chain.It cause abend at capreset to reset reverse.//~v158I~
//v11w:990813 (BUG)abend after pending lcmd is deleted;dd--c--dd is lcmd err//~v11wI~
//            but d9--c delete lcmd-c line remaining lcmd pending list.//~v11wI~
//v11v:990813 (BUG)when undoed rep,reset lcmd remaining pending list-->paring err//~v11vI~
//v115:990612 issue errmsg for undo cmd(not pfk) with opd          //~v115I~
//v10K:990418 (BUG)buff is shorten case,undo area destroy(occur at sort case)//~v10KI~
//v0eB:970923 find/change range support(include hdr)               //~v0eBI~
//v0ew:970922 split fcmd2 to fcmd22                                //~v0ewI~
//v0du:970909 for performance,use flag once chked spfnumok         //~v0duI~
//            set on when chked,reset when line update or insert.  //~v0duI~
//v0d8:970831 allow err line copy into spf file                    //~v0d8I~
//v0cu:970814 renumsuffix maxintval is 100 for spf file            //~v0cuI~
//v0ct:970814 RENUM(NUM reset) Force option for spf file           //~v0ctI~
//v0cp:970814 undo maxver msg                                      //~v0cpI~
//v0co:970813 undo set ver even if pfh set only case               //~v0coI~
//v0cn:970813 RENUM undo support                                   //~v0cnI~
//v0cm:970812 NUM setver subcmd(reset spf version)                 //~v0cmI~
//v0az:970720 errline reverse display                              //~v0azI~
//v0ay:970720 (BUG)save-->undo-->update-->save save no update because//~v0ayI~
//                 upctr is same value as upctrsave                //~v0ayI~
//v0au:970719 undo max ctr change for other than dos.20-->32768    //~v0auI~
//v092:970301:(BUG)like v055,undo del isrted line which may registered lcmd//~v092I~
//            cause abend                                          //~v092I~
//v08f:961106:performance up                                       //~v08fI~
//			  only once redraw for previous update/previous undo   //~v08fI~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*v011:950610:reset reverse when double ESC                    //~5610I~
//************************************************************* //~5610I~
//*950521 LCMDERR flag clear for lineno normal display after undo//~5521I~
//*950422 hilight curr cap block or find block                  //~5422I~
//*950105 current top ajust when del inserted line              //~5422I~
//*       no confirm when cmd input                             //~5105I~
//*       reverse display current undo result                   //~5105I~
//*950104 line positioning at confirm                           //~5105I~
//*941211 undo isrt/del,undo exclude                            //~5104I~
//*941204 confirmation
//*941204 cur update by updateno not bur ULHCURUNDO
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
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>                                              //~5318I~
#include <uparse.h>                                                //~v0eBI~
#include <ucvext.h>                                                //~va7LI~
#include <ucvebc.h>                                                //~va7LR~
#include <ucvebc4.h>                                               //~va7LI~
#include <utrace.h>                                                //~va23I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"
#include "xefile.h"                                             //~5118I~
#include "xefile12.h"                                              //~v0cmI~
#include "xefile2.h"
#include "xefcmd22.h"                                              //~v0ewR~
#include "xeundo.h"
#include "xelcmd.h"
#include "xelcmd2.h"
#include "xefsub.h"                                             //~5318I~
#include "xeerr.h"                                                 //~v115I~
#include "xecap.h"                                                 //~v158I~
#include "xesub.h"                                                 //~v58cI~
#include "xesyn.h"                                                 //~v780I~
#include "xeopt.h"                                                 //~va7LI~
//*******************************************************
#define MAXUNDOCTR  32768       //other than native dos            //~v0auI~
#ifdef DOS                                                         //~v0auI~
    #ifdef DPMI					//DPMI version                     //~v0auI~
    #else                       //not DPMI                         //~v0auI~
#undef  MAXUNDOCTR				//reset then                       //~v0auI~
#define MAXUNDOCTR  20
    #endif                      //DPMI or not                      //~v0auI~
#else                                                              //~v0auI~
#endif                                                             //~v0auI~
//#ifdef W32          //test on windows at first                   //~vaghR~
    #define REDO                                                   //~vaghR~//~vb2ER~
//#endif                                                           //~vaghR~
//***********************************************
#ifdef REDO                                                        //~vag2I~
	static int Sswredoundo;    //not from redo                     //~vag2R~
#endif                                                             //~vag2I~
//***********************************************                  //~vag2I~
void freeundoent(PUUNDOH Ppuh);
int undoclearplcmd(PUFILEH Ppfh,PULINEH Pplh);                     //~v11vI~
int undosetdeletedflag(PUFILEH Ppfh,PUUNDOH Ppuh,PULINEH Pplh);    //~v74rR~
#ifdef REDO                                                        //~vag2I~
	void freeredoq(PUFILEH Ppfh);                                  //~vag2I~
	int redoprep(PUCLIENTWE Ppcw,PUUNDOH Ppuh,int Ptype,PULINEH Pplh);//~vag2I~
	int redo_undoupdate(PUCLIENTWE Ppcw,PULINEH Pplh,int Ptype);   //~vag2R~
	int redo_undoprep(PUCLIENTWE Ppcw,PULINEH Pplh,int Ptype);     //~vag2I~
#endif                                                             //~vag2I~
//****************************************************************
// undoupdate
//*set line update flag/file update flag
//*parm1:PUCLIENTWE
//*parm2:PULINEH
//*parm3:update type ('R'/'I'/'D')
//*ret  :rc 0 or UALLOC_FAILED                                  //~v04dR~
//****************************************************************
//int undoupdate(PUCLIENTWE Ppcw,PULINEH Pplh,UCHAR Ptype)         //~v761R~
int undoupdate(PUCLIENTWE Ppcw,PULINEH Pplh,int Ptype)             //~v761I~
{
	PUFILEH pfh;
    int rc=0;                                                   //~v04dI~
    int opt;                                                       //~v761I~
#ifdef UNX     //for permission chk                                //~v58cI~
    int rc2=0;                                                     //~v57mI~
#endif                                                             //~v58cI~
//********************
    opt=(int)(((UINT)Ptype>>8)<<8);                                //~v761I~
    Ptype&=0xff;                                                   //~v761I~
	pfh=UGETPFH(Pplh);
//  if (UCBITCHK(pfh->UFHflag6,UFHF6NOUNDO))  //skip save undo data(for ::cb)//~v650R~
//  	return 0;                                                  //~v650R~
	if (UCBITCHK(pfh->UFHflag,UFHFUPCTRREQ))//first time after exec_file
	{
		UCBITOFF(pfh->UFHflag,UFHFUPCTRREQ);	//upctr updated
		UCBITOFF(pfh->UFHflag2,UFHF2RESETPASTE);//v011ignore reset paste//~5610I~
#ifdef UNX     //for permission chk                                //~v55PI~
		if (!pfh->UFHupctr)                                        //~v55PI~
        {                                                          //~v55PI~
//  		if (xefsubwritepermissionchk(pfh)>1) //1:remote        //~v57mR~
    		if ((rc2=xefsubwritepermissionchk(pfh))>1) //1:remote  //~v57mI~
            {                                                      //~v57mI~
              if (rc2==4)                                          //~v57mI~
            	uerrmsg("Warning:No write permission",0);          //~v55PI~
              else                                                 //~v57mI~
            	uerrmsg("Warning:No parent dir write permission",0);//~v57mI~
            }                                                      //~v57mI~
        }                                                          //~v55PI~
#else                                                              //~v55XI~
		if (!pfh->UFHupctr)                                        //~v55XI~
        {                                                          //~v55XI~
			if (xefsubwritepermissionchk(pfh)>1) //1:remote        //~v55XI~
            	uerrmsg("Warning:File is Read-Only",0);            //~v55XI~
        }                                                          //~v55XI~
#endif                                                             //~v55PI~
		pfh->UFHupctr++;					//upctr up
	}
    if (UCBITCHK(pfh->UFHflag6,UFHF6NOUNDO))  //skip save undo data(for ::cb)//~v650I~
    	return 0;                                                  //~v650I~
	switch(Ptype)
	{
	case UUHTISRT:							//line insert
		rc=undoprep(Ppcw,Pplh,Ptype);			//prepare for undo//~v04dR~
    	UCBITON(Pplh->ULHflag2,ULHF2INSERT);//for change id      //~4C13R~
//  	UCBITON(Pplh->ULHflag3,ULHF3CURUPDATE);//reset at next upctr//~v45vR~
//  	UCBITOFF(Pplh->ULHflag3,ULHF3SPFNUMOK|ULHF3SPFNUMERR);//need chk next//~v0duR~
//  clear at ulhcopy because undoupdate is called after fileisvalidspfline//~v0duI~
    	Pplh->ULHupctr=pfh->UFHupctr;		//latest update line.//~4C13R~
        break;                                                //~4C13R~
	case UUHTDEL:							//line delete
//  	UCBITOFF(Pplh->ULHflag3,ULHF3ERRLINE);//lcmd inputline is cleared at xechar but other err in the linerange is not cleared 3errline//~vag3R~
		rc=undoprep(Ppcw,Pplh,Ptype);			//prepare for undo//~v04dR~
		break;
	case UUHTRENUM:  						//spf file renum       //~v0cnR~
    case UUHTSPFVER:    					//versionno chng       //~v0cmR~
	case UUHTCUTOFF: 						//spf file renum       //~v45uI~
		rc=undoprep(Ppcw,Pplh,Ptype);			//prepare for undo //~v0cmI~
		UCBITON(Pplh->ULHflag,ULHFDRAW);                           //~v0cmI~
//  	UCBITON(Pplh->ULHflag3,ULHF3CURUPDATE);//reset at next upctr//~v45vR~
    	Pplh->ULHupctr=pfh->UFHupctr;		//latest update line.  //~v0cmI~
		break;                                                     //~v0cmI~
	case UUHTCIDCLEAR:  					//cid clear/shift      //~v0cmI~
	case UUHTREPRENUM:  					//line replace         //~v0ctI~
	case UUHTREPRENUMCLR:  					//line replace by num clear cmd//~v42rR~
	case UUHTREP:							//line replace
//  	if (Pplh->ULHupctr!=pfh->UFHupctr)                         //~v761R~
    	if (Pplh->ULHupctr!=pfh->UFHupctr                          //~v761I~
        ||  opt & UNDO_FORCE_PREP)                                 //~v761I~
        {                                                          //~v0azI~
//  		UCBITOFF(Pplh->ULHflag3,ULHF3ERRLINE);//no err after undo//~v0azI~//~vag3R~
			rc=undoprep(Ppcw,Pplh,Ptype);			//save old data//~v04dR~
    		UCBITOFF(Pplh->ULHflag3,ULHF3ERRLINE);//no err after undo//~vag3I~
        }                                                          //~v0azI~
//*for display '*',once line draw,to clear cur undo-able line 
		UCBITON(Pplh->ULHflag,ULHFDRAW);
//  	UCBITOFF(Pplh->ULHflag,ULHFCURCAP|ULHFCURFOUND|ULHFMOVE|ULHFCIDCLEAR);//for cir "R"//~v0cmR~
    	UCBITOFF(Pplh->ULHflag,ULHFCURCAP|ULHFCURFOUND|ULHFMOVE);//for cir "R"//~v0cmI~
        if (Ptype!=UUHTCIDCLEAR)	//cid clear/shift              //~v0cmI~
        {                                                          //~v0cmI~
  		  	UCBITOFF(Pplh->ULHflag,ULHFCIDCLEAR);//for cir "R"     //~v0cmI~
	    	UCBITOFF(Pplh->ULHflag3,ULHF3SETSPFVER);//not set ver only//~v0cmR~
		}                                                          //~v0cmI~
                                                                   //~v0duI~
        if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR))  //~v0duR~
        {                                                          //~v0duI~
            UCBITOFF(Pplh->ULHflag3,ULHF3SPFNUMERR);//always reset err//~v0duR~
            if (Ptype==UUHTREPRENUM)    //renum for spf file       //~v0duR~
                UCBITON(Pplh->ULHflag3,ULHF3SPFNUMOK);//num ok     //~v0duR~
            else                                                   //~v0duR~
                UCBITOFF(Pplh->ULHflag3,ULHF3SPFNUMOK);//both reset//~v0duR~
		}                                                          //~v0duI~
                                                                   //~v0duI~
//  	UCBITON(Pplh->ULHflag3,ULHF3CURUPDATE);//reset at next upctr//~v45vR~
    	Pplh->ULHupctr=pfh->UFHupctr;		//latest update line.//~5107I~
		break;
	}
	return rc;                                                  //~v04dR~
}//undoupdate
//****************************************************************
//!undoprep                                                     //~v04dR~
//*prepare for undo,called from undoupdate for data line
//*                 called from lcmd for EXCLUDE line,data line x on/off
//*parm1 :pcw
//*parm2 :line hdr ptr
//*parm3 :update type
//*return:0 or UALLOC_FAILED                                    //~v04dI~
//****************************************************************
//int  undoprep(PUCLIENTWE Ppcw,PULINEH Pplh,UCHAR Ptype)          //~v761R~
int  undoprep(PUCLIENTWE Ppcw,PULINEH Pplh,int Ptype)              //~v761I~
{
	int     lastundoctr,freeundoctr,len;
    int oldupctr;                                                  //~v0cmI~
	UCHAR   *pc;
	PUFILEH pfh;
	PULINEH plhsave;
	PUUNDOH puh;
	PUQUEH  pqh;
//*********************************
    Ptype&=0xff;                                                   //~v761I~
	pfh=UGETPFH(Pplh);
//  if (UCBITCHK(pfh->UFHflag6,UFHF6NOUNDO))  //skip save undo data(for ::cb)//~v650R~
//  	return 0;                                                  //~v650R~
	if (UCBITCHK(pfh->UFHflag,UFHFUNDOCTRREQ))//first after exec_file
	{
		UCBITOFF(pfh->UFHflag,UFHFUNDOCTRREQ);	//undoctr updated
		pfh->UFHundoctr++;					//undoctr up
		pfh->UFHupundoctr++;	//update+undo ctr		        //~5105I~
	}
    if (UCBITCHK(pfh->UFHflag6,UFHF6NOUNDO))  //skip save undo data(for ::cb)//~v650I~
    	return 0;                                                  //~v650I~
	pqh=&(pfh->UFHundoque);
    oldupctr=Pplh->ULHupctr;	 //current                         //~v0cmI~
	if (puh=UGETQTOP(pqh),puh)
	{
		lastundoctr=puh->UUHundoctr;
		if (pfh->UFHundoctr!=lastundoctr		//new update llevel
		&& lastundoctr>=MAXUNDOCTR)				//saved maxlevel
		{									//new update data
//*free oldest uuh
			freeundoctr=pfh->UFHundoctr-MAXUNDOCTR;
			while((puh=UGETQEND(pqh))->UUHundoctr==freeundoctr)//same level
				freeundoent(UDEQ(UQUE_END,pqh,0));	//free entry
		}//level changed and reached maxlevel
	}//not first time
	puh=UALLOCC(1,UUNDOHSZ);                                    //~v04dR~
    UALLOCCHK(puh,UALLOC_FAILED);                               //~v04dI~
	memcpy(puh->UUHcbid,UUHCBID,4);                             //~5105I~
	puh->UUHupctr=pfh->UFHupctr;
	puh->UUHundoctr=pfh->UFHundoctr;
	puh->UUHplh=Pplh;					//inserted plh
	puh->UUHtype=(UCHAR)Ptype;
//*save data
	switch(Ptype)
	{
	case UUHTISRT:							//line insert
        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~v54RI~
        IFDEF_SYNSUPP(xesynundoprep(0,Ptype,Ppcw,pfh,Pplh,puh));   //~v780R~
		break;
	case UUHTDEL:							//line delete
        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~v54RI~
        pfh->UFHplhlcmdi=0;     //protect undoed data cause continued lcmd isrt//~v78SI~
		puh->UUHplh=UGETQPREV(Pplh);		//insert after when undo
		puh->UUHplhsave=Pplh;				//old data plh
        IFDEF_SYNSUPP(xesynundoprep(0,Ptype,Ppcw,pfh,Pplh,puh));   //~v780R~
                                                                   //~v11wI~
		if (UCBITCHK(Pplh->ULHflag,ULHFLINECMD))//clear line cmd input//~v11wI~
        {                                                          //~v11wI~
			memset(Pplh->ULHlinecmd,0,sizeof(Pplh->ULHlinecmd));   //~v11wI~
			UCBITOFF(Pplh->ULHflag,ULHFLINECMD|ULHFLCMDERR);//clear line cmd input//~v11wI~
			undoclearplcmd(pfh,Pplh);//*clear lcmd list when registered//~v11wI~
        }                                                          //~v11wI~
		UDEQ(UQUE_ENT,0,Pplh);				//delete
		if (UCBITCHK(Pplh->ULHflag3,ULHF3SPFNUMERR))//3errline for lcmd input line was cleared at xechar//~vag3R~
			UCBITON(Pplh->ULHflag3,ULHF3ERRLINE);   //keep err after undoed//~vag3R~
                                                                   //~vag3I~
     if (UCBITCHK(Pplh->ULHflag2,ULHF2INSERT) && oldupctr==pfh->UFHupctr)//~v78yI~
        undosetdeletedflag(pfh,puh,Pplh);                          //~v74rI~
		break;
	case UUHTCIDCLEAR:  					//cid clear/shift      //~v0cmI~
	case UUHTREPRENUM:						//spf chng err->ok     //~v0ctI~
	case UUHTREPRENUMCLR:					//num clear cmd        //~v42rR~
	case UUHTREP:							//line replace
        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~v54RI~
		len=Pplh->ULHlen;
        if (Pplh->ULHdbcs)    
		{                                  //~5103I~
//  		pc=UALLOCM((UINT)(ULINEHSZ+len+len));//plh,data,dbcs//~v04dR~//~vb2DR~
    		pc=UALLOCM((UINT)((int)ULINEHSZ+len+len));//plh,data,dbcs//~vb2DR~
			UCBITON(puh->UUHflag,UUHFDBCS);	//dbcs tbl save falg
		}
        else                                                    //~5103I~
//  		pc=UALLOCM((UINT)(ULINEHSZ+len));//plh,data         //~v04dR~//~vb2DR~
    		pc=UALLOCM((UINT)((int)ULINEHSZ+len));//plh,data       //~vb2DR~
        if (!pc)                                                //~v04dI~
        {                                                       //~v04dI~
        	ufree(puh);                                         //~v04dI~
            return UALLOC_FAILED;                               //~v04dR~
        }                                                       //~v04dI~
		puh->UUHplhsave=plhsave=(PVOID)pc;
		memcpy(plhsave,Pplh,sizeof(ULINEH));
		memset(&plhsave->ULHqelem,0,sizeof(plhsave->ULHqelem));
		memset(plhsave->ULHlinecmd,0,sizeof(plhsave->ULHlinecmd));//~5220R~
		UCBITOFF(plhsave->ULHflag,ULHFLINECMD|ULHFLCMDERR);//clear line cmd input//~5521R~
		memcpy(pc+ULINEHSZ,Pplh->ULHdata,(UINT)len);//save data
        if (Pplh->ULHdbcs)                                    //~5103I~
			memcpy(pc+ULINEHSZ+len,Pplh->ULHdbcs,(UINT)len);//save dbcs
		plhsave->ULHdata=plhsave->ULHdbcs=0;//avoid free     //~5103R~
        if (Ptype!=UUHTREPRENUM)	//cid clear/shift              //~v71ZI~
        {                                                          //~v71ZI~
//		  	if (UCBITCHK(Pplh->ULHflag,ULHF4REPRENUM))//update is renum only//~v71ZI~//~va23R~
  		  	if (UCBITCHK(Pplh->ULHflag4,ULHF4REPRENUM))//update is renum only//~va23I~
            {                                                      //~v71ZI~
		    	UCBITON(puh->UUHflag,UUHFREPRENUM);		//recover to ON at undo//~v71ZI~
//    		  	UCBITOFF(Pplh->ULHflag,ULHF4REPRENUM);  //reset renum only//~v71ZI~//~va23R~
      		  	UCBITOFF(Pplh->ULHflag4,ULHF4REPRENUM);  //reset renum only//~va23I~
            }                                                      //~v71ZI~
        }                                                          //~v71ZI~
        if (Ptype==UUHTREPRENUM)	//renum changed err to ok?     //~v0ctI~
        {                                                          //~v0ctI~
	        if (                                                   //~v71ZR~
                !oldupctr //not yet updated                        //~v71ZI~
	  		&&  Ppcw->UCWreason         //parm from filerenum:renum only of valid spf number//~v71ZR~
               )                                                   //~v71ZI~
			  		UCBITON(Pplh->ULHflag4,ULHF4REPRENUM);//update is reprenum only//~v71ZR~
  		  	if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMERR))            //~v0ctR~
		    	UCBITON(puh->UUHflag,UUHFSETSPFOK);                //~v0ctI~
//		   	if (UCBITCHK(pfh->UFHflag5,UFHF5NOAUTONUM)) //changed clear-->reset(renum)//~v42sR~
//  	     	UCBITON(puh->UUHflag,UUHFNUMCLEAR);                //~v42sR~
//		  	if (UCBITCHK(pfh->UFHflag5,UFHF5COB)) //may changed cob-->non cob by clear cob cmd//~v42tR~
//  	    	UCBITON(puh->UUHflag,UUHFCOB);                     //~v42tR~
  		  	if (UCBITCHK(pfh->UFHflag5,UFHF5NUMCLEARED)) //1st time num clear//~v42rI~
            {                                                      //~v42rI~
  		  		UCBITOFF(pfh->UFHflag5,UFHF5NUMCLEARED);           //~v42rI~
		    	UCBITON(puh->UUHflag,UUHFNUMCLEAR);                //~v42rI~
            }                                                      //~v42rI~
		}                                                          //~v0ctI~
        else                                                       //~v0ctI~
        if (Ptype==UUHTREPRENUMCLR)	//renum changed err to ok?     //~v42rR~
        {                                                          //~v42rR~
  		  	if (!UCBITCHK(pfh->UFHflag5,UFHF5NUMCLEARED)) //1st time num clear//~v42tR~
            {                                                      //~v42tI~
  		  		UCBITON(pfh->UFHflag5,UFHF5NUMCLEARED);            //~v42tI~
		    	UCBITON(puh->UUHflag,UUHFNUMCLEAR);                //~v42rR~
            }                                                      //~v42tI~
		}                                                          //~v42rR~
        else                                                       //~v42rR~
        if (Ptype==UUHTCIDCLEAR)                                   //~v0cmI~
	        if (!oldupctr) //not yet updated                       //~v0cmR~
	  		  	UCBITON(Pplh->ULHflag,ULHFCIDCLEAR);//for cir "R"  //~v0cmR~
        IFDEF_SYNSUPP(xesynundoprep(0,Ptype,Ppcw,pfh,Pplh,puh));   //~v780R~
		break;
	case UUHTXON:							//exclude flag on
		UCBITON(Pplh->ULHflag2,ULHF2EXCLUDED);		
		break;
	case UUHTXOFF:							//exclude flag off
		UCBITOFF(Pplh->ULHflag2,ULHF2EXCLUDED);		
		break;
	case UUHTXSUFFIX:						//suffix change
	case UUHTXSUFFIX2:						//spf suffix overflow line//~v42iI~
		puh->UUHctrsave=Pplh->ULHsuffix;		//save suffix
		puh->UUHlongsave=Pplh->ULHlinenor;	//save lineno          //~v0cuI~
        if (Ptype==UUHTXSUFFIX2)                                   //~v42iI~
        	if (!UCBITCHK(Pplh->ULHflag4,ULHF4SETSPFVER2))	//1st time//~v42iR~
            {                                                      //~v42iI~
        		UCBITON(Pplh->ULHflag4,ULHF4SETSPFVER2);	//1st time//~v42iI~
            	UCBITON(puh->UUHflag,UUHFSETSPFVER2);	//reset when undo//~v42iI~
            }                                                      //~v42iI~
		break;
	case UUHTSPFVER:    					//versionno chng       //~v0cmI~
		puh->UUHspfver=Pplh->ULHspfver;		//save version         //~v0cmI~
//  	puh->UUHspfvermax=pfh->UFHspfver;	//save max version     //~v0coR~
		puh->UUHctrsave=oldupctr;	//original upctr               //~v0cmR~
        if (!oldupctr) //not yet updated                           //~v0cmR~
        {                                                          //~v0cmI~
            UCBITON(Pplh->ULHflag3,ULHF3SETSPFVER);                //~v0cmR~
            UCBITON(puh->UUHflag,UUHFSETSPFVER);	//reset when undo//~v0cmR~
		}                                                          //~v0cmI~
		break;                                                     //~v0cmI~
	case UUHTSPFVERMAX:    					//pfh version no chng  //~v0coI~
		puh->UUHspfver=pfh->UFHspfver;	//save max version         //~v0coI~
		break;                                                     //~v0coI~
	case UUHTWIDTH:        					//bin file width changed//~v58cI~
//  	puh->UUHlongsave2=((ULONG)(pfh->UFHwidth)<<16)|(pfh->UFHmergin);	//width and mergin//~v58cR~//~vb2ER~
    	puh->UUHlongsave2=(FILESZT)(((ULONG)(pfh->UFHwidth)<<16)|(pfh->UFHmergin));	//width and mergin//~vb2EI~
		puh->UUHlongsave=UCBITCHK(pfh->UFHflag4,UFHF4WIDTH)!=0;     //width parm flag//~v58cI~
		break;                                                     //~v58cI~
	case UUHTXLINENO:						//excluded lineno change
		puh->UUHctrsave=(int)Pplh->ULHlinenow;	//save excluded lineno
        if (UCBITCHK(Pplh->ULHflag4,ULHF4XSAMEHDR))	//reset prev hdr//~v40pI~
        	UCBITON(puh->UUHflag,UUHFXSAME);                       //~v40pI~
        else                                                       //~v40pI~
        	UCBITOFF(puh->UUHflag,UUHFXSAME);                      //~v40pI~
		break;
	case UUHTRENUM:  						//excluded lineno change//~v0cnI~
		puh->UUHctrsave2=Pplh->ULHsuffix; 	//save suffix          //~v0cnR~
		puh->UUHctrsave=oldupctr;	//original upctr               //~v0cnI~
		puh->UUHlongsave=Pplh->ULHlinenor;	//save suffix          //~v0cnR~
		puh->UUHlongsave2=Pplh->ULHoffs;	//save line offset for hex lineno//~v178I~
        if (!oldupctr) //not yet updated                           //~v0cnI~
        {                                                          //~v0cnI~
            UCBITON(Pplh->ULHflag3,ULHF3SETSPFVER);                //~v0cnI~
            UCBITON(puh->UUHflag,UUHFSETSPFVER);	//reset when undo//~v0cnI~
		}                                                          //~v0cnI~
		break;                                                     //~v0cnI~
	case UUHTCUTOFF:    					//cut split line       //~v45uI~
        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~v54RI~
        IFDEF_SYNSUPP(xesynundoprep(0,Ptype,Ppcw,pfh,Pplh,puh));   //~v780R~
		puh->UUHctrsave=oldupctr;	//restore at undo              //~v45uI~
        if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1))                  //~v45uI~
        {                                                          //~v45uI~
            UCBITON(puh->UUHflag2,UUHF2SPLIT1);                    //~v45uI~
//      	UCBITOFF(Pplh->ULHflag2,ULHF2SPLIT1);                  //~v45AR~
        }                                                          //~v45uI~
        if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT2))                  //~v45uI~
        {                                                          //~v45uI~
            UCBITON(puh->UUHflag2,UUHF2SPLIT2);                    //~v45uI~
//      	UCBITOFF(Pplh->ULHflag2,ULHF2SPLIT2);                  //~v45AR~
        }                                                          //~v45uI~
		break;                                                     //~v45uI~
	case UUHTEBCSETCP:    				//EBC codepage will be changed//~va7LI~
		puh->UUHctrsave=pfh->UFHhandle;	//save before update pfh   //~va7LI~
        if (!UCBITCHK(pfh->UFHflag11,UFHF11EBCSETCP))              //~va7LI~
        {                                                          //~va7LI~
        	UCBITON(pfh->UFHflag11,UFHF11EBCSETCP);                //~va7LI~
			pfh->UFHhandleorg=pfh->UFHhandle;	//save original    //~va7LI~
        }                                                          //~va7LI~
		break;                                                     //~va7LI~
	}
	UENQ(UQUE_TOP,pqh,puh);
#ifdef REDO    	                                                   //~vag2I~
    if (!Sswredoundo)    //not from redo                           //~vag2I~
		freeredoq(pfh);	//new update case string                   //~vag2R~
#endif                                                             //~vag2I~
	return 0;                                                   //~v04dR~
}//undoprep;
                                                                //~v04dI~
//****************************************************************
// func_undo_file                                                  //~vag2R~
//*restore old data on undoq
//*parm1 :file hdr ptr
//*return:0:success,4:no undo data,UALLOC_FAIL                  //~v04dR~
//****************************************************************
int func_undo_file(PUCLIENTWE Ppcw)
{
	int     curundoctr,upctr=0,len,upundoctr;                   //~5105R~
    int ii;                                                        //~v092I~
    int opdno,opid,freesw=0,rc;                                    //~v58cR~
    int obuffl;                                                    //~v10KI~
    int  lcmdsw;                                                   //~v11vI~
	UCHAR   *pc,*pcr1,*pcr2=0;                                     //~v192R~
	PUFILEC pfc;
	PUFILEH pfh;
//  PUFILEH pfhcb;                                                 //~v58cR~
	PULINEH plh,plhsave,plh1st=0;                               //~v04dR~
	PUUNDOH puh;                                                //~5106R~
	PUQUEH  pqh;	//uuh que
    UCHAR msgtype=0,maxver=0;                                      //~v192R~
    UCHAR uhtype;                                                  //~v0ctI~
    int handle=0,oldhandle;                                        //~vaf9R~
//  UCHAR  fpath[_MAX_PATH];                                       //~v58cR~
//static char Swordtbl[]="FREE\0CB\0";                             //~v58cR~
static char Swordtbl[]="FREE\0";                                   //~v58cI~
//static char Scbfnm[]=CLIPBOARDID;                                //~v58cR~
//*********************************
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
	if (Ppcw->UCWkeytype==UCWKTCMD	//cmdline input                //~v115I~
	&&  Ppcw->UCWparm)	//input on cmdline                         //~v115I~
    {                                                              //~v54HI~
    	opdno=Ppcw->UCWopdno;           //funccmd created already  //~v58cI~
    	pc=Ppcw->UCWopdpot;                                        //~v58cI~
        for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)   //next operand addr//~v58cR~
        {                                                          //~v58cI~
            switch(opid=wordtblisrch(pc,Swordtbl),opid)            //~v58cI~
            {                                                      //~v58cI~
            case 1: //FREE                                         //~v58cI~
            	freesw=1;                                          //~v58cI~
                break;                                             //~v58cI~
//          case 2: //CB                                           //~v58cR~
//          	cbsw=1;                                            //~v58cR~
//              break;                                             //~v58cR~
            default: //0:err                                       //~v58cI~
		        return errinvalid(pc);                             //~v58cR~
	        }//for                                                 //~v58cI~
        }//for                                                     //~v58cI~
//    if (stricmp(Ppcw->UCWparm,"FREE"))                           //~v58cI~
//      return errinvalid(Ppcw->UCWparm);                          //~v58cI~
//    else                                                         //~v58cR~
        rc=0;                                                      //~v58cI~
//        if (cbsw)     //free ::cb undo data                      //~v58cR~
//        {                                                        //~v58cR~
//            if (filesrchpfh(Scbfnm,fpath,&pfhcb))//not found on fileq or err//~v58cR~
//            {                                                    //~v58cR~
//                uerrmsg("%s is not loaded.",                     //~v58cR~
//                        "%s はロードされていません。",           //~v58cR~
//                        Scbfnm);                                 //~v58cR~
//                return 4;                                        //~v58cR~
//            }                                                    //~v58cR~
//            pqh=&pfhcb->UFHundoque;                              //~v58cR~
//            puh=UGETQTOP(pqh);                                   //~v58cR~
//            if (!puh)                                            //~v58cR~
//            {                                                    //~v58cR~
//                uerrmsg("No update data for %s",                 //~v58cR~
//                        "%s には更新データがありません",         //~v58cR~
//                        Scbfnm);                                 //~v58cR~
//                rc=4;                                            //~v58cR~
//            }                                                    //~v58cR~
//            undofreeuuh(pfh);                                    //~v58cR~
//            uerrmsg("update level %d undo data is freed for %s.",//~v58cR~
//                    "%s の更新レベル %d 以前のundoデータは削除されました。",//~v58cR~
//                    Scbfnm,pfhcb->UFHundoctr);                   //~v58cR~
//        }//cbsw                                                  //~v58cR~
      	if (freesw)                                                //~v58cR~
      	{                                                          //~v58cR~
			pqh=&pfh->UFHundoque;                                  //~v51rI~
			puh=UGETQTOP(pqh);                                     //~v51rI~
            if (!puh)                                              //~v51rI~
            {                                                      //~v51rI~
				uerrmsg("No update data",                          //~v51rI~
				"更新データがありません");                         //~v51rI~
                return 4;                                          //~v51rI~
        	}                                                      //~v51rI~
			undofreeuuh(pfh);                                      //~v51rI~
			uerrmsg("update level %d undo data is freed.",         //~v51rI~
					"更新レベル %d 以前のundoデータは削除されました。",//~v51rI~
					pfh->UFHundoctr);                              //~v51rI~
//          return 0;                                              //~v58cR~
      	}//free                                                    //~v58cR~
		return rc;                                                 //~v58cR~
    }//cmdline input                                               //~v54HI~
                                                                   //~v115I~
	UCBITON(pfh->UFHflag,UFHFUPCTRREQ|UFHFUNDOCTRREQ);
	if (!(puh=UGETQTOP(pqh=&(pfh->UFHundoque))))
	{
		uerrmsg("No update data",
				"更新データがありません");
		return 4;
	}
	curundoctr=pfh->UFHundoctr;
	upundoctr=++pfh->UFHupundoctr;  //update+undo ctr for reverse//~5106I~
//*confirmation                                                 //~5104I~
	if (Ppcw->UCWkeytype!=UCWKTCMD	//func key not cmdline input//~5225R~
	&&  !scrconfirmchk(GSCRCONFUNDO))//not yet confirmed        //~5105R~
	{                                                           //~5104I~
//search first operation	                                    //~5104I~
		while(puh)                                              //~5104I~
		{                                                       //~5104I~
			if (puh->UUHundoctr!=curundoctr)                    //~5104I~
				break;                                          //~5104I~
            if (msgtype==UUHTEBCSETCP)  //multiple entry if not "ebc setcp" cmd but "cv setcp" cmd.//~va7LI~
                msgtype=0;                                         //~va7LI~
			plh=puh->UUHplh;			//corresponding ULINEH  //~5106I~
			uhtype=puh->UUHtype;                                   //~v0ctI~
			switch(uhtype)                                         //~v0ctR~
			{                                                   //~5106I~
			case UUHTISRT:                                      //~5106I~
				UCBITON(plh->ULHflag,ULHFDRAW);                 //~5106I~
              if (!UCBITCHK(puh->UUHflag2,UUHF2DELETED))           //~v74rR~
              {                                                    //~v74rI~
				plh1st=plh;			//csr move plh              //~5106R~
				plh1st->ULHupundoctr=upundoctr;	//current undo  //~5106I~
              }                                                    //~v74rI~
				break;                                          //~5106I~
			case UUHTDEL:                                       //~5106I~
				plh1st=puh->UUHplh;		//csr move to prev of deleted//~5106R~
				break;                                          //~5106I~
			case UUHTSPFVER:		//version change               //~v0cmM~
			case UUHTCIDCLEAR:  					//cid clear/shift//~v0cmI~
			case UUHTREPRENUM:                                     //~v0ctI~
			case UUHTREPRENUMCLR:                                  //~v42rR~
			case UUHTREP:                                       //~5106I~
				UCBITON(plh->ULHflag,ULHFDRAW);                 //~5106I~
				plh1st=plh;			//csr move plh              //~5106I~
				plh1st->ULHupundoctr=upundoctr;	//current undo result line//~5106I~
                if (uhtype==UUHTREPRENUM)                          //~v0ctI~
	                if (UCBITCHK(puh->UUHflag,UUHFSETSPFOK))       //~v0ctI~
		                msgtype=UUHTREPRENUM;                      //~v0ctI~
				break;                                          //~5106I~
			case UUHTSPFVERMAX:		//version change               //~v0coI~
            	msgtype=UUHTSPFVERMAX;                             //~v0cpI~
	            maxver=puh->UUHspfver;//restore max version        //~v0cpI~
				break;                                             //~v0cpI~
			case UUHTXON:                                       //~5106I~
				break;                                          //~5106I~
			case UUHTXOFF:                                      //~5106I~
				UCBITON(plh->ULHflag,ULHFDRAW);                 //~5106I~
				plh1st=plh;			//csr move plh              //~5106R~
				plh1st->ULHupundoctr=upundoctr;	//current undo result line//~5106I~
				break;                                          //~5106I~
			case UUHTXSUFFIX:		//suffix change             //~5106I~
			case UUHTXSUFFIX2:		//suffix change                //~v42iI~
				break;                                          //~5106I~
			case UUHTXLINENO:		//excluded lineno change    //~5106I~
				UCBITON(plh->ULHflag,ULHFDRAW);                 //~5106I~
				plh1st=plh;			//csr move plh              //~5106R~
				plh1st->ULHupundoctr=upundoctr;	//current undo result line//~5106I~
				break;                                          //~5106I~
			case UUHTRENUM:  		//excluded lineno change       //~v0cnI~
			case UUHTCUTOFF: 		//split line                   //~v45uI~
				plh1st=plh;			//csr move plh                 //~v0coI~
				UCBITON(plh->ULHflag,ULHFDRAW);                    //~v0cnI~
				plh->ULHupundoctr=upundoctr;	//current undo result line//~v0cnI~
				break;                                             //~v0cnI~
			case UUHTEBCSETCP:  	//ebc codepage change          //~va7LI~
				handle=puh->UUHctrsave;                            //~va7LI~
            	msgtype=UUHTEBCSETCP;                              //~va7LI~
				break;                                             //~va7LI~
			}//sw by type                                       //~5106I~
			puh=UGETQNEXT(puh);                                 //~5104I~
		}//	all puh                                             //~5104I~
//set csr to 1st plh                                            //~5105R~
		if (plh1st)	//data exist                                //~v04dI~
			undocsrmove(Ppcw,plh1st);                              //~5104R~//~v04dR~
        switch(msgtype)                                            //~v0cpI~
        {                                                          //~v0cpI~
        case UUHTSPFVERMAX:     //version change                   //~v0cpI~
		    uerrmsg("Version restore confirmation(%d-->%d)",       //~v0cpI~
        		    "バージョン番号が戻されます(%d-->%d)",         //~v0cpI~
            		pfh->UFHspfver,maxver);                        //~v0cpI~
            break;                                                 //~v0cpI~
        case UUHTREPRENUM:     //changed er->ok                    //~v0ctI~
		    uerrmsg("It will back to line-no err status",          //~v0ctI~
        		    "行番号エラー状態に戻ります");                 //~v0ctI~
            break;                                                 //~v0ctI~
        case UUHTEBCSETCP:                                         //~va7LI~
		    uerrmsg("EBCDIC codepage will be retored to %s by the same key",//~va7LR~
        		    "EBCDICコードページを %s に戻しますか。同じキー操作で実行。",//~va7LR~
					ucvebc4_getcvname(0,handle));                  //~va7LR~
            break;                                                 //~va7LI~
        default:                                                   //~v0cpR~
			uerrmsg("Update level %d confirmation, execute by the same key",//~5105R~//~va7LR~
					"更新レベル %d, 操作の繰り返しにより UNDO されます",//~5105R~
					pfh->UFHundoctr);	//confirmid             //~5105R~
		}                                                          //~v0cpI~
		return 1;       //stay cmd on cmdline for reenter       //~5105R~
	}                                                           //~5104I~
//*undo                                                         //~5104I~
	while(puh)
	{
		if (puh->UUHundoctr!=curundoctr)
			break;
		plh=puh->UUHplh;			//corresponding ULINEH      //~5104R~
        uhtype=puh->UUHtype;                                       //~v0ctI~
#ifdef REDO                                                        //~vag2I~
		redoprep(Ppcw,puh,uhtype,plh);                             //~vag2R~
#endif                                                             //~vag2I~
        switch(uhtype)
		{                                                          //~v0ctI~
		case UUHTISRT:
        	IFDEF_SYNSUPP(xesynundo(0,uhtype,Ppcw,pfh,plh,puh));   //~v780R~
	        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~v54RI~
			plh1st=UGETQPREV(plh);	//csr move                  //~5105I~
			if (plh->ULHtype==ULHTDATA)
				upctr=puh->UUHupctr;
            if (plh==pfc->UFCcurtop) //del current top(ptr now invalid)//~5105R~
				pfc->UFCcurtop=getdisplayline(plh,-1,0);        //~5204R~
//*clear lcmd list when registered                                 //~v092I~
        	for (ii=pfh->UFHcmdlinectr-1;ii>=0;ii--)               //~v092R~
            {                                                      //~va23I~
        		if (plh==pfh->UFHcmdline[ii])                      //~v092I~
                {                                                  //~va23I~
        			pfh->UFHcmdline[ii]=0;                         //~v092I~
				    UTRACEP("@@@1 %s:drop by redo isrt %c cmd,cmdlinectr=%d,ii=%d\n",UTT,*plh->ULHlinecmd,pfh->UFHcmdlinectr,ii);//~va23R~
                }                                                  //~va23I~
            }                                                       //~v158I~//~va23R~
//#ifdef NOTEST  abend test                                        //~v158R~
            if (Gcappcw==Ppcw)                                     //~v158R~
                if (plh==Gcapplh1 || plh==Gcapplh2)                //~v158R~
                    capreset(1);//clear block define               //~v158R~
            if (Gcalcpcw==Ppcw)                                    //~v158I~
                if (plh==Gcalcplh1 || plh==Gcalcplh2)              //~v158I~
                    capresetcalc(Ppcw);//clear block define        //~v158I~
//#endif                                                           //~v158R~
			lcmddelresetcurtop(Ppcw,plh);	//maint pfccurtop      //~v54HI~
#ifdef REDO                                                        //~vag2I~
			UDEQ(UQUE_ENT,0,plh);  //deq after lcmddelresetcurtop  //~vag2R~
#else                                                              //~vag2I~
			filefreeplh((PULINEH)UDEQ(UQUE_ENT,0,plh),1);//free isrted
#endif                                                             //~vag2I~
			break;
		case UUHTDEL:
	        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~v54RI~
			plhsave=puh->UUHplhsave;
			plhsave->ULHupundoctr=upundoctr;	//current undo result line//~5105I~
			plh1st=plhsave;	//csr move                          //~5105I~
			if (plhsave->ULHtype==ULHTDATA)
				upctr=puh->UUHupctr;
			UCBITOFF(plhsave->ULHflag,ULHFBLOCK);//no more effective capdbcs tbl saveed//~5422I~
//  	    UCBITON(plhsave->ULHflag3,ULHF3CURUNDO);//reset at next uundo//~v45zR~
			UENQENT(UQUE_AFT,puh->UUHplh,plhsave);
			puh->UUHplhsave=0;	//avoid free by freeundoent
        	IFDEF_SYNSUPP(xesynundo(0,uhtype,Ppcw,pfh,plhsave,puh));//~v780R~
			break;
        case UUHTCIDCLEAR:                      //cid clear/shift  //~v0cmI~
		case UUHTREPRENUM:                                         //~v0ctI~
		case UUHTREPRENUMCLR:                                      //~v42rR~
		case UUHTREP:
	        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~v54RI~
			plhsave=puh->UUHplhsave;                            //~v04dI~
//  		pcr1=UALLOCM((UINT)plhsave->ULHbufflen);               //~v10KR~
    		obuffl=plhsave->ULHbufflen;                            //~v10KI~
    		pcr1=UALLOCM((UINT)obuffl);                            //~v10KI~
            UALLOCCHK(pcr1,UALLOC_FAILED);                      //~v04dR~
			if (UCBITCHK(puh->UUHflag,UUHFDBCS))	//dbcs tbl saveed//~v04dI~
            {                                                   //~v04dI~
//  			pcr2=UALLOCM((UINT)plh->ULHbufflen);               //~v10KR~
    			pcr2=UALLOCM((UINT)obuffl);                        //~v10KI~
                if (!pcr2)                                      //~v04dI~
                {                                               //~v04dI~
	            	ufree(pcr1);                                //~v04dI~
	                return UALLOC_FAILED;                       //~v04dR~
                }                                               //~v04dI~
			}                                                   //~v04dI~
			if (plh->ULHtype==ULHTDATA)
				upctr=puh->UUHupctr;
			filefreeplh(plh,0);	//free data only
			lcmdsw=UCBITCHK(plh->ULHflag,ULHFLINECMD);//currentry lcmd active?//~v11vI~
			memcpy(&(plh->ULHqelem)+1,
					&(plhsave->ULHqelem)+1,                     //~v04dR~
					ULINEHSZ-UQUEESZ);	//except qelem hdr
                                                                   //~v11vI~
			if (lcmdsw)                                            //~v11vI~
				if (!UCBITCHK(plh->ULHflag,ULHFLINECMD))//lcmd cleared by undo//~v11vR~
					undoclearplcmd(pfh,plh);//*clear lcmd list when registered//~v11vI~
                                                                   //~v11vI~
			UCBITOFF(plh->ULHflag,ULHFBLOCK);//no more effective capdbcs tbl saveed//~5422I~
//  	    UCBITON(plh->ULHflag3,ULHF3CURUNDO);//reset at next uundo//~v45zR~
			plh1st=plh;	//csr move                              //~5105I~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~5105I~
			len=plh->ULHlen;
			pc=(PVOID)plhsave;
			memcpy(plh->ULHdata=pcr1,pc+ULINEHSZ,(UINT)len);    //~v04dR~
			if (UCBITCHK(puh->UUHflag,UUHFDBCS))	//dbcs tbl saveed
				memcpy(plh->ULHdbcs=pcr2,pc+ULINEHSZ+len,(UINT)len);//~v04dR~
		    if (UCBITCHK(puh->UUHflag,UUHFREPRENUM))		//recover to ON at undo//~v71ZI~
				UCBITON(plh->ULHflag4,ULHF4REPRENUM);	//update is renum only//~v71ZI~
            if (uhtype==UUHTREPRENUM)    //renum changed err to ok?//~v0ctR~
            {                                                      //~v40FI~
                if (UCBITCHK(puh->UUHflag,UUHFSETSPFOK))           //~v0ctI~
                {                                                  //~v0ctI~
	                msgtype=UUHTREPRENUM;                          //~v0ctI~
                	UCBITON(pfh->UFHflag2,UFHF2SPFNUMERR);         //~v0ctR~
                	UCBITOFF(pfh->UFHflag2,UFHF2SPFNUMOK);         //~v0ctR~
				}                                                  //~v0ctI~
//              if (UCBITCHK(puh->UUHflag,UUHFNUMCLEAR))           //~v42sR~
//                  UCBITON(pfh->UFHflag5,UFHF5NOAUTONUM); //back to no autonum mode//~v42sR~
//              else                                               //~v42sR~
//                  UCBITOFF(pfh->UFHflag5,UFHF5NOAUTONUM); //back to no autonum mode//~v42sR~
//              if (UCBITCHK(puh->UUHflag,UUHFCOB))                //~v42tR~
//                  UCBITON(pfh->UFHflag5,UFHF5COB); //recover cob flag//~v42tR~
                if (UCBITCHK(puh->UUHflag,UUHFNUMCLEAR)) //renum changed cleared//~v42rI~
                    UCBITON(pfh->UFHflag5,UFHF5NUMCLEARED); //back to no autonum mode//~v42rI~
            }                                                      //~v40FI~
            if (uhtype==UUHTREPRENUMCLR)    //renum changed err to ok?//~v42rR~
            {                                                      //~v42rR~
                if (UCBITCHK(puh->UUHflag,UUHFNUMCLEAR))           //~v42rR~
                    UCBITOFF(pfh->UFHflag5,UFHF5NUMCLEARED); //back to autonum mode//~v42rR~
            }                                                      //~v42rR~
        	IFDEF_SYNSUPP(xesynundo(0,uhtype,Ppcw,pfh,plh,puh));   //~v780R~
			break;
		case UUHTXON:
			plh1st=plh;	//csr move                              //~5105I~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~5105I~
			UCBITOFF(puh->UUHplh->ULHflag2,ULHF2EXCLUDED);
//  	    UCBITON(plh->ULHflag3,ULHF3CURUNDO);//reset at next uundo//~v45zR~
			break;
		case UUHTXOFF:
			plh1st=plh;	//csr move                              //~5105I~
			UCBITON(puh->UUHplh->ULHflag2,ULHF2EXCLUDED);
			break;
		case UUHTXSUFFIX:		//suffix change
		case UUHTXSUFFIX2:		//suffix change                    //~v42iI~
			puh->UUHplh->ULHsuffix=puh->UUHctrsave;	//restore old value
			plh->ULHlinenor=puh->UUHlongsave;//restore old value   //~v0cuI~
//  	    UCBITON(plh->ULHflag3,ULHF3CURUNDO);//reset at next uundo//~v45zR~
            if (UCBITCHK(puh->UUHflag,UUHFSETSPFVER2))	//suffix overflow for spf//~v42iI~
        		UCBITOFF(plh->ULHflag4,ULHF4SETSPFVER2);           //~v42iR~
			break;
		case UUHTSPFVER:		//version change                   //~v0cmI~
			upctr=puh->UUHupctr;                                   //~v0cmI~
//  	    UCBITON(plh->ULHflag3,ULHF3CURUNDO);//reset at next uundo//~v45zR~
			plh1st=plh;	//csr move                                 //~v0cmI~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~v0cmI~
                                                                   //~v0cmI~
			plh->ULHspfver=puh->UUHspfver;	//restore old value    //~v0cmI~
//  		pfh->UFHspfver=puh->UUHspfvermax;//restore max version //~v0coR~
			plh->ULHupctr=puh->UUHctrsave;	//restore old value    //~v0cmR~
            if (UCBITCHK(puh->UUHflag,UUHFSETSPFVER))	//reset when undo//~v0cmR~
            	UCBITOFF(plh->ULHflag3,ULHF3SETSPFVER);	//reset when undo//~v0cmR~
	        filesetvernum(pfh,plh);                                //~v0cmM~
			break;                                                 //~v0cmI~
		case UUHTSPFVERMAX:		//undo pfh spfver                  //~v0coI~
            msgtype=UUHTSPFVERMAX;                                 //~v0cpI~
//  		upctr=puh->UUHupctr;	//pfh upctr back               //~v45wR~
//  	    UCBITON(plh->ULHflag3,ULHF3CURUNDO);//reset at next uundo//~v45wR~
//  		plh->ULHupundoctr=upundoctr;	//current undo result line//~v45wR~
            maxver=pfh->UFHspfver;//current value                  //~v0cpI~
			pfh->UFHspfver=puh->UUHspfver;//restore max version    //~v0coI~
			break;                                                 //~v0coI~
		case UUHTWIDTH:        					//bin file width changed//~v58cI~
			pfh->UFHwidth=(USHORT)(puh->UUHlongsave2>>16);         //~v58cI~
			pfh->UFHmergin=(USHORT)(puh->UUHlongsave2 & 0xffff);   //~v58cI~
			if (puh->UUHlongsave)                                  //~v58cI~
				UCBITON(pfh->UFHflag4,UFHF4WIDTH);     //width parm flag//~v58cI~
            else                                                   //~v58cI~
				UCBITOFF(pfh->UFHflag4,UFHF4WIDTH);     //width parm flag//~v58cI~
			break;                                                 //~v58cI~
		case UUHTXLINENO:		//excluded lineno change
			plh1st=plh;	//csr move                              //~5105I~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~5105I~
			puh->UUHplh->ULHlinenow=puh->UUHctrsave;//restore old value
        	if (UCBITCHK(puh->UUHflag,UUHFXSAME))                  //~v40pI~
        		UCBITON(plh->ULHflag4,ULHF4XSAMEHDR);              //~v40pI~
        	UCBITOFF(puh->UUHflag,UUHFXSAME);                      //~v40pI~
//  	    UCBITON(plh->ULHflag3,ULHF3CURUNDO);//reset at next uundo//~v45zR~
			lcmdeditxline(puh->UUHplh);//edit lineno
			break;
		case UUHTRENUM:  		//renum undo                       //~v0cnI~
			upctr=puh->UUHupctr;                                   //~v0cnI~
			plh1st=plh;	//csr move                                 //~v0cnI~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~v0cnI~
			plh->ULHlinenor=puh->UUHlongsave;//restore old value   //~v0cnI~
			plh->ULHoffs=puh->UUHlongsave2;//restore line hex offset//~v178I~
			plh->ULHsuffix=puh->UUHctrsave2;//restore old value    //~v0cnR~
			plh->ULHupctr=puh->UUHctrsave;	//restore old value    //~v0cnI~
            if (UCBITCHK(puh->UUHflag,UUHFSETSPFVER))	//reset when undo//~v0cnI~
            	UCBITOFF(plh->ULHflag3,ULHF3SETSPFVER);	//reset when undo//~v0cnI~
            if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK))             //~v0cnI~
	            filespfnumedit(pfh,plh,1);//setup num field,ver from plh//~v0cnR~
//  	    UCBITON(plh->ULHflag3,ULHF3CURUNDO);//reset at next uundo//~v45zR~
			break;                                                 //~v0cnI~
        case UUHTCUTOFF:                        //cut split line   //~v45uI~
	        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~v54RI~
			upctr=puh->UUHupctr;                                   //~v45uI~
			plh->ULHupctr=puh->UUHctrsave;	//restore old value    //~v45uI~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~v45uI~
			plh1st=plh;	//csr move                                 //~v45uI~
            if (UCBITCHK(puh->UUHflag2,UUHF2SPLIT1))               //~v45uI~
            	UCBITON(plh->ULHflag2,ULHF2SPLIT1);                //~v45uR~
            if (UCBITCHK(puh->UUHflag2,UUHF2SPLIT2))               //~v45uI~
            	UCBITON(plh->ULHflag2,ULHF2SPLIT2);                //~v45uR~
//  	    UCBITON(plh->ULHflag3,ULHF3CURUNDO);//reset at next uundo//~v45zR~
        	IFDEF_SYNSUPP(xesynundo(0,uhtype,Ppcw,pfh,plh,puh));   //~v780R~
            break;                                                 //~v45uI~
        case UUHTSPFERR:                        //set spf err      //~v0d8I~
        	UCBITON(pfh->UFHflag2,UFHF2SPFNUMOK);                  //~v0d8R~
        	UCBITOFF(pfh->UFHflag2,UFHF2SPFNUMERR);                //~v0d8I~
            break;                                                 //~v0d8I~
        case UUHTEBCSETCP:                                         //~va7LI~
        	oldhandle=pfh->UFHhandle;                              //~va7LR~
        	pfh->UFHhandle=puh->UUHctrsave;                        //~va7LI~
			fsubresetebcdbcstbl(0,oldhandle,Ppcw,pfh);             //~va7LI~
            opt2setebccvname(0,pfh);                               //~va7LR~
            break;                                                 //~va7LI~
		}
		freeundoent(UDEQ(UQUE_TOP,pqh,puh));
		puh=UGETQTOP(pqh);
	}//all puh
//*csr move                                                     //~5105R~
	if (plh1st)	//data exist                                    //~v04dI~
		undocsrmove(Ppcw,plh1st);                               //~v04dR~
                                                                //~5105I~
    filesetmultdraw(Ppcw);	//all client draw of same file      //~5118I~
	if (pfh->UFHundoctr)
		--pfh->UFHundoctr;
	if (upctr)		//upctr restore	
		pfh->UFHupctr=upctr-1;
//  pfh->UFHupctrsave=0;		//reset saved id                   //~v0ayI~//~va36R~
  	if (pfh->UFHupctrsave)		//once saved                       //~va36I~
		pfh->UFHupctrsave=-1;		//trace of once updated to accept writeback//~va36I~
    switch(msgtype)                                                //~v0cpI~
    {                                                              //~v0cpI~
    case UUHTSPFVERMAX:     //version change                       //~v0cpI~
        uerrmsg("Version restore(%d-->%d)",                        //~v0cpI~
                "バージョン番号が戻されました(%d-->%d)",           //~v0cpI~
                maxver,pfh->UFHspfver);                            //~v0cpI~
        break;                                                     //~v0cpI~
    case UUHTREPRENUM:     //changed er->ok                        //~v0ctI~
        uerrmsg("Backed to line-no err status",                    //~v0ctI~
                "行番号エラー状態に戻りました");                   //~v0ctI~
        break;                                                     //~v0ctI~
    default:                                                       //~v0cpR~
	uerrmsg("Backed to update level %d",
			"更新レベル %d に戻りました",
			pfh->UFHundoctr);
	}                                                              //~v0cpI~
	return 0;
}//func_undo_file                                                  //~vag2R~
//**************************************************************** //~v9@8I~
// undoclearplcmdall                                               //~v9@8I~
//*clear all pending linecmd plh list                              //~v9@8I~
//*void                                                            //~v9@8I~
//**************************************************************** //~v9@8I~
int undoclearplcmdall(int Popt,PUFILEH Ppfh)                       //~v9@8I~
{                                                                  //~v9@8I~
    int ii,rc=0;                                                   //~v9@8I~
    PULINEH plh;                                                   //~v9@8I~
//******************                                               //~v9@8I~
    for (ii=Ppfh->UFHcmdlinectr-1;ii>=0;ii--)                      //~v9@8I~
    {                                                              //~v9@8I~
        plh=Ppfh->UFHcmdline[ii];                                  //~v9@8I~
        if (plh)                                                   //~v9@8I~
        {                                                          //~v9@8I~
		    UTRACEP("@@@1 %s:%c cmd,cmdlinectr=%d,ii=%d\n",UTT,*plh->ULHlinecmd,Ppfh->UFHcmdlinectr,ii);//~va23R~
        	memset(plh->ULHlinecmd,0,sizeof(plh->ULHlinecmd));     //~v9@8I~
        	UCBITOFF(plh->ULHflag,ULHFLINECMD|ULHFLCMDERR);//clear line cmd input//~v9@8I~
    		UCBITON(plh->ULHflag,ULHFDRAW); //redraw for clear hilite//~v9@8I~
            lcmdclearlcmdplc(plh); //clear also Slcmd to protect deleted lcmd process//~v9@8I~
            rc=1;                                                  //~v9@8I~
        }                                                          //~v9@8I~
    }                                                              //~v9@8I~
    Ppfh->UFHcmdlinectr=0;                                         //~v9@8I~
    return rc;                                                     //~v9@8I~
}//undoclearplcmdall                                               //~v9@8I~
//**************************************************************** //~v11vI~
// undoclearplcmd                                                  //~v11vI~
//*clear pending linecmd plh list                                  //~v11vI~
//*parm1:pfh                                                       //~v11vI~
//*parm2:plh                                                       //~v11vI~
//*void                                                            //~v11vI~
//**************************************************************** //~v11vI~
int undoclearplcmd(PUFILEH Ppfh,PULINEH Pplh)                      //~v11vI~
{                                                                  //~v11vI~
    int ii,rc=0;                                                   //~v11vI~
//******************                                               //~v11vI~
    for (ii=Ppfh->UFHcmdlinectr-1;ii>=0;ii--)                      //~v11vI~
        if (Pplh==Ppfh->UFHcmdline[ii])                            //~v11vI~
        {                                                          //~v11vI~
		    UTRACEP("@@@1 %s:cmd=%x,cmdlinectr=%d\n",UTT,*Pplh->ULHlinecmd,Ppfh->UFHcmdlinectr);//~va23R~
            lcmdclearlcmdplc(Pplh); //clear also Slcmd to protect deleted lcmd process//~v724R~
            Ppfh->UFHcmdline[ii]=0;                                //~v11vI~
            rc=1;                                                  //~v11vI~
		}                                                          //~v11vI~
	return rc;                                                     //~v11vI~
}//undoclearplcmd                                                  //~v51rR~
//****************************************************************
// undofreeuuh
//*free all undo entry
//*parm1:PUFILEH
//*void
//****************************************************************
void undofreeuuh(PUFILEH Ppfh)
{
	UQUEH   *pqh;
	PUUNDOH puh;
//******************
	pqh=&Ppfh->UFHundoque;
	while (puh=UDEQ(UQUE_TOP,pqh,0),puh)	//dequed
		freeundoent(puh);
#ifdef REDO                                                        //~vag2I~
	freeredoq(Ppfh);                                               //~vag2R~
#endif                                                             //~vag2I~
	return;
}//undofreeuuh
//****************************************************************
// freeundoent
//*free undo entry
//*parm1:PUUNDOH
//*void
//****************************************************************
void freeundoent(PUUNDOH Ppuh)
{
	if (Ppuh->UUHplhsave)
#ifdef REDO                                                        //~vag2I~
	  if (!(    UCBITCHK(Ppuh->UUHflag2,UUHF2REDO)                 //~vag2R~
			 && Ppuh->UUHtype==UUHTDEL	//redo entry               //~vag2R~
           )                                                       //~vag2I~
         )    //UUHplhsave is pointer to plh enqued on pfh         //~vag2R~
#endif                                                             //~vag2I~
		filefreeplh(Ppuh->UUHplhsave,1);
	ufree(Ppuh);
}//freeundoent
                                                                //~5105I~
//****************************************************************//~5105I~
// undocsrmove                                                  //~5105R~
//*csr move to first line                                       //~5105I~
//*parm1:pcw                                                       //~v0coR~
//*parm2:plh                                                       //~v0coI~
//*void                                                         //~5105I~
//****************************************************************//~5105I~
void undocsrmove(PUCLIENTWE Ppcw,PULINEH Pplh)                  //~5106R~
{                                                               //~5105I~
//************************                                      //~5105I~
	if (UCBITCHK(Pplh->ULHflag2,ULHF2EXCLUDED))                 //~5106I~
		Pplh=getdisplayline(Pplh,-1,0);                         //~5204R~
	fcmdscrollpage(Ppcw,Pplh);	//display page include the line //~5105I~
	filesetcsr(Ppcw,Pplh,0,0);		//csr set to lineno fld,fldtop//~5223R~
	return;                                                     //~5105I~
}//undocsrmove                                                  //~5105R~
//**************************************************************** //~v74rI~
// undosetdeletedflag                                              //~v74rI~
//*set deleted flag for prev undo entry                            //~v74rI~
//*parm1:pcw                                                       //~v74rI~
//*parm2:plh                                                       //~v74rI~
//*void                                                            //~v74rI~
//**************************************************************** //~v74rI~
int undosetdeletedflag(PUFILEH Ppfh,PUUNDOH Ppuh,PULINEH Pplh)     //~v74rR~
{                                                                  //~v74rI~
	PUUNDOH puh;                                                   //~v74rI~
    int curundoctr;                                                //~v74rR~
    int rc=0;                                                      //~v74rI~
//****************************                                     //~v74rI~
	curundoctr=Ppuh->UUHundoctr;                                   //~v74rI~
	puh=UGETQTOP(&(Ppfh->UFHundoque));                             //~v74rI~
    while(puh)                                                     //~v74rI~
    {                                                              //~v74rI~
        if (puh->UUHundoctr!=curundoctr)                           //~v74rI~
            break;                                                 //~v74rI~
        if (puh->UUHplh==Pplh)            //corresponding ULINEH   //~v74rI~
        {                                                          //~v74rI~
	        UCBITON(puh->UUHflag2,UUHF2DELETED);                   //~v74rI~
            rc=1;                                                  //~v74rI~
            break;                                                 //~v78yI~
        }                                                          //~v74rI~
        puh=UGETQNEXT(puh);                                        //~v74rI~
    }// all puh                                                    //~v74rI~
    return rc;                                                     //~v74rI~
}//undosetdeletedflag                                              //~v74rI~
                                                                //~5105I~//~vag2M~
#ifdef REDO                                                        //~vag2I~
//**************************************************************** //~vag2I~
//*redo q                                                          //~vag2I~
//**************************************************************** //~vag2I~
void freeredoq(PUFILEH Ppfh)                                       //~vag2I~
{                                                                  //~vag2I~
	UQUEH   *pqh;                                                  //~vag2I~
	PUUNDOH puh;                                                   //~vag2I~
//******************                                               //~vag2I~
	pqh=&Ppfh->UFHredoque;                                         //~vag2I~
	while (puh=UDEQ(UQUE_TOP,pqh,0),puh)	//dequed               //~vag2I~
		freeundoent(puh);                                          //~vag2I~
}                                                                  //~vag2I~
//**************************************************************** //~vag2I~
//!redoprep                                                        //~vag2I~
//*return:0 or UALLOC_FAILED                                       //~vag2I~
//**************************************************************** //~vag2I~
int redoprep(PUCLIENTWE Ppcw,PUUNDOH Ppuh,int Ptype,PULINEH Pplh)  //~vag2R~
{                                                                  //~vag2I~
	int   /*lastundoctr,freeundoctr,*/len;                         //~vag2R~
    int oldupctr;                                                  //~vag2R~
	UCHAR   *pc;                                                   //~vag2I~
	PUFILEH pfh;                                                   //~vag2I~
	PULINEH plhsave;                                               //~vag2I~
	PUUNDOH puh;                                                   //~vag2I~
	PUQUEH  pqh;                                                   //~vag2I~
	PUFILEC  pfc;                                                  //~vag2R~
//*********************************                                //~vag2I~
    Ptype&=0xff;                                                   //~vag2I~
	pfc=Ppcw->UCWpfc;                                              //~vag2I~
	pfh=pfc->UFCpfh;                                               //~vag2I~
//    if (UCBITCHK(pfh->UFHflag,UFHFUNDOCTRREQ))//first after exec_file//~vag2R~
//    {                                                            //~vag2R~
//        UCBITOFF(pfh->UFHflag,UFHFUNDOCTRREQ);  //undoctr updated//~vag2R~
//        pfh->UFHundoctr++;                  //undoctr up         //~vag2R~
//        pfh->UFHupundoctr++;    //update+undo ctr                //~vag2R~
//    }                                                            //~vag2R~
    if (UCBITCHK(pfh->UFHflag6,UFHF6NOUNDO))  //skip save undo data(for ::cb)//~vag2I~
    	return 0;                                                  //~vag2I~
//  pqh=&(pfh->UFHundoque);                                        //~vag2R~
    pqh=&(pfh->UFHredoque);                                        //~vag2I~
    oldupctr=Pplh->ULHupctr;     //current                         //~vag2R~
//    if (puh=UGETQTOP(pqh),puh)                                   //~vag2R~
//    {                                                            //~vag2R~
//        lastundoctr=puh->UUHundoctr;                             //~vag2R~
//        if (pfh->UFHundoctr!=lastundoctr        //new update llevel//~vag2R~
//        && lastundoctr>=MAXUNDOCTR)             //saved maxlevel //~vag2R~
//        {                                   //new update data    //~vag2R~
////*free oldest uuh                                               //~vag2R~
//            freeundoctr=pfh->UFHundoctr-MAXUNDOCTR;              //~vag2R~
//            while((puh=UGETQEND(pqh))->UUHundoctr==freeundoctr)//same level//~vag2R~
//                freeundoent(UDEQ(UQUE_END,pqh,0));  //free entry //~vag2R~
//        }//level changed and reached maxlevel                    //~vag2R~
//    }//not first time                                            //~vag2R~
//  puh=UALLOCC(1,UUNDOHSZ);                                       //~vag2R~
    puh=umalloc(UUNDOHSZ);                                         //~vag2I~
    UALLOCCHK(puh,UALLOC_FAILED);                                  //~vag2I~
//    memcpy(puh->UUHcbid,UUHCBID,4);                              //~vag2R~
//    puh->UUHupctr=pfh->UFHupctr;                                 //~vag2R~
//    puh->UUHundoctr=pfh->UFHundoctr;                             //~vag2R~
//    puh->UUHplh=Pplh;                   //inserted plh           //~vag2R~
//    puh->UUHtype=(UCHAR)Ptype;                                   //~vag2R~
    memcpy(puh,Ppuh,UUNDOHSZ);                                     //~vag2I~
	UCBITON(puh->UUHflag2,UUHF2REDO);	//redo entry               //~vag2I~
    memcpy(puh->UUHcbid,URHCBID,sizeof(puh->UUHcbid));             //~vag2I~
    memset(&puh->UUHqelem,0,sizeof(puh->UUHqelem));                //~vag2R~
//*save data                                                       //~vag2I~
	switch(Ptype)                                                  //~vag2I~
	{                                                              //~vag2I~
	case UUHTISRT:		//UUHplh:insrted                           //~vag2R~
//        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~vag2R~
//        IFDEF_SYNSUPP(xesynundoprep(0,Ptype,Ppcw,pfh,Pplh,puh)); //~vag2R~
		puh->UUHplh=UGETQPREV(Pplh);		//insert after when undo//~vag2I~
		puh->UUHplhsave=Pplh;				//inserted             //~vag2R~
		break;                                                     //~vag2I~
	case UUHTDEL:		//UUHplh:prev,UUHplhsave=deleted           //~vag2R~
//        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~vag2R~
//        pfh->UFHplhlcmdi=0;     //protect undoed data cause continued lcmd isrt//~vag2R~
//        puh->UUHplh=UGETQPREV(Pplh);        //insert after when undo//~vag2R~
//        puh->UUHplhsave=Pplh;               //old data plh       //~vag2R~
//        IFDEF_SYNSUPP(xesynundoprep(0,Ptype,Ppcw,pfh,Pplh,puh)); //~vag2R~
//                                                                 //~vag2R~
//        if (UCBITCHK(Pplh->ULHflag,ULHFLINECMD))//clear line cmd input//~vag2R~
//        {                                                        //~vag2R~
//            memset(Pplh->ULHlinecmd,0,sizeof(Pplh->ULHlinecmd)); //~vag2R~
//            UCBITOFF(Pplh->ULHflag,ULHFLINECMD|ULHFLCMDERR);//clear line cmd input//~vag2R~
//            undoclearplcmd(pfh,Pplh);//*clear lcmd list when registered//~vag2R~
//        }                                                        //~vag2R~
//        UDEQ(UQUE_ENT,0,Pplh);              //delete             //~vag2R~
//     if (UCBITCHK(Pplh->ULHflag2,ULHF2INSERT) && oldupctr==pfh->UFHupctr)//~vag2R~
//        undosetdeletedflag(pfh,puh,Pplh);                        //~vag2R~
        break;                                                     //~vag2R~
	case UUHTCIDCLEAR:  					//cid clear/shift      //~vag2I~
	case UUHTREPRENUM:						//spf chng err->ok     //~vag2I~
	case UUHTREPRENUMCLR:					//num clear cmd        //~vag2I~
	case UUHTREP:			//UUHplh=updated line, UUHplhsave=copy of plh+data+dbcs//~vag2R~
//        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~vag2R~
		len=Pplh->ULHlen;                                          //~vag2I~
        if (Pplh->ULHdbcs)                                         //~vag2I~
		{                                                          //~vag2I~
//  		pc=UALLOCM((UINT)(ULINEHSZ+len+len));//plh,data,dbcs   //~vag2I~//~vb2DR~
    		pc=UALLOCM((UINT)((int)ULINEHSZ+len+len));//plh,data,dbcs//~vb2DR~
			UCBITON(puh->UUHflag,UUHFDBCS);	//dbcs tbl save falg   //~vag2I~
		}                                                          //~vag2I~
        else                                                       //~vag2I~
//  		pc=UALLOCM((UINT)(ULINEHSZ+len));//plh,data            //~vag2I~//~vb2DR~
    		pc=UALLOCM((UINT)((int)ULINEHSZ+len));//plh,data       //~vb2DR~
        if (!pc)                                                   //~vag2I~
        {                                                          //~vag2I~
        	ufree(puh);                                            //~vag2I~
            return UALLOC_FAILED;                                  //~vag2I~
        }                                                          //~vag2I~
		puh->UUHplhsave=plhsave=(PVOID)pc;                         //~vag2I~
		memcpy(plhsave,Pplh,sizeof(ULINEH));                       //~vag2I~
		memset(&plhsave->ULHqelem,0,sizeof(plhsave->ULHqelem));    //~vag2I~
		memset(plhsave->ULHlinecmd,0,sizeof(plhsave->ULHlinecmd)); //~vag2I~
		UCBITOFF(plhsave->ULHflag,ULHFLINECMD|ULHFLCMDERR);//clear line cmd input//~vag2I~
		memcpy(pc+ULINEHSZ,Pplh->ULHdata,(UINT)len);//save data    //~vag2I~
        if (Pplh->ULHdbcs)                                         //~vag2I~
			memcpy(pc+ULINEHSZ+len,Pplh->ULHdbcs,(UINT)len);//save dbcs//~vag2I~
		plhsave->ULHdata=plhsave->ULHdbcs=0;//avoid free           //~vag2I~
//        if (Ptype!=UUHTREPRENUM)    //cid clear/shift            //~vag2R~
//        {                                                        //~vag2R~
//            if (UCBITCHK(Pplh->ULHflag,ULHF4REPRENUM))//update is renum only//~vag2R~
//            {                                                    //~vag2R~
//                UCBITON(puh->UUHflag,UUHFREPRENUM);     //recover to ON at undo//~vag2R~
//                UCBITOFF(Pplh->ULHflag,ULHF4REPRENUM);  //reset renum only//~vag2R~
//            }                                                    //~vag2R~
//        }                                                        //~vag2R~
//        if (Ptype==UUHTREPRENUM)    //renum changed err to ok?   //~vag2R~
//        {                                                        //~vag2R~
//            if (                                                 //~vag2R~
//                !oldupctr //not yet updated                      //~vag2R~
//            &&  Ppcw->UCWreason         //parm from filerenum:renum only of valid spf number//~vag2R~
//               )                                                 //~vag2R~
//                    UCBITON(Pplh->ULHflag4,ULHF4REPRENUM);//update is reprenum only//~vag2R~
//            if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMERR))          //~vag2R~
//                UCBITON(puh->UUHflag,UUHFSETSPFOK);              //~vag2R~
//            if (UCBITCHK(pfh->UFHflag5,UFHF5NUMCLEARED)) //1st time num clear//~vag2R~
//            {                                                    //~vag2R~
//                UCBITOFF(pfh->UFHflag5,UFHF5NUMCLEARED);         //~vag2R~
//                UCBITON(puh->UUHflag,UUHFNUMCLEAR);              //~vag2R~
//            }                                                    //~vag2R~
//        }                                                        //~vag2R~
//        else                                                     //~vag2R~
//        if (Ptype==UUHTREPRENUMCLR) //renum changed err to ok?   //~vag2R~
//        {                                                        //~vag2R~
//            if (!UCBITCHK(pfh->UFHflag5,UFHF5NUMCLEARED)) //1st time num clear//~vag2R~
//            {                                                    //~vag2R~
//                UCBITON(pfh->UFHflag5,UFHF5NUMCLEARED);          //~vag2R~
//                UCBITON(puh->UUHflag,UUHFNUMCLEAR);              //~vag2R~
//            }                                                    //~vag2R~
//        }                                                        //~vag2R~
//        else                                                     //~vag2R~
//        if (Ptype==UUHTCIDCLEAR)                                 //~vag2R~
//            if (!oldupctr) //not yet updated                     //~vag2R~
//                UCBITON(Pplh->ULHflag,ULHFCIDCLEAR);//for cir "R"//~vag2R~
        IFDEF_SYNSUPP(xesynundoprep(0,Ptype,Ppcw,pfh,Pplh,puh)); //ULHcid=0 to avoid ufree//~vag2R~
		break;                                                     //~vag2I~
	case UUHTXON:							//exclude flag on      //~vag2I~
//        UCBITON(Pplh->ULHflag2,ULHF2EXCLUDED);                   //~vag2R~
		break;                                                     //~vag2I~
	case UUHTXOFF:							//exclude flag off     //~vag2I~
//        UCBITOFF(Pplh->ULHflag2,ULHF2EXCLUDED);                  //~vag2R~
		break;                                                     //~vag2I~
	case UUHTXSUFFIX:						//suffix change        //~vag2I~
	case UUHTXSUFFIX2:						//spf suffix overflow line//~vag2I~
        puh->UUHctrsave=Pplh->ULHsuffix;        //save suffix      //~vag2R~
        puh->UUHlongsave=Pplh->ULHlinenor;  //save lineno          //~vag2R~
        if (Ptype==UUHTXSUFFIX2)                                   //~vag2R~
        {                                                          //~vag2I~
            if (!UCBITCHK(Pplh->ULHflag4,ULHF4SETSPFVER2))  //1st time//~vag2R~
                UCBITON(puh->UUHflag,UUHFSETSPFVER2);   //reset when undo//~vag2R~
            else                                                   //~vag2I~
                UCBITOFF(puh->UUHflag,UUHFSETSPFVER2);   //reset when undo//~vag2I~
        }                                                          //~vag2I~
		break;                                                     //~vag2I~
	case UUHTSPFVER:    					//versionno chng       //~vag2I~
        puh->UUHspfver=Pplh->ULHspfver;     //save version         //~vag2R~
        puh->UUHctrsave=oldupctr;   //original upctr               //~vag2R~
//        if (!oldupctr) //not yet updated                         //~vag2R~
//        {                                                        //~vag2R~
//            UCBITON(Pplh->ULHflag3,ULHF3SETSPFVER);              //~vag2R~
//            UCBITON(puh->UUHflag,UUHFSETSPFVER);    //reset when undo//~vag2R~
//        }                                                        //~vag2R~
		break;                                                     //~vag2I~
	case UUHTSPFVERMAX:    					//pfh version no chng  //~vag2I~
        puh->UUHspfver=pfh->UFHspfver;  //max value before undo    //~vag2R~
		break;                                                     //~vag2I~
	case UUHTWIDTH:        					//bin file width changed//~vag2I~
//      puh->UUHlongsave2=((ULONG)(pfh->UFHwidth)<<16)|(pfh->UFHmergin);    //width and mergin//~vag2R~//~vb2ER~
        puh->UUHlongsave2=(FILESZT)(((ULONG)(pfh->UFHwidth)<<16)|(pfh->UFHmergin));    //width and mergin//~vb2EI~
        puh->UUHlongsave=UCBITCHK(pfh->UFHflag4,UFHF4WIDTH)!=0;     //width parm flag//~vag2R~
		break;                                                     //~vag2I~
	case UUHTXLINENO:						//excluded lineno change//~vag2I~
        puh->UUHctrsave=(int)Pplh->ULHlinenow;  //save excluded lineno//~vag2R~
        if (UCBITCHK(Pplh->ULHflag4,ULHF4XSAMEHDR)) //reset prev hdr//~vag2R~
            UCBITON(puh->UUHflag,UUHFXSAME);                       //~vag2R~
        else                                                       //~vag2R~
            UCBITOFF(puh->UUHflag,UUHFXSAME);                      //~vag2R~
		break;                                                     //~vag2I~
	case UUHTRENUM:  						//excluded lineno change//~vag2I~
        puh->UUHctrsave2=Pplh->ULHsuffix;   //save suffix          //~vag2R~
        puh->UUHctrsave=oldupctr;   //original upctr               //~vag2R~
        puh->UUHlongsave=Pplh->ULHlinenor;  //save suffix          //~vag2R~
        puh->UUHlongsave2=Pplh->ULHoffs;    //save line offset for hex lineno//~vag2R~
//        if (!oldupctr) //not yet updated                         //~vag2R~
//        {                                                        //~vag2R~
//            UCBITON(Pplh->ULHflag3,ULHF3SETSPFVER);              //~vag2R~
//            UCBITON(puh->UUHflag,UUHFSETSPFVER);    //reset when undo//~vag2R~
//        }                                                        //~vag2R~
		break;                                                     //~vag2I~
	case UUHTCUTOFF:    					//cut split line       //~vag2I~
//        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~vag2R~
//        IFDEF_SYNSUPP(xesynundoprep(0,Ptype,Ppcw,pfh,Pplh,puh)); //~vag2R~
        puh->UUHctrsave=oldupctr;   //restore at undo              //~vag2R~
        if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1))                  //~vag2R~
            UCBITON(puh->UUHflag2,UUHF2SPLIT1);                    //~vag2R~
        else                                                       //~vag2I~
            UCBITOFF(puh->UUHflag2,UUHF2SPLIT1);                   //~vag2I~
        if (UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT2))                  //~vag2R~
            UCBITON(puh->UUHflag2,UUHF2SPLIT2);                    //~vag2R~
        else                                                       //~vag2I~
            UCBITOFF(puh->UUHflag2,UUHF2SPLIT2);                   //~vag2I~
		break;                                                     //~vag2I~
	case UUHTEBCSETCP:    				//EBC codepage will be changed//~vag2I~
        puh->UUHctrsave=pfh->UFHhandle; //save before undo pfh     //~vag2R~
//        if (!UCBITCHK(pfh->UFHflag11,UFHF11EBCSETCP))            //~vag2R~
//        {                                                        //~vag2R~
//            UCBITON(pfh->UFHflag11,UFHF11EBCSETCP);              //~vag2R~
//            pfh->UFHhandleorg=pfh->UFHhandle;   //save original  //~vag2R~
//        }                                                        //~vag2R~
		break;                                                     //~vag2I~
	}                                                              //~vag2I~
	UENQ(UQUE_TOP,pqh,puh);                                        //~vag2I~
	return 0;                                                      //~vag2I~
}//redoprep;                                                       //~vag2I~
//**************************************************************** //~vag2I~
//*redo file,from xefunc2                                          //~vag2R~
//**************************************************************** //~vag2I~
int undo_redo(PUCLIENTWE Ppcw)                                     //~vag2R~
{                                                                  //~vag2I~
	int     curundoctr,upctr=0,len,upundoctr;                      //~vag2I~
//    int ii;                                                      //~vag2R~
//  int opdno/*,opid,freesw=0,rc*/;                                //~vak5R~
    int obuffl;                                                    //~vag2I~
//    int  lcmdsw;                                                 //~vag2R~
    int  lcmdsw;                                                   //~vb85I~
	UCHAR   *pc,*pcr1,*pcr2=0;                                     //~vag2I~
	PUFILEC pfc;                                                   //~vag2I~
	PUFILEH pfh;                                                   //~vag2I~
	PULINEH plh,plhsave,plh1st=0;                                  //~vag2I~
	PUUNDOH puh;                                                   //~vag2I~
	PUQUEH  pqh;	//uuh que                                      //~vag2I~
    UCHAR msgtype=0,maxver=0;                                      //~vag2I~
    UCHAR uhtype;                                                  //~vag2I~
    int handle=0,oldhandle;                                        //~vag2I~
//static char Swordtbl[]="FREE\0";                                 //~vag2R~
//*********************************                                //~vag2I~
	pfc=Ppcw->UCWpfc;                                              //~vag2I~
	pfh=pfc->UFCpfh;                                               //~vag2I~
                                                                   //~vag2I~
	if (Ppcw->UCWkeytype==UCWKTCMD	//cmdline input                //~vag2I~
	&&  Ppcw->UCWparm)	//input on cmdline                         //~vag2I~
    {                                                              //~vag2I~
//  	opdno=Ppcw->UCWopdno;           //funccmd created already  //~vak5R~
    	pc=Ppcw->UCWopdpot;                                        //~vag2I~
//        for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)   //next operand addr//~vag2R~
//        {                                                        //~vag2R~
//            switch(opid=wordtblisrch(pc,Swordtbl),opid)          //~vag2R~
//            {                                                    //~vag2R~
//            case 1: //FREE                                       //~vag2R~
//                freesw=1;                                        //~vag2R~
//                break;                                           //~vag2R~
//            default: //0:err                                     //~vag2R~
//                return errinvalid(pc);                           //~vag2R~
//            }//for                                               //~vag2R~
//        }//for                                                   //~vag2R~
//        rc=0;                                                    //~vag2R~
//        if (freesw)                                              //~vag2R~
//        {                                                        //~vag2R~
//            pqh=&pfh->UFHundoque;                                //~vag2R~
//            puh=UGETQTOP(pqh);                                   //~vag2R~
//            if (!puh)                                            //~vag2R~
//            {                                                    //~vag2R~
//                uerrmsg("No update data",                        //~vag2R~
//                "更新データがありません");                       //~vag2R~
//                return 4;                                        //~vag2R~
//            }                                                    //~vag2R~
//            undofreeuuh(pfh);                                    //~vag2R~
//            uerrmsg("update level %d undo data is freed.",       //~vag2R~
//                    "更新レベル %d 以前のundoデータは削除されました。",//~vag2R~
//                    pfh->UFHundoctr);                            //~vag2R~
//        }//free                                                  //~vag2R~
//        return rc;                                               //~vag2R~
          return errinvalid(pc);                                   //~vag2I~
    }//cmdline input                                               //~vag2I~
                                                                   //~vag2I~
	UCBITON(pfh->UFHflag,UFHFUPCTRREQ|UFHFUNDOCTRREQ);             //~vag2I~
//  if (!(puh=UGETQTOP(pqh=&(pfh->UFHundoque))))                   //~vag2R~
    if (!(puh=UGETQTOP(pqh=&(pfh->UFHredoque))))                   //~vag2I~
	{                                                              //~vag2I~
//  	uerrmsg("No update data",                                  //~vag2R~
//  			"更新データがありません");                         //~vag2R~
    	uerrmsg("No redo data",                                    //~vag2I~
    			"redo データがありません");                        //~vag2I~
		return 4;                                                  //~vag2I~
	}                                                              //~vag2I~
	curundoctr=pfh->UFHundoctr;                                    //~vag2I~
	upundoctr=++pfh->UFHupundoctr;  //update+undo ctr for reverse  //~vag2I~
//*confirmation                                                    //~vag2I~
	if (Ppcw->UCWkeytype!=UCWKTCMD	//func key not cmdline input   //~vag2I~
	&&  !scrconfirmchk(GSCRCONFUNDO))//not yet confirmed           //~vag2I~
	{                                                              //~vag2I~
//search first operation                                           //~vag2I~
		while(puh)                                                 //~vag2I~
		{                                                          //~vag2I~
//  		if (puh->UUHundoctr!=curundoctr)                       //~vag2R~
    		if (puh->UUHundoctr!=curundoctr+1)                     //~vag2I~
				break;                                             //~vag2I~
            if (msgtype==UUHTEBCSETCP)  //multiple entry if not "ebc setcp" cmd but "cv setcp" cmd.//~vag2I~
                msgtype=0;                                         //~vag2I~
			plh=puh->UUHplh;			//corresponding ULINEH     //~vag2I~
			uhtype=puh->UUHtype;                                   //~vag2I~
			switch(uhtype)                                         //~vag2I~
			{                                                      //~vag2I~
			case UUHTISRT:  //UUHplh:prev, UUHplhsave:inserted     //~vag2R~
				UCBITON(plh->ULHflag,ULHFDRAW);                    //~vag2I~
//            if (!UCBITCHK(puh->UUHflag2,UUHF2DELETED))           //~vag2R~
           	if (!plh1st)          //redo que is lineno ascendant   //~vag2I~
              if (UGETQHDR(plh))    //prev of 1st inserted of multiple inserted lines//~vag2I~
              {                                                    //~vag2I~
				plh1st=plh;			//csr move plh                 //~vag2I~
				plh1st->ULHupundoctr=upundoctr;	//current undo     //~vag2I~
              }                                                    //~vag2I~
				break;                                             //~vag2I~
			case UUHTDEL:   //UUHplh:prev, UUHplhsave:deleted      //~vag2R~
//  			plh1st=puh->UUHplh;		//csr move to prev of deleted//~vag2R~
              if (!plh1st)          //redo que is lineno ascendant //~vag2I~
	    		plh1st=puh->UUHplhsave;	//1st(last of que) deleted line//~vag2I~
				break;                                             //~vag2I~
			case UUHTSPFVER:		//version change               //~vag2I~
			case UUHTCIDCLEAR:  					//cid clear/shift//~vag2I~
			case UUHTREPRENUM:                                     //~vag2I~
			case UUHTREPRENUMCLR:                                  //~vag2I~
			case UUHTREP:			//UUHplh=updated line, UUHplhsave=copy of plh+data+dbcs//~vag2I~
				UCBITON(plh->ULHflag,ULHFDRAW);                    //~vag2I~
              if (!plh1st)          //redo que is lineno ascendant //~vag2I~
				plh1st=plh;			//csr move plh                 //~vag2I~
//  			plh1st->ULHupundoctr=upundoctr;	//current undo result line//~vag2R~
    			plh->ULHupundoctr=upundoctr;	//current undo result line//~vag2I~
                if (uhtype==UUHTREPRENUM)                          //~vag2I~
	                if (UCBITCHK(puh->UUHflag,UUHFSETSPFOK))       //~vag2I~
		                msgtype=UUHTREPRENUM;                      //~vag2I~
				break;                                             //~vag2I~
			case UUHTSPFVERMAX:		//version change               //~vag2I~
            	msgtype=UUHTSPFVERMAX;                             //~vag2I~
	            maxver=puh->UUHspfver;//restore max version        //~vag2I~
				break;                                             //~vag2I~
			case UUHTXON:                                          //~vag2I~
              	if (!plh1st)          //redo que is lineno ascendant//~vag2I~
					plh1st=plh;			//csr move plh             //~vag2I~
                plh->ULHupundoctr=upundoctr; //current undo result line//~vag2I~
				break;                                             //~vag2I~
			case UUHTXOFF:                                         //~vag2I~
				UCBITON(plh->ULHflag,ULHFDRAW);                    //~vag2I~
//                plh1st=plh;         //csr move plh               //~vag2R~
//                plh1st->ULHupundoctr=upundoctr; //current undo result line//~vag2R~
				break;                                             //~vag2I~
			case UUHTXSUFFIX:		//suffix change                //~vag2I~
			case UUHTXSUFFIX2:		//suffix change                //~vag2I~
				break;                                             //~vag2I~
			case UUHTXLINENO:		//excluded lineno change       //~vag2I~
				UCBITON(plh->ULHflag,ULHFDRAW);                    //~vag2I~
              if (!plh1st)          //redo que is lineno ascendant //~vag2R~
				plh1st=plh;			//csr move plh                 //~vag2I~
//  			plh1st->ULHupundoctr=upundoctr;	//current undo result line//~vag2R~
    			plh->ULHupundoctr=upundoctr;	//current undo result line//~vag2I~
				break;                                             //~vag2I~
			case UUHTRENUM:  		//excluded lineno change       //~vag2I~
			case UUHTCUTOFF: 		//split line                   //~vag2I~
              if (!plh1st)          //redo que is lineno ascendant //~vag2I~
				plh1st=plh;			//csr move plh                 //~vag2I~
				UCBITON(plh->ULHflag,ULHFDRAW);                    //~vag2I~
				plh->ULHupundoctr=upundoctr;	//current undo result line//~vag2I~
				break;                                             //~vag2I~
			case UUHTEBCSETCP:  	//ebc codepage change          //~vag2I~
				handle=puh->UUHctrsave;     //handle before undo   //~vag2R~
            	msgtype=UUHTEBCSETCP;                              //~vag2I~
				break;                                             //~vag2I~
			}//sw by type                                          //~vag2I~
			puh=UGETQNEXT(puh);                                    //~vag2I~
		}//	all puh                                                //~vag2I~
//set csr to 1st plh                                               //~vag2I~
		if (plh1st)	//data exist                                   //~vag2I~
			undocsrmove(Ppcw,plh1st);                              //~vag2I~
        switch(msgtype)                                            //~vag2I~
        {                                                          //~vag2I~
        case UUHTSPFVERMAX:     //version change                   //~vag2I~
//  	    uerrmsg("Version restore confirmation(%d-->%d)",       //~vag2R~
//      		    "バージョン番号が戻されます(%d-->%d)",         //~vag2R~
    	    uerrmsg("Version redo confirmation(%d-->%d)",          //~vag2R~
	      		    "バージョン番号が再設定されます(%d-->%d)",     //~vag2R~
            		pfh->UFHspfver,maxver);                        //~vag2I~
            break;                                                 //~vag2I~
        case UUHTREPRENUM:     //changed er->ok                    //~vag2R~
//  	    uerrmsg("It will back to line-no err status",          //~vag2R~
//      		    "行番号エラー状態に戻ります");                 //~vag2R~
  		    uerrmsg("Renum will be re-done",                       //~vag2I~
	      		    "Renum が再実行されます");                     //~vag2I~
            break;                                                 //~vag2I~
        case UUHTEBCSETCP:                                         //~vag2I~
//  	    uerrmsg("EBCDIC codepage will be retored to %s by the same key",//~vag2R~
//      		    "EBCDICコードページを %s に戻しますか。同じキー操作で実行。",//~vag2R~
    	    uerrmsg("EBCDIC codepage will be re-set to %s by the same key",//~vag2I~
        		    "EBCDICコードページを %s に再設定しますか。同じキー操作で実行。",//~vag2I~
					ucvebc4_getcvname(0,handle));                  //~vag2I~
            break;                                                 //~vag2I~
        default:                                                   //~vag2I~
// 		 	uerrmsg("Update level %d confirmation, execute by the same key",//~vag2R~
//  				"更新レベル %d, 操作の繰り返しにより UNDO されます",//~vag2R~
//  				pfh->UFHundoctr);	//confirmid                //~vag2I~
   		 	uerrmsg("Redo Update level %d confirmation, execute by the same key",//~vag2R~
 	  				"更新レベル %dへ, 同じキー操作で Redo されます",//~vag2R~
    				pfh->UFHundoctr+1);	//confirmid                //~vag2I~
		}                                                          //~vag2I~
		return 1;       //stay cmd on cmdline for reenter          //~vag2I~
	}                                                              //~vag2I~
//*redo                                                            //~vag2R~
	while(puh)                                                     //~vag2I~
	{                                                              //~vag2I~
//  	if (puh->UUHundoctr!=curundoctr)                           //~vag2R~
    	if (puh->UUHundoctr!=curundoctr+1)                         //~vag2I~
			break;                                                 //~vag2I~
		plh=puh->UUHplh;			//corresponding ULINEH         //~vag2I~
        uhtype=puh->UUHtype;                                       //~vag2I~
        switch(uhtype)                                             //~vag2I~
		{                                                          //~vag2I~
		case UUHTISRT:  //UUHplh:prev, UUHplhsave:inserted         //~vag2I~
//            IFDEF_SYNSUPP(xesynundo(0,uhtype,Ppcw,pfh,plh,puh)); //~vag2R~
//            pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~vag2R~
//            plh1st=UGETQPREV(plh);  //csr move                   //~vag2R~
//            if (plh->ULHtype==ULHTDATA)                          //~vag2R~
//                upctr=puh->UUHupctr;                             //~vag2R~
//            if (plh==pfc->UFCcurtop) //del current top(ptr now invalid)//~vag2R~
//                pfc->UFCcurtop=getdisplayline(plh,-1,0);         //~vag2R~
////*clear lcmd list when registered                               //~vag2R~
//            for (ii=pfh->UFHcmdlinectr-1;ii>=0;ii--)             //~vag2R~
//                if (plh==pfh->UFHcmdline[ii])                    //~vag2R~
//                    pfh->UFHcmdline[ii]=0;                       //~vag2R~
//                                                                 //~vag2R~
//            if (Gcappcw==Ppcw)                                   //~vag2R~
//                if (plh==Gcapplh1 || plh==Gcapplh2)              //~vag2R~
//                    capreset(1);//clear block define             //~vag2R~
//            if (Gcalcpcw==Ppcw)                                  //~vag2R~
//                if (plh==Gcalcplh1 || plh==Gcalcplh2)            //~vag2R~
//                    capresetcalc(Ppcw);//clear block define      //~vag2R~
//            lcmddelresetcurtop(Ppcw,plh);   //maint pfccurtop    //~vag2R~
//            filefreeplh((PULINEH)UDEQ(UQUE_ENT,0,plh),1);//free isrted//~vag2R~
            pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~vag2I~
			plhsave=puh->UUHplhsave;                               //~vag2I~
			plhsave->ULHupundoctr=upundoctr;	//current undo result line//~vag2I~
          if (!plh1st)          //redo que is lineno ascendant     //~vag2I~
			plh1st=plhsave;	//csr move                             //~vag2I~
			if (plhsave->ULHtype==ULHTDATA)                        //~vag2I~
				upctr=puh->UUHupctr;                               //~vag2I~
			UCBITOFF(plhsave->ULHflag,ULHFBLOCK);//no more effective capdbcs tbl saveed//~vag2I~
            memset(plhsave->ULHlinecmd,0,sizeof(plhsave->ULHlinecmd));//~vagxI~
            UCBITOFF(plhsave->ULHflag,ULHFLINECMD|ULHFLCMDERR);//clear line cmd input//~vagxI~
			UENQENT(UQUE_AFT,puh->UUHplh,plhsave);                 //~vag2I~
			puh->UUHplhsave=0;	//avoid free by freeundoent        //~vag2I~
			if (redo_undoupdate(Ppcw,plhsave,UUHTISRT)==UALLOC_FAILED)//for undo after redo//~vag2R~
        		return UALLOC_FAILED;                               //~v04dI~//~vag2I~
            IFDEF_SYNSUPP(xesynundo(0,uhtype,Ppcw,pfh,plhsave,puh));//~vag2I~
			break;                                                 //~vag2I~
		case UUHTDEL:   //UUHplh:prev, UUHplhsave:deleted          //~vag2I~
            pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~vag2R~
            plhsave=puh->UUHplhsave;                               //~vag2R~
            plhsave->ULHupundoctr=upundoctr;    //current undo result line//~vag2R~
//          plh1st=plhsave; //csr move                             //~vag2R~
          if (!plh1st)          //redo que is lineno ascendant     //~vag2I~
            plh1st=plh; //csr move                                 //~vag2I~
            if (plhsave->ULHtype==ULHTDATA)                        //~vag2R~
                upctr=puh->UUHupctr;                               //~vag2R~
//            UCBITOFF(plhsave->ULHflag,ULHFBLOCK);//no more effective capdbcs tbl saveed//~vag2R~
//            UENQENT(UQUE_AFT,puh->UUHplh,plhsave);               //~vag2R~
            puh->UUHplhsave=0;  //avoid free by freeundoent        //~vag2R~
//            IFDEF_SYNSUPP(xesynundo(0,uhtype,Ppcw,pfh,plhsave,puh));//~vag2R~
			if (redo_undoupdate(Ppcw,plhsave,UUHTDEL)==UALLOC_FAILED)//chain to puh//~vag2R~
        		return UALLOC_FAILED;                              //~vag2M~
			break;                                                 //~vag2I~
        case UUHTCIDCLEAR:                      //cid clear/shift  //~vag2I~
		case UUHTREPRENUM:                                         //~vag2I~
		case UUHTREPRENUMCLR:                                      //~vag2I~
		case UUHTREP:			//UUHplh=updated line, UUHplhsave=copy of plh+data+dbcs//~vag2I~
			if (redo_undoupdate(Ppcw,plh,uhtype)==UALLOC_FAILED)   //~vag2R~
        		return UALLOC_FAILED;                              //~vag2I~
	        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~vag2I~
			plhsave=puh->UUHplhsave;                               //~vag2I~
    		obuffl=plhsave->ULHbufflen;                            //~vag2I~
    		pcr1=UALLOCM((UINT)obuffl);                            //~vag2I~
            UALLOCCHK(pcr1,UALLOC_FAILED);                         //~vag2I~
			if (UCBITCHK(puh->UUHflag,UUHFDBCS))	//dbcs tbl saveed//~vag2I~
            {                                                      //~vag2I~
    			pcr2=UALLOCM((UINT)obuffl);                        //~vag2I~
                if (!pcr2)                                         //~vag2I~
                {                                                  //~vag2I~
	            	ufree(pcr1);                                   //~vag2I~
	                return UALLOC_FAILED;                          //~vag2I~
                }                                                  //~vag2I~
			}                                                      //~vag2I~
			if (plh->ULHtype==ULHTDATA)                            //~vag2I~
				upctr=puh->UUHupctr;                               //~vag2I~
			filefreeplh(plh,0);	//free data only                   //~vag2I~
//            lcmdsw=UCBITCHK(plh->ULHflag,ULHFLINECMD);//currentry lcmd active?//~vag2R~
            lcmdsw=UCBITCHK(plh->ULHflag,ULHFLINECMD);//currentry lcmd active?//~vb85I~
			memcpy(&(plh->ULHqelem)+1,                             //~vag2I~
					&(plhsave->ULHqelem)+1,                        //~vag2I~
					ULINEHSZ-UQUEESZ);	//except qelem hdr         //~vag2I~
                                                                   //~vag2I~
//            if (lcmdsw)                                          //~vag2R~
//                if (!UCBITCHK(plh->ULHflag,ULHFLINECMD))//lcmd cleared by undo//~vag2R~
//                    undoclearplcmd(pfh,plh);//*clear lcmd list when registered//~vag2R~
            if (lcmdsw)                                            //~vb85I~
                if (!UCBITCHK(plh->ULHflag,ULHFLINECMD))//lcmd cleared by undo//~vb85I~
                      undoclearplcmd(pfh,plh);//*clear lcmd list when registered//~vb85I~
                                                                   //~vag2I~
			UCBITOFF(plh->ULHflag,ULHFBLOCK);//no more effective capdbcs tbl saveed//~vag2I~
          if (!plh1st)          //redo que is lineno ascendant     //~vag2I~
			plh1st=plh;	//csr move                                 //~vag2I~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~vag2I~
			len=plh->ULHlen;                                       //~vag2I~
			pc=(PVOID)plhsave;                                     //~vag2I~
			memcpy(plh->ULHdata=pcr1,pc+ULINEHSZ,(UINT)len);       //~vag2I~
			if (UCBITCHK(puh->UUHflag,UUHFDBCS))	//dbcs tbl saveed//~vag2I~
				memcpy(plh->ULHdbcs=pcr2,pc+ULINEHSZ+len,(UINT)len);//~vag2I~
		    if (UCBITCHK(puh->UUHflag,UUHFREPRENUM))		//recover to ON at undo//~vag2I~
				UCBITON(plh->ULHflag4,ULHF4REPRENUM);	//update is renum only//~vag2I~
            if (uhtype==UUHTREPRENUM)    //renum changed err to ok?//~vag2I~
            {                                                      //~vag2I~
                if (UCBITCHK(puh->UUHflag,UUHFSETSPFOK))           //~vag2I~
                {                                                  //~vag2I~
	                msgtype=UUHTREPRENUM;                          //~vag2I~
//              	UCBITON(pfh->UFHflag2,UFHF2SPFNUMERR);         //~vag2R~
                	UCBITOFF(pfh->UFHflag2,UFHF2SPFNUMERR);        //~vag2I~
//              	UCBITOFF(pfh->UFHflag2,UFHF2SPFNUMOK);         //~vag2R~
                	UCBITON(pfh->UFHflag2,UFHF2SPFNUMOK);          //~vag2I~
				}                                                  //~vag2I~
                if (UCBITCHK(puh->UUHflag,UUHFNUMCLEAR)) //renum changed cleared//~vag2I~
//                  UCBITON(pfh->UFHflag5,UFHF5NUMCLEARED); //back to no autonum mode//~vag2R~
                    UCBITOFF(pfh->UFHflag5,UFHF5NUMCLEARED); //back to no autonum mode//~vag2I~
            }                                                      //~vag2I~
            if (uhtype==UUHTREPRENUMCLR)    //renum changed err to ok?//~vag2I~
            {                                                      //~vag2I~
                if (UCBITCHK(puh->UUHflag,UUHFNUMCLEAR))           //~vag2I~
//                  UCBITOFF(pfh->UFHflag5,UFHF5NUMCLEARED); //back to autonum mode//~vag2R~
                    UCBITON(pfh->UFHflag5,UFHF5NUMCLEARED); //back to autonum mode//~vag2I~
            }                                                      //~vag2I~
        	IFDEF_SYNSUPP(xesynundo(0,uhtype,Ppcw,pfh,plh,puh));   //~vag2I~
			break;                                                 //~vag2I~
		case UUHTXON:                                              //~vag2I~
			if (redo_undoprep(Ppcw,plh,uhtype)==UALLOC_FAILED)     //~vag2R~
        		return UALLOC_FAILED;                              //~vag2I~
//            plh1st=plh; //csr move                               //~vag2R~
//            plh->ULHupundoctr=upundoctr;    //current undo result line//~vag2R~
//  		UCBITOFF(puh->UUHplh->ULHflag2,ULHF2EXCLUDED);         //~vag2R~
    		UCBITON(puh->UUHplh->ULHflag2,ULHF2EXCLUDED);          //~vag2I~
			break;                                                 //~vag2I~
		case UUHTXOFF:                                             //~vag2I~
			if (redo_undoprep(Ppcw,plh,uhtype)==UALLOC_FAILED)     //~vag2R~
        		return UALLOC_FAILED;                              //~vag2I~
          if (!plh1st)          //redo que is lineno ascendant     //~vag2I~
			plh1st=plh;	//csr move                                 //~vag2I~
//  		UCBITON(puh->UUHplh->ULHflag2,ULHF2EXCLUDED);          //~vag2R~
    		UCBITOFF(puh->UUHplh->ULHflag2,ULHF2EXCLUDED);         //~vag2I~
			break;                                                 //~vag2I~
		case UUHTXSUFFIX:		//suffix change                    //~vag2I~
		case UUHTXSUFFIX2:		//suffix change                    //~vag2I~
			puh->UUHplh->ULHsuffix=puh->UUHctrsave;	//restore old value//~vag2I~
			plh->ULHlinenor=puh->UUHlongsave;//restore old value   //~vag2I~
          if (uhtype==UUHTXSUFFIX2)                                //~vag2R~
          {                                                        //~vag2I~
            if (UCBITCHK(puh->UUHflag,UUHFSETSPFVER2))	//suffix overflow for spf//~vag2I~
        		UCBITOFF(plh->ULHflag4,ULHF4SETSPFVER2);           //~vag2I~
            else                                                   //~vag2I~
        		UCBITON(plh->ULHflag4,ULHF4SETSPFVER2);            //~vag2I~
          }                                                        //~vag2I~
			break;                                                 //~vag2I~
		case UUHTSPFVER:		//version change                   //~vag2I~
			if (redo_undoupdate(Ppcw,plh,UUHTSPFVER)==UALLOC_FAILED)//chain to puh//~vag2R~
        		return UALLOC_FAILED;                              //~vag2M~
			upctr=puh->UUHupctr;                                   //~vag2I~
          if (!plh1st)          //redo que is lineno ascendant     //~vag2I~
			plh1st=plh;	//csr move                                 //~vag2I~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~vag2I~
                                                                   //~vag2I~
			plh->ULHspfver=puh->UUHspfver;	//restore old value    //~vag2I~
			plh->ULHupctr=puh->UUHctrsave;	//restore old value    //~vag2I~
//            if (UCBITCHK(puh->UUHflag,UUHFSETSPFVER))   //reset when undo//~vag2R~
//                UCBITOFF(plh->ULHflag3,ULHF3SETSPFVER); //reset when undo//~vag2R~
	        filesetvernum(pfh,plh);                                //~vag2I~
			break;                                                 //~vag2I~
		case UUHTSPFVERMAX:		//undo pfh spfver                  //~vag2I~
            msgtype=UUHTSPFVERMAX;                                 //~vag2I~
            maxver=pfh->UFHspfver;//current value                  //~vag2I~
			if (redo_undoprep(Ppcw,plh,UUHTSPFVERMAX)==UALLOC_FAILED)//chain to puh//~vag2R~
        		return UALLOC_FAILED;                              //~vag2I~
			pfh->UFHspfver=puh->UUHspfver;//restore max version    //~vag2I~
			break;                                                 //~vag2I~
		case UUHTWIDTH:        					//bin file width changed//~vag2I~
			pfh->UFHwidth=(USHORT)(puh->UUHlongsave2>>16);         //~vag2I~
			pfh->UFHmergin=(USHORT)(puh->UUHlongsave2 & 0xffff);   //~vag2I~
			if (puh->UUHlongsave)                                  //~vag2I~
				UCBITON(pfh->UFHflag4,UFHF4WIDTH);     //width parm flag//~vag2I~
            else                                                   //~vag2I~
				UCBITOFF(pfh->UFHflag4,UFHF4WIDTH);     //width parm flag//~vag2I~
			break;                                                 //~vag2I~
		case UUHTXLINENO:		//excluded lineno change           //~vag2I~
			if (redo_undoprep(Ppcw,plh,uhtype)==UALLOC_FAILED)//chain to puh//~vag2I~
        		return UALLOC_FAILED;                              //~vag2I~
          if (!plh1st)          //redo que is lineno ascendant     //~vag2I~
			plh1st=plh;	//csr move                                 //~vag2I~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~vag2I~
			puh->UUHplh->ULHlinenow=puh->UUHctrsave;//restore old value//~vag2I~
        	if (UCBITCHK(puh->UUHflag,UUHFXSAME))                  //~vag2I~
        		UCBITON(plh->ULHflag4,ULHF4XSAMEHDR);              //~vag2I~
            else                                                   //~vag2I~
        		UCBITOFF(plh->ULHflag4,ULHF4XSAMEHDR);             //~vag2I~
        	UCBITOFF(puh->UUHflag,UUHFXSAME);                      //~vag2I~
			lcmdeditxline(puh->UUHplh);//edit lineno               //~vag2I~
			break;                                                 //~vag2I~
		case UUHTRENUM:  		//renum undo                       //~vag2I~
			upctr=puh->UUHupctr;                                   //~vag2I~
          if (!plh1st)          //redo que is lineno ascendant     //~vag2I~
			plh1st=plh;	//csr move                                 //~vag2I~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~vag2I~
			plh->ULHlinenor=puh->UUHlongsave;//restore old value   //~vag2I~
			plh->ULHoffs=puh->UUHlongsave2;//restore line hex offset//~vag2I~
			plh->ULHsuffix=puh->UUHctrsave2;//restore old value    //~vag2I~
			plh->ULHupctr=puh->UUHctrsave;	//restore old value    //~vag2I~
            if (UCBITCHK(puh->UUHflag,UUHFSETSPFVER))	//reset when undo//~vag2I~
            	UCBITOFF(plh->ULHflag3,ULHF3SETSPFVER);	//reset when undo//~vag2I~
            if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK))             //~vag2I~
	            filespfnumedit(pfh,plh,1);//setup num field,ver from plh//~vag2I~
			break;                                                 //~vag2I~
        case UUHTCUTOFF:                        //cut split line   //~vag2I~
			if (redo_undoupdate(Ppcw,plh,uhtype)==UALLOC_FAILED)//chain to puh//~vag2R~
        		return UALLOC_FAILED;                              //~vag2I~
	        pfh->UFHmaxlrecl=0;     //re-calc required by fsubgetmaxlen//~vag2I~
			upctr=puh->UUHupctr;                                   //~vag2I~
			plh->ULHupctr=puh->UUHctrsave;	//restore old value    //~vag2I~
			plh->ULHupundoctr=upundoctr;	//current undo result line//~vag2I~
          if (!plh1st)          //redo que is lineno ascendant     //~vag2I~
			plh1st=plh;	//csr move                                 //~vag2I~
            if (UCBITCHK(puh->UUHflag2,UUHF2SPLIT1))               //~vag2I~
            	UCBITON(plh->ULHflag2,ULHF2SPLIT1);                //~vag2I~
            else                                                   //~vag2I~
            	UCBITOFF(plh->ULHflag2,ULHF2SPLIT1);               //~vag2I~
            if (UCBITCHK(puh->UUHflag2,UUHF2SPLIT2))               //~vag2I~
            	UCBITON(plh->ULHflag2,ULHF2SPLIT2);                //~vag2I~
            else                                                   //~vag2I~
            	UCBITOFF(plh->ULHflag2,ULHF2SPLIT2);               //~vag2I~
        	IFDEF_SYNSUPP(xesynundo(0,uhtype,Ppcw,pfh,plh,puh));   //~vag2I~
            break;                                                 //~vag2I~
        case UUHTSPFERR:                        //set spf err      //~vag2I~
//      	UCBITON(pfh->UFHflag2,UFHF2SPFNUMOK);                  //~vag2R~
//      	UCBITOFF(pfh->UFHflag2,UFHF2SPFNUMERR);                //~vag2R~
        	UCBITOFF(pfh->UFHflag2,UFHF2SPFNUMOK);                 //~vag2I~
        	UCBITON(pfh->UFHflag2,UFHF2SPFNUMERR);                 //~vag2I~
            break;                                                 //~vag2I~
        case UUHTEBCSETCP:                                         //~vag2I~
			if (redo_undoprep(Ppcw,plh,uhtype)==UALLOC_FAILED)//chain to puh//~vag2R~
        		return UALLOC_FAILED;                              //~vag2I~
        	oldhandle=pfh->UFHhandle;                              //~vag2I~
        	pfh->UFHhandle=puh->UUHctrsave; //handle before undo   //~vag2R~
			fsubresetebcdbcstbl(0,oldhandle,Ppcw,pfh);             //~vag2I~
            opt2setebccvname(0,pfh);                               //~vag2I~
            break;                                                 //~vag2I~
		}                                                          //~vag2I~
		freeundoent(UDEQ(UQUE_TOP,pqh,puh));                       //~vag2I~
		puh=UGETQTOP(pqh);                                         //~vag2I~
	}//all puh                                                     //~vag2I~
//*csr move                                                        //~vag2I~
	if (plh1st)	//data exist                                       //~vag2I~
		undocsrmove(Ppcw,plh1st);                                  //~vag2I~
                                                                   //~vag2I~
    filesetmultdraw(Ppcw);	//all client draw of same file         //~vag2I~
//    if (pfh->UFHundoctr)                                         //~vag2R~
//        --pfh->UFHundoctr;      //                               //~vag2R~
//* ++UFHundoctr by redo_undoupdate() call++                       //~vag2R~
	if (upctr)		//upctr restore                                //~vag2I~
//  	pfh->UFHupctr=upctr-1;                                     //~vag2R~
    	pfh->UFHupctr=upctr;                                       //~vag2I~
//    if (pfh->UFHupctrsave)      //once saved                     //~vag2R~
//        pfh->UFHupctrsave=-1;       //trace of once updated to accept writeback//~vag2R~
    switch(msgtype)                                                //~vag2I~
    {                                                              //~vag2I~
    case UUHTSPFVERMAX:     //version change                       //~vag2I~
//      uerrmsg("Version restore(%d-->%d)",                        //~vag2R~
//              "バージョン番号が戻されました(%d-->%d)",           //~vag2R~
        uerrmsg("Version re-set(%d<--%d)",                         //~vag2I~
                "バージョン番号が再設定されました(%d-->%d)",       //~vag2R~
                maxver,pfh->UFHspfver);                            //~vag2I~
        break;                                                     //~vag2I~
    case UUHTREPRENUM:     //changed er->ok                        //~vag2I~
//      uerrmsg("Backed to line-no err status",                    //~vag2R~
//              "行番号エラー状態に戻りました");                   //~vag2R~
        uerrmsg("Renum was re-done",                               //~vag2I~
                "Renum が再実行されました");                       //~vag2I~
        break;                                                     //~vag2I~
    default:                                                       //~vag2I~
//  uerrmsg("Backed to update level %d",                           //~vag2R~
//  		"更新レベル %d に戻りました",                          //~vag2R~
  		uerrmsg("Update level was upped to %d by Redo",            //~vag2R~
    			"Redoで更新レベルが %d に Up しました",            //~vag2R~
			pfh->UFHundoctr);                                      //~vag2I~
	}                                                              //~vag2I~
	return 0;                                                      //~vag2I~
}//undo_redo                                                       //~vag2R~
//***************************************************************  //~vag2I~
//*undo prepare by redo                                            //~vag2I~
//***************************************************************  //~vag2I~
int redo_undoupdate(PUCLIENTWE Ppcw,PULINEH Pplh,int Ptype)        //~vag2R~
{                                                                  //~vag2I~
	int rc;                                                        //~vag2I~
//*****************                                                //~vag2I~
    Sswredoundo=1;    //not from redo                              //~vag2I~
	rc=undoupdate(Ppcw,Pplh,Ptype);                                //~vag2I~
    Sswredoundo=0;    //not from redo                              //~vag2I~
    return rc;                                                     //~vag2I~
}//redo_undo                                                       //~vag2I~
//***************************************************************  //~vag2I~
//*undo prepare by redo                                            //~vag2I~
//***************************************************************  //~vag2I~
int redo_undoprep(PUCLIENTWE Ppcw,PULINEH Pplh,int Ptype)          //~vag2I~
{                                                                  //~vag2I~
	int rc;                                                        //~vag2I~
//*****************                                                //~vag2I~
    Sswredoundo=1;    //not from redo                              //~vag2I~
	rc=undoprep(Ppcw,Pplh,Ptype);                                  //~vag2I~
    Sswredoundo=0;    //not from redo                              //~vag2I~
    return rc;                                                     //~vag2I~
}//redo_undo                                                       //~vag2I~
#else //!REDO                                                      //~vag2I~
int undo_redo(PUCLIENTWE Ppcw)                                     //~vag2I~
{                                                                  //~vag2I~
    return 0;                                                      //~vag2I~
}                                                                  //~vag2I~
#endif                                                             //~vag2I~
