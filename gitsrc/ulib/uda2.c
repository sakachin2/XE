//CID://+v6h7R~:          update#=      11                         //+v6h7R~
//*************************************************************
//*uda2.c  disassemble                                             //~v210R~
//*************************************************************
//v6h7:120609 (VC6)avoid c4701 warning by VC6(used uninitialized variable)//+v6h7I~
//v5i4:060505 (XDA)add 2nd labt for short comment of hint serach   //~v5i4I~
//v5i2:060505 (XDA)insert LineFeed after return and before enter   //~v5i2I~
//v318 000603:allow DISAS:PL1 inst for VxD                         //~v318I~
//v317 000603:DISAS:DB for c3(ret)+90(nop)+00 case                 //~v317I~
//v313 000507:DISAS:(BUG)ff/00/20 is DB when >=4                   //~v313I~
//v311 000507:(DISAS)0 after adcon is not the case DB by jumpc,set DB ph2 and no lab ref//~v311I~
//v306 000422:DISAS:set OpdSz/AdrSz prefix nemonic(not DB 'F').    //~v306I~
//v285:990918 disas:increase default buff size for dup addr export entry//~v285I~
//v275:990808 disas:(BUG)backward ref label not set                //~v275I~
//v269:990717 disas:(BUG)print end addr is not to be printed       //~v269I~
//v267:990717 disas:DB print with no 0 prefix like as 0eah.(-->eah)//~v267I~
//v263:990710 disas:DOS int funcname edit by xda not by ulib       //~v263I~
//v262:990704 disas:set DOS int 21 comment                         //~v262I~
//v260:990626 disas:seg:off addr is not same as real mode(for real but no seg:off required case)//~v260I~
//v258:990626 disas:DOS MZ support;pass LABT_DOSSEG to callback func//~v248I~
//v248:990620 disas:assume continuous 20(space) as DB if len>=4    //~v248I~
//v247:990620 disas:(BUG)labsw save needed at opcd err dump        //~v247I~
//v246:990620 disas:DOS MZ support                                 //~v246I~
//v246:990619 disas:double space for albel line                    //~v246I~
//v242:990515 disas:if not dos drop previlage level 1 inst         //~v242I~
//v236:990501 disas:int20 VxD service name display                 //~v236I~
//v229:990320 disas:entry statement for export                     //~v229I~
//v228:990320 disas:assume continuous 00/ff as DB if len>=4        //~v228I~
//v223:990213 disas:callback func for reloc data proc for each magic//~v223I~
//v221:990212 disas:chk 00 after uncond jmp(jmp,ret,retf,iret) for DB not ADD//~v221I~
//v220:990212 disas:support indirect branch for also LX/NE         //~v220I~
//v217:990108 disas:change v216;for current buff addr use same value//~v217I~
//v216:990108 disas:base 0 id(-1)                                  //~v216I~
//v215:990103 disas:LX relocation support                          //~v215I~
//v214:981227 disas:use labt for 1-path disas(foward label)        //~v214I~
//v213:981226 disas:adcon chk for indirect call/jump               //~v213I~
//v212:981223 disas:import name display                            //~v212I~
//v211:981223 disas:eyecathable label                              //~v211I~
//v210:981223 disas:code addr base support                         //~v210I~
//*************************************************************    //~v210I~
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>     //offsetof
//*************************************************************    //~v212I~
#include <ulib.h>
#include <uda.h>
#include <udasub.h>     //disas sub
#include <uda2.h>                                                  //~v214M~
#include <udait.h>
#include <udaimage.h>                                              //~v215M~
#include <uedit2.h>     //disas sub
#include <ualloc.h>     //disas sub                                //~8321I~
#include <uerr.h>                                                  //~v285I~
#include <ucvucs.h>                                                //~v5i4I~
//*************************************************************
#define DELM_REM ';'                                               //~8321I~
#define REL_DOSSEG  256     //dos seg  relocation                  //~v246I~
#define INST_NOP    0x90	//NOP  instruction                     //~v317I~
//*************************************************************    //~8321I~
//*************************************************************    //~v228I~
int udaledit(PDAREQ Ppdar,int Plabel,int Popt);                    //~v236R~
#define  LE_VXDID     0x01           //Popt                        //~v236I~
void udacat(UCHAR **Pppout,UCHAR *Ppreqpos,UCHAR *Pdata);
void udacat2(UCHAR **Pppout,UCHAR *Ppreqpos,UCHAR *Pdata,UCHAR *Pendout);
void udadump(PDAPARM Ppdap,UCHAR **Pppout,UCHAR *Ppreqpos,PDAREQ Ppdar);
void udaasciidump(int Premid,PDAPARM Ppdap,UCHAR **Pppout,UCHAR *Ppreqpos,PDAREQ Ppdar);//~8321R~
void udasetaddr(PDAREQ Ppdar,UCHAR **Pppout);                      //~v214R~
void udadb(PDAPARM Ppdap,UCHAR **Pppout,UCHAR *Ppreqpos,PDAREQ Ppdar);
void udachk0db(UCHAR *Pcaddr,UCHAR *Peaddr,UCHAR *Plabt,int Pcont0chksw);//~v228R~
void udaucsdump(PDAPARM Ppdap,UCHAR **Pppout,UCHAR *Ppreqpos,PDAREQ Ppdar);//~v5i4I~
//*****************************************************************
//*uda2 :dummy for LIB                                             //~v212R~
//*parm:none
//*ret :insttbl addr
//*****************************************************************
void uda2(void)                                                    //~8411R~
{
//**********************
    return;
}//uda
//*****************************************************************
//*udisas1
//* decode one inst
//*parm1:pdap
//*parm2:label tbl ptr                                             //~v214I~
//*parm3:output dar addr                                           //~v214I~
//*ret  :4 type unmatch for fpu
//*     :8  not def
//*     :16 buff shortage
//*     :20 parm err
//*****************************************************************
int udisas1(PDAPARM Ppdap,UCHAR *Pplabt,PDAREQ *Pppdar,UINT *Ppstat,UCHAR *Pcaddr)//~v214R~
{
static  DAREQ   Sdar,Sdarerr;
    DISAS_CALLBACK *pcbfunc;                                       //~v223I~
    PINSTTBL pit;                                                  //~v221I~
    UCHAR       *caddr,*eaddr,*saddr;                              //~v214R~
    int rc,itype,class,dumpsw,labsw,labswt=0,labswopce=0;              //~v247R~//+v6h7R~
    int absaddsw;                                                  //~v213I~
    int relocsw;        //relocated ADCON                          //~v223I~
    int opcdersw;                                                  //~v221I~
    int vxdidsw=0;                                                   //~v236I~//+v6h7R~
    UCHAR  labid,ch;                                               //~v275R~
    UCHAR  *pc,*pc2;                                               //~v317R~
    LONG  offs,offsr;                                              //~v214R~
//**********************
//    Ppdap->DAPvpdar=&Sdar;                                       //~v214R~
    pcbfunc=Ppdap->DAPpcbfunc;                                     //~v223I~
    *Pppdar=&Sdar;                                                 //~v214I~
	Sdar.DARpdap=Ppdap;			//reverse ptr                      //~v213I~
	Sdar.DARplabt=Pplabt;		//reverse ptr                      //~v214I~
    saddr=Ppdap->DAPsaddr;                                         //~v223M~
//    absaddsw=0;                                                  //~v223R~
//    labsw=0;                                                     //~v223R~
//    relocsw=0;                                                   //~v223R~
//    if (Pplabt)                                                  //~v223R~
//    {                                                            //~v223R~
//        offs=(LONG)Pcaddr-(LONG)saddr;                           //~v223R~
//        labid=*(Pplabt+offs);                                    //~v223R~
//        switch (labid)                                           //~v223R~
//        {                                                        //~v223R~
//        case LABT_NONE:                                          //~v223R~
//        case LABT_OPCODE:                                        //~v223R~
//            break;                                               //~v223R~
//        case LABT_REF:                                           //~v223R~
//            labsw=1;                                             //~v223R~
//            break;                                               //~v223R~
//        case LABT_ADCON4:                                        //~v223R~
//            labsw=1;                                             //~v223R~
//            absaddsw=4;                                          //~v223R~
//            break;                                               //~v223R~
//        case LABT_ADCON2:                                        //~v223R~
//            labsw=1;                                             //~v223R~
//            absaddsw=2;                                          //~v223R~
//            break;                                               //~v223R~
//        case (LABT_ADCON4|LABT_RELOC):                           //~v223R~
//            labsw=1;                                             //~v223R~
//            absaddsw=4;                                          //~v223R~
//            relocsw=1;                                           //~v223R~
//            break;                                               //~v223R~
//        case (LABT_ADCON2|LABT_RELOC):                           //~v223R~
//            labsw=1;                                             //~v223R~
//            absaddsw=2;                                          //~v223R~
//            relocsw=1;                                           //~v223R~
//            break;                                               //~v223R~
//        }                                                        //~v223R~
//    }                                                            //~v223R~
//preserve stat
    if (Ppdap->DAPopt & DAPOPSTART)   //1st call                   //~8321R~
    {
        Ppdap->DAPopt &= ~DAPOPSTART;      //new addr start
//*inst class
        itype=(int)Ppdap->DAPitype;
        class=DAIIC_MMASK;     //ignore machine level
        if (itype & DAPITFPU)
            class|=DAIIC_FPU;
        if (itype & DAPITDOS)
        {
            class|=DAIIC_PL1;
            if (itype & DAPITFULL)
                class|=DAIIC_RARE;
        }
        else
        {                                                          //~v318I~
            if (itype & DAPITFULL)
                class|=(DAIIC_IMASK-DAIIC_FPU-DAIIC_PL1);//drop fpu,P-lvl-1//~v242R~
            if (itype & DAPITPL1)                                  //~v318I~
                class|=DAIIC_PL1;//P-lvl-1                         //~v318I~
        }                                                          //~v318I~
//  	if (Ppdap->DAPbase)                                        //~v217R~
//      {                                                          //~v217R~
//        if (Ppdap->DAPbase==(UCHAR*)-1)                          //~v217R~
//          Sdar.DARoffsfrombase=(ULONG)Ppdap->DAPsaddr;           //~v217R~
//        else                                                     //~v217R~
	        Sdar.DARoffsfrombase=(ULONG)Ppdap->DAPsaddr-(ULONG)Ppdap->DAPbase;//~v210I~
//  	}                                                          //~v217R~
//  	else                                                       //~v217R~
//          Sdar.DARoffsfrombase=0;                                //~v217R~
                Sdar.DARopt =Ppdap->DAPopt;
                Sdar.DARmode=Ppdap->DAPmode;
                Sdar.DARsaddr=Ppdap->DAPsaddr;
                Sdar.DAReaddr=Ppdap->DAPeaddr;
                Sdar.DARclass=(UINT)class;
                Sdar.DARstat=0;
        }
    Sdar.DARstat2=0;	//init                                     //~v5i2I~
    Sdar.DARopt2=0;                                                //~8328I~
    if (*Ppstat & DAPSTPH1)                                        //~v214R~
    	Sdar.DARopt2|=DAROPT2PH1;                                  //~8328I~
    caddr=Sdar.DARcaddr=Pcaddr;                                    //~v214R~
    eaddr=Sdar.DAReaddr;
    for (dumpsw=0;caddr<eaddr;caddr++)      //until dump max or valid opcode//~8321R~
    {
    	Sdar.DARcaddr=caddr;
        offs=(LONG)caddr-(LONG)saddr;                              //~v221I~
    	Sdar.DARoffs=(ULONG)offs;                                  //~v223I~
//clear output area
        memset(((char*)(void*)&Sdar)+offsetof(DAREQ,DARinstlen),0,
                    sizeof(Sdar)-offsetof(DAREQ,DARinstlen));
//  	opcdersw=(Pplabt && *(Pplabt+offs)==LABT_DB);              //~v223R~
        absaddsw=0;                                                //~v223I~
        labsw=0;                                                   //~v223I~
        relocsw=0;                                                 //~v223I~
		opcdersw=0;                                                //~v223I~
	    vxdidsw=0;		//4 byte VxD id                            //~v236I~
        if (Pplabt)                                                //~v223I~
        {                                                          //~v223I~
            labid=*(Pplabt+offs);                                  //~v229R~
            if (labid & LABT_ENTRY)                                //~v246R~
            {                                                      //~v229I~
            	labsw=2;			//entry id                     //~v229I~
            	labid=(UCHAR)(labid & ~LABT_ENTRY);                //~v246R~
            }                                                      //~v229I~
            if (labid & LABT_DOSSEG)                               //~v246I~
            {                                                      //~v246I~
            	labsw+=REL_DOSSEG;	//req callback by DOS_SEG      //~v246R~
            	labid=(UCHAR)(labid & ~LABT_DOSSEG);               //~v246I~
            }                                                      //~v246I~
            relocsw=labid & LABT_RELOC;                            //~v223R~
            if (relocsw)                                           //~v223I~
            {                                                      //~v223I~
	            if (labid & LABT_OFFS16)                           //~v223R~
            	    absaddsw=2;                                    //~v223M~
        	    else                    	//16bit reloc          //~v223R~
    	            absaddsw=4;                                    //~v223M~
            	labid=(UCHAR)(labid & ~(LABT_RELOC|LABT_OFFS16));  //~v223R~
            }                                                      //~v223I~
            switch (labid)                                         //~v223I~
            {                                                      //~v223I~
            case LABT_NONE:                                        //~v223I~
//          	if (*caddr==0x00 || *caddr==0xff)                  //~v248R~
            	if (*caddr==0x00 || *caddr==0xff || *caddr==0x20)  //~v248I~
                {                                                  //~v228I~
                    udachk0db(caddr,eaddr,Pplabt+offs,1);	//chk 1st continuous 00/ff//~v228I~
                    if ((labid=*(Pplabt+offs))==LABT_DB)           //~v228R~
                    	opcdersw=1;                                //~v228I~
				}                                                  //~v228I~
                break;                                             //~v228I~
            case LABT_OPCODE:                                      //~v223I~
                break;                                             //~v223I~
            case LABT_REF:                                         //~v223I~
                labsw++;    //gen addr label                       //~v229R~
                break;                                             //~v223I~
            case LABT_ADCON4:                                      //~v223I~
                labsw++;                                           //~v229R~
                absaddsw=4;                                        //~v223I~
                break;                                             //~v223I~
            case LABT_ADCON2:                                      //~v223I~
                labsw++;                                           //~v229R~
                absaddsw=2;                                        //~v223I~
                break;                                             //~v223I~
            case LABT_VXDSVCID:	//VxD service id after int 20      //~v223I~
			    vxdidsw=LE_VXDID;		//4 byte VxD id            //~v236R~
                absaddsw=4;                                        //~v223I~
                break;                                             //~v223I~
			case LABT_DB:                                          //~v223R~
				opcdersw=1;                                        //~v223I~
                break;                                             //~v223I~
            }                                                      //~v223I~
        }//labt exist                                              //~v223I~
      if (!opcdersw)    //not err                                  //~v221R~
      if (!absaddsw)                                               //~v221I~
      {                                                            //~v213I~
        rc=udainst(&Sdar);
        if (rc>DARC_OPCDERR)
            return rc;
        if (!rc)
        {
            memcpy(Sdar.DARdump,caddr,(UINT)Sdar.DARinstlen);
//lab taget set                                                    //~v214I~
    		if (Pplabt)                                            //~v214I~
            {                                                      //~v220I~
		        if (*(Pplabt+offs)==LABT_NONE)  //not refered      //~v220I~
		        	*(Pplabt+offs)=LABT_OPCODE;//start of inst     //~v220R~
            	if (Sdar.DARstat & DARSJMPRO)	//jump relative offset//~v214R~
                {                                                  //~v214I~
                    offsr=offs+(LONG)Sdar.DARimmvalue+Sdar.DARinstlen;//~v214R~
                    if (offsr>=0 && offsr<(LONG)eaddr-(LONG)saddr) //~v214R~
                    {                                              //~v275I~
//  	        	  if (*(Pplabt+offsr)==LABT_NONE)  //not refered//~v275R~
    	        	  ch=*(Pplabt+offsr);                          //~v275I~
    	        	  if (ch==LABT_NONE || ch==LABT_OPCODE)  //not refered//~v275I~
                        *(Pplabt+offsr)=LABT_REF;                  //~v220R~
                    }                                              //~v275I~
                }                                                  //~v214I~
			    pit=Sdar.DARvpit;                                  //~v221R~
                if (pit->DAIinsttyp & DAIIT_UCJMP)	//uncond jmp   //~v221I~
                {                                                  //~v317I~
//                    for (pc=caddr+Sdar.DARinstlen,               //~v223R~
//                            pc2=Pplabt+offs+Sdar.DARinstlen;     //~v223R~
//                            pc<eaddr;pc++,pc2++)    //net addr   //~v223R~
//                    {                                            //~v223R~
//                        if (*pc)    //not x'00'                  //~v223R~
//                            break;                               //~v223R~
//                        if (*pc2!=LABT_NONE)    //not refered    //~v223R~
//                            break;                               //~v223R~
//                        *pc2=LABT_DB;           //opcode err     //~v223R~
//                    }                                            //~v223R~
//                  udachk0db(caddr+Sdar.DARinstlen,eaddr,Pplabt+offs+Sdar.DARinstlen,0);//~v317R~
                    for (pc=caddr+Sdar.DARinstlen,                 //~v317I~
                            pc2=Pplabt+offs+Sdar.DARinstlen;       //~v317I~
                            pc<eaddr;pc++,pc2++)    //net addr     //~v317I~
                        if (*pc!=INST_NOP)    //skip x'90'         //~v317I~
                            break;                                 //~v317I~
                    udachk0db(pc,eaddr,pc2,0);                     //~v317I~
                }                                                  //~v317I~
			}//labt exist                                          //~v223R~
            labswt=labsw;	//labsw of top caddr                   //~v223I~
            break;
        }//rc==0                                                   //~v223R~
        if (!(Ppdap->DAPopt & DAPOPFCONT))   //no continue
        {
            Sdar.DARinstlen=1;
            Sdar.DARdump[0]=*caddr;
            return rc;
        }
      }//opcdersw!=0 || absaddsw!=0                                //~v223R~
        dumpsw=1;
        if (!Sdarerr.DARinstlen) //1st opcd err
        {
//          labswt=labsw;	//labsw of cadd top                    //~v247R~
            labswopce=labsw;	//save top labt for dump opcd err  //~v247I~
            Sdarerr=Sdar;
            Sdarerr.DARinstlen=0;
            Sdarerr.DARdumplen[0]=0;
            Sdarerr.DARstat|=DARSOPCDERRD;//opcode err dump
		 	if (absaddsw)                                          //~v213R~
            {                                                      //~v213M~
              if (absaddsw==4)                                     //~v220R~
	            memcpy(Sdarerr.DARmn,"DD",3); 	//dword            //~v213M~
              else                              //2 byte adcon     //~v220R~
	            memcpy(Sdarerr.DARmn,"DW",3); 	// word            //~v220R~
//              memcpy(Sdarerr.DARdump,caddr,4);    //4 byte abs addr//~v220R~
                memcpy(Sdarerr.DARdump,caddr,(UINT)absaddsw);    //4 byte abs addr//~v220R~
//              Sdarerr.DARinstlen=4;                              //~v220R~
                Sdarerr.DARinstlen=absaddsw;                       //~v220R~
//              udachk0db(caddr+absaddsw,eaddr,Pplabt+offs+absaddsw,0);//~v311R~
                udachk0db(caddr+absaddsw,eaddr,Pplabt+offs+absaddsw,(*Ppstat & DAPSTPH1)==0);//~v311I~
					//1byte 0 is DB when phase2 and no label ref   //~v311I~
			    if (relocsw)                                       //~v223I~
            		if (pcbfunc)                                   //~v223I~
                		pcbfunc(CB_ADCON,&Sdarerr,caddr,(ULONG)absaddsw);//chk reloc record//~v223R~
            	break;                                             //~v213M~
            }                                                      //~v213M~
            memcpy(Sdarerr.DARmn,"DB",3);
        }//1st time dump case                                      //~v223R~
		if (absaddsw)	//adcon after opcd err case                //~v223M~
            break;                                                 //~v223M~
        Sdarerr.DARdump[Sdarerr.DARinstlen++]=*caddr;
//      if (Sdarerr.DARinstlen==DARMAXDUMP)                        //~v221R~
        if (Sdarerr.DARinstlen==DARMAXDUMP_DB)                     //~v221I~
            break;
    }//until opcd ok or dumpmax
    if (dumpsw) //may breaked by rc=0
    {
        Sdar=Sdarerr;                   //ignore nex ok inst(retry next)
        Sdar.DARstat|=DARSOPCDERRD;                                //~8321I~
        Sdarerr.DARinstlen=0;   //for next DB first sw
        labswt=labswopce;	    //opcode err top labsw             //~v247I~
    }
    if (!(*Ppstat & DAPSTPH1))	//phase1                           //~v214R~
//    	rc=udaledit(&Sdar,labsw);                                  //~v223R~
      	rc=udaledit(&Sdar,labswt,vxdidsw);                         //~v236R~
	else                                                           //~8321I~
    	rc=0;                                                      //~8321I~
    return rc;                                                     //~8321R~
}//udisas1
//*****************************************************************//~v223I~
//*udachk0db                                                       //~v223I~
//* assume x'00'/x'ff' as DB byte                                  //~v228R~
//*parm1:caddr                                                     //~v223I~
//*parm2:eaddr                                                     //~v223I~
//*parm3:labt cur addr                                             //~v223I~
//*parm4:at first continuous 0 chk sw                              //~v228I~
//*****************************************************************//~v223I~
void udachk0db(UCHAR *Pcaddr,UCHAR *Peaddr,UCHAR *Pplabt,int Pcont0chksw)//~v228R~
{                                                                  //~v223I~
	UCHAR *pc,*pc2;                                                //~v223I~
    int   contffsw=0,cont0sw;                                      //~v228I~
    int   contspsw=0;   //no continuous space chk after ff or 00   //~v248I~
    ULONG  reslen;                                                 //~v228I~
//    ULONG  ul3sp=0x20202000;    //3 byte space                   //~v313R~
//**********************                                           //~v223I~
	cont0sw=Pcont0chksw;                                           //~v228I~
    for (pc=Pcaddr,pc2=Pplabt;pc<Peaddr;pc++,pc2++)    //net addr  //~v223R~
    {                                                              //~v223I~
        reslen=(ULONG)Peaddr-(ULONG)pc;                            //~v228R~
    	if (*pc==0xff)                                             //~v228I~
        {                                                          //~v228I~
        	if (!contffsw)	//1st time                             //~v228I~
            {                                                      //~v228I~
        		contffsw=1;                                        //~v228I~
//                if (reslen<2                                     //~v313R~
//                ||  (*(USHORT*)(void*)pc!=0xffff)                //~v313R~
//                ||  (*(USHORT*)(void*)pc2!=0))                   //~v313R~
                if (reslen<4                                       //~v313I~
                ||  *(LONG*)(void*)pc!=-1                          //~v313I~
                ||  *(LONG*)(void*)pc2!=0)                         //~v313I~
                	break;                                         //~v228I~
			}                                                      //~v228I~
//          cont0sw=0;	//after ffff evenif 1st 0 chk              //~v313R~
            cont0sw=1;	//when 1,check 4 byte                      //~v313I~
            contspsw=0;//newly space length chk                    //~v248I~
		}                                                          //~v228I~
        else                                                       //~v228I~
        {                                                          //~v228I~
        	contffsw=0;                                            //~v228I~
	        if (*pc)    //not x'00'                                //~v228R~
            {                                                      //~v248I~
              if (*pc!=' ')                                        //~v248I~
            	break;                                             //~v228I~
              if (!contspsw)  //1st time                           //~v248I~
              {                                                    //~v248I~
                  if (reslen<4                                     //~v248R~
//                    ||  (((*(ULONG*)(void*)pc)<<8)!=ul3sp)  //chk 3 byte//~v313R~
//                    ||  (((*(ULONG*)(void*)pc2)<<8)!=0))         //~v313R~
					||  *(ULONG*)(void*)pc!=0x20202020  //chk 4 byte//~v313I~
                	||  *(ULONG*)(void*)pc2!=0)                    //~v313I~
                      break;                                       //~v248I~
                  contspsw=1;                                      //~v248I~
              }                                                    //~v248I~
	            cont0sw=1;	//when 1,check 4 byte                  //~v313I~
            }                                                      //~v248I~
            else		//x00                                      //~v228I~
            {                                                      //~v248I~
	            contspsw=0;//newly space length chk                //~v248I~
            	if (cont0sw)	//1st time cont0 chk required      //~v228I~
                {                                                  //~v228I~
		        	if (reslen<4      //end of code  confirm 4 byte//~v228R~
//                    ||  (((*(ULONG*)(void*)pc)<<8)!=0)  //chk 3 byte//~v313R~
//                    ||  (((*(ULONG*)(void*)pc2)<<8)!=0))         //~v313R~
					||  *(ULONG*)(void*)pc!=0  //chk 4 byte        //~v313I~
                	||  *(ULONG*)(void*)pc2!=0)                    //~v313I~
        	        	break;                                     //~v228I~
		        	cont0sw=0;                                     //~v228I~
				}                                                  //~v228I~
			}                                                      //~v248I~
		}//not ff                                                  //~v228I~
        if (*pc2!=LABT_NONE)    //not refered                      //~v223I~
            break;                                                 //~v223I~
        *pc2=LABT_DB;           //opcode err                       //~v223I~
    }                                                              //~v223I~
    return;                                                        //~v223I~
}//udachk0db                                                       //~v223I~
//*****************************************************************//~8321I~
//*udaledit                                                        //~8321I~
//* edit line                                                      //~8321I~
//*parm1:pdap                                                      //~8321I~
//*parm2:label sw   x01:label  x02:entry                           //~v229I~
//*parm3:other opt   01:4 byte vxdid constant                      //~v236I~
//*                  02:DOS SEG callback requred sw                //~v246I~
//*ret  :16 buff shortage                                          //~v246R~
//*     :20 parm err                                               //~8321I~
//*****************************************************************//~8321I~
int udaledit(PDAREQ Ppdar,int Plabel,int Popt)                     //~v236R~
{                                                                  //~8321I~
    DISAS_CALLBACK *pcbfunc;                                       //~v221I~
    PINSTPROC   pfunc;                                             //~v263R~
    PINSTTBL pit;                                                  //~8321I~
    PDAPARM  pdap;                                                 //~v214R~
    UCHAR    *pout,*pc,*pc2,*opdstart,*pout0;                      //~8321R~
    UCHAR    *poutsv;                                              //~v211I~
    int      len,col,opdsw,ii,blen,dumpsw,dbsw,endcol,addroutsw,memsz,opdf;//~8322R~
    int      dossegsw;                                             //~v248I~
#define MAXOUTPOS 256                                              //~8321I~
//      UCHAR outbuff[MAXOUTPOS*3];                                //~v285R~
static  UCHAR *Soutbuff;                                           //~v285I~
static UCHAR *Smemtype[]={0,       // 0                            //~8322R~
                          "byte  ptr", // 1                        //~8331R~
                          "word  ptr", // 2                        //~8331R~
                          0,       // 3                            //~8322R~
                          "dword ptr", // 4                        //~8322R~
                          0,       // 5                            //~8322R~
                          "fword ptr", // 6                        //~8322R~
                          0,       // 7                            //~8322R~
                          "qword ptr", // 8                        //~8322R~
                          0,       // 9                            //~8322R~
                          "tbyte ptr"};//10                        //~8322R~
#define MAXMEMTYPE (sizeof(Smemtype)/4)                            //~8322I~
//**********************                                           //~8321I~
	pdap=Ppdar->DARpdap;                                           //~v214I~
    pcbfunc=pdap->DAPpcbfunc;                                      //~v221I~
    pit=Ppdar->DARvpit;                                            //~v214R~
    dumpsw=(int)(Ppdar->DARstat & DARSOPCDERRD);                   //~v214R~
//*edit line                                                       //~8321I~
//  pout0=pout=outbuff;                                            //~v285R~
	if (!Soutbuff)		//for dup export entry stmt                //~v285I~
    {                                                              //~v285I~
    	Soutbuff=umalloc(DFLTBUFSZ);                               //~v285I~
        if (!Soutbuff)                                             //~v285I~
        	uerrexit("Storage shortage for DA2 buff",0);           //~v285I~
    }                                                              //~v285I~
    pout0=pout=Soutbuff;                                           //~v285I~
//  blen=sizeof(outbuff);                                          //~v285R~
//  memset(pout,' ',(UINT)blen);                                   //~v285R~
//  if (Plabel &0x02)   //entry                                    //~v246R~
    if ((Plabel & 0x02)    //entry                                 //~v246R~
    ||  (Plabel>=REL_DOSSEG))	//dos seg,callback                 //~v246R~
    {                                                              //~v246I~
    	if (Plabel>=REL_DOSSEG)	//dos seg,callback                 //~v246I~
        {                                                          //~v248I~
            dossegsw=1;                                            //~v248I~
        	Plabel-=REL_DOSSEG;                                    //~v246I~
        }                                                          //~v248I~
        else                                                       //~v248I~
            dossegsw=0;                                            //~v248I~
        if (pcbfunc)    //callback func defined                    //~v229I~
        {                                                          //~v229I~
//          pcbfunc(CB_ENTRY,Ppdar,(void*)(ULONG)&pout,0);         //~v248R~
            pcbfunc(CB_ENTRY,Ppdar,(void*)(ULONG)&pout,(ULONG)dossegsw);//~v248R~
            pout0=pout;                                            //~v229I~
		}                                                          //~v229I~
	}                                                              //~v246I~
//*addr                                                            //~8321I~
    blen=MAXOUTPOS*3;                                              //~v285I~
    memset(pout,' ',(UINT)blen);                                   //~v285I~
    col=pdap->DAPaddrpos;                                          //~v214R~
    addroutsw=!(pdap->DAPopt & DAPOPNOADDR);	//no noaddr req    //~v214R~
    if (col>0                                                      //~8321R~
    && (addroutsw						//no noaddr req            //~8321I~
        || Plabel))                     //label required           //~8321I~
    {                                                              //~8321I~
        if (col>=MAXOUTPOS)                                        //~8321I~
            return DARC_PARMERR;                                   //~8321I~
//      if (Plabel)        //label                                 //~v5i2R~
        if (Plabel        //label                                  //~v5i2I~
        ||  (Ppdar->DARstat2 & DARS2LF1))                          //~v5i2I~
        {                                                          //~v246I~
   			*pout++='\n'; //set a blank line                       //~v246I~
            pout0=pout;	//newline top                              //~v246I~
		}                                                          //~v246I~
        pout+=col-1;                                               //~8321R~
        poutsv=pout;                                               //~v211I~
        udasetaddr(Ppdar,&pout);                                   //~v214R~
        if (!Plabel)        //not label                            //~v211I~
        {                                                          //~v211I~
            *poutsv=' ';                                           //~v211I~
            if (!memcmp(poutsv+1,"00",2))                          //~v211R~
            	memcpy(poutsv+1,"  ",2);                           //~v211R~
        }                                                          //~v211I~
		if (addroutsw)                                             //~8321R~
   			pout++; //skip space                                   //~8321I~
		else         //no addrout, lab only                        //~8321R~
        {                                                          //~8321I~
   			*pout++='\n'; //new line                               //~8321I~
            pout0=pout;	//newline top                              //~8321I~
		}                                                          //~8321I~
    }                                                              //~8321I~
//*hex dump                                                        //~8321I~
    col=pdap->DAPdumppos;                                          //~v214R~
    if (col>0)                                                     //~8321I~
    {                                                              //~8321I~
        if (col>=MAXOUTPOS)                                        //~8321I~
            return DARC_PARMERR;                                   //~8321I~
        udadump(pdap,&pout,pout0+col-1,Ppdar);                     //~v214R~
        pout++; //skip space                                       //~8321I~
    }                                                              //~8321I~
//*ope code                                                        //~8321I~
//printf("mn=%s,opd=%s\n",Ppdar->DARmn,Ppdar->DARopd[0]);//@@@@    //~v214R~
    col=pdap->DAPopcpos;                                           //~v214R~
    if (col>0)                                                     //~8321I~
    {                                                              //~8321I~
        if (col>=MAXOUTPOS)                                        //~8321I~
            return DARC_PARMERR;                                   //~8321I~
        udacat(&pout,pout0+col-1,Ppdar->DARmn);                    //~v214R~
        pout++; //skip space                                       //~8321I~
    }                                                              //~8321I~
//*operand                                                         //~8321I~
    col=pdap->DAPopdpos;                                           //~v214R~
//  dbsw=(dumpsw || (pit->DAIinsttyp & (DAIIT_ADDRSZ|DAIIT_OPDSZ)));//~v306R~
    dbsw=dumpsw;                                                   //~v306I~
    if (col>0)                                                     //~8321I~
    {                                                              //~8321I~
        if (col>=MAXOUTPOS)                                        //~8321I~
            return DARC_PARMERR;                                   //~8321I~
        opdstart=pout0+col-1;                                      //~8321I~
        if (dbsw)                                                  //~8321I~
        {                                                          //~v236I~
            udadb(pdap,&pout,opdstart,Ppdar);                      //~v214R~
        	if (pcbfunc)                                           //~v236I~
            	if (Popt & LE_VXDID)                               //~v236I~
	            	pcbfunc(CB_SHORTREMDB,Ppdar,(void*)(ULONG)&pout,0);//~v236R~
		}                                                          //~v236I~
        else                                                       //~8321I~
        {                                                          //~8321I~
            opdsw=0;        //operand exist sw                     //~8321I~
            for (ii=0;ii<3;ii++)                                   //~8321I~
            {                                                      //~8321I~
                pc=Ppdar->DARopd[ii];                              //~v214R~
                if (*pc)                                           //~8321I~
                {                                                  //~8321I~
                    if (opdsw)  //2nd opd                          //~8321I~
                        *pout++=',';                               //~8321I~
                    memsz=Ppdar->DARmemsize;	//memory size needed//~v214R~
                    if (memsz<MAXMEMTYPE)                          //~8322R~
                    {                                              //~8322R~
                    	opdf=(int)(pit->DAIopdf[ii]);              //~8323R~
                        if ((opdf & DAIOT_fTPMASK)==DAIOT_tMRMMEM  //~8322I~
                        ||  (opdf & DAIOT_fIDMASK)==DAIOT_OFFS)    //~8322I~
                        {                                          //~8322I~
                            pc2=Smemtype[memsz];                   //~8322R~
                            if (pc2)                               //~8322R~
                                udacat(&pout,opdstart,pc2);        //~8322R~
						}                                          //~8322I~
                    }                                              //~8322I~
                    udacat(&pout,opdstart,pc);                     //~8321I~
                    opdsw=1;                                       //~8321I~
                }                                                  //~8321I~
            }                                                      //~8321I~
        }//dumpsw                                                  //~v215R~
        if (Ppdar->DARdapcaseno==DAPCASE_LEDIT)//callback requested//~v263I~
        {                                                          //~v263I~
            pfunc=pit->DAIpfunc;                                   //~v263I~
            pfunc(Ppdar);       //get AX value into DARimmvalue2 for int DOS//~v263I~
        }                                                          //~v263I~
        if (pcbfunc)                                               //~v223I~
            pcbfunc(CB_SHORTREM,Ppdar,(void*)(ULONG)&pout,0);      //~v223I~
//        if (Ppdar->DARdapcaseno==DAPCASE_LEDIT)//callback requested//~v263R~
//        {                                                        //~v263R~
//            Ppdar->DARdapparm=pout;  //short rem output pos      //~v263R~
//            pfunc=pit->DAIpfunc;                                 //~v263R~
//            pfunc(Ppdar);       //recall dap                     //~v263R~
//            pout=Ppdar->DARdapparm; //updated print pos          //~v263R~
//        }                                                        //~v263R~
        pout++;                                                    //~8321I~
    }//opd col specified                                           //~8321I~
//*remark                                                          //~8321I~
    col=pdap->DAPrempos;                                           //~v214R~
    if (col>0)                                                     //~8321I~
    {                                                              //~8321I~
        if (col>=MAXOUTPOS)                                        //~8321I~
            return DARC_PARMERR;                                   //~8321I~
        endcol=pdap->DAPadumppos;                                  //~v223I~
        if (endcol<=0)                                             //~v223I~
            endcol=col+DAOL_REM;                                   //~v223I~
        if (dumpsw)               //DB const display case          //~8321I~
        {                                                          //~v223I~
	    	if (Ppdar->DARrelocopdno)		//reloc data           //~v223I~
	         	udacat2(&pout,pout0+col-1,Ppdar->DARrem,pout0+endcol-1);//~v223I~
            else                                                   //~v223I~
			  	if (Ppdar->DARmn[1]=='B')      //DB(ope code err)  //~v223I~
	         		udacat2(&pout,pout0+col-1,"??",pout0+endcol-1);//~v223R~
//          udaasciidump(1,pdap,&pout,pout0+col-1,Ppdar);//add ';' //~v223R~
		}                                                          //~v223I~
        else                                                       //~8321I~
        {                                                          //~8321I~
         	udacat2(&pout,pout0+col-1,Ppdar->DARrem,pout0+endcol-1);//~v214R~
		}                                                          //~8321I~
        pout++; //skip space                                       //~8321I~
    }//rem col specified                                           //~8321I~
//*ascii dump                                                      //~8321I~
//  if (!dbsw)	//db dumped             //normal inst              //~v223R~
//  {                                                              //~v223R~
        col=pdap->DAPadumppos;                                     //~v214R~
        if (col>0)                                                 //~8321I~
        {                                                          //~8321I~
            if (col>=MAXOUTPOS)                                    //~8321I~
                return DARC_PARMERR;                               //~8321I~
            udaasciidump(0,pdap,&pout,pout0+col-1,Ppdar);//no remid//~v214R~
    		if ((pdap->DAPopt & DAPOPADUCS))	//no noaddr req    //~v5i4I~
            	udaucsdump(pdap,&pout,pout0+col-1+10,Ppdar);//sjis print from ucs code//~v5i4R~
        }//rem col specified                                       //~8321I~
//  }                                                              //~v223R~
                                                                   //~8321I~
    if (Ppdar->DARstat2 & DARS2LF2)	//insert LF after line         //~v5i2I~
	    *pout++='\n';                                              //~v5i2I~
    *pout++='\n';                                                  //~8321I~
    *pout++=0;                                                     //~8321I~
//  len=(int)((ULONG)pout-(ULONG)outbuff);                         //~v285R~
    len=(int)((ULONG)pout-(ULONG)Soutbuff);                        //~v285I~
    if (len>pdap->DAPoutbufflen)                                   //~v214R~
        return DARC_OUTERR;                                        //~8321I~
//  memcpy(pdap->DAPoutbuff,outbuff,(UINT)len);                    //~v285R~
    memcpy(pdap->DAPoutbuff,Soutbuff,(UINT)len);                   //~v285I~
    pdap->DAPoutlen=len-1;                                         //~v214R~
    return 0;                                                      //~8321I~
}//udaledit                                                        //~v214R~
//************************************************************
//*udacat
//*   strcat to outbuff
//*parm1:input:outbuff addr,output:next buff addr
//*parm2:requested output pos
//*parm3:data addr to be set
//*rc   :none
//************************************************************
void udacat(UCHAR **Pppout,UCHAR *Ppreqpos,UCHAR *Pdata)
{
        UINT ulen;
    UCHAR *pc;
//********************
        ulen=strlen(Pdata);
    if (!ulen)
        return;
        pc=*Pppout;
    if (Ppreqpos>pc)
        pc=Ppreqpos;
    memcpy(pc,Pdata,ulen);
    *Pppout=pc+ulen;
        return;
}//udacat
//************************************************************
//*udacat2
//*   strcat to outbuff,if overflow stepback
//*parm1:input:outbuff addr,output:next buff addr
//*parm2:requested output pos
//*parm3:data addr to be set
//*parm4:output limit addr
//*rc   :none
//************************************************************
void udacat2(UCHAR **Pppout,UCHAR *Ppreqpos,UCHAR *Pdata,UCHAR *Pendout)
{
    UINT ulen;
    int  backlen;
    UCHAR *pc;
//********************
    ulen=strlen(Pdata);                                            //~8321R~
    pc=*Pppout;                                                    //~8321R~
    if (Ppreqpos>pc)
        pc=Ppreqpos;
	backlen=pc+ulen+2-Pendout;                                     //~8321R~
	if (backlen>0)
    {
    	pc-=backlen;
        if (pc<*Pppout)	//before startpos
        	pc=*Pppout;
	}
    *pc++=DELM_REM;                                                //~8321I~
    memcpy(pc,Pdata,ulen);
    *Pppout=pc+ulen;                                               //~8321R~
        return;
}//udacat2
//************************************************************
//*udasetaddr
//*   set addr
//*parm1:pdar                                                      //~v214R~
//*parm2:input:outbuff addr,output:next outbuff addr
//*parm3:addr value
//*rc   :none
//************************************************************
void udasetaddr(PDAREQ Ppdar,UCHAR **Pppout)                       //~v214R~
{
    UCHAR *pco,*pat;
    UCHAR wk[16];                                                  //~8321R~
    UINT  seg,off;
    ULONG vaddr;		//virtual addr                             //~v210R~
    PDAPARM pdap;                                                  //~v214I~
    ULONG dossegoff,dosvaddr;                                      //~v246I~
//********************
        pco=*Pppout;
    pdap=Ppdar->DARpdap;                                           //~v214R~
    vaddr=(ULONG)pdap->DAPbase;                                    //~v214R~
//  if (vaddr)      //base spacified                               //~v217R~
//    if (vaddr==(ULONG)-1)                                        //~v217R~
//  	vaddr=(ULONG)Ppdar->DARcaddr-(ULONG)pdap->DAPsaddr;        //~v217R~
//    else                                                         //~v217R~
    	vaddr=(ULONG)Ppdar->DARcaddr-(ULONG)pdap->DAPsaddr+vaddr;  //~v214R~
//  else                                                           //~v217R~
//  	vaddr=(ULONG)Ppdar->DARcaddr;                              //~v217R~
//  if (pdap->DAPmode & DAPMREAL)                                  //~v246R~
//  {                                                              //~v246R~
//      if (pdap->DAPopt & DAPOPLOWADR)                            //~v246R~
//          pat="_%04x_%04x:";                                     //~v246R~
//      else                                                       //~v246R~
//          pat="_%04X_%04X:";                                     //~v246R~
//      seg=((ULONG)pdap->DAPcaddr >>16);                          //~v214R~
//      off=((ULONG)pdap->DAPcaddr & 0xffff);                      //~v214R~
//      seg=vaddr>>16;                                             //~v246R~
//      off=vaddr & 0xffff;                                        //~v246R~
//      sprintf(wk,pat,seg,off);                                   //~v246R~
//      memcpy(pco,wk,11);                                         //~v246R~
//      *Pppout=pco+11;                                            //~v246R~
//  }                                                              //~v246R~
//  else                                                           //~v246R~
//  {                                                              //~v246R~
        if (pdap->DAPopt & DAPOPLOWADR)                            //~v214R~
            pat="_%08lx ";                                         //~v246R~
        else
            pat="_%08lX ";                                         //~v246R~
//      sprintf(wk,pat,pdap->DAPcaddr);                            //~v214R~
        sprintf(wk,pat,vaddr);                                     //~v210I~
        memcpy(pco,wk,10);                                         //~8321R~
//      *Pppout=pco+10;                                            //~v246R~
        pco+=10;                                                   //~v246I~
//  }                                                              //~v246R~
//  if (pdap->DAPmode & DAPMREAL)                                  //~v260R~
    if (pdap->DAPmode & DAPMSEGOFFA)                               //~v260R~
    {                                                              //~v246I~
        if (pdap->DAPopt & DAPOPLOWADR)                            //~v246I~
            pat="%04x:%04x ";                                      //~v246R~
        else                                                       //~v246I~
            pat="%04X:%04X ";                                      //~v246R~
		dossegoff=Ppdar->DARdossegoff;                             //~v246I~
        seg=(UINT)(dossegoff>>16);                                 //~v246I~
        dosvaddr=seg<<4;                                           //~v246I~
        off=(UINT)(USHORT)(vaddr-dosvaddr);                        //~v246I~
        seg=(USHORT)(seg+pdap->DAPrelocv);  //reloc by parm reloc value//~v248I~
        sprintf(wk,pat,seg,off);                                   //~v246I~
        memcpy(pco,wk,10);                                         //~v246I~
        pco+=10;                                                   //~v246I~
    }                                                              //~v246I~
    *Pppout=pco;                                                   //~v246I~
    return;
}//udasetaddr

