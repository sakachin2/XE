//CID://+vb7fR~:         update#=      6                           //~vb7fR~
//****************************************************************//~5820I~
//*xedlcmd4.h                                                      //~v19FR~
//****************************************************************//~5820I~
//vb7f:170109 FTP:not found msg if deleded undelsavefile           //~vb7fI~
//vb7c:170106 longname support; del on root file(xmove to undeldir fails)//~vb7cI~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//v62h:050316 ftp undel support                                    //~v62hI~
//v19Y:000929 LINUX support(dir tbit means protection of another owners file from rename/unlink)//~v19YI~
//            But it is effective only if the dir owner is not me) //~v19YI~
//v19U:000928 LINUX support(undo dirlist;pre chk owner;only owner can unlink/rename)//~v19UI~
//v19F:000925 LINUX support(XE_UNDEL_%d:add uid to undo dir name for permition)//~v19FI~
//**************************************************************** //~v19FI~
		DLCMDFUNC dlcmdundelete;                                //~5C23R~
//**************************************************************** //~v19FI~
#ifdef UNX                                                         //~v19FI~
void dlcmdundelinit(void);                                         //~v19FI~
int dlcmdtbitchk(PUDIRLH Ppdh,int Popt);                           //~v19YR~
#define DLCTBCMSG 0x01		//msg when owner unmatch               //~v19YR~
#endif                                                             //~v19FI~
//****************************************************************//~6104I~
int dlcmdundelterm(void);                                       //~6104I~
//****************************************************************//~5C24I~
int dlcmdundelprep(PUCLIENTWE Ppcw,UCHAR *Pfullpath,PUDIRLH Ppdh);//~5C24I~
//**************************************************************** //~v62hI~
#ifdef FTPSUPP                                                     //~v62hI~
	int dlcmdftpundelprechk(UCHAR *Pfullpath,char *Pnewname);      //~v62hR~
	int dlcmdftpundelprep(PUCLIENTWE Ppcw,PUDIRLH Ppdh,UCHAR *Pfullpath,UCHAR *Pnewname);//~v62hI~
	int dlcmdftpundelprepdir(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUDIRLH Ppdh,UCHAR *Pfullpath);//~v62hI~
#endif                                                             //~v62hI~
#ifdef UNX                                                         //~vaa0I~
void dlcmdwildrenamemsg(int Popt,char *Pnewname);                  //~vaa0I~
#endif                                                             //~vaa0I~
int dlcUndelPrepRenameLongname(int Popt,char *Psrc,char *Ptgt,int Ptgtpos,int Pbuffsz);//~vb7cM~
#define DLCYRLO_NOFSTAT    0x01                                    //~vb7cI~
//**************************************************************** //~vb7fI~
int dlcmdftpclearundelsaveDeleted(char *Prenamedsave);             //~vb7fI~
//**************************************************************** //+vb7fI~
int dlcmdftpclearundelsaveDeletedDir(char *Pfpathrenamesave);      //+vb7fI~
