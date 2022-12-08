//CID://+vbvqR~:     update#=  35                                  //~vbvqR~
//*************************************************************
//* xeini.c                                                     //~5528R~
//************************************************************* //~v018I~
//vbvq:221201 (BUG)key ctr of the functbl is errornous when line of xe.ini was deleted. keep key with deleted sign.//~vbvqI~
//vbvh:221130 =0.2; clear key did not update xe.ini                //~vbvhI~
//vb55:160904 old func-key def on ::xe.in reset new added default key of xefunct//~vb55I~
//vb50:160827 accept S+A/C+extended key                            //~vb50I~
//vb3A:160625 for compiler warning,-Wformat-security(not literal printf format)//~vb3AI~
//vagb:120824 (BUG)func NULLCHAR is not written to ini             //~vagbI~
//vag2:120811 REDo suupport                                        //~vag2I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//vaa8:111208 keep original errmsg for ini file err                //~vaa8I~
//vaf9:120607 (WTL)Bug found by vs2010exp(used uninitialized variable),avoid warning C4701//~vaf9I~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v74B:070225 (LNX:BUG)ini file process fail by EOL type for the file Windows created.//~v74BI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v71u:061022 (BUG of v69Y) A+= cause err at xe start because "=" is parsed as delimiter//~v71uI~
//v69Y:060722 add A+"=" to virtical line for 101 keyboard (scancode=13, "^" on japanese kbd)//~v69YI~
//v694:060423 drop japanese comment from ini file                  //~v694I~
//v643:050617 (BUG)ccfunc active even when opt ccfunc=off if ini file used//~v643I~
//v60s:050130 support display width change without close current opened//~v60sI~
//v55x:040303 Ctrl+char is rejected by ini file chk,allow for v55j //~v55jI~
//v21a:001209 LINUX support:lower case exe name(xe)                //~v21aI~
//v190:000902 LINUX support(CRLF)                                  //~v190I~
//v146:000220:(BUG)of v13d(filesrchpfh has new parm pcw,but at term func_ini pcw parm is 0)//~v146I~
//                 it cause abend at term when ini inf updated.    //~v146I~
//v13d:991023 *\ support for filecmd(save/repl/create/append/copy/move/ini)//~v13dI~
//v138:991023 (BUG) # for CID is err because # and follower is comment on .INI//~v138I~
//v0jh:980722 reject char key for key assign change                //~v0jhI~
//v0je:980722 allow s+ for alternative of Shift+ for key assign in ini//~v0jeI~
//v0jd:980722 fix ctrl+2(null char),drop from ini and assign chng screen//~v0jdI~
//v0it:980717 funckey change option support                        //~v0itI~
//            write to ini when cmd/key assign changed             //~v0itI~
//v0b2:970723 split uparse fro ustring to uparse.c                 //~v0b2I~
//v0am:970713 (BUG)ini fgets buffsize MAXLINEDATA-->INIRECSZ       //~v0amI~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//            -printf format chk                                   //~v095I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v077:960608:(BUG)too long record msg for the case last line has no crlf//~v077I~
//v075:960608:color option                                         //~v075I~
//v06H:960421:(BUG of v064)effect disappear when twice restarted   //~v06HR~
//            tabdisplay flag,nocid flag,tab ctr need set to also ini variable//~v06HR~
//            move saveini to ini3.c                               //~v06HR~
//v064:960217:split inifile for Ginitscroll/Giniopt_/Ginifiletabskip//~v064I~
//v04k:951007:(BUG)v03o close after load when browse.edit for same file//~v04kI~
//            can not reopen to save because hfile is null(errno=12//~v04kI~
//            ENULLFCB).drop v03o.leave ini cmd err when browsing.//~v04kI~
//            open chk at ini by srchpfh                        //~v04kI~
//v04d:950930:malloc/calloc rc chk for dos                      //~v04dI~
//*v03h:950810:split xeini.c  to xeini.c and xeini2.c           //~v03hI~
//*v031:950712:fixed cid variable apart from Scidtbl(alternative of v021)//~v031I~
//*v030:950709:dir proc avail flag on by 2nd line version id    //~v030I~
//*v021:950710:bug when no ini file(fixed CID process)          //~v021I~
//*v01a:950705:kbd rate ini option(entry and exit value)        //~v01aI~
//*v018 950702:same ver/date to xe.ini and title msg            //~v018I~
//*            time edit by utimeedit                           //~v018I~
//*v015:950624 fixed cid parm                                   //~v01aI~
//*************************************************************
//*950603 write option except by cmd line parm(/yr etc)         //~v015I~
//*950528 customizable CID table                                //~5528I~
//*950527 UCBITCHK result the value not 1.                      //~5527I~
//*950506 Ctrl+char
//*950429 created
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*************************************************************
#ifdef DOS
#else
//  #define INCL_BASE                                              //~v07sR~
//  #include <os2.h>                                               //~v07sR~
#endif
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ufile.h>
#include <uparse.h>                                                //~v0b2R~
#include <ualloc.h>
#include <uedit.h>                                              //~v018I~
#include <utrace.h>                                                //~vb55I~

#include "xe.h"
#include "xescr.h"
#include "xeini.h"
#include "xeini2.h"                                             //~v03hI~
#include "xefunc.h"
#include "xefunct.h"
#include "xekbd.h"                                              //~v03hI~
#include "xefile.h"                                             //~5507I~
#include "xesub.h"                                                 //~v74xM~
#include "xegbl.h"                                                 //~v79zI~
//*******************************************************
#define INIRECSZ   512
#define PREFIXLEN	4
//*******************************************************
//static UCHAR  Spalid[]="PAL_";                                   //~v075R~
//static UCHAR  Scolid[]="COL_";                                   //~v075R~
static UCHAR *Scommline1="#######################################################################\n";//~5503I~
static UCHAR *Scommline2="\n#################\n";
//static UCHAR  Spalnoid[16][5]=                                   //~v075R~
//		{"----","---B","--G-","--GB","-R--","-R-B","-RG-","-RGB",  //~v075R~
//		 "H---","H--B","H-G-","H-GB","HR--","HR-B","HRG-","HRGB"}; //~v075R~
#define SECT_FUNC	0                                              //~v075I~
#define SECT_OTHER  1                                              //~v075I~
static UCHAR *Ssectionid[]=
//			{"[FUNCTION]","[PALLETTE]","[COLOR]","[OTHER]",0};     //~v075R~
  			{"[FUNCTION]","[OTHER]",0};                            //~v075I~
