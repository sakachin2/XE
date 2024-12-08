//*CID://+v559R~:                             update#=   18;       //+v559R~
//******************************************************           //~v327I~
//v559:020427 (UNX)disket support(mcopy) for copy file             //+v559I~
//v557:020427 (UNX)disket support(mren) for rename file            //~v557I~
//v556:020427 (UNX)disket support(mdel) for delete file            //~v556I~
//v538:020322 (LNX)mdos disk support;mkdir rmdir;attrib            //~v538I~
//******************************************************           //~v327I~
int umkdir_mdos(char *Ppfile);                                     //~v538R~
                                                                   //~v50GI~
//******************************************************           //~v538I~
int urmdir_mdos(char *Ppfile);                                     //~v538I~
                                                                   //~v538I~
//******************************************************           //~v538I~
int uattrib_mdos(char *Ppfile,ULONG Pattron,ULONG Pattroff);       //~v538R~
                                                                   //~v556R~
//******************************************************           //~v556R~
int uremove_mdos(char *Ppfile);                                    //~v556R~
                                                                   //~v557I~
//******************************************************           //~v557I~
int urename_mdos(char *Poldname,char *Pnewname);                   //~v557I~
                                                                   //+v559I~
//******************************************************           //+v559I~
int ucopy_mdos(char *Psource,char *Ptarget,int Popt);              //+v559I~
