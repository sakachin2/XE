//CID://+v108R~:                                                   //~v108R~
//*************************************************************    //~v100I~
//*XVER.C  return version                                          //~v100I~
//*format                                                          //~v100I~
//*      xver                                                      //~v100R~
//*return version numver                                           //~v100R~
//*************************************************************    //~v100I~
//*020217 xver:v108:spell miis                                     //~v108I~
//*v107 980203 no need /Nm option(sufficiaent by >nul)             //~v107R~
//*            /w optio(win version) is meaningfull to w95 only    //~v107I~
//*            (w95 dos version is 7.0,win version is 4.0)         //~v107I~
//*            nt 4.0's dos is 5.0,no need of /N option            //~v107I~
//*v106 980202 win or nt by /W option                              //~v107I~
//*v105  980201 gcc version                                        //~v105I~
//*v104  980126 under DOS rc=1 for not executable,so set +100 for NT//~v103I~
//*v103  980124 win version and NT support                         //~v103R~
//*v102 980123 xver:v1.02:No msg option /Nm                        //~v102I~
//*v101 970420 /D support(DPMI version)                            //~v102I~
//*v100 first                                                      //~v100I~
//*************************************************************    //~v100I~
#define VERSION  "v1.08"                                           //+v108R~
#define PGMID    "XVER"                                            //~v100I~
//*************************************************************    //~v100I~
#include <time.h>                                                  //~v100I~
#include <stdio.h>                                                 //~v100I~
#include <stdlib.h>                                                //~v100I~
#include <string.h>                                                //~v100I~
                                                                   //~v105I~
#include <ctype.h>                                                 //~v106R~
                                                                   //~v105I~
