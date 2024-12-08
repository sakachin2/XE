//*CID://+vbAtR~:                             update#=  727;       //+vbAtR~
//*************************************************************
//*xefcmd25.c                                                      //~v73dR~
//*  find/change/exclude                                           //~v11kR~
//****************************************************************////~v438R~
//vbAt:240704 (Bug)find -cont should be used in exe cmd file. If not save plh pos may cause 0c4//+vbAtI~
//vbzx:240307 Find cmd;add option "next2, start pos is same as previous failed next cmd for performance of "exe" cmd by sorted find word.//~vbzxI~
//            ==>nevertheless found or not found, start pos is from topline of the page. So performance gain is not so large. effective when continued not found with large following line.//~vbzxI~
//vbc2:170821 add TS   option for find cmd on dirlist              //~vbc2I~
//vbc1:170820 add ATTR option for find cmd on dirlist              //~vbc1I~
//vb86:170216 display cmdline ctr excluded(fcmd:x,xx; lcmd x)      //~vb86I~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vaza:150111 (BUG of vauG)F5/S+F5 cut 2 byte from end of search word//~vazaI~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//vax1:140625 (BUG:Win)find ucs2 failes(searchs ucs4)              //~vax1I~
//vaw4:140528 (Win:UNICODE)escsrch by 3byte unicode                //~vaw4I~
//vavu:140428 (BUG)0c4 by rfind on filename list panel.rc=0 but Sfindplh=0 because of async schedule//~vavuI~
//vauG:140316 (BUG)rfind(f5) misses utf8 code when searchword on cmdline.//~vauGI~
//vaga:120823 (BUG)"F *u" cmd loop by Sstep=0,Rfind faile by "enter Find cmd at first" ;//~vagaI~
//            previous "F *\n"  set *Ssrch=0 and "F *u" cmd dose not set Ssrch.//~vagaI~
//            And Sstep=strlen(Ssrch)                              //~vagaI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//va7b:100817 (BUG)and search on ebc file,rfind on next session faile by "no ebcdic data";//~va7bI~
//            (utf8 data was not saved for Sescsrchachar2)         //~va7bI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3E:100313 (BUG)search on utf8 file(ddstr) fail near the line top//~va3EI~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1G:091118 (UTF8)add UTF8 trans err char Find/Change function   //~va1GI~
//va1v:091109_Find U8 simplely searchs L2f string                  //~va1vI~
//va1q:091107 compchkm                                             //~va1qI~
//va1g:091102_Find cmd;search word code is depend not on env(LANG) but kbd mode(A+u)//~va1gI~
//va0y:090920_add UTF8 to Unicode find option  U[B|L|8] (Big/Little Endian/utf8)//~va0yI~
//va0c:090711 Unicode find option  U[B|L] (Big/Little Endian,default is OS endian)//~va0cI~
//v79L:081020 change cmd support P'..' fmt as target string specification(=(same),<(lower),>(upper) is special char)//~v79LR~
//v78q:080322 REGEXSUPP for win/lnx                                //~v78qI~
//v78d:080308 screen grep support                                  //~v78dI~
//v73d:070111*split fcmd2 to fcmd25 fcmd26                         //~v73dI~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ualloc.h>                                             //~5318I~

//*******************************************************
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <uparse.h>                                                //~v0b2R~
#include <ustring.h>                                               //~v0b2I~
#include <ufile.h>                                              //~5318R~
#include <uedit.h>                                                 //~v09LI~
#include <utrace.h>                                                //~v11nI~
#ifdef UTF8SUPPH                                                   //~va0cI~
	#include <ucvucs.h>                                            //~va0cI~
	#include <utf.h>                                               //~va0cI~
	#include <utf22.h>                                             //~va20I~
#endif                                                             //~va0cI~
                                                                //~5318I~
#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefile.h"
#include "xefile2.h"                                               //~v0avI~
#include "xefile3.h"                                            //~v013I~
#include "xefile42.h"                                              //~v0bvR~
#include "xefile6.h"                                               //~v0avI~
#include "xedir.h"                                              //~v05wI~
#include "xedir2.h"                                                //~v481I~
#include "xedir3.h"                                                //~v182R~
#include "xechar.h"                                             //~5124I~
#include "xechar12.h"                                              //~v0dvI~
#include "xelcmd.h"
#include "xelcmd2.h"
#include "xelcmd4.h"       //join                                  //~v539I~
#include "xefcmd2.h"
#include "xefcmd22.h"                                              //~v0ewI~
#include "xefcmd23.h"                                              //~v13pI~
#include "xefcmd24.h"	//x =all                                   //~v40pI~
#include "xefcmd27.h"	//x =all                                   //~v78dI~
#include "xefcmd5.h"	//x =all                                   //~v50vI~
#include "xefunc.h"
#include "xefunc2.h"  	//funccmdstack                             //~v0hdI~
#include "xefunct.h"                                               //~v09dI~
#include "xeundo.h"                                             //~5106I~
#include "xesub.h"                                              //~5318R~
#include "xefsub.h"                                             //~5318I~
#include "xeerr.h"                                              //~v033I~
#ifdef UTF8SUPPH                                                   //~va0cI~
	#include "xeutf.h"                                             //~va0cI~
#endif                                                             //~va0cI~
//*******************************************************
//*******************************************************          //~v09II~
int linesrchstring(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Plocatesw,//~v73dI~
					int Pchangeopt,int Psubcmdid);                 //~v73dI~
//**************************************************************** //~v73dI~
//int operandchk(PUCLIENTWE Ppcw,UCHAR *Popd,int Pchangeopt,int Pbackward);//~v78dR~
int operandchk(PUCLIENTWE Ppcw,UCHAR *Popd,int Pchangeopt,int Pbackward,int Pcasesw);//~v78dI~
//**************************************************************** //~v73dI~
int fcmdesctabchk(int Popt,PUFILEH Ppfh,UCHAR *Pstring,int Plen);  //~v73dI~
//**************************************************************** //~va0cI~
#ifdef UTF8SUPPH                                                   //~va1qI~
int fcmdgetescsrchword(int Popt,PUCLIENTWE Ppcw,char *Psrch,UCHAR *Pescsrch,int *Ppsrchlen,UCHAR *Ppscsrchlen);//~va0cR~
#endif                                                             //~va1qI~
void fcmd_execfindcmd(PUCLIENTWE Ppcw,int Pparmoffs,int Pcmdlen,int Poffstail);//~vauGR~
//***********************                                          //~vbzxI~
static PULINEH SnextStartplh;                                      //~vbzxR~
static int SnextStartoffset;                                       //~vbzxR~
//****************************************************************
//!fcmdrfind
//*rfind command(repeat find)
//*parm1 :pcw
//*parm2 :reverse option(0:no change direction,1:reverse search direction)//~5302R~
//*parm3 :change option                                         //~5106I~
//*rc   :0
//****************************************************************
int fcmdrfind(PUCLIENTWE Ppcw,int Preverse,int Pchangeopt)      //~5302R~
{
#ifdef AAA                                                         //~vbCBM~
static  FUNCTBL *Spfti=0,*Spftf=0,*Spftc=0;                        //~v437R~
#else                                                              //~vbCBI~
static  FUNCTBL *Spfti=0,*Spftc=0;                                 //~vbCBI~
	FUNCTBL *pft;                                                  //~vbCBI~
    char wkcmd[sizeof(pft->FTcmd)];                                //~vbCBI~
#endif                                                             //~vbCBI~
static  UCHAR   *Scprev=" PreV";                                   //~v10VR~
	PULINEH plh=0;                                                 //~vaf9R~
	PULINEH plhw;                                                  //~v0hHI~
	PUFILEH pfh;                                                   //~v09cI~
	PUFILEC pfc;                                                   //~v09cI~
//  FUNCTBL *pft;                                                  //~v0hdR~
	int offset,rc;                                              //~5302R~
    int len;                                                       //~v0hdR~
    int expandlen;                                                 //~v59TI~
    UCHAR *pc,*pcd;                                                //~v0hdI~
#ifdef UTF8UCS2                                                    //~va3EI~
    int ddstrlen;                                                  //~va3EI~
    UCHAR *pddstr;                                                 //~va3EI~
#endif                                                             //~va3EI~
	int offssrchword,offstail;                                     //~vauGR~
//*****************
    rc=fcmdsrchSTD(0,Ppcw,Preverse,Pchangeopt); //restor STD cmd if prev is findPS//~vbCBR~
    if (rc==1)	//no operand case,reenq prev std cmd               //~vbCBI~
    {                                                              //~vbCBI~
    	return 0;                                                  //~vbCBI~
    }                                                              //~vbCBI~
	Sothererr_abrange=0;	//not notfound err count:ab range err  //~v614M~
	Sothererr_selfjoin=0;   //not notfound err count:join myself case//~v614M~
//	UCBITON(Gprocstatus,GPROCSINIUPDATE);//need write ini at term//~v064R~
    pfc=Ppcw->UCWpfc;                                              //~v10RM~
    expandlen=pfc->UFCexpandlen;                                   //~v59TR~
    if (Pchangeopt)                                                //~v10RI~
		if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse mode      //~v10RI~
			return errbrowsemode();                                //~v10RI~
	if (Ppcw->UCWparm)	//input on cmdline                      //~5504R~
	{
//  	rc=fcmdfind(Ppcw,Pchangeopt,Pchangeopt,Preverse);          //~v09dR~
//  		//case sensitive when change,insensitive when find     //~v09dR~
//  	funcopdpostp(Ppcw,rc);	//operand post process by rc       //~v09dR~
//  	return rc;								//process FIND cmd //~v09dI~
        if (!Spfti)                                                //~v0hdI~
            if (!(Spfti=functblsrch(FUNCID_IFIND)))                //~v0hdI~
                return 4;                                          //~v0hdI~
#ifdef AAA                                                         //~vbCBM~
        if (!Spftf)                                                //~v0hdI~
            if (!(Spftf=functblsrch(FUNCID_FIND)))                 //~v0hdI~
                return 4;                                          //~v0hdI~
#endif                                                             //~vbCBM~
        if (!Spftc)                                                //~v0hdI~
            if (!(Spftc=functblsrch(FUNCID_CHANGE)))               //~v0hdI~
                return 4;                                          //~v0hdI~
		pc=Ppcw->UCWparm;                                          //~v0hdI~
		pcd=strpbrk(pc," ,");	//first opd delm pos               //~v0hdI~
        if (pcd)                                                   //~v0hdI~
//        	len=(int)((ULONG)pcd-(ULONG)pc);                       //~v0hdI~//~vafkR~
        	len=(int)((ULPTR)pcd-(ULPTR)pc);                       //~vafkI~
		else                                                       //~v0hdI~
        	len=(int)strlen(pc);                                   //~v0hdI~
    	len=min(len,(int)sizeof(wkcmd)-1);                         //~vbCBI~
    	UmemcpyZ(wkcmd,pc,(size_t)len);                            //~vbCBR~
		pft=functblsrchbycmd(wkcmd);                               //~vbCBI~
		*Gcmdbuff=0;                                               //~v0hdI~
        if (Pchangeopt)                                            //~v09dI~
        {                                                          //~v0hdI~
//          funcid=FUNCID_CHANGE;                                  //~v0hdR~
//          if	(len!=(int)Spftc->FTcmdalen                        //~v0iuR~
#ifdef AAA                                                         //~vbCBI~
            if	(len!=(int)strlen(Spftc->FTcmda)                   //~v0iuI~
			||   memicmp(pc,Spftc->FTcmda,(UINT)len))              //~v0hdI~
#else                                                              //~vbCBM~
			if (!pft || !UCBITCHK(pft->FTflag2,FTF2CHANGECMD))     //~vbCBM~
#endif                                                             //~vbCBM~
				strcpy(Gcmdbuff,Spftc->FTcmda);	//verve            //~v0hdI~
        }                                                          //~v0hdI~
        else                                                       //~v09dI~
        {                                                          //~v0hdI~
#ifdef AAA                                                         //~vbCBI~
//          funcid=FUNCID_IFIND;                                   //~v0hdR~
//          if	(len!=(int)Spfti->FTcmdalen                        //~v0iuR~
            if	(len!=(int)strlen(Spfti->FTcmda)                   //~v0iuI~
            ||   memicmp(pc,Spfti->FTcmda,(UINT)len))              //~v0hdI~
//          	if	(len!=(int)Spftf->FTcmdalen                    //~v0iuR~
            	if	(len!=(int)strlen(Spftf->FTcmda)               //~v0iuI~
                ||   memicmp(pc,Spftf->FTcmda,(UINT)len))          //~v0hdI~
#else                                                              //~vbCBM~
			if (!pft || !UCBITCHK(pft->FTflag2,FTF2FINDCMD))       //~vbCBM~
#endif                                                             //~vbCBM~
					strcpy(Gcmdbuff,Spfti->FTcmda);	//verve        //~v0hdI~
        }                                                          //~v0hdI~
//      if (!(pft=functblsrch(funcid)))                            //~v0hdI~
//          return 4;                                              //~v0hdI~
//  	strcpy(Gcmdbuff,pft->FTcmda);	//verve                    //~v0hdR~
        len=(int)strlen(Gcmdbuff);                                 //~v09dI~
	if (len)                                                       //~v0hdI~
        *(Gcmdbuff+len++)=' ';                                     //~v09dI~
        offssrchword=len;	//srch word position                   //~vauGI~
		strcpy(Gcmdbuff+len,Ppcw->UCWparm);                        //~v09dI~
        len=(int)strlen(Gcmdbuff);                                 //~v0hdI~
        offstail=len;	//srch word position                       //~vauGI~
        if (Preverse)                                              //~v09dI~
        {                                                          //~v0hdI~
          if (len<=5 || memcmp(Gcmdbuff+len-5,Scprev,5))           //~v0hdR~
          {                                                        //~v0hdI~
//      	strcat(Gcmdbuff+len," prev");                          //~v0hdR~
        	strcpy(Gcmdbuff+len,Scprev);	//add "Prev"           //~v0hdR~
            len+=5;                                                //~v0hdI~
		  }	                                                       //~v0hdI~
//      }                                                          //~v10VR~
//      else                                                       //~v10VR~
//      {                                                          //~v10VR~
          else                                                     //~v10VI~
          if (len>5 && !memcmp(Gcmdbuff+len-5,Scprev,5))           //~v0hdR~
          {                                                        //~v0hdI~
        	*(Gcmdbuff+len-5)=0;	//drop "Prev"                  //~v0hdI~
            len-=5;                                                //~v0hdI~
          }                                                        //~v0hdI~
        }                                                          //~v0hdI~
//  	funccmdstack(Gcmdbuff,len);	//save for retrieve            //~v670R~
//  	funccmdstack(Gcmdbuff,len,Ppcw->UCWseqno);	//save for retrieve//~v670R~//~vauGR~
		fcmd_execfindcmd(Ppcw,offssrchword,len,offstail);          //~vauGR~
    	Sfoundplh=NULL;                                            //~vavuI~
		return 0;                                                  //~v09dI~
	}//operand exist                                            //~5106R~
    pfh=pfc->UFCpfh;                                               //~v0hxI~
//  if (!Sreadsw)                                               //~v064R~
//  {                                                           //~v064R~
// 		Sreadsw=1;                                              //~v064R~
//      fcmdrfparm();                                           //~v064R~
//  }//first time                                               //~v064R~
	if (Pchangeopt)                                             //~5504R~
	{                                                           //~5504R~
      if (!Srepnull)                                               //~v09JI~
		if (!*Srepword)                                         //~5504R~
		{                                                       //~5504R~
			uerrmsg("Enter Change command at first",            //~5504R~
					"まず CHANGE コマンドを入力して下さい");    //~5504R~
			return 4;                                           //~5504R~
		}                                                       //~5504R~
	}                                                           //~5504R~
	else                                                        //~5504R~
//  	if (!*Ssrch)                                               //~v54zR~
    	if (!*Ssrch && !Seolsrchsw)   //len=0 eolsrch              //~v54zR~
        {                                                          //~v41rR~
			uerrmsg("Enter Find command at first",              //~5504R~
					"まず FIND コマンドを入力して下さい");      //~5504R~
			return 4;                                           //~5504R~
		}                                                       //~5504R~
    Swrapsw=0;						//clear at first               //~v0eFI~
	if (Preverse)	//S+PF5                                     //~5302R~
        if (Ssubcmdid==SUBCMD_PREV)                                //~v0iuR~
            Ssubcmdid=SUBCMD_NEXT;  //reverse direction            //~v0iuR~
        else                                                       //~v0iuR~
			Ssubcmdid=SUBCMD_PREV;	//reverse direction         //~5302R~
    else            //not reverse                                  //~v09cI~
    	if (!Pchangeopt)			//find not change              //~v09cI~
//          if (Gkbdinpctr==Snotfinpctr+1)    //next ope after failed find//~v0eGR~
            if (Gkbdinpctr==Snotfinpctr+1     //next ope after failed find//~v0eGR~
            &&  Snotfinpctr)     //not first time                  //~v0eGR~
            {                                                      //~v09cI~
//          	pfc=Ppcw->UCWpfc;                                  //~v0hxR~
//              pfh=pfc->UFCpfh;                                   //~v0hxR~
            	if (Ssubcmdid==SUBCMD_PREV) //previous ope is upward searc//~v09cI~
                {                                                  //~v09cI~
            		plh=UGETQPREV(UGETQEND(&pfh->UFHlineque));//search from last//~v09cI~
                	offset=plh->ULHlen;                            //~v09cI~
    			}                                                  //~v09cI~
            	else						//previous is downword search//~v09cI~
                {                                                  //~v09cI~
            		plh=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));//search from first//~v09cI~
                	offset=0;                                      //~v09cI~
    			}                                                  //~v09cI~
                Swrapsw=1;                                         //~v09cI~
            }                                                      //~v09cI~
