//*CID://+va33R~:                             update#=   23;       //~va33R~
//*************************************************************
//*xefile.c*
//**load/save/edit/browse/end/cancel
//*************************************************************    //~v102I~
//va34:070511 xft:indexlist invalid print seqence when dupfunc on the same plh//~va34I~
//va33:070511 xft:ABEND by plh free(#define macro with no parm;#define func that is not used)//~va33I~
//011018 v102 function to exclude function of DEBUG etc            //~v102I~
//*************************************************************
//#define TEST                                                     //~v102R~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#ifdef DOS
    #ifdef DPMI					//DPMI version
        #include <errno.h>
    #else                       //not DPMI
    #endif                      //DPMI or not
#else
    #include <errno.h>
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
#define CONTINUE_COMMENT -1
#define CONTINUE_QUATE   -2
#define CONTINUE_DQUATE  -3
#define ENDOF_MACDEFINE  -4       //search failed in #define line range//~va33I~

//*******************************************************
       UQUEH  	Gfilehq;		//q of UFILEH
extern int Gerrsw;
extern int Gexcludefuncno;                                         //~v102I~
extern UCHAR *Gexcludefunc[];                                      //~v102R~
//*******************************************************
static PUFUNCDEF  Scurrpfd,Scurrpfdmac,Scurrpfdmacdef;	//current pfd//~0705R~
static int Stestsw;
typedef struct _MAC_STMT{	int MStype;                            //~0709M~
							int MSlen;                             //~0709M~
							int MSlvl;                             //~0709M~
						UCHAR  *MSstmt;                            //~0709M~
                        } MAC_STMT,*PMAC_STMT;                     //~0709M~
static MAC_STMT Smacstmt[]={                                       //~0709M~
		 {ULHMTIF,     5, 1,"ifdef"},                              //~0709M~
		 {ULHMTIF,     6, 1,"ifndef"},                             //~0709M~
		 {ULHMTIF,     2, 1,"if"},                                 //~0709M~
		 {ULHMTELIF,   4, 0,"elif"},                               //~0709M~
		 {ULHMTELSE,   4, 0,"else"},                               //~0709M~
		 {ULHMTENDIF,  5,-1,"endif"},                              //~0709M~
		 {ULHMTDEFINE, 6, 0,"define"},                             //~0709M~
		 {ULHMTUNDEF,  5, 0,"undef"}                               //~0709M~
		 };                                                        //~0709M~
//**********************************
int precompile(PUFILEH Ppfh);
int srchfunc(PUFILEH Ppfh);
int clearcomment(PULINEH *Ppplh,UCHAR **Ppdata);
int srchfuncsub(PULINEH *Ppplh,UCHAR **Ppdata,int Ptype,int Pifsw,UCHAR *Pfuncnm);
int setmacrotype(PULINEH *Ppplh,int Pmactype,int Pmacnest);
UCHAR *namechk(UCHAR *Ptop,UCHAR *Ptail,int *Pplen);
int namechksub(int Pch);
int getbyte(PULINEH *Ppplh,UCHAR **Ppdata,int Psrchchar,int Pifsw,UCHAR *Pfuncnm);
int srchrquate(PULINEH *Ppplh,UCHAR **Ppdata,int Pmsgsw);          //~0708R~
int addfuncdef(PULINEH Pplhs,UCHAR *Pnametop,
			PULINEH Pplhe,UCHAR *Pdefend,int Pnamelen,int Pmacfuncid);//~0722R~
int addfunccall(PULINEH Pplhs,UCHAR *Pnametop,
			 PULINEH Pplhe,UCHAR *Pcallend,int Pnamelen,int Pifsw);
int prototypechk(PULINEH Pplh,UCHAR *Pname);
int freeunused(PUFILEH Ppfh);
int addmacroline(PUFILEH Ppfh);
int addmacrolinefc(PUFILEH Ppfh);                                  //~0720R~
int dropmacroline(PUFILEH Ppfh);
int dropmacrolinesub(PULINEH *Pplh);
int skipmacrocont(PULINEH *Ppplh,UCHAR **Ppdata);
PUFUNCDEF fdalloc(UCHAR *Pname,int Pnamelen);
PUFUNCCALL fcalloc(UCHAR *Pname,int Pnamelen);
int setchiparsub(PUFUNCDEF Ppfd,int Pchildlevel);
int macrochk(PULINEH *Pplh,UCHAR *Pdata,int *Ppnestcnt);           //~0704R~
int errplh(PULINEH Pplh,UCHAR *Pcomm);
int errplh2(PULINEH Pplh,UCHAR *Pcomm);
int defmacrochk(PULINEH *Ppplh,UCHAR **Ppdata,int P1stsw);
int undefmacrochk(PULINEH Pplhs,PULINEH Pplhe,UCHAR *Pname,int Pnamelen);//~0709I~
int defmacrochksub(PULINEH *Ppplh,UCHAR **Ppdata,PULINEH Pplhe,    //~0704R~
					UCHAR **Ppname,int *Pnamelen);                 //~0704I~
