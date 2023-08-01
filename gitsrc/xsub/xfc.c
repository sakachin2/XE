//*CID://+vas3R~:                             update#=  358;       //~vas3R~
//***********************************************************
//* XFC : compare file(win95 missing comp cmd)
//***********************************************************
#define VER "V1.27"   //version                                    //~vaa0R~//~vaj0R~
//***********************************************************
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//vaj0:180304 /CPU8 option:output triler by utf8 to show on xe result of "=" cmd with cpu8 option//~vaj0I~
//vaa1:160418 Lnx64 compiler warning                               //~vaa1I~
//vaa0:160417 Lnx compiler warning                                 //~vaa0I~
//va9E:160404 compiler warning win64                               //~va9EI~
//va9u:150529 xfc v1.25 parm count error(by xuerpck),crash when english mode recfm=v too long record//~va9uI~
//va9j:150305 xfc v1.24 add /=N (no consideration for "=")         //~va9jI~
//va9i:150303 xfc v1.24 add /=F (apply \"=" to fullpath)           //~va9iI~
//va9d:150127 xfc v1.24 support copy path specification ../=/..    //~va9dR~
//va9c:150120 xfc v1.23 margin should be adjust when /L was specified//~va9cI~//~va9dR~
//va9b:150120 xfc v1.23 (BUG)no need to consider last \n for recordmode//~va9bI~//~va9dR~
//va9a:150120 xfc v1.23 (BUG)crah when margin is out of record    //~va9aI~//~va9dR~
//va96:150106 xfc v1.22 errmsg of "too long record",add comment "try bin mode"//~va96I~
//va94:140906 xfc v1.21 bin comp,corrupted result msg              //~va94I~
//va93:140503 xfc v1.20 UD fmt input filename                      //~va93I~
//va92:140503 xfc /O option for output redirect for xe             //~va92I~
//va80:140125 xfc v1.19:lienno prefix support for xms output       //~va80I~
//va79:131201 xfc v1.18:support record mode(fix/Variable)          //~va79I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va58:111217 compiler warning,uninitialized                       //~va4eI~
//va4e:090807 xfc v1.17 chk both is missing EOF and assume SAME    //~va4eI~
//va4d:090620 xfc v1.17 print seperator line when /OB              //~va4dI~
//va4c:090604 xfc v1.17 (BUG) word option and colomn range specified case;miss to chk unmatch//~va4cI~
//va3x:080816 xfc v1.16 warning "file contains null" is isuued when \n is missing at eof//~va3xI~
//va3p:080129 xfc v1.15 english msg spell miss                     //~va3pI~
//va3d:070819 xfc:1.14 word matching with delm other than space/tab//~va3dI~
//va3b:070620 xfc:1.13 (BUG of va36) /M option ignored and (BUG) range2 shoud be column(to be compared)//~va3bR~
//va3a:070620 xfc:1.12 rc=0 when help for xe compare call          //~va3aI~
//va36:070522 xfc:new parameter "text line size" for long record over 4000//~va36I~
//va30:061227 filesize>4GB support                                 //~va30I~
//va25:050414 xfc:v2.1:comment id should be string( "|" may be or operation)//~va25I~
//va24:050414 xfc:v2.1:(BUG)"|" is ignored as comment id           //~va24I~
//va1y:041103 xfc:v1.8:ignore space/tab before line comment when -C option//~va1yR~
//*va14:031028 xfc:(BUG) abend when null file(also for /CI(ignore comment))//~va12I~
//*va12:031027 xfc:comment line input ignore option                //~va12I~
//*va11:031027 xfc:set rc=2 when comment unmatch ignored case      //~va11I~
//*va10:031027 xfc:accept comment start by ! , # and *.            //~va11R~
//031013 xfc v1.6 v153 (BUG)no bell option is /na not /nb on helpmsg//~v153I~
//031008 xfc v1.6 v152 no nomal msg output option for under xdig   //~v152I~
//031008 xfc v1.6 v151 set return code for shell use               //~v151R~
//030816 xfc v1.6 v150 no ubell option for xdig use                //~v150I~
//v149 xfc.c 030607 v1.6:(BUG)same msg for bin file compare by default text mode//~v149I~
//v148 xfc.c 030111 v1.5:(BUG)unmatch when \0a missing at eol of text file//~v147I~
//v147 xfc.c 011224 v1.4:help msg chng                             //~v147I~
//v146 xfc.c 011202 v1.4:no list option for comment line           //~v146I~
//v145 xfc.c 010128 v1.3:allow filename is on only one of two filespec parm.//~v145I~
//v144 xfc.c 010103 LINUX support(ignor \r before \n for PC file)  //~v144I~
//v143 xfc.c 010103 LINUX support(flag parm)                       //~v144R~
//v142 xfc.c 001203 LINUX support                                  //~v144R~
//xfc.c  *001202 v107 v1.3:tab display option                      //~v107I~
//xfc.c  *001105 v106 v1.3:change binary compare result line fmt   //~v106I~
//xfc.c  *990612 v105 v1.2:/c option(ignore // comment)            //~v105I~
//xfc.c  *990612 v104 /w option(word matching:ignore tab space)    //~v104I~
//xfc.c  *990425 v103 (DOS)it should be exit when storage shortage //~v103I~
//xfc.c  *990211 v102 loop when 1 line deleted after fazy chk      //~v103R~
//xfc.c  *990211 v101 no open err msg when /b                      //~v103R~
//***********************************************************

#define PGM "xfc"                                                  //~va9dR~

//**********************************************/
//*parm1 : input file1
//*parm2 : input file2
//*r.c   : none
//**********************************************/
//*
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef UNX                                                         //~v142I~
#else                                                              //~v142I~
#include <conio.h>
#endif                                                             //~v142I~

#ifdef UNX                                                         //~v142I~
#else                                                              //~v142I~
#if defined(DOS) || defined(W32)
	#include <dos.h>
    #ifdef DPMI
    	#include <errno.h>
    #endif
#else
    #define INCL_DOSFILEMGR  //DCPY_EXISTING
    #include <os2.h>
#endif
#endif                                                             //~v142I~

//*********************************************************************
#include <ulib.h>
#include <uque.h>
#include <ufile.h>
#include <ufile5.h>                                                //~va79I~
#include <uerr.h>
#include <udbcschk.h>
#include <uedit.h>
#include <ufemsg.h>                                                //~va30R~
#include <utrace.h>                                                //~va3dI~
#include <ufilew.h>                                                //~va93I~
//*********************************************************************

#if defined(DOS) && !defined(DPMI)
	#define BUFFSZ  	32760   //32k
#else
	#define BUFFSZ  	131072	//128k
#endif
//#define TXTBUFFSZ  	4000                                       //~va36R~
//#define DEFAULT_TXTBUFFSZ  	4096                                   //~va36I~//~va9uR~
#define DEFAULT_TXTBUFFSZ  	32760                                  //~va9uI~
static int TXTBUFFSZ=DEFAULT_TXTBUFFSZ;                            //~va36I~

#define DBGTRC2(cmt,prh1,prh2)          \
		{                               \
        	if (prh1)					\
				printf("%-8s (%7d)=%s",cmt,prh1->URHlineno,&prh1->URHdata);\
        	if (prh2)                                                      \
				printf("         (%7d)=%s",prh2->URHlineno,&prh2->URHdata);\
        }                                                          //~v146I~
//*********************************************************************
#ifdef UNX                                                         //~v143I~
    #define RPREFIX  ':'                                           //~v143I~
#else                                                              //~v143I~
    #define RPREFIX  '/'      //range parm seperator               //~v143I~
#endif                                                             //~v143I~
                                                                   //~v143I~
#define MAXCTR 10
#define MAXRATE    50  //assume updated pair if match is over this percent
#define ULMAX  0xffffffff
#define PRINT_BOTH     'B'
#define PRINT_DIFF     'D'
#define PRINT_MERGE    'M'
#define PRINT_FULL     'F'                                         //~va4dR~
#define LINEHDRSZ       18
//*********************
typedef struct _URECH {
						UQUEE           URHqe;
						struct _URECH  *URHprev;
						struct _URECH  *URHnext;
						struct _URECH  *URHpair;
						struct _URECH  *URHlifo;
						long            URHlineno;
						long            URHprefixlineno;           //~va80I~
						int             URHdlen;
						int             URHdlennet; //compare len considerating comment//~v105I~
                        int             URHwordno;  //words string //~v104I~
                        int             URHwordtblen;//words string len//~v105R~
                        int             URHwordtblennet;//words string len except cmt//~v105I~
                        UCHAR          *URHwordtb;  //words string //~v104I~
                        USHORT         *URHwordoffstb;  //words string//~v104I~
//  					UCHAR           URHchar[3];                //~v146R~
    					UCHAR           URHchar[4];                //~v146I~
#define                 URHflag  URHchar[0]              //for boundary//~v105I~
#define URHFSAME        'S'             //matched
#define URHFISRT        'I'             //inserted
#define URHFDLET        'D'             //deleted
#define URHFREPL        'R'             //updated
#define                 URHflag2 URHchar[1]              //for boundary//~v105I~
#define URHF2SAME       'S'             //completely same          //~v105I~
#define URHF2SAMEC      'C'             //except comment           //~v105I~
#define URHF2SAMEW      'W'             //word match               //~v105I~
#define URHF2SAMEWC     'w'             //word match  except comment//~v105I~
//#define               URHdata  URHchar[2]              //for boundary//~v146R~
#define                 URHflag3 URHchar[2]  //flags               //~v146I~
#define URHF3NULLCMT    0x01            //null or comment line     //~v146I~
#define                 URHdata  URHchar[3]              //for boundary//~v146I~
					  }	URECH;
typedef URECH  *PURECH;
#define URECHSZ (sizeof(URECH))
//*********************

static char Sfnm1[_MAX_PATH],Sfnm2[_MAX_PATH];
static int Smaxctr=MAXCTR;
#ifdef UNX                                                         //~v144I~
	static int Spcfile;      //ignore \r before \n                 //~v144I~
#endif                                                             //~v144I~
static int Snobellsw=0;                                            //~v150I~
static int Snookmsg=0;                                             //~v152I~
static int Sdbcssw;
static int Sbinsw,Sostyle=PRINT_DIFF;
static int Sostyle2=0;                                             //~va4dI~
static long Sisrtctr,Sreplctr,Sdletctr,Ssamectr;
static long Sisrtctrprint=0,Sreplctrprint=0,Sdletctrprint=0;       //~va11I~
static long Sinp1ctr,Sinp2ctr;
//static int Smargin1,Smargin2,Smarginw=TXTBUFFSZ-1; 		//binary compare//~va36R~
static int Smargin1,Smargin2,Smarginw=DEFAULT_TXTBUFFSZ-1; 		//binary compare//~va36I~
static ULONG Srange1s,Srange1e=ULMAX,Srange2s,Srange2e=ULMAX;
static	char Spgmver[16];
static	char *Stxtbuff;
static PURECH Srhlifoq1,Srhlifoq2;
static int Slvl;
static int Scriteria=MAXRATE;
static int Slogicerr;                                              //~v102I~
static int Swordmatchingsw;		//word matcing(count rate by wordno matched)//~v104I~
static int Swordpsw;			//word matcing(count rate by wordno matched)//~v105I~
static int Sworddelmsw; 		//word matcing(ignore space/tab around delm)//~va3dI~
static char *Sworddelmtb=",()*&";	//word matcing(default delm tbl)//~va3dR~
static int Scmntsw;				//ignore // comment                //~v105I~
static int Scmntid=0;   		//comment start char(default is C++ //)//~va10I~
static char *Scmntidstr=0; 	//comment string                       //~va25R~
static int Scmntpsw;			//ignore // comment but print      //~v105I~
static int Scmntnoprsw=0;			//no print comment line        //~v146I~
static int Stabdisp='.';		//tab display char default         //~v107I~
static int Sbinchksw=0;                                            //~v149I~
static int Seofchksw=0;                                            //~va4eI~
static int Sendoffsp1=0,Sendoffsp2=0;	//endoffset parm specified sw//~va30I~
static int Svfmt,Slrecl,Sbuffsz,Srecordmode;                       //~va79R~
static int Slinenodigit[2];                                        //~va80I~
static FILE *Sfhout;                                               //~va92I~
//*********************************
int bincomp(void);
int txtcomp(void);
long getirec(char *Pfnm,FILE *Pfh,char *Pbuff,PUQUEH Ppqh,ULONG Pranges,ULONG Prangee);
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw);
UINT getinput(char *Pfnm,FILE *Pfh,char *Pbuff,UINT Preqsz);
void setnetlen(PURECH Pprh);                                       //~v105R~
void wordtbgen(PURECH Pprh);                                       //~v104I~
//void lvl0matching(PUQUEH Ppqh1,PUQUEH Ppqh2);                    //~va14R~
int lvl0matching(PUQUEH Ppqh1,PUQUEH Ppqh2);                       //~va14R~
void lvl2matching(PURECH Pprh1,PURECH Pprh2,PURECH *Ppprh1,PURECH *Ppprh2);
int fazywordmatching(PURECH Pprh1,PURECH Pprh2);                   //~v104I~
int fazymatching(PURECH Pprh1,PURECH Pprh2,PURECH *Ppprh2m);
int nsntmatching(char *Pdata1,char *Pdata2,int Pdlen1,int Pdlen2);
void pushpair(PURECH Pprh1,PURECH Pprh2);
int  poppair(PURECH *Ppprh1,PURECH *Ppprh2);
long getmax(PURECH Pprh1,PURECH Pprh2,PURECH *Ppprh1m,PURECH *Ppprh2m);
long chkmax(PURECH Pprh1,PURECH Pprh2,PURECH *Ppprh1n,PURECH *Ppprh2m);
int linecompare(PURECH Pprh1,PURECH Pprh2);                        //~v105R~
void setupdate(PUQUEH Ppqh1,PUQUEH Ppqh2);
void resultprint(PUQUEH Ppqh1,PUQUEH Ppqh2);
void printsub(PURECH Pprh,int Pfilesw);
void markline(PURECH Pprh);
void putline(char *Pbuff,int Plen);
ULONG binstartpos(char *Pfnm,FILE *Pfh,FILEFINDBUF3 *Pfstat3,ULONG Poffs);
void parmchk(int parmc,char *parmp[]);
//void getrange(char *Pfnm,ULONG *Ppranges,ULONG *Ppramgee);       //~va30R~
int getrange(char *Pfnm,ULONG *Ppranges,ULONG *Ppramgee);          //~va30I~
void optionerr(char *Ptype,char* Pvalue);
void help(void);
void getrecordformat(char *Pfmt);                                  //~va79I~
FILE *openfilefv(char *Pfnm);                                      //~va79I~
int readrecfv(char *Ppfnm,FILE *Ppfh,char *Pbuff,int Pline);       //~va79I~
long getirecfv(char *Pfnm,FILE *Pfh,char *Pbuff,PUQUEH Ppqh,ULONG Pranges,ULONG Prangee);//~va79I~
int chksamepathparm(char *Pfnm,char *Prangeparm);                  //~va9dR~
//*********************************************************************
//* return 0:fully equall
//*        1:textcomp for binfile                                  //~v151R~
//*        3:unmatch exist                                         //~v151I~
//*        4:encountered error condition
//*********************************************************************
int main(int parmc,char *parmp[])
{
	int rc;
//**********************
#ifdef W32UNICODE                                                  //~va93I~
    SET_UDMODE();  //filename by UD format                         //~va93I~
#endif                                                             //~va93I~
	sprintf(Spgmver,"%s:%s(%c): ",PGM,VER,OSTYPE);
	uerrmsg_init(Spgmver,stdout,0);//msg to stdout
	uerrexit_init(Spgmver,stdout,0,0,0);//stdout only,no pathmsg
//  uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit       //~v150R~
    uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit       //~va14M~
    UTRACE_INIT("utrace.xfc",1);                                   //~va93I~
    Sdbcssw=udbcschkcp();
    Smarginw=TXTBUFFSZ-1;                                          //~va3bR~
	parmchk(parmc,parmp);
//  Smarginw=TXTBUFFSZ-1;   	//binary compare                   //~va3bR~
//  if (!Snobellsw)                                                //~va14R~
//  	uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit   //~va14R~
    if (!Sdbcssw)
		uerrmsg_init(Spgmver,stdout,UERR_FORCE_ENGLISH);
//*****************************
	if (Sbinsw)
    	rc=bincomp();
    else
    	rc=txtcomp();
  if (!Snookmsg || rc)                                             //~v152I~
	uerrmsg("===Process completed===",
			"===処理完了===");
	ARMXSUB_CLOSE(PGM);	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//+vas3I~
	return rc;
}//main

