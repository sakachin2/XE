//*CID://+vby8R~:                             update#=  137;       //~vby8R~
//*********************************************************************
//*xesub.h
//* common routine hdr
//*********************************************************************
//vby8:230415 (ARM)open document file                              //~vby8I~
//vb89:170217 create if not found. ::xehosts ::xesync_.cfg         //~vb89I~
//vb4h:160804 fnm list reverse len is short because strlen stop by 00 of dbcs unicode//~vb4hI~
//vb2e:160122 convert filename according IOCHARSET mount option    //~vb2eI~
//vb28:160116 (BUG)display spilit utf8 by lineattr                 //~vb28I~
//vauD:140315 (Win BUG)Ctl+W(copyword to cmdline) from dirlist;keep original u8/lc and ignore kbd mode.//~vauDI~
//vagv:120915 delete unused function; filesetdbcstblu              //~vagvI~
//vaar:120101 over vaap;not by padding but position for ddfmt also for locale dbcs(contains "d")//~vaarI~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va8j:101013 SPLit cmd;dbcs consideration for TAIL cut without SBCS option .//~va8jI~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va5t:100515 display filenamelist by dd fmt                       //~va5tI~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20R~
//va1r:091108_(UTF8)cmd string get/set by all of lc, u8 and ct to avoid miss interpretation//~va1rI~
//va1c:091030_merge GB18030 support                                //~va1cI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          cmdline may be mixed of utf8 and locale code           //~va00I~
//          filename list is mixed of utf8 and locale code         //~va00I~
//v7ak:081208 cause newfile if UNC name is netaddr only (missing share folder)//~v7akI~
//v78Z:080708 (3270)sw key assignment by hot key                   //~v78ZI~
//v77y:080118 *\/^* support for dos cmd                            //~v77yI~
//v76p:070628 compare remote file support                          //~v76pI~
//v750:070416 split cmd;setdbcs when dbcs split by SBCS option     //~v750I~
//v74W:070407 split cmd bnds/margin support                        //~v74WI~
//v74x:070223*(BUG)generated tab expand required for "cv x2c"      //~v74xI~
//v73q:070121*(BUG)for the line oom contain tab,after del omm contains imm data by shiftback//~v73qI~
//v73h:070114 (BUG)tab rep by hex mode dosen not delete expanded char//~v73hI~
//v730:061225 use UPLbuff for cmdline(to display as long as possible if del key used, and accept insert over screen width)//~v730I~
//v636:050428 new workdir filename naming ::#((pid).xxx) for grep work filename//~v636I~
//v49b:020623 support *= for not only "(i)x all" but also "(i)find","change"//~v49bI~
//v48c:020429 (UNX)edit/browse mdos disk support                   //~v45cI~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd            //~v45xI~
//v44a:011202 (BUG)hex input replace another tab char to space     //~v44aI~
//v40w:010618 display unprintable for dbcs split by line width parm//~v40wI~
//v40u:010617 wild-card support for path name if dir contain only one member.//~v40uI~
//            (replace v143)                                       //~v40uI~
//v21n:010114 LINUX support:wordrep may dsetroy dbcs conbination   //~v21nI~
//v09Y:970629:file NULL(0x00) support                              //~v09YI~
//            set dbcstbl(new function for file area only)   sub   //~v09YI~
//v05O:960120:copy/move cmd *\(same as source)/ **\(parent of source) support//~v05OR~
//*v039:950728:bug,setflddata need set dbcstbl also             //~v039I~
//*v020:950616:dir support(fldprotchk return pfld)              //~v020I~
//*********************************************************************//~v020I~
#ifdef XESUB_GBL                                                   //~v40uI~
    int Gsubgblopt;                                                //~v40uI~
#else                                                              //~v40uI~
    extern int Gsubgblopt;                                         //~v40uI~
#endif                                                             //~v40uI~
#define XESUB_GBLOPT_WILDPATH    0x01	//expand wild card path if it has only a member//~v40uI~
#define XESUB_GBLOPT_WILDMEMB    0x02	//expand wild card last filename if it has only a member//~v40uI~
#ifdef LNX                                                         //~vb2eI~
#define XESUB_GBLOPT_RQ_NOCHKMOUNT_FFP     0x04   	//filefullpath dose not check mount option//~vb2eR~
#define XESUB_GBLOPT_DONE_CHKMOUNT_FFP     0x08     //filefullpath did check mount option//~vb2eR~
#define XESUB_GBLOPT_DONE_L2F              0x10     //filefullpath did l2f conversion//~vb2eR~
#define XESUB_GBLOPT_RC_MOUNTU8_FFP        0x20     //filefullpath did check mount option//~vb2eI~
#endif                                                             //~vb2eI~
#define XESUB_PIDFILEID  '#'     //::# is translated to ::pid.     //~v636I~
#define XESUB_NOTDBCSDBCSPIDFILEID  '#'     //::# is translated to ::pid.//~va1cR~
//*********************************************************************//~v020I~
//* FUNCTION *******************************
//*******************************************************       //~v020I~
int filefind(UCHAR *Ppfile,UCHAR *Pfullpath,FILEFINDBUF3 *Ppfstat3,//~5513R~
			 int Pmsgopt);                                      //~5513I~
