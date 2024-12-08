//CID://+v0fzR~:**           update#=  2                           //+v0fzR~
//****************************************************************//~5810I~
//*xeini2.h                                                     //~5810I~
//****************************************************************//~5810I~
//v0fz:971201 print/xprint cmd on .ini for each os                 //~v0fzI~
//**************************************************               //~v0fzI~
//*ini2term                                                        //~v0fzI~
//* term proc(ufree),called from gblterm                           //~v0fzI~
//*parm :none                                                      //~v0fzI~
//*ret  :none                                                      //~v0fzI~
//**************************************************               //~v0fzI~
void ini2term(void);                                               //~v0fzR~
//**************************************************            //~5810I~
//*iniwother                                                    //~5810I~
//* write other parameter                                       //~5810I~
//*parm1:output filename                                        //~5810I~
//*parm2:output FILE *                                          //~5810I~
//*parm3:section id string                                      //~5810I~
//*ret  :rc                                                     //~5810I~
//**************************************************            //~5810I~
int iniwother(UCHAR *Pfilename,FILE *Pfh,UCHAR *Psectionid);    //~5810I~
                                                                //~5810I~
//**************************************************            //~5810I~
//*inirother                                                    //~5810I~
//* other parameter section line process                        //~5810I~
//*parm1:parsed word number                                     //~5810I~
//*parm2:read area                                              //~5810I~
//*ret :rc                                                      //~5810I~
//**************************************************            //~5810I~
int inirother(int Pwordno,UCHAR *Pbuff);                        //~5810R~
