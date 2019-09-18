//*CID://+vbp1R~:                             update#=  274;       //~vbp1R~
//*************************************************************
//*xedir.c*
//* execute key,dlcmd cut and paste,pathup,pathdown,linetop,lineend//~v55NR~
//*************************************************************
//vbp1:181028 new lineno specification:Select --[n];  select member from last//~vbp1I~
//vbd7:171119 "SEL all" support on file panel                      //~vbd7I~
//vb60:161127 select 1st entry when no filename operand (S [-n] n:line number)//~vb60I~
//vb35:160529 (BUG)locate cmd on dirlist fail when path is wildcard on root dir//~vb35I~
//vb31:160418 (LNX64)Compiler warning                              //~vb31I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vb2F:160229 W32 64 compiler warning                              //~vb2FI~
//vb18:151222 dlcmd rename loop(by u8len==0) by mixedstrupdate bug(codetbl indicate u8 but data is lcdbcs only)//~vb18I~
//vb17:151221 on dirlist;PasteIns to rename fld of line of dbcs member name cause corrupted display of rename fld//~vb17I~
//vawk:140605 (BUG:LNX)additional to vawj;lc len shrink but colpos remainsby setflddata;use dd2l like as other paste such as to cmdline//~vawkI~
//vawc:140601 support to paste to rename fld                       //~vaw9I~
//vaw9:140531 (W32UNICODE)recover UTF8 code on also rename fld     //~aw9I~//~vaw9R~
//vamJ:131121 (BUG)"%"/"$" cmd could not cut after cmd end         //~vamJI~
//vamy:131103 add dlcmd "$"(async version of "%")                  //~vamyI~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//vafc:120607 C4701 warning(used uninitialized variable) by VC6    //~vafcI~
//vaf3:120604 (BUG of v611)Select cmd for only 1 member fail if filename is space embedding//~vaf3I~
//vac1:120204 (SMB)smb node support                                //~vac1I~
//va0W:091007!(BUG)dir locate consider "2U" mode                   //~va0WI~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          rename/move.. by filename of the codepage              //~va00I~
//          locate by utf8str                                      //~va00I~
//          select cmd chk cpu8/cplc of dir open parm              //~va00I~
//va03:090605 (BUG)"S" lcmd abend for long path filename(MAXCOLUMN is shorter than _MAX_PATH;define MAXPARMSZ)//~va03I~
//v78M:080511 "pathup" to =1/=2 panel from root dir                //~v78MI~
//v78g:080312 on dirlist;execute locate cmd by type on filename fld//~v78gI~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v71J:061103 (BUG:3270)cmd err when option specified for select cmd for tso dir list//~v71JI~
//v717:060926 3270:dirlist support                                 //~v717I~
//v693:060423 (BUG)when scr resized,remains previous image         //~v693I~
//v621:050308 (WXE:BUG)scr-resize dose not reset dirlist expanded  //~v621I~
//v61m:050301 for Sx cmd(SB etc) also avoid to use /Mx parm for filename list//~v61mI~
//v611:050207 Select lcmd;select member if only one when no operand filename specified.//~v611I~
//v59T:041207 dirlist resizeing                                    //~v59TI~
//v59M:041121 sort on dir list parameter change sor [[{/|-}o]{n|s|t}[-]]//~v59MI~
//v59A:041118 Locate cmd:help for dirlist sorted by time/size      //~v59AI~
//            dir3.c                                               //~v59AI~
//v58p:040923 drop filename when dir paste of moved entry(after move)//~v58pI~
//            (filename is padded for undo)                        //~v58pI~
//v586:040823 (BUG)dirlist paste dose not paste attr fld           //~v586I~
//v57r:040530 dir sort cmd option fmt chng;[/o][-]{n|s|t}[-]       //~v57rI~
//v57g:040522 support locate cmd for dirlist sorted by time/size   //~v57gI~
//v55N:040318 linetop & lineend for dirlist                        //~v55NI~
//v55h:040214 (FTP)uid/gid display for remote file                 //~v55hI~
//v558:040204 new func:path up/down by A+left/right                //~v558I~
//v54f:040104 (FTP)DIR_SEPx for ftp                                //~v54fI~
//v51W:030810 dir lcmd %:apply cmd with filename parm as %.        //~v51WI~
//v50G:030201 add cmd "et"/"bt"/"st" for e/b/s /mt                 //~v50GI~
//v47R:020330 support cut/paste for dlcmd "o"                      //~v47RI~
//v47p:020313 (BUG)long paste(f11) string cut by rename fldsz      //~v47pR~
//v44e:011203 use not x but h for hex display                      //~v44eI~
//v440:011125 browse hex                                           //~v440I~
//v42y:011010 add cmd ek,bk,sk,ekn,bkn,skn                         //~v42yI~
//v20h:001003 LINUX support(F6:size,S+F6:uid and username toggle)  //~v20hI~
//            UNAME:username,UNAME+UID: by user id,none:size       //~v20hI~
//v20f:001001 LINUX support(uid/gid display on dirlist)            //~v20fI~
//v19y:000924 LINUX support(skip drive id chk for fullpath)        //~v19yI~
//v19a:000903 LINUX support(dir path seperator)                    //~v19aI~
//v182:001209 long filename display on dirlist(over attr fld)      //~v182I~
//v151:000311 set csr wait sign for dir cmd toggle size<->lineno   //~v151I~
//v144:000210:(BUG)parse err when space embeding for select file name.//~v144I~
//v13d:991023 *\ support for filecmd(edit/browsw/select/save/repl/create/append/copy/move/ini)//~v13dI~
//v137:991003 scroll down when reached to bottom line by field full on dir list//~v137I~
//v11i:990718 edit cmd help                                        //~v11iI~
//v11h:990717 support f10/f11 cut/paste of rename on dirlist       //~v11hI~
//v10P:990508 issue errmsg(csr pos err) for F6 on dirlist          //~v10PI~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v10LI~
//v10G:990417 EB/BB/SB for "e /mx","b /mx","s /mb"                 //~v10GI~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v0ie:980607 Locate cmd for disrlist                              //~v0ieI~
//v0fx:971116 (BUG)select for space embedding dir,cause parse err. //~v0fxI~
//                 membx of dir "a b"-->edit a b\membx             //~v0fxI~
//v0fp:971108 split dlcmd2-->dlcmd5.c                              //~v0fpI~
//v0el:970919 (BUG)select with wild card dir create like as "e *.c\x3.c"//~v0elI~
//v09w:970524:Select cmd support on dir list                       //~v09wI~
//v095:970405:DPMI version                                         //~v095I~
//            -\ of dbcs 2nd byte                                  //~v095I~
//v07s:960825:new ulib.h/ulibdef.h(no need base def by os2.h)      //~v07sI~
//            to speed up compile,drop include(caused by WIN95 modify)//~v07sI~
//v07e:960629:dir lcmd copy(PF10 and PF11)                         //~v07eI~
//v03u:950827:bug;ULHFLINECMD(lcmd reg sw) reset by xechar ignore//~v03uI~
//            lcmd input from other side of same pfc.           //~v03uI~
//            so move lcmd stack to pfh from pfc.(alt of v03q)  //~v03uI~
//*v030:950709:dir pgup/pgdn/filetop/fileend/lineup/linedown share with file//~v030I~
//*v020:950624:dir support(new)                                 //~v030R~
//*************************************************************
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
#ifdef W32                                                         //~v717I~
	#include <io.h>                                                //~v717I~
#endif                                                             //~v717I~
//*******************************************************
#include <ulib.h>
#include <uerr.h>
#include <uque.h>
#include <ustring.h>
#include <ufile.h>
#include <uparse.h>     //uparsein                                 //~v0fxI~
#include <uftp.h>     //uparsein                                   //~v54fI~
#include <ualloc.h>                                                //~v558I~
#include <uedit.h>                                                 //~v57gR~
#include <uedit2.h>                                                //~v57gI~
#include <u3270.h>                                                 //~v717I~
#include <ufilew.h>                                                //~vawcI~
#include <utf.h>                                                   //~vawcI~
#include <utrace.h>                                                //~vawkI~
#include <udbcschk.h>                                              //~vb17I~

#include "xe.h"
#include "xescr.h"
#include "xecsr.h"
#include "xefile.h"
#include "xefile13.h"                                              //~v61mI~
#include "xefile2.h"
#include "xefile3.h"
#include "xefile4.h"
#include "xefile5.h"                                               //~v11iI~
#include "xepan.h"                                              //~v030M~
#include "xedir.h"                                                 //~v07eI~
#include "xedir2.h"                                                //~v07eI~
                                                                   //~v182I~
#define XEGBL_DIR3                                                 //~v182I~
#include "xedir3.h"                                                //~v182I~
                                                                   //~v182I~
#include "xedlcmd.h"                                            //~v030R~
#include "xedlcmd2.h"                                              //~v10rI~
#include "xedlcmd5.h"                                              //~v0fpR~
#include "xedlcmd3.h"                                              //~v07eI~
#include "xefcmd22.h"   //fcmdscrollpage                           //~v0ieI~
#include "xefunc.h"
#include "xefunc2.h"                                               //~v78MI~
#include "xedcmd.h"                                                //~v13dM~
#include "xefsub.h"
#include "xesub.h"
#include "xeerr.h"                                                 //~v09wI~
#include "xefunct.h"                                               //~v61mI~
#include "xetso.h"                                                 //~v717I~
#include "xechar12.h"                                              //~va0WI~
#include "xeutf.h"                                                 //~vawcI~
#include "xecap.h"                                                 //~vbd7I~
//*******************************************************
#define SELECT_MODE(browsefuncid,editfuncid) (((browsefuncid)<<8)|(editfuncid & 255))//~v61mI~
#define SAVEDATAPOS 2                                              //~v07eM~
//*******************************************************
//static UCHAR Sbinsw;                                             //~v61mR~
static int Sbinsw;                                                 //~v61mI~
static UCHAR Sdlcmdsave[2+_MAX_PATH]="\0,";                        //~v07eR~
static int Sinternallocatesw;                                      //~v78gI~
//********************************************                     //~v10GI~
int dirfunccall(PUCLIENTWE Ppcw);                                  //~v07eI~
int dirpatherr(UCHAR *Ppath);                                      //~v0ieI~
//void dirddresetall(PUCLIENTWE Ppcw);                             //~v621R~
//void dirddresetallsub(PUCLIENTWE Ppcw,PUFILEH Ppfh);             //~v621R~
int dirlocateparmchk(char *Popd,int Psorttype,PUDIRLH Ppdh);       //~v57gI~
int func_select_filefuncid(PUCLIENTWE Ppcw,int Pbrowsesw,int Pfuncid);//~v61mI~
PUDIRLH getdefaultentry(PUFILEH Ppfh);                             //~vb60I~
int getlinenumbername(PUFILEH Ppfh,char *Popd,char *Pmembername);  //~vb60I~
//****************************************************************
// exec key for file panel
//*rc   :0
//****************************************************************
int func_exec_dir(PUCLIENTWE Ppcw)
{
  	PUFILEC  pfc;                                               //~v030R~
  	PUFILEH  pfh;                                               //~v03uI~
	int rc;                                                     //~v030I~
//****************************                                  //~v030I~
//**scroll chk                                                  //~v030I~
	if (rc=filescrollchk(Ppcw),rc)                              //~v030I~
		return rc;                                              //~v030I~
  	pfc=Ppcw->UCWpfc;                                           //~v030R~
  	pfh=pfc->UFCpfh;                                            //~v03uI~
  	if (pfh->UFHcmdlinectr 			//cmd line exist            //~v03uR~
  	&&  (!UCBITCHK(pfh->UFHflag2,UFHF2LCMDCOMP) || pfh->UFHpendctr))//~v03uR~
  		if (rc=dlcmdmain(Ppcw),rc<4)	//pending               //~v030R~
        	rc=0;						//no beep               //~v030R~
	return rc;                                                  //~v030I~
}//func_exec_dir                                                //~v030R~
                                                                   //~v07eI~
