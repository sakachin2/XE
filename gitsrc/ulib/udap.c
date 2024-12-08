//CID://+v5i4R~:                                                   //~v5i4R~
//*************************************************************    //~v213I~
//*udap.c  disassemble sub                                         //~v213I~
//*************************************************************    //~v213I~
//v5i4:060505 (XDA)add 2nd labt for short comment of hint serach   //~v5i4I~
//v5i1:060505 (XDA)no more relocation data for import table reference from somewhen//+v5i4R~
//            (import table shifted to .idata to .rdata section)   //~v5i1I~
//v309 000502:(DISAS)PE linker v6 support(IAT is in code seg and no reloc data)//~v309I~
//            set reloc bit on labt,it cause generate IMPORT remark//~v309I~
//v308 000501:(DISAS)set reference for also refered by adcon       //~v308I~
//v275:990808 disas:(BUG)backward ref label not set                //~v275I~
//v273:990729 disas:int remark for NE                              //~v273I~
//v271:990718 disas:opcode err for invalid int no                  //~v271I~
//v266:990711 disas:chk XOR for AH/AL/AX set for DOS int           //~v266I~
//v263:990710 disas:DOS int funcname edit by xda not by ulib       //~v262I~
//v262:990704 disas:set DOS int 21 comment                         //~v262I~
//v254:990626 disas:DOS MZ support(direct far call label ref)      //~v254I~
//v246:990620 disas:DOS MZ support                                 //~v246I~
//v243:990515 disas:PE display import func name for indirect call/jump//~v243I~
//v236:990501 disas:int20 VxD service name display                 //~v236I~
//v227:990228 disas:int20 follow dword vxd id                      //~v227I~
//v223:990213 disas:callback func for reloc data proc for each magic//~v220I~
//v220:990212 disas:support indirect branch for also LX/NE         //~v220R~
//v214:981227 disas:use labt for 1-path disas(foward label)        //~v214I~
//v213:981226 disas:adcon chk for indirect call/jump               //~v213I~
//*************************************************************    //~v213I~
#include <stdlib.h>                                                //~v213I~
#include <stdio.h>                                                 //~v213I~
#include <string.h>                                                //~v213I~
#include <ctype.h>                                                 //~v213I~
//*************************************************************    //~v213I~
#include <ulib.h>                                                  //~v213I~
//********************                                             //~v213I~
#include <uda.h>                                                   //~v213I~
#include <udasub.h>	                                               //~v213R~
#include <udait.h>                                                 //~v213I~
#include <udap.h>	                                               //~v213I~
//#include <udadfts.h>                                             //~v262R~
#include <udaimage.h>                                              //~v214R~
//*****************************************************************//~v262I~
static int Sdosfarsw;                                              //~v246I~
static UCHAR Salah[2],*Sahset,*Salset;                             //~v263R~
//*****************************************************************//~v213I~
//*udasf  :dummy for LIB                                           //~v213I~
//*parm:none                                                       //~v213I~
//*ret :none                                                       //~v213I~
//*****************************************************************//~v213I~
void udap(void)                                                    //~v213R~
{                                                                  //~v213I~
//**********************                                           //~v213I~
    return;                                                        //~v213I~
}//udap                                                            //~v213R~
//*****************************************************************//~v213I~
//*absolute indirect addr call/jump                                //~v213I~
//*parm1:pdar                                                      //~v213I~
//*ret  :0                                                         //~v213I~
//*****************************************************************//~v213I~
int udap_aiajc(PDAREQ Ppdar)                                       //~v213I~
{                                                                  //~v213I~
    int caseno,ii;                                                 //~v213R~
    int opdsz;                                                     //~v220I~
    int destsw,destswo,diff;                                       //~v220R~
	PDAPARM pdap;                                                  //~v213I~
    UCHAR *plabt;                                                  //~v213I~
    ULONG bstart,bend,bpaddr,vbase,vend,vpaddr,vaddr;              //~v213R~
    ULONG vcaddr,vaddro;	//current inst virtual addr            //~v220R~
    int   keepsw;                                                  //~v220R~
    UCHAR *pc,ch;                                                  //~v275R~
    DISAS_CALLBACK *pcbfunc;                                       //~v5i1I~
//******************************                                   //~v213I~
    caseno=Ppdar->DARdapcaseno;                                    //~v213R~
    pdap=Ppdar->DARpdap;                                           //~v213I~
    switch (caseno)                                                //~v213I~
    {                                                              //~v213I~
    case DAPCASE_INIT:  				//called from udaitsrch    //~v236R~
//        if (pdap->DAPsignature==IMAGE_NT_SIGNATURE  //PE         //~v246R~
//        ||  pdap->DAPsignature==IMAGE_NT_SIGNATURE  //LE         //~v246R~
//        ||  pdap->DAPsignature==E32MAGIC            //LX         //~v246R~
//        ||  pdap->DAPsignature==NEMAGIC)            //NE         //~v246R~
			Ppdar->DARdapcaseno=DAPCASE_AFTERSETOPD;               //~v236R~
        break;                                                     //~v213I~
    case DAPCASE_AFTERSETOPD:             //called from dainst after dasetopd,before line edit//~v236R~
                                                                   //~v243I~
//*search adcon after indirect ptr                                 //~v243I~
                                                                   //~v243I~
    	plabt=Ppdar->DARplabt;                                     //~v214R~
        if (Ppdar->DARstat & DARSO32)   //opd size 32              //~v220I~
            opdsz=4;                                               //~v220I~
        else                                                       //~v220I~
          if (Sdosfarsw)                                           //~v246I~
            opdsz=4;                                               //~v246I~
          else                                                     //~v246I~
            opdsz=2;                                               //~v220I~
//        if (pdap->DAPsignature==IMAGE_NT_SIGNATURE)              //~v220R~
//        {                                                        //~v220R~
            bstart=(ULONG)pdap->DAPsaddr;	//buff start           //~v213I~
//          bend=(ULONG)pdap->DAPeaddr-4;   //buff end             //~v220R~
            bend=(ULONG)pdap->DAPeaddr-opdsz;//buff end            //~v220I~
            vbase=(ULONG)pdap->DAPbase;     //vitrual base of buff start//~v213I~
            vend=vbase+bend-bstart;         //virtual addr of buffend//~v213R~
            vpaddr=(ULONG)Ppdar->DARdisp;   //virtual adcon addr   //~v213R~
            bpaddr=vpaddr-vbase+bstart;     //adcon addr on buff   //~v213I~
	        vcaddr=vbase+(ULONG)Ppdar->DARcaddr-(ULONG)Ppdar->DARsaddr;//~v220R~
            destswo=0;       //1:backword,2:formard                //~v220R~
            vaddro=0 ;                                             //~v220I~
//*linker v6 IAT reference;set RELOC ****************              //~v309R~
            if (pdap->DAPsignature==IMAGE_NT_SIGNATURE) //PE       //~v309I~
            {                                                      //~v309I~
//printf("vpaddr=%08x,vbase=%08x,vcaddr=%08x,Pdarinstlen=%08x\n",  //~v309R~
//        vpaddr,vbase,vcaddr,Ppdar->DARinstlen);                  //~v309R~
                if ((*(Ppdar->DARcaddr+1)&(DA_MASK_MOD|DA_MASK_RM))==0x05)//disp32//~v309R~
                    //15=mod=00,nnn=2(call);r/m=5(disp32)          //~v5i1I~
    		    if (plabt)                                         //~v309I~
              {                                                    //~v5i1I~
            	if (vpaddr>=vbase && vpaddr<vend)//adcon vaddr     //~v309I~
                {                                                  //~v309I~
                	pc=plabt+vpaddr-vbase;                         //~v309I~
                    if ((*pc & (LABT_ADCON4|LABT_RELOC))           //~v309I~
                        ==(LABT_ADCON4|LABT_RELOC))//set by labt init//~v309I~
                    {                                              //~v309I~
                		pc=plabt+vcaddr+2-vbase;   //of disp32 addr//~v309R~
//printf("Reloc *pc=%02x\n",*pc);                                  //~v309R~
    	        		if (*pc==LABT_NONE)  //initial             //~v309I~
                        	*pc=LABT_RELOC;                        //~v309I~
                        return 0;		//done                     //~v309I~
                    }                                              //~v309I~
				}                                                  //~v309I~
                else //adcon is out of section                     //~v5i1I~
                {                                                  //~v5i1I~
				    pcbfunc=pdap->DAPpcbfunc;                      //~v5i1R~
                	if (pcbfunc(CB_ADCONCHK,Ppdar,(void*)vpaddr,0))//defined on import table//~v5i1R~
                    {                                              //~v5i1I~
                		pc=plabt+vcaddr+2-vbase;   //of disp32 addr//~v5i1I~
    	        		if (*pc==LABT_NONE)  //initial             //~v5i1I~
                        	*pc=(LABT_RELOC);          //like as relocation data exist//~v5i1R~
                        return 0;		//done                     //~v5i1I~
                    }                                              //~v5i1I~
                }                                                  //~v5i1I~
              }                                                    //~v5i1I~
            }                                                      //~v309I~
//**********                                                       //~v309I~
                                                                   //~v243I~
//            if (pdap->DAPsignature==IMAGE_NT_SIGNATURE)          //~v243R~
//            {                                                    //~v243R~
//                pc=plabt+vcaddr+Ppdar->DARdumplen[0]-vbase;//set on operand//~v243R~
//                if (*pc==LABT_NONE)                              //~v243R~
//                    *pc=LABT_RELOC;         //process as import at CBFUNC//~v243R~
//            }                                                    //~v243R~
//                                                                 //~v243R~
//          for (ii=0;;ii++,vpaddr+=4,bpaddr+=4)                   //~v220R~
            for (ii=0;;ii++,vpaddr+=opdsz,bpaddr+=opdsz)           //~v220I~
            {                                                      //~v213R~
    		    if (!plabt)                                        //~v220I~
            		break;                                         //~v220I~
            	if (vpaddr<=vbase || vpaddr>=vend)	//adcon addr id out of range//~v220R~
                	break;                                         //~v213I~
              if (opdsz==4)                                        //~v220I~
              {                                                    //~v246I~
                vaddr=*(ULONG*)bpaddr;                             //~v213R~
                if (Sdosfarsw)                                     //~v246R~
                {                                                  //~v254I~
//printf("Dos seg:off=%08lx,ptr offs=%08lx,vbase=%08lx,bstart=%08lx\n",//~v266R~
//  				vaddr,bpaddr-vbase,vbase,bstart);              //~v266R~
              		vaddr=DOS_MAKE_FLAT((vaddr>>16)-(USHORT)pdap->DAPrelocv,vaddr & 0xffff);	//seg:off//~v254R~
//printf("vaddr=%08lx,vend=%08lx\n",vaddr,vend);                   //~v266R~
                }                                                  //~v254I~
              }                                                    //~v246I~
              else                                                 //~v220I~
                vaddr=(ULONG)(*(USHORT*)bpaddr);                   //~v220I~
            	if (!vaddr || vaddr<vbase || vaddr>vend)	//adcon addr id out of range//~v220R~
                    break;                                         //~v213R~
//              if (plabt)                                         //~v220R~
//              {                                                  //~v220R~
				if (vaddr<vcaddr)   //backward reference           //~v220R~
                {                   //uncond for forward ref       //~v220I~
//              	if (*(plabt+vaddr-vbase)==LABT_NONE)	//not opcode,lab ref//~v275R~
                	ch=*(plabt+vaddr-vbase);                       //~v275I~
                    if (ch!=LABT_OPCODE && ch!=LABT_REF && ch!=LABT_ENTRY)//~v275I~
                    	break;                                     //~v220I~
				}                                                  //~v220I~
                if (opdsz==2)       //16bit addr                   //~v220I~
                {                                                  //~v220I~
//                  if (!(Ppdar->DARstat & DARSCSOV))	//no cs iverride//~v254R~
                    if (!(Ppdar->DARstat & DARSCSOV) 	//no cs iverride//~v254I~
                    &&  !(pdap->DAPmode & DAPMCSDS))               //~v254I~
                    	break;                                     //~v220I~
                    destsw=1+(vpaddr<vaddr);   //adcon addr:pointed addr//~v220R~
                    if (destswo && destsw!=destswo)                //~v220R~
                    {                                              //~v220R~
                        diff=(int)(vaddr-vaddro);                  //~v220R~
                        if (diff>256 ||diff<-256)                  //~v220R~
                            break;  //dest changed                 //~v220R~
                    }                                              //~v220R~
                    destswo=destsw;                                //~v220R~
                    vaddro=vaddr;   //save prev value;inst vaddr   //~v220R~
                }                                                  //~v220I~
                                                                   //~v220I~
                	pc=plabt+vpaddr-vbase;                         //~v220I~
                	keepsw=(*pc & (LABT_RELOC|LABT_ENTRY));	//save reloc/entry//~v220R~
	              	if (opdsz==4)                                  //~v220R~
                		*pc=LABT_ADCON4;	//'2' DW adcon         //~v220R~
                  	else                                           //~v220R~
                		*pc=LABT_ADCON2;	//'3' 2 byte adcon     //~v220R~
                	*pc=(UCHAR)(*pc|keepsw);                       //~v220R~
//set ref-id for refered by ADCON                                  //~v308I~
                	pc=plabt+vaddr-vbase;   //by value of ADCON    //~v308I~
    	        	if (*pc==LABT_NONE || *pc==LABT_OPCODE)  //not refered//~v308I~
                        *pc=LABT_REF;                              //~v308I~
//  			}                                                  //~v220R~
            }                                                      //~v213R~
            Ppdar->DARabsaddrcnt=ii;    //absolute addr count      //~v213R~
//        }//PE                                                    //~v220R~
        break;                                                     //~v213I~
    }                                                              //~v213I~
    return 0;                                                      //~v213R~
}//udap_aiajc                                                      //~v213I~
//*****************************************************************//~v246I~
//*absolute indirect addr Far call/jump	 support DOS only          //~v246I~
//*parm1:pdar                                                      //~v246I~
//*ret  :0                                                         //~v246I~
//*****************************************************************//~v246I~
int udap_aiajcF(PDAREQ Ppdar)                                      //~v246I~
{                                                                  //~v246I~
	PDAPARM pdap;                                                  //~v246I~
    int caseno;                                                    //~v246I~
//******************************                                   //~v246I~
    caseno=Ppdar->DARdapcaseno;                                    //~v246I~
    pdap=Ppdar->DARpdap;                                           //~v246I~
    switch (caseno)                                                //~v246I~
    {                                                              //~v246I~
    case DAPCASE_INIT:  				//called from udaitsrch    //~v246I~
        if (UCBITCHK(pdap->DAPmode,DAPMREAL))	//real mode        //~v246I~
			Ppdar->DARdapcaseno=DAPCASE_AFTERSETOPD;               //~v246I~
        break;                                                     //~v246I~
    case DAPCASE_AFTERSETOPD:             //called from dainst after dasetopd,before line edit//~v246I~
        if (!(Ppdar->DARstat & DARSCSOV)    //no cs iverride       //~v254R~
        &&  !(pdap->DAPmode & DAPMCSDS))                           //~v254I~
            break;                                                 //~v246R~
    	Sdosfarsw=1;                                               //~v246I~
		udap_aiajc(Ppdar);                                         //~v246I~
    	Sdosfarsw=0;                                               //~v246I~
    }                                                              //~v246I~
    return 0;                                                      //~v246I~
}//udap_aiajcF                                                     //~v246I~
//*****************************************************************//~v254I~
//*absolute direct addr Far call/jump	 support DOS only          //~v254I~
//*parm1:pdar                                                      //~v254I~
//*ret  :0                                                         //~v254I~
//*****************************************************************//~v254I~
int udap_directF(PDAREQ Ppdar)                                     //~v254I~
{                                                                  //~v254I~
	PDAPARM pdap;                                                  //~v254I~
    int caseno;                                                    //~v254I~
    ULONG bstart,bend,vbase,vend,vaddr,immv;                       //~v254R~
    UCHAR *plabt,*pc;                                              //~v254I~
//******************************                                   //~v254I~
    caseno=Ppdar->DARdapcaseno;                                    //~v254I~
    pdap=Ppdar->DARpdap;                                           //~v254I~
    plabt=Ppdar->DARplabt;                                         //~v254I~
    switch (caseno)                                                //~v254I~
    {                                                              //~v254I~
    case DAPCASE_INIT:  				//called from udaitsrch    //~v254I~
    	if (!plabt)                                                //~v254I~
        	break;                                                 //~v254I~
        if (UCBITCHK(pdap->DAPmode,DAPMREAL))	//real mode        //~v254I~
			Ppdar->DARdapcaseno=DAPCASE_AFTERSETOPD;               //~v254I~
        break;                                                     //~v254I~
    case DAPCASE_AFTERSETOPD:             //called from dainst after dasetopd,before line edit//~v254I~
    	immv=Ppdar->DARimmvalue;                                   //~v254R~
        vaddr=DOS_MAKE_FLAT((immv>>16)-(USHORT)pdap->DAPrelocv,immv & 0xffff);	//seg:off//~v254R~
                                                                   //~v254I~
        bstart=(ULONG)pdap->DAPsaddr;	//buff start               //~v254I~
        bend=(ULONG)pdap->DAPeaddr;     //buff end                 //~v254I~
        vbase=(ULONG)pdap->DAPbase;     //vitrual base of buff start//~v254I~
        vend=vbase+bend-bstart;         //virtual addr of buffend  //~v254I~
//printf("Dos direct Far:offset=%08lx,immv=%08lx,vbase=%08lx,vend=%08lx,vaddr=%08lx\n",//~v266R~
//  				(ULONG)Ppdar->DARcaddr-bstart,immv,vbase,vend,vaddr);//~v266R~
                                                                   //~v254I~
        if (vaddr<vbase || vaddr>=vend)                            //~v254I~
        	break;                                                 //~v254I~
        pc=plabt+vaddr-vbase;                                      //~v254I~
//      if (*pc==LABT_NONE)                                        //~v275R~
        if (*pc==LABT_NONE || *pc==LABT_OPCODE || *pc==LABT_REF || *pc==LABT_ENTRY)//~v275I~
        	*pc=LABT_REF|LABT_DOSSEG;                              //~v254R~
    }                                                              //~v254I~
    return 0;                                                      //~v254I~
}//udap_directF                                                    //~v254I~
//*****************************************************************//~v227I~
//*int xx(chk int 20 followed vxdid)                               //~v227I~
//*parm1:pdar                                                      //~v227I~
//*ret  :0                                                         //~v227I~
//*****************************************************************//~v227I~
int udap_int(PDAREQ Ppdar)                                         //~v227I~
{                                                                  //~v227I~
    int caseno;                                                    //~v227I~
    int intno;                                                     //~v271I~
	PDAPARM pdap;                                                  //~v227I~
    UCHAR *plabt,*caddr;                                           //~v227R~
//    UCHAR  *pout,*fn;                                            //~v262R~
    ULONG   eax;                                                   //~v263R~
//******************************                                   //~v227I~
    caseno=Ppdar->DARdapcaseno;                                    //~v227I~
    pdap=Ppdar->DARpdap;                                           //~v227I~
    plabt=Ppdar->DARplabt;                                         //~v227I~
    caddr=Ppdar->DARcaddr;                                         //~v262I~
    switch (caseno)                                                //~v227I~
    {                                                              //~v227I~
    case DAPCASE_INIT:  				//called from udaitsrch    //~v236R~
		intno=*(caddr+1);                                          //~v271I~
	    if (plabt                                                  //~v227R~
		&&  (caddr+5)<=Ppdar->DAReaddr                             //~v227I~
		&&  *(caddr+1)==0x20	//int 20  for VxD call from VxD    //~v236R~
		&&  pdap->DAPsignature==IMAGE_VXD_SIGNATURE)//LE           //~v236R~
        {                                                          //~v227R~
            plabt+=(ULONG)caddr-(ULONG)Ppdar->DARsaddr+2;          //~v227R~
            if (*plabt==LABT_NONE)  //at first                     //~v227R~
                *plabt=LABT_VXDSVCID; //DW VxD service id          //~v227R~
//          Ppdar->DARdapcaseno=DAPCASE_AFTERSETOPD;  //protect re-entry//~v236R~
        }                                                          //~v227R~
//  	if (*(caddr+1)==0x21)	//int 21                           //~v263R~
        	if (UCBITCHK(pdap->DAPmode,DAPMREAL)   //real mode     //~v273R~
		    ||  (pdap->DAPsignature==NEMAGIC            //NE       //~v273I~
        	  && !UCBITCHK(pdap->DAPmode,DAPM32)))	//16bit seg    //~v273I~
            {                                                      //~v271I~
		        if (intno<0x10 || (intno>=0x70 && intno <0x78))    //~v271I~
                	return 4;			//opcd err                 //~v271I~
				Ppdar->DARdapcaseno=DAPCASE_LEDIT;	//req int21 remark//~v262R~
			}                                                      //~v271I~
        break;                                                     //~v227I~
//  case DAPCASE_AFTERSETOPD:             //called from dainst after dasetopd,before line edit//~v236R~
//      break;                                                     //~v236R~
    case DAPCASE_LEDIT:             //called from dainst after dasetopd,before line edit//~v262R~
//      pout=Ppdar->DARdapparm;         //short rem pos            //~v262R~
//      if ((ULONG)caddr-(ULONG)Sahset<16)  //distance from MOV AX/AH,imm//~v262R~
//      {                                                          //~v262R~
//          al=(int)Salah[0];                                      //~v262R~
//          ah=(int)Salah[1];                                      //~v262R~
//          rc=udadfts(0x21,ah,al,&fn);         //dos func table search//~v262R~
//          if (!rc)        //AH+AL match                          //~v262R~
//              pout+=sprintf(pout,"   ;@D_%02X%02X= %s",ah,al,fn);     //short remark edit//~v262R~
//          else                                                   //~v262R~
//              if (rc==3)                                         //~v262R~
//                  pout+=sprintf(pout,"   ;@D_    = %s",fn);        //short remark edit//~v262R~
//              else                                               //~v262R~
//              {                                                  //~v262R~
//                  if (rc==4)           //AH unmatch              //~v262R~
//                      fn="Unknown";                              //~v262R~
//                  pout+=sprintf(pout,"   ;@D_%02X= %s",ah,fn);        //short remark edit//~v262R~
//              }                                                  //~v262R~
//      }                                                          //~v262R~
//      else                                                       //~v262R~
//          pout+=sprintf(pout,"   ;@D_\?\?=");        //short remark edit//~v262R~
//      *pout++=' ';                                               //~v262R~
//      Ppdar->DARdapparm=pout;         //return next output pos   //~v262R~
        if ((ULONG)caddr-(ULONG)Sahset<16)  //distance from MOV AX/AH,imm//~v262I~
        {                                                          //~v263I~
        	if ((ULONG)caddr-(ULONG)Salset<16)  //distance from MOV AX/AH,imm//~v263I~
                eax=(ULONG)*(USHORT*)(void*)Salah;      //ah+al    //~v263I~
        	else                                                   //~v263I~
          		eax=(ULONG)(((ULONG)(Salah[1])<<8)|0x00ff00ff); 			   //clear al//~v263R~
        }                                                          //~v263I~
        else                                                       //~v262I~
          	eax=0xffffffff;                                        //~v263R~
        Ppdar->DARimmvalue2=eax;                                   //~v263I~
        break;                                                     //~v262R~
    }                                                              //~v227I~
    return 0;                                                      //~v227I~
}//udap_int                                                        //~v227I~
//*****************************************************************//~v262I~
//*MOV AH,imm or MOV eAX,imm                                       //~v262I~
//*    chk next inst is int21 and set DOS func name required flag  //~v262I~
//*parm1:pdar                                                      //~v262I~
//*ret  :0                                                         //~v262I~
//*****************************************************************//~v262I~
int udap_int21AX(PDAREQ Ppdar)                                     //~v262I~
{                                                                  //~v262I~
    int caseno;                                                    //~v262R~
    UINT  immv;                                                    //~v262I~
	PDAPARM pdap;                                                  //~v262I~
    UCHAR  *caddr;                                                 //~v262I~
//******************************                                   //~v262I~
    pdap=Ppdar->DARpdap;                                           //~v262I~
    caddr=Ppdar->DARcaddr;                                         //~v262I~
    caseno=Ppdar->DARdapcaseno;                                    //~v262I~
    switch (caseno)                                                //~v262I~
    {                                                              //~v262I~
    case DAPCASE_INIT:  				//called from udaitsrch    //~v262I~
        if (UCBITCHK(pdap->DAPmode,DAPMREAL)   //real mode         //~v273R~
		||  (pdap->DAPsignature==NEMAGIC            //NE           //~v273I~
          && !UCBITCHK(pdap->DAPmode,DAPM32)))	//16bit seg        //~v273I~
			Ppdar->DARdapcaseno=DAPCASE_AFTERSETOPD;               //~v273R~
        break;                                                     //~v262I~
    case DAPCASE_AFTERSETOPD:             //called from dainst after dasetopd,before line edit//~v262I~
        immv=(UINT)Ppdar->DARimmvalue;                             //~v262I~
        switch(*caddr)                                             //~v262I~
        {                                                          //~v262I~
        case 0xB0:			//MOV AL,imm                           //~v262I~
        	Salah[0]=(UCHAR)immv;	//AL                           //~v262R~
            Salset=caddr;                                          //~v263I~
        	break;                                                 //~v262M~
        case 0xB4:			//MOV AH,imm                           //~v262I~
        	Salah[1]=(UCHAR)immv;	//AH                           //~v262R~
            Sahset=caddr;                                          //~v262I~
        	break;                                                 //~v262I~
//  	default:			//MOV AX,imm                           //~v266R~
    	case 0xB8:  		//MOV AX,imm                           //~v266I~
        	*(USHORT*)(void*)Salah=(USHORT)immv;                   //~v262R~
            Sahset=caddr;                                          //~v262R~
            Salset=caddr;                                          //~v263I~
        	break;                                                 //~v266I~
    	case 0x32:  		//XOR Gb,Eb                            //~v266I~
            if (*(caddr+1)==0xC0)   //XOR AL,AL                    //~v266I~
            {                                                      //~v266I~
	        	Salah[0]=0;		//AL                               //~v266I~
            	Salset=caddr;                                      //~v266I~
//printf("XOR AL\n");                                              //~v266R~
            }                                                      //~v266I~
            else                                                   //~v266I~
	            if (*(caddr+1)==0xE4)   //XOR AH,AH                //~v266I~
    	        {                                                  //~v266I~
	    	    	Salah[1]=0;		//AH                           //~v266I~
            		Sahset=caddr;                                  //~v266I~
//printf("XOR AH\n");                                              //~v266R~
           	 	}                                                  //~v266I~
        	break;                                                 //~v266I~
    	case 0x33:  		//XOR Gv,Ev                            //~v266I~
            if (*(caddr+1)==0xC0)   //XOR eAX,eAX                  //~v266I~
            {                                                      //~v266I~
//printf("XOR AX\n");                                              //~v266R~
        	    Sahset=caddr;                                      //~v266I~
            	Salset=caddr;                                      //~v266I~
	        	*(USHORT*)(void*)Salah=0;                          //~v266I~
            }                                                      //~v266I~
        	break;                                                 //~v266I~
		}//by inst type                                            //~v262I~
    }//by case no                                                  //~v262R~
    return 0;                                                      //~v262I~
}//udap_int21AX                                                    //~v262I~
