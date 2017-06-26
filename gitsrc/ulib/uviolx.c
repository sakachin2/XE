//*CID://+v6EtR~:                             update#=  100;       //~v6EtR~
//*************************************************************
//*uviol for gxe and Axe                                           //~v6ErI~
//*************************************************************    //~v6ErI~
//v6Et:160816 (XXE)for xe:vb4A,when Ligature mode display at xxecsub altch of UNICOMB UNPR//~v6EtI~
//v6Er:160814 (Bug:XXE)UNCOMB UNPR was ignored                     //~v6ErI~
//v6Eq:160812 lineopt should be cleared by USDFNCELL               //~v6EqI~
//v6Ep:160812 (WXE)errmsg lineopt;strput called intermediate of errmsg string by attr change,it should not Col but msg len//~v6EpI~
//v6Eo:160811 (XXE)v6ei for XXE(specify ligature on/off,combine on/of line by line(used for edit/filename  panel)//~v6EoI~
//v6Bd:160207 (LNX)compiler warning                                //~v6BdI~
//v6Bc:160207 (BUG:W32)screen corrupted when screen buffer width is odd number//~v6BcI~
//            For gxe,Scrwidth=240,so no bug appear but correct it //~v6BcI~
//v6b9:111117 (gcc4.6)Warning:unused-but-set                       //~v6b9I~
//v5ky:071006*(WXE:BUG)scrcls parme len is multiline(LINEUPDATE flag set on multiple line)//~v5kyI~
//v5g6:050613 (XXE)xxe support                                     //~v5g6I~
//v5fy:050419 del UTRACE(helpmsg call uviogetmode)                 //~v5fyI~
//v5fh:050125 (W32)window should be at current last of consolebuff //~v5fhI~
//v5e0:040828 drop dangerouse coding(using __asm)                  //~v5e0I~
//v5bj:040209 (WIN)set scree size from window size not by buff size//~v5bjI~
//v570:020824 wxe support                                          //~v570I~
//v534:020315 (WIN/AIX)screen width parameter support              //~v534I~
//v531:020309 (WIN)screen height parameter support                 //~v531I~
//v50X:011202 force nt option for vio                              //~v50XI~
//v307 000422:try test for scr unable to redraw.                   //~v307I~
//v305 000409:(Win:BUG)cause of eh fail.uehexit-->scrcls-->uviowrtncell-->memcpy//~v252I~
//            memcpy source Sw95buffa malloc size is screen width  //~v252I~
//            but scrcl request scrieen size write by space.       //~v252I~
//            loop required bu screen width.                       //~v252I~
//v252:990626 (Win):for redirect;Once create console buff and then get inf befre destroy//~v252I~
//                  return rc=1 when redirected.                   //~v252I~
//v@@@ test trace on 98/01/31 18:52 version                        //~v@@@R~
//v157:980131 scr height for W95 english mode(set value included IME line,//~v157I~
//            caller chk english mode and count down.it is same as DOS)//~v157I~
//            Only OS/2 dos session return 23(lineno except IME line.//~v157I~
//            leave it until OS/2 can be determinable.             //~v157I~
//v155:980123 (BUG:NT)under NT english mode fullscreen x'00' by cell write//~v153I~
//            display invalid char.                                //~v153I~
//            English mode chk by udbcschk(chk dbcs env tbl) in not valid//~v153I~
//            because NT english mode has dbcs tbl.So use udbcschkcp.//~v153I~
//v153:980123 (BUG:DOS/GCC)DOS english mode under OS/2 video buff is virtul//~v153I~
//            but dbcs tble is null.And os/2 hang soon if dbcs is written.//~v153I~
//            So vbuff is virtual and english mode,change dbcs first byte to//~v153I~
//            special char.                                        //~v153I~
//v151:980119 (BUG:DOS/GCC)video buff direct write determined by not dbcs env//~v151I~
//            but video mode.video buff chk by int 10 ah=FE        //~v151I~
//            (none is displayed under os2 dos session when changed chev us)//~v151I~
//            add udpmiint86x(pass through es/dsetc )              //~v151I~
//v149:980118 (GCC:BUG)w96buffwrite support rec(height,width) specification//~v149I~
//v145:980116 (W32)performance reason                              //~v145I~
//            -uvio_w95wrtcharstratt3 (2 part attr at once)        //~v145I~
//v144:980116 (W32)WINNT support                                   //~v144I~
//            -USDCELLSTR2 type support for cell write required case//~v144I~
//				uvio_w95wrtcharstratt2                             //~v144I~
//v143:980115 (BUG:W32)uvio_w95buffwrite--uviowrtcellstr interface //~v143I~
//             height for cell ctr specified case                  //~v143I~
//v142:980115 (W32)WINNT support                                   //~v142I~
//            -Nt english mode cannot display ctl char normaly when fullscreen//~v142R~
//             WriteConsoleOutputCharacter+WriteConsoleOutputAttribute//~v142R~
//             cdisplay ? for some ctl char,buff image for x'00'   //~v142I~
//             WriteConsoleOutput is errornous for x'00' only.     //~v142I~
//            -same matter for WriteConsolCharacter+FillConsoleOutputAttribute//~v142I~
//v054:970111:for also DOS,getwork by full screen size at init to avoid//~v053R~
//            frequent get/free.                                   //~v053I~
//v053:970107:gcc version(control by DPMI)                         //~v053R~
//     970406 -short size ont equal int size                       //~v053I~
//v046:961112:screen row is already -1 if IME is on at start.      //~v046I~
//v045:961109:(BUG)buffwrite ctr                                   //~v045I~
//v044:961106:too large for XEDOS,split uvio.c to uvio2.c          //~v044I~
//v043:961104:(W95)write attr string function support              //~v043I~
//v042:961102:(W95)write all line to screen by one api issue for performance//~v042I~
//v034:961008:VC support(identify by (_MSC_VER>=800))              //~v034I~
//           .scroll function not usefull for clear screen         //~v034R~
//            (dest position must not negative,so need twice half scroll)//~v034I~
//           .WriteConsoleOutput is not effective when full-screen mode//~v034I~
//            Output can be seen after when change active screen buffer//~v034I~
//            to another and returned.                             //~v034I~
//            (so use WriteConsoleOutputCharacter and WriteConsoleOutputAttribute)//~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*uvio_init/uvio_term                                             //~v022R~
//*uviogetmode                                                     //~v044R~
//*uviosetmode                                                     //~v044R~
//*uvioreadcellstr/uvioreadcharstr
//*uviowrtcellstr/uviowrtcharstr/uviowrtcharstratt/uviowrtattrstr  //~v043R~
//*uviowrtnattr/uviowrtncell/uviowrtnchar
//*************************************************************
//v015:960211:(BUG)uviowrttty advance char ptr for DOS          //~6212I~
//951001:malloc uvio work at init(uvio_init,uvio_term)          //~5A01I~
//950930:malloc/calloc rc chk for dos                           //~5930I~
//*950513 write direct to b800 when english display mode 3      //~5513I~
//*       (int10 ax=1302 cause scroll up when write to row 25 col 80)//~5513I~
//*950222 scroll down/up                                        //~5222R~
//*941221 int 10 ax=1302 for english mode not but 1320          //~5222I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
//*******************************************************
#include <ulib.h>                                                  //~v022R~
#include <ualloc.h>
#include <udbcschk.h>
#include <uvio.h>
#include <uvio2.h>                                                 //~v044I~
#include <uviol.h>                                                 //~v6ErI~
#include <uerr.h>                                                  //~v022I~
#include <uedit.h>                                                 //~v022I~
#include <utrace.h>                                                //~v034I~
#include <udos.h>                                                  //~v159I~
#include <uviom.h>                                                 //~v6EoI~
#include <utf.h>                                                   //~v6ErI~
#include <utf22.h>                                                 //~v6ErI~
    #include <xxexei.h>     //ukbd_w95init                         //~v5g6I~
