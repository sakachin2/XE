//CID://+v7c5R~:         update#=     22                           //+v7c5R~
//*******************************************************
//*ustring.h
//*******************************************************
//v7c5:240620 add ustrnspnc, it use strspn and suppors null char length//+v7c5I~
//v70a:200616 ARM:sprintf chk wariable boundary by __vsprintf_chk and signal(6):abort//~v6J0I~
//v6J0:170205 malloc udirlist filename to  allow more large number of fine in the dir//~v6J0I~
//v6H3:170105 (BUG)crash when too long name;it should chk strlen   //~v6H3I~
//v6D0:160408 LNX compiler warning                                 //~v6D0I~
//v6x6:150108 add USTRHEADIS_STR,USTRHEADIS_IC_STR                 //~v6x6I~
//v6hE:120906 add USKIP_SPACETAB/USRCH_SPACETAB                    //~v6hEI~
//v6hD:120906 add umemspn_spacetab                                 //~v6hDI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v6d2:120203 add USR_MINPTR,USTR_MAXPTR                           //~v6d2I~
//v669:100517 add trim ascii option                                //~v669I~
//v668:100512 add utrim drop head option                           //~v668I~
//v65h:100321 add umemicmpdbcs                                     //~v65hI~
//v640:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~v640I~
//v62X:091107_compchkm                                             //~v62XI~
//v62q:090921!add uispunctdbcs                                     //~v62qI~
//v5mQ:080806 (CJK)DBCS chk for C(J)K                              //~v5mQI~
//v5mA:080620 missing definition of ustrstr in hdr file            //~v5mAI~
//v5mz:080619 add UstrncpyZ                                       //~v5mzI~//~v6hER~
//v5my:080614 add USTRHEADCMD USTRHEADICMP                         //~v5myI~
//v5mw:080529 add USTRLENC,UMEMLENC,..                             //~v5mwI~
//v5mp:080402 add umemtrim                                         //~v5mpI~
//v5m9:080217 STR_DROPEOL macro add                                //~v5m9I~
//v5m8:080216 ustrdup for syntaxhl                                 //~v5m8I~
//v5m6:080204 add uispunct                                         //~v5m6I~
//v5m5:080203 define macro UmemcpyZ                                //~v5m5I~
//v57s:030125 add umempbrk                                         //~v57sI~
//v516:011219 add umemrpblk;search last pos of char ins parm string//~v516I~
//v111:971103 ustrncpyz strncpy gualantied with last null and only one null//~v111I~
//v098:970723 split uparse fro ustring to uparse.c                 //~v098I~
//v097:970720 umemspnc,umemrspnc                                   //~v097I~
//v094:970706 umemrspn(umemspn is same meaning as ustrnspn)        //~v094I~
//            ustrnrspn must trate parm1 as string                 //~v094I~
//v093:970706 (BUG)set null out of range may corrupt naboring area(ustrnchar2,ustrnrchr2)//~v093I~
//            and conbine to umemchar2,umemrchr2)                  //~v093I~
//v092:970705 umemmem/umemmemi/umemstr/umemstri/umemrmem/umemrmemi/umemrstr/umemrstri//~v092R~
//v091:970705 add ustrnlen(max n)                                  //~v091I~
//v080:970503 add uparsein to enclabe string by quate for dlcmd to dcmd//~v080I~
//v069:970330:uparsev(output by argv format)                       //~v069I~
//v046:961123:uparse2 no malloc output area option(malloc at out of function)//~v046I~
//           :uparse:malloc only when long string                  //~6B23I~
//           :uparse:delm lost when pre/post space exist.          //~6B23I~
//                   add option to set delm except for ","         //~6B23I~
//v017:960714:add ustrchr2(strchr protecting detect dbcs 2nd byte) //~v017I~
//            add ustrnchr2=(ustrchr2 with length)                 //~v017I~
//            add ustrrchr2(search last char protecting detect dbcs 2nd byte)//~v017I~
//            add ustrnrchr2=(ustrrchr2 with length)               //~v017I~
//960324:uparse2:with delm/qaute return function                //~6324I~
//*******************************************************       //~6324I~
#define USTR_NOPUNCT  "@_$"                                        //~v5m6I~
#define UmemcpyZ(to,from,len)  memcpy(to,from,len),*((to)+(len))=0 //~v5m5R~
#define UstrncpyZ(to,from,len)  strncpy(to,from,(len)-1),*((to)+(len)-1)=0//~v5mzI~
#define UstrcpyZ(to,from,sz)  \
        do {                                                   \
        		size_t strsz;                                  \
                strsz=strlen(from);                            \
       			if (strsz>=(size_t)sz)                         \
                	UmemcpyZ(to,from,(size_t)(sz-1));          \
                else                                           \
                	memcpy(to,from,strsz+1); /*with last null*/\
		} while(0)                                                 //~v6J0I~
