//*CID://+v6FcR~: update#=  331;                                   //+v6FcR~
//******************************************************           //~v600I~
//*utf22.h                                                         //~v640R~
//******************************************************           //~v600I~
//v6Fc:160904 in addition to v6F3,also DBCS space altch is changable//+v6FcI~
//v6F7:160905 (W64) TAB disp char on W64                           //~v6F7I~
//                  TT font:tab skip colomn err,errmsg OK          //~v6F7I~
//                  Laster font tab skip colomn OK,errmsg shorten  //~v6F7I~
//                  Column err by TT font is fixed by change OutputCharacterW+OutputAttribute to OutputW//~v6F7I~
//                  So, remove v6F6(back to old altch of TAB display)//~v6F7I~
//v6F6:160905 change tab display char 21be,21c0-->25b8,25b9 it ok on W7 both laster and trutype font.//~v6F6R~
//v6F4:160905 write default tab altch to ini file                  //~v6F4I~
//v6F3:160904 function to update visible altch for TAB/TABPAD      //~v6F3I~
//v6E9:160729 add strz option to utfcvdd2f                         //~v6E9I~
//v6E0:160717 (W32)chk printable by iswprint for dbcs              //~v6E0I~
//v6Dc:160613 use u-25a1 for unprintable dbcs                      //~v6DcI~
//v6Db:160613 (XXE)on dirlist Non printable ucs was dispalyed as sbcs-altch + ucs 2nd byte//~v6DbI~
//v6BZ:160327 roundup width0 boundary to dbcsid=xx00 to avoid incresing testcase by change of UDBCSCHK_ISUCSWIDTH0//~v6BZI~
//v6BY:160326 not fixed width0 ucs boundary                        //~v6BYI~
//v6BT:160319 (BUG)isalpha is apply to UCHAR only(UTF_COMBINABLE use it for ucs)//~v6BTI~
//v6BP:160313 (W32)utf162ucs4 for wxe                              //~v6BPI~
//v6BM:160308 add utfdd2u4W for xprint                             //~v6BMI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6Bj:160213 (W32:BUG)UCS4 was cut to UCS2                        //~v6BjI~
//v6uL:140603 split next option for utfddpos2offs(3byte advance for ucs4)//~v6uLI~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6um:140502 add utfddicmp                                        //~v6umI~
//v6uf:140424 (BUG)f2l compare should chk dbcs subchr              //~v6ufI~
//v6ua:140410 (Win)use UNICODE Api;apply WIN32_FIND_DATAW by "#ifdef W32UNICODE"//~v6uaI~
//v6p2:131008 dd2f option;rep null by altch for gtkprint           //~v6p2I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v6c7:120127 try save/restore sbcstbl for quick startup           //~v6c7I~
//v6bs:111230 add "get ucsctr of ddfmt" for cmdline shrink         //~v6bsI~
//v69a:100808 sbcsid overflow;temporary(HHH) expand to 6800-->6c00; target is assigning from >0x__20//~v69aR~
//            current status by /c850 width0=6c00->6fe4(x1b remains),sbcs:0100-->6bed(x12 remains)//~v69aR~
//            Lnx reduce by chking wcwidth=-1,Win has no wcwidth and iswprint redule large number containing actualy printable//~v69aR~
//v682:100616 reduce width0 sbcs range of ucs map tbl(overflow at ub9)//~v682I~
//v67Z:100615 (LNX)sbcsid overflowed at ub9(ue000-u8ff private area is assigbed as sbcs)//~v66eI~
//            remap should reassign for overflowed ucs             //~v66eI~
//v66e:100522 set dbcs errrep to f2l/dd2l for mixedstrupdate(rep to sbcs "?" will loose dbcsid on dbcstbl)//~v66eI~
//v66d:100521 nullrep option for dd2u for wxe C&P                  //~v66dI~
//v667:100510 utf8 sbcs support for pbrk,memchr                    //~v667I~
//v665:100510 add UTF_umemrpbrk                                    //~v665I~
//v660:100325 local EBCDIC translation support                     //~v660I~
//v65n:100331 default tab/tab padding is shown by 0xff as data value//~v65nI~
//v65m:100329 to print 0x14 glyph(q:0xb6),use another altchar(0xff)//~v65mI~
//v65i:100327 (WinCons)display 0x1b by unicodwe letterlike symbols u21xx because 0x1b make trouble for line clear//~v65iI~
//v65g:100320 compare utf8 dbcs split string option                //~v65gI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v650:100121 print width=0(combine mdeo)                          //~v650I~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//******************************************************           //~v600I~
#ifdef UTF8UCS2                                                    //~v640I~
//  #define UTF22_TABALT1       0x21be      //TAB(0x09) display char//~v6F6R~
//  #define UTF22_TABALT2       0x21c0      //TAB padding display char//~v6F6R~
//  #define UTF22_TABALT1       0x25b8      //TAB(0x09) display char//~v6F7R~
//  #define UTF22_TABALT2       0x25b9      //TAB padding display char//~v6F7R~
    #define UTF22_TABALT1       0x21be      //TAB(0x09) display char//~v6F7I~
    #define UTF22_TABALT2       0x21c0      //TAB padding display char//~v6F7I~
    #define UTF22_DBCSSPACEALT  0x2591      //default dbcs space altch//+v6FcI~