//*******************************************************          //~v5g6I~
typedef struct _CHAR_INFO {                                        //~v5g6I~
    union {                                                        //~v5g6I~
        WCHAR UnicodeChar;                                         //~v5g6I~
        CHAR   AsciiChar;                                          //~v5g6I~
    } Char;                                                        //~v5g6I~
    WORD Attributes;                                               //~v5g6I~
} CHAR_INFO, *PCHAR_INFO;                                          //~v5g6I~
                                                                   //~v5g6I~
//*******************************************************
  	#define	ATTRCOUNT() Sattrcount
                                                                //~5A01I~
    #define UALLOCM16WORK(len)                       \
        ( ((len) <= Svioworklen) ? Sviowork :        \
							(		UTRACEP("uallocm16work len=%d\n",len),\
		 							((PCH)UALLOCM16(len)) )  )     //~v142R~
    #define UFREE16WORK(addr)                       \
        if ((char*)(addr)!= Sviowork)                      \
        	UTRACEP("ufree16work addr=%08x\n",addr), \
			ufree16(addr)                                          //~v142R~

//*******************************************************
#define OS2DOSENGDISP    0xb2                                      //~v153R~
#define WINNTNULLDISP    ' '  //if >=x'80',disply ? actualy under nt eng fullscreen//~v153R~
                              //disply it if windows mode          //~v153I~
		static  int     Sattrcount=1;	//attribute byte counte    //~v022I~
    	static  int     Svioworklen; 	//vioworklen               //~v022I~
    	static 	char 	*Sviowork;		//to avoid malloc at emergency msg//~v022I~
        static  char    Scellnasw;//cell write or char and attr write//~v142I~
                                                                   //~v042I~
                                                                   //~v5g6I~
                                                                   //~v042I~
		static  UCHAR   *Sw95buffc;		//screen char buffer       //~v042I~
		static  UCHAR   *Swxelineupdate;	//line update flag tbl //~v570R~
        static  int     Sscrheight;  	//scr line count           //~v570I~
		static  WORD    *Sw95buffa;		//screen attribute buffer  //~v042R~
		static  WORD    *Sw95buffa0;	//screen attribute buffer foe save const//~v043I~
		static  int     Sw95buffoptsz;	//ligature option for line by line//~v6EoI~
        static  int     Sscrsize;   	//screen size(row*col)     //+v042I~//~v042I~
        static  int     Sscrwidth;   	//scr line size            //+v042I~//~v042I~
    	void uviogetwork(int Pscrwidth);                           //~v042I~
		WORD *uvio_w95getattrtbl(USHORT Pattr);                    //~v043R~
		void  uvio_w95setscrattr(void *Pout,USHORT Pattr,int Plen);//~v252I~
		int uvio_w95writecell(int Ptype,int Prow,int Pcol,int Plen,void *Pstr1,void *Pstr2);//~v142I~
                                                                   //~v531I~
#ifndef OS2                                                        //~v5e0I~
static int Sheightparm=0,Swidthparm=0;	//user specification       //~v531I~
#endif                                                             //~v5e0I~

static VIOMODEINFO SvioModeInfo;	//save current mode
                                                                //~5A01I~
static  UCHAR   *Sdbcstbl;		//xe's scr dbcstbl                 //~v6ErI~
//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void uvio(void)
{
	return;
}

//*******************************************************       //~5A01I~
//*free vio work                                                //~5A01I~
//*******************************************************       //~5A01I~
void uviofreework(void)                                         //~5A01I~
{                                                               //~5A01I~
//**********************                                        //~5A01I~
//UTRACEP("uviofreework\n");                                       //~v5fyR~
	if (Sviowork)                                               //~5A01I~
    {                                                           //~5A01I~
	    ufree16(Sviowork);		//cell size                     //~5A01I~
    	Sviowork=0;                                             //~5A01I~
	    Svioworklen=0;                                          //~5A01I~
	}                                                           //~5A01I~
	if (Sw95buffc)                                                 //~v042I~
	    ufree16(Sw95buffc);                                        //~v042I~
	if (Sw95buffa0)                                                //~v043I~
	    ufree16(Sw95buffa0);                                       //~v043I~
	if (Swxelineupdate)                                            //~v570I~
	    ufree(Swxelineupdate);                                     //~v570I~
    if (Gw95buffopt)                                               //~v6EoI~
        ufree(Gw95buffopt);                                        //~v6EoI~
    Swxelineupdate=0;                                              //~v570I~
	Sw95buffc=0;                                                   //~v043R~
	Sw95buffa0=0;                                                  //~v043I~
    Gw95buffopt=0;                                                 //~v6EoI~
	return;                                                     //~5A01I~
}//uviofreework                                                 //~5A01I~
                                                                //~5A01I~
//*******************************************************       //~5A01I~
//*get vio work                                                 //~5A01I~
//*parm:screen width                                            //~5A01I~
//*******************************************************       //~5A01I~
void uviogetwork(int Pscrwidth)                                 //~5A01I~
{                                                               //~5A01I~
    int len;                                                    //~5A01I~
//**********************                                        //~5A01I~
//#ifdef W32                                                       //~v5g6R~
//  len=Pscrwidth*sizeof(CHAR_INFO);	//cell size                //~v042R~//~v6BdR~
    len=Pscrwidth*(int)sizeof(CHAR_INFO);	//cell size            //~v6BdI~
//#else                                                            //~v5g6R~
//    len=Pscrwidth*(ATTRCOUNT()+1);      //cell size              //~v5g6R~
//#endif                                                           //~v5g6R~
    if (len==Svioworklen)                                          //~v042R~
        return;                                                 //~5A01I~
	uviofreework();		//cell size                             //~5A01I~
    Svioworklen=len;		//cell size                         //~5A01R~
//  if (Svioworklen)                                               //~v042R~
//  Sviowork=UALLOCM16(Svioworklen);                        //~5A01I~//~v042R~//~v6BdR~
    Sviowork=UALLOCM16((size_t)Svioworklen);                       //~v6BdI~
    if (!Sviowork)                                                 //~v042R~
    	uerrexit("uviogetwork malloc failed(len=%d)",0,len);       //~v042I~
	Sw95buffoptsz=(Pscrwidth/Sscrwidth)*(int)sizeof(int)*2;	//opt for pcw1 and pcw2//~v6EoI~
  	Gw95buffopt=UALLOCC(1,(size_t)Sw95buffoptsz);	//opt for pcw1 and pcw2//~v6EoI~
//#ifdef W32                                                       //~v5g6R~
//  Sw95buffc=UALLOCM16(Pscrwidth*3);	//char+WORD+WORD tbl       //~v043R~//~v6BdR~
    Sw95buffc=UALLOCM16((size_t)Pscrwidth*3);	//char+WORD+WORD tbl//~v6BdI~
	if (!Sw95buffc)                                                //~v042R~
		uerrexit("Win95 scrren buff malloc failed(len=%d)",0,Pscrwidth*3);//~v042R~
    Sw95buffa=(USHORT*)(void*)(Sw95buffc+Pscrwidth);	//attr table//~v042R~
//  Sw95buffa0=UALLOCC(1,Sscrwidth*sizeof(USHORT));			//attr table for save value//~v570R~
//  Sw95buffa0=UALLOCC(1,Pscrwidth*sizeof(USHORT));			//attr table for save value//~v570I~//~v6BdR~
    Sw95buffa0=UALLOCC(1,(size_t)Pscrwidth*sizeof(USHORT));			//attr table for save value//~v6BdI~
//    #ifdef WXE                                                   //~v5g6R~
//  	Swxelineupdate=UALLOCC(1,Sscrheight);			//attr table for save value//~v570R~//~v6BdR~
    	Swxelineupdate=UALLOCC(1,(size_t)Sscrheight);			//attr table for save value//~v6BdI~
//      wxe_uviogetwork(Sw95buffc,Sw95buffa,Swxelineupdate);       //~v6EoR~
        wxe_uviogetwork(Sw95buffc,Sw95buffa,Swxelineupdate,Gw95buffopt);//~v6EoI~
//    #endif                                                       //~v5g6R~
//#endif                                                           //~v5g6R~
	return;                                                     //~5A01I~
}//uviogetwork                                                  //~5A01I~
                                                                //~5A01I~
