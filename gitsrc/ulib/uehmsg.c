//CID://+v6VvR~:     update#=     53                               //~v6VvR~
// *******************************************************************
// * uehmsg.c
// * exception handler set/unset,exception handler itself          //~v6T3R~
// *******************************************************************
//v6Vv:180622 show pid on exception msg                            //~v6VvI~
//v6T3:180217 exception info is 16byte for 64bit                   //~v6T3I~
//v6F1:160831 W64 try Exception msg                                //~v6F1I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v288:991023 (BUG)map not found msg override previous uerrexit msg//~v288I~
//v286:991023 abend in eh when map is not found;allow double entry to eh//~v286I~
//v171:980501 (BUG)use printf because long msg is cut by uerrmsgedit//~v171I~
//v167:980430 test eh bug                                          //~v167I~
//v150:980119 need differrentiate codepage and dbcs tbl            //~v150I~
//            w95J codepdge 437 hase dbcs table and first half of DBCS on//~v150I~
//            rightmost column effect on first column of next line //~v150I~
//v053:970107:gcc version(control by DPMI)                         //~v032I~
//            -exception handle by signal                          //~v032I~
//v032:960923:set title line(*) id for dump print pgm title        //~v032I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
// 941204 print path msg at first
// *******************************************************************

#include <string.h>
#include <stdlib.h>       //malloc,free
#include <stdio.h>
                                                                   //~v022I~
#ifdef DPMI	    			//DPMI version                         //~v032R~
#else                       //not DPMI                             //~v032R~
#ifdef W32  //copy from f:\toolkt21\c\os2h\bsexcpt.h               //~v022I~
    #include <windows.h>                                           //~v022R~
	#include <ImageHlp.h>                                          //~v6F1R~
#else                                                              //~v022I~
    #define INCL_DOSSEMAPHORES//for DosCreate/Request/ReleaseMutexSem//~v032I~
    #define INCL_DOSEXCEPTIONS  //c.b about exception handle       //~v022I~
    #define INCL_DOSDATETIME    //for DosSleep,DosGetDateTime      //~v022I~
    #include <os2.h>                                               //~v022I~
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v032R~

#include <ulib.h>
#include <udbcschk.h>
#include <ualloc.h>
#include <uerr.h>
#include <ufuncmap.h>
#include <ueh.h>
#include <uehmsg.h>
#include <uehdump.h>                                               //~v032I~
#include <utrace.h>                                                //~v167I~
#include <uproc2.h>                                                //~v6VvI~

//********************************************************************
#define WKMSGSIZE 16384  //msg work alloc size
//***************************************************************
#ifdef DPMI	    			//DPMI version                         //~v032R~
#else                       //not DPMI                             //~v032R~
//* NPX environment define  

typedef union  _UNPXENV{
   struct {// integer type definition
            USHORT UNPXEcw;          //+00 control word
            USHORT UNPXErsv1;        //+02 resv
            USHORT UNPXEsw;          //+04 status word 
            USHORT UNPXErsv2;        //+06 resv
            USHORT UNPXEtw;          //+08 tag word
            USHORT UNPXErsv3;        //+0a resv
            ULONG  UNPXEfip;         //+0c float instruction pointer
            USHORT UNPXEfcs;         //+10 float code segment
            USHORT UNPXErsv4;        //+12 rsv(5bit)+float operation code
            ULONG  UNPXEfoo;         //+14 operand offset
            USHORT UNPXEfos;         //+18 operand segment
            USHORT UNPXErsv5;        //+1a resv
          } defint;
   struct {// bit type definition
        //cw
            UINT   UNPXEcw_im  :1;    //+00 cw 00    invalid operation mask
            UINT   UNPXEcw_dm  :1;    //+00 cw 01    denormal operand mask
            UINT   UNPXEcw_zm  :1;    //+00 cw 02    zero divide mask
            UINT   UNPXEcw_om  :1;    //+00 cw 03    overflow  mask
            UINT   UNPXEcw_um  :1;    //+00 cw 04    underflow mask
            UINT   UNPXEcw_pm  :1;    //+00 cw 05    precision mask
            UINT               :2;    //+00 cw 07-06
            UINT   UNPXEcw_pc  :2;    //+00 cw 09-08 precision ctl
            UINT   UNPXEcw_rc  :2;    //+00 cw 11-10 rounding ctl
            UINT               :4;    //+00 cw 15-12 rsv

            UINT               :16;   //+02 resv
        //sw
            UINT   UNPXEsw_ie  :1;    //+04 sw 00    invalid operation exception
            UINT   UNPXEsw_de  :1;    //+04 sw 01    denormal exception
            UINT   UNPXEsw_ze  :1;    //+04 sw 02    zero divide exception
            UINT   UNPXEsw_oe  :1;    //+04 sw 03    overflow exception
            UINT   UNPXEsw_ue  :1;    //+04 sw 04    underflow exception
            UINT   UNPXEsw_pe  :1;    //+04 sw 05    precision exception
            UINT   UNPXEsw_sf  :1;    //+04 sw 06    stack fault
            UINT   UNPXEsw_es  :1;    //+04 sw 07    error summary
            UINT   UNPXEsw_c0  :1;    //+04 sw 08    condition code 0
            UINT   UNPXEsw_c1  :1;    //+04 sw 09    condition code 1
            UINT   UNPXEsw_c2  :1;    //+04 sw 10    condition code 2
            UINT   UNPXEsw_top :3;    //+04 sw 13-11 top of stack
            UINT   UNPXEsw_c3  :1;    //+04 sw 14    condition code 3
            UINT   UNPXEsw_b   :1;    //+04 sw 15    busy 

            UINT               :16;   //+06 resv
        //tw
            UINT   UNPXEtw_r0  :2;    //+08 tag word for reg0
            UINT   UNPXEtw_r1  :2;    //+08 tag word for reg1
            UINT   UNPXEtw_r2  :2;    //+08 tag word for reg2
            UINT   UNPXEtw_r3  :2;    //+08 tag word for reg3
            UINT   UNPXEtw_r4  :2;    //+08 tag word for reg4
            UINT   UNPXEtw_r5  :2;    //+08 tag word for reg5
            UINT   UNPXEtw_r6  :2;    //+08 tag word for reg6
            UINT   UNPXEtw_r7  :2;    //+08 tag word for reg7

            UINT               :16;   //+0a resv
        //fip
            ULONG  UNPXEfip;          //+0c float instruction pointer
        //fcs+fop
            UINT               :16;   //+10 float code segment
            UINT   UNPXEfop    :11;   //+12 float operation code
            UINT               :5;    //+12 float operation code

          } defbit;
        } UNPXENV;

typedef UNPXENV*  PUNPXENV;
#endif                      //DPMI or not                          //~v032R~
//***************************************************************
#ifdef DPMI	    			//DPMI version                         //~v032I~
	static char has_error[] = {0,0,0,0,0,0,0,0 ,1,0,1,1,1,1,1,0 ,0,1 };//~v032I~
