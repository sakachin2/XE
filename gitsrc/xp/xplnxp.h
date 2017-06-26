//CID://+v970R~:                  update#=     34                  //~v970R~
//***********************************************************      //~v928I~
//* xplnxp.h                                                       //~v928R~
//***********************************************************      //~v928I~
//v97m:131104 (gxp)header print err for utf8 filename;chk utf8 encoding for filename//~v970I~
//v973:131011 (GtkPrint)new form option(E[w]/form[L](2p is by /Y2 only)//~v973I~
//v971:130923 Lnx color should be black(404040ff-->ff000000)       //~v971I~
//v970:130922 GtkPrint for alternative of Gnomeprint               //~v970I~
//071013 v92f (Win/gxp)auto-set maxcol/maxline when not predefined pich specified//~v92fI~
//071006 v92d (Lnx)UTF8 support                                    //~v928I~
//**********************************************************************//~v928I~
//#define DEFAULT_PRINTCOLOR  0x404040ff //RRGGBBAA                  //~v92fR~//~v971R~
#define DEFAULT_PRINTCOLOR  0xff000000                             //~v971I~
#define DEFAULT_PAPER     "A4"                                     //~v973I~
#define POINT2MM(pt)    ((float)(pt)*127.0f/360.0f)                //~vam3I~//~v973I~
#define MM2POINT(mm)    ((float)(mm)*360.0f/127.0f)      // 72/25.4 //1inch=72point=25.4mm//~vam3I~//~v973I~
#define INCH2MM(inch)    ((float)(inch)*25.4)                      //~va6yR~//~v973I~
#define MM2INCH(mm)       ((float)(mm)/25.4)                       //~v973I~
#define INCH2POINT(inch)    ((float)(inch)*72)                     //~va6yR~//~v973I~
typedef struct _GDRECT{double top,bottom,left,right;} GDRECT,*PGDRECT;//~vamuR~//~v973R~
typedef struct _FRECT{float top,bottom,left,right;} FRECT,*PFRECT; //~vamuR~//~v973I~
//**********************************************************************//~v92fI~
int lnx_init(int argc,char **argv);                                //~v928R~
//**********************************************************************//~v928I~
void lnx_opendoc(int Phmi,int Pvmi,char *Pdocname);                //~v928R~
//**********************************************************************//~v928I~
void lnx_setupfont(char *Pfontnm);                                 //~v928M~
//**********************************************************************//~v928I~
void lnx_putline(char *Pbuff,unsigned long Plen);                  //~v928R~
//**********************************************************************//~v928I~
void lnx_endjob(int Pendsw);                                       //~v928I~
//**********************************************************************//~v928I~
void lnx_closedoc(void);                                           //~v928M~
//**********************************************************************//~v92fI~
int lnx_getmaxcol(int Pformtype,int Pnonumsw,int Ppitch);          //~v92fI~
//**********************************************************************//~v92fI~
int lnx_getmaxline(int Pformtype,int Ppitch);                      //~v92fI~
                                                                   //~v970I~
#ifdef GTKPRINT                                                    //~v970I~
//**********************************************************************//~v970I~
int lnx_flushprint();                                              //~v970R~
//**********************************************************************//~v970I~
void lnx_startjob(char *Pfnm);                                     //~v970I~
//**********************************************************************//~v970I~
void lnx_startdoc2(int Ppagectr);                                  //~v970I~
//**********************************************************************//~v970I~
void lnx_opendoc2printer(int Phmi,int Pvmi,char *Pdocname);        //~v970I~
//**********************************************************************//~v970I~
void lnx_textout2printer(int Pflag,double Pxx,double Pyy,char *Pputf8,int Pwrite);//~v970I~//~v973R~
//**********************************************************************//~v970I~
void lnx_lineout2printer(double Pposx0,double Pposy0,double Pposx1,double Pposy1);//~v970I~
//**********************************************************************//~v970I~
void lnx_newpage_flush(void);                                      //~v970I~
//**********************************************************************//~v973I~
int lnx_formchk(char *Pform);                                      //~v973R~
//**********************************************************************//~v973I~
void showwindow(int Popt);                                         //+v970R~
//**********************************************************************//~v973I~
void hidewindow(int Popt);                                         //~v970R~
//**********************************************************************//~v970I~
#endif //!GTKPRINT                                                 //~v970I~
