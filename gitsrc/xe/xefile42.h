//*CID://+va50R~:                             update#=   14;       //~va20R~//+va50R~
//****************************************************************//~4C23I~
//xefile42.h                                                       //~v0bvR~
//****************************************************************//~4C23I~
//va50:100324 Raw EBCDIC file support for NFS mount                //+va50I~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//v74E:070315 BOUNDS cmd support(find,shift-lcmd,paste-lcmd)       //~v74EI~
//v73g:070112 (BUG)margin chk is not correct when rep char by TAB using vhex mode//~v71UI~
//v71U:061112 (BUG)accept insert in short(<mergin) record of margined file//~v71UI~
//v42g:010929 spf join ignoreing num fld                           //~v42gI~
//v421:010918 set default cidpos to 63 for spf file                //~v421I~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v0eLI~
//v0eN:970927 for DOS icc compile warning                          //~v0eNI~
//v0er:970921 (BUG)shitback err when isrt if tab is on oom         //~v0erI~
//v0c2:970728 simple principle.do not touch/move out of mergin     //~v0c2I~
//            if mergin not specified,last space is not dropped    //~v0c2I~
//v0bw:970728 hdrline parameter change MAXREC-->MERGIN             //~v0bwI~
//v0bv:970728 split file4-->file42                                 //~v0bvI~
//v0be:970725 filemerginchk return lrecl witoutcid(change over v0b7)//~v0beI~
//v0b7:970725 filemerginchk return avail space(last data to mergin)//~v0b7I~
//v0av:970720-fixed lrecl support                                  //~v0avI~
//           -filetoplinecid/filegetcid return rc                  //~v0avI~
//           -charmaxovererr has maxlen parm                       //~v0avI~
//****************************************************************//~5611I~
//************************************************************     //~v0bvI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //+va50I~
int filetoplinelrecl(PUFILEH Ppfh,PULINEH Pplh,int Pdefaultcidpossw,int *Ppupctrposlen);//+va50I~
#else                                                              //+va50I~
int filetoplinelrecl(PUFILEH Ppfh,PULINEH Pplh,int Pdefaultcidpossw);//~v421R~
#endif                                                             //+va50I~
                                                                   //~v0bvI~
//************************************************************     //~v0eLR~
//int  filesrchlastcid(char *Pdata,int Plen,char *Pcid,int Pcidlen);//~v0c2R~
                                                                   //~v0c2I~
//************************************************************     //~v0avI~
//************************************************************     //~v0avI~
#ifdef UTF8UCS2                                                    //~va20R~
int filemerginchk(PULINEH Pplh,int Pcpos,char *Padddata,char *Padddbcs/*dd fmt dbcs*/,//~va20R~
#else                                                              //~va20I~
int filemerginchk(PULINEH Pplh,int Pcpos,char *Padddata,           //~v0c2I~
#endif                                                             //~va20I~
					int Paddlen,int Pdellen,int Popt,              //~v0c2I~
					int *Ppaddlen,int *Pnewlen,int *Poomlen);      //~v0c2I~
//#define MERGIN_WITHOUTCID  0x01        //chk len of cid dropped  //~v0c2R~
#define MERGIN_REPMODE     0x02        //allow change in mergin even if long//~v0beI~
#define MERGIN_NOMSG       0x04        //bypass overflow msg       //~v0avR~
#define MERGIN_NOTAB       0x08        //ignore tab effect         //~v0avI~
#define MERGIN_OOMOK       0x10        //allow out of mergin input //~v0c2I~
#define MERGIN_JOINSPF     0x20        //join ignored num fld      //~v42gI~
#define MERGIN_SHORTRECOK  0x40        //accept short rec overflow if overflow is space only//~v71UI~
#define MERGIN_BNDS        0x80        //chk with bnds right boundary//~v74EI~
#define MERGIN_HEX         0x0800      //hex byte input may change column width//~v73gR~
                                                                   //~v0avI~
//************************************************************     //~v0c2I~
int filegetoomlen(PUFILEH Ppfh,PULINEH Pplh);                      //~v0eNR~
//**************************************************************** //~v0b7I~
int filecidmoffs(PUFILEH Ppfh,PULINEH Pplh,int *Ppoffs);           //~v0b7I~
//**************************************************************** //~v0c2I~
//int fileoomshiftback(PUFILEH Ppfh,PULINEH Pplh,int Poomlen);     //~v74ER~
int fileoomshiftback(PUFILEH Ppfh,PULINEH Pplh,int Poomlen,int Pmergin);//~v74EI~
//**************************************************************** //~v0eLI~
int filedefaultspf(PUFILEH Ppfh);                                  //~v0eLI~
