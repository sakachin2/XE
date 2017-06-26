//*CID://+vbCBR~:**               update#=  43                     //~vbCBR~
//****************************************************************
//*xefcmd22.h                                                      //~v437R~
//****************************************************************//~v064I~
//vbCB:160820 Find cmd;add panel specific option                   //~vbCBI~
//vax1:140625 (BUG:Win)find ucs2 failes(searchs ucs4), U4 is not only for change cmd repword but for search word//~vax1I~
//vaw1:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~vaw1I~
//va7b:100817 (BUG)and search on ebc file,rfind on next session faile by "no ebcdic data";//~va7bI~
//            (utf8 data was not saved for Sescsrchachar2)         //~va7bI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3x:100302 (LNX)UCS4 support                                    //~va3xI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1G:091118 (UTF8)add UTF8 trans err char Find/Change function   //~va1GI~
//va0y:090920_add U8(UTF8 code search) to find option(U[B|L|8] (Big/Little Endian/UTF8)//~va0yI~
//va0c:090711 Unicode find option  U[B|L] (Big/Little Endian,default is OS endian)//~va0cI~
//v79L:081020 change cmd support P'..' fmt as target string specification(=(same),<(lower),>(upper) is special char)//~v79LI~
//v78e:080310 supprt find cmd search patern by P'.'                //~v78eI~
//v78d:080308 screen grep support                                  //~v78dI~
//v698:060427 (BUG)scrolling dose not occur when hex 3line mode.   //~v698I~
//v62a:050311 -m option of find cmd to keep previous reverse       //~v61hI~
//v61h:050226 find cmd set label option(-lxxx)                     //~v61hI~
//v59Z:041218 find cmd:csr line position option                    //~v59ZI~
//v58r:040923 find cmd option -je:join to eof(line range2) if 2nd word not found//~v58rI~
//v54Z:040202 find cmd:search "x y" at eol by EOL option("a b"\n is fmt err by parse())//~v54ZI~
//v54R:040125 find cmd:max record search by f \n max               //~v54RI~
//v539:030920 join option for find; {i|f}[nx] -j                   //~v539I~
//v532:030915 2 cols pos parm for & search                         //~v532I~
//v49d:020629 to exclude from 1st same "x *= -b"                   //~v49dI~
//v43w:011116 ! for also word2 of & search                         //~v43wI~
//v43u:011112 fgind:change *! --> ! only                           //~v43uI~
//v43t:011112 fgind:change *& --> & only                           //~v43tI~
//v43i:011031 distance option <,>,= (default is =)                 //~v43iI~
//v43e:011026 find cmd option;f *& word1 word2 -dn                 //~v43eI~
//v43d:011026 find cmd option to always set csr to leftmost        //~v43dI~
//v437:011024 add unexclude range optio to find cmd                //~v437I~
//v41r:010830 except search "*!" prefix; "i *! word" fmt           //~v41rI~
//v13p:991106 find consideration for concat line/bin file line     //~v13pI~
//v11s:990808 (BUG) not allowed \x string search if \x09 is contained.Allow to bin file.//~v11sI~
//v11p:990725 accept "EXClude all" (no search word  case)          //~v11pI~
//v11o:990720 (BUG)compatibility to DOS;find parm save len change int to SHORT//~v11oI~
//v11k:990718 Find/change/Exclude cmd help                         //~v11kI~
//v11g:990717 set found line in the middle of page                 //~v11gI~
//v0ic:980607 label support for DROP cmd                           //~v0icI~
//v0hx:980410 label lcmd support for find etc.                     //~v0hxI~
//            alternative of v0hk and  v0hw is not needed anymore. //~v0hxI~
//v0eB:970923 find/change range support                            //~v0eBI~
//v0ew:970922 split fcmd2 to fcmd22                                //~v0ewI~
//**************************************************************** //~v0eBI~
#define  MAXRIGHT   32767   //specified not range but pos1 only    //~v13pM~
                                                                   //~v13pI~
#define  RANGE1M       -1   //search left mergin only              //~v0eBM~
#define  RANGE2M       -2   //search rifht mergin only             //~v0eBM~
#define  RANGE1ONLY    -3   //specified not range but pos1 only    //~v0eBM~
#define  RANGENOPARM   -4   //specified not range but pos1 only    //~v0eBM~
#define  RANGEMAX      -5   //specified not range but pos1 only    //~v54RI~
#define  RANGEEOL      -6   //search at end of line only           //~v54ZI~
                                                                   //~v41rI~
