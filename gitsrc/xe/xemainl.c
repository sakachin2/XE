//*CID://+vbs5R~:                             update#=   97;       //+vbs5R~
//*************************************************************
//*xemainl.c                                                       //~0924R~
//*	linux xe main                                                  //~0924R~
//*************************************************************
//vbs5:201023 help more for --7(backspace and del)                 //+vbs5I~
//vb30:160411 (LNX)Compiler warning                                //~vb30I~
//vang:131214 NOSCO option(ignore puTTY:SCO Esc string)            //~vangI~
//va70:000701 LP64 option support                                  //~va70I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            mainl.c:(LNX)always no cleardbcs mode(clear done by uviom)//~va20I~
//v79A:081004 (LNX)BOLD option for FC5 CONSOLE(screen corruptted if A_BOLD is set)//~v79AI~
//v79z:080916 DBCS tbl for C and K of CJK                          //~v79zI~
//v78N:080521 (LNXCON)rctl support                                 //~v78NI~
//v75Z:070527 (LNX)add UNDERLINE option for insert mode as default for X-console-mode//~v75ZI~
//v63s:050526 (LNX)change default mouse click interval 2 to 10 for drag start(cap start)//~v63sI~
//v55M:040317 (UNX)help msg for option --1                         //~v55MI~
//v55g:040213 (UNX:BUG)force tab3(-tabs)                           //~v55gR~
//v53H:031019 set default to vt100 because telnet from aix to aix change $TERM to xterm//~v53HI~
//v53m:030928 (LNX)mouse support                                   //~v53mR~
//v53i:030927 (LNX)option not to twice write dbcs line             //~v53iI~
//v526:030819 no more need to force under X because it is determined by ps cmd//~v526I~
//v525:030819 force TTERM env(kbd and viol) option                 //~v525I~
//v524:030819 integrate UKBDLNXC_-->UKBDL_                         //~v524I~
//v51Y:030802 (AIX) key option for 7f force to BS/DEL/CHAR for also AIX//~v51YI~
//v51R:030802 (LNX) key option for 7f force to BS/DEL/CHAR         //~v51RI~
//v515:030405 (LNX)user key string specification file support      //~v515I~
//v482:020420 (AIX)acccept curses key when under x not only for xterm//~v482I~
//v478:020217 (UNX)use clearok if not splitted for redraw performance//~v478I~
//v45y:011221 (AIX)fix option;clearok and dbcsclear                //~v45yI~
//v45r:011215 (AIX)dbcs clear is yet option for AIX to test        //~v45rI~
//v45n:011212 (UNX)dbcs clear by default,drop --d option           //~v45nI~
//v45m:011212 (UNX)dbcs clear mode by --d option                   //~v45nI~
//v424:010920 UNX:change scrclear for dbcs split to option (--c)   //~v424I~
//v403:010205 AIX-X support:xterm on X                             //~v403I~
//v30e:010107 AIX support:original key string change function by -k parm.//~v30eI~
//v211:001126 LINUX nomore file parm(drop from help)               //~v211I~
//v20b:001001 chk xe assign not by pfk parm                        //~v20bI~
//v19Z:000929 LINUX support(free ALTL+Pfn parm)                    //~v19ZI~
//v19J:000925 LINUX support(insert cursor option;BLINK and/or REVERSE)//~v19JI~
//v19z:000924 LINUX support(mono color support)                    //~v19zI~
//*************************************************************    //~v19zI~
#include <stdlib.h>                                                //~0924R~
#include <stdio.h>                                                 //~0924I~
#include <string.h>                                                //~v53mR~
#ifdef AIX                                                         //~v525I~
    #include <ucurses.h>                                           //~v525I~
#endif                                                             //~v525I~
#include <term.h>                                                  //~v525I~
//**********************                                           //~0924I~
#include <ulib.h>                                                  //~v53mR~
#include <uedit.h>                                                 //~v53mR~
#include <ukbdl.h>                                                 //~v524I~
#include <ukbdlnxc.h>                                              //~0924I~
#ifdef AIX                                                         //~v403I~
	#include <ukbdaixt.h>                                          //~v403I~
#else                                                              //~v53mR~
	#include <ukbdlnxm.h>                                          //~v53mR~