//**************************************************************** //~v07eI~
// dlcmd cut                                                       //~v07eI~
//*rc   :0                                                         //~v07eI~
//**************************************************************** //~v07eI~
int func_dlcmdcut_dir(PUCLIENTWE Ppcw)                             //~v07eI~
{                                                                  //~v07eI~
    PULINEH plh;                                                   //~v07eI~
    PUDIRLH pdh;                                                   //~v07eI~
	PUSCRD psd;                                                    //~v07eI~
    UCHAR  incmd,cmd;                                              //~v07eR~
	UCHAR  data[_MAX_PATH];                                        //~v07eR~
	int rc;                                                        //~v07eR~
	int pathlen;                                                   //~v58pI~
#ifdef FTPSUPP                                                     //~v717I~
    PUFTPHOST puftph;                                              //~v717I~
    char membname[DSN_MAXMEMBERNAMELEN+1];                         //~v717I~
#endif                                                             //~v717I~
//****************************                                     //~v07eI~
	if (!CSRONFILELINE(Ppcw))				//out of screen        //~v07eI~
        return 4;                                                  //~v07eI~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~v07eI~
	plh=psd->USDbuffc;                                             //~v07eI~
    pdh=UGETPDH(plh);                                              //~v07eI~
    incmd=cmd=(UCHAR)toupper(*plh->ULHlinecmd);   //input id       //~v07eR~
    if (!incmd)					//no input                         //~v07eR~
    {                                                              //~v54fI~
    	if (UCBITCHK(pdh->UDHupdatetype,UDHUTCOPYO))               //~v07eR~
        	cmd='C';                                               //~v07eR~
        else                                                       //~v07eI~
    		if (UCBITCHK(pdh->UDHupdatetype,UDHUTMOVEO|UDHUTMOVEOCHILD))//~v07eR~
	        	cmd='M';                                           //~v07eR~
            else                                                   //~v11hI~
    			if (UCBITCHK(pdh->UDHupdatetype,UDHUTRENAMEO))     //~v11hI~
		        	cmd='R';                                       //~v11hI~
                else                                               //~vamJI~
    			if (UCBITCHK(pdh->UDHflag4,UDHF4APPCMD))           //~vamJI~
		        	cmd='%';                                       //~vamJI~
                else                                               //~vamJI~
    			if (UCBITCHK(pdh->UDHflag4,UDHF4APPCMDASYNC))      //~vamJI~
                    cmd=UDLCCMD_APPASYNC;                          //~vamJI~
    }                                                              //~v54fI~
	rc=0;                                                          //~v07eI~
    switch(cmd)                                                    //~v07eR~
    {                                                              //~v07eI~
    case 'A':       //attrib                                       //~v07eI~
		if (dirgetflddata(Ppcw,plh,PANL310ATTR,data)<=0)           //~v07eR~
			return dlcmdnoattrerr();                               //~v07eR~
    	break;                                                     //~v07eI~
    case 'O': 		//open cmd                                     //~v47RI~
    case 'G': 		//grep cmd                                     //~v75JI~
//  	if (dirgetflddata(Ppcw,plh,PANL310RENAME,data)<=0)         //~v47RI~//~va00R~
    	if (BYUTF8_dirgetflddata(Ppcw,plh,PANL310RENAME,data)<=0)  //~va00I~
			return dlcmdnodesterr();                               //~v47RI~
    	cmd=*plh->ULHlinecmd; //keep upper/lower case              //~v47RI~
    	break;                                                     //~v47RI~
    case 'C': 		//copy input                                   //~v07eI~
    case 'M': 		//move input                                   //~v07eI~
    case 'R': 		//rename input                                 //~v11hI~
    	if (incmd)	//cmd input                                    //~v07eI~
        {                                                          //~v07eI~
//			if (dirgetflddata(Ppcw,plh,PANL310RENAME,data)<=0)     //~v07eR~//~va00R~
#ifdef W32UNICODE                                                  //~vam9I~
			if (dirgetflddata_l2f(DGFDL2FO_UD,Ppcw,plh,PANL310RENAME,data,NULL/*swl2f*/)<=0)//~vam9R~
#else                                                              //~vam9I~
			if (BYUTF8_dirgetflddata(Ppcw,plh,PANL310RENAME,data)<=0)//~va00I~
#endif                                                             //~vam9I~
				return dlcmdnodesterr();                           //~v07eR~
		}                                                          //~v07eI~
    	else                                                       //~v07eR~
			if (pdh->UDHrenamesv)                                  //~v07eR~
            {                                                      //~v58pI~
//				strcpy(data,pdh->UDHrenamesv);                     //~v07eR~//~va00R~
  				strcpy(data,PDH_UDHrenamesv(pdh));                 //~va00I~
    			if (cmd=='M')	//after move                       //~v58pI~
                {                                                  //~v58pI~
#ifdef FTPSUPP                                                     //~v717I~
					uftpisremote(data,&puftph);                    //~v717I~
				  if (UFTPHISTSO(puftph))	//target is remote TSO //~v717R~
                  {                                                //~v717I~
                  	if (u3270getmembname(0,data,membname))	//membnamelen>0//~v717I~
 						if (!stricmp(membname,pdh->UDHname))       //~v717R~
		                  	u3270parentdsn(U3PL_DROPMEMBER,data,data);	//membnamelen>0//~v717R~
                  }                                                //~v717I~
                  else                                             //~v717I~
                  {                                                //~v717I~
#endif                                                             //~v717I~
                	pathlen=PATHLEN(data);                         //~v58pI~
                    if (pathlen>0                                  //~v58pI~
#ifdef UNX                                                         //~v58pI~
 					&& !strcmp(data+pathlen,pdh->UDHname))         //~v58pI~
#else                                                              //~v58pI~
 					&& !stricmp(data+pathlen,pdh->UDHname))        //~v58pI~
#endif                                                             //~v58pI~
						*(data+pathlen)=0;                         //~v58pI~
#ifdef FTPSUPP                                                     //~v717I~
                  }//not TSO                                       //~v717I~
#endif                                                             //~v717I~
                }                                                  //~v58pI~
            }                                                      //~v58pI~
			else                                                   //~v07eR~
        		rc=4;                                              //~v07eR~
    	break;                                                     //~v07eI~
    case '%': 		//apply cmd                                    //~v51WI~
    case UDLCCMD_APPASYNC: 		//apply cmd  async                 //~vamyI~
//		if (dirgetflddata(Ppcw,plh,PANL310RENAME,data)<=0)         //~v51WI~//~va00R~
		if (BYUTF8_dirgetflddata(Ppcw,plh,PANL310RENAME,data)<=0)  //~va00I~
			return dlcmdnodesterr();                               //~v51WI~
    	break;                                                     //~v51WI~
    default:                                                       //~v07eI~
        rc=4;                                                      //~v07eR~
    }                                                              //~v07eI~
    if (rc)                                                        //~v07eI~
    {                                                              //~v07eI~
//  	uerrmsg("Support Attrib/Copy/Move line copy only",         //~v11hR~
//  				"属性変更/複写/移動 行の複写のみ可能");        //~v095R~
//  				"属性変更/複写/移動 行の複写のみ可\x94\\");    //~v11hR~
//  	uerrmsg("Support Attrib/Copy/Move/Rename line copy only",  //~v47RR~
//  				"属性変更/複写/移動/改名 行の複写のみ可\x94\\");//~v47RR~
//  	uerrmsg("Support Attrib/Copy/Move/Rename/Open line copy only",//~v51WR~
//  				"属性変更/複写/移動/改名/オープン 行の複写のみ可\x94\\");//~v51WR~
//  	uerrmsg("Support Attrib/Copy/Move/Rename/Open/%%cmd-exec line copy only",//~v75JR~
//  				"属性変更/複写/移動/改名/オープン/%%コマンド実行 行の複写のみ可\x94\\");//~v75JR~
//  	uerrmsg("Support Attrib/Copy/Move/Rename/Open/Grep/%%cmd-exec line copy only",//~v75JI~//~vamyR~
//  				"属性変更/複写/移動/改名/オープン/Grep/%%コマンド実行 行の複写のみ可\x94\\");//~v75JI~//~vamyR~
    	uerrmsg("Cmd copy supports Attrib/Copy/Move/Rename/Open/Grep/%%/%c only",//~vamyI~
    				"属性変更/複写/移動/改名/オープン/Grep/%%/%c の行複写のみ可\x94\\",//~vamyI~
                    UDLCCMD_APPASYNC);	                           //~vamyI~
        return 4;                                                  //~v07eI~
    }                                                              //~v07eI~
	*Sdlcmdsave=cmd;                                               //~v07eI~
	strcpy(Sdlcmdsave+SAVEDATAPOS,data);                           //~v07eI~
    uerrmsg(Sdlcmdsave,0);	//confirm                              //~v07eR~
    UTRACED("cutdata",Sdlcmdsave,(int)strlen(Sdlcmdsave));              //~vawkR~//~vb30R~
	return func_nextline(Ppcw);                                    //~v07eI~
}//func_dlcmdcut_dir                                               //~v07eI~
//**************************************************************** //~v07eI~//~vawkR~
//*set rename ddfmt before UDHrenamesv setup                       //~vawkI~
//**************************************************************** //~vawkI~
int xedirsetuprenamedraw(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh)//~vawkR~
{                                                                  //~vawkI~
	UCHAR *pc,*pcd,*pct;                                           //~vawkR~
    int lenlc;                                                     //~vawkR~
//************************                                         //~vawkI~
  	if (dirsetflddata(Ppcw,Pplh,PANL310RENAME,Sdlcmdsave+SAVEDATAPOS)<=0)//~vawkI~
  		return 4;                                                  //~vawkI~
	if (dirgetfldpos(Ppcw,Pplh,PANL310RENAME,&pc,&pcd)<=0)         //~vawkI~
		return 4;                                                  //~vawkI~
//  lenlc=strlen(pc);                                              //~vawkI~//~vb30R~
    lenlc=(int)strlen(pc);                                         //~vb30I~
    pct=Ppdh->UDHrename_codetype;                                  //~vawkI~
    if (!pct)                                                      //~vawkI~
    	return 4;                                                  //~vawkI~
	UCBITOFF(Ppdh->UDHflag4,UDHF4RENAMEU8|UDHF4RENAMELC);          //~vawkI~
//  if (memchr(pct,XEUTFCT_UTF8,lenlc))                            //~vawkI~//~vb30R~
    if (memchr(pct,XEUTFCT_UTF8,(size_t)lenlc))                    //~vb30I~
		UCBITON(Ppdh->UDHflag4,UDHF4RENAMEU8);                     //~vawkI~
//  if (memchr(pct,XEUTFCT_LC,lenlc))                              //~vawkR~//~vb30R~
    if (memchr(pct,XEUTFCT_LC,(size_t)lenlc))                      //~vb30I~
		UCBITON(Ppdh->UDHflag4,UDHF4RENAMELC);                     //~vawkI~
    UCBITOFF(Ppdh->UDHflag2,UDHF2RENAMEOVF);  //clear ts fld if ovf//~vawkI~
    UCBITON(Ppdh->UDHflag5,UDHF5PASTERENAME);  //draw by ddfmt by UDHrename_codetype//~vawkR~
    if (lenlc>(int)((offsetof(UDIRLD,UDDrsv3[0])-offsetof(UDIRLD,UDDrname[0]))))//~vawkR~
    {                                                              //~vawkR~
        UCBITON(Ppdh->UDHflag2,UDHF2RENAMEOVF);  //protect clear by func_draw_dir//~vawkR~
//        len=UDIRLDSZ-offsetof(UDIRLD,UDDrname[0])-lenlc;         //~vawkR~
//        if (len>0)  //clear after rename overflow                //~vawkR~
//        {                                                        //~vawkR~
//            memset(pc+lenlc,0,len);                              //~vawkR~
//            memset(pcd+lenlc,0,len);                             //~vawkR~
//        }                                                        //~vawkR~
    }                                                              //~vawkR~
    return 0;                                                      //~vawkI~
}//xedirsetuprenamedraw                                            //~vawkR~
//**************************************************************** //~v07eI~
// dlcmd paste by F11                                              //~v07eI~//~vawkR~
//*rc   :0                                                         //~v07eI~
//**************************************************************** //~v07eI~
int func_dlcmdpaste_dir(PUCLIENTWE Ppcw)                           //~v07eI~
{                                                                  //~v07eI~
    PULINEH plh;                                                   //~v07eI~
	PUSCRD psd;                                                    //~v07eI~
	PUDIRLH pdh;                                                   //~v47pR~
	int rc,posy;                                                   //~v07eR~
//  int len;                                                       //~v47pR~//~vawkR~
//****************************                                     //~v07eI~
	if (!CSRONFILELINE(Ppcw))				//out of screen        //~v07eI~
        return 4;                                                  //~v07eI~
	psd=Ppcw->UCWpsd+(posy=Ppcw->UCWrcsry);                        //~v07eR~
	plh=psd->USDbuffc;                                             //~v07eI~
    pdh=UGETPDH(plh);                                              //~v47pR~
    if (!*Sdlcmdsave)                                              //~v07eR~
    {                                                              //~v07eI~
		uerrmsg("No saved data to be copy",                        //~v07eM~
				"複写データが保存されていません");                 //~v07eM~
        return 4;                                                  //~v07eI~
    }                                                              //~v07eI~
//setup for funccall like as kbdproc                               //~v07eI~
	if (rc=dirfunccall(Ppcw),rc)                                   //~v07eI~
    	return 0;           //already belled at funccall           //~v07eR~
    if (*Sdlcmdsave=='A')	//attrib                               //~v07eI~
    {                                                              //~v07eI~
		if (dirsetflddata(Ppcw,plh,PANL310ATTR,Sdlcmdsave+SAVEDATAPOS)<=0)//~v07eR~
			return 4;                                              //~v07eR~
		UCBITON(pdh->UDHflag,UDHFDDSETUP);	//skip attr setup      //~v586I~
	}                                                              //~v07eI~
    else 		//copy/move/rename                                 //~v11hR~
    {                                                              //~v07eI~
//  	if (dirsetflddata(Ppcw,plh,PANL310RENAME,Sdlcmdsave+SAVEDATAPOS)<=0)//~v07eR~//~va00R~
//  	if (BYUTF8_dirsetflddata(Ppcw,plh,PANL310RENAME,Sdlcmdsave+SAVEDATAPOS)<=0)//~va00R~//~va0GR~
//  	if (dirsetflddata(Ppcw,plh,PANL310RENAME,Sdlcmdsave+SAVEDATAPOS)<=0)//~va0GI~//~vawkR~
//  		return 4;                                              //~v07eI~//~vawkR~
//        len=(int)strlen(Sdlcmdsave+SAVEDATAPOS);                   //~v47pR~//~vawkR~
//        if (len>(int)((offsetof(UDIRLD,UDDrsv3[0])-offsetof(UDIRLD,UDDrname[0]))))//~v47pR~//~vawkR~
//            UCBITON(pdh->UDHflag2,UDHF2RENAMEOVF);  //protect clear by func_draw_dir//~v47pR~//~vawkR~
		xedirsetuprenamedraw(0,Ppcw,plh,pdh);                      //~vawkR~
        UCBITOFF(pdh->UDHflag,UDHFDDSETUP);  //dirfiunccall->dlcmdfe cleard rename/ts fld//~vawkI~
    }                                                              //~v07eI~
	UCBITON(plh->ULHflag,ULHFDRAW); //required to redraw rename fld dirfunccall set and reset//~vawcI~
    if (posy==Ppcw->UCWrcsry)                                      //~v07eI~
//  	rc=func_nextline(Ppcw);                                    //~v137R~
    	rc=dirnexttab(Ppcw);                                       //~v137I~
	else                                                           //~v07eI~
		rc=0;                                                      //~v07eI~
    UTRACEP("%s:pastebyF11 rc=%d\n",UTT,rc);                       //~vawkI~
	return rc;                                                     //~v07eI~
}//func_dlcmdpaste_dir                                             //~v07eI~
//**************************************************************** //~vawcR~
// paste to rename fld                                             //~vawcR~
//*rc   :0                                                         //~vawcR~
//**************************************************************** //~vawcR~
//**************************************************************** //~vawcI~
int dirpasterenamefld(int Popt,PUCLIENTWE Ppcw,char *Pdata,char *Pdbcs,int Poffs,int Plen)//~vawcI~
{                                                                  //~vawcI~
    PULINEH plh;                                                   //~vawcI~
	PUSCRD psd;                                                    //~vawcI~
	PUDIRLH pdh;                                                   //~vawcI~
    int len,lenlc,lenu8,lenu8out,lenlcout,outlen,szrename,fldsz,readlen,opt,rc2;//~vawcR~
    int lenlcdata,lenu8data,swu8,szrenameu8;                       //~vawcR~
    UCHAR *pc,*pcd;                                                //~vawcR~
    char *plc,*putf8,*pct;                                         //~vawcI~
    char wklcdata[_MAX_PATH];                                      //~vawcI~
    char wkctdata[_MAX_PATH];                                      //~vawcI~
//****************************                                     //~vawcI~
//*FIXME text on linux:FIXED                                       //~vawcR~
    swu8=(Popt & DRFPO_U8)!=0;                                     //~vawcI~
	if (!CSRONFILELINE(Ppcw))				//out of screen        //~vawcI~
        return 4;                                                  //~vawcI~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~vawcR~
	plh=psd->USDbuffc;                                             //~vawcI~
    pdh=UGETPDH(plh);                                              //~vawcI~
    szrename=UDHRENAME_CODETYPESZ-1;                               //~vawcI~
    szrenameu8=UDHRENAME_UTF8SZ;                                   //~vawcI~
	fldsz=dirgetfldpos(Ppcw,plh,PANL310RENAME,&pc,&pcd);           //~vawcR~
	if (fldsz<0)                                                   //~vawcR~
		return 4;                                                  //~vawcI~
    plc=pc;                                                        //~vawcI~
//  lenlc=strlen(plc);                                             //~vawcI~//~vb30R~
    lenlc=(int)strlen(plc);                                        //~vb30I~
    putf8=pdh->UDHrename_utf8;                                     //~va0GI~//~vawcI~
//  lenu8=strlen(putf8);                                           //~vawcI~//~vb30R~
    lenu8=(int)strlen(putf8);                                      //~vb30I~
    pct=pdh->UDHrename_codetype;                                   //~va0GI~//~vawcI~
  if (Popt & DRFPO_SETCT2)  //paste utf8;Gcmdbufflc,Gcmdbufflc was set by captofld//~vawkR~
  {                                                                //~vawkR~
    opt=XEUTFMSUO_STRZ;                                            //~vawkR~
    if (Popt & DRFPO_INS)                                          //~vawkR~
        opt|=XEUTFMSUO_INS;                                        //~vawkR~
    lenu8out=lenu8; //as input                                     //~vawkI~
//  lenu8data=strlen(Gcmdbuffu8);                                  //~vb18I~//~vb30R~
    lenu8data=(int)strlen(Gcmdbuffu8);                             //~vb30I~
    xeutf_mixedstrupdate(opt,pc,putf8,pct,pcd,lenlc,&lenlcout,&lenu8out,//~vawkR~
                        Poffs,szrename,                            //~vawkR~
//                      Gcmdbufflc,Pdata,Gcmdbuffct,Pdbcs,Gcmdbufflclen,Plen,szrenameu8);//~vawkR~//~vb18R~
                        Gcmdbufflc,Gcmdbuffu8,Gcmdbuffct,Pdbcs,Gcmdbufflclen,lenu8data,szrenameu8);//~vb18R~
  }                                                                //~vawkR~
  else                                                             //~vawkR~
  {                                                                //~vawcI~
    if (swu8)                                                      //~vawcI~
    {                                                              //~vawcI~
  	  	opt=XEUTFF2LCO_ERRREP;                                     //~vawcI~
		rc2=xeutfcvf2lc(opt,Pdata,Plen,wklcdata,wkctdata,sizeof(wklcdata),&outlen,&readlen);//~vawcI~
        if (rc2>=XEUTFF2LCRC_UTF8ERR)                              //~vawcI~
        	return 4;                                              //~vawcI~
        lenlcdata=outlen;                                          //~vawcI~
        lenu8data=Plen;                                            //~vawcI~
    }                                                              //~vawcI~
    else                                                           //~vawcI~
    {                                                              //~vawcI~
//  	len=min(Plen,sizeof(wklcdata));                            //~vawcI~//~vb30R~
    	len=min(Plen,(int)sizeof(wklcdata));                       //~vb30I~
//      UmemcpyZ(wklcdata,Pdata,len);                              //~vawcI~//~vb30R~
        UmemcpyZ(wklcdata,Pdata,(size_t)len);                      //~vb30I~
//      memset(wkctdata,0,len);                                    //~vawcI~//~vb17R~
		{                                                          //~vb17I~
        	int ii;                                                //~vb17I~
            char *pcd2,*pct2;                                      //~vb17I~
        	for (ii=0,pcd2=Pdbcs,pct2=wkctdata;ii<len;ii++,pcd2++,pct2++)//~vb17R~
            	if (UDBCSCHK_DBCSCOLS(*pcd2))                      //~vb17I~
                	*pct2=XEUTFCT_LC;                              //~vb17I~
                else                                               //~vb17I~
                	*pct2=0;                                       //~vb17I~
        }                                                          //~vb17I~
        lenlcdata=len;                                             //~vawcI~
        lenu8data=len;                                             //~vawcI~
    }                                                              //~vawcI~
    opt=XEUTFMSUO_STRZ;                                            //~vawcI~
    if (Popt & DRFPO_INS)                                          //~vawcI~
        opt|=XEUTFMSUO_INS;                                        //~vawcI~
	xeutf_mixedstrupdate(opt,plc,putf8,pct,pcd,lenlc,&lenlcout,&lenu8out,//~vawcR~
							Poffs,szrename,                        //~vawcI~
							wklcdata,Pdata,wkctdata,Pdbcs,lenlcdata,lenu8data,szrenameu8);//~vawcR~
  }//!SETCT2                                                       //~vawcI~
//  if (memchr(pct,XEUTFCT_UTF8,lenlcout))     //same as dirsetflddata_f2l to set swddfmt//~vawcR~//~vb30R~
    if (memchr(pct,XEUTFCT_UTF8,(size_t)lenlcout))     //same as dirsetflddata_f2l to set swddfmt//~vb30I~
		UCBITON(pdh->UDHflag4,UDHF4RENAMEU8);                      //~vawcI~
//  if (memchr(pct,XEUTFCT_LC,lenlcout))                           //~vawcR~//~vb30R~
    if (memchr(pct,XEUTFCT_LC,(size_t)lenlcout))                   //~vb30I~
		UCBITON(pdh->UDHflag4,UDHF4RENAMELC);                      //~vawcI~
    	                                                           //~vawcI~
	UCBITON(plh->ULHflag,ULHFDRAW);                                //~vawcM~
    UCBITON(pdh->UDHflag,UDHFDDSETUP);  //noneed to setup, then call drawrename//~vawcI~
    if (lenlcout>(int)((offsetof(UDIRLD,UDDrsv3[0])-offsetof(UDIRLD,UDDrname[0]))))//~vawcR~
    {                                                              //~vawcI~
      	UCBITON(pdh->UDHflag2,UDHF2RENAMEOVF);  //protect clear by func_draw_dir//~vawcI~
//      len=UDIRLDSZ-offsetof(UDIRLD,UDDrname[0])-lenlcout;        //~vawcI~//~vb30R~
        len=UDIRLDSZ-(int)offsetof(UDIRLD,UDDrname[0])-lenlcout;   //~vb30I~
        if (len>0)	//clear after rename overflow                  //~vawcI~
        {                                                          //~vawcI~
//      	memset(pc+lenlcout,0,len);                             //~vawcI~//~vb30R~
        	memset(pc+lenlcout,0,(size_t)len);                     //~vb30I~
//      	memset(pcd+lenlcout,0,len);                            //~vawcI~//~vb30R~
        	memset(pcd+lenlcout,0,(size_t)len);                    //~vb30I~
        }                                                          //~vawcI~
    }                                                              //~vawcI~
	return 0;                                                      //~vawcR~
}//dirpasterenamefld                                               //~vawcI~
//**************************************************************** //~v10rI~
// dlcmd change size display option                                //~v10rI~
//*parm1:pcw                                                       //~v10rI~
//*ret  :rc                                                        //~v10rI~
//**************************************************************** //~v10rI~
int func_dlcmdchngsz_dir(PUCLIENTWE Ppcw)                          //~v10rI~
{                                                                  //~v10rI~
    PULINEH plh;                                                   //~v10rI~
    PUDIRLH pdh;                                                   //~v10rI~
	PUSCRD psd;                                                    //~v10rI~
	int opt;                                                       //~v10rI~
    int rc;                                                        //~v151I~
//****************************                                     //~v10rI~
    if (UCBITCHK(Gscrstatus,GSCRSDIRUGNAME))    //in user display  //~v20hI~
    {                                                              //~v20hI~
        UCBITOFF(Gscrstatus,GSCRSDIRUGNAME);    //reset,display size//~v20hI~
        uerrmsg("Now filesize display mode",                       //~v20hI~
                "ファイルサイズ\x95\\示に変更");                   //~v182R~
//      dirddresetall(Ppcw);                                       //~v693R~
        dirddresetall(DDRESET_LINECOUNT,Ppcw);                     //~v693I~
        return 0;                                                  //~v20hI~
    }                                                              //~v20hI~
	if (!CSRONFILELINE(Ppcw))				//out of screen        //~v10rI~
    {                                                              //~v20hI~
//      return 4;                                                  //~v10PR~
//      return errcsrpos();                                        //~v20hR~
    	uerrmsg("To toggle filesize and lineno,move cursor to the line.",//~v20hR~
        		"ファイルサイズ/行数の切替えにはカー\x83\\ルを移動させる");//~v182R~
            return 4;                                              //~v20hI~
    }                                                              //~v20hI~
	psd=Ppcw->UCWpsd+Ppcw->UCWrcsry;                               //~v10rI~
	plh=psd->USDbuffc;                                             //~v10rI~
    pdh=UGETPDH(plh);                                              //~v10rI~
	opt=(UCBITCHK(pdh->UDHflag2,UDHF2DISPLC)==0);	//toggle       //~v10rI~
//  if (dlcmdsetszorlc(Ppcw,plh,opt))                              //~v151R~
	csrsetwait(1);      //set wait mode csr if now not wait        //~v151I~
    rc=dlcmdsetszorlc(Ppcw,plh,opt);                               //~v151I~
    csrsetwait(0);      //reset wait mode csr                      //~v151I~
    if (rc)                                                        //~v151I~
    	return 4;                                                  //~v10rI~
	if (opt)                                                       //~v10rI~
    	uerrmsg("Size by LineCount",                               //~v10rI~
        		"行数\x95\\示");                                   //~v10rI~
	else                                                           //~v10rI~
    	uerrmsg("Size by ByteCount",                               //~v10rI~
        		"バイト\x95\\示");                                 //~v10rI~
	return 0;                                                      //~v10rI~
}//func_dlcmdchngsz_dir                                            //~v10rI~
                                                                   //~v20fI~