#define STR_SEARCH_NOT "!"                                         //~v43uR~
#define STR_SEARCH_AND "&"                                         //~v43tR~
                                                                   //~va0cI~
#define STR_SEARCH_UCSBE   "UB"                                    //~va0cI~
#define STR_SEARCH_UCSLE   "UL"                                    //~va0cI~
#define STR_SEARCH_UTF8    "U8"                                    //~va0yI~
//#ifdef UTF8UCS4                                                    //~va1CI~//~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
#define STR_SEARCH_UCS4    "U4"                                    //~va3xI~
#endif                                                             //~va1CI~//~va3xI~
                                                                   //~va0cI~
#define FCMDOPT_UCSSTR     'U'                                     //~va0cM~
#define FCMDOPT_BIG        'B'                                     //~va0cM~
#define FCMDOPT_LITTLE     'L'                                     //~va0cM~
#define FCMDOPT_UTF8       '8'                                     //~va0yI~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
#define FCMDOPT_UCS4       '4'                                     //~va3xI~
#endif                                                             //~va3xI~
//**************************************************************** //~v437I~
//int fcmdgetfindoption(PUCLIENTWE Ppcw,int Pchangeopt,int *Popdno,//~v49dR~
int fcmdgetfindoption(PUCLIENTWE Ppcw,int Pexcludesw,int Pchangeopt,int *Popdno,//~v49dI~
//				char **Popd,UPODELMTBL *Podt,int *Pinttbl,int *Ppopt);//~v59ZR~
				char **Popd,UPODELMTBL *Podt,int *Pinttbl,int *Ppopt,ULONG *Ppopt2);//~v59ZI~
#define FINDIP_BEFORE      0    //int parm index                   //~v43dI~
#define FINDIP_AFTER       1    //int parm index                   //~v43dI~
#define FINDIP_DISTANCE    2    //int parm index                   //~v43dI~
//#define FINDIP_MAX       3    //int parm index                   //~v61hR~
#define FINDIP_LABELOPDNO  3    //-l operand operand no            //~v61hI~
#define FINDIP_MAX         4    //int parm max                     //~v61hI~
                                                                   //~v43dI~
//#define FINDOPT_CSRTOP   0x01   //csr top option                 //~v59ZR~
#define FINDOPT_DISTIN   0x02   //-dn<,-d>n                        //~v43iI~
#define FINDOPT_DISTOUT  0x04   //-dn>,-d<n                        //~v43iI~
#define FINDOPT_BEFORE0  0x08   //-b[0] to exclude same line from top//~v49dI~
#define FINDOPT_JOIN     0x10   //-j:join option                   //~v539R~
#define FINDOPT_JOINEOF  0x20   //-je:join option,join to eof if not found 2nd word//~v58rI~
#define FINDOPT_DISTOPT  0x40   //-dn option,n may be 0            //~v58rI~
#define FINDOPT_SETLABEL 0x80   //-l option(set label)             //~v61hI~
#define FINDOPT_MULTIREV      0x0100 //-m option(keep previous reverse)//~v62aR~
#define FINDOPT_MULTIREVNEXT  0x0200 //-mn option(keep previous reverse from next)//~v62aI~
#define FINDOPT_MULTIREVRESTA 0x0400 //-m interrupted(internal use)//~v62aI~
#define FINDOPT_GREP          0x0800 //-e option for grep search   //~v78dI~
#define FINDOPT_GREPP         0x1000 //P'.' patern                 //~v78eI~
#define FINDOPT_GREPPTARGET   0x2000 //change target is P'.' patern//~v79LI~
#define FINDOPT2_CSRLINEMASK   0x00ff //line position line ctr mask//~v59ZR~
#define FINDOPT2_CSRCOLMASK    0xff00 //line position cols mask    //~v59ZI~
#define FINDOPT2_CSRTOP      0x080000 //line position is from bottom//~v59ZR~
#define FINDOPT2_CSRBOTTOM   0x040000 //line position is from bottom//~v59ZR~
#define FINDOPT2_CSRLEFT     0x020000 //line position is from bottom//~v59ZR~
#define FINDOPT2_CSRRIGHT    0x010000 //line position is from bottom//~v59ZR~
#define FINDOPT2_CSRMIDDLE   (FINDOPT2_CSRTOP|FINDOPT2_CSRBOTTOM)  //~v59ZI~
#define FINDOPT2_CSRCENTER   (FINDOPT2_CSRLEFT|FINDOPT2_CSRRIGHT)  //~v59ZI~
#define FINDOPT2_CSROPTION   (FINDOPT2_CSRTOP|FINDOPT2_CSRBOTTOM|FINDOPT2_CSRLEFT|FINDOPT2_CSRRIGHT)//~v59ZR~
//**************************************************************** //~v0eBI~
//int fcmdoperandrearange(PUCLIENTWE Ppcw,int Pchangeopt,int *Popdno,//~v532R~
//				char **Popd,UPODELMTBL *Podt,SHORT *Pposfrom,SHORT *Pposto,int *Ppopt);//~v532R~
int fcmdoperandrearange(PUCLIENTWE Ppcw,int Pchangeopt,int *Popdno,//~v532I~
//  			char **Popd,UPODELMTBL *Podt,SHORT *Pposfrom,SHORT *Pposto,//~v58rR~
  				char **Popd,UPODELMTBL *Podt,                      //~v58rI~
                int Pfindopt,int *Pinttbl,                         //~v58rI~
				SHORT *Pposfrom,SHORT *Pposto,                     //~v58rI~
				SHORT *Pposfromand,SHORT *Ppostoand,int *Ppopt);   //~v532R~