#endif                      //DPMI or not                          //~v032I~
  struct EXCTBL {ULONG excode;PSZ pexnamej;PSZ pexnamee;};
  static struct EXCTBL exctbl[]
         ={
#ifdef DPMI 				//DPMI version                         //~v032R~
            {0,	"�����[�����Z",			"INTEGER DIVIDE BY ZERO"	},//~v032R~
            {1,	"�f�o�b�O",				"DEBUG"			            },//~v032R~
            {2,	"NMI���荞��",			"NMI"						},//~v032R~
            {3,	"�u���[�N�|�C���g",		"BREAKPOINT"	           	},//~v032R~
            {4,	"�������ӂ�",			"INTEGER OVERFLOW"          },//~v032R~
            {5,	"�z�񋫊E",	    		"ARRAY BOUNDS EXCEEDED"		},//~v032R~
            {6,	"���߃R�[�h",			"ILLEGAL INSTRUCTION"       },//~v032R~
            {7,	"�R�v���Z�b�T�s��",		"CO-PROCESSOR NOT AVAIL"    },//~v032R~
            {8,	"�_�u���t�H�[���g",		"DOUBLE FAULT"			    },//~v032R~
            {9,	"�R�v���Z�b�T�I�[�o�[����","CO-PROCESSOR OVERRUN"   },//~v032R~
            {10,"�s��TSS",				"INVALID TSS"			    },//~v032R~
            {11,"�Z�O�����g�s��",   	"SEGMENT NOT PRESENT"       },//~v032R~
            {12,"�X�^�b�N�t�H�[���g",  	"STACK FAULT"				},//~v032R~
            {13,"��ʕی�"	,		   	"GENERAL PROTECTION FAULT"  },//~v032R~
            {14,"�y�[�W�t�H�[���g",    	"PAGE FAULT"                },//~v032R~
            {16,"���������_���Z�G���[",	"CO-PROCESSOR ERROR"        },//~v032R~
            {17,"����`�F�b�N",         "ALIGNMENT CHECK"			},//~v032R~
                                                                   //~v032R~
            {0x1b,"�u���C�N",         	"CONTROL+BREAK"				},//~v032R~
            {0x75,"���������_",		   	"FLOATING POINT EXCEPTION"  },//~v032R~
            {0x79,"�R���g���[��+C",   	"CONTROL+C"                 },//~v032R~
            {EXCEPTION_UABEND,"���[�U�[�A�x���h",   "USER ABEND"                },//~v032I~
#else                       //not DPMI                             //~v032R~
            {                                                      //~v022I~
		    XCPT_GUARD_PAGE_VIOLATION     ,"�K�[�h�y�[�W",
				"GUARD PAGE VIOLATION"                             //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_UNABLE_TO_GROW_STACK     ,"�ŏI�K�[�h�y�[�W",
		    	"UNABLE TO GROW STACK"                             //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_IN_PAGE_ERROR            ,"�y�[�W I/O",
		    	"PAGE ERROR",
            },                                                     //~v022R~
#ifdef W32                                                         //~v022R~
#else                                                              //~v022I~
            {                                                      //~v022I~
		    XCPT_PROCESS_TERMINATE        ,"�X���b�h�I��",
		   		"PROCESS TERMINATE"                                //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_ASYNC_PROCESS_TERMINATE  ,"���X���b�h�I��",
		    	"ASYNC PROCESS TERMINATE"                          //~v022R~
            },                                                     //~v022R~
#endif                                                             //~v022I~
            {                                                      //~v022I~
		    XCPT_NONCONTINUABLE_EXCEPTION ,"�p���v���s��",
		    	"NONCONTINUABLE EXCEPTION"                         //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_INVALID_DISPOSITION      ,"E.H �߂�R�[�h",
				"INVALID DISPOSITION"                              //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_ACCESS_VIOLATION         ,"�A�N�Z�X",
		    	"ACCESS VIOLATION"                                 //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_INTEGER_DIVIDE_BY_ZERO   ,"�����[�����Z",
		    	"INTEGER DIVIDE BY ZERO"                           //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_FLOAT_DIVIDE_BY_ZERO     ,"���������_�[�����Z",
		    	"FLOAT DIVIDE BY ZERO"                             //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_FLOAT_INVALID_OPERATION  ,"���������_����",
		    	"FLOAT INVALID OPERATION"                          //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_ILLEGAL_INSTRUCTION      ,"���߃R�[�h",
		    	"ILLEGAL INSTRUCTION"                              //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
   		    XCPT_PRIVILEGED_INSTRUCTION   ,"��������",
   		    	"PRIVILEGED INSTRUCTION"                           //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_INTEGER_OVERFLOW         ,"�������ӂ�",
		    	"INTEGER OVERFLOW"                                 //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_FLOAT_OVERFLOW           ,"���������_�゠�ӂ�",
		    	"FLOAT OVERFLOW"                                   //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_FLOAT_UNDERFLOW          ,"���������_�����ӂ�",
		    	"FLOAT UNDERFLOW"                                  //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_FLOAT_DENORMAL_OPERAND   ,"���������_�f�m�[�}���I�y�����h",
		    	"FLOAT DENORMAL OPERAND"                           //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_FLOAT_INEXACT_RESULT     ,"���������_���x",
		    	"FLOAT INEXACT RESULT"                             //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_FLOAT_STACK_CHECK        ,"���������_�X�^�b�N",
		    	"FLOAT STACK CHECK"                                //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
            XCPT_DATATYPE_MISALIGNMENT    ,"�f�[�^���E",
            	"DATATYPE MISALIGNMENT"                            //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_BREAKPOINT               ,"�u���[�N�|�C���g",
		    	"BREAKPOINT"                                       //~v022R~
            },                                                     //~v022I~
            {                                                      //~v022I~
		    XCPT_SINGLE_STEP              ,"�V���O���X�e�b�v",
		    	"SINGLE STEP"                                      //~v022R~
            },                                                     //~v022R~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
            {                                                      //~v022I~
		    XCPT_INVALID_LOCK_SEQUENCE    ,"LOCK SEQUENCE",
		    	"INVALID LOCK SEQUENCE"                            //~v022R~
            },                                                     //~v022R~
#endif                                                             //~v022I~
            {                                                      //~v022I~
		    XCPT_ARRAY_BOUNDS_EXCEEDED    ,"�z�񋫊E",
		    	"ARRAY BOUNDS EXCEEDED"                            //~v022R~
            },                                                     //~v022R~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
            {                                                      //~v022I~
		    XCPT_UNWIND                   ,"�����߂�",
		    	"UNWIND"                                           //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_BAD_STACK                ,"E.H�X�^�b�N",
		    	"BAD STACK"                                        //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_INVALID_UNWIND_TARGET    ,"�����߂��ڕW",
		    	"INVALID UNWIND TARGET"                            //~v022R~
            },                                                     //~v022R~
            {                                                      //~v022I~
		    XCPT_SIGNAL                   ,"�V�O�i��",
		    	"SIGNAL"                                           //~v022R~
            },                                                     //~v022R~
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v032R~
            {                                                      //~v022I~
		    0   /*table search stopper*/  ,"--------",
		    	"--------"                                         //~v022I~
            }                                                      //~v022I~
          };
#ifdef DPMI				    //DPMI version                         //~v032R~
static UCHAR *parmercj	    ="�G���[�R�[�h";                       //~v032R~
static UCHAR *parmerce  	="ERROR CODE";                         //~v032R~
#else                       //not DPMI                             //~v032R~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
static UCHAR *parmfragj		="�t���O ......W/R"; 
static UCHAR *parmfrage		="flag   ......W/R"; 
static UCHAR *parmvaddrj	="���z�A�h���X";
static UCHAR *parmvaddre	="virtual addr";
static UCHAR *parmfrag2j	="�t���O ...L/S/E/W/R"; 
static UCHAR *parmfrag2e	="flag   ...L/S/E/W/R"; 
static UCHAR *parmaddrnaj	="�A�h���X�s��";
static UCHAR *parmaddrnae	="address N/A ";
static UCHAR *parmxaddrj	="��O�A�h���X";
static UCHAR *parmxaddre	="exceptn addr";
static UCHAR *parmbmaskj	="���E���킹�}�X�N";
static UCHAR *parmbmaske	="boundary mask   ";
static UCHAR *parmthreadj	="�I���X���b�hID";
static UCHAR *parmthreade	="end Thread ID ";
static UCHAR *parmpfendj	="�v���Z�X�����I��";
static UCHAR *parmpfende	="Process Forced  ";
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v032R~

//static UCHAR constnaj[]="�֐����s��";                            //~v6F1R~
//static UCHAR constnae[]="Function name N/A";                     //~v6F1R~
#define MAX_FUNCNAME 24                                            //~v6F1I~
static UCHAR constnaj[MAX_FUNCNAME]="�֐����s��";                  //~v6F1I~
static UCHAR constnae[MAX_FUNCNAME]="Function name N/A";           //~v6F1I~
//static UCHAR constspace[]=" ";                                   //~v022R~
//static UCHAR msgehmsgtitle[]="Exception Report\n";               //~v6VvR~
static UCHAR msgehmsgtitle[]="Exception Report";                   //~v6VvI~
#ifdef ULIB64X                                                     //~v6F1I~
  static UCHAR msgprotexaddrj[]                                    //~v6F1I~
         =DUMPTITLEID "�A�h���X %p(%-24.24s)��%s��O(%08X)\n%n";   //~v6F1I~
  static UCHAR msgprotexaddre[]                                    //~v6F1I~
         =DUMPTITLEID "Addr %p(%-24.24s) Exception %s(%08X)\n%n";  //~v6F1I~
