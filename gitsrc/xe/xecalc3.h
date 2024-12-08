//CID://+v40RR~:                                                   //~v40RR~
//*******************************************************
//v40R:010720 TC fld# parm support                                 //~v40RI~
//v17f:000501 change TCN to TC and NX option.                      //~v17fI~
//v168:000418 add table format function to TC/TCN cmd              //~v168I~
//            TC[N] fmt [[fldno]{R|L}]                             //~v168I~
//*******************************************************
#define TCHDR_LINEID         '='                                   //~v40RI~
#define TCHDR_LINEID_TRAILER " <==!! TCHDR !!"                     //~v40RI~
#define TCHDR_LINEID_TRAILERSZ (sizeof(TCHDR_LINEID_TRAILER)-1)    //~v40RI~
#define TCHDR_FLDSEPID       ':'                                   //~v40RR~
#define TCHDR_FLDSEPCONTID   '_'                                   //+v40RI~
#define TCHDR_FLDCONTID      '-'                                   //~v40RI~
#define TCFLDNUMID           'F'                                   //~v40RI~
//*******************************************************
int tc_format(PUCLIENTWE Ppcw);                                    //~v17fR~
//*******************************************************          //~v168I~
int *tc_chkhdr(PUCLIENTWE Ppcw,PUFILEH Pplh,PULINEH* Pplabplh);    //~v40RR~
//*******************************************************          //~v40RI~
int tc_helpfmt(void);                                              //~v168I~
