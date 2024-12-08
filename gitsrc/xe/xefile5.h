//*CID://+vbmjR~:                             update#=  104;       //~vazsR~//+vbmjR~
//**************************************************************** //~v08qI~
//xefile5.h                                                        //~v08qI~
//**************************************************************** //~v08qI~
//vbmj:180812 request "Force" option to save updated at other session.//+vbmjI~
//vazs:150114 (BUG)partial edit;if outfile!=0(save to another file) original file endposition is not changed.=>outfile length did not expand at 2nd save//~vazsI~
//vajb:130804 vhdr len for utf8 code len                           //~vajbI~
//vaj0:130710 localfile:recfm=V support (E /mV F{MFH|RDW})         //~vaj0I~
//va7K:100904 add RESET option to cv cmd B2B(change UFHhandle) and CPEB option to RESet cmd.//~va7KI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va7t:100823 EBC:handle support to file output(save/rep/..)       //~va7tI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va6Q:100722 Fxx+/MxR is output lrecl for end/save/rep.. input lrecl for copy cmd//~va6QI~
//va6D:000719 EBC eol 0x15 support                                 //~va6DI~
//va6c:100619 add SOSI option -S{i|r|d} to REP/CRE/APP/SAV/COP/MOV cmd//~va6cI~
//va68:100618 expand when LRECL is changed for record mode         //~va68I~
//va66:100618 add "R"(record mode write) to REP/CRE/SAV cmd        //~va66I~
//va65:100617 write lrecl to profile by REP cmd if the file is record mode//~va65I~
//va51:100415 Record mode file option                              //~va51I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va0C:090721_set wxp work CPxx to the same as source file         //~va0CI~
//va00:090510 merge utf8 version(enclosed by UTF8SUPPH)            //~va00I~
//          files encoded by utf8                                  //~va00I~
//            Edit/Browse/end/create/rep/app/save cmd support CPU8/CPLC//~va00I~
//            No Width[C]                                          //~va00I~
//          save option "IE"(ignore translation err)               //~va00I~
//          save CPxx to profile                                   //~va00I~
//          chk same CPxx status for dup open                      //~va00I~
//v92n:080802 (UTF)add  [cplc|cpu8] option for save cmd            //~v92nI~//~va00I~
//v90u:071116 (UTF8) ignore utf8 mode for so(=6) file              //~v90uI~//~va00I~
//v76X:071107 save option [NB|BK]                                  //~v76XI~
//v75H:070508 e8("e /f80 p1") command support. lcmd "8" on fname-list and dir-list.//~v75HI~
//v54Y:040201 "cre/rep/sav/app" support xall nxall .a .b           //~v54YI~
//v50G:030201 add cmd "et"/"bt"/"st" for e/b/s /mt                 //~v47XI~
//v47X:020413 mac file support(eol=0x0d) /Mm                       //~v47XI~
//v47T:020406 eol-id change option for cre/rep/app/sav/end cmd     //~v47TI~
//v440:011125 browse hex                                           //~v440I~
//v42y:011010 add cmd ek,bk,sk,ekn,bkn,skn                         //~v42yI~
//v414:010728 EC/ENC/BC/BNC/SC/SNC cmd add for cobol               //~v414I~
//v40u:010617 wild-card support for path name if dir contain only one member.//~v40uI~
//            (replace v143)                                       //~v40uI~
//v11i:990718 edit cmd help                                        //~v11iI~
//v10L:990424 EN/BN/SN edit/browse command for SPF file specific.(No cid,margin=72,P=1)//~v10LI~
//v10G:990417 EB/BB/SB for "e /mx","b /mx","s /mb"                 //~v10GI~
//v10D:990417 limit screen width function to browse only when implicit//~v10DI~
//v107:981213 use new opt of ufgetsinit for binary chk(del filechkbin)//~v107I~
//v0hK:980418 binary file chk.(reject tab clear)                   //~v0hKI~
//**************************************************************** //~v08qI~
int filetempname(PUFILEH Ppfh);                                    //~v08qI~
//**************************************************************** //~v47TI~
//int filesaveoptionchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pretopt,UCHAR **Ppfnm);//~v54YR~
int filesaveoptionchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,int *Pretopt,UCHAR **Ppfnm,//~v54YI~
//  			PULINEH *Ppplh1,PULINEH *Ppplh2);                  //~v54YI~//~va66R~
    			PULINEH *Ppplh1,PULINEH *Ppplh2,int *Pretlrecl);   //~va66I~