#else                                                              //~v6F1I~
  static UCHAR msgprotexaddrj[]
         =DUMPTITLEID "�A�h���X %08X(%-24.24s)��%s��O(%08X)\n%n"; //~v032R~
  static UCHAR msgprotexaddre[]
//       =DUMPTITLEID "Addr %08X(%-14.14s) Exception %s(%08X)\n%n";//~v032R~//~v6F1R~
         =DUMPTITLEID "Addr %08X(%-24.24s) Exception %s(%08X)\n%n";//~v6F1I~
#endif                                                             //~v6F1I~
  static UCHAR msgprotcodedump1j[]
         ="�R�[�h�_���v�@(�A�h���X:%08X ���@%02d �o�C�g)\n  %n";//~5105R~
  static UCHAR msgprotcodedump1e[]
         ="Code Seg Dump (Addr:%08X %02d byte)\n  %n";          //~5105R~
  static UCHAR msgprotcodedump2[]
         =" %08X%n";                                            //~5105R~
  static UCHAR msgprotcodedump3j[]
         =" �A�N�Z�X�ł��܂���%n";                                 //~v022R~
  static UCHAR msgprotcodedump3e[]
         =" Not Avail%n";
  static UCHAR msgprotparm1[]
#ifdef ULIB64X                                                     //+i called//~v6T3R~
         ="P%1d=%p(%s) %n";  //with description                    //~v6T3M~
#else                                                              //~v6T3M~
         ="P%1d=%08X(%s) %n";  //with description               //~5105R~
#endif                                                             //~v6T3R~
  static UCHAR msgprotparm2[]
#ifdef ULIB64X                                                     //~v6T3R~
         ="P%1d=%p %n";      //without description                 //~v6T3I~
#else                                                              //~v6T3M~
         ="P%1d=%08X %n";      //without description            //~5105R~
#endif                                                             //~v6T3R~
  static UCHAR msgprotintreg[]
         ="EAX=%08X EBX=%08X ECX=%08X EDX=%08X ESI=%08X EDI=%08X\n%n";//~5105R~
  static UCHAR msgprotsegreg[]
         ="DS=%04X ES=%04X FS=%04X GS=%04X\n%n";                //~5105R~
  static UCHAR msgprotctlreg[]
         ="CS=%04X EIP=%08X  SS=%04X ESP=%08X EBP=%08X  FLG=%08X\n%n";//~5105R~
#ifdef DPMI	    			//DPMI version                         //~v032R~
#else                       //not DPMI                             //~v032R~
  static UCHAR msgprotnpx1[]
         ="NPX: CW=%04X SW=%04X(TOP=%1d) TW(7-0)=%04X\n\
     OPCODE=%04X FIP=%04X:%08X OPERAND=%04X:%08X\n%n";          //~5105R~
  static UCHAR msgprotnpx2[]
         ="    ST(%1d): %04X-%08X %08X  ST(%1d): %04X-%08X %08X\n%n";//~5105R~
#endif                      //DPMI or not                          //~v032R~
#ifdef ULIB64X                                                     //~v6F1I~
	int uehstacktracemsg(int Popt,void *Pexceptionaddr,char *Pmsgout);//~v6F1R~
	#define UEHSMO_EXCEPTIONADDR    0x01                           //~v6F1I~
	#define UEHSMO_SYMINIT          0x02    //need only once       //~v6F1I~
#endif                      //DPMI or not                          //~v6F1I~
#ifndef ULIB64X                                                    //~v6F1I~
//*************************************************************
//* uehmsg                                                         //~v6F1R~
//* INPUT      :
//*     p1:exception report
//*     p2:registration record
//*     p3:context record
//*     p4:epatbl ptr
//*     p5:uerrexit msg                                         //~5827I~
//* RETURN     : abend msg area addr
//*             display exception information by msgbox
//*************************************************************