//*********************************************************************
//* return 0:fully equall
//*        1:unmatch exist
//*        4:encountered error condition
//*********************************************************************
int txtcomp(void)
{
	FILE *fh;
    UQUEH qh1,qh2;
    ULONG r1s,r1e,r2s,r2e;
    int margin1,margin2;
    int nullsw=0;                                                  //~va14R~
    int rc;                                                        //~v151I~
//*****************************
//  if (!(Stxtbuff=malloc(TXTBUFFSZ+LINEHDRSZ+1)))	//for line hdr to print//~v149R~
   if (Slrecl)                                                     //~va79I~
   {                                                               //~va79I~
    Sbuffsz=Slrecl;                                                //~va79I~
//  if (!(Stxtbuff=malloc((UINT)(Slrecl+LINEHDRSZ+1+1))))	//for line hdr to print//~va79I~//~va9cR~
    if (!(Stxtbuff=malloc((UINT)(Slrecl+LINEHDRSZ+1+1+8))))	//for line hdr to print//~va9cI~
		uerrexit("malloc failed for text i/o buff,size=%d)",0,Slrecl);//~va79I~
   }                                                               //~va79I~
   else                                                            //~va79I~
   {                                                               //~va79I~
    Sbuffsz=TXTBUFFSZ;                                             //~va79R~
//  if (!(Stxtbuff=malloc((UINT)(TXTBUFFSZ+LINEHDRSZ+1+1))))	//for line hdr to print//~va36R~//~va9cR~
    if (!(Stxtbuff=malloc((UINT)(TXTBUFFSZ+LINEHDRSZ+1+1+8))))	//for line hdr to print//~va9cI~
		uerrexit("malloc failed for text i/o buff,size=%d)",0,TXTBUFFSZ);
   }                                                               //~va79I~
  if (Slrecl || Svfmt)                                             //~va79I~
  { 		                                                       //~va79I~
  	Srecordmode=1;                                                 //~va79I~
//*file1                                                           //~va79I~
	fh=openfilefv(Sfnm1);	//exit when open faile                 //~va79I~
	Sinp1ctr=getirecfv(Sfnm1,fh,Stxtbuff,&qh1,Srange1s,Srange1e);  //~va79I~
    fclose(fh);                                                    //~va79I~
//*file1                                                           //~va79I~
	fh=openfilefv(Sfnm2);	//exit when open faile                 //~va79I~
	Sinp2ctr=getirecfv(Sfnm2,fh,Stxtbuff,&qh2,Srange2s,Srange2e);  //~va79I~
    fclose(fh);                                                    //~va79I~
  }                                                                //~va79I~
  else                                                             //~va79I~
  {                                                                //~va79I~
//*file1
	fh=openfile(Sfnm1,"r",0);	//exit when open faile
	Sinp1ctr=getirec(Sfnm1,fh,Stxtbuff,&qh1,Srange1s,Srange1e);
    fclose(fh);
//*file1
	fh=openfile(Sfnm2,"r",0);	//exit when open faile
	Sinp2ctr=getirec(Sfnm2,fh,Stxtbuff,&qh2,Srange2s,Srange2e);
    fclose(fh);
  }                                                                //~va79I~

    lvl0matching(&qh1,&qh2);
    setupdate(&qh1,&qh2);
    resultprint(&qh1,&qh2);
    if (!(r1s=Srange1s))
    	r1s=1;
    if (!(r1e=Srange1e)||r1e==ULMAX)
    	r1e=(ULONG)Sinp1ctr;
    if (!(r2s=Srange2s))
    	r2s=1;
    if (!(r2e=Srange2e)||r2e==ULMAX)
    	r2e=(ULONG)Sinp2ctr;
    if (Smargin1 || Smargin2)
    {
        if (!(margin1=Smargin1))
        	margin1=1;
        else
        	margin1++;
//      if (margin2=Smargin2,margin2)                              //~va3bR~
//      	margin2++;                                             //~va3bR~
        margin2=Smargin2;                                          //~va3bI~
    }
    else
    	margin1=margin2=0;
//  if (!Snookmsg                                                  //~va11R~
//  ||   Sdletctr||Sisrtctr||Sreplctr)                             //~va11R~
//    printf("Text file compare: %s (%ld-%ld/%ld) and %s (%ld-%ld/%ld)\n//~va14R~
//with margin(%d-%d)\n",                                           //~va11R~
//                Sfnm1,r1s,r1e,Sinp1ctr,                          //~va11R~
//                Sfnm2,r2s,r2e,Sinp2ctr,                          //~va11R~
//                margin1,margin2);                                //~va11R~
    if (Sdletctr||Sisrtctr||Sreplctr)
    {
//		printf("UNMATCH found(same=%ld, deleted=%ld, inserted=%ld, updated=%ld).\n",//~va92R~
  		fprintf(Sfhout,"UNMATCH found(same=%ld, deleted=%ld, inserted=%ld, updated=%ld).\n",//~va92I~
        		Ssamectr,Sdletctr,Sisrtctr,Sreplctr);
    	if (!Sdletctrprint && !Sisrtctrprint && !Sreplctrprint)    //~va11R~
        	rc=2;                                                  //~va11R~
        else                                                       //~va11I~
        {                                                          //~va11I~
      if (!Snobellsw)                                              //~v150I~
		ubell();
        rc=3;                                                      //~v151R~
        }                                                          //~va11I~
	}
    else
    {                                                              //~v151I~
	  if (!Snookmsg)                                               //~v152R~
      {                                                            //~va14R~
       if (!nullsw)                                                //~va14R~
//  	printf("===== SAME is both =====\n");                      //~va30R~
//    	printf("===== SAME are both files =====\n");               //~va30I~//~va92R~
      	fprintf(Sfhout,"===== SAME are both files =====\n");       //~va92I~
      }                                                            //~va14R~
        rc=0;                                                      //~v151I~
    }                                                              //~v151I~
    if (Seofchksw!=0 && Seofchksw!=3)                              //~va4eI~
        Sbinchksw=1;                                               //~va4eI~
    if (Sbinchksw)                                                 //~v149I~
    {                                                              //~v151I~
        rc=1;                                                      //~v151I~
//  	printf("Warning:File contains null(x00) value!!, use %cb option\n",CMDFLAG_PREFIX);//~va3xR~
//  	printf("Warning:File contains null(x00) value, or EndOfLine(\\n) is missing at EOF!! use %cb option\n",CMDFLAG_PREFIX);//~va3xI~//~va92R~
    	fprintf(Sfhout,"Warning:File contains null(x00) value, or EndOfLine(\\n) is missing at EOF!! use %cb option\n",CMDFLAG_PREFIX);//~va92I~
    }                                                              //~v151I~
  	if (!Snookmsg                                                  //~va11I~
  	||   Sdletctr||Sisrtctr||Sreplctr)                             //~va11I~
//  	printf("Text file compare: %s (%ld-%ld/%ld) and %s (%ld-%ld/%ld)\n//~va92R~
    	uerrmsg("Text file compare: %s (%ld-%ld/%ld) and %s (%ld-%ld/%ld)\n\
with margin(%d-%d);rc=%d\n",                                       //~va11I~
				0,                                                 //~va93I~
		        Sfnm1,r1s,r1e,Sinp1ctr,                            //~va11I~
        		Sfnm2,r2s,r2e,Sinp2ctr,                            //~va11I~
        		margin1,margin2,rc);                               //~va11I~
    if (Slogicerr)                                                 //~v102I~
        uerrexit("Internal logic err;check \"?==?\",\"?=!?\"",0);  //~v102R~
//  return 0;                                                      //~v151R~
    return rc;                                                     //~v151I~
}//txtcomp
//*********************************************************************
//* read input file then enq all record(RecordMode)                //~va79R~
//*********************************************************************
long getirecfv(char *Pfnm,FILE *Pfh,char *Pbuff,PUQUEH Ppqh,ULONG Pranges,ULONG Prangee)//~va79R~
{
    int reclen;                                                    //~va79R~
    long recno=0,enqctr=0;
    PURECH prh,prhprev;
    char rec[16];
    int eofsw=0;                                                   //~v149R~
//*****************************
    memset(Ppqh,0,UQUEHSZ);
    prhprev=0;
    for(;;)
    {
    	if (eofsw)                                                 //~v149I~
        	break;                                                 //~v149I~
        recno++;
//      memset(Pbuff,0,Sbuffsz+1);	//required when EOL missing//~va4eI~//~va79R~//~vaa0R~
        memset(Pbuff,0,(size_t)Sbuffsz+1);	//required when EOL missing//~vaa0I~
//  	if ((reclen=readrecfv(Pfnm,Pfh,Pbuff,recno))<0)            //~va79R~//~vaa1R~
    	if ((reclen=readrecfv(Pfnm,Pfh,Pbuff,(int)recno))<0)       //~vaa1I~
        	break;                                                 //~va79I~
        if (!Pranges
	    ||  ((ULONG)recno>=Pranges && (ULONG)recno<=Prangee))
        {
        	enqctr++;
//          prh=malloc((UINT)(reclen+URECHSZ+1));                  //~vaa0R~
            prh=malloc(((size_t)reclen+URECHSZ+1));                //~vaa0I~
            if (!prh)
                uerrexit("storage shortage at %ld'th line of %s",0,//~v103I~
                                recno,Pfnm);
            memset(prh,0,URECHSZ);
            if (prhprev)
            	prhprev->URHnext=prh;
			prh->URHprev=prhprev;
            memcpy(&prh->URHdata,Pbuff,(UINT)reclen);
            *(&prh->URHdata+reclen)=0;			//string term
            prh->URHdlen=reclen;
            prh->URHlineno=recno;
                                                                   //~v105I~
            setnetlen(prh);                                        //~v105R~
          if (Scmntsw==2        //ignore comment record            //~va12R~
          &&  prh->URHflag3==URHF3NULLCMT)                         //~va12I~
          {                                                        //~va12I~
            if (prhprev)                                           //~va12I~
            	prhprev->URHnext=0;                                //~va12I~
          	free(prh);                                             //~va12R~
          }                                                        //~va12I~
          else                                                     //~va12I~
          {                                                        //~va12I~
            wordtbgen(prh);                //create word tbl       //~v104R~
                                                                   //~v104I~
            UENQ(UQUE_END,Ppqh,prh);       //fifo que
            prhprev=prh;                    //prev of next
          }                                                        //~va12I~
        }
	}//until eof
    if (!enqctr)
    {
        if (Prangee==ULMAX)
	        *rec=0;
        else
	        sprintf(rec,"%ld",Prangee);
    	uerrmsg("no record selected from %s of the range %ld-%s",0,//~va12I~
					Pfnm,Pranges,rec);
    }
	return recno-1;
}//getfvrec                                                        //~va79R~
//*********************************************************************
//* read input file then enq all record
//*parm1:filename for errmsg
//*parm2:FILE*
//*parm3:buff
//*parm4:qcb
//*parm5:input line range start
//*parm6:input line range end
//*ret  :rc
//*********************************************************************
long getirec(char *Pfnm,FILE *Pfh,char *Pbuff,PUQUEH Ppqh,ULONG Pranges,ULONG Prangee)
{
    int rc,reclen;
    long recno=0,enqctr=0;
    PURECH prh,prhprev;
    char *pc;
    char rec[16];
    int eofsw=0;                                                   //~v149R~
//*****************************
    memset(Ppqh,0,UQUEHSZ);
    prhprev=0;
    for(;;)
    {
    	if (eofsw)                                                 //~v149I~
        	break;                                                 //~v149I~
        recno++;
//      memset(Pbuff,0,TXTBUFFSZ+1);	//clear for \n search;no need fgets insert null after (n-1) byte read//~va36R~
//      memset(Pbuff,0,TXTBUFFSZ+1);	//required when EOL missing//~va4eI~//~vaa0R~
        memset(Pbuff,0,(size_t)TXTBUFFSZ+1);	//required when EOL missing//~vaa0I~
    	if (!fgets(Pbuff,TXTBUFFSZ,Pfh))
        {
        	rc=errno;
        	if (ferror(Pfh))
            	uerrexit("%s read error at %ld'th line,rc=%d",0,
                			Pfnm,recno,rc);
			break;			//eof
        }
        if (!Pranges
	    ||  ((ULONG)recno>=Pranges && (ULONG)recno<=Prangee))
        {
        	enqctr++;
//          pc=memchr(Pbuff,'\n',TXTBUFFSZ);                       //~v148R~
//          pc=strchr(Pbuff,'\n');                                 //~v149R~
            pc=memchr(Pbuff,'\n',(UINT)(TXTBUFFSZ));               //~va36R~
                                                                   //~v148R~
            if (!pc)
            {                                                      //~v149I~
                if (feof(Pfh))                                     //~v149R~
                {                                                  //~v149R~
                    pc=Pbuff+strlen(Pbuff);                        //~v149R~
                    *pc='\n';                                      //~v149R~
                    eofsw=1;            //eof                      //~v149R~
                    if (Pfnm==Sfnm1)                               //~va4eI~
                        Seofchksw|=1;     //file1 missing EOL at EOF//~va4eI~
                    else                                           //~va4eI~
                        Seofchksw|=2;     //file1 missing EOL at EOF//~va4eI~
                }                                                  //~v149R~
                else                                               //~v149I~
//              uerrexit("too long line(>%d) detected at %ld'th line of %s",0,//~va36R~
//                              TXTBUFFSZ,recno,Pfnm);             //~va36I~
//              uerrexit("too long line(>%d) detected at %ld'th line of %s, Specify %cL option.",0,//~va96R~
//                              TXTBUFFSZ,recno,Pfnm,CMDFLAG_PREFIX);//~va96R~
                uerrexit("too long line(>%d) detected at %ld'th line of %s, Specify %cL option. Or use %cB(binary mode compare).",//~va96R~
                         "行長が長すぎます(>%d) ( %ld 行目:%s ), %cL を指定するか %cB(バイナリー比較)を指定してください",//~va96R~
                                TXTBUFFSZ,recno,Pfnm,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va96I~
            }                                                      //~v149M~
//          reclen=(int)((ULONG)pc-(ULONG)Pbuff+1);    //include \n//~v104R~//~va66R~
            reclen=(int)((ULPTR)pc-(ULPTR)Pbuff+1);    //include \n//~va66I~
            if (pc)                                                //~v149I~
            	if (!Sbinchksw)                                    //~v149I~
                	if (reclen!=(int)strlen(Pbuff))                //~v149R~
                    	Sbinchksw=1;                               //~v149I~
#ifdef UNX                                                         //~v144I~
            if (Spcfile)    //ignore \r before \n                  //~v144I~
                if (pc!=Pbuff && *(pc-1)=='\r')                    //~v144I~
                {                                                  //~v144I~
                    reclen--;                                      //~v144I~
                    *(pc-1)='\n';//ignore \r                       //~v144I~
                }                                                  //~v144I~
#endif                                                             //~v144I~
//          prh=malloc((UINT)(reclen+URECHSZ+1));                  //~vaa0R~
            prh=malloc(((size_t)reclen+URECHSZ+1));                //~vaa0I~
            if (!prh)
//              uerrmsg("storage shortage at %ld'th line of %s",0, //~v103R~
                uerrexit("storage shortage at %ld'th line of %s",0,//~v103I~
                                recno,Pfnm);
            memset(prh,0,URECHSZ);
            if (prhprev)
            	prhprev->URHnext=prh;
			prh->URHprev=prhprev;
          if (Slinenodigit[Pfnm==Sfnm2])                           //~va80I~
          {                                                        //~va80I~
          	int digit,lineno;                                      //~va80I~
            digit=Slinenodigit[Pfnm==Sfnm2];                       //~va80I~
            lineno=uatoin(Pbuff,digit);                            //~va80R~
            if (reclen>digit)                                      //~va80I~
            	reclen-=digit;                                     //~va80I~
            else                                                   //~va80I~
            	reclen=0;                                          //~va80I~
            memcpy(&prh->URHdata,Pbuff+digit,(UINT)reclen);        //~va80I~
            prh->URHprefixlineno=lineno;                           //~va80I~
//          printf("prefix lineno=%d for lineno=%d\n",lineno,(int)recno);//~va80R~
          }                                                        //~va80I~
          else                                                     //~va80I~
          {                                                        //~va80I~
            memcpy(&prh->URHdata,Pbuff,(UINT)reclen);
          }                                                        //~va80I~
            *(&prh->URHdata+reclen)=0;			//string term
            prh->URHdlen=reclen;
            prh->URHlineno=recno;
                                                                   //~v105I~
            setnetlen(prh);                                        //~v105R~
          if (Scmntsw==2        //ignore comment record            //~va12R~
          &&  prh->URHflag3==URHF3NULLCMT)                         //~va12I~
          {                                                        //~va12I~
            if (prhprev)                                           //~va12I~
            	prhprev->URHnext=0;                                //~va12I~
          	free(prh);                                             //~va12R~
          }                                                        //~va12I~
          else                                                     //~va12I~
          {                                                        //~va12I~
            wordtbgen(prh);                //create word tbl       //~v104R~
                                                                   //~v104I~
            UENQ(UQUE_END,Ppqh,prh);       //fifo que
            prhprev=prh;                    //prev of next
//printf("record=%s",&prh->URHdata);                               //~v104R~
          }                                                        //~va12I~
        }
	}//until eof
    if (!enqctr)
    {
        if (Prangee==ULMAX)
	        *rec=0;
        else
	        sprintf(rec,"%ld",Prangee);
//  	uerrexit("no record selected from %s of the range %ld-%s",0,//~va12R~
    	uerrmsg("no record selected from %s of the range %ld-%s",0,//~va12I~
					Pfnm,Pranges,rec);
    }
//printf("recno=%d\n",recno-1);                                    //~v104R~
	return recno-1;
}//getirec
//*********************************************************************//~v105I~
//*set matcing pair                                                //~v105I~
//*parm1:RECH                                                      //~v105I~
//*ret  :rc                                                        //~v105I~
//*********************************************************************//~v105I~
void setnetlen(PURECH Pprh)                                        //~v105R~
{                                                                  //~v105I~
	UCHAR *data,*datae,*data0,ch,*cmpos=0;                         //~v105R~
	UCHAR *pc;                                                     //~va1yI~
    int    dlen,quatesw=0,spacecnt=0,datacnt;                      //~v105R~
    int   cmntid;                                                  //~va10I~
    int   cmntidstrlen;                                            //~va25I~
//*****************************                                    //~v105I~
 	data0=data=&Pprh->URHdata;                                     //~v105I~
  if (Srecordmode)                                                 //~va9bI~
    dlen=Pprh->URHdlen;		//exclude \n                           //~va9bI~
  else                                                             //~va9bI~
    dlen=Pprh->URHdlen-1;		//exclude \n                       //~v104R~
    Pprh->URHdlennet=dlen;                                         //~v105I~
    if (!Scmntsw)                                                  //~v105R~
    	return;                                                    //~v105I~
    if (Scmntidstr)                                                //~va25R~
	    cmntidstrlen=(int)strlen(Scmntidstr);                      //~va25R~
    else                                                           //~va25I~
    	cmntidstrlen=0;                                            //~va25R~
    if (cmntid=Scmntid,!cmntid)                                    //~va10I~
    	cmntid='/';                                                //~va10I~
                                                                   //~v105I~
    for (datae=data+dlen;data<datae;data++) //search // cmnt       //~v105R~
    {                                                              //~v105R~
        ch=*data;                                                  //~v105R~
        switch (ch)                                                //~v105R~
        {                                                          //~v105R~
        case '\\':                                                 //~v105R~
            data++;                                                //~v105R~
            break;                                                 //~v105R~
        case '\'':                                                 //~v105R~
        case '\"':                                                 //~v105R~
            if (quatesw==ch)                                       //~v105R~
                quatesw=0;                                         //~v105R~
            else                                                   //~v105R~
                if (!quatesw)                                      //~v105R~
                    quatesw=ch;                                    //~v105R~
            break;                                                 //~v105R~
        case '/':                                                  //~v105R~
          	if (cmntid!='/')	//cmt is not C++ style             //~va10I~
            	break;                                             //~va10I~
            if (quatesw)                                           //~v105R~
                break;                                             //~v105R~
            data++;                                                //~v105R~
            if (data<datae)                                        //~v105R~
                if (*data=='/')                                    //~v105R~
                    cmpos=data-1;                                  //~v105R~
            break;                                                 //~v105R~
        case '\t':                                                 //~v105I~
        case ' ':                                                  //~v105I~
        	spacecnt++;                                            //~v105I~
            break;                                                 //~va14I~
        default:                                                   //~va10I~
        	if (ch==cmntid)                                        //~va10I~
            {                                                      //~va10I~
                if (!quatesw)                                      //~va10I~
                {                                                  //~va25I~
                  if (cmntidstrlen==1)                             //~va25I~
                  	cmpos=data;                                    //~va10I~
                  else                                             //~va25I~
                  if (cmntidstrlen>1                               //~va25R~
			      &&  data+cmntidstrlen<=datae                     //~va25M~
                  &&  !memcmp(data,Scmntidstr,(UINT)cmntidstrlen)) //~va25M~
                  	cmpos=data;                                    //~va25I~
                }                                                  //~va25I~
            }                                                      //~va10I~
        }                                                          //~v105R~
        if (cmpos)                                                 //~v105R~
            break;                                                 //~v105R~
    }                                                              //~v105R~
    if (cmpos)	//comment found                                    //~v105R~
    {                                                              //~v105I~
//      datacnt=(int)((ULONG)cmpos-(ULONG)data0);                  //~v105I~//~va66R~
        datacnt=(int)((ULPTR)cmpos-(ULPTR)data0);                  //~va66I~
        if (datacnt!=spacecnt)                                     //~v105I~
        {                                                          //~va1yI~
            for (pc=cmpos-1;pc>=data0;pc--)                        //~va1yI~
                if (*pc!=' ' && *pc!='\t')                         //~va1yI~
                    break;                                         //~va1yI~
//        	datacnt=(int)((ULONG)pc-(ULONG)data0)+1;               //~va1yI~//~va66R~
        	datacnt=(int)((ULPTR)pc-(ULPTR)data0)+1;               //~va66I~
        	Pprh->URHdlennet=datacnt;                              //~v105R~
        }                                                          //~va1yI~
        else                                                       //~v146I~
			Pprh->URHflag3=URHF3NULLCMT;//null or comment line     //~v146R~
	}                                                               //~v105I~
    else                                                           //~va12I~
        if (dlen==spacecnt)                                        //~va12I~
			Pprh->URHflag3=URHF3NULLCMT;//null or comment line     //~va12I~
//printf("cmpos=%s,netlen=%d,len=%d\n",cmpos,Pprh->URHdlennet,Pprh->URHdlen);//~v104R~
	return;                                                        //~v105I~
}//setnetlen                                                       //~v105R~
//*********************************************************************//~v104I~
//*set matching pair                                               //~va36R~
//*parm1:RECH                                                      //~v104I~
//*ret  :rc                                                        //~v104I~
//*********************************************************************//~v104I~
void wordtbgen(PURECH Pprh)                                        //~v104I~
{                                                                  //~v104I~
	UCHAR *data,*datas,*datae,*datac,*wordtb,*wordtb0,ch;          //~v105R~
    int    dlen,stsw,wordno,wordtblen,wordtblennet;                //~v105R~
    int delmsw=0;                                                  //~va3dI~
    USHORT *pus;                                                   //~v104I~
//*****************************                                    //~v104I~
 	datas=&Pprh->URHdata+Smargin1;                                 //~v104R~
    if ((dlen=Pprh->URHdlen-Smargin1)<=0)                          //~v105R~
    	return;			//no data in margin                        //~v104I~
    if (dlen>Smarginw)                                             //~v104I~
    	dlen=Smarginw;                                             //~v104I~
	datae=datas+dlen;                                              //~v104I~
    datac=datas+Pprh->URHdlennet-Smargin1;  //comment pos          //~v105I~
    if (datac<datas)                                               //~v105I~
    	datac=datas;                                               //~v105I~
    wordtblennet=-1;    //unset wordtblennet                       //~va4cR~
    for (data=datas,stsw=1,wordno=0,wordtblen=0;data<datae;data++) //~v104I~
    {                                                              //~v104I~
    	if (data==datac)                                           //~v105I~
        	wordtblennet=wordtblen;                                //~v105I~
    	ch=*data;                                                  //~v104I~
        if (ch==' '||ch=='\t')                                     //~v104I~
        	if (stsw)	//already in space/tab                     //~v104I~
            	continue;                                          //~v104I~
            else                                                   //~va3dI~
        	if (delmsw)	//space after delm                         //~va3dI~
            	continue;    //ignore                              //~va3dI~
            else                                                   //~v104I~
            	stsw=1;                                            //~v104I~
        else                                                       //~v104I~
        {                                                          //~v104I~
          	if (Sworddelmsw && strchr(Sworddelmtb,ch))	//delm found//~va3dI~
            	delmsw=1;                                          //~va3dI~
          	else                                                   //~va3dI~
//      	if (stsw)	//1st cahr of word                         //~va3dR~
        	if (stsw||delmsw)	//1st char after space or delm     //~va3dI~
            {                                                      //~v104I~
            	wordno++;                                          //~v104I~
                stsw=0;                                            //~v104I~
                delmsw=0;                                          //~va3dI~
                if (wordtblen)		//not 1st word                 //~v104I~
                	wordtblen++;    //intermidiate space           //~v104I~
			}                                                      //~v104I~
            wordtblen++;                                           //~v104I~
		}                                                          //~v104I~
	}                                                              //~v104I~
    if (wordtblennet<0)	//comment is not detected(column range specified case)//~va4cI~
    	wordtblennet=wordtblen;                                    //~va4cI~
//*malloc word tbl		wordlen,wordlen,...,wordtbl                //~v104I~
    wordtb0=malloc((UINT)(((wordno+1)<<1)+wordtblen+1));	//each word len by short//~v104R~
    if (!wordtb0)                                                  //~v104I~
    	uerrexit("storage shortage at for word tbl of lineno %ld",0,//~v104I~
        			Pprh->URHlineno);                              //~v104I~
//  pus=(USHORT*)(ULONG)wordtb0;                                   //~v104I~//~va66R~
    pus=(USHORT*)(ULPTR)wordtb0;                                   //~va66I~
//  wordtb=(UCHAR*)(ULONG)(pus+(wordno+1));                        //~v104R~//~va66R~
    wordtb=(UCHAR*)(ULPTR)(pus+(wordno+1));                        //~va66I~
    *(wordtb+wordtblen++)=0;	//last word terminator             //~v104I~
    *(pus+wordno)=(USHORT)wordtblen;	//to calc len              //~v104R~
                                                                   //~v104I~
	Pprh->URHwordno=wordno;                                        //~v104I~
	Pprh->URHwordoffstb=pus;                                       //~v104I~
	Pprh->URHwordtb=wordtb;                                        //~v104I~
	Pprh->URHwordtblen=wordtblen;                                  //~v105R~
	Pprh->URHwordtblennet=wordtblennet;                            //~v105I~
//printf("wordno=%d,wordtblen=%d,wordtblnetlen=%d\n",wordno,wordtblen,wordtblennet);//~v105R~
                                                                   //~v104I~
UTRACED("wordtbl in",datas,(int)((ULPTR)datae-(ULPTR)datas));	//each word len by short//~va3dI~//~va66R~//~va9ER~
	delmsw=0;                                                      //~va3dI~
    for (data=datas,stsw=1,wordtblen=0;data<datae;data++)          //~v104I~
    {                                                              //~v104I~
    	ch=*data;                                                  //~v104I~
        if (ch==' '||ch=='\t')                                     //~v104I~
        	if (stsw)	//already in space/tab                     //~v104I~
            	continue;                                          //~v104I~
            else                                                   //~va3dI~
        	if (delmsw)	//space after any delimiter                //~va3dI~
            	continue;                                          //~va3dI~
            else                                                   //~v104I~
            	stsw=1;                                            //~v104I~
        else                                                       //~v104I~
        {                                                          //~v104I~
          	if (Sworddelmsw && strchr(Sworddelmtb,ch))	//delm found//~va3dI~
            	delmsw=1;                                          //~va3dI~
          	else                                                   //~va3dI~
//      	if (stsw)	//1st cahr of word                         //~va3dR~
        	if (stsw||delmsw)	//1st char after space or delm     //~va3dI~
            {                                                      //~v104I~
                stsw=0;                                            //~v104I~
                delmsw=0;                                          //~va3dI~
                if (wordtblen)		//not 1st word                 //~v104I~
                {                                                  //~v104I~
                	wordtblen++;    //intermidiate space           //~v104I~
                	*wordtb++=0;  //intermidiate space             //~v104R~
                }                                                  //~v104I~
            	*pus++=(USHORT)wordtblen;                          //~v104R~
//printf("wordlen=%d\n",wordtblen);                                //~v105R~
			}                                                      //~v104I~
            wordtblen++;                                           //~v104I~
            *wordtb++=ch;                                          //~v104I~
		}                                                          //~v104I~
	}                                                              //~v104I~
UTRACED("wordtbl out",wordtb0,(((wordno+1)<<1)+wordtblen+1));	//each word len by short//~va3dI~
	return;                                                        //~v104I~
}//wordtbgen                                                       //~v104I~
                                                                   //~v104I~
//*********************************************************************
//*set matcing pair
//*parm1:file1 qhdr
//*parm2:file2 qhdr
//*ret  :rc
//*********************************************************************
//void lvl0matching(PUQUEH Ppqh1,PUQUEH Ppqh2)                     //~va14R~
int  lvl0matching(PUQUEH Ppqh1,PUQUEH Ppqh2)                       //~va14R~
{
    long matchctr;
    PURECH prh1,prh2,prh1m,prh2m,prh1p,prh2p,prh1n,prh2n;
//*****************************
	prh1=UGETQTOP(Ppqh1);		//top entry
	prh2=UGETQTOP(Ppqh2);
    if (!prh1 || !prh2)                                            //~va14R~
    {                                                              //~va14R~
//      printf("===== NULL file detected after comment line ignore =====\n");//~va14R~//~va92R~
        fprintf(Sfhout,"===== NULL file detected after comment line ignore =====\n");//~va92I~
    	return 1;               //no record to be pushed           //~va14R~
    }                                                              //~va14R~
    pushpair(prh1,prh2);		//stack 1st pair of block
    for (;;)
    {
	    if (poppair(&prh1,&prh2))   //popup block
        	break;
    	matchctr=getmax(prh1,prh2,&prh1m,&prh2m);	//search matched max bandle
        if (!matchctr)              //no matcing found
            continue;               //pop next
//split prev part of max bandle
        if (prh1p=prh1m->URHprev,prh1p)
        	prh1p->URHnext=0;		//deq the bandle from prev of file1
        if (prh2p=prh2m->URHprev,prh2p)
        	prh2p->URHnext=0;		//deq the bandle from prev of file2
		if (prh1p && prh2p)			//both has bandle ont in max bandle
        	pushpair(prh1,prh2);	//search retry prev bandle
//set pair chain
		for (prh1n=prh1m,prh2n=prh2m;matchctr;matchctr--)
        {
        	prh1n->URHflag=URHFSAME;
        	prh2n->URHflag=URHFSAME;
        	prh1n->URHpair=prh2n;
        	prh2n->URHpair=prh1n;
            prh1n=prh1n->URHnext;
            prh2n=prh2n->URHnext;
        }
//split prev part of max bandle
        if (prh1n)
        	prh1n->URHprev=0;		//deq the bandle from followe of file1
        if (prh2n)
        	prh2n->URHprev=0;		//deq the bandle from followe of file2
		if (prh1n && prh2n)			//both has bandle ont in max bandle
        	pushpair(prh1n,prh2n);	//search retry next part
	}//all stack
//  return;                                                        //~va14R~
    return 0;                                                      //~va14R~
}//lvl0matching

//*********************************************************************
//*stack bandle top
//*parm1:file1 bandle top
//*parm2:file2 bandle top
//*ret  :rc
//*********************************************************************
void pushpair(PURECH Pprh1,PURECH Pprh2)
{
//*****************************
	Pprh1->URHlifo=Srhlifoq1;
	Pprh2->URHlifo=Srhlifoq2;
	Srhlifoq1=Pprh1;
	Srhlifoq2=Pprh2;
	return;
}//pushpair

//*********************************************************************
//*stack bandle top deq to search max bandle
//*parm1:output file1 bandle top ptr
//*parm2:output file2 bandle top ptr
//*ret  :rc
//*********************************************************************
int  poppair(PURECH *Ppprh1,PURECH *Ppprh2)
{
    PURECH	prh1,prh2;
//*****************************
	prh1=Srhlifoq1;
	prh2=Srhlifoq2;
    if (( prh1 && !prh2)
    ||  (!prh1 &&  prh2))
        uerrexit("Bandle Q deq internal logic err",0);
	*Ppprh1=prh1;
	*Ppprh2=prh2;
	if (!prh1)
		return 4;
	Srhlifoq1=prh1->URHlifo;
	Srhlifoq2=prh2->URHlifo;
	return 0;
}//poppair

//*********************************************************************
//*select max bandle
//*parm1:file1 bandle top ptr
//*parm2:file2 bandle top ptr
//*parm3:output file1 max match bandle top ptr
//*parm4:output file2 max match bandle top ptr
//*ret  :bandle width
//*********************************************************************
long getmax(PURECH Pprh1,PURECH Pprh2,PURECH *Ppprh1m,PURECH *Ppprh2m)
{
    long maxwidth=0,width;
    PURECH prh1,prh1m,prh1n,prh2m,prh2s;
//*****************************
	prh1m=0;prh2m=0;                                               //~va4eI~
//DBGTRC2("getmax",Pprh1,Pprh2);                                   //~v146R~
	for (prh1=Pprh1;prh1;)
	{
		width=chkmax(prh1,Pprh2,&prh1n,&prh2s);
        if (width)
        {
        	if (width>maxwidth)
            {
            	maxwidth=width;
                prh1m=prh1;			//max bandle start of file1
                prh2m=prh2s;		//max bandle start of file2
            }
            prh1=prh1n;         //contine from next of bandle
        }
        else                    //no matching
            prh1=prh1->URHnext;
    }//end of file1 bandle
	*Ppprh1m=prh1m;
	*Ppprh2m=prh2m;
	return maxwidth;
}//getmax

//*********************************************************************
//*search max bandle on file2
//*parm1:file1 bandle top ptr
//*parm2:file2 bandle top ptr
//*parm3:output file1 next of max bandle
//*parm4:output file2 top of max bandle
//*ret  :bandle width
//*********************************************************************
long chkmax(PURECH Pprh1,PURECH Pprh2,PURECH *Ppprh1n,PURECH *Ppprh2m)
{
    long maxwidth=0,width;
    PURECH prh1,prh2,prh1n,prh2m,prh2s=NULL,prh2sv;                //~va64R~
//*****************************
	prh1n=0;                                                       //~va58R~
	prh2m=0;                                                       //~va58I~
//DBGTRC2("chkmax",Pprh1,Pprh2);                                   //~v146R~
	for (prh2=Pprh2;prh2;prh2=prh2->URHnext)
	{
    	prh2sv=prh2;		//for level1 logic
    	width=0;
		for (prh1=Pprh1;prh1 && prh2;prh1=prh1->URHnext,prh2=prh2->URHnext)
        {
//      	data1=&prh1->URHdata+Smargin1;                         //~v105R~
//      	data2=&prh2->URHdata+Smargin1;                         //~v105R~
//      	dlen1=prh1->URHdlen-Smargin1;                          //~v105R~
//      	dlen2=prh2->URHdlen-Smargin1;                          //~v105R~
//          if (dlen1>Smarginw)                                    //~v105R~
//          	dlen1=Smarginw;                                    //~v105R~
//          if (dlen2>Smarginw)                                    //~v105R~
//          	dlen2=Smarginw;                                    //~v105R~
//          if (dlen1!=dlen2)       //length unmatch               //~v104R~
//              break;                                             //~v104R~
//          if (dlen1>0)      		//out of margin                //~v104R~
//              if (memcmp(data1,data2,(UINT)dlen1))               //~v104R~
            if (!linecompare(prh1,prh2))                           //~v105R~
                break;                                             //~v105I~
            if (!(width++)) //1st match                            //~v105I~
            	prh2s=prh2;			//save bandle top of file2
        }//until unmatch found

        if (width>maxwidth)
        {
            maxwidth=width;
            prh1n=prh1;         //next of max bandle of file1
            prh2m=prh2s;        //max bandle start of file2
        }
        if (Slvl)				//logic level(1 or 2)
        	prh2=prh2sv;		//restart from next of start
        if (!prh2)
        	break;
	}//until eof of bandle2
	*Ppprh1n=prh1n;
	*Ppprh2m=prh2m;
	return maxwidth;
}//chkmax

//*********************************************************************//~v105I~
//*compare                                                         //~v105R~
//*parm1:prh1                                                      //~v105I~
//*parm2:prh2                                                      //~v105I~
//*ret  :0:unmatch,4:match,3:match except comment,2:word match,1word match except cmt//~v105R~
//*********************************************************************//~v105I~
int linecompare(PURECH Pprh1,PURECH Pprh2)                         //~v105R~
{                                                                  //~v105I~
    int wdlen1,wdlen2;                                             //~v105M~
    UCHAR *wdata1,*wdata2;                                         //~v105M~
    int dlen1,dlen2;                                               //~v105R~
    UCHAR *data1,*data2;                                           //~v105I~
//*****************************                                    //~v105I~
    data1=&Pprh1->URHdata+Smargin1;                                //~v105I~
    data2=&Pprh2->URHdata+Smargin1;                                //~v105I~
    dlen1=Pprh1->URHdlen-Smargin1;                                 //~v105R~
    dlen2=Pprh2->URHdlen-Smargin1;                                 //~v105R~
//printf("linecomp len1=%d,len2=%d,data1=%s,data2=%s\n",dlen1,dlen2,data1,data2);//~v145R~
//DBGTRC2("comp",Pprh1,Pprh2);                                     //~v146R~
    if (dlen1>Smarginw)                                            //~v105I~
        dlen1=Smarginw;                                            //~v105I~
    if (dlen2>Smarginw)                                            //~v105I~
        dlen2=Smarginw;                                            //~v105I~
    if (dlen1<0)                                                   //~va9aI~
        dlen1=0;                                                   //~va9aI~
    if (dlen2<0)                                                   //~va9aI~
        dlen2=0;                                                   //~va9aI~
    if (dlen1==dlen2        //length match                         //~v105I~
    &&  (!dlen1 || !memcmp(data1,data2,(UINT)dlen1)))              //~v105R~
    	return URHF2SAME;			//completely match             //~v105R~
//compare except comment                                           //~v105I~
    dlen1=Pprh1->URHdlennet-Smargin1;                              //~v105I~
    dlen2=Pprh2->URHdlennet-Smargin1;                              //~v105I~
    if (dlen1>Smarginw)                                            //~v105I~
        dlen1=Smarginw;                                            //~v105I~
    if (dlen2>Smarginw)                                            //~v105I~
        dlen2=Smarginw;                                            //~v105I~
    if (dlen1<0)                                                   //~va9aI~
        dlen1=0;                                                   //~va9aI~
    if (dlen2<0)                                                   //~va9aI~
        dlen2=0;                                                   //~va9aI~
    if (dlen1==dlen2        //length match                         //~v105I~
    &&  (!dlen1 || !memcmp(data1,data2,(UINT)dlen1)))              //~v105I~
    	return URHF2SAMEC;			//completely match             //~v105R~
//word matching                                                    //~v105M~
    if (!Swordmatchingsw)                                          //~v105I~
    	return 0;                                                  //~v105I~
    wdata1=Pprh1->URHwordtb;                                       //~v105M~
    wdata2=Pprh2->URHwordtb;                                       //~v105M~
    wdlen1=Pprh1->URHwordtblen;                                    //~v105I~
    wdlen2=Pprh2->URHwordtblen;                                    //~v105I~
//printf("wordcomp len1=%d,len2=%d,data1=%s,data2=%s\n",wdlen1,wdlen2,wdata1,wdata2);//~v104R~
    if (wdlen1==wdlen2)                                            //~v105R~
    	if (!wdlen1 || !memcmp(wdata1,wdata2,(UINT)wdlen1))        //~v105R~
        	return URHF2SAMEW;                                     //~v105I~
                                                                   //~v105I~
    wdlen1=Pprh1->URHwordtblennet;                                 //~v105I~
    wdlen2=Pprh2->URHwordtblennet;                                 //~v105I~
    if (wdlen1==wdlen2)                                            //~v105I~
    	if (!wdlen1 || !memcmp(wdata1,wdata2,(UINT)wdlen1))        //~v105I~
        	return URHF2SAMEWC;                                    //~v105I~
	return 0;                                                      //~v105I~
}//linecompare                                                     //~v105R~
//*********************************************************************
//*set ins/del/upd flag
//*parm1:file1 qhdr
//*parm2:file2 qhdr
//*ret  :none
//*********************************************************************
void setupdate(PUQUEH Ppqh1,PUQUEH Ppqh2)
{
	PURECH prh1,prh2;
//*****************************
	prh1=UGETQTOP(Ppqh1);
	prh2=UGETQTOP(Ppqh2);
	while (prh1 || prh2)
	{
//dlet chk
        if (!prh2
        ||   prh2->URHflag==URHFSAME)	//more file2
        	for (;prh1 && prh1->URHflag!=URHFSAME;prh1=UGETQNEXT(prh1))
            {
            	prh1->URHflag=URHFDLET;
                Sdletctr++;
            }
//isrt chk
    	if (!prh1
        ||   prh1->URHflag==URHFSAME)	//may insert line exist
        	for (;prh2 && prh2->URHflag!=URHFSAME;prh2=UGETQNEXT(prh2))
            {
            	prh2->URHflag=URHFISRT;
                Sisrtctr++;
            }
//skip match bandle
        for (;   prh1 && prh1->URHflag==URHFSAME
              && prh2 && prh2->URHflag==URHFSAME ;
				prh1=UGETQNEXT(prh1),prh2=UGETQNEXT(prh2))
            Ssamectr++;
//between with next mactch bandle
        if (prh1 && prh1->URHflag!=URHFSAME
        &&  prh2 && prh2->URHflag!=URHFSAME)
	        lvl2matching(prh1,prh2,&prh1,&prh2);
	}//until both eof
	return;
}//setupdate

//*********************************************************************
//*set matcing pair for not 100% equal line
//*parm1:start of bandle of file1
//*parm2:start of bandle of file2
//*parm3:next prh1
//*parm4:next prh2
//*ret  :rc
//*********************************************************************
void lvl2matching(PURECH Pprh1,PURECH Pprh2,PURECH *Ppprh1,PURECH *Ppprh2)
{
    long width1=0,width2=0;
    PURECH prh1,prh2,prh2sv,prh1end,prh2end;
    PURECH prh1prev,prh1next,prh2next,prh1del,prh2ins=NULL;             //~v100R~//~va64R~
//*****************************
	prh1end=0;prh2end=0;                                           //~va4eI~
//*save bandle end
    for (prh1=Pprh1;prh1;prh1=prh1->URHnext)
    {
    	width1++;
    	prh1end=UGETQNEXT(prh1);           //last entry
	}
    for (prh2=Pprh2;prh2;prh2=prh2->URHnext)
    {
    	width2++;
    	prh2end=UGETQNEXT(prh2);           //last entry
	}
//*
	if (Slvl==2)
    {
    	if (width1>width2)
        {
        	prh1=Pprh2;     //see from small bandle=file2
            prh2=Pprh1;
        }
		else
        {
        	prh1=Pprh1;     //see from small bandle=file1
            prh2=Pprh2;
        }
        prh2sv=prh2;			//restart point
        for (;prh1 && prh2;prh1=prh1->URHnext)
        {
            if (!fazymatching(prh1,prh2,&prh2))
            {
                prh1->URHflag=URHFREPL;
                prh2->URHflag=URHFREPL;
                prh1->URHpair=prh2;
                prh2->URHpair=prh1;
                prh2=prh2->URHnext;
                Sreplctr++;
                prh2sv=prh2;
            }
            else
            	prh2=prh2sv;
		}//loop by file small bandle
	}
//*set isrt/dlet for not matched
    prh1prev=0;                                                    //~v100I~
    for (prh1=Pprh1;prh1!=prh1end;prh1=UGETQNEXT(prh1))
    {                                                              //~v100I~
    	if (prh1->URHflag!=URHFREPL)
        {
//printf("prh1=(%c)%s\n",prh1->URHflag,&(prh1->URHdata));          //~v100R~
//assume repl if 1-del and 1-ins                                   //~v100I~
        	prh1del=0;                                             //~v100I~
            prh1next=prh1->URHnext;		//next of del              //~v100I~
//printf("prh1next=%08x\n",prh1next);                              //~v100R~
            if ((!prh1prev				//1st non repl             //~v100R~
			     ||prh1prev->URHflag==URHFREPL)   //after rep      //~v100R~
            &&  (!prh1next				//no next                  //~v100I~
			     ||prh1next->URHflag==URHFREPL)) //or next is rep  //~v100R~
            {                           //only 1 deleted line      //~v100I~
            	if (!prh1prev)          //1st deleted              //~v100I~
                	prh2ins=Pprh2;       //another candidate is top//~v100I~
                else                    //prev has pair            //~v100I~
                	prh2ins=(prh1prev->URHpair)->URHnext;//next of pair//~v100I~
//printf("prh2ins=%08x\n",prh2ins);                                //~v100R~
                if (prh2ins)                                       //~v100I~
                if (!prh2ins->URHflag)                             //~v102R~
                {                                                  //~v100I~
//printf("prh2ins=(%c)%s\n",prh2ins->URHflag,&prh2ins->URHdata);   //~v100R~
                	prh2next=prh2ins->URHnext;                     //~v100I~
                	if (!prh2next			//no another next      //~v100I~
					||   prh2next->URHflag==URHFREPL)//next is rep //~v100R~
	                	prh1del=prh1;		//1-delete 1-insert    //~v100I~
                }                                                  //~v100I~
			}                                                      //~v100I~
//printf("prh1del=%08x\n",prh1del);                                //~v100R~
            if (prh1del)                                           //~v100R~
            {                                                      //~v100I~
                prh1del->URHflag=URHFREPL;                         //~v100I~
                prh2ins->URHflag=URHFREPL;                         //~v100I~
                prh1del->URHpair=prh2ins;                          //~v100I~
                prh2ins->URHpair=prh1del;                          //~v100I~
                Sreplctr++;                                        //~v100I~
            }                                                      //~v100I~
            else                                                   //~v100I~
            {                                                      //~v100I~
	    		prh1->URHflag=URHFDLET;                            //~v100R~
            	Sdletctr++;                                        //~v100R~
            }                                                      //~v100I~
		}//not repl entry                                          //~v100R~
        prh1prev=prh1;                                             //~v100I~
    }                                                              //~v100I~
//set insert                                                       //~v100I~
    for (prh2=Pprh2;prh2!=prh2end;prh2=UGETQNEXT(prh2))
    	if (prh2->URHflag!=URHFREPL)
		{
	    	prh2->URHflag=URHFISRT;
            Sisrtctr++;
		}
   	*Ppprh1=prh1end;
   	*Ppprh2=prh2end;
	return;
}//lvl2matching

//*********************************************************************
//*fazy matching
//*parm1:line of short bandle
//*parm2:long bandle start rh
//*parm3:output fazy matched line
//*ret  :rc 0:matched line exist
//*********************************************************************
int fazymatching(PURECH Pprh1,PURECH Pprh2,PURECH *Ppprh2m)
{
    PURECH prh2;
    int dlen1,dlen2;
    char *data1,*data2;
//*****************************
//printf("fazymatching %s and %s",&Pprh1->URHdata,&Pprh2->URHdata);//~v104R~
	data1=&Pprh1->URHdata+Smargin1;
    if ((dlen1=Pprh1->URHdlen-Smargin1)<0)                         //~v105R~
    	return 4;			//chk next
    if (dlen1>Smarginw)
        dlen1=Smarginw;
	for (prh2=Pprh2;prh2;prh2=prh2->URHnext)
	{
     	data2=&prh2->URHdata+Smargin1;
        if ((dlen2=prh2->URHdlen-Smargin1)<0)                      //~v105R~
        	continue;	//asume unmatched
        if (dlen2>Smarginw)
            dlen2=Smarginw;
        if (fazywordmatching(Pprh1,prh2))                          //~v104R~
            break;                                                 //~v104R~
        if (fazywordmatching(prh2,Pprh1))                          //~v104R~
            break;                                                 //~v104R~
		if (nsntmatching(data1,data2,dlen1,dlen2))
        	break;
		if (nsntmatching(data2,data1,dlen2,dlen1))
        	break;
	}//until eof of bandle2
    if (!prh2)
    	return 4;
	*Ppprh2m=prh2;
	return 0;
}//fazymatching
//*********************************************************************//~v104I~
//*fazy wordmatching                                               //~v104I~
//*parm1:RECH1                                                     //~v104I~
//*parm2:RECH2                                                     //~v104I~
//*ret  :mached id 0:unmatch,1:match                               //~v104I~
//*********************************************************************//~v104I~
int fazywordmatching(PURECH Pprh1,PURECH Pprh2)                    //~v104I~
{                                                                  //~v104I~
    int wordno1,wordno2,ii,jj,jj0,len1,len2,compctr,samectr,rc;    //~v104R~
    UCHAR *wdata1,*wdata2,*pc1,*pc2;                               //~v104I~
    USHORT *pus1,*pus2,*pus2s;                                     //~v104R~
//*************                                                    //~v104I~
    wdata1=Pprh1->URHwordtb;                                       //~v104R~
    wdata2=Pprh2->URHwordtb;                                       //~v104R~
    wordno1=Pprh1->URHwordno;                                      //~v104R~
    wordno2=Pprh2->URHwordno;                                      //~v104R~
    pus1=Pprh1->URHwordoffstb;                                     //~v104R~
    pus2=Pprh2->URHwordoffstb;                                     //~v104R~
//printf("word1=%s,word2=%s no1=%d,no2=%d\n",wdata1,wdata2,wordno1,wordno2);//~v105R~
                                                                   //~v104I~
    compctr=0;                                                     //~v104I~
    samectr=0;                                                     //~v104I~
    pus2s=pus2;                                                    //~v104I~
    jj0=0;                                                         //~v104R~
    for (ii=0;ii<wordno1;ii++,pus1++)                              //~v104I~
    {                                                              //~v104I~
        pc1=wdata1+*pus1;		//word start                       //~v104I~
        len1=*(pus1+1)-*pus1-1;	//wrd len                          //~v104R~
		compctr++;                                                 //~v104I~
        for (jj=jj0,pus2=pus2s+jj;jj<wordno2;jj++,pus2++)          //~v104R~
        {                                                          //~v104I~
	        pc2=wdata2+*pus2;                                      //~v104I~
	        len2=*(pus2+1)-*pus2-1;	//wrd len                      //~v104R~
//printf("word comp ii=%d,jj=%d,len1=%d,len2=%d,word1=%s,word2=%s\n",ii,jj,len1,len2,pc1,pc2);//~v104R~
            if (len1==len2 && !memcmp(pc1,pc2,(UINT)len1))	//word match//~v104I~
            	break;                                             //~v104I~
		}                                                          //~v104I~
        if (jj==wordno2)	//not matched                          //~v104I~
        	continue;                                              //~v104I~
//printf("match %s,%s",pc1,pc2);                                   //~v105R~
        samectr++;                                                 //~v104I~
        pus2++;                                                    //~v104I~
        jj++;                                                      //~v104I~
	}                                                              //~v104I~
//char count on data2                                              //~v104I~
    if (!compctr)	//both all space/tab                           //~v104I~
    	return 1;			//assume as match                      //~v104I~
    rc=samectr*100/compctr>=Scriteria;                             //~v104R~
//printf("same=%d,comp=%d,match=%d Scriteria=%d\n",samectr,compctr,rc,Scriteria);//~v104R~
	return rc;                                                     //~v104I~
}//fazywordmatching                                                //~v104I~
                                                                   //~v104I~
//*********************************************************************
//*chk except space tab
//*parm1:data1
//*parm2:data2
//*parm3:data1 len
//*parm4:data2 len
//*ret  :mached id 0:unmatch,1:match
//*********************************************************************
int nsntmatching(char *Pdata1,char *Pdata2,int Pdlen1,int Pdlen2)
{
    char *data1,*data2,*data1e,*data2e,ch,*pc;
    int compctr,samectr,d2ctr,rc;
//*************
    data1=Pdata1;
    data2=Pdata2;
    data1e=Pdata1+Pdlen1;
    data2e=Pdata2+Pdlen2;

    compctr=0;
    samectr=0;
    for (;data1<data1e;data1++)
    {
    	ch=*data1;
        if (ch==' '||ch=='\t')
            continue;
		compctr++;
        for (pc=data2;pc<data2e;pc++)
        {
            if (*pc==' '||*pc=='\t')
            	continue;
            if (ch==*pc)
            	break;
		}
        if (pc>=data2e)	//not matched
        	continue;
//printf("match %s,%s\n",data1,pc);                                //~v104R~
        samectr++;
        data2=pc+1;
	}
//char count on data2
    for (d2ctr=0,pc=Pdata2;pc<data2e;pc++)
    	if (*pc!=' ' && *pc!='\t')
        	d2ctr++;
	if (compctr<d2ctr)
    	compctr=d2ctr;
    if (!compctr)	//both all space/tab
    	return 1;			//assume as match
    rc=samectr*100/compctr>=Scriteria;
//printf("nsnt match same=%d,comp=%d,match=%d,%s and %s\n",samectr,compctr,rc,Pdata1,Pdata2);//~v104R~
	return rc;
}//nsntmatching
//*********************************************************************
//*set ins/del/upd flag
//*parm1:file1 qhdr
//*parm2:file2 qhdr
//*ret  :none
//*********************************************************************
void resultprint(PUQUEH Ppqh1,PUQUEH Ppqh2)
{
	PURECH prh1,prh2;
	PURECH prh1o,prh2o,prhw;                                       //~v102R~
    int    skipsw;                                                 //~v102I~
//*****************************
	prh1=UGETQTOP(Ppqh1);
	prh2=UGETQTOP(Ppqh2);
	if (Sostyle==PRINT_BOTH)
	{
        sprintf(Stxtbuff,"***** file1 : %s\n",Sfnm1);              //~va4dR~
//      putline(Stxtbuff,strlen(Stxtbuff));                        //~va4dR~//~vaa0R~
        putline(Stxtbuff,(int)strlen(Stxtbuff));                   //~vaa0I~
	    for (;prh1;prh1=UGETQNEXT(prh1))
			printsub(prh1,0);		//isrt print
        sprintf(Stxtbuff,"\n***** file2 : %s\n",Sfnm2);            //~va4dR~
//      putline(Stxtbuff,strlen(Stxtbuff));                        //~va4dR~//~vaa0R~
        putline(Stxtbuff,(int)strlen(Stxtbuff));                   //~vaa0I~
	    for (;prh2;prh2=UGETQNEXT(prh2))
			printsub(prh2,1);		//isrt print
        return;
    }
//marge prit or difference print
	while (prh1 || prh2)
	{
    	prh1o=prh1;                                                //~v102I~
    	prh2o=prh2;                                                //~v102I~
//print deleted
        for (;prh1 && prh1->URHflag==URHFDLET;prh1=UGETQNEXT(prh1))
	        printsub(prh1,0);		//delete print
        for (;prh2 && prh2->URHflag==URHFISRT;prh2=UGETQNEXT(prh2))
            printsub(prh2,1);		//isrt print
//print matched
        for (;   prh1 && prh1->URHflag==URHFSAME
              && prh2 && prh2->URHflag==URHFSAME ;
				prh1=UGETQNEXT(prh1),prh2=UGETQNEXT(prh2))
		{                                                          //~v102I~
            if (prh1->URHpair!=prh2                                //~v102R~
            ||  prh2->URHpair!=prh1)                               //~v102I~
            {                                                      //~v102I~
            	printsub(prh1,-1);		//err print                //~v102I~
            	printsub(prh2,-1);		//err print                //~v102I~
            }                                                      //~v102I~
            else                                                   //~v102I~
//          if (Sostyle==PRINT_MERGE)                              //~v105R~
//          {                                                      //~v105R~
            	printsub(prh1,0);		//same print
            	printsub(prh2,1);		//same print if word match or comment match//~v105R~
//          }                                                      //~v105R~
		}                                                          //~v102I~
//between with next mactch bandle
        for (;   prh1 && prh1->URHflag==URHFREPL
              && prh2 && prh2->URHflag==URHFREPL ;
				prh1=UGETQNEXT(prh1),prh2=UGETQNEXT(prh2))
		{
            if (prh1->URHpair!=prh2                                //~v102I~
            ||  prh2->URHpair!=prh1)                               //~v102I~
            {                                                      //~v102I~
            	printsub(prh1,-1);		//err print                //~v102I~
            	printsub(prh2,-2);		//err print                //~v102R~
            }                                                      //~v102I~
            else                                                   //~v102I~
            {                                                      //~v102I~
        	printsub(prh1,0);		//update print
        	printsub(prh2,1);		//update print
            }                                                      //~v102I~
		}
//logic err chk                                                    //~v102R~
        if (prh1==prh1o && prh2==prh2o)//infinite loop             //~v102R~
        {                                                          //~v102R~
        	skipsw=0;	//skip prh1                                //~v102I~
            if (!prh1)                                             //~v102R~
            	if (prh2)       //prh1==0,prh2!=0                  //~v102I~
	                skipsw=1;                                      //~v102R~
                else        	//both 0                           //~v102I~
                	break;	                                       //~v102I~
            else	                                               //~v102I~
            	if (prh2)       //both not 0                       //~v102R~
                {                                                  //~va14I~
                	if (prhw=prh1->URHpair,prhw)                   //~v102I~
                    {                                              //~v102I~
                    	if (prhw->URHlineno>prh2->URHlineno)       //~v102I~
                        	skipsw=1;	//advance prh2             //~v102I~
					}                                              //~v102I~
                    else                                           //~v102I~
                        if (prhw=prh2->URHpair,prhw)               //~v102I~
                            if (prhw->URHlineno<prh1->URHlineno)   //~v102I~
                                skipsw=1;   //advance prh2         //~v102I~
                }//prh2                                            //~va14I~
			if (skipsw)	//prh2 skip                                //~v102I~
            {                                                      //~v102I~
            	printsub(prh2,-2);		//err print                //~v102I~
				prh2=UGETQNEXT(prh2);                              //~v102I~
            }                                                      //~v102I~
            else                                                   //~v102I~
            {                                                      //~v102I~
            	printsub(prh1,-1);		//err print                //~v102I~
				prh1=UGETQNEXT(prh1);                              //~v102I~
            }                                                      //~v102I~
        }//logic err                                               //~v102R~
	}//until both eof
	return;
}//resultprint

//*********************************************************************
//*print 1 record
//*parm1:URH
//*parm2:0:file1,1:file2
//*ret  :none
//*********************************************************************
void printsub(PURECH Pprh,int Pfilesw)
{
    UCHAR flag,flag2;                                              //~v105R~
    PURECH prh2;
    UCHAR zline1[16],zline2[16],*pzl1,*pzl2,*updid;
    UCHAR linehdr[64];
    UCHAR  updidw[8];                                              //~v105I~
    UCHAR *pc,*pce;                                                //~v107I~
    int   len;                                                     //~v107I~
    int marklinesw=0;                                              //~v104I~
    int ch;                                                        //~va79I~
//*****************************
	updid=0;pzl1=0;pzl2=0;                                         //~va4eI~
  if (Pprh->URHprefixlineno)                                       //~va80I~
    sprintf(zline1,"%ld",Pprh->URHprefixlineno);                   //~va80I~
  else                                                             //~va80I~
    sprintf(zline1,"%ld",Pprh->URHlineno);
UTRACEP("file=%d lineno=%d,prefix=%d\n",Pfilesw,Pprh->URHlineno,Pprh->URHprefixlineno);//~va80I~
    flag=Pprh->URHflag;
//chk comment mach or word match                                   //~v105I~
    if (flag==URHFSAME)                                            //~v105I~
    {                                                              //~va14I~
        if (Pfilesw)   //1st file                                  //~v105I~
        {                                                          //~v105I~
          if (Sostyle2!=PRINT_FULL)                                //~va4dI~
          {                                                        //~va4dI~
            flag=Pprh->URHflag2;                                   //~v105R~
            if (!flag || flag==URHF2SAME)                          //~v105I~
        		return;			//completely matched 2nd file line //~v105I~
          }                                                        //~va4dI~
		}                                                          //~v105I~
        else                                                       //~v105R~
            if ((prh2=Pprh->URHpair)!=0)    //pair chained         //~v105R~
            {                                                      //~v105I~
                flag2=(UCHAR)linecompare(Pprh,prh2);               //~v105R~
                if ((Swordpsw && (flag2==URHF2SAMEW||flag2==URHF2SAMEWC))//~v105R~
                ||  (Scmntpsw && (flag2==URHF2SAMEC||flag2==URHF2SAMEWC)))//~v105R~
                {                                                  //~v105I~
                	flag=flag2;                                    //~v105I~
                	Pprh->URHflag2=flag;                           //~v105R~
                	prh2->URHflag2=flag;                           //~v105R~
//printf("same flag2=%c\n",flag);                                  //~v104R~
                }                                                  //~v105I~
            }                                                      //~v105I~
    }//urhfsame                                                    //~va14I~
                                                                   //~v105I~
    switch(flag)
    {
    case URHFSAME:
		if (Sostyle==PRINT_DIFF)                                   //~v105R~
        	return;                                                //~v105I~
    	prh2=Pprh->URHpair;
        if (prh2)                                                  //~v102I~
        {                                                          //~va80I~
  			if (prh2->URHprefixlineno)                             //~va80R~
	    sprintf(zline2,"%ld",prh2->URHprefixlineno);               //~va80I~
            else                                                   //~va80I~
	    sprintf(zline2,"%ld",prh2->URHlineno);
        }                                                          //~va80I~
        else                                                       //~v102I~
	        zline2[0]=0;                                           //~v102I~
        pzl1=zline1;
        pzl2=zline2;
        if (Pfilesw<0)	//internal logic err                       //~v102I~
    	    updid="?==?";                                          //~v102I~
        else                                                       //~v102I~
        updid=" == ";
UTRACEP("swame z1=%s,z2=%s\n",pzl1,pzl2);                          //~va80I~
        break;
    case URHFREPL:
    case URHF2SAMEW:     //word match                              //~v105R~
    case URHF2SAMEC:     //match except comment                    //~v105R~
    case URHF2SAMEWC:    //word match except comment               //~v105R~
//        prh2=Pprh->URHpair;                                      //~v102I~
//        sprintf(zline2,"%ld",prh2->URHlineno);                   //~v102I~
		if (Scmntnoprsw && Sostyle==PRINT_DIFF)                    //~v146I~
        {                                                          //~v146I~
        	prh2=Pprh->URHpair;                                    //~v146I~
        	if ((Pprh->URHflag3 & URHF3NULLCMT)//null or comment line//~v146R~
        	&&  (prh2->URHflag3 & URHF3NULLCMT))//null or comment line//~v146I~
	        	return; 		//no print                         //~v146I~
        }                                                          //~v146I~
        Sreplctrprint++;                                           //~va11I~
		marklinesw=1;                                              //~v104I~
        zline2[0]=0;                                               //~v102I~
        if (Pfilesw<0)  //internal logic err                       //~v102M~
        {                                                          //~v102M~
            if (Pfilesw==-2)    //file2                            //~v102I~
            {                                                      //~v102I~
                updid="?!=?";                                      //~v102I~
                pzl1=zline2;                                       //~v102I~
                pzl2=zline1;                                       //~v102I~
            }                                                      //~v102I~
            else                //file1                            //~v102R~
            {                                                      //~v102I~
                updid="?=!?";                                      //~v102R~
                pzl1=zline1;                                       //~v102I~
                pzl2=zline2;                                       //~v102I~
            }                                                      //~v102I~
        }                                                          //~v102I~
        else                                                       //~v102I~
        if (Pfilesw)
        {
          if (flag==URHFREPL)                                      //~v105R~
	        updid=" != ";
          else                                                     //~v105I~
          {                                                        //~v105M~
    	  	sprintf(updidw," %c= ",flag);                          //~v105I~
	        updid=updidw;                                          //~v105R~
          }                                                        //~v105I~
	        pzl1=zline2;
	        pzl2=zline1;
		}
        else
        {
          if (flag==URHFREPL)                                      //~v105I~
	        updid=" =! ";
          else                                                     //~v105I~
          {                                                        //~v105I~
    	  	sprintf(updidw," =%c ",flag);                          //~v105I~
	        updid=updidw;                                          //~v105R~
          }                                                        //~v105I~
	        pzl1=zline1;
	        pzl2=zline2;
		}
        break;
    case URHFISRT:
		if (Scmntnoprsw && Sostyle==PRINT_DIFF)                    //~v146I~
        	if (Pprh->URHflag3 & URHF3NULLCMT)//null or comment line//~v146I~
	        	return; 		//no print                         //~v146I~
        Sisrtctrprint++;                                           //~va11I~
        pzl1="INS   ";
	    pzl2=zline1;
        updid=" << ";
        break;
    case URHFDLET:
		if (Scmntnoprsw && Sostyle==PRINT_DIFF)                    //~v146I~
        	if (Pprh->URHflag3 & URHF3NULLCMT)//null or comment line//~v146I~
	        	return; 		//no print                         //~v146I~
        Sdletctrprint++;                                           //~va11I~
	    pzl1=zline1;
        pzl2="DEL   ";
        updid=" >> ";
        break;
    }
    if (Pfilesw<0)                                                 //~v102R~
        Slogicerr=1;                                               //~v102I~
	sprintf(linehdr,"%-6s%-4s%-6s | ",pzl1,updid,pzl2);            //~v105R~
    memcpy(Stxtbuff,linehdr,LINEHDRSZ);
    memcpy(Stxtbuff+LINEHDRSZ,&Pprh->URHdata,(UINT)Pprh->URHdlen);
//repl tab char                                                    //~v107I~
#ifdef AAA                                                         //~va79I~
    if (Stabdisp)   //requested tab replace                        //~v107I~
        for (pc=Stxtbuff+LINEHDRSZ,len=Pprh->URHdlen,pce=pc+len;pc<pce;)//~v107I~
        {                                                          //~v107I~
        	if (!(pc=memchr(pc,'\t',(UINT)len)))                   //~v145R~
            	break;                                             //~v107I~
            *pc++=(UCHAR)Stabdisp;                                 //~v145R~
//          len=(int)((ULONG)pce-(ULONG)pc);                       //~v145R~//~va66R~
            len=(int)((ULPTR)pce-(ULPTR)pc);                       //~va66I~
        }                                                          //~v107I~
#else                                                              //~va79I~
    UTRACED("printsub1",Stxtbuff+LINEHDRSZ,Pprh->URHdlen);         //~va79R~
    for (pc=Stxtbuff+LINEHDRSZ,len=Pprh->URHdlen,pce=pc+len;pc<pce;pc++)//~va79I~
    {                                                              //~va79I~
    	ch=*pc;                                                    //~va79I~
    	if (ch=='\t')                                              //~va79R~
        {                                                          //~va79I~
    		if (Stabdisp)                                          //~va79I~
		        *pc=(UCHAR)Stabdisp;                               //~va79I~
        }                                                          //~va79I~
        else                                                       //~va79I~
    	if (ch=='\n')                                              //~va79R~
        {                                                          //~va79I~
    		if (Srecordmode)                                       //~va79I~
	        	*pc='.';                                           //~va79R~
        }                                                          //~va79I~
        else                                                       //~va79I~
    	if (ch<' ')  //unprintable                                 //~va79I~
	        *pc='.';                                               //~va79I~
    }                                                              //~va79I~
    UTRACED("printsub1",Stxtbuff+LINEHDRSZ,Pprh->URHdlen);         //~va79R~
#endif                                                             //~va79I~
	putline(Stxtbuff,LINEHDRSZ+Pprh->URHdlen);
    if (Srecordmode)                                               //~va79I~
        putline("\n",1);                                           //~va79I~
//  if (flag==URHFREPL) //mark line print required                 //~v104R~
    if (marklinesw) //mark line print required                     //~v104I~
        markline(Pprh);
	return;
}//printsub

//*********************************************************************
//*search max bandle on file2
//*parm1:prh
//*ret  :none
//*********************************************************************
void markline(PURECH Pprh)
{
    PURECH prh2;
    int dlen0,dlen1,dlen2,ii,minlen;
    char *data1,*data2,*buff;
//*****************************
	memset(Stxtbuff,' ',LINEHDRSZ-1);
    *(Stxtbuff+LINEHDRSZ-1)='|';
    buff=Stxtbuff+LINEHDRSZ;
	prh2=Pprh->URHpair;
//
    data1=&Pprh->URHdata;
    data2=&prh2->URHdata;
  if (Srecordmode)                                                 //~va79I~
  {                                                                //~va79I~
    dlen0=dlen1=Pprh->URHdlen;	//no last \n                       //~va79I~
    dlen2=prh2->URHdlen;                                           //~va79I~
  }                                                                //~va79I~
  else                                                             //~va79I~
  {                                                                //~va79I~
    dlen0=dlen1=Pprh->URHdlen-1;	//except last \n
    dlen2=prh2->URHdlen-1;
  }                                                                //~va79I~
    if (minlen=min(dlen1,Smargin1),minlen)
    {
	    memset(buff,' ',(UINT)minlen);
		buff+=minlen;
		data1+=minlen;
		data2+=minlen;
        dlen1-=minlen;
        dlen2-=minlen;
    }
    if (dlen1>0)		//over start margin
    {
    	minlen=min(dlen1,Smarginw);
        for (ii=0;ii<minlen;ii++,dlen2--)
        {
            if (dlen2>0 && *data1==*data2)
                *buff=' ';
            else
                *buff='+';
            buff++;
            data1++;
            data2++;
        }
        if ((dlen1-=minlen)>0)	//over end of margin
		    memset(buff,' ',(UINT)dlen1);
    }
	dlen0+=LINEHDRSZ;
    *(Stxtbuff+dlen0++)='\n';
	putline(Stxtbuff,dlen0);
	return;
}//markline

//*********************************************************************
//*put a line
//*parm1:data
//*parm2:len
//*ret  :none
//*********************************************************************
void putline(char *Pbuff,int Plen)
{
//*****************************
    UTRACED("putline",Pbuff,Plen);                                 //~va79I~
//  if (fwrite(Pbuff,1,(UINT)Plen,stdout)!=(UINT)Plen)             //~va92R~
    if (fwrite(Pbuff,1,(UINT)Plen,Sfhout)!=(UINT)Plen)             //~va92I~
    	uerrexit("Output to stdout failed,rc=%d\n",0,
					errno);
	return;
}//putline

//*********************************************************************
//* return 0:fully equall
//*        1:unmatch exist
//*        4:encountered error condition
//*********************************************************************
int bincomp(void)
{
	FILE *fh1,*fh2;
    UINT readlen1,readlen2;
//  ULONG totlen1=0,totlen2=0,offset;                              //~va30R~
    FILESZT totlen1=0,totlen2=0,offset;                            //~va30I~
    int ctr=0,ii,complen;
    int rc;                                                        //~v151I~
    UINT ch1,ch2;
    UCHAR *pc1,*pc2,*buff1,*buff2;
    FILEFINDBUF3 fstat31,fstat32;
//  ULONG pos1,pos2,endoffs1,endoffs2;                             //~va30R~
    FILESZT pos1,pos2,endoffs1,endoffs2;                           //~va30I~
//    int readctr=0;                                               //~va30R~
//*****************************
//    if (ufstat(Sfnm1,&fstat31))                                  //~v101R~
//        exit(8);                                                 //~v101R~
//    if (ufstat(Sfnm2,&fstat32))                                  //~v101R~
//        exit(8);                                                 //~v101R~
    ufstat(Sfnm1,&fstat31);                                        //~v101I~
    ufstat(Sfnm2,&fstat32);                                        //~v101I~
	fh1=openfile(Sfnm1,"rb",0);	//exit when open faile
	fh2=openfile(Sfnm2,"rb",0);	//exit when open faile
    if (!(buff1=malloc(BUFFSZ)))
		uerrexit("malloc failed for buff1,size=%d)",0,BUFFSZ);
    if (!(buff2=malloc(BUFFSZ)))
		uerrexit("malloc failed for buff2,size=%d)",0,BUFFSZ);
//skip to start pos
//  pos1=binstartpos(Sfnm1,fh1,&fstat31,Srange1s);                 //~vaa1R~
    pos1=(FILESZT)binstartpos(Sfnm1,fh1,&fstat31,Srange1s);        //~vaa1I~
//  pos2=binstartpos(Sfnm2,fh2,&fstat32,Srange2s);                 //~vaa1R~
    pos2=(FILESZT)binstartpos(Sfnm2,fh2,&fstat32,Srange2s);        //~vaa1I~
  if (Sendoffsp1)                                                  //~va30I~
//  endoffs1=Srange1e-pos1;                                        //~vaa1R~
    endoffs1=(FILESZT)Srange1e-pos1;                               //~vaa1I~
  else                                                             //~va30I~
    endoffs1=FILESZ_MAX-pos1;                                      //~va30I~
  if (Sendoffsp2)                                                  //~va30I~
//  endoffs2=Srange2e-pos2;                                        //~vaa1R~
    endoffs2=(FILESZT)Srange2e-pos2;                               //~vaa1I~
  else                                                             //~va30I~
    endoffs2=FILESZ_MAX-pos1;                                      //~va30I~
//printf("pos1=%08lx,pos2=%08lx,eoff1=%08lx,eoff2=%08lx\n",pos1,pos2,endoffs1,endoffs2);
//compare
    for (;;)
    {
		readlen1=getinput(Sfnm1,fh1,buff1,BUFFSZ);
        if (totlen1+readlen1>endoffs1)
//      	readlen1=endoffs1-totlen1;		//compare residual     //~va30R~
        	readlen1=(UINT)(endoffs1-totlen1);		//compare residual//~va30R~
		readlen2=getinput(Sfnm2,fh2,buff2,BUFFSZ);
        if (totlen2+readlen2>endoffs2)
//      	readlen2=endoffs2-totlen2;		//compare residual     //~va30R~
        	readlen2=(UINT)(endoffs2-totlen2);		//compare residual//~va30R~
        if (readlen1<readlen2)
		     complen=(int)readlen1;
        else
		     complen=(int)readlen2;
//        readctr++;                                               //~va30R~
//if (!(readctr%100))                                              //~va30R~
//printf("totlen1=%llx\n",totlen1+pos1);                           //~va30R~
		if (memcmp(buff1,buff2,BUFFSZ))
            for (ii=0,pc1=buff1,pc2=buff2;ii<complen;ii++,pc1++,pc2++)
                if (*pc1!=*pc2)
                {
                    if ((ch1=*pc1)<' ')		//ctr char
                    	ch1=' ';
                    if ((ch2=*pc2)<' ')		//ctr char
                    	ch2=' ';
                    offset=totlen1+ii;
                  	if (pos1==pos2)                                //~v106R~
//                  	printf("+x%08lX: %c(x%02X) != %c(x%02X)\n",//~va30R~
//  							offset+pos1,ch1,(UINT)*pc1,ch2,(UINT)*pc2);//~va30R~
//                  	printf("+x%s: %c(x%02X) != %c(x%02X)\n",   //~va30I~//~va92R~
                    	fprintf(Sfhout,"+x%s: %c(x%02X) != %c(x%02X)\n",//~va92I~
    							ufileeditsz(UFEFSZ_HEXUPPER,offset+pos1,0),//~va30I~
    							ch1,(UINT)*pc1,ch2,(UINT)*pc2);    //~va30I~
                  	else                                           //~v106R~
                    {                                              //~va30I~
//                  	printf("+x%08lX: %c(x%02X) != %c(x%02X) :+x%08lX\n",//~va30R~
//  							offset+pos1,ch1,(UINT)*pc1,ch2,(UINT)*pc2,offset+pos2);//~va30R~
//                  	printf("+x%s: %c(x%02X) != %c(x%02X) :",   //~va30R~//~va92R~
                    	fprintf(Sfhout,"+x%s: %c(x%02X) != %c(x%02X) :",//~va92I~
    							ufileeditsz(UFEFSZ_HEXUPPER,offset+pos1,0),//~va30I~
    							ch1,(UINT)*pc1,ch2,(UINT)*pc2);    //~va30I~
//                  	printf("+x%s\n",                           //~va30R~//~va92R~
                    	fprintf(Sfhout,"+x%s\n",                   //~va92I~
    							ufileeditsz(UFEFSZ_HEXUPPER,offset+pos2,0));//~va30R~
                    }                                              //~va30I~
                	if (++ctr>=Smaxctr)
                    	uerrexit("Binary compare: %s and %s,\n UNMATCH reached to max(%d;default %d)",0,
									Sfnm1,Sfnm2,Smaxctr,MAXCTR);
                }
        totlen1+=readlen1;
        totlen2+=readlen2;
//printf("totlen1=%ld,totlen2=%ld,buffsz=%d\n",totlen1,totlen2,BUFFSZ);
        if (totlen1>=endoffs1)  //out of range
            break;
        if (totlen2>=endoffs2)  //out of range
            break;
        if (readlen1<BUFFSZ)
        	break;
        if (readlen2<BUFFSZ)
        	break;
    }

    if (totlen1<totlen2)
#ifdef LFSSUPP                                                     //~va30I~
    	uerrexit("file1 short(x%" FILESZ_EDIT "x < x%" FILESZ_EDIT "x),compare terminated",0,//~va30I~
					totlen1,totlen2);                              //~va30I~
#else                                                              //~va30I~
    	uerrexit("file1 short(x%lx < x%lx),compare terminated",0,
					totlen1,totlen2);
#endif                                                             //~va30I~
    if (totlen1>totlen2)
#ifdef LFSSUPP                                                     //~va30I~
    	uerrexit("file2 short(x%" FILESZ_EDIT "x < x%" FILESZ_EDIT "x),compare terminated",0,//~va30I~
					totlen2,totlen1);                              //~va30I~
#else                                                              //~va30I~
    	uerrexit("file2 short(x%lx < x%lx),compare terminated",0,
					totlen2,totlen1);
#endif                                                             //~va30I~

    fclose(fh1);
    fclose(fh2);
#ifdef LFSSUPP                                                     //~va30I~
//  printf("Binary compare: %s (x%" FILESZ_EDIT "x-x%" FILESZ_EDIT "x/x%" FILESZ_EDIT "x)"//~va92R~
//    uerrmsg("Binary compare: %s (x%" FILESZ_EDIT "x-x%" FILESZ_EDIT "x/x%" FILESZ_EDIT "x)"//~va94R~
//            " and %s file (x%" FILESZ_EDIT "x-x%" FILESZ_EDIT "x/x%" FILESZ_EDIT "x)\n",//~va94R~
//                Sfnm1,pos1,pos1+totlen1,fstat31.cbFile,          //~va94R~
//                Sfnm2,pos2,pos2+totlen2,fstat32.cbFile);         //~va94R~
	//*uerrmsg parm max=10,it is short for longlong(requires 2 word)//~va94I~
    fprintf(Sfhout,"Binary compare: %s (x%" FILESZ_EDIT "x-x%" FILESZ_EDIT "x/x%" FILESZ_EDIT "x)"//~va94I~
            " and %s file (x%" FILESZ_EDIT "x-x%" FILESZ_EDIT "x/x%" FILESZ_EDIT "x)\n",//~va94I~
                Sfnm1,pos1,pos1+totlen1,fstat31.cbFile,            //~va94I~
                Sfnm2,pos2,pos2+totlen2,fstat32.cbFile);           //~va94I~
#else                                                              //~va30I~
//  printf("Binary compare: %s (x%lx-x%lx/x%lx) and %s file (x%lx-x%lx/x%lx)\n",//~va92R~
    fprintf(Sfhout,"Binary compare: %s (x%lx-x%lx/x%lx) and %s file (x%lx-x%lx/x%lx)\n",//~va92I~
				Sfnm1,pos1,pos1+totlen1,fstat31.cbFile,
				Sfnm2,pos2,pos2+totlen2,fstat32.cbFile);
#endif                                                             //~va30I~
    if (ctr)
    {
//  	printf("  %d UNMATCH found\n",ctr);                        //~va92R~
    	fprintf(Sfhout,"  %d UNMATCH found\n",ctr);                //~va92I~
      if (!Snobellsw)                                              //~v150I~
        ubell();
        rc=3;                                                      //~v151R~
	}
    else
    {                                                              //~v151I~
//  	printf("  No unmatch found\n");                            //~v145R~
//  	printf("===== SAME is both =====\n");                      //~va30R~
//  	printf("===== SAME are both files =====\n");               //~va30I~//~va92R~
    	fprintf(Sfhout,"===== SAME are both files =====\n");       //~va92I~
        rc=0;                                                      //~v151R~
    }                                                              //~v151I~
//  return 0;                                                      //~v151R~
    return rc;                                                     //~v151I~
}//bincomp
//**********************************************************************
//* position to start offset
//* parm1:file name
//* parm2:file handle
//* parm3:fstat3
//* parm4:offset
//* rc   :offset
//**********************************************************************
ULONG binstartpos(char *Pfnm,FILE *Pfh,FILEFINDBUF3 *Pfstat3,ULONG Poffs)
{
//****************
    if (!Poffs)
        return 0;   //do nothing
    if (Poffs>=Pfstat3->cbFile)
		uerrexit("start offset x%lx is out of range of %s(size=x%lx)",0,
                    Poffs,Pfnm,Pfstat3->cbFile);
	if (fseek(Pfh,(long)Poffs,SEEK_SET))
		uerrexit("fseek failed for %s,offset=x%lx",0,
            			Pfnm,Poffs);
//printf("seek to %08lx\n",Poffs);
	return Poffs;
}//binstartpos
//**********************************************************************
//* open file name
//* parm1:open file name
//* parm2:open option
//* parm3:msg sw 0:no opened msg,1:display opened msg,-1:return if open err
//**********************************************************************
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw)
{
	FILE *file;
//****************
	if (!(file=fopen(Pfile,Popt)))
    {                                                              //~va14I~
    	if (Pmsgsw==-1)
        	return 0;
        else
			uerrexit("%s open failed rc=%d",0,
					Pfile,errno);
    }                                                              //~va14I~
	if (Pmsgsw==1)
    {                                                              //~va93I~
      if (Sfhout)                                                  //~va92I~
    	fprintf(Sfhout,"%s opened.",Pfile);                        //~va92R~
      else                                                         //~va92I~
    	printf("%s opened.",Pfile);
    }                                                              //~va93I~
	return file;
}//openfile
//*********************************************************************//~va79I~
//* open file RecordMode                                           //~va79I~
//*********************************************************************//~va79I~
FILE *openfilefv(char *Pfnm)                                       //~va79I~
{                                                                  //~va79I~
	FILE *fh;                                                      //~va79I~
    int buffsz,binopt;                                             //~va79R~
//***********************                                          //~va79I~
	fh=openfile(Pfnm,"rb",0);	//exit when open faile             //~va79I~
    binopt=UFGETS_BIN;                                 //~v107I~   //~va79I~
    if (Slrecl)                                                    //~va79I~
    {                                                              //~va79I~
    	binopt|=UFGETS_RECORD;	//record mode,split by LRECL//~va51I~//~va79I~
        buffsz=Slrecl;                                             //~va79I~
    }                                                              //~va79I~
    else                                                           //~va79I~
    {                                                              //~va79I~
    	binopt|=UFGETS_RV;	//record mode,split by LRECL           //~vaj0I~//~va79I~
	    binopt|=(Svfmt<<UFGETS_VFMTSHIFT);                 //~vaj0R~//~va79I~
    	buffsz=0; //ufgetsinit alloc 65536 for recfm=V             //~va79I~
    }                                                              //~va79I~
//  ufgetsinit(binopt,buffsz,0/*bin rate*/,0/*opt binwidth*/);     //~va79I~//~vaa0R~
    ufgetsinit(binopt,(unsigned)buffsz,0/*bin rate*/,0/*opt binwidth*/);//~vaa0I~
    return fh;                                                     //~va79I~
}                                                                  //~va79I~
//*********************************************************************//~va79I~
//* open file RecordMode                                           //~va79I~
//*********************************************************************//~va79I~
int readrecfv(char *Ppfnm,FILE *Ppfh,char *Pbuff,int Pline)        //~va79I~
{                                                                  //~va79I~
    int eolid,len,rc;                                              //~va79R~
    UINT ulen,ureqlen;                                             //~va79R~
//***********************                                          //~va79I~
//  ureqlen=Sbuffsz;	//Fix lrecl or max for Vfmt                //~va79I~//~vaa0R~
    ureqlen=(unsigned)Sbuffsz;	//Fix lrecl or max for Vfmt        //~vaa0I~
    rc=ufgets(Pbuff,ureqlen,Ppfh,&ulen,&eolid);                    //~va79I~
    UTRACEP("readrecfv ufgets rc=%d\n",rc);                        //~va79I~
    len=(int)ulen;                                                 //~va79I~
    UTRACED("readrecfv data",Pbuff,len);                           //~va79I~
    switch (rc)		//0 or 4 is ok                                 //~v09YI~//~va79I~
    {                                                              //~v09YI~//~va79I~
    case UFGETS_ERR:                                               //~v09YI~//~va79I~
        uerrexit ("%s:ufgets failed at lineNo %ld",0,              //~va79I~
        			Ppfnm,Pline);                                  //~va79I~
    case UFGETS_ERRV:   //recfm=V length err                       //~vaj0I~//~va79I~
        uerrexit ("%s:Vfmt err at lineNo %ld",0,                   //~va79I~
        			Ppfnm,Pline);                                  //~va79I~
    case UFGETS_EOF:                                               //~v09YI~//~va79I~
      	if (!len)                                                    //~v10aI~//~va79I~
			return -1;		//eof                                      //~v09YI~//~va79I~
        break;                                                     //~v10aI~//~va79I~
    case UFGETS_MORE:                                              //~va79I~
//      uerrexit ("%s:Too long record at %d (>%d)\n",0,            //~va79I~//~va9aR~
//      			Ppfnm,Pline,Sbuffsz);                          //~va79I~//~va9aR~
//      uerrexit("%s:Too long line(>%d) detected at %ld'th line of %s, Specify %cL option. Or use %cB(binary mode compare).",//~va9aI~//~va9uR~
        uerrexit("Too long line(>%d) detected at %ld'th line of %s, Specify %cL option. Or use %cB(binary mode compare).",//~va9uI~
                         "行長が長すぎます(>%d) ( %ld 行目:%s ), %cL を指定するか %cB(バイナリー比較)を指定してください",//~va9aI~
                                TXTBUFFSZ,Pline,Ppfnm,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~va9aR~
	default:	//normal                                           //~v103R~//~va79I~
    	if (Svfmt)                                                 //~va79I~
        {                                                      //~vaj0I~//~va79I~
            if (rc==UFGETS_RCMFH2)                             //~vaj0I~//~va79I~
            	Svfmt=UFGETS_VFMT_MFH2;                //~vaj0R~   //~va79I~
            else                                               //~vaj0I~//~va79I~
            if (rc==UFGETS_RCMFH4)                             //~vaj0I~//~va79I~
             	Svfmt=UFGETS_VFMT_MFH4;                //~vaj0R~   //~va79I~
        }                                                          //~vaj0I~//~va79I~
    }                                                              //~v09YI~//~va79I~
    return len;                                                    //~va79R~
}//readrecfv                                                       //~va79R~
//**********************************************************************
//* get input up to the size
//**********************************************************************
UINT getinput(char *Pfnm,FILE *Pfh,char *Pbuff,UINT Preqsz)
{
	UINT readlen;
//****************
//  readlen=fread(Pbuff,1,Preqsz,Pfh);	//read 1 block             //~vaa1R~
    readlen=(UINT)fread(Pbuff,1,Preqsz,Pfh);	//read 1 block     //~vaa1I~
//printf("read=%08x,req=%08x\n",readlen,Preqsz);
    if (readlen<Preqsz)
		if (ferror(Pfh))
        	uerrexit("\n%s read failed rc=%d,req=%d,read=%d",0,
						Pfnm,errno,Preqsz,readlen);
	return readlen;
}//getinput
//**********************************************************************
//*parameter chk
//**********************************************************************
void parmchk(int parmc,char *parmp[])
{
  	int parmno; //parm count work
  	int posparmno=0; //parm count work
    int marginsw=0;
    int omsw=0,ratesw=0;                                           //~v104R~
    char *fnm1,*fnm2,*cptr;
    char *pc;
    char *dirnm=NULL,*dirfnm;                                           //~v145R~//~va64R~
    char ch;                                                       //~va10I~
    FILEFINDBUF3 fstat31,fstat32;                                  //~v145I~
#ifdef W32UNICODE                                                  //~va93I~
#ifdef AAA                                                         //~va93I~
    char fnm1x[_MAX_PATH],fnm2x[_MAX_PATH];                        //~va93I~
#endif                                                             //~va93I~
#endif                                                             //~va93I~
	int swmaxlen=0;                                                //~va9cI~
    char wkfnm1[_MAX_PATH],wkfnm2[_MAX_PATH];                      //~va9dI~
    int rcen;                                                      //~va9dI~
    char *parmfnm1,*parmfnm2;                                      //~va9dI~
    int swfpathcopaypath=0,fecopt=0;                               //~va9iI~
    int swnocopypath=0;                                            //~va9jI~
//*************************
	fnm1=0;fnm2=0;                                                 //~va58R~
//	if (parmc<2 || *parmp[1]=='?')                                 //~va3aR~
  	if (parmc<2 || *parmp[1]=='?' || !strcmp(parmp[1],"--help"))   //~va3aI~
  	{
    	help();
//  	exit(4);                                                   //~va3aR~
    	exit(0);                                                   //~va3aI~
  	}
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
#ifdef UNX                                                         //~v143I~
  		if(*cptr=='-')                                             //~v143I~
#else                                                              //~v143I~
  		if(*cptr=='/'||*cptr=='-')
#endif                                                             //~v143I~
  		{//option
        	cptr++;		//dummy for compile warning
            switch(toupper(*cptr))
            {
            case '?':
                help();
                exit(0);
                break;
            case 'B':
                Sbinsw=1;
        		if (*(cptr+1))
	          		Smaxctr=atoi(cptr+1);
                break;
            case 'C':                                              //~v105I~
            	if (!stricmp(cptr,"CPU8"))                         //~vaj0R~
                {                                                  //~vaj0I~
#ifdef W32                                                         //~vaj0M~
    				uerrsetopt2(GBL_UERR2_OUTUTF8,0);              //~vaj0R~
#endif              //Linux ignore,xe may specify                  //~vaj0I~
                    break;                                         //~vaj0I~
                }                                                  //~vaj0I~
                Scmntsw=1;                                         //~v105I~
                if (*(cptr+1))                                     //~v105I~
                {                                                  //~va10I~
                    if (toupper(*(cptr+1))=='P')                   //~v105I~
                    {                                              //~va10I~
                        Scmntpsw=1;                                //~v105I~
	                    ch=*(cptr+2);                              //~va10R~
//                      if (ch>0x20 && ch <0x40 && !(ch>='0' && ch<='9'))//~va24R~
//                      if (ch>=0x20 && !isalnum(ch))              //~va25R~
                        	Scmntid=ch;                            //~va10I~
                        Scmntidstr=cptr+2;                         //~va25R~
                    }                                              //~va10I~
                    else                                           //~v105I~
                    if (toupper(*(cptr+1))=='N')                   //~v146I~
                    {                                              //~va10I~
                        Scmntnoprsw=1;                             //~v146I~
	                    ch=*(cptr+2);                              //~va10R~
//                      if (ch>0x20 && ch <0x40 && !(ch>='0' && ch<='9'))//~va24R~
//                      if (ch>=0x20 && !isalnum(ch))              //~va25R~
                        	Scmntid=ch;                            //~va10I~
                        Scmntidstr=cptr+2;                         //~va25R~
                    }                                              //~va10I~
                    else                                           //~v146I~
                    if (toupper(*(cptr+1))=='I')                   //~va12I~
                    {                                              //~va12I~
                        Scmntsw=2;  //ignore comment line input    //~va12I~
	                    ch=*(cptr+2);                              //~va12I~
//                      if (ch>0x20 && ch <0x40 && !(ch>='0' && ch<='9'))//~va24R~
//                      if (ch>=0x20 && !isalnum(ch))              //~va25R~
                        	Scmntid=ch;                            //~va12I~
                        Scmntidstr=cptr+2;                         //~va25R~
                    }                                              //~va12I~
                    else                                           //~va12I~
                    {                                              //~va10I~
	                    ch=*(cptr+1);                              //~va10R~
//                      if (ch>0x20 && ch <0x40 && !(ch>='0' && ch<='9'))//~va24R~
                        if (ch>=0x20 && !isalnum(ch))              //~va24I~
                        {                                          //~va12I~
//                      	if (*(cptr+2))                         //~va25R~
//  	                		optionerr("Comment sw",cptr); //c#i dmt//~va25R~
                        	Scmntid=ch;                            //~va10I~
    	                    Scmntidstr=cptr+2;                     //~va25R~
                        }                                          //~va12I~
                        else                                       //~va10I~
//              		optionerr("Print sw",cptr);                //~va12R~
		                	optionerr("Comment sw",cptr); //c#i dmt//~va12I~
                    }                                              //~va10I~
                }                                                  //~va10I~
                break;                                             //~v105I~
            case 'D':                                              //~va3dI~
	          	Sworddelmtb=cptr+1;                                //~va3dR~
                if (*Sworddelmtb=='\'')                            //~va3dR~
                {                                                  //~va3dI~
	                Sworddelmtb++;                                 //~va3dI~
                    *(Sworddelmtb+strlen(Sworddelmtb)-1)=0;        //~va3dI~
				}                                                  //~va3dI~
				printf("word delm specified(%s)\n",Sworddelmtb);   //~va3dI~
                break;                                             //~va3dI~
            case 'F':           //margin                           //~va79I~
	          	getrecordformat(cptr+1);                           //~va79R~
                break;                                             //~va79I~
            case 'L':           //margin                           //~va36I~
            	swmaxlen=1;                                        //~va9cI~
	          	TXTBUFFSZ=atoi(cptr+1);                            //~va36I~
                break;                                             //~va36I~
            case 'M':           //Lineno prefix                    //~va80R~
                if (toupper(*(cptr+1))=='P')                       //~va80I~
                {                                                  //~va80I~
                	int idx=0,digit;                               //~va80R~
	                pc=cptr+2;                                     //~va80I~
                    if (*pc=='1')                                  //~va80I~
                    	;                                          //~va80R~
                    else                                           //~va80I~
                    if (*pc=='2')                                  //~va80I~
                    	idx=1;                                     //~va80R~
                    else                                           //~va80I~
                		optionerr("Lineno prefix",cptr);           //~va80I~
                    pc++;                                          //~va80R~
                    digit=atoi(pc);                                //~va80I~
                    Slinenodigit[idx]=digit;                       //~va80R~
                	break;                                         //~va80I~
                }                                                  //~va80I~
            	marginsw=1;
                pc=strchr(cptr+1,'-');
                if (pc)
                {
                    *pc++=0;
		          	Smargin2=atoi(pc);
				}
                if (!*(cptr+1))
                    Smargin1=1;
                else
	          		Smargin1=atoi(cptr+1);
                if (Smargin1<=0
                ||  (Smargin2
					 && (Smargin2<=Smargin1 || Smargin2==1 || Smargin1>TXTBUFFSZ)))
                	optionerr("Margin",cptr);
                Smargin1--;			//offset value
//              if (Smargin2)                                      //~va3bR~
//              	Smargin2--;                                    //~va3bR~
//              else                                               //~va3bR~
//                  Smargin2=TXTBUFFSZ-1;                          //~va3bR~
//              if (!Smargin2)                                     //~va3bI~//~va9cR~
//                  Smargin2=TXTBUFFSZ-1;                          //~va3bI~//~va9cR~
//              Smarginw=Smargin2-Smargin1;                        //~va9cR~
                break;
            case 'O':			//output style
                omsw=1;         //parm specified
                Sostyle=toupper(*(cptr+1));
                switch(Sostyle)
                {
                case PRINT_FULL:    //F                            //~va4dI~
                	Sostyle=PRINT_BOTH;                            //~va4dR~
                    Sostyle2=PRINT_FULL;                           //~va4dI~
                    break;                                         //~va4dI~
                case PRINT_BOTH:    //B
                case PRINT_DIFF:    //D
                case PRINT_MERGE:   //M
                	break;
                default:
                	optionerr("Output style",cptr);
                }
                break;
#ifdef UNX                                                         //~v144I~
            case 'P':                                              //~v144I~
                Spcfile=1;      //ignore \r before \n              //~v144I~
                break;                                             //~v144I~
#endif                                                             //~v144I~
            case 'Q':                                              //~va92I~
				Sfhout=openfile(cptr+1,"w",0/*errmsg if err*/);    //~va92M~
                if (Sfhout)                                        //~va92I~
                {                                                  //~va92I~
                    uerrmsg_init(Spgmver,Sfhout,0);//msg to stdout //~va92I~
                    uerrexit_init(Spgmver,Sfhout,0,0,0);//stdout only,no pathmsg//~va92I~
                }                                                  //~va92I~
                break;                                             //~va92M~
            case 'R':
                ratesw=1;       //parm specified
                Scriteria=atoi(cptr+1);
        		if (Scriteria<0 || Scriteria>100)
                	optionerr("Matching level",cptr);
                break;
            case 'T':                                              //~v107I~
            	Stabdisp=*(cptr+1);	//if null no change orignal tab//~v107I~
                break;                                             //~v107I~
            case 'W':                                              //~v104I~
                Swordmatchingsw=1;                                 //~v104I~
//              if (*(cptr+1))                                     //~va3dR~
//              {                                                  //~va3dR~
            	for (pc=cptr+1;*pc;pc++)                           //~va3dI~
                {                                                  //~va3dI~
                	switch(toupper(*pc))                           //~va3dI~
                    {                                              //~va3dI~
//                  if (toupper(*(cptr+1))=='P')                   //~va3dR~
                    case 'P':                                      //~va3dI~
                        Swordpsw=1;                                //~v105R~
                        break;                                     //~va3dI~
                    case 'D':                                      //~va3dI~
                        Sworddelmsw=1;                             //~va3dI~
                        break;                                     //~va3dI~
//                  else                                           //~va3dR~
                    default:                                       //~va3dI~
                		optionerr("Print sw",cptr);                //~v105I~
                    }                                              //~va3dI~
                                                                   //~va3dI~
                }                                                  //~va14I~
                break;                                             //~v104I~
            case '=':           //print dir1 member only v1.3a     //~va9iI~
              	switch(toupper(*(cptr+1)))                         //~va9iI~
              	{                                                  //~va9iI~
              	case 'F':           //print dir1 member only v1.3a //~va9iI~
                	swfpathcopaypath=1;                            //~va9iI~
                	break;                                         //~va9iI~
              	case 'N':           //print dir1 member only v1.3a //~va9jI~
                	swnocopypath=1;                                //~va9jI~
                	break;                                         //~va9jI~
              	default:                                           //~va9iI~
                	optionerr("pathcopy by fullpath",cptr);        //~va9iI~
              	}                                                  //~va9iI~
              	break;            //v1.3a                          //~va9iI~
            case 'Y':
            	for (pc=cptr+1;*pc;pc++)
                {
                	switch(toupper(*pc))
                    {
                    case '9':                                      //~v150I~
                    	Sdbcssw=1;                                 //~v150I~
	                    UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set//~v150I~
    	                UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs //~v150I~
                        break;                                     //~v150I~
                    case 'A':                                      //~v150R~
                    	Snobellsw=0;	//alearm                   //~v150R~
						uerrexit_optinit(UERREXIT_BELL);	//bell when uerrexit//~va14I~
                        break;                                     //~v150I~
                    case 'M':                                      //~v152I~
                    	Snookmsg=0;		//no output ok msg         //~v152I~
                        break;                                     //~v152I~
                    default:                                       //~v150I~
                        *(pc+1)=0;                                 //~v150I~
                		optionerr("Toggle(Y/N) option",pc);        //~v150I~
                    }
                }
            	break;
            case 'N':
            	for (pc=cptr+1;*pc;pc++)
                {
                	switch(toupper(*pc))
                    {
                    case '9':
                    	Sdbcssw=0;
	                    UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set
    	                UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs
                        break;                                     //~v150I~
                    case 'A':                                      //~v150I~
                    	Snobellsw=1;	//alearm                   //~v150I~
						uerrexit_optinit(0);	//no bell when uerrexit//~va14R~
                        break;                                     //~v150I~
                    case 'M':                                      //~v152I~
                    	Snookmsg=1;		//no output ok msg         //~v152I~
                        break;                                     //~v152I~
                    default:                                       //~v150I~
                        *(pc+1)=0;                                 //~v150I~
                		optionerr("Toggle(Y/N) option",pc);        //~v150I~
                    }
                }
            	break;                                             //~v150I~
            default:                                               //~v150I~
                optionerr("Unknown option",cptr);                  //~v150I~
            	break;
            }
    	}//flag
      	else
      	{//positional parmno
        	posparmno++;
        	switch (posparmno)
        	{
        	case  1:          //first parm
          		fnm1=cptr;
                UTRACED("inp1",fnm1,(int)strlen(fnm1));                 //~va93R~//~vaa0R~
                Sendoffsp1=                                        //~va30I~
                getrange(fnm1,&Srange1s,&Srange1e);
          		break;
        	case  2:          //2nd
          		fnm2=cptr;
                UTRACED("inp2",fnm2,(int)strlen(fnm2));                 //~va93I~//~vaa0R~
                Sendoffsp2=                                        //~va30I~
                getrange(fnm2,&Srange2s,&Srange2e);
          		break;
            default:
              	uerrexit("too many positional parameter(%s)",0,cptr);
            }//switch by parmno
  		}//option or posparm
	}//for all parm
    if (posparmno<2)
        uerrexit("filename parameter missing",0);
    if (marginsw)                                                  //~va9cI~
    {                                                              //~va9cI~
        if (!Smargin2)                                             //~va9cI~
            Smargin2=TXTBUFFSZ;   //after /L was processed         //~va9cR~
        Smarginw=Smargin2-Smargin1;                                //~va9cI~
    }                                                              //~va9cI~
    else                                                           //~va9cI~
    if (swmaxlen)	//no margin and maxlen changed                 //~va9cI~
    {                                                              //~va9cI~
        Smargin2=TXTBUFFSZ;	//by specifiex max len                 //~va9cR~
        Smarginw=Smargin2;                                         //~va9cI~
    }                                                              //~va9cI~
//  fprintf(stderr,"marginsw=%d swmaxlen=%d,Smargin1=%d,Smargin2=%d,Smarginw=%d\n",marginsw,swmaxlen,Smargin1,Smargin2,Smarginw);//~va9cR~
#ifdef W32UNICODE                                                  //~va93I~
#ifdef AAA                                                         //~va93I~
	if (memchr(fnm1,UD_UTF8X,strlen(fnm1)))                        //~va93R~
    {                                                              //~va93I~
    	ufilecvUDX2UD(UFCVO_STRZ,fnm1,strlen(fnm1),fnm1x,sizeof(fnm1x),NULL/*outlen*/);//~va93R~
        fnm1=fnm1x;                                                //~va93I~
    }                                                              //~va93I~
	if (memchr(fnm2,UD_UTF8X,strlen(fnm2)))                        //~va93R~
    {                                                              //~va93I~
    	ufilecvUDX2UD(UFCVO_STRZ,fnm2,strlen(fnm2),fnm2x,sizeof(fnm2x),NULL/*outlen*/);//~va93R~
        fnm2=fnm2x;                                                //~va93I~
    }                                                              //~va93I~
#endif                                                             //~va93I~
#endif                                                             //~va93I~
//  rcen=fileeditname_copypath(0,fnm1,fnm2,wkfnm1,wkfnm2);         //~va9dR~//~va9iR~
  if (swnocopypath)                                                //~va9jI~
    rcen=0;                                                        //~va9jI~
  else                                                             //~va9jI~
  {                                                                //~va9jI~
	if (swfpathcopaypath)                                          //~va9iI~
        fecopt=FECO_FULLPATH;                                      //~va9iI~
    rcen=fileeditname_copypath(fecopt,fnm1,fnm2,wkfnm1,wkfnm2);    //~va9iR~
  }                                                                //~va9jI~
    parmfnm1=fnm1;                                                 //~va9dI~
    parmfnm2=fnm2;                                                 //~va9dI~
    if (rcen==1)   //fnm1 contains "="                             //~va9dI~
        fnm1=wkfnm1;                                               //~va9dR~
    else                                                           //~va9dI~
    if (rcen==2)   //fnm2 contains "="                             //~va9dI~
        fnm2=wkfnm2;                                               //~va9dR~
	if (!ufullpath(Sfnm1,fnm1,sizeof(Sfnm1)))
    	exit(8);
	if (!ufullpath(Sfnm2,fnm2,sizeof(Sfnm2)))
    	exit(8);
//chk filename on both fnm parm                                    //~v145I~
    if (ROOTDIR(Sfnm1))                                            //~v145I~
    	fstat31.attrFile |= FILE_DIRECTORY;		//fnm1 is directory//~v145I~
    else                                                           //~v145I~
    	if (ufstat(Sfnm1,&fstat31))                                //~v145R~
        {                                                          //~va9dI~
            if (rcen==-1)                                          //~va9dR~
    			fileeditname_copypath_err(FCEO_UERREXIT,parmfnm1,parmfnm2);//~va9dR~
    		uerrexit("%s not found",0,                             //~v145R~
						Sfnm1);                                    //~v145I~
        }                                                          //~va9dI~
    if (ROOTDIR(Sfnm2))                                            //~v145I~
    	fstat32.attrFile |= FILE_DIRECTORY;		//fnm1 is directory//~v145I~
    else                                                           //~v145I~
    	if (ufstat(Sfnm2,&fstat32))                                //~v145R~
        {                                                          //~va9dI~
            if (rcen==-2)                                          //~va9dR~
    			fileeditname_copypath_err(FCEO_UERREXIT,parmfnm1,parmfnm2);//~va9dR~
    		uerrexit("%s not found",0,                             //~v145R~
						Sfnm2);                                    //~v145I~
        }                                                          //~va9dI~
    dirfnm=0;                                                      //~v145I~
    if (fstat31.attrFile & FILE_DIRECTORY)		//fnm1 is directory//~v145I~
    	if (fstat32.attrFile & FILE_DIRECTORY)                     //~v145I~
//  		uerrexit("Both is directory",                          //~va30R~
    		uerrexit("Both are directory",                         //~va30I~
            		"両方ともディレクトリーです。");               //~v145I~
        else                //fnm1:dir,fnm2:file                   //~v145I~
        {                                                          //~v145I~
        	dirnm=Sfnm1;                                           //~v145I~
			dirfnm=Sfnm2;                                          //~v145I~
		}                                                          //~v145I~
    else    //fnm1 is file                                         //~v145I~
    	if (fstat32.attrFile & FILE_DIRECTORY)                     //~v145I~
        {                                                          //~v145I~
        	dirnm=Sfnm2;                                           //~v145I~
			dirfnm=Sfnm1;                                          //~v145R~
		}                                                          //~v145I~
    if (dirfnm)                                                    //~v145I~
    {                                                              //~va14I~
        if (ROOTDIR(dirnm))                                        //~v145I~
        	strcat(dirnm,dirfnm+PATHLEN(dirfnm));                  //~v145I~
        else                                                       //~v145I~
        	strcat(dirnm,dirfnm+PATHLEN(dirfnm)-1);                //~v145I~
    }                                                              //~va14I~
    if (Sbinsw)
        if (marginsw||omsw||ratesw||Swordmatchingsw||Scmntsw)      //~v105R~
			uerrexit("%cM,%cO,%cR,%cW,%cC option is inconsistent with %cB\n",//~v145R~
  					"%cM,%cO,%cR,%cW,%cC オプションと %cB オプションは両立しません\n",//~v145R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,//~v145I~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v145I~
	if (Scriteria)
    	Slvl=2;
    if (!Sfhout)                                                   //~va92I~
    	Sfhout=stdout;	//for common fprintf                       //~va92I~
}//parmchk
//**********************************************************************
//* get input range specification
//* return 1:if endoffset parm exist                               //~va30I~
//**********************************************************************
//void getrange(char *Pfnm,ULONG *Ppranges,ULONG *Pprangee)        //~va30R~
int getrange(char *Pfnm,ULONG *Ppranges,ULONG *Pprangee)           //~va30I~
{
	char *pc0,*pc,*pc2,*pc20;
    ULONG rs,re;
    int xsw=0;                                                     //~v100I~
    int rc=0;                                                      //~va30I~
//*************
//  pc0=pc=strchr(Pfnm,'/');                                       //~v143R~
    pc0=pc=strchr(Pfnm,RPREFIX);                                   //~v143I~
    if (!pc)
//  	return;             //leave static int 0                   //~va30R~
    	return 0;           //leave static int 0                   //~va30I~
//range1
    pc++;               //skip /
    pc20=pc2=strchr(pc,'-');      //end range
    if (pc2)
        *(pc2++)=0;
    if (*pc=='x' || *pc=='X')
    {
        if (ux2l(pc+1,&rs)) //hex err
        {                                                          //~va9dI~
      		chksamepathparm(Pfnm,pc0);                             //~va9dI~
            optionerr("input range",pc0);
        }                                                          //~va9dI~
        xsw=1;                                                     //~v100I~
    }
    else
    {
        if (*pc)
        {
        	if ((int)strlen(pc)!=unumlen(pc,0,8))
            {                                                      //~va9dI~
	      		chksamepathparm(Pfnm,pc0);                         //~va9dI~
            	optionerr("input range",pc0);
            }                                                      //~va9dI~
        	rs=(ULONG)atol(pc);
        }
        else
        	rs=0;
    }
//range2
    if (!pc2)               //no range2
        re=ULMAX;          //max value
    else
        if (*pc2=='x' || *pc2=='X')                                //~v100R~
        {                                                          //~v100R~
            if (ux2l(pc2+1,&re)) //hex err                         //~v100R~
            {                                                      //~va9dI~
	      		chksamepathparm(Pfnm,pc0);                         //~va9dI~
                optionerr("input range",pc2);                      //~v100R~
            }                                                      //~va9dI~
            rc=1;   //end offset specified                         //~va30I~
        }                                                          //~v100R~
        else                                                       //~v100I~
            if (xsw)                                               //~v100I~
            {                                                      //~v100I~
                if (ux2l(pc2,&re)) //hex err                       //~v100I~
                {                                                  //~va9dI~
	      			chksamepathparm(Pfnm,pc0);                     //~va9dI~
                    optionerr("input range",pc2);                  //~v100I~
                }                                                  //~va9dI~
	            rc=1;   //end offset specified                     //~va30I~
            }                                                      //~v100I~
            else                                                   //~v100R~
            {                                                      //~v100R~
                if (*pc2)                                          //~v100R~
                {                                                  //~v100R~
                    if ((int)strlen(pc2)!=unumlen(pc2,0,8))        //~v100R~
                    {                                              //~va9dI~
	      				chksamepathparm(Pfnm,pc0);                 //~va9dI~
                        optionerr("input range",pc2);              //~v100R~
                    }                                              //~va9dI~
                    re=(ULONG)atol(pc2);                           //~v100R~
		            rc=1;   //end offset specified                 //~va30I~
                }                                                  //~v100R~
                else                                               //~v100R~
                    re=ULMAX;          //max value                 //~v100R~
            }                                                      //~v100R~
//printf("start=%08lx,end=%08lx\n",rs,re);
	if (pc20)
    	*pc20='-';
	if (rs>=re)
    {                                                              //~va9dI~
      	chksamepathparm(Pfnm,pc0);                                 //~va9dR~
    	optionerr("input range",pc0);
    }                                                              //~va9dI~
	*pc0=0;		//filename only
	*Ppranges=rs;
	*Pprangee=re;
//	return;                                                        //~va30R~
  	return rc;                                                     //~va30I~
}//getrange
//**********************************************************************//~va79I~
//* get -F parameter(record format)                                //~va79I~
//**********************************************************************//~va79I~
void getrecordformat(char *Pfmt)                                   //~va79I~
{                                                                  //~va79I~
	int vfmt,lrecl=0,rc;                                           //~va79R~
//****************                                                 //~va79I~
	rc=ufile5chkvfmt(0,Pfmt,&vfmt);                                //~va79I~
    if (rc)                                                        //~va79I~
    {                                                              //~va79I~
    	lrecl=atoi(Pfmt);                                          //~va79I~
        if (!lrecl||(int)strlen(Pfmt)!=unumlen(Pfmt,0,8))          //~va79R~
            optionerr("Record Format is not numeric and not varid Vfmt",Pfmt);//~va79I~
	    Slrecl=lrecl;                                              //~va79I~
	    Svfmt=0;                                                   //~va79I~
    }                                                              //~va79I~
    else                                                           //~va79I~
    {                                                              //~va79I~
	    Svfmt=vfmt;                                                //~va79R~
	    Slrecl=0;                                                  //~va79I~
    }                                                              //~va79I~
//  printf("vfmt=%d,lrecl=%d",0,Svfmt,Slrecl);                     //~va79R~
}//getrecordformat                                                 //~va79R~
//**********************************************************************
//* write option err msg
//**********************************************************************
void optionerr(char *Ptype,char* Pvalue)
{
	uerrexit("invalid %s option parm value(%s)\n",
  			"%s の値が無効です(%s)\n",
			Ptype,Pvalue);
  	return;
}//optionerr
//**********************************************************************//~va9dI~
//*rc:1:contains "=",0:not contains "=" or Linux                   //~va9dI~
//**********************************************************************//~va9dI~
int chksamepathparm(char *Pfnm,char *Prangeparm)                   //~va9dR~
{                                                                  //~va9dI~
#ifdef UNX //rangeparm follow ":"                                  //~va9dI~
	return 0;	//range parm err                                   //~va9dI~
#else                                                              //~va9dI~
	UTRACEP("chksamepathparm %s-%s\n",Pfnm,Prangeparm);            //~va9dI~
//    if (!strchr(Pfnm,ID_SAMEPATH))//no "=" found                 //~va9dR~
//        return 0;   //range parm err                             //~va9dR~
    uerrmsg("\"/\" is path separator on Unix, it is xfc's \"input range\" parm separator on Windows.",//~va9dR~
    		"\"/\" は Unixでのパス分離文字です, Windows での xfc は \"比較の範囲\"指定の分離文字として使用しています");//~va9dR~
    return 1;                                                      //~va9dI~
#endif                                                             //~va9dI~
}//chksamepathparm                                                 //~va9dR~
//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
//**********************
#define HELPMSG uerrhelpmsg(stdout,stderr,
//**********************
HELPMSG
"%s:%s(%c): file comapre utility program\n",                       //~v100R~
"%s:%s(%c): ファイル比較ユーティリティー\n",PGM,VER,OSTYPE);       //~v100R~
HELPMSG
"format:\n",
"形式  :\n");
HELPMSG
" %s  filename1[%crange1] filename2[%crange2] [%coptions]\n",      //~v143R~
" %s  filename1[%crange1] filename2[%crange2] [%coptions]\n",      //~v143R~
			PGM,RPREFIX,RPREFIX,CMDFLAG_PREFIX);                   //~v143R~
        HELPMSG                                                    //~va66I~
