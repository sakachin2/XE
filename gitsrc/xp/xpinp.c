//*CID://+v9a1R~:                             update#=  185;       //+v9a1R~
//***********************************************************
//* xpinp.c                                                     //~v74pR~
//***********************************************************
//v9a1:160418 v9.33 LNX64 Compiler warning                         //+v9a1I~
//v990:140506 v9.30 (W32UNICODE) filename by UD fmt                //~v990I~
//v97v:131114 (BUG)-nl(no crlf) was ignored(it is default for R/V). it CRLF should be unprintable for R/V.//~v97vI~
//v97m:131104 (gxp)header print err for utf8 filename;chk utf8 encoding for filename//~v97mI~
//v978:131026 compiler warninig "type-punned pointer"              //~v978I~
//v96i:130726 v9.25 add -EOLPRINT: option to identify eol of vfmt  //~v96iI~
//v96e:130724 v9.25 recfm=V(-Vvfmt) support                        //~v96eI~
//v96d:130618 v9.24 findnext required dirname by ulib:v64k(win symlink support)//~v96dI~
//120705 v96b warning on suse64                                    //~v96bI~
//120629 v968 VC2010:LP64 support                                  //~v968I~
//120616 v967 for VC6:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~v967I~
//120613 v966 warning(variable may not be uninitialized) on FC12   //~v966I~
//120611 v965 avoid C4701 warning(variable may not be uninitialized)//~v965I~
//100923 v956 v9.20 (BUG) "too long line" err msg when from xe(xpr ** for ebc vhex mode. /Me oprion ignored)//~v956I~
//100908 v953 v9.19 EBC convertername support /CPEB:               //~v953I~
//100430 v943 (BUG)vhex mode;input fmt err msg when HHEX+VHEX      //~v943I~
//100428 v941 v9.16 ebcdic print support                           //~v941I~
//071005 v928 (Win)UTF8 support                                    //~v928I~
//070511 v927 (BUG)compile err by LONG LONG file size support      //~v927I~
//050410 v91u (BUG)vhex mode;input fmt err msg when line contain 0x1a(fgets return 0)//~v91uI~
//050410 v91t (BUG)vhex mode;too long line err msg when line contain 0x00//~v91tI~
//050309 v91r vhex print support for xe(/WN___X);line split and page eject//~v91rI~
//041009 v91q (BUG)exit when restart file is canceled.             //~v91qI~
//040605 v91n :no "*" on hdr fname when ftp(<xx>yy fmt)            //~v91nI~
//040605 v91m :additional to 90b,allow dir without wildcard        //~v91mI~
//				for also indirect file if not remote dir.          //~v91mI~
//040531 v91k (FTP)remote file print support;"<orgfname>LocalTempFile" fmt//~v91kI~
//                 on parm and indirect file.                      //~v91kI~
//040417 v91j (WIN)uattlib parm changed char to long               //~v91jI~
//020107 v90u (BUG)not applicable errmsg when dir has subdir only  //~v90uI~
//             xpinp.c                                             //~v90uI~
//011209 v90m :support stdout output                               //~v90mI~
//010521 v90f :LINUX support:shell expand wildcard                 //~v90fI~
//010520 v909 :filename extention is after last .(for win/os2/linux)//~v909I~
//010519 v907 :LINUX support(filename case sensitive,parm flag)    //~v907R~
//001105 v902 :new sort order option "F"(fullname),not base+ext    //~v902I~
//001105 v901 :(BUG)file name sort extention should be case insensitive
//000115 v898 :y2k:2000 year displayed as 100                      //~v898I~
//991003 v896 :(BUG)of v890.del v892                               //~v896I~
//             if crlf if just on the line limit,colomn width is changed//~v896I~
//             between phase.so page number differ phase2 and phase1//~v896I~
//             At phase 1 crlf at 80 is line count 1 because maxline is 115,//~v896I~
//             At phase 2 crlf at 80 is line count 2 because maxline is 80.//~v896I~
//             page on header is printed like as 15/14.            //~v896I~
//             Change getinput to chk lf when cr then return lf when text mode.//~v896I~
//990918 v894 :(BUG)2 set print when last is dbcs 1st byte         //~v894I~
//990911 v890 :Win stop read at 0x1a;change r to rb of readmode.   //~v890I~
//990828 v888 :/W= support(filename on header;for xe current file print thru work)//~v888I~
//981028 v868 :(BUG)fullpath failed when dest is "プリンター"　    //~v868I~
//             for chk input and out put is same name.             //~v868I~
//980923 v841 :(BUG:WIN/GCC)wild card *.* or * is rejected because it is directory//~v839I~
//             set parm SUBDIR flag and use nomsg option findfirst //~v841R~
//971130 v839 :findfirst with dir option to avoid dup errmsg       //~v839I~
//971129 v836 :GCC version                                         //~v836I~
//             xpinp.c:alias and lfn                               //~v836I~
//971125 v835 :GCC version                                         //~v835I~
//             _dos_findfirst/_dos_findnext\_dos_setfileattr       //~v835I~
//                      -->udosfindfirst/udosfindnext/uattrib      //~v835I~
//971124 v834 :GCC version                                         //~v834I~
//             del xpfullpath,use ufullpath                        //~v834I~
//971123 v827 :split xpsub1 from xrint.c                           //~v827I~
//970928 v826 :w95 version                                         //~v826I~
//             compiler warning:comp singned and unsigned          //~v826I~
//             _dos_findfirst/_dos_findnext\_dos_setfileattr       //~v826I~
//                  -->udosfindfirst/udosfindnext/uattrib          //~v826I~
//970607 v825 :(BUG)ext key for confirma reply cause line destroy. //~v825I~
//970607 v824 :bypass confirm before restart file for also /ol(no sort)//~v824I~
//970607 v823 :(BUG)display invalid filename on confirmation when /ol//~v823I~
//                  (static pathlen changed by fullpath PATHLEN)   //~v823I~
//970607 v822 :(BUG)unmatch with restart/prn file when path is  specified//~v822I~
//970607 v821 :(BUG)drive specification dropped when no \ embedded in filename//~v821I~
//970512 v80a:display filename after replyed 'A'll.                //~v80aI~
//970214 v806:header filename:split filename from dir name         //~v806I~
//970214 v805:pathlen considering dbcs filename                    //~v805I~
//970207 v802:confirm reply 'E'(all selected) 'Esc'(cancel)        //~v802I~
//970206 v801:option to print files in a dir conjunctly            //~v801I~
//960707 v766 :ibmc2-->msc6                                        //~v766I~
//960606 v764 :confirm reply all option                            //~v764I~
//960606 v763 :confirm only following of specified restart file    //~v763I~
//960606 v762 :(BUG)strupr cause err for some DBCS filename,use memicmp//~v762I~
//951123 v751 :err msg for dir name as input                    //~v751I~
//951123 v74r :err msg when no condition match file exist       //~v74rI~
//951122 v74p :open err whe \hhh format(drop first \ )          //~v74rI~
//*************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add
//*************************************************************

#ifdef DOS                           //v3.6a                    //~v743I~
                                                                //~v743I~
    #include <dos.h>                     //v3.7a                //~v743I~
    #include <errno.h>                   //v3.7a                //~v743I~
    #include <bios.h>                   //av4.2                 //~v743I~
                                                                //~v743I~
#else                                //v3.6a                    //~v743I~
                                                                //~v743I~
  #ifdef W32                                                       //~v826I~
    #include <io.h>                                                //~v826I~
    #include <windows.h>                                           //~v826I~
  #else                                                            //~v826I~
    #define INCL_BASE                     //v1.3 add v3.7r      //~v743I~
    #define INCL_SPL                        //v7.11a            //~v743I~
    #define INCL_WINSHELLDATA               //v7.11a            //~v743I~
    #define INCL_SPLDOSPRINT                //prqinfo3 v7.11a   //~v743I~
    #include <os2.h>         //v1.3 add                         //~v743I~
  #endif                                                           //~v826I~
                                                                //~v743I~
#endif                               //v3.6a                    //~v743I~
                                                                //~v743I~
#include <ulib.h>                                               //~v743M~
#include <uerr.h>                                                  //~v801I~
#include <ufile.h>                                                 //~v806I~
#ifdef W32                                                         //~v826I~
    #include <ufile2.h>                                            //~v826I~
#endif                               //v3.6a                       //~v826I~
#include <utrace.h>                                                //~v928I~
#include <ucvebc.h>                                                //~v956R~
#include <ustring.h>                                               //~v96dI~
#include <ufilew.h>                                                //~v990I~
                                                                //~v743I~
//*********************************************************************
#include  "xp.h"                                                //~v74kI~
#include  "xpinp.h"                                                //~v909I~
#include  "xpsub1.h"                                               //~v827I~
#include  "xputf.h"                                                //~v928I~
#include  "xpebc.h"                                                //~v941I~
#ifdef GTKPRINT                                                    //~v97mI~
	#include  "xplnxp.h"                                           //~v97mI~
