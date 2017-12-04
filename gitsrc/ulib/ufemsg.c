//*CID://+v6N1R~:                             update#=   80;       //+v6N1R~
//*************************************************************
//*ufemsg.c                                                        //~v036R~
//*************************************************************//~4C18I~
//v6N1:171203 (Bug)chk by xuerpck                                  //+v6N1I~
//v6Hj:170119 bypass toolong errmsg at xe term                     //~v6HjI~
//v6Hf:170117 (Win)change errmsg for longname(move filename at end)//~v6HfI~
//v6H9:170109 (Win)del longname using \\?\ prefix(path max is 32767) and Unicode API because move to shortpath dir could not delete dir/file name longer >=260.//~v6H1I~
//v6H1:161231 filename >_MAX_PATH occurse when moved directory on xe(native cmd issue error fo5r xcopy /move)//~v6H1R~
//            and it cause fpath area overflow then 0c4            //~v6H1R~
//v6B7:160121 errmsg for open err with errno=22(Invalid argument)  //~v6B7I~
//v6yg:150314 avoid \\.\ is displayed on errmsg                    //~v6ygI~
//v6xb:150111 add apierr with errno description                    //~v6xbI~
//v6km:130704 notfound msg --> dir exist but no file exist;for xcopy wildcard parm sepcified//~v6kmI~
//v6kg:130629 errno=5(ioerr) when symlink created by mklink /D(dir) to a file//~v6kgI~
//v6k8:130623 junction is link to dir,so issue errmsg for junction to file//~v6k8I~
//v6k6:130619 (BUG of v6hc)OSTYPE=6 for 2010 64bit                 //~v6k6I~
//v6hL:120917 chk and errmsg when too long fullpath                //~v6hLI~
//v6h3:120604 (WTL)ELOOP is defined on errno.h of vc2010(#ifdef VC10EXP)//~v6h3I~
//v6d7:120209 (SMB)adjust for target:Windows                       //~v6d7I~
//v62b:090724 (FTP:BUG) del dir confirm msg remains when member is file only(no dir member exist)//~v62bI~
//v5kq:070630 remote file compare support                          //~v5kqI~
//v5k0:061226 (LNX/WIN)largefile(>4GB) support                     //~v5k0I~
//v5d9:040530 (FTP)skip upload for r2r to bypass not found msg if downloaded no entry//~v5d9I~
//v5d8:040530 (FTP)hide temp filename for dir to file operation err mnsg//~v5d8I~
//v5d3:040529 (BUG)xmove cannot override same name file            //~v5d3I~
//v5cd:040425 xcopy support option to create src dir intarget dir. //~v5cdI~
//v5av:040112 (FTP)addtional errmsg for FTP like as UNX            //~v5avI~
//v59e:031103 ftp support(4 byte udirlist attr for ! UNX)          //~v59eI~
//v573:021009 (UNX)slink err msg bypass option(u#3)                //~v573I~
//v56s:020712 (UNX)allow to udirlist select non-reguler file       //~v56sI~
//v56g:020711 (UNX)ELOOP msg for lstat                             //~v56gI~
//v538:020322 (LNX)mdos disk support;mkdir rmdir;attrib            //~v538I~
//v379:000930 LINUX support(4 byte attr)                           //~v379I~
//v366:000927 LINUX support(display operation on permission errmsg)//~v366I~
//v351:000926 LINUX support(filename on permission err msg)        //~v351I~
//v329 000827:LINUX:add msg permission err                         //~v329I~
//v276:990813 chk wild card before rename                          //~v276I~
//v195:980920 display attr/size on xdd list                        //~v195I~
//v101:971009 long filename                                        //~v101I~
//            ufilevfat for DOS/W95                                //~v101I~
//v053:970107:gcc version(control by DPMI)                         //~v035I~
//            -compile err if DBCS containe \ in it.               //~v035I~
//v036:961016:new member for errmsg of ufile_.c                    //~v036I~
//v035:961016:_dos_open of ugetftime fail for dir,so use ufstat    //~v035I~
//            _dos_open of usetftime fail for dir,so chk it before open//~v035I~
//************************************************************* //~5617I~
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>                                                  //~v6d7I~
#ifdef VC10EXP                                                     //~v6h3I~
	#include <errno.h>	//ELOOP                                    //~v6h3I~
#endif                                                             //~v6h3I~
//*******************************************************
#ifdef DOS
#else
#endif

//*******************************************************
#include <ulib.h>
#include <ufile.h>                                                 //~v538I~
#include <ufemsg.h>                                                //~v036R~
#include <uerr.h>
#include <uedit.h>                                                 //~v195I~
#include <uedit2.h>                                                //~v195I~
#include <uque.h>                                                  //~v5avI~
#include <uftp.h>                                                  //~v5avI~
#include <ucalc2.h>                                                //~v5k0I~
#include <ufilew.h>                                                //~v6ygI~
#include <ustring.h>                                               //~v6H1I~
//*******************************************************
//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void ufemsg(void)                                                  //~v036R~
{
	return;
}
//****************************************************************//~5905M~
//ufilenotfound                                                 //~5909R~
//* file not found msg                                          //~5909R~
//*parm1:filename                                               //~5909R~
//*parm2:rc                                                     //~5909R~
//*retrn:rc                                                     //~5905M~
//****************************************************************//~5905M~
int ufilenotfound(UCHAR *Pfname,int Prc)                        //~5909R~
{                                                               //~5905M~
//********************                                          //~5905M~
//  uerrmsg("%s is not found",                                  //~5909I~//~v6HfR~
//  		"%s が見つかりません",                              //~5909I~//~v6HfR~
    uerrmsg("Not found:%s",                                        //~v6HfI~
    		"見つかりません:%s",                                   //~v6HfI~
//  		Pfname);                                            //~5909I~//~v6ygR~
    		STD_FNM(Pfname));                                      //~v6ygI~
	return Prc;                                                 //~5909R~
}//ufilenotfound                                                //~5909R~
//**************************************************************** //~v6kmI~
//udirlist with wildcard, other attr member exist                  //~v6kmR~
//**************************************************************** //~v6kmI~
int ufilenotfoundotherexist(char *Pfnm,int Prc)                    //~v6kmR~
{                                                                  //~v6kmI~
//********************                                             //~v6kmI~
	uerrmsg("%s; no corresponding attr member(other attribute entries exist)",//~v6kmR~
			"%s; 該当の属性のメンバーはありません(他の属性のメンバーはあります)",//~v6kmR~
//  		Pfnm);                                                 //~v6kmR~//~v6ygR~
    		STD_FNM(Pfnm));                                        //~v6ygI~
	return Prc;                                                    //~v6kmI~
}//ufilenotfoundbutdirfound                                        //~v6kmI~
                                                                //~5905M~
