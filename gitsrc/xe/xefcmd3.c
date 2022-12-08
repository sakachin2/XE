//*CID://+vbw3R~:                             update#=  195;       //~vbw3R~
//*************************************************************
//*xefcmd3.c*
//**file cmd CID,SCRoll,NUMber,drop                                //~v40KR~
//*************************************************************
//vbw3:221205 accept cidtype by unicode fo cid on/clear cmd        //~vbw3I~
//vbv6:221121 add NOAPPEND to CID cmd                              //~vbv6I~
//vbs7:201028 Debian10 compiler warning -Wformat-overflow          //~vbs7I~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//va8k:101013 SPLit cmd;dbcs consideration for split ALL/OVER without SBCS option.(split to fcmd43)//~va8kI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va1q:091107 compchkm                                             //~va1qI~
//va02:090525 CID copyon/copyoff(lcmd copy CID option)             //~va02I~
//v79U:081028 CID append mode                                      //~v79UI~
//v75s:070427 option to specify fixed lrecl on top cid specification line,and set by "cid TOPD"//~v75sI~
//v74B:070225 (LNX:BUG)ini file process fail by EOL type for the file Windows created.//~v74BI~
//            chk other fgets process                              //~v74BI~
//v73f:070112*(BUG)errmsg "4 line changed" is issued when rc=4 returned from filecidclear//~v73fI~
//v72f:061123 (BUG)csr position error after find after lineno-size is changed by num cmd(xon/xoff,renum f)//~v72fI~
//v69B:060612 (BUG)at save tab is replaced by space after spl cmd  //~v69bI~
//v62p:050325 tc_getnumrange is moved to uedit.c for v62o          //~v62pI~
//v60k:050129 (BUG)GOPT4XLINENO is not recovered even if changed by "S" option//~v60kI~
//v53d:030923 option seti/setr without renum                       //~v53dI~
//v512:030309 protect inserted after eof hdr line                  //~v512I~
//v511:030302 new rotate cmd                                       //~v511I~
//v506:021019 add "set" option for renum cmd;set num fld on specified colomn//~v506I~
//v504:021006 accept ren cmd as "num reset" on edit scr            //~v504I~
//v503:021006 accept del cmd as drop on edit scr                   //~v503I~
//v47A:020321 renum and num clear for cobk                         //~v47AI~
//v47c:020223 chk duplicated label on lineno column.               //~v47cI~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd            //~v45xI~
//v45u:011216 num cutoff cmd to split coninued line                //~v45uI~
//v42y:011010 add cmd ek,bk,sk,ekn,bkn,skn                         //~v42yI~
//v42j:011002 function to setup cid top line by file in wd         //~v42jI~
//v420:010918 cob fld num clear option;num clear cob               //~v420I~
//v41o:010820 cobol UFCleft=6                                      //~v41oI~
//v41a:010729 add TOPCN to cid cmd                                 //~v41aI~
//v40X:010722 cannot set 72-80 by v40W because lrecl=72;use lcmdisrtwithlen//~v40XI~
//v40W:010722 set spfnum(cob) after isrt topline cid(cob)          //~v40WI~
//v40K:010714 option to insert comment line for drop excluded cmd(dro x|nx rep)//~v40FI~
//v40F:010709 COB support:num clear(clear col72-80)                //~v40FI~
//v40D:010709 COB support:cid tobcob                               //~v40DI~
//v40C:010709 (BUG)err when browse for renum cmd                   //~v40CI~
//v40b:010327 LINUX support:ajust after merge                      //~v40bI~
//v20X:001124 missing prot parm for cid topa                       //~v20XI~
//v20T:001119 (BUG)miss to set cid to cidtop line                  //~v20SI~
//v20S:001119 CID cmd:protect when browse mode or partial edit mode//~v20SI~
//v20N:001028 cid cmd option to insert cid top line;with and w/o options//~v20NI~
//v20w:001028 cid cmd help by no operand(current status is by ?)   //~v20wI~
//v20x:001028 cid cmd option to insert cid top line                //~v20NI~
//v177:000430 reject "num xon" to spf file                         //~v177I~
//v173:000430 ajust linenosz when num XON/XOFF                     //~v173I~
//v165:000414 (BUG)label err msg not displayed(sort cmd)           //~v165I~
//v157:000403 (BUG)cid clear rejected when cid is NONE("cid clear c" is ok so change guide)//~v157I~
//v136:990918 NUM cmd help change(add [s])                         //~v136I~
//v11D:990822 help for num cmd                                     //~v11DI~
//v11m:990718 drop cmd help                                        //~v11mI~
//v10X:990605 hex digit lineno display for binary file             //~v10XI~
//v10H:990417 (BUG)uerrmsg parm count chk by xuerpck               //~v10HI~
//v10d:981218 if bin,no cid set                                    //~v10dI~
//v0ik:980625 num cmd avail for kf again                           //~v0ifI~
//v0if:980620 pfk cmd support                                      //~v0ifR~
//            -reject cid on for work dir file                     //~v0ifI~
//            -reject num change                                   //~v0ifI~
//v0ic:980607 label support for DROP cmd                           //~v0icI~
//v0hu:980410 DEL cmd on edit screen(same as DROP)                 //~v0huI~
//            and cmd fmt change (drop xall-->drop x all)          //~v0huI~
//v0hq:980316 add DROP cmd(del all line XON/XOFF)                  //~v0hqI~
//v0eA:970922 assume cid(no operand) as cid ?
//v0dx:970914 split fileclear from xefile4.c                       //~v0dxI~
//v0cz:970818 null cid //+NONE~R                                   //~v0czI~
//v0ct:970814 RENUM(NUM reset) Force option for spf file           //~v0ctI~
//v0cs:970814 (BUG)do RENUM after err chk end                      //~v0csI~
//v0cr:970814 NUM VER subcmd --> VER cmd                           //~v0crI~
//v0cn:970813 RENUM undo support(move filerenum from xefile to xefile12)//~v0cnI~
//v0cm:970812 NUM VER subcmd(reset spf version)                    //~v0cmR~
//v0c7:970802 full draw needed even if filegetcid faled(mergin may changed default)//~v0buI~
//v0bu:970728 draw mergin                                          //~v0buI~
//            cid ? need fulldraw for mergin change redraw         //~v0buI~
//v0br:970727 support RENUM command alias of NUM RESET             //~v0brI~
//            num renum is also avail                              //~v0brI~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0av:970720-fixed lrecl support                                  //~v0avI~
//           -filetoplinecid/filegetcid return rc                  //~v0avI~
//v09F:970614:CID postfix support                                  //~v09FI~
//            CID cmd support postfix(ex. cid clear,asm,?? or cid clear //,??)//~v09FI~
//v09r:970521:arbitaly CID type by first line                      //~v09rI~
//            -UFILEH has pos info.                                //~v09rI~
//            -filecidtypechk return cidtbl ptr not but cid for get pos//~v09rI~
//            -filegetcid parm 0:always chk first line,2 chk if sline==0//~v09rI~
//            -reject change cid type if hdr line cid exist        //~v09rI~
//            -reject cid shift when browse                        //~v09rI~
//            -cid type on clear/shift is temporary                //~v09rI~
//            -no cid msg for invalid ext                          //~v09rI~
//            -before clear/shift reset by 1st line                //~v09rI~
//v09g:970517:-shift linenosz by line number of file.(file.c)      //~v09gI~
//            -set default even if operand is same as current pcw size(fcmd3.c)//~v09gI~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v074:960602:num reset cmd(renumber line number)                  //~v074I~
//v06y:960407:protect edit so file when iit is used by cmd result     //~v06yI~
//            (cmd edit identification only by PANMOCMD)              //~v06yI~
//v06r:960325:cid pos for lineno field len =4 as default              //~v06rI~
//            and support CID shift(colomn re-arange)                 //~v06rI~
//v069:960224:linenosz changeable for edit/browse(NUM cmd)      //~v069I~
//v065:960217:save also cmd history to XE!SAVE!                 //~v065I~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*v033:950715:SCROLL cmd for dir list scroll                   //~v033I~
//************************************************************* //~v033I~
//*950603 write ini when cid option change                      //~5603I~
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
#include <uque.h>
#include <uerr.h>
#include <uparse.h>                                                //~v0b2R~
#include <ufile.h>                                              //~5318I~
#include <ualloc.h>                                             //~v04dI~
#include <uedit.h>                                                 //~v62pI~
#include <ucvebc.h>                                                //~va50I~
#include <utrace.h>                                                //~vbv6I~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xefile.h"
#include "xefile12.h"                                              //~v0cmI~
#include "xefile13.h"                                              //~v173I~
#include "xefile2.h"                                            //~v069I~
#include "xefile3.h"                                            //~v033I~
#include "xefile4.h"                                               //~v0dxR~
#include "xefile6.h"                                               //~v40XI~
#include "xefile7.h"                                               //~v0hqI~
#include "xefile43.h"                                              //~v0dxI~
#include "xefcmd22.h"                                              //~v0icI~
#include "xefcmd3.h"
#include "xefsub.h"                                                //~v0icI~
#include "xelcmd.h"                                                //~v0icI~
#include "xelcmd2.h"                                               //~v20wI~
#include "xechar2.h"                                               //~v20wM~
#include "xepan.h"
#include "xesub.h"
#include "xeerr.h"                                              //~v033I~
#include "xefunc.h"                                                //~v504I~
#ifdef UTF8SUPPH                                                   //~va1qI~
#include "xeopt.h"                                                 //~va02I~
#endif                                                             //~va1qI~
#include "xeebc.h"                                                 //~va50I~
//#include "xecalc2.h"                                             //~v62pR~
//*******************************************************
#define CIDTOP_FNAME       "xe_top"  //default cidtop file         //~v42jI~
#define CIDTOP_MAXSZ       MAXCOLUMN                               //~v42jI~
//*******************************************************          //~v42jI~
static int Srenumcmdsw=0;                                          //~v504I~
static char *Sisrtdbcs=0;	//fcmdisrtlinedbcs                     //~v511I~
//*******************************************************          //~v504I~
int fcmdpostfixlenerr(char *Ppostfix);                             //~v09FI~
int fcmdcidhelp(PUCLIENTWE Ppcw,PUFILEH pfh);                      //~v0eAI~
int fcmdinvalidfile(void);                                         //~v0ifI~
int fcmdnumajustlinenosz(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt);   //~v173I~
int fcmdinvalidforspf(void);                                       //~v177I~
int fcmdcidsettop(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt,char *Pfiletype);//~v42jR~
int fcmdchkcidtopfile(int Poption,char *Pfiletype,char *Ptopdata); //~v42jI~
int fcmdgetrenumsetfld(PUCLIENTWE Ppcw,char *Pdata,int *Ppcol1,int *Ppcol2,UCHAR *Ppdelmch);
//****************************************************************
//****************************************************************
// func_cid
//*rc   :0
//****************************************************************
int func_cid(PUCLIENTWE Ppcw)
{
//  int ii,opdno,opid,cidtype=0;                                   //~va8kR~
    int ii,opdno,opid=0,cidtype=0;                                 //~va8kI~
//  char cidtypesv,cidpossv,fixidsv;                               //~v09FR~
    int rc;                                                        //~v09rI~
    int len;                                                       //~v09FI~
    int appendopt=0;                                               //~v79UI~
    int appendoptNo=0;                                             //~vbv6I~
    long lineno;
	UCHAR *pc,cidtypec[4];                                         //~v09FR~
	UCHAR *pc2;                                                    //~v79UI~
    PUFILEC pfc;
    PUFILEH pfh;
	CIDTBL *pcidtbl;                                               //~v09rI~
    UCHAR postfixw[1+LINEPOSTFIXLEN+1];                            //~v09FR~
//  char cidsv[sizeof(pfh->UFHcid)];                               //~v09FR~
static UCHAR *Swordtbl="ON\0OFF\0CLEAR\0DEFON\0DEFOFF\0?\0SHIFT\0TOP\0TOPA\0"//~v40DR~
                       "TOPC\0TOPCOB\0TOPCN\0TOPNC\0"              //~v42yR~
                       "TOPK\0TOPKN\0TOPNK\0"                      //~v75sR~
                       "TOPD\0"  //17                              //~v75sR~
                       "COPYON\0"  //18                            //~va02I~
                       "COPYOFF\0"  //19                           //~va02I~
                       ;                                           //~v75sI~
#define  CID_APPEND    "APPEND"                                    //~v79UI~
#define  CID_NOAPPEND  "NOAPPEND"                                  //~vbv6I~
//*********************************
    *postfixw=0;	//clear                                        //~v09FI~
    *(postfixw+1)=0;	//clear                                    //~v09FI~
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
	if (!(pc=Ppcw->UCWparm))		//operand
    {                                                              //~v0eAI~
//      return errmissing();                                       //~v0eAR~
//      return fcmdcidhelp(Ppcw,pfh);                              //~v20wR~
//      uerrmsg("CID [on|off|clear|shift|defon|defoff|top|topa|?] [cid-type|prefix[,postfix]]",0);//~v75sR~
//      uerrmsg("CID [on|off|clear|shift|defon|defoff|top|topa|topc|topcn|topk|topkn|topd|?] [cid-type|prefix[,postfix]]",0);//~v79UR~
//      uerrmsg("CID [on|off|clear|shift|defon|defoff|top|topa|topc|topcn|topk|topkn|topd|?] [ [cid-type|prefix[,postfix]] | APPEND ]",0);//~v79UI~//~va02R~
//      uerrmsg("CID [on|off|clear|shift|defon|defoff|top|topa|topc|topcn|topk|topkn|topd|copyon|copyoff|?] [ [cid-type|prefix[,postfix]] | APPEND ]",0);//~vbv6R~
        uerrmsg("CID [on|off|clear|shift|defon|defoff|top|topa|topc|topcn|topk|topkn|topd|copyon|copyoff|?] [ [cid-type|prefix[,postfix]] | [APPEND|NOAPPEND] ]",0);//~vbv6I~
        return 0;                                                  //~v20wI~
    }                                                              //~v0eAI~
//*operand chk
	UPARSERC(pc,pc,&opdno,0,",");	//parse out string(accept cr/lf)//~v04dR~
    if (opdno>1)                                                   //~v79UI~
    {                                                              //~v79UI~
    	pc2=pc+strlen(pc)+1;                                       //~v79UI~
        appendopt=!stricmp(pc2,CID_APPEND);                        //~v79UR~
        appendoptNo=!stricmp(pc2,CID_NOAPPEND);                    //~vbv6I~
    }                                                              //~v79UR~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr
	{
    	switch(ii)
        {
        case 0:		//first opd
//  		switch(opid=wordtblisrch(pc,Swordtbl),opid)            //~v79UR~
    		opid=wordtblisrch(pc,Swordtbl);                        //~v79UI~
            if (appendopt)                                         //~v79UI~
            {                                                      //~v79UI~
            	switch(opid)                                       //~v79UI~
                {                                                  //~v79UI~
                case 1:         //on                               //~v79UI~
//    				if (UCBITCHK(pfh->UFHflag9,UFHF9CIDAPPEND))    //~vbv6R~
      				if (UCBITCHK(pfh->UFHflag9,UFHF9CIDAPPEND)     //~vbv6I~
            	    &&  UCBITCHK(pfh->UFHflag,UFHFCIDON))          //~vbv6I~
                    	return erralready();                       //~v79UI~
                    break;                                         //~v79UI~
                case 2:         //off                              //~v79UI~
//    				if (UCBITCHK(pfh->UFHflag9,UFHF9CIDAPPENDN))   //~vbv6R~
      				if (UCBITCHK(pfh->UFHflag9,UFHF9CIDAPPEND)     //~vbv6I~
                	&&  UCBITCHK(pfh->UFHflag,UFHFCIDOFF))         //~vbv6I~
                    	return erralready();                       //~v79UI~
                    break;                                         //~v79UI~
                case 4:         //defon                            //~v79UI~
//          		if (UCBITCHK(Gopt5,GOPT5CIDAPPEND))            //~vbv6R~
            		if (UCBITCHK(Gopt5,GOPT5CIDAPPEND)             //~vbv6I~
            	    &&  !UCBITCHK(Gopt2,GOPT2NOCID))               //~vbv6I~
                    	return erralready();                       //~v79UI~
                    break;                                         //~v79UI~
                case 5:         //defoff                           //~v79UI~
//          		if (!UCBITCHK(Gopt5,GOPT5CIDAPPEND))           //~vbv6R~
            		if (UCBITCHK(Gopt5,GOPT5CIDAPPEND)             //~vbv6R~
            	    &&  UCBITCHK(Gopt2,GOPT2NOCID))                //~vbv6I~
                    	return erralready();                       //~v79UI~
                	break;                                         //~v79UI~
                default:                                           //~v79UI~
        			uerrmsg("APPEND option is valid with ON/OFF/DEFON/DEFOFF",//~v79UI~
        					"APPEND 指定は ON/OFF/DEFON/DEFOFF で指定する");//~v79UI~
        			return 4;                                      //~v79UI~
                }                                                  //~v79UI~
            }                                                      //~v79UI~
            if (appendoptNo)                                       //~vbv6I~
            {                                                      //~vbv6I~
            	switch(opid)                                       //~vbv6I~
                {                                                  //~vbv6I~
                case 1:         //on NOAPPEND                      //~vbv6R~
	  				if (UCBITCHK(pfh->UFHflag9,UFHF9CIDAPPENDN)    //~vbv6R~
                	&&  UCBITCHK(pfh->UFHflag,UFHFCIDON))          //~vbv6I~
                    	return erralready();                       //~vbv6R~
                    break;                                         //~vbv6I~
                case 2:         //off NOAPPEND                     //~vbv6R~
	  				if (UCBITCHK(pfh->UFHflag9,UFHF9CIDAPPENDN)    //~vbv6R~
            	    &&  UCBITCHK(pfh->UFHflag,UFHFCIDOFF))         //~vbv6I~
    	            	return erralready();                       //~vbv6R~
                    break;                                         //~vbv6I~
                case 4:         //defon NOAPPEND                   //~vbv6R~
            		if (!UCBITCHK(Gopt5,GOPT5CIDAPPEND)            //~vbv6R~
            	    &&  !UCBITCHK(Gopt2,GOPT2NOCID))               //~vbv6I~
                    	return erralready();                       //~vbv6I~
                    break;                                         //~vbv6I~
                case 5:         //defoff NOAPPEND                  //~vbv6R~
            		if (!UCBITCHK(Gopt5,GOPT5CIDAPPEND)            //~vbv6R~
            	    &&  UCBITCHK(Gopt2,GOPT2NOCID))                //~vbv6I~
                    	return erralready();                       //~vbv6I~
                	break;                                         //~vbv6I~
                default:                                           //~vbv6I~
        			uerrmsg("NOAPPEND option is valid with ON/OFF/DEFON/DEFOFF",//~vbv6I~
        					"NOAPPEND 指定は ON/OFF/DEFON/DEFOFF で指定する");//~vbv6I~
        			return 4;                                      //~vbv6I~
                }                                                  //~vbv6I~
            }                                                      //~vbv6I~
    		switch(opid)                                           //~v79UI~
            {
        	case 0:	//err
            	if (*pc || opdno==1)   //not ",xx" or not "," format
                {                                                  //~v42jI~
                    if (strlen(pc)>3 && !memicmp(pc,"TOP",3))   //topxxx//~v42jR~
            			return fcmdcidsettop(Ppcw,pfh,-1,pc);   //cobol with col72-80//~v42jI~
                	return errinvalid(pc);                      //~v033I~
                }                                                  //~v42jI~
                break;
        	case 1:	//on
            	if (UCBITCHK(pfh->UFHflag,UFHFCIDON)
				&&  opdno==1)		//no type operand
        		{
        			uerrmsg("CID-add function is already On for this file",
//        					"CID セット機能はこのファイルですでにオンです");//~v095R~
        					"CID セット機\x94\\はこのファイルですでにオンです");//~v095I~
        			return 4;
        		}
                if (UCBITCHK(pfh->UFHflag,UFHFWORKDIRFILE))  //cb or so//~v0ifI~
			    	return fcmdinvalidfile();                      //~v0ifR~
                if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //bin file  //~v10dI~
			    	return fcmdinvalidbinfile();                   //~v10dI~
			 	if (pfh->UFHcidtype==UFHCIDTYPEERR && opdno==1)
				{
					uerrmsg("CID type is not defined on this file",
						"このファイルには CID-タイプ が定義されていません");
					return 4;
				}
                break;
        	case 2:	//off
                if (UCBITCHK(pfh->UFHflag,UFHFWORKDIRFILE))  //cb or so//~v10dI~
			    	return fcmdinvalidfile();                      //~v10dI~
                if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //bin file  //~v10dI~
			    	return fcmdinvalidbinfile();                   //~v10dI~
            	if (UCBITCHK(pfh->UFHflag,UFHFCIDOFF))
        		{
				  if (opdno==1)		//no type operand              //~vbv6I~
                  {                                                //~vbv6I~
        			uerrmsg("CID-add function is already Off for this file",
//      					"CID セット機能はこのファイルですでにオフです");//~v095R~
        					"CID セット機\x94\\はこのファイルですでにオフです");//~v095I~
        			return 4;
                  }                                                //~vbv6I~
        		}
                break;
        	case 3:	//clear
        	case 7:	//shift                                        //~v09rI~
			    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))
				{
					uerrmsg("Now Browse mode",
//  				"現在は 表示モードです");                      //~v095R~
    				"現在は \x95\\示モードです");                  //~v095R~
					return 4;
				}
                if (UCBITCHK(pfh->UFHflag,UFHFWORKDIRFILE))  //cb or so//~v10dI~
			    	return fcmdinvalidfile();                      //~v10dI~
                if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))  //bin file  //~v10dI~
			    	return fcmdinvalidbinfile();                   //~v10dI~
			 	if (pfh->UFHcidtype==UFHCIDTYPEERR && opdno==1) //~5311I~
				{                                               //~5311I~
//  				uerrmsg("CID type is not defined on this file",//~v157R~
//  					"このファイルには CID-タイプ が定義されていません");//~v157R~
    				uerrmsg("CID type operand is required for this file",//~v157I~
    					"このファイルでは CID-タイプ の指定が必要です");//~v157I~
					return 4;                                   //~5311I~
				}                                               //~5311I~
                break;
        	case 4:	//defon