#endif                                                             //~v97mI~
//*********************************************************************//~v74kI~
extern int  dbcsenv;           //dbcs environment sw v4.9a v7.23r//~5B23I~
extern char pgmid[];     //v7.1a v7.23r                         //~5B23I~
extern char ver[];          //v7.1a v7.23r                      //~5B23I~
extern int ordertype;     //default order is by EXT and NAME    v4.6a//~5B23I~
extern int ordersw;        //file select in the specified order  v4.6a v5.7r//~5B23I~
extern char *prn;    // default output                          //~5B23I~
extern long inputrange1,inputrange2;    //v7.21a                //~5B23I~
extern int multiprintjob; //output multijob sw v7.1a            //~5B23I~
extern char  docname[];         //document name             v7.11a//~5B23I~
extern int dumpmode;         //dump mode default=text v2.8rep v6.7r//~v892R~
extern int swconfirm;        //confirm when wild card  v3.7a    //~5B23I~
extern int outdevprn;        //output is printer                   //~v868I~
extern UCHAR *Ghdrfnm;       //alternative filename on hdr         //~v888I~
extern FILE *Gmsgfile;       //for print start msg                 //~v90mR~
extern int nocrlfsw; 	      	//ignore crlf for dump mode        //~v97vI~
//*********************************************************************//~v74lM~
static char inputfname[_MAX_PATH];   // default output             //~v821R~
//static unsigned char rbuff[RBUFFSZ];                             //~v96iR~
static unsigned char rbuff[RBUFFSZ+32]; //for the space of eolprint(eolid+length);//~v96iR~
static char *openfn;            //opend file file name           v7.2a
static int  Snextgetc=0;      //next fgetc char                    //~v91nR~
static int  Snextsavedsw;   //next fgetc char saved                //~v896I~
static int	Sffopt=0;                                              //~v91mI~
static int  Shdrfnmtype=0;                                         //~v91nI~
//****************************************************************//~v742R~
//char *xpfullpath(char *Pfullpath,char *Pfilename,size_t Plen);   //~v834R~
int getpath(char *,int);            //get pathname v5.7a           //~v825R~
int  fileconfirm(char *,USHORT,USHORT);     //file name confirmation to print v6.1a//~v74kR~
int notfound(ULONG Pdirrc,UCHAR *Pfname);                       //~v751I~
int pathcomp(char *Ppath,int Ppathlen,char *Pparmfname);           //~v822I~
int fullpathcomp(char *Pfname1,char *Pfname2);                     //~v822I~
//**********************************************************************
// create sorted file list          v4.6a
//**********************************************************************
FLIST *listgen(char *multifile[],char *parmfname) //v5.7r          //~v801R~
{
    int i;  //v6.1a
    int pathlen,rc;                                                //~v822R~
    char *cptr; //v6.1a
    int openrc;
    int filenumb=0;     //v7.0r
    int infileno;       //multifileno spec index v5.7a
    FLIST *flistt,*flistw; //v7.0r
//***********************
    listgensw=1;                        //for openinput,bypass open 
    if (!(flistt=(FLIST*)malloc((UINT)(sizeof(FLIST)*MAXFLIST)))) //v7.0r//~v766R~
    {
        if (dbcsenv)    //DBCS mode v4.9a
//          printf("%s:%s:ソート用記憶域不足,/No(無順序出力) オプションを使って下さい\n",pgmid,ver);//v4.9a//~v834R~
            printf("%s:%s:\x83\\ート用記憶域不足,%cNo(無順序出力) オプションを使って下さい\n",pgmid,ver,//~v907R~
						CMDFLAG_PREFIX);//v4.9a                    //~v907I~
        else            //SBCS mode v4.9a   
            printf("%s:%s:file sort work alloc failed,try %cNo(no order) option\n",pgmid,ver,//~v907R~
						CMDFLAG_PREFIX);                           //~v907I~
        uexit(8);                                               //~v74rR~
    }
    flistw=flistt;  //v7.0r

    for (infileno=0;;infileno++)                //v5.7a         //~v742R~
    {                                                           //v5.7a 
        if (!multifile[infileno])           //end of list   v5.7a
            break;                          //v5.7a 
//      openrc=openinput(multifile[infileno]);     //find first v5.7r//~v91kR~
        openrc=openinput(xpparsehdrfnm(multifile[infileno]));     //find first v5.7r//~v91kI~
        if (openrc>=4)                                          //~v742I~
            uexit(8);                                           //~v742I~
        while(openrc<4)                   //all wild card file
        {                                 //
            if (openrc)                      //file selected
            {                               //save to sort list
#if defined(W32) || defined(DPMI)                                  //~v836I~
                memset(flistw->name,0,sizeof(flistw->name));       //~v836I~
                strcpy(flistw->name,fstat3.cFileName);             //~v836I~
                memset(flistw->alias,0,sizeof(flistw->alias));     //~v836I~
                strcpy(flistw->alias,fstat3.achName);              //~v836I~
//  printf("alias=%s,name=%s\n",flistw->alias,flistw->name);//@@@@test//~v839R~
#else                                                              //~v836I~
                memset(flistw->name,0,sizeof(flistw->name));
                strcpy(flistw->name,fstat3.achName);
#endif                                                             //~v836I~
//              strupr(flistw->name);       //for strcmp v6.1a     //~v762R~
                flistw->attr=(char)fstat3.attrFile; //v7.0r
//              flistw->time=*((USHORT*)(void*)(&(fstat3.ftimeLastWrite))); //940609r//~v978R~
                flistw->time=FTIME2USHORT(fstat3.ftimeLastWrite);  //~v978I~
//              flistw->date=*((USHORT*)(void*)(&(fstat3.fdateLastWrite))); //940609r//~v978R~
                flistw->date=FDATE2USHORT(fstat3.fdateLastWrite);  //~v978I~
                flistw->size=fstat3.cbFile;
                flistw->inpfindex=infileno; //v5.7a
                if (filenumb++==MAXFLIST)
                {
                    if (dbcsenv)    //DBCS mode v4.9a
                        printf("%s:%s:ファイル数が制限値(=%d)以上です,%cNo(無順序出力)オプションを指定して下さい\n",pgmid,ver,//~v907R~
							(int)MAXFLIST,CMDFLAG_PREFIX);//v4.9a  //~v907I~
                    else            //SBCS mode v4.9a   
                        printf("%s:%s:file count over max(=%d),try %cNo(no order) option\n",pgmid,ver,//~v907R~
							(int)MAXFLIST,CMDFLAG_PREFIX);         //~v907I~
                    uexit(4);                                   //~v742R~
                }
                flistw++;
            }//file selected
            openrc=openinput(NULL);         //findnext
        }
    }//all input file spec(multi input file)    v5.7a
    memset(flistw->name,0,sizeof(flistw->name));//eof id
    listgensw=0;                        //for openinput,bypass find

    if (!filenumb)                                              //~v74rI~
    {                                                           //~v74rI~
        if (dbcsenv)                                            //~v74rI~
            printf("%s:%s:条件に一致するファイルがありません\n",pgmid,ver);//v4.9a//~v74rI~
        else                                                    //~v74rI~
            printf("%s:%s:no file selected\n",pgmid,ver);       //~v74rI~
        uexit(4);                                               //~v74rI~
    }                                                           //~v74rI~
    qsort(flistt,(UINT)filenumb,sizeof(FLIST),compare); //sort //v7.0r

//** confirmation v6.1a
//  if (swconfirm) //question to operator option v6.2d
    if (pagefile)                                                  //~v763R~
    {                                                              //~v763I~
        for (flistw=flistt,i=0;i<filenumb;flistw++,i++) //v7.0r    //~v763I~
        {                                                          //~v763I~
//          cptr=multifile[flistw->inpfindex];          //parm file name//~v91kR~
            cptr=xpparsehdrfnm(multifile[flistw->inpfindex]);          //parm file name//~v91kI~
            if (strpbrk(cptr,"*?"))                     //nonzero if "*" or "?" is used//~v763I~
            {                                                      //~v763I~
                strcpy(inputfname+(pathlen=getpath(cptr,1)),flistw->name); //append file name//~v822R~
                cptr=inputfname;                                   //~v763I~
                rc=pathcomp(cptr,pathlen,pagefile); //pagefile may contain path//~v822I~
            }                                                      //~v763I~
//          if (!stricmp(cptr,pagefile)) //mutched filename        //~v822R~
            else                                                   //~v822I~
//              rc=stricmp(cptr,pagefile); //fullname compare      //~v909R~
                rc=xpfnmcomp(cptr,pagefile); //fullname compare    //~v909R~
            if (!rc)                     //mutched filename        //~v822I~
            {                                                      //~v763I~
                for (i--,flistw--;i>=0;flistw--,i--)    //until first//~v763R~
                    flistw->inpfindex=-1;   //id of no print       //~v763I~
                break;                                             //~v763I~
            }                                                      //~v763I~
        }//all entry                                               //~v763I~
        if (i>=0)   //not found pagefile                           //~v763I~
        {                                                          //~v763I~
            if (dbcsenv)    //DBCS mode v6.2a                      //~v763I~
                printf("\n%s:%s:%cP パラメータの ファイル名(%s)の誤りです.\n",pgmid,ver,//~v907R~
					CMDFLAG_PREFIX,pagefile);                      //~v907I~
            else            //SBCS mode v4.9a                      //~v763I~
                printf("\n%s:%s:error of filename(%s) on %cP parameter.\n",pgmid,ver,//~v907R~
					pagefile,CMDFLAG_PREFIX);//v6.2a               //~v907I~
            uexit(4);                                              //~v763I~
        }                                                          //~v763I~
    }                                                              //~v763I~
#ifdef GTKPRINT                                                    //~v970M~
	hidewindow(1);                                                 //~v970R~
#endif                                                             //~v970M~
    for (flistw=flistt,i=0;i<filenumb;flistw++,i++) //v7.0r
    {
        if (flistw->inpfindex==-1)  //id of no print               //~v763I~
            continue;   //skip confirm;                            //~v763I~
//      cptr=multifile[flistw->inpfindex];          //parm file name//~v91kR~
        cptr=xpparsehdrfnm(multifile[flistw->inpfindex]);          //parm file name//~v91kI~
#ifdef UNX          //confirm always for UNX(shell expand case)    //~v90fI~
#else                                                              //~v90fI~
        if (strpbrk(cptr,"*?"))                     //nonzero if "*" or "?" is used
        {
#endif                                                             //~v90fI~
            strcpy(inputfname+(pathlen=getpath(cptr,1)),flistw->name); //append file name//~v822R~
            if (!fileconfirm(inputfname,flistw->date,flistw->time)) //reply no//~v74kR~
            {                                                      //~v763I~
                flistw->inpfindex=-1;   //id of no print
                if (pagefile                                       //~v763I~
//              &&  !stricmp(inputfname,pagefile)) //canceled restart file//~v822R~
                &&  !pathcomp(inputfname,pathlen,pagefile)) //canceled restart file//~v822I~
                {                                                  //~v763I~
                    if (dbcsenv)    //DBCS mode v6.2a              //~v763I~
                        printf("\n%s:%s:%cP パラメータのリスタートファイル(%s)が取り消されました.\n",pgmid,ver,//~v907R~
								CMDFLAG_PREFIX,pagefile);          //~v907I~
                    else            //SBCS mode v4.9a              //~v763I~
                        printf("\n%s:%s:You canceled restart file(%s) on %cP parameter.\n",pgmid,ver,//~v907R~
								pagefile,CMDFLAG_PREFIX);//v6.2a   //~v907I~
//                  uexit(4);                                      //~v91qR~
                    pagefilesw=3;   //from 1st page of next file   //~v91qI~
                }                                                  //~v763I~
            }                                                      //~v763I~
#ifdef UNX                                                         //~v90fI~
#else                                                              //~v90fI~
        }
#endif                                                             //~v90fI~
    }//all entry
#ifdef GTKPRINT                                                    //~v970M~
	showwindow(1);                                                 //~v970R~
#endif                                                             //~v970M~
//** confirmation v6.1a

    return flistt; //v7.0r
}//listgen
//**********************************************************************//~v822I~
//* file name compare for pagefile/output file                     //~v822I~
//parm1:path+filename                                              //~v822I~
//parm2:pathlen                                                    //~v822I~
//parm3:parm specification                                         //~v822I~
//*  return code: 0: mutch, else unmatch                           //~v822I~
//**********************************************************************//~v822I~
int pathcomp(char *Ppath,int Ppathlen,char *Pparmfname)            //~v822I~
{                                                                  //~v822I~
    int rc;                                                        //~v822I~
//**************                                                   //~v822I~
    if (!getpath(Pparmfname,0)) //no copy to inputfname            //~v822I~
//      rc=stricmp(Ppath+Ppathlen,Pparmfname);  //compare member name//~v909R~
        rc=xpfnmcomp(Ppath+Ppathlen,Pparmfname);  //compare member name//~v909I~
    else                                                           //~v822I~
//      rc=stricmp(Ppath,Pparmfname);   //compare member name      //~v909R~
        rc=xpfnmcomp(Ppath,Pparmfname);   //compare member name    //~v909I~
    return rc;                                                     //~v822I~
}//pathcomp                                                        //~v822R~
//**********************************************************************//~v822I~
//* file name compare by its fullpath name                         //~v822I~
//parm1:name1                                                      //~v822I~
//parm2:name2                                                      //~v822I~
//*  return code: 0: mutch, else unmatch                           //~v822I~
//**********************************************************************//~v822I~
int fullpathcomp(char *Pfname1,char *Pfname2)                      //~v822I~
{                                                                  //~v822I~
    char fullpath1[_MAX_PATH],fullpath2[_MAX_PATH];                //~v822I~
//**************                                                   //~v822I~
    if (!ufullpath(fullpath1,Pfname1,_MAX_PATH))                   //~v834R~
        return 4;                                                  //~v822I~
    if (!ufullpath(fullpath2,Pfname2,_MAX_PATH))                   //~v834R~
        return 4;                                                  //~v822I~
//  return stricmp(fullpath1,fullpath2);                           //~v909R~
    return xpfnmcomp(fullpath1,fullpath2);                         //~v909I~
}//pathcomp                                                        //~v822I~
//**********************************************************************
//* file name compare for sort
//*  return code: -1: ent1<ent2
//*                0: ent1=ent2
//*                1: ent1>ent2
//**********************************************************************
int compare(const void *ent1,const void *ent2)
{
    int type;
    int rc=0;                                                      //~v965R~
//  int len;            //v7.0d
    FLIST *flist1,*flist2;
    char *pos1,*pos2;
    char *name1,*name2;                                            //~v836I~
//  char c1,c2;                                                    //~v836R~
//  char fnwk1[9],fnwk2[9];                                        //~v836R~
//*****************
//  flist1=(FLIST*)(ULONG)ent1;    //v7.0r                         //~v91nR~//~v968R~
    flist1=(FLIST*)(ULPTR)ent1;    //v7.0r                         //~v968I~
//  flist2=(FLIST*)(ULONG)ent2;    //v7.0r                         //~v91nR~//~v968R~
    flist2=(FLIST*)(ULPTR)ent2;    //v7.0r                         //~v968I~
    name1=flist1->name;                                            //~v836I~
    name2=flist2->name;                                            //~v836I~

    if ((type=ordertype)<0)
        type=-type;         //plus value

    switch (type)
    {
    case 'N':         //by fullname                                //~v902R~
//      rc=stricmp(name1,name2);    //first half is same           //~v909R~
        rc=xpfnmcomp(name1,name2);    //first half is same         //~v909I~
      break;                                                       //~v902I~
                                                                   //~v902I~
    case 'E':         //ext and name
//    if (!(pos1=strpbrk(flist1->name,".")))                       //~v836R~
//      pos1=flist1->name+8; //null string                         //~v836R~
//    if (!(pos1=strpbrk(name1,".")))                              //~v909R~
      if (!(pos1=strrchr(name1,'.')))                              //~v909I~
        pos1="";                                                   //~v836I~
//    if (!(pos2=strpbrk(flist2->name,".")))                       //~v836R~
//      pos2=flist2->name+8; //null string                         //~v836R~
//    if (!(pos2=strpbrk(name2,".")))                              //~v909R~
      if (!(pos2=strrchr(name2,'.')))                              //~v909I~
        pos2="";             //null string                         //~v836I~
//    strncpy(fnwk1,pos1+1,4);                                     //~v836R~
//    strncpy(fnwk2,pos2+1,4);                                     //~v836R~
//    if (!(rc=memicmp(pos1,pos2,3)))   //same ext                 //~v836R~
//    if (!(rc=stricmp(pos1,pos2))) //same ext                     //~v909R~
      if (!(rc=xpfnmcomp(pos1,pos2))) //same ext                   //~v909I~
      {
//        c1=*pos1;                                                //~v836R~
//        c2=*pos2;                                                //~v836R~
//        *pos1=0;    //temporaly null term                        //~v836R~
//        *pos2=0;    //temporaly null term                        //~v836R~
//        strncpy(fnwk1,flist1->name,9);                           //~v836R~
//        strncpy(fnwk2,flist2->name,9);                           //~v836R~
//        *pos1=c1;   //recov original value                       //~v836R~
//        *pos2=c2;   //recov original value                       //~v836R~

//      rc=memicmp(fnwk1,fnwk2,8);                                 //~v836R~
        if (*pos1)             //null string                       //~v836I~
            *pos1=0;    //temporaly null term                      //~v836I~
        else                                                       //~v836I~
            pos1=0;                                                //~v836I~
        if (*pos2)             //null string                       //~v836I~
            *pos2=0;    //temporaly null term                      //~v836I~
        else                                                       //~v836I~
            pos2=0;                                                //~v836I~
//      rc=stricmp(name1,name2);                                   //~v909R~
        rc=xpfnmcomp(name1,name2);                                 //~v909I~
        if (pos1)             //null string                        //~v836I~
            *pos1='.';    //temporaly null term                    //~v836I~
        if (pos2)             //null string                        //~v836I~
            *pos2='.';    //temporaly null term                    //~v836I~
      }
      break;

//  case 'N':         //by base+ext                                //~v902R~
    case 'B':         //by base+ext                                //~v902I~
//      if (!(pos1=strpbrk(flist1->name,".")))                     //~v836R~
//        pos1=flist1->name+8; //null string                       //~v836R~
//      if (!(pos2=strpbrk(flist2->name,".")))                     //~v836R~
//        pos2=flist2->name+8; //null string                       //~v836R~

//      c1=*pos1;                                                  //~v836R~
//      c2=*pos2;                                                  //~v836R~
//      *pos1=0;  //temporaly null term                            //~v836R~
//      *pos2=0;  //temporaly null term                            //~v836R~
//      strncpy(fnwk1,flist1->name,9);                             //~v836R~
//      strncpy(fnwk2,flist2->name,9);                             //~v836R~
//      *pos1=c1; //recov original value                           //~v836R~
//      *pos2=c2; //recov original value                           //~v836R~
        if (pos1=strrchr(name1,'.'),pos1)                          //~v836R~
            *pos1=0;  //temporaly null term                        //~v836I~
        if (pos2=strrchr(name2,'.'),pos2)                          //~v836R~
            *pos2=0;  //temporaly null term                        //~v836I~

//    if (!(rc=memicmp(fnwk1,fnwk2,8))) //first half is same       //~v836R~
//      rc=stricmp(name1,name2);    //first half is same           //~v909R~
        rc=xpfnmcomp(name1,name2);    //first half is same         //~v909I~
        if (pos1)                                                  //~v836I~
            *pos1='.';                                             //~v836R~
        else                                                       //~v836I~
            pos1="";                                               //~v836I~
        if (pos2)                                                  //~v836I~
            *pos2='.';                                             //~v836R~
        else                                                       //~v836I~
            pos2="";                                               //~v836R~
        if (!rc)                                                   //~v836R~
//      {                                                          //~v836R~
//        strncpy(fnwk1,pos1+1,4);                                 //~v836R~
//        strncpy(fnwk2,pos2+1,4);                                 //~v836R~
//        rc=memicmp(fnwk1,fnwk2,3);                               //~v836R~
//          rc=strcmp(pos1,pos2);                                  //~v836I~
//          rc=stricmp(pos1,pos2);                                 //~v909R~
            rc=xpfnmcomp(pos1,pos2);                               //~v909I~
//      }                                                          //~v836R~
      break;

    case 'D':         //by date
      if (!(rc=(INT)(flist1->date-flist2->date)))   //same date v7.0r
        rc=(INT)(flist1->time-flist2->time);        //by time v7.0r
      break;
    }//switch by type

    if (!rc)        //same seq v5.7a
        rc=flist1->inpfindex-flist2->inpfindex; //input spec sequence v5.7a

    if ((type=ordertype)<0)
        rc=-rc;             //reverse
    return rc;
}//compare
//**********************************************************************
// find and open input file
// rc 0:normal 1:normal(return to listgen) 4:no more file 8:file not found//~v742I~
//**********************************************************************
int openinput(char *parmfname)    //v3.7a
{
static int pathlen;            //file path name length v3.7a
static FLIST *flistw=NULL;          //flist pointer v4.6a v5.7r
static FLIST *flist1stsel;          //first selected file          //~v801I~
  int rc;                       //v5.8a
  int fullpathlen;                                                 //~v823I~
  int fullpathln2;                                                 //~v888I~
  char *cptr;                    //v3.7a 
  char *openmode;               //av4.2
static  int  wildcardsw;                //wildcard sw for 1 input file spec v5.7a
    char fullpath[_MAX_PATH];                                   //~v74fI~

int fdatechkmain(void);             //940609a                   //~v74jR~
//int findfile(char *);           //v5.8a findfirst/findnext       //~v91kR~
    USHORT *pus;                                                   //~v96bI~
    ULPTR  ulp;                                                    //~v96bI~
#ifdef W32UNICODE                                                  //~v990R~
    char fullpathstrip[_MAX_PATH];                                 //~v990R~
#endif                                                             //~v990R~
//*********************************
  input=NULL;                    //v3.9add
#ifdef UTF8SUPP                                                    //~v928I~
    if (XPUTF8MODE())                                              //~v928I~
        xputf_open(0);      //reda buff clear                      //~v928I~
#endif                                                             //~v928R~
  if (ordersw && !listgensw)    //sort required and case of called from main v4.6a
  {//copy file status data from sorted flist v4.6a
    if (!flistw)                    //first tile v5.7a
    {                                                              //~v801I~
        flist1stsel=NULL;           //to detect first selected     //~v801I~
        flistw=flist;               //top of file list v5.7a
    }                                                              //~v801I~
    if (!*(flistw->name))   //end of list    v4.6a
    {                                                              //~v801I~
        if (UCBITCHK(swsw3,SW3CONJUNCT))      //dir consecutive    //~v801R~
        {                                                          //~v801I~
            flistw=flist1stsel; //for phase2 first call            //~v801I~
            if (!phase2sw)                                         //~v801I~
            {                                                      //~v91nI~
#ifdef W32UNICODE                                                  //~v990I~
                uerrfprintfutf(0,Gmsgfile,"\n%s:%s:print start - \"%s\"",//~v990R~
                    				"\n%s:%s:プリント開始 - \"%s\"",//~v990I~
                    				pgmid,ver,Gparmfname);         //~v990I~
#else                                                              //~v990I~
                if (dbcsenv)    //DBCS mode v5.0a                  //~v801I~
//                  printf("\n%s:%s:プリント開始 - \"%s\"",pgmid,ver,Gparmfname);//~v90mR~
                    fprintf(Gmsgfile,"\n%s:%s:プリント開始 - \"%s\"",pgmid,ver,Gparmfname);//~v90mI~
                else                                               //~v801I~
//                  printf("\n%s:%s:print start - \"%s\"",pgmid,ver,Gparmfname);//~v90mR~
                    fprintf(Gmsgfile,"\n%s:%s:print start - \"%s\"",pgmid,ver,Gparmfname);//~v90mI~
#endif                                                             //~v990I~
            }                                                      //~v91nI~
        }                                                          //~v801I~
        else                                                       //~v801I~
            flistw=NULL;    //for not merge mode,next dir          //~v801I~
        return 4;           //return as eof  v4.6a
    }                                                              //~v801I~
    if (flistw->inpfindex==-1)      //id of no print v6.1 add
    {//v6.1a
        flistw++;                   //v6.1a
        return 0;                   //print skip v6.1a
    }//v6.1a

    if (!flist1stsel)       //first time selected                  //~v801I~
        flist1stsel=flistw; //for conjunct mode                    //~v801I~
    flistc=flistw;          //current selected                     //~v801I~
    fstat3.attrFile=flistw->attr;               //v4.6a v7.0r
#if defined(W32) || defined(DPMI)                                  //~v836I~
    memcpy(fstat3.cFileName,flistw->name,sizeof(fstat3.cFileName));//v4.6a//~v836I~
    memcpy(fstat3.achName,flistw->alias,sizeof(fstat3.achName));//v4.6a//~v836I~
#else                                                              //~v836I~
    memcpy(fstat3.achName,flistw->name,sizeof(fstat3.achName));//v4.6a
#endif                                                             //~v836I~
//  *((USHORT*)(void*)(&(fstat3.ftimeLastWrite)))=flistw->time;//v4.6a 940609r//~v96bR~
    ulp=(ULPTR)(&(fstat3.ftimeLastWrite));                         //~v96bR~
    pus=(USHORT*)ulp;                                              //~v96bI~
    *pus=flistw->time;                                             //~v96bI~
//  *((USHORT*)(void*)(&(fstat3.fdateLastWrite)))=flistw->date;//v4.6a 940609r//~v96bR~
    ulp=(ULPTR)(&(fstat3.fdateLastWrite));                         //~v96bR~
    pus=(USHORT*)ulp;                                              //~v96bI~
    *pus=flistw->date;                                             //~v96bI~
    fstat3.cbFile=flistw->size;//v4.6a
//  cptr=multifile[flistw->inpfindex];          //parm file name v6.1r//~v91kR~
    cptr=xpparsehdrfnm(multifile[flistw->inpfindex]);          //parm file name v6.1r//~v91kI~
    pathlen=getpath(cptr,1);                        //v5.7a v6.1r  //~v822R~
    wildcardsw=(strpbrk(cptr,"*?")!=NULL);      //nonzero if "*" or "?" is used v6.1a
#if defined(W32) || defined(DPMI)                                  //~v836I~
    strcpy(inputfname+pathlen,fstat3.cFileName); //append file namev4.6a//~v836I~
#else                                                              //~v836I~
    strcpy(inputfname+pathlen,fstat3.achName); //append file namev4.6a
#endif                                                             //~v836I~
    cptr=inputfname;             //file name set area v4.6a
    flistw++;                   //v4.6a
  }                                             //v4.6a
  else  //no sort option or called from listgen v4.6a
  {                                     //v4.6a
    if (parmfname)                          //first time
    {
        wildcardsw=(strpbrk(parmfname,"*?")!=NULL);//nonzero if "*" or "?" is used v5.7a
        pathlen=getpath(parmfname,1);           //v5.7a            //~v822R~
    }//first time

    rc=findfile(parmfname);        //dir search v5.8r   //v7.0r
    if (rc)                        //dir search v5.8r v7.0r
        return rc;                      //eof v5.8r

//  if (!stricmp(fstat3.achName,WKFPAGE)    //xprint work file v5.3a//~v909R~
//  ||  !stricmp(fstat3.achName,WKFPOS))    //xprint work file v5.3a//~v909R~
    if (!xpfnmcomp(fstat3.achName,WKFPAGE)    //xprint work file v5.3a//~v909I~
    ||  !xpfnmcomp(fstat3.achName,WKFPOS))    //xprint work file v5.3a//~v909I~
        return 0;
#if defined(W32) || defined(DPMI)                                  //~v836I~
    strcpy(inputfname+pathlen,fstat3.cFileName); //append file namev4.6a//~v836I~
#else                                                              //~v836I~
    strcpy(inputfname+pathlen,fstat3.achName); //append file name
#endif                                                             //~v836I~
    cptr=inputfname;             //file name set area

    if (condcode)   //date compare requested 940609a
        if (!fdatechkmain())//date compare failed(unmatch) 940609a//~v74jR~
        {                                   //v7.2a
            if (!wildcardsw)    //msg only when wildcardv7.2a
            {                                                      //~v91nI~
#ifdef W32UNICODE                                                  //~v990I~
        		uerrfprintfutf(0,stdout,"%s:%s:\"%s\" is not printed.(out of file timestamp selection condition)\n",//~v990I~
                    					"%s:%s:\"%s\" はファイルのタイムスタンプ条件指定に合致しません。\n",//~v990I~
								pgmid,ver,cptr);                   //~v990I~
#else                                                              //~v990I~
                if (dbcsenv)    //DBCS modev7.2a
                    printf("%s:%s:\"%s\" はファイルのタイムスタンプ条件指定に合致しません。\n",pgmid,ver,cptr);//v7.2a
                else            //SBCS mode         //v7.2a
                    printf("%s:%s:\"%s\" is not printed.(out of file timestamp selection condition)\n",pgmid,ver,cptr);//v7.2a
#endif                                                             //~v990I~
            }                                                      //~v91nI~
            return 0;   //chk next file     940609a     
        }                                   //v7.2a
//** archive attribute process v7.2a start
    if (swgetarchive)   //select archive file only
        if (!(fstat3.attrFile & FILE_ARCHIVED))
        {
            if (!wildcardsw)    //msg only when wildcard
            {                                                      //~v91nI~
#ifdef W32UNICODE                                                  //~v990I~
        		uerrfprintfutf(0,stdout,"%s:%s:\"%s\" is not printed.(not archived attribute)\n",//~v990I~
                    					"%s:%s:\"%s\" は保存属性オフです,プリントされません.\n",//~v990I~
								pgmid,ver,cptr);                   //~v990I~
#else                                                              //~v990I~
                if (dbcsenv)    //DBCS mode
                    printf("%s:%s:\"%s\" は保存属性オフです,プリントされません.\n",pgmid,ver,cptr);
                else            //SBCS mode
                    printf("%s:%s:\"%s\" is not printed.(not archived attribute)\n",pgmid,ver,cptr);
#endif                                                             //~v990I~
            }                                                      //~v91nI~
            return 0;   //chk next file 
        }
//** archive attribute process v7.2a end
//  if (!stricmp(cptr,prn)) //same as outputfile v5.0a v5.3r       //~v822R~
  if (!outdevprn)                                                  //~v868I~
    if (!fullpathcomp(cptr,prn))    //same as outputfile v5.0a v5.3r//~v822I~
    {//v5.0a
#ifdef W32UNICODE                                                  //~v990I~
        uerrfprintfutf(0,stdout,"%s:%s:\"%s\" is not printed.(output file you specified)\n",//~v990I~
        						"%s:%s:\"%s\"は出力ファイルです,プリントされません.\n",//~v990I~
						pgmid,ver,cptr);                           //~v990I~
#else                                                              //~v990I~
        if (dbcsenv)    //DBCS mode v5.0a
            printf("%s:%s:\"%s\"は出力ファイルです,プリントされません.\n",pgmid,ver,cptr);//v5.0a
        else            //SBCS mode v5.0a
            printf("%s:%s:\"%s\" is not printed.(output file you specified)\n",pgmid,ver,cptr);//v5.0a
#endif                                                             //~v990I~
        return 0;   //skip proces       v5.0a
    }

//** confirmation when wild card
    if (wildcardsw)
//      if (swconfirm) //question to operator option v6.2d
        if (!ordersw)   //not file sort v6.1a
        {                                                          //~v824I~
          rc=1;                 //for the case pathcomp not called //~v824I~
          if (pagefilesw!=1     //restart file specified,not yet found//~v824R~
          || !*pagefile                                            //~v824I~
          || !(rc=pathcomp(cptr,pathlen,pagefile))) //canceled restart file//~v824R~
            if (!fileconfirm(cptr,                              //~v74kR~
//  *((USHORT*)(void*)(&(fstat3.fdateLastWrite))),              //~v74kI~//~v978R~
    FDATE2USHORT(fstat3.fdateLastWrite),                           //~v978I~
//  *((USHORT*)(void*)(&(fstat3.ftimeLastWrite)))               //~v74kI~//~v978R~
    FTIME2USHORT(fstat3.ftimeLastWrite)                            //~v978I~
                    ))  //reply no v6.1a                        //~v74kI~
            {                                                      //~v824I~
                if (!rc)    //pathcomp returned match              //~v824I~
                {                                                  //~v91qI~
                    if (dbcsenv)    //DBCS mode                    //~v824I~
                        printf("\n%s:%s:%cP パラメータのリスタートファイル(%s)が取り消されました.\n",pgmid,ver,//~v907R~
								CMDFLAG_PREFIX,pagefile);          //~v907I~
                    else            //SBCS mode v4.9a              //~v824I~
                        printf("\n%s:%s:You canceled restart file(%s) on %cP parameter.\n",pgmid,ver,//~v907R~
								pagefile,CMDFLAG_PREFIX);          //~v907I~
//                  uexit(4);                                      //~v91qR~
                    pagefilesw=3; //pagefile replyed 'N'//start from next file//~v91qR~
                }                                                  //~v91qI~
                return 0;           //bypass print v6.1a
            }                                                      //~v824I~
        }                                                          //~v824I~
     if (listgensw)         //called from listgen  v4.6a
        return 1;               //bypass open v4.6a
  }//no sort or called from listgen v4.6a

//restart file control  v6.8a start
    if (pagefilesw==1)      //restart file specified
    {
        if (*pagefile                                              //~v822R~
//      && stricmp(cptr,pagefile)) //unmutched filename            //~v822I~
        && pathcomp(cptr,pathlen,pagefile)) //canceled restart file//~v822R~
            return 0;               //bypass print
        pagefilesw=2;               //resume file
    }
//restart file control  v6.8a end

//start offset chk with file size v7.21a start
    if (inputrangeopt==2)
        if ((UINT)inputrange1>=fstat3.cbFile)   //ovr eof          //~v826R~
        {
#ifdef W32UNICODE                                                  //~v990I~
        uerrfprintfutf(0,stdout,"%s:%s:\"%s\" is not printed.File size(%08" FILESZ_EDIT "x) is smaller than Input range start parm.\n",//~v990I~
                				"%s:%s:\"%s\" はプリントされません。入力開始位置がファイルサイズ(%08" FILESZ_EDIT "x)を越えています。\n",//~v990I~
                        pgmid,ver,cptr,fstat3.cbFile);             //~v990I~
#else                                                              //~v990I~
            if (dbcsenv)    //DBCS mode
//              printf("%s:%s:\"%s\" はプリントされません。入力開始位置がファイルサイズ(%08lx)を越えています。\n",//~v927R~
                printf("%s:%s:\"%s\" はプリントされません。入力開始位置がファイルサイズ(%08" FILESZ_EDIT "x)を越えています。\n",//~v927I~
                        pgmid,ver,cptr,fstat3.cbFile);
            else            //SBCS mode
//              printf("%s:%s:\"%s\" is not printed.File size(%08lx) is smaller than Input range start parm.\n",//~v927R~
                printf("%s:%s:\"%s\" is not printed.File size(%08" FILESZ_EDIT "x) is smaller than Input range start parm.\n",//~v927I~
                        pgmid,ver,cptr,fstat3.cbFile);
#endif                                                             //~v990I~
            return 0;   //chk next file 
        }
//start offset chk with file size v7.21a start

    if (!ufullpath(fullpath,cptr,_MAX_PATH))                       //~v834R~
        strcpy(fullpath,cptr);                                  //~v74fI~
//sprintf(header0+1,"%35.35s",cptr);        //v1.5add v2.6rep v4.4r v4.7d
  if (multiprintjob)                //multiple print job v7.11a
      strcpy(docname,cptr);         //doc name for each file v7.11a
//sprintf(header0,"%s",fullpath);        //v1.5add v2.6rep v4.4r v4.7a//~v806R~
if (Ghdrfnm)                                                       //~v888I~
{                                                                  //~v888I~
    fullpathln2=getpath(Ghdrfnm,0);                                //~v888R~
    memcpy(header0,Ghdrfnm,(UINT)fullpathln2); //path name(dir)    //~v888I~
    if (UCBITCHK(swsw3,SW3CONJUNCT))                               //~v888I~
        *(header0+fullpathln2)='-';        //easy idedifyable filename//~v888I~
    else                                                           //~v888I~
        *(header0+fullpathln2)=' ';        //easy idedifyable filename//~v888I~
  if (!Shdrfnmtype)	//no ftp remote                                //~v91nI~
    *(header0+fullpathln2+1)='*';      //id of alternative name    //~v888I~
  else                                                             //~v91nI~
    *(header0+fullpathln2+1)=' ';      //id of alternative name    //~v91nI~
  if (UCBITCHK(swsw3,SW3SCRPRT))                                   //~v90fR~
  {                                                                //~v90fI~
    *(header0+fullpathln2+2)='*';      //id of alternative name    //~v90fI~
   if (WILDCARD(Ghdrfnm+fullpathln2))//dir/wildcard                //~v91kI~
   {                                                               //~v91kI~
  	fullpathlen=getpath(fullpath,0);                               //~v91kI~
    strcpy(header0+fullpathln2+3,fullpath+fullpathlen); //get filename from tmp file//~v91kI~
   }                                                               //~v91kI~
   else                                                            //~v91kI~
    strcpy(header0+fullpathln2+3,Ghdrfnm+fullpathln2); //filename  //~v90fI~
  }                                                                //~v90fI~
  else                                                             //~v90fI~
   if (WILDCARD(Ghdrfnm+fullpathln2))//dir/wildcard                //~v91kI~
   {                                                               //~v91kI~
  	fullpathlen=getpath(fullpath,0);                               //~v91kI~
    strcpy(header0+fullpathln2+2,fullpath+fullpathlen); //get filename from tmp file//~v91kR~
   }                                                               //~v91kI~
   else                                                            //~v91kI~
    strcpy(header0+fullpathln2+2,Ghdrfnm+fullpathln2); //filename  //~v888I~
}                                                                  //~v888I~
else                                                               //~v888I~
{                                                                  //~v888I~
#ifdef W32UNICODE                                                  //~v990R~
	if (strchr(fullpath,UD_NOTLC))                                 //~v990R~
    {                                                              //~v990R~
    	int striplen;                                              //~v990R~
    	ufilecvUD2LC_bestfit(0,fullpath,strlen(fullpath),fullpathstrip,sizeof(fullpathstrip),&striplen);//~v990R~
        UmemcpyZ(fullpath,fullpathstrip,striplen);                 //~v990R~
    }                                                              //~v990R~
#endif                                                             //~v990R~
//fullpathlen=PATHLEN(fullpath);                                   //~v888R~
  fullpathlen=getpath(fullpath,0);                                 //~v888I~
  memcpy(header0,fullpath,(UINT)fullpathlen); //path name(dir)     //~v823R~
if (UCBITCHK(swsw3,SW3CONJUNCT))                                   //~v806I~
  *(header0+fullpathlen)='-';        //easy idedifyable filename   //~v823R~
else                                                               //~v806I~
  *(header0+fullpathlen)=' ';        //easy idedifyable filename   //~v823R~
  *(header0+fullpathlen+1)=' ';        //easy idedifyable filename //~v823R~
  strcpy(header0+fullpathlen+2,fullpath+fullpathlen); //filename   //~v823R~
}                                                                  //~v888M~
  sprintf(header0+strlen(header0),         //                  v1.3add//~v801R~
//        "  (%ldbyte %04d-%02d-%02d %02d:%02d)",//size yy-mm-dd hh:mm v1.3addv3.7r v4.7r//~v927R~
          "  (%" FILESZ_EDIT "dbyte %04d-%02d-%02d %02d:%02d)",//size yy-mm-dd hh:mm v1.3addv3.7r v4.7r//~v927I~
          fstat3.cbFile,                        //v1.3add
//        fstat3.fdateLastWrite.year+80,        //v1.3add          //~v898R~
          fstat3.fdateLastWrite.year+1980,        //v1.3add        //~v898R~
          fstat3.fdateLastWrite.month,          //v1.3add
          fstat3.fdateLastWrite.day,            //v1.3add
          fstat3.ftimeLastWrite.hours,          //v1.3add
          fstat3.ftimeLastWrite.minutes         //v1.3add
         );                                     //v1.3add
    strcpy(headers,header0);                                       //~v801R~
        strcat(header0+1," PAGE=");           //v1.1add v1.5rep    //~v801R~
        pagepos =(INT)strlen(header0);               //v1.1add v7.0r//~v801R~
//      pagenoedit(); //for printfile strlen to chk header0 width  //~v801I~//~v97mR~
        pagenoedit(PNEO_OPENINPUT); //for printfile strlen to chk header0 width//~v97mR~

//if (dumpmode)         //av4.2                                    //~v890R~
  if (!(swsw4 & SW4VHEXMODE))	//not vhex mode file from xe       //~v91rI~
    openmode="rb";      //av4.2
//else                  //av4.2                                    //~v890R~
//  openmode="r";       //av4.2                                    //~v890R~
  else                  //av4.2                                    //~v91rI~
//  openmode="r";       //av4.2                                    //~v91uR~
    openmode="rb";      //to read 0x1a(EOF char)                   //~v91uI~
  vhexreadline=0;       //init read line count                     //~v91rI~
  Snextsavedsw=0;       //clear saved for CRLF process             //~v896I~
  if (!(input=fopen(cptr,openmode)))  //open input fail //v2.6rep rv4.2
  {
    if (dbcsenv)    //DBCS mode v4.9a
        printf("%s:%s:入力ファイル(%s) のオープンエラー\n",pgmid,ver,fullpath); //v4.9a//~v74pR~
    else            //SBCS mode v4.9a   
        printf("%s:%s:input file(%s) open err\n",pgmid,ver,fullpath); //v2.6rep//~v74pR~
    uexit(4);                                                   //~v742R~
  }
  if (vfmt)                                                        //~v96eI~
  {                                                                //~v96eI~
  	sub1freadVinit(0,cptr);  //init recfm=V read                   //~v96eR~
  }                                                                //~v96eI~
  openfn=cptr;  //parm to archoff() v7.2a   
  if (!UCBITCHK(swsw3,SW3CONJUNCT)                                 //~v801I~
  ||  fastpathsw                                                   //~v801R~
  ||  !phase2sw)                                                   //~v801I~
  {                                                                //~v91nI~
//  if (UCBITCHK(swsw1,SW1NOKBD|SW1BACKG))  //no kbd intf          //~v801R~
#ifdef W32UNICODE                                                  //~v990I~
      uerrfprintfutf(0,Gmsgfile,"\n%s:%s:print start - \"%s\"",    //~v990I~
            			        "\n%s:%s:プリント開始 - \"%s\"",   //~v990I~
							pgmid,ver,cptr);                       //~v990I~
#else                                                              //~v990I~
        if (dbcsenv)    //DBCS mode v4.9a                       //~v74bI~
//          printf("\n%s:%s:プリント開始 - \"%s\"",pgmid,ver,cptr);//~v90mR~
            fprintf(Gmsgfile,"\n%s:%s:プリント開始 - \"%s\"",pgmid,ver,cptr);//~v90mI~
        else            //SBCS mode v4.9a                       //~v74bI~
//          printf("\n%s:%s:print start - \"%s\"",pgmid,ver,cptr); //~v90mR~
            fprintf(Gmsgfile,"\n%s:%s:print start - \"%s\"",pgmid,ver,cptr);//~v90mR~
//  else                                                           //~v801R~
//      if (dbcsenv)    //DBCS mode v4.9a                          //~v801R~
//          printf("\n%s:%s:プリント開始 - \"%s\"(Esc で中断します) ",pgmid,ver,cptr);//v4.9a//~v801R~
//      else            //SBCS mode v4.9a                          //~v801R~
//          printf("\n%s:%s:print start - \"%s\"(hit Esc to break) ",pgmid,ver,cptr);//v4.7r//~v801R~
#endif                                                             //~v990I~
  }                                                                //~v91nI~

  fflush(stdout);           //v7.1a
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
if (vfmt)       //to control EndOfLine by length                   //~v96eI~
 databuffsw=0;                                                     //~v96eI~
else                                                               //~v96eI~
if (UCBITCHK(swsw4,SW4EBCCFG))                                     //~v941R~
 databuffsw=0;                                                     //~v941I~
else                                                               //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
if (UCBITCHK(swsw3,SW3CONJUNCT))                                   //~v801I~
{                                                                  //~v801I~
//databuffsw=(databufft && ((fstat3.cbFile+(ULONG)databuffc-(ULONG)databufft)<DATABUFFSZ)); //malloc ok and size is ok v5.8a//~v801R~//~v968R~
//databuffsw=(databufft && ((fstat3.cbFile+(ULPTR)databuffc-(ULPTR)databufft)<DATABUFFSZ)); //malloc ok and size is ok v5.8a//~v968I~//+v9a1R~
  databuffsw=(databufft && ((fstat3.cbFile+(FILESZT)PTRDIFF(databuffc,databufft))<DATABUFFSZ)); //malloc ok and size is ok v5.8a//+v9a1I~
  if (databuffsw)                                                  //~v801I~
    if (phase2sw)                                                  //~v801I~
        databuffl=flistc->databuffl;    //eof pos                  //~v801I~
}                                                                  //~v801I~
else                                                               //~v801I~
  databuffsw=(databufft && (fstat3.cbFile<DATABUFFSZ)); //malloc ok and size is ok v5.8a
    
  return 0;
}//openinput

