//*CID://+vb7jR~:                             update#=  158;       //+vb7jR~
//****************************************************************
//xedir.h
//****************************************************************
//vb7j:170115 (Win)_MAX_PATH is ucsctr,mbcs len is more over       //+vb7jI~
//vb2p:160203 LNX compiler warning                                 //~vb2pI~
//vb2o:160203 try to malloc UDHname for performance(#ifndef MMM)   //~vb2oI~
//vb10:150327 for performance, UDHnameW malloc only when over limit size//~vawmI~
//vawm:140605 (BUG)ddfmt display err at just renameovf occured     //~vawmI~
//vawa:140531 (W32UNICODE:BUG)F11(paste on dirlist) fail to display UD str on rename fld//~vawaI~
//vavd:140421 (Win;BUG of vava) did not nameW for path entry of dirlist//~vavdI~
//vava:140410 (Win)unicode support(UD fmt string)                  //~vavaI~
//vauE:140316 (Win)use ddfmt for dirlist;On cmd-prompt with setcp=65001,f2l dosenot change length but Windows display line shrinked//~vauEI~
//            use ddfmt to set USDfdata                            //~vauEI~
//vauB:140315 (Win)Alt+W/Ctl+W on dirlist;u8 membername on dir list by fnu8 option,but string is treated by lc by env:lc on windows//~vauBI~
//vaui:140311 find on dirlist by ddstrsrch                         //~vauiI~
//vau0:140223 (LNX:BUG)utf8 filename on dirlist,filename locale:de is invalid if f2l on locale=ja_jp//~vau0I~
//            use ddfmt to set USDfdata                            //~vau0I~
//vand:131203 reduce udirlist size. name max is 256,slinkname max=_MAX_PATH=4096 on suse64. change to malloc slinkname.//~vandI~
//van2:131127 support deletion of invalid(wildcard) name entry on dir list//~van2I~
//vamJ:131121 (BUG)"%"/"$" cmd could not cut after cmd end         //~vamJI~
//vaiB:130626 slink err by attrFile                                //~vaiBI~
//vaiz:130624 set slink target not found id to dir list(ftime=fdate=0 by ulib)//~vaizI~
//vaa0:110705 wildcard member display on dirlist,but disallow delete lcmd//~vaa0I~
//va0G:090725!rename fld by codetype                               //~va0GI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          conv descname to locale if utf8                        //~va00I~
//          rename/move.. by filename of the codepage              //~va00I~
//v743:070209*(BUG)rename DBCS 2nd byte is lost when input at boundary to date fled//~v743I~
//v731:061226 filesize>4GB support                                 //~v731I~
//v693:060423 (BUG)when scr resized,remains previous image         //~v693I~
//v692:060418 display expand file-description field(from attr field)//~v692I~
//v690:060418 display file-description support on dir-list panel   //~v690R~
//v58h:040905 (BUG)rename fld by %cmd prevent long filename display//~v58hI~
//v57f:040521 dirlist sort;dlcmd "-" with /ox option:x:Size,t:Time,n:Name//~v57fI~
//v54m:040105 (FTP)update dir list file time when once browsed     //~v54mI~
//v54k:040105 (UNX,FTP)dirlist:display slink attr when expanded bt f11//~v54kI~
//v54e:040104 (UNX,FTP)dirlist:display slink size/ts when expanded bt f11//~v54eI~
//v54a:040102 dirlist; use ts/size field for for long filename     //~v54aI~
//v53Q:031103 ftp support(4 byte udirlist attr for ! UNX);ulib:v59e//~v53QI~
//v47a:020223 (BUG)S+f1(refresh) issue err file not found          //~v47aI~
//             when dirname is expanded by S+f11(long filename display)//~v47aI~
//v44j:011204 display timestamp/size until rename fld filled       //~v44jI~
//v40t:010616 LNX:slink name display                               //~v40tI~
//v20f:001001 LINUX support(uid/gid display on dirlist)            //~v20fI~
//v205:000930 LINUX support(DDATTRSZ expanded to 5 from 4)         //~v205I~
//v19X:000928 LINUX support(save uid/gid on UFILEH/UDIRH)          //~v19XI~
//v19c:000904 LINUX support(attr size,1-->4)                       //~v19cI~
//v190:000902 LINUX support(CRLF)                                  //~v190I~
//v183:001209 long filename display on dirlist;expand to rename fld//~v183I~
//v182:001209 long filename display on dirlist(over attr fld)      //~v182I~
//v137:991003 scroll down when reached to bottom line by field full on dir list//~v137I~
//v10r:990327 display lineno on dir list                           //~v10rI~
//v0fr:971109 dir list sort by fully for longname                  //~v0frI~
//v0fe:971019 (w95/GCC)deney v0fd;copy etc need keep long filename.//~v0feI~
//                     long name and short name is kept.           //~v0feI~
//v0fd:971018 (w95/GCC)udhname is long or short,but only one of them is needed.//~v0fdI~
//v0fa:971017 fatname from udhalias for w95/gcc under no LFN mode  //~v0faR~
//v0f0:971010 long filename support                                //~v0f0I~
//            dir.h     ;maxfilename and maxfilename_fat(display)  //~v0f0I~
//v09i:970517:rename field length 12->14 for quatation             //~v09iI~
//v081:960906:(BUG)free err when storage shortage at dirload       //~v081I~
//v07g:960707:printed msg on dir list                              //~v07gI~
//v05N:960114:add function undo rename/move on dir list         //~v05NI~
//v05I:960107:dir list indentation space -->'|'(lineno attr)    //~v05II~
//v05G:960105:update time stamp of dir list when edit saved(add to v04j)//~v05GI~
//            change interface of dlcgetfullname(plc-->pdh parm)//~v05GI~
//v05u:951202:undelete dlcmd(rename when delete)                //~v05uI~
//v048:950924:dir renum from current line(performance)          //~v048I~
//v046:950923:view dir lcmd                                     //~v046I~
//****************************************************************//~v046I~
#define UDHLINENOSZ2   4                                        //~v048R~
#define UDHLINENOSZ  ( 2+UDHLINENOSZ2)                          //~5820I~
#define UDDMAXLEVEL  (14-UDHLINENOSZ2)  //max dir level         //~5820R~
                                                                   //~v205I~
