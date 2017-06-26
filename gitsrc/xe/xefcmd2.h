//*CID://+vbCBR~:                             update#=   69;       //~vbCBR~
//****************************************************************
//*xefcmd2.h
//****************************************************************//~v064I~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //~vaz0I~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1G:091118 (UTF8)add UTF8 trans err char Find/Change function   //~va1GI~
//v79V:081028 save and restore search word(A+[) between sessions.  //~v79VI~
//v76m:070627 find support on =1/=2 filename list panel            //~v76mI~
//v74F:070322 add NX option for Find/Change as alternative of fnx/cnx//~v74FI~
//v635:050428 move fcmdgetstartplhoffs from xefcmd2.c xefcmd23.c   //~v635I~
//v632:050427 find cmd;support grepline search by *G               //~v62dI~
//v62d:050312 matching cmd;find *= col1 col2 & ^* col3 col4        //~v62dI~
//v62a:050311 -m[n] option of find cmd to keep previous reverse;n:multi rev from next//~v62aI~
//v61s:050306 for multiple found reverse support;change structure of mfwtbl(offs,len,next entry offset ushort count)//~v61sI~
//v537:030920 find/change allkx option(keep excluded)              //~v537I~
//v49b:020623 support *= for not only "(i)x all" but also "(i)find"//~v49bI~
//v47i:020302 join cmd support:"join nx/x .a .b"                   //~v47iM~
//            join cmd use getstartoffs(-->fcmdgetstartplhoffs)    //~v47iM~
//v43h:011030 (BUG)no highlight pair when on the same line         //~v43hI~
//v43g:011030 save each find word len for multiple word search case//~v43gI~
//            (spanded or *& case)                                 //~v43gI~
//v0ew:970922 split fcmd2 to fcmd22                                //~v0ewI~
//v064:960217:split inifile for Ginitscroll/Giniopt_/Ginifiletabskip//~v064I~
//****************************************************************
#ifdef DOS                                                         //~v43gM~
	#ifdef DPMI                                                    //~v43gM~
		#define MAXMFWTENTRY 100                                   //~v43gM~
    #else                                                          //~v43gM~
		#define MAXMFWTENTRY 1000                                  //~v43gM~
    #endif                                                         //~v43gM~
#else                                                              //~v43gM~
	#define MAXMFWTENTRY 1000                                      //~v43gI~
#endif                                                             //~v43gM~
                                                                   //~v61sI~
#define MFWTENTSZ  3                //rev start offs,revlen,next entry offs ctr//~v61sR~
#define MFWTBLSZ    (MAXMFWTENTRY*MFWTENTSZ)	//table size       //~v61sI~
                                                                   //~v43gI~
#define SUBCMD_FIRST 1                                             //~v0ewM~
#define SUBCMD_LAST  2                                             //~v0ewM~
#define SUBCMD_NEXT  3                                             //~v0ewM~
#define SUBCMD_PREV  4                                             //~v0ewM~
#define SUBCMD_ALL   5                                             //~v0ewM~
#define SUBCMD_ALLKX 6                                             //~v537I~
                                                                   //~v0ewM~
#define LINE_SAMESRCH  3   	//3:same line search(not x *= all case)//~v49bM~
#define LINE_RESEARCH  4   	//4:latest line re-search(must be 4;0 by "& 3" operation)//~v49bM~
#define LINE_SAMEMATCH 5   	//matching                             //~v62dI~
#define LINE_GREPSEARCH  6   	//grepline search                  //~v62dI~
                                                                   //~v635I~
#define RC_EXC_ALL  	2                                          //~v635I~
#define RC_STOP_SRCH  121   //stop all search by join fail etc     //~v635I~
#define RC_ERR_NOTNF  122   //not err,but later errmsg             //~v635I~
                                                                   //~v635I~
#define EOLSRCHID  "\\n"        //eol search id                    //~v635I~
#define EOLIDLEN   2                                               //~v635I~
#define EOLSRCHIDANY  "*\\n"        //eol search without preceding strng specification//~v635I~
#define EOLSRCHIDAST  "\"*\"\\n"    //search * at eol              //~v635I~
#define MATCHINGID   'M'            //"*=M"                        //~v635I~
#define CMDFIND         0                                          //~vbCBI~
#define CMDCHANGE       1                                          //~vbCBI~
//**************************************************************** //~v635I~
#ifdef  XEFCMD2_GLOBAL                                             //~v635I~
  #define FCMD2GBL_EXT                                             //~v635I~
  #define FCMD2GBL_INIT(value) =value                              //~v635I~