//**********************************************************************//~v91mI~
// find to allow dirname                                           //~v91mI~
//rc:0:ok, 4:no more(findnext), 8:not found(findfirst), 12:other api err//~v91mR~
//**********************************************************************//~v91mI~
int findfile2(int Popt,char *parmfname)    //v3.7a                 //~v91mR~
{                                                                  //~v91mI~
	int rc;                                                        //~v91mI~
//******************                                               //~v91mI~
	Sffopt=Popt;                                                   //~v91mI~
    rc=findfile(parmfname);                                        //~v91mI~
    Sffopt=0;                                                      //~v91mI~
    return rc;                                                     //~v91mI~
}//findfile2                                                       //~v91mI~
//**********************************************************************
// find and open input file av5.8
//rc:0:ok, 4:no more(findnext), 8:not found(findfirst), 12:other api err//~v742R~
//**********************************************************************
int findfile(char *parmfname)    //v3.7a
{
	static char Sfnmfirst[_MAX_PATH];                              //~v96dR~
#ifdef UNX                                                         //~v907I~
  static HDIR hdir;              //dir handle         v3.7a v7.11r //~v907I~
         APIRET apiret;          //api r.c                         v1.3 av3.7r//~v907I~
//*********************************                                //~v907I~
    if (parmfname)                          //first time           //~v907I~
    {                                                              //~v907I~
    	UstrncpyZ(Sfnmfirst,parmfname,sizeof(Sfnmfirst));          //~v96dI~
        apiret=udosfindfirst(parmfname,          //global name     //~v907I~
                        &hdir,          //search handle            //~v907I~
                        FILE_NORMAL     //search file attr         //~v907I~
                | FILE_READONLY                                    //~v907I~
                | FILE_HIDDEN                                      //~v907I~
                | FILE_SYSTEM,                                     //~v907I~
                        &fstat3);                                  //~v907I~
        if(apiret)                                                 //~v907I~
            return 8;                                              //~v907I~
    }//first time                                                  //~v907I~
    else //request next file                                       //~v907I~
    {                                                              //~v907I~
//  	apiret=udosfindnext(hdir,           //search handle        //~v907I~//~v96dR~
    	apiret=udosfindnext(Sfnmfirst,hdir,           //search handle//~v96dI~
                       &fstat3);       //output file information   //~v907I~
        if (apiret)                     //ERROR_NO_MORE_FILES)     //~v907I~
            return 4;  //no more file                              //~v907I~
    }//next req                                                    //~v907I~
#else  //!UNX                                                      //~v907I~
#ifdef DOS                          //v3.6a
  static ULONG apiret;              //v3.6a v3.7rv3.7d v4.0a  
  #ifdef DPMI                   //DPMI version                     //~v835I~
      static HDIR hdir;              //dir handle         v3.7a v7.11r//~v835I~
  #else                       //not DPMI                           //~v835I~
  #endif                      //DPMI or not                        //~v835I~
#else                               //v3.6a
  static APIRET apiret;          //api r.c                         v1.3 av3.7r
  static HDIR hdir;              //dir handle         v3.7a v7.11r
  #ifdef W32                                                       //~v967I~
  #else                                                            //~v967I~
         ULONG  cfilename=1;     //file name count    v3.7a v7.11r
  #endif                                                           //~v967I~
#endif                               //v3.6a

//*********************************

#ifdef DOS                          //v3.6a v3.7d

  #ifdef DPMI                   //DPMI version                     //~v835I~
    if (parmfname)                          //first time           //~v835I~
    {                                                              //~v835I~
//      apiret=udosfindfirst(parmfname,          //global name     //~v841R~
        apiret=udosfindfirstnomsg(parmfname,          //global name//~v841I~
                        &hdir,          //search handle            //~v835I~
                       _A_NORMAL           //search file attr      //~v835I~
                    |  _A_RDONLY           //search file attr      //~v835I~
                    |  _A_HIDDEN           //search file attr      //~v835I~
                    |  _A_SYSTEM           //search file attr      //~v835I~
//                  |  _A_SUBDIR           //search file attr      //~v841R~
                    |  _A_ARCH,            //search file attr      //~v835I~
                       &fstat3);           //output file information//~v835I~
//      if (!apiret && (fstat3.attrFile & _A_SUBDIR))              //~v841R~
//          return notfound(apiret,parmfname);//dir err            //~v841R~
        if(apiret)                                                 //~v835I~
        {                                                          //~v835I~
            if (apiret==ENOENT||apiret==ENMFILE)                   //~v835R~
            {                                                      //~v841I~
//              return 8;                                          //~v841R~
                apiret=udosfindfirstnomsg(parmfname,          //global name//~v841I~
                        &hdir,          //search handle            //~v841I~
                       _A_SUBDIR,       //chk dir                  //~v841I~
                       &fstat3);           //output file information//~v841I~
                return notfound(apiret,parmfname);//dir err        //~v841I~
            }                                                      //~v841I~
            return 12;                                             //~v841R~
        }                                                          //~v835I~
    }//first time                                                  //~v835I~
    else //request next file                                       //~v835I~
    {                                                              //~v835I~
        apiret=udosfindnext(hdir,&fstat3);  //output file information v4.0r//~v835I~
        if (apiret) //v4.0a                                        //~v835I~
            return 4;  //no more file                              //~v835I~
    }//next req                                                    //~v835I~
  #else                       //not DPMI                           //~v835I~
//*** dos
                                                                   //~v835I~
    if (parmfname)                          //first time
    {
        apiret=_dos_findfirst(parmfname,          //global name v4.0r
                       _A_NORMAL           //search file attr   //~v74dR~
                    |  _A_RDONLY           //search file attr   //~v74dI~
                    |  _A_HIDDEN           //search file attr   //~v74dI~
                    |  _A_SYSTEM           //search file attr   //~v74dI~
                    |  _A_ARCH,            //search file attr   //~v74dI~
                       (struct find_t*)&fstat3);           //output file information
//      if(errno)  //v4.0d
        if(apiret) //v4.0d
        {
            if(errno==ENOENT)
            {                                                   //~v742I~
                apiret=_dos_findfirst(parmfname,_A_SUBDIR,(struct find_t*)&fstat3);           //output file information//~v751I~
                return notfound(apiret,parmfname);              //~v751I~
            }                                                   //~v742I~
            else
            {                                                   //~v742I~
                if (dbcsenv)    //DBCS mode v4.9a
                    printf("%s:%s:(%s) FindFirst の失敗,リターンコード=%d\n",pgmid,ver,parmfname,errno);//v4.9a
                else            //SBCS mode v4.9a   
                    printf("%s:%s:(%s) FindFirst failed,rc=%d\n",pgmid,ver,parmfname,errno);
                return 12;                                      //~v742R~
            }                                                   //~v742I~
        }
    }//first time
    else //request next file
    {
        apiret=_dos_findnext((struct find_t*)&fstat3);  //output file information v4.0r
      
        if (apiret) //v4.0a
        {
            if (errno==ENOENT)
                return 4;  //no more file
     
//          if (errno)  v4.0d
//          {           v4.0d
            if (dbcsenv)    //DBCS mode v4.9a
                printf("%s:%s:FindNext の失敗,リターンコード=%d\n",pgmid,ver,errno);//v4.9a
            else            //SBCS mode v4.9a   
                printf("%s:%s:FindNext failed,rc=%d\n",pgmid,ver,errno);
            uexit (4);                                          //~v742R~
        }//apiret
    }//next req
  #endif                      //DPMI or not                        //~v835I~

#else                               //os2/2 v3.6a
  #ifdef W32                                                       //~v826I~
    if (parmfname)                          //first time           //~v826I~
    {                                                              //~v826I~
    	UstrncpyZ(Sfnmfirst,parmfname,sizeof(Sfnmfirst));          //~v96dI~
//      apiret=udosfindfirst(parmfname,          //global name     //~v841R~
        apiret=udosfindfirstnomsg(parmfname,          //global name//~v841I~
                        &hdir,          //search handle            //~v826I~
                        FILE_NORMAL     //search file attr         //~v826I~
                | FILE_READONLY                                    //~v826I~
//              | FILE_DIRECTORY                                   //~v841R~
                | FILE_HIDDEN                                      //~v826I~
                | FILE_SYSTEM                                      //~v826I~
                | FILE_ARCHIVED,                                   //~v826I~
                        &fstat3);                                  //~v826I~
//      if (!apiret && (fstat3.attrFile & FILE_DIRECTORY))         //~v841R~
//          return notfound(apiret,parmfname);   //dir err         //~v841R~
        if(apiret)                                                 //~v826I~
        {                                                          //~v826I~
            if(apiret==ERROR_NO_MORE_FILES                         //~v826I~
            || apiret==ERROR_FILE_NOT_FOUND     //v7.23a           //~v826I~
            || apiret==ERROR_PATH_NOT_FOUND)    //v7.23a           //~v826I~
            {                                                      //~v826I~
//                cfilename=1;                                     //~v839R~
//                apiret=udosfindfirst(parmfname,&hdir,            //~v839R~
//                        FILE_DIRECTORY,                          //~v839R~
//                        &fstat3);       //output file information//~v839R~
//              return 8;                                          //~v841I~
                apiret=udosfindfirstnomsg(parmfname,&hdir,         //~v841I~
                          FILE_DIRECTORY,                          //~v841I~
                          &fstat3);       //output file information//~v841I~
                return notfound(apiret,parmfname);   //dir err     //~v841I~
            }                                                      //~v826I~
            else                                                   //~v826I~
            {                                                      //~v826I~
//              if (dbcsenv)    //DBCS mode v4.9a                  //~v841R~
//                  printf("%s:%s:(%s) udosfindfirst の失敗,リターンコード=%d\n",pgmid,ver,parmfname,apiret);//v4.9a//~v841R~
//              else            //SBCS mode v4.9a                  //~v841R~
//                  printf("%s:%s:(%s) udosfindfirst failed,rc=%d\n",pgmid,ver,parmfname,apiret);//~v841R~
                return 12;                                         //~v826I~
            }                                                      //~v826I~
        }//apiret                                                  //~v826I~
    }//first time                                                  //~v826I~
    else //request next file                                       //~v826I~
    {                                                              //~v826I~
//      apiret=udosfindnext(hdir,           //search handle        //~v826I~//~v96dR~
        apiret=udosfindnext(Sfnmfirst,hdir,           //search handle//~v96dI~
                       &fstat3);       //output file information   //~v826I~
        if (apiret)                     //ERROR_NO_MORE_FILES)     //~v826I~
            return 4;  //no more file                              //~v826I~
    }//next req                                                    //~v826I~
  #else                                                            //~v826I~
//** os/2
    if (parmfname)                          //first time
    {
        hdir=(ULONG)HDIR_CREATE;  //dir handle create req  v7.11a
        apiret=DosFindFirst(parmfname,          //global name
                        &hdir,          //search handle
                        FILE_NORMAL     //search file attr      //~v74dR~
                | FILE_READONLY                                 //~v74dI~
                | FILE_HIDDEN                                   //~v74dI~
                | FILE_SYSTEM                                   //~v74dI~
                | FILE_ARCHIVED,                                //~v74dI~
                        &fstat3,       //output file information
                        sizeof(fstat3),//output area size
                        &cfilename,     //request file count
                        FIL_STANDARD);  //file information level
        if(apiret)
        {
            if(apiret==ERROR_NO_MORE_FILES
            || apiret==ERROR_FILE_NOT_FOUND     //v7.23a
            || apiret==ERROR_PATH_NOT_FOUND)    //v7.23a
            {                                                   //~v742I~
                hdir=(ULONG)HDIR_CREATE;  //dir handle create req  v7.11a//~v751I~
                cfilename=1;                                    //~v751I~
                apiret=DosFindFirst(parmfname,&hdir,            //~v751R~
                        FILE_DIRECTORY,                         //~v751R~
                        &fstat3,       //output file information//~v751I~
                        sizeof(fstat3),//output area size       //~v751I~
                        &cfilename,     //request file count    //~v751I~
                        FIL_STANDARD);  //file information level//~v751I~
                return notfound(apiret,parmfname);              //~v751I~
            }                                                   //~v742I~
            else
            {                                                   //~v742I~
                if (dbcsenv)    //DBCS mode v4.9a
                    printf("%s:%s:(%s) DosFindFirst の失敗,リターンコード=%d\n",pgmid,ver,parmfname,apiret);//v4.9a
                else            //SBCS mode v4.9a   
                    printf("%s:%s:(%s) DosFindFirst failed,rc=%d\n",pgmid,ver,parmfname,apiret);
                return 12;                                      //~v742R~
            }                                                   //~v742I~
        }//apiret
    }//first time
    else //request next file
    {
        apiret=DosFindNext(hdir,           //search handle
                       &fstat3,       //output file information
                       sizeof(fstat3),//output area size
                       &cfilename);    //request file count
      
        if (apiret==ERROR_NO_MORE_FILES)
        {
            apiret=DosFindClose(hdir);        //relese  handle
            if (apiret)
            {
                if (dbcsenv)    //DBCS mode v4.9a
                    printf("%s:%s:FindClose の失敗,リターンコード=%d\n",pgmid,ver,apiret);//v4.9a
                else            //SBCS mode v4.9a   
                    printf("%s:%s:FindClose failed,rc=%d\n",pgmid,ver,apiret);
                uexit (4);                                      //~v742R~
            }
            return 4;  //no more file
        }
     
        if (apiret)
        {
            if (dbcsenv)    //DBCS mode v4.9a
                printf("%s:%s:FindNext の失敗,リターンコード=%d\n",pgmid,ver,apiret);//v4.9a
            else            //SBCS mode v4.9a   
                printf("%s:%s:FindNext failed,rc=%d\n",pgmid,ver,apiret);
            uexit (4);                                          //~v742R~
        }
    }//next req

  #endif                                                           //~v826I~
#endif                               //v3.6a
#endif //!UNX                                                      //~v907I~

  return 0;
}//findfile
//**********************************************************************//~v751I~
//* not found msg                                               //~v751I~
//**********************************************************************//~v751I~
int notfound(ULONG Pdirrc,UCHAR *Pfname)                        //~v751I~
{                                                               //~v751I~
//****************                                              //~v751I~
    if (Pdirrc      //dir attr not found                           //~v90uR~
    ||  WILDCARD(Pfname))                                          //~v90uI~
#ifdef W32UNICODE                                                  //~v990I~
      uerrfprintfutf(0,Gmsgfile,"%s:%s:(%s) no such file exist.\n",//~v990I~
            					"%s:%s:ファイル(%s) が見つかりません.\n",//~v990I~
            			pgmid,ver,Pfname);                         //~v990I~
#else                                                              //~v990I~
        if (dbcsenv)    //DBCS mode v4.9a                       //~v751I~
//          printf("%s:%s:ファイル(%s) が見つかりません.\n",pgmid,ver,Pfname);//v4.9a//~v90mR~
            fprintf(Gmsgfile,"%s:%s:ファイル(%s) が見つかりません.\n",pgmid,ver,Pfname);//v4.9a//~v90mI~
        else            //SBCS mode v4.9a                       //~v751I~
//          printf("%s:%s:(%s) no such file exist.\n",pgmid,ver,Pfname);//~v90mR~
            fprintf(Gmsgfile,"%s:%s:(%s) no such file exist.\n",pgmid,ver,Pfname);//~v90mI~
#endif                                                             //~v990I~
    else            //name found as dir                         //~v751I~
      if (Sffopt & FF2OPT_DIR)	//accept dir                       //~v91mI~
      	return 1;	//id of dir found                              //~v91mI~
      else                                                         //~v91mI~
#ifdef W32UNICODE                                                  //~v990I~
      	uerrfprintfutf(0,Gmsgfile,"%s:%s:%s is directory,use wild card(*.* etc).\n",//~v990I~
								"%s:%s:%s はディレクトリーです，ワイルドカード指定して下さい.\n",//~v990I~
					pgmid,ver,Pfname);                             //~v990I~
#else                                                              //~v990I~
        if (dbcsenv)    //DBCS mode v4.9a                       //~v751I~
//          printf("%s:%s:%s はディレクトリーです，ワイルドカード指定して下さい.\n",pgmid,ver,Pfname);//v4.9a//~v90mR~
            fprintf(Gmsgfile,"%s:%s:%s はディレクトリーです，ワイルドカード指定して下さい.\n",pgmid,ver,Pfname);//v4.9a//~v90mI~
        else            //SBCS mode v4.9a                       //~v751I~
//          printf("%s:%s:%s is directory,use wild card(*.* etc).\n",pgmid,ver,Pfname);//~v90mR~
            fprintf(Gmsgfile,"%s:%s:%s is directory,use wild card(*.* etc).\n",pgmid,ver,Pfname);//~v90mI~
#endif                                                             //~v990I~
    return 8;   //not found                                     //~v751I~
}//notfound                                                     //~v751I~
//**********************************************************************
//* archive attribute reset     v7.2a
//**********************************************************************
void    archoff(void)
{
#ifdef UNX                                                         //~v907I~
#else                                                              //~v907I~
#ifdef DOS 
//** os/2
    UINT   rc;
    UINT   attr;
//*********************

    attr=(fstat3.attrFile&~_A_ARCH);//reset archived flag

    rc=_dos_setfileattr(openfn,attr);
    if (rc)
    {
        printf("%s:%s:_dos_setfileattr failed,rc=%d,errno=%d\n",pgmid,ver,rc,errno);
        uexit (4);                                              //~v742R~
    }
#else
  #ifdef W32                                                       //~v826I~
//** w95                                                           //~v826I~
//  UCHAR rattr;                                                   //~v91jR~
    ULONG rattr;                                                   //~v91jI~
//*********************                                            //~v826I~
    uattrib(openfn,0,FILE_ARCHIVED,&rattr);                        //~v826I~
    return;                                                        //~v826I~
  #else                                                            //~v826I~
//** os/2
    APIRET apiret;
    FILESTATUS3 filestatus3;
//*********************

    memset((PVOID)(&filestatus3),0,sizeof(FILESTATUS3));
    filestatus3.attrFile=(fstat3.attrFile&~FILE_ARCHIVED);//reset archived flag

    apiret=DosSetPathInfo(openfn,FIL_STANDARD,
                            (PVOID)(&filestatus3),sizeof(FILESTATUS3),
                            DSPI_WRTTHRU);
    if (apiret)
    {
        printf("%s:%s:DosSetPathInfo failed,rc=%d\n",pgmid,ver,apiret);
        uexit (4);                                              //~v742R~
    }
  #endif                                                           //~v826I~
#endif
#endif  //!UNX                                                     //~v907I~
    return;
}//archoff
//**********************************************************************
//* get pathname                    v5.7a
//* input   :input file spec
//*         :copy option(1:copy to inputfname)                     //~v822I~
//* output  :inputfname contain pathname
//* return  :pathname length
//**********************************************************************
int getpath(char* parmfname,int copyopt)                           //~v822R~
{
    int pathlen;
//***********************
  if (copyopt)                                                     //~v822I~
    strcpy(inputfname,parmfname);         //get path name and file name
//  for (pathlen=(int)strlen(inputfname);pathlen>=0;pathlen--)       //get path name only//~v805R~
//  {                                                              //~v805R~
//      if ( *(inputfname+pathlen)=='\\'                           //~v805R~
//          ||*(inputfname+pathlen)==':') //v3.9a                  //~v805R~
//      { pathlen++;                                               //~v805R~
//          break;                                                 //~v805R~
//      }                                                          //~v805R~
//  }                                                              //~v805R~
//  pathlen=PATHLEN(inputfname);                                   //~v822R~
    pathlen=PATHLEN(parmfname);                                    //~v822I~
    if (pathlen<0)  //no \ or : found                              //~v806R~
        pathlen=0;                                                 //~v806R~
    if (!pathlen)  //no \ or : found                               //~v821I~
        if (strlen(parmfname)>=2)                                  //~v821I~
            if (*(parmfname+1)==':')                               //~v821R~
                pathlen=2;                                         //~v821I~
    return pathlen;
}//getpath

