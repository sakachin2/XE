//*CID://+vbzwR~:                             update#=  157;       //~vbzwR~
//*************************************************************
//*xegetmid.c                                                      //~v51aR~
//*	linux get terminal type                                        //~v51aR~
//*************************************************************
//vbzw:240306 try get plyph width by pango api                     //~vbzwI~
//v765:070531 (LNX:BUG)support "Konsole" as one of X-terminal      //~v765I~
//v51a:030419 (LNX)terminal type get for xe shell                  //~v51aI~
//*************************************************************    //~v19zI~
#include <stdlib.h>                                                //~0924R~
#include <stdio.h>                                                 //~0924I~
#include <string.h>                                                //~1122I~
#ifdef AIX                                                         //~v51aI~
    #include <ucurses.h>                                           //~v51aI~
#endif                                                             //~v51aI~
#include <term.h>                                                  //~v51aI~
                                                                   //~v40aI~
//**********************                                           //~0924I~
#include <ulib.h>                                                  //~v30eI~
#include <uque.h>                                                  //~1122R~
#include <ukbd.h>                                                  //~v30eI~
#include <ukbdl.h>                                                 //~v51aR~
#include <uerr.h>                                                  //~1122I~
#include <udbcschk.h>                                              //~1122I~
#include <utrace.h>                                                //~1122I~
#include <ufile.h>                                                 //~v518I~
//*************************************************************    //~0924I~
#define PGMID "xechksim"                                           //~v51aR~
#define VER   "1.0"                                                //~v51aI~
//*************************************************************    //~0924I~
//default kbd opt                                                  //~0924I~
//*********************************************************************//~0229I~
int main(int argc,char **argp)
{
    int termid,xid;                                                //~v51aR~
    char *termnm;                                                  //~v51aR~
//********************************
	if (argc>1)                                                    //~v51aI~
		if (!stricmp(argp[1],"-?")                                 //~v51aR~
	    ||  !stricmp(argp[1],"-h"))                                //~v51aR~
        {                                                          //~v51aI~
            printf("%s:%s:print terminal simulator type \n",PGMID,VER);//~v51aI~
//          printf("       xterm/kterm/gnome-terminal/X-terminol/kon/console\n");//~v765R~
            printf("       xterm/kterm/gnome-terminal/X-terminol/kon/console/konsole\n");//~v765R~
            return 1;                                              //~v51aR~
        }                                                          //~v51aI~
	uerrmsg_init("",0,0); 	//no stdout                            //~v51aR~
	termid=ukbdl_gettermsim();                                     //~v51aI~
    xid=termid & TERM_SIMID;                                       //~v51aR~
    switch(xid)                                                    //~v51aI~
    {                                                              //~v51aI~
    case TERM_XTERMSIM:                                            //~v51aI~
    	termnm="xterm";                                            //~v51aR~
        break;                                                     //~v51aI~
    case TERM_KTERMSIM:                                            //~v51aI~
    	termnm="kterm";                                            //~v51aR~
        break;                                                     //~v51aI~
    case TERM_GTERMSIM:                                            //~v51aI~
    	termnm="gnome-terminal";                                   //~v51aR~
        break;                                                     //~v51aI~
    case TERM_OTHERSIM:                                            //~v51aI~
    	termnm="X-terminal";                                       //~v51aR~
        break;                                                     //~v51aI~
    case TERM_KONSOLE:                                             //~v765I~
    	termnm="konsole";                                          //~v765R~
        break;                                                     //~v765I~
    case TERM_AIXTERMSIM:                                          //~v51aR~
    	termnm="aixterm";                                          //~v51aR~
        break;                                                     //~v51aI~
    case TERM_DTTERMSIM:                                           //~v51aR~
    	termnm="dtterm";                                           //~v51aR~
        break;                                                     //~v51aI~
    case TERM_NXTERMSIM:                                           //~v51aI~
    	termnm="nxterm";                                           //~v51aI~
        break;                                                     //~v51aI~
    case TERM_COLORXSIM:                                           //~v51aI~
    	termnm="color-xterm";                                      //~v51aI~
        break;                                                     //~v51aI~
    case TERM_RXVTSIM:                                             //~v51aI~
    	termnm="rxvt";                                             //~v51aI~
        break;                                                     //~v51aI~
    default:                                                       //~v51aI~
    	if (termid & TERM_UNDERKON)                                //~v51aI~
	    	termnm="kon";                                          //~v51aR~
        else                                                       //~v51aI~
        	termnm="console";                                      //~v51aR~
    }                                                              //~v51aI~
    printf("%s\n",termnm);                                         //~v765R~
    fflush(stdout);                                                //~v51aI~
    return 0;                                                      //~v51aI~
}//main
//int uvioGetCursorWidth(int Popt,ULONG Pucs){return 0;}  //avoid link err//+vbzwR~