//*********************************************************************//~v640M~
    #define UTF_UNPDBCS      0x25a1 //square grid                  //~v6DcI~
	#define UTF_ISTABDBCS(dbcsid) \
			( (dbcsid)==UDBCSCHK_TABCHAR || (dbcsid)==UDBCSCHK_TABPADCHAR )//~v640I~
	#define UTF_ISASCIITABDBCS(dbcsid)   \
			( (dbcsid)==0 || UTF_ISTABDBCS(dbcsid) )               //~v640I~
	#define UTF_isasciidbcs(sw,dbcsid)   \
			( (sw) ? ((dbcsid)==0) : 1 )                           //~v640I~
	#define UTFDD_ISSPACE(datach,dbcsid) \
                ( (datach)==' ' && UTF_ISASCIITABDBCS(dbcsid) )    //~v640I~
	#define UTF_eqspace(sw,datach,dbcsid) \
		(   (sw) ? UTFDD_ISSPACE(datach,dbcsid) \
                 : ((datach)==' ') \
        )                                                          //~v640I~
	#define UTF_eqspacetab(sw,datach,dbcsid) \
		(   (sw) ? (UTFDD_ISSPACE(datach,dbcsid) || UTFDD_ASCIIEQ(datach,dbcsid,TABCHAR)) \
                 : ((datach)==' '||(datach==TABCHAR)) \
        )                                                          //~v660I~
	#define UTFDD_ISNOTSPACE(datach,dbcsid) \
				(!UTFDD_ISSPACE(datach,dbcsid))                    //~v640R~
	#define UTF_nespace(sw,datach,dbcsid) \
				(!UTF_eqspace(sw,datach,dbcsid))                   //~v640I~
	#define UTFDD_ISNULL(datach,dbcsid) \
                ( (datach)==0 && !UDBCSCHK_ISCOMPOSED(dbcsid) )    //~v640M~
	#define UTF_eqnull(sw,datach,dbcsid) \
		(   (sw) ? UTFDD_ISNULL(datach,dbcsid) \
                 : ((datach)==0) \
        )                                                          //~v640I~
	#define UTF_nenull(sw,datach,dbcsid) \
			(!(UTF_eqnull(sw,datach,dbcsid)))                      //~v640I~
	#define UTFDD_ISASCII(datach,dbcsid) \
                ( UTF8ISASCII(datach) && !UDBCSCHK_ISCOMPOSED(dbcsid) )//~v640M~
	#define UTF_isascii(sw,datach,dbcsid) \
		(   (sw) ? UTFDD_ISASCII(datach,dbcsid) \
                 : (UTF8ISASCII(datach)) \
        )                                                          //~v640I~
	#define UTFDD_ASCIIEQ(ch1,dbcsid,ch2) /*use UTF_ISSPACE to fo chk space*/\
				( ((ch1)==(ch2)) && (!(dbcsid)) )                  //~v640M~
	#define UTF_eq(sw,ch1,dbcsid,ch2) \
		(   (sw) ? UTFDD_ASCIIEQ(ch1,dbcsid,ch2) \
                 : (ch1==ch2) \
        )                                                          //~v640I~
	#define UTFDD_ASCIINOTEQ(ch1,dbcsid,ch2)   \
				(!UTFDD_ASCIIEQ(ch1,dbcsid,ch2))                   //~v640R~
	#define UTF_ne(sw,ch1,dbcsid,ch2) \
				(!UTF_eq(sw,ch1,dbcsid,ch2))                       //~v640R~
//*********************************************************************//~v640I~
#define UTF_UCS2DDSBCS(ucs,pdata,pdbcs)		utfddsetsbcs(0,ucs,pdata,pdbcs)//~v640R~
#define UTF_GETUCSSBCS(pdata,pdbcs) 		utfddgetsbcs(0,pdata,pdbcs)//~v640M~
#define UTF_GETUCSSBCS_HIGH(pdbcs) 		    (*(pdbcs) & 0x7f)      //~v640I~
#define UTF_GETUCSDBCS(pdata) \
          ((WUCS)( (*(UCHAR*)(pdata) <<8) | *(UCHAR*)(pdata+1) ))  //~v640M~
//#ifdef UTF8UCS4                                                  //~v6f3R~
	#define UTF_ISUCS4(ucs) (((ucs)>>16)!=0)                       //~v65cR~
//#ifdef UTF8UCS4                                                    //~v6f3I~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
	#define UTF_GETUCSDBCSOVF_HIGH(pdbcs) \
          ( ((*(UCHAR*)(pdbcs) & UDBCSCHK_UCS4MASK1)<<3) | (*(UCHAR*)(pdbcs+1) & UDBCSCHK_UCS4MASK2) )//~v65cR~
	#define UTF_GETUCSDBCSOVF(pdata,pdbcs) \
          (UTF_GETUCSDBCS(pdata)|(UTF_GETUCSDBCSOVF_HIGH(pdbcs)<<16))//~v65cR~
#endif                                                             //~v65cM~
	#define UTF_SETUCS4TOBESTR(ucs,ucsbe) \
          ((ucsbe)[0]=(UCHAR)(((ucs)>>16)&0xff),(ucsbe)[1]=(UCHAR)(((ucs)>>8)&0xff),(ucsbe)[2]=(UCHAR)((ucs)&0xff))//~v65cR~
	#define UTF_GETUCS4FROMBESTR(ucsbe) \
          ( (((UCHAR)(ucsbe)[0])<<16) | (((UCHAR)(ucsbe)[1])<<8) | (((UCHAR)(ucsbe)[2])) )//~v65cR~
#define UTF_GETUCSBESTR(ucsbe) \
          ( (((UCHAR)(ucsbe)[0])<<8) | (((UCHAR)(ucsbe)[1])) )     //~v65cR~
#define UTF_SETUCSBESTR(ucs,ucsbe) \
          ((ucsbe)[0]=(UCHAR)((ucs)>>8),(ucsbe)[1]=(UCHAR)((ucs)&0xff))//~v640I~//~v65cR~
#define UTF_UCS2MAX    0xffff                                      //~v640I~
#define UTF_GETDDUCS1(pdata,pdbcs,len) 	utfdd2u1(0,pdata,pdbcs,len)//~v640R~
#ifdef W32                                                         //~v6BjR~
#define UTF_U2DD1(ucs,pdata,pdbcs,plen) \
			utfcvu2dd1wUCS4(0,ucs,pdata,pdbcs,plen);               //~v6BjR~
#else                                                              //~v6BjR~
#define UTF_U2DD1(ucs,pdata,pdbcs,plen) \
    		utfcvu2dd1(0,ucs,pdata,pdbcs,plen)   //~v640I~         //~v6uaR~
