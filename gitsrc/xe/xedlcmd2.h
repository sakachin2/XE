//*CID://+vb2sR~:                             update#=   29;       //+vb2sR~
//****************************************************************//~v043I~
//vb2s:160206 (Win)target err msg if slinkerr                      //+vb2sI~
//vavH:140403 (W32UNICODE)set UTF8 option of parm filename for xdc/xfc because cmd prompt translate to locale//~vavHI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8,option cplc/cpu8                 //~va00I~
//v92h:080505 (UTF)new dlcmd "[":cplc, "]":cpu8 option for edit/browse//~v92hI~//~va00I~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HR~
//v75G:070508 dlcmd "3" support like as on filename panael         //~v75GI~
//v731:061226 filesize>4GB support                                 //~v731I~
//v59c:041107 % lcmd:remote support(use rsh)                       //~v59cI~
//v57j:040522 sort cmd for dirlist                                 //~v57jI~
//v568:040402 (WXE:BUG)ignore association for dir(force open by xe)//~v568I~
//v55U:040321 (WXE)openwith when dblclick on filenamelist/dirlist if associated//~v55UI~
//v50G:030201 add cmd "et"/"bt"/"st" for e/b/s /mt                 //~v50GI~
//v47Q:020330 leave "s" as old fashion and use "o" for edit/browse wit patm//~v47QI~
//v47P:020330 dlcmd "s" support option specification               //~v47PI~
//v44t:011206 dlcmd "I":/Mcn,"J":/Mkn                              //~v44tI~
//v44g:011204 new dlcmd 'K':/Mk(cob with no num),'N':/Mn(spf),'L':/Mc//~v44gI~
//v44f:011204 new dlcmd 'H'/'h'(h:follow edit/browse open mode,'H':reverse)//~v44fI~
//v152:000311 dir-list REFresh cmd                                 //~v152I~
//v10v:990326 chng browse binary mode:"2" -->"1",and add "2" as edit binary mode//~v10vI~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v10p:990326 new dlcmd "2";browse binary mode                     //~v10pI~
//v0g1:971207 print parm by short filename option(opt plfn on/off) //~v0g1I~
//v0fp:971108 split dlcmd2-->dlcmd5.c                              //~v0fpI~
//v09w:970524:Select cmd support on dir list                       //~v09wR~
//            update pdh line timstamp/size(search function)       //~v09wR~
//v05G:960105:update time stamp of dir list when edit saved(add to v04j)//~v05GI~
//            change interface of dlcgetfullname(plc-->pdh parm)//~v05GI~
//v04b:950924:expand all dlcmd(>)                               //~v04bI~
//v046:950923:view dir lcmd                                     //~v046I~
//v043:950917:cur dir lcmd(.)                                   //~v043I~
//****************************************************************//~5715I~
//*xedlcmd2.h                                                   //~5715I~
//****************************************************************//~5715I~
		DLCMDFUNC dlcmdselect;                                     //~v47PI~
		DLCMDFUNC dlcmdselecttext;                                 //~v50GI~
		DLCMDFUNC dlcmdopen;                                       //~v47QI~
		DLCMDFUNC dlcmdbrowse;                                  //~5806M~
		DLCMDFUNC dlcmdbrowse2; 	//binary mode                  //~v10pI~
	    DLCMDFUNC dlcmdedit2  ; 	//edit   mode                  //~v10vI~
#ifdef UTF8SUPPH                                                   //~v92hM~//~va00R~
	    DLCMDFUNC dlcmdedit3; 	//browse/edit utf8                 //~v92hI~//~va00I~
#endif                                                             //~v92hM~//~va00I~
	    DLCMDFUNC dlcmdbinbe3 ; 	//browse/edit binary mode      //~v75GI~
	    DLCMDFUNC dlcmdeditf80; 	//edit with f80 option         //~v75HI~
		DLCMDFUNC dlcmdedit;                                    //~5806M~
		DLCMDFUNC dlcmdviewb;                                   //~v046I~
		DLCMDFUNC dlcmdviewe;                                   //~v046I~
		DLCMDFUNC dlcmdexpand;                                  //~5806I~
		DLCMDFUNC dlcmdexpandall;                               //~v04bR~
		DLCMDFUNC dlcmdunexpand;                                //~5806I~
		DLCMDFUNC dlcmdexclude;                                 //~5806I~
		DLCMDFUNC dlcmdunexclude;                               //~5806I~
		DLCMDFUNC dlcmdpath;                                    //~5813I~
		DLCMDFUNC dlcmdcd;                                      //~v043I~
		DLCMDFUNC dlcmdfree;                                    //~v046I~
		DLCMDFUNC dlcmdhex;      //hex display                     //~v44fI~
		DLCMDFUNC dlcmdcobnum;   //cobol with col1-6 seqno         //~v44gR~
		DLCMDFUNC dlcmdcobspace; //cobol with col1-6 space         //~v44gR~
		DLCMDFUNC dlcmdspfcobnum;   //spfcobol with col1-6 seqno   //~v44tI~
		DLCMDFUNC dlcmdspfcobspace; //spfcobol with col1-6 space   //~v44tI~
		DLCMDFUNC dlcmdspf;      //numbered file                   //~v44gR~
