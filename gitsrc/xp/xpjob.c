//CID://+v915R~:                                                   //+v915R~
//***********************************************************
//* XPRINT : file print utility  
//***********************************************************
//020719 v915 support FORM2P/WIN2P for prntyp OS2                  //+v915I~
//981028 v869 :docname parm support(/J)                            //~v869I~
//            (enumprinter is poor performance when remote search option,//~v869R~
//				logaddr is displayed when remote)                  //~v869I~
//981024 v865 :(OS2)docname set by startdoc api                    //~v865I~
//971129 v836 :GCC version                                         //~v836I~
//             xpinp.c,xpjob.c:alias and lfn                       //~v836I~
//951110 v74m :LAN support
//*************************************************************
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add
//*************************************************************

#define INCL_PM                                                    //~v865R~
#define INCL_SPLDOSPRINT  				//prqinfo3 v7.11a   //~v743I~
#define INCL_ERRORS                                                //~v865I~
#include <os2.h>         //v1.3 add                         //~v743I~
                                                                //~v743I~
//*************************************************************
#include <ulib.h>	                                            //~v743M~
#include <ufile.h>                                                 //~v836I~
//*********************************************************************
#include  "xp.h"                                                //~v74kI~
#include  "xp2p.h"                                                 //+v915I~
//*********************************************************************//~v74kI~
//* global                                                      //~v74lR~
//*********************************************************************
extern char pgmid[];                                            //~v74lI~
extern char ver[];                                              //~v74lI~
extern int  dbcsenv;           //dbcs environment sw v4.9a v7.23r//~v74lI~
extern char docname[];			//document name				v7.11a//~v74lI~
extern char *jobname;			//document name	override			v7.11a//~v869I~
extern int hdr0linesw;       //in xppf,header0 print req           //~v865I~
//*****************************************************************//~v865I~
static HAB Shab;                                                   //~v865I~
static HDC Shdc;                                                   //~v865I~
static  int Sopendocsw;                                            //~v865I~
//*****************************************************************//~v865I~
int os2_getdefqname(UCHAR *Pqname,ULONG Pbufflen);                 //~v865I~
int os2_srchqname(UCHAR *Pport,UCHAR *Pqname,ULONG Pbufflen);      //~v865I~
int os2_srchprinter(UCHAR *Pport,UCHAR *Pqname,ULONG Pbufflen);    //~v865I~
PPRQINFO6 os2_getqinf6(UCHAR *Pqname);                             //~v865I~
void os2_chkqinf6(PRQINFO6 *Ppprqi6,ULONG Plevel);                 //~v865I~
PPRDINFO3 os2_getdinf3(UCHAR *Pprintername);                       //~v865I~
void os2_chkdinf3(PPRDINFO3 Ppprdi3);                              //~v865I~
HDC  os2_devopen(PPRQINFO6 Ppprqi6);                               //~v865I~
void os2_chkdc(HDC Phdc);                                          //~v865I~
void udevquerycaps(HDC Phdc,LONG Pstart,LONG Pcnt,PLONG Pout);     //~v865I~
void os2_newpage(void);                                            //~v865I~
//*****************************************************************//~v865I~
//*********************************************
//*set comment/document name to os2 print job v7.11a
//*********************************************
//*parm:port name("LPTn")
//*rc 1:success
//*   0:invalid queue(stopped or not valid local queue)
//*********************************************
int setdocname(UCHAR *port)
{
static 	int firstsw=1;
static 	CHAR defaultq[64];	//quename
static 	CHAR queuename[64];	//quename
static 	CHAR splbuff[512];		//spl api buff
static  CHAR *porttbl,*porttblt;
	int i;
	UCHAR *pc,*pc2,*pc3;
	ULONG ulrc;
	ULONG namelen;
int setqjob(CHAR*);
//***********************
	if (firstsw)
	{
		firstsw=0;
//****** spooler active chk
		ulrc=PrfQueryProfileString(HINI_PROFILE,
         				         (PSZ)"PM_SPOOLER", //application
                        		(PSZ)"SPOOL",    //key
		                        NULL,            //token
        		                splbuff,	     //output
								(LONG)sizeof(splbuff));//buff len
		if (!ulrc)
		{
			printf("\n%s:%s:PrfQueryProfileString for spooler option failed,rc=%d;Use /Nd option.\n",pgmid,ver,ulrc);//~v749R~
			uexit(8);                                           //~v742R~
		}
//		printf("spool opt=%s\n",splbuff);
		if (splbuff[0]!='1')	//spooler inactive
		{
			if (dbcsenv)
				printf("\n%s:%s:スプーラー が使用禁止です。/Nd オプションを使って下さい。\n",pgmid,ver);//~v749R~
			else
				printf("\n%s:%s:spooler is inactive,Use /Nd option.\n",pgmid,ver);//~v749R~
			uexit (8);                                          //~v742R~
		}
//****** get default queue name
		ulrc=PrfQueryProfileString(HINI_PROFILE,
         				         (PSZ)"PM_SPOOLER", //application name
                        		(PSZ)"QUEUE",   //key
		                        NULL,           //token
        		                &defaultq,   //output buff
								(LONG)sizeof(defaultq));//bufflen
		if (!ulrc)
		{
			printf("\n%s:%s:PrfQueryProfileString for default Queue name failed,rc=%d;Use /Nd option.\n",pgmid,ver,ulrc);//~v749R~
			uexit(8);                                           //~v742R~
		}
		defaultq[strlen(defaultq)-1]=0;	//drop ";"
// 		printf("default queuename=%s\n",defaultq);
//****** get queuename related to output port
//****** get all port
		ulrc=PrfQueryProfileSize(HINI_PROFILE,
         				        (PSZ)"PM_SPOOLER_PRINTER",//application
                        		NULL,    //key=NULL:get all entry key
								&namelen);//get bufflen
		if (!ulrc)
		{
			printf("\n%s:%s:PrfQueryProfileSize for get port entry failed,rc=%d;Use /Nd option.\n",pgmid,ver,ulrc);//~v749R~
			uexit(8);                                           //~v742R~
		}
	   	porttblt=porttbl=malloc(namelen);

		ulrc=PrfQueryProfileString(HINI_PROFILE,
         				         (PSZ)"PM_SPOOLER_PRINTER",//application
                        		NULL,    //key=NULL:get all key
		                        NULL,    //token
        		                porttblt,//output buff
								namelen);//bufflen
		if (!ulrc)
		{
			printf("\n%s:%s:PrfQueryProfileString for Port tbl failed,rc=%d;Use /Nd option.\n",pgmid,ver,ulrc);//~v749R~
			uexit(8);                                           //~v742R~
		}
//		printf("port tbl entry len=%d\n",namelen);

//****** search  port
		for (i=0;i<namelen-1;)
		{
//			printf("port tbl entry =%s\n",porttbl);
			ulrc=PrfQueryProfileString(HINI_PROFILE,
         				       (PSZ)"PM_SPOOLER_PRINTER",//application
                        		porttbl,    //key
		                        NULL,       //token
        		                splbuff,    //output:port data
								sizeof(splbuff));//bufflen
			if (!ulrc)
			{
				printf("\n%s:%s:PrfQueryProfileString for Port data failed,rc=%d;Use /Nd option.\n",pgmid,ver,ulrc);//~v749R~
				uexit(8);                                       //~v742R~
			}
//			printf("port data=%s\n",splbuff);
			pc=strpbrk(splbuff,";");	//"LPTn;..."
			if (pc)
			{
				*pc=0;			//for psz
				if (!stricmp(splbuff,port))                     //~v742R~
					break;			//fount entry
			}	
			i+=(int)(strlen(porttbl)+1);
			porttbl=porttblt+i;
		}
		free(porttblt);

		if (i>=namelen-1)
		{
			if (dbcsenv)
				printf("\n%s:%s:%s が割り当てられていません。/Nd オプションを使って下さい。\n",pgmid,ver,port);//~v749R~
			else
				printf("\n%s:%s:%s has no related Queue,Use;Use /Nd option.\n",pgmid,ver,port);//~v749R~
			uexit(8);                                           //~v742R~
		}
//****** search queue name
		pc=strpbrk(pc+1,";");	//"LPTn;...;"
		if (pc)
		{
			pc2=pc3=++pc;				//"LPTn;...;q.."
			while(*pc2!=';') //"LPTn;...;q1,q2;"
			{
				pc2=strpbrk(pc,";,");
				if (!pc2)
					break;
				i=(int)((ULONG)pc2-(ULONG)pc);
				memcpy(queuename,pc,(UINT)i);
				queuename[i]=0;			//psz
				if (!stricmp(queuename,defaultq))	//defaultq on//~v742R~
					if (setqjob(queuename))
						return 1;
				pc=pc2+1;
			}
			pc2=pc=pc3;				//"LPTn;...;q.."
			while(*pc2!=';')
			{
				pc2=strpbrk(pc,";,");
				if (!pc2)
					break;
				i=(int)((ULONG)pc2-(ULONG)pc);
				memcpy(queuename,pc,(ULONG)i);
				queuename[i]=0;			//psz
				if (stricmp(queuename,defaultq))	//other than defaultq//~v742R~
					if (setqjob(queuename))
						return 1;
				pc=pc2+1;
			}
		}	
		if (dbcsenv)
			printf("\n%s:%s:%s の宛先キュ－不明,文書名設定機能停止。\n",pgmid,ver,port);//~v74lR~
		else
			printf("\n%s:%s:related Queue for %s is not found,Document name set function terminated.\n",pgmid,ver,port);//~v74lR~
	}//firstsw
	else
	{
		if (setqjob(queuename))
			return 1;
		if (dbcsenv)
			printf("\n%s:%s:印刷ジョブの宛先不明 ( %s ? ),文書名設定機能停止。\n",pgmid,ver,queuename);//~v749R~
		else
			printf("\n%s:%s:Where has gone my print job?(Not found on %s),Document name set function terminated.\n",pgmid,ver,queuename);//~v749R~
	}
	return 0;		//err
}//setdocname
//************************************************
//************************************************
//************************************************
int setqjob(UCHAR* qname)
{
static 	CHAR commentsys[]="システム";	//comment system
static 	CHAR commentxp[16];		//comment xprint+version
static	PPRJINFO2 pprjinfo2t=NULL;
	PPRJINFO2 pprjinfo2;
	int i;
	ULONG ulrc;
	ULONG ultot,ulret,bufflen,bufflen2;
//*************************************
	sprintf(commentxp,"%s:%s",pgmid,ver);

	if (pprjinfo2t)			//previous buff
		free(pprjinfo2t);

	ulrc=SplEnumJob(NULL,		//get buff size
                    qname,
                    2L,            //level prjinfo2
                    (PVOID)NULL,    //buff
                    0L,            //buff len
                    &ulret,      	//returned ent no
                    &ultot,       //total entry no
                    &bufflen,    //outbut len
                    NULL);
	if (ulrc && ulrc!=ERROR_MORE_DATA)
	{
		printf("%s:%s:SplEnumJob-1 failed,rc=%d;Use /Nd option.\n",pgmid,ver,ulrc);
		uexit(8);                                               //~v742R~
	}
	if (!bufflen)	//no data
		return 0;

	bufflen2=bufflen;
   	pprjinfo2t=pprjinfo2=malloc(bufflen2);
    ulrc=SplEnumJob(NULL,		//get entry
                    qname,
                    2L,            //level   prqinfo3 and prjinfo2
                    pprjinfo2,      //buff
                    bufflen2,      //buff len
                    &ulret,      //req ent no
                    &ultot,       //  avail no
                    &bufflen,	  //outputlen	
					NULL) ;
	if (ulrc && ulrc!=ERROR_MORE_DATA)
	{
		printf("%s:%s:SplEnumJob-2 failed,rc=%d;Use /Nd option.\n",pgmid,ver,ulrc);
		uexit(8);                                               //~v742R~
	}
//******** search current job
   	for(i=(int)ulret-1,pprjinfo2+=i;i>=0;i--)
   	{
//		printf("Jobid=%d,Prty=%d,User=%s,Pos=%d,status=%08x,comm=%s,doc=%s\n",
//				(ULONG)(pprjinfo2->uJobId),
//				(ULONG)(pprjinfo2->uPriority),
//				(pprjinfo2->pszUserName),
//				(ULONG)(pprjinfo2->uPosition),
//				(ULONG)(pprjinfo2->fsStatus),
//				(pprjinfo2->pszComment),
//				(pprjinfo2->pszDocument));
		if((pprjinfo2->fsStatus&PRJ_QSTATUS)==PRJ_QS_SPOOLING	//on spooling
		&&  !(pprjinfo2->pszDocument[0]))	//multiple parallel
		{
			break;
		}
		pprjinfo2--;
    }//all prjinfo2 entry

	if (i<0)	//my job not found
		return 0;
//*************
	ulrc=SplSetJob(NULL,
                   qname,
       	           pprjinfo2->uJobId,
           	       3L,            //level
   	               commentxp,
                   strlen(commentxp)+1,       //buff len
   	               PRJ_COMMENT_PARMNUM);    //outbut len
	if (ulrc)
	{
		printf("%s:%s:SplSetJob comment set failed for %s,rc=%d;Use /Nd option.\n",pgmid,ver,docname,ulrc);
		uexit(8);                                               //~v742R~
	}

	ulrc=SplSetJob(NULL,
                   qname,
                   pprjinfo2->uJobId,
                   3L,            //level
                   docname, //buff
                   strlen(docname)+1,       //buff len
                   PRJ_DOCUMENT_PARMNUM);    //outbut len
	if (ulrc)
	{
		printf("%s:%s:SplSetJob document-name set failed for %s,rc=%d;Use /Nd option.\n",pgmid,ver,docname,ulrc);
		uexit(8);                                               //~v742R~
	}
	return 1;
}//setqjob
//*****************************************************************//~v865I~
//*****************************************************************//~v865I~
//*****************************************************************//~v865I~
//*****************************************************************//~v865I~
//*os2 dev open                                                    //~v865I~
//*parm1:Output destination                                        //~v865R~
//*parm2:dest is prn/lptx                                          //~v865I~
//*parm3:docname set option                                        //~v865I~
//*ret :rc 1:output is printer,0:file                              //~v865I~
//*********************************************                    //~v865I~
int os2_devinit(UCHAR *Pport,int Pdestprnsw,int Pdocnamesw)        //~v865R~
{                                                                  //~v865I~
	PPRQINFO6 pprqi6;                                              //~v865I~
    UCHAR qname[256];                                              //~v865I~
    int rc=0;                                                      //~v865R~
//*********************	                                           //~v865I~
//printf("req dest=%s\n",Pport);                                   //~v869R~
    if (Pdocnamesw)                                                //~v865I~
    {                                                              //~v865I~
        Shab=WinInitialize(0);                                     //~v865R~
        for (;;)                                                   //~v865R~
        {                                                          //~v865R~
            pprqi6=0;       //fail id                              //~v865R~
            if (!Pport || !stricmp(Pport,"PRN"))    //serach    default//~v865R~
            {                                                      //~v865R~
                if (os2_getdefqname(qname,sizeof(qname)))          //~v865R~
                    break;                                         //~v865R~
            }                                                      //~v865R~
            else                                                   //~v865R~
                if (os2_srchqname(Pport,qname,sizeof(qname)))      //~v865R~
//                  if (os2_srchprinter(Pport,qname,sizeof(qname)))//~v869R~
         	           break;                                      //~v865R~
            pprqi6=os2_getqinf6(qname);                            //~v865R~
            break;                                                 //~v865R~
        }                                                          //~v865R~
        if (pprqi6)                                                //~v865R~
        {                                                          //~v865R~
            Shdc=os2_devopen(pprqi6);                              //~v865R~
            if (Shdc)                                              //~v865R~
            {                                                      //~v865R~
                rc=1;                                              //~v865R~
                if (stricmp(Pport,qname))                          //~v865R~
                    if (dbcsenv)    //DBCS mode                    //~v865R~
                        printf("出力先=%s(%s)\n",                  //~v865R~
								pprqi6->pszComment,qname);         //~v865I~
                    else            //SBCS                         //~v865R~
                        printf("Output destination=%s(%s)\n",      //~v865R~
								pprqi6->pszComment,qname);         //~v865I~
            }                                                      //~v865R~
            free(pprqi6);                                          //~v865M~
        }                                                          //~v865R~
    }//docnamesw on                                                //~v865I~
    if (!rc)    //docnamesw reset                                  //~v865I~
	    if (Pdestprnsw)		//prn,lptx                             //~v865R~
        {                                                          //~v865I~
            if (Pdocnamesw)                                        //~v865I~
            {                                                      //~v865I~
		        if (!pprqi6)                                       //~v865I~
	                if (dbcsenv)    //DBCS mode                    //~v865I~
    	                printf("出力Ｑが見つかりません.ジョブの文書名は設定されません\n");//~v865I~
        	        else            //SBCS                         //~v865I~
            	        printf("DestQ not found,Docname is not set to output job\n");//~v865I~
            }                                                      //~v865I~
        }                                                          //~v865I~
		else                                                       //~v865I~
        	if (dbcsenv)    //DBCS mode                            //~v865I~
            	printf("ファイル出力\n");                          //~v865R~
            else            //SBCS                                 //~v865I~
                printf("Output destination is file\n");            //~v865I~
                                                                   //~v865I~
	return rc;                                                     //~v865R~
}//os2_devinit                                                     //~v865I~
//*********************************************                    //~v865I~
//*os2_getdefqname                                                 //~v865I~
//*parm1:output buff                                               //~v865I~
//*parm2:output buff len                                           //~v865I~
//*rc   :                                                          //~v865I~
//*********************************************                    //~v865I~
int os2_getdefqname(UCHAR *Pqname,ULONG Pbufflen)                  //~v865I~
{                                                                  //~v865I~
	UINT ulrc;                                                     //~v865I~
	UCHAR 	spool[256];		//spool                                //~v865I~
//*********************                                            //~v865I~
//****** spooler active chk                                        //~v865I~
	*(spool+sizeof(spool)-1)=0;	//for the case cut by bufflen      //~v865I~
	ulrc=PrfQueryProfileString(HINI_SYSTEMPROFILE,	//search system profile//~v865I~
         				      	(PSZ)"PM_SPOOLER", 	//applname     //~v865I~
                        		(PSZ)"SPOOL",    	//keyanme      //~v865I~
		                        NULL,              	//return if not found//~v865I~
        		                spool,      		//output buff  //~v865I~
								(LONG)sizeof(spool)-1);//output buffsz//~v865I~
	if (!ulrc)                                                     //~v865I~
	{                                                              //~v865I~
		printf("PrfQueryProfileString(PM_SPOOLER,SPOOL) failed,rc=%d\n",WinGetLastError(Shab));//~v865I~
		return 4;                                                  //~v865I~
	}                                                              //~v865I~
//printf("PrfQueryProfileString(PM_SPOOLER,SPOOL)=%s\n",spool);    //~v869R~
//****** search queue name                                         //~v865I~
	*(Pqname+Pbufflen-1)=0;                                        //~v865I~
	ulrc=PrfQueryProfileString(HINI_PROFILE,                       //~v865I~
	         					(PSZ)"PM_SPOOLER", 	//applname     //~v865I~
                        		(PSZ)"QUEUE",    	//keyname      //~v865I~
		                        NULL,              	//str if not found//~v865I~
        		                Pqname,      		//outbuff      //~v865I~
								Pbufflen-1);//bufflen              //~v865I~
	if (!ulrc)                                                     //~v865I~
	{                                                              //~v865I~
		printf("PrfQueryProfileString(PM_SPOOLER,QUEUE) failed,rc=%d\n",WinGetLastError(Shab));//~v865I~
		return 8;                                                  //~v865I~
	}                                                              //~v865I~
//printf("PrfQueryProfileString(PM_SPOOLER,QUEUE)=%s\n",Pqname);   //~v869R~
    *(Pqname+strlen(Pqname)-1)=0;	//drop last ";"                //~v865I~
	return 0;                                                      //~v865I~
}//os2_getdefqname                                                 //~v865I~
//*********************************************                    //~v865I~
//*os2_srchqname                                                   //~v865I~
//*parm1:port name                                                 //~v865I~
//*parm2:output qname area                                         //~v865I~
//*parm3:output area len                                           //~v865I~
//*ret  :rc                                                        //~v865I~
//*********************************************                    //~v865I~
int os2_srchqname(UCHAR *Pport,UCHAR *Pqname,ULONG Pbufflen)       //~v865I~
{                                                                  //~v865I~
	ULONG ulrc,outcnt,totcnt,bufflen,needlen;                      //~v865I~
    PVOID   qbuff;                                                 //~v865I~
    int     found,ii;                                              //~v865R~
    PPRQINFO6 pprqi6;                                              //~v865I~
    PPRDINFO3 pprdi3;                                              //~v865I~
    UCHAR *pc,*pc2;                                                //~v869R~
//*********************                                            //~v865I~
//*chk required len                                                //~v865I~
	ulrc=SplEnumQueue(NULL,			//local                        //~v865I~
	 					6,			//level                        //~v865I~
                        0,			//buff                         //~v865I~
                        0,			//bufflen                      //~v865I~
		                &outcnt,	//retuned entry count          //~v865I~
		                &totcnt,	//total entry count            //~v865I~
		                &needlen,	//output bufflen               //~v865I~
        		        NULL);		//rsv                          //~v865I~
	if (ulrc!=ERROR_MORE_DATA && ulrc!=NERR_BufTooSmall)           //~v865I~
	{                                                              //~v865I~
		printf("SplEnumQueue-1 failed,rc=%d\n",ulrc);              //~v865I~
		return 4;                                                  //~v865I~
	}                                                              //~v865I~
	bufflen=needlen;                                               //~v865I~
    if (!bufflen)       //may 0 for totcnt!=0 case                 //~v869I~
        bufflen=4000;                                              //~v869I~
	pprqi6=qbuff=malloc(bufflen);                                  //~v865I~
//*enum                                                            //~v865I~
	ulrc=SplEnumQueue(NULL,			//local                        //~v865I~
	 					6,			//level                        //~v865I~
                        qbuff,			//buff                     //~v865I~
                        bufflen,			//bufflen              //~v865I~
		                &outcnt,	//retuned entry count          //~v865I~
		                &totcnt,	//total entry count            //~v865I~
		                &needlen,	//output bufflen               //~v865I~
        		        NULL);		//rsv                          //~v865I~
	if (ulrc)                                                      //~v865I~
	{                                                              //~v865I~
		printf("SplEnumQueue-2 failed,rc=%d\n",ulrc);              //~v865I~
		return 4;                                                  //~v865I~
	}                                                              //~v865I~
//****** chk port name                                             //~v865I~
//printf("enumq=%d\n",outcnt);                                     //~v869R~
	found=0;                                                       //~v865I~
	for (ii=0;ii<outcnt;ii++,pprqi6++)                             //~v865R~
    {                                                              //~v865I~
//os2_chkqinf6(pprqi6,6);                                          //~v869R~
//printf("by Printer\n");                                          //~v869R~
		if (!stricmp(Pport,pprqi6->pszName))                       //~v865I~
        	break;                                                 //~v865I~
		if (pprqi6->pszComment)                                    //~v869M~
			if (!stricmp(Pport,pprqi6->pszComment))                //~v869M~
        		break;                                             //~v869M~
		if (pprqi6->pszComment)                                    //~v869I~
			if (!stricmp(Pport,pprqi6->pszComment))                //~v869I~
        		break;                                             //~v869I~
		if (pprqi6->pszRemoteComputerName)                         //~v869I~
        {                                                          //~v869I~
        	pc=strchr(pprqi6->pszRemoteComputerName,'\\');         //~v869I~
            if (pc)                                                //~v869I~
            	if (*(pc+1)=='\\')                                 //~v869R~
					if (!stricmp(Pport,pc+2))                      //~v869R~
                    	break;                                     //~v869I~
        }                                                          //~v869I~
                                                                   //~v869I~
		if (pprqi6->pszPrinters)                                   //~v865R~
        {                                                          //~v865I~
            pc=pprqi6->pszPrinters;                                //~v869I~
            for (;;)                                               //~v869I~
            {                                                      //~v869I~
                pc2=strchr(pc,',');                                //~v869I~
                if (pc2)                                           //~v869I~
                    *pc2=0;                                        //~v869I~
                if (!stricmp(Pport,pc))                            //~v869R~
                    break;                                         //~v869R~
                pprdi3=os2_getdinf3(pc);                           //~v869R~
//printf("parm=%s,printer=%s,prd3=%08x\n",Pport,pc,pprdi3);        //~v869R~
                if (pprdi3) //success                              //~v869R~
                {                                                  //~v869R~
                    if (pprdi3->pszLogAddr)                        //~v869R~
                        if (!stricmp(Pport,pprdi3->pszLogAddr))    //~v869R~
                            found=1;                               //~v869R~
//printf("parm=%s,logaddr=%s,found=%d\n",Pport,pprdi3->pszLogAddr,found);//~v869R~
                    free(pprdi3);                                  //~v869R~
                    if (found)                                     //~v869R~
                        break;                                     //~v869R~
                }                                                  //~v869R~
                if (found)                                         //~v869I~
                	break;                                         //~v869I~
				if (!pc2)                                          //~v869I~
                	break;                                         //~v869I~
                pc=pc2+1;                                          //~v869I~
            }//all printers                                        //~v869R~
    	    if (found)                                             //~v869I~
        	    break;                                             //~v869I~
		}//printeres defined                                       //~v869R~
	}//enum q                                                      //~v865I~
	if (ii<outcnt)                                                 //~v865I~
    {                                                              //~v865I~
    	*(Pqname+Pbufflen-1)=0;                                    //~v865I~
    	strncpy(Pqname,pprqi6->pszName,Pbufflen-1);                //~v865I~
//printf("found enumqueue\n");                                     //~v869R~
//printf("srched qname=%s\n",Pqname);                              //~v869R~
    }                                                              //~v865I~
    free(qbuff);                                                   //~v865I~
                                                                   //~v865I~
	if (ii<outcnt)                                                 //~v865I~
    	return 0;                                                  //~v865R~
	return 4;                                                      //~v865R~
}//os2_srchqname                                                   //~v865I~
//*********************************************                    //~v865I~
//*os2_srchprinter(lptx of remote)                                 //~v865I~
//*parm1:port name                                                 //~v865I~
//*parm2:output qname area                                         //~v865I~
//*parm3:output area len                                           //~v865I~
//*ret  :rc 0:found                                                //~v869R~
//*********************************************                    //~v865I~
int os2_srchprinter(UCHAR *Pport,UCHAR *Pqname,ULONG Pbufflen)     //~v865I~
{                                                                  //~v865I~
	ULONG ulrc,srchtype,outcnt,totcnt,bufflen,needlen;             //~v865I~
    PVOID   buff;                                                  //~v865I~
    int     ii;                                                    //~v865I~
    PPRINTERINFO pprni;                                            //~v865I~
//*********************                                            //~v865I~
	srchtype=SPL_PR_QUEUE                                          //~v865I~
	        |SPL_PR_QUEUED_DEVICE;                                 //~v865I~
//*chk required len                                                //~v865I~
	ulrc=SplEnumPrinter(NULL,			//local                    //~v865I~
	 					0,			//level                        //~v865I~
                        srchtype,                                  //~v865I~
                        NULL,    	//buff                         //~v865I~
                        NULL,   	//bufflen                      //~v865I~
		                &outcnt,	//retuned entry count          //~v865I~
		                &totcnt,	//total entry count            //~v865I~
		                &needlen,	//output bufflen               //~v865I~
        		        NULL);		//rsv                          //~v865I~
	if (ulrc!=ERROR_MORE_DATA && ulrc!=NERR_BufTooSmall)           //~v865I~
	{                                                              //~v865I~
		printf("SplEnumPrinter-1 failed,rc=%d\n",ulrc);            //~v865I~
		return 4;                                                  //~v865I~
	}                                                              //~v865I~
	bufflen=needlen;                                               //~v865I~
    if (!bufflen)       //may 0 for totcnt!=0 case                 //~v869I~
        bufflen=4000;                                              //~v869I~
	pprni=buff=malloc(bufflen);                                    //~v865I~
//*enum                                                            //~v865I~
	ulrc=SplEnumPrinter(NULL,			//local                    //~v865I~
	 					0,			//level                        //~v865I~
                        srchtype,                                  //~v865I~
                        buff,		//buff                         //~v865I~
                        bufflen,	//bufflen                      //~v865I~
		                &outcnt,	//retuned entry count          //~v865I~
		                &totcnt,	//total entry count            //~v865I~
		                &needlen,	//output bufflen               //~v865I~
        		        NULL);		//rsv                          //~v865I~
	if (ulrc)                                                      //~v865I~
	{                                                              //~v865I~
		printf("SplEnumPrinter-2 failed,rc=%d\n",ulrc);            //~v869R~
		return 4;                                                  //~v865I~
	}                                                              //~v865I~
//****** chk port name                                             //~v865I~
//printf("enumprinter=%d\n",outcnt);                               //~v869R~
	for (ii=0;ii<outcnt;ii++,pprni++)                              //~v865I~
    {                                                              //~v865I~
//printf("enumprinter %08x type=%08x,dest=%s,desc=%s,localname=%s\n",//~v869R~
//        pprni,                                                   //~v869R~
//        pprni->flType,                                           //~v869R~
//        pprni->pszPrintDestinationName,                          //~v869R~
//        pprni->pszDescription,                                   //~v869R~
//        pprni->pszLocalName);                                    //~v869R~
		if (pprni->pszPrintDestinationName)                        //~v865I~
			if (!stricmp(Pport,pprni->pszPrintDestinationName))    //~v865I~
    	    	break;                                             //~v865I~
		if (pprni->pszDescription)                                 //~v865I~
			if (!stricmp(Pport,pprni->pszDescription))             //~v865I~
	        	break;                                             //~v865I~
		if (pprni->pszLocalName)                                   //~v865I~
			if (!stricmp(Pport,pprni->pszLocalName))               //~v865I~
    	    	break;                                             //~v865I~
	}//enum printer                                                //~v865I~
    if (ii>=outcnt)                                                //~v865I~
    	return 4;                                                  //~v865I~
    *(Pqname+Pbufflen-1)=0;                                        //~v865I~
    strncpy(Pqname,pprni->pszPrintDestinationName,Pbufflen-1);     //~v865I~
//printf("found enum printer\n");                                  //~v869R~
//printf("srched destname=%s\n",Pqname);                           //~v869R~
	return 0;                                                      //~v865I~
}//os2_srchprinter                                                 //~v865I~
//*********************************************                    //~v865I~
//*os2_getqinf6                                                    //~v865I~
//*parm1:qname                                                     //~v865I~
//*return:PPRQINFO6,caller must free                               //~v865I~
//*********************************************                    //~v865I~
PPRQINFO6 os2_getqinf6(UCHAR *Pqname)                              //~v865I~
{                                                                  //~v865I~
	ULONG ulrc,outlen;                                             //~v865I~
	PPRQINFO6 pprqi6;                                              //~v865I~
//*********************                                            //~v865I~
//printf("os2_getqinf6\n");                                        //~v869R~
	ulrc=SplQueryQueue(NULL,				//local                //~v865I~
         				Pqname,				//qname                //~v865I~
                        6,					//info level           //~v865I~
		                0,					//output area          //~v865I~
        		        0,					//buffsz               //~v865I~
						&outlen);                                  //~v865I~
//printf("SplQueryQueue rc=%d\n",ulrc);                            //~v869R~
	if (ulrc!=ERROR_MORE_DATA && ulrc!=NERR_BufTooSmall)           //~v865I~
	{                                                              //~v865I~
		printf("SplQueryQueue-1 for %s failed,,rc=%d\n",Pqname,ulrc);//~v865I~
		return 0;                                                  //~v865I~
	}                                                              //~v865I~
    pprqi6=malloc(outlen);                                         //~v865I~
	ulrc=SplQueryQueue(NULL,				//local                //~v865I~
         				Pqname,				//qname                //~v865I~
                        6,					//info level           //~v865I~
		                pprqi6,				//output area          //~v865I~
        		        outlen,				//buffsz               //~v865I~
						&outlen);                                  //~v865I~
	if (ulrc)                                                      //~v865I~
	{                                                              //~v865I~
		printf("SplQueryQueue-2 for %s failed,rc=%d\n",Pqname,ulrc);//~v865I~
		return 0;                                                  //~v865I~
	}                                                              //~v865I~
//os2_chkqinf6(pprqi6,6);                                          //~v869R~
	return pprqi6;                                                 //~v865I~
}//os2_getqinf6                                                    //~v865I~
//*********************************************                    //~v865I~
//*os2_chkqinf6	:display prqinfo6 for debug                        //~v865I~
//*parm1:PRQINFO6 ptr                                              //~v865I~
//*parm2:level 3 or 6                                              //~v865I~
//*return:none                                                     //~v865I~
//*********************************************                    //~v865I~
void os2_chkqinf6(PPRQINFO6 Ppprqi6,ULONG Plevel)                  //~v865I~
{                                                                  //~v865I~
//*********************                                            //~v865I~
//UTRACED("QINF6",Ppprqi6,sizeof(PRQINFO6));                       //~v865I~
//UTRACE_INIT("xpt.trc",3);	//close                                //~v865I~
	printf("PRQINFO%d :Name=%s,SepFile=%s,PrProc=%s,Parms=%s,Comment=%s,\
Printers=%s,DriverName=%s,DriverData.DeviceName=%s\n",             //~v865I~
			Plevel,                                                //~v865I~
			Ppprqi6->pszName,                                      //~v865I~
			Ppprqi6->pszSepFile,                                   //~v865I~
			Ppprqi6->pszPrProc,                                    //~v865I~
			Ppprqi6->pszParms,                                     //~v865I~
			Ppprqi6->pszComment,                                   //~v865I~
			Ppprqi6->pszPrinters,                                  //~v865I~
			Ppprqi6->pszDriverName,                                //~v865I~
			Ppprqi6->pDriverData->szDeviceName);                   //~v865I~
	if (Plevel==6)                                                 //~v865I~
		printf("    remote=(%s,%s)\n",                             //~v865I~
			Ppprqi6->pszRemoteComputerName,                        //~v865I~
			Ppprqi6->pszRemoteQueueName);                          //~v865I~
	return;                                                        //~v865I~
}//os2_chkqinf6                                                    //~v865I~
//*********************************************                    //~v865I~
//*os2_getdinf3                                                    //~v865I~
//*parm1:printer name                                              //~v865I~
//*retrn:prdinf3                                                   //~v865I~
//*********************************************                    //~v865I~
PPRDINFO3 os2_getdinf3(UCHAR *Pprintername)                        //~v865I~
{                                                                  //~v865I~
	ULONG ulrc,outlen;                                             //~v865I~
    PPRDINFO3 pprdi3;                                              //~v865I~
//*********************                                            //~v865I~
	ulrc=SplQueryDevice(NULL,		//local                        //~v865I~
	         				Pprintername,		//printer device name//~v865I~
                        	3,			//level                    //~v865I~
		                    0,			//buff                     //~v865I~
        		            0,			//bufflen                  //~v865I~
							&outlen);                              //~v865I~
	if (ulrc!=NERR_BufTooSmall)                                    //~v865I~
    {                                                              //~v865I~
		printf("SplQueryDevice-1 for %s failed,rc=%d\n",Pprintername,ulrc);//~v865I~
        return 0;                                                  //~v865I~
    }                                                              //~v865I~
	pprdi3=malloc(outlen);                                         //~v865I~
	ulrc=SplQueryDevice(NULL,		//local                        //~v865I~
	         				Pprintername,		//printer device name//~v865I~
                        	3,			//level                    //~v865I~
		                    pprdi3, 	//buff                     //~v865I~
        		            outlen,		//bufflen                  //~v865I~
							&outlen);                              //~v865I~
	if (ulrc)                                                      //~v865I~
    {                                                              //~v865I~
		printf("SplQueryDevice-2 for %s failed,rc=%d\n",Pprintername,ulrc);//~v865I~
        free(pprdi3);                                              //~v865I~
        return 0;                                                  //~v865I~
    }                                                              //~v865I~
//os2_chkdinf3(pprdi3);		                                       //~v869R~
    return pprdi3;                                                 //~v865I~
}//os2_getdinf3                                                    //~v865I~
//*********************************************                    //~v865I~
//*os2_chkdinf3	:display prdinfo3 for debug                        //~v865I~
//*parm1:PRDINFO3 ptr                                              //~v865I~
//*return:none                                                     //~v865I~
//*********************************************                    //~v865I~
void os2_chkdinf3(PPRDINFO3 Ppprdi3)                               //~v865I~
{                                                                  //~v865I~
//*********************                                            //~v865I~
	printf("PRDINFO3 :PrinterName=%s,UserName=%s,LogAddr=%s,Status=%s,\
Comment=%s,Drivers=%s\n",                                          //~v865I~
			Ppprdi3->pszPrinterName,                               //~v865I~
			Ppprdi3->pszUserName,                                  //~v865I~
			Ppprdi3->pszLogAddr,                                   //~v865I~
			Ppprdi3->pszStatus,                                    //~v865I~
			Ppprdi3->pszComment,                                   //~v865I~
			Ppprdi3->pszDrivers);                                  //~v865I~
	return;                                                        //~v865I~
}//os2_chkdinf3                                                    //~v865I~
//*********************************************                    //~v865I~
//*os2_ devopen                                                    //~v865I~
//*parm:PRQINFO3                                                   //~v865I~
//*rc  :HDC                                                        //~v865I~
//*********************************************                    //~v865I~
HDC os2_devopen(PPRQINFO6 Ppprqi6)                                 //~v865I~
{                                                                  //~v865I~
	HDC hdc;                                                       //~v865I~
    DEVOPENSTRUC devos;                                            //~v865I~
    UCHAR *pc;                                                     //~v865I~
//*********************                                            //~v865I~
    memset(&devos,0,sizeof(devos));                                //~v865I~
    if (pc=strchr(Ppprqi6->pszDriverName,'.'),pc)                  //~v865I~
    	*pc=0;				//drivername.printer name              //~v865I~
    devos.pszLogAddress=Ppprqi6->pszName;   //qname                //~v865R~
    devos.pszDriverName=Ppprqi6->pszDriverName;                    //~v865I~
    devos.pdriv        =Ppprqi6->pDriverData;                      //~v865I~
    devos.pszDataType  ="PM_Q_RAW";                                //~v865I~
//printf("devopen logaddr=%s,driver=%s,type=%s,drvdata=%s\n",      //~v869R~
//    devos.pszLogAddress,                                         //~v869R~
//    devos.pszDriverName,                                         //~v869R~
//    devos.pszDataType,                                           //~v869R~
//    devos.pdriv);                                                //~v869R~
    hdc=DevOpenDC(Shab,                                            //~v865I~
					OD_QUEUED,      //dev context tyep             //~v865I~
					"*",			//default token                //~v865I~
					4,				//parm cnt of DEVOPENSTRUC     //~v865I~
					(PDEVOPENDATA)(PVOID)(&devos),                 //~v865I~
    				NULL);                                         //~v865R~
	if (!hdc)                                                      //~v865I~
    {                                                              //~v865I~
		printf("DevOpenDC(printer=%s,driver=%s,drivedata=%s) failed,rc=%d\n",//~v865I~
		    devos.pszLogAddress,                                   //~v865I~
		    devos.pszDriverName,                                   //~v865I~
		    devos.pdriv->szDeviceName,                             //~v865I~
					WinGetLastError(Shab));                        //~v865I~
        return 0;                                                  //~v865I~
	}                                                              //~v865I~
//os2_chkdc(hdc);                                                  //~v869R~
    return hdc;                                                    //~v865I~
}//os2_devopen                                                     //~v865I~
//*********************************************                    //~v865I~
//*os2_ chkdc                                                      //~v865I~
//*parm:HDC                                                        //~v865I~
//*rc  :none                                                       //~v865I~
//*********************************************                    //~v865I~
void os2_chkdc(HDC Phdc)                                           //~v865I~
{                                                                  //~v865I~
	long caps[CAPS_LINEWIDTH_THICK-CAPS_FAMILY+1];                 //~v865I~
//*************************                                        //~v865I~
	udevquerycaps(Phdc,CAPS_FAMILY,CAPS_LINEWIDTH_THICK-CAPS_FAMILY+1,caps);//~v865I~
	printf(                                                        //~v865I~
"CAPS_WIDTH=%d,\
CAPS_HEIGHT=%d,\
CAPS_WIDTH_IN_CHARS=%d,\
CAPS_HEIGHT_IN_CHARS=%d,\
CAPS_DEVICE_FONTS=%d,\
CAPS_GRAPHICS_CHAR_WIDTH=%d,\
CAPS_GRAPHICS_CHAR_HEIGHT=%d,\
CAPS_HORIZONTAL_FONT_RES=%d,\
CAPS_VERTICAL_FONT_RES=%d\n",                                      //~v865I~
                                                                   //~v865I~
caps[CAPS_WIDTH-CAPS_FAMILY],                                      //~v865I~
caps[CAPS_HEIGHT-CAPS_FAMILY],                                     //~v865I~
caps[CAPS_WIDTH_IN_CHARS-CAPS_FAMILY],                             //~v865I~
caps[CAPS_HEIGHT_IN_CHARS-CAPS_FAMILY],                            //~v865I~
caps[CAPS_DEVICE_FONTS-CAPS_FAMILY],                               //~v865I~
caps[CAPS_GRAPHICS_CHAR_WIDTH-CAPS_FAMILY],                        //~v865I~
caps[CAPS_GRAPHICS_CHAR_HEIGHT-CAPS_FAMILY],                       //~v865I~
caps[CAPS_HORIZONTAL_FONT_RES-CAPS_FAMILY],                        //~v865I~
caps[CAPS_VERTICAL_FONT_RES-CAPS_FAMILY]);                         //~v865I~
	return;                                                        //~v865I~
}//os2_chkdc                                                       //~v865I~
//****************************************************************************//~v865I~
//*doc open                                                        //~v865I~
//*parm1:horizontal width of char by unit of 1/720 per inch        //~v865I~
//*parm2:vertical  height of char by unit of 1/720 per inch        //~v865I~
//*parm3:docname                                                   //~v865I~
//****************************************************************************//~v865I~
void os2_opendoc(void)                                             //~v865I~
{                                                                  //~v865I~
	LONG retcnt;                                                   //~v865I~
    char *jbn;                                                     //~v869I~
//********************************                                 //~v865I~
	if (!(jbn=jobname))                                            //~v869I~
    	jbn=docname;                                               //~v869I~
	if (Sopendocsw)                                                //~v865I~
    	printf("duplicated doc open req\n");                       //~v865I~
	else                                                           //~v865I~
    {                                                              //~v865I~
    	retcnt=0;                                                  //~v865I~
        if (DevEscape(Shdc,                                        //~v865I~
							DEVESC_STARTDOC,                       //~v865I~
//  						(long)strlen(docname),                 //~v869R~
//  						docname,                               //~v869R~
    						(long)strlen(jbn),                     //~v869I~
    						jbn,                                   //~v869I~
							&retcnt,                               //~v865I~
							NULL)!=DEV_OK)                         //~v865I~
		{                                                          //~v865I~
            printf("\nDevEscape(STARTDOC) for %s failed rc=%d\n",  //~v865I~
                      docname,WinGetLastError(Shab));              //~v865I~
			uexit(8);                                              //~v865I~
		}                                                          //~v865I~
        Sopendocsw=1;                                              //~v865I~
//printf("startdoc\n");                                            //~v869R~
	}//nit opened                                                  //~v865I~
}//os2_opendoc                                                     //~v865I~
//**********************************************************************//~v865I~
//* close doc                                                      //~v865I~
//**********************************************************************//~v865I~
void os2_closedoc(void)                                            //~v865I~
{                                                                  //~v865I~
	long retcnt;                                                   //~v865I~
    USHORT jobno;                                                  //~v865I~
//********************************                                 //~v865I~
//printf("EndDoc\n");                                              //~v869R~
  	if (UCBITCHK(swsw3,SW3WIN2P|SW3FORM2P))	//2p                   //+v915I~
		closedoc2p();	//flushout line on 2p work tbl             //+v915I~
	if (Sopendocsw)                                                //~v865I~
    {                                                              //~v865I~
		Sopendocsw=0;                                              //~v865I~
        retcnt=2;                                                  //~v865I~
        if (DevEscape(Shdc,                                        //~v865I~
        					DEVESC_ENDDOC,                         //~v865I~
							0,                                     //~v865I~
							NULL,                                  //~v865I~
							&retcnt,                               //~v865I~
							(UCHAR*)(PVOID)&jobno)!=DEV_OK)        //~v865I~
            printf("\nDevEscape(ENDDOC) failed rc=%d\n",WinGetLastError(Shab));//~v865I~
	}                                                              //~v865I~
	return;                                                        //~v865I~
}//os2_closedoc                                                    //~v865I~
//****************************************************************************//~v865I~
//write line into PS                                               //~v865I~
//parm1:text addr                                                  //~v865I~
//parm2:text len                                                   //~v865I~
//****************************************************************************//~v865I~
unsigned long os2_putline(char *Pbuff,unsigned long Plen)          //~v865I~
{                                                                  //~v865I~
    int  lastcr;                                                   //~v865I~
	char *pci,*pco,*pcl;    	                                   //~v865R~
    LONG outlen,reqlen,ilen;                                       //~v865R~
	unsigned char escbuff[MAXLINEWIDTH*5];	//1+2(ESCP start cmd)+2(ESCP end cmd)//~v865I~
//********************************                                 //~v865I~
//chang '\n'-->'\r\n'                                              //~v865I~
//printf("inputdata=%s\n",Pbuff);                                  //~v865R~
    pci=Pbuff;                                                     //~v865I~
    pco=escbuff;                                                   //~v865I~
    ilen=(long)Plen;                                               //~v865R~
//drop page eject and call NEWFRAME                                //~v865I~
    if (hdr0linesw)		//form feed                                //~v865I~
    {                                                              //~v865I~
//    if (jobname)     //@@@@test                                  //~v869R~
//    {                //@@@@test                                  //~v869R~
        os2_newpage();                                             //~v865I~
    	pci++;                                                     //~v865I~
        ilen--;                                                    //~v865I~
//    }                //@@@@test                                  //~v869R~
	}                                                              //~v865I~
//*change newline to cr+nl                                         //~v865I~
    while(ilen && *pci=='\n')                                      //~v865I~
    {                                                              //~v865I~
        pci++;                                                     //~v865I~
        ilen--;                                                    //~v865I~
		*pco++='\r';                                               //~v865I~
		*pco++='\n';                                               //~v865I~
    }                                                              //~v865I~
    lastcr=0;                                                      //~v865I~
    pcl=pci+ilen-1;                                                //~v865R~
    while(ilen && *pcl=='\n')                                      //~v865R~
    {                                                              //~v865I~
    	ilen--;                                                    //~v865I~
        lastcr++;                                                  //~v865I~
        pcl--;                                                     //~v865R~
    }                                                              //~v865I~
    memcpy(pco,pci,(UINT)ilen);                                    //~v865R~
    for (pco+=ilen;lastcr;lastcr--)                                //~v865R~
    {	                                                           //~v865I~
    	*pco++='\r';                                               //~v865R~
    	*pco++='\n';                                               //~v865R~
	}                                                              //~v865I~
    reqlen=(long)((ULONG)pco-(ULONG)escbuff);                      //~v865I~
    if (DevEscape(Shdc,                                            //~v865I~
					DEVESC_RAWDATA,                                //~v865I~
					reqlen,                                        //~v865R~
					escbuff,                                       //~v865R~
					&outlen,			//outlen                   //~v865I~
                    NULL)!=DEV_OK)                                 //~v865I~
	{                                                              //~v865I~
		printf("\nDevEscape(DEVESC_RAWDATA) failed rc=%d\n",WinGetLastError(Shab));//~v865I~
       	uexit(8);                                                  //~v865I~
    }                                                              //~v865I~
//printf("rawdata,ilen=%d,olen=%d,data=%s\n",Plen,reqlen,escbuff); //~v865R~
	return Plen;                                                   //~v865I~
}//os2_putline                                                     //~v865I~
//****************************************************************************//~v865I~
//start new page                                                   //~v865I~
//****************************************************************************//~v865I~
void os2_newpage(void)                                             //~v865I~
{                                                                  //~v865I~
    LONG outlen=0,reqlen=0;                                        //~v865I~
//********************************                                 //~v865I~
//printf("newpage\n");                                             //~v869R~
    if (DevEscape(Shdc,                                            //~v865I~
					DEVESC_NEWFRAME,                               //~v865I~
					reqlen,                                        //~v865I~
					NULL,                                          //~v865I~
					&outlen,			//outlen                   //~v865I~
                    NULL)!=DEV_OK)                                 //~v865I~
	{                                                              //~v865I~
		printf("\nDevEscape(DEVESC_NEWFRAME) failed rc=%d\n",WinGetLastError(Shab));//~v865I~
       	uexit(8);                                                  //~v865I~
    }                                                              //~v865I~
    return;                                                        //~v865I~
}//os2_newnpage                                                    //~v865I~
//*********************************************                    //~v865I~
//*os2_endjob                                                      //~v865I~
//*parm:normal end sw                                              //~v865I~
//*rc  :none                                                       //~v865I~
//*********************************************                    //~v865I~
void os2_endjob(int Pendjobsw)                                     //~v865I~
{                                                                  //~v865I~
	static int Sendrequested;                                      //~v865I~
//********************************                                 //~v865I~
//printf("endjob sw=%d\n",Pendsw);                                 //~v865I~
	if (Sendrequested)	//loop detection                           //~v865I~
    	return;                                                    //~v865I~
	Sendrequested=1;	//loop detection                           //~v865I~
	if (Sopendocsw)                                                //~v865I~
		os2_closedoc();                                            //~v865R~
    if (Shdc)                                                      //~v865I~
    {	                                                           //~v865I~
    	if (DevCloseDC(Shdc)==DEV_ERROR)                           //~v865I~
			printf("DevCloseDC failed,rc=%d\n",WinGetLastError(Shab));//~v865I~
        Shdc=0;                                                    //~v865I~
	}                                                              //~v865I~
	return;                                                        //~v865I~
}//os2_endjob                                                      //~v865I~
//*********************************************                    //~v865I~
//*udevquerycaps                                                   //~v865I~
//*parm:HDC                                                        //~v865I~
//*rc  :none                                                       //~v865I~
//*********************************************                    //~v865I~
void udevquerycaps(HDC Phdc,LONG Pstart,LONG Pcnt,PLONG Pout)      //~v865I~
{                                                                  //~v865I~
//*************************                                        //~v865I~
	if (!DevQueryCaps(Phdc,Pstart,Pcnt,Pout))                      //~v865I~
    {                                                              //~v865I~
        printf("\nDevQueryCaps failed,rc=%d\n",WinGetLastError(Shab));//~v865I~
        uexit(8);                                                  //~v865I~
    }                                                              //~v865I~
    return;                                                        //~v865I~
}//udevquerycaps                                                   //~v865I~
