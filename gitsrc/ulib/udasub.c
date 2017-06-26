//CID://+v6D4R~:        update#=      3     1                      //+v6D4R~
//*************************************************************
//*udasub.c  disassemble sub
//*************************************************************
//v6D4:160427 Win compiler warning                                 //+v6D4I~
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//~v6h7I~
//v5i2:060505 (XDA)insert LineFeed after return and before enter   //~v5i2I~
//v319 000603:DISAS:CREG expanded to CR4                           //~v319I~
//v310 000507:(DISAS)jump direction up/down on remark              //~v310I~
//v284:990912 disas:print remark if reloc data evenif coment level=1//~v284I~
//v274:990808 disas:comment level:jumponly or all                  //~v274I~
//v268:990717 disas:chk also define byte for opcd err              //~v268I~
//v259:990626 disas:0c1 for 1 byte imm value for DOSSEG relloc data//~v259I~
//v255:990626 disas:set 0c1 when recoc is 2nd or 4th byte of imm value//~v255I~
//v239:990508 disas:set abs value for reloc to other object        //~v239I~
//                  when all object base is zero.                  //~v239I~
//v238:990508 disas:(BUG)xda set opdno as start from 1.bug for "e" mode edit//~v238I~
//v225:990228 disas:protect export entry treate as inst data       //~v225I~
//v223:990213 disas:callback func for reloc data proc for each magic//~v223I~
//v220:990212 disas:support indirect branch for also LX/NE         //~v220I~
//v218:990211 disas:reg by modrm is dtermined by opdsz not by adrsz//~v218I~
//v213:981226 disas:adcon chk for indirect call/jump               //~v213I~
//v212:981223 disas:import name display                            //~v212I~
//v210:981223 disas:code addr base support                         //~v210I~
//*************************************************************    //~v210I~
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//*************************************************************
#include <ulib.h>
//********************
#include <uda.h>
#include <udasub.h>	//disas sub
#include <udait.h>	//inst tbl
#include <udaits.h>	//inst tbl
#include <udaimage.h>	//inst tbl                                 //~v213R~
//*************************************************************
#define LABEL_ID '_'                                               //~8321I~
#define CSOVERRIDE  0x2e                                           //~v220I~
//*************************************************************    //~8321I~
//static UCHAR Sbreg[8][2]={"AL","CL","DL","BL","AH","CH","DH","BH"};//+v6D4R~
static UCHAR Sbreg[8][3]={"AL","CL","DL","BL","AH","CH","DH","BH"};//+v6D4I~
//static UCHAR Swreg[8][2]={"AX","CX","DX","BX","SP","BP","SI","DI"};//+v6D4R~
static UCHAR Swreg[8][3]={"AX","CX","DX","BX","SP","BP","SI","DI"};//+v6D4I~
static UCHAR Sereg[8][4]={"EAX","ECX","EDX","EBX","ESP","EBP","ESI","EDI"};//~8308R~
static UCHAR Ssreg[8]={'E','C','S','D','F','G',0,0};//seg reg      //~8315R~
//*************************************************************
int udasetopd(PDAREQ Ppdar);
int udamodrm(PDAREQ Ppdar,int Pregmem,int Pamode32,int Pomode32,int Pmodrm,//~v223R~
					int Popdno,int Popdst,int Popdf,UCHAR *Pout);  //~v223I~
int udasetmrmreg(int Pomode32,int Preg,int Popds,int Popdf,UCHAR *Pout);//~8315R~
void udasetgreg(int Pmode32,int Preg,int Popds,UCHAR *Pout);
int udasetmrmmem(PDAREQ Ppdar,int Pamode32,int Pomode23,int Pmodrm,//~v223R~
					int Popdno,int Popds,int Popdf,UCHAR *Pout);   //~v223R~
int udasetsib(int Pmod,int Psib,UCHAR **Ppout);                    //~8316R~
int udasetimmsub(int Popt,int Pmode,int Popdno,int Popdf,          //~v223R~
		PDAREQ Ppdar,UCHAR *Pdata,int Plen,ULONG *Pbinout,UCHAR **Ppout);//~v212R~
#define IMMS_DROP    0x01       //drop preceding 0                 //~8321R~
#define IMMS_SIGN    0x02       //change sign if minus             //~8321R~
#define IMMS_DISP    0x04       //displacement                     //~8321I~
int udasetopdf(PDAREQ Ppdar);
void udasetregf(int Preg,UCHAR *Pout);
int udasetimm(PDAREQ Ppdar,int Pamode,int Pomode32,                //~v223R~
					int Popdno,int Popdsz,int Popd,UCHAR *Pout);   //~v223I~
