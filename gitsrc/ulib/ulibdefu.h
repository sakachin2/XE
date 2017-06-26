//*CID://+v6E2R~:                             update#=  224;       //+v6E2R~
//*********************************************************************//~v600I~
//* define utf8 data type:to avoid compile err for header file when !UTF8SUPP//~v600R~
//*********************************************************************//~v600I~
//v6E2:160718 (W32)by v6E2(ctlen=2 but lclen=1) not usr USUBSTRLEN //~v6E2I~
//v6BT:160319 (BUG)isalpha is apply to UCHAR only(UTF_COMBINABLE use it for ucs)//~v6BTI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6B3:160116 Win compiler warning                                 //~v6B3I~
//v6uM:140606 (LNX:BUG)F2L/U2L trans 0xff>=.. 0x=>80 to hankaku katakana is iconv BUG?,back trans is ffxx for han-kana//~v6uMI~
//v6uB:140523 (Win:UNICODE)dbcsid:overflow for ucs4 on Windows     //~v6uBI~
//v6ue:140423 (Win:BUG)See v6u7;surrogate pair support (!UTF8UCS4 but UCS4(WUCS is 4 byte when UTF8UCS4)),treate as 2 unprintable//~v6ueI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6f3:120417 (Lnx)option to use ICU as local converter            //~v6f3I~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v5nq:081105*move UTF8ISASCII to ulibdef.h                        //~v5nqI~
//v5n8:080916 (CJK)IME support for CJK other than Japanese         //~v5n8I~
//v5n0:080821 partialy release UTF8SUPP for xcv                    //~v5n0I~
//v5mb:080220 (UTF)pre relese CHOFTYPE for xeacb                   //~v5mbI~
//v61c:071205 (UTF)include ascii for UTCUTF8MODE                   //~v61cI~
//v60r:071026 (UTF)utf8mode for each file                          //~v60rI~
//v600:070710 (UTF8)new typdef                                     //~v600I~
//*********************************************************************//~v600I~
#ifdef INC_ULIBDEFU                                                //~v600I~
#else                                                              //~v600I~
    #define INC_ULIBDEFU                                           //~v600I~
//*********************************************************************//~v5nqI~
#define UTF8_F2LMAXRATE 2   //expnd rate by utf8->locale code (for GB18030 4 byte code)//~v62UR~
#define MAX_MBCSLENLC   4   //max mb char sz(4:for Gb18030,5 for UTF8)//~v62UR~
#define MAX_MBCSLEN     5   //>=0x20-0000 && <0x400-0000, this range is invalid for unicode//~v6hhR~
                            //valid unicode is up to 0x10ffff(4 byte utf8)//~v6hhI~
                                                                   //~v5n8I~
#define UTF8ISASCII(ch)  ((ch)<128)                            //~v5n8I~//~v5nqR~
                                                                   //~v6E2I~
#define ASCIISTRLEN(pc,len,pcend,psubstrlen) \
    do {                                          \
        char *_pc;                                \
        int _len;                                 \
        for (_pc=(pc),_len=(len);_len>0;_pc++,_len--) \
        {                                             \
        	if (!UTF8ISASCII(*_pc))                   \
            	break;                                \
        }                                             \
        *(psubstrlen)=(len)-_len;                     \
        *(pcend)=_pc;                                 \
        UTRACEP("%s:ASCIISTRLEN=%d\n",UTT,*(psubstrlen));\
   }while(0)                                                       //~v6E2I~
                                                                   //~v6E2I~
#define UTF8CHARLEN(ch)                               \
	(((ch) < 128) ? 1:                                \
    	(((ch) & 0xe0)==0xc0 ? 2:                     \
 			(((ch) & 0xf0)==0xe0 ? 3:                 \
				(((ch) & 0xf8)==0xf0 ? 4:             \
					(((ch) & 0xfc)==0xf8 ? 5:         \
						(((ch) & 0xfe)==0xfc ? 6:     \
                        	0 ) ) ) ) ) )                          //~v600M~//~v5nqM~