#include <ulib.h>                                                  //~v100I~
#include <udos.h>                                                  //~v100I~
#include <uerr.h>                                                  //~v100I~
//********************                                             //~v100I~
static  char Spgmver[16];                                          //~v100I~
//********************                                             //~v100I~
void help(void);                                                   //~v100I~
void parmerr(char *Pprm);                                          //~v103I~
//*************************************************************    //~v100I~
int main(int parmc,char * parmp[])                                 //~v100I~
{                                                                  //~v100I~
        int parmno,rc;                                                 //~v100R~
    int majv,minv,other,majv2,minv2;                               //~v100R~
    char *cptr;                                                    //~v100I~
    char *pc;                                                      //~v103I~
    char rcver[16];                                                //~v100I~
    int dpmisw=0;                                                  //~v101I~
//  int msgsw=1;                                                   //~v107R~
//  int ntsw=0;                                                    //~v107R~
    int winsw=0;                                                   //~v107I~
    int yesno;                                                     //~v103I~
    char *wintype;                                                 //~v103I~
//  int ntadd;                                                     //~v107R~
//**********************                                           //~v100I~
        sprintf(Spgmver,"%s:%s: ",PGMID,VERSION);                      //~v100I~
        uerrmsg_init(Spgmver,stdout,0);//msg to stdout                 //~v100I~
        for (parmno=1;parmno<parmc;parmno++)                           //~v100I~
        {                                                              //~v100I~
                cptr=parmp[parmno];                                        //~v100I~
                if(*cptr=='?'                                              //~v100I~
                || !strcmp(cptr,"/?")                                      //~v100I~
                || !strcmp(cptr,"-?"))                                     //~v100I~
        {                                                          //~v100I~
                help();                                                //~v100I~
            exit (0);                                              //~v100I~
                }                                                          //~v100I~
//        if (!strcmp(cptr,"/D")                                   //~v103R~
//        ||  !strcmp(cptr,"/d")                                   //~v103R~
//        ||  !strcmp(cptr,"-D")                                   //~v103R~
//        ||  !strcmp(cptr,"-d"))                                  //~v103R~
//            dpmisw=1;                                            //~v103R~
//                                                                 //~v103R~
//        if (!strcmp(cptr,"/N9")                                  //~v103R~
//        ||  !strcmp(cptr,"/n9"))                                 //~v103R~
//            uerrmsg_init(Spgmver,stdout,UERR_FORCE_ENGLISH);//msg to stdout//~v103R~
//        if (!strcmp(cptr,"/Y9")                                  //~v103R~
//        ||  !strcmp(cptr,"/y9"))                                 //~v103R~
//            uerrmsg_init(Spgmver,stdout,0);//msg to stdout       //~v103R~
//        if (!stricmp(cptr,"/Ym"))                                //~v103R~
//                msgsw=1;                                         //~v103R~
//        if (!stricmp(cptr,"/Nm"))                                //~v103R~
//                msgsw=0;                                         //~v103R~
                if(*cptr=='/' || *cptr=='-')                               //~v103I~
        {                                                          //~v103I~
            pc=cptr+1;                                             //~v103R~
            switch(toupper(*pc))                                   //~v103I~
            {                                                      //~v103I~
            case 'D':   //dpmi version                             //~v103I~
                                dpmisw=1;                                          //~v106R~
                break;                                             //~v103I~
            case 'W':   //dpmi version                             //~v106I~
//              ntsw=1;                                            //~v107R~
                winsw=1;                                           //~v107I~
                break;                                             //~v106I~
            case 'Y':                                              //~v103I~
            case 'N':                                              //~v103I~
                yesno=(toupper(*pc)=='Y');                         //~v103I~
                ++pc;                                              //~v103I~
//              if  (!*pc && !yesno)    //      /N(nt)                 //~v106R~
//                      ntsw=1;                                        //~v106I~
                if  (!*pc)                                         //~v106I~
                    parmerr(cptr);                                 //~v106I~
                else                                               //~v106R~
                    for(;*pc;pc++)                                 //~v103I~
                    {                                              //~v103I~
                        switch(toupper(*pc))                       //~v103I~
                        {                                          //~v103I~
//                        case 'M':   //msg output                 //~v107R~
//                            msgsw=yesno;                         //~v107R~
//                            break;                               //~v107R~
//                        case 'N':   //nt sw                      //~v107R~
//                            ntsw=yesno;                          //~v107R~
//                            break;                               //~v107R~
                        case '9':   //japnese                      //~v103I~
                            uerrmsg_init(Spgmver,stdout,UERR_FORCE_ENGLISH*(!yesno));//msg to stdout//~v103I~
                            break;                                 //~v103R~
                        default:                                   //~v103I~
                            parmerr(pc);                           //~v103I~
                        }                                          //~v103I~
                    }//pc loop                                     //~v103I~
                break;                                             //~v103I~
                        default:                                               //~v103I~
                    parmerr(cptr);                                     //~v103I~
            }//sw                                                  //~v103I~
        }// / or -                                                 //~v103I~
        else                                                       //~v103I~
            parmerr(cptr);                                         //~v103I~
        }//for all parm                                                //~v100I~
    if (dpmisw)                                                    //~v101I~
    {                                                              //~v101I~
#ifdef DOS                                                         //~v101I~
        rc=udpmi_version(0);                                       //~v101I~
//    if (msgsw)                                                   //~v107R~
                uerrmsg("DPMI Version=%d,ERRORLEVEL=%d.",          //~v107R~
                        "DPMI バージョン=%d,ERRORLEVEL=%d.",       //~v107R~
                        rc,rc);                                                //~v101I~
            return rc;                                                 //~v101I~
#else                                                              //~v101I~
                uerrmsg("/D option avail for DOS version only",            //~v101I~
                        "/D オプションはDOSバージョンでのみ有効です");         //~v101I~
            return 0;                                                  //~v103R~
#endif                                                             //~v101I~
        }                                                              //~v101I~
//nt option                                                        //~v103I~
//    if (ntsw)                                                    //~v106R~
//    {                                                            //~v106R~
//#ifdef W32                                                       //~v106R~
//        rc=udosiswinnt();                                        //~v103R~
//        if (msgsw)                                               //~v103R~
//            if (rc)                                              //~v103R~
//                uerrmsg("System IS WindowsNT",                   //~v103R~
//                        "WindoswNT です");                       //~v103R~
//            else                                                 //~v103R~
//                uerrmsg("System is NOT WindowsNT",               //~v103R~
//                        "WindoswNT ではありません");             //~v103R~
//        return rc;                                               //~v103R~
//#else                                                            //~v106R~
//        uerrmsg("/N option avail for Windows version only",      //~v106R~
//            "/N オプションはWindoswバージョンでのみ有効です");   //~v106R~
//        return 0;                                                //~v106R~
//#endif                                                           //~v106R~
//    }                                                            //~v106R~
//#ifdef W32                                                       //~v106R~
//    if (udosiswinnt())                                           //~v106R~
//    {                                                            //~v106R~
//        wintype="WindoswNT";                                     //~v106R~
//        if (ntsw)                                                //~v106R~
//            ntadd=100;                                           //~v106R~
//    }                                                            //~v106R~
//    else                                                         //~v106R~
//        wintype="Windows";                                       //~v106R~
//#else                                                            //~v106R~
//    wintype="";                                                  //~v106R~
//#endif                                                           //~v106R~
    if (udosiswinnt())                                             //~v107R~
//    {                                                            //~v107R~
//        ntadd=200;                                               //~v107R~
#ifdef DOS                                                         //~v107I~
        wintype="Windows NT DOS";                                  //~v108R~
#else                                                              //~v107I~
        wintype="Windows NT";                                      //~v108R~
#endif                                                             //~v107I~
//    }                                                            //~v107R~
    else                                                           //~v107R~
        if (udosiswin())                                           //~v107R~
        {                                                          //~v107R~
//            ntadd=100;                                           //~v107R~
#ifdef DOS                                                         //~v107I~
    		if (winsw)                                             //~v107I~
	            wintype="Windows";                                 //~v107I~
			else                                                   //~v107I~
	            wintype="Windows DOS";                             //~v107I~
#else                                                              //~v107I~
            wintype="Windows";                                     //~v107R~
#endif                                                             //~v107I~
        }                                                          //~v107R~
        else                                                       //~v107R~
        {                                                          //~v107R~
//            ntadd=0;                                             //~v107R~
            if (udosisos2())    //os2 version only return 1        //~v107R~
#ifdef DOS                                                         //~v107I~
                wintype="OS/2 DOS";                                //~v107I~
#else                                                              //~v107I~
                wintype="OS/2";                                    //~v107R~
#endif                                                             //~v107I~
            else                                                   //~v107R~
#ifdef DOS                                                         //~v107I~
                wintype="DOS";                                     //~v107R~
#else                                                              //~v107I~
                wintype="???";                                     //~v107R~
#endif                                                             //~v107I~
        }                                                          //~v107R~
//    if (ntsw)                                                    //~v107R~
//    {                                                            //~v107R~
//      if (msgsw)                                                 //~v107R~
//            if (ntadd==200)                                      //~v107R~
//                uerrmsg("System IS WindowsNT(ERRORLEVEL=%d)",    //~v107R~
//                        "WindoswNT です(ERRORLEVEL=%d)",         //~v107R~
//                        ntadd);                                  //~v107R~
//            else                                                 //~v107R~
//                if (ntadd==100)                                  //~v107R~
//                    uerrmsg("System IS Windows(ERRORLEVEL=%d)",  //~v107R~
//                            "Windosw です(ERRORLEVEL=%d)",       //~v107R~
//                            ntadd);                              //~v107R~
//                else                                             //~v107R~
//                    uerrmsg("System IS Not Windows(ERRORLEVEL=%d)",//~v107R~
//                            "Windosw ではありません(ERRORLEVEL=%d)",//~v107R~
//                            ntadd);                              //~v107R~
//        return ntadd;                                            //~v107R~
//    }                                                            //~v107R~
//*********                                                        //~v107R~
    if (winsw)                                                     //~v107I~
    {                                                              //~v107I~
#ifdef DOS                                                         //~v107I~
        if (!uwin_version(&majv,&minv,&other))	//not win          //~v107R~
	        rc=udos_version(&majv,&minv,&other);                   //~v107I~
		else                                                       //~v107I~
        	rc=0;                                                  //~v107I~
#else                                                              //~v107I~
        rc=udos_version(&majv,&minv,&other);                       //~v107I~
#endif                                                             //~v107M~
        if (rc)                                                    //~v107I~
                return 255;                                            //~v107I~
    }                                                              //~v107I~
    else                                                           //~v107I~
    {                                                              //~v107I~
//#ifdef DOS                                                       //~v107R~
//    if (!uwin_version(&majv,&minv,&other))  //not windows        //~v107R~
//    {                                                            //~v107R~
//#endif                                                           //~v107R~
        rc=udos_version(&majv,&minv,&other);                       //~v100R~
        if (rc)                                                    //~v100R~
                return 255;                                            //~v100R~
//#ifdef DOS                                                       //~v107R~
        }                                                              //~v100I~
//#endif                                                           //~v107R~
        if (!(majv%10))                                                //~v100I~
        majv2=majv/10;                                             //~v100R~
        else                                                           //~v100I~
        majv2=majv;                                                //~v100I~
        if (!(minv%10))                                                //~v100I~
        minv2=minv/10;                                             //~v100R~
        else                                                           //~v100I~
        minv2=minv;                                                //~v100I~
    sprintf(rcver,"%d%d",majv2,minv2);                             //~v100R~
    rc=atoi(rcver);                                                //~v100R~
//  rc+=ntadd;                                                     //~v106R~
//if (msgsw)                                                       //~v107R~
    if (winsw)                                                     //~v107I~
        uerrmsg("%s Version= %d.%d, ERRORLEVEL=%d.",               //~v107I~
                        "%s バージョン= %d.%d, ERRORLEVEL=%d.",    //~v107I~
            wintype,                                               //~v107I~
                        majv,minv,rc);                             //~v107I~
    else                                                           //~v107I~
        uerrmsg("%s Version= %d.%d, ERRORLEVEL=%d.(/? for help)",      //~v103R~
                        "%s バージョン= %d.%d, ERRORLEVEL=%d.(ヘルプは /?)",   //~v103R~
            wintype,                                               //~v103I~
                        majv,minv,rc);                                         //~v100R~
    return rc;                                                     //~v100R~
}//main                                                            //~v100I~
//*********************                                            //~v100I~
void help(void)                                                    //~v100I~
{                                                                  //~v100I~
//************                                                     //~v100I~
        uerrmsg("Set ERRORLEVEL value from OS Version number.\n\
            Use ERRORLEVEL value in .BAT/.CMD file to control exec sequence.\n\
            ex. if ERRORLEVEL 211 goto os2dos.\n\
    (note). only lowest 1 byte value(0-255) of return code is evaluated.\n\
    Format: %s [/d] [/w]\n\
                  /d  :get DPMI version(for DOS version only)\n\
                  /w  :get Windows version if OS is Windows\n",    //~v107R~
             "システムのバージョン番号から ERRORLEVEL 値を設定する.\n\
            ERRORLEVEL 値は .BATや.CMDファイルでコマンドの実行条件制御に使用.\n\
            例. if ERRORLEVEL 211 goto os2dos.\n\
  (註) 戻りコードのうち下1バイトの値が評価されます(0から255迄の値).\n\
  形式: %s [/d] [/w]\n\
              /d  :DPMI バージョンを得る(DOSバージョンでのみ有効)\n\
              /w  :OSがWindowsならWindowsのバージョンを得る\n",    //~v107R~
            PGMID);                                                //~v103I~
        return;                                                        //~v100I~
}//help                                                            //~v100I~
//*********************                                            //~v103I~
void parmerr(char *Pprm)                                           //~v103I~
{                                                                  //~v103I~
//************                                                     //~v103I~
        uerrmsg("Invalid option(%s)",                                  //~v103I~
                        "オプションエラー(%s)",                                //~v103I~
            Pprm);                                                 //~v103I~
        exit(4);                                                       //~v103I~
        return;                                                        //~v103I~
}//parmerr                                                         //~v103I~