void udasetrem(PDAREQ Ppdar,int Pamode,int Pomode);                //~8314R~
//*****************************************************************
//*udasub :dummy for LIB
//*parm:none
//*ret :none
//*****************************************************************
void udasub(void)
{
//**********************
    return;
}//udasub
//*****************************************************************
//*udainst
//* instrunction analysys by inst tbl
//*parm1:pdar
//*ret  :4 type unmatch for fpu
//*     :8  not def
//*****************************************************************
int udainst(PDAREQ Ppdar)
{
    PINSTTBL pit;
    int rc,class,insttype,amode32,omode32,stat,waitsw;             //~8315R~
    UCHAR *opmn,*opmnout;
    DAREQ waitdar;                                                 //~8315I~
    PINSTPROC 	pfunc;                                             //~v213I~
//**********************
	waitsw=(int)(Ppdar->DARstat & DARSWAITP);                      //~8323R~
	Ppdar->DARstat&=DARSSAVEMASK;		//clear except previous prefix effect//~8315I~
	Ppdar->DARdapcaseno=DAPCASE_INIT;				//entry no for dap(subfunc for each inst)//~v225R~
	if (rc=udaitsrch(Ppdar),rc)
    {                                                              //~8315I~
		Ppdar->DARstat&=~DARSSAVEMASK;		//clear previous prefix effect//~8315I~
    	return rc;
    }                                                              //~8315I~
    pit=Ppdar->DARvpit;
    class=(int)pit->DAIclass;
    if (class & ~(Ppdar->DARclass))
    {                                                              //~8315I~
		Ppdar->DARstat&=~DARSSAVEMASK;		//clear previous prefix effect//~8315I~
    	return DARC_TYPEERR;							//out of request type
	}                                                              //~8315I~
    opmnout=Ppdar->DARmn;
    opmn=pit->DAImn;
    insttype=(int)pit->DAIinsttyp;
    amode32=omode32=((Ppdar->DARmode & DAPM32)!=0);                //~8310R~
    stat=(int)Ppdar->DARstat;
//opdsize/addrsize prefix
    if (insttype & DAIIT_PREFIX)
    {
    	if (insttype & DAIIT_ADDRSZ)
        	stat|=DARSASZP;
    	if (insttype & DAIIT_OPDSZ)
        	stat|=DARSOSZP;
		if (*Ppdar->DARcaddr==CSOVERRIDE)                          //~v220I~
        	stat|=DARSCSOVP;                                       //~v220I~
    	if (insttype & DAIIT_WAIT)                                 //~8315M~
        {                                                          //~8315I~
			if (waitsw)		//already wait active                  //~8315R~
                return DARC_OPCDERR;    //not FWAIT                //~8315I~
        	stat|=DARSWAITP;                                       //~8315I~
        }                                                          //~8315I~
	}
    else
    {
//opdsize/addrsize mode chk
        if (stat & DARSASZP) //previous prefix
            amode32^=1;
        if (stat & DARSOSZP) //previous prefix
            omode32^=1;
        if (amode32)
            stat|=DARSA32;
        if (omode32)
            stat|=DARSO32;
        if (stat & DARSCSOVP) //cs override                        //~v220I~
            stat|=DARSCSOV;  	//for indirect addr use inst like as jmp/call//~v220I~
        stat&=~DARSSAVEMASK;	//clear effect of prefix           //~8315R~
    }
    Ppdar->DARstat=(UCHAR)stat;
//*try next is fpu when wait                                       //~8315I~
	if (Ppdar->DARstat & DARSWAITP)	//wait active                  //~8315I~
    {                                                              //~8315I~
    	waitdar=*Ppdar;		//save dar                             //~8315M~
        rc=udainst(Ppdar);	//chk next fpu inst                    //~8315M~
        if (!rc && (Ppdar->DARstat & DARSFWAIT))	//wait combined next fpf//~8315M~
        	return 0;                                              //~8315M~
        *Ppdar=waitdar;		//try next inst at next call;          //~8315M~
	}                                                              //~8315I~
//disas
    if (class & DAIIC_FPU)
    {
	    if (*opmn==DAIMN_CONCAT)   //"\1FNSAVE\0FSAVE" format
    		if (waitsw) 		//wait active st entry             //~8315R~
            {                                                      //~8315I~
                opmn+=(int)strlen(opmn)+1;                         //~8314R~
			    Ppdar->DARstat|=DARSFWAIT;                         //~8315R~
            }                                                      //~8315I~
            else
                opmn++;
	    strcpy(opmnout,opmn);
        rc=udasetopdf(Ppdar);
	}
    else
    {
        if (*opmn==DAIMN_CONCAT)    //mnm vary by opd size
            if (omode32)
                opmn+=(int)strlen(opmn)+1;                         //~8314R~
            else
                opmn++;
	    strcpy(opmnout,opmn);
//printf("mn=%s\n",Ppdar->DARmn);//@@@@                            //~8315R~
        rc=udasetopd(Ppdar);                                       //~8310R~
//printf("mn=%s\n",Ppdar->DARmn);//@@@@                            //~8315R~
    }//not prefix
    if (!rc)                                                       //~v213I~
    	if (Ppdar->DARdapcaseno==DAPCASE_AFTERSETOPD)//callback requested//~v225R~
        {                                                          //~v213I~
			pit=Ppdar->DARvpit;                                    //~v213I~
    		pfunc=pit->DAIpfunc;                                   //~v213I~
		    pfunc(Ppdar);		//recall dap                       //~v213I~
    	}                                                          //~v213I~
	return rc;
}//udainst
//*****************************************************************
//*udasetopd
//*parm1:pdar
//*ret  :none
//*****************************************************************
int udasetopd(PDAREQ Ppdar)
{
    PINSTTBL pit;
	int insttype,stat,amode32,omode32,ii,opdf,opds,opdid,opdtp,rc,modrm=0;//~v6h7R~
    UCHAR *pout,*pc,*caddr;
//************************
    stat=(int)Ppdar->DARstat;
    amode32=stat&DARSA32;
    omode32=stat&DARSO32;
    pit=Ppdar->DARvpit;
    insttype=(int)pit->DAIinsttyp;
	caddr=Ppdar->DARcaddr+Ppdar->DARinstlen;
    if (insttype & DAIIT_MODRM)
    {
	    if (rc=udanextbyte(Ppdar,1,1),rc)   //update inst len
	        return rc;
    	modrm=*caddr++;
	}
    for (ii=0;ii<3;ii++)
    {
        opdf=(int)pit->DAIopdf[ii];
        opds=(int)pit->DAIopdsz[ii];
        pout=Ppdar->DARopd[ii];
        opdid=opdf & DAIOT_fIDMASK;
        opdtp=opdf & DAIOT_fTPMASK;
        if (opdid==DAIOT_NOOPD)
            break;
        switch (opdtp)
        {
        case DAIOT_tMRMREG:
            rc=udamodrm(Ppdar,0,amode32,omode32,modrm,ii+1,opds,opdf,pout);//~v223R~
        	if (rc)                                                //~8315I~
        		return rc;                                         //~8315I~
            break;
        case DAIOT_tMRMMEM:
            rc=udamodrm(Ppdar,1,amode32,omode32,modrm,ii+1,opds,opdf,pout);//~v223R~
        	if (rc)                                                //~8310I~
        		return rc;                                         //~8310I~
            break;
        case DAIOT_tIMMVAL:
            rc=udasetimm(Ppdar,amode32,omode32,ii+1,opds,opdf,pout);//no amode needed//~v223R~
        	if (rc)                                                //~8310I~
        		return rc;                                         //~8310I~
            break;
        default:
            pc=pit->DAIopdstr[ii];//fixed value type
            switch (opdid)
            {
            case DAIOT_FIXED:
                strcpy(pout,pc);  //fixed value
                break;
            case DAIOT_EREG:        //eAX etc
                if (omode32)
                    *pout++='E';
                strcpy(pout,pc+1);
                break;
            }//sw by opdid
        }//sw by opdtp
    }//3 opd
//remarks
    udasetrem(Ppdar,amode32,omode32);                              //~8406R~
    return 0;
}//udasetopd
//*****************************************************************
//*udamodrm
//*parm1:pdar
//*parm2:0:edit reg, 1:edit mem from modrm
//*parm3:addr size mode                                            //~8322R~
//*parm4:opdsz mode                                                //~8322I~
//*parm5:modrm byte                                                //~8322R~
//*parm6:operand number                                            //~v223R~
//*parm7:operand size                                              //~v223I~
//*parm8:operand flag                                              //~v223R~
//*parm9:output area                                               //~v223R~
//*ret  :0:ok,8:not defined(len short,seg reg err)                 //~8315R~
//*****************************************************************
int udamodrm(PDAREQ Ppdar,int Pregmem,int Pamode32,int Pomode32,int Pmodrm,//~v223R~
				int Popdno,int Popds,int Popdf,UCHAR *Pout)        //~v223I~
{
    int rc,mod,reg;                                                //~8322R~
    PINSTTBL pit;                                                  //~8310I~
//******************************
    if (Pregmem)    //memory
    {
    	pit=Ppdar->DARvpit;                                        //~8310I~
    	mod=UGETDAMOD(Pmodrm);
        if (mod==3)
        {
        	if (pit->DAIinsttyp & DAIIT_MEMONLY)                   //~8310R~
            	return DARC_OPCDERR;                               //~8310I~
            Ppdar->DARstat|=DARSREGRM;	//r/m is reg               //~8405I~
            reg=UGETDARM(Pmodrm);
//          udasetgreg(Pamode32,reg,Popds,Pout);//addr size mode   //~v218R~
            udasetgreg(Pomode32,reg,Popds,Pout);//addr size mode   //~v218I~
            rc=0;
        }
        else
        {
        	if (pit->DAIinsttyp & DAIIT_REGONLY)                   //~8310R~
            	return DARC_OPCDERR;                               //~8310I~
            rc=udasetmrmmem(Ppdar,Pamode32,Pomode32,Pmodrm,Popdno,Popds,Popdf,Pout);//~v223R~
        }
    }
    else    //edit reg
    {
        reg=UGETDAREG(Pmodrm);
        rc=udasetmrmreg(Pomode32,reg,Popds,Popdf,Pout);	//opdsize reg//~8322R~
    }
    return rc;
}//udamodrm
//*****************************************************************
//*udasetmrmreg
//*parm1:opd size mode
//*parm2:regno
//*parm3:opdsize
//*parm3:opdflag
//*parm4:out area
//*ret  :rc  8:seg reg err                                         //~8315R~
//*****************************************************************
int udasetmrmreg(int Pomode32,int Preg,int Popds,int Popdf,UCHAR *Pout)//~8315R~
{
	UCHAR *pout;
    int regid;                                                     //~8405R~
                   //  0   1   2   3   4   5   6   7               //~8405I~
//static char Screg[8]={'0', 0 ,'2','3', 0 , 0 , 0 , 0 };  //cr0,2,3//~v319R~
static char Screg[8]={'0', 0 ,'2','3','4', 0 , 0 , 0 };  //cr0,2,3 //~v319I~
static char Sdreg[8]={'0','1','2','3', 0 , 0 ,'6','7'};  //dr0,1,2,3,6,7//~8405I~
static char Streg[8]={ 0 , 0 , 0 ,'3','4','5','6','7'};  //tr3,4,5,6,7//~8405I~
//******************************
	pout=Pout;
	regid=(Popdf & DAIOT_fIDMASK);
	switch(regid)
    {
    case DAIOT_GREG:
		udasetgreg(Pomode32,Preg,Popds,pout);                      //~8314R~
        break;
	case DAIOT_SREG:
        if(!Ssreg[Preg])                                           //~8315R~
        	return DARC_OPCDERR;                                   //~8315I~
        *pout++=Ssreg[Preg];                                       //~8315I~
        *pout++='S';
        *pout++=0;
        break;
	case DAIOT_CREG:		//ctl reg
        if (!Screg[Preg])                                          //~8405I~
            return DARC_OPCDERR;                                   //~8405I~
    	*pout++='C';                                               //~8405I~
    	*pout++='R';                                               //~8405I~
    	*pout++=Screg[Preg];                                       //~8405I~
        *pout++=0;                                                 //~8405I~
        break;                                                     //~8405I~
	case DAIOT_DREG:		//debug reg
        if (!Sdreg[Preg])                                          //~8405I~
            return DARC_OPCDERR;                                   //~8405I~
    	*pout++='D';                                               //~8405I~
    	*pout++='R';                                               //~8405I~
    	*pout++=Sdreg[Preg];                                       //~8405I~
        *pout++=0;                                                 //~8405I~
        break;                                                     //~8405I~
	case DAIOT_TREG:		//test reg
        if (!Streg[Preg])                                          //~8405I~
            return DARC_OPCDERR;                                   //~8405I~
    	*pout++='T';                                               //~8405I~
    	*pout++='R';
    	*pout++=Streg[Preg];                                       //~8405R~
        *pout++=0;
        break;
	}
    return 0;                                                      //~8315R~
}//udasetmrmreg
//*****************************************************************
//*udasetgreg
//*parm1:amode
//*parm2:regno
//*parm3:opdfsize
//*parm4:out area
//*ret  :none
//*****************************************************************
void udasetgreg(int Pmode32,int Preg,int Popds,UCHAR *Pout)
{
	UCHAR *pout;
    int opdsz,hsz;
//******************************
    pout=Pout;
    opdsz=DAIGETLSZ(Popds);
    if (Pmode32)
    {
    	hsz=DAIGETHSZ(Popds);                                      //~8314R~
        if (hsz)
        	opdsz=hsz;
	}
    if (opdsz==4)                                                  //~8314I~
		*pout++='E';                                               //~8314I~
    if (opdsz==1)
    	memcpy(pout,Sbreg[Preg],2);
    else
    	memcpy(pout,Swreg[Preg],2);
    pout+=2;
    *pout=0;
    return;
}//udasetgreg
//*****************************************************************
//*udasetmrmmem
//*parm1:pdar
//*parm2:amode
//*parm3:omode                                                     //~8322I~
//*parm4:modrm                                                     //~8322R~
//*parm5:operand number                                            //~v223R~
//*parm6:operand size attr                                         //~v223I~
//*parm7:operand flag                                              //~v223R~
//*parm8:out area                                                  //~v223R~
//*ret  :0 or 8
//*****************************************************************
int udasetmrmmem(PDAREQ Ppdar,int Pamode32,int Pomode32,int Pmodrm,//~v223R~
					int Popdno,int Popds,int Popdf,UCHAR *Pout)    //~v223I~
{
static UCHAR *Smem16[]={
		"BX+SI","BX+DI","BP+SI","BP+DI","SI","DI","BP","BX"};
//*200:sib, 100:disp only
static UCHAR Sdisptyp16[]={  0,  0,  0,  0,  0,  0,116,  0,
                             8,  8,  8,  8,  8,  8,  8,  8,
                            16, 16, 16, 16, 16, 16, 16, 16};
static UCHAR Sdisptyp32[]={  0,  0,  0,  0,200,132,  0,  0,
                             8,  8,  8,  8,208,  8,  8,  8,
                            32, 32, 32, 32,232, 32, 32, 32};
	int sibsw,instlen,rm,type,basesw,rc,sib=0,immopt,mrm,opdsz;      //~8322R~//~v6h7R~
    UCHAR *pout,*pdisp,*caddr,*pmem,*pout0,*poutdisp=NULL;              //~8314R~//~v6h7R~
    UINT ulen;
//******************************
//opdsz                                                            //~8322I~
    opdsz=DAIGETHSZ(Popds);                                        //~8322I~
    if (!opdsz || !Pomode32)                                       //~8322I~
        opdsz=DAIGETLSZ(Popds);                                    //~8322I~
    Ppdar->DARmemsize=opdsz;		//ptr type output required     //~8322R~
//disp                                                             //~8322I~
    instlen=Ppdar->DARinstlen;
    caddr=Ppdar->DARcaddr+instlen;
    pout=Pout;
    mrm=UGETDAMRM(Pmodrm);                                         //~8316I~
    rm=UGETDARM(Pmodrm);                                           //~8316R~
    if (Pamode32)                                                  //~8310R~
    {
        pmem=Sereg[rm];
        type=Sdisptyp32[mrm];                                      //~8316R~
    }
    else
    {
        pmem=Smem16[rm];
        type=Sdisptyp16[mrm];                                      //~8316R~
    }
    if (type>=200)
    {
    	sibsw=1;
        basesw=0;
        type-=200;
	}
	else
    {
        sibsw=0;
        if (type>=100)
        {
            basesw=0;
            type-=100;
        }
        else
            basesw=1;
    }
    if (sibsw)   //sib exist
    {
        if (rc=udanextbyte(Ppdar,1,1),rc)
            return rc;
        sib=*caddr++;
    }
    type>>=3;		//byte count
    if (rc=udanextbyte(Ppdar,type,2),rc)                           //~8308R~
    	return rc;
//*                                                                //~8310I~
    pdisp=caddr;
    *pout++='[';                                                   //~8310I~
    pout0=pout;		//to chk disp only                             //~8310I~
    if (sibsw)   //sib exist                                       //~8310M~
    {                                                              //~8314I~
                                                                   //~8316I~
    	if (udasetsib(UGETDAMOD(Pmodrm),sib,&pout))                //~8316R~
        {                                                          //~8322I~
        	type=4;					//disp32                       //~8322M~
            if (rc=udanextbyte(Ppdar,type,2),rc)                   //~8322R~
                return rc;                                         //~8322R~
        }                                                          //~8322I~
	}                                                              //~8314I~
    else                                                           //~8310R~
    	if (basesw)		//disp only
	    {
            ulen=strlen(pmem);
            memcpy(pout,pmem,ulen);
            pout+=ulen;
        }
    if (type)                                                      //~8310R~
    {                                                              //~8310R~
        immopt=IMMS_DROP|IMMS_DISP;                                //~8321R~
    	if (pout0!=pout)	//reg used                             //~8316M~
        {                                                          //~8316M~
	        poutdisp=pout;	//for reg used chk                     //~8316I~
	        *pout++='+';                                           //~8316M~
        	immopt|=IMMS_SIGN;   //display minus value             //~8321R~
		}                                                          //~8316M~
        if (udasetimmsub(immopt,Pamode32,Popdno+DAR_RELOCDISP,//5 addr opd 1//~v223R~
				Popdf,Ppdar,pdisp,type,&Ppdar->DARdisp,&pout))//sign changed//~v223I~
        	if (immopt & IMMS_SIGN)   //reg used                   //~8321R~
		        *poutdisp='-';                                     //~8316R~
        if (!basesw && !sibsw)  //no reg,no sib                    //~v212M~
			Ppdar->DARstat|=DARSNOREGSIB;  //no sib and no reg used//~v212R~
    }                                                              //~8310R~
    *pout++=']';                                                   //~8310I~
    return 0;
}//udasetmrmmem
//*****************************************************************
//*udasetsib
//*parm1:mod(00-02)                                                //~8316R~
//*parm2:sib byte                                                  //~8316I~
//*parm3:out area                                                  //~8316R~
//*int  :1:no base EBP(disp32 case)                                //~8314R~
//*****************************************************************
int udasetsib(int Pmod,int Psib,UCHAR **Ppout)                     //~8316R~
{
static UCHAR Sbregf[]={ 0, 1, 2, 3, 4,15, 6, 7};
static UCHAR Sxregf[]={ 0, 1, 2, 3,14, 5, 6, 7};
	int xreg,breg,ss;                                              //~8316R~
    int bregf,xregf,rc;                                            //~8314R~
    UCHAR *pout;
//******************************
    xreg=UGETDAREG(Psib);                                          //~8310R~
    ss=UGETDAMOD(Psib);                                            //~8316R~
    breg=UGETDARM(Psib);                                           //~8310R~
    pout=*Ppout;                                                   //~8310R~
    bregf=(int)Sbregf[breg];                                       //~8310R~
    xregf=(int)Sxregf[xreg];                                       //~8310R~
//base                                                             //~8314I~
    if (!Pmod && bregf>10)		// not (mod=00 && base==5)         //~8316R~
    	rc=1;		//disp32 need                                  //~8314I~
    else                                                           //~8314I~
    {
    	rc=0;                                                      //~8314I~
	    memcpy(pout,Sereg[breg],3);                                //~8310R~
        pout+=3;
	}
//index                                                            //~8314I~
    if (xregf<10)	//index reg defined
    {
    	if (pout!=*Ppout)                                          //~8310I~
		    *pout++='+';                                           //~8310R~
	    memcpy(pout,Sereg[xreg],3);                                //~8310R~
        pout+=3;                                                   //~8314I~
        if (ss)                                                    //~8316R~
        {
        	ss=(1<<ss);                                            //~8316R~
            *pout++='*';
            *pout++=(UCHAR)(ss+'0');                               //~8316R~
        }
    }
    *Ppout=pout;                                                   //~8310I~
    return rc;                                                     //~8314R~
}//udasetsib
//*****************************************************************
//*udasetimm
//*parm1:pdar
//*parm2:amode                                                     //~8316R~
//*parm3:omode                                                     //~8316I~
//*parm4:opdno index                                               //~v223I~
//*parm5:opdsz                                                     //~v223R~
//*parm6:opdflag                                                   //~v223R~
//*parm7:out area                                                  //~v223R~
//*ret  :0 or 8                                                    //~8314R~
//*****************************************************************
int udasetimm(PDAREQ Ppdar,int Pamode32,int Pomode32,              //~v223R~
				int Popdno,int Popds,int Popdf,UCHAR *Pout)        //~v223I~
{
	int opdsz,rc,immopt,rc2,offsetsw,mode32,opdszlh,relosw,opdszo; //~8321R~
    UCHAR *pout,*caddr,*poutsign=NULL;                                  //~8314R~//~v6h7R~
//******************************
	offsetsw=((Popdf & DAIOT_fIDMASK)==DAIOT_OFFS);                //~8315I~
	pout=Pout;
    caddr=Ppdar->DARcaddr+Ppdar->DARinstlen;
    if (Popdf & DAIOT_fADRSZ)       //by addr size opd             //~8316I~
    {                                                              //~8316I~
        mode32=Pamode32;                                           //~8316I~
        opdszlh=DAIOS_BYADRSZ;                                     //~8316I~
    }                                                              //~8316I~
    else                                                           //~8316I~
    {                                                              //~8316I~
        mode32=Pomode32;                                           //~8316I~
        opdszlh=Popds;        //operand size definition on it      //~8316I~
    }                                                              //~8316I~
    if (!mode32 || !(opdsz=DAIGETHSZ(opdszlh)))                    //~8316R~
		opdsz=DAIGETLSZ(opdszlh);                                  //~8316R~
    if (rc=udanextbyte(Ppdar,opdsz,2),rc)                          //~v223R~
    	return rc;
	if (offsetsw)                                                  //~8315I~
    {                                                              //~8321I~
	    if (!Pomode32 || !(opdszo=DAIGETHSZ(Popds)))               //~8321R~
			opdszo=DAIGETLSZ(Popds);                               //~8321R~
        Ppdar->DARmemsize=opdszo;   //ptr type output required     //~8322R~
    	*pout++='[';                                               //~8315I~
	}                                                              //~8321I~
	immopt=((Popdf & DAIOT_fSIGNEXP)!=0)*IMMS_SIGN;                //~8321R~
	relosw=((Popdf & DAIOT_fIDMASK)==DAIOT_RELO);                  //~8321I~
    if (immopt)                                                    //~8321R~
        if (!relosw)                                               //~8321I~
		    poutsign=pout++;                                       //~8321R~
    rc2=udasetimmsub(immopt,mode32,Popdno,Popdf,Ppdar,caddr,opdsz,&Ppdar->DARimmvalue,&pout);	//disp32//~v223R~
    if (immopt)                                                    //~8321R~
        if (!relosw)                                               //~8321I~
            if (rc2)                                               //~8321R~
                *poutsign='-';                                     //~8321R~
            else                                                   //~8321R~
                *poutsign='+';                                     //~8321R~
	if (offsetsw)                                                  //~8315I~
    	*pout++=']';                                               //~8315I~
     return 0;                                                     //~8314R~
}//udasetimm
//*****************************************************************
//*udasetimmsub
//*parm1:option  01:sign change req,02:drop 0 req(with 01 only),04:displacement//~8321R~
//*parm2:mode32                                                    //~v223I~
//*parm3:operandno(4 for displacement)                             //~v223R~
//*parm4:opdf                                                      //~v223R~
//*parm5:pdar                                                      //~v223R~
//*parm6:ulch byte area                                            //~v223R~
//*parm7:length                                                    //~v223R~
//*parm8:output binary area                                        //~v223R~
//*parm9:out area ptr                                              //~v223R~
//*ret  :0:minus not changed,1:minus changed sign                  //~8321R~
//*****************************************************************
int  udasetimmsub(int Popt,int Pmode32,int Popdno,int Popdf,       //~v223R~
				PDAREQ Ppdar,UCHAR *Pdata,int Plen,ULONG *Pbinout,UCHAR **Ppout)//~v212R~
{
    DISAS_CALLBACK *pcbfunc;                                       //~v223I~
	union {ULONG uli[2];                                           //~8321R~
			UCHAR uch[8];                                          //~8321I~
			USHORT usi[4];                                         //~8321I~
			long sli;                                              //~8321I~
			short ssi;                                             //~8321I~
			signed char sch;                                       //~8321I~
			} ulch;                                                //~8321I~
	UCHAR xnote[20],*pout,*pc;                                     //~8321R~
    int ii,len,lowsw,rc=0,expsw,relosw;                            //~8321R~
    int opdid;                                                     //~8321I~
    int rintrosw;                                                  //~v239R~
    UCHAR  *pdata;                                                 //~v223R~
    int cbrc,impsw;                                                //~v223R~
    ULONG  cbparm[3];                                              //~v223R~
//*******************
//printf("immsub before mn=%s(%p)\n",Ppdar->DARmn,Ppdar->DARmn);//@@@@//~8315R~
	memset(&ulch,0,sizeof(ulch));                                  //~v6h7I~
    lowsw=(int)(Ppdar->DARopt & DAPOPLOWADR);                      //~8321I~
	pout=*Ppout;
    pdata=Pdata;                                                   //~v223I~
	ulch.uli[0]=0;                                                 //~8321R~
    for (ii=0;ii<Plen;ii++)
    	ulch.uch[ii]=*pdata++;                                     //~v223R~
    pcbfunc=Ppdar->DARpdap->DAPpcbfunc;                            //~v223I~
    if (pcbfunc)                                                   //~v223I~
    {                                                              //~v223I~
        cbparm[0]=(ULONG)&ulch;                                    //~v223I~
        cbparm[1]=(ULONG)Plen;                                     //~v223I~
        cbparm[2]=(ULONG)Popdno;                                   //~v223I~
        cbrc=pcbfunc(CB_CHKRELOC,Ppdar,Pdata,(ULONG)cbparm);       //~v223R~
    }                                                              //~v223I~
	else                                                           //~v223I~
	    cbrc=0;				//callback func rc                     //~v223I~
	impsw=(cbrc==CB_RCIMPORT);                                     //~v223I~
	rintrosw=(cbrc==CB_RCRINTRO);   //objno set to highword for internal ref//~v239R~
    opdid=Popdf & DAIOT_fIDMASK;                                   //~8321R~
    relosw=(opdid==DAIOT_RELO);                                    //~8321I~
    if (opdid==DAIOT_ADDR)                                         //~8321R~
    {                                                              //~8321I~
	    *Pbinout=ulch.uli[0];                                      //~8321I~
    	if (Pmode32)                                               //~8321I~
        {                                                          //~8321I~
            *(Pbinout+1)=(ULONG)ulch.usi[2];                       //~8321I~
            if (lowsw)                                             //~8321I~
                sprintf(xnote,"%04xh:%08lxh",(UINT)ulch.usi[2],(ULONG)ulch.uli[0]);//~8405R~
            else                                                   //~8321I~
                sprintf(xnote,"%04Xh:%08lXh",(UINT)ulch.usi[2],(ULONG)ulch.uli[0]);//~8405R~
			len=9;	//2nd half len                                 //~8321R~
        }                                                          //~8321I~
        else                                                       //~8321I~
        {                                                          //~8321I~
            if (lowsw)                                             //~8321I~
                sprintf(xnote,"%04xh:%04xh",(UINT)ulch.usi[1],(UINT)ulch.usi[0]);//~8323R~
            else                                                   //~8321R~
                sprintf(xnote,"%04Xh:%04Xh",(UINT)ulch.usi[1],(UINT)ulch.usi[0]);//~8323R~
			len=5;                                                 //~8321R~
		}                                                          //~8321I~
//      if (*xnote>'9')                                            //~v259R~
//      	*pout++='0';                                           //~v259R~
	    memcpy(pout,xnote,6);                                      //~8321R~
        pout+=6;                                                   //~8321R~
//      if (*(xnote+6)>'9')                                        //~v259R~
//      	*pout++='0';                                           //~v259R~
	    memcpy(pout,xnote+6,(UINT)len);                            //~8321I~
        pout+=len;                                                 //~8321I~
	}                                                              //~8321I~
    else		//not direct ptr                                   //~8321I~
    {                                                              //~8321I~
//sign expand                                                      //~8314I~
        expsw=0;                                                   //~8321I~
        if (Popdf & DAIOT_fSIGNEXP)                                //~8321I~
            expsw=1;                                               //~8321I~
        else                                                       //~8321I~
            if (Popt & IMMS_DISP)                                  //~8321I~
                expsw=(Plen<4);                                    //~8321I~
        if (expsw)  //sign expand                                  //~8321R~
        {                                                          //~8321R~
            if (Plen==1)                                           //~8321R~
                ulch.sli=(long)ulch.sch;                           //~8321R~
            else                                                   //~8321R~
                if (Plen==2)                                       //~8321R~
                    ulch.sli=(long)ulch.ssi;                       //~8321R~
        }                                                          //~8321I~
        *Pbinout=ulch.uli[0];                                      //~8321R~
        len=Plen<<1;                                               //~8321I~
        if (relosw)                                                //~8321R~
        {                                                          //~8321I~
		 if (!rintrosw)                                            //~v239R~
		  if (!impsw)                                              //~v223R~
        	Ppdar->DARstat|=DARSJMPRO;	//label required           //~8321I~
        	*pout++=LABEL_ID;                                      //~8321R~
//      	ulch.uli[0]+=(UINT)(Ppdar->DARcaddr)+Ppdar->DARinstlen;//~v210R~
		 if (!rintrosw)                                            //~v239R~
		  if (!impsw)                                              //~v223R~
        	ulch.uli[0]+=(ULONG)(Ppdar->DARcaddr)-Ppdar->DARoffsfrombase+Ppdar->DARinstlen;//~v210I~
            len=8;                                                 //~8321I~
		}                                                          //~8321I~
		else                                                       //~8321I~
            if (Popt & IMMS_SIGN)                                  //~8321R~
                if (ulch.sli<0)                                    //~8321R~
                {                                                  //~8321R~
                    rc=1;                                          //~8321R~
                    ulch.sli=-ulch.sli; //change sign              //~8321R~
                }                                                  //~8321R~
        if (lowsw)                                                 //~8321I~
            sprintf(xnote,"%08lx",ulch.uli[0]);                    //~8321I~
        else                                                       //~8321I~
            sprintf(xnote,"%08lX",ulch.uli[0]);                    //~8321I~
        pc=xnote+8-len;                                            //~8321I~
        if (!relosw)                                               //~8321I~
        {                                                          //~8321I~
		  if (!rintrosw)                                           //~v239I~
            if (expsw || (Popt & IMMS_DROP))//expand or drop 0 req //~8321R~
            {                                                      //~8321R~
                for (;*pc;pc++,len--)                              //~8321R~
                    if (*pc!='0')                                  //~8321R~
                        break;                                     //~8321R~
                if (!len)                                          //~8401R~
                {                                                  //~8321R~
                    len=2;                                         //~8401R~
                    pc-=2;                                         //~8401R~
                }                                                  //~8321R~
                else                                               //~8401I~
                    if (len%2)                                     //~8401I~
                    {                                              //~8401I~
                        len++;                                     //~8401I~
                        pc--;                                      //~8401I~
                    }                                              //~8401I~
            }                                                      //~8321R~
//          if (*pc>'9')    //hex                                  //~v259R~
//              *pout++='0';                                       //~v259R~
		}                                                          //~8321I~
	    memcpy(pout,pc,(UINT)len);                                 //~8321I~
        pout+=len;                                                 //~8321I~
        if (!relosw)                                               //~8321R~
	        *pout++='h';                                           //~8321R~
	}//not direct ptr                                              //~8321R~
    *Ppout=pout;                                                   //~8321R~
//printf("immsub before mn=%s\n",Ppdar->DARmn);//@@@@              //~8315R~
    return rc;                                                     //~8314R~
}//udasetimmsub
//*****************************************************************
//*udasetopdf
//*parm1:pdar
//*ret  :rc
//*****************************************************************
int udasetopdf(PDAREQ Ppdar)
{
    PINSTTBL pit;
    UCHAR *pout;                                                   //~8319R~
    int  opdf,opds,rc;
    int modrm,reg,ii,opdid;                                        //~8316R~
//******************************
    pit=Ppdar->DARvpit;
	modrm=*(Ppdar->DARcaddr+Ppdar->DARinstlen-1);	//2 byte already set//~8319R~
//*opd1***
    for (ii=0;ii<2;ii++)
    {
        opdf=(int)pit->DAIopdf[ii];
        opds=(int)pit->DAIopdsz[ii];
        pout=Ppdar->DARopd[ii];
        opdid=opdf & DAIOT_fIDMASK;
        if (opdid==DAIOT_NOOPD)                                    //~8314I~
        	break;                                                 //~8314I~
        switch(opdid)
        {
        case DAIOT_FIXED:
            strcpy(pout,pit->DAIopdstr[ii]);	//fixed value
            break;
        case DAIOT_MEM:
            if (rc=udasetmrmmem(Ppdar,(int)Ppdar->DARstat&DARSA32,(int)Ppdar->DARstat&DARSO32,//~8322R~
								modrm,ii+1,opds,opdf,pout),rc)//no amode needed//~v223R~
            	return rc;
            break;
        case DAIOT_FPSTi:
            reg=UGETDARM(modrm);                                   //~8314I~
            udasetregf(reg,pout);
            break;
        }
    }//1,2
//remarks                                                          //~8314I~
    udasetrem(Ppdar,1,1);   //no mode32 effective                  //~8406R~
    return 0;
}//udasetopdf
//*****************************************************************
//*udasetregf
//*parm1:regno
//*parm2:out area
//*ret  :none
//*****************************************************************
void udasetregf(int Preg,UCHAR *Pout)
{
//******************************
    memcpy(Pout,"ST",2);
    Pout+=2;
    if (Preg)
    {                                                              //~8314I~
    	*Pout++='(';                                               //~8314R~
    	*Pout++=(UCHAR)('0'+Preg);                                 //~8314I~
    	*Pout++=')';                                               //~8314I~
	}                                                              //~8314I~
	*Pout=0;
    return;
}//udasetregf
//*****************************************************************
//*udasetrem
//*parm1:pdar
//*parm2:addr    size mode                                         //~8314R~
//*parm3:operand size mode                                         //~8314I~
//*ret  :none
//*****************************************************************
void udasetrem(PDAREQ Ppdar,int Pamode,int Pomode)                 //~8314R~
{
	PINSTTBL pit;
    PDAPARM  pdap;			//dap addr                             //~v274I~
	UCHAR    *prem,*popd,*pc,*pout,type,*addr,*updown;             //~v310R~
	UCHAR    *flens,relrem[sizeof(Ppdar->DARrem)];                 //~v223R~
    int opdsz,opno;                                                //~v223R~
    UINT     ulen;
    ULONG    offs;                                                 //~v223I~
    int      relopdno;                                             //~v223I~
//******************************
    if (Ppdar->DARopt2 & DAROPT2PH1)	//phase1                   //~8406I~
    	return;                                                    //~8406I~
	pit=Ppdar->DARvpit;
	pdap=Ppdar->DARpdap;                                           //~v274I~
    prem=pit->DAIrem;
    popd=Ppdar->DARopd[0];
    pout=Ppdar->DARrem;
    relopdno=Ppdar->DARrelocopdno;  //remark edit import for reloc data//~v223R~
    memcpy(relrem,pout,sizeof(relrem));       //may set reloc data //~v223I~
    type=*prem++;
                                                                   //~v5i2I~
    if (*prem==DAIRT_LF1)    //line feed before the line           //~v5i2I~
    {                                                              //~v5i2M~
    	prem++;                                                    //~v5i2M~
        Ppdar->DARstat2|=DARS2LF1;                                 //~v5i2M~
    }                                                              //~v5i2M~
    else                                                           //~v5i2I~
    if (*prem==DAIRT_LF2)    //line feed before the line           //~v5i2I~
    {                                                              //~v5i2I~
    	prem++;                                                    //~v5i2I~
        Ppdar->DARstat2|=DARS2LF2;                                 //~v5i2I~
    }                                                              //~v5i2I~
                                                                   //~v5i2I~
    if (*prem==DAIRT_CONCAT)
    	if (Pomode)                                                //~8314R~
        	prem+=strlen(prem)+1;
        else                                                       //~8331I~
            prem++;                                                //~8331I~
    if (*prem==DAIRT_CMLVL1)    //comment level=1                  //~v274I~
     	prem++;                                                    //~v274I~
    else                                                           //~v274I~
    	if (pdap->DAPopt & DAPOPCMLVL1)                            //~v274I~
        if (!relopdno)	//no reloc data                            //~v284I~
        {                                                          //~v274I~
            *pout=0;                                               //~v274I~
            return;                                                //~v274I~
        }                                                          //~v274I~
                                                                   //~v274I~
    switch(type)
    {
    case DAIRT_CONST:
    	strcpy(pout,prem);
        break;
    case DAIRT_RUNARY:		//unary from right(opd,op)
	  if (relopdno)                                                //~v223I~
    	strcpy(pout,relrem);	//preset relocation remark         //~v223I~
  	  else                                                         //~v223I~
    	strcpy(pout,popd);
    	strcat(pout,prem);
        break;
    case DAIRT_LUNARY:		//unary from left (op,opd)
    	strcpy(pout,prem);
	  if (relopdno)                                                //~v223I~
    	strcat(pout,relrem);	//preset relocation remark         //~v223I~
  	  else                                                         //~v223I~
    	strcat(pout,popd);
        break;
    case DAIRT_BINARY:		//unary from left (op,opd)
	  if (relopdno==1)          //opd 1 is reloc data              //~v223I~
    	strcpy(pout,relrem);	//preset relocation remark         //~v223I~
  	  else                                                         //~v223I~
    	strcpy(pout,popd);
    	strcat(pout,prem);
	  if (relopdno==2)          //opd 2 is reloc data              //~v223I~
    	strcat(pout,relrem);	//preset relocation remark         //~v223I~
  	  else                                                         //~v223I~
    	strcat(pout,Ppdar->DARopd[1]);
        break;
    case DAIRT_EDIT:		//unary from left (op,opd)
    	while(*prem)
        {
            if (!(pc=strchr(prem,'%')))
            	break;
            ulen=(ULONG)pc-(ULONG)prem;
            memcpy(pout,prem,ulen);
            pout+=ulen;
            pc++;
            prem=pc+1;    //next search start
            switch(*pc)
            {
            case '1':
            case '2':
            case '3':
                opno=*pc-'1';                                      //~8405R~
//  	  	  if (relopdno==opno)    //opd  is reloc data          //~v238R~
    	  	  if (relopdno==opno+1)    //opd  is reloc data        //~v238I~
    			popd=relrem;	//preset relocation remark         //~v223I~
              else                                                 //~v223I~
                popd=Ppdar->DARopd[opno];                          //~8405I~
                ulen=strlen(popd);
                memcpy(pout,popd,ulen);
                pout+=ulen;
                if (*prem=='%' && *(prem+1)=='w') //%w             //~8405R~
                {                                                  //~8405I~
                    if (!(Ppdar->DARstat & DARSREGRM)  //r/m is mem//~8405I~
                    &&   (pit->DAIopdf[opno] & DAIOT_fTPMASK)==DAIOT_tMRMMEM)//~v212R~
                    {                                              //~8405I~
                        opdsz=Ppdar->DARmemsize;                   //~8406R~
                        *pout++='(';                               //~8405I~
                        *pout++=(UCHAR)('0'+opdsz);                //~8405I~
                        *pout++=')';                               //~8405I~
                    }//r/m is mem                                  //~8405I~
                    prem+=2;    //skip %w                          //~8405I~
                }                                                  //~8405I~
                break;
            case 'e':          //by opd size   %e                  //~8406R~
            	if (Pomode)                                        //~8314R~
                	*pout++='E';
                break;
            case 'E':          //by addr size   %E                 //~8406R~
            	if (Pamode)                                        //~8314I~
                	*pout++='E';                                   //~8314I~
                break;                                             //~8314I~
            case 'x':                        // %x                 //~8406R~
            	if (Pomode)                                        //~8331I~
                	*pout++='X';                                   //~8331M~
                else
                	*pout++='L';                                   //~8331M~
                break;
            case 'l':                       //%l                   //~8406R~
            	if (Pomode)                                        //~8314R~
                	*pout++='4';
                else
                	*pout++='2';
                break;
            case 'j':			//jump addr %j                     //~8406R~
		  	 if (relopdno)    //opd  is reloc data                 //~v223M~
             {                                                     //~v223M~
                ulen=strlen(relrem);                               //~v223M~
                memcpy(pout,relrem,ulen);                          //~v223M~
                pout+=ulen;                                        //~v223M~
             }                                                     //~v223M~
             else                                                  //~v223M~
             {                                                     //~v223M~
                offs=Ppdar->DARimmvalue;                           //~v223R~
	          if (Ppdar->DARstat & DARSJMPRO)	//label required   //~v223I~
              {                                                    //~v310I~
                addr=Ppdar->DARcaddr+Ppdar->DARinstlen+offs        //~v210R~
        	           -Ppdar->DARoffsfrombase;                    //~v210I~
                if ((LONG)offs<0)                                  //~v310I~
                	updown="^";                                    //~v310I~
                else                                               //~v310I~
                	updown="v";                                    //~v310I~
              }                                                    //~v310I~
			  else                                                 //~v223I~
              {                                                    //~v310I~
                addr=(UCHAR*)offs;                                 //~v223R~
                updown="";                                         //~v310I~
              }                                                    //~v310I~
                if (Ppdar->DARopt & DAPOPLOWADR)                   //~8314R~
                    sprintf(pout,"%s %08lx",updown,(ULONG)addr);   //~v310R~
                else                                               //~8314I~
                    sprintf(pout,"%s %08lX",updown,(ULONG)addr);   //~v310R~
                pout+=8;                                           //~8314I~
              }                                                    //~v223I~
                break;                                             //~8314I~
    		case 'd':       //dll search                           //~v212I~
//  			udasetimportPE(Ppdar,&pout);                       //~v223R~
			  	if (relopdno)    //opd  is reloc data              //~v223I~
	    			popd=relrem;	//preset relocation remark     //~v223I~
                ulen=strlen(popd);                                 //~v223I~
                memcpy(pout,popd,ulen);                            //~v223I~
                pout+=ulen;                                        //~v223I~
        		break;                                             //~v212I~
    		case 'n':       //STi   %n                             //~8404R~
    			*pout++=Ppdar->DARopd[0][3];                       //~8404R~
        		break;                                             //~8404I~
    		case 'r':       //real for fpu  %r                     //~8404I~
    		case 'i':       //int  for fpu  %i                     //~8404I~
                if ((pit->DAIopdf[0] & DAIOT_fTPMASK)==DAIOT_tMRMMEM)//~v212R~
                {                                                  //~8404I~
                    opdsz=Ppdar->DARmemsize;                       //~8406I~
                    flens=0;                                       //~8404I~
                    switch (opdsz)                                 //~8404I~
                    {                                              //~8404I~
                    case 2:                                        //~8404I~
                    	flens="16";	                               //~8404I~
						break;                                     //~8404I~
                    case 4:                                        //~8404I~
                    	flens="32";                                //~8404I~
						break;                                     //~8404I~
                    case 8:                                        //~8404I~
                    	flens="64";                                //~8404I~
						break;                                     //~8404I~
                    case 10:                                       //~8404I~
                    	flens="80";                                //~8404I~
						break;                                     //~8404I~
                    }                                              //~8404I~
                    if (flens)                                     //~8404I~
                    {                                              //~8404I~
	    				*pout++='(';                               //~8404I~
    					*pout++=*pc;    // r or i                  //~8404I~
                        memcpy(pout,flens,2);                      //~8404I~
                        pout+=2;                                   //~8404I~
    					*pout++=')';                               //~8404I~
                    }                                              //~8404I~
                }                                                  //~8404I~
        		break;                                             //~8404I~
    		case '%':                                              //~8316I~
    			*pout++='%';                                       //~8316I~
        		break;                                             //~8316I~
            }
		}//until rem string last
        if (*prem)
        {
        	ulen=strlen(prem);
            memcpy(pout,prem,ulen);                                //~8314R~
            pout+=ulen;
        }
        break;
    default:		//unary from left (op,opd)
        *pout=0;
    }
    return;
}//udasetrem
//*****************************************************************//~8310M~
//*udanextbyte                                                     //~8310M~
//* chk last and update instlen                                    //~8310M~
//*   if opt!=2(sub opecode,modrm,sib byte;chk it is not reloc data)//~v223I~
//*parm1:pdar                                                      //~8310M~
//*parm2:byte count                                                //~8310M~
//*parm3:option 0:no istlen update,1:instlen update,2:1 and immlen update//~8310M~
//*ret  :8 			no data                                        //~8310M~
//*****************************************************************//~8310M~
int udanextbyte(PDAREQ Ppdar,int Pbytecnt,int Popt)                //~8310M~
{                                                                  //~8310M~
	int instlen,instlen0;                                          //~8310M~
    UCHAR *plabt;                                                  //~v225I~
//*******************                                              //~8310M~
	instlen0=Ppdar->DARinstlen;                                    //~8310M~
	instlen=instlen0+Pbytecnt;                                     //~8310M~
	if (Ppdar->DARcaddr+instlen>Ppdar->DAReaddr)                   //~8310I~
		return DARC_OPCDERR;                                       //~8310M~
    if (Popt)                                                      //~8310M~
		Ppdar->DARinstlen=instlen;                                 //~8310M~
    if (plabt=Ppdar->DARplabt,plabt)                               //~v225I~
    	plabt+=Ppdar->DARoffs+instlen0;                            //~v225I~
                                                                   //~v225I~
    if (instlen0)	//not instruction top                          //~v225I~
//  	if (plabt && (*plabt & LABT_ENTRY))                        //~v268R~
    	if (plabt)                                                 //~v268I~
		  if ((*plabt & LABT_ENTRY)                                //~v268I~
		  ||  ((*plabt & LABT_TYPEMASK)==LABT_DB))//DB             //~v268I~
			return DARC_OPCDERR;                                   //~v225I~
                                                                   //~v225I~
    if (Popt==2)                                                   //~v223R~
    {                                                              //~8310M~
    	if (!Ppdar->DARdumplen[0])                                 //~8310M~
    		Ppdar->DARdumplen[0]=instlen0;                         //~8310M~
        if (Ppdar->DARdumplen[1])                                  //~8310M~
			Ppdar->DARdumplen[2]=Pbytecnt;	//immed                //~8310M~
        else                                                       //~8310M~
			Ppdar->DARdumplen[1]=Pbytecnt;	//dis or immed         //~8310M~
        if (plabt)                                                 //~v255I~
	        if (Pbytecnt==2)                                       //~v255I~
        	{                                                      //~v255I~
				if (*(plabt+1) & (LABT_RELOC|LABT_ENTRY))          //~v255R~
					return DARC_OPCDERR;                           //~v255I~
        	}                                                      //~v255I~
            else                                                   //~v255I~
		        if (Pbytecnt==4)                                   //~v255I~
                {                                                  //~v259I~
					if ((*(plabt+1) & (LABT_RELOC|LABT_ENTRY))     //~v255R~
					||  (*(plabt+3) & (LABT_RELOC|LABT_ENTRY)))    //~v255R~
						return DARC_OPCDERR;                       //~v255I~
                }                                                  //~v259I~
                else                                               //~v259I~
		        	if (Pbytecnt==1)                               //~v259I~
						if (*plabt & (LABT_RELOC|LABT_ENTRY))      //~v259I~
							return DARC_OPCDERR;                   //~v259I~
	}                                                              //~8315R~
    else                                                           //~v223I~
    {                                                              //~v223I~
    	if (plabt && (*plabt & LABT_RELOC))                        //~v225R~
			return DARC_OPCDERR;                                   //~v223M~
    }                                                              //~v223I~
    return 0;                                                      //~8310M~
}//danextbyte                                                      //~8310M~
