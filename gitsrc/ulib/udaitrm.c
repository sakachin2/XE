//CID://+v5i3R~:                                                   //~v5i3R~
//*************************************************************
//*udaitrm.c instruction remark edit patern difinition
//*          included into udamt.c
//*************************************************************
//v5i3:060505 (XDA)add instruction SYSENTER(0f34) and SYSEXIT(0f35)//~v5i3I~
//v5i2:060505 (XDA)insert LineFeed after return and before enter   //~v5i2I~
//v320 000603:DISAS:add 0f30(WRMSR),0f31(RDTSC),0f32(RDMSR),0f33(RDPMC)//~v320I~
//v310 000507:(DISAS)jump direction up/down on remark              //~v310I~
//v283:990912 disas:comment change                                 //~v283I~
//v274:990808 disas:comment level:jumponly or all                  //~v274I~
//v254:990626 disas:DOS MZ support(direct far call label ref)      //~v254I~
//v212:981223 disas:import name display                            //~v212I~
//*************************************************************    //~v212I~
#include <udaitrm.h>
//*************************************************************
//*remark type
//*  type:
//* 	'c':        //constant
//* 	'r':        //right unary like as AX++
//* 	'l':        //right unary like as ++AX
//* 	'2':        //binary operator
//* 	'e':        //need edit %
//* 	     %1,%2,%3:operand
//* 	     %e      :"E" or "" by operand size(ex %eDI)           //~8316R~
//* 	     %E      :"E" or "" by addr size(ex %EDI)              //~8316I~
//* 	     %x      :"X" or "L"(ex A%x) by opdsz of opd1          //~8308R~
//* 	     %l      :operand size
//* 	     %j      :jump addr                                    //~v310I~
//* 	     %d      :dllname(import tbl search)                   //~v212R~
//* 	     %w      :if memory generatye (%l)                     //~8331I~
//*          %n,%r,%i:rsved for FPU                                //~v310I~
//*  string:
//*          \x0d    :if 1st char is x0d insert \n before print line//~v5i2I~
//*          \x0a    :if 1st char is x0a insert \n after  print line//~v5i2I~
//*          \x01     :if 1st char is x01 string is \1xxx\0yyy format//~v5i2R~
//*                  remark is change by operand size
//*          \x02   :if 1st char is x02 on it is level=1 comment   //~v274I~
//*************************************************************
//* Group instruction table
REMCOPD(2Byte_     ,c,"");
REMCOPD(GrpFpu_    ,c,"");
REMCOPD(Grp1_      ,c,"");
REMCOPD(Grp2_      ,c,"");
REMCOPD(Grp3_      ,c,"");
REMCOPD(Grp4_      ,c,"");
REMCOPD(Grp5_      ,c,"");
REMCOPD(Grp6_      ,c,"");
REMCOPD(Grp7_      ,c,"");
REMCOPD(Grp8_      ,c,"");

