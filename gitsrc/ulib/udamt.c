//CID://+v5i3R~:                                                   //+v5i3R~
//*************************************************************
//*udamt.c  un-asm map table
//*************************************************************
//v5i3:060505 (XDA)add instruction SYSENTER(0f34) and SYSEXIT(0f35)//+v5i3I~
//v320 000603:DISAS:add 0f30(WRMSR),0f31(RDTSC),0f32(RDMSR),0f33(RDPMC)//~v320I~
//v264:990711 disas:(BUG) abend for AAD(D50A) for D50B.maptbl ctr set miss//~v264I~
//v219:990211 disas:allow 82 as Eb,Ib(repack.exe used,err under VC)//~v219I~
//*************************************************************    //~v219I~
#include <stdlib.h>
#include <stdio.h>                                                 //~8C26I~
//*************************************************************
#include <ulib.h>
//********************
#include <uda.h>                                                   //~8C26I~
#include <udasub.h>                                                //~8228R~
#include <udait.h>	//map tble                                     //~8213I~
#include <udamt.h>	//map tble                                     //~8213M~
#include <udaits.h>	//search                                       //~8213I~
#include <udap.h>	//search                                       //~8C26I~
//********************
#ifdef C6                                                          //~8323I~
#undef C6              //for ulib.h                                //~8311I~
#endif                                                             //~8323I~
//*************************************************************

