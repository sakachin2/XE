//CID://+v5i5R~:                                                   //~v5i5R~
//*************************************************************
//*xua.h
//*************************************************************
//v5i5:060505 (XDA)print ucs code                                  //~v5i5I~
//v5i4:060505 (XDA)add 2nd labt for short comment of hint serach   //~v5i1I~
//v5i1:060505 (XDA)no more relocation data for mport table reference from somewhen//~v318I~
//            (import table shifted to .idata to .rdata section)   //~v318I~
//v318 000603:allow DISAS:PL1 inst for VxD                         //~v318I~
//v312 000507:DISAS:same as above for inst NOP (0x90) to save paper//~v312I~
//v300 000311:DISAS:same as above for inst int 3(0xcc) to save paper//~v300I~
//v285:990918 disas:increase default buff size for dup addr export entry//~v285I~
//v274:990808 disas:comment level:jumponly or all                  //~v274I~
//v260:990626 disas:seg:off addr is not same as real mode(for real but no seg:off required case)//~v260I~
//v246:990620 disas:DOS MZ support                                 //~v246I~
//v239:990508 disas:set abs value for reloc to other object        //~v239I~
//                  when all object base is zero.                  //~v239I~
//v236:990501 disas:int20 VxD service name display                 //~v236I~
//v229:990320 disas:entry statement for export                     //~v229I~
//v227:990228 disas:int20 follow dword vxd id                      //~v227I~
//v224:990228 disas:print subrange                                 //~v224I~
//v223:990213 disas:callback func for reloc data proc for each magic//~v223I~
//v221:990212 disas:chk 00 after uncond jmp(jmp,ret,retf,iret) for DB not ADD//~v221I~
//v220:990212 disas:support indirect branch for also LX/NE         //~v217I~
//v217:990108 disas:change v216;-1 for current buff addr           //~v217I~
//v216:990108 disas:base 0 id(-1)                                  //~v216I~
//v215:990103 disas:LX relocation support                          //~v215I~
//v214:981227 disas:use labt for 1-path disas(foward label)        //~v214I~
//v213:981226 disas:adcon chk for indirect call/jump               //~v213I~
//v212:981223 disas:import name display                            //~v212I~
//v210:981223 disas:code addr base support                         //~v210I~
//*************************************************************
#define DFLTBUFSZ    32768                                         //~v285I~
//call back func for reloc proc                                    //~v223I~
typedef int (DISAS_CALLBACK)(int Pcase,void *Pprm1,void *Pprm2,ULONG Pprm3);//~v223R~
#define CB_LABTINIT     1   //at after labt init:p1=pdap,p2=plabt  //~v223R~
#define CB_CHKRELOC     2   //chk immedeate value by reloc data    //~v223I~
#define CB_SHORTREM     3   //set short remark before remark       //~v223R~
#define CB_ADCON        4   //chk referenced adcon                 //~v223R~
#define CB_ENTRY        5   //exported entry                       //~v229I~
#define CB_SHORTREMDB   6   //for vxd name                         //~v236I~
#define CB_TERMRELOC    9   //at end of disas,chk all reloc rec used//~v223R~
#define CB_ADCONCHK    10   //more relocation chk(PE import tbl serch)//~v5i1R~
                                                                   //~v236I~
#define CB_RCINTR       1   //internal reference                   //~v223R~
#define CB_RCIMPORT     2   //import data is output                //~v223I~
#define CB_RCRINTRO     3   //internal ref to other object and objbase is 0//~v239I~
#define CB_RCERR        4   //reloc rec err                        //~v223I~
                                                                   //~v223I~
