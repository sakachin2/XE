//*CID://+va8jR~:                             update#=   10;       //~va8jR~
//**************************************************************** //~va53I~
//xeacbdmy.h                                                       //~va53I~
// to avoid link not used function                                 //~va53I~
//**************************************************************** //~va53I~
//va8j:101013 SPLit cmd;dbcs consideration for TAIL cut without SBCS option .//~va8jI~
//va53:100419 num setr/seti should chk margin/lrecl overflow       //~va53I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//**************************************************************** //~va53I~
void chartabclear(UCHAR *Pdbcs,int Plen){return;}                  //~va53I~
int setobtabdbcs(UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Prangelen){return 0;}//~va53R~
int xeebc_setdbcstblplh(int Popt,PUFILEH Ppfh,PULINEH Pplh,int Plen){return 0;}//~va53I~
int xeebc_setdbcstbl(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen){return 0;}//~va50I~
int setdbcssplit(UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar){return 0;}//~va50I~
int xeebc_m2bsetdbcs(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char **Poutdata,char **Poutdbcs,int *Ppoutlen)//~va50I~
{return 0;}                                                        //~va50I~
int xeebc_setdbcssplitsetsosi(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Prepch)//+va8jR~
{return 0;}                                                        //~va8jI~
