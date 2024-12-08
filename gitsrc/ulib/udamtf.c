//CID://+v213R~:                                                   //+v213I~
//*************************************************************
//*udamt.c  un-asm map table for FPU                               //~8316R~
//*************************************************************
//v213:981226 disas:adcon chk for indirect call/jump               //+v213I~
//*************************************************************    //+v213I~
#include <stdlib.h>
#include <stdio.h>
//*************************************************************
#include <ulib.h>
//********************
#include <uda.h>
#include <udasub.h>
#include <udait.h>
#include <udaitf.h>
#include <udamt.h>
#include <udapf.h>
//*************************************************************
//*************************************************************
#include "udaitmnf.c"			//instruction MNEMONIC generation
//*************************************************************
#include "udaitrmf.c"			//instruction REMARK generation
//*************************************************************
#include "udaitf.c"		//instruction yable      generation
//*************************************************************
#define  MF(x) 	MAPGEN(x)
#define  FPUOP_START     0xD8
//*************************************************************
//*code table define
//*************************************************************
//for /digit(modR/M reg is op code) type
static MAPT Smaptfregop[8][8]={
{MF(D80),MF(D81),MF(D82),MF(D83),MF(D84),MF(D85),MF(D86),MF(D87)},
{MF(D90),0      ,MF(D92),MF(D93),MF(D94),MF(D95),MF(D96),MF(D97)},
{MF(DA0),MF(DA1),MF(DA2),MF(DA3),MF(DA4),MF(DA5),MF(DA6),MF(DA7)},
{MF(DB0),0      ,MF(DB2),MF(DB3),0      ,MF(DB5),0      ,MF(DB7)},
{MF(DC0),MF(DC1),MF(DC2),MF(DC3),MF(DC4),MF(DC5),MF(DC6),MF(DC7)},
{MF(DD0),0      ,MF(DD2),MF(DD3),MF(DD4),0      ,MF(DD6),MF(DD7)},
{MF(DE0),MF(DE1),MF(DE2),MF(DE3),MF(DE4),MF(DE5),MF(DE6),MF(DE7)},
{MF(DF0),0      ,MF(DF2),MF(DF3),MF(DF4),MF(DF5),MF(DF6),MF(DF7)}
          			      };
//for STi type,  2nd opcode =  C0/C8/D0/D8/E0/E8/F0/F8
static MAPT Smaptfsti[8][8]={
{MF(D8C0),MF(D8C8),MF(D8D0),MF(D8D8),MF(D8E0),MF(D8E8),MF(D8F0),MF(D8F8)},
{MF(D9C0),MF(D9C8),0       ,MF(D9D8),0       ,0       ,0       ,0       },//~8404R~
{0       ,0       ,0       ,0       ,0       ,0       ,0       ,0       },//DAxx
{0       ,0       ,0       ,0       ,0       ,0       ,0       ,0       },//DBxx
{MF(DCC0),MF(DCC8),MF(DCD0),MF(DCD8),MF(DCE0),MF(DCE8),MF(DCF0),MF(DCF8)},//~8328R~
{MF(DDC0),0       ,MF(DDD0),MF(DDD8),MF(DDE0),MF(DDE8),0       ,0       },
{MF(DEC0),MF(DEC8),0       ,0       ,MF(DEE0),MF(DEE8),MF(DEF0),MF(DEF8)},//~8404R~
{0       ,0       ,0       ,0       ,0       ,0       ,0       ,0       }//~8404R~
          			      };
//for No operand type opcode =  D9E0-D9FA
static MAPT SmaptfothD9[]={
  		 	MAPGEN(D9D0),                                          //~8323I~
  		 	 0 , //D9D1                                            //~8323I~
  		 	 0 , //D9D2                                            //~8323I~
  		 	 0 , //D9D3                                            //~8323I~
  		 	 0 , //D9D4                                            //~8323I~
  		 	 0 , //D9D5                                            //~8323I~
  		 	 0 , //D9D6                                            //~8323I~
  		 	 0 , //D9D7                                            //~8323I~
  		 	 0 , //D9D8                                            //~8323I~
  		 	 0 , //D9D9                                            //~8323I~
  		 	 0 , //D9DA                                            //~8323I~
  		 	 0 , //D9DB                                            //~8323I~
  		 	 0 , //D9DC                                            //~8323I~
  		 	 0 , //D9DD                                            //~8323I~
  		 	 0 , //D9DE                                            //~8323I~
  		 	 0 , //D9DF                                            //~8323I~
  		 	MAPGEN(D9E0),
  		 	MAPGEN(D9E1),
  		 	 0 ,  //D9E2
  		 	 0 ,  //D9E3
  		 	MAPGEN(D9E4),
  		 	MAPGEN(D9E5),
  		 	 0 ,  //D9E6
  		 	 0 ,  //D9E7
  		 	MAPGEN(D9E8),
  		 	MAPGEN(D9E9),
  		 	MAPGEN(D9EA),
  		 	MAPGEN(D9EB),
  		 	MAPGEN(D9EC),
  		 	MAPGEN(D9ED),
  		 	MAPGEN(D9EE),
  		 	 0 ,  //D9EF

  		 	MAPGEN(D9F0),
  		 	MAPGEN(D9F1),
  		 	MAPGEN(D9F2),
  		 	MAPGEN(D9F3),
  		 	MAPGEN(D9F4),
  		 	MAPGEN(D9F5),
  		 	MAPGEN(D9F6),
  		 	MAPGEN(D9F7),
  		 	MAPGEN(D9F8),
  		 	MAPGEN(D9F9),
  		 	MAPGEN(D9FA),
  		 	MAPGEN(D9FB),
  		 	MAPGEN(D9FC),
  		 	MAPGEN(D9FD),
  		 	MAPGEN(D9FE),
  		 	MAPGEN(D9FF)
          			      };