typedef struct _DAPARM
         {
//************************************************************     //~v213I~
//*following is user parm                                          //~v213I~
//************************************************************     //~v213I~
            UINT     DAPopt;		//option
#define DAPOPPUTF    0x0001         //output to file
#define DAPOPFCONT   0x0002         //continue even if not defined isnt
#define DAPOPSTART   0x0004         //new da start
#define DAPOP2PHASE  0x0008         //2 phase analysis for label   //~8321R~
#define DAPOPLOWADR  0x0100         //addr by lowwer char
#define DAPOPLOWDMP  0x0200         //dump by lowwer char
#define DAPOPLOWOPD  0x0400         //opd  by lowwer char
#define DAPOPADKANA  0x0800         //asciidump KANA
#define DAPOPADSBCS  0x1000         //ascii dump no dbcs
#define DAPOPNOADDR  0x2000         //no addr,addr col is for label only//~8321I~
#define DAPOPCMLVL1  0x4000         //instruction comment is branch only//~v274R~
#define DAPOPADUCS   0x8000         //ascii dump +ucs dump         //~v5i5I~
            UINT     DAPmode;		//0:16 bit,1:32 bit
#define DAPM32       0x0001         //32 bit
#define DAPMREAL     0x0002         //REAL mode
#define DAPMCSDS     0x0004         //assume cs=ds(COM file)       //~v246I~
#define DAPMSEGOFFA  0x0008         //addr by seg:off fmt also     //~v260R~
            UCHAR   *DAPbase ;		//unasm start addr(base virtual addr)//~v217R~
            UCHAR   *DAPsaddr;		//unasm code buff start addr   //~8C23R~
            UCHAR   *DAPeaddr;		//unasm code buff end   addr   //~8C23R~
            UCHAR   *DAPsaddrp;		//print start addr or 0 if all //~v224R~
            UCHAR   *DAPeaddrp;	    //print end addr               //~v224R~
            UINT     DAPitype;  		//request instruction type
#define DAPITDOS     0x0001     //dos,iclude pl1 and exclude prot only
#define DAPITFPU     0x0100     //fpu
#define DAPITFULL    0x0200     //full function except fpu
#define DAPITPL1     0x0400     //PL1 for VxD                      //~v318I~
            FILE    *DAPfh;
            UCHAR   *DAPoutbuff;	//out area with last \n\0 for no fileout case//~8C23R~
            int      DAPoutbufflen; //out area len for no file out;//~8C23R~
            int      DAPoutlen; 	//output len containing last \n
            int      DAPaddrpos;    //addr/label column,0:default,<0 if not required//~8321R~
            int      DAPdumppos;    //hex dump
            int      DAPopcpos;   	//mnemonic code out col
            int      DAPopdpos;	   	//operand out col
            int      DAPrempos;    	//remark out col
            int      DAPadumppos;   //ascii dump col
            int      DAPint3maxlen; //continuous int 3(cc)/Nop(90) to budle to a line(same as above)//~v312R~
#define DAI3_MAX     4                                             //~v300I~
            USHORT   DAPsignature;  //                             //~v213M~
            USHORT   DAPrsv2;                                      //~v246I~
//          void    *DAPimpinfo; //import information              //~v223R~
//          void    *DAPrelocinfo;//array of ptr to r32_rlc        //~v223R~
            DISAS_CALLBACK *DAPpcbfunc;	//callback func addr       //~v223I~
            void    *DAPpcbparm;         //parm for callback func  //~v223R~
            ULONG    DAPrelocv;		 //relocation value            //~v246I~
         } DAPARM,*PDAPARM;
//*****************************************************************
//*default output column size
#define DAOL_ADDR      10     //_xxxxxxxx                          //~v246R~
#define DAOL_ADDRREAL  20     //_xxxxxxxx xxxx:xxxx                //~v246I~
#define DAOL_DUMP      18     //8+1+8+1 opc(1-2),modrm,sib,disp/imm//~8321R~
                              //or 1+1+12+1 (call 16:32 addr)      //~8321R~
#define DAOL_MN         8     //7+1
#define DAOL_OPD       30     //20(disp32[EBP][ECX*8])+8(WORD PTR)
#define DAOL_REM       30     //remarks
#define DAOL_ADUMP     24     //ascii dump
                                                                   //~v217I~
#define LABT_NONE       0     //none of following                  //~v220I~
#define LABT_TYPEMASK  0x07   //reloc required                     //~v223I~
#define LABT_OPCODE     1     //opecode start                      //~v223R~
#define LABT_REF        2     //refered position                   //~v223R~
#define LABT_ADCON4     3     //DWORD adcon                        //~v223R~
#define LABT_ADCON2     4     //WORD adcon                         //~v223R~
#define LABT_VXDSVCID   5     //DWORD VxD service id               //~v227I~
#define LABT_DB         7     //opecode err                        //~v223I~
#define LABT_RELOC     0x80   //reloc required                     //~v223M~
#define LABT_OFFS16    0x08   //with reloc,16bit reloc source      //~v223R~
#define LABT_ENTRY     0x40   //entry record                       //~v223I~
#define LABT_DOSSEG    0x20   //chk dos segment start              //~v246I~
                                                                   //~v5i1I~
#define LABT2_RELOCDATA  0x01   //LABT_RELOC flag set by relocation data//+v5i5R~
#define LABT2_UCSCODE1   0x02   //ucs constant string detected     //~v5i5R~
#define LABT2_UCSCODE2   0x04   //2nd byte of ucs code             //~v5i5I~
//*****************************************************************
int udisas(PDAPARM Ppdap);
#define DARC_OPCDERRD   1   //ope code err dump
#define DARC_TYPEERR    4   //type mismatch
#define DARC_OPCDERR    8   //not valid inst
#define DARC_OUTERR    16   //file output err or buff over flow
#define DARC_PARMERR   20   //parameter err
#define DARC_MEMSHORT  24   //storage shortage                     //~8321I~
//*****************************************************************//~8411I~
//*****************************************************************//~v214I~
int udisasrevchk(PDAPARM Ppdap,UCHAR **Ppsaddr);                   //~v214I~