//for Sothopt                                                      //~va1GI~
#define  SEARCH_NOT    0x01 //search line not contains the word "*!"//~v41rI~
#define  SEARCH_AND    0x02 //search line not contains the word "*!"//~v43eR~
#define  SEARCH_NOT2   0x04 //! for word2 of & search              //~v43wI~
#define  SEARCH_UCS    0x10 //1st word is Unicode                  //~va0cI~
#define  SEARCH_UCS2   0x20 //2nd word is Unicode                  //~va0cI~
#define  SEARCH_UCSBE  0x40 //1st word is BigEndian                //~va0cI~
#define  SEARCH_UCSBE2 0x80 //2nd word is BigEndian                //~va0cI~
#define  SEARCH_UTF8   0x0100 //1st word is UTF8                   //~va0yI~
#define  SEARCH_UTF82  0x0200 //2nd word is UTF8                   //~va0yI~
#define  SEARCH_UTF8ECH   0x0400 //1st is utf8 trans err search    //~va1GR~
#define  SEARCH_UTF8ECH2  0x0800 //2nd is utf8 trans err search    //~va1GR~
#define  SEARCH_UTF8ECHR  0x1000 //reset utf8 trans err, accept as locale code//~va1GI~
#ifdef UTF8UCS2                                                    //~va1GI~
#define  SEARCH_SAMEAS    0x2000 //"*" specified                   //~va1GI~
#define  SEARCH_UCS2WORD  0x4000 //word of searchword is from utf8 file//~va1GI~
#define  SEARCH_USEESCSTR  (SEARCH_UTF8|SEARCH_UCS) //Sescsrchchar is filled by this type of search(but Sescsrchlen=0)//~va1GI~
#define  SEARCH_USEESCSTR2 (SEARCH_UTF82|SEARCH_UCS2) //Sescsrchchar is filled by this type of search(but Sescsrchlen=0)//~va1GI~
#define  SEARCH_CHANGE    0x8000 //change cmd                      //~va1GR~
#define  SEARCH_ESCDDSRCH  0x010000 //escsrch by dd str            //~va20I~
#define  SEARCH_ESCDDREP   0x020000 //escsrch by dd str            //~va20I~
//#ifdef UTF8UCS4                                                    //~va3xI~//~vaw1R~
#ifdef UTF8UCS416                                                  //~vaw1I~
#define  SEARCH_UCS4       0x040000 //repword is ucs4 esc str      //~va3xI~
#endif                                                             //~va3xI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define  SEARCH_EBCWORD       0x080000 //FWF cmd word is ebcdic//~va50I~
	#define  SEARCH_DDSTR2        0x100000 //Sescsrchchar2 is filled by utf8//~va7bI~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#define  SEARCH_REPWORD    0x200000 //parm tofcmdchkucsopt         //~vax1I~
