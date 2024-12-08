//*CID://+vauFR~:**              update#=    1221                  //+vauFR~
//**************************************************************** //~v13pI~
//*xefcmd23.h                                                      //~v13pI~
//**************************************************************** //~v13pI~
//vauF:140316 (Win)find on dirlist by ddstrsrch(LNX:vaui)          //+vauFI~
//vaui:140311 find on dirlist by ddstrsrch                         //~vauiI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va5w:100517 panutil:keep utf8 codetype over session              //~va5wI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//            fcmd23.c:search on dd str                            //~va20I~
//v78r:080326 profile function                                     //~v78rI~
//v74W:070407 split cmd bnds/margin support                        //~v74WI~
//v74N:070328 keep bnds parm for also filename                     //~v74NI~
//v74E:070315 BOUNDS cmd support                                   //~v74EI~
//v635:050428 move fcmdgetstartplhoffs from xefcmd2.c xefcmd23.c   //~v635I~
//v43g:011030 save each find word len for multiple word search case//~v43gI~
//            (spanded or *& case)                                 //~v43gI~
//v13p:991106 find/rep consideration for bin file                  //~v13pI~
//**************************************************************** //~v13pI~
#define OFFS_TOP       -1   //start from top line                  //~v635M~
#define OFFS_LAST      -2   //start from top line                  //~v635M~
#define OFFS_ULNEXT    -3   //ulsearch nextline step is already done//~v635M~
//**************************************************************** //~v74EI~
#define BNDS_ADJUSTPOS(bndsoffs1,bndsoffs2,pos)   \
    {\
    	if (bndsoffs1>=0)	/*bnds left specified*/ \
			if (pos<bndsoffs1) /*left of left bnds*/ \
	        	pos=bndsoffs1;                       \
	    if (bndsoffs2>0 && pos>=bndsoffs2) /*right of right bnds */\
        	pos=bndsoffs1;                                          \
    }                                                              //~v74EI~
//**************************************************************** //~v74EI~
typedef struct _BNDSTBL {                                          //~v74EI~
                        UQUEE  BNDSTqe;         //enq chain        //~v74EI~
						int    BNDSTflag;                          //~v74EI~
#define BNDSTF_DIR      0x01      //dirname entry                  //~v74ER~
#define BNDSTF_FILE     0x02      //filename entry                 //~v74NR~
						UCHAR *BNDSTextname;		//filename extension//~v74ER~
						int    BNDSTcol1;                          //~v74EI~
						int    BNDSTcol2;                          //~v74EI~
#define BNDST_NOLIMIT   0                                          //~v74ER~
					  	} BNDSTBL,*PBNDSTBL;                       //~v74ER~
#define BNDSTSZ sizeof(BNDSTBL)                                    //~v74EI~
//**************************************************************** //~v635I~
int fcmdsplitsrch(PULINEH Pplh,int Poffset,char *Psrch,int Psrchlen,//~v13pR~
                    int Ptabsrchsw,int Pdirection,int Pcasesw,UCHAR **Ppos,//~v13pR~
					PULINEH *Pwordplh,UCHAR **Pwordend);           //~v13pR~
//**************************************************************** //~v13pI~
int fcmdsplitrep(PUCLIENTWE Ppcw,PULINEH Pplh,int Pspanlen);       //~v13pI~
//**************************************************************** //~v13pI~
int fcmdsplitdisplay(PUFILEH Ppfh,PULINEH Pplh,PULINEH Plastplh,int Poffs,int Plen,int Plocatesw);//~v43gR~
//**************************************************************** //~v13pI~
int fcmdnextofspan(int *Poffs,int Pstep,PULINEH *Ppplh);           //~v13pI~
//**************************************************************** //~v74EI~
int fcmdbndstupdate(int Popt,char *Pfnm,int Pcol1,int Pcol2);      //~v74ER~
#define FCBND_ADD    0x01 //allow Pfnm widthout "."                //~v74ER~
#define FCBND_DEL    0x02                                          //~v74ER~
#define FCBND_UPD    0x04                                          //~v74ER~
#define FCBND_DIR    0x10                                          //~v74ER~
#define FCBND_PATH   0x20                                          //~v74ER~
#define FCBND_FILE   0x40                                          //~v74NI~
#define FCBND_EXT    0x80                                          //~v78rR~
//**************************************************************** //~v74EI~
void fcmdbndstfree(void);                                          //~v74ER~
//**************************************************************** //~v74EI~
int fcmdbndstgettop(PBNDSTBL *Ppbndst);                            //~v74EI~
//**************************************************************** //~v74EI~
int fcmdbndsset(PUFILEH Ppfh);                                     //~v74EI~
//**************************************************************** //~v74WI~
int fcmdgetbnds(int Popt,PUFILEH Ppfh,int *Ppbndsoffs1,int *Ppbndsoffs2);//~v74WI~
#define FCBGRC_BNDS         1                                      //~v74WI~
#define FCBGRC_MARGIN       2                                      //~v74WI~
#ifdef UTF8UCS2                                                    //~va20R~
//**************************************************************** //~va20R~
char *fcmdddstrsrch(int Popt,PULINEH Pplh,UCHAR *Psrchstr,UCHAR *Psrchdbcs,int Psrchstrlen,char *Pdata,int Poffset,int *Ppwordlen);//~va20R~
    #define  FCMDDDSSO_NEXT    0x01  //forward                     //~va20I~
    #define  FCMDDDSSO_PREV    0x02  //backward                    //~va20I~
    #define  FCMDDDSSO_ESC     0x04  //escape string(binary string) search//~va20I~
    #define  FCMDDDSSO_NOCASE  0x08  //case insensitive            //~va20R~
    #define  FCMDDDSSO_DDSTR   0x10  //ddstr search                //~va20I~