//#endif                                                           //~v5g6R~
                                                                //~5A01I~
//*********************************************************************//~v6ErI~
//* uvio_init2                                                     //~v6ErI~
//*********************************************************************//~v6ErI~
void uviol_init2(UCHAR *Pdbcstbl)                                  //~v6ErR~
{                                                                  //~v6ErI~
//*************************                                        //~v6ErI~
	Sdbcstbl=Pdbcstbl;                                             //~v6ErI~
    return;                                                        //~v6ErI~
}//uvio_init2                                                      //~v6ErI~
//*******************************************************          //~v043I~
//uvio_w95getattrtbl                                               //~v043I~
//*(W95)get attr table constatnt value                             //~v043I~
//*parm1 :attr to set                                              //~v043I~
//*return:attr table                                               //~v043I~
//*******************************************************          //~v043I~
WORD *uvio_w95getattrtbl(USHORT Pattr)                             //~v043R~
{                                                                  //~v043I~
    int ii;                                                        //~v043I~
//*********************************                                //~v043I~
	if (*Sw95buffa0!=Pattr)                                        //~v043I~
    	for (ii=0;ii<Sscrwidth;ii++)                               //~v043I~
        	Sw95buffa0[ii]=Pattr;                                  //~v043I~
	return Sw95buffa0;                                             //~v043I~
}//uvio_w95getattrtbl                                              //~v043I~
//*******************************************************          //~v252I~
//uvio_w95setscrattr                                               //~v252I~
//*(W95)get screen attribute line by line                          //~v252I~
//*parm1 :out area                                                 //~v252I~
//*parm2 :attr to set(WORD)                                        //~v252I~
//*parm3 :out area len                                             //~v252I~
//*return:none                                                     //~v252I~
//*******************************************************          //~v252I~
void uvio_w95setscrattr(void *Pout,USHORT Pattr,int Plen)          //~v252I~
{                                                                  //~v252I~
    int len,width/*,linewidth*/;                                       //~v252R~//~v6b9R~
    int linewidth;                                                 //~v6BcI~
    char *pattrtb,*pout;                                           //~v252I~
//*********************************                                //~v252I~
	pattrtb=(char*)(void*)uvio_w95getattrtbl(Pattr);//len=scrwidth //~v252I~
    linewidth=(Sscrwidth<<1);                                      //~v252I~//~v6b9R~//~v6BcR~
    for (pout=Pout,len=Plen;len>0;len-=width,pout+=width)          //~v252I~
    {                                                              //~v252I~
//  	width=min(len,Sscrwidth);                                  //~v252I~//~v6BcR~
    	width=min(len,linewidth);                                  //~v6BcI~
//  	memcpy(pout,pattrtb,width);                                //~v252R~//~v6BdR~
    	memcpy(pout,pattrtb,(size_t)width);                        //~v6BdI~
	}                                                              //~v252I~
	return;                                                        //~v252I~
}//uvio_w95setscrattr                                              //~v252I~
//*******************************************************
//*uvio_initparm                                                   //~v531R~
//*******************************************************
//void uvio_initparm(int Pheight,int Pwidth)                       //~v534R~
void uvio_initparm(int *Pscrparm)                                  //~v534I~
{                                                                  //~v531I~
//  Sheightparm=Pheight;                                           //~v534R~
//  Swidthparm=Pwidth;                                             //~v534R~
#ifndef OS2
    if (Pscrparm)                                                  //~v534I~
    {                                                              //~v534I~
    	Sheightparm=Pscrparm[0];                                   //~v534R~
    	Swidthparm=Pscrparm[1];                                    //~v534R~
    }                                                              //~v534I~
#endif
    return;                                                        //~v531I~
}//uvio_initparm                                                   //~v534R~
//*******************************************************          //~v531I~
//*VioGetMode                                                      //~v531I~
//*rc=1:mean redirected(Win)                                       //~v531I~
//*******************************************************          //~v531I~
UINT uviogetmode(PVIOMODEINFO PvioModeInfo)                        //~v531I~
{
        HANDLE temph;                                              //~v252I~
        int buffh;                                                 //~v5fhI~
	APIRET16 rc16;
//*********************************
//      #ifdef WXE                                                 //~v5g6R~
        Scellnasw=1;	//wxe use 2 api TextOut and TextColor      //~v570I~
//      #else   //!WXE                                             //~v5g6R~
//      #endif //!WXE                                              //~v5g6R~
                                                                   //~v570I~
        temph=0;                                                   //~v252I~
        	memset(PvioModeInfo,0,sizeof(VIOMODEINFO));            //~v022I~
        	PvioModeInfo->cb=sizeof(VIOMODEINFO);                  //~v022I~
//text mode                                                        //~v022I~
        	PvioModeInfo->fbType=(UCHAR)(0*VGMT_GRAPHICS);         //~v022I~
//  color;                                                         //~v022I~
//        	PvioModeInfo->color=(UCHAR)3;  //3**4                  //~v5g6R~
          	PvioModeInfo->color=(UCHAR)4;  //color depth 2**4=16   //~v5g6I~
//colomn                                                           //~v022I~
//        #ifdef WXE                                               //~v5g6R~
            wxe_getmaxscrsize(&PvioModeInfo->col,&PvioModeInfo->row);//~v570R~
            buffh=PvioModeInfo->row;                               //~v5fhI~
//        #else                                                    //~v5g6R~
//        #endif                                                   //~v5g6R~
			if (Sheightparm)                                       //~v531I~
            {                                                      //~v531I~
//  			if (Sheightparm>PvioModeInfo->row)                 //~v5fhR~
    			if (Sheightparm>buffh)                             //~v5fhI~
                {                                                  //~v531I~
                	printf("Screen height parm(%d)>screen buff size(%d)",//~v531R~
//  						Sheightparm,PvioModeInfo->row);        //~v5fhR~
    						Sheightparm,buffh);                    //~v5fhI~
		        	return rc16=2;                                 //~v531R~
                }                                                  //~v531I~
//  			PvioModeInfo->row=Sheightparm;                     //~v531I~//~v6BdR~
    			PvioModeInfo->row=(USHORT)Sheightparm;             //~v6BdI~
			}                                                      //~v531I~
			if (Swidthparm)                                        //~v531I~
            {                                                      //~v531I~
				if (Swidthparm>PvioModeInfo->col)                  //~v531I~
                {                                                  //~v531I~
                	printf("Screen width parm(%d)>screen buff size(%d)",//~v531R~
							Swidthparm,PvioModeInfo->col);         //~v531I~
		        	return rc16=2;                                 //~v531R~
                }                                                  //~v531I~
//  			PvioModeInfo->col=Swidthparm;                      //~v531I~//~v6BdR~
    			PvioModeInfo->col=(USHORT)Swidthparm;              //~v6BdI~
			}                                                      //~v531I~
                                                                   //~v531I~
//hres;                                                            //~v022I~
//vres;                                                            //~v022I~
//fmt_ID				//temp use                                 //~v022I~
			PvioModeInfo->fmt_ID=(UCHAR)3;                         //~v022I~
//atrribute byte count                                             //~v022I~
    		PvioModeInfo->attrib=(UCHAR)Sattrcount;                //~v022I~
//buf_addr;                                                        //~v022I~
//buf_length;                                                      //~v022I~
//full_length;                                                     //~v022I~
//partial_length;                                                  //~v022I~
//ext_data_addr;                                                   //~v022I~
                                                                   //~v022I~
//        #ifdef WXE                                               //~v5g6R~
        	Sscrheight=PvioModeInfo->row;                          //~v570I~
//        #else   //!WXE                                           //~v5g6R~
//            Sbuffattr=csbi.wAttributes;                          //~v5g6R~
//        #endif //!WXE                                            //~v5g6R~
        	Sscrwidth=PvioModeInfo->col;          //+v042R~         //~v042I~//~v043I~
        	Sscrsize =PvioModeInfo->col*PvioModeInfo->row;          //+v042R~//~v042I~//~v043I~
        	uviogetwork(Sscrsize);	//malloc work                  //~v043R~
          if (temph)                                               //~v252I~
            rc16=1;     //notify redirected                        //~v252I~
          else                                                     //~v252I~
        	rc16=0;                                                //~v022I~
//      }                                                          //~v252R~
//        #ifndef WXE                                              //~v5g6R~
//            Stoplineoffs=uvio_setinitwindowpos(&csbi,(int)(PvioModeInfo->row));//~v5g6R~
//            uvio2_init(Shconout,Stoplineoffs);  //pass to uvio2  //~v5g6R~
//        #endif                                                   //~v5g6R~
	SvioModeInfo=*PvioModeInfo;	//save current
   	return (UINT)rc16;
}//uviogetmode                                                     //~v252R~

