//CID://+va8iR~:        update#=     4;                            //+va8iR~
//****************************************************************
//xchar2.h
//****************************************************************
//va8i:101011 bnds sort;add SBCS option for BNDS sort without dbcs consideration//+va8iI~
//va8h:101010 bnds sort;set space to split dbcs except dbcs continued case//~va8hI~
//va7y:100823 EBC:handle support for cap                           //~va7yI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3S:100322 (BUG)"S" lcmd replace split dbcs to space,it should be avoid when split on vhex line//~va3SI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v74E:070315 BOUNDS cmd support(find,shift-lcmd,paste-lcmd)       //~v74EI~
//v74j:070216 (BUG)C&P del fail by join fail for margined file.    //~v74jI~
//            (by remaining oom of 1st line;delete oom for 1stline for region cut)//~v74jI~
//v67V:060227 copy on/niche:reverse only updated line              //~v67VI~
//v676:051226 cut & paste;margined file(COBOL etc) consideration(ignore space cut by margin)//~v676I~
//v66f:051021 support standard mode cut & paste,assign Ctrl+v for stream insert.(split xecap.c to xecap2.c)//~v66fI~
//                     None   OpenBlock  ClosedBlock   OpenRegion ClosedRegion//~v66fI~
//            C+v    RgnIns   NoBlockErr BlockClearRep OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Ins  BlockIns NoBlockErr GetBlock+Ins  OpenRgnErr RgnDel+Ins//~v66fI~
//            A+Rep  BlockRep NoBlockErr GetBlock+Rep  OpenRgnErr RgnDel+Ins//~v66fI~
//v58s:040923 niche option for copy edit cmd(n:override target line by not space char of src line)//~v58sI~
//v168:000418 add table format function to TC/TCN cmd              //~v168I~
//v163:000410 func to set line data from string.(reviced fro charcap(line to line)).//~v163I~
//v0i7:980520 line cmd split cmd('S')/join('J') support            //~v0i7I~
//v0bo:970727 allow crlf pos del key to concatinate line           //~v0boI~
//            reverse of splitline split.                          //~v0boI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//v06M:960424:hi-lighten insert line by cut and paste              //~v06MI~
//**************************************************************** //~v06MI~
                                                                //~5211I~
//****************************************************************//~5211I~
int charcap(PUCLIENTWE Ppcw,int Pmode,PULINEH Pplhs,PULINEH Pplhd,int Poffs);//~5211R~
#define CHAROPON   	0 		//copy on                           //~5211R~
#define CHAROPBREP 	1       //block override                    //~5211I~
#define CHAROPBINS 	2       //block insert	                    //~5211R~
#define CHAROPNICHE 3      //copy n (override from non space char) //~v58sR~
#define CHAROPLCMD  0x0100 //called by lcmd                        //~v74EI~
                                                                //~5211I~
//**************************************************************** //~v163I~
int charcap2(PUCLIENTWE Ppcw,int Pmode,UCHAR *Pdata,UCHAR *Pdbcs,int Psrclen,//~v163R~
				PULINEH Pplhd,int Poffs);                          //~v163I~
#define CHARCAP2_UNDO		0x0100	//issue undo prepare;over Pmode of charcap//~v163I~
#define CHARCAP2_OVFCUT 	0x0200	//cut data if margin verflow   //~v163R~
#define CHARCAP2_NOREV  	0x0400	//no reverse option            //~v168I~
#define CHARCAP2_IGNOVFSPC  0x0800	//noset rc=1 if overflow cut is all space//~v676I~
#ifdef UTF8UCS2                                                    //~va20I~
	#define CHARCAP2_OPMODEMASK            0xff                    //~va20I~
	#define CHARCAP2_SRCU8               0x1000   //modechange required,src data is dd fmt//~va20R~
	#define CHARCAP2_SRCLC               0x2000   //modechange required,src data is locale code//~va20R~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define CHARCAP2_SRCEB               0x4000   //modechange required,src data is ebcdic code//~va50I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~va20R~
	#define CHARCAP2_EBCHANDLEP  0x00008000   //handle parameter   //~va7yI~
	#define CHARCAP2_HANDLEMASK  0x00070000   //ebc converter handle(00->07)//~va7yI~
	#define CHARCAP2_HANDLEMASK_SHIFT  16      //handle shift count//~va7yI~
	#define CHARCAP2_GETHANDLE(opt)  ((((opt) & CHARCAP2_HANDLEMASK))>>CHARCAP2_HANDLEMASK_SHIFT)//~va7yI~
	#define CHARCAP2_SETHANDLE(handle)  (((handle)<<CHARCAP2_HANDLEMASK_SHIFT) & CHARCAP2_HANDLEMASK)//~va7yI~
	#define CHARCAP2_EBCBNDSSORT 0x00100000   //rep for bnds sort  //~va8hR~
	#define CHARCAP2_SBCS        0x00200000   //no consideration for dbcs split by bnds setting//+va8iI~
//**************************************************************** //~v06MI~
void charcaprev(PULINEH Pplh,int Poffs,int Plen);                  //~v06MR~
                                                                   //~v0boI~
//**************************************************************** //~v0boI~
int charconcatline(PUCLIENTWE Ppcw,PULINEH Pplh,PULINEH Pplhnext); //~v0boI~
                                                                   //~v0i7I~
//*******************************************************          //~v0i7I~
//int charlcmdsplit(PUCLIENTWE Ppcw,PULINEH Pplh);                 //~v66fR~
//int charlcmdsplit(PUCLIENTWE Ppcw,PULINEH Pplh,int Ppos);        //~v74jR~
int charlcmdsplit(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,int Ppos); //~v74jI~
#define CLS_IGM        0x01 //ignore margin                        //~v74jI~
#define CLS_LCSPLITVX  0x02 //lcmd "S" start from vhexline         //~va3SR~
                                                                   //~v67VI~
//*******************************************************          //~v67VI~
void chartabrep(char *Ppcd,char *Ppcde);                           //~v67VR~