//****************************************************************//~5909I~
//ufilepatherr                                                  //~5909I~
//* path err msg                                                //~5909I~
//*parm1:filename                                               //~5909I~
//*parm2:rc                                                     //~5909I~
//*retrn:rc                                                     //~5909I~
//****************************************************************//~5909I~
int ufilepatherr(UCHAR *Ppathname,int Prc)                      //~5909I~
{                                                               //~5909I~
//********************                                          //~5909I~
//	uerrmsg("%s is path err",                                   //~5909I~//~v6HfR~
//			"%s の経路エラー",                                  //~5909R~//~v6HfR~
  	uerrmsg("path err:%s",                                         //~v6HfI~
			"経路エラー:%s",                                       //~v6HfI~
//  		Ppathname);                                         //~5909I~//~v6ygR~
    		STD_FNM(Ppathname));                                   //~v6ygI~
	return Prc;                                                 //~5909I~
}//ufilepatherr                                                 //~5909I~
                                                                //~5909I~
//****************************************************************//~5909I~
//ufileapierr                                                   //~5909I~
//* file api r.c msg                                            //~5909I~
//*parm1:apiname                                                //~5909I~
//*parm2:filename                                               //~5909I~
//*parm3:rc                                                     //~5909I~
//*retrn:rc                                                     //~5909I~
//****************************************************************//~5909I~
int ufileapierr(UCHAR *Papiname,UCHAR *Pfname,int Papirc)       //~5909I~
{                                                               //~5909I~
//********************                                          //~5909I~
//  uerrmsg("%s failed for %s,rc=%d",0,                         //~5917R~//~v6HfR~
    uerrmsg("%s failed rc=%d:%s",0,                                //~v6HfI~
//  		Papiname,Pfname,Papirc);                            //~5917R~//~v6ygR~
//  		Papiname,STD_FNM(Pfname),Papirc);                      //~v6ygI~//~v6HfR~
    		Papiname,Papirc,STD_FNM(Pfname));                      //~v6HfI~
	return Papirc;                                              //~5909I~
}//ufileapierr                                                  //~5909I~
//**************************************************************** //~v6xbI~
//ufileapierr_str                                                  //~v6xbI~
//**************************************************************** //~v6xbI~
int ufileapierr_str(UCHAR *Papiname,UCHAR *Pfname,int Perrno)      //~v6xbI~
{                                                                  //~v6xbI~
//********************                                             //~v6xbI~
	uerrmsg("%s failed for %s,rc=%d(%s)",0,                        //~v6xbI~
//  		Papiname,Pfname,Perrno,strerror(Perrno));              //~v6xbR~//~v6ygR~
    		Papiname,STD_FNM(Pfname),Perrno,strerror(Perrno));     //~v6ygI~
	return Perrno;                                                 //~v6xbI~
}//ufileapierr_str                                                 //~v6xbI~
                                                                //~5909I~
//****************************************************************//~5B12I~
//ufilerdelpath                                                 //~5B12I~
//* cur dir is on the delete path msg                           //~5B12I~
//*parm1:filename                                               //~5B12I~
//*parm2:return code                                            //~5B12I~
//*retrn:rc                                                     //~5B12I~
//****************************************************************//~5B12I~
int ufiledelpath(UCHAR *Pfname,int Prc)                         //~5B12I~
{                                                               //~5B12I~
//********************                                          //~5B12I~
	uerrmsg("Cur dir is on the path %s",                        //~5B12I~
			"現行ディレクトリーが 経路 %s 上にあります",        //~5B12I~
//  		Pfname);                                            //~5B12I~//~v6ygR~
    		STD_FNM(Pfname));                                      //~v6ygI~
	return Prc;                                                 //~5B12I~
}//ufiledelpath                                                 //~5B12I~
                                                                //~5B12I~
//****************************************************************//~5909I~
//ufilereadonly                                                 //~5909I~
//* readonly msg                                                //~5909I~
//*parm1:filename                                               //~5909I~
//*parm2:return code                                            //~5909I~
//*retrn:rc                                                     //~5909I~
//****************************************************************//~5909I~
int ufilereadonly(UCHAR *Pfname,int Prc)                        //~5909I~
{                                                               //~5909I~
//********************                                          //~5909I~
//  uerrmsg("%s is Read only",                                  //~5909I~//~v6HfR~
//  		"%s は読取専用",                                    //~v010R~//~v6HfR~
    uerrmsg("Read only:%s",                                        //~v6HfI~
    		"読取専用:%s",                                         //~v6HfI~
//  		Pfname);                                            //~5909I~//~v6ygR~
    		STD_FNM(Pfname));                                      //~v6ygI~
	return Prc;                                                 //~5909I~
}//ufilereadonly                                                //~5909I~
                                                                //~5909I~
