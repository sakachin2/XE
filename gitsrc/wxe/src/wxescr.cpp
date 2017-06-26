//CID://+vb4iR~:       update#=   119                              //~vb4iR~
//******************************************************************************//~v003I~
//vb4i:160805 vb4f for wxe(specify ligature on/off,combine on/of line by line)//~vb4iI~
//vb4g:160801 (WXE)dirlist ligature on always like as vb37         //~vb4gI~
//vb3q:160617 (BUG)dbcsspace dispchar should be fix to ffff(apply assign by ini file to LC file only)//~vb3qI~
//vb3p:160616 (BUG)when utf8 ligature on,1st colomn green is ligatured to linono//~vb3pI~
//vb3o:160616 (BUG)DBCS space was displayed as dbcsspace-altch and 0xff//~vb3oI~
//vb2K:160314 (W32:BUG) need to consider 3/4 byte DBCS             //~vb2KI~
//vb2J:160313 (W32) compier warning                                //~vb2JI~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//va7S:100907 (BUG)mouse drag at edge of screen dose not expand copy range bat scroll.//~va7SI~
//va7Q:100907 (WXE:BUG)csr width did'nt change fo del-key dbcs<-->may be changed by shift//~va7QI~
//va7D:100830 (XXE:BUG)cap menu update err(it should not be based on Mcellcopy1 bur Gcsrposy)//~va7DI~
//va77:100806 redundant select object for font                     //~va77I~
//va74:100806 (BUG:WXE)reset va6v; write by locale code to use font codepage on setupdialog//~va74I~
//                     currentrly l2uany use base locale           //~va74I~
//va6v:000626 (WXE)use textoutW for locale code (more printable for any font slected)//~va6vI~
//va6u:000626 (WXE)ligature support for also locale code file      //~va6uI~
//va46:100331 not use ctrl char for tab and tab padding,but use xff as default//~va46I~
//va44:100329 to print 0x14 glyph(q:0xb6),use another altchar(0xff)//~va44I~
//va42:100328 (WXE:BUG)tab,tab padding char is not visual,print alt char//~va42I~
//va3t:100221 (WXEXXE)break also at prev char of vhex data csr pos for backspace at vhex line//~va3tI~
//va3k:100210 (BUG:WIN)vsplit line draw err(=1,=2,edit hdr line at right half)//~va3kI~
//va3j:100208 (LNX)try ligature for console version                //~va3jI~
//            (draw csr line when ligature or combinemode)         //~va3jI~
//va3g:100207 try ligature for also wxe(write ucs string at once) for arabic etc//~va3gI~
//va3a:100205 (WXE)dbcs caret support                              //~va3aI~
//va30:100126 combine mode of diacritical marks by A+/(saved to ini)//~va30I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v78B:080426 (wxe,gxe)vertical ruler draw performance             //~v78BI~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v73t:070125 cross-hair ruler support by Shift+Ctl+lbuton         //~v73tI~
//v69S:060716 (WXE:BUG)corrupted dbcs disply by mouse drag when dbcs split//~v69SI~
//v682:060313 (WXE:BUG)menu enable re-evaluation requred for drag selection on dirlist;and also when reset by esc key//~v682I~
//v653:050712 (WXE:BUG)top dbcs split char is not displayed        //~v653I~
//v63r:050525 ignore(no cursor move) 1st mouse click after killfocus//~v63rI~
//v55W:040322 (WXE)AT cmd support;"AT(&) interval,count;cmd"       //~v55WI~
//v55u:040229 (WXE)add open with for dir-list                      //~v55uI~
//v51w:030615 (WXE)icon for MDOS and Explorer                      //~v51wI~
//******************************************************************************//~v003I~
//******************************************************************************//~v003I~
#include <sys/timeb.h>                                             //~v63rI~
#include    "StdAfx.h"                                             //~v003I~
#define NO_MACRO_REDIRECT                                          //~vak7I~
#include    "ulib.h"                                               //~vak7I~
#include    "wxedef.h"                                             //~v003I~
#include    "wxe.h"                                                //~2A10I~
#include    "wxefile.h"                                            //~v003M~
#include    "wxeDoc.h"                                             //~v003I~
#include    "wxexei.h"                                             //~v780M~
#include    "wxemain.h"                                            //~v003R~
#include    "mainfrm.h"                                            //~v682I~
#include    "wxecsub.h"                                            //~2901I~
#include    "wxexei.h"                                             //~v78BI~
#include    "resource.h"                                           //~v003I~
                                                                   //~v003I~