#ifdef UNX                                                         //~v205I~
	#define UDDATTRSZ      5             //nnnst attr field sz     //~v205I~
#else  //!UNX                                                      //~v205I~
#define UDDATTRSZ      4                //attr field sz         //~5906I~
#endif //!UNX                                                      //~v205I~
#define UDDATTRSZMAX      5               //for ftp                //~v53QI~
                                                                   //~v205I~
//*DATA TYPE *******************************
//** line data ctl ****************************************
typedef struct _UDIRLH {
                        UCHAR  UDHcbid[4];      //acronym
#define UDHCBID         "UDH"                  //acronym
//                	  	UCHAR  UDHname[MAXFILENAME+1];             //~v0f0R~
#ifdef MMM                                                         //~vb2oI~
                  	  	UCHAR  UDHname[MAXFILENAMEZ];              //~v0fdR~
#else //MMM                                                        //~vb2oI~
//#ifdef W32	                                                   //+vb7jR~
//  #define UDHNAME_MAXSZ (MAXFILENAMEZ+3) //for UD string         //+vb7jR~
//#else                                                            //+vb7jR~
	#define UDHNAME_MAXSZ (MAXFILENAMEZ)                           //~vb2oI~
//#endif                                                           //+vb7jR~
                        int    UDHnamebuffsz;  //strlen of UDHname //~vb2oR~
                  	  	UCHAR *UDHname;                            //~vb2oI~
#endif                                                             //~vb2oI~
#if defined(W32) || defined(DPMI)                                  //~v0feI~
                  	  	UCHAR  UDHalias[MAXFILENAMEZ_FAT];         //~v0feI~
    #define UDHALIAS    UDHalias                                   //~v0feI~
#else                                                              //~v0feI~
    #define UDHALIAS    UDHname     //no alias fld,use udhname     //~v0feI~
#endif                                                             //~v0feI~
#ifdef UNX                                                         //~v19cI~
                        uid_t  UDHuid    ;     //userid            //~v19XR~
                        gid_t  UDHgid    ;     //groupid           //~v19XR~
//                      char  *UDHuname;        //username         //~v54mR~
//                      char  *UDHgname;        //groupname        //~v54mR~
                        char   UDHuname[MAXUNAMESZ+1];             //~v54mI~
                        char   UDHgname[MAXGNAMESZ+1];             //~v54mR~
#ifdef UTF8SUPPH                                                   //~va00I~
                        UCHAR *UDHslink;        //slink name       //~va00I~
#else                                                              //~va00I~
                        char  *UDHslink;        //slink name       //~v40tI~
#endif                                                             //~va00I~
	                    ULONG  UDHattr;                            //~v19cI~
                        dev_t  UDHfsid   ;     //file system id    //~v19XR~
//                      UCHAR  UDHrsvunx[3];                       //~vaa0R~
	#ifdef UNX                                                     //~vaa0I~
                        ino_t  UDHinode   ;    //inode no          //~vaa0M~
	#endif                                                         //~vaa0M~
#else                                                              //~v19cI~
	#ifdef FTPSUPP                                                 //~v54eI~
//                      char  *UDHuname;        //username         //~v54mR~
//                      char  *UDHgname;        //groupname        //~v54mR~
                        char   UDHuname[MAXUNAMESZ+1];             //~v54mI~
                        char   UDHgname[MAXGNAMESZ+1];             //~v54mR~
                        char  *UDHslink;        //slink name       //~v54eI~
	#endif                                                         //~v54eI~
//                      UCHAR  UDHattr;                            //~v53QR~
	                    ULONG  UDHattr;    //4byte attr for ftp support//~v53QI~
#ifdef W32                                                         //~van2M~
    #define UDH_IS_WILDNAMEOK(pdh) (FILE_IS_WILDNAME(pdh->UDHattr))//~van2M~
#endif                                                             //~van2M~
#endif                                                             //~v19cI~
#ifdef FTPSUPP                                                     //~v54eI~
		                FTIME  UDHslinktime;                       //~v54eR~
	                  	FDATE  UDHslinkdate;                       //~v54eR~
//                	  	ULONG  UDHslinksize; //slink size          //~v731R~
                  	  	FILESZT UDHslinksize; //slink size         //~v731I~
//                                            current line count fot SPF file//~v693I~
	              	  	ULONG  UDHslinkattr; //slink attr          //~v54kI~
                        char  *UDHslinkuname;        //slink username//~v54eI~
                        char  *UDHslinkgname;        //slink groupname//~v54eI~
#endif                                                             //~v54eI~
						UCHAR  UDHtype;
#define UDHTDIR     	'+'  		//sub dir                   //~5812I~
#define UDHTDIREXP      '-'  		//expanded dir              //~5812I~
#define UDHTDIREXPMASK  '='  		//temporaly status(init mask expand)//~5812I~
#define UDHTPARENT      ':'  		//parent dir(..)            //~5812R~
#define UDHTFILE    	'.'  		//not dir                   //~v05IR~
						UCHAR  UDHflag;
#define UDHFDDSETUP 	0x80 		//dir data line setup end
#define UDHFLCMDIN1 	0x40 		//attr lcmd
#define UDHFLCMDIN2 	0x20 		//new name lcmd
#define UDHFAPPCMDSTR   0x10 		//rename fld is by % lcmd executed//~v58hI~
#define UDHFEXCLUDED  	0x08 		//dir expanded              //~5806I~
#define UDHFMASK    	0x04 		//dir file mask req         //~5807I~
#define UDHFMASK2   	0x02 		//on undel confirm pending  //~v05uI~
#define UDHFPRINTED 	0x01 		//printed                      //~v07gI~
						UCHAR  UDHlevel;                        //~5813R~
						UCHAR  UDHflag2;                           //~v10rR~
#define UDHF2DISPLC  	0x01 		//display file size by line count//~v10rI~
#define UDHF2LCGOTTEN	0x02 		//line size gotten             //~v10rR~
#define UDHF2SETATTR	0x04 		//UDDattr field setuped        //~v183I~
#define UDHF2SETRENAME  0x08 		//UDDrname field setupped      //~v183I~
#define UDHF2RENAMEOVF  0x10 		//keyin rename fld overflow to timestamp fld//~v44jI~
#define UDHF2MASKNAME   0x20 		//UDHrenamesv is dir mask      //~v47aI~
#define UDHF2SETTSSZ	0x40 		//UDDdate/time/size field setupped//~v54aI~
#define UDHF2REFRESH	0x80 		//refresh requested            //~v690I~
						UCHAR  UDHflag3;                           //~v692I~
#define UDHF3SETDESC 	0x01 		//file description displayed   //~v692I~
#define UDHF3RESIZE  	0x02 		//re-setup reason:resize       //~v693I~
                                                                   //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
                                                                   //~va00I~
#define UDHF3U8SET   	0x04 		//encoding chked               //~va00R~
#define UDHF3U8LC    	0x08 		//filename is by localecode    //~va00I~
#define UDHF3U8UTF      0x10 		//filename is by utf8          //~va00R~
#define UDHF3U8LCSL  	0x20 		//slink filename is by localecode//~va00R~
#define UDHF3U8UTFSL    0x40 		//slink filename is by utf8    //~va00R~
#define UDHF3DESCATTR   0x80 		//draw desc field by lineno attr//~va00R~
                                                                   //~va00I~
#endif  //UTF8SUPPH                                                //~va00I~
//  					UCHAR  UDHrsv2;                            //~v57fR~
    					UCHAR  UDHsortopt;  //sort sequence        //~v57fR~
#define UDHSONAME   	0    		//name seq                     //~v57fR~
#define UDHSOTIME   	'T'  		//date/time+name seq           //~v57fR~
#define UDHSOSIZE   	'Z'  		//size+name seq                //~v57fR~
#define UDHSOREVERSE	0x80 		//discending order             //~v57fI~
						UCHAR  UDHerrfldno; //highlight fld no  //~5826I~
						UCHAR  UDHupdatetype;
#define UDHUTRENAMEO	0x80 		//rename origin
#define UDHUTRENAMET	0x08 		//rename target
#define UDHUTCOPYO 		0x40 		//copy origin
#define UDHUTCOPYT 		0x04 		//copy target
#define UDHUTMOVEO 		0x20 		//move origin
#define UDHUTMOVET 		0x02 		//move target
#define UDHUTDELETED	0x10 		//deleted
#define UDHUTMOVEOCHILD 0x01 		//moved child               //~v05NI~
#define UDHUTNOTEXIST   (UDHUTRENAMEO|UDHUTMOVEO|UDHUTDELETED)  //~5903R~
#ifdef UTF8SUPPH                                                   //~va00I~
						UCHAR  UDHflag4;                           //~va00I~
//#define UDHF4RENAMEU8   0x01 		//renamesv by utf8             //~va00I~//~va0GR~
#define UDHF4APPCMD       0x01 		//renamesv by appcmd(#)        //~vamJI~
#define UDHF4APPCMDASYNC  0x02 		//renamesv by appcmdAsync($)   //~vamJI~
//#ifdef LNX                                                         //~vau0I~//~vauER~
	#define UDHF4RENAMEU8 0x04      //rename field contains utf8   //~vau0I~
	#define UDHF4RENAMELC 0x08      //rename field contains utf8   //~vau0I~
	#define UDHF4NOTSETDD 0x10      //ddsetup bypassed             //~vau0R~
	#define UDHF4DDFMT    0x20      //ddfmt line                   //~vau0R~
	#define UDHF4DESCU8   0x40      //                             //~vau0I~
	#define UDHF4DESCLC   0x80      //                             //~vau0I~
//#endif                                                             //~vau0I~//~vauER~
//  					UCHAR  UDHrsv3[3];                         //~va00I~//~vavaR~
						UCHAR  UDHflag5;                           //~vavaI~
#ifdef W32UNICODE                                                  //~vavaI~
	#define UDHF5SUBCHFNAME   0x01  //UDHnamef2l contains subchar  //~vavaI~
	#define UDHF5SUBCHSLINK   0x02  //slinkname  contains subchar  //~vavaI~
#endif                                                             //~vavaI~
	#define UDHF5SETRENAMEDD  0x04  //renameddfmt was updated      //~vawaM~
	#define UDHF5CHNGRNOVF    0x08  //char input changed rename fld overflow status,do drawrenameDDFMT//~vawmR~
	#define UDHF5PASTERENAME  0x10  //rename fld pasted;draw by UDHrename_utf8/UDHrename_codetype//~vawmI~
    					UCHAR  UDHrsv3[2];                         //~vavaI~
#endif                                                             //~va00I~
              struct    _UDIRLH *UDHotptr; //origin/target ptr(copy/rename)//~5806R~
              struct    _UDIRLH *UDHdirptr;//ptr to included dir line//~5806I~
		                FTIME  UDHtime;
	                  	FDATE  UDHdate;
//                	  	ULONG  UDHsize;                            //~v731R~
                  	  	FILESZT UDHsize;                           //~v731I~
						UCHAR *UDHrenamesv;//name save area ptr //~5903R~
#ifdef UTF8SUPPH                                                   //~va00I~
#ifdef MMM                                                         //~vb2oI~
#else                                                              //~vb2oI~
						int    UDHnamef2lstrlen;//strlen           //~vb2oR~
#endif                                                             //~vb2oI~
						UCHAR *UDHnamef2l;//locale code of utf8 filename//~va00R~
						UCHAR *UDHrename_codetype;                 //~va0GR~
						UCHAR *UDHrename_utf8;                     //~va0GI~
    #define UDHRENAME_CODETYPESZ UDDRNAMESZ //max rename fld sz    //~va0GI~
    #define UDHRENAME_UTF8SZ     ((UDDRNAMESZ*UTF8_MAXCHARSZ)+1)   //~va0GI~
						UCHAR *UDHrenamesvbyutf8;//input by utf8   //~va00R~
//  #define PDH_UDHrenamesv(pdh) /*get string in renamesv LC or UTF8*///~va0GR~
//          (UCBITCHK(pdh->UDHflag4,UDHF4RENAMEU8)? pdh->UDHrenamesvbyutf8 : pdh->UDHrenamesv)//~va00I~//~va0GR~
    #define PDH_UDHrenamesv(pdh) /*get string in renamesv LC or UTF8*/ pdh->UDHrenamesvbyutf8//~va0GI~
    #define PDH_UDHname(pdh) /*get string to display memb name, LC or UTF8*/\
            ((pdh->UDHnamef2l)? pdh->UDHnamef2l : pdh->UDHname)    //~va00I~
    #define PDH_UDHnamestrsrchlen(pdh) /*get buffsz for ustrnstr*/\
            ((pdh->UDHnamef2l)? pdh->UDHnamef2lstrlen : pdh->UDHnamebuffsz)//~vb2oI~
#else                                                              //~va00I~
    #define PDH_UDHrenamesv(pdh) pdh->UDHrenamesv                  //~va00R~
    #define PDH_UDHname(pdh) pdh->UDHname                          //~va00R~
#endif                                                             //~va00I~
                        UQUEH  UDHviewqh;	//view lcmd q hdr   //~v046I~
						int    UDHdesclen;  //file description strlen//~v690R~
						UCHAR *UDHpdesc;    //file description     //~v690R~
						int    UDHnameoffs; //offset on UDIRLD     //~vauiM~
						int    UDHslinkoffs; //offset on UDIRLD    //~vauiM~
						int    UDHfnmlen;   //fnm(+sllink)len in UDHfnmwidth//~vauiI~
						int    UDHfnmwidth; //fnm available fld width//~vauiM~
//#ifdef LNX                                                         //~vau0R~//~vauER~
						UCHAR *UDHnameddfmt;    //membername by ddfmt dddata+dddbcs(no codetable)//~vau0R~
						int    UDHnameddfmtlen;                    //~vau0R~
						UCHAR *UDHslinkddfmt;    //slinkname by ddfmt//~vau0R~
						int    UDHslinkddfmtlen;                   //~vau0R~
						UCHAR *UDHrenameddfmt;                     //~vau0I~
						int    UDHrenameddfmtlen;                  //~vau0I~
						int    UDHrenameoffs; //offset on UDIRLD   //~vau0I~
//#else                                                              //~vauBI~//~vauER~
//                        int    UDHslinknameu8len; //UDHslink is replace by localecode name,keep orignal u8 code//~vauBR~//~vauER~
//                        char  *UDHslinknameu8;    //slink name strlen//~vauBR~//~vauER~
//#endif                                                             //~vau0R~//~vauER~
#ifdef W32UNICODE                                                  //~vauEI~//~vavaI~
                        int    UDHnameWctr;                        //~vauER~//~vavaI~
						UWCH  *UDHnameW;                           //~vauEI~//~vavaI~
#define UDHNAMEWSHORT_MAXCTR   15                                  //~vb10R~
                        UWCH   UDHnameWshort[UDHNAMEWSHORT_MAXCTR+1];//~vb10R~
#endif                                                             //~vauEI~//~vavaI~
					  	} UDIRLH;