//************************************************************
//*udadump
//*   strcat to outbuff
//*parm1:option 1:lower case
//*parm2:input:outbuff addr,output:next outbuff addr
//*parm3:request out addr
//*parm4:pdar
//*rc   :0:ok,16:buff shortage
//************************************************************
void udadump(PDAPARM Ppdap,UCHAR **Pppout,UCHAR *Ppreqpos,PDAREQ Ppdar)
{
    int opt,datalen,datalen2,len;                                  //~v269R~
    UCHAR *pco,*wkp;
    UCHAR wk[32];
//********************
        pco=*Pppout;
        if (Ppreqpos>pco)
        pco=Ppreqpos;
    if (Ppdap->DAPopt & DAPOPLOWDMP)
        opt=UBX_LOWER;
    else
        opt=0;
    datalen=Ppdar->DARinstlen;
    ub2x(opt,wk,Ppdar->DARdump,datalen);
    wkp=wk;
    if (Ppdap->DAPeaddrp)                                          //~v269I~
    	if ((datalen2=Ppdap->DAPeaddrp-Ppdar->DARcaddr)<datalen)   //~v269I~
        	if (datalen2>0)                                        //~v269I~
            	datalen=datalen2;                                  //~v269I~
    len=Ppdar->DARdumplen[0];
    if (!len)
        len=datalen;
    datalen<<=1;
//opcd
    len<<=1;
    memcpy(pco,wkp,(UINT)len);
    pco+=len;
        datalen-=len;
    if (datalen<=0) //opcd only or DB type
        return;
    wkp+=len;
//disp
    len=Ppdar->DARdumplen[1];
    if (len)
    {
        pco++;
        len<<=1;
        memcpy(pco,wkp,(UINT)len);
        pco+=len;
        datalen-=len;
        wkp+=len;
        if (datalen<=0) //opcd only or DB type                     //~8329I~
            return;                                                //~8329I~
    }
//imm
    len=Ppdar->DARdumplen[2];
    if (len)
    {
        pco++;
        len<<=1;
        memcpy(pco,wkp,(UINT)len);
        pco+=len;
    }
    *Pppout=pco;
    return;
}//udadump

