//*CID://+v@@@R~:                             update#=  542;       //~v@@@R~
//*************************************************************
//v@@@:081006 acb sub                                              //~v@@@I~
//*************************************************************
//*xeacb:ANSI color escape sequence Browser
//* read esc seq file(1b[aa;bb,ffm) (output from source-highlight by outlang=esc)
//* and write colour info correspond to the source file offset
//*      color file is binary file TOL is line ength
//*               ll(4)+attrbyte*0x0a  attrbyte=bg(4bit)+fg(4bit)
//*      style file is ascii file
//*               style byte+0x0d0a    atyle byte is at that point only
//*               0:normal,'1':bold ...
//* browse to scree if output file is not specified
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>

//**********
#ifdef W32                                                         //~v70rI~
    #include <io.h>                                                //~8215I~
	#include <windows.h>                                           //~v70rI~
#else                                                              //~8215I~
    #include <unistd.h>                                            //~8220I~
	#include <wchar.h>                                             //~8215I~
#endif                                                             //~v70rI~
//**********
#include <ulib.h>
#include <uque.h>
#include <uerr.h>
#include <ufile.h>
#include <ualloc.h>
#include <ustring.h>
#include <utrace.h>
#include <udbcschk.h>
#include <uedit.h>                                                 //~v70rI~
#include <utf.h>                                                   //~v70rI~

#include "xe.h"
#include "xescr.h"                                                 //~8217I~
#include "xefile.h"                                                //~8217I~
#include "xeacb.h"                                                 //~8217I~
#include "xesyn2.h"                                                //~8222M~
//*************************************************************
#define RBUFFSZ  32760                                             //~8215R~
//*************************************************************
#define CH_ESC1     0x1b
#define CH_ESC2     '['
#define CH_DELM     ';'
#define CH_RESET    'm'
#define CH_TABREP   ' '
#define CH_TABSKIP  ' '
#define NO_STYLE    '0'
#define DEFAULT_FG       0x07      //whilte on black
#define DEFAULT_BG       0         //whilte on black
#define COLOR_INTENSIVE  0x08      //highlight color bit by BOLD   //~8217I~

#define DEFAULT_TAB_SKIP 8
#define MAX_TAB_SKIP     20                                        //~v70rI~
#define GETTABSKIPCTR(tabcharoffset) \
    	(Stabskipctr-(tabcharoffset)%Stabskipctr-1)
#define GETWIDTH21(pchof2,pchof1) ((int)((ULONG)pchof2-(ULONG)pchof1)/CHOFSZ)//~v70rR~
//*************************************************************
typedef struct _SHLINE {
						UQUEE           SHLqe;
                        int             SHLlineno;
                        int             SHLlen;  	//utflen       //~v70rR~
                        int             SHLwidth;                  //~v70rI~
						char           *SHLptext;
						char           *SHLpcolor;
						char           *SHLpdbcs;                  //~v70rI~
						PCHOFTYPE       SHLpchof;                  //~v70rR~
                      } SHLINE,*PSHLINE;
#define SHLINESZ   sizeof(SHLINE)
                                                                   //~8215I~
#ifdef LNX                                                         //~8215I~
    #ifdef CURSESW                                                 //~8215I~
        #define CHTYPE cchar_t                                     //~8215I~
    #else                                                          //~8215I~
        #define CHTYPE chtype                                      //~8215I~
    #endif                                                         //~8215I~
#endif                                                             //~8215I~
//*************************************************************
static int Sopt;                                                   //~v70rM~
#define OPT_STYLEOUT        0x01                                   //~v70rM~
#define OPT_GXE             0x02                                   //~v70rM~
#define OPT_LNX             0x04                                   //~v70rM~
#define OPT_XE              0x08                                   //~v70rM~
#define OPT_WXE             0x10                                   //~v70rM~
#define OPT_SCRTEST         0x20                                   //~v70rM~
#define OPT_USERMAP         0x40                                   //~v70rM~
#define OPT_DBCS            0x80   //Jspanese:SJIS(Win) or EUC(Linux)//~v70rM~
#define OPT_DBCSEUC       0x0100   //Jspanese:EUC(Linux)           //~v70rM~
#define OPT_USERMAP_RB    0x0200   //swap red and blue             //~v70rM~
#define OPT_USERMAP_BW    0x0400   //swap brack and white          //~v70rM~
#define OPT_UTF8          0x0800   //utf8 file                     //~v70rM~
#define OPT_IDX           0x1000   //index file output             //~8216I~
#define OPT_FROMXE        0x2000   //req from xe(weite complete record on errfile)//~8217I~
#define OPT_COMLETE       0x4000   //req from xe(weite complete record on errfile)//~8217I~
#define OPT_HIGHBIT       0x8000   //color 0x08(FG) bit on by BOLD //~8217I~
                                                                   //~v70rM~
static  int Scolorfileopt;
static  int Suerrmsgopt=0;                                         //~8220R~
static  int Sdeffg=DEFAULT_FG,Sdefbg=DEFAULT_BG,Sfg,Sbg,Sdefcolor;
static  int Scsrposx,Scsrposy;
static  int Stabpadchar=CH_TABSKIP,Stabrepchar=CH_TABREP;
static  char *Spbuffinp;
static  char *Spbuffstylecolor;                                    //~8217I~
static  UCHAR *Spbuffcolor,*Spbufftext;                            //~8215R~
static  char *Spbuffstyle;
static  char Sdbcstwk[MAXCOLUMN*2];
static  FILE *Sfhinp,*Sfhoutc,*Sfhouts,*Sfhidx;                    //~8216R~
static  char *Sinpfnm;
static  int Slineno;                                               //~8220R~
static int Sscrlineno,Sscrwidth,Sscrheight;
static UQUEH  Sshlqh;		//line data q
//*********
static  UCHAR Sdefpalette[SHMAX_COLOR]; //default color reg assign tbl for pallete no//~8216R~
static  UCHAR Soldattrc;          //for setmode at return
static  UCHAR Sscrstatus;
static  char *Sexpandwkt,*Sexpandwkc;
static  void *Sviodata;                                            //~v70rR~
static  int Stabskipctr=DEFAULT_TAB_SKIP;
#ifdef W32                                                         //~8215I~
    static int Stoplineoffs;                                       //~8215R~
#endif                                                             //~8215I~
#ifdef UTF8SUPP	//Windows is always UTF8SUPP                       //~8220I~
	static  char *Spbuffdbcs;                                      //~8220I~
	static  PCHOFTYPE Spbuffchof;                                  //~8220I~
	#ifdef LNX                                                     //~8220I~
    	static  CHTYPE *Sviochtype;      //widichar ch work        //~8220R~
	#endif                                                         //~8220I~
	static  PCHOFTYPE Sexpandwkchof,Sviochof;                      //~8220I~
	static  char *Sviodbcs;                                        //~8220I~
	static  void *Svioattr;                                        //~8220I~
