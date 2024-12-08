//*CID://+v6K9R~: updat#    110;                                   //+v6K9R~
//*************************************************************
//v6K9:170401 large memcpy faile by LENCHK(max 1MB), enlarge to 1GB(MAX_MALLOC at ualloc.c)//+v6K9I~
//            ustrcpy.c                                            //+v6K9I~
//v6n1:130905 memcpy implementation of suse12.3(err if region overlap)(also for Windows spec)//~v6n1I~
//*************************************************************    //~v6n1M~
//************************************************************* //~5307I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*******************************************************
#include <ulib.h>
#include <uerr.h>                                                  //~v6n1I~
#include <utrace.h>                                                //~v6n1I~
//*******************************************************       //~4C19I~
//#define LENCHK_SHIFT   20 // 20 bit shift : 0xfff00000     //max length<1MB//~v6n1I~//+v6K9R~
#define LENCHK_SHIFT   30 // 30 bit shift : 0xc0000000     //max length<1GB//+v6K9I~
//***************************************************************  //~v6n1I~
//redirect memcpy to memmove if ovrlap                             //~v6n1I~
//***************************************************************  //~v6n1I~
void *ustring_memcpy(void *Ptgt,const void *Psrc,size_t Plen)      //~v6n1R~
{                                                                  //~v6n1I~
	char *pte,*pse;                                                //~v6n1I~
//*****************************                                    //~v6n1I~
	if (Plen>>LENCHK_SHIFT)                                        //~v6n1I~
    	uerrexit("ustring_memcpy invalid length parameter;tgt=%p,src=%p,len=%x",0,//~v6n1I~
        		Ptgt,Psrc,Plen);                                   //~v6n1I~
	pse=(char*)Psrc+Plen;	//src end                              //~v6n1I~
	pte=(char*)Ptgt+Plen;	//target end                           //~v6n1I~
	if (pte<=(char*)Psrc || pse<=(char*)Ptgt)	//no overlap       //~v6n1R~
    {                                                              //~v6n1I~
#ifdef PUSH_MEMCPY                                                 //~v6n1I~
	#pragma pop_macro("memcpy")                                    //~v6n1R~
#else                                                              //~v6n1I~
	#undef memcpy	                                               //~v6n1I~
#endif                                                             //~v6n1I~
    	memcpy(Ptgt,Psrc,Plen);                                    //~v6n1I~
//  	UTRACEP("ustring_memcpy:memcpy  tgt=%p,src=%p,len=0x%x\n",Ptgt,Psrc,Plen);//~v6n1R~
    }                                                              //~v6n1I~
    else                                                           //~v6n1I~
    {                                                              //~v6n1I~
    	memmove(Ptgt,Psrc,Plen);                                   //~v6n1I~
    	UTRACEP("ustring_memcpy:memmove tgt=%p,src=%p,len=0x%x\n",Ptgt,Psrc,Plen);//~v6n1R~
    }                                                              //~v6n1I~
    return Ptgt;                                                   //~v6n1I~
}//usring_memcpy                                                   //~v6n1R~
//***************************************************************  //~v6n1I~
//redirect strncpy to memmove if ovrlap                            //~v6n1I~
//***************************************************************  //~v6n1I~
char *ustring_strncpy(char *Ptgt,const char *Psrc,size_t Plen)     //~v6n1R~
{                                                                  //~v6n1I~
	char *pte;                                                     //~v6n1R~
	const char *pse;                                               //~v6n1I~
    size_t lensrc,lencpy;                                          //~v6n1I~
//*****************************                                    //~v6n1I~
	if (Plen>>LENCHK_SHIFT)                                        //~v6n1I~
    	uerrexit("ustring_strncpy invalid length parameter;tgt=%p,src=%p,len=%x",0,//~v6n1I~
        		Ptgt,Psrc,Plen);                                   //~v6n1I~
	pse=Psrc+Plen;	//src end                                      //~v6n1R~
	pte=Ptgt+Plen;	//target end                                   //~v6n1R~
	if (pte<=Psrc || pse<=Ptgt)	//no overlap                       //~v6n1R~
    {                                                              //~v6n1I~
#ifdef PUSH_STRNCPY                                                //~v6n1I~
	#pragma pop_macro("strncpy")                                   //~v6n1I~
#else                                                              //~v6n1I~
	#undef strncpy                                                 //~v6n1I~
#endif                                                             //~v6n1I~
    	strncpy(Ptgt,Psrc,Plen);                                   //~v6n1I~
//  	UTRACEP("ustring_strncpy:strncpy tgt=%p,src=%p,len=0x%x\n",Ptgt,Psrc,Plen);//~v6n1I~
    }                                                              //~v6n1I~
    else                                                           //~v6n1I~
    {                                                              //~v6n1I~
    	lensrc=strlen(Psrc);                                       //~v6n1I~
        if (lensrc<Plen)                                           //~v6n1I~
        	lencpy=lensrc;                                         //~v6n1I~
        else                                                       //~v6n1I~
        	lencpy=Plen;                                           //~v6n1I~
    	memmove(Ptgt,Psrc,lencpy);                                 //~v6n1I~
        if (lensrc<Plen)                                           //~v6n1I~
        	memset(Ptgt+lensrc,0,Plen-lensrc);                     //~v6n1I~
    	UTRACEP("ustring_strncpy:memmove tgt=%p,src=%p,len=0x%x\n",Ptgt,Psrc,Plen);//~v6n1I~
    }                                                              //~v6n1I~
    return Ptgt;                                                   //~v6n1R~
}//usring_strncpy                                                  //~v6n1I~
//***************************************************************  //~v6n1I~
//redirect strcpy to memmove if ovrlap                             //~v6n1I~
//***************************************************************  //~v6n1I~
char *ustring_strcpy(char *Ptgt,const char *Psrc)                  //~v6n1R~
{                                                                  //~v6n1I~
	char *pte;                                                     //~v6n1R~
	const char *pse;                                               //~v6n1I~
    size_t lensrc;                                                 //~v6n1I~
//*****************************                                    //~v6n1I~
    lensrc=strlen(Psrc)+1;                                         //~v6n1I~
	pse=Psrc+lensrc; //src end                                     //~v6n1R~
	pte=Ptgt+lensrc; //target end                                  //~v6n1R~
	if (pte<=Psrc || pse<=Ptgt)	//no overlap                       //~v6n1R~
    {                                                              //~v6n1I~
#ifdef PUSH_STRCPY                                                 //~v6n1I~
	#pragma pop_macro("strcpy")                                    //~v6n1I~
#else                                                              //~v6n1I~
	#undef strcpy                                                  //~v6n1I~
#endif                                                             //~v6n1I~
    	strcpy(Ptgt,Psrc);                                         //~v6n1I~
//  	UTRACEP("ustring_strncpy:strcpy  tgt=%p,src=%p,len=0x%x\n",Ptgt,Psrc,lensrc);//~v6n1R~
    }                                                              //~v6n1I~
    else                                                           //~v6n1I~
    {                                                              //~v6n1I~
    	memmove(Ptgt,Psrc,lensrc);                                 //~v6n1I~
    	UTRACEP("ustring_strcpy:memmove tgt=%p,src=%p,len=0x%x\n",Ptgt,Psrc,lensrc);//~v6n1R~
    }                                                              //~v6n1I~
    return Ptgt;                                                   //~v6n1R~
}//usring_strcpy                                                   //~v6n1I~
