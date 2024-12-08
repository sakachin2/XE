//*CID://+vbyrR~:                        update#=    138           //+vbyrR~
//*************************************************************    
//*xefcmd7.c*                                                      //~v78rR~//~vba2R~
//**SP cmd  :SP {edit|refresh|add {file-spec | * | ^* }            //~vba2R~
//*************************************************************    
//vbyr:230704 ARM:slso do refresh when added                       //+vbyrI~
//vc5c 2023/07/04 display directory set to access by ACTION_OPEN_DOCUMENT_TREE//~vc5cI~
//vbye:230501 "sp add" cmd for Doc ; not allow alias(//alias) but allow "//" only.//~vbyeR~
//vby7:230415 (ARM)split ufile1l.c to ufiledoc.c                   //~vby7I~
//vby6:230402 (ARM)adjust by4; go around by shortname and change to uri at ulib(ufile1l)//~vby6I~
//vby4:230402 (ARM)shared resource support by //shareName defined by SP(ShortPath) cmd.//~vby4I~
//vba2:170710 add SP cmd to register shortcut path name and use by  sp:xxx//~vba2I~
//*************************************************************    
#include <time.h>                                                  
#include <stdio.h>                                                 
#include <stddef.h>                                                
#include <stdlib.h>                                                
#include <ctype.h>                                                 
#include <string.h>                                                
#include <errno.h>                                                 //~v78rI~
#ifdef LNX                                                         //~vby4I~
	#include <dirent.h>   //for func in ufile1l.h                  //~vby4I~
#endif                                                             //~vby4I~
                                                                   
//*******************************************************          
#include <ulib.h>                                                  
#include <uque.h>                                                  
#include <uerr.h>                                                  
#include <ufile.h>                                                 //~vba2I~
#include <uftp.h>                                                  //~v76pI~
#include <ualloc.h>                                                //~vba2I~
#include <ufemsg.h>                                                //~vba2I~
#include <utrace.h>                                                //~vba2I~
#include <ustring.h>                                               //~vba2I~
#include <ufile1l.h>                                           //~vby4I~//~vby6I~
#include <ufiledoc.h>                                              //~vby7I~
#ifdef ARMXXE                                                      //~vby4R~
	#include <jnic2ju.h>                                           //~vby4I~
#endif                                                             //~vby4I~
                                                                   
                                                                   //~vby4I~
#include "xe.h"                                                    
#include "xescr.h"                                                 //~vba2I~
#include "xefile.h"                                                //~vba2I~
#include "xesub.h"                                                 //~vba2I~
#include "xeerr.h"                                                 //~vba2I~
#include "xefunc.h"                                                //~vba2I~
#include "xedir.h"                                                 //~vba2I~
#include "xedcmd.h"                                                //~vba2I~
#include "xefcmd7.h"                                               //~vba2M~
                                                                   //~vby4I~
//*******************************************************          
//same as constant in USAF                                         //~vby4I~
#define AID_CREATE_FILE 17                                         //~vby4I~
#define AID_OPEN_FILE   18                                         //~vby4I~
#define AID_OPEN_TREE   19                                         //~vby4I~
//*******************************************************          //~vby4I~
static 	UQUEH  Sqhsp;		//q of SHORTPATH                       //~vba2I~
//static  char *SdocUri;                                           //~vby4R~
//*******************************************************          //~vba2I~
int funcsp_edit(int Popt,PUCLIENTWE Ppcw);                         //~vba2I~
int funcsp_add(int Popt,PUCLIENTWE Ppcw,char *Ppname,char *Pppath);//~vba2I~
int funcsp_refresh(int Popt,PUCLIENTWE Ppcw);                      //~vba2I~
#ifdef ARMXXE                                                      //~vby4I~
	PSHORTPATH funcsp_getentryDoc(int Popt,int Plineno,char *Pname,int Pnamelen,char *Ppath,int Ppathlen,char *PstrUri);//~vby4I~
	int startArmPicker(int Popt,char *Palias);                     //~vby4R~
