//*CID://+v6n1R:                              update#=  137;       //~v6n1R
//*********************************************************************//~v131I~
//v6n1:130905 memcpy implementation of suse12.3(err if region overlap)(also for Windows spec)//~v6n1I
//*********************************************************************//~v131I~//~v6n1I
#ifdef memcpy                                                      //+v6n1M
	#define PUSH_MEMCPY                                            //+v6n1I
	#pragma push_macro("memcpy")                                   //+v6n1R
	#undef memcpy                                                  //~v6n1I
#endif                                                             //~v6n1I
#define memcpy(tgt,src,len) ustring_memcpy(tgt,src,len)            //~v6n1I
#define USTR_MEMCPY ustring_memcpy                                 //~v6n1I
                                                                   //~v6n1I
#ifdef strncpy                                                     //~v6n1I
	#define PUSH_STRNCPY                                           //+v6n1I
	#pragma push_macro("strncpy")                                  //+v6n1I
	#undef strncpy                                                 //~v6n1I
#endif                                                             //~v6n1I
#define strncpy(tgt,src,len) ustring_strncpy(tgt,src,len)          //~v6n1I
#define USTR_STRNCPY ustring_strncpy                               //~v6n1I
                                                                   //~v6n1I
#ifdef strcpy                                                      //~v6n1I
	#define PUSH_STRCPY                                            //+v6n1I
	#pragma push_macro("strcpy")                                   //+v6n1I
	#undef strcpy                                                  //~v6n1I
#endif                                                             //~v6n1I
#define strcpy(tgt,src    ) ustring_strcpy(tgt,src)                //~v6n1R
#define USTR_STRCPY ustring_strcpy                                 //~v6n1I
#ifdef __cplusplus                                                 //~v6n1I
extern  "C"                                                        //~v6n1I
{                                                                  //~v6n1I
#endif                                                             //~v6n1I
	void *ustring_memcpy(void *Ptgt,const void *Psrc,size_t Plen); //~v6n1I
	char *ustring_strncpy(char *Ptgt,const char *Psrc,size_t Plen);//~v6n1I
	char *ustring_strcpy(char *Ptgt,const char *Psrc);             //~v6n1I
#ifdef __cplusplus                                                 //~v6n1I
}                                                                  //~v6n1I
#endif                                                             //~v6n1I