//**********************************************************************//~v74jI~
//* date compare              940609a                           //~v74jI~
//* return 0:not match with parameter condition                 //~v74jI~
//*        1:    match with parameter condition                 //~v74jI~
//**********************************************************************//~v74jI~
int fdatechkmain(void)                                          //~v74jI~
{                                                               //~v74jI~
  int select,select2;   //selected result                       //~v74jI~
int fdatechk(int Pcondcode,USHORT Pconddate,USHORT Pcondtime);  //~v74jM~
//****************                                              //~v74jI~
    select=fdatechk(condcode,conddate,condtime);                //~v74jI~
    if (!UCBITCHK(swsw2,SW2ANDDATE|SW2ORDATE))                  //~v74jI~
        return select;                                          //~v74jI~
    select2=fdatechk(condcode2,conddate2,condtime2);            //~v74jI~
    if (UCBITCHK(swsw2,SW2ANDDATE))                             //~v74jI~
        select=(select && select2);                             //~v74jI~
    else                                                        //~v74jI~
        select=(select || select2);                             //~v74jI~
    return select;                                              //~v74jI~
}//end of fdatechk                                              //~v74jI~
                                                                //~v74jI~
//**********************************************************************
//* date compare              940609a
//* return 0:not match with parameter condition
//*        1:    match with parameter condition
//**********************************************************************
int fdatechk(int Pcondcode,USHORT Pconddate,USHORT Pcondtime)   //~v74jR~
{
  int rc;       //time stamp compare result
  int select=0;   //selected result                                //~v965R~
  int date1,time1;//time stamp of file //v7.0r
//****************
    
//  date1=*((USHORT*)(void*)(&(fstat3.fdateLastWrite)));//v7.0r    //~v978R~
    date1=FDATE2USHORT(fstat3.fdateLastWrite);//v7.0r              //~v978I~
//  time1=*((USHORT*)(void*)(&(fstat3.ftimeLastWrite)))&0xffe0;//drop second//v7.0r//~v978R~
    time1=FTIME2USHORT(fstat3.ftimeLastWrite)&0xffe0;//drop second//v7.0r//~v978I~
    
    rc=date1-Pconddate;                     //v7.0r             //~v74jR~
    if (!rc)            //date equal    
        if (Pcondtime)  //time specified                        //~v74jR~
          rc=time1-Pcondtime;        //0 if eq //v7.0r          //~v74jR~
            
    switch (Pcondcode)                                          //~v74jR~
    {
    case 1:         //eq
        select=!rc;
        break;
    case 2:         //ne
        select=rc;
        break;
    case 3:         //gt
        select=(rc>0);
        break;
    case 4:         //ge
        select=(rc>=0);
        break;
    case 5:         //lt
        select=(rc<0);
        break;
    case 6:         //le
        select=(rc<=0);
        break;
    }
    return select;
}//end of fdatechk