"*******************************************************************************\n", //80 column limit indicator//~va66I~
"*******************************************************************************\n");//~va66I~
HELPMSG
"   filename1,2:filename to be compared.\n",                       //~v143R~
"   filename1,2:比較対象ファイル.\n");                             //~v143R~
HELPMSG                                                            //~va9dI~
"              :last filename is ommittable when last name is the same.\n",//~va9dR~
"              :ファイル名が同じなら一方はパス名のみでもよい\n");  //~va9dI~
HELPMSG                                                            //~va9dI~
"              :cnveniently use the letter \"=\" which means same path.\n",//~va9dR~
"              :パス名に\"=\"を指定することで指定を簡略化できる\n");//~va9dI~
HELPMSG                                                            //~va9dI~
"              :format n=[m] : n=skip count(0--9,default=0), m=copy count.\n",//~va9dR~
"              :形式 n=[m] : n=スキップ数(0--9,省略値=0), m=コピー数\n");//~va9dR~
HELPMSG                                                            //~va9dI~
//"              :See example below.\n",                             //~va9dI~//~va9iR~
//"              :下記の例を参照\n");                                //~va9dI~//~va9iR~
"              :See example below. %c=F is a related option.\n",   //~va9iI~
"              :下記の例を参照。%c=Fも関連オプションです。\n" ,    //~va9iR~
					CMDFLAG_PREFIX);                               //~va9iI~