//#include    "ulib.h"                                               //~v003I~//~va42M~//~vak7R~
#include    "udbcschk.h"                                           //~v003I~
#include    "utrace.h"                                             //~2914I~
#ifdef UTF8UCS2                                                    //~va20I~
#include    "utf.h"                                              //~va20R~//~va30R~
#include    "utf22.h"                                              //~va30I~
#endif                                                             //~va20I~
#include    "uviom.h"                                              //~vb4iI~
//static int Sswcsrlinedd;                                         //~va3jR~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void  CWxemain::scrinit(void)                                      //~v003R~
{                                                                  //~v003I~
//************************************                             //~v003I~
//  CClientDC dc(Mpview);                                          //~@@@@R~
    CClientDC *pdc=new CClientDC(HWND(*Mpview));                   //~@@@@R~
    Mpmemdc=new CDC();                                             //~v003M~
//  Mpmemdc->CreateCompatibleDC(&dc);                              //~@@@@R~
    Mpmemdc->CreateCompatibleDC(HDC(*pdc));                        //~@@@@I~
    scrbgrect(Mpmemdc);                                            //~2A20R~
    createfont();                                                  //~v003I~
    scrpeninit(1);                                                 //~v73tR~
	return;                                                        //~v003I~
}//scrinit                                                         //~v003I~
//===============================================================================//~v73tI~
void  CWxemain::scrpeninit(int Pinitsw)                            //~v73tR~
{                                                                  //~v73tI~
	LOGPEN lpen={PS_SOLID,{1,0}};                                  //~v73tM~
//************************************                             //~v73tI~
    if (!Pinitsw)	//fits time only                               //~v73tI~
    	Mrulerpen.DeleteObject();                                  //~v73tI~
    lpen.lopnColor=Mrulercolor;                                    //~v73tM~
    Mrulerpen.CreatePenIndirect(&lpen);                            //~v73tM~
//  Mpmemdc->SelectObject(Mrulerpen);   //inner grid;save cuurrent //~v78BR~
    return;                                                        //~v73tI~
}                                                                  //~v73tI~
//===============================================================================//~2908I~
//                                                                 //~2908I~
//===============================================================================//~2908I~
void  CWxemain::scronok(int Pcpchngsw)                             //~2929R~
{                                                                  //~2908I~
    Mscrcmaxrow=ROWCTR(Mscrheight);                                //~2908I~
    Mscrcmaxcol=COLCTR(Mscrwidth);                                 //~2908I~
    Mwxeintf.WXEIcsrchangesw=1;	//recreate caret                   //~2914I~
    createfont();                                                  //~2A23M~
    OnSize(0,Mscrwidth,Mscrheight); 	//ajust row/col ctr and resize//~2A23R~
//  wxe_onsize(Mscrcmaxrow,Mscrcmaxcol,Pcpchngsw);	//init         //~2A23R~
//  scrbgrect(Mpmemdc);                                            //~2A23R~
//  Mfulldrawsw=1;                                                 //~2A23R~
//  scrinvalidate();                                               //~2A23R~
	return;                                                        //~2908I~
}//scronok                                                         //~2928R~
//===============================================================================//~2908I~
//draw background rectangle                                        //~2908I~
//===============================================================================//~2908I~
void  CWxemain::scrbgrect(CDC *Ppmemdc)                            //~2A20R~
{                                                                  //~2908I~
//  CBrush  br(Mbgcolor);                                          //~@@@@R~
    CBrush  br;                                                    //~@@@@I~
    RECT  rr;                                                      //~2908I~
//************************************                             //~2908I~
    br.CreateSolidBrush(Mbgcolor);                                 //~@@@@I~
//  CClientDC dc(Mpview);                                          //~@@@@R~
    CClientDC *pdc=new CClientDC(*Mpview);                         //~@@@@R~
    CBitmap *pnewbmp=new CBitmap();                                //~2908I~
//  pnewbmp->CreateCompatibleBitmap(&dc,Mscrwidth,Mscrheight);     //~@@@@R~
    pnewbmp->CreateCompatibleBitmap(HDC(*pdc),Mscrwidth,Mscrheight);//~@@@@R~
//  Ppmemdc->SelectObject(pnewbmp);                                //~@@@@R~
    Ppmemdc->SelectBitmap(HBITMAP(*pnewbmp));                      //~@@@@I~
    if (Mpbgbitmap)                                                //~2908I~
        Mpbgbitmap->DeleteObject();                                //~2908R~
    Mpbgbitmap=pnewbmp;                                            //~2908R~
	rr.top=0;                                                      //~2908I~
	rr.left=0;                                                     //~2908I~
	rr.bottom=Mscrheight;                                          //~2B23R~
	rr.right=Mscrwidth;                                            //~2B23R~
//  Ppmemdc->FillRect(&rr,&br);                                    //~@@@@R~
    Ppmemdc->FillRect(&rr,br);                                     //~@@@@I~
	return;                                                        //~2908I~
}//scrbgrect                                                       //~2908R~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
int  CWxemain::OnSize(UINT Ptype,int Px,int Py)                    //~v003R~
{                                                                  //~v003I~
    TEXTMETRIC tm;                                                 //~2B23R~
//  int smh,smw;                                                   //~2908R~
    CSize tl;                                                      //~2B23R~
	WINDOWPLACEMENT wp;                                            //~2A23I~
	int screxpandsw,ceilx,ceily;                                   //~2A23R~
//************************************                             //~v003I~
    if (!Mpmemdc->m_hDC)                                           //~v003R~
    	return 0;                                                  //~v003I~
    if (!Mxeinitsw)	//before xe init                               //~2916I~
		return 0;                                                  //~2916I~
    UTRACEP("wxescr onsize type=%d,x=%d,y=%d\n",Ptype,Px,Py);      //~2A14I~
    if (!Px || !Py)                                                //~2A23I~
		return 0;                                                  //~2A23I~
    	                                                           //~2A23I~
    if (Py>Mscrheight || Px>Mscrwidth)                             //~2908I~
    	screxpandsw=1;                                             //~2908R~
    else                                                           //~2908I~
    	screxpandsw=0;                                             //~2908I~
    Mscrheight=Py;                                                 //~2908R~
    Mscrwidth=Px;                                                  //~2908R~
    Mpmemdc->GetTextMetrics(&tm);                                  //~2B23R~
UTRACEP("scr textmetric h=%d,avw=%d,maxw=%d\n",                    //~2B23I~
				tm.tmHeight,tm.tmAveCharWidth,tm.tmMaxCharWidth);  //~2B23I~
//  tl=Mpmemdc->GetTextExtent("1234567890",10);                    //~@@@@R~
    Mpmemdc->GetTextExtent("1234567890",10,&tl);                   //~@@@@I~
UTRACEP("scr textextent ext=%d,%d\n",tl.cx,tl.cy);                 //~2B23I~
//  Mrowheight=tm.tmHeight+tm.tmExternalLeading;                   //~v003R~
//  Mcolwidth =tm.tmAveCharWidth;                                  //~v003R~
//  Mcolwidth =tl.cx/10;                                           //~v003R~
//  smh=GetSystemMetrics(SM_CYSCREEN);                             //~2908R~
//  smw=GetSystemMetrics(SM_CXSCREEN);                             //~2908R~
    Mscrcmaxrow=ROWCTR(Mscrheight);                                //~v003R~
    Mscrcmaxcol=COLCTR(Mscrwidth);                                 //~v003R~
    if (Mpmainframe)                                               //~2A23R~
    {                                                              //~2A23I~
        ceily=Py-CWINHEIGHT(Mscrcmaxrow);   //to ajust height by row count//~2A23R~
        ceilx=Px-CWINWIDTH(Mscrcmaxcol);   //to ajust width  by col count//~2A23R~
        if (ceilx||ceily)                                          //~2A23I~
        {                                                          //~2A23I~
//  		Mscrheight-=ceily;                                     //~2B23R~
//  		Mscrwidth-=ceilx;                                      //~2B23R~
            Mpmainframe->GetWindowPlacement(&wp);                  //~2A23I~
            wp.rcNormalPosition.right-=ceilx;                      //~2A23R~
            wp.rcNormalPosition.bottom-=ceily;                     //~2A23R~
            Mpmainframe->SetWindowPlacement(&wp);                  //~2A23I~
        }                                                          //~2A23I~
    }                                                              //~2A23I~
    wxe_onsize(Mscrcmaxrow,Mscrcmaxcol,0);                         //~2A20R~
    if (screxpandsw==1)                                            //~2908R~
	    scrbgrect(Mpmemdc);                                        //~2A20R~
    Mfulldrawsw=1;                                                 //~2914I~
	scrinvalidate();                                               //~2914I~
	return 1;                                                      //~v003R~
}//OnSize                                                          //~v003I~
//===============================================================================//~v003M~
//                                                                 //~v003M~
//===============================================================================//~v003M~
int  CWxemain::draw(CDC *Pdc,CWxeDoc *Pdoc)                        //~v003M~
{                                                                  //~v003M~
    char newpath[_MAX_PATH];                                       //~2922I~
    char newtitle[_MAX_PATH*2];                                    //~2922I~
//************************************                             //~v003M~
	if (!Mxeinitsw)		//xe init called                           //~2914I~
    	return 0;                                                  //~2914I~
    if (Mwxeintf.WXEIxetermsw)	//xe term called already           //~v55WR~
    	return 0;                                                  //~v55WR~
//  if (Pdc->IsPrinting())	//from onprint                         //~@@@@R~
//  	return onprint(Pdc,Pdoc);   //print direct from PrintPage  //~@@@@R~
	Mwinextw=Pdc->GetDeviceCaps(HORZRES);	//screen pixel         //~2B02I~
	Mwinexth=Pdc->GetDeviceCaps(VERTRES);                          //~2B02I~
    if (Mpfont)                                                    //~v003M~
//      if (!Mpmemdc->SelectObject(Mpfont))   //inner grid;save cuurrent//~@@@@R~
        if (!Mpmemdc->SelectFont(HFONT(*Mpfont)))   //inner grid;save cuurrent//~@@@@R~
	        uerrlast("SelectObject for font");                     //~2928I~
UTRACEP("CREATEFONT draw select obj font=%p\n",Mpfont);            //~va74I~
//  Mfulldrawsw=1;                                                 //~2914R~
    if (ugetcpath(newpath))    //current path changed              //~2922I~
    {                                                              //~2922I~
    	sprintf(newtitle,"%s    CWD=%s",WXE_TITLE,newpath);        //~2922R~
    	Mpmainframe->SetWindowText(newtitle);                      //~2A14R~
    }                                                              //~2922I~
	scrupdate(Mpmemdc,0);                                          //~2A20R~
//  Pdc->BitBlt(0,0,Mscrwidth,Mscrheight,Mpmemdc,0,0,SRCCOPY);     //~@@@@R~
    Pdc->BitBlt(0,0,Mscrwidth,Mscrheight,HDC(*Mpmemdc),0,0,SRCCOPY);//~@@@@R~
    scrruler(Pdc,Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx);//direct write not required erase old ruler//~v78BR~
	return 0;                                                      //~v003M~
}//draw                                                            //~v003M~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void CWxemain::scrupdate(CDC *Ppmemdc,int Pprintsw)                //~2A20R~
{                                                                  //~v003I~
    int row;                                                       //~v003R~
    UCHAR *puf;                                                    //~v003R~
    int csrrow,csrcol,csrredrawreqcond;                            //~va3kR~
//  int swligature;                                                //~va3jR~
    int csrdataline=-1,rc2,opt,opt0,fileinfo;                      //~va3kI~
    char *pdbcs;                                                   //~va30I~
    int vhexpos;                                                   //~va3tR~
//************************************                             //~v003I~
//  wxe_getligaturerows(0,NULL);                                   //~vb4iR~
    puf=Mwxeintf.WXEIlineupdate;                                   //~v003R~
    csrrow=Mwxeintf.WXEIcsrposy;                                   //~va30I~
    csrcol=Mwxeintf.WXEIcsrposx;                                   //~va30I~
    pdbcs=(char*)TEXTDBCS(csrrow,0);                               //~va30I~
//    Sswcsrlinedd=-1;                                             //~va3jR~
//    swligature=(((Mwxeintf.WXEIstatus & WXEIS_LIGATURE)!=0) ^ ((Mwxeintf.WXEIstatus & WXEIS_TEMPLIGATURE)!=0));//~va3jR~
//    csrredrawreqcond=(!Pprintsw                                  //~va3jR~
////                       && (UTF_COMBINEMODE()) //allow combine  //~va3jR~
//                         && (Sswcsrlinedd=csubchkdd(0,pdbcs,Mscrcmaxcol)!=0)//~va3jR~
//                         && (swligature||UTF_COMBINEMODE())      //~va3jR~
//                     );                                          //~va3jR~
//    UTRACEP("scrupdate csrrow=%d,drawsw=%d\n",csrrow,csrredrawreqcond);//~va3jR~
//  scrrulererase(Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx);	//set redraw flag to erase prev line//~v78BR~
    csrredrawreqcond=(!Pprintsw                                    //~va3kI~
                       );                                          //~va3kI~
	opt0=0;                                                        //~va3kI~
    if (csrredrawreqcond)                                          //~va3kI~
    {                                                              //~va3kI~
    	rc2=xxe_chkcsrpos(XXECCPO_CSRLINEBREAK,csrrow,csrcol,&fileinfo);//csr is on text area?//~va3kI~
        if (rc2)	//csr is on data or vhex line                  //~va3kI~
        {                                                          //~va3kI~
	        if (fileinfo & XXECCPI_CPU8)                           //~va3kI~
            {                                                      //~va3kI~
                opt0|=LPO_CPU8;                                    //~va3kI~
                if (rc2>0)      //csr is on dataline               //~va3kI~
                    csrdataline=csrrow; //csr is on dataline       //~va3kI~
//              //else;  data line is redrawn when csr is on vhex line for CPU8 file//~va3tR~
                else                                               //~va3tI~
                {                                                  //~va3tI~
                    if (fileinfo & XXECCPI_VHEXCSRPOS)   //vheccsrpos is returned//~va3tR~
                    {                                              //~va3tI~
						vhexpos=XXECCPI_GETVHEXCSR(fileinfo);      //~va3tI~
                    	csrdataline=csrrow+rc2; //draw dataline on csr corresponding to csr vhex line//~va3tR~
                        vhexpos<<=LPO_VHEXSHIFT;                   //~va3tI~
                		opt0|=LPO_VHEX|vhexpos;                    //~va3tR~
                    }                                              //~va3tI~
                }                                                  //~va3tI~
            }                                                      //~va3kI~
            else                                                   //~va3kI~
            {                                                      //~va3kI~
//              if (Mligature)  //allow ligature                   //~va3kI~
//              if (Mligature^Mligaturereverse)  //allow ligature  //~va3kR~
                if (wxe_optligature(WXEIOLO_ISON,0/*pvalue*/))     //~va3kR~
                {                                                  //~va3kI~
                    if (rc2>0)      //csr is ondataline            //~va3kI~
                        csrdataline=csrrow; //csr is on dataline   //~va3kI~
                    else                                           //~va3kI~
                        csrdataline=csrrow+rc2; //draw dataline on csr corresponding to csr vhex line//~va3kI~
                }                                                  //~va3kI~
            }                                                      //~va3kI~
        }                                                          //~va3kI~
    }                                                              //~va3kI~
    for (row=0;row<Mscrcmaxrow;row++,puf++)                        //~v003R~
    {                                                              //~v003I~
//  	if (Mfulldrawsw || *puf!=0)	//line updated                 //~v003I~//~va30R~
    	if (Mfulldrawsw	//full scr draw                            //~va30I~
    	||  *puf!=0	//line updated                                 //~va30I~
//  	||  (row==csrrow && csrredrawreqcond)                      //~va3jR~
        )                                                          //~va30I~
        {                                                          //~v003I~
//      	lineput(Ppmemdc,Pprintsw,row);                         //~va3kR~
			opt=opt0;                                              //~va3kI~
			if (row==csrdataline)                                  //~va3kI~
				opt|=LPO_CSRBREAK;	//strput split at csr pos      //~va3kI~
          	lineput(opt,Ppmemdc,Pprintsw,row);                     //~va3kR~
		    *puf=0;	//reset line updated                           //~v003I~
        }                                                          //~v003I~
    }                                                              //~v003I~
    if (!Pprintsw)                                                 //~2A27I~
    {                                                              //~v682I~
//      scrruler(Ppmemdc,Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx);//~v78BR~
	    scrcsr();                                                  //~2A27R~
    	if (Mwxeintf.WXEIstatus & WXEIS_DRAWMENU)	//draw menu req by reset key//~v682I~
        {                                                          //~v682I~
    		Mwxeintf.WXEIstatus &=~WXEIS_DRAWMENU;	//processed    //~v682I~
		    ((CMainFrame*)Mpmainframe)->enablemainmenu();	//main menu enable/disable//~v682I~
        }                                                          //~v682I~
    }                                                              //~v682I~
    Mfulldrawsw=0;	//reset                                        //~2914R~
    return;                                                        //~v003I~
}//scrupdate                                                       //~v003R~
//===============================================================================//~v73tI~
//csr process                                                      //~v73tI~
//===============================================================================//~v73tI~
void  CWxemain::scrruler(CDC *Ppmemdc,int Prow,int Pcol)           //~v73tR~
{                                                                  //~v73tI~
    CPoint pt[2];                                                  //~v73tI~
	int xx,yy;                                                     //~v73tR~
//  CPen penn;                                                     //~v73tR~
//************************************                             //~v73tI~
//    if (Mrulermodeo)    //previously written                     //~v73tR~
//        peno.CreatePen(PS_SOLID,0,Mbgcolor);                     //~v73tR~
//  if (Mrulermode)	//vertical line                                //~v73tR~
//  	penn.CreatePen(PS_SOLID,0,Mrulercolor);                    //~v73tR~
////erase prev                                                     //~v73tR~
//    if (Mrulermodeo & WXERULER_V && Mrulercol!=0 && Mrulercol!=Pcol) //col changed//~v73tR~
//    {                                                            //~v73tR~
//        if (!Mfulldrawsw)   //no newed to clear if fulldraw      //~v73tR~
//        {                                                        //~v73tR~
//            xx=XX(Mrulercol)-1;                                  //~v73tR~
//            pt[0].x=xx;                                          //~v73tR~
//            pt[1].x=xx;                                          //~v73tR~
//            pt[0].y=0;                                           //~v73tR~
//            pt[1].y=Mscrheight;                                  //~v73tR~
//            Mpmemdc->SelectObject(peno);   //inner grid;save cuurrent//~v73tR~
//            Ppmemdc->Polyline(pt,2);        //erase line         //~v73tR~
//        }                                                        //~v73tR~
//        Mrulermodeo&=~WXERULER_V;       //erased                 //~v73tR~
//    }                                                            //~v73tR~
//    if (Mrulermodeo & WXERULER_H && Mrulerrow!=0 && Mrulerrow!=Prow)    //col changed//~v73tR~
//    {                                                            //~v73tR~
//        if (!Mfulldrawsw)   //no newed to clear if fulldraw      //~v73tR~
//        {                                                        //~v73tR~
//            yy=YY(Mrulerrow+1)-1;                                //~v73tR~
//            pt[0].x=0;                                           //~v73tR~
//            pt[1].x=Mscrwidth;                                   //~v73tR~
//            pt[0].y=yy;                                          //~v73tR~
//            pt[1].y=yy;                                          //~v73tR~
//            Mpmemdc->SelectObject(peno);   //inner grid;save cuurrent//~v73tR~
//            Ppmemdc->Polyline(pt,2);        //draw line          //~v73tR~
//        }                                                        //~v73tR~
//        Mrulermodeo&=~WXERULER_H;                                //~v73tR~
//    }                                                            //~v73tR~
    if (Mrulermode & (WXERULER_V | WXERULER_H))	//horizontal       //~v78BM~
//      Ppmemdc->SelectObject(Mrulerpen);   //inner grid;save cuurrent//~@@@@R~
        Ppmemdc->SelectPen(Mrulerpen);   //inner grid;save cuurrent//~@@@@I~
//  if (Pcol && Mrulermode & WXERULER_V)	//vertical line        //~v78BR~
    if (Mrulermode & WXERULER_V)	//vertical line                //~v78BI~
    {                                                              //~v73tI~
		xx=XX(Pcol)-1;                                             //~v73tR~
    	pt[0].x=xx;                                                //~v73tI~
    	pt[1].x=xx;                                                //~v73tI~
    	pt[0].y=0;                                                 //~v73tI~
    	pt[1].y=Mscrheight;                                        //~v73tI~
//  	Mpmemdc->SelectObject(penn);   //inner grid;save cuurrent  //~v73tR~
		Ppmemdc->Polyline(pt,2);		//draw line                //~v73tR~
	    Mrulercol=Pcol;                                            //~v73tI~
        Mrulermodeo|=WXERULER_V;                                   //~v73tI~
    }                                                              //~v73tI~
//  if (Prow && Mrulermode & WXERULER_H)	//horizontal           //~v78BR~
    if (Mrulermode & WXERULER_H)	//horizontal                   //~v78BI~
    {                                                              //~v73tI~
		yy=YY(Prow+1)-1;                                           //~v73tR~
    	pt[0].x=0;                                                 //~v73tI~
    	pt[1].x=Mscrwidth;                                         //~v73tI~
    	pt[0].y=yy;                                                //~v73tI~
    	pt[1].y=yy;                                                //~v73tI~
//  	Mpmemdc->SelectObject(penn);   //inner grid;save cuurrent  //~v73tR~
		Ppmemdc->Polyline(pt,2);		//draw line                //~v73tR~
    	Mrulerrow=Prow;                                            //~v73tI~
        Mrulermodeo|=WXERULER_H;                                   //~v73tI~
    }                                                              //~v73tI~
//  if (Mrulermodeo)	//previously written                       //~v73tR~
//  	peno.DeleteObject();                                       //~v73tR~
//  if (Mrulermode)                                                //~v73tR~
//  	penn.DeleteObject();                                       //~v73tR~
    return;                                                        //~v73tI~
}//scrruler                                                        //~v73tI~
#ifdef AAA       //no need to erase(write to memdc but to dc)      //~v78BI~
//===============================================================================//~v73tI~
//csr process                                                      //~v73tI~
//===============================================================================//~v73tI~
void  CWxemain::scrrulererase(int Prow,int Pcol)                   //~v73tR~
{                                                                  //~v73tI~
    UCHAR *puf;                                                    //~v73tI~
//************************************                             //~v73tI~
    if (Mrulermodeo & WXERULER_V)                                  //~v73tI~
    {                                                              //~v73tI~
    	Mfulldrawsw=1;                                             //~v73tI~
		Mrulermodeo&=~WXERULER_V;       //erased                   //~v73tI~
	}                                                              //~v73tI~
    else                                                           //~v73tI~
    if (Mrulermodeo & WXERULER_H && Mrulerrow!=0 && Mrulerrow!=Prow)    //col changed//~v73tI~
    {                                                              //~v73tI~
    	puf=Mwxeintf.WXEIlineupdate;                               //~v73tI~
        puf+=Mrulerrow;                                            //~v73tI~
        *puf=1;		//drw prev line to erase ruler for the case v-split screen//~v73tI~
		Mrulermodeo&=~WXERULER_H;                                  //~v73tI~
    }                                                              //~v73tI~
    return;                                                        //~v73tI~
}//scrruler                                                        //~v73tI~
#endif                                                             //~v78BI~
//===============================================================================//~v73tM~
//open by application                                              //~v73tM~
//===============================================================================//~v73tM~
int CWxemain::scrsetruler(int Ptype)                               //~v73tR~
{                                                                  //~v73tM~
//************************************                             //~v73tM~
    if (Ptype)                                                     //~v73tI~
    {                                                              //~v73tI~
    	if (Mrulermode==Ptype)                                     //~v73tI~
    		Mrulermode=0;                                          //~v73tI~
        else                                                       //~v73tI~
    		Mrulermode=Ptype;                                      //~v73tI~
    }                                                              //~v73tI~
    else                                                           //~v73tI~
    if (++Mrulermode>WXERULER_VH)                                  //~v73tM~
    	Mrulermode=WXERULER_NONE;                                  //~v73tM~
    Mfulldrawsw=1;                                                 //~v73tM~
    scrinvalidate();                                               //~v73tI~
    return Mrulermode;                                             //~v73tM~
}//scrsetruler                                                     //~v73tM~
//===============================================================================//~2914I~
//csr process                                                      //~2914I~
//===============================================================================//~2914I~
int  CWxemain::scrcsr(void)                                        //~2914I~
{                                                                  //~2914I~
	int rc=0;                                                      //~2914I~
    int opt,dbcsid;                                                //~va3aR~
//************************************                             //~2914I~
    if (Mwxeintf.WXEIcsrchangesw)                                  //~2914R~
    {                                                              //~2914I~
	    Mwxeintf.WXEIcsrchangesw=0;		//processed                //~2914M~
    	Mwxeintf.WXEIcsrmovesw=1;	//reset csr pos                //~2914I~
//      rc+=usetcaret(Mwxeintf.WXEIcsrdbcssw,                      //~2915R~
        rc+=usetcaret(0, //for performance use sbcs csr always.    //~2915I~
					Mwxeintf.WXEIcsrhstart,Mcellw,Mcellh,Mfontheight);//~2915I~
        rc+=ushowcaret();                                          //~2914I~
    }                                                              //~2914I~
    if (Mwxeintf.WXEIcsrvisiblechangesw)                           //~2914R~
    {                                                              //~2914I~
	    Mwxeintf.WXEIcsrvisiblechangesw=0;		//processed        //~2914M~
    	if (Mwxeintf.WXEIcsrvisible)                               //~2914R~
        	rc+=ushowcaret();	                                   //~2914R~
        else                                                       //~2914I~
        	rc+=uhidecaret();                                      //~2914R~
    }                                                              //~2914I~
    if (Mwxeintf.WXEIcsrmovesw)	//csr moved                        //~2914M~
    {                                                              //~2914M~
//  	Mwxeintf.WXEIcsrmovesw=0;	//processed                    //~2914M~//~va7DR~
//  	rc+=usetcaretpos(Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx);//~2914R~//~va3aR~
	    dbcsid=(int)*(TEXTDBCS(Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx));//~va3aI~
		if (UDBCSCHK_DBCS1STLU(dbcsid))   	//1:dbcs1st            //~va3aR~
        	opt=USCPO_DBCS1ST;     //pos is dbcs1st                //~va3aI~
        else                                                       //~va3aI~
        	opt=0;                                                 //~va3aI~
		rc+=usetcaretpos(opt,Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx);//~va3aI~
//      if (Mwxeintf.WXEIcsrmovesw==2)  //not by mouse but kbd     //~va7DI~//~va7SR~
            mouse_csrmovedbykbd(0);        //update toolbar menu item//~va7DI~
    	Mwxeintf.WXEIcsrmovesw=0;	//processed                    //~va7DI~
    }                                                              //~2914M~
    else                                                           //~va7QI~
    {                                                              //~va7QI~
	    dbcsid=(int)*(TEXTDBCS(Mwxeintf.WXEIcsrposy,Mwxeintf.WXEIcsrposx));//~va7QI~
		if (UDBCSCHK_DBCS1STLU(dbcsid))   	//1:dbcs1st            //~va7QI~
        	opt=USCPO_DBCS1ST;     //pos is dbcs1st                //~va7QI~
        else                                                       //~va7QI~
            opt=0;                                                 //~va7QI~
        rc+=usetcaretwidthchngchk(opt);                            //~va7QI~
    }                                                              //~va7QI~
    return rc;                                                     //~2914I~
}//scrcsr                                                          //~2914I~
//===============================================================================//~v003I~
//1 line write                                                     //~v003I~
//===============================================================================//~v003I~
//int  CWxemain::lineput(CDC *Ppmemdc,int Pprintsw,int Prow)       //~va3kR~
int  CWxemain::lineput(int Popt,CDC *Ppmemdc,int Pprintsw,int Prow)//~va3kI~
{                                                                  //~v003I~
    USHORT *pattr,attr;                                            //~v003I~
    int col,totlen,len,colstart;                                   //~2A05R~
    int inboxswn,inboxsw;                                          //~2A05R~
    int nextcolstart;                                              //~v69SI~
    CPoint pt1,pt2;                                                //~2A01I~
    char *pdbcs;                                                   //~v69SI~
    char *pstyle,style;                                            //~v780R~
#ifdef UTF8UCS2                                                    //~va20I~
	int dbcsid;                                                    //~va20R~
    int csrposbreaksw,csrpos,csrposnext,csrposprev;                //~va30R~
    int vhexcol;                                                   //~va3tR~
#endif                                                             //~va20I~
	int linenofldsz[2];                                            //~vb3pR~
//************************************                             //~v003I~
	pattr=TEXTATTR(Prow,0);                                        //~2901R~
	pstyle=(char*)TEXTSTYLE(Prow,0);                               //~v780R~
    totlen=Mscrcmaxcol;                                            //~v003I~
	UTRACEP("lineput row=%d,opt=%x\n",Prow,Popt);                              //~2914I~//~va6uR~
	UTRACED("line data",TEXTDATA(Prow,0),totlen);                  //~2914I~
	UTRACED("line dbcs",TEXTDBCS(Prow,0),totlen);                  //~2914I~
	UTRACED("line attr",TEXTATTR(Prow,0),totlen);                  //~2914I~
	UTRACED("line style",pstyle,totlen);                           //~v780I~
    len=0;                                                         //~2901R~
    attr=*pattr;                                                   //~2901I~
    style=*pstyle;	//top byte may be set no use                   //~v780R~
    if (Mcpcopypansw)	//pan copy                                 //~2A05I~
    {                                                              //~2A05R~
        pt1=Mcellcopy1;                                            //~2A05R~
        pt2=Mcellcopy2;                                            //~2A05R~
        CAPGETBOX(pt1,pt2);  //get let top and right bottom        //~2A05R~
        inboxsw=CAPCHKINBOX(pt1,pt2,Prow,0);	//attr of col 0    //~2A05R~
    }                                                              //~2A05R~
    else                                                           //~2A05R~
        inboxsw=-1;     //id of line is out of range               //~2A05R~
    colstart=0;                                                    //~2A05I~
    pdbcs=(char*)TEXTDBCS(Prow,0);  //top of the line              //~v69SI~
#ifdef UTF8UCS2                                                    //~va30I~
//    csrposbreaksw=( (Prow==Mwxeintf.WXEIcsrposy)                 //~va3kR~
////                  && Sswcsrlinedd==1    //line is dd fmt       //~va3kR~
//                  );                                             //~va3kR~
    csrposbreaksw=(Popt & LPO_CSRBREAK);                           //~va3kI~
	csrpos=csrposnext=csrposprev=-1;                               //~va30R~
    if (csrposbreaksw)                                             //~va30I~
    {                                                              //~va30I~
      if (Popt & LPO_VHEX)                                         //~va3tR~
      {                                                            //~va3tI~
        vhexcol=LPO_GETVHEXPOS(Popt);                              //~va3tI~
		csubgetcsrposbf(UTFDDGSP_ALSOLOCAL,pdbcs,Mscrcmaxcol,vhexcol,&csrposprev,&csrpos,0/*next*/);//~va3tR~
	  }                                                            //~va3tI~
      else                                                         //~va3tI~
		csubgetcsrposbf(UTFDDGSP_ALSOLOCAL,pdbcs,Mscrcmaxcol,Mwxeintf.WXEIcsrposx,&csrposprev,&csrpos,&csrposnext);//~va3kR~
    }                                                              //~va30I~
#endif                                                             //~va30I~
  	xxe_getlinenofldsz(0,Prow,linenofldsz);	//-1 if not fileedit line,split lineno fld and filedata for ligature//~vb3pR~
//  for (col=0;col<totlen;col++,pattr++,len++)                     //~v69SR~
//  for (col=0;col<totlen;col++,pattr++,pdbcs++)                   //~v780R~
    for (col=0;col<totlen;col++,pattr++,pdbcs++,pstyle++)          //~v780I~
    {                                                              //~v003I~
        if (inboxsw>=0)	//row is in the cap range                  //~2A05R~
            inboxswn=CAPCHKINBOX(pt1,pt2,Prow,col);                //~2A05R~
        else                                                       //~2A05R~
            inboxswn=-1;                                           //~2A05R~
//      if (attr!=*pattr || inboxswn!=inboxsw)                     //~v780R~
        if (                                                       //~v780I~
			attr!=*pattr                                           //~v780I~
		||  (!Pprintsw && style!=*pstyle)                          //~v780R~
		||  (col==csrposprev||col==csrpos||col==csrposnext)	//to keep csr position char//~va30R~
		|| inboxswn!=inboxsw                                       //~v780I~
        || col==linenofldsz[0] || col==linenofldsz[1]              //~vb3pR~
        )                                                          //~v780I~
        {                                                          //~v003I~
#ifdef UTF8UCS2                                                    //~va20I~
			dbcsid=*pdbcs;                                         //~va20I~
            if (inboxswn==1 && inboxsw==0 && UDBCSCHK_DBCSNOT1ST(dbcsid))//~va20I~
#else                                                              //~va20I~
            if (inboxswn==1 && inboxsw==0 && *pdbcs==UDBCSCHK_DBCS2ND)//left boundary split dbcs//~v69SI~
#endif                                                             //~va20I~
	            nextcolstart=col+1;                                //~v69SR~
            else                                                   //~v69SI~
#ifdef UTF8UCS2                                                    //~va20I~
            if (inboxswn==0 && inboxsw==1 && UDBCSCHK_DBCSNOT1ST(dbcsid))//right boundary split dbcs//~va20I~
#else                                                              //~va20I~
            if (inboxswn==0 && inboxsw==1 && *pdbcs==UDBCSCHK_DBCS2ND)//right boundary split dbcs//~v69SI~
#endif                                                             //~va20I~
	            nextcolstart=col-1;  //next start col by dbcs 1st  //~v69SR~
            else                                                   //~v69SI~
	            nextcolstart=col;  //next start col by dbcs 1st    //~v69SI~
            len=nextcolstart-colstart;                             //~v69SI~
UTRACEP("row=%d,colstart=%d,len=%d,attr=%x,inbox=%d\n",Prow,colstart,len,attr,inboxsw);//~v69SM~
          if (len>0)                                               //~v69SI~
//          strput(Ppmemdc,Pprintsw,Prow,colstart,len,attr,inboxsw);//~v780R~
            strput(Ppmemdc,Pprintsw,Prow,colstart,len,attr,style,inboxsw);//~v780R~
        	attr=*pattr;                                           //~v003I~
        	style=*pstyle;                                         //~v780I~
//          colstart=col;                                          //~v69SR~
            colstart=nextcolstart;                                 //~v69SI~
            inboxsw=inboxswn;                                      //~2A05R~
            len=0;                                                 //~v003I~
        }                                                          //~v003I~
    }                                                              //~v003I~
    len=totlen-colstart;                                           //~v69SI~
    if (len)                                                       //~2901I~
// 		strput(Ppmemdc,Pprintsw,Prow,colstart,len,attr,inboxsw);   //~v780R~
   		strput(Ppmemdc,Pprintsw,Prow,colstart,len,attr,style,inboxsw);//~v780R~
	if (style!=WXEFONTSTYLE_NORMAL)                                //~v780R~
	if (style!=WXEFONTSTYLE_NOSYNTAX)   //nosyntax is same as normal//~va77I~
    {                                                              //~va74I~
//  	Ppmemdc->SelectObject(Mpfont);  //back to normal for next line(it may not be drawn this yime)//~@@@@R~
    	Ppmemdc->SelectFont(HFONT(*Mpfont));  //back to normal for next line(it may not be drawn this yime)//~@@@@R~
UTRACEP("CREATEFONT lineput backto normal style=%d,font=%p\n",style,Mpfont);//~va74R~
    }                                                              //~va74I~
    return 0;                                                      //~v003I~
}//lineput                                                         //~v003R~
//===============================================================================//~2901I~
//1 line write                                                     //~2901I~
//parm:capsw:-1:no cap line,0:cap line but out of range,1:str in cap range//~2A01I~
//===============================================================================//~2901I~
//int  CWxemain::strput(CDC *Ppmemdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pcapsw)//~v780R~
int  CWxemain::strput(CDC *Ppmemdc,int Pprintsw,int Prow,int Pcol,int Plen,USHORT Pattr,int Pstyle,int Pcapsw)//~v780I~
{                                                                  //~2901I~
    char   *pdata,*pdbcs;                                          //~2901I~
//  unsigned    fgcolor,bgcolor;                                   //~vb4iR~
    unsigned    fgcolor=0,bgcolor=0;                               //~vb4iR~
    int  ii,xx,yy,fgpal,bgpal,rr,gg,bb,cellh,cellw;                //~2A20R~
    int dbcssw;                                                    //~v653I~
#define PANCOLAJUST 20                                             //~2A05R~
    RECT rect;                                                     //~2A05R~
#ifdef UTF8UCS2                                                    //~va20I~
	int swutf8data;                                                //~va20R~
	int opt;                                                       //~va30I~
#endif                                                             //~va20I~
    WUCS ucs;                                                      //~va42I~
    WUCS ucsalt;                                                   //~va44I~
    int optaltch,swaltch;                                          //~va46R~
    int swlocaleligature=0;                                        //~@@@@R~
    int mblen;                                                     //~vb2KI~
    int lineopt;                                                   //~vb4iR~
//************************************                             //~2901I~
//	rc_ligature=wxe_chkligaturerow(0,NULL,Prow,Pcol,&rrow);        //~vb4iR~
  	lineopt=wxe_getlineopt(0,Prow,Pcol);                           //~vb4iR~
    xx=XX(Pcol);                                                   //~2A27M~
    yy=YY(Prow);                                                   //~2A27M~
    cellh=Mcellh;                                                  //~2A27M~
    cellw=Mcellw;                                                  //~2A27M~
    if (Pprintsw)                                                  //~2A27M~
    {                                                              //~2A27I~
        Ppmemdc->SetTextColor(PRINT_BW_FGCOLOR);                   //~2A27I~
        Ppmemdc->SetBkColor(PRINT_BW_BGCOLOR);                     //~2A27I~
    }                                                              //~2A27I~
    else                                                           //~2A27I~
    {                                                              //~2A27M~
UTRACEP("strput row=%d,col=%d,style=%d,len=%d\n",Prow,Pcol,Pstyle,Plen);//~v780I~
		if (Pstyle==WXEFONTSTYLE_NOSYNTAX) //not syntax highlight part//~v780R~
        {                                                          //~va74I~
//  		Ppmemdc->SelectObject(Mpfont);                         //~@@@@R~
    		Ppmemdc->SelectFont(HFONT(*Mpfont));                   //~@@@@R~
UTRACEP("CREATEFONT strput normal style=%d,font=%p\n",Pstyle,Mpfont);//~va74R~
		}                                                          //~va74I~
        else                                                       //~v780I~
        {                                                          //~va74I~
//  		Ppmemdc->SelectObject(Mpfonts[Pstyle]);                //~@@@@R~
    		Ppmemdc->SelectFont(HFONT(*(Mpfonts[Pstyle])));        //~@@@@R~
UTRACEP("CREATEFONT strput syntax=%d font=%p\n",Pstyle,Mpfonts[Pstyle]);//~va74I~
        }                                                          //~va74I~
        if (Pcapsw==1)                                             //~2A27R~
        {                                                          //~2A27R~
            bgpal=Pattr & 0x0f;                                    //~2A27R~
            fgpal=(Pattr>>4) & 0x0f;                               //~2A27R~
        }                                                          //~2A27R~
        else                                                       //~2A27R~
        {                                                          //~2A27R~
            fgpal=Pattr & 0x0f;                                    //~2A27R~
            bgpal=(Pattr>>4) & 0x0f;                               //~2A27R~
        }                                                          //~2A27R~
                                                                   //~2A27R~
	  if (Pcapsw==1 || Pstyle==WXEFONTSTYLE_NOSYNTAX) //capcopy on pan or not syntax highlight part//~v780R~
      {                                                            //~v780I~
        fgcolor=Mwxeintf.WXEIpalrgb[fgpal];                        //~2A27R~
        bgcolor=Mwxeintf.WXEIpalrgb[bgpal];                        //~2A27R~
      }                                                            //~v780I~
      else                                                         //~v780M~
      {                                                            //~v780M~
        fgcolor=Mwxeintf.WXEIsynrgb[fgpal];                        //~v780M~
        if ((fgcolor & WXE_SYNTAXRGB))                             //~v780R~
	        fgcolor&=~WXE_SYNTAXRGB;                               //~v780I~
        else                                                       //~v780I~
	        fgcolor=Mwxeintf.WXEIpalrgb[fgpal];                    //~v780I~
        bgcolor=Mwxeintf.WXEIsynrgb[bgpal];                        //~v780M~
        if ((bgcolor & WXE_SYNTAXRGB))                             //~v780R~
	        bgcolor&=~WXE_SYNTAXRGB;                               //~v780I~
        else                                                       //~v780I~
	        bgcolor=Mwxeintf.WXEIpalrgb[bgpal];                    //~v780I~
      }                                                            //~v780M~
                                                                   //~2A05I~
        if (Pcapsw==1)                                             //~2A27R~
        {                                                          //~2A27R~
            rr=RGB_GETRED(bgcolor);                                //~2A27R~
            gg=RGB_GETGREEN(bgcolor);                              //~2A27R~
            bb=RGB_GETBLUE(bgcolor);                               //~2A27R~
            if (rr<128)                                            //~2A27R~
                rr+=PANCOLAJUST;                                   //~2A27R~
            else                                                   //~2A27R~
                rr-=PANCOLAJUST;                                   //~2A27R~
            if (gg<128)                                            //~2A27R~
                gg+=PANCOLAJUST;                                   //~2A27R~
            else                                                   //~2A27R~
                gg-=PANCOLAJUST;                                   //~2A27R~
            if (bb<128)                                            //~2A27R~
                bb+=PANCOLAJUST;                                   //~2A27R~
            else                                                   //~2A27R~
                rr-=PANCOLAJUST;                                   //~2A27R~
            bgcolor=RGB_MAKE(rr,gg,bb);                            //~2A27R~
        }                                                          //~2A27R~
	  if (Pcapsw==1 || Pstyle==WXEFONTSTYLE_NOSYNTAX) //cap or not syntax highlight part//~v780R~
        if (!bgcolor)   //bk color=0                               //~2A27R~
            bgcolor=Mbgcolor;                                      //~2A27R~
//      CBrush  br(bgcolor);                                       //~@@@@R~
        CBrush  br;                                                //~@@@@I~
    	br.CreateSolidBrush(bgcolor);                              //~@@@@I~
        rect.top=yy;                                               //~2A27R~
        rect.left=xx;                                              //~2A27R~
        if (!Pprintsw && Prow==Mscrcmaxrow-1) //last row           //~2A27R~
            rect.bottom=Mscrheight;                                //~2B23R~
        else                                                       //~2A27R~
            rect.bottom=yy+cellh;                                  //~2B23R~
        rect.right=xx+Plen*cellw;                                  //~2B23R~
//      Ppmemdc->FillRect(&rect,&br);                              //~@@@@R~
        Ppmemdc->FillRect(&rect,br);                               //~@@@@I~
                                                                   //~2A27R~
        Ppmemdc->SetTextColor(fgcolor);                            //~2A27R~
        Ppmemdc->SetBkColor(bgcolor);                              //~2A27R~
    }                                                              //~2A27M~
    pdata=(char*)TEXTDATA(Prow,Pcol);                              //~2901R~
    pdbcs=(char*)TEXTDBCS(Prow,Pcol);                              //~2901R~
    UTRACED("strput data",pdata,Plen);                             //~va46I~
    UTRACED("strput dbcs",pdbcs,Plen);                             //~va46I~
#ifdef UTF8UCS2                                                    //~va20M~
    	swutf8data=csubchkdd(0,pdbcs,Plen)*SPO_DDFMT;                  //~va20I~
  	if (!swutf8data)                                               //~va6uI~
  	{                                                              //~va6uI~
    	swlocaleligature=0;                                        //~va6uR~
//      if (wxe_optligature(WXEIOLO_ISON,0/*pvalue*/))             //~vb4iR~
        if (WXE_LIGATUREMODE(lineopt))                             //~vb4iR~
          if (lineopt & UVIOO_CSRPOSCHK)                           //~vb4iR~
  			if (!xxe_chkcsrpos(XXECCPO_STRCHK,Prow,Pcol,0/*fileinfo*/))//chk disable ligature for each str//~va6uI~
				swlocaleligature=1;	                               //~va6uR~
    }                                                              //~va6uI~
  if (swutf8data)                                                  //~va20R~
  {                                                                //~va20M~
//  csubtextoutw(0,Ppmemdc->m_hDC,xx,yy,pdata,pdbcs,Plen,cellw);   //~va20R~//~va30R~
    opt=CSTOWO_COMBINECHK;                                         //~va30I~
//  	csubtextoutw(opt,Ppmemdc->m_hDC,xx,yy,pdata,pdbcs,Plen,cellw);//~vb4iR~
//	csubtextoutw(opt,lineopt,Ppmemdc->m_hDC,xx,yy,pdata,pdbcs,Plen,cellw,fgcolor,bgcolor);//+vb4iR~
  	csubtextoutw(opt,lineopt,Ppmemdc->m_hDC,xx,yy,pdata,pdbcs,Plen,cellw);//+vb4iI~
  }                                                                //~va20M~
  else                                                             //~va20M~
#endif                                                             //~va20M~
  if (swlocaleligature)                                            //~va6uR~
	csubtextoutw_locale_ligature(0,Ppmemdc->m_hDC,xx,yy,pdata,pdbcs,Plen);//~va6uR~
  else                                                             //~va6uI~
  {                                                                //~va20M~
    dbcssw=0;                                                      //~v653I~
    ucsalt=0;                                                      //~va44I~
    for (ii=0;ii<Plen;ii++,pdata++,pdbcs++,xx+=cellw)              //~2A20R~
    {                                                              //~2901I~
        if (!*pdata)                                               //~2901I~
            *pdata=' ';                                            //~2901I~
        ucs=(WUCS)*pdata;                                          //~va42I~
//*not dd fmt                                                      //~va20I~
        if (*pdbcs==UDBCSCHK_DBCS1ST && (ii+1)<Plen)               //~2C08R~
        {                                                          //~v653I~
  UTRACEP("dbcs ii=%d,%02x,%02x\n",ii,*pdata,*(pdata+1));          //~v78BR~
//        if (ucs>=0x20||!csubtextoutw1alt(0,Ppmemdc->m_hDC,xx,yy,ucs))	//alt ch not written//~va42I~//~va44R~
            ucsalt=0;                                              //~va44I~
          if (ucs==Mwxeintf.WXEIunpdispchar[3] && *(pdata+1)==ucs)    //dbcsspace altch,may changed by ini file//~vb3qR~
          {                                                        //~vb3qI~
	          ucsalt=(WUCS)csubtextoutw1alt(UTFGVACO_DBCSSPACE,Ppmemdc->m_hDC,xx,yy,ucs); 
              if (!ucsalt)                                         //no altch defined//~vb3qM~
              	ucsalt=(WUCS)csubtextoutw1alt(CSUBTOWAO_FORCE,Ppmemdc->m_hDC,xx,yy,ucs);//~vb3qR~
              dbcssw=1;                                            //~vb3qI~
          }                                                        //~vb3qI~
          else                                                     //~vb3qI~
          if (ucs<0x20)                                            //~va44R~
//            ucsalt=csubtextoutw1alt(0,Ppmemdc->m_hDC,xx,yy,ucs); //~va44R~//~vb2JR~
              ucsalt=(WUCS)csubtextoutw1alt(0,Ppmemdc->m_hDC,xx,yy,ucs);//~vb2JI~
          else                                                     //~va44R~
////        if (ucs==DBCSSPACE_ALT && *(pdata+1)==DBCSSPACE_ALT)    //default DBCSSPACE altch//~va46R~//~vb3qR~
//          if (ucs==DEFAULT_ALTCH && *(pdata+1)==DEFAULT_ALTCH)    //default DBCSSPACE altch//~va46I~//~vb3qR~
//          {                                                        //~vb3oI~//~vb3qR~
////            ucsalt=csubtextoutw1alt(0,Ppmemdc->m_hDC,xx,yy,ucs); //~va46R~//~vb3qR~
////            ucsalt=csubtextoutw1alt(UTFGVACO_DBCSSPACE,Ppmemdc->m_hDC,xx,yy,ucs);//~va46I~//~vb2JR~//~vb3qR~
//              ucsalt=(WUCS)csubtextoutw1alt(UTFGVACO_DBCSSPACE,Ppmemdc->m_hDC,xx,yy,ucs);//~vb2JI~//~vb3qR~
//              dbcssw=1;                                            //~vb3oI~//~vb3qR~
//          }                                                        //~vb3oI~//~vb3qR~
//          else                                                     //~va44R~//~vb3qR~
          if (ucs<0x80)                                            //~va44R~
//            ucsalt=csubtextoutw1alt(CSUBTOWAO_FORCE,Ppmemdc->m_hDC,xx,yy,ucs);//~va44R~//~vb2JR~
              ucsalt=(WUCS)csubtextoutw1alt(CSUBTOWAO_FORCE,Ppmemdc->m_hDC,xx,yy,ucs);//~vb2JI~
          else                                                     //~va44I~
          {                                                        //~vb2KI~
//          Ppmemdc->TextOut(xx,yy,pdata,2);                       //~2A20R~//~va6vR~
//          csubtextoutw1_locale(0,Ppmemdc->m_hDC,xx,yy,pdata,2);  //~va6vI~//~va74R~
//          csubtextoutw1_locale(CSTOW1LO_NOTRANS,Ppmemdc->m_hDC,xx,yy,pdata,2);//~va74I~//~vb2KR~
            mblen=UDBCSCHK_PCD_MBCHSZ(pdbcs,Plen-ii);              //~vb2KI~
            csubtextoutw1_locale(CSTOW1LO_NOTRANS,Ppmemdc->m_hDC,xx,yy,pdata,mblen);//~vb2KI~
           if (mblen>1) //dbcs noit split                          //~vb2KI~
            dbcssw=1;                                              //~v653I~
          }                                                        //~vb2KI~
        }                                                          //~v653I~
        else                                                       //~2901I~
//*not dd fmt                                                      //~va20I~
//      if (*pdbcs==UDBCSCHK_DBCS2ND)                              //~2901I~//~vb2KR~
        if (*pdbcs==UDBCSCHK_DBCS2ND||*pdbcs==UDBCSCHK_DBCSPAD)    //~vb2KR~
        {                                                          //~v653I~
          if (dbcssw)                                              //~v653I~
          {                                                        //~va42I~
          	if (ucsalt)                                          //~va42I~//~va44R~
				csubtextoutw1alt(CSUBTOWAO_FORCE,Ppmemdc->m_hDC,xx,yy,ucsalt);	//alt ch not written//~va42R~//~va44R~
            continue;                                              //~2901I~
          }                                                        //~va42I~
//          Ppmemdc->TextOut(xx,yy,pdata,1);                       //~v653I~//~va6vR~
//          csubtextoutw1_locale(0,Ppmemdc->m_hDC,xx,yy,pdata,1);  //~va6vI~//~va74R~
            csubtextoutw1_locale(CSTOW1LO_NOTRANS,Ppmemdc->m_hDC,xx,yy,pdata,1);//~va74I~
  UTRACEP("dbcs2 ii=%d,%02x\n",ii,*pdata);                         //~v78BR~
        }                                                          //~v653I~
        else                                                       //~2901I~
        {                                                          //~v653I~
            dbcssw=0;                                              //~v653I~
          optaltch=UTF_GETALTCH_SBCSID(*pdbcs);                    //~va46R~
          if (optaltch>=0)	//not tab/unp                          //~va46R~
          	swaltch=csubtextoutw1alt(optaltch,Ppmemdc->m_hDC,xx,yy,ucs);	//alt ch not written//~va46R~
          else                                                     //~va46I~
          if (ucs<0x20)                                            //~va46I~
			swaltch=csubtextoutw1alt(0,Ppmemdc->m_hDC,xx,yy,ucs);  //~va46R~
          else                                                     //~va46I~
          	swaltch=0;                                             //~va46R~
          if (!swaltch)                                            //~va46R~
//          Ppmemdc->TextOut(xx,yy,pdata,1);                       //~2A20R~//~va6vR~
//          csubtextoutw1_locale(0,Ppmemdc->m_hDC,xx,yy,pdata,1);  //~va6vI~//~va74R~
            csubtextoutw1_locale(CSTOW1LO_NOTRANS,Ppmemdc->m_hDC,xx,yy,pdata,1);//~va74I~
  UTRACEP("sbcs ii=%d,%02x\n",ii,*pdata);                          //~v78BR~
        }                                                          //~v653I~
    }                                                              //~2901I~
  }                                                                //~va20I~
    return 0;                                                      //~2901I~
}//strput                                                          //~2901I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
int  CWxemain::createfont()                                        //~v003I~
{                                                                  //~v003I~
	int ii;                                                        //~v780I~
//************************************                             //~v003I~
//  if (Mpfont)                                                    //~v780R~
//  	delete Mpfont;                                             //~v780R~
    for (ii=WXEFONTSTYLE_NORMAL;ii<WXEFONTSTYLE_MAX;ii++)          //~v780R~
    {                                                              //~v780I~
	  	if (Mpfonts[ii])                                           //~v780R~
		  	delete Mpfonts[ii];                                    //~v780I~
    }                                                              //~v780I~
	Mpfont=createfontsub(Mcharset,Mfontstyle,Mttfont,Mfontheight,Mfontwidth,0);//~2B23R~
    Mpfonts[WXEFONTSTYLE_NORMAL]     =Mpfont;                      //~v780R~
    for (ii=WXEFONTSTYLE_NORMAL+1;ii<WXEFONTSTYLE_MAX;ii++)        //~v780R~
		Mpfonts[ii]=createfontsub(Mcharset,Mfontstyle,Mttfont,Mfontheight,Mfontwidth,(ii<<8));//~v780I~
	return 0;                                                      //~v003I~
}//createfont                                                      //~v003I~
//**************************************************************** //~3601I~
//*                                                                //~3601I~
//**************************************************************** //~3601I~
int  CWxemain::createfontlist(CComboBox *Ppcombo,char *Pcurfont)   //~3601R~
{                                                                  //~3601I~
    LOGFONT elftbl[MAXELF];                                        //~3601I~
    int ii,fontstylectr;                                           //~3601I~
    char *pc;                                                      //~3601I~
    HDC hdc;                                                       //~3601I~
//********************************                                 //~3601I~
    hdc=Mpmemdc->m_hDC;                                            //~3601R~
    fontstylectr=enumfont(hdc,elftbl,MAXELF);                      //~3601R~
    for (ii=0;ii<fontstylectr;ii++)                                //~3601I~
    {                                                              //~3601I~
	    pc=(char *)(elftbl[ii].lfFaceName);                        //~3601I~
	    Ppcombo->AddString(pc);                                    //~3601I~
    }                                                              //~3601I~
	Ppcombo->SelectString(-1,Pcurfont);                            //~3601R~
    return fontstylectr;                                           //~3601I~
}//createfontlist                                                  //~3601I~
//===============================================================================//~2928I~
//                                                                 //~2928I~
//===============================================================================//~2928I~
CFont *CWxemain::createfontsub(int Pcharset,char *Pfontstyle,int Ptruetype,//~2928R~
								int Pfontheight,int Pfontwidth,int Poutprec)//~2B23R~
{                                                                  //~2928I~
    int outprec,charset;                                           //~2928I~
    int style,weight,italic,underline;                             //~v780I~
//  CFont *pfont =new CFont;                                       //~2928I~//~@@@@R~
    CFont *pfont =new CFont();                                     //~@@@@I~
//************************************                             //~2928I~
    charset=Pcharset;                                              //~2928I~
//    if (!wxe_iswinnt()) //win95/98                               //~2C03R~
//        if (Pfontstyle && !strcmp(Pfontstyle,DEF_DOSFONT)) //terminal//~2C03R~
//        {                                                        //~2C03R~
//            if (charset==SHIFTJIS_CHARSET)                       //~2C03R~
//                charset=0xfe;       //not defined on wingdi.h but on pifmgr.dll through xda//~2C03R~
//            else                                                 //~2C03R~
//                charset=OEM_CHARSET;                             //~2C03R~
//        }                                                        //~2C03R~
//  if (!(outprec=Poutprec))                                       //~v780R~
    style=(Poutprec&0xff00)>>8;                                    //~v780R~
    if (!(outprec=(Poutprec&0xff)))                                //~v780R~
        if (Ptruetype)                                             //~2B23R~
            outprec=OUT_TT_PRECIS;      //output precision:true type//~2B23R~
        else                                                       //~2B23R~
            outprec=OUT_DEFAULT_PRECIS;      //output precision    //~2B23R~
UTRACEP("createfont type=%s,h=%d,w=%d truetype=%d,h=%d,outprecision=%d,charset=%d\n",//~2C02R~
				Pfontstyle,Pfontheight,Pfontwidth,Ptruetype,Pfontheight,outprec,charset);//~2C02R~
    weight=FW_NORMAL;                                              //~v780I~
    underline=FALSE;                                               //~v780I~
    italic=FALSE;                                                  //~v780I~
    switch(style)                                                  //~v780R~
    {                                                              //~v780I~
    case WXEFONTSTYLE_BOLD:                                        //~v780R~
	    weight=FW_BOLD;                                            //~v780I~
    	break;                                                     //~v780I~
    case WXEFONTSTYLE_UNDERLINE:                                   //~v780R~
	    underline=TRUE;                                            //~v780I~
    	break;                                                     //~v780I~
    case WXEFONTSTYLE_ITALIC:                                      //~v780R~
	    italic=TRUE;                                               //~v780R~
    	break;                                                     //~v780I~
    }                                                              //~v780I~
    if (!pfont->CreateFont(Pfontheight,	//font height              //~2928R~
					 Pfontwidth,   //font width                    //~2B23R~
//                   0,0,FW_NORMAL,           //escapement,orientation,weight//~v780R~
                     0,0,weight,              //escapement,orientation,weight//~v780I~
//                   0,0,0,                   //italic,underline,strikeout//~v780R~
//                   italic,underline,0,                   //italic,underline,strikeout//~v780I~//~vb2JR~
                     (BYTE)italic,(BYTE)underline,0,                   //italic,underline,strikeout//~vb2JI~
//                   charset,              //from dialog           //~2928I~//~vb2JR~
                     (BYTE)charset,              //from dialog     //~vb2JI~
//                   outprec,                //output precision    //~2928I~//~vb2JR~
                     (BYTE)outprec,                //output precision//~vb2JI~
                     CLIP_DEFAULT_PRECIS,     //clip precision     //~2928I~
//                   DEFAULT_QUALITY,         //quality            //~2928I~
//                   PROOF_QUALITY,         //quality.scaling na for raster font//~2C03R~
                     DRAFT_QUALITY,         //quality,scaling avail for raster font//~2C03R~
//                   FIXED_PITCH|FF_MODERN, //pitch and family     //~2928I~
                     FIXED_PITCH          , //pitch and family     //~2928I~
                     Pfontstyle))      //face                      //~2928R~
        uerrlast("CreateFont");                                    //~2928I~
UTRACEP("CREATEFONT createfontsub font=%p\n",pfont);               //~va74I~
	return pfont;                                                  //~2928I~
}//createfontsub                                                   //~2928I~
//===============================================================================//~2901I~
//                                                                 //~2901I~
//===============================================================================//~2901I~
void CWxemain::scrinvalidate()                                     //~2908R~
{                                                                  //~2901I~
//************************************                             //~2901I~
    Mpview->Invalidate(FALSE);                                     //~2901I~
    return;                                                        //~2901I~
}//scrinvalidate                                                   //~2908R~
//===============================================================================//~2922I~
//                                                                 //~2922I~
//===============================================================================//~2922I~
void CWxemain::onsetfocus(CWnd* pOldWnd)                           //~2922R~
{                                                                  //~2922I~
    struct _timeb ctm;                                             //~v63rR~
UTRACEP("active onsetfocus old wnd=%x\n",pOldWnd);                 //~v63rR~
    if (Mxeinitsw)      	    //xe init called                   //~2922I~
		uredrawcaret();                                            //~2922I~
//  Mswkillfocus=0;             //by frame window clicked          //~v63rR~
	_ftime(&ctm);		//chk later lbdown                         //~v63rR~
	Msetfocustime=ctm.time;		//chk later lbdown                 //~v63rI~
	Msetfocusmsec=ctm.millitm;		//chk later lbdown             //~v63rI~
    return;                                                        //~2922I~
}//onsetfocus                                                      //~2922I~
//===============================================================================//~2922I~
//                                                                 //~2922I~
//===============================================================================//~2922I~
void CWxemain::onkillfocus(CWnd* pNewWnd)                          //~2922R~
{                                                                  //~2922I~
//************************************                             //~2922I~
UTRACEP("active onkillfocus new wnd=%x\n",pNewWnd);                //~v63rR~
    if (Mxeinitsw)      	    //xe init called                   //~2922I~
		DestroyCaret();                                            //~2922I~
    Mswkillfocus=1;             //ignore 1st click after kill focus//~v63rI~
    return;                                                        //~2922I~
}//onkillfocus                                                     //~2922I~
//===============================================================================//~3102I~
//End command by popup menu                                        //~3102I~
//===============================================================================//~3102I~
int CWxemain::scrend(void)                                         //~3102R~
{                                                                  //~3102I~
    return scrcmd(WXEOF_END,"");                                   //~3102R~
}//scrend                                                          //~3102I~
//===============================================================================//~3102I~
//Cancel command by popup menu                                     //~3102I~
//===============================================================================//~3102I~
int CWxemain::scrcancel(void)                                      //~3102R~
{                                                                  //~3102I~
    return scrcmd(WXEOF_CANCEL,"");                                //~3102R~
}//scrcancel                                                       //~3102I~
//===============================================================================//~3102I~
//End command by popup menu                                        //~3102I~
//===============================================================================//~3102I~
int CWxemain::scrcmd(int Pfuncid,char *Pparm)                      //~3102R~
{                                                                  //~3102I~
    int rc;                                                        //~3102I~
//************************************                             //~3102I~
    rc=wxe_otherfunc(Pfuncid,Pparm);                               //~3102R~
    if (rc==-1)                                                    //~3102I~
    	exitmain();                                                //~3102I~
    Mpview->Invalidate(FALSE);                                     //~3102I~
    return rc;                                                     //~3102R~
}//scrcmd                                                          //~3102I~
//===============================================================================//~v51wI~
//End command by popup menu                                        //~v51wI~
//===============================================================================//~v51wI~
int CWxemain::strcmd(char *Pcmd,char *Pparm)                       //~v51wI~
{                                                                  //~v51wI~
    int rc;                                                        //~v51wI~
//************************************                             //~v51wI~
    rc=wxe_strcmd(Pcmd,Pparm);                                     //~v51wI~
    if (rc==-1)                                                    //~v51wI~
    	exitmain();                                                //~v51wI~
    Mpview->Invalidate(FALSE);                                     //~v51wI~
    return rc;                                                     //~v51wI~
}//scrcmd                                                          //~v51wI~
//===============================================================================//~v55uI~
//open by application                                              //~v55uI~
//===============================================================================//~v55uI~
int CWxemain::onfileopenwith(void)                                 //~v55uI~
{                                                                  //~v55uI~
    int rc;                                                        //~v55uI~
//************************************                             //~v55uI~
    rc=wxe_onfileopenwith();                                       //~v55uI~
    if (!rc)                                                       //~v55uI~
	    Mpview->Invalidate(FALSE);                                 //~v55uR~
    return rc;                                                     //~v55uI~
}//onfileopenwith                                                  //~v55uI~
