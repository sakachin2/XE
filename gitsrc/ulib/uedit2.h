//CID://+v6XcR~:         update#=     7;                           //~v6D2R~//~v6XcR~
//*******************************************************          //~v163I~
//*uedit2.h                                                        //~v5i5R~
//*******************************************************          //~v163I~
//v6Xc:180823 add ueditescrep,process \a,\x..                      //~v6XcI~
//v6D2:160423 LNX compiler warning for bitmask assignment(FDATE,FTIE)//~v6D2I~
//v6Bf:160211 add uedit2:uxdumpstr                                 //~v6BfI~
//v6d7:120209 (SMB)adjust for target:Windows                       //~v6d7I~
//v5ig:060620 add convert macro;char to hex char                   //~v5igI~
//v5i9:060601 (LNX:UTF)support UTF8 for other than japanese        //~v5i9I~
//v5i5:060505 (XDA)print ucs code                                  //~v5i5I~
//v5cz:040522 date/time edit func for locate cmd                   //~v5czI~
//v59e:031103 ftp support(4 byte udirlist attr for ! UNX)          //~v59eI~
//v50Q:010915 UNX:edit file attr for other than xe(rwxd/lugt fmt)  //~v50QR~
//v50G:010618 LNX:disket support(using mtools)                     //~v50GI~
//v333 000904:LINUX support(file attr size 1-->4)                  //~v333I~
//v256:990626 seg:off display for dump of DOS                      //~v256I~
//v217:990108 disas:change v216;for current buff addr use same value//~v217I~
//v216:990108 disas:base 0 id(-1)                                  //~v216I~
//v207:981220 add uxdumpline                                       //~v207I~
//v195:980920 display attr/size on xdd list                        //~v195I~
//v163:980301 add uasciidump                                       //~v163I~
//*******************************************************          //~v163I~
typedef struct _XDUMPLINEPRM {                                     //~v207I~
                            UCHAR *XDLPinpbuff;                    //~v207I~
                            UCHAR *XDLPoutbuff;                    //~v207I~
                            UCHAR *XDLPvirtual;  //virtual addr    //~v217R~
                            FILE  *XDLPfh;       //output fh       //~v207I~
                            ULONG  XDLPlen;  	 //input length    //~v207R~
                            int    XDLPhexpos;	 //spece intermediate//~v207R~
                            int    XDLPcharpos;	 //space intermediate//~v207R~
                            USHORT XDLPdosseg;      //seg value for DOS//~v256I~
                            USHORT XDLPdossegr;      //relocation seg value for DOS//~v256I~
                            UCHAR  XDLPdelm1;		//delimeter of char dump//~v256M~
                            UCHAR  XDLPdelm2;		//delimeter of char dump//~v256M~
                            UCHAR  XDLPopt;                        //~v207R~
#define XDLP_2ND    	0x01    					//once called  //~v207R~
#define XDLP_DBCS   	0x02                                       //~v207R~
#define XDLP_KANA   	0x04                                       //~v207R~
#define XDLP_32     	0x08    					//32 byte dump //~v207R~
#define XDLP_UPPER 	   	0x10    					//upper case hex digit//~v207R~
#define XDLP_NOTLAST   	0x20    					//last line call to put same line data//~v207R~
#define XDLP_DOSSEG    	0x40    					//print seg:off fmt addr//~v256I~
#define XDLP_UCS       	0x80    					//print ucs code converted to sjis//~v5i5I~
                                                                   //~v5i5I~
#define XDLP_UCSSPACE  	 2      					//space between ascii dump//~v5i5I~
                            UCHAR  XDLPrsv;                        //~v256R~
                } XDUMPLINEPRM,*PXDUMPLINEPRM;                     //~v207R~
#define CH2HEXU(ch,pc)  \
        (               \
         *(pc  )=(char)( ( ((ch>>4) & 0x0f) <10 ? '0' : 'A'-10 )+((ch>>4) & 0x0f) ),\
         *(pc+1)=(char)( ( ( ch & 0x0f    ) <10 ? '0' : 'A'-10 )+( ch & 0x0f)     ) \
        )                                                          //~v5igR~
#define CH2HEXL(ch,pc)  \
        (               \
         *(pc  )=(char)( ( ((ch>>4) & 0x0f) <10 ? '0' : 'a'-10 )+((ch>>4) & 0x0f) ),\
         *(pc+1)=(char)( ( ( ch & 0x0f    ) <10 ? '0' : 'a'-10 )+( ch & 0x0f)     ) \
        )                                                          //~v5igR~