//            if (!appendopt)                                      //~vbv6R~
              if (!appendopt && !appendoptNo)                      //~vbv6I~
            	if (!UCBITCHK(Gopt2,GOPT2NOCID))
        		{
        			uerrmsg("Default CID-add function is already On",
//      					"CID 機能の省略時値はすでにオンです"); //~v095R~
        					"CID 機\x94\\の省略時値はすでにオンです");//~v095R~
        			return 4;
        		}
                break;
        	case 5:	//defoff
//            if (!appendopt)                                      //~vbv6R~
              if (!appendopt && !appendoptNo)                      //~vbv6I~
            	if (UCBITCHK(Gopt2,GOPT2NOCID))
        		{
        			uerrmsg("Default CID-add function is already Off",
//      					"CID 機能の省略時値はすでにオフです"); //~v095R~
        					"CID 機\x94\\の省略時値はすでにオフです");//~v095R~
        			return 4;
        		}
                break;
        	case 6:	//?
            	fcmdcidhelp(Ppcw,pfh);                             //~v0eAR~
				return 0;
        	case 8:	//TOP                                          //~v20NR~
            	return fcmdcidsettop(Ppcw,pfh,1,pc);  //update ctr only//~v42jR~
//				return 0;                                          //~v20SR~
        	case 9:	//TOPA                                         //~v20NI~
            	return fcmdcidsettop(Ppcw,pfh,0,pc);   //all option//~v42jR~
//				return 0;                                          //~v20SR~
        	case 10:	//TOPB                                     //~v40DI~
        	case 11:	//TOPCOB                                   //~v40DI~
            	return fcmdcidsettop(Ppcw,pfh,2,pc);   //cobol option//~v42jR~
        	case 12:	//TOPCN                                    //~v41aI~
        	case 13:	//TOPNC                                    //~v41aI~
            	return fcmdcidsettop(Ppcw,pfh,3,pc);   //cobol with col72-80//~v42jR~
        	case 14:	//TOPK                                     //~v42yI~
            	return fcmdcidsettop(Ppcw,pfh,4,pc);   //cobol with col72-80//~v42yI~
        	case 15:	//TOPKN                                    //~v42yI~
        	case 16:	//TOPNK                                    //~v42yI~
            	return fcmdcidsettop(Ppcw,pfh,5,pc);   //cobol with col72-80//~v42yI~
        	case 17:	//TOPD                                     //~v75sI~
            	return fcmdcidsettop(Ppcw,pfh,6,pc);   //F80(SPF data)//~v75sI~
