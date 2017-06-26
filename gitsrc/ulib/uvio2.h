//*CID://+v6hhR~:                             update#=    4;       //+v6hhR~
//******************************************************
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//+v6hhI~
//v5fh:050125 (W32)window should be at current last of consolebuff //~v5fhI~
//v252:990626 (Win):for redirect;Once create console buff and then get inf befre destroy//~v252I~
//v156:980126 ugetconhwnd:get console appl HWND                    //~v156I~
//v151:980119 (BUG:DOS/GCC)video buff direct write determined by not dbcs env//~v044I~
//            but video mode.video buff chk by int 10 ah=FE        //~v044I~
//            (none is displayed under os2 dos session when changed chev us)//~v044I~
//v044:961106:too large for XEDOS,split uvio.c to uvio2.c          //~v044I~
//v043:961104:(W95)write attr string function support              //~v043I~
//v042:961102:(W95)write all line to screen by one api issue for performance//~v042I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//******************************************************           //~v022I~
#ifdef W32                                                         //~v044I~
                                                                   //~v044I~
//*******************************************************          //~v044M~
//void uvio2_init(HANDLE Phconout);                                //~v5fhR~
void uvio2_init(HANDLE Phconout,int Stoplineoffs);                 //~v5fhI~
                                                                   //~v044I~
//*******************************************************          //~v022I~
HANDLE ugetstdhandle(int Pid);                                     //~v022R~
                                                                   //~v044I~
//*******************************************************          //~v252I~
HANDLE uviowincreatecsb(int Popt);                                 //~v252I~
                                                                   //~v252I~
#endif                                                             //~v022I~
                                                                   //~v044I~
//*******************************************************
UINT uviogetcurpos (int *Pprow,int *Ppcol);
                                                                   //~v044I~
//*******************************************************
UINT uviosetcurpos (int Prow,int Pcol);
                                                                   //~v044I~
//*******************************************************
UINT uviogetcurtype(PVIOCURSORINFO pvioCursorInfo);
                                                                   //~v044I~
//*******************************************************
UINT uviosetcurtype (PVIOCURSORINFO pvioCursorInfo);
                                                                   //~v044I~
//*******************************************************
UINT uviowrttty(PCH pch,int Plen);
                                                                   //~v044I~
//*******************************************************
UINT uviogetstate(PVOID Ppreqblk);
                                                                   //~v044I~
//*******************************************************
UINT uviosetstate(PVOID Ppreqblk);
                                                                //~5222I~
//*******************************************************       //~5222I~
UINT uvioscrolldn(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell);//~5222I~
                                                                //~5222I~
//*******************************************************       //~5222I~
UINT uvioscrollup(int Ptoprow,int Pleftcol,int Pbottomrow,int Prightcol,int Pline,UCHAR *Pcell);//~5222R~
                                                                   //~v044I~
//*******************************************************          //~v044I~
int uvio_dosgetvbuff(UCHAR **Ppvbuff);                             //~v044I~
                                                                   //~v156I~
#ifdef W32                                                         //~v156I~
//********************************************************************///~v156I~
//ULONG ugetconhwnd(void);                                           //~v156R~//+v6hhR~
ULPTR ugetconhwnd(void);                                           //+v6hhI~
#endif                                                             //~v156I~