#endif                                                             //~v6BjR~
//#define UTF_COMBINABLE(ucs) (isalpha(ucs) || (ucs)>=0x100)         //~v650I~//~v6BTR~
#define UCSIS_NONCHARACTER(ucs) \
		(  ((ucs)&0xffff)==0xffff      \
        || ((ucs)&0xffff)==0xfffe      \
        || ((ucs)>=0xfdd0 && (ucs)<=0xfdef) \
        )                                                          //~v6BTI~
#define UTF_COMBINABLE(ucs) \
		(   \
		    !UCSIS_NONCHARACTER((ucs)) \
		 && iswalpha((wint_t)(ucs))   /* ! iswcntrl && ! iswdigit && ! iswpunct && ! iswspace */ \
		)                                                          //~v6BTI~
//*******************************************************************//~v640I~
typedef struct _UCS2DDMAP {                                        //~v640R~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v67ZR~
                  			USHORT UCS2DDsbcsid;   //ucvs->sbcsid map//~v65cR~
//#else                                                              //~v65cI~//~v67ZR~
//                            WUCS UCS2DDsbcsid;     //ucvs->sbcsid map//~v640R~//~v67ZR~
//                            WUCS UCS2DDucs;        //reverse map   //~v640R~//~v67ZR~
//#endif                                                             //~v65cM~//~v67ZR~
#define UCSDDID_UNP         0    //width<0                         //~v640R~
#define UCSDDID_NONSPACE    1    //width==0                        //~v640R~
#define UCSDDID_OVERFLOW    2    //width==1,but count overflow,treate as dbcs//~v640I~
#define UCSDDID_WIDESBCS    3    //wide sbcs both wcwidth=1/2(pond,DZ)//~v640R~
#define UCSDDID_NARROWDBCS  4    //narrow even when wcwidth=2(katakana)//~v640R~
#define UCSDDID_OVERFLOWW0  5    //width=0 overflow                //~v67ZR~
#define UCSDDID_DBCS        8    //width==2                        //~v640I~
#define UCSDDID_STARTUCS 0x80                                      //~v640I~
#define UCSDDID_STARTSBCSID  0x0100                                //~v640I~
                          } UCS2DDMAP,*PUCS2DDMAP;                 //~v640R~
#define UCS2DDMAPSZ      sizeof(UCS2DDMAP)                         //~v640I~
//efine UCSDDID_STARTWIDTH0  0x6000   //width=0 sbcsid is exxx,this is used at UDBCSCHK_ISWIDTH0//~v682R~
//#define UCSDDID_STARTWIDTH0  0x6800   //width=0 sbcsid is exxx,this is used at UDBCSCHK_ISWIDTH0//~v682R~//~v69aR~
#ifdef WWW                                                         //~v6BTI~
#define UCSDDID_STARTWIDTH0  UDBCSCHK_WIDTH0TOP   //width=0 sbcsid is exxx,this is used at UDBCSCHK_ISWIDTH0//~v69aR~
//* modify also UDBCSCHK_WIDTH0ID !!!!!                            //~v682I~
#define UCSDDID_ENDWIDTH0    0x6fff   //aval 4095 for combining char//~v640I~
#else                                                              //~v6BTI~
	#define UCSDDID_WIDTH0_MODIFY      0x8000 //temporary sbcsid for modify to width0 (max 16 entry is reserved)//~v6BTR~
#endif  //WWW                                                      //~v6BTI~
//#define UCS2DDMAXSBCSID    0x7fff                                //~v640R~
//                                  0x7____ is for UCS4 on dbcstbl
#ifdef WWW                                                         //~v6BTI~
#define UCS2DDMAXSBCSID    UCSDDID_STARTWIDTH0                     //~v640I~
//*                         ==UDBCSCHK_WIDTH0TOP==0x6800           //~v6BTI~
#else                                                              //~v6BTI~
	#define UCS2DDMAXSBCSID   ( ((UDBCSCHK_UCS4-UDBCSCHK_SBCSUCSID)<<8)-1 )  //((f0-80)<<8)-1==>6fff//~v6BTR~
#endif                                                             //~v6BTI~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uBR~
#ifdef UTF8UCS416                                                  //~v6uBI~
#define UCS4_START        0x00010000    //start of ucs4            //~v65cI~
#define UCS4_DBCSTOP      0x00020000    //CJK Unified Ideographs Extension B and Supplement//~v65cI~
#define UCS4_DBCSLAST     0x00040000    //except xxxfe/xxxff for BOM?//~v65cI~
#define UCS4_MAX          0x0010ffff    //max ucs4                 //~v65cI~
  #ifdef UTF8UTF16                                                 //~v6uBI~
	#define UCS2DDMAP_ENTNO   0x00010000    //tbl size             //~v6uBI~
  #else                                                            //~v6uBI~
#define UCS2DDMAP_ENTNO   UCS4_DBCSTOP                             //~v65cR~
  #endif                                                           //~v6uBI~
#else                                                              //~v65cI~
#define UCS2DDMAP_ENTNO   0x00010000    //tbl size                 //~v640R~
#endif                                                             //~v65cI~
//*******************                                              //~v640I~
#ifdef UTF22_GBL                                                   //~v640I~
	UCS2DDMAP Gucs2ddmap[UCS2DDMAP_ENTNO];                         //~v640M~
#else                                                              //~v640I~
	extern UCS2DDMAP Gucs2ddmap[UCS2DDMAP_ENTNO];                  //~v640I~
#endif                                                             //~v640I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v67ZR~
	#define UCS2DDMAP_I2U_ENTNO  0x8000		//dbcsid-->ucs4 map, 0x80 is sbcs id//~v65cI~
    #ifdef UTF22_GBL                                               //~v65cI~
        WUCS Gucs2ddmap_i2u[UCS2DDMAP_I2U_ENTNO];                  //~v65cI~
    #else                                                          //~v65cI~
        extern WUCS Gucs2ddmap_i2u[UCS2DDMAP_I2U_ENTNO]; //ucs is up to 0x20000(LNX)/0x10000(W32) //~v65cI~
    #endif                                                         //~v65cI~
//#endif                                                             //~v65cI~//~v67ZR~
                                                                   //~v6BYI~