#define UMEMSPRINTF(dest,destsz,fmt,...)                    \
                do {/*bypass appending last null char*/    \
                    char wk[destsz+2];                     \
                  /*UTRACED("xedir2.wk before",wk,destsz+2);*/ \
                    snprintf(wk,destsz+1,fmt,__VA_ARGS__);\
                  /*UTRACED("xedir2.wk after",wk,destsz+2);*/ \
                    memcpy(dest,wk,destsz);                \
                }  while(0)                                        //~v6J0I~
//#define USTRLENC(src,ch,wkpc)  ((wkpc=strchr(src,ch))?((ULONG)wkpc-(ULONG)(src)):strlen(src))//~v5mwR~//~v6hhR~
#define USTRLENC(src,ch,wkpc)  ((wkpc=strchr(src,ch))?((ULPTR)wkpc-(ULPTR)(src)):strlen(src))//~v6hhI~
//#define USTRLENCINC(src,ch,wkpc)  ((wkpc=strchr(src,ch))?((ULONG)wkpc-(ULONG)(src)+1):strlen(src))//~v5mwR~//~v6hhR~
#define USTRLENCINC(src,ch,wkpc)  ((wkpc=strchr(src,ch))?((ULPTR)wkpc-(ULPTR)(src)+1):strlen(src))//~v6hhI~
//#define UMEMLENC(src,ch,len,wkpc)  ((wkpc=memchr(src,ch,len))?((ULONG)wkpc-(ULONG)(src)):len)//~v5mwR~//~v6hhR~
#define UMEMLENC(src,ch,len,wkpc)  ((wkpc=memchr(src,ch,len))?((ULPTR)wkpc-(ULPTR)(src)):len)//~v6hhI~
//#define UMEMLENCINC(src,ch,len,wkpc)  ((wkpc=memchr(src,ch,len))?((ULONG)wkpc-(ULONG)(src)+1):len)//~v5mwR~//~v6hhR~
#define UMEMLENCINC(src,ch,len,wkpc)  ((wkpc=memchr(src,ch,len))?((ULPTR)wkpc-(ULPTR)(src)+1):len)//~v6hhI~
//#define UMEMLENCR(src,ch,len,wkpc) ((wkpc=umemrchr(src,ch,len))?(wkpc++,((ULONG)(src)+len-(ULONG)wkpc)):(wkpc=src,len))//~v5mwR~//~v6hhR~
//#define UMEMLENCR(src,ch,len,wkpc) ((wkpc=umemrchr(src,ch,len))?(wkpc++,((ULPTR)(src)+len-(ULPTR)wkpc)):(wkpc=src,len))//~v6hhI~//~v6D0R~
#define UMEMLENCR(src,ch,len,wkpc) ((wkpc=umemrchr(src,ch,len))?(wkpc++,((size_t)PTRDIFF(src,wkpc)+len)):(wkpc=src,len))//~v6D0R~
//#define UMEMLENCRINC(src,ch,len,wkpc) ((wkpc=umemrchr(src,ch,len))?((ULONG)(src)+len-(ULONG)wkpc):wkpc=src,len)//~v5mwR~//~v6hhR~
#define UMEMLENCRINC(src,ch,len,wkpc) ((wkpc=umemrchr(src,ch,len))?((ULPTR)(src)+len-(ULPTR)wkpc):wkpc=src,len)//~v6hhI~
#define USTR_DROPEOL(line) \
		   {	int lenlen;                                    \
        		lenlen=(int)strlen(line);                              \
                if (lenlen && *(line+lenlen-1)=='\n')    /*0x0a*/    \
                	lenlen--;                                     \
                if (lenlen && *(line+lenlen-1)=='\r')    /*0x0d*/    \
                	lenlen--;                                     \
                *(line+lenlen)=0;                                 \
            }                                                      //~v5m9R~