//****************************************************************//~v010I~
//ufilereadonly2                                                //~v010I~
//* readonly msg for list read only                             //~v010I~
//*parm1:filename                                               //~v010I~
//*parm2:dir ot file id                                         //~v010I~
//*retrn:rc                                                     //~v010I~
//****************************************************************//~v010I~
void ufilereadonly2(UCHAR *Pfname,UCHAR Pid)                    //~v010I~
{                                                               //~v010I~
//********************                                          //~v010I~
	uerrmsg("RD-Only(%c):-%s",                                  //~v010I~
			"読専(%c):-%s",                                     //~v010I~
//  		Pid,Pfname);                                        //~v010I~//~v6ygR~
    		Pid,STD_FNM(Pfname));                                  //~v6ygI~
	return;                                                     //~v010I~
}//ufilereadonly2                                               //~v010I~
                                                                //~v010I~
//****************************************************************//~v010M~
//ufiledeleted                                                  //~v010I~
//* deleted msg                                                 //~v010I~
//*parm1:filename                                               //~v010M~
//*parm2:dir ot file id                                         //~v010M~
//*parm3:file size                                                 //~v195I~
//*parm4:file attr                                                 //~v195I~
//*retrn:rc                                                     //~v010M~
//****************************************************************//~v010M~
//#ifdef UNX                                                       //~v59eR~
//void ufiledeleted(UCHAR *Pfname,UCHAR Pid,long Psize,ULONG Pattr)//~v5k0R~
void ufiledeleted(UCHAR *Pfname,UCHAR Pid,FILESZT Psize,ULONG Pattr)//~v5k0I~
//#else  //!UNX                                                    //~v59eR~
//void ufiledeleted(UCHAR *Pfname,UCHAR Pid,long Psize,UCHAR Pattr)//~v59eR~
//#endif //!UNX                                                    //~v59eR~
{                                                               //~v010M~
    char editwk[16];                                               //~v195I~
    char attrwk[8];                                                //~v195I~
#ifdef UNX                                                         //~v379I~
    int efaopt;                                                    //~v379I~
#endif                                                             //~v379I~
//********************                                          //~v010M~
//if (Psize==-1)                                                   //~v5k0R~
  if (Psize==(FILESZT)(-1))                                        //~v5k0I~
	uerrmsg("Deleted(%c): %s",                                  //~v010I~
			"削除(%c): %s",                                     //~v010I~
//  		Pid,Pfname);                                        //~v010M~//~v6ygR~
    		Pid,STD_FNM(Pfname));                                  //~v6ygI~
  else                                                             //~v195I~
  {                                                                //~v195I~
//  unumedit((ULONG)Psize,"z,zzz,zzz,zz9",editwk);                 //~v5k0R~
    ufileeditsz(0,Psize,editwk);                                   //~v5k0R~
#ifdef UNX                                                         //~v538R~
	efaopt=UEFA_DIR|UEFA_SZ;		//set sz at last               //~v538R~
    if (MDOSDISKOK(Pfname))                                        //~v538R~
    	efaopt|=UEFA_MDOS;                                         //~v538R~
    ueditfattr(Pattr,attrwk,efaopt);		//set sz at last       //~v538R~
#else                                                              //~v538R~
    ueditfattr(Pattr,attrwk,UEFA_DIR|UEFA_SZ);		//set sz at last//~v195R~
#endif                                                             //~v538R~
	uerrmsg("Deleted: %s%s %s",                                    //~v195R~
			"削除: %s%s %s",                                       //~v195R~
//  		attrwk,editwk,Pfname);                                 //~v195R~//~v6ygR~
    		attrwk,editwk,STD_FNM(Pfname));                        //~v6ygI~
  }	                                                               //~v195I~
	return;                                                     //~v010M~
}//ufiledeleted                                                 //~v010I~
                                                                //~v010M~
//****************************************************************//~5909I~
//ufileshare                                                    //~5909I~
//* invarid share msg                                           //~5909I~
//*parm1:filename                                               //~5909I~
//*parm2:return code                                            //~5909I~
//*retrn:rc                                                     //~5909I~
//****************************************************************//~5909I~
int ufileshare(UCHAR *Pfname,int Prc)                           //~5909I~
{                                                               //~5909I~
//********************                                          //~5909I~
	uerrmsg("Sharing violation for %s",                         //~5909I~
			"%s に対する共用違反",                              //~5909I~
//  		Pfname);                                            //~5909I~//~v6ygR~
    		STD_FNM(Pfname));                                      //~v6ygI~
	return Prc;                                                 //~5909I~
}//ufileshare                                                   //~v010R~
                                                                //~5909I~
//****************************************************************//~5909I~
//ufileexist                                                    //~5909I~
//* already file exist                                          //~5910R~
//*parm1:filename                                               //~5909I~
//*parm2:return code                                            //~5909I~
//*retrn:rc                                                     //~5909I~
//****************************************************************//~5909I~
int ufileexist(UCHAR *Pfname,int Prc)                           //~5909I~
{                                                               //~5909I~
//********************                                          //~5909I~
//  uerrmsg("%s is already exist",                              //~5909I~//~v6HfR~
//  		"%s が既に存在する",                                //~5909I~//~v6HfR~
    uerrmsg("Already exist:%s",                                    //~v6HfI~
    		"既に存在する:%s",                                     //~v6HfI~
//  		Pfname);                                            //~5909I~//~v6ygR~
    		STD_FNM(Pfname));                                      //~v6ygI~
	return Prc;                                                 //~5909I~
}//ufileexist                                                   //~5909I~
                                                                //~5909I~