//************************************************************
//*udadb
//*   define byte
//*parm1:pdap
//*parm2:input:outbuff addr,output:next outbuff addr
//*parm3:request out addr
//*parm4:pdar
//*rc   :none
//************************************************************
void udadb(PDAPARM Ppdap,UCHAR **Pppout,UCHAR *Ppreqpos,PDAREQ Ppdar)
{
    int opt,datalen,ii,datalen2;                                   //~v269R~
    UCHAR *wkp,*pdata,*pout;
    UCHAR wk[32];
//********************
        pout=*Pppout;
        if (Ppreqpos>pout)
        pout=Ppreqpos;
    if (Ppdap->DAPopt & DAPOPLOWOPD)
        opt=UBX_LOWER;
    else
        opt=0;
    datalen=Ppdar->DARinstlen;
    pdata=Ppdar->DARdump;
    ub2x(opt,wk,pdata,datalen);
    if (Ppdap->DAPeaddrp)                                          //~v269I~
    	if ((datalen2=Ppdap->DAPeaddrp-Ppdar->DARcaddr)<datalen)   //~v269I~
        	if (datalen2>0)                                        //~v269I~
            	datalen=datalen2;                                  //~v269I~
  if (Ppdar->DARmn[1]=='D'      //dowrd (adcon)                    //~v220R~
  ||  Ppdar->DARmn[1]=='W')      // owrd (adcon)                   //~v220R~
  {                                                                //~v213I~
//  for (ii=3;ii>=0;ii--)                                          //~v220R~
    for (ii=datalen-1;ii>=0;ii--)                                  //~v220R~
    {                                                              //~v213I~
    	*pout++=*(wk+ii+ii);                                       //~v213I~
    	*pout++=*(wk+ii+ii+1);                                     //~v213I~
    }                                                              //~v213I~
    *pout++='h';                                                   //~v213I~
  }                                                                //~v213I~
  else                                                             //~v213I~
  {     //DB                                                       //~v213I~
    wkp=wk;
    for (ii=0;ii<datalen;ii++,pdata++)
    {
        if (ii)
            *pout++=',';
        if (*pdata>=' ' && *pdata<0x7f)
        {
            *pout++='\'';
            *pout++=*pdata;
            *pout++='\'';
            wkp+=2;
        }
        else
        {
//              if (*wkp>'9')                                      //~v267R~
//              *pout++='0';                                       //~v267R~
            *pout++=*wkp++;
            *pout++=*wkp++;
            *pout++='h';
        }
    }
  }     //DB                                                       //~v213I~
    *Pppout=pout;
    return;
}//udadb