HELPMSG
"   range1,2   :input range to compare by line(for text file,start from 1)\n",//~v143R~
"   range1,2   :比較の範囲を行(テキスファイルの場合, 1 から開始)または\n");//~v143R~
HELPMSG
"              :or by offset(for binary file,start from 0).\n",
"              :オフセット値(バイナリーファイルの場合, 0 から開始)を指定.\n");
HELPMSG
"   %cBn        :do binary compare;n is unmatch ctr to stop compare.default=%d.\n",//~v143R~
"   %cBn        :バイナリー比較を実行;n は比較中止の不一致バイト数.省略値=%d.\n",//~v143R~
					CMDFLAG_PREFIX,                                //~v143I~
					MAXCTR);
#ifdef W32                                                         //~vaj0I~
HELPMSG                                                            //~vaj0I~
"   %cCPU8      :(Win)for XE, msg by UTF8 code.\n",                //~vaj0R~
"   %cCPU8      :(Win)XE 用、メッセージをUTF8 コードで出力\n",     //~vaj0R~
					CMDFLAG_PREFIX);                               //~vaj0R~
#endif                                                             //~vaj0I~
//HELPMSG                                                          //~va10R~
//"   %cC[P|N]    :ignore diff in C++ comment(after '//') except full comment line.\n",//~va10R~
//"   %cC[P|N]    :コメント行以外のC++スタイルのコメント('//で開始')の違いを無視.\n",//~va10R~
//					CMDFLAG_PREFIX);                               //~va10R~
HELPMSG                                                            //~va10I~
"   %cC[P|N|I][xx]:chk comment. x:comment start id string(ex #,!. default:'//').\n",//~va3bR~
"   %cC[P|N|I][xx]:コメントの扱い。x:コメント開始文字列(#,!等。省略値は//)。\n",//~va25R~
					CMDFLAG_PREFIX);                               //~va10I~