//**********************************************************************
//* get 1 byte input char       av4.2
//**********************************************************************
int getinput(void)
{
  int readc;                    //v5.8a
  char *pc;                                                        //~v91uR~
#ifdef UTF8UCS2                                                    //~v928I~
  	int vhexlen=0;                                                   //~v928I~//~v965R~
#endif                                                             //~v928I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
	int swebcfile;                                                 //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
	int rcv=0,reslen;                                              //~v96eR~
    int vlensz;                                                    //~v96iI~
//****************
    readcount++;                //v6.6a
    if (inputrangeopt==2)       //input offset range parameter v7.21a
        if (readcount>inputrange2) //already send end range byte v7.21a v7.25r
            return EOF;             //v7.21a
//**** input data buff process v5.8a *****
    if (phase2sw && databuffsw)     //input data from saved buff at phase2
    {                                                              //~v91nI~
//      if ((ULONG)databuffc>=(ULONG)databuffl) //reached to last v6.4r v7.0r//~v968R~
        if ((ULPTR)databuffc>=(ULPTR)databuffl) //reached to last v6.4r v7.0r//~v968I~
            return EOF;
        else
//dv6.3     return *databuffc++;    //return saved data
            return (UCHAR)(*databuffc++);   //return saved data v6.3a
    }                                                              //~v91nI~
//**************************** v5.8a *****                         //~v91rI~
	swebcfile=UCBITCHK(swsw4,SW4EBCCFG);                           //~v956I~
//  if (vhexlinech)  //vhex mode                                   //~v91rR~//~v956R~
  if (!vfmt)	//not recfm=V                                      //~v96eI~
    if (vhexlinech && !swebcfile)  //vhex mode                     //~v956I~
    {                                                              //~v91rI~
        if (vhexrcount==vhexrmax)                                  //~v91rI~
        {                                                          //~v91rI~
            if (!fgets(vhexlinech,MAXTEXTINPLINESZ,input)) //read char line//~v91uR~
            	return EOF;                                        //~v91rI~
            vhexreadline++;                                        //~v91rI~
//          *(vhexlinech+MAXTEXTINPLINESZ-1)=0;                    //~v91uR~
//          vhexrmax=(int)strlen(vhexlinech);                      //~v91tR~
            pc=memchr(vhexlinech,'\n',MAXTEXTINPLINESZ);           //~v91uR~
            if (pc)                                                //~v91uR~
//            	vhexrmax=(int)((ULONG)(pc+1)-(ULONG)vhexlinech);   //~v91uR~//~v968R~
            	vhexrmax=(int)((ULPTR)(pc+1)-(ULPTR)vhexlinech);   //~v968I~
//          if (rmax==0)                                           //~v91tR~
//              return EOF;                                        //~v91tR~
//          if (*(vhexlinech+vhexrmax-1)!='\n')	//too long line    //~v91tR~
            else    	//too long line                            //~v91uR~
            	uerrexit("\ntoo long line at line %d,max is %d",0,   //~v91rI~//~v956R~
							vhexreadline,MAXTEXTINPLINESZ);        //~v91rR~
            if (*vhexlinech==VHEXDATALINEID)	//data line?(not title/exclude)//~v91rR~
            {                                                      //~v91rI~
            	vhexreadline++;                                    //~v91rI~
#ifdef UTF8UCS2                                                    //~v928I~
              if ((swsw4 & SW4VHEXMODEU))	//hexline is by unicode by /WN=nU parm//~v928I~
              {                                                    //~v928I~
UTRACED("xpinp read char",vhexlinech,vhexrmax);                    //~v928I~
                if (!fgets(vhexlinex1,MAXTEXTINPLINESZ,input))     //~v928R~
	            	uerrexit("\ninput fmt err for vhex mode at line %d",0,//~v928I~
								vhexreadline);                     //~v928I~
    	        pc=memchr(vhexlinex1,'\n',MAXTEXTINPLINESZ);       //~v928I~
            	if (pc)                                            //~v928I~
//            		vhexlen=(int)((ULONG)(pc+1)-(ULONG)vhexlinex1);//~v928I~//~v968R~
            		vhexlen=(int)((ULPTR)(pc+1)-(ULPTR)vhexlinex1);//~v968I~
            	else    	//too long line                        //~v928I~
            		uerrexit("too long line at line %d,max is %d",0,//~v928I~
								vhexreadline,MAXTEXTINPLINESZ);    //~v928I~
UTRACED("xpinp read vhex1",vhexlinex1,vhexlen);                    //~v928R~
            	vhexreadline++;                                    //~v928I~
                if (!fgets(vhexlinex2,vhexlen+1,input)||*(vhexlinex2+vhexlen-1)!='\n') //read char line//~v928I~
	            	uerrexit("\ninput fmt err for vhex mode at line %d",0,//~v928I~
								vhexreadline);                     //~v928I~
                Gutf8vhexlen=vhexlen-1;	//notify to xppf(ignore top byte vhex id)//~v928R~
UTRACED("xpinp read vhex2",vhexlinex2,vhexlen);                    //~v928R~
              }                                                    //~v928I~
              else                                                 //~v928I~
#endif                                                             //~v928I~
              {                                                    //~v928I~
//              if (!fgets(vhexlinex1,MAXTEXTINPLINESZ-1,input)) //read char line//~v91uR~
#ifdef AAA                                                         //~v943I~
                if (!fgets(vhexlinex1,vhexrmax+1,input)||*(vhexlinex1+vhexrmax-1)!='\n') //read char line//~v91uR~
#else                                                              //~v943I~
                if (!fgets(vhexlinex1,vhexrmax+1,input)) //read char line//~v943I~
#endif                                                             //~v943I~
	            	uerrexit("\ninput fmt err for vhex mode at line %d",0,//~v928R~
								vhexreadline);                     //~v91rR~
//          	vhexreadline++;                                    //~v91rI~//~v956R~
#ifdef AAA                                                         //~v943I~
#else                                                              //~v943I~
    	        pc=memchr(vhexlinex1,'\n',MAXTEXTINPLINESZ);       //~v943I~
            	if (pc)                                            //~v943I~
//            		vhexlen=(int)((ULONG)(pc+1)-(ULONG)vhexlinex1);//~v943I~//~v968R~
            		vhexlen=(int)((ULPTR)(pc+1)-(ULPTR)vhexlinex1);//~v968I~
            	else    	//too long line                        //~v943I~
            		uerrexit("too long line at line %d,max is %d",0,//~v943I~
								vhexreadline,MAXTEXTINPLINESZ);    //~v943I~
                Gvhexlinelenhhex=vhexlen;                          //~v96iI~
#endif                                                             //~v943I~
            	vhexreadline++;                                    //~v943I~
//              if (!fgets(vhexlinex2,MAXTEXTINPLINESZ-1,input)) //read char line//~v91uR~
#ifdef AAA                                                         //~v943I~
                if (!fgets(vhexlinex2,vhexrmax+1,input)||*(vhexlinex2+vhexrmax-1)!='\n') //read char line//~v91uR~
#else                                                              //~v943I~
                if (!fgets(vhexlinex2,vhexlen+1,input)||*(vhexlinex2+vhexlen-1)!='\n') //read char line//~v943I~
#endif                                                             //~v943I~
	            	uerrexit("\ninput fmt err for vhex mode at line %d",0,//~v928R~
								vhexreadline);                     //~v91rR~
              }                                                    //~v928I~
            }                                                      //~v91rI~
            vhexrcount=1; 	//skip line id column                  //~v91rI~
            Gvhexlineoffs=vhexrcount;	//hex line offset          //~v91rR~
        }                                                          //~v91rI~
        readc=(*(vhexlinech+vhexrcount++)); //v5.8a                //~v91rI~
        return readc;                           //v5.8r            //~v91rI~
    }                                                              //~v91rI~
//**************************** v5.8a *****
//#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~//~v956R~
//    swebcfile=UCBITCHK(swsw4,SW4EBCCFG);                           //~v941R~//~v956R~
//#endif          //EBCDIC dbcs support                              //~v941I~//~v956R~
  if (!vfmt)	//not recfm=V                                      //~v96eI~
    if (!dumpmode)                                                 //~v892R~
    {                                                              //~v892R~
      if (Snextsavedsw)     //saved after CR                       //~v896R~
      {                                                            //~v896R~
            readc=Snextgetc;    //saved at previos CR              //~v896R~
            Snextsavedsw=0;     //no more saved                    //~v896R~
      }                                                            //~v896R~
      else                                                         //~v896I~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
      if (swebcfile)                                               //~v941I~
        readc=xpebc_fgetc(0,input);                                //~v941I~
      else                                                         //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
        readc=fgetc(input); //from file v5.8a                      //~v892R~
//      if (readc==CR)                                             //~v896I~//~v953R~
        if (readc==CR                                              //~v953I~
        &&  !nocrlfsw	//cr/lf is unprintable data for record mode//~v97vI~
        &&  (!swebcfile || (Gxpotheropt & GOO_ASCEOL))             //~v953R~
        )                                                          //~v953I~
        {                                                          //~v91nI~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
            if ((Snextgetc=UWHICH(swebcfile,xpebc_fgetc(0,input),fgetc(input)))==CRLF) //pre read after CR//~v941I~
#else                                                              //~v941I~
            if ((Snextgetc=fgetc(input))==CRLF) //pre read after CR//~v896I~
#endif          //EBCDIC dbcs support                              //~v941I~
                readc=CRLF;             //ignore CR but return LF for cr+lf//~v896I~
            else                                                   //~v896I~
                Snextsavedsw=1;     //no more saved                //~v896I~
        }                                                          //~v91nI~
        if (readc!=EOF)                                            //~v892R~
            if (databuffsw)             //buff mode v5.8a          //~v892R~
                *databuffc++=(UCHAR)readc;  //save input data v5.8a//~v892R~
        return readc;       //v5.8a                                //~v892R~
    }                                                              //~v892R~
//*binary mode
	UTRACEP("xpinp rcount=%d,rmax=%d\n",rcount,rmax);              //~v96iI~
    if (rcount==rmax)
    {
//v5.8d breakchk();
        rcount=0;
//      rmax=(INT)fread(rbuff,1,(UINT)rmax,input);  //read 1 block v7.0r//~v894R~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
      if (swebcfile)                                               //~v941I~
      {                                                            //~v96eI~
        rmax=(INT)xpebc_fread(0,rbuff,RBUFFSZ,input); //read 1 block v7.0r//~v941I~
        if (rmax==EOF) 	//recordszV is set at epebc_fread          //~v96eI~
            return EOF;                                            //~v96eI~
      }                                                            //~v96eI~
      else                                                         //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
      if (vfmt)                                                    //~v96eI~
      {                                                            //~v96eI~
         rcv=sub1freadV(0,rbuff,RBUFFSZ,input,&rmax,&reslen); //rmax<=RBUFFSZ//~v96eR~
         if (rcv==EOF)                                             //~v96eR~
            return EOF;                                            //~v96eI~
         recordszV=rmax+reslen;	//EOL pos                          //~v96eI~
         vlensz=0;                                                 //~v96iI~
		 Geolprintcol=0;                                           //~v96iI~
         if (!reslen)                                              //~v96iI~
         	if (eolprintfmt)                                       //~v96iR~
            {                                                      //~v96iI~
         		vlensz=sprintf(rbuff+rmax,eolprintfmt,recordszV0); //~v96iR~
                recordszV+=vlensz;                                 //~v96iR~
                rmax+=vlensz;                                      //~v96iI~
            }                                                      //~v96iI~
        recordszVEOL=recordszV0+vlensz;                            //~v96iI~
		UTRACEP("xpinp freadV recordszV=%d,rmax=%d,reslen=%d,recordszVEOL=%d\n",recordszV,rmax,reslen,recordszVEOL);//~v96iR~
      }                                                            //~v96eI~
      else                                                         //~v96eI~
      {                                                            //~v96eI~
        rmax=(INT)fread(rbuff,1,RBUFFSZ,input); //read 1 block v7.0r//~v894I~
        if (rmax==0)
        {
//          rmax=RBUFFSZ;                                          //~v894R~
            return EOF; 
        }
      }                                                            //~v96eI~
    }
  if (rmax>0)   //not lrecl=0                                      //~v96eI~
  {                                                                //~v96eI~
#ifdef UTF8EBCD //EBCDIC dbcs support                              //~v941I~
  if (swebcfile)                                                   //~v941I~
    readc=xpebc_freadnext(0,rcount++);	//set ctype also           //~v941I~
  else                                                             //~v941I~
#endif          //EBCDIC dbcs support                              //~v941I~
    readc=(*(rbuff+rcount++)); //v5.8a
    if (databuffsw)             //buff mode v5.8a
        *databuffc++=(UCHAR)readc;      //save for later input v5.8a
  }                                                                //~v96eI~
  else                                                             //~v96eI~
  {                                                                //~v96iI~
    readc=XPGIRC_VLEN0;                                                      //~v96eI~//~v96iR~
    readcount--;                                                   //~v96iI~
  }                                                                //~v96iI~
    return readc;                           //v5.8r
}//end of getinput
//**********************************************************************
//*case insensitive string compare sub v5.3a
//**********************************************************************
//int  cistrcmp(char *str1,char *str2)                          //~v742R~
//{                                                             //~v742R~
//    strcpy(uppercnv1,str1);                                   //~v742R~
//    strcpy(uppercnv2,str2);                                   //~v742R~
//  strupr(uppercnv1);      //upper case                        //~v742R~
//  strupr(uppercnv2);      //upper case                        //~v742R~
//  return strcmp(uppercnv1,uppercnv2); //compare result        //~v742R~
//}//cistrcmp                                                   //~v742R~

