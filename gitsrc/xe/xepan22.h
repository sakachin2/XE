//*CID://+vavpR~:                             update#=  106;       //~vavpR~
//****************************************************************
//xepan22.h
//****************************************************************
//vavp:140426 (vaub for Win)maintain ddfmt for pan fnmlist and util panel//~vavpI~
//vavc:140421 (Win)unicode support(UD fmt string)                  //~vavaI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vaub:140306 maintain ddfmt for pan fnmlist and util panel        //~va5wI~
//va5w:100517 panutil:keep utf8 codetype over session              //~va5wI~
//va5t:100515 display filenamelist by dd fmt                       //~va5tI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1y:091108_(UTF8)like as cmd string,stack filename list with lc //~va1yI~
//va0E:090725!accept utf8 input on =3.14 option line(utfg string search)//~va0EI~
//va0t:090913!maintains locale and utf8 code for panel input(cmdline,panutil)//~va0tI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          filename list is mixed of utf8 and locale code         //~va00I~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v61r:050302 keep edit or browse id on filename queue             //~v61rI~
//v61c:050221 set open parm to filename list to reopen by same option//~v61cI~
//v55V:040321 (WIN)filename list ! lcmd(openwith) support          //~v55VI~
//v55U:040321 (WXE)openwith when dblclick on filenamelist/dirlist if associated//~v55UI~
//v557:040203 filename list multi-page support                     //~v557I~
//v54v:040114 display and select by cursor the driveid list.       //~v54vI~
//v53c:030921 alt+w for C&P copy word                              //~v53cI~
//v20y:001028 new function:filename selection on menu 1/2 name list
//****************************************************************
#ifdef DOSDOS                                                      //~v557R~
	#define MAXFNMLIST  30                                         //~v557R~
#else                                                              //~v557R~
	#define MAXFNMLIST  200                                        //~v557R~
#endif                                                             //~v557R~
#ifdef  XEPAN22_GLOBAL                                             //~v557R~
	int  Gmaxfnmlist=MAXFNMLIST;                                   //~v557R~
#else                                                              //~v557R~
	extern int  Gmaxfnmlist;                                       //~v557R~
#endif                                                             //~v557R~
//**************************************************************** //~v61rI~
typedef struct _UP300LIST {						//stack cmd                   ,//~v61rM~
						UQUEE   U3Lqelem;   //fifo q                          ,//~v61rM~
                        int     U3Lflag;	                       //~v61cI~  ,//~v61rM~
#define U3LFCMDMASK      0x00ff                                    //~v61cR~  ,//~v61rM~
#define U3LFCMDBINCMD    'b'                                       //~v61cI~  ,//~v61rM~
#define U3LFCMDBINLCMD   '3'                                       //~v61cR~  ,//~v61rM~
#define U3LFSPACEEMBEDED 0x0100                                    //~v61cI~  ,//~v61rM~
#define U3LFPARM         0x0200                                    //~v61cI~  ,//~v61rM~
                                                                   //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
#define U3LFDRAW         0x1000    //editcmd at drawing            //~va00R~
#define U3LFUTF8CHKED    0x2000    //utf8 code chk done            //~va00I~
#define U3LFF2L          0x4000    //filename contains utf8 code,converted to locale code//~va00R~
#define U3LFDRAWDD       0x8000    //editcmd at drawing by dd fmt  //~va5tR~
#endif                                                             //~va00I~
						void   *U3Lplh;     //plh for find support //~v76mI~
#ifdef UTF8SUPPH                                                   //~v90rI~//~va00I~
						char   *U3Lcodetype; //codetype utf8/locale//~va00I~
						char   *U3Lfnmbylc;  //by locale code      //~va00R~
                        int     U3Lnetfnmlenbylc;  //net filename len  by locale code//~va00I~
	#define U3L_GETLOCALEDATA_LEN(pup3,addr) \
		((pup3->U3Lflag & U3LFF2L) ? (*(addr)=pup3->U3Lfnmbylc,pup3->U3Lnetfnmlenbylc)  \
    		                       : (*(addr)=pup3->U3Lfnm,pup3->U3Lnetfnmlen))//~va00R~
#else                                                              //~va00I~
	#define U3L_GETLOCALEDATA_LEN(pup3,addr) \
    		                       (*(addr)=pup3->U3Lfnm,pup3->U3Lnetfnmlen)//~va00I~
#endif                                                             //~v90rI~//~va00I~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//~vavpI~
						int     U3Lddlen;                          //~vaubI~
						char   *U3Ldddata;                         //~vaubI~
						char   *U3Ldddbcs;                         //~vaubI~
						char   *U3Lddcode;                         //~vaubI~
#endif                                                             //~vaubI~
                        int     U3Lnetfnmlen;  //net filename len  //~v61cI~  ,//~v61rM~
                        int     U3Lfnmlen;  //cmd string len                  ,//~v61rM~
						UCHAR   U3Lfnm[1];	//cmd string                      ,//~v61rM~
//#ifdef LNX                                                         //~vaubI~//~vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavpI~
#define U3LDDFMTNAMEID  0x00                                       //~vaubR~
#endif                                                             //~vaubI~
					  	} UP300LIST,*PUP300LIST;           //                 ,//~v76mR~