#define USTR_DROPEOL_GETLEN(line,lenlen) \
		   {	                                               \
        		lenlen=(int)strlen(line);                              \
                if (lenlen && *(line+lenlen-1)=='\n')    /*0x0a*/    \
                	lenlen--;                                     \
                if (lenlen && *(line+lenlen-1)=='\r')    /*0x0d*/    \
                	lenlen--;                                     \
                *(line+lenlen)=0;                                 \
            }                                                      //~v5m9R~
#define USTR_DROPEOL_GETBINLEN(line,lenlen,maxlen) \
		   {	                                               \
           		char *pcpc;                                    \
        		pcpc=memchr(line,'\n',maxlen);                 \
                lenlen=(pcpc?(int)((ULONG)pcpc-(ULONG)line)+1:maxlen); \
                if (lenlen && *(line+lenlen-1)=='\n')    /*0x0a*/      \
                	lenlen--;                                          \
                if (lenlen && *(line+lenlen-1)=='\r')    /*0x0d*/      \
                	lenlen--;                                          \
                *(line+lenlen)=0;                                      \
            }                                                      //~v5mQI~
#define USTRHEADIS(str,conststr) \
       (strlen(str)>=sizeof(conststr)-1 && !memcmp(str,conststr,sizeof(conststr)-1))//~v5myI~
#define USTRHEADIS_STR(str,substr) \
       (strlen(str)>=strlen(substr) && !memcmp(str,substr,strlen(substr)))//~v6x6I~
#define USTRHEADIS_IC(str,conststr) \
       (strlen(str)>=sizeof(conststr)-1 && !memicmp(str,conststr,sizeof(conststr)-1))//~v5myI~
#define USTRHEADIS_IC_STR(str,substr) \
       (strlen(str)>=strlen(substr) && !memicmp(str,substr,strlen(substr)))//~v6x6I~
#define USTRTAILIS(str,conststr) \
       (strlen(str)>=sizeof(conststr)-1 && !memcmp(str+strlen(str)-(sizeof(conststr)-1),conststr,sizeof(conststr)-1))//~v5myI~
#define USTRTAILIS_IC(str,conststr) \
       (strlen(str)>=sizeof(conststr)-1 && !memicmp(str+strlen(str)-(sizeof(conststr)-1),conststr,sizeof(conststr)-1))//~v5myI~
//**get not null large or small ptr ***                            //~v6d2I~
#define USTR_MINPTR(pc1,pc2) \
		(pc1) ? ( (pc2) ? ((pc1)<(pc2)?(pc1):(pc2)) \
                        : (pc1)                     \
                )                                   \
              : (pc2)                                              //~v6d2I~
#define USTR_MAXPTR(pc1,pc2) \
		(pc1) ? ( (pc2) ? ((pc1)>(pc2)?(pc1):(pc2)) \
                        : (pc1)                     \
                )                                   \
              : (pc2)                                              //~v6d2I~
#define USKIP_SPACETAB(_pdata,_len)	                           \
        do {                                               \
        		int spacectr;                              \
       			spacectr=(int)umemspn_spacetab(_pdata,(unsigned)_len);    \
        		_pdata+=spacectr;                          \
	    		_len-=spacectr;                             \
		} while(0)                                                 //~v6hEI~
