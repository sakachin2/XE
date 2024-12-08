//CID://+v9e2R~:       update#=   113                              //+v9e2R~
//***********************************************************
//* XPRINT : file print utility                                    //~v801R~
//***********************************************************
//v9e2:170809 compiler warning                                     //+v9e2I~
//v997:160309 v9.32 (LNX)compiler warning                          //~v997I~
//v996:160309 v9.32 (BUG)utfdd2u buffsize parm is not ctr but size //~v996I~
//v993:160308 v9.32 ucs4 support                                   //~v993I~
//v97t:131113 (BUG)record mode vhex print EOLDELM('|')             //~v97tI~
//v97p:131110 hexline monospace(vhex and hhex partially)           //~v97pI~
//v96k:130731 v9.25 Recordmode vhexdump by -mtx not by mx(hhex dump)//~v96kI~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//120629 v968 VC2010:LP64 support                                  //~v968R~
//111117 v964 (gcc4.6)Warning:unused-but-set                       //~v964I~
//100909 v955 v9.19 print EBC file by TextOutW for avoid print "?" for trans err to locale code//~v955I~
//100706 v950 v9.18 64bit compile                                  //~v950I~
//080215 v92u (BUG)v9.13 ABEND when hex dump not UTF8mode          //~v92uI~
//080109 v92s (UTF:BUG)crlf was inserted before "|" of h-hexdump   //~v92sI~
//080108 v92r (UTF:BUG)toolong line write when /mxu                //~v92rI~
//            under win long line was cut  and bug disppear but linux print "?"//~v92rI~
//080108 v92q (LNX)new version of utfcvf2u                         //~v92qI~
//071006 v92b text mode vhex dump support                          //~v92bI~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//971124 v830 :split xphex from xprint                             //~v830I~
//*************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add
//*************************************************************

#ifdef DOS                           //v3.6a                    //~v743I~
#else                                //v3.6a                    //~v743I~
                                                                //~v743I~
  #ifdef W32                                                       //~v826I~
  #else                                                            //~v826I~
  #endif                                                           //~v826I~
                                                                //~v743I~
#endif                               //v3.6a                    //~v743I~
                                                                //~v743I~
#include <ulib.h>	                                            //~v743M~
#include <ustring.h>                                               //~v768I~
#include <uerr.h>                                                  //~v801I~
#include <ufile.h>                                                 //~v807I~
#ifdef UTF8SUPP                                                    //~v928I~
#include <utf.h>                                                   //~v928I~
#endif                                                             //~v928I~
#include <utrace.h>                                                //~v955I~
#include <ucvebc.h>                                                //~v96eI~
#include <utf22.h>                                                 //~v993I~
                                                                //~v743I~
//*********************************************************************
#include  "xp.h"                                                //~v74kI~
#include  "xphex.h"                                                //~v827I~
#include  "xppf.h"                                                 //~v830I~
#include  "xputf.h"                                                //~v928I~
#include  "xpebc.h"                                                //~v955I~
//*********************************************************************//~v74lM~
extern long inputrange1;                                           //~v827I~
extern int lineprefixsw;		//line prefix output v7.12a        //~v827I~
extern int maxline;    //line   no per page v7.23r                 //~v827I~
//*                                                                //~v827I~
extern int printdumpfsw;				//printdump sub first sw v6.7a//~v827I~
extern int Linehexdpos;       //hex dec colomn in line   v6.7a     //~v827I~
extern int dumpwidth;       	//hexdump 1 line dump width	v6.7a  //~v827I~
extern int samechk;	      	//chk same as above      v6.7a         //~v827I~
extern int puthexfsw;					//puthexline sub first sw v6.7a//~v827I~
extern char linespwk[];             		//line hdr(line/offset) edit sprintf wk v6.7a//~v827I~
extern int Linecharpos;       //char dump colomn in line v6.7a     //~v827I~
extern int recordsz;       	//input record length      	v6.7a      //~v827I~
extern long inputrange1b;		//boundary alignment v7.21a	v7.25r //~v827I~
extern int line;                 //v2.1rep v6.7r                   //~v827I~
extern int lineskip;         //print line advancing count v3.5add  //~v827I~
extern FILE *output;       //handle v7.11r                         //~v827I~
extern int hexdump;                                                //~v96kI~
                                                                   //~v891I~
static  UCHAR dumpline[MAXLINEWIDTH];      //dump print line v6.7a //~v827I~
//static  UCHAR Hexline1[MAXLINEWIDTH];		//record hexdump hex first 4bit v6.7a//~v827I~//~v97pR~
        UCHAR Hexline1[MAXLINEWIDTH];		//record hexdump hex first 4bit v6.7a//~v97pI~
//static  UCHAR Hexline2[MAXLINEWIDTH];		//record hexdump hex last 4 bit v6.7a//~v827I~//~v97pR~
        UCHAR Hexline2[MAXLINEWIDTH];		//record hexdump hex last 4 bit v6.7a//~v97pI~
static  UCHAR Sameline[MAXLINEWIDTH];      //same as above line v6.7a//~v827I~
//static  UCHAR trt[16]="0123456789ABCDEF";/*hex cnv tbl*/           //~v92bI~//~v968R~
static  UCHAR trt[17]="0123456789ABCDEF";/*hex cnv tbl*///for C4295 warning no null string//~v968R~
#ifdef UTF8SUPP                                                    //~v928I~
//  static  USHORT Solducs[MAXLINEWIDTH];     //same chk dump data save//~v928R~//~v950R~
//  static  WUCS   Solducs[MAXLINEWIDTH];     //same chk dump data save//~v950I~//~v993R~
    static  UWUCS  Solducs[MAXLINEWIDTH];     //same chk dump data save//~v993I~
	static  UCHAR  oldintc[MAXLINEWIDTH];     //same chk dump data save//~v955I~
	static int Solducscnt=0;                                       //~v928R~
	static int Soldintclen=0;                                      //~v955I~