#ifdef UTF8SUPPH                                                   //~va1qI~
        	case 18:	//COPYON                                   //~va02I~
                if (UCBITCHK(Goptopt2,GOPT2_CIDCOPY))              //~va02I~
                    return erralready();                           //~va02I~
                UCBITON(Goptopt2,GOPT2_CIDCOPY);                   //~va02I~
        		uerrmsg("CID copy option for \"C\" lcmd is set ON",//~va02I~
        				"CIDコピーオプションは ON になりました。");//~va02I~
            	return 0;                                          //~va02I~
        	case 19:	//COPYOFF                                  //~va02I~
                if (!UCBITCHK(Goptopt2,GOPT2_CIDCOPY))             //~va02I~
                    return erralready();                           //~va02I~
                UCBITOFF(Goptopt2,GOPT2_CIDCOPY);                  //~va02I~
        		uerrmsg("CID copy option for \"C\" lcmd is set OFF",//~va02I~
        				"CIDコピーオプションは OFF になりました。");//~va02I~
            	return 0;                                          //~va02I~
#endif                                                             //~va1qI~
        	}
            break;
        case 1:		//second opd
//          if (appendopt)                                         //~vbv6R~
            if (appendopt||appendoptNo)                            //~vbv6R~
                break;                                             //~v79UM~
 			switch(opid)
            {
        	case 2:	//off
        	case 4:	//defon
        	case 5:	//defoff
        	case 6:	//?                                               //~v06rI~
        		uerrmsg("2nd operand avail only for ON/CLEAR/SHIFT",//~v09rR~
        				"第2オペランドは ON/CLEAR/SHIFTのときだけ有効です");//~v09rR~
        		return 4;
        	case 0:	//ommitted   ",asm" etc
        	case 1:	//on
        	case 3:	//claer
        	case 7:	//shift                                        //~v09rM~
//          	if(!(cidtype=filecidtypechk(cidtypec=pc,0)))//no alias//~v09rR~
                if ((len=(int)strlen(pc))>LINEPREFIXLEN            //~v09FI~
                && (*(pc+LINEPREFIXLEN)==',' || *(pc+LINEPREFIXLEN)==' '))//~v09FI~
                {                                                  //~v09FI~
                	if (len>LINEPREFIXLEN+LINEPOSTFIXLEN+1)        //~v09FI~
                    	return fcmdpostfixlenerr(pc+LINEPREFIXLEN+1);//~v09FI~
                    *postfixw=',';                                 //~v09FI~
                    strcpy(postfixw+1,pc+LINEPREFIXLEN+1);         //~v09FI~
				}                                                  //~v09FI~
            	if(!(pcidtbl=filecidtypechk(pc,0)))//no alias      //~v09FR~
                {
            	  if(!(pcidtbl=filecidtypechkUTF8(pfh,pc)))//no alias//~vbw3R~
                  {                                                //~vbw3I~
//      			uerrmsg("%s is not valid CID type",            //~vbw3R~
//      					"%s は 無効な CID タイプです",         //~vbw3R~
        			uerrmsg("%s is not valid CID type, check Change_ID_Type_ of ::xe.ini.",//~vbw3I~
        					"%s は 無効な CID タイプです、::xe.ini の Change_ID_Type_ を確認してください。",//~vbw3I~
							pc);
        			return 4;
                  }                                                //~vbw3I~
                  else                                             //~vbw3I~
                  {                                                //~vbw3I~
					if (!FILEUTF8MODE(pfh))                        //~vbw3R~
                    {                                              //~vbw3I~
        				uerrmsg("%s is not valid CID type for not CPU8 file",//~vbw3I~
        						"%s は CPLC ファイルには無効な CID タイプです",//~vbw3I~
								pc);                               //~vbw3I~
        				return 4;                                  //~vbw3I~
                    }                                              //~vbw3I~
                  }                                                //~vbw3I~
        		}
            	cidtype=(int)pcidtbl->CIDTid;//cid type;           //~v09rI~
                strcpy(cidtypec,pcidtbl->CIDTexttbl);              //~v09FR~
                break;                                             //~v79UI~
        	}
            break;
        case 2:		//third opd
            if (cidtype)	//accept postfix                       //~v09FI~
            {                                                      //~v09FI~
            	if (strlen(pc)>LINEPOSTFIXLEN)                     //~v09FR~
                	return fcmdpostfixlenerr(pc);                  //~v09FR~
                *postfixw=',';                                     //~v09FR~
                strcpy(postfixw+1,pc);                             //~v09FI~
            }                                                      //~v09FI~
            else                                                   //~v09FI~
        	return errtoomany();                                //~v033R~
            break;                                                 //~v09FI~
        case 3:		//third opd                                    //~v09FI~
        	return errtoomany();                                   //~v09FI~
		}//sw by opd no
	}//loop by operand no

//*process
    UTRACEP("%s:cidtype=%d\n",UTT,cidtype);                        //~vbv6R~
	if (cidtype)
    {
    	switch(opid)                                               //~v09rI~
        {                                                          //~v09rI~
    	case 0:	//err                                              //~v09rI~
    	case 1:	//on                                               //~v09rI~
//  		filegetcid(pfh,2,0);	//reset by chk first line if sline==0//~v0avR~
    		if (filegetcid(pfh,2,0,0))	//reset by chk first line if sline==0//~v0avR~
               	return 4;//cid header err                          //~v0avI~
//  		if (pfh->UFHcidtype==(UCHAR)cidtype) 	//not change   //~v09FR~
//          {                                                      //~v09FR~
//      		uerrmsg("CID type is already %s",                  //~v09FR~
//      				"CID タイプ は既に %s です",               //~v09FR~
//      				cidtypec);                                 //~v09FR~
//  			return 4;                                          //~v09FR~
//  		}   //postfix may changed                              //~v09FR~
    		if (UCBITCHK(pfh->UFHflag2,UFHF2HDRLINECID))           //~v09rR~
            {                                                      //~v09rI~
        		uerrmsg("File has CID on 1st line,it cannot be changed type",//~v09rI~
        				"1 行目に CID 指定があります,変更出来ません");//~v09rI~
    			return 4;                                          //~v09rI~
    		}                                                      //~v09rI~
            break;                                                 //~v09rI~
    	case 3:	//clear                                            //~v09rI~
    	case 7:	//shift                                            //~v09rI~
//          cidtypesv=pfh->UFHcidtype;                             //~v09FR~
//          cidpossv=pfh->UFHcidpos;                               //~v09FR~
//          memcpy(cidsv,pfh->UFHcid,sizeof(pfh->UFHcid));         //~v09FR~
//          fixidsv=(char)UCBITCHK(pfh->UFHflag2,UFHF2FIXEDCID);   //~v09FR~
//          UCBITOFF(pfh->UFHflag2,UFHF2FIXEDCID);                 //~v09FR~
            break;                                                 //~v09rI~
        }                                                          //~v09rI~
        pfh->UFHcidtype=(UCHAR)cidtype;
//      pfh->UFHcidpos=pcidtbl->CIDTpos;  reset by filegetcid(1)   //~v09FR~
//		filegetcid(pfh,1,postfixw+1);	//reset pfh cid            //~v0avR~
  		filegetcid(pfh,1,postfixw+1,0);	//reset pfh cid            //~v0avI~
	}
    else                                                           //~v09rI~
    {                                                              //~v09rI~
    	switch(opid)                                               //~v09rI~
        {                                                          //~v09rI~
    	case 3:	//clear                                            //~v09rI~
    	case 7:	//shift                                            //~v09rI~
//      	filegetcid(pfh,2,0);	//reset by chk first line if sline==0//~v0avR~
            if (filegetcid(pfh,2,0,0))	//reset by chk first line if sline==0//~v0avR~
               	return 4;//cid header err                          //~v0avI~
            break;                                                 //~v09rI~
        }                                                          //~v09rI~
	}                                                              //~v09rI~
    rc=0;                                                          //~v09rI~
	switch(opid)
    {
	case 0:	// ommited 1st opd
		uerrmsg("CID type is set to %s",
				"CID タイプ を %s にセットしました",
				cidtypec);
        break;
	case 1:	//on
    	UCBITON(pfh->UFHflag,UFHFCIDON);	//explicit cmd on
    	UCBITOFF(pfh->UFHflag,UFHFCIDOFF);
        if(cidtype)
			uerrmsg("CID(type %s%s) is set on the modified line of this file when Save",//~v10HR~
					"このファイルの保存時,変更行には %s%s タイプの CID がセットされます",//~v09FR~
					cidtypec,postfixw);                            //~v09FR~
        else
			uerrmsg("CID is set on the modified line of this file when Save",
					"このファイルの保存時,変更行には CID がセットされます");
        if (appendopt)                                             //~v79UI~
        {                                                          //~v79UI~
            UCBITON(pfh->UFHflag9,UFHF9CIDAPPEND);                 //~v79UI~
            UCBITOFF(pfh->UFHflag9,UFHF9CIDAPPENDN); //reset no append//~v79UI~
			uerrmsgcat("(APPEND mode)",0);                         //~v79UI~
        }                                                          //~v79UI~
        if (appendoptNo)                                           //~vbv6I~
        {                                                          //~vbv6I~
            UCBITOFF(pfh->UFHflag9,UFHF9CIDAPPEND);                //~vbv6I~
            UCBITON(pfh->UFHflag9,UFHF9CIDAPPENDN); //reset no append//~vbv6I~
			uerrmsgcat("(NOAPPEND mode)",0);                       //~vbv6I~
        }                                                          //~vbv6I~
        break;
	case 2:	//off
//    if (appendopt)	//reset append mode only                   //~vbv6R~
//    {                                                            //~vbv6R~
//  	uerrmsg("CID append mode is reset",                        //~vbv6R~
//  			"このファイルのCID APPEND モードをリセット");      //~vbv6R~
//    }                                                            //~vbv6R~
//    else                                                         //~vbv6R~
//    {                                                            //~vbv6R~
    	UCBITON(pfh->UFHflag,UFHFCIDOFF);
    	UCBITOFF(pfh->UFHflag,UFHFCIDON);
		uerrmsg("CID is not set on the modified line of this file when Save",
				"このファイルの保存時,変更行に CID はセットされません");
//    }                                                            //~vbv6R~
      if (appendoptNo)	//reset append mode only                   //~vbv6I~
      {                                                            //~vbv6I~
	  	UCBITOFF(pfh->UFHflag9,UFHF9CIDAPPEND);
	  	UCBITON(pfh->UFHflag9,UFHF9CIDAPPENDN);                    //~v79UI~
		uerrmsgcat("(NOAPPEND mode)",0);                           //~vbv6I~
      }                                                            //~vbv6I~
      if (appendopt)	//reset append mode only                   //~vbv6I~
      {                                                            //~vbv6I~
	  	UCBITON(pfh->UFHflag9,UFHF9CIDAPPEND);                     //~vbv6I~
	  	UCBITOFF(pfh->UFHflag9,UFHF9CIDAPPENDN);                   //~vbv6I~
		uerrmsgcat("(APPEND mode)",0);                             //~vbv6I~
      }                                                            //~vbv6I~
                                                                   //~vbv6I~
        break;
	case 3:	//clear
		lineno=filecidclear(Ppcw,pfh,CIDOPTCLEAR);                    //~v06rR~
        if (lineno<0)	//storage shortage                      //~v04dI~
        	rc=UALLOC_FAILED;                                      //~v09rR~
        else                                                       //~v73fI~
        if (lineno==0 && FILEUTF8MODE(pfh) && UCBITCHK(pfh->UFHflag14,UFHF14CIDU8))//+vbw3I~
			uerrmsg("No CID found. Unicode CID prefix may be missed for file shared between different language environment",//+vbw3I~
					"CID が見つかりません。ユニコードCIDプレフィックスは異なる言語環境では相互認識出来ないことがあります",//+vbw3I~
						lineno);                                   //+vbw3I~
        else                                                       //+vbw3I~
		uerrmsg("Cleared CID of %ld line",
				"%ld 行 の CID をクリアー",
				lineno);
        break;
	case 4:	//defon
    	UCBITOFF(Gopt2,GOPT2NOCID);
      	UCBITOFF(Giniopt2,GOPT2NOCID);               
//  	UCBITON(Gprocstatus,GPROCSINIUPDATE);   //need write ini at term//~v065R~
		uerrmsg("CID-add function is set On as default",
//  			"CID 機能を省略時オンに設定");                     //~v095R~
				"CID 機\x94\\を省略時オンに設定");                 //~v095I~
        if (appendopt)                                             //~v79UI~
        {                                                          //~v79UI~
            UCBITON(Gopt5,GOPT5CIDAPPEND);                         //~v79UI~
			uerrmsgcat("(Default-APPEND mode)",0);                         //~v79UI~//~vbv6R~
        }                                                          //~v79UI~
        if (appendoptNo)                                           //~vbv6I~
        {                                                          //~vbv6I~
            UCBITOFF(Gopt5,GOPT5CIDAPPEND);                        //~vbv6I~
			uerrmsgcat("(default-NOAPPEND mode)",0);               //~vbv6R~
        }                                                          //~vbv6I~
        break;
	case 5:	//defoff
//    if (appendopt)	//reset append mode only                   //~vbv6R~
//    {                                                            //~vbv6R~
//  	uerrmsg("default CID append mode is reset",                //~vbv6R~
//  			"省略値CID APPEND モードをリセット");              //~vbv6R~
//    }                                                            //~vbv6R~
//    else                                                         //~vbv6R~
//    {                                                            //~vbv6R~
    	UCBITON(Gopt2,GOPT2NOCID);
      	UCBITON(Giniopt2,GOPT2NOCID);                
//  	UCBITON(Gprocstatus,GPROCSINIUPDATE);   //need write ini at term//~v065R~
		uerrmsg("CID-add function is set Off as default",
//  			"CID 機能を省略時オフに設定");                     //~v095R~
    			"CID 機\x94\\を省略時オフに設定");                 //~v095R~
//    }                                                            //~vbv6R~
      if (appendopt)	//reset append mode only                   //~vbv6I~
      {                                                            //~vbv6I~
        UCBITON(Gopt5,GOPT5CIDAPPEND);                             //~vbv6I~
		uerrmsgcat("(Default-APPEND mode)",0);                     //~vbv6R~
      }                                                            //~vbv6I~
      if (appendoptNo)	//reset append mode only                   //~vbv6I~
      {                                                            //~vbv6I~
        UCBITOFF(Gopt5,GOPT5CIDAPPEND);                            //~v79UM~
		uerrmsgcat("(Default-NOAPPEND mode)",0);                   //~vbv6R~
      }                                                            //~vbv6I~
        break;
	case 7:	//shift                                                   //~v06rI~
		lineno=filecidclear(Ppcw,pfh,CIDOPTSHIFT);                    //~v06rR~
        if (lineno<0)	//storage shortage                            //~v06rI~
        	rc=UALLOC_FAILED;                                      //~v09rR~
        else                                                       //~v73fI~
		uerrmsg("Shifted CID of %ld line",                            //~v06rI~
				"%ld 行 の CID を整列",                               //~v06rI~
				lineno);                                              //~v06rI~
        break;                                                        //~v06rI~
	}
	if (cidtype)                                                   //~v09rI~
    {                                                              //~v09rI~
    	switch(opid)                                               //~v09rI~
        {                                                          //~v09rI~
		case 3:	//clear                                            //~v09rI~
    	case 7:	//shift                                            //~v09rI~
//          pfh->UFHcidtype=cidtypesv;                             //~v09FR~
//          pfh->UFHcidpos=cidpossv;                               //~v09FR~
//          memcpy(pfh->UFHcid,cidsv,sizeof(pfh->UFHcid));         //~v09FR~
//          if (fixidsv)                                           //~v09FR~
//              UCBITON(pfh->UFHflag2,UFHF2HDRLINECID);            //~v09FR~
//  		filegetcid(pfh,3,0);	//restore from saved at status filegetcid(1)//~v0avR~
    		filegetcid(pfh,3,0,0);	//restore from saved at status filegetcid(1)//~v0avI~
            break;                                                 //~v09rI~
		}                                                          //~v09rI~
	}                                                              //~v09rI~
	return rc;                                                     //~v09rR~
}//func_cid

