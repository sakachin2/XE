//CID://+v5i3R~:                                                   //+v5i3R~
//*************************************************************
//*udait.c    instruction table generation
//*           included into udamt.c
//*************************************************************
//v5i3:060505 (XDA)add instruction SYSENTER(0f34) and SYSEXIT(0f35)//+v5i3I~
//v320 000603:DISAS:add 0f30(WRMSR),0f31(RDTSC),0f32(RDMSR),0f33(RDPMC)//~v320I~
//v266:990711 disas:chk XOR for AH/AL/AX set for DOS int           //~v265I~
//v265:990711 disas:(BUG) group function name codeing miss(grp4:er,grp5:valid)//~v265I~
//v262:990704 disas:set DOS int 21 comment                         //~v262I~
//v254:990626 disas:DOS MZ support(direct far call label ref)      //~v254I~
//v246:990620 disas:DOS MZ support                                 //~v246I~
//v227:990228 disas:int20 follow dword vxd id                      //~v227I~
//v221:990212 disas:chk 00 after uncond jmp(jmp,ret,retf,iret) for DB not ADD//~v221I~
//v219:990211 disas:allow 82 as Eb,Ib(repack.exe used,err under VC)//~v219I~
//v213:981226 disas:adcon chk for indirect call/jump               //~v213I~
//v212:981223 disas:import name display                            //~v212I~
//            opd type=e absolute indirect derived from "E"        //~v212I~
//*************************************************************
//*   OP       MN      op1,sz1,op2,sz2,op3 ,cls1,cls2,cls3,remid,subrtn//~8308R~
ITGN1(00,      ADD    ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(01,      ADD    ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(02,      ADD    ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(03,      ADD    ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(04,      ADD    ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(05,      ADD    ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
//*
ITGN1(06,      PUSH   ,ES ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
//*
ITGN1(07,      POP    ,ES ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
//*
ITGN1(08,      OR     ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(09,      OR     ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(0A,      OR     ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(0B,      OR     ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(0C,      OR     ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(0D,      OR     ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
//*
ITGNE(0,E,     PUSH   ,CS ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(0F,      2Byte  ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,2Byte);//***2 byte escape//~8308R~

ITGN1(10,      ADC    ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(11,      ADC    ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(12,      ADC    ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(13,      ADC    ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(14,      ADC    ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(15,      ADC    ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(16,      PUSH   ,SS ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(17,      POP    ,SS ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(18,      SBB    ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(19,      SBB    ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(1A,      SBB    ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(1B,      SBB    ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(1C,      SBB    ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(1D,      SBB    ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGNE(1,E,     PUSH   ,DS ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(1F,      POP    ,DS ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(20,      AND    ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(21,      AND    ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(22,      AND    ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(23,      AND    ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(24,      AND    ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(25,      AND    ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(26,      ES     ,SO ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8314R~

ITGN1(27,      DAA    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(28,      SUB    ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(29,      SUB    ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(2A,      SUB    ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(2B,      SUB    ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(2C,      SUB    ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(2D,      SUB    ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGNE(2,E,     CS     ,SO ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8314R~

ITGN1(2F,      DAS    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(30,      XOR    ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(31,      XOR    ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
//ITGN1(32,      XOR    ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,0); //~v265R~
ITGN1(32,      XOR    ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,int21AX);//~v265I~
//ITGN1(33,      XOR    ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,0); //~v265R~
ITGN1(33,      XOR    ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,int21AX);//~v265I~
ITGN1(34,      XOR    ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(35,      XOR    ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(36,      SS     ,SO ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8314R~

ITGN1(37,      AAA    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(38,      CMP    ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(39,      CMP    ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(3A,      CMP    ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(3B,      CMP    ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(3C,      CMP    ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(3D,      CMP    ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGNE(3,E,     DS     ,SO ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8314R~

ITGN1(3F,      AAS    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(40,      INC    ,eAX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(41,      INC    ,eCX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(42,      INC    ,eDX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(43,      INC    ,eBX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(44,      INC    ,eSP,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(45,      INC    ,eBP,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(46,      INC    ,eSI,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(47,      INC    ,eDI,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(48,      DEC    ,eAX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(49,      DEC    ,eCX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(4A,      DEC    ,eDX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(4B,      DEC    ,eBX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(4C,      DEC    ,eSP,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(4D,      DEC    ,eBP,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGNE(4,E,     DEC    ,eSI,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(4F,      DEC    ,eDI,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(50,      PUSH   ,eAX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(51,      PUSH   ,eCX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(52,      PUSH   ,eDX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(53,      PUSH   ,eBX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(54,      PUSH   ,eSP,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(55,      PUSH   ,eBP,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(56,      PUSH   ,eSI,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(57,      PUSH   ,eDI,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(58,      POP    ,eAX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(59,      POP    ,eCX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(5A,      POP    ,eDX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(5B,      POP    ,eBX,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(5C,      POP    ,eSP,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(5D,      POP    ,eBP,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGNE(5,E,     POP    ,eSI,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(5F,      POP    ,eDI,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(60,      PUSHA  ,0  ,0  ,0  ,0  ,0,0 ,_   ,186 ,_   ,_,0);   //~8308R~
ITGN1(61,      POPA   ,0  ,0  ,0  ,0  ,0,0 ,_   ,186 ,_   ,_,0);   //~8308R~

ITGN1(62,      BOUND  ,G  ,v  ,M  ,a  ,0,0 ,_   ,186 ,_   ,_,0);   //~8308R~

ITGN1(63,      ARPL   ,E  ,w  ,G  ,w  ,0,0 ,_   ,286 ,PP  ,_,0);//prot only//~8308R~

ITGN1(64,      FS     ,SO ,0  ,0  ,0  ,0,0 ,_   ,386 ,_   ,_,0);   //~8314R~
ITGN1(65,      GS     ,SO ,0  ,0  ,0  ,0,0 ,_   ,386 ,_   ,_,0);   //~8314R~

ITGN1(66,      OpdSz  ,OS ,0  ,0  ,0  ,0,0 ,_   ,386 ,_   ,_,0);   //~8308R~
ITGN1(67,      AddSz  ,AS ,0  ,0  ,0  ,0,0 ,_   ,386 ,_   ,_,0);   //~8308R~

ITGN1(68,      PUSH   ,I  ,v  ,0  ,0  ,0,0 ,_   ,186 ,_   ,_,0);   //~8308R~

ITGN1(69,      IMUL   ,G  ,v  ,E  ,v  ,I,v ,_   ,386 ,_   ,_3,0);//3 opd//~8308R~
                                                  //if no ,_,0);   //~8308R~
ITGN1(6A,      PUSH   ,I  ,b  ,0  ,0  ,0,0 ,_   ,186 ,_   ,_,0);   //~8308R~

ITGN1(6B,      IMUL   ,G  ,v  ,E  ,v  ,K,b ,_   ,386 ,_   ,_3S,0);//3 opd signed//~8331R~
                                                  //if no ,_,0);   //~8308R~
ITGN1(6C,      INSB   ,Y  ,b  ,0  ,w  ,0,0 ,186 ,P1  ,_   ,_,0);   //~8315R~
ITGN1(6D,      INSW   ,Y  ,v  ,0  ,w  ,0,0 ,186 ,P1  ,_   ,_,0);   //~8315R~
ITGNE(6,E,     OUTSB  ,0  ,w  ,X  ,b  ,0,0 ,186 ,P1  ,_   ,_,0);   //~8315R~
ITGN1(6F,      OUTSW  ,0  ,w  ,X  ,v  ,0,0 ,186 ,P1  ,_   ,_,0);   //~8315R~

ITGN1(70,      JO     ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(71,      JNO    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(72,      JB     ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(73,      JNB    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(74,      JZ     ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(75,      JNZ    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(76,      JNA    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(77,      JA     ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(78,      JS     ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(79,      JNS    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(7A,      JP     ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(7B,      JNP    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(7C,      JL     ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(7D,      JNL    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGNE(7,E,     JNG    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(7F,      JG     ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(80,      Grp1   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp1);//*** Grp-1//~8308R~

ITGN1(81,      Grp1   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp1);//*** Grp-1//~8308R~
ITGN1(82,      Grp1   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp1);//*** Grp-1//~v219I~

ITGN1(83,      Grp1   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp1);//*** Grp-1//~8308R~

ITGN1(84,      TEST   ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(85,      TEST   ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(86,      XCHG   ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(87,      XCHG   ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(88,      MOV    ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(89,      MOV    ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(8A,      MOV    ,G  ,b  ,E  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(8B,      MOV    ,G  ,v  ,E  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(8C,      MOV    ,E  ,w  ,S  ,w  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(8D,      LEA    ,G  ,v  ,M  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGNE(8,E,     MOV    ,S  ,w  ,E  ,w  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(8F,      POP    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~

ITGN1(90,      NOP    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(91,      XCHG   ,eAX,v  ,eCX,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(92,      XCHG   ,eAX,v  ,eDX,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(93,      XCHG   ,eAX,v  ,eBX,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(94,      XCHG   ,eAX,v  ,eSP,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(95,      XCHG   ,eAX,v  ,eBP,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(96,      XCHG   ,eAX,v  ,eSI,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(97,      XCHG   ,eAX,v  ,eDI,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(98,      CBW    ,0  ,v  ,0  ,c  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(99,      CWD    ,0  ,qd ,0  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

//ITGN1(9A,      CALL   ,A  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Far,0);//~v254R~
ITGN1(9A,      CALL   ,A  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Far,directF);//~v254I~

ITGN1(9B,      WAIT   ,WT ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(9C,      PUSHF  ,F  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(9D,      POPF   ,F  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGNE(9,E,     SAHF   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(9F,      LAHF   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(A0,      MOV    ,AL ,b  ,O  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(A1,      MOV    ,eAX,v  ,O  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(A2,      MOV    ,O  ,b  ,AL ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(A3,      MOV    ,O  ,v  ,eAX,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(A4,      MOVSB  ,X  ,b  ,Y  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(A5,      MOVSW  ,X  ,v  ,Y  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(A6,      CMPSB  ,X  ,b  ,Y  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(A7,      CMPSW  ,X  ,v  ,Y  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(A8,      TEST   ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(A9,      TEST   ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(AA,      STOSB  ,Y  ,b  ,0  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8315R~
ITGN1(AB,      STOSW  ,Y  ,v  ,0  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8315R~

ITGN1(AC,      LODSB  ,X  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(AD,      LODSW  ,X  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(AE,      SCASB  ,0  ,0  ,X  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(AF,      SCASW  ,0  ,0  ,X  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

//ITGN1(B0,      MOV    ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0); //~v262R~
ITGN1(B0,      MOV    ,AL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,int21AX);//~v262I~
ITGN1(B1,      MOV    ,CL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(B2,      MOV    ,DL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(B3,      MOV    ,BL ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
//ITGN1(B4,      MOV    ,AH ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0); //~v262R~
ITGN1(B4,      MOV    ,AH ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,int21AX);//~v262I~
ITGN1(B5,      MOV    ,CH ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(B6,      MOV    ,DH ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(B7,      MOV    ,BH ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

//ITGN1(B8,      MOV    ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0); //~v262R~
ITGN1(B8,      MOV    ,eAX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,int21AX);//~v262I~
ITGN1(B9,      MOV    ,eCX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(BA,      MOV    ,eDX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(BB,      MOV    ,eBX,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(BC,      MOV    ,eSP,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(BD,      MOV    ,eBP,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(BE,      MOV    ,eSI,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(BF,      MOV    ,eDI,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(C0,      Grp2   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp2);//Grp-2//~8308R~

ITGN1(C1,      Grp2   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp2);//Grp-2//~8308R~

//ITGN1(C2,      RET    ,I  ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Pop,0);//~v221R~
//ITGN1(C3,      RET    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~v221R~
ITGNX(C2,      RET    ,I  ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Pop,0,DAIIT_UCJMP);//~v221I~
ITGNX(C3,      RET    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0,DAIIT_UCJMP);//~v221I~

ITGN1(C4,      LES    ,G  ,v  ,M  ,p  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(C5,      LDS    ,G  ,v  ,M  ,p  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(C6,      MOV    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(C7,      MOV    ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(C8,      ENTER  ,I  ,w  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_,0);   //~8308R~
ITGN1(C9,      LEAVE  ,0  ,0  ,0  ,0  ,0,0 ,186 ,_   ,_   ,_,0);   //~8308R~
//ITGN1(CA,      RETF   ,I  ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Pop,0);//~v221R~
//ITGN1(CB,      RETF   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~v221R~
ITGNX(CA,      RETF   ,I  ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Pop,0,DAIIT_UCJMP);//~v221I~
ITGNX(CB,      RETF   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0,DAIIT_UCJMP);//~v221I~

ITGN1(CC,      INT    ,3  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_3,0);  //~8308R~
ITGN1(CD,      INT    ,I  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,int); //~v227R~
ITGN1(CE,      INTO   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

//ITGN1(CF,      IRET   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~v221R~
ITGNX(CF,      IRET   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0,DAIIT_UCJMP);//~v221I~

ITGN1(D0,      Grp2   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp2);//Grp-2//~8308R~

ITGN1(D1,      Grp2   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp2);//Grp-2//~8308R~

ITGN1(D2,      Grp2   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp2);//Grp-2//~8308R~

ITGN1(D3,      Grp2   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp2);//Grp-3//~8308R~

//* add Grp   AAM
ITGN1(D4,      GrpAAM ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,GrpAAM);//~8308R~
ITGN2(D4,0A,   AAM    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

//* add Grp   AAD                                                  //~8308R~
ITGN1(D5,      GrpAAD ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,GrpAAD);//~8308R~
ITGN2(D5,0A,   AAD    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(D7,      XLAT   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
//*Fpu Escape
ITGN1(D8,      GrpFpu ,0  ,0  ,0  ,0  ,0,0 ,_   ,GRP ,FPU ,_,GrpFpu);//~8308R~
ITGN1(D9,      GrpFpu ,0  ,0  ,0  ,0  ,0,0 ,_   ,GRP ,FPU ,_,GrpFpu);//~8308R~
ITGN1(DA,      GrpFpu ,0  ,0  ,0  ,0  ,0,0 ,_   ,GRP ,FPU ,_,GrpFpu);//~8308R~
ITGN1(DB,      GrpFpu ,0  ,0  ,0  ,0  ,0,0 ,_   ,GRP ,FPU ,_,GrpFpu);//~8308R~
ITGN1(DC,      GrpFpu ,0  ,0  ,0  ,0  ,0,0 ,_   ,GRP ,FPU ,_,GrpFpu);//~8308R~
ITGN1(DD,      GrpFpu ,0  ,0  ,0  ,0  ,0,0 ,_   ,GRP ,FPU ,_,GrpFpu);//~8308R~
ITGN1(DE,      GrpFpu ,0  ,0  ,0  ,0  ,0,0 ,_   ,GRP ,FPU ,_,GrpFpu);//~8308R~
ITGN1(DF,      GrpFpu ,0  ,0  ,0  ,0  ,0,0 ,_   ,GRP ,FPU ,_,GrpFpu);//~8308R~

ITGN1(E0,      LOOPNZ ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8314R~
ITGN1(E1,      LOOPZ  ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(E2,      LOOP   ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(E3,      JCXZ   ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(E4,      IN     ,AL ,b  ,I  ,b  ,0,0 ,_   ,P1  ,_   ,_,0);//PL=1//~8308R~
ITGN1(E5,      IN     ,eAX,v  ,I  ,b  ,0,0 ,_   ,P1  ,_   ,_,0);   //~8308R~
ITGN1(E6,      OUT    ,I  ,b  ,AL ,b  ,0,0 ,_   ,P1  ,_   ,_,0);   //~8308R~
ITGN1(E7,      OUT    ,I  ,b  ,eAX,v  ,0,0 ,_   ,P1  ,_   ,_,0);   //~8308R~

ITGN1(E8,      CALL   ,J  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_rel,0);//~8314R~

//ITGN1(E9,      JMP    ,J  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_rel,0);//~v221R~
//ITGN1(EA,      JMP    ,A  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Far,0);//~v221R~
//ITGN1(EB,      JMP    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_rel,0);//~v221R~
ITGNX(E9,      JMP    ,J  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_rel,0,DAIIT_UCJMP);//~v221I~
//ITGNX(EA,      JMP    ,A  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Far,0,DAIIT_UCJMP);//~v254R~
ITGNX(EA,      JMP    ,A  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Far,directF,DAIIT_UCJMP);//~v254I~
ITGNX(EB,      JMP    ,J  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_rel,0,DAIIT_UCJMP);//~v221I~

ITGN1(EC,      IN     ,AL ,b  ,DX ,0  ,0,0 ,_   ,P1  ,_   ,_,0);   //~8308R~
ITGN1(ED,      IN     ,eAX,v  ,DX ,0  ,0,0 ,_   ,P1  ,_   ,_,0);   //~8308R~
ITGN1(EE,      OUT    ,DX ,0  ,AL ,b  ,0,0 ,_   ,P1  ,_   ,_,0);   //~8308R~
ITGN1(EF,      OUT    ,DX ,0  ,eAX,v  ,0,0 ,_   ,P1  ,_   ,_,0);   //~8308R~

ITGN1(F0,      LOCK   ,LP ,0  ,0  ,0  ,0,0 ,_   ,P1  ,_   ,_,0);//PL=1(I/O)//~8314R~

ITGN1(F2,      REPNE  ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(F3,      REP    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(F4,      HLT    ,0  ,0  ,0  ,0  ,0,0 ,_   ,P0  ,_   ,_,0);   //~8308R~

ITGN1(F5,      CMC    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(F6,      Grp3   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp3);//Grp-3//~8308R~

ITGN1(F7,      Grp3   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp3);//Grp-3//~8308R~

ITGN1(F8,      CLC    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(F9,      STC    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(FA,      CLI    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(FB,      STI    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(FC,      CLD    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN1(FD,      STD    ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

ITGN1(FE,      Grp4   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp4);//Grp-4//~8308R~

//ITGN1(FF,      Grp5   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp4);//Grp-5//~v265R~
ITGN1(FF,      Grp5   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp5);//Grp-5//~v265I~

//*************************************************************
//*2 byte Escape
//*************************************************************
ITGN2(0F,00,   Grp6   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp6);//Grp-6//~8308R~

ITGN2(0F,01,   Grp7   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp7);//Grp-7//~8308R~

ITGN2(0F,02,   LAR    ,G  ,v  ,E  ,v  ,0,0 ,286 ,PP  ,_   ,_,0);//prot only//~8308R~
ITGN2(0F,03,   LSL    ,G  ,v  ,E  ,v  ,0,0 ,286 ,PP  ,_   ,_,0);//prot only//~8308R~

ITGN2(0F,05,   LOADALL,0  ,0  ,0  ,0  ,0,0 ,386 ,P3  ,_   ,_,0);//rare//~8308R~
ITGN2(0F,06,   CLTS   ,0  ,0  ,0  ,0  ,0,0 ,286 ,P0  ,_   ,_,0);//PL0//~8308R~

ITGN2(0F,08,   INVD   ,0  ,0  ,0  ,0  ,0,0 ,486 ,P3  ,_   ,_,0);//rare//~8308R~
ITGN2(0F,09,   WBINVD ,0  ,0  ,0  ,0  ,0,0 ,486 ,P3  ,_   ,_,0);//rare//~8308R~

ITGN2(0F,20,   MOV    ,R  ,d  ,C  ,d  ,0,0 ,386 ,_   ,_   ,_RC,0); //~8308R~
ITGN2(0F,21,   MOV    ,R  ,d  ,D  ,d  ,0,0 ,386 ,_   ,_   ,_RD,0); //~8308R~
ITGN2(0F,22,   MOV    ,C  ,d  ,R  ,d  ,0,0 ,386 ,_   ,_   ,_CR,0); //~8308R~
ITGN2(0F,23,   MOV    ,D  ,d  ,R  ,d  ,0,0 ,386 ,_   ,_   ,_DR,0); //~8308R~
ITGN2(0F,24,   MOV    ,R  ,d  ,T  ,d  ,0,0 ,386 ,_   ,_   ,_RT,0); //~8308R~
ITGN2(0F,26,   MOV    ,T  ,d  ,R  ,d  ,0,0 ,386 ,_   ,_   ,_TR,0); //~8308R~

//#ifdef P5                                                        //~v320R~

ITGN2(0F,30,   WRMSR  ,0  ,0  ,0  ,0  ,0,0 ,P5  ,P0  ,_   ,_,0);   //~v320R~
ITGN2(0F,31,   RDTSC  ,0  ,0  ,0  ,0  ,0,0 ,P5  ,P0  ,_   ,_,0);   //~v320R~
ITGN2(0F,32,   RDMSR  ,0  ,0  ,0  ,0  ,0,0 ,P5  ,P0  ,_   ,_,0);   //~v320R~
ITGN2(0F,33,   RDPMC  ,0  ,0  ,0  ,0  ,0,0 ,P5  ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,34,  SYSENTER,0  ,0  ,0  ,0  ,0,0 ,P5  ,_   ,_   ,_,0);   //+v5i3I~
ITGN2(0F,35,  SYSEXIT ,0  ,0  ,0  ,0  ,0,0 ,P5  ,_   ,_   ,_,0);   //+v5i3I~

//#endif                                                           //~v320R~

#ifdef MMX

ITGN2(0F,60,   PUNPCKLBW,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,61,   PUNPCKLWD,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,62,   PUNPCKLDQ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,63,   PACKSSWB ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,64,   PCMPGTB  ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,65,   PCMPGTW  ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,66,   PCMPGTD  ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,67,   PACKUSWB ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,68,   PUNPCKHBW,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,69,   PUNPCKHWD,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,6A,   PUNPCKHDQ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,6B,   PACKSSDW ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,6E,   MOVD     ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,6F,   MOVQ     ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,71,   PSHIMW*  ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,72,   PSHIMD*  ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,73,   PSHIMQ*  ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,74,   PCMPEQB  ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,75,   PCMPEQW  ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,76,   PCMPEQD  ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,77,   EMMS     ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,7E,   MOVD     ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;
ITGN2(0F,7F,   MOVQ     ,Q,Q  ,0 ,0   ,MMX ,    ,       ,0;

#endif          //MMX

//*   OP       MN      op1,sz1,op2,sz2,op3 ,cls1,cls2,cls3,remid
ITGN2(0F,80,   JO     ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,81,   JNO    ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,82,   JB     ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,83,   JNB    ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,84,   JZ     ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,85,   JNZ    ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,86,   JNA    ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,87,   JA     ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,88,   JS     ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,89,   JNS    ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,8A,   JP     ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,8B,   JNP    ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,8C,   JL     ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,8D,   JNL    ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGNF(0F,8,E,  JNG    ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,8F,   JG     ,J  ,v  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~

ITGN2(0F,90,   SETO   ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,91,   SETNO  ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,92,   SETB   ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,93,   SETNB  ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,94,   SETZ   ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,95,   SETNZ  ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,96,   SETNA  ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,97,   SETA   ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,98,   SETS   ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,99,   SETNS  ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,9A,   SETP   ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,9B,   SETNP  ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,9C,   SETL   ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,9D,   SETNL  ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGNF(0F,9,E,  SETNG  ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,9F,   SETG   ,E  ,b  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~

ITGN2(0F,A0,   PUSH   ,FS ,w  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,A1,   POP    ,FS ,w  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~

#ifdef P5

ITGN2(0F,A2,   CPUID  ,0  ,0  ,0  ,0  ,0,0 ,P5  ,_   ,_   ,_,0);   //~8308R~

#endif

ITGN2(0F,A3,   BT     ,E  ,v  ,G  ,v  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,A4,   SHLD   ,E  ,v  ,G  ,v  ,I,b ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,A5,   SHLD   ,E  ,v  ,G  ,v  ,CL,b,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,A8,   PUSH   ,GS ,w  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,A9,   POP    ,GS ,w  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~

#ifdef RSM

ITGN2(0F,AA,   RSM    ,0  ,0  ,0  ,0  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~

#endif

ITGN2(0F,AB,   BTS    ,E  ,v  ,G  ,v  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,AC,   SHRD   ,E  ,v  ,G  ,v  ,I,b ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,AD,   SHRD   ,E  ,v  ,G  ,v  ,CL,b,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,AF,   IMUL   ,G  ,v  ,E  ,v  ,0,0 ,386 ,_   ,_   ,_2,0);//(d)word reg*=r/m word//~8308R~

ITGN2(0F,B0,   CMPXCHG,E  ,b  ,G  ,b  ,0,0 ,486 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,B1,   CMPXCHG,E  ,v  ,G  ,v  ,0,0 ,486 ,_   ,_   ,_v,0);  //~8405R~

ITGN2(0F,B2,   LSS    ,G  ,v  ,M  ,p  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,B3,   BTR    ,E  ,v  ,G  ,v  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~


//*   OP       MN      op1,sz1,op2,sz2,op3 ,cls1,cls2,cls3m
ITGN2(0F,B4,   LFS    ,G  ,v  ,M  ,p  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,B5,   LGS    ,G  ,v  ,M  ,p  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,B6,   MOVZX  ,G  ,v  ,E  ,b  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,B7,   MOVZX  ,G  ,d  ,E  ,w  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~

ITGN2(0F,BA,   Grp8   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,GRP ,_,Grp8);//Grp-8//~8308R~

ITGN2(0F,BB,   BTC    ,E  ,v  ,G  ,v  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,BC,   BSF    ,G  ,v  ,E  ,v  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,BD,   BSR    ,G  ,v  ,E  ,v  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,BE,   MOVSX  ,G  ,v  ,E  ,b  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,BF,   MOVSX  ,G  ,d  ,E  ,w  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~

ITGN2(0F,C0,   XADD   ,E  ,b  ,G  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,C1,   XADD   ,E  ,v  ,G  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

#ifdef P5
ITGN2(0F,C7,   CMPXCHG8B  ,   ,   ,0  ,0,0 ,P5  ,_   ,_   ,_,0);   //~8308R~
#endif

ITGN2(0F,C8,   BSWAP  ,EAX,d  ,0  ,0  ,0,0 ,486 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,C9,   BSWAP  ,ECX,d  ,0  ,0  ,0,0 ,486 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,CA,   BSWAP  ,EDX,d  ,0  ,0  ,0,0 ,486 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,CB,   BSWAP  ,EBX,d  ,0  ,0  ,0,0 ,486 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,CC,   BSWAP  ,ESP,d  ,0  ,0  ,0,0 ,486 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,CD,   BSWAP  ,EBP,d  ,0  ,0  ,0,0 ,486 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,CE,   BSWAP  ,ESI,d  ,0  ,0  ,0,0 ,486 ,_   ,_   ,_,0);   //~8308R~
ITGN2(0F,CF,   BSWAP  ,EDI,d  ,0  ,0  ,0,0 ,486 ,_   ,_   ,_,0);   //~8308R~

#ifdef MMX

ITGN2(0F,D1,   PSRLW  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,D2,   PSRLD  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,D3,   PSRLQ  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,D5,   PMULLW ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,D8,   PSUBUSB,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,D9,   PSUBUSW,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,DB,   PAND   ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,DC,   PADDUSB,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,DD,   PADDUSW,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,DF,   PANDN  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,E1,   PSRAW  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,E2,   PSRAD  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,E5,   PMULHW ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,E8,   PSUBSB ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,E9,   PSUBSW ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,EB,   POR    ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,EC,   PADDSB ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,ED,   PADDSW ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,EF,   PXOR   ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,F1,   PSLLW  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,F2,   PSLLD  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,F3,   PSLLQ  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,F5,   PMADDWD,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,F8,   PSUBB  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,F9,   PSUBW  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,FA,   PSUBD  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,FC,   PADDB  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,FD,   PADDW  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;
ITGN2(0F,FE,   PADDD  ,   ,0  ,0 ,0   ,MMX ,_   ,_      ,0;

#endif

//******************************************************************
//*Group table its sub opecode on modR/M
//******************************************************************
//** GRP-1 ******
ITGN2(80, 0,   ADD    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(80, 1,   OR     ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(80, 2,   ADC    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(80, 3,   SBB    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(80, 4,   AND    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(80, 5,   SUB    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(80, 6,   XOR    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(80, 7,   CMP    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

//** GRP-1 ******
ITGN2(81, 0,   ADD    ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(81, 1,   OR     ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(81, 2,   ADC    ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(81, 3,   SBB    ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(81, 4,   AND    ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(81, 5,   SUB    ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(81, 6,   XOR    ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(81, 7,   CMP    ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

//** GRP-1 ******                                                  //~v219I~
ITGN2(82, 0,   ADD    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~v219R~
ITGN2(82, 1,   OR     ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~v219R~
ITGN2(82, 2,   ADC    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~v219R~
ITGN2(82, 3,   SBB    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~v219R~
ITGN2(82, 4,   AND    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~v219R~
ITGN2(82, 5,   SUB    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~v219R~
ITGN2(82, 6,   XOR    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~v219R~
ITGN2(82, 7,   CMP    ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~v219R~
                                                                   //~v219I~
//** GRP-1 ******
ITGN2(83, 0,   ADD    ,E  ,v  ,K  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(83, 1,   OR     ,E  ,v  ,K  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(83, 2,   ADC    ,E  ,v  ,K  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(83, 3,   SBB    ,E  ,v  ,K  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(83, 4,   AND    ,E  ,v  ,K  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(83, 5,   SUB    ,E  ,v  ,K  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(83, 6,   XOR    ,E  ,v  ,K  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(83, 7,   CMP    ,E  ,v  ,K  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~

//*** GRP-2 ******
ITGN2(C0, 0,   ROL    ,E  ,b  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_b,0);  //~8405R~
ITGN2(C0, 1,   ROR    ,E  ,b  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_b,0);  //~8405R~
ITGN2(C0, 2,   RCL    ,E  ,b  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_b,0);  //~8405R~
ITGN2(C0, 3,   RCR    ,E  ,b  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_b,0);  //~8405R~
ITGN2(C0, 4,   SHL    ,E  ,b  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_b,0);  //~8405R~
ITGN2(C0, 5,   SHR    ,E  ,b  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_b,0);  //~8405R~
ITGN2(C0, 7,   SAR    ,E  ,b  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_b,0);  //~8405R~

//*** GRP-2 ******
ITGN2(C1, 0,   ROL    ,E  ,v  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_,0);   //~8308R~
ITGN2(C1, 1,   ROR    ,E  ,v  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_,0);   //~8308R~
ITGN2(C1, 2,   RCL    ,E  ,v  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_,0);   //~8308R~
ITGN2(C1, 3,   RCR    ,E  ,v  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_,0);   //~8308R~
ITGN2(C1, 4,   SHL    ,E  ,v  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_,0);   //~8308R~
ITGN2(C1, 5,   SHR    ,E  ,v  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_,0);   //~8308R~
ITGN2(C1, 7,   SAR    ,E  ,v  ,I  ,b  ,0,0 ,186 ,_   ,_   ,_,0);   //~8308R~

//*** GRP-2 *****
ITGN2(D0, 0,   ROL    ,E  ,b  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D0, 1,   ROR    ,E  ,b  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D0, 2,   RCL    ,E  ,b  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D0, 3,   RCR    ,E  ,b  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D0, 4,   SHL    ,E  ,b  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D0, 5,   SHR    ,E  ,b  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D0, 7,   SAR    ,E  ,b  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~

//*** GRP-2 *****
ITGN2(D1, 0,   ROL    ,E  ,v  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D1, 1,   ROR    ,E  ,v  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D1, 2,   RCL    ,E  ,v  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D1, 3,   RCR    ,E  ,v  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D1, 4,   SHL    ,E  ,v  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D1, 5,   SHR    ,E  ,v  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D1, 7,   SAR    ,E  ,v  ,1  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

//*** GRP-2 *****
ITGN2(D2, 0,   ROL    ,E  ,b  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D2, 1,   ROR    ,E  ,b  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D2, 2,   RCL    ,E  ,b  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D2, 3,   RCR    ,E  ,b  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D2, 4,   SHL    ,E  ,b  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D2, 5,   SHR    ,E  ,b  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(D2, 7,   SAR    ,E  ,b  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~

//*** GRP-2 *****
ITGN2(D3, 0,   ROL    ,E  ,v  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D3, 1,   ROR    ,E  ,v  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D3, 2,   RCL    ,E  ,v  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D3, 3,   RCR    ,E  ,v  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D3, 4,   SHL    ,E  ,v  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D3, 5,   SHR    ,E  ,v  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(D3, 7,   SAR    ,E  ,v  ,CL ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~

//*** GRP-3 *****
ITGN2(F6, 0,   TEST   ,E  ,b  ,I  ,b  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(F6, 2,   NOT    ,E  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(F6, 3,   NEG    ,E  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(F6, 4,   MUL    ,E  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(F6, 5,   IMUL   ,E  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(F6, 6,   DIV    ,E  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(F6, 7,   IDIV   ,E  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~

//*** GRP-3 *****
ITGN2(F7, 0,   TEST   ,E  ,v  ,I  ,v  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(F7, 2,   NOT    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(F7, 3,   NEG    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8308R~
ITGN2(F7, 4,   MUL    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(F7, 5,   IMUL   ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(F7, 6,   DIV    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(F7, 7,   IDIV   ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~

//*** GRP-4 *****
ITGN2(FE, 0,   INC    ,E  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~
ITGN2(FE, 1,   DEC    ,E  ,b  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_b,0);  //~8405R~

//*** GRP-5 *****
ITGN2(FF, 0,   INC    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
ITGN2(FF, 1,   DEC    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~
//GN2(FF, 2,   CALL   ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~v212R~
ITGN2(FF, 2,   CALL   ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_AIA,aiajc);//~v213R~
//ITGN2(FF, 3,   CALL   ,M  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Far,0);//~v246R~
ITGN2(FF, 3,   CALL   ,M  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Far,aiajcF);//~v246I~
//GN2(FF, 4,   JMP    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~v212R~
//ITGN2(FF, 4,   JMP    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_AIA,aiajc);//~v221R~
//ITGN2(FF, 5,   JMP    ,M  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~v221R~
ITGNY(FF,4,    JMP    ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_AIA,aiajc,DAIIT_UCJMP);//~v221I~
//ITGNY(FF,5,    JMP    ,M  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0,DAIIT_UCJMP);//~v246R~
ITGNY(FF,5,    JMP    ,M  ,p  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_Far,aiajcF,DAIIT_UCJMP);//~v246I~
ITGN2(FF, 6,   PUSH   ,E  ,v  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0);   //~8405R~

//* GRP-6 *******
ITGN3(0F,00, 0,SLDT   ,E  ,w  ,0  ,0  ,0,0 ,286 ,PP  ,_   ,_,0);//Prot only//~8308R~
ITGN3(0F,00, 1,STR    ,E  ,w  ,0  ,0  ,0,0 ,286 ,PP  ,_   ,_,0);//prot only//~8308R~
ITGN3(0F,00, 2,LLDT   ,E  ,w  ,0  ,0  ,0,0 ,286 ,P0  ,_   ,_,0);   //~8308R~
ITGN3(0F,00, 3,LTR    ,E  ,w  ,0  ,0  ,0,0 ,286 ,PP  ,_   ,_,0);//prot only//~8308R~
ITGN3(0F,00, 4,VERR   ,E  ,w  ,0  ,0  ,0,0 ,286 ,PP  ,_   ,_,0);//prot only//~8308R~
ITGN3(0F,00, 5,VERW   ,E  ,w  ,0  ,0  ,0,0 ,286 ,PP  ,_   ,_,0);//prot only//~8308R~

//* GRP-7 *******
ITGN3(0F,01, 0,SGDT   ,M  ,s  ,0  ,0  ,0,0 ,286 ,P3  ,_   ,_,0);//rare//~8308R~
ITGN3(0F,01, 1,SIDT   ,M  ,s  ,0  ,0  ,0,0 ,286 ,P3  ,_   ,_,0);//rare//~8308R~
ITGN3(0F,01, 2,LGDT   ,M  ,s  ,0  ,0  ,0,0 ,286 ,P0  ,_   ,_,0);   //~8308R~
ITGN3(0F,01, 3,LIDT   ,M  ,s  ,0  ,0  ,0,0 ,286 ,P0  ,_   ,_,0);   //~8308R~
ITGN3(0F,01, 4,SMSW   ,E  ,w  ,0  ,0  ,0,0 ,286 ,P3  ,_   ,_,0);//rare//~8308R~
ITGN3(0F,01, 6,LMSW   ,E  ,w  ,0  ,0  ,0,0 ,286 ,P3  ,_   ,_,0);//rare//~8308R~
ITGN3(0F,01, 7,INVLPG ,m  ,0  ,0  ,0  ,0,0 ,486 ,P3  ,_   ,_,0);//rare//~8308R~

//** GRP-8 ******
ITGN3(0F,BA, 4,BT     ,E  ,v  ,I  ,b  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN3(0F,BA, 5,BTS    ,E  ,v  ,I  ,b  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN3(0F,BA, 6,BTR    ,E  ,v  ,I  ,b  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~
ITGN3(0F,BA, 7,BTC    ,E  ,v  ,I  ,b  ,0,0 ,386 ,_   ,_   ,_,0);   //~8308R~

//******************************************************************
