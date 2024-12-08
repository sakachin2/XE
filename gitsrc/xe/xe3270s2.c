//*CID://+vb30R~:                              update#= 1132;      //+vb30R~
//*************************************************************
//vb30:160411 (LNX)Compiler warning                                //+vb30I~
//vafk:120624 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  use ULPTR(unsigned __int64/ULONG)//~vafkI~
//v79a:080808 DBCS other than Japanese                             //~v79aI~
//v9@b:080718 3270:no echo option for rsh cmd                      //~v9@bI~
//v8@D:080627 3270:(BUG)for the case multiple dest defined for same dest/user,set config option each time//~v8@DI~
//v8@B:080627 3270:submit cmd support by TSO SUBMIT cmd(cmd->3270, add TSO/cmd)//~v8@BI~
//v8@y:080625 3270:line mode by READY detection on last line at snap3270//~v8@yI~
//v8@v:080624 3270:prelogon msg chk required for the case 522 abend logoff//~v8@vI~
//v8@r:080621 3270:use not prelogon msg but logon flag to chk already logon//~v8@rI~
//                 acsidentaly host down is rare for real host     //~v8@rI~
//                 (confirm connected each time)                   //~v8@rI~
//            3270.c 3270s.h 3270s2.c 3270e.c                      //~v8@rI~
//v8@8:080613 3270:cmdline row parameter                           //~v8@8I~
//v8@6:080610 defines s3270 command string for each host           //~v8@6I~
//v8@5:080609 write ftp retry log to another log by append mode    //~v8@5I~
//v8@3:080602 receive also hostname on xehosts file to identify logon command//~v8@3I~
//v8@1:080526 (3270)TSOE support                                   //~v8@1I~
//v72F:061206 3270:configuarable emulator name                     //~v72FI~
//v72n:061127 3270:spf cmd to update spf info                      //~v72iI~
//v72i:061124 3270:timeout value is setable by cfg file            //~v72iI~
//v72h:061124 optionaly(cfg setup) allow SEQ dataset update(upload)//~v725I~
//v725:061117 3270:conf file support
//*************************************************************
//*xe3270s2.c                                                      //~v8@1R~
//*************************************************************

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>      //offsetof
#include <ctype.h>
#include <string.h>
#include <fcntl.h>

//**********
#ifdef LNX
	#define _MT		//multithred notification to UTRACE etc
    #include <unistd.h>
#else
	#include <dos.h>
	#include <errno.h>
#endif
//**********
#include <ulib.h>
#include <ualloc.h>
#include <uque.h>
#include <uerr.h>
#include <ufile.h>
#include <uftp.h>
#include <u3270.h>
#include <utrace.h>
#include <ustring.h>
#include <uedit.h>
#include <uparse.h>
#include <ucvext.h>                                                //~v79aI~

#include "xe.h"
#include "xe3270.h"
#define  GBL_XE3270
#include "xe3270s.h"

//*************************************************************
static char *Soptiontb[]={/*"SPF"*/	                               //~v8@yR~
                         /*,*/"NOPUTCONF"                          //~v8@yR~
                         ,"NOGETCONF"                              //~v8@5I~
						,0};                                       //~v8@1I~
static int  Soptiontb_flag[]={/*THTF2_SPF*/                        //~v8@yR~
                             /*,*/THTF2_NOPUTCONF                  //~v8@yR~
                             ,THTF2_NOGETCONF                      //~v8@5I~
						,0};                                       //~v8@1I~
