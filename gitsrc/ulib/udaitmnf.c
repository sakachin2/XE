//*************************************************************
//*udaitmnf.c
//*** instruction MNEMONIC static symbol generation for FPU
//***   included into udamtf.c
//*************************************************************
#include <udaitmn.h>
//*************************************************************
//*-------------------
    INSTMN (F2XM1   );
    INSTMN (FABS    );
    INSTMN (FADD    );
    INSTMN (FADDP   );
    INSTMN (FBLD    );
    INSTMN (FBSTP   );
    INSTMN (FCHS    );
    INSTMN (FCOM    );
    INSTMN (FCOMP   );
    INSTMN (FCOMPP  );
    INSTMN (FCOS    );
    INSTMN (FDECSTP );
//  INSTMN (FDISI   );
    INSTMN (FDIV    );
    INSTMN (FDIVP   );
    INSTMN (FDIVR   );
    INSTMN (FDIVRP  );
    INSTMN (FFREE   );
    INSTMN (FIADD   );
    INSTMN (FICOM   );
    INSTMN (FICOMP  );
    INSTMN (FIDIV   );
    INSTMN (FIDIVR  );
    INSTMN (FILD    );
    INSTMN (FIMUL   );
//*-------------------
    INSTMN (FINCSTP );
    INSTMN (FIST    );
    INSTMN (FISTP   );
    INSTMN (FISUB   );
    INSTMN (FISUBR  );
    INSTMN (FLD     );
    INSTMN (FLD1    );
    INSTMN (FLDCW   );                                             //~8328R~
    INSTMN (FLDENV  );
    INSTMN (FLDL2E  );
    INSTMN (FLDL2T  );
    INSTMN (FLDLG2  );
    INSTMN (FLDLN2  );
    INSTMN (FLDPI   );
    INSTMN (FLDZ    );
    INSTMN (FMUL    );
    INSTMN (FMULP   );
    INSTMN2(FNCLEX,FCLEX);                                         //~8213R~
    INSTMN2(FNDISI,FDISI);                                         //+8404R~
    INSTMN2(FNENI,FENI);                                           //+8404R~
    INSTMN2(FNINIT,FINIT);                                         //~8213R~
    INSTMN (FNOP    );
    INSTMN2(FNSAVE,FSAVE);                                         //~8213R~
    INSTMN2(FNSTCW,FSTCW);                                         //~8213R~
    INSTMN2(FNSTENV,FSTENV);                                       //~8213R~
    INSTMN2(FNSTSW,FSTSW);                                         //~8213R~
    INSTMN (FPATAN  );
    INSTMN (FPREM   );
    INSTMN (FPREM1  );
    INSTMN (FPTAN   );
    INSTMN (FRNDINT );
    INSTMN (FRSTOR  );
    INSTMN (FSCALE  );
    INSTMN (FSETPM  );                                             //+8404R~
    INSTMN (FSIN    );
    INSTMN (FSINCOS );
    INSTMN (FSQRT   );
//*-------------------
    INSTMN (FST     );
    INSTMN (FSTP    );
    INSTMN (FSUB    );
    INSTMN (FSUBP   );
    INSTMN (FSUBR   );
    INSTMN (FSUBRP  );
    INSTMN (FTST    );
    INSTMN (FUCOM   );
    INSTMN (FUCOMP  );
    INSTMN (FUCOMPP );
    INSTMN (FXAM    );
    INSTMN (FXCH    );
    INSTMN (FXTRACT );
    INSTMN (FYL2X   );
    INSTMN (FYL2XP1 );
//*-------------------
//****************************************************
