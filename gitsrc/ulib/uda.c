//CID://+v6h7R~:           update#=    1                           //+v6h7R~
//*************************************************************
//*uda.c  disassemble
//*************************************************************
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//+v6h7I~
//v5i4:060505 (XDA)add 2nd labt for short comment of hint serach   //~v5i4I~
//v312 000507:DISAS:same as above for inst NOP (0x90) to save paper//~v312I~
//v300 000311:DISAS:same as above for inst int 3(0xcc) to save paper//~v300I~
//v285:990918 disas:increase default buff size for dup addr export entry//~v285I~
//v270:990717 disas:(BUG)print before start addr if in the range of instlen//~v270I~
//v260:990626 disas:seg:off addr is not same as real mode(for real but no seg:off required case)//~v260I~
//v257:990626 disas:print end addr is not to be printed(next byte) //~v257I~
//v224:990228 disas:print subrange                                 //~v224I~
//v223:990213 disas:callback func for reloc data proc for each magic//~v223I~
//v214:981227 disas:use labt for 1-path disas(foward label)        //~v214I~
//v213:981226 disas:adcon chk for indirect call/jump               //~v213I~
//v209:981223 disas:default buffer setup when fileout requested    //~v209I~
//*************************************************************    //~v209I~
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>     //offsetof
//*************************************************************
#include <ulib.h>
//********************
#include <uda.h>
#include <udasub.h>     //disas sub                                //~v214M~
#include <uda2.h>                                                  //~8411I~
#include <ualloc.h>     //disas sub                                //~8321I~
#include <ustring.h>                                               //~v300R~
//*************************************************************
#define INST_INT3   0xcc	//INT3 instruction                     //~v300I~
#define INST_NOP    0x90	//NOP  instruction                     //~v312I~
static UCHAR  *Sdfltbuff;                                          //~v285I~
//*****************************************************************
//*udaits :dummy for LIB
//*parm:none
//*ret :insttbl addr
//*****************************************************************
void uda(void)
{
//**********************
    return;
}//uda
//*****************************************************************
//*udisas                                                          //~8321R~
//* decode range                                                   //~8321R~
//*parm1:pdap
//*ret  :4 type unmatch for fpu
//*     :8  not def
//*     :12 buff shortage
//*****************************************************************
int udisas(PDAPARM Ppdap)
{
//#define DFLTBUFSZ  512                                           //~v285R~
    PDAREQ   pdar;                                                 //~8321I~
    UCHAR       *pc0,*caddr,*eaddr,*labt,*saddr;                   //~8321R~
    UCHAR       *eaddrp,*saddrp;                                   //~v224I~
    int rc=0,filesw,len0,len,pos,ii,phase,offs0;                     //~v214R~//+v6h7R~
    int outlen=0;                                                    //~8411I~//+v6h7R~
    int int3len;                                                   //~v300I~
    FILE *fh;
//  UCHAR  dfltbuff[DFLTBUFSZ];                                    //~v285R~
    UINT  dapstat;                                                 //~v214I~
    DISAS_CALLBACK *pcbfunc;                                       //~v223I~
    UCHAR  int3pa[128];     //int3 print work                      //~v300I~
    UCHAR  int3ornop;                                              //~v312I~
                                                                   //~v223I~
#define SETCOL(req,pos,width) 	if (req!=-1)         \
                                {                    \
									if (req)         \
                             			pos=req;     \
                                    else             \
                                    	req=pos;     \
                                    pos+=width;      \
                                }					 \
                        		else				 \
									req=0                          //~8321I~
//**********************
    filesw=(int)(Ppdap->DAPopt & DAPOPPUTF);
    phase=((Ppdap->DAPopt & DAPOP2PHASE)!=0);	//1 when 2phase    //~8321R~
    saddr=Ppdap->DAPsaddr;                                         //~8321I~
    eaddr=Ppdap->DAPeaddr;                                         //~8321I~
    if (saddrp=Ppdap->DAPsaddrp,saddrp)	//print range parm specified//~v224R~
    	eaddrp=Ppdap->DAPeaddrp;                                   //~v224I~
	else                                                           //~v224I~
    {                                                              //~v224I~
	    saddrp=saddr;                                              //~v224I~
    	eaddrp=eaddr;                                              //~v224I~
	}                                                              //~v224I~
    dapstat=0;                                                     //~v214R~
//    if (phase)                                                   //~v214R~
//    {                                                            //~v214R~
        offs0=(int)((ULONG)eaddr-(ULONG)saddr);                    //~8323R~
//  	labt=umalloc((UINT)offs0);                                 //~v5i4R~
    	labt=umalloc((UINT)(offs0+offs0));	//labt and labt2       //~v5i4I~
        if (!labt)                                                 //~8321I~
        	return DARC_MEMSHORT;                                  //~8321I~
//  	memset(labt,0,(UINT)offs0);                                //~v5i4R~
    	memset(labt,0,(UINT)(offs0+offs0));    //clear labt and labt2//~v5i4I~
    if (saddrp>saddr && saddrp<eaddr)                              //~v224I~
        *(labt+(ULONG)saddrp-(ULONG)saddr)=LABT_ENTRY;	//should be start of inst//~v224R~
    pcbfunc=Ppdap->DAPpcbfunc;                                     //~v223I~
    if (pcbfunc)        //call back defined                        //~v223I~
        pcbfunc(CB_LABTINIT,Ppdap,labt,(ULONG)offs0);              //~v223R~
      if (phase)                                                   //~v214I~
        dapstat|=DAPSTPH1;                                         //~v214R~
//    }                                                            //~v214R~
//    else                                                         //~v214R~
//        labt=0;                                                  //~v214R~
//    Ppdap->DAPlabt=labt;        //parm to udap_aiajc             //~v214R~
//set output column                                                //~8321I~
    pos=1;                                                         //~8321I~
//if (Ppdap->DAPmode & DAPMREAL)                                   //~v260R~
  if (Ppdap->DAPmode & DAPMSEGOFFA)                                //~v260I~
    SETCOL(Ppdap->DAPaddrpos ,pos,DAOL_ADDRREAL);                  //~v224I~
  else                                                             //~v224I~
    SETCOL(Ppdap->DAPaddrpos ,pos,DAOL_ADDR);                      //~8321R~
                                                                   //~v224I~
    SETCOL(Ppdap->DAPdumppos ,pos,DAOL_DUMP);                      //~8321I~
    SETCOL(Ppdap->DAPopcpos  ,pos,DAOL_MN);                        //~8321R~
    SETCOL(Ppdap->DAPopdpos  ,pos,DAOL_OPD);                       //~8321I~
    SETCOL(Ppdap->DAPrempos  ,pos,DAOL_REM);                       //~8321I~
    SETCOL(Ppdap->DAPadumppos,pos,0);                              //~8321I~
                                                                   //~8321I~
    fh=Ppdap->DAPfh;
    pc0=Ppdap->DAPoutbuff;
    len0=Ppdap->DAPoutbufflen;
    if (filesw & !pc0)      //no buffer specified                  //~v209I~
    {                                                              //~v209I~
    	if (!Sdfltbuff)	//first time                               //~v285I~
        {	                                                       //~v285I~
        	Sdfltbuff=umalloc(DFLTBUFSZ);                          //~v285I~
            if (!Sdfltbuff)                                        //~v285I~
	        	return DARC_MEMSHORT;                              //~v285I~
        }                                                          //~v285I~
//  	Ppdap->DAPoutbuff=pc0=dfltbuff;                            //~v285R~
    	Ppdap->DAPoutbuff=pc0=Sdfltbuff;                           //~v285I~
		Ppdap->DAPoutbufflen=len0=DFLTBUFSZ;                       //~v209I~
    }                                                              //~v209I~
    for (ii=0;ii<2;ii++)	//2 whase                              //~8321I~
    {                                                              //~8321I~
        outlen=0;                                                  //~8411I~
//    if (saddrp==saddr)                                           //~v224R~
        caddr=saddr;                                               //~8321R~
//    else                                                         //~v224R~
//      caddr=saddrp;                                              //~v224R~
        Ppdap->DAPopt|=DAPOPSTART;      //new addr start           //~8321R~
        while(caddr<eaddr)                                         //~8321R~
        {                                                          //~8321R~
//            Ppdap->DAPcaddr=caddr;                               //~v214R~
//            offs=(int)((ULONG)caddr-(ULONG)saddr);               //~v214R~
//          if (phase==2 &&  *(labt+offs))	//reffered             //~v214R~
//            if (phase!=1 &&  *(labt+offs))  //1-phase or phase-2 //~v214R~
//            {                                                    //~v214R~
//                dapstat|=DAPSTLAB;      //cleared at called      //~v214R~
//                if (*(labt+offs)=='2')                           //~v214R~
//                    dapstat|=DAPSTABSA;     //cleared at called  //~v214R~
//            }                                                    //~v214R~
            if (rc=udisas1(Ppdap,labt,&pdar,&dapstat,caddr),rc>DARC_OPCDERRD)//~v214R~
                    break;                                         //~8321R~
//            pdar=Ppdap->DAPvpdar;                                //~v214R~
//            if (phase==1)                                        //~v214R~
//            {                                                    //~v214R~
//                if (!rc)                                         //~v214R~
//                    if (pdar->DARstat &DARSJMPRO)   //jump relative offset//~v214R~
//                    {                                            //~v214R~
//                        offs+=(int)(pdar->DARimmvalue)+pdar->DARinstlen;//~v214R~
//                        if (offs>=0 && offs<offs0)               //~v214R~
//                            *(labt+offs)='1';                    //~v214R~
//                    }                                            //~v214R~
//            }                                                    //~v214R~
//            else                                                 //~v214R~
//  	  if (caddr<=eaddrp && caddr>=saddrp)                      //~v257R~
//  	  if (caddr<eaddrp && caddr>=saddrp)                       //~v270R~
    	  if (caddr<eaddrp && caddr+pdar->DARinstlen>saddrp)       //~v270I~
            if (phase!=1)                                          //~v214I~
            {                                                      //~8321I~
                len=Ppdap->DAPoutlen;                              //~8321R~
                if (filesw)                                        //~8321R~
                {                                                  //~8321R~
                    if (!fwrite(pc0,(UINT)len,1,fh))               //~8321R~
                    {                                              //~8321R~
                        rc=DARC_OUTERR;                            //~8321R~
                        break;                                     //~8321R~
                    }                                              //~8321R~
                }                                                  //~8321R~
                else                                               //~8321R~
                {                                                  //~8321R~
                    outlen+=len;                                   //~8411I~
                    Ppdap->DAPoutbuff+=len;                        //~8321R~
                    Ppdap->DAPoutbufflen-=len;                     //~8321R~
            	}                                                  //~8321R~
//*continuous int3 proc                                            //~v300I~
//  	        if (*caddr==INST_INT3                              //~v312R~
    	        int3ornop=*caddr;                                  //~v312I~
		        if ((int3ornop==INST_INT3||int3ornop==INST_NOP)    //~v312I~
                &&  Ppdap->DAPint3maxlen)   //requested save line fot continuous int 3//~v300I~
    	  			if (caddr<eaddrp)                              //~v300I~
                    {                                              //~v300I~
//                  	int3len=(int)umemspnc(caddr,INST_INT3,(ULONG)eaddrp-(ULONG)caddr);//~v312R~
                    	int3len=(int)umemspnc(caddr,int3ornop,(ULONG)eaddrp-(ULONG)caddr);//~v312I~
                    	if (int3len>=Ppdap->DAPint3maxlen)         //~v300I~
                        {                                          //~v300I~
		                  if (int3ornop==INST_INT3)                //~v312I~
                            len=sprintf(int3pa,"\n   ++++++  0x%04x(%5d) byte 0xCC(Int 3) is followed  ++++++\n",int3len-1,int3len-1);//~v300R~
                          else                                     //~v312I~
                            len=sprintf(int3pa,"\n   ++++++  0x%04x(%5d) byte 0x90(Nop)   is followed  ++++++\n",int3len-1,int3len-1);//~v312I~
                            if (filesw)                            //~v300I~
                            {                                      //~v300I~
                                if (!fwrite(int3pa,(UINT)len,1,fh))//~v300I~
                                {                                  //~v300I~
                                    rc=DARC_OUTERR;                //~v300I~
                                    break;                         //~v300I~
                                }                                  //~v300I~
                            }                                      //~v300I~
                            else                                   //~v300I~
                            {                                      //~v300I~
                                outlen+=len;                       //~v300I~
                                Ppdap->DAPoutbuff+=len;            //~v300I~
                                Ppdap->DAPoutbufflen-=len;         //~v300I~
                            }                                      //~v300I~
           					pdar->DARinstlen=int3len; //advance    //~v300I~
                        }                                          //~v300I~
                	}                                              //~v300I~
			}//no phase or 2nd phase                               //~8321I~
            caddr+=pdar->DARinstlen;                               //~8321R~
    	}//loop                                                    //~8321R~
        if (!phase)                                                //~8321R~
        	break;                                                 //~8321I~
        dapstat&=~DAPSTPH1;                                        //~v214R~
        dapstat|=DAPSTPH2;                                         //~v214R~
		phase=2;                                                   //~8321R~
	}//2phase                                                      //~8321I~
    Ppdap->DAPoutlen=outlen;                                       //~8411R~
    Ppdap->DAPoutbuff=pc0;                                         //~8411I~
    Ppdap->DAPoutbufflen=len0;
    if (pcbfunc)        //call back defined                        //~v223I~
        pcbfunc(CB_TERMRELOC,Ppdap,0,0);	//chk all reloc data used//~v223I~
    free(labt);                                                    //~v214I~
    return rc;
}//udisas
//*****************************************************************//~8411I~
//*udisasrevchk                                                    //~8411I~
//* decode range reverse(retry until last valid isnst is end at endaddr)//~8411I~
//*parm1:pdap                                                      //~8411I~
//*parm2:output valid start addr                                   //~v214I~
//*ret  :0:start addr found,!=0:no valid start addr found          //~8411I~
//*****************************************************************//~8411I~
int udisasrevchk(PDAPARM Ppdap,UCHAR **Ppsaddr)                    //~v214R~
{                                                                  //~8411I~
    PDAREQ   pdar;                                                 //~8411I~
    UCHAR   *caddr,*eaddr,*saddr,*caddr00;                         //~8411R~
    UCHAR   *outsaddr=NULL;                                             //~v214I~//+v6h7R~
    int rc=0,offs,offs0,sw00;                                        //~8411R~//+v6h7R~
    UINT optsv;                                                    //~8411I~
    UINT dapstat;                                                  //~v214I~
//**********************                                           //~8411I~
	optsv=Ppdap->DAPopt;                                           //~8411I~
    saddr=Ppdap->DAPsaddr;                                         //~8411I~
    eaddr=Ppdap->DAPeaddr;                                         //~8411I~
    Ppdap->DAPopt=0;		//stop if invalid inst                 //~8411I~
    dapstat=DAPSTPH1;	//bypass line edit                         //~v214R~
	offs0=(int)((ULONG)eaddr-(ULONG)saddr);                        //~8419R~
//try until boundary found                                         //~8411I~
    caddr00=0;			//first ok with 00                         //~8411I~
    for (offs=0;offs<offs0;offs++)		//start from top           //~8411I~
    {                                                              //~8411I~
    	sw00=0;                                                    //~8411I~
    	caddr=saddr+offs;                                          //~8411I~
        Ppdap->DAPopt|=DAPOPSTART;      //new addr start           //~8411I~
        while(caddr<eaddr)                                         //~8411I~
        {                                                          //~8411I~
        	if (!*caddr)		//0x00 may invalid                 //~8411I~
            	sw00=1;                                            //~8411I~
//            Ppdap->DAPcaddr=caddr;                               //~v214R~
            outsaddr=caddr;                                        //~v214I~
            if (rc=udisas1(Ppdap,0,&pdar,&dapstat,caddr),rc) //no labt//~v214R~
            	break;                                             //~8411I~
//            pdar=Ppdap->DAPvpdar;                                //~v214R~
            caddr+=pdar->DARinstlen;                               //~8411I~
    	}//loop                                                    //~8411I~
        if (!rc)                                                   //~8411R~
			if (!sw00)	//reached to end addr normaly without 00   //~8411I~
        	{                                                      //~8411R~
//                Ppdap->DAPcaddr=saddr+offs; //valid start addr   //~v214R~
				  outsaddr=saddr+offs; //valid start addr          //~v214I~
        		break;                                             //~8411R~
			}                                                      //~8411R~
            else                                                   //~8411I~
                if (!caddr00)                                      //~8411I~
                	caddr00=saddr+offs;	//lowest next better       //~8411I~
	}                                                              //~8411I~
    if (offs==offs0)	//not breaked                              //~8411I~
    	if (caddr00)                                               //~8411I~
//            Ppdap->DAPcaddr=caddr00;    //valid start addr       //~v214R~
            outsaddr=caddr00;    //valid start addr                //~v214I~
    Ppdap->DAPopt=optsv;		//stop if invalid inst             //~8411I~
    *Ppsaddr=outsaddr;                                             //~v214I~
    return rc;                                                     //~8411I~
}//udisasrevchk                                                    //~8411I~
