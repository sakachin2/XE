//*CID://+v78dR~:                             update#=   43;       //~v78dR~
//**************************************************************** //~v13pI~
//*xefcmd27.h                                                      //~v78dR~
//**************************************************************** //~v13pI~
//v78d:080308 screen grep support                                  //~v78dI~
//**************************************************************** //~v13pI~
#define FCMD_REGEX_SYNTAX	(0						\
/* RE_BACKSLASH_ESCAPE_IN_LISTS :off: backslash is backslash in [ ] */\
/* RE_BK_PLUS_QM                :off: not \+ or \*  but + or *     */\
  |RE_CHAR_CLASSES           /* :on : use character class          */\
/* RE_CONTEXT_INDEP_ANCHORS	    :off: ^, $ has meaning if at proper position*/\
/* RE_CONTEXT_INDEP_OPS         :off: +, * has meaning if at proper position*/\
/* RE_CONTEXT_INVALID_OPS       :off: +, * is normal char if at not proper position*/\
  |RE_DOT_NEWLINE            /* :on : . match to newline         */\
/* RE_DOT_NOT_NULL              :off: . match to null            */\
  |RE_HAT_LISTS_NOT_NEWLINE  /* :on : [^...] unmatch with newline */\
  |RE_INTERVALS              /* :on : use interval { and }        */\
/* RE_LIMITED_OPS               :off: use + * |                   */\
/* RE_NEWLINE_ALT               :off: newline is normal char      */\
  |RE_NO_BK_BRACES			 /* :on : use { and } not \{ and \}   */\
  |RE_NO_BK_PARENS			 /*	:on : use ( and ) not \( and \)   */\
  |RE_NO_BK_REFS  			 /*	:on : no use bkwd ref \n(digit)   */\
  |RE_NO_BK_VBAR             /* :on : use | not \|                */\
  |RE_NO_EMPTY_RANGES        /* :on : invalid when range list seq down*/\
  |RE_UNMATCHED_RIGHT_PAREN_ORD /*:on: unmatched ) is trated as normal char */\
                 )                                                 //~v78dI~
//**************************************************************** //~v78dI~
//**************************************************************** //~v78dM~
int fcmdgrepplh(int Popt,PUCLIENTWE Ppcw,PULINEH Pplh,UCHAR *Pdata,int Psrchrange,int Pcasesw,UCHAR **Pmatchstr,int *Pmatchlen);//~v78dR~
#define FCGPO_FWD         0x01     //fwd srch                      //~v78dM~
#define FCGPO_BWD         0x02     //backword srch                 //~v78dI~
//**************************************************************** //~v78dI~
int fcmdgrepcomp(int Popt,PUCLIENTWE Ppcw,UCHAR *Ppattern,int Pcasesw);//~v78dR~
#define FCGCO_AND         0x01     //2nd word of and               //~v78dI~
