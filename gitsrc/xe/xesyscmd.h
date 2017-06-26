//*CID://+v59ER~:                                                  //~v59ER~
//**************************************************************** //~v579I~
//xesyscmd.h                                                       //~v579I~
//**************************************************************** //~v579I~
//v59E:041120 (WXE)pass env to sub process xesyscmd.exe            //~v59EI~
//v579:040516 (WXE:BUG)cmd svr should set CD effect for cmd grep etc//~v579I~
//**************************************************************** //~v579I~
//************************************                             //~v579I~
#define XECMDSVR_CMDSTR    "!%c %-8s %s"   //cmd string for fmd server//~v579R~
#define XECMDSVR_CMDID     '!'                                     //~v579I~
#define XECMDSVR_OPRPOS     3                                      //~v59EI~
#define XECMDSVR_OPDPOS     12                                     //~v579R~
#define XECMDSVR_DRIVECMD  '1'                                     //~v579I~
#define XECMDSVR_CDCMD     '2'                                     //~v579I~
#define XECMDSVR_PWDCMD    '3'                                     //~v579I~
#define XECMDSVR_GETENV    '4'                                     //~v59ER~
#define XECMDSVR_PUTENV    '5'                                     //~v59EI~
//************************************                             //~v579I~
