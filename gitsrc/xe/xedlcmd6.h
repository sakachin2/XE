//*CID://+vc60R~:                             update#=   38;       //~vamyR~//+vc60R~
//****************************************************************//~v043I~
//vc60 2023/08/03 mediaview as openWith                            //+vc60I~
//vamy:131103 add dlcmd "$"(async version of "%")                  //~vamyI~
//v76p:070628 compare remote file support                          //~v76pI~
//v76h:070621 do xdc for compare dir and dir                       //~v76hI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v75M:070509 "="(compare) lcmd support. 1st file is line with cmd option on Enter'ed screen.//~v75JI~
//v75J:070509 "g"(grep) dlcmd support                              //~v75JI~
//v662:050863 &(spawn) linecmd support(async version of #)         //~v662I~
//v64v:050708 (LNX)openwith support                                //~v64vI~
//v59e:041107 add "#" lcmd:submit for localfile/rsh for remotefile //~v59eI~
//v56e:040404 xp open dir by explorler,so allow dir for openwith   //~v56eI~
//v55V:040321 (WIN)filename list ! lcmd(openwith) support          //~v55VI~
//v55v:040229 (W32)v55u for W32 console xe(dlcmd "!":openwith)     //~v55vI~
//v51W:030810 dir lcmd %:apply cmd with filename parm as %.        //~v51WI~
//****************************************************************//~5715I~
//*xedlcmd6.h                                                      //~v51WR~
//****************************************************************//~5715I~
#define DLCMD_APPCMD      '%'                                      //~v51WI~
#define DLCMD_SUBRSH      '#'                                      //~v59eI~
#define DLCMD_SPAWN       '&'                                      //~v662I~
#define DLCMD_APPASYNC    '$'                                      //~vamyI~
#define COMPARETOOL "xfc"                                          //~v76gI~
#define COMPARETOOLDIR "xdc"                                       //~v76hI~
#define GREPTOOL       "grep"                                      //~v76gI~
//**************************************************************** //~v51WI~
		DLCMDFUNC dlcmdappcmd;                                     //~v51WR~
		DLCMDFUNC dlcmdsubrshcmd;                                  //~v59eI~
		DLCMDFUNC dlcmdspawn;                                      //~v662I~
		DLCMDFUNC dlcmdgrep;                                       //~v75JI~
		DLCMDFUNC dlcmdcompare;                                    //~v75JI~
		DLCMDFUNC dlcmdsend;                                       //~v76gI~
		DLCMDFUNC dlcmdappasync;                                   //~vamyI~
//#ifdef W32                                                       //~v64vR~
#if defined(W32) || defined(LNX)                                   //~v64vI~
	DLCMDFUNC dlcmdopenwith;                                       //~v55vR~
  #ifdef ARM                                                       //+vc60I~
	int dlcmdopenwithsub(PUCLIENTWE Ppcw,char *Pfnm,FILESZT Psize);//+vc60I~
  #else                                                            //+vc60I~
	int dlcmdopenwithsub(PUCLIENTWE Ppcw,char *Pfnm);              //~v55VI~
  #endif                                                           //+vc60I~
#endif                                                             //~v55vI~
//****************************************************************//~v05GI~
int dlcmdaclist(PUCLIENTWE Ppcw,PUDLCMD Pplc,int Precno);          //~v51WI~
//#ifdef WXE                                                       //~v64vR~
#if defined(WXE) || defined(LNX)                                   //~v64vR~
//**************************************************************** //~v56eI~
int dlcmdassocchk_fnamelist(PUCLIENTWE Ppcw);                      //~v56eI~
//**************************************************************** //~v56eI~
int  dlcmdassocchk_dirlist(PUCLIENTWE Ppcw);                       //~v56eI~
#endif                                                             //~v56eI~
int dlcmdsenddnd(int Popt,PUCLIENTWE Ppcw);                        //~v76gI~
#ifdef FTPSUPP                                                     //~v76pI~
	int dlccompchkfiletype(char *Pfnm1,char *Pfnm2,PUFTPHOST *Pppuftph1,PUFTPHOST *Pppuftph2,int *Ppdirsw1,int *Ppdirsw2);//~v76pI~
#endif                                                             //~v76pI~