REMCOPD(GrpAAM_    ,c,"");
REMCOPD(GrpAAD_    ,c,"");
//*************************************************************
REMCOPD(AAA_       ,c,"(AH:AL)=ASCII Ajust AL after BCD ADD");     //~8316R~
REMCOPD(AAD_       ,c,"(AH,AL)=(0,AH*10+AL)");                     //~8316R~
REMCOPD(AAM_       ,c,"(AH,AL)=(AL/10,AL%10)");                    //~8316R~
REMCOPD(AAS_       ,c,"AL=ASCII Ajust AL after BCD SUB");
REMCOPD(ADC_       ,e,"%1+=%2+CF");                                //~8401R~
REMCOPD(ADD_       ,2,"+=");
REMCOPD(AddSz_     ,c,"AddressSizeOverride");
REMCOPD(AND_       ,2,"&=");
REMCOPD(ARPL_      ,c,"\x02ARPL");                                 //~v274R~
REMCOPD(BOUND_     ,c,"CheckArrayIndexAgainstBounds");
REMCOPD(BSF_       ,2,"=First Bit Offset of ");
REMCOPD(BSR_       ,2,"=Last Bit Offset from last of ");
REMCOPD(BSWAP_     ,l,"Big<->Little Endian of ");                  //~8406R~
REMCOPD(BT_        ,e,"CF=BIT(%1,%2)");
REMCOPD(BTC_       ,e,"CF=BIT(%1,%2),~BIT(%1,%2)");
REMCOPD(BTR_       ,e,"CF=BIT(%1,%2),BIT(%1,%2)=0");
REMCOPD(BTS_       ,e,"CF=BIT(%1,%2),BIT(%1,%2)=1");
//REMCOPD(CALL_      ,c,"<---------->");                           //~v212R~
REMCOPD(CALL_rel   ,e,"\x02<---------->%j");                       //~v274R~
//REMCOPD(CALL_Far ,c,"<-------------------->");                   //~v212R~
REMCOPD(CALL_Far   ,l,"\x02<---------->Far ");                     //~v274R~
REMCOPD(CALL_AIA   ,e,"\x02<==>%d");    //imprt tbl search         //~v283R~
REMCOPD(CBW_       ,e,"%eAX=Sign##A%x");
REMCOPD(CLC_       ,c,"CF=0");
REMCOPD(CLD_       ,c,"DF=0");
REMCOPD(CLI_       ,c,"IF=0");
REMCOPD(CLTS_      ,c,"TS flag in CR0=0");
REMCOPD(CMC_       ,c,"~CF");
REMCOPD(CMP_       ,2," -? ");
REMCOPD(CMPSB_     ,e,"DS:[%ESI++](1) -? ES:[%EDI++]");            //~8316R~
REMCOPD(CMPSW_     ,e,"DS:[%ESI++] -? ES:[%EDI++]");//nemonic change//~8405R~
REMCOPD(CMPXCHG_   ,e,"(AL==%1)?%1=%2:AL=%1");                     //~8405R~
REMCOPD(CMPXCHG_v  ,e,"(%eAX==%1)?%1=%2:%eAX=%1");                 //~8405I~
REMCOPD(CS_        ,c,"CS:");
REMCOPD(CWD_       ,e,"(%eDX:%eAX)=Sign##%eAX");                   //~8316R~
REMCOPD(DAA_       ,c,"AL=Decimal Ajust AL after BCD ADD");
REMCOPD(DAS_       ,c,"AL=Decimal Ajust AL after BCD SUB");
REMCOPD(DEC_       ,l,"--");                                       //~8405R~
REMCOPD(DEC_b      ,e,"--%1%w");                                   //~8405R~
REMCOPD(DIV_       ,e,"(%eAX..%eDX)=(%eDX:%eAX)/%1");              //~8405R~
REMCOPD(DIV_b      ,e,"(AL..AH)=AX/%1%w");                         //~8405I~
REMCOPD(DS_        ,c,"DS:");
//REMCOPD(ENTER_     ,e,"PUSH %eBP,Copy %2 parm,%eBP=%eSP,%eSP-=%1");//~v5i2R~
REMCOPD(ENTER_     ,e,"\rPUSH %eBP,Copy %2 parm,%eBP=%eSP,%eSP-=%1");//~v5i2I~
//*
REMCOPD(ES_        ,c,"ES:");
REMCOPD(FS_        ,c,"FS:");
REMCOPD(GS_        ,c,"GS:");
REMCOPD(HLT_       ,c,"HALT");
REMCOPD(IDIV_      ,e,"(%eAX..%eDX)=(%eDX:%eAX)/%1");              //~8405R~
REMCOPD(IDIV_b     ,e,"(AL..AH)=AX/%1%w");                         //~8405I~
REMCOPD(IMUL_      ,e,"(%eDX:%eAX)=%eAX*%1");                      //~8405R~
REMCOPD(IMUL_b     ,e,"AX=AL*%1");                                 //~8406R~
REMCOPD(IMUL_2     ,e,"%1*=%2");                                   //~8405R~
REMCOPD(IMUL_3     ,e,"%1=%2*%3");
REMCOPD(IMUL_3S    ,e,"%1=%2*(Signed exp %3)");                    //~8331R~
REMCOPD(IN_        ,2,"<--port ");
REMCOPD(INC_       ,l,"++");                                       //~8405R~
REMCOPD(INC_b      ,e,"++%1%w");                                   //~8405R~
REMCOPD(INSB_      ,e,"ES:[%EDI](1)<--port DX");                   //~8405R~
REMCOPD(INSW_      ,e,"ES:[%EDI]<--port DX");                      //~8405R~
REMCOPD(INT_3      ,c,"\x02INT 3(BreakPoint)<=====>");             //~v274R~
REMCOPD(INT_       ,e,"\x02INT %1<=====>");                        //~v274R~
REMCOPD(INTO_      ,c,"\x02INTO(Overflow)<=====>");                //~v274R~
REMCOPD(INVD_      ,c,"Invalidate Cache");
REMCOPD(INVLPG_    ,c,"TLB Invalidate");
//REMCOPD(IRET_      ,e,"\x02flag<--,<==========");                //~v5i2R~
REMCOPD(IRET_      ,e,"\n\x02flag<--,<==========");                //~v5i2I~
REMCOPD(JCXZ_      ,e,"\x02if !%eCX,----->%j");                    //~v274R~
//REMCOPD(JMP_       ,c,"----->");                                 //~v254R~
REMCOPD(JMP_rel    ,e,"\x02----->%j");                             //~v274R~
//REMCOPD(JMP_Far  ,c,"---------->");                              //~v212R~
REMCOPD(JMP_Far    ,l,"\x02----->Far ");                           //~v274R~
REMCOPD(JMP_AIA    ,e,"\x02==>:%d");                               //~v274R~

