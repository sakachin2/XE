//*************************************************************
//*udaitf.c   instruction table generation for FPU
//*           included into udamtf.c
//*************************************************************
//*************************************************************
//*   OP       MN      op1,sz1,op2,sz2,op3 ,cls1,cls2,cls3,rtype,subrtn//~8308R~
//ITGN3(9B,D9, 6,FSTENV ,M  ,f  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~8308R~
//ITGN3(9B,D9, 7,FSTCW  ,M  ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~8308R~
//ITGN3(9B,DB,E0,FENI   ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~8308R~
////GN3(9B,DB,E1,FDISI  ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~8308R~
//ITGN3(9B,DB,E2,FCLEX  ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~8308R~
//ITGN3(9B,DB,E3,FINIT  ,0  ,0  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~8308R~
//ITGN3(9B,DD, 6,FSAVE  ,M  ,n  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~8308R~
//ITGN3(9B,DD, 7,FSTSW  ,M  ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~8308R~
//ITGN3(9B,DF,E0,FSTSW  ,AX ,w  ,0  ,0  ,0,0 ,_   ,_   ,_   ,_,0); //~8308R~

ITGN2(D8, 0,   FADD   ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0);//ST op %1//~8319R~
ITGN2(D8, 1,   FMUL   ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(D8, 2,   FCOM   ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(D8, 3,   FCOMP  ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(D8, 4,   FSUB   ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(D8, 5,   FSUBR  ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(D8, 6,   FDIV   ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(D8, 7,   FDIVR  ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~

ITGN2(D8,C0,   FADD   ,ST ,0  ,STi,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D8,C8,   FMUL   ,ST ,0  ,STi,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D8,D0,   FCOM   ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0);//ST?=STi//~8308R~
ITGN2(D8,D8,   FCOMP  ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(D8,E0,   FSUB   ,ST ,0  ,STi,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D8,E8,   FSUBR  ,ST ,0  ,STi,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D8,F0,   FDIV   ,ST ,0  ,STi,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D8,F8,   FDIVR  ,ST ,0  ,STi,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~

ITGN2(D9, 0,   FLD    ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9, 2,   FST    ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9, 3,   FSTP   ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9, 4,   FLDENV ,M  ,f  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9, 5,   FLDCW  ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8328R~
ITGN2(D9, 6,   FNSTENV,M  ,f  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9, 7,   FNSTCW ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~

ITGN2(D9,C0,   FLD    ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,C8,   FXCH   ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,D0,   FNOP   ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,D8,   FSTP   ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //+8404I~
ITGN2(D9,E0,   FCHS   ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,E1,   FABS   ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,E4,   FTST   ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,E5,   FXAM   ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,E8,   FLD1   ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,E9,   FLDL2T ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,EA,   FLDL2E ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,EB,   FLDPI  ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,EC,   FLDLG2 ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,ED,   FLDLN2 ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,EE,   FLDZ   ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~

ITGN2(D9,F0,   F2XM1  ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,F1,   FYL2X  ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,F2,   FPTAN  ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,F3,   FPATAN ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,F4,   FXTRACT,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,F5,   FPREM1 ,0  ,0  ,0  ,0  ,0,0 ,387 ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,F6,   FDECSTP,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,F7,   FINCSTP,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,F8,   FPREM  ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,F9,   FYL2XP1,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,FA,   FSQRT  ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,FB,   FSINCOS,0  ,0  ,0  ,0  ,0,0 ,387 ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,FC,   FRNDINT,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,FD,   FSCALE ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,FE,   FSIN   ,0  ,0  ,0  ,0  ,0,0 ,387 ,FPU ,_   ,_,0);   //~8308R~
ITGN2(D9,FF,   FCOS   ,0  ,0  ,0  ,0  ,0,0 ,387 ,FPU ,_   ,_,0);   //~8308R~

ITGN2(DA, 0,   FIADD  ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0);//ST op %1//~8308R~
ITGN2(DA, 1,   FIMUL  ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DA, 2,   FICOM  ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DA, 3,   FICOMP ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DA, 4,   FISUB  ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DA, 5,   FISUBR ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DA, 6,   FIDIV  ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DA, 7,   FIDIVR ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~

ITGN2(DA,E9,   FUCOMPP,0  ,0  ,0  ,0  ,0,0 ,387 ,FPU ,_   ,_,0);   //~8308R~

ITGN2(DB, 0,   FILD   ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DB, 2,   FIST   ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DB, 3,   FISTP  ,M  ,d  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DB, 5,   FLD    ,M  ,t  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DB, 7,   FSTP   ,M  ,t  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DB,E0,   FNENI  ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //+8404R~
ITGN2(DB,E1,   FNDISI ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //+8404I~
ITGN2(DB,E2,   FNCLEX ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DB,E3,   FNINIT ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DB,E4,   FSETPM ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //+8404I~

ITGN2(DC, 0,   FADD   ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0);//ST op %1//~8308R~
ITGN2(DC, 1,   FMUL   ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DC, 2,   FCOM   ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DC, 3,   FCOMP  ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DC, 4,   FSUB   ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DC, 5,   FSUBR  ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DC, 6,   FDIV   ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DC, 7,   FDIVR  ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~

ITGN2(DC,C0,   FADD   ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DC,C8,   FMUL   ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DC,D0,   FCOM   ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0);//ST?=STi//~8328I~
ITGN2(DC,D8,   FCOMP  ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8328I~
ITGN2(DC,E0,   FSUBR  ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DC,E8,   FSUB   ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DC,F0,   FDIVR  ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DC,F8,   FDIV   ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~

ITGN2(DD, 0,   FLD    ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DD, 2,   FST    ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DD, 3,   FSTP   ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DD, 4,   FRSTOR ,M  ,n  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DD, 6,   FNSAVE ,M  ,n  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DD, 7,   FNSTSW ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~

ITGN2(DD,C0,   FFREE  ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DD,D0,   FST    ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DD,D8,   FSTP   ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~

ITGN2(DD,E0,   FUCOM  ,STi,0  ,0  ,0  ,0,0 ,387 ,FPU ,_   ,_ST,0);//ST -? %1//~8308R~
ITGN2(DD,E8,   FUCOMP ,STi,0  ,0  ,0  ,0,0 ,387 ,FPU ,_   ,_ST,0); //~8308R~

ITGN2(DE, 0,   FIADD  ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0);//ST op %1//~8308R~
ITGN2(DE, 1,   FIMUL  ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DE, 2,   FICOM  ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DE, 3,   FICOMP ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DE, 4,   FISUB  ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DE, 5,   FISUBR ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DE, 6,   FIDIV  ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~
ITGN2(DE, 7,   FIDIVR ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //~8308R~

ITGN2(DE,C0,   FADDP  ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DE,C8,   FMULP  ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
//GN2(DE,D0,   FCOMP  ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_ST,0); //+8404R~
ITGN2(DE,D9,   FCOMPP ,0  ,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8322R~
ITGN2(DE,E0,   FSUBRP ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DE,E8,   FSUBP  ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DE,F0,   FDIVRP ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DE,F8,   FDIVP  ,STi,0  ,ST ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~

ITGN2(DF, 0,   FILD   ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DF, 2,   FIST   ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DF, 3,   FISTP  ,M  ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DF, 4,   FBLD   ,M  ,t  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DF, 5,   FILD   ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DF, 6,   FBSTP  ,M  ,t  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~
ITGN2(DF, 7,   FISTP  ,M  ,q  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~

//GN2(DF,C0,   FFREE  ,STi,0  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //+8404R~
ITGN2(DF,E0,   FNSTSW ,AX ,w  ,0  ,0  ,0,0 ,_   ,FPU ,_   ,_,0);   //~8308R~

//*************************************************************
