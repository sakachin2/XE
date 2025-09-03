//*CID://+vbD2R~:                             update#=   36;       //+vbD2R~
//*********************************************************************
//* keyboard sub hdr
//*********************************************************************
//vbD2:250624 save funkkey/shortcut cmd to another file for save operation in multiple sessions//+vbD2I~
//vb50:160827 accept S+A/C+extended key                            //~vb50I~
//vanf:131209 alias cmd;support addtional parm;%*,%^ for filename,%@ all remaining//~vanfI~
//vafm:120626 LLP64 changes infile size                            //~vafmI~
//va70:000701 LP64 option support                                  //~v70YI~
//v69Y:060722 add A+"=" to virtical line for 101 keyboard (scancode=13, "^" on japanese kbd)//~v69YI~
//v69A:060609 (LNX:BUG)keyname euc conversion process should be done before before functable init//~v69AI~
//v69z:060609 (LNX:UTF)utf8 support                                //~v69zI~
//v67C:051228 support alias cmd(save in ini file using shortcut key table position ":")//~v67CI~
//v641:050614 (LNX)xxe support;ukbdsym splitted to ulib            //~v641I~
//v58q:040923 (BUG)submit child shell dose not wait key enter      //~v589I~
//            (as v142,Enter key genarate 0a1c after 0d1c)         //~v589I~
//v55c:040208 (WXE)distingush L-CTL/R-CTL & report R-CTL           //~v55cI~
//v500:020827 wxe support                                          //~v500I~
//v48p:020519 (DOS:BUG)int size is 2 byte for DOS(ini save data size)//~v48pI~
//v48f:020504 more key for macro function(not only PFn but also A+q,A+a and 1 byte char)//~v48fI~
//v0j7:980720 int size of DOS and W32(ini write entno)             //~v0j7I~
//v0ix:980718 key assign by key press                              //~v0ixI~
//v0io:980702 pfk cmd support(opt 0.4)                             //~v0ioI~
//v0ij:980625 pfk cmd support(save to ini)                         //~v0ijI~
//v0ih:980621 pfk cmd support(pfk table)                           //~v0ihI~
//v09t:970523:(BUG)need re-init kbd binary mode after child shell  //~v09tI~
//*v01a:950705:kbd rate ini option(entry and exit value)        //~v01aI~
//*******************************************************
//* function key definition
//* (treate xxe0 as xx00)
//*******************************************************
#include <ukbdsym.h>                                               //~v589I~
//*DATA TYPE ******************************************************
//*function key table entry
typedef struct _KEYTBL	{
				 		UCHAR   KTnamee[12];	//key name
//  			 		UCHAR   KTnamej[12];   	//key name         //~v69zR~
    			 		UCHAR   KTnamej[20];   	//expand for UTF encode//~v69zI~
						USHORT  KTkey  [4];  		//scan(AH)/char(AL)
						                   		//lower,upper,alt,ctrl
						UCHAR   KTflag [4];     //flag for each key
#define KTCTLDUP1 		0x01			   	//duplicate when Ctrl+//~5501R~
#define KTCTLDUP2 		0x02			   	//duplicate when Ctrl+//~5501I~
#define KTCHARKEY 		0x04	//no need display on ini file   //~5506R~
#define KTSHIFTDUP		0x08	//shift+ is same value             //~v0ioI~
#define KTFIXED   		0x10	//assign to functbl is fixed       //~v0ixI~
#define KTALTDUP1 		0x20			   	//duplicate when Alt+  //~v69YI~
                                                                //~5501R~
						} KEYTBL;