//***********************************************                  //~v20wI~
//*!fcmdcidsettop  ******************************                  //~v20wI~
//*insert top cid line sample                                      //~v20wI~
//*parm1 :client work element                  *                   //~v20wI~
//*parm2 :pfh                                                      //~v20wI~
//*parm3 :option(0:full option,1:update ctr only)                  //~v20NI~
//*return:rc  4:browse mode,patial file                            //~v20SR~
//***********************************************                  //~v20wI~
int fcmdcidsettop(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Poption,char *Pfiletype)//~v42jR~
{                                                                  //~v20wI~
//static char Stopcidlinesample[]="//*CID://+dateR~:#63 option=(m72,n,p0,tabclear) update#=    1;";//~v75sR~
static char Stopcidlinesample[]="//*CID://+dateR~:#63 option=(f80,m72,n,p0,tabclear) update#=    1;";//~v75sI~
static char Stopcidlinesampl2[]="//*CID://+dateR~:                             update#=    1;";//~v20NR~
static char Stopcidlinesampl3[]=                                   //~v40WR~
"000000*CID:**+NONER~:option=(m72,n,cob,p0,tabclear) update#=    1;      00000000";//~v42yR~
static char Stopcidlinesampl4[]=                                   //~v41aI~
"000000*CID:**+NONER~:option=(m72,cob,p0,tabclear)   update#=    1;      00000000";//~v41aI~
static char Stopcidlinesamplk[]=                                   //~v42yI~
"      *CID:**+NONER~:option=(m72,cobk,p0,tabclear)  update#=    1;      00000000";//~v42yI~
static char Stopcidlinesamplkn[]=                                  //~v42yI~
"      *CID:**+NONER~:option=(m72,n,cobk,p0,tabclear)  update#=    1;      00000000";//~v42yI~
static char Stopcidlinesampld[]=                                   //~v75sI~
"      *CID:**+NONER~:option=(f80,p0)  update#=    1;                              ";//~v75sR~
	int rc;                                                        //~v20wI~
    PULINEH plh;                                                   //~v20wI~
    PUFILEC pfc;                                                   //~v20SI~
    char *pc="",*cid;                                                 //~v20TR~//~vafcR~
    char toplinedata[CIDTOP_MAXSZ];                                //~v42jI~
//****************************                                     //~v20wI~
	pfc=Ppcw->UCWpfc;                                              //~v20SI~
	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                         //~v20SI~
		return errbrowsemode();                                    //~v20SI~
    if (Ppfh->UFHsline)		//partial,top line not loaded          //~v20SI~
    {                                                              //~v20SI~
	    uerrmsg("This is partialy loaded file.",                   //~v20SI~
            	"1行目がReadされてない部分編集です。");            //~v20SI~
        return 4;                                                  //~v20SI~
    }                                                              //~v20SI~
	UPCTRREQ(Ppfh);	//end of a shot                                //~v20wI~
	plh=UGETQTOP(&Ppfh->UFHlineque);                               //~v20wI~
    switch(Poption)                                                //~v40DR~
    {                                                              //~v40DI~
    case 1:                                                        //~v40DI~
        pc=Stopcidlinesampl2;   //updatectr only                   //~v20NR~
        break;                                                     //~v40DI~
    case 0:                                                        //~v40DR~
        pc=Stopcidlinesample;   //all                              //~v20NR~
        break;                                                     //~v40DI~
    case 2:                                                        //~v40DI~
        pc=Stopcidlinesampl4;   //topc topcob                      //~v41aR~
        break;                                                     //~v40DI~
    case 3:                                                        //~v41aI~
        pc=Stopcidlinesampl3;   //topcn topnc                      //~v41aI~
        break;                                                     //~v41aI~
    case 4:                                                        //~v42yI~
        pc=Stopcidlinesamplk;   //topk                             //~v42yI~
        break;                                                     //~v42yI~
    case 5:                                                        //~v42yI~
        pc=Stopcidlinesamplkn;   //topkn                           //~v42yI~
        break;                                                     //~v42yI~
    case 6:                                                        //~v75sI~
        pc=Stopcidlinesampld;   //topd                             //~v75sI~
        break;                                                     //~v75sI~
    }                                                              //~v40DI~
//chk file in wd                                                   //~v42jI~
	if (fcmdchkcidtopfile(Poption,Pfiletype,toplinedata))	//not found//~v42jI~
    {                                                              //~v42jI~
    	if (Poption<0)                                             //~v42jI~
	    	return 4;                                              //~v42jI~
    }                                                              //~v42jI~
    else                                                           //~v42jI~
    	pc=toplinedata;                                            //~v42jI~
  if (pc!=toplinedata)	//not file but default                     //~v42jI~
    if (*(cid=Ppfh->UFHcid))                                       //~v20TR~
    {                                                              //~v20TR~
    	memcpy(pc,cid,2);                                          //~v20TR~
    	memcpy(pc+7,cid,2);                                        //~v20TR~
    }                                                              //~v20TR~
	rc=fcmdisrtline(Ppcw,plh,pc,(int)strlen(pc));                  //~v40bR~
    if (!rc)                                                       //~v40XI~
	    if (Poption==2) //topc                                     //~v40XR~
        {                                                          //~v40XI~
            plh=UGETQNEXT(plh);     //isrted line                  //~v40XI~
            if (plh->ULHsuffix>=100)       //for topline           //~v40XR~
            	plh->ULHsuffix=99;                                 //~v40XI~
    	    filespfnumedit(Ppfh,plh,SPFNUMEDIT_COB|SPFNUMEDIT_CIDTOP|SPFNUMEDIT_CURVER);//~v40XR~
        }                                                          //~v40XI~
	UPCTRREQ(Ppfh);	//end of a shot                                //~v20wI~
	return rc;                                                     //~v20wI~
}//fcmdcidsettop                                                   //~v20wI~
//***********************************************                  //~v42jI~
//*get topline data from file                                      //~v42jI~
//***********************************************                  //~v42jI~
int fcmdchkcidtopfile(int Poption,char *Pfiletype,char *Ptopdata)  //~v42jI~
{                                                                  //~v42jI~
	FILE          *fh;                                             //~v42jI~
//	UCHAR fpath[_MAX_PATH],fnm[16],*pc;                            //~vbs7R~
  	UCHAR fpath[_MAX_PATH],fnm[_MAX_PATH+256],*pc;                 //~vbs7R~
//****************************                                     //~v42jI~
//search file                                                      //~v42jI~
	strcpy(fpath,Pfiletype+3);                                     //~v53dR~
    strlwr(fpath);                                                 //~v53dR~
	sprintf(fnm,"::%s.%s",CIDTOP_FNAME,fpath);                     //~v53dR~
	if (filefind(fnm,fpath,0,FFMSG)!=0)	//no fstat output          //~v53dR~
    {                                                              //~v42jI~
		if (Poption==-1)	//no default exist                     //~v42jI~
        	return 4;                                              //~v42jI~
        ugeterrmsg();   //clear errmsg                             //~v42jI~
        return 1;       //use default                              //~v42jI~
	}                                                              //~v42jI~
    if (!(fh=fileopen(fpath,"r")))                                 //~v53dR~
        return 4;                                                  //~v42jI~
    if (!fgets(Ptopdata,CIDTOP_MAXSZ,fh))//null if error/ eof      //~v42jR~
    {                                                              //~v42jI~
        uerrmsg("%s CIDTOP data read faileed",0,                   //~v42jI~
                fnm);                                              //~v42jI~
        return 4;                                                  //~v42jI~
    }                                                              //~v42jI~
    Ptopdata[CIDTOP_MAXSZ-1]=0;                                    //~v42jI~
    if ((pc=memchr(Ptopdata,'\n',CIDTOP_MAXSZ))!=0)                //~v42jI~
    {                                                              //~v74BR~
        *pc=0;                                                     //~v42jI~
        if (pc>(UCHAR*)Ptopdata && *(pc-1)=='\r')                  //~v74BR~
        	*(pc-1)=0;                                             //~v74BR~
    }                                                              //~v74BR~
    fileclose(fpath,fh);                                           //~v53dR~
	return 0;                                                      //~v42jI~
}//fcmdchkcidtopfile                                               //~v42jI~
//***********************************************                  //~v20wI~
//*!fcmdisrtline  ******************************                   //~v20wI~
//*insert line with specified data                                 //~v20wI~
//*when tgt is ebc file,translate to ebc(source is ascii internal data)//~va50I~
//*parm1 :client work element                  *                   //~v20wI~
//*parm2 :plh                                                      //~v20wI~
//*return:rc                                                       //~v20wI~
//***********************************************                  //~v20wI~
int fcmdisrtline(PUCLIENTWE Ppcw,PULINEH Pplh,char *Pdata,int Plen)//~v20wI~
{                                                                  //~v20wI~
	PULINEH plh;                                                   //~v20wI~
	int rc;                                                        //~v20wI~
    int len;                                                       //~v62pI~
//  char *pdbcs;                                                   //~v40XR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    int swebcfile;                                                 //~va50I~
    int handle;                                                    //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//****************************                                     //~v20wI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    swebcfile=PLH_ISEBC(Pplh);                                     //~va50R~
    handle=UGETPFH(Pplh)->UFHhandle;                               //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//    if (!(pdbcs=umalloc((UINT)Plen)))                            //~v40XR~
//        return UALLOC_FAILED;      //top 1 byte                  //~v40XR~
//    setdbcstbl(Pdata,pdbcs,Plen);                                //~v40XR~
//  if (!(rc=lcmdisrt(Ppcw,Pplh,1,0)))  //1line,req no indentation //~v40XR~
    if (!(rc=lcmdisrtwithlen(Ppcw,Pplh,1,0,Plen)))  //1line,req no indentation//~v40XI~
    {                                                              //~v20wI~
        plh=UGETQNEXT(Pplh);      //inserted                       //~v20wI~
        if (!plh)                                                  //~v512I~
            plh=UGETQPREV(Pplh);                                   //~v512I~
//        filesetcsr(Ppcw,plh,1,0);   //reset to cur line fldno 1,fldtop//~v40XR~
//  	if (charcap2(Ppcw,CHAROPBREP,Pdata,pdbcs,Plen,plh,0)==UALLOC_FAILED) //block replace//~v40DR~
//      	rc=UALLOC_FAILED;      //top 1 byte                    //~v40DR~
//        rc=charcap2(Ppcw,CHAROPBREP,Pdata,pdbcs,Plen,plh,0);     //~v40XR~
        memcpy(plh->ULHdata,Pdata,(UINT)Plen);                           //~v40XI~
      if (Sisrtdbcs)                                               //~v511I~
      {                                                            //~v511I~
		plh->ULHdbcs=UALLOCC(1,(UINT)plh->ULHbufflen);             //~v511I~
		UALLOCCHK(plh->ULHdbcs,UALLOC_FAILED);   //return 0 if storage shortage//~v511I~
        memcpy(plh->ULHdbcs,Sisrtdbcs,(UINT)Plen);                 //~v511I~
        len=Plen;                                                  //~v69BR~
        if (filetabexp(1,plh,0,&len)==UALLOC_FAILED)   //1:rechk, 0:offset tab re-expand(len update)//~v69BR~
            return UALLOC_FAILED;                                  //~v69BR~
      }                                                            //~v511I~
      else                                                         //~v511I~
      {                                                            //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//      UCVEBC_a2bfld(swebcfile,plh->ULHdata,Plen); //a2b in the place//~va50I~//~va79R~
        UCVEBC_a2bfld(swebcfile,handle,plh->ULHdata,Plen); //a2b in the place//~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
        if (filechktabdbcs(plh)==UALLOC_FAILED)                    //~v40XR~
        	rc=UALLOC_FAILED;                                      //~v40XI~
      }                                                            //~va50I~
    }                                                              //~v20wI~
//    ufree(pdbcs);                                                //~v40XR~
    return rc;                                                     //~v20wI~
}//fcmdisrtline                                                    //~v20wI~
//***********************************************                  //~v511I~
//*!fcmdisrtlinedbcs                                               //~v511I~
//*insert line with specified data/dbcs                            //~v511I~
//*parm1 :client work element                                      //~v511I~
//*parm2 :isrt after this plh                                      //~v511I~
//*parm3 :isrt data                                                //~v511I~
//*parm4 :isrt dbcs                                                //~v511I~
//*return:rc                                                       //~v511I~
//***********************************************                  //~v511I~
int fcmdisrtlinedbcs(PUCLIENTWE Ppcw,PULINEH Pplh,char *Pdata,char *Pdbcs,int Plen)//~v511I~
{                                                                  //~v511I~
	int rc;                                                        //~v511I~
    PULINEH plh;                                                   //~va50R~
//****************************                                     //~v511I~
    Sisrtdbcs=Pdbcs;                                               //~v511I~
	rc=fcmdisrtline(Ppcw,Pplh,Pdata,Plen);                         //~v511I~
    Sisrtdbcs=0;                                                   //~v511I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50M~
    if (PLH_ISEBC(Pplh))                                           //~va50M~
    {                                                              //~va50I~
        plh=UGETQNEXT(Pplh);                                       //~va50I~
		xeebc_setdbcstblplh(0,0/*pfh*/,plh,Plen);                  //~va50R~
    }                                                              //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50M~
    return rc;                                                     //~v511I~
}//fcmdisrtlinedbcs                                                //~v511I~
//***********************************************                  //~va8kI~
//*!fcmdisrtlinedbcsebcsosi                                        //~va8kI~
//*insert line with specified data/dbcs                            //~va8kI~
//*return:rc UALLOC_FAILED                                         //~va8kI~
//***********************************************                  //~va8kI~
int fcmdisrtlinedbcsebcsosi(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,char *Pdata,char *Pdbcs,int Plen)//~va8kI~
{                                                                  //~va8kI~
	int rc,swso,swsi,len;                                          //~va8kR~
    char *pcd,*pc,*pc2,*pcd2;                                      //~va8kR~
//****************************                                     //~va8kI~
	swso=(Popt & FCILDEO_INSERT_SO)!=0;                            //~va8kR~
	swsi=(Popt & FCILDEO_APPEND_SI)!=0;                            //~va8kR~
	len=Plen+swso+swsi;                                            //~va8kI~
    if (len>Plen)                                                  //~va8kI~
    {                                                              //~va8kI~
//      pc=pc2=umalloc(len*2);                                     //~va8kR~//~vb2DR~
        pc=pc2=umalloc((size_t)len*2);                             //~vb2DI~
		UALLOCCHK(pc,UALLOC_FAILED);   //return 0 if storage shortage//~va8kI~
        pcd=pcd2=pc+len;                                           //~va8kR~
    	if (swso)                                                  //~va8kI~
        {                                                          //~va8kI~
    		*pc2++=CHAR_SO;                                        //~va8kI~
            *pcd2++=0;                                             //~va8kI~
        }                                                          //~va8kI~
//  	memcpy(pc2,Pdata,Plen);                                    //~va8kI~//~vb2DR~
    	memcpy(pc2,Pdata,(size_t)Plen);                            //~vb2DI~
//  	memcpy(pcd2,Pdbcs,Plen);                                   //~va8kI~//~vb2DR~
    	memcpy(pcd2,Pdbcs,(size_t)Plen);                           //~vb2DI~
    	if (swsi)                                                  //~va8kI~
        {                                                          //~va8kI~
    		*(pc2+Plen)=CHAR_SI;                                   //~va8kI~
    		*(pcd2+Plen)=0;                                        //~va8kI~
        }                                                          //~va8kI~
    }                                                              //~va8kI~
    else                                                           //~va8kI~
        pc=Pdata,pcd=Pdbcs;                                        //~va8kI~
	rc=fcmdisrtlinedbcs(Ppcw,Pplh,pc,pcd,len);                     //~va8kR~
    if (len>Plen)                                                  //~va8kI~
    	ufree(pc);                                                 //~va8kI~
    if (rc==UALLOC_FAILED)                                         //~va8kI~
    	return rc;                                                 //~va8kI~
    return 0;                                                      //~va8kI~
}//fcmdisrtlinedbcsebcsosi                                         //~va8kI~
//***********************************************
//*!fcmdcidhelp    ******************************                  //~v0eAR~
//*parm1 :client work element                  *
//*parm2 :pfh                                                      //~v0eAI~
//*return:rc
//***********************************************
int fcmdcidhelp(PUCLIENTWE Ppcw,PUFILEH pfh)                       //~v0eAR~
{
	UCHAR *pc;                                                     //~v0eAI~
//****************************
                UCBITON(Ppcw->UCWflag,UCWFDRAW);  //full redraw    //~v0buI~
//      		filegetcid(pfh,2,0);	//reset by chk first line if sline==0//~v0avR~
        		if (filegetcid(pfh,2,0,0))	//reset by chk first line if sline==0//~v0avI~
                	return 4;//cid header err                      //~v0avI~
            	pc=filegetcidtype(pfh);
        		if (UCBITCHK(pfh->UFHflag,UFHFCIDOFF))
            		if (UCBITCHK(Gopt2,GOPT2NOCID))
    	    			uerrmsg("CID Off(type %s) for this file,default is Off",
//      						"CID 機能はオフ(%sタイプ).(省略時値オフ)",//~v095R~
        						"CID 機\x94\\はオフ(%sタイプ).(省略時値オフ)",//~v095I~
								pc);
					else
    	    			uerrmsg("CID Off(type %s) for this file,default is On",
//      						"CID 機能はオフ(%sタイプ).(省略時値オン)",//~v095R~
        						"CID 機\x94\\はオフ(%sタイプ).(省略時値オン)",//~v095I~
								pc);
				else	//not off
            		if (UCBITCHK(pfh->UFHflag,UFHFCIDON))
                		if (UCBITCHK(Gopt2,GOPT2NOCID))
        	    			uerrmsg("CID On(type %s) for this file,default is Off",
//          						"CID 機能はオン(%sタイプ).(省略時値オフ)",//~v095R~
            						"CID 機\x94\\はオン(%sタイプ).(省略時値オフ)",//~v095R~
    								pc);
    					else
        	    			uerrmsg("CID On(type %s) for this file,default is On",
//          						"CID 機能はオン(%sタイプ).(省略時値オン)",//~v095R~
            						"CID 機\x94\\はオン(%sタイプ).(省略時値オン)",//~v095I~
    								pc);
					else
                      if (pfh->UFHcidtype==UFHCIDTYPEERR)          //~v09rI~
                	   if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))       //~v10dI~
        	    		uerrmsg("CID Off for bynary file",         //~v10dI~
            					"CID はバイナリーファイルには設定されません");//~v10dI~
                       else                                        //~v10dI~
        	    		uerrmsg("CID Off for this file by ext-name or NONE parm",//~v0czR~
            					"CID 機\x94\\は拡張子名またはNONE指定によりオフ");//~v0czR~
                      else                                         //~v09rI~
                		if (UCBITCHK(Gopt2,GOPT2NOCID))
        	    			uerrmsg("CID Off(type %s) for this file by default",
//          						"CID 機能は省略時値によりオフ(%sタイプ)",//~v095R~
            						"CID 機\x94\\は省略時値によりオフ(%sタイプ)",//~v095I~
    								pc);
    					else
        	    			uerrmsg("CID On(type %s) for this file by default",
//          						"CID 機能は省略時値によりオン(%sタイプ)",//~v095R~
            						"CID 機\x94\\は省略時値によりオン(%sタイプ)",//~v095I~
    								pc);
        if (UCBITCHK(pfh->UFHflag9,UFHF9CIDAPPEND))                //~v79UR~
            uerrmsgcat("(APPEND mode)",0);                         //~v79UI~
        else                                                       //~v79UI~
        if (UCBITCHK(pfh->UFHflag9,UFHF9CIDAPPENDN))               //~v79UI~
            uerrmsgcat("(Not APPEND mode)",0);                     //~v79UI~
        else                                                       //~v79UI~
        if (UCBITCHK(Gopt5,GOPT5CIDAPPEND))                        //~v79UI~
            uerrmsgcat("(APPEND mode by default)",0);              //~v79UI~
        else                                                       //~v79UI~
            uerrmsgcat("(Not APPEND mode by default)",0);          //~v79UR~