//*******************************************************
//*VioSetMode(for Win95 resize by new (col,row))                   //~v022R~
//*parm:pviomodeinfo,if 0 free work and return                  //~5A01I~
//*******************************************************
UINT uviosetmode (PVIOMODEINFO pvioModeInfo)
{
	APIRET16 rc16;
//*********************************
	if (!pvioModeInfo)                                          //~5A01I~
    {                                                              //~v034I~
    	uviofreework();                                            //~v034I~
        return 0;                                               //~5A01I~
    }                                                              //~v034I~
    	rc16=0;                                                    //~v570I~
    return (UINT)rc16;
}//uviosetmode

//*******************************************************
//*VioReadCellStr
//*******************************************************
UINT uvioreadcellstr(PCH pchCellStr,int *Pplen,int Prow,int Pcol)
{
		UCHAR  *pcd;                                               //~v570R~
		USHORT *pca;                                               //~v570I~
		int len,reqctr;                                            //~v570I~
//*********************************
        pcd=UVIO_TEXTDATA(Prow,Pcol);                              //~v570I~
        pca=UVIO_ATTRDATA(Prow,Pcol);                              //~v570I~
    	reqctr=*Pplen/2;				//cell count               //~v570I~
        for (len=0;len<reqctr;len++)  //char(BYTE)+attr(BYTE) fmt  //~v570I~
        {                                                          //~v570I~
            *pchCellStr++=*pcd++;                                  //~v570I~
            *pchCellStr++=(UCHAR)(*pca++);                         //~v570R~
        }                                                          //~v570I~
        return 0;                                                  //~v570R~
}//uvioreadcellstr

