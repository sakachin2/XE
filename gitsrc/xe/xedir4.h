//*CID://+vb14R~:                             update#=   30;       //+vb14R~
//**************************************************************** //~v690I~
//vb14:150613 0x00 is set for rename field display for U8-LC mixed string, set '.' for visibility//+vb14I~
//vawn:140605 (BUG)ddfmt display err for renamesv at cmd comp(getmixedstr fail to recover utf8 and display dbcs)//~vawnI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vav4:140404 select dlcmd for utf8 subdir shoud apply fnm encoding determined on the dir list//~vav4I~
//vauE:140316 (Win)use ddfmt for dirlist;On cmd-prompt with setcp=65001,f2l dosenot change length but Windows display line shrinked//~vauEI~
//            use ddfmt to set USDfdata                            //~vauEI~
//vau0:140223 (LNX:BUG)utf8 filename on dirlist,filename locale:de is invalid if f2l on locale=ja_jp//~vau0I~
//            use ddfmt to set USDfdata                            //~vau0I~
//vagE:120918 apply cmdline option /U{N|F}{8|L} to also edit/browse cmd//~vagEI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          conv descname to locale if utf8                        //~va00I~
//v777:071204*EUC hankana chk(2byte but 1 column) hankana input not avail on rh9 but on fc5//~v777I~
//v690:060418 display file-description support on dir-list panel   //~v690I~
//**************************************************************** //~v690I~
//xedir4.h                                                         //~v690I~
//**************************************************************** //~v690I~
//**************************************************************** //~v690I~
#define XESTREAMNAME       "xe-desc" //alternative data stream for xe description save//~v690R~
#define DESCRIPTIONRANGE     1024    //search  DID; in the range   //~v690R~
#define DESCRIPTIONID        "DID:"                                //~v690R~
//**************************************************************** //~v690I~
char *dirgetdesc(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PUDIRLH Ppdh);//~v690R~
//**************************************************************** //~v777I~
#ifdef UTF8SUPPH                                                   //~va00I~
//	int dirsetlocalename(int Popt,PUDIRLIST Ppudl,PUDIRLH Ppdh);   //~va00I~//~vagER~
	int dirsetlocalename(int Popt,PUDIRLIST Ppudl,PUFILEH Ppfh,PUDIRLH Ppdh);//~vagEI~
    #define DIRSLNO_FNMEMB    0x01 //apply member FN option        //~vav4I~
//**************************************************************** //~vav4I~
//  int dirsetlocalenameforpath(PUDIRLH Ppdh);                     //~va00R~//~vagER~
    int dirsetlocalenameforpath(PUFILEH Ppfh,PUDIRLH Ppdh);        //~vagEI~
#endif                                                             //~va00I~
//**************************************************************** //~va00I~
int dircharcsr(PUCLIENTWE Ppcw);                                   //~v777I~
//**************************************************************** //~vau0I~
//#ifdef LNX                                                         //~vau0M~//~vauER~
	int dirsetddfmtname(int Popt,PUDIRLH Ppdh,char *Putf8,int Plen);//~vau0R~
	#define DSDFO_L2DD               0x01                          //~vau0R~
	#define DSDFO_MEMBNAME           0x02                          //~vau0I~
	#define DSDFO_SLINKNAME          0x04                          //~vau0R~
	#define DSDFO_RENAME             0x08                          //~vau0I~
#ifdef W32UNICODE                                                  //~vav0I~//~vavaI~
	#define DSDFO_UTF16              0x10   //parm is utf16        //~vav0I~//~vavaI~
#endif                                                             //~vav0I~//~vavaI~
#ifdef LNX                                                         //~vawnI~
	#define DSDFO_DDFMT              0x20   //parm is dddata+dddbcs//~vawnI~
#endif                                                             //~vawnI~
	#define DSDFO_ERRREP             0x40   //rep by '.' when l2f err//+vb14I~
//#endif                                                             //~vau0M~//~vauER~
#ifdef LNX                                                         //~vawnI~
//#ifdef HHH                                                       //~vawnR~
//int dirsetddfmtname_renamesv(int Popt,PULINEH Pplh,char *Putf8,int Plen,char *Pct,char *Pdatalc);//~vawnR~
//#else                                                            //~vawnR~
int dirsetddfmtname_renamesv(int Popt,PULINEH Pplh,char *Putf8,int Plen,char *Pct,int Plclen);//~vawnI~
//#endif                                                           //~vawnR~
#endif                                                             //~vawnI~
