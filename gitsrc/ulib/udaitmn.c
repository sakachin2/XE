//CID://+v5i3R~:                                                   //+v5i3R~
//*************************************************************
//*udaitmn.c
//*** instruction MNEMONIC static symbol generation
//***   included into udamt.c
//*************************************************************
//v5i3:060505 (XDA)add instruction SYSENTER(0f34) and SYSEXIT(0f35)//+v5i3I~
//v320 000603:DISAS:add 0f30(WRMSR),0f31(RDTSC),0f32(RDMSR),0f33(RDPMC)//~v320I~
//v306 000422:DISAS:set OpdSz/AdrSz prefix nemonic(not DB 'F').    //~0422I~
//*************************************************************    //~0422I~
#include <udaitmn.h>
//*************************************************************
//* for instruction group
    INSTMN (2Byte   );
    INSTMN (GrpFpu  );
    INSTMN (Grp1    );
    INSTMN (Grp2    );
    INSTMN (Grp3    );
    INSTMN (Grp4    );
    INSTMN (Grp5    );
    INSTMN (Grp6    );
    INSTMN (Grp7    );
    INSTMN (Grp8    );

    INSTMN (GrpAAM  );  //1 byte opcode but next  byte is fixed
    INSTMN (GrpAAD  );  //1 byte opcode but next  byte is fixed

//****************************************************
    INSTMN (AAA     );
    INSTMN (AAD     );
    INSTMN (AAM     );
    INSTMN (AAS     );
    INSTMN (ADC     );
    INSTMN (ADD     );
    INSTMN (AND     );
    INSTMN (ARPL    );
//*-----------------
    INSTMN (BOUND   );
    INSTMN (BSF     );
    INSTMN (BSR     );
    INSTMN (BSWAP   );
    INSTMN (BT      );
    INSTMN (BTC     );
    INSTMN (BTR     );
//*-----------------
    INSTMN (BTS     );
//*-----------------
    INSTMN (CALL    );
    INSTMN2(CBW,CWDE);
    INSTMN (CLC     );
    INSTMN (CLD     );
    INSTMN (CLI     );
    INSTMN (CLTS    );
    INSTMN (CMC     );
    INSTMN (CMP     );
    INSTMN (CMPSB   );
    INSTMN2(CMPSW,CMPSD);                                          //~8321R~
    INSTMN (CMPXCHG );
//  INSTMN (CPUID   );
    INSTMNC(CS,"CS:");
    INSTMN2(CWD,CDQ);
//*-------------------
    INSTMN (DAA     );
    INSTMN (DAS     );
    INSTMN (DEC     );
    INSTMN (DIV     );
    INSTMNC(DS,"DS:");
//*-------------------
    INSTMN (ENTER   );
    INSTMNC(ES,"ES:");
//*-------------------
    INSTMNC(FS,"FS:");
//*-------------------
    INSTMNC(GS,"GS:");
//*-------------------
    INSTMN (HLT     );
//*-------------------
    INSTMN (IDIV    );
    INSTMN (IMUL    );
    INSTMN (IN      );
    INSTMN (INC     );
    INSTMN (INSB    );
    INSTMN2(INSW,INSD);
    INSTMN (INT     );
    INSTMN (INTO    );
    INSTMN (INVD    );
    INSTMN (INVLPG  );
    INSTMN2(IRET,IRETD);
//*-------------------
    INSTMN (JA      );
    INSTMN (JB      );
    INSTMN (JCXZ    );
    INSTMN (JG      );
    INSTMN (JL      );
    INSTMN (JNA     );
    INSTMN (JNB     );
    INSTMN (JNG     );
    INSTMN (JNL     );
    INSTMN (JNO     );
    INSTMN (JNP     );
    INSTMN (JNS     );
    INSTMN (JNZ     );
    INSTMN (JO      );
    INSTMN (JP      );
    INSTMN (JS      );
    INSTMN (JZ      );
    INSTMN (JMP     );
