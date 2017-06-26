//*CID://+v45cR~:                             update#=    4;       //~v45cR~
//****************************************************************
//xecsr.h
//****************************************************************
//v45c:011209 (BUG)errmsg may override DBCS filename on hdr line   //~v45cI~
//v44k:011204 (BUG)hex corsor line is invalid for the case setcsr is called//~v44kI~
//v137:991003 scroll down when reached to bottom line by field full on dir list//~v137I~
//v09s:970523:(BUG)force csr write after child shell               //~v09sI~
//            (csrwrite bypass write if position not changed)      //~v09sI~
//v09l:970518:csr wait mark in dlcmd or cmd processing             //~v09lI~
//****************************************************************
void csrinit(int Pcharh);
                                                                   //~v137I~
//****************************************************************
void csrterm(void);
                                                                //~4C25I~
//****************************************************************//~4C25I~
int csrrestore(PUCLIENTWE Ppcw);                                //~4C25I~
                                                                //~4C25I~
//****************************************************************//~4C25I~
void csrloctogbl(PUCLIENTWE Ppcw);                              //~4C25I~

//****************************************************************
int csrchangetype(int Pcsrtype);
                                                                   //~v137I~
#define CSRTYPNOR		0						//normal cursor type	
#define CSRTYPREV		1						//reverse cursor type	
#define CSRTYPINS		2						//for insert mode
#define CSRTYPNON 		9						//no display

//**************************************************************** //~v09lI~
int csrsetwait(int Preqtype);                                      //~v09lI~
                                                                   //~v09lI~
//****************************************************************
void csrsetdbcstbl(int Px,int Py,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Pcelopt);

//****************************************************************
int csrsetdbcstbl2(int Px,int Py,UCHAR *Pdbcs,int Plen);

//****************************************************************
void csrcleardbcstbl(int Px,int Py,int Plen);

//****************************************************************
int csrhomepos(int Pclientid);

//****************************************************************
int csrchangetype(int Pcsrtype);

//****************************************************************//~5223I~
int csronthefld(PUCLIENTWE Ppcw,int Prow,int Pfldno,int Poffs); //~5223I~
#define FROMLEFT  -1                                            //~5C09R~
                                                                   //~v44kI~
//**************************************************************** //~v44kI~
int csronthefldchk(PUCLIENTWE Ppcw,int Prow,int Pfldno,int Poffs); //~v44kI~
                                                              //~4C23I~
//****************************************************************
int csrwrite(PUCLIENTWE Ppcw);
                                                                //~5423I~
//**************************************************************** //~v09sI~
void csrforcewritereq(void);                                       //~v09sR~
                                                                   //~v09sI~
//************************************************************  //~5423I~
void csrchardown(PUCLIENTWE Ppcw);                              //~5423I~
                                                                //~5423I~
//************************************************************  //~5423I~
void csrcharright(PUCLIENTWE Ppcw);                             //~5423I~
                                                                   //~v137I~
//************************************************************     //~v137I~
int csrnexttaboftheline(PUCLIENTWE Ppcw);                          //~v137I~
                                                                   //~v45cI~
//************************************************************     //~v45cI~
int  csrresetobdbcs(int Pdest,int Px,int Py);                      //+v45cR~