//              UCBITON(Ppcw->UCWflag,UCWFDRAW);  //full redraw    //~v0buR~
#ifdef UTF8SUPPH                                                   //~va1qI~
        if (UCBITCHK(Goptopt2,GOPT2_CIDCOPY))                      //~va02I~
            uerrmsgcat(",copyon",0);                               //~va02I~
        else                                                       //~va02I~
            uerrmsgcat(",copyoff",0);                              //~va02I~
#endif                                                             //~va1qI~
	return 0;                                                      //~v0eAI~
}//fcmdcidhelp                                                     //~v0eAI~

//***********************************************               //~v033I~
//*!set scroll size ******************************              //~v033I~
//*parm1 :client work element                  *                //~v033I~
//*return:rc                                                    //~v033I~
//***********************************************               //~v033I~
int func_setscroll(PUCLIENTWE Ppcw)                             //~v033I~
{                                                               //~v033I~
	int opdno;                                                  //~v033R~
    int value;                                                  //~v033I~
	char *wkbuff;                                               //~v033I~
//****************************                                  //~v033I~
    if (!(wkbuff=Ppcw->UCWparm)) //input on cmdline set by funccall//~v033I~
        return errmissing();                                    //~v033I~
	strupr(wkbuff);                                             //~v033I~
    UPARSERC(wkbuff,wkbuff,&opdno,0,","); //parse out,accept cr/lf//~v04dR~
    if (opdno!=1)	//single operand                            //~v033I~
    	return errtoomany();                                    //~v033R~
	if (!(value=filechkscrollopd(wkbuff))                       //~v033R~
    ||  value>9999)                                             //~v033I~
    	return errinvalid(wkbuff);                              //~v033I~
	return filesetscrollsz(Ppcw,wkbuff);	//set to scroll fld //~v033I~
}//func_setscroll                                               //~v033I~
                                                                //~v069I~
