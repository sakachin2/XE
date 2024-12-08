//***********************************************************
//* XIL.c : print ordno inf from import lib                        //~9807R~
//***********************************************************
//**********************************************/
//*
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#if defined(DOS) || defined(W32)
	#include <dos.h>
    #ifdef DPMI
    	#include <errno.h>
    #endif
#else
    #define INCL_DOSFILEMGR  //DCPY_EXISTING
    #include <os2.h>
#endif

//*********************************************************************
#include <ulib.h>
#include <ualloc.h>                                                //~9808R~
#include <uque.h>                                                  //~9808I~
#include <ufile.h>
#include <uerr.h>
#include <udbcschk.h>
#include <uedit.h>
//*********************************************************************
#define VER "V1.0"   //version                                     //~9808R~
#define PGM "XIL"                                                  //~9808I~
//*********************************************************************//~9808I~
                                                                   //~9808I~
#pragma pack(1)    /* Force byte alignment */
//objrec                                                           //~9801I~
typedef struct _OBJREC {                                           //~9807R~
							UCHAR  ORtype;                         //~9807R~
#define ORT_LIBHDR     0xf0          //lib hdr                     //~9807R~
#define ORT_LIBEND     0xf1          //end of object               //~9807I~
                                                                   //~9807I~
#define ORT_THEADR     0x80                                        //~9807R~
#define ORT_LHEADR     0x82                                        //~9807I~
#define ORT_MODEND     0x8a                                        //~9807R~
#define ORT_MODEND386  0x8b                                        //~9807I~
#define ORT_COMENT     0x88                                        //~9807R~
#define ORT_SEGDEF     0x98                                        //~9807R~
#define ORT_SEGDEF386  0x99                                        //~9807I~
                            USHORT ORlen;                          //~9807R~
                        	UCHAR  ORdata[1];                      //~9807R~
#define ORT_COM_IMPEXP 0xa0                 //comment class        //~9807R~
#define ORT_COM_IMPEXP_IMPDEF 0x01			//subtype of comment class of a0//~9807I~
						} OBJREC,*POBJREC;                         //~9807R~
//sort work                                                        //~9808I~
typedef struct _OBJENT {                                           //~9808I~
							UQUEE  OEqe;                           //~9808I~
                            ULONG  OEoffs;                         //~9808I~
                            LONG   OEobjsz;                        //~9808R~
                            USHORT OEordno;                        //~9808I~
							UCHAR  OEtype;                         //~9808I~
#define OET_OBJMOD     0             //no import entry,simple obj  //~9808I~
#define OET_BYORD      2             //import by ordno             //~9808I~
#define OET_BYNAME     3             //import by name              //~9808R~
                        	UCHAR  OEdllnmlen;                     //~9808I~
                        	UCHAR  OEdllnm[9];	//filename for non import entry//~9808I~
                        	UCHAR  OEprocnmlen;                    //~9808I~
                        	UCHAR  OEprocnm[1];                    //~9808I~
						} OBJENT,*POBJENT;                         //~9808I~
#define OBJENTSZ (sizeof(OBJENT))                                  //~9808I~
#pragma pack()
//*********************************************************************
#define BUFFSZ   	1024         //normaly max 1024 byte object record//~9807R~
                                                                   //~9801I~