//**********************************************************************
//*confirm file print yes/no                         v6.1r
//* parm : file name with path name
//* r.c  : 0:reply No, 1:reply Yes
//**********************************************************************
int  fileconfirm(char *filename,USHORT Pfdate,USHORT Pftime)    //~v74kR~
{
  static char Sfirstconfirm=1;  //first confirm sw v5.0a           //~v802R~
  static char Sendall=0;          //no more print file             //~v91nR~
  static char Syesall=0;          //all replyed                    //~v91nR~
                                                                   //~v802I~
    int reply=0;              //confirmation reply         v3.7a v5.2r
//  char wk[16];                                                   //~v898R~
    char wk[20];                                                   //~v898I~
    FILEFINDBUF3 wkfstat3={0};     //for time stamp get            //~v966R~
    ULPTR  ulp;                                                    //~v96bR~
    USHORT *pus;                                                   //~v96bI~
//****************
//restart file control v6.2a v6.8d
//  if (pagefilesw==1)      //restart file specified
//  {
//      if (stricmp(filename,pagefile)) //unmutched filename    //~v742R~
//          return 0;               //bypass print
//      pagefilesw=2;               //resume file
//  }
//restart file control v6.2a v6.8d

    if (!swconfirm) //question to operator option v6.2a
        return 1;   //select                    v6.2a
    if (Sendall) //reject print replyed once                       //~v802I~
        return 0;   //not selected                                 //~v802I~
    if (UCBITCHK(swsw1,SW1NOKBD))                               //~v74aI~
    {                                                           //~v74aI~
        swconfirm=0;                                            //~v74aR~
        return 1;   //select                    v6.2a           //~v74aI~
    }                                                           //~v74aI~
//  *((USHORT*)(void*)(&(wkfstat3.fdateLastWrite)))=Pfdate;        //~v96bR~
    ulp=(ULPTR)(&(wkfstat3.fdateLastWrite));                       //~v96bR~
    pus=(USHORT*)ulp;                                              //~v96bR~
    *pus=Pfdate;                                                   //~v96bI~
//  *((USHORT*)(void*)(&(wkfstat3.ftimeLastWrite)))=Pftime;        //~v96bR~
    ulp=(ULPTR)(&(wkfstat3.ftimeLastWrite));                       //~v96bR~
    pus=(USHORT*)ulp;                                              //~v96bI~
    *pus=Pftime;                                                   //~v96bI~
    sprintf(wk,"%04d-%02d-%02d %02d:%02d",                         //~v898R~
//        wkfstat3.fdateLastWrite.year+80,                         //~v898R~
          wkfstat3.fdateLastWrite.year+1980,                       //~v898R~
          wkfstat3.fdateLastWrite.month,                        //~v74kI~
          wkfstat3.fdateLastWrite.day,                          //~v74kI~
          wkfstat3.ftimeLastWrite.hours,                        //~v74kI~
          wkfstat3.ftimeLastWrite.minutes);                     //~v74kI~
    while (reply==reply)//until y/n reply   //v7.0r
    {
        if (Sfirstconfirm)          //first confirm sw v5.0a       //~v802I~
        {                                                          //~v802I~
            if (dbcsenv)    //DBCS mode v4.9a                      //~v802I~
//              fprintf(stderr,"\n印刷確認,Y(印刷)/N(取消)/A(以後全て)/E(以後取消)のどれか入力して下さい\n//~v970R~
                fprintf(stderr,"\n印刷確認,Y(印刷)/N(取消)/A(以後全て)/E(以後取消)/Esc(キャンセル)のどれか入力して下さい\n\
   (煩雑ならば Esc で中断し %cNc オプション で 再実行して下さい)\n",//~v907R~
					CMDFLAG_PREFIX);                               //~v907I~
            else        //v6.0a                                    //~v802I~
//              fprintf(stderr,"\nPrint confirmation,Enter one of \"Y\"es,\"N\"o,\"A\"ll,\"E\"(nd-up)\n//~v970R~
                fprintf(stderr,"\nPrint confirmation,Enter one of \"Y\"es,\"N\"o,\"A\"ll,\"E\"(nd-up) or Esc(Cancel).\n\
   (You may use %cNc option to skip confirmation)\n",              //~v907R~
					CMDFLAG_PREFIX);                               //~v907I~
            Sfirstconfirm=0;            //first confirm sw v5.0a   //~v802R~
        }                                                          //~v802I~
#ifdef W32UNICODE                                                  //~v990I~
        uerrfprintfutf(0,stderr,"%s (%s) ? -",0,                   //~v990I~
                    filename,wk);//v6.0r                           //~v990I~
#else                                                              //~v990I~
        if (dbcsenv)    //DBCS mode v4.9a
            fprintf(stderr,"%s (%s) ? -",                          //~v802R~
                    filename,wk);//v6.0r                        //~v74kI~
        else            //SBCS mode v4.9a   
            fprintf(stderr,"%s (%s) ? -",                          //~v802R~
                    filename,wk);//v6.0r                        //~v74kI~
#endif                                                             //~v990I~
//      if (firstconfirm)           //first confirm sw v5.0a       //~v764R~
//      {                                                          //~v764R~
//          if (dbcsenv)    //DBCS mode v4.9a                      //~v764R~
//              fprintf(stderr,"         (煩雑ならば Esc で中断し /Nc オプション で 再実行して下さい)\n");//v6.0r//~v764R~
//          else        //v6.0a                                    //~v764R~
//              fprintf(stderr,"         (You may use /Nc option after stopping by Esc key if you want)\n");//v6.0a//~v764R~
//          firstconfirm=0;         //first confirm sw v5.0a       //~v764R~
//      }                                                          //~v764R~
        fflush(0);                                                 //~v764R~
    if (Syesall) //already replyed all                             //~v80aI~
    {                                                              //~v80aI~
        reply='Y';                                                 //~v80aI~
        fprintf(stderr,"Y (All)\n");                               //~v80aI~
    }                                                              //~v80aI~
    else                                                           //~v80aI~
    {                                                              //~v80aI~
        reply=(kbdinp(_KEYBRD_READ)&255);   //v5.2a
        escstopmsg(reply);                  //v6.0a
//      printf("%c\n",reply);                                      //~v80aR~
        if (!isalnum(reply))                                       //~v825I~
            reply='?';                                             //~v825I~
        fprintf(stderr,"%c\n",reply);                              //~v80aI~
    }                                                              //~v80aI~
        if (toupper(reply)=='N') //v5.2r
        {
//          if (dbcsenv)    //DBCS mode v4.9a                      //~v764R~
//              printf("%s:%s:\"%s\"のプリントは取り消されました.\n",pgmid,ver,filename);//v4.9a//~v764R~
//          else            //SBCS mode v4.9a                      //~v764R~
//              printf("%s:%s:print skipped for \"%s\".\n",pgmid,ver,filename);//~v764R~
            if (pagefilesw==2)      //restart file specified v6.2a
                pagefilesw=3;       //ignore page range v6.2a
            return 0; //continue to next file(return with input=NULL)
        }
        if (toupper(reply)=='Y') //v5.2r
            break;
        if (toupper(reply)=='A') //v5.2r                           //~v764I~
        {                                                          //~v764I~
//          swconfirm=0;    //no more confirmation                 //~v80aR~
            Syesall=1;      //no more confirmation                 //~v80aI~
            break;                                                 //~v764I~
        }                                                          //~v764I~
        if (toupper(reply)=='E') //v5.2r                           //~v802I~
        {                                                          //~v802I~
            Sendall=1;    //reject after this                      //~v802I~
            return 0;                                              //~v802I~
        }                                                          //~v802I~
    }//infinite loop
    return 1;
}//fileconfirm
//**********************************************************************//~v909I~
//*filename compare                                                //~v909I~
//**********************************************************************//~v909I~
int  xpfnmcomp(char *fnm1,char *fnm2)                              //~v909I~
{                                                                  //~v909I~
#ifdef UNX                                                         //~v909I~
    return strcmp(fnm1,fnm2);                                      //~v909I~
#else                                                              //~v909I~
    return stricmp(fnm1,fnm2);                                     //~v909I~
#endif                                                             //~v909I~
}//xpfnmcomp                                                       //~v909I~
//**********************************************************************//~v91kI~
//*parse HeaderFilename and PrintFileName                          //~v91kI~
//* specification fmt "<headerfilename>printfilename"              //~v91kI~
//**********************************************************************//~v91kI~
char *xpparsehdrfnm(char *Pfnm)                                    //~v91kI~
{                                                                  //~v91kI~
	char *pc;                                                      //~v91kI~
    int len;                                                       //~v91kI~
static char *Shdrfnm=0;                                            //~v91kI~
//*******************                                              //~v91kI~
    Shdrfnmtype=0;                                                 //~v91nI~
	if (*Pfnm!=HDRFNM_PREFIX)                                      //~v91kI~
    	return Pfnm;		//normal filename specification        //~v91kI~
    Shdrfnmtype=HDRFNM_PREFIX;  //id of no "*" on hdr filename     //~v91nI~
    pc=strchr(Pfnm,HDRFNM_POSTFIX);                                //~v91kI~
    if (!pc)                                                       //~v91kI~
    	uerrexit("filename specification err(%s)",0,               //~v91kI~
        			Pfnm);                                         //~v91kI~
//  len=(int)((ULONG)pc-(ULONG)Pfnm-1);                            //~v91kI~//~v968R~
    len=(int)((ULPTR)pc-(ULPTR)Pfnm-1);                            //~v968I~
    if (!Shdrfnm)                                                  //~v91kI~
    	Shdrfnm=malloc(_MAX_PATH+1);                               //~v91kI~
    if (len>_MAX_PATH)                                             //~v91kI~
    	uerrexit("Too long filename specification err(%s)",0,      //~v91kI~
        			Pfnm);                                         //~v91kI~
    memcpy(Shdrfnm,Pfnm+1,(UINT)len);  //hdr filename              //~v91kR~
    *(Shdrfnm+len)=0;                                              //~v91kR~
    Ghdrfnm=Shdrfnm;                                               //~v91kI~
    return pc+1;	//print filename                               //~v91kI~
}//xpparsehdrfnm                                                   //~v91kR~
