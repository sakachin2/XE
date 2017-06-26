//*CID://+v5dbR~:                             update#=  161;       //+v5dbR~
//*************************************************************
//*ufile1l2.c                                                      //~v50GR~
//*  mmd,mrd,mattrib,mdel                                          //~v556I~
//*************************************************************
//v6db:120217 (BUG)tempnam may overflow fo Axe because /tmp is not available and changed to /mnt/sdcard/tmp/...//+v5dbI~
//v563:020702 (AIX)filename set to notsupported msg                //~v563I~
//v55n:020503 (AIX)disket support                                  //~v55nI~
//v55m:020501 (TL)mcopy issue "Skipping "xxx", is not a directory" to stderr//~v55mI~
//v55i:020430 (UNX:BUG)uerrmsg "copying" because msg on stderr     //~v55iI~
//v559:020427 (UNX)disket support(mcopy) for copy file             //~v559I~
//v557:020427 (UNX)disket support(mren) for rename file            //~v557I~
//v556:020427 (UNX)disket support(mdel) for delete file            //~v556I~
//v538:020322 (LNX)mdos disk support;mkdir rmdir;attrib            //~v538I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>                                                //~v559I~
//*******************************************************
#include <ulib.h>
#include <ufile.h>
#include <ufile1l2.h>                                              //~v538R~
#include <ufile2.h>                                                //~v55nI~
#include <ufile2l2.h>                                              //~v538I~
#include <ufile3.h>                                                //~v559I~
#include <ufile4.h>                                                //~v559I~
#include <uerr.h>
#include <ustring.h>
#include <ualloc.h>                                                //~v50GI~
#include <uproc.h>                                                 //~v50GI~
//*******************************************************
#ifdef AIX                                                         //~v55nI~
	#define CMD_DOSDEL       "dosdel \"%s\""     //remove file     //~v55nI~
	#define CMD_DOSREAD      "dosread \"%s\" \"%s\"" //dosread dosfile unxfile//~v55nI~
	#define CMD_DOSWRITE     "doswrite \"%s\" \"%s\"" //dosread unixfile dosfile//~v55nI~
