//CID://+v327R~:   update#=  1                                     //+v327R~
//******************************************************           //~6A26I~
//*udos.h                                                          //~6A26I~
//******************************************************           //~6A26I~
//v327 000820:LINUX support                                        //~v327I~
//v188:980727 Windows98,iswin98 for kbdw                           //~v188R~
//v162:980202 iswin,iswinnt,isos2 for other version                //~v162I~
//v159:980131 udosisos2   for DOS(chk env string "OS2" in comspec) //~v159I~
//v158:980131 udosiswinnt for DOS(chk env OS=Windows_NT)           //~v158I~
//v136:980103 (W32)WINNT support                                   //~v136I~
//            -udosiswinnt func   udos.c/h ualloc.c                //~v136I~
//v133:971221 for Win/NT;malloc logic                              //~v133I~
//v075:970420 (DOS/GCC)udpmi_version support                       //~7420I~
//v074:970420 (OS2)uharederr support(disable or enable popup)      //~7420I~
//v073:970420 (GCC)_harderr,_hardresume support                    //~7420I~
//v052:961205:win version                                          //~6C05I~
//v039:961026:add udos.c(at first udos_version)                    //~6A26I~
//******************************************************           //~6A26I~
#ifdef DOS                                                         //~7420I~
//copyed from udpmi.h to share with native DOS                     //~7420I~
    typedef struct {                                               //~7420R~
      unsigned char  major;                                        //~7420R~
      unsigned char  minor;                                        //~7420R~
      unsigned short flags;                                        //~7420R~
//    DOS			0x0001 : 32bit prog support                    //~7420I~
//    GCC			0x0001 : 386 dpmi                              //~7420I~
//                  0x0002 : use real mode for reflection          //~7420I~
//                  0x0004 : virtual memory support                //~7420I~
      unsigned char  cpu;  //2:286,3:386,4:486                     //~7420R~
      unsigned char  master_pic;    //not supported under DOS native//~7420R~
      unsigned char  slave_pic;     //not supported under DOS native//~7420R~
    } UDPMIVER;                                                    //~7420R~
#else                                                              //~7420I~
#endif                                                             //~7420I~
//*******************************************************          //~6A26I~
int udos_version(int *Ppmaj,int *Ppmin,void *Ppinfo);              //~6A26I~
                                                                   //~6C05I~
#ifdef DOS                                                         //~6C07I~
//*******************************************************          //~7420I~
int udpmi_version(UDPMIVER *Pdpmiver);                             //~7420I~
                                                                   //~7420I~
//*******************************************************          //~6C05I~
int uwin_version(int *pmaj,int *pmin,int *pmode);                  //~6C05I~
#define REAL_MODE           1                                      //~6C05M~
#define STANDARD_MODE       2                                      //~6C05M~
#define ENHANCED_MODE       3                                      //~6C05M~
                                                                   //~6C07I~
//#ifdef DPMI					//DPMI version                     //~7420R~
//#else                       //not DPMI                           //~7420R~
//*******************************************************          //~6C07I~
#ifndef UNX                                                        //~v327I~
void uharderr(int Pabortopt);                                      //~6C07I~
#endif                                                             //~v327I~
                                                                   //~6C07I~
//#endif                      //DPMI or not                        //~7420R~
#endif                                                             //~6C07I~
                                                                   //~v136I~
//*******************************************************          //~v162I~
int udosiswin(void);                                               //~v162I~
                                                                   //~v162I~
#ifdef W32                                                         //~v188R~
//*******************************************************          //~v188R~
int udosiswin98(void);                                             //~v188R~
#endif                                                             //~v188R~
//*******************************************************          //~v136I~
int udosiswinnt(void);                                             //~v136I~
                                                                   //~v159I~
//*******************************************************          //~v159I~
int udosisos2(void);                                               //~v159I~