//*******************************************************
//*VioWrtCellStr
//*parm1:cell(char+attr) addr                                      //~v042I~
//*parm2:cell string len                                           //~v042I~
//       or height+width(W95 only,avail when write from buff and box mode)//~v042I~
//*parm3:target row                                                //~v042I~
//*parm4:target column                                             //~v042I~
//*ret  :rc                                                        //~v042R~
//*******************************************************          //~v042I~
//UINT uviowrtcellstr (PCH pchCellStr,int Plen,int Prow,int Pcol)  //~v6EoR~
UINT uviowrtcellstr (int Popt,PCH pchCellStr,int Plen,int Prow,int Pcol)//~v6EoI~
{
		int len,reqctr;                                            //~v034R~
        int pos,height;                                            //~v143R~
        UINT rc;                                                   //~v034I~
		char      *wpch;                                           //~v034I~
		WORD      *wpat;                                           //~v034I~
        int swcombaltch;                                           //~v6ErI~
        char *pdbcs,wkdddata[2],wkdddbcs[2];                       //~v6ErR~
//*********************************
//#ifdef DOS                                                       //~v5g6R~
//#else                                                            //~v5g6R~
//    #ifdef W32                           //win95                 //~v5g6R~
        height=(Plen>>16);                                         //~v042I~
        if (height)                                                //~v042I~
//  		reqctr=(Plen&0xffff);                                  //~v149R~
    		reqctr=height*Sscrwidth;    //called from writebuff,needed cell buff ctr;//~v149I~
        else                                                       //~v042I~
    	reqctr=Plen/2;                                             //~v034I~
                                                                   //~v022I~
#ifndef XXE                                                        //~v5g6I~
      if (Sw95buffmode==WRITETOBUFF)                               //~v042R~
      {                                                            //~v042I~
#endif                                                             //~v5g6I~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+reqctr)>Sscrsize)                    //~v042R~
            	rc=8;                                              //~v042I~
            else                                                   //~v042I~
            {                                                      //~v042I~
//#ifdef WXE                                                       //~v5g6R~
            	UVIO_LINEUPDATE(Prow);                             //~v570I~
//#endif                                                           //~v5g6R~
//            	uvio_setbufflineopt(0,Prow,Popt);                  //~v6EpR~
              	uvio_setbufflineopt(0,Prow,Popt,Pcol,reqctr);      //~v6EpI~
                wpch=&Sw95buffc[pos];                              //~v042I~
                wpat=&Sw95buffa[pos];                              //~v042I~
                pdbcs=Sdbcstbl+pos;//xe's Gscrdbcstbl              //~v6ErR~
                UTRACED("inp pChCEllStr",pchCellStr,reqctr*2);     //~v6ErM~
                UTRACED("inp dbcs",pdbcs,reqctr);                  //~v6ErI~
    		  if (xxe_optligature(XXEIOLO_ISON,0))//ligature mode  //+v6EtR~
                swcombaltch=0;                                     //+v6EtI~
              else                                                 //+v6EtI~
                swcombaltch=(UTF_COMBINEMODE_NP()                  //~v6ErR~
 							&& Gutfcombaltch                       //~v6ErR~
							&& (UTF_UCS2DDSBCS((ULONG)Gutfcombaltch,wkdddata,wkdddbcs)<=1)//~v6ErR~
                            );                                     //~v6ErI~
                UTRACEP("%s:swcombaltch=%x,altch=%02x,attrfg=%02x,altch dddata=%02x,dddbcs=%02x\n",UTT,swcombaltch,Gutfcombaltch,ATTR_COMBINENP_FG,*wkdddata,*wkdddbcs);//~v6ErR~
            	for (len=0;len<reqctr;len++)  //charstring+attrtbl //~v042I~
                {                                                  //~v042I~
                	*wpch++=*pchCellStr++;                         //~v042I~
                	*wpat++=(WORD)*pchCellStr++;                   //~v042I~
                    if (swcombaltch)                               //~v6ErI~
                    	if (UDBCSCHK_ISUCSWIDTH0(*pdbcs))          //~v6ErI~
                        {                                          //~v6ErI~
                        	*(wpch-1)=wkdddata[0];                 //~v6ErR~
		                	*(wpat-1)=(WORD)((*(wpat-1)&0xf0)|ATTR_COMBINENP_FG);//@@@@test uviol_repfg?//~v6ErR~
                        	UTRACEP("%s:set combinealtch ch=%02x,attr=%02x,olddbcs=%02x,newch=%02x,newat=%02x\n",UTT,*(pchCellStr-2),*(pchCellStr-1),*pdbcs,*(wpch-1),*(wpat-1));//~v6ErR~
                            *pdbcs=wkdddbcs[0];                    //~v6ErI~
                        }                                          //~v6ErI~
                    pdbcs++;                                       //~v6ErI~
                }                                                  //~v042I~
                UTRACED("uviowrtcellstr ch",&Sw95buffc[pos],reqctr);//~v6b9I~
                UTRACED("uviowrtcellstr attr",&Sw95buffa[pos],reqctr*(int)sizeof(WORD));//~v6b9I~//~v6BdR~
                rc=0;                                              //~v042I~
            }                                                      //~v042I~
#ifndef XXE                                                        //~v5g6I~
      }                                                            //~v042I~
      else  //not write to buff                                    //~v042R~
      {                                                            //~v042I~
		len=reqctr*sizeof(CHAR_INFO);		//cell read work       //~v034R~
//  	wko=wk=(PCHAR_INFO)(PVOID)UALLOCM16WORK(len);		//cell read work//~v142R~
//      UALLOCCHK(wk,UALLOC_FAILED);                               //~v142R~
//      if (Sfullscreensw)                                         //~v142R~
        if (Scellnasw)      //cell write not avail                 //~v142I~
        {                                                          //~v034I~
    		wko=wk=(PCHAR_INFO)(PVOID)UALLOCM16WORK(len);		//cell read work//~v142I~
        	UALLOCCHK(wk,UALLOC_FAILED);                           //~v142I~
            coordpos.X  =(SHORT)Pcol;                              //~v034I~
//          coordpos.Y  =(SHORT)Prow;                              //~v5fhR~
            coordpos.Y  =(SHORT)(Prow+Stoplineoffs);               //~v5fhI~
                                                                   //~v034I~
	      if (Sw95buffmode==WRITEFROMBUFF)                         //~v042R~
          {                                                        //~v042I~
            coordpos.X  =0;                                        //~v149I~
//          pos=Pcol+Prow*Sscrwidth;                               //~v149R~
            pos=Prow*Sscrwidth;                                    //~v149I~
            wpch=&Sw95buffc[pos];                                  //~v042I~
            wpat=&Sw95buffa[pos];                                  //~v042I~
          }                                                        //~v042I~
          else                                                     //~v042I~
          {				//write from parm                          //~v042I~
            wpch=(void*)wko;                                       //~v034I~
            wpat=(void*)(wpch+reqctr);                             //~v034I~
        	for (len=0;len<reqctr;len++)  //charstring+attrtbl     //~v034I~
            {                                                      //~v034I~
            	*wpch++=*pchCellStr++;                             //~v034R~
            	*wpat++=(WORD)*pchCellStr++;                       //~v034R~
            }                                                      //~v034I~
            wpch=(void*)wko;                                       //~v034I~
            wpat=(void*)(wpch+reqctr);                             //~v034I~
          }//write from buff or else                               //~v042I~
    		rc=!WriteConsoleOutputCharacter(Shconout,		//write to buffer//~v034I~
    										wpch,			//char //~v034I~
                                    		reqctr,                //~v034I~
                                    		coordpos,		//upper left pos in source buff//~v034I~
                                			&len);			//writelen//~v034I~
            if (rc)                                                //~v034I~
                rc=uerrapi0("WriteConsoleOutputCharacter",GetLastError());//~v034I~
UTRACED("uviowrtcellstr cordpos",&coordpos,sizeof(coordpos));      //~v@@@R~
UTRACED("uviowrtcellstr WriteConsoleOutputCharacter",wpch,reqctr); //~v@@@I~
    		rc=!WriteConsoleOutputAttribute(Shconout,		//write to buffer//~v034I~
    										wpat,			//attribute//~v034I~
                                    		reqctr,                //~v034I~
                                    		coordpos,		//upper left pos in source buff//~v034I~
                                			&len);			//writelen//~v034I~
            if (rc)                                                //~v034I~
                rc=uerrapi0("WriteConsoleOutputAttribute",GetLastError());//~v034I~
UTRACED("uviowrtcellstr WriteConsoleOutputAttribute",wpat,reqctr*2);//~v@@@R~
  		  	UFREE16WORK((char*)(void*)wko);                        //~v142I~
        }                                                          //~v034I~
        else    //fullscreensw off(box write)                      //~v042R~
        {                                                          //~v034I~
//****use writeconsoleoutput                                       //~v142I~
	      if (Sw95buffmode==WRITEFROMBUFF)                         //~v042I~
           if (height)                                             //~v149I~
            rc=uvio_w95writecell(6,Prow,Pcol,Plen,Sw95buffc,Sw95buffa);//parm is char+ushort attr//~v149I~
           else                                                    //~v149I~
            rc=uvio_w95writecell(1,Prow,Pcol,reqctr,Sw95buffc,Sw95buffa);//parm is char+ushort attr//~v142R~
          else                                                     //~v042I~
            rc=uvio_w95writecell(2,Prow,Pcol,reqctr,pchCellStr,0);//parm is cell//~v142R~
		}                                                          //~v034I~
//  	UFREE16WORK((char*)(void*)wko);                            //~v142R~
      }//buff mode or else                                         //~v042I~
#endif //!XXE                                                      //~v5g6I~
        return rc;                                                 //~v034I~
//    #else                                                        //~v5g6R~
//   return (UINT)VioWrtCellStr(pchCellStr,(USHORT)Plen,(USHORT)Prow,(USHORT)Pcol,0);//~v5g6R~
//    #endif                                                       //~v5g6R~
//#endif                                                           //~v5g6R~
}//uviowrtcellstr

