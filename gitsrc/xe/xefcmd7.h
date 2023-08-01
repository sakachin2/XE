//CID://+vby4R~:   update#=  15;                                   //~vby4R~
//**************************************************************** //~7710I~
//*xefcmd7.h                                                       //~7710I~//~vba2R~
//**************************************************************** //~7710I~
//vby4:230402 (ARM)shared resource support by //shareName defined by SP(ShortPath) cmd.//~vby4I~
//vba2:170710 add SP cmd to register shortcut path name and use by  sp:xxx//~vba2I~
//**************************************************************** //~7710I~
#define WKFNM_SHORTPATH    "::xe.shortpath"                        //~vba2M~
//typedef struct _SHORTPATH {                                        //~vba2I~//+vby4R~
//                        UQUEE  USPqelem;                           //~vba2I~//+vby4R~
//                        char*  USPpname;                           //~vba2I~//+vby4R~
//                        char*  USPppath;                           //~vba2I~//+vby4R~
////#ifdef ARMXXE                                                  //+vby4R~
////                        char*  USPpstrUri;                     //+vby4R~
////#endif                                                         //+vby4R~
//                        char   USPdata[1];                         //~vba2I~//+vby4R~
//                            } SHORTPATH,*PSHORTPATH;               //~vba2I~//+vby4R~
//#define SHORTPATHSZ (offsetof(SHORTPATH,USPdata))                  //~vba2R~//+vby4R~
//**************************************************************** //~vba2I~
int funcsp_init(int Popt);                                         //~vba2I~
void funcsp_term(int Popt);                                        //~vba2R~
char *funcsp_search(int Popt,char *Ppname);                        //~vba2I~
#ifdef ARMXXE                                                      //~vby4I~
	void xefc7_OnActivityResult(int PreqID,int Prc,char *Pparm,char *PstrUri,char *Ppath);//~vby4R~
	void funcsp_filefullpathDoc(char *Pfnm,char *PpathDoc,char *Pfullpath);//~vby4R~
#endif                                                             //~vby4I~