#define UP300LISTSZ (sizeof(UP300LIST))                      //               ,//~v76mR~
//**************************************************************** //~v76mM~
int pan300init(PUCLIENTWE Ppcw);                                   //~v76mM~
//**************************************************************** //~v54vI~
int pan300updatelist(PUCLIENTWE Ppcw,int Pwakeupsw);
//****************************************************************
//void pan300stack(PUCLIENTWE Ppcw,PUFILEH Ppfh);                  //~v61cR~
void pan300stack(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUCLIENTWE Pcmdpcw); //~v61cR~
//****************************************************************
void pan300freestack(void);
//****************************************************************
int pan300wstack(FILE *Pfh);
//****************************************************************
int pan300rstack(FILE *Pfh);
//****************************************************************
int pan300felcmd(PUCLIENTWE Ppcw,UCHAR *Pdata,int Peventid);
//****************************************************************
int pan300execlist(PUCLIENTWE Ppcw);
//**************************************************************** //~v53cI~
int pan300getword(PUCLIENTWE Ppcw,char *Pword,int Plen);           //~v53cI~
//**************************************************************** //~v54vI~
int pan300drawdid(PUCLIENTWE Ppcw);                                //~v54vM~
//**************************************************************** //~v55UI~
int pan300getfnm(int Pyy,UCHAR *Pout);                             //~v55UR~
//**************************************************************** //~v55VI~
void pan300addentry(UCHAR *Pfnm,int Pfnmlen,int Pinitsw);          //~v55VI~
#define PAN300AEO_INIT    0x01                                     //~v61rM~
#define PAN300AEO_REMOTE  0x02                                     //~v61rM~
#define PAN300AEO_BECMD   0x04                                     //~v61rM~
#define PAN300AEO_BROWSE  0x10                                     //~v61rI~
#define PAN300AEO_EDIT    0x20                                     //~v61rI~
#define PAN300AEO_SETCT   0x40  //get codetbl from Gcmdbuffct      //~va1yI~
//**************************************************************** //~v76mM~
int panfnlfind(int Popt,PUCLIENTWE Ppcw);                          //~v76mM~
#define PANFIND_ICASE    0x01        //case insensitive search     //~v76mM~
#define PANFIND_RFIND    0x02        //re-find key                 //~v76mM~
#define PANFIND_REV      0x04        //reverse search              //~v76mM~
//**************************************************************** //~v76mI~
int panfnlsetuppfh(PUCLIENTWE Ppcw,UQUEH *Ppqh);                   //~v76mI~
//**************************************************************** //~v76mI~
int panfnlfreepfh(void);                                           //~v76mI~
//**************************************************************** //~v76mI~
int panfnlupdatepfh(int Popt,PUP300LIST Ppqh);                     //~v76mR~
#define PANFIND_ENQ      0x01	//enq to top(neq or reenq)         //~v76mI~
#define PANFIND_DEQ      0x02   //delete                           //~v76mR~
//**************************************************************** //~v76mI~
int panfnlfind(int Popt,PUCLIENTWE Ppcw);                          //~v76mR~
//**************************************************************** //~v76mI~
int pan300locatepage(PUCLIENTWE Ppcw,int Plinetop,int Plinecsr);   //~v76mR~
//**************************************************************** //~v76mI~
int panfnlgetstartplhoffs(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Popt);//~v76mI~
//**************************************************************** //~va00I~
#ifdef UTF8SUPPH                                                   //~va00R~
	int pan300attr(PUCLIENTWE Ppcw,int Prow,PUSCRD Ppsd);          //~va00I~
	UCHAR *pan300getfldpos_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata);//~va00I~
	int pan300setflddata_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata);//~va00I~
	int pan300editcmdf2l(int Popt,PUP300LIST Ppsc);                //~va00M~
    #define P3EF2LO_SETCT 0x01 //set lc/ct from cmdbuff            //~va1yI~
