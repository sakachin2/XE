//CID://+v5i2R~:                                                   //+v5i2R~
//*************************************************************
//*udait.h   instruction table define/generate  macro
//*************************************************************
//v5i2:060505 (XDA)insert LineFeed after return and before enter   //+v5i2I~
//v274:990808 disas:comment level:jumponly or all                  //~v274I~
//v221:990212 disas:chk 00 after uncond jmp(jmp,ret,retf,iret) for DB not ADD//~v221I~
//*************************************************************    //~v221I~
//*processor
typedef int (INSTPROC)(PDAREQ Ppdar);	//process instruction
typedef INSTPROC *PINSTPROC;
//*inst tbl
typedef struct _INSTTBL         //instruction define
         {
            UCHAR               DAIopcode[4];
            UCHAR 			   *DAImn;		//MNEMONIC
#define         DAIMN_CONCAT  0x01         //concatinate mnemonic
            UCHAR 			   *DAIrem;	//remarks
//*first byte is rem type
#define         DAIRT_LF1     '\r'         //concatinate mnemonic  //+v5i2I~
#define         DAIRT_LF2     '\n'         //comment level=1       //+v5i2I~
#define         DAIRT_CONCAT  0x01         //concatinate mnemonic
#define         DAIRT_CMLVL1  0x02         //comment level=1       //~v274I~
#define         DAIRT_CONST     	'c'         //constant
#define         DAIRT_RUNARY    	'r'         //right unary like as AX++
#define         DAIRT_LUNARY    	'l'         //right unary like as ++AX
#define         DAIRT_BINARY    	'2'         //binary operator
#define         DAIRT_EDIT      	'e'         //edit needed
            UCHAR 			    DAIopdstr[3][4];   //operand type string
            UINT         		DAIopdf[3]; 	//op1 opd amode/size
//*operand type flags
#define   		DAIOT_fSZATTR 	0x8000      //opd width by operand/addr size attr
#define   		DAIOT_fOPDSZ  	0x4000      //opd vary operand size attr
#define   		DAIOT_fADRSZ  	0x2000      //opd vary addr    size attr
#define   		DAIOT_fSIGNEXP	0x1000      //imm value sign expand//~8314I~
#define   		DAIOT_fTPMASK  	0x0f00      //type mask1
#define   		DAIOT_fIDMASK  	0x00ff      //type mask2
#define   		DAIOT_tMRMREG 	0x0100      //reg opd of modrm
#define   		DAIOT_tMRMMEM	0x0200      //memory opd of modrm
#define   		DAIOT_tIMMVAL 	0x0300      //immediate value
#define   		DAIOT_NOOPD  	   'N'      //no operand
#define   		DAIOT_FIXED  	   'F'      //fixed operand
#define   		DAIOT_IV  		   'I'      //immediate opd
#define   		DAIOT_OFFS		   'O'      //offset
#define   		DAIOT_RELO		   'J'      //relative offset      //~8321I~
#define   		DAIOT_ADDR		   'A'      //direct address
#define   		DAIOT_MEM    	   'M'      //modrm memory
#define   		DAIOT_MEMREG  	   'E'      //modrm memory/reg
#define   		DAIOT_DSSI   	   'X'      //implicit DS:SI
#define   		DAIOT_ESDI   	   'Y'      //implicit ES:DI
#define         DAIOT_EREG         'e'      //eAX etc,vary by operand size
#define         DAIOT_SREG         's'      //reg seg reg
#define 		DAIOT_CREG         'c'      //reg is ctl rerg
#define 		DAIOT_DREG         'd'      //reg is debug reg
#define         DAIOT_GREG         'g'      //reg is general reg
#define 		DAIOT_TREG         't'      //reg is trace reg
#define 		DAIOT_FPST0        '0'      //FPU stack top
#define 		DAIOT_FPSTi        'i'      //FPU stack(i)
//*operand size
            UINT                DAIopdsz[3]; 	//operand size
#define 		DAIOS_BYADRSZ      0x0402   //for imm value by adrsize attr//~8316I~
#define 		DAIOS_HMASK        0xff00   //mask for length vary by mode
#define 		DAIOS_HSHIFT       8
#define 		DAIOS_LMASK        0x00ff   //mask for length vary by mode
#define DAIGETLSZ(opdsz) ( (opdsz) & DAIOS_LMASK )
#define DAIGETHSZ(opdsz) ( ((opdsz) & DAIOS_HMASK)>>DAIOS_HSHIFT )
            UINT         		DAIinsttyp;  	//instruction type

#define 		DAIIT_MODRM      0x8000           //MODRM exist
#define         DAIIT_MEMONLY    0x2000
#define         DAIIT_REGONLY    0x1000
#define         DAIIT_PREFIX     0x0800
#define         DAIIT_ADDRSZ     0x0001           //addr size prefix
#define         DAIIT_OPDSZ      0x0002           //opearnd size prefix
#define         DAIIT_WAIT       0x0004           //wait prefix for FPU
#define         DAIIT_UCJMP      0x0010           //uncond jmp     //~v221I~
            UINT         		DAIclass;	//instruction class
#define         DAIIC_186        0x0001
#define         DAIIC_286        0x0002
#define         DAIIC_386        0x0003
#define         DAIIC_486        0x0004
#define         DAIIC_P5         0x0005
#define         DAIIC_387        0x0008
#define         DAIIC_GROUP      0x000f      //grop table ptr
#define         DAIIC_MMX        0x0010
#define         DAIIC_MMASK      0x00ff      //machine level mask
#define         DAIIC_PREV       0x0100      //previleage
#define         DAIIC_FPU        0x0200      //floating point
#define         DAIIC_PL0        0x0400      //priviledge level 0
#define         DAIIC_PL1        0x0800      //priviledge level 1
#define         DAIIC_PROT       0x1000      //protect mode only
#define         DAIIC_RARE       0x2000      //rarely used inst
#define         DAIIC_IMASK      0xff00      //inst type mask
            	PINSTPROC        DAIpfunc;
         } INSTTBL,*PINSTTBL;