#endif                                                             //~v928I~
//********************************************************************//~v827I~
void puthexline(UCHAR* oldintc,UCHAR *oldchar,ULONG offset,int hexlen,int charlen);//v7.0r//~v827I~
void putsameline(ULONG offset,int sameno); //v7.0r                 //~v827I~
void datapxline(UCHAR *buff,int len);                              //~v827I~
void pxline(UCHAR *buff,int len);                                  //~v827I~
#ifdef UTF8SUPP                                                    //~v928I~
//  void datapxline_ucs(UCHAR *Pbuff,USHORT *Ppucs,int Pcount);    //~v928I~//~v950R~
    void datapxline_ucs(UCHAR *Pbuff,WUCS *Ppucs,int Pcount);      //~v950I~
	int xphexresetboundary(UCHAR *Pdata,int Poffs);                //~v928R~
#endif                                                             //~v928I~
//void datapxline_ucsebc(int Popt,UCHAR *Pbuff,WUCS *Ppucs,int Plen);//~v955I~//~v996R~
void datapxline_ucsebc(int Popt,UCHAR *Pbuff,WUCS *Ppucs,int Plen,int Pbuffsz);//~v996I~
//void pxline_ucsebc(int Popt,UCHAR *buff,WUCS *Pucs,int Plen);      //~v955R~//~v996R~
void pxline_ucsebc(int Popt,UCHAR *buff,WUCS *Pucs,int Plen,int Pbuffsz);//~v996I~
//********************************************************************
//********************************************************************
int setprintucsline(void)                                          //~v96kR~
{                                                                  //~v96kI~
	if (XPUTF8MODE())                                              //~v96kI~
    {                                                              //~v96kI~
    	Solducscnt=Gcolumnucs;		//ucs count                    //~v96kI~
//      memcpy(Solducs,Gbuffucs,(UINT)Gcolumnucs*WUCSSZ);          //~v96kI~//~v993R~
        memcpy(Solducs,Gbuffucs,(UINT)Gcolumnucs*UWUCSSZ);         //~v993I~
        UTRACED("setprintucsline",Gbuffucs,Gcolumnucs*UWUCSSZ);     //~v96kI~//~v993R~
    }                                                              //~v96kI~
    return 0;                                                      //~v96kI~
}                                                                  //~v96kI~
//********************************************************************//~v96kI~
void printdump(UCHAR *newintc,char *newchar,ULONG offset,int len,int charlen,int lastreadc)//v7.0r
{
static	int sameno;
static  int oldlen,oldcharlen;      //hexpart,char part len
//static  UCHAR oldintc[MAXLINEWIDTH];     //same chk dump data save//~v955R~
static  UCHAR oldchar[MAXLINEWIDTH];        //1 line data stack
static  ULONG Samestart;         //Same line start addr value
static  ULONG Samestartrecoffs;         //Same line start addr value//~v96kR~

  int    i; //,j;                /*work*/ v7.0r
  int    wlen;				//hex part len	
//int    comp;               /*same line compare sw*/ //v7.0d
//*********************
	if (printdumpfsw)				//printdump sub first sw
	{								//first time
		printdumpfsw=0;				//printdump sub first sw reset
		memset(dumpline,' ',sizeof(dumpline));
		memset(Hexline1,' ',sizeof(Hexline1));
		memset(Hexline2,' ',sizeof(Hexline2));
		i=Linehexdpos+dumpwidth;
    	Hexline1[Linehexdpos-1]=CHARDELM;
    	Hexline2[Linehexdpos-1]=CHARDELM;
    	Hexline1[i]=CHARDELM;
    	Hexline2[i]=CHARDELM;
		i++;
    	Hexline1[i]=CRLF;
    	Hexline2[i]=CRLF;
		memset(Sameline,' ',sizeof(Sameline));
		Samestart=0;	                            //first time sw
		Samestartrecoffs=0;	                            //first time sw//~v96kI~
		sameno=0;		                            //not saved line
	}
//******************************
    UTRACEP("printdump offset=%d,len=%d,charlen=%d,lastreadc=%d,samechk=%d\n",offset,len,charlen,lastreadc,samechk);//~v96kR~//~v97pR~
	wlen=len;
	if (lastreadc==EOF)
		wlen--;
	wlen=min(wlen,dumpwidth);	//hex length	
	if (!samechk)
	{
//  	recorddumpcopyoffs=reccolomn-wlen;                         //~v96kR~
    	recorddumpcopyoffs=Greccolomnold-wlen;//offset in the record of start of dump//~v96kI~
//            if (XPUTF8MODE())                                    //~v96kR~
//            {                                                    //~v96kR~
//                Solducscnt=Gcolumnucs;      //ucs count          //~v96kR~
////              memcpy(Solducs,Gbuffucs,(UINT)Gcolumnucs*sizeof(USHORT));//~v96kR~
//                memcpy(Solducs,Gbuffucs,(UINT)Gcolumnucs*WUCSSZ);//~v96kR~
//            }                                                    //~v96kR~
		setprintucsline();	//set to Solducs                       //~v96kI~
		puthexline(newintc,newchar,offset,wlen,charlen);
	}
	else
	{
		if  (wlen==dumpwidth		//buff full
        &&   Soldintclen==dumpwidth                                //~v96kI~
		&&  sameno				//not first line
   		&&  !memcmp(oldintc,newintc,(UINT)dumpwidth)) //v7.0r
			sameno++;
		else	//buff to be flushed
		{
			if (sameno)	//not first line full
			{
				puthexline(oldintc,oldchar,Samestart,oldlen,oldcharlen);
    	  	   	if (sameno>1) // multiple line same 
                {                                                  //~v96kI~
          		  if (recordsz || vfmt) //recfm=R/V                //~v96kI~
					putsameline(Samestartrecoffs,sameno);          //~v96kI~
                  else                                             //~v96kI~
					putsameline(Samestart,sameno);
                }                                                  //~v96kI~
			}//not first

//  		recorddumpcopyoffs=reccolomn-wlen;                     //~v96kR~
    		recorddumpcopyoffs=Greccolomnold-wlen;//offset in the record of start of dump//~v96kI~
			memcpy(oldintc,newintc,(UINT)wlen); //v7.0r
    	  	memcpy(oldchar,newchar,(UINT)charlen); //v7.0r
            UTRACED("printdump new oldintc",oldintc,wlen);         //~v955R~
            UTRACED("printdump new oldchar",oldchar,charlen);      //~v955R~
            Soldintclen=wlen;                                      //~v955I~
#ifdef UTF8SUPP                                                    //~v928I~
//            if (XPUTF8MODE())                                      //~v928I~//~v96kR~
//            {                                                      //~v928I~//~v96kR~
//                Solducscnt=Gcolumnucs;      //ucs count            //~v928I~//~v96kR~
////              memcpy(Solducs,Gbuffucs,(UINT)Gcolumnucs*sizeof(USHORT));//~v928I~//~v950R~//~v96kR~
//                memcpy(Solducs,Gbuffucs,(UINT)Gcolumnucs*WUCSSZ);  //~v950I~//~v96kR~
//            }                                                      //~v928I~//~v96kR~
		    setprintucsline();	//set to Solducs                   //~v96kI~
#endif                                                             //~v928I~
			oldlen=wlen;
			oldcharlen=charlen;
          	if (recordsz || vfmt) //recfm=R/V                      //~v96kR~
//				Samestartrecoffs=reccolomn;                        //~v96kR~//~v997R~
  				Samestartrecoffs=(ULONG)reccolomn;                 //~v997I~
			Samestart=offset;
			sameno=1;			//line saved no
			if (lastreadc==EOF)
				if (wlen)
					puthexline(oldintc,oldchar,Samestart,wlen,charlen);
		}//not same line
	}//same chk

    return;
}//end of printdump

