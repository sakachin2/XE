//*CID://+v6H3R~: updat#    110;                                   //~v6H3R~
//*************************************************************
//*ustring.c 
//*  ustrncpyz                                                     //~v111I~
//*  ustrnpbrk/ustrnstr/ustrnspn                                //~4C21I~
//*  ustrrspn /ustrrspni /ustrstr  /ustrrstri                      //~v5mpR~
//*  ustrnrspn/ustrnrspni/ustrnstri/ustrnrstri				    //~4C21R~
//*  ustrchr2/ustrnchr2/ustrrchr2/ustrnrchr2                       //~v017I~
//*  ustrnlen                                                      //~v094R~
//*  ustrnchr                                                      //~v6H3I~
//*  umemrspn,umemrspnc,umemspnc,umemspn_spacetab                   //~v097R~//~v6hDR~
//*  umemrchr/umemchr2/umemrchar2                                  //~v093R~
//*  umemmem/umemmemi/umemstr/umemstri                             //~v093M~
//*  umemrmem/umemrmemi/umemrstr/umemrstri                         //~v093I~
//*  umemrpbrk/umempbrk                                            //~v57sR~
//*  uispunct/uispunctdbcs                                         //~v5m6I~//~v62pR~
//*  umemtrim                                                      //~v5mpI~
//*************************************************************
//v6H3:170105 (BUG)crash when too long name;it should chk strlen   //~v6H3I~
//v6Bx:160212 (LNX)compiler warning at suse64                      //~v6BxI~
//v6Bk:160220 (LNX)compiler warning                                //~v6BkI~
//v6uE:140529 (W32)request explicit option UCVUCS_UCS4 for UCS4 for also Win//~v6uEI~
//v6n1:130905 memcpy implementation of suse12.3(err if region overlap)(also for Windows spec)//~v6n1I~
//v6hD:120906 add umemspn_spacetab                                 //~v6hDI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6hf:120616 (BUG)found by VC10:/W4 warning except                //~v6hfI~
//v6he:120616 for VC10:/W4 warning except C4115,C4214,C4100,C4706,C4244,C4210,C4127,C4245//~v6heI~
//v691:100730 LP64 wchar_t is 4byte on LP64                        //~v691I~
//v669:100517 add trim ascii option                                //~v669I~
//v668:100512 add umemtrim drop head option                        //~v668R~
//v65h:100321 add umemicmpdbcs                                     //~v65hI~
//v65c:100302 (LNX)UCS4 support                                    //~v65cI~
//v63d:091129 (BUG)ustrnspn, protect parm len<0                    //~v63dI~
//v62U:091030_GB18030 merge                                        //~v62UI~
//v62q:090921!add uispunctdbcs                                     //~v62pI~
//v628:090720 (BUG)ustrnrchr should call umemrchr2                 //~v628I~
//v620:090506 merge UTF8 version                                   //~v620I~
//            "/" after utf8 was detected as dbcs 2nd byte         //~v620I~
//v5mp:080402 add umemtrim                                         //~v5mpI~
//v5m8:080216 ustrdup for syntaxhl                                 //~v5m8I~
//v5m6:080204 add uispunct                                         //~v5m6I~
//v5h4:051015 (BUG)umempbrk miss if delm in strdelm is adjacent    //~v5fkI~
//v5fk:050226 (BUG)unumlen abend by overrun end of string          //~v5fkI~
//v57s:030125 add umempbrk                                         //~v57sI~
//v517:011219 umemrchr performance up(for the case char continued,everytime//~v516I~
//            memchr called)                                       //~v516I~
//v516:011219 add umemrpblk;search last pos of char ins parm string//~v516I~
//v327 000820:LINUX support                                        //~v327I~
//v292:991029 no upper case search required when 1st char is case insensitive//~v292I~
//v111:971103 ustrncpyz strncpy gualantied with last null and only one null//~v111I~
//v098:970723 split uparse fro ustring to uparse.c                 //~v098I~
//v097:970720 umemspnc,umemrspnc                                   //~v097I~
//v094:970706 umemrspn(umemspn is same meaning as ustrnspn)        //~v094I~
//            ustrnrspn must trate parm1 as string                 //~v094I~
//v093:970706 (BUG)set null out of range may corrupt naboring area(ustrnchar2,ustrnrchr2)//~v093R~
//            and conbine to umemchar2,umemrchr2)                  //~v093I~
//v092:970705 umemmem/umemmemi/umemstr/umemstri/umemrmem/umemrmemi/umemrstr/umemrstri//~v092I~
//v091:970705 add ustrnlen(max n)                                  //~v091I~
//v088:970621 add umemrchr                                         //~v088I~
//v081:970503 (BUG)uparse rc=1 for case quate enclosed             //~v081I~
//v080:970503 add uparsein to enclabe string by quate for dlcmd to dcmd//~v080I~
//            ustring.c                                            //~v080I~
//v069:970330:uparsev(output by argv format)                       //~v069I~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//            -warning if mixed &&,||                              //~v053I~
//v046:961123:uparse2 no malloc output area option(malloc at out of function)//~v046I~
//           :uparse:malloc only when long string                  //~v046I~
//           :uparse:delm lost when pre/post space exist.          //~6B23R~
//                   add option to set delm except for ","         //~6B23R~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//v017:960714:add ustrchr2(strchr protecting detect dbcs 2nd byte) //~v017I~
//            add ustrnchr2=(ustrchr2 with length)                 //~v017I~
//            add ustrrchr2(search last char protecting detect dbcs 2nd byte)//~v017I~
//            add ustrnrchr2=(ustrrchr2 with length)               //~v017I~
//960324:(BUG)delm after quate("abc",vvv) cannot drop quate.    //~6324I~
//960324:uparse2:with delm/qaute return function                //~6324R~
//950930:malloc/calloc rc chk for dos                           //~5930I~
//*950503 bug loop when all space(quate init value set)         //~5430R~
//*950430 uparse delm tbl support                               //~5430R~
//*950307 uparse "" null string support                         //~5430I~
//************************************************************* //~5307I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
#ifdef UNX                                                         //~v327R~
	#include <ugcclib.h>                                           //~v327I~
#else   //!UNX                                                     //~v327R~
#ifdef DOS
#else
    #ifdef W32                                                     //~v022I~
	#else                                                          //~v022I~
//  #define INCL_BASE                                              //~v022R~
//  #include <os2.h>                                               //~v022R~
	#endif                                                         //~v022I~
#endif
#endif  //!UNX                                                     //~v327R~
//*******************************************************
#include <ulib.h>
#include <ustring.h>
#include <ualloc.h>
#include <udbcschk.h>                                              //~v017I~
#ifdef UTF8SUPPH                                                   //~v620I~
	#include <ucvucs.h>                                            //~v620I~
	#include <utrace.h>                                            //~v620I~
#endif                                                             //~v620I~
//*******************************************************
//*******************************************************       //~4C19I~
//*ustring
//* dummy for LIB
//******************************************************
void ustring(void)
{
	return;
}//ustring

//*******************************************************          //~v6H3I~
//*ustrnchr                                                        //~v6H3I~
//******************************************************           //~v6H3I~
char *ustrnchr(char *Pbuff,int Pkey,size_t Plen)                   //+v6H3R~
{                                                                  //~v6H3I~
	char *pc,*pc0;                                                 //~v6H3I~
//******************                                               //~v6H3I~
    pc=memchr(Pbuff,Pkey,Plen);                                    //~v6H3R~
    if (!pc)                                                       //~v6H3I~
        return 0;                                                  //~v6H3I~
    pc0=memchr(Pbuff,0,Plen);                                      //~v6H3I~
    if (pc0 && pc0<pc)                                             //~v6H3I~
        return 0;                                                  //~v6H3I~
    return pc;                                                     //~v6H3I~
}//ustrnchr                                                        //~v6H3I~
//*******************************************************       //~4C20I~
//*ustrnpbrk                                                    //~4C21R~
//* search first char which is on parm2 string                  //~4C21R~
//* parm1 :string to be serached                                //~4C20I~
//* parm2 :string specify check char string                     //~4C21R~
//* parm3 :parm1 len                                            //~4C20I~
//* return:pointer to the first char,null in not found          //~4C21R~
//******************************************************        //~4C20I~
char *ustrnpbrk(const char *Pbuff,const char *Pkey,unsigned int Plen)//~4C21R~
{                                                               //~4C20I~
	char ch,*pc,*pco,*pcl;                                      //~4C21R~
//******************                                            //~4C20I~
//  Plen=ustrnlen((char*)(ULONG)Pbuff,Plen);                       //~v5fkR~//~v6hhR~
//  Plen=ustrnlen((char*)(ULPTR)Pbuff,Plen);                       //~v6hhI~//~v6BxR~
    Plen=(UINT)ustrnlen((char*)(ULPTR)Pbuff,Plen);                 //~v6BxI~
    if (!Plen)                                                  //~4C20I~
    	return 0;                                               //~4C20I~
//	if (strchr(Pkey,*(pc=(char*)(ULONG)Pbuff+Plen-1)))	//on parm2 //~v5fkR~//~v6hhR~
	if (strchr(Pkey,*(pc=(char*)(ULPTR)Pbuff+Plen-1)))	//on parm2 //~v6hhI~
		pcl=pc;	//last cadidate                                 //~4C21R~
	else                                                        //~4C20I~
		pcl=0;                                                  //~4C21R~
	ch=*pc;				//save last byte                        //~4C20I~
	*pc=0;				//create string for ustrrspn            //~4C20I~
	pco=strpbrk(Pbuff,Pkey);                                    //~4C21R~
	*pc=ch;				//restore last byte                     //~4C20I~
	if (!pco)           //not founf                             //~4C21R~
		pco=pcl;                                                //~4C21R~
	return pco;                                                 //~4C21R~
}//ustrnpbrk                                                       //~v093R~
                                                                //~4C21I~
//*******************************************************       //~4C21I~
//*ustrnspn                                                     //~4C21I~
//* search first char which is not on parm2 string              //~4C21I~
//* parm1 :string to be serached                                //~4C21I~
//* parm2 :string specify exception char string                 //~4C21I~
//* parm3 :parm1 len                                            //~4C21I~
//* return:offset to the last char,length if all match          //~4C21I~
//******************************************************        //~4C21I~
size_t ustrnspn(const char *Pbuff,const char *Pxstr,unsigned int Plen)//~4C21I~
{                                                               //~4C21I~
	char ch,*pc;                                                //~4C21I~
	size_t  offs,offsl;                                         //~4C21I~
//******************                                            //~4C21I~
    if (Plen<=0)                                                   //~v63dI~
        return 0;                                                  //~v63dI~
//  Plen=ustrnlen((char*)(ULONG)Pbuff,Plen);                       //~v5fkR~//~v6hhR~
//  Plen=ustrnlen((char*)(ULPTR)Pbuff,Plen);                       //~v6hhI~//~v6BxR~
    Plen=(UINT)ustrnlen((char*)(ULPTR)Pbuff,Plen);                 //~v6BxI~
    if (!Plen)                                                  //~4C21I~
    	return 0;                                               //~4C21I~
//	if (!strchr(Pxstr,*(pc=(char*)(ULONG)Pbuff+Plen-1)))	//not on parm2//~v5fkR~//~v6hhR~
	if (!strchr(Pxstr,*(pc=(char*)(ULPTR)Pbuff+Plen-1)))	//not on parm2//~v6hhI~
		offsl=Plen-1;	//last cadidate                         //~4C21I~
	else                                                        //~4C21I~
		offsl=Plen;                                             //~4C21I~
	ch=*pc;				//save last byte                        //~4C21I~
	*pc=0;				//create string for ustrrspn            //~4C21I~
	offs=strspn(Pbuff,Pxstr);                                   //~4C21I~
	*pc=ch;				//restore last byte                     //~4C21I~
	if (offs==Plen-1)                                           //~4C21I~
		offs=offsl;                                             //~4C21I~
	return offs;                                                //~4C21I~
}//ustrnspn                                                     //~4C21I~
                                                                //~4C20I~
