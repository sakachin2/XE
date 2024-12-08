//CID://+va8kR~:                                                   //~va8kR~
//****************************************************************//~5308I~
//*xefcmd3.h                                                    //~5308I~
//****************************************************************//~5308I~
//va8k:101013 SPLit cmd;dbcs consideration for split ALL/OVER without SBCS option.(split to fcmd43)//~va8kI~
//v511:030302 new rotate cmd                                       //~v511I~
//v45x:011219 integrate "num cutoff" cmd to "split" cmd            //~v45xI~
//v40K:010714 option to insert comment line for drop excluded cmd(dro x|nx rep)//~v40KI~
//v165:000414 (BUG)label err msg not displayed(sort cmd)           //~v165I~
//**************************************************************** //~v165I~
int fcmdgetlabelrange(PUFILEH Ppfh,int Plabctr,                    //~v165M~
			UCHAR Plabelt[][ULHLINENOSZ+1],PULINEH *Pplht,int Popt);//~v165I~
//**************************************************************** //~v40KI~
int fcmdisrtline(PUCLIENTWE Ppcw,PULINEH Pplh,char *Pdata,int Plen);//~v40KM~
                                                                   //~v45xI~
//**************************************************************** //~v511I~
int fcmdisrtlinedbcs(PUCLIENTWE Ppcw,PULINEH Pplh,char *Pdata,char *Pdbcs,int Plen);//~v511I~
                                                                   //~v511I~
//**************************************************************** //~va8kI~
int fcmdisrtlinedbcsebcsosi(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,char *Pdata,char *Pdbcs,int Plen);//~va8kI~
#define  FCILDEO_INSERT_SO          0x01                           //+va8kI~
#define  FCILDEO_APPEND_SI          0x02                           //+va8kI~
//**************************************************************** //~v45xI~
int fcmdinvalidbinfile(void);                                      //~v45xM~