#ifndef XXE		//no actual user                                   //~v5g6I~
//*******************************************************
//*VioReadCharStr(read char+attr then pick up char)
//*******************************************************
UINT uvioreadcharstr(PCH pchStr,int *Pplen,int Prow,int Pcol)
{
		COORD 		coord;				//read pos                 //~v022I~
        DWORD       len;                                           //~v022R~
		APIRET16 rc16;                                             //~v022I~
//*********************************
//    #ifdef  W32                                                  //~v5g6R~
        coord.X  =(SHORT)Pcol;					//pos x            //~v022R~
//      coord.Y  =(SHORT)Prow;					//pos y            //~v5fhR~
        coord.Y  =(SHORT)(Prow+Stoplineoffs);					//pos y//~v5fhI~
    	rc16=(APIRET16)!ReadConsoleOutputCharacter(Shconout,       //~v022R~
        								pchStr,	//buff read into   //~v022R~
        								*Pplen,	//read len         //~v022I~
        								coord,	//pos read from    //~v022I~
                                        &len);	//output read      //~v022I~
		*Pplen=len;                                                //~v022I~
		return (UINT)rc16;                                         //~v022I~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
}//uvioreadcharstr
#endif //!XXE		//no actual user                               //~v5g6I~

//*******************************************************
//*VioWrtCharStr(read char+attr and merge char then write)
//*******************************************************
//UINT uviowrtcharstr(PCH pchStr,int Plen,int Prow,int Pcol)       //~v6EoR~
UINT uviowrtcharstr(int Popt,PCH pchStr,int Plen,int Prow,int Pcol)//~v6EoI~
{
//    #ifdef W32                           //win95                 //~v5g6R~
        int pos;                                                   //~v042I~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
//*********************************
//#ifdef DOS                                                       //~v5g6R~
//#else                                                            //~v5g6R~
//    #ifdef  W32                                                  //~v5g6R~
#ifndef XXE                                                        //~v5g6I~
      if (Sw95buffmode)                                            //~v042R~
      {                                                            //~v042I~
#endif	//!XXE                                                     //~v5g6I~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	return 8;                                          //~v042I~
//#ifdef WXE                                                       //~v5g6R~
            UVIO_LINEUPDATE(Prow);                                 //~v570I~
//#endif                                                           //~v5g6R~
//          uvio_setbufflineopt(0,Prow,Popt);                      //~v6EpR~
            uvio_setbufflineopt(0,Prow,Popt,Pcol,Plen);            //~v6EpI~
//          memcpy(&Sw95buffc[pos],pchStr,Plen);                   //~v042I~//~v6BdR~
            memcpy(&Sw95buffc[pos],pchStr,(size_t)Plen);           //~v6BdI~
            return 0;                                              //~v042I~
#ifndef XXE                                                        //~v5g6I~
      }                                                            //~v042I~
      else  //not buff mode                                        //~v042I~
      {                                                            //~v042I~
        coord.X  =(SHORT)Pcol;					//pos x            //~v022R~
//      coord.Y  =(SHORT)Prow;					//pos y            //~v5fhR~
        coord.Y  =(SHORT)(Prow+Stoplineoffs);					//pos y//~v5fhI~
UTRACEP("uviowrtchrstr pos x=%d,y=%d\n",coord.X,coord.Y);          //~v@@@I~
UTRACED("uviowrtcharstr WriteConsoleOutputCharacter",pchStr,Plen); //~v@@@I~
    	return !WriteConsoleOutputCharacter(Shconout,              //~v022R~
        								pchStr,	//buff write from  //~v022I~
        								Plen,	//write len        //~v022I~
        								coord,	//pos write into   //~v022I~
                                        &len);	//len written      //~v022I~
      }                                                            //~v042I~
#endif	//!XXE                                                     //~v5g6I~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
//#endif                                                           //~v5g6R~
}//uviowrtcharstr

//#ifdef  W32                                                      //~v5g6R~
//*******************************************************          //~v043I~
//*uviowrtattrstr(attr string write)                               //~v043I~
//*parm1 :attr WORD table                                          //~v043I~
//*parm2 :word count                                               //~v043I~
//*parm3 :pos row                                                  //~v043I~
//*parm4 :pos col                                                  //~v043I~
//*******************************************************          //~v043I~
UINT uviowrtattrstr(USHORT *Pattr,int Plen,int Prow,int Pcol)      //~v043R~
{                                                                  //~v043I~
    int pos;                                                       //~v043I~
    UINT rc;                                                       //~v043I~
//*********************************                                //~v043I~
 		pos=Pcol+Prow*Sscrwidth;                                   //~v043I~
        if (pos<0 || (pos+Plen)>Sscrsize)                          //~v043I~
         	return 8;                                              //~v043I~
//#ifdef WXE                                                       //~v5g6R~
         UVIO_LINEUPDATE(Prow);                                    //~v570I~
//#endif                                                           //~v5g6R~
//       memcpy(&Sw95buffa[pos],Pattr,Plen*2);                     //~v043R~//~v6BdR~
         memcpy(&Sw95buffa[pos],Pattr,(size_t)Plen*2);             //~v6BdI~
         rc=0;                                                     //~v043I~
    return rc;                                                     //~v043I~
}//uviowrtattrstr                                                  //~v043I~
//#endif                                                           //~v5g6R~
                                                                   //~v043I~
//*******************************************************
//*VioWrtCharStrAtt(support 3 byte attr)
//*******************************************************
//UINT uviowrtcharstratt(PCH pch,int Plen,int Prow,int Pcol,PBYTE pAttr)//~v6EoR~
UINT uviowrtcharstratt(int Popt,PCH pch,int Plen,int Prow,int Pcol,PBYTE pAttr)//~v6EoI~
{
//    #ifdef W32                           //win95                 //~v5g6R~
        UINT        rc;                                            //~v022I~
        int			pos;                                           //~v042I~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
//*********************************
//#ifdef DOS                                                       //~v5g6R~
//#else                                                            //~v5g6R~
//    #ifdef W32                           //win95                 //~v5g6R~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	rc=8;                                              //~v042I~
            else                                                   //~v042I~
            {                                                      //~v042I~
//#ifdef WXE                                                       //~v5g6R~
	 	        UVIO_LINEUPDATE(Prow);                             //~v570I~
//#endif                                                           //~v5g6R~
//          	uvio_setbufflineopt(0,Prow,Popt);                  //~v6EpR~
            	uvio_setbufflineopt(0,Prow,Popt,Pcol,Plen);        //~v6EpI~
//              memcpy(&Sw95buffc[pos],pch,Plen);                  //~v042R~//~v6BdR~
                memcpy(&Sw95buffc[pos],pch,(size_t)Plen);          //~v6BdI~
//              memcpy(&Sw95buffa[pos],uvio_w95getattrtbl((WORD)*pAttr),Plen*2);//~v252R~
                uvio_w95setscrattr(&Sw95buffa[pos],(WORD)*pAttr,Plen*2);//~v252I~
                rc=0;                                              //~v042I~
            }                                                      //~v042I~
		return rc;                                                 //~v022I~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
//#endif                                                           //~v5g6R~
}//uviowrtcharstratt