//     			spacectr=umemspn_spacetab(_pdata,_len)             //~v6D0I~
#define USKIP_TO_SPACETAB(_pdata,_len)	                       \
        do {                                                   \
        		int _nonspacectr;                              \
                char *_pc;                                     \
       			_pc=umempbrk(_pdata," \t",_len);               \
                if (_pc)                                       \
                	_nonspacectr=PTRDIFF(_pc,_pdata);          \
                else                                           \
                	_nonspacectr=_len;                         \
        		_pdata+=_nonspacectr;                          \
	    		_len-=_nonspacectr;                            \
		} while(0)                                                 //~v6hEI~
//*******************************************************       //~4C21I~
char *ustrnpbrk(const char *Pbuff,const char *Pkey,unsigned int Plen);//~4C21I~
//*******************************************************       //~4C20I~
size_t ustrnspn(const char *Pbuff,const char *Pxstr,unsigned int Plen);//~4C20I~
//*******************************************************       //~4C20I~
size_t ustrrspn(const char *Pbuff,const char *Pxstr);           //~4C20R~
//*******************************************************       //~4C20I~
size_t ustrnrspn(const char *Pbuff,const char *Pxstr,unsigned int Plen);//~4C20I~
//*******************************************************          //~v094I~
size_t umemrspn(char *Pbuff,char *Pxstr,unsigned int Plen);        //~v094I~
//*******************************************************          //~v516I~
char *umempbrk(char *Pbuff,UCHAR *Pstr,size_t Plen);               //~v57sR~
//*******************************************************          //~v57sI~
char *umemrpbrk(char *Pbuff,UCHAR *Pstr,size_t Plen);              //~v57sI~
//*******************************************************       //~4C20I~
char *ustrnstr(const char *Pbuff,const char *Pkey,unsigned int Plen);//~4C20I~
//*******************************************************       //~4C20I~
char *ustrrstr(const char *Pbuff,const char *Pkey);             //~4C20I~
//*******************************************************       //~4C20I~
char *ustrnrstr(const char *Pbuff,const char *Pkey,unsigned int Plen);//~4C20I~
//*******************************************************       //~4C20I~
char *ustrstri(const char *Pbuff,const char *Pkey);             //~4C20I~
//*******************************************************          //~v5mAI~
char *ustrrstr(const char *Pbuff,const char *Pkey);                //~v5mAR~
//*******************************************************       //~4C20I~
char *ustrnstri(const char *Pbuff,const char *Pkey,unsigned int Plen);//~4C20I~
//*******************************************************       //~4C20I~
char *ustrrstri(const char *Pbuff,const char *Pkey);            //~4C20I~
//*******************************************************       //~4C20I~
char *ustrnrstri(const char *Pbuff,const char *Pkey,unsigned int Plen);//~4C20I~
//*******************************************************       //~4C23I~
char *ustrnrchr(const char *Pbuff,UCHAR Pch,size_t Plen);       //~4C23R~
//*******************************************************          //~v017I~
char *ustrchr2(char *Pbuff,char Pch);                              //~v017I~
//*******************************************************          //~v017I~
char *ustrnchr2(char *Pbuff,char Pch,size_t Plen);                 //~v093R~
//*******************************************************          //~v093I~
char *umemchr2(char *Pbuff,char Pch,size_t Plen);                  //~v093R~
//*******************************************************          //~v017I~
char *ustrrchr2(char *Pbuff,char Pch);                             //~v017R~
//*******************************************************          //~v017I~
char *ustrnrchr2(char *Pbuff,char Pch,size_t Plen);                //~v093R~
//*******************************************************          //~v093M~
char *umemrchr2(char *Pbuff,char Pch,size_t Plen);                 //~v093R~
//*******************************************************          //~v080I~
char *umemrchr(char *Pbuff,UCHAR Pch,size_t Plen);                 //~v080I~
//*******************************************************          //~v6H3I~
char *ustrnchr(char *Pbuff,int Pch,size_t Plen);                   //~v6H3R~
//*******************************************************          //~v091I~
size_t ustrnlen(char *Pbuff,unsigned int Plen);                    //~v091I~
//*******************************************************          //~v092I~
char *umemstr(char *Pbuff,char *Pkey,unsigned int Plen);           //~v092I~
//*******************************************************          //~v092I~
char *umemstri(char *Pbuff,char *Pkey,unsigned int Plen);          //~v092I~
//*******************************************************          //~v092I~
char *umemrstr(char *Pbuff,char *Pkey,unsigned int Plen);          //~v092I~
//*******************************************************          //~v092I~
char *umemrstri(char *Pbuff,char *Pkey,unsigned int Plen);         //~v092I~
//*******************************************************          //~v092I~
char *umemmem(char *Pbuff,char *Pkey,unsigned int Plen,unsigned int Plenk);//~v092I~
//*******************************************************          //~v092I~
char *umemmemi(char *Pbuff,char *Pkey,unsigned int Plen,unsigned int Plenk);//~v092I~
//*******************************************************          //~v092I~
char *umemrmem(char *Pbuff,char *Pkey,unsigned int Plen,unsigned int Plenk);//~v092I~
//*******************************************************          //~v092I~
char *umemrmemi(char *Pbuff,char *Pkey,unsigned int Plen,unsigned int Plenk);//~v092I~
//*******************************************************          //~v097I~
size_t umemspnc(char *Pbuff,char Pchr,unsigned int Plen);          //~v097I~
size_t ustrnspnc(char *Pbuff,char Pchr,unsigned int Plen);         //+v7c5I~
//*******************************************************          //~v6hDI~
size_t umemspn_spacetab(char *Pbuff,unsigned int Plen);            //~v6hDI~
//*******************************************************          //~v097I~
size_t umemrspnc(char *Pbuff,char Pchr,unsigned int Plen);         //~v097I~
//*******************************************************          //~v111I~
char *ustrncpyz(char *Ptarget,char *Psource,unsigned int Plen);    //~v111I~
//*******************************************************          //~v5m6I~
int uispunct(int Popt,int Pch);                                    //~v5m6I~
#define  UISP_ACCEPT_LOCALE  0x01 //chk also non ASCII(>=128)      //~v5m6R~
#define  UISP_NON_C          0x02 //treat @_$ as punct             //~v5m6R~
#define  UISP_UCS2           0x04 //input is ucs2 BigEndian        //~v640I~
//*******************************************************          //~v62qI~
#ifdef UTF8SUPPH                                                   //~v62XI~
int uispunctdbcs(int Popt,char *Pdata);                            //~v62qI~
#endif                                                             //~v62XI~
//*******************************************************          //~v5m6I~
char *ustrdup(int Popt,char *Pstr,int Plen);                       //~v5m8R~
//*******************************************************          //~v5mpI~
char *umemtrim(int Popt,char *Pmem,int Plen,char Pch,char *Pout,int *Ppoutlen);//~v5mpI~
#define  UMTO_1ST     0x01      //trim by 1st detected char        //~v5mpI~
#define  UMTO_HEAD    0x02      //trim headding                    //~v668I~
#define  UMTO_NOCOPY  0x04      //only return add and length       //~v668I~
#define  UMTO_ASCII   0x08      //trim ascii(get non ascii)        //~v669I~
//*******************************************************          //~v65hI~
int umemicmpdbcs(int Popt,char *Pdata,char *Pdbcs,char* Pcmp,int Plen);//~v65hI~
//*******************************************************          //~v65hI~
char *umemstridbcs(int Popt,char *Pdata,char *Pdbcs,char* Pkey,int Plen);//~v65hR~
#define UMSIDO_KEYDBCS   0x01 //dbcs is of key                     //~v65hI~
//*******************************************************          //~v65hI~
char *umemrstridbcs(int Popt,char *Pdata,char *Pdbcs,char* Pkey,int Plen);//~v65hI~
#define UMRSIDO_KEYDBCS   0x01 //dbcs is of key                    //~v65hI~