//HELPMSG                                                          //~va10R~
//"              :P:means output those lines.(identified by '=C').\n",//~va10R~
//"              :P:一致するとみなした行も出力する。'=C'で識別される.\n");//~va10R~
HELPMSG                                                            //~va10I~
"              :P:output lines with id of '=C' if unmatch is comment only.\n",//~va12R~
"              :P:コメントのみの不一致行も出力する。'=C'で識別される。\n");//~va12R~
//HELPMSG                                                          //~va10R~
//"              :N:unmatched comment and null line is not printed.\n",//~va10R~
//"              :N:不一致の空白行、コメント行は出力しない.\n");   //~va10R~
HELPMSG                                                            //~va10I~
"              :N:No output lines if unmatch is comment only.\n",  //~va12R~
"              :N:コメントのみの相違は不一致リスト出力しない。\n");//~va12R~
HELPMSG                                                            //~va12I~
"              :I:full comment line or Null/Space line is ignored.\n",//~va12R~
"              :I:コメントのみ行、あるいは空白行は無視する。\n");  //~va12R~
HELPMSG                                                            //~va10I~
"              :else:ignore unmatch of comment except full comment line.\n",//~va12R~
"              :以外 :コメントのみの行でなければコメントの不一致は無視。\n");//~va12R~
HELPMSG                                                            //~va3dI~
"   %cD'xx'     :Delimiters for %cWD.\n",                          //~va3dR~
"   %cD'xx'     :%cWD使用時の分離文字の省略値を変更する。\n",      //~va3dR~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~va3dI~
HELPMSG                                                            //~va79I~
"   %cF{nn|vfmt}:record Format.\n",                                //~va79R~
"   %cF{nn|vfmt}:レコード形式\n",                                  //~va79R~
					CMDFLAG_PREFIX);                               //~va79R~