//*******************************************************
//*ustrrspn
//* search last char which is not on parm2 string
//* parm1 :string to be serached
//* parm2 :string specify exception char string                 //~4C19R~
//* return:offset to the last char(-1 if not found)
//******************************************************
size_t ustrrspn(const char *Pbuff,const char *Pxstr)
{
	const char *pcb;
	size_t     lenb;
//******************
	lenb=strlen(Pbuff);
	pcb=Pbuff+lenb-1;		//last char
	while(lenb)
	{
		if (!strchr(Pxstr,*pcb))		//not found
			break;
		lenb--;
		pcb--;
	}
	return --lenb;
}//ustrrspn

//*******************************************************       //~4C20I~
//*ustrnrspn                                                    //~4C20I~
//* search last char which is not on parm2 string               //~4C20I~
//* parm1 :string to be serached                                //~4C20I~
//* parm2 :string specify exception char string                 //~4C20I~
//* parm3 :parm1 len                                            //~4C20I~
//* return:len of last span                                        //~v094R~
//******************************************************        //~4C20I~
size_t ustrnrspn(const char *Pbuff,const char *Pxstr,unsigned int Plen)//~4C20I~
{                                                               //~4C20I~
	const char *pcb;                                               //~v094R~
	size_t     lenb;                                            //~4C20I~
	size_t     span;                                               //~v094I~
//******************                                            //~4C20I~
//  lenb=Plen;                                                     //~v094R~
//  lenb=ustrnlen((char*)(ULONG)Pbuff,Plen);                       //~v5fkR~//~v6hhR~
    lenb=ustrnlen((char*)(ULPTR)Pbuff,Plen);                       //~v6hhI~
	pcb=Pbuff+lenb-1;		//last char                         //~4C20I~
    span=0;                                                        //~v094I~
	while(lenb)                                                 //~4C20I~
	{                                                           //~4C20I~
		if (!strchr(Pxstr,*pcb))		//not found             //~4C20I~
			break;                                              //~4C20I~
		lenb--;                                                 //~4C20I~
		pcb--;                                                  //~4C20I~
        span++;                                                    //~v094I~
	}                                                           //~4C20I~
//  return --lenb;                                                 //~v094R~
    return span;                                                   //~v094I~
}//ustrnrspn                                                    //~4C20I~
                                                                //~4C20I~
//*******************************************************          //~v094I~
//*umemrspn                                                        //~v094I~
//* search last char which is not on parm2 string                  //~v094I~
//* parm1 :string to be serached                                   //~v094I~
//* parm2 :string specify exception char string                    //~v094I~
//* parm3 :parm1 len                                               //~v094I~
//* return:len of last span                                        //~v094I~
//******************************************************           //~v094I~
size_t umemrspn(char *Pbuff,char *Pxstr,unsigned int Plen)         //~v094I~
{                                                                  //~v094I~
	char *pcb;                                                     //~v094I~
	size_t     lenb,lenk,span=0;                                   //~v094I~
//******************                                               //~v094I~
	lenk=strlen(Pxstr);                                            //~v094I~
    lenb=Plen;                                                     //~v094I~
	pcb=Pbuff+lenb-1;		//last char                            //~v094I~
	while(lenb)                                                    //~v094I~
	{                                                              //~v094I~
		if (!memchr(Pxstr,*pcb,lenk))		//not found            //~v094I~
			break;                                                 //~v094I~
		lenb--;                                                    //~v094I~
		pcb--;                                                     //~v094I~
        span++;                                                    //~v094I~
	}                                                              //~v094I~
	return span;                                                   //~v094I~
}//umemrspn                                                        //~v094I~
                                                                   //~v094I~
//*******************************************************          //~v097I~
//*umemspnc                                                        //~v097I~
//* get span of char                                               //~v097I~
//* parm1 :area to be serached                                     //~v097I~
//* parm2 :char                                                    //~v097I~
//* parm3 :parm1 len                                               //~v097I~
//* return:span                                                    //~v097I~
//******************************************************           //~v097I~
size_t umemspnc(char *Pbuff,char Pchr,unsigned int Plen)           //~v097I~
{                                                                  //~v097I~
	char *pc,*pce;                                                 //~v097I~
//******************                                               //~v097I~
	for (pc=Pbuff,pce=Pbuff+Plen;pc<pce;pc++)                      //~v097I~
		if (*pc!=Pchr)                                             //~v097I~
			break;                                                 //~v097I~
//	return (UINT)((ULONG)pc-(ULONG)Pbuff);                         //~v097I~//~v6hhR~
	return (UINT)((ULPTR)pc-(ULPTR)Pbuff);                         //~v6hhI~
}//umemspnc                                                        //~v097I~
//*******************************************************          //~v6hDI~
//*umemspn_spacetab                                                //~v6hDI~
//* get span of char                                               //~v6hDI~
//* parm1 :area to be serached                                     //~v6hDI~
//* parm2 :char                                                    //~v6hDI~
//* parm3 :parm1 len                                               //~v6hDI~
//* return:span                                                    //~v6hDI~
//******************************************************           //~v6hDI~
size_t umemspn_spacetab(char *Pbuff,unsigned int Plen)             //~v6hDI~
{                                                                  //~v6hDI~
	char *pc,*pce;                                                 //~v6hDI~
//******************                                               //~v6hDI~
	for (pc=Pbuff,pce=Pbuff+Plen;pc<pce;pc++)                      //~v6hDI~
		if (*pc!=' ' && *pc!='\t')                                 //~v6hDI~
			break;                                                 //~v6hDI~
	return (UINT)PTRDIFF(pc,Pbuff);                                //~v6hDI~
}//umemspn_spacetab                                                //~v6hDI~
                                                                   //~v097I~
//*******************************************************          //~v097I~
//*umemrspnc                                                       //~v097I~
//* get span of char of last part of area                          //~v097I~
//* parm1 :area to be serached                                     //~v097I~
//* parm2 :char                                                    //~v097I~
//* parm3 :parm1 len                                               //~v097I~
//* return:span                                                    //~v097I~
//******************************************************           //~v097I~
size_t umemrspnc(char *Pbuff,char Pchr,unsigned int Plen)          //~v097I~
{                                                                  //~v097I~
	char *pc,*pce;                                                 //~v097R~
//******************                                               //~v097I~
	for (pce=pc=Pbuff+Plen-1;pc>=Pbuff;pc--)                       //~v097R~
		if (*pc!=Pchr)                                             //~v097I~
			break;                                                 //~v097I~
//	return (UINT)((ULONG)pce-(ULONG)pc);                           //~v097R~//~v6hhR~
	return (UINT)((ULPTR)pce-(ULPTR)pc);                           //~v6hhI~
}//umemrspnc                                                       //~v097I~
                                                                   //~v097I~
//*******************************************************       //~4C20I~
//*ustrnstr                                                     //~4C20I~
//* search parm2 string on parm1 string                         //~4C20I~
//* parm1 :string to be serached                                //~4C20I~
//* parm2 :search key string                                    //~4C20I~
//* parm3 :parm1 len                                            //~4C20I~
//* return:pinter to string on parm1 string,or NULL if not found//~4C20I~
//*        return top addr if parm2 is null string              //~4C20I~
//******************************************************        //~4C20I~
char *ustrnstr(const char *Pbuff,const char *Pkey,unsigned int Plen)//~4C20I~
{                                                               //~4C20I~
	char *pc,*pco,*pcl;                                         //~4C20I~
	char ch;                                                    //~4C20I~
	unsigned int lenk;                                          //~4C20I~
//******************                                            //~4C20I~
//  Plen=ustrnlen((char*)(ULONG)Pbuff,Plen);                       //~v5fkR~//~v6hhR~
//  Plen=ustrnlen((char*)(ULPTR)Pbuff,Plen);                       //~v6hhI~//~v6BxR~
    Plen=(UINT)ustrnlen((char*)(ULPTR)Pbuff,Plen);                 //~v6BxI~
//  if (!(lenk=strlen(Pkey)))                                   //~4C20I~//~v6BxR~
    if (!(lenk=(UINT)strlen(Pkey)))                                //~v6BxI~
//		return (char*)(ULONG)Pbuff;                                //~v5fkR~//~v6hhR~
		return (char*)(ULPTR)Pbuff;                                //~v6hhI~
    if (lenk>Plen)                                              //~4C20I~
    	return 0;                                               //~4C20I~
//  if (memcmp(pcl=(char*)(ULONG)Pbuff+Plen-lenk,Pkey,lenk))	//match at last//~v5fkR~//~v6hhR~
    if (memcmp(pcl=(char*)(ULPTR)Pbuff+Plen-lenk,Pkey,lenk))	//match at last//~v6hhI~
		pcl=0;                           		//last unmatch  //~4C20I~
//	ch=*(pc=(char*)(ULONG)Pbuff+Plen-1);	//save last byte       //~v5fkR~//~v6hhR~
	ch=*(pc=(char*)(ULPTR)Pbuff+Plen-1);	//save last byte       //~v6hhI~
	*pc=0;					//create string for ustrrspn        //~4C20I~
	pco=strstr(Pbuff,Pkey);                                     //~4C20I~
	*pc=ch;					//restore last byte                 //~4C20I~
	if (!pco)  				//not found                         //~4C20I~
		pco=pcl;          	//set result of last chk            //~4C20I~
	return pco;                                                 //~4C20I~
}//ustrnstr                                                     //~4C20I~
                                                                //~4C20I~
//*******************************************************       //~4C19I~
//*ustrrstr                                                     //~4C19I~
//* search last parm2 string on parm1 string                    //~4C19I~
//* parm1 :string to be serached                                //~4C19I~
//* parm2 :search key string                                    //~4C19I~
//* return:pinter to string on parm1 string,or NULL if not found//~4C19I~
//*        null char addr if parm2 is null char                 //~4C20I~
//******************************************************        //~4C19I~
char *ustrrstr(const char *Pbuff,const char *Pkey)              //~4C19I~
{                                                               //~4C19I~
	char *pc,*pco;                                              //~4C19I~
//******************                                            //~4C19I~
    if (!*Pkey)			//null key                              //~4C20I~
//		return (char*)(ULONG)Pbuff+strlen(Pbuff);                  //~v5fkR~//~v6hhR~
		return (char*)(ULPTR)Pbuff+strlen(Pbuff);                  //~v6hhI~
//	for (pco=0,pc=(char *)(ULONG)Pbuff;pc=strstr(pc,Pkey),pc;pc++) //~v5fkR~//~v6hhR~
	for (pco=0,pc=(char *)(ULPTR)Pbuff;pc=strstr(pc,Pkey),pc;pc++) //~v6hhI~
		pco=pc;                                                 //~4C19I~
	return pco;                                                 //~4C19I~
}//ustrrstr                                                     //~4C19I~
                                                                //~4C19I~
