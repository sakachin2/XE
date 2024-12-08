//CID://+v5i2R~:                                                   //+v5i2R~
//*************************************************************
//*xuasub.h
//*************************************************************
//v5i2:060505 (XDA)insert LineFeed after return and before enter   //+v5i2I~
//v262:990704 disas:set DOS int 21 comment                         //~v262I~
//v246:990620 disas:DOS MZ support                                 //~v246I~
//v236:990501 disas:int20 VxD service name display                 //~v236I~
//v223:990213 disas:callback func for reloc data proc for each magic//~v223I~
//v221:990212 disas:chk 00 after uncond jmp(jmp,ret,retf,iret) for DB not ADD//~v221I~
//v220:990212 disas:support indirect branch for also LX/NE         //~v220I~
//v214:981227 disas:use labt for 1-path disas(foward label)        //~v214I~
//v213:981226 disas:adcon chk for indirect call/jump               //~v213I~
//v212:981223 disas:import name display                            //~v212I~
//v210:981223 disas:code addr base support                         //~v210I~
//*************************************************************    //~v210I~
#define DA_MASK_MOD  0xc0      //mod MASK of modR/M  11.. ....
#define DA_MASK_REG  0x38      //reg MASK of modR/M  ..11 1...
#define DA_MASK_RM   0x07      //R/M MASK of modR/M  .... .111
#define DA_SHIFT_MOD    6      //shift cout for mod
#define DA_SHIFT_REG    3      //shift cout for mod
#define DA_SHIFT_RM     0      //shift cout for mod
#define UGETDAMOD(x)  ( ((x)&DA_MASK_MOD)>>DA_SHIFT_MOD )          //~8301R~
#define UGETDAMRM(x) (( ((x)&DA_MASK_MOD)>>DA_SHIFT_REG )|UGETDARM(x))//~8301R~
#define UGETDAREG(x)  ( ((x)&DA_MASK_REG)>>DA_SHIFT_REG )          //~8301R~
#define UGETDARM(x)   ( (x)&DA_MASK_RM )                           //~8301R~
//*************************************************************
typedef struct _DAREQ
         {
//*input
            UINT     DARopt;		//option from DAPopt           //~8328R~
            UINT     DARopt2;		//option from udisas1          //~8328I~
#define DAROPT2PH1   0x0001         //phase1                       //~8328I~
            UINT     DARmode;		//mode from DAPmode            //~8328R~
            UCHAR   *DARsaddr;		//unasm start addr
            UCHAR   *DAReaddr;	//out of boundary
            UCHAR   *DARcaddr;		//current addr
            ULONG    DARoffs;   	//caddr offset from saddr      //~v223I~
            UINT     DARclass;  	//request instruction type
            ULONG    DARoffsfrombase; //DARsaddr offset from virtual base//~v212M~
            ULONG    DARdossegoff; 	//for DOS;seg:off              //~v246I~
//*output byt con data
            UINT     DARstat;   	//current status               //~8315R~
//output from prefix(passed to next inst)                          //~8315I~
//stat from previous prefix                                        //~8315M~
#define DARSSAVEMASK 0x000f			//continue data mask           //~8304I~
#define DARSASZP     0x0001			//address size prefix effective//~8315I~
#define DARSOSZP     0x0002			//operand size prefix effective//~8315I~
#define DARSWAITP    0x0004			//wait prefix  prefix effective//~8315I~
#define DARSCSOVP    0x0008			//cs override prefix           //~v220R~
//stat output                                                      //~8315M~
#define DARSA32      0x0010			//actual address size          //~8315I~
#define DARSO32      0x0020			//actual operand size          //~8315I~
#define DARSCSOV     0x0080			//cs override effective        //~v220I~
#define DARSREGOPC   0x0100			//reg is ope code              //~8405R~
#define DARS2BYTEOPC 0x0200			//2 byte ope code              //~8301R~
#define DARSFWAIT    0x0400			//wait used as prefix          //~8315I~
#define DARSREGRM    0x1000			//r/m is reg                   //~8405I~
#define DARSJMPRO    0x2000			//imm value is jump relative offset//~8321R~
#define DARSNOREGSIB 0x4000			//no reg and no sib            //~v212R~
#define DARSOPCDERRD 0x8000			//opecode err dump             //~8308I~
#define DARMAXDUMP   12                                            //~8308I~
#define DARMAXDUMP_DB 8             //dump width for "DB"          //~v221I~
            UINT     DARstat2;  	//current status               //+v5i2I~
#define DARS2LF1     0x8000			//insert LF before print line  //+v5i2I~
#define DARS2LF2     0x4000			//insert LF after  print line  //+v5i2I~
            UCHAR    DARdump[DARMAXDUMP];   //code dump            //~8308I~
//*******                                                          //~v213I~
            PDAPARM  DARpdap;			//dap addr                 //~v213M~
            UCHAR   *DARplabt;  		//label table ptr          //~v214R~
//***************************************************              //~v213R~
//*start of output area cleared before each udainst call           //~v213I~
//***************************************************              //~v213I~
            int      DARinstlen;   //instlen,0 if unknown op code
            int      DARdumplen[3];//opecode len,opc/mod/sib,disp,imm//~8308R~
            int      DARmemsize;   	//modrm memory size            //~8310R~
            ULONG    DARdisp;   	//displacement for opd         //~v212R~
            ULONG    DARimmvalue; 	//immediate value              //~v212R~
            ULONG    DARimmvalue2; 	//for 6byte imm value          //~v212R~
            UCHAR    DARmn[8];		//mnemonic
            UCHAR    DARopd[3][32];		//operand1
            UCHAR    DARrem[64];		//remarks
            void    *DARvpit;			//pit,interface itsearch and group sub//~8308R~
            int      DARdapcaseno;  	//daproc entry id(init 0)  //~v213M~
#define     DAPCASE_INIT        0x00 //call by IT registration     //~v236R~
#define     DAPCASE_AFTERSETOPD 0x03 //called at udainst after all opd set//~v236R~
#define     DAPCASE_LEDIT       0x05 //called at udaledit with pout pos parm//~v262I~
            void    *DARdapparm;		//parm between udap and caller//~v262I~
            int      DARabsaddrcnt;		//absolute addr count      //~v213I~
            void    *DARrelocdata;      //relocation data of this inst//~v223I~
            int      DARrelocopdno;     //operand no of relocation required//~v223R~
#define     DAR_RELOCADCON      0x04    //adcon relocation         //~v223I~
#define     DAR_RELOCDISP       0x10    //displacement is relocated 5=opd1,6=opd2,..//~v223R~
         } DAREQ,*PDAREQ;
//*****************************************************************//~8301I~
int udainst(PDAREQ Ppdar);                                         //~8321I~
//*****************************************************************//~8321I~
int udanextbyte(PDAREQ Ppdar,int Pbytecnt,int Popt);               //~8304I~