#endif                                                             //~vby4I~
//**************************************************************** //~vba2I~
void funcsp_help(PUCLIENTWE Ppcw)                                  //~vba2I~
{                                                                  //~vba2I~
	uerrmsgcat("; SP { edit | refresh | add sp-name { file-spec | *\\ | ^*\\ } }",0);//~vba2R~
#ifdef ARMXXE                                                      //~vbyeI~
	uerrmsgcat("; sp-name:\"%s\" is for Android shared storage;",0,PREFIX_ARM_SHARE);//~vbyeI~
#endif                                                             //~vbyeI~
}//funcsp_help                                                     //~vba2I~
//**************************************************************** //~vba2I~
int funcsp_errline(int Plineno,char *Pbuff)                        //~vba2R~
{                                                                  //~vba2I~
	uerrmsg("%s err at line %d(%s)",0,                             //~vba2I~
    			WKFNM_SHORTPATH,Plineno,Pbuff);                    //~vba2I~
    UTRACEP("%s:err line=%d\n",UTT,Plineno);                       //~vba2I~
    return 4;                                                      //~vba2I~
}//funcsp_help                                                     //~vba2I~
//**************************************************************** 
// sort on optional label range                                    
//*rc   :0                                                         
//**************************************************************** 
int func_shortpath(PUCLIENTWE Ppcw)                                //~vba2R~
{                                                                  
static UCHAR *SwordtblSP="EDIT\0ADD\0REFRESH\0";                   //~vba2R~
    int rc=0,opdno,ii,opid=0;                                      //~vba2R~
    char *pname=0,*pc,*ppath=0;                                    //~vba2R~
//*********************************                                
    opdno=Ppcw->UCWopdno;           //funccmd created already      //~vba2I~
    pc=Ppcw->UCWopdpot;                                            //~vba2I~
	if (!opdno)		//operand                                      //~vba2R~
    {                                                              
        funcsp_help(Ppcw);                                         //~vba2R~
        return 0;                                                  
    }                                                              
    for (ii=0;ii<opdno;ii++,pc+=strlen(pc)+1)	//next operand addr//~vba2I~
	{                                                              //~vba2I~
    	switch(ii)                                                 //~vba2I~
        {                                                          //~vba2I~
        case 0:		//first opd                                    //~vba2I~
 			switch(opid=wordtblisrch(pc,SwordtblSP),opid)          //~vba2I~
            {                                                      //~vba2I~
        	case 1:	//edit                                         //~vba2I~
                break;                                             //~vba2I~
        	case 2:	//add                                          //~vba2I~
                break;                                             //~vba2I~
        	case 3:	//refresh                                      //~vba2I~
                break;                                             //~vba2I~
        	default:	//err                                      //~vba2I~
		        uerrmsg("operand(%s) err",0,                       //~vba2R~
						pc);                                       //~vba2I~
		        funcsp_help(Ppcw);                                 //~vba2I~
                return 4;                                          //~vba2I~
            }                                                      //~vba2I~
            break;                                                 //~vba2I~
        case 1:		//2nd opd                                      //~vba2I~
 			switch(opid)                                           //~vba2I~
            {                                                      //~vba2I~
        	case 1:	//edit                                         //~vba2I~
        	case 3:	//refresh                                      //~vba2I~
	        	errtoomany();                                      //~vba2R~
		        funcsp_help(Ppcw);                                 //~vba2I~
	            return 4;                                          //~vba2I~
                break;                                             //~vba2I~
        	case 2:	//add                                          //~vba2I~
            	pname=pc;                                          //~vba2R~
                break;                                             //~vba2I~
            }                                                      //~vba2I~
            break;                                                 //~vba2I~
        case 2:		//2nd opd                                      //~vba2I~
 			switch(opid)                                           //~vba2I~
            {                                                      //~vba2I~
        	case 2:	//add                                          //~vba2I~
            	ppath=pc;                                          //~vba2I~
                break;                                             //~vba2I~
            }                                                      //~vba2I~
            break;                                                 //~vba2I~
        default:                                                   //~vba2I~
	        errtoomany();                                          //~vba2R~
		    funcsp_help(Ppcw);                                     //~vba2I~
            return 4;                                              //~vba2I~
		}//sw by opd no                                            //~vba2I~
	}//loop by operand no                                          //~vba2I~
    switch(opid)                                                   //~vba2I~
    {                                                              //~vba2I~
    case 1: //edit                                                 //~vba2I~
    	rc=funcsp_edit(0,Ppcw);                                    //~vba2I~
        break;                                                     //~vba2I~
    case 2: //add                                                  //~vba2I~
    	if (!ppath)                                                //~vba2I~
        {                                                          //~vba2I~
#ifdef ARM                                                         //~vby4I~
            if (pname && IS_DOCPATH(pname))                        //~vby4R~
            {                                                      //~vby4I~
              if (!strcmp(pname,PREFIX_ARM_SHARE))                 //~vbyeI~
            	startArmPicker(0,pname);                           //~vby4R~
              else                                                 //~vbyeI~
                uerrmsg("use %s for add shortpath for Android share storage",//~vbyeI~
                        "Android 共有ストレージを追加する場合 %s を使用してください",//~vbyeI~
    						PREFIX_ARM_SHARE);                     //~vbyeI~
            	break;                                             //~vby4I~
            }                                                      //~vby4I~
#endif                                                             //~vby4I~
        	errmissing();                                          //~vba2I~
		    funcsp_help(Ppcw);                                     //~vba2I~
            return 4;                                              //~vba2I~
        }                                                          //~vba2I~
    	rc=funcsp_add(0,Ppcw,pname,ppath);                         //~vba2R~
        break;                                                     //~vba2I~
    case 3: //refresh                                              //~vba2I~
    	rc=funcsp_refresh(0,Ppcw);                                 //~vba2I~
        break;                                                     //~vba2I~
    }                                                              //~vba2I~
    return rc;                                                     
}//func_shortpath                                                  //~vba2R~
//*********************************************************************************//~vba2I~
PSHORTPATH funcsp_getentry(int Popt,int Plineno,char *Pname,int Pnamelen,char *Ppath,int Ppathlen)//~vba2R~
{                                                                  //~vba2I~
	int cblen;                                                     //~vba2I~
    PSHORTPATH psp;                                                //~vba2I~
    char *pc;                                                      //~vba2I~
//*********************                                            //~vba2I~
//    UTRACEP("%s:SdocUri=%s\n",UTT,SdocUri);                      //~vby4R~
    if (Pnamelen<2)                                                //~vba2I~
    {                                                              //~vba2I~
    	if (Plineno>0)                                             //~vba2I~
    		uerrmsg("%s at lineno=%d;shortpath id:%s is invalid, specify minimum 2 chars.",//~vba2R~
        		    "%s-%d 行目;短縮パス名(%s)のエラー(2桁以上にしてください)",//~vba2I~
    				WKFNM_SHORTPATH,Plineno,Pname);                //~vba2R~
        else                                                       //~vba2I~
    		uerrmsg("shortpath id:%s is invalid, specify minimum 2 chars.",//~vba2I~
        		    "短縮パス名(%s)のエラー(2桁以上にしてください)",//~vba2I~
    				Pname);                                        //~vba2I~
        return 0;                                                  //~vba2I~
    }                                                              //~vba2I~
    if (*Ppath==SAMEDIR                       //*               //~v05OR~//~vba2I~
	||  USTRHEADIS(Ppath,FNMOF2NDSCR)       //^*                   //~vba2I~
	||  USTRHEADIS_IC(Ppath,FTP_SHORTPATH_PREFIX)                  //~vba2I~
    )                                                              //~vba2I~
    {                                                              //~vba2I~
    	if (Plineno>0)                                             //~vba2I~
    		uerrmsg("%s at lineno=%d;lineprefix:%c/%s/%s is invalid as shortpath target.",//~vba2I~
        		    "%s-%d 行目;プレフィックス:%c/%s/%s は短縮パス名の宛先として使用できません",//~vba2R~
    				WKFNM_SHORTPATH,Plineno,                       //~vba2I~
    				SAMEDIR,FNMOF2NDSCR,FTP_SHORTPATH_PREFIX);     //~vba2I~
        else                                                       //~vba2I~
    		uerrmsg("prefix:%c/%s/%s is invalid as shortpath target.",//~vba2R~
        		    "プレフィックス:%c/%s/%s は短縮パス名の宛先として使用できません",//~vba2R~
    				SAMEDIR,FNMOF2NDSCR,FTP_SHORTPATH_PREFIX);     //~vba2R~
        return 0;                                                  //~vba2I~
    }                                                              //~vba2I~
    cblen=(int)SHORTPATHSZ+Pnamelen+1+Ppathlen+1;                  //~vba2R~
//#ifdef ARMXXE                                                    //~vby4R~
//    if (SdocUri)                                                 //~vby4R~
//        cblen+=(int)strlen(SdocUri)+1;                           //~vby4R~
//#endif                                                           //~vby4R~
    psp=(PSHORTPATH)umalloc((size_t)cblen);                        //~vba2R~
    memset(psp,0,(size_t)cblen);                                   //~vba2R~
    pc=psp->USPdata;                                               //~vba2I~
    psp->USPpname=pc;                                              //~vba2I~
    memcpy(pc,Pname,(size_t)Pnamelen);                             //~vba2R~
    pc+=Pnamelen+1;                                                //~vba2I~
    psp->USPppath=pc;                                              //~vba2I~
    memcpy(pc,Ppath,(size_t)Ppathlen);                             //~vba2R~
//#ifdef ARMXXE                                                    //~vby4R~
//    if (SdocUri)                                                 //~vby4R~
//    {                                                            //~vby4R~
//        pc+=Ppathlen+1;                                          //~vby4R~
//        psp->USPpstrUri=pc;                                      //~vby4R~
//        memcpy(pc,SdocUri,strlen(SdocUri));                      //~vby4R~
//    }                                                            //~vby4R~
//    else                                                         //~vby4R~
//        psp->USPpstrUri=0;                                       //~vby4R~
//#endif                                                           //~vby4R~
    UTRACED("pwp",psp,cblen);                                 //~vba2I~//~vby4R~
    return psp;                                                    //~vba2R~
}//funcsp_getentry                                                 //~vba2I~
//*********************************************************************************//~vba2I~
int funcsp_load(int Popt)                                          //~vba2R~
{                                                                  //~vba2I~
#define SP_BUFFSZ 4096                                             //~vba2I~
    char buff[SP_BUFFSZ],*pc,*pc2,*pc3;                            //~vba2R~
    char fpathsp[_MAX_PATH];                                       //~vba2I~
	FILE *fh;                                                      //~vba2I~
	PSHORTPATH psp;                                                //~vba2R~
    int linectr=0,len,namelen,pathlen;                              //~v6h7I~//~vba2R~
//************************                                         //~vba2I~
    filefullpath(fpathsp,WKFNM_SHORTPATH,sizeof(fpathsp));     //~v54nI~//~vba2I~
    fh=fopen(fpathsp,"r");                                         //~vba2I~
    if (!fh)                                                       //~vba2I~
        return 0;                                                  //~vba2I~
    while (fgets(buff,SP_BUFFSZ,fh))                               //~vba2I~
    {                                                              //~vba2I~
    	linectr++;                                                 //~vba2I~
    	len=(int)strlen(buff);                                     //~v6D0I~//~vba2I~
        if (len && *(buff+len-1)=='\n')                            //~vba2I~
        {                                                          //~vba2I~
            len--;                                                 //~vba2I~
            *(buff+len)=0;                                         //~vba2I~
        }                                                          //~vba2I~
        if (len && *(buff+len-1)=='\r') 	//0x0d                 //~v5baI~//~vba2I~
        {                                                          //~v5baI~//~vba2I~
            len--;                                                 //~v5baI~//~vba2I~
            *(buff+len)=0;                                         //~v5baI~//~vba2I~
        }                                                          //~v5baI~//~vba2I~
        pc=buff;                                                   //~vba2I~
        UTRACEP("%s:buff=%s\n",UTT,buff);                          //~vba2I~
        pc+=strspn(pc," \t");                                      //~vba2I~
        if (*pc=='#')	//comment                                  //~vba2R~
        	continue;                                              //~vba2I~
        pc2=strpbrk(pc," \t");                                     //~vba2I~
        if (!pc2)                                                  //~vba2I~
        {                                                          //~vba2I~
        	funcsp_errline(linectr,buff);                          //~vba2R~
            continue;                                              //~vba2I~
        }                                                          //~vba2I~
        namelen=PTRDIFF(pc2,pc);                                   //~vba2I~
        *pc2++=0;                                                  //~vba2I~
        UTRACEP("%s:len=%d,name=%s\n",UTT,namelen,pc);             //~vba2I~
        pc2+=strspn(pc2," \t");                                    //~vba2I~
        if (*pc2=='\"')                                            //~vba2I~
        {                                                          //~vba2I~
        	pc3=strchr(pc2+1,'\"');                                //~vba2R~
            if (pc3)                                               //~vba2I~
                pc3++;                                             //~vba2R~
        }                                                          //~vba2I~
        else                                                       //~vba2I~
        	pc3=strpbrk(pc2," \t");                                //~vba2R~
        if (!pc3)                                                  //~vba2I~
        	pathlen=(int)strlen(pc2);                              //~vba2R~
        else                                                       //~vba2I~
        {                                                          //~vba2I~
        	pathlen=PTRDIFF(pc3,pc2);                              //~vba2I~
            *pc3=0;                                                //~vba2R~
        }                                                          //~vba2I~
        UTRACEP("%s:len=%d,path=%s\n",UTT,pathlen,pc2);            //~vba2I~
#ifdef ARMXXE                                                      //~vby4I~
	  if (pc3)                                                     //~vby4I~
	  	psp=funcsp_getentryDoc(0,linectr,pc,namelen,pc2,pathlen,pc3+1);//~vby4I~
	  else	                                                       //~vby4I~
#endif                                                             //~vby4I~
        psp=funcsp_getentry(0,linectr,pc,namelen,pc2,pathlen);     //~vba2R~
        if (!psp)                                                  //~vba2I~
        	continue;                                              //~vba2I~
		UENQ(UQUE_END,&Sqhsp,psp);                                 //~vba2I~
    }                                                              //~vba2I~
    fclose(fh);                                                    //~vba2I~
#ifdef ARMXXE                                                      //~vby6I~
    ufile_notify_shortpath(&Sqhsp);                                //~vby6I~
#endif                                                             //~vby6I~
    return 0;                                                      //~vba2I~
}//funcsp_load                                                     //~vba2R~
//*********************************************************************************//~vba2I~
int funcsp_init(int Popt)                                          //~vba2I~
{                                                                  //~vba2I~
	int rc;                                                        //~vba2I~
//************************                                         //~vba2I~
	rc=funcsp_load(Popt);                                          //~vba2R~
    return rc;                                                     //~vba2I~
}//funcsp_init                                                     //~vba2I~
//*********************************************************************************//~vba2I~
int funcsp_append(int Popt,PUCLIENTWE Ppcw,PSHORTPATH Ppsp)        //~vba2R~
{                                                                  //~vba2I~
    char fpathsp[_MAX_PATH];                                       //~vba2I~
	FILE *fh;                                                      //~vba2I~
//************************                                         //~vba2I~
    filefullpath(fpathsp,WKFNM_SHORTPATH,sizeof(fpathsp));         //~vba2I~
    fh=fopen(fpathsp,"a");                                         //~vba2I~
    if (!fh)                                                       //~vba2I~
    	return ufileapierr("fopen",fpathsp,errno);                 //~vba2I~
//#ifdef ARMXXE                                                    //~vby4R~
//  if (Ppsp->USPpstrUri)                                          //~vby4R~
//     fprintf(fh,"%s %s %s\n",Ppsp->USPpname,Ppsp->USPppath,Ppsp->USPpstrUri);//~vby4R~
//  else                                                           //~vby4R~
//#endif                                                           //~vby4R~
    fprintf(fh,"%s %s\n",Ppsp->USPpname,Ppsp->USPppath);           //~vba2I~
    fclose(fh);                                                    //~vba2I~
    return 0;                                                      //~vba2I~
}//funcsp_init                                                     //~vba2I~
//*********************************************************************************//~vba2I~
void funcsp_term(int Popt)                                         //~vba2R~
{                                                                  //~vba2I~
//************************                                         //~vba2I~
	UQUFREE(&Sqhsp);                                               //~vba2I~
}//funcsp_term                                                     //~vba2I~
//*********************************************************************************//~vba2I~
int funcsp_edit(int Popt,PUCLIENTWE Ppcw)                          //~vba2I~
{                                                                  //~vba2I~
	int rc=0;                                                      //~vba2I~
    Ppcw->UCWparm=WKFNM_SHORTPATH;// "::xe.shortpath"              //~vba2I~
    rc=func_edit_file2(Ppcw,0);	//file name only                   //~vba2I~
    uerrmsg("If updated, to enable it, use \"SP refresh\" after saved or restart xe.",//~vba2R~//~vbyeR~
            "修正したら、それを有効化するには保存後 \"SP refresh\" するか xe を再起動");//~vba2R~//~vbyeR~
	return rc;                                                     //~vba2I~
}//funcsp_edit                                                     //~vba2I~
//*******************                                              //~vba2I~
int funcsp_chkopen(int Popt,PUCLIENTWE Ppcw,char *Pppath,PUFILEH *Pppfh)//~vba2I~
#define FSPCOO_ERRPENDING 0x01                                     //~vba2I~
{                                                                  //~vba2I~
	PUFILEH pfh=0;                                                 //~vba2I~
//*************************                                        //~vba2I~
    if (!filesrchpfh(WKFNM_SHORTPATH,Pppath,&pfh))//found          //~vba2R~
    {                                                              //~vba2I~
        if (Popt & FSPCOO_ERRPENDING)  //update chk                //~vba2R~
        {                                                          //~vba2I~
			if (pfh->UFHupctr!=pfh->UFHupctrsave)	//update after saved//~vba2I~
            {                                                      //~vba2I~
		    	uerrmsg("%s is opened, retry after close it.",     //~vba2I~
    		        	"%s が更新後未保存です、保存してから再試行してください",//~vba2I~
        		    	WKFNM_SHORTPATH);                          //~vba2I~
        		return 4;                                          //~vba2I~
            }                                                      //~vba2I~
        }                                                          //~vba2I~
        else                                                       //~vba2I~
        {                                                          //~vba2I~
	    	uerrmsg("%s is opened, retry after close it.",         //~vba2R~
    	        "%s がオープン中です、閉じてから再試行してください",//~vba2I~
        	    WKFNM_SHORTPATH);                                  //~vba2I~
        	return 4;                                              //~vba2R~
        }                                                          //~vba2I~
    }                                                              //~vba2I~
    *Pppfh=pfh;                                                    //~vba2I~
    return 0;                                                      //~vba2I~
}//funcsp_chkopen                                                  //~vba2I~
//*********************************************************************************//~vba2I~
int funcsp_refresh(int Popt,PUCLIENTWE Ppcw)                       //~vba2I~
{                                                                  //~vba2I~
	int rc;                                                        //~vba2R~
    PUFILEH pfh;                                                   //~vba2I~
    char fpathsp[_MAX_PATH];                                       //~vba2I~
//***********************************                              //~vba2I~
    if (funcsp_chkopen(FSPCOO_ERRPENDING,Ppcw,fpathsp,&pfh))//not found on fileq or err//~vba2R~
        return 4;                                                  //~vba2I~
	UQUFREE(&Sqhsp);                                               //~vba2I~
	rc=funcsp_load(0);                                             //~vba2R~
    uerrmsgcat("; Shortpath definition was refreshed.",            //~vba2R~
            "; 短縮パス名定義がリフレッシュされました");           //~vba2R~
	return rc;                                                     //~vba2I~
}//funcsp_refresh                                                  //~vba2I~
#ifdef ARMXXE                                                      //+vbyrI~
//*********************************************************************************//+vbyrI~
int refresh()                                                      //+vbyrI~
{                                                                  //+vbyrI~
	int rc=0;                                                      //+vbyrI~
//  PUFILEH pfh;                                                   //+vbyrI~
//  char fpathsp[_MAX_PATH];                                       //+vbyrI~
//***********************************                              //+vbyrI~
//  if (funcsp_chkopen(FSPCOO_ERRPENDING,Ppcw,fpathsp,&pfh))//not found on fileq or err//+vbyrI~
//      return 4;                                                  //+vbyrI~
	UQUFREE(&Sqhsp);                                               //+vbyrI~
	rc=funcsp_load(0);                                             //+vbyrI~
//  uerrmsgcat("; Shortpath definition was refreshed.",            //+vbyrI~
//          "; 短縮パス名定義がリフレッシュされました");           //+vbyrI~
	return rc;                                                     //+vbyrI~
}//funcsp_refresh                                                  //+vbyrI~
#endif //ARMXXE                                                    //+vbyrI~
//*********************************************************************************//~vba2I~
int funcsp_add(int Popt,PUCLIENTWE Ppcw,char *Ppname,char *Pppath) //~vba2R~
{                                                                  //~vba2I~
	int rc=0,len;                                                  //~vba2R~
    char *ppath;                                                   //~vba2I~
    PSHORTPATH psp;                                                //~vba2I~
    PUFILEH pfh;                                                   //~vba2I~
    char fpathsp[_MAX_PATH];                                       //~vba2I~
//*******************                                              //~vba2I~
    if (funcsp_chkopen(0,Ppcw,fpathsp,&pfh))//not found on fileq or err//~vba2R~
        return 4;                                                  //~vba2I~
	ppath=funcsp_search(0,Ppname);                                 //~vba2R~
    if (ppath)                                                     //~vba2I~
    {                                                              //~vba2I~
	    uerrmsg("Shortpath name:%s is already defined as %s.",     //~vba2I~
    	        "短縮パス名:%s は既存です(%s)",                    //~vba2I~
        	    Ppname,ppath);                                     //~vba2I~
        return 4;                                                  //~vba2I~
    }                                                              //~vba2I~
    if (!dcmdfullpath(Ppcw,fpathsp,Pppath))                        //~vba2I~
        return 4;                                                  //~vba2I~
    len=(int)strlen(fpathsp);                                      //~vba2R~
    if (strchr(fpathsp,' '))  //space embedding                    //~vba2I~
    {                                                              //~vba2I~
    	memmove(fpathsp+1,fpathsp,(size_t)len);                    //~vba2I~
        *fpathsp='\"';                                             //~vba2I~
        *(fpathsp+1+len)='\"';                                     //~vba2I~
        *(fpathsp+1+len+1)=0;                                      //~vba2I~
        len+=2;                                                    //~vba2I~
    }                                                              //~vba2I~
	psp=funcsp_getentry(0,-1,Ppname,(int)strlen(Ppname),fpathsp,len);//~vba2R~
    if (!psp)                                                      //~vba2I~
        return 4;                                                  //~vba2I~
	UENQ(UQUE_END,&Sqhsp,psp);                                     //~vba2I~
	funcsp_append(0,Ppcw,psp);                                     //~vba2R~
    uerrmsg("Shortpath name:%s was added as %s.",                  //~vba2R~
            "短縮パス名:%s が追加されました(%s)",                  //~vba2R~
            Ppname,fpathsp);                                       //~vba2R~
	return rc;                                                     //~vba2I~
}//funcsp_add                                                      //~vba2I~
#ifdef ARMXXE                                                      //~vby4I~
//*********************************************************************************//~vby4I~
PSHORTPATH funcsp_getentryDoc(int Popt,int Plineno,char *Pname,int Pnamelen,char *Ppath,int Ppathlen,char *PstrUri)//~vby4I~
{                                                                  //~vby4I~
	PSHORTPATH psp;                                                //~vby4I~
    int len;                                                       //~vby4I~
    char fpath[_MAX_PATH];                                         //~vby4I~
//*********************                                            //~vby4I~
//    SdocUri=PstrUri;                                             //~vby4R~
//	psp=funcsp_getentry(Popt,Plineno,Pname,Pnamelen,Ppath,Ppathlen);//~vby4R~
//    SdocUri=0;                                                   //~vby4R~
	len=makeDocPath(Pname,PstrUri,fpath);                      //~vby4R~
  	psp=funcsp_getentry(Popt,Plineno,Pname,Pnamelen,fpath,len);    //~vby4R~
    return psp;                                                    //~vby4I~
}//funcsp_getentry                                                 //~vby4I~
//*********************************************************************************//~vby4M~
void makePrefixDoc(char *PshortPath,char *PpathDoc,char *Pprefix)  //~vby4R~
{                                                                  //~vby4M~
	char *sp;                                                      //~vby4M~
//**********************                                           //~vby4M~
	sp=PshortPath+sizeof(PREFIX_ARM_SHARE)-1;                      //~vby4M~
    if (!*sp)                                                      //~vby4M~
    	sp=PpathDoc;                                               //~vby4M~
    sprintf(Pprefix,"%s%s",PREFIX_ARM_SHARE,sp);                   //~vby4R~
    UTRACEP("%s:shortPath=%s,docPath=%s,prefix=%s\n",UTT,PshortPath,PpathDoc,Pprefix);//~vby4M~
}                                                                  //~vby4M~
//*********************************************************************************//~vby4I~
void funcsp_filefullpathDoc(char *Pshortpath,char *PpathDoc/*uri format for root*/,char *Pfullpath)//~vby4R~
{                                                                  //~vby4I~
	char *pSubPath;                                                //~vby4I~
//**********************                                           //~vby4I~
	pSubPath=strchr(Pshortpath+sizeof(PREFIX_ARM_SHARE),DIR_SEPC); //~vby4R~
    strcpy(Pfullpath,PpathDoc);                                    //~vby4I~
    if (pSubPath)                                                  //~vby4I~
    	strcat(Pfullpath,pSubPath);                                //~vby4I~
    UTRACEP("%s:Pshortpath=%s,PpathDoc=%s,Pfullpath=%s\n",UTT,Pshortpath,PpathDoc,Pfullpath);//~vby4R~
}                                                                  //~vby4I~
//*********************************************************************************//~vby4I~
int funcsp_addDoc(int Popt,char *PshortPath,char *PstrUri,char *PpathDoc)//~vby4I~
{                                                                  //~vby4I~
	int rc=0;                                                      //~vby4I~
    PSHORTPATH psp;                                                //~vby4I~
    PUFILEH pfh;                                                   //~vby4I~
    char prefixSP[_MAX_PATH],*ppath;                                      //~vby4I~
    char fpathSPfile[_MAX_PATH];                                   //~vby4I~
	PUCLIENTWE pcw;                                                //~vby4I~
//*******************                                              //~vby4I~
    UTRACEP("%s:shortPath=%s,strUri=%s,docPath=%s\n",UTT,PshortPath,PstrUri,PpathDoc);//~vby4M~
	pcw=scrgetcw(0);	//active client                            //~vby4I~
	makePrefixDoc(PshortPath,PpathDoc,prefixSP);                    //~vby4I~
    if (funcsp_chkopen(0,pcw,fpathSPfile,&pfh))//not found on fileq or err//~vby4R~
        return 4;                                                  //~vby4I~
	ppath=funcsp_search(0,prefixSP);                               //~vby4R~
    if (ppath)                                                     //~vby4I~
    {                                                              //~vby4I~
	    uerrmsg("Shortpath name:%s is already defined as %s.",     //~vby4I~
    	        "短縮パス名:%s は既存です(%s)",                    //~vby4I~
        	    prefixSP,ppath);                                     //~vby4I~
        return 4;                                                  //~vby4I~
    }                                                              //~vby4I~
	psp=funcsp_getentryDoc(0,-1,prefixSP,(int)strlen(prefixSP),PpathDoc,(int)strlen(PpathDoc),PstrUri);//~vby4R~
    if (!psp)                                                      //~vby4I~
        return 4;                                                  //~vby4I~
	UENQ(UQUE_END,&Sqhsp,psp);                                     //~vby4I~
	funcsp_append(0,pcw,psp);                                     //~vby4I~
    uerrmsg("Shortpath name:%s was added as %s.",                  //~vby4I~
            "短縮パス名:%s が追加されました(%s)",                  //~vby4I~
            prefixSP,PpathDoc);                                       //~vby4I~
//  ufiledoc_notify_sp_changed();                                  //~vc5cI~//+vbyrR~
    refresh();                                                     //+vbyrI~
	return rc;                                                     //~vby4I~
}//funcsp_addDoc                                                   //~vby4I~
#endif //ARMXXE                                                    //~vby4I~
//**************************************************************** //~vba2I~
//!fncomp                                                          //~v0ctR~//~vba2I~
//*file name compare for uqscan                                    //~vba2I~
//*parm1:que element ptr                                           //~vba2I~
//*parm2:search key(file name)                                     //~vba2I~
//*rc   :0:match, 1:request forward search(UGETQNEXT)           //~4C19R~//~vba2I~
//**************************************************************** //~vba2I~
int funcsp_fncomp(PUQUEE Ppqe,PVOID Ppname)                        //~vba2I~
{                                                                  //~vba2I~
    PSHORTPATH psp;                                                //~vba2I~
    char *pname;                                                   //~vba2I~
//**********************************                               //~v48eI~//~vba2I~
    psp=(PSHORTPATH)Ppqe;                                          //~vba2I~
    pname=(char *)Ppname;                                          //~vba2I~
#ifdef UNX                                                         //~v20DI~//~vba2I~
	return strcmp(psp->USPpname,pname)!=0;                //~v48eI~//~vba2I~
#else  //!UNX                                                      //~v20DI~//~vba2I~
	return stricmp(psp->USPpname,pname)!=0;                        //~vba2I~
#endif //!UNX                                                      //~v20DI~//~vba2I~
}//funcsp_fncomp                                                   //~vba2I~
//*********************************************************************************//~vba2I~
char *funcsp_search(int Popt,char *Ppname)                         //~vba2I~
{                                                                  //~vba2I~
    PSHORTPATH psp;                                                //~vba2I~
#ifdef ARMXXE                                                      //~vby4I~
    char prefix[_MAX_PATH];                                        //~vby4I~
#endif                                                             //~vby4I~
//*******************                                              //~vba2I~
#ifdef ARMXXE                                                      //~vby4I~
	psp=0;                                                         //~vby4I~
    if (IS_DOCPATH(Ppname))                                        //~vby4I~
    {                                                              //~vby4I~
    	char *pc,*pc2;                                                  //~vby4R~
        pc=strchr(Ppname+sizeof(PREFIX_ARM_SHARE),SEP_ARM_SHARE);    //":" after "//"//~vby4R~
        if (!pc)                    // "//prefix/sub" patten       //~vby4I~
        {                                                          //~vby4I~
	        pc2=strchr(Ppname+sizeof(PREFIX_ARM_SHARE),DIR_SEPC);    //after "//"//~vby4I~
        	if (!pc2)                                              //~vby4R~
	            strcpy(prefix,Ppname);                               //~vby4I~
            else                                                   //~vby4I~
	            UmemcpyZ(prefix,Ppname,PTRDIFF(pc2,Ppname));       //~vby4R~
        }                                                          //~vby4I~
        else	// "//prefix:content://..../subdir patten          //~vby4I~
        {                                                          //~vby4I~
	    	UmemcpyZ(prefix,Ppname,PTRDIFF(pc,Ppname));            //~vby4I~
        }                                                          //~vby4I~
    	UTRACEP("%s:prefix=%s,Ppname=%s\n",UTT,prefix,Ppname);     //~vby4I~
    	psp = uqscan(UQUE_TOP, &Sqhsp, funcsp_fncomp,prefix);   //search by root prefix//~vby4I~
    }                                                              //~vby4I~
    if (!psp)                                                      //~vby4I~
#endif                                                             //~vby4I~
    if (!(psp = uqscan(UQUE_TOP, &Sqhsp, funcsp_fncomp, Ppname)))//not found//~vba2R~
    {                                                              //~vby4I~
    	UTRACEP("%s:sp=%s not found\n",UTT,Ppname);                //~vby4R~
        return 0;                                                  //~vba2I~
    }                                                              //~vby4I~
//#ifdef ARMXXE                                                    //~vby4R~
//    if (IS_DOCPATH(Ppname))                                      //~vby4R~
//    {                                                            //~vby4R~
//        UTRACEP("%s:arm return %s itself with // prefix\n",UTT,Ppname);//~vby4R~
//        return psp->USPppath;                                    //~vby4R~
//    }                                                            //~vby4R~
//#endif                                                           //~vby4R~
    UTRACEP("%s:sp=%s,real=%s\n",UTT,Ppname,psp->USPppath);        //~vby4R~
    return psp->USPppath;                                          //~vba2I~
}
#ifdef ARMXXE                                                      //~vby4R~
//*********************************************************************************//~vby4I~
int startArmPicker(int Popt,char *Palias)                          //~vby4I~
{                                                                  //~vby4I~
	int rc;                                                        //~vby4I~
//*******************                                              //~vby4I~
    UTRACEP("%s:alias=%s\n",UTT,Palias);                           //~vby4I~
	rc=c2j_startPicker(Popt,Palias);                               //~vby4I~
    return rc;                                                     //~vby4I~
}//startArmPicker                                                  //~vba2I~//~vbyeR~
////*********************************************************************************//~vby4R~
//void xefc7_getDirlistDoc(int Popt,char *PshortPath,char *PstrUri,char *PpathDoc)//~vby4R~
//{                                                                //~vby4R~
////    int fd;                                                    //~vby4R~
//    char dirName[_MAX_PATH];                                     //~vby4R~
//    PUDIRLIST pudirlist;                                         //~vby4R~
////***************                                                //~vby4R~
////    fd=c2j_getDirFD(0,PstrUri);                                //~vby4R~
////    udirlistFD(0,PshortPath,PpathDoc,PstrUri,fd);              //~vby4R~
////    UTRACEP("xefc7_udirlistDoc OPEN_TREE fd=%d\n",fd);         //~vby4R~
//    UTRACEP("xefc7_getDirlistDoc shortPath=%s,strUri=%s,path=%s\n",PshortPath,PstrUri,PpathDoc);//~vby4R~
//    sprintf(dirName,"%s:%s",PshortPath,PpathDoc);                //~vby4R~
//    udirlistDoc(0,dirName,PstrUri,0/*attrSelect*/,&pudirlist,'N'/*sortType:name*/);//~vby4R~
//    UTRACEP("xefc7_getDirlistDoc exit");                         //~vby4R~
//}                                                                //~vby4R~
//*********************************************************************************//~vby4M~
void xefc7_OnActivityResult(int PreqID,int Prc,char *PshortPath,char *PstrUri,char *PpathDoc)//~vby4R~
{                                                                  //~vby4I~
//***************                                                  //~vby4I~
    UTRACEP("xefc7_OnActivityResult reqID=%d,rc=%d,shortPath=%s,strUri=%s,docPath=%s\n",PreqID,Prc,PshortPath,PstrUri,PpathDoc);//~vby4R~
    if (PreqID==AID_OPEN_TREE)                                     //~vby4I~
    {                                                              //~vby4I~
    	if (Prc)                                                   //~vby4I~
    	{                                                          //~vby4I~
			uerrmsg("%s documet access failed for %s",0,           //~vby4I~
    				PshortPath);                                        //~vby4I~
			return;                                                //~vby4I~
    	}                                                          //~vby4I~
//  	xefc7_getDirlistDoc(0,PshortPath,PstrUri,PpathDoc);        //~vby4R~
    	funcsp_addDoc(0,PshortPath,PstrUri,PpathDoc);              //~vby4I~
    }                                                              //~vby4I~
    uinvalidateARM();                                              //~vby4I~
}                                                                  //~vby4I~
#endif //ARMXXE                                                    //~vby4R~
