//*CID://+vbq0R~:                             update#=  263;       //+vbq0R~
//*************************************************************
//*xechar2.c
//* del/bs/erase eol/erase tol/clear tol/split line/tab insert  //~5111I~
//*******************************************************************//~v07sI~
//vbq0:200418 del excluded by S+Del                                //+vbq0I~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa7I~
//va8i:101011 bnds sort;add SBCS option for BNDS sort without dbcs consideration//~va8iI~
//va8h:101010 bnds sort;set space to split dbcs except dbcs continued case//~va8hI~
//va8b:101001 dbcs consideration for C&P                           //~va8bI~
//va7y:100823 EBC:handle support for cap                           //~va7yI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3S:100322 (BUG)"S" lcmd replace split dbcs to space,it should be avoid when split on vhex line//~va3SI~
//va3K:100316 allow unicode hex input on cmdline                   //~va3KI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va2i:100101 (BUG)cap cause dbcs split at margin boundary(rep mode set dbcs1st only)//~va2iI~
//va2h:091225 (BUG)inserted tab by charcap2 is not expanded; -->clear tab after rep/ins//~va2hR~
//va27:091211 (BUG)splitctr when used on not dbcspoint(BUG at DBCS env only)//~va27I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            char2.c :cap betwenn utf8 and nonutf8                //~va20I~
//va1q:091107 compchkm                                             //~va1qI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//v78S:080606**continued insert line mode by lcmd "i" and S_INS,opt INS_LINE//~v78SI~
//v8@2:080529 save tabctr in profile                               //~v8@2I~
//v77d:071222 (BUG)"copy on" left unpredictable char value when source dbcs split case//~v77dI~
//v76V:071105*(BUG)invalid access by BS when csr is on cmd line if hex mode(abend when utf8 mode)//~v76VI~
//v76M:070915*(BUG)S+Enter(split line) on vhexline change to space split dbcs//~v76MI~
//v74H:070324*(BUG of v74E)half dbcs remains when paste-insert     //~v74HI~
//v74E:070315 BOUNDS cmd support(find,shift-lcmd,paste-lcmd)       //~v74EI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v74q:070218 (BUG)cob margin consideration for ETOL(by C+b)       //~v74qI~
//v74k:070217 (BUG)line split shift ignored oom for except spf numok line//~v74kI~
//v74j:070216 (BUG)C&P del fail by join fail for margined file.    //~v74jI~
//            (by remaining oom of 1st line;delete oom for 1stline for region cut)//~v74jI~
//v74a:070213 (BUG)paste missing dbcs clear for padding area       //~v74aI~
//v73r:070124*(BUG)change cmd:for margined file string near margin is dropped when expand replace is absorbed by tab//~v73uI~
//v71U:061112 (BUG)accept insert in short(<mergin) record of margined file//~v71UI~
//v67V:060227 copy on/niche:reverse only updated line              //~v67VI~
//v67H:060125 (BUG)abend when copy on                              //~v67HI~
//v67B:051228 nexttab:cobol consideration stop at col7 if FCleft=6 //~v67BI~
//v676:051226 cut & paste;margined file(COBOL etc) consideration(ignore space cut by margin)//~v676I~
//v66k:051025 (BUG)charlcmdsplit should check line is to be data line//~v66kI~
//v66g:051023 tab is not cleared from the line tab is set by lcmd paste//~v66gI~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert.(split xecap.c to xecap2.c)//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnDel+Ins//~v66fI~
//v59u:041114 (BUG)hexinput:del cur pos if csr is on later half of byte//~v59uR~
//v58s:040923 niche option for copy edit cmd(n:override target line by not space char of src line)//~v58sI~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd            //~v45xI~
//v44d:011203 tab for hexdisplay                                   //~v44dI~
//v42e:010924 limit len of copy on souce to the margin limit       //~v42eI~
//            and accept v417(drop v42d)                           //~v42eI~
//v42d:010924 (BUG of v417)copy on also out of margin when not protected//~v42dI~
//v42c:010924 cobol split line,copy to after num fld               //~v42cI~
//v417:010729 allow lineno fld when not protected for spf file     //~v417I~
//v40x:010625 (BUG)invalid tab expand when split line              //~v40xI~
//v21r:010211 tabstop id on gauge                                  //~v21rI~
//v168:000418 add table format function to TC/TCN cmd              //~v168I~
//v163:000410 func to set line data from string.(reviced fro charcap(line to line)).//~v163I~
//v11q:990726 errmsg when csrpos err for shift+enter(split line) to chk shift lcmd err bug//~v119I~
//v10b:981213 (BUG)charconcatline need set returncode;if return 0; //~v10bI~
//            area destroy because buff is not expanded            //~v10bI~
//v101:981205 hex input                                            //~v101I~
//v0ji:980722 tab for key cmd(0.1)                                 //~v0jiI~
//v0ja:980721 change define value by change opt start from 0.0     //~v0jaI~
//v0j0:980720 (BUG of v06a)prevtab of HDR line shoud be end of line//~v0j0I~
//v0iz:980720 tab for change key assign screen                     //~v0izI~
//v0ih:980621 pfk cmd support(input protect)                       //~v0ihI~
//v0i7:980520 line cmd split cmd('S')/join('J') support            //~v0i7I~
//v0eI:970927 margin and copy on/paste                             //~v0eII~
//            for SPFERR/SPFOK file;oom update prohibit            //~v0eII~
//            for mergined file;avail over mergin line if not protected//~v0eII~
//v0ez:970920 v0ep to charcap insert                               //~v0eiI~
//v0ei:970915 split line;ignore mergin.if pos is in mergin,        //~v0eiI~
//            out of mergin to be copyed?                          //~v0eiI~
//v0eh:970915 (BUG) split line leave half of DBCS on 2nd line      //~v0ehI~
//v0eg:970915 (BUG) by v0di,spli use EEOL also                     //~v0egR~
//v0ef:970915 return copylen not contlen for new reclen;           //~v0ebI~
//v0eb:970915 paste source len;same logic as copy lcmd(fullline)   //~v0ebI~
//v0dp:970907 no page shift for ETOL because out of mergin ETOL dose not//~v0dpI~
//            clear in mergin by v0d0                              //~v0dpI~
//v0dm:970831 (BUG)abend when cap isrt if len<cpos for mergin file //~v0dmI~
//            char2.c                                              //~v0dmI~
//v0di:970907 undo unit for EEOL,ETOL,CTOL                         //~v0diI~
//v0ci:970810 (BUG)cid clear abend(oldpos is last cidpos)          //~v0ciI~
//v0cf:970810 ignore mergin of next line when join line            //~v0cfI~
//v0cc:970803 filegetcidlen return last cidpos                     //~v0cbI~
//v0cb:970802 split allow for long rec even if at out of mergin    //~v0cbI~
//            if csr<mergin cut/erase up to mergin                 //~v0cbI~
//            if csr>=mergin cut/erase up to rec end               //~v0cbI~
//              except case mergin=cidpos=topcidpos                //~v0cbI~
//v0c2:970728 simple principle.do not touch/move out of mergin     //~v0c2I~
//            if mergin not specified,last space is not dropped    //~v0c2I~
//v0bv:970728 split file4-->file42                                 //~v0boI~
//v0bo:970727 allow crlf pos del key to concatinate line           //~v0boI~
//            reverse of splitline split.                          //~v0boI~
//v0bn:970727 split line csr must on the crlf pos,err if over lrecl//~v0bnI~
//            like as del                                          //~v0bnI~
//v0bm:970727 (BUG)missing draw set when split line                //~v0bmI~
//v0bl:970727 split concat line by split_line when csr is out of line//~v0blI~
//v0bj:970727 no split cid by split-line funckey                   //~v0bjI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//           -expand pre chk(split file2 to file6)                 //~v0avI~
//v098:970413:(BUG)avail update on browse line(but its is not saved)//~v098I~
//            by Shift+Ins/Del/F10(rep)/Enter(Split).              //~v098I~
//            char2.c                                              //~v098I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v06M:960424:hi-lighten insert line by cut and paste              //~v06MI~
//            char2.c char2.h lcmd3.c                              //~v06MI~
//v06a:960224:(BUG)back tab skip to end of cur line,if curr csr is on lineno fld//~v06aI~
//v069:960224:linenosz changeable for edit/browse               //~v069I~
//v05c:951111:(BUG)line split abend when CID only after split point//~v05cI~
//v057:951015:(BUG)same as v055 for capdel del CR(line concat)  //~v057I~
//v055:951014:(BUG)abend when delete lcmd input line by Shist+Del key//~v055I~
//            because pfh->UFHcmdline remain point deleted line.//~v055I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*v011:950610:browse mode tab                                  //~5611I~
//************************************************************* //~5611I~
//*950514 prev tab stop also on cursor pos                      //~5514R~
//*950422 highlighten copyed block                              //~5422R~
//*950225 bug:bs step back evenif protected                     //~5422I~
//*950111 claer top of line/delete line/insert line             //~5111R~
//*950102 tab display by space for screen print                 //~5111I~
//************************************************************* //~5102I~
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
#include <ualloc.h>                                             //~v04dI~
#include <ustring.h>                                               //~v676I~
#ifdef UTF8SUPPH                                                   //~va1qR~
#include <udbcschk.h>                                              //~v78SI~
#endif                                                             //~va1qI~
#ifdef UTF8UCS2                                                    //~va20R~
#include <utf.h>                                                   //~va20R~
#include <utf22.h>                                                 //~va20R~
#endif                                                             //~va20R~
#include <ucvebc.h>                                                //~va50I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xescr2.h"                                                //~v101I~
#include "xecsr.h"
#include "xefile.h"
#include "xefile2.h"                                               //~v0avI~
#include "xefile22.h"                                              //~v44dI~
#include "xefile3.h"                                            //~5423I~
#include "xefile4.h"                                               //~v0boR~
#include "xefile42.h"                                              //~v0boI~
#include "xefile6.h"                                               //~v0avI~
#include "xechar.h"                                             //~5124I~
#include "xechar12.h"                                              //~va2hR~
#include "xechar2.h"                                            //~5211I~
#include "xefunc.h"
#include "xelcmd.h"                                             //~4C29I~
#include "xelcmd2.h"                                            //~4C29I~
#include "xelcmd3.h"                                            //~4C29I~
#include "xepan.h"                                                 //~v0izI~
#include "xefile7.h"                                               //~v0izI~
#include "xeundo.h"                                             //~5211I~
#include "xeerr.h"                                                 //~v098I~
#include "xesub.h"                                              //~5318I~
#ifdef UTF8SUPPH                                                   //~va1qR~
#include "xesub2.h"                                                //~va1cR~
#endif                                                             //~va1qI~
#include "xefcmd4.h"     //fcmdsplit                               //~v45xI~
#include "xefcmd23.h"     //fcmdsplit                              //~v74EI~
#ifdef UTF8UCS2                                                    //~va20R~
#include "xeutf.h"                                                 //~va20R~
#endif                                                             //~va20R~
#include "xeebc.h"                                                 //~va50I~
//*******************************************************       //~5225I~
//*******************************************************          //~v0egI~
int funcbschk(PUCLIENTWE Ppcw);                                 //~5225I~
int charsplitline(PUCLIENTWE Ppcw,PULINEH Pplh);                   //~v0blI~
int char2tabstopchk(PUCLIENTWE Ppcw,PUFILEC Ppfc,int Pdest);       //~v21rR~
int charcaponundoprep(PUCLIENTWE Ppcw,int Psrclen,PULINEH Pplhd,int Poffs,int Preclen);//~v67VI~
//*******************************************************
//* del char **
//*******************************************************
int func_del_pan(PUCLIENTWE Ppcw)
{
	return charpan(Ppcw,CHAROPDEL);
}//func_del_pan

//* for file **********
int func_del_file(PUCLIENTWE Ppcw)
{
	return charfile(Ppcw,CHAROPDEL);
}//func_del_file

//*******************************************************
//* truncate line(Erase End of line)                            //~4C25R~
//*******************************************************
int func_eraseeol_pan(PUCLIENTWE Ppcw)                          //~4C25R~
{
	return charpan(Ppcw,CHAROPEEOL);                            //~4C25R~
}//func_eraseeol_pan                                            //~5111R~

//* for file **********
int func_eraseeol_file(PUCLIENTWE Ppcw)                         //~4C25R~
{
	PUFILEH pfh;                                                   //~v0diI~
    int rc;                                                        //~v0diI~
//****************                                                 //~v0diI~
	pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;                         //~v0diI~
	UPCTRREQ(pfh);//next time updatectr up                         //~v0diI~
	rc=charfile(Ppcw,CHAROPEEOL); 	                               //~v0diR~
	UPCTRREQ(pfh);//next time updatectr up                         //~v0diI~
	return rc;                                                     //~v0diI~
}//func_eraseeol_file                                           //~5111R~

//*******************************************************       //~4C29I~
//* backspace *                                                 //~5225R~
//*******************************************************       //~4C29I~
int func_bs_pan(PUCLIENTWE Ppcw)                                //~4C29I~
{                                                               //~4C29I~
//**********                                                    //~4C29I~
	if (Ghexctl[HEXCTL_MODE])	//hex input mode                   //~va3KI~
    {                                                              //~va3KI~
    	if(Ghexctl[HEXCTL_LEN])                                    //~va3KI~
        {                                                          //~va3KI~
            scrclearmsg(Ppcw);  //redraw hdr line                  //~va3KI~
	    	Ghexctl[HEXCTL_LEN]=(UCHAR)(Ghexctl[HEXCTL_LEN]-1);    //~va3KI~
            return 0;                                              //~va3KI~
        }                                                          //~va3KI~
    }                                                              //~va3KI~
	if (funcbschk(Ppcw))                                        //~5225R~
		return 4;					//now left most             //~5225I~
	return charpan(Ppcw,CHAROPDEL);                             //~4C29I~
}//func_bs_pan                                                  //~4C29I~
                                                                //~4C29I~
//*for file******                                               //~4C29I~
int func_bs_file(PUCLIENTWE Ppcw)                               //~4C29I~
{                                                               //~4C29I~
	PUSCRD psd;                                                    //~v59uI~
	PUFILEC pfc;                                                   //~v59uI~
    PUFILEH pfh;                                                   //~v59uI~
    PULINEH plh;                                                   //~v59uI~
    int   hpos,hpose,cpos,dpos=0,oddsw;                            //~v59uI~
//**********                                                    //~4C29I~
	if (Ghexctl[HEXCTL_MODE])	//hex input mode                   //~v101I~
    	if(Ghexctl[HEXCTL_LEN])                                    //~v101I~
        {                                                          //~v101I~
            scrclearmsg(Ppcw);  //redraw hdr line                  //~v101I~
	    	Ghexctl[HEXCTL_LEN]=(UCHAR)(Ghexctl[HEXCTL_LEN]-1);    //~v101R~
            return 0;	                                           //~v101I~
        }                                                          //~v101I~
	if (funcbschk(Ppcw))                                        //~5225I~
		return 4;					//now left most             //~5225I~
	pfc=Ppcw->UCWpfc;                                              //~v59uI~
    pfh=pfc->UFCpfh;                                               //~v59uR~
    if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                          //~v59uI~
    {                                                              //~v59uI~
      if (CSRONFILELINE(Ppcw))                                     //~v76VI~
      {                                                            //~v76VI~
	 	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                           //~v59uI~
		plh=psd->USDbuffc;                                         //~v59uI~
	    filegethposrange(pfh,plh->ULHlen,&hpos,&hpose);//get hex area range//~v59uI~
	    cpos=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;        //~v59uI~
        if (cpos>hpos && cpos<hpose)	//hex part                 //~v59uI~
        {                                                          //~v59uI~
    		oddsw=filegetdatapos(hpos,hpose,cpos,&dpos,1);//left most data pos//~v59uI~
            if (oddsw<0)	//intermediate space                   //~v59uI~
            {                                                      //~v59uI~
				if (funcbschk(Ppcw))        //2 col back           //~v59uR~
					return 4;					//now left most    //~v59uR~
            }                                                      //~v59uI~
            if (funcbschk(Ppcw))        //2 col back               //~v59uI~
                return 4;                   //now left most        //~v59uI~
		    cpos=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;    //~v59uI~
    		oddsw=filegetdatapos(hpos,hpose,cpos,&dpos,1);//left most data pos//~v59uI~
            if (oddsw<0)	//intermediate space	               //~v59uI~
            {                                                      //~v59uI~
				if (funcbschk(Ppcw))        //2 col back           //~v59uI~
					return 4;					//now left most    //~v59uI~
            }                                                      //~v59uI~
        }                                                          //~v59uI~
      }//csr on fileline                                           //~v76VI~
    }                                                              //~v59uI~
	return charfile(Ppcw,CHAROPDEL);                            //~4C29I~
}//func_bs_file                                                 //~4C29I~
                                                                //~4C29I~
//*prot chk ******                                              //~5225I~
int funcbschk(PUCLIENTWE Ppcw)                                  //~5225I~
{                                                               //~5225I~
	int rc;                                                     //~5225I~
	int cposx;                                                  //~5301I~
//**********                                                    //~5225I~
	cposx=Gcsrposx;		//save current                          //~5301I~
	if (rc=func_left(Ppcw),rc)  //row changed                   //~5301R~
		return rc;                                              //~5225I~
	if ((Ppcw->UCWrcsrx-=(cposx-Gcsrposx))<0)//func_left not change UCWrcsrx//~5301R~
		return 4;                                               //~5301I~
  	return 0;                                                   //~5225I~
}//funcbschk                                                    //~5225I~
                                                                //~5225I~