//#ifdef UNX                                                       //~v55hR~
#ifdef FTPSUPP                                                     //~v55hI~
                                                                   //~v20fI~
//**************************************************************** //~v20fI~
// dlcmd change size display option                                //~v20fI~
//*parm1:pcw                                                       //~v20fI~
//*ret  :rc                                                        //~v20fI~
//**************************************************************** //~v20fI~
int func_dlcmduidorsz_dir(PUCLIENTWE Ppcw)                         //~v20fI~
{                                                                  //~v20fI~
	PUFILEH pfh;                                                   //~v55hI~
//****************************                                     //~v20fI~
	pfh=UGETPFHFROMPCW(Ppcw);                                      //~v55hI~
#ifdef W32                                                         //~v55hM~
    if (!FILEISREMOTE(pfh))                                        //~v55hI~
    	uerrmsg("This Dir is Local",                               //~v55hI~
        		"このDirはLocalです");                             //~v55hM~
    else                                                           //~v55hI~
    	uerrmsg("user/group display mode",                         //~v55hI~
        		"ユーザー/グループ\x95\\示");                      //~v55hI~
    UCBITON(Gscrstatus,GSCRSDIRUGNAME); //display user             //~v55hI~
#else                                                              //~v55hI~
	if (!UCBITCHK(Gscrstatus,GSCRSDIRUGNAME))	//in szie display  //~v20hR~
    {                                                              //~v20hI~
		UCBITON(Gscrstatus,GSCRSDIRUGNAME);	//display user         //~v20hI~
	  if (FILE_ISSMB(pfh))                                         //~vac1M~
      {                                                            //~vac1M~
       if (UCBITCHK((pfh)->UFHflag12,UFHF12RWIN))                  //~vac1R~
       {                                                           //~vac1I~
		UCBITOFF(Gscrstatus,GSCRSDIRUGNAME);	//display user     //~vac1I~
        uerrmsg("No UserID on Woindow(SMB)",0);                    //~vac1I~
        return 4;                                                  //~vac1I~
       }                                                           //~vac1I~
       else                                                        //~vac1I~
       {                                                           //~vac1I~
        UCBITON(Gscrstatus,GSCRSDIRUGID);   //by id,no name available//~vac1M~
        uerrmsg("By uid/gid(SMB)",                                 //~vac1M~
                "uid/gid\x95\\示(SMB)");                           //~vac1M~
       }                                                           //~vac1I~
      }                                                            //~vac1M~
      else                                                         //~vac1M~
      {                                                            //~vac1M~
    	uerrmsg("user/group display mode",                         //~v20hI~
        		"ユーザー/グループ\x95\\示");                      //~v20hI~
      }                                                            //~vac1I~
    }                                                              //~v20hI~
    else                                                           //~v20hI~
    {                                                              //~v55hI~
		if (UCBITCHK(Gscrstatus,GSCRSDIRUGID))	//by id            //~v20hI~
        {                                                          //~v20hI~
			UCBITOFF(Gscrstatus,GSCRSDIRUGID);	//by name          //~v20hI~
    		uerrmsg("By user/group",                               //~v20hR~
        			"user/group\x95\\示");                         //~v20hR~
        }                                                          //~v20hI~
        else    //by name                                          //~v20hI~
        {                                                          //~v20hI~
			UCBITON(Gscrstatus,GSCRSDIRUGID);	//by id            //~v20hI~
    		uerrmsg("By uid/gid",                                  //~v20hI~
        			"uid/gid\x95\\示");                            //~v20hI~
        }                                                          //~v20hI~
	    if (FILEISREMOTE(pfh))                                     //~v55hI~
        {                                                          //~vac1I~
          if (FILE_ISSMB(pfh)) //Gscsrstatus is global;so flag is changed//~vac1R~
	      	uerrmsgcat(";Remote(Samba) is id only",0);             //~vac1R~
          else                                                     //~vac1I~
//      	uerrmsg("This Dir is Remote",                          //~v55hI~//~vac1R~
        	uerrmsgcat("This Dir is Remote",                       //~vac1R~
    	    		"このDirはRemoteです");                        //~v55hI~
        }                                                          //~vac1I~
    }                                                              //~v55hI~
#endif                                                             //~v55hI~
//  dirddresetall(Ppcw);                                           //~v693R~
    dirddresetall(DDRESET_UGID,Ppcw);                              //~v693I~
    return 0;                                                      //~v20hI~
}//func_dlcmduidorsz_dir                                           //~v20fR~
                                                                   //~v20fI~
