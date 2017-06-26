//*CID://+vaj0R~:                             update#=   54;       //~vagmR~//~vaj0R~
//**************************************************************** //~v0baI~
//xefile12.h                                                       //~v0baI~
//**************************************************************** //~v0baI~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW|FD|HD|F|H})//~vaj0I~
//vagm:120825 (BUG)binfile width change;UUHTWIDTH & UUHTREP is different undoctr(2step undo/redo)//~vagmI~
//v76w:070808 for precompile chk of UTF( version                   //~v76wI~
//v73b:070109*(BUG)spf renum force leave dbcs 1st byte at EOL(col80)//~v73bI~
//v71Y:061113 keep spf version number over renum force;(currently reset all renumed if spferr at loadtime)//~v71YI~
//v625:050309 vhex mode support for wxp **/***(line split no consideration)//~v625I~
//v61g:050226 diffrrent errmsg for cobnum fld err                  //~v61gI~
//v60u:050201 xpr cmd;add -tabon option to write tab display char(default istaboff)//~v60uI~
//            (tab display char may not be printed and line is shorten)//~v60uI~
//v53d:030923 option seti/setr without renum                       //~v53dI~
//v506:021019 add "set" option for renum cmd;set num fld on specified colomn//~v506I~
//v47A:020321 renum and num clear for cobk                         //~v47AI~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd            //~v45xI~
//            move filecutoff to fcmd4                             //~v45xI~
//v45u:011216 num cutoff cmd to split continued line               //~v45uI~
//v445:011201 binary file support for xprint **/***                //~v445I~
//v42v:011009 option to allow cob num fld is all space             //~v42vI~
//v420:010918 cob fld num clear option;num clear cob               //~v420I~
//v40W:010722 set spfnum(cob) after isrt topline cid(cob)          //~v40WI~
//v40F:010709 COB support:num clear(clear col72-80)                //~v40FI~
//v40k:010526 screen current print("***")                          //~v40kR~
//v40h:010526 xprint **;like as print screen                       //~v40hI~
//v0ib:980530 v0i9 cotinued for other than file copy               //~v0ibI~
//v0du:970909 for performance,use flag once chked spfnumok         //~v0duI~
//            set on when chked,reset when line update or insert.  //~v0duI~
//v0ct:970814 RENUM(NUM reset) Force option for spf file           //~v0ctI~
//v0cn:970813 RENUM undo support(move filerenum from xefile to xefile12)//~v0cnI~
//v0cl:970811 spf NUM field support                                //~v0clI~
//v0ba:970726 split xefile,xefile12(save)                          //~v0baI~
//**************************************************************** //~v0baI~
int filesave(PUCLIENTWE Ppcw,int Pendsw,PUFILEH Ppfh,PULINEH Pplh1,PULINEH Pplh2,UCHAR *Poutfile);//~v445R~
#define FSENDSW_SAVE  	0x00        //save cmd                     //~v0ibI~
#define FSENDSW_END   	0x01        //end cmd,if off save cmd      //~v0ibI~
#define FSENDSW_APPEND	0x03                                       //~v0ibI~
#define FSENDSW_BANDLE	0x10                                       //~v0ibI~
#define FSENDSW_PRTSCR	0x20        //save to tempwork for print screen//~v40hI~
#define FSENDSW_PRTPAGE	0x40        //print current page only      //~v40kI~
#define FSENDSW_PRTTAB 	0x80        //write tab display chat       //~v60uI~
#define FSENDSW_WXP    	0x0100      //wxp cmd                      //~v625R~
#ifdef UTF8UCS2                                                    //~v76wI~
#define FSENDSW_IGNCVER	0x0200      //ignore translation err, but indicate by rc//~v76wI~
#endif                                                             //~v76wI~
#define FSENDSW_CUT 	0x0400      //cb2 to chk recfm=v mfh       //~vaj0R~
                                                                   //~v0clI~
//**************************************************************** //~v0ibI~
                                                                   //~v0ibI~