HELPMSG                                                            //~va79I~
"              :nn:record length of LRECL=F.\n",                   //~va79R~
"              :nn:固定長形式のレコード長\n");                     //~va79R~
HELPMSG                                                            //~va79I~
"              :vfmt:following variable record header format.\n",  //~va79I~
"              :vfmt:以下の可変長形式のレコードヘッダ形式\n");     //~va79R~
HELPMSG                                                            //~va79I~
"              :%s(llzz),%s(MicroFocus),%s(2bytes),%s(DataOnlyLength).\n",//~va79R~
"              :%s(llzz),%s(MicroFocus),%s(2バイト),%s(データのみの長さ)\n",//~va79R~
                VFMT_DEFAULT,VFMT_MFH,VFMT_HW,VFMT_HWDATA);        //~va79I~
HELPMSG                                                            //~va79I~
"              :F(4bytes,length=4+DataLength),FD(DataOnlyLength).\n",//~va79I~
"              :F(4バイト,値は4+データ長),FD(データのみの長さ)\n", //~va79R~
                VFMT_FW,VFMT_FWDATA);                              //~va79I~
HELPMSG                                                            //~va36I~
"   %cLnn       :Text compare max line size.\n",                   //~va36I~
"   %cLnn       :テキストファイルの最大行長.\n",                   //~va36I~
					CMDFLAG_PREFIX);                               //~va36I~
