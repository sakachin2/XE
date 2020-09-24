//*CID://+vap1R~:                             update#=  153;       //+vap1R~
//***********************************************************************************
//xcfont:change console font
//***********************************************************************************
//vap1:200919 by xuerpchk                                          //+vap1I~
//***********************************************************************************//+vap1I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef W32
#include <conio.h>
#include <locale.h>
#endif
//*******************************************************
#ifdef W32
#define UNICODE
#include <windows.h>
#endif
#include <wchar.h>
//**************************************
#include <ulib.h>       //@@@@
#include <udbcschk.h>       //@@@@
#include <utrace.h>
#include <uerr.h>
#include <ustring.h>
#include <uedit.h>
#include <utf.h>
#include <ucvucs.h>
//******************************************************
#define VER "V1.01"   //version
//***********************************************************
#define PGM "xcfont"

#define CFONTINFO     CONSOLE_FONT_INFOEX
#define CLOGFONT      LOGFONT
#define CENUMMETRIC   NEWTEXTMETRICEX
#define CENUMFUNC     EnumFontFamiliesEx
#define CENUMCALLBACK FONTENUMPROC
//#define CENUMLOGFONT  LOGFONT
#define CENUMLOGFONT  ENUMLOGFONTEX

#define PARM_CHARSET     "CharSet="
#define PARM_FONTINDEX   "No="
#define PARM_FONTW       "W="
#define PARM_FONTH       "H="
#define PARM_WEIGHT      "Weight="
#define PARM_BOLD        "Bold"
#define PARM_NORMAL      "Regular"
#define PARM_QUERY       'Q'

static int Sopt;
#define XCFO_ENUMFONT        0x01
#define XCFO_ENUMCHARSET     0x02
#define XCFO_CURRENT         0x04
#define XCFO_SHOWCURRENT     0x08

#define XCFO_TRUETYPE        0x10
#define XCFO_TRUETYPENOT     0x20

#define XCFO_FIXEDPITCH      0x40
#define XCFO_VALIABLEPITCH   0x80
#define XCFO_COPYFONTH       0x0100
#define XCFO_COPYFONTW       0x0200
#define XCFO_UPDATESIZE      0x0400
#define XCFO_CONTAIN         0x0800
#define XCFO_VERBOSE         0x1000
#define XCFO_NORESTORE       0x2000