//#define UTF_ISUCSWIDTH0(ucs)                    utf_isucswidth0(0,ucs)//~v6BYR~//~v6BZR~
int utf_isucswidth0(int Popt,UWUCS Pucs);                          //~v6BYR~
//#define UTF_ISDDWIDTH0(dddata,dddbcs,reslen,pddwidth)    utf_isddwidth0(0,dddata,dddbcs,reslen,pddwidth)//~v6BYR~//~v6BZR~
int utf_isddwidth0(int Popt,char *Pdddata,char *Pdddbcs,int Preslen,int *Ppddwidth);//~v6BYR~
//*******************************************************************//~v640I~
int utfwwapichk(int Popt,ULONG Pucs,int Pmkwidth,int *Ppflag,int *Ppwcwidth);//~v640I~
//*******************************************************************//~v640I~
int utfchkdd(int Popt,UCHAR *Ppdbcs,int Plen);                     //~v640I~
//*******************************************************************//~v640I~
int utfddisasciistr(int Popt,UCHAR *Pdata,UCHAR *Ppdbcs,int Plen); //~v640R~
#define UTFDDIASO_M1RCIFDD    0x01 //return -1 if ddstr            //~v640I~
//*******************************************************************//~v667I~
int utfddissbcsstr(int Popt,UCHAR *Pdata,UCHAR *Ppdbcs,int Plen);  //~v667I~
//*******************************************************************//~v640I~
int utfddasciilen(int Popt,UCHAR *Pdata,UCHAR *Ppdbcs,int Plen);   //~v640I~
//*******************************************************************//~v640I~
int utfdd2u(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,WUCS *Ppucs,int Poutbuffsz,int *Ppucsctr,int *Ppucsdbcsctr,int *Ppucssbcsctr);//~v640I~
#define UTFDD2UO_ERRREP    0xff                                    //~v640I~
#define UTFDD2UO_VIO       0x0100     //for vio; data is not ucs but errid//~v640I~
#define UTFDD2UO_UCS1      0x0200     //get 1 ucs                  //~v640I~
#define UTFDD2UO_NULLREP   0x0400     //get 1 ucs                  //~v66dR~
//*******************************************************************//~v640I~
#ifdef UTF8UTF16                                                   //~v6uBI~
UWUCS utfdd2u1(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen);     //~v6uBI~
#else                                                              //~v6uBI~
WUCS utfdd2u1(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen);      //~v640R~
#endif                                                             //~v6uBI~
//*******************************************************************//~v660I~
#ifdef UTF8EBCD                                                    //~v660I~
  #ifdef UTF8UTF16                                                 //~v6uBI~
UWUCS/*ucs4*/ utfdd2u1chsz(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,int *Ppchsz);//~v6uBI~
  #else                                                            //~v6uBI~
WUCS utfdd2u1chsz(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,int *Ppchsz);//~v660I~
  #endif                                                           //~v6uBI~
#endif                                                             //~v660I~
//*******************************************************************//~v640I~
#ifdef LNX	                                                       //~v6uLR~
int utfu2dd(int Popt,PWUCS Ppdata,int Plen,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int Poutbuffsz,int *Ppoutlen);//~v640I~
#endif                                                             //~v6uBI~
//*******************************************************************//~v640I~
int utfgetwcw(int Popt,UCHAR *Pdata,int Plen,ULONG *Ppucs,int *Pchklen,int *Ppwidth);//~v640I~
#define UTFGWCWO_INPUTUCS     0x01     //input is not utf but ucs  //~v640I~
#define UTFGWCWO_GETSBCSID    0x02     //return sbcsid             //~v640I~
//*******************************************************************//~v640I~
int utfucsmapinit(int Popt);                                       //~v640I~
//*******************************************************************//~v640I~
int utfucsmapmodify(int Popt,int Pdatatype,int Pstartucs,int Penducs);//~v640R~
//*******************************************************************//~v640I~
int utfmapucs2dd(int Popt,ULONG Pucs,WUCS *Ppsbcsid);              //~v640I~
//*******************************************************************//~v640I~
int utfmapdd2ucs(int Popt,ULONG Psbcsid,ULONG *Ppucs);             //~v640R~
//*******************************************************************//~v640I~
int utfddsetsbcs(int Popt,ULONG Pucs,UCHAR *Ppdbcs,UCHAR *Ppdata); //~v640R~
//*******************************************************************//~v640I~
ULONG utfddgetsbcs(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs);          //~v640I~
//*******************************************************************//~v640I~
int utfddgetlenflag(int Popt,ULONG Pucs,int *Pplen,int *Ppflag);   //~v640I~
//*******************************************************************//~v640I~
int utfcvdd2f(int Popt,UCHAR *Ppdata,int Plen,UCHAR *Ppdbcs,UCHAR *Ppout,int Pbuffsz,int *Ppoutlen,UCHAR *Poutdbcs);//~v640R~
#define  UTFDD2FO_ERRREPCHMASK     0x00ff                          //~v640I~
#define  UTFDD2FO_VIO              0x0100 //scr output,display altch for unprintable//~v640R~
#define  UTFDD2FO_ERRREP           0x0200                          //~v640I~
#define  UTFDD2FO_DBCSSPACEREP     0x0400 //display dbcs space u3000 by alt char//~v640R~
#define  UTFDD2FO_DUPREPCHK        0x0800 //leave split replacement at xe//~v640R~
#define  UTFDD2FO_NULLALT          0x1000 //rep null by altch;for gxe//~v6p2I~
#define  UTFDD2FO_OUTSTRZ          0x2000 //append null char       //~v6E9I~
                                                                   //~v640I~