#endif                                                             //~v20fI~
                                                                   //~v20fI~
//**************************************************************** //~v182I~
// change to display long filename over attr field                 //~v182I~
//*parm1:pcw                                                       //~v182I~
//*ret  :rc                                                        //~v182I~
//**************************************************************** //~v182I~
int func_dlcmdlfn_dir(PUCLIENTWE Ppcw)                             //~v182I~
{                                                                  //~v182I~
//****************************                                     //~v182I~
    if (UCBITCHK(Gdir3status,GDIR3SLFN))  //by long                //~v182I~
    {                                                              //~v182I~
        UCBITOFF(Gdir3status,GDIR3SLFN);  //toggle                 //~v182I~
        uerrmsg("Attr Display",                                    //~v182I~
                "属性\x95\\示");                                   //~v182I~
    }                                                              //~v182I~
    else    //by short name                                        //~v182I~
    {                                                              //~v182I~
        UCBITON(Gdir3status,GDIR3SLFN);  //toggle                  //~v182I~
        uerrmsg("LongFileName",                                    //~v182I~
                "長いファイル名\x95\\示");                         //~v182I~
    }                                                              //~v182I~
//  dirddresetall(Ppcw);                                           //~v693R~
    dirddresetall(DDRESET_LFN,Ppcw);                               //~v693I~
    return 0;                                                      //~v182I~
}//func_dlcmlfn_dir                                                //~v182I~
                                                                   //~v182I~
