//*CID://+v69mR~:                             update#=    4;       //~v69mR~
//**************************************************************** //~v53mI~
//xemousel.h                                                       //~v53mI~
//**************************************************************** //~v53mI~
//v69m:060524 (WXEXXE)pass scroll ctr not by string cmd parm but thrugh gbl var to avoid cmd line input cleared//~v69mI~
//v53m:030928 (LNX)mouse support                                   //~v53mI~
//**************************************************************** //~v53mI~
#ifdef XEMOUSEL_GLOBAL                                             //~v69mI~
  	#define EXTERN                                                 //~v69mI~
	#define INITV(value) =value                                    //~v69mI~
#else                                                              //~v69mI~
  	#define EXTERN extern                                          //~v69mI~
    #define INITV(value)                                           //~v69mI~
#endif                                                             //~v69mI~
                                                                   //~v69mI~
  	EXTERN  int Gwxestat;                                          //~v69mI~
#define GWXES_SCROLLBYMOUSE   0x10	//scroll by mouse              //~v69mI~
                                                                   //~v69mI~
  	EXTERN  int Gwxescrollctr INITV(3);                            //+v69mR~
                                                                   //~v69mI~
#undef EXTERN                                                      //~v69mI~
#undef INITV                                                       //~v69mI~
//************************************************************     //~v53mI~
int mousel_btnproc(KBDKEYINFO *Ppkeyinfo);                         //~v53mI~
//************************************************************     //~v53mI~
int mousel_funcsrch(PUCLIENTWE Ppcw,UCHAR *Pxy,FUNCTBL **Pppft,FTFUNC **Ppfunc);//~v53mI~