typedef UDIRLH *PUDIRLH;
#define UDIRLHSZ (sizeof(UDIRLH))
//#ifdef AIX                                             a            //~vaizM~//~vaiBR~
//    #define XEDIR_PDHSLINKERR(pdh) \                   a         //~vaiBR~
//        (   (pdh)->UDHslink\                           a         //~vaiBR~
//            && !((pdh)->UDHslinksize)\                 a         //~vaiBR~
//            && !((pdh)->UDHslinkattr)\                 a         //~vaiBR~
//            && !*((int*)(&((pdh)->UDHdate)))\          a         //~vaiBR~
//            && !*((int*)(&((pdh)->UDHtime)))\          a         //~vaiBR~
//        )                                              a             //~vaizI~//~vaiBR~
//#else                                                  a            //~vaizR~//~vaiBR~
//    #define XEDIR_PDHSLINKERR(pdh) \                   a         //~vaiBR~
//        (   (pdh)->UDHslink\                           a         //~vaiBR~
//            && !((pdh)->UDHslinksize)\                 a         //~vaiBR~
//            && !((pdh)->UDHslinkattr)\                 a         //~vaiBR~
//            && !*((USHORT*)(&((pdh)->UDHslinkdate)))\  a         //~vaiBR~
//            && !*((USHORT*)(&((pdh)->UDHslinktime)))\  a         //~vaiBR~
//        )                                              a            //~vaizR~//~vaiBR~
//#endif                                                 a            //~vaizI~//~vaiBR~
#if defined(W32) || defined(UNX)                                   //~vaiBI~
	#define XEDIR_PDHSLINKERR(pdh) \
		(IS_SLINKERR((pdh)->UDHattr))	//SLINK and SLINKERR       //~vaiBI~