#define UTF8CHARLENERR1(ch)                               \
	(((ch) < 128) ? 1:                                \
    	(((ch) & 0xe0)==0xc0 ? 2:                     \
 			(((ch) & 0xf0)==0xe0 ? 3:                 \
				(((ch) & 0xf8)==0xf0 ? 4:             \
					(((ch) & 0xfc)==0xf8 ? 5:         \
						(((ch) & 0xfe)==0xfc ? 6:     \
                        	1 ) ) ) ) ) )                          //~v600M~//~v5nqM~
#define UTF8_ISTOPBYTE(ch)    	(((ch) & 0xc0)==0xc0)              //0xc0<-->0xfd//~v600R~//~v5nqM~
#define UTF8_IS2NDBYTE(ch)    	(((ch) & 0x80) && !((ch) &0x40))   //0x80<-->0xbf//~v600I~//~v5nqM~
#define UTF8_ISDBCS2ND(Ptgt,Ppos)    (utfisdbcssplit(0,Ptgt,Ppos))     //invalid char//~v600R~//~v5nqM~
#define UTF8_IS80FF(ch) ((ch)==0xc2||(ch)==0xc3)                   //~v6uMI~
#define UCS_IS80FF(ucs) ((ucs)>=0x80 && (ucs)<=0xff)               //~v6uMI~
                                                                   //~v5nqI~
#define UTF16_TO_UCS4(high,low)  \
		( (((high)&0x3ff)<<10) + ((low)&0x3ff) + 0x10000 )         //~v6f3I~
#define IS_UTF16_HIGH(surrogate)  \
		( surrogate>=0xd800 && surrogate<0xdc00)                   //~v6f3I~
#define IS_UTF16_LOW(surrogate)  \
		( surrogate>=0xdc00 && surrogate<=0xdfff)                  //~v6f3I~
//#define IS_UTF16(surrogate)                                      //~v6uBR~
//        ( surrogate>=0xd800 && surrogate<=0xdfff)                  //~v6ueI~//~v6uBR~
#define IS_UTF16SURROGATE(surrogate)          \
        ( surrogate>=0xd800 && surrogate<=0xdfff)                  //~v6BTI~
#define IS_UTF16_PAIR(high,low)  \
		( IS_UTF16_HIGH(high) && IS_UTF16_LOW(low))                //~v6f3I~
//        		*(utf16)=(((ucs-0x10000)>>10)&0x3ff)+0xd800;       //~v6BkI~
//        		*(utf16+1)=((ucs-0x10000)&0x3ff)+0xdc00;           //~v6BkI~
//          	*(utf16)=(WUCS)(ucs);  /*wchar_t=USHORT*/          //~v6BkI~
#define UCS4_TO_UTF16(ucs,utf16,plen)                   \
		do                                             \
        {                                              \
	        if (ucs>0xffff)                       \
            {                                          \
          		*(utf16)=(USHORT)( (((ucs-0x10000)>>10)&0x3ff)+0xd800 );  \
        		*(utf16+1)=(USHORT)( ((ucs-0x10000)&0x3ff)+0xdc00 );       \
                *(plen)=2;                                 \
            }                                          \
            else                                       \
            {                                          \
            	*(utf16)=(USHORT)(ucs);  /*wchar_t=USHORT*/  \
                *(plen)=1;                                 \
            }                                          \
        } while(0)                                                 //~v6f3I~
//*********************************************************************//~v5nqI~
                                                                   //~v5mbI~
    typedef unsigned short  CHOFTYPE,*PCHOFTYPE;                   //~v61cR~
    #define CHOFSZ    sizeof(USHORT)                               //~v61cR~
                                                                   //~v5n0I~
	typedef unsigned int  UTCHAR;                                  //~v5n0M~
	typedef struct _UTCHARS  {                                     //~v5n0M~
                       	 	unsigned char *data;  //top addr       //~v5n0M~
                       	 	PCHOFTYPE  chof;  //offset tbl         //~v5n0M~
//  #define UTCCHOFASCII    (PCHOFTYPE)(-1)     //data is ascii only//~v5n0M~//~v6hhR~
    #define UTCCHOFASCII    (PCHOFTYPE)(ULPTR)(-1)     //data is ascii only//~v6hhI~
//                          int        lenutf;     //utf len       //~v5n0M~
                        	int        lenc;    //char width       //~v5n0M~
                            int        cpos;    //current column pos//~v5n0M~
                          } UTCHARS,*PUTCHARS;                     //~v5n0M~
    #define UTCHARSSZ (sizeof(UTCHARS))                            //~v5n0M~
                                                                   //~v5mbM~