#else                                                              //~v635I~
  #define FCMD2GBL_EXT extern                                      //~v635R~
  #define FCMD2GBL_INIT(value)                                     //~v635I~
#endif                                                             //~v635I~
#define  SRCHIDS_UTF8ECH         "*EC"   //utf8 trans err char search option//~va1GI~
#define  SRCHIDS_UTF8ECHR        "*"    //reset utf8 err id        //~va1GR~
FCMD2GBL_EXT  UCHAR *Sulsrchid FCMD2GBL_INIT((UCHAR*)"*U");        //~v635R~
FCMD2GBL_EXT  UCHAR *Selsrchid FCMD2GBL_INIT((UCHAR*)"*E");        //~v635R~
FCMD2GBL_EXT  UCHAR *Sllsrchid FCMD2GBL_INIT((UCHAR*)"*L");  //research last line search//~v635R~
FCMD2GBL_EXT  UCHAR *Sgrepsrchid FCMD2GBL_INIT((UCHAR*)"*G");  //search grepline//~v635R~
FCMD2GBL_EXT  UCHAR Seqsrchid[3] FCMD2GBL_INIT("*=");              //~v635R~
FCMD2GBL_EXT  UCHAR Smatchingid[4] FCMD2GBL_INIT("*=M");           //~v635R~
FCMD2GBL_EXT  char Ssrch[MAXCOLUMN];                               //~v635I~
FCMD2GBL_EXT  char Ssrch2[MAXCOLUMN]; 	//for *&,2nd word          //~v635I~
FCMD2GBL_EXT  char Srepword[MAXCOLUMN];                            //~v635I~
FCMD2GBL_EXT  int  Ssrchlen FCMD2GBL_INIT(0);                      //~v635I~
FCMD2GBL_EXT  int  Ssrchlen2 FCMD2GBL_INIT(0);                     //~v635I~
#ifdef UTF8UCS2                                                    //~va20I~
FCMD2GBL_EXT  char Gsrchdd[MAXCOLUMN];                             //~va20I~
FCMD2GBL_EXT  char Gsrchdd2[MAXCOLUMN]; 	//for *&,2nd word      //~va20I~
FCMD2GBL_EXT  char Gsrchdbcs[MAXCOLUMN];                           //~va20I~
FCMD2GBL_EXT  char Gsrchdbcs2[MAXCOLUMN]; 	//for *&,2nd word      //~va20I~
FCMD2GBL_EXT  char Grepworddd[MAXCOLUMN]; 	//for *&,2nd word      //~va20I~
FCMD2GBL_EXT  char Grepworddbcs[MAXCOLUMN];                        //~va20I~
FCMD2GBL_EXT  int  Gsrchlenu8 FCMD2GBL_INIT(0);                    //~va20R~
FCMD2GBL_EXT  int  Gsrchlenu82 FCMD2GBL_INIT(0);                   //~va20R~
FCMD2GBL_EXT  int  Gsrchlendd FCMD2GBL_INIT(0);                    //~va20I~
FCMD2GBL_EXT  int  Gsrchlendd2 FCMD2GBL_INIT(0);                   //~va20R~
FCMD2GBL_EXT  int  Grepwordlenu8 FCMD2GBL_INIT(0);                 //~va20I~
FCMD2GBL_EXT  int  Grepwordlendd FCMD2GBL_INIT(0);                 //~va20I~
                                                                   //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
    FCMD2GBL_EXT  char Gsrchebcdata[MAXCOLUMN];                    //~va50I~
    FCMD2GBL_EXT  char Gsrchebcdata2[MAXCOLUMN];    //for *&,2nd word//~va50I~
    FCMD2GBL_EXT  char Gsrchebcdbcs[MAXCOLUMN];                    //~va50I~
    FCMD2GBL_EXT  char Gsrchebcdbcs2[MAXCOLUMN];    //for *&,2nd word//~va50I~
    FCMD2GBL_EXT  char Grepwordebcdata[MAXCOLUMN];   //for *&,2nd word//~va50R~
    FCMD2GBL_EXT  char Grepwordebcdbcs[MAXCOLUMN];                 //~va50R~
    FCMD2GBL_EXT  int  Gsrchebclen FCMD2GBL_INIT(0);               //~va50I~
    FCMD2GBL_EXT  int  Gsrchebclen2 FCMD2GBL_INIT(0);              //~va50I~
    FCMD2GBL_EXT  int  Grepwordebclen FCMD2GBL_INIT(0);            //~va50I~
    FCMD2GBL_EXT  int  Gebchandle FCMD2GBL_INIT(0);                //~va79I~
    FCMD2GBL_EXT  int  Gebchandle2 FCMD2GBL_INIT(0);               //~va79I~
    FCMD2GBL_EXT  int  Gebchandler FCMD2GBL_INIT(0);               //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~va20I~