//**************************************************************** //~v5cdI~
//ufileexistcopy                                                   //~v5cdI~
//* already file exist required replace option                     //~v5cdI~
//*parm1:filename                                                  //~v5cdI~
//*parm2:return code                                               //~v5cdI~
//*retrn:rc                                                        //~v5cdI~
//**************************************************************** //~v5cdI~
int ufileexistcopy(UCHAR *Pfname,int Prc)                          //~v5cdI~
{                                                                  //~v5cdI~
//********************                                             //~v5cdI~
//  uerrmsg("%s is already exist,replace option required to override.",//~v5cdI~//~v6HfR~
//  		"%s が既に存在する、上書きするには置換オプションが必要。",//~v5cdI~//~v6HfR~
    uerrmsg("Already exist,replace option required to override:%s",//~v6HfI~
    		"既存、上書きするには置換オプションが必要:%s",         //~v6HfI~
//  		Pfname);                                               //~v5cdI~//~v6ygR~
    		STD_FNM(Pfname));                                      //~v6ygI~
	return Prc;                                                    //~v5cdI~
}//ufileexistcopy                                                  //~v5cdI~
                                                                   //~v5cdI~
//****************************************************************//~v052I~
//ufileexist2                                                   //~v052I~
//* already file exist in target dir                            //~v052I~
//*parm1:filename                                               //~v052I~
//*parm2:target dir                                             //~v052I~
//*parm3:return code                                            //~v052I~
//*retrn:rc                                                     //~v052I~
//****************************************************************//~v052I~
int ufileexist2(UCHAR *Pfname,UCHAR *Pdir,int Prc)              //~v052I~
{                                                               //~v052I~
//********************                                          //~v052I~
	uerrmsg("%s is already exist in %s",                        //~v052I~
			"%s が %s 内に既に存在する",                        //~v052I~
//  		Pfname,Pdir);                                       //~v052I~//~v6ygR~
    		STD_FNM(Pfname),STD_FNM(Pdir));                        //~v6ygI~
	return Prc;                                                 //~v052I~
}//ufileexist2                                                  //~v052I~
                                                                //~v052I~
//**************************************************************** //~v5d3I~
//ufileexistdir                                                    //~v5d3I~
//* already dir exist                                              //~v5d3I~
//*parm1:dirname                                                   //~v5d3I~
//*parm3:return code                                               //~v5d3I~
//*retrn:rc                                                        //~v5d3I~
//**************************************************************** //~v5d3I~
int ufileexistdir(UCHAR *Pdir,int Prc)                             //~v5d3I~
{                                                                  //~v5d3I~
//********************                                             //~v5d3I~
//  uerrmsg("Dir %s is already exist.",                            //~v5d3I~//~v6HfR~
//  		"Dir %s が既に存在する",                               //~v5d3R~//~v6HfR~
    uerrmsg("The dir is already exist:%s",                         //~v6HfI~
    		"Dir が既に存在する:%s",                               //~v6HfI~
//  		Pdir);                                                 //~v5d3I~//~v6ygR~
    		STD_FNM(Pdir));                                        //~v6ygI~
	return Prc;                                                    //~v5d3I~
}//ufileexistdir                                                   //~v5d3I~
                                                                   //~v5d3I~
//****************************************************************//~5910I~
//ufilenotdir                                                   //~5910I~
//* not dir msg                                                 //~5910I~
//*parm1:filename                                               //~5910I~
//*parm2:return code                                            //~5910I~
//*retrn:rc                                                     //~5910I~
//****************************************************************//~5910I~
int ufilenotdir(UCHAR *Pfname,int Prc)                          //~5910I~
{                                                               //~5910I~
//********************                                          //~5910I~
//  uerrmsg("%s is not a directory",                            //~5910I~//~v6HfR~
//  		"%s がディレクトリーでない",                        //~5910I~//~v6HfR~
    uerrmsg("Not a directory:%s",                                  //~v6HfI~
    		"ディレクトリーでない:%s",                             //~v6HfI~
//  		Pfname);                                            //~5910I~//~v6ygR~
    		STD_FNM(Pfname));                                      //~v6ygI~
	return Prc;                                                 //~5910I~
}//ufilenotdir                                                  //~5910I~
                                                                //~5910I~
//****************************************************************//~5910I~
//ufilediskfull                                                 //~5910I~
//* diskfull msg                                                //~5910I~
//*parm1:filename                                               //~5910I~
//*parm2:return code                                            //~5910I~
//*retrn:rc                                                     //~5910I~
//****************************************************************//~5910I~
int ufilediskfull(UCHAR *Pfname,int Prc)                        //~5910I~
{                                                               //~5910I~
//********************                                          //~5910I~
	uerrmsg("%c: is disk full",                                 //~5910R~
			"%c: にスペースがない",                             //~5910R~
			*Pfname);                                           //~5910I~
	return Prc;                                                 //~5910I~
}//ufilenotdir                                                  //~5910I~
                                                                //~5910I~
//****************************************************************//~v052I~
//ufilewildtarget                                               //~v052I~
//* wild card target                                            //~v052I~
//*parm1:return code                                               //~v276R~
//*retrn:rc                                                     //~v052I~
//****************************************************************//~v052I~
int ufilewildtarget(int Prc)                                    //~v052I~
{                                                               //~v052I~
//********************                                          //~v052I~
	uerrmsg("Wildcard taget is not supported",                  //~v052I~
			"宛先にワイルドカードはつかえません");              //~v052I~
	return Prc;                                                 //~v052I~
}//ufilewildtarget                                              //~v052I~
                                                                //~v052I~
//**************************************************************** //~v276I~
//ufilewildcarderr                                                 //~v276I~
//* wild card not supported                                        //~v276I~
//*parm2:return code                                               //~v276I~
//*retrn:rc                                                        //~v276I~
//**************************************************************** //~v276I~
int ufilewildcarderr(int Prc)                                      //~v276I~
{                                                                  //~v276I~
//********************                                             //~v276I~
	uerrmsg("Wildcard is not supported",                           //~v276I~
			"ワイルドカードはつかえません");                       //~v276I~
	return Prc;                                                    //~v276I~
}//ufilewildcarderr                                                //~v276I~
                                                                   //~v276I~
