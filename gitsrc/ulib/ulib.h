//CID://+v6B2R~:      update#=      6                              //+v6B2R~
//*********************************************************************
//* common routine hdr                                             //~v021R~
//*********************************************************************
//v6B2:160115 (Linux compiler warning)tarns minus int to unsigned. ULBITOFF//+v6B2I~
//v6q3:131129 (LNX)compiler warning;dereferencing type-punned pointer//~v6q3I~
//v6k4:130525 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//            ulib.h   UIBITCHK                                    //~v6k4I~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v321 000729:UNIX support                                         //~v321R~
//v246:990620 disas:DOS MZ support                                 //~v246I~
//v131:971220 OSTYPE macro to ulibdef.h                            //~v131I~
//v053:970107:gcc version(control by DPMI)                         //~v053R~
//            -not used macro _CDECL                               //~v053I~
//            -change macro name FP_SEGOFF-->DOS_MAKE_FLAT to chck dos mem refer//~v053I~
//            -del macro name FLATADDR that is for 16:16 model     //~v053I~
//            -lack of function mkdir,memicmp etc                  //~v053I~
//v027:960917:dos dump sub                                         //~v027I~
//v021:960727:WIN32 BCC(_CDECL-->_cdecl)                           //~v021I~
//v001:960602 for MSC6,c2 define _CDECL cdecl,msc6 use _cdecl.     //~6602I~
//*********************************************************************//~6602I~
//* DEF MACRO *******************************

#ifdef UNX                                                         //~v321R~
    #include <ulibdef.h>		//UCHAR etc                        //~v321R~
#else                                                              //~v321R~
#ifdef DOS
    #ifdef C6                   //MS C6                            //~6706R~
        #define _CDECL _cdecl                                      //~6706R~
    #endif                                                         //~6706R~
    #ifdef DPMI                 //DPMI                             //~v053R~
        #define _CDECL                                             //~v053R~
    #endif                                                         //~v053I~
    #include <ulibdef.h>		//UCHAR etc                        //~v021I~

  #ifdef DPMI                                                      //~v053R~
    #include <udpmilib.h>		//c function not supported on libc.a//~v053I~
    #define DOS_MAKE_FLAT(Seg,Offset) (((Seg)<<4)+(Offset))        //~v053R~
  #else                                                            //~v053I~
   	#define FP_SEGOFF(Seg,Offset)							\
   				((PVOID)(((ULONG)Seg<<16)+(ULONG)(Offset)))
    #define FLATADDR(pc) (((ULONG)FP_SEG(pc)<<4)+(ULONG)FP_OFF(pc))//~v027M~
  #endif                                                           //~v053I~
#else                                                              //~v021I~
   	#define FP_SEGOFF(Seg,Offset)							\
   				((PVOID)(((ULONG)Seg<<16)+(ULONG)(Offset)))        //~v246I~
    #define FLATADDR(pc) (((ULONG)FP_SEG(pc)<<4)+(ULONG)FP_OFF(pc))//~v246I~
    #define DOS_MAKE_FLAT(Seg,Offset) ((ULONG)(((ULONG)(Seg)<<4)+(ULONG)(Offset)))//~v246I~
    #ifdef W32                   //WIN32 by BC                     //~v021I~
        #define _CDECL _cdecl                                      //~v021I~
        #define doserrno _doserrno                                 //~v021I~
                                                                   //~v021I~
		#include <ulibdef.h>		//UCHAR etc                    //~v021R~
    #else                           /*os2*/                        //~v021I~
//*for compiler warning when MSC_VER is used without unde ifdef W32//~v027I~
        #define _MSC_VER 0                                         //~v027I~
	    #ifndef __OS2_H__            //no os2.h     included       //~v021I~
		    #include <ulibdef.h>		//UCHAR etc                //~v021I~
	    #endif                                                     //~v021I~
    #endif                                                         //~v021M~
#endif
#endif   //!UNX                                                    //~v321R~
//* MCARO     ******************************
//*1 byte bit operation ***
#define UCBITCHK(uc,bit)		\
		(UCHAR)((uc) & (bit))                                   //~5225R~
#define UCBITON(uc,bit)		\
		uc=(UCHAR)((uc) | (bit))                                //~5225R~
#define UCBITOFF(uc,bit)		\
		uc=(UCHAR)((uc) & ~(bit))                               //~5225R~