//********************************************************************
#define  ITGEN(OPID,OP,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)  \
        static INSTTBL Sid_##OPID=                                  \
                {#OP,                                   /*opcode*/  \
                 Smn_##MN,                              /*MNEMONIC*/\
                 Srem_##MN##REMTYP,                    /*remarks*/\
             {{#OPD1},{#OPD2},{#OPD3}},                /*opd*/ \
             {OPDTP_##OPD1,OPDTP_##OPD2,OPDTP_##OPD3}, /*operand fmt*/\
             {OPDSZ_##SZ1,OPDSZ_##SZ2,OPDSZ_##SZ3},     /*opearnd size*/\
             INSTT_##OPD1 | INSTT_##OPD2 | INSTT_##OPD3,/*inst type flag*/\
             ICLS_##CLS1|ICLS_##CLS2|ICLS_##CLS3,/*instruction class*/\
             udap_##SUBRTN                  /*instruction subfunction*/   \
                        }
//with additional INST TYPE                                        //~v221I~
#define  ITGEN_IT(OPID,OP,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN,INSTTP)  \
        static INSTTBL Sid_##OPID=                                  \
                {#OP,                                   /*opcode*/  \
                 Smn_##MN,                              /*MNEMONIC*/\
                 Srem_##MN##REMTYP,                    /*remarks*/\
             {{#OPD1},{#OPD2},{#OPD3}},                /*opd*/ \
             {OPDTP_##OPD1,OPDTP_##OPD2,OPDTP_##OPD3}, /*operand fmt*/\
             {OPDSZ_##SZ1,OPDSZ_##SZ2,OPDSZ_##SZ3},     /*opearnd size*/\
             INSTT_##OPD1 | INSTT_##OPD2 | INSTT_##OPD3 |INSTTP,/*inst type flag*/\
             ICLS_##CLS1|ICLS_##CLS2|ICLS_##CLS3,/*instruction class*/\
             udap_##SUBRTN                  /*instruction subfunction*/   \
                        }                                          //~v221I~
//*for 1 byte opc
#define  ITGN1(OP,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)  \
         ITGEN(OP,\x##OP,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)
//*for 1 byte opc bith additional INST_TYPE                        //~v221I~
#define  ITGNX(OP,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN,INSTTP)  \
         ITGEN_IT(OP,\x##OP,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN,INSTTP)//~v221I~
//*for OS/2 compiler bug;1E,2E etc chked as floating constant
#define  ITGNE(OPL,OPR,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)  \
         ITGEN(OPL##OPR,\x##OPL##OPR,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)
//*for 2 byte opc
#define  ITGN2(OP1,OP2,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)  \
         ITGEN(OP1##OP2,\x##OP1\x##OP2,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)
//*for 2 byte opc  with INST TYPE                                  //~v221I~
#define  ITGNY(OP1,OP2,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN,INSTTP)  \
         ITGEN_IT(OP1##OP2,\x##OP1\x##OP2,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN,INSTTP)//~v221I~
//*for OS/2 compiler bug;1E,2E etc chked as floating constant
#define  ITGNF(OP1,OP2L,OP2R,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)  \
         ITGEN(OP1##OP2L##OP2R,\x##OP1\x##OP2L##OP2R,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)
//*for 3 byte opc
#define  ITGN3(OP1,OP2,OP3,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)  \
         ITGEN(OP1##OP2##OP3,\x##OP1\x##OP2\x##OP3,MN,OPD1,SZ1,OPD2,SZ2,OPD3,SZ3,CLS1,CLS2,CLS3,REMTYP,SUBRTN)
#define OPDTP_0        DAIOT_NOOPD
#define OPDSZ_0        0
#define INSTT_0        0
#define ICLS__         0
//*************************************************************
//*set instruction type by operand-id parm ********************
//*************************************************************
//**addressing mode
//* A:direct addr,no modRM                              far JMP (EA,o0,o1,s0,s1)
//* C:reg in modRM is control reg       MOV (0F,20,modRM)
//* D:reg in modRM is debug   reg       MOV (0F,21,modRM)
//* E:opcode+modRM
//* F:flag reg
//* G:reg in modRM is general reg       ADD (00)
//* I:immediate data
//* J:have relative offset              JMP short (77,r0)
//* K:immediate data for sign expand                               //~8331I~
//* M:modRM is memory only              BOUND (62,modRM,d0,d1)
//* m:                                  INVLP
//* O:no modRM,offset only              MOV (A0,d0,d1)
//* R:mod of modRM is general reg only  MOV (0F,20,modRM)
//* S:mod of modRM is seg reg           MOV (8c,modRM,d0,d1)
//* T:mod of modRM is test reg          MOV (0F,24,modRM)
//* X:memory addr by DS:SI              MOVS (A4)
//* Y:memory addr by ES:DI              MOVS (A4)
//*
//* AS:addr size prefix
//* OS:addr size prefix
//*************************************************************
//opd type
#define OPDTP_A                  DAIOT_tIMMVAL|DAIOT_ADDR
#define OPDTP_C                  DAIOT_tMRMREG|DAIOT_CREG
#define OPDTP_D                  DAIOT_tMRMREG|DAIOT_DREG
#define OPDTP_E                  DAIOT_tMRMMEM|DAIOT_MEMREG
#define OPDTP_F                  DAIOT_fOPDSZ |DAIOT_NOOPD
#define OPDTP_G                  DAIOT_tMRMREG|DAIOT_GREG
#define OPDTP_I                  DAIOT_tIMMVAL|DAIOT_IV
#define OPDTP_J                  DAIOT_tIMMVAL|DAIOT_fOPDSZ|DAIOT_fSIGNEXP|DAIOT_RELO//~8321R~
#define OPDTP_K                  DAIOT_tIMMVAL|DAIOT_fSIGNEXP|DAIOT_IV//~8331R~
#define OPDTP_M                  DAIOT_tMRMMEM|DAIOT_MEM
#define OPDTP_m                  DAIOT_tMRMMEM|DAIOT_MEM
#define OPDTP_O                  DAIOT_tIMMVAL|DAIOT_fADRSZ|DAIOT_OFFS
#define OPDTP_R                  DAIOT_tMRMMEM|DAIOT_GREG//reg by rm//~8314R~
#define OPDTP_S                  DAIOT_tMRMREG|DAIOT_SREG
#define OPDTP_T                  DAIOT_tMRMREG|DAIOT_TREG
#define OPDTP_X                  DAIOT_DSSI
#define OPDTP_Y                  DAIOT_ESDI

#define OPDTP_AL                 DAIOT_FIXED
#define OPDTP_AH                 DAIOT_FIXED
#define OPDTP_BL                 DAIOT_FIXED
#define OPDTP_BH                 DAIOT_FIXED
#define OPDTP_CL                 DAIOT_FIXED
#define OPDTP_CH                 DAIOT_FIXED
#define OPDTP_DL                 DAIOT_FIXED
#define OPDTP_DH                 DAIOT_FIXED
#define OPDTP_AX                 DAIOT_FIXED
#define OPDTP_BX                 DAIOT_FIXED
#define OPDTP_CX                 DAIOT_FIXED
#define OPDTP_DX                 DAIOT_FIXED
#define OPDTP_DI                 DAIOT_FIXED
#define OPDTP_SI                 DAIOT_FIXED
#define OPDTP_BP                 DAIOT_FIXED
#define OPDTP_SP                 DAIOT_FIXED
#define OPDTP_eAX                DAIOT_fOPDSZ|DAIOT_EREG
#define OPDTP_eBX                DAIOT_fOPDSZ|DAIOT_EREG
#define OPDTP_eCX                DAIOT_fOPDSZ|DAIOT_EREG
#define OPDTP_eDX                DAIOT_fOPDSZ|DAIOT_EREG
#define OPDTP_eSP                DAIOT_fOPDSZ|DAIOT_EREG
#define OPDTP_eBP                DAIOT_fOPDSZ|DAIOT_EREG
#define OPDTP_eSI                DAIOT_fOPDSZ|DAIOT_EREG
#define OPDTP_eDI                DAIOT_fOPDSZ|DAIOT_EREG
#define OPDTP_EAX                DAIOT_FIXED
#define OPDTP_EBX                DAIOT_FIXED
#define OPDTP_ECX                DAIOT_FIXED
#define OPDTP_EDX                DAIOT_FIXED
#define OPDTP_ESP                DAIOT_FIXED
#define OPDTP_EBP                DAIOT_FIXED
#define OPDTP_ESI                DAIOT_FIXED
#define OPDTP_EDI                DAIOT_FIXED
#define OPDTP_CS                 DAIOT_FIXED
#define OPDTP_DS                 DAIOT_FIXED
#define OPDTP_ES                 DAIOT_FIXED
#define OPDTP_FS                 DAIOT_FIXED
#define OPDTP_GS                 DAIOT_FIXED
#define OPDTP_SS                 DAIOT_FIXED

#define OPDTP_WT                 DAIOT_NOOPD
#define OPDTP_AS                 DAIOT_NOOPD
#define OPDTP_OS                 DAIOT_NOOPD
#define OPDTP_SO                 DAIOT_NOOPD    //segment override //~8314I~
#define OPDTP_RP                 DAIOT_NOOPD    //repaet prefix    //~8314I~
#define OPDTP_LP                 DAIOT_NOOPD    //lock prefix      //~8314I~

#define OPDTP_3                  DAIOT_FIXED
#define OPDTP_1                  DAIOT_FIXED
//inst type
#define INSTT_A                  0
#define INSTT_C                  DAIIT_MODRM
#define INSTT_D                  DAIIT_MODRM
#define INSTT_E                  DAIIT_MODRM
#define INSTT_F                  0
#define INSTT_G                  DAIIT_MODRM
#define INSTT_I                  0
#define INSTT_J                  0
#define INSTT_K                  0                                 //~8331I~
#define INSTT_M                  DAIIT_MODRM|DAIIT_MEMONLY
#define INSTT_m                  DAIIT_MODRM|DAIIT_MEMONLY
#define INSTT_O                  0
#define INSTT_R                  DAIIT_MODRM|DAIIT_REGONLY
#define INSTT_S                  DAIIT_MODRM                       //~8331R~
#define INSTT_T                  DAIIT_MODRM                       //~8331R~
#define INSTT_X                  0
#define INSTT_Y                  0
#define INSTT_1                  0	//constant 1
#define INSTT_3                  0

#define INSTT_AL                 0
#define INSTT_AH                 0
#define INSTT_BL                 0
#define INSTT_BH                 0
#define INSTT_CL                 0
#define INSTT_CH                 0
#define INSTT_DL                 0
#define INSTT_DH                 0
#define INSTT_AX                 0
#define INSTT_BX                 0
#define INSTT_CX                 0
#define INSTT_DX                 0
#define INSTT_SI                 0
#define INSTT_DI                 0
#define INSTT_BP                 0
#define INSTT_SP                 0
#define INSTT_eAX                0
#define INSTT_eBX                0
#define INSTT_eCX                0
#define INSTT_eDX                0
#define INSTT_eSP                0
#define INSTT_eBP                0
#define INSTT_eSI                0
#define INSTT_eDI                0
#define INSTT_EAX                0
#define INSTT_EBX                0
#define INSTT_ECX                0
#define INSTT_EDX                0
#define INSTT_ESP                0
#define INSTT_EBP                0
#define INSTT_ESI                0
#define INSTT_EDI                0
#define INSTT_CS                 0
#define INSTT_DS                 0
#define INSTT_ES                 0
#define INSTT_FS                 0
#define INSTT_GS                 0
#define INSTT_SS                 0

#define INSTT_AS                 DAIIT_PREFIX|DAIIT_ADDRSZ
#define INSTT_OS                 DAIIT_PREFIX|DAIIT_OPDSZ
#define INSTT_SO                 DAIIT_PREFIX       //segment override//~8314I~
#define INSTT_RP                 DAIIT_PREFIX       //repeat prefix//~8314I~
#define INSTT_LP                 DAIIT_PREFIX       //lock   prefix//~8314I~
#define INSTT_WT                 DAIIT_PREFIX|DAIIT_WAIT
//*************************************************************
//**opd size
//* a:2 WORD or 2 DWORD by opdsize attr    (BOUND only)
//* b:byte size
//* c:byte or word by opdsize attr
//* d:DWORD
//* p:32bit or 48bit ptr by opdsize attr
//* qd:dword or qward by opdsize attr
//* s:6 byte psude descripter
//* u:BYTE or WORD by opdsize attr        @@@@@
//* v:WORD or DWORD by opdsize attr
//* w:WORD
//*************************************************************
//**
#define OPDSZ_a            0x0804                                  //~8321R~
#define OPDSZ_b                 1
#define OPDSZ_c            0x0201   //byte or word
#define OPDSZ_d                 4
#define OPDSZ_p            0x0604   //16:16 or 16:32
#define OPDSZ_qd           0x0804    //DWORD or QWORD
#define OPDSZ_s                 6   //from descriptor
#define OPDSZ_v            0x0402	//WORD or DWORD
#define OPDSZ_w                 2
//*************************************************************
//*instruction class
//************************************************************
//REAL mode:select PL=1(I/O)
//PROT mode:select not classified inst grp unless srequested
//          (P0,P1,P3,PP is converted to DB)
//*************************************************************
#define ICLS_186        DAIIC_186
#define ICLS_286        DAIIC_286
#define ICLS_386        DAIIC_386
#define ICLS_387        DAIIC_387
#define ICLS_486        DAIIC_486
#define ICLS_P5         DAIIC_P5
#define ICLS_MMX        DAIIC_MMX
#define ICLS_FPU        DAIIC_FPU    //floating
#define ICLS_P0         DAIIC_PL0    //previleadge level 0
#define ICLS_P1         DAIIC_PL1    //previleadge level 1(I/O)
#define ICLS_P3         DAIIC_RARE   //PL=3 but rarely used inst
#define ICLS_PP         DAIIC_PROT   //prot mode only
#define ICLS_GRP        DAIIC_GROUP  //prot mode only
//*************************************************************
#define  udap_0         0
INSTPROC udap_2Byte;
INSTPROC udap_GrpFpu;
INSTPROC udap_Grp1;
INSTPROC udap_Grp2;
INSTPROC udap_Grp3;
INSTPROC udap_Grp4;
INSTPROC udap_Grp5;
INSTPROC udap_Grp6;
INSTPROC udap_Grp7;
INSTPROC udap_Grp8;

INSTPROC udap_GrpAAM;
INSTPROC udap_GrpAAD;