#endif                                                             //~vaiBI~
//#define UDH_SET_SLINKNAME(pdh,pslinkname)                        //~vandR~
//        ( ((PUDIRLH)(pdh))->slink=umalloc((pslinkname)?strlen(pslinkname):0)+1),//~vandR~
//           (pslinkname)?strcpy( ((PUDIRLH)(pdh))->slink,pslinkname)//~vandR~
//                       :*((PUDIRLH)(pdh))->slink=0)              //~vandR~
//        )                                                        //~vandR~
//** line data ctl ****************************************
typedef struct _UDIRLD {
                        UCHAR  UDDlvl[UDDMAXLEVEL+2];      //dir level//~5819R~
//                      UCHAR  UDDname[MAXFILENAME];     //file name//~v0f0R~
                        UCHAR  UDDname[MAXFILENAMEZ_FAT-1];     //file name//~v0f0I~
						UCHAR  UDDattrflag;                     //~5906R~
                        UCHAR  UDDattr[UDDATTRSZ];     	//attr  //~5906R~
#ifdef UNX                                                         //~v205I~
#else  //!UNX                                                      //~v205I~
						UCHAR  UDDattrflag2;                    //~5909I~
#endif //!UNX                                                      //~v205I~
                                                                   //~v182I~
#define  UDDLFNSZ (offsetof(UDIRLD,UDDrsv2)-offsetof(UDIRLD,UDDname[0]))	//long filename fld sz//~v182I~
                                                                   //~v205I~
						UCHAR  UDDrsv2;                         //~5909R~
//                      UCHAR  UDDrname[MAXFILENAME];    //rename  //~v09iR~
//                      UCHAR  UDDrname[PANL310MASKLEN];    //rename//~v09iR~
//                      UCHAR  UDDrname[MAXFILENAME+2];    //rename//~v0f0R~
                        UCHAR  UDDrname[MAXFILENAMEZ_FAT+1];    //rename//~v0f0R~
//#define  UDDLFNSZ2 (offsetof(UDIRLD,UDDrsv3[0])-offsetof(UDIRLD,UDDname[0]))	//longlong filename fld sz//~v183I~//~vb2pR~
#define  UDDLFNSZ2 ((int)(offsetof(UDIRLD,UDDrsv3[0])-offsetof(UDIRLD,UDDname[0])))	//longlong filename fld sz//~vb2pI~
//#define  UDDOFFS_RSV3 (offsetof(UDIRLD,UDDrsv3[0]))	//longlong filename fld sz//~v743I~//~vb2pR~
#define  UDDOFFS_RSV3 ((int)(offsetof(UDIRLD,UDDrsv3[0])))	//longlong filename fld sz//~vb2pI~
//  					UCHAR  UDDrsv3[2];                         //~v09iR~
    					UCHAR  UDDrsv3[1];                         //~v09iI~
                        UCHAR  UDDdate[8];     	//date
//  					UCHAR  UDDrsv4[2];                         //~v09iR~
						UCHAR  UDDrsv4[1];                         //~v09iI~
                        UCHAR  UDDtime[5];     	//time
                        UCHAR  UDDsize[13];    	//size
					  	} UDIRLD;
