//*************************************************************
//*udaitrmf.c instruction remark edit patern difinition for FPU
//*           included into udamtf.c
//*************************************************************
#include <udaitrm.h>
//*************************************************************
//*remark type
//*  type:
//* 	'c'         //constant
//* 	'r'         //right unary like as AX++
//* 	'l'         //right unary like as ++AX
//* 	'2'         //binary operator
//* 	'e':        //need edit %
//* 	     %1,%2,%3:operand
//* 	     %n      :STi reg number                               //+8404R~
//* 	     %i      :integer width 16/32/64                       //+8404R~
//* 	     %r      :real    width 32/64/80                       //~8404I~
//*************************************************************
//*fpu
REMCOPD(F2XM1_     ,c,"ST=2**ST-1");
REMCOPD(FABS_      ,c,"Sign(ST)=0");
REMCOPD(FADD_      ,2,"+=");
REMCOPD(FADD_ST    ,e,"ST+=%1%r");                                 //~8404R~
REMCOPD(FADDP_     ,e,"%1+=%2,<--");
REMCOPD(FBLD_      ,r,"(packed bcd)-->");                          //~8404R~
REMCOPD(FBSTP_     ,r,"(packed bcd)<--");                          //~8404R~
REMCOPD(FCHS_      ,c,"-ST");
REMCOPD(FCOM_ST    ,e,"ST -? %1%r");                               //~8404R~
REMCOPD(FCOMP_ST   ,e,"ST -? %1%r,<--");                           //~8404R~
REMCOPD(FCOMPP_    ,c,"ST -? ST(1),<--,<--");                      //~8404R~
REMCOPD(FCOS_      ,c,"ST=cos(ST)");
REMCOPD(FDECSTP_   ,c,"StackTopPtr--");

REMCOPD(FDIV_      ,2,"/=");
REMCOPD(FDIVP_     ,e,"%1/=%2,<--");                               //~8221I~
REMCOPD(FDIVR_     ,e,"%1=%2/%1");
REMCOPD(FDIVRP_    ,e,"%1=%2/%1,<--");                             //~8221I~
REMCOPD(FDIV_ST    ,e,"ST/=%1%r");                                 //~8404R~
REMCOPD(FDIVR_ST   ,e,"ST=%1%r/ST");                               //~8404R~

REMCOPD(FFREE_     ,e,"TAG(%n)=11B");                              //+8404R~
REMCOPD(FIADD_ST   ,e,"ST+=%1%i");                                 //+8404R~
REMCOPD(FICOM_ST   ,e,"ST -? %1%i");                               //+8404R~
REMCOPD(FICOMP_ST  ,e,"ST -? %1%i,<--");                           //+8404R~

REMCOPD(FIDIV_ST   ,e,"ST/=%1%i");                                 //+8404R~
REMCOPD(FIDIVR_ST  ,e,"ST=%1%i/ST");                               //+8404R~

REMCOPD(FILD_      ,e,"%1%i-->");                                  //+8404R~
REMCOPD(FIMUL_ST   ,e,"ST*=%1%i");                                 //+8404R~
REMCOPD(FINCSTP_   ,c,"StackTopPtr++");
REMCOPD(FIST_      ,e,"%1%i=ST");                                  //+8404R~
REMCOPD(FISTP_     ,e,"%1%i<--");                                  //+8404R~

REMCOPD(FISUB_ST   ,e,"ST-=%1%i");                                 //+8404R~
REMCOPD(FISUBR_ST  ,e,"ST=%1%i-ST");                               //+8404R~

REMCOPD(FLD_       ,e,"%1%r-->" );                                 //~8404R~
REMCOPD(FLD1_      ,c,"+1.0-->");
REMCOPD(FLDCW_     ,l,"CW=" );                                     //~8328R~
REMCOPD(FLDENV_    ,l,"fpu env=");
REMCOPD(FLDL2E_    ,c,"log2(e)-->");
REMCOPD(FLDL2T_    ,c,"log2(10)-->");
REMCOPD(FLDLG2_    ,c,"Log10(2)-->");
REMCOPD(FLDLN2_    ,c,"loge(2)-->");
REMCOPD(FLDPI_     ,c,"Pi-->");
REMCOPD(FLDZ_      ,c,"+0.0-->");
REMCOPD(FMUL_      ,2,"*=");                                       //~8328R~
REMCOPD(FMUL_ST    ,e,"ST*=%1%r");                                 //~8404R~
REMCOPD(FMULP_     ,e,"%1*=%2,<--");
REMCOPD(FNCLEX_    ,c,"SW[0-7,15]=0");
REMCOPD(FNDISI_    ,c,"FNDISI");                                   //~8404R~
REMCOPD(FNENI_     ,c,"FNENI");                                    //~8404R~
REMCOPD(FNINIT_    ,c,"FNINIT");
REMCOPD(FNOP_      ,c,"Nop");
REMCOPD(FNSAVE_    ,r,"=fpu status");
REMCOPD(FNSTCW_    ,r,"=CW");
REMCOPD(FNSTENV_   ,r,"=fpu env,CW[0..5]=111111B");
REMCOPD(FNSTSW_    ,r,"=SW");                                      //~8404R~
REMCOPD(FPATAN_    ,c,"ST(1)=arctan(ST(1)/ST),<--");
REMCOPD(FPREM_     ,c,"ST%=ST(1)");
REMCOPD(FPREM1_    ,c,"ST%=ST(1)");
REMCOPD(FPTAN_     ,c,"ST=tan(ST),1.0-->");
REMCOPD(FRNDINT_   ,c,"ST=round(ST)");
REMCOPD(FRSTOR_    ,l,"fpu status=");
REMCOPD(FSCALE_    ,c,"ST*=2**ST(1)");
REMCOPD(FSETPM_    ,c,"FSETPM");                                   //~8404R~
REMCOPD(FSIN_      ,c,"ST=sin(ST)");
REMCOPD(FSINCOS_   ,c,"(cos(ST),sin(ST))-->");
REMCOPD(FSQRT_     ,c,"ST=root(ST)");
REMCOPD(FST_       ,e,"%1%r=ST");                                  //~8404R~
REMCOPD(FSTP_      ,e,"%1%r<--");                                  //~8404R~

REMCOPD(FSUB_      ,2,"-=");
REMCOPD(FSUBP_     ,e,"%1-=%2,<--");                               //~8221I~
REMCOPD(FSUBR_     ,e,"%1=%2-%1");
REMCOPD(FSUBRP_    ,e,"%1=%2-%1,<--");                             //~8221I~
REMCOPD(FSUB_ST    ,e,"ST-=%1%r");                                 //~8404R~
REMCOPD(FSUBR_ST   ,e,"ST=%1%r-ST");                               //~8404R~

REMCOPD(FTST_      ,c,"ST ? 0.0");
REMCOPD(FUCOM_ST   ,l,"ST -? ");                                   //~8404R~
REMCOPD(FUCOMP_ST  ,e,"ST -? %1,<--");                             //~8404R~
REMCOPD(FUCOMPP_   ,c,"ST -? ST(1),<--,<--");                      //~8404R~
REMCOPD(FXAM_      ,c,"C1=Sign(ST)");
REMCOPD(FXCH_      ,l,"ST<->");
REMCOPD(FXTRACT_   ,c,"(significant(ST),exp(ST))-->");
REMCOPD(FYL2X_     ,c,"ST(1)*=log2(ST),<--");
REMCOPD(FYL2XP1_   ,c,"ST(1)*=log2(ST+1.0),<--");

