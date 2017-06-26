//*CID://+v98iR~:                             update#=    9;       //~v98iR~
//***********************************************************      //~v831I~
//* XPESC.H                                                        //~v831I~
//***********************************************************      //~v831I~
//v98i:140208 (BUG)Paper width/haight re-evaluation is required when orientation was changed by dialog//~v98iI~
//v987:140201 (BUG)when papersize change by dialog,need to adjust maxcol/maxline//~v987I~
//020720 v916 (WIN)auto set form orientation                       //~v916I~
//971124 v831 :split xppf from xprint                              //~v831I~
//***********************************************************      //~v831I~
typedef struct _PITCHL	{                                          //~v916M~
                  	  		int formmaxcol[2][5];//num and nonum   //~v916M~
	                  		int formmaxline;                       //~v916M~
                            int formtype;                          //~v916M~
#define PFT_YOKO     0x0100                                        //~v916M~
#define PFT_2P       0x0200                                        //~v916M~
#define PFT_REVERSE  0x0400                                        //~v98iI~
#define PFT_FORM     0x00ff                                        //~v916R~
#define PFT_A4       0x0001                                        //~v916I~
#define PFT_B4       0x0002                                        //~v916M~
#define PFT_B5       0x0003                                        //~v916M~
	                	} PITCHL;                                  //~v916M~
//**********************************************************************//~v831I~
//* ESC cmd setup		v5.1a                                      //~v831I~
//**********************************************************************//~v831I~
void esccmdsetup(int pmaxcol,int prntyp,char *cmdfile);//v5.5r v7.12r//~v831I~
#ifdef GTKPRINT                                                   //~v980I~//~v987I~//+v98iR~
int escformchkGtk(char *Pform,char *Pdisplayname,int Plandscape);  //~v987I~//~v98iR~
#endif                                                             //~v980I~//~v987I~