//set start pos                                                    //~v41rR~
  if (!Swrapsw)		//not research                                 //~v09cI~
  {                                                                //~v09eI~
//  if (!getstartoffs(Ppcw,&plh,&offset)	//in client area       //~v09eR~
	rc=fcmdgetstartplhoffs(Ppcw,&plh,&offset,Sulsrchsw);		//in client area//~v47iR~
	if (Sulsrchsw==LINE_SAMESRCH                                   //~v49bI~
	&&  !Preverse                                                  //~v49bI~
	&&  Ssamelastplh)                                              //~v49bI~
    {                                                              //~v62dI~
        if (rc<4	//cs in the file area,1:on lineno fld          //~v49bR~
		&&  plh==Sfoundplh                                         //~v49bI~
//  	&&  offset==Sfoundoffs  fcmdgetstartplhoffs set offs=0 when ulsrch//~v49bR~
		&&  plh->ULHrevctr==Spfhfindctr) //after prev find         //~v49bI~
        {                                                          //~v49bI~
            if (Ssubcmdid==SUBCMD_PREV) //backword                 //~v49bI~
            {                                                      //~v49bI~
            	plh=UGETQPREV(Sfoundplh);                          //~v49bR~
                offset=plh->ULHlen;                                //~v49bI~
            }                                                      //~v49bI~
            else //forward                                         //~v49bI~
            {                                                      //~v49bI~
            	plh=UGETQNEXT(Ssamelastplh);                       //~v49bI~
                offset=0;                                          //~v49bI~
            }                                                      //~v49bI~
        }                                                          //~v49bI~
    }//samesrch                                                    //~v62dI~
    else                                                           //~v62dI~
	if (Sulsrchsw==LINE_SAMEMATCH)                                 //~v62dI~
    {                                                              //~v62dI~
        if (Ssubcmdid==SUBCMD_PREV) //backword                     //~v62dI~
        {                                                          //~v62dI~
        	if (offset==Srange1)                                   //~v62dI~
            {                                                      //~v62dI~
				if (Sfindcmdinpctr!=Gkbdinpctr-1)	//cursor moved //~v62dI~
	            	offset=OFFS_LAST;	//bypass getprev at linesrchstring//~v62dI~
            }                                                      //~v62dI~
            else                                                   //~v62dI~
        	if (offset>Srange1)                                    //~v62dI~
            	offset=OFFS_LAST;	//bypass getprev at linesrchstring//~v62dR~
        }                                                          //~v62dI~
        else //forward                                             //~v62dI~
        {                                                          //~v62dI~
        	if (offset==Srange1)                                   //~v62dI~
            {                                                      //~v62dI~
				if (Sfindcmdinpctr!=Gkbdinpctr-1)	//cursor moved //~v62dI~
	            	offset=OFFS_TOP;	//bypass getprev at linesrchstring//~v62dI~
            }                                                      //~v62dI~
            else                                                   //~v62dI~
        	if (offset<Srange1)                                    //~v62dI~
            	offset=OFFS_TOP;	//bypass getprev at linesrchstring//~v62dR~
        }                                                          //~v62dI~
    }//samematch                                                   //~v62dI~
    	                                                           //~v49bI~
//  if (Snotsrchsw)                                                //~v539R~
    if (Snotsrchsw                  //same as line search          //~v539I~
    ||  Sfindopt & FINDOPT_JOIN)    //of joined line               //~v539I~
                                                                   //~v539I~
    {                                                              //~v41rI~
        if (plh==Sfoundplh                                         //~v41rR~
        &&  plh->ULHrevctr==Spfhfindctr) //after prev find         //~v41rR~
        {                                                          //~v41rR~
            if (Ssubcmdid==SUBCMD_PREV) //backword                 //~v41rR~
            {                                                      //~v41rR~
            	plh=UGETQPREV(plh);                                //~v41rR~
                offset=plh->ULHlen;                                //~v41rR~
            }                                                      //~v41rR~
            else //forward                                         //~v41rR~
            {                                                      //~v41rR~
            	plh=UGETQNEXT(plh);                                //~v41rR~
                offset=0;                                          //~v41rR~
            }                                                      //~v41rR~
        }                                                          //~v41rR~
    }//*!                                                          //~v41rR~
    else                                                           //~v41rI~
   if (!Sulsrchsw)                          //not update line search//~v09eR~
   {                                                               //~v54aI~
    if (!rc									//in client area       //~v09eI~
	&&  plh==Sfoundplh                                          //~5107R~
	&&  offset==Sfoundoffs                                      //~5107R~
	&&  plh->ULHrevctr==Spfhfindctr) //after prev find          //~5422R~
	{                                                           //~5107I~
//      if (Ppcw->UCWtype==UCWTDIR && Sdirstep)	                   //~v084R~
        if (Ppcw->UCWtype==UCWTDIR)                                //~v084I~
        {                                                          //~v084I~
        	if (Preverse)	//change direction                     //~v084I~
     	       offset+=Sdirstepr;	//for reverse serch            //~v084R~
            else                                                   //~v084I~
            offset+=Sdirstep;                                   //~v05wI~
        }                                                          //~v084I~
		else	//edit                                             //~v41rR~
    	if (Ssubcmdid==SUBCMD_PREV)	//backword                  //~5302R~
		{                                                       //~5114I~
            if (Seolsrchsw)                                        //~v54zI~
            {                                                      //~v54zI~
            	plh=UGETQPREV(plh);//search from last              //~v54zI~
                offset=plh->ULHlen;//eol                           //~v54zI~
    		}//eolsrch                                             //~v54zI~
            else                                                   //~v54zI~
			if (Pchangeopt					//change            //~5114R~
            &&  Schangeopt!=Pchangeopt)     //change after find //~5114R~
            {                                                      //~v54aI~
              if (Sspanplh)                                        //~v13pR~
              	fcmdnextofspan(&offset,Sstep,&plh);	//advance to next line//~v13pI~
              else                                                 //~v13pI~
        		offset+=Sstep;                                  //~5107I~
            }                                                      //~v54aI~
		}                                                       //~5114I~
		else	//forward                                       //~5114I~
		{                                                       //~5114I~
            if (Seolsrchsw)                                        //~v54zI~
            {                                                      //~v54zI~
            	plh=UGETQNEXT(plh);//search from first             //~v54zI~
                offset=0;                                          //~v54zI~
    		}//eolsrch                                             //~v54zI~
            else                                                   //~v54zI~
			if (!Pchangeopt					//find              //~5114I~
		  	||  Schangeopt==Pchangeopt)     //change after change//~5114~I
            {                                                      //~v54aI~
              if (Sspanplh)                                        //~v13pR~
              	fcmdnextofspan(&offset,Sstep,&plh);	//advance to next line//~v13pI~
              else                                                 //~v13pI~
        		offset+=Sstep;                                  //~5114I~
            }                                                      //~v54aI~
		}                                                       //~5114I~
	}                                                           //~5107I~
    else                                                        //~5107I~
//not found or cursor moved after found                            //~v41rI~
    	if (Ssubcmdid==SUBCMD_PREV)	//backword                  //~5302R~
		    if (Ppcw->UCWtype!=UCWTDIR                          //~v05wI~
//          ||  offset>=(int)offsetof(UDIRLD,UDDrname[0]))         //~v59TR~
            ||  offset>=(int)offsetof(UDIRLD,UDDrname[0])+expandlen)//~v59TI~
        {                                                          //~v54aI~
          if ((offset+Ssrchlen>plh->ULHlen)                        //~v13pI~
          &&   UCBITCHK(pfh->UFHflag4,UFHF4BIN)                    //~v13pR~
          &&  (Ssrchlen2 && (int)Srangeid2and==RANGENOPARM) //old fashion//~v532R~
          &&  ((int)Srangeid2==RANGENOPARM)) //old fashion         //~v437R~
            fcmdnextofspan(&offset,Ssrchlen,&plh);	//advance to next line//~v13pI~
          else                                                     //~v13pI~
          {                                                        //~va3EI~
#ifdef UTF8UCS2                                                    //~va3EI~
		   if ((ddstrlen=fcmdisddsrch(0,Ppcw,&pddstr,&pddstr/*not used*/)))//~va3ER~
			offset+=ddstrlen;		//search also current pos word //~va3EI~
           else                                                    //~va3EI~
#endif                                                             //~va3EI~
			offset+=Ssrchlen;		//search also current pos word//~5107I~
          }                                                        //~va3EI~
        }                                                          //~v54aI~
   }//!ulsrch                                                      //~v54aI~
  }                                                                //~v09eI~
  else      //wrap serch                                           //~v09eI~
   if (Sulsrchsw)                          //not update line search//~v09eI~
   {                                                               //~v54aI~
    	if (Ssubcmdid==SUBCMD_PREV)	//backword                     //~v09eI~
//  		offset=2;               //id of search from the last line//~v41rR~
    		offset=OFFS_LAST;       //id of search from the last line//~v41rI~
        else                                                       //~v09eI~
//  		offset=1;               //id of search from the top line//~v41rR~
    		offset=OFFS_TOP;        //id of search from the top line//~v41rR~
   }//ulsrchsw                                                     //~v54aI~
//	return linesrchstring(Ppcw,&plh,&offset,1,Pchangeopt,Ssubcmdid);	//locate//~v09cR~
//  if (fcmdsetrange(Ppcw,Sulsrchsw,                               //~v0eBR~//~vbc1R~
    if (fcmdsetrange(Ppcw,Sulsrchsw,Ssrch,                         //~vbc1I~
		Ssrchlen,Srangeid1,Srangeid2,&Srange1,&Srange2))           //~v0eBI~
		return 4;                                                  //~v0eBI~
    Sfindopt&=~(FINDOPT_DIRATTR|FINDOPT_DIRATTRAND);               //~vbc1I~
    Sfindopt&=~(FINDOPT_DIRTS|FINDOPT_DIRTSAND);                   //~vbc2I~
    if (Srangeid2==RANGEATTR)                                      //~vbc1I~
    {                                                              //~vbc1I~
    	Sfindopt|=FINDOPT_DIRATTR;                                 //~vbc1I~
    }                                                              //~vbc1I~
    if (Srangeid2==RANGETS)                                        //~vbc2I~
    {                                                              //~vbc2I~
    	Sfindopt|=FINDOPT_DIRTS;                                   //~vbc2I~
    }                                                              //~vbc2I~
//  if (Ssrchlen2)             //*&                                //~v54zR~
//  if (Ssrchlen2||Seolsrchsw2)//*&                                //~v62dR~
    if (Ssrchlen2||Seolsrchsw2)//*&                                //~v62fR~
    {                                                              //~v532I~
//  	if (fcmdsetrange(Ppcw,Sulsrchsw,                           //~v532I~//~vbc1R~
    	if (fcmdsetrange(Ppcw,Sulsrchsw,Ssrch2,                    //~vbc1I~
			Ssrchlen2,Srangeid1and,Srangeid2and,&Srange1and,&Srange2and))//~v532I~
			return 4;                                              //~v532I~
	    if (Srangeid2and==RANGEATTR)                               //~vbc1I~
    	{                                                          //~vbc1I~
    		Sfindopt|=FINDOPT_DIRATTRAND;                          //~vbc1I~
    	}                                                          //~vbc1I~
	    if (Srangeid2and==RANGETS)                                 //~vbc2I~
    	{                                                          //~vbc2I~
    		Sfindopt|=FINDOPT_DIRTSAND;                            //~vbc2I~
    	}                                                          //~vbc2I~
    }                                                              //~v532I~