//*******************************************************       //~4C20I~
//*ustrnrstr                                                    //~4C20I~
//* search last parm2 string on parm1 string                    //~4C20I~
//* parm1 :string to be serached                                //~4C20I~
//* parm2 :search key string                                    //~4C20I~
//* parm3 :parm1 length                                         //~4C20I~
//* return:pinter to string on parm1 string,or NULL if not found//~4C20I~
//*        null char addr if parm2 is null char                 //~4C20I~
//******************************************************        //~4C20I~
char *ustrnrstr(const char *Pbuff,const char *Pkey,unsigned int Plen)//~4C20I~
{                                                               //~4C20I~
	char *pc,*pco;                                              //~4C20I~
	char ch;                                                    //~4C20I~
	unsigned int lenk;                                          //~4C20I~
//******************                                            //~4C20I~
//  Plen=ustrnlen((char*)(ULONG)Pbuff,Plen);                       //~v5fkR~//~v6hhR~
//  Plen=ustrnlen((char*)(ULPTR)Pbuff,Plen);                       //~v6hhI~//~v6BxR~
    Plen=(UINT)ustrnlen((char*)(ULPTR)Pbuff,Plen);                 //~v6BxI~
//  lenk=strlen(Pkey);                                          //~4C20I~//~v6BxR~
    lenk=(UINT)strlen(Pkey);                                       //~v6BxI~
    if (lenk>Plen)                                              //~4C20I~
    	return 0;                                               //~4C20I~
	if (!memcmp(Pbuff+Plen-lenk,Pkey,lenk))	//match at last     //~4C20I~
//		return (char*)(ULONG)Pbuff+Plen-lenk;                      //~v5fkR~//~v6hhR~
		return (char*)(ULPTR)Pbuff+Plen-lenk;                      //~v6hhI~
//	ch=*(pc=(char*)(ULONG)Pbuff+Plen-1);	//save last byte       //~v5fkR~//~v6hhR~
	ch=*(pc=(char*)(ULPTR)Pbuff+Plen-1);	//save last byte       //~v6hhI~
	*pc=0;					//create string for ustrrspn        //~4C20I~
	pco=ustrrstr(Pbuff,Pkey);                                   //~4C20I~
	*pc=ch;					//restore last byte                 //~4C20I~
	return pco;                                                 //~4C20I~
}//ustrnrstr                                                    //~4C20I~
                                                                //~4C20I~
//*******************************************************       //~4C19I~
//*ustrstri                                                     //~4C19I~
//* search parm2 string on parm1 string by case insensitive     //~4C19I~
//* parm1 :string to be serached                                //~4C19I~
//* parm2 :search key string                                    //~4C19I~
//* return:pinter to string on parm1 string,or NULL if not found//~4C19I~
//*        null char addr if parm2 is null char                 //~4C20I~
//******************************************************        //~4C19I~
char *ustrstri(const char *Pbuff,const char *Pkey)              //~4C19I~
{                                                               //~4C19I~
	char topchar[3];                                            //~4C19I~
	char *pc,*pce;                                              //~4C19I~
	int  lenk;                                                  //~4C19I~
//******************                                            //~4C19I~
	topchar[0]=(char)toupper(*Pkey);                            //~4C19I~
	topchar[1]=(char)tolower(*Pkey);                            //~4C19I~
	topchar[2]=0;                                               //~4C19I~
	if (!(lenk=(int)strlen(Pkey)))                              //~4C20R~
//     	return (char*)(ULONG)Pbuff+strlen(Pbuff);                  //~v5fkR~//~v6hhR~
     	return (char*)(ULPTR)Pbuff+strlen(Pbuff);                  //~v6hhI~
//	for (pc=(char *)(ULONG)Pbuff,pce=(char *)(ULONG)Pbuff+strlen(Pbuff)-lenk;//~v5fkR~//~v6hhR~
	for (pc=(char *)(ULPTR)Pbuff,pce=(char *)(ULPTR)Pbuff+strlen(Pbuff)-lenk;//~v6hhI~
		 (pc=strpbrk(pc,topchar),pc) && pc<=pce;)      //~4C19I~
	{                                                           //~4C19I~
//		if (!memicmp(pc,(char*)(ULONG)Pkey,(UINT)lenk))//match case insensitive//~v5fkR~//~v6hhR~
		if (!memicmp(pc,(char*)(ULPTR)Pkey,(UINT)lenk))//match case insensitive//~v6hhI~
 			break;                                              //~4C19I~
		if (++pc>pce)                                           //~4C19I~
    		break;
	}                                                           //~4C19I~
	if (pc>pce)                                           //~4C19I~
    	pc=0;                                              //~4C19I~
	return pc;                                                  //~4C19I~
}//ustrstri                                                     //~4C19R~
                                                                //~4C19I~
//*******************************************************       //~4C20I~
//*ustrnstri                                                    //~4C20I~
//* search parm2 string on parm1 string by case insensitive     //~4C20I~
//* parm1 :string to be serached                                //~4C20I~
//* parm2 :search key string                                    //~4C20I~
//* parm3 :parm1 string len                                     //~4C20I~
//* return:pinter to string on parm1 string,or NULL if not found//~4C20I~
//*        null char addr if parm2 is null char                 //~4C20I~
//******************************************************        //~4C20I~
char *ustrnstri(const char *Pbuff,const char *Pkey,unsigned int Plen)//~4C20I~
{                                                               //~4C20I~
	char *pc,*pco,*pcl;                                         //~4C20I~
	char ch;                                                    //~4C20I~
	unsigned int lenk;                                          //~4C20I~
//******************                                            //~4C20I~
//  Plen=ustrnlen((char*)(ULONG)Pbuff,Plen);                       //~v5fkR~//~v6hhR~
//  Plen=ustrnlen((char*)(ULPTR)Pbuff,Plen);                       //~v6hhI~//~v6BxR~
    Plen=(UINT)ustrnlen((char*)(ULPTR)Pbuff,Plen);                 //~v6BxI~
//  lenk=strlen(Pkey);                                          //~4C20I~//~v6BxR~
    lenk=(UINT)strlen(Pkey);                                       //~v6BxI~
    if (lenk>Plen)                                              //~4C20I~
    	return 0;                                               //~4C20I~
//	if (memicmp(pcl=(char*)(ULONG)Pbuff+Plen-lenk,(char*)(ULONG)Pkey,lenk))	//not match at last//~v5fkR~//~v6hhR~
	if (memicmp(pcl=(char*)(ULPTR)Pbuff+Plen-lenk,(char*)(ULPTR)Pkey,lenk))	//not match at last//~v6hhI~
		pcl=0;                           		//last unmatch  //~4C20I~
//	ch=*(pc=(char*)(ULONG)Pbuff+Plen-1);	//save last byte       //~v5fkR~//~v6hhR~
	ch=*(pc=(char*)(ULPTR)Pbuff+Plen-1);	//save last byte       //~v6hhI~
	*pc=0;					//create string for ustrrspn        //~4C20I~
	pco=ustrstri(Pbuff,Pkey);                                   //~4C20I~
	*pc=ch;					//restore last byte                 //~4C20I~
	if (!pco)  				//not found                         //~4C20I~
		pco=pcl;          	//set result of last chk            //~4C20I~
	return pco;                                                 //~4C20I~
}//ustrnstri                                                    //~4C20I~
                                                                //~4C20I~
//*******************************************************       //~4C19I~
//*ustrrstri                                                    //~4C19I~
//* search last parm2 string on parm1 string  case insensitve   //~4C19I~
//* parm1 :string to be serached                                //~4C19I~
//* parm2 :search key string                                    //~4C19I~
//* return:pinter to string on parm1 string,or NULL if not found//~4C19I~
//*        null char addr if parm2 is null char                 //~4C20I~
//******************************************************        //~4C19I~
char *ustrrstri(const char *Pbuff,const char *Pkey)             //~4C19I~
{                                                               //~4C19I~
	char *pc,*pco;                                              //~4C19I~
//******************                                            //~4C19I~
    if (!*Pkey)			//null key                              //~4C20I~
//		return (char*)(ULONG)Pbuff+strlen(Pbuff);                  //~v5fkR~//~v6hhR~
		return (char*)(ULPTR)Pbuff+strlen(Pbuff);                  //~v6hhI~
//	for (pco=0,pc=(char *)(ULONG)Pbuff;pc=ustrstri(pc,Pkey),pc;pc++)//~v5fkR~//~v6hhR~
	for (pco=0,pc=(char *)(ULPTR)Pbuff;pc=ustrstri(pc,Pkey),pc;pc++)//~v6hhI~
		pco=pc;                                                 //~4C19I~
	return pco;                                                 //~4C19I~
}//ustrrstri                                                    //~4C19I~
                                                                //~4C19I~
//*******************************************************       //~4C19I~
//*ustrnrstri                                                   //~4C19I~
//* search last parm2 string on parm1 string  case insensitve   //~4C19I~
//* parm1 :string to be serached                                //~4C19I~
//* parm2 :search key string                                    //~4C19I~
//* parm3 :parm1 len                                            //~4C19I~
//* return:pinter to string on parm1 string,or NULL if not found//~4C19I~
//*        null char addr if parm2 is null char                 //~4C20I~
//******************************************************        //~4C19I~
char *ustrnrstri(const char *Pbuff,const char *Pkey,unsigned int Plen)//~4C19I~
{                                                               //~4C19I~
	char *pc,*pco;                                              //~4C20R~
	char ch;                                                    //~4C20I~
	unsigned int lenk;                                          //~4C20I~
//******************                                            //~4C20I~
//  Plen=ustrnlen((char*)(ULONG)Pbuff,Plen);                       //~v5fkR~//~v6hhR~
//  Plen=ustrnlen((char*)(ULPTR)Pbuff,Plen);                       //~v6hhI~//~v6BxR~
    Plen=(UINT)ustrnlen((char*)(ULPTR)Pbuff,Plen);                 //~v6BxI~
//  lenk=strlen(Pkey);                                          //~4C20I~//~v6BxR~
    lenk=(UINT)strlen(Pkey);                                       //~v6BxI~
    if (lenk>Plen)                                              //~4C20I~
    	return 0;                                               //~4C20I~
//	if (!memicmp((char*)(ULONG)Pbuff+Plen-lenk,(char*)(ULONG)Pkey,lenk))//match at last//~v5fkR~//~v6hhR~
	if (!memicmp((char*)(ULPTR)Pbuff+Plen-lenk,(char*)(ULPTR)Pkey,lenk))//match at last//~v6hhI~
//		return (char*)(ULONG)Pbuff+Plen-lenk;                      //~v5fkR~//~v6hhR~
		return (char*)(ULPTR)Pbuff+Plen-lenk;                      //~v6hhI~
//	ch=*(pc=(char*)(ULONG)Pbuff+Plen-1);	//save last byte       //~v5fkR~//~v6hhR~
	ch=*(pc=(char*)(ULPTR)Pbuff+Plen-1);	//save last byte       //~v6hhI~
	*pc=0;					//create string for ustrrspn        //~4C20I~
	pco=ustrrstri(Pbuff,Pkey);                                  //~4C20R~
	*pc=ch;					//restore last byte                 //~4C20I~
	return pco;                                                 //~4C20I~
}//ustrnrstri                                                   //~4C20R~
                                                                //~4C19I~