//********************************************************************
//* hex line edit and print		v6.7a
//*   input:
//*     p1 : original data buff
//*     p2 : char data buff
//*     p3 : hex data len
//*     p4 : char data len
//*   output:
//*     print output
//********************************************************************
//void puthexline(UCHAR* oldintc,UCHAR *oldchar,ULONG offset,int hexlen,int charlen)//v7.0r//+v9e2R~
void puthexline(UCHAR* Poldintc,UCHAR *oldchar,ULONG offset,int hexlen,int charlen)//v7.0r//+v9e2I~
{
//static  UCHAR trt[16]="0123456789ABCDEF";/*hex cnv tbl*/         //~v92bR~
static  ULONG oldline;
	    UCHAR *pchexd;       /*line ptr*/
	    UCHAR *pcintc;       /*line ptr*/
		int i;
		int lowboundary;	//v7.25a
		int wlen;
#ifdef UTF8SUPP                                                    //~v928I~
//      USHORT *pucs;                                              //~v928I~//~v950R~
//      WUCS   *pucs;                                              //~v950I~//~v993R~
        UWUCS  *pucs;                                              //~v993I~
        int ii;                                                    //~v928I~
#endif                                                             //~v928I~
	int swfillspace;                                               //~v96eI~
//******************
    UTRACEP("puthexline offset=%x hexlen=%d,charlen=%d\n",offset,hexlen,charlen);//~v96kI~
	if (puthexfsw)				//printdump sub first sw
	{
		puthexfsw=0;	
		oldline=(ULONG)(-1);
	}

	if (offset==oldline)
    	memset(dumpline,' ',LINENOSZ);
	else
	{
		sprintf(dumpline,linespwk,offset);
		oldline=offset;
	}
	*(dumpline+LINENOSZ)=ADDRDELM;
	if (!memcmp(dumpline,"00",2))
    	memset(dumpline,' ',2);
	wlen=charlen;

	memcpy(dumpline+Linecharpos,oldchar,(UINT)wlen); //v7.0a
    if (vhexdump>1)                                           //~v96eR~//~v96kR~
		wlen+=Linecharpos;                                         //~v96eI~
    else                                                           //~v96eI~
	if (wlen==dumpwidth+2)	//last dbcs
		wlen+=Linecharpos;
	else
	{	
		swfillspace=1;                                             //~v96eI~
		if (wlen<=dumpwidth)	//last dbcs
#ifdef UTF8SUPP                                                    //~v928I~
        {                                                          //~v928I~
          if (XPUTF8MODE())                                        //~v928I~
            for (Solducscnt--,pucs=Solducs+Solducscnt,ii=dumpwidth-wlen+1;ii>0;ii--,Solducscnt++)//~v928R~
                *pucs++=' ';                                       //~v928R~
          else                                                     //~v928I~
#endif                                                             //~v928I~
          if (swsw4 & SW4EBCCFG)                                   //~v96eR~
			swfillspace=0;                                         //~v96eR~
          else                                                     //~v96eI~
			memset(dumpline+Linecharpos+wlen-1,' ',(UINT)(dumpwidth-wlen+1));//v7.0r
#ifdef UTF8SUPP                                                    //~v928I~
        }                                                          //~v928I~
        else                                                       //~v92sI~
        	Solducscnt--;       //drop last crlf                   //~v92sI~
#endif                                                             //~v928I~
      if (!swfillspace)                                            //~v96eR~
      {                                                            //~v96eI~
		wlen+=Linecharpos;                                         //~v96eI~
        if (*(dumpline+wlen-1)==CRLF)                               //~v96eI~//~v96kR~
        	wlen--;                                                //~v96eI~
      }                                                            //~v96eI~
      else                                                         //~v96eI~
		wlen=Linecharpos+dumpwidth;
		*(dumpline+wlen++)=CHARDELM;
		XPsetCa_(Solducs,Solducscnt,CHARDELM)                      //~v928R~
		*(dumpline+wlen++)=CRLF;
		XPsetCa_(Solducs,Solducscnt,CRLF)                          //~v928R~
	}

//  if (recordsz)                                                  //~v96kR~
    if (vhexdump==2)    //record mode vhex dump                    //~v96kI~
	{
//*recordmode vhex                                                 //~v97tI~
//  	pcintc=oldintc;	                                           //+v9e2R~
    	pcintc=Poldintc;                                           //+v9e2I~
		XPsetucsON_()	//parm to datapline:utf strlen             //~v928R~
		datapxline(dumpline,wlen);//v7.12r
		XPsetucsOFF_()	//parm to datapline:utf strlen             //~v928R~
#ifdef AAA                                                         //~v97tR~
		for (i=0,wlen=Linehexdpos;i<dumpwidth;i++,wlen++)        /* 1 line setup*/
		{
	        if (i>=hexlen)
	        {
				Hexline1[wlen]=' ';
				Hexline2[wlen]=' ';
        	}
	        else                             /*net area*/
    	    {
    	      Hexline1[wlen]=*(trt+(pcintc[i]>>4));     /*first 4 bit*/
          	  Hexline2[wlen]=*(trt+(pcintc[i] & 0x0F));	/*last 4*/
	        }
		}                                  /*dumpwidth loop*/
        wlen+=2;
#else                                                              //~v97tI~
		for (i=0,wlen=Linehexdpos;i<hexlen;i++,wlen++)        /* 1 line setup*///~v97tI~
		{                                                          //~v97tI~
    	      Hexline1[wlen]=*(trt+(pcintc[i]>>4));     /*first 4 bit*///~v97tI~
          	  Hexline2[wlen]=*(trt+(pcintc[i] & 0x0F));	/*last 4*/ //~v97tI~
		}                                                          //~v97tI~
	  	Hexline1[wlen]=CRLF;  // \n                                //~v97tI~
	    Hexline2[wlen]=CRLF;                                       //~v97tI~
        wlen++;                                                    //~v97tI~
#endif                                                             //~v97tI~
		datapxline(Hexline1,wlen);//v7.12r
		datapxline(Hexline2,wlen);//v7.12r

	}
	else
    if (vhexdump==3)                                               //~v96kI~
	{                                                              //~v96eI~
//*vmt vhex                                                        //~v97tI~
//  	pcintc=oldintc;                                            //~v96eI~//+v9e2R~
    	pcintc=Poldintc;                                           //+v9e2I~
		XPsetucsON_()	//parm to datapline:utf strlen             //~v96eI~
		datapxline(dumpline,wlen);//v7.12r                         //~v96eI~
		XPsetucsOFF_()	//parm to datapline:utf strlen             //~v96eI~
		for (i=0,wlen=Linehexdpos;i<hexlen;i++,wlen++)        /* 1 line setup*///~v96eR~
		{                                                          //~v96eI~
    		Hexline1[wlen]=*(trt+(pcintc[i]>>4));     /*first 4 bit*///~v96eI~
          	Hexline2[wlen]=*(trt+(pcintc[i] & 0x0F));	/*last 4*/ //~v96eI~
		}                                  /*dumpwidth loop*/      //~v96eI~
	  	Hexline1[wlen]=CRLF;  // \n                                //~v96eR~
	    Hexline2[wlen]=CRLF;                                       //~v96eR~
        wlen++;                                                    //~v96eI~
		datapxline(Hexline1,wlen);//v7.12r                         //~v96eI~
		datapxline(Hexline2,wlen);//v7.12r                         //~v96eI~
	}                                                              //~v96eI~
	else                                                           //~v96eI~
	{
#ifdef UTF8SUPP                                                    //~v928I~
	  if (XPUTF8MODE())                                            //~v92uI~
      {                                                            //~v92uI~
//      memmove(Solducs+Linecharpos,Solducs+LINENOSZ+1,(Solducscnt-LINENOSZ-1)*sizeof(USHORT));  //shift to char pos//~v928R~//~v950R~
//      memmove(Solducs+Linecharpos,Solducs+LINENOSZ+1,(Solducscnt-LINENOSZ-1)*WUCSSZ);  //shift to char pos//~v950I~//~v993R~
//      memmove(Solducs+Linecharpos,Solducs+LINENOSZ+1,(Solducscnt-LINENOSZ-1)*UWUCSSZ);  //shift to char pos//~v993I~//~v997R~
        memmove(Solducs+Linecharpos,Solducs+LINENOSZ+1,(size_t)((Solducscnt-LINENOSZ-1)*UWUCSSZ));  //shift to char pos//~v997I~
        Solducscnt=Linecharpos+(Solducscnt-LINENOSZ-1);  //shift to char pos//~v928I~
      }                                                            //~v92uI~
#endif                                                             //~v928I~
//* clear start boundary line v7.25a start
		if (offset==(ULONG)inputrange1b)		//start baoundary  //~v826R~
		{
			lowboundary=(int)(inputrange1-inputrange1b);//skip len
			if (lowboundary)	//v7.25a
#ifdef UTF8SUPP                                                    //~v928I~
            {                                                      //~v928I~
              if (XPUTF8MODE())                                    //~v928I~
//              xphexresetboundary(oldintc,lowboundary);           //~v928R~//+v9e2R~
                xphexresetboundary(Poldintc,lowboundary);          //+v9e2I~
          	  else                                                 //~v928I~
#endif                                                             //~v928I~
				memset(dumpline+Linecharpos,' ',(UINT)lowboundary);
#ifdef UTF8SUPP                                                    //~v928I~
            }                                                      //~v928I~
#endif                                                             //~v928I~
		}
		else
			lowboundary=0;
//* clear start boundary line v7.25a end
		*(dumpline+Linecharpos-1)=CHARDELM;

		if (dumpwidth==16)	
			for (i=0,pchexd=dumpline+Linehexdpos;i<dumpwidth;i++)           /* 1 line setup*/
			{
	    	    if (i>=hexlen
				||  i<lowboundary) //for boundary v7.25a
	        	{
    		  		if (i==8)                                      //~v781I~
    					*(pchexd-1)=' ';	                       //~v781I~
			  		*pchexd++=' ';
					*pchexd++=' ';
//  		  		*(dumpline+Linecharpos+i)=' ';  //don't rest CHARDELM and CRLF//~v96kR~
//  		  		if (i==8)                                      //~v781R~
//  					*pchexd=' ';	                           //~v781R~
        		}
	        	else                             /*net area*/
    	    	{
//  	      		*pchexd++=*(trt+(oldintc[i]>>4));     /*first 4 bit*///+v9e2R~
    	      		*pchexd++=*(trt+(Poldintc[i]>>4));     /*first 4 bit*///+v9e2I~
//        	  		*pchexd++=*(trt+(oldintc[i] & 0x0F));	/*last 4*///+v9e2R~
          	  		*pchexd++=*(trt+(Poldintc[i] & 0x0F));	/*last 4*///+v9e2I~
//  		  		if (i==8)                                      //~v781R~
    		  		if (i==7)                                      //~v781I~
    					*pchexd='-';	                           //~v781R~
	        	}
				pchexd++;
			}                                  /*dumpwidth loop*/
		else//32byte mode
			for (i=0,pchexd=dumpline+Linehexdpos-2;i<dumpwidth;i++)           /* 1 line setup*/
			{
	        	if (!(i & 0x03))
				{
					pchexd++;  /*' ' each 4 byte*/
	    	    	if (!(i & 0x0F))
						pchexd++;  /*' ' each 16 byte*/
				}
	    	    if (i>=hexlen
				||  i<lowboundary) //for boundary v7.25a
	        	{
			  		*pchexd++=' ';
					*pchexd++=' ';
//  		  		*(dumpline+Linecharpos+i)=' ';                 //~v96kR~
        		}
	        	else                             /*net area*/
    	    	{
//  	      		*pchexd++=*(trt+(oldintc[i]>>4));     /*first 4 bit*///+v9e2R~
    	      		*pchexd++=*(trt+(Poldintc[i]>>4));     /*first 4 bit*///+v9e2I~
//        	  		*pchexd++=*(trt+(oldintc[i] & 0x0F));	/*last 4*///+v9e2R~
          	  		*pchexd++=*(trt+(Poldintc[i] & 0x0F));	/*last 4*///+v9e2I~
	        	}
			}                                  /*dumpwidth loop*/
        UTRACED("puthexline hhex",dumpline,wlen);                  //~v97pR~
		XPsetucsON_()	//parm to datapline:utf strlen             //~v928I~
        Gxpotheropt|=GOO_HHEXLINE;	                               //~v97pI~
		datapxline(dumpline,wlen); //v7.12r
        Gxpotheropt&=~GOO_HHEXLINE;                                //~v97pI~
		XPsetucsOFF_()	//parm to datapline:utf strlen             //~v928I~
	}
}//puthexline