//    Srangeplhs=0;       //clear range                            //~v0hxR~
//    Srangeplhe=0;       //clear range                            //~v0hxR~
    if (Ppcw->UCWtype==UCWTDIR)     //on dir list                  //~v0hxR~
    {                                                              //~v0hxR~
    	Slinerangesw=0;                                            //~v0hxR~
		Srangeplhe=0;       //clear range                          //~v0hxR~
	}                                                              //~v0hxR~
    else                                                           //~v0hxR~
    {                                                              //~v0hxR~
    	plhw=plh;		//for chk update by label                  //~v0hHI~
    	Slinerangesw=fcmdsetabrange(Ppcw,pfh,Ssubcmdid,&plh,&Srangeplhe);//set from/to plh//~v0hxR~
    	if (Slinerangesw>=2)	//label err,not found              //~v0hxR~
        	return 4;                                              //~v0hxR~
        if (!Sulsrchsw)                                            //~v0hHI~
			if (plh!=plhw)                                         //~v0hHI~
	        {                                                      //~v54aI~
		    	if (Ssubcmdid==SUBCMD_PREV)	//backword             //~v0hHI~
    	        	offset=plh->ULHlen;                            //~v0hHI~
        	    else                                               //~v0hHI~
            		offset=0;                                      //~v0hHI~
        	}//plhw                                                //~v54aI~
	    if (Sulsrchsw==LINE_SAMEMATCH)                             //~v62dI~
        {                                                          //~v62dI~
        	Spfhmatching=fcmdget2ndpfh(Ppcw,Smatchingid);          //~v62fR~
            if (!Spfhmatching)                                     //~v62dI~
            	return 8;                                          //~v62dI~
        }                                                          //~v62dI~
	}                                                              //~v0hxR~
    Supctrsw=0;                                                    //~v0hzI~
	rc=linesrchstring(Ppcw,&plh,&offset,1,Pchangeopt,Ssubcmdid);	//locate//~v09cI~
//    if (rc)                                                      //~v11sR~
//        UTRACEP("fcmdrfind:rc=%d\n",rc);                         //~v11sR~
    if (Supctrsw)			//exclude/include occured              //~v0hzI~
    	UPCTRREQ(pfh);                                             //~v0hzI~
//  if (Smfwtindex>1)   //multiple found                           //~v43hR~
//      if (fcmdcpymfwt(pfh))                                      //~v62bR~
//          return 8;                                              //~v62bR~
//  Swrapsw=0;						//clear for next op            //~v0eFR~
	return rc;                                                     //~v09cI~
}//fcmdrfind