//*******************************************************       //~4C25I~
//* erase top of line                                           //~4C25I~
//*******************************************************       //~4C25I~
int func_erasetol_pan(PUCLIENTWE Ppcw)                          //~4C25I~
{                                                               //~4C25I~
	int rc;                                                     //~4C29I~
//**************                                                //~4C29I~
	if (rc=charpan(Ppcw,CHAROPETOL),rc)                         //~4C29R~
		return rc;                                              //~4C29I~
	return csronthefld(Ppcw,Ppcw->UCWrcsry,Ppcw->UCWfleno,0);   //~5223R~
}//func_erasetol_pan                                            //~5111R~
                                                                //~4C25I~
//* for file **********                                         //~4C25I~
int func_erasetol_file(PUCLIENTWE Ppcw)                         //~4C25I~
{                                                               //~4C25I~
	int rc;                                                     //~4C29I~
    UCHAR reason;                                                  //~v0dpI~
    int csrpos;                                                    //~v0dpI~
    PUFILEC pfc;                                                //~4C29R~
    PUFILEH pfh;                                                   //~v0diI~
//**************                                                //~4C29I~
	pfc=Ppcw->UCWpfc;                                              //~v0diM~
	pfh=pfc->UFCpfh;                                               //~v0diM~
	UPCTRREQ(pfh);//next time updatectr up                         //~v0diM~
	Ppcw->UCWreason=0;      //                                     //~v0dpI~
//  rc=charfile(Ppcw,CHAROPETOL);                                  //~v74qR~
    rc=charfile(Ppcw,CHAROPETOLCOB);  //keep COB margin            //~v74qI~
	reason=Ppcw->UCWreason;                                        //~v0dpI~
	Ppcw->UCWreason=0;      //                                     //~v0dpI~
	UPCTRREQ(pfh);//next time updatectr up                         //~v0diM~
    if (rc)                                                        //~v0diI~
		return rc;                                              //~4C29I~
	if (reason)                                                    //~v0dpI~
    {                                                              //~v0dpI~
    	csrpos=pfh->UFHmergin-pfc->UFCleft;                        //~v0dpI~
        if (csrpos<0)                                              //~v0dpR~
        	csrpos=0;                                              //~v0dpI~
    }                                                              //~v0dpI~
	else                                                           //~v0dpI~
//  	csrpos=0;                                                  //~v0ihR~
    	csrpos=pfh->UFHprotlen;                                    //~v0ihI~
//    if (pfc->UFCleft)                                            //~v0dpR~
//    {                                                            //~v0dpR~
//        pfc->UFCleft=0;                                          //~v0dpR~
//        UCBITON(Ppcw->UCWflag,UCWFDRAW);    //scr draw           //~v0dpR~
//    }                                                            //~v0dpR~
	return csronthefld(Ppcw,Ppcw->UCWrcsry,Ppcw->UCWfleno,csrpos); //~v0dpR~
}//func_erasetol_file                                           //~5111R~
                                                                //~4C25I~
//*******************************************************       //~5111I~
//* claer top of line line                                      //~5111I~
//*******************************************************       //~5111I~
int func_cleartol_pan(PUCLIENTWE Ppcw)                          //~5111I~
{                                                               //~5111I~
	return charpan(Ppcw,CHAROPCTOL);                            //~5111I~
}//func_claertol_pan                                            //~5111I~
                                                                //~5111I~
//* for file **********                                         //~5111I~
int func_cleartol_file(PUCLIENTWE Ppcw)                         //~5111I~
{                                                               //~5111I~
	PUFILEH pfh;                                                   //~v0diI~
    int rc;                                                        //~v0diI~
//****************                                                 //~v0diI~
	pfh=((PUFILEC)(Ppcw->UCWpfc))->UFCpfh;                         //~v0diI~
	UPCTRREQ(pfh);//next time updatectr up                         //~v0diI~
	rc=charfile(Ppcw,CHAROPCTOL);                                  //~v0diI~
	UPCTRREQ(pfh);//next time updatectr up                         //~v0diI~
    return rc;                                                     //~v0diI~
}//func_cleartol_file                                           //~5111I~
                                                                //~5111I~