HELPMSG
"   %cMm-n      :compare column range in the line(Text file compare only).\n",//~v143R~
"   %cMm-n      :行内の比較対象範囲を桁位置指定(テキストF比較でのみ有効).\n",//~v143R~
					CMDFLAG_PREFIX);                               //~v143I~
HELPMSG                                                            //~va80I~
"   %cMP{1|2}n  :top of line of {1st|2nd} file is n-digit lineNo.\n",//~va80I~
"   %cMP{1|2}n  :{1番目|2番目}のファイルの各行先頭が n 桁行番号.\n",//~va80I~
					CMDFLAG_PREFIX);                               //~va80I~
HELPMSG
"   %cOstyle    :output style,Default is %cOd.(Text file compare only)\n",//~v143R~
"   %cOstyle    :出力様式、省略値は %cOd(テキストF比較でのみ有効).\n",//~v143R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v143I~
HELPMSG
"              :style=D:difference only,M:2 files merged,B:both files.\n",
"              :style=D:不一致行のみ,M:両ファイルのマージ,B:両ファイル別々に.\n");
                                                                   //~v144I~
HELPMSG                                                            //~va4dI~
"              :      F:Full print both files.\n",                 //~va4dR~
"              :      F:両ファイル別々に全行出力\n");              //~va4dR~
#ifdef UNX                                                         //~v144I~
HELPMSG                                                            //~v144I~
"   %cP         :PC file comapre(ignore CR before LF)\n",          //~v144I~
"   %cP         :PCファイル比較（改行コードCRLFのCRを無視する）\n",//~v144I~
					CMDFLAG_PREFIX);                               //~v144I~