//****************************************************************
//!fcmdfind
//*find command
//* parm1 :pcw
//* parm2 :case sensitive sw
//* parm3 :change cmd option(0:find 1:change)                   //~5106I~
//* parm4 :backward search opt(0:dest from cmd opd,1:force backward)//~5302I~
//* parm5 :option to search on not excluded line only              //~v10oI~
//* ret   :rc                                                   //~5106R~
//****************************************************************
int fcmdfind(PUCLIENTWE Ppcw,int Pcasesw,int Pchangeopt,int Pbackward,int Pnxopt)//~v10oR~
{                                                                  //~vbCBI~
int fcmdfindsub(PUCLIENTWE Ppcw,int Pcasesw,int Pchangeopt,int Pbackward,int Pnxopt);//~vbCBI~
    int rc;                                                        //~vbCBI~
//**********************                                           //~vbCBI~
	fcmdchkPS(0,0,Ppcw,Pcasesw,Pchangeopt,Pbackward,Pnxopt);       //~vbCBI~
	rc=fcmdfindsub(Ppcw,Pcasesw,Pchangeopt,Pbackward,Pnxopt);      //~vbCBI~
	fcmdchkPS(1,rc,Ppcw,Pcasesw,Pchangeopt,Pbackward,Pnxopt);      //~vbCBI~
    return rc;                                                     //~vbCBR~
}                                                                  //~vbCBI~
int fcmdfindsub(PUCLIENTWE Ppcw,int Pcasesw,int Pchangeopt,int Pbackward,int Pnxopt)//~vbCBI~
{
	PUFILEC pfc;
	PULINEH plh=0;                                                 //~vaf9R~
	PULINEH plhw;                                                  //~v0hHI~
	PUFILEH pfh;
	int rc,offset;                                              //~5107R~
	int orgsubcmdid;
	int foundctr;                                                  //~v47BI~
#ifdef UTF8UCS2                                                    //~va3EI~
    int ddstrlen;                                                  //~va3EI~
    UCHAR *pddstr;                                                 //~va3EI~
#endif                                                             //~va3EI~
//*********************************
	Sothererr_abrange=0;	//not notfound err count:ab range err  //~v614I~
	Sothererr_selfjoin=0;   //not notfound err count:join myself case//~v614I~
//  Snxsw=Pnxopt;		//parm to linesrchstring                   //~v73dR~
    Gnxsw=Pnxopt;		//parm to linesrchstring                   //~v73dI~
//  Srangeplhs=0;		//clear range                              //~v0hxR~
//  Srangeplhe=0;       //clear range                              //~v0hxR~
    Swrapsw=0;						//no re-search case            //~v0hFI~
	pfc=Ppcw->UCWpfc;
	pfh=pfc->UFCpfh;
    if (Pchangeopt)                                                //~v10RI~
		if (UCBITCHK(pfc->UFCflag,UFCFBROWSE))	//browse mode      //~v10RI~
			return errbrowsemode();                                //~v10RI~
// 	Sreadsw=1;			//avoid read parm file anymore          //~v064R~
//  if (operandchk(Ppcw,Ppcw->UCWparm,Pchangeopt,Pbackward))	//get operand word//~v11pR~
//  rc=operandchk(Ppcw,Ppcw->UCWparm,Pchangeopt,Pbackward);	//get operand word//~v78dR~
    rc=operandchk(Ppcw,Ppcw->UCWparm,Pchangeopt,Pbackward,Pcasesw);	//get operand word//~v78dI~
    if (rc==RC_EXC_ALL)		//not exclude all case                 //~v11pR~
    {                                                              //~v40GI~
    	rc=fcmdxall(Ppcw,pfh);                                     //~v40JI~
	    fcmd2saverestorx(0);	//restore for the case "x all"/"x=all"//~v40GI~
    	return rc;                                                 //~v40JI~
    }                                                              //~v40GI~
//  if (rc==RC_EXC_ALLSAME)	//x *= or c *=                         //~v49bR~
//  {                                                              //~v49bR~
//  	rc=fcmdxallsame(Ppcw,pfh,Pcasesw,Srange1,Srange2,Sminsame);//~v49bR~
//      fcmd2saverestorx(0);	//restore for the case "x all"/"x=all"//~v49bR~
//  	return rc;                                                 //~v49bR~
//  }                                                              //~v49bR~
    if (rc)                                                        //~v11pI~
		return 4;                                               //~5106I~
//	UCBITON(Gprocstatus,GPROCSINIUPDATE);//need write ini at term//~v064R~
    if (!Pchangeopt)        //find cmd                             //~v40HI~
    	*Srepword=0; 		//inactivate change                    //~v40HI~
    Swrapsw=0;						//clear at first               //~v10UM~
    if (!Pchangeopt)                                               //~v10UI~
        if (Gkbdinpctr==Snotfinpctr+1     //next ope after failed find//~v10UM~
        &&  Snotfinpctr)     //repeated cmd entry                  //~v10UM~
        {                                                          //~v54aI~
        	if (!Ssubcmdid || Ssubcmdid==SUBCMD_NEXT)              //~v10UR~
            {                                                      //~v10UI~
            	Ssubcmdid=SUBCMD_FIRST;                            //~v10UI~
	            Swrapsw=1;       //try wrap if subcmd=next/prev    //~v10UI~
			}                                                      //~v10UI~
            else                                                   //~v10UI~
        		if (Ssubcmdid==SUBCMD_PREV)                        //~v10UR~
	            {                                                  //~v10UI~
    	        	Ssubcmdid=SUBCMD_LAST;                         //~v10UI~
	    	        Swrapsw=1;       //try wrap if subcmd=next/prev//~v10UI~
				}                                                  //~v10UI~
        }//inpctr                                                  //~v54aI~
	orgsubcmdid=Ssubcmdid;
	switch(Ssubcmdid)
	{
	case 0:				//no subcmd default is current line top
	case SUBCMD_NEXT:	//next
	  if (Sfindopt & FINDOPT_NEXT2 && SnextStartplh)               //~vbzxR~
      {                                                            //~vbzxI~
        UTRACEP("%s:next2 Serrplh->plhlineno=%d\n",UTT,SnextStartplh->ULHlinenor);//~vbzxR~
    	plh=SnextStartplh;                                         //~vbzxR~
    	offset=SnextStartoffset;                                   //~vbzxR~
      }                                                            //~vbzxI~
      else                                                         //~vbzxI~
    	fcmdgetstartplhoffs(Ppcw,&plh,&offset,Sulsrchsw);	//strat pos by csr pos//~v47iR~
        UTRACEP("%s:next2 startplh lineno=%d,Ssrch=%s\n",UTT,plh->ULHlinenor,Ssrch);//~vbzxR~
		Ssubcmdid=SUBCMD_NEXT; //for case 0                     //~4C30R~
    	if (Snotsrchsw)                                            //~v41rR~
        	offset=0;                                              //~v41rI~
		break;
	case SUBCMD_FIRST:			//first
	case SUBCMD_ALL:			//all
	case SUBCMD_ALLKX:			//all                              //~v537I~
		if (Ssubcmdid==SUBCMD_ALLKX)                               //~v537I~
        	Sallkxinpctr=Gkbdinpctr;	//effective only at once   //~v537I~
		plh=UGETQNEXT(UGETQTOP(&pfh->UFHlineque));              //~4C30R~
        if (Sulsrchsw)                                             //~v41sI~
          offset=OFFS_TOP;   //dont skip to next line              //~v41rR~
        else                                                       //~v41sI~
    	offset=0;
//        rc=fcmdsetabrange(Ppcw,pfh,1);//lcmd 'A'/'B' exist       //~v0hxR~
//        if (rc<0)   //err                                        //~v0hxR~
//            return 4;                                            //~v0hxR~
//        if (rc)                                                  //~v0hxR~
//            if (Srangeplhs) //'A' detected                       //~v0hxR~
//                plh=Srangeplhs; //start plh                      //~v0hxR~
		Ssubcmdid=SUBCMD_NEXT; //for search
		break;
	case SUBCMD_LAST:			//last
		plh=UGETQPREV(UGETQEND(&pfh->UFHlineque));              //~4C30R~
        if (Sulsrchsw)                                             //~v41sI~
          offset=OFFS_LAST;   //dont skip to prev line             //~v41rR~
        else                                                       //~v41sI~
    	offset=plh->ULHlen;                                     //~4C30R~
		Ssubcmdid=SUBCMD_PREV; //for search
		break;
	case SUBCMD_PREV:			//prev
    	fcmdgetstartplhoffs(Ppcw,&plh,&offset,Sulsrchsw);	//strat pos by csr pos//~v47iR~
      if ((offset+Ssrchlen>plh->ULHlen)                            //~v13pR~
      &&   UCBITCHK(pfh->UFHflag4,UFHF4BIN)                        //~v13pR~
      &&  (Ssrchlen2 && !Srange1and && (Srange2and==MAXRIGHT))     //~v532I~
      &&  (!Srange1 && (Srange2==MAXRIGHT)))                       //~v13pI~
        fcmdnextofspan(&offset,Ssrchlen,&plh);	//advance to next line//~v13pR~
      else                                                         //~v13pI~
      {                                                            //~va3EI~
#ifdef UTF8UCS2                                                    //~va3EI~
		   if ((ddstrlen=fcmdisddsrch(0,Ppcw,&pddstr,&pddstr/*not used*/)))//~va3ER~
			offset+=ddstrlen;		//search also current pos word //~va3EI~
           else                                                    //~va3EI~
#endif                                                             //~va3EI~
		offset+=Ssrchlen;		//srch also current pos word    //~5107I~
      }                                                            //~va3EI~
                                                                   //~va3EI~
    	if (Snotsrchsw)                                            //~v41rR~
        	offset=plh->ULHlen;                                    //~v41rI~
		break;
	}//by subcmd
//*set linerange                                                   //~v0hxR~
    if (Ppcw->UCWtype==UCWTDIR)     //on dir list                  //~v0hxR~
    {                                                              //~v0hxR~
    	Slinerangesw=0;                                            //~v0hxR~
		Srangeplhe=0;       //clear range                          //~v0hxR~
	}                                                              //~v0hxR~
    else                                                           //~v0hxR~
    {                                                              //~v0hxR~
    	plhw=plh;		//for change chk                           //~v0hHI~
    	Slinerangesw=fcmdsetabrange(Ppcw,pfh,Ssubcmdid,&plh,&Srangeplhe);//set from/to plh//~v0hxR~
    	if (Slinerangesw>=4)	//label err                        //~v0hxR~
        	return 4;                                              //~v0hxR~
		else                                                       //~v0hxI~
        	if (Slinerangesw==2)	//not found                    //~v0hxI~
            	return 1;		//enter as new line                //~v0hxI~
        if (!Sulsrchsw)                                            //~v0hHI~
        	if (plh!=plhw)			//start line changed by label  //~v0hHM~
            {                                                      //~v54aI~
				if (Ssubcmdid==SUBCMD_PREV) //for search           //~v0hHR~
		    		offset=plh->ULHlen;	//search start from last of label line//~v0hHR~
                else                                               //~v0hHI~
                	offset=0;                                      //~v0hHI~
            }//plhw                                                //~v54aI~
	}                                                              //~v0hxR~
//*search
    Supctrsw=0;			//exclude/include occured                  //~v0hzI~
//if (!Pchangeopt)                                                 //~v10QI~,//~v72PR~
	Scasesensesw=Pcasesw;		//case sensitive
//else                                                             //~v649I~,//~v72PR~
//  Scasesensesw=1;         	//case sensitive  after change     //~v649I~,//~v72PR~
//  if (rc=linesrchstring(Ppcw,&plh,&offset,1,Pchangeopt,Ssubcmdid),rc)//locate//~v61bR~
	UTRACEP("%s:startplh lineno=%d\n",UTT,rc,plh?plh->ULHlinenor:-1);//~vbzxI~
    rc=linesrchstring(Ppcw,&plh,&offset,1,Pchangeopt,Ssubcmdid);   //~v61bI~
	UTRACEP("%s:next2 rc=%d,srch return lineno=%d\n",UTT,rc,plh?plh->ULHlinenor:-1);//~vbzxR~
    SnextStartplh=plh;     //if not found plh stay at starting point/+vbzxI~//~vbzxI~
    SnextStartoffset=offset;                                       //~vbzxM~
    if (rc)                                                        //~v61bI~
    {                                                              //~v0hzI~
//        UTRACEP("fcmdfind:rc=%d\n",rc);                          //~v11sR~
    	if (Supctrsw)			//exclude/include occured          //~v0hzI~
    		UPCTRREQ(pfh);                                         //~v0hzI~
        return rc;
	}                                                              //~v0hzI~
//  if (orgsubcmdid==SUBCMD_ALL)	//all                          //~v537R~
    if (orgsubcmdid==SUBCMD_ALL	//all                              //~v537I~
    ||  orgsubcmdid==SUBCMD_ALLKX)	//all                          //~v537I~
	{
//*loop until not found                                         //~5106I~
		S2ndofallsw=1; //2nd search of all                         //~v54BR~
		while(!rc)
		{                                                       //~5107I~
          if (Sulsrchsw==LINE_SAMESRCH                             //~v49bI~
          &&  Ssamelastplh)                                        //~v49bI~
          {                                                        //~v49bI~
            plh=UGETQNEXT(Ssamelastplh);                           //~v49bI~
            offset=0;                                              //~v49bI~
          }                                                        //~v49bI~
          else  //!*=                                              //~v49bI~
          {                                                        //~v49bI~
//      	if (Sdirstep)                                          //~v0hDR~
    		if (Ppcw->UCWtype==UCWTDIR)     //on dir list          //~v0hDI~
            	offset+=Sdirstep;                               //~v05wI~
            else                                                //~v05wI~
//          if (Snotsrchsw)  //not srch                            //~v43sR~
//          if (Snotsrchsw||Ssrchlen2)  //not srch                 //~v539R~
            if (Snotsrchsw||Ssrchlen2  //not srch                  //~v539I~
            ||  Seolsrchsw             //eol search                //~v54zI~
            ||  Sulsrchsw              //*u or *e                  //~vagaI~
            ||  Splhafter             //-a parm specified and after plh is after the found line//~v54VI~
        	||  Sfindopt & FINDOPT_JOIN)                           //~v539I~
            {                                                      //~v41rI~
//  			if (Ssubcmdid==SUBCMD_PREV) //backword             //~v539R~
//              {                                                  //~v539R~
//              	plh=UGETQPREV(plh);                            //~v539R~
//                  offset=plh->ULHlen;                            //~v539R~
//              }                                                  //~v539R~
//              else                                               //~v539R~
//              {                                                  //~v539R~
				  	if (Splhafter)                                 //~v54VR~
                  		plh=Splhafter;                             //~v54VR~
                	plh=UGETQNEXT(plh);                            //~v41rI~
					if (Sulsrchsw)	//srchlinestringsub step next  //~v633R~
						offset=OFFS_ULNEXT;//avoid step next line  //~v633I~
                    else                                           //~v633I~
                    offset=0;                                      //~v41rI~
//              }                                                  //~v539R~
            }//*!                                                  //~v41rI~
            else                                                   //~v41rI~
			offset+=Sstep;		//find word len or rep word len //~5307M~
          }//!*=                                                   //~v49bI~
			rc=linesrchstring(Ppcw,&plh,&offset,0,Pchangeopt,Ssubcmdid);	//step,no locate//~5114R~
		}                                                       //~5107I~
        if (S2ndofallsw==2)	//excluded 2nd                         //~v54BI~
			lcmdexcfromxall2(Ppcw,0,0);	//update excluded counter  //~v54BR~
		S2ndofallsw=0; //reset 2nd search of all                   //~v54BR~
    	if (Supctrsw)			//exclude/include occured          //~v0hzI~
    		UPCTRREQ(pfh);                                         //~v0hzI~
//*reset find all table                                         //~v05vI~
//      if (Smfwtindex>1)	//multiple found                       //~v43hR~
//        {                                                        //~v43gR~
//            if (pfh->UFHmfwtbl)                                  //~v43gR~
//                ufree(pfh->UFHmfwtbl);  //free old               //~v43gR~
//            pfh->UFHmfwtbl=UALLOCM((UINT)(Smfwtindex*sizeof(USHORT)));//~v43gR~
//            UALLOCCHK(pfh->UFHmfwtbl,8);    //return 8 if fail   //~v43gR~
//            memcpy(pfh->UFHmfwtbl,Gfilemfwtbl,(UINT)(Smfwtindex*sizeof(USHORT)));//~v43gR~
//        }                                                        //~v43gR~
//          if (fcmdcpymfwt(pfh))                                  //~v62bR~
//          	return 8;                                          //~v62bR~
		if (rc>4)	//replace overflow maxlinedata              //~5107I~
    		return 8;                                           //~5107R~
        foundctr=Sfoundctr;                                        //~v47BI~
//  	if (Ssrchlen2)      //*& serch                             //~v54zR~
    	if (Ssrchlen2||Seolsrchsw2)// & srch                       //~v54zR~
//          foundctr>>=1;                                          //~v54aR~
            foundctr/=2;                                           //~v54aI~
		if (Pchangeopt)                                         //~5106I~
//  		if (Smfwtovf)                                          //~v73dR~
    		if (Gmfwtovf)                                          //~v73dI~
//                uerrmsg("Changed %d times;reverse display upto %d word(line %ld-%d,offset x%lX).",//~vaz0R~
////                      "%d 個 変更しました,%d 個迄強調表示されています",//~vaz0R~
//                        "%d 個 変更しました,%d個 (%ld-%d 行目,Offset x%lX)まで反転\x95\\示されています。",//~vaz0R~
////                      Sfoundctr,Smfwtovf,Sovflineno,Sovfsuffix,Sovfoffset);//~vaz0R~
//                        Sfoundctr,Gmfwtovf,Sovflineno,Sovfsuffix,Sovfoffset);//~vaz0R~
                uerrmsg("Changed %d times;reverse display upto %d word(line %ld-%d,offset %s).",//~vaz0R~
                        "%d 個 変更しました,%d個 (%ld-%d 行目,Offset %s)まで反転\x95\\示されています。",//~vaz0I~
                        Sfoundctr,Gmfwtovf,Sovflineno,Sovfsuffix,ueditFILESZ(0/*opt*/,0/*buf*/,0/*buffsz*/,"x%$X",Sovfoffset));//~vaz0R~
			else                                                //~5106I~
				uerrmsg("Found %d times",                       //~5106I~
						"%d 個 変更しました",                   //~5106I~
						Sfoundctr);                             //~5106I~
        else                                                    //~5106I~
//  		if (Smfwtovf)                                          //~v73dR~
    		if (Gmfwtovf)                                          //~v73dI~
//  			uerrmsg("Found %d times;reverse display up to %d word(line %ld-%d,offset x%lX).",//~vaz0R~
    			uerrmsg("Found %d times;reverse display up to %d word(line %ld-%d,offset %s).",//~vaz0I~
//  					"%d 個 見つかりました,%d 個迄強調表示されています",//~v095R~
//  					"%d 個 見つかりました,%d 個(%ld-%d 行目,Offset x%lX)まで反転\x95\\示されています。",//~vaz0R~
    					"%d 個 見つかりました,%d 個(%ld-%d 行目,Offset %s)まで反転\x95\\示されています。",//~vaz0I~
//  					Sfoundctr,Smfwtovf);                       //~v47BR~
//  					foundctr,Smfwtovf,Sovflineno,Sovfsuffix,Sovfoffset);//~v73dR~
//  					foundctr,Gmfwtovf,Sovflineno,Sovfsuffix,Sovfoffset);//~vaz0R~
    					foundctr,Gmfwtovf,Sovflineno,Sovfsuffix,ueditFILESZ(0/*opt*/,0/*buff*/,0/*buffsz*/,"x%$X",Sovfoffset));//~vaz0R~
			else                                                //~5106R~
              if (Sexcludesw2)                                     //~v0hzI~
				uerrmsg("Excluded %d lines",                       //~v0hzR~
//  					"%d 行 非表示化",                          //~v0hzR~
//  					"%d 行 非\x95\\示化",                      //~v49bR~
    					"%d 個所 非\x95\\示化",                    //~v49bI~
//  					Sfoundctr);                                //~v47BR~
						foundctr);                                 //~v47BI~
              else                                                 //~v0hzI~
    		   if (Sulsrchsw==LINE_SAMESRCH)  //*=                 //~v58ZI~
				uerrmsg("Found %d times",                          //~v58ZI~
						"%d 個所 見つかりました",                  //~v58ZI~
						foundctr);                                 //~v58ZI~
               else                                                //~v58ZI~
				uerrmsg("Found %d times",                       //~5106R~
						"%d 個 見つかりました",                 //~5106R~
//  					Sfoundctr);                                //~v47BR~
						foundctr);                                 //~v47BI~
        if (rc=fcmdothererrmsgcat(SUBCMD_ALL),rc)                  //~v614R~
            return rc;                                             //~v614I~
	}
    if (Sexcludesw)                                                //~vb86I~
    	lcmdexcludedmsg(LCXMO_MSGCAT,pfh);                         //~vb86I~
//  else   //not all,but multi when *&                             //~v62bR~
//      if (Smfwtindex>1)	//multiple found                       //~v43hR~
//          if (fcmdcpymfwt(pfh))                                  //~v62bR~
//          	return 8;                                          //~v62bR~
	return 0;
}//fcmdfind
//****************************************************************//~5106I~
//!operandchk                                                   //~5106I~
//* parm1 :pcw                                                     //~v09dR~
//* parm2 :operand string                                          //~v09dI~
//* parm3 :change cmd option(0:find 1:change)                      //~v09dR~
//* parm4 :force backward option(0:use cmd operand,1:force backward srch)//~v09dR~
//*rc   :0:ok,2:exclude all,4:err                                  //~v11pR~
//****************************************************************//~5106I~
//int operandchk(PUCLIENTWE Ppcw,UCHAR *Popd,int Pchangeopt,int Pbackward)//~v78dR~
int operandchk(PUCLIENTWE Ppcw,UCHAR *Popd,int Pchangeopt,int Pbackward,int Pcasesw)//~v78dI~
{                                                               //~5106I~
//#define MAXFCMDOPDNO  5                                          //~v0hIR~
//#define MAXFCMDOPDNO  7                                          //~v437R~
#define MAXFCMDOPDNO   15     //cur max is 9                       //~v437I~
	int rc,psubcmdid,subcmdid1,subcmdid2,opdno=0,ii;               //~v0eBR~
    SHORT rangeid1=0,rangeid2=0;                                       //~v11oR~//~vafcR~
    SHORT rangeid1and=0,rangeid2and=0;                                 //~v532I~//~vafcR~
//	char *pc,*srchword,*repword="",*sub1,*sub2,*srchword2;         //~v43eR~//~vafcR~
 	char *pc,*srchword="",*repword="",*sub1="",*sub2="",*srchword2=NULL;//~vafcI~
    UPODELMTBL *podt1=NULL,*podt2=NULL,*popdt12;                             //~v43eR~//~vafcR~
    PUFILEH     pfh;                                               //~v11sI~
    PUFILEC     pfc;                                               //~v11sI~
	UPODELMTBL  odt[MAXFCMDOPDNO+1];                               //~v0eBI~
	char       *opd[MAXFCMDOPDNO+1];                               //~v0eBI~
    int   orgopdno=0,tabchkrc;                                       //~v11sR~//~vaf9R~
    int  intparm[FINDIP_MAX];	//display before,after line count  //~v43eR~
    int grepsw=0;                                                  //~v78dR~
#ifdef UTF8SUPPH                                                   //~va1GI~
    int repwordastsw=0;                                            //~va1GI~
    int swsameas=0;                                                //~va20R~
#endif                                                             //~va1GI~
#ifdef UTF8UCS2                                                    //~va20I~
    char utf8wk[sizeof(Sescrepchar)*UTF8_MAXCHARSZMAX];            //~va20R~
	int utf8len;                                                   //~va20I~
#endif                                                             //~va20I~
//*********************************                             //~5106I~
	pfc=Ppcw->UCWpfc;                                              //~v11sI~
	pfh=pfc->UFCpfh;                                               //~v11sI~
	if (Pbackward)                                              //~5302I~
    	psubcmdid=SUBCMD_PREV;                                  //~5302I~
    else                                                        //~5302I~
    	psubcmdid=0;			//                              //~5302I~
    Snotsrchsw=0;                                                  //~v41rI~
    Snotsrchsw2=0;                                                 //~v43wI~
    Sothopt&=SEARCH_DDSTR2;     //utf8 data for ddstr was set      //~va7bI~
	if (Popd)				//operand                           //~5106R~
	{                                                           //~5106I~
//  	UPARSERC(Popd,Popd,&opdno,0,",");	//parse out string(accept cr/lf)//~v09dR~
      orgopdno=                                                    //~v11pI~
    	opdno=Ppcw->UCWopdno;	//result of func_cmd,operand num   //~v09dI~
    	Popd=Ppcw->UCWopdpot;   //result of func_cmd,parse out tbl //~v09dI~
        pc=Popd;                                                //~5307I~
		for (ii=0;ii<MAXFCMDOPDNO && ii<opdno;ii++)                //~v0eBR~
		{                                                       //~5106I~
			opd[ii]=pc;                                         //~5307R~
			pc+=((int)strlen(pc)+1);                               //~v0eBR~
		}                                                       //~5106I~
        opdno=ii;	//max 4                                     //~5307I~
//      memcpy(odt,Ppcw->UCWopddelmt,(UINT)(sizeof(UPODELMTBL)*opdno));//~v0eBR~//~vb30R~
        memcpy(odt,Ppcw->UCWopddelmt,sizeof(UPODELMTBL)*(size_t)opdno);//~vb30I~
        memset(intparm,0,sizeof(intparm));                         //~v43eI~
//  	if (fcmdgetfindoption(Ppcw,Sexcludesw,Pchangeopt,&opdno,opd,odt,intparm,&Sfindopt))//get int parm//~v49bR~
//  	if (fcmdgetfindoption(Ppcw,Sexcludesw,Pchangeopt,&opdno,opd,odt,intparm,&Sfindopt))//get int parm//~v59ZR~
    	if (fcmdgetfindoption(Ppcw,Sexcludesw,Pchangeopt,&opdno,opd,odt,intparm,&Sfindopt,&Sfindopt2))//get int parm//~v59ZI~
        	return 4;                                              //~v437I~
        strncpy(Ssetlabel,opd[intparm[FINDIP_LABELOPDNO]]+2,sizeof(Ssetlabel)-1);   //save before fcmdoperandrearange//~v61hR~
//  	if (fcmdoperandrearange(Ppcw,Pchangeopt,&opdno,opd,odt,&rangeid1,&rangeid2,&Sothopt))//~v532R~
    	if (fcmdoperandrearange(Ppcw,Pchangeopt,&opdno,opd,odt,    //~v532I~
        		Sfindopt,intparm,	//chk option conflict          //~v58rR~
              &rangeid1,&rangeid2,&rangeid1and,&rangeid2and,&Sothopt))//~v532I~
        	return 4;                                              //~v0eBI~
	    podt1=odt;                 //1st opd delm tbl,assume it is search word//~v0eBR~
        grepsw= Sfindopt& FINDOPT_GREP;                            //~v78dR~
#ifdef REGEXSUPP                                                   //~v78qR~
        if (grepsw && UCBITCHK(pfh->UFHflag4,UFHF4BIN))            //~v78dR~
        	return errconflict("grep","binary file");              //~v78dR~
#else                                                              //~v78qR~
        if (grepsw)                                                //~v78qR~
        	return errnotsupported("-g option","This version");    //~v78qR~
#endif                                                             //~v78qR~
	}                                                           //~5106I~
    rc=0;                                                       //~5106I~
//  podt1=Ppcw->UCWopddelmt;	//1st opd delm tbl,assume it is search word//~v0eBR~
	switch(opdno)                                               //~5106I~
	{                                                           //~5106I~
	case 0:                                                     //~5106I~
//  	return errmissing();                                       //~v11kR~
    	return fcmdfindhelp(Pchangeopt,Sexcludesw);                //~v11kI~
	case 1:                                                     //~5106I~
		if (Pchangeopt)                                         //~5106I~
		{                                                       //~5106I~
			uerrmsg("Specify both Search and Replace string",   //~5106I~
					"探索文字列と置換文字列の両方を指定して下さい");//~5106I~
			return 4;                                           //~5106I~
		}                                                       //~5106I~
        if (Sexcludesw                                             //~v11pR~
//      &&  orgopdno==1                                            //~v40zR~
        &&  !podt1->upoquate)        //not "alll"(quatation)       //~v40pR~
          if (!stricmp(opd[0],"ALL")                               //~v40zR~
		  &&  orgopdno==1)                                         //~v40zI~
        	return RC_EXC_ALL;		//return 2	to special process to performance up//~v11pI~
//          else                                                   //~v40JR~
//          if ((!stricmp(opd[0],"=ALL")||!stricmp(opd[0],"ALL=")) //~v40JR~
//          &&  opdno==1)                                          //~v40JR~
//          {                                                      //~v40JR~
//            if (fcmdsetrange(Ppcw,0,1,rangeid1,rangeid2,&Srange1,&Srange2))//~v40JR~
//                return 4;                                        //~v40JR~
//            return RC_EXC_ALLSAME;  //return 3  to special process to performance up//~v40JR~
//          }                                                      //~v40JR~
        	                  		//and keep Ssrch value etc     //~v11pI~
		Ssubcmdid=psubcmdid;		//default may be find next  //~5302R~
		srchword=opd[0];                                        //~5106I~
		break;                                                  //~5106I~
	case 2:                                                     //~5106I~
		if (Pchangeopt)                                         //~5106I~
		{                                                       //~5106I~
			Ssubcmdid=psubcmdid;		//default may be change next//~5302R~
			srchword=opd[0];                                    //~5106I~
			repword=opd[1];                                     //~5106I~
		}                                                       //~5106I~
		else                                                    //~5106I~
			if (Pbackward)	//rev rfind                         //~5302R~
				rc=4;	//to many opd                           //~5106I~
			else                                                //~5106I~
            {                                                   //~5106I~
				sub1=opd[0];                                    //~5106I~
				sub2=opd[1];                                    //~5106I~
                podt2=podt1+1;              //sub2 delmtbl         //~v09dI~
            	rc=1;       //chk subcmdid                      //~5106R~
            }                                                   //~5106I~
		break;                                                  //~5106I~
	case 3:                                                     //~5106I~
		if (Pchangeopt)                                         //~5106I~
			if (Pbackward)	//rev rfind                         //~5302R~
				rc=4;	//to many opd                           //~5106I~
			else                                                //~5106I~
            {                                                   //~5106I~
				sub1=opd[0];                                    //~5106I~
				sub2=opd[2];                                    //~5106I~
                podt2=podt1+2;              //sub2 delmtbl         //~v09dI~
            	rc=1;       //chk subcmdid                      //~5106I~
            }                                                   //~5106I~
		else                                                    //~5106I~
			rc=4;                                               //~5106R~
		break;                                                  //~5106I~
    default:                                                    //~5106R~
        rc=4;                                                   //~5106I~
	}//by opdno                                                 //~5106R~
	if (rc==1)                                                  //~5106R~
	{                                                           //~5106I~
		subcmdid1=srchsubcmd(sub1);                             //~5114R~
		subcmdid2=srchsubcmd(sub2);                             //~5114R~
        if (subcmdid1 && subcmdid2)	//both subcmd                  //~v09dI~
        	if (!podt1->upoquate && podt2->upoquate)	//only 2nd is enclosed//~v09dR~
            	subcmdid2=0;		//1st is subcmd,2nd is search data//~v09dI~
		if (subcmdid2)	//"F xxxx prev"/"C xxx yyy all"         //~5106R~
		{                                                       //~5106R~
			rc=0;                                               //~5106I~
			srchword=opd[0];                                    //~5106R~
			repword =opd[1];                                    //~5106R~
			Ssubcmdid=subcmdid2;                                //~5106R~
		}                                                       //~5106R~
		else			//"F all  xxxx"/"C all xxx yyy"         //~5106R~
			if (subcmdid1)                                      //~5106I~
			{                                                   //~5106I~
				rc=0;                                           //~5106I~
				srchword=opd[1];                                //~5106R~
				repword =opd[2];                                //~5106R~
				Ssubcmdid=subcmdid1;                            //~5106I~
				podt1++;		//shift operand,2nd opd is search word//~v09dR~
			}                                                   //~5106I~
		if (!Pchangeopt)                                        //~5106I~
			repword ="";//null if find                          //~5106I~
	}//rc=1                                                     //~5106R~
    podt2=podt1+1;					//repword opd delm tbl         //~v09dR~
	if (rc)                                                     //~5106R~
    	return errtoomany();                                    //~v033I~
    if (!*srchword)                 //search word null             //~v10TI~
        if (!Sexcludesw)            //change,on dir,normal fined   //~v10TR~
    	{                                                          //~v10TI~
        	uerrmsg("Search string is not set yet",                //~v10TI~
    				"探索文字列が無効です");                       //~v10TI~
    		return 4;                                              //~v10TI~
        }                                                          //~v10TI~
//"x *= all"/"c *= chr all"                                        //~v40JI~
//  if (Sexcludesw                                                 //~v49bR~
//  &&  !memicmp(srchword,Seqsrchid,sizeof(Seqsrchid)-1)    //"*=" //~v49bR~
//  &&  Ssubcmdid==SUBCMD_ALL                                      //~v49bR~
//  &&  !podt1->upoquate)        //not enclosed by quate           //~v49bR~
//  {                                                              //~v49bR~
//  	Sminsame=atoi(srchword+sizeof(Seqsrchid)-1);               //~v49bR~
//      if (Ssubcmdid!=SUBCMD_ALL)                                 //~v49bR~
//      {                                                          //~v49bR~
//      	uerrmsg("\"all\" is required for \"*=\".",             //~v49bR~
//  				"\"*=\" 指定の時は all 指定が必要です");       //~v49bR~
//  		fcmd2saverestorx(0);	//restore for the case "x all"/"x=all"//~v49bR~
//          return 4;                                              //~v49bR~
//      }                                                          //~v49bR~
//      if (fcmdsetrange(Ppcw,0,1,rangeid1,rangeid2,&Srange1,&Srange2))//~v49bR~
//      {                                                          //~v49bR~
//          fcmd2saverestorx(0);    //restore for the case "x all"/"x=all"//~v49bR~
//          return 4;                                              //~v49bR~
//      }                                                          //~v49bR~
//      return RC_EXC_ALLSAME;  //return 3  to special process to performance up//~v49bR~
//  }                                                              //~v49bR~
    if (Ssubcmdid==SUBCMD_ALLKX)                                   //~v537I~
    {                                                              //~v539I~
	    if (Sexcludesw|| Ppcw->UCWtype==UCWTDIR)     //x cmd or on dir list//~v537I~
        {                                                          //~v537I~
            uerrmsg("\"allkx\" is not for dir-list or exclude cmd",0);//~v537R~
            return 4;                                              //~v537I~
        }                                                          //~v537I~
        if (Sfindopt & FINDOPT_JOIN)                               //~v539R~
        	return errconflict("-j","allkx");//duplicate           //~v539I~
    }                                                              //~v539I~
//  if (othopt & SEARCH_NOT)                                       //~v43wR~
    if (Sothopt & (SEARCH_NOT|SEARCH_NOT2))                        //~v43wR~
    {                                                              //~v54aI~
        if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                      //~v41rI~
        {                                                          //~v41rI~
//          uerrmsg("*! search is not avail for binary file",0);   //~v41rI~//~va0cR~
            uerrmsg("\"!\"(NOT) search is not avail for binary file",0);//~va0cI~
            return 4;                                              //~v41rI~
        }                                                          //~v41rI~
        else                                                       //~v41rI~
        {                                                          //~v43wI~
		  if (Sothopt & SEARCH_NOT)                                //~v43wR~
            Snotsrchsw=1;                                          //~v41rI~
		  if (Sothopt & SEARCH_NOT2)                               //~v43wI~
            Snotsrchsw2=1;                                         //~v43wI~
        }                                                          //~v43wI~
    }//not not2                                                    //~v54aI~
//  else                                                           //~v43wR~
//      Snotsrchsw=0;                                              //~v43wR~
//for 2nd word of *&                                               //~v43eI~
    Stabsrchsw2=0;              //once clear                       //~v43eI~
    Sescsrchlen2=0;             //once clear                       //~v43eI~
	Sulsrchsw2=0;                                                  //~v634I~
    *Ssrch2=0;                                                     //~v43eI~
    Ssrchlen2=0;                                                   //~v43eI~
    Seolsrchsw=0;					//1st word eol req id          //~v47BI~
    Seolsrchsw2=0;                //2nd word eol req id            //~v47BR~
    if (Sothopt & SEARCH_AND)                                      //~v43wR~
    {                                                              //~v43eI~
#ifdef REGEXSUPP                                                   //~v78qI~
      if (grepsw)                                                  //~v78dR~
      {                                                            //~v78dR~
    	srchword2=opd[opdno];   //fcm22 set after all opd for 2nd word of *&//~v78dR~
        if (fcmdgrepcomp(FCGCO_AND,Ppcw,srchword2,Pcasesw))        //~v78dR~
        	return 4;                                              //~v78dI~
        strcpy(Ssrch2,srchword2);                                  //~v78dR~
		Ssrchlen2=(int)strlen(Ssrch2);                             //~v78dR~
      }                                                            //~v78dR~
      else                                                         //~v78dR~
      {                                                            //~v78dR~
#endif                                                             //~v78qR~
    	if (rangeid2and==RANGEEOL)                                 //~v54ZR~
        	Seolsrchsw2=2;      //sw by eol option                 //~v54ZR~
    	srchword2=opd[opdno];	//fcm22 set after all opd for 2nd word of *&//~v43eI~
    	popdt12=odt+opdno;                                         //~v43eR~
        strcpy(Ssrch2,srchword2);                                  //~v43eI~
        if (!popdt12->upoquate)    //not enclosed                  //~v43eR~
        {                                                          //~v634I~
    		if (*srchword2=='\\')	//escape sequence              //~v43eI~
            {                                                      //~v43eI~
            	if ((rc=fcmdchkescseq(srchword2+1,Sescsrchchar2,0))<0)//esc seq chk err//~v43eI~
                  	return 4;                                      //~v43eI~
                if (rc)//esc seq char                              //~v43eI~
                {                                                  //~v43eI~
    				tabchkrc=fcmdesctabchk(0,pfh,Sescsrchchar2,rc);    //1 byte tabsearch//~v43eI~
                    if (tabchkrc<0)                                //~v43eI~
                    	return 4;                                  //~v43eI~
    				Stabsrchsw2=(UCHAR)tabchkrc;                   //~v43eI~
                    Sescsrchlen2=(char)rc;                         //~v43eI~
				}//esc specified                                   //~v43eI~
            }                                                      //~v43eI~
          	if (!Pchangeopt         //search                       //~v634I~
		  	&&  Ppcw->UCWtype==UCWTFILE)    //on file scr          //~v634I~
            {                                                      //~v634I~
          		if (!stricmp(srchword2,Sgrepsrchid))    //search err line//~v634R~
	        		Sulsrchsw2=LINE_GREPSEARCH;                    //~v634I~
          	}                                                      //~v634I~
#ifdef UTF8SUPPH                                                   //~va1GI~
            if (!stricmp(srchword2,SRCHIDS_UTF8ECH) //search err line//~va1GR~
            )                                                      //~va1GI~
	        	Sothopt|=SEARCH_UTF8ECH2;                          //~va1GR~
#endif                                                             //~va1GI~
        }//not enclosed in quote                                   //~v634I~
  		if (Sescsrchlen2) 				//tab search req           //~v43eI~
    		Ssrchlen2=Sescsrchlen2;                                //~v43eI~
  		else                                                       //~v43eI~
        {                                                          //~v47BI~
          if (!Seolsrchsw2)	//no EOL option                        //~v54ZI~
          {                                                        //~v54ZI~
           if (!popdt12->upoquate)   //not enclosed                //~v550I~
           {                                                       //~v550I~
			if (!strcmp(Ssrch2,EOLSRCHIDANY))	//  *\n            //~v54zR~
            	strcpy(Ssrch2,EOLSRCHID);		//drop preceding * //~v54zI~
            else                                                   //~v54zI~
			if (!strcmp(Ssrch2,EOLSRCHIDAST))	//  "*"\n          //~v54zR~
            	strcpy(Ssrch2,EOLSRCHIDANY);	// search *\n      //~v54zI~
           }                                                       //~v54ZR~
          }//no EOL option                                         //~v54ZI~
			Ssrchlen2=(int)strlen(Ssrch2);                         //~v43eI~
          if (!Seolsrchsw2)	//no EOL option                        //~v54ZI~
          {                                                        //~v54ZI~
        	if (!popdt12->upoquate    //not enclosed               //~v47BI~
			&&  Ppcw->UCWtype==UCWTFILE    //on file scr           //~v47BI~
//          &&  Ssrchlen2>EOLIDLEN                                 //~v54zR~
            &&  Ssrchlen2>=EOLIDLEN                                //~v54zI~
            &&  !memcmp(Ssrch2+Ssrchlen2-EOLIDLEN,EOLSRCHID,EOLIDLEN))//~v47BI~
            {                                                      //~v47BI~
        		if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))              //~v47BI~
                {                                                  //~v47BI~
                	Ssrchlen2--;                                   //~v47BI~
            		*(Ssrch2+Ssrchlen2-1)='\n';                    //~v47BI~
            		*(Ssrch2+Ssrchlen2)=0;                         //~v47BI~
                }                                                  //~v47BI~
                else                                               //~v47BI~
                {                                                  //~v47BI~
            		Seolsrchsw2=1;                                 //~v47BR~
                	Ssrchlen2-=EOLIDLEN;                           //~v47BR~
            		*(Ssrch2+Ssrchlen2)=0;                         //~v47BR~
                }                                                  //~v47BI~
            }                                                      //~v47BI~
          }//no EOL option                                         //~v54ZI~
#ifdef UTF8SUPPH                                                   //~va1qI~
//        if (fcmdgetescsrchword(Sothopt & (SEARCH_UCS2|SEARCH_UCSBE2),Ppcw,Ssrch2,Sescsrchchar2,&Ssrchlen2,&Sescsrchlen2)>1) 	//2nd word by ucs//~va0cR~//~va0yR~
#ifdef UTF8UCS2                                                    //~va20I~
//        if (fcmdgetescsrchword((Sothopt & (SEARCH_UCS2|SEARCH_UCSBE2|SEARCH_UTF82))|SEARCH_AND,Ppcw,Ssrch2,Sescsrchchar2,&Ssrchlen2,&Sescsrchlen2)>1) 	//2nd word by ucs//~va20I~//~vax1R~
          if (fcmdgetescsrchword((Sothopt & (SEARCH_UCS2|SEARCH_UCSBE2|SEARCH_UTF82|SEARCH_UCS4SW2))|SEARCH_AND,Ppcw,Ssrch2,Sescsrchchar2,&Ssrchlen2,&Sescsrchlen2)>1) 	//2nd word by ucs//~vax1R~
#else                                                              //~va20I~
          if (fcmdgetescsrchword(Sothopt & (SEARCH_UCS2|SEARCH_UCSBE2|SEARCH_UTF82),Ppcw,Ssrch2,Sescsrchchar2,&Ssrchlen2,&Sescsrchlen2)>1) 	//2nd word by ucs//~va0yR~
#endif                                                             //~va20I~
            	return 4;                                          //~va0cI~
#endif                                                             //~va1qI~
        }	//not esc search                                       //~v47BI~
#ifdef REGEXSUPP                                                   //~v78qR~
      }//not grep                                                  //~v78dR~
