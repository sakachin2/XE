//CID://+vbdgR~:        update#=    2                              //~vbdgR~
//*************************************************************
//*xefile.c*
//**load/save/edit/browse/end/cancel
//*************************************************************
//vbdg:171123 by vbdf compiler warning:conversion                  //~vbdgI~
//va34:070511 xft:indexlist invalid print seqence when dupfunc on the same plh//~va34R~
//*************************************************************    //~7511I~
#define TEST
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
    #ifdef DPMI					//DPMI version
    #else                       //not DPMI
    #endif                      //DPMI or not
#else
#endif
//*******************************************************
#include <ulib.h>
#include <ualloc.h>
#include <uerr.h>
#include <uque.h>
#include <uedit.h>
#include <ustring.h>
#include <ufile.h>

#include "xft.h"
//*******************************************************
#define CONT_LINEID "."

#define EXPTYPE_EXPANDED '-'
#define EXPTYPE_EXTERN   '*'
#define EXPTYPE_SINGLE   '+'
#define EXPTYPE_FUNCMACP '#'                                       //~0703R~
#define EXPTYPE_NONE     '|'
//*******************************************************
extern UQUEH  	Gfilehq;		//q of UFILEH
extern int      Gxftdbcssw;                                        //~0709I~
//*******************************************************
static int Stestsw;
static int Soption;
static int Slistfdsw;
static int Sfilectr;                                               //~0722I~
//static int Slevel0No;      //for index print                     //~0720R~
static int Sfuncindex=0;     //for index print                     //~5322R~
static int Sfuncindexcp=0;     //for index print of child-parent   //~5322R~
static int Sinmacprint;		//printing all macro at first          //~0722I~
static int Sinmacprint1stlevel;		//printing all macro at first  //~0722I~
#define MAXLEVEL  50
static PUFUNCDEF Sfuncpath[MAXLEVEL];
static PUFUNCDEF *Ssortppfd=0;		//sorted pfd ptr list          //~5322R~
static int        Ssortppfdcnt=0;		//sorted pfd ptr list      //~5322R~
//**********************************
int listfuncsub(PUFUNCDEF Ppfd,int Plevel);                        //~0722R~
int listfc(int Plevel,PUFUNCCALL Ppfc,PUFUNCDEF Ppfd);
int listmac(int Plevel,PULINEH Pplh,int Pdefid);
int listfd(int Plevel,PUFUNCDEF Ppfd,PULINEH Pundefplhs,PULINEH Pundefplhe);//~0720R~
int listprefix(int Plevel,int Ptype,int Pexptype,PULINEH Pplh);
#define PREFIX_DEF       '='
#define PREFIX_DEFSTART  '{'
#define PREFIX_DEFEND    '}'
#define PREFIX_CONT      '.'
#define PREFIX_CALL      ' '
#define PREFIX_MAC       '#'
int listline(PULINEH Pplh,int Plevel,int Ppos,int Ptype);
int listlinedata(UCHAR *Pdata,int Plen,int Ppos,PULINEH Ppplh);
int listchipar(UCHAR *Pfuncnm);
int fdcompare(const void *ent1,const void *ent2);
int listchiparsubtree(PUFUNCDEF Ppfd,PUFUNCCALL Ppfc,int Plevel,PULINEH Pplh,int Prepeatsw);//~0722R~
int fccompare(const void *ent1,const void *ent2);
int listprefixcp(int Plevel,PULINEH Pplh,int Ptype,PUFUNCDEF Ppfd);//~0722R~
int listlinecp(PULINEH Pplh,int Ppos,int Plen);
int listfilename(void);
int expandcondchk(PUFUNCDEF Ppfd,int Plevel);                      //~0722R~
//int listlevel0(void);                                            //~0720R~
int listindex(void);                                               //~0709I~
int listindexcp(void);                                             //~0715I~
int sortpfd(void);                                                 //~0709I~
int listundef(PULINEH Pplhs,PULINEH Pplhe,int Plevel);             //~0720I~
//**********************************************************************
int listfunc(int Popt,UCHAR *Pfuncnm)
{
	PUFILEH pfh;
	PUFUNCDEF  pfd;
    int pfdno;                                                     //~0708R~
//*********************
//  Sfilectr=UGETQCTR(&Gfilehq);                                   //~0722I~//~vbdgR~
    Sfilectr=(int)UGETQCTR(&Gfilehq);                              //~vbdgI~
	Soption=Popt;
	Stestsw=Popt&OPT_TEST;
	listfilename();		//filename list
	if (Soption&OPT_PARCHI)
    {
    	if (Gxftdbcssw)                                            //~0709I~
        {                                                          //~0709I~
            printf("\n===============   Parent-Child List    ========================================\n");//~0723R~
            printf("      ---> : 関数/マクロ コール (展開形)\n");  //~0723R~
            printf("      +--> : 関数コール         (非展開形)\n");//~0723R~
            printf("      +--# : マクロコール       (非展開形)\n");//~0723R~
            printf("      +--* : 外部関数コール\n");               //~0709I~
            printf("      =    : 関数定義行\n");                   //~0709I~
        }                                                          //~0709I~
        else                                                       //~0709I~
        {                                                          //~0709I~
            printf("\n===============   Parent-Child List    ========================================\n");//~0723R~
            printf("      ---> : function/macro call.   (expanded)\n");//~0723R~
            printf("      +--> : function call.         (reduced)\n");//~0723R~
            printf("      +--# : macro function call    (reduced)\n");//~0723R~
            printf("      +--* : external function call.\n");      //~0709R~
            printf("      =    : function prototype.\n");          //~0723R~
        }                                                          //~0709I~
        for (pfh=UGETQTOP(&Gfilehq);pfh;pfh=UGETQNEXT(pfh))
        {
            printf("\n===== %-50s ======================\n",pfh->UFHfilename);//~0722R~
            Slistfdsw=0;     //chk printed
//print function macro at first                                    //~0702I~
			Sinmacprint=1;		//printing all macro at first      //~0722I~
//          pfdno=UGETQCTR(&pfh->UFHfuncque);                      //~0708I~//~vbdgR~
            pfdno=(int)UGETQCTR(&pfh->UFHfuncque);                 //~vbdgI~
			if (Soption & OPT_PMACRO)                              //~0708I~
                for (pfd=UGETQTOP(&pfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))//~0708R~
                    if (UCBITCHK(pfd->UFDflag,UFDF_DEFINEMAC))        //macro//~0708R~
//                  &&  !UCBITCHK(pfd->UFDflag,UFDF_DEFINEMACP))      //macro func with parm//~0708R~
					{                                              //~0722I~
                        Sinmacprint1stlevel=pfd->UFDlevel;         //~0722I~
                        listfuncsub(pfd,0);                        //~0722R~
                    }                                              //~0722I~
			Sinmacprint=0;		//printing all macro at first,end  //~0722I~
//print from level0                                                //~0702I~
            for (pfd=UGETQTOP(&pfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))
                if (!pfd->UFDlevel)         //level 0 func
                    listfuncsub(pfd,0);                            //~0722R~
            if (!Slistfdsw)      //chk printed
            {                                                      //~va34I~
                if (pfdno)                                         //~0708R~
            		printf("--- All function already printed with call statement ---\n");//~0708R~
                else                                               //~0708I~
            		printf("--- No function defined ---\n");       //~0708I~
            }                                                      //~va34I~
        }
		if (Soption & (OPT_INDEX1|OPT_INDEX2))                     //~0715R~
        	listindex();                                           //~0709I~
//        else                                                     //~0720R~
//            listlevel0();                                        //~0720R~
    }
	if (Soption&OPT_CHIPAR)
		listchipar(Pfuncnm);
    if (Ssortppfd)                                                 //~0720I~
	    ufree(Ssortppfd);                                          //~0720R~
    return 0;
}//listfunc
////**********************************************************************//~0720R~
////* summary level 0 function                                     //~0720R~
////**********************************************************************//~0720R~
//int listlevel0(void)                                             //~0720R~
//{                                                                //~0720R~
//    PUFILEH pfh;                                                 //~0720R~
//    PUFUNCDEF  pfd;                                              //~0720R~
//    int     ch;                                                  //~0720R~
////*********************                                          //~0720R~
//    printf("\n-----   Level-0 Function List   -----\n");         //~0720R~
//    printf(  "   No * FunctionName                     --- FileName\n");//~0720R~
//    for (pfh=UGETQTOP(&Gfilehq);pfh;pfh=UGETQNEXT(pfh))          //~0720R~
//    {                                                            //~0720R~
//        for (pfd=UGETQTOP(&pfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))//~0720R~
//            if (!pfd->UFDlevel && !UCBITCHK(pfd->UFDflag,UFDF_DUPDEF2))//~0720R~
//            {                                                    //~0720R~
//                if (UCBITCHK(pfd->UFDflag,UFDF_DEFINEMAC))       //~0720R~
//                    ch='#';                                      //~0720R~
//                else                                             //~0720R~
//                    ch='*';                                      //~0720R~
//                printf("  %3d %c %-32.*s --- %s\n",              //~0720R~
//                        pfd->UFDindex,ch,pfd->UFDfnl,pfd->UFDfnm,pfh->UFHfilename);//~0720R~
//            }                                                    //~0720R~
//    }                                                            //~0720R~
//    return 0;                                                    //~0720R~
//}//listlevel0(void)                                              //~0720R~
//**********************************************************************//~0709I~
//* summary level 0 function                                       //~0709I~
//**********************************************************************//~0709I~
int listindex(void)                                                //~0709I~
{                                                                  //~0709I~
	PUFUNCDEF  pfd,*ppfd;                                          //~0709I~
    int        ii;                                                 //~0709I~
//*********************                                            //~0709I~
	sortpfd();                                                     //~0720M~
	printf("\n------------------  Parent->Child Function Index List  ------------------------\n");//~0723R~
	printf(  "----- FunctionName                     --- Func No. --- NestLevel -------------\n");//~0722R~
    for (ppfd=Ssortppfd,ii=Ssortppfdcnt;ii>0;--ii,ppfd++)          //~0709I~
    {                                                              //~0709I~
     	pfd=*ppfd;                                                 //~0709I~
        if (Soption & OPT_INDEX2	//all print	                   //~0720R~
        ||  pfd->UFDindex)                                         //~0715I~
        {                                                          //~va34I~
			if (UCBITCHK(pfd->UFDflag,UFDF_DUPDEF2))               //~0720I~
#ifdef AAA                                                         //~va34I~
                printf("      \"%-32s--- %5d    --- (  \")\n",     //~0722R~
                        " ",pfd->UFDindex);                        //~0720R~
#else                                                              //~va34I~
                printf("      \"%-32s--- %5d    --- (%3d)\n",      //~va34R~
                        " ",pfd->UFDindex,pfd->UFDlevel);          //~va34I~
#endif                                                             //~va34I~
            else                                                   //~0720I~
                if (pfd->UFDindex)                                 //~0720R~
                    printf("      %-32.*s --- %5d    --- (%3d)\n", //~0722R~
                            pfd->UFDfnl,pfd->UFDfnm,pfd->UFDindex,pfd->UFDlevel);//~0720R~
                else                                               //~0720R~
                    printf("     *%-32.*s ---     -    --- (%3d)\n",//~0722R~
                            pfd->UFDfnl,pfd->UFDfnm,pfd->UFDlevel);//~0720R~
        }                                                          //~va34I~
    }                                                              //~0709I~
    return 0;                                                      //~0709I~
}//listindex                                                       //~0709I~
//**********************************************************************//~0709I~
//* get sorted pfd list                                            //~0709I~
//**********************************************************************//~0709I~
int sortpfd(void)                                                  //~0709I~
{                                                                  //~0709I~
	PUFUNCDEF *ppfd,pfd;                                           //~0709R~
    PUFILEH    pfh;                                                //~0709I~
    int        fdcnt;                                              //~0709I~
static int Ssortedsw=0;                                            //~5322R~
//**********************                                           //~0709I~
    if (Ssortedsw)                                                 //~0720I~
        return 0;                                                  //~0720I~
    Ssortedsw=1;                                                   //~0720I~
//count func number                                                //~0709M~
    for (pfh=UGETQTOP(&Gfilehq),fdcnt=0;pfh;pfh=UGETQNEXT(pfh))    //~0709M~
//      fdcnt+=UGETQCTR(&pfh->UFHfuncque);                         //~0709M~//~vbdgR~
        fdcnt+=(int)UGETQCTR(&pfh->UFHfuncque);                    //~vbdgI~
//sort func def list                                               //~0709M~
	Ssortppfdcnt=fdcnt;                                            //~0709I~
	Ssortppfd=UALLOCM((UINT)(fdcnt<<2));	//pfd ptr list for sort//~0709I~
    if (!Ssortppfd)                                                //~0709R~
    	errmalloc("FuncDef Ptr List for sort");                    //~0709M~
    for (ppfd=Ssortppfd,pfh=UGETQTOP(&Gfilehq);pfh;pfh=UGETQNEXT(pfh))//~0709I~
        for (pfd=UGETQTOP(&pfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))//~0709M~
            *ppfd++=pfd;                                           //~0709M~
  	qsort(Ssortppfd,(UINT)fdcnt,4,fdcompare);                      //~0709I~
    return fdcnt;                                                  //~0709I~
}//sortpfd                                                         //~0709I~
//**********************************************************************
//* set reverse relation for call in a function
//**********************************************************************
int listfuncsub(PUFUNCDEF Ppfd,int Plevel)                         //~0722R~
{
	PUFUNCDEF  pfd,pfdc;                                           //~0708R~
	PUFUNCCALL pfc;                                                //~0708R~
    PULINEH    undefplhs,undefplhe,*pplh;                          //~0720R~
    int        ii;                                                 //~0720I~
//*********************
    if (Stestsw)
		printf("suncsub:UFDlevel=%d,curlevel=%5d curfunc=%.*s\n",Ppfd->UFDlevel,Plevel,
				(int)Ppfd->UFDfnl,Ppfd->UFDfnm);
	if (!expandcondchk(Ppfd,Plevel))                               //~0722R~
    	return 0;		//skip expand                              //~0720I~
    Slistfdsw=1;
	for (pfd=Ppfd,undefplhs=0,undefplhe=0;pfd;pfd=pfd->UFDdupnamepfd)//~0720R~
    {                                                              //~0708I~
        listfd(Plevel,pfd,undefplhs,undefplhe);                    //~0720R~
        undefplhs=pfd->UFDundefplhs;                               //~0720R~
        undefplhe=pfd->UFDundefplhe;                               //~0720R~
        pfc=UGETQTOP(&pfd->UFDqhc);                                //~0723I~
        if (pfc || !UCBITCHK(pfd->UFDflag,UFDF_DEFINEMACP))        //~0723I~
        {	//skip when macro calls no function                    //~0723I~
            listprefix(Plevel,PREFIX_DEFSTART,' ',0);  //prefix of def//~0723I~
            for (;pfc;pfc=UGETQNEXT(pfc))                          //~0723R~
            {                                                      //~0723R~
                if (Stestsw)                                       //~0723R~
                    printf("%5d %.*s\n",Plevel+1,(int)pfc->UFCfnl,pfc->UFCfnm);//~0723R~
                pfdc=pfc->UFCpfdc;                                 //~0723R~
                listfc(Plevel+1,pfc,pfdc);                         //~0723R~
            }                                                      //~0723R~
            listprefix(Plevel,PREFIX_DEFEND,' ',0);  //prefix of def//~0723R~
        }                                                          //~0723I~
//print funcdef macro encloser                                     //~0720I~
    	for (ii=pfd->UFDmacplhcnte,pplh=&pfd->UFDmacplhliste[0];ii>0;ii--,pplh++)//~0720R~
			listmac(Plevel,*pplh,1);	//1:funcdef                //~0720I~
    }                                                              //~0708I~
	return 0;
}//listfuncsub
//**********************************************************************//~0720I~
//* expand condition chk                                           //~0720I~
//* ret: 1 to be expand,0:don't expand                             //~0720I~
//**********************************************************************//~0720I~
int expandcondchk(PUFUNCDEF Ppfd,int Plevel)                       //~0722R~
{                                                                  //~0720I~
//**********************                                           //~0720I~
    if (UCBITCHK(Ppfd->UFDflag,UFDF_PRINTED|UFDF_DUPDEF2|UFDF_EXTERN))//~0720M~
        return 0;                                                  //~0720M~
	if (Sinmacprint) 		//printing all macro at first          //~0722R~
    {                                                              //~0720I~
    	if (!Plevel)		//macro define func stmt               //~0722R~
        	return 1;		//expand                               //~0722I~
    	if (UCBITCHK(Ppfd->UFDflag,UFDF_DEFINEMAC))         //func macro//~0722I~
            return 0;                                              //~0722R~
        Plevel+=Sinmacprint1stlevel;	//start=0 and actual nest  //~0722I~
    }                                                              //~0722I~
    if (Soption & OPT_PHIGH)    //print at highest level           //~0722R~
        if (Ppfd->UFDlevel!=Plevel) //print at highest level       //~0722R~
            return 0;                                              //~0722R~
    return 1; //expand                                             //~0720I~
}//expandcondchk                                                   //~0720I~
//**********************************************************************
//* print func definition line
//**********************************************************************
int listfd(int Plevel,PUFUNCDEF Ppfd,PULINEH Pundefplhs,PULINEH Pundefplhe)//~0720R~
{
	int  len,ii,undefprintsw;                                      //~0720R~
    PULINEH plh,*pplh;                                             //~0720R~
//*********************
    UCBITON(Ppfd->UFDflag,UFDF_PRINTED);                           //~0708R~
    if (!Plevel)                                                   //~0722R~
    {                                                              //~0722R~
        if (Sfilectr==1)   //one file                              //~0722R~
            len=7;                                                 //~0722I~
        else                                                       //~0722I~
            len=11;                                                //~0722I~
        printf("\n%.*s:%.*s\n",len,"===========",Ppfd->UFDfnl,Ppfd->UFDfnm);//~0722R~
    }                                                              //~0722R~
    Ppfd->UFDindex=++Sfuncindex;                                   //~0720R~
    if (Soption & (OPT_INDEX1|OPT_INDEX2))                         //~0720R~
        printf("                                       >>>>>>>>>> P-C Func No. %5d >>>>>>>>>>\n",Sfuncindex);//~0722R~
//print nest level                                                 //~0720I~
	undefprintsw=0;                                                //~0720I~
    for (ii=Ppfd->UFDmacplhcnts,pplh=&Ppfd->UFDmacplhlists[ii-1];ii>0;ii--,pplh--)//~0720R~
    {                                                              //~0720I~
		plh=*pplh;                                                 //~0720I~
    	if (Pundefplhs && !undefprintsw)                           //~0720R~
        	if (UGETPFH(plh)==UGETPFH(Pundefplhs))  //same file    //~0720R~
                if (Pundefplhs->ULHlinenor<plh->ULHlinenor)        //~0720R~
                {                                                  //~0720I~
                	listundef(Pundefplhs,Pundefplhe,Plevel);       //~0720I~
                    undefprintsw=1;                                //~0720I~
                }                                                  //~0720I~
		listmac(Plevel,plh,1);	//1:funcdef                        //~0720R~
    }                                                              //~0720I~
    if (Pundefplhs && !undefprintsw)                               //~0720R~
    	listundef(Pundefplhs,Pundefplhe,Plevel);                   //~0720I~
                                                                   //~0720I~
    for (plh=Ppfd->UFDplhs;plh;plh=UGETQNEXT(plh))                 //~0720R~
    {
        if (plh->ULHtype==ULHTMACRO)
		    listmac(Plevel,plh,1);	//1:funcdef                    //~0720R~
        else
            if (plh==Ppfd->UFDplhs)                                //~0708R~
            {
			    if (!(Soption & OPT_STMT))   //def name only
                {
                	if (!Plevel)
                    {
		                listprefix(Plevel,PREFIX_DEF,' ',plh);  //prefix of def
                    	listlinedata(Ppfd->UFDfnm,(int)Ppfd->UFDfnl,0,plh);//~0708R~
                    }
                }
                else
                {
	                listprefix(Plevel,PREFIX_DEF,' ',plh);  //prefix of def
                    if (plh==Ppfd->UFDplhe) //single line          //~0708R~
                        len=(int)((ULONG)Ppfd->UFDdefend-(ULONG)plh->ULHdata);//~0708R~
                    else
                        len=plh->ULHlen;
                    if (!listlinedata(plh->ULHdata,len,0,plh))
                    	printf("\n");
                }
            }
            else
			    if ((Soption & OPT_STMT))   //def stmt print
                {
                    if (plh==Ppfd->UFDplhe) //single line          //~0708R~
                        len=(int)((ULONG)Ppfd->UFDdefend-(ULONG)plh->ULHdata);//~0708R~
                    else
                        len=plh->ULHlen;
                    if (len && len!=(int)ustrnspn(plh->ULHdata,TABSPACE,(UINT)len))
                    {
	                	listprefix(Plevel,PREFIX_CONT,'|',plh);  //prefix of def//~0720R~
                    	if (!listlinedata(plh->ULHdata,len,0,plh))
                    		printf("\n");
                    }
                }
		if (plh==Ppfd->UFDplhe)                                    //~0720R~
        	break;                                                 //~0708R~
	}
    return 0;
}//listfd
//**********************************************************************//~0720I~
//* list undef line                                                //~0720I~
//**********************************************************************//~0720I~
int listundef(PULINEH Pplhs,PULINEH Pplhe,int Plevel)              //~0720I~
{                                                                  //~0720I~
    PULINEH plh;                                                   //~0720I~
//****************                                                 //~0720I~
    for (plh=Pplhs;plh;plh=UGETQNEXT(plh))                         //~0720I~
    {                                                              //~0720I~
        listmac(Plevel,plh,1);                                     //~0720I~
        if (plh==Pplhe)                                            //~0720I~
            break;                                                 //~0720I~
    }                                                              //~0720I~
    return 0;                                                      //~0720I~
}//listundef                                                       //~0720I~
//**********************************************************************
//* print func call line
//* p1:func call level
//* p2:pfc
//* p3:pfd of called
//**********************************************************************
int listfc(int Plevel,PUFUNCCALL Ppfc,PUFUNCDEF Ppfdc)             //~0722R~
{
	int pos,len,expandsw,posw,conttype;                            //~0720R~
    PULINEH plh;                                                   //~0720R~
    UCHAR  *top;
//*********************
	if (Ppfdc && !UCBITCHK(Ppfdc->UFDflag,UFDF_EXTERN))            //~0722R~
    {
		if (!expandcondchk(Ppfdc,Plevel))	//0:child expand       //~0722R~
        {                                                          //~0703I~
			if (Ppfdc->UFDflag & UFDF_DEFINEMAC) //macro func with parm//~0722R~
        		expandsw=EXPTYPE_FUNCMACP;                         //~0703I~
            else                                                   //~0703I~
        		expandsw=EXPTYPE_SINGLE;                           //~0703R~
        }                                                          //~0703I~
        else
    		expandsw=EXPTYPE_EXPANDED;
        if (Stestsw)
            printf("listfc:level=%d,expandsw=%c,called=%.*s\n",Plevel,expandsw,
            		Ppfdc->UFDfnl,Ppfdc->UFDfnm);                  //~0722R~
    }
    else
        expandsw=EXPTYPE_EXTERN;

//print macro BEFORE                                               //~0720R~
    for (plh=Ppfc->UFCmacplhs;plh;plh=UGETQNEXT(plh))              //~0720R~
    {                                                              //~0720I~
        if (plh==Ppfc->UFCplhs)                                    //~0720I~
        	break;                                                 //~0720I~
		listmac(Plevel,plh,0);	//0:funccall                       //~0720R~
    }                                                              //~0720I~
                                                                   //~0720I~
    for (plh=Ppfc->UFCplhs;plh;plh=UGETQNEXT(plh))                 //~0720R~
    {
        if (plh->ULHtype==ULHTMACRO)
            listmac(Plevel,plh,0);
        else
            if (plh==Ppfc->UFCplhs)
            {
                pos=listprefix(Plevel,PREFIX_CALL,expandsw,plh);
                top=Ppfc->UFCtop;
                if (plh==Ppfc->UFCplhe)	//single line
//              	len=Ppfc->UFCend-top;                          //+vbdgR~
                	len=PTRDIFF(Ppfc->UFCend,top);                 //+vbdgI~
                else
//              	len=(int)(plh->ULHlen-((ULONG)top-(ULONG)plh->ULHdata));//~vbdgR~
                	len=(int)(plh->ULHlen-PTRDIFF(top,plh->ULHdata));//+vbdgR~
                listlinedata(top,len,0,plh);
                pos+=Ppfc->UFCfnl+1;
            }
            else
            {
                if (UGETQNEXT(Ppfc))	//has next call stmt       //~0720I~
                	conttype='|';	//continue to call line        //~0720I~
                else                                               //~0720I~
                	conttype=' ';                                  //~0720I~
	            posw=pos-listprefix(Plevel,PREFIX_CONT,conttype,plh);  //prefix of def//~0720R~
                if (plh==Ppfc->UFCplhe) //single line
                    len=(int)((ULONG)Ppfc->UFCend-(ULONG)plh->ULHdata);
                else
                    len=plh->ULHlen;
                listlinedata(plh->ULHdata,len,posw,plh);
            }
        if (plh==Ppfc->UFCplhe)                                    //~0720R~
            break;
    }
    if (Ppfdc)                                                     //~0722I~
        listfuncsub(Ppfdc,Plevel);//expand called                  //~0722I~
//print macro AFTER                                                //~0722R~
    if (Ppfc->UFCmacplhe!=plh)                                     //~0720I~
        for (;plh=UGETQNEXT(plh),plh;)                             //~0720I~
        {                                                          //~0720I~
            listmac(Plevel,plh,0);  //0:funccall                   //~0720I~
            if (plh==Ppfc->UFCmacplhe)                             //~0720I~
                break;                                             //~0720I~
        }                                                          //~0720I~
    return 0;
}//listfc
//**********************************************************************
//* print hierarchy prefix
//* p2:prefix type
//* p3:expand type
//* return print offset
//**********************************************************************
int listprefix(int Plevel,int Ptype,int Pexptype,PULINEH Pplh)
{
    int ii,jj,pos,type,ch,nofilenosw;                              //~0729R~
    PUFILEH pfh;
//*********************
    if (Sfilectr==1)   //one file                                  //~0722I~
    	nofilenosw=1;
    else
    	nofilenosw=0;
    type=Ptype;                                                    //~0723R~
    if (type==PREFIX_CONT || type==PREFIX_MAC)                     //~0723I~
    	type=' ';
    if (Pplh)
        if (nofilenosw)
    		pos=printf("%c%6ld:",type,Pplh->ULHlinenor);
        else
        {
			pfh=UGETPFH(Pplh);
    		pos=printf("%c%3d-%6ld:",type,pfh->UFHfileno,Pplh->ULHlinenor);
        }
    else
        if (nofilenosw)
    		pos=printf("%c      :",type);
        else
    		pos=printf("%c          :",type);
    for (ii=Plevel-1,ch=' ',jj=1;ii>=0;ii--,jj++,pos+=4)           //~0729R~
    {
        printf("%c   ",ch);
        if (!(jj%4))                                               //~0729R~
        	ch='I';                                                //~0729I~
        else                                                       //~0729I~
        	ch='|';                                                //~0729R~
    }
    switch(Ptype)
    {
    case PREFIX_DEF:         //define
    	if (Plevel)
        {
    		printf("%c   =",ch);                                   //~0729R~
        	pos+=5;
        }
        break;
    case PREFIX_DEFSTART:       //define
    	if (Plevel)
        {
    		printf("%c   {\n",ch);                                 //~0729R~
        	pos+=4;
        }
        else
        {
    		printf("{\n");
        	pos+=1;
        }
        break;
    case PREFIX_DEFEND:         //define
    	if (Plevel)
        {
    		printf("%c   }\n",ch);                                 //~0729R~
        	pos+=4;
        }
        else
        {
    		printf("}\n");
        	pos+=1;
        }
        break;
    case PREFIX_CONT:     //cont line
    	if (Pexptype=='|')                                         //~0729I~
        	Pexptype=ch;                                           //~0729R~
    	if (Plevel)
        {
    		printf("%c      ",Pexptype);                           //~0720R~
        	pos+=8;
        }
        else
        {
    		printf("    ");
        	pos+=4;
        }
        break;
    case PREFIX_CALL:         //call
        if (Pexptype==EXPTYPE_FUNCMACP)                            //~0703R~
    		printf("+--#");                                        //~0703I~
        else                                                       //~0703I~
        if (Pexptype==EXPTYPE_EXTERN)//  '*'                       //~0703I~
    		printf("+--*");                                        //~0703I~
        else                                                       //~0703I~
    		printf("%c-->",Pexptype);                              //~0703R~
        pos+=4;
        break;
    case PREFIX_MAC:         //macro
        if (!UCBITCHK(Pplh->ULHflag,ULHFMACHASP))	//top line     //~0729R~
            switch(Pplh->ULHmactype)                               //~0729R~
            {                                                      //~0729R~
            case ULHMTIF:                                          //~0729R~
            case ULHMTELIF:                                        //~0729R~
            case ULHMTELSE:                                        //~0729R~
                printf("(%d)",Pplh->ULHmacnest);                   //~0729R~
                break;                                             //~0729R~
            case ULHMTENDIF:                                       //~0729R~
                printf("(%d)",Pplh->ULHmacnest+1);                 //~0729R~
                break;                                             //~0729R~
            }                                                      //~0729R~
        break;
    default:
    	printf("    ");
        pos+=4;
        break;
    }
    return pos;
}//listprefix
//**********************************************************************
//* print func mcro line
//**********************************************************************
int listmac(int Plevel,PULINEH Pplh,int Pdefid)
{
//*********************
    if (Pplh->ULHmactype==ULHMTDEFINE)
    	return 0;
	if (Pdefid)         //listfd
    {
		if (Plevel)
    		Plevel++;
    }
    else		//listfc
    	if (UCBITCHK(Pplh->ULHflag,ULHFMACHASP))	//has prev cont
    		Plevel++;
    listline(Pplh,Plevel,0,PREFIX_MAC);
    return 0;
}//listmac
//**********************************************************************
//* print line data
//* p3:pos of cont line
//* p4:type of cont/macro line
//**********************************************************************
int listline(PULINEH Pplh,int Plevel,int Ppos,int Ptype)
{
	int  pos,len,offs;                                             //~0729R~
	UCHAR *pdata;
//*********************
    len=Pplh->ULHlen;
    pdata=Pplh->ULHdata;
    if (UCBITCHK(Pplh->ULHflag,ULHFLITERAL))
    	offs=0;
    else
    	offs=(int)ustrnspn(pdata,TABSPACE,(UINT)len);
    len-=offs;
    if (!len)
    	return 0;
    pos=Ppos-listprefix(Plevel,Ptype,EXPTYPE_NONE,Pplh);
    if (pos>0)
		printf("%-*s",pos,"");
	printf("%.*s\n",len,pdata+offs);
                                                                   //~0729I~
    return 1;
}//listline
//**********************************************************************
//* drop preceding tab/space and print
//* ret : printlen
//**********************************************************************
int listlinedata(UCHAR *Pdata,int Plen,int Ppos,PULINEH Pplh)
{
	int   offs,len=0;
//*********************
    if (UCBITCHK(Pplh->ULHflag,ULHFLITERAL))
    	offs=0;
    else
    	offs=(int)ustrnspn(Pdata,TABSPACE,(UINT)Plen);
    Plen-=offs;
    if (!Plen)
    	return 0;
    if (Ppos>0)
		len+=printf("%-*s",Ppos,"");
	len+=printf("%.*s\n",Plen,Pdata+offs);
    return len;
}//listlinedata
//**********************************************************************
//* print child-parent relation
//**********************************************************************
int listchipar(UCHAR *Pfuncnm)
{
	PUFUNCDEF  pfd;
	PUFUNCDEF *ppfd;                                               //~0709R~
    int        ii,len,printsw=0,subtreesw;                         //~0722R~
//*********************
	sortpfd();                                                     //~0720I~
	printf("\n===============   Child-Parent List    ========================================\n");//~0723R~
//list child-parent
    for (ppfd=Ssortppfd,ii=Ssortppfdcnt;ii>0;--ii,ppfd++)          //~0709R~
    {
     	pfd=*ppfd;
        subtreesw=0;		//call id                              //~0722I~
        if (Pfuncnm)
        {
			len=(int)strlen(Pfuncnm);
			if (len==(int)pfd->UFDfnl
            &&  !memcmp(Pfuncnm,pfd->UFDfnm,(UINT)len))
            {
            	printsw=1;
                subtreesw=1;	                                   //~0722I~
            }
        }
        else
            if (!UCBITCHK(pfd->UFDflag,UFDF_DUPDEF2))	//not dup entry//~0709I~
            if ((Soption & OPT_PEXTERN)			//print extern also//~0709I~
            ||  !UCBITCHK(pfd->UFDflag,UFDF_EXTERN))	//not external func//~0709I~
            if (Soption & OPT_CPALL                                //~0715I~
            ||  !UCBITCHK(pfd->UFDflag,UFDF_CPEXPANDED))           //~0715I~
            	subtreesw=1;                                       //~0722I~
        if (subtreesw)                                             //~0722I~
        {                                                          //~0722I~
            if (Sfilectr==1)   //one file                          //~0722I~
                len=7;                                             //~0722I~
            else                                                   //~0722I~
                len=11;                                            //~0722I~
            printf("\n%.*s:\n",len,"===========");                 //~0722I~
            listchiparsubtree(pfd,0,0,pfd->UFDplhs,0);             //~0722I~
        }                                                          //~0722I~
        if (printsw)                                               //~0722I~
            break;                                                 //~0722I~
    }
    if (Pfuncnm && !printsw)
    	uerrexit("Function %s is not found",0,                     //~0722R~
        		Pfuncnm);
    else                                                           //~0715I~
		if (Soption & (OPT_INDEX1|OPT_INDEX2))                     //~0715I~
        	listindexcp();                                         //~0715I~
    return 0;
}//listchipar
//**********************************************************************//~0715I~
//* summary level 0 function                                       //~0715I~
//**********************************************************************//~0715I~
int listindexcp(void)                                              //~0715I~
{                                                                  //~0715I~
	PUFUNCDEF  pfd,*ppfd;                                          //~0715I~
    int        ii,externsw;                                        //~0720R~
//*********************                                            //~0715I~
	printf("\n--------------  Child->Parent Function Index List  ----------------------------\n");//~0723R~
	printf(  "----- FunctionName                     --- Func No. ---------------------------\n");//~0722R~
    for (ppfd=Ssortppfd,ii=Ssortppfdcnt;ii>0;--ii,ppfd++)          //~0715I~
    {                                                              //~0715I~
     	pfd=*ppfd;                                                 //~0715I~
        if (UCBITCHK(pfd->UFDflag,UFDF_DUPDEF2))	//not dup entry//~0720I~
            continue;                                              //~0720I~
        if (UCBITCHK(pfd->UFDflag,UFDF_EXTERN))	//not external func//~0720I~
        {                                                          //~0720I~
            if (!(Soption & OPT_PEXTERN))			//print extern also//~0720I~
            	continue;                                          //~0720I~
            externsw='*';                                          //~0720I~
        }                                                          //~0720I~
        else                                                       //~0720I~
            externsw=' ';                                          //~0720I~
        if (Soption & OPT_INDEX2	//all function                 //~0715I~
        ||  pfd->UFDindexcp)          //expanded                   //~0715R~
        {                                                          //~va34I~
        	if (pfd->UFDindexcp)          //expanded               //~0715R~
        		printf("     %c%-32.*s --- %5d\n",                 //~0722R~
						externsw,pfd->UFDfnl,pfd->UFDfnm,pfd->UFDindexcp);//~0720R~
            else                                                   //~0715I~
		        printf("     %c%-32.*s ---     -\n",               //~0722R~
						externsw,pfd->UFDfnl,pfd->UFDfnm);         //~0720R~
        }                                                          //~va34I~
    }                                                              //~0715I~
    return 0;                                                      //~0715I~
}//listindex                                                       //~0715I~
//**********************************************************************
//* file name compare for sort
//*  return code: -1: ent1<ent2
//*                0: ent1=ent2
//*                1: ent1>ent2
//**********************************************************************
int fdcompare(const void *ent1,const void *ent2)
{
	int  len1,len2,len;
    PUFUNCDEF pfd1,pfd2;
    PULINEH   plh1,plh2;                                           //~0709I~
    int rc;
//*************
	pfd1=*(PUFUNCDEF*)(ULONG)ent1;                                 //~5322R~
	pfd2=*(PUFUNCDEF*)(ULONG)ent2;                                 //~5322R~
    len1=(int)pfd1->UFDfnl;
    len2=(int)pfd2->UFDfnl;
    len=min(len1,len2);
    if (rc=memcmp(pfd1->UFDfnm,pfd2->UFDfnm,(UINT)len),rc)
        return rc;
    if (len=len1-len2,len)                                         //~0709R~
    	return len;                                                //~0709I~
    plh1=pfd1->UFDplhs;                                            //~0709I~
    plh2=pfd2->UFDplhs;                                            //~0709I~
    rc=UGETPFH(plh1)->UFHfileno-UGETPFH(plh2)->UFHfileno;          //~0720I~
    if (rc)                                                        //~0720I~
    	return rc;                                                 //~0720I~
    if (plh1==plh2)                                                //~va34R~
    	return (int)(pfd1->UFDdupcnt-pfd2->UFDdupcnt);             //~va34R~
    return (int)(plh1->ULHlinenor-plh2->ULHlinenor);               //~0709I~
}//fdcompare
//**********************************************************************
//* print 1 level child-parent relation
//* p1:parent pfd                                                  //~0709I~
//* p2:pfc(caller is parent)                                       //~0709R~
//* p5:1:skip expansion because same child parent relation excep parm//~0709I~
//**********************************************************************
int listchiparsubtree(PUFUNCDEF Ppfd,PUFUNCCALL Ppfc,int Plevel,PULINEH Pplh,int Prepeatsw)//~0722R~
{
	UQUEE      *pqe;
	PUFUNCCALL  pfc,*ppfc,*ppfc0;
	PUFUNCDEF   pfd,pfdtop,pfdo;                                   //~0722R~
	PULINEH     plh;
    int   fccnt,ii,len,pos,type,expandsw=0,repeatsw;               //~0722R~
    UCHAR *top;
//*********************
//list call stmt
	pfdtop=Ppfd->UFDdupnametoppfd;	//top of same name parent func //~0720I~
    if (!pfdtop)                                                   //~0720I~
    	pfdtop=Ppfd;                                               //~0720I~
    if (pfdtop->UFDlevel)         //level 0 func                   //~0720R~
        if (!(Soption & OPT_CPALL) && UCBITCHK(pfdtop->UFDflag,UFDF_CPEXPANDED))//~0722R~
        {                                                          //~0715R~
            if (UCBITCHK(Ppfd->UFDflag,UFDF_DEFINEMAC))            //~0715R~
                type='#';                                          //~0715R~
            else                                                   //~0715R~
                type='+';                                          //~0715R~
        }                                                          //~0715R~
        else                                                       //~0715R~
        {                                                          //~0715R~
            UCBITON(Ppfd->UFDflag,UFDF_CPEXPANDED);                //~0715R~
            type='-';                                              //~0715R~
            expandsw=1;                                            //~0722I~
        }                                                          //~0715R~
    else                                                           //~0715I~
        type='*';	//level0                                       //~0715R~
	pos=listprefixcp(Plevel,Pplh,type,Ppfd);                       //~0722R~
    pos+=printf("%.*s",Ppfd->UFDfnl,Ppfd->UFDfnm);                 //~0722I~
    if (!UCBITCHK(Ppfd->UFDflag,UFDF_DEFINEMAC)                    //~0722I~
    ||  UCBITCHK(Ppfd->UFDflag,UFDF_DEFINEMACP))                   //~0722I~
    	pos+=printf("()");                                         //~0722R~
    if (Ppfc
	&&  Soption & OPT_STMT)   //def name only
    {
        for (plh=Ppfc->UFCplhs;plh;plh=UGETQNEXT(plh))
        {
//printf("plh=%08x,plhs=%08x,plhe=%08x\n",plh,Ppfc->UFCplhs,Ppfc->UFCplhe);
            if (plh->ULHtype!=ULHTMACRO)
            {                                                      //~va34I~
                if (plh==Ppfc->UFCplhs)
                {
                    top=Ppfc->UFCtop;
                    if (plh==Ppfc->UFCplhe) //single line
//                      len=Ppfc->UFCend-top;                      //~vbdgR~
                        len=PTRDIFF(Ppfc->UFCend,top);             //~vbdgI~
                    else
//                      len=(int)(plh->ULHlen-((ULONG)top-(ULONG)plh->ULHdata));//~vbdgR~
                        len=(int)(plh->ULHlen-PTRDIFF(top,plh->ULHdata));//+vbdgR~
                    printf(" : %.*s",len,top);
                    pos+=3+Ppfc->UFCfnl;                           //~0722R~
                }
                else
                {
                    if (plh==Ppfc->UFCplhe)
                        len=(int)((ULONG)Ppfc->UFCend-(ULONG)plh->ULHdata);
                    else
                        len=plh->ULHlen;
                    listlinecp(plh,pos,len);                       //~0722R~
                }
            }                                                      //~va34I~
            if (plh==Ppfc->UFCplhe)
                break;
        }
    }
//recursivechk
    for (ii=Plevel-1;ii>=0;ii--)
        if (Sfuncpath[ii]==Ppfd)
        {
            printf(" (***** Recursive *****)\n");
            return 0;
        }
    if (Plevel>=MAXLEVEL)
    {
        printf(" :::: Too long path\n");
        return 0;
    }
    Sfuncpath[Plevel]=Ppfd;

	printf("\n");
    if (expandsw)                                                  //~0715M~
		if (Soption & (OPT_INDEX1|OPT_INDEX2))                     //~0720R~
        {                                                          //~0722I~
    		Ppfd->UFDindexcp=++Sfuncindexcp;                       //~0722M~
    		printf("                                       <<<<<<<<<< C-P Func No. %5d <<<<<<<<<<\n",Sfuncindexcp);//~0722R~
        }                                                          //~0722I~
                                                                   //~0709I~
//  fccnt=UGETQCTR(&Ppfd->UFDqhp);                                 //~vbdgR~
    fccnt=(int)UGETQCTR(&Ppfd->UFDqhp);                            //~vbdgI~
    if (!fccnt)
    	return 0;
	if (!expandsw)                                                 //~0715R~
    	return fccnt;                                              //~0709I~
	ppfc0=UALLOCM((UINT)(fccnt<<2));	//pfd ptr list for sort
    if (!ppfc0)
    	errmalloc("FuncCall Ptr List for sort");
//list parent by name seq
    for (ppfc=ppfc0,pqe=UGETQTOP(&Ppfd->UFDqhp);pqe;pqe=UGETQNEXT(pqe))
    	*ppfc++=(PUFUNCCALL)((ULONG)pqe-(ULONG)&((PUFUNCCALL)0)->UFCqerev);
  	qsort(ppfc0,(UINT)fccnt,4,fccompare); //v1.4r

    Plevel++;
//printf("fccnt=%d\n",fccnt);                                      //~0720R~
	pfdo=0;                                                        //~0722R~
    for (ppfc=ppfc0,ii=fccnt;ii>0;ii--,ppfc++)
    {
    	pfc=*ppfc;
		pfd=pfc->UFCpfdp;                                          //~0709I~
//printf("pfc%.*s\n",(int)pfc->UFCfnl,pfc->UFCfnm);                //~0720R~
		repeatsw=(pfd==pfdo);                                      //~0722R~
		listchiparsubtree(pfd,pfc,Plevel,pfc->UFCplhs,repeatsw);   //~0722R~
        pfdo=pfd;                                                  //~0722I~
    }
    ufree(ppfc0);
	return fccnt;
}//listchiparsubtree
//**********************************************************************
//* file name compare for sort
//*  return code: -1: ent1<ent2
//*                0: ent1=ent2
//*                1: ent1>ent2
//**********************************************************************
int fccompare(const void *ent1,const void *ent2)
{
    PUFUNCCALL pfc1,pfc2;
    PUFUNCDEF  pfd1,pfd2;
//*************
	pfc1=*(PUFUNCCALL*)(ULONG)ent1;                                //~5322R~
	pfc2=*(PUFUNCCALL*)(ULONG)ent2;                                //~5322R~
    pfd1=pfc1->UFCpfdp;
    pfd2=pfc2->UFCpfdp;
    return fdcompare(&pfd1,&pfd2);
}//fccompare
//**********************************************************************
//* print hierarchy prefix
//* return print offset
//**********************************************************************
int listprefixcp(int Plevel,PULINEH Pplh,int Ptype,PUFUNCDEF Ppfd) //~0722R~
{
    int ii,jj,pos,ch;                                              //~0729R~
    PUFILEH pfh;
//*********************
	pfh=UGETPFH(Pplh);
//top column,line id                                               //~0722I~
    ch=SPACE;                                                      //~0722I~
	if (UCBITCHK(Ppfd->UFDflag,UFDF_EXTERN))                       //~0722R~
    	ch='*';                                                    //~0709I~
    else                                                           //~0709I~
	if (UCBITCHK(Ppfd->UFDflag,UFDF_DEFINEMAC))                    //~0722R~
    {                                                              //~0722I~
    	if (!Plevel)                                               //~0722I~
	    	ch='#';                                                //~0722I~
    }                                                              //~0722I~
	if (UGETQCTR(&Gfilehq)==1)
    	pos=printf("%c%6ld:",ch,Pplh->ULHlinenor);                 //~0709R~
    else
    	pos=printf("%c%3d-%6ld:",ch,pfh->UFHfileno,Pplh->ULHlinenor);//~0709R~
    for (ii=Plevel-1,jj=1,ch=' ';ii>=0;ii--,jj++,pos+=4)           //~0729R~
    {
        printf("%c   ",ch);                                        //~0709R~
        if (!(jj%4))                                               //~0729R~
        	ch='I';                                                //~0729I~
        else                                                       //~0729I~
        	ch='|';                                                //~0729R~
    }
    if (Plevel)
    {
    	printf("<--%c",Ptype);                                     //~0709R~
    	pos+=4;
    }
    return pos;
}//listprefixcp
//**********************************************************************
//* print line data
//**********************************************************************
int listlinecp(PULINEH Pplh,int Ppos,int Plen)
{
	int  pos,len;
	UCHAR *pdata;
//*********************
    len=Pplh->ULHlen;
    pdata=Pplh->ULHdata;
    pos=(int)ustrnspn(pdata,TABSPACE,(UINT)len);
    len-=pos;
    if (!len)
    	return 0;
    if (Ppos)
		printf("\n%-*s",Ppos,CONT_LINEID);                         //~0722R~
	printf("%.*s",len,pdata+pos);
    return 1;
}//listlinecp
//**********************************************************************
//* print line data
//**********************************************************************
int listfilename(void)
{
	PUFILEH pfh;
//***************
	printf("\n===============   Source Member List   ========================================\n");//~0723R~
    for (pfh=UGETQTOP(&Gfilehq);pfh;pfh=UGETQNEXT(pfh))
        printf("%3d-%s\n",pfh->UFHfileno,pfh->UFHfilename);
    return 0;
}//listfile