//**************************************************************** //~v504I~
// func_renum                                                      //~v504R~
//*rc   :0                                                         //~v504I~
//**************************************************************** //~v504I~
int func_renum(PUCLIENTWE Ppcw)                                    //~v504I~
{                                                                  //~v504I~
	int rc,opdno;                                                  //~v504R~
	char *pc;                                                      //~v504I~
//*********************************                                //~v504I~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v504I~
    pc=Ppcw->UCWopdpot;                                            //~v504I~
	if (opdno>0 && *pc=='?')		//operand                      //~v504R~
    {                                                              //~v504I~
//      uerrmsg("REN [ F | K | ?]",0);                             //~v506R~
        uerrmsg("REN [ F | K | SETI | SETR | ?] [col1[-col2][delmchar|B|S]]",0);//~v506R~
        return 4;                                                  //~v504I~
    }                                                              //~v504I~
	Srenumcmdsw=1;                                                 //~v504I~
    rc=func_number(Ppcw);                                          //~v504I~
	Srenumcmdsw=0;                                                 //~v504I~
    return rc;                                                     //~v504I~
}//func_renum                                                      //~v504I~
//****************************************************************//~v069I~
// func_number                                                  //~v069I~
//*rc   :0                                                      //~v069I~
//****************************************************************//~v069I~
int func_number(PUCLIENTWE Ppcw)                                //~v069I~
{                                                               //~v069I~
    int ii,jj,opdno,opid,resetsw=0;                                //~v074R~
    UCHAR linenosz=ULHLINENOSZ0;                                             //~v069I~//~vafcR~
	UCHAR *pc;                                                  //~v069I~
    PUFILEC pfc;                                                //~v069I~
    PUFILEH pfh;                                                   //~v10XI~
static UCHAR *Swordtbl="ON\0" "OFF\0" "RESET\0" "?\0" "RENUM\0" "XON\0" "XOFF\0"//~v40FR~
//                     "CLEAR\0";                                  //~v45uR~
//                     "CLEAR\0" "CUTOFF\0";                       //~v45xR~
//                     "CLEAR\0";                                  //~v53dR~
                       "CLEAR\0"                                   //~v53dI~
                       "SETI\0" "SETR\0"                           //~v53dI~
                       ;                                           //~v53dI~
    char typ[3][4];                                                //~v09gI~
//    int setversw=0;                                              //~v0crR~
//  PUFILEH pfh;                                                   //~v0ikR~
    int renumsw=0;                                                 //~v0csI~
//  int cutoffsw=0;                                                //~v45xR~
    int forceopt=0;                                                //~v506R~
    int xnumsw=0,prevxnumopt,xnumdefsw=0;                          //~v10XR~
    int col1,col2;                                                 //~v506R~
    UCHAR delmch;                                                  //~v506I~
    ULONG  numfld;                                                 //~v506I~
    int rc;                                                        //~v0cmI~
//*********************************                             //~v069I~
	pfc=Ppcw->UCWpfc;                                           //~v069I~
    pfh=pfc->UFCpfh;                                               //~v10XR~
	if (!(pc=Ppcw->UCWparm))		//operand                   //~v069I~
	if (!Srenumcmdsw)                                              //~v504R~
    {                                                              //~v11DI~
//      return errmissing();                                       //~v11DR~
//      uerrmsg("NUM { ON|OFF|RESET|RENUM|XON|XOFF|line-number-width|? } [s|f]",0);//~v420R~
//      uerrmsg("NUM { ON|OFF|RESET|RENUM|XON|XOFF|CLEAR|line-number-width|? } [s|f|c]",0);//~v420R~
//      uerrmsg("NUM { ON|OFF|RESET|RENUM|XON|XOFF|CLEAR|line-number-width|? } [s|f]",0);//~v47AR~
//      uerrmsg("NUM { ON|OFF|RESET|RENUM|XON|XOFF|CLEAR|line-number-width|? } [s|f|k]",0);//~v506R~
//      uerrmsg("NUM { ON|OFF|RENUM|XON|XOFF|CLEAR|line-number-width|? } [S|F|K|SETR|SETI] [col1[-col2][delmchar|B|S]]",0);//~v53dR~
        uerrmsg("NUM [ON|OFF|RENUM|XON|XOFF|CLEAR|line-number-width|?] [S|F|K] [SETR|SETI] [col1[-col2][delmchar|B|S]]",0);//~v53dI~
        return 4;                                                  //~v11DI~
    }                                                              //~v11DI~
// 	if (pfh->UFHtype==UFHTKFI)	//ke func ini file                 //~v0ifR~
//  	return fcmdinvalidfile();                                  //~v0ifR~
//*operand chk                                                  //~v069I~
//  UPARSERC(pc,pc,&opdno,0,",");	//parse out string(accept cr/lf)//~v0brR~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v0brI~
    pc=Ppcw->UCWopdpot;                                            //~v0brR~
	if (Srenumcmdsw)                                               //~v504I~
    {                                                              //~v504I~
    	ii=1;                                                      //~v504I~
        opdno++;                                                   //~v504I~
        renumsw=1;                                                 //~v504I~
//      forceopt=0;                                                //~v506R~
        forceopt|=RENUMOPT_RENUM;                                  //~v53dI~
    }                                                              //~v504I~
    else                                                           //~v504I~
    	ii=0;                                                      //~v504I~
    col1=1;     //default for the case fld not specified           //~v53dI~
    col2=Ppcw->UCWlinenosz-1;   //default for the case fld not specified//~v53dI~
    delmch='|';                                                    //~v53dI~
//  for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v504R~
    for (;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr    //~v504I~
	{                                                           //~v069I~
    	switch(ii)                                              //~v069I~
        {                                                       //~v069I~
        case 0:		//first opd                                 //~v069I~
 			switch(opid=wordtblisrch(pc,Swordtbl),opid)         //~v069I~
            {                                                   //~v069I~
        	case 0:	//err                                       //~v069I~
				if (!ISNUMSTR(pc))                              //~v069I~
	                return errinvalid(pc);                      //~v069I~
                jj=atoi(pc)+1;                                  //~v069R~
                if (jj>ULHLINENOSZ || jj<0)                     //~v069R~
	                return errinvalid(pc);                      //~v069I~
                linenosz=(UCHAR)jj;                             //~v069I~
                break;                                          //~v069I~
        	case 1:	//on                                        //~v069I~
                linenosz=ULHLINENOSZ;                           //~v069I~
                break;                                          //~v069I~
        	case 2:	//off                                       //~v069R~
                linenosz=ULHLINENOSZ0;                          //~v069R~
                break;                                          //~v069I~
        	case 3:	//reset                                        //~v074I~
        	case 5:	//renum                                        //~v0brI~
                renumsw=1;                                         //~v0csI~
//              forceopt=0;                                        //~v506R~
                forceopt|=RENUMOPT_RENUM;                          //~v53dI~
                break;                                             //~v074I~
        	case 4:	//?                                            //~v09gI~
                if(Glinenoszb==ULHLINENOSZ0)                       //~v09gI~
                    strcpy(typ[0],"OFF");                          //~v09gR~
                else                                               //~v09gI~
                    sprintf(typ[0],"%d",Glinenoszb-1);             //~v09gR~
                if(Glinenosze==ULHLINENOSZ0)                       //~v09gI~
                    strcpy(typ[1],"OFF");                          //~v09gR~
                else                                               //~v09gI~
                    sprintf(typ[1],"%d",Glinenosze-1);             //~v09gR~
                if(Glinenoszc==ULHLINENOSZ0)                       //~v09gI~
                    strcpy(typ[2],"OFF");                          //~v09gR~
                else                                               //~v09gI~
                    sprintf(typ[2],"%d",Glinenoszc-1);             //~v09gR~
        		uerrmsg("Default is %s(B), %s(E), %s(C)",          //~v09gR~
        				"省略値は %s(B), %s(E), %s(C)",            //~v09gR~
						typ[0],typ[1],typ[2]);                     //~v09gR~
                return 0;                                          //~v09gI~
//            case 6: //setver                                     //~v0crR~
//                setversw=1; //server id                          //~v0crR~
//                break;                                           //~v0crR~
              case 6: //xon                                        //~v10XI~
    			if (UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMERR|UFHF2SPFNUMOK))//~v177R~
					return fcmdinvalidforspf();                    //~v177R~
                strcpy(typ[0],"XON");                              //~v10XI~
            	if (UCBITCHK(pfh->UFHflag4,UFHF4XLINENO))          //~v10XR~
                	xnumsw=2;//already that status  	           //~v10XI~
                else                                               //~v10XI~
                {                                                  //~v10XI~
                  	xnumsw=1; //need file reset                    //~v10XI~
                 	UCBITON(pfh->UFHflag4,UFHF4XLINENO);           //~v10XI~
				}                                                  //~v10XI~
                  break;                                           //~v10XI~
              case 7: //xoff                                       //~v10XI~
                strcpy(typ[0],"XOFF");                             //~v10XI~
            	if (UCBITCHK(pfh->UFHflag4,UFHF4XLINENO))          //~v10XR~
                {                                                  //~v10XI~
                  	xnumsw=3; //need file reset                    //~v10XI~
                  	UCBITOFF(pfh->UFHflag4,UFHF4XLINENO);          //~v10XI~
				}                                                  //~v10XI~
                else                                               //~v10XI~
                  	xnumsw=4; //already off                        //~v10XI~
                  break;                                           //~v10XI~
        	case 8:	//clear                                        //~v40FI~
                renumsw=1;                                         //~v40FI~
                forceopt=RENUMOPT_CLEAR;                           //~v40FI~
                break;                                             //~v40FI~
//      	case 9:	//cutoff                                       //~v45xR~
//              cutoffsw=1;                                        //~v45xR~
//              break;                                             //~v45xR~
        	case 9:	//seti                                         //~v53dI~
                forceopt|=RENUMOPT_SETI;                           //~v53dI~
                break;                                             //~v53dI~
        	case 10:	//setr                                     //~v53dI~
                forceopt|=RENUMOPT_SETR;                           //~v53dI~
                break;                                             //~v53dI~
            }                                                   //~v069I~
            break;                                              //~v069I~
        default:                                                //~v069I~
//            if (setversw)                                        //~v0crR~
//            {                                                    //~v0crR~
//                if (*pc=='?')                                    //~v0crR~
//                    jj=-1;                                       //~v0crR~
//                else                                             //~v0crR~
//                {                                                //~v0crR~
//                    if (!ISNUMSTR(pc))                           //~v0crR~
//                        return errinvalid(pc);                   //~v0crR~
//                    jj=atoi(pc);                                 //~v0crR~
//                }                                                //~v0crR~
//                rc=fileresetver(Ppcw,pfh,jj);                    //~v0crR~
//                if (rc)                                          //~v0crR~
//                    return rc;                                   //~v0crR~
//                setversw=2; //processed                          //~v0crR~
//            }                                                    //~v0crR~
//            else                                                 //~v0crR~
            if (xnumsw && ii==1)                                   //~v10XI~
            {                                                      //~v10XI~
                if (toupper(*pc)!='S')                             //~v10XI~
                    return errinvalid(pc);                         //~v10XI~
            	prevxnumopt=UCBITCHK(Gopt4,GOPT4XLINENO);          //~v10XR~
                if ((xnumsw<=2 && prevxnumopt)  	//already on   //~v10XI~
                ||  (xnumsw>2 && !prevxnumopt))  //already off     //~v10XI~
                	uerrmsg("Default is already set so",           //~v10XI~
                    		"設定済みの省略値です");               //~v10XI~
				                                                   //~v10XI~
                else                                               //~v10XI~
                {                                                  //~v10XI~
                	xnumdefsw=1;                                   //~v10XI~
                	if (xnumsw<=2)                                 //~v10XI~
            			UCBITON(Gopt4,GOPT4XLINENO);               //~v10XR~
                    else                                           //~v10XI~
            			UCBITOFF(Gopt4,GOPT4XLINENO);              //~v10XR~
            		UCBITON(Gopt5,GOPT5XLINENOS); //changed by cmd //~v60kI~
                	uerrmsg("Default is reset to %s",              //~v10XI~
                    		"省略値を %s に設定",                  //~v10XI~
							typ[0]);                               //~v10XR~
                }                                                  //~v10XI~
            }                                                      //~v10XI~
            else                                                   //~v10XI~
//          if (renumsw && ii==1)                                  //~v47AR~
//          if (renumsw && ii<=2)                                  //~v506R~
            if (renumsw && ii==1)                                  //~v506I~
            {                                                      //~v0ctI~
                if (toupper(*pc)=='F')                             //~v0ctI~
//                  forceopt=1;                                    //~v40FR~
                    forceopt|=RENUMOPT_FORCE;                      //~v40FI~
				else                                               //~v0ctI~
//                if (toupper(*pc)=='C')  //cob                    //~v420R~
//                    if (forceopt==RENUMOPT_CLEAR)                //~v420R~
//                        forceopt|=(RENUMOPT_FORCE|RENUMOPT_COB); //~v420R~
//                    else                                         //~v420R~
//                    {                                            //~v420R~
//                        uerrmsg("option Cob is valid with CLEAR option",//~v420R~
//                                "Cob オプションは CLEARの時のみ有効");//~v420R~
//                        return 4;                                //~v420R~
//                    }                                            //~v420R~
//                else                                             //~v420R~
                if (toupper(*pc)=='K')  //cob                      //~v47AR~
                    forceopt|=RENUMOPT_COBK;                       //~v47AR~
                else                                               //~v47AI~
//              if (!stricmp(pc,"SETI"))                           //~v53dR~
                if (!stricmp(pc,"SETI") && (forceopt & RENUMOPT_RENUM))//~v53dI~
                    forceopt|=RENUMOPT_SETI;                       //~v506I~
                else                                               //~v506I~
//              if (!stricmp(pc,"SETR"))                           //~v53dR~
                if (!stricmp(pc,"SETR") && (forceopt & RENUMOPT_RENUM))//~v53dI~
                    forceopt|=RENUMOPT_SETR;                       //~v506I~
                else                                               //~v506I~
                    return errinvalid(pc);                         //~v0ctI~
//              col1=1; 	//default for the case fld not specified//~v53dR~
//              col2=Ppcw->UCWlinenosz-1; 	//default for the case fld not specified//~v53dR~
//              delmch='|';                                        //~v53dR~
            }                                                      //~v0ctI~
            else                                                   //~v0ctI~
//          if (ii==2 && (forceopt & (RENUMOPT_SETI|RENUMOPT_SETR)))//~v53dR~
            if ((forceopt & (RENUMOPT_SETI|RENUMOPT_SETR))         //~v53dI~
            &&  (  ((forceopt & RENUMOPT_RENUM) && ii==2) //with renum//~v53dI~
                ||!((forceopt & RENUMOPT_RENUM) && ii==1) //without renum//~v53dI~
                ))                                                 //~v53dI~
            {                                                      //~v506I~
				if (fcmdgetrenumsetfld(Ppcw,pc,&col1,&col2,&delmch))//~v506I~
                	return 4;                                      //~v506I~
            }                                                      //~v506I~
            else                                                   //~v506I~
        	return errtoomany();                                //~v069I~
		}//sw by opd no                                         //~v069I~
	}//loop by operand no                                       //~v069I~
                                                                   //~v10XI~
    if (xnumsw)                                                    //~v10XR~
    {                                                              //~v10XI~
    	if (xnumsw==1||xnumsw==3) //file is to be reset            //~v10XR~
			UCBITON(Ppcw->UCWflag,UCWFDRAW);  //full redraw        //~v10XI~
		if (!xnumdefsw)	//no default chnage msg                    //~v10XI~
        {                                                          //~v53dI~
	    	if (xnumsw==1||xnumsw==3) //file is reset              //~v10XI~
            {                                                      //~v173I~
				fcmdnumajustlinenosz(Ppcw,pfh,0);//ajust lineno    //~v173I~
                                                                   //~v173I~
            	uerrmsg("Reset to %s",                             //~v10XI~
                    	"%s に設定",                               //~v10XI~
							typ[0]);                               //~v10XI~
            }                                                      //~v173I~
            else                                                   //~v10XI~
            	uerrmsg("Already set so",                          //~v10XI~
                    	"すでに設定済み");                         //~v10XI~
        }                                                          //~v53dI~
        return 0;                                                  //~v10XI~
    }                                                              //~v10XI~
                                                                   //~v10XI~
//    if  (setversw==1)                                            //~v0crR~
//        return fileresetver(Ppcw,pfh,-1);                        //~v0crR~
//*process                                                      //~v069I~
//    if (!resetsw && !setversw)  //not reset and not setver       //~v0crR~
//  if  (renumsw)                                                  //~v53dR~
    if  (renumsw                                                   //~v53dI~
    ||   (forceopt & (RENUMOPT_SETI|RENUMOPT_SETR)))               //~v53dI~
    {                                                              //~v0csI~
		if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                     //~v40CI~
			return errbrowsemode();                                //~v40CI~
        numfld=(ULONG)(((col1&255)<<16)+((col2&255)<<8)+(delmch&255));//~v53dR~
//      rc=filerenum(Ppcw,pfc->UFCpfh,forceopt);                   //~v506R~
        rc=filerenum(Ppcw,pfc->UFCpfh,forceopt,numfld);            //~v506I~
      if (!(forceopt & (RENUMOPT_SETI|RENUMOPT_SETR)))             //~v506R~
      {                                                            //~v506I~
		fcmdnumajustlinenosz(Ppcw,pfh,0);//ajust lineno            //~v173I~
		fileinitialleft(pfc,pfh);       //cobol initial fcleft     //~v41oI~
      }                                                            //~v506I~
        UCBITON(Ppcw->UCWflag,UCWFDRAW);  //full redraw            //~v47AI~
        return rc;                                                 //~v0csI~
    }                                                              //~v0csI~
//  if  (cutoffsw)                                                 //~v45xR~
//  {                                                              //~v45xR~
//  	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                     //~v45xR~
//      	return errbrowsemode();                                //~v45xR~
//      rc=filecutoff(Ppcw,pfc->UFCpfh);                           //~v45xR~
//      return rc;                                                 //~v45xR~
//  }                                                              //~v45xR~
    if (!resetsw) //not reset and not setver                       //~v0crI~
    {                                                              //~v074I~
  if (Ppcw->UCWmenuopt==PANMOCMD)                                     //~v06yR~
    	pc=&Glinenoszc;	//browse screen                         //~v069I~
  else                                                          //~v069I~
	if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                      //~v069R~
    	pc=&Glinenoszb;	//browse screen                         //~v069I~
	else                                                        //~v069I~
    	pc=&Glinenosze;   //edit screen                         //~v069I~
    if (linenosz==Ppcw->UCWlinenosz)                            //~v069I~
    {                                                              //~v53dI~
      if (linenosz!=*pc)    //differnt from default                //~v09gI~
      {                                                            //~v09gI~
        if(linenosz==ULHLINENOSZ0)                                 //~v09gI~
            strcpy(typ[0],"OFF");                                  //~v09gI~
        else                                                       //~v09gI~
            sprintf(typ[0],"%d",linenosz-1);                       //~v09gI~
		uerrmsg("Default set to %s",                               //~v09gR~
				"省略値を %s に設定",                              //~v09gR~
				typ[0]);                                           //~v09gR~
		*pc=linenosz;	  //edit screen                            //~v09gI~
        return 0;                                                  //~v09gI~
      }                                                            //~v09gI~
      else                                                         //~v09gI~
    	return erralready();                                    //~v069R~
    }                                                              //~v53dI~
    Ppcw->UCWlinenosz=*pc=linenosz;	  //edit screen             //~v069R~
	fileufldinit(Ppcw);	//ajust ufld                            //~v069I~
//  if (pfc->UFCleft+Ppcw->UCWwidth-linenosz>MAXLINEDATA)          //~v0avR~
//  	pfc->UFCleft=MAXLINEDATA-(Ppcw->UCWwidth-linenosz)+1;      //~v0avR~
	}//not reset subcmd                                            //~v074I~
	UCBITON(Ppcw->UCWflag,UCWFDRAW);  //full redraw             //~v069R~
	return 0;                                                   //~v069I~
}//func_number                                                  //~v069I~
                                                                //~v069I~