#define  UTFDD2FRC_ASCII           0x01	//ascii contained          //~v640I~
#define  UTFDD2FRC_UCS             0x02	//ucs translated           //~v640R~
#define  UTFDD2FRC_F2LERR          0x04	//writeback load err value //~v640I~
#define  UTFDD2FRC_SPLITTOL        0x08	//ucs2 split at eol        //~v640I~
#define  UTFDD2FRC_SPLITEOL        0x10	//ucs2 split at eol        //~v640I~
#define  UTFDD2FRC_ERR             0x20	//err criteria             //~v640R~
#define  UTFDD2FRC_FMTERR          0x40	//ucs2 dbcstbl fmt err     //~v640R~
#define  UTFDD2FRC_BUFFOVERFLOW    0x80	//ucs2 dbcstbl fmt err     //~v640R~
//*******************************************************************//~v640I~
int utfcvu2dd1(int Popt,WUCS Pucs,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int *Ppoutlen);//~v640I~
#ifdef W32UNICODE                                                  //~v6uBI~
int utfcvu2dd1wUCS4(int Popt,ULONG Pulucs,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int *Ppoutlen);//~v6uBI~
#endif                                                             //~v6uBI~
//*******************************************************************//~v640I~
int utfddoffs2pos(int Popt,char *Pdata,char *Pdbcs,int Plen,int Poffs,int *Pppos);//~v640I~
#define  UTFDDO2PO_INITPOS     0x01    //input start position on Pppos//~v640I~
//*******************************************************************//~v640I~
int utfddpos2offs(int Popt,char *Pdata,char *Pdbcs,int Plen,int Ppos,int *Ppoffs);//~v640I~
#define  UTFDDP2OO_NEXT        0x01    //if split apply next ucs   //~v6uLI~
//*******************************************************************//~v640I~
int utfddispunct(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);     //~v640I~
//*******************************************************************//~v640I~
int utfddcmp(int Popt,UCHAR *Ppdata1,UCHAR *Ppdbcs1,UCHAR *Ppdata2,UCHAR *Ppdbcs2,int Plen);//~v640R~
#define UTFDDCMPO_NOCASE      0x01                                 //~v640R~
#define UTFDDCMPO_SPLITOPTMASK      0xff00                         //~v65gI~
#define UTFDDCMPO_SPLITSPACE        0x0100   //assume as space for dbcs split//~v65gI~
#define UTFDDCMPO_SPLITEXC          0x0200   //exclude split data  //~v65gR~
#define UTFDDCMPO_SPLITINC0         0x0400   //include prev column data//~v65gI~
#define UTFDDCMPO_SPLITINC1         0x0800   //include next byte of data1 key//~v65gI~
#define UTFDDCMPO_SPLITINC2         0x1000   //include next byte of data2 key//~v65gI~
//*******************************************************************//~v640I~
int utfddcmpdbcstab(int Popt,UCHAR *Pdbcs1,UCHAR *Pdbcs2,int Plen);//~v640I~
//*******************************************************************//~v640I~
int utfddstrnlen(int Popt,char *Pbuff,char *Pdbcs,int Plen);       //~v640I~
//*******************************************************************//~v640I~
int utfddstrlen(int Popt,char *Pbuff,char *Pdbcs);                 //~v640I~
#define UTF_strlen(sw,pc,pcd) \
		(   (sw) ? utfddstrlen(0/*Popt*/,(pc),(pcd)) \
                 : strlen((pc)) \
        )                                                          //~v640I~