int srchdefmacrouse(PULINEH Pplh,UCHAR *Pdata,int Pifsw);          //~0708R~
PUFUNCDEF srchpfd(UCHAR *Pllname,int Plen,int Ptype);              //~0709I~
int setdupent(PUFUNCDEF Ppfd);                                     //~0720I~
int excludefuncchk(char *Pnametop,int Pnamelen);                   //~v102I~
//**********************************************************************
//* process C source file
//**********************************************************************
int filesrchfunc(PUFILEH Ppfh,int Popt)
{
	PMAC_STMT pmacstmt;                                            //~0709I~
    int ii;                                                        //~0709I~
//***************************
    Scurrpfd=Scurrpfdmac=Scurrpfdmacdef=0;	//current pfd for each file//~0723R~
	Stestsw=Popt&OPT_TEST;
    if (!(Popt & OPT_DEFMAC))                                      //~0709R~
    {                                                              //~0709I~
        ii=sizeof(Smacstmt)/sizeof(MAC_STMT);                      //~0709I~
        for (pmacstmt=Smacstmt;ii;ii--,pmacstmt++)                 //~0709I~
        {                                                          //~0709I~
            if (pmacstmt->MStype==ULHMTDEFINE                      //~0709I~
            ||  pmacstmt->MStype==ULHMTUNDEF)                      //~0709I~
            	*pmacstmt->MSstmt=0xff;	//can not be match         //~0709R~
        }                                                          //~0709I~
    }                                                              //~0709I~
                                                                   //~0709I~
    UENQ(UQUE_END,&Gfilehq,Ppfh);
    Ppfh->UFHfileno=UGETQCTR(&Gfilehq);	//fileseqno
//*setup func def/call struct
	if (Stestsw)
		printf("fileproc : %s\n",Ppfh->UFHfilename);
	if (!UGETQTOP(&Ppfh->UFHlineque))	//null file
    	return 0;
	precompile(Ppfh);	//precompile
	srchfunc(Ppfh);		//get func def/call

	dropmacroline(Ppfh);          //drop macro line with no def/call
	freeunused(Ppfh);            //*free not used plh
	addmacroline(Ppfh);  //add macro line to def/call
    return 0;
}//filesrchfunc
//**********************************************************************
//* process macro line
//**********************************************************************
int precompile(PUFILEH Ppfh)
{
	PULINEH plh;
    UCHAR   *pc,*pce;
    int     macnest=0,nesterr=0,len,len2;                          //~0704R~
//***************************
//*comment clear
	plh=UGETQTOP(&Ppfh->UFHlineque);		//top entry
    for (;plh;)      //until eof
    {
    	pc=plh->ULHdata;
    	pce=plh->ULHdata+plh->ULHlen;
//errplh2(plh,"precompile");
        for (;plh && pc<pce;)
        {
            switch(*pc)
            {
            case TAB:
                *pc++=SPACE;    				//tab clear to easy search//~0704R~
                break;
            case '/':
                pc++;
                clearcomment(&plh,&pc);
//printf("after clear comment plh=%08x,pc=%08x(%s),pce=%08x\n",plh,pc,pc,pce);
				if (plh)                                           //~0704I~
    				pce=plh->ULHdata+plh->ULHlen;                  //~0704R~
                break;
            case '"':
            case '\'':
                srchrquate(&plh,&pc,1); //search corresponding quate//~0708R~
				if (plh)                                           //~0704I~
	    			pce=plh->ULHdata+plh->ULHlen;                  //~0704R~
                break;
            default:                                               //~0704I~
                pc++;                                              //~0704I~
            }//switch

        }//until end of line
        if (!plh)
            break;
    	plh=UGETQNEXT(plh);
    }//until end of file
//*macro line process
	plh=UGETQTOP(&Ppfh->UFHlineque);		//top entry
    for (;plh;plh=UGETQNEXT(plh))      //until eof                 //~0704R~
    {
        plh->ULHmacnest=(UCHAR)macnest;                            //~0720M~
    	pc=plh->ULHdata;
    	len=plh->ULHlen;                                           //~0704R~
        len2=(int)umemspnc(pc,SPACE,(UINT)len);                    //~0704R~
        if (len2==len)                                             //~0704I~
        	continue;                                              //~0704I~
        pc+=len2;                                                  //~0704I~
        if (*pc!='#')                                              //~0704I~
        	continue;                                              //~0704I~
		macrochk(&plh,pc,&macnest); //mcro line                    //~0704R~
//printf("macronest=%d,lineno=%ld\n",macnest,plh->ULHlinenor);     //~0708R~
//errplh2(plh,"test");                                             //~0708R~
    }//until end of file
//
    if (macnest)
    {
//search corresponding line                                        //~0708I~
		plh=UGETQEND(&Ppfh->UFHlineque);		//top entry        //~0708I~
    	for (;plh;plh=UGETQPREV(plh))      //until eof             //~0708I~
        	if (plh->ULHmactype                                    //~0708R~
            &&  plh->ULHmacnest==macnest                           //~0708I~
        	&&  (plh->ULHmactype==ULHMTIF                          //~0708R~
        	  || plh->ULHmactype==ULHMTELSE                        //~0708I~
        	  || plh->ULHmactype==ULHMTELIF))                      //~0708I~
            	break;                                             //~0708I~
    	Gerrsw=1;
        if (plh)                                                   //~0708I~
            uerrmsg("%s macro nest err,No pair of lineno %ld",0,   //~0708R~
                    Ppfh->UFHfilename,plh->ULHlinenor);            //~0708R~
        else                                                       //~0708I~
            uerrmsg("%s macro nest err",0,                         //~0708I~
                    Ppfh->UFHfilename);                            //~0708I~
        nesterr++;
    }
    return nesterr;
}//precompile
//**********************************************************************
//* clear comment part("//" and "/*  */")
//  p2:next byte of /   ; next of comment at exit
//  ret : 0:not comment 1:comment cleared
//**********************************************************************
int clearcomment(PULINEH *Ppplh,UCHAR **Ppdata)
{
	PULINEH plh,plhs;
    UCHAR   *pc,*pcs,*pce;
    int     foundsw;
//*****************************
    plh=*Ppplh;
    pc=*Ppdata;
    pcs=pc-1;                 // comment start addr
    pce=plh->ULHdata+plh->ULHlen;

    if (pc>=pce)		// "/" on EOL
    	return 0;
    if (*pc=='/')	// "//" comment
    {
    	memset(pcs,SPACE,(UINT)((ULONG)pce-(ULONG)pcs));           //~v102R~
        *Ppdata=pce;
        return 1;		//comment cleared
    }
    if (*pc++!='*')	//not comment
    	return 0;
// "/*" comment start
    foundsw=0;
    plhs=plh;
    for (;plh;)
    {
//	    errplh2(plh,"/* comment");
        for (;pc<pce;pc++)  //end of line
        {
        	if (!(pc=memchr(pc,'*',(UINT)((ULONG)pce-(ULONG)pc))))	//no *//~v102R~
            {
            	pc=pce;
            	break;
            }
            if (pc+1<pce && *(pc+1)=='/')
            {
            	foundsw=1;
            	pc+=2;
            	break;
            }
        }
//printf("clear comment plh=%08x,%.*s\n",plh,(ULONG)pc-(ULONG)pcs,pcs);
        memset(pcs,SPACE,(UINT)((ULONG)pc-(ULONG)pcs));            //~v102R~
        if (foundsw)
        	break;
    	if (!(plh=UGETQNEXT(plh)))
        {
        	errplh(plhs,"missing \"*/\"");
        	break;
        }
		pc=pcs=plh->ULHdata;
	    pce=plh->ULHdata+plh->ULHlen;
//printf("clear comment next plh=%08x",plh);
    }
	*Ppplh=plh;
	*Ppdata=pc;
    return 1;
}//clearcomment
//**********************************************************************
//* search corresponding right quatation
//*prm 2:pos of left quatation;next of right quatation at exit
//**********************************************************************
int srchrquate(PULINEH *Ppplh,UCHAR **Ppdata,int Pmsgsw)           //~0708R~
{
    PULINEH plh;
    UCHAR *pc,*pce,contsw;                                         //~0704R~
    int   quateid;
//***************************
	plh=*Ppplh;
	pc=*Ppdata;
    pce=plh->ULHdata+plh->ULHlen;
    quateid=*pc++;
//skip comment,literal continued from prev line
	for (;plh;)
    {
//printf("srch rquate:plh=%08x,pc=%08x(-1=%s)\n",plh,pc,pc-1);
//        errplh2(plh,"srch rquate");
    	for (contsw=0;pc<pce;*pc++=SPACE)                          //~0704R~
        {
        	if (*pc=='\\')
            {
//printf("contsw pc=%s\n",pc);
				pc++;                                              //~0704I~
				if (pc<pce)                                        //~0704I~
            		*pc=SPACE;                                     //~0704R~
                else                                               //~0704I~
                	contsw=1;                                      //~0704I~
                continue;
			}
        	if (*pc==quateid)
                break;
		}
        if (pc<pce)
        	break;
//printf("contpos=%08x,quateid=%c\n",contpos,quateid);
        plh=UGETQNEXT(plh);
        if (plh)                                                   //~0708I~
        {                                                          //~0708I~
            UCBITON(plh->ULHflag,ULHFLITERAL);                     //~0708I~
            pc=plh->ULHdata;                                       //~0708I~
            pce=plh->ULHdata+plh->ULHlen;                          //~0708I~
        }                                                          //~0708I~
        if (!contsw || !plh)                                       //~0704R~
        {
        	if (Pmsgsw)	//precompile phase                         //~0708I~
	            errplh(*Ppplh,"No literal end");                   //~0708R~
            break;
        }
	}
	*Ppplh=plh;
    *Ppdata=pc+1;
    return 0;
}//srchrquate
//**********************************************************************
//* macro chk
//* p2:addr of next of '#' sign:EOL of last line
//* ret:0:not macro line;1:macro line
//**********************************************************************
int macrochk(PULINEH *Ppplh,UCHAR *Pdata,int *Ppnestcnt)           //~0704R~
{
	PMAC_STMT pmacstmt;
    PULINEH plh;
	UCHAR *pdata;                                                  //~0704R~
    int   macronest,macrotype,rlen,len,ii,rc=0;                    //~0704R~
//*********************
	plh=*Ppplh;
	pdata=Pdata+1;	//next of '#'                                  //~0704R~
    macronest=*Ppnestcnt;                                          //~0704I~
//search verb                                                      //~0704I~
    for (;plh;)                                                    //~0704I~
    {                                                              //~0704I~
	    rlen=(int)(plh->ULHlen-((ULONG)pdata-(ULONG)plh->ULHdata));//~0704I~
        len=(int)umemspnc(pdata,SPACE,(UINT)rlen);                 //~0704R~
        if (len==rlen)                                             //~0704R~
        {                                                          //~0708I~
            rlen=0;                                                //~0708I~
        	break;                                                 //~0704I~
        }                                                          //~0708I~
        else                                                       //~0704I~
        	if (len!=rlen-1 || *(pdata+len)!='\\')                 //~0704R~
            {                                                      //~0704I~
                pdata+=len;                                        //~0704I~
                rlen-=len;                                         //~0704I~
            	break;                                             //~0704I~
            }                                                      //~0704I~
        plh=UGETQNEXT(plh);                                        //~0704R~
        if (!plh)                                                  //~0704I~
        	break;                                                 //~0704I~
        pdata=plh->ULHdata;                                        //~0704I~
    }                                                              //~0704I~
//set macro type                                                   //~0704I~
    macrotype=0;                                                   //~0704I~
    if (plh && rlen)  //verb found                                 //~0708R~
    {                                                              //~0704I~
        ii=sizeof(Smacstmt)/sizeof(MAC_STMT);                      //~0704R~
        for (pmacstmt=Smacstmt;ii;ii--,pmacstmt++)                 //~0704R~
        {                                                          //~0704R~
            len=pmacstmt->MSlen;                                   //~0704R~
            if (rlen>=len && !memcmp(pdata,pmacstmt->MSstmt,(UINT)len))//~0704R~
                break;                                             //~0704R~
        }                                                          //~0704R~
        if (ii)     //found                                        //~0704R~
        {                                                          //~0704R~
            macronest+=pmacstmt->MSlvl;                            //~0704R~
            if (macronest<0)                                       //~0704R~
            {                                                      //~0704R~
                errplh(plh,"macro nest err(exesive #endif)");      //~0708R~
                macronest=0;                                       //~0704R~
            }                                                      //~0704R~
            macrotype=pmacstmt->MStype;                            //~0704R~
            plh->ULHmacdata=pdata+len;;                            //~0709R~
            rc=1;                                                  //~0709R~
        }//valid verb                                              //~0704R~
    }//verb found                                                  //~0704I~
    setmacrotype(Ppplh,macrotype,macronest);                       //~0704R~
    *Ppnestcnt=macronest;                                          //~0704M~
    return rc;                                                     //~0704R~
}//macrochk
//**********************************************************************
//* set macro line(consider line continuation)
//**********************************************************************
int setmacrotype(PULINEH *Ppplh,int Pmactype,int Pmacnest)
{
	PULINEH plh,plhp;
    int     lastsw;
//*****************************
    plh=*Ppplh;
    for (plhp=0;plh;plhp=plh,plh=UGETQNEXT(plh))
    {
        lastsw=(*(plh->ULHdata+plh->ULHlen-1)!='\\');
	    if (Pmactype)
        {
            plh->ULHtype=ULHTMACRO;
            plh->ULHmactype=(UCHAR)Pmactype;
            plh->ULHmacnest=(UCHAR)Pmacnest;
            if (plhp)
                UCBITON(plh->ULHflag,ULHFMACHASP);
            if (!lastsw)
                UCBITON(plh->ULHflag,ULHFMACHASN);
        }
        else
        	memset(plh->ULHdata,SPACE,(UINT)plh->ULHlen);	//clear other macro//~0704R~

        if (lastsw)
            break;
    }
    *Ppplh=plh;
    return 0;
}//setmacrotype
//**********************************************************************
//* search func def/call stmt
//**********************************************************************
int srchfunc(PUFILEH Ppfh)
{
	PULINEH plh;
	UCHAR  *pc;
//***************************
	plh=UGETQTOP(&Ppfh->UFHlineque);		//top entry
    pc=plh->ULHdata;
    srchfuncsub(&plh,&pc,0,0,0);
    return 0;
}//srchfunc
//**********************************************************************
//* search func def/call over macro
//* Pifsw:1:in #if block,2:in #define block,3:#define block after macro name found
//* ret  -1:eof
//**********************************************************************
int srchfuncsub(PULINEH *Ppplh,UCHAR **Ppdata,int Ptype,int Pifsw,UCHAR *Pfuncnm)
{
	PULINEH plh,plhs,plhrp,plhsv;
    UCHAR   *pcnext,*pdatas,*pdatarp,*pdatasv,*funcnm;
    int     namelen,ch,len;
    UCHAR   namewk[256];
    int rc2;                                                       //~va33I~
	PULINEH plherr;                                                //~va33I~
//***************************
    plh=*Ppplh;
    pcnext=*Ppdata;
//search new top
    for (;plh;)      //until eof
    {
//      if (getbyte(&plh,&pcnext,Ptype,Pifsw,Pfuncnm))    //get current effective byte//~va33R~
        if ((rc2=getbyte(&plh,&pcnext,Ptype,Pifsw,Pfuncnm)))   //get current effective byte//~va33R~
        {
        	if (!plh)
	        	break;
            *Ppdata=pcnext;
            *Ppplh=plh;
            if (rc2==8)	//(Pifsw=2) at defmacrochk reached to Snextplh(endof #define macro)//~va33I~
            	return ENDOF_MACDEFINE;                            //~va33I~
            return 0;	//rc=4:end of if-block
        }
        switch(*pcnext++)
        {
        case '(':
            if (Ptype=='{') //serching funcdef end                 //~0708R~
                return 4;                                          //~0708R~
			if (!(pdatas=namechk(plh->ULHdata,pcnext-2,&namelen)))	//not funcname
            	plhs=0;
            else
            	plhs=plh;
            if (!(funcnm=pdatas))
            	funcnm=Pfuncnm;   	//of 1st level
//printf("Pfuncnm=%.8s,funcnm=%.8s\n",Pfuncnm,funcnm);
//  		if (srchfuncsub(&plh,&pcnext,')',Pifsw,funcnm))	//search right parenthesis//~va33R~
//          	break;                                             //~va33R~
			plherr=plh;                                            //~va33I~
			if ((rc2=srchfuncsub(&plh,&pcnext,')',Pifsw,funcnm)))	//search right parenthesis//~va33I~
            {                                                      //~va33I~
            	if (rc2==ENDOF_MACDEFINE)	//search ")" for #define macro failed//~va33I~
                {                                                  //~va33I~
	        		errplh(plherr,"Missing ')' for function #define");//~va33I~
                	return rc2;                                    //~va33I~
                }                                                  //~va33I~
            	break;                                             //~va33I~
            }                                                      //~va33I~
            if (!plhs)	//( ) but not func parm
            	break;
            plhrp=plh;	//plh of right parent
            pdatarp=pcnext;	//next of rp
//      	if (getbyte(&plh,&pcnext,Ptype,Pifsw,Pfuncnm))	//srch next char over comment//~va33R~
        	if ((rc2=getbyte(&plh,&pcnext,Ptype,Pifsw,Pfuncnm)))	//srch next char over comment//~va33I~
            {
            	if (!plh)
            		break;
	            *Ppdata=pcnext;
    	        *Ppplh=plh;
                if (Pifsw!=2)	//#if block
                	errplh2(plhs,"Assumed as function call");
            	addfunccall(plhs,pdatas,plhrp,pdatarp,namelen,Pifsw);
            	if (rc2==8)	//(Pifsw=2) at defmacrochk reached to Snextplh(endof #define macro)//~va33I~
            		return ENDOF_MACDEFINE;                        //~va33I~
                return 0;
            }
            ch=*pcnext;
            if (ch=='{')   //func def
            	addfuncdef(plhs,pdatas,plh,pcnext++,namelen,0);    //~0722R~
            else
            if (ch==';')	//prototype?
            {
            	if (Pifsw==2	//#define
                ||  Scurrpfd)   //avoid prototype definition
                    if (!prototypechk(plhs,pdatas))
                        addfunccall(plhs,pdatas,plhrp,pdatarp,namelen,Pifsw);
            }
            else
			if  (namechksub(ch))	//id
            {
	            if (Ptype=='{')                                    //~0708I~
    	            return 12;  //loop protection                  //~0708I~
            	plhsv=plh;
                pdatasv=pcnext;
                if (plhs==plhrp)                                   //~0708I~
	                len=(int)((ULONG)pdatarp-(ULONG)pdatas);       //~0708R~
                else                                               //~0708I~
    	            len=plhs->ULHlen-(int)((ULONG)pdatas-(ULONG)plhs->ULHdata);//~0708R~
                if (len>16)
                	len=16;
                sprintf(namewk,"missing '{' for %.*s...",len,pdatas);//~0708R~
                if (srchfuncsub(&plh,&pcnext,'{',Pifsw,0)) //search '{'//~0708R~
                {       //eof or dup serach condition              //~0708R~
                	plh=plhsv;
                    pcnext=pdatasv;
                    errplh(plh,namewk);
                    break;
                }
            	addfuncdef(plhs,pdatas,plh,pcnext-1,namelen,0);    //~0722R~
            }
            else	//call
            	addfunccall(plhs,pdatas,plhrp,pdatarp,namelen,Pifsw);
            break;
        case ')':
            if (Ptype!=')')
            {
            	if (!Pifsw)   //not in if-block
               		errplh(plh,"unmatched ')'");
            	break;
            }
            *Ppplh=plh;
            *Ppdata=pcnext;
            return 0;
        case '{':
        	if (Ptype==')')
            {
                errplh(plh,"unmatched \"{\"");
            	break;
            }
        	if (Ptype=='{')
            {
            	*Ppplh=plh;
            	*Ppdata=pcnext;
            	return 0;
            }
        }//switch
    }//search func
    return -1;
}//srchfuncsub
//**********************************************************************
//* search non comment data top
//*   \" is data  /*,//," end chk by started
//* ret:macro type or -1 when eof
//**********************************************************************
int getbyte(PULINEH *Ppplh,UCHAR **Ppdata,int Psrchchar,int Pifsw,UCHAR *Pfuncnm)
{
	PULINEH plh;
    UCHAR   *pc,*pce,mactype;
    int     rc=0;
//*****************************
    pc=*Ppdata;
    for (plh=*Ppplh;plh;)      //until eof
    {
    	pce=plh->ULHdata+plh->ULHlen;
        for (;plh && pc<pce;)
        {
            switch(*pc)
            {
            case '"':
            case '\'':
//printf("getbyte srch rqute plh=%08x,pc=%08x(%s)\n",plh,pc,pc);
                srchrquate(&plh,&pc,0); //search corresponding quate//~0708R~
		    	pce=plh->ULHdata+plh->ULHlen;
                continue;
            case SPACE:                                            //~0704R~
            	pc++;
                continue;
            }//switch
            break;
        }//until end of line
        if (!plh)
        	break;
        if (pc<pce)
        {
//#define block process
            if (plh->ULHmactype==ULHMTDEFINE && Pifsw!=2)	//1st counter
            {
                defmacrochk(&plh,&pc,1); //#define func chk,try next line
                continue;   //now end of line
            }
            else                                                   //~0709I~
            if (plh->ULHmactype==ULHMTUNDEF)	//1st counter      //~0709I~
            {                                                      //~0709I~
                defmacrochk(&plh,&pc,2); //#undef symbol process   //~0709I~
                continue;   //now end of line                      //~0709I~
            }                                                      //~0709I~
            else                                                   //~0709I~
            break;
        }
    	plh=UGETQNEXT(plh);
        if (!plh)
        	break;
        pc=plh->ULHdata;
//#define stmt EOL chk
        if (Pifsw==2)		//to get byte in #define line
        {                                                          //+va33I~
        	if (defmacrochk(&plh,&pc,0))	//end of stmt chk
            {
            	rc=8;			//end of #definestmt
                break;
            }
            else
            {                                                      //~0705I~
    	    	srchdefmacrouse(plh,pc,Pifsw);   //search defined macro usage//~0708R~
            	continue;	//chk 1st of byte in continued line of #define stmt
            }                                                      //~0705I~
        }                                                          //+va33I~

        if (plh->ULHtype!=ULHTMACRO)
        {                                                          //~0708I~
    	    srchdefmacrouse(plh,pc,Pifsw);   //search defined macro usage//~0708R~
        	continue;   //loop in line
        }                                                          //~0708I~
        if (plh->ULHmactype==ULHMTDEFINE                           //~0709R~
        ||  plh->ULHmactype==ULHMTUNDEF)                           //~0709I~
        	continue;   //catch at top byte
        while (plh && UCBITCHK(plh->ULHflag,ULHFMACHASN))   //until last cont
			plh=UGETQNEXT(plh);	//to end of continued
        if (!plh)
            break;
        pc=plh->ULHdata+plh->ULHlen;
        mactype=plh->ULHmactype;
        if (mactype==ULHMTIF||mactype==ULHMTELIF)	//#if or #elif
        {
			if (Psrchchar==')')   //if or elif
            {
//printf("getbyte %.8s\n",Pfuncnm);
            	if (Pfuncnm)
                	errplh2(plh,"macro in func call");
                srchfuncsub(&plh,&pc,0,1,Pfuncnm); //start new func search in if block
            }
            else
			if (Psrchchar=='{')   //if or elif
                errplh2(plh,"macro in func definition");//warning
        }
        else		//else,endif
        	if (Pifsw==1)		//in if-block
            {
            	rc=4;	//end of if block
                break;
            }
    }//all line
    *Ppplh=plh;
	*Ppdata=pc;
    if (!plh)
    	rc=-1;
    return rc;
}//getbyte
//**********************************************************************
//* func search in #define line
//* p2:1st non space byte of line;set to end of last continued line
//* p3:1:1st byte of #define ,0:chk end of stmt
//* rc:0:continue to get next byte,
//     4:return to func search
//**********************************************************************
int defmacrochk(PULINEH *Ppplh,UCHAR **Ppdata,int P1stsw)
{
static PULINEH Snextplh;	//next of #define macro line
	PULINEH plh,plhe,plhs;
	UCHAR *pc,*pce,*pname;                                         //~0704R~
    int rc=0,namelen,macroparmsw;
//*********************
	plh=*Ppplh;
	pc=*Ppdata;
    if (P1stsw)                 //#define macro line
    {
    	plhs=plh;
        for (plhe=plh;plhe;plhe=UGETQNEXT(plhe))
            if (!UCBITCHK(plhe->ULHflag,ULHFMACHASN))
                    break;
         pce=plhe->ULHdata+plhe->ULHlen;

    	if (!defmacrochksub(&plh,&pc,plhe,&pname,&namelen))//not valid #definr macro//~0704R~
        {
            if (P1stsw==1)  //#define macro                        //~0709I~
            {                                                      //~0709I~
                Snextplh=UGETQNEXT(plhe);                          //~0709R~
                macroparmsw=(*(pname+namelen)=='(');   //func macro//~0709R~
                addfuncdef(plhs,pname,plhe,pce,namelen,1+macroparmsw);//~0722R~
                Scurrpfdmacdef=Scurrpfdmac; //parm to srchdefmacrouse;no replace by this last define//~0722R~
                srchdefmacrouse(plh,pc,2);   //search defined macro usage in #define//~0709R~
                *pc='+';    //to stop namechk(avoid asuumed as func by '('//~0709R~
                srchfuncsub(&plh,&pc,0,2,0); //start new func search in #define block//~0709R~
                Scurrpfdmacdef=0;   //parm to no replace by this last define//~0709R~
//clear macro with no func call
                if (!macroparmsw && !UGETQTOP(&Scurrpfdmac->UFDqhc))//~0709R~
                {                                                  //~0709R~
		          if (!UCBITCHK(Scurrpfdmac->UFDflag,UFDF_DUPDEF2)) //no duplicated follower//~va33R~
                  {                                                //~va33I~
                    UDEQ(UQUE_ENT,&(UGETPFH(plh)->UFHfuncque),Scurrpfdmac);//~0709R~
                    ufree(Scurrpfdmac);                            //~0709R~
                    Scurrpfdmac=0;                                 //~0709R~
//                  for (plh=plhs;plh;plh=UGETQNEXT(plh))          //~va33R~
//                  {                                              //~va33R~
//                      plh->ULHtype=0;     //drop later           //~va33R~
//                      if (plh==plhe)                             //~va33R~
//                          break;                                 //~va33R~
//                  }                                              //~va33R~
                  }                                                //~va33M~
                }                                                  //~0709R~
            }   //#define                                          //~0709I~
            else    //#undef                                       //~0709I~
				undefmacrochk(plhs,plhe,pname,namelen);            //~0709I~
        }//valid #define/#undef                                    //~0709R~
        plh=plhe;
        pc=pce;
	}//end chk
	else                         //in processing
        if (plh==Snextplh)	//singleline
            rc=4;
	*Ppplh=plh;
	*Ppdata=pc;
    return rc;		//continue to get next byte
}//defmacrochk
//**********************************************************************
//* search #define macro macro name and operand
//* p1:start plh
//* p2:top of 1st line;output name pos
//* p3:last plh
//* p4:output macro name                                           //~0704R~
//* p5:output macro name len                                       //~0704I~
//* rc:0:valid
//     4:no valid #define macro
//**********************************************************************
int defmacrochksub(PULINEH *Ppplh,UCHAR **Ppdata,PULINEH Pplhe,    //~0704R~
					UCHAR **Ppname,int *Pnamelen)                  //~0704I~
{
	PULINEH plh;
	UCHAR *pc,*pce,*pname;
    int   ii,len,len2,namelen;                                     //~0704R~
//*********************
	plh=*Ppplh;
	pc=*Ppdata;
    ii=0;
    for (;;)
    {
        pce=plh->ULHdata+plh->ULHlen;    //end pos
    	switch(ii)
        {
        case 0:     //skip to verb line                            //~0708I~
        	if ((pc=plh->ULHmacdata),pc)                           //~0708I~
            {                                                      //~0708I~
	            ii=1;                                              //~0708I~
                continue;                                          //~0708I~
            }                                                      //~0708I~
            break;                                                 //~0708R~
        case 1:     //skip space                                   //~0708R~
            len=(int)((ULONG)pce-(ULONG)pc);
            if (UCBITCHK(plh->ULHflag,ULHFMACHASN))
                len--;      //last cont "\"
        	if (len<=0)
            	break;	//to next line
	        len2=(int)umemspnc(pc,SPACE,(UINT)len);                //~0704R~
            if (len2==len)
            	break;	//to next line
	        pc+=len2;
            ii=2;		//get name                                 //~0708R~
            continue;
        case 2:		//name get                                     //~0708R~
        	pname=pc;
            len=(int)((ULONG)pce-(ULONG)pc);
            if (UCBITCHK(plh->ULHflag,ULHFMACHASN))
                len--;      //last cont "\"
        	pc=ustrnpbrk(pc," \t(",(UINT)len); //search "("
            ii=9;   //return 0;                                    //~0704I~
            if (pc)
            {
            	namelen=(int)((ULONG)pc-(ULONG)pname);
                if (*pc=='(')       //func type                    //~0704I~
                {                                                  //~0704I~
                    ii=3;           //search ')'                   //~0708R~
                    continue;                                      //~0704I~
                }                                                  //~0704I~
            }
            else
            {                                                      //~0704I~
            	namelen=len;
                pc=pce;                                            //~0704I~
            }                                                      //~0704I~
            break;
        case 3:		//name get                                     //~0708R~
            len=(int)((ULONG)pce-(ULONG)pc);                       //~0704I~
            if (UCBITCHK(plh->ULHflag,ULHFMACHASN))                //~0704I~
                len--;      //last cont "\"                        //~0704I~
        	pc=memchr(pc,')',(UINT)len); //search ")"              //~0704I~
            if (!pc)                                               //~0704I~
            	break;		//next plh                             //~0704I~
            pc++;	//define part pos                              //~0704I~
            ii=9;                                                  //~0704I~
            break;                                                 //~0704I~
        }
        if (ii==9)
        	break;
        if (plh==Pplhe)                                            //~0704R~
        	return 4;
        plh=UGETQNEXT(plh);
        if (!plh)
        	return 4;
        pc=plh->ULHdata;
    }
	*Ppplh=plh;
	*Ppdata=pc;                                                    //~0704R~
	*Ppname=pname;                                                 //~0704I~
	*Pnamelen=namelen;
    return 0;		//continue to get next byte
}//defmacrochksub
//**********************************************************************//~0704I~
//* search macro usage on the line,and add as func call            //~0704I~
//* ret :1 func call registered                                    //~0704I~
//**********************************************************************//~0704I~
int srchdefmacrouse(PULINEH Pplh,UCHAR *Pdata,int Pifsw)           //~0708R~
{                                                                  //~0704I~
	PUFUNCDEF pfd;                                                 //~0704I~
    PUFILEH   pfh;                                                 //~0704I~
    UCHAR    *pc,*pct;                                             //~0705R~
    int namelen,rc=0,len,ifsw;                                     //~0708R~
//************                                                     //~0704I~
	if ((ifsw=Pifsw)==2)                                           //~0708I~
    	ifsw=3;				//repl on macro line                   //~0708I~
	pfh=UGETPFH(Pplh);                                             //~0704I~
	pct=Pplh->ULHdata;                                             //~0705I~
	len=Pplh->ULHlen-(int)((ULONG)Pdata-(ULONG)pct);               //~0705R~
    for (pfd=UGETQTOP(&pfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))    //~0704I~
        if ((Pifsw==2 && pfd!=Scurrpfdmacdef)	//avoid repl by self define//~0708R~
        ||  (Pifsw!=2))                                            //~0708I~
        	if (UCBITCHK(pfd->UFDflag,UFDF_DEFINEMAC)         //macro//~0708I~
            &&  !UCBITCHK(pfd->UFDflag,UFDF_DEFINEMACP))      //macro func without parm//~0705R~
            {                                                      //~0708R~
                namelen=(int)pfd->UFDfnl;                          //~0708R~
                if (len<namelen)                                   //~0708R~
                    continue;                                      //~0708R~
                pc=umemmem(Pdata,pfd->UFDfnm,(UINT)len,(UINT)namelen);//~0708R~
                if (!pc)                                           //~0708R~
                    continue;   //try next func                    //~0708R~
                if (pc!=pct && isalnum(*(pc-1)))                   //~0708R~
                    continue;   //part of other word               //~0708R~
                if (isalnum(*(pc+namelen)))                        //~0708R~
                    continue;   //part of word                     //~0708R~
                addfunccall(Pplh,pc,Pplh,pc+namelen,namelen,ifsw); //~0708R~
                rc=1;                                              //~0708R~
                break;                                             //~0709I~
            }                                                      //~0708R~
    return rc;                                                     //~0704I~
}//srchdefmacrouse(PULINEH Pplh)                                   //~0704I~
//**********************************************************************//~0709I~
//* process #undef line                                            //~0709I~
//**********************************************************************//~0709I~
int undefmacrochk(PULINEH Pplhs,PULINEH Pplhe,UCHAR *Pname,int Pnamelen)//~0709I~
{                                                                  //~0709I~
    PULINEH   plh;                                                 //~0709R~
    PUFUNCDEF pfd,pfdo,pfdn;                                       //~0709R~
//************                                                     //~0709I~
	if (pfd=srchpfd(Pname,Pnamelen,1),pfd)	//search predefined macro//~0709R~
    {                                                              //~0709I~
        for (pfdn=pfd;pfdn;) //search last pfd                     //~0709R~
        {                                                          //~0709I~
        	pfdo=pfdn;                                             //~0709R~
			pfdn=pfdn->UFDdupnamepfd;                              //~0709R~
        }                                                          //~0709I~
    	pfdo->UFDundefplhs=Pplhs;			//set undef to latest #define//~0720R~
    	pfdo->UFDundefplhe=Pplhe;			//set undef to latest #define//~0720I~
    }                                                              //~0709I~
    for (plh=Pplhs;plh;plh=UGETQNEXT(plh))                         //~0709R~
    {                                                              //~0709I~
    	if (pfd)                                                   //~0709I~
        	UCBITON(plh->ULHflag,ULHFASSIGNED);                    //~0709I~
        else                                                       //~0709I~
    		plh->ULHtype=0;	//drop #undef line                     //~0709R~
        if (plh==Pplhe)                                            //~0709R~
        	break;                                                 //~0709I~
    }                                                              //~0709I~
    return 4;                                                      //~0709I~
}//undefmacrochk                                                   //~0709I~
//**********************************************************************
//* func name chk
//* ret:func name top addr
//*     plen:reason code when rc=0;
//           1:all space,2:no symbol,3:known func
//**********************************************************************
UCHAR *namechk(UCHAR *Ptop,UCHAR *Ptail,int *Pplen)
{
	UCHAR *pc;
    int   len;
//*********************
    *Pplen=1;			//all space
    for (pc=Ptail;pc>=Ptop;pc--)
        if (*pc!=SPACE) //skip tab
            break;
    if (pc<Ptop)
        return 0;
    *Pplen=2;			//symbol err
    for (len=0;pc>=Ptop;pc--,len++)
    {
        if (isalnum(*pc))
            continue;
        if (*pc!='#' && *pc!='$' && *pc!='_' && *pc!='@')
            break;
    }
    if (!len)
        return 0;
    pc++;
    if (isdigit(*pc))	//top char should be not numeric
        return 0;
    *Pplen=3;			//known symbol
    if ((len==6 && !memcmp(pc,"switch",6))
    ||  (len==6 && !memcmp(pc,"return",6))
    ||  (len==2 && !memcmp(pc,"if",    2))
    ||  (len==5 && !memcmp(pc,"while", 5))
    ||  (len==3 && !memcmp(pc,"for",   3))
    ||  (len==5 && !memcmp(pc,"until", 5))
    ||  (len==6 && !memcmp(pc,"sizeof",6)))
        return 0;
    *Pplen=len;
    return pc;
}//namechk
//**********************************************************************
//* var id top byte chk
//* ret:1:valid id,0:err
//**********************************************************************
int namechksub(int Pch)
{
//*********************
	if (isalpha(Pch))
    	return 1;
    if (Pch=='#' || Pch=='$' || Pch=='_' || Pch =='@')
    	return 1;
    return 0;
}//namechk
//**********************************************************************
//* chk proto type definition
//* ret:0:no proto type,1:prototype
//**********************************************************************
int prototypechk(PULINEH Pplh,UCHAR *Pname)
{
	UCHAR *pc,*pctop,ch,*previd;
    int namelen,astctr,symbfound;
//*********************
    for (pc=Pname-1,pctop=Pplh->ULHdata,astctr=0;pc>=pctop;pc--)
    {
    	ch=*pc;
        if (ch==SPACE) //skip space                                //~0704R~
            continue;
        if (ch!='*')		//not ptr prototype
        	break;
        astctr++;
    }
    if (pc<pctop)
        return 0;       	//return type,func call
    if (!isalnum(ch))       //not id(*)funcnum
        return 0;       	//return type,func call
    if (!astctr)			//no * before func name
        return 1;       	//id+funcname
// id+*+funcname
	for (symbfound=0;pc>=pctop;)
    {
		if (!(previd=namechk(pctop,pc,&namelen)))	//no identifier before *
        {
        	if (namelen!=1		//not previous is all space
            ||  !symbfound)
            	return 0;
            break;
        }
        symbfound=1;	//once found
        pc=previd-1;
    }
    return 1;           //any number  of identifier before func name
}//prototypechk
//**********************************************************************
//* register func definition
//**********************************************************************
int addfuncdef(PULINEH Pplhs,UCHAR *Pnametop,
			PULINEH Pplhe,UCHAR *Pdefend,int Pnamelen,int Pmacfuncid)//~0722R~
{
	PUFILEH pfh;
	PULINEH plh;
	PUFUNCDEF pfd,pfdo,pfdn,pfdtop;                                //~0720R~
    UCHAR   *pc;
    UCHAR   msgwk[256];                                            //~0715I~
//*********************
//*chk return type line
	for (pc=Pplhs->ULHdata;pc<Pnametop;pc++)
    	if (*pc!=SPACE)
    		break;
    if (pc==Pnametop)	//no return type
        if (plh=UGETQPREV(Pplhs),plh)
        	Pplhs=plh;
//cretae entry
	pfh=UGETPFH(Pplhs);
	pfd=fdalloc(Pnametop,Pnamelen);
    if (Pplhs->ULHmactype==ULHMTDEFINE)
		Scurrpfdmac=pfd;
    else
		Scurrpfd=pfd;
    pfd->UFDplhs=Pplhs;
    pfd->UFDplhe=Pplhe;
    pfd->UFDdeftop=Pnametop;
    pfd->UFDdefend=Pdefend;
    switch(Pmacfuncid)                                             //~0722I~
    {                                                              //~0722I~
    case 1:                                                        //~0722I~
        UCBITON(pfd->UFDflag,UFDF_DEFINEMAC);                      //~0722I~
    	break;                                                     //~0722I~
    case 2:                                                        //~0722I~
        UCBITON(pfd->UFDflag,UFDF_DEFINEMAC|UFDF_DEFINEMACP);  //macro with parm//~0722I~
    }                                                              //~0722I~
	if (Stestsw)
		printf("func def %s\n",pfd->UFDfnm);
	pfdtop=pfdo=srchpfd(Pnametop,Pnamelen,0);			//dup name chk//~0720R~
    if (pfdo)                                                      //~0708I~
    {                                                              //~0708I~
		if (Stestsw)                                               //~0720I~
    		errplh2(Pplhs,"TEST msg; dup def");//warning           //~0720I~
        if (!UCBITCHK(pfd->UFDflag,UFDF_DEFINEMAC)                 //~0715I~
        ||  !UCBITCHK(pfdo->UFDflag,UFDF_DEFINEMAC)                //~0715R~
        ||  UGETPFH(pfd->UFDplhs)!=UGETPFH(pfdo->UFDplhs))         //~0715I~
        {   //not macro type                                       //~0715I~
			pc=UGETPFH(pfdo->UFDplhs)->UFHfilename;//warning       //~0720R~
			pc+=PATHLEN(pc);                                       //~0720I~
    		sprintf(msgwk,"duplicated function name definition with line %ld of %s",//~0720R~
				pfdo->UFDplhs->ULHlinenor,pc);//warning            //~0720R~
    		errplh2(Pplhs,msgwk);//warning                         //~0715R~
        }                                                          //~0715I~
        for (pfdn=pfdo;pfdn;)                                      //~0708I~
        {                                                          //~0708I~
        	pfdo=pfdn;                                             //~0708I~
			pfdn=pfdn->UFDdupnamepfd;                              //~0708R~
        }                                                          //~0708I~
        pfdo->UFDdupnamepfd=pfd;	//dup name chain               //~0708R~
        pfd->UFDdupnametoppfd=pfdtop;	//dup name chain top       //~0720R~
        UCBITON(pfd->UFDflag,UFDF_DUPDEF2); //duplicated follower  //~0708I~
        pfd->UFDdupcnt=pfdo->UFDdupcnt+1;	//dup name chain top   //~va34I~
    }                                                              //~0708I~
    UENQ(UQUE_END,&pfh->UFHfuncque,pfd);                           //~0708R~
    for (plh=Pplhs;plh;plh=UGETQNEXT(plh))
    {
		if (Stestsw)
			printf("func def:%5ld: %.*s\n",plh->ULHlinenor,plh->ULHlen,plh->ULHdata);//~v102R~
//        if (Pplhs->ULHmactype==ULHMTDEFINE)                      //~0722R~
//            UCBITON(plh->ULHflag,ULHFFUNCMACRO);    //id of function macro//~0722R~
       	UCBITON(plh->ULHflag,ULHFASSIGNED);                        //~0720I~
        plh->ULHtype=ULHTDEF;
        if (plh==Pplhe)
        	break;
	}
	return 0;
}//addfuncdef
//**********************************************************************
//* register func definition
//**********************************************************************
PUFUNCDEF fdalloc(UCHAR *Pname,int Pnamelen)
{
	PUFUNCDEF pfd;
//*********************
	pfd=UALLOCC(1,(UINT)(UFUNCDEFSZ+Pnamelen));
    if (!pfd)
    	errmalloc("FuncDef Elem");
	pfd->UFDfnl=(UCHAR)Pnamelen;
	memcpy(pfd->UFDfnm,Pname,(UINT)Pnamelen);
	return pfd;
}//fdalloc
//**********************************************************************
//* register func call
//* Pifsw:0:normal,1:in #if block,2:in #define line,3:macro use in #define line//~0705R~
//**********************************************************************
int addfunccall(PULINEH Pplhs,UCHAR *Pnametop,
			 PULINEH Pplhe,UCHAR *Pcallend,int Pnamelen,int Pifsw)
{
	PUFUNCCALL pfc;
	PUFUNCDEF  pfd,pfdc;                                           //~0723R~
    PUQUEH   pqh;
    PULINEH  plh;
    int macrousesw,len;                                            //~0708R~
    UCHAR   namewk[256];                                           //~0708I~
//*********************
	if (excludefuncchk(Pnametop,Pnamelen)) //exclude function nmae //~v102I~
    	return 0;                                                  //~v102I~
	if (Pifsw==3)                                                  //~0705R~
    {                                                              //~0704I~
    	Pifsw=2;                                                   //~0705R~
        macrousesw=1;                                              //~0704I~
    }                                                              //~0704I~
    else                                                           //~0704I~
        macrousesw=0;                                              //~0705R~
	if (Pifsw==2)		//in #define macro
    	pfd=Scurrpfdmac;
    else
		pfd=Scurrpfd;
    if (!pfd)
    {   //who called this function?                                //~0723R~
//printf("no funcdef %s\n",Pnametop);                              //~0708R~
        len=Pnamelen;                                              //~0723M~
        if (len>32)                                                //~0723M~
        	len=32;                                                //~0723M~
	    pfdc=srchpfd(Pnametop,Pnamelen,0);//child pfd;func or macro func//~0723I~
        if (pfdc && UCBITCHK(pfdc->UFDflag,UFDF_DEFINEMAC))        //~0723I~
        {                                                          //~0723I~
            if (!UCBITCHK(pfdc->UFDflag,UFDF_DEFINEVAR))           //~0723I~
            {                                                      //~0723I~
                UCBITON(pfdc->UFDflag,UFDF_DEFINEVAR);  //assume as variable definition macro//~0723I~
                sprintf(namewk,"Assumed %.*s as variable definition macro",//~0723I~
                        len,Pnametop);                             //~0723I~
                errplh2(Pplhs,namewk);                             //~0723I~
            }                                                      //~0723I~
        }                                                          //~0723I~
        else                                                       //~0723I~
        	errplh(Pplhs,"Func-call at out of any function definition");//~0723I~
        return 4;                                                  //~0723I~
    }
    pfc=fcalloc(Pnametop,Pnamelen);
	if (Stestsw)
		printf("func call %s\n",pfc->UFCfnm);
    pfc->UFCplhs=Pplhs;
    pfc->UFCplhe=Pplhe;
    pfc->UFCtop=Pnametop;
    pfc->UFCend=Pcallend;
    pfc->UFCpfdp=pfd;
    if (macrousesw)                                                //~0704I~
    	UCBITON(pfc->UFCflag,UFCF_MACUSE);                         //~0704R~
    pqh=&pfd->UFDqhc;			//child chain
    UENQ(UQUE_END,pqh,pfc);     //enq to func def
    for (plh=Pplhs;plh;plh=UGETQNEXT(plh))
    {
		if (Stestsw)
			printf("     call:%5ld: %.*s\n",plh->ULHlinenor,plh->ULHlen,plh->ULHdata);//~v102R~
        plh->ULHtype=ULHTCALL;
       	UCBITON(plh->ULHflag,ULHFASSIGNED);                        //~0720I~
        if (plh==Pplhe)
        	break;
	}
	return 0;
}//addfunccall                                                     //~0723R~
//**********************************************************************
//* alloc call elem
//**********************************************************************
PUFUNCCALL fcalloc(UCHAR *Pname,int Pnamelen)
{
	PUFUNCCALL pfc;
//*********************
	pfc=UALLOCC(1,(UINT)(UFUNCCALLSZ+Pnamelen));
    if (!pfc)
    	errmalloc("FuncCall Elem");
	pfc->UFCfnl=(UCHAR)Pnamelen;
	memcpy(pfc->UFCfnm,Pname,(UINT)Pnamelen);
	return pfc;
}//fcalloc
//**********************************************************************
//* free unused plh
//**********************************************************************
int freeunused(PUFILEH Ppfh)
{
	PULINEH plh,plhn;
//*********************
    plh=UGETQTOP(&Ppfh->UFHlineque);
    for (;plh;)
    {
    	plhn=UGETQNEXT(plh);
        if (!plh->ULHtype)
        {
			UDEQ(UQUE_ENT,0,plh);
        	filefreeplh(plh,1);
        }
        plh=plhn;
    }
	return 0;
}//freeunused
//**********************************************************************
//* free unused plh
//**********************************************************************
int dropmacroline(PUFILEH Ppfh)
{
	PULINEH plh;
//*********************
    for (plh=UGETQTOP(&Ppfh->UFHlineque);plh;plh=UGETQNEXT(plh))
        if (plh->ULHtype==ULHTMACRO)
        {
            dropmacrolinesub(&plh);
            if (!plh)   //eof
                break;
        }
    return 0;
}//dropmacroline
//**********************************************************************
//* free unused plh
//**********************************************************************
int dropmacrolinesub(PULINEH *Ppplh)
{
	PULINEH plh,plhe,plhs;
    int defcallctr=0,macnest;
//*********************
	plhs=*Ppplh;
	macnest=plhs->ULHmacnest;
    for (plh=UGETQNEXT(plhs);plh;plh=UGETQNEXT(plh))
    {
        if (plh->ULHtype==ULHTMACRO)
        {
        	if (plh->ULHmacnest<macnest)   //#endif
            	break;
        	if (plh->ULHmacnest>macnest)	//new #if
            {
            	defcallctr+=dropmacrolinesub(&plh);
                if (!plh)
                    break;
            }
        }
        else
        if (plh->ULHtype)	//def or call
        	defcallctr++;
    }
    *Ppplh=plh;
    if (defcallctr)
    	return defcallctr;
    plhe=plh;
    for (plh=plhs;plh;plh=UGETQNEXT(plh))
    {
        if (plh->ULHtype==ULHTMACRO)
        	if (!UCBITCHK(plh->ULHflag,ULHFASSIGNED)) //not used-#undef//~0716R~
        		plh->ULHtype=0;                                    //~0716R~
        if (plh==plhe)
        	break;
    }
    return 0;
}//dropmacrolinesub
//**********************************************************************
//* concat macro line to pfd/pfc line
//**********************************************************************
int addmacroline(PUFILEH Ppfh)
{
	PULINEH    plh;                                                //~0720R~
	PUFUNCDEF  pfd;                                                //~0720R~
//  PUFUNCCALL pfc;                                                //~0720R~
    int        macnests,macneste,plhcnt;  //func def macro level   //~0720R~
    int        ifelselevel[2][MAX_PRINT_MACNEST+1],diff,addsw;     //~0720I~
//*********************
    for (pfd=UGETQTOP(&Ppfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))
    {
//search nested macro line BEFORE funcdef                          //~0720R~
        plh=pfd->UFDplhs;                                          //~0720I~
    	macnests=plh->ULHmacnest;  //func def macro level          //~0720R~
        if (macnests)                                              //~0720R~
        {                                                          //~0720I~
//macro search BEFORE                                              //~0720I~
			diff=macnests-MAX_PRINT_MACNEST;                       //~0720I~
            if (diff<0)                                            //~0720I~
            	diff=0;                                            //~0720I~
			memset(ifelselevel,0,sizeof(ifelselevel));             //~0720I~
            for (plhcnt=0;plh=UGETQPREV(plh),plh;)                 //~0720R~
            {                                                      //~0720R~
                if (plh->ULHtype!=ULHTMACRO)                       //~0720R~
                	continue;                                      //~0720I~
                if (plh->ULHmacnest>macnests)                      //~0720I~
                	continue;                                      //~0720I~
                addsw=0;                                           //~0720I~
                switch(plh->ULHmactype)                            //~0720I~
                {                                                  //~0720I~
                case ULHMTIF:                                      //~0720I~
	                if (plh->ULHmacnest<=macnests)                 //~0720I~
                    	if (!ifelselevel[0][plh->ULHmacnest-diff]) //~0720I~
                        {                                          //~0720I~
                    		ifelselevel[0][plh->ULHmacnest-diff]=1;//~0720I~
                    		ifelselevel[1][plh->ULHmacnest-diff]=1;//if detected #if at first//~0720I~
			                if (plh->ULHmacnest==1)                //~0720I~
                            	addsw=2;	//break                //~0720I~
                            else                                   //~0720I~
                            	addsw=1;                           //~0720I~
                        }                                          //~0720I~
                	break;                                         //~0720I~
                case ULHMTELSE:                                    //~0720I~
	                if (plh->ULHmacnest==macnests)                 //~0720I~
                    	if (!ifelselevel[1][plh->ULHmacnest-diff]) //~0720I~
                        {                                          //~0720I~
                    		ifelselevel[1][plh->ULHmacnest-diff]=1;//~0720I~
                            addsw=1;                               //~0720I~
                        }                                          //~0720I~
                	break;                                         //~0720I~
                case ULHMTELIF:                                    //~0720I~
	                if (plh->ULHmacnest==macnests)                 //~0720I~
                    	if (!ifelselevel[1][plh->ULHmacnest-diff]) //~0720I~
                            addsw=1;                               //~0720I~
                	break;                                         //~0720I~
                }                                                  //~0720I~
                if (!addsw)                                        //~0720I~
                	continue;                                      //~0720I~
                UCBITON(plh->ULHflag,ULHFASSIGNED);                //~0720I~
                pfd->UFDmacplhlists[plhcnt++]=plh;                 //~0720R~
                if (addsw==2)                                      //~0720R~
                	break;                                         //~0720I~
                if (plhcnt==MAX_PRINT_MACNEST2)                    //~0720R~
                	break;                                         //~0720I~
            }                                                      //~0720R~
            pfd->UFDmacplhcnts=plhcnt;                             //~0720R~
//macro search AFTER                                               //~0720I~
	        plh=pfd->UFDplhs;                                      //~0720I~
			memset(ifelselevel,0,sizeof(ifelselevel));             //~0720I~
            for (plhcnt=0;plh=UGETQNEXT(plh),plh;)                 //~0720I~
            {                                                      //~0720I~
                if (plh->ULHtype!=ULHTMACRO)                       //~0720I~
                	continue;                                      //~0720I~
                if (plh->ULHmacnest>macnests)                      //~0720I~
                	continue;                                      //~0720I~
                addsw=0;                                           //~0720I~
                switch(plh->ULHmactype)                            //~0720I~
                {                                                  //~0720I~
                case ULHMTENDIF:                                   //~0720I~
	                if (plh->ULHmacnest<macnests)                  //~0720I~
                    	if (!ifelselevel[0][plh->ULHmacnest-diff]) //~0720I~
                        {                                          //~0720I~
                    		ifelselevel[0][plh->ULHmacnest-diff]=1;//~0720I~
                    		ifelselevel[1][plh->ULHmacnest-diff]=1;//if detected #endif at 1st//~0720I~
			                if (plh->ULHmacnest==0)                //~0720I~
                            	addsw=2;	//break                //~0720I~
                            else                                   //~0720I~
                            	addsw=1;                           //~0720I~
                        }                                          //~0720I~
                	break;                                         //~0720I~
                case ULHMTELIF:                                    //~0720R~
	                if (plh->ULHmacnest<=macnests)                 //~0720I~
                    	if (!ifelselevel[1][plh->ULHmacnest-diff]) //~0720I~
                            addsw=1;                               //~0720I~
                	break;                                         //~0720I~
                case ULHMTELSE:                                    //~0720I~
	                if (plh->ULHmacnest<=macnests)                 //~0720I~
                    	if (!ifelselevel[1][plh->ULHmacnest-diff]) //~0720I~
                        {                                          //~0720I~
                    		ifelselevel[1][plh->ULHmacnest-diff]=1;//~0720I~
                            addsw=1;                               //~0720I~
                        }                                          //~0720I~
                	break;                                         //~0720I~
                }                                                  //~0720I~
                if (!addsw)                                        //~0720I~
                	continue;                                      //~0720I~
                UCBITON(plh->ULHflag,ULHFASSIGNED);                //~0720I~
                pfd->UFDmacplhliste[plhcnt++]=plh;                 //~0720I~
                if (addsw==2)                                      //~0720I~
                	break;                                         //~0720I~
                if (plhcnt==MAX_PRINT_MACNEST2)                    //~0720I~
                	break;                                         //~0720I~
            }                                                      //~0720I~
            pfd->UFDmacplhcnte=plhcnt;                             //~0720I~
        }                                                          //~0720I~
//search nested macro line IN funcdef                              //~0720I~
        plh=pfd->UFDplhe;                                          //~0720I~
    	macneste=plh->ULHmacnest;  //func def macro level          //~0720I~
    	if (macneste>macnests)                                     //~0720I~
        {                                                          //~0720I~
            for (;plh=UGETQNEXT(plh),plh;)                         //~0720I~
            {                                                      //~0720I~
                UCBITON(plh->ULHflag,ULHFASSIGNED);                //~0720I~
                if (plh->ULHtype!=ULHTMACRO)                       //~0720I~
                	continue;                                      //~0720I~
                if (plh->ULHmacnest<macneste)                      //~0720I~
                	break;                                         //~0720I~
            }                                                      //~0720I~
            if (plh)                                               //~0720I~
	            pfd->UFDplhe=plh;                                  //~0720I~
        }                                                          //~0720I~
////get def macro of after last func call                          //~0720R~
//        plh=0;  //stop plh                                       //~0720R~
//        if (defmacnest)                                          //~0720R~
//        {                                                        //~0720R~
//            pfc=UGETQEND(&pfd->UFDqhc);                          //~0720R~
//            if (pfc)                                             //~0720R~
//                plh=pfc->UFCplhs;                                //~0720R~
//            else                                                 //~0720R~
//                plh=pfd->UFDplhe;                                //~0720R~
//            for (;plh;plh=UGETQNEXT(plh))                        //~0720R~
//            {                                                    //~0720R~
//                if (plh->ULHtype==ULHTMACRO                      //~0720R~
//                &&  !UCBITCHK(plh->ULHflag,ULHFASSIGNED))        //~0720R~
//                    if (plh->ULHmactype==ULHMTENDIF              //~0720R~
//                    &&  plh->ULHmacnest<defmacnest)              //~0720R~
//                    {                                            //~0720R~
//                        UCBITON(plh->ULHflag,ULHFASSIGNED);      //~0720R~
//                        pfd->UFDlastmacplh=plh;                  //~0720R~
//                        break;                                   //~0720R~
//                    }                                            //~0720R~
//                    else                                         //~0720R~
//                    if  ((plh->ULHmactype==ULHMTELSE || plh->ULHmactype==ULHMTELIF)//~0720R~
//                    &&   plh->ULHmacnest==defmacnest)            //~0720R~
//                        break;                                   //~0720R~
//                    else                                         //~0720R~
//                        break;                                   //~0720R~
//            }                                                    //~0720R~
//        }//macro nest before define                              //~0720R~
//set macro of func call
    }
    addmacrolinefc(Ppfh);                                          //~0720I~
	return 0;
}//addmacroline
//**********************************************************************
//* concat macro line to pfc line(block devided by macro func/funcdef)//~0720R~
//* p2:func define macro nest level
//**********************************************************************
int addmacrolinefc(PUFILEH Ppfh)                                   //~0720R~
{
	PULINEH    plhn,plhp;                                          //~0720I~
	PUFUNCCALL pfc;                                                //~0720I~
	PUFUNCDEF  pfd;                                                //~0720I~
//*********************                                            //~0720I~
    for (pfd=UGETQTOP(&Ppfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))   //~0720I~
    {                                                              //~0720I~
        for (pfc=UGETQTOP(&pfd->UFDqhc);pfc;pfc=UGETQNEXT(pfc))    //~0720R~
        {                                                          //~0720R~
//search prev                                                      //~0720I~
            for (plhp=pfc->UFCplhs;plhn=plhp,plhp=UGETQPREV(plhp),plhp;)//~0720R~
            {                                                      //~0720R~
                if (UCBITCHK(plhp->ULHflag,ULHFASSIGNED))          //~0720R~
                    break;                                         //~0720R~
                UCBITON(plhp->ULHflag,ULHFASSIGNED);               //~0720R~
            }                                                      //~0720R~
            if (plhn)                                              //~0723I~
	            pfc->UFCmacplhs=plhn;                              //~0723R~
            else                                                   //~0723I~
	            pfc->UFCmacplhs=pfc->UFCplhs;                      //~0723I~
//search next                                                      //~0720I~
            plhn=pfc->UFCplhe;                                     //~0720R~
//            macnest=plhn->ULHmacnest;                            //~0720R~
            for (plhn=pfc->UFCplhe;plhp=plhn,plhn=UGETQNEXT(plhn),plhn;)//~0720R~
            {                                                      //~0720R~
                if (UCBITCHK(plhn->ULHflag,ULHFASSIGNED))          //~0720R~
                    break;                                         //~0720R~
//                if (plhn->ULHmacnest>macnest)   //append to next func call//~0720R~
//                    break;                                       //~0720R~
                UCBITON(plhn->ULHflag,ULHFASSIGNED);               //~0720R~
            }                                                      //~0720R~
            if (plhp)                                              //~0723I~
	            pfc->UFCmacplhe=plhp;                              //~0723R~
            else                                                   //~0723I~
	            pfc->UFCmacplhe=pfc->UFCplhe;                      //~0723I~
        }//pfc                                                     //~0720R~
    }//pfd                                                         //~0720I~
	return 0;                                                      //~0720I~
}//addmacrolinefc                                                  //~0720I~
//**********************************************************************
//* set reverse relation
//**********************************************************************
int setchipar(void)
{
	PUFILEH pfh;
	PUFUNCDEF  pfd,duppfd;                                         //~0722R~
    int      ii,procsw,callsw;                                     //~0722R~
//*********************
//ENQ all parent
    for (pfh=UGETQTOP(&Gfilehq);pfh;pfh=UGETQNEXT(pfh))
        for (pfd=UGETQTOP(&pfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))
            setchiparsub(pfd,0);      //child level=1
//set highest(low level number) level
    for (ii=0;;ii++)                //level
    {
    	procsw=0;
    	for (pfh=UGETQTOP(&Gfilehq);pfh;pfh=UGETQNEXT(pfh))
            for (pfd=UGETQTOP(&pfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))
            {
            	callsw=0;                                          //~0722I~
                if (!UCBITCHK(pfd->UFDflag,UFDF_DUPDEF2))	//not dup entry//~0722I~
                {                                                  //+va33I~
                    if (!ii)        //1st level                    //~0722R~
                    {                                              //~0722R~
                        if (!UGETQCTR(&pfd->UFDqhp))               //~0722R~
                            callsw=1;                              //~0722I~
                    }                                              //~0722R~
                    else                                           //~0722R~
                    {                                              //~0722R~
                        if (pfd->UFDlevel==ii)                     //~0722R~
                            callsw=1;                              //~0722I~
                    }                                              //~0722R~
                }                                                  //+va33I~
                if (callsw)                                        //~0722I~
                {                                                  //~0722I~
                	procsw+=setchiparsub(pfd,ii+1);      //child level=1//~0722I~
					duppfd=pfd->UFDdupnamepfd;                     //~0722I~
              		if (duppfd)                                    //~0722I~
                		for (;duppfd;duppfd=duppfd->UFDdupnamepfd) //~0722I~
                        	procsw+=setchiparsub(duppfd,ii+1);      //child level=1//~0722R~
                }                                                  //~0722I~
            }//pfd                                                 //~0722R~
        if (!procsw)
        	break;
    }
    return 0;
}//setchipar
//**********************************************************************
//* set reverse relation for call in a function
//* p1 : parent pfd
//* ret: 0:nop,1:call stmt found
//**********************************************************************
int setchiparsub(PUFUNCDEF Ppfd,int Pchildlevel)
{
	PUFILEH    pfh;                                                //~0709I~
	PULINEH    plhs;                                               //~0709I~
	PUFUNCDEF  pfd;
	PUFUNCCALL pfc;
    PUQUEH   pqh;
    PUQUEE   pqe;
//*********************
//  	if (UCBITCHK(Ppfd->UFDflag,UFDF_PROCESSED))
//      	return 0;
//  	UCBITON(Ppfd->UFDflag,UFDF_PROCESSED);

    for (pfc=UGETQTOP(&Ppfd->UFDqhc);pfc;pfc=UGETQNEXT(pfc))
    {
    	if (Pchildlevel)	//second call
	        pfd=pfc->UFCpfdc;		//called pfd
        else				//1st call
	        pfc->UFCpfdc=pfd=srchpfd(&pfc->UFCfnl,0,0);//ll+name,func or macro func//~0709R~
        if (!pfd)	//only when 1st call                           //~0709R~
        {
			if (Stestsw)
				printf("ext call %.*s\n",pfc->UFCfnl,pfc->UFCfnm);
            UCBITON(pfc->UFCflag,UFCF_EXTERN);
            plhs=pfc->UFCplhs;                                     //~0709I~
            addfuncdef(plhs,pfc->UFCfnm,pfc->UFCplhe,pfc->UFCend,(int)pfc->UFCfnl,0);//~0722R~
            pfh=UGETPFH(plhs);                                     //~0709I~
		    pfd=UGETQEND(&pfh->UFHfuncque);                        //~0709I~
            UCBITON(pfd->UFDflag,UFDF_EXTERN);                     //~0709I~
		    pfc->UFCpfdc=pfd;		//set called pfd               //~0709R~
        }
    	if (Pchildlevel)	//second call
        {
//printf("old=%d,curr=%d,p=%.*s,c=%.*s\n",pfd->UFDlevel,Pchildlevel,//~0722R~
//					Ppfd->UFDfnl,Ppfd->UFDfnm,pfd->UFDfnl,pfd->UFDfnm,pfd->UFDlevel);//~0722R~
            if (!pfd->UFDlevel
            ||  (UINT)pfd->UFDlevel>(UINT)Pchildlevel)
            {                                                      //~0720I~
                pfd->UFDlevel=(UCHAR)Pchildlevel;
				setdupent(pfd);                                    //~0720I~
            }                                                      //~0720I~
        }
        else 				//1st call
        {
        	pqe=&pfc->UFCqerev;
        	pqh=&pfd->UFDqhp;       //parent chain
        	UENQ(UQUE_END,pqh,pqe);
        }
    }
	return 1;
}//setchiparsub
//**********************************************************************//~0720I~
//* set to same name entry                                         //~0720I~
//**********************************************************************//~0720I~
int setdupent(PUFUNCDEF Ppfd)                                      //~0720I~
{                                                                  //~0720I~
	PUFUNCDEF  pfd;                                                //~0720I~
    int level;                                                     //~0720I~
//******************                                               //~0720I~
    level=Ppfd->UFDlevel;                                          //~0720I~
	pfd=Ppfd->UFDdupnamepfd;                                       //~0720I~
    if (!pfd || UCBITCHK(Ppfd->UFDflag,UFDF_DUPDEF2)) //duplicated follower//~0720R~
    	return 0;                                                  //~0720I~
    for (;pfd;pfd=pfd->UFDdupnamepfd)                              //~0720I~
		pfd->UFDlevel=(UCHAR)level;		//copy call level          //~0720R~
    return 1;                                                      //~0720I~
}//setdupent                                                       //~0720I~
//**********************************************************************
//* search funcdef by ll+name  or name and ll                      //~0709R~
//* p1:ll+name when p2=0; or name ptr when p2!=0                   //~0709I~
//* p2:len or 0                                                    //~0709I~
//* p3:1:search macro func or 0:any type                           //~0709I~
//**********************************************************************
PUFUNCDEF srchpfd(UCHAR *Pllname,int Plen,int Ptype)               //~0709R~
{
	PUFILEH    pfh;
	int        lend,lenc;
	PUFUNCDEF  pfd;
    UCHAR     *name;                                               //~0709I~
//*********************
	if (!(lenc=Plen))                                              //~0709I~
    {                                                              //~0709I~
		lenc=(int)*Pllname;                                        //~0709R~
        name=Pllname+1;                                            //~0709I~
    }                                                              //~0709I~
    else                                                           //~0709I~
    	name=Pllname;                                              //~0709R~
    for (pfh=UGETQTOP(&Gfilehq);pfh;pfh=UGETQNEXT(pfh))
        for (pfd=UGETQTOP(&pfh->UFHfuncque);pfd;pfd=UGETQNEXT(pfd))
        {
            lend=(int)pfd->UFDfnl;
//printf("len=%d,%d;%.*s--%.*s\n",lenc,lend,lenc,name,lend,pfd->UFDfnm);//~0709R~
            if (lenc!=lend)
                continue;
            if (!memcmp(pfd->UFDfnm,name,(UINT)lenc))              //~0709R~
            	if (!Ptype	//req any match                        //~0709I~
                ||  UCBITCHK(pfd->UFDflag,UFDF_DEFINEMAC))//search macro//~0709R~
                	return pfd;                                    //~0709R~
        }
    return 0;
}//srchpfd
//**********************************************************************//~v102I~
//* chk funcname to be excluded                                    //~v102I~
//* p1:funcname                                                    //~v102I~
//* p2:nemalen                                                     //~v102I~
//* ret: 1 if to be excluded                                       //~v102I~
//**********************************************************************//~v102I~
int excludefuncchk(char *Pnametop,int Pnamelen)                    //~v102I~
{                                                                  //~v102I~
    int ii;                                                        //~v102I~
//*********************                                            //~v102I~
    for (ii=0;ii<Gexcludefuncno;ii++)	//search exclude list      //~v102I~
    {                                                              //~v102I~
    	if (Pnamelen==(int)strlen(Gexcludefunc[ii])                //~v102R~
        &&  !memcmp(Gexcludefunc[ii],Pnametop,(UINT)Pnamelen))     //~v102R~
            return 1;		//match,func to be ignored             //~v102I~
    }                                                              //~v102I~
	return 0;				//accept this func                     //~v102I~
}//excludefuncchk                                                  //~v102I~
//**********************************************************************
//* search funcdef by ll+name
//**********************************************************************
int errplh(PULINEH Pplh,UCHAR *Pcomm)
{
    UCHAR *pc;                                                     //~0709I~
//*********************
	pc=UGETPFH(Pplh)->UFHfilename;                                 //~0709I~
	pc+=PATHLEN(pc);                                               //~0709R~
    uerrmsg("Error  :%5ld of %-13s:%s\n    -----%.*s\n",0,         //~0715R~
			Pplh->ULHlinenor,pc,Pcomm,                             //~0709R~
			Pplh->ULHlen,Pplh->ULHdata+Pplh->ULHlen+1);            //~0708R~
    Gerrsw=1;
    return 4;
}//errplh
//**********************************************************************
//* search funcdef by ll+name
//**********************************************************************
int errplh2(PULINEH Pplh,UCHAR *Pcomm)
{
    UCHAR *pc;                                                     //~0709I~
//*********************
	pc=UGETPFH(Pplh)->UFHfilename;                                 //~0709I~
	pc+=PATHLEN(pc);                                               //~0709R~
    uerrmsg("Warning:%5ld of %-13s:%s\n    .....%.*s\n",0,         //~0715R~
			Pplh->ULHlinenor,pc,Pcomm,                             //~0709R~
			Pplh->ULHlen,Pplh->ULHdata+Pplh->ULHlen+1);            //~0708R~
    return 4;
}//errplh