#endif                                                             //~v78qR~
    }//2nd str of *&                                               //~v43eI~
//*set search string                                            //~5106I~
//  if (strcmp(srchword,"*"))                                      //~v09dR~
#ifdef REGEXSUPP                                                   //~v78qI~
  if (grepsw)                                                      //~v78dR~
  {                                                                //~v78dR~
    if (fcmdgrepcomp(0,Ppcw,srchword,Pcasesw))                     //~v78dR~
    	return 4;                                                  //~v78dI~
  	Stabsrchsw=0;                                                  //~v78dR~
    Sescsrchlen=0;                                                 //~v78dR~
	Sulsrchsw=0;                                                   //~v78dR~
	strcpy(Ssrch,srchword);	//search string update                 //~v78dR~
  }                                                                //~v78dR~
  else                                                             //~v78dR~
  {                                                                //~v78dR~
#endif                                                             //~v78qR~
    if (strcmp(srchword,"*") || podt1->upoquate)                   //~v09IR~
    {                                                              //~v09II~
    	Stabsrchsw=0;				//once clear                   //~v09II~
    	Sescsrchlen=0;				//once clear                   //~v09OR~
//  	strcpy(Ssrch,srchword);	//search string update             //~v0hBR~
        if (!Pchangeopt         //search                           //~v09eI~
        &&  !podt1->upoquate    //not enclosed                     //~v09eI~
        &&  !stricmp(srchword,Sulsrchid))	//search update line   //~v0ilR~
        {                                                          //~vagaI~
        	Sulsrchsw=1;                                           //~v09eI~
			strcpy(Ssrch,srchword);	//after "f *\n" *Ssrch=0,so next "i *e" and Rfind fail by "enetr Find cmd at first"//~vagaI~
        }                                                          //~vagaI~
		else                                                       //~v09eI~
          if (!Pchangeopt         //search                         //~v0bqR~
          &&  !podt1->upoquate    //not enclosed                   //~v0bqR~
          &&  !stricmp(srchword,Selsrchid))    //search err line   //~v0ilR~
          {                                                        //~vagaI~
        	Sulsrchsw=2;                                           //~v0bqR~
			strcpy(Ssrch,srchword);	//after "f *\n" *Ssrch=0,so next "i *e" and Rfind fail by "enetr Find cmd at first"//~vagaI~
          }                                                        //~vagaI~
          else                                                     //~v496I~
		  if (Ppcw->UCWtype==UCWTFILE    //on file scr             //~v49bI~
          &&  !podt1->upoquate    //not enclosed                   //~v49bI~
          &&  !memicmp(srchword,Seqsrchid,sizeof(Seqsrchid)-1))    //*=//~v49bR~
          {                                                        //~v49bI~
           if (toupper(*(srchword+sizeof(Seqsrchid)-1))==MATCHINGID)   //*=M//~v62fR~
           {                                                       //~v62dI~
	        	Sulsrchsw=LINE_SAMEMATCH;                          //~v62dI~
                if (Sothopt & SEARCH_AND)                          //~v62fR~
                {                                                  //~v62dI~
                    uerrmsg("%s%c(matching) is invalid with \"&\".",//~v62fR~
                            "%s%c(マッチング)は \"&\"とは指定できません。",//~v62fR~
                            Seqsrchid,MATCHINGID);                 //~v62fR~
                    return 4;                                      //~v62dI~
                }                                                  //~v62dI~
                if (Pchangeopt)                                    //~v62dI~
                {                                                  //~v62dI~
                    uerrmsg("%s%c(matching) is invalid for Change cmd.",//~v62fR~
                            "%s%c(マッチング)は 置換コマンドでは指定できません。",//~v62fR~
                            Seqsrchid,MATCHINGID);                 //~v62fR~
                    return 4;                                      //~v62dI~
                }                                                  //~v62dI~
	    		Sminsame=atoi(srchword+sizeof(Seqsrchid));//key position//~v62fI~
                if (Sminsame)                                      //~v62fI~
                    Sminsame--;                                    //~v62fI~
                Spfhmatching=fcmdget2ndpfh(Ppcw,Smatchingid);      //~v62fR~
                if (!Spfhmatching)                                 //~v62dI~
                    return 8;                                      //~v62dI~
				strcpy(Ssrch,srchword);	//search string update     //~v62dI~
           }                                                       //~v62dI~
           else                                                    //~v62dI~
           {                                                       //~v62dI~
    		if (Sothopt & (SEARCH_AND|SEARCH_NOT))                 //~v49bR~
            {                                                      //~v49bI~
        		uerrmsg("%s(same line search) is invalid with \"&\" or \"!\".",//~v49bR~
    					"%s(重複行探索)は \"&\",\"!\" とは指定できません。",//~v49bR~
						Seqsrchid);                                //~v49bI~
	    		return 4;                                          //~v49bI~
            }                                                      //~v49bI~
    		Sminsame=atoi(srchword+sizeof(Seqsrchid)-1);           //~v49bI~
			strcpy(Ssrch,srchword);	//search string update         //~v49bI~
        	Sulsrchsw=LINE_SAMESRCH;                               //~v49bI~
           }                                                       //~v62dI~
          }                                                        //~v49bI~
		  else                                                     //~v49bI~
          if (!Pchangeopt         //search                         //~v496I~
		  &&  Ppcw->UCWtype==UCWTFILE    //on file scr             //~v496I~
          &&  !podt1->upoquate    //not enclosed                   //~v496I~
          &&  !stricmp(srchword,Sllsrchid))    //search err line   //~v496I~
          {                                                        //~v496I~
    		if (Sothopt & SEARCH_AND)                              //~v496I~
            {                                                      //~v496I~
        		uerrmsg("%s(line research) is invalid with \"&\".",//~v496I~
    					"%s(行再探索)は \"&\" とは指定できません。",//~v496I~
						Sllsrchid);                                //~v496I~
	    		return 4;                                          //~v496I~
            }                                                      //~v496I~
        	Sulsrchsw=LINE_RESEARCH;                               //~v496R~
          }                                                        //~v496I~
		  else	                                                   //~v0bqR~
          if (!Pchangeopt         //search                         //~v632I~
		  &&  Ppcw->UCWtype==UCWTFILE    //on file scr             //~v632I~
          &&  !podt1->upoquate    //not enclosed                   //~v632I~
          &&  !stricmp(srchword,Sgrepsrchid))    //search err line //~v632I~
          {                                                        //~v632I~
        	Sulsrchsw=LINE_GREPSEARCH;                             //~v632I~
          }                                                        //~v632I~
		  else                                                     //~v632I~
          {                                                        //~v0hBI~
		    Sulsrchsw=0;		//once reset                       //~v09eI~
			strcpy(Ssrch,srchword);	//search string update         //~v0hBI~
#ifdef UTF8SUPPH                                                   //~va1GM~
          	if (!podt1->upoquate    //not enclosed                 //~va1GI~
          	&&  !stricmp(srchword,SRCHIDS_UTF8ECH) //search err line//~va1GI~
          	)                                                      //~va1GI~
	        	Sothopt|=SEARCH_UTF8ECH;                           //~va1GI~
#endif                                                             //~va1GM~
		  }	                                                       //~v0hBI~
        if (!podt1->upoquate)    //not enclosed                    //~v09II~
//      	if (*srchword=='*')                                    //~v0bsR~
//          {                                                      //~v0bsR~
//  			if (*(srchword+1)=='\\')	//escape sequence      //~v0bsR~
    			if (*srchword=='\\')	//escape sequence          //~v0bsI~
                {                                                  //~v09II~
//                if ((rc=fcmdchkescseq(srchword+2,Sescsrchchar))<0)//esc seq chk err//~v0apR~
//                if ((rc=fcmdchkescseq(srchword+2,Sescsrchchar,0))<0)//esc seq chk err//~v0bsR~
                  if ((rc=fcmdchkescseq(srchword+1,Sescsrchchar,0))<0)//esc seq chk err//~v0bsI~
                  	return 4;                                      //~v09NI~
                  if (rc)//esc seq char                            //~v09NI~
                  {                                                //~v09LI~
//					if (!stricmp(srchword+2,"T"))	//search update line//~v09LR~
//*                 if (Sescsrchchar[0]==TABCHAR)                  //~v11sR~
//*                 {                                              //~v11sR~
//  			        if (Ppcw->UCWtype==UCWTDIR)     //on dir list//~v09LR~
//                      {                                          //~v09LR~
//              			uerrmsg("Tab search not avail on this panel.",//~v09LR~
//              					"この画面でタブ検索は出来ません");//~v09LR~
//  						return 4;                              //~v09LR~
//                      }                                          //~v09LR~
//* 					Stabsrchsw=1;				//tab search req//~v11sR~
//  					Sescseqsrch=1;				//tab search req//~v09LR~
//* 				}                                              //~v11sR~
    				tabchkrc=fcmdesctabchk(0,pfh,Sescsrchchar,rc);    //1 byte tabsearch//~v11sI~
                    if (tabchkrc<0)                                //~v11sI~
                    	return 4;                                  //~v11sI~
    				Stabsrchsw=(UCHAR)tabchkrc;                    //~v11sR~
                    Sescsrchlen=(char)rc;                          //~v09OR~
//  				sprintf(Ssrch,"0x%02X",(UINT)(UCHAR)*Sescsrchchar);//~v0apR~
//                  if (Sescsrchlen>1)                             //~v0apR~
//  					sprintf(Ssrch+4,"%02X",(UINT)(UCHAR)*(Sescsrchchar+1));//~v0apR~
				  }//esc specified                                 //~v09LI~
                }                                                  //~v09II~
//          }//*srchword=="*"                                      //~v0bsR~
    }                                                              //~v09IR~
    else					//F *                                  //~v09IR~
    {                                                              //~va20I~
    	if (!*Ssrch)                                               //~v09IR~
    	{                                                          //~v09IR~
        	uerrmsg("Search string is not set yet",                //~v09IR~
    				"探索文字列が設定されていません");             //~v09IR~
    		return 4;                                              //~v09IR~
    	}                                                          //~v09IR~
        swsameas|=SEARCH_SAMEAS;                                   //~va20I~
    }                                                              //~va20I~
#ifdef REGEXSUPP                                                   //~v78qI~
  }//not grep                                                      //~v78dR~