//*******************************************************
//*VioWrtNAtrr(read char+attr and merge attr then write)
//*******************************************************
UINT uviowrtnattr (PBYTE pAttr,int Plen,int Prow,int Pcol)
{
//    #ifdef W32                           //win95                 //~v5g6R~
        int         pos;                                           //~v042I~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
//*********************************
//    #ifdef W32                           //win95                 //~v5g6R~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	return 8;                                          //~v042I~
//#ifdef WXE                                                       //~v5g6R~
	 	    UVIO_LINEUPDATE(Prow);                                 //~v570I~
//#endif                                                           //~v5g6R~
//          memcpy(&Sw95buffa[pos],uvio_w95getattrtbl((WORD)*pAttr),Plen*2);//~v252R~
            uvio_w95setscrattr(&Sw95buffa[pos],(WORD)*pAttr,Plen*2);//~v252I~
            return 0;                                              //~v042I~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
}//uviowrtnattr

//*******************************************************
//*VioWrtNCell(setup buff and write cell(char+attr))
//*******************************************************
//UINT uviowrtncell(PBYTE pCell,int Plen,int Prow,int Pcol)        //~v6EqR~
UINT uviowrtncell(int Popt,PBYTE pCell,int Plen,int Prow,int Pcol) //~v6EqI~
{
//    #ifdef W32                           //win95                 //~v5g6R~
#ifndef XXE                                                        //~v5g6I~
		DWORD         len;                                         //~v022R~
		COORD 		coordpos;                                      //~v022R~
#endif                                                             //~v5g6I~
        UINT        rc;                                            //~v022I~
        int         pos;                                           //~v042I~
        int         col,lineoptlen;                                //~v6EqI~
        int row,reslen;                                            //~v5kyI~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
//*********************************
//    #ifdef W32                           //win95                 //~v5g6R~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	rc=8;                                              //~v042I~
			else                                                   //~v042I~
            {                                                      //~v042I~
//#ifdef WXE                                                       //~v5g6R~
//   	    	UVIO_LINEUPDATE(Prow);                             //~v5kyR~
			  col=Pcol;                                            //~v6EqI~
              lineoptlen=min(Plen,Sscrwidth-col);                  //~v6EqI~
              for (row=Prow,reslen=Plen;reslen>0;row++,reslen-=Sscrwidth)//~v5kyI~
              {                                                    //~v6EqI~
     	    	UVIO_LINEUPDATE(row);                              //~v5kyI~
	            uvio_setbufflineopt(Popt,row,Popt,col,lineoptlen); //~v6EqI~
                col=0;                                             //~v6EqI~
                lineoptlen=min(reslen,Sscrwidth);                  //~v6EqI~
              }                                                    //~v6EqI~
//#endif                                                           //~v5g6R~
//          	memset(&Sw95buffc[pos],*pCell,Plen);               //~v042I~//~v6BdR~
            	memset(&Sw95buffc[pos],*pCell,(size_t)Plen);       //~v6BdI~
//          	memcpy(&Sw95buffa[pos],                            //~v252R~
//  					uvio_w95getattrtbl((WORD)*(pCell+1)),      //~v252R~
//  					Plen*sizeof(USHORT));                      //~v252R~
                uvio_w95setscrattr(&Sw95buffa[pos],                //~v252I~
    					           (WORD)*(pCell+1),               //~v252I~
//                                  Plen*sizeof(USHORT));          //~v252I~//~v6BdR~
                                    Plen*(int)sizeof(USHORT));     //~v6BdI~
            	rc=0;                                              //~v042I~
            }                                                      //~v042I~
		return rc;                                                 //~v022I~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
}//uviowrtncell