//static char *SdeletedKey="***Deleted***";                        //~vbvqR~
static char *SdeletedKey="(x)";                                    //~vbvqI~
static PUPODELMTBL Spodelmtb;                                      //~v138I~
static int Sfirstfuncsw;
static int Ssection;
static int Siniterr;
//static UCHAR **Spplinetype,*Spallettenotbl,*Scolornotbl;         //~v075R~
static UCHAR *Sgetsbuff;
int iniwkeytbl(UCHAR *Pfilename,FILE *Pfh);
int iniwfunctbl(UCHAR *Pfilename,FILE *Pfh);
//int iniwcolortbl(UCHAR *Pfilename,FILE *Pfh);                    //~v075R~
void inilineproc(UCHAR *Pfilename,int Plineno,int Plinelen);
int inirfunc(int Pwordno);                                      //~5501R~
//int inirpallette(int Pwordno);                                   //~v075R~
//int inircolor(int Pwordno);                                      //~v075R~
//void inisave(void);                                              //~v06HR~
//**************************************************
//*func_ini
//* ini filename[,d]
//*parm :pcw
//*ret  :rc
//**************************************************
int func_ini(PUCLIENTWE Ppcw)
{
	UCHAR  *fname,fpath[_MAX_PATH];                                //~v55jR~
    int rc;                                                     //~5507I~
    FILE *fh;
    PUFILEH pfh;                                                //~5507I~
//*********************************
	if (!Ppcw || !(fname=Ppcw->UCWparm))		//no operand    //~5527R~
		fname=inigetfname(0);                                   //~5503R~
//*operand chk
//  if (rc=filesrchpfh(fname,fpath,&pfh),rc>4)                     //~v55jR~
  if (Ppcw)                                                        //~v146I~
  {                                                                //~v146I~
//  if (rc=filesrchpfh2(Ppcw,fname,fpath,&pfh),rc>4)               //~v60sR~
    if (rc=filesrchpfh2(Ppcw,fname,fpath,&pfh,0),rc>4)//0:edit     //~v60sI~
    	return 16;                                              //~5507I~
  }                                                                //~v146I~
  else                                                             //~v146I~
    if (rc=filesrchpfh(fname,fpath,&pfh),rc>4)                     //~v55jR~
    	return 16;                                                 //~v146I~
	if (!rc)//found                                             //~5507I~
//      if (pfh->UFHeditpcw)                                    //~v04kR~
    	{                                                       //~5507I~
    		uerrmsg("%s is now Opened,try after close",         //~v04kR~
    				"%s はオープン中,クローズした後再試行して下さい",fpath);//~v55jR~
    		return 8;                                           //~5507I~
    	}                                                       //~5507I~
    UTRACEP("%s:fileopen fpath=%s\n",UTT,fpath);                   //~vb55I~
    if (!(fh=fileopen(fpath,"w")))                                 //~v55jR~
        return 12;
    if (!Ppcw)          //write at term                            //~v0itR~
        funcsetft();    //update ft by wft                         //~v0itR~
//	fprintf(fh,Scommline1);                                        //~vb3AR~
  	fprintf(fh,"%s",Scommline1);                                   //~vb3AI~
	fprintf(fh,"##### Parameter File for %s : %s : %s ( %s ) #\n",//~v018R~
				PGMID,                                          //~5528R~
				Gversion,                                       //~v018I~
				Gverdate,                                       //~v018I~
                (char*)utimeedit("YY-MM-DD  HH:MM",0));            //~v095R~
//  fprintf(fh,Scommline1);                                        //~vb3AR~
    fprintf(fh,"%s",Scommline1);                                   //~vb3AI~
//*write functbl
	if (iniwfunctbl(fpath,fh))                                     //~v55jR~
    	return 20;
//  if (iniwcolortbl(fpath,fh))                                    //~v55jR~
//  	return 24;                                                 //~v075R~
	if (iniwother(fpath,fh,Ssectionid[SECT_OTHER]))                //~v55jR~
    	return 24;
//  fprintf(fh,Scommline2);                                        //~vb3AR~
    fprintf(fh,"%s",Scommline2);                                   //~vb3AI~
    fileclose(fpath,fh);                                           //~v55jR~
    if (Ppcw)		//cmd input                                 //~5527I~
		uerrmsg("%s was written",                               //~5527R~
        	    "%s を出力しました",                            //~5527R~
       	    	fpath);                                            //~v55jR~
	return 0;
}//func_ini

//**************************************************
//*iniwkeytbl
//* write kbd tbl as comment
//*parm1:output filename
//*parm2:output FILE *
//*ret  :rc
//**************************************************
int iniwkeytbl(UCHAR *Pfilename,FILE *Pfh)
{
	KEYTBL *pkt;
    int ii;
//*********************************

	fprintf(Pfh,"##### Valid KeyID List                                                #");//~5502R~
	fprintf(Pfh,"\n##### (You can also use any char key with Alt like as Alt+a)          #");//~5506R~
	fprintf(Pfh,"\n##### (You can also use almost char key with Ctrl like as Ctrl+a)     #");//~5506I~
	fprintf(Pfh,"\n#####     Shift Modifier=>%s(%c+)  %s(%c+)    %s(%c+)   ",//~v0jhR~
    	*(Gkeyshiftname+1),**(Gkeyshiftname+1),                    //~v0jhR~
		*(Gkeyshiftname+2),**(Gkeyshiftname+2),                    //~v0jhI~
		*(Gkeyshiftname+3),**(Gkeyshiftname+3));                   //~v0jhI~
	for (pkt=Gkeytbl,ii=0;*(pkt->KTnamee);pkt++)                //~5502R~
	{
        if (UCBITCHK(pkt->KTflag[2],KTCHARKEY))//Alt+,Ctrl+ char//~5506R~
        	continue;                                           //~5502I~
    	if (!(ii++%5))                                          //~5502R~
			fprintf(Pfh,"\n# %-12s",pkt->KTnamee);
		else
			fprintf(Pfh,"%-12s",pkt->KTnamee);
	}
//  fprintf(Pfh,Scommline2);                                       //~vb3AR~
    fprintf(Pfh,"%s",Scommline2);                                  //~vb3AI~
	return 0;
}//iniwkeytbl