//*******************************************************       //~4C29I~
//* split line                                                  //~4C29I~
//*******************************************************       //~4C29I~
int func_splitline_file(PUCLIENTWE Ppcw)                        //~4C29I~
{                                                               //~4C29I~
	ULCMD  *plc;                                                //~5223R~
	PULINEH plh,plhprev,plhi;                                   //~4C29R~
	PUFILEH  pfh;                                               //~5111I~
    PUFILEC pfc;                                                //~4C29I~
    UCHAR *pc,*pcd;                                                //~v40xR~
    int addlen;                                                    //~v40xI~
	int rc,col,len;                                             //~v05cR~
//    int netlen;                                                  //~v0eiR~
    int copylen;                                                   //~v0eiI~
    int copypos,cobsw;                                             //~v42cR~
//  int lastcidpos;                                                //~v0cfR~
//  int mergin;                                                    //~v0cfR~
    int vhexmode;                                                  //~v76MI~
	PUSCRD psd;                                                    //~v76MI~
//**************                                                //~4C29I~
    if (Ppcw->UCWkeytype==UCWKTCMD)//split cmd                     //~v45xI~
        return fcmdsplit(Ppcw);                                    //~v45xI~
	if (!CSRONFILEDATA(Ppcw))	//csr on line data except lineno//~5223R~
    {                                                              //~v10bI~
        errcsrpos();                                               //~v11qR~
        uerrmsgcat("(SplitLine)",                                  //~v11qR~
    				"(çsï™äÑ)");                                   //~v11qR~
   		return 4;				//not on file line data area    //~5111R~
    }                                                              //~v10bI~
	plh=((PUSCRD)Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc;        //~4C29R~
	if (plh->ULHtype!=ULHTDATA)                                 //~4C29I~
   		return 4;				//not data line                 //~4C29I~
	plhprev=UGETQPREV(plh);		//prev line                     //~4C29I~
	pfc=Ppcw->UCWpfc;                                           //~4C29I~
	psd=(PUSCRD)Ppcw->UCWpsd+Ppcw->UCWrcsry;                       //~v76MI~
    if (UCBITCHK(pfc->UFCflag2,UFCF2VHEX))                         //~v76MI~
	    vhexmode=(psd->USDflag2 & (USDF2VHEXLINE1|USDF2VHEXLINE2));//~v76MI~
    else                                                           //~v76MI~
        vhexmode=0;                                                //~v76MI~
	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse mode          //~v098I~
		return errbrowsemode();                                    //~v098R~
	pfh=pfc->UFCpfh;                                            //~5111I~
    cobsw=UCBITCHK(pfh->UFHflag5,UFHF5COB);                        //~v42cI~
	UPCTRREQ(pfh);//next time updatectr up                      //~5225R~
//  mergin=pfh->UFHmergin;                                         //~v0cfR~
	plc=lcmdgetdummyplc(Ppcw,'B');	//destination Before        //~5223I~
	col=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;	//current col//~v069R~
   	if (col>plh->ULHlen)		//over line                        //~v0bnI~
        return 4;                                                  //~v0bnI~
	if (!col)	//top of line                                   //~4C29R~
	{                                                           //~4C29I~
 		if (rc=lcmdisrt(Ppcw,plhprev,1,0),rc)//isrt 1 line after prev without indent//~v04dR~
        	return rc;                                          //~v04dI~
		filesetcsr(Ppcw,plh,1,0);	//reset to cur line fldno 1,fldtop//~5223R~
		if (plh==pfc->UFCcurtop && pfc->UFCmaxline>1)           //~4C29I~
			pfc->UFCcurtop=UGETQPREV(plh); //                   //~4C29R~
	}                                                           //~4C29I~
	else                                                        //~4C29I~
	{                                                           //~4C29I~
//      netlen=filecidlrecl2(plh,pfh);//from end of record even if mergin specified//~v0cbR~
//  	filegetcidlen2(plh,pfh,&netlen,0,0);//regardless mergin    //~v0eiR~
    	filegetcidlenc(plh,pfh,0,0,0,&copylen);//netlen=toppos=lastpo=0//~v0eiI~
//  	if (col>=plh->ULHlen)		//over line                    //~v0bjR~
//  	if (col>=netlen)		//over line                        //~v0eiR~
    	if (col>=copylen)		//over line                        //~v0eiI~
//  	||  (UCBITCHK(pfh->UFHflag2,UFHF2MERGINCID)                //~v0cfR~
//  	  && lastcidpos==mergin                                    //~v0cfR~
//  	  && col>=lastcidpos))	//in cid                           //~v0cfR~
        {                                                       //~v04dI~
		  	if (col>=plh->ULHlen                                   //~v0blI~
            && 	UCBITCHK(plh->ULHflag2,ULHF2SPLIT1))	//has follower//~v0blI~
            {                                                      //~v0blI~
//*split contline to 2 single line by S+Enter at EOL pos;no dbcstbl chng//~va50I~
                if (rc=charsplitline(Ppcw,plh),rc)                 //~v0blI~
		        	return rc;                                     //~v0blI~
			}                                                      //~v0blI~
            else                                                   //~v0blI~
 			if (rc=lcmdisrt(Ppcw,plh,1,0),rc)	//isrt 1 line after,w/o indent//~v04dR~
	        	return rc;                                      //~v04dI~
        }                                                       //~v04dI~
		else                                                    //~4C29I~
		{                                                       //~4C29I~
			plc->ULCplh=UGETQNEXT(plh);	//copy before next      //~5223R~
     		if (rc=lcmdcopy(Ppcw,plh,plh,1,plc),rc)             //~5223R~
				return rc;                                      //~4C29I~
			plhi=UGETQNEXT(plh);			//inserted          //~4C29I~
//  		if (rc=func_eraseeol_file(Ppcw),rc)                    //~v0egR~
            rc=charfile(Ppcw,CHAROPEEOL);                          //~v0eiR~
            if (rc)                                                //~v0eiR~
                return rc;                                         //~v0eiR~
    		plh->ULHlen=col;	//drop out of mergin               //~v0eiI~
                                                                   //~v0eiI~
//  		len=plhi->ULHlen-col;	//len after drop CID           //~v0cbR~
//  		len=netlen;      	//len drop CID                     //~v0eiR~
    		len=copylen;     	//len drop CID                     //~v0eiI~
//          if (col<mergin)                                        //~v0cfR~
//          {                                                      //~v0cfR~
//          	if (len>mergin)                                    //~v0cfR~
//              	len=mergin;                                    //~v0cfR~
//          }                                                      //~v0cfR~
            len-=col;                                              //~v0cbI~
            if (len>0)                                          //~v05cI~
            {                                                   //~v05cI~
     		  	if (cobsw && col>=SPFCOBNUMFLDLEN)                 //~v42cR~
              		copypos=SPFCOBNUMFLDLEN;                       //~v42cR~
              	else                                               //~v42cI~
              		copypos=0;                                     //~v42cI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    		 if (PFH_ISEBC(pfh)) //no insert char to ebcfile       //~va50R~
             {                                                     //~va50I~
    			memcpy(plhi->ULHdata+copypos,plhi->ULHdata+col,(UINT)len);//~va50I~
    			plhi->ULHlen=len+copypos;                          //~va50I~
				xeebc_setdbcstblplh(0,pfh,plhi,0);                 //~va50R~
             }                                                     //~va50I~
             else                                                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
             {//!ebc                                               //~va50I~
              if (vhexmode)                                        //~v76MI~
				setsplitdbcserr(0,plhi->ULHdbcs,plhi->ULHlen,col);//0:pdata:don't replace to space//~v76MR~
              else                                                 //~v76MI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                setobtabdbcs(0,0,plhi->ULHdata,plhi->ULHdbcs,plhi->ULHlen,//~va50I~
#else                                                              //~va50I~
                setobtabdbcs(plhi->ULHdata,plhi->ULHdbcs,plhi->ULHlen,//~v0ehI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                             0,col);//right of col                 //~v42cR~
//  			memcpy(plhi->ULHdata,plhi->ULHdata+col,(UINT)len); //~v42cR~
    			memcpy(plhi->ULHdata+copypos,plhi->ULHdata+col,(UINT)len);//~v42cR~
//  			memcpy(plhi->ULHdbcs,plhi->ULHdbcs+col,(UINT)len); //~v42cR~
    			memcpy(plhi->ULHdbcs+copypos,plhi->ULHdbcs+col,(UINT)len);//~v42cR~
//  			plhi->ULHlen=len;                                  //~v42cR~
    			plhi->ULHlen=len+copypos;                          //~v42cI~
				pc=plhi->ULHdata;                                  //~v40xI~
				pcd=plhi->ULHdbcs;                                 //~v40xI~
				chartabexp(plhi,0,0,&pc,&pcd,0,len,&addlen);       //~v40xI~
             }//!ebc                                               //~va50I~
            }                                                   //~v05cI~
            else                                                //~v05cI~
				plhi->ULHlen=0;                                 //~v05cI~
    		filesetcsr(Ppcw,plhi,1,0);	//reset to cur line fldno 1,fldtop//~v42cR~
		}//intermediate                                         //~4C29I~
     if (!cobsw)                                                   //~v42cI~
      if (pfc->UFCleft)                                            //~v0bmI~
      {                                                            //~v0bmI~
		UCBITON(Ppcw->UCWflag,UCWFDRAW);	//full draw            //~v0bmI~
		pfc->UFCleft=0;                                         //~4C29I~
      }                                                            //~v0bmI~
	}                                                           //~4C29I~
	UPCTRREQ(pfh);//next time updatectr up                      //~5225I~
    return csronthefld(Ppcw,Ppcw->UCWrcsry,Ppcw->UCWfleno,0);      //~v42cR~
}//func_splitline_file                                          //~5125R~
                                                                //~4C29I~
//*******************************************************          //~v0i7I~
//* split line by lcmd('S')                                        //~v0i7I~
//* parm1:pcw                                                      //~v0i7I~
//* parm2:plh                                                      //~v0i7I~
//* rc   :UALLOC_FAILED,4(mergin protected etc)                    //~v0i7I~
//*******************************************************          //~v0i7I~
//int charlcmdsplit(PUCLIENTWE Ppcw,PULINEH Pplh)                  //~v66fR~
//int charlcmdsplit(PUCLIENTWE Ppcw,PULINEH Pplh,int Ppos)         //~v74jR~
int charlcmdsplit(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Ppos)  //~v74jI~
{                                                                  //~v0i7I~
	ULCMD  *plc;                                                   //~v0i7I~
	PULINEH plhprev,plhi;                                          //~v0i7I~
	PUFILEH  pfh;                                                  //~v0i7I~
    PUFILEC pfc;                                                   //~v0i7I~
	int rc,col,len;                                                //~v0i7I~
    int copylen;                                                   //~v0i7I~
//  int copypos,cobsw;                                             //~v74qR~
    int excsw;                                                     //~v0i7I~
    int mode;                                                      //~v74jI~
    int vhexmode=0;                                                //~va3SI~
//**************                                                   //~v0i7I~
	if (!Pplh->ULHdbcs)                                            //~v0i7I~
    	if (filechktabdbcs(Pplh)==UALLOC_FAILED)                   //~v0i7I~
        		return UALLOC_FAILED;                              //~v0i7I~
    if (Pplh->ULHtype!=ULHTDATA)                                   //~v66kI~
        return 4;                                                  //~v66kI~
	plhprev=UGETQPREV(Pplh);		//prev line                    //~v0i7I~
    excsw=UCBITCHK(Pplh->ULHflag2,ULHF2EXCLUDED);                  //~v0i7I~
	pfc=Ppcw->UCWpfc;                                              //~v0i7I~
	pfh=pfc->UFCpfh;                                               //~v0i7I~
	if (Popt & CLS_LCSPLITVX) //lcmd "S" start from vhexline       //~va3SR~
    	vhexmode=CFEO_VHEXLCMDS;    //split lcmd on vhex line      //~va3SR~
//  cobsw=UCBITCHK(pfh->UFHflag5,UFHF5COB);                        //~v74qR~
  if (Ppos>=0)	//from xecap2                                      //~v66fI~
  	col=Ppos;                                                      //~v66fI~
  else                                                             //~v66fI~
	col=pfc->UFCleft+Ppcw->UCWrcsrx-Ppcw->UCWlinenosz;	//current col//~v0i7I~
	if (!col)	//top of line                                      //~v0i7I~
	{                                                              //~v0i7I~
 		if (rc=lcmdisrt(Ppcw,plhprev,-1,0),rc)//isrt 1 line after prev without indent//~v0i7R~
 		                                      //-1 mean ignore EXCLUDED//~v0i7I~
        	return rc;                                             //~v0i7I~
        if (excsw)                                                 //~v0i7I~
        {                                                          //~v0i7I~
            plhi=UGETQNEXT(plhprev);                               //~v0i7I~
		    UCBITON(plhi->ULHflag2,ULHF2EXCLUDED);                 //~v0i7I~
        }                                                          //~v0i7I~
	}                                                              //~v0i7I~
	else                                                           //~v0i7I~
	{                                                              //~v0i7I~
    	filegetcidlenc(Pplh,pfh,0,0,0,&copylen);//netlen=toppos=lastpo=0//~v0i7I~
    	if (col>=copylen)		//over line                        //~v0i7I~
        {                                                          //~v0i7I~
		  	if (col>=Pplh->ULHlen                                  //~v0i7I~
            && 	UCBITCHK(Pplh->ULHflag2,ULHF2SPLIT1))	//has follower//~v0i7I~
            {                                                      //~v0i7I~
//*split contline to 2 single line by "S" lcmd with csr at EOL pos;no dbcstbl chng//~va50I~
                if (rc=charsplitline(Ppcw,Pplh),rc) //spli cont line//~v0i7R~
		        	return rc;                                     //~v0i7I~
			}                                                      //~v0i7I~
            else                                                   //~v0i7I~
            {                                                      //~v0i7I~
 				if (rc=lcmdisrt(Ppcw,Pplh,-1,0),rc)	//isrt 1 line after,w/o indent//~v0i7R~
 		                                      //-1 mean ignore EXCLUDED//~v0i7I~
	    	    	return rc;                                     //~v0i7I~
        		if (excsw)                                         //~v0i7I~
                {                                                  //~v0i7I~
            		plhi=UGETQNEXT(Pplh);                          //~v0i7R~
		    		UCBITON(plhi->ULHflag2,ULHF2EXCLUDED);         //~v0i7R~
                }                                                  //~v0i7I~
            }                                                      //~v0i7I~
        }                                                          //~v0i7I~
		else	//split intermidiate                               //~v0i7I~
		{                                                          //~v0i7I~
			plc=lcmdgetdummyplc(Ppcw,'B');	//destination Before   //~v0i7I~
			plc->ULCplh=UGETQNEXT(Pplh);	//copy before next     //~v0i7I~
     		if (rc=lcmdcopy(Ppcw,Pplh,Pplh,1,plc),rc)              //~v0i7I~
				return rc;                                         //~v0i7I~
			plhi=UGETQNEXT(Pplh);			//inserted             //~v0i7I~
            if (Popt & CLS_IGM)                                    //~v74jI~
            	mode=CHAROPEEOLIGM;                                //~v74jI~
            else                                                   //~v74jI~
            	mode=CHAROPEEOL;                                   //~v74jI~
//          rc=charfldedit(CHAROPEEOL,                             //~v74jR~
			mode|=vhexmode;                                        //~va3SI~
            rc=charfldedit(mode,                                   //~v74jR~
							Pplh->ULHdata,                         //~v0i7I~
							Pplh->ULHdbcs,                         //~v0i7I~
                            col,			//record offset        //~v0i7I~
                            0,              //start col            //~v0i7I~
                            Pplh->ULHlen,	//endcol               //~v0i7I~
                            Pplh->ULHbufflen,//bufflen             //~v0i7I~
							Ppcw,                                  //~v0i7I~
							Pplh);                                 //~v0i7I~
            if (rc)                                                //~v0i7I~
                return rc;                                         //~v0i7I~
    		Pplh->ULHlen=col;	//drop out of mergin               //~v0i7I~
    		len=copylen;     	//len drop CID                     //~v0i7I~
            len-=col;                                              //~v0i7I~
            if (len>0)                                             //~v0i7I~
            {                                                      //~v0i7I~
//   		  	if (cobsw && col>=SPFCOBNUMFLDLEN)                 //~v74qR~
//            		copypos=SPFCOBNUMFLDLEN;                       //~v74qR~
//            	else                                               //~v74qR~
//            		copypos=0;                                     //~v74qR~
//                setobtabdbcs(plhi->ULHdata,plhi->ULHdbcs,plhi->ULHlen,//~v74kR~
//                             0,col);//right of col               //~v74kR~
////              memcpy(plhi->ULHdata,plhi->ULHdata+col,(UINT)len);//~v74kR~
//                memcpy(plhi->ULHdata+copypos,plhi->ULHdata+col,(UINT)len);//~v74kR~
////              memcpy(plhi->ULHdbcs,plhi->ULHdbcs+col,(UINT)len);//~v74kR~
//                memcpy(plhi->ULHdbcs+copypos,plhi->ULHdbcs+col,(UINT)len);//~v74kR~
////              plhi->ULHlen=len;                                //~v74kR~
//                plhi->ULHlen=len+copypos;                        //~v74kR~
//              rc=charfldedit(CHAROPETOL,                         //~v74qR~
//              rc=charfldedit(CHAROPETOLCOB,                      //~v74qI~//~va3SR~
                mode=CHAROPETOLCOB|vhexmode;                       //~va3SI~
                rc=charfldedit(mode,                               //~va3SI~
                                plhi->ULHdata,                     //~v74kM~
                                plhi->ULHdbcs,                     //~v74kM~
                                col,            //record offset    //~v74kM~
//                              copypos,        //start col        //~v74qR~
                                0,              //start col        //~v74qI~
                                plhi->ULHlen,   //endcol           //~v74kM~
                                plhi->ULHbufflen,//bufflen         //~v74kM~
                                Ppcw,                              //~v74kM~
                                plhi);                             //~v74kM~
                if (rc)                                            //~v74kM~
                    return rc;                                     //~v74kM~
            }                                                      //~v0i7I~
            else                                                   //~v0i7I~
				plhi->ULHlen=0;                                    //~v0i7I~
		}//intermediate                                            //~v0i7I~
	}                                                              //~v0i7I~
	return 0;                                                      //~v0i7I~
}//charlcmdsplit                                                   //~v0i7I~
                                                                   //~v0i7I~
//*******************************************************       //~5111I~
//* delete line                                                 //~5111I~
//*******************************************************       //~5111I~
int func_delline_file(PUCLIENTWE Ppcw)                          //~5111I~
{                                                               //~5111I~
	PULINEH plh;                                                //~5111R~
	PUFILEH  pfh;                                               //~5111I~
	PUFILEC  pfc;                                                  //~v098I~
    int rc;                                                     //~v057R~
//**************                                                //~5111I~
	if (!CSRONFILELINE(Ppcw))	//chk csr on file line          //~5111R~
   		return 4;				//not on file client area       //~5111I~
	pfc=Ppcw->UCWpfc;                                              //~v098I~
	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse mode          //~v098I~
		return errbrowsemode();                                    //~v098I~
	plh=((PUSCRD)Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc;        //~5111I~
	if (plh->ULHtype!=ULHTDATA)                                 //~5111I~
	  if (plh->ULHtype!=ULHTEXCLUDE)                               //+vbq0I~
   		return 4;				//not data line                 //~5111I~
    pfh=UGETPFH(plh);                                           //~5111I~
	UPCTRREQ(pfh);//next time updatectr up                      //~5225I~
	rc=lcmddel(Ppcw,plh,plh,1,1,1);//1line del,csr set to next line//~v057R~
                                   //UFHcmdline clear           //~v057I~
//  if (!rc                                                     //~v057R~
//  &&  UCBITCHK(plh->ULHflag,ULHFLINECMD))	//remain not processed lcmd//~v057R~
//  	for(ii=pfh->UFHcmdlinectr-1;ii>=0;ii--)                 //~v057R~
//      	if (pfh->UFHcmdline[ii]==plh)                       //~v057R~
//      	{                                                   //~v057R~
//          	pfh->UFHcmdline[ii]=0;                          //~v057R~
//              break;                                          //~v057R~
//  		}                                                   //~v057R~
	UPCTRREQ(pfh);//next time updatectr up                      //~5225I~
	return rc;                                                  //~5111I~
}//func_delline_file                                            //~5111I~
                                                                //~5111I~
//*******************************************************       //~5111I~
//* insert line                                                 //~5111I~
//*******************************************************       //~5111I~
int func_insline_file(PUCLIENTWE Ppcw)                          //~5111I~
{                                                               //~5111I~
	PULINEH plh;                                                //~5111I~
	PUFILEH  pfh;                                               //~5111I~
	PUFILEC  pfc;                                                  //~v098I~
    int rc;                                                     //~5111I~
//**************                                                //~5111I~
	if (!CSRONFILELINE(Ppcw))	//chk csr on file line          //~5111I~
   		return 4;				//not on file client area       //~5111I~
	pfc=Ppcw->UCWpfc;                                              //~v098I~
	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse mode          //~v098I~
		return errbrowsemode();                                    //~v098I~
	plh=((PUSCRD)Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc;        //~5111I~
    pfh=UGETPFH(plh);                                           //~5111I~
	UPCTRREQ(pfh);//next time updatectr up                      //~5225I~
#ifdef AAA                                                         //~v78SI~
    rc=lcmdisrt(Ppcw,plh,1,LCIO_INDENT|LCIO_CONT);	//with indent req  and continued isn//~v78SM~
#else                              //it may be better  for me not to continue insertion//~v78SI~
    rc=lcmdisrt(Ppcw,plh,1,1);	//req indentation                  //~v78SR~
#endif                                                             //~v78SI~
	UPCTRREQ(pfh);//next time updatectr up                      //~5225I~
	return rc;                                                  //~5111I~
}//func_insline_file                                            //~5111I~
                                                                //~5111I~
//*******************************************************       //~5223I~
//* repeat line                                                 //~5223I~
//*******************************************************       //~5223I~
int func_repline_file(PUCLIENTWE Ppcw)                          //~5223I~
{                                                               //~5223I~
    ULCMD   *plc;                                               //~5223R~
	PULINEH  plh;                                               //~5223I~
	PUFILEH  pfh;                                               //~5223I~
	PUFILEC  pfc;                                                  //~v098I~
	int rc;                                                     //~5223I~
//**************                                                //~5223I~
	if (!CSRONFILELINE(Ppcw))	//chk csr on lineno/line dat    //~5223I~
   		return 4;				//not on file line data area    //~5223I~
	pfc=Ppcw->UCWpfc;                                              //~v098I~
	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse mode          //~v098I~
		return errbrowsemode();                                    //~v098I~
	plh=((PUSCRD)Ppcw->UCWpsd+Ppcw->UCWrcsry)->USDbuffc;        //~5223I~
	if (plh->ULHtype==ULHTHDR)                                  //~5223I~
   		return 4;				//not data line                 //~5223I~
	pfh=UGETPFH(plh);                                           //~5223I~
	UPCTRREQ(pfh);//next time updatectr up                      //~5225I~
	plc=lcmdgetdummyplc(Ppcw,'R');	//Repaet cmd                //~5223R~
	plc->ULCplh=plh;			                                //~5223R~
    rc=lcmdrep(Ppcw,plh,plh,1,plc);                             //~5223R~
	UPCTRREQ(pfh);//next time updatectr up                      //~5225I~
	return rc;                                                  //~5223I~
}//func_repline_file                                            //~5223I~
                                                                //~5223I~
//**************************************************
//* next tab on file record 
//**************************************************
int func_nexttab_file(PUCLIENTWE Ppcw)
{
	PUSCRD 	 psd;
	PULINEH  plh;
	PUFILEC  pfc;
	PUFILEH  pfh;                                                  //~v44dI~
	int 	rc,recoff,step;                                     //~5514R~
    int linenosz;                                               //~v069I~
    int csrx,csrx2;                                                //~v0izR~
    int tabbycolsw;//ii,jj;                                        //~v21rR~
    int hextabsw=0,hpos,hpose,ulhlen;                              //~v44dI~
    int cobsw;                                                     //~v67BI~
    int tabskip;                                                   //~v8@2I~
#ifdef UTF8SUPPH                                                   //~v78SI~
    int splitctr;                                                  //~v78SI~
#endif                                                             //~v78SI~
//****************************
	if (!CSRONFILELINE(Ppcw))                                   //~5514R~
		return func_nexttab_pan(Ppcw);                          //~5514I~
	pfc=Ppcw->UCWpfc;                                           //~5611I~
	pfh=pfc->UFCpfh;                                               //~v44dI~
    tabskip=pfh->UFHtabskip;                                       //~v8@2I~
    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))  //v011 browse mode  //~5611I~
		return func_nexttab_pan(Ppcw);      //v011              //~5611I~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;
	plh=psd->USDbuffc;
	if (plh->ULHtype!=ULHTDATA)                                 //~5514R~
		return func_nexttab_pan(Ppcw);                          //~5514I~
    linenosz=(int)Ppcw->UCWlinenosz;                            //~v069I~
	if (Ppcw->UCWrcsrx>=linenosz                                //~v069R~
	&&  !Gfiletabskip)                                          //~5514I~
		return func_nexttab_pan(Ppcw);                          //~5514I~
    if (Ppcw->UCWmenuopt==PANMOPARMFK_FKEY) //key assign chng      //~v0jaR~
    {                                                              //~v0izI~
    	if (UCBITCHK(plh->ULHflag4,ULHF4PROTLINE) 	//protected(change line attr)//~v0izR~
        ||  Ppcw->UCWwidth<=linenosz)                              //~v0izI~
			return func_nexttab_pan(Ppcw);                         //~v0izI~
		csrx=Ppcw->UCWrcsrx;                                       //~v0izR~
		recoff=pfc->UFCleft+csrx-linenosz;	//current col          //~v0izI~
        csrx2=FKF_PROTLEN3-pfc->UFCleft+linenosz;                  //~v0izI~
		if (pfc->UFCleft>FKF_PROTLEN3                              //~v0izR~
        ||  csrx2>=Ppcw->UCWwidth                                  //~v0izR~
		||  recoff>=FKF_PROTLEN3)                                  //~v0izR~
        {                                                          //~v0izI~
        	if (csrx<linenosz)                                     //~v0izI~
				if (rc=func_nexttab_pan(Ppcw),rc)                  //~v0izR~
    	        	return rc;                                     //~v0izI~
			return func_nexttab_pan(Ppcw);                         //~v0izI~
        }                                                          //~v0izR~
        Ppcw->UCWrcsrx=csrx2;                                      //~v0izR~
		csrloctogbl(Ppcw);  //set gbl pos                          //~v0izI~
		return 0;                                                  //~v0izI~
    }                                                              //~v0izI~
    else                                                           //~v0jiI~
        if (Ppcw->UCWmenuopt==PANMOPARMFK_KCMD) //0.1 fn key cmd   //~v0jiI~
        {                                                          //~v0jiI~
            csrx=Ppcw->UCWrcsrx;                                   //~v0jiI~
            recoff=pfc->UFCleft+csrx-linenosz;  //current col      //~v0jiI~
            csrx2=FKF_PROTLEN1-pfc->UFCleft+linenosz;              //~v0jiI~
            if (csrx<linenosz                                      //~v0jiI~
            ||  recoff<FKF_PROTLEN1)                               //~v0jiI~
            {                                                      //~v0jiI~
            	if (csrx2>=Ppcw->UCWwidth)                         //~v0jiI~
	            {                                                  //~v0jiI~
                	if (csrx<linenosz)                             //~v0jiI~
                    	if (rc=func_nexttab_pan(Ppcw),rc)          //~v0jiI~
                        	return rc;                             //~v0jiI~
                	return func_nexttab_pan(Ppcw);	//next line    //~v0jiI~
                }                                                  //~v0jiI~
                Ppcw->UCWrcsrx=csrx2;                              //~v0jiI~
                csrloctogbl(Ppcw);  //set gbl pos                  //~v0jiI~
                return 0;                                          //~v0jiI~
            }                                                      //~v0jiI~
        }//0.1                                                     //~v0jiI~
//next tab by cols                                                 //~v21rI~
	if (Ppcw->UCWfilehdrlineno>FILEHDRLINENO	//gauge displayed  //~v21rR~
	&&  !UCBITCHK(Gscrstatus,GSCRSINS)) 	//rep mode             //~v21rI~
		tabbycolsw=char2tabstopchk(Ppcw,pfc,1);//next tab          //~v21rI~
    else                                                           //~v21rI~
    {                                                              //~v44dI~
		tabbycolsw=0;                                              //~v21rI~
        if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                      //~v44dR~
        {                                                          //~v44dR~
            csrx=Ppcw->UCWrcsrx;                                   //~v44dR~
            recoff=pfc->UFCleft+max(0,csrx-linenosz);   //current col//~v44dR~
            ulhlen=plh->ULHlen;                                    //~v44dR~
//          if ((recoff+TABSKIPCTR(recoff)+1)>ulhlen)              //~v8@2R~
            if ((recoff+TABSKIPCTRF(tabskip,recoff)+1)>ulhlen)     //~v8@2I~
            {                                                      //~v44dR~
                filegethposrange(pfh,ulhlen,&hpos,&hpose);//get hex area range//~v44dR~
                hextabsw=1;                                        //~v44dR~
                if (recoff<hpos)                                   //~v44dR~
                    recoff=hpos;                                   //~v44dR~
                else                                               //~v44dR~
                    recoff=hpos+((recoff-hpos+9)/9)*9;             //~v44dR~
                Ppcw->UCWrcsrx=recoff-pfc->UFCleft+linenosz;       //~v44dR~
            }//over lrecl                                          //~v44dR~
        }//hex display mode                                        //~v44dR~
    }//not cols tab                                                //~v44dI~
	if (!UCBITCHK(Gscrstatus,GSCRSINS) 	//rep mode              //~5514R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    ||  PFH_ISEBC(pfh) //no insert char to ebcfile                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	||  !Gfiletabskip					//no tab ctr            //~5514I~
	||  tabbycolsw						//tab set by cols          //~v21rI~
	||  hextabsw    					//csr on hex part          //~v44dI~
	||  Ppcw->UCWrcsrx<linenosz)		//linenofld             //~v069R~
	{
      if (!tabbycolsw)	//not yet set by cols                      //~v21rI~
      {                                                            //~v67BI~
       if (!hextabsw)                                              //~v44dI~
       {                                                           //~v58sI~
		if (Ppcw->UCWrcsrx<linenosz		//linenofld             //~v069R~
		||  !Gfiletabskip)					//no tab ctr        //~5514I~
        {                                                       //~5514I~
          cobsw=0;                                                 //~v67BI~
          if (Ppcw->UCWrcsrx<linenosz		//linenofld            //~v67BI~
          &&  UCBITCHK(pfh->UFHflag5,UFHF5COB|UFHF5COB2)//cobol    //~v67BI~
          &&  pfc->UFCleft==SPFCOBNUMFLDLEN)    //cob display position//~v67BI~
          {                                                        //~v67BI~
          	if (plh->ULHlen<=SPFCOBNUMFLDLEN                       //~v67BR~
            ||  (plh->ULHdbcs!=0 &&  *(plh->ULHdbcs+SPFCOBNUMFLDLEN)!=TABPADCHAR))//~v67BR~
            	cobsw=1;                                           //~v67BI~
          }                                                        //~v67BI~
          if (cobsw)                                               //~v67BI~
    	    Ppcw->UCWrcsrx=linenosz;                               //~v67BI~
          else                                                     //~v67BI~
          {                                                        //~v67BI~
//  		step=TABSKIPCTR(pfc->UFCleft)+1;	                   //~v8@2R~
    		step=TABSKIPCTRF(tabskip,pfc->UFCleft)+1;              //~v8@2I~
//      	if (!Gfiletabskip || step==Gfiletabskip)               //~v8@2R~
        	if (!Gfiletabskip || step==tabskip)                    //~v8@2I~
    	    	Ppcw->UCWrcsrx=linenosz;                        //~v069R~
			else                                                //~5514I~
    	    	Ppcw->UCWrcsrx=linenosz+step;                   //~v069R~
          }//!cob                                                  //~v67BI~
		}                                                       //~5514I~
        else                                                    //~5514I~
        {                                                       //~5514I~
			recoff=pfc->UFCleft+Ppcw->UCWrcsrx-linenosz;	//current col//~v069R~
//  		Ppcw->UCWrcsrx+=TABSKIPCTR(recoff)+1;	               //~v8@2R~
    		Ppcw->UCWrcsrx+=TABSKIPCTRF(tabskip,recoff)+1;         //~v8@2I~
        }                                                       //~5514I~
       }//hextabsw                                                 //~v58sI~
      }//!tabbycolsw                                               //~v67BI~
		recoff=pfc->UFCleft+Ppcw->UCWrcsrx-linenosz;	//new col//~v069R~
//      if (*(plh->ULHdbcs+recoff)==DBCS2NDCHAR)	               //~v21rR~
#ifdef UTF8SUPPH                                                   //~v78SI~
        if (recoff<plh->ULHlen                                     //~v78SI~
        &&  UDBCSCHK_DBCSNOT1ST(*(plh->ULHdbcs+recoff))            //~v78SI~
        )                                                          //~v78SI~
        {                                                          //~v78SI~
        	splitctr=xesub_cleardbcssplit(XESUBCDSO_LEFT|XESUBCDSO_GETCTR,0/*data*/,plh->ULHdbcs+recoff,plh->ULHlen-recoff,0/*repct*/);//~v78SI~
			Ppcw->UCWrcsrx+=splitctr;                              //~va1cR~
        }                                                          //~v78SI~
#else                                                              //~v78SI~
        if (recoff<plh->ULHlen && *(plh->ULHdbcs+recoff)==DBCS2NDCHAR)//~v21rI~
			Ppcw->UCWrcsrx++;                                   //~5514R~
#endif                                                             //~v78SI~
		if (Ppcw->UCWrcsrx>=Ppcw->UCWwidth)                     //~5514I~
		{
			func_nextline(Ppcw);
//  		if (Ppcw->UCWwidth>linenosz)                           //~v21rR~
//  			return 4;                                          //~v21rR~
			return 0;                                           //~5514I~
		}
		csrloctogbl(Ppcw);  //set gbl pos                       //~5514R~
		return 0;                                               //~5514R~
	}
////insert mode and Gtabskip!=0 and cur pos>=linenosz              //~v21rR~
//    if (Ppcw->UCWfilehdrlineno>FILEHDRLINENO    //gauge displayed//~v21rR~
//    &&  !UCBITCHK(Gscrstatus,GSCRSCSRDOWN))                      //~v21rR~
//    {                                                            //~v21rR~
//        recoff=pfc->UFCleft+Ppcw->UCWrcsrx-linenosz;    //current col//~v21rR~
//        csrx2=Ppcw->UCWrcsrx+TABSKIPCTR(recoff)+1;  //new pos    //~v21rR~
//        if (tabstop=char2tabstopchk(Ppcw,pfc,Ppcw->UCWrcsrx,csrx2),tabstop)//~v21rR~
//        {                                                        //~v21rR~
////insert space char                                              //~v21rR~
//            for (rc=0,jj=0,ii=tabstop-Ppcw->UCWrcsrx;ii>0;ii--) //difference//~v21rR~
//            {                                                    //~v21rR~
//                Ppcw->UCWkeydata[0]=' ';        //space insert   //~v21rR~
//                if (rc=func_char_file(Ppcw),rc)     //insert tab //~v21rR~
//                    break;                                       //~v21rR~
//                if (rc=filecharcsr(Ppcw),rc)    //cursor move using UCWkeytype(add len)//~v21rR~
//                    break;                                       //~v21rR~
//                jj++;                                            //~v21rR~
//            }                                                    //~v21rR~
//            if (jj)                                              //~v21rR~
//                if (csrx==Ppcw->UCWrcsrx)   //not right shifted  //~v21rR~
//                {                                                //~v21rR~
//                    Ppcw->UCWrcsrx+=jj-1;                        //~v21rR~
//                    csrloctogbl(Ppcw);  //set gbl pos            //~v21rR~
//                }                                                //~v21rR~
//            return rc;                                           //~v21rR~
//        }                                                        //~v21rR~
//    }                                                            //~v21rR~
	Ppcw->UCWkeydata[0]=TABCHAR;                                //~5102R~
	if (rc=func_char_file(Ppcw),rc) 	//insert tab            //~5102R~
		return rc;
	return filecharcsr(Ppcw);	//cursor move using UCWkeytype(add len)//~5423R~
}//func_nexttab_file
//**************************************************               //~v21rI~
//* tabstop chk                                                    //~v21rI~
//* parm3:1:tab next,-1:tab prev                                   //~v21rI~
//* rc:1:csr pos set by cols                                       //~v21rR~
//**************************************************               //~v21rI~
int char2tabstopchk(PUCLIENTWE Ppcw,PUFILEC Ppfc,int Pdest)        //~v21rR~
{                                                                  //~v21rI~
    int csrx,csrx2=0,linenosz,*ptabstoppos,tabstoppos=0,tscnt,ii,recoff;//~v21rI~//~vaf9R~
//**********************************************                   //~v21rI~
    linenosz=(int)Ppcw->UCWlinenosz;                               //~v21rI~
	recoff=Ppfc->UFCleft;                                          //~v21rR~
    csrx=Ppcw->UCWrcsrx-linenosz;                                  //~v21rR~
    ptabstoppos=(int*)(void*)(Ppfc->UFCcolsdata+Ppfc->UFCcolsdatalen+1);//~v21rI~
    tscnt=*ptabstoppos++;                                          //~v21rM~
    if (!tscnt)                                                    //~v21rI~
    	return 0;		//no tabstop defined                       //~v21rI~
    if (Pdest>0)			//nexttab                              //~v21rR~
    {                                                              //~v21rI~
        if (csrx<0 && !recoff)	//in lineno fld and record offset=0//~v21rR~
        	csrx2=linenosz;                                        //~v21rI~
        else                                                       //~v21rI~
        {                                                          //~v21rI~
            for (ii=0;ii<tscnt;ii++)                               //~v21rR~
            {                                                      //~v21rR~
                tabstoppos=*ptabstoppos++;                         //~v21rR~
                tabstoppos-=recoff;                                //~v21rR~
                if (csrx<tabstoppos)                               //~v21rR~
                {                                                  //~v21rI~
					csrx2=tabstoppos+linenosz;                     //~v21rR~
                    break;                                         //~v21rR~
                }                                                  //~v21rI~
            }                                                      //~v21rR~
            if (ii==tscnt)                                         //~v21rI~
            	csrx2=Ppcw->UCWwidth;		//goto next line       //~v21rI~
        }                                                          //~v21rI~
    }                                                              //~v21rI~
    else	//backtab                                              //~v21rR~
    {                                                              //~v21rR~
        if (csrx<=0)	//in lineno fld and record offset=0        //~v21rI~
		{                                                          //~v21rI~
        	if (csrx+linenosz>0)                                   //~v21rI~
        		csrx2=0;	//back to top of lineno fld	           //~v21rI~
            else                                                   //~v21rI~
            	csrx2=-1;	//prev line                            //~v21rI~
        }                                                          //~v21rI~
        else                                                       //~v21rI~
        {                                                          //~v21rI~
            ptabstoppos+=tscnt-1;                                  //~v21rR~
            for (ii=0;ii<tscnt;ii++)                               //~v21rR~
            {                                                      //~v21rR~
                tabstoppos=*ptabstoppos--;                         //~v21rR~
                tabstoppos-=recoff;                                //~v21rR~
                if (csrx>tabstoppos) //newpos                      //~v21rR~
                {                                                  //~v21rI~
                    csrx2=tabstoppos+linenosz;                     //~v21rR~
                    break;                                         //~v21rR~
                }                                                  //~v21rI~
            }                                                      //~v21rR~
            if (tabstoppos<0 || ii==tscnt)                         //~v21rR~
            	csrx2=linenosz;                                    //~v21rI~
        }                                                          //~v21rI~
    }                                                              //~v21rI~
    Ppcw->UCWrcsrx=csrx2;                                          //~v21rI~
    return 1;                                                      //~v21rR~
}//char2tabstopchk                                                 //~v21rI~
//**************************************************            //~5514I~
//* prev tab on file record                                     //~5514I~
//**************************************************            //~5514I~
int func_prevtab_file(PUCLIENTWE Ppcw)                          //~5514I~
{                                                               //~5514I~
	PUSCRD 	 psd;                                               //~5514I~
	PULINEH  plh;                                               //~5514I~
	PUFILEC  pfc;                                               //~5514I~
	PUFILEH  pfh;                                                  //~v44dI~
	int 	 recoff=0,step,rc;                                    //~5514R~//~vaf9R~
    int      csrx;                                                 //~v0izI~
    int linenosz;                                               //~v069I~
    int hextabsw=1,hpos,hpose,ulhlen;                              //~v44dI~
    int tabskip;                                                   //~v8@2I~
#ifdef UTF8SUPPH                                                   //~va1cR~
    int splitctr;                                                  //~va1cR~
#endif                                                             //~va1cR~
//****************************                                  //~5514I~
	if (!CSRONFILELINE(Ppcw))                                   //~5514R~
		return func_prevtab_pan(Ppcw);                          //~5514I~
	pfc=Ppcw->UCWpfc;                                           //~5611M~
	pfh=pfc->UFCpfh;                                               //~v44dI~
    tabskip=pfh->UFHtabskip;                                       //~v8@2I~
    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))  //v011 browse mode  //~5611I~
		return func_prevtab_pan(Ppcw);      //v011              //~5611R~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                            //~5514I~
	plh=psd->USDbuffc;                                          //~5514I~
    linenosz=(int)Ppcw->UCWlinenosz;                            //~v069I~
	if (plh->ULHtype!=ULHTDATA      	//header line/excluded display//~5514R~
    ||  (!linenosz && !Ppcw->UCWrcsrx)    //no line number and csr is leftmost//~v21rR~
    ||  UCBITCHK(plh->ULHflag4,ULHF4PROTLINE) //protected(change line attr)//~v0izI~
    ||  Ppcw->UCWrcsrx<linenosz) 	                            //~v069R~
    {                                                           //~5514I~
//  	if (plh->ULHtype!=ULHTDATA      	//header line/excluded display//~v0j0R~
//      ||  Ppcw->UCWrcsrx)                                        //~v0j0R~
        if (Ppcw->UCWrcsrx)                                        //~v0j0I~
			return func_prevtab_pan(Ppcw);                      //~5514I~
//on top of lineno fld                                                //~v06aI~
		if (rc=func_prevtab_pan(Ppcw),rc)	//prev line         //~5514R~
			return rc;                                          //~5514I~
		if (!CSRONFILELINE(Ppcw))	//prev line is out of file data//~5514R~
        	return 0;                                           //~5514I~
		psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                        //~5514I~
		plh=psd->USDbuffc;                                      //~5514I~
//  	if (plh->ULHtype!=ULHTDATA)    	//header line/excluded display//~v0izR~
    	if (plh->ULHtype!=ULHTDATA     	//header line/excluded display//~v0izI~
    	||  UCBITCHK(plh->ULHflag4,ULHF4PROTLINE)) //protected(change line attr)//~v0izR~
		    return csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);//lineno fld top//~5514I~
        if (Ppcw->UCWmenuopt==PANMOPARMFK_FKEY) //key assign chng  //~v0jaR~
        {                                                          //~v0izI~
            csrx=FKF_PROTLEN3-pfc->UFCleft+linenosz;               //~v0izI~
            if (pfc->UFCleft>FKF_PROTLEN3                          //~v0izR~
        	||  csrx>=Ppcw->UCWwidth)                              //~v0izR~
			    return csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);//lineno fld top//~v0izI~
            Ppcw->UCWrcsrx=csrx;                                   //~v0izI~
            csrloctogbl(Ppcw);  //set gbl pos                      //~v0izI~
            return 0;                                              //~v0izI~
        }                                                          //~v0izI~
        else                                                       //~v0jiI~
	        if (Ppcw->UCWmenuopt==PANMOPARMFK_KCMD) //key assign chng//~v0jiI~
            {                                                      //~v0jiI~
                csrx=FKF_PROTLEN1-pfc->UFCleft+linenosz;           //~v0jiI~
                if (csrx>=Ppcw->UCWwidth)                          //~v0jiI~
                    return csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);//lineno fld top//~v0jiI~
			}                                                      //~v0jiI~
        Ppcw->UCWrcsrx=Ppcw->UCWwidth;	//of prev line          //~5514R~
        hextabsw=0;     //no hex tab back                          //~v44dI~
	}                                                           //~5514I~
    if (Ppcw->UCWmenuopt==PANMOPARMFK_FKEY) //key assign chng and csr is datafld//~v0jaR~
    {                                                              //~v0izI~
		recoff=pfc->UFCleft+Ppcw->UCWrcsrx-linenosz;	//current col//~v0izR~
        csrx=FKF_PROTLEN3-pfc->UFCleft+linenosz;                   //~v0izI~
		if (pfc->UFCleft>FKF_PROTLEN3                              //~v0izI~
        ||  csrx>=Ppcw->UCWwidth                                   //~v0izI~
		|| recoff<=FKF_PROTLEN3)                                   //~v0izI~
			return csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);//lineno fld top//~v0izI~
        Ppcw->UCWrcsrx=csrx;                                       //~v0izR~
		csrloctogbl(Ppcw);  //set gbl pos                          //~v0izI~
		return 0;                                                  //~v0izI~
    }                                                              //~v0izI~
	if (!Gfiletabskip)					//no tab skip           //~5514I~
    {                                                           //~5514I~
		func_prevtab_pan(Ppcw);                                 //~5514I~
    	step=0;                                                 //~5514M~
        hextabsw=0;     //no hex tab back                          //~v44dI~
    }                                                           //~5514I~
    else                                                        //~5514I~
    {                                                           //~5514I~
		recoff=pfc->UFCleft+Ppcw->UCWrcsrx-linenosz;	//current col//~v069R~
//  	if(!(step=Gfiletabskip-TABSKIPCTR(recoff)-1))	//on the column//~v8@2R~
    	if(!(step=tabskip-TABSKIPCTRF(tabskip,recoff)-1))	//on the column//~v8@2I~
//  		step=Gfiletabskip;                                     //~v8@2R~
    		step=tabskip;                                          //~v8@2I~
    }                                                           //~5514I~
    csrx=Ppcw->UCWrcsrx;    //before value                         //~v0jiI~
    if (Ppcw->UCWfilehdrlineno>FILEHDRLINENO)   //gauge displayed  //~v21rM~
        if (char2tabstopchk(Ppcw,pfc,-1))                          //~v21rI~
        {                                                          //~v44dI~
        	step=0;				//already rcsrx set                //~v21rI~
            hextabsw=0;                                            //~v44dI~
        }                                                          //~v44dI~
    if (hextabsw)   //hex chk                                      //~v44dI~
    {                                                              //~v44dI~
        if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                      //~v44dI~
        {                                                          //~v44dI~
            ulhlen=plh->ULHlen;                                    //~v44dI~
            filegethposrange(pfh,ulhlen,&hpos,&hpose);//get hex area range//~v44dI~
            if (recoff>hpos)                                       //~v44dI~
                step=recoff-(hpos+((recoff-1-hpos)/9)*9);          //~v44dI~
        }//hex display mode                                        //~v44dI~
    }//hex chk                                                     //~v44dI~
	if ((Ppcw->UCWrcsrx-=step)>=linenosz)                       //~v069R~
    {                                                           //~5514I~
		recoff=pfc->UFCleft+Ppcw->UCWrcsrx-linenosz;	//new col//~v069R~
        if (Ppcw->UCWmenuopt==PANMOPARMFK_KCMD) //key assign chng  //~v0jiM~
        {                                                          //~v0jiM~
			csrx=pfc->UFCleft+csrx-linenosz;	//before value     //~v0jiI~
            if (recoff<FKF_PROTLEN1)                               //~v0jiI~
            {                                                      //~v58sI~
                if  (csrx>FKF_PROTLEN1)                            //~v0jiI~
					Ppcw->UCWrcsrx+=csrx-FKF_PROTLEN1;	//top of cmd input//~v0jiI~
                else                                               //~v0jiI~
					Ppcw->UCWrcsrx=0;                              //~v0jiR~
            }//recoff                                              //~v58sI~
        }                                                          //~v0jiI~
#ifdef UTF8SUPPH                                                   //~va1cR~
        if (recoff<plh->ULHlen                                     //~va1cR~
        &&  UDBCSCHK_DBCSNOT1ST(*(plh->ULHdbcs+recoff))            //~va1cR~
        )                                                          //~va1cR~
        {                                                          //~va1cR~
        	splitctr=xesub_cleardbcssplit(XESUBCDSO_RIGHT|XESUBCDSO_GETCTR,0/*data*/,plh->ULHdbcs,recoff,0/*repct*/);//~va1cR~
			Ppcw->UCWrcsrx-=splitctr;                              //~va1cR~
        }                                                          //~va1cR~
#else                                                              //~va1cR~
//      if (*(plh->ULHdbcs+recoff)==DBCS2NDCHAR)	               //~v21rR~
        if (recoff<plh->ULHlen && *(plh->ULHdbcs+recoff)==DBCS2NDCHAR)//~v21rI~
			Ppcw->UCWrcsrx--;                                   //~5514I~
#endif                                                             //~va1cR~
    }                                                           //~5514I~
	if (Ppcw->UCWrcsrx<linenosz)                                //~v069R~
    {                                                                 //~v069I~
    	if (!linenosz)                                                //~v069I~
        {                                                             //~v069I~
			Ppcw->UCWrcsrx=0;   //prepare to contine step to end line //~v069I~
			return func_prevtab_file(Ppcw);	//end of prev line        //~v069I~
        }                                                             //~v069I~
	    return csronthefld(Ppcw,Ppcw->UCWrcsry,0,0);//lineno fld top//~5514I~
	}                                                                 //~v069I~
	csrloctogbl(Ppcw);  //set gbl pos                           //~5514I~
	return 0;                                                   //~5514I~
}//func_prevtab_file                                            //~5514I~
                                                                //~5514I~
