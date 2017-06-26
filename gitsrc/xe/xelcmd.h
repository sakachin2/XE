//*CID://+vb87R~:                             update#=   29;       //+vb87R~
//****************************************************************
//xelcmd.h
//****************************************************************//~v06hI~
//vb87:170216 inactivate lcmd on excluded line                     //+vb87I~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va07:090628 add copy cid option to Copy lcmd(AI/BI)              //~va07I~
//v75b:070419 lcmd TS support                                      //~v75bI~
//v75a:070419 lcmd TFn/":"/";" support                             //~v75aR~
//v74M:070328 lcmd lower support                                   //~v74MI~
//v724:061118 (BUG)ABEND by join lcmd;access of deleted line cause ABEND//~v724R~
//v69W:060720 one more RESet level;to clear label lcmd use "RES L" or 3 times continuous Esc key press.//~v69WI~
//v69L:060713 cap(CAPS LOCK On) support;add "U" lcmd(uppercase translation)//~v69LI~
//v62J:050413 new lcmd(!):execute cmd on the line                  //~v62JI~
//v58s:040923 niche option for copy edit cmd(n:override target line by not space char of src line)//~v58sI~
//v0k3:981011 "=" lcmd(compare line)                               //~v0k3I~
//v0i0:980508 lcmd skip/bandle support over v099                   //~v0i0I~
//v0i0:980429 lcmd skip/bandle support                             //~v0i0I~
//v0hx:980410 label lcmd support for find etc.                     //~v0hxI~
//            alternative of v0hk and  v0hw is not needed anymore. //~v0hxI~
//v0ho:980221 range support for on/pase pos cmd                    //~v0hoI~
//v0hm:980215 pend/err lcmd reset by double Esc or typed RESET     //~v0hmI~
//v0hk:980214 support line range by A/B for find/change all cmd    //~v0hkI~
//            (fcmd2 split to fcmd2a as include file)              //~v0hkI~
//v0bg:970727 mergin err notify to cap to protect err msg override //~v0bgI~
//v0as:970719 general comment command(+)                           //~v0asI~
//v06l:960317:rearange key for no num option                    //~v06lI~
//           -include/exclude/include last/include first        //~v06lI~
//v06h:960310:support Copy/Move file by ALt+a                   //~v06hI~
//****************************************************************//~v06hI~
typedef struct _ULCMD {
						UCHAR   ULCcmd;			//cmd code
#define ULCCMDCOPY 		'C'     //copy cmd                      //~v06hI~
#define ULCCMDMOVE 		'M'     //move cmd                      //~v06hI~
#define ULCCMDAFTER		'A'     //after cmd                     //~v06hI~
#define ULCCMDBEFORE	'B'     //before cmd                       //~v0hkI~
#define ULCCMDEXCLUDE   'X'     //exclude                       //~v06lI~
#define ULCCMDINCLUDE   'Y'     //include                       //~v06lI~
#define ULCCMDINCF      'F'     //include first                 //~v06lI~
#define ULCCMDINCL      'L'     //include first                 //~v06lI~
#define ULCCMDCOMM      '+'     //comment out cmd                  //~v0asI~
#define ULCCMDREP       'R'     //repeat                           //~v0hoI~
#define ULCCMDLABEL     '.'     //label for line range             //~v0hxI~
#define ULCCMDNICHE     'N'     //override target line by source line not space char//~v58sI~
#define ULCCMDEXEC      '#'     //execute command                  //~v62JR~
#define ULCCMDUPPER     'U'     //uppercase translation            //~v69LI~
#define ULCCMDLOWER     '_'     //lowercase translation            //~v74MI~
#define ULCCMDDELETE    'D'     //uppercase translation            //~v69LI~
#define ULCCMDTFLOW     ':'     //tflow                            //~v75aR~
#define ULCCMDTFLOWKW   ';'     //tflow with keepword option       //~v75aR~
#define ULCCMDTFLOWSTR  0x01    //tflow internal id for "TF"       //~v75aR~
#define ULCCMDTFLOWSTRID "TF"   //tflow internal id for "TF"       //~v75aI~
#define ULCCMDTSSTR     0x02    //tflow internal id for "TS"       //~v75bI~
#define ULCCMDTSSTRID    "TS"   //cmd for "TS"                     //~v75bI~
#define ULCCMDCIDOPT     'C'    //cid copy option                  //~va07R~
#define ULCCMDBIN   	'B'     //no translation option(binary mode)//~va7xI~
						UCHAR   ULCtype;         //cmd type
#define ULCTNOPAIR 		0x00					//not pair cmd
#define ULCTNEEDPOS		0x01					//need postion cmd
#define ULCTPOSCMD 		0x02					//postion cmd
#define ULCTLABEL  		0x03					//label            //~v0hxI~
#define ULCTSAMEPAIR	0x04					//pair with same cmd//~v0k3I~
						UCHAR   ULCflag;         //cmd flag 
#define ULCFRANGE   	0x01					//can be range cmd
#define ULCFRANGEREQ	0x02					//range specified
#define ULCFRGNOREP 	0x04					//no repeat when region
#define ULCFBROWSE  	0x08					//allow also for browse
#define ULCFERR      	0x80					//err detected
#define ULCFCOMP     	0x40					//command completed
#define ULCFPEND     	0x20					//pair command pending
#define ULCFRPEND    	0x10					//range pending
						UCHAR   ULCflag2;                       //~5219R~
#define ULCF2CAPREP  	0x01					//block replace //~5219I~
#define ULCF2CAPINS  	0x02					//block insert  //~5219I~
#define ULCF2NOREP   	0x04					//count not allowed//~5226I~
#define ULCF2STRREP  	0x08					//rep is string    //~v0asI~
#define ULCF2MERGINERR  0x10					//mergin err detected//~v0bgI~
#define ULCF2NOSKIP     0x20					//skip count not avail//~v0i0I~
#define ULCF2NOBAND     0x40					//band count not avail//~v0i0I~
#define ULCF2NOCNTSB    0x80					//skip/band is avail only when range specified//~v0i0I~
						UCHAR   ULCflag3;                          //~v75aI~
#define ULCF3CNT0       0x80					//keep count 0 as no parm(repeat/bandle/skip)//~v75aI~
#define ULCF3CID        0x40					//copy cid option for Copy lcmd//~va07I~
#define ULCF3BIN        0x20					//no translation ooption(binary mode)//~va7xI~
#define ULCF3PEND_EXC   0x10					//pending by excluded line//+vb87I~
						UCHAR   ULCrsv[3];                         //~v75aI~
						int     ULCindex; 		//UFCcmd index
						int     ULCrepeat;		//repeat count	
    					int     ULCskip;        //skip count       //~v0i0R~
    					int     ULCband;        //band count       //~v0i0R~
						int     ULCsplitid; 	//pcw splitid   //~5114I~
						PULINEH ULCplh;			//ULINEH addr
				struct	_ULCMD *ULCplcrange;	//ULINEH for range
					  	} ULCMD,*PULCMD;                           //~v0hkR~
