//*CID://+vbE4R~:                             update#=   51;       //+vbE4R~
//******************************************************        //~5B11I~
//*ufile4.h                                                        //~v050R~
//******************************************************        //~5B11I~
//vbE4:250921 (LNX)update UFSINFO(mountpoint) by S+F1(refresh)     //+vbE4I~
//vbE2:250918 (LNX)dirlist, display free rate for mount point      //~vbE2I~
//vat8:241025 xdig:support multiple dirmask                        //~vat8I~
//vat5:241023 xdig:add option to apply dirmask once and all        //~vat5I~
//v6Vx:180626 (LNX:BUG)trace file is not protected at xe initial clear//~v6VxI~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6x0:150105 BUG:offset value is long long for fseek error msg    //~v6x0I~
//v6w1:141122 (Axe:BUG)ufile4 compile err. fsid_t was changed fro ndkr7 to ndkr9//~v6w1I~
//            ndkr7:vfs.h-statfs:__kernel_fsid_t, ndkr9d:vfs.h-statfs:__fsid_t, ufile4.h-UDISKINFO:__kernel_fsid_t//~v6w1I~
//v6uV:140608 support isvfat,isntfs for LNX                        //~v6uVI~
//v6q1:131128 (WIN)for wildname dir,use alias to get dirlist       //~v6q1I~
//v6kq:130705 no need to outoflink chk for junction and moutpoint  //~v6kqI~
//v6kp:130704 (BUG)relative slink is outof link err when copy to same dir//~v6kpI~
//v6kf:130627 warning relative link may lose to linkage after copy //~v6kfI~
//v6k4:130610 (Win)Jnction(from xp) and Symlink(from Vista)        //~v6k4I~
//            ufile4.c/h slink loop chk                            //~v6k4I~
//v6a0:110520 Android porting(-DARM)                               //~v6a0R~
//v5nu:081107 (Win)\\x\y remote filename support                   //~v5nuI~
//v5nh:081020 lockfile support so SOnn                             //~v5nhI~
//v5i0:060419 add ufileisntfs                                      //~v5b0I~
//v5b0:040115 (LNX:BUG)mkstmp is for file only,mkdtmp is required for temp dir//~v5b0I~
//v578:021207 udirlist performance tuning(stat call on the current dir)//~v578I~
//v56A:020809 (BUG)S-link loop chk;for the case slinked to looped path(over update#0)//~v56AR~
//v56t:020712 (UNX)udirwalk slink skip option                      //~v56tI~
//v56m:020711 udirwalk;option to skip dir by rc=-5 from user func  //~v56mI~
//v528:020217 option to apply mask 1st level only for xds          //~v528I~
//v424:010101 TLinux:f_fsid is not type name but fld name          //~v424I~
//v348:000926 LINUX support(ugetdiskfree now returns file system id additionaly)//~v348I~
//v327 000820:LINUX support                                        //~v327I~
//v202:981101 udirwalk:end of list call support for uds(dir size calc)//~v202I~
//v120:971116 (BUG:GCC)when env var LFN changed N to Y,it is needed to force//~v120I~
//                     call _get_volume_info at _use_lfn.          //~v120I~
//                     new option to ufileisvfat                   //~v120I~
//v101:971009 long filename                                        //~v101I~
//            ufile4.c/h:add ufileishpfs(return file system id)    //~v101I~
//                       ufilevfat for DOS/W95                     //~v101I~
//v083:970508 add ugetdiskfree                                     //~v083I~
//v063:970210:udirwalk function add                                //~v063I~
//v050:961201:add utempnam                                         //~v050I~
//**************************************************************** //~v083I~
typedef  struct _UDISKINFO {                                       //~v083R~
//      unsigned total_clusters;                                   //~v083R~//~v6D0R~
        FILESZT  total_clusters;                                   //~v6D0R~
//      unsigned avail_clusters;                                   //~v083I~//~v6D0R~
        FILESZT  avail_clusters;                                   //~v6D0R~
        unsigned sectors_per_cluster;                              //~v083I~
        unsigned bytes_per_sector;                                 //~v083I~
#ifdef UNX                                                         //~v348I~
//      f_fsid   filesystemid;                                     //~v424R~
	#ifdef ARM                                                     //~v6a0R~
//  	__kernel_fsid_t  filesystemid;                             //~v6w1R~
    	__fsid_t  filesystemid;                                    //~v6w1I~
    #else                                                          //~v6a0R~
        fsid_t   filesystemid;                                     //~v424I~
	#endif                                                         //~v6a0R~
#endif                                                             //~v348I~
        } UDISKINFO;                                               //~v083R~