#ifdef UTF8SUPP                                                    //~v5n8R~//~v5nqR~
//valid unicode is up to 0x10ffff(4 byte utf8)                     //~v6hhI~
	#define UTF8_MAXCHARSZ 4	//0x10ffff->f4.8f.bf.bf            //~v62UR~
	#define UTF8_MAXCHARSZMAX 6	//logical max(0x400-0000==>0x7fff-ffff)//~v6hhR~
	#define UTF8E(exp1,exp2)    exp2    //exp1 when not UTF8SUPP   //~v600R~
                                                                   //~v600I~
	#define UTCDATA(name)      (name)->data                        //~v600R~
	#define UTCCHOF(name)      (name)->chof                        //~v600R~
	#define UTCCHOFCPOS(name)  ((name)->chof+(name)->cpos)         //~v600I~
	#define UTCLENC(name)      (name)->lenc                        //~v600R~
	#define UTCsetLENC(name,val)   (name)->lenc=val                //~v600I~
	#define UTCsetLENC_(name,val)  UTCsetLENC(name,val);           //~v600I~
	#define UTCLENCCPOS(name)  ((name)->lenc-(name)->cpos)         //~v600I~
//  #define UTCLENUTF(name)    (name)->lenutf                      //~v600R~
	#define UTCCPOS(name)      (name)->cpos                        //~v600R~
	#define UTCSTRLEN(name) (UTCLENC(name)-UTCCPOS(name))          //~v600I~
	#define UTC_ISVALIDCHOF(putch) ((putch)->chof)                 //~v600R~
	#define UTC_ISASCII(putch) ((putch)->chof==UTCCHOFASCII)       //~v600R~
	#define UTC_ISNORMALCHOF(putch) (UTC_ISVALIDCHOF(putch) && !UTC_ISASCII(putch))//~v600R~
	#define UTCLENUTFCHOF(putc) *(UTCCHOF(putc)+UTCLENC(putc))     //~v600R~
	#define UTCLENUTFCHOFFROMCPOS(putc) (UTCLENUTFCHOF(putc)-*UTCCHOFCPOS(putc))//~v600I~
	#define UTCOFFSCHOFFROMCPOS(putc,pos)  *(UTCCHOF(putc)+UTCCPOS(putc)+pos)//~v600I~
	#define UTCLENUTF(putc)  ((UTC_ISASCII(putc)||!UTC_ISVALIDCHOF(putc)) \
									? UTCLENC(putc)-UTCCPOS(putc) \
                                    : UTCLENUTFCHOFFROMCPOS(putc)         \
                              )                                    //~v600R~
                                                                   //~v600I~
    #define UTCVAL(data,chof,width) \
                  {data,chof,width,0}                              //~v600R~
//*********************                                            //~v600I~
    #define UTC_SNAME(name)  name##_utch   //pointer target structure name//~v600I~
    #define UTC_SPDEF(name)  UTCHARS  UTC_SNAME(name);PUTCHARS name   //object and ptr for plh defineition//~v600I~
    #define UTC_SPDEFI(name) UTCHARS  UTC_SNAME(name);PUTCHARS name=&UTC_SNAME(name)   //object and ptr for plh defineition//~v600I~
    #define UTC_SDEF(type,name)   UTCHARS  name                    //~v600R~