//*******************************************************       //~4C23I~
//*ustrnrchr                                                    //~4C23R~
//* search last char on parm1                                   //~4C23I~
//* parm1 :string to be checked                                 //~4C23I~
//* parm2 :search key char                                      //~4C23I~
//* parm3 :parm1 len                                            //~4C23I~
//* return:pinter to char on parm1 string,or NULL if not found  //~4C23I~
//*        NULL return if parm1 len=0                           //~4C23I~
//******************************************************        //~4C23I~
char *ustrnrchr(const char *Pbuff,UCHAR Pch,size_t Plen)        //~4C23R~
{                                                               //~4C23I~
	char *pc,*pco;                                              //~4C23I~
	char ch;                                                    //~4C23I~
//******************                                            //~4C23I~
//  Plen=ustrnlen((char*)(ULONG)Pbuff,Plen);                       //~v5fkR~//~v6hhR~
//  Plen=ustrnlen((char*)(ULPTR)Pbuff,Plen);                       //~v6hhI~//~v6BxR~
    Plen=(UINT)ustrnlen((char*)(ULPTR)Pbuff,(UINT)Plen);           //~v6BxR~
	if (!Plen)                                                  //~4C23I~
		return 0;                                               //~4C23I~
//  ch=*(pc=(char*)(ULONG)Pbuff+Plen-1);		//save char        //~v5fkR~//~v6hhR~
    ch=*(pc=(char*)(ULPTR)Pbuff+Plen-1);		//save char        //~v6hhI~
   	if (ch==Pch)                                                //~4C23I~
		return pc;                                              //~4C23I~
	*pc=0;                                                      //~4C23I~
    pco=strrchr(Pbuff,Pch);                                     //~4C23I~
	*pc=ch;			//restore                                   //~4C23I~
	if (Pch)		//not null search                           //~4C23I~
		return pco;                                             //~4C23I~
	else 			//null search                               //~4C23I~
		if (pco==pc)		//match with replaced char          //~4C23I~
			if (ch)			//original is not null              //~4C23I~
				return 0;                                       //~4C23I~
			else                                                //~4C23I~
				return pc;                                      //~4C23I~
		else                                                    //~4C23I~
			return pco;                                         //~4C23I~
}//ustrnrchr                                                    //~4C23R~
#ifdef UTF8SUPPH                                                   //~v620I~
//*******************************************************          //~v620I~
//*umemchar_utf                                                    //~v620I~
//* search SBCS char protecting to detect DBCS(not Japanese) 2nd byte or UTF8//~v620I~
//*Plen=0 for strchr                                               //~v620I~
//*Ppc:found pos                                                   //~v620I~
//******************************************************           //~v620I~
char *umemchr_utf(int Pdest,char *Pbuff,char Pch,char *Ppc,int Plen)//~v620R~
{                                                                  //~v620I~
	UCHAR *pc,*pcf=0;                                              //~v620I~
//  ULONG ucs;                                                     //~v620I~//~v691R~
    UWUCS ucs;                                                     //~v691I~
    int rlen,ch,chsz,rc2;                                          //~v620R~
//******************************                                   //~v620I~
//  if (Pch<UDBCSCHK_DBCS2ND_MIN)                                  //~v62UR~
    if (Pch<UDBCSCHK_DBCS2ND_MIN())                                //~v62UR~
    {                                                              //~v620I~
        if (!Pdest)		//forward                                  //~v620I~
			return Ppc;                                            //~v620I~
//  	return umemrchr(Pbuff,Pch,Plen); //backward                //~v620I~//~v6BkR~
    	return umemrchr(Pbuff,Pch,(size_t)Plen); //backward        //~v6BkI~
    }                                                              //~v620I~
//  if (UDBCSCHK_ISDBCSJ_LOCAL())	//japanese	SJIS or EUC        //~v620I~
//  	return (char *)-1;          //old logic                    //~v620I~
	if (!UDBCSCHK_ISDBCS())                                        //~v620I~
    {                                                              //~v620R~
        if (!Pdest)		//forward                                  //~v620R~
			return Ppc;                                            //~v620R~
//  	return umemrchr(Pbuff,Pch,Plen); //backward                //~v620R~//~v6BkR~
    	return umemrchr(Pbuff,Pch,(size_t)Plen); //backward        //~v6BkI~
    }                                                              //~v620R~
	for (pc=Pbuff,rlen=Plen;rlen>0;pc+=chsz,rlen-=chsz)            //~v620R~
    {                                                              //~v620I~
        ch=*pc;                                                    //~v620I~
    	if (ch==Pch)                                               //~v620I~
        {                                                          //~v620I~
            pcf=pc;		//last match                               //~v620M~
        	if (!Pdest)		//forward                              //~v620I~
	        	break;			//found                            //~v620R~
        }                                                          //~v620I~
//#ifdef UTF8UCS4                                                    //~v65cI~//~v6uER~
#ifdef UTF8UCS416                                                  //~v6uER~
		rc2=uccvutf2ucs(UCVUCS_UCS4,pc,rlen,&ucs,&chsz);           //~v65cI~
#else                                                              //~v65cI~
		rc2=uccvutf2ucs(0,pc,rlen,&ucs,&chsz);                     //~v620I~
#endif                                                             //~v65cI~
        if (rc2) 	//not utf8                                     //~v620I~
//  		chsz=udbcschk_getmblen(0,pc);                          //~v62UR~
    		udbcschk_getmblen(0,pc,rlen,&chsz);                    //~v62UR~
	}                                                              //~v620I~
	return pcf;                                                    //~v620R~
//  UTRACEP("umemchr_utf srch=%c,dest=%d,pos=%p\n",Pch,Pdest,pcf); //~v620R~//~v6heR~
//  UTRACED("umemchr_utf",Pbuff,Plen);                             //~v620I~//~v6heR~
}//umemchr_utf                                                     //~v620I~
#endif                                                             //~v620I~
//*******************************************************          //~v017I~
//*ustrchr2                                                        //~v017I~
//* search SBCS char protecting to detect DBCS 2nd byte            //~v017I~
//* parm1 :string to be checked                                    //~v017I~
//* parm2 :search key SBCS char                                    //~v017I~
//* return:pinter to char on parm1 string,or NULL if not found     //~v017I~
//*        NULL return if parm1 len=0                              //~v017I~
//******************************************************           //~v017I~
char *ustrchr2(char *Pbuff,char Pch)                               //~v017I~
{                                                                  //~v017I~
	char *pc,*pc2;                                                 //~v017I~
//*********************************                                //~v017I~
	if (pc=strchr(Pbuff,Pch),!pc)                                  //~v022R~
    	return 0;                                                  //~v017I~
#ifdef UTF8SUPPH                                                   //~v620I~
//	if (pc=umemchr_utf(0/*forward*/,Pbuff,Pch,pc,(int)strlen(Pbuff)),pc!=(char*)-1);//~v620R~//~v6hfR~
//  if (pc=umemchr_utf(0/*forward*/,Pbuff,Pch,pc,(int)strlen(Pbuff)),pc!=(char*)-1)//~v6hfI~//~v6hhR~
    if (pc=umemchr_utf(0/*forward*/,Pbuff,Pch,pc,(int)strlen(Pbuff)),pc!=(char*)(ULPTR)-1)//~v6hhI~
    	return pc;                                                 //~v620I~
#endif                                                             //~v620I~
  	if (pc==Pbuff  //first byte match                              //~v017I~
    ||  !udbcschk((unsigned char)(*(pc-1))))  //prev is not dbcs 1st byte//~v022R~
    	return pc;                                                 //~v017I~
	pc2=Pbuff+strlen(Pbuff);	//end addr                         //~v017I~
	for (pc=Pbuff;pc<pc2;pc++)                                     //~v017I~
    {                                                              //~v017I~
    	if (*pc==Pch)                                              //~v017I~
        	return pc;			//found                            //~v017I~
		if (udbcschk(*pc))	//dbcs 1st byte                        //~v017I~
    		pc++;                                                  //~v017I~
	}                                                              //~v017I~
	return 0;                                                      //~v017I~
}//ustrchr2                                                        //~v017I~
                                                                   //~v017I~
//*******************************************************          //~v017I~
//*ustrnchr2                                                       //~v017I~
//* search SBCS char protecting to detect DBCS 2nd byte with length//~v017I~
//* parm1 :string to be checked                                    //~v017I~
//* parm2 :search key SBCS char                                    //~v017I~
//* parm3 :str length                                              //~v017I~
//* return:pinter to char on parm1 string,or NULL if not found     //~v017I~
//*        NULL return if parm1 len=0                              //~v017I~
//******************************************************           //~v017I~
char *ustrnchr2(char *Pbuff,char Pch,size_t Plen)                  //~v093R~
{                                                                  //~v017I~
//  char pch,ch,*pc;                                               //~v093R~
//  int plen;                                                      //~v093R~
//*********************************                                //~v017I~
//  plen=Plen;			//to protect destroyed by 0 set following  //~v093R~
//  pch=Pch;			//to protect destroyed by 0 set following  //~v093R~
//  ch=*(Pbuff+plen);	//save for 0                               //~v093R~
//  *(Pbuff+plen)=0;                                               //~v093R~
//  pc=ustrchr2(Pbuff,pch);                                        //~v093R~
//  *(Pbuff+plen)=ch;                                              //~v093R~
//  return pc;                                                     //~v093I~
//  return umemchr2(Pbuff,Pch,ustrnlen(Pbuff,Plen));               //~v093R~//~v6BxR~
    return umemchr2(Pbuff,Pch,(UINT)ustrnlen(Pbuff,(UINT)Plen));   //~v6BxR~
}//ustrnchr2                                                       //~v017I~
                                                                   //~v017I~
//*******************************************************          //~v093I~
//*umemchr2                                                        //~v093I~
//* search SBCS char protecting to detect DBCS 2nd byte with length//~v093I~
//* parm1 :string to be checked                                    //~v093I~
//* parm2 :search key SBCS char                                    //~v093I~
//* parm3 :mem length                                              //~v093I~
//* return:pinter to char on parm1 string,or NULL if not found     //~v093I~
//*        NULL return if parm1 len=0                              //~v093I~
//******************************************************           //~v093I~
char *umemchr2(char *Pbuff,char Pch,size_t Plen)                   //~v093R~
{                                                                  //~v093I~
	char *pc,*pc2;                                                 //~v093I~
//*********************************                                //~v093I~
	if (pc=memchr(Pbuff,Pch,(UINT)Plen),!pc)                       //~v093I~
    	return 0;                                                  //~v093I~
#ifdef UTF8SUPPH                                                   //~v620I~
//  if (pc=umemchr_utf(0/*forward*/,Pbuff,Pch,pc,(int)Plen),pc!=(char*)-1);//~v620R~//~v6hfR~
//  if (pc=umemchr_utf(0/*forward*/,Pbuff,Pch,pc,(int)Plen),pc!=(char*)-1)//~v6hfI~//~v6hhR~
    if (pc=umemchr_utf(0/*forward*/,Pbuff,Pch,pc,(int)Plen),pc!=(char*)(ULPTR)-1)//~v6hhI~
    	return pc;                                                 //~v620I~
#endif                                                             //~v620I~
  	if (pc==Pbuff  //first byte match                              //~v093I~
    ||  !udbcschk((unsigned char)(*(pc-1))))  //prev is not dbcs 1st byte//~v093I~
    	return pc;                                                 //~v093I~
	pc2=Pbuff+Plen;	//end addr                                     //~v093I~
	for (pc=Pbuff;pc<pc2;pc++)                                     //~v093I~
    {                                                              //~v093I~
    	if (*pc==Pch)                                              //~v093I~
        	return pc;			//found                            //~v093I~
		if (udbcschk(*pc))	//dbcs 1st byte                        //~v093I~
    		pc++;                                                  //~v093I~
	}                                                              //~v093I~
	return 0;                                                      //~v093I~
}//umemchr2                                                        //~v093I~
                                                                   //~v093I~