//**************************************************************** //~v20hI~
// reset ddsetup all client                                        //~v20hI~
//*parm1:pcw                                                       //~v20hI~
//*ret  :rc                                                        //~v20hI~
//**************************************************************** //~v20hI~
//void dirddresetall(PUCLIENTWE Ppcw)                              //~v693R~
void dirddresetall(int Popt,PUCLIENTWE Ppcw)                       //~v693I~
{                                                                  //~v20hI~
	UQUEH *pqh;                                                    //~v20hM~
	PUCLIENTWE pcw;                                                //~v20hM~
  	PUFILEC  pfc;                                                  //~v182I~
  	PUFILEH  pfh;                                                  //~v182I~
//*******************************                                  //~v20hI~
//apply to all dir pcw                                             //~v20hM~
  	pfc=Ppcw->UCWpfc;                                              //~v182I~
    pqh=UGETQHDR(Ppcw);                                            //~v20hM~
  	pfh=pfc->UFCpfh;                                               //~v182I~
	pfh->UFHfindctr++;		//reset find                           //~v182I~
                                                                   //~v182I~
    for (pcw=UGETQTOP(pqh);pcw;pcw=UGETQNEXT(pcw))                 //~v20hM~
    	if (pcw->UCWtype==UCWTDIR)                                 //~v20hM~
//  		dirddresetallsub(pcw,pfh);                             //~v693R~
    		dirddresetallsub(Popt,pcw,pfh);                        //~v693I~
	if (pcw=scrgetcw(-1),pcw)			//other client             //~v20hM~
    {                                                              //~v20hM~
        pqh=UGETQHDR(pcw);                                         //~v20hM~
        for (pcw=UGETQTOP(pqh);pcw;pcw=UGETQNEXT(pcw))             //~v20hM~
            if (pcw->UCWtype==UCWTDIR)                             //~v20hM~
//              dirddresetallsub(pcw,pfh);                         //~v693R~
                dirddresetallsub(Popt,pcw,pfh);                    //~v693I~
    }                                                              //~v20hM~
	return;                                                        //~v20hR~
}//dirddresetall                                                   //~v20hI~
//**************************************************************** //~v20fI~
// reset ddsetup all line                                          //~v20fI~
//*parm1:pcw                                                       //~v20fI~
//*ret  :rc                                                        //~v20fI~
//**************************************************************** //~v20fI~
//void dirddresetallsub(PUCLIENTWE Ppcw,PUFILEH Ppfh)              //~v693R~
void dirddresetallsub(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh)       //~v693I~
{                                                                  //~v20fI~
  	PULINEH  plh;                                                  //~v20fI~
  	PUDIRLH  pdh;                                                  //~v20fI~
//****************************                                     //~v20fI~
    plh=UGETQTOP(&Ppfh->UFHlineque);                               //~v182R~
    for (;plh;plh=UGETQNEXT(plh))                                  //~v20fI~
    {                                                              //~v20fI~
        if (plh->ULHtype!=ULHTDATA) //file data                    //~v20fI~
            continue;                                              //~v20fI~
        pdh=UGETPDH(plh);                                          //~v20fI~
    	UCBITOFF(pdh->UDHflag,UDHFDDSETUP);                        //~v20fI~
        if (Popt & DDRESET_RESIZE)                                 //~v693I~
	    	UCBITON(pdh->UDHflag3,UDHF3RESIZE);	//reset reason     //~v693I~
    }                                                              //~v20fI~
    UCBITON(Ppcw->UCWflag,UCWFDRAW);    //full redraw              //~v20fI~
	return;                                                        //~v20fI~
}//dirddresetallsub                                                //~v20hR~
//**************************************************************** //~v50GI~
// func_selecttext                                                 //~v50GI~
//   select file/dir from dir list by /Mb mode                     //~v50GI~
//*rc   :rc of func_select                                         //~v50GI~
//**************************************************************** //~v50GI~
int func_selecttext(PUCLIENTWE Ppcw)                               //~v50GI~
{                                                                  //~v50GI~
    int rc;                                                        //~v50GI~
//****************************                                     //~v50GI~
//  Sbinsw=BESOPT_TEXT;	//parm to func_select,SPF file             //~v61mR~
    Sbinsw=SELECT_MODE(FUNCID_BROWSETEXT,FUNCID_EDITTEXT);//parm to func_select//~v61mI~
	rc=func_select(Ppcw);                                          //~v50GI~
	Sbinsw=0;                                                      //~v50GI~
	return rc;                                                     //~v50GI~
}//func_selecttext                                                 //~v50GI~
//**************************************************************** //~v10GI~
// func_selectbin                                                  //~v10GI~
//   select file/dir from dir list by /Mb mode                     //~v10GI~
//*rc   :rc of func_select                                         //~v10GI~
//**************************************************************** //~v10GI~
int func_selectbin(PUCLIENTWE Ppcw)                                //~v10GI~
{                                                                  //~v10GI~
    int rc;                                                        //~v10GI~
//****************************                                     //~v10GI~
//  Sbinsw=1;	//parm to func_select                              //~v61mR~
    Sbinsw=SELECT_MODE(FUNCID_BROWSEBIN,FUNCID_EDITBIN);//parm to func_select//~v61mI~
	rc=func_select(Ppcw);                                          //~v10GR~
	Sbinsw=0;                                                      //~v10GI~
	return rc;                                                     //~v10GI~
}//func_selectbin                                                  //~v10GI~
//**************************************************************** //~v10LI~
// func_selectspf                                                  //~v10LI~
//   select file/dir from dir list by /Mn mode                     //~v182R~
//*rc   :rc of func_select                                         //~v10LI~
//**************************************************************** //~v10LI~
int func_selectspf(PUCLIENTWE Ppcw)                                //~v10LI~
{                                                                  //~v10LI~
    int rc;                                                        //~v10LI~
//****************************                                     //~v10LI~
//  Sbinsw=2;	//parm to func_select,SPF file                     //~v61mR~
    Sbinsw=SELECT_MODE(FUNCID_BROWSESPF,FUNCID_EDITSPF);//parm to func_select//~v61mI~
	rc=func_select(Ppcw);                                          //~v10LI~
	Sbinsw=0;                                                      //~v10LI~
	return rc;                                                     //~v10LI~
}//func_selectspf                                                  //~v10LI~
//**************************************************************** //~v182I~
// func_selectspfcob                                               //~v182I~
//   select file/dir from dir list by /Mc mode                     //~v182I~
//*rc   :rc of func_select                                         //~v182I~
//**************************************************************** //~v182I~
int func_selectspfcob(PUCLIENTWE Ppcw)                             //~v182I~
{                                                                  //~v182I~
    int rc;                                                        //~v182I~
//****************************                                     //~v182I~
//  Sbinsw=BESOPT_SPFCOB;	//parm to func_select,SPF file         //~v61mR~
    Sbinsw=SELECT_MODE(FUNCID_BROWSESPFCOB,FUNCID_EDITSPFCOB);//parm to func_select//~v61mI~
	rc=func_select(Ppcw);                                          //~v182I~
	Sbinsw=0;                                                      //~v182I~
	return rc;                                                     //~v182I~
}//func_selectspfcob                                               //~v182I~
//**************************************************************** //~v182I~
// func_selectspfcobnum                                            //~v182I~
//   select file/dir from dir list by /Mnc mode                    //~v182I~
//*rc   :rc of func_select                                         //~v182I~
//**************************************************************** //~v182I~
int func_selectspfcobnum(PUCLIENTWE Ppcw)                          //~v182R~
{                                                                  //~v182I~
    int rc;                                                        //~v182I~
//****************************                                     //~v182I~
//  Sbinsw=BESOPT_SPFCOBNUM;	//parm to func_select,SPF file     //~v61mR~
    Sbinsw=SELECT_MODE(FUNCID_BROWSESPFCOBNUM,FUNCID_EDITSPFCOBNUM);//parm to func_select//~v61mI~
	rc=func_select(Ppcw);                                          //~v182I~
	Sbinsw=0;                                                      //~v182I~
	return rc;                                                     //~v182I~
}//func_selectspfcobnum                                            //~v182R~
//**************************************************************** //~v42yI~
// func_selectspfcob2                                              //~v42yI~
//   select file/dir from dir list by /Mk mode                     //~v42yI~
//*rc   :rc of func_select                                         //~v42yI~
//**************************************************************** //~v42yI~
int func_selectspfcob2(PUCLIENTWE Ppcw)                            //~v42yI~
{                                                                  //~v42yI~
    int rc;                                                        //~v42yI~
//****************************                                     //~v42yI~
//  Sbinsw=BESOPT_SPFCOB2;	//parm to func_select,SPF file         //~v61mR~
    Sbinsw=SELECT_MODE(FUNCID_BROWSESPFCOB2,FUNCID_EDITSPFCOB2);//parm to func_select//~v61mI~
	rc=func_select(Ppcw);                                          //~v42yI~
	Sbinsw=0;                                                      //~v42yI~
	return rc;                                                     //~v42yI~
}//func_selectspfcob2                                              //~v42yI~
//**************************************************************** //~v42yI~
// func_selectspfcob2num                                           //~v42yI~
//   select file/dir from dir list by /Mkn mode                    //~v42yI~
//*rc   :rc of func_select                                         //~v42yI~
//**************************************************************** //~v42yI~
int func_selectspfcob2num(PUCLIENTWE Ppcw)                         //~v42yI~
{                                                                  //~v42yI~
    int rc;                                                        //~v42yI~
//****************************                                     //~v42yI~
//  Sbinsw=BESOPT_SPFCOB2NUM;	//parm to func_select,SPF file     //~v61mR~
    Sbinsw=SELECT_MODE(FUNCID_BROWSESPFCOB2NUM,FUNCID_EDITSPFCOB2NUM);//parm to func_select//~v61mI~
	rc=func_select(Ppcw);                                          //~v42yI~
	Sbinsw=0;                                                      //~v42yI~
	return rc;                                                     //~v42yI~
}//func_selectspfcob2num                                           //~v42yI~
//**************************************************************** //~v75HI~
// func_selectf80                                                  //~v75HI~
//   select file/dir from dir list by f80 mode                     //~v75HI~
//**************************************************************** //~v75HI~
int func_selectf80(PUCLIENTWE Ppcw)                                //~v75HI~
{                                                                  //~v75HI~
    int rc;                                                        //~v75HI~
//****************************                                     //~v75HI~
    Sbinsw=SELECT_MODE(FUNCID_BROWSEF80,FUNCID_EDITF80);//parm to func_select//~v75HI~
	rc=func_select(Ppcw);                                          //~v75HI~
	Sbinsw=0;                                                      //~v75HI~
	return rc;                                                     //~v75HI~
}//func_selectspfcob2num                                           //~v75HI~
//**************************************************************** //~v440I~
// func_selecthex                                                  //~v440I~
//   select file/dir from dir list by /Mx mode                     //~v440I~
//*rc   :rc of func_select                                         //~v440I~
//**************************************************************** //~v440I~
int func_selecthex_file(PUCLIENTWE Ppcw)                           //~v440R~
{                                                                  //~v440I~
    int rc;                                                        //~v440I~
//****************************                                     //~v440I~
//  Sbinsw=BESOPT_HEX;	//parm to func_select,SPF file             //~v61mR~
    Sbinsw=SELECT_MODE(FUNCID_BROWSEHEX,FUNCID_EDITHEX);//parm to func_select//~v61mI~
	rc=func_select(Ppcw);                                          //~v440I~
	Sbinsw=0;                                                      //~v440I~
	return rc;                                                     //~v440I~
}//func_selecthex                                                  //~v440I~
//**************************************************************** //~v09wI~
// func_select                                                     //~v09wI~
//   select file/dir from dir list                                 //~v09wI~
//*rc   :0:ok,4:not found                                          //~v09wI~
//**************************************************************** //~v09wI~
int func_select(PUCLIENTWE Ppcw)                                   //~v09wI~
{                                                                  //~v09wI~
//  PUFILEH pfh;                                                   //~v13dR~
    PUFILEH pfh;                                                   //~v54fI~
  	PUFILEC pfc;                                                   //~v09wR~
  	PULINEH plh,plhp;                                              //~v611I~
  	PUDIRLH pdh,pdhp;                                              //~v611R~
//  char fname[_MAX_PATH];                                         //~v10GR~
//  char fname[_MAX_PATH+4];                                       //~v13dR~
//  char fname[MAXCOLUMN+1];                                       //~v13dI~//~va03R~
    char fname[_MAX_PATH+4];                                       //~va03I~
//  char onlyonemember[MAXCOLUMN+1];                               //~v611I~//~va03R~
//  char onlyonemember[_MAX_PATH+4];                               //~vaf3R~
    char onlyonemember[_MAX_PATH+6];                               //~vaf3I~
//  char fnamew[_MAX_PATH];	//enclose if space contain             //~v13dR~
    char *opdfname;                                                //~v09wI~
    int len,rc;                                                    //~v09wR~
    char *pc;                                                      //~v13dR~
    char dirsepc;                                                  //~v54fR~
#ifdef FTPSUPP                                                     //~v71JI~
    char *pc2;                                                     //~v71JI~
#endif                                                             //~v71JI~
//****************************                                     //~v09wI~
  	pfc=Ppcw->UCWpfc;                                              //~v611I~
    pfh=pfc->UFCpfh;                                               //~v611I~
    if (Ppcw->UCWtype==UCWTFILE)                                   //~vbd7R~
    	return capselectallfilecmd(Ppcw,pfh);                      //~vbd7R~
    if (!(opdfname=Ppcw->UCWparm))//pparseout 1st parm             //~v09wR~
    {                                                              //~v611I~
		plh=UGETQEND(&pfh->UFHlineque);	//last                     //~v611I~
		plh=UGETQPREV(plh);	//prev of last hdr                     //~v611I~
        pdh=UGETPDH(plh);  //only one member                       //~v611M~
		plhp=UGETQPREV(plh);//prev of last                         //~v611I~
        pdhp=UGETPDH(plhp);  //prev line                           //~v611R~
      	if (pdh->UDHtype==UDHTPARENT)	//last is path(no member)  //~v611R~
      	{                                                          //~v611I~
        	uerrmsg("Empty directory",                             //~v611I~
            		"空ディレクトリー");                           //~v611I~
            return 4;                                              //~v611I~
      	}                                                          //~v611I~
      if (pdhp->UDHtype!=UDHTPARENT)	//prev is not path entry//      return errmissing();//~v611R~
      {                                                            //~vb60I~
       if (!(pdh=getdefaultentry(pfh)))//pparseout 1st parm        //~vb60R~
        return fileedithelp('S');	//select id                    //~v11iR~
      }                                                            //~vb60I~
//      strncpy(onlyonemember,pdh->UDHname,sizeof(onlyonemember)); //~vaf3R~
        sprintf(onlyonemember,"\"%s\"",pdh->UDHname);              //~vaf3R~
        opdfname=onlyonemember;                                    //~v611I~
    }                                                              //~v611I~
    else     //operand exist                                       //~vb60I~
    {                                                              //~vb60I~
    	if (getlinenumbername(pfh,opdfname,onlyonemember))	//get line number [-n] membername//~vb60I~
       		return 4;                                              //~vb60I~
    	if (*onlyonemember)	//get line number [-n] membername      //~vb60I~
	        opdfname=onlyonemember;                                //~vb60I~
    }                                                              //~vb60I~
//	pfc=Ppcw->UCWpfc;                                              //~v611R~
//    pfh=pfc->UFCpfh;                                             //~v13dR~
//  pfh=pfc->UFCpfh;                                               //~v611R~
//    pc=pfh->UFHfilename;            //dir name                   //~v13dR~
//    if (WILDCARD(pc))                                            //~v13dR~
//    {                                                            //~v13dR~
//        len=PATHLEN(pc);                                         //~v13dR~
//        if (len<=0)  //err                                       //~v13dR~
//            return 4;                                            //~v13dR~
//        len--;              //drop last \ for followed logic     //~v13dR~
//    }                                                            //~v13dR~
//    else                                                         //~v13dR~
//        len=(int)strlen(pc);            //dir name               //~v13dR~
////  memcpy(fname,pc,(UINT)len);         //dir name               //~v13dR~
//    memcpy(fnamew,pc,(UINT)len);            //dir name           //~v13dR~
//    *(fnamew+len)=0;                                             //~v13dR~
	dirsepc=pfh->UFHdirsepc;                                       //~v54fI~
#ifdef FTPSUPP                                                     //~v717I~
    if (FILEISTSO(pfh))                                            //~v717I~
    {                                                              //~v717I~
        if (pfh->UFHattr & FILE_DIRECTORY   //PDS directory        //~v717R~
        ||  UCBITCHK(pfh->UFHflag7,UFHF7PDSMEMBER))//mebername wildcard//~v717R~
            dirsepc=DSN_SEPCMEMB;                                  //~v717I~
    }                                                              //~v717I~
#endif                                                             //~v717I~
    len=(int)strlen(opdfname);                                     //~v13dM~
    pc=fname;                                                      //~v13dI~
    if (*opdfname=='"')		//enclosed filename                    //~v13dI~
    {                                                              //~v13dI~
    	opdfname++;                                                //~v13dI~
        *pc++='"';			                                       //~v13dI~
        len--;                                                     //~v13dI~
    }                                                              //~v13dI~
    if (*opdfname=='\'')		//enclosed filename                //~v144I~
    {                                                              //~v144I~
    	opdfname++;                                                //~v144I~
        *pc++='\'';                                                //~v144R~
        len--;                                                     //~v144I~
    }                                                              //~v144I~
    if (*opdfname!='*'                                             //~v13dR~
//  ||  (*(opdfname+1)!='\\' && *(opdfname+1)!='*')                //~v19aR~
//  ||  (*(opdfname+1)!=DIR_SEPC && *(opdfname+1)!='*')            //~v54fR~
    ||  (*(opdfname+1)!=dirsepc  && *(opdfname+1)!='*')            //~v54fI~
       )                                                           //~v13dI~
    {                                                              //~v13dI~
//    	memcpy(pc,"*\\",2);                                        //~v19aR~
//    	memcpy(pc,"*" DIR_SEPS,2);                                 //~v54fR~
      	*pc='*';                                                   //~v54fR~
      	*(pc+1)=dirsepc;                                           //~v54fI~
        pc+=2;                                                     //~v13dI~
	}                                                              //~v13dI~
    memcpy(pc,opdfname,(UINT)len);                                 //~v13dI~
#ifdef FTPSUPP                                                     //~v717I~
    if (dirsepc==DSN_SEPCMEMB)                                     //~v717R~
    {                                                              //~v71JI~
        pc2=memchr(pc,' ',(UINT)len);   //chk other operand        //~v71JI~
      if (pc2)                                                     //~v71JI~
      {                                                            //~v71JI~
//    	len=len-((ULONG)pc2-(ULONG)pc);                            //~v71JI~//~vafkR~
//    	len=len-((ULPTR)pc2-(ULPTR)pc);                            //~vafkI~//~vb2FR~
      	len=len-PTRDIFF(pc2,pc);                                   //~vb2FI~
        memmove(pc2+1,pc2,(UINT)len);                              //~v71JI~
        *pc2=DSN_SEPCMEMB2;  //")"                                 //~v71JI~
        pc=pc2+1;                                                  //~v71JI~
      }                                                            //~v71JI~
      else                                                         //~v71JI~
        *(pc+++len)=DSN_SEPCMEMB2;  //")"                          //~v717R~
    }                                                              //~v71JI~
#endif                                                             //~v717I~
    *(pc+len)=0;                                                   //~v13dI~
//    if (uparsein (fnamew,fname,sizeof(fname),0,'\"'))//enclosed if space embedding//~v13dR~
//        len=(int)strlen(fname);         //dir name               //~v13dR~
//    if (pfh->UFHlevel)                                           //~v13dR~
//        *(fname+len++)='\\';                                     //~v13dR~
//    strcpy(fname+len,opdfname);                                  //~v13dR~
//    if (Sbinsw)                                                  //~v61mR~
//    {                                                            //~v61mR~
//      if (Sbinsw==1)                                             //~v61mR~
//        strcat(fname," /MB");   //force binary bode              //~v61mR~
//      else                                                       //~v61mR~
//      if (Sbinsw==BESOPT_TEXT)                                   //~v61mR~
//        strcat(fname," /MT");   //force binary bode              //~v61mR~
//      else                                                       //~v61mR~
//      if (Sbinsw==BESOPT_SPF)                                    //~v61mR~
//        strcat(fname," /MN");   //force spf file                 //~v61mR~
//      else                                                       //~v61mR~
//      if (Sbinsw==BESOPT_SPFCOB)                                 //~v61mR~
//        strcat(fname," /MC");   //force spf cob file             //~v61mR~
//      else                                                       //~v61mR~
//      if (Sbinsw==BESOPT_SPFCOB2)                                //~v61mR~
//        strcat(fname," /MK");   //force spf cob file             //~v61mR~
//      else                                                       //~v61mR~
//      if (Sbinsw==BESOPT_SPFCOB2NUM)                             //~v61mR~
//        strcat(fname," /MKN");   //force spf cob file            //~v61mR~
//      else                                                       //~v61mR~
//      if (Sbinsw==BESOPT_HEX)                                    //~v61mR~
//        strcat(fname," /MH");   //force spf cob file             //~v61mR~
//      else                                                       //~v61mR~
//        strcat(fname," /MNC");   //force spf cob file with col-72 num fld//~v61mR~
//    }                                                            //~v61mR~
	Ppcw->UCWparm=fname;                                           //~v09wI~
#ifdef UTF8SUPPH                                                   //~va00I~
	UCBITON(Ppcw->UCWflag2,UCWF2SELECTCMD);	//parm to fileoptionchk//~va00I~
#endif                                                             //~va00I~
	if (UCBITCHK(pfc->UFCflag,UFCFDEDIT))                          //~v09wI~
      if (Sbinsw)                                                  //~v61mI~
		rc=func_select_filefuncid(Ppcw,0,(Sbinsw & 255));	//may additional parm//~v61mR~
      else                                                         //~v61mI~
		rc=func_edit_file2(Ppcw,1);	//may additional parm          //~v09wR~
	else                                                           //~v09wI~
      if (Sbinsw)                                                  //~v61mI~
		rc=func_select_filefuncid(Ppcw,1,(int)((UINT)Sbinsw >>8));	//may additional parm//~v621R~
      else                                                         //~v61mI~
		rc=func_browse_file2(Ppcw,1);	//may additional parm      //~v09wI~
#ifdef UTF8SUPPH                                                   //~va00I~
	UCBITOFF(Ppcw->UCWflag2,UCWF2SELECTCMD);                       //~va00I~
#endif                                                             //~va00I~
    if (!rc)                                                       //~v09wI~
    	dlcmdeditenq2(Ppcw);                                       //~v09wI~
    return rc;                                                     //~v09wR~
}//func_select                                                     //~v09wI~
                                                                   //~v09wI~