//************************************************************
//*udaasciidump
//*   strcat to outbuff
//*parm1:rem ';' add option                                        //~8321R~
//*parm1:pdap                                                      //~8321I~
//*parm2:input:outbuff addr,output:next outbuff addr
//*parm3:request out addr
//*parm4:pdar
//*rc   :none
//************************************************************
void udaasciidump(int Premid,PDAPARM Ppdap,UCHAR **Pppout,UCHAR *Ppreqpos,PDAREQ Ppdar)//~8321R~
{
    UCHAR *pco;
    int opt;
//********************
    pco=*Pppout;                                                   //~8321R~
    if (Ppreqpos>pco)                                              //~8321R~
        pco=Ppreqpos;
	if (Premid)                                                    //~8321I~
    	*pco++=DELM_REM;                                           //~8321I~
    opt=0;
    if (Ppdap->DAPopt & DAPOPADKANA)
        opt|=UAD_KANA;
    if (!(Ppdap->DAPopt & DAPOPADSBCS))
        opt|=UAD_DBCS;
        uasciidump(opt,pco,Ppdar->DARdump,Ppdar->DARinstlen);
    *Pppout=pco+Ppdar->DARinstlen;
    return;
}//udaasciidump
//************************************************************     //~v5i4I~
//*udaucsdump                                                      //~v5i4I~
//*   sjis print from ucs code                                     //~v5i4I~
//*parm1:pdap                                                      //~v5i4I~
//*parm2:input:outbuff addr,output:next outbuff addr               //~v5i4I~
//*parm3:request out addr                                          //~v5i4I~
//*parm4:pdar                                                      //~v5i4I~
//*rc   :none                                                      //~v5i4I~
//************************************************************     //~v5i4I~
void udaucsdump(PDAPARM Ppdap,UCHAR **Pppout,UCHAR *Ppreqpos,PDAREQ Ppdar)//~v5i4I~
{                                                                  //~v5i4I~
    UCHAR *pco,*plabt2,*plabt,*pcode,*pc;                          //~v5i4R~
    int offs,instlen,ucsoffs,ucslen,opt;                           //~v5i4R~
//********************                                             //~v5i4I~
	pcode=Ppdar->DARcaddr;                                         //~v5i4I~
    pco=*Pppout;                                                   //~v5i4I~
    if (Ppreqpos>pco)                                              //~v5i4I~
        pco=Ppreqpos;                                              //~v5i4I~
    offs=(int)((ULONG)(Ppdar->DARcaddr)-(ULONG)(Ppdar->DARsaddr));	//of curr instruction//~v5i4R~
if (offs>=0x0711)   //@@@@test                                     //~v5i4I~
    offs=offs;                                                     //~v5i4I~
    plabt=Ppdar->DARplabt+offs;                                    //~v5i4I~
    plabt2=plabt+(ULONG)(Ppdar->DAReaddr)-(ULONG)(Ppdar->DARsaddr);	//same pos on labt2//~v5i4R~
    instlen=Ppdar->DARinstlen;                                     //~v5i4I~
    ucsoffs=0;                                                     //~v5i4R~
    pc=plabt2;                                                     //~v5i4I~
    if (*pc & LABT2_UCSCODE2)                                      //~v5i4I~
    {                                                              //~v5i4I~
    	if (instlen>1 && (*(pc+1) & LABT2_UCSCODE1))               //~v5i4R~
        {                                                          //~v5i4I~
        	ucsoffs=1;                                             //~v5i4I~
            *pco++='.';                                            //~v5i4I~
        }                                                          //~v5i4I~
    }                                                              //~v5i4I~
    ucslen=instlen-ucsoffs;                                        //~v5i4I~
    if (ucslen)                                                    //~v5i4R~
    {                                                              //~v5i4I~
    	opt=UUD_NORETRY;		//try from top byte only           //~v5i4I~
	    if (!(Ppdap->DAPopt & DAPOPADSBCS))                        //~v5i4I~
	        opt|=UUD_DBCS;                                         //~v5i4I~
		pco+=uucsdump(opt,pco,pcode+ucsoffs,ucslen,(int)((ULONG)Ppdar->DAReaddr-(ULONG)pcode-ucsoffs));//~v5i4R~
    }                                                              //~v5i4I~
    *Pppout=pco;                                                   //~v5i4I~
    return;                                                        //~v5i4I~
}//udaucsdump                                                      //~v5i4I~