//*************************************************************    //~v8@1I~
int readconfsub(char *Pfnm);
//int chkconfparm(char *Ppkey,char *Ppvalue);                      //~v8@1R~
int chkconfparm(char *Ppkey,char *Ppvalue,int Pmoreopdno,UCHAR **Pppmoreopd);//~v8@1R~
int srchconfd(int Popt,char *Phost);                               //~v8@8I~
PCONFDEST srchconfdbyparm(int Popt,char *Pparm,int Pparmlen);      //~v8@8I~
ULONG optionchk(int Popt,char *Poptstr,int Pmoreopdno,UCHAR **Pppmoreopd);//~v8@8R~
//****************************************************************
//*config file process
//****************************************************************
int readconf(void)
{
    int rc;
    char cfnm[_MAX_PATH];
    FILEFINDBUF3 ffb3;
//************************
UTRACEP("readconf entry\n");
    G3270confd[0].CONFDemulator=ustrdup(0,EM3270,0);    //default s3270 cmd//~v8@8R~
	if (!*G3270workdir)	//no config parm specified
    {
	    uerrmsgmt(1,"Warning:No config file used(if need use \"-W\" option)",0);
        return 0;
    }
    strcpy(cfnm,G3270workdir);
//  rc=ufstat(cfnm,&ffb3);                                         //+vb30R~
    rc=(int)ufstat(cfnm,&ffb3);                                    //+vb30I~
    if (rc)
    {
	    uerrmsgmt(1,"-W option err, %s not found",0,
					cfnm);
        return 4;
    }
    if (ffb3.attrFile & FILE_DIRECTORY)
    {
    	strcat(cfnm,DIR_SEPS CONFXE3270);
//      rc=ufstat(cfnm,&ffb3);                                     //+vb30R~
        rc=(int)ufstat(cfnm,&ffb3);                                //+vb30I~
	    if (rc)
    	{
	    	uerrmsgmt(1,"%s not found,No config file used",0,
						cfnm);
        	return 0;
    	}
    }
	uerrmsgmt(1,"start using config file: %s",0,
						cfnm);
    if (readconfsub(cfnm))
    	return 4;
UTRACEP("readconf exit \n");
    return 0;
}//readconf
//****************************************************************
//*config file process
//****************************************************************
int readconfsub(char *Pfnm)
{
	int rc=0,len,opt,opdno;
    int ii;                                                        //~v8@1I~
    FILE *fh;
//  char *pdelmstr=" \t=";                                         //~v8@1R~
    char *pdelmstr=" \t=,";                                        //~v8@1I~
    UCHAR  **pargc;
    void   *pargc0;
    char buff[MAX_CMDSZ+32];
//************************
UTRACEP("readconf sub entry\n");
	fh=fopen(Pfnm,"r");
    if (!fh)
    {
	    uerrmsgmt(1,"%s open failed",0,
        			Pfnm);
        return 4;
    }
//****
    while (fgets(buff,sizeof(buff),fh))
    {
//  	len=strlen(buff);                                          //+vb30R~
    	len=(int)strlen(buff);                                     //+vb30I~
        if (len && *(buff+len-1)=='\n')
        {
            len--;
            *(buff+len)=0;
        }
        if (len && *(buff+len-1)=='\r') 	//0x0d
        {
            len--;
            *(buff+len)=0;
        }
    	opt=UPARSETABISSPACE;
        uparsev(buff,&pargc,&opdno,opt,pdelmstr);//no ignore crlf,no delmstr
//      pargc0=(void*)(ULONG)pargc;   //free area                  //~vafkR~
        pargc0=(void*)(ULPTR)pargc;   //free area                  //~vafkI~
        if (!opdno)    //null line
        {
            continue;
            break;
        }
//      if (*pargc[0]=='#')	//1st opd                              //~v8@1R~
//      	continue;                                              //~v8@1R~
      if (*pargc[0]!='#')	//1st opd                              //~v8@1I~
      {                                                            //~v8@1I~
        for (ii=0;ii<opdno;ii++)                                   //~v8@1I~
            if (*pargc[ii]=='#')                                   //~v8@1I~
                break;                                             //~v8@1I~
        opdno=ii;                                                  //~v8@1I~
//      if (opdno<2 || chkconfparm(pargc[0],pargc[1]))             //~v8@1R~
        if (opdno<2 || chkconfparm(pargc[0],pargc[1],opdno-2,pargc+2))//~v8@1R~
        {
        	rc=4;
            uerrmsgmt(1,"config file(%s) has error(%s)",0,         //~v72iR~
            			Pfnm,buff);
            break;
        }
      }                                                            //~v8@1I~
    	if (pargc0)
	    	ufree(pargc0);
    }//err break
//****
	fclose(fh);
    if (G3270opt & (G3270OPT_SPFLVL1|G3270OPT_SPFLVL2))            //~v72iR~
    	if (!*G3270memblistcmd)                                    //~v72iR~
        {                                                          //~v72iI~
        	rc=4;                                                  //~v72iI~
            uerrmsgmt(1,"specify %s parm if use %s parm",0,        //~v72iI~
            			CONFIGP_CMDMEMBLIST,CONFIGP_SPFLEVEL);     //~v72iI~
        }                                                          //~v72iI~
UTRACEP("readconfsub exit\n");
    return rc;
}//readconfsub
//****************************************************************
//*config file process
//****************************************************************
//int chkconfparm(char *Ppkey,char *Ppvalue)                       //~v8@1R~
int chkconfparm(char *Ppkey,char *Ppvalue,int Pmoreopdno,UCHAR **Pppmoreopd)//~v8@1R~
{
	int rc=0,no;
    int retryno,verbsz;                                            //~v8@1R~
    char *pc,*pc2="",*pc3="";                                      //~v8@1R~
    PCONFDEST pconfd;                                              //~v8@8I~
    ULONG options;                                                 //~v8@8I~
    PUCVEXTCFG pcfg;                                               //~v79aI~
    int opt;                                                       //~v79aI~
//************************
UTRACEP("chkconfparm entry key=%s,value=%s\n",Ppkey,Ppvalue);      //~v79aR~
    for (;;)
    {
        if (!stricmp(Ppkey,CONFIGP_GETRETRY))
        {
        	no=atoi(Ppvalue);
            if (no<RETRYGETMIN || no>RETRYGETMAX)
            {
            	uerrmsgmt(1,"config parm err(%s value should be %d to %d)",0,
            				 CONFIGP_GETRETRY,RETRYGETMIN,RETRYGETMAX);
                rc=4;
	            break;
            }
            G3270retryget=no;
            uerrmsgmt(1,"config parm accepted: %s=%d",0,
            			 CONFIGP_GETRETRY,G3270retryget);
            break;
        }
        else
        if (!stricmp(Ppkey,CONFIGP_PUTRETRY))
        {
        	no=atoi(Ppvalue);
            if (no<RETRYPUTMIN || no>RETRYPUTMAX)
            {
            	uerrmsgmt(1,"config parm err(%s value should be %d to %d)",0,
            				 CONFIGP_PUTRETRY,RETRYPUTMIN,RETRYPUTMAX);
                rc=4;
	            break;
            }
            G3270retryput=no;
            uerrmsgmt(1,"config parm accepted: %s=%d",0,
            			 CONFIGP_PUTRETRY,G3270retryput);
            break;
        }
        else
        if (!stricmp(Ppkey,CONFIGP_CMDMEMBLIST))
        {
        	if (strlen(Ppvalue)>=MAX_CMDSZ)
            {
            	uerrmsgmt(1,"config parm err(%s length>=%d)",0,
            				 CONFIGP_CMDMEMBLIST,MAX_CMDSZ);
                rc=4;
	            break;
            }
            strcpy(G3270memblistcmd,Ppvalue);
            uerrmsgmt(1,"config parm accepted: %s=%s",0,
            				 CONFIGP_CMDMEMBLIST,G3270memblistcmd);
	        break;
        }
        verbsz=sizeof(CONFIGP_CMD3270)-1;                          //~v8@6I~
//      if (!stricmp(Ppkey,CONFIGP_CMD3270))                       //~v8@6R~
//      if (!memicmp(Ppkey,CONFIGP_CMD3270,verbsz))                //~v8@6I~//+vb30R~
        if (!memicmp(Ppkey,CONFIGP_CMD3270,(size_t)verbsz))        //+vb30I~
        {                                                          //~v72FI~
        	if (strlen(Ppvalue)>=MAX_CMDSZ)                        //~v72FI~
            {                                                      //~v72FI~
            	uerrmsgmt(1,"config parm err(%s length>=%d)",0,    //~v72FI~
            				 CONFIGP_CMD3270,MAX_CMDSZ);           //~v72FI~
                rc=4;                                              //~v72FI~
	            break;                                             //~v72FI~
            }                                                      //~v72FI~
//          strcpy(G3270emulator,Ppvalue);                         //~v8@6R~
            pc=Ppvalue;                                            //~v8@6I~
            if (!(pconfd=srchconfdbyparm(0,Ppkey,verbsz)))         //~v8@8R~
                break;                                             //~v8@6I~
            pconfd->CONFDemulator=ustrdup(0,pc,0);                 //~v8@8R~
            uerrmsgmt(1,"config parm accepted: %s=\"%s\"",0,       //~v8@6R~
//          				 CONFIGP_CMD3270,G3270emulator);       //~v8@6R~
            				 Ppkey,pc);                            //~v8@6I~
            rc=0;                                                  //~v8@6I~
	        break;                                                 //~v8@6M~
        }                                                          //~v72FI~
        if (!stricmp(Ppkey,CONFIGP_CHARSETCFG))                    //~v79aI~
        {                                                          //~v79aI~
        	opt=UCEIO_SAVECV|UCEIO_SAVEMAP;                        //~v79aR~
			rc=ucvext_mapinit(opt,Ppvalue,&pcfg);                  //~v79aR~
        	if (rc)                                                //~v79aI~
            {                                                      //~v79aI~
                rc=4;                                              //~v79aI~
                break;                                             //~v79aI~
            }                                                      //~v79aI~
            G3270pmapcfg=pcfg;                                     //~v79aR~
            uerrmsgmt(1,"config parm accepted: %s=\"%s\"",0,       //~v79aI~
            				 Ppkey,Ppvalue);                       //~v79aR~
            rc=0;                                                  //~v79aI~
	        break;                                                 //~v79aI~
        }                                                          //~v79aI~
        if (!stricmp(Ppkey,CONFIGP_PSUPLOAD))                      //~v72hI~
        {                                                          //~v72hI~
        	if (*Ppvalue=='1')                                     //~v72hI~
            	G3270opt|=G3270OPT_PSUPLOAD;                       //~v72hI~
            else                                                   //~v72hI~
        	if (*Ppvalue=='0')                                     //~v72hI~
            	G3270opt&=~G3270OPT_PSUPLOAD;                      //~v72hI~
            else                                                   //~v72hI~
            {                                                      //~v72hI~
            	uerrmsgmt(1,"config parm err(%s value is \"1\" or \"0\")",0,//~v72hI~
            				 CONFIGP_PSUPLOAD);                    //~v72hI~
                rc=4;                                              //~v72hI~
	            break;                                             //~v72hI~
            }                                                      //~v72hI~
            uerrmsgmt(1,"config parm accepted: %s=%c",0,           //~v72hI~
            			 CONFIGP_PSUPLOAD,*Ppvalue);               //~v72hI~
	        break;                                                 //~v72hI~
        }                                                          //~v72hI~
        if (!stricmp(Ppkey,CONFIGP_RSHECHO))                       //~v9@bR~
        {                                                          //~v9@bI~
        	if (*Ppvalue=='1')                                     //~v9@bI~
            	G3270opt&=~G3270OPT_NORSHECHO;                     //~v9@bI~
            else                                                   //~v9@bI~
        	if (*Ppvalue=='0')                                     //~v9@bI~
            	G3270opt|=G3270OPT_NORSHECHO;                      //~v9@bI~
            else                                                   //~v9@bI~
            {                                                      //~v9@bI~
            	uerrmsgmt(1,"config parm err(%s value is \"1\" or \"0\")",0,//~v9@bI~
            				 CONFIGP_RSHECHO);                     //~v9@bI~
                rc=4;                                              //~v9@bI~
	            break;                                             //~v9@bI~
            }                                                      //~v9@bI~
            uerrmsgmt(1,"config parm accepted: %s=%c",0,           //~v9@bI~
            			 CONFIGP_RSHECHO,*Ppvalue);                //~v9@bI~
	        break;                                                 //~v9@bI~
        }                                                          //~v9@bI~
        if (!stricmp(Ppkey,CONFIGP_CMDLINEROW))                    //~v8@8I~
        {                                                          //~v8@8I~
        	no=atoi(Ppvalue);                                      //~v8@8I~
            G3270cmdrow=max(0,no-1);                               //~v8@8R~
            uerrmsgmt(1,"config parm accepted: %s=%d",0,           //~v8@8I~
            			 CONFIGP_CMDLINEROW,G3270cmdrow+1);        //~v8@8R~
	        break;                                                 //~v8@8I~
        }                                                          //~v8@8I~
        if (!stricmp(Ppkey,CONFIGP_TO_CONNECT))                    //~v72iI~
        {                                                          //~v72iI~
            if (G3270opt & G3270OPT_CMDLINEC)	//cmd parameter setup//~v72iI~
            	uerrmsgmt(1,"config parm ignored,accepted command line parameter: %s=%d",0,//~v72iI~
            				 CONFIGP_TO_CONNECT,G3270to_connect);  //~v72iR~
            else                                                   //~v72iI~
            {                                                      //~v72iI~
        		no=atoi(Ppvalue);                                  //~v72iI~
            	G3270to_connect=no;                                //~v72iI~
            	uerrmsgmt(1,"config parm accepted: %s=%d",0,       //~v72iI~
            				 CONFIGP_TO_CONNECT,G3270to_connect);  //~v72iR~
            }                                                      //~v72iI~
	        break;                                                 //~v72iI~
        }                                                          //~v72iI~
        if (!stricmp(Ppkey,CONFIGP_TO_FTP))                        //~v72iI~
        {                                                          //~v72iI~
            if (G3270opt & G3270OPT_CMDLINET)	//cmd parameter setup//~v72iR~
            	uerrmsgmt(1,"config parm ignored,accepted command line parameter: %s=%d",0,//~v72iI~
            				 CONFIGP_TO_FTP,G3270to_ftp);          //~v72iR~
            else                                                   //~v72iI~
            {                                                      //~v72iI~
        	    no=atoi(Ppvalue);                                  //~v72iI~
            	G3270to_ftp=no;                                    //~v72iR~
            	uerrmsgmt(1,"config parm accepted: %s=%d",0,       //~v72iI~
            				 CONFIGP_TO_FTP,G3270to_ftp);          //~v72iR~
            }                                                      //~v72iI~
	        break;                                                 //~v72iI~
        }                                                          //~v72iI~
        if (!stricmp(Ppkey,CONFIGP_TO_TSOCMD))                     //~v72iI~
        {                                                          //~v72iI~
        	no=atoi(Ppvalue);                                      //~v72iI~
            G3270to_tsocmd=no;                                     //~v72iR~
            uerrmsgmt(1,"config parm accepted: %s=%d",0,           //~v72iI~
            			 CONFIGP_TO_TSOCMD,G3270to_tsocmd);        //~v72iR~
	        break;                                                 //~v72iI~
        }                                                          //~v72iI~
        if (!stricmp(Ppkey,CONFIGP_TO_LOGON))                      //~v8@1I~
        {                                                          //~v8@1I~
        		no=atoi(Ppvalue);                                  //~v8@1I~
            	G3270to_logon=no;                                  //~v8@1I~
            	uerrmsgmt(1,"config parm accepted: %s=%d",0,       //~v8@1I~
            				 CONFIGP_TO_LOGON,G3270to_logon);      //~v8@1I~
	        break;                                                 //~v8@1I~
        }                                                          //~v8@1I~
        if (!stricmp(Ppkey,CONFIGP_TO_LOGOFF))                     //~v8@3I~
        {                                                          //~v8@3I~
        		no=atoi(Ppvalue);                                  //~v8@3I~
            	G3270to_logoff=no;                                 //~v8@3I~
            	uerrmsgmt(1,"config parm accepted: %s=%d",0,       //~v8@3I~
            				 CONFIGP_TO_LOGOFF,G3270to_logoff);    //~v8@3I~
	        break;                                                 //~v8@3I~
        }                                                          //~v8@3I~
        if (!stricmp(Ppkey,CONFIGP_TO_DISCONN))                    //~v8@8I~
        {                                                          //~v8@8I~
        		no=atoi(Ppvalue);                                  //~v8@8I~
            	G3270to_disconn=no;                                //~v8@8I~
            	uerrmsgmt(1,"config parm accepted: %s=%d",0,       //~v8@8I~
            				 CONFIGP_TO_DISCONN,G3270to_disconn);  //~v8@8I~
	        break;                                                 //~v8@8I~
        }                                                          //~v8@8I~
        if (!stricmp(Ppkey,CONFIGP_SPFLEVEL))                      //~v72iI~
        {                                                          //~v72iI~
        	no=atoi(Ppvalue);                                      //~v72iI~
            switch(no)                                             //~v72iI~
            {                                                      //~v72iI~
            case 0:                                                //~v72iI~
                break;                                             //~v72iI~
            case 1:                                                //~v72iI~
                G3270opt|=G3270OPT_SPFLVL1;                        //~v72iI~
                break;                                             //~v72iI~
            case 2:                                                //~v72iI~
                G3270opt|=(G3270OPT_SPFLVL1|G3270OPT_SPFLVL2);     //~v72iR~
                break;                                             //~v72iI~
            default:                                               //~v72iI~
            	uerrmsgmt(1,"config parm err(%s value should be 0 to 2)",0,//~v72iI~
            				 CONFIGP_SPFLEVEL);                    //~v72iI~
                rc=4;                                              //~v72iI~
                break;                                             //~v72iI~
            }                                                      //~v72iI~
            if (!rc)                                               //~v72iI~
            	uerrmsgmt(1,"config parm accepted: %s=%d",0,       //~v72iI~
            				 CONFIGP_SPFLEVEL,no);                 //~v72iI~
	        break;                                                 //~v72iI~
        }                                                          //~v72iI~
        verbsz=sizeof(CONFIGP_CMDLOGON)-1;                         //~v8@1I~
//      if (!memicmp(Ppkey,CONFIGP_CMDLOGON,verbsz))               //~v8@1R~//+vb30R~
        if (!memicmp(Ppkey,CONFIGP_CMDLOGON,(size_t)verbsz))       //+vb30I~
        {                                                          //~v8@1I~
            if (!(pconfd=srchconfdbyparm(0,Ppkey,verbsz)))         //~v8@8R~
                break;                                             //~v8@8I~
            pc=strchr(Ppvalue,'%');                                //~v8@1R~
            if (pc)                                                //~v8@1I~
            {                                                      //~v8@1I~
                if (!(ustrstri(pc,CONFIGP_CMDLOGON_USER) || ustrstri(pc,CONFIGP_CMDLOGON_PSWD)))//~v8@1R~
                {                                                  //~v8@1I~
		            uerrmsgmt(1,"config parm err(%s), invalid %%parm%%",0,//~v8@1R~
            			 pc);                                      //~v8@1I~
                	rc=4;                                          //~v8@1I~
	            	break;                                         //~v8@1I~
                }                                                  //~v8@1I~
            }                                                      //~v8@1I~
            no=pconfd->CONFDlogoncmdno;                            //~v8@8I~
            if (no>=MAX_LOGONCMDNO)                                //~v8@8R~
            {                                                      //~v8@1I~
                uerrmsgmt(1,"config parm err(%s), max count(%d) over",0,//~v8@1R~
                     Ppvalue,MAX_LOGONCMDNO);                      //~v8@1I~
                rc=4;                                              //~v8@1I~
                break;                                             //~v8@1I~
            }                                                      //~v8@1I~
            pc=pconfd->CONFDlogoncmd[no]=ustrdup(0,Ppvalue,0);     //~v8@8R~
            if (Pmoreopdno>0) //response msg chk                   //~v8@1I~
            {                                                      //~v8@1I~
            	retryno=LOGONCMD_DEFAULT_RETRYNO; // 5  //logon response chk retry count default//~v8@6R~
	            pconfd->CONFDlogoncmdrespchk[no]=pc2=ustrdup(0,Pppmoreopd[0],0);//~v8@8R~
	            if (Pmoreopdno>1) //response msg chk               //~v8@1I~
                {                                                  //~v8@1I~
		            pc3=Pppmoreopd[1];                             //~v8@1R~
                    retryno=atoi(pc3);                             //~v8@1I~
                }                                                  //~v8@1I~
	            pconfd->CONFDlogoncmdrespchkretry[no]=retryno;     //~v8@8R~
            }                                                      //~v8@1I~
            pconfd->CONFDlogoncmdno=no+1;                          //~v8@8I~
            if (!rc)                                               //~v8@1I~
            	uerrmsgmt(1,"config parm accepted: %s=%s,%s,%s",0, //~v8@6R~
            				 Ppkey,pc,pc2,pc3);                    //~v8@1R~
	        break;                                                 //~v8@1I~
        }                                                          //~v8@1I~
        verbsz=sizeof(CONFIGP_CMDLOGOFF)-1;                        //~v8@1I~
//      if (!memicmp(Ppkey,CONFIGP_CMDLOGOFF,verbsz))              //~v8@1I~//+vb30R~
        if (!memicmp(Ppkey,CONFIGP_CMDLOGOFF,(size_t)verbsz))      //+vb30I~
        {                                                          //~v8@1I~
            if (!(pconfd=srchconfdbyparm(0,Ppkey,verbsz)))         //~v8@8R~
                break;                                             //~v8@8I~
            no=pconfd->CONFDlogoffcmdno;                           //~v8@8I~
            if (no>=MAX_LOGOFFCMDNO)                               //~v8@8R~
            {                                                      //~v8@1I~
                uerrmsgmt(1,"config parm err(%s), max count(%d) over",0,//~v8@1I~
                     Ppvalue,MAX_LOGOFFCMDNO);                     //~v8@1I~
                rc=4;                                              //~v8@1I~
                break;                                             //~v8@1I~
            }                                                      //~v8@1I~
            pc=pconfd->CONFDlogoffcmd[no]=ustrdup(0,Ppvalue,0);    //~v8@8R~
            if (Pmoreopdno>0) //response msg chk                   //~v8@6I~
            {                                                      //~v8@6I~
            	retryno=LOGOFFCMD_DEFAULT_RETRYNO; // 5  //logon response chk retry count default//~v8@6I~
	            pconfd->CONFDlogoffcmdrespchk[no]=pc2=ustrdup(0,Pppmoreopd[0],0);//~v8@8R~
	            if (Pmoreopdno>1) //response msg chk               //~v8@6I~
                {                                                  //~v8@6I~
		            pc3=Pppmoreopd[1];                             //~v8@6I~
                    retryno=atoi(pc3);                             //~v8@6I~
                }                                                  //~v8@6I~
	            pconfd->CONFDlogoffcmdrespchkretry[no]=retryno;    //~v8@8R~
            }                                                      //~v8@6I~
            pconfd->CONFDlogoffcmdno=no+1;                         //~v8@8I~
            if (!rc)                                               //~v8@1I~
            	uerrmsgmt(1,"config parm accepted: %s=%s,%s,%s",0, //~v8@6R~
            				 Ppkey,pc,pc2,pc3);                    //~v8@6I~
	        break;                                                 //~v8@1I~
        }                                                          //~v8@1I~
        verbsz=sizeof(CONFIGP_CMDLOGON_ERR)-1;                     //~v8@1I~
//      if (!memicmp(Ppkey,CONFIGP_CMDLOGON_ERR,verbsz))           //~v8@1R~//+vb30R~
        if (!memicmp(Ppkey,CONFIGP_CMDLOGON_ERR,(size_t)verbsz))   //+vb30I~
        {                                                          //~v8@1I~
            if (!(pconfd=srchconfdbyparm(0,Ppkey,verbsz)))         //~v8@8R~
                break;                                             //~v8@8I~
            no=pconfd->CONFDlogoncmderrmsgno;                      //~v8@8I~
            if (no>=MAX_LOGONERRMSGNO)                             //~v8@8R~
            {                                                      //~v8@1I~
                uerrmsgmt(1,"config parm err(%s), max count(%d) over",0,//~v8@1R~
                     Ppvalue,MAX_LOGONERRMSGNO);                   //~v8@1I~
                rc=4;                                              //~v8@1I~
                break;                                             //~v8@1I~
            }                                                      //~v8@1I~
            pconfd->CONFDlogoncmderrmsgtbl[no]=pc=ustrdup(0,Ppvalue,MAX_CHKMSGLEN);//~v8@8R~
            pc2="";                                                //~v8@1I~
            if (Pmoreopdno>0) //response msg chk                   //~v8@1R~
	            strncpy((pc2=pconfd->CONFDlogoncmderraction[no]),Pppmoreopd[0],MAX_ACTIONSZ);//~v8@8R~
            pconfd->CONFDlogoncmderrmsgno=no+1;                    //~v8@8I~
            uerrmsgmt(1,"config parm accepted: %s=%s %s",0,        //~v8@1R~
            				 Ppkey,pc,pc2);                        //~v8@1R~
	        break;                                                 //~v8@1I~
        }                                                          //~v8@1I~
//        verbsz=sizeof(CONFIGP_CMDLOGON_ALR)-1;                   //~v8@rR~
//        if (!memicmp(Ppkey,CONFIGP_CMDLOGON_ALR,verbsz))         //~v8@rR~
//        {                                                        //~v8@rR~
//            if (!(pconfd=srchconfdbyparm(0,Ppkey,verbsz)))       //~v8@rR~
//                break;                                           //~v8@rR~
//            no=pconfd->CONFDlogonalreadychkno;                   //~v8@rR~
//            if (no>=MAX_LOGONALREADYCHKNO)                       //~v8@rR~
//            {                                                    //~v8@rR~
//                uerrmsgmt(1,"config parm err(%s), max count(%d) over",0,//~v8@rR~
//                     Ppvalue,MAX_LOGONALREADYCHKNO);             //~v8@rR~
//                rc=4;                                            //~v8@rR~
//                break;                                           //~v8@rR~
//            }                                                    //~v8@rR~
//            pconfd->CONFDlogonalreadychktbl[no]=pc=ustrdup(0,Ppvalue,MAX_CHKMSGLEN);//~v8@rR~
//            pconfd->CONFDlogonalreadychkno=no+1;                 //~v8@rR~
//            uerrmsgmt(1,"config parm accepted: %s=%s",0,         //~v8@rR~
//                             Ppkey,pc);                          //~v8@rR~
//            break;                                               //~v8@rR~
//        }                                                        //~v8@rR~
        verbsz=sizeof(CONFIGP_CMDLOGON_PRE)-1;                     //~v8@vR~
//      if (!memicmp(Ppkey,CONFIGP_CMDLOGON_PRE,verbsz))           //~v8@vR~//+vb30R~
        if (!memicmp(Ppkey,CONFIGP_CMDLOGON_PRE,(size_t)verbsz))   //+vb30I~
        {                                                          //~v8@vR~
            if (!(pconfd=srchconfdbyparm(0,Ppkey,verbsz)))         //~v8@vR~
                break;                                             //~v8@vR~
            no=pconfd->CONFDprelogonno;                            //~v8@vR~
            if (no>=MAX_PRELOGONNO)                                //~v8@vR~
            {                                                      //~v8@vR~
                uerrmsgmt(1,"config parm err(%s), max count(%d) over",0,//~v8@vR~
                     Ppvalue,MAX_PRELOGONNO);                      //~v8@vR~
                rc=4;                                              //~v8@vR~
                break;                                             //~v8@vR~
            }                                                      //~v8@vR~
            pconfd->CONFDlogonprelogontbl[no]=pc=ustrdup(0,Ppvalue,MAX_CHKMSGLEN);//~v8@vR~
            pconfd->CONFDprelogonno=no+1;                          //~v8@vR~
            uerrmsgmt(1,"config parm accepted: %s=%s",0,           //~v8@vR~
                             Ppkey,pc);                            //~v8@vR~
            break;                                                 //~v8@vR~
        }                                                          //~v8@vR~
        verbsz=sizeof(CONFIGP_OPTIONS)-1;                          //~v8@1I~
//      if (!memicmp(Ppkey,CONFIGP_OPTIONS,verbsz))                //~v8@1I~//+vb30R~
        if (!memicmp(Ppkey,CONFIGP_OPTIONS,(size_t)verbsz))        //+vb30I~
        {                                                          //~v8@1I~
            if (!(pconfd=srchconfdbyparm(0,Ppkey,verbsz)))         //~v8@8R~
                break;                                             //~v8@8I~
            pc=Ppvalue;                                            //~v8@8R~
			if ((options=optionchk(0,pc,Pmoreopdno,Pppmoreopd))==0)//~v8@8R~
            {                                                      //~v8@8I~
                rc=4;                                              //~v8@8I~
                break;                                             //~v8@8I~
            }                                                      //~v8@8I~
            pconfd->CONFDoptions|=options;                         //~v8@8I~
            rc=0;                                                  //~v8@1I~
            uerrmsgmt(1,"config parm accepted: %s=%s",0,           //~v8@1I~
            				 Ppkey,pc);                            //~v8@1I~
	        break;                                                 //~v8@1I~
        }                                                          //~v8@1I~
        verbsz=sizeof(XE3270_QUERY_SUBMITWORK)-1;                  //~v8@BI~
//      if (!memicmp(Ppkey,XE3270_QUERY_SUBMITWORK,verbsz))        //~v8@BI~//+vb30R~
        if (!memicmp(Ppkey,XE3270_QUERY_SUBMITWORK,(size_t)verbsz))//+vb30I~
        {                                                          //~v8@BI~
            if (!(pconfd=srchconfdbyparm(0,Ppkey,verbsz)))         //~v8@BI~
                break;                                             //~v8@BI~
            pc=ustrdup(0,Ppvalue,0);    //default s3270 cmd        //~v8@BR~
            pconfd->CONFDsubmitwork=pc;                            //~v8@BI~
            rc=0;                                                  //~v8@BI~
            uerrmsgmt(1,"config parm accepted: %s=%s",0,           //~v8@BI~
            				 Ppkey,pc);                            //~v8@BI~
	        break;                                                 //~v8@BI~
        }                                                          //~v8@BI~
    	rc=4;
	    break;
    }
UTRACEP("chkconfparm exit rc=%d\n",rc);
    return rc;
}//chkconfparm
//**************************************************************** //~v8@8I~
//*search config dest table by dest name                           //~v8@8I~
//*opt:1 init,0:search                                             //~v8@8I~
//*ret:index or -4:overflow,0 for not found for serach(default entry)//~v8@8I~
//**************************************************************** //~v8@8I~
int srchconfd(int Popt,char *Phost)                                //~v8@8I~
{                                                                  //~v8@8I~
	int idx;                                                       //~v8@8I~
    PCONFDEST pconfd;                                              //~v8@8I~
//******************                                               //~v8@8I~
	if (!Phost||!*Phost)                                           //~v8@8R~
    	idx=0;                                                     //~v8@8I~
    else                                                           //~v8@8I~
    {                                                              //~v8@8I~
    	for (idx=1,pconfd=G3270confd+1;idx<G3270confdno;idx++,pconfd++)//~v8@8R~
        {                                                          //~v8@8I~
        	if (!stricmp(Phost,pconfd->CONFDhost))                 //~v8@8R~
            	break;                                             //~v8@8I~
        }                                                          //~v8@8I~
    	if (idx>=G3270confdno)  //not found                        //~v8@8I~
        {                                                          //~v8@8I~
        	if (!Popt)   	//search                               //~v8@8I~
    			idx=0;                                             //~v8@8I~
            else                                                   //~v8@8I~
            {                                                      //~v8@8I~
        		if (idx>=MAX_HOST)                                 //~v8@DR~
        		{                                                  //~v8@8I~
            		uerrmsgmt(1,"config parm hostname(%s) overflow(max count=%d)",0,//~v8@8I~
                		 		Phost,MAX_HOST);                   //~v8@8I~
            		return -4;                                     //~v8@8I~
        		}                                                  //~v8@8I~
	            strncpy(pconfd->CONFDhost,Phost,THTHOSTNAMESZ-1);  //~v8@DI~
    	        G3270confdno++;                                    //~v8@DI~
            }                                                      //~v8@8I~
        }                                                          //~v8@8I~
    }                                                              //~v8@8I~
    return idx;                                                    //~v8@8I~
}//srchconfd                                                       //~v8@8I~
//**************************************************************** //~v8@8I~
//*search config dest table by parm string                         //~v8@8I~
//**************************************************************** //~v8@8I~
PCONFDEST srchconfdbyparm(int Popt,char *Pparm,int Pparmlen)       //~v8@8I~
{                                                                  //~v8@8I~
	int idx;                                                       //~v8@8I~
    char *pc;                                                      //~v8@8I~
//******************                                               //~v8@8I~
	pc=Pparm+Pparmlen;                                             //~v8@8I~
    if (*pc=='.')	//hostname specified                           //~v8@8I~
    	idx=srchconfd(1,pc+1);                                     //~v8@8I~
    else                                                           //~v8@8I~
    	idx=0;                                                     //~v8@8I~
    if (idx<0)	//overflow                                         //~v8@8I~
    	return 0;                                                  //~v8@8I~
    return G3270confd+idx;                                         //~v8@8I~
}//srchconfdbyparm                                                 //~v8@8I~
//**************************************************************** //~v8@8I~
//*chec options parm                                               //~v8@8I~
//*ret:option,0 if err                                             //~v8@8I~
//**************************************************************** //~v8@8I~
ULONG optionchk(int Popt,char *Poptstr,int Pmoreopdno,UCHAR **Pppmoreopd)//~v8@8R~
{                                                                  //~v8@8I~
	int ii,jj;                                                     //~v8@8R~
    ULONG options=0;                                               //~v8@8I~
    char **ppc;                                                    //~v8@8I~
    char *poptstr;                                                 //~v8@8I~
//******************                                               //~v8@8I~
    for (jj=0;jj<Pmoreopdno+1;jj++)                                //~v8@8I~
    {                                                              //~v8@8I~
        if (jj==0)                                                 //~v8@8I~
      		poptstr=Poptstr;                                       //~v8@8I~
        else                                                       //~v8@8I~
      		poptstr=Pppmoreopd[jj-1];                              //~v8@8I~
    	for (ii=0,ppc=Soptiontb;*ppc;ii++,ppc++)                   //~v8@8I~
        	if (!stricmp(*ppc,poptstr))                            //~v8@8I~
            	break;                                             //~v8@8I~
        if (!*ppc)                                                 //~v8@8I~
        {                                                          //~v8@8I~
            uerrmsgmt(1,"config parm err(%s), invalid value(%s)",0,//~v8@8I~
                	 CONFIGP_OPTIONS,Poptstr);                     //~v8@8I~
            return 0;                                              //~v8@8I~
        }                                                          //~v8@8I~
//  	options|=Soptiontb_flag[ii]|THTF2_OPTIONSET;               //~v8@8I~//+vb30R~
    	options|=(ULONG)(Soptiontb_flag[ii]|THTF2_OPTIONSET);      //+vb30I~
    }//jj                                                          //~v8@8I~
    return options;                                                //~v8@8I~
}//optionchk                                                       //~v8@8I~
//**************************************************************** //~v8@8I~
//*get emulator string                                             //~v8@8R~
//**************************************************************** //~v8@8I~
char *cfggetemulator(int Popt,PTHREADTB Ppthtb)                    //~v8@8I~
{                                                                  //~v8@8I~
	char *pc;                                                      //~v8@8I~
    PCONFDEST pconfd;                                              //~v8@8I~
//******************                                               //~v8@8I~
	pconfd=G3270confd+Ppthtb->THThosttblidx;                       //~v8@8I~
    pc=pconfd->CONFDemulator;                                      //~v8@8I~
    if (!pc || !*pc)                                               //~v8@8R~
	    pc=G3270confd[0].CONFDemulator;                            //~v8@8I~
    return pc;                                                     //~v8@8I~
}//cfggetemulator                                                  //~v8@8I~
//**************************************************************** //~v8@8I~
//*get logon cmd count                                             //~v8@8I~
//**************************************************************** //~v8@8I~
int cfggetlogoncmdno(int Popt,PTHREADTB Ppthtb)                    //~v8@8I~
{                                                                  //~v8@8I~
    PCONFDEST pconfd;                                              //~v8@8I~
//******************                                               //~v8@8I~
	pconfd=cfggetlogoncmd(Popt,Ppthtb);                            //~v8@8R~
    return pconfd->CONFDlogoncmdno;                                //~v8@8R~
}//cfggetlogoncmdno                                                //~v8@8I~
//**************************************************************** //~v8@8I~
//*get logoff cmd count                                            //~v8@8I~
//**************************************************************** //~v8@8I~
int cfggetlogoffcmdno(int Popt,PTHREADTB Ppthtb)                   //~v8@8I~
{                                                                  //~v8@8I~
    PCONFDEST pconfd;                                              //~v8@8I~
//******************                                               //~v8@8I~
	pconfd=cfggetlogoffcmd(Popt,Ppthtb);                           //~v8@8I~
    return pconfd->CONFDlogoffcmdno;                               //~v8@8R~
}//cfggetlogoffcmdno                                               //~v8@8I~
//**************************************************************** //~v8@8I~
//*get logon cmd tbl                                               //~v8@8I~
//**************************************************************** //~v8@8I~
PCONFDEST cfggetlogoncmd(int Popt,PTHREADTB Ppthtb)                //~v8@8I~
{                                                                  //~v8@8I~
	int no;                                                        //~v8@8I~
    PCONFDEST pconfd;                                              //~v8@8I~
//******************                                               //~v8@8I~
	pconfd=G3270confd+Ppthtb->THThosttblidx;                       //~v8@8I~
    no=pconfd->CONFDlogoncmdno;                                    //~v8@8I~
    if (!no)                                                       //~v8@8I~
	    pconfd=G3270confd;                                         //~v8@8I~
    return pconfd;                                                 //~v8@8I~
}//cfggetlogoncmd                                                  //~v8@8I~
//**************************************************************** //~v8@8I~
//*get logoff cmd tbl                                              //~v8@8I~
//**************************************************************** //~v8@8I~
PCONFDEST cfggetlogoffcmd(int Popt,PTHREADTB Ppthtb)               //~v8@8I~
{                                                                  //~v8@8I~
	int no;                                                        //~v8@8I~
    PCONFDEST pconfd;                                              //~v8@8I~
//******************                                               //~v8@8I~
	pconfd=G3270confd+Ppthtb->THThosttblidx;                       //~v8@8I~
    no=pconfd->CONFDlogoffcmdno;                                   //~v8@8I~
    if (!no)                                                       //~v8@8I~
	    pconfd=G3270confd;                                         //~v8@8I~
    return pconfd;                                                 //~v8@8I~
}//cfggetlogoffcmd                                                 //~v8@8I~
//**************************************************************** //~v8@8I~
//*get logoff cmd tbl                                              //~v8@8I~
//**************************************************************** //~v8@8I~
PCONFDEST cfggetlogonerr(int Popt,PTHREADTB Ppthtb)                //~v8@8I~
{                                                                  //~v8@8I~
	int no;                                                        //~v8@8I~
    PCONFDEST pconfd;                                              //~v8@8I~
//******************                                               //~v8@8I~
	pconfd=G3270confd+Ppthtb->THThosttblidx;                       //~v8@8I~
    no=pconfd->CONFDlogoncmderrmsgno;                              //~v8@8I~
    if (!no)                                                       //~v8@8I~
	    pconfd=G3270confd;                                         //~v8@8I~
    return pconfd;                                                 //~v8@8I~
}//cfggetlogonerr                                                  //~v8@8I~
////****************************************************************//~v8@rR~
////*get logoff cmd tbl                                            //~v8@rR~
////****************************************************************//~v8@rR~
//PCONFDEST cfggetalready(int Popt,PTHREADTB Ppthtb)               //~v8@rR~
//{                                                                //~v8@rR~
//    int no;                                                      //~v8@rR~
//    PCONFDEST pconfd;                                            //~v8@rR~
////******************                                             //~v8@rR~
//    pconfd=G3270confd+Ppthtb->THThosttblidx;                     //~v8@rR~
//    no=pconfd->CONFDlogonalreadychkno;                           //~v8@rR~
//    if (!no)                                                     //~v8@rR~
//        pconfd=G3270confd;                                       //~v8@rR~
//    return pconfd;                                               //~v8@rR~
//}//cfggetalready                                                 //~v8@rR~
//**************************************************************** //~v8@vR~
//*get logoff cmd tbl                                              //~v8@vR~
//**************************************************************** //~v8@vR~
PCONFDEST cfggetprelogon(int Popt,PTHREADTB Ppthtb)                //~v8@vR~
{                                                                  //~v8@vR~
    int no;                                                        //~v8@vR~
    PCONFDEST pconfd;                                              //~v8@vR~
//******************                                               //~v8@vR~
    pconfd=G3270confd+Ppthtb->THThosttblidx;                       //~v8@vR~
    no=pconfd->CONFDprelogonno;                                    //~v8@vR~
    if (!no)                                                       //~v8@vR~
        pconfd=G3270confd;                                         //~v8@vR~
    return pconfd;                                                 //~v8@vR~
}//cfggetprelogon                                                  //~v8@vR~
//**************************************************************** //~v8@BI~
//*get logoff cmd tbl                                              //~v8@BI~
//**************************************************************** //~v8@BI~
int xe3270squery(int Popt,PTHREADTB Ppthtb,char **Ppopd)           //~v8@BR~
{                                                                  //~v8@BI~
    PCONFDEST pconfd;                                              //~v8@BI~
    char **popd,*pparmname,*pc;                                    //~v8@BR~
//******************                                               //~v8@BI~
	getcfgparm(0,Ppthtb);                                          //~v8@BI~
    pconfd=G3270confd+Ppthtb->THThosttblidx;                       //~v8@BI~
	popd=Ppopd+PARM_HOSTFILE;                                      //~v8@BI~
    pparmname=*popd;                                               //~v8@BM~
    if (!stricmp(pparmname,XE3270_QUERY_SUBMITWORK))               //~v8@BR~
    {                                                              //~v8@BI~
    	if (pc=pconfd->CONFDsubmitwork,!pc)                        //~v8@BI~
    		if (pc=G3270confd[0].CONFDsubmitwork,!pc)              //~v8@BI~
        		pc=XE3270_SUBMIT_WORK;                             //~v8@BR~
    	uerrmsgmt(1,"%s=%s",0,                                     //~v8@BI~
        	pparmname,pc);                                         //~v8@BR~
    }                                                              //~v8@BI~
    else                                                           //~v8@BI~
    {                                                              //~v8@BI~
    	uerrmsgmt(1,"Query parm(%s) err",0,                        //~v8@BR~
					pparmname);                                    //~v8@BR~
        return U3CR_RC_OTHER;                                      //~v8@BI~
    }                                                              //~v8@BI~
    return 0;    //issue errmsg                                    //~v8@BR~
}//xe3270squery                                                    //~v8@BI~
