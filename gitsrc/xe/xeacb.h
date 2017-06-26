//*CID://+v780R~:                                                  //~v780I~
//**************************************************************** //~v780I~
//xeship.h                                                         //~v780I~
//**************************************************************** //~v780I~
//v780:080212 syntaxhighlight support                              //~v780I~
//**************************************************************** //~v780I~
#define SYN_PGM  "xeacb"                                           //~v780I~
//************************************                             //~v780I~
#define SIGN_VERSION   "01"		//data format versin               //~v780M~
#define SIGN_HEAD    "!!_HEAD vv f s !!"                           //~v780R~
#define SIGN_HEAD_CHKLEN 8 		//valid header record size         //~v780I~
#define SIGN_HEAD_VER    8      //offset                           //~v780I~
#define SIGN_HEAD_FLAG   11                                        //~v780I~
#define SIGN_HEAD_FLAG_LE  0x01 //len is little endian             //~v780I~
#define SIGN_HEAD_LENSZ  13     //line top line length field size(sizeof(int))//~v780R~
                                                                   //~v780I~
#define SIGN_TAIL           "!!_TAIL!!"  //process completion id   //~v780R~
#define SIGN_TAIL_CHKLEN    9                                      //~v780I~
                                                                   //~v780I~
#define SIGN_COMPLETED   "!!Completed!!"                           //~v780I~
                                                                   //~v780I~
#define SHSTYLE_NORMAL     '0'                                     //~v780I~
#define SHSTYLE_BOLD       '1'                                     //~v780I~
#define SHSTYLE_UNDERLINE  '4'                                     //~v780R~
#define SHSTYLE_BLINK      '5'                                     //~v780I~
#define SHSTYLE_REVERSE    '7'                                     //~v780I~
#define SHSTYLE_INVISIBLE  '8'                                     //~v780I~
#define SHSTYLE_MAXNO      16                                      //~v780R~
//************************************                             //~v780I~
#ifdef UNX                                                         //~v780M~
    #define SHMAX_COLOR     16                                     //~v780I~
    #define SHMAX_COLOR_BG  8                                      //~v780I~
#else //!UNX                                                       //~v780M~
    #define SHMAX_COLOR     16                                     //~v780I~
    #define SHMAX_COLOR_BG  16                                     //~v780I~
#endif//!UNX                                                       //~v780M~
                                                                   //~v780I~
#define MAX_INDEX_STACKSZ 1024         //stack 1024 index entry    //~v780R~
//************************************                             //~v780I~
typedef struct _SHINDEX {         //index record                   //~v780M~
						ULONG SHXoffs;                             //~v780M~
						ULONG SHXlen;                              //~v780R~
                      } SHINDEX,*PSHINDEX;                         //~v780M~
#define SHINDEXSZ   sizeof(SHINDEX)                                //~v780M~
#define GET_CFINDEXOFFS(lineno) (lineno*SHINDEXSZ)	//top is hdr,lineno start from 1//~v780I~
#define GET_CFRECLEN(ulhlen)    ((int)sizeof(int)+(ulhlen)+(ulhlen)+1)	//top is hdr,lineno start from 1//~v780R~