//****************************************************************//~5211I~
// chacap                                                       //~5211R~
// line override to destination line                            //~5211R~
//*parm 1:pcw                                                   //~5211I~
//*parm 2:mode (copy on,block rep,block insert)                 //~5211R~
//*parm 3:source ulh                                            //~5211R~
//*parm 4:destination plh                                       //~5211R~
//*parm 5:override position                                     //~5211R~
//*return:0:ok,16:mergin err or UALLOC_FAILED                      //~v0avR~
//****************************************************************//~5211I~
int charcap(PUCLIENTWE Ppcw,int Pmode,PULINEH Pplhs,PULINEH Pplhd,int Poffs)//~5211R~
{                                                               //~5211I~
    UCHAR *pc,*pcd,*pcs,*pcsd;                                     //~v67VR~
    UCHAR *pc0,*pcd0;                                              //~v0eiI~
//  UCHAR *pcde;                                                   //~v67VR~
    UCHAR *pcdebefore;                                             //~v67VI~
    int reclen,reslen,srclen,len,ii,/*dbcssw=0,*/orgdestlen;        //~5503R~//~vaa7R~
#ifndef UTF8SUPPH                                                  //~vaa7I~
    int dbcssw=0;                                                  //~vaa7I~
#endif                                                             //~vaa7I~
    int rc,mergin;                                                 //~v0avR~
    int oomlen;                                                    //~v0dmI~
//  int contlen;                                                   //~v0efR~
    int topcidpos,cidlen,topcidend;                                //~v0ebI~
    int revupdateonlysw=0;                                         //~v67VI~
    int updatesw=0;                                                //~v67VI~
    int shortrecovf=0,revlen;                                      //~v71UR~
    PUFILEH pfhd;                                                  //~v0avI~
    PUFILEH pfhs;                                                  //~v0ebI~
    int imlen;                                                     //~v73uI~
    int lcmdsw,bndsoffs1,bndsoffs2,srcoffs=0,merginchkopt=0;       //~v74ER~
    int srcdbcssplitsw;                                            //~v74HI~
#ifdef UTF8SUPPH                                                   //~va1cR~
	int jj,srcsplittopend,srcsplitendstart,dbcsskipctr=0,splitctr; //~va1cR~
#endif                                                             //~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
    int rcmc,srclencv;                                             //~va20R~
    UCHAR *pcscv,*pcsdcv;                                          //~va20R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50R~
    int swutf8file;                                                //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    int optsetsosi=0,rcsetsosi=0;                                      //~va8bR~//~vaf9R~
//****************************                                  //~5211I~
    lcmdsw=Pmode & CHAROPLCMD;                                     //~v74EI~
    Pmode &=~CHAROPLCMD;                                           //~v74EI~
//  if (undoupdate(Ppcw,Pplhd,UUHTREP)==UALLOC_FAILED) //reset flag CURFOUND//~v0avR~
//  	return UALLOC_FAILED;                                      //~v0avR~
  	revupdateonlysw=(Pmode==CHAROPON || Pmode==CHAROPNICHE); 	//copy o/n//~v67VM~
	if (!Pplhs->ULHdbcs)	//not once displayed                //~5212R~
		if (filechktabdbcs(Pplhs)==UALLOC_FAILED)//expand data len//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
	if (!Pplhd->ULHdbcs)	//not once displayed                //~5212R~
		if (filechktabdbcs(Pplhd)==UALLOC_FAILED)//expand data len//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
    pfhd=UGETPFH(Pplhd);                                           //~v0avI~
    mergin=pfhd->UFHmergin;                                        //~v0avI~
//  srclen=filecidlrecl(Pplhs,UGETPFH(Pplhs));                     //~v0ebR~
    pfhs=UGETPFH(Pplhs);                                           //~v0ebR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swutf8file=FILEUTF8MODE(pfhd);                                 //~va50R~
    swebcfile=PFH_ISEBC(pfhd);                                     //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    cidlen=filegetcidlenc(Pplhs,pfhs,&srclen,&topcidpos,0,&srclen);//no topcidpos//~v42eR~
    if (lcmdsw)                                                    //~v74EI~
    {                                                              //~v74EI~
        bndsoffs1=pfhs->UFHbndscol1-1;	//source line bounds       //~v74EI~
        bndsoffs2=pfhs->UFHbndscol2;                               //~v74EI~
        if (bndsoffs1>0)                                           //~v74EI~
            srcoffs=bndsoffs1;                                     //~v74EI~
        if (bndsoffs2>0)                                           //~v74EI~
        	srclen=max(0,min(srclen,bndsoffs2)-srcoffs);           //~v74EI~
        bndsoffs1=pfhd->UFHbndscol1-1;  //dest line bounds         //~v74EI~
        bndsoffs2=pfhd->UFHbndscol2;                               //~v74EI~
        BNDS_ADJUSTPOS(bndsoffs1,bndsoffs2,Poffs);//update Poffs by bnds parm//~v74EI~
        if (bndsoffs2>0)                                           //~v74EI~
        {                                                          //~v74EI~
            mergin=min(mergin,bndsoffs2);                          //~v74EI~
            merginchkopt=MERGIN_BNDS;	//right bnds chk           //~v74EI~
        }                                                          //~v74EI~
    }                                                              //~v74EI~
//  if (contlen)                                                   //~v0efR~
//      srclen=pfhs->UFHmergin;                                    //~v0efR~
    topcidend=topcidpos+cidlen;                                    //~v0ebR~
    orgdestlen=Pplhd->ULHlen;                                   //~5503I~
	reslen=orgdestlen-Poffs;                                    //~5503R~
    pcs=Pplhs->ULHdata;                                            //~v0avI~
    pcsd=Pplhs->ULHdbcs;                                           //~va20R~//~va2iM~
    if (lcmdsw)                                                    //~v74EI~
    {                                                              //~va2iI~
    	pcs+=srcoffs;                                              //~v74EI~
    	pcsd+=srcoffs;                                             //~va20R~//~va2iM~
    }                                                              //~va2iI~
#ifdef UTF8UCS2                                                    //~va20R~
	rcmc=xeutf_modechng(0,pfhd,pfhs,pcs,pcsd,srclen,&pcscv,&pcsdcv,&srclencv);//~va20R~
    UALLOCCHKRC(rcmc);                                             //~va20R~
    if (rcmc)	//different utf8 mode                              //~va20R~
    {                                                              //~va20R~
    	pcs=pcscv;                                                 //~va20R~
    	pcsd=pcsdcv;                                               //~va20R~
    	srclen=srclencv;                                           //~va20R~
    }                                                              //~va20R~
#endif                                                             //~va20R~
    if (swebcfile && (Pmode==CHAROPBINS||Pmode==CHAROPBREP))       //~va8bI~
    {                                                              //~va8bI~
        optsetsosi=0;                                              //~va8bR~
        if (Pmode==CHAROPBINS)                                     //~va8bI~
        	optsetsosi|=XEEBCSO_CAPINS;                            //~va8bR~
		rcsetsosi=xeebc_filesetsosiplh(optsetsosi,pfhd,Pplhd,Poffs,pcs,pcsd,srclen,&pcscv,&pcsdcv,&srclencv);//~va8bR~
        UALLOCCHKRC(rcsetsosi);                                    //~va8bI~
        rcmc=1; //restore sorce addr                               //~va8bI~
    	pcs=pcscv;                                                 //~va8bI~
    	pcsd=pcsdcv;                                               //~va8bI~
    	srclen=srclencv;                                           //~va8bI~
    }                                                              //~va8bI~
    rc=0;                                                          //~v0eII~
    if (UCBITCHK(Pplhs->ULHflag2,ULHF2TABFOUND))    //may yet have tab//~v66gI~
    	UCBITON(Pplhd->ULHflag2,ULHF2TABFOUND);		               //~v66gI~
    if (Pmode==CHAROPBINS)                                      //~5219R~
    {                                                              //~v0avI~
      if (Poffs<mergin)                                            //~v0eII~
      {                                                            //~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
        rc=filemerginchk(Pplhd,Poffs,pcs,pcsd,srclen,0,//dellen=0  //~va20I~
#else                                                              //~va20I~
        rc=filemerginchk(Pplhd,Poffs,pcs,srclen,0,//dellen=0       //~v0c2R~
#endif                                                             //~va20I~
						MERGIN_SHORTRECOK| //accept merginover flow is space only for short record//~v71UI~
                        merginchkopt|                              //~v74EI~
						MERGIN_NOMSG,0,0,&oomlen);//adden=netlen=0 //~v0dmR~
        if (!rc && oomlen<0)    //short record space overflow      //~v71UI~
        {                                                          //~v71UI~
            shortrecovf=1;                                         //~v71UI~
            oomlen=0;                                              //~v71UI~
        }                                                          //~v71UI~
      }                                                            //~v71UI~
      else                                                         //~v0eII~
        oomlen=0;   //no shift back                                //~v0eII~
    	reclen=Poffs+srclen+max(reslen,0);                         //~v0avR~
    }                                                              //~v0avI~
    else                                                        //~5219I~
    {                                                              //~v0avI~
    	oomlen=0;                                                  //~v0dmI~
//      if (Poffs+srclen>mergin)                                   //~v0eIR~
//      	rc=4;				//mergin err                       //~v0eIR~
//  	else                                                       //~v0eIR~
//      	rc=0;                                                  //~v0eIR~
        if (Poffs<mergin && Poffs+srclen>mergin)//overflow case    //~v0eII~
//            if (UCBITCHK(pfhd->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR)//spf file//~v417R~
//            ||  (UCBITCHK(pfhd->UFHflag2,UFHF2MERGIN)            //~v417R~
//                 && !UCBITCHK(pfhd->UFHflag3,UFHF3OOMNOPROT)))//prot mergin file//~v417R~
//          if (UCBITCHK(pfhd->UFHflag2,UFHF2MERGIN))              //~v42dR~
//          if (UCBITCHK(pfhd->UFHflag2,UFHF2MERGIN)               //~v42eR~
//          && !UCBITCHK(pfhd->UFHflag3,UFHF3OOMNOPROT))//prot mergin file//~v42eR~
//          if (UCBITCHK(pfhd->UFHflag2,UFHF2MERGIN))              //~v42eR~
//               rc=4;	//mergin overflow                          //~v42eR~
            srclen=mergin-Poffs;    //limit to copy avail len      //~v42eI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (!swebcfile)                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            if (UDBCSCHK_DBCSNOTEND(*(pcsd+srclen-1)))             //~va2iI~
            {                                                      //~va2iI~
            	srclen-=XESUB_DBCSSPLITCTR_L(pcsd,srclen);         //~va2iI~
                if (srclen<=0)                                     //~va2iI~
                    rc=4;                                          //~va2iI~
            }                                                      //~va2iI~
      if (revupdateonlysw&&!srclen)	//source len=0                 //~v67VI~
		reclen=Pplhd->ULHlen;	//no update                        //~v67VI~
      else                                                         //~v67VI~
    	reclen=Poffs+max(reslen,srclen);                           //~v0avI~
    }                                                              //~v0avI~
	if (rc>=4)                                                     //~v0avI~
    	return 16;  //mergin err                                   //~v0avR~
    if (reclen>MAXLINEDATA)                                        //~v0eII~
    	return 16;                                                 //~v0eII~
//*can be insert                                                   //~v0avI~
  if (!revupdateonlysw)                                            //~v67VI~
  {                                                                //~v67VI~
    if (undoupdate(Ppcw,Pplhd,UUHTREP)==UALLOC_FAILED) //reset flag CURFOUND//~v0avI~
    	return UALLOC_FAILED;                                      //~v0avI~
  }                                                                //~v67VI~
	if (reclen>Pplhd->ULHbufflen)                               //~5211R~
		if (fileexpandbuff(Pplhd,reclen)==UALLOC_FAILED)		//expand buff//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
                                                                   //~v67VI~
    pcdebefore=Pplhd->ULHdbcs+Pplhd->ULHlen; //override tab chk end addr//~v67VI~
  if (!revupdateonlysw)                                            //~v67VI~
	Pplhd->ULHlen=reclen;                                       //~5211I~
    pc0 =Pplhd->ULHdata;                                           //~v0eiI~
    pcd0=Pplhd->ULHdbcs;                                           //~v0eiI~
    pc =pc0+Poffs;                                                 //~v0eiR~
    pcd=pcd0+Poffs;                                                //~v0eiR~
//  pcde=pcd0+reclen;                                              //~v67VR~
    pcs=Pplhs->ULHdata;                                            //~v0avM~
    pcsd=Pplhs->ULHdbcs;                                           //~v0avM~
    if (lcmdsw)                                                    //~v74EI~
    {                                                              //~v74EI~
    	pcs+=srcoffs;                                              //~v74EI~
    	pcsd+=srcoffs;                                             //~v74ER~
    }                                                              //~v74EI~
#ifdef UTF8UCS2                                                    //~va20R~
	if (rcmc)                                                      //~va20R~
    {                                                              //~va20R~
	    pcs=pcscv;                                                 //~va20R~
    	pcsd=pcsdcv;                                               //~va20R~
    }                                                              //~va20R~
#endif                                                             //~va20R~
  if (!revupdateonlysw)                                            //~v67VI~
    charcaprev(Pplhd,Poffs,srclen);	//set reverse                  //~v06MI~
                                                                   //~v06MI~
//add space before csr or shift post data                       //~5211I~
	if (reslen<=0)	//out of reclen                             //~5211R~
	{                                                           //~5211I~
      if (!revupdateonlysw||srclen)                                //~v67VI~
      {                                                            //~v67VI~
        if (revupdateonlysw)                                       //~v67VI~
        {                                                          //~v67VI~
			if (charcaponundoprep(Ppcw,srclen,Pplhd,Poffs,reclen)) //~v67VI~
    			return UALLOC_FAILED;                              //~v67VI~
        }                                                          //~v67VI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		UCVEBC_memset_space(swebcfile,pc+reslen,(UINT)(-reslen));  //~va50R~
#else                                                              //~va50I~
		memset(pc+reslen,' ',(UINT)(-reslen));                  //~5211R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		memset(pcd+reslen,0,(UINT)(-reslen));                      //~v74aI~
		memcpy(pc ,pcs ,(UINT)srclen);                          //~5211R~
		memcpy(pcd,pcsd,(UINT)srclen);                          //~5211I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		xesub_setdbcssplit(swebcfile,Pplhd,pc,pcd,srclen,' ');     //~va50R~
		XEEBC_setdbcstblplh(swebcfile,pfhd,Pplhd);//re-evaluate dbcstbl//~va8bI~
#else                                                              //~va50I~
		setdbcssplit(pc,pcd,srclen,' ');                           //~v74HI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
      }                                                            //~v67VI~
	}                                                           //~5211I~
	else                                                        //~5211I~
	{                                                           //~5211I~
		switch (Pmode)                                          //~5211I~
		{                                                       //~5211I~
		case CHAROPON:	//copy on                               //~5211R~
		case CHAROPNICHE:	//copy n                               //~v58sI~
//del tab at boundary                                           //~5211I~
//            for (pctab=pcd;*pctab==TABCHAR||*pctab==TABPADCHAR;pctab--)//~v67VR~
//                *pctab=0;   //reset boundary tab                 //~v67VR~
//  		for (pctab=pcd+srclen;*pctab==TABPADCHAR;pctab++)      //~v67HR~
//            for (pctab=pcd+srclen;pctab<pcde && *pctab==TABPADCHAR;pctab++)//~v67VR~
//                *pctab=0;   //reset boundary tab                 //~v67VR~
//*rep space data clear tab                                     //~5211I~
#ifdef UTF8SUPPH                                                   //~va1cR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (swebcfile)                                           //~va50I~
          {                                                        //~va50I~
            srcsplittopend=0;	//left boundary dbcs split inner count//~va50I~
            srcsplitendstart=srclen;   //right boundary dbcssplit inner count//~va50I~
          }                                                        //~va50I~
          else                                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
          {                                                        //~va50I~
            srcsplittopend=XESUB_DBCSSPLITCTR_R(pcsd,srclen);	//left boundary dbcs split inner count//~va1cR~
            srcsplitendstart=srclen-XESUB_DBCSSPLITCTR_L(pcsd,srclen);   //right boundary dbcssplit inner count//~va1cR~
          }                                                        //~va50I~
#endif                                                             //~va1cR~
            for (ii=0;ii<srclen;reslen--,ii++,pcs++,pcsd++,pc++,pcd++)//~5211R~
			{                                                   //~5211I~
              if (ii<topcidpos || ii>=topcidend)                   //~v0ebR~
              {                                                    //~v0ebI~
			   if (Pmode==CHAROPNICHE)                             //~v58sI~
               {                                                   //~v58sI~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
				if (reslen<=0||UCVEBCUTF_nespace(swebcfile,swutf8file,*pcs,*pcsd))	//src is not space or previously override dbcs 1st//~va50R~
    #else                                                          //~va50I~
				if (reslen<=0||UTFDD_ISNOTSPACE(*pcs,*pcsd))	//src is not space or previously override dbcs 1st//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
				if (reslen<=0||*pcs!=' ')	//src is not space or previously override dbcs 1st//~v58sR~
#endif                                                             //~va20R~
				{                                                  //~v58sI~
                	if (!updatesw) //1st time                      //~v67VI~
                    {                                              //~v67VI~
                    	updatesw=1;                                //~v67VI~
						if (charcaponundoprep(Ppcw,srclen,Pplhd,Poffs,reclen))//~v67VI~
	    					return UALLOC_FAILED;                  //~v67VI~
                    }                                              //~v67VI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                  if (swebcfile)    //no dbcssplit consideration, but re-evaluate later//~va50I~
                  {                                                //~va50I~
		 	 		*pc=*pcs;                                      //~va50I~
		 	 		*pcd=*pcsd;                                    //~va50I~
                  }                                                //~va50I~
                  else                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                  {//!ebcfile                                      //~va50I~
                	if (reslen>0)                                  //~v58sI~
                    {                                              //~v58sI~
//#ifdef UTF8UCS4                                                    //~va3xR~//~vaw1R~
#ifdef UTF8UCS416       //FIXME test surrogate:FIXED: nich lcmd treate surrogate pair as 2 byte//~vaw1R~
                        switch(UDBCSCHK_TEMPDBCSID(*pcd))          //~va3xR~
#else                                                              //~va3xR~
                        switch(*pcd)                               //~v58sR~
#endif                                                             //~va3xR~
                        {                                          //~v58sR~
#ifdef UTF8SUPPH                                                   //~va1cR~
                        case UDBCSCHK_DBCS1ST:                     //~va1cR~
                        case UDBCSCHK_DBCS2ND:                     //~va1cR~
                        case UDBCSCHK_DBCSPAD:                     //~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
                        case UDBCSCHK_DBCS1STUCS_CASE():           //~va20R~
                        case UDBCSCHK_DBCS2NDUCS_CASE():           //~va20R~
#endif                                                             //~va20R~
//*!ebc                                                            //~va50I~
                            xesub_cleardbcs1(0,pc0,pcd0,orgdestlen,Poffs+ii,' ');//clear dbcs at the offset//~va1cR~
                            break;                                 //~va1cR~
#else                                                              //~va1cR~
                        case DBCS1STCHAR:   //dbcs 1st char replaced//~v58sR~
//*!UTF8SUPPH                                                      //~va50I~
                            *(pc+1)=' ';                           //~v58sR~
                            *(pcd+1)=0; //clear dbcs 2nd byte      //~v58sR~
                            break;                                 //~v58sR~
                        case DBCS2NDCHAR:                          //~v58sR~
                            if (!dbcssw)    //target original is dbcs 2nd//~v58sR~
                            {                                      //~v58sR~
//*!UTF8SUPPH                                                      //~va50I~
                                *(pc-1)=' ';                       //~v58sR~
                                *(pcd-1)=0;                        //~v58sR~
                            }                                      //~v58sR~
                            break;                                 //~v58sR~
#endif                                                             //~va1cR~
//*!ebc                                                            //~va50I~
                        case TABCHAR:                              //~v67VI~
						case TABPADCHAR://target line tab space    //~v67VI~
							chartabrep(pcd,pcdebefore);            //~v67VR~
                            break;                                 //~v67VI~
                        }//sw by dbcs                              //~v58sR~
                    }                                              //~v58sI~
#ifdef UTF8SUPPH                                                   //~va1cR~
                  if (ii<srcsplittopend||ii>=srcsplitendstart)     //~va1cR~
#else                                                              //~va1cR~
                  if ((*pcsd==DBCS2NDCHAR && ii==0)                //~v74HR~
                  ||  (*pcsd==DBCS1STCHAR && ii+1==srclen))        //~v74HI~
#endif                                                             //~va1cR~
                  {                                                //~v74HI~
//*!ebc                                                            //~va50I~
		 	 		*pc=' ';                                       //~v74HI~
		 	 		*pcd=0;                                        //~v74HI~
                  }                                                //~v74HI~
				  else                                             //~v74HI~
                  {                                                //~v74HI~
		 	 		*pc=*pcs;                                      //~v58sI~
		 	 		*pcd=*pcsd;                                    //~v58sI~
                  }                                                //~v74HI~
#ifndef UTF8SUPPH                                                  //~vaa7I~
#ifdef UTF8UCS2                                                    //~va20R~
                    dbcssw=UDBCSCHK_DBCS1STLU(*pcd);//dbcs1st char is copyed(dbcssw is not used more, but)//~va20R~
#else                                                              //~va20R~
                    dbcssw=*pcd==DBCS1STCHAR;//dbcs1st char is copyed//~v58sI~
#endif                                                             //~va20R~
#endif   //!UTF8SUPPH                                              //~vaa7I~
//*!ebc                                                            //~va50I~
     	 	 	    if (*pcd==TABCHAR||*pcd==TABPADCHAR)           //~v67VI~
    				    *pcd=0;		//reset tab of override range  //~v67VI~
                  }//!ebcfile                                      //~va50I~
				}                                                  //~v58sI~
               }//niche                                            //~v58sI~
               else                                                //~v58sI~
               {                                                   //~v58sI~
//************                                                     //~va50I~
//*COPYON    *                                                      //~va20R~//~va50R~
//************                                                     //~va50I~
#ifdef UTF8SUPPH                                                   //~va1cR~
                srcdbcssplitsw=0;                                  //~va1cR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
              if (!swebcfile)                                      //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
              {//!ebc                                              //~va50I~
                if (ii<srcsplittopend||ii>=srcsplitendstart)       //~va1cR~
                {                                                  //~va1cR~
                    if (reslen>=0)                                 //~va1cR~
                    	continue;                                  //~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
                    if (UDBCSCHK_ISCOMPOSEDDBCS(*pcsd))            //~va20R~
#else                                                              //~va20R~
                    if (UDBCSCHK_DBCSCOLS(*pcsd))    	           //~va1cR~
#endif                                                             //~va20R~
		                srcdbcssplitsw=1;  	//set space            //~va1cR~
                }                                                  //~va1cR~
                else                                               //~va1cR~
                if (dbcsskipctr>0)                                 //~va1cR~
                {                                                  //~va1cR~
                	dbcsskipctr--;                                 //~va1cR~
		            srcdbcssplitsw=1;  	//set space                //~va1cR~
                }                                                  //~va1cR~
                else                                               //~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
                if (UDBCSCHK_DBCS1STLU(*pcsd))                     //~va20R~
#else                                                              //~va20R~
                if (*pcsd==UDBCSCHK_DBCS1ST)                       //~va1cR~
#endif                                                             //~va20R~
                {                                                  //~va1cR~
//*chk available space for source dbcs copy                        //~va50I~
                    splitctr=XESUB_DBCSSPLITCTR(pcsd,srclen-ii,0); //~va1cR~
                    for (jj=0;jj<splitctr;jj++)                    //~va1cR~
#ifdef UTF8UCS2                                                    //~va20R~
//!ebc                                                             //~va50I~
                          if (jj<reslen && UTFDD_ISNOTSPACE(*(pc+jj),*(pcd+jj)))  //dbcs target is not all apace//~va20R~
#else                                                              //~va20R~
                          if (jj<reslen && *(pc+jj)!=' ')  //dbcs target is not all apace//~va1cR~
#endif                                                             //~va20R~
                              break;                               //~va1cR~
                    if (jj<splitctr)  //non space found            //~va1cR~
                    {                                              //~va1cR~
		                srcdbcssplitsw=1;  	//set space            //~va1cR~
                      	dbcsskipctr=splitctr-1; //next n byte copy skip//~va1cR~
                    }                                              //~va1cR~
                }                                                  //~va1cR~
#endif                                                             //~va1cR~
              }//!ebc                                              //~va50I~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
				if (reslen<=0 || UCVEBCUTF_eqspace(swebcfile,swutf8file,*pc,*pcd))	//src is not space or previously override dbcs 1st//~va50R~
	#else                                                          //~va50I~
				if (reslen<=0 || UTFDD_ISSPACE(*pc,*pcd))	//src is not space or previously override dbcs 1st//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
				if (reslen<=0 || *pc==' ')                      //~5211R~
#endif                                                             //~va20R~
				{                                               //~5211I~
                	if (!updatesw) //1st time                      //~v67VI~
                    {                                              //~v67VI~
                    	updatesw=1;                                //~v67VI~
						if (charcaponundoprep(Ppcw,srclen,Pplhd,Poffs,reclen))//~v67VI~
	    					return UALLOC_FAILED;                  //~v67VI~
                    }                                              //~v67VI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                  if (swebcfile)                                   //~va50I~
                  {                                                //~va50I~
		 	 		*pc=*pcs;                                      //~va50I~
		 	 		*pcd=*pcsd;                                    //~va50I~
                  }                                                //~va50I~
                  else                                             //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                  {//!ebc                                          //~va50I~
#ifdef UTF8SUPPH                                                   //~va1cR~
#else                                                              //~va1cR~
                    srcdbcssplitsw=0;                              //~v74HI~
					switch(*pcsd)                               //~5211R~
					{                                           //~5211I~
					case DBCS1STCHAR:                           //~5211I~
                      if (ii+1==srclen)                            //~v74HI~
                      {                                            //~v74HI~
                        	srcdbcssplitsw=1;                      //~v74HI~
                            dbcssw=0;                              //~v74HI~
                      }                                            //~v74HI~
                      else                                         //~v74HI~
                      {                                            //~v74HI~
//*!UTF8SUPPH                                                   //~va20R~//~va50R~
						if (reslen>1 && *(pc+1)!=' ')           //~5212R~
							continue;                           //~5211I~
						dbcssw=1;                               //~5211I~
                      }                                            //~v74HI~
						break;                                  //~5211I~
					case DBCS2NDCHAR:                           //~5211I~
                      if (ii==0)                                   //~v74HI~
                      {                                            //~v74HI~
                        	srcdbcssplitsw=1;                      //~v74HI~
                            dbcssw=0;                              //~v74HI~
                      }                                            //~v74HI~
                      else                                         //~v74HI~
                      {                                            //~v74HI~
						if (!dbcssw)                            //~5211I~
                        {                                          //~v77dI~
                          if (reslen<=0)    //over target EOL      //~v77dI~
                        	srcdbcssplitsw=1;   //set space        //~v77dI~
                          else                                     //~v77dI~
							continue;                           //~5211I~
                        }                                          //~v77dI~
						dbcssw=0;                               //~5211I~
                      }                                            //~v74HI~
						break;                                  //~5211I~
					default:                                    //~5211I~
						dbcssw=0;                               //~5211I~
					}//sw by dbcs                               //~5211R~
#endif //!UTF8SUPPH                                                //~va1cR~
//*!ebc                                                            //~va50I~
                    if (*pcd==TABCHAR||*pcd==TABPADCHAR)//target line tab space//~v67VI~
						chartabrep(pcd,pcdebefore);                //~v67VR~
                  if (srcdbcssplitsw)                              //~v74HI~
                  {                                                //~v74HI~
//!ebc                                                             //~va50I~
		 	 		*pc=' ';                                       //~v74HI~
		 	 		*pcd=0;                                        //~v74HI~
                  }else                                            //~v74HI~
                  {                                                //~v74HI~
		 	 		*pc=*pcs;                                   //~5211R~
		 	 		*pcd=*pcsd;                                 //~5211I~
                  }                                                //~v74HI~
//*!ebc                                                            //~va50I~
     	 	 	    if (*pcd==TABCHAR||*pcd==TABPADCHAR)           //~v67VI~
    				    *pcd=0;		//reset tab of override range  //~v67VI~
                  }//!ebc                                          //~va50I~
//tgt space                                                        //~va50I~
				}                                               //~5211I~
               }//niche or on                                      //~v58sI~
//  	 	 	if (*pcd==TABCHAR||*pcd==TABPADCHAR)               //~v67VR~
//  				*pcd=0;		//reset tab of override range      //~v67VR~
              }                                                    //~v0ebI~
              else	//cid pos                                      //~v0ebI~
				if (reslen<=0)                                     //~v0ebI~
	            {                                                  //~v0ebI~
                	if (!updatesw) //1st time                      //~v67VI~
                    {                                              //~v67VI~
                    	updatesw=1;                                //~v67VI~
						if (charcaponundoprep(Ppcw,srclen,Pplhd,Poffs,reclen))//~v67VI~
	    					return UALLOC_FAILED;                  //~v67VI~
                    }                                              //~v67VI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		 	 		*pc=UCVEBC_CHAR_SPACE(swebcfile);              //~va50R~
#else                                                              //~va50I~
		 	 		*pc=' ';                                       //~v0ebI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		 	 		*pcd=0;                                        //~v0ebI~
              	}                                                  //~v0ebI~
			}//loop by source len                               //~5211I~
			break;                                              //~5211I~
                                                                //~5211I~
		case CHAROPBREP:	//block replace                     //~5211R~
//del tab at boundary                                           //~5211I~
//  	 	for (pctab=pcd;*pctab==TABCHAR||*pctab==TABPADCHAR;pctab--)//~5503R~
//  			*pctab=0;	//reset boundary tab                //~5503R~
//  		for (pctab=pcd+srclen;*pctab==TABPADCHAR;pctab++)   //~5503R~
//  			*pctab=0;	//reset boundary tab                //~5503R~
//*block override                                               //~5211I~
//   	 	if (*pcd==DBCS2NDCHAR)	//start with second byte    //~5503R~
//  		{                                                   //~5503R~
//  			*(pc-1)=*pc=' ';                                //~5503R~
//  			*(pcd-1)=*pcd=0;                                //~5503R~
//  		}                                                   //~5503R~
//  		if (*(pcd+srclen)==DBCS2NDCHAR)//last repl repled 1st byte//~5503R~
//  		{                                                   //~5503R~
//           	*(pc+srclen)=' ';                               //~5503R~
//              *(pcd+srclen)=0;                                //~5503R~
//  		}                                                   //~5503R~
//*boundary ajust for tab and dbcs                              //~5503I~
    	  if (swebcfile)                                           //~va8bI~
			xeebc_filesetsosiplhupdate(optsetsosi,rcsetsosi,pfhd,Pplhd,Poffs,orgdestlen,pcs,pcsd,srclen);//~va8bR~
          else                                                     //~va8bI~
          {                                                        //~va8bI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	setobtabdbcs(swebcfile,0,Pplhd->ULHdata,Pplhd->ULHdbcs,orgdestlen,//~va50I~
							Poffs,srclen);                         //~va50I~
#else                                                              //~va50I~
        	setobtabdbcs(Pplhd->ULHdata,Pplhd->ULHdbcs,orgdestlen,//~5503I~
							Poffs,srclen);                      //~5503I~
#endif                                                             //~va50M~
			memcpy(pc ,pcs,(UINT)srclen);                       //~5211R~
			memcpy(pcd,pcsd,(UINT)srclen);                      //~5211R~
          }                                                        //~va8bI~
			break;                                              //~5211I~
                                                                //~5211I~
		case CHAROPBINS:	//block replace                     //~5211R~
//dbcs split                                                    //~5211I~
//   	 	if (*pcd==DBCS2NDCHAR)	//start with second byte    //~5503R~
//  		{                                                   //~5503R~
//  			*(pc-1)=*pc=' ';                                //~5503R~
//  			*(pcd-1)=*pcd=0;                                //~5503R~
//  		}                                                   //~5503R~
//  		else                                                //~5503R~
//  		{                                                   //~5503R~
//tab split	                                                    //~5211I~
//  	 	 	for (pctab=pcd;*pctab==TABCHAR||*pctab==TABPADCHAR;pctab--)//~5503R~
//  				*pctab=0;	//reset boundary tab            //~5503R~
//  			if (pctab!=pcd)	//tab found                     //~5503R~
//  		 	 	for (pctab=pcd+1;*pctab==TABCHAR||*pctab==TABPADCHAR;pctab++)//~5503R~
//  					*pctab=0;	//reset boundary tab        //~5503R~
//  		}                                                   //~5503R~
//around mergin                                                    //~v0eiI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		  if (!swebcfile)                                          //~va50I~
#endif                                                             //~va50I~
          {                                                        //~va50I~
	        if (oomlen)	//ins in mergin and has oom                //~v0eiI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		        setobtabdbcs(0,0,pc0,pcd0,orgdestlen,mergin,0);//left/rigth of mergin//~va50I~
#else                                                              //~va50I~
		        setobtabdbcs(pc0,pcd0,orgdestlen,mergin,0);//left/rigth of mergin//~v0eiI~
#endif                                                             //~va50I~
            else                                                   //~v71UI~
            if (shortrecovf)                                       //~v71UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		        setobtabdbcs(0,0,pc0,pcd0,orgdestlen,mergin,0);//left/rigth of mergin//~va50I~
#else                                                              //~va50I~
		        setobtabdbcs(pc0,pcd0,orgdestlen,mergin,0);//left/rigth of mergin//~v71UI~
#endif                                                             //~va50I~
//*boundary ajust for tab and dbcs                              //~5503I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	setobtabdbcs(0,0,pc0,pcd0,orgdestlen,Poffs,0);         //~va50I~
#else                                                              //~va50I~
        	setobtabdbcs(pc0,pcd0,orgdestlen,Poffs,0);             //~v0eiR~
#endif                                                             //~va50I~
          }                                                        //~va50M~
    	  if (swebcfile)                                           //~va8bI~
			xeebc_filesetsosiplhupdate(optsetsosi,rcsetsosi,pfhd,Pplhd,Poffs,orgdestlen,pcs,pcsd,srclen);//~va8bR~
          else                                                     //~va8bI~
          {                                                        //~va8bI~
			memmove(pc +srclen,pc ,(UINT)reslen);//right shift  //~5211R~
			memmove(pcd+srclen,pcd,(UINT)reslen);//right shift  //~5211R~
			memcpy(pc ,pcs,(UINT)srclen);                       //~5211R~
			memcpy(pcd,pcsd,(UINT)srclen);                      //~5211R~
                                                                   //~va8bI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
			xesub_setdbcssplit(swebcfile,0/*plh*/,pc,pcd,srclen,' ');//~va50I~
#else                                                              //~va50I~
			setdbcssplit(pc,pcd,srclen,' ');                       //~v74HI~
#endif                                                             //~va50M~
    		if (UCBITCHK(Pplhd->ULHflag2,ULHF2TABFOUND))        //~5211R~
            {                                                      //~v58sI~
              if (oomlen)	//ulhlen already set                   //~v0eiI~
              {                                                    //~v73uI~
//  			fileimtabexp(Pplhd,Poffs,0,mergin);//len=mergin;expand in mergin//~v73uR~
				imlen=reslen+srclen-oomlen;                        //~v73uI~
    			fileimtabexp(Pplhd,Poffs,&imlen,mergin);//len=mergin;expand in mergin//~v73uI~
              }                                                    //~v73uI~
              else                                                 //~v0eiI~
              if (shortrecovf)                                     //~v71UI~
				fileimtabexp(Pplhd,Poffs,0,mergin);//len=mergin;expand in mergin//~v71UI~
              else                                                 //~v71UI~
				chartabexp(Pplhd,0,0,&pc,&pcd,Poffs+srclen,reslen,&len);//len nouse//~5507R~
            }//TABFOUND                                            //~v58sI~
          }//!ebcfile                                              //~va8bR~
            if (oomlen)                                            //~v0dmI~
//  			fileoomshiftback(pfhd,Pplhd,oomlen);               //~v74ER~
    			fileoomshiftback(pfhd,Pplhd,oomlen,mergin);        //~v74EI~
            else                                                   //~v71UI~
            if (shortrecovf)                                       //~v71UI~
            	Pplhd->ULHlen=mergin;                              //~v71UI~
			if (!revupdateonlysw)                                  //~v71UI~
            	if (oomlen||shortrecovf)                           //~v71UI~
                {                                                  //~v71UI~
                	revlen=mergin-Poffs;                           //~v71UI~
                	if (revlen>0 && revlen<srclen)                 //~v71UI~
   						charcaprev(Pplhd,Poffs,revlen); //cut reverselen by margin//~v71UR~
                }                                                  //~v71UI~
			break;                                              //~5211I~
		}//sw by op                                             //~5211I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		XEEBC_setdbcstblplh(swebcfile,pfhd,Pplhd);//re-evaluate dbcstbl//~va50R~
#endif                                                             //~va50I~
	}//on rec or out of rec                                     //~5211I~
