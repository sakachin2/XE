//*CID://+vb4iR~: update#=  107;                                   //+vb4iR~
//******************************************************************************//~v003I~
//vb4i:160805 vb4f for wxe(specify ligature on/off,combine on/of line by line)//~vb4jI~
//vb2J:160313 (W32) compier warning                                //~vb2JI~
//vb2H:160307 (W32)UWCHART cut ucs4                                //~vb2HI~
//vavz:140428 (wxe)display ucs2 filename on page dialog            //~vafaI~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vafaI~
//vafh:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~vafhI~
//vafa:120607 (WXE2010)C4700 warning(used uninitialized variable)  //~vafaI~
//va8a:100926 (WXE)end wxp work at end print                       //~va8aI~
//va88:100926 (WXE)2p print;right half contline dbcs override left half lineno fld//~va88I~
//va80:100917 (WXEXXE)print ebcfile by ucs                         //~va80I~
//va49:100406 (WXE:BUG)wxe print abend when VHEX and HHEX.         //~va49I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v66A:051220 dialog to confirm wxe/gxe termination when func-key used//~v66AI~
//v65h:050729 (BUG:WXE)hardcopy;fullpage is allways effective      //~v65gR~
//v65g:050729 (BUG:WXE)hardcopy overflows preview-area/form by difference of Mdrawcellw(print) and Mcellh(scr)//~v65gI~
//v65f:050729 (BUG:WXE)maxcellheight parameter effect as on/off(any value limit to cellh(fonth)) and do not expand//~v65fI~
//v62W:050422 (WXE)maximum cell height definition for small doc    //~v62WI~
//v62M:050417 (WXE)more ajust when calcurated maxrow is minus when no parm specified//~v62MI~
//            (reduce font width by expanding maxrow)              //~v62MI~
//v627:050309 (WXE)vhex print support                              //~v627I~
//v53q:030930 (WXE:BUG) area not freed when print canceled because endprinting is not called//~v53qI~
//v51h:030525 (WXE)col/row by font size specification              //~v51hI~
//******************************************************************************//~v003I~
#include    "StdAfx.h"                                             //~v003I~
#define NO_MACRO_REDIRECT                                          //~vafaI~
#include    "ulib.h"                                               //~vafaI~
#include    "wxedef.h"                                             //~v003I~
#include    "wxe.h"                                                //~2A10I~
#include    "wxefile.h"                                            //~v003M~
#include    "wxeDoc.h"                                             //~v003I~
#include    "wxemain.h"                                            //~v003R~
#include    "wxecsub.h"                                            //~2901I~
#include    "wxepage.h"                                            //~2B23I~
#include    "wxexei.h"                                             //~2901I~
#include    "resource.h"                                           //~v003I~
                                                                   //~v003I~
//#include    "ulib.h"                                               //~v003I~//~vafaR~
#include    "udbcschk.h"                                           //~v003I~
#include    "utrace.h"                                             //~2914I~
//===============================================================================//~2B09I~
#define MM2POINT(mm)    ((float)(((float)mm)*72/25.4)) //1inch=72point=25.4mm//~v51hR~
#ifdef UTF8UCS2                                                    //~va20I~
#define VHEXLINEID      0xff     //vhexline of pagewk              //~va20R~
#endif                                                             //~va20I~
//===============================================================================//~2B18I~
#define FORM_CTR 7                                                 //~2B09I~
#define FORM_DEFAULT_INDX 1 // A4                                  //~2B09I~
	static char *Sformtbl[FORM_CTR]={"A3","A4","A5","B4","B5","Letter","Leagal"};//~2B09I~
    static int   Sformsz[FORM_CTR][2]={                            //~2B09I~
					{297,420},	//A3                               //~2B09I~
					{210,297},	//A4                               //~2B09I~
					{148,210},	//A5                               //~2B09I~
					{257,364},	//B4                               //~2B09I~
					{182,257},	//B5                               //~2B09I~
					{216,279},	//letter                           //~2B09I~
					{216,355} 	//leagal                           //~2B09I~
                    };                                             //~2B09I~
    static int   Sdmformtype[FORM_CTR]={//for devmode chng         //~2B24I~
					DMPAPER_A3,                                    //~2B24I~
					DMPAPER_A4,                                    //~2B24I~
					DMPAPER_A5,                                    //~2B24I~
					DMPAPER_B4,                                    //~2B24I~
					DMPAPER_B5,                                    //~2B24I~
					DMPAPER_LETTER,   // 8.5*11 inch               //~2B24R~
					DMPAPER_LEGAL};   // 8.5*14                    //~2B24R~
                                                                   //~2B09I~