REMCOPD(JO_        ,e,"\x02if OF,----->%j");                       //~v274R~
REMCOPD(JNO_       ,e,"\x02if !OF,----->%j");                      //~v274R~
REMCOPD(JB_        ,e,"\x02if CF,----->%j");                       //~v274R~
REMCOPD(JNB_       ,e,"\x02if !CF,----->%j");                      //~v274R~
REMCOPD(JZ_        ,e,"\x02if ZF,----->%j");                       //~v274R~
REMCOPD(JNZ_       ,e,"\x02if !ZF,----->%j");                      //~v274R~
REMCOPD(JNA_       ,e,"\x02if CF || ZF,----->%j");                 //~v274R~
REMCOPD(JA_        ,e,"\x02if !OF && !ZF,----->%j");               //~v274R~
REMCOPD(JS_        ,e,"\x02if SF,----->%j");                       //~v274R~
REMCOPD(JNS_       ,e,"\x02if !SF,----->%j");                      //~v274R~
REMCOPD(JP_        ,e,"\x02if PF,----->%j");                       //~v274R~
REMCOPD(JNP_       ,e,"\x02if !PF,----->%j");                      //~v274R~
REMCOPD(JL_        ,e,"\x02if SF!=OF,----->%j");                   //~v274R~
REMCOPD(JNL_       ,e,"\x02if SF==OF,----->%j");                   //~v274R~
REMCOPD(JNG_       ,e,"\x02if ZF || SF!=OF,----->%j");             //~v274R~
REMCOPD(JG_        ,e,"\x02if !ZF && SF==OF,----->%j");            //~v274R~

