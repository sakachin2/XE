//*CID://+va7jR~:                             update#=    7;       //~va7jR~
//****************************************************************
//*xelcmd4.h
//****************************************************************
//va7j:100820 (BUG)non ascii char on lineno fld of ebc file is not show for lcmd "+".//~va7jI~
//v57H:040612 (BUG)tc cmd;no err set if one of two opd is valid for 2 opd type//~v57HI~
//v53E:031018 TC cmd;reset previous err line                       //~v53EI~
//v47i:020302 join cmd support:"join nx/x .a .b"                   //~v47iI~
//v0i7:980520 line cmd split cmd('S')/join('J') support            //~v0i7I~
//v0i0:980429 lcmd skip/bandle support                             //~v0i0I~
//v0b5:970725 move lcmdshift to lcmd4.c                            //~v0asI~
//v0av:970720-fixed lrecl support(mergin support,MAXLEN=nn[N])     //~v0avI~
//v0as:970719 general comment command(+)                           //~v0asI~
//v0aq:970719 add lcmd //(c comment out)
//**************************************************************** //~v0asI~
#ifdef GBL_LCMD4                                                   //~v57HI~
    int Glcmd4errctr=0;                                            //~v57HI~
#else                                                              //~v57HI~
    extern int Glcmd4errctr;                                       //~v57HI~
#endif                                                             //~v57HI~
//**************************************************************** //~v57HI~
int lcmdshiftbs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,UCHAR Pcmd,//~v0i0I~
				int Pbandle,int Pskip);                            //~v0i0I~
                                                                   //~v0i0I~
//**************************************************************** //~v0i0I~
int lcmdshift(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,UCHAR Pcmd);//~v0asI~
                                                                   //~v0i0I~
//**************************************************************** //~v0i0I~
int lcmdcombs(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~v0i0I~
				int Pbandle,int Pskip);                            //~v0i0I~
//**************************************************************** //~v0aqI~
int lcmdcom(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,char *Pcomment);//~v0aqR~
                                                                   //~v0aqI~
//**************************************************************** //~v0asR~
int lcmdgcom(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2);         //~v0asR~
                                                                   //~v0asI~
//**************************************************************** //~v0i7I~
int lcmdsplit(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~v0i7I~
				int Pbandle,int Pskip);                            //~v0i7I~
                                                                   //~v0i7I~
//**************************************************************** //~v0asI~
int lcmdjoin(PUCLIENTWE Ppcw,PULINEH Pplh1,PULINEH Pplh2,int Prepeat,//~v0i7I~
				int Pbandle,int Pskip);                            //~v0i7I~
                                                                   //~v0i7I~
//**************************************************************** //~v0i7I~
void lcmddbcssplit(PULINEH Pplh,int Ppos);                         //~v0asI~
                                                                   //~v0avI~
//**************************************************************** //~v0avI~
void lcmdshifterr(PULINEH Pplh,PULINEH Pplhx,PULINEH *Ppplherr);   //~v0avI~
                                                                   //~v47iI~
//**************************************************************** //~v53EI~
int lcmdresetshifterr(PULINEH Pplh,int Pchkexsw);                  //~v53EI~
                                                                   //~v53EI~
//**************************************************************** //~v47iI~
int lcmdjoinx(PUCLIENTWE Ppcw,PULINEH Pplh);                       //~v47iI~
//**************************************************************** //~va7jI~
int filecvlcmd(int Popt,PUFILEH Ppfh,UCHAR *Pdddata,UCHAR *Pdddbcs,UCHAR *Plcmd,int Plen);//~va7jI~
#define  FCLCO_2FILE            0x01    //set into plhdata         //+va7jI~