//**************************************************
//*iniwfunctbl
//* write func tbl for key assing
//*parm1:output filename
//*parm2:output FILE *
//*ret  :rc
//**************************************************
int iniwfunctbl(UCHAR *Pfilename,FILE *Pfh)
{
	FUNCTBL *pft;
	KEYTBL *pkt,*pkt2;                                          //~5501R~
    int ii,shiftid;
    UCHAR shiftch[3];                                              //~v0jeI~
	USHORT kid;
//  UCHAR keyedit[20];                                          //~5501I~//~vbvhR~
    UCHAR keyedit[32];                                             //~vbvhI~
    UCHAR *fixid,fixid2,*cmd,*cmda,cmdid;                          //~v0itR~
    int englishmode;                                               //~v694I~
#ifndef KKK                                                        //~vb50I~
    int swshiftAC;                                                 //~vb50I~
#endif                                                             //~vb50I~
//*********************************
    englishmode=(UCBITCHK(Gscrstatus,GSCRSDBCS)==0 || (Guerropt & GBL_UERR_FORCEENG)!=0);//~v694I~
	fprintf(Pfh,"\n##### Function Key assignment #########################################\n");
                                                                //~5508I~
	iniwkeytbl(Pfilename,Pfh);                                  //~5502I~
                                                                //~5502I~
	fprintf(Pfh,"%s\n",Ssectionid[SECT_FUNC]);                     //~v075R~
//	fprintf(Pfh,"#################                   (*):Fixed,it can not re-assign.");//~vbvqR~
  	fprintf(Pfh,"################# (*):Fixed,it can not re-assign. (x):Deleted.  #######");//~vbvqR~
//  fprintf(Pfh,"\n#%-20s=   %-20s # %s",                          //~v0itR~
//  			"(function-name)","(KeyID)","(Japanese comment)\n");//~v0itR~
  if (!englishmode)                                                //~v694I~
    fprintf(Pfh,"\n#(Function-name)     =   (KeyID)            =(Cmd)=(Cmd)\
# (Japanese comment)");                                            //~v0itI~
  else                                                             //~v694I~
    fprintf(Pfh,"\n#(Function-name)     =   (KeyID)            =(Cmd)=(Cmd)\
#");                                                               //~v694I~
    shiftch[2]=0;                                                  //~v0jeI~
	for (pft=Gfunctbl;*(pft->FTnamee);pft++)	//all ft entry
	{
//      if (pft->FTfuncid==FUNCID_REDO)     //not supported yet    //~vag2R~
//          continue;                                              //~vag2R~
//      if (pft->FTfuncid==FUNCID_NULLCHAR)     //not supported yet//~vagbR~
//          continue;                                              //~vagbR~
        UTRACEP("%s:FTnamee=%s\n",UTT,pft->FTnamee);               //~vb55I~
        UTRACED("FTkey",pft->FTkey,sizeof(pft->FTkey));            //~vb55I~
        UTRACED("FTkflag",pft->FTkflag,sizeof(pft->FTkflag));      //~vbvhI~
        for (ii=0;ii<FTMAXKEY;ii++)
        {
		  	UTRACEP("%s:ii=%d\n",UTT,ii);                          //~vb55I~
        	if (!(kid=pft->FTkey[ii]))
            {                                                   //~5502I~
		        UTRACEP("%s:ii=%d,kid=x%x\n",UTT,ii,kid);          //~vb55I~//~vbvhR~
                if (!ii)                                        //~5502I~
                {                                                  //~v694I~
//  				fprintf(Pfh,"\n %-20s= %-20s   # %s",          //~v0itR~
//  					pft->FTnamee," "    ,pft->FTnamej);        //~v0itR~
                  if (!englishmode)                                //~v694R~
            		fprintf(Pfh,"\n %-20s=   %-18s = %-3s = %-3s # %s",//~v0itI~
                    	pft->FTnamee," ",pft->FTcmd,pft->FTcmda,pft->FTnamej);//~v0itI~
                  else                                             //~v694I~
            		fprintf(Pfh,"\n %-20s=   %-18s = %-3s = %-3s #",//~v694I~
                    	pft->FTnamee," ",pft->FTcmd,pft->FTcmda);  //~v694I~
                }                                                  //~v694I~
				break;
            }                                                   //~5502I~
//         if (UCBITCHK(pft->FTkflag[ii],FTDELETED))               //~vbvqR~
//         {                                                       //~vbvqR~
//            sprintf(keyedit,"%s(%d)",SdeletedKey,ii);            //~vbvqR~
//            pkt2=0;                                              //~vbvqR~
//            UTRACEP("%s:Deleted");                               //~vbvqR~
//         }                                                       //~vbvqR~
//         else                                                    //~vbvqR~
//         {                                                       //~vbvqR~
            shiftid=kbdsrchkt(kid,&pkt);
            UTRACED("keytbl",pkt,sizeof(KEYTBL));                  //~vb55I~
            if (!pkt)
            {
//          	if (UCBITCHK(Gscrstatus,GSCRSDBCS))                //~v79zR~
            	if (XE_ISDBCSKONJ())    //japanese on KON          //~v79zI~
	            	uerrmsg("Function:%s assigned invalid key x\"%02X\"",
//    	            		"機能:%sに無効なキー(\"%02X\")が割り当てられています",//~v095R~
      	            		"機\x94\\:%sに無効なキー(\"%02X\")が割り当てられています",//~v095R~
        	                pft->FTnamej,kid);
				else
	            	uerrmsg("Function:%s assigned invalid key x\"%02X\"",
    	            		0,
        	                pft->FTnamee,kid);

				continue;
			}
#ifndef KKK                                                        //~vb50I~
			swshiftAC=0;                                           //~vb50I~
            if (shiftid==2||shiftid==3)	//Alt or Ctl               //~vb50I~
            {                                                      //~vb50I~
	            if (UCBITCHK(pft->FTkflag[ii],FTSHIFT))            //~vb50I~
    	         	swshiftAC=1;                                   //~vb50I~
            }                                                      //~vb50I~
            else                                                   //~vb50I~
#endif                                                             //~vb50I~
            if (UCBITCHK(pft->FTkflag[ii],FTSHIFT))
            	shiftid=1;
			if (shiftid==3                                      //~5503I~
			&&  UCBITCHK(pkt->KTflag[3],KTCTLDUP1))	//duplicated key//~5503I~
//  			pkt=kbdsrchdupkt(pkt2=pkt);                        //~v0itR~
//  			pkt2=kbdsrchdupkt(pkt);                            //~v69YR~
    			pkt2=kbdsrchdupkt(pkt,shiftid);                    //~v69YI~
			else	                                            //~5503I~
			if (shiftid==2     //alt                               //~v69YR~
			&&  UCBITCHK(pkt->KTflag[2],KTALTDUP1))	//duplicated key//~v69YR~
    			pkt2=kbdsrchdupkt(pkt,shiftid);                    //~v69YI~
			else                                                   //~v69YI~
            	pkt2=0;                                         //~5503I~
//          sprintf(keyedit,"%s%s",*(Gkeyshiftname+shiftid),pkt->KTnamee);//~v0jeR~
#ifndef KKK                                                        //~vb50M~
          if (swshiftAC)                                           //~vb50M~
			xekbdsetSAC(0,shiftid,pkt,keyedit);                    //~vb50R~
          else                                                     //~vb50M~
#endif                                                             //~vb50M~
          {                                                        //~vb50I~
            if (!(shiftch[0]=**(Gkeyshiftname+shiftid)))           //~v0jeI~
            {                                                      //~v0jeI~
            	shiftch[0]=' ';                                    //~v0jeI~
            	shiftch[1]=' ';                                    //~v0jeI~
			}                                                      //~v0jeI~
            else                                                   //~v0jeI~
            	shiftch[1]='+';                                    //~v0jeI~
            sprintf(keyedit,"%s%s",shiftch,pkt->KTnamee);          //~v0jeR~
          }                                                        //~vb50I~
//         }//!deleted                                             //~vbvqR~
            if (UCBITCHK(pft->FTkflag[ii],FTFIX))
            {                                                      //~v0itI~
//  			fprintf(Pfh,"\n#%-20s=(*)%-20s # %s",              //~v0itR~
//  					pft->FTnamee,keyedit,pft->FTnamej);        //~v0itR~
                fixid="(*)";                                       //~v0itI~
                fixid2='#';                                        //~v0itI~
            }                                                      //~v0itI~
            else
            if (UCBITCHK(pft->FTkflag[ii],FTDELETED))              //~vbvqI~
            {                                                      //~vbvqI~
                fixid=SdeletedKey;		//"(x)"                    //~vbvqI~
                fixid2=' ';                                        //~vbvqI~
              	UTRACEP("%s:Deleted");                             //~vbvqI~
           }                                                       //~vbvqI~
           else                                                    //~vbvqI~
            {                                                      //~v0itI~
//  			fprintf(Pfh,"\n %-20s=   %-20s # %s",              //~v0itR~
//  					pft->FTnamee,keyedit,pft->FTnamej);        //~v0itR~
                fixid="   ";                                       //~v0itI~
                fixid2=' ';                                        //~v0itI~
            }                                                      //~v0itI~
            if (pft->FTfuncid==FUNCID_NULLCHAR                     //~v0itI~
            ||  pft->FTfuncid>=FUNCID_GRAPHCHAR)                   //~v0itI~
            {                                                      //~v0itI~
            	cmdid=' ';                                         //~v0itI~
            	cmd=cmda="";                                       //~v0itI~
            }                                                      //~v0itI~
            else                                                   //~v0itI~
            {                                                      //~v0itI~
            	cmdid='=';                                         //~v0itI~
            	cmd=pft->FTcmd;                                    //~v0itI~
            	cmda=pft->FTcmda;                                  //~v0itI~
            }                                                      //~v0itI~
		  UTRACEP("%s:englishmode=%d,FTnamee=%s,fixid=%c,keyedit=%s,FTKflag=x%x\n",UTT,englishmode,pft->FTnamee,fixid,keyedit,pft->FTkflag[ii]);//~vb55R~//~vbvhR~
          if (!englishmode)                                        //~v694I~
            fprintf(Pfh,"\n%c%-20s=%s%-18s %c %-3s %c %-3s # %s",  //~v0itR~
                    fixid2,pft->FTnamee,fixid,keyedit,cmdid,cmd,cmdid,cmda,pft->FTnamej);//~v0itR~
          else                                                     //~v694I~
            fprintf(Pfh,"\n%c%-20s=%s%-18s %c %-3s %c %-3s #",     //~v694I~
                    fixid2,pft->FTnamee,fixid,keyedit,cmdid,cmd,cmdid,cmda);//~v694I~
//for duplicated key value                                      //~5503M~
			if (pkt2)                                           //~5503R~
            {                                                   //~5503I~
            	pkt=pkt2;                                       //~5503I~
  		        sprintf(keyedit,"%s%s",*(Gkeyshiftname+3),pkt->KTnamee);//~5503I~
//  			fprintf(Pfh,"\n#%-19s(=   %-20s)# Same Key Code",  //~v0itR~
    			fprintf(Pfh,"\n#%-19s(=   %-18s)            # Same Key Code",//~v0itI~
						" ",keyedit);                              //~v095R~
			}	                                                //~5503I~
		}//by FTkey
	}//by pft                                                   //~5503R~
//  fprintf(Pfh,Scommline2);                                       //~vb3AR~
    fprintf(Pfh,"%s",Scommline2);                                  //~vb3AI~
	return 0;
}//iniwfunctbl

