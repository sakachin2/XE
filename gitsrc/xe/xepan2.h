//*CID://+va0tR~:**                                                //~va0eR~//~va0tR~
//****************************************************************
//xepan2.h                                                         //~v76gR~
//****************************************************************
//va0t:090913!maintains locale and utf8 code for panel input(cmdline,panutil)//~va0tI~
//va0e:090718 (BUG)util cmd,missing clear ini data                 //~va0eI~
//v77C:080129*english spell chk                                    //~v77CI~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v54v:040114 display and select by cursor the driveid list.       //~v54vI~
//v0j1:980720 concatinated cmd for opt screen(hsp;6;.. rejected. hsp;=6;.. accepted)//~v0j1I~
//v07a:960615:allow dup key assign to differrent function for only on of assigned key//~v07aI~
//            color option-2                                       //~v07aI~
//              -field next value function for color register field//~v07aI~
//v075:960608:color option                                         //~v075I~
//*v020:950611:dir support(field full intercept)                //~v020I~
//*     950701:dir support(field clear intercept)               //~5701I~
//*     950708:change dir support                               //~v020I~
//**************************************************************** //~v07aI~
#define NOVALUE   0xff                                             //~v07aM~
#define ERVALUE   0xfe                                             //~v07aM~
#define NOINPUT   '_'                                              //~v07aM~
//****************************************************************//~v020I~
int panfieldevent(PUCLIENTWE Ppcw,int Peventid);                //~5701R~
#define PFE_FULL    0                                           //~5701R~
#define PFE_CLEAR   1                                           //~5701I~
                                                                //~5701I~
#define PANUHELPMSG       "  [ -nolist:display rc only.  Enter ? or --help for Help]"//~v76gR~
#define PANUHELPMSGGREP   "  [ Options and Pattern.  Enter ? or --help for Help]"//~v76jR~
#define PANUHELPMSGOPTFNM "  [ \"-f\" at end of \"Options\" allows 1st line as pattern file. ]"//~v76gR~
#define PANUHELPMSGFIND   "  [ Try InsertLine key (default:F5) after partial path input. ]"//~v76gR~
#define PANUHELPMSGFIND2  "  [ Then use Send keys (default:A+i/r/d/Up/Down) or \"^\" lcmd. ]"//~v77CR~
#define PANUHELPMSGDND    "  [ Drag & Drop is also available.                            ]"//~v76gR~
#define PANUHELPMSGRESET  "  [ Use RESet cmd (or Esc twice) to clear.                    ]"//~v76gR~
#define PANUOPTNOLIST     "-Nolist"                                //~v76gI~
//**************************************************************** //~v075I~
void panattr10(PUCLIENTWE Ppcw,int Prow,PUSCRD Ppsd);              //~v075R~
//****************************************************************//~v020I~
void pandraw300(PUCLIENTWE Ppcw);                               //~v020I~
//**************************************************************** //~v075I~
int panixtorgb(int Pindex,char *Prgb);                             //~v07aR~
//**************************************************************** //~v07aI~
UCHAR pangetrgbix(PUCLIENTWE Ppcw,int Prow,int Pfldno);            //~v07aI~
//**************************************************************** //~v07aI~
int panrgbtoix(int Prgb);                                          //~v07aI~
//**************************************************************** //~v0j1I~
int panfunc000optchk(PUCLIENTWE Ppcw,UCHAR *Pcmd,int *Prc);        //~v0j1I~
//**************************************************************** //~v54vI~
int pan300setcpath(PUCLIENTWE Ppcw,char Pdriveid);                 //~v54vI~
//**************************************************************** //~v76gI~
int panutildataproc(int Popt,PUCLIENTWE Ppcw,char **Ppdata,char **Ppdbcs,int *Pplen);//~v76gR~
#define PANUO_LINENO    0x00ff      //lineno                       //~v76gR~
#define PANUO_INIT      0x0100      //malloc data area             //~v76gR~
#define PANUO_GETLINE   0x0200      //get data line addr           //~v76gR~
#define PANUO_GETDATA   0x0400      //get pandata                  //~v76gR~
#define PANUO_FLDTOP    0x0800      //with GETLINE,return fld addr //~v76gI~
                                                                   //~v76gI~