//*********************                                            //~v600I~
    #define UTCPARMD(type,name)          PUTCHARS name  //orignal data name and PUTCHARS name for UTF8SUPP//~v600I~
    #define UTCPARMD2(type,name,sname)   PUTCHARS sname  //orignal data name and PUTCHARS name for UTF8SUPP//~v600I~
    #define UTCPARMD_OPT(Poptions)       ,Poptions   //additional parm for prototype definition//~v600I~
    #define UTCPARM_OPT(optparm)         ,optparm                  //~v600I~
    #define UTCINITD(utch,src) memset(&utch,0,sizeof(UTCHARS)),utch.data=src//~v600I~
    #define UTCINITAD(utch,src) memset(&utch,0,sizeof(UTCHARS)),utch.data=src,utch.chof=UTCCHOFASCII//~v600I~
    #define UTCINITADL(utch,src,width) memset(&utch,0,sizeof(UTCHARS)),utch.data=src,utch.chof=UTCCHOFASCII,utch.lenc=width//~v600I~
    #define UTCINITDCL(utch,pdata,pchof,width) memset(&utch,0,sizeof(UTCHARS)),utch.data=pdata,utch.chof=pchof,utch.lenc=width//~v600I~
    #define UTCRESETCPOS(putc,pdata)     UTCDATA(putc)=pdata,UTCCPOS(putc)=0//~v600I~
    #define UTCUTF8MODE(putc)     (UTC_ISNORMALCHOF(putc))         //~v61cR~
#else	//!UTF8                                                    //~v600R~
  #ifdef WCSUPP                                                    //~v5n8I~
	#define UTF8_MAXCHARSZ 4	//to included in int size          //~v5n8I~
	#define UTF8_MAXCHARSZMAX 6	//logical max                      //~v5n8I~
  #else                                                            //~v5n8I~
	#define UTF8_MAXCHARSZ 1	//to included in int size          //~v600I~
  #endif                                                           //~v5n8I~
	#define UTF8E(exp1,exp2)    exp1    //exp2 when UTF8SUPP       //~v600R~
                                                                   //~v600I~
	#define UTCDATA(name)       name                               //~v600I~
	#define UTCCHOF(name)                                          //~v600I~
	#define UTCCHOFCPOS(name)                                      //~v600I~
	#define UTCLENC(name)                                          //~v600I~
	#define UTCsetLENC_(name,val)                                  //~v600I~
	#define UTCLENCCPOS(name)                                      //~v600I~
	#define UTCCPOS(name)      name                                //~v600R~
	#define UTCSTRLEN(name)                                        //~v600I~
	#define UTC_ISVALIDCHOF(putch)                                 //~v600I~
	#define UTC_ISASCII(putch)                                     //~v600I~
	#define UTC_ISNORMALCHOF(putch)                                //~v600I~
	#define UTCLENUTF(putc)                                        //~v600I~
    #define UTCVAL(data,chof,width) data                           //~v600I~
//*********************                                            //~v600I~
    #define UTC_SNAME(name)                                        //~v600I~
    #define UTC_SPDEF(name)                                        //~v600I~
    #define UTC_SPDEFI(name)                                       //~v600I~
    #define UTC_SDEF(type,name)   type *name                       //~v600R~
//*********************                                            //~v600I~
    #define UTCPARMD(type,name)          type name //orignal data name and PUTCHARS name for UTF8SUPP//~v600R~
    #define UTCPARMD2(type,name,sname)   type name //orignal data name and PUTCHARS name for UTF8SUPP//~v600R~
    #define UTCPARMD_OPT(Poptions)                                 //~v600I~
    #define UTCPARM_OPT(optparm)                                   //~v600I~
    #define UTCINITD(utch,src)                   utch=src          //~v600R~
    #define UTCINITAD(utch,src)                  utch=src          //~v600R~
    #define UTCINITDCL(utch,pdata,pchof,width)   utch=src          //~v600R~
    #define UTCRESETCPOS(putc,pdata)             putc=pdata        //~v600I~
    #define UTCUTF8MODE(putc)     0                                //~v60rI~
#endif //!UTF8                                                     //~v5mbR~
#endif //INC_ULIBDEFU                                              //~v600I~
