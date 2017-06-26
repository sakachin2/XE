//CID://+v213R~:                                                   //+v213I~
//*************************************************************
//*udaits.c  instruction table search
//*************************************************************
//v213:981226 disas:adcon chk for indirect call/jump               //+v213I~
//*************************************************************    //+v213I~
#include <stdlib.h>
#include <stdio.h>                                                 //~8302I~
//*************************************************************
#include <ulib.h>
//********************
#include <uda.h>
#include <udasub.h>                                                //~8302I~
#include <udait.h>	//map tble
#include <udamt.h>	//map tble
#include <udaits.h>                                                //~8302R~
//*************************************************************
int udaitsdigit(PDAREQ Ppdar,GRPPT *Ppgrppt);                      //~8308R~
int udaitsother2Byte(PDAREQ Ppdar,PMAPPT Ppmappt);                 //~8308R~
//*****************************************************************
//*udaits :dummy for LIB
//*parm:none
//*ret :insttbl addr
//*****************************************************************
void udaits(void)
{
//**********************
    return;
}//udamt
//*****************************************************************
//*udaitsrch
//*parm1:pdareq
//*ret  :4 type unmatch for fpu
//*     :8 not def
//*****************************************************************
int udaitsrch(PDAREQ Ppdar)
{
extern  MAPT Gcodemap[];
    int  		pcode,rc;                                          //~8302R~
    PINSTPROC 	pfunc;
    PINSTTBL 	pit;
//**********************
	if (rc=udanextbyte(Ppdar,1,1),rc)	//update inst len          //~8301I~
    	return rc;                                                 //~8301I~
    pcode=(int)(*(Ppdar->DARcaddr+Ppdar->DARinstlen-1));//+1 for wait prefix//~8315R~
    pit=Gcodemap[pcode];
    Ppdar->DARvpit=pit;     //output
    if (!(pit->DAImn))		//pit point to Sid_err,not defined opcode
    	return DARC_OPCDERR;                                       //~8302R~
    pfunc=pit->DAIpfunc;                                           //~8308M~
    if (!pfunc)	//group func                                       //~8308R~
    	return 0;                                                  //~8308R~
    return pfunc(Ppdar);                                           //~8308R~
}//udaitsrch
//*****************************************************************
//*udap_2Byte
//      2 byte opecode search
//*parm1:pdareq
//*ret  :8 not defined
//*****************************************************************
int udap_2Byte(PDAREQ Ppdar)                                       //~8308R~
{
extern  MAPT Gcodemap_2Byte[];
    int  		pcode,rc;                                          //~8302R~
    PINSTPROC 	pfunc;
    PINSTTBL 	pit;
//**********************
	if (rc=udanextbyte(Ppdar,1,1),rc)	//update inst len          //~8301R~
    	return rc;                                                 //~8301R~
    pcode=(int)(*(Ppdar->DARcaddr+1));                             //~8302R~
    pit=Gcodemap_2Byte[pcode];
    Ppdar->DARvpit=pit;     //output
    if (!(pit->DAImn))		//pit point to Sid_err,not defined opcode
    	return DARC_OPCDERR;			//not def                  //~8302R~
    Ppdar->DARstat|=DARS2BYTEOPC;                                  //~8302R~
    pfunc=pit->DAIpfunc;	//more table
    if (!pfunc)	//group func                                       //~8308I~
    	return 0;                                                  //~8308M~
    return pfunc(Ppdar);                                           //~8308R~
}//udap_2Byte
//*****************************************************************
//*udap_Grpxx
//      Group of sub opecode is /n  (n is reg of mod R/M)
//*parm1:pdareq
//*ret  :8 not defined
//*****************************************************************
#define GRPSRCH(GRP)          			 	\
int udap_Grp##GRP(PDAREQ Ppdar) 			\
{                                             			\
    extern GRPPT Ggrppt##GRP;                  			\
/***********************/                     			\
    return udaitsdigit(Ppdar,&Ggrppt##GRP);\
}//udap_Grp##GRP
  GRPSRCH(1)                                                       //~8301R~
  GRPSRCH(2)                                                       //~8301R~
  GRPSRCH(3)                                                       //~8301R~
  GRPSRCH(4)                                                       //~8301R~
  GRPSRCH(5)                                                       //~8301R~
  GRPSRCH(6)                                                       //~8301R~
  GRPSRCH(7)                                                       //~8301R~
  GRPSRCH(8)                                                       //~8301R~
//*****************************************************************//~8302I~
//*udaitsdigit                                                     //~8302I~
//*   /digit type group search                                     //~8302I~
//*parm1:pdareq                                                    //~8302I~
//*parm2:GRPT ptr                                                  //~8308R~
//*ret  :8 not defined                                             //~8302I~
//*****************************************************************//~8302I~
int udaitsdigit(PDAREQ Ppdar,GRPPT *Ppgrppt)                       //~8308R~
{                                                                  //~8302I~
    int 		rc,instlen;                                        //~8304R~
    int 		index;                                             //~8302I~
    int         modrmreg;                                          //~8302I~
    MAPT       *pmt;                                               //~8302I~
    PINSTTBL 	pit;                                               //~8302I~
    PINSTPROC 	pfunc;                                             //+v213I~
//**********************                                           //~8302I~
	instlen=Ppdar->DARinstlen;                                     //~8302I~
    index=(int)*(Ppdar->DARcaddr+instlen-1)-Ppgrppt->DAGstart;     //~8302I~
    if (index<0 || index>=Ppgrppt->DAGctr)                         //~8302I~
        return DARC_OPCDERR;                                       //~8302I~
	pmt=Ppgrppt->DAGpgt[index];                                    //~8302I~
    if (!pmt)       //no grp tbl defined                           //~8302I~
        return DARC_OPCDERR;                                       //~8302I~
	if (rc=udanextbyte(Ppdar,1,0),rc)	//no update inst len       //~8302I~
    	return rc;                                                 //~8302I~
	modrmreg=(int)*(Ppdar->DARcaddr+instlen);                      //~8302I~
    modrmreg=UGETDAREG(modrmreg);                                  //~8302I~
    pit=pmt[modrmreg];                                             //~8302I~
    Ppdar->DARvpit=pit;     //output                               //~8302I~
    if (!pit)				//not defined                          //~8302I~
    	return DARC_OPCDERR;			//not def                  //~8302I~
    Ppdar->DARstat|=DARSREGOPC;                                    //~8302I~
    pfunc=pit->DAIpfunc;	//more table                           //+v213I~
  if (!pfunc)	//group func                                       //+v213I~
    return 0;                                                      //~8302I~
    return pfunc(Ppdar);                                           //+v213I~
}//udaitsdigit                                                     //~8302I~
//*****************************************************************
//*udap_GrpAAM
//*parm1:pdareq
//*ret  :8 not defined
//*****************************************************************
int udap_GrpAAM(PDAREQ Ppdar)                                      //~8308R~
{
 extern  MAPPT   GmapptAAM;
//**********************
    return udaitsother2Byte(Ppdar,&GmapptAAM);                     //~8308R~
}//udap_GrpAAM
//*****************************************************************
//*udap_GrpAAD
//*parm1:pdareq
//*ret  :8 not defined
//*****************************************************************
int udap_GrpAAD(PDAREQ Ppdar)                                      //~8308R~
{
 extern  MAPPT   GmapptAAD;
//**********************
    return udaitsother2Byte(Ppdar,&GmapptAAD);                     //~8308R~
}//udap_GrpAAD
//*****************************************************************//~8302I~
//*udaitsother2Byte                                                //~8302I~
//*   othe 2 byte ope code chk                                     //~8302I~
//*parm1:pdareq                                                    //~8302I~
//*parm2:MAPPT addr                                                //~8308R~
//*ret  :8 not defined                                             //~8302I~
//*****************************************************************//~8302I~
int udaitsother2Byte(PDAREQ Ppdar,PMAPPT Ppmappt)                  //~8308R~
{                                                                  //~8302I~
    int 		index,rc;                                          //~8302I~
    PINSTTBL    pit;                                               //~8302I~
    PINSTPROC 	pfunc;                                             //+v213I~
//**********************                                           //~8302I~
	if (rc=udanextbyte(Ppdar,1,1),rc)	//update inst len          //~8302I~
    	return rc;                                                 //~8302I~
    index=(int)*(Ppdar->DARcaddr+1)-Ppmappt->DAMstart;             //~8302I~
    if (index<0 || index>=Ppmappt->DAMctr)                         //~8302I~
        return DARC_OPCDERR;                                       //~8302I~
	pit=Ppmappt->DAMpmt[index];                                    //~8302I~
    Ppdar->DARvpit=pit;     //output                               //~8302I~
    if (!pit)				//not defined                          //~8302I~
    	return DARC_OPCDERR;			//not def                  //~8302I~
    pfunc=pit->DAIpfunc;	//more table                           //+v213I~
  if (!pfunc)	//group func                                       //+v213I~
    return 0;                                                      //~8302I~
    return pfunc(Ppdar);                                           //+v213I~
}//udaitsother2Byte                                                //~8302I~