//*-------------------
    INSTMN (LAHF    );
    INSTMN (LAR     );
    INSTMN (LDS     );
    INSTMN (LEA     );
    INSTMN (LEAVE   );
    INSTMN (LES     );
    INSTMN (LFS     );
    INSTMN (LGDT    );
    INSTMN (LGS     );
    INSTMN (LIDT    );
    INSTMN (LLDT    );
    INSTMN (LMSW    );
    INSTMN (LOADALL );                                             //~8221R~
    INSTMN (LOCK    );
    INSTMN (LODSB   );
    INSTMN2(LODSW,LODSD);
    INSTMN (LOOP    );
    INSTMN (LOOPNZ  );
    INSTMN (LOOPZ   );
    INSTMN (LSL     );
    INSTMN (LSS     );
    INSTMN (LTR     );
//*-------------------
    INSTMN (MOV     );
    INSTMN (MOVSB   );
    INSTMN2(MOVSW,MOVSD);
    INSTMN (MOVSX   );
    INSTMN (MOVZX   );
    INSTMN (MUL     );
//*-------------------
    INSTMN (NEG     );
    INSTMN (NOP     );
    INSTMN (NOT     );
//*-------------------
    INSTMN (OR      );
    INSTMN (OUT     );
    INSTMN (OUTSB   );
    INSTMN2(OUTSW,OUTSD);
//*-------------------
    INSTMN (POP     );
    INSTMN2(POPA,POPAD);
    INSTMN2(POPF,POPFD);
    INSTMN (PUSH    );
    INSTMN2(PUSHA,PUSHAD);
    INSTMN2(PUSHF,PUSHFD);
//*-------------------
    INSTMN (RCL     );
    INSTMN (RCR     );
    INSTMN (RDMSR   );                                             //~v320R~
    INSTMN (RDPMC   );                                             //~v320I~
    INSTMN (RDTSC   );                                             //~v320R~
    INSTMN (REP     );
    INSTMN (REPNE   );
    INSTMN (RET     );
    INSTMN (RETF    );
    INSTMN (ROL     );
    INSTMN (ROR     );
//  INSTMN (RSM     );
//*-------------------
    INSTMN (SAHF    );
//  INSTMN (SAL     );  //same as SHL
    INSTMN (SAR     );
    INSTMN (SBB     );
    INSTMN (SCASB   );
    INSTMN2(SCASW,SCASD);
//  INSTMN (SETALC  );
    INSTMN (SETA    );
    INSTMN (SETB    );
    INSTMN (SETG    );
    INSTMN (SETL    );
    INSTMN (SETNA   );
    INSTMN (SETNB   );
    INSTMN (SETNG   );
    INSTMN (SETNL   );
    INSTMN (SETNO   );
    INSTMN (SETNP   );
    INSTMN (SETNS   );
    INSTMN (SETNZ   );
    INSTMN (SETO    );
    INSTMN (SETP    );
    INSTMN (SETS    );
    INSTMN (SETZ    );
    INSTMN (SGDT    );
    INSTMN (SHL     );
    INSTMN (SHLD    );
    INSTMN (SHR     );
    INSTMN (SHRD    );
    INSTMN (SIDT    );
    INSTMN (SLDT    );
    INSTMN (SMSW    );
    INSTMNC(SS,"SS:");                                             //~8315R~
    INSTMN (STC     );
    INSTMN (STD     );
    INSTMN (STI     );
    INSTMN (STOSB   );
    INSTMN2(STOSW,STOSD);
    INSTMN (STR     );
    INSTMN (SUB     );
    INSTMN (SYSENTER);                                             //+v5i3I~
    INSTMN (SYSEXIT );                                             //+v5i3I~
//*-------------------
    INSTMN (TEST    );
//*-------------------
    INSTMN (VERR    );
    INSTMN (VERW    );
//*-------------------
    INSTMN (WAIT    );
    INSTMN (WBINVD  );
    INSTMN (WRMSR   );                                             //~v320R~
//*-------------------
    INSTMN (XADD    );
    INSTMN (XCHG    );
    INSTMN (XLAT    );
    INSTMN (XOR     );
//*-------------------
//  INSTMNC(OpdSz,"DB");                                           //~v306R~
    INSTMNC(OpdSz,"OpdSz");                                        //~v306R~
//  INSTMNC(AddSz,"DB");                                           //~v306R~
    INSTMNC(AddSz,"AdrSz");                                        //~v306R~
//*
