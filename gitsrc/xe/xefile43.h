//*CID://+vbBwR~:                             update#=     1;      //+vbBwI~
//****************************************************************//~4C23I~
//xefile43.h                                                       //~v0dxR~
//****************************************************************//~4C23I~
//vbBw:241127 label support for cid clear                          //+vbBwI~
//v0dx:970914 split fileclear from xefile4.c                       //~v0dxI~
//v0df:970831 (BUG)cid not set if cont exist.(see also v0d3)       //~v0dfI~
//v0cz:970818 null cid //+NONE~R                                   //~v0ciI~
//v0ci:970810 (BUG)cid clear abend(oldpos is last cidpos)          //~v0ciI~
//v0cc:970803 filegetcidlen return last cidpos                     //~v0ccI~
//v0cb:970802 split allow for long rec even if at out of mergin    //~v0cbI~
//            EOL   allow for long rec even if at out of mergin    //~v0cbI~
//v0c8:970802 filecidlrecl return len in mergin if cidps<mergin    //~v0c8I~
//v0c1:970728 errornous cid shift when 2 continuous cid            //~v0c1I~
//v0bv:970728 split file4-->file42                                 //~v0bvI~
//v0be:970725 filemerginchk return lrecl witoutcid(change over v0b7)//~v0beI~
//v0b7:970725 filemerginchk return avail space(last data to mergin)//~v0b7I~
//v0av:970720-fixed lrecl support                                  //~v0avI~
//           -filetoplinecid/filegetcid return rc                  //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//v09F:970614:CID postfix support                                  //~v09FI~
//            (change CIDTBL fmt,cidfmt conatin only prefix and postfix)//~v09FI~
//v09r:970521:arbitaly CID type by first line                      //~v09rI~
//            -filecidtypechk return cidtbl ptr not but cid for get pos//~v09rI~
//            -filegetcid parm 0:always chk first line,2 chk if sline==0//~v09rI~
//v06r:960325:cid pos for lineno field len =4 as default              //~v06rI~
//            and support CID shift(colomn re-arange)                 //~v06rI~
//*v014:950624:bug:when save not displayed line after copy file //~v014I~
//*v012:950611:fixed CID                                        //~5611I~
//****************************************************************//~5611I~
//************************************************************  //~5225I~
// filecidclear                                                 //~5225I~
//*clear all line cid                                           //~5225I~
//*parm1:pcw                                                    //~5225I~
//*parm2:pfh                                                    //~5225I~
//*parm3:option 0:cid clear,1:cid shift                               //~v06rI~
//*return:cleared lineno                                        //~5225I~
//************************************************************  //~5225I~
//long filecidclear(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt);             //~v06rR~//+vbBwR~
long filecidclear(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt,PULINEH *Ppplh);//+vbBwI~
#define CIDOPTCLEAR     0                                             //~v06rR~
#define CIDOPTSHIFT     1                                             //~v06rR~