//*******************************************************          //~v017I~
//*ustrrchr2                                                       //~v017I~
//* search last SBCS char protecting to detect DBCS 2nd byte       //~v017I~
//* parm1 :string to be checked                                    //~v017I~
//* parm2 :search key SBCS char                                    //~v017I~
//* return:pinter to char on parm1 string,or NULL if not found     //~v017I~
//*        NULL return if parm1 len=0                              //~v017I~
//******************************************************           //~v017I~
char *ustrrchr2(char *Pbuff,char Pch)                              //~v017R~
{                                                                  //~v017I~
	char *pc,*pc2,*pc3;                                            //~v017R~
//*********************************                                //~v017I~
	if (pc=strrchr(Pbuff,(int)Pch),!pc)                            //~v022R~
    	return 0;                                                  //~v017I~
#ifdef UTF8SUPPH                                                   //~v620I~
//  if (pc=umemchr_utf(1/*backward*/,Pbuff,Pch,pc,(int)strlen(Pbuff)),pc!=(char*)-1);//~v620R~//~v6hfR~
//  if (pc=umemchr_utf(1/*backward*/,Pbuff,Pch,pc,(int)strlen(Pbuff)),pc!=(char*)-1)//~v6hfI~//~v6hhR~
    if (pc=umemchr_utf(1/*backward*/,Pbuff,Pch,pc,(int)strlen(Pbuff)),pc!=(char*)(ULPTR)-1)//~v6hhI~
    	return pc;                                                 //~v620I~
#endif                                                             //~v620I~
  	if (pc==Pbuff  //first byte match                              //~v017I~
    ||  !udbcschk(*(pc-1)))  //prev is not dbcs 1st byte           //~v017I~
    	return pc;                                                 //~v017I~
	pc2=pc;		//end addr                                         //~v017I~
	for (pc=Pbuff,pc3=0;pc<=pc2;pc++)                              //~v017R~
    {                                                              //~v017I~
    	if (*pc==Pch)                                              //~v017I~
        	pc3=pc;			//last match                           //~v017I~
		if (udbcschk(*pc))	//dbcs 1st byte                        //~v017I~
    		pc++;                                                  //~v017I~
	}                                                              //~v017I~
    return pc3;                                                    //~v017R~
}//ustrrchr2                                                       //~v017I~
                                                                   //~v017I~
//*******************************************************          //~v017I~
//*ustrnrchr2                                                      //~v017I~
//* search last SBCS char protecting to detect DBCS 2nd byte with length//~v017I~
//* parm1 :string to be checked                                    //~v017I~
//* parm2 :search key SBCS char                                    //~v017I~
//* parm3 :str length                                              //~v017I~
//* return:pinter to char on parm1 string,or NULL if not found     //~v017I~
//*        NULL return if parm1 len=0                              //~v017I~
//******************************************************           //~v017I~
char *ustrnrchr2(char *Pbuff,char Pch,size_t Plen)                 //~v093R~
{                                                                  //~v017I~
//  char pch,ch,*pc;                                               //~v093R~
//  int plen;                                                      //~v093R~
//*********************************                                //~v017I~
//  plen=Plen;			//to protect destroyed by 0 set following  //~v093R~
//  pch=Pch;			//to protect destroyed by 0 set following  //~v093R~
//  ch=*(Pbuff+plen);	//save for 0                               //~v093R~
//  *(Pbuff+plen)=0;                                               //~v093R~
//  pc=ustrrchr2(Pbuff,pch);                                       //~v093R~
//  *(Pbuff+plen)=ch;                                              //~v093R~
//  return pc;                                                     //~v093R~
//  return umemchr2(Pbuff,Pch,ustrnlen(Pbuff,Plen));               //~v628R~
//  return umemrchr2(Pbuff,Pch,ustrnlen(Pbuff,Plen));              //~v628I~//~v6BxR~
    return umemrchr2(Pbuff,Pch,(UINT)ustrnlen(Pbuff,(UINT)Plen));  //~v6BxR~
}//ustrnrchr2                                                      //~v017I~
                                                                   //~v017I~
//*******************************************************          //~v093I~
//*umemrchr2                                                       //~v093I~
//* search last SBCS char protecting to detect DBCS 2nd byte with length//~v093I~
//* parm1 :string to be checked                                    //~v093I~
//* parm2 :search key SBCS char                                    //~v093I~
//* parm3 :mem length                                              //~v093I~
//* return:pinter to char on parm1 string,or NULL if not found     //~v093I~
//*        NULL return if parm1 len=0                              //~v093I~
//******************************************************           //~v093I~
char *umemrchr2(char *Pbuff,char Pch,size_t Plen)                  //~v093R~
{                                                                  //~v093I~
	char *pc,*pc2,*pc3;                                            //~v093I~
//*********************************                                //~v093I~
	if (!memchr(Pbuff,(int)Pch,(UINT)Plen))                        //~v093I~
    	return 0;                                                  //~v093I~
#ifdef UTF8SUPPH                                                   //~v620I~
    pc=0;                                                          //~v620I~
//  if (pc=umemchr_utf(1/*backward*/,Pbuff,Pch,pc,(int)Plen),pc!=(char*)-1);//~v620R~//~v6hfR~
//  if (pc=umemchr_utf(1/*backward*/,Pbuff,Pch,pc,(int)Plen),pc!=(char*)-1)//~v6hfI~//~v6hhR~
    if (pc=umemchr_utf(1/*backward*/,Pbuff,Pch,pc,(int)Plen),pc!=(char*)(ULPTR)-1)//~v6hhI~
    	return pc;                                                 //~v620I~
#endif                                                             //~v620I~
	pc2=Pbuff+Plen;		//end addr                                 //~v093I~
	for (pc=Pbuff,pc3=0;pc<pc2;pc++)                               //~v093I~
    {                                                              //~v093I~
    	if (*pc==Pch)                                              //~v093I~
        	pc3=pc;			//last match                           //~v093I~
		if (udbcschk(*pc))	//dbcs 1st byte                        //~v093I~
    		pc++;                                                  //~v093I~
	}                                                              //~v093I~
    return pc3;                                                    //~v093I~
}//umemrchr2                                                       //~v093I~
                                                                   //~v093I~
//*******************************************************          //~v088I~
//*umemrchr                                                        //~v088I~
//* search last char on parm1                                      //~v088I~
//* parm1 :buff to be checked                                      //~v088I~
//* parm2 :search key char                                         //~v088I~
//* parm3 :parm1 len                                               //~v088I~
//* return:pointer to char on parm1,or NULL if not found           //~v088I~
//*        NULL return if parm1 len=0                              //~v088I~
//******************************************************           //~v088I~
char *umemrchr(char *Pbuff,UCHAR Pch,size_t Plen)                  //~v088I~
{                                                                  //~v088I~
//    char *pc,*pco;                                               //~v516R~
//    UINT len;                                                    //~v516R~
////******************                                             //~v516R~
//    for (pco=0,pc=Pbuff,len=Plen;len;)                           //~v516R~
//    {                                                            //~v516R~
//        if (!(pc=memchr(pc,Pch,len)))                            //~v516R~
//            return pco;                                          //~v516R~
//        pco=pc;                                                  //~v516R~
//        pc++;                                                    //~v516R~
//        len=Plen-(UINT)((ULONG)pc-(ULONG)Pbuff);                 //~v516R~
//    }                                                            //~v516R~
//    return pco;                                                  //~v516R~
	UCHAR *pc;                                                     //~v516I~
//******************                                               //~v516I~
	for (pc=Pbuff+Plen-1;pc>=(UCHAR*)Pbuff;pc--)                   //~v516R~
    {                                                              //~v516I~
    	if (*pc==Pch)                                              //~v516I~
        	return pc;                                             //~v516I~
	}                                                              //~v516I~
    return 0;                                                      //~v516I~
}//umemrchr                                                        //~v088I~
                                                                   //~v088I~
//*******************************************************          //~v57sI~
//*umempbrk                                                        //~v57sI~
//* search pos of char on parm string                              //~v57sI~
//* parm1 :buff to be checked                                      //~v57sI~
//* parm2 :search char string                                      //~v57sI~
//* parm3 :parm1 len                                               //~v57sI~
//* return:pointer to char on parm1,or NULL if not found           //~v57sI~
//*        NULL return if parm1 len=0                              //~v57sI~
//******************************************************           //~v57sI~
char *umempbrk(char *Pbuff,UCHAR *Pstr,size_t Plen)                //~v57sR~
{                                                                  //~v57sI~
	char *pcb,*pcs,*pcbn,*pco=0;                                   //~v57sI~
    UINT len;                                                      //~v57sI~
//******************                                               //~v57sI~
	pcb=Pbuff;                                                     //~v57sI~
//  len=Plen;                                                      //~v57sI~//~v6BxR~
    len=(UINT)Plen;                                                //~v6BxI~
//  for (pcs=Pstr;*pcs && len;pcs++)                               //~v5fkR~
    for (pcs=Pstr;len && *pcs;pcs++)                               //~v5fkI~
    {                                                              //~v57sI~
    	if (pcbn=memchr(pcb,*pcs,len),pcbn)                        //~v57sR~
        {                                                          //~v57sI~
			pco=pcbn;                                              //~v57sI~
            if (pcbn==pcb)  //fopund at top                        //~v57sI~
            	break;                                             //~v57sM~
//      	len=(ULONG)pco-(ULONG)pcb-1;                           //~v5fkR~
//        	len=(ULONG)pco-(ULONG)pcb;                             //~v5fkI~//~v6hhR~
//      	len=(ULPTR)pco-(ULPTR)pcb;                             //~v6hhI~//~v6BxR~
        	len=(UINT)PTRDIFF(pco,pcb);                            //~v6BxI~
        }                                                          //~v57sI~
	}                                                              //~v57sI~
    return pco;                                                    //~v57sI~
}//umempbrk                                                        //~v57sR~
                                                                   //~v57sI~
//*******************************************************          //~v516I~
//*umemrpbrk                                                       //~v516I~
//* search last pos of char on parm string                         //~v516I~
//* parm1 :buff to be checked                                      //~v516I~
//* parm2 :search char string                                      //~v516I~
//* parm3 :parm1 len                                               //~v516I~
//* return:pointer to char on parm1,or NULL if not found           //~v516I~
//*        NULL return if parm1 len=0                              //~v516I~
//******************************************************           //~v516I~
char *umemrpbrk(char *Pbuff,UCHAR *Pstr,size_t Plen)               //~v516I~
{                                                                  //~v516I~
	char *pcb,*pcs,*pcbn,*pco=0,*pce;                              //~v516R~
    UINT len;                                                      //~v516I~
//******************                                               //~v516I~
	pcb=Pbuff;                                                     //~v516I~
    pce=pcb+Plen;		//end addr                                 //~v516I~
//  len=Plen;                                                      //~v516I~//~v6BxR~
    len=(UINT)Plen;                                                //~v6BxI~
//  for (pcs=Pstr;*pcs && len;pcs++)                               //~v5fkR~
    for (pcs=Pstr;len && *pcs;pcs++)                               //~v5fkI~
    {                                                              //~v516I~
    	if (pcbn=umemrchr(pcb,*pcs,len),pcbn)                      //~v516R~
        {                                                          //~v516I~
			pco=pcbn;                                              //~v516R~
        	pcb=pcbn+1;                                            //~v516R~
//        	len=(ULONG)pce-(ULONG)pcb;                             //~v516I~//~v6hhR~
//      	len=(ULPTR)pce-(ULPTR)pcb;                             //~v6hhI~//~v6BxR~
        	len=(UINT)PTRDIFF(pce,pcb);                            //~v6BxI~
        }                                                          //~v516I~
	}                                                              //~v516I~
    return pco;                                                    //~v516I~
}//umemrpbrk                                                       //~v516I~
                                                                   //~v516I~