#define FSOC_EOL_PC       0x01	//outpt option;EOL type specified PC(0d0a)//~v47TI~
#define FSOC_EOL_UNIX     0x02	//outpt option;EOL type specified UNIX(0a)//~v47TI~
#define FSOC_EOL_MAC      0x04	//outpt option;EOL type specified MAC(0d)//~v47XI~
#define FSOC_EOL_RECORD   0x08	//no EOL write                     //~va66I~
//#define FSOC_EOL_NOTEBC   (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_RECORD)//~va6DI~//~vaj0R~
#define FSOC_EOL_NOTEBC   (FSOC_EOL_PC|FSOC_EOL_UNIX|FSOC_EOL_MAC|FSOC_EOL_RECORD|FSOC_EOL_RECORDV)//~vaj0R~
#define FSOC_XALL         0x10	//XALL option used                 //~v54YI~
#define FSOC_NXALL        0x20	//NXALL option used                //~v54YI~
#define FSOC_NB           0x40	//No backup                        //~v76XI~
#define FSOC_BK           0x80	//backup and del at save           //~v76XI~
#ifdef UTF8SUPPH                                                    //~v92nI~//~v76XI~
	#define FSOC_CPLC       0x0100	//conv utf8->local             //~v92nI~//~v76XI~
	#define FSOC_CPU8       0x0200	//conv utf8<-local             //~v92nI~//~v76XI~
	#define FSOC_ERRREP     0x0400	//replace cv err and continue to save//~va00I~
	#define FSOC_RESTORE    0x0800	//restore bkup when cverr      //~va00I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define FSOC_CPEB       0x1000	//CPEB option                  //~va50I~
	#define FSOC_ERRREPEBC  0x2000	//force errrep for tgt ebc file//~va50R~
	#define FSOC_EOL1       0x4000	//1 byte EOL added             //~va50I~
	#define FSOC_EOL2       0x8000	//2 byte EOL added             //~va50I~
	#define FSOC_ADJLRECL 0x010000	//adjust LRECL,parm to filecvwrite//~va68I~
	#define FSOC_SOSI_REP 0x020000	                               //~va68R~
	#define FSOC_SOSI_DEL 0x040000	                               //~va68R~
	#define FSOC_SOSI_INS 0x080000	                               //~va68R~
	#define FSOC_EOL_EBC  0x100000	//outpt option;EOL type specified EBCDIC//~va6DI~
	#define FSOC_EOL_OPT  (FSOC_EOL_EBC|FSOC_EOL_NOTEBC)           //~va6DI~
	#define FSOC_RETLRECL 0x200000   //Fxx parm was gotten         //~va6QI~
                                                                   //~va7tI~
	#define FSOC_EBCHANDLEP  0x00400000   //handle parameter       //~va7tI~
	#define FSOC_BIN         0x00800000   //no translation option  //~va7xI~
	#define FSOC_HANDLEMASK  0x07000000   //ebc converter handle(00->07)//~va79R~
	#define FSOC_HANDLEMASK_SHIFT  24      //handle shift count    //~va79I~
	#define FSOC_GETHANDLE(opt)  ((((opt) & FSOC_HANDLEMASK))>>FSOC_HANDLEMASK_SHIFT)//~va79I~
	#define FSOC_SETHANDLE(handle)  (((handle)<<FSOC_HANDLEMASK_SHIFT) & FSOC_HANDLEMASK)//~va79I~
                                                                   //~va7tI~
	#define FSOC_EOL_RECORDV 	0x10000000		//recfm=V(no EOL write)//~vaj0I~
	#define FSOC_EOL_NOTRECORDV (FSOC_EOL_OPT-FSOC_EOL_RECORDV)    //~vaj0R~
	#define FSOC_RETLRECLV  	0x20000000		//format parm of recfm=V//~vaj0R~
	#define FSOC_FILESAVE   	0x40000000		//filecvwrite from filesave//~vajbI~
	#define FSOC_FORCE      	0x80000000		//Force for SAVE and END cmd//+vbmjI~
                                                                   //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