//*******************************************************
//*VioWrtNChar(read char+attr and merge same char then write)
//*******************************************************
UINT uviowrtnchar(PCH pchChar,int Plen,int Prow,int Pcol)
{
//    #ifdef W32                           //win95                 //~v5g6R~
#ifndef XXE                                                        //~v5g6I~
		DWORD        len;                                          //~v022R~
		COORD 		coordpos;                                      //~v022R~
#endif                                                             //~v5g6I~
        int         pos;                                           //~v042I~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
//*********************************
//    #ifdef W32                           //win95                 //~v5g6R~
            pos=Pcol+Prow*Sscrwidth;                               //~v042I~
            if (pos<0 || (pos+Plen)>Sscrsize)                      //~v042R~
            	return 8;                                          //~v042I~
//#ifdef WXE                                                       //~v5g6R~
 	    	UVIO_LINEUPDATE(Prow);                                 //~v570I~
//#endif                                                           //~v5g6R~
//      	memset(&Sw95buffc[pos],*pchChar,Plen);                 //~v042I~//~v6BdR~
        	memset(&Sw95buffc[pos],*pchChar,(size_t)Plen);         //~v6BdI~
	       	return 0;                                              //~v042R~
//    #else                                                        //~v5g6R~
//    #endif                                                       //~v5g6R~
}//uviowrtnchar                                                 //~5A01R~
//#ifdef W32                                                       //~v5g6R~
//*******************************************************          //~v142I~
//*uvio_w95writecell                                               //~v142I~
//*		write by window cell(CHAR_INFO)                            //~v142I~
//*parm1:parm type                                                 //~v142I~
//*				1:buff(str1=char,str2=USHORT attr str)             //~v144R~
//*				2:cell(str1=char+attr byte)                        //~v142I~
//*				3:char and USHORT attr(str1=cha,str2=USHORT attr str)//~v144R~
//*				4:char and a attr byte(str1=cha,str2=attr byte)    //~v142I~
//*				5:char and 2 USHORT attr string(str1=cha,str2=USHORT attr str)//~v144I~
//*				6:same as 1 except parm4 is height+width(box write)//~v149I~
//*parm2:output row                                                //~v142I~
//*parm3:output column                                             //~v142I~
//*parm4:char/cell len                                             //~v144R~
//*         for type=5,len=1st halflen+total len                   //~v145R~
//*         for type=6,len=box height+box width                    //~v149I~
//*parm5:str1                                                      //~v142I~
//*parm6:str2                                                      //~v142I~
//*ret  :rc                                                        //~v142I~
//*******************************************************          //~v142I~
int uvio_w95writecell(int Ptype,int Prow,int Pcol,int Plen,void *Pstr1,void *Pstr2)//~v142R~
{                                                                  //~v142I~
	return 0;   //never called                                     //~v570I~
}//uvio_w95writecell                                               //~v142I~
//*******************************************************          //~v307I~
//*uvio_w95resetconsole                                            //~v307I~
//*  for test redrau unavaile bug;reset console                    //~v307I~
//*return:rc                                                       //~v307I~
//*******************************************************          //~v307I~
void uvio_w95resetconsole(void)                                    //~v307I~
{                                                                  //~v307I~
//*********************************                                //~v307I~
//*reset console-->created another dosprompt frame!!               //~v307I~
//    if (!FreeConsole())                                          //~v307R~
//        uerrapi0("FreeConsole",GetLastError());                  //~v307R~
//    if (!AllocConsole())                                         //~v307R~
//        uerrapi0("AllocConsole",GetLastError());                 //~v307R~
//    Shconout=ugetstdhandle(STD_OUTPUT_HANDLE);                   //~v307R~
//    uvio2_init(Shconout);   //pass to uvio2                      //~v307R~
//    ukbd_w95init();                                              //~v307R~
//*pritf(x07);  caused redraw                                      //~v307I~
//    if (!SetConsoleActiveScreenBuffer(Shconout))                 //~v307R~
//        uerrapi0x("SetConsoleActiveScreenBuffer",GetLastError());//~v307R~
//    usetconsolemode(1,ENABLE_PROCESSED_OUTPUT);   //stdout console mode//~v307R~
//try another buffer                                               //~v307I~
//    CloseHandle(Shconout);                                       //~v307R~
//    Shconout=CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,//~v307R~
//                 FILE_SHARE_READ | FILE_SHARE_WRITE,             //~v307R~
//                 NULL,                                           //~v307R~
//                 CONSOLE_TEXTMODE_BUFFER,                        //~v307R~
//                 NULL);                                          //~v307R~
//    if (Shconout==INVALID_HANDLE_VALUE)                          //~v307R~
//        uerrapi0x("CreateConsoleScreenBuffer",GetLastError());   //~v307R~
//    if (!SetStdHandle(STD_OUTPUT_HANDLE,Shconout))               //~v307R~
//        uerrapi0x("SetStdHandle",GetLastError());                //~v307R~
//    if (SetConsoleActiveScreenBuffer(Shconout)==FALSE)           //~v307R~
//        uerrapi0x("SetActiveScreenBuffer",GetLastError());       //~v307R~
//    usetconsolemode(1,0);   //stdout console mode                //~v307R~
//    uvio2_init(Shconout);   //pass to uvio2                      //~v307R~
//try re-set buff inf                                              //~v307I~
//    int    ii;                                                   //~v307R~
//    int      rc16;                                               //~v307R~
//    CONSOLE_SCREEN_BUFFER_INFO csbi;                             //~v307R~
////*********************************                              //~v307R~
//    rc16=0;                                                      //~v307R~
//    GetConsoleScreenBufferInfo(Shconout,&csbi);                  //~v307R~
//    if (!SetConsoleScreenBufferSize(Shconout,csbi.dwSize))       //~v307R~
//        rc16=2;             //setconbuffi err                    //~v307R~
//    for (ii=0;ii<rc16;ii++)                                      //~v307R~
//        ubell();                                                 //~v307R~
//no buffering stdout                                              //~v307I~
//  setvbuf(stdout,NULL,_IONBF,0);                                 //~v307R~
//close and create new buff                                        //~v307I~
    return;                                                        //~v307I~
}//uvio_w95resetconsole                                            //~v307I~
//#endif                                                           //~v5g6R~
//uvio2 *********************************************************  //~v5g6R~
//CID://+v5fhR~:                                                   //~v5fhR~
//*************************************************************
//v5fh:050125 (W32)window should be at current last of consolebuff //~v5fhI~
//v570:020824 wxe support                                          //~v570I~
//v252:990626 (Win):for redirect;Once create console buff and then get inf befre destroy//~v252I~
//v156:980126 ugetconhwnd:get console appl HWND                    //~v156I~
//v151:980119 (BUG:DOS/GCC)video buff direct write determined by not dbcs env//~v151M~
//            but video mode.video buff chk by int 10 ah=FE        //~v151M~
//            (none is displayed under os2 dos session when changed chev us)//~v151M~
//v056:970119:for int10 ah=0e(tty write),not needed INT10X,INT10 is sufficiant.//~v056I~
//v053:970406:gcc version(control by DPMI)                         //~v053I~
//            -short size ont equal int size                       //~v053I~
//v044:961106:too large for XEDOS,split uvio.c to uvio2.c          //~v044I~
//v043:961104:(W95)write attr string function support              //~v043I~
//v042:961102:(W95)write all line to screen by one api issue for performance//~v042I~
//v034:961008:VC support(identify by (_MSC_VER>=800))              //~v034I~
//           .scroll function not usefull for clear screen         //~v034R~
//            (dest position must not negative,so need twice half scroll)//~v034I~
//           .WriteConsoleOutput is not effective when full-screen mode//~v034I~
//            Output can be seen after when change active screen buffer//~v034I~
//            to another and returned.                             //~v034I~
//            (so use WriteConsoleOutputCharacter and WriteConsoleOutputAttribute)//~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*ugetstdhandle                                                   //~v044I~
//*uviogetcurtype/uviogetcurpos                                    //~v044R~
//*uviosetcurtype/uviosetcurpos                                    //~v044R~
//*uviowrttty                                                      //~v043I~
//*uviogetstate/uviosetsate
//*uvioscrolldn(back)/uvioscrollup(forward)                     //~5222I~
//*************************************************************
//v015:960211:(BUG)uviowrttty advance char ptr for DOS          //~6212I~
//951001:malloc uvio work at init(uvio_init,uvio_term)          //~5A01I~
//950930:malloc/calloc rc chk for dos                           //~5930I~
//*950513 write direct to b800 when english display mode 3      //~5513I~
//*       (int10 ax=1302 cause scroll up when write to row 25 col 80)//~5513I~
//*950222 scroll down/up                                        //~5222R~
//*941221 int 10 ax=1302 for english mode not but 1320          //~5222I~
//*******************************************************
                                                                   //~v022I~
//*******************************************************
//*VioGetCurPos
//*******************************************************
UINT uviogetcurpos (int *Pprow,int *Ppcol)
{
        return (UINT)wxe_getcurpos(Pprow,Ppcol);                   //~v570I~
}//uviogetcurpos

//*******************************************************
//*VioSetCurPos
//*******************************************************
UINT uviosetcurpos (int Prow,int Pcol)
{
        return (UINT)wxe_setcurpos(Prow,Pcol);                     //~v570I~
}//uviosetcurpos                                                   //~v022R~

//*******************************************************
//*VioGetCurType
//*******************************************************
UINT uviogetcurtype(PVIOCURSORINFO pvioCursorInfo)
{
        return (UINT)wxe_getcurtype(pvioCursorInfo);               //~v570R~
}//uviogetcurtype

//*******************************************************
//*VioSetCurType
//*******************************************************
UINT uviosetcurtype (PVIOCURSORINFO pvioCursorInfo)
{
        return (UINT)wxe_setcurtype(pvioCursorInfo);               //~v570R~
}//uviosetcurtype
//*******************************************************
//*uviogetstate
//* for DOS,supprt pallette reg and overscan reg
//*parm:req block addr
//*******************************************************
UINT uviogetstate(PVOID Ppreqblk)
{
    	return (UINT)wxe_uviogetstate(Ppreqblk);                   //~v570I~
}//uvigetstate
                                                                //~5222I~
//*******************************************************
//*uviosetstate
//* for DOS,supprt pallette reg and overscan reg
//*parm:req block addr
//*******************************************************
UINT uviosetstate(PVOID Ppreqblk)
{
    	return (UINT)wxe_uviosetstate(Ppreqblk);                   //~v570I~
}//uviosetstate                                                 //~5222R~