//===============================================================================//~2B02I~
//called once first at print start                                 //~2B02R~
//parm:pinfo;0 if preview                                          //~2B04I~
//rc:   FALSE:print skip                                           //~2B10I~
//===============================================================================//~2B02I~
//int CWxemain::onprepareprinting(CPrintInfo* pInfo)               //~@@@@R~
int CWxemain::onprepareprinting(int Pprintsw)                      //~@@@@I~
{                                                                  //~2B02I~
	int maxpage=1,totline,formw,formh,linenofw,col2p,totrow;       //~2C01R~
    int rc=TRUE,len,len2,formid;                                   //~2B30R~
    int /*pfontsz,*/fonth,fontw;                                   //~v51hR~
    void *pfh;                                                     //~2B09I~
    void *pcw=0;                                                   //~v627I~
#ifdef UTF8UCS2                                                    //~va20I~
    int swutf8file;                                                //~va20I~
#endif                                                             //~va20I~
	int allowance=256;                                             //~va80R~
//************************************                             //~2B02I~
//  Mprtlinework=0;                                                //~v53qR~
//  Mprtpagework=0;                                                //~v53qR~
//	afterprint();                                                  //~v53qI~//~va8aR~
  	afterprint(0);                                                 //~va8aI~
    Mprtclineno=0;                                                 //~2B04I~
//set Mhcopysw now not later                                       //~v65hI~
	if (!Mhcopysw)	//not printscreen                              //~v65hI~
    {                                                              //~v65hI~
    	if (wxe_getpcw(0)==PRTTYPE_HCOPY)                          //~v65hI~
        	Mhcopysw=1;                                            //~v65hI~
    }                                                              //~v65hI~
//create printer font                                              //~v51hI~
//  if (Mchkpfontsz)    //fontsize specified                       //~v65hR~
    if (!Mhcopysw||(Mchkpfontsz && !Mwwscrprt))    //fontsize specified,if wysiwig use screen cell size//~v65gR~
    {                                                              //~v51hI~
        fonth=Mpfontszh,fontw=Mpfontszw,                           //~v51hR~
        Mdrawcellh=Mpcellszh,Mdrawcellw=Mpcellszw;                 //~v51hR~
        if (!Mdrawcellh)        //if cellh=0                       //~v51hR~
        	Mdrawcellh=fonth;	//same as font height              //~v51hR~
        if (!fonth)                                                //~v65gI~
        	fonth=Mdrawcellh;	//one of cellh and fonth is not 0 by wxepage//~v65gI~
    }                                                              //~v51hI~
    else                                                           //~v51hR~
    {                                                              //~v51hI~
        fonth=Mfontheight,fontw=Mfontwidth,                        //~v51hR~
        Mdrawcellh=Mcellh,Mdrawcellw=Mcellw;                       //~v51hR~
    }                                                              //~v51hI~
    if (Mfullpage||Mchkpfontsz)                                    //~v51hI~
        if (!fontw)                                                //~v51hI~
        	fontw=fonth>>1;                                        //~v51hI~
    if (!Mdrawcellw)                                               //~v51hR~
    	Mdrawcellw=Mdrawcellh>>1;                                  //~v51hR~
//  if (pInfo)	//not preview                                      //~@@@@R~
    if (Pprintsw)	//not preview                                  //~@@@@I~
        Mpprtfont=createfontsub(Mcharset,Mprtfontstyle,Mttfont,fonth,fontw,0);//~v51hR~
    else                                                           //~v51hI~
        Mpprtfont=createfontsub(Mcharset,NULL,Mttfont,fonth,fontw,0);//~v51hI~
    formid=prtgetformsz(Mlandscape,Mformtype,&formw,&formh);       //~2B24I~
UTRACEP("prepare print formsz=%s(%d),land=%d\n",Mformtype,formid,Mlandscape);//~3105R~
	if (!Mhcopysw)	//not printscreen                              //~2B23R~
    {                                                              //~2B07I~
//  	Mprttype=prtgetscrdata(0,Mwwscrprt,&pfh,Mprtfnm,           //~v627R~
#ifdef W32UNICODE                                                  //~vafaI~
    	Mprttype=prtgetscrdata(0,Mwwscrprt,&pcw,&pfh,Mprtfnm,MprtfnmW,sizeof(MprtfnmW),//~vafaI~
#else                                                              //~vafaI~
    	Mprttype=prtgetscrdata(0,Mwwscrprt,&pcw,&pfh,Mprtfnm,      //~v627I~
#endif                                                             //~vafaI~
					&totline,&Mprtmaxlrecl,&Mprtlinenosz,&Mprtcmaxlrecl,&Mprtlnotype);//~2C07R~
#ifdef UTF8UCS2                                                    //~va20I~
        swutf8file=WXEPRINT_UTF8MODE();                            //~va20I~
#endif                                                             //~va20I~
    	if (Mprttype>0)	//file/dir screen                          //~2B30R~
    	{                                                          //~2B09M~
            Mprtdatamaxcol=                                        //~v51hI~
            Mprtcmaxcol=Mprtcol;                                   //~2B09R~
            Mprtdatamaxrow=                                        //~v51hI~
            Mprtcmaxrow=Mprtrow;                                   //~2B09R~
            if (Mprttype==PRTTYPE_VHEXTEXT                         //~v627R~
            ||  Mprttype==PRTTYPE_VHEXHHEX                         //~va49I~
            ||  Mprttype==PRTTYPE_VHEXBIN)                         //~v627R~
            {                                                      //~v627I~
                if (Mprtdatamaxrow>=3)                             //~v627I~
                    Mprtdatamaxrow=(Mprtdatamaxrow/3)*3;    //multiple of 3 line//~v627R~
            }                                                      //~v627I~
            if (Mlinenumber)                                       //~2B17I~
                linenofw=Mprtlinenosz+1;                           //~2B17I~
            else                                                   //~2B17I~
                linenofw=0;                                        //~2B17I~
//          if (!Mprtcol || !Mprtrow)                              //~v51hR~
            if (!Mprtcol || !Mprtrow || Mchkpfontsz)               //~v51hI~
            {                                                      //~2B09R~
                prtgetformsz(Mlandscape,Mformtype,&formw,&formh);  //~2B09R~
                formw-=max(Mmarginl,MARGIN_FORM_CLIP)+max(Mmarginr,MARGIN_FORM_CLIP);//~2B23R~
                formh-=max(Mmargint,MARGIN_FORM_CLIP)+max(Mmarginb,MARGIN_FORM_CLIP);//~2B23R~
		        if (M2p)                                           //~2B09I~
        		    col2p=Mprt2pcol;                               //~2B09R~
        		else                                               //~2B09I~
            		col2p=0;                                       //~2B09I~
//                if (Mchkpfontsz)                                 //~v51hR~
//                    pfontsz=(Mpfontszw<<16)|Mpfontszh;           //~v51hR~
//                else                                             //~v51hR~
//                    pfontsz=0;                                   //~v51hR~
//              if (prtajustcolrow(Mprttype,formw,formh,Mheader+Mfooter,Mcellw,Mcellh,//~v51hR~
                if (prtajustcolrow(Mprttype,formw,formh,Mheader+Mfooter,Mdrawcellw,Mdrawcellh,//~v51hR~
//                              Mprtcmaxlrecl,totline,linenofw,col2p,&Mprtcmaxcol,&Mprtcmaxrow);//~v51hR~
                                Mprtcmaxlrecl,totline,linenofw,col2p,&Mprtcmaxcol,&Mprtcmaxrow,//~v51hR~
//								Mchkpfontsz,&Mprtdatamaxcol,&Mprtdatamaxrow))//~v62WR~
								Mchkpfontsz,Mpcellszhmax,&Mprtdatamaxcol,&Mprtdatamaxrow))//~v62WI~
                    return FALSE;//skip print by parm err          //~v51hI~
            }                                                      //~2B09R~
//  		maxpage=wxe_prtgetmaxpage(pfh,&Mprtcmaxlrecl,&Mprtcmaxcol,Mprtcmaxrow,&totrow);//~v51hR~
//     		maxpage=wxe_prtgetmaxpage(pfh,&Mprtcmaxlrecl,&Mprtcmaxcol,//~v627R~
     		maxpage=wxe_prtgetmaxpage(pcw,pfh,&Mprtcmaxlrecl,&Mprtcmaxcol,//~v627I~
										&Mprtdatamaxcol,Mprtdatamaxrow,&totrow);//~v51hR~
            switch(Mprtlnotype)                                    //~2C07R~
            {                                                      //~2B30I~
            case PRTLNOTYPE_HEX:                                   //~2C07R~
                sprintf(Mprtlinenoedit,"%%0%dX ",Mprtlinenosz);    //~2B30I~
                break;                                             //~2B30I~
            case PRTLNOTYPE_hex:                                   //~2C07I~
                sprintf(Mprtlinenoedit,"%%0%dx ",Mprtlinenosz);    //~2B30I~
                break;                                             //~2B30I~
            default:                                               //~2B30I~
                sprintf(Mprtlinenoedit,"%%0%dd ",Mprtlinenosz);    //~2B30R~
            }                                                      //~2B30I~
            Mprtlinenosz++;                                        //~2B04I~
            if (Mprttype==PRTTYPE_DIR)                             //~2C07I~
            {                                                      //~2C08I~
		        len=Mprtmaxlrecl;	//dirlist entry full size      //~2C08R~
		        len2=len+len;        //for dbcs chk                //~2C08I~
            }                                                      //~2C08I~
            else                                                   //~2C07I~
            {                                                      //~2C08I~
		        len2=len=Mprtcmaxcol;	//len2:for lineworksz,len:for 2p work sz//~2C07R~
                switch(Mprttype)                                   //~2C08R~
                {                                                  //~2C08R~
                case PRTTYPE_VHEXTEXT:                             //~v627R~
                case PRTTYPE_VHEXBIN:                              //~v627I~
                    len2+=len+len;  //3line mode(data+hex1+hex2)   //~v627I~
#ifdef UTF8UCS2                                                    //~va20I~
            		if (swutf8file)                                //~va20R~
                    	len2+=len;	//dbcs                         //~va20R~
                    else                                           //~va80R~
					if (WXEPRINT_EBCBYUCS())                       //~va80R~
                    	len2+=len;	//dbcs                         //~va80R~
#endif                                                             //~va20I~
                    break;                                         //~v627I~
                case PRTTYPE_BIN:                                  //~2C08R~
                    len2+=len;  //data and dbcs for tabdisplay call//~2C08R~
                    break;                                         //~2C08R~
                case PRTTYPE_HEX:                                  //~2C08R~
                case PRTTYPE_VHEXHHEX:  //hhex+vhex                //~va49I~
                    len2+=(Mprtmaxlrecl+Mprtmaxlrecl)+Mprtmaxlrecl;//hexeditwk+dbcs//~2C08R~
                    break;                                         //~2C08R~
#ifdef UTF8UCS2                                                    //~va20I~
                default:                                           //~va20I~
            		if (swutf8file)                                //~va20I~
                    	len2+=len;       //dbcs                    //~va20I~
                    else                                           //~va80R~
					if (WXEPRINT_EBCBYUCS())                       //~va80R~
                    	len2+=len;       //dbcs                    //~va80R~
#endif                                                             //~va20I~
                }                                                  //~2C08R~
            }                                                      //~2C08I~
            len+=linenofw;                                         //~2B30R~
            len2+=linenofw; 	//line work sz                     //~2B30I~
//          Mprtlinework=(char*)umemalloc(len2);                   //~2B30R~//~va80R~
            Mprtlinework=(char*)umemalloc(len2+allowance);         //~va80R~
UTRACEP("Mprtlinework len=x%x,len2=x%x,addr=%p,swbyucs=%x\n",len,len2,Mprtlinework,WXEPRINT_EBCBYUCS());//~va80R~
            if (M2p)	                                           //~2B04I~
            {                                                      //~2B17I~
            	len+=len+Mprt2pcol;                                //~2B17R~
#ifdef UTF8UCS2                                                    //~va20M~
	          	len+=len;	//dbcstbl                              //~va20I~
#endif                                                             //~va20M~
                len*=(Mprtcmaxrow+(Mheader+Mfooter)*2);            //~2B17R~
                Mprtpagework=(char*)umemalloc(len);                //~2B17I~
            	maxpage=(maxpage+1)>>1;                            //~2B04I~
            }                                                      //~2B17I~
            wxe_prtgetftime(pfh,Mprtftime,Mprtsystime);            //~2B09R~
    	}                                                          //~2B02I~
//      else                                                       //~v65hR~
//      if (Mprttype==PRTTYPE_HCOPY)	//pannel                   //~v65hR~
//      	Mhcopysw=1;                                            //~v65hR~
        else                    //file in bin/hex mode             //~2B10I~
        	rc=FALSE;           //bypass print                     //~2B10I~
    }                                                              //~2B07I~
//  if (pInfo)                                                     //~@@@@R~
//  {                                                              //~@@@@R~
//      pInfo->SetMaxPage(maxpage);         //set at printdialog   //~@@@@R~
//      prtformsetup(formid,Mlandscape);    //set at printdialog   //~@@@@R~
    Mformid=formid;     //use at printdialog                       //~@@@@I~
//  	usetupprinter(formid,Mlandscape);                          //~3116R~
//  }                                                              //~@@@@R~
    Mprtmaxpage=maxpage;                                           //~2B02I~
    if (Mhcopysw)                                                  //~2B23R~
    {                                                              //~vafaI~
		strcpy(Mprtfnm,PRTSCRID);                                  //~2B09R~
#ifdef W32UNICODE                                                  //~vafaI~
		strcpyW_ASCII(MprtfnmW,PRTSCRID);                          //~vafaI~
#endif                                                             //~vafaI~
    }                                                              //~vafaI~
//  Mpdoc->SetTitle(Mprtfnm);    //set at printdialog              //~@@@@R~
	return rc;                                                     //~2B10R~
}//onprepareprinting                                               //~2B02R~
//===============================================================================//~2B24I~
//printer form setup on m_hDevMode gotten by app class             //~3116R~
//	form size and orientation                                      //~2B24I~
//===============================================================================//~2B24I~
//void CWxemain::prtformsetup(int Pformid,int Plandscape)          //~@@@@R~
void CWxemain::prtformsetup(LPDEVMODE Ppdevmode,int Pformid,int Plandscape)//~@@@@I~
{                                                                  //~2B24I~
//  CWxeApp *papp;                                                 //~@@@@R~
//  DEVMODE *pdm,**ppdm;                                           //~@@@@R~
    DEVMODE *pdm;                                                  //~@@@@I~
//**************************                                       //~2B24I~
//no effect because devmode is freed and recreate each time        //~2B24I~
//    papp=(CWxeApp*)AfxGetApp();                                  //~@@@@R~
//    ppdm=(DEVMODE**)(papp->Mppdevmode);                          //~@@@@R~
//    if (!ppdm)                                                   //~@@@@R~
//        return;                                                  //~@@@@R~
//    pdm=*ppdm;             //m_hDevMode                          //~@@@@R~
//    if (!pdm)                                                    //~@@@@R~
//        return;                                                  //~@@@@R~
//    pdm=(LPDEVMODE)GlobalLock(pdm); //handle to addr             //~@@@@R~
    pdm=Ppdevmode;                                                 //~@@@@I~
    pdm->dmFields|=DM_ORIENTATION;                                 //~2B24I~
    if (Plandscape)                                                //~2B24I~
    	pdm->dmOrientation=DMORIENT_LANDSCAPE;                     //~2B24I~
    else                                                           //~2B24I~
    	pdm->dmOrientation=DMORIENT_PORTRAIT;                      //~2B24I~
                                                                   //~2B24I~
    if (Pformid)                                                   //~2B24I~
    {                                                              //~2B24I~
    	pdm->dmFields|=DM_PAPERSIZE;                               //~2B24I~
//  	pdm->dmPaperSize=Pformid;                                  //~2B24I~//~vb2JR~
    	pdm->dmPaperSize=(short)Pformid;                           //~vb2JI~
    }                                                              //~2B24I~
    return;                                                        //~2B24I~
}//prtformsetup                                                    //~2B24I~
//===============================================================================//~2B07I~
//get print data for current scr                                   //~2B10R~
//maxlrecl :output max lrecl of plh                                //~2C07I~
//cmaxlrecl:output max lrecl to be printed ajusted for bin file by width open parm//~2C07I~
//ret :scr type 'F':fie,'D':dir,-1:other panel                     //~2B07I~
//===============================================================================//~2B07I~
//int CWxemain::prtgetscrdata(int Phcopysw,BOOL Pwwscrprt,void **Pppfh,char *Poutfnm,//~v627R~
#ifdef W32UNICODE                                                  //~vafaI~
int CWxemain::prtgetscrdata(int Phcopysw,BOOL Pwwscrprt,void **Pppcw,void **Pppfh,char *Poutfnm,UWCH *PoutfnmW,int Pbuffsz,//~vafaR~
#else                                                              //~vafaI~
int CWxemain::prtgetscrdata(int Phcopysw,BOOL Pwwscrprt,void **Pppcw,void **Pppfh,char *Poutfnm,//~v627I~
#endif                                                             //~vafaI~
					int *Pptotlineno,int *Ppmaxlrecl,int *Pplinenodigit,int *Ppcmaxlrecl,int *Pplnotype)//~2C07R~
{                                                                  //~2B07I~
//  int  maxlen,totline=0,scrtype,linenosz,pfhwidth;                 //~2C01R~//~vafaR~
    int  maxlen=0,totline=0,scrtype,linenosz=0,pfhwidth=0;         //~vafaI~
//************************************                             //~2B07I~
    *Pplnotype=0;                                                  //~2C07I~
	if (Phcopysw)                                                  //~2B24R~
    {                                                              //~v627I~
    	scrtype=PRTTYPE_HCOPY;                                     //~2B30R~
        *Pppcw=0;                                                  //~v627I~
    }                                                              //~v627I~
    else                                                           //~2B10I~
//  	scrtype=wxe_prtgetfnm(Poutfnm,Pppfh,Pplnotype);	//file/dir/screen//~v627R~
#ifdef W32UNICODE                                                  //~vafaI~
    	scrtype=wxe_prtgetfnm(Poutfnm,Pppcw,Pppfh,Pplnotype,PoutfnmW,Pbuffsz,NULL/*outucsctr*/);	//file/dir/screen//~vafaR~
#else                                                              //~vafaI~
    	scrtype=wxe_prtgetfnm(Poutfnm,Pppcw,Pppfh,Pplnotype);	//file/dir/screen//~v627I~
#endif                                                             //~vafaI~
    if (scrtype<0)                                                 //~2B07I~
    {                                                              //~2B10I~
        if (scrtype!=PRTTYPE_HCOPY)                                //~2B30R~
//      	umsgbox("Not supported edit mode");                    //~v66AR~
        	umsgbox("Not supported edit mode",MB_OK);              //~v66AI~
        else                                                       //~2B10I~
        {                                                          //~2B10I~
            *Pppfh=0;                                              //~2B10R~
            strcpy(Poutfnm,PRTSCRID);                              //~2B10R~
#ifdef W32UNICODE                                                  //~vafaI~
            strcpyW_ASCII(PoutfnmW,PRTSCRID);                      //~vafaI~
#endif                                                             //~vafaI~
//            if (Pwwscrprt)      //wiswyg                         //~2B24R~
//            {                                                    //~2B24R~
//                maxlen=GetSystemMetrics(SM_CXSCREEN);            //~2B24R~
//                maxlen/=Mcellw;                                  //~2B24R~
//                maxlen++;                                        //~2B24R~
//                totline=GetSystemMetrics(SM_CYSCREEN);           //~2B24R~
//                totline/=Mcellh;                                 //~2B24R~
//                totline++;                                       //~2B24R~
//            }                                                    //~2B24R~
//            else                                                 //~2B24R~
//            {                                                    //~2B24R~
                totline=Mscrcmaxrow;                               //~2B10R~
                maxlen=Mscrcmaxcol;                                //~2B10R~
//            }                                                    //~2B24R~
            linenosz=0;                                            //~2B10R~
        }                                                          //~2B10I~
    }                                                              //~2B10I~
    else                                                           //~2B10I~
//  	totline=wxe_prtinit(*Pppfh,&maxlen,&linenosz,&pfhwidth);   //~v627R~
    	totline=wxe_prtinit(*Pppcw,*Pppfh,&maxlen,&linenosz,&pfhwidth);//~v627R~
    *Pptotlineno=totline;                                          //~2B09I~
    *Ppmaxlrecl=maxlen;                                            //~2B09R~
    *Pplinenodigit=linenosz;                                       //~2B09I~
    if (scrtype==PRTTYPE_HEX                                       //~2C01I~
    ||  scrtype==PRTTYPE_VHEXBIN                                   //~v627I~
    ||  scrtype==PRTTYPE_VHEXHHEX                                  //~va49I~
    ||  scrtype==PRTTYPE_BIN)                                      //~2C07R~
        *Ppcmaxlrecl=pfhwidth;                                     //~2C01I~
    else                                                           //~2C01I~
        *Ppcmaxlrecl=maxlen;                                       //~2C01I~
	return scrtype;                                                //~2B07I~
}//prtgetscrdata                                                   //~2B10R~
//===============================================================================//~2B09I~
//ajust row and col by form size and cellh/cellw for the case maxcol or maxrow is 0//~2B09I~
//===============================================================================//~2B09I~
int  CWxemain::prtajustcolrow(int Pscrtype,int Pformw,int Pformh,int Phdrftr,int Pcellw,int Pcellh,//~v51hR~
							  int Pmaxlrecl,int Ptotlineno,int Plinenofw,int Pcol2p,//~v51hR~
							  int *Ppcmaxcol,int *Ppcmaxrow,int Pchkpfontsz,//~v51hR~
                              int Ppcellszhmax,                    //~v62WI~
							  int *Ppdatamaxcol,int *Ppdatamaxrow) //~v51hI~
{                                                                  //~2B09I~
//  int rc=0,logicalw,cmaxcol,cmaxrow;                             //~2B17R~//~vafhR~
    int logicalw,cmaxcol,cmaxrow;                                  //~vafhI~
    int datamaxrow,datamaxcol,fontmaxrow=0,fontmaxcol=0;           //~vafaR~
	float fprtcellh,fprtcellw;                                     //~2B17I~
    float wkf;                                                     //~v51hI~
//************************************                             //~2B09I~
    if (Pchkpfontsz>0)  //id of fixed fontsz                       //~v51hR~
    {                                                              //~v51hI~
//        pfontszw=Ppfontsz>>16;                                   //~v51hR~
//        pfontszh=Ppfontsz&0xffff;                                //~v51hR~
//        if (!pfontszw)                                           //~v51hR~
//            pfontszw=pfontszh>>1;                                //~v51hR~
        if (!Pcellw)                                               //~v51hI~
        	Pcellw=Pcellh>>1;                                      //~v51hI~
  		wkf=(float)Pformw;                                         //~v51hM~
        wkf=MM2POINT(wkf);                                         //~v51hI~
  		fontmaxcol=(int)(wkf/Pcellw);                              //~v51hR~
        fontmaxcol-=Plinenofw;   //text width                      //~v51hI~
        if (Pcol2p) //2p and inter space                           //~v51hM~
            fontmaxcol=(fontmaxcol-Pcol2p)/2;                      //~v51hI~
  		wkf=(float)Pformh;                                         //~v51hM~
        wkf=MM2POINT(wkf);                                         //~v51hI~
  		fontmaxrow=(int)(wkf/Pcellh);                              //~v51hR~
        fontmaxrow-=Phdrftr+Phdrftr;                               //~v51hI~
    }                                                              //~v51hI~
    if (Pscrtype<0)                                                //~2B10R~
    {                                                              //~2B10M~
    	datamaxcol=                                                //~v51hI~
		cmaxcol=Pmaxlrecl;                                         //~2C01R~
    	datamaxrow=                                                //~v51hI~
		cmaxrow=Ptotlineno;                                        //~2B10I~
    }                                                              //~2B10I~
    else         //file print                                      //~2B10R~
    {                                                              //~2B10I~
		cmaxcol=*Ppcmaxcol;                                        //~2B10R~
		cmaxrow=*Ppcmaxrow;                                        //~2B10R~
        if (Pchkpfontsz)	//font size parm specified             //~v51hR~
        {                                                          //~v51hI~
            if (!cmaxcol && !cmaxrow)//no col/row parm             //~v51hR~
            {                                                      //~v51hI~
            	cmaxcol=fontmaxcol;	//use count by font size       //~v51hI~
            	cmaxrow=fontmaxrow;	//use count by font size       //~v51hI~
            }                                                      //~v51hI~
        }                                                          //~v51hI~
        if (!cmaxcol)                                              //~2B10R~
        {                                                          //~2B10R~
            if (Pmaxlrecl)                                         //~2C01R~
            {                                                      //~va49I~
    			if (Pscrtype==PRTTYPE_HEX)                         //~2C07R~
		            cmaxcol=GET_HEXDISPLAYLINESZ(Pmaxlrecl);       //~2C01R~
                else                                               //~2C01I~
    			if (Pscrtype==PRTTYPE_VHEXHHEX)                    //~va49I~
		            cmaxcol=GET_HEXDISPLAYLINESZ(Pmaxlrecl); //lrecl+margin+hex part len//~va49R~
                else                                               //~va49I~
                	cmaxcol=Pmaxlrecl;                             //~2C01R~
            }                                                      //~va49I~
            else                                                   //~2B10R~
                cmaxcol=DEF_COLFORLRECL0;                          //~2B10R~
        }                                                          //~2B10R~
        if (!cmaxrow)                                              //~2B10R~
        {                                                          //~2B10R~
            logicalw=cmaxcol+Plinenofw;   //text width             //~2B17R~
            if (Pcol2p) //2p and inter space                       //~2B10R~
                logicalw+=logicalw+Pcol2p;                         //~2B17R~
            fprtcellw=(float)Pformw/logicalw;//cell width by mm    //~2B23R~
//          fprtcellh=fprtcellw*Mcellh/Mcellw;              //cell height by mm//~v51hR~
            fprtcellh=fprtcellw*Pcellh/Pcellw;              //cell height by mm//~v51hI~
			wkf=MM2POINT(fprtcellh);	//cellh by point           //~v62WI~
	        if (Ppcellszhmax && wkf>Ppcellszhmax) //push under max cell height//~v62WR~
            {                                                      //~v62WI~
    			if (!Pchkpfontsz   //font size parm not specified  //~v62WI~
				&&  *Ppcmaxcol==0)	//col not specified            //~v62WI~
//get col/max by maxfontsz                                         //~v62WI~
//  				return prtajustcolrow(Pscrtype,Pformw,Pformh,Phdrftr,Pcellw,Ppcellszhmax,//~v65fR~
    				return prtajustcolrow(Pscrtype,Pformw,Pformh,Phdrftr,Ppcellszhmax/2,Ppcellszhmax,//~v65fI~
							  Pmaxlrecl,Ptotlineno,Plinenofw,Pcol2p,//~v62WI~
							  Ppcmaxcol,Ppcmaxrow,1,	//Pchkfontsz=1//~v62WR~
                              Ppcellszhmax,                        //~v62WI~
							  Ppdatamaxcol,Ppdatamaxrow);          //~v62WI~
            }                                                      //~v62WI~
            cmaxrow=(int)(Pformh/fprtcellh);                       //~2B23R~
            cmaxrow-=Phdrftr+Phdrftr;                              //~2B10R~
UTRACEP("ajust logw=%d,cellw=%d,cellh=%d,form=(%d,%d)\n",          //~v51hR~
            logicalw,Pcellh,Pcellw,Pformw,Pformh);                 //~v51hR~
			if (cmaxrow<=0 && *Ppcmaxcol==0)	//calculated fontcellh is too large//~v62MI~
            {                                                      //~v62MI~
            	fprtcellh=(float)Pformh/(Phdrftr+Phdrftr+1);	//minimum 1//~v62WR~
            	fprtcellw=fprtcellh*Pcellw/Pcellh;                 //~v62MI~
            	logicalw=(int)(Pformw/fprtcellw);                  //~v62MR~
            	if (Pcol2p) //2p and inter space                   //~v62MI~
                	logicalw=(logicalw-Pcol2p)/2;                  //~v62MI~
                logicalw=max(Plinenofw+1,logicalw);                //~v62WI~
            	cmaxcol=logicalw-Plinenofw;                        //~v62MI~
            	cmaxrow=1;                                         //~v62WR~
            }                                                      //~v62MI~
        }                                                          //~2B10R~
        datamaxrow=cmaxrow;                                        //~v51hI~
        datamaxcol=cmaxcol;                                        //~v51hI~
    }                                                              //~2B10I~
    if (Pchkpfontsz)   //font size parm specified                  //~v51hR~
    {                                                              //~v51hI~
        if (cmaxcol<=fontmaxcol) //small font                      //~v51hR~
        {                                                          //~v51hI~
            datamaxcol=cmaxcol; //data count                       //~v51hI~
            cmaxcol=fontmaxcol; //page width                       //~v51hI~
        }                                                          //~v51hI~
        else                                                       //~v51hI~
            datamaxcol=cmaxcol=fontmaxcol;	//use by font sz       //~v51hI~
        if (cmaxrow<=fontmaxrow)  //small font                     //~v51hR~
        {                                                          //~v51hI~
            datamaxrow=cmaxrow; //data count                       //~v51hI~
            cmaxrow=fontmaxrow; //page width                       //~v51hI~
        }                                                          //~v51hI~
        else                                                       //~v51hI~
            datamaxrow=cmaxrow=fontmaxrow;	//use by font sz       //~v51hI~
    }                                                              //~v51hI~
UTRACEP("data=(%d,%d),page=(%d,%D)\n",datamaxcol,datamaxrow,cmaxcol,cmaxrow);//~v51hI~
    if (cmaxcol<=0||cmaxrow<=0||datamaxcol<=0||datamaxrow<=0)      //~v51hR~
    {                                                              //~v51hM~
    	uerrmsgbox("invalid Col,Row or Fontsz parm",0);            //~v51hR~
        return 4;                                                  //~v51hM~
    }                                                              //~v51hM~
    *Ppcmaxcol=cmaxcol;                                            //~2B09M~
    *Ppcmaxrow=cmaxrow;                                            //~2B09R~
    *Ppdatamaxcol=datamaxcol;                                      //~v51hI~
    if (Pscrtype==PRTTYPE_VHEXTEXT                                 //~v627I~
    ||  Pscrtype==PRTTYPE_VHEXHHEX                                 //~va49I~
    ||  Pscrtype==PRTTYPE_VHEXBIN)                                 //~v627I~
    {                                                              //~v627I~
    	if (datamaxrow>=3)                                         //~v627I~
	        datamaxrow=(datamaxrow/3)*3;	//multiple of 3 line   //~v627I~
    }                                                              //~v627I~
    *Ppdatamaxrow=datamaxrow;                                      //~v51hI~
	return 0;                                                      //~v51hR~
}//prtajustcolrow                                                  //~2B09I~
//===============================================================================//~2B09I~
//get form size                                                    //~2B09I~
//===============================================================================//~2B09I~
int CWxemain::prtgetformsz(int Plandscape,char *Pform,int *Ppw,int *Pph)//~2B09I~
{                                                                  //~2B09I~
	int ii,formw,formh,rc=0;                                       //~2B09I~
//************************************                             //~2B09I~
    for (ii=0;ii<FORM_CTR;ii++)                                    //~2B09I~
	    if (!strcmp(Sformtbl[ii],Pform))                           //~2B09I~
        	break;                                                 //~2B09I~
    if (ii>=FORM_CTR)                                              //~2B09I~
    {                                                              //~2B09I~
    	ii=FORM_DEFAULT_INDX;                                      //~2B09I~
    }                                                              //~2B09I~
	rc=Sdmformtype[ii];                                            //~2B24I~
    if (Plandscape)                                                //~2B09I~
    {                                                              //~2B09I~
	    formw=Sformsz[ii][1];                                      //~2B09I~
		formh=Sformsz[ii][0];                                      //~2B09I~
    }                                                              //~2B09I~
    else                                                           //~2B09I~
    {                                                              //~2B09I~
	    formw=Sformsz[ii][0];                                      //~2B09I~
		formh=Sformsz[ii][1];                                      //~2B09I~
    }                                                              //~2B09I~
    *Ppw=formw;                                                    //~2B09I~
    *Pph=formh;                                                    //~2B09I~
	return rc;                                                     //~2B09I~
}//prtgetformsz                                                    //~2B09I~
//===============================================================================//~2B09I~
//get form type tbl addr                                           //~2B09I~
//===============================================================================//~2B09I~
int CWxemain::prtgetformtype(char ***Ppformtbl)                    //~2B09R~
{                                                                  //~2B09I~
	*Ppformtbl=Sformtbl;                                           //~2B09I~
    return FORM_CTR;                                               //~2B09I~
}//prtgetformtype                                                  //~2B09I~
//===============================================================================//~2B04I~
//called once at last of print after enddoc                        //~2B04I~
//parm:pInfo is 0 when preview call                                //~2B24I~
//===============================================================================//~2B04I~
void CWxemain::onendprinting(CDC *pDC,CPrintInfo* pInfo)           //~2B04I~
{                                                                  //~2B04I~
//  afterprint();                                                  //~v53qI~//~va8aR~
  if (pInfo)                                                       //~va8aI~
    afterprint(1);     //endprint                                  //~va8aI~
  else                //preview                                    //~va8aI~
    afterprint(0);                                                 //~va8aI~
}//onendprinting                                                   //~v53qI~
//===============================================================================//~v53qI~
//free resource after printed                                      //~v53qI~
//opt: 1:endprint,2:cancel print,0:before print                    //~va8aI~
//===============================================================================//~v53qI~
//void CWxemain::afterprint(void)                                    //~v53qI~//~va8aR~
void CWxemain::afterprint(int Popt)                                //~va8aI~
{                                                                  //~v53qI~
//************************************                             //~2B04I~
	if (Mprtlinework)                                              //~2B04R~
    {                                                              //~2B04I~
        umemfree(Mprtlinework);                                    //~2B04I~
	    Mprtlinework=0;                                            //~2B04I~
    }                                                              //~2B04I~
	if (Mprtpagework)                                              //~2B17I~
    {                                                              //~2B17I~
        umemfree(Mprtpagework);                                    //~2B17I~
	    Mprtpagework=0;                                            //~2B17I~
    }                                                              //~2B17I~
	if (Mpprtfont)                                                 //~v51hI~
    {                                                              //~v51hI~
    	Mpprtfont->DeleteObject();                                 //~v51hI~
	    Mpprtfont=0;                                               //~v51hI~
    }                                                              //~v51hI~
    if (Popt & 0x03)                                               //~va8aI~
    {                                                              //~va8aI~
	    wxe_endprint(0);                                           //~va8aI~
    	Mpview->Invalidate(FALSE);                                 //~va8aI~
    }                                                              //~va8aI~
	return;                                                        //~2B04I~
}//afterprint                                                      //~v53qR~
//===============================================================================//~2B02I~
//called first of each page start                                  //~2B02R~
//warning:twice called by the reason odf MFC                       //~2B02I~
//===============================================================================//~2B02I~
//void CWxemain::prtpreparedc(CDC *Pdc,CPrintInfo* pInfo)          //~@@@@R~
void CWxemain::prtpreparedc(CDC *Pdc,CPrintInfo* pInfo,int Ppage)  //~@@@@I~
{                                                                  //~2B02I~
//************************************                             //~2B02I~
//  Mprtcurpage=pInfo->m_nCurPage;                                 //~@@@@R~
    Mprtcurpage=Ppage;                                             //~@@@@I~
	return;                                                        //~2B02I~
}//prtpreparedc                                                    //~2B02I~
//===============================================================================//~2A20I~
//print cmd                                                        //~2A20I~
//===============================================================================//~2A20I~
int  CWxemain::onprint(CDC *Pdc,CWxeDoc *Pdoc)                     //~2A20I~
{                                                                  //~2A20I~
//************************************                             //~2A20I~
	if (Mhcopysw)	//printscreen                                  //~2B23R~
//      return prtscr(Pdc,Mpfont,0,0,0,0);                         //~v51hR~
        return prtscr(Pdc,Mpprtfont,0,0,0,0);                      //~v51hI~
//  return prtfile(Pdc,Mpfont,0,0,0,0);	//0:not preview            //~v51hR~
    return prtfile(Pdc,Mpprtfont,0,0,0,0);	//0:not preview        //~v51hR~
}//onprint                                                         //~2B02R~
//===============================================================================//~2B02I~
//screen print                                                     //~2B02R~
//===============================================================================//~2B02I~
int  CWxemain::prtscr(CDC *Pdc,CFont *Ppfont,                      //~2B24R~
			int Ppreviewwidth,int Ppreviewheight,int Pprevieworgx,int Pprevieworgy)//~2B24I~
{                                                                  //~2B02I~
//  CFont *poldfont;                                               //~@@@@R~
    HFONT  poldfont;                                               //~@@@@I~
    int svcellh,svcellw;                                           //~v65gR~
//************************************                             //~2B02I~
    Mhcopysw=0;                                                    //~2B23R~
    if (!Mscrcmaxrow || !Mscrcmaxcol)                              //~2B02I~
    	return 4;                                                  //~2B02I~
	prtviewporthcopy(Pdc,Ppreviewwidth,Ppreviewheight,Pprevieworgx,Pprevieworgy);//~2B24R~
//  poldfont=Pdc->SelectObject(Ppfont);   //inner grid;save cuurrent//~@@@@R~
    poldfont=Pdc->SelectFont(HFONT(*Ppfont));   //inner grid;save cuurrent//~@@@@I~
    Mfulldrawsw=1;                                                 //~2B02I~
    svcellh=Mcellh,svcellw=Mcellw;                                 //~v65gR~
    Mcellh=Mdrawcellh,Mcellw=Mdrawcellw;                           //~v65gR~
	scrupdate(Pdc,1);                                              //~2B02I~
    Mcellh=svcellh,Mcellw=svcellw;                                 //~v65gR~
    if (poldfont)                                                  //~2B23I~
//  	Pdc->SelectObject(poldfont);                               //~@@@@R~
    	Pdc->SelectFont(poldfont);                                 //~@@@@I~
	return 0;                                                      //~2B02I~
}//prtscr                                                          //~2B02I~
//===============================================================================//~2A27I~
//setup viewport for hcopy                                         //~2B24R~
//===============================================================================//~2A27I~
void  CWxemain::prtviewporthcopy(CDC* Pdc,                         //~2B24R~
			int Ppreviewwidth,int Ppreviewheight,int Pprevieworgx,int Pprevieworgy)//~2B24I~
{                                                                  //~2A27I~
    RECT rect;                                                     //~2B23I~
	int prnh,prnw,scrw,scrh,orgx,orgy;                             //~2B23R~
	float fhbwp,fhbws;                                             //~2B23R~
//************************************                             //~2A27M~
//  int mapmode=Pdc->GetMapMode();                                 //~2B10R~
//  CPoint cp=Pdc->GetWindowOrg();                                 //~2B10R~
//  CPoint cp2=Pdc->GetViewportOrg();                              //~2B10R~
//  CSize  cs=Pdc->GetWindowExt();                                 //~2B10R~
//  CSize  cs2=Pdc->GetViewportExt();                              //~2B10R~
//  if (Mfullpage)                                                 //~v51hR~
    if (Mfullpage||Mchkpfontsz)                                    //~v51hI~
    	Pdc->SetMapMode(MM_ANISOTROPIC);                           //~2B30R~
    else                                                           //~2B30I~
    	Pdc->SetMapMode(MM_ISOTROPIC);                             //~2B30I~
    if (Mwwscrprt)          //Wysiwig print                        //~2B24I~
    {                                                              //~2B24I~
        scrh=Mwinexth;  //range of logical axis by max display size//~2B24I~
        scrw=Mwinextw;  //range of logical axis by max display size//~2B24I~
    }                                                              //~2B24I~
    else                                                           //~2B24I~
    {                                                              //~2B24I~
//      scrh=Mscrcmaxrow*Mcellh;    //range of logical axis by max display size//~v51hR~
//      scrw=Mscrcmaxcol*Mcellw;    //range of logical axis by max display size//~v51hR~
        scrh=Mscrcmaxrow*Mdrawcellh;    //range of logical axis by max display size//~v51hR~
        scrw=Mscrcmaxcol*Mdrawcellw;    //range of logical axis by max display size//~v51hR~
    }                                                              //~2B24I~
UTRACEP("prtscr scr w=%d,h=%d\n",scrw,scrh);                       //~2B24I~
    Pdc->SetWindowOrg(0,0);                                        //~2B24I~
    Pdc->SetWindowExt(scrw,scrh);   //range of logical axis by max display size//~2B24I~
    if (Ppreviewwidth) //preview                                   //~2B24I~
    {                                                              //~2B24I~
        prnw=Ppreviewwidth;                                        //~2B24I~
        prnh=Ppreviewheight;                                       //~2B24I~
        orgx=Pprevieworgx;                                         //~2B24R~
        orgy=Pprevieworgy;                                         //~2B24I~
    }                                                              //~2B24I~
    else                                                           //~2B24I~
    {                                                              //~2B24I~
        rect.left  =Mmarginl;                                      //~2B24R~
        rect.top   =Mmargint;                                      //~2B24R~
        rect.right =Mmarginr;                                      //~2B24R~
        rect.bottom=Mmarginb;                                      //~2B24R~
        prtmarginrect(Pdc,&rect);                                  //~2B24R~
        orgx=rect.left;                                            //~2B24R~
        orgy=rect.top;                                             //~2B24R~
        prnw=rect.right-rect.left;                                 //~2B24R~
        prnh=rect.bottom-rect.top;                                 //~2B24R~
    }//preview or not                                              //~2B24I~
//  if (Mwwscrprt)          //Wysiwig print                        //~v65hR~
    if (Mwwscrprt||!Mfullpage||Mchkpfontsz) //Wysiwig print        //~v65hR~
    {                                                              //~2B30I~
        fhbwp=(float)prnh/prnw;                                    //~2B30I~
        fhbws=(float)scrh/scrw;                                    //~2B30I~
        if (fhbwp<fhbws)      //printer is wider                   //~2B30I~
            prnw=prnh*scrw/scrh;                                   //~2B30I~
        else                    //screen is wider                  //~2B30I~
            prnh=prnw*scrh/scrw;                                   //~2B30I~
    }                                                              //~2B30I~
    if (Ppreviewwidth) //preview                                   //~2B30I~
    {                                                              //~2B30I~
    	prnw=prnw*100/Mscrcmaxcol*Mscrcmaxcol/100;	//protect right cut//~2B30I~
    	prnh=prnh*100/Mscrcmaxrow*Mscrcmaxrow/100;	//protect right cut//~2B30I~
    }                                                              //~2B30I~
    else                                                           //~2B30I~
    {                                                              //~2B30I~
	    prnh=prnh/Mscrcmaxrow*Mscrcmaxrow;                         //~2B30I~
    	prnw=prnw/Mscrcmaxcol*Mscrcmaxcol;                         //~2B30I~
    }//preview or not                                              //~2B30I~
UTRACEP("ww prt ajust col=%d,row=%d,w=%d,h=%d\n",Mscrcmaxcol,Mscrcmaxrow,prnw,prnh);//~2B23R~
//  prnw-=PRINT_MARGIN_RIGHT_SAFETY;                               //~2B17R~
    Pdc->SetViewportExt(prnw,prnh);                                //~2A27R~
    Pdc->SetViewportOrg(orgx,orgy);//map origin on physical axis   //~2B23R~
//  int mapmode3=Pdc->GetMapMode();                                //~2B10R~
//  CPoint cp3=Pdc->GetWindowOrg();                                //~2B10R~
//  CPoint cp32=Pdc->GetViewportOrg();                             //~2B10R~
//  CSize  cs3=Pdc->GetWindowExt();                                //~2B10R~
//  CSize  cs32=Pdc->GetViewportExt();                             //~2B10R~
    return;                                                        //~2A27I~
}//prtviewporthcopy                                                //~2B24R~
//===============================================================================//~2B02I~
//file print                                                       //~2B02I~
//===============================================================================//~2B02I~
int  CWxemain::prtfile(CDC *Pdc,CFont *Ppfont,                     //~2B23R~
		int Ppreviewwidth,int Ppreviewheight,int Pprevieworgx,int Pprevieworgy)//~2B23I~
{                                                                  //~2B02I~
	char *pdata,*pagewk,*pagewk2,*linewk;                          //~2B24R~
	int  svch,len,ii,jj,yy,yy0,pos,pos2,rc=0,logicalw,logicalh,lrecl;//~2C07R~//~vafaR~
    int  kk;                                                       //~v627I~
	int  pos2px,pos2px0=0,curpage,skiplineno,posyfooter,previewsw;   //~2B24R~//~vafaR~
	int  swhexlineno=0;                                            //~2C07R~
    int  datalen;                                                  //~v627I~
    char footer[16];                                               //~2B02I~
    char footerp[16];                                              //~2B02I~
//  CFont *poldfont;                                               //~@@@@R~
    HFONT  poldfont;                                               //~@@@@I~
//	TEXTMETRIC  metric;int rc2;                                    //~2C07R~
#ifdef UTF8UCS2                                                    //~va20I~
//  int swutf8file,linenofldsz,dbcsoffspgwk,dbcsoffslinewk=0,logicalwu8,vhexlen,pos2px0u8;//~va20R~//~va80R~//~vafaR~
    int swutf8file,linenofldsz=0,dbcsoffspgwk=0,dbcsoffslinewk=0,logicalwu8=0,vhexlen,pos2px0u8=0;//~vafaI~
    char *pc,*pdbcs;                                               //~va20R~
    int rowlen[PRINTROW_MAX][2];                                   //~va20I~
    int rowlenhhexlrecl[PRINTROW_MAX][2]; //m2p lrecl of hhex mode for ebcdic file dd fmt//~va80I~
#endif                                                             //~va20I~
    int swebcbyucs,swucsprint,opttow,hhexlrecl;                    //~va80R~
#ifdef W32UNICODE                                                  //~vafaI~
	int fnmlclen=0;                                                //~vafaR~
#endif                                                             //~vafaI~
//************************************                             //~2B02I~
    if (Mprtlnotype==PRTLNOTYPE_HEX                                //~2C07I~
    ||  Mprtlnotype==PRTLNOTYPE_hex)                               //~2C07I~
        swhexlineno=1;                                             //~2C07M~
//        Pdc->GetTextMetrics(&metric);                            //~2B30R~
//UTRACEP("textmetric h=%d,avw=%d,maxw=%d\n",                      //~2B30R~
//                metric.tmHeight,metric.tmAveCharWidth,metric.tmMaxCharWidth);//~2B30R~
//      Pdc->GetOutputTextMetrics(&metric);                        //~2C07R~
//UTRACEP("outtextmetric h=%d,avw=%d,maxw=%d,charset=%x,pich=%2x\n",//~2C07R~
//                metric.tmHeight,metric.tmAveCharWidth,metric.tmMaxCharWidth,metric.tmCharSet,metric.tmPitchAndFamily);//~2C07R~
//        rc2=Pdc->GetTextCharacterExtra();                        //~2C03R~
	previewsw=(Ppreviewheight!=0);                                 //~2B24I~
	prtviewportfile(Pdc,Ppreviewwidth,Ppreviewheight,Pprevieworgx,Pprevieworgy);//~2B24R~
//  poldfont=Pdc->SelectObject(Ppfont);   //inner grid;save cuurrent//~@@@@R~
    poldfont=Pdc->SelectFont(HFONT(*Ppfont));   //inner grid;save cuurrent//~@@@@R~
    if (!poldfont)                                                 //~2B23I~
    	uerrlast("SelectObject(font:prtfile)");                    //~2B23I~
    Pdc->SetTextColor(PRINT_BW_FGCOLOR);                           //~2B02M~
    Pdc->SetBkColor(PRINT_BW_BGCOLOR);                             //~2B02M~
	logicalw=Mprtcmaxcol+Mprtlinenosz*(Mlinenumber==TRUE);//line width//~2B17I~
    if (M2p)                                                       //~2B17I~
    {                                                              //~2B17I~
	    pos2px0=logicalw+Mprt2pcol;                                //~2B17R~
        logicalw=pos2px0+logicalw;	//line width                   //~2B17R~
    }                                                              //~2B17I~
#ifdef UTF8UCS2                                                    //~va20I~
	swutf8file=WXEPRINT_UTF8MODE();                                //~va20I~
	swebcbyucs=WXEPRINT_EBCBYUCS();                                //~va80R~
    swucsprint=swutf8file || swebcbyucs;	//ucs print(TextoutW)  //~va80R~
//  if (swutf8file)                                                //~va20I~//~va80R~
    if (swucsprint)                                                //~va80R~
    {                                                              //~va20I~
    	linenofldsz=Mprtlinenosz*(Mlinenumber==TRUE);              //~va20I~
		logicalwu8=Mprtcmaxcol+linenofldsz;                        //~va20R~
        dbcsoffspgwk=dbcsoffslinewk=logicalwu8;//line width        //~va20R~
        if (Mprttype==PRTTYPE_VHEXTEXT                             //~va20I~
        ||  Mprttype==PRTTYPE_VHEXBIN)                             //~va20I~
        	dbcsoffslinewk+=Mprtcmaxcol*2;                         //~va20R~
        else                                                       //~va80I~
		if (swebcbyucs && Mprttype==PRTTYPE_VHEXHHEX)  //hhex+vhex for EBC file//~va80I~
        	dbcsoffslinewk+=Mprtcmaxcol*2;                         //~va80I~
        if (M2p)                                                   //~va20I~
        {                                                          //~va20I~
        	logicalwu8=dbcsoffspgwk+Mprtcmaxcol;	//half         //~va20R~
		    pos2px0u8=logicalwu8+Mprt2pcol;                        //~va20R~
        	logicalwu8+=pos2px0u8;                                 //~va20R~
        }                                                          //~va20I~
    }                                                              //~va20I~
#endif                                                             //~va20I~
    yy=0;                                                          //~2B03I~
    logicalh=0;                                                    //~2B17I~
    pagewk=Mprtpagework;                                           //~2B17I~
    if (Mheader)                                                   //~2B03I~
    {                                                              //~2B03I~
		len=strlen(Mprtfnm);                                       //~2B03R~
        len=min(len,logicalw);                                     //~2B17R~
        if (M2p)                                                   //~2B17I~
        	linewk=pagewk;                                         //~2B24I~
        else                                                       //~2B24I~
        	linewk=Mprtlinework;                                   //~2B24I~
        memset(linewk,' ',logicalw);                               //~2B24R~
        memcpy(linewk,Mprtfnm,len);                                //~2B24R~
#ifdef W32UNICODE                                                  //~vafaI~
		fnmlclen=len;                                              //~vafaI~
#endif                                                             //~vafaI~
        if (Mfiletime)                                             //~2B03I~
        {                                                          //~2B04I~
            pos=(len+4);                                           //~2B04I~
            len=strlen(Mprtftime);                                 //~2B04I~
            len=min(len,logicalw-pos);                             //~2B17R~
            if (len>0)                                             //~2B04I~
        		memcpy(linewk+pos,Mprtftime,len);                  //~2B24R~
        }                                                          //~2B04I~
        if (!M2p)                                                  //~2B24I~
        {                                                          //~vafaI~
#ifdef W32UNICODE                                                  //~vafaI~
          if (!previewsw)                                          //~vafaI~
			prttextoutwHeader(Pdc,yy,linewk,logicalw,0,fnmlclen,MprtfnmW);//~vafaR~
          else                                                     //~vafaI~
#endif                                                             //~vafaI~
			prttextout(previewsw,Pdc,yy,linewk,logicalw);          //~2B24M~
        }                                                          //~vafaI~
//      yy+=Mcellh+Mcellh;                                         //~v51hR~
        yy+=Mdrawcellh+Mdrawcellh;                                 //~v51hR~
        logicalh=2;                                                //~2B04I~
        if (M2p)                                                   //~2B17I~
        {                                                          //~2B17I~
        	pagewk+=logicalw;                                      //~2B17R~
        	memset(pagewk,' ',logicalw);                           //~2B17R~
        	pagewk+=logicalw;                                      //~2B17R~
        }                                                          //~2B17I~
    }                                                              //~2B03I~
    yy0=yy;                                                        //~2B04I~
    pagewk2=pagewk;		//after header                             //~2B17I~
    pos2px=0;                                                      //~2B17R~
//  posyfooter=logicalh+Mprtcmaxrow+1;                             //~v51hR~
    posyfooter=logicalh+Mprtdatamaxrow+1;                          //~v51hI~
    for (jj=0;jj<2;jj++)	//for 2p                               //~2B04I~
    {                                                              //~2B04I~
//      for (ii=0,yy=yy0;ii<Mprtcmaxrow;ii++,yy+=Mcellh)           //~v51hR~
//      for (ii=0,yy=yy0;ii<Mprtdatamaxrow;ii++,yy+=Mcellh)        //~v51hR~
        for (ii=0,yy=yy0;ii<Mprtdatamaxrow;ii++,yy+=Mdrawcellh)    //~v51hR~
        {                                                          //~2B04R~
            if (M2p)                                               //~2B04I~
            	curpage=Mprtcurpage+Mprtcurpage+jj-1;              //~2B16R~
            else                                                   //~2B04I~
	        	curpage=Mprtcurpage;                               //~2B04I~
#ifdef UTF8UCS2                                                    //~va20I~
		  if (dbcsoffslinewk)                                      //~va80I~
            pdbcs=Mprtlinework+dbcsoffslinewk;    //addr to set dir data//~va20R~
          else                                                     //~va80I~
            pdbcs=0;                                               //~va80I~
#endif                                                             //~va20I~
            if (Mlinenumber)                                       //~2C07R~
                pdata=Mprtlinework+Mprtlinenosz;    //addr to set dir data//~2C07R~
            else                                                   //~2C07R~
                pdata=Mprtlinework; //addr to set dir data         //~2C07R~
//          if ((rc=wxe_prtgetline(curpage,Mprtcmaxlrecl,Mprtcmaxrow,pdata,&lrecl,&skiplineno,&len))<0)//eof//~v51hR~
#ifdef UTF8UCS2                                                    //~va20I~
            if ((rc=wxe_prtgetline(curpage,Mprtcmaxlrecl,Mprtdatamaxrow,pdata,pdbcs,&vhexlen,&lrecl,&skiplineno,&len))<0)//eof//~va20R~
#else                                                              //~va20I~
            if ((rc=wxe_prtgetline(curpage,Mprtcmaxlrecl,Mprtdatamaxrow,pdata,&lrecl,&skiplineno,&len))<0)//eof//~v51hI~
#endif                                                             //~va20I~
                break;                                             //~2B23R~
            datalen=len;                                           //~v627I~
            if (Mlinenumber)                                       //~2B04R~
            {                                                      //~2B04R~
                Mprtclineno+=skiplineno;                           //~2B04M~
                if (rc) //cont line                                //~2B04R~
                {                                                  //~2B04R~
                    memset(Mprtlinework,' ',Mprtlinenosz);         //~2B04R~
                    *(Mprtlinework+Mprtlinenosz-2)='-'; //cont id  //~2B04R~
                }                                                  //~2B04R~
                else                                               //~2B04R~
                {                                                  //~2B04R~
                	if (!swhexlineno)                              //~2B30I~
                    	Mprtclineno++;                             //~2B30R~
					svch=*(Mprtlinework+Mprtlinenosz);	//for sprinf last null//~2B06I~
                    sprintf(Mprtlinework,Mprtlinenoedit,Mprtclineno);//~2B04R~
//  				*(Mprtlinework+Mprtlinenosz)=svch;             //~2B06I~//~vb2JR~
    				*(Mprtlinework+Mprtlinenosz)=(char)svch;       //~vb2JI~
                }                                                  //~2B04R~
                if (swhexlineno)                                   //~2B30I~
                    Mprtclineno+=lrecl;   //offset in the file     //~2C01R~
                pdata=Mprtlinework;                                //~2B16R~
				len+=Mprtlinenosz;                                 //~2B06I~
            }                                                      //~2B04R~
        	if (M2p)                                               //~2B17R~
            {                                                      //~2B17I~
            	if (!jj)	//	left half                          //~2C01R~
                {                                                  //~2B17I~
                	logicalh++;     //count line in page           //~2C01R~
#ifdef UTF8UCS2                                                    //~va20I~
//            	  if (swutf8file)                                  //~va20I~//~va80R~
              	  if (swucsprint)                                  //~va80R~
                  {                                                //~va80I~
              	  	rowlen[ii][1]=0;	//clear right half len     //~va20I~
              	  	rowlenhhexlrecl[ii][1]=0;	//clear right half len//~va80I~
                  }                                                //~va80I~
                  else                                             //~va20I~
#endif                                                             //~va20I~
                	memset(pagewk,' ',logicalw);                   //~2B17M~
                }                                                  //~2B17I~
                memcpy(pagewk+pos2px,pdata,(UINT)len);             //~2B24R~
#ifdef UTF8UCS2                                                    //~va20I~
//            if (swutf8file)                                      //~va20I~//~va80R~
              if (swucsprint)                                      //~va80R~
              {                                                    //~va20I~
              	rowlen[ii][jj]=len;                                //~va20R~
              	rowlenhhexlrecl[ii][jj]=lrecl;                     //~va80I~
//              memcpy(pagewk+pos2px+dbcsoffspgwk,pdbcs,(UINT)len);//~va20R~//~va88R~
                memcpy(pagewk+pos2px+dbcsoffspgwk,pdbcs,(UINT)lrecl);//~va88I~
                pagewk+=logicalwu8;                                //~va20I~
              }                                                    //~va20I~
              else                                                 //~va20I~
#endif                                                             //~va20I~
                pagewk+=logicalw;                                  //~2B17I~
            }                                                      //~2B17I~
            else                                                   //~2B17I~
            {                                                      //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
//            if (swutf8file)                                      //~va20I~//~va80R~
              if (swucsprint)                                      //~va80R~
              {                                                    //~va80I~
        		opttow=previewsw;                                  //~va80I~
    			if (Mprttype==PRTTYPE_HEX                          //~va80I~
    			||  Mprttype==PRTTYPE_VHEXHHEX  //hhex+vhex        //~va80I~
    			)                                                  //~va80I~
                {                                                  //~va80I~
        			opttow|=PRTTOWO_HHEX|((lrecl<<PRTTOWO_LRECLMASKSHIFT) & PRTTOWO_LRECLMASK);//~va80R~
                }                                                  //~va80I~
//  			prttextoutw(previewsw,Pdc,yy,0/*xx*/,pdata,pdbcs,len,linenofldsz);//~va20R~//~va80R~
    			prttextoutw(opttow,Pdc,yy,0/*xx*/,pdata,pdbcs,len,linenofldsz);//~va80I~
              }                                                    //~va80I~
              else                                                 //~va20I~
#endif                                                             //~va20I~
				prttextout(previewsw,Pdc,yy,pdata,len);            //~2B24I~
            }                                                      //~va20I~
            if (Mprttype==PRTTYPE_VHEXTEXT                         //~v627I~
            ||  Mprttype==PRTTYPE_VHEXHHEX  //hhex+vhex            //~va49I~
            ||  Mprttype==PRTTYPE_VHEXBIN)                         //~v627I~
            {                                                      //~v627I~
                pdata=Mprtlinework; 	//top                      //~v627I~
                for (kk=0;kk<2;kk++)                               //~v627R~
                {                                                  //~v627I~
#ifdef UTF8UCS2                                                    //~va20M~
//  		      if (swutf8file)                                  //~va20I~//~va80R~
    		      if (swucsprint)                                  //~va80R~
                  {                                                //~va20I~
                  	if (!kk)                                       //~va20I~
                		pdata+=datalen;                            //~va20R~
                    else                                           //~va20I~
                		pdata+=vhexlen;                            //~va20I~
                    len=vhexlen;                                   //~va20I~
                  }                                                //~va20I~
                  else                                             //~va20I~
#endif                                                             //~va20M~
            	  if (Mprttype==PRTTYPE_VHEXHHEX)                  //~va49I~
                  {                                                //~va49I~
                  	if (!kk)                                       //~va49I~
                		pdata+=datalen; //hhex line data length    //~va49I~
                    else                                           //~va49I~
                		pdata+=vhexlen;                            //~va49I~
                    len=vhexlen;                                   //~va49I~
                  }                                                //~va49I~
                  else                                             //~va49I~
                  {                                                //~va20I~
	                len=datalen;                                   //~v627I~
                	pdata+=len;                                    //~v627I~
                  }                                                //~va20I~
					yy+=Mdrawcellh;                                //~v627I~
					ii++;                                          //~v627I~
                    if (Mlinenumber)                               //~v627I~
                    {                                              //~v627I~
                        memset(pdata,' ',Mprtlinenosz);            //~v627I~
                        *(pdata+Mprtlinenosz-2)='.'; //hex line id //~v627I~
                        len+=Mprtlinenosz;                         //~v627I~
                    }                                              //~v627I~
                    if (M2p)                                       //~v627I~
                    {                                              //~v627I~
                        if (!jj)    //  left half                  //~v627I~
                        {                                          //~v627I~
                            logicalh++;     //count line in page   //~v627I~
#ifdef UTF8UCS2                                                    //~va20I~
//  					  if (swutf8file)                          //~va20I~//~va80R~
    					  if (swucsprint)                          //~va80R~
                          {                                        //~va80I~
              	  		  	rowlen[ii][1]=0;	//clear right half len//~va20I~
              	  		  	rowlenhhexlrecl[ii][1]=0;	//clear right half len//~va80I~
                          }                                        //~va80I~
                          else                                     //~va20I~
#endif                                                             //~va20I~
                            memset(pagewk,' ',logicalw);           //~v627I~
                        }                                          //~v627I~
                        memcpy(pagewk+pos2px,pdata,(UINT)len);     //~v627I~
#ifdef UTF8UCS2                                                    //~va20I~
//                    if(swutf8file)                               //~va20I~//~va80R~
                      if(swucsprint)                               //~va80R~
                      {                                            //~va20I~
		              	rowlen[ii][jj]=len;                        //~va20R~
		              	rowlenhhexlrecl[ii][jj]=-1; //vhexlineid   //~va80R~
                        *(pagewk+pos2px+dbcsoffspgwk)=VHEXLINEID;	//vhexlineid//~va20R~
                        pagewk+=logicalwu8;                        //~va20I~
                      }                                            //~va20I~
                      else                                         //~va20I~
#endif                                                             //~va20I~
                        pagewk+=logicalw;                          //~v627I~
                    }                                              //~v627I~
                    else                                           //~v627I~
                        prttextout(previewsw,Pdc,yy,pdata,len);    //~v627I~
        	    }//for kk                                          //~v627R~
            }//vhex                                                //~v627I~
        }                                                          //~2B04R~
        if (!M2p)                                                  //~2B04R~
        	break;                                                 //~2B04I~
        if (rc<0)                                                  //~2B04I~
        	break;                                                 //~2B04I~
	    pagewk=pagewk2;		//after header                         //~2B17I~
#ifdef UTF8UCS2                                                    //~va20I~
//    if (swutf8file)                                              //~va20I~//~va80R~
      if (swucsprint)                                              //~va80R~
    	pos2px=pos2px0u8;                                          //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
    	pos2px=pos2px0;                                            //~2B17I~
    }//2p                                                          //~2B04I~
    if (M2p)                                                       //~2B17M~
    {                                                              //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
//    if (swutf8file)                                              //~va20I~//~va80R~
      if (swucsprint)                                              //~va80R~
      {                                                            //~va20I~
	    pagewk=Mprtpagework;                                       //~va20I~
        yy=0;                                                      //~va20I~
        jj=logicalh;                                               //~va20I~
    	if (Mheader)                                               //~va20I~
        {                                                          //~va20I~
#ifdef W32UNICODE                                                  //~vafaI~
          if (!previewsw)                                          //~vafaI~
			prttextoutwHeader(Pdc,0/*yy*/,pagewk,logicalw,0/*col*/,fnmlclen,MprtfnmW);//~vafaI~
          else                                                     //~vafaI~
#endif                                                             //~vafaI~
			prttextout(previewsw,Pdc,0/*yy*/,pagewk,logicalw);     //~va20I~
            pagewk+=logicalw;                                      //~va20I~
			prttextout(previewsw,Pdc,Mdrawcellh/*yy*/,pagewk,logicalw);//~va20I~
            pagewk+=logicalw;                                      //~va20I~
            yy=2*Mdrawcellh;                                       //~va20M~
            jj-=2;                                                 //~va20I~
        }                                                          //~va20I~
	    for (ii=0;                                                 //~va20R~
				ii<jj;                                             //~va20R~
					ii++,pagewk+=logicalwu8,yy+=Mdrawcellh)        //~va20R~
        {                                                          //~va20I~
        	len=rowlen[ii][0];                                     //~va20R~
            if (len)                                               //~va20I~
            {                                                      //~va80I~
//  			prttextoutw(previewsw,Pdc,yy,0/*xx*/,pagewk,pagewk+dbcsoffspgwk,len,linenofldsz);//~va20R~//~va80R~
                opttow=previewsw;                                  //~va80I~
                hhexlrecl=rowlenhhexlrecl[ii][0];                  //~va80I~
                if (hhexlrecl<0)    //vhexline                     //~va80I~
                    opttow|=PRTTOWO_VHEXLINE;                      //~va80I~
    			if (Mprttype==PRTTYPE_HEX                          //~va80I~
    			||  Mprttype==PRTTYPE_VHEXHHEX  //hhex+vhex        //~va80I~
    			)                                                  //~va80I~
                {                                                  //~va80I~
                    if (hhexlrecl>0)    //not vhexline             //~va80I~
        				opttow|=PRTTOWO_HHEX|((hhexlrecl<<PRTTOWO_LRECLMASKSHIFT) & PRTTOWO_LRECLMASK);//~va80R~
                }                                                  //~va80I~
    			prttextoutw(opttow,Pdc,yy,0/*xx*/,pagewk,pagewk+dbcsoffspgwk,len,linenofldsz);//~va80I~
            }                                                      //~va80I~
	        pc=pagewk+pos2px0u8;                                   //~va20R~
        	len=rowlen[ii][1];                                     //~va20R~
        	hhexlrecl=rowlenhhexlrecl[ii][1];                      //~va80I~
            if (len)                                               //~va20I~
            {                                                      //~va80I~
//  			prttextoutw(previewsw,Pdc,yy,pos2px0,pc,pc+dbcsoffspgwk,len,linenofldsz);//~va20R~//~va80R~
                opttow=previewsw;                                  //~va80I~
                hhexlrecl=rowlenhhexlrecl[ii][1];                  //~va80I~
                if (hhexlrecl<0)    //vhexline                     //~va80I~
                    opttow|=PRTTOWO_VHEXLINE;                      //~va80I~
    			if (Mprttype==PRTTYPE_HEX       //no hhex case for utf8 file//~va80R~
    			||  Mprttype==PRTTYPE_VHEXHHEX  //hhex+vhex        //~va80I~
    			)                                                  //~va80I~
                {                                                  //~va80I~
                    if (hhexlrecl>0)    //not vhexline             //~va80I~
        				opttow|=PRTTOWO_HHEX|((hhexlrecl<<PRTTOWO_LRECLMASKSHIFT) & PRTTOWO_LRECLMASK);//~va80R~
                                                                   //~va80I~
                }                                                  //~va80I~
    			prttextoutw(opttow,Pdc,yy,pos2px0,pc,pc+dbcsoffspgwk,len,linenofldsz);//~va80I~
            }                                                      //~va80I~
        }                                                          //~va20I~
      }                                                            //~va20I~
      else                                                         //~va20I~
#endif                                                             //~va20I~
	    for (yy=0,pagewk=Mprtpagework,ii=logicalh;                 //~2B17I~
				ii>0;                                              //~2B17M~
//  				ii--,pagewk+=logicalw,yy+=Mcellh)              //~v51hR~
					ii--,pagewk+=logicalw,yy+=Mdrawcellh)          //~v51hR~
        {                                                          //~vafaI~
#ifdef W32UNICODE                                                  //~vafaI~
          if (!yy && !previewsw)                                   //~vafaI~
			prttextoutwHeader(Pdc,0/*yy*/,pagewk,logicalw,0/*col*/,fnmlclen,MprtfnmW);//~vafaI~
          else                                                     //~vafaI~
#endif                                                             //~vafaI~
			prttextout(previewsw,Pdc,yy,pagewk,logicalw);          //~2B24I~
        }                                                          //~vafaI~
    }//M2p                                                         //~va20I~
//footer                                                           //~2B17I~
    if (Mfooter)                                                   //~2B03I~
    {                                                              //~2B03I~
    	len=sprintf(footer,"%d",Mprtmaxpage);                      //~2B17M~
    	sprintf(footerp,"%% %dd / %%d",len);                       //~2B17M~
    	len=sprintf(footer,footerp,Mprtcurpage,Mprtmaxpage);       //~2B17M~
        pos=(logicalw-len)/2;                                      //~2B17I~
//      yy=posyfooter*Mcellh; //1 space line                       //~v51hR~
        yy=posyfooter*Mdrawcellh; //1 space line                   //~v51hR~
        if (M2p)                                                   //~2B24I~
        	linewk=pagewk;                                         //~2B24I~
        else                                                       //~2B24I~
	        linewk=Mprtlinework;                                   //~2B24R~
        memset(linewk,' ',logicalw);                               //~v62WI~
//      if (pos>0)                                                 //~v62WR~
        if (pos>=0)                                                //~v62WI~
        {                                                          //~2B24R~
//          memset(linewk,' ',logicalw);                           //~v62WR~
            memcpy(linewk+pos,footer,len);                         //~2B24I~
            pos2=pos+len;                                          //~2C07I~
            if (Msystime)                                          //~2C07R~
            {                                                      //~2C07R~
                len=strlen(Mprtsystime);                           //~2C07R~
                pos=logicalw-len;                                  //~2C07R~
                if (pos>pos2)                                      //~2C07R~
                    memcpy(linewk+pos,Mprtsystime,len);            //~2C07R~
            }                                                      //~2C07R~
        }                                                          //~2C07M~
		prttextout(previewsw,Pdc,yy,linewk,logicalw);              //~2B24I~
    }                                                              //~2B03I~
    if (poldfont)                                                  //~2B23I~
//  	Pdc->SelectObject(poldfont);                               //~@@@@R~
    	Pdc->SelectFont(poldfont);                                 //~@@@@I~
	return 0;                                                      //~2B02I~
}//prtfile                                                         //~2B02R~
//===============================================================================//~2B24I~
//file preview text line print                                     //~2B24I~
//===============================================================================//~2B24I~
int  CWxemain::prttextout(int Ppreviewsw,CDC *Pdc,int Pyy,char *Pdata,int Plen)//~2B24I~
{                                                                  //~2B24I~
#define SJIS1(A)    ((A >=0x81 && A <=0x9f) || (A >=0xe0 && A <=0xfc))//sjis 1st byte//~v51hI~
    int ii,xx;                                                     //~2B24R~
    char *pc;                                                      //~2B24I~
//  CSize sz,sz2;                                                  //~@@@@R~
    CSize    sz2;                                                  //~@@@@I~
//************************************                             //~2B24I~
	if (!Plen)                                                     //~2B24R~
    	return 0;                                                  //~2B24I~
//  sz=Pdc->GetOutputTextExtent(Pdata,Plen);                       //~@@@@R~
//  Pdc->GetOutputTextExtent(Pdata,Plen,&sz);                      //~@@@@I~
//  sz2=Pdc->GetTextExtent(Pdata,Plen);                            //~@@@@R~
    Pdc->GetTextExtent(Pdata,Plen,&sz2);                           //~@@@@I~
//UTRACEP("textout yy=%d,len=%d=%d,out-ext=%d,%d,ext=%d,%d\n",     //~@@@@R~
//				Pyy,Plen,Plen*Mdrawcellw,sz.cx,sz.cy,sz2.cx,sz2.cy);//~@@@@R~
UTRACEP("textout yy=%d,len=%d=%d,ext=%d,%d\n",                     //~@@@@I~
				Pyy,Plen,Plen*Mdrawcellw,sz2.cx,sz2.cy);           //~@@@@I~
UTRACED("textout",Pdata,Plen);                                     //~v53hR~
	if (Ppreviewsw)	//preview                                      //~2B24I~
    {                                                              //~2B24I~
//		for (ii=0,xx=0,pc=Pdata;ii<Plen;ii++,xx+=Mcellw,pc++)      //~v51hR~
  		for (ii=0,xx=0,pc=Pdata;ii<Plen;ii++,xx+=Mdrawcellw,pc++)  //~v51hR~
#ifdef UTF8UCS2                                                    //~va20I~
          if (ii<Plen-1 && udbcschk(*pc))                          //~va20I~
#else                                                              //~va20I~
          if (ii<Plen-1 && SJIS1(*pc))                             //~v51hI~
#endif                                                             //~va20I~
          {                                                        //~v51hI~
			Pdc->TextOut(xx,Pyy,pc,2);                             //~v51hI~
            ii++,pc++,xx+=Mdrawcellw;                              //~v51hR~
          }                                                        //~v51hI~
          else                                                     //~v51hI~
			Pdc->TextOut(xx,Pyy,pc,1);                             //~2B24I~
    }                                                              //~2B24I~
    else                                                           //~2B24I~
    	Pdc->TextOut(0,Pyy,Pdata,Plen);                            //~2B24I~
    return 0;                                                      //~2B24I~
}//prttextout                                                      //~2B24I~
#ifdef UTF8UCS2                                                    //~va20I~
//===============================================================================//~va20I~
//utf8 file print                                                  //~va20I~
//===============================================================================//~va20I~
int  CWxemain::prttextoutw(int Ppreviewsw,CDC *Pdc,int Pyy,int Pcol,char *Pdata,char *Pdbcs,int Plen,int Plinenofldlen)//~va20R~
{                                                                  //~va20I~
    int reslen,xx;                                                 //~va20R~
    char *pcd,*pc;                                                 //~va20R~
    int opttow,reslenhhex,hhexlen;                                 //~va80I~
//************************************                             //~va20I~
    opttow=Ppreviewsw;                                             //~va80I~
    Ppreviewsw&=PRTTOWO_PREVIEW;                                   //~va80R~
	if (!Plen)                                                     //~va20I~
    	return 0;                                                  //~va20I~
UTRACEP("prttextoutw opt=%x,yy=%d,xcol=%d,linenosz=%d,len=%d\n",opttow,Pyy,Pcol,Plinenofldlen,Plen);//~va20R~//~va80R~
UTRACED("prttextoutw data",Pdata,Plen);                                    //~va20I~//~va80R~
//  if (*Pdbcs==VHEXLINEID)	//vhexline                             //~va20I~//~va80R~
    if (opttow & PRTTOWO_VHEXLINE)	//vhexline,dont depend on dbcsid==ff//~va80I~
    {                                                              //~va20I~
		Pdc->TextOut(Pcol*Mdrawcellw,Pyy,Pdata,Plen);              //~va20I~
        return 0;                                                  //~va20I~
    }                                                              //~va20I~
    xx=Pcol*Mdrawcellw;                                            //~va20I~
    pc=Pdata;                                                      //~va20I~
    reslen=Plen;                                                   //~va20I~
    if (Plinenofldlen)                                             //~va20R~
    {                                                              //~va20I~
		Pdc->TextOut(xx,Pyy,Pdata,Plinenofldlen);                  //~va20I~
        xx+=Plinenofldlen*Mdrawcellw;                              //~va20I~
        pc+=Plinenofldlen;                                         //~va20R~
        reslen-=Plinenofldlen;                                     //~va20R~
    }                                                              //~va20I~
    if (opttow & PRTTOWO_HHEX)                                     //~va80I~
    {                                                              //~va80I~
		hhexlen=((opttow & PRTTOWO_LRECLMASK)>>PRTTOWO_LRECLMASKSHIFT);//~va80R~
    	reslenhhex=reslen-hhexlen;                                 //~va80I~
        reslen=hhexlen;                                            //~va80I~
UTRACED("prttextoutw dbcs",Pdbcs,hhexlen);                         //~va80I~
    	if (reslenhhex)                                            //~va80M~
        {                                                          //~va80M~
			Pdc->TextOut(xx+Mdrawcellw*reslen,Pyy,pc+reslen,reslenhhex);//~va80R~
            UTRACEP("prttextoutw hhex xx%d\n",xx);                 //~va80I~
            UTRACED("prttextoutw hhex",pc,reslenhhex);             //~va80I~
        }                                                          //~va80M~
    }                                                              //~va80I~
	if (Ppreviewsw)	//preview                                      //~va20I~
    {                                                              //~va20I~
  		for (pcd=Pdbcs;reslen>0;reslen--,xx+=Mdrawcellw,pc++,pcd++)//~va20R~
        {                                                          //~va20I~
			csubtextoutw1(0,Pdc->m_hDC,xx,Pyy,pc,pcd,reslen);      //~va20R~
//          if (UDBCSCHK_DBCS1STUCS2NW(*pcd))	//printable dbcs   //~va20I~//~vb2HR~
            if (UDBCSCHK_DBCS1STUCS2NWPO(*pcd))	//printable dbcs   //~vb2HI~
            {                                                      //~va20I~
            	xx+=Mdrawcellw;                                    //~va20R~
                pc++;                                              //~va20I~
                pcd++;                                             //~va20I~
                reslen--;                                          //~va20I~
            }                                                      //~va20I~
        }                                                          //~va20I~
                                                                   //~va20I~
    }                                                              //~va20I~
    else                                                           //~va20I~
    {                                                              //~va20I~
//  	csubtextoutw(CSTOWO_PRINT,Pdc->m_hDC,xx,Pyy,pc,Pdbcs,reslen,Mdrawcellw);//+vb4iR~
    	csubtextoutw(CSTOWO_PRINT,0/*lineopt*/,Pdc->m_hDC,xx,Pyy,pc,Pdbcs,reslen,Mdrawcellw);//+vb4iR~
    }                                                              //~va20I~
    return 0;                                                      //~va20I~
}//prttextoutw                                                     //~va20R~
#ifdef W32UNICODE                                                  //~vafaI~
//===============================================================================//~vafaI~
//header print for ucs filename                                    //~vafaI~
//===============================================================================//~vafaI~
int  CWxemain::prttextoutwHeader(CDC *Pdc,int Pyy,char *Pdata,int Plen,int Ppos,int Plclen,UWCH *PfnmW)//~vafaI~
{                                                                  //~vafaI~
    int xx,len,ucsctr;                                             //~vafaR~
//************************************                             //~vafaI~
	if (!Plen)                                                     //~vafaI~
    	return 0;                                                  //~vafaI~
UTRACED("text",Pdata,Plen);                                        //~vafaI~
UTRACED("fnmW",PfnmW,strszW(PfnmW));                               //~vafaI~
	if (Ppos)                                                      //~vafaI~
    	Pdc->TextOut(0,Pyy,Pdata,Ppos);                            //~vafaI~
    xx=Ppos*Mdrawcellw;                                            //~vafaI~
    ucsctr=strctrW(PfnmW);                                         //~vafaR~
UTRACEP("fnmw pos=%d,Mdrawcellw=%d,xx=%d\n",Ppos,Mdrawcellw,xx);   //~vafaI~
//  Pdc->TextOutW(xx,Pyy,PfnmW,ucsctr);                            //~vafaR~
    csubtextoutWW(0,Pdc->m_hDC,xx,Pyy,PfnmW,ucsctr);               //~vafaR~
	len=Plen-(Ppos+Plclen);                                        //~vafaI~
    if (len>0)                                                     //~vafaI~
    {                                                              //~vafaI~
    	xx+=Plclen*Mdrawcellw;                                     //~vafaI~
	    Pdc->TextOut(xx,Pyy,Pdata+Ppos+Plclen,len);                //~vafaI~
    }                                                              //~vafaI~
    return 0;                                                      //~vafaI~
}//prttextoutw                                                     //~vafaI~
#endif	//W32UNICODE                                               //~vafaI~
#endif                                                             //~va20I~
//===============================================================================//~2B02I~
//file print                                                       //~2B02I~
//===============================================================================//~2B02I~
void CWxemain::prtviewportfile(CDC *Pdc,int Pwidth,int Pheight,int Porgx,int Porgy)//~2B24R~
{                                                                  //~2B02I~
	int  prnw,prnh,logicalw,logicalh;                              //~2B23R~
	int  orgx,orgy,cellw,cellh;                                    //~2B23R~
    int rc; RECT rect;                                             //~2B17M~
    TEXTMETRIC  metric;                                            //~2B23I~
    CSize sz,szo;                                                  //~2B23R~
//************************************                             //~2B02I~
//    CPoint cp=Pdc->GetWindowOrg();                               //~2B23R~
//    CPoint cp2=Pdc->GetViewportOrg();                            //~2B23R~
//    CSize  cs=Pdc->GetWindowExt();                               //~2B23R~
//    CSize  cs2=Pdc->GetViewportExt();                            //~2B23R~
//  if (Mfullpage)                                                 //~v51hR~
    if (Mfullpage||Mchkpfontsz)                                    //~v51hI~
    	Pdc->SetMapMode(MM_ANISOTROPIC); //x,y is not same pixel rate//~2B30R~
    else                                                           //~2B30I~
    	Pdc->SetMapMode(MM_ISOTROPIC); //x,y is not same pixel rate//~2B30I~
    rc=Pdc->GetBoundsRect(&rect,0);                                //~2B17M~
    Pdc->GetClipBox(&rect);                                        //~2B17M~
    logicalw=Mprtcmaxcol+Mprtlinenosz*(Mlinenumber==TRUE);         //~2B04R~
    if (M2p)                                                       //~2B04R~
    	logicalw+=logicalw+Mprt2pcol;                              //~2B17R~
    logicalh=Mprtcmaxrow+(Mfooter+Mheader)*2;                      //~2B17I~
//  sz=Pdc->GetTextExtent("0",1);                                  //~@@@@R~
    Pdc->GetTextExtent("0",1,&sz);                                 //~@@@@I~
UTRACEP("gettextextent =%d,%d\n",sz.cx,sz.cy);                     //~2B23I~
    Pdc->GetTextMetrics(&metric);                                  //~2B23I~
UTRACEP("outtextmetric h=%d,avw=%d,maxw=%d\n",                     //~2B23I~
				metric.tmHeight,metric.tmAveCharWidth,metric.tmMaxCharWidth);//~2B23I~
//  cellw=Mcellw;                                                  //~v51hR~
//  cellh=Mcellh;                                                  //~v51hR~
    cellw=Mdrawcellw;                                              //~v51hR~
    cellh=Mdrawcellh;                                              //~v51hR~
    Pdc->SetWindowExt(logicalw*cellw,logicalh*cellh);	//range of logical axis by max display size//~2B23R~
UTRACEP("textout cell=%d,%d,-->windext=%d,%d\n",                   //~2B24R~
				Mdrawcellw,Mdrawcellh,logicalw*cellw,logicalh*cellh);//~v51hR~
    Pdc->SetWindowOrg(0,0);                                        //~2B06M~
    if (Pwidth) //preview                                          //~2B04I~
    {                                                              //~2B04I~
        prnw=Pwidth;                                               //~2B06R~
        prnh=Pheight;                                              //~2B06R~
        orgx=Porgx;                                                //~2B06I~
        orgy=Porgy;                                                //~2B06I~
    	prnw=prnw*100/logicalw*logicalw/100;	//protect right cut//~2B24I~
    	prnh=prnh*100/logicalh*logicalh/100;	//protect right cut//~2B24I~
    }                                                              //~2B04I~
    else                                                           //~2B04I~
    {                                                              //~2B04I~
    	rect.left  =Mmarginl;                                      //~2B23I~
    	rect.top   =Mmargint;                                      //~2B23I~
    	rect.right =Mmarginr;                                      //~2B23I~
    	rect.bottom=Mmarginb;                                      //~2B23I~
    	prtmarginrect(Pdc,&rect);//change mm to pixel              //~2B24R~
	    orgx=rect.left;                                            //~2B23R~
	    orgy=rect.top;                                             //~2B23R~
        prnw=rect.right-rect.left;                                 //~2B23R~
        prnh=rect.bottom-rect.top;                                 //~2B23R~
    	prnw=prnw/logicalw*logicalw;	//protect right cut        //~2B23I~
    	prnh=prnh/logicalh*logicalh;	//protect right cut        //~2B23I~
UTRACEP("devcap x=%d,y=%d\n",                                      //~3113R~
			Pdc->GetDeviceCaps(LOGPIXELSX),Pdc->GetDeviceCaps(LOGPIXELSY));//~3113R~
    }                                                              //~2B04I~
//  prnw-=PRINT_MARGIN_RIGHT_SAFETY;                               //~2B16R~
    Pdc->SetViewportOrg(orgx,orgy);//map origin on physical axis   //~2B23M~
    Pdc->SetViewportExt(prnw,prnh);                                //~2B17R~
//  Pdc->SetViewportExt(szo.cx,szo.cy);                            //~2B17R~
UTRACEP("viewport org=(%d,%d),ext=(%d,%d)\n",orgx,orgy,prnw,prnh); //~3113R~
	sz.cx=logicalw*cellw;                                          //~2B23R~
	sz.cy=logicalh*cellh;                                          //~2B23R~
	Pdc->LPtoDP(&sz);                                              //~2B17I~
UTRACEP("LtoD logw=%d,logh=%d,logszw=%d,logszh=%d,dev=(%d,%d)\n",  //~2B23I~
			logicalw,logicalh,logicalw*cellw,logicalh*cellh,sz.cx,sz.cy);//~2B23R~
	sz.cx=prnw;                                                    //~2B17I~
	sz.cy=prnh;                                                    //~2B17I~
	Pdc->DPtoLP(&sz);                                              //~2B17I~
UTRACEP("DtoL D=(%d,%d),L=(%d,%d)\n",prnw,prnh,sz.cx,sz.cy);       //~2B23I~
	return;                                                        //~2B02R~
}//prtviewportfile                                                 //~2B24R~
//===============================================================================//~2B23I~
//file print                                                       //~2B23I~
//===============================================================================//~2B23I~
void CWxemain::prtmarginrect(CDC *Pdc,RECT *Pprect)                //~2B23R~
{                                                                  //~2B23I~
	int  prnw,prnh,prnwmm,prnhmm,margin,top,left,bottom,right;     //~2B23I~
    float fwpixbymm,fhpixbymm;                                     //~2B23I~
//************************************                             //~2B23I~
    prnw=Pdc->GetDeviceCaps(HORZRES);       //by pixel             //~2B23I~
    prnh=Pdc->GetDeviceCaps(VERTRES);                              //~2B23I~
    prnwmm=Pdc->GetDeviceCaps(HORZSIZE);    //by mm                //~2B23I~
    prnhmm=Pdc->GetDeviceCaps(VERTSIZE);                           //~2B23I~
UTRACEP("prepare devpix=(%d,%d),dev mm=(%d,%d)\n",prnw,prnh,prnwmm,prnhmm);//~2B23I~
    fwpixbymm=(float)prnw/prnwmm;                                  //~2B23I~
    fhpixbymm=(float)prnh/prnhmm;                                  //~2B23I~
	margin=max(0,Pprect->left-MARGIN_FORM_CLIP);                   //~2B23I~
	left=(int)(margin*fwpixbymm+(margin!=0));                      //~2B23I~
	margin=max(0,Pprect->top-MARGIN_FORM_CLIP);                    //~2B23I~
	top=(int)(margin*fhpixbymm+(margin!=0));                       //~2B23I~
	margin=max(0,Pprect->right-MARGIN_FORM_CLIP);                  //~2B23I~
	right=(int)(margin*fwpixbymm+(margin!=0));   //right margin pos by pixel//~2B23I~
	margin=max(0,Pprect->bottom-MARGIN_FORM_CLIP);                 //~2B23I~
	bottom=(int)(margin*fhpixbymm+(margin!=0));   //bottom margin pos by pixel//~2B23I~
	Pprect->top =top;                                              //~2B23I~
	Pprect->left=left;                                             //~2B23I~
	Pprect->bottom=prnh-bottom;                                    //~2B23I~
	Pprect->right =prnw-right;                                     //~2B23I~
UTRACEP("marginrect     pix:t=%d,l=%d,b=%d,r=%d\n",                //~2B23I~
	Pprect->top,Pprect->left=left,Pprect->bottom,Pprect->right);   //~2B23I~
    return;                                                        //~2B23I~
}//prtmaginrect                                                    //~2B23I~
//===============================================================================//~2B23R~
//preview of page setup dialog                                     //~2C03R~
//===============================================================================//~2B23R~
int CWxemain::prtpreview(CDC *Pdc,RECT *Pdrawrect,int Phcopysw,int Pcurpage)//~2C14R~
{                                                                  //~2B23R~
    int orgx,orgy,width,height,rc;                                 //~2B23R~
//  CFont *pnewfont;                                               //~v51hR~
    char fontface[64];                                             //~2C03I~
//************************************                             //~2B23R~
	Mhcopysw=Phcopysw;                                             //~2B23M~
	Mprtcurpage=Pcurpage;                                          //~2C14R~
//  pnewfont=createfontsub(Mcharset,Mfontstyle,Mttfont,Mfontheight,Mfontwidth,0);//~2C03R~
//  pnewfont=createfontsub(Mcharset,NULL,Mttfont,fonth,fontw,0);//try default font//~v51hI~
    onprepareprinting(0);   //0:preview id                         //~2B23R~
    orgx=Pdrawrect->left;                                          //~2B24R~
    orgy=Pdrawrect->top;                                           //~2B24R~
    width=Pdrawrect->right-orgx;                                   //~2B24R~
    height=Pdrawrect->bottom-orgy;                                 //~2B24R~
    if (Mhcopysw)                                                  //~2B24M~
      rc=                                                          //~vafaI~
        prtscr(Pdc,Mpprtfont,width,height,orgx,orgy);              //~v51hR~
    else                                                           //~2B24I~
        rc=prtfile(Pdc,Mpprtfont,width,height,orgx,orgy);          //~v51hR~
//  Pdc->GetTextFace(64,fontface);                                 //~@@@@R~
    Pdc->GetTextFace(fontface,sizeof(fontface));                   //~@@@@I~
UTRACEP("preview default font=%s\n",fontface);                     //~2C03I~
	onendprinting(Pdc,0);	//free work                            //~2B24I~
//  pnewfont->DeleteObject();                                      //~v51hR~
    return rc;                                                     //~2B23I~
}//prtpreview                                                      //~2B23R~
//===============================================================================//~@@@@I~
//ID_FILE_PRINT command:setup printjob                             //~@@@@I~
//===============================================================================//~@@@@I~
int CWxemain::printdlg()                                           //~@@@@R~
{                                                                  //~@@@@I~
	CPrintJobInfo *pjobinfo;                                       //~@@@@I~
    DWORD dlgflag=PD_ALLPAGES                                      //~@@@@R~
    		     | PD_USEDEVMODECOPIES                             //~@@@@I~
				 | PD_NOSELECTION                                  //~@@@@I~
    			 | PD_NOCURRENTPAGE			//diable chkbox current page//~@@@@I~
    			 | PD_DISABLEPRINTTOFILE                           //~@@@@I~
                 ;	                                               //~@@@@I~
    int rc,frompage,topage,action;                                 //~@@@@R~
    bool multithred,swfile;                                        //~@@@@R~
    char *pdocname;                                                //~@@@@I~
//************************************                             //~@@@@I~
	if (!Mprinterinit)                                             //~@@@@I~
    {                                                              //~@@@@I~
    	if (Mprinter.OpenDefaultPrinter()==FALSE                   //~@@@@R~
    	||  Mdevmode.CopyFromPrinter(Mprinter)==FALSE)             //~@@@@R~
        {                                                          //~@@@@I~
    		uerrmsgbox("Failed to Open Default Printer",0);        //~@@@@I~
        	return 4;                                              //~@@@@I~
        }                                                          //~@@@@I~
        Mprinterinit=1;                                            //~@@@@R~
    }                                                              //~@@@@I~
    CPrintDialogEx dlg(dlgflag);                                   //~@@@@R~
    dlg.m_pdex.hDevMode=Mdevmode.CopyToHDEVMODE();                 //~@@@@R~
    dlg.m_pdex.hDevNames=Mprinter.CopyToHDEVNAMES();               //~@@@@R~
    dlg.m_pdex.nMaxPageRanges=MAX_PAGERANGE;                       //~@@@@R~
//  ppagerange=::GlobalAlloc(GPTR/*fixed,nullified*/,sizeof(PRINTPAGERANGE)*MAX_PAGERANGE);//~@@@@I~
    dlg.m_pdex.lpPageRanges=Mpageranges;                           //~@@@@R~
    dlg.m_pdex.nMinPage=1;                                         //~@@@@I~
    dlg.m_pdex.nMaxPage=Mprtmaxpage;                               //~@@@@R~
    prtformsetup(dlg.GetDevMode(),Mformid,Mlandscape);    //set formid//~@@@@R~
    Mpagerangeno=0;  //clear pagerange count                       //~@@@@I~
    rc=dlg.DoModal();                                              //~@@@@I~
UTRACEP("printjob dlg name=%s,rc=%d\n",dlg.m_pdex.hDevNames);      //~@@@@R~
    if (SUCCEEDED(rc))        //S_OK                               //~@@@@R~
    {                                                              //~@@@@I~
	    action=dlg.m_pdex.dwResultAction;                          //~@@@@I~
	    if (action==PD_RESULT_PRINT                                //~@@@@I~
	    ||  action==PD_RESULT_APPLY)                               //~@@@@I~
        {                                                          //~@@@@I~
			Mdevmode.CopyFromHDEVMODE(dlg.m_pdex.hDevMode);  //save dialog setting//~@@@@R~
        	Mprinter.ClosePrinter();                               //~@@@@R~
        	Mprinter.OpenPrinter(dlg.m_pdex.hDevNames,Mdevmode);   //~@@@@R~
        }                                                          //~@@@@I~
	    if (action==PD_RESULT_PRINT)                               //~@@@@I~
        {                                                          //~@@@@I~
        	if (dlg.PrintRange())                                  //~@@@@I~
			    Mpagerangeno=dlg.m_pdex.nPageRanges;  //clear pagerange count//~@@@@I~
            frompage=1;                                            //~@@@@R~
            topage=Mprtmaxpage;                                    //~@@@@R~
            multithred=FALSE;                                      //~@@@@R~
            pjobinfo=(CMainFrame*)Mpmainframe;                     //~@@@@R~
            swfile=dlg.PrintToFile()!=FALSE;                       //~@@@@R~
            pdocname=Mprtfnm;                                      //~@@@@R~
            Mprintjob.StartPrintJob(multithred,Mprinter,Mdevmode,pjobinfo,pdocname,frompage,topage,swfile);//~@@@@R~
//FIXME:currently  no UNICODE version API                          //~vafaI~
            //*callback sequense:BeginPrintJob,{Isvalid,PrePrintPage,PrintPage,PostPrintPage},EndPrintJob//~@@@@I~
        }                                                          //~@@@@I~
    }                                                              //~@@@@I~
	::GlobalFree(dlg.m_pdex.hDevMode);                             //~@@@@R~
	::GlobalFree(dlg.m_pdex.hDevNames);                            //~@@@@R~
    return 0;                                                      //~@@@@I~
}//onfileprint                                                     //~@@@@I~
//===============================================================================//~@@@@I~
//*WTL                                                             //~@@@@I~
//===============================================================================//~@@@@I~
//===============================================================================//~@@@@I~
//*                                                                //~@@@@I~
//===============================================================================//~@@@@I~
bool CWxemain::printpage(UINT nPage, HDC hDC)   //rc:False=Cancel  //~@@@@R~
{                                                                  //~@@@@I~
	CPrintJobInfo *pjobinfo;                                       //~@@@@I~
	int ii,ranges;                                                 //~@@@@I~
//***************                                                  //~@@@@I~
	if (Mpagerangeno)                                              //~@@@@I~
    {                                                              //~@@@@I~
		ranges=min(Mpagerangeno,MAX_PAGERANGE);                    //~@@@@R~
		for (ii=0;ii<ranges;ii++)                                  //~@@@@I~
        {                                                          //~@@@@I~
    		if (nPage>=Mpageranges[ii].nFromPage && nPage<=Mpageranges[ii].nToPage)//~@@@@I~
        		break;                                             //~@@@@I~
        }                                                          //~@@@@I~
        if (ii>=ranges)                                            //~@@@@I~
        	return TRUE;                                           //~@@@@I~
    }                                                              //~@@@@I~
    CDC *pdc=new CDC(hDC);                                         //~@@@@M~
    pjobinfo=(CPrintJobInfo*)Mpmainframe;                          //~@@@@R~
    prtpreparedc(pdc,pjobinfo,nPage);//set Current Pageno          //~@@@@R~
    CWxeDoc *pdoc=Mpview->GetDocument();                           //~@@@@I~
	onprint(pdc,pdoc);                                             //~@@@@R~
    return TRUE;	//continue to next page                        //~@@@@I~
}                                                                  //~@@@@I~
//===============================================================================//~@@@@I~
//*                                                                //~@@@@I~
//===============================================================================//~@@@@I~
bool CWxemain::isvalidpage(UINT nPage)   //rc:False=Cancel         //~@@@@R~
{                                                                  //~@@@@I~
	return TRUE;  //FALSE:break print                              //~@@@@R~
}                                                                  //~@@@@I~