//**************************************************
//*iniwcolortbl
//* write pallette/color tbl
//*parm1:output filename
//*parm2:output FILE *
//*ret  :rc
//**************************************************
//int iniwcolortbl(UCHAR *Pfilename,FILE *Pfh)                     //~v075R~
//{                                                                //~v075R~
//    UCHAR *pc,**ppc;                                             //~v075R~
//    int ii;                                                      //~v075R~
//*********************************
//	scrgetcolortbl(&Spplinetype,&Spallettenotbl,&Scolornotbl);     //~v075R~
//*pallette
//	fprintf(Pfh,"\n##### Pallette number assignment ######################################\n");//~v075R~
//	fprintf(Pfh,"##### Format: Line-Type = %s(pallette-no)%28s\n", //~v075R~
//				Spalid,"#");                                       //~v075R~
//	fprintf(Pfh,"#####    Line-Type    : (FG):Text , (BG):Background%20s\n","#");//~v075R~
//	fprintf(Pfh,"#####    pallette-no  :0-15 hrgb fmt(h:highlite,r:red,g:green,b:blue) #\n");//~v075R~
//	fprintf(Pfh,"#####      ex. 5=0101(R+B)=purple, 10=1010(H+G)=High-green            #\n");//~v075R~
//	fprintf(Pfh,"#####    (actual color is determined by %s,see next section)     #\n",//~v075R~
//					Ssectionid[2]);                                //~v075R~
//	fprintf(Pfh,"%s\n",Ssectionid[1]);                             //~v075R~
//	for (pc=Spallettenotbl,ppc=Spplinetype;*ppc;ppc++,pc++)	//all linetype//~v075R~
//      if (*pc>0x09)                                              //~v075R~
//			fprintf(Pfh,"\n %-20s= %s%d       # %s",               //~v075R~
//					*ppc,Spalid,(int)*pc,Spalnoid[(int)*pc]);      //~v075R~
//      else                                                       //~v075R~
//			fprintf(Pfh,"\n %-20s= %s%d        # %s",              //~v075R~
//					*ppc,Spalid,(int)*pc,Spalnoid[(int)*pc]);      //~v075R~
//	fprintf(Pfh,Scommline2);                                       //~v075R~
//*color
//	fprintf(Pfh,"\n##### Color assignment ################################################\n");//~v075R~
//	fprintf(Pfh,"##### Format: %s(pallette-no) = %s(color-register-no)             #\n",//~v075R~
//			Spalid,Scolid);                                        //~v075R~
//	fprintf(Pfh,"#####      see .doc for RGB value of color-register-no                #\n");//~v075R~
//	fprintf(Pfh,"%s\n",Ssectionid[2]);                             //~v075R~
//	for (pc=Scolornotbl,ii=0;ii<16;ii++,pc++)	//all pallette     //~v075R~
//    	if (*pc!=0xff)                                             //~v075R~
//			fprintf(Pfh,"\n %s%d = %s%d",Spalid,ii,Scolid,(int)*pc);//~v075R~
//	fprintf(Pfh,Scommline2);                                       //~v075R~
//	return 0;                                                      //~v075R~
//}//iniwcolortbl                                                  //~v075R~