//****************************************************************//~v05GI~
int dlcmdresetdata(PUDIRLH Ppdh);                               //~v05GR~
//****************************************************************//~v04bI~
int dlcmdfreesub(PUCLIENTWE Ppcw,PUFILEC Ppfc);                 //~v04bI~
//****************************************************************//~v04bI~
int dlcgetfullname(PUDIRLH Ppdh,UCHAR *Pfname);                 //~v04bI~
//**************************************************************** //~v59cI~
//int dlcgetfullnameenclose(PUDIRLH Ppdh,UCHAR *Pfname);             //~v59cI~//~vavHR~
int dlcgetfullnameenclose(int Popt,PUDIRLH Ppdh,UCHAR *Pfname);    //~vavHI~
#ifdef W32UNICODE                                                  //~vavHI~
	#define DLCGFEO_ENCUD	0x01   //enclose if UD str             //~vavHI~
	#define DLCGFEO_STRIPUD 0x02   //strip UD                      //~vavHI~
	#define DLCGFEO_ALIAS   0x04   //use alias for UD fmt          //~vavHI~
#endif                                                             //~vavHI~
//**************************************************************** //~v55UI~
//int dlcgetdirlistfname(PUCLIENTWE Ppcw,char *Pfpath);            //~v568R~
int dlcgetdirlistfname(PUCLIENTWE Ppcw,char *Pfpath,PUDIRLH *Pppdh);//~v568I~
                                                                   //~v10pI~
#if defined(W32) || defined(DPMI)                                  //~v0g1I~
//**************************************************************** //~v0g1I~
int dlcgetfullnamealias(PUDIRLH Ppdh,UCHAR *Pfname);               //~v0g1I~
#endif                                                             //~v0g1I~
                                                                   //~v10pI~
//****************************************************************//~v046I~
void dlcmddeqpfc(PUFILEC Ppfc);                                 //~v046I~
//**************************************************************** //~v10pI~
void dlcmdlvlclear(PUCLIENTWE Ppcw,PUDIRLH Ppdh,int Popt,int Paction);//~v04bR~
//**************************************************************** //~v0fpI~
void dlcmddeqpfc(PUFILEC Ppfc);                                    //~v0fpI~
//**************************************************************** //~v10rR~
int dlcmdsetszorlc(PUCLIENTWE Ppcw,PULINEH Pplh,int Popt);         //~v10rR~
//**************************************************************** //~v10rI~
//int dlcmdresetparentsz(PUDIRLH Ppdh,int Popt,ULONG Paddsz,LONG Paddlc);//~v731R~
int dlcmdresetparentsz(PUDIRLH Ppdh,int Popt,FILESZT Paddsz,LONG Paddlc);//~v731I~
#define DLCPSZ_SZ   1           //size update                      //~v10rR~
#define DLCPSZ_LC   2           //lc   update                      //~v10rR~
//**************************************************************** //~v152I~
int func_dlcmdrefresh(PUCLIENTWE Ppcw);                            //~v152I~
//**************************************************************** //~v57jI~
int dlcmdexpandbysort(PUCLIENTWE Ppcw,char *Psortopt);             //~v57jI~
//**************************************************************** //~v75JI~
int dlcmdbecmdid(PUCLIENTWE Ppcw,PUDLCMD Pplc);                    //~v75JI~
//**************************************************************** //~v75JI~
int dlcmdotherbecmd(PUCLIENTWE Ppcw,PUDLCMD Pplc,char *Pmode);     //~v75JI~
//**************************************************************** //+vb2sI~
int dlcgetfullnamefilejunctiontarget(PUDIRLH Ppdh,UCHAR *Pfname);  //+vb2sI~