//  if (Pplhd->ULHlen>MAXLINEDATA)                                 //~v0avR~
//  {                                                              //~v0avR~
//  	setdbcssplit(Pplhd->ULHdata,Pplhd->ULHdbcs,MAXLINEDATA,' ');//~v0avR~
//  	Pplhd->ULHlen=MAXLINEDATA;                                 //~v0avR~
//  	charmaxovererr(MAXLINEDATA);                                //~51//~v0avR~
//  }                                                              //~v0avR~
                                                                //~5211I~
	return 0;                                                   //~5211I~
}//charcap                                                      //~5211R~
//**************************************************************** //~v67VI~
// clear tab by char rep                                           //~v67VI~
//**************************************************************** //~v67VI~
void chartabrep(char *Ppcd,char *Ppcde)                            //~v67VR~
{                                                                  //~v67VI~
	char *pctab;                                                   //~v67VR~
//******************                                               //~v67VI~
	if (Ppcd>=Ppcde)                                               //~v67VI~
    	return;                                                    //~v67VI~
 	for (pctab=Ppcd;*pctab==TABPADCHAR;pctab--)                    //~v67VI~
		*pctab=0;                                                  //~v67VI~
//*no tab on dbcstbl for ebcfile                                   //~va50I~
 	if (*pctab==TABCHAR)                                           //~v67VI~
		*pctab=0;                                                  //~v67VI~
    for (pctab=Ppcd+1;pctab<Ppcde && *pctab==TABPADCHAR;pctab++)   //~v67VI~
		*pctab=0;	//reset boundary tab                           //~v67VI~
    return;                                                        //~v67VI~
}//chartabrep                                                      //~v67VR~
//**************************************************************** //~v67VI~
// delayed undo prepare for on/niche                               //~v67VI~
//**************************************************************** //~v67VI~
int charcaponundoprep(PUCLIENTWE Ppcw,int Psrclen,PULINEH Pplhd,int Poffs,int Preclen)//~v67VI~
{                                                                  //~v67VI~
	if (undoupdate(Ppcw,Pplhd,UUHTREP)==UALLOC_FAILED) //reset flag CURFOUND//~v67VI~
    	return UALLOC_FAILED;                                      //~v67VI~
	Pplhd->ULHlen=Preclen;                                         //~v67VI~
	charcaprev(Pplhd,Poffs,Psrclen);	//set reverse              //~v67VI~
    return 0;                                                      //~v67VI~
}//charcaponundoprep                                               //~v67VI~
//**************************************************************** //~v163I~
// charcap2                                                        //~v163I~
// data override to destination line(source is not plh but string) //~v163I~
//*parm 1:pcw                                                      //~v163I~
//*parm 2:mode (copy on,block rep,block insert)                    //~v163I~
//*parm 3:source data                                              //~v163I~
//*parm 4:source dbcs                                              //~v163I~
//*parm 5:source len                                               //~v163I~
//*parm 6:destination plh                                          //~v163I~
//*parm 7:override position                                        //~v163I~
//*return:0:ok,16:mergin err or UALLOC_FAILED                      //~v163I~
//*       1:margincut                                              //~va50I~
//**************************************************************** //~v163I~
int charcap2(PUCLIENTWE Ppcw,int Pmode,UCHAR *Pdata,UCHAR *Pdbcs,int Psrclen,//~v163R~
				PULINEH Pplhd,int Poffs)                           //~v163I~
{                                                                  //~v163I~
    UCHAR *pc,*pcd,*pcs,*pcsd,*pctab;                              //~v163I~
    UCHAR *pc0,*pcd0;                                              //~v163I~
    UCHAR *pcde;                                                   //~v67HI~
    int reclen,reslen,len,ii,dbcssw=0,orgdestlen;              //~va1cR~//~va27R~
    int rc,mergin;                                                 //~v163I~
    int ignovfspcsw,len2;                                          //~v676I~
    int oomlen,undoprepsw,ovfcutsw,margincutsw=0,norevsw;          //~v168R~
    PUFILEH pfhd;                                                  //~v163I~
    int shortrecovf=0,revlen;                                      //~v71UR~
    int imlen;                                                     //~v73uI~
#ifdef UTF8SUPPH                                                   //~va27I~
    int dbcssz;                                                    //~va27I~
    UCHAR *pspace="    ";	//4byte space                          //~va27R~
#endif                                                             //~va27I~
#ifdef UTF8UCS2                                                    //~va20R~
    int rcmc,srclencv,swutf8file,cap2opt,optmc;                    //~va20R~
    UCHAR *pcscv=NULL,*pcsdcv=NULL;                                          //~va20R~//~vaf9R~
#endif                                                             //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	int swebcfile;                                                 //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
	int handle;                                                    //~va7yI~
    int optsetsosi=0,rcsetsosi=0;                                      //~va8bI~//~vaf9R~
//****************************                                     //~v163I~
	if (Pmode & CHARCAP2_UNDO)                                     //~v163R~
    {                                                              //~v163I~
		Pmode &= ~CHARCAP2_UNDO;                                   //~v163R~
        undoprepsw=1;                                              //~v163I~
    }                                                              //~v163I~
    else                                                           //~v163I~
        undoprepsw=0;                                              //~v163I~
	if (Pmode & CHARCAP2_OVFCUT)                                   //~v163R~
    {                                                              //~v163I~
		Pmode &= ~CHARCAP2_OVFCUT;                                 //~v163R~
        ovfcutsw=1;                                                //~v163I~
    }                                                              //~v163I~
    else                                                           //~v163I~
        ovfcutsw=0;                                                //~v163I~
	if (Pmode & CHARCAP2_NOREV)                                    //~v168I~
    {                                                              //~v168I~
		Pmode &= ~CHARCAP2_NOREV;                                  //~v168I~
        norevsw=1;                                                 //~v168I~
    }                                                              //~v168I~
    else                                                           //~v168I~
        norevsw=0;                                                 //~v168I~
	if (Pmode & CHARCAP2_IGNOVFSPC) //ignore overflow cut is all space//~v676I~
    {                                                              //~v676I~
		Pmode &= ~CHARCAP2_IGNOVFSPC;                              //~v676I~
        ignovfspcsw=1;                                             //~v676I~
    }                                                              //~v676I~
    else                                                           //~v676I~
        ignovfspcsw=0;                                             //~v676I~
#ifdef UTF8UCS2                                                    //~va20R~
    cap2opt=Pmode;                                                 //~va20R~
    Pmode &= CHARCAP2_OPMODEMASK;                                  //~va20R~
#endif                                                             //~va20R~
	if (!Pplhd->ULHdbcs)	//not once displayed                   //~v163I~
		if (filechktabdbcs(Pplhd)==UALLOC_FAILED)//expand data len //~v163I~
        	return UALLOC_FAILED;                                  //~v163I~
    pfhd=UGETPFH(Pplhd);                                           //~v163I~
    mergin=pfhd->UFHmergin;                                        //~v163I~
    orgdestlen=Pplhd->ULHlen;                                      //~v163I~
	reslen=orgdestlen-Poffs;                                       //~v163I~
#ifdef UTF8UCS2                                                    //~va20R~
    swutf8file=FILEUTF8MODE(pfhd);                                 //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	swebcfile=PFH_ISEBC(pfhd);                                     //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    rcmc=0;                                                        //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    if (cap2opt & (CHARCAP2_SRCU8|CHARCAP2_SRCLC|CHARCAP2_SRCEB))	//mode change may be required//~va50I~
#else                                                              //~va50I~
    if (cap2opt & (CHARCAP2_SRCU8|CHARCAP2_SRCLC))	//mode change may be required//~va20R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    {                                                              //~va20R~
        optmc=0;                                                   //~va20R~
        if (cap2opt & CHARCAP2_SRCU8)                              //~va20R~
            optmc|=XEUTFMCO_SRCU8;                                 //~va20R~
        else                                                       //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        if (cap2opt & CHARCAP2_SRCEB)                              //~va50I~
        {                                                          //~va7yI~
            optmc|=XEUTFMCO_SRCEB;                                 //~va50I~
            if (cap2opt & CHARCAP2_EBCHANDLEP)                     //~va7yI~
            {                                                      //~va7yI~
                handle=CHARCAP2_GETHANDLE(cap2opt);                //~va7yI~
                optmc|=XEUTFMCO_EBCHANDLEP|XEUTFMCO_SETHANDLE(handle);//~va7yR~
            }                                                      //~va7yI~
        }                                                          //~va7yI~
        else                                                       //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            optmc|=XEUTFMCO_SRCLC;                                 //~va20R~
        rcmc=xeutf_modechng(optmc,pfhd,0/*source pfh*/,Pdata,Pdbcs,Psrclen,&pcscv,&pcsdcv,&srclencv);//~va20R~
        UALLOCCHKRC(rcmc);                                         //~va20R~
        if (rcmc)   //different utf8 mode 1:utf8-->,  2:utf8<--    //~va20R~
        {                                                          //~va20R~
            Pdata=pcscv;                                           //~va20R~
            Pdbcs=pcsdcv;                                          //~va20R~
            Psrclen=srclencv;                                      //~va20R~
        }                                                          //~va20R~
    }                                                              //~va20R~