static MAPT SmaptfothDA[]={
  		 	MAPGEN(DAE9)   //fucompp
          			      };
static MAPT SmaptfothDB[]={
         	MAPGEN(DBE0),      //FNESI                             //~8404R~
  	     	MAPGEN(DBE1),      //FNDISI                            //~8404R~
  		 	MAPGEN(DBE2),      //FNCLEX
  		 	MAPGEN(DBE3),      //FNINIT
  	     	MAPGEN(DBE4)       //FSETPM                            //~8404R~
          			      };
static MAPT SmaptfothDE[]={
  		 	MAPGEN(DED9)       //FCOMPP
          			      };
static MAPT SmaptfothDF[]={                                        //~8323I~
  		 	MAPGEN(DFE0)       //FSTSW AX                          //~8323I~
          			      };                                       //~8323I~
//*ptr to other tbl
static MAPPT Smapptoth[]={
			{0},      //D8,
			{SmaptfothD9,0xD0,sizeof(SmaptfothD9)/sizeof(MAPT)},   //~8323R~
			{SmaptfothDA,0xE9,sizeof(SmaptfothDA)/sizeof(MAPT)},   //~8316R~
			{SmaptfothDB,0xE0,sizeof(SmaptfothDB)/sizeof(MAPT)},   //~8316R~
			{0},      //DC,
			{0},      //DD,
			{SmaptfothDE,0xD9,sizeof(SmaptfothDE)/sizeof(MAPT)},   //~8316R~
			{SmaptfothDF,0xE0,sizeof(SmaptfothDF)/sizeof(MAPT)}    //~8323I~
          			      };
//*****************************************************************
//*uuat :return inst tbl addr
//*parm:none
//*ret :insttbl addr
//*****************************************************************
void  udamtf(void)
{
//**********************
    return;
}//uuat
//*************************************************************
//*****************************************************************
//*udap_Grp_Fpu
//*      search it for FPU
//*parm1:pdar
//*ret  :4 type unmatch for fpu
//*     :8 not def
//*****************************************************************
int udap_GrpFpu(PDAREQ Ppdar)
{
    int  		opcode,opcindx,modregrm,mrindx,reg,mod,rc;
    PINSTTBL 	pit;
	MAPPT      *pmappt;
	MAPT       *pmt;
    UCHAR  *caddr;
    PINSTPROC 	pfunc;                                             //+v213I~
//**********************
	if (rc=udanextbyte(Ppdar,1,1),rc)	//modrm(opcode is already chked)//~8319R~
    	return rc;
    caddr=Ppdar->DARcaddr+Ppdar->DARinstlen-2;	//for wait prefix  //~8319R~
    opcode=(int)*caddr++;
    opcindx=opcode-FPUOP_START;
	modregrm=(int)*caddr++;
    mod=UGETDAMOD(modregrm);
    reg=UGETDAREG(modregrm);    //sub op code
    pit=0;
    if (mod!=3)     //reg is part of ope code
        pit=Smaptfregop[opcindx][reg];
    else
	{
        pmappt=Smapptoth+opcindx;     //fixed code inst tbl
        pmt=pmappt->DAMpmt;
        if (pmt)
        {
        	mrindx=modregrm-pmappt->DAMstart;
        	if (mrindx>=0 && mrindx<pmappt->DAMctr)
            	pit=pmt[mrindx];
        }
        if (!pit)
	        pit=Smaptfsti[opcindx][reg];     //fixed code inst tbl
	}
	Ppdar->DARvpit=pit;
    if (!pit)
    	return DARC_OPCDERR;
  	pfunc=pit->DAIpfunc;                                           //+v213I~
  if (!pfunc)	//group func                                       //+v213I~
	return 0;
    return pfunc(Ppdar);                                           //+v213I~
}//udap_GrpFpu