static int Scharset=DEFAULT_CHARSET;             //1
static int Sweight;
static int Sfontctr,Slistctr;
static int Sfoundctr;
static int SfontW,SfontH;
static WCHAR Sfontname[256];
static int Sfontnameucsctr;
static int Sfontnameidx;
static HANDLE Shconout;
static HDC Shdc;
static LOGFONT Slf;
static int SswTT;	//selected font is truetype
//**********************************************************
typedef struct _CHARSETTB {int CSTBid; WCHAR *CSTBname;} CHARSETTB,*PCHARSETTB;
static CHARSETTB Scstb[]={
 {ANSI_CHARSET        , L"ANSI"                }, //     0
 {DEFAULT_CHARSET     , L"DEFAULT"             }, //     1
 {SYMBOL_CHARSET      , L"SYMBOL"              }, //     2
 {MAC_CHARSET         , L"MAC"                 }, //    77
 {SHIFTJIS_CHARSET    , L"SHIFTJIS"            }, //   128
 {HANGEUL_CHARSET     , L"HANGEUL"             }, //   129
 {HANGUL_CHARSET      , L"HANGUL"              }, //   129
 {JOHAB_CHARSET       , L"JOHAB"               }, //   130
 {GB2312_CHARSET      , L"GB2312"              }, //   134
 {CHINESEBIG5_CHARSET , L"CHINESEBIG5"         }, //   136
 {GREEK_CHARSET       , L"GREEK"               }, //   161
 {TURKISH_CHARSET     , L"TURKISH"             }, //   162
 {VIETNAMESE_CHARSET  , L"VIETNAMESE"          }, //   163
 {HEBREW_CHARSET      , L"HEBREW"              }, //   177
 {ARABIC_CHARSET      , L"ARABIC"              }, //   178
 {BALTIC_CHARSET      , L"BALTIC"              }, //   186
 {RUSSIAN_CHARSET     , L"RUSSIAN"             }, //   204
 {THAI_CHARSET        , L"THAI"                }, //   222
 {EASTEUROPE_CHARSET  , L"EASTEUROPE"          }, //   238
 {OEM_CHARSET         , L"OEM"                 }  //   255
};
static CHARSETTB Sfamb[]={
 {FF_DONTCARE         , L"DONTCARE"           }, //     00
 {FF_ROMAN            , L"ROMAN"              }, //     10
 {FF_SWISS            , L"SWISS"              }, //     20
 {FF_MODERN           , L"MODERN"             }, //     30
 {FF_SCRIPT           , L"SCRIPT"             }, //     40
 {FF_DECORATIVE       , L"DECORATIVE"         }  //     50
};
//**************************************************************************
void parmchk(int Pctr,char **Pparm);
void init(void);
int enumfont(void);
int changefont(void);
int getCurrentFontInfo(int Popt,CFONTINFO *Ppfonti);
int setCurrentFontInfo(int Popt,CFONTINFO *Ppfonti,CFONTINFO *Ppfontiold,int *Pperrno,int *Pplasterr);//~8817I~//~8819R~
void showCurrent(void);
void helpmsg(void);
//**************************************************************************
void enumcharset(void)
{
	int ii,entno;
    PCHARSETTB pcst;
//***************
	entno=(int)(sizeof(Scstb)/sizeof(Scstb[0]));
	for (ii=0,pcst=Scstb;ii<entno;ii++,pcst++)
    {
    	wprintf(L"Charset % 4d : %s\n",pcst->CSTBid,pcst->CSTBname);
    }
    printf("----- Total %d Charsets\n",entno);
    return;
}//enumcharset
//**************************************************************************
WCHAR *getcharsetname(int Pcs)
{
	int ii,entno;
    PCHARSETTB pcst;
//***************
	entno=(int)(sizeof(Scstb)/sizeof(Scstb[0]));
	for (ii=0,pcst=Scstb;ii<entno;ii++,pcst++)
    {
    	if (Pcs==pcst->CSTBid)
			return pcst->CSTBname;
    }
    return L"Unknown";
}//getcharsetname
//****************************************************************
//pitch on TEXTMETRIC tmPitchAndFamily for CONSOLE_FONT_INFOEX
//****************************************************************
WCHAR *getPitchTM(int Ppf,int *Ppfixed,int *Pptruetype,int *Ppvector,int *Ppdevice)
{
	static WCHAR Swktxt[128];
    int swfixed,swTT,swVector,swDevice;
//***********************
    swfixed=(Ppf & TMPF_FIXED_PITCH)==0;	//microsoft document say opposite of name implies.
    swTT=(Ppf & TMPF_TRUETYPE)!=0;	//microsoft document
    swVector=(Ppf & TMPF_VECTOR)!=0;	//microsoft document
    swDevice=(Ppf & TMPF_DEVICE)!=0;	//microsoft document
    wsprintf(Swktxt,L"FixedPitch=%d,TrueType=%d,Vector=%d,Device=%d",swfixed,swTT,swVector,swDevice);
    if (Ppfixed)
    	*Ppfixed=swfixed;
    if (Pptruetype)
    	*Pptruetype=swTT;
    if (Ppvector)
    	*Ppvector=swVector;
    if (Ppdevice)
    	*Ppdevice=swDevice;
    return Swktxt;
}//getPitchTM
//****************************************************************
//*pitch on LOGFONT lfPitchAndFamily
//****************************************************************
WCHAR *getPitch(int Popt,int Ppf,int *Ppfixed)
{
	static WCHAR Swktxt[128];
    int fixid,swfixed;
//***********************
    fixid=(Ppf & 0x03);	//low order 2 bit
    swfixed=(fixid==FIXED_PITCH);
	wsprintf(Swktxt,L"%s",(swfixed ? L"Fixed" : ((fixid==VARIABLE_PITCH) ? L"Variable" : L"DefaultPitch")));
    if (Ppfixed)
    	*Ppfixed=swfixed;
    return Swktxt;
}//getPitch
//****************************************************************
//pitch on TEXTMETRIC tmPitchAndFamily for CONSOLE_FONT_INFOEX
//****************************************************************
int *setPitchTM(int Ptruetype,int Plfpf/*LOGFONT Pitch and Family*/,int *Pppf)
{
    int swFixed,swTT,swVector,swDevice,pf,fam,swFixedLF;
//***********************
	getPitch(0,Plfpf,&swFixedLF);
    swFixed=swFixedLF ? 0 : TMPF_FIXED_PITCH;	//microsoft document say opposite of name implies.
    swTT=Ptruetype ? TMPF_TRUETYPE : 0; 	//microsoft document
    swVector=Ptruetype ? TMPF_VECTOR : 0;	//microsoft document
    swDevice=0; //(Ppf & TMPF_DEVICE)!=0;	//microsoft document
    fam=Plfpf & 0xf0;  //bit 4 to 7:family
    pf=fam|swFixed|swTT|swVector|swDevice;
    *Pppf=pf;
    return 0;
}//getPitch
//****************************************************************
//*Popt: 01:Verbose
//****************************************************************
WCHAR *getFontType(int Popt,int Pft)
{
	static WCHAR Swktxt[128];
//***********************
    if (Popt & 0x01)
	    wsprintf(Swktxt,L"FontType=x%02x:",Pft);
    else
    	*Swktxt=0;
	if (Pft & TRUETYPE_FONTTYPE)
    	strcatW(Swktxt,L"TrueType ");
	if (Pft & RASTER_FONTTYPE)
    	strcatW(Swktxt,L"Raster ");
	if (Pft & DEVICE_FONTTYPE)
    	strcatW(Swktxt,L"Device ");
	if ((Pft & (TRUETYPE_FONTTYPE|RASTER_FONTTYPE|DEVICE_FONTTYPE))==0)
    {
	    if (Popt & 0x01)
    		strcatW(Swktxt,L"Unknown");
        else
		    wsprintf(Swktxt,L"FontType=x%02x:%s",Pft,L"Unknown");
    }
    return Swktxt;
}//getFontType
//****************************************************************
WCHAR *getWeight(int Pweight)
{
    WCHAR *id;
//***********************
    switch(Pweight)
    {
case FW_DONTCARE   :id=L"DONTCARE"   ; break;     //  0
case FW_THIN       :id=L"THIN"       ; break;     //  100
case FW_EXTRALIGHT :id=L"EXTRALIGHT" ; break;     //  200
case FW_LIGHT      :id=L"LIGHT"      ; break;     //  300
case FW_NORMAL     :id=L"Regular"    ; break;     //  400
case FW_MEDIUM     :id=L"MEDIUM"     ; break;     //  500
case FW_SEMIBOLD   :id=L"SEMIBOLD"   ; break;     //  600
case FW_BOLD       :id=L"Bold"       ; break;     //  700
case FW_EXTRABOLD  :id=L"EXTRABOLD"  ; break;     //  800
case FW_HEAVY      :id=L"HEAVY"      ; break;     //  900
default            :id=L"Unknown"    ;
    }
    return id;
}//getFontType
//****************************************************************
void printLogFont(int Popt,WCHAR *Ppcmt,CONST CLOGFONT *Pplf)
{
//*****************************************
    wprintf(L"%s:FaceName=%s,charset=%d,Width=%d,Height=%d,PitchAndFamily=x%02x(%s),Weight=%d(%s)\n",
			Ppcmt,Pplf->lfFaceName,Pplf->lfCharSet,Pplf->lfWidth,Pplf->lfHeight,Pplf->lfPitchAndFamily,getPitch(0,Pplf->lfPitchAndFamily,0),Pplf->lfWeight,getWeight(Pplf->lfWeight));
}//printLogFont
//**************************************************************************
//*Popt:01:short msg even not VERBOSE option
//**************************************************************************
void printEnum(int Popt,int Pctr,CONST CENUMLOGFONT *Ppelf,CONST CLOGFONT *Pplf,DWORD Pft)
{
	int pf,swFixed;
    WCHAR *strpitch;
//************************
    pf=Pplf->lfPitchAndFamily;
	if (Sopt & XCFO_VERBOSE)
    {
		strpitch=getPitch(0,pf,&swFixed);
		wprintf(L"No.%3d: \"%s\", %s, %s, %s\n",Pctr,Ppelf->elfFullName,Ppelf->elfStyle,Ppelf->elfScript,getFontType(0,Pft));
		wprintf(L"          FaceName=%s,CharSet=%d(%s),H=%d,W=%d\n",Pplf->lfFaceName,Pplf->lfCharSet,getcharsetname(Pplf->lfCharSet),Pplf->lfHeight,Pplf->lfWidth);
		wprintf(L"          PitchAndFamily=x%02x(%s),Weight=%d(%s)\n",pf,strpitch,Pplf->lfWeight,getWeight(Pplf->lfWeight));
    }
    else
    {
		strpitch=getPitch(0,pf,&swFixed);
		wprintf(L"No.%3d: \"%s\", %s, %s, %s, %d(%s), %s.\n",Pctr,Ppelf->elfFullName,Ppelf->elfStyle,Ppelf->elfScript,getFontType(0,Pft),Pplf->lfCharSet,getcharsetname(Pplf->lfCharSet),strpitch);
    }
}//printEnum
//**************************************************************************
//int CALLBACK effp(CONST CENUMLOGFONT *Pelf,CONST CENUMMETRIC *ntm,DWORD Pft/*fonttype*/,LPARAM Plp)
int CALLBACK effp(CONST LOGFONT *Pelf,CONST VOID *ntm,DWORD Pft/*fonttype*/,LPARAM Plp)
{
	CONST CLOGFONT *plf;
	int pf,nameucsctr;
    CENUMLOGFONT *pelf;
    int swTT,swFixed;
    WCHAR *strpitch;
    WCHAR wkbufftgt[sizeof(((CENUMLOGFONT*)0)->elfFullName)/sizeof(WCHAR)];
    WCHAR wkbuffsrc[sizeof(Sfontname)/sizeof(WCHAR)];
//*****************************************
    pelf=(CENUMLOGFONT*)(ULPTR)Pelf;	//wingdi.h define LOG_FONT,but it is actually ENUMLOGFONTEX
    plf=&pelf->elfLogFont;
    pf=plf->lfPitchAndFamily;
	strpitch=getPitch(0,pf,&swFixed);
    swTT=(Pft==TRUETYPE_FONTTYPE);
    SswTT=swTT;
    UTRACED("pelf",pelf,sizeof(CENUMLOGFONT));
    UTRACEP("%s:fonttype=x%x,logfont height=%d,width=%d,charset=%d\n",UTT,Pft,plf->lfHeight,plf->lfWidth,(int)plf->lfCharSet);
    UTRACEP("%s:PitchAndFamily=x%02x(%s) vector=%d,device=%d\n",UTT,pf,strpitch,(pf & TMPF_VECTOR)!=0,swTT,(pf & TMPF_DEVICE)!=0);
#ifdef TEST
    if (wcscmp(pelf->elfFullName,plf->lfFaceName))
    	wprintf(L"@@@@test fullname and facename unmatch Face=%s,fullnam=%s\n",plf->lfFaceName,pelf->elfFullName);
#endif
    if (Sopt & XCFO_TRUETYPE)
    {
        if (!swTT)
        {
            UTRACEP("%s:Not TrueType\n",UTT);
        	return 1;
        }
    }
    if (Sopt & XCFO_TRUETYPENOT)
    {
        if (swTT)
        {
            UTRACEP("%s:TrueType\n",UTT);
        	return 1;
        }
    }
    if (Sopt & XCFO_FIXEDPITCH)
    {
		if (!swFixed)
    	{
    		UTRACEP("%s:Not FixedPitch\n",UTT);
        	return 1;
        }
    }
    if (Sopt & XCFO_VALIABLEPITCH)
    {
		if (swFixed)
    	{
    		UTRACEP("%s:FixedPitch\n",UTT);
        	return 1;
        }
    }
    if (*Sfontname)
    {
	    if (Sopt & XCFO_CONTAIN)
        {
#ifdef AAA
            if (!strstrW(pelf->elfFullName,Sfontname))
#else
            if (!strstriW(pelf->elfFullName,Sfontname,wkbufftgt,wkbuffsrc))//case insensitive
#endif
            {
                UTRACEP("%s:Name Unmatch,containing\n",UTT);
                return 1;
            }
        }
        else
        {
            nameucsctr=strctrW(pelf->elfFullName);
            if (nameucsctr<Sfontnameucsctr
#ifdef AAA
            ||  memcmpW(pelf->elfFullName,Sfontname,Sfontnameucsctr))
#else
            ||  memicmpW(pelf->elfFullName,Sfontname,wkbufftgt,wkbuffsrc,Sfontnameucsctr))
#endif
            {
                UTRACEP("%s:Name Unmatch,startsWith\n",UTT);
                return 1;
            }
        }
    }
	Sfontctr++;
    if (Sfontnameidx)
    {
        if (Sfontnameidx!=Sfontctr)
        	return 1;
        memcpy(&Slf,plf,sizeof(Slf));
    	UTRACEP("%s:Index:%d selected \n",UTT,Sfontctr);
    	UTRACED("Index select",&Slf,(int)sizeof(Slf));
    }
    if (Sopt & XCFO_ENUMFONT)
    {
        Slistctr++;
		printEnum(0,Sfontctr,pelf,plf,Pft);
    }
    else
    {
    	Sfoundctr++;
        if (Sfoundctr==1)
        {
            memcpy(&Slf,plf,sizeof(Slf));
            wprintf(L"\"%s\" was selected,%s\n",pelf->elfFullName,getFontType(0,Pft));
            printLogFont(0,L"LogFont",plf);
        }
        else
        {
        	wprintf(L"Multiple candidate for \"%s\", No.%3d:\n",Sfontname,Sfoundctr);
            printLogFont(0,L"LogFont",plf);
        }
        UTRACEP("%s:selected by name foundctr=%d\n",UTT,Sfoundctr);
	    if (Sfontnameidx)
        	return 0;
    }
	return 1;
}//effp
//****************************************************************
int main(int parmc,char **parmp)
{
	int rc=0;
//**********************
    init();
    parmchk(parmc,parmp);
    for (;;)
    {
        if (Sopt & XCFO_SHOWCURRENT)
        {
            showCurrent();
            break;
        }
        if (Sopt & XCFO_ENUMCHARSET)
        {
            enumcharset();
            break;
        }
        if (Sopt & XCFO_ENUMFONT)
        {
            enumfont();
            wprintf(L"----- %d fonts listed. (name=%s, charset=%d)\n",Slistctr,Sfontname,Scharset);
            break;
        }
        if (Sopt & XCFO_UPDATESIZE)
        {
        	rc=changefont();
            break;
        }
        enumfont();
        if (!Sfoundctr)
        {
            wprintf(L"No font selected by CharSet=%d,FontName=%s,IndexNo=%d\n",Scharset,Sfontname,Sfontnameidx);
            return 4;
        }
        if (Sfoundctr>1)
        {
            wprintf(L"----- %d fonts listed. (name=%s, charset=%d), selectable by \"No=\" option.\n",Sfoundctr,Sfontname,Scharset);
            return 4;
        }
        rc=changefont();
        break;
    }
    return rc;
}//main
//****************************************************************
void init(void)
{
    HWND hwnd=0;
    char localecharset[128];
//*****************************
    udbcschk_setlocale(0,LC_ALL,0/*set system default*/);//required fot ICU getdefaultname
    UTRACEP("%s:localecharset=%s\n",UTT,localecharset);
    Shconout=GetStdHandle(STD_OUTPUT_HANDLE);
    hwnd=GetConsoleWindow();
    UTRACEP("%s:GetConsoleWindow hwnd=%p,Shconout=%p\n",UTT,hwnd,Shconout);
    Shdc=GetDC(hwnd);
    UTRACEP("%s:GetDC=%p\n",UTT,Shdc);
//  udbcschk_wcinit(0,localecharset);
}
//****************************************************************
int enumfont(void)
{
    CLOGFONT lf;
	CENUMCALLBACK enumproc;
//***********************
	Sfontctr=0;
    Sfoundctr=0;
    Slistctr=0;
    memset(&lf,0,sizeof(lf));    //PitchAndFamily should be 0
    lf.lfCharSet=(BYTE)Scharset;
    enumproc=&effp;
    CENUMFUNC(Shdc,&lf,enumproc,0,0);
    return Sfoundctr==1;
}//enumfont
//****************************************************************
void printCurrentFontInfo(int Popt,WUCS *Ppcmt,CFONTINFO *Ppfonti)
{
//***********************
    if (Popt & 1)   //request fontinfo
	    wprintf(L"%s:FaceName=%s,nFont=%d,W=%d,H=%d,Weight=%d(%s)\n",
				Ppcmt,Ppfonti->FaceName,Ppfonti->nFont,Ppfonti->dwFontSize.X,Ppfonti->dwFontSize.Y,Ppfonti->FontWeight,getWeight(Ppfonti->FontWeight));
    else
	    wprintf(L"%s:FaceName=%s,nFont=%d,W=%d,H=%d,PitchAndFamily=0x%x(%s),Weight=%d(%s)\n",
				Ppcmt,Ppfonti->FaceName,Ppfonti->nFont,Ppfonti->dwFontSize.X,Ppfonti->dwFontSize.Y,Ppfonti->FontFamily,getPitchTM(Ppfonti->FontFamily,0,0,0,0),Ppfonti->FontWeight,getWeight(Ppfonti->FontWeight));
}//getCurrentFont
//****************************************************************
int getCurrentFontInfo(int Popt,CFONTINFO *Ppfonti)
{
	size_t fontisz;
    int rc;
//******************************
 	fontisz=sizeof(CFONTINFO);
 	memset(Ppfonti,0,fontisz);
    Ppfonti->cbSize=fontisz;
    rc=GetCurrentConsoleFontEx(Shconout,FALSE/*current window size*/,Ppfonti);
    if (rc)
    {
        if (Popt & 1)   //print
            wprintf(L"\"%s\": Height=%d, Width=%d\n",Ppfonti->FaceName,Ppfonti->dwFontSize.Y,Ppfonti->dwFontSize.X);
    }
    else
    	wprintf(L"GetCurrentConsoleFontEx failed by %d\n",GetLastError());
    UTRACEP("%s:rc=%d,getLastError=%d\n",UTT,rc,GetLastError());
    UTRACED("CurrentFont",Ppfonti,(int)fontisz);
    UTRACEP("%s:nFont=%d,fontW=%d,fontH=%d,family=%d,Weight=%d\n",UTT,Ppfonti->nFont,Ppfonti->dwFontSize.X,Ppfonti->dwFontSize.Y,Ppfonti->FontFamily,Ppfonti->FontWeight);
    return rc;
}//getCurrentFont
//****************************************************************
//*rc:0:name changed differentry, 4:req same as old,3:name was not changed,2:size/weight adjusted,1:suceeded//~8817M~
//**************************************************************** //~8817I~
int setCurrentFontInfo(int Popt,CFONTINFO *Ppfonti,CFONTINFO *Ppfontiold,int *Pperrno,int *Pplasterr)//~8817R~//~8819R~
{
	int rc=1/*success*/,errn,erro,errcode;                                 //~8817I~//~8819R~
	CFONTINFO fontinew;                                            //~8817I~
    int swSameReqName,swSameReqSize,swSameReqWeight;               //~8817I~
    int swUpdatedName,swUpdatedSize,swUpdatedWeight;               //~8817I~
    int swChangedName,swChangedSize,swChangedWeight;               //~8817I~
    int swAdjustedName,swAdjustedSize,swAdjustedWeight;            //~8817I~
    int swRejectedName,swRejectedSize,swRejectedWeight;            //~8817I~
//******************************                                   //~8817I~
    UTRACED("Ppfonti",Ppfonti,(int)sizeof(CFONTINFO));             //~8817I~
    UTRACED("Ppfontiold",Ppfontiold,(int)sizeof(CFONTINFO));       //~8817I~
	printCurrentFontInfo(0,L"Requested",Ppfonti);                  //~8817I~
    swSameReqName=!memcmp(Ppfonti->FaceName,Ppfontiold->FaceName,sizeof(Ppfonti->FaceName));//~8817I~
    swSameReqSize=!memcmp(&Ppfonti->dwFontSize,&Ppfontiold->dwFontSize,sizeof(Ppfonti->dwFontSize));//~8817I~
    swSameReqWeight=Ppfonti->FontWeight==Ppfontiold->FontWeight;   //~8817I~
    UTRACEP("%s:same req name=%d,size=%d,weight=%d\n",UTT,swSameReqName,swSameReqSize,swSameReqWeight);//~8817I~
    if (swSameReqName && swSameReqSize && swSameReqWeight)         //~8817I~
    {                                                              //~8817I~
		printCurrentFontInfo(0,L"Old",Ppfontiold);                 //~8817I~
    	wprintf(L"Not updated(same as current status).\n");        //~8817I~
    	*Pperrno=0;                                                //~8817I~
    	*Pplasterr=0;                                              //~8819I~
    	return 4;                                                  //~8817I~
    }                                                              //~8817I~
    erro=GetLastError();                                           //~8817I~
    rc=SetCurrentConsoleFontEx(Shconout,FALSE,Ppfonti);            //~8817I~
    errcode=errno;                                                 //~8819I~
    errn=GetLastError();                                           //~8817I~
    UTRACEP("%s:SetCurrentConsoleFontEx errno=%d,lasterr=%d\n",UTT,errcode,errn);//~8819I~
    if (rc)	//done                                                 //~8817I~
    {                                                              //~8817I~
		getCurrentFontInfo(0,&fontinew);                           //~8817I~
	    UTRACED("fontinew",&fontinew,(int)sizeof(CFONTINFO));      //~8817I~
	    swUpdatedName=!memcmp(Ppfonti->FaceName,&fontinew.FaceName,sizeof(Ppfonti->FaceName));//~8817I~
    	swUpdatedSize=!memcmp(&Ppfonti->dwFontSize,&fontinew.dwFontSize,sizeof(Ppfonti->dwFontSize));//~8817I~
    	swUpdatedWeight=Ppfonti->FontWeight==fontinew.FontWeight;  //~8817I~
	    swChangedName=memcmp(Ppfontiold->FaceName,&fontinew.FaceName,sizeof(Ppfonti->FaceName));//~8817I~
    	swChangedSize=memcmp(&Ppfontiold->dwFontSize,&fontinew.dwFontSize,sizeof(Ppfonti->dwFontSize));//~8817I~
    	swChangedWeight=Ppfonti->FontWeight!=fontinew.FontWeight;  //~8817I~
        UTRACEP("%s:updated by req name=%d,size=%d,weight=%d, changed from old name=%d,size=%d,weight=%d\n",UTT,swUpdatedName,swUpdatedSize,swUpdatedWeight,swChangedName,swChangedSize,swChangedWeight);//~8817I~
	    swRejectedName  =!swSameReqName     && !swChangedName;	//changed req rejected//~8817I~
        swRejectedSize  =!swSameReqSize     && !swChangedSize;	//changed req rejected//~8817I~
        swRejectedWeight=!swSameReqWeight   && !swChangedWeight;	//changed req rejected//~8817I~
	    swAdjustedName  =!swSameReqName     && !swUpdatedName   && swChangedName;	//changed not as requested//~8817I~
	    swAdjustedSize  =!swSameReqSize     && !swUpdatedSize   && swChangedSize;	//changed not as requested//~8817I~
	    swAdjustedWeight=!swSameReqWeight   && !swUpdatedWeight && swChangedWeight;	//changed not as requested//~8817I~
        UTRACEP("%s:rejected name=%d,size=%d,weight=%d, Adjusted req name=%d,size=%d,weight=%d\n",UTT,swRejectedName,swRejectedSize,swRejectedWeight,swAdjustedName,swAdjustedSize,swAdjustedWeight);//~8817I~
        if (swRejectedName)	//name not was updated differently     //~8817I~
        {                                                          //~8817I~
			printCurrentFontInfo(0,L"Old      ",Ppfontiold);       //~8817R~
			printCurrentFontInfo(0,L"Result   ",&fontinew);        //~8817R~
    		wprintf(L"ERROR:setFont done but not accepted !!!\n"); //~8817I~
            UTRACEP("%s:name not changed\n",UTT);                  //~8817I~
            if (swChangedSize||swChangedWeight)                    //~8817I~
            	rc=0;	//restore                                  //~8817I~
            else                                                   //~8817I~
            	rc=3;       //no need to restore                   //~8817I~
	    	*Pperrno=errcode;                                         //~8817I~//~8819R~
	    	*Pplasterr=errn;                                       //~8819I~
    		UTRACEP("%s:SetCurrentFontEx rc=%d,Pperrno=%d,lasterr=%d\n",UTT,rc,*Pperrno,*Pplasterr);//~8817I~//~8819R~
            return rc;       //no need to restore                  //~8817I~
        }                                                          //~8817I~
        if (swAdjustedName)	//name was updated differently         //~8817I~
        {                                                          //~8817I~
			printCurrentFontInfo(0,L"Old      ",Ppfontiold);       //~8817R~
			printCurrentFontInfo(0,L"Result   ",&fontinew);        //~8817R~
    		wprintf(L"ERROR:setFont done but fontname change request adjusted by system !!!\n");//~8817I~
	    	*Pperrno=errcode;                                         //~8817I~//~8819R~
	    	*Pplasterr=errn;                                       //~8819I~
            UTRACEP("%s:name updated differently,errno=%d,lasterr=%d\n",UTT,errcode,errn);          //~8817I~//~8819I~
            return 0;	//req restore                              //~8817I~
        }                                                          //~8817I~
//*name changed accepted or name change was not requested          //~8817I~
    	if (swAdjustedSize || swAdjustedWeight || swRejectedSize || swRejectedWeight)	//size/weight updated differentry//~8817I~
        {                                                          //~8817I~
    		UTRACEP("%s:adjusted szie/weight.\n",UTT);             //~8817I~
			printCurrentFontInfo(0,L"Result   ",&fontinew);        //~8817R~
	    	wprintf(L"Size/Weight change request was Adjusted or Rejected,\n Height: %d --> %d, Width: %d--> %d Weight: %d --> %d.\n",//~8817I~
		                Ppfonti->dwFontSize.Y,                     //~8817I~
        			    fontinew.dwFontSize.Y,                     //~8817I~
                		Ppfonti->dwFontSize.X,                     //~8817I~
                		fontinew.dwFontSize.X,                     //~8817I~
                		Ppfonti->FontWeight,                       //~8817I~
                		fontinew.FontWeight);                      //~8817I~
            rc=2;                                                  //~8817I~
        }                                                          //~8817I~
        else                                                       //~8817I~
        {                                                          //~8817I~
			printCurrentFontInfo(0,L"Result   ",&fontinew);        //~8817R~
            if (Popt & 1 )	//restore                              //~8817I~
		    	wprintf(L"Restore was successfully done!\n");      //~8817I~
            else                                                   //~8817I~
		    	wprintf(L"Successfully done!\n");                  //~8817R~
        }                                                          //~8817I~
    }                                                              //~8817I~
    *Pperrno=errcode;                                                 //~8817I~//~8819R~
    *Pplasterr=errn;                                               //~8819I~
    UTRACEP("%s:GetLastError old=%d,new=%d\n",UTT,erro,errn);      //~8817I~
    UTRACEP("%s:SetCurrentFontEx rc=%d,errno=%d,lasterr=%d\n",UTT,rc,*Pperrno,*Pplasterr);//~8817I~//~8819R~
    return rc;                                                     //~8817I~
}//setCurrentFont
//****************************************************************
int changefont(void)
{
    int fontisz,rc,errcode,pf,lasterr;                             //~8819R~
	CFONTINFO fonti,fontiold,fontiold2;                            //~8817R~
	CLOGFONT *plf=0;
    double dww,dhh;
//*****************************************
	getCurrentFontInfo(0,&fontiold);
	if (Sopt & XCFO_UPDATESIZE)
    {
        memcpy(&fonti,&fontiold,sizeof(fonti));
    }
    else
    {
		plf=&Slf;
 		memset(&fonti,0,sizeof(CFONTINFO));
 		fontisz=sizeof(CFONTINFO);
    	fonti.cbSize=fontisz;
 		fonti.dwFontSize.X=(SHORT)plf->lfWidth;
 		fonti.dwFontSize.Y=(SHORT)plf->lfHeight;
//  	fonti.FontFamily=plf->lfPitchAndFamily;
		setPitchTM(SswTT,plf->lfPitchAndFamily,&pf);
  		fonti.FontFamily=pf;
  		fonti.FontWeight=plf->lfWeight;
    	UstrncpyZWctr(fonti.FaceName,plf->lfFaceName,LF_FACESIZE);
    }
    if (Sweight)
	    fonti.FontWeight=Sweight;
    if (Sopt & XCFO_COPYFONTH)
        SfontH=fontiold.dwFontSize.Y;
    if (Sopt & XCFO_COPYFONTW)
        SfontW=fontiold.dwFontSize.X;
    UTRACEP("%s:Sopt=%x,H=%d,W=%d\n",UTT,Sopt,SfontH,SfontW);
    dhh=fonti.dwFontSize.Y;
    dww=fonti.dwFontSize.X;
    if (SfontH && !SfontW)   //Width missing
        SfontW=(int)(SfontH*dww/dhh);
    else
    if (SfontW && !SfontH)   //Width missing
        SfontH=(int)(SfontW*dhh/dww);
    if (SfontH)
		fonti.dwFontSize.Y=(SHORT)SfontH;
    if (SfontW)
		fonti.dwFontSize.X=(SHORT)SfontW;
	rc=setCurrentFontInfo(0,&fonti,&fontiold,&errcode,&lasterr);            //~8817R~//~8819R~
    if (!rc)                                                       //~8817R~
    {
        UTRACEP("%s:SetFont request failed, restored old value(errno=%d,GetLastError=%d)\n",UTT,errcode,lasterr);//~8819R~
        if ((Sopt & XCFO_NORESTORE))
        	wprintf(L"WARNING!! restore was not done by specified option.\n");
        else
        {
        	wprintf(L"SetFont request failed (errno=%d,GetLastError=%d), will be restore old value.\n",errcode,lasterr);//~8817I~//~8819R~
			getCurrentFontInfo(0,&fontiold2);                      //~8817I~
			rc=setCurrentFontInfo(1,&fontiold,&fontiold2,&errcode,&lasterr);//~8817R~//~8819R~
        }
    }
    return rc;
}//changefont
//****************************************************************
void showCurrent(void)
{
	CFONTINFO fonti;
//*****************************************
	getCurrentFontInfo(0,&fonti);
	printCurrentFontInfo(0,L"Current Status",&fonti);
}//showCurrent;
//****************************************************************
int cvl2u(int Popt,char *Plcdata,int Plen,WUCS *Ppucs,int Pbuffsz,int *Ppucsctr)
{
    int rc,u8len,chklen,errctr,outlen,ucsctr;
    char wku8[256];
//*****************************************
    rc=utfcvl2f(0,wku8,Plcdata,0/*initoffs*/,(int)strlen(Plcdata),0/*pchof*/,0/*pdbcs*/,&chklen,&u8len,0/*charctr*/,0/*charwidth*/);
    if (rc>=UTFCVRC_ERR)
    {
//  	uerrexit("Unicode translation error(%s)",Plcdata);         //+vap1R~
    	uerrexit("Unicode translation error(%s)",0,Plcdata);       //+vap1I~
    }
    rc=ucvsutf2ucs(0,UCVUCS_LE,wku8,u8len,(UCHAR*)Ppucs,Pbuffsz,&chklen,&outlen,&errctr);
    ucsctr=outlen/sizeof(WUCS);
    Ppucs[ucsctr]=0;
    if (Ppucsctr)
    	*Ppucsctr=ucsctr;
    return rc;
}//cvl2u
//**********************************************************************
//* write option err msg
//**********************************************************************
void optionerr(char *Ptype,char* Pvalue)
{
	if (Ptype)
		uerrexit("invalid %s option parm value(%s)\n",0,
				Ptype,Pvalue);
    else
		uerrexit("invalid parm value(%s)\n",0,
				Pvalue);
  	return;
}//optionerr
//****************************************************************
void parmchk(int parmc,char **parmp)
{
	int parmno,ucsctr,swnot,posparmno=0;
    char *cptr,*pval;
//*****************************************
  	if (parmc<2 || *parmp[1]=='?')
  	{
    	helpmsg();
    	exit(0);
  	}
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
  		if(*cptr=='/'||*cptr=='-')
  		{//option
        	swnot=0;
        	for (pval=cptr+1;*pval;pval++)
            {
            	switch(toupper(*pval))
                {
        		case 'A':
	            	Sopt|=XCFO_NORESTORE;
                    break;
        		case 'B':
	            	Sopt|=XCFO_TRUETYPENOT;
                    break;
        		case 'D':
    	        	Sopt|=XCFO_VERBOSE;
                    break;
        		case 'F':
    	        	Sopt|=XCFO_FIXEDPITCH;
                    break;
        		case 'Q':
                    Sopt|=XCFO_ENUMFONT;
                    break;
        		case 'T':
	            	Sopt|=XCFO_TRUETYPE;
                    break;
                case 'V':
	            	Sopt|=XCFO_VALIABLEPITCH;
                    break;
                case '?':
    				helpmsg();
    				exit(0);
                default:
                	optionerr(0,pval);
        	    }//switch
            }//foe
    	}//flag
      	else
      	{//positional parmno
        	if (USTRHEADIS_IC(cptr,PARM_CHARSET))
        	{
            	pval=cptr+sizeof(PARM_CHARSET)-1;
                if (*pval=='?')
                {
                    Sopt|=XCFO_ENUMCHARSET;//
                }
                else
                {
                	if (unumlen(pval,0,strlen(pval))!=(int)strlen(pval))//~8828R~
                		optionerr(0,cptr);
                	Scharset=atoi(pval);
                }
            }
            else
        	if (USTRHEADIS_IC(cptr,PARM_FONTINDEX))
        	{
            	pval=cptr+sizeof(PARM_FONTINDEX)-1;
                if (unumlen(pval,0,strlen(pval))!=(int)strlen(pval))//~8828R~
                	optionerr(0,cptr);
                Sfontnameidx=atoi(pval);
            }
            else
        	if (USTRHEADIS_IC(cptr,PARM_FONTH))
        	{
            	pval=cptr+sizeof(PARM_FONTH)-1;
                if (!strcmp(pval,"*"))
                {
                    Sopt|=XCFO_COPYFONTH;
                }
                else
                {
                	if (unumlen(pval,0,strlen(pval))!=(int)strlen(pval))//~8828R~
                		optionerr(0,cptr);
                	SfontH=atoi(pval);
                    if (!SfontH)
                		optionerr(0,cptr);
                }
            }
            else
        	if (USTRHEADIS_IC(cptr,PARM_FONTW))
        	{
            	pval=cptr+sizeof(PARM_FONTW)-1;
                if (!strcmp(pval,"*"))
                {
                    Sopt|=XCFO_COPYFONTW;
                }
                else
                {
                	if (unumlen(pval,0,strlen(pval))!=(int)strlen(pval))//~8828R~
                		optionerr(0,cptr);
                	SfontW=atoi(pval);
                    if (!SfontW)
                		optionerr(0,cptr);
                }
            }
            else
        	if (USTRHEADIS_IC(cptr,PARM_WEIGHT))
        	{
            	pval=cptr+sizeof(PARM_WEIGHT)-1;
	        	if (USTRHEADIS_IC(pval,PARM_BOLD))
                	Sweight=FW_BOLD;
                else
	        	if (USTRHEADIS_IC(pval,PARM_NORMAL))
                	Sweight=FW_NORMAL;
                else
                	optionerr(0,cptr);
            }
            else
        	{
            	if (posparmno)
                {
                	uerrmsg("Multiple fontname spcification,",0);
	                optionerr(0,cptr);
                }
                posparmno++;
            	pval=cptr;
                if (!strcmp(pval,"*"))
                {
                    Sopt|=XCFO_CURRENT;
                }
                else
                {
	                if (*pval=='*')
                    {
	                    Sopt|=XCFO_CONTAIN;
                        pval++;
                    }
                    cvl2u(0,pval,(int)strlen(pval),Sfontname,sizeof(Sfontname),&ucsctr);
                    UTRACED("Parm fontname",Sfontname,(ucsctr+1)*2);
                    Sfontnameucsctr=ucsctr;
                }
            }
  		}//option or posparm
	}//for all parm
    if (Sopt & XCFO_CURRENT)
    {
        if (Sopt & XCFO_ENUMFONT)
            Sopt|=XCFO_SHOWCURRENT;
        else
            Sopt|=XCFO_UPDATESIZE;
    }
    if (Sopt & XCFO_UPDATESIZE)
    {
        if (!SfontH && !SfontW && !Sweight)
        	uerrexit("%s , %s or %s required when fontname is \"*\" (Change size of current Font),\n or missing %c%c ?",0,
						PARM_FONTW,PARM_FONTH,PARM_WEIGHT,CMDFLAG_PREFIX,PARM_QUERY);
    }
    return;
}//parmchk
//****************************************************************
void helpmsg(void)
{
#define HELPMSG uerrhelpmsg(stdout,stderr,
//*****************************************
HELPMSG
"%s:%s(%c): Change Current Console Font. (Supported From Vista.)\n",0,//~8821R~
				PGM,VER,OSTYPE);