REMCOPD(LAHF_      ,c,"AH=Flag");                                  //~8316R~
REMCOPD(LAR_       ,e,"\1%1=%2 & FF00\0%1=%2 & 00FxFF00");         //~8316R~
REMCOPD(LDS_       ,e,"(%1,DS)=%2");                               //~8406R~
REMCOPD(LEA_       ,2,"=@"  );
REMCOPD(LEAVE_     ,e,"%eSP=%eBP,%eBP<--");                        //~8316R~
REMCOPD(LES_       ,e,"(%1,ES)=%2");                               //~8406R~
REMCOPD(LFS_       ,e,"(%1,FS)=%2");                               //~8406R~
REMCOPD(LGDT_      ,l,"(Limit,Base) of GDTR=");                    //~8406R~
REMCOPD(LGS_       ,e,"(%1,GS)=%2");                               //~8406R~
REMCOPD(LIDT_      ,l,"(Limit,Base) of IDTR=");                    //~8406R~
REMCOPD(LLDT_      ,l,"LDTR=");
REMCOPD(LMSW_      ,l,"MSW=");
REMCOPD(LOADALL_   ,c,"LOADALL");  //not on manual but msdev disasm display it//~8405R~
REMCOPD(LOCK_      ,c,"LockPrefix");
REMCOPD(LODSB_     ,e,"AL=DS:[%ESI++]");                           //~8314R~
REMCOPD(LODSW_     ,e,"%eAX=DS:[%ESI++]");                         //~8314R~
REMCOPD(LOOP_      ,e,"\x02if --%eCX,----->%j");                   //~v274R~
REMCOPD(LOOPNZ_    ,e,"\x02if --%eCX && !ZF,----->%j");            //~v274R~
REMCOPD(LOOPZ_     ,e,"\x02if --%eCX && ZF,----->%j");             //~v274R~
REMCOPD(LSL_       ,2,"=Segment Limit of ");                       //~8316R~
REMCOPD(LSS_       ,e,"(%1,SS)=%2");                               //~8406R~
REMCOPD(LTR_       ,l,"TaskReg=");
REMCOPD(MOV_       ,2,"=");
REMCOPD(MOV_CR     ,2,"=");                                        //~8308R~
REMCOPD(MOV_DR     ,2,"=");                                        //~8308R~
REMCOPD(MOV_RC     ,2,"=");                                        //~8308R~
REMCOPD(MOV_RD     ,2,"=");                                        //~8308R~
REMCOPD(MOV_RT     ,2,"=");                                        //~8308R~
REMCOPD(MOV_TR     ,2,"=");                                        //~8308R~
REMCOPD(MOVSB_     ,e,"ES:[%EDI++](1)=DS:[%ESI++]");               //~8316R~
REMCOPD(MOVSW_     ,e,"ES:[%EDI++]=DS:[%ESI++]");                  //~8405R~
REMCOPD(MOVSX_     ,2,"=Sign##");                                  //~8315R~
REMCOPD(MOVZX_     ,2,"=0##");                                     //~8315R~
REMCOPD(MUL_       ,e,"(%eDX:%eAX)=%eAX*%1");                      //~8405R~
REMCOPD(MUL_b      ,e,"AX=AL*%1");                                 //~8406R~
REMCOPD(NEG_       ,e,"-%1");                                      //~8405R~
REMCOPD(NEG_b      ,e,"-%1%w");                                    //~8405I~
REMCOPD(NOP_       ,c,"NOP");
REMCOPD(NOT_       ,e,"~%1");                                      //~8405R~
REMCOPD(NOT_b      ,e,"~%1%w");                                    //~8405I~
REMCOPD(OpdSz_     ,c,"OperandSizeOverride");                      //~8316R~
REMCOPD(OR_        ,2,"|=");
REMCOPD(OUT_       ,e,"port %1<--%2");                             //~8316R~
REMCOPD(OUTSB_     ,e,"port DX<--DS:[%ESI](1)");                   //~8314R~
REMCOPD(OUTSW_     ,e,"port DX<--DS:[%ESI]");                      //~8405R~
REMCOPD(POP_       ,r,"<--");
REMCOPD(POPA_      ,c,"All Reg<--");
REMCOPD(POPF_      ,e, "%eFlag<--");                               //~8316R~
REMCOPD(PUSH_      ,r,"-->");                                      //~8308R~
REMCOPD(PUSHA_     ,c,"All Reg-->");
REMCOPD(PUSHF_     ,e,"%eFlag-->");
REMCOPD(RCL_       ,e,"(CF:%1) ((= %2");                           //~8405R~
REMCOPD(RCL_b      ,e,"(CF:%1%w) ((= %2");                         //~8405I~
REMCOPD(RCR_       ,e,"(%1:CF) ))= %2");                           //~8405R~
REMCOPD(RCR_b      ,e,"(%1%w:CF) ))= %2");                         //~8405I~
REMCOPD(RDMSR_     ,c,"EDX:EAX=MSR[ECX]");                         //~v320R~
REMCOPD(RDPMC_     ,c,"EDX:EAX=PMC[ECX]");                         //~v320R~
REMCOPD(RDTSC_     ,c,"EDX:EAX=TimeStampCounter");                 //~v320R~
REMCOPD(ROL_       ,e,"%1 ((= %2");                                //~8405R~
REMCOPD(ROL_b      ,e,"%1%w ((= %2");                              //~8405I~
REMCOPD(ROR_       ,e,"%1 ))= %2");                                //~8405R~
REMCOPD(ROR_b      ,e,"%1%w ))= %2");                              //~8405I~
REMCOPD(REP_       ,e,"While(%eCX-- && ZF=1)");
REMCOPD(REPNE_     ,e,"While(%eCX-- && ZF=0)");
//REMCOPD(RET_       ,c,"\x02<=====");                             //~v5i2R~
REMCOPD(RET_       ,c,"\n\x02<=====");                             //~v5i2I~
//REMCOPD(RET_Pop    ,e,"\x02<=====,%eSP+=%1");                    //~v5i2R~
REMCOPD(RET_Pop    ,e,"\n\x02<=====,%eSP+=%1");                    //~v5i2I~
//REMCOPD(RETF_      ,c,"\x02<==========");                        //~v5i2R~
REMCOPD(RETF_      ,c,"\n\x02<==========");                        //~v5i2I~
//REMCOPD(RETF_Pop   ,e,"\x02<==========,%eSP+=%1");               //~v5i2R~
REMCOPD(RETF_Pop   ,e,"\n\x02<==========,%eSP+=%1");               //~v5i2I~
//MCOPD(RSM_       ,0,0);
REMCOPD(SAR_       ,e,"(Signed(%1):CF) >>= %2");                   //~8406R~
REMCOPD(SAR_b      ,e,"(Signed(%1%w):CF) >>= %2");                 //~8406R~
REMCOPD(SAHF_      ,c,"Flag=AH");                                  //~8316R~
REMCOPD(SBB_       ,e,"%1-=%2+CF");                                //~8401R~
REMCOPD(SCASB_     ,e,"AL -? ES:[%EDI++]");                        //~8406R~
REMCOPD(SCASW_     ,e,"%eAX -? ES:[%EDI++]");                      //~8406R~
//MCOPD(SETALC     ,0,0);