#endif                                                             //~va20R~
    if (swebcfile && (Pmode==CHAROPBINS||Pmode==CHAROPBREP))       //~va8bI~
    {                                                              //~va8bI~
        optsetsosi=0;                                              //~va8bI~
        if (Pmode==CHAROPBINS)                                     //~va8bI~
        	optsetsosi|=XEEBCSO_CAPINS;                            //~va8bI~
    	if (cap2opt & CHARCAP2_EBCBNDSSORT)                        //~va8hI~
        	optsetsosi|=XEEBCSO_BNDSSORT;                          //~va8hI~
    	if (cap2opt & CHARCAP2_SBCS)                               //~va8iI~
        	optsetsosi|=XEEBCSO_SBCS;                              //~va8iI~
		rcsetsosi=xeebc_filesetsosiplh(optsetsosi,pfhd,Pplhd,Poffs,Pdata,Pdbcs,Psrclen,&pcscv,&pcsdcv,&srclencv);//~va8bR~
        UALLOCCHKRC(rcsetsosi);                                    //~va8bI~
        rcmc=1; //restore sorce addr                               //~va8bI~
    	Pdata=pcscv;                                               //~va8bI~
    	Pdbcs=pcsdcv;                                              //~va8bI~
    	Psrclen=srclencv;                                          //~va8bI~
    }                                                              //~va8bI~
    pcs=Pdata;                                                     //~v163I~
    rc=0;                                                          //~v163I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  if (!swebcfile)                                                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    if (memchr(Pdbcs,TABCHAR,(UINT)Psrclen))    // have tab        //~v66kR~
    	UCBITON(Pplhd->ULHflag2,ULHF2TABFOUND); //tab expand required//~v66gI~
    if (Pmode==CHAROPBINS)                                         //~v163I~
    {                                                              //~v163I~
      	if (Poffs<mergin)                                          //~v163R~
        {                                                          //~v71UI~
#ifdef UTF8UCS2                                                    //~va20I~
        	rc=filemerginchk(Pplhd,Poffs,pcs,Pdbcs,Psrclen,0,//dellen=0//~va20I~
#else                                                              //~va20I~
        	rc=filemerginchk(Pplhd,Poffs,pcs,Psrclen,0,//dellen=0  //~v163R~
#endif                                                             //~va20I~
						MERGIN_SHORTRECOK| //accept merginover flow is space only for short record//~v71UI~
						MERGIN_NOMSG,0,0,&oomlen);//adden=netlen=0 //~v163I~
	        if (!rc && oomlen<0)    //short record space overflow  //~v71UI~
    	    {                                                      //~v71UI~
        	    shortrecovf=1;                                     //~v71UI~
            	oomlen=0;                                          //~v71UI~
        	}                                                      //~v71UI~
        }                                                          //~v71UI~
      	else                                                       //~v163R~
        	oomlen=0;   //no shift back                            //~v163R~
    	reclen=Poffs+Psrclen+max(reslen,0);                        //~v163I~
    }                                                              //~v163I~
    else                                                           //~v163I~
    {                                                              //~v163I~
    	oomlen=0;                                                  //~v163I~
        if (Poffs<mergin && Poffs+Psrclen>mergin)//overflow case   //~v163I~
//            if (UCBITCHK(pfhd->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR)//spf file//~v417R~
//            ||  (UCBITCHK(pfhd->UFHflag2,UFHF2MERGIN)            //~v417R~
//                 && !UCBITCHK(pfhd->UFHflag3,UFHF3OOMNOPROT)))//prot mergin file//~v417R~
            if (UCBITCHK(pfhd->UFHflag2,UFHF2MERGIN))              //~v417I~
            {                                                      //~v58sI~
				if (ovfcutsw)                                      //~v163I~
                {                                                  //~v163I~
                	len2=Psrclen;                                  //~v676I~
                	Psrclen=mergin-Poffs;	//set only in margin   //~v163I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
  				  if (!swebcfile)                                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
            		if (UDBCSCHK_DBCSNOTEND(*(Pdbcs+Psrclen-1)))   //~va2iI~
            		{                                              //~va2iI~
            			Psrclen-=XESUB_DBCSSPLITCTR_L(Pdbcs,Psrclen);//~va2iI~
                		if (Psrclen<=0)                            //~va2iI~
                    		rc=4;                                  //~va2iI~
            		}                                              //~va2iI~
                    len2-=Psrclen;		//cut len                  //~v676I~
                  if (!ignovfspcsw                                 //~v676I~
#ifdef UTF8UCS2                                                    //~va20R~
	#ifdef UTF8EBCD	  //raw ebcdic file support                    //~va50I~
//                || (int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,Pdata+Psrclen,Pdbcs+Psrclen,(UINT)len2)!=len2)//~va50I~//~vb2DR~
                  || (int)UCVEBCUTF_umemspnc_space(swebcfile,swutf8file,Pdata+Psrclen,Pdbcs+Psrclen,len2)!=len2)//~vb2DI~
    #else                                                          //~va50I~
                  || (int)UTF_UMEMSPNC(swutf8file,Pdata+Psrclen,Pdbcs+Psrclen,' ',(UINT)len2)!=len2)//~va20R~
	#endif //UTF8EBCD raw ebcdic file support                      //~va50I~
#else                                                              //~va20R~
                  || (int)umemspnc(Pdata+Psrclen,' ',(UINT)len2)!=len2)//~v67VR~
#endif                                                             //~va20R~
                    margincutsw=1;                                 //~v163I~
				}                                                  //~v163I~
                else                                               //~v163I~
                 	rc=4;	//margin overflow                      //~v163R~
            }//MERGIN                                              //~v58sI~
    	reclen=Poffs+max(reslen,Psrclen);                          //~v163I~
    }                                                              //~v163I~
	if (rc>=4)                                                     //~v163I~
    	return 16;  //mergin err                                   //~v163I~
    if (reclen>MAXLINEDATA)                                        //~v163I~
    	return 16;                                                 //~v163I~
