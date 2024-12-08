//*CID://+vbi3R~:                             update#=   47;       //~vbi3R~
//**************************************************************** //~8627I~
//vbi3:180211 supprt command history list                          //~vbi3I~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vb2D:160221 LNX compiler warning                                 //~vb2DI~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//v77L:080206 (BUG)EXE cmd ABEND when "END" cmd closed all panel   //~v77LI~
//v77K:080205 EXE cmd support parameter file EXE ___ [< { wildcard[{[p][f]}] | @filename} ]//~v77KI~
//v71A:061030 (WXE)Use HtmlHelp;Winhelp is deprecated at Vista;XP english ersion cannot read .hlp by the readson of codepage unsupported//~v71AI~
//v670:051224 cmd histry retrieve for each screen(A+F12)           //~v670I~
//v62J:050413 new lcmd(!):execute cmd on the line                  //~v62JI~
//v62G:050412 cmdlog function                                      //~5412I~
//v0im:980627 pfk cmd support(long cmd ove screenwidth)            //~8627I~
//****************************************************************
//*xefunc2.h
//****************************************************************
#define  XEHELP_TOP_HTML                 "indexj.htm"              //~v71AR~
#define  XEHELP_TOP_HTML_E               "indexe.htm"              //~v71AR~
#define  XEHELPDIR                       "xehelp"                  //~v71AI~
                                                                   //~v670M~
#define XECMDLOGFNM    "::cl"                                      //~v62JR~
#define LONGCMDCONTID  0x1f                                        //~8628I~
//*stack cmd                                                    //~5114I~
typedef struct _USCMD {						//stack cmd         //~5114I~
						UQUEE   USCqelem;   //fifo q            //~5114I~
                        int     USCcmdlenlc;//if not 0 cmd by locale code is save after USCcmd//~va1rR~
                        int     USCseqno;   //pcw instance no      //~v670I~
                        int     USCentryno; //malloc seqno(key of search for cmd history list)//~vbi3I~
                        int     USCcmdlen;  //cmd string len    //~5114R~
						UCHAR   USCcmd[1];	//cmd string        //~5114I~
					  	} USCMD;                                //~5114I~
typedef USCMD  *PUSCMD;                                         //~5114I~
//#define USCMDSZ (sizeof(USCMD))                                 //~5114I~//~vb2DR~
#define USCMDSZ ((int)sizeof(USCMD))                               //~vb2DI~
                                                                //~5114I~
//**************************************************            //~5114I~
//void funccmdstack(UCHAR *Pcmd,int Pcmdlen);                      //~v670R~
//void funccmdstack(UCHAR *Pcmd,int Pcmdlen,int Pseqno);           //~vbCBR~
PUSCMD funccmdstack(UCHAR *Pcmd,int Pcmdlen,int Pseqno);           //~vbCBI~
//**************************************************               //~va1rI~
#ifdef UTF8SUPPH                                                   //~va1rI~
void funccmdstack_utf8(int Popt,UCHAR *Pcmd,int Pcmdlen,int Pseqno);//~va1rR~
#define FCSO_SETCT     0x01 //save also codetbl                    //~va1rI~
#define FCSO_SETCTOK   0x02 //no strcmp required                   //~va1rI~
#endif                                                             //~va1rI~
                                                                //~5114I~
//**************************************************            //~5114I~
void funcfreecmdstack(void);                                    //~5114I~
                                                                //~6217I~
//**************************************************            //~6217I~
int funcwcmdstack(FILE *Pfh);                                   //~6217I~
                                                                //~6217I~
//**************************************************            //~6217I~
int funcrcmdstack(FILE *Pfh);                                   //~6217I~
                                                                   //~8627I~