#ifdef CCC                                                         //~va0tI~
	int pansetflddata_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno);//~va00I~
#endif                                                             //~va0tM~
	int pancompsetflddata_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata);//~va00I~
	int pangrepsetflddata_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata);//~va00I~
	UCHAR *pancompgetfldpos_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata);//~va00I~
	UCHAR *pangrepgetfldpos_utf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata);//~va00I~
	int pancompdraw2(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,int Pyy);//~va00I~
	int pangrepdraw2(int Popt,PUCLIENTWE Ppcw,PUSCRD Ppsd,int Pyy);//~va00I~
	int pansetfnmattr(PUCLIENTWE Ppcw,PUSCRD Ppsd,int Prow,int Pfldid,char *Pcodetype,int Plclen);//~va00M~
	int panutilfldupdate_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,int Poffs,char *Pdata,int Pdatalen,char*Pdbcs);//~va00R~
    #define PUFU8O_INS        0x01		//insert mode              //~va00R~
    #define PUFU8O_PARMROW    0x02		//use param Prow not Ppcw->UCWrcsry//~va0EI~
#ifdef UTF8UCS2                                                    //~va20I~
    #define PUFU8O_SETCT2     0x04		//lc through Gcmdbufflc    //~va20I~
#endif                                                             //~va20I~
	int pan300fldupdate_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,int Ppos,UCHAR *Pdata,int Pdatalen,char *Pdbcs);//~va00I~
    #define P3FU8O_INS        0x01		//insert mode              //~va00I~
#ifdef UTF8UCS2                                                    //~va20I~
    #define P3FU8O_SETCT2     0x04		//lc through Gcmdbufflc    //~va20I~
#endif                                                             //~va20I~
//**************************************************************** //~va00I~
	int pansetfld_f2l(int Popt,PUPANELL Ppupl,int Pfldno,char *Pdata,char *Pdatabylc,int Poutbuffsz,int *Ppoutlen);//~va00R~
    #define  PSFF2LO_USECT       0x01                              //~va5wI~
//**************************************************************** //~va00I~
	int pangetbuff_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,//~va0tI~
					PUPANELL *Pppupl,UCHAR **Ppbuffu8,UCHAR **Ppcodetype,int *Ppbuffu8sz);//~va0tR~
	int pan300stackchkcmdbuff(int Popt,char *Pfpath);              //~va1yI~
    #define P3SCCBO_CHKFULLPARMFNAME   0x01 //no preceding ascii chk//~vavaI~
    #define P3SCCBO_RCIFLC             0x02 //set rc=3 if U8=LC    //~vavaI~
//	int pan300stacksetctfromcmdbuffsub(int Popt,char *Ppu8,char *Pplc,char *Ppct,int Pbuffsz);//~vaubR~
  	int pan300stacksetctfromcmdbuffsub(int Popt,char *Ppu8,char *Pplc,char *Ppct,int Pbuffsz,//~vaubR~
    		char *Pdddata,char *Pdddbcs,char *Pddcode,int Pddbuffsz,int *Pddlen);//~vaubR~
#endif                                                             //~va00I~
//#ifdef LNX                                                         //~vaubI~//+vavpR~
#if defined(LNX) || defined(W32UNICODE)                            //~vavaI~//+vavpI~
int panutillf2dd(int Popt,PUCLIENTWE Ppcw,PUPANELL Ppupl,PUSCRD Ppsd,int Prow,int Pfldno,int Plclen);//~vaubI~
#endif                                                             //~vaubI~