#else                                                              //~v55nI~
#define CMD_MMD        "mmd -s \"%s\""  //mmd -s dirnm;-s skip if dup name//~v538R~
#define CMD_MRD        "mrd  \"%s\""     //mrd:rmdir               //~v538R~
#define CMD_MATTRIB3   "mattrib %s \"%s\"" //mattrib [+|-]{a|h|r|s}	fnm//~v538R~
#define CMD_MDEL       "mdel \"%s\""     //mdel:remove             //~v556I~
#define CMD_MREN       "mren -r \"%s\" \"%s\""     //mdel:remove   //~v557I~
#define CMD_MCOPY      "mcopy -n -o %s \"%s\" \"%s\"" //mcopy -n -o [-m] f1 f2//~v559R~
#endif                                                             //~v55nI~
//                       -n:no confirmation to override unix       //~v559R~
//                       -m:preserve mod time                      //~v559I~
//                       -o:override on disket file                //~v559I~
//*******************************************************
int uappend_mdos(char *Psource,char *Ptarget,int Popt);            //~v559I~
int ufilemdoscopyerr(char *Psource,char *Ptarget);                 //~v559I~
//*******************************************************          //~v50GI~
//*mkdir MSDOS                                                     //~v538R~
//*parm 1:file name                                                //~v50GI~
//*******************************************************          //~v50GI~
int umkdir_mdos(char *Ppfile)                                      //~v538R~
{                                                                  //~v50GI~
#ifdef AIX                                                         //~v55nI~
	return ufileerrmdosnotsupported("mkdir",Ppfile);               //~v563R~
#else                                                              //~v55nI~
    int rc;                                                        //~v50GR~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v50GR~
//*********************************                                //~v50GI~
    sprintf(mtoolscmd,CMD_MMD,Ppfile);                             //~v538R~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,0,0,0,0);	//get stdout/stderr//~v538R~
    if (rc)                                                        //~v538I~
        if (!ufstat(Ppfile,0))	//no fstat info                    //~v538I~
        	rc=EEXIST;                                             //~v538I~
    errno=rc;	//after ufstat                                     //~v538I~
    return rc;                                                     //~v538R~
#endif                                                             //~v55nI~
}//umkdir_mdos                                                     //~v538R~
//*******************************************************          //~v538I~
//*mkdir MSDOS                                                     //~v538I~
//*parm 1:file name                                                //~v538I~
//*******************************************************          //~v538I~
int urmdir_mdos(char *Ppfile)                                      //~v538R~
{                                                                  //~v538I~
#ifdef AIX                                                         //~v55nI~
	return ufileerrmdosnotsupported("rmdir",Ppfile);               //~v563R~
#else                                                              //~v55nI~
    int rc,stdectr;                                                //~v538R~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v538I~
    char **stde;                                                   //~v538R~
//*********************************                                //~v538I~
    sprintf(mtoolscmd,CMD_MRD,Ppfile);                             //~v538R~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,0,&stde,0,&stdectr);	//get stderr//~v538R~
    if (rc==1 && stdectr==1)	//chk if 1 line stderr             //~v538R~
    {                                                              //~v538I~
    	if (strstr(stde[0],"Removing")) //"Removing filename" is written to stderr//~v538R~
        {                                                          //~v55iR~
            ugeterrmsg();   //clear this msg by uproc              //~v55iR~
    		errno=rc=0;                                            //~v538R~
        }                                                          //~v55iR~
    }                                                              //~v538I~
    if (stde)                                                      //~v538I~
        ufree(stde);                                               //~v538I~
    return rc;                                                     //~v538I~
#endif                                                             //~v55nI~
}//urmdir_mdos                                                     //~v538R~
//**************************************************************** //~v538I~
//uattrib                                                          //~v538I~
//* set file attribute(read/hidden/system/archive)                 //~v538I~
//*parm1:filename                                                  //~v538I~
//*parm2:attribute to set on   mode+attr                           //~v538I~
//*parm3:attribute to set off  mode+attr   if on=0,off=0:query     //~v538I~
//*retrn:rc                                                        //~v538I~
//**************************************************************** //~v538I~
int uattrib_mdos(char *Pfname,ULONG Pattron,ULONG Pattroff)        //~v538R~
{                                                                  //~v538I~
#ifdef AIX                                                         //~v55nI~
	return ufileerrmdosnotsupported("attrib",Pfname);              //~v563R~
#else                                                              //~v55nI~
	int ii,rc;                                                     //~v538R~
    char  *pc,attrstr[16];                                         //~v538R~
    ULONG attr;                                                    //~v538I~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v538I~
//********************                                             //~v538I~
    pc=attrstr;                                                    //~v538M~
    attr=FILE_GETATTR(Pattroff);                                   //~v538I~
    if (attr)                                                      //~v538R~
    	*pc++='-';                                                 //~v538I~
    for (ii=0;ii<2;ii++)//off and on                               //~v538R~
    {                                                              //~v538I~
    	if (attr & FILE_READONLY)                                  //~v538I~
        	*pc++='r';                                             //~v538R~
    	if (attr & FILE_HIDDEN)                                    //~v538I~
        	*pc++='h';                                             //~v538R~
    	if (attr & FILE_SYSTEM)                                    //~v538I~
        	*pc++='s';                                             //~v538R~
    	if (attr & FILE_ARCHIVED)                                  //~v538I~
        	*pc++='a';                                             //~v538R~
    	attr=FILE_GETATTR(Pattron);                                //~v538I~
        if (!attr)                                                 //~v538I~
        	break;                                                 //~v538I~
	    *pc++=' ';                                                 //~v538R~
	    *pc++='+';                                                 //~v538I~
    }                                                              //~v538I~
    if (pc==attrstr)	//no attr bit specified                    //~v538I~
    	return 0;                                                  //~v538I~
    *pc=0;                                                         //~v538I~
    sprintf(mtoolscmd,CMD_MATTRIB3,attrstr,Pfname);                //~v538R~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,0,0,0,0);	//get stdout/stderr//~v538I~
    return rc;                                                     //~v538I~
#endif                                                             //~v55nI~
}//uattrib_mdos                                                    //~v538R~
//*******************************************************          //~v556I~
//*remove MSDOS                                                    //~v556I~
//*parm 1:file name                                                //~v556I~
//*******************************************************          //~v556I~
int uremove_mdos(char *Ppfile)                                     //~v556I~
{                                                                  //~v556I~
    int rc,stdectr;                                                //~v556I~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v556I~
    char **stde;                                                   //~v556I~
//*********************************                                //~v556I~
#ifdef AIX                                                         //~v55nI~
    sprintf(mtoolscmd,CMD_DOSDEL,Ppfile+3);                        //~v55nR~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG|MDCO_CHKSTDO,mtoolscmd,0,&stde,0,&stdectr);	//get stderr//~v55nI~
#else                                                              //~v55nI~
    sprintf(mtoolscmd,CMD_MDEL,Ppfile);                            //~v556I~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,0,&stde,0,&stdectr);	//get stderr//~v556I~
#endif                                                             //~v55nM~
#ifdef AIX                                                         //~v55nI~
#else                                                              //~v55nI~
    if (rc==1 && stdectr==1)	//chk if 1 line stderr             //~v556I~
    {                                                              //~v556I~
    	if (strstr(stde[0],"Removing")) //"Removing filename" is written to stderr//~v556I~
        {                                                          //~v55iR~
            ugeterrmsg();   //clear this msg by uproc              //~v55iR~
    		errno=rc=0;                                            //~v556I~
        }                                                          //~v55iR~
    }                                                              //~v556I~
#endif                                                             //~v55nI~
    if (stde)                                                      //~v556I~
        ufree(stde);                                               //~v556I~
    return rc;                                                     //~v556I~
}//uremove_mdos                                                    //~v556I~
#ifdef AIX                                                         //~v55nI~
//*******************************************************          //~v55nI~
//*rename MSDOS file for AIX                                       //~v55nI~
//* (copy and delete)                                              //~v55nI~
//*parm 1:old name(file or dir on mdos disk)                       //~v55nI~
//*parm 1:new name(path allowed if on mdos disk)                   //~v55nI~
//*******************************************************          //~v55nI~
int urename_mdos(char *Poldname,char *Pnewname)                    //~v55nI~
{                                                                  //~v55nI~
    int rc;                                                        //~v55nI~
//*********************************                                //~v55nI~
	if (rc=ucopy_mdos(Poldname,Pnewname,DCPY_NOCOPYINFO),rc)       //~v55nI~
    	return rc;                                                 //~v55nI~
	return uremove_mdos(Poldname);                                 //~v55nI~
}//urename_mdos                                                    //~v55nI~
#else                                                              //~v55nI~
//*******************************************************          //~v557I~
//*rename MSDOS                                                    //~v557I~
//*parm 1:old name(file or dir on mdos disk)                       //~v557I~
//*parm 1:new name(path allowed if on mdos disk)                   //~v557I~
//*******************************************************          //~v557I~
int urename_mdos(char *Poldname,char *Pnewname)                    //~v557I~
{                                                                  //~v557I~
    int rc;                                                        //~v557I~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v557I~
//*********************************                                //~v557I~
    sprintf(mtoolscmd,CMD_MREN,Poldname,Pnewname);                 //~v557I~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,0,0,0,0);	//get stderr//~v557I~
    return rc;                                                     //~v557I~
}//urename_mdos                                                    //~v557I~
#endif                                                             //~v55nI~
//*******************************************************          //~v559I~
//*copy MSDOS                                                      //~v559I~
//*parm 1:source file                                              //~v559I~
//*parm 2:target file                                              //~v559I~
//*parm 3:option;copy pathinfo or appendsw                         //~v559I~
//*******************************************************          //~v559I~
int ucopy_mdos(char *Psource,char *Ptarget,int Popt)               //~v559I~
{                                                                  //~v559I~
    UCHAR mtoolscmd[_MAX_PATH+32];                                 //~v55nR~
    int rc,stdectr;                                                //~v559R~
    char **stde;                                                   //~v559I~
    int nocopyinfosw;                                              //~v559I~
#ifdef AIX                                                         //~v55nI~
//  char tempfnm[32];                                              //~v55nI~//+v5dbR~
    char tempfnm[_MAX_PATH];                                       //+v5dbI~
    FILEFINDBUF3 ffb3;                                             //~v55nI~
#else                                                              //~v55nI~
    UCHAR *preserveparm;                                           //~v55nI~
#endif                                                             //~v55nI~
//*********************************                                //~v559I~
    nocopyinfosw=Popt & DCPY_NOCOPYINFO;                           //~v559I~
    Popt &= ~DCPY_NOCOPYINFO;		//drop flag                    //~v559I~
    if (Popt)                                                      //~v559I~
		return uappend_mdos(Psource,Ptarget,nocopyinfosw);         //~v559R~
#ifdef AIX                                                         //~v55nI~
    if (MDOSDISKOK(Psource)         //both is disket               //~v55nR~
    &&  MDOSDISKOK(Ptarget))        //confirmation issed none the less -n option//~v55nR~
    {                                                              //~v55nR~
        utempnam("/tmp","xetmpre_",tempfnm);                       //~v55nR~
        rc=ucopy_mdos(Psource,tempfnm,nocopyinfosw);               //~v55nR~
        if (rc)                                                    //~v55nR~
            ufilemdoscopyerr(Psource,tempfnm);                     //~v55nR~
        else                                                       //~v55nR~
        {                                                          //~v55nR~
            rc=ucopy_mdos(tempfnm,Ptarget,nocopyinfosw);           //~v55nR~
            if (rc)                                                //~v55nR~
                ufilemdoscopyerr(tempfnm,Ptarget);                 //~v55nR~
        }                                                          //~v55nR~
        unlink(tempfnm);        //del tempfile                     //~v55nR~
        return rc;                                                 //~v55nR~
    }                                                              //~v55nR~
    if (MDOSDISKOK(Psource))         //mdos to unix                //~v55nI~
    	sprintf(mtoolscmd,CMD_DOSREAD,Psource+3,Ptarget);          //~v55nR~
    else							//unix to dos                  //~v55nI~
    	sprintf(mtoolscmd,CMD_DOSWRITE,Psource,Ptarget+3);         //~v55nR~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG|MDCO_CHKSTDO,mtoolscmd,0,&stde,0,&stdectr);	//get stderr//~v55nR~
  if (!rc)                                                         //~v55nI~
    if (!nocopyinfosw)  //copy path info                           //~v55nI~
	    if (MDOSDISKOK(Psource))         //mdos to unix            //~v55nI~
        	if (!ufstat(Psource,&ffb3))                            //~v55nR~
            	usetftime(Ptarget,ffb3.fdateLastWrite,ffb3.ftimeLastWrite);//copy filetime//~v55nI~
#else                                                              //~v55nI~
//copy                                                             //~v559I~
    if (nocopyinfosw)                                              //~v559I~
    	preserveparm="";                                           //~v559I~
    else                                                           //~v559I~
    	preserveparm="-m";                                         //~v559I~
    sprintf(mtoolscmd,CMD_MCOPY,preserveparm,Psource,Ptarget);     //~v559I~
    rc=ufilemdoscmd(UPROC_NOMSG|UPROC_NOOKMSG,mtoolscmd,0,&stde,0,&stdectr);	//get stderr//~v559R~
#ifdef LNXLC2     //turbo linux                                    //~v55mM~
    if (rc==ENOTDIR && stdectr==1) //bug of tl,"not dir" is written to stderr//~v55mR~
    {                                                              //~v55mI~
        ugeterrmsg();   //clear this msg by uproc                  //~v55mI~
        errno=rc=0;                                                //~v55mI~
    }                                                              //~v55mI~
#endif                                                             //~v55mM~
    if (rc==1 && stdectr==1)	//chk if 1 line stderr             //~v559I~
    {                                                              //~v559I~
    	if (strstr(stde[0],"Copying")) //"Copying filename" is written to stderr//~v559I~
        {                                                          //~v55iR~
//          ugeterrmsg();   //clear this msg by uproc              //~v55nR~
    		errno=rc=0;                                            //~v559I~
        }                                                          //~v55iR~
    }                                                              //~v559I~
#endif                                                             //~v55nI~
    if (stde)                                                      //~v559I~
        ufree(stde);                                               //~v559I~
    if (rc==ENOSPC)                                                //~v55nI~
		ufilediskfull(Ptarget,rc);                                 //~v55nI~
    else                                                           //~v55nI~
    if (rc)                                                        //~v55nI~
        uerrmsg("copy failed, %s to %s(rc=%d)",                    //~v55nI~
                 "%s ‚©‚ç %s ‚Ö‚ÌƒRƒs[Ž¸”s(rc=%d)",               //~v55nI~
                    Psource,Ptarget,rc);                           //~v55nI~
    return rc;                                                     //~v559I~
}//ucopy_mdos                                                      //~v559I~
//*******************************************************          //~v559I~
//*append MSDOS                                                    //~v559I~
//*parm 1:source file                                              //~v559I~
//*parm 2:target file                                              //~v559I~
//*parm 3:option;copy pathinfo                                     //~v559I~
//*******************************************************          //~v559I~
int uappend_mdos(char *Psource,char *Ptarget,int Popt)             //~v559I~
{                                                                  //~v559I~
    int rc,unlinksw=1;                                             //~v559I~
//  char tempfnm[32];                                              //~v559I~//+v5dbR~
    char tempfnm[_MAX_PATH];                                       //+v5dbI~
//*********************************                                //~v559I~
    utempnam("/tmp","xetmpappend_",tempfnm);                       //~v559I~
  	if (MDOSDISKOK(Ptarget))	    //target is mdosdisk           //~v559I~
    {                                                              //~v559I~
    	rc=ucopy_mdos(Ptarget,tempfnm,Popt);//copy target to /tmp  //~v559I~
        if (rc)                                                    //~v559I~
        	ufilemdoscopyerr(Ptarget,tempfnm);                     //~v559I~
        else                                                       //~v559I~
        {                                                          //~v559I~
        	rc=udoscopy(Psource,tempfnm,Popt|DCPY_APPEND);	//copy mdos to unix or cop//~v559I~
        	if (rc)                                                //~v559I~
	        	ufilemdoscopyerr(Psource,tempfnm);                 //~v559I~
            else                                                   //~v559I~
            {                                                      //~v559I~
		    	rc=ucopy_mdos(tempfnm,Ptarget,Popt);//copy back appended file to target//~v559I~
                if (rc)                                            //~v559I~
                {                                                  //~v559I~
		        	ufilemdoscopyerr(tempfnm,Ptarget);             //~v559I~
                    unlinksw=0;		//keep work                    //~v559I~
                }                                                  //~v559I~
            }                                                      //~v559I~
        }                                                          //~v559I~
    }                                                              //~v559I~
    else	//append mdosdisk to unix                              //~v559I~
    {                                                              //~v559I~
    	rc=ucopy_mdos(Psource,tempfnm,Popt);//copy target to /tmp  //~v559I~
        if (rc)                                                    //~v559I~
			ufilemdoscopyerr(Psource,tempfnm);                     //~v559I~
        else                                                       //~v559I~
        {                                                          //~v559I~
        	rc=udoscopy(tempfnm,Ptarget,Popt|DCPY_APPEND);	//copy mdos to unix or cop//~v559I~
            if (rc)                                                //~v559I~
            {                                                      //~v559I~
				ufilemdoscopyerr(tempfnm,Ptarget);                 //~v559I~
                unlinksw=0;     //keep work                        //~v559I~
            }                                                      //~v559I~
        }                                                          //~v559I~
    }                                                              //~v559I~
    if (unlinksw)                                                  //~v559I~
	    unlink(tempfnm);        //del tempfile                     //~v559I~
    return rc;                                                     //~v559I~
}//uappend_mdos                                                    //~v559I~
//*******************************************************          //~v559I~
//*copy fail errmsg                                                //~v559I~
//*parm 1:source file                                              //~v559I~
//*parm 2:target file                                              //~v559I~
//*******************************************************          //~v559I~
int ufilemdoscopyerr(char *Psource,char *Ptarget)                  //~v559I~
{                                                                  //~v559I~
	if (!ugeterrmsg2())	//no previous errmsg set                   //~v559I~
		uerrmsg("MDOS:copy failed,%s to %s;rc=%d",0,               //~v55nR~
    			Psource,Ptarget,errno);                            //~v55nR~
	return 4;                                                      //~v559I~
}//ufilemdoscopyerr                                                //~v559I~