//**************************************************************** //~v61mI~
// func_browse_file2                                               //~v61mI~
//*internal call interface,setup parseout tbl                      //~v61mI~
//*parm1:uclient work element                                      //~v61mI~
//*parm2:1:optional operand may exist,0:no optional opd            //~v61mI~
//*rc   :of func_browse_file                                       //~v61mI~
//**************************************************************** //~v61mI~
int func_select_filefuncid(PUCLIENTWE Ppcw,int Pbrowsesw,int Pfuncid)//~v61mI~
{                                                                  //~v61mI~
//  UCHAR wkpot[MAXCOLUMN+1];                                      //~v61mI~//~va03R~
    UCHAR wkpot[MAXPARMSZ+1];                                      //~va03I~
    PUPODELMTBL pupod;                                             //~v61mI~
    FUNCTBL *pft;                                                  //~v61mI~
    FTFUNC *pfunc;                                                 //~v61mI~
	int rc;                                                        //~v61mI~
//*********************************                                //~v61mI~
    pft=functblsrch(Pfuncid);                                      //~v61mI~
    if (!pft)                                                      //~v61mI~
    	return 8;                                                  //~v61mI~
    filefnquate(Ppcw->UCWparm);     //quatation change             //~v61mI~
    pupod=Ppcw->UCWopddelmt=Gpodelmt;                              //~v61mI~
    Ppcw->UCWopdpot=wkpot;                                         //~v61mI~
    if ((rc=uparse2(Ppcw->UCWparm,&pupod,                          //~v61mI~
            &Ppcw->UCWopdpot,&Ppcw->UCWopdno,UPARSE2USEAREAPARM,","))>=4)//~v61mI~
        return rc;          //umalloc failed                       //~v61mI~
    Ppcw->UCWpfunct=pft;                                           //~v61mI~
    pfunc=pft->FTfunc[UCWTFILE];                                   //~v61mI~
    rc=pfunc(Ppcw);                                                //~v61mI~
    return rc;                                                     //~v61mI~
}//func_select_filefuncid                                          //~v61mI~
//**************************************************************** //~v07eI~
// dirfunccall                                                     //~v07eI~
// setup for funccall like as kbdproc and call funccall            //~v07eI~
//*rc   :0                                                         //~v07eI~
//**************************************************************** //~v07eI~
int dirfunccall(PUCLIENTWE Ppcw)                                   //~v07eI~
{                                                                  //~v07eI~
	int keytype;                                                   //~v07eI~
	UCHAR inputc[3];                                               //~v07eI~
//****************************                                     //~v07eI~
	Ppcw->UCWrcsrx=0;	//simulate top pos,rcsry is same           //~v07eI~
	csrloctogbl(Ppcw);	//funccall covert gbl to local             //~v07eR~
                                                                   //~v07eI~
	keytype=UCWKTSBCS;                                             //~v07eI~
	inputc[0]=*Sdlcmdsave;	//char code                            //~v07eI~
	inputc[1]=0;			//scan code                            //~v07eI~
	inputc[2]=0;            //delm                                 //~v07eI~
	Ppcw->UCWkeyshift=0;	//shift key status                     //~v07eI~
                                                                   //~v07eI~
	return funccall(keytype,inputc,Ppcw);                          //~v07eI~
}//dirfunccall                                                     //~v07eI~
                                                                   //~v0ieI~