#endif                                                             //~v92nI~//~v76XI~
//**************************************************************** //~v08qI~
//int fileoptionchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Popt,UCHAR Pbinsw);//~v75HR~
int fileoptionchk(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Popt,int Pbinsw);//~v75HI~
#define BESOPT_BIN    0x01                                         //~v10LR~
#define BESOPT_SPF    0x02                                         //~v10LR~
#define BESOPT_SPFCOB 0x04          //cobol and ignore col72       //~v414I~
#define BESOPT_SPFCOBNUM 0x08       //cobol with col72 number fld  //~v414I~
#define BESOPT_SPFCOB2    0x10       //cobol and ignore col72 and col1-6=space//~v42yI~
#define BESOPT_SPFCOB2NUM 0x20       //cobol with col72 number fld,col1-6=space//~v42yI~
#define BESOPT_HEX    0x40                                         //~v440I~
#define BESOPT_TEXT   0x80                                         //~v47XI~
#define BESOPT_F80    0x0100         //fixed 80                    //~v75HR~
#ifdef UTF8SUPPH                                                    //~v90uI~//~v76XI~
	#define BESOPT_LOCALE 0x0200         //locale mode(not force utf8)//~v90uR~//~v76XI~
	#define BESOPT_IE     0x0400     //ignore f2l err              //~va00I~
	#define BESOPT_CPLC   0x0800     //force CPLC                  //~va00I~
	#define BESOPT_CPU8   0x1000     //force CPU8                  //~va0CI~
#endif                                                             //~v90uI~//~v76XI~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
	#define BESOPT_CPEB   0x2000     //force CPEB                  //~va50R~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                                                                   //~v08qI~
#define OPTSTR_CODEPAGE  MODE_EBC                                  //~va79R~
//**************************************************************** //~v40uI~
//int fileoptionprechk(PUCLIENTWE Ppcw);                           //~v54YR~
//int fileoptionprechk(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Popt,UCHAR Pbinsw,int *Pretopt);//~v75HR~
int fileoptionprechk(PUCLIENTWE Ppcw,PUFILEH Ppfh,UCHAR Popt,int Pbinsw,int *Pretopt);//~va00R~
#define BECMDOPT_LISTDIR    0x01	//rc:dirlist brwose forsed     //~v40uR~
#define BECMDOPT_BIN        0x02	//binnary mode                 //~v440I~
#define BECMDOPT_HEX        0x04	//hex dump list                //~v440I~
                                                                   //~v40uI~
//**************************************************************** //~v08qI~
int filepartialcopy(int Popt,PUFILEH Ppfhsrc,PUFILEH Ppfhdest);    //~v08qI~
#define FPCO_2ND   0x01     //copy part of after read end offset   //~vazsI~
#define FPCO_SELF  0x02     //save to original file                //~vazsI~
//**************************************************************** //~v0hKI~
//int filechkbin(PUFILEH Ppfh);                                    //~v107R~
//**************************************************************** //~v11iI~
int fileedithelp(int Pcmdid);                                      //~v11iI~
                                                                   //~va00I~
#ifdef UTF8SUPPH                                                   //~va00I~
//**************************************************************** //~va00I~
    int fileupdateprofile(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);  //~va00I~//~va65R~
	#define FUPO_CHKONLY 0x01  //no profile record update,chk only //~va00I~
	#define FUPO_FCMD    0x02  //fcmd REP/CRE                      //~va65I~
	#define FUPO_RECORD  0x04  //record mode by rep cmd option     //~va66I~
	#define FUPO_EOL     0x08  //change to EOL write               //~va66I~
	#define FUPO_ECMD    0x10  //end cmd;  lrecl is on plh         //~va6QI~
	#define FUPO_RCMD    0x20  //reset cmd                         //~va7KI~
	#define FUPO_RECORDV 0x40  //recfm=V                           //~vaj0I~
//  int fileupdateprofilesave(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int Psaveopt,char *Pfnm);//~va00R~//~va66R~
    int fileupdateprofilesave(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,int Psaveopt,char *Pfnm,int Plreclparm);//~va66I~
	int fileupdateprofilesave_cut(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh);//~vaj0I~
//	int filesaveoptionchkcp(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pcpopt,int *Ppopt);//~va00R~//~va6QR~
	int filesaveoptionchkcp(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pcpopt,int *Ppopt,int *Ppint);//~va6QI~
    #define  FSOCCO_COPY    0x01  //cp option chk by COPy cmd      //~va00I~
    #define  FSOCCO_CMDFLAG 0x02  //cmd flag(width top "-","/")    //~va6cR~
    #define  FSOCCO_GETLRECL     0x04  //request to get Fxx parm   //~va6QI~
#endif                                                             //~va00I~
//**************************************************************** //~va51I~
//int fileupdateprofilelrecl(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnm); //~va51I~//~va65R~//~va66R~
int fileupdateprofilelrecl(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,char *Pfnm,int Plreclparm);//~va66I~
//**************************************************************** //~va7KI~
int fileoptionchkebcconverter(int Popt,char *Popd,int Poffs,int *Pphandle);//~va7KI~
//**************************************************************** //~vaj0I~
int xefile5getparmlreclV(int Popt,char *Pparm,int *Pplrecl);       //~vaj0I~
//**************************************************************** //~vaj0I~