//**************************************************            //~5501I~
//*inigetparm                                                   //~5501I~
//* get parm from .ini file                                     //~5501I~
//*parm :ini file name parameter                                //~5501I~
//*      nul:no parm(use dafault), "":no use ini file           //~5501I~
//*ret  :rc                                                     //~5501I~
//**************************************************            //~5501I~
int inigetparm(UCHAR *Pinifile)                                 //~5501I~
{
	UCHAR  fpath[_MAX_PATH],*inifile;                              //~v55jR~
    int newfile,lineno=0,len;
    FILE *fh;
//*********************************
// 	inisave();		//save for err return                          //~v06HR~
	                                                            //~5603I~
	if (Pinifile && !*Pinifile)	//""                            //~5501I~
    	return 0;                                               //~5501R~
    if (!(inifile=Pinifile))				//no /I parameter   //~5503R~
		inifile=inigetfname(0);                                 //~5503I~
//*operand chk
	if ((newfile=filefind(inifile,fpath,0,                         //~v55jR~
			FFNONFMSG*(Pinifile==0)))>4)//no need fstat3 output //~5513R~
        return 8;
	if (newfile)	//not found
    {
//      uerrmsg("No ini file(%s),continue with default parm",   //~5508R~
//  	     	"INIファイル(%s)がありません,省略値で処理続行", //~5508R~
//      	    fpath);                                            //~v55jR~
        return 0;
	}
    if (!(fh=fileopen(fpath,"r")))                                 //~v55jR~
        return 8;
//ini file read
//	scrgetcolortbl(&Spplinetype,&Spallettenotbl,&Scolornotbl);     //~v075R~
	Sgetsbuff=UALLOCM(INIRECSZ);                                //~v04dR~
	Spodelmtb=UALLOCM(INIRECSZ*UPODELMTBLSZ);                      //~v138R~
	Sfirstfuncsw=Siniterr=0;
    Ssection=-1;
	for (;;)	//until eof/err
	{
		++lineno;
//  	if (!fgets(Sgetsbuff,MAXLINEDATA+2,fh))//null if error/ eof//~v0amR~
    	if (!fgets(Sgetsbuff,INIRECSZ,fh))//null if error/ eof     //~v0amI~
        {                                                          //~v55jI~
			if (ferror(fh))
				uerrexit("%s-I/O(fgets) error at %d line",
						 "%s-%d 行目で I/O(fgets) エラー",
						 inifile,lineno);
			else
            	break;
        }                                                          //~v55jI~
//@@@@ temporary logic dir process err when v0.20               //~v030I~
//      if (lineno==2 && memcmp(Sgetsbuff+31,"0.20",4))         //~v030I~
//  		UCBITON(Gopt3,GOPT3DIRPROCAVAIL);                   //~v030I~
//@@@@ temporary logic dir process err when v0.20               //~v030I~
		len=(int)strlen(Sgetsbuff);			//read len
//  	if (len>=MAXLINEDATA                                       //~v0amR~
    	if (len>=(INIRECSZ-2)	//for the case last record has no crlf//~v0amI~
		&&	*(Sgetsbuff+len-1)!='\n')                              //~v077I~
			uerrexit("%s-%d line is tool long",
					 "%s-%d 行目の行が長過ぎます",
					 inifile,lineno);
		if (*(Sgetsbuff+len-1)=='\n')                              //~v077I~
        {                                                          //~v077I~
			len--;						//drop 0a                  //~v077R~
			*(Sgetsbuff+len)=0;                                    //~v077R~
        }                                                          //~v077I~
		if (len>0 && *(Sgetsbuff+len-1)=='\r')                     //~v74BI~
        {                                                          //~v74BI~
			len--;						//drop 0a                  //~v74BI~
			*(Sgetsbuff+len)=0;                                    //~v74BI~
        }                                                          //~v74BI~
        inilineproc(inifile,lineno,len);
	}
    fileclose(fpath,fh);                                           //~v55jR~
	ufree(Sgetsbuff);
	ufree(Spodelmtb);                                              //~v138I~
	Sgetsbuff=0;
    if (Siniterr)
    {
    	if (Sfirstfuncsw)	//get copyed
    		functreset();
	}
// 	inisave();	    //save for write at term(out of exe parm efect)//~v06HR~
    return Siniterr;
}//inigetparm                                                   //~5603R~

