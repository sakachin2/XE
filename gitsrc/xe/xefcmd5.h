//CID://+v62aR~:                                                   //~v62aR~
//****************************************************************//~5308I~
//*xefcmd5.h                                                       //~v47UR~
//****************************************************************//~5308I~
//v62b:050312 for -m[n] option of find cmd;assign mfwtbl for each pfh to avoid copy and copyback each time//+v62aI~
//v62a:050311 -m option of find cmd to keep previous reverse       //~v62aI~
//v50i:021230 cv cmd:ucs conv support                              //~v50iI~
//v47U:020407 cv cmd(euc<-->sjis)                                  //~v47UI~
//**************************************************************** //~v165I~
int fcmdsetfound(PUFILEH Ppfh,PULINEH Pplh,int Plocatesw,int Poffset,int Pwordlen);//~v50iI~
//**************************************************************** //~v50iI~
//int fcmdcpymfwt2(PUFILEH Ppfh,int Pindex);                       //+v62aR~
//**************************************************************** //~v62aI~
//int fcmdcpymfwtback(PUFILEH Ppfh,char *Ptbladdr);                //+v62aR~
//**************************************************************** //+v62aI~
int fcmdallocmfwt(PUFILEH Ppfh);                                   //+v62aI~