#endif                                                             //~8220I~
//*************************************************************
UEXITFUNC uerrexitcbfunc;                                          //~8216I~
void help(void);
void parmproc(int Pparmc,char *Pparmp[]);
void fileproc(void);
int getinput(void);
int lineproc(char *Pbuffinp,int Pleninp,char *Pbuffoutt,char *Pbuffoutc,char *Pbuffouts,int *Pplenout);
int escchk(char *Pinp,char *Peol,char **Pinpnext,int *Ppfg,int *Ppbg,int *Ppstyle);
void optionerr(char *Ptype,char* Pvalue);
void errmemshortage(char *Pcmt,int Plen);                          //~8216R~
PSHLINE allocshl(char *Pptext,char *Ppcolor,int Plen,PCHOFTYPE Ppchof,int Pwidth);//~v70rI~
int savescrdata(int Popt,char *Pptext,char *Ppcolor,char *Ppstyle,int Plen,int Pwidth);//~v70rR~
#define  SCDO_UTF8    0x01                                         //~v70rR~
int utfsavescrdata(int Popt,char *Pptext,char *Ppcolor,char *Ppstyle,int Plen,int Pwidth);//~v70rR~
int acbinitscr(void);                                              //~8215R~
void acbsetdbcstbl(char *Ppdata,char *Ppdbcs,int Plen);            //~8215R~
int writecolorinfofile(int Popt,char *Ppcolor,int Plen);
int utfshiftcolortbl(char *Ppcolortbl,int Plen,int *Ppwidth);      //~v70rR~
int writeindex(int Popt,int Plen);                                 //~8216I~
void errnullopd(char Popt);                                        //~8217I~
void errfilecheck(char *Pfnmerr);                                  //~8217I~
//*************************************************************
//*parm1:option
//*parm2:read pipe fd number
//*parm3:write pipe fd number
//*************************************************************
int xeshms_acb(int parmc,UCHAR *parmp[])                           //~v@@@R~
{
	int ii,len;
//**********************
	Scolorfileopt|=SIGN_HEAD_FLAG_LE;
    for (ii=0;ii<SHMAX_COLOR;ii++)                                 //~8216R~
		Sdefpalette[ii]=ii;
#ifdef LNX
    if (udbcschkcp())
    {
        Sopt|=OPT_DBCS;
    	if (Gudbcschk_flag & UDBCSCHK_EUC)
	        Sopt|=OPT_DBCSEUC;
    }
#else
    if (udbcschkcp())
        Sopt|=OPT_DBCS;
#endif
	parmproc(parmc,parmp);
#ifdef UTF8SUPP                                                    //~8220I~
    if (Sopt & OPT_UTF8)                                           //~v70rR~
    {                                                              //~v70rI~
        utf_init(UTFIO_FORCE);                                     //~v70rI~
        if (!(Gulibutfmode & GULIBUTFENV)) //no env                //~v70rI~
        {                                                          //~v70rI~
            if (Sopt & OPT_DBCS)                                   //~v70rI~
                Gudbcschk_flag|=UDBCSCHK_UTF8|UDBCSCHK_UTF8J;      //~v70rI~
            else                                                   //~v70rI~
                Gudbcschk_flag|=UDBCSCHK_UTF8|UDBCSCHK_UTF8E;      //~v70rI~
        }                                                          //~v70rI~
    }                                                              //~v70rI~
#endif                                                             //~8220I~
//*buff init
    len=RBUFFSZ*4;
    Spbuffinp=umalloc((UINT)len);
    if (!Spbuffinp)
    	errmemshortage("text read buff",len);                      //~8216R~
	Spbufftext=Spbuffinp+RBUFFSZ*1;
	Spbuffcolor=Spbuffinp+RBUFFSZ*2;
	Spbuffstyle=Spbuffinp+RBUFFSZ*3;
	    len=RBUFFSZ*2;                                             //~8217I~
    	Spbuffstylecolor=umalloc((UINT)len);                       //~8217I~
    	if (!Spbuffstylecolor)                                     //~8217I~
    		errmemshortage("style+color output buff",len);         //~8217I~
#ifdef UTF8SUPP                                                    //~8220I~
    if (Sopt & OPT_UTF8)                                           //~v70rI~
    {                                                              //~v70rI~
    	len=RBUFFSZ*(1+CHOFSZ)+CHOFSZ; //dbcs+chof                 //~v70rR~
    	Spbuffdbcs=umalloc((UINT)len);                             //~v70rR~
    	if (!Spbuffdbcs)                                           //~v70rI~
    		errmemshortage("utf8 buff",len);                       //~8216R~
		Spbuffchof=(PCHOFTYPE)(ULONG)(Spbuffdbcs+RBUFFSZ);         //~v70rR~
    }                                                              //~v70rI~
#endif                                                             //~8220I~
//*                                                                //~v70rI~
    if (Sopt & OPT_STYLEOUT)
	    fprintf(Sfhouts,"%s\n",SIGN_HEAD);
		writecolorinfofile(1/*write Header*/,0,0);
	fileproc();
    fclose(Sfhinp);
UTRACEP("fclose inp\n");                                           //~8224I~
    if (Sopt & OPT_STYLEOUT)
    {
	    fprintf(Sfhouts,"%s\n",SIGN_TAIL);
	    fclose(Sfhouts);
    }
		writecolorinfofile(2/*write Tail*/,0,0);
    	fclose(Sfhoutc);
		Sopt|=OPT_COMLETE;                                         //~8217I~
    	uerrmsg("%s",0,                                            //~v@@@R~
             SIGN_COMPLETED);	//tell to xe                       //~8217I~
	return 0;
}//main
//**********************************************************************
//* main process
//**********************************************************************
void fileproc(void)
{
    int len,outlen;
//*********
	Slineno=0;
    Sfg=Sdeffg;     //initial default fg color
    Sbg=Sdefbg;
	while((len=getinput())>=0)     //until eof
 	{
        if (len>0)
        {
            lineproc(Spbuffinp,len,Spbufftext,Spbuffcolor,Spbuffstyle,&outlen);
            if (outlen)
            {
                writecolorinfofile(0/*caseno*/,Spbuffcolor,outlen);//~v70rR~
                if (Sopt & OPT_STYLEOUT)
                    fwrite(Spbuffstyle,1,(UINT)outlen,Sfhouts);   //color
            }
        }
        else
            outlen=0;
        if (!outlen)
        	writecolorinfofile(0/*caseno*/,0/*colortbl*/,0/*len*/);//~v70rR~
    	if (!(Sopt & OPT_SCRTEST))
        {
			if (Sopt & OPT_STYLEOUT)
	        	fwrite("\n",1,1,Sfhouts);	//write EOL
        }
	}//until eof
	return;
}//fileproc
//**********************************************************************
//* esc.outlang
//      extension "txt"
//
//      styletemplate "\x1b[$stylem$text\x1b[m"
//      styleseparator ";"
//
//      bold "01$style"
//      underline "04$style"
//      italics "$style"
//      color "$style"
//
//
//      colormap
//      "green" "32"
//      "red" "31"
//      "darkred" "31"
//      "blue" "34"
//      "brown" "31"
//      "pink" "35"
//      "yellow" "33"
//      "cyan" "36"
//      "purple" "35"
//      "orange" "31"
//      "brightorange" "31"
//      "brightgreen" "32"
//      "darkgreen" "32"
//      "black" "30"
//      "teal" "37"
//      "gray" "37"
//      "darkblue" "34"
//      default "30;"
//      end
//
//      # Decorate text with terminal control sequences (escape sequences).
//      # To set the attribute/fg_color/bg_color we need to print
//      #   "\033[AA;FF;BBm"
//      # where AA is one of these:
//      # 00=none 01=bold 04=underscore 05=blink 07=reverse 08=concealed,
//      # FF is one of these:
//      # 30=black 31=red 32=green 33=yellow 34=blue 35=magenta 36=cyan 37=white
//      # BB is one of these:
//      # 40=black 41=red 42=green 43=yellow 44=blue 45=magenta 46=cyan 47=white
//      #
//      # Any of AA,FF,BB may be omited.
//      #
//      # To reset do default color/attribute we need to print
//      # "\033[m"
//*sample output
//      0x1b01;34m#include0x1b[m 0x1b[31m<string.h>0x1b[m     0x1b[31m//0x1b[m0x1b[31m~7112I~0x1b[m//~8304R~
//      0x1b31m//0x1b[m0x1b[31m*************************************************************    //~7112I~0x1b[m//~8304R~
//*output color: bg(4bit)+fg(4bit)
//        style: "0":none,"1":bold,"4":underline
//**********************************************************************
int lineproc(char *Pbuffinp,int Pleninp,char *Pbuffoutt,char *Pbuffoutc,char *Pbuffouts,int *Ppoutlen)
{
	char *pci,*pcoc,*pcos,*pcn,*pce,*nextpci,*pcot;
	int reslen,len,color,nextstyle,nextfg,nextbg,fg,bg;            //~8217R~
    int eolsw;                                                     //~8215R~
static int Sstyle=SHSTYLE_NORMAL;                                  //~8217I~
//*********
    pci=Pbuffinp;
    pce=pci+Pleninp;
    pcot=Pbuffoutt;
    pcoc=Pbuffoutc;
    pcos=Pbuffouts;
	fg=Sfg;
	bg=Sbg;
    nextstyle=Sstyle;		//cont over line                       //~8217R~
    for (;;)
    {
	    reslen=(int)((ULONG)pce-(ULONG)pci);
        pcn=pci;
        nextfg=fg;
        nextbg=bg;
        for (;;)
        {
            eolsw=1;
		    len=(int)((ULONG)pce-(ULONG)pcn);
    		pcn=memchr(pcn,CH_ESC1,(UINT)len);
        	if (!pcn)
            	break;
            eolsw=0;
	        if (escchk(pcn,pce,&nextpci,&nextfg,&nextbg,&nextstyle))//color esc found
            	break;
            pcn++;         //esc is not for color

        }
        if (Sopt & OPT_USERMAP)
        	color=(Sdefpalette[bg]<<4)|Sdefpalette[fg];
        else
	        color=(bg <<4) | (fg);
        if (Sopt & OPT_HIGHBIT)                                    //~8217I~
            if (Sstyle==SHSTYLE_BOLD)                              //~8217R~
                color|=COLOR_INTENSIVE;           //highlight color bit by BOLD//~8217I~
        if (eolsw)
        	break;
        len=(int)((ULONG)pcn-(ULONG)pci);
	    memset(pcoc,color,(UINT)len);                              //~8215R~
        pcoc+=len;
        fg=nextfg;
        bg=nextbg;

#ifdef AAA                                                         //~8223I~
        if (len>0)                                                 //~8217R~
        {                                                          //~8217R~
            memset(pcos,SHSTYLE_CONT,(UINT)(len-1));               //~8217R~
            pcos+=len-1;                                           //~8217R~
        }                                                          //~8217R~
        if (pcos==Pbuffouts)	//top of line                      //~8217I~
            *pcos++=nextstyle;                                     //~8217I~
        else                                                       //~8217I~
        if (nextstyle==Sstyle)                                     //~8217R~
            *pcos++=SHSTYLE_CONT;                                  //~8217R~
        else                                                       //~8217R~
            *pcos++=nextstyle;                                     //~8217R~
#else 		//fill all postion                                     //~8223I~
        memset(pcos,Sstyle,(UINT)len);                             //~8223I~
        pcos+=len;                                                 //~8223I~
#endif                                                             //~8223I~
        Sstyle=nextstyle;                                          //~8217R~
        pci=nextpci;
    }
    memset(pcoc,color,(UINT)reslen);                               //~8215R~
    pcoc+=reslen;
    *Ppoutlen=(int)((ULONG)pcoc-(ULONG)Pbuffoutc);
    if (reslen>0)                                                  //~8217R~
#ifdef AAA                                                         //~8223I~
        memset(pcos,SHSTYLE_CONT,(UINT)(reslen-1));                //~8217R~
#else 		//fill all postion                                     //~8223I~
        memset(pcos,Sstyle,(UINT)reslen);                          //~8223I~
#endif                                                             //~8223I~
	Sfg=fg;
	Sbg=bg;
	return 0;
}//lineproc
//**********************************************************************
//*chk esc str
//*ANSI format
//* ESC[#(;#)m    multiple seperated by ; and end with m
//*  0,1,4,5,7,8  style(source-highkigh is 00,01...)
//*    ( 1(Bold) means highlight by ansi)
//*  30,31,...37  fg
//*  40,31,...37  bg
//* rc:1:color esc detected,0:not valid color esc
//**********************************************************************
int escchk(char *Pinp,char *Peol,char **Pinpnext,int *Ppfg,int *Ppbg,int *Ppstyle)
{
	char *pc;
	int fg,bg,style,value,ch,valuesw=0;                            //~8217R~
//*********
	pc=Pinp;
    fg=*Ppfg;
	bg=*Ppbg;
    style=*Ppstyle;     //continue until reset                     //~8217I~
    pc++;
    if (pc>=Peol)
        return 0;
    if (*pc!=CH_ESC2)  	//[ of 0x1b[
        return 0;
    pc++;
    value=0;
    for (;;pc++)
    {
    	if (pc>=Peol)
        	return 0;
    	ch=*pc;
        if (ch==CH_RESET
        ||  ch==CH_DELM)	//m
        {
            if (value<10)
                style=value;
            else
            if (value>=30 && value<=37)
                fg=value-30;
            else
            if (value>=40 && value<=47)
                bg=value-40;
            else
                return 0;
            if (ch==CH_DELM)
            {
                value=0;
                continue;
            }
        	pc++;
            if (valuesw)	//any parm
            	break;
            fg=Sdeffg;	//reset to default
            bg=Sdefbg;
        	break;
        }
        if (!isdigit(ch))	//m
        	return 0;
        value=value*10+(ch & 0x0f);
        valuesw=1;
    }
    *Pinpnext=pc;
    *Ppfg=fg;
    *Ppbg=bg;
    style|='0';	//"0":normal
    *Ppstyle=style;
    return 1;   //valid color esc
}//escchk
//**********************************************************************
//* get 1 line
//* ret:line length,-1 if eof
//**********************************************************************
int getinput(void)
{
	int len;
//****************
    Slineno++;                                                     //~8215I~
UTRACEP("getinput req lineno=%d\n",Slineno);                       //~8224R~
	if (!fgets(Spbuffinp,RBUFFSZ,Sfhinp))	//fgets set null at eol
    {                                                              //~8215I~
UTRACEP("getinput fail errno=%d\n",errno);                         //~8224R~
		if (ferror(Sfhinp))
			uerrexit("Input read error",0);                        //~8217R~
		else
        if (Slineno==1)                                            //~8217I~
			uerrexit("Input is NULL",0);                           //~8217R~
        else                                                       //~8217I~
			return -1;
    }                                                              //~8215I~
UTRACEP("getinput ok lineno=%d\n",Slineno);                        //~8224R~
	len=(int)strlen(Spbuffinp);			//read len
	if (*(Spbuffinp+len-1)!='\n')
    {
      	if (len>=RBUFFSZ-1)
			uerrmsg("\n????? Input has too long record over %d byte at line %d",0,
					RBUFFSZ-1,Slineno);
    }
    else
        len--;
	if (len>1 && *(Spbuffinp+len-1)==0x0d) 	//pc/mac file
    	len--;
	*(Spbuffinp+len)=0;
UTRACED("getinput",Spbuffinp,len);                                 //~8228R~
	return len;
}//end of getinput
//**********************************************************************
//* write color info file
//* utf consideration is output to screen case only                //~v70rI~
//**********************************************************************
int writecolorinfofile(int Popt,char *Ppcolor,int Plen)
{
	int rc=-1,len,opt=0,width=0,ii;                                //~8217R~
    char *pcc,*pcs,*pcsc,*pcsc0;                                   //~8217R~
    char hdrwk[sizeof(SIGN_HEAD)+4];
//***************
	switch(Popt & 0x0f)
    {
    case 0:
        pcsc0=Spbuffstylecolor;                                    //~8217I~
UTRACED("color",Ppcolor,Plen);                                     //~8217I~
UTRACED("style",Spbuffstyle,Plen);                                 //~8217I~
        for (pcc=Ppcolor,pcs=Spbuffstyle,pcsc=pcsc0,ii=0;ii<Plen;ii++)//~8217I~
        {                                                          //~8217I~
        	*pcsc++=*pcs++;                                        //~8217R~
        	*pcsc++=*pcc++;                                        //~8217R~
        }                                                          //~8217I~
        len=Plen*2+1/*lastLF*/;                                    //~8218R~
UTRACED("style+color",pcsc0,len);                                  //~8217I~
    	rc=fwrite(&len,1,sizeof(int),Sfhoutc);                     //~8217R~
		rc+=fwrite(pcsc0,1,(UINT)len-1,Sfhoutc);   //color         //~8218R~
    	rc+=fwrite("\n",1,1,Sfhoutc);               //for editor
    	if ((Sopt & OPT_IDX))                                      //~8216I~
        	writeindex(0/*data*/,sizeof(int)+len);                 //~8218R~
    	break;
    case 1:	//header
    	len=sizeof(SIGN_HEAD)-1;
        memcpy(hdrwk,SIGN_HEAD,(UINT)len);
        memcpy(hdrwk+SIGN_HEAD_VER,SIGN_VERSION,2);
        *(hdrwk+SIGN_HEAD_FLAG)=Scolorfileopt;
        *(hdrwk+SIGN_HEAD_LENSZ)=sizeof(int);
    	rc=fwrite(&len,1,sizeof(int),Sfhoutc);
	    rc+=fwrite(hdrwk,1,(UINT)len,Sfhoutc);
    	rc+=fwrite("\n",1,1,Sfhoutc);               //for editor
    	if ((Sopt & OPT_IDX))                                      //~8216I~
        	writeindex(1/*start*/,0);                              //~8216R~
    	break;
    case 2:	//tail
    	if ((Sopt & OPT_IDX))                                      //~8216I~
        	writeindex(2/*close*/,0);                              //~8216R~
    	len=sizeof(SIGN_TAIL)-1;
    	rc=fwrite(&len,1,sizeof(int),Sfhoutc);
	    rc+=fwrite(SIGN_TAIL,1,(UINT)len,Sfhoutc);
    	rc+=fwrite("\n",1,1,Sfhoutc);               //for editor
    	break;
    }
    return rc;
}//writecolorinfofile
//**********************************************************************//~8216I~
//* write color info index file                                    //~8217R~
//**********************************************************************//~8216I~
int writeindex(int Popt,int Plen)                                  //~8216I~
{                                                                  //~8216I~
static	SHINDEX Sidxrec;                                           //~8216I~
static  PSHINDEX Spidxbuff;                                        //~8216I~
static  int      Sstackctr;                                        //~8216I~
	int rc,len,outsw=0;                                            //~8216I~
//***************                                                  //~8216I~
	switch(Popt & 0x0f)                                            //~8216I~
    {                                                              //~8216I~
    case 0:		//called at after hdr write                        //~8216I~
        Sidxrec.SHXlen=Plen;                                       //~8216I~
        memcpy(Spidxbuff+Sstackctr,&Sidxrec,sizeof(SHINDEX));  	//1st entry is acronym//~8216I~
        Sidxrec.SHXoffs+=Plen;                                     //~8216I~
        if (++Sstackctr==MAX_INDEX_STACKSZ)                        //~8217R~
        	outsw=1;                                               //~8216I~
    	break;                                                     //~8216I~
    case 1:	//header                                               //~8216I~
    	len=MAX_INDEX_STACKSZ*sizeof(SHINDEX);                     //~8217R~
    	Spidxbuff=umalloc(len);                                    //~8216I~
        if (!Spidxbuff)                                            //~8216I~
    		errmemshortage("index buff",len);                      //~8216I~
        memcpy(Spidxbuff,SIGN_HEAD,sizeof(SHINDEX));  	//1st entry is acronym//~8216I~
        Sstackctr=1;                                               //~8218I~
        Sidxrec.SHXoffs=(ULONG)ftell(Sfhoutc);			//color file hdr len//~8218R~
    	break;                                                     //~8216I~
    case 2:	//called at before trailer write                       //~8216I~
        Sidxrec.SHXlen=0xffffffff;                     //trailer pointer id//~8216I~
        memcpy(Spidxbuff+Sstackctr,&Sidxrec,sizeof(SHINDEX));  	//1st entry is acronym//~8216I~
        Sstackctr++;                                               //~8216I~
        outsw=1;                                                   //~8216I~
    	break;                                                     //~8216I~
    }                                                              //~8216I~
    if (outsw)                                                     //~8216I~
    {                                                              //~8216I~
	    rc=fwrite(Spidxbuff,1,sizeof(SHINDEX)*Sstackctr,Sfhidx);   //~8216R~
        Sstackctr=0;                                               //~8216I~
    }                                                              //~8216I~
    return rc;                                                     //~8216I~
}//writeindex                                                      //~8218R~
//**********************************************************************
//* save input text and attr for later screen write folding by scr width
//* tab is expanded by tab ctr                                     //~v70rI~
//**********************************************************************
int savescrdata(int Popt,char *Pptext,char *Ppcolor,char *Ppstyle,int Plen,int Pwidth)//~v70rR~
{
	char *pct,*pcc,*pcwte,*pcwt,*pcwc,*pcwc0,*pcwt0,*pcto,*pcco,*pcto0;
	int reslen,len,len2,col=0,expand=0,tabcolor,ii;
    PSHLINE pshl;
//*********
#ifdef UTF8SUPP                                                    //~8220I~
	if (Popt & SCDO_UTF8)	//utf column width                     //~v70rR~
		return utfsavescrdata(Popt,Pptext,Ppcolor,Ppstyle,Plen,Pwidth);//~v70rR~
#endif                                                             //~8220I~
    pcwt0=Sexpandwkt;
    pcwc0=Sexpandwkc;
	for (reslen=Plen,pct=Pptext,pcc=Ppcolor;;)
    {
    	len=min(reslen,Sscrwidth-expand);
        pcwt=pcwt0+expand;		//tab expand work
        pcwte=pcwt0+Sscrwidth;
        pcwc=pcwc0+expand;		//tab expand work
        pcto0=pct;
        for (;reslen>0 && pcwt<pcwte;)
        {
        	pcto=pct;
        	pcco=pcc;
//UTRACED("text",pcto,len);
//UTRACED("colr",pcco,len);
        	if (!(pct=memchr(pct,TABCHAR,(UINT)len)))
            {
                len2=len;
            	pct=pcto+len;
            }
            else
		        len2=(int)((ULONG)pct-(ULONG)pcto);
		    memcpy(pcwt,pcto,(UINT)len2);   //last residual
		    memcpy(pcwc,pcco,(UINT)len2);   //last residual
            pcwt+=len2;
            pcwc+=len2;
            pcc+=len2;
            len-=len2;
            if (!len) 	//tab not found
            	break;
            tabcolor=*pcc++;
            *pcwt++=Stabrepchar;         //rep tab to space
            *pcwc++=tabcolor;
            pct++;               //skip tab char
            len--;
            ii=GETTABSKIPCTR((int)((ULONG)(pcwt-1)-(ULONG)pcwt0+col));
            for (;ii>0;ii--)
            {
                *pcwt++=Stabpadchar;
                *pcwc++=tabcolor;
            }
        }//end of string
        len2=(int)((ULONG)pcwt-(ULONG)pcwt0);
        len=min(len2,Sscrwidth);
//UTRACED("outtext",pcwt0,len);
//UTRACED("outcolr",pcwc0,len);
    	if (len && len<=len2 && (Sopt & OPT_DBCS))
        {
			acbsetdbcstbl(pcwt0,Sdbcstwk,len2);
//UTRACED("dbcst",Sdbcstwk,len2);
        	if ((len<len2 &&  *(Sdbcstwk+len-1)==UDBCSCHK_DBCS1ST)
            ||  (len==len2 && *(Sdbcstwk+len-1)==UDBCSCHK_HKDBCSERR))
            {
            	len--;
            }
        }
        pshl=allocshl(pcwt0,pcwc0,len,0/*pchof*/,0/*pwidth*/);     //~v70rR~
        pshl->SHLlineno=++Sscrlineno;
        UENQ(UQUE_END,&Sshlqh,pshl);       //fifo que
        col+=len;
        expand=len2-len;
//UTRACEP("expand=%d\n",expand);
        memcpy(pcwt0,pcwt-expand,(UINT)expand);
        memcpy(pcwc0,pcwc-expand,(UINT)expand);
        len=(int)((ULONG)pct-(ULONG)pcto0);
        reslen-=len;
        if (reslen<=0 && !expand)
        	break;
    }
    return 0;
}//savescrdata
#ifdef UTF8SUPP                                                    //~8220I~
//**********************************************************************//~v70rI~
//* for utf8file                                                   //~v70rI~
//**********************************************************************//~v70rI~
int utfsavescrdata(int Popt,char *Pptext,char *Ppcolor,char *Ppstyle,int Putflen,int Pwidth)//~v70rR~
{                                                                  //~v70rI~
	char *pcwt,*pcwc,*pcwc0,*pcwt0,*pcolor0,*pdbcs0,*ptext0;       //~v70rR~
	int reslen,len,col=0,expand=0,tabcolor,ii,maxlen,maxlen2,reslen2,pos,offs;//~v70rR~
    int tabsw,dbcssplitsw,lenutf,diff;                             //~v70rR~
    PSHLINE pshl;                                                  //~v70rI~
    PCHOFTYPE pchof,pchof2,pchof0,pcwchof0,pcwchof,pchofe;         //~v70rR~
//*********                                                        //~v70rI~
    pcwt0=Sexpandwkt;	//text   wk                                //~v70rI~
    pcwc0=Sexpandwkc;   //color                                    //~v70rI~
    pcwchof0=Sexpandwkchof;    //chof                              //~v70rR~
    ptext0=Pptext;      //inp text                                 //~v70rI~
    pcolor0=Ppcolor;      //inp color                              //~v70rI~
    pdbcs0=Spbuffdbcs;      //inp dbcs                             //~v70rI~
    pchof0=Spbuffchof;      //    chof                             //~v70rI~
    pchofe=pchof0+Pwidth;      //    chof                          //~v70rI~
UTRACED("intext",ptext0,Putflen);                                  //~8215R~
UTRACED("indbcs",pdbcs0,Pwidth);                                   //~8215R~
UTRACED("incolor",pcolor0,Pwidth);                                 //~8215R~
UTRACED("inchof",pchof0,Pwidth*2);                                 //~8215R~
    maxlen=Pwidth;                                                 //~v70rR~
	for (reslen=maxlen,pchof=pchof0;;)                             //~v70rR~
    {                                                              //~v70rI~
    	maxlen2=min(reslen,Sscrwidth-expand);                      //~v70rR~
        pcwt=pcwt0+expand;		//tab expand work                  //~v70rI~
        pcwc=pcwc0+expand;		//tab expand work                  //~v70rI~
        pcwchof=pcwchof0+expand;		//tab expand work          //~v70rI~
        for (reslen2=maxlen2;;)                                    //~v70rR~
        {                                                          //~v70rI~
            tabsw=0;                                               //~v70rI~
            dbcssplitsw=0;                                         //~v70rR~
            for (ii=0,pchof2=pchof;ii<reslen2;ii++,pchof2++)       //~v70rR~
            {                                                      //~v70rI~
                if (                  //dbcssplit chk              //~v70rI~
                    (ii+1==reslen2)                                //~v70rR~
                &&  (pchof2+1<pchofe)                              //~v70rR~
                &&  (*(pdbcs0+GETWIDTH21(pchof2,pchof0))==UDBCSCHK_DBCS1ST)//~v70rR~
                )                                                  //~v70rI~
                {                                                  //~v70rI~
                    dbcssplitsw=1;                                 //~v70rR~
                    break;                                         //~v70rI~
                }                                                  //~v70rI~
                if (*(ptext0+*pchof2)==TABCHAR)                    //~v70rR~
                {                                                  //~v70rI~
                    tabsw=1;                                       //~v70rI~
                    break;                                         //~v70rI~
                }                                                  //~v70rI~
            }                                                      //~v70rI~
            pos=GETWIDTH21(pchof,pchof0);   //strat pos            //~v70rR~
            len=GETWIDTH21(pchof2,pchof);   //column from pchof to pchof2//~v70rI~
            if (len)                                               //~v70rI~
            {                                                      //~v70rI~
                offs=*pchof;                                       //~v70rI~
	            lenutf=*pchof2-offs;                               //~v70rI~
                memcpy(pcwt,ptext0+offs,(UINT)lenutf);   //last residual//~v70rR~
                memcpy(pcwc,pcolor0+pos,(UINT)len);   //last residual//~v70rR~
                pcwt+=lenutf;                                      //~v70rI~
                pcwc+=len;                                         //~v70rI~
                if (pcwchof==pcwchof0)                             //~v70rI~
                    diff=-offs;                                    //~v70rR~
                else                                               //~v70rI~
                    diff=*pcwchof-offs;                            //~v70rI~
                UTC_CHOFCPY(pcwchof,pchof,len,diff);   //update pchof also//~v70rR~
                col+=len;                                          //~v70rI~
                pos+=len;   //of pchof                             //~v70rI~
            }                                                      //~v70rI~
            if (dbcssplitsw)                                       //~v70rI~
            	break;                                             //~v70rI~
            if (tabsw)                                             //~v70rI~
            {                                                      //~v70rI~
                tabcolor=*(pcolor0+pos);                           //~v70rR~
                offs=(int)((ULONG)pcwt-(ULONG)pcwt0);              //~v70rI~
                *pcwt++=Stabrepchar;         //rep tab to space    //~v70rI~
                *pcwc++=tabcolor;                                  //~v70rI~
                *pcwchof++=offs++;                                 //~v70rI~
                pchof++;                    //tab char             //~v70rI~
                ii=GETTABSKIPCTR(col);                             //~v70rI~
                col+=ii+1;                                         //~v70rI~
                for (;ii>0;ii--)                                   //~v70rI~
                {                                                  //~v70rI~
                    *pcwt++=Stabpadchar;                           //~v70rI~
                    *pcwc++=tabcolor;                              //~v70rI~
                    *pcwchof++=offs++;                             //~v70rI~
                }                                                  //~v70rI~
                *pcwchof=offs;  //boundary balue requred to calc offs//~v70rI~
            }                                                      //~v70rI~
            reslen2=maxlen2-GETWIDTH21(pcwchof,pcwchof0);          //~v70rR~
            if (reslen2<=0)                                        //~v70rI~
            	break;                                             //~v70rI~
        }//tab search                                              //~v70rR~
        lenutf=(int)((ULONG)pcwt-(ULONG)pcwt0);                    //~v70rI~
        *pcwchof=lenutf;	//for next diff                        //~v70rR~
        len=GETWIDTH21(pcwchof,pcwchof0);                          //~v70rR~
        if (len>maxlen2)                                           //~v70rI~
        {                                                          //~v70rI~
        	expand=len-maxlen2;                                    //~v70rI~
            len=maxlen2;                                           //~v70rI~
            lenutf-=expand;                                        //~v70rI~
        }                                                          //~v70rI~
        else                                                       //~v70rI~
        	expand=0;                                              //~v70rI~
UTRACED("outtext",pcwt0,lenutf);                                   //~8215R~
UTRACED("outcolr",pcwc0,len);                                      //~8215R~
UTRACED("outchof",pcwchof0,len*2);                                 //~8215R~
        pshl=allocshl(pcwt0,pcwc0,lenutf,pcwchof0,len);            //~v70rR~
        pshl->SHLlineno=++Sscrlineno;                              //~v70rI~
        UENQ(UQUE_END,&Sshlqh,pshl);       //fifo que              //~v70rI~
        if (expand)                                                //~v70rI~
        {                                                          //~v70rI~
        	memcpy(pcwt0,pcwt-expand,(UINT)expand);                //~v70rR~
        	memcpy(pcwc0,pcwc-expand,(UINT)expand);                //~v70rR~
            pcwchof=pcwchof0;                                      //~v70rI~
            UTC_CHOFSET(pcwchof,expand+1,0);	//for tabskip count//~v70rI~
        }                                                          //~v70rI~
        reslen=maxlen-GETWIDTH21(pchof,pchof0);                    //~v70rR~
        if (reslen<=0 && !expand)                                  //~v70rI~
        	break;                                                 //~v70rI~
    }                                                              //~v70rI~
    return 0;                                                      //~v70rI~
}//utfsavescrdata                                                  //~v70rR~
#endif //UTF8                                                      //~8220I~
//*******************************************************
//*dbcs tbl output
//*******************************************************
void acbsetdbcstbl(char *Ppdata,char *Ppdbcs,int Plen)             //~8215R~
{
//***************
#ifdef WCSUPP                                                      //~079zM~
    if (UDBCSCHK_ISWCDBCS())   //C or K of CJK                     //~079zM~
    {                                                              //~079zI~
        usetdbcstblmb(USDTMO_SPLITERR|USDTMO_CHK2ND,Ppdata,Ppdbcs,Plen);	//set HKDBCSERR for last split dbcs//~079zI~
        return;                                                    //~079zI~
    }                                                              //~079zI~
#endif                                                             //~079zM~
#ifdef LNX
    if (Sopt & OPT_DBCSEUC)
    {
    	ueucchk(Ppdata,Plen,Ppdbcs,0,UDBCSCHK_EUCHKERR|UDBCSCHK_ASCIISBCS);//err when>=x'80' if not euc
    	return;
    }
#endif
    if (Sopt & OPT_DBCS)
	    usjischk(Ppdata,Plen,Ppdbcs,0/*kanactr*/,UDBCSCHK_ERRDBCSCHK);
    return;
}//acbsetdbcstbl                                                   //~v70rR~
#ifdef UTF8SUPP                                                    //~8220I~
//*******************************************************          //~v70rI~
//*set utf8 dbcs tbl and shift color info by char column           //~v70rI~
//rc:0:no utf8,1:utf8 found                                        //~v70rI~
//*******************************************************          //~v70rI~
int utfshiftcolortbl(char *Ppcolortbl,int Plen,int *Ppwidth)       //~v70rR~
{                                                                  //~v70rI~
	int width,ucscnt,ii;                                           //~v70rR~
    char *pcc;                                                     //~v70rI~
    PCHOFTYPE pchof;                                               //~v70rI~
//***************                                                  //~v70rI~
//UTRACED("in",Ppcolortbl,Plen);                                   //~8215R~
	utfsetdbcstbl(0/*opt*/,Spbufftext,Spbuffdbcs,Spbuffchof,Plen,&width,&ucscnt);//~v70rI~
    if (ucscnt==Plen)	//all single byte(NO utf8 found)           //~v70rI~
    	return 0;                                                  //~v70rI~
    for (ii=0,pcc=Ppcolortbl,pchof=Spbuffchof;ii<width;ii++,pchof++,pcc++)//~v70rI~
        *pcc=*(Ppcolortbl+*pchof);                                 //~v70rR~
    *Ppwidth=width;                                                //~v70rI~
UTRACED("shiftcolor setdbcstbl out dbcs",Spbuffdbcs,width);        //~8215R~
UTRACED("shiftcolor setdbcstbl out chof",Spbuffchof,width*2);      //~8215R~
UTRACED("chiftcolor out",Ppcolortbl,width);                        //~8215R~
    return 1;                                                      //~v70rI~
}//utfshiftcolortbl;                                               //~v70rI~
#endif                                                             //~8220I~
//**********************************************************************
//* allocate linedata save buff
//**********************************************************************
PSHLINE allocshl(char *Pptext,char *Ppcolor,int Plen,PCHOFTYPE Ppchof,int Pwidth)//~v70rR~
{
	PSHLINE pshl;
    char *pc;
    int len;
    PCHOFTYPE pchof;                                               //~v70rI~
//*********
	len=SHLINESZ+(Plen+1)*2;
    if (Pwidth)                                                    //~v70rI~
    	len+=CHOFSZ*Pwidth+CHOFSZ;                                 //~v70rI~
	pshl=(PSHLINE)(ULONG)(pc=(char*)umalloc((UINT)len));
    if (!pshl)
    	errmemshortage("screen data",len);                         //~8216R~
    memset(pshl,0,sizeof(SHLINE));                                 //~v70rR~
    pshl->SHLlen=Plen;
    pc=pshl->SHLptext=pc+SHLINESZ;
    UmemcpyZ(pc,Pptext,Plen);
    pc=pshl->SHLpcolor=pc+Plen+1;
    UmemcpyZ(pc,Ppcolor,Plen);
    if (Pwidth)                                                    //~v70rI~
    {                                                              //~v70rI~
    	pshl->SHLwidth=Pwidth;                                     //~v70rR~
    	pchof=(PCHOFTYPE)(ULONG)(pshl->SHLpcolor+Plen+1);          //~v70rI~
        memcpy(pchof,Ppchof,(UINT)(Pwidth+1)*CHOFSZ);              //~v70rI~
        pshl->SHLpchof=pchof;                                      //~v70rI~
    }                                                              //~v70rI~
    return pshl;
}//allocshl
//************************************************
//*get wkdir,ini process parameter
//************************************************
void parmproc(int Pparmc,char *Pparmp[])
{
    int parmno,posparmno=0,colno,ii;
    int fgsw=0,bgsw=0,len;                                         //~8217R~
    char *cptr,ch,*pfninp=0,*pfnoutc=0,*pfnouts=0,*pc,*pusermap=0,*pfnidx=0,*pfnerr=0,*pfnprefix=0;//~8217R~
    char fpath[_MAX_PATH];                                         //~8217I~
	UCHAR usermap[SHMAX_COLOR],hexwk[4];                           //~8216R~
#ifdef UNX
    int flagsw;
#endif
//********************
    for (parmno=1;parmno<Pparmc;parmno++)
    {
        cptr=Pparmp[parmno];
#ifdef UNX
        flagsw=CMDFLAGCHK(*cptr,posparmno); //not flag
        if (flagsw)    //filename parm                             //~8215R~
#else
        if(*cptr=='/'||*cptr=='-')
#endif
        {//option
            ch=*(++cptr);                      //first option byte
            if (*(++cptr)==':')               // /o:x format
                cptr++;                         //skip :
            switch(toupper(ch))       //option
            {
            case 'B':   //bg color
                colno=atoi(cptr);
                if (colno>=SHMAX_COLOR_BG)                         //~8216R~
        			uerrexit("Max paletteNo for BG is %d",0,       //~8215R~
                    			SHMAX_COLOR_BG-1);                 //~8216R~
                Sdefbg=colno;
                bgsw=1;                                            //~v70rI~
                break;
            case 'E':   //error msg file for xe                    //~8216I~
                if (!*cptr)                                        //~8217I~
                    errnullopd(ch);                                //~8217R~
                unlink(cptr);                                      //~8217R~
    			uerrexit_init("",stderr,0/*mapfile*/,uerrexitcbfunc/*callback*/,cptr);//~8217R~
                break;                                             //~8216I~
            case 'F':   //fg color
                colno=atoi(cptr);
                if (colno>=SHMAX_COLOR)                            //~8216R~
        			uerrexit("Max paletteNo for FG is %d",0,       //~8215R~
                    			SHMAX_COLOR-1);                    //~8216R~
                fgsw=1;                                            //~v70rI~
                Sdeffg=colno;
                break;
            case 'I':
                Sopt|=OPT_HIGHBIT;                                 //~8217I~
                break;
            case 'M':
                pc=cptr;
                if (toupper(*pc)=='R'||toupper(*(pc+1))=='R')
                {                                                  //~v70rI~
                    Sopt|=OPT_USERMAP;  //swap red and blue        //~v70rR~
                    if (Sopt & OPT_USERMAP_RB)  //swap red and blue//~v70rI~
	                    Sopt&=~OPT_USERMAP_RB;  //swap red and blue//~v70rI~
                    else                                           //~v70rI~
	                    Sopt|=OPT_USERMAP_RB;  //swap red and blue //~v70rI~
                }                                                  //~v70rI~
                if (toupper(*pc)=='W'||toupper(*(pc+1))=='W')
                    Sopt|=(OPT_USERMAP|OPT_USERMAP_BW);  //swap red and blue
                if (!(Sopt & OPT_USERMAP))
                {
                	pusermap=pc;
                    Sopt|=OPT_USERMAP;
                }
                break;
            case 'P':                                              //~8217I~
                if (!*cptr)                                        //~8217I~
                    errnullopd(ch);                                //~8217R~
                pfnprefix=cptr;                                    //~8217I~
        		len=strlen(cptr);                                  //~8217I~
        		Sopt|=OPT_FROMXE;   //write completion record on errfile//~8217I~
    			memcpy(fpath,pfnprefix,(UINT)len);                 //~8217R~
        		strcpy(fpath+len,SHFNM_COLORF);                    //~8217I~
        		pfnoutc=ustrdup(0,fpath,0);                        //~8217I~
        		strcpy(fpath+len,SHFNM_INDEXF);                    //~8217R~
        		pfnidx=ustrdup(0,fpath,0);                         //~8217I~
        		strcpy(fpath+len,SHFNM_ERRORF2);                   //~8218R~
        		pfnerr=ustrdup(0,fpath,0);                         //~8217I~
			    uerrexit_init("",0/*no fh out*/,0/*mapfile*/,uerrexitcbfunc/*callback*/,pfnerr);//~8218M~
        		strcpy(fpath+len,SHFNM_ERRORF);                    //~8218I~
                errfilecheck(fpath);	//check source-highlight stderr output//~8218R~
                break;                                             //~8217I~
            case 'S':
                if (!*cptr)                                        //~8217I~
                    errnullopd(ch);                                //~8217R~
                Sopt|=OPT_STYLEOUT;
                pfnouts=cptr;
                break;
            case 'T':
                Stabskipctr=atoi(cptr);
                if (!Stabskipctr||Stabskipctr>MAX_TAB_SKIP)        //~v70rR~
                    uerrexit("Max tab ctr is %d",0,                //~v70rR~
                                MAX_TAB_SKIP);                     //~v70rI~
                pc=cptr+unumlen(cptr,0/*opt*/,strlen(cptr));       //~v70rR~
                if (*pc==':')                                      //~v70rI~
                	pc++;                                          //~v70rR~
                if (*pc)                                           //~v70rR~
                {                                                  //~v70rI~
                    if (isdigit(*pc))                              //~v70rI~
                    {                                              //~v70rI~
                    	if (ugethex(pc,hexwk,2)<0)                 //~v70rR~
		        			optionerr("Tab display char hex notation",Pparmp[parmno]);//~v70rI~
                        Stabrepchar=*hexwk;                        //~v70rR~
                        pc+=2;                                     //~v70rI~
                    }                                              //~v70rI~
                    else                                           //~v70rI~
                    {                                              //~v70rI~
                		Stabrepchar=*pc;                           //~v70rR~
                    	pc++;                                      //~v70rR~
                    }                                              //~v70rI~
	                if (*pc)                                       //~v70rI~
                    {                                              //~v70rI~
                        if (isdigit(*pc))                          //~v70rI~
                        {                                          //~v70rI~
                            if (ugethex(pc,hexwk,2)<0)             //~v70rR~
                                optionerr("Tab padding char hex notation",Pparmp[parmno]);//~v70rI~
                            Stabpadchar=*hexwk;                    //~v70rR~
                        }                                          //~v70rI~
                        else                                       //~v70rI~
                            Stabpadchar=*pc;                       //~v70rI~
                    }                                              //~v70rI~
                }                                                  //~v70rI~
UTRACEP("tabctr=%d=%s,rep=%c,pad=%c\n",Stabskipctr,cptr,Stabrepchar,Stabpadchar);
                break;
            case 'U':                                              //~v70rI~
#ifdef UTF8SUPP                                                    //~8220I~
                Sopt|=OPT_UTF8;                                    //~v70rI~
#else                                                              //~8220I~
				uerrexit("%cU is not supported by not UTF8 version",0,//~8220R~
							CMDFLAG_PREFIX);                       //~8220R~
#endif                                                             //~8220I~
                break;                                             //~v70rI~
//**************************
//* set option     */Y
//**************************
            case 'Y':
                while (*cptr)
                {
                    switch (toupper(*cptr))
                    {
                    case '9':   //japanese errmsg if avail
                        Suerrmsgopt=(Suerrmsgopt & ~UERR_FORCE_ENGLISH);
                        break;
                    }//switch by /Yx
                    cptr++;
                }//until strlen
                break;
//**************************
//* reset option     */N
//**************************
            case 'N':
                while (*cptr)
                {
                    switch (toupper(*cptr))
                    {
                    case '9':   //no japanese errmsg(force english)
                        Suerrmsgopt=(Suerrmsgopt|UERR_FORCE_ENGLISH);
    					uerrmsg_init("",stderr,Suerrmsgopt);//msg to stdout
                        break;
                    }//switch by /Nx
                    cptr++;
                }//until strlen
                break;
            default:                                               //~8217I~
                optionerr("Unknown",Pparmp[parmno]);               //~8217I~
            }//kwd parm
        }//option
        else
        {
            if (!posparmno)
                pfninp=cptr;
            else
                uerrexit("Too  many inputfile(%s)",0,
                			cptr);
            posparmno++;
        }
    }//for all parm
    if (pfninp)                                                    //~8217R~
    {
    	Sinpfnm=pfninp;
    	if (Sfhinp=fopen(pfninp,"r"),!Sfhinp)
        	uerrexit("Input file(%s) open failed.rc=%d",
            		 "入力ファイル(%s) オープン失敗,rc=%d",
                     	pfninp,errno);
    }
    else
    	uerrexit("Specify input filename by %cI option",0,
					CMDFLAG_PREFIX);

    if (pfnoutc)                                                   //~8217R~
    {
    	if (Sfhoutc=fopen(pfnoutc,"wb"),!Sfhoutc)
        	uerrexit("Output color file (%s)open failed.rc=%d",
            		 "カラー情報出力ファイル(%s) オープン失敗,rc=%d",
                     	pfnoutc,errno);
    }
    else
    {
    	Sopt|=OPT_SCRTEST;	//test by writing to screen
    }
    if (pfnidx)                                                    //~8216I~
    {                                                              //~8216I~
    	if (Sfhidx=fopen(pfnidx,"wb"),!Sfhidx)                     //~8216I~
        	uerrexit("Output color file index file(%s)open failed.rc=%d",//~8216I~
            		 "カラー情報出力ファイルのインデックス(%s) オープン失敗,rc=%d",//~8216I~
                     	pfnidx,errno);                             //~8216I~
        Sopt|=OPT_IDX;                                             //~8216I~
    }                                                              //~8216I~
    if (pfnouts)                                                   //~8217R~
    {
    	if (Sfhouts=fopen(pfnouts,"w"),!Sfhouts)
        	uerrexit("Output style file(%s) open failed.rc=%d",
            		 "スタイル情報出力ファイル(%s)オープン失敗,rc=%d",
                     	pfnouts,errno);
    }
    else
	    if (Sopt & OPT_STYLEOUT)
        	uerrexit("specify style output filename option",0);
    if (Sopt & OPT_USERMAP_RB)  //swap red and blue
    {
        memcpy(usermap,Sdefpalette,SHMAX_COLOR);                   //~8216R~
        for (pc=usermap,ii=0;ii<SHMAX_COLOR;ii++,pc++)             //~8216R~
        {
            if ((*pc & 0x01) && !(*pc & 0x04))
                *pc=(*pc & 0x0a) | 0x04;
            else
            if (!(*pc & 0x01) && (*pc & 0x04))
                *pc=(*pc & 0x0a) | 0x01;
        }
UTRACED("usermap",Sdefpalette,16);
UTRACED("usermap",usermap,16);
        memcpy(Sdefpalette,usermap,SHMAX_COLOR);                   //~8216R~
    }
    if (Sopt & OPT_USERMAP_BW)  //swap black and white
    {
        memcpy(usermap,Sdefpalette,SHMAX_COLOR);                   //~8216R~
        for (pc=usermap,ii=0;ii<SHMAX_COLOR;ii++,pc++)             //~8216R~
        {
            if ((*pc & 0x07)==0x07)   //white
                *pc=*pc & 0x80;
            else
            if (!(*pc & 0x07))          //black
                *pc=*pc | 0x07;
        }
UTRACED("usermap",Sdefpalette,16);
UTRACED("usermap",usermap,16);
        memcpy(Sdefpalette,usermap,SHMAX_COLOR);                   //~8216R~
    }
    if (pusermap)
    {
        pc=pusermap;
        memcpy(usermap,Sdefpalette,SHMAX_COLOR);                   //~8216R~
        if (*pc=='"')
            pc++;
        for (ii=0;*pc && *pc!='"' && ii<SHMAX_COLOR;ii++,pc+=2)    //~8216R~
        {
            if (isdigit(*pc) && isdigit(*(pc+1)))
            {
                colno=(*pc&0x0f)*10+(*(pc+1)&0x0f);
                if (colno>=SHMAX_COLOR)                            //~8216R~
                    optionerr("Colormap value",pusermap);
                usermap[ii]=colno;
            }
            else
            if (!(*pc=='_' && *(pc+1)=='.'))
                optionerr("Colormap value",pusermap);
        }
        if (*pc && *pc!='"')
            optionerr("Colormap value",pusermap);
        memcpy(Sdefpalette,usermap,SHMAX_COLOR);                   //~8216R~
UTRACED("usermap",Sdefpalette,16);
UTRACED("usermap",usermap,16);
    }
    if (Sdefbg==Sdeffg)                                            //~v70rI~
    {                                                              //~v70rI~
        if (fgsw & bgsw)                                           //~v70rI~
            uerrexit("FG color and BG color is same",0);           //~v70rR~
        if (fgsw)   //no bg specified                              //~v70rI~
            Sdefbg=DEFAULT_FG;  //swap                             //~v70rI~
        else                                                       //~v70rI~
            Sdeffg=DEFAULT_BG;                                     //~v70rI~
    }                                                              //~v70rI~
    if (Sopt & OPT_USERMAP)
    	Sdefcolor=(Sdefpalette[Sdefbg]<<4)+Sdefpalette[Sdeffg];
    else
    	Sdefcolor=(Sdefbg<<4)+Sdeffg;
UTRACED("defmap",Sdefpalette,16);                                  //~8215I~
UTRACEP("defcolor=%x\n",Sdefcolor);                                //~8215I~
#ifdef AAA                                                         //~8215I~
bkgdset(Sdefcolor<<8);                                             //~8215I~
Sdefcolor=0;                                                       //~8215I~
#endif                                                             //~8215I~
    return;
}//parmproc
//**********************************************************************//~8217I~
//* sherrfilechk                                                   //~8217I~
//*   check errfile(source-highlight stderr)                       //~8217I~
//**********************************************************************//~8217I~
void errfilecheck(char *Ppfnmerr)                                  //~8217R~
{                                                                  //~8217I~
	FILE *fh;                                                      //~8217I~
    char errmsg[512],*pc;                                          //~8220R~
    int len;                                                       //~8220R~
//*************                                                    //~8217I~
UTRACEP("errfilechk fnm=%s\n",Ppfnmerr);                           //~8218I~
    if (fh=fopen(Ppfnmerr,"r"),!fh)	//not found                    //~8217I~
    	return;                                                    //~8217I~
	pc=fgets(errmsg,sizeof(errmsg),fh);	//fgets set null at eol    //~8220R~
    fclose(fh);			//unlink faile by errno=13 because source-highlight and xeacb is piped//~8218R~
    if (!pc)                                                       //~8220R~
    	return;                                                    //~8217I~
    USTR_DROPEOL_GETLEN(errmsg,len);                               //~8217I~
    if (len)                                                       //~8217I~
    	uerrexit("%s",0,errmsg);                                   //~8217I~
    return;                                                        //~8217I~
}//errfilecheck                                                    //~8217I~
//**********************************************************************
//* write option err msg                                           //~8217R~
//**********************************************************************
void optionerr(char *Ptype,char* Pvalue)
{
	uerrexit("invalid %s option parm value(%s)",                   //~8216R~
				"%s の値が無効です(%s)",
				Ptype,Pvalue);
    return;                                                        //~8216I~
}//optionerr
//**********************************************************************//~8217I~
//* write option err msg                                           //~8217I~
//**********************************************************************//~8217I~
void errnullopd(char Popt)                                         //~8217I~
{                                                                  //~8217I~
	uerrexit("%c%c option specified NULL,put option value just after the option flag like as %c%cxxx",//~8217I~
			"%c%c の値がNULLです。オプション値は%c%cxxxのようにオプションフラグに続けてください。",//~8217I~
			CMDFLAG_PREFIX,Popt,CMDFLAG_PREFIX,Popt);              //~8217I~
    return;                                                        //~8217I~
}//optionerr                                                       //~8217I~
//**********************************************************************
//* memory shortage err exit                                       //~8217R~
//**********************************************************************
void errmemshortage(char *Pcmt,int Plen)                           //~8216R~
{
	uerrexit("memory shortage for %s,reqlen=%d",0,                 //~8216R~
    			Pcmt,Plen);                                        //~8216R~
    return;                                                        //~8216I~
}//errmemshortage
//************************************************                 //~8216I~
//*called from uerrexit to pass msg to xe        *                 //~8216I~
//************************************************                 //~8216I~
void uerrexitcbfunc(char * Pmsg,void * Pvoid)                      //~8216I~
{                                                                  //~8216I~
	FILE* fherrmsgfile;                                            //~8216I~
    char *fnm;                                                     //~8216I~
//******************                                               //~8216I~
UTRACEP("cbfunc msg=%s void=%08x\n",Pmsg,Pvoid);                   //~8218R~
    if (Pvoid!=(PVOID)(-1)) //not from ueh                         //~8216I~
    {                                                              //~8216I~
    	fnm=Pvoid;                                                 //~8216I~
UTRACEP("cbfunc wite to %s\n",fnm);                                //~8218I~
    	fherrmsgfile=fopen(fnm,"w");                               //~8216I~
UTRACEP("cbfunc wite to fh=%x,errno=%d\n",fherrmsgfile,errno);     //~8218I~
        if (!fherrmsgfile)                                         //~8216R~
        	fprintf(stderr,"err msg file(%s) open failed\n",fnm);  //~8216I~
        else                                                       //~8216I~
        {                                                          //~8216I~
UTRACEP("cbfunc wite to %s\n",fnm);                                //~8218I~
        	fprintf(fherrmsgfile,"%s\n",Pmsg);                     //~8216R~
        	fclose(fherrmsgfile);                                  //~8216R~
UTRACEP("cbfunc wite to %s close\n",fnm);                          //~8218I~
        }                                                          //~8216I~
        if (Sopt & OPT_COMLETE)                                    //~8217I~
        	exit(0);                                               //~8217I~
    }                                                              //~8216I~
    return;                                                        //~8216I~
}//uerrexitcbfunc                                                  //~8216I~