//**************************************************************** //~v506I~
// fcmdgetrenumsetfld                                              //~v506I~
//*  get num fld column range and delm char from parm for SETI/SETR option//~v506I~
//*rc   :4:err                                                     //~v506I~
//**************************************************************** //~v506I~
int fcmdgetrenumsetfld(PUCLIENTWE Ppcw,char *Pdata,int *Ppcol1,int *Ppcol2,UCHAR *Ppdelmch)//~v506R~
{                                                                  //~v506I~
	int rc,col1,col2;                                              //~v506R~
    char *pc,ch;                                                   //~v506R~
//**********************************************                   //~v506I~
//  rc=tc_getnumrange(Pdata,&col1,&col2,&pc); //1:col1 only;err if col1=0//~v62pR~
    rc=ugetnumrange3(Pdata,&col1,&col2,&pc); //1:col1 only;err if col1=0//~v62pI~
    if (rc>1)                                                      //~v506I~
    	return errinvalid(Pdata);                                  //~v506I~
    ch=(char)toupper(*pc);                                         //~v53dR~
    if (ch=='S'||ch=='B')                                          //~v506I~
		*Ppdelmch=' ';                                             //~v506R~
    else                                                           //~v506I~
    if (ch=='\"'||ch=='\'')                                        //~v506R~
		*Ppdelmch=*(pc+1);                                         //~v506R~
    else                                                           //~v506I~
		*Ppdelmch=*pc;                                             //~v506I~
    if (rc==1)                                                     //~v506I~
	    col2=col1+Ppcw->UCWlinenosz-1;                             //~v506R~
    if (col1>=256                                                  //~v506R~
	||  col2>=256   //should be 1 byte                             //~v506I~
	||  col1==col2)                                                //~v506I~
    	return errinvalid(Pdata);                                  //~v506I~
    *Ppcol1=col1;                                                  //~v506I~
    *Ppcol2=col2;                                                  //~v506I~
    return 0;                                                      //~v506I~
}//fcmdgetrenumsetfld                                              //~v506I~
//**************************************************************** //~v173I~
// fcmdnumajustlinenosz                                            //~v173I~
//*opt  :0:no change if redused, 1:back to default,2:reduce size   //~v177R~
//*rc   :0,1:linenosz changed,4:line count=0                       //~v173I~
//**************************************************************** //~v173I~
int fcmdnumajustlinenosz(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt)    //~v173I~
{                                                                  //~v173I~
	int linenosz,oldsz;                                            //~v173I~
    PUFILEC pfc;                                                   //~v173I~
//**********************************************                   //~v173I~
	pfc=Ppcw->UCWpfc;                                              //~v173I~
	linenosz=filecalclinenosz(Ppfh);                               //~v173I~
    if (!linenosz)     //line count=0 case?                        //~v173I~
    	return 4;                                                  //~v173I~
    oldsz=(int)Ppcw->UCWlinenosz;                                  //~v173R~
    if (linenosz<oldsz)		//back to default                      //~v173I~
    {                                                              //~v53dI~
    	if (!Popt)                                                 //~v177R~
        	linenosz=oldsz;		//no change                        //~v177I~
        else                                                       //~v177I~
        if (Popt==1)       //back to default                       //~v177R~
        {                                                          //~v173I~
            if (Ppcw->UCWmenuopt==PANMOCMD)                        //~v173I~
                linenosz=Glinenoszc;    //browse screen            //~v173I~
            else                                                   //~v173I~
                if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))             //~v173I~
                    linenosz=Glinenoszb;    //browse screen        //~v173I~
                else                                               //~v173I~
                    linenosz=Glinenosze;   //edit screen           //~v173I~
        }                                                          //~v173I~
    }                                                              //~v53dI~
    if (linenosz==oldsz)                                           //~v173I~
    	return 0;                                                  //~v173I~
    Ppcw->UCWlinenosz=(char)linenosz;                              //~v173I~
	fileufldinit(Ppcw);	//ajust ufld                               //~v72fI~
    return 1;  			//value changed                            //~v173I~
}//fcmdnumajustlinenosz                                            //~v173I~
//**************************************************************** //~v0crI~
// func_version                                                    //~v0crI~
//*rc   :0                                                         //~v0crI~
//**************************************************************** //~v0crI~
int func_version(PUCLIENTWE Ppcw)                                  //~v0crI~
{                                                                  //~v0crI~
    int ii,ver=0,opdno;                                              //~v0crR~//~va8kR~
    int rc;                                                        //~v0crI~
    char *pc;                                                      //~v0crI~
    PUFILEC pfc;                                                   //~v0crI~
    PUFILEH pfh;                                                   //~v0crI~
//*********************************                                //~v0crI~
	pfc=Ppcw->UCWpfc;                                              //~v0crI~
    pfh=pfc->UFCpfh;                                               //~v0crI~
	if (!(pc=Ppcw->UCWparm))		//operand                      //~v0crI~
        return fileresetver(Ppcw,pfh,-1);	//display              //~v0crI~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v0crI~
    pc=Ppcw->UCWopdpot;                                            //~v0crI~
                                                                   //~v0crI~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v0crI~
	{                                                              //~v0crI~
    	switch(ii)                                                 //~v0crI~
        {                                                          //~v0crI~
        case 0:		//first opd                                    //~v0crI~
            if (*pc=='?')                                          //~v0crI~
                ver=-1;                                            //~v0crR~
            else                                                   //~v0crI~
            {                                                      //~v0crI~
                if (!ISNUMSTR(pc))                                 //~v0crI~
                    return errinvalid(pc);                         //~v0crI~
                ver=atoi(pc);                                      //~v0crR~
            }                                                      //~v0crI~
            break;                                                 //~v0crI~
        default:                                                   //~v0crI~
        	return errtoomany();                                   //~v0crI~
		}//sw by opd no                                            //~v0crI~
	}//loop by operand no                                          //~v0crI~
    rc=fileresetver(Ppcw,pfh,ver);                                 //~v0crI~
    return rc;                                                     //~v0crI~
}//func_version                                                    //~v0crI~
                                                                   //~v0crI~