HELPMSG
" %s  [%coptions] [ <name> ] [ %s<seqno> ] [ %s{<charset>|?} ]\n",0,
			PGM,CMDFLAG_PREFIX,PARM_FONTINDEX,PARM_CHARSET);
HELPMSG
"                    [ %s<height> ] [ %s<width> ] [ %s<weight> ]\n",0,
			PARM_FONTH,PARM_FONTW,PARM_WEIGHT);
        HELPMSG                                                    //~8817I~
"*******************************************************************************\n",0); //80 column limit indicator//~8817I~
HELPMSG
" <name >  :Partial string of FontName(StartsWith).\n",0);
HELPMSG
"           \"*\" means current font.\n",0);
HELPMSG
"           Prefix:\"*\" means Contains.\n",0);
HELPMSG
" <seqno>  :Select font by SeqNo from listed fonts,\n",0);
HELPMSG
"           to allow name is not full specification.\n",0);
HELPMSG
" <charset>:Select filtering by charset.\n",0);
HELPMSG
"           List available value by \"charset=?\".\n",0);          //~8817R~
HELPMSG
" <height> :Font Height. \"*\" means copy from current.\n",0);
HELPMSG
" <width>  :Font Width. \"*\" means copy from current.\n",0);
HELPMSG
"           if missing, calculated from height.\n",0);
HELPMSG
" <weight> :Weight. specify %s/%s.\n",0,
			PARM_NORMAL,PARM_BOLD);
