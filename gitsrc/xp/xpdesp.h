//CID://+v97pR~:            update#=     3                         //+v97pR~
//***********************************************************      //~v832I~
//* XPDESP.H                                                       //~v832I~
//***********************************************************      //~v832I~
//v97p:131110 hexline monospace(vhex and hhex partially)           //+v97pI~
//v97m:131104 (gxp)header print err for utf8 filename;chk utf8 encoding for filename//~v97mI~
//981023 v859 :(BUG of v844)output should not to be open when _WIN //~v859I~
//971124 v832 :split xpdesp from xprint                            //~v832I~
//***********************************************************      //~v832I~
//**********************************************************************//~v832I~
//* line write to page work file v5.3a                             //~v832I~
//**********************************************************************//~v832I~
void deswkfwrite(char *area,int len);                              //~v832I~
                                                                   //~v832I~
//**********************************************************************//~v832I~
//* write to output from page work file by page descending order v5.3a//~v832I~
//**********************************************************************//~v832I~
void despageout(int Popt,FILE *output);                            //~v859R~
#ifdef GTKPRINT                                                    //~v859I~
	void desp_gtkopendoc(int Phmi,int Pvmi,char *Pdocname);        //~v859I~
	void desp_gtkclosedoc();                                       //~v859R~
//***************************************************************************//~v97mI~
	void desp_gtktextout(int Pflag,double Pxx,double Pyy,char *Pbuff,int Plen);//~v859R~
	#define GTKTOF_MONOSPACE    0x01                                     //~v970I~//~v859R~
	#define GTKTOF_HDR0         0x02                               //~v97mI~
	#define GTKTOF_SUBHDR       0x04                               //~v97mI~
	#define GTKTOF_HHEX         0x08                               //+v97pI~
//***************************************************************************//~v97mI~
	void desp_gtklineout(double Pxx1,double Pyy1,double Pxx2,double Pyy2);//~v859I~
	void desp_gtknewpage();                                        //~v859I~
	void desp_gtkclosepage();                                      //~v859I~
	void desp_gtkdrawpage(int Ppageno);                            //~v859I~
	void desp_gtkbeginprint(int Ppageno);                          //~v859R~
#endif //!GTKPRINT                                                 //~v859I~
