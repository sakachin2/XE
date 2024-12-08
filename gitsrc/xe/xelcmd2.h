//CID://+vb88R~:                             update#=    5;        //+vb88R~
//****************************************************************
//*xelcmd2.h
//****************************************************************
//vb88:170216 stop lcmd "i" continue mode by cut&paste             //+vb88I~
//vb86:170216 display cmdline ctr excluded(fcmd:x,xx; lcmd x)      //~vb86I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v9@8:080717 3270:fs mode del excluded line                       //~v9@8I~
//v78S:080606 continuede insert line mode by lcmd "i"              //~v54XI~
//v54X:040201 del nx all performance tuning                        //~v54XI~
//v54G:040121 (BUG)abend when curtop xline is deleted              //~v54GI~
//v54B:040120 exclude logic performance up for "(i)x all" cmd      //~v54BI~
//v498:020617 XX cmd support .a .b                                 //~v498I~
//v41k:010820 add XR command(reverse excluded line)                //~v41kI~
//v40X:010722 cannot set 72-80 by v40W because lrecl=72;use lcmdisrtwithlen//~v40XI~
//v40p:010603 add x *= (exclude same as above line)                //~v40pI~
//v11u:990813 hidden line reset by reset x cmd                     //~v11uI~
//v0ib:980530 v0i9 cotinued for other than file copy               //~v0ibI~
//v0i0:980429 lcmd skip/bandle support(DEL)                        //~v0i0I~
//v0hz:980412 EXCLUDE/IEXCLUDE cmd support                         //~v0hzI~
//v057:951015:(BUG)same as v055 for capdel del CR(line concat)  //~5A15I~
//****************************************************************//~5A15I~
int lcmdsingle(PUCLIENTWE Ppcw,ULCMD *Pplc);
//****************************************************************//~5223I~
int lcmdrep(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,ULCMD *Pplc);//~5223I~
//****************************************************************//~5A15I~
int lcmddel(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~5A15I~
            int Pcsropt,int Pnotlcmdmain);                      //~5A15I~
#define LCDEL_NOTFROMMAIN     0x01                                 //~v54XI~
#define LCDEL_BYDELNXALL      0x02                                 //~v54XI~
//**************************************************************** //~v0ibI~
int lcmddelbs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,int Pbandle,int Pskip);//~v0ibM~
//****************************************************************//~5223I~
int lcmdisrt(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pindentopt);//~5223I~
#define LCIO_INDENT 0x01      //indent                             //~v78SR~
#define LCIO_CONT   0x02      //save last inserted plh to pfh for continuous isrt//~v78SR~
#define LCIO_CONT2  0x04      //from lcmdisrtcont                  //+vb88I~
#ifdef UTF8UCS2                                                    //~va20I~
#define LCIO_ALLOCDBCS  0x04  //for lcmdisrtwithlen;allocate plhdbcs//~va20I~
#endif                                                             //~va20I~
//**************************************************************** //~v78SI~
int lcmdisrtcont(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);           //~v78SI~
//**************************************************************** //~v40XI~
int lcmdisrtwithlen(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pindentopt,int Plen);//~v40XI~
//****************************************************************//~5131I~
int lcmdrenumsuffix(PUCLIENTWE Ppcw,PULINEH Pplhprev,PULINEH Pplhnext,//~5A04R~
					int Pcount,int Pmovesw);                    //~5131I~
//****************************************************************
void lcmdeditxline(PULINEH Pplh);
//**************************************************************** //~v9@8I~
int lcmddelxline(PUCLIENTWE Ppcw,PULINEH Pplh);                    //~v9@8I~
//**************************************************************** //~v498I~
int lcmdincf(PUCLIENTWE Ppcw,PULINEH Pplh,int Prepeat,int Pcsropt);//~v498I~
//****************************************************************
int lcmdincm(PUCLIENTWE Ppcw,PULINEH Pplh);
//**************************************************************** //~v41kI~
int lcmdincall(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat);//~v41kI~
//**************************************************************** //~v0hzI~
int lcmdexc(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat);//~v0hzM~
//**************************************************************** //~v40pI~
int lcmdexcsame(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2);      //~v40pI~
//**************************************************************** //~v54BI~
int lcmdexcfromxall2(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2); //~v54BI~
//****************************************************************//~5226I~
int lcmdgetplhrange(PULINEH *Ppplh1,PULINEH *Ppplh2,int Prepeat);//~5226I~
//**************************************************************** //~v0i0I~
int lcmdgetplhrange2(PULINEH *Ppplh1,PULINEH *Ppplh2,PULINEH Pplhstop,int Prepeat);//~v0i0I~
//**************************************************************** //~v0hzI~
int lcmdclearlcmd(PUFILEH Ppfh,PULINEH Pplh);                      //~v0hzI~
//**************************************************************** //~v11uI~
int lcmdresetx(PUCLIENTWE Ppcw);                                   //~v11uI~
//**************************************************************** //~v54GI~
int lcmddelresetcurtop(PUCLIENTWE Ppcw,PULINEH Pplh);              //~v54GI~
//**************************************************************** //~vb86I~
int lcmdexcludedmsg(int Popt,PUFILEH Ppfh);                        //~vb86R~
#define LCXMO_MSGCAT           0x01                                //~vb86I~
#define LCXMO_NOMSG            0x02                                //~vb86I~
