//CID://+vba2R~:   update#=   6;                                   //~7710I~//~vba2R~
//**************************************************************** //~7710I~
//*xefcmd7.h                                                       //~7710I~//~vba2R~
//**************************************************************** //~7710I~
//vba2:170710 add SP cmd to register shortcut path name and use by  sp:xxx//~vba2I~
//**************************************************************** //~7710I~
#define WKFNM_SHORTPATH    "::xe.shortpath"                        //~vba2M~
typedef struct _SHORTPATH {                                        //~vba2I~
                        UQUEE  USPqelem;                           //~vba2I~
                        char*  USPpname;                           //~vba2I~
                        char*  USPppath;                           //~vba2I~
                        char   USPdata[1];                         //~vba2I~
							} SHORTPATH,*PSHORTPATH;               //~vba2I~
#define SHORTPATHSZ (offsetof(SHORTPATH,USPdata))                  //~vba2R~
//**************************************************************** //~vba2I~
int funcsp_init(int Popt);                                         //~vba2I~
void funcsp_term(int Popt);                                        //~vba2R~
char *funcsp_search(int Popt,char *Ppname);                        //+vba2I~