#define UCBITXOR(uc,bit)		\
		uc=(UCHAR)((uc) ^ (bit))                                //~5225I~
//*2 byte bit operation ***                                     //~5110I~
#define USBITCHK(uc,bit)		\
		(USHORT)((uc) & (bit))                                  //~5225R~
#define USBITON(uc,bit)		\
		uc=(USHORT)((uc) | (bit))                               //~5225R~
#define USBITOFF(uc,bit)		\
		uc=(USHORT)((uc) & ~(bit))                              //~5225R~
#define USBITXOR(uc,bit)		\
		uc=(USHORT)((uc) ^ (bit))                               //~5225I~
//*4 byte bit operation ***                                     //~5110I~
#define ULBITCHK(uc,bit)		\
		(ULONG)((uc) & (bit))                                   //~5225R~
#define ULBITON(uc,bit)		\
		uc=(ULONG)((uc) | (bit))                                //~5225R~
#define ULBITOFF(uc,bit)		\
  		uc=(ULONG)((uc) & ~((ULONG)bit))                           //+v6B2R~
//		uc=(ULONG)((uc) & ~(bit))                                  //+v6B2I~
#define ULBITXOR(uc,bit)		\
		uc=(ULONG)((uc) ^ (bit))                                //~5225I~
//*4 byte bit operation ***                                        //~v6k4I~
#define UIBITCHK(uc,bit)		\
		(UINT)((uc) & (bit))                                       //~v6k4I~
#define UIBITON(uc,bit)		\
		uc=(UINT)((uc) | (bit))                                    //~v6k4I~
#define UIBITOFF(uc,bit)		\
		uc=(UINT)((uc) & ~(bit))                                   //~v6k4I~
#define UIBITXOR(uc,bit)		\
		uc=(UINT)((uc) ^ (bit))                                    //~v6k4I~
//*1/2/4 byte move operation ***
#define UMOVSB(destptr,sourceptr)		\
		*((UCHAR *)(PVOID)(destptr))=*((UCHAR *)(PVOID)(sourceptr))
/**                                                                //~v6q3I~
#define UMOVSW(destptr,sourceptr)		\
		*((USHORT *)(PVOID)(destptr))=*((USHORT *)(PVOID)(sourceptr))
**/                                                                //~v6q3I~
#define UMOVSW(destptr,sourceptr)		\
		(*(UCHAR*)(destptr)=*(UCHAR*)(sourceptr), \
		 *(UCHAR*)(destptr+1)=*(UCHAR*)(sourceptr+1))              //~v6q3R~
/***                                                               //~v6hhI~
#define UMOVSD(destptr,sourceptr)		\
		*((ULONG *)(PVOID)(destptr))=*((ULONG *)(PVOID)(sourceptr))
***/                                                               //~v6hhI~
#define UMOVSD(destptr,sourceptr)		\
		*((UINT4 *)(PVOID)(destptr))=*((UINT4 *)(PVOID)(sourceptr))//~v6hhI~
#define ISNUMSTR(str)                                   \
		(*(UCHAR*)(str) && strspn((UCHAR*)(str),"0123456789")==strlen((UCHAR*)(str)))//~5501R~
//*integer reverse load
/***                                                               //~v6hhI~
#define  USTRLOAD(pstr)                            \
         ( ((*(ULONG*)(PVOID)(pstr)<<24))              \
          |((*(ULONG*)(PVOID)(pstr)<< 8) & 0x00ff0000) \
          |((*(ULONG*)(PVOID)(pstr)>> 8) & 0x0000ff00) \
          |((*(ULONG*)(PVOID)(pstr)>>24))              \
         )
***/                                                               //~v6hhI~
#define  USTRLOAD(pstr)                            \
         ( ((*(UINT4*)(PVOID)(pstr)<<24))              \
          |((*(UINT4*)(PVOID)(pstr)<< 8) & 0x00ff0000) \
          |((*(UINT4*)(PVOID)(pstr)>> 8) & 0x0000ff00) \
          |((*(UINT4*)(PVOID)(pstr)>>24))              \
         )                                                         //~v6hhI~
//* DATA TYPE ******************************
//* FUNCTION *******************************
#include <ulibdefc.h>		//common for all version               //~v131I~
//* Global variable *********************************************