//**************************************************************** //~v0hqI~
// func_drop_file                                                  //~v0hqI~
//*rc   :0                                                         //~v0hqI~
//**************************************************************** //~v0hqI~
int func_drop_file(PUCLIENTWE Ppcw)                                //~v0hqI~
{                                                                  //~v0hqI~
    PUFILEC pfc;                                                   //~v0hqI~
    PUFILEH pfh;                                                   //~v0hqI~
    int ii,opdno,opid;                                             //~v0huR~
	UCHAR *pc;                                                     //~v0hqI~
static UCHAR *Swordtbl="X\0" "NX\0" "ALL\0" "REP\0";               //~v40KR~
	int allsw=0,funcid=0,repsw=0;                                  //~v40KR~
    int lblcnt=0;                                                  //~v0icR~
    UCHAR labelt[2][ULHLINENOSZ+1];                                //~v0icI~
    PULINEH plht[2];			//output of lcmdgetabplh           //~v0icI~
    int rc;                                                        //~v0hqI~
//*********************************                                //~v0hqI~
    if (!(Ppcw->UCWparm))       //operand                          //~v11mI~
    {                                                              //~v11mI~
//      uerrmsg("DRO { x | nx } [rep] { all | .lab1 .lab2 }",0);   //~v503R~
        uerrmsg("{DRO|DEL} { x | nx } [rep] { all | .lab1 .lab2 }",0);//~v503I~
        return 4;                                                  //~v11mI~
    }                                                              //~v11mI~
	pfc=Ppcw->UCWpfc;                                              //~v0hqI~
    if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))                         //~v0huM~
		return errbrowsemode();                                    //~v0huM~
//    if (!(Ppcw->UCWparm))       //operand                        //~v11mR~
//        return errmissing();                                     //~v11mR~
    pfh=pfc->UFCpfh;                                               //~v0hqI~
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~v0hqI~
    pc=Ppcw->UCWopdpot;                                            //~v0hqI~
//  if (opdno>2)                                                   //~v0icR~
    if (opdno>3)                                                   //~v0icI~
        return errtoomany();                                       //~v0huI~
    if (opdno<2)                                                   //~v0huI~
        return errmissing();                                       //~v0huI~
	for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~v0hqI~
	{                                                              //~v0hqI~
      if (*pc==ULCCMDLABEL)    //start by '.'                      //~v0icR~
      {                                                            //~v0icI~
      	if (lblcnt>=2)                                             //~v0icI~
        	return fcmdlabelerr(pc);                               //~v0icI~
        strncpy(labelt[lblcnt],pc,ULHLINENOSZ);                    //~v0icI~
        labelt[lblcnt][ULHLINENOSZ]=0;                             //~v0icR~
        lblcnt++;                                                  //~v0icR~
      }                                                            //~v0icI~
      else                                                         //~v0icI~
      {                                                            //~v0icI~
        opid=wordtblisrch(pc,Swordtbl);                            //~v0huI~
    	switch(opid)                                               //~v0huI~
        {                                                          //~v0huI~
        case 0: //err                                              //~v0huI~
            return errinvalid(pc);                                 //~v0huI~
        case 1: //x                                                //~v0huI~
        	funcid=1;                                              //~v0huR~
            break;                                                 //~v0huI~
        case 2: //nx                                               //~v0huI~
        	funcid=2;                                              //~v0huR~
            break;                                                 //~v0huI~
        case 3: //all                                              //~v0huI~
        	allsw=1;                                               //~v0huI~
            break;                                                 //~v0huI~
        case 4: //rep                                              //~v40KR~
        	repsw=1;                                               //~v40FI~
            break;                                                 //~v40FI~
        }                                                          //~v0huI~
      }//not label                                                 //~v0icI~
	}//loop by operand no                                          //~v0hqI~
                                                                   //~v0icI~
	if (lblcnt&1)	//odd number                                   //~v0icR~
    	return fcmdlabelerr("Need From/To");                       //~v0icI~
	if (allsw && lblcnt)	//odd number                           //~v0icR~
    	return fcmdlabelerr("All and label is mixed");             //~v0icI~
//  if (!allsw || !funcid)                                         //~v0icR~
    if ((!allsw && !lblcnt) || !funcid)                            //~v0icR~
        return errmissing();                                       //~v0huI~
//  if (rc=fcmdgetlabelrange(pfh,lblcnt,labelt,plht),rc)           //~v165R~
    if (rc=fcmdgetlabelrange(pfh,lblcnt,labelt,plht,1),rc)         //~v165I~
		return rc;                                                 //~v0icI~
    if (repsw)                                                     //~v40KR~
    	funcid|=DFOPT_REP;                                         //~v40KR~
    rc=filedrop(Ppcw,pfh,funcid,plht[0],plht[1]);                  //~v0icR~
	return rc;                                                     //~v0hqI~
}//func_drop_file                                                  //~v0hqI~
                                                                   //~v0hqI~
//**************************************************************** //~v0icI~
// fcmdgetlabelrange                                               //~v0icI~
// 2 label range search                                            //~v0icI~
//*parm1:pfh                                                       //~v0icI~
//*parm2:label ctr(0 or 2)                                         //~v0icI~
//*parm3:label table                                               //~v0icI~
//*parm4:output plh table(first and next of last)                  //~v0icI~
//*parm5:option 1:from drop(set next of end plh)                   //~v165I~
//*rc   :4:err,2:err same as previous label                        //~v0icI~
//**************************************************************** //~v0icI~
int fcmdgetlabelrange(PUFILEH Ppfh,int Plabctr,                    //~v0icI~
			UCHAR Plabelt[][ULHLINENOSZ+1],PULINEH *Pplht,int Popt)//~v165R~
{                                                                  //~v0icI~
static UCHAR Slabold[2][ULHLINENOSZ+1];//to bell once at changed   //~v0icI~
    int ii,rc;                                                     //~v0icI~
    int sortseq[2];				//output of lcmdgetabplh           //~v0icI~
    PULINEH plh;                                                   //~v0icI~
    UCHAR editwk[ULHLINENOSZ+32];                                  //~v0icI~
//*******************                                              //~v0icI~
    if (!Plabctr)			//no label                             //~v0icI~
    {                                                              //~v0icI~
        Pplht[0]=0;                                                //~v0icI~
        Pplht[1]=0;                                                //~v0icI~
        Slabold[0][0]=0;                                           //~v0icI~
        return 0;                                                  //~v0icI~
    }                                                              //~v0icI~
//  if (lcmdgetabplh(Ppfh,2,Plabelt,Pplht,sortseq))                //~v47cR~
    if (rc=lcmdgetabplh(Ppfh,2,Plabelt,Pplht,sortseq),rc)          //~v47cR~
    {                                                              //~v0icI~
        for (ii=0;ii<2;ii++)                                       //~v0icI~
            if (!sortseq[ii])   //0 if label not found             //~v0icI~
                break;                                             //~v0icI~
        if (ii<2)                                                  //~v0icI~
            strcpy(editwk,Plabelt[ii]);                            //~v0icI~
        else                                                       //~v0icI~
            *editwk=0;                                             //~v0icI~
      if (rc==5)		//dup label                                //~v47cR~
        	strcat(editwk," is duplicated");                       //~v47cR~
      else                                                         //~v47cR~
        strcat(editwk," not found");                               //~v0icI~
        fcmdlabelerr(editwk);                                      //~v0icI~
      if (rc!=5)                                                   //~v47cR~
      {                                                            //~v53dI~
        if (memcmp(Plabelt,Slabold,sizeof(Slabold)))               //~v0icI~
	       	rc=4;                                                  //~v0icI~
    	else                                                       //~v0icI~
        	rc=2;          //skip bell                             //~v0icI~
      }                                                            //~v53dI~
        memcpy(Slabold,Plabelt,sizeof(Slabold));//save err label   //~v0icR~
        return rc;                                                 //~v0icI~
    }                                                              //~v0icI~
//set which is start and end                                       //~v0icI~
    if (sortseq[0]>sortseq[1]) //plh1>plh2                         //~v0icR~
    {                                                              //~v0icI~
        plh=Pplht[0];                                              //~v0icI~
        Pplht[0]=Pplht[1];                                         //~v0icI~
        Pplht[1]=plh;                                              //~v0icI~
    }                                                              //~v0icI~
//*set end line                                                    //~v0icI~
  if (Popt==1)	//from drop cmd                                    //~v165I~
    if (Pplht[1]->ULHtype!=ULHTHDR)                                //~v0icI~
        Pplht[1]=getdisplayline(Pplht[1],1,0);//next display line  //~v0icI~
    Slabold[0][0]=0;                                               //~v0icI~
    return 0;                                                      //~v0icI~
}//fcmdgetlabelrange                                               //~v0icI~
//**************************************************************** //~v09FI~
// postfix err                                                     //~v09FI~
//*rc   :4                                                         //~v09FI~
//**************************************************************** //~v09FI~
int fcmdpostfixlenerr(char *Ppostfix)                              //~v09FI~
{                                                                  //~v09FI~
	uerrmsg("%s is too long postfix",                              //~v09FI~
			"%s は 長過ぎます(後置文字は最大2バイト)",             //~v09FI~
			Ppostfix);                                             //~v09FI~
	return 4;                                                      //~v09FI~
}//fcmdpostfixlenerr                                               //~v09FI~
//**************************************************************** //~v0ifI~
// file type err                                                   //~v0ifI~
//*rc   :4                                                         //~v0ifI~
//**************************************************************** //~v0ifI~
int fcmdinvalidfile(void)                                          //~v0ifI~
{                                                                  //~v0ifI~
	uerrmsg("Invalid cmd for this file",                           //~v0ifI~
    		"このファイルには無効なコマンドです");                 //~v0ifR~
    return 4;                                                      //~v0ifI~
}//fcmdinvalidfile                                                 //~v0ifI~
//**************************************************************** //~v10dI~
// file type err                                                   //~v10dI~
//*rc   :4                                                         //~v10dI~
//**************************************************************** //~v10dI~
int fcmdinvalidbinfile(void)                                       //~v10dI~
{                                                                  //~v10dI~
	uerrmsg("Invalid cmd for binary file",                         //~v10dI~
    		"バイナリーファイルには無効です");                     //~v10dI~
    return 4;                                                      //~v10dI~
}//fcmdinvalidfile                                                 //~v10dI~
//**************************************************************** //~v177I~
// invalid for spf file                                            //~v177I~
//*rc   :4                                                         //~v177I~
//**************************************************************** //~v177I~
int fcmdinvalidforspf(void)                                        //~v177I~
{                                                                  //~v177I~
    uerrmsg("It's Numbered-Line-File",                             //~v177I~
            "行番付きファイルです");                               //~v177I~
    return 4;                                                      //~v177I~
}//fcmdinvalidforspf                                               //~v177I~