static UCHAR Sfnm[_MAX_PATH];                                      //~9801R~
static UCHAR *Sbuff;                                               //~9801I~
static FILE *Sfh;                                                  //~9807R~
static int Spgsz;                                                  //~9807R~
static ULONG Sdiroffs=0xffffffff;	//for ist read                 //~9807R~
static ULONG Sfilecpos,Sfilenpos;                                  //~9807R~
//static int Sdbcssw;                                              //~9808R~
static int Ssortsw;                                                //~9808I~
static UQUEH Sqh;                                                  //~9808I~
//*********************************
int mainproc(void);                                                //~9808M~
void help(void);                                                   //~9808I~
POBJREC getobjrec(int Palignopt);                                  //~9807R~
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw);                 //~9801M~
int objread(void *Pbuff);                                          //~9807I~
void logicerr(UCHAR *Pmsg);                                        //~9807I~
void sortout(int Pentno);                                          //~9808I~
int compbyordno(const void *ent1,const void *ent2);                //~9808I~
//*********************************************************************
int main(int parmc,char *parmp[])
{
	int rc,parmno,posparmno=0;                                     //~9808R~
    UCHAR *cptr,c,*pc;                                             //~9808R~
//**********************
	if (parmc<2 || *parmp[1]=='?')                                 //~9808I~
    {
	    help();                                                    //~9808R~
        exit(4);
    }
//*******************************                                  //~9808I~
//* parm process                *                                  //~9808I~
//*******************************                                  //~9808I~
	for (parmno=0;parmno<parmc;parmno++)                           //~9808I~
        printf("%s ",parmp[parmno]);                               //~9808I~
	printf("\n");                                                  //~9808I~
                                                                   //~9808I~
	for (parmno=1;parmno<parmc;parmno++)                           //~9808I~
	{                                                              //~9808I~
  		cptr=parmp[parmno];                                        //~9808I~
  		if(*cptr=='/'||*cptr=='-')                                 //~9808I~
  		{//option                                                  //~9808I~
    		c=*(++cptr);                      //first option byte  //~9808I~
    		switch(toupper(c))             //option                //~9808I~
    		{                                                      //~9808I~
    		case '?':                                              //~9808I~
	    		help();                                            //~9808I~
    			exit(0);                                           //~9808I~
      			break;                                             //~9808I~
    		case 'O':           //sub dir chk                      //~9808I~
      			Ssortsw=1;                                         //~9808I~
                c=*++cptr;                                         //~9808R~
                if (c)                                             //~9808R~
                	if (c=='1')                                    //~9808R~
                    	Ssortsw=2;                                 //~9808I~
                    else                                           //~9808I~
                    	uerrexit("Sort option(%c) err",0,          //~9808I~
                        			c);                            //~9808R~
      			break;                                             //~9808I~
    		case 'Y':                                              //~9808I~
                for (pc=cptr+1;*pc;pc++)                           //~9808I~
                {                                                  //~9808I~
                    switch(toupper(*pc))                           //~9808I~
                    {                                              //~9808I~
                    case '9':                                      //~9808I~
//                      Sdbcssw=1;                                 //~9808R~
                        UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set//~9808I~
                        UCBITON(Guerropt,GBL_UERR_DBCSMODE);//dbcs //~9808I~
                        break;                                     //~9808I~
                    default:                                       //~9808I~
                        uerrexit("Parm(%c) err",0,                 //~9808I~
								*pc);                              //~9808I~
                    }                                              //~9808I~
                }                                                  //~9808I~
                break;                                             //~9808I~
            case 'N':                                              //~9808I~
                for (pc=cptr+1;*pc;pc++)                           //~9808I~
                {                                                  //~9808I~
                    switch(toupper(*pc))                           //~9808I~
                    {                                              //~9808I~
                    case '9':                                      //~9808I~
//                      Sdbcssw=0;                                 //~9808R~
                        UCBITON(Guerropt,GBL_UERR_DBCSSET);     //external set//~9808I~
                        UCBITOFF(Guerropt,GBL_UERR_DBCSMODE);//sbcs//~9808I~
                        break;                                     //~9808I~
                    default:                                       //~9808I~
                        uerrexit("Parm(%c) err",0,                 //~9808I~
								*pc);                              //~9808I~
                    }                                              //~9808I~
                }                                                  //~9808I~
                break;                                             //~9808I~
            default:                           //not option        //~9808I~
                uerrexit("Parm(%s) err",0,                         //~9808I~
								cptr);                             //~9808I~
            }//switch  by first option byte                        //~9808I~
        }                                                          //~9808I~
        else                                                       //~9808I~
        {//positional parmno                                       //~9808I~
            posparmno++;                                           //~9808I~
            switch (posparmno)                                     //~9808I~
            {                                                      //~9808I~
            case  1:          //first parm                         //~9808I~
                strcpy(Sfnm,cptr);                                 //~9808I~
                if (!strchr(Sfnm,'.'))                             //~9808I~
                    strcat(Sfnm,".LIB");                           //~9808I~
                break;                                             //~9808I~
            default:                                               //~9808I~
                uerrexit("Excesive parameter(%s)",0,               //~9808I~
					cptr);                                         //~9808I~
            }//switch by parmno                                    //~9808I~
        }//option or posparm                                       //~9808I~
	}//for all parm                                                //~9808I~
    if (!posparmno)                                                //~9808I~
        uerrexit("Specify lib filename",                           //~9808I~
                    "LIB ファイル名を指定して下さい");             //~9808I~
    rc=mainproc();
	return rc;
}//main