//**************************************************************** //~v276I~
//ufilewildpatherr                                                 //~v276I~
//* wild card not supported                                        //~v276I~
//*parm2:return code                                               //~v276I~
//*retrn:rc                                                        //~v276I~
//**************************************************************** //~v276I~
int ufilewildpatherr(int Prc)                                      //~v276I~
{                                                                  //~v276I~
//********************                                             //~v276I~
	uerrmsg("Wildcard Path is not supported",                      //~v276I~
			"ワイルドカードの経路はつかえません");                 //~v276I~
	return Prc;                                                    //~v276I~
}//ufilewildpatherr                                                //~v276I~
                                                                   //~v276I~
//****************************************************************//~5B25I~
//ufileroot                                                     //~5B25I~
//* err because root                                            //~5B25I~
//*parm1:fullpath name                                          //~5B25I~
//*parm2:rc                                                     //~5B25I~
//*retrn:rc                                                     //~5B25I~
//****************************************************************//~5B25I~
int ufileroot(char *Pfullpath,int Prc)                          //~5B25I~
{                                                               //~5B25I~
//********************                                          //~5B25I~
	uerrmsg("Root dir(%s) is not processed",                       //~v5d3R~
			"ルートは処理できません.(%s)",                      //~5B25R~
            Pfullpath);                                         //~5B25I~
    return Prc;                                                 //~5B25I~
}//ufileroot                                                    //~5B25I~
                                                                //~5B25I~
//****************************************************************//~5909I~
//ufileapierr2                                                  //~5909I~
//* file api r.c msg                                            //~5909I~
//*parm1:apiname                                                //~5909I~
//*parm2:filename1                                              //~5909I~
//*parm3:filename2                                              //~5909I~
//*parm4:rc                                                     //~5909I~
//*retrn:rc                                                     //~5909I~
//****************************************************************//~5909I~
int ufileapierr2(UCHAR *Papiname,UCHAR *Pfname1,UCHAR *Pfname2,int Papirc)//~5909I~
{                                                               //~5909I~
//********************                                          //~5909I~
	uerrmsg("%s failed for %s and %s,rc=%d",0,                  //~5909I~
//  		Papiname,Pfname1,Pfname2,Papirc);                   //~5909I~//~v6ygR~
    		Papiname,STD_FNM(Pfname1),STD_FNM(Pfname2),Papirc);    //~v6ygI~
	return Papirc;                                              //~5909I~
}//ufileapierr2                                                 //~5909I~
                                                                   //~v035I~
