//*CID://+vaz0R~:                             update#=   22;       //+vaz0R~
//****************************************************************
//xefile.h
//**************************************************************** //~v0cmI~
//vaz0:150105 BUG:offset value is long long for fseek error msg    //+vaz0I~
//vag2:120811 REDo suupport                                        //~vag2I~
//va7L:100905 undo support for EBC SETCP cmd                       //~va7LI~
//v9@8:080717 3270:fs mode del excluded line                       //~v9@8I~
//v780:080212 syntaxhighlight support (SYN cmd,C+s func key)       //~v780I~
//v761:070529 split tail cmd:del continued line if all space       //~v761I~
//v74r:070220 (BUG)undo csr line positioning invalid at undo confirmation//~v74rI~
//            C&P region paste generate Ins & Del undosdata in the same undoctr.//~v74rI~
//            postion to inserted line by splitline is deleted by last join operation.//~v74rI~
//v71Z:061114 v71Y miss set version number in the following case   //~v71ZI~
//            for SPF err file opened by en,update then "renum force" because SPFNUMOK set by renum at undo.//~v71ZI~
//v617:050212 mergin set required for continue protection attr     //~v617I~
//v45u:011216 num cutoff cmd to split continued line               //~v45uI~
//v42r:011009 (BUG)num clear ignored at save                       //~v42rI~
//v42i:011002 set spfnum at save for suffix overflow line to avoid line update flag(*u search)//~v42iI~
//v420:010918 cob fld num clear option;num clear cob               //~v420I~
//v40F:010709 COB support:num clear(clear col72-80)                //~v40FI~
//v40p:010603 add x *= (exclude same as above line)                //~v40pI~
//v178:000430 renum support for lineno hex mode                    //~v178I~
//v0d8:970831 allow err line copy into spf file                    //~v0d8I~
//v0ct:970814 RENUM(NUM reset) Force option for spf file           //~v0ctI~
//v0co:970813 undo set ver even if pfh set only case               //~v0coI~
//v0cn:970813 RENUM undo support                                   //~v0cnI~
//v0cm:970812 NUM setver subcmd(reset spf version)                 //~v0cmI~
//****************************************************************
//*DATA TYPE *******************************
//****************************************************************
typedef struct _UUNDOH {
						UQUEE   UUHqelem;
                        UCHAR   UUHcbid[4];                     //~5105I~
#define UUHCBID         "UUH "                                  //~5105I~
#define URHCBID         "URH "                                     //~vag2I~
						UCHAR   UUHtype;		//update type
#define UUHTISRT        'I'						//data line insert
#define UUHTDEL         'D'						//data line delete
#define UUHTREP         'R'						//data line replace
#define UUHTXON         'N'						//exclude flag on
#define UUHTXOFF        'F'						//exclude flag off
#define UUHTXSUFFIX     'S'						//suffix change
#define UUHTXSUFFIX2    's'						//suffix change for spf//~v42iI~
#define UUHTSPFVER      'V'						//spf version no   //~v0cmI~
#define UUHTSPFVERMAX   'M'						//spf version max  //~v0coI~
#define UUHTSPFERR      '1'						//set spf err      //~v0d8I~
#define UUHTCIDCLEAR    'C'						//cid clear/shift  //~v0cmI~
#define UUHTCUTOFF      'T'						//split line cutoff//~v45uR~
#define UUHTXLINENO     'L'						//excluded lineno chng
#define UUHTRENUM       'E'						//renum            //~v0cnI~
#define UUHTREPRENUM    'U'		//rep by renum spf file,save SPFNUMERR//~v0ctI~
#define UUHTREPRENUMCLR 'c'		//num clear operation              //~v42rI~
#define UUHTWIDTH       'W'						//width changed for bin file mergin//~v617I~
#define UUHTEBCSETCP    'B'						//ebcdic codepage was changed//~va7LI~
						UCHAR   UUHflag;		//flag
#define UUHFDBCS        0x01					//dbcs saved
#define UUHFSETSPFVER   0x02					//ver/num changed  //~v0cnR~
#define UUHFSETSPFOK    0x04					//changed spf err-->ok//~v0ctI~
#define UUHFXSAME       0x08					//exclude hdr by same as above//~v40pI~
#define UUHFNUMCLEAR    0x10					//renum by num cmd(clear option if on)//~v40FI~
#define UUHFCOB         0x20					//cob file         //~v420I~
#define UUHFSETSPFVER2  0x40					//suffix updated for spf file//~v42iI~
#define UUHFREPRENUM    0x80					//recover ULHF4REPRENUM at undo//~v71ZI~
//  					UCHAR   UUHrsv[2];		//reserved         //~v0cmR~
//  					UCHAR   UUHrsv;         //rsv              //~v45uR~
    					UCHAR   UUHflag2;       //falgs            //~v45uI~
#define UUHF2SPLIT1     0x01					//continued        //~v45uI~
#define UUHF2SPLIT2     0x02					//continuing       //~v45uI~
#define UUHF2DELETED    0x04					//deleted later in the same update level//~v74rI~
#define UUHF2SYNVALID   0x08					//recover for CUTOFF//~v780I~
#define UUHF2REDO       0x10					//redo entry       //~vag2I~
    					UCHAR   UUHspfver;		//ULHspfver save   //~v0cmR~
						int     UUHupctr;		//new upctr of lh
						int     UUHundoctr;		//new undoctr
						int     UUHctrsave;		//suffix/linenow
						int     UUHctrsave2;	//suffix/linenow   //~v0cnI~
						LONG    UUHlongsave;	//suffix/linenow   //~v0cnR~
//						ULONG   UUHlongsave2;   //line offset save //+vaz0R~
  						FILESZT UUHlongsave2;   //line offset save //+vaz0I~
						PULINEH UUHplhsave; 	//old data save
						PULINEH UUHplh;			//back ptr to ULINEH
					  	} UUNDOH;
typedef UUNDOH *PUUNDOH;
#define UUNDOHSZ (sizeof(UUNDOH))
#define  UGETPFHFROMPUH(puh)   \
    ((PUFILEH)((ULPTR)(((PUUNDOH)(puh))->UUHqelem.UQqhdr)-offsetof(UFILEH,UFHundoque)))//~vag2I~

//****************************************************************
//int undoupdate(PUCLIENTWE Ppcw,PULINEH Pplh,UCHAR Ptype);        //~v761R~
int undoupdate(PUCLIENTWE Ppcw,PULINEH Pplh,int Ptype);            //~v761R~
#define UNDO_FORCE_PREP        0x0100      //for datasave even if upctr same//~v761I~
//****************************************************************
//int  undoprep(PUCLIENTWE Ppcw,PULINEH Pplh,UCHAR Ptype);         //~v761R~
int  undoprep(PUCLIENTWE Ppcw,PULINEH Pplh,int Ptype);             //~v761I~
//****************************************************************
void undofreeuuh(PUFILEH Ppfh);
//**************************************************************** //~v0coI~
void undocsrmove(PUCLIENTWE Ppcw,PULINEH Pplh);                    //~v0coI~
//**************************************************************** //~v9@8I~
int undoclearplcmdall(int Popt,PUFILEH Ppfh);                      //~v9@8I~
//**************************************************************** //~vag2I~
int undo_redo(PUCLIENTWE Ppcw);                                    //~vag2I~
