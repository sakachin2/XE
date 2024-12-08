//**************************************************************
//* uehmsg.h                                                    //+5827R~
//**************************************************************
//*************************************************************
//* ä÷êîñº     : uehmsg
//* INPUT      :
//*     p1:exception report
//*     p2:registration record
//*     p3:context record
//*     p4:epatbl ptr
//*     p5:uerrexit msg                                         //~5827I~
//* RETURN     : abend msg area addr
//* ã@î\äTóv   :
//*             display exception information by msgbox
//*************************************************************
UCHAR*  uehmsg(PEXCEPTIONREPORTRECORD pexreprec,
	           	PEXCEPTIONREGISTRATIONRECORD pexregrec,
               	PCONTEXTRECORD pctxrec,
				PEPATBL Ppepatbl,                               //~5827I~
				UCHAR   *Puerrexitrmsg);                        //~5827R~