#endif                                                             //~v144I~
                                                                   //~v144I~
HELPMSG                                                            //~va92M~
"   %cQoutfile  :redirect all output to this file\n",              //~va92R~
"   %cQoutfile  :出力を全てこのファイルに書き出す\n",              //~va92R~
					CMDFLAG_PREFIX);                               //~va92M~
                                                                   //~v144I~//~va4dI~//~va92M~
HELPMSG
"   %cRnn       :Assume as update line pair when matching char is over this rate\n",//~v143R~
"   %cRnn       :1行内の一致する文字の割合がこの指定を越える時更新行とみなす\n",//~v143R~
					CMDFLAG_PREFIX);                               //~v143I~
HELPMSG
"              :in a line. Specify digit 0 to 100. 0 means all unmatched line\n",//~va3pR~
"              :0-->100の数字を指定. 0 とすると不一致行はすべて削除または\n");
HELPMSG
"              :is ISRTed or DLETed.(Text file compare only,default is %cR%d).\n",//~v143R~
"              :挿入と\x95\\示(テキストF比較でのみ有効,省略値は%cR%d).\n",//~v143R~
				CMDFLAG_PREFIX,MAXRATE);                           //~v143R~
HELPMSG                                                            //~v107I~
"   %cT[x]      :Char to replace tab on output list.\n",           //~v143R~
"   %cT[x]      :出力リスト上でタブを置き換える文字。\n",          //~v143R~
					CMDFLAG_PREFIX);                               //~v143I~
HELPMSG                                                            //~v107I~
"              :Default is \"%cT.\"(period),leave tab when \"%cT\"(with no char)\n",//~v143R~
"              :省略値は \"%cT.\"(ピリオド)、\"%cT\" でタブ文字をそのまま出力。\n",//~v143R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v143I~
HELPMSG                                                            //~v104I~
//"   %cW[P]      :Word matcghing(ignore intermediate space or tab)\n",//~va3dR~
//"   %cW[P]      :語句比較(連続するスペース、タブを 1 文字として比較)\n",//~va3dR~
"   %cW[D][P]   :Word matching(ignore intermediate space or tab)\n",//~va3pR~//~va9iR~
"   %cW[D][P]   :語句比較(連続するスペース、タブを 1 文字として比較)\n",//~va3dR~//~va9iR~
					CMDFLAG_PREFIX);                               //~v143I~
HELPMSG                                                            //~va3dI~
"              :D:ignore space/tab of before/after delimiters(default:\"%s\").\n",//~va3dR~
"              :D:分離文字(省略値:\"%s\")の前後のスペース/タブは無視する。\n",//~va3dR~
				Sworddelmtb);                                      //~va3dI~
HELPMSG                                                            //~v105I~
"              :P:means output those lines.(identified by '=W',\n",//~v105R~
"              :P:一致するとみなした行も出力する。'=W'で識別される,\n");//~v105I~
HELPMSG                                                            //~v105I~
"              :  '=w' is for the line by %cW and %cC).\n",        //~v143R~
"              :  '=w' は %cW と %cC で一致するとした行.\n",       //~v143R~
					CMDFLAG_PREFIX,CMDFLAG_PREFIX);                //~v143I~
HELPMSG                                                            //~va9iI~
//"   %c=F        :Apply \"=\"(copy filespec path) to fullpath name\n",//~va9iR~//~va9jR~
//"   %c=F        :\"=\"(ファイル名のパスのコピー)をフルパス名に適用する\n",//~va9iR~//~va9jR~
"   %c={F|N}    :F:Apply \"=\"(copy filespec path) to fullpath name\n",//~va9jI~
"   %c={F|N}    :F:\"=\"(ファイル名のパスのコピー)をフルパス名に適用する\n",//~va9jI~
					CMDFLAG_PREFIX);                               //~va9iI~
HELPMSG                                                            //~va9jI~
"              :N:ignores \"=\".\n",                               //~va9jI~
"              :N:\"=\"は無視する\n");                             //~va9jI~
#ifdef UNX                                                         //~va9iI~
HELPMSG                                                            //~va9iI~
"              :(ex) %s  %c=F a/b/c  /tmp/1=  (cd=/home/you)\n",   //~va9iR~
"              :(例) %s  %c=F a/b/c  /tmp/1=  (cd=/home/you)\n",   //~va9iR~
		PGM,CMDFLAG_PREFIX);                                       //~va9iI~
HELPMSG                                                            //~va9iI~
"              :     ===> %s /home/you/a/b/c  /tmp/you/a/b/c\n",   //~va9iR~
"              :     ===> %s /home/you/a/b/c  /tmp/you/a/b/c\n",   //~va9iR~
		PGM);                                                      //~va9iI~
#else                                                              //~va9iI~
HELPMSG                                                            //~va9iI~
"              :(ex) %s  %c=F a\\b\\c  D:\\tmp\\2=  (cd=C:\\home\\you)\n",//~va9iR~
"              :(例) %s  %c=F a\\b\\c  D:\\tmp\\2=  (cd=C:\\home\\you)\n",//~va9iR~
		PGM,CMDFLAG_PREFIX);                                       //~va9iI~
HELPMSG                                                            //~va9iI~
"              :     ===> %s C:\\home\\you\\a\\b\\c  D:\\tmp\\you\\a\\b\\c\n",//~va9iR~
"              :     ===> %s C:\\home\\you\\a\\b\\c  D:\\tmp\\you\\a\\b\\c\n",//~va9iR~
		PGM);                                                      //~va9iI~
#endif                                                             //~va9iI~
HELPMSG                                                            //~v150I~
//"   %cNb        :No err alarm.\n",                               //~v153R~
//"   %cNb        :エラーのときアラームを鳴らさない。\n",          //~v153R~
"   %cNa        :No err alarm.\n",                                 //~v153I~
"   %cNa        :エラーのときアラームを鳴らさない。\n",            //~v153I~
					CMDFLAG_PREFIX);                               //~v150I~
HELPMSG                                                            //~v152I~
"   %cNm        :No msg output when successful compare.\n",        //~va3pR~
"   %cNm        :比較OKの時のMSGを出力しない。\n",                 //~v152R~
					CMDFLAG_PREFIX);                               //~v152I~
HELPMSG                                                            //~va11M~
"   ReturnCode :0:Match. 1:Null detected even if text file compare option.\n",//~va11M~
"   戻りコード :0:一致。 1:テキストファイル比較オプションでNULLを検知。\n");//~va11M~
HELPMSG                                                            //~va11M~
"              :2:Unmatch is comment only under %cCN option.\n",   //~va11M~
"              :2:%cCNオプションのときで不一致はコメントのみ。\n", //~va11M~
					CMDFLAG_PREFIX);                               //~va11M~
HELPMSG                                                            //~va11M~
"              :3:Unmatch detected. >=4: other err.\n",            //~va11M~
"              :3:不一致有。 >=4:その他のエラー。\n");             //~va11M~
HELPMSG
"ex)  %s  old.c  new.c\n",
"例   %s  old.c  new.c\n",
		PGM);
HELPMSG
"     %s  old.exe  new.exe  %cB\n",                                //~v143R~
"     %s  old.exe  new.exe  %cB\n",                                //~v143R~
		PGM,CMDFLAG_PREFIX);                                       //~v143R~
HELPMSG
"     %s  old.txt%c1-200  new.txt%c11-  %cM1-72  %cOb %cW\n",      //~v143R~
"     %s  old.txt%c1-200  new.txt%c11-  %cM1-72  %cOb %cW\n",      //~v143R~
		PGM,RPREFIX,RPREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v143R~
HELPMSG
"     %s  old.bin%cx2f0-300  new.bin%cx2f1-3f1  %cB20\n",          //~v143R~
"     %s  old.bin%cx2f0-300  new.bin%cx2f1-3f1  %cB20\n",          //~v143R~
		PGM,RPREFIX,RPREFIX,CMDFLAG_PREFIX);                       //~v143R~
#ifdef UNX                                                         //~va9dI~
HELPMSG                                                            //~va9dI~
"     %s  a/b/c/d/e/f/g  x/=\n",                                   //~va9dR~
"     %s  a/b/c/d/e/f/g  x/=\n",                                   //~va9dI~
		PGM);                                                      //~va9dI~
HELPMSG                                                            //~va9dI~
"         ===> %s a/b/c/d/e/f/g  x/a/b/c/d/e/f/g\n",               //~va9dR~
"         ===> %s a/b/c/d/e/f/g  x/a/b/c/d/e/f/g\n",               //~va9dR~
		PGM);                                                      //~va9dI~
#else                                                              //~va9dI~
HELPMSG                                                            //~va9dI~
"     %s  a\\b\\c\\d\\e\\f\\g  x\\=\n",                            //~va9dI~
"     %s  a\\b\\c\\d\\e\\f\\g  x\\=\n",                            //~va9dI~
		PGM);                                                      //~va9dI~
HELPMSG                                                            //~va9dI~
"         ===> %s a\\b\\c\\d\\e\\f\\g  x\\a\\b\\c\\d\\e\\f\\g\n",  //~va9dR~
"         ===> %s a\\b\\c\\d\\e\\f\\g  x\\a\\b\\c\\d\\e\\f\\g\n",  //~va9dI~
		PGM);                                                      //~va9dI~
#endif                                                             //~va9dI~
#ifdef UNX                                                         //~va9dM~
HELPMSG                                                            //~va9dM~
"     %s /a/b/c/d/e/f/g  /x/1=\n",                                 //~va9dI~
"     %s /a/b/c/d/e/f/g  /x/1=\n",                                 //~va9dI~
		PGM);                                                      //~va9dM~
HELPMSG                                                            //~va9dM~
"         ===> %s /a/b/c/d/e/f/g  /x/b/c/d/e/f/g\n",               //~va9dI~
"         ===> %s /a/b/c/d/e/f/g  /x/b/c/d/e/f/g\n",               //~va9dI~
		PGM);                                                      //~va9dM~
#else                                                              //~va9dM~
HELPMSG                                                            //~va9dM~
"     %s \\a\\b\\c\\d\\e\\f\\g  \\x\\1=\n",                        //~va9dI~
"     %s \\a\\b\\c\\d\\e\\f\\g  \\x\\1=\n",                        //~va9dI~
		PGM);                                                      //~va9dM~
HELPMSG                                                            //~va9dM~
"         ===> %s \\a\\b\\c\\d\\e\\f\\g  \\x\\b\\c\\d\\e\\f\\g\n", //~va9dI~
"         ===> %s \\a\\b\\c\\d\\e\\f\\g  \\x\\b\\c\\d\\e\\f\\g\n", //~va9dI~
		PGM);                                                      //~va9dM~
#endif                                                             //~va9dM~
#ifdef UNX                                                         //~va9dI~
HELPMSG                                                            //~va9dI~
"     %s /a/b/c/d/e/f/g  /x/2=3/z\n",                              //~va9dR~
"     %s /a/b/c/d/e/f/g  /x/2=3/z\n",                              //~va9dR~
		PGM);                                                      //~va9dI~
HELPMSG                                                            //~va9dI~
"         ===> %s /a/b/c/d/e/f/g  /x/c/d/e/z\n",                   //~va9dR~
"         ===> %s /a/b/c/d/e/f/g  /x/c/d/e/z\n",                   //~va9dR~
		PGM);                                                      //~va9dI~
#else                                                              //~va9dI~
HELPMSG                                                            //~va9dI~
"     %s \\a\\b\\c\\d\\e\\f\\g  2=3\\z\n",                         //~va9dR~
"     %s \\a\\b\\c\\d\\e\\f\\g  2=3\\z\n",                         //~va9dR~
		PGM);                                                      //~va9dI~
HELPMSG                                                            //~va9dI~
"         ===> %s \\a\\b\\c\\d\\e\\f\\g  c\\d\\e\\z\n",            //~va9dR~
"         ===> %s \\a\\b\\c\\d\\e\\f\\g  c\\d\\e\\z\n",            //~va9dR~
		PGM);                                                      //~va9dI~
#endif                                                             //~va9dI~
HELPMSG                                                            //~va3aI~//~va9dR~
" --- %s  End Of Help ---\n",                                      //~va3aR~
" --- %s  End Of Help ---\n",                                      //~va3aI~
		PGM);                                                      //~va3aI~
}//help
