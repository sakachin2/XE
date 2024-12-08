//*************************************************************    //~8211I~
//*udaitmn.h                                                       //~8211I~
//*************************************************************    //~8211I~
//*ope code mnemonic generation                                    //~8211I~
//*    [\1]xxxx[\0yyyy]\0 format                                   //~8213R~
//      \1  :id of 2 string is concatinated                        //~8213R~
//      xxxx:mnemonic                                              //~8213R~
//      0   :string terminater                                     //~8213I~
//      yyyy:2nd mnemonic for the case nemonic is different by operand size//~8213R~
//       or  for FPU name of the case WAIT (9B) is prefixed        //+8213I~
//*************************************************************    //~8213I~
#define  INSTMN(MN)  		static UCHAR Smn_##MN[]={#MN}          //~8213R~
#define  INSTMNC(MN,CONST)  static UCHAR Smn_##MN[]={CONST}        //~8213R~
#define  INSTMN2(MN,MN2)  	static UCHAR Smn_##MN[]={"\1" #MN "\0" #MN2}//~8213R~
//*************************************************************    //~8211I~