//*******************************************************          //~v091I~
//*ustrnlen                                                        //~v091I~
//* strlen but max is up to parm                                   //~v091I~
//* parm1 :string to be serached null                              //~v091I~
//* parm2 :string max len                                          //~v091I~
//* return:len                                                     //~v091I~
//******************************************************           //~v091I~
size_t ustrnlen(char *Pbuff,unsigned int Plen)                     //~v091I~
{                                                                  //~v091I~
	char *pc;                                                      //~v091R~
//******************                                               //~v091I~
	pc=memchr(Pbuff,0,Plen);                                       //~v091R~
	if (!pc)	//not found                                        //~v091R~
    	return Plen;                                               //~v091I~
//	return (UINT)((ULONG)pc-(ULONG)Pbuff);                         //~v091R~//~v6hhR~
	return (UINT)((ULPTR)pc-(ULPTR)Pbuff);                         //~v6hhI~
}//ustrnlen                                                        //~v091I~
                                                                   //~v091I~
//*******************************************************          //~v092I~
//*umemstr                                                         //~v092I~
//* search string parm2 on mem parm1                               //~v092I~
//* parm1 :mem                                                     //~v092I~
//* parm2 :search key string case sensitive                        //~v092I~
//* parm3 :parm1 len                                               //~v092I~
//* return:pointer to mem on parm1,or NULL if not found            //~v092I~
//*        return top addr if parm2 len=0                          //~v092I~
//******************************************************           //~v092I~
char *umemstr(char *Pbuff,char *Pkey,unsigned int Plen)            //~v092I~
{                                                                  //~v092I~
//******************                                               //~v092I~
//  return umemmem(Pbuff,Pkey,Plen,strlen(Pkey));                  //~v092I~//~v6BxR~
    return umemmem(Pbuff,Pkey,Plen,(UINT)strlen(Pkey));            //~v6BxI~
}//umemstr                                                         //~v092I~
                                                                   //~v092I~
//*******************************************************          //~v092I~
//*umemstri                                                        //~v092I~
//* search string parm2 on mem parm1                               //~v092I~
//* parm1 :mem                                                     //~v092I~
//* parm2 :search key string case insensitiv                       //~v092I~
//* parm3 :parm1 len                                               //~v092I~
//* return:pointer to mem on parm1,or NULL if not found            //~v092I~
//*        return top addr if parm2 len=0                          //~v092I~
//******************************************************           //~v092I~
char *umemstri(char *Pbuff,char *Pkey,unsigned int Plen)           //~v092I~
{                                                                  //~v092I~
//******************                                               //~v092I~
//  return umemmemi(Pbuff,Pkey,Plen,strlen(Pkey));                 //~v092I~//~v6BxR~
    return umemmemi(Pbuff,Pkey,Plen,(UINT)strlen(Pkey));           //~v6BxI~
}//umemstri                                                        //~v092I~
                                                                   //~v092I~
//*******************************************************          //~v092I~
//*umemrstr                                                        //~v092I~
//* search string parm2 on mem parm1                               //~v092I~
//* parm1 :mem                                                     //~v092I~
//* parm2 :search key string case sensitive from last              //~v092I~
//* parm3 :parm1 len                                               //~v092I~
//* return:pointer to mem on parm1,or NULL if not found            //~v092I~
//*        return top addr if parm2 len=0                          //~v092I~
//******************************************************           //~v092I~
char *umemrstr(char *Pbuff,char *Pkey,unsigned int Plen)           //~v092I~
{                                                                  //~v092I~
//******************                                               //~v092I~
//  return umemrmem(Pbuff,Pkey,Plen,strlen(Pkey));                 //~v092I~//~v6BxR~
    return umemrmem(Pbuff,Pkey,Plen,(UINT)strlen(Pkey));           //~v6BxI~
}//umemrstr                                                        //~v093R~
                                                                   //~v092I~
//*******************************************************          //~v092I~
//*umemrstri                                                       //~v092I~
//* search string parm2 on mem parm1                               //~v092I~
//* parm1 :mem                                                     //~v092I~
//* parm2 :search key string case insensitiv from last             //~v092I~
//* parm3 :parm1 len                                               //~v092I~
//* return:pointer to mem on parm1,or NULL if not found            //~v092I~
//*        return top addr if parm2 len=0                          //~v092I~
//******************************************************           //~v092I~
char *umemrstri(char *Pbuff,char *Pkey,unsigned int Plen)          //~v092I~
{                                                                  //~v092I~
//******************                                               //~v092I~
//  return umemrmemi(Pbuff,Pkey,Plen,strlen(Pkey));                //~v092I~//~v6BxR~
    return umemrmemi(Pbuff,Pkey,Plen,(UINT)strlen(Pkey));          //~v6BxI~
}//umemrstri                                                       //~v092I~
                                                                   //~v092I~
//*******************************************************          //~v092I~
//*umemmem                                                         //~v092I~
//* search mem parm2 on mem parm1                                  //~v092I~
//* parm1 :mem                                                     //~v092I~
//* parm2 :search key case sensitive                               //~v092I~
//* parm3 :parm1 len                                               //~v092I~
//* parm4 :parm2 len                                               //~v092I~
//* return:pointer to mem on parm1,or NULL if not found            //~v092I~
//*        return top addr if parm2 len=0                          //~v092I~
//******************************************************           //~v092I~
char *umemmem(char *Pbuff,char *Pkey,unsigned int Plen,unsigned int Plenk)//~v092I~
{                                                                  //~v092I~
	char *pc,*pce,top;                                             //~v092R~
	unsigned int len;                                              //~v092I~
//******************                                               //~v092I~
	if (!Plenk)                                                    //~v092I~
		return Pbuff;                                              //~v092I~
	top=*Pkey;                                                     //~v092I~
    pc=Pbuff;                                                      //~v092R~
    pce=Pbuff+Plen;                                                //~v092I~
    for (;;)                                                       //~v092R~
    {                                                              //~v092I~
//      len=((ULONG)pce-(ULONG)pc);                                //~v092I~//~v6hhR~
//      len=((ULPTR)pce-(ULPTR)pc);                                //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	pc=memchr(pc,top,len);                                     //~v092R~
        if (!pc)                                                   //~v092I~
        	break;                                                 //~v092I~
		if (pc+Plenk>pce)                                          //~v092R~
            return 0;                                              //~v092I~
		if (!memcmp(pc,Pkey,Plenk))                                //~v093R~
        	break;                                                 //~v092R~
    	pc++;                                                      //~v092I~
	}                                                              //~v092I~
	return pc;                                                     //~v092R~
}//umemmem                                                         //~v092I~
                                                                   //~v092I~
//*******************************************************          //~v092I~
//*umemmemi                                                        //~v092I~
//* search parm2 string on parm1 storage                           //~v092I~
//* parm1 :mem                                                     //~v092I~
//* parm2 :search key case insensitive                             //~v092I~
//* parm3 :parm1 len                                               //~v092I~
//* parm4 :parm2 len                                               //~v092I~
//* return:pointer to mem on parm1,or NULL if not found            //~v092I~
//*        return top addr if parm2 len=0                          //~v092I~
//******************************************************           //~v092I~
char *umemmemi(char *Pbuff,char *Pkey,unsigned int Plen,unsigned int Plenk)//~v092I~
{                                                                  //~v092I~
	unsigned char *pc,*pce,topl,topu,*pcu;                         //~v092R~
	unsigned int len;                                              //~v092I~
//******************                                               //~v092I~
	if (!Plenk)                                                    //~v092I~
		return Pbuff;                                              //~v092I~
	topu=(UCHAR)toupper((int)*Pkey);                               //~v092I~
	topl=(UCHAR)tolower((int)*Pkey);                               //~v092I~
    pce=Pbuff+Plen;                                                //~v092I~
    pc=Pbuff;                                                      //~v092I~
//search by upper                                                  //~v092I~
    for (;;)                                                       //~v092I~
    {                                                              //~v092I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~v092I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,topu,len),!pc)                            //~v092R~
	    	break;                                                 //~v092I~
        if (pc+Plenk>pce)                                          //~v092R~
        {                                                          //~v092I~
            pc=0;                                                  //~v092I~
            break;                                                 //~v092I~
        }                                                          //~v092I~
		if (!memicmp(pc,Pkey,Plenk))	//found                    //~v092I~
	    	break;                                                 //~v092I~
    	pc++;                                                      //~v092I~
	}                                                              //~v092I~
//serach by lower                                                  //~v092I~
	pcu=pc;                                                        //~v092I~
    if (topu==topl)     //top is case insensitive                  //~v292I~
        return pcu;     //not required by lower case               //~v292I~
	if (pcu)				//found                                //~v092I~
    	pce=pcu+Plenk;                                             //~v092I~
    pc=Pbuff;                                                      //~v092R~
    for (;;)                                                       //~v092I~
    {                                                              //~v092I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~v092I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,topl,len),!pc)                            //~v092R~
	    	break;                                                 //~v092I~
    	if (pc+Plenk>pce)                                          //~v092R~
        {                                                          //~v092I~
            pc=0;                                                  //~v092I~
        	break;                                                 //~v092I~
        }                                                          //~v092I~
		if (!memicmp(pc,Pkey,Plenk))                               //~v092I~
        	break;                                                 //~v092I~
    	pc++;                                                      //~v092I~
	}                                                              //~v092I~
    if (pc)                                                        //~v092I~
    	return pc;                                                 //~v092I~
	else                                                           //~v092I~
    	return pcu;                                                //~v092I~
}//umemmemi                                                        //~v092I~
                                                                   //~v092I~
//*******************************************************          //~v092I~
//*umemrmem                                                        //~v092I~
//* search mem parm2 on mem parm1                                  //~v092I~
//* parm1 :mem                                                     //~v092I~
//* parm2 :search key case sensitive reverse search                //~v092I~
//* parm3 :parm1 len                                               //~v092I~
//* parm4 :parm2 len                                               //~v092I~
//* return:pointer to mem on parm1,or NULL if not found            //~v092I~
//*        return top addr if parm2 len=0                          //~v092I~
//******************************************************           //~v092I~
char *umemrmem(char *Pbuff,char *Pkey,unsigned int Plen,unsigned int Plenk)//~v092I~
{                                                                  //~v092I~
	char *pc,*pce,*pcl,top;                                        //~v092R~
	unsigned int len;                                              //~v092I~
//******************                                               //~v092I~
	if (!Plenk)                                                    //~v092I~
		return Pbuff;                                              //~v092I~
	top=*Pkey;                                                     //~v092I~
    pc=Pbuff;                                                      //~v092R~
    pce=Pbuff+Plen;                                                //~v092I~
    pcl=0;				//last found                               //~v092R~
    for (;;)                                                       //~v092R~
    {                                                              //~v092I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~v092I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	pc=memchr(pc,top,len);                                     //~v092R~
        if (!pc)                                                   //~v092I~
        	break;                                                 //~v092I~
		if (pc+Plenk>pce)                                          //~v092R~
        	break;                                                 //~v092I~
		if (!memcmp(pc,Pkey,Plenk))                                //~v093R~
        	pcl=pc;                                                //~v092I~
    	pc++;                                                      //~v092I~
	}                                                              //~v092I~
	return pcl;                                                    //~v092I~
}//umemrmem                                                        //~v093R~
                                                                   //~v092I~
