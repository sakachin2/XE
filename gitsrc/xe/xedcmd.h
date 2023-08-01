//*CID://+vbygR~:      update#=     10                             //~vbygR~
//****************************************************************
//xedcmd.h
//****************************************************************
//vbyg:230508 correct errmsg;distinguish for dlcmd and dcmd        //~vbygI~
//van2:131127 support deletion of invalid(wildcard) name entry on dir list//~van2I~
//vac2:120204 (SMB)target:windows consideration                    //~vac2I~
//vaa4:110520 ANDROID Send command/dlcmd                           //~vaa4I~
//v781:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v781I~
//v70q:060823 SUB cmd;support /U option(submit using) to submit to the script file//~v70qI~
//v646:050617 copy/move d(l)cmd wild path support                  //~v646I~
//v630:050426 grep support  as dos cmd(for edit screen flag line and search by rfind for *L)//~v630I~
//v59E:041120 (WXE)pass env to sub process xesyscmd.exe            //~v59EI~
//v59g:041107 rsh:set MOCMD screen as rlogin                       //~v59gI~
//v59f:041107 (BUG)attr change not availe for remotefile           //~v59fI~
//v53Q:031103 ftp support(4 byte udirlist attr for ! UNX);ulib:v59e//~v53QI~
//v47C:020323 disket support;mkdir,rmdir,attrib                    //~v47CI~
//v20h:001015 LINUX support("*"(all member) confirmation           //~v20hI~
//            for rename,xcopy,xmove,attribute,xprint(not edit screen only)//~v20hI~
//v208:000930 add chmod cmd(also for other platform)               //~v208I~
//v19t:000923 LINUX support(cmd PWD support)                       //~v19tI~
//v19c:000904 LINUX support(attr size,1-->4)                       //~v19cI~
//v11M:990828 dcmd xprint;filename=* should be current status(updated).//~v11MI~
//v11K:990828 *\ support for sorce file of mkdir/rmdir/cd          //~v11KI~
//v11H:990822 *\ support for sorce file of xcopy/xmove/append/rename/attr/del/xdd//~v11tI~
//v11t:990813 rename target wild card support                      //~v11tI~
//v0ia:980530 add APPend cmd(avail by also CAP Alt+h)              //~v0iaI~
//v060:960204:add dir lcmd "z","0"(undeletable delete)          //~v060I~
//v05R:960121:rmdir/file del by all xdd for read only chk       //~v05RI~
//v05Q:960121:xdd force option for move inter-drive,delete undel save at term//~v05QI~
//v05m:951123:xdd command(del dir)                              //~v05mI~
//v05i:951114:xmove cmd                                         //~v05iI~
//v042:950916:xcopy  cmd                                        //~v042I~
//v03z:950903:attrib cmd,rmdir,mkdir                            //~v03zR~
//v03p:950820:dos command delete/rename                         //~v03pI~
//****************************************************************//~v03pI~
//*DATA TYPE *******************************
//************************************
//*dos command table
//************************************
typedef struct _UDCMDTBL
{
		UCHAR  UDCcmd  [8];			//command word
		UCHAR  UDCcmda [4];			//abrebiation
 		FTFUNC *UDCfunc;			//function addr
		UCHAR  UDCflag;				//func flag                 //~v020M~
#define UDCLINECMD 		0x01		//avail for command line input//~v020M~
		UCHAR  UDCrsv[3];                                       //~v020M~
} UDCMDTBL;                                                     //~v020R~
typedef UDCMDTBL *PUDCMDTBL;                                    //~v020R~
#define UDCMDTBLSZ (sizeof(UDCMDTBL))

//*FUNCTION**************
	FTFUNC dcmd_drive;                                          //~v020I~
	FTFUNC dcmd_cd;                                             //~v020I~
	FTFUNC dcmd_pwd;                                               //~v19tI~
	FTFUNC dcmd_xdelete;                                        //~v05iR~
	FTFUNC dcmd_xdd;        //deldir                            //~v05mI~
	FTFUNC dcmd_rmdir;                                          //~v03zI~
	FTFUNC dcmd_mkdir;                                          //~v03zI~
	FTFUNC dcmd_rename;                                         //~v03pI~
	FTFUNC dcmd_xcopy;                                          //~v042I~
	FTFUNC dcmd_xmove;                                          //~v05iI~
	FTFUNC dcmd_append;                                            //~v0iaI~
	FTFUNC dcmd_attribute;                                      //~v03pI~
	FTFUNC dcmd_chmod;                                             //~v208R~
	FTFUNC dcmd_rlogin;                                            //~v59gI~
	FTFUNC dcmd_grep;                                              //~v630I~
#ifdef ARM                                                         //~vaa4R~
	FTFUNC dcmd_androsend;                                         //~vaa4I~