UCHAR*  uehmsg(PEXCEPTIONREPORTRECORD pexreprec,
	           	PEXCEPTIONREGISTRATIONRECORD pexregrec,
               	PCONTEXTRECORD pctxrec,
				PEPATBL Ppepatbl,                               //~5827R~
				UCHAR   *Puerrexitmsg)                          //~5827I~
{ 
#ifdef DPMI			    	//DPMI version                         //~v032R~
	UCHAR *parmerc;                                                //~v032R~
#else                       //not DPMI                             //~v032R~
	PUEXREGREC purr;                                               //~v286I~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
	UCHAR *parmfrag,*parmvaddr,*parmfrag2,*parmaddrna,*parmxaddr,  //~v022I~
		  *parmpfend,*parmthread,*parmbmask;                       //~v022R~
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v032R~
  APIRET apiret;
  ULONG  exnum;             //exception number
  PVOID allocmem;           //pvoid work msg area
  UCHAR *msgwk;             //work msg area
  UCHAR *pcurfunc,*pchar;
  ULONG i,j;             //work index
  int   offset;               //sprintf %n offset     
  PVOID pepa;              //fumction entry point ptr
//ULONG  pstacktop,pstackend;     //committed stack start/end      //~v022R~
#ifdef DPMI	    			//DPMI version                         //~v032R~
#else                       //not DPMI                             //~v032R~
  PUNPXENV punpxenv;    //npx environment field
#endif                      //DPMI or not                          //~v032R~
	PPATHTBL ppathtbl;
	UCHAR *constna,*msgprotexaddr,*msgprotcodedump1,*msgprotcodedump3;
	UCHAR *pc;
	int dbcssw;
//*****************
//UTRACED("ehmsg entry",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
  exnum=pexreprec->ExceptionNum; //exception number
//ugetstackaddr(&pstacktop,&pstackend);//get stack top,end         //~v022R~
//****************************
//* alocate work msg         *
//****************************
#ifdef DPMI	    			//DPMI version                         //~v032R~
    allocmem=malloc(WKMSGSIZE);        //req len                   //~v032R~
    if (!allocmem)                                                 //~v032R~
    	uerrexit("malloc failed,len=%d",0,WKMSGSIZE);              //~v032R~
#else                       //not DPMI                             //~v032R~
	purr=(PUEXREGREC)(void*)pexregrec;                             //~v286I~
#ifdef W32                                                         //~v022I~
	allocmem=HeapAlloc(GetProcessHeap(),                           //~v022R~
						HEAP_ZERO_MEMORY,//flag=clear,return NULL,serialize//~v022R~
                    	WKMSGSIZE);        //req len               //~v022R~
	if (!allocmem)                                                 //~v022R~
    	apiret=GetLastError();                                     //~v022R~
	else                                                           //~v022R~
    {                                                              //~v022I~
    	apiret=0;                                                  //~v022M~
		apiret=apiret*((PUEXREGREC)(PVOID)pexregrec)->UERGthreadid;//for compiler warning//~v022I~
    }                                                              //~v022I~
//  printf("allocmem=%08x\n",allocmem);                            //~v022R~
   if(apiret)                                                      //~v032I~
      uerrexit("HeapAlloc failed,len=%d,rc=%d",0,WKMSGSIZE,apiret);//~v032I~
#else                                                              //~v022I~
   apiret=DosAllocMem( &allocmem,             //output:addr
                       WKMSGSIZE,             //len
                       PAG_COMMIT      //input attr,commit page
                        | PAG_WRITE    //writable
                     );                                   //
   if(apiret)
      uerrexit("DosAllocMem failed,len=%d,rc=%d",0,WKMSGSIZE,apiret);
#endif                                                             //~v032M~
#endif                      //DPMI or not                          //~v032R~
	msgwk=allocmem;
//UTRACEP("get  msgwk=%08x\n",msgwk);                              //~v171R~
//  strcpy(msgwk,msgehmsgtitle);                                   //~v6VvR~
//  msgwk+=sizeof(msgehmsgtitle)-1;                                //~v6VvR~
    msgwk+=sprintf(msgwk,"%s : pid=%ld\n",msgehmsgtitle,ugetpid());//+v6VvR~

//  if (dbcssw=udbcschk(0x81),dbcssw)                              //~v150R~
    if (dbcssw=udbcschkcp(),dbcssw)                                //~v150I~
	{
		constna=constnaj;
		msgprotexaddr=msgprotexaddrj;
		msgprotcodedump1=msgprotcodedump1j;
		msgprotcodedump3=msgprotcodedump3j;
#ifdef DPMI		    		//DPMI version                         //~v032R~
		parmerc=parmercj;                                          //~v032R~
#else                       //not DPMI                             //~v032R~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
		parmfrag=parmfragj;
		parmvaddr=parmvaddrj;
		parmfrag2=parmfrag2j;
		parmaddrna=parmaddrnaj;
		parmxaddr=parmxaddrj;
		parmbmask=parmbmaskj;
		parmthread=parmthreadj;
		parmpfend=parmpfendj;
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v032R~
	}
	else
	{
		constna=constnae;
		msgprotexaddr=msgprotexaddre;
		msgprotcodedump1=msgprotcodedump1e;
		msgprotcodedump3=msgprotcodedump3e;
#ifdef DPMI			    	//DPMI version                         //~v032R~
		parmerc=parmerce;                                          //~v032R~
#else                       //not DPMI                             //~v032R~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
		parmfrag=parmfrage;
		parmvaddr=parmvaddre;
		parmfrag2=parmfrag2e;
		parmaddrna=parmaddrnae;
		parmxaddr=parmxaddre;
		parmbmask=parmbmaske;
		parmthread=parmthreade;
		parmpfend=parmpfende;
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v032R~
	}
//**********************
//* abend module name  *
//**********************
	pcurfunc=constna;                    //if failed
	offset=0;
	if (pctxrec->ContextFlags & CONTEXT_CONTROL)//valid segment fields
	{
//UTRACED("before funcpathtbl",(char*)( ((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
		ppathtbl=ufuncpathtbl(Ppepatbl,
				pctxrec->ctx_RegEbp,
//				(ULONG)pexreprec->ExceptionAddress);               //~v6hhR~
 				(ULPTR)pexreprec->ExceptionAddress);               //~v6hhI~
//UTRACED("after  funcpathtbl",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
		if (ppathtbl)
		{
			pcurfunc=ppathtbl->funcname;
//* call path           *
//UTRACED("before pathmsgsub ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
			offset=ufuncpathmsgsub(ppathtbl,msgwk);
//UTRACED("before pathmsgsub ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
		}
	}
//*uerrexit msg
	if (Puerrexitmsg)                                           //~5827R~
    {                                                              //~v022I~
//      printf("exitmsg=%s======\n",Puerrexitmsg);                 //~v022R~
	   sprintf(msgwk+=offset,DUMPTITLEID "%s\n%n",Puerrexitmsg,&offset);//~v032R~
    }                                                              //~v022I~
    else                                                           //~v288I~
	   sprintf(msgwk+=offset,DUMPTITLEID "%s\n%n","No ExitMsg",&offset);//~v288I~
//UTRACED("before geterrmsg  ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
	if (pc=ugeterrmsg(),pc)     //ufuncmap errmsg               //~5827I~
    {                                                              //~v022I~
//      printf("funcmapmsg =%s",pc);                               //~v022R~
	   sprintf(msgwk+=offset,DUMPTITLEID "%s\n%n",pc,&offset);     //~v032R~
    }                                                              //~v022I~
//UTRACED("aftere geterrmsg  ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
//**********************
//* conv code to kanji *
//**********************
   for (i=0;                                                       //~v032R~
        #ifdef DPMI					//DPMI version                 //~v032I~
            !i ||                                                  //~v032I~
        #else                       //not DPMI                     //~v032I~
        #endif                      //DPMI or not                  //~v032I~
		exctbl[i].excode;i++)     //exception code tbl search      //~v032I~
   {
     if (exnum==exctbl[i].excode) break;
   }
//****line set   
	if (dbcssw)
		pc=exctbl[i].pexnamej;
	else
		pc=exctbl[i].pexnamee;
   sprintf(msgwk+=offset,msgprotexaddr,
           pexreprec->ExceptionAddress,  //abend addr
           pcurfunc,                      //abend function name
           pc,				            //exceptio name
           exnum,		                 //abend code
           &offset);                     //%n output(current offset)

#ifdef DPMI					//DPMI version                         //~v032I~
    if (exnum!=EXCEPTION_UABEND)                                   //~v032I~
    {                                                              //~v032I~
#else                       //not DPMI                             //~v032I~
#endif                      //DPMI or not                          //~v032I~
//**********************
//* code data dump     *
//**********************
//UTRACED("before codedump   ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
   pepa=pexreprec->ExceptionAddress;      //abend addr
   i=32;                                 //before16 after 16 byte dump
   sprintf((msgwk+=offset),msgprotcodedump1,
           (UCHAR*)pepa-16,              //dump start addr
           i,                            //length 
           &offset);                     //%n output(current offset)

	apiret=                                                        //~v022I~
// umemchk((ULONG)((UCHAR*)pepa-16),   //from 16 byte before       //~v6hhR~
   umemchk((ULPTR)((UCHAR*)pepa-16),   //from 16 byte before       //~v6hhI~
           &i,                 //in:size,out:scaned size
           &j);                //out:attr of scaned range page

//UTRACED("after  memchk     ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
   i=(i>>2)<<2;          //cut 4 byte boundary of scaned len
   if ( !apiret && i && (j & PAG_COMMIT) )   //commited
     for (j=0;j<i;j+=4)         //by 4 byte
     {
       sprintf((msgwk+=offset),msgprotcodedump2,
               USTRLOAD((UCHAR*)pepa-16+j),  //4 byte dump
               &offset);                     //%n output(current offset)
     }   //by 4 byte
   else
   {                                                               //~v022I~
     sprintf((msgwk+=offset),msgprotcodedump3,
             &offset);                     //%n output(current offset)
	}                                                              //~v022I~
   strcat(msgwk,"\n");     
   offset++;
#ifdef DPMI					//DPMI version                         //~v032I~
    }//not uabend                                                  //~v032I~
#else                       //not DPMI                             //~v032I~
#endif                      //DPMI or not                          //~v032I~
//*******************************
//* max 4 exception information *
//*******************************
   for(i=0;i<pexreprec->cParameters;i++)
   {
//*********************************
//* set description for each exnum*
//*********************************
     pchar=NULL;
#ifdef DPMI				    //DPMI version                         //~v032R~
	if (exnum<sizeof(has_error)                                    //~v032I~
    &&  has_error [exnum]                                          //~v032R~
    &&  pexreprec->ExceptionInfo[i])	//same as libc\go32\dpmiexcp.c//~v032I~
		pchar=parmerc;                                             //~v032R~
#else                       //not DPMI                             //~v032R~
#ifdef W32                                                         //~v022I~
#else                                                              //~v022I~
     switch (exnum)
     {
     case XCPT_GUARD_PAGE_VIOLATION:
       if (i==0) pchar=parmfrag;
       if (i==1) pchar=parmvaddr;
       break;
     case XCPT_ACCESS_VIOLATION:
       if (i==0) pchar=parmfrag2;
       if (i==1)
         if (pexreprec->ExceptionInfo[i]==XCPT_DATA_UNKNOWN)
	       pchar=parmaddrna;
		 else
	       pchar=parmxaddr;
       break;
     case XCPT_DATATYPE_MISALIGNMENT:
       if (i==0) pchar=parmfrag;
       if (i==1) pchar=parmbmask;
       if (i==2) pchar=parmvaddr;
       break;
     case XCPT_IN_PAGE_ERROR:
       if (i==1) pchar=parmvaddr;
       break;
     case XCPT_ASYNC_PROCESS_TERMINATE:
       if (i==0) pchar=parmthread;
       break;
     case XCPT_SIGNAL:
       if (i==0)
       {
         switch(pexreprec->ExceptionInfo[i])
         { 
         case XCPT_SIGNAL_INTR:
	       pchar="Ctrl+C";
		   break;
         case XCPT_SIGNAL_KILLPROC:
	       pchar=parmpfend;
		   break;
         case XCPT_SIGNAL_BREAK:
	       pchar="Ctrl+Break";
		   break;
		 }//switch by signal id
       }
       break;
     }
#endif                                                             //~v022I~
#endif                      //DPMI or not                          //~v032R~
                                                                   //~v022I~
     if (pchar)
       sprintf((msgwk+=offset),msgprotparm1,
               i,pexreprec->ExceptionInfo[i],pchar,
               &offset);                     //%n output(current offset)
     else
       sprintf((msgwk+=offset),msgprotparm2,
               i,pexreprec->ExceptionInfo[i],//without description
               &offset);                     //%n output(current offset)
   }
   if (pexreprec->cParameters)
   {
     strcat(msgwk,"\n");
     offset++;
   }
#ifdef DPMI		    		//DPMI version                         //~v032R~
#else                       //not DPMI                             //~v032R~
//**********************
//*NPX ENV             *
//**********************
//UTRACED("before NPXENV ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
 if (purr->UERGentryctr==1)   //only 1st entry                     //~v286I~
   if (pctxrec->ContextFlags & CONTEXT_FLOATING_POINT)//valid float fields
   {
     punpxenv=(PUNPXENV)(PVOID)(pctxrec->ctx_env);
     sprintf((msgwk+=offset),msgprotnpx1,
             punpxenv->defint.UNPXEcw,    
             punpxenv->defint.UNPXEsw,    
             punpxenv->defbit.UNPXEsw_top,    
             punpxenv->defint.UNPXEtw,    
             punpxenv->defbit.UNPXEfop,
             punpxenv->defint.UNPXEfcs,
             punpxenv->defint.UNPXEfip,
             punpxenv->defint.UNPXEfos,   
             punpxenv->defint.UNPXEfoo,  
             &offset);                     //%n output(current offset)
//*stack 
     for (i=0;i<8;i+=2)
	 {
       sprintf((msgwk+=offset),msgprotnpx2,
               i,
               pctxrec->ctx_stack[i  ].signexp,
               pctxrec->ctx_stack[i  ].hisig,
               pctxrec->ctx_stack[i  ].losig,
               i+1,
               pctxrec->ctx_stack[i+1].signexp,
               pctxrec->ctx_stack[i+1].hisig,
               pctxrec->ctx_stack[i+1].losig,
               &offset);                     //%n output(current offset)
     }
   }
#endif                      //DPMI or not                          //~v032R~
//**********************
//* register           *
//**********************
//* integer reg
//UTRACED("before REG ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
   if (pctxrec->ContextFlags & CONTEXT_INTEGER)//valid integer fields
   {
     sprintf((msgwk+=offset),msgprotintreg,
             pctxrec->ctx_RegEax,          //EAX
             pctxrec->ctx_RegEbx,          //EBX
             pctxrec->ctx_RegEcx,          //ECX
             pctxrec->ctx_RegEdx,          //EDX
             pctxrec->ctx_RegEsi,          //Esi
             pctxrec->ctx_RegEdi,          //Edi
             &offset);                     //%n output(current offset)
   }

//* segment reg
   if (pctxrec->ContextFlags & CONTEXT_SEGMENTS)//valid segment fields
   {
     sprintf((msgwk+=offset),msgprotsegreg,
             pctxrec->ctx_SegDs,          //DS
             pctxrec->ctx_SegEs,          //ES
             pctxrec->ctx_SegFs,          //FS
             pctxrec->ctx_SegGs,          //GS
             &offset);                     //%n output(current offset)
   }

//* control reg
   if (pctxrec->ContextFlags & CONTEXT_CONTROL)//valid segment fields
   {
     sprintf((msgwk+=offset),msgprotctlreg,
             pctxrec->ctx_SegCs,          //CS
             pctxrec->ctx_RegEip,         //EIP
             pctxrec->ctx_SegSs,          //SS
             pctxrec->ctx_RegEsp,         //ESP
             pctxrec->ctx_RegEbp,         //EBP
             pctxrec->ctx_EFlags,        //FLAGS
             &offset);                     //%n output(current offset)
   }

//****************************
//* msgbox                   *
//****************************
//UTRACEP("last  msgwk=%08x\n",msgwk);                             //~v171R~
  msgwk=allocmem; //recover top addr
//UTRACED("before uerrmsg",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v171R~
//uerrmsg(msgwk,msgwk);                                            //~v171R~
//UTRACED("after  uerrmsg",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v171R~
//  ugeterrmsg();			//clear for next call                  //~v171R~
//UTRACED("before return ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~
  printf(msgwk);                                                   //~v171I~
  return msgwk;                                   //a930223
}//uehmsg
#else   //ULIB64X                                                  //~v6F1I~
//*************************************************************    //~v6F1I~
//* uehmsg                                                         //~v6F1I~
//*     p3:context record:NULL                                     //~v6F1R~
//*     p4:epatbl ptr    :NULL                                     //~v6F1R~
//*************************************************************    //~v6F1I~
UCHAR*  uehmsg(PEXCEPTIONREPORTRECORD pexreprec,                   //~v6F1I~
	           	PEXCEPTIONREGISTRATIONRECORD pexregrec,            //~v6F1I~
               	PCONTEXTRECORD pctxrec,                            //~v6F1I~
				PEPATBL Ppepatbl,                               //~5827R~//~v6F1I~
				UCHAR   *Puerrexitmsg)                          //~5827I~//~v6F1I~
{                                                                  //~v6F1I~
	PUEXREGREC purr;                                               //~v286I~//~v6F1I~
  APIRET apiret;                                                   //~v6F1I~
  ULONG  exnum;             //exception number                     //~v6F1I~
  PVOID allocmem;           //pvoid work msg area                  //~v6F1I~
  UCHAR *msgwk;             //work msg area                        //~v6F1I~
  UCHAR *pcurfunc,*pchar;                                          //~v6F1I~
  ULONG i;             //work index                                //~v6F1R~
  int   offset;               //sprintf %n offset                  //~v6F1I~
//  PVOID pepa;              //fumction entry point ptr            //~v6F1R~
//ULONG  pstacktop,pstackend;     //committed stack start/end      //~v022R~//~v6F1I~
//  PUNPXENV punpxenv;    //npx environment field                  //~v6F1R~
//    PPATHTBL ppathtbl;                                           //~v6F1R~
	UCHAR *constna,*msgprotexaddr,*msgprotcodedump1,*msgprotcodedump3;//~v6F1I~
	UCHAR *pc;                                                     //~v6F1I~
	int dbcssw;                                                    //~v6F1I~
    char wkexcfunc[255];                                           //~v6F1I~
//*****************                                                //~v6F1I~
//UTRACED("ehmsg entry",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1I~
  exnum=pexreprec->ExceptionNum; //exception number                //~v6F1I~
//****************************                                     //~v6F1I~
//* alocate work msg         *                                     //~v6F1I~
//****************************                                     //~v6F1I~
	purr=(PUEXREGREC)(void*)pexregrec;                             //~v286I~//~v6F1I~
	allocmem=HeapAlloc(GetProcessHeap(),                           //~v022R~//~v6F1I~
						HEAP_ZERO_MEMORY,//flag=clear,return NULL,serialize//~v022R~//~v6F1I~
                    	WKMSGSIZE);        //req len               //~v022R~//~v6F1I~
	if (!allocmem)                                                 //~v022R~//~v6F1I~
    	apiret=GetLastError();                                     //~v022R~//~v6F1I~
	else                                                           //~v022R~//~v6F1I~
    {                                                              //~v022I~//~v6F1I~
    	apiret=0;                                                  //~v022M~//~v6F1I~
		apiret=apiret*((PUEXREGREC)(PVOID)pexregrec)->UERGthreadid;//for compiler warning//~v022I~//~v6F1I~
    }                                                              //~v022I~//~v6F1I~
   if(apiret)                                                      //~v032I~//~v6F1I~
      uerrexit("HeapAlloc failed,len=%d,rc=%d",0,WKMSGSIZE,apiret);//~v032I~//~v6F1I~
	msgwk=allocmem;                                                //~v6F1I~
//  strcpy(msgwk,msgehmsgtitle);                                   //~v6F1I~//~v6VvR~
//  msgwk+=sizeof(msgehmsgtitle)-1;                                //~v6F1I~//~v6VvR~
    msgwk+=sprintf(msgwk,"%s : pid=%ld\n",msgehmsgtitle,ugetpid());//+v6VvR~
    *msgwk++='\n';                                                 //~v6F1R~
	msgwk+=uehstacktracemsg(UEHSMO_SYMINIT,pexreprec->ExceptionAddress,msgwk);//~v6F1R~
    if (dbcssw=udbcschkcp(),dbcssw)                                //~v150I~//~v6F1I~
	{                                                              //~v6F1I~
		constna=constnaj;                                          //~v6F1I~
		msgprotexaddr=msgprotexaddrj;                              //~v6F1I~
		msgprotcodedump1=msgprotcodedump1j;                        //~v6F1I~
		msgprotcodedump3=msgprotcodedump3j;                        //~v6F1I~
	}                                                              //~v6F1I~
	else                                                           //~v6F1I~
	{                                                              //~v6F1I~
		constna=constnae;                                          //~v6F1I~
		msgprotexaddr=msgprotexaddre;                              //~v6F1I~
		msgprotcodedump1=msgprotcodedump1e;                        //~v6F1I~
		msgprotcodedump3=msgprotcodedump3e;                        //~v6F1I~
	}                                                              //~v6F1I~
//**********************                                           //~v6F1I~
//* abend module name  *                                           //~v6F1I~
//**********************                                           //~v6F1I~
	pcurfunc=constna;                    //if failed               //~v6F1I~
	if (uehstacktracemsg(UEHSMO_EXCEPTIONADDR,pexreprec->ExceptionAddress,wkexcfunc))	//exception addr funcname gotten//~v6F1R~
    {	                                                           //~v6F1I~
    	wkexcfunc[MAX_FUNCNAME-1]=0;                               //~v6F1R~
        pcurfunc=wkexcfunc;                                        //~v6F1I~
    }                                                              //~v6F1I~
	offset=0;                                                      //~v6F1I~
//    if (pctxrec->ContextFlags & CONTEXT_CONTROL)//valid segment fields//~v6F1R~
//    {                                                            //~v6F1R~
////UTRACED("before funcpathtbl",(char*)( ((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1R~
//        ppathtbl=ufuncpathtbl(Ppepatbl,                          //~v6F1R~
//                pctxrec->ctx_RegEbp,                             //~v6F1R~
//                (ULPTR)pexreprec->ExceptionAddress);               //~v6hhI~//~v6F1R~
////UTRACED("after  funcpathtbl",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1R~
//        if (ppathtbl)                                            //~v6F1R~
//        {                                                        //~v6F1R~
//            pcurfunc=ppathtbl->funcname;                         //~v6F1R~
////* call path           *                                        //~v6F1R~
////UTRACED("before pathmsgsub ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1R~
//            offset=ufuncpathmsgsub(ppathtbl,msgwk);              //~v6F1R~
////UTRACED("before pathmsgsub ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1R~
//        }                                                        //~v6F1R~
//    }                                                            //~v6F1R~
//*uerrexit msg                                                    //~v6F1I~
                                                                   //~v6F1I~
	if (Puerrexitmsg)                                           //~5827R~//~v6F1I~
    {                                                              //~v022I~//~v6F1I~
//      printf("exitmsg=%s======\n",Puerrexitmsg);                 //~v022R~//~v6F1I~
	   sprintf(msgwk+=offset,DUMPTITLEID "%s\n%n",Puerrexitmsg,&offset);//~v032R~//~v6F1I~
    }                                                              //~v022I~//~v6F1I~
    else                                                           //~v288I~//~v6F1I~
	   sprintf(msgwk+=offset,DUMPTITLEID "%s\n%n","No ExitMsg",&offset);//~v288I~//~v6F1I~
//UTRACED("before geterrmsg  ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1I~
	if (pc=ugeterrmsg(),pc)     //ufuncmap errmsg               //~5827I~//~v6F1I~
    {                                                              //~v022I~//~v6F1I~
//      printf("funcmapmsg =%s",pc);                               //~v022R~//~v6F1I~
	   sprintf(msgwk+=offset,DUMPTITLEID "%s\n%n",pc,&offset);     //~v032R~//~v6F1I~
    }                                                              //~v022I~//~v6F1I~
//UTRACED("aftere geterrmsg  ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1I~
//**********************                                           //~v6F1I~
//* conv code to kanji *                                           //~v6F1I~
//**********************                                           //~v6F1I~
   for (i=0;                                                       //~v032R~//~v6F1I~
		exctbl[i].excode;i++)     //exception code tbl search      //~v032I~//~v6F1I~
   {                                                               //~v6F1I~
     if (exnum==exctbl[i].excode) break;                           //~v6F1I~
   }                                                               //~v6F1I~
//****line set                                                     //~v6F1I~
	if (dbcssw)                                                    //~v6F1I~
		pc=exctbl[i].pexnamej;                                     //~v6F1I~
	else                                                           //~v6F1I~
		pc=exctbl[i].pexnamee;                                     //~v6F1I~
   sprintf(msgwk+=offset,msgprotexaddr,                            //~v6F1I~
           pexreprec->ExceptionAddress,  //abend addr              //~v6F1I~
           pcurfunc,                      //abend function name    //~v6F1I~
           pc,				            //exceptio name            //~v6F1I~
           exnum,		                 //abend code              //~v6F1I~
           &offset);                     //%n output(current offset)//~v6F1I~
	UTRACEP("%s:exception code=%08x=%s,msgwk=%s,offset=%d\n",UTT,exnum,pc,msgwk,offset);//~v6F1R~
//**********************                                           //~v6F1I~
//* code data dump     *                                           //~v6F1I~
//**********************                                           //~v6F1I~
//UTRACED("before codedump   ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1I~
//   pepa=pexreprec->ExceptionAddress;      //abend addr           //~v6F1R~
//   i=32;                                 //before16 after 16 byte dump//~v6F1R~
//   sprintf((msgwk+=offset),msgprotcodedump1,                     //~v6F1R~
//           (UCHAR*)pepa-16,              //dump start addr       //~v6F1R~
//           i,                            //length                //~v6F1R~
//           &offset);                     //%n output(current offset)//~v6F1R~
//                                                                 //~v6F1R~
//    apiret=                                                        //~v022I~//~v6F1R~
//   umemchk((ULPTR)((UCHAR*)pepa-16),   //from 16 byte before       //~v6hhI~//~v6F1R~
//           &i,                 //in:size,out:scaned size         //~v6F1R~
//           &j);                //out:attr of scaned range page   //~v6F1R~
//                                                                 //~v6F1R~
////UTRACED("after  memchk     ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1R~
//   i=(i>>2)<<2;          //cut 4 byte boundary of scaned len     //~v6F1R~
//   if ( !apiret && i && (j & PAG_COMMIT) )   //commited          //~v6F1R~
//     for (j=0;j<i;j+=4)         //by 4 byte                      //~v6F1R~
//     {                                                           //~v6F1R~
//       sprintf((msgwk+=offset),msgprotcodedump2,                 //~v6F1R~
//               USTRLOAD((UCHAR*)pepa-16+j),  //4 byte dump       //~v6F1R~
//               &offset);                     //%n output(current offset)//~v6F1R~
//     }   //by 4 byte                                             //~v6F1R~
//   else                                                          //~v6F1R~
//   {                                                               //~v022I~//~v6F1R~
//     sprintf((msgwk+=offset),msgprotcodedump3,                   //~v6F1R~
//             &offset);                     //%n output(current offset)//~v6F1R~
//    }                                                              //~v022I~//~v6F1R~
//*******************************                                  //~v6F1I~
//* max 4 exception information *                                  //~v6F1I~
//*******************************                                  //~v6F1I~
   for(i=0;i<pexreprec->cParameters;i++)                           //~v6F1I~
   {                                                               //~v6F1I~
//*********************************                                //~v6F1I~
//* set description for each exnum*                                //~v6F1I~
//*********************************                                //~v6F1I~
     pchar=NULL;                                                   //~v6F1I~
                                                                   //~v022I~//~v6F1I~
//     if (pchar)                                                  //~v6F1R~
//       sprintf((msgwk+=offset),msgprotparm1,                     //~v6F1R~
//               i,pexreprec->ExceptionInfo[i],pchar,              //~v6F1R~
//               &offset);                     //%n output(current offset)//~v6F1R~
//     else                                                        //~v6F1R~
       sprintf((msgwk+=offset),msgprotparm2,                       //~v6F1I~
               i,pexreprec->ExceptionInfo[i],//without description //~v6F1I~
               &offset);                     //%n output(current offset)//~v6F1I~
   }                                                               //~v6F1I~
   if (pexreprec->cParameters)                                     //~v6F1I~
   {                                                               //~v6F1I~
     strcat(msgwk,"\n");                                           //~v6F1I~
     offset++;                                                     //~v6F1I~
   }                                                               //~v6F1I~
//**********************                                           //~v6F1I~
//*NPX ENV             *                                           //~v6F1I~
//**********************                                           //~v6F1I~
//UTRACED("before NPXENV ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1I~
// if (purr->UERGentryctr==1)   //only 1st entry                     //~v286I~//~v6F1R~
//   if (pctxrec->ContextFlags & CONTEXT_FLOATING_POINT)//valid float fields//~v6F1R~
//   {                                                             //~v6F1R~
//     punpxenv=(PUNPXENV)(PVOID)(pctxrec->ctx_env);               //~v6F1R~
//     sprintf((msgwk+=offset),msgprotnpx1,                        //~v6F1R~
//             punpxenv->defint.UNPXEcw,                           //~v6F1R~
//             punpxenv->defint.UNPXEsw,                           //~v6F1R~
//             punpxenv->defbit.UNPXEsw_top,                       //~v6F1R~
//             punpxenv->defint.UNPXEtw,                           //~v6F1R~
//             punpxenv->defbit.UNPXEfop,                          //~v6F1R~
//             punpxenv->defint.UNPXEfcs,                          //~v6F1R~
//             punpxenv->defint.UNPXEfip,                          //~v6F1R~
//             punpxenv->defint.UNPXEfos,                          //~v6F1R~
//             punpxenv->defint.UNPXEfoo,                          //~v6F1R~
//             &offset);                     //%n output(current offset)//~v6F1R~
////*stack                                                         //~v6F1R~
//     for (i=0;i<8;i+=2)                                          //~v6F1R~
//     {                                                           //~v6F1R~
//       sprintf((msgwk+=offset),msgprotnpx2,                      //~v6F1R~
//               i,                                                //~v6F1R~
//               pctxrec->ctx_stack[i  ].signexp,                  //~v6F1R~
//               pctxrec->ctx_stack[i  ].hisig,                    //~v6F1R~
//               pctxrec->ctx_stack[i  ].losig,                    //~v6F1R~
//               i+1,                                              //~v6F1R~
//               pctxrec->ctx_stack[i+1].signexp,                  //~v6F1R~
//               pctxrec->ctx_stack[i+1].hisig,                    //~v6F1R~
//               pctxrec->ctx_stack[i+1].losig,                    //~v6F1R~
//               &offset);                     //%n output(current offset)//~v6F1R~
//     }                                                           //~v6F1R~
//   }                                                             //~v6F1R~
//**********************                                           //~v6F1I~
//* register           *                                           //~v6F1I~
//**********************                                           //~v6F1I~
////* integer reg                                                  //~v6F1R~
////UTRACED("before REG ",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v167R~//~v6F1R~
//   if (pctxrec->ContextFlags & CONTEXT_INTEGER)//valid integer fields//~v6F1R~
//   {                                                             //~v6F1R~
//     sprintf((msgwk+=offset),msgprotintreg,                      //~v6F1R~
//             pctxrec->ctx_RegEax,          //EAX                 //~v6F1R~
//             pctxrec->ctx_RegEbx,          //EBX                 //~v6F1R~
//             pctxrec->ctx_RegEcx,          //ECX                 //~v6F1R~
//             pctxrec->ctx_RegEdx,          //EDX                 //~v6F1R~
//             pctxrec->ctx_RegEsi,          //Esi                 //~v6F1R~
//             pctxrec->ctx_RegEdi,          //Edi                 //~v6F1R~
//             &offset);                     //%n output(current offset)//~v6F1R~
//   }                                                             //~v6F1R~
//                                                                 //~v6F1R~
////* segment reg                                                  //~v6F1R~
//   if (pctxrec->ContextFlags & CONTEXT_SEGMENTS)//valid segment fields//~v6F1R~
//   {                                                             //~v6F1R~
//     sprintf((msgwk+=offset),msgprotsegreg,                      //~v6F1R~
//             pctxrec->ctx_SegDs,          //DS                   //~v6F1R~
//             pctxrec->ctx_SegEs,          //ES                   //~v6F1R~
//             pctxrec->ctx_SegFs,          //FS                   //~v6F1R~
//             pctxrec->ctx_SegGs,          //GS                   //~v6F1R~
//             &offset);                     //%n output(current offset)//~v6F1R~
//   }                                                             //~v6F1R~
//                                                                 //~v6F1R~
////* control reg                                                  //~v6F1R~
//   if (pctxrec->ContextFlags & CONTEXT_CONTROL)//valid segment fields//~v6F1R~
//   {                                                             //~v6F1R~
//     sprintf((msgwk+=offset),msgprotctlreg,                      //~v6F1R~
//             pctxrec->ctx_SegCs,          //CS                   //~v6F1R~
//             pctxrec->ctx_RegEip,         //EIP                  //~v6F1R~
//             pctxrec->ctx_SegSs,          //SS                   //~v6F1R~
//             pctxrec->ctx_RegEsp,         //ESP                  //~v6F1R~
//             pctxrec->ctx_RegEbp,         //EBP                  //~v6F1R~
//             pctxrec->ctx_EFlags,        //FLAGS                 //~v6F1R~
//             &offset);                     //%n output(current offset)//~v6F1R~
//   }                                                             //~v6F1R~
//                                                                 //~v6F1R~
//****************************                                     //~v6F1I~
//* msgbox                   *                                     //~v6F1I~
//****************************                                     //~v6F1I~
//UTRACEP("last  msgwk=%08x\n",msgwk);                             //~v171R~//~v6F1I~
  msgwk=allocmem; //recover top addr                               //~v6F1I~
//UTRACED("before uerrmsg",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v171R~//~v6F1I~
//UTRACED("after  uerrmsg",(char*)(((UEXREGREC*)(void*)pexregrec)->UERGparm)-64,128);//~v171R~//~v6F1I~
  UTRACEP("%s:before return msg=%s\n",UTT,msgwk);                  //~v6F1R~
  printf(msgwk);                                                   //~v171I~//~v6F1I~
  return msgwk;                                   //a930223        //~v6F1I~
}//uehmsg                                                          //~v6F1I~
#ifdef AAA                                                         //~v6F1I~
//*************************************************************    //~v6F1I~
int uehstacktracemsg(int Popt,void *Pexceptionaddr,char *Pmsgout)  //~v6F1R~
{                                                                  //~v6F1I~
#define STACK_TRACE_CTR   20                                       //~v6F1I~
#define SYM_MAX_NAMELEN   255                                      //~v6F1R~
	void* stack[STACK_TRACE_CTR];                                  //~v6F1R~
    int ctr,msglen=0,ii,rc2,len;                                   //~v6F1R~
    SYMBOL_INFO  *symbol;                                          //~v6F1I~
    HANDLE process;                                                //~v6F1I~
    char *pc,*prevname;                                            //~v6F1R~
    ULONG64 prevepa,disp;                                          //~v6F1R~
int uehstacktracemsg2(int Popt,void *Pexceptionaddr,char *Pmsgout);//~v6F1I~
//*************                                                    //~v6F1I~
	ctr=ubacktrace(0,0/*skipctr*/,STACK_TRACE_CTR,stack);          //~v6F1R~
    process=GetCurrentProcess();                                   //~v6F1I~
    rc2=SymInitialize(process,NULL,TRUE );                         //~v6F1R~
    UTRACEP("%s:SymInitialize rc=%d,lasterr=%d\n",UTT,rc2,GetLastError());//~v6F1R~
    if (!rc2)                                                      //~v6F1I~
    	return 0;                                                  //~v6F1I~
    symbol=(SYMBOL_INFO*)calloc(sizeof(SYMBOL_INFO)+SYM_MAX_NAMELEN*sizeof(char),1);//~v6F1R~
    symbol->MaxNameLen=SYM_MAX_NAMELEN;                            //~v6F1R~
    symbol->SizeOfStruct=sizeof(IMAGEHLP_SYMBOL);                  //~v6F1R~
    if (Popt & UEHSMO_EXCEPTIONADDR)                               //~v6F1I~
    {                                                              //~v6F1I~
    	rc2=SymFromAddr(process,(DWORD64)Pexceptionaddr,&disp,symbol);//~v6F1R~
    	UTRACEP("%s:SymFromAddress rc=%d,addr=%p,disp=%p,lasterr=%d\n",UTT,rc2,Pexceptionaddr,disp,GetLastError());//~v6F1R~
    	UTRACED("exception addr symbol",symbol,(int)sizeof(SYMBOL_INFO));//~v6F1R~
		if (!rc2)                                                  //~v6F1I~
    		return 0;                                              //~v6F1I~
    }                                                              //~v6F1I~
    prevname=symbol->Name;                                         //~v6F1I~
    prevepa=symbol->Address;                                       //~v6F1I~
    if (Popt & UEHSMO_EXCEPTIONADDR)                               //~v6F1I~
    {                                                              //~v6F1I~
    	msglen=sprintf(Pmsgout,"%p=%s\n",symbol->Address,symbol->Name);//~v6F1I~
        UTRACEP("%s:Pmsgout=%s\n",UTT,Pmsgout);                    //~v6F1I~
        return msglen;                                             //~v6F1I~
    }                                                              //~v6F1I~
    for(ii=0,pc=Pmsgout;ii<ctr;ii++)                               //~v6F1I~
    {                                                              //~v6F1I~
        len+=sprintf(pc,"%2d: at %p called %p:%s\n",ii,stack[ii],prevepa,prevname);//~v6F1R~
        pc+=len;                                                   //~v6F1I~
        msglen+=len;                                               //~v6F1I~
        rc2=SymFromAddr(process,(DWORD64)(stack[ii]),&disp,symbol);//~v6F1R~
    UTRACEP("%s:SymFromAddress rc=%d,addr=%p,disp=%p,lasterr=%d\n",UTT,rc2,stack[ii],disp,GetLastError());//~v6F1R~
    UTRACED("link addr symbol",symbol,(int)sizeof(SYMBOL_INFO));   //~v6F1R~
		prevname=symbol->Name;                                     //~v6F1I~
    	prevepa=symbol->Address;                                   //~v6F1I~
    }                                                              //~v6F1I~
    free(symbol);                                                  //~v6F1I~
	msglen+=uehstacktracemsg2(Popt,Pexceptionaddr,Pmsgout+msglen); //~v6F1R~
    return msglen;                                                 //~v6F1I~
}//uehstacktracemsg                                                //~v6F1I~
#else                                                              //~v6F1I~
//*************************************************************    //~v6F1I~
int uehstacktracemsg(int Popt,void *Pexceptionaddr,char *Pmsgout)  //~v6F1R~
{                                                                  //~v6F1I~
#define STACK_TRACE_CTR   20                                       //~v6F1I~
#define SYM_MAX_NAMELEN   255                                      //~v6F1I~
	void* stack[STACK_TRACE_CTR];                                  //~v6F1I~
    int ctr,msglen=0,ii,rc2,len;                                   //~v6F1R~
    IMAGEHLP_SYMBOL64 *symbol;                                     //~v6F1R~
    HANDLE process;                                                //~v6F1I~
    char *pc;                                                      //~v6F1R~
//*************                                                    //~v6F1I~
	ctr=ubacktrace(0,0/*skipctr*/,STACK_TRACE_CTR,stack);          //~v6F1I~
    process=GetCurrentProcess();                                   //~v6F1I~
	if (Popt & UEHSMO_SYMINIT) //         0x02    //need only once //~v6F1I~
    {                                                              //~v6F1I~
    	rc2=SymInitialize(process,NULL,TRUE );                     //~v6F1R~
    	UTRACEP("%s:SymInitialize rc=%d,lasterr=%d\n",UTT,rc2,GetLastError());//~v6F1R~
    	if (!rc2)                                                  //~v6F1R~
    		return 0;                                              //~v6F1R~
    }                                                              //~v6F1I~
    symbol=(IMAGEHLP_SYMBOL64*)calloc(sizeof(IMAGEHLP_SYMBOL64)+SYM_MAX_NAMELEN*sizeof(char),1);//~v6F1R~
    symbol->MaxNameLength=SYM_MAX_NAMELEN;                         //~v6F1I~
    symbol->SizeOfStruct=sizeof(IMAGEHLP_SYMBOL);                  //~v6F1I~
    if (Popt & UEHSMO_EXCEPTIONADDR)                               //~v6F1I~
    {                                                              //~v6F1I~
	    rc2=SymGetSymFromAddr64(process,(DWORD64)Pexceptionaddr,0,symbol);//~v6F1I~
    	UTRACEP("%s:SymFromAddress rc=%d,addr=%p,lasterr=%d\n",UTT,rc2,Pexceptionaddr,GetLastError());//~v6F1R~
    	UTRACED("exception addr symbol",symbol,(int)sizeof(IMAGEHLP_SYMBOL64)+SYM_MAX_NAMELEN);//~v6F1R~
		if (!rc2)                                                  //~v6F1I~
    		return 0;                                              //~v6F1I~
    	msglen=sprintf(Pmsgout,"%s",symbol->Name);                 //~v6F1R~
        UTRACEP("%s:Pmsgout=%s\n",UTT,Pmsgout);                    //~v6F1M~
        return msglen;                                             //~v6F1M~
    }                                                              //~v6F1I~
    for(ii=0,pc=Pmsgout;ii<ctr;ii++)                               //~v6F1I~
    {                                                              //~v6F1I~
        rc2=SymGetSymFromAddr64(process,(DWORD64)(stack[ii]),0,symbol);//~v6F1M~
        if (!rc2)                                                  //~v6F1I~
        	break;                                                 //~v6F1I~
        UTRACEP("%s:SymFromAddress rc=%d,addr=%p,lasterr=%d\n",UTT,rc2,stack[ii],GetLastError());//~v6F1I~
        UTRACED("link addr symbol",symbol,(int)sizeof(IMAGEHLP_SYMBOL64)+SYM_MAX_NAMELEN);//~v6F1R~
        len=sprintf(pc,"%2d: at %p called %p:%s\n",ii,stack[ii+1],(void*)symbol->Address,symbol->Name);//~v6F1R~
        pc+=len;                                                   //~v6F1I~
        msglen+=len;                                               //~v6F1I~
    }                                                              //~v6F1I~
    free(symbol);                                                  //~v6F1I~
    return msglen;                                                 //~v6F1I~
}//uehstacktracemsg                                                //~v6F1R~
#endif //AAA                                                       //~v6F1I~
#endif //ULIB64X                                                   //~v6F1I~