//*can be insert                                                   //~v163I~
	if (undoprepsw)                                                //~v163I~
    	if (undoupdate(Ppcw,Pplhd,UUHTREP)==UALLOC_FAILED) //reset flag CURFOUND//~v163I~
    		return UALLOC_FAILED;                                  //~v163I~
	if (reclen>Pplhd->ULHbufflen)                                  //~v163I~
		if (fileexpandbuff(Pplhd,reclen)==UALLOC_FAILED)		//expand buff//~v163I~
        	return UALLOC_FAILED;                                  //~v163I~
	Pplhd->ULHlen=reclen;                                          //~v163I~
    pc0 =Pplhd->ULHdata;                                           //~v163I~
    pcd0=Pplhd->ULHdbcs;                                           //~v163I~
    pc =pc0+Poffs;                                                 //~v163I~
    pcd=pcd0+Poffs;                                                //~v163I~
    pcde=pcd0+reclen;                                              //~v67HI~
#ifdef UTF8UCS2                                                    //~va20R~
  if (rcmc)                                                        //~va20R~
  {                                                                //~va20R~
	pcs=pcscv;                                                     //~va20R~
    pcsd=pcsdcv;                                                   //~va20R~
  }                                                                //~va20R~
  else                                                             //~va20R~
#endif                                                             //~va20R~
  {                                                                //~va20R~
    pcs=Pdata;                                                     //~v163I~
    pcsd=Pdbcs;                                                    //~v163I~
  }                                                                //~va20R~
                                                                   //~v163I~
  if (!norevsw)                                                    //~v168I~
    charcaprev(Pplhd,Poffs,Psrclen);	//set reverse              //~v163I~
                                                                   //~v163I~