#define  MTGx0_xf(X)	  \
  		 	MAPGEN(X##0),   \
  		 	MAPGEN(X##1),   \
  		 	MAPGEN(X##2),   \
  		 	MAPGEN(X##3),   \
  		 	MAPGEN(X##4),   \
  		 	MAPGEN(X##5),   \
  		 	MAPGEN(X##6),   \
  		 	MAPGEN(X##7),   \
  		 	MAPGEN(X##8),   \
  		 	MAPGEN(X##9),   \
  		 	MAPGEN(X##A),   \
  		 	MAPGEN(X##B),   \
  		 	MAPGEN(X##C),   \
  		 	MAPGEN(X##D),   \
  		 	MAPGEN(X##E),   \
  		 	MAPGEN(X##F)    //define 16 ptr                        //~8213R~

//**2byte op code map gen
#define  MTG0f(X,Y0,Y1,Y2,Y3,Y4,Y5,Y6,Y7,Y8,Y9,YA,YB,YC,YD,YE,YF) \
  		 	MAPGEN(0F##X##Y0),   \
  		 	MAPGEN(0F##X##Y1),   \
  		 	MAPGEN(0F##X##Y2),   \
  		 	MAPGEN(0F##X##Y3),   \
  		 	MAPGEN(0F##X##Y4),   \
  		 	MAPGEN(0F##X##Y5),   \
  		 	MAPGEN(0F##X##Y6),   \
  		 	MAPGEN(0F##X##Y7),   \
  		 	MAPGEN(0F##X##Y8),   \
  		 	MAPGEN(0F##X##Y9),   \
  		 	MAPGEN(0F##X##YA),   \
  		 	MAPGEN(0F##X##YB),   \
  		 	MAPGEN(0F##X##YC),   \
  		 	MAPGEN(0F##X##YD),   \
  		 	MAPGEN(0F##X##YE),   \
  		 	MAPGEN(0F##X##YF)    //define 16 ptr                   //~8213R~
#define Sid_0F0_   Sid_err
#define Sid_0F1_   Sid_err
#define Sid_0F2_   Sid_err
#define Sid_0F3_   Sid_err
#define Sid_0F4_   Sid_err
#define Sid_0F5_   Sid_err
#define Sid_0F6_   Sid_err
#define Sid_0F7_   Sid_err
#define Sid_0F8_   Sid_err
#define Sid_0F9_   Sid_err
#define Sid_0FA_   Sid_err
#define Sid_0FB_   Sid_err
#define Sid_0FC_   Sid_err
#define Sid_0FD_   Sid_err
#define Sid_0FE_   Sid_err
#define Sid_0FF_   Sid_err

//*************************************************************
#include "udaitmn.c"			//instruction MNEMONIC generation
//*************************************************************
#include "udaitrm.c"			//instruction REMARK generation
//*************************************************************
#include "udait.c"		//instruction yable      generation
//*************************************************************
//*************************************************************
//*code table define
//*************************************************************
//*define not defined opcode
//#define  Sid_82         Sid_err                                  //~v219R~
#define  Sid_D6         Sid_err
#define  Sid_F1         Sid_err
static   INSTTBL Sid_err;       //for not defined ope code         //~8213R~
//***************************
//operation code map table
       MAPT Gcodemap[]={                                           //~8213R~
 		MTGx0_xf(0),
 		MTGx0_xf(1),
 		MTGx0_xf(2),
 		MTGx0_xf(3),
 		MTGx0_xf(4),
 		MTGx0_xf(5),
 		MTGx0_xf(6),
 		MTGx0_xf(7),
 		MTGx0_xf(8),
 		MTGx0_xf(9),
 		MTGx0_xf(A),
 		MTGx0_xf(B),
 		MTGx0_xf(C),
 		MTGx0_xf(D),
 		MTGx0_xf(E),
 		MTGx0_xf(F)
          			      };

//2byte opecode map table 0Fxx
       MAPT Gcodemap_2Byte[]={                                     //~8213R~
 		MTG0f(0, 0,1,2,3,_,5,6,_,8,9,_,_,_,_,_,_),                 //~8221R~
 		MTG0f(1, _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_),
 		MTG0f(2, 0,1,2,3,4,_,6,_,_,_,_,_,_,_,_,_),
//  	MTG0f(3, 0,1,2,3,_,_,_,_,_,_,_,_,_,_,_,_),                 //+v5i3R~
    	MTG0f(3, 0,1,2,3,4,5,_,_,_,_,_,_,_,_,_,_),  //add sysenter,sysexit//+v5i3I~
 		MTG0f(4, _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_),
 		MTG0f(5, _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_),
 		MTG0f(6, _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_),
 		MTG0f(7, _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_),
 		MTG0f(8, 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F),
 		MTG0f(9, 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F),
 		MTG0f(A, 0,1,_,3,4,5,_,_,8,9,_,B,C,D,_,F),                 //~8221R~
 		MTG0f(B, 0,1,2,3,4,5,6,7,_,_,A,B,C,D,E,F),                 //~8221R~
 		MTG0f(C, 0,1,_,_,_,_,_,_,8,9,A,B,C,D,E,F),
 		MTG0f(D, _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_),
 		MTG0f(E, _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_),
 		MTG0f(F, _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_)
          			      };
//Group table
#define MG MAPGEN                                                  //~8304R~
//*Grp1
static MAPT Smapt_80[]=                                            //~8213R~
	 {MG(800),MG(801),MG(802),MG(803),MG(804),MG(805),MG(806),MG(807)};//~8304R~
static MAPT Smapt_81[]=                                            //~8213R~
	 {MG(810),MG(811),MG(812),MG(813),MG(814),MG(815),MG(816),MG(817)};//~8304R~
static MAPT Smapt_82[]=                                            //~v219I~
	 {MG(820),MG(821),MG(822),MG(823),MG(824),MG(825),MG(826),MG(827)};//~v219I~
static MAPT Smapt_83[]=                                            //~8213R~
	 {MG(830),MG(831),MG(832),MG(833),MG(834),MG(835),MG(836),MG(837)};//~8304R~
//*Grp2
static MAPT Smapt_C0[]=                                            //~8213R~
	 {MG(C00),MG(C01),MG(C02),MG(C03),MG(C04),MG(C05),0     ,MG(C07)};//~8304R~
static MAPT Smapt_C1[]=                                            //~8213R~
	 {MG(C10),MG(C11),MG(C12),MG(C13),MG(C14),MG(C15),0     ,MG(C17)};//~8304R~
static MAPT Smapt_D0[]=                                            //~8213R~
	 {MG(D00),MG(D01),MG(D02),MG(D03),MG(D04),MG(D05),0     ,MG(D07)};//~8304R~
static MAPT Smapt_D1[]=                                            //~8213R~
	 {MG(D10),MG(D11),MG(D12),MG(D13),MG(D14),MG(D15),0     ,MG(D17)};//~8304R~
static MAPT Smapt_D2[]=                                            //~8213R~
	 {MG(D20),MG(D21),MG(D22),MG(D23),MG(D24),MG(D25),0     ,MG(D27)};//~8304R~
static MAPT Smapt_D3[]=                                            //~8213R~
	 {MG(D30),MG(D31),MG(D32),MG(D33),MG(D34),MG(D35),0     ,MG(D37)};//~8304R~
//*Grp3
static MAPT Smapt_F6[]=                                            //~8213R~
	 {MG(F60),0     ,MG(F62),MG(F63),MG(F64),MG(F65),MG(F66),MG(F67)};//~8304R~
static MAPT Smapt_F7[]=                                            //~8213R~
	 {MG(F70),0     ,MG(F72),MG(F73),MG(F74),MG(F75),MG(F76),MG(F77)};//~8304R~
//*Grp4
static MAPT Smapt_FE[]=                                            //~8213R~
	 {MG(FE0),MG(FE1),0     ,0     ,0     ,0     ,0     ,0     };  //~8304R~
//*Grp5
static MAPT Smapt_FF[]=                                            //~8213R~
	 {MG(FF0),MG(FF1),MG(FF2),MG(FF3),MG(FF4),MG(FF5),MG(FF6),0     };//~8304R~
//*Grp6
static MAPT Smapt_0F00[]=                                          //~8213R~
 {MG(0F000),MG(0F001),MG(0F002),MG(0F003),MG(0F004),MG(0F005),0       ,0       };//~8304R~
//*Grp7                                                            //~8302R~
static MAPT Smapt_0F01[]=                                          //~8213R~
 {MG(0F010),MG(0F011),MG(0F012),MG(0F013),MG(0F014),0       ,MG(0F016),MG(0F017)};//~8304R~
//*Grp8                                                            //~8302R~
static MAPT Smapt_0FBA[]=                                          //~8213R~
 {0       ,0       ,0       ,0       ,MG(0FBA4),MG(0FBA5),MG(0FBA6),MG(0FBA7)};//~8304R~
//*GrpAAM
static MAPT Smapt_AAM[]={MG(D40A)};                                //~8304R~
//*GrpAAD
static MAPT Smapt_AAD[]={MG(D50A)};                                //~8304R~
#undef MG                                                          //~8304R~
//*****************************************************************//~8213I~
//static  GRPT Sgrpt1[]={Smapt_80,Smapt_81,0      ,Smapt_83};      //~v219R~
static  GRPT Sgrpt1[]={Smapt_80,Smapt_81,Smapt_82,Smapt_83};       //~v219I~
static  GRPT Sgrpt2[]=		        //       4,5,6,7,8,9,A,B,C,D,E,F//~8213R~
		{Smapt_C0,Smapt_C1,0       ,0       ,0,0,0,0,0,0,0,0,0,0,0,0,//~8213R~
 		 Smapt_D0,Smapt_D1,Smapt_D2,Smapt_D3};                     //~8213R~
static  GRPT Sgrpt3[]={Smapt_F6,Smapt_F7};                         //~8213R~
static  GRPT Sgrpt4[]={Smapt_FE};                                  //~8213R~
static  GRPT Sgrpt5[]={Smapt_FF};                                  //~8213R~
static  GRPT Sgrpt6[]={Smapt_0F00};                                //~8213R~
static  GRPT Sgrpt7[]={Smapt_0F01};                                //~8213R~
static  GRPT Sgrpt8[]={Smapt_0FBA};                                //~8213R~
//        GRPPT Ggrppt1={Sgrpt1,0x80,sizeof(Sgrpt1)};              //~v264R~
//        GRPPT Ggrppt2={Sgrpt2,0xC0,sizeof(Sgrpt2)};              //~v264R~
//        GRPPT Ggrppt3={Sgrpt3,0xF6,sizeof(Sgrpt3)};              //~v264R~
//        GRPPT Ggrppt4={Sgrpt4,0xFE,sizeof(Sgrpt4)};              //~v264R~
//        GRPPT Ggrppt5={Sgrpt5,0xFF,sizeof(Sgrpt5)};              //~v264R~
//        GRPPT Ggrppt6={Sgrpt6,0x00,sizeof(Sgrpt6)};              //~v264R~
//        GRPPT Ggrppt7={Sgrpt7,0x01,sizeof(Sgrpt7)};              //~v264R~
//        GRPPT Ggrppt8={Sgrpt8,0xBA,sizeof(Sgrpt8)};              //~v264R~
 		GRPPT Ggrppt1={Sgrpt1,0x80,sizeof(Sgrpt1)/sizeof(GRPT)};   //~v264R~
 		GRPPT Ggrppt2={Sgrpt2,0xC0,sizeof(Sgrpt2)/sizeof(GRPT)};   //~v264R~
 		GRPPT Ggrppt3={Sgrpt3,0xF6,sizeof(Sgrpt3)/sizeof(GRPT)};   //~v264R~
 		GRPPT Ggrppt4={Sgrpt4,0xFE,sizeof(Sgrpt4)/sizeof(GRPT)};   //~v264R~
 		GRPPT Ggrppt5={Sgrpt5,0xFF,sizeof(Sgrpt5)/sizeof(GRPT)};   //~v264R~
 		GRPPT Ggrppt6={Sgrpt6,0x00,sizeof(Sgrpt6)/sizeof(GRPT)};   //~v264R~
 		GRPPT Ggrppt7={Sgrpt7,0x01,sizeof(Sgrpt7)/sizeof(GRPT)};   //~v264R~
 		GRPPT Ggrppt8={Sgrpt8,0xBA,sizeof(Sgrpt8)/sizeof(GRPT)};   //~v264R~
                                                                   //~8213I~
//  	MAPPT GmapptAAM={Smapt_AAM,0x0A,sizeof(Smapt_AAM)};        //~v264R~
//  	MAPPT GmapptAAD={Smapt_AAD,0x0A,sizeof(Smapt_AAD)};        //~v264R~
    	MAPPT GmapptAAM={Smapt_AAM,0x0A,sizeof(Smapt_AAM)/sizeof(MAPT)};//~v264I~
    	MAPPT GmapptAAD={Smapt_AAD,0x0A,sizeof(Smapt_AAD)/sizeof(MAPT)};//~v264I~
//*****************************************************************
//*udamt :dummy for LIB
//*parm:none
//*ret :insttbl addr
//*****************************************************************
void udamt(void)
{
//**********************
    return;
}//udamt