//*******************************************************************//~v640I~
int utfddmemspnc(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v640I~
#define UTF_umemspnc  UTF_UMEMSPNC                                 //~v640I~
//               : umemspnc((pc),(ch),(UINT)(len))                 //~v6BkI~
#define UTF_UMEMSPNC(sw,pc,pcd,ch,len) \
		(   (sw) ? utfddmemspnc(0/*Popt*/,(pc),(pcd),(ch),(len)) \
                 : (int)umemspnc((pc),(ch),(UINT)(len)) \
        )                                                          //~v640I~
//*******************************************************************//~v640I~
int utfddmemrspnc(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v640M~
#define UTF_umemrspnc  UTF_UMEMRSPNC                               //~v640I~
//               : umemrspnc((pc),(ch),(UINT)(len))                //~v6BkI~
#define UTF_UMEMRSPNC(sw,pc,pcd,ch,len) \
		(   (sw) ? utfddmemrspnc(0/*Popt*/,(pc),(pcd),(ch),(len)) \
                 : (int)umemrspnc((pc),(ch),(UINT)(len)) \
        )                                                          //~v640I~
//*******************************************************************//~v640I~
int utfddmemspn(int Popt,char *Pbuff,char *Pdbcs,char *Pxstr,int Plen);//~v640I~
int utfddstrnspn(int Popt,char *Pbuff,char *Pdbcs,char *Pxstr,int Plen);//~v640I~
//                 : ustrnspn((pc),(str),(UINT)(len))              //~v6BkI~
#define UTF_ustrnspn(sw,pc,pcd,str,len) \
		(   (sw) ? utfddstrnspn(0/*Popt*/,(pc),(pcd),(str),(len)) \
                 : (int)ustrnspn((pc),(str),(UINT)(len)) \
        )                                                          //~v640I~
#define UTF_memspn(sw,pc,pcd,str,len) \
		(   (sw) ? utfddmemspn(0/*Popt*/,(pc),(pcd),(str),(len)) \
                 : memspn((pc),(str),(UINT)(len)) \
        )                                                          //~v640I~
//*******************************************************************//~v640I~
int utfddmemrspn(int Popt,char *Pbuff,char *Pdbcs,char *Pxstr,int Plen);//~v640I~
#define UTF_umemrspn  UTF_UMEMRSPN                                 //~v640I~
//               : umemrspn((pc),(str),(UINT)(len))                //~v6BkI~
#define UTF_UMEMRSPN(sw,pc,pcd,str,len) \
		(   (sw) ? utfddmemrspn(0/*Popt*/,(pc),(pcd),(str),(len)) \
                 : (int)umemrspn((pc),(str),(UINT)(len)) \
        )                                                          //~v640I~
//*******************************************************************//~v640I~
char *utfddmemchr(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v640R~
#define UTF_memchr    UTF_MEMCHR                                   //~v640I~
#define UTF_MEMCHR(sw,pc,pcd,ch,len) \
		(   (sw) ? utfddmemchr(0/*Popt*/,(pc),(pcd),(ch),(len)) \
                 : memchr((pc),(ch),(UINT)(len)) \
        )                                                          //~v640I~
#define UTF_strchr(sw,pc,pcd,ch) \
		UTF_memchr(sw,pc,pcd,ch,UTF_strlen(sw,pc,pcd))             //~v640I~
#define UTF_umemchr2  UTF_UMEMCHR2                                 //~v640I~
#define UTF_UMEMCHR2(sw,pc,pcd,ch,len) \
		(   (sw) ? utfddmemchr(0/*Popt*/,(pc),(pcd),(ch),(len)) \
                 : umemchr2((pc),(char)(ch),(UINT)(len)) \
        )                                                          //~v640I~
//*******************************************************************//~v667I~
#define UTF_memchr_nonascii(sw,pc,pcd,ch,dbcsid,len) \
		(   (sw) ? utfddmemchr_nonascii(0/*Popt*/,(pc),(pcd),(ch),(dbcsid)(len)) \
                 : memchr((pc),(ch),(UINT)(len)) \
        )                                                          //~v667I~
char *utfddmemchr_nonascii(int Popt,char *Pdata,char *Pdbcs,int Pch,int Pdbcsid,int Plen);//~v667I~
//*******************************************************************//~v640I~
char *utfddmemrchr(int Popt,char *Pdata,char *Pdbcs,int Pch,int Plen);//~v640I~
#define UTF_umemrchr  UTF_UMEMRCHR                                 //~v640R~
//                 : umemrchr((pc),(ch),(UINT)(len))               //~v6BkI~
#define UTF_UMEMRCHR(sw,pc,pcd,ch,len) \
		(   (sw) ? utfddmemrchr(0/*Popt*/,(pc),(pcd),(ch),(len)) \
                 : umemrchr((pc),(ch),(size_t)(len)) \
        )                                                          //~v640I~
#define UTF_umemrchr2 UTF_UMEMRCHR2                                //~v640I~
#define UTF_UMEMRCHR2(sw,pc,pcd,ch,len) \
		(   (sw) ? utfddmemrchr(0/*Popt*/,(pc),(pcd),(ch),(len)) \
                 : umemrchr2((pc),(char)(ch),(UINT)(len)) \
        )                                                          //~v640I~
//*******************************************************************//~v667I~
#define UTF_umemrchr_nonascii(sw,pc,pcd,ch,dbcsid,len) \
		(   (sw) ? utfddmemrchr_nonascii(0/*Popt*/,(pc),(pcd),(ch),(dbcsid)(len)) \
                 : umemrchr((pc),(ch),(UINT)(len)) \
        )                                                          //~v667I~
char *utfddmemchr_nonascii(int Popt,char *Pdata,char *Pdbcs,int Pch,int Pdbcsid,int Plen);//~v667I~
//*******************************************************************//~v640I~
char *utfddmempbrk(int Popt,char *Pdata,char *Pdbcs,char *Pdelm,int Plen);//~v640I~
#define UTF_umempbrk  UTF_UMEMPBRK                                 //~v640I~
#define UTF_UMEMPBRK(sw,pc,pcd,delms,len) \
		(   (sw) ? utfddmempbrk(0/*Popt*/,(pc),(pcd),(delms),(len)) \
                 : umempbrk((pc),(delms),(UINT)(len)) \
        )                                                          //~v640I~
//*******************************************************************//~v667I~
char *utfddmempbrk_nonascii(int Popt,char *Pdata,char *Pdbcs,char *Pdelm,char *Pdelmdbcs,int Plen);//~v667I~
#define UTF_umempbrk_nonascii(sw,pc,pcd,delms,delmdbcs,len) \
		(   (sw) ? utfddmempbrk_nonascii(0/*Popt*/,(pc),(pcd),(delms),(delmdbcs),(len)) \
                 : umempbrk((pc),(delms),(UINT)(len)) \
        )                                                          //~v667I~
//*******************************************************************//~v667I~
char *utfddmemrpbrk_nonascii(int Popt,char *Pdata,char *Pdbcs,char *Pdelm,char *Pdelmdbcs,int Plen);//~v667I~
#define UTF_umemrpbrk_nonascii(sw,pc,pcd,delms,delmdbcs,len) \
		(   (sw) ? utfddmemrpbrk_nonascii(0/*Popt*/,(pc),(pcd),(delms),(delmdbcs),(len)) \
                 : umemrpbrk((pc),(delms),(UINT)(len)) \
        )                                                          //~v667I~
//*******************************************************************//~v665I~
char *utfddmemrpbrk(int Popt,char *Pdata,char *Pdbcs,char *Pdelm,int Plen);//~v665I~
#define UTF_umemrpbrk(sw,pc,pcd,delms,len) \
		(   (sw) ? utfddmemrpbrk(0/*Popt*/,(pc),(pcd),(delms),(len)) \
                 : umemrpbrk((pc),(delms),(UINT)(len)) \
        )                                                          //~v665I~
//*******************************************************************//~v640I~
char *utfddmemmem(int Popt,char *Pbuff,char *Pdbcs,char *Pkey,char *Pkeydbcs,int Plen,int Plenk);//~v640I~
#define UTFDDMMO_TABUNMATCH      0x01  //no ignore tab and tab padding(unmatch with space)//~v640R~
#define UTFDDMMO_NOCASE          0x02                              //~v640I~
#define UTF_umemmem  UTF_UMEMMEM                                   //~v640I~
#define UTF_UMEMMEM(sw,pc,pcd,key,keydbcs,len,keylen) \
		(   (sw) ? utfddmemmem(0/*Popt*/,(pc),(pcd),(key),(keydbcs),(len),(keylen)) \
                 : umemmem((pc),(key),(UINT)(len),(UINT)(keylen)) \
        )                                                          //~v640I~
#define UTF_umemstr(sw,pc,pcd,key,keydbcs,len) \
		(   (sw) ? utfddmemmem(0/*Popt*/,(pc),(pcd),(key),(keydbcs),(len),(int)strlen(key)) \
                 : umemstr((pc),(key),(UINT)(len)) \
        )                                                          //~v640I~
#define UTF_umemstri(sw,pc,pcd,key,keydbcs,len) \
		(   (sw) ? utfddmemmem(UTFDDMMO_NOCASE,(pc),(pcd),(key),(keydbcs),(len),(int)strlen(key)) \
                 : umemstri((pc),(key),(UINT)(len)) \
        )                                                          //~v640I~
#define UTF_umemmemi(sw,pc,pcd,key,keydbcs,len,keylen) \
		(   (sw) ? utfddmemmem(UTFDDMMO_NOCASE,(pc),(pcd),(key),(keydbcs),(len),(keylen)) \
                 : umemmemi((pc),(key),(UINT)(len),(UINT)(keylen)) \
        )                                                          //~v640I~
//*******************************************************************//~v640I~
char *utfddmemrmem(int Popt,char *Pbuff,char *Pdbcs,char *Pkey,char *Pkeydbcs,int Plen,int Plenk);//~v640R~
#define UTF_umemrmem  UTF_UMEMRMEM                                 //~v640I~
#define UTF_UMEMRMEM(sw,pc,pcd,key,keydbcs,len,keylen) \
		(   (sw) ? utfddmemrmem(0/*Popt*/,(pc),(pcd),(key),(keydbcs),(len),(keylen)) \
                 : umemrmem((pc),(key),(UINT)(len),(UINT)(keylen)) \
        )                                                          //~v640I~
#define UTF_umemrmemi(sw,pc,pcd,key,keydbcs,len,keylen) \
		(   (sw) ? utfddmemrmem(UTFDDMMO_NOCASE,(pc),(pcd),(key),(keydbcs),(len),(keylen)) \
                 : umemrmemi((pc),(key),(UINT)(len),(UINT)(keylen)) \
        )                                                          //~v640I~
//*******************************************************************//~v640I~
int utfddnumlen(int Popt,char *Pbuff,char *Pdbcs,int Plen);        //~v640R~
#define UTF_unumlen(sw,pc,pcd,opt,len) \
		(   (sw) ? utfddnumlen((opt),(pc),(pcd),(len)) \
                 : unumlen((pc),(opt),(len)) \
        )                                                          //~v640I~
//*******************************************************************//~v640I~
#define UTF_uatoin(sw,pc,pcd,len) \
		(   (sw) ? uatoin((pc),utfddnumlen(0/*opt*/,(pc),(pcd),(len))) \
                 : uatoin((pc),(len)) \
        )                                                          //~v640I~
#define UTF_isalnum(sw,ch,dbcsid) \
		(   (sw) ? (dbcsid)==0 && isalnum(ch) \
                 : isalnum(ch) \
        )                                                          //~v660I~
//*******************************************************************//~v650I~
int utfddcombine(int Popt,char *Pdata,char *Pdbcs,char *Pcombineid,int Plen,int *Ppstarterrctr,int *Ppendcombinectr);//~v650R~
#define UTFDDCO_ERRIFNOCB   0x01    //set err if not combinemode   //~v650I~
#define UTFDDCOMBID_START   's'                                    //~v650R~
#define UTFDDCOMBID_CONT    'c'                                    //~v650R~
#define UTFDDCOMBID_ERR     'e'                                    //~v650R~
#define UTFDDCOMBID_DRAWN   'd'  //string drawn(changed from cont) //~v650I~
#define UTFDDCOMBRC_DDFMT        0x01   //ddfmt                    //~v650I~
#define UTFDDCOMBRC_COMBINE      0x02   //width0 data              //~v650I~
                                                                   //~v650I~
//*******************************************************************//~v650I~
int utfddcombinegetsubstr(int Popt,char *Pdbcs,char *Pcombine,int Plen,int *Pplennormal,int *Pplencombine,int *Pplendrawn);//~v650I~
#define UTFDDGSS_SETDRAW     0x01    //set drawn for detected combine char//~v650I~
#define UTFDDGSS_DRAWNCHK    0x02    //count tail count            //~v650R~
#define UTFDDGSS_ERRBREAK    0x04    //cut by err                  //~v650I~
//*******************************************************************//~v650I~
int utfddgetcsrposbca(int Popt,char *Pdbcs,int Plen,int Ppos,int *Ppposb,int *Ppposc,int *Ppposa);//~v650I~
#define UTFDDGSP_ALSOLOCAL  0x01  //dbcschk for also localfile     //~v650I~
//*******************************************************************//~v650I~
int utfddgetdbcslr(int Popt,char *Pdbcs,int Plen,int Ppos);        //~v650I~
#define UTFDDGLRO_TOP  0x01   //search DBCS1ST                     //~v650I~
#define UTFDDGLRO_END  0x02   //search DBCS2ND                     //~v650I~
//*******************************************************************//~v65iI~
int utfgetvisiblealtchprint(int Popt,int Pctlchar,UCHAR *Pdata,UCHAR *Pdbcs);//~v65nR~
//*******************************************************************//~v6F3I~
int utfsetvisiblealtch(int Popt,int Paltch);                       //~v6F3I~
//*******************************************************************//~v65nI~
int utfgetvisiblealtch(int Popt,int Pctlchar);                     //~v65iI~
//#define UC_DBCSSPACE_ALT   0x2591			//0xff is NBSP by CP437;us as altch for DBCS space when TAB on//~v65nR~
#define DEFAULT_ALTCH      0xff             //for tab and tab padding data//~v65nI~
#define DEFAULT_UNPATTR    'l'              //DISPLINEATTRID       //~v65nI~
//#define DBCSSPACE_ALT      0xff                                  //~v65nR~
#define DBCSSPACE_ALT2     0xffff           //tabdisplay set ff*2 as dbcs//~v65mI~
#define UTFGVACO_CHMASK       0x0f                                 //~v65nI~
#define UTFGVACO_TAB             0                                 //~v65nI~
#define UTFGVACO_TABPAD          1                                 //~v65nI~
#define UTFGVACO_DBCSSPACE       2                                 //~v65nI~
#define UTFGVACO_UNP             3                                 //~v65nR~
#define UTFGVACO_CHMAX           4                                 //~v65nI~
                                                                   //~v65nI~
#define UTFGVACO_GETDD      0x0010   //get ddfmt ucs               //~v65nR~
#define UTFGVACO_GETLC      0x0020   //get locale code             //~v65nI~
                                                                   //~v65nI~
#define UTF_GETALTCH_SBCS(dbcsid)   /*get alt disp char for tab/tabpad/unp*/\
            (   (dbcsid)==UDBCSCHK_TABCHAR                                \
            	? utfgetvisiblealtch(UTFGVACO_TAB,DEFAULT_ALTCH)           \
                : ( (dbcsid)==UDBCSCHK_TABPADCHAR                         \
					? utfgetvisiblealtch(UTFGVACO_TABPAD,DEFAULT_ALTCH)    \
                    : (  (dbcsid)==DEFAULT_UNPATTR                        \
						 ? utfgetvisiblealtch(UTFGVACO_UNP,DEFAULT_ALTCH)  \
              			 : -2/*utfgetvisiblealtch returns -1*/        \
                      )                                                    \
                  )                                                        \
            )                                                      //~v65nI~
#define UTF_GETALTCH_SBCSID(dbcsid) /*get alt disp char for tab/tabpad/unp*/\
            (   (dbcsid)==UDBCSCHK_TABCHAR                                \
            	? UTFGVACO_TAB           \
                : ( (dbcsid)==UDBCSCHK_TABPADCHAR                         \
					? UTFGVACO_TABPAD    \
                    : (  (dbcsid)==DEFAULT_UNPATTR                        \
						 ? UTFGVACO_UNP  \
              			 : -2/*utfgetvisiblealtch returns -1*/        \
                      )                                                    \
                  )                                                        \
            )                                                      //~v65nI~
#define UTF_GETALTCH_DBCS() \
            	 utfgetvisiblealtch(UTFGVACO_DBCSSPACE,DEFAULT_ALTCH)//~v65nR~
#define UTF_GETALTCH_CTL(ch) \
            	 utfgetvisiblealtch(0,ch)                          //~v65nI~
                                                                   //~v660I~
//#define UTF_PC2PCD(pcd0,pc,pc0) ((pcd0)+((ULONG)(pc)-(ULONG)(pc0)))//~v660I~//~v6hhR~
//#define UTF_PCD2PC(pc0,pcd,pcd0) ((pc0)+((ULONG)(pcd)-(ULONG)(pcd0)))//~v660I~//~v6hhR~
#define UTF_PC2PCD(pcd0,pc,pc0) ((pcd0)+((ULPTR)(pc)-(ULPTR)(pc0)))//~v6hhI~
#define UTF_PCD2PC(pc0,pcd,pcd0) ((pc0)+((ULPTR)(pcd)-(ULPTR)(pcd0)))//~v6hhI~
                                                                   //~v660I~
//*******************************************************************//~v66eI~
int utf_setsubchar_dbcs(int Popt,UCHAR *Prepch);                   //~v66eR~
//*******************************************************************//~v66eI~
#define SBCSTBFNM "SbcsidTb"    //file on workdir                  //~v6c7I~
int utf22setworkdir(int Popt,char *Pworkdir,char *Psuffix);        //~v6c7R~
int utfddgetucsctr(int Popt,UCHAR *Ppdbcs,int Plen,int Ppos,int *Ppucsctr);//~v6bsI~
#endif	//UTF8UCS2                                                 //~v640I~
#ifdef W32UNICODE                                                  //~v6uaI~
	int utf162dd(int Popt,PUWCH Ppdata,int Pctr,UCHAR *Ppoutdata,UCHAR *Ppoutdbcs,int Poutbuffsz,int *Ppoutlen);//~v6uaI~
    #define U162DO_CHKDBCSPRINT   0x01    //chk iswprint for dbcs  //~v6E0I~
	int utf_trimascii(int Popt,UCHAR *Pstr,int Plen,UCHAR *Pout,int *Pppos);//~v6u0I~//~v6uaI~
	#define UTTAO_STRZ          0x01                                   //~v6u0I~//~v6uaI~
#endif                                                             //~v6uaI~
//*******************************************************************//~v6uaI~
char *utfmemrchrDD(char *Pdddata,char *Pdddbcs,int Plen,int Psrch);//~v6uaI~
//*******************************************************************//~v6uaI~
char *utfmemchrDD(char *Pdddata,char *Pdddbcs,int Plen,int Psrch); //~v6uaI~
//*******************************************************************//~v6uaI~
int isPrintableASCIImem(char *Ppc,int Plen);                       //~v6uaI~
//*******************************************************************//~v6uaI~
int isPrintableASCIIstr(char *Ppc);                                //~v6uaI~
//*******************************************************************//~v6uaI~
int isASCIIstr(char *Ppc);                                         //~v6uaI~
//*******************************************************************//~v6uaI~
int utf_subcharcmp(int Popt,int Psbcssubchar,char *Pstr1,char *Pstr2,int Plen);//~v6ufI~
//*******************************************************************//~v6umI~
int utfddicmp(int Popt,UCHAR *Ppdata1,UCHAR *Ppdbcs1,UCHAR *Ppdata2,UCHAR *Ppdbcs2,int Plen);//~v6umI~
#ifdef AAA  //no caller                                            //~v6DbI~
//*******************************************************************//~v6BMI~
int utfdd2u4(int Popt,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,UWUCS *Ppucs,int Poutbuffsz,int *Ppucsctr,int *Ppucsdbcsctr,int *Ppucssbcsctr);//~v6BMI~
#endif                                                             //~v6DbI~
//*******************************************************************//~v6BMI~
int utfucs42utf16(int Popt,UWUCS *Pucs4,int Pucs4ctr,WUCS *Pucs2,int Pbuffsz,int *Ppoutctr);//~v6BMR~
//*******************************************************************//~v6BPI~
int utf162ucs4(int Popt,WUCS *Ppdata,int Pctr,UWUCS *Poutucs4,int Poutbuffsz,int *Ppchkctr,int *Ppoutctr);//~v6BPR~
#define U162U4O_UCS1      0x01 //return by 1 ucs4                  //~v6BPI~