#endif                                                             //~v403I~
//*************************************************************    //~0924I~
//*************************************************************    //~v53mI~
void xesetkbdopt(int Popt);                                        //~0924I~
//#ifdef AIX                                                       //~v55gR~
	void xesettabs(int Pinitsw);                                   //~v55gR~
//#endif                                                           //~v55gR~
int xemain(int parmc,char **parmp);                                //~0924I~
//*************************************************************    //~v19ZI~
//helpmsg                                                          //~v19ZI~
//*********************************************************************//~v19ZI~
void helpmsg(void)                                                 //~v19ZI~
{                                                                  //~v19ZI~
//********************************                                 //~v19ZI~
//  printf("xe [--bhmr] [-fxx] [cps]\n");                          //~v211R~
#ifdef AIX                                                         //~v30eI~
//  printf("xe [--bchmr] [--x] [--kfilename] [cps]\n");            //~v45yR~
//  printf("xe [--bcdhmr] [--x] [--kfilename] [cps]\n");           //~v51YR~
//  printf("xe [--bcdhmr] [--x] [--7{B|D|C}] [--kfilename] [cps]\n");//~v525R~
//  printf("xe [--bcdhmrt] [--x] [--7{B|D|C}] [--kfilename] [cps]\n");//~v526R~
//  printf("xe [--bcdhmrt] [--7{B|D|C}] [--kfilename] [cps]\n");   //~v53HR~
//  printf("xe [--bcdhmrtx] [--7{B|D|C}] [--kfilename] [cps]\n");  //~v55MR~
    printf("xe [--bcdhmrtx1] [--7{B|D|C}] [--kfilename] [cps]\n"); //~v55MI~
#else                                                              //~v30eI~
//  printf("xe [--bcdhmr] [cps]\n");                               //~v515R~
//  printf("xe [--bcdhmr] [--7{B|D|C}] [--kfilename] [cps]\n");    //~v53mR~
//  printf("xe [--bcdhmr] [--Mi-j] [--7{B|D|C}] [--kfilename] [cps]\n");//~v55MR~
//  printf("xe [--bcdhmr1] [--Mi-j] [--7{B|D|C}] [--kfilename] [cps]\n");//~v75ZR~
//  printf("xe [--bcdhmru1] [--Mi-j] [--7{B|D|C}] [--kfilename] [cps]\n");//~v79AR~
//  printf("xe [--bBcdhmru1] [--Mi-j] [--7{B|D|C}] [--kfilename] [cps]\n");//~v79AR~//~vangR~
    printf("xe [--bBcdhmru1] [--%s] [--%s] [--Mi-j] [--7{B|D|C}] [--kfilename] [cps]\n",OPTSTR_NOSCO,OPTSTR_Z2);//~vangR~
#endif                                                             //~v30eI~
//#ifdef LNX                                                       //~v51YR~
#ifdef UNX                                                         //~v51YI~
	printf(" --7  : force assign 0x7f to BackSpace,Delete or Char 0x'7f'.\n");//~v51RR~
#ifdef LNX                                                         //~v51YI~
	printf("        B:Backspace, D:Delete, C:character input.\n"); //+vbs5I~
	printf("        default is by terminfo.\n");                   //~v51RI~
#else                                                              //~v51YI~
	printf("        default is by BS for AIX.\n");                 //~v51YI~
#endif                                                             //~v51YI~
#endif                                                             //~v51RI~
#ifdef UTF8UCS2                                                    //~va20I~
#ifndef CURSESW                                                    //~v79zI~
	printf(" --1  : draw by one write API also for DBCS line.\n"); //~v55MI~
#else                                                              //~v79zI~
	printf(" --1  : draw DBCS line twice, write SBCS/DBCS only data each\n");//~v79zR~
#endif                                                             //~v79zI~
#endif                                                             //~va20I~
	printf(" --b  : Blink when insert key mode.\n");               //~v30eR~
#ifdef LNX                                                         //~v78NI~
	printf(" --B  : Reset default BOLD attribute usage for highlight color.\n");//~v79AR~
	printf("        Default: USE when X mode, Not USE when CONSOLE mode.\n");//~v79AR~
	printf("        A_BOLD may have effect on char glyph.\n");     //~v79AR~
	printf("        A_BOLD is now used e.g to display yellow(=brown+A_BOLD).\n");//~v79AR~
	printf("        This effect depends on environment such as terminfo.\n");//~v79AR~
#endif                                                             //~v78NI~
//#ifdef AIX                                                       //~v478R~
	printf(" --c  : Clear then Redraw at FullScrWrite when DBCS mode.\n");//~v55MR~
//#else                                                            //~v478R~
//	printf(" --c  : Clear and draw when DBCS mode.\n");            //~v478R~
//#endif                                                           //~v478R~
#ifdef AIX                                                         //~v45rI~
//  printf(" --d  : Clear DBCS line before redraw when DBCS mode.\n");//~v45yR~
#endif                                                             //~v45rI~
#ifndef CURSESW                                                    //~v79zI~
//  printf(" --d  : Clear and redraw only DBCS line when DBCS mode.\n");//~v55MR~
    printf(" --d  : redraw only updated line even when DBCS mode.\n");//~v55MI~
//  printf("        (default --c if screen is not splitted.)\n");  //~v55MR~
    printf("(default is Clear then Redraw at FullScrWrite if screen is not splitted.)\n");//~v55MR~
#else                                                              //~v79zI~
    printf(" --d  : not draw updated line only but whole screen when DBCS mode.\n");//~v79zI~
#endif                                                             //~v79zI~
	printf(" --h  : Help msg.\n");                                 //~v30eR~
//#ifdef AIX                                                       //~v515R~
	printf(" --k  : key string specification file name.\n");       //~v30eI~
//#endif                                                           //~v515R~
	printf(" --m  : Mono color mode.\n");                          //~v30eR~
#ifdef LNX                                                         //~v75ZI~
	printf(" --r  : Reverse when insert key mode. This is default under VT-Console.\n");//~v75ZI~
#else                                                              //~v75ZI~
	printf(" --r  : Reverse when insert key mode.it is default.\n");//~v30eR~
#endif                                                             //~v75ZI~
#ifdef AIX                                                         //~v403I~
    printf(" --t  : force TeraTerm keymap even if TERM!=vt100.(This is default)\n");//~v53HR~
//  printf(" --x  : execution on xterm under X.\n");               //~v482R~
//    printf(" --x  : execution under X.(default for aixterm).\n");//~v526R~
    printf(" --x  : force not TeraTerm keymap even if TERM==vt100.\n");//~v53HI~
#endif                                                             //~v403I~
//    printf("   fxx: free Func-key in combination with alt-key.\n");//~v20bR~
//    printf("        by up to 2 digit,F1 to Fxx is free; ex) -f6.\n");//~v20bR~
//    printf("        by up to 12 '0'/'1' binary digit,F1 to Fxx is free;  ex) -f111111.\n");//~v20bR~
//    printf("        free alt+Fn is kept original assignment,it is usualy Console-nn.\n");//~v20bR~
//    printf("        default is -f6.\n");                         //~v20bR~
#ifdef LNX                                                         //~v53mR~
	printf(" --u  : Underline when insert key mode.This is default under X-terminal.\n");//~v75ZI~
	printf(" --Mi-j: mouse click interval and dblclick interval by unit of 0.1 sec.\n");//~v63sR~
	printf("         i:down->up max interval for click, j:up->down interval for dblclick.\n");//~v63sR~
	printf("         default %d-%d.\n",UKLM_CLICK_INTVL,UKLM_DBLCLICK_INTVL);//~v63sR~
	printf(" --%s: ignore EscString defined for terminal type:SCO of puTTY.\n",OPTSTR_NOSCO);//~vangR~
	printf(" --%s : assign ^[[Z not to S+Tab but S+F2 according to SCO.\n",OPTSTR_Z2);//~vangR~
#endif                                                             //~v53mR~
  printf("\n   cps:common parms with other platforms.\n");         //~v19ZR~
    printf("       use -h flag(xe -h).\n");                        //~v19ZR~
	return;                                                        //~v19ZI~
}//helpmsg                                                         //~v19ZI~
//*************************************************************    //~v19ZI~
//free pfk mask parm proc                                          //~v19ZR~
//*********************************************************************//~v19ZI~
//int getpfkmask(char **Pnum)                                      //~v20bR~
//{                                                                //~v20bR~
//    char *pc,*pc0;                                               //~v20bR~
//    int  ii,mask,dc,bitsw,errsw=0;                               //~v20bR~
////********************************                               //~v20bR~
//    pc0=*Pnum+1;                                                 //~v20bR~
//    for (dc=0,bitsw=1,mask=0,pc=pc0;*pc;pc++)                    //~v20bR~
//        if (*pc>='0' && *pc<='9')                                //~v20bR~
//        {                                                        //~v20bR~
//            if (*pc>='2')                                        //~v20bR~
//                bitsw=0;                                         //~v20bR~
//            else                                                 //~v20bR~
//                mask=(mask<<1)+*pc-'0'; //bit on if "1"          //~v20bR~
//            dc++;                                                //~v20bR~
//        }                                                        //~v20bR~
//        else                                                     //~v20bR~
//            break;                                               //~v20bR~
//    *Pnum=pc;   //update next byte                               //~v20bR~
//    if (!dc)                                                     //~v20bR~
//        errsw=1;                                                 //~v20bR~
//    else                                                         //~v20bR~
//    if (dc<=2)  //pfk num specification is "from 1 to n"         //~v20bR~
//    {                                                            //~v20bR~
//        dc=atoi(pc0);                                            //~v20bR~
//        if (dc>12)                                               //~v20bR~
//            errsw=1;                                             //~v20bR~
//        else                                                     //~v20bR~
//            for (ii=0,mask=0;ii<dc;ii++)                         //~v20bR~
//                mask=(mask<<1)+1;       //bit on until the pfk num//~v20bR~
//    }                                                            //~v20bR~
//    else                                                         //~v20bR~
//        if (!bitsw || dc>12)    //not all 1 or 0                 //~v20bR~
//            errsw=1;                                             //~v20bR~
//    if (errsw)                                                   //~v20bR~
//    {                                                            //~v20bR~
//        helpmsg();                                               //~v20bR~
//        exit(4);                                                 //~v20bR~
//    }                                                            //~v20bR~
//    return   mask;  //free Fn mask                               //~v20bR~
//}//getpfkmask                                                    //~v20bR~
//*************************************************************    //~0924I~
//default kbd opt                                                  //~0924I~
//*********************************************************************//~0229I~
int main(int argc,char **argp)
{
//  int ii,parmc,opt,insertmodesw=0;                               //~v19JR~//~vb30R~
    int ii,parmc,insertmodesw=0;                                   //~vb30I~
    unsigned opt;                                                  //~vb30I~
#ifdef LNX                                                         //~v53mI~
    long intvl=-1;  //use default                                  //~v53mR~
    long intvlclick,intvldblclick;                                 //~v53mI~
//  int rc;                                                        //~v55gR~
#endif                                                             //~v53mI~
    int rc;                                                        //~v55gI~
    char **parmp,*pc;                                              //~v30eR~
//#ifdef AIX                                                       //~v515R~
    char *cnffnm=0;                                                //~v30eI~
#ifdef AIX                                                         //~v515I~
//    int   xxtermsw=0;                                            //~v526R~
#endif                                                             //~v30eI~
//********************************
	opt=0                                                          //~0924I~
       +UKBDL_USEALTL  //  0x01      //use altL as ALT func key    //~v524R~
       +UKBDL_USEALTR  //  0x02      //use altR as ALT func key    //~v524R~
       +UKBDL_COMPOSE  //0x0100      //set katakana composer       //~v524R~
       +UKBDL_CURSES   //0x1000      //use curses                  //~v524R~
       +0x00000fc0     //pf7-pf12    //alt+pfn usage               //~0924I~
  #ifndef CURSESW                                                  //~v79zI~
       +UKBDL_CLEAR1     //use clearok when not splitted(default)  //~v524R~
  #endif                                                           //~v79zI~
#ifndef AIX                                                        //~v45rI~
  #ifndef CURSESW                                                  //~v79zI~
       +UKBDL_CLEARDBCS  //dbcs clear and rewrite when DBCS mode   //~v524R~
  #endif                                                           //~v79zI~
#else   //AIX                                                      //~v45yI~
//     +UKBDLNXC_CLEAR     //clear screen before draw              //~v45yR~
       +UKBDL_TNTT        //teraterm                               //~v53HM~
       +UKBDL_CLEARDBCS  //dbcs clear and rewrite when DBCS mode   //~v524R~
#endif                                                             //~v45rI~
       ; 		//default option to ukbdlnxc.c                     //~0924I~
//select parm to xe                                                //~0924I~
//	parmp=malloc((unsigned int)((argc+1)*4));                      //~0924I~//~va70R~
  	parmp=malloc((unsigned int)((argc+1)*PTRSZ));                  //~va70I~
    parmp[0]=argp[0];       //1st parm is cmd name                 //~0924I~
    parmc=1;                                                       //~0924I~
    for (ii=1;ii<argc;ii++)                                        //~0807I~
    {                                                              //~0807I~
    	pc=argp[ii];                                               //~0924I~
    	if (*pc!='-' || *(pc+1)!='-')	//parm to xe(--xxx is parm to xemailnl)//~0924I~
        {                                                          //~0924I~
        	parmp[parmc++]=pc;                                     //~0924I~
            continue;                                              //~0924I~
        }                                                          //~0924I~
//process parm to xemainl.c                                        //~0924I~
        pc+=2;                                                     //~v30eI~
        if (!stricmp(pc,OPTSTR_NOSCO))                             //~vangR~
        {                                                          //~vangI~
            opt|=UKBDL_NOSCO;                                      //~vangI~
            continue;                                              //~vangI~
        }                                                          //~vangI~
        if (!stricmp(pc,OPTSTR_Z2))                                //~vangI~
        {                                                          //~vangI~
            opt|=UKBDL_Z2;                                         //~vangI~
            continue;                                              //~vangI~
        }                                                          //~vangI~
//#ifdef AIX                                                       //~v515R~
        if (*pc=='K' || *pc=='k')                                  //~v30eI~
        {                                                          //~v30eI~
            cnffnm=pc+1;                                           //~v30eI~
            continue;                                              //~v30eI~
        }                                                          //~v30eI~
//#endif                                                           //~v515R~
//#ifdef LNX                                                       //~v51YR~
#ifdef UNX                                                         //~v51YI~
        if (*pc=='7')                                              //~v51RI~
        {                                                          //~v51RI~
            switch(*(pc+1))                                        //~v51RI~
            {                                                      //~v51RI~
            case 'B':                                              //~v51RI~
            case 'b':                                              //~v51RI~
                opt|=UKBDL_7fBS;                                   //~v524R~
                break;                                             //~v51RI~
            case 'D':                                              //~v51RI~
            case 'd':                                              //~v51RI~
                opt|=UKBDL_7fDEL;                                  //~v524R~
                break;                                             //~v51RI~
            case 'C':                                              //~v51RI~
            case 'c':                                              //~v51RI~
                opt|=UKBDL_7fCHAR;                                 //~v524R~
                break;                                             //~v51RI~
            default:                                               //~v51RI~
                printf("parm err(%s)\n",pc);                       //~v51RI~
                helpmsg();                                         //~v51RI~
                exit(1);                                           //~v51RI~
            }                                                      //~v51RI~
            continue;                                              //~v51RI~
        }                                                          //~v51RI~
#endif                                                             //~v51RM~
        for (;*pc;pc++)                                            //~v30eR~
        	switch(*pc)                                            //~v19JI~
            {                                                      //~v19JI~
#ifdef UTF8UCS2                                                    //~va20I~
#else                                                              //~va20I~
            case '1':                                              //~v53iI~
#ifndef CURSESW                                                    //~v79zM~
            	opt&=~UKBDL_CLEARDBCS;  //no dbcs line write twice //~v53iI~
#else                                                              //~v79zI~
            	opt|=UKBDL_CLEARDBCS;  //no dbcs line write twice  //~v79zI~
#endif                                                             //~v79zM~
                break;                                             //~v53iI~
#endif  //!UTF8UCS2                                                //~va20I~
            case 'B':                                              //~v19ZM~
#ifdef LNX                                                         //~v79AR~
            	opt|=UKBDL_BOLD;  //no A_BOLD use                  //~v79AR~
                break;                                             //~v79AR~
#endif                                                             //~v79AR~
            case 'b':                                              //~v19ZM~
            	opt|=UKBDL_BLINK;	//blink when insert mode       //~v524R~
                insertmodesw=1;                                    //~v19ZM~
                break;                                             //~v19ZM~
//#ifndef AIX                                                      //~v45yR~
            case 'C':                                              //~v424I~
            case 'c':                                              //~v424I~
            	opt|=UKBDL_CLEAR;    //clear screen before draw    //~v524R~
//            	opt&=~UKBDL_CLEAR1;    //reset clear when not splitted//~v524R~//~vb30R~
//            	opt&=~(unsigned)UKBDL_CLEAR1;    //reset clear when not splitted//~vb30I~
                break;                                             //~v424I~
//#endif                                                           //~v45yR~
//#ifdef AIX                                                       //~v45yR~
//            case 'D':                                            //~v45yR~
//            case 'd':                                            //~v45yR~
//                opt|=UKBDLNXC_CLEARDBCS; //dbcs clear and rewrite when DBCS mode//~v45yR~
//                break;                                           //~v45yR~
//#endif                                                           //~v45yR~
              case 'D':                                            //~v478I~
              case 'd':                                            //~v478I~
#ifndef CURSESW                                                    //~v79zM~
            	opt&=~UKBDL_CLEAR1;	//reset clear when not splitted//~v524R~
#else                                                              //~v79zI~
            	opt|=UKBDL_CLEAR1;	//reset clear when not splitted//~v79zI~
#endif                                                             //~v79zI~
                break;                                             //~v478I~
//            case 'F':                                            //~v20bR~
//            case 'f':                                            //~v20bR~
//                opt &=~UKBDLNXC_ALTPFKMASK; //reset once         //~v20bR~
//                opt |=getpfkmask(&pc);                           //~v20bR~
//                pc--;       //for next pc++                      //~v20bR~
//                break;                                           //~v20bR~
            case 'H':                                              //~v19ZI~
            case 'h':                                              //~v19ZI~
            	helpmsg();                                         //~v19ZI~
            	exit(0);                                           //~v19ZI~
                break;                                             //~v19ZI~
            case 'L':    //line mode,no clear even if full screen mode//~v53iI~
            case 'l':                                              //~v53iI~
            	opt&=~(UKBDL_CLEAR|UKBDL_CLEAR1);//reset clear spli or not split//~v53iR~
                break;                                             //~v53iI~
#ifdef LNX                                                         //~v53mI~
            case 'M':                                              //~v19JI~
                if (!*(pc+1))                                      //~v53mI~
                {                                                  //~v53mI~
                	printf("parm format err(%s)\n",pc);            //~v53mI~
                    exit(1);                                       //~v53mI~
                }                                                  //~v53mI~
                rc=ugetnumrange(pc+1,&intvlclick,&intvldblclick);  //~v53mI~
                switch (rc)                                        //~v53mI~
                {                                                  //~v53mI~
                case 0:                                            //~v53mI~
                	intvldblclick=UKLM_DBLCLICK_INTVL;             //~v53mI~
                    break;                                         //~v53mI~
                case 1:                                            //~v53mI~
                    break;                                         //~v53mI~
                default:                                           //~v53mI~
                	printf("parm format err(%s)\n",pc);            //~v53mI~
                    exit(1);                                       //~v53mI~
                }                                                  //~v53mI~
                intvl=(intvlclick<<16)+intvldblclick;              //~v53mI~
                for (;*pc;pc++)                                    //~v53mI~
                	if (*pc==' ')                                  //~v53mI~
                    	break;                                     //~v53mI~
                pc--;                                              //~v53mI~
                break;                                             //~v53mR~
#endif                                                             //~v53mI~
            case 'm':                                              //~v19JI~
            	opt|=UKBDL_MONO;	//mono color                   //~v524R~
                break;                                             //~v19JI~
            case 'R':                                              //~v19JI~
            case 'r':                                              //~v19JI~
            	opt|=UKBDL_REVERSE;  //reverse when insert mode    //~v524R~
                insertmodesw=1;                                    //~v19JI~
                break;                                             //~v19JI~
#ifdef LNX                                                         //~v75ZI~
            case 'U':                                              //~v75ZI~
            case 'u':                                              //~v75ZI~
            	opt|=UKBDL_UNDERLINE;	//blink when insert mode   //~v75ZI~
                insertmodesw=1;                                    //~v75ZI~
                break;                                             //~v75ZI~
#endif                                                             //~v75ZI~
#ifdef AIX                                                         //~v403I~
            case 'T':                                              //~v525I~
            case 't':                                              //~v525I~
                opt|=UKBDL_TNTT;                                   //~v525I~
                opt&=~UKBDL_TNLNX;  //resey lnx                    //~v53HI~
                break;                                             //~v525I~
//            case 'X':                                            //~v526R~
//            case 'x':                                            //~v526R~
//                xxtermsw=1;                                      //~v526R~
//                break;                                           //~v526R~
            case 'X':                                              //~v53HI~
            case 'x':                                              //~v53HI~
                opt&=~UKBDL_TNTT; 	//reset teraterm               //~v53HI~
                opt|=UKBDL_TNLNX;   //set linux                    //~v53HI~
                break;                                             //~v53HI~
#endif                                                             //~v403I~
            default:                                               //~v19JI~
            	printf("parm err(%c)\n",*pc);                      //~v19ZR~
                helpmsg();                                         //~v19ZR~
                exit(1);                                           //~v19JI~
            }                                                      //~v19JI~
    }                                                              //~0807I~
    if (!insertmodesw)                                             //~v19JI~
    {                                                              //~v75ZI~
#ifdef LNX                                                         //~v75ZI~
    	opt|=UKBDL_UNDERLINE;  //select later at uviol_init if under X-terminal//~v75ZR~
#endif                                                             //~v75ZM~
    	opt|=UKBDL_REVERSE;  //mono color                          //~v524R~
    }                                                              //~v75ZI~
    parmp[parmc]=0;       //terminator                             //~0924I~
//**********                                                       //~0924I~
//#ifdef AIX                                                       //~v55gR~
    xesettabs(1);                                                  //~v55gI~
//#endif                                                           //~v55gR~
//  xesetkbdopt(opt);//tell to xe                                  //~0924I~//~vb30R~
    xesetkbdopt((int)opt);//tell to xe                             //~vb30I~
#ifdef AIX                                                         //~v30eI~
//    if (xxtermsw)                                                //~v526R~
//        Gkbdaixt_opt|=GKBAIX_XXTERM;                             //~v526R~
    if (cnffnm)                                                    //~v30eI~
//  	ukbdaixt_chngttkey(cnffnm);                                //~v525R~
    	ukbdaixt_chngttkey(opt,cnffnm);                            //~v525I~
#else                                                              //~v515I~
    if (cnffnm)                                                    //~v515I~
//  	ukbdlnxc_chngttkey(cnffnm);                                //~v78NR~
    	ukbdlnxc_chngttkey(0,cnffnm);                              //~v78NI~
    ukbdlnxm_mouseopt(intvl);                                      //~v53mR~
#endif                                                             //~v30eI~
//  return xemain(parmc,parmp);                                    //~v55gR~
    rc=xemain(parmc,parmp);                                        //~v55gI~
//#ifdef AIX                                                       //~v55gR~
    xesettabs(0);                                                  //~v55gI~
//#endif                                                           //~v55gR~
    return rc;                                                     //~v55gI~
}//main
//#ifdef AIX                                                       //~v55gR~
//*********************************************************************//~v55gI~
//* assign sym to keycode with modifier                            //~v55gI~
//*********************************************************************//~v55gI~
void xesettabs(int Pinitsw)                                        //~v55gI~
{                                                                  //~v55gI~
static struct termios Soldtios;                                    //~v55gI~
       struct termios newtios;                                     //~v55gI~
    int fd=0;   //stdin                                            //~v55gI~
//*****************************                                    //~v55gI~
	if (Pinitsw)                                                   //~v55gI~
    {                                                              //~v55gI~
    	ukbdl_tcgetattr(fd,&Soldtios);                             //~v55gI~
	    memcpy(&newtios,&Soldtios,sizeof(newtios));                //~v55gI~
        newtios.c_oflag |= TABDLY;  //tab delay(rep tab by space)  //~v55gI~
    	ukbdl_tcsetattr(fd,&newtios);                              //~v55gI~
    }                                                              //~v55gI~
    else                                                           //~v55gI~
    	ukbdl_tcsetattr(fd,&Soldtios);                             //~v55gI~
    return;                                                        //~v55gI~
}//xesettabs                                                       //~v55gI~
//#endif                                                           //~v55gR~