FCMD2GBL_EXT  char Seolsrchsw FCMD2GBL_INIT(0),Seolsrchsw2 FCMD2GBL_INIT(0);		//eol req id//~v635I~
FCMD2GBL_EXT  int  Srepwordlen;                                    //~v635I~
FCMD2GBL_EXT  int  Ssubcmdid FCMD2GBL_INIT(0);                     //~v635I~
FCMD2GBL_EXT  int  Scasesensesw;		//case sensitive sw        //~v635I~
FCMD2GBL_EXT  int  Schangeopt FCMD2GBL_INIT(0);	//for rchange after rfind//~v635I~
FCMD2GBL_EXT 	int Spfhfindctr FCMD2GBL_INIT(0);                  //~v635I~
FCMD2GBL_EXT 	PUFILEH Spfhmatching FCMD2GBL_INIT(0);	//2nd scr pfh for matching//~v635I~
FCMD2GBL_EXT 	int  Sallkxinpctr FCMD2GBL_INIT(0);                //~v635I~
FCMD2GBL_EXT 	int  S2ndofallsw FCMD2GBL_INIT(0); //2nd search of all//~v635I~
FCMD2GBL_EXT 	PULINEH Sfoundplh FCMD2GBL_INIT(0);	//found line   //~v635I~
FCMD2GBL_EXT 	PULINEH Splhafter FCMD2GBL_INIT(0);	//plh by -a option,0 if before found plh//~v635I~
FCMD2GBL_EXT 	int  Sfoundoffs FCMD2GBL_INIT(0);	//found word top offset//~v635I~
FCMD2GBL_EXT 	int  Sstep FCMD2GBL_INIT(0);			//for rfind/rchange step//~v635I~
FCMD2GBL_EXT 	int  Sdirstep FCMD2GBL_INIT(0);		//step after dir list filename find//~v635I~
FCMD2GBL_EXT 	int  Sdirstepr FCMD2GBL_INIT(0); 	//for reverse serch//~v635I~
FCMD2GBL_EXT 	int  Sfoundctr FCMD2GBL_INIT(0);		//found count//~v635I~
FCMD2GBL_EXT 	int  Gmfwtovf FCMD2GBL_INIT(0);		//found count at Gfilemfwtbl overflow//~v635R~
FCMD2GBL_EXT  LONG Sovflineno FCMD2GBL_INIT(0);                    //~v635I~
//FCMD2GBL_EXT  ULONG Sovfoffset FCMD2GBL_INIT(0);                 //~vaz0R~
FCMD2GBL_EXT  FILESZT Sovfoffset FCMD2GBL_INIT(0);                 //~vaz0I~
FCMD2GBL_EXT  int  Sovfsuffix FCMD2GBL_INIT(0);                    //~v635I~
FCMD2GBL_EXT 	int  Snotfinpctr FCMD2GBL_INIT(0);	//Gkbdinpctr resulted not found to chk wrap ope//~v635I~
FCMD2GBL_EXT 	int  Sfindcmdinpctr FCMD2GBL_INIT(0);	//to chk continued operation of rfind//~v635I~
FCMD2GBL_EXT 	char Swrapsw;		//reqid to wrap for linesrchstring//~v635I~
FCMD2GBL_EXT 	char Sulsrchsw FCMD2GBL_INIT(0); 	//1:update line search,2:errline search//~v635I~
FCMD2GBL_EXT 	char Sulsrchsw2 FCMD2GBL_INIT(0); 	//for 2nd opd of & srch//~v635I~
FCMD2GBL_EXT  int  Sscrollpendsw FCMD2GBL_INIT(0);	//set when 1st word found//~v635I~
FCMD2GBL_EXT 	char Snotsrchsw FCMD2GBL_INIT(0);    //*! search   //~v635I~
FCMD2GBL_EXT 	char Snotsrchsw2 FCMD2GBL_INIT(0);    //*! search  //~v635I~
FCMD2GBL_EXT 	UCHAR Sescsrchchar[MAXCOLUMN];	//escape sequence srch char//~v635I~
FCMD2GBL_EXT 	UCHAR Sescsrchchar2[MAXCOLUMN];	//for 2nd word of *&//~v635I~
FCMD2GBL_EXT 	UCHAR Sescrepchar[MAXCOLUMN];	//escape sequence repl char//~v635I~
FCMD2GBL_EXT 	char Sescsrchlen;   //escape sequence char len     //~v635I~
FCMD2GBL_EXT 	char Sescsrchlen2;   //escape sequence char len    //~v635I~
FCMD2GBL_EXT 	char Sescreplen;	//replace to escape sequence len(1or 2)//~v635I~
FCMD2GBL_EXT 	char Stabsrchsw;	//tab search                   //~v635I~
FCMD2GBL_EXT 	char Sphasesw;		//1st/2nd word search phase of *&//~v635I~
FCMD2GBL_EXT 	char Stabsrchsw2;	//tab search for *&            //~v635I~
FCMD2GBL_EXT 	char Stabrepsw;		//repword contain tab          //~v635I~
FCMD2GBL_EXT 	char Srepnull FCMD2GBL_INIT(0);		//rep to null sw//~v635I~
FCMD2GBL_EXT  char Sexcludesw;	//exclude cmd active               //~v635I~
FCMD2GBL_EXT  char Sexcludesw2 FCMD2GBL_INIT(0);	//exclude cmd active on edit/browse(0 when dir list screen)//~v635I~
FCMD2GBL_EXT  int  Gnxsw;			//nx line only sw              //~v635R~
#define  GNXSW_CMD  0x01            //by inx cmd                   //~v74FI~
#define  GNXSW_OPT  0x02            //by NX option                 //~v74FI~
FCMD2GBL_EXT  char Supctrsw;		//exclude/include occuerd(for undo)//~v635I~
FCMD2GBL_EXT  char Sallxfound FCMD2GBL_INIT(0);                    //~v635I~
FCMD2GBL_EXT  SHORT Srange1 FCMD2GBL_INIT(0),Srange2 FCMD2GBL_INIT(0),Srangeid1 FCMD2GBL_INIT(0),Srangeid2 FCMD2GBL_INIT(0);     //search change range//~v635I~
FCMD2GBL_EXT  SHORT Srange1and FCMD2GBL_INIT(0),Srange2and FCMD2GBL_INIT(0),Srangeid1and FCMD2GBL_INIT(0),Srangeid2and FCMD2GBL_INIT(0);     //for and srch//~v635I~
FCMD2GBL_EXT int Slinebefore FCMD2GBL_INIT(0),Slineafter FCMD2GBL_INIT(0),Slinedist FCMD2GBL_INIT(0);	//display line after,before found line//~v635I~
FCMD2GBL_EXT int Sminsame FCMD2GBL_INIT(0);        //minimum same line count to exclude//~v635I~
FCMD2GBL_EXT PULINEH Srangeplhe;                                   //~v635I~
FCMD2GBL_EXT PULINEH Srangeplhe2; //for 2nd word range of *&       //~v635I~
FCMD2GBL_EXT PULINEH Ssrcherrplh FCMD2GBL_INIT(0);                 //~v635I~
FCMD2GBL_EXT int Slinerangesw;	//1:out of range                   //~v635I~
FCMD2GBL_EXT 	PULINEH Sspanplh FCMD2GBL_INIT(0);		//word spaned to multiple line for bin//~v635I~
FCMD2GBL_EXT 	PULINEH Sandplh1 FCMD2GBL_INIT(0);		//1st word plh of *&//~v635I~
FCMD2GBL_EXT 	PULINEH Ssamelastplh FCMD2GBL_INIT(0);	//last plh of same line(after first plh even if prev srch)//~v635I~
FCMD2GBL_EXT 	LONG    Ssamelinectr FCMD2GBL_INIT(0);	//same line count//~v635I~
FCMD2GBL_EXT int  Sfindopt FCMD2GBL_INIT(0);	//cmd parm option flag//~v635I~
FCMD2GBL_EXT ULONG Sfindopt2 FCMD2GBL_INIT(0);	//cmd parm option flag2//~v635I~
FCMD2GBL_EXT int  Sothopt FCMD2GBL_INIT(0);	//cmd parm option flag //~v635I~
FCMD2GBL_EXT int  Sothererr_abrange FCMD2GBL_INIT(0);	//not notfound err count:ab range err//~v635I~
FCMD2GBL_EXT int  Sothererr_selfjoin FCMD2GBL_INIT(0);   //not notfound err count:join myself case//~v635I~
FCMD2GBL_EXT char Ssetlabel[ULHLINENOSZ];    //-l parm operand ptr //~v635I~
FCMD2GBL_EXT int  Gpanfindopt;                                     //~v76mI~
#define           PANFO_FNL       0x01      //filename list search //~v76mI~
FCMD2GBL_EXT char  Ssrchword[MAXCOLUMN];   //word get area         //~v79VM~
FCMD2GBL_EXT int   Ssrchwordlen;                                   //~v79VM~
#ifdef UTF8UCS2                                                    //~va20R~
#define SAVE_SRCHWORDSZ 128          //save data extention size    //~va20I~
FCMD2GBL_EXT char  Gsrchwordforini[SAVE_SRCHWORDSZ];   //word get area//~va20R~
#endif                                                             //~va20I~
#define FCMD_SPLIT_INDEX_STD    2   //cmd for std find cmd         //~vbCBI~
#define FCMD_SPLIT_INDEX_MAX    3   //cmd for std find cmd         //~vbCBI~
FCMD2GBL_EXT void *GfindcmdSplit[FCMD_SPLIT_INDEX_MAX];//split specific cmd string//~vbCBR~
//****************************************************************//~5504I~
int fcmdwfparm(FILE *Pfh);                                      //~v064R~
                                                                //~v064I~