#endif                                                             //~v78qR~
    if (Sulsrchsw2)                                                //~v634I~
    {                                                              //~v634I~
    	if (Sulsrchsw!=Sulsrchsw2)                                 //~v634I~
        {                                                          //~v634I~
        	uerrmsg("1st and 2nd of & search shuld be same for %s",//~v634I~
    				"&探索の2番目で%sを使用するときは1番目も同じでなければなりません。",//~v634I~
                    srchword2);                                    //~v634I~
    		return 4;                                              //~v634I~
        }                                                          //~v634I~
    }                                                              //~v634I~
  if (Pchangeopt)                                                  //~v09JI~
  {                                                                //~v54aI~
//  if (strcmp(repword,"*"))                                       //~v09dR~
    if (strcmp(repword,"*") || podt2->upoquate)                    //~v09dR~
    {                                                              //~v09II~
		strcpy(Srepword,repword);	//search string update      //~5106I~
        Srepnull=0;                                                //~v09LI~
        Stabrepsw=0;  				//repword contain tab          //~v0apI~
    	Sescreplen=0;				//esc repl word len            //~v09OR~
    	if (podt2->upoquate                                        //~v09LI~
        &&  !*Srepword)                                            //~v09LI~
            Srepnull=1;                                            //~v09LM~
        if (!podt2->upoquate)    //not enclosed                    //~v09OR~
//      	if (*repword=='*')                                     //~v0bsR~
//  			if (*(repword+1)=='\\')	//escape sequence          //~v0bsR~
    			if (*repword=='\\')	//escape sequence              //~v0bsI~
                {                                                  //~v09II~
//                if ((rc=fcmdchkescseq(repword+2,Sescrepchar))<0)//rep,esc seq chk//~v0apR~
//                if ((rc=fcmdchkescseq(repword+2,Sescrepchar,1))<0)//rep,esc seq chk//~v0bsR~
                  if ((rc=fcmdchkescseq(repword+1,Sescrepchar,1))<0)//rep,esc seq chk//~v0bsI~
                  	return 4;                                      //~v09OI~
                  if (rc)                                          //~v09OI~
                  {                                                //~v09OI~
//                  if (rc==1)      //1 byte input                 //~v0apR~
//  		        	if (Gvalidchartbl[*Sescrepchar])           //~v0apR~
//  	    	            return funcinhibitkey(*Sescrepchar);   //~v0apR~
//					if (!stricmp(repword+2,"T"))	//search update line//~v09OR~
                                                                   //~v11sI~
//*                 for (ii=0;ii<rc;ii++)                          //~v11sR~
//*                     if (Sescrepchar[ii]==TABCHAR)              //~v11sR~
//*                     {                                          //~v11sR~
//*                         Stabrepsw=1;                           //~v11sR~
//*                         break;                                 //~v11sR~
//*                     }                                          //~v11sR~
    				Stabrepsw=(UCHAR)fcmdesctabchk(1,pfh,Sescrepchar,rc);    //1 byte tabsearch//~v11sR~
                                                                   //~v11sI~
//					if (Sescrepchar[0]==TABCHAR)	//search update line//~v0apR~
  					if (Stabrepsw)                                 //~v0apI~
                    {                                              //~v09II~
			        	if (Sulsrchsw==LINE_SAMESRCH)              //~v49bI~
                    	{                                          //~v49bI~
                        	uerrmsg("Tab is not avail as replace word for *= search.",//~v49bI~
                    				"*=探索の置換文字列はタブを含むことはできません");//~v49bI~
                    		return 4;                              //~v49bI~
                    	}                                          //~v49bI~
//                  	if (Stabsrchsw)                            //~v0apR~
                    	if (Stabsrchsw && rc ==1)                  //~v0apI~
                    	{                                          //~v09II~
                        	uerrmsg("Tab to Tab change request",   //~v09II~
                    				"タブからタブへの同じ置換要求です");//~v09II~
                    		return 4;                              //~v09II~
                    	}                                          //~v09II~
//                      *Srepword=' ';                             //~v0apR~
//                      *(Srepword+1)=0;                           //~v0apR~
//  					Sescseqrep=1;				//tab search req//~v09OR~
                    }                                              //~v09II~
    				Sescreplen=(char)rc;			//tab search req//~v09OR~
                  }//esc char                                      //~v09OI~
                }                                                  //~v09II~
	}                                                              //~v09II~
	else					//F *                               //~5106I~
    {                                                              //~va1GI~
    	if (!stricmp(repword,SRCHIDS_UTF8ECHR))	//change reset option  without quotation//~va1GR~
        {                                                          //~va1GI~
       		repwordastsw=1;                                        //~va1GI~
            strcpy(Srepword,SRCHIDS_UTF8ECHR);                     //~va1GI~
        }                                                          //~va1GI~
      if (!Srepnull)                                               //~v09JI~
		if (!*Srepword)                                         //~5106I~
		{                                                       //~5106I~
			uerrmsg("Replace string is not set yet",            //~5106I~
					"置換文字列が設定されていません");          //~5106I~
			return 4;                                           //~5106I~
		}                                                       //~5106I~
    }                                                              //~va1GI~
#ifdef UTF8UCS2                                                    //~va20I~
	if (!Sescreplen)	//no esc repword                           //~va20I~
    {                                                              //~va20I~
//      fcmdcvl2fsrchstr(SEARCH_CHANGE,Ppcw,Srepword,strlen(Srepword),utf8wk,sizeof(utf8wk),&utf8len);//~va20R~//~vb30R~
        fcmdcvl2fsrchstr(SEARCH_CHANGE,Ppcw,Srepword,(int)strlen(Srepword),utf8wk,(int)sizeof(utf8wk),&utf8len);//~vb30R~
//      utf8len=min(sizeof(Sescrepchar)-1,utf8len);                //~va20I~//~vb30R~
        utf8len=min((int)sizeof(Sescrepchar)-1,utf8len);           //~vb30I~
//      UmemcpyZ(Sescrepchar,utf8wk,utf8len);                      //~va20I~//~vb30R~
        UmemcpyZ(Sescrepchar,utf8wk,(size_t)utf8len);              //~vb30I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
  }//chng opt                                                      //~v54aI~
//*set start line/column by subcmd                              //~5106I~
    if (rangeid2==RANGEEOL)                                        //~v54ZR~
    	Seolsrchsw=2;                                              //~v54ZR~
  if (Sescsrchlen) 				//tab search req                   //~v09OR~
    Ssrchlen=Sescsrchlen;                                          //~v09OR~
  else                                                             //~v09II~
  {                                                                //~v47BI~
   if (!Seolsrchsw)	//no EOL option                                //~v54ZI~
   {                                                               //~v54ZI~
    if (!podt1->upoquate)   //not enclosed                         //~v550I~
    {                                                              //~v550I~
      if (!strcmp(Ssrch,EOLSRCHIDANY))    //  *\n                  //~v54zR~
          strcpy(Ssrch,EOLSRCHID);        //drop preceding *       //~v54zI~
      else                                                         //~v54zI~
      if (!strcmp(Ssrch,EOLSRCHIDAST))    //  "*"\n                //~v54zR~
          strcpy(Ssrch,EOLSRCHIDANY);     //drop preceding *       //~v54zI~
    }                                                              //~v550I~
   }//no EOL                                                       //~v54ZI~
	Ssrchlen=(int)strlen(Ssrch);                                //~5106I~
   if (!Seolsrchsw)	//no EOL option                                //~v54ZI~
   {                                                               //~v54ZI~
      if (!podt1->upoquate    //not enclosed                       //~v47BR~
	  &&  Ppcw->UCWtype==UCWTFILE    //on file scr                 //~v47BI~
//    &&  Ssrchlen>EOLIDLEN                                        //~v54zR~
      &&  Ssrchlen>=EOLIDLEN                                       //~v54zI~
      &&  !memcmp(Ssrch+Ssrchlen-EOLIDLEN,EOLSRCHID,EOLIDLEN))     //~v47BI~
      {                                                            //~v47BI~
          if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                    //~v47BI~
          {                                                        //~v47BI~
            Ssrchlen--;                                            //~v47BI~
            *(Ssrch+Ssrchlen-1)='\n';                              //~v47BI~
            *(Ssrch+Ssrchlen)=0;                                   //~v47BI~
          }                                                        //~v47BI~
          else                                                     //~v47BI~
          {                                                        //~v47BI~
          	Seolsrchsw=1;                                          //~v47BR~
          	Ssrchlen-=EOLIDLEN;                                    //~v47BR~
          	*(Ssrch+Ssrchlen)=0;                                   //~v47BR~
            if (!Ssrchlen && Pchangeopt)                           //~v54zR~
            {	                                                   //~v54zI~
				uerrmsg("EndOfLine can not be replaced.",          //~v54zI~
						"行末は置換出来ません。");                 //~v54zI~
				return 4;                                          //~v54zI~
            }                                                      //~v54zI~
          }                                                        //~v47BI~
      }                                                            //~v47BI~
   }//no EOL                                                       //~v54ZI~
#ifdef UTF8SUPPH                                                   //~va1qI~
//  if (fcmdgetescsrchword(Sothopt & (SEARCH_UCS|SEARCH_UCSBE),Ppcw,Ssrch,Sescsrchchar,&Ssrchlen,&Sescsrchlen)>1) 	//1st word by ucs2//~va0cR~//~va0yR~
#ifdef UTF8UCS2                                                    //~va20I~
//  if (fcmdgetescsrchword((Sothopt & (SEARCH_UCS|SEARCH_UCSBE|SEARCH_UTF8))|swsameas,Ppcw,Ssrch,Sescsrchchar,&Ssrchlen,&Sescsrchlen)>1) 	//1st word by ucs2//~va20I~//~vax1R~
    if (fcmdgetescsrchword((Sothopt & (SEARCH_UCS|SEARCH_UCSBE|SEARCH_UTF8|SEARCH_UCS4SW))|swsameas,Ppcw,Ssrch,Sescsrchchar,&Ssrchlen,&Sescsrchlen)>1) 	//1st word by ucs2//~vax1R~
#else                                                              //~va20I~
    if (fcmdgetescsrchword(Sothopt & (SEARCH_UCS|SEARCH_UCSBE|SEARCH_UTF8),Ppcw,Ssrch,Sescsrchchar,&Ssrchlen,&Sescsrchlen)>1) 	//1st word by ucs2//~va0yR~
#endif                                                             //~va20I~
    	return 4;                                                  //~va0cR~
    if (Pchangeopt         //change cmd                            //~va1GI~
    &&  Sothopt & SEARCH_UTF8ECH)                                  //~va1GI~
        if (repwordastsw)                                          //~va1GI~
            Sothopt|=SEARCH_UTF8ECHR;   //reset ech                //~va1GI~
#endif                                                             //~va1qI~
  }   //not esc search                                             //~v47BI~
  if (Sescreplen) 				//tab search req                   //~v09OR~
    Srepwordlen=Sescreplen;                                        //~v09OR~
  else                                                             //~v09II~
  {                                                                //~v79LR~
	Srepwordlen=(int)strlen(Srepword);                          //~5106I~
    if (Sfindopt & FINDOPT_GREPPTARGET)   //change target is P'..' pattern//~v79LR~
        Srepwordlen-=3;    //net len enclosed                      //~v79LR~
  }                                                                //~v79LR~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw4R~
#ifdef UTF8UCS416                                                  //~vaw4I~
//    if (Sothopt & SEARCH_UCS4)                                     //~va3xI~//~vax1R~
//        if (!Pchangeopt || !Sescreplen)                            //~va3xI~//~vax1R~
//        {                                                          //~va3xI~//~vax1R~
//            uerrmsg("%s (UCS4) option is for replace string by \\x notation",0,//~va3xI~//~vax1R~
//                    STR_SEARCH_UCS4);                              //~va3xI~//~vax1R~
//            return 4;                                              //~va3xI~//~vax1R~
//        }                                                          //~va3xI~//~vax1R~
#endif                                                             //~va1CI~//~va3xI~
//  if (fcmdsetrange(Ppcw,Sulsrchsw,	//*u or *e                 //~v0eBR~//~vbc1R~
    if (fcmdsetrange(Ppcw,Sulsrchsw,Ssrch,	//*u or *e             //~vbc1I~
					Ssrchlen,rangeid1,rangeid2,&Srange1,&Srange2)) //~v0eHR~
    	return 4;                                                  //~v0eBI~
    Sfindopt&=~(FINDOPT_DIRATTR|FINDOPT_DIRATTRAND);               //~vbc1I~
    Sfindopt&=~(FINDOPT_DIRTS|FINDOPT_DIRTSAND);                   //~vbc2I~
    if (rangeid2==RANGEATTR)                                       //~vbc1R~
    {                                                              //~vbc1I~
    	Sfindopt|=FINDOPT_DIRATTR;                                 //~vbc1I~
    }                                                              //~vbc1I~
    if (rangeid2==RANGETS)                                         //~vbc2I~
    {                                                              //~vbc2I~
    	Sfindopt|=FINDOPT_DIRTS;                                   //~vbc2I~
    }                                                              //~vbc2I~
//  if (Ssrchlen2)             //*&                                //~v54zR~
//  if (Ssrchlen2||Seolsrchsw2)//*&                                //~v62dR~
    if (Ssrchlen2||Seolsrchsw2 //*&                                //~v62dI~
    ||  Sulsrchsw==LINE_SAMEMATCH)//matching                       //~v62dR~
    {                                                              //~v532I~
//      if (fcmdsetrange(Ppcw,Sulsrchsw,    //*u or *e             //~v532I~//~vbc1R~
        if (fcmdsetrange(Ppcw,Sulsrchsw,Ssrch2,    //*u or *e      //~vbc1I~
                        Ssrchlen2,rangeid1and,rangeid2and,&Srange1and,&Srange2and))//~v532I~
            return 4;                                              //~v532I~
	    if (rangeid2and==RANGEATTR)                                //~vbc1R~
    	{                                                          //~vbc1I~
    		Sfindopt|=FINDOPT_DIRATTRAND;                          //~vbc1I~
    	}                                                          //~vbc1I~
	    if (rangeid2and==RANGETS)                                  //~vbc2I~
    	{                                                          //~vbc2I~
    		Sfindopt|=FINDOPT_DIRTSAND;                            //~vbc2I~
    	}                                                          //~vbc2I~
    }                                                              //~v532I~
    if (Sfindopt & FINDOPT_SETLABEL)                               //~v61hI~
    {                                                              //~v61hI~
    	if (Ssubcmdid==SUBCMD_ALL||Ssubcmdid==SUBCMD_ALLKX)        //~v61hI~
            return errconflict("-l",0);//0:conflict with other option//~v61hI~
    }                                                              //~v61hI~
	Srangeid1=rangeid1;                                            //~v0eHI~
	Srangeid2=rangeid2;                                            //~v0eHI~
	Srangeid1and=rangeid1and;                                      //~v532I~
	Srangeid2and=rangeid2and;                                      //~v532I~
	Slinebefore=intparm[FINDIP_BEFORE];                            //~v43eR~
	Slineafter =intparm[FINDIP_AFTER];                             //~v43eR~
	Slinedist  =intparm[FINDIP_DISTANCE];                          //~v43eI~
	return 0;                                                   //~5106I~
}//operandchk                                                   //~5106I~
//**************************************************************** //~v11sI~
//!fcmdesctabchk                                                   //~v11sI~
//* tab chk in srch/rep string                                     //~v11sR~
//* parm1 :opt 0:search char, 1:rep char                           //~v11sI~
//* parm2 :pfh                                                     //~v11sI~
//* parm3 :esc string                                              //~v11sI~
//* parm4 :len                                                     //~v11sI~
//*rc     :1:tab contained except (len>1 and text file)            //~v11sR~
//*        0:no tab found                                          //~v11sR~
//		  -1:len >1 tab containing string for text file            //~v11sI~
//**************************************************************** //~v11sI~
int fcmdesctabchk(int Popt,PUFILEH Ppfh,UCHAR *Pstring,int Plen)   //~v11sR~
{                                                                  //~v11sI~
	int ii;                                                        //~v11sI~
	UCHAR *pc;                                                     //~v11sI~
#ifdef UTF8UCS2                                                    //~va20I~
    int ddlen;                                                     //~va20R~
    UCHAR wkdd[sizeof(Grepworddd)],wkdbcs[sizeof(Grepworddd)];     //~va20I~
#endif                                                             //~va20I~
//************************                                         //~v11sI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	if (PFH_ISEBC(Ppfh))	//no TAB process fot ebc file          //~va50I~
    	return 0;                                                  //~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
    for (ii=0,pc=Pstring;ii<Plen;ii++,pc++)                        //~v11sI~
        if (*pc==TABCHAR)                                          //~v11sI~
            break;                                                 //~v11sI~
	if (ii==Plen)          //no tab found                          //~v11sI~
    	return 0;                                                  //~v11sI~
	if (Plen==1)			//only 1 byte TAB                      //~v11sI~
    	return 1;                                                  //~v11sI~
	if (UCBITCHK(Ppfh->UFHflag4,UFHF4BIN))                         //~v11sM~
    	return 1;		//normal esc search will be done           //~v11sI~
    if (Popt)				//rep char                             //~v11sI~
    {                                                              //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
    	if (FILEUTF8MODE(Ppfh))                                    //~va20I~
        {                                                          //~va20I~
			if (fcmdcvesc2dd(0,Pstring,Plen,wkdd,wkdbcs,sizeof(wkdd),&ddlen))//~va20R~
            	return -1;                                         //~va20I~
		  	if (utfddmemchr(0,wkdd,wkdbcs,TABCHAR,ddlen))          //~va20R~
            	return 1;                                          //~va20I~
            else                                                   //~va20I~
            	return 0;                                          //~va20I~
        }                                                          //~va20I~
#endif                                                             //~va20I~
    	return 1;			//contain tab                          //~v11sI~
    }                                                              //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
    if (FILEUTF8MODE(Ppfh))                                        //~va20I~
    	return 0;	//assume part of ucs2                          //~va20I~
#endif                                                             //~va20I~
    uerrmsg("Only single byte Tab(0x09) is avail for search in Text file",//~v11sR~
            "テキストファイルではタブ(0x09)探索指定は1バイト指定のみ");//~v11sR~
    return -1;                                                     //~v11sI~
}//fcmdesctabchk                                                   //~v11sI~
#ifdef UTF8SUPPH                                                   //~va1qI~
//**************************************************************** //~va0cI~
//!fcmgetescsrchword                                               //~va0cR~
//search by locale code(utf8->locale if utf8code)                  //~va0cR~
//by Unicoed option ,translate locale to unicode(UCS2)             //~va0cI~
//*rc: 1:set esc srch word,4 err                                   //~va0cI~
//**************************************************************** //~va0cI~
int fcmdgetescsrchword(int Popt,PUCLIENTWE Ppcw,char *Psrch,UCHAR *Pescsrch,int *Ppsrchlen,UCHAR *Ppescsrchlen)//~va0cR~
{                                                                  //~va0cI~
	int opt,rc,outlen/*,lclen*/,srchlen;                           //~va1vR~
//  char *plc;                                                     //~va1vR~
    char utf8wk[sizeof(Sescsrchchar)*UTF8_MAXCHARSZMAX];           //~va50R~
    UCHAR *pu8;                                                    //~va50I~
#ifdef AAA                                                         //~va1vI~
    char lcwk[MAXCOLUMN*UTF8_F2LMAXRATE];                          //~va1gR~
#endif                                                             //~va1vI~
//************************                                         //~va0cI~
	srchlen=*Ppsrchlen;                                            //~va0cI~
    if (Popt & (SEARCH_UTF8|SEARCH_UTF82)) //cv to utf8            //~va0yR~
 	{                                                              //~va0yR~
#ifdef AAA                                                         //~va1vI~
		plc=xeutf_getlocalestr(Psrch,srchlen,Pescsrch,sizeof(Sescsrchchar),&lclen,0/*pcharcnt*/);//~va0yR~
		if (XEUTFGLRC_ISALLASCII(plc)) /*utf8->locale conversion NOT done*///~va1gI~
        	return 0;                                              //~va1gI~
		if (!XEUTFGLRC_ISF2L(plc)) /*utf8->locale conversion NOT done*///~va0yR~
        {                                                          //~va0yR~
//      	opt=XEUTFCVO_STRZ;                                     //~va0yR~//~va1gR~
        	opt=XEUTFCVO_STRZ|XEUTFCVO_OUTPARM;                    //~va1gI~
            pu8=utf8wk;                                            //~va0yR~
			if (!xeutf_islocalestr(opt,Psrch,srchlen,&pu8,&outlen))//~va0yR~
	        {                                                      //~va0yR~
    	        uerrmsg("translation to UTF8 failed for \"%s\"",0, //~va0yR~
        	            Psrch);                                    //~va0yR~
            	return 4;                                          //~va0yR~
        	}                                                      //~va0yR~
        	outlen=min(outlen,sizeof(Sescsrchchar)-1);             //~va0yR~
		    UmemcpyZ(Pescsrch,utf8wk,outlen);	//srch by UTF8     //~va0yR~
        }                                                          //~va0yR~
        else      //f2l ok                                         //~va0yR~
        {                                                          //~va0yR~
        	outlen=srchlen;                                        //~va0yR~
        	UmemcpyZ(Pescsrch,Psrch,outlen);	//serch by UTF8 code//~va0yR~
        }                                                          //~va0yR~
#endif                                                             //~va1vI~
        opt=XEUTFCVO_CPU8|XEUTFCVO_STRZ|XEUTFCVO_OUTPARM|XEUTFCVO_RETALLASCII;//~va1vI~
        pu8=utf8wk;                                                //~va1vI~
		rc=xeutf_cvdata(opt,Psrch,srchlen,&pu8,&outlen);           //~va1vI~
        if (rc==XEUTFCVRC_ALLASCII)                                //~va1vI~
        	return 0;                                              //~va1vI~
        if (rc>XEUTFCVRC_ALLASCII)                                 //~va1vI~
        {                                                          //~va1vI~
            uerrmsg("translation to UTF8 failed for \"%s\"",0,     //~va1vI~
                    Psrch);                                        //~va1vI~
            return 4;                                              //~va1vI~
        }                                                          //~va1vI~
//      outlen=min(outlen,sizeof(Sescsrchchar)-1);                 //~va1vI~//~vb30R~
        outlen=min(outlen,(int)sizeof(Sescsrchchar)-1);            //~vb30I~
//      UmemcpyZ(Pescsrch,utf8wk,outlen);   //srch by UTF8         //~va1vI~//~vb30R~
        UmemcpyZ(Pescsrch,utf8wk,(size_t)outlen);   //srch by UTF8 //~vb30I~
    }                                                              //~va0yR~
    else                                                           //~va0yR~
    if (Popt & (SEARCH_UCS|SEARCH_UCS2)) //cv to ucs2              //~va0cI~//~vax1R~
    {                                                              //~va0cI~
	    opt=((Popt & (SEARCH_UCSBE|SEARCH_UCSBE2))==0)*XEUTFCVO_UCSLE;	//little endian flag//~va0cI~
	    if (Popt & (SEARCH_UCS4SW|SEARCH_UCS4SW2)) //selected one of two at call//~vax1R~
		    opt|=XEUTFCVO_UCS4;                                    //~vax1R~
        rc=xeutf_getucsstr(opt,Psrch,srchlen,Pescsrch,sizeof(Sescsrchchar),&outlen);//~va0cR~
        if (rc)                                                    //~va0cR~
        {                                                          //~va0cI~
            uerrmsg("translation to unicode failed for \"%s\"",0,  //~va0cR~
                    Psrch);                                        //~va0cR~
            return 4;                                              //~va0cI~
        }                                                          //~va0cI~
    }//cv to ucs                                                   //~va0cI~
//get locale from utf8                                             //~va0cI~
	else                                                           //~va0yR~
 	{                                                              //~va0yR~
#ifdef AAA                                                         //~va1vI~
//  	if (!XEUTF8MODE_ENV_FORCE()) //kbd is utf8 mode            //~va0yR~//~va1gR~
//  		return 0;	//no need to cv utf8 to locale             //~va0yR~//~va1gR~
//  	plc=xeutf_getlocalestr(Psrch,srchlen,Pescsrch,sizeof(Sescsrchchar),&lclen,0/*pcharcnt*/);//~va0yR~//~va1gR~
//  	if (!XEUTFGLRC_ISF2L(plc)) /*utf8->locale conversion NOT done*///~va0yR~//~va1gR~
//  		return 0;	//no need to cv utf8 to locale             //~va0yR~//~va1gR~
		rc=xeutf_getmixedstr(0,Psrch,srchlen,lcwk,0/*Pdbcs*/,0/*Pcodetype*/,sizeof(lcwk),&lclen,//~va1gI~
                        0/*Poututf8*/,0/*Poututf8sz*/,0/*Ppoututf8len*/);//~va1gI~
        if (rc==UALLOC_FAILED)                                     //~va1gI~
        	return 0;                                              //~va1gI~
        if (!(rc & XEUTFGU8MRC_UTF8))                              //~va1gI~
        	return 0;                                              //~va1gI~
		plc=lcwk;                                                  //~va1gI~
        outlen=min(lclen,sizeof(Sescsrchchar)-1);                  //~va0yR~
        UmemcpyZ(Pescsrch,plc,outlen);                             //~va0yR~
#endif                                                             //~va1vI~
#ifdef UTF8UCS2                                                    //~va20I~
		if (!(Popt & SEARCH_SAMEAS))                               //~va20I~
        {                                                          //~va20I~
            if (fcmdcvl2fsrchstr(Popt,Ppcw,Psrch,srchlen,utf8wk,sizeof(utf8wk),&outlen))//~va20R~
                return 0;   //search input string itself,it may be utf8 by A+u or not//~va20R~
//          outlen=min(sizeof(Sescsrchchar)-1,outlen);             //~va20R~//~vb30R~
            outlen=min((int)sizeof(Sescsrchchar)-1,outlen);        //~vb30I~
            if (Popt & SEARCH_AND)	//2nd word                     //~va7bI~
            	Sothopt|=SEARCH_DDSTR2;	//save to ini              //~va7bI~
//          UmemcpyZ(Pescsrch,utf8wk,outlen);                      //~va20R~//~vb30R~
            UmemcpyZ(Pescsrch,utf8wk,(size_t)outlen);              //~vb30I~
        }                                                          //~va20I~
        return 1;                                                  //~va20R~
#else                                                              //~va20I~
                                                                   //~va20I~
        return 0;   //search input string itself,it may be utf8 by A+u or not//~va1vI~
#endif                                                             //~va20M~
    }                                                              //~va0yR~
    *Ppescsrchlen=(UCHAR)outlen;                                   //~va0cI~
//  *Ppsrchlen=outlen;                                             //~va0cR~
    *Ppsrchlen=outlen;                                             //~va1gI~
    return 1;   //cv to ucs2 done                                  //~va0cI~
}//fcmdgetescsrchword                                              //~va0cR~
#endif                                                             //~va1qI~
//********************************************************************//~vauGI~
//*imediately execute find cmd(Rfind with parm)                    //~vauGI~
//********************************************************************//~vauGI~
void fcmd_execfindcmd(PUCLIENTWE Ppcw,int Pparmoffs,int Pcmdlen,int Poffstail)//~vauGR~
{                                                                  //~vauGI~
    int opt=0,lenu8,lenlc,lenct,lentail,parmlen,lent2;             //~vauGR~
//*********************************                                //~vauGI~
	UTRACEP("fcmd_execfindcmd cmd=%s,parm=\n",Gcmdbuff,Ppcw->UCWparm);//~vauGR~
	if (!strcmp(Ppcw->UCWparm,Gcmdbuffu8))                         //~vauGR~
    {                                                              //~vauGI~
		parmlen=Poffstail-Pparmoffs;//operand length               //~vauGR~
    	lenu8=min(parmlen,(int)sizeof(Gcmdbuffu8)-Pparmoffs-1);    //~vauGR~
//  	memmove(Gcmdbuffu8+Pparmoffs,Gcmdbuffu8,lenu8+1);  //with strZ//~vauGR~//~vb30R~
    	memmove(Gcmdbuffu8+Pparmoffs,Gcmdbuffu8,(size_t)lenu8+1);  //with strZ//~vb30I~
    	lenlc=min(Gcmdbufflclen,(int)sizeof(Gcmdbufflc)-Pparmoffs-1);;//~vauGR~
//  	memmove(Gcmdbufflc+Pparmoffs,Gcmdbufflc,lenlc+1);          //~vauGR~//~vb30R~
    	memmove(Gcmdbufflc+Pparmoffs,Gcmdbufflc,(size_t)lenlc+1);  //~vb30I~
    	lenct=min(Gcmdbufflclen,(int)sizeof(Gcmdbuffct)-Pparmoffs);//~vauGR~
//  	memmove(Gcmdbuffct+Pparmoffs,Gcmdbuffct,lenct);            //~vauGR~//~vb30R~
    	memmove(Gcmdbuffct+Pparmoffs,Gcmdbuffct,(size_t)lenct);    //~vb30I~
//      memcpy(Gcmdbuffu8,Gcmdbuff,Pparmoffs);                     //~vauGM~//~vb30R~
        memcpy(Gcmdbuffu8,Gcmdbuff,(size_t)Pparmoffs);             //~vb30I~
//      memcpy(Gcmdbufflc,Gcmdbuff,Pparmoffs);                     //~vauGM~//~vb30R~
        memcpy(Gcmdbufflc,Gcmdbuff,(size_t)Pparmoffs);             //~vb30I~
//      memset(Gcmdbuffct,0,Pparmoffs);                            //~vauGM~//~vb30R~
        memset(Gcmdbuffct,0,(size_t)Pparmoffs);                    //~vb30I~
        if (Pcmdlen>Poffstail)                                     //~vauGR~
        {                                                          //~vauGI~
        	lentail=Pcmdlen-Poffstail;                             //~vauGR~
	    	lent2=min(lentail,(int)sizeof(Gcmdbuffu8)-Pparmoffs-lenu8-1)+1;//~vauGI~
//          memcpy(Gcmdbuffu8+Pparmoffs+lenu8,Gcmdbuff+Poffstail,lent2);//~vauGR~//~vb30R~
            memcpy(Gcmdbuffu8+Pparmoffs+lenu8,Gcmdbuff+Poffstail,(size_t)lent2);//~vb30I~
	    	lent2=min(lentail,(int)sizeof(Gcmdbufflc)-Pparmoffs-lenlc-1)+1;//~vauGI~
//  	    memcpy(Gcmdbufflc+Pparmoffs+lenlc,Gcmdbuff+Poffstail,lent2);//~vauGR~//~vb30R~
    	    memcpy(Gcmdbufflc+Pparmoffs+lenlc,Gcmdbuff+Poffstail,(size_t)lent2);//~vb30I~
	    	lent2=min(lentail,(int)sizeof(Gcmdbuffct)-Pparmoffs-lenct);//~vauGI~
//      	memset(Gcmdbuffct+Pparmoffs+lenct,0,lent2);            //~vauGR~//~vb30R~
        	memset(Gcmdbuffct+Pparmoffs+lenct,0,(size_t)lent2);    //~vb30I~
        }                                                          //~vauGI~
    	opt=FCSO_SETCT;                                            //~vauGR~
//  	Gcmdbufflclen=strlen(Gcmdbufflc);                          //~vazaI~//~vb30R~
    	Gcmdbufflclen=(int)strlen(Gcmdbufflc);                     //~vb30I~
    }                                                              //~vauGI~
    funccmdstack_utf8(opt,Gcmdbuff,Pcmdlen,Ppcw->UCWseqno);  //save for retrieve//~vauGR~
}//fcmd_execfindcmd                                                //~vauGI~
//************************************************************************//+vbAtI~
void setFindStat(int Popt)                                         //+vbAtI~
{                                                                  //+vbAtI~
	if (Popt & SFSO_EXECMD_START)                                  //+vbAtI~
    {                                                              //+vbAtI~
    	GfindStat|=GFS_EXECMD;                                     //+vbAtI~
		SnextStartplh=0;                                           //+vbAtI~
    }                                                              //+vbAtI~
    else                                                           //+vbAtI~
	if (Popt & SFSO_EXECMD_END)                                    //+vbAtI~
    	GfindStat&=~GFS_EXECMD;                                    //+vbAtI~
    UTRACEP("%s:opt=0x%02x,GfindStat=0x%02x\n",UTT,Popt,GfindStat);//+vbAtI~
}//finderr_notdirlist                                              //+vbAtI~
