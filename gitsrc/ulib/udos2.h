//*CID://+v70dR~:                             update#=    6;       //~v70dR~
//******************************************************
//*udos2.h
//******************************************************
//v70d:200625 (LNX)setenv may destroy env,use putenv               //+v70dI~
//v6c1:120120 udos_setenv:to append to $PATH,specify explicit option(duplicated fpr ICUDATA)//~v5c1I~
//v6bo:111214 putenv(dont free)/setenv(copyed, can be free)        //~v6boI~//~v5kpM~
//v5kp:070613 (BUG)repeated rctl is effective only once(need keyup)//~v5kpI~
//v566:020703 new function of drive id list for xff all            //~v566I~
//v180:980508 add ugetdrivetype
//******************************************************
int ugetdriveidlist(int Ptype,char *Pdriveidlist);                 //~v566I~
//******************************************************           //~v566I~
ULONG ugetdrivelist(int Ptype);                                    //~v566I~
//******************************************************           //~v566I~
int ugetdrivetype(char Pdriveid,int Pmsgopt);
#define UDDC_ERRMSG 0x01
#define UDDC_ERR    	-1
#define UDDC_INVDRVID   -2
#define UDDC_REMOVABLE  0      //cdrom for os/2
#define UDDC_FIXED      1
#define UDDC_REMOTE     2      //cdrom for dos/gcc
#define UDDC_CDROM      3      //win95 only
#define UDDC_RAMDISK    4      //win 95 only
#ifdef DOS                                                         //~v5kpI~
	int udossleephs(int Phs);                                      //~v5kpI~
#endif                                                             //~v5kpI~
//*******************************************************          //~v6boI~//~v5kpM~
int udos_setenv(int Popt,char *Pkey,char *Pvalue);                 //~v6boI~//~v5kpM~
#define UDSE_PREPEND 0x01    //for $PATH, prepend to old env       //~v5c1I~
//*******************************************************          //~v70dI~
void listenv();                                                    //~v70dI~