//**************************************************
//*inilinedata
//* line process
//*parm1:filename
//*parm2:lineno
//*parm3:line len
//*ret  :none
//**************************************************
void inilineproc(UCHAR *Pfilename,int Plineno,int Plinelen)
{
    UCHAR *pc;
    int wordno,ii,rc=0;                                            //~vaf9R~
    PUPODELMTBL ppodt;                                             //~v138I~
    int tempch=0;                                                  //~v71uI~
    UCHAR *pc2;                                                    //~v71uI~
//*********************************
//*drop comment
//    if (!(pc=strchr(Sgetsbuff,'#')))    //not found              //~v138R~
//        len=Plinelen;                                            //~v138R~
//    else                                                         //~v138R~
//    {                                                            //~v138R~
//        len=(int)((ULONG)pc-(ULONG)Sgetsbuff);                   //~v138R~
//        *pc=0;                                                   //~v138R~
//    }                                                            //~v138R~
//    if (!len)                                                    //~v138R~
//        return;                                                  //~v138R~
//*parse
//    while ((pc=strchr(Sgetsbuff,'\t'))!=0)                       //~v138R~
//        *pc++=' ';                          //repl all tab to space//~v138R~
//  uparse(Sgetsbuff,Sgetsbuff,&wordno,0,"=");	//parse out string(accept cr/lf)//~v138R~
    if (*Sgetsbuff!='['        //not new section                   //~v71uI~
	&&  Ssection==0)            //function                         //~v71uR~
    {                                                              //~v71uI~
        if (pc=strstr(Sgetsbuff,"+= "),pc) 	//key A+=              //~v71uR~
        {                                                          //~v71uI~
        	tempch=0xff;                                           //~v71uI~
        	*(pc+1)=(UCHAR)tempch;		//temporary change "=" to avoidd to be parsed as delm//~v71uR~
        }                                                          //~v71uI~
    }                                                              //~v71uI~
    uparse2(Sgetsbuff,&Spodelmtb,&Sgetsbuff,&wordno,	//parse out string(accept cr/lf)//~v138R~
					UPARSE2TABISSPACE|UPARSE2USEAREAPARM|UPARSE2SETCONTDLM2,"=#");//~v138R~
    for (ii=0,ppodt=Spodelmtb,pc=Sgetsbuff;ii<wordno;ii++,ppodt++,pc+=strlen(pc)+1)//~v138I~
    {                                                              //~v71uI~
        if (tempch)                                                //~v71uM~
        	if (pc2=strchr(pc,tempch),pc2)                         //~v71uM~
            	*pc2='=';	//restore orginal char                 //~v71uM~
    	if (ppodt->upodelm=='#')                                   //~v138I~
        {	                                                       //~v138I~
        	wordno=ii+(strlen(pc) || ppodt->upoquate);             //~v138R~
            break;                                                 //~v138I~
        }                                                          //~v138I~
    }                                                              //~v71uI~
    if (!wordno)	//all space
        return;
//*section statement
    if (*Sgetsbuff=='[')
    {
    	for (ii=0;pc=Ssectionid[ii],pc;ii++)
    		if (!stricmp(Sgetsbuff,pc))
				break;
		if (!pc && !Siniterr)
        {
        	Siniterr=4;
			uerrmsg("%s-%d line is invalid section id",
					 "%s-%d 行目は無効な [セクションID]",
					 Pfilename,Plineno);
		}
		Ssection=ii;
        return;
    }
    if (Plineno==247)                                              //~v69YI~
        Plineno=247;                                               //~v69YI~
//*effective statement
	switch (Ssection)
    {
    case 0:		//function
    	rc=inirfunc(wordno);                                    //~5501R~
    	break;
//  case 1:     //pallette                                         //~v075R~
//  	rc=inirpallette(wordno);                                   //~v075R~
//  	break;                                                     //~v075R~
//  case 2:     //color                                            //~v075R~
//  	rc=inircolor(wordno);                                      //~v075R~
//  	break;                                                     //~v075R~
//  case 3:     //other                                            //~v075R~
    case 1:     //other                                            //~v075I~
    	rc=inirother(wordno,Sgetsbuff);                         //~v03hR~
    	break;
    default:
    	if (!Siniterr)
   		{
       		Siniterr=4;
			uerrmsg("%s-%d missing [section] statement",
					 "%s-%d 行目は [セクションID]の後に指定して下さい",
					 Pfilename,Plineno);
			return;
		}
	}//sw by section
    if (rc && !Siniterr)
	{
   		Siniterr=4;
//  	uerrmsg("%s-%d has error",                                 //~vaa8R~
    	uerrmsgcat("; %s-%d has error",                            //~vb55R~
				 "; %s-%d 行目に誤りがあります",                   //~vb55R~
				 Pfilename,Plineno);
	}
    return;
}//inilineproc