//add space before csr or shift post data                          //~v163I~
	if (reslen<=0)	//out of reclen                                //~v163I~
	{                                                              //~v163I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		UCVEBC_memset_space(swebcfile,pc+reslen,(UINT)(-reslen));  //~va50I~
#else                                                              //~va50I~
		memset(pc+reslen,' ',(UINT)(-reslen));                     //~v163I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
		memset(pcd+reslen,0,(UINT)(-reslen));                      //~v74aI~
		memcpy(pc ,pcs ,(UINT)Psrclen);                            //~v163I~
		memcpy(pcd,pcsd,(UINT)Psrclen);                            //~v163I~
        len=Psrclen;                                               //~v74xI~
    	if (UCBITCHK(Pplhd->ULHflag2,ULHF2TABFOUND)) //tab expand required//~v74xI~
			if (filetabexp(1,Pplhd,Poffs,&len)==UALLOC_FAILED)     //~v74xI~
				return UALLOC_FAILED;                              //~v74xI~
		XEEBC_setdbcstblplh(swebcfile,pfhd,Pplhd);//re-evaluate dbcstbl//~va8bI~
	}                                                              //~v163I~
	else                                                           //~v163I~
	{                                                              //~v163I~
		switch (Pmode)                                             //~v163I~
		{                                                          //~v163I~
//** no user cap2 and CHAROPON ****                                //~va20R~
		case CHAROPON:	//copy on                                  //~v163I~
//del tab at boundary                                              //~v163I~
//*no tab on dbcstbl for ebcfile                                   //~va50I~
		 	for (pctab=pcd;*pctab==TABCHAR||*pctab==TABPADCHAR;pctab--)//~v163I~
				*pctab=0;	//reset boundary tab                   //~v163I~
//  		for (pctab=pcd+Psrclen;*pctab==TABPADCHAR;pctab++)     //~v67HR~
    		for (pctab=pcd+Psrclen;pctab<pcde && *pctab==TABPADCHAR;pctab++)//~v67HI~
				*pctab=0;	//reset boundary tab                   //~v163I~
//*rep space data clear tab                                        //~v163I~
            for (ii=0;ii<Psrclen;reslen--,ii++,pcs++,pcsd++,pc++,pcd++)//~v163I~
			{                                                      //~v163I~
//** no user cap2 and CHAROPON ****                                //~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
				if (reslen<=0 || *pc==UCVEBC_CHAR_SPACE(swebcfile))//~va50I~
#else                                                              //~va50I~
				if (reslen<=0 || *pc==' ')                         //~v163I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
				{                                                  //~v163I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
                  if (!swebcfile)                                  //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                  {//!ebc                                          //~va50I~
					switch(*pcsd)                                  //~v163I~
					{                                              //~v163I~
//#ifdef UTF8SUPPH                                                   //~va1cR~//~va27R~
//                    case UDBCSCHK_DBCS1ST:                         //~va1cR~//~va27R~
//                    case UDBCSCHK_DBCS2ND:                         //~va1cR~//~va27R~
//                    case UDBCSCHK_DBCSPAD:                         //~va1cR~//~va27R~
//                        xesub_cleardbcs1(0,pc0,pcd0,orgdestlen,Poffs+ii,' ');//clear dbcs at the offset//~va1cR~//~va27R~
//                        break;                                     //~va1cR~//~va27R~
//#else                                                              //~va1cR~//~va27R~
					case DBCS1STCHAR:                              //~v163I~
#ifdef UTF8SUPPH                                                   //~va27I~
                        dbcssz=XESUB_DBCSSPLITCTR(pcsd,reslen,0);  //~va27R~
                        dbcssz=min(reslen,dbcssz);                 //~va27I~
    #ifdef UTF8UCS2                                                //~va20I~
//*!ebc                                                            //~va50I~
                        if (XESUB_DDMEMCMP(swutf8file,XESUBDDSCO_EQCHKONLY,pc,pcd,pspace,0/*pdbcs2;ascii*/,dbcssz))//no space to set full dbcs char//~va20I~
    #else                                                          //~va20I~
                        if (memcmp(pc,pspace,(UINT)dbcssz))//no space to set full dbcs char//~va27R~
    #endif                                                         //~va20I~
#else                                                              //~va27I~
						if (reslen>1 && *(pc+1)!=' ')              //~v163I~
#endif                                                             //~va27I~
							continue;                              //~v163I~
						dbcssw=1;                                  //~v163I~
						break;                                     //~v163I~
					case DBCS2NDCHAR:                              //~v163I~
#ifdef UTF8SUPPH                                                   //~va27I~
                    case UDBCSCHK_DBCSPAD:                         //~va27I~
#endif                                                             //~va27I~
						if (!dbcssw)                               //~v163I~
                          if (reslen>0)    //leave target data     //~v77dI~
							continue;                              //~v163I~
#ifdef UTF8SUPPH                                                   //~va27I~
					  if (*pcsd==UDBCSCHK_DBCS2ND)                 //~va27I~
#endif                                                             //~va27I~
						dbcssw=0;                                  //~v163I~
						break;                                     //~v163I~
					default:                                       //~v163I~
						dbcssw=0;                                  //~v163I~
//#endif                                                             //~va1cR~//~va27R~
					}//sw by dbcs                                  //~v163I~
                  }//!ebc                                          //~va50I~
		 	 		*pc=*pcs;                                      //~v163I~
		 	 		*pcd=*pcsd;                                    //~v163I~
				}                                                  //~v163I~
//*no tab on dbcstbl for ebcfile                                   //~va50I~
		 	 	if (*pcd==TABCHAR||*pcd==TABPADCHAR)               //~v163I~
					*pcd=0;		//reset tab of override range      //~v163I~
			}//loop by source len                                  //~v163I~
			break;                                                 //~v163I~
                                                                   //~v163I~
		case CHAROPBREP:	//block replace                        //~v163I~
    	  if (swebcfile)                                           //~va8bI~
			xeebc_filesetsosiplhupdate(optsetsosi,rcsetsosi,pfhd,Pplhd,Poffs,orgdestlen,pcs,pcsd,Psrclen);//~va8bI~
          else                                                     //~va8bI~
          {                                                        //~va8bI~
//*boundary ajust for tab and dbcs                                 //~v163I~
    	   if (!(cap2opt & CHARCAP2_SBCS))                         //~va8iI~
           {                                                       //~va8iI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	setobtabdbcs(swebcfile,0,Pplhd->ULHdata,Pplhd->ULHdbcs,orgdestlen,//~va50I~
							Poffs,Psrclen);                        //~va50I~
#else                                                              //~va50I~
        	setobtabdbcs(Pplhd->ULHdata,Pplhd->ULHdbcs,orgdestlen, //~v163I~
							Poffs,Psrclen);                        //~v163I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
           } //!SBCS  option                                       //~va8iI~
			memcpy(pc ,pcs,(UINT)Psrclen);                         //~v163I~
			memcpy(pcd,pcsd,(UINT)Psrclen);                        //~v163I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//        if (!swebcfile)                                          //~va50I~//~va8bR~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
			chartabclear(pcd,Psrclen);                             //~va2hR~
          }                                                        //~va8bI~
			break;                                                 //~v163I~
                                                                   //~v163I~
		case CHAROPBINS:	//block insert                         //~v163R~
//around mergin                                                    //~v163I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
          if (!swebcfile)                                          //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
          {                                                        //~va50I~
	        if (oomlen)	//ins in mergin and has oom                //~v163I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		        setobtabdbcs(0,0,pc0,pcd0,orgdestlen,mergin,0);//left/rigth of mergin//~va50I~
#else                                                              //~va50I~
		        setobtabdbcs(pc0,pcd0,orgdestlen,mergin,0);//left/rigth of mergin//~v163I~
#endif                                                             //~va50I~
            else                                                   //~v71UI~
        	if (shortrecovf)                                       //~v71UI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
		        setobtabdbcs(0,0,pc0,pcd0,orgdestlen,mergin,0);//left/rigth of mergin//~va50I~
#else                                                              //~va50I~
		        setobtabdbcs(pc0,pcd0,orgdestlen,mergin,0);//left/rigth of mergin//~v71UI~
#endif                                                             //~va50I~
//*boundary ajust for tab and dbcs                                 //~v163I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
        	setobtabdbcs(0,0,pc0,pcd0,orgdestlen,Poffs,0);         //~va50I~
#else                                                              //~va50I~
        	setobtabdbcs(pc0,pcd0,orgdestlen,Poffs,0);             //~v163I~
#endif                                                             //~va50I~
          }//!ebc                                                  //~va50I~
    	  if (swebcfile)                                           //~va8bI~
			xeebc_filesetsosiplhupdate(optsetsosi,rcsetsosi,pfhd,Pplhd,Poffs,orgdestlen,pcs,pcsd,Psrclen);//~va8bR~
          else                                                     //~va8bI~
          {                                                        //~va8bI~
			memmove(pc +Psrclen,pc ,(UINT)reslen);//right shift    //~v163I~
			memmove(pcd+Psrclen,pcd,(UINT)reslen);//right shift    //~v163I~
			memcpy(pc ,pcs,(UINT)Psrclen);                         //~v163I~
			memcpy(pcd,pcsd,(UINT)Psrclen);                        //~v163I~
			chartabclear(pcd,Psrclen);                             //~va2hR~
    		if (UCBITCHK(Pplhd->ULHflag2,ULHF2TABFOUND))           //~v163I~
            {                                                      //~v58sI~
              if (oomlen)	//ulhlen already set                   //~v163I~
              {                                                    //~v73uI~
//  			fileimtabexp(Pplhd,Poffs,0,mergin);//len=mergin;expand in mergin//~v73uR~
				imlen=reslen+Psrclen-oomlen;                       //~v73uR~
    			fileimtabexp(Pplhd,Poffs,&imlen,mergin);//len=mergin;expand in mergin//~v73uI~
              }                                                    //~v73uI~
              else                                                 //~v163I~
          	  if (shortrecovf)                                     //~v71UI~
				fileimtabexp(Pplhd,Poffs,0,mergin);//len=mergin;expand in mergin//~v71UI~
              else                                                 //~v71UI~
				chartabexp(Pplhd,0,0,&pc,&pcd,Poffs+Psrclen,reslen,&len);//len nouse//~v163I~
            }//TABFOUND                                            //~v58sI~
          }//!ebcfile                                              //~va8bI~
            if (oomlen)                                            //~v163I~
//				fileoomshiftback(pfhd,Pplhd,oomlen);               //~v74ER~
  				fileoomshiftback(pfhd,Pplhd,oomlen,0);             //~v74EI~
            else                                                   //~v71UI~
          	if (shortrecovf)                                       //~v71UI~
            	Pplhd->ULHlen=mergin;                              //~v71UI~
  			if (!norevsw)                                          //~v71UI~
            	if (oomlen||shortrecovf)                           //~v71UI~
                {                                                  //~v71UI~
                	revlen=mergin-Poffs;                           //~v71UI~
                	if (revlen>0 && revlen<Psrclen)                //~v71UI~
   						charcaprev(Pplhd,Poffs,revlen);	//cut reverselen by margin//~v71UI~
                }                                                  //~v71UI~
			break;                                                 //~v163I~
		}//sw by op                                                //~v163I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  	XEEBC_setdbcstblplh(swebcfile,pfhd,Pplhd);//re-evaluate dbcstbl//~va50I~//~va8iR~
		if (swebcfile)                                             //~va8iR~
			 xeebc_setdbcstblplh(0,pfhd,Pplhd,0);                  //~va8iI~
        else                                                       //~va8iI~
        {                                                          //~va8iI~
      		if (cap2opt & CHARCAP2_SBCS)	//from bnds sort       //~va8iI~
				filesetdbcstblplh(0,pfhd,Pplhd,0,-1/*use ulhlen*/);//~va8iI~
        }                                                          //~va8iI~
#endif                                                             //~va50I~
	}//on rec or out of rec                                        //~v163I~
	return margincutsw;                                            //~v163R~
}//charcap2                                                        //~v163I~
//**************************************************************** //~v06MI~
// charcaprev                                                      //~v0blR~
// set reverse to copyed block                                     //~v06MI~
//*parm 1:plh                                                      //~v06MI~
//*parm 2:offset                                                   //~v06MI~
//*parm 3:len                                                      //~v06MI~
//*return:none                                                     //~v06MI~
//**************************************************************** //~v06MI~
void charcaprev(PULINEH Pplh,int Poffs,int Plen)                   //~v06MR~
{                                                                  //~v06MI~
//****************************                                     //~v06MI~
    Pplh->ULHrevctr=Pplh->ULHupundoctr;//hilight only when curr update//~v06MI~
    Pplh->ULHrevoffs=(USHORT)Poffs;                                //~v06MI~
    Pplh->ULHrevlen=(USHORT)Plen;                                  //~v06MI~
    UCBITON(Pplh->ULHflag,ULHFCURCAP);	//current paste block line //~v06MI~
    UCBITOFF(Pplh->ULHflag,ULHFCURFOUND);//reset reason find hilight//~v06MI~
    UCBITOFF(Pplh->ULHflag2,ULHF2MFOUND);//reset reason find hilight//~v06MI~
    return;                                                        //~v06MI~
}//charcaprev                                                      //~v06MI~
//**************************************************************** //~v0blI~
// charsplitline                                                   //~v0blI~
//  split long line                                                //~v0blI~
//*parm 1:pcw                                                      //~v0blI~
//*parm 2:plh                                                      //~v0blI~
//*return:0, UALLOC_FAILED                                         //~v0blI~
//**************************************************************** //~v0blI~
int charsplitline(PUCLIENTWE Ppcw,PULINEH Pplh)                    //~v0blI~
{                                                                  //~v0blI~
	PULINEH plh;                                                   //~v0blI~
    int rc;                                                        //~v0blI~
//****************************                                     //~v0blI~
	rc=undoupdate(Ppcw,Pplh,UUHTREP);                              //~v0blI~
    if (rc)                                                        //~v0blI~
    	return rc;                                                 //~v0blI~
    plh=UGETQNEXT(Pplh);            			//next             //~v0blM~
//*split contline to 2 single line by S+Enter/"S" lcmd at EOL pos;no dbcstbl chng//~va50I~
	rc=undoupdate(Ppcw,plh,UUHTREP);                               //~v0blI~
    if (rc)                                                        //~v0blI~
    	return rc;                                                 //~v0blI~
    UCBITOFF(Pplh->ULHflag2,ULHF2SPLIT1);    	//no follower      //~v0blI~
    UCBITOFF(plh->ULHflag2,ULHF2SPLIT2);   		//no prev          //~v0blI~
    return 0;                                                      //~v0blI~
}//charsplitline                                                   //~v0blI~
//**************************************************************** //~v0boI~
// charconcatline                                                  //~v0boI~
//  concatinate to split line                                      //~v0boI~
//*parm 1:pcw                                                      //~v0boI~
//*parm 2:plh                                                      //~v0boI~
//*parm 2:plhnext                                                  //~v0boI~
//*return:0, UALLOC_FAILED                                         //~v0boI~
//**************************************************************** //~v0boI~
int charconcatline(PUCLIENTWE Ppcw,PULINEH Pplh,PULINEH Pplhnext)  //~v0boI~
{                                                                  //~v0boI~
    int rc;                                                        //~v0boI~
//****************************                                     //~v0boI~
//*del at EOL/"J" lcmd concat splitline;set only split flag,no dbcstbl update//~va50I~
	rc=undoupdate(Ppcw,Pplh,UUHTREP);                              //~v0boI~
    if (rc)                                                        //~v0boI~
    	return rc;                                                 //~v0boI~
	rc=undoupdate(Ppcw,Pplhnext,UUHTREP);                          //~v0boI~
    if (rc)                                                        //~v0boI~
    	return rc;                                                 //~v0boI~
    UCBITON(Pplh->ULHflag2,ULHF2SPLIT1);    	//has follower     //~v0boI~
    UCBITON(Pplhnext->ULHflag2,ULHF2SPLIT2);   	//has prev         //~v0boI~
	uerrmsg("Split line generated",                                //~v0c2I~
    		"ï™äÑçsçÏê¨");                                         //~v0c2I~
    return 1;                                                      //~v10bR~
}//charconcattline                                                 //~v0boI~