//*******************************************************          //~v092I~
//*umemrmemi                                                       //~v092I~
//* search parm2 string on parm1 storage                           //~v092I~
//* parm1 :mem                                                     //~v092I~
//* parm2 :search key case insensitive reverse search              //~v092I~
//* parm3 :parm1 len                                               //~v092I~
//* parm4 :parm2 len                                               //~v092I~
//* return:pointer to mem on parm1,or NULL if not found            //~v092I~
//*        return top addr if parm2 len=0                          //~v092I~
//******************************************************           //~v092I~
char *umemrmemi(char *Pbuff,char *Pkey,unsigned int Plen,unsigned int Plenk)//~v092I~
{                                                                  //~v092I~
	unsigned char *pc,*pce,*pcl,topl,topu;                         //~v092R~
	unsigned int len;                                              //~v092I~
//******************                                               //~v092I~
	if (!Plenk)                                                    //~v092I~
		return Pbuff;                                              //~v092I~
	topu=(UCHAR)toupper((int)*Pkey);                               //~v092I~
	topl=(UCHAR)tolower((int)*Pkey);                               //~v092I~
    pc=Pbuff;                                                      //~v092I~
    pce=Pbuff+Plen;                                                //~v092I~
    pcl=0;                                                         //~v092I~
//search by upper                                                  //~v092I~
    for (;;)                                                       //~v092R~
    {                                                              //~v092I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~v092I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,topu,len),!pc)                            //~v092R~
	       	break;                                                 //~v092R~
		if (pc+Plenk>pce)                                          //~v092R~
        	break;                                                 //~v092I~
		if (!memicmp(pc,Pkey,Plenk))                               //~v093R~
        	pcl=pc;                                                //~v092I~
    	pc++;                                                      //~v092I~
	}                                                              //~v092I~
//serach by lower                                                  //~v092I~
    if (topu==topl)     //top is case insensitive                  //~v292I~
        return pcl;     //not required by lower case               //~v292I~
	if (pcl)                                                       //~v092I~
    	pc=pcl+1;                                                  //~v092R~
    else                                                           //~v092I~
        pc=Pbuff;                                                  //~v092I~
    for (;;)                                                       //~v092R~
    {                                                              //~v092I~
//      len=(ULONG)pce-(ULONG)pc;                                  //~v092I~//~v6hhR~
//      len=(ULPTR)pce-(ULPTR)pc;                                  //~v6hhI~//~v6BxR~
        len=(UINT)PTRDIFF(pce,pc);                                 //~v6BxI~
    	if (pc=memchr(pc,topl,len),!pc)                            //~v092R~
	    	break;                                                 //~v092R~
		if (pc+Plenk>pce)                                          //~v092R~
	    	break;                                                 //~v092I~
		if (!memicmp(pc,Pkey,Plenk))                               //~v092I~
        	pcl=pc;                                                //~v092I~
    	pc++;                                                      //~v092I~
	}                                                              //~v092I~
	return pcl;                                                    //~v092I~
}//umemrmemi                                                       //~v092I~
                                                                   //~v092I~