//*******************************************************          //~v207I~
int uasciidump(int Popt,UCHAR *Pout,UCHAR *Pinp,int Pinplen);      //~v163I~
int uasciidump_utf(int Popt,UCHAR *Pout,UCHAR *Pinp,int Pinplen);  //~v5i9I~
#define UAD_DBCS		0x01		//dbcs chk                     //~v163R~
#define UAD_KANA		0x02		//kana chk                     //~v163R~
#define UAD_LLASTDBCS	0x04		//leave last dbcs split        //~v163I~
#define UAD_LATIN   	0x08		//print 0x80-0xff              //~v5i9M~
#define UAD_ALLUTF  	0x10		//all valid utf                //~v5i9I~
//*******************************************************          //~v5i5I~
int uucsdump(int Popt,UCHAR *Pout,UCHAR *Pinp,int Pprintlen,int Pinplen);//~v5i5I~
#define UUD_DBCS		0x01		//dbcs chk                     //~v5i5I~
#define UUD_NORETRY 	0x02		//try from top byte only       //~v5i5I~
//*******************************************************          //~v163I~
int ub2x(int Popt,UCHAR *Pout,void *Pinp,int Plen);                //~v163R~
#define UBX_UPPER    0                                             //~v163I~
#define UBX_LOWER    1                                             //~v163I~
//*******************************************************          //~v195I~
//#ifdef UNX                                                       //~v59eR~
void ueditfattr(ULONG Pattr,UCHAR *Pout,int Popt);                 //~v333I~
//#else                                                            //~v59eR~
//void ueditfattr(UCHAR Pattr,UCHAR *Pout,int Popt);               //~v59eR~
//#endif                                                           //~v59eR~
#define UEFA_SZ   0x01          //set last 0                       //~v195I~
#define UEFA_DIR  0x02          //chk and set dir attr             //~v195I~
#ifdef UNX                                                         //~v50GI~
	#define UEFA_MDOS 0x04          //mdos file  attr              //~v50GR~
#endif                                                             //~v59eI~
	#define UEFA_UFMT 0x08          //@dsgt fmt output             //~v50QI~
#define UEFA_RWIN 0x10          //remote is windows                //~v6d7I~
//#endif                                                           //~v59eR~
//*******************************************************          //~v207I~
int uxdumpline(PXDUMPLINEPRM Ppxdlp);                              //~v207I~
//*******************************************************          //~v5czI~
int ugetdtparm(UCHAR *Pdata,void /*FDATE*/ *Ppfdate,void /*FTIME*/ *Ppftime);//~v5czR~
//*******************************************************          //~v5czI~
int ugetdateparm(UCHAR *Pdata,void /*FDATE*/ *Ppfdate);            //~v5czR~
//*******************************************************          //~v5czI~
int ugettimeparm(UCHAR *Pdata,void /*FDATE*/ *Ppftime);            //~v5czR~
//*******************************************************          //~v5czI~
int ueditsetfdate(int Pyy,int Pmm,int Pdd,void /*FDATE*/ *Ppfdate);//~v5czR~
//*******************************************************          //~v5czI~
int ueditsetftime(int Phh,int Pmm,int Pss,void /*FTIME*/ *Ppftime);//~v5czI~
//*******************************************************          //~v6BfI~
int uxdumpstr(int Popt,char *Pinp,int Plen,char *Pout,int Pbuffsz,int *Ppoutlen);//~v6BfI~
#define UXDSO_LOWER       0x01      //lower char('a' for 10)       //~v6BfI~
#define UXDSO_OUTSTRZ     0x02      //add null at last             //~v6BfI~
#ifdef MAKE_FTIME   //ufile.h is included                          //~v6D2I~
//*******************************************************          //~v6D2I~
int ueditsetfdateUSHORT(int Popt,int Pyy,int Pmm,int Pdd,FDATE *Ppfdate);//~v6D2R~
//*******************************************************          //~v6D2I~
int ueditsetftimeUSHORT(int Popt,int Phh,int Pmm,int Pss,FTIME *Ppftime);//~v6D2R~
//*******************************************************          //~v6T2I~//~v6D2M~
int ueditNowFileTime(int Popt,FDATE *Ppfdate,FTIME *Ppftime);      //~v6T2I~//~v6D2M~
#endif                                                             //~v6D2I~
int ueditescrep(int Popt,char *Pin,int Plen,char *Pout,int Pbuffsz,int *Ppoutlen);//~v6XcI~
#define UEERO_NULLERR  0x01     //err if contains \x00             //~v6XcI~
#define UEERO_MSG      0x02     //err msg                          //+v6XcI~
