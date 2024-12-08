//CID://+v6hdR~:        update#=   7                               //+v6hdR~
//******************************************************
// ukbdw.h                                                         //~v137R~
//******************************************************        //~5104I~
//v6hd:120616 for VC6:/W4 warning(C4057)                           //~v6hdI~
//v65d:100311 RAW unicode input(ucs2local fail but accept it when env is utf8)//~v65dI~
//v5ma:080219 (BUG)C+c break process after system(),spawn() because it loose console mode//~v5maI~
//v298:000205 add option of w95 kbd trace by UTRACE                //~v298I~
//v186:980724 accept force NT mode req                             //~v186I~
//v141:980115 (W32)uget/usetconsolemode for input/output each      //~v141I~
//v137:980110 (W32)split ukbdw.c from ubd ukbd.c                   //~v137I~
//v034:961008:VisualC++ support(identify by (_MSC_VER>=800))       //~v034I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//******************************************************           //~v022I~
void ukbd_w95init(void);                                           //~v137I~
//*******************************************************          //~v137I~
int ukbd_w95read(PKBDKEYINFO Ppkinf,int Pwait);                    //~v137I~
//**************************************************               //~v137I~
void ukbd_w95traceinit(int Popt);                                  //~v034I~
#define KBD_PTRACE  0x01            //printf trace                 //~v298I~
#define KBD_UTRACE  0x02            //trace by utrace              //~v298I~
//**************************************************               //~v137I~
int ukbd_w95setstatus(PKBDINFO Ppkbdinfo);                         //~v137R~
//**************************************************               //~v137I~
//UINT ugetconsolemode(int Pid);                                     //~v141I~//~v6hdR~
DWORD ugetconsolemode(int Pid);                                    //~v6hdI~
//*******************************************************          //~v137M~
//UINT usetconsolemode(int Pid,UINT Pmode);                          //~v141I~//~v6hdR~
DWORD usetconsolemode(int Pid,UINT Pmode);                         //~v6hdI~
//*******************************************************          //~v5maI~
int usetconsolemode2(int Popt,int Pid,UINT Pmode,UINT *Ppoldmode); //~v5maI~
#define USCM_ERREXIT      0x01 //errexit if err                    //~v5maR~
//**************************************************               //~v137M~
void ukbd_w95forcent(void);                                        //~v186R~
//**************************************************               //~v186I~
int uwriteconsoleinput(int Popt,void *Pinprec,int Pilen,int *Polen);//~v65dR~
//**************************************************               //~v65dI~
void ureadconsole(char *Parea,int Pilen,int *Polen);               //~v65dI~
