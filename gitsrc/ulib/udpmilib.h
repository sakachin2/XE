//CID://+v134R~:                                                   //~v134R~
//******************************************************           //~v053I~
//*udpmilib.h function lack from libc                              //~v053I~
//*************************************************************    //~v053I~
//v134:971224 (BUG:GCC)libc/ansi/string/memchr function is buggy for dbcs//~v134I~
//            because compare by int(dbcs is minus value).add to udpmilib//~v134I~
//v073:970420 (GCC)_harderr,_hardresume support                    //~v073R~
//v053:970107:gcc version(control by DPMI)                         //~v053I~
//******************************************************           //~v053I~
#define _HARDERR_ABORT 	2	//program exit                         //~v073M~
#define	_HARDERR_FAIL	3	//stop system call                     //~v073M~
#define	_HARDERR_IGNORE	0	//ignore                               //~v073M~
#define	_HARDERR_RETRY	1	//retry                                //~v073M~
typedef void (*FUNC24)(USHORT Pdeverr,USHORT Perrcode,char *Pdevhdr);//~v073R~
                                                                   //~v073M~
//*******************************************************          //~v053I~
int memicmp(void *Psrc1,void *Psrc2,unsigned int Plen);            //~v053R~
                                                                   //~v053I~
//*******************************************************          //~v053I~
int fcloseall(void);                                               //~v053I~
                                                                   //~v053I~
//*******************************************************          //~v053I~
unsigned long _dos_getvect(int Pintno);                            //~v053I~
                                                                   //~v073I~
//**************************************************************** //~v073I~
void _harderr(FUNC24 Pfunc24);                                     //~v073R~
                                                                   //~v073I~
//**************************************************************** //~v073I~
void _hardresume(int Popt);                                        //~v073I~
                                                                   //~v134I~
//**************************************************************** //~v134I~
void *                                                             //~v134I~
memchr(const void *s, int c, size_t n);                            //+v134R~