//*func key cmd table  for OPT 0.1 and 0.3                         //~vb50R~
typedef struct _FKCT	{                                          //~v0ihI~
				 		void        *FKCTpft_pcmd;                 //~v0ijM~
				 		KEYTBL      *FKCTpkt;                      //~v0ijR~
#define FKCTFIDOFFS  (offsetof(FKCT,FKCTfuncid))                   //~v70YI~
#define FKCTFIDOFFSZ (sizeof(FKCT)-FKCTFIDOFFS)                    //~v70YI~
				 		USHORT 		 FKCTfuncid;	//func number  //~v0ijR~
				 		USHORT 		 FKCTcmdlen;                   //~v0ijI~
				 		USHORT 		 FKCTkey;                      //~v0ijR~
				 		UCHAR   	 FKCTshift;                    //~v0ijM~
				 		UCHAR   	 FKCTflag;                     //~v0ijM~
#define  FKCTFNONPFK    0x01        //not PFn key                  //~v0ijR~
#define  FKCTFPFT       0x02        //func assigned                //~v0ijI~
#define  FKCTFFIX       0x04        //fixed assignment             //~v0ijI~
#define  FKCTFSHIFT     0x08        //S+ is same as no shift       //~v0ijI~
#define  FKCTFSHIFTAC   0x10        //S+A or S+C                   //~vb50I~
						} FKCT,*PFKCT;                             //~v0ihI~
//#ifdef ULIB64                                                      //~v70YI~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    typedef struct _FKCT32  {                                      //~v70YI~
                            UINT4        FKCT32pft_pcmd;           //~v70YI~
                            UINT4        FKCT32pkt;                //~v70YI~
#define FKCT32FIDOFFS  (offsetof(FKCT32,FKCT32funcid))             //~v70YI~
#define FKCT32FIDOFFSZ (sizeof(FKCT32)-FKCT32FIDOFFS)              //~v70YI~
                            USHORT       FKCT32funcid;    //func number//~v70YI~
                            USHORT       FKCT32cmdlen;             //~v70YI~
                            USHORT       FKCT32key;                //~v70YI~
                            UCHAR        FKCT32shift;              //~v70YI~
                            UCHAR        FKCT32flag;               //~v70YI~
                            } FKCT32,*PFKCT32;                     //~v70YI~
#endif                                                             //~v70YI~
typedef struct _FKCTT	{                                          //~v0ijI~
//  			 		int 	FKCTTentno;	//fkct entry no        //~v0j7R~
    			 		USHORT  FKCTTentno;	//fkct entry no        //~v0j7I~
				 		PFKCT	FKCTTpfkct;	//ptr to 1st entry     //~v0ijI~
						} FKCTT,*PFKCTT;                           //~v0ijI~
typedef struct _SCKT	{      //short cut key tbl                 //~v48fI~
//  			 		int  		 SCKTcmdlen;                   //~v48pR~
    			 		USHORT  	 SCKTcmdlen;                   //~v48pI~
    			 		USHORT  	 SCKTrsv;   //padding          //~v48pI~
				 		char        *SCKTcmd;                      //~v48fI~
						} SCKT,*PSCKT;                             //~v48fI~
#define SCKTSZ (sizeof(SCKT))                                      //~v48fI~
//#ifdef ULIB64                                                      //~v70YI~//~vafmR~
#if defined(ULIB64)||defined(ULIB64X)                              //~vafmI~
    typedef struct _SCKT32  {      //short cut key tbl             //~v70YI~
                            USHORT       SCKT32cmdlen;             //~v70YI~
                            USHORT       SCKT32rsv;   //padding    //~v70YI~
                            UINT4        SCKT32cmd;                //~v70YI~
                            } SCKT32,*PSCKT32;  //4byte for compatibility to 32bit version//~v70YI~
    #define SCKT32SZ (sizeof(SCKT32))                              //~v70YI~
#endif                                                             //~v70YI~
                                                                   //~v48fI~
#define SCKTTOP   '0'                                              //~v48fI~
#define SCKTEND   'z'                                              //~v48fI~
#define SCKTALIAS  ':'  //index of alias cmd(all concatinated)     //~v67CI~
#define SCKTMAXNO  (SCKTEND-SCKTTOP+1)                             //~v48fR~
#define KBD_EXTENDED_KEY(key) (key && !(key & 0xff))      //scan+char,char=0//~vb50R~
                                                                   //~v48fI~
#ifdef  XEKBD_GLOBAL                                               //~v48fI~
  SCKT  Gkbdsckt[SCKTMAXNO];                                       //~v48fR~
#else                                                              //~v48fI~
  extern SCKT Gkbdsckt[SCKTMAXNO];                                 //~v48fR~