//**************************************************               //~vbvhI~
//*idxkey or -1;                                                   //~vbvhI~
//**************************************************               //~vbvhI~
//int chkDeleted(PFUNCTBL Ppft,UCHAR *Ppc,KEYTBL **Ppkt,int *Ppshiftid)//~vbvqR~
//{                                                                //~vbvqR~
//    int len,idxKey=-1,shiftid=-1;                                //~vbvqR~
//    USHORT key;                                                  //~vbvqR~
//    KEYTBL *pkt=0;                                               //~vbvqR~
//    //*******************************                            //~vbvqR~
//    UTRACEP("%s:pc=%s\n",UTT,Ppc);                               //~vbvqR~
//    len=(int)strlen(SdeletedKey);                                //~vbvqR~
//    if (!memcmp(Ppc,SdeletedKey,(UINT)len))                      //~vbvqR~
//    {                                                            //~vbvqR~
//        idxKey=atoi(Ppc+len+1);                                  //~vbvqR~
//        if (idxKey>=0 && idxKey<FTMAXKEY)                        //~vbvqR~
//        {                                                        //~vbvqR~
//            key=Ppft->FTkey[idxKey];                             //~vbvqR~
//            shiftid=kbdsrchkt(key,&pkt);                         //~vbvqR~
//        }                                                        //~vbvqR~
//        else                                                     //~vbvqR~
//            idxKey=-1;                                           //~vbvqR~
//    }                                                            //~vbvqR~
//    *Ppkt=pkt;                                                   //~vbvqR~
//    *Ppshiftid=shiftid;                                          //~vbvqR~
//    UTRACEP("%s:FTnamee=%s,idxKey=%d,shiftid=%d,pkt=%p\n",UTT,Ppft->FTnamee,idxKey,shiftid,pkt);//~vbvqR~
//    return idxKey;                                               //~vbvqR~
//}                                                                //~vbvqR~
//**************************************************               //~vbvqI~
//*return 1 if deleted                                             //~vbvqI~
//**************************************************               //~vbvqI~
int chkDeleted(PFUNCTBL Ppft,UCHAR **Ppc)                          //~vbvqI~
{                                                                  //~vbvqI~
	int rc,len;                                                    //~vbvqR~
    char *pc;                                                      //~vbvqI~
    //*******************************                              //~vbvqI~
    pc=*Ppc;                                                       //~vbvqI~
    UTRACEP("%s:pc=%s\n",UTT,pc);                                  //~vbvqI~
    len=(int)strlen(SdeletedKey);                                  //~vbvqI~
    rc=memcmp(pc,SdeletedKey,(UINT)len)==0;                        //~vbvqI~
    if (rc)                                                        //~vbvqI~
    	*Ppc=pc+len;	//skip Sdeleted key                        //~vbvqI~
    UTRACEP("%s:FTnamee=%s,rc=%d\n",UTT,Ppft->FTnamee,rc);         //~vbvqI~
    return rc;                                                     //~vbvqI~
}                                                                  //~vbvqI~
//**************************************************
//*inirfunc
//* function section line process
//*parm:none
//*ret :rc
//**************************************************
int inirfunc(int Pwordno)                                       //~5501R~
{
    FUNCTBL *pft;
	KEYTBL *pkt=0;                                                 //~vaf9R~
    UCHAR *pc;
    UCHAR *pccmd,*pccmda=0;                                        //~vaf9R~
    int ii,jj,shiftid=0;                                           //~vaf9R~
    int firstsw;                                                   //~v0itI~
#ifndef KKK                                                        //~vb50I~
    int swshiftAC=0;                                               //~vb50R~
#endif                                                             //~vb50I~
	int swDeleted;                                                 //~vbvhR~
//*********************************
    if (!Sfirstfuncsw)
    {
		Sfirstfuncsw=1;
    	functgetcopy();
	}
//funcid chk                                                    //~5501I~
	if (!(pft=functblsrchbyname(Sgetsbuff)))
    	return 4;
    UTRACEP("%s:Pwordno=%d,FTnamee=%s\n",UTT,Pwordno,pft->FTnamee);//~vbvhI~
    if (!UCBITCHK(pft->FTflag,FTFUPINI))	//first time
    {
        firstsw=1;                                                 //~v0itI~
    	UCBITON(pft->FTflag,FTFUPINI);
    	for (ii=0,jj=-1;ii<FTMAXKEY;ii++)                       //~5501R~
    		if (!UCBITCHK(pft->FTkflag[ii],FTFIX))	//not fixed
            {
            	if (jj<0)	//first time                        //~5501R~
                	jj=ii;	//set pos
//          	if (!pft->FTkey[ii])                               //~vb55R~
//              	break;                                         //~vb55R~
//          	pft->FTkey[ii]=pft->FTkflag[ii]=0;//clear at set new key later//~vb55R~
            	UCBITON(pft->FTkflag[ii],FTUPDATEINI);  //for next entry,updateable//~vb55R~
            }
    }
    else
    {
        firstsw=0;                                                 //~v0itI~
    	for (ii=0;ii<FTMAXKEY;ii++)	//serch free entry
//  		if (!pft->FTkey[ii])	//not used                     //~vb55R~
    		if (UCBITCHK(pft->FTkflag[ii],FTUPDATEINI))	//updateable//~vb55R~
            	break;
    	if (ii==FTMAXKEY)	//no free entry
        {                                                          //~vb55I~
    		uerrmsg("Too many(Max:%d) key definition for a function",//~vb55I~
    				"１機\x94\\のキー定義は最大 %d",               //~vb55R~
                    FTMAXKEY);                                     //~vb55I~
        	return 4;
        }                                                          //~vb55I~
        jj=ii;
    }
    UTRACED("FTkey",pft->FTkey,sizeof(pft->FTkey));                //+vbvqI~
    UTRACED("FTkflag",pft->FTkflag,sizeof(pft->FTkflag));          //+vbvqI~
//*key process                                                  //~5501I~
    if (Pwordno==1)	//clear req                                 //~5501R~
    {                                                           //~5501I~
//    	UTRACEP("%s:pkt clear by Pwordno=1 func=%s\n",UTT,pft->FTnamee);//~vb55R~
		pft->FTkey[jj]=0;                                       //~5501I~
		return 0;                                               //~5501I~
    }                                                           //~5501I~
    pc=Sgetsbuff+strlen(Sgetsbuff)+1;	//second word,key fld   //~5501M~
   	UTRACEP("%s:pc=%s\n",UTT,pc);                                  //~vbvhR~
//*chk cmd verb                                                    //~v0itM~
    if (Pwordno<=2)	//no cmd                                       //~v0itI~
    	pccmd=0;                                                   //~v0itR~
	else    // >=3                                                 //~v0itR~
    {                                                              //~v0itI~
	    pccmd=pc+strlen(pc)+1;	//second word,key fld              //~v0itI~
        pccmda="";                                                 //~v0itI~
	    if (Pwordno>3)	//cmd alias                                //~v0itR~
		    pccmda=pccmd+strlen(pccmd)+1;	//second word,key fld  //~v0itI~
        if (strlen(pccmda)>=sizeof(pft->FTcmda))                   //~v0itR~
            return 4;                                              //~v0itR~
        if (strlen(pccmd)>=sizeof(pft->FTcmd))                     //~v0itM~
            return 4;                                              //~v0itM~
        if (*pccmd)                                                //~v0itI~
	        if (!strcmp(pccmd,pccmda))  //dup                      //~v0itR~
    	        return 4;                                          //~v0itR~
    }                                                              //~v0itI~
//*chk cmd verb end                                                //~v0itI~
    swDeleted=0;                                                   //~vbvhI~
    UTRACEP("%s:cmd=%s,cmda=%s,FTflag=x%x,FTnamee=%s\n",UTT,pccmd,pccmda,pft->FTflag,pft->FTnamee);//~vbvqI~
  if (*pc)                                                         //~v0itI~
  {                                                                //~v0itI~
    if (UCBITCHK(pft->FTflag,FTFCMDONLY))                          //~v0itI~
    {                                                              //~vbvqI~
	    UTRACEP("%s:FTCMDONLY\n",UTT);                             //~vbvqI~
        return 4;                                                  //~v0itI~
    }                                                              //~vbvqI~
//  if (chkDeleted(pft,pc,&pkt,&shiftid)>=0)                       //~vbvqR~
//  {                                                              //~vbvqR~
//  	swDeleted=1;                                               //~vbvqR~
//  }                                                              //~vbvqR~
//  else                                                           //~vbvqR~
//  {                                                              //~vbvqR~
	swDeleted=chkDeleted(pft,&pc);                                 //~vbvqI~
#ifndef KKK                                                        //~vb50I~
	xekbdchkSAC(0,pc,&pkt,&shiftid);                               //~vb50R~
  if (shiftid)	//2 or 3                                           //~vb50R~
  {                                                                //~vb50I~
    swshiftAC=1;                                                   //~vb50I~
  }                                                                //~vb50I~
  else                                                             //~vb50I~
#endif                                                             //~vb50I~
	shiftid=kbdsrchktbyname(pc,&pkt);                           //~5501I~
    if (!pkt)		//shift prefix                              //~5501I~
    	return 4;	//invalid key                               //~5501I~
    if (shiftid!=2    //char key or not alt+                       //~v0jhR~
    &&  UCBITCHK(pkt->KTflag[2],KTCHARKEY))                        //~v0jhI~
      if (!(shiftid==3 && (pkt->KTkey[3] & 255)<' ')) //allow ctl+char//~v55jR~
    	return 4;	//invalid key                                  //~v0jhI~
 // }//!deleted                                                    //~vbvqI~
  }	                                                               //~v0itI~
    if (pccmd)                                                     //~v0itI~
    {                                                              //~v0itI~
        if (*pccmd)                                                //~v0itI~
            if (pft->FTfuncid==FUNCID_NULLCHAR                     //~v0itR~
            ||  pft->FTfuncid>=FUNCID_GRAPHCHAR)                   //~v0itR~
                return 4;                                          //~v0itI~
        if (firstsw || *pccmd)                                     //~v0itR~
   		{                                                          //~v0itI~
    		strcpy(pft->FTcmd,pccmd);                              //~v0itR~
        	strcpy(pft->FTcmda,pccmda);                            //~v0itR~
    	}                                                          //~v0itR~
    }                                                              //~v0itI~
    UTRACEP("%s:after set cmd FTcmd=%s,FTcmda=%s\n",UTT,pft->FTcmd,pft->FTcmda);//~vbvqR~
	if (!*pc)                                                      //~v0itI~
    {                                                              //~v0itI~
		pft->FTkey[jj]=0;                                          //~v0itI~
      	UTRACEP("%s:pkt clear by pc=null func=%s\n",UTT,pft->FTnamee);//~vbvqR~
  		return 0;                                                  //~v0itI~
	}                                                              //~v0itI~
//duplicate chk for fixed                                       //~5506I~
    for (ii=0;ii<jj;ii++)                                       //~5506I~
		if (pft->FTkey[ii]==pkt->KTkey[shiftid]                 //~5506I~
    	&&  UCBITCHK(pft->FTkflag[ii],FTFIX))	//fixed         //~5506I~
			return 0;                                           //~5506I~
  if (swDeleted)                                                   //~vbvhI~
	pft->FTkey[jj]=FTDELETEDKEY;                                   //~vbvhI~
  else                                                             //~vbvhI~
	pft->FTkey[jj]=pkt->KTkey[shiftid];                         //~5501R~
  UTRACEP("%s:pkt set jj=%d,key=x%x,func=%s\n",UTT,jj,pft->FTkey[jj],pft->FTnamee);//~vbvqR~
    pft->FTkflag[jj]=0;	//updated,not candidate of next entry      //~vb55R~
    if (shiftid==1)     //Shift+
		if (pkt->KTkey[1]==pkt->KTkey[0])	//no diference
			UCBITON(pft->FTkflag[jj],FTSHIFT);
    if ((shiftid==3 && (pkt->KTkey[3] & 255)<' ')) //ctl+char      //~v643I~
		UCBITON(pft->FTkflag[jj],FTCTLC);                          //~v643I~
#ifndef KKK                                                        //~vb50I~
    if (swshiftAC)                                                 //~vb50I~
		UCBITON(pft->FTkflag[jj],FTSHIFT);	//S+Alt or S+CTL       //~vb50R~
#endif                                                             //~vb50I~
	UTRACED("inirdunc exit FTkey",pft->FTkey,sizeof(pft->FTkey));  //+vbvqR~
    UTRACED("inirfunc exit FTkflag",pft->FTkflag,sizeof(pft->FTkflag));//+vbvqI~
	return 0;
}//inirfunc