//#define  UDDLFNSZ3 (sizeof(UDIRLD)-offsetof(UDIRLD,UDDname[0]))	//longlong filename fld sz//~v54aI~//~vb2pR~
#define  UDDLFNSZ3 ((int)(sizeof(UDIRLD)-offsetof(UDIRLD,UDDname[0])))	//longlong filename fld sz//~vb2pI~
typedef UDIRLD *PUDIRLD;
//#define UDIRLDSZ (sizeof(UDIRLD))                                //~vb2pR~
#define UDIRLDSZ ((int)(sizeof(UDIRLD)))                           //~vb2pI~
//#define UDDTSSZ   (UDIRLDSZ-offsetof(UDIRLD,UDDdate[0]))           //~v44jI~//~vb2pR~
#define UDDTSSZ   (UDIRLDSZ-(int)offsetof(UDIRLD,UDDdate[0]))      //~vb2pI~
//#define UDDDESCSZ  (UDIRLDSZ-offsetof(UDIRLD,UDDrname[0]))   //fill description from rename field//~v692R~
//#define UDDRNAMESZ (UDIRLDSZ-offsetof(UDIRLD,UDDrname[0]))   //fill description from rename field//~va0GI~//~vb2pR~
#define UDDRNAMESZ (UDIRLDSZ-(int)offsetof(UDIRLD,UDDrname[0]))   //fill description from rename field//~vb2pI~
//#define UDDDESCSZ  (UDIRLDSZ-offsetof(UDIRLD,UDDattr[0]))   //fill description from rename field//~v692I~//~vb2pR~
#define UDDDESCSZ  (UDIRLDSZ-(int)offsetof(UDIRLD,UDDattr[0]))   //fill description from rename field//~vb2pR~