//**************************************************************** //~v43gI~
int fcmdrfparm(FILE *Pfh);                                      //~v064I~
                                                                   //~v43gI~
//**************************************************************** //~v43gI~
int fcmdsetfindhighlight(PUFILEH Ppfh,PULINEH Pplh,int Plocatesw,int Plinesrchsw,//~v43gM~
			int Poffset,int Pwordlen,PULINEH Pspanplh);            //~v43gM~
#define FCMDSFHOPT_LOCATE     0x0001    //new   find cmd(not rfind)//~v62aI~
#define FCMDSFHOPT_NOMULTIREV 0x0100	//reset multiple reverse   //~v62aI~
                                                                   //~v43hI~
//**************************************************************** //~v43hI~
int fcmdcpymfwt(PUFILEH Ppfh);                                     //~v43hM~
                                                                   //~v47iM~
//**************************************************************** //~v47iM~
int fcmdgetstartplhoffs(PUCLIENTWE Ppcw,PULINEH *Ppplh,int *Ppoffset,int Popt);//~v635R~
//**************************************************************** //~v635I~
void fcmd2saverestorx(int Psave);	//save for the case "x all"/"x=all"//~v635I~
//**************************************************************** //~v635I~
int fcmdothererrmsgcat(int Psubcmdid);                             //~v635I~
//**************************************************************** //~v635I~
int fcmdsrcherr(int Pchangeopt,int Plocatesw,int Psubcmdid,PULINEH Pplh);//~v635I~
//**************************************************************** //~v635I~
char *fcmdescsrch(char *Ppc,int Pdirection,int Poffset);           //~v635I~
//**************************************************************** //~va20I~
int fcmdrfind(PUCLIENTWE Ppcw,int Preverse,int Pchangeopt);        //+vbCBI~