//**************************************************************** //~v78gI~
// dirlocate                                                       //~v78gI~
//   execute locate function by type on filename fld               //~v78gI~
//*rc   :0:done,4:err(protected but not filename fld)              //~v78gI~
//**************************************************************** //~v78gI~
int dirlocate(int Popt,PUCLIENTWE Ppcw)                            //~v78gI~
{                                                                  //~v78gI~
#define MAX_LOCATE_PREFIX   32                                     //~v78gI~
    int xx,yy,oldkbdctr,rc,nextoffs;                               //~v78gR~
    char *pc;                                                      //~v78gI~
    UFLDE *pfle;                                                   //~v78gI~
//    PUFILEC pfc;                                                 //~v78gR~
//    PULINEH plh;                                                 //~v78gR~
    static int Skbdinpctr;                                         //~v78gR~
    static char Sfnmprefix[MAX_LOCATE_PREFIX+1];                   //~v78gR~
    static int  Sfnmprefixctr;                                     //~v78gI~
#ifdef UTF8SUPPH                                                   //~va00I~
    int utf8len;                                                   //~va00I~
#endif                                                             //~va00I~
//***************************                                      //~v78gI~
	oldkbdctr=Skbdinpctr;	//old                                  //~v78gI~
    Skbdinpctr=Gkbdinpctr;	//continued press chk                  //~v78gI~
	xx=Ppcw->UCWrcsrx;                                             //~v78gR~
	yy=Ppcw->UCWrcsry;                                             //~v78gR~
    if (yy<=CMDLINENO)                                             //~v78gR~
    	return 4;                                                  //~v78gI~
    pfle=getuflde(Ppcw,yy,PANL310ATTR);                            //~v78gR~
    nextoffs=pfle->UFLstart;                                       //~v78gI~
    if (xx>=nextoffs)                                              //~v78gR~
    	return 4;                                                  //~v78gI~
    if (oldkbdctr+1!=Skbdinpctr)	//continued                    //~v78gI~
    	Sfnmprefixctr=0;                                           //~v78gI~
    if (Sfnmprefixctr+Ppcw->UCWkeytype>=MAX_LOCATE_PREFIX)         //~v78gR~
    	return 4;                                                  //~v78gI~
    if (Ppcw->UCWkeydata[0]<' ')    //ignore ctl char              //~v78gI~
    	return 4;                                                  //~v78gI~
#ifdef UTF8SUPPH                                                   //~va00I~
//if (UCBITCHK(Ppcw->UCWflag2,UCWF2UTF8STR))                       //~va00I~//~va0WR~
  if (chargetkbdutf8(0,Ppcw,0/*ppu8*/,&utf8len,0/*codetype*/)==1) //utf8 gotten//~va0WI~
  {                                                                //~va00I~
//    utf8len=(int)strlen(Ppcw->UCWkeydata_utf8str);               //~va00I~//~va0WR~
      if (Sfnmprefixctr+utf8len>=MAX_LOCATE_PREFIX)                //~va00I~
          return 4;                                                //~va00I~
      memcpy(Sfnmprefix+Sfnmprefixctr,Ppcw->UCWkeydata_utf8str,(UINT)utf8len);//~va00I~
      Sfnmprefixctr+=utf8len;                                      //~va00I~
  }                                                                //~va00I~
  else                                                             //~va00I~
  {                                                                //~va00I~
#endif                                                             //~va00I~
    Sfnmprefix[Sfnmprefixctr++]=Ppcw->UCWkeydata[0];               //~v78gI~
    if (Ppcw->UCWkeytype==UCWKTDBCS)                               //~v78gI~
    	Sfnmprefix[Sfnmprefixctr++]=Ppcw->UCWkeydata[1];           //~v78gI~
#ifdef UTF8SUPPH                                                   //~va00I~
  }                                                                //~va00I~
#endif                                                             //~va00I~
    Sfnmprefix[Sfnmprefixctr]=0;                                   //~v78gI~
    Sinternallocatesw=1;                                           //~v78gI~
    pc=Ppcw->UCWparm;                                              //~v78gI~
    Ppcw->UCWparm=Sfnmprefix;                                      //~v78gI~
	rc=func_locate_dir(Ppcw);                                      //~v78gR~
    Ppcw->UCWparm=pc;                                              //~v78gI~
    Sinternallocatesw=0;                                           //~v78gI~
    if (rc)                                                        //~v78gI~
    	return rc;                                                 //~v78gR~
//    pfc=Ppcw->UCWpfc;                                            //~v78gR~
//    plh=pfc->UFCcsrplh;                                          //~v78gR~
//    pc=plh->ULHdata;                                             //~v78gR~
//    for (ii=0;ii<UDDMAXLEVEL;ii++)                               //~v78gR~
//        if (*pc++!='|')                                          //~v78gR~
//            break;                                               //~v78gR~
//    filesetcsr(Ppcw,plh,0,Ppcw->UCWlinenosz+ii+1+Sfnmprefixctr);    //fld 1 col 1//~v78gR~
    return 0;                                                      //~v78gI~
}//dirlocate                                                       //~v78gI~
//**************************************************************** //~v0ieI~
// func_locate_dir                                                 //~v0ieI~
//   search filename by name seq                                   //~v0ieI~
//*rc   :0:ok,4:path not found                                     //~v0ieI~
//**************************************************************** //~v0ieI~
int func_locate_dir(PUCLIENTWE Ppcw)                               //~v0ieI~
{                                                                  //~v0ieI~
    PUFILEH pfh;                                                   //~v0ieI~
  	PUFILEC pfc;                                                   //~v0ieI~
  	PULINEH plh;                                                   //~v0ieI~
  	PULINEH plhp=NULL;                                                  //~v57gI~//~vafcR~
  	PUDIRLH pdhp,pdh=NULL;		//parent pdh,found pdh                 //~v0ieI~//~vafcR~
  	UDIRLH dhtemp;                                                 //~v57gR~
    char fname[_MAX_PATH];                                         //~v0ieI~
    char *opdfname;                                                //~v0ieI~
    int len;                                                       //~v42yR~
    int sorttype;                                                  //~v57gI~
#ifndef UNX                                                        //~v42yI~
    int opdlen;                                                    //~v42yI~
#endif //!UNX                                                      //~v42yI~
    char *pc;                                                      //~v0ieI~
//****************************                                     //~v0ieI~
  if (Sinternallocatesw)                                           //~v78gI~
    opdfname=Ppcw->UCWparm;                                        //~v78gI~
  else                                                             //~v78gI~
  {                                                                //~v78gI~
	if (Ppcw->UCWopdno>1)                                          //~v0ieI~
    	return errtoomany();                                       //~v0ieI~
	if (!Ppcw->UCWopdno)                                           //~v0ieI~
    {                                                              //~v59AI~
//  	return errmissing();                                       //~v59AR~
        uerrmsg("L {Line-no | FileName| yymmdd[-hhmm] | FileSize}",0);//~v59AR~
        return 4;                                                  //~v59AI~
    }                                                              //~v59AI~
    opdfname=Ppcw->UCWopdpot;                                      //~v0ieR~
  }                                                                //~v78gI~
//	opdlen=(int)strlen(opdfname);                                  //~v42yR~
  	pfc=Ppcw->UCWpfc;                                              //~v0ieI~
  	pfh=pfc->UFCpfh;                                               //~v0ieI~
//chk sort option                                                  //~v57gI~
	sorttype=UDHSONAME;                                            //~v57gI~
	for (plh=UGETQTOP(&pfh->UFHlineque);plh;plh=UGETQNEXT(plh))    //~v57gI~
	{                                                              //~v57gI~
		if (plh->ULHtype!=ULHTDATA)	//file data                    //~v57gI~
            continue;                                              //~v57gI~
    	pdh=UGETPDH(plh);                                          //~v57gI~
        if (pdh->UDHtype==UDHTPARENT)                              //~v57gI~
        {                                                          //~v57gI~
        	plhp=plh;	//parent plh for size/time search          //~v57gR~
        	sorttype=pdh->UDHsortopt;                              //~v57gR~
        }                                                          //~v57gI~
        else                                                       //~v57gI~
        	break;                                                 //~v57gI~
    }                                                              //~v57gI~
  if (sorttype==UDHSONAME)                                         //~v57gI~
  {                                                                //~v57gI~
#ifdef FTPSUPP                                                     //~v717I~
  if (FILEISTSO(pfh))                                              //~v717I~
        xetsoconcatfilename(pfh,opdfname,fname);                   //~v717R~
  else                                                             //~v717I~
  {                                                                //~v717I~
#endif                                                             //~v717I~
#ifndef UNX                                                        //~v19aI~
  	opdlen=(int)strlen(opdfname);                                  //~v42yI~
    if (opdlen>=3 && *(opdfname+1)==':' && *(opdfname+2)=='\\')    //~v0ieR~
    {                                                              //~v0ieI~
       	len=0;		//from drive id                                //~v0ieI~
        if (toupper(*opdfname)!=toupper(*(pfh->UFHfilename)))      //~v0ieI~
	    	return dirpatherr(opdfname);                           //~v0ieI~
	}                                                              //~v0ieI~
	else                                                           //~v0ieI~
#endif //!UNX                                                      //~v19aI~
    {                                                              //~v0ieI~
        pc=pfh->UFHfilename;            //dir name                 //~v0ieR~
        if (WILDCARD(pc))                                          //~v0ieR~
        {                                                          //~v0ieR~
//          len=PATHLEN(pc);                                       //~v54fR~
            len=FILEPATHLEN(pfh,pc);                               //~v54fI~
            if (len<=0)  //err                                     //~v0ieR~
                return 4;                                          //~v0ieR~
          if (pfh->UFHlevel)                                       //~vb35I~
            len--;              //drop last \ for followed logic   //~v0ieR~
        }                                                          //~v0ieR~
        else                                                       //~v0ieR~
            len=(int)strlen(pc);            //dir name             //~v0ieR~
        memcpy(fname,pc,(UINT)len);            //dir name          //~v0ieR~
        *(fname+len)=0;                                            //~v0ieR~
//      if (*opdfname=='\\')                                       //~v19aR~
//      if (*opdfname==DIR_SEPC)                                   //~v54fR~
        if (*opdfname==pfh->UFHdirsepc)                            //~v54fI~
        {                                                          //~v54fI~
#ifdef UNX                                                         //~v19yI~
            len=0;                                                 //~v19yI~
#else                                                              //~v19yI~
	#ifdef FTPSUPP  //w32                                          //~v54fI~
          if (*opdfname==FTP_DIR_SEPC)                             //~v54fI~
            len=0;                                                 //~v54fI~
          else                                                     //~v54fI~
    #endif                                                         //~v54fI~
            len=2;                                                 //~v0ieR~
#endif                                                             //~v19yI~
		}                                                          //~v54fI~
        else                                                       //~v0ieR~
        	if (pfh->UFHlevel)                                     //~v0ieR~
//          	*(fname+len++)='\\';                               //~v19aR~
//          	*(fname+len++)=DIR_SEPC;                           //~v54fR~
            	*(fname+len++)=pfh->UFHdirsepc;                    //~v54fR~
	}                                                              //~v0ieI~
	strcpy(fname+len,opdfname);                                    //~v0ieI~
#ifdef FTPSUPP                                                     //~v717I~
  } //!tso                                                         //~v717I~
#endif                                                             //~v717I~
//*                                                                //~v0ieI~
    dlcpdhsrch2(pfh,fname,&pdh,&pdhp);//stop by grater or equal    //~v0ieR~
    if (!pdh)                                                      //~v0ieI~
    	pdh=pdhp;                                                  //~v0ieI~
    if (!pdh)                                                      //~v0ieI~
    	return dirpatherr(opdfname);                               //~v0ieR~
  }//sort by name                                                  //~v57gI~
  else                                                             //~v57gI~
  {                                                                //~v57gI~
  	if (dirlocateparmchk(opdfname,sorttype,&dhtemp))//get timestamp or size//~v57gI~
    	return 4;                                                  //~v57gI~
   if (plhp)	//confirm !0c4                                     //~vafcI~
    dlcpdhsrchts(plhp,&dhtemp,&pdh);//search by size or timestamp  //~v57gR~
  }                                                                //~v57gI~
    plh=UGETDIRPLH(pdh);                                           //~v0ieR~
	fcmdscrollpage(Ppcw,plh);		//scroll to the plh            //~v0ieI~
    filesetcsr(Ppcw,plh,0,0);   	//fld 1 col 1                  //~v0ieR~
    return 0;                                                      //~v0ieI~
}//func_locate_dir                                                 //~v0ieI~
//**************************************************************** //~v57gI~
// dirlocateparmchk                                                //~v57gI~
//   locate parm chk for sorted list by size or timestamp          //~v57gI~
//*rc   :0:ok,4:path not found                                     //~v57gI~
//**************************************************************** //~v57gI~
int dirlocateparmchk(char *Popd,int Psorttype,PUDIRLH Ppdh)        //~v57gI~
{                                                                  //~v57gI~
	int sorttype,rc=0,len;                                         //~v57gR~
//****************************                                     //~v57gI~
	sorttype=Psorttype&~UDHSOREVERSE;                              //~v57gI~
    len=(int)strlen(Popd);                                         //~v59MR~
    if (sorttype==UDHSOSIZE)                                       //~v57gI~
    {                                                              //~v57gI~
        if (unumlen(Popd,0,len)==len)                              //~v57gI~
//          Ppdh->UDHsize=(ULONG)atol(Popd);                       //~v59MR~//~vb31R~
            Ppdh->UDHsize=(FILESZT)atol(Popd);                     //~vb31I~
        else                                                       //~v57gI~
            rc=4;                                                  //~v57gI~
    }                                                              //~v57gI~
    else    //time sort                                            //~v57gI~
    	rc=ugetdtparm(Popd,&Ppdh->UDHdate,&Ppdh->UDHtime);         //~v57gR~
    if (rc)                                                        //~v57gI~
    	uerrmsg("locate parm(%s) err for sorted dirlist",0,        //~v57gR~
        		Popd);                                             //~v57gR~
    return rc;                                                     //~v57gI~
}//dirlocateparmchk                                                //~v57gI~
//**************************************************************** //~v558I~
// func_pathup                                                     //~v558I~
//   edit/browse parent dir                                        //~v558I~
//*rc   :0:ok,4:err                                                //~v558I~
//**************************************************************** //~v558I~
int func_pathup(PUCLIENTWE Ppcw)                                   //~v558I~
{                                                                  //~v558I~
	PUCLIENTWE pcw;                                                //~v558R~
	PUFILEC pfc;                                                   //~v558I~
	PUFILEH pfh;                                                   //~v558I~
    char *pathnm,*copypathnm,*cpathnm;                             //~v558R~
    char ebfnm[_MAX_PATH];                                         //~v558I~
    int pathlen,rc,cpathlen;                                       //~v558R~
//****************************                                     //~v558I~
    pfc=Ppcw->UCWpfc;                                              //~v558I~
	pfh=pfc->UFCpfh;                                               //~v558I~
    if (!(pathnm=pfc->UFCdeepestpath))                             //~v558R~
    	pathnm=pfh->UFHfilename;                                   //~v558I~
    cpathnm=pfh->UFHfilename;                                      //~v558I~
    if (ROOTDIR3(cpathnm))                                         //~v558R~
    {                                                              //~v558I~
//      uerrmsg("Now root",0);                                     //~v78MR~
//      return 4;                                                  //~v78MR~
        *ebfnm='=';                                                //~v78MM~
        if (UCBITCHK(pfc->UFCflag,UFCFDEDIT))                      //~v78MI~
        	*(ebfnm+1)='2';                                        //~v78MI~
        else                                                       //~v78MM~
        	*(ebfnm+1)='1';                                        //~v78MI~
		funcsetlongcmd(Ppcw,1,ebfnm,2,0);	//1:execute,0:no output cmdlen//~v78MM~
        return 0;                                                  //~v78MI~
    }                                                              //~v558I~
#ifdef FTPSUPP                                                     //~v717I~
    if (FILEISTSO(pfh))                                            //~v717I~
        if (!UCBITCHK(pfh->UFHflag7,UFHF7PDSMEMBER))               //~v717R~
        {                                                          //~v717I~
            uerrmsg("PATH up is avail only for PDS member for TSO file",0);//~v717I~
            return 4;                                              //~v717I~
        }                                                          //~v717I~
#endif                                                             //~v717I~
    pathlen=(int)strlen(pathnm);                                   //~v59MR~
    copypathnm=UALLOCM((UINT)pathlen+1);                           //~v59MR~
    UALLOCCHK(copypathnm,UALLOC_FAILED);                           //~v558R~
    memcpy(copypathnm,pathnm,(UINT)pathlen);                       //~v558R~
    *(copypathnm+pathlen)=0;                                       //~v558I~
                                                                   //~v717I~
#ifdef FTPSUPP                                                     //~v717I~
  if (FILEISTSO(pfh))                                              //~v717I~
  	u3270parentdsn(U3PL_DROPMEMBER,cpathnm,ebfnm);                 //~v717I~
  else                                                             //~v717I~
  {                                                                //~v717I~
#endif                                                             //~v717I~
    cpathlen=PATHLEN(cpathnm);                                     //~v558R~
    memcpy(ebfnm,cpathnm,(UINT)cpathlen);                          //~v558R~
    *(ebfnm+cpathlen)=0;                                           //~v558R~
    if (!ROOTDIR3(ebfnm))                                          //~v558I~
    	*(ebfnm+cpathlen--)=0;                                     //~v558I~
#ifdef FTPSUPP                                                     //~v717I~
  }                                                                //~v717I~
#endif                                                             //~v717I~
    Ppcw->UCWparm=ebfnm;     //quatation change                    //~v558I~
	if (UCBITCHK(pfc->UFCflag,UFCFDEDIT)	//dir list by edit     //~v558I~
	|| !UCBITCHK(pfc->UFCflag,UFCFBROWSE))  //file edit            //~v558I~
        rc=func_edit_file2(Ppcw,0); //w/o option parm              //~v558M~
    else                                                           //~v558I~
        rc=func_browse_file2(Ppcw,0);   //w/o option               //~v558M~
    if (rc)                                                        //~v558I~
    	ufree(copypathnm);                                         //~v558I~
    else                                                           //~v558I~
    {                                                              //~v558I~
    	pcw=scrgetcw(Ppcw->UCWsplitid+1);	//new pcw              //~v558R~
        pfc=pcw->UCWpfc;                                           //~v558R~
        if (pfc->UFCdeepestpath)                                   //~v558R~
	    	ufree(pfc->UFCdeepestpath);  	//change path          //~v558R~
	    pfc->UFCdeepestpath=copypathnm;		//for pathdown         //~v558R~
    }                                                              //~v558I~
    return rc;                                                     //~v558R~
}//func_pathup                                                     //~v558I~
//**************************************************************** //~v558I~
// func_pathup                                                     //~v558I~
//   edit/browse parent dir                                        //~v558I~
//*rc   :0:ok,4:err                                                //~v558I~
//**************************************************************** //~v558I~
int func_pathdown(PUCLIENTWE Ppcw)                                 //~v558I~
{                                                                  //~v558I~
	PUCLIENTWE pcw;                                                //~v558I~
	PUFILEC pfc;                                                   //~v558I~
	PUFILEH pfh;                                                   //~v558I~
    char *pathnm,*copypathnm;                                      //~v558I~
    char ebfnm[_MAX_PATH];                                         //~v558I~
    int pathlen,cpathlen,len,rc;                                   //~v558R~
//****************************                                     //~v558I~
    pfc=Ppcw->UCWpfc;                                              //~v558I~
	pfh=pfc->UFCpfh;                                               //~v558I~
    cpathlen=(int)strlen(pfh->UFHfilename);    //current path      //~v59MR~
    pathnm=pfc->UFCdeepestpath;                                    //~v558R~
    if (!pathnm                                                    //~v558I~
    ||   (pathlen=(int)strlen(pathnm))==cpathlen)                  //~v59MR~
    {                                                              //~v558I~
    	uerrmsg("Now bottom of path",0);                           //~v558R~
    	return 4;                                                  //~v558I~
    }                                                              //~v558I~
#ifdef FTPSUPP                                                     //~v717I~
    if (FILEISTSO(pfh))                                            //~v717I~
    {                                                              //~v717I~
        if (pfh->UFHtype!=UFHTDIR)                                 //~v717I~
        {                                                          //~v717I~
            uerrmsg("PATH down is avail only for PDS for TSO file",0);//~v717I~
            return 4;                                              //~v717I~
        }                                                          //~v717I~
    }                                                              //~v717I~
#endif                                                             //~v717I~
    memcpy(ebfnm,pathnm,(UINT)pathlen);                            //~v558I~
    *(ebfnm+pathlen)=0;                                            //~v558I~
    copypathnm=UALLOCM((UINT)pathlen+1);                           //~v59MR~
    UALLOCCHK(copypathnm,UALLOC_FAILED);                           //~v558R~
    memcpy(copypathnm,pathnm,(UINT)pathlen);                       //~v558I~
    *(copypathnm+pathlen)=0;                                       //~v558I~
#ifdef FTPSUPP                                                     //~v717I~
  if (!FILEISTSO(pfh))                                             //~v717I~
  {                                                                //~v717I~
#endif                                                             //~v717I~
    for (;;)                                                       //~v558R~
    {                                                              //~v558I~
    	len=PATHLEN(ebfnm);                                        //~v558R~
        if (!ROOTDIR3(ebfnm))                                      //~v558I~
        	len--;                                                 //~v558I~
        if (len<=cpathlen)                                         //~v558I~
        	break;                                                 //~v558I~
        *(ebfnm+len)=0;                                            //~v558I~
    }                                                              //~v558I~
#ifdef FTPSUPP                                                     //~v717I~
  }                                                                //~v717I~
#endif                                                             //~v717I~
    Ppcw->UCWparm=ebfnm;     //quatation change                    //~v558I~
	if (UCBITCHK(pfc->UFCflag,UFCFDEDIT))                          //~v558I~
        rc=func_edit_file2(Ppcw,0); //w/o option parm              //~v558M~
    else                                                           //~v558I~
        rc=func_browse_file2(Ppcw,0);   //w/o option               //~v558M~
    if (rc)                                                        //~v558I~
    	ufree(copypathnm);                                         //~v558I~
    else                                                           //~v558I~
    {                                                              //~v558I~
    	pcw=scrgetcw(Ppcw->UCWsplitid+1);	//new pcw              //~v558R~
        pfc=pcw->UCWpfc;                                           //~v558R~
        if (pfc->UFCdeepestpath)                                   //~v558R~
	    	ufree(copypathnm);  	//reopen case                  //~v558I~
        else                                                       //~v558I~
	        pfc->UFCdeepestpath=copypathnm;		//for pathdown     //~v558R~
    }                                                              //~v558I~
    return rc;                                                     //~v558I~
}//func_pathdown                                                   //~v558I~
//**************************************************************** //~v0ieI~
// dirpatherr                                                      //~v0ieI~
//*rc   :0:ok,4:path not found                                     //~v0ieI~
//**************************************************************** //~v0ieI~
int dirpatherr(UCHAR *Ppath)                                       //~v0ieI~
{                                                                  //~v0ieI~
	uerrmsg("Path specification err(%s)",                          //~v19aR~
    		"経路指定の誤り(%s)",                                  //~v0ieR~
			Ppath);                                                //~v0ieI~
    return 4;                                                      //~v0ieI~
}//dirpatherr                                                      //~v0ieI~
//*line top ************************************************       //~v55NI~
int func_linetop_dir(PUCLIENTWE Ppcw)                              //~v55NI~
{                                                                  //~v55NI~
	PULINEH plh;                                                   //~v55NI~
	PUDIRLH pdh;                                                   //~v55NI~
	PUFILEC pfc;                                                   //~v59TI~
    int fldno,posx,posy;                                           //~v55NR~
    int expandlen;                                                 //~v59TI~
//****************:                                                //~v55NI~
	if (!CSRONFILELINE(Ppcw))                                      //~v55NI~
		return func_linetop_pan(Ppcw);                             //~v55NI~
	pfc=Ppcw->UCWpfc;                                              //~v59TI~
    expandlen=pfc->UFCexpandlen;	//expand if scr is wide        //~v59TI~
	posy=Ppcw->UCWrcsry;                                           //~v55NI~
  	posx=Ppcw->UCWrcsrx;                                           //~v55NM~
	plh=(((PUSCRD)(Ppcw->UCWpsd)+posy)->USDbuffc);                 //~v55NR~
	if (!plh)                                                      //~v55NI~
		return func_linetop_pan(Ppcw);                             //~v55NI~
    pdh=UGETPDH(plh);                                              //~v55NI~
    fldno=PANL310LINENO;                                           //~v55NI~
  	if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN1))  //attrcmd             //~v55NI~
    {                                                              //~v55NI~
//  	if (posx>(UDHLINENOSZ+offsetof(UDIRLD,UDDattrflag)))       //~v59TR~
//  	if (posx>(int)(UDHLINENOSZ+offsetof(UDIRLD,UDDattrflag)+expandlen))//~v59TR~//~vb30R~
    	if (posx>(int)(UDHLINENOSZ+(int)offsetof(UDIRLD,UDDattrflag)+expandlen))//~vb30I~
	    	fldno=PANL310ATTR;                                     //~v55NR~
    }                                                              //~v55NI~
    else                                                           //~v55NI~
  	if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN2))  //other cmd rename fld use//~v55NI~
    {                                                              //~v55NI~
//  	if ((UINT)posx>UDHLINENOSZ+offsetof(UDIRLD,UDDrname[0]))   //~v59TR~
//  	if ((UINT)posx>UDHLINENOSZ+offsetof(UDIRLD,UDDrname[0])+expandlen)//~v59TI~//~vb30R~
    	if (posx>UDHLINENOSZ+(int)offsetof(UDIRLD,UDDrname[0])+expandlen)//~vb30R~
    		fldno=PANL310RENAME;                                   //~v55NR~
    }                                                              //~v55NI~
	return csronthefld(Ppcw,posy,fldno,0);//top of client fld      //~v55NR~
}//func_linetop_dir                                                //~v55NI~
//*line end ************************************************       //~v55NI~
int func_lineend_dir(PUCLIENTWE Ppcw)                              //~v55NI~
{                                                                  //~v55NI~
	PULINEH plh;                                                   //~v55NI~
	PUDIRLH pdh;                                                   //~v55NI~
	PUFILEC pfc;                                                   //~v59TI~
    UCHAR *pc;                                                     //~v55NR~
    int fldno,posx,posy,newposx;                                   //~v55NR~
    int expandlen;                                                 //~v59TI~
//****************:                                                //~v55NI~
	if (!CSRONFILELINE(Ppcw))                                      //~v55NI~
		return func_lineend_pan(Ppcw);                             //~v55NI~
	pfc=Ppcw->UCWpfc;                                              //~v59TI~
    expandlen=pfc->UFCexpandlen;	//expand if scr is wide        //~v59TI~
	posy=Ppcw->UCWrcsry;                                           //~v55NI~
  	posx=Ppcw->UCWrcsrx;                                           //~v55NI~
	plh=(((PUSCRD)(Ppcw->UCWpsd)+posy)->USDbuffc);                 //~v55NI~
	if (!plh)                                                      //~v55NI~
		return func_lineend_pan(Ppcw);                             //~v55NI~
    pdh=UGETPDH(plh);                                              //~v55NI~
    fldno=PANL310LINENO;                                           //~v55NI~
    newposx=0;                                                     //~v55NM~
  	if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN1))  //attrcmd             //~v55NI~
    {                                                              //~v55NI~
        fldno=PANL310ATTR;                                         //~v55NI~
//  	if (posx>=(UDHLINENOSZ+offsetof(UDIRLD,UDDattrflag)))      //~v59TR~
//  	if (posx>=(int)(UDHLINENOSZ+offsetof(UDIRLD,UDDattrflag)+expandlen))//~v59TR~//~vb30R~
    	if (posx>=(int)(UDHLINENOSZ+(int)offsetof(UDIRLD,UDDattrflag)+expandlen))//~vb30I~
        {                                                          //~v55NI~
			if (dirgetfldpos(Ppcw,plh,fldno,&pc,0))                //~v55NI~
            	newposx=(int)strlen(pc);                           //~v59MR~
        }                                                          //~v55NI~
    }                                                              //~v55NI~
    else                                                           //~v55NI~
  	if (UCBITCHK(pdh->UDHflag,UDHFLCMDIN2))  //other cmd rename fld use//~v55NI~
    {                                                              //~v55NI~
        fldno=PANL310RENAME;                                       //~v55NI~
//  	if ((UINT)posx>=UDHLINENOSZ+offsetof(UDIRLD,UDDrname[0]))  //~v59TR~
//  	if ((UINT)posx>=UDHLINENOSZ+offsetof(UDIRLD,UDDrname[0])+expandlen)//~v59TI~//~vb30R~
    	if (posx>=UDHLINENOSZ+(int)offsetof(UDIRLD,UDDrname[0])+expandlen)//~vb30R~
        {                                                          //~v55NI~
			if (dirgetfldpos(Ppcw,plh,fldno,&pc,0))                //~v55NI~
            	newposx=(int)strlen(pc);                           //~v59MR~
        }                                                          //~v55NI~
    }                                                              //~v55NI~
	return csronthefld(Ppcw,posy,fldno,newposx);//top of client fld//~v55NI~
}//file_lineend_dir                                                //~v55NI~
//**********************************************************       //~v57gI~
//* sort dirlist by size/time/name *************************       //~v57gI~
//**********************************************************       //~v57gI~
#ifdef DOSDOS                                                      //~v57gI~
int func_sort_dir(PUCLIENTWE Ppcw)                                 //~v57gI~
{                                                                  //~v57gI~
    return errnotsupported("SORt","DOS version");                  //~v57gI~
}//func_sort_dir                                                   //~v57gI~
#else  //!DOSDOS                                                   //~v57gI~
int func_sort_dir(PUCLIENTWE Ppcw)                                 //~v57gI~
{                                                                  //~v57gI~
    int rc,sorttype;                                               //~v57gR~
    char *pc,*psortp;                                              //~v57gI~
    UCHAR   lcmdparm[8]; //getflddata                              //~v57gI~
//*********************************                                //~v57gI~
	if (!(pc=Ppcw->UCWparm))		//operand                      //~v57gI~
    {                                                              //~v57gI~
//      uerrmsg("SOR { N | T | S }",0);                            //~v57rR~
//      uerrmsg("SOR [/o][-]{N | T | S}[-]",0);                    //~v59MR~
        uerrmsg("SOR [ [/o]{N | T | S}[-] ]",0);//reverse is after only//~v59MR~
        return 0;                                                  //~v57gI~
    }                                                              //~v57gI~
//  if (*pc=='/')                                                  //~v59MR~
    if (*pc=='/'||*pc=='-')                                        //~v59MI~
    {                                                              //~v57rI~
//  	pc++;                                                      //~v59MR~
//      if (*pc=='o'||*pc=='O')                                    //~v59MR~
//      	pc++;                                                  //~v59MR~
        if (*(pc+1)=='o'||*(pc+1)=='O')                            //~v59MI~
        	pc+=2;                                                 //~v59MI~
    }                                                              //~v57rI~
    psortp=pc;                                                     //~v57gI~
//  if (*pc=='-')                                                  //~v59MR~
//  	pc++;                                                      //~v59MR~
    switch (toupper(*pc))                                          //~v57gI~
    {                                                              //~v57gI~
    case 'N':                                                      //~v57gI~
        sorttype=0;	//no parm                                      //~v57gI~
        break;                                                     //~v57gI~
    case 'S':                                                      //~v57gI~
    case 'T':                                                      //~v57gI~
        sorttype=1; //pass parm                                    //~v57gI~
        break;                                                     //~v57gI~
    default :                                                      //~v57gI~
    	uerrmsg("dirlist sort option err(%s)",0,                   //~v57gI~
        		psortp);                                           //~v57gI~
        return 4;                                                  //~v57gI~
    }                                                              //~v57gI~
    pc++;                                                          //~v57gI~
    if (*pc=='-')                                                  //~v57gI~
        pc++;                                                      //~v57gI~
    *(pc+1)=0;                                                     //~v57gI~
    if (sorttype)                                                  //~v57gI~
	    sprintf(lcmdparm,"/o%s",psortp);                           //~v57gI~
    else                                                           //~v57gI~
    	*lcmdparm=0;                                               //~v57gI~
	rc=dlcmdexpandbysort(Ppcw,lcmdparm);                           //~v57gR~
    return rc;                                                     //~v57gI~
}//func_sort_dir                                                   //~v57gR~
#endif  //!DOSDOS                                                  //~v57gI~
//**********************************************************       //~vb60I~
//*get first non path entry                                        //~vb60I~
//**********************************************************       //~vb60I~
PUDIRLH getdefaultentry(PUFILEH Ppfh)                              //~vb60I~
{                                                                  //~vb60I~
	PULINEH plh;                                                   //~vb60I~
    PUDIRLH pdh,pdhfound=0;                                        //~vb60I~
//***************                                                  //~vb60I~
	plh=UGETQTOP(&Ppfh->UFHlineque);	//1st                      //~vb60I~
    for (;plh=UGETQNEXT(plh),plh && plh->ULHtype==ULHTDATA;)       //~vb60I~
    {                                                              //~vb60I~
        pdh=UGETPDH(plh);                                          //~vb60R~
      	if (pdh->UDHtype!=UDHTPARENT)                              //~vb60I~
        {                                                          //~vb60I~
        	pdhfound=pdh;                                          //~vb60I~
        	break;                                                 //~vb60I~
        }                                                          //~vb60I~
    }                                                              //~vb60I~
    return pdhfound;                                               //~vb60I~
}//getdefaultentry                                                 //~vb60I~
//**********************************************************       //~vb60I~
//*get linenumber filename by -n option                            //~vb60I~
//**********************************************************       //~vb60I~
int getlinenumbername(PUFILEH Ppfh,char *Popd,char *Pmembername)	//~vb60I~
{                                                                  //~vb60I~
	int len,lineno,ii,rc=0,swfound=0;                              //~vb60R~
	PULINEH plh;                                                   //~vb60I~
    PUDIRLH pdh;                                                   //~vb60I~
//*********************************                                //~vb60I~
	*Pmembername=0;	//id of not selected                           //~vb60I~
	if (*Popd!=CMDFLAG_PREFIX && *Popd!=CMDFLAG_PREFIX2)           //~vb60R~
    	return 0;                                                  //~vb60I~
  	if (*(Popd+1)=='?'||*(Popd+1)=='h')                            //~vbp1I~
    	return fileedithelp('S');                                  //~vbp1R~
  if (*(Popd+1)=='-')                                              //~vbp1I~
  {                                                                //~vbp1I~
    len=(int)strlen(Popd+2);                                       //~vbp1I~
    if (unumlen(Popd+2,0/*digit*/,len)!=len)                       //~vbp1I~
    	return 0;                                                  //~vbp1I~
    lineno=atoi(Popd+2);                                           //~vbp1I~
//	lineno=UGETQCTR(&Ppfh->UFHlineque)-2-lineno;	//from last    //+vbp1R~
  	lineno=(int)UGETQCTR(&Ppfh->UFHlineque)-2-lineno;	//from last//+vbp1I~
  }                                                                //~vbp1I~
  else                                                             //~vbp1I~
  {                                                                //~vbp1I~
    len=(int)strlen(Popd+1);                                       //~vb60I~
    if (unumlen(Popd+1,0/*digit*/,len)!=len)                       //~vb60I~
    	return 0;                                                  //~vb60I~
    lineno=atoi(Popd+1);                                           //~vb60I~
  }                                                                //~vbp1I~
	plh=UGETQTOP(&Ppfh->UFHlineque);	//1st                      //~vb60I~
    for (ii=1;plh=UGETQNEXT(plh),plh;ii++)                         //~vb60I~
    {                                                              //~vb60I~
    	if (ii==lineno)                                            //~vb60I~
        {                                                          //~vb60I~
        	swfound=1;                                             //~vb60I~
			if (plh->ULHtype!=ULHTDATA)                            //~vb60I~
        	{                                                      //~vb60I~
    			uerrmsg("LineNumber:%d is not a member entry",     //~vb60I~
						"行番号:%d はメンバー行ではありません",    //~vb60I~
                        lineno);                                   //~vb60I~
        		rc=4;                                              //~vb60I~
        	}                                                      //~vb60I~
            else                                                   //~vb60I~
            {                                                      //~vb60I~
        		pdh=UGETPDH(plh);                                  //~vb60I~
      			if (pdh->UDHtype==UDHTPARENT)                      //~vb60I~
        		{                                                  //~vb60I~
    				uerrmsg("LineNumber:%d is path entry",         //~vb60I~
							"行番号:%d は経路行です",              //~vb60R~
                        	lineno);	                           //~vb60I~
        			rc=4;                                          //~vb60I~
                }                                                  //~vb60I~
        		sprintf(Pmembername,"\"%s\"",pdh->UDHname);        //~vb60I~
        	}                                                      //~vb60I~
            break;                                                 //~vb60I~
        }                                                          //~vb60I~
    }                                                              //~vb60I~
    if (!swfound)                                                  //~vb60R~
    {                                                              //~vb60I~
        uerrmsg("LineNumber:%d is out of range",                   //~vb60I~
                "行番号:%d は範囲外です",                          //~vb60R~
                lineno);                                           //~vb60I~
        rc=4;                                                      //~vb60I~
    }                                                              //~vb60I~
    return rc;                                                     //~vb60I~
}//getlinenumbername                                               //~vb60I~