#define ULCMDSZ sizeof(ULCMD)
//****************************************************************
int filelinecmd(PUCLIENTWE Ppcw);
                                                                //~5223I~
//*******************************************************       //~5223I~
ULCMD *lcmdgetdummyplc(PUCLIENTWE Ppcw,UCHAR Plcmd);            //~5223R~
//*******************************************************          //~v0hkI~
//int lcmdgetabplh(PUFILEH Ppfh,int Ppendindex,PULINEH *Ppplh);    //~v0hxR~
int lcmdgetabplh(PUFILEH Ppfh,int Pentno,                          //~v0hxI~
				UCHAR Plabtbl[][ULHLINENOSZ+1],PULINEH Pplht[],int Psortseq[]);//~v0hxI~
//*******************************************************          //~v0hmI~
//int lcmdreset(PUCLIENTWE Ppcw,PUFILEH Ppfh);                     //~v69WR~
int lcmdreset(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Popt);              //~v69WI~
#define LCMDRESETLABEL 0x01                                        //~v69WI~
                                                                   //~v0hxI~
//*******************************************************          //~v0hxI~
int lcmdlinenocomp(const void*,const void*);//sort func            //~v0hxI~
//*******************************************************          //~v724R~
int lcmdclearlcmdplc(PULINEH Pplh);                                //~v724R~