#define PANUO_SETDATA   0x1000      //set pandata from parm        //~v76gR~
#define PANUO_SETFLD    0x2000      //set pandata to ufld          //~v76gI~
#define PANUO_SETSAVE   0x4000      //set pandata to static save   //~v76gI~
#define PANUO_HELPMSG   0x8000      //set helpmsg                  //~va0eR~
                                                                   //~v76jI~
#define PANU_WKFLDSZ    (MAXCOLUMN+_MAX_PATH+1)                    //~v76jI~
//**************************************************************** //~v76gI~
int pancomp(PUCLIENTWE Ppcw);                                      //~v76gI~
int pancompdraw(PUCLIENTWE Ppcw,int Popt);                         //~v76gI~
int pancompexec(PUCLIENTWE Ppcw);                                  //~v76gI~
//**************************************************************** //~v76gI~
int pangrep(PUCLIENTWE Ppcw);                                      //~v76gI~
int pangrepdraw(PUCLIENTWE Ppcw,int Popt);                         //~v76gI~
int pangrepexec(PUCLIENTWE Ppcw);                                  //~v76gI~
//**************************************************************** //~v76gI~
int panutilfind(int Popt,PUCLIENTWE Ppcw,int Pmenuid);             //~v76gR~
#define PANSENDO_LINENO  0x00ff                                    //~v76gI~
#define PANSENDO_REP     0x0100                                    //~v76gR~
#define PANSENDO_INS     0x0200                                    //~v76gR~
#define PANSENDO_DEL     0x0400                                    //~v76gR~
#define PANSENDO_UP      0x0800                                    //~v76gR~
#define PANSENDO_DOWN    0x1000                                    //~v76gR~
#define PANSENDO_DND   0x010000    // dragdrop                     //~v76gR~
#define PANSENDO_CMD   0x020000    //by cmd on util panel          //~v76gR~
//**************************************************************** //~v76gI~
int panutilreceive(int Popt,PUCLIENTWE Ppcw,PUCLIENTWE Ppcw2,int Ppanelid,char *Pfnm);//~v76gR~
//**************************************************************** //~v76gI~
int panutilpaste(int Pinsopt,PUCLIENTWE Ppcw,char *Pdata,int Pcopylen,int Ppffs);//~v76jI~
//**************************************************************** //~v76jI~
int panreset(PUCLIENTWE Ppcw);                                     //~v76gI~
//**************************************************************** //~v76gI~
int panutilreset(int Popt,PUCLIENTWE Ppcw,int Ppanelid);           //~v76gI~
//**************************************************************** //~v76gI~
int panutiliniput(FILE *Ppfh);                                     //~v76gI~
//**************************************************************** //~v76jI~
int panutiliniget(FILE *Ppfh);                                     //~v76gI~
                                                                   //~va0tI~
#ifdef UTF8SUPPH                                                   //~va0tI~
//**************************************************************** //~va0tI~
	int panutilgetpupl(int Popt,PUCLIENTWE Ppcw,PUPANELL *Pppupl,int *Pbuffszu8);//~va0tI~
#ifndef CCC                                                        //~va0tI~
//**************************************************************** //~va0tI~
	#define BYUTF8_pansetflddata(Popt,Ppcw,Plineid,Pfldid,Pdata) \
		pansetflddata_utf8(Popt,Ppcw,Plineid,Pfldid,Pdata)         //+va0tR~
	int pansetflddata_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,char *Pdata);//+va0tR~
#endif                                                             //~va0tI~
#else                                                              //~va0tI~
#ifndef CCC                                                        //~va0tI~
	#define BYUTF8_pansetflddata(Popt,Ppcw,Plineid,Pfldid,Pdata) \
		setflddata(Ppcw,Plineid,Pfldid,Pdata)                      //~va0tI~
#endif                                                             //~va0tI~
#endif                                                             //~va0tI~