//********************************************************************//~v92bI~
//* same as above print 		v6.7a                              //~v92bI~
//*   input:                                                       //~v92bI~
//*     p1 : same start offset/readline                            //~v92bI~
//*     p2 : same lineno/readline                                  //~v92bI~
//*   output:                                                      //~v92bI~
//*     print output                                               //~v92bI~
//********************************************************************//~v92bI~
void printdump3(UCHAR *Pdumpbuff,int Plen)                         //~v92bI~
{                                                                  //~v92bI~
	int i,wlen;                                                    //~v92bI~
    UCHAR *pc;                                                     //~v92bI~
//****************                                                 //~v92bI~
    UTRACED("printdump3",Pdumpbuff,Plen);                          //~v96kI~//~v97pR~
	wlen=LINENOSZ;                                                 //~v92bI~
	memset(Hexline1,' ',(UINT)wlen);                               //~v92uR~
	memset(Hexline2,' ',(UINT)wlen);                               //~v92uR~
    Hexline1[wlen]=CHARDELM;                                       //~v92bI~
    Hexline2[wlen]=CHARDELM;                                       //~v92bI~
    wlen++;                                                        //~v92bI~
	for (i=0,pc=Pdumpbuff;i<Plen;i++,wlen++,pc++)                  //~v92bI~
	{                                                              //~v92bI~
    	Hexline1[wlen]=*(trt+(*pc>>4));     /*first 4 bit*/        //~v92bI~
        Hexline2[wlen]=*(trt+(*pc & 0x0F));	/*last 4*/             //~v92bI~
	}                                                              //~v92bI~
    Hexline1[wlen]=CRLF;                                           //~v92bI~
    Hexline2[wlen]=CRLF;                                           //~v92bI~
    wlen++;                                                        //~v92bI~
	datapxline(Hexline1,wlen);                                     //~v92bI~
	datapxline(Hexline2,wlen);                                     //~v92bI~
    return;                                                        //~v92bI~
}//printdump3(UCHAR *Pdumpbuff,int Plen)                           //~v92bI~
//********************************************************************
//* same as above print 		v6.7a
//*   input:
//*     p1 : same start offset/readline
//*     p2 : same lineno/readline
//*   output:
//*     print output
//********************************************************************
void putsameline(ULONG offset,int sameno) //v7.0r
{
	int wlen;
//****************
//  if (recordsz)                                                  //~v96kR~
    if (recordsz||vfmt)                                            //~v96kI~
	{
		if (sameno==2)
			wlen=sprintf(Sameline+Linehexdpos,
//  					"LINE %6ld           is same as above\n",  //~v96kR~
//  					offset+1)+Linehexdpos;                     //~v96kR~
    					"OFFS %6lX           is same as above\n",  //~v96kR~
    					offset)+Linehexdpos;                       //~v96kR~
		else
			wlen=sprintf(Sameline+Linehexdpos,
//  					"LINE %6ld to %6ld is same as above\n",    //~v96kR~
//  					offset+1,                                  //~v96kR~
//  					offset+sameno-1)+Linehexdpos;              //~v96kR~
    					"OFFS %6lX to %6lX is same as above\n",    //~v96kI~
    					offset,                                    //~v96kI~
//  					offset+dumpwidth*(sameno-1)-1)+Linehexdpos;//~v96kR~//~v997R~
    					offset+(ULONG)(dumpwidth*(sameno-1))-1)+Linehexdpos;//~v997I~
//  	pxline("\n",1);                                            //~v96kR~
		datapxline(Sameline,wlen);//v7.12r
//  	pxline("\n",1);                                            //~v96kR~
	}
	else
	{
		if (sameno==2)
			wlen=sprintf(Sameline+Linehexdpos,
						"OFFS %06lX           is same as above\n",
//  					offset+dumpwidth)                          //~v997R~
    					offset+(ULONG)dumpwidth)                   //~v997I~
				+Linehexdpos;
		else
			wlen=sprintf(Sameline+Linehexdpos,
						"OFFS %06lX to %06lX is same as above\n",
//  					offset+dumpwidth,                          //~v997R~
    					offset+(ULONG)dumpwidth,                   //~v997I~
//  					offset+dumpwidth*sameno-1)                 //~v997R~
    					offset+(ULONG)(dumpwidth*sameno)-1)        //~v997I~
				+Linehexdpos;
		datapxline(Sameline,wlen);//v7.12r
	}
}//putsameline