//*********************************************************************//~9808I~
//* help                                                           //~9808I~
//*********************************************************************//~9808I~
void help(void)                                                    //~9808I~
{                                                                  //~9808I~
	uerrmsg("%s:%s:-(%c)- Get Ordinal-No from Lib",                //~9808R~
	        "%s:%s:-(%c)- Lib から オーディナル番号\x95\\示",      //~9808R~
			PGM,VER,OSTYPE);                                       //~9808I~
//  uerrmsg("      %s Lib-FileName [/O[1]]",0);                    //~9808R~//+5529R~
    uerrmsg("      %s Lib-FileName [/O[1]]",0,                     //+5529I~
				PGM);                                              //+5529I~
    uerrmsg("           /O : Output by ordno-sequence",            //~9808R~
//          "           /O : オーディナル番号順出力",              //~9808R~//+5529R~
            "           /O : オーディナル番号順出力");             //+5529I~
//  			PGM);                                              //~9808I~//+5529R~
    uerrmsg("              : 1: output 1 line for each ordno",     //~9808R~
            "              : 1: オーディナル番号につき1行出力");   //~9808R~
    return;                                                        //~9808I~
}//help                                                            //~9808I~
//*********************************************************************
//* process LIB file
//*********************************************************************
int mainproc(void)
{
    POBJREC por;                                                   //~9807R~
    POBJENT poe;                                                   //~9808I~
    LONG    objlen,seglen;                                         //~9807R~
    ULONG   hdroffs;                                               //~9808I~
    USHORT  usordno;                                               //~9808R~
    int     hdrsw,ordflag,impno,rtype,lenpnm,lendnm,lenxnm,importsw,bigbit;//~9807R~
    int     modno,lenfnm;                                          //~9808R~
    UCHAR   *pc,*pprocnm,*pdllnm,llfnm[256];                       //~9807R~
//*****************************
	Sbuff=umalloc(BUFFSZ*2);//processing+read overflow             //~9808R~
    if (!Sbuff)                                                    //~9801R~
    	uerrexit("malloc failed reqsize=%d",0,                     //~9801I~
        		BUFFSZ*3);                                         //~9807R~
	Sfh=openfile(Sfnm,"rb",0);	//exit when open fail              //~9801R~
    por=getobjrec(0);                                              //~9807R~
    if (por->ORtype!=ORT_LIBHDR)                                   //~9807R~
    	uerrexit("%s is not valid LIB file(first byte !=0xF0)",0,  //~9807R~
					Sfnm);                                         //~9801R~
	Spgsz=por->ORlen+3;	//object alignment                         //~9807R~
	Sdiroffs=*(ULONG*)(void*)(por->ORdata);	//end of object data   //~9807R~
	impno=0;                                                       //~9807R~
	modno=0;                                                       //~9807I~
    hdrsw=0;                                                       //~9807I~
    while((por=getobjrec(!hdrsw))!=0)                              //~9807R~
    {
	    rtype=(int)por->ORtype;                                    //~9807I~
        pc=por->ORdata;                                            //~9807I~
        if (rtype==ORT_LIBEND)                                     //~9807I~
            break;              //end of object                    //~9807I~
        if (rtype==ORT_THEADR                                      //~9807I~
        ||  rtype==ORT_LHEADR)                                     //~9807I~
        {                                                          //~9807I~
//      	printf("== %.*s\n",(int)*pc,pc+1);                     //~9807R~
			if (!Ssortsw)                                          //~9808R~
	            printf("==%08lx",Sfilecpos);                       //~9808R~
            hdroffs=Sfilecpos;                                     //~9808I~
        	if (hdrsw)                                             //~9807I~
            	logicerr("Duplicated Header record(0x80/0x82)");   //~9807R~
            hdrsw=1;                                               //~9807I~
            importsw=0;                                            //~9807I~
            objlen=0;                                              //~9807I~
            memcpy(llfnm,pc,(UINT)(*pc+1));                        //~9807R~
		}                                                          //~9807I~
        else                                                       //~9807I~
        {                                                          //~9807I~
        	if (!hdrsw)                                            //~9807I~
            	logicerr("No previous Header record(0x80/0x82)");  //~9807R~
                                                                   //~9807I~
	        switch (rtype)                                         //~9807I~
            {                                                      //~9807I~
            case ORT_MODEND:                                       //~9807I~
            case ORT_MODEND386:                                    //~9807I~
            	if (!importsw)                                     //~9807I~
                {                                                  //~9807I~
                	lenfnm=*llfnm;                                 //~9808R~
                    if (Ssortsw)                                   //~9808I~
                    {                                              //~9808I~
                        poe=ucalloc((UINT)(OBJENTSZ+lenfnm-sizeof(poe->OEdllnm)-1),1);//~9808R~
                        if (!poe)                                  //~9808I~
                            uerrexit("storage shortage",0);        //~9808I~
                        poe->OEoffs=hdroffs;                       //~9808I~
                        poe->OEobjsz=objlen;                       //~9808I~
                        poe->OEtype=OET_OBJMOD;                    //~9808I~
                        poe->OEordno=0;                            //~9808I~
                        poe->OEdllnmlen=(UCHAR)lenfnm;             //~9808I~
                        memcpy(poe->OEdllnm,llfnm+1,(UINT)lenfnm); //~9808R~
                        *(poe->OEdllnm+lenfnm)=0;                  //~9808I~
                                                                   //~9808I~
                        UENQ(UQUE_END,&Sqh,poe);                   //~9808R~
                    }                                              //~9808I~
                    else                                           //~9808I~
                        printf("==! %-32.*s               ",lenfnm,llfnm+1);//~9808R~
                    modno++;                                       //~9807I~
                }                                                  //~9807I~
                else    //import                                   //~9808I~
                    if (Ssortsw)                                   //~9808I~
                    	poe->OEobjsz=objlen;                       //~9808I~
				if (!Ssortsw)                                      //~9808R~
    	            printf("   objsz=x%08lX\n",objlen);	           //~9808R~
	        	hdrsw=0;                                           //~9807I~
                break;                                             //~9807I~
            case ORT_SEGDEF:                                       //~9807I~
            case ORT_SEGDEF386:                                    //~9807I~
            	bigbit=*pc & 0x02;                                 //~9807I~
            	if (!(*pc++ & 0xe0)) //attr fld                    //~9807R~
                	pc+=3;			//skip optional frame#/offset fld//~9807I~
                if (rtype==ORT_SEGDEF)                             //~9807I~
                	if (bigbit)                                    //~9807I~
                    	seglen=0x10000;		//64k                  //~9807I~
                    else                                           //~9807I~
	        			seglen=(long)(*(USHORT*)(void*)pc);        //~9807R~
                else                                               //~9807I~
		        	seglen=*(LONG*)(void*)pc;                      //~9807R~
                objlen+=seglen;                                    //~9807I~
                break;                                             //~9807I~
            case ORT_COMENT:                                       //~9807I~
                if (*++pc==ORT_COM_IMPEXP)   	//comment class    //~9807I~
                	if (*++pc==ORT_COM_IMPEXP_IMPDEF)  //subclass	import define//~9807R~
                    {                                              //~9807I~
		            	impno++;                                   //~9807I~
                    	ordflag=*++pc;			//ordinal flag,0 for import by name//~9807I~
						lenpnm=*++pc;                              //~9807I~
        				pprocnm=++pc;                              //~9807I~
                        pc+=lenpnm;                                //~9807I~
						lendnm=*pc;                                //~9807I~
        				pdllnm=++pc;                               //~9807I~
                        pc+=lendnm;                                //~9807I~
                        usordno=*(USHORT*)(void*)pc;               //~9808I~
                        lenxnm=*pc++;                              //~9808I~
                        if (Ssortsw)                               //~9808I~
                        {                                          //~9808I~
                        	poe=ucalloc((UINT)(OBJENTSZ+lenpnm),1);//~9808R~
                            if (!poe)                              //~9808I~
                            	uerrexit("storage shortage",0);    //~9808I~
                            if (ordflag)                //imp by ordno//~9808I~
                            {	                                   //~9808I~
                            	poe->OEtype=OET_BYORD;             //~9808I~
                            	poe->OEordno=usordno;              //~9808I~
                            }                                      //~9808I~
                            else                                   //~9808I~
                            {                                      //~9808I~
                            	poe->OEtype=OET_BYNAME;            //~9808R~
                            	poe->OEordno=0;                    //~9808I~
                            }                                      //~9808I~
	                        poe->OEoffs=hdroffs;                   //~9808I~
                            lendnm=min(lendnm,sizeof(poe->OEdllnm));//~9808R~
                            poe->OEdllnmlen=(UCHAR)lendnm;         //~9808I~
                            memcpy(poe->OEdllnm,pdllnm,(UINT)lendnm);//~9808R~
                            *(poe->OEdllnm+lendnm)=0;              //~9808I~
                                                                   //~9808I~
                            poe->OEprocnmlen=(UCHAR)lenpnm;        //~9808I~
                            memcpy(poe->OEprocnm,pprocnm,(UINT)lenpnm);//~9808R~
                            *(poe->OEprocnm+lenpnm)=0;             //~9808I~
                                                                   //~9808I~
							UENQ(UQUE_END,&Sqh,poe);               //~9808R~
                        }                                          //~9808I~
                        else                                       //~9808I~
                            if (ordflag)                //imp by ordno//~9808R~
                                printf("==  %-32.*s :%-8.*s.%4d",  //~9808R~
                                        lenpnm,pprocnm,lendnm,pdllnm,(int)usordno);//~9808R~
                            else                    //by name      //~9808R~
                                if (lenxnm)                        //~9808R~
                                    printf("==  %-32.*s :%-8.*s.%.*s",//~9808R~
                                            lenpnm,pprocnm,lendnm,pdllnm,lenxnm,pc);//~9808R~
                                else                               //~9808R~
                                    printf("==  %-32.*s :%-8.*s.*   ",//~9808R~
                                            lenpnm,pprocnm,lendnm,pdllnm);//~9808R~
						importsw=1;                                //~9807I~
                	}//impdef record                               //~9807I~
                	pc++;                                          //~9807R~
            	break;                                             //~9807I~
			}//by record type                                      //~9807I~
		}//not hdr rec                                             //~9807I~
    }//until directory record                                      //~9807R~
	ufree(Sbuff);                                                  //~9808I~
    if (Ssortsw)                                                   //~9808I~
    	sortout(modno+impno);                                      //~9808I~
    printf ("============ total %d module,%d IMPDEF record ===%s:%s(%c)===\n",//~9808R~
				modno,impno,PGM,VER,OSTYPE);                       //~9808I~
    return 0;
}//mainproc
//**********************************************************************//~9808I~
//* get next object record                                         //~9808I~
//* return:objrec ptr                                              //~9808I~
//**********************************************************************//~9808I~
void sortout(int Pentno)                                           //~9808I~
{                                                                  //~9808I~
    POBJENT  poe,poen;                                             //~9808I~
    POBJENT *sptr,*sptr0;                                          //~9808I~
    int      ii,etype,lendnm,lenpnm,dllchng;                       //~9808R~
    UCHAR   *pdllnm,*pprocnm,*pdllnmo="";                          //~9808R~
    USHORT   usord,usordo=0;                                       //~9808R~
    ULONG    hdroffs;                                              //~9808I~
     LONG    objsz;                                                //~9808I~
//****************                                                 //~9808I~
    if (!Pentno)                                                   //~9808I~
        return;                                                    //~9808I~
//sort                                                             //~9808I~
	sptr=sptr0=umalloc((UINT)(Pentno<<2));                         //~9808I~
    for (ii=0,poe=UGETQTOP(&Sqh);ii<Pentno;ii++,poe=UGETQNEXT(poe))//~9808I~
    	*sptr++=poe;                                               //~9808I~
    qsort(sptr0,(UINT)Pentno,4,compbyordno);                       //~9808I~
//list by order                                                    //~9808I~
	sptr=sptr0;                                                    //~9808I~
    for (ii=0,sptr=sptr0;ii<Pentno;ii++,sptr++)                    //~9808I~
    {                                                              //~9808I~
    	poe=*sptr;                                                 //~9808I~
        etype=poe->OEtype;                                         //~9808I~
        usord=poe->OEordno;                                        //~9808I~
        hdroffs=poe->OEoffs;                                       //~9808I~
        lendnm=poe->OEdllnmlen;                                    //~9808I~
        pdllnm=poe->OEdllnm;                                       //~9808I~
        lenpnm=poe->OEprocnmlen;                                   //~9808I~
        pprocnm=poe->OEprocnm;                                     //~9808I~
        objsz=poe->OEobjsz;                                        //~9808I~
        if (Ssortsw==2)     //1line for each ordno                 //~9808I~
            switch (etype)                                         //~9808I~
            {                                                      //~9808I~
            case OET_BYORD:                                        //~9808I~
            	dllchng=stricmp(pdllnm,pdllnmo);                   //~9808I~
            	if (dllchng	|| usordo!=usord)                      //~9808I~
                {                                                  //~9808I~
                    if (dllchng)                                   //~9808I~
                    	printf("\n");                              //~9808I~
	                printf("\n==%08X== (x%08lX) %-8.*s.%4d :%.*s", //~9808I~
    	                    hdroffs,objsz,lendnm,pdllnm,(int)usord,lenpnm,pprocnm);//~9808I~
                }                                                  //~9808I~
				else                                               //~9808I~
	                printf(" , %.*s",                              //~9808I~
    	                    lenpnm,pprocnm);                       //~9808I~
				usordo=usord;                                      //~9808I~
				pdllnmo=pdllnm;                                    //~9808I~
                break;                                             //~9808I~
            case OET_BYNAME:                                       //~9808I~
                printf("==%08X== (x%08lX) %-8.*s.*   :%-32.*s\n",  //~9808I~
                        hdroffs,objsz,lendnm,pdllnm,lenpnm,pprocnm);//~9808I~
                break;                                             //~9808I~
            default:                                               //~9808I~
                printf("==%08X==!(x%08lX) %.*s\n",hdroffs,objsz,lendnm,pdllnm);//~9808R~
                break;                                             //~9808I~
            }                                                      //~9808I~
        else                                                       //~9808I~
            switch (etype)                                         //~9808R~
            {                                                      //~9808R~
            case OET_BYORD:                                        //~9808R~
                printf("==%08X==  %-32.*s :%-8.*s.%4d (x%08lX)\n", //~9808R~
                        hdroffs,lenpnm,pprocnm,lendnm,pdllnm,(int)usord,objsz);//~9808R~
                break;                                             //~9808R~
            case OET_BYNAME:                                       //~9808R~
                printf("==%08X==  %-32.*s :%-8.*s.*    (x%08lX)\n",//~9808R~
                        hdroffs,lenpnm,pprocnm,lendnm,pdllnm,objsz);//~9808R~
                break;                                             //~9808R~
            default:                                               //~9808R~
                printf("==%08X==! %-32.*s :              (x%08lX)\n",hdroffs,lendnm,pdllnm,objsz);//~9808R~
                break;                                             //~9808R~
            }                                                      //~9808R~
    }                                                              //~9808I~
    printf("\n");                                                  //~9808I~
//free entry                                                       //~9808I~
	poen=0;                                                        //~9808I~
    for (poe=UGETQTOP(&Sqh);poe;poe=poen)                          //~9808I~
    {                                                              //~9808I~
    	poen=UGETQNEXT(poe);                                       //~9808I~
        ufree(poe);                                                //~9808I~
    }                                                              //~9808I~
    ufree(sptr0);                                                  //~9808I~
    return;                                                        //~9808I~
}//sortout                                                         //~9808I~
//**********************************************************************//~9808I~
//**********************************************************************//~9808I~
int compbyordno(const void *ent1,const void *ent2)                 //~9808I~
{                                                                  //~9808I~
	POBJENT   poe1,poe2;                                           //~9808I~
    int       rc;                                                  //~9808I~
//*****************                                                //~9808I~
	poe1=*(POBJENT*)ent1;                                          //~9808R~
	poe2=*(POBJENT*)ent2;                                          //~9808R~
    rc=(poe1->OEtype>>1)-(poe2->OEtype>>1); 	//objmod or import //~9808I~
    if (rc)                                                        //~9808I~
    	return rc;                                                 //~9808I~
    rc=stricmp(poe1->OEdllnm,poe2->OEdllnm); //by dllname/filename //~9808I~
    if (poe1->OEtype==OET_OBJMOD)                                  //~9808I~
    	return rc;					//bu filename                  //~9808I~
//by name or by ord(import data)                                   //~9808I~
    if (rc)                                                        //~9808I~
    	return rc;                  //by dllname                   //~9808I~
    if (poe1->OEordno < poe2->OEordno)                             //~9808I~
        return -1;                                                 //~9808I~
    if (poe1->OEordno > poe2->OEordno)                             //~9808I~
        return  1;                                                 //~9808I~
    return strcmp(poe1->OEprocnm,poe2->OEprocnm); //by dllname/filename//~9808R~
}//compbyordno                                                     //~9808I~
//**********************************************************************//~9801I~
//* get next object record                                         //~9807R~
//* return:objrec ptr                                              //~9807R~
//**********************************************************************//~9801I~
POBJREC getobjrec(int Palignopt)                                   //~9807R~
{                                                                  //~9801I~
static int Sreslen,Sprevpos=-1;                                    //~9807I~
    POBJREC  porc;                                                 //~9807R~
    int 	lenc,lenr,lenp,lenw,posc,fillerlen;                    //~9807R~
//****************                                                 //~9801I~
    if (Sprevpos<0)           //1st time                           //~9807I~
        posc=0;                                                    //~9807I~
    else                                                           //~9807I~
    {                                                              //~9807I~
		lenp=((POBJREC)(void*)(Sbuff+Sprevpos))->ORlen+3;	//prev rec len//~9807R~
        if (Palignopt)                                             //~9807I~
        {                                                          //~9807I~
        	fillerlen=(int)(((Sfilecpos+lenp+Spgsz-1)/Spgsz)*Spgsz-Sfilecpos-lenp);//~9807R~
            lenp+=fillerlen;                                       //~9807I~
        	Sreslen-=fillerlen;                                    //~9807R~
        }                                                          //~9807I~
        Sfilecpos+=lenp;                                           //~9807I~
		posc=Sprevpos+lenp;                                        //~9807I~
		porc=(POBJREC)(void*)(Sbuff+posc);		//current  return addr//~9807I~
		lenc=porc->ORlen+3;						//current  len     //~9807I~
	}                                                              //~9807I~
	if (Sreslen<3 	//no more(also when initial)                   //~9807I~
    ||  Sreslen<lenc)                                              //~9807I~
    {                                                              //~9807I~
    	if (Sreslen>0)		//no effect by align                   //~9807I~
        {                                                          //~9807I~
        	memcpy(Sbuff,Sbuff+posc,(UINT)Sreslen);                //~9807R~
	        lenr=objread(Sbuff+Sreslen);                           //~9807R~
            fillerlen=0;                                           //~9807I~
		}                                                          //~9807I~
		else                                                       //~9807I~
        {                                                          //~9807I~
	        lenr=objread(Sbuff);                                   //~9807I~
            fillerlen=-Sreslen;			//residual of alignment    //~9807R~
        }                                                          //~9807I~
        if (!lenr)		//reached to directory                     //~9807I~
        	if (Sreslen)                                           //~9807R~
            	logicerr("reached to directory");                  //~9807I~
            else                                                   //~9807I~
            	return 0;		//normal eof                       //~9807I~
        Sreslen+=lenr;                                             //~9807I~
        if (Sreslen<3)                                             //~9807I~
        	logicerr("short record");                              //~9807I~
		porc=(POBJREC)(void*)Sbuff+fillerlen;		//current rec  //~9807R~
		lenc=porc->ORlen+3;	//current  return addr                 //~9807I~
        if ((lenw=lenc-Sreslen)>0)				//skip long record //~9807I~
        {                                                          //~9807I~
            for (;;)                                               //~9807I~
            {                                                      //~9807I~
                lenr=objread(porc->ORdata);                        //~9807R~
                if (!lenr)                                         //~9807I~
                    logicerr("eof reached for long record");       //~9807I~
                if (lenw<=lenr)                                    //~9807I~
                	break;                                         //~9807I~
                lenw-=lenr;                                        //~9807I~
            }                                                      //~9807I~
            porc->ORlen=(USHORT)lenw;   //only data len            //~9807R~
            lenw+=3;                //hdr and data                 //~9807I~
            Sfilecpos+=lenc-lenw;   //later added by hdr+data      //~9807R~
            lenc=lenw;                                             //~9807R~
            Sreslen=lenr+3;         //readlen-datalen at later     //~9807R~
		}                                                          //~9807I~
	}//not enough                                                  //~9807I~
    Sreslen-=lenc;                                                 //~9807I~
    Sprevpos=(int)((ULONG)porc-(ULONG)Sbuff);                      //~9807R~
    return porc;                                                   //~9807I~
}//getobjrec                                                       //~9807R~
//**********************************************************************//~9801I~
//*read input file                                                 //~9801I~
//* parm1:out area                                                 //~9807R~
//* ret  :read len                                                 //~9801I~
//**********************************************************************//~9801I~
int objread(void *Pbuff)                                           //~9807R~
{                                                                  //~9801I~
	int   readlen;                                                 //~9807R~
//****************                                                 //~9801I~
    if (Sfilenpos>=Sdiroffs)	//reached to dir record            //~9807R~
    	return 0;                                                  //~9807I~
    readlen=(int)fread(Pbuff,1,BUFFSZ,Sfh);	//read 1 block         //~9807R~
//printf("read=%08x,req=%08x\n",readlen,Preqsz);                   //~9801I~
    if (readlen<BUFFSZ)                                            //~9807R~
		if (ferror(Sfh))                                           //~9801R~
        	uerrexit("\n%s read failed rc=%d,pos=%08lx,reqlen=%08lx,read=%08x",0,//~9807R~
						Sfnm,errno,Sfilenpos,BUFFSZ,readlen);      //~9807R~
    Sfilenpos+=readlen;                                            //~9807R~
    if (Sfilenpos>=Sdiroffs)	//reached to dir record            //~9807R~
    	readlen=(int)(Sdiroffs-Sfilecpos);                         //~9807R~
	return readlen;                                                //~9801I~
}//objread                                                         //~9807R~
//**********************************************************************//~9807M~
//* open file name                                                 //~9807M~
//* parm1:open file name                                           //~9807M~
//* parm2:open option                                              //~9807M~
//* parm3:msg sw 0:no opened msg,1:display opened msg,-1:return if open err//~9807M~
//**********************************************************************//~9807M~
FILE *openfile(char *Pfile,char *Popt,int Pmsgsw)                  //~9807M~
{                                                                  //~9807M~
	FILE *file;                                                    //~9807M~
//****************                                                 //~9807M~
	if (!(file=fopen(Pfile,Popt)))                                 //~9807M~
    	if (Pmsgsw==-1)                                            //~9807M~
        	return 0;                                              //~9807M~
        else                                                       //~9807M~
			uerrexit("%s open failed rc=%d",0,                     //~9807M~
					Pfile,errno);                                  //~9807M~
	if (Pmsgsw==1)                                                 //~9807M~
    	printf("%s opened.",Pfile);                                //~9807M~
	return file;                                                   //~9807M~
}//openfile                                                        //~9807M~
//**********************************************************************//~9807I~
//*read input file                                                 //~9807I~
//* parm1:comment err msg                                          //~9807I~
//* ret  :read len                                                 //~9807I~
//**********************************************************************//~9807I~
void logicerr(UCHAR *Pmsg)                                         //~9807I~
{                                                                  //~9807I~
//****************                                                 //~9807I~
    uerrexit("At file offset %08lX: %s",0,                         //~9807I~
    			Sfilecpos,Pmsg);                                   //~9807R~
}//logicerr                                                        //~9807I~