#endif                                                             //~vaa4R~
//**************************************************************** //~v781I~
int dcmdinit(int Popt);                                            //~v781I~
//**************************************************************** //~v781I~
#ifdef WINCON                                                      //~v781I~
	int dcmdrestoreconsolemode(int Popt);                          //~v781R~
#endif                                                             //~v781I~
//****************************************************************//~v05RI~
int dcmddelxdd(PUCLIENTWE Ppcw,int Popdno,UINT Pmask,int Pxdelopt,//~v05RI~
				int Pxddopt,int Pxddid,PUDIRLH Ppdh);           //~v05RI~
#define DCMDXDDIDDEL      0x00		//called from DEL cmd       //~v060I~
#define DCMDXDDIDXDD      0x01		//called from XDD cmd       //~v060I~
#define DCMDXDDIDNOUNDEL  0x02		//called from DEL cmd       //~v060I~
#define DCMDXDDID_DCMD    0x04		//by not dlcmd but dcmd        //+vbygR~
                                                                //~v03zI~
//****************************************************************//~v03pI~
int dcmdrename(PUCLIENTWE Ppcw,UCHAR *Pfullpathold,UCHAR *Pnewname,UCHAR *Prealnew);//~v11tR~
                                                                //~v03pI~
//****************************************************************//~v03pI~
#ifdef UNX                                                         //~v19cI~
//int dcmdattrchk(UCHAR *Pattrs,ULONG *Pattron,ULONG *Pattroff);   //~v47CR~
int dcmdattrchk(UCHAR *Pattrs,ULONG *Pattron,ULONG *Pattroff,int Popt);//~v47CI~
#else                                                              //~v19cI~
//int dcmdattrchk(UCHAR *Pattrs,UCHAR *Pattron,UCHAR *Pattroff);   //~v53QR~
int dcmdattrchk(UCHAR *Pattrs,ULONG *Pattron,ULONG *Pattroff);     //~v53QI~
	#ifdef FTPSUPP                                                 //~v59fI~
		int dcmdattrchkunix(UCHAR *Pattrs,ULONG *Pattron,ULONG *Pattroff);//~v59fR~
    #endif                                                         //~v59fI~
#endif                                                             //~v19cI~
#define DCACO_MDOS   0x01    //MDOS                                //~vac2I~
#define DCACO_RWIN   0x02    //ftp remote is windows               //~vac2I~
                                                                //~v03pI~
//****************************************************************//~v03pI~
//#ifdef UNX                                                       //~v53QR~
int dcmdattrchng(UCHAR *Pfullpath,ULONG Pattron,ULONG Pattroff,ULONG *Pattrout);//~v19cI~
//#else                                                            //~v53QR~
//int dcmdattrchng(UCHAR *Pfullpath,UCHAR Pattron,UCHAR Pattroff,UCHAR *Pattrout);//~v53QR~
//#endif                                                           //~v53QR~
#ifndef UNX                                                        //~v59fI~
	#ifdef FTPSUPP                                                 //~v59fI~
		int dcmdattrchngunix(UCHAR *Pfullpath,ULONG Pattron,ULONG Pattroff,ULONG *Pattrout);//~v59fR~
	#endif                                                         //~v59fI~
#endif                                                             //~v59fI~
                                                                   //~v11tI~
//**************************************************************** //~v11tI~
UCHAR *dcmdfullpath(PUCLIENTWE Ppcw,UCHAR *Pfullpath,UCHAR *Pfnm); //~v11tM~
//**************************************************************** //~v70qI~
int dcmdexefullpath(PUCLIENTWE Ppcw,UCHAR *Pfullpath,UCHAR *Pfnm); //~v70qI~
//**************************************************************** //~v646I~
UCHAR *dcmdfullpathwild(int Popt,PUCLIENTWE Ppcw,UCHAR *Pfullpath,UCHAR *Pfnm);//~v646I~
                                                                   //~v11MI~
//**************************************************************** //~v11MI~
#ifdef UNX                                                         //~v20hI~
	int dcmdconfallmemb(char *Poperation,char *Pfullpath);         //~v20hR~
#else  //!UNX                                                      //~v20hI~
int dcmdaster(void);                                               //~v11MM~
#endif //!UNX                                                      //~v20hI~
//**************************************************************** //~v59EI~
#ifdef WXE                                                         //~v59EI~
	int dcmdsyscmdnotify(int Pcmdid,char *Pcmdstrid,char *Pcmdopd);//~v59EI~
#endif                                                             //~v59EI~
//**************************************************************** //~vac2I~
int dcmdattrchng_ftp(int Popt,PUFTPHOST Ppuftph,UCHAR *Pfullpath,ULONG Pattron,ULONG Pattroff,ULONG *Pattrout);//~vac2I~
//**************************************************************** //~van2I~
int dcmdwildconf(int Popt,PUCLIENTWE Ppcw,UCHAR *Pfullpath,PUDIRLH Ppdh);//~van2M~
