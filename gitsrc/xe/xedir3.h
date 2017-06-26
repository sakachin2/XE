//*CID://+vawkR~:                             update#=    8;       //+vawkR~
//**************************************************************** //~v693I~
//vawk:140605 (BUG:LNX)additional to vawj;lc len shring but colpos remainsby setflddata;use dd2l like as other paste such as to cmdline//+vawkI~
//vawc:140601 support to paste to rename fld                       //~vawcI~
//v78g:080312 on dirlist;execute locate cmd by type on filename fld//~v78gI~
//v693:060423 (BUG)when scr resized,remains previous image         //~v693I~
//v621:050308 (WXE:BUG)scr-resize dose not reset dirlist expanded  //~v621I~
//****************************************************************//~v020I~
//xedir.h                                                       //~v020I~
//****************************************************************//~v020I~
#ifdef  XEGBL_DIR3                                                 //~v182I~
    int Gdir3status;                                               //~v182I~
#else                                                              //~v182I~
	extern int Gdir3status;                                        //~v182I~
#endif                                                             //~v182I~
#define GDIR3SLFN   0x01	//disply by long filename	           //~v182I~
//**************************************************************** //~v621I~
//void dirddresetall(PUCLIENTWE Ppcw);                             //~v693R~
void dirddresetall(int Popt,PUCLIENTWE Ppcw);                      //~v693I~
#define DDRESET_RESIZE      0x01        //reseetup by screen resize//~v693I~
#define DDRESET_DESC        0x02        //description display      //~v693I~
#define DDRESET_UGID        0x04        //UID/GID display change   //~v693I~
#define DDRESET_LINECOUNT   0x08        //size/linecount           //~v693I~
#define DDRESET_LFN         0x10        //LongFileName on/off      //~v693I~
//void dirddresetallsub(PUCLIENTWE Ppcw,PUFILEH Ppfh);             //~v693R~
void dirddresetallsub(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);      //~v693I~
//**************************************************************** //~v78gI~
int dirlocate(int Popt,PUCLIENTWE Ppcw);                           //~v78gI~
//**************************************************************** //~vawcI~
int dirpasterenamefld(int Popt,PUCLIENTWE Ppcw,char *Pdata,char *pdbcs,int Poffs,int Plen);//~vawcI~
#define DRFPO_INS    0x01                                          //~vawcI~
#define DRFPO_U8     0x02                                          //~vawcI~
#define DRFPO_EBC    0x04                                          //~vawcI~
#define DRFPO_SETCT2 0x08                                          //+vawkI~
