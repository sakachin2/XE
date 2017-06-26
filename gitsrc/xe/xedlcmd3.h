//CID://+vb7cR~: update#=      7                                   //+vb7cR~
//****************************************************************//~5820I~
//*xedlcmd3.h                                                   //~5820I~
//****************************************************************//~5820I~
//vb7c:170106 longname support; del on root file(xmove to undeldir fails)//+vb7cI~
//van3:131127 support select of invalid(wildcard) name entry on dir list//~van3I~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//v71o:061020 3270:wildcard mask support for dlcmd copy            //~v57BI~
//v57B:040605 xpr dir support                                      //~v57BI~
//v09b:970510:disk free space display                              //~v09bI~
//            -req update free space info(dlcmd3.c,dlcmd4.c,dlcmd3.h)//~v09bI~
//v07e:960629:dir lcmd copy(PF10 and PF11)                         //~v07eI~
//v060:960204:add dir lcmd "z","0"(undeletable delete)          //~v060I~
//v05S:960131:force delete r-only from dlcmd("/" cmd)           //~v05SI~
//****************************************************************//~v05SI~
		DLCMDFUNC dlcmddelete;                                  //~5820I~
		DLCMDFUNC dlcmddeleter;	//del force read only           //~v060R~
		DLCMDFUNC dlcmddeletez; //del without undel             //~v060I~
		DLCMDFUNC dlcmddeletezr;//del without undel force read only//~v060I~
#define DLCMDDELRONLY    0x01     //parm to dlcmddelete from dlcmddeleter//~v060R~
#define DLCMDDELNOUNDEL  0x02     //ignore Undelele_option      //~v060I~
		DLCMDFUNC dlcmdrename;                                  //~5826I~
		DLCMDFUNC dlcmdattrib;                                  //~5906I~
		DLCMDFUNC dlcmdcopymove;                                //~5B19R~
		DLCMDFUNC dlcmdprint;                                   //~5A14I~
//****************************************************************//~5B25I~
int dlcmddelflag(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh);    //~5B25I~
                                                                //~5B25I~
//****************************************************************//~5B25I~
int dlcmddelview(PUCLIENTWE Ppcw,PUDIRLH Ppdh);                 //~5B25I~
                                                                //~5B25I~
//****************************************************************//~5B26I~
int dlcmdmoveflag(PUCLIENTWE Ppcw,PULINEH Pplh,PUDIRLH Ppdh,int Pchildsw);//~6115I~
                                                                //~5B26I~
//****************************************************************//~5A22I~
int dlcmdxpflist(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Precno);      //~5A22R~
                                                                   //~v07eI~
//**************************************************************** //~v07eI~
int dlcmdnoattrerr(void);                                          //~v07eI~
                                                                   //~v07eI~
//**************************************************************** //~v07eI~
int dlcmdnodesterr(void);                                          //~v07eI~
                                                                   //~v07eI~
//**************************************************************** //~v09bR~
void dlcfsiupdate(PUCLIENTWE Ppcw);                                //~v09bR~
                                                                   //~v57BI~
//**************************************************************** //~v57BI~
int dlcxpdelremotetemp(void);                                      //~v57BI~
                                                                   //~v57BI~
//**************************************************************** //~v57BI~
int dlcxpgettmpdir(char *Pptmpdir);                                //~v57BI~
                                                                   //~v57BI~
//**************************************************************** //~v57BI~
//int dlcmdappendwildcard(int Popt,PUFILEH Ppfh,PUDIRLH Ppdh,char *Pfullpathname);//~v57BI~//+vb7cR~
int dlcmdappendwildcard(int Popt,PUFILEH Ppfh,PUDIRLH Ppdh,char *Pfullpathname,int Pbuffsz);//+vb7cI~
#define DLCAW_ALLMEMB   0x01        //wppend * when no wildcard specified//~v57BI~
#ifdef UNX                                                         //~vaa0I~
//**************************************************************** //~vaa0I~
int dlcmdresetwildmultiple(int Popt,PUFILEH Ppfh,PUDIRLH Ppdh,char *Pfilename);//~vaa0R~
#endif                                                             //~vaa0I~
#ifdef W32                                                         //~van3I~
int dlcerrwildname(PUDIRLH Ppdh);                                  //~van3I~
#endif                                                             //~van3I~