//***                                                              //~vbE2I~
#ifdef LNX                                                         //~vbE2I~
typedef struct _UFSINFO {                                          //~vbE2I~
				char filesystem[64];                               //~vbE2I~
                char mountpoint[64];                               //~vbE2I~
                long size;                                         //~vbE2I~
                long used;                                         //~vbE2I~
                long avail;                                        //~vbE2I~
                int  usedRateM10;                                  //~vbE2I~
                int  availRateM10;                                 //~vbE2I~
            } UFSINFO,*PUFSINFO;                                   //~vbE2I~
#define UFSINFOSZ (UINT)sizeof(UFSINFO)                            //~vbE2I~
#endif                                                             //~vbE2I~
//**************************************************************** //~v050I~
char *utempnam(char *Pdir,char *Pprefix,char *Ptempfile);          //~v050I~
//**************************************************************** //~v5b0I~
char *utempnamd(char *Pdir,char *Pprefix,char *Ptempfile);         //~v5b0I~
//**************************************************************** //~v050I~
//long  ufgetpos(FILE *Pfh);                                       //~v6x0R~
FILESZT ufgetpos(FILE *Pfh);                                       //~v6x0I~
//**********************************************************************//~v063I~
int  udirwalk(int Popt,char *Pstartdir,char *Pdirmask,char *Pfilemask,//~v063I~
                int Pattrmask,int Pstopdepth,                      //~v063I~
               int (*Pfunc)(char *Pdir,char *Pfullpath,UDIRLIST *Pudirlist,//~v063I~
                            int Pdepth,void *Pdata,int *Papplrc),  //~v063I~
               void *Pfuncdata,int *Prc);                          //~v063I~
//*                                                                //~v063I~
#define UDIRWALK_FILECALL       0x0100                             //~v063I~
#define UDIRWALK_DIRCALL        0x0200                             //~v063I~
#define UDIRWALK_NOMSG          0x0400  //no err msg               //~v063I~
#define UDIRWALK_EMPTYCALL      0x0800  //call if empty even if file call only//~v063I~
#define UDIRWALK_SORT_REV       0x1000  //reverse sort sw          //~v063I~
#define UDIRWALK_CD             0x2000  //change dir               //~v063I~
#define UDIRWALK_EOLCALL        0x4000  //end of list entry req    //~v202I~
#define UDIRWALK_TOPMASK        0x8000  //apply mask to top level only//~v528I~
//#ifdef UNX                                                         //~v56tI~//~v6k4R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~
#define UDIRWALK_SKIPSLINK    0x010000  //skip slink               //~v56tI~
#endif                                                             //~v6k4I~
#ifdef UNX                                                         //~v6k4I~
#define UDIRWALK_TEMPCD       0x020000  //cd for udirlist performance up//~v578I~
#endif                                                             //~v56tI~
#if defined(W32)||defined(UNX)                                     //~v6k4I~
#define UDIRWALK_LISTSLINKERR 0x040000  //list also slink err(without step down into the dir)//~v6k4I~
#endif                                                             //~v6k4I~
#define UDIRWALK_DIGBYALIAS   0x080000  //for wildname dir dig by alias//~v6q1I~
#define UDIRWALK_DIRMASK_PATH 0x100000  //search all sub dir       //~vat5R~
#define UDIRWALK_DIRMASK_ONLY 0x200000  //apply to the dir only    //~vat5R~
#define UDIRWALK_DIRMASK_MULT  0x00400000  //dirmask is multiple   //~vat8R~
#define UDIRWALK_FILEMASK_MULT 0x00800000  //filemask is multiple  //~vat8R~
                                                                   //~v56tI~
#define UDIRWALK_SORT_MASK      0x00ff  //sort order mask          //~v063I~
#define UDIRWALK_SORT_NAME         'N'  //name seq                 //~v063I~
#define UDIRWALK_SORT_EXT          'E'  //extention                //~v063I~
#define UDIRWALK_SORT_DATE         'D'  //time stamp               //~v063I~
#define UDIRWALK_RC_EMPTY   1   //no matching file                 //~v063I~
#define UDIRWALK_RC_NAME    4   //dir name err                     //~v063I~
#define UDIRWALK_RC_NOTF    8   //not found                        //~v063I~
#define UDIRWALK_RC_NOTDIR 12   //not dir                          //~v063I~
                                                                   //~v56mI~