#define  SEARCH_UCS4SW     0x400000 //ucs4 search word1            //~vax1I~
#define  SEARCH_UCS4SW2    0x800000 //ucs4 search word2            //~vax1I~
#endif                                                             //~va1GI~
                                                                   //~vbCBI~
//**************************************************************** //~v0eBI~
int  fcmdsetrange(PUCLIENTWE Ppcw,int Pnorangeopt,int Pwordlen,    //~v0eBI~
				SHORT Ppos1,SHORT Ppos2,SHORT *Prange1,SHORT *Prange2);//~v11oR~
//****************************************************************//~5104I~
int fcmdscrollpage(PUCLIENTWE Ppcw,PULINEH Pplh);               //~5104I~
//**************************************************************** //~v11gI~
int fcmdscrollpagemid(PUCLIENTWE Ppcw,PULINEH Pplh);               //~v11gI~
//**************************************************************** //~v59ZI~
int fcmdfindscroll(PUCLIENTWE Ppcw,PULINEH Pplh,ULONG Popt2);      //~v59ZI~
//*******************************                                  //~v0ewI~
int srchsubcmd(char *Psubcmd);                                     //~v0ewI~
//**************************************************               //~v0ewI~
int fcmdtabsrch(PULINEH Pplh,int Pdirection,int Poffset,unsigned char **Pppc,//~v0eBR~
                int Prange1,int Prange2,UCHAR *Pstring,int Pstrlen);//~v11sR~
//**************************************************               //~va1GI~
int fcmdutf8echsrch(PULINEH Pplh,int Pdirection,int Poffset,unsigned char **Pppc,//~va1GI~
                int Prange1,int Prange2);                          //~va1GI~
//**************************************************               //~v0ewI~
int fcmdchkescseq(char *Pin,char *Pout,int Popt);                  //~v0ewI~
//**************************************************               //~v0hxI~
int fcmdsetabrange(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Psubcmdid,PULINEH *Ppplhs,PULINEH *Ppplhe);//~v0hxI~
//**************************************************               //~v11pI~
int fcmdxall(PUCLIENTWE Ppcw,PUFILEH Ppfh);                        //~v11pR~
//**************************************************               //~v0icI~
int fcmdlabelerr(char *Pmsg);                                      //~v0icI~
//**************************************************               //~v11kI~
int fcmdfindhelp(int Pchangeopt,int Pexcludesw);                   //~v11kI~
//**************************************************               //~v61hI~
int fcmdsetfoundlinelabel(PULINEH Pplh,char *Plabel);              //~v61hR~
//**************************************************               //~v698I~
PULINEH fcmdfindscrollvhexline(PULINEH Pplh,int Pscrheight,int Pstep);//~v698I~
//**************************************************               //~v698I~
int fcmdcountvhexline(PUCLIENTWE Ppcw,PUFILEC Ppfc,PULINEH Pplh,int *Ppline);//~v698I~
//**************************************************               //~vbCBI~
void fcmd2term(void);                                              //~vbCBI~
//**************************************************               //~vbCBI~
int fcmdchkPS(int Popt,int Prc,PUCLIENTWE Ppcw,int Pcasesw,int Pchangeopt,int Pbackward,int Pnxopt);//~vbCBI~
//**************************************************               //~vbCBI~
int fcmdsrchPSF(int Popt,PUCLIENTWE Ppcw,int Pdest,int Pchangeopt);//~vbCBR~
//**************************************************               //~vbCBI~
int fcmdsrchPSP(int Popt,PUCLIENTWE Ppcw,int Pdest,int Pchangeopt);//~vbCBR~
//**************************************************               //~vbCBI~
int fcmdsrchSTD(int Popt,PUCLIENTWE Ppcw,int Pdest,int Pchangeopt);//~vbCBI~
//**************************************************               //~vbCBI~
int fcmdPSinit(int Popt,void* /*PUSCMD*/ Ppsc);                    //~vbCBR~
//**************************************************               //+vbCBI~
void fcmddisplayPSall(PUCLIENTWE Ppcw);                            //+vbCBI~