#endif                                                             //~v48fI~
//*FUNCTION*********************************************************
//**************************************************
int kbdinit(void);
//**************************************************               //~v09tI~
#ifdef LNX                                                         //~v69AI~
    void kbdcvkeyname2euc(void);                                   //~v69AI~
#endif                                                             //~v69AI~
//**************************************************               //~v69AI~
int kbdreinit(void);                                               //~v09tI~
//**************************************************            //~5705I~
int kbdterm(void);                                              //~5705I~
//**************************************************
int  kbdproc(void);
#define XEKBD_RC_MORE -9                                           //~v500I~
//**************************************************
int kbdchk(void);
//**************************************************
int kbdsrchkt(USHORT Pkey,KEYTBL **Ppkt);
//**************************************************            //~5501I~
//KEYTBL *kbdsrchdupkt(KEYTBL *Ppkt);                              //~v69YR~
KEYTBL *kbdsrchdupkt(KEYTBL *Ppkt,int Pshiftid);                   //~v69YI~
//**************************************************            //~5429I~
int kbdsrchktbyname(UCHAR *Pkeyname,KEYTBL **Ppkt);             //~5429I~
//**************************************************
UCHAR *kbdgetname(USHORT Pkey,int Pshift);
//**************************************************            //~5506I~
UCHAR *kbdgetchartbl(int Popt);                                 //~5506R~
//**************************************************               //~v0ihI~
int kbdgetktgrp(int Pgrp,KEYTBL **Ppkts,KEYTBL **Ppkte);           //~v0ihR~
//**************************************************               //~v0ihI~
int kbdgetfkct(PFKCTT *Ppfkctt);                                   //~v0ijR~
//**************************************************               //~v0ijI~
int kbdwfkct(FILE *Pfh);                                           //~v0ijR~
//**************************************************               //~v0ijI~
int kbdrfkct(FILE *Pfh);                                           //~v0ijR~
//**************************************************               //~v48fI~
int kbdwsckt(FILE *Pfh);                                           //~v48fI~
//**************************************************               //~v48fI~
int kbdrsckt(FILE *Pfh);                                           //~v48fI~
//**************************************************               //~v0ijI~
void kbdsetfkcmd(void);                                            //~v0ijI~
//**************************************************               //~v0ijI~
#ifndef KKK                                                        //~vb50I~
	int kbdfkctsrch(int Popt,KEYTBL *Ppkt,int Pshift);             //~vb50I~
    #define KFKCSO_SHIFTAC       0x01 //search S+A,S+C             //~vb50I~
#else                                                              //~vb50I~
int kbdfkctsrch(KEYTBL *Ppfkt,int Pshift);                         //~v0ijI~
#endif                                                             //~vb50I~
//**************************************************               //~v55cI~
                                                                   //~v589I~
//**************************************************               //~v589I~
void kbdchngstatus(int Popt);                                      //~v55cI~
//**************************************************               //~v589I~
#ifndef WXE                                                        //~v589M~
int kbdwaitkey(int Pscanchar);                                     //~v589R~
#endif                                                             //~v55cI~
//**************************************************               //~vanfI~
void kbdsetmacrocmdfilenameparm(PUCLIENTWE Ppcw,char *Ppfnm);      //~vanfI~
#ifndef KKK                                                        //~vb50I~
//**************************************************************** //~vb50I~
int xekbdchkSAC(int Popt,char *Pstr,KEYTBL **Pppkt,int *Ppshiftid);//~vb50I~
#define XEKBDCKSACO_SRCHNONSAC       0x01 //search even if not SAC //~vb50I~
//**************************************************************** //~vb50I~
int xekbdsetSAC(int Popt,int Pshiftid,KEYTBL *Ppkt,char *Pkeyname);//~vb50I~
#define XEKBDSACO_NOSTRZ       0x01 //no output strz               //~vb50R~
#define XEKBDSACO_JP           0x02 //KTnamej                      //~vb50I~
#endif                                                             //~vb50I~
//**************************************************************** //+vbD2I~
int kbdupdatesckt(int Popt);                                       //+vbD2I~