//**************************************************************** //~va50I~
int fcmdddstrcmp(int Popt,PULINEH Pplh1,int Ppos1,PULINEH Pplh2,int Ppos2,int Plen);//~va20I~
    #define  FCMDDDSCO_NOCASE  0x01  //case insensitive            //~va20R~
//**************************************************************** //~va20I~
int fcmdsearchoncmdbuff(int Popt,UCHAR *Psrchstr,int Psrchstrlen,UCHAR **Pplc,UCHAR **Ppct,UCHAR **Ppdbcs);//~va20R~//~va5wR~
//**************************************************************** //~va20I~
int fcmdcvl2fsrchstr(int Popt,PUCLIENTWE Ppcw,UCHAR *Psrch,int Psrchlen,UCHAR *Putf8str,int Putf8buffsz,int *Ppoutu8len);//~va20R~
//**************************************************************** //~va20I~
//int fcmdsetupddsrch(int Popt,UCHAR *Psrchu8,int Psrchlenu8);       //~va20I~//~va79R~
int fcmdsetupddsrch(int Popt,int Phandle,UCHAR *Psrchu8,int Psrchlenu8);//~va79I~
//**************************************************************** //~va20I~
int fcmdisddsrch(int Popt,PUCLIENTWE Ppcw,UCHAR **Ppddstr,UCHAR **Ppdddbc);//~va20R~
//**************************************************************** //~va50I~
int fcmdddescrep(int Popt,PULINEH Pplh,int Poffs,int Psrchlen,UCHAR *Prepword,int Prepwordlen,//~va20I~
				UCHAR *Poutdd,UCHAR *Poutdbcs,int Poutbuffsz,int *Ppoutlen);//~va20I~
#define  FCERDDRC_LEFT  0x01      //left boundary changed          //~va20M~
#define  FCERDDRC_RIGHT 0x02      //right boundary changed         //~va20M~
//**************************************************************** //~va20I~
int fcmdescsrchinit(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);        //~va20M~
#define FCESI_LOCATE       0x01                                    //~va20M~
#define FCESI_CHANGE       0x02                                    //~va20M~
#define FCESI_FIND         0x04                                    //~va20M~
//**************************************************************** //~va20I~
int fcmdcvesc2dd(int Popt,UCHAR *Pescchar,int Plen,UCHAR *Pescdd,UCHAR *Pescdbcs,int Poutbuffsz,int *Pescddlen);//~va20I~
#ifdef UTF8EBCD                                                    //~va50I~
//**************************************************************** //~va50I~
	int fcmdgetebcsrchstr(int Popt,PUCLIENTWE Ppcw,UCHAR **Ppddstr,UCHAR **Ppdddbcs,int *Ppesclen);//~va50I~
//**************************************************************** //~va20I~//~va50M~
    int fcmd_savelcctforerrmsg(int Popt,int Ptype,UCHAR *Ppu8,int Plenu8,UCHAR **Pppct,UCHAR **Pppcd,int Plenlc);//~va50R~
    #define FCSCFEMO_SAVECT       0x01                             //~va50R~
    #define FCSCFEMO_GETCT        0x02                             //~va50R~
    #define FCSCFEMO_CT2INI       0x04                             //~va50R~
    #define FCSCFEMO_INI2CT       0x08                             //~va50R~
    #define FCSCFEMO_SETCTPREFIX  0x10                             //~va50I~
    #define FCSCFEMO_TRIM         0x20                             //~va50I~
    #define FCSCFEMO_INICTID      0xFF                             //~va50R~
//**************************************************************** //~va5wI~
	int fcmd_bitcodetype(int Popt,char *Pcodetype,char *Pbitarray,int Pctlen,int Pbitarraysz);//~va5wI~
	#define  FCBCO_2BIT           0x01                             //~va5wI~
	#define  FCBCO_2CT            0x02                             //~va5wI~
#endif                                                             //~va50I~
#endif                                                             //~va20R~
//#ifdef LNX                                                         //~vauiI~//+vauFR~
	char *fcmdddstrsrch_dir(int Popt,UCHAR *Psrchstr,UCHAR *Psrchdbcs,int Psrchstrlen,char *Pdata,char *Pdbcs,int Pddlen,int *Ppoffs);//~vauiR~
//#endif                                                             //~vauiI~//+vauFR~