#ifdef W32                                                         //~v993I~
//**********************************************************************//~v993I~
//* translate ucs4 to utf16 before call datapline_ucs              //~v993I~
//**********************************************************************//~v993I~
void datapxline_ucs4(UCHAR *Pbuff,UWUCS *Ppucs4,int Pcount)        //~v993I~
{                                                                  //~v993I~
    int ucs2ctr;                                                   //~v993I~
//*****************                                                //~v993I~
	utfucs42utf16(0,Ppucs4,Pcount,Gbuffucs2,(int)sizeof(Gbuffucs2),&ucs2ctr);//~v993I~
	datapxline_ucs(Pbuff,Gbuffucs2,ucs2ctr);                       //~v993I~
    return;                                                        //~v993I~
}//datapxline_ucs4                                                 //~v993I~
#endif	//W32                                                      //~v993I~
//**********************************************************************
//* 1 hex data line print v7.12a
//**********************************************************************
void datapxline(UCHAR *buff,int len)
{
	UTRACED("datapxline",buff,len);                                //~v96kI~
#ifdef UTF8SUPP                                                    //~v928I~
    if (Gxputfstat & GXPUS_UCSLINE)                                //~v928R~
    {                                                              //~v928I~
#ifdef W32                                                         //~v993I~
		datapxline_ucs4(buff,Solducs,Solducscnt);                  //~v993I~
#else                                                              //~v993I~
		datapxline_ucs(buff,Solducs,Solducscnt);                   //~v928R~
#endif                                                             //~v993I~
        return;                                                    //~v928I~
    }                                                              //~v928I~
    if (Gxputfstat & GXPUS_UCSLINE_EBC)                            //~v955R~
    {                                                              //~v955I~
#ifdef W32                                                         //~v993I~
//		datapxline_ucsebc(0,buff,Gbuffucs2,len);                   //~v993I~//~v996R~
  		datapxline_ucsebc(0,buff,Gbuffucs2,len,(int)sizeof(Gbuffucs2));//~v996I~
#else                                                              //~v993I~
//  	datapxline_ucsebc(0,buff,Gbuffucs,len);                    //~v955R~//~v996R~
    	datapxline_ucsebc(0,buff,Gbuffucs,len,(int)sizeof(Gbuffucs));//~v996I~
#endif                                                             //~v993I~
        return;                                                    //~v955I~
    }                                                              //~v955I~
#endif                                                             //~v928I~
	if (lineprefixsw)
		pxline(buff,len);
	else
		pxline(buff+LINENOSZ+1,len-LINENOSZ-1);
}
#ifdef UTF8SUPP                                                    //~v928I~
//**********************************************************************//~v928I~
//* 1 data line print v7.12a                                       //~v928I~
//* count:column                                                   //~v928I~
//**********************************************************************//~v928I~
//void datapxline_ucs(UCHAR *Pbuff,USHORT *Ppucs,int Pcount)         //~v928I~//~v950R~
void datapxline_ucs(UCHAR *Pbuff,WUCS *Ppucs,int Pcount)           //~v950I~
{                                                                  //~v928I~
    int ii,endpos;                                                 //~v928R~
//  USHORT *pucs;                                                  //~v928I~//~v950R~
    WUCS *pucs;                                                    //~v950I~
    UCHAR *pc;                                                     //~v928I~
//**********************                                           //~v928I~
	UTRACED("datapxline_ucs",Ppucs,Pcount*WUCSSZ);                 //~v97pI~
//  if (!recordsz)	//horizontal hex                               //~v928R~//~v96eR~
    if (hexdump)	//horizontal hex           //~v96eR~           //~v96kR~
    	endpos=Linecharpos;	//set hexpart                          //~v928I~
    else                                                           //~v928I~
	    if (lineprefixsw)                                          //~v928I~
	    	endpos=LINENOSZ+1; //set prefix                        //~v928I~
        else                                                       //~v928I~
        	endpos=0;                                              //~v928I~
    if (endpos)                                                    //~v928I~
        for (pucs=Ppucs,pc=Pbuff,ii=0;ii<endpos;ii++)              //~v928R~
//          *pucs++=(USHORT)(*pc++);                               //~v928I~//~v950R~
            *pucs++=(WUCS)(*pc++);                                 //~v950I~
    UTRACED("datapxline_ucs",Ppucs,Pcount*2);                      //~v96kI~
    if (lineprefixsw)                                              //~v928I~
//      pxline((UCHAR*)(ULONG)Ppucs,Pcount);                       //~v928R~//~v968R~
        pxline((UCHAR*)(ULPTR)Ppucs,Pcount);                       //~v968R~
    else                                                           //~v928I~
//      pxline((UCHAR*)(ULONG)(Ppucs+LINENOSZ+1),Pcount-LINENOSZ-1);//~v928R~//~v968R~
        pxline((UCHAR*)(ULPTR)(Ppucs+LINENOSZ+1),Pcount-LINENOSZ-1);//~v968R~
    return;                                                        //~v928I~
}//datapxline_ucs                                                   //~v928I~//~v955R~
//**********************************************************************//~v955I~
//* ebc char line                                                  //~v955I~
//**********************************************************************//~v955I~
//void datapxline_ucsebc(int Popt,UCHAR *Pbuff,WUCS *Ppucs,int Plen) //~v955I~//~v996R~
void datapxline_ucsebc(int Popt,UCHAR *Pbuff,WUCS *Ppucs,int Plen,int Pbuffsz)//~v996I~
{                                                                  //~v955I~
    int ii,endpos;                                                 //~v955I~
    WUCS *pucs;                                                    //~v955I~
    UCHAR *pc;                                                     //~v955I~
//**********************                                           //~v955I~
	UTRACED("datapxline_ucsebc",Ppucs,Plen*WUCSSZ);                //~v97pI~
//  if (!recordsz)	//horizontal hex                               //~v955I~//~v96eR~
    if (hexdump)	//horizontal hex           //~v96eR~           //~v96kR~
    	endpos=Linecharpos;	//set hexpart                          //~v955I~
    else                                                           //~v955I~
	    if (lineprefixsw)                                          //~v955I~
	    	endpos=LINENOSZ+1; //set prefix                        //~v955I~
        else                                                       //~v955I~
        	endpos=0;                                              //~v955I~
	UTRACEP("datapxline_ucsebc len=%d,endpos=%d\n",Plen,endpos);   //~v955I~
    if (endpos)                                                    //~v955I~
        for (pucs=Ppucs,pc=Pbuff,ii=0;ii<endpos;ii++)              //~v955I~
            *pucs++=(WUCS)(*pc++);                                 //~v955I~
//  pxline_ucsebc(0,Pbuff,Ppucs,Plen);                             //~v955R~//~v996R~
    pxline_ucsebc(0,Pbuff,Ppucs,Plen,Pbuffsz);                     //~v996I~
    return;                                                        //~v955I~
}//datapxline_ucsebc                                                  //~v955I~//~v96kR~//~v97pR~
#endif                                                             //~v928I~
//********************************************************************
//* hexdump line print v6.7a
//*   input:
//*     p1 : line buff addr
//*     p2 : buff len
//*   output:
//*     print output
//********************************************************************
void pxline(UCHAR *buff,int len)
{
	int i,wlen;
#ifdef UTF8SUPP                                                    //~v928I~
  	int ucssw;                                                     //~v928I~
#endif                                                             //~v928I~
//****************
	UTRACED("pxline",buff,len);                                    //~v97pI~
#ifdef UTF8SUPP                                                    //~v928I~
  	ucssw=(Gxputfstat & GXPUS_UCSLINE);	//save over printhdr       //~v928I~
#endif                                                             //~v928I~
	wlen=len;
	if (line==maxline)           //page overflow 
		printhdr();

	line++;
	for (i=0;i<lineskip;i++)
#ifdef UTF8SUPP                                                    //~v928I~
	{                                                              //~v928I~
#endif                                                             //~v928I~
  		buff[wlen++]='\n';
  		XPsetAC_(Solducs,Solducscnt,'\n')                          //~v928R~
#ifdef UTF8SUPP                                                    //~v928I~
	}                                                              //~v928I~
#endif                                                             //~v928I~
#ifdef UTF8SUPP                                                    //~v928I~
  	Gxputfstat|=ucssw;	//recover                                  //~v928I~
  if (Gxputfstat & GXPUS_UCSLINE)                                  //~v928R~
//  pline(buff,4,wlen,output);                                     //~v92rR~
//  pline(buff,sizeof(USHORT),wlen,output);                        //~v92qI~//~v950R~
    pline(buff,WUCSSZ,wlen,output);                                //~v950I~
  else                                                             //~v928I~
#endif                                                             //~v928I~
	pline(buff,sizeof(char),wlen,output);
}//pxline
//********************************************************************//~v955I~
//char line print for ebc                                          //~v955I~
//********************************************************************//~v955I~
//void pxline_ucsebc(int Popt,UCHAR *Pbuff,WUCS *Pucs,int Plen)      //~v955R~//~v996R~
void pxline_ucsebc(int Popt,UCHAR *Pbuff,WUCS *Pucs,int Plen,int Pbuffsz)//~v996I~
{                                                                  //~v955I~
	int ii,wlen,ucsctr,swucsebc,endpos;                            //~v955R~
    UCHAR *pmb;                                                    //~v955I~
    WUCS *pucs;                                                    //~v955I~
//****************                                                 //~v955I~
	UTRACED("pxline_ucsebc buff",Pbuff,Plen);                      //~v96kR~
	UTRACED("pxline_ucsebc ucs",Pucs,Plen*(int)sizeof(WUCS));           //~v96kI~//~v997R~
	wlen=Plen;                                                     //~v955I~
  	swucsebc=(Gxputfstat & GXPUS_UCSLINE_EBC);	//save over printhdr//~v955M~
	if (line==maxline)           //page overflow                   //~v955I~
		printhdr();                                                //~v955I~
  	Gxputfstat|=swucsebc;	//recover ucsline ebc                  //~v955M~
                                                                   //~v955I~
	line++;                                                        //~v955I~
	for (ii=0;ii<lineskip;ii++)                                    //~v955R~
  		Pbuff[wlen++]='\n';                                        //~v955R~
//  if (!recordsz)	//horizontal hex                               //~v955I~//~v96eR~
    if (hexdump)	//horizontal hex           //~v96eR~           //~v96kR~
    {                                                              //~v955I~
    	endpos=Linecharpos;	//set hexpart                          //~v955I~
    	pmb=Pbuff+endpos;                                          //~v955I~
    	pucs=Pucs+endpos;                                          //~v955I~
        wlen=Plen-endpos;                                          //~v955I~
                                                                   //~v955I~
	}                                                              //~v955I~
    else                                                           //~v955I~
    if (lineprefixsw)                                              //~v955I~
    {                                                              //~v955I~
    	pmb=Pbuff+LINENOSZ+1;                                      //~v955I~
    	pucs=Pucs+LINENOSZ+1;                                      //~v955R~
        wlen=Plen-LINENOSZ-1;                                      //~v955I~
    }                                                              //~v955I~
    else                                                           //~v955I~
    {                                                              //~v955I~
    	pmb=Pbuff+LINENOSZ+1;                                      //~v955R~
        wlen=Plen-LINENOSZ-1;                                      //~v955I~
    	pucs=Pucs;                                                 //~v955R~
    }                                                              //~v955I~
    if (samechk)                                                   //~v955I~
//  	xpebc_setucslinesamechk(0,pmb,wlen,oldintc,Soldintclen,pucs,&ucsctr);//~v955R~//~v996R~
    	xpebc_setucslinesamechk(0,pmb,wlen,oldintc,Soldintclen,pucs,&ucsctr,Pbuffsz-PTRDIFF(pucs,Pucs));//~v996R~
    else                                                           //~v955I~
//  	xpebc_setucsline(XPEBCSULO_HEX,pmb,pucs,wlen,&ucsctr);     //~v955R~//~v996R~
    	xpebc_setucsline(XPEBCSULO_HEX,pmb,pucs,wlen,&ucsctr,Pbuffsz-PTRDIFF(pucs,Pucs));//~v996R~
#ifdef W32                                                         //~v993I~
	pucs=Gbuffucs2;                                                //~v993I~
#else                                                              //~v993I~
	pucs=Gbuffucs;                                                 //~v955I~
#endif                                                             //~v993I~
//  if (!recordsz)	//horizontal hex                               //~v955I~//~v96eR~
    if (hexdump)	//horizontal hex                               //~v96kR~
    {                                                              //~v955I~
    	ucsctr+=Linecharpos;	//set hexpart                      //~v955I~
    	if (!lineprefixsw)                                         //~v955I~
        {                                                          //~v955I~
        	pucs+=LINENOSZ+1;                                      //~v955I~
    		ucsctr-=LINENOSZ+1;                                    //~v955I~
        }                                                          //~v955I~
    }                                                              //~v955I~
    else                                                           //~v955I~
    if (lineprefixsw)                                              //~v955I~
    	ucsctr+=LINENOSZ+1;                                        //~v955I~
                                                                   //~v955I~
    UTRACED("pxline_ucsebc",Gbuffucs,ucsctr*WUCSSZ);               //~v955I~
	pline(pucs,WUCSSZ,ucsctr,output);                              //~v955R~
}//pxline_ucsebc                                                   //~v955I~
#ifdef UTF8SUPP                                                    //~v928I~
//********************************************************************//~v928I~
//* hexdump char part ucs re-evaluate by range parameter cut       //~v928I~
//********************************************************************//~v928I~
int xphexresetboundary(UCHAR *Pdata,int Poffs)                     //~v928R~
{                                                                  //~v928I~
//  USHORT newucs[MAXLINEWIDTH],*pucs;                             //~v928I~//~v950R~
//  WUCS   newucs[MAXLINEWIDTH],*pucs;                             //~v950I~//~v993R~
    UWUCS  newucs[MAXLINEWIDTH],*pucs;                             //~v993I~
    int newucscnt,width,/*opt,*/ii;                                    //~v928R~//~v964R~
//****************                                                 //~v928I~
//	opt=0;		//windows TextOutW support USHORT wide char only   //~v928I~//~v964R~
//  utfcvf2u(0,newucs,Pdata+Poffs,0,dumpwidth-Poffs,&newucscnt,&width);//~v92qR~
    utfcvf2u(0,newucs,Pdata+Poffs,0/*pchof*/,0/*dbcs*/,0/*initoffs*/,dumpwidth-Poffs,0/*out readlen*/,&newucscnt,&width);//~v92qI~
    for (pucs=Solducs+Linecharpos,ii=Poffs;ii>0;ii--)              //~v928I~
    	*pucs++=' ';                                               //~v928I~
    for (ii=0;ii<newucscnt;ii++)                                   //~v928I~
    	*pucs++=newucs[ii];                                        //~v928I~
    for (ii=dumpwidth-width-Poffs;ii>0;ii--)                       //~v928I~
    	*pucs++=' ';                                               //~v928I~
    Solducscnt=Linecharpos+dumpwidth-(width-newucscnt);            //~v928R~
	XPsetCa_(Solducs,Solducscnt,CHARDELM)                          //~v928I~
	XPsetCa_(Solducs,Solducscnt,CRLF)                              //~v928I~
    return 0;                                                      //~v928R~
}//xphexresetboundary                                              //~v928I~
#endif                                                             //~v928I~