#define UDIRWALK_URC_SKIPDIR  -2 //user requested skip this dir    //~v56mI~
//*                                                                //~v063I~
//*******************************************************          //~v083I~
//#ifdef UNX                                                         //~v327I~//~v6k4R~
#if defined(W32)||defined(UNX)                                     //~v6k4I~
//int ufileslinkchk(char *Pdir,char *Pmember,char *Pslink);          //~v56AR~//~v6k4R~
int ufileslinkloopchk(int Popt,char *Pdir,char *Pmember,char *Pslink);//~v6k4I~
#define UFSLCO_NODUPMSG    0x01 //bypass to issue duplicated err msg//~v6k4I~
//int ufileslinkchk2(char *Pstartdir,char *Pdir,char *Pmember,char *Pslink);//~v6k4R~
int ufileslinkloopchk2(int Popt,char *Pstartdir,char *Pdir,char *Pmember,char *Pslink);//~v6k4R~
unsigned int ugetdiskfree(char *Pfname,UDISKINFO *Pudiskinfo);     //~v327I~
#else                                                              //~v327I~
//unsigned int ugetdiskfree(char Pdletter,UDISKINFO *Pudiskinfo);    //~v083R~//~v5nuR~
unsigned int ugetdiskfree(char *Pfname,UDISKINFO *Pudiskinfo);     //~v5nuI~
#endif                                                             //~v327I~
                                                                   //~v101I~
#ifdef OS2                                                         //~v101I~
//*******************************************************          //~v101I~
int ufileishpfs(char Pdletter);                                    //~v101R~
#else                                                              //~v101I~
//*******************************************************          //~v101I~
int ufileisvfat(int Popt);                                         //~v120R~
#define ISVFAT_ERRMSG   0x01    //errmsg if not vfat               //~v120I~
#define ISVFAT_FORCE    0x02    //force get_volume_info to _use_lfn//~v120I~
#endif                                                             //~v101I~
                                                                   //~v5b0I~
int ufileisntfs(int Pdriveletter);                                 //~v5b0I~
//*******************************************************          //~v5nhI~
int ufsetlock(int Popt,char *Plockfnm);                            //~v5nhI~
#define UFSLO_LOCK        0x01                                     //~v5nhI~
#define UFSLO_UNLOCK      0x02                                     //~v5nhI~
//*******************************************************          //~v6VxI~
int uflock(int Popt,char *Pfnm,int *Ppfd);                         //~v6VxR~
#define  UFLO_LOCK        0x01    //enlock                         //~v6VxI~
#define  UFLO_CLOSE       0x02    //close fd                       //~v6VxI~
//*******************************************************          //~v6kfI~
#if defined(W32)||defined(UNX)                                     //~v6kfI~
//int ufileslinkoutoflinkchk(int Popt,char *Pstartdir,char *Pfnm,char *Pslink);//~v6kpR~
//int ufileslinkoutoflinkchk(int Popt,char *Pstartdir,char *Pfnm,char *Pslink,char *Pdest);//~v6kqR~
int ufileslinkoutoflinkchk(int Popt,char *Pstartdir,char *Pfnm,char *Pslink,char *Pdest,UINT Psattr);//~v6kqI~
#endif                                                             //~v6kfI~
#ifdef LNX                                                         //~v6uVI~
int ufileisvfatMounted(int Popt,char *Pfnm);                       //~v6uVI~
int ufileisntfsMounted(int Popt,char *Pfnm);                       //~v6uVR~
int ufileisMSMounted(int Popt,char *Pfnm);                         //~v6uVR~
#endif                                                             //~v6uVI~
char *multipleMask(char *Pstrs,int *Ppctr);                        //~vat8I~
int  udirwalkChkMask(int Popt,char *Pname,char *Pmask);            //~vat8R~
#ifdef LNX                                                         //~vbE2I~
UFSINFO* ugetfsinfoDF();                                           //~vbE2I~
UFSINFO* usrchfsinfoDF(char *Ppath);                               //~vbE2R~
void urefreshFsinfoDF();                                           //+vbE4I~
#endif                                                             //~vbE2I~