//**************************************************               //~8627I~
int funcsetlongcmd(PUCLIENTWE Ppcw,int Popt,UCHAR *Pcmd,int Plen,int *Psetlen);//~8627I~
#define FSLCO_EXECUTE   0x01  //execute                            //~va1rI~
#define FSLCO_SETCT     0x10  //set lc/ct fro Gcmdbufflc/Gcmdbuffct//~va1rR~
#define FSLCO_SETCTOK   0x20  //cmdbuff u8 and lc is syncronized   //~va1rI~
                                                                   //~va1rI~
#ifdef UTF8SUPPH                                                   //~va1rI~
	int funcsetlongcmd_utf8(PUCLIENTWE Ppcw,int Popt,char *Pcmdu8,int Pcmdu8len,char *Pcmdlc,int Pcmdlclen,char *Pcodetype,int *Ppdatalen);//~va1rR~
#endif                                                             //~va1rI~
                                                                   //~8628I~
//**************************************************               //~8628I~
int funcgetlongcmd(PUCLIENTWE Ppcw,UCHAR *Pcmd);                   //~8628I~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************               //~va00I~
	int funcgetlongcmd_byutf8(int Popt,PUCLIENTWE Ppcw,UCHAR *Pcmd);//~va00I~
    #define FGLC8O_SETCT       0x01    //set Gcmdbufflc,Gcmdbuffct //~va1rI~
	#define BYUTF8_funcgetlongcmd(Ppcw,Pcmd) \
			funcgetlongcmd_byutf8(0,Ppcw,Pcmd)                     //~va00R~
#else                                                              //~va00I~
	#define BYUTF8_funcgetlongcmd(Ppcw,Pcmd) \
			funcgetlongcmd(Ppcw,Pcmd)                              //~va00I~
#endif                                                             //~va00I~
//**************************************************               //~5412I~
int funccmdlog(UCHAR *Pcmd,int Pcmdlen);                           //~5412M~
#define FCMDLOG_OPEN    0  //open log                              //~5412R~
#define FCMDLOG_CLOSE   1  //close log                             //~5412R~
#define FCMDLOG_START   2  //log start(after stack restore from ini file end)//~5412R~
#define FCMDLOG_TIMESTAMPID '='   //to skip cmdlog time stamp when execute line by "#" lcmd//~5413I~
//**************************************************               //~v62JI~
//int execmdsub(PUCLIENTWE Ppcw,char *Pcmdbuff,char **Pcmdparm,int *Pcmdsw,int *Pignorerc);//~v77KR~
int execmdsub(int Popt,PUCLIENTWE Ppcw,char *Pcmdbuff,char **Pcmdparm,int *Pcmdsw,int *Pignorerc,FILE *Pfhlog);//~v77KI~
//**************************************************               //~v77KI~
int funcparseredirect(int Popt,PUCLIENTWE Ppcw,char *Pcmdstr,char *Ppot,char *Ppodt,char *Pdelmt,//~v77KI~
					char **Ppredirectparm,int *Predirectparmidx,int *Predirectparmctr);//~v77KI~
#define FPR_UPDATEPCW         0x01                                 //~v77KI~
//**************************************************               //~v77LI~
int  funcerrexecmdinprog(void);                                    //~v77LI~
//**************************************************               //~vbCBI~
int funcrestorePSC(PUCLIENTWE Ppcw,PUSCMD Ppsc);                   //~vbCBR~
//**************************************************               //~vbi3I~
PUSCMD funcgetcmdstack(int Popt,PUSCMD Ppsc,char **Ppcmdstr,int *Pplen,int *Ppfmt);//~vbi3R~
//**************************************************               //~vbi3I~
PUSCMD funcsrchpsc(int Popt,int Pentryno);                         //~vbi3R~
#define FSPO_ERRMSG 0x01                                           //~vbi3I~
//**************************************************               //~vbi3I~
int funcretrievepsc(int Popt,PUCLIENTWE Ppcw,PUSCMD Ppsc,void* /*PULINEH*/ Pplh);//+vbi3R~
int funccmdrepeatpsc(int Popt,PUCLIENTWE Ppcw,PUSCMD Ppsc);        //~vbi3R~