//****************************************************************
//*get pdh addr from plh
#define UGETPDH(plh)       \
       ((PUDIRLH)(PVOID)((UCHAR*)(PVOID)(PULINEH)(plh)+ULINEHSZ))//~5806R~
#define UGETPDD(plh)       \
       ((PUDIRLD)(PVOID)plh->ULHdata)                           //~5807I~
//*get plh addr from pdh                                        //~5806I~
#define UGETDIRPLH(pdh)       \
       ((PULINEH)(PVOID)((UCHAR*)(PVOID)(PUDIRLH)(pdh)-ULINEHSZ))//~5806I~

//****************************************************************
int dirload(PUCLIENTWE Ppcw,PUFILEH Ppfh);
//****************************************************************//~5731I~
PULINEH dirsetdata(int Plevel,PUDIRLIST Ppudirlist,PUFILEH Ppfh);  //~v0fdI~
//****************************************************************//~5819I~
void dirsetdatasub(PUDIRLH Ppdh,PUDIRLIST Ppudirlist);          //~5819R~
//****************************************************************//~v05GI~
void dirsetdatasub2(PUDIRLH Ppdh,FILEFINDBUF3 *Ppfstat3);       //~v05GI~
//****************************************************************//~5806I~
int dirgetlist(PUFILEH Ppfh,UCHAR *Pfilemask,UINT Popt,PUDIRLIST *Pppudirlist);//~v0frR~
#define DGLO_SORTOPT  0xff00    //sort option mask                 //~v57fR~
//****************************************************************//~5806I~
void dirfreeplh(PULINEH Pplh);                                  //~5806I~
//****************************************************************//~5820I~
void dirrenum(PULINEH Pplh);                                    //~v048R~
//**************************************************************** //~v081I~
int dirclosefree2(PUFILEH Ppfh);                                   //~v081I~
//**************************************************************** //~v137I~
int dirnexttab(PUCLIENTWE Ppcw);                                   //~v137R~
#ifdef FTPSUPP                                                     //~v54mI~
//**************************************************************** //~v54mI~
void dirresetftpfiletime(PUDIRLH Ppdh,PUFILEH Ppfh);               //~v54mI~
#endif                                                             //~v54mI~
//**************************************************************** //~vavdI~
int dirgetfstat(int Popt,PUFILEH Ppfh,UCHAR *Ppathname,int Plevel,PUDIRLIST Ppudirlist);//~vavdI~
#define DGFSO_PATH    0x01     //fstat for intermediate path       //~vavdI~
//**************************************************************** //~vb2oI~
#ifdef MMM                                                         //~vb2oI~
#else                                                              //~vb2oI~
int dirupdatename(int Popt,PUDIRLH Ppdh,char *Psrc,int Psrclen);   //~vb2oR~
#define DUNO_ALLOCNEW  0x01   //alloacte new area even if new string is short//~vb2oI~
#define DUNO_MEMSET    0x02   //null clear existing buff           //~vb2oI~
#endif                                                             //~vb2oI~
