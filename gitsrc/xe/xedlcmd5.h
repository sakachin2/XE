//CID://+v57gR~:                                                   //+v57gR~
//**************************************************************** //~v0fpI~
//*xedlcmd5.h                                                      //~v0fpI~
//**************************************************************** //~v0fpI~
//v57g:040522 support locate cmd for dirlist sorted by time/size   //+v57gI~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v0ie:980607 Locate cmd for disrlist                              //~v0ieI~
//v0fq:971109 new file by select cmd has alias but it is temporary name//~v0fqI~
//            it may duplicated alias name.                        //~v0fqI~
//            dont created new pdh if new,isrt at end file if new file.//~v0fqI~
//v0fp:971108 split dlcmd2-->dlcmd5.c                              //~v0fpI~
//**************************************************************** //~v0fpI~
int dlcmdeditenq(PUCLIENTWE Ppcw,PUDLCMD Pplc);                 //~v04jR~
//**************************************************************** //~v09wI~
PUDIRLH dlcmdeditenq2(PUCLIENTWE Ppcw);                            //~v09wR~
//**************************************************************** //~v0fqI~
PUDIRLH dlcmdeditenq3(PUFILEC Ppfc);                               //~v0fqR~
//****************************************************************//~v046I~
int dlcmdviewscrswap1(PUCLIENTWE Ppcw,PUDLCMD Pplc,UCHAR *Pfname,PUCLIENTWE *Pppcw2);//~v046I~
//****************************************************************//~v046I~
int dlcmdviewscrswap2(PUCLIENTWE Ppcw,PUDLCMD Pplc);             //~v046R~
//****************************************************************//~5819I~
void dlclvlmerge(PUCLIENTWE Ppcw,PUDIRLH Ppdh,PUDIRLIST Ppudirlist,int Pfilectr);//~5819I~
//****************************************************************//~5806I~
PULINEH dlcunexsub(PUDIRLH Ppdh);                                //~5806I~
//****************************************************************//~5819I~
void dlcchngfh(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfilename);//~5819I~
//****************************************************************//~5813I~
PULINEH dlcdelentry(PULINEH Pplh,PULINEH Pplhtop);                  //~v09AR~
//****************************************************************//~v05LI~
int errnotdir(void);                                             //~v05LR~
//**************************************************************** //~v0ieI~
int dlcpdhsrch2(PUFILEH Ppfh,char *Pfullpath,PUDIRLH *Pppdh,PUDIRLH *Pppdhp);//~v0ieR~
//**************************************************************** //+v57gI~
int dlcpdhsrchts(PULINEH Pplh,PUDIRLH Ppdhkey,PUDIRLH *Pppdhout);  //+v57gI~
//**************************************************************** //~v0ieI~
PUDIRLH dlcpdhsrch(PUFILEH Ppfh,char *Pfullpath,PUDIRLH *Pppdhp);  //~v0ieI~
//**************************************************************** //~v10rI~
int dlcmdseteditlc(PUFILEC Ppfc);                                  //~v10rI~