//*******************************************************          //~v111I~
//*ustrncpyz                                                       //~v111I~
//* strncpy +(1) last null is gualantied (2) only one null is added//~v111I~
//* parm1 :target                                                  //~v111I~
//* parm2 :source                                                  //~v111I~
//* parm3 :targetlen                                               //~v111I~
//* return:target ptr                                              //~v111I~
//******************************************************           //~v111I~
char *ustrncpyz(char *Ptarget,char *Psource,unsigned int Plen)     //~v111I~
{                                                                  //~v111I~
	unsigned int len;                                              //~v111I~
//******************                                               //~v111I~
	if ((int)Plen<=0)                                              //~v5fkR~
    	return Ptarget;                                            //~v111I~
//  len=strlen(Psource);                                           //~v111I~//~v6BxR~
    len=(UINT)strlen(Psource);                                     //~v6BxI~
    if (len>=Plen)                                                 //~v111I~
    {                                                              //~v111I~
    	memcpy(Ptarget,Psource,Plen-1);		//for last null        //~v111I~
        *(Ptarget+Plen-1)=0;                                       //~v111I~
	}                                                              //~v111I~
    else                                                           //~v111I~
    	memcpy(Ptarget,Psource,len+1);		//with last null       //~v111I~
	return Psource;                                                //~v111I~
}//ustrncpyz                                                       //~v111I~
//*******************************************************          //~v5m6I~
//*uispunct                                                        //~v5m6I~
//*ispunct effected by setlocale. optionaly accept it?             //~v5m6I~
//* return:target ptr                                              //~v5m6I~
//******************************************************           //~v5m6I~
int uispunct(int Popt,int Pch)                                     //~v5m6I~
{                                                                  //~v5m6I~
#define UISP_NOPUNC "@_$"                                          //~v5m6I~
//******************                                               //~v5m6I~
	if (Pch==' ')                                                  //~v5m6I~
    	return 1;                                                  //~v5m6I~
	if (!(Popt & UISP_ACCEPT_LOCALE))       //chk also non ASCII(>=128)//~v5m6I~
    {                                                              //~v5m6I~
    	if (Pch>127)                                               //~v5m6I~
        	return 0;                                              //~v5m6I~
    }                                                              //~v5m6I~
    if (!ispunct(Pch))                                             //~v5m6I~
    	return 0;                                                  //~v5m6I~
	if ((Popt & UISP_NON_C))               //treat @_$ as punct    //~v5m6R~
    	return 1;                                                  //~v5m6I~
	if (strchr(UISP_NOPUNC,Pch))                                   //~v5m6I~
    	return 0;                                                  //~v5m6I~
    return 1;                                                      //~v5m6I~
}//uispunct                                                        //~v5m6I~
//*******************************************************          //~v62pI~
//*uispunct                                                        //~v62pI~
//*ispunct effected by setlocale. optionaly accept it?             //~v62pI~
//* return:target ptr                                              //~v62pI~
//******************************************************           //~v62pI~
int uispunctdbcs(int Popt,char *Pdata)                             //~v62pI~
{                                                                  //~v62pI~
#define UISP_NOPUNCDBCS "ÅóÅQÅê"                                   //~v62pI~
#define PUNCDBCSTBSZ 		(sizeof(Spunctdbcs_sjis)-1)            //~v62pR~
static char Spunctdbcs_sjis[]="Å@"/*dbcs space*/ UISP_NOPUNCDBCS "ÅIÅgÅhÅîÅìÅïÅfÅiÅjÅñÅ{ÅAÅ|ÅBÅEÅFÅGÅÉÅÅÅÑÅHÅuÅèÅvÅOÅeÅfÅoÅbÅpÅ`ÅCÅDÅsÅtÅwÅx";//~v62pR~
static char Spunctdbcs_euc[PUNCDBCSTBSZ]={0xa1,0xa1};  //dbcs space by EUC japanese//~v62pR~
#ifdef UTF8UCS2                                                    //~v62UI~
static USHORT Spunctdbcs_ucs2[]={                                  //~v62UI~
    0x3000, 0xFF20, 0xFF3F, 0xFF04, 0xFF01, 0x201C, 0x201D, 0xFF03,//~v62UI~
//    space   @       _       $       !       "L      "R      #    //~v62UI~
                                                                   //~v62UI~
    0xFF05, 0xFF06, 0x201b, 0xFF08, 0xFF09, 0xFF0A, 0xFF0B, 0x3001, 0x2212,//~v62UR~
//    %       &     'apost    (       )       *       +       ,       -//~v62UR~
                                                                   //~v62UI~
    0x3002, 0x30FB, 0xFF1A, 0xFF1B, 0xFF1C, 0xFF1D, 0xFF1E, 0xFF1F,//~v62UI~
//    .maru   center  :       ;       <       =       >       ?    //~v62UI~
                                                                   //~v62UI~
    0x300C, 0xFFE5, 0x300D, 0xFF3E, 0x2018, 0x2019, 0xFF5B, 0xFF5C,//~v62UI~
//    kagiL   \       kagiR   ^       'L      'R      {       |    //~v62UI~
                                                                   //~v62UI~
    0xFF5D, 0x301C, 0xFF0C, 0xFF0E, 0x300A, 0x300B, 0x300E, 0x300F,//~v62UI~
//    }       wave    ,       .       <<      >>      kagiDL  kagiDR//~v62UI~
                                                                   //~v62UI~
								};                                 //~v62UI~
#define PUNCUCSTBSZ 		(sizeof(Spunctdbcs_ucs2))              //~v62UR~
	USHORT ucs,*pucs;                                              //~v62UI~
#endif                                                             //~v62UI~
	char *ppuncdbcs;                                               //~v62pI~
    int ii,dbcscnt;                                                //~v62pR~
    char *pc;                                                      //~v62pI~
#ifdef LNX                                                         //~v62pI~
	char eucdbcswk[PUNCDBCSTBSZ];                                  //~v62pR~
    int euclen;                                                    //~v62pI~
#endif                                                             //~v62pI~
//******************                                               //~v62pI~
#ifdef UTF8UCS2	                                                   //~v62UI~
  if (Popt & UISP_UCS2)                                            //~v62UI~
  {                                                                //~v62UI~
//	ucs=(*Pdata<<8)+(*(Pdata+1)&0xff);                             //~v62UI~//~v6BkR~
  	ucs=(USHORT)((*Pdata<<8)+(*(Pdata+1)&0xff));                   //~v6BkI~
    dbcscnt=PUNCUCSTBSZ/2;                                         //~v62UI~
    for (ii=0,pucs=Spunctdbcs_ucs2;ii<dbcscnt;ii++,pucs++)         //~v62UR~
		if (ucs==*pucs)                                            //~v62UR~
        	break;                                                 //~v62UI~
  }                                                                //~v62UI~
  else                                                             //~v62UI~
#endif                                                             //~v62UI~//~v63dM~
  {                                                                //~v62UI~
#ifdef LNX                                                         //~v62pI~
	if (udbcschk(*Spunctdbcs_euc))                                 //~v62pI~
    {                                                              //~v62pI~
		if (!Spunctdbcs_euc[2])	//1st time                         //~v62pI~
        {                                                          //~v62pI~
			ushift2euc(Spunctdbcs_sjis,0/*sjis dbcstbl*/,PUNCDBCSTBSZ,//~v62pR~
						Spunctdbcs_euc,eucdbcswk,&euclen,0/*opt*/);//~v62pI~
    	}                                                          //~v62pR~
	    ppuncdbcs=Spunctdbcs_euc;                                  //~v62pI~
    }                                                              //~v62pI~
    else                                                           //~v62pI~
    	return 0;                                                  //~v62pI~
#else                                                              //~v62pI~
	if (!udbcschk(*Spunctdbcs_sjis))                               //~v62pI~
    	return 0;                                                  //~v62pI~
    ppuncdbcs=Spunctdbcs_sjis;                                     //~v62pI~
#endif                                                             //~v62pI~
    dbcscnt=PUNCDBCSTBSZ/2;                                        //~v62pI~
    for (ii=0,pc=ppuncdbcs;ii<dbcscnt;ii++,pc+=2)                  //~v62pR~
		if (*pc==*Pdata && *(pc+1)==*(Pdata+1))                    //~v62pR~
        	break;                                                 //~v62pI~
  }                                                                //~v62UI~
    if (ii==dbcscnt)                                               //~v62pR~
    	return 0;                                                  //~v62pI~
	if ((Popt & UISP_NON_C))               //treat @_$ as punct    //~v62pI~
    	return 1;                                                  //~v62pI~
	if (ii>=1 && ii<=(sizeof(UISP_NOPUNCDBCS))/2)                  //~v62pR~
    	return 0;                                                  //~v62pI~
    return 1;                                                      //~v62pI~
}//uispunctdbcs                                                    //~v62pI~
//*******************************************************          //~v5m8I~
//*ustrdup                                                         //~v5m8I~
//*  using umalloc,set always last null                            //~v5m8R~
//******************************************************           //~v5m8I~
char *ustrdup(int Popt,char *Pstr,int Plen)                        //~v5m8R~
{                                                                  //~v5m8I~
    int len;                                                       //~v5m8I~
    char *pc;                                                      //~v5m8I~
//******************                                               //~v5m8I~
	if (Plen>0)                                                    //~v5m8I~
    {                                                              //~v5m8I~
        pc=umalloc((UINT)(Plen+1));                                //~v5m8R~
        if (!pc)                                                   //~v5m8I~
        	return 0;                                              //~v5m8I~
        strncpy(pc,Pstr,(UINT)Plen);                               //~v5m8R~
        *(pc+Plen)=0;                                              //~v5m8R~
    }                                                              //~v5m8I~
    else                                                           //~v5m8I~
    {                                                              //~v5m8I~
	    len=(int)strlen(Pstr);                                     //~v5m8R~
        pc=umalloc((UINT)(len+1));                                 //~v5m8I~
        if (!pc)                                                   //~v5m8I~
        	return 0;                                              //~v5m8I~
        strcpy(pc,Pstr);                                           //~v5m8I~
    }                                                              //~v5m8I~
    return pc;                                                     //~v5m8I~
}//ustrdup                                                         //~v5m8I~
//*******************************************************          //~v5mpI~
//*umemtrim                                                        //~v5mpI~
//*  mem cut by a char                                             //~v5mpI~
//******************************************************           //~v5mpI~
char *umemtrim(int Popt,char *Pmem,int Plen,char Pch,char *Pout,int *Ppoutlen)//~v5mpI~
{                                                                  //~v5mpI~
	char *pc;                                                      //~v5mpI~
    int len;                                                       //~v5mpI~
    int headctr;                                                   //~v668I~
	char *pce;                                                     //~v669R~
    int ch;                                                        //~v669R~
//******************                                               //~v5mpI~
  if (Popt & UMTO_ASCII)                                           //~v669I~
  {                                                                //~v669I~
    for (pc=Pmem,pce=pc+Plen;pc<pce;pc++)                          //~v669I~
    {	                                                           //~v669I~
    	ch=*pc;                                                    //~v669I~
        if (!UTF8ISASCII(ch))                                      //~v669I~
        	break;                                                 //~v669I~
    }                                                              //~v669I~
    if (pc<pce)                                                    //~v669I~
    {                                                              //~v669I~
	    Pmem=pc;    //strat addr                                   //~v669I~
    	for (pc=pce-1;pc>Pmem;pc--)                                //~v669I~
    	{                                                          //~v669I~
    		ch=*pc;                                                //~v669I~
        	if (!UTF8ISASCII(ch))                                  //~v669I~
        		break;                                             //~v669I~
    	}                                                          //~v669I~
//      len=(int)((ULONG)pc-(ULONG)Pmem)+1;                        //~v669I~//~v6hhR~
      len=(int)((ULPTR)pc-(ULPTR)Pmem)+1;                          //~v6hhI~
    }                                                              //~v669I~
    else                                                           //~v669I~
    	len=0;                                                     //~v669I~
  }                                                                //~v669I~
  else                                                             //~v669I~
  {                                                                //~v669I~
	if (Popt & UMTO_1ST)                                           //~v5mpI~
    {                                                              //~v5mpI~
        pc=memchr(Pmem,Pch,(UINT)Plen);                            //~v5mpI~
        if (!pc)                                                   //~v5mpI~
            len=Plen;                                              //~v5mpI~
        else                                                       //~v5mpI~
//          len=(int)((ULONG)pc-(ULONG)Pmem);                      //~v5mpI~//~v6hhR~
            len=(int)((ULPTR)pc-(ULPTR)Pmem);                      //~v6hhI~
    }                                                              //~v5mpI~
    else                                                           //~v5mpI~
    {                                                              //~v5mpI~
	    if (Popt & UMTO_HEAD)                                      //~v668I~
        {                                                          //~v668I~
//        	headctr=umemspnc(Pmem,Pch,(UINT)Plen);                 //~v668R~//~v6BkR~
          	headctr=(int)umemspnc(Pmem,Pch,(UINT)Plen);            //~v6BkI~
            Pmem+=headctr;                                         //~v668I~
            Plen-=headctr;                                         //~v668I~
        }                                                          //~v668I~
        len=Plen-(int)umemrspnc(Pmem,Pch,(UINT)Plen);              //~v5mpR~
    }                                                              //~v5mpI~
  }//!ascii                                                        //~v669I~
  if (!(Popt & UMTO_NOCOPY))                                       //~v668I~
  {                                                                //~v668I~
    memcpy(Pout,Pmem,(UINT)len);                                   //~v5mpI~
    *(Pout+len)=0;                                                 //~v5mpI~
  }                                                                //~v668I~
    if (Ppoutlen)                                                  //~v5mpI~
        *Ppoutlen=len;                                             //~v5mpI~
  	if (Popt & UMTO_NOCOPY)                                        //~v668I~
    	return Pmem;                                               //~v668I~
    return Pout;                                                   //~v5mpI~
}//umemtrim                                                        //~v5mpI~
//***************************************************************  //~v65hI~
//* memicmp avoid dbcs partialy match upper/lower                  //~v65hI~
//* rc:0 unmatch,1:match                                           //~v65hI~
//***************************************************************  //~v65hI~
int umemicmpdbcs(int Popt,char *Pdata,char *Pdbcs,char* Pcmp,int Plen)//~v65hI~
{                                                                  //~v65hI~
	char *pcd,*pc,*pcmp;                                           //~v65hR~
    int ii;                                                        //~v65hI~
//**********************                                           //~v65hI~
    for (ii=0,pc=Pdata,pcd=Pdbcs,pcmp=Pcmp;ii<Plen;ii++,pc++,pcd++,pcmp++)//~v65hI~
    {                                                              //~v65hI~
        if (*pc==*pcmp)                                            //~v65hI~
        	continue;                                              //~v65hI~
        if (!*pcd && toupper(*pc)==toupper(*pcmp))//not dbcs, icase match//~v65hI~
        	continue;                                              //~v65hI~
        return 0;                                                  //~v65hI~
    }                                                              //~v65hI~
    return 1;                                                      //~v65hI~
}//umemicmpdbcs                                                    //~v65hI~
//***************************************************************  //~v65hI~
//* icase search string avoiding dbcs partialy match upper/lower   //~v65hI~
//* return addr                                                    //~v65hI~
//***************************************************************  //~v65hI~
char *umemstridbcs(int Popt,char *Pdata,char *Pdbcs,char* Pkey,int Plen)//~v65hR~
{                                                                  //~v65hI~
	char *pc2,*pcd,*pc;                                            //~v65hR~
    int reslen,keylen,offs;                                        //~v65hR~
//**********************                                           //~v65hI~
//  keylen=strlen(Pkey);                                           //~v65hI~//~v6BkR~
    keylen=(int)strlen(Pkey);                                      //~v6BkI~
    for (pc=Pdata,reslen=Plen;reslen>=keylen;)                     //~v65hR~
    {                                                              //~v65hI~
//  	pc2=umemmemi(pc,Pkey,reslen,keylen);                       //~v65hI~//~v6BkR~
    	pc2=umemmemi(pc,Pkey,(UINT)reslen,(UINT)keylen);           //~v6BkI~
        if (!pc2)                                                  //~v65hI~
        	return 0;                                              //~v65hI~
//      offs=(ULONG)pc2-(ULONG)Pdata;                              //~v65hR~//~v6hhR~
//      offs=(ULPTR)pc2-(ULPTR)Pdata;                              //~v6hhI~//~v6BkR~
        offs=PTRDIFF(pc2,Pdata);                                   //~v6BkI~
		if (Popt & UMSIDO_KEYDBCS)   //dbcs is of key              //~v65hI~
		    pcd=Pdbcs;                                             //~v65hI~
        else                                                       //~v65hI~
        	pcd=Pdbcs+offs;                                        //~v65hI~
		if (umemicmpdbcs(0,pc2,pcd,Pkey,keylen))//icase match except DBCS//~v65hI~
        	return pc2;                                            //~v65hI~
        pc=Pdata+offs+1;                                           //~v65hI~
        reslen=Plen-offs-1;                                        //~v65hI~
    }                                                              //~v65hI~
    return 0;                                                      //~v65hI~
}//umemstridbcs                                                    //~v65hI~
//***************************************************************  //~v65hI~
//* reverse icase search string avoiding dbcs partialy match upper/lower//~v65hI~
//* return addr                                                    //~v65hI~
//***************************************************************  //~v65hI~
char *umemrstridbcs(int Popt,char *Pdata,char *Pdbcs,char* Pkey,int Plen)//~v65hI~
{                                                                  //~v65hI~
	char *pcd,*pc;                                                 //~v65hI~
    int reslen,keylen;                                             //~v65hI~
//**********************                                           //~v65hI~
//  keylen=strlen(Pkey);                                           //~v65hI~//~v6BkR~
    keylen=(int)strlen(Pkey);                                      //~v6BkI~
    for (reslen=Plen;reslen>=keylen;)                              //~v65hI~
    {                                                              //~v65hI~
//  	pc=umemrmemi(Pdata,Pkey,reslen,keylen);                    //~v65hI~//~v6BkR~
    	pc=umemrmemi(Pdata,Pkey,(UINT)reslen,(UINT)keylen);        //~v6BkI~
        if (!pc)                                                   //~v65hI~
        	return 0;                                              //~v65hI~
//      reslen=(ULONG)pc-(ULONG)Pdata;                             //~v65hI~//~v6hhR~
//      reslen=(ULPTR)pc-(ULPTR)Pdata;                             //~v6hhI~//~v6BkR~
        reslen=PTRDIFF(pc,Pdata);                                  //~v6BkI~
		if (Popt & UMRSIDO_KEYDBCS)   //dbcs is of key             //~v65hI~
        	pcd=Pdbcs;                                             //~v65hI~
        else                                                       //~v65hI~
        	pcd=Pdbcs+reslen;                                      //~v65hR~
		if (umemicmpdbcs(0,pc,pcd,Pkey,keylen))//icase match except DBCS//~v65hI~
        	return pc;                                             //~v65hI~
        reslen+=keylen-1;                                          //~v65hI~
    }                                                              //~v65hI~
    return 0;                                                      //~v65hI~
}//umemrstridbcs                                                   //~v65hR~