//**************************************************
//*inirpallette
//* pallette section line process
//*parm:none
//*ret :rc
//**************************************************
//int inirpallette(int Pwordno)                                    //~v075R~
//{                                                                //~v075R~
//  UCHAR *pc,**ppc,*pc2;                                          //~v075R~
//  int palno;                                                     //~v075R~
//*********************************
//search line type
//  if (Pwordno==1)	//no operand                                   //~v075R~
//  	return 4;                                                  //~v075R~
//  for (pc=Spallettenotbl,ppc=Spplinetype;*ppc;ppc++,pc++)	//all linetype//~v075R~
//  	if (!stricmp(Sgetsbuff,*ppc))                              //~v075R~
//      	break;                                                 //~v075R~
//  if (!ppc)	//not found                                        //~v075R~
//  	return 4;                                                  //~v075R~
//  pc2=Sgetsbuff+strlen(Sgetsbuff)+1;	//second word,palletteno fld//~v075R~
//  if (memcmp(pc2,Spalid,PREFIXLEN) || !ISNUMSTR(pc2+PREFIXLEN))  //~v075R~
//  	return 4;                                                  //~v075R~
//  palno=atoi(pc2+PREFIXLEN);                                     //~v075R~
//  if (palno<0 || palno>15)                                       //~v075R~
//  	return 4;                                                  //~v075R~
//  *pc=(UCHAR)palno;                                              //~v075R~
//  return 0;                                                      //~v075R~
//}//inirpallette                                                  //~v075R~

//**************************************************
//*inircolor
//* color section line process
//*parm:none
//*ret :rc
//**************************************************
//int inircolor(int Pwordno)                                       //~v075R~
//{                                                                //~v075R~
//  int palno,colno;                                               //~v075R~
//  UCHAR *pc;                                                     //~v075R~
//*********************************
//  if (Pwordno==1)	//no operand                                   //~v075R~
//  	return 4;                                                  //~v075R~
//  if (memcmp(Sgetsbuff,Spalid,PREFIXLEN) || !ISNUMSTR(Sgetsbuff+PREFIXLEN))//~v075R~
//  	return 4;                                                  //~v075R~
//  palno=atoi(Sgetsbuff+PREFIXLEN);                               //~v075R~
//  if (palno<0 || palno>15)                                       //~v075R~
//  	return 4;                                                  //~v075R~
//  pc=Sgetsbuff+strlen(Sgetsbuff)+1;	//second word,colorno fld  //~v075R~
//  if (memcmp(pc,Scolid,PREFIXLEN) || !ISNUMSTR(pc+PREFIXLEN))    //~v075R~
//  	return 4;                                                  //~v075R~
                                            //~5501R~
//  colno=atoi(pc+PREFIXLEN);                                      //~v075R~
//  if (colno<0 || colno>63)                                       //~v075R~
//  	return 4;                                                  //~v075R~
//  *(Scolornotbl+palno)=(UCHAR)colno;                             //~v075R~
//  return 0;                                                      //~v075R~
//}//inircolor                                                     //~v075R~

//**************************************************            //~5503I~
//*inigetfname                                                  //~5503I~
//* get ini file name                                           //~5503I~
//*parm:output area if you want copy                            //~5503R~
//*ret :same as input(if input is 0,return internal static area addr)//~5503R~
//**************************************************            //~5503I~
UCHAR *inigetfname(UCHAR *Pfname)                               //~5503I~
{                                                               //~5503I~
#ifdef UNX                                                         //~v21aI~
	static UCHAR Sinifile[]=WORKDIRPATHID PGMID ".ini";            //~v55jR~
#else                                                              //~v21aI~
static UCHAR Sinifile[]={WORKDIRPATHID PGMID ".INI"};           //~5503I~
#endif                                                             //~v21aI~
//***************                                               //~5503I~
	if (!Pfname)                                                //~5503I~
    	return Sinifile;                                        //~5503I~
    return strcpy(Pfname,Sinifile);                             //~5503I~
}//inigetfname                                                  //~5503I~