REMCOPD(SETO_      ,r,"=(OF==1)");                                 //~8316R~
REMCOPD(SETNO_     ,r,"=(OF==0)");                                 //~8316R~
REMCOPD(SETB_      ,r,"=(CF==1)");                                 //~8316R~
REMCOPD(SETNB_     ,r,"=(CF==0)");                                 //~8316R~
REMCOPD(SETZ_      ,r,"=(ZF==1)");                                 //~8316R~
REMCOPD(SETNZ_     ,r,"=(ZF==0)");                                 //~8316R~
REMCOPD(SETNA_     ,r,"=(CF==1||ZF==1)");                          //~8316R~
REMCOPD(SETA_      ,r,"=(OF==0&&ZF==0)");                          //~8316R~
REMCOPD(SETS_      ,r,"=(SF==1)");                                 //~8316R~
REMCOPD(SETNS_     ,r,"=(SF==0)");                                 //~8316R~
REMCOPD(SETP_      ,r,"=(PF==1)");                                 //~8316R~
REMCOPD(SETNP_     ,r,"=(PF==0)");                                 //~8316R~
REMCOPD(SETL_      ,r,"=(SF!=OF)");                                //~8316R~
REMCOPD(SETNL_     ,r,"=(SF==OF)");                                //~8316R~
REMCOPD(SETNG_     ,r,"=(ZF==1||SF!=OF)");                         //~8316R~
REMCOPD(SETG_      ,r,"=(ZF==0&&SF==OF)");                         //~8316R~

REMCOPD(SGDT_      ,r,"=(Limit,Base) of GDTR");                    //~8406R~
REMCOPD(SHL_       ,e,"(CF:%1) <<= %2");                           //~8405R~
REMCOPD(SHL_b      ,e,"(CF:%1%w) <<= %2");                         //~8405I~
REMCOPD(SHLD_      ,e,"(%1:%2) <<= %3");                           //~8331R~
REMCOPD(SHR_       ,e,"(%1:CF) >>= %2");                           //~8405R~
REMCOPD(SHR_b      ,e,"(%1%w:CF) >>= %2");                         //~8405I~
REMCOPD(SHRD_      ,e,"(%1:%2) >>= %3");                           //~8331R~
REMCOPD(SIDT_      ,r,"=(Limit,Base) of IDTR");                    //~8406R~
REMCOPD(SLDT_      ,r,"=LDTR");
REMCOPD(SMSW_      ,r,"=MSW");
REMCOPD(SS_        ,r,"SS:");                                      //~8315R~
REMCOPD(STC_       ,c,"CF=1");
REMCOPD(STD_       ,c,"DF=1");
REMCOPD(STI_       ,c,"IF=1");
REMCOPD(STOSB_     ,e,"ES:[%EDI++]=AL");                           //~8314R~
REMCOPD(STOSW_     ,e,"ES:[%EDI++]=%eAX");                         //~8314R~
REMCOPD(STR_       ,r,"=TaskReg");
REMCOPD(SUB_       ,2,"-=");
REMCOPD(SYSENTER_  ,c,"\x02==========>R0");                        //+v5i3R~
REMCOPD(SYSEXIT_   ,c,"\n\x02<==========R0");                      //~v5i3R~
REMCOPD(TEST_      ,2," &? ");
REMCOPD(VERR_      ,c,"Verify Read");
REMCOPD(VERW_      ,c,"Verify Write");
REMCOPD(WAIT_      ,c,"WAIT");
REMCOPD(WBINVD_    ,c,"WriteBack,Invalidate Cache");
REMCOPD(WRMSR_     ,c,"MSR[ECX]=EDX:EAX");                         //~v320R~
REMCOPD(XADD_      ,e,"(%1,%2)=(%1+%2,%1)");
REMCOPD(XCHG_      ,2,"<->");
REMCOPD(XLAT_      ,e,"AL=[%EBX+AL]");                             //~8316R~
REMCOPD(XOR_       ,2,"^=");                                       //~8316R~