//**************************************************************** //~v035I~
//ufiledirna                                                       //~v035I~
//* not avail for dir                                              //~v053R~
//*parm1:filename                                                  //~v035I~
//*parm2:funcname                                                  //~v035I~
//*parm3:rc                                                        //~v035R~
//*retrn:rc                                                        //~v035I~
//**************************************************************** //~v035I~
int ufiledirna(UCHAR *Pfname,UCHAR *Pfunc,int Prc)                 //~v035R~
{                                                                  //~v035I~
//********************                                             //~v035I~
	uerrmsg("%s is directory,function %s is not available(rc=%d)", //~v053R~
//          "%s はディレクトリーです,%s は機能しません(rc=%d)",    //~v053R~
            "%s はディレクトリーです,%s は無効です(rc=%d)",        //~v053I~
//  		Pfname,Pfunc,Prc);                                     //~v035R~//~v6ygR~
    		STD_FNM(Pfname),Pfunc,Prc);                            //~v6ygI~
	return Prc;                                                    //~v035I~
}//ufiledirna                                                      //~v035I~
//**************************************************************** //~v5kqI~
//ufileerrdir                                                      //~v5kqI~
//* dir is invalid                                                 //~v5kqI~
//*retrn:rc                                                        //~v5kqI~
//**************************************************************** //~v5kqI~
int ufileerrdir(UCHAR *Pfname,int Prc)                             //~v5kqI~
{                                                                  //~v5kqI~
//********************                                             //~v5kqI~
//  uerrmsg("%s is directory",                                     //~v5kqI~//~v6HfR~
//          "%s はディレクトリーです",                             //~v5kqI~//~v6HfR~
    uerrmsg("It\'s a directory:%s",                                //~v6HfI~
            "ディレクトリーです:%s",                               //~v6HfI~
//			Pfname);                                               //~v5kqI~//~v6ygR~
  			STD_FNM(Pfname));                                      //~v6ygI~
	return Prc;                                                    //~v5kqI~
}//ufileerrdir                                                     //~v5kqI~
#ifdef OS2                                                         //~v101I~
#else                                                              //~v101I~
//**************************************************************** //~v101I~
//ufilenotvfat                                                     //~v101I~
//*parm :none                                                      //~v101I~
//*retrn:4                                                         //~v101I~
//**************************************************************** //~v101I~
int ufilenotvfat(void)                                             //~v101I~
{                                                                  //~v101I~
//********************                                             //~v101I~
	uerrmsg("Environment dose not support LFN",                    //~v101I~
            "環境が長いファイル名をサポートしていません");         //~v101I~
	return 4;                                                      //~v101I~
}//ufilenotvfat                                                    //~v101I~
#endif                                                             //~v101I~
//#ifdef UNX                                                       //~v59eR~
//**************************************************************** //~v329I~
//ufilenopermission                                                //~v329I~
//*parm :none                                                      //~v329I~
//*retrn:4                                                         //~v329I~
//**************************************************************** //~v329I~
int ufilenopermission(UCHAR *Poperation,UCHAR *Pfnm,int Prc)       //~v366R~
{                                                                  //~v329I~
//********************                                             //~v329I~
	uerrmsg("%s:Permission error for %s",                          //~v366R~
            "%s:権限エラー %s",                                    //~v366R~
//  		Poperation,Pfnm);                                      //~v366R~//~v6ygR~
    		Poperation,STD_FNM(Pfnm));                             //~v6ygI~
	return Prc;                                                    //~v329R~
}//ufilenopermission                                               //~v329I~
//#ifdef UNX                                                       //~v5avR~
#ifdef FTPSUPP                                                     //~v5avI~
//**************************************************************** //~v56gI~
//ufileslinkloop                                                   //~v56gI~
//*parm :none                                                      //~v56gI~
//*retrn:4                                                         //~v56gI~
//**************************************************************** //~v56gI~
int ufileslinkloop(UCHAR *Poperation,UCHAR *Pfnm)    //~v56gI~     //~v6k8R~
{                                                                  //~v56gI~
//********************                                             //~v56gI~
  if (!(Gufile_opt & GFILEOPT_NOSLINKERRMSG))                      //~v573I~
//	uerrmsg("%s failed;Too many slink level of %s",                //~v56gI~//~v6k8R~
//          "%s 失敗。S-linkレベルオーバー(%s)",                   //~v56gI~//~v6k8I~
  	uerrmsg("%s failed;Symlink loop:%s",                           //~v6k8R~
            "%s 失敗。Symlink ループ:%s",                          //~v6k8R~
//  		Poperation,Pfnm);                                      //~v56gI~//~v6ygR~
    		Poperation,STD_FNM(Pfnm));                             //~v6ygI~
	return ELOOP;                                                  //~v56gI~
}//ufileslinkloop                                                  //~v56gI~
//**************************************************************** //~v56sI~
//ufileerrspecialfile                                              //~v56sI~
//*parm :fnm,rc                                                    //~v56sI~
//*retrn:rc                                                        //~v56sI~
//**************************************************************** //~v56sI~
int ufileerrspecialfile(UCHAR *Pfnm,int Prc)                       //~v56sI~
{                                                                  //~v56sI~
//********************                                             //~v56sI~
	uerrmsg("%s is not a reguler file.",                           //~v56sI~
    	        "%s は特殊ファイルです。",                         //~v5kqR~
			       Pfnm);                                          //~v56sI~
    return Prc;                                                    //~v56sI~
}//ufileerrspecialfile                                             //~v56sI~
#endif                                                             //~v329I~
//**************************************************************** //~v5kqI~
//ufileerrspecialfile                                              //~v5kqI~
//*parm :fnm,rc                                                    //~v5kqI~
//*retrn:rc                                                        //~v5kqI~
//**************************************************************** //~v5kqI~
int ufileerrnotnormal(UCHAR *Pfnm,int Prc)                         //~v5kqI~
{                                                                  //~v5kqI~
//********************                                             //~v5kqI~
//  uerrmsg("%s is not a reguler file.",                           //~v5kqR~//~v6HfR~
//  	        "%s 通常ファイルではありません。",                 //~v5kqR~//~v6HfR~
    uerrmsg("Not a reguler file:%s",                               //~v6HfI~
    	        " 通常ファイルではありません:%s",                  //~v6HfI~
			       Pfnm);                                          //~v5kqI~
    return Prc;                                                    //~v5kqI~
}//ufileerrnotnormal                                               //~v5kqI~
//**************************************************************** //~v5d8I~
//ufile 2 dir                                                      //~v5d8I~
//**************************************************************** //~v5d8I~
int ufileerrdir2file(int Prc)                                      //~v5d8I~
{                                                                  //~v5d8I~
    uerrmsg("Operation not allowed from Dir/Wildcard to File",0);  //~v5d8I~
    return Prc;                                                    //~v5d8I~
}//ufileerrdir2file                                                //~v5d8I~
//**************************************************************** //~v5d9I~
//ufileerrnoentry                                                  //~v5d9I~
//*parm :fnm,rc                                                    //~v5d9I~
//*retrn:rc                                                        //~v5d9I~
//**************************************************************** //~v5d9I~
int ufileerrnoentry(char *Pfnm,int Prc)                            //~v5d9I~
{                                                                  //~v5d9I~
//********************                                             //~v5d9I~
    uerrmsg("No entry in %s",0,                                    //~v5d9I~
//      	    Pfnm);                                             //~v5d9R~//~v6ygR~
        	    STD_FNM(Pfnm));                                    //~v6ygI~
    return Prc;                                                    //~v5d9I~
}//ufileerrnoentry                                                 //~v62bR~
//**************************************************************** //~v62bI~
//ufileerrnofileentry                                              //~v62bI~
//*parm :fnm,rc                                                    //~v62bI~
//*retrn:rc                                                        //~v62bI~
//**************************************************************** //~v62bI~
int ufileerrnofileentry(char *Pfnm,int Prc)                        //~v62bI~
{                                                                  //~v62bI~
//********************                                             //~v62bI~
    uerrmsg("No file entry in %s",0,                               //~v62bI~
//      	    Pfnm);                                             //~v62bI~//~v6ygR~
        	    STD_FNM(Pfnm));                                    //~v6ygI~
    return Prc;                                                    //~v62bI~
}//ufileerrnofileentry                                             //~v62bI~
//**************************************************************** //~v6hLI~
//ufileerrnofileentry                                              //~v6hLI~
//*parm :fnm,rc                                                    //~v6hLI~
//*retrn:rc                                                        //~v6hLI~
//**************************************************************** //~v6hLI~
int ufileTooLongFullpathName(int Prc)                              //~v6hLI~
{                                                                  //~v6hLI~
//********************                                             //~v6hLI~
	if (Gufile_opt & GFILEOPT_XETERMINATING)	//   0x0400 //xe ytermination avoid toolongname errmsg at dlterm//~v6HjI~
    	return Prc;                                                //~v6HjI~
    uerrmsg("too long file path name(Max:%d)",                       //~v6hLI~//~v6H1R~
    		"長過ぎるファイルパス名(Max:%d)",                        //~v6hLR~//~v6H1R~
        		_MAX_PATH);                                        //~v6hLI~
    return Prc;                                                    //~v6hLI~
}//ufileTooLongFullpathName                                        //~v6hLI~
//**************************************************************** //~v6H1R~
//ufileerrnofileentry                                              //~v6H1R~
//*parm :fnm,rc                                                    //~v6H1R~
//*retrn:rc                                                        //~v6H1R~
//**************************************************************** //~v6H1R~
int ufileTooLongFullpathName2(int Prc,char *Ppath,char *Pfnm)      //~v6H1R~
{                                                                  //~v6H1R~
    char fpath[_MAX_PATH];                                         //~v6H1I~
    char fpath2[_MAX_PATH];                                        //~v6H1I~
//********************                                             //~v6H1R~
	if (Gufile_opt & GFILEOPT_XETERMINATING)	//   0x0400 //xe ytermination avoid toolongname errmsg at dlterm//~v6HjI~
    	return Prc;                                                //~v6HjI~
	UstrncpyZ(fpath,Ppath,sizeof(fpath));                          //~v6H1I~
	if (!Pfnm || !*Pfnm)                                           //~v6H1I~
//      uerrmsg("too long file path name(Max:%d):%s - %s",         //~v6H1R~//+v6N1R~
        uerrmsg("too long file path name(Max:%d):%s",              //+v6N1I~
    			"長過ぎるファイルパス名(Max:%d):%s",               //~v6H1R~
        		_MAX_PATH,fpath);                                  //~v6H1R~
    else                                                           //~v6H1I~
    {                                                              //~v6H1I~
		UstrncpyZ(fpath2,Pfnm,sizeof(fpath2));                     //~v6H1I~
    	uerrmsg("too long file path name(Max:%d):%s - %s",         //~v6H1R~
    			"長過ぎるファイルパス名(Max:%d):%s - %s",          //~v6H1R~
        		_MAX_PATH,fpath,fpath2);                           //~v6H1R~
    }                                                              //~v6H1I~
    return Prc;                                                    //~v6H1R~
}//ufileTooLongFullpathName2                                       //~v6H1R~
//**************************************************************** //~v5k0M~
//ufileeditsz                                                      //~v5k0M~
//edit file size by z,zzz,zzz,zz9    if sz<4GB                     //~v5k0M~
//               by  zzz,zzz,zz9K    if sz<1TB                     //~v5k0M~
//               by  zzz,zzz,zz9M    if else                       //~v5k0M~
//**************************************************************** //~v5k0M~
char *ufileeditsz(int Popt,FILESZT Psz,char *Pout)                 //~v5k0R~
{                                                                  //~v5k0M~
#ifdef LFSSUPP                                                     //~v5k0I~
	FILESZT tb=1000000000;	//1TB by K                             //~v5k0M~
#endif                                                             //~v5k0I~
static char Seditwk[32];                                           //~v5k0I~
	char *pout;                                                    //~v5k0I~
    int minsz;                                                     //~v5k0I~
//**********************                                           //~v5k0I~
    minsz=Popt & UFEFSZ_MINSZMASK;                                 //~v5k0I~
    if (Pout)                                                      //~v5k0I~
        pout=Pout;                                                 //~v5k0I~
    else                                                           //~v5k0I~
        pout=Seditwk;                                              //~v5k0I~
  if (Popt & (UFEFSZ_HEXUPPER|UFEFSZ_HEXLOWER))	//hex edit         //~v5k0R~
  {                                                                //~v5k0I~
#ifdef LFSSUPP                                                     //~v5k0I~
    if (!minsz)                                                    //~v5k0I~
        minsz=8;                                                   //~v5k0I~
    if (Popt & UFEFSZ_STDFMT)	//printf fmt                       //~v5k0I~
    {                                                              //~v5k0I~
		if (Popt & UFEFSZ_HEXUPPER)	//hex edit                     //~v5k0I~
			sprintf(pout,"%0*" FILESZ_EDIT "X",minsz,Psz); //minimum 8 char//~v5k0R~
    	else                                                       //~v5k0I~
			sprintf(pout,"%0*" FILESZ_EDIT "x",minsz,Psz); //minimum 8 char//~v5k0I~
    }                                                              //~v5k0I~
    else                                                           //~v5k0I~
	if (Psz>>32)                                                   //~v5k0I~
    {                                                              //~v5k0I~
        minsz-=8;                                                  //~v5k0I~
        if (minsz<0)                                               //~v5k0I~
            minsz=0;                                               //~v5k0I~
		if (Popt & UFEFSZ_HEXUPPER)	//hex edit                     //~v5k0I~
			sprintf(pout,"%0*lX..%08lX",minsz,(ULONG)(Psz>>32),(ULONG)Psz);//~v5k0R~
    	else                                                       //~v5k0I~
			sprintf(pout,"%0*lx..%08lx",minsz,(ULONG)(Psz>>32),(ULONG)Psz);//~v5k0R~
    }                                                              //~v5k0I~
    else                                                           //~v5k0I~
    {                                                              //~v5k0I~
#endif                                                             //~v5k0I~
		if (Popt & UFEFSZ_HEXUPPER)	//hex edit                     //~v5k0I~
			sprintf(pout,"%0*lX",minsz,(ULONG)Psz);                //~v5k0R~
    	else                                                       //~v5k0I~
			sprintf(pout,"%0*lx",minsz,(ULONG)Psz);                //~v5k0R~
#ifdef LFSSUPP                                                     //~v5k0I~
    }                                                              //~v5k0I~
#endif                                                             //~v5k0I~
  }                                                                //~v5k0I~
  else                                                             //~v5k0I~
  {                                                                //~v5k0I~
#ifdef LFSSUPP                                                     //~v5k0M~
    if (Popt & UFEFSZ_STDFMT)	//printf fmt                       //~v5k0I~
    {                                                              //~v5k0I~
        if (minsz)                                                 //~v5k0I~
			sprintf(pout,"%*" FILESZ_EDIT "d",minsz,Psz);          //~v5k0I~
        else                                                       //~v5k0I~
			sprintf(pout,"%" FILESZ_EDIT "d",Psz);                 //~v5k0I~
    }                                                              //~v5k0I~
    else                                                           //~v5k0I~
    if (Popt & UFEFSZ_FULLZ)	//bo K/M edit                      //~v5k0I~
    {                                                              //~v5k0I~
		if (Psz>>32)                                               //~v5k0I~
        	bc_dweditnum64(0,'Z',Psz,pout);                        //~v5k0R~
        else                                                       //~v5k0I~
		    if (Popt & UFEFSZ_NOTMINZ10)	//bo K/M edit          //~v5k0I~
	        	bc_dweditnum64(0,'Z',Psz,pout);                    //~v5k0I~
            else                                                   //~v5k0I~
				unumedit((ULONG)Psz,"z,zzz,zzz,zz9",pout);         //~v5k0I~
    }                                                              //~v5k0I~
    else                                                           //~v5k0I~
	if (Psz>>32)                                                   //~v5k0M~
    	if ((Psz>>10)<tb)	//under 1,000,000,000K                 //~v5k0M~
			unumedit((ULONG)(Psz>>10)," zzz,zzz,zz9K",pout);       //~v5k0R~
        else                                                       //~v5k0M~
			unumedit((ULONG)(Psz>>20)," zzz,zzz,zz9M",pout);       //~v5k0R~
    else                                                           //~v5k0M~
		unumedit((ULONG)Psz,"z,zzz,zzz,zz9",pout);                 //~v5k0R~
#else                                                              //~v5k0M~
	unumedit((ULONG)Psz,"z,zzz,zzz,zz9",pout);                     //~v5k0R~
#endif                                                             //~v5k0M~
  }//decimal                                                       //~v5k0I~
	return pout;                                                   //~v5k0R~
}//ufileeditsz                                                     //~v5k0M~
//**************************************************************** //~v6k6I~
#if defined(W32)||defined(UNX)                                     //~va71I~//~v6k6I~
int ufileslinktargeterr(int Prc,char *Pslink,char *Ptarget)        //~v6k6I~
{                                                                  //~v6k6I~
	uerrmsg("Symbolic Link broken(%s-->%s)",                       //~v6k6I~
    		"リンク相手なし(%s-->%s)",                             //~v6k6R~
//          Pslink,Ptarget);                                       //~v6k6I~//~v6ygR~
            STD_FNM(Pslink),STD_FNM(Ptarget));                     //~v6ygI~
    return Prc;                                                    //~v6k6I~
}                                                                  //~v6k6I~
#endif                                                             //~v6k6I~
#if defined(W32)                                                   //~v6k8I~
//**************************************************************** //~v6kgM~
int ufileslinkj2ferr(int Prc,char *Pslink,char *Ptarget)           //~v6k8I~
{                                                                  //~v6k8I~
	uerrmsg("Junction target is not dir(%s-->%s)",                 //~v6k8I~
    		"ジャンクション先がDirでない(%s-->%s)",                //~v6k8I~
//          Pslink,Ptarget);                                       //~v6k8I~//~v6ygR~
            STD_FNM(Pslink),STD_FNM(Ptarget));                     //~v6ygI~
    return Prc;                                                    //~v6k8I~
}                                                                  //~v6k8I~
//**************************************************************** //~v6kgI~
int ufileslinkd2ferr(int Prc,char *Pslink,char *Ptarget)           //~v6kgI~
{                                                                  //~v6kgI~
	uerrmsg("<SLINKD> target is not dir(%s-->%s)",                 //~v6kgI~
    		"<SLINKD>リンク先がDirでない(%s-->%s)",                //~v6kgI~
//          Pslink,Ptarget);                                       //~v6kgI~//~v6ygR~
            STD_FNM(Pslink),STD_FNM(Ptarget));                     //~v6ygI~
    return Prc;                                                    //~v6kgI~
}                                                                  //~v6kgI~
#endif                                                             //~v6k8I~
//**************************************************************** //~v6B7I~
int ufileopenerrInvalidargument(int Popt,int Prc,char *Ppfile)     //~v6B7R~
{                                                                  //~v6B7I~
	int rc=EINVAL;                                                 //~v6B7I~
//******************                                               //~v6B7I~
#ifdef UNX                                                         //~vb2dR//~v6B7I~
        uerrmsg("%s Open failed(errno=%d:%s)(Is codepage matches with \"iocharset\" mount option?)",//+vb2dR//~v6B7R~
                "%s オープンエラー(errno=%d:%s)(文字コード不一致?,\"iocharset\" mount オプションを確認してください)",//+vb2dR//~v6B7R~
				Ppfile,rc,strerror(rc));//~v08qR~            //~vb2dI//~v6B7R~
#else                                                              //~vb2dR//~v6B7I~
        uerrmsg("%s Open failed(errno=%d:%s)(Maybe invalid codepage)",//~vb2dR//~v6B7R~
                "%s オープンエラー(errno=%d:%s)(文字コード不一致？)",//~vb2dR//~v6B7R~
				Ppfile,rc,strerror(rc));//~v08qR~            //~vb2dR//~v6B7R~
#endif                                                             //~vb2dR//~v6B7I~
	return Prc;                                                    //~v6B7I~
}//ufileopenerrInvalidargument                                     //~v6B7I~
//**************************************************************** //~v6H1I~
int ufileErrInvalidName(int Prc,char *Ppfile)                      //~v6H1I~
{                                                                  //~v6H1I~
//******************                                               //~v6H1I~
    uerrmsg("Invalid FileName(%s)",0,                              //~v6H1I~
                Ppfile);                                           //~v6H1R~
	return Prc;                                                    //~v6H1I~
}//ufileErrInvalidName                                             //~v6H1I~