//**************************************************************** //~v0cnI~
//int filerenum(PUCLIENTWE Ppcw,UFILEH *Ppfh,int Popt);            //~v506R~
int filerenum(PUCLIENTWE Ppcw,UFILEH *Ppfh,int Popt,ULONG Pnumfld);//~v506I~
#define RENUMOPT_FORCE     0x01                                    //~v40FI~
#define RENUMOPT_CLEAR     0x02                                    //~v40FI~
#define RENUMOPT_COB       0x04                                    //~v420I~
#define RENUMOPT_COBK      0x08                                    //~v47AI~
#define RENUMOPT_SETI      0x10     //insert num fld               //~v506I~
#define RENUMOPT_SETR      0x20     //repl   num fld               //~v506I~
#define RENUMOPT_RENUM     0x40     //renum option                 //~v53dI~
#define RENUMOPT_NOUPCTR   0x80                                    //~vagmI~
                                                                   //~v0cnI~
//**************************************************************** //~v0clI~
//*rc of filespfchk                                                //~v40EI~
#define SPFERRLEN  0x01                                            //~v0clI~
#define SPFERRNUM  0x02                                            //~v0clI~
#define SPFERRNOTSPC  0x04                                         //~v42vI~
#define SPFERRCOBNUM  0x08     //cobol number  fld err             //~v61gI~
                                                                   //~v42vI~
int filespfchk(PULINEH Pplh,int Pspfpos,int *Pmaxver);             //~v0clR~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
void filespfloadnum(PUFILEH Ppfh,int Pmaxver,int Perrsw);          //~v0ctI~
                                                                   //~v0clI~
//************************************************************     //~v0clI~
//int  filesetspfnum(PUFILEH Ppfh,PULINEH Pplh,char * Pdata,char *Pdbcs,int Popt);//~v73bR~
//int  filesetspfnum(PUFILEH Ppfh,PULINEH Pplh,char * Pdata,char *Pdbcs,int Pnewlen,int Popt);//~v76wR~
int  filesetspfnum(PUFILEH Ppfh,PULINEH Pplh,char *Pdata,char *Pdbcs,int Pnewlen,int Popt);//~v76wI~
#define SETSPFNUM_PLHVER      0x01                                 //~v40FI~
#define SETSPFNUM_CLEAR       0x02  //spfnum/cob fld clear req     //~v40FI~
#define SETSPFNUM_FORCE       0x04  //force renum/clear(by cmd)    //~v40FI~
#define SETSPFNUM_COB         0x08  //cob fld clear req            //~v420I~
#define SETSPFNUM_COBKRENUM   0x10  //renum cob fld of cobk file   //~v47AR~
#define SETSPFNUM_ATSAVE      0x20  //automaticaly set at save     //~v71YI~
                                                                   //~v0clI~
//************************************************************     //~v0cnI~
void filespfnumedit(PUFILEH Ppfh,PULINEH Pplh,int Popt);           //~v0cnI~
#define SPFNUMEDIT_CURVER  0x01 //set currlen version              //~v40WI~
#define SPFNUMEDIT_COB     0x02                                    //~v40WI~
#define SPFNUMEDIT_CIDTOP  0x04                                    //~v40WI~
                                                                   //~v0cnI~
//**************************************************************** //~v0clI~
int fileresetver(PUCLIENTWE Ppcw,UFILEH *Ppfh,int Pver);           //~v0clR~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
int filesetvernum(PUFILEH Ppfh,PULINEH Pplh);                      //~v0clR~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
void filesetlineerr(PULINEH Pplh);                                 //~v0clI~
                                                                   //~v0clI~
//**************************************************************** //~v0clI~
void filespfpfeerr(void);                                          //~v0clI~
                                                                   //~v0ctI~
//**************************************************************** //~v0ctI~
int fileisvalidspfline(PUFILEH Ppfh,PULINEH Pplh,int Popt);        //~v0duI~
//**************************************************************** //~vaj0I~
int fileadjustfh4cut(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int Psaveopt);//~vaj0I~
#define FACO_OPEN    0x01	//from f14                             //~vaj0I~
#define FACO_PROFILE 0x02	//update profile                       //+vaj0I~
