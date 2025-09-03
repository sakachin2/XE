//CID://+vbD5R~:     update#=     2                                //~vbD5I~
//**************************************************************
//* uehmsg.h                                                    //~5827R~
//**************************************************************
//vbD5:250701 (Win)exception handling using DbgHelp API            //~vbD5I~
//*************************************************************
//* uehmsg                                                         //~vbD5R~
//* INPUT      :
//*     p1:exception report
//*     p2:registration record
//*     p3:context record
//*     p4:epatbl ptr
//*     p5:uerrexit msg                                         //~5827I~
//* RETURN     : abend msg area addr
//*             display exception information by msgbox
//*************************************************************
#ifdef WIN_EXH                                                     //~vbD5I~
UCHAR*  uehmsg(PEXCEPTIONREPORTRECORD pexreprec,                   //~vbD5I~
	           	PEXCEPTIONREGISTRATIONRECORD pexregrec,            //~vbD5I~
               	PCONTEXT pctxrec,                                  //+vbD5R~
				UCHAR   *Puerrexitrmsg);                           //~vbD5I~
#else                                                              //~vbD5I~
UCHAR*  uehmsg(PEXCEPTIONREPORTRECORD pexreprec,
	           	PEXCEPTIONREGISTRATIONRECORD pexregrec,
               	PCONTEXTRECORD pctxrec,
				PEPATBL Ppepatbl,                               //~5827I~
				UCHAR   *Puerrexitrmsg);                        //~5827R~
#endif                                                             //~vbD5I~
