//*CID://+vbyiR~:             update#=      2                      //+vbyiR~
//**************************************************************** //~v636I~
//vbyi:230515 (ARM)for also xfc dcmd, support for external storage(no more need of vbyh)//+vbyiI~
//vbyh:230514 (ARM)dlcmd "=" support for external storage          //~vbyhI~
//v77z:080125 (BUG)submit faile by v76q(::#bat missing bat extention)//~v77zI~
//v75M:070509 "="(compare) lcmd support. 1st file is line with cmd option on Enter'ed screen.//~v75MI~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v64r:050630 (XXE)xxe support;child shell                         //~v64rI~
//v63c:050429 change dcmd stdout file(::so) to use pid for contension inter user//~v63cI~
//v63b:050429 change dlcmd "%" temp file(cfso/cf) to use pid for contension inter user//~v63bI~
//v639:050428 change dlcmd xprint temp file(XE_XPIN_) to use pid for contension inter user//~v639I~
//v638:050428 change xprint temp file to use pid for contension inter user//~v638I~
//v637:050428 change submit temp file to use pid for contension inter user//~v637I~
//v636:050428 new workdir filename naming ::#((pid).xxx) for grep work filename//~v636I~
//**************************************************************** //~v636I~
//xedcmd4.h                                                        //~v636I~
//**************************************************************** //~v636I~
#ifdef  XEGBL_DCMD4                                                //~v636I~
	int Gdcmdtempf;                                                //~v636R~
#else                                                              //~v636I~
	extern int Gdcmdtempf;                                         //~v636R~
#endif                                                             //~v636I~
#define GDCMDTEMPF_GREPI 0x01                                      //~v636I~
#define GDCMDTEMPF_GREPO 0x02                                      //~v636I~
#define GDCMDTEMPF_SUB   0x04                                      //~v637I~
#define GDCMDTEMPF_XPRINT 0x08                                     //~v638I~
#define GDCMDTEMPF_DLCMDP 0x10                                     //~v639I~
#define GDCMDTEMPF_DLCMDCF 0x20                                    //~v63bR~
#define GDCMDTEMPF_DCMDSO  0x40                                    //~v63cI~
#define GDCMDTEMPF_SYSCMDF 0x80                                    //~v64rI~
#define GDCMDTEMPF_GREPODLC 0x1000                                 //~v75JI~
#define GDCMDTEMPF_COMPODLC 0x2000                                 //~v75MI~
                                                                   //~vbyhI~
//#ifdef ARMXXE                                                      //~vbyhI~//+vbyiR~
//#define GDCMDTEMPF_COPY2TEMP 0x4000        //process on temp file copyed from arm shared storage file//~vbyhI~//+vbyiR~
//#endif                                                             //~vbyhI~//+vbyiR~
//**************************************************************** //~v636I~
#ifndef UNX                                                        //~v637I~
#ifdef OS2                                                         //~v637I~
//  #define DCMDSUBMITCMDFNM  "::#cmd"                             //~v77zR~
    #define DCMDSUBMITCMDFNM  "::#.cmd"                            //~v77zI~
#else                                                              //~v637I~
//  #define DCMDSUBMITCMDFNM  "::#bat"                             //~v77zR~
    #define DCMDSUBMITCMDFNM  "::#.bat"                            //~v77zI~
#endif                                                             //~v637I~
#else                                                              //~v637I~
	#define DCMDSUBMITCMDFNM  "::#submit"                          //~v637I~
#endif //!UNX                                                      //~v637I~
#define DCMDGREPTEMPFNMI  "::#grep"                                //~v637R~
#define DCMDGREPTEMPFNMO  "::#go"                                  //~v637R~
#define DCMDXPRINTTEMPFNM "::#xp"                                  //~v638I~
#define DCMDDLCMDPINPFNM  "::#dxp"                                 //~v639R~
#define DCMDDLCMDCFSO     "::#cfso"                                //~v63bR~
#define DCMDDCMDSO        "::#so"                                  //~v63cI~
#define DCMDSYSCMDTEMPF   "::#system"                              //~v64rI~
#define DCMDGREPTEMPFNMODLC "::#god"                               //~v75JR~
#define DCMDCOMPTEMPFNMODLC "::#cod"                               //~v75MI~
//**************************************************************** //~v636I~
int dcmdwdclear(void);                                             //~v636R~
//**************************************************************** //~v75JI~
int dcmd_grepdlcmd(PUCLIENTWE Ppcw,char *Pcmd,int Pcmdlen,char *Predirectfnm,int Pgrepctr);//~v75JR~
//**************************************************************** //~v75MI~
int dcmd_comparedlcmd(PUCLIENTWE Ppcw,char *Pcmd,int Pcmdlen,char *Predirectfnm,int Pgrepctr);//~v75MI~