HELPMSG
"           if missing, adopted from selected font.\n",0);
HELPMSG
"  %coptions \n",0,
			CMDFLAG_PREFIX);
HELPMSG
"     %cA:Accept System Selection.\n",0,
			CMDFLAG_PREFIX);
HELPMSG
"        Not restore even when system set differently from requested.\n",0,
			CMDFLAG_PREFIX);
HELPMSG
"     %cB:Select Not TrueType fonts(Raster) only.\n",0,
			CMDFLAG_PREFIX);
HELPMSG
"     %cD:Detail Query Information.\n",0,
			CMDFLAG_PREFIX);
HELPMSG
"     %cF:Select Fixed Pitch fonts only.\n",0,
			CMDFLAG_PREFIX);
HELPMSG
"     %c%c:Query candidate fonts.\n",0,
			CMDFLAG_PREFIX,PARM_QUERY);
HELPMSG
"     %cT:Select TrueType fonts only.\n",0,
			CMDFLAG_PREFIX);
HELPMSG
"     %cV:Select Variable Pitch fonts only.\n",0,
			CMDFLAG_PREFIX);
HELPMSG
" e.g. ----- (all are case insensitive) -----\n",0);
HELPMSG
"   %s %c%c charset=222     ; List fonts of charset:THAI.\n",0,PGM,CMDFLAG_PREFIX,PARM_QUERY);
HELPMSG
"   %s charset=?          ; List available charset .\n",0,PGM);
HELPMSG
"   %s %c%cf                ; List FixedPitch font.\n",0,PGM,CMDFLAG_PREFIX,PARM_QUERY);
HELPMSG
"   %s %c%c *               ; Show current font set.\n",0,PGM,CMDFLAG_PREFIX,PARM_QUERY);
HELPMSG
"   %s %c%c Microsoft       ; List fontname starting with \"Microsoft\".\n",0,PGM,CMDFLAG_PREFIX,PARM_QUERY);
HELPMSG
"   %s %c%c *Sans           ; List fontname containing \"Sans\".\n",0,PGM,CMDFLAG_PREFIX,PARM_QUERY);
HELPMSG
"   %s Microsoft No=2     ; Select second font listed by \"Microsoft\".\n",0,PGM);
HELPMSG
"   %s SimSun charset=238 ; Select SimSun with charset:EASTEUROPE.\n",0,PGM);
HELPMSG
"   %s Tahoma H=*         ; H=current, W=H*rate of W/H of selected.\n",0,PGM);
HELPMSG
"   %s * H=16 W=10        ; Update current font sizes\n",0,PGM);
HELPMSG
"   %s * Weight=Bold      ; Set current font weight to Bold\n",0,PGM);
HELPMSG                                                            //~8817I~
"   chcp 57002                ; 57002:Devanagari, \"Mangal\" requires it.\n",0);//~8817R~
HELPMSG                                                            //~8817I~
"   %s Mangal H=*         ; Codepage will be listed by \"xcv /list\".\n",0,PGM);//~8817R~
}//helpmsg