#define FFMSG   	0                                           //~5625R~
#define FFNONFMSG   1                                           //~5625R~
#define FFNODIRMSG  2                                           //~5625R~
#define FFNORPATHER 4     //avoid UNC format path err(\\remote is invalid fmt err)//~v7akI~
//*******************************************************       //~5625I~
int filedirchk(UCHAR *Pfilename);                               //~5625I~
//*******************************************************
FILE *fileopen(UCHAR *Ppfile,UCHAR *Ppopt);

#ifdef UNX                                                         //~v48cI~
//*******************************************************          //~v48cR~
FILE *fileopen_mdostemp(UCHAR *Ppfile,UCHAR *Ppopt,int Pnewsw,UCHAR *Pmdostempfnm);//~v48cR~
#endif                                                             //~v48cI~
                                                                   //~v48cR~
//*******************************************************
int fileclose(UCHAR *Pfile,FILE* Pfh);                          //~v039I~

#ifdef UNX                                                         //~v48cI~
//*******************************************************          //~v48cI~
int fileclose_mdos(UCHAR *Pmdosfile,UCHAR *Ptempfile);             //~v48cI~
#endif                                                             //~v48cI~
                                                                   //~v48cI~
//*******************************************************          //~v76pI~
int filefullpatha(int Popt,PUCLIENTWE Ppcw,char* Pfnm,char *Plocalfnm,char *Pfpath,char *Pfpathlocal);//~v76pR~
#define FFPA_WILDPATH              0x01                            //~v76pR~
#define FFPA_WILDMEMB              0x02                            //~v76pR~
#define FFPA_REMOTEDIR             0x04 //already known as remote dir//~v76pR~
#define FFPA_REMOTEFILE            0x08 //already known as remote file//~v76pI~
#define FFPA_LOCALCOPYIFREMOTEFILE 0x10 //get local copy if remote file//~v76pI~
#define FFPA_FULLPATHTEMP          0x20 //create local filename from fullpath name//~v76pI~
//*******************************************************       //~5318M~
char *filefullpath(char *Pfullpath,char *Pfilename,size_t Plen);//~5318M~
//*******************************************************       //~v05OI~
char *filefullpath2(char *Pfullpath,char *Ptarget,size_t Plen,char *Psource);//~v05OR~
#define SAMEDIR  	'*'                                         //~v05OM~
//*******************************************************          //~v77yI~
int subeditscrfnm(int Popt,PUCLIENTWE Ppcw,char *Pinp,char *Pout); //~v77yR~
//*******************************************************
//*dbcs tbl output
//*******************************************************
void setdbcstbl(UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen);
//*******************************************************          //~v09YI~
//*dbcs tbl output for file client area only                       //~v09YI~
//*******************************************************          //~v09YI~
int filesetdbcstbl(UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,int Popt); //~v44aR~
#define FSDT_TABSAVE       1	//preserve previous tab id         //~v44aI~
#define FSDT_TABSET      0x02   //set tabid on dbcs tbl for utf8 hex rep//~v74xI~
#define FSDT_EBC         0x04   //if off ignore request for ebc filea50R~//~va50R~
#define FSDT_EBCONLY     0x08   //if on  ignore request for locale file//~va50I~
#define FSDT_LOADEBC     0x10   //from filechktabdbcs at load time(ULHdbcs=0)//~va50R~
#define FSDT_CALLOC      0x20   //null initialized                 //~va7xR~
#define FSDT_B2B         0x40     //B2B                            //~va7LI~
#define FSDT_CVCMD       0x80     //by CV cmd                      //~va7LI~
#define FSDT_TGTDBCS     0x0100   //Phandle is dbcs                //~va7LR~
#define FSDT_SRCDBCS     0x0200   //UFHhandle  dbcs                //~va7LR~
//*******************************************************          //~va50R~
int filesetdbcstblplh(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int Plen);//~va50R~
//*******************************************************          //~va7LI~
int filesetdbcstblplh_handle(int Popt,int Phandle,PUFILEH Ppfh,PULINEH Pplh,int Ppos,int Plen);//~va7LI~
//*******************************************************          //~va20R~
#ifdef UTF8UCS2                                                    //~va20R~
#ifdef AAA                                                         //~vagvI~
int filesetdbcstblu(int Popt,PULINEH Pplh,UCHAR *Ppdata,UCHAR *Ppdbcs,int Plen,int *Pnewlen);//~va20R~
#endif                                                             //~vagvI~
#endif                                                             //~va20R~
//*******************************************************          //~v74xI~
int setdbcstbltabid(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~v74xR~
#define SDTTI_INIT        0x01   //initial(ignore previous dbcstbl value)//~v74xR~
#define SDTTI_SETTABFOUND 0x02   //set ULHF2TABFOUND               //~v74xI~
//*******************************************************       //~5224I~
int getcmdstr(UCHAR *Pcin,UCHAR *Pcout);                        //~5224I~
//*******************************************************
//*get next commnad parse
//*******************************************************
void getnextcmd(UCHAR *Pcin,UCHAR *Pcout);
//*******************************************************       //~v039I~
int getfldpos(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR **Pout,UCHAR **Pdbcs);//~v039I~
//*******************************************************          //~vb4hI~
int getfldstrlen(int Popt,char *Pdata,char *Pdbcs,int Pfldsz);     //~vb4hI~
//*******************************************************
int getfldinput(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pout);
#ifdef UTF8SUPPH                                                   //~va00I~
	int getfldinput_utf8(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pout);//~va00R~
    #define BYUTF8_getfldinput(Popt,Ppcw,Prow,Pfldno,Pout) \
			getfldinput_utf8(Popt,Ppcw,Prow,Pfldno,Pout)           //~va00R~
#else                                                              //~va00I~
    #define BYUTF8_getfldinput(Popt,Ppcw,Prow,Pfldno,Pout) \
			getfldinput(Ppcw,Prow,Pfldno,Pout)                     //~va00R~
#endif                                                             //~va00I~
//*******************************************************
int setflddata(PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata);
//*******************************************************          //~va5tI~
int setflddatadd(int Popt,PUCLIENTWE Ppcw,int Prow,int Pfldno,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~va5tR~
//**************************************************            //~4C23I~
int fldprotchk(PUCLIENTWE Ppcw,int Popt,PVOID Pppfld);          //~v020I~
#define FPC_DBCSCHK	   	0                                       //~5423I~
#define FPC_NODBCSCHK   1                                       //~5423I~
//*******************************************************       //~v020M~
PVOID getuflde(PUCLIENTWE Ppcw,int Prow,int Pfldno);            //~v020R~
//**************************************************            //~5103I~
//**************************************************               //~va1cR~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int setdbcssplit(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar);//change prototype to search user//~va50I~
#else                                                              //~va50I~
int setdbcssplit(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar);//~5103I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**************************************************               //~v40wI~
//int setdbcssplit2(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar);//~v40wI~//~vb28R~
int setdbcssplit2(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar,UCHAR Prepdbcs);//~vb28I~
//**************************************************            //~5503I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
int setobtabdbcs(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Prangelen);//~va50R~
#define SOTDO_EBCMASK        0xff  //ebc file                      //~va50I~
#define SOTDO_NOSBCSIFEBC  0x0100  //dbcs consideration if EBC file//~va8jI~
#define SOTDO_NOSOSIDBCSCONCAT 0x0200 //concat dbcs2nd+dbcs1st at boundary//~va8jI~
#else                                                              //~va50I~
void setobtabdbcs(UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,//~5503I~
					int Prangelen);                             //~5503I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
//**************************************************               //~v74WI~
int setobtabclear(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Prangelen);//~v74WI~
//**************************************************            //~5225I~
int wordtblisrch(UCHAR *Pword,UCHAR *Pwordtbl);                 //~5225I~
//**************************************************            //~v039I~
int getpathlen(UCHAR *Pfilename,UCHAR *Plevel,int Pdirsw);      //~v039I~
#define GPL_DIR          0x01                                      //~vaa0I~
                                                                   //~vaa0I~
#ifdef UNX                                                         //~vaa0I~
#define GPL_WILDNAME     0x02       //wildcard name is real name   //~vaa0I~
#endif                                                             //~vaa0I~
//**************************************************               //~v09YI~
int subgetfilelc(int Popt,UCHAR *Ppfnm,ULONG *Pplinecnt);          //~v09YR~
#define GETLC_FPATHINP   0x01		//parm fname is already fullpath//~v09YI~
//**************************************************               //~v21nI~
//void setobdbcserr(UCHAR *Pdbcs,int Plen,int Ppos1,int Ppos2);    //~v49bR~
void setobdbcserr(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos1,int Ppos2);//~v49bR~
//**************************************************               //~v750I~
int setibdbcserr(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos1,int Ppos2);//~v750I~
//**************************************************               //~v750I~
int setsplitdbcserr(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos);  //~v750I~
//**************************************************               //~v45xI~
int btabclear(UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Popt);//~v45xI~
//**************************************************               //~v730I~
int setflddatacmd(PUCLIENTWE Ppcw,UCHAR *Pdata);                   //~v730I~
//**************************************************               //~v730I~//~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef EEE                                                         //~va00I~
	int setflddatacmd_byutf8(int Popt,PUCLIENTWE Ppcw,UCHAR *Pdata);                   //~v730I~//~va00I~
	#define BYUTF8_setflddatacmd(Popt,Ppcw,Pdata)  setflddatacmd_byutf8(Popt,Ppcw,Pdata)//~va00R~
#endif                                                             //~va00I~
//**************************************************               //~va00I~
	int setflddatadbcscmd_byutf8(int Popt,PUCLIENTWE Ppcw,int Ppos,UCHAR *Pdata,UCHAR *Pdbcs,int Plen);//~va00I~
//  #define SFDDCUO_SETDBCS      0x01   //dbcstbl setup required   //~va00R~
	#define SFDDCUO_INS          0x02   //insertmode               //~va00I~
	#define SFDDCUO_FULLREP      0x04   //fully replace            //~va00I~
	#define SFDDCUO_SETCT        0x08   //lc/ct is on Gcmdbufflc/Gcmdbuffct//~va1rI~
#ifdef UTF8UCS2                                                    //~va20I~
	#define SFDDCUO_SETCT2       0x10   //not fullrep but lc/ct is on Gcmdbufflc/Gcmdbuffct//~va20I~
#endif                                                             //~va20I~
	#define SFDDCUO_CAP          0x20   //paste cmd to cmdline     //~vaarI~
	#define SFDDCUO_UTF8         0x40   //from func_copyword_dir;membername is utf8//~vauDI~
	#define SFDDCUO_LC           0x80   //from func_copyword_dir;membername is LC//~vauDI~
//**************************************************               //~va00I~
	int getfldutf8(PUCLIENTWE Ppcw,int Prow,int Pfldno,char **Pputf8,char **Ppcodetype);//~va00I~
//**************************************************               //~va00I~
	int setflddatadbcs(int Popt,char *Ptgt,char *Ptgtdbcs,int Ptgtlen,int *Pptglen,//~va00I~
						int Ptgtpos,int Ptgtwidth,char *Psrc,char *Psrcdbcs,int Psrclclen);//~va00I~
    #define SFDDO_STRZ      0x01                                   //~va00I~
    #define SFDDO_INS       0x02                                   //~va00I~
#else                                                              //~va00I~
	#define BYUTF8_setflddatacmd(Popt,Ppcw,Pdata)  setflddatacmd(Ppcw,Pdata)//~va00R~
#endif                                                             //~va00I~
//**************************************************               //~v73hI~
int delobtabpad(UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos);  //~v73hI~
//**************************************************               //~v73hI~
int updatedbcstblhex(int Pmode,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Pch,int *Ppaddlen,int Poomlen);//~v73qI~
#define UDBTH_INS  0x01                                            //~v73hI~
#define UDBTH_DEL  0x02                                            //~v73hI~
#define UDBTH_REP  0x04                                            //~v73hI~
//**************************************************               //~v73hI~
int sub_restoretabdroppad(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen);//~v73hR~
//**************************************************               //~v76pI~
int subsavetempfnm(char *Pfnm,int Plen);                           //~v76pI~
//**************************************************               //~v76pI~
int subdeletetempfile(void);                                       //~v76pI~
//**************************************************               //~v78ZI~
int gethomepos(int Popt,PUCLIENTWE Ppcw);                          //~v78ZR~
//**************************************************               //~vb89I~
FILE *fileopencreate(int Popt,UCHAR *Ppfile,UCHAR *Ppopt,UCHAR *Pdummyrecord);//~vb89R~
#define FOCO_CLOSE  0x01      //close at return                    //~vb89I~
//*******************************************************          //~vby8I~
#ifdef ARMXXE                                                      //~vby8I~
FILE *xesub_openDoc(int Popt,PUFILEH Ppfh,UCHAR *Ppfile,UCHAR *Ppopt);//~vby8R~
#endif                                                             //~vby8I~
//*******************************************************          //~vbyaI~
FILE *fileopenWithOption(int Popt,UCHAR *Ppfile,UCHAR *Ppopt);       //~vbyaI~//~vby8R~
#define FOWOO_ALLOWDOC    0x01                                     //~vbyaI~//~vby8R~
//*******************************************************          //~vbyaI~
