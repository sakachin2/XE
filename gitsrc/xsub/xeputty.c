//*CID://+DATER~:                             update#=  287;
//***********************************************************
//* xeputty : customize puTTY keymapping                           //~7228R~
//***********************************************************
//070226 v1.0: first release
//***********************************************************
#define XE_PGMID   "xeputty"
#define XE_VER 	"V1.0"   //version
//*************************************************************
//#define TESTMAIN     //function test                             //~7228R~
//*************************************************************
#ifdef TESTMAIN
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>

#ifdef _WINDOWS                                                    //~7228I~
    #include <windows.h>
#else                                                              //~7228I~
    #include <unistd.h>                                            //~7228I~
    #include <gtk/gtk.h>                                           //~7228I~
    #include <gdk/gdkkeysyms.h>                                    //~7228I~
#endif                                                             //~7228I~

#else	//!TESTMAIN                                                //~7228I~
	#ifdef _WINDOWS                                                //~7228I~
	#else                                                          //~7228I~
    	#include <ctype.h>                                         //~7228I~
	#endif                                                         //~7228I~
#endif  //TESTMAIN                                                 //~7228R~
                                                                   //~7228I~
//*********************************************************************
#define XE_MAP_ENVVAR         "PUTTY_KEYMAP" 	//mapfile name environment variable//~7301R~
#ifdef _WINDOWS                                                    //~7301M~
	#define XE_MAP_FILENAME  "c:\\puTTY.xekeymap"                  //~7301M~
#else                                                              //~7301M~
	#define XE_MAP_FILENAME  "~/puTTY.xekeymap"                    //~7301M~
#endif                                                             //~7301M~
#define XE_MODID_KEYUP         '-'    //send at keyup              //~7228R~
#define XE_MAX_ESCSTRLEN   19
#define XE_MAP_LINEHDR  "KeyString:"
#define XE_MAP_SECTION_PUTTY  "puTTY"
#define XE_MAP_SECTION_COMMON "common"                             //~7301I~
#define XE_MAP_NULLFILE  '-'
//*********************************************************************
enum XE_MODID_IDX { //index by modifier key                        //~7301I~
        XE_MODID_NORMAL ,     //0                                  //~7301I~
        XE_MODID_SHIFT  ,     //1                                  //~7301I~
        XE_MODID_CTL    ,     //2                                  //~7301I~
        XE_MODID_ALT    ,     //3                                  //~7301I~
        XE_MODID_SCTL   ,     //4                                  //~7301I~
        XE_MODID_SALT   ,     //5                                  //~7301I~
        XE_MODID_CALT   ,     //6                                  //~7301I~
        XE_MODID_SCA    ,     //7                                  //~7301I~
        XE_MODID_MAX    ,     //8                                  //~7301I~
        };                                                         //~7301I~
typedef struct _UKMAPTBL {
							int   UKMTvkey;		//virtual key
							int   UKMTflag;		//virtual key      //~7228I~
#define UKMTF_CHARKEY    0x01   //not predefined numonic key name  //~7228I~
#define UKMTF_KEYUP      0x02   //string write at keyupcevent      //~7228I~
							int   UKMTescstrlen[XE_MODID_MAX];		//virtual key//~7227I~
							char  UKMTescstr[XE_MODID_MAX][XE_MAX_ESCSTRLEN+1];	//escape sequence
                         } UKMAPTBL,*PUKMAPTBL;
#define UKMAPTBLSZ       sizeof(UKMAPTBL)
typedef struct _UKNAMTBL {
							int   UKNTvkey;		    //virtual key
							char  UKNTkeyname[10];	//key identifier name
                         } UKNAMTBL,*PUKNAMTBL;
#define UKNAMTBLSZ       sizeof(UKNAMTBL)
//*********************************************************************
static char *Smodidt[XE_MODID_MAX]={"","S+","C+","A+","S+C+","S+A+","C+A+","S+C+A+"};//~7301I~
static int Smodidxtb[8]={                                          //~7228I~
                    XE_MODID_NORMAL,          //0                  //~7228M~
                    XE_MODID_SHIFT ,          //0x01 S+            //~7228M~
                    XE_MODID_CTL   ,          //0x02 C+            //~7228M~
                    XE_MODID_SCTL  ,          //0x03 S+C+          //~7228M~
                    XE_MODID_ALT   ,          //0x04 A+            //~7228M~
                    XE_MODID_SALT  ,          //0x05 S+A           //~7228M~
                    XE_MODID_CALT  ,          //0x06 C+A           //~7228M~
                    XE_MODID_SCA   };         //0x07 S+C+A         //~7228I~
                                                                   //~7228I~
#ifdef _WINDOWS                                                    //~7301M~
#else                                                              //~7301M~
    #define       VK_F1         GDK_F1                             //~7301M~
    #define       VK_F2         GDK_F2                             //~7301M~
    #define       VK_F3         GDK_F3                             //~7301M~
    #define       VK_F4         GDK_F4                             //~7301M~
    #define       VK_F5         GDK_F5                             //~7301M~
    #define       VK_F6         GDK_F6                             //~7301M~
    #define       VK_F7         GDK_F7                             //~7301M~
    #define       VK_F8         GDK_F8                             //~7301M~
    #define       VK_F9         GDK_F9                             //~7301M~
    #define       VK_F10        GDK_F10                            //~7301M~
    #define       VK_F11        GDK_F11                            //~7301M~
    #define       VK_F12        GDK_F12                            //~7301M~
    #define       VK_HOME       GDK_Home                           //~7301M~
    #define       VK_END        GDK_End                            //~7301M~
    #define       VK_INSERT     GDK_Insert                         //~7301M~
    #define       VK_DELETE     GDK_Delete                         //~7301M~
    #define       VK_PRIOR      GDK_Page_Up      //=GDK_Prior      //~7301M~
    #define       VK_NEXT       GDK_Page_Down    //=GDK_Next       //~7301M~
    #define       VK_UP         GDK_Up                             //~7301M~
    #define       VK_DOWN       GDK_Down                           //~7301M~
    #define       VK_LEFT       GDK_Left                           //~7301M~
    #define       VK_RIGHT      GDK_Right                          //~7301M~
    #define       VK_ESCAPE     GDK_Escape                         //~7301M~
    #define       VK_BACK       GDK_BackSpace                      //~7301M~
    #define       VK_TAB        GDK_Tab                            //~7301M~
    #define       VK_RETURN     GDK_Return                         //~7301M~
    #define       VK_NUMPAD0    GDK_KP_0                           //~7301M~
    #define       VK_NUMPAD1    GDK_KP_1                           //~7301M~
    #define       VK_NUMPAD2    GDK_KP_2                           //~7301M~
    #define       VK_NUMPAD3    GDK_KP_3                           //~7301M~
    #define       VK_NUMPAD4    GDK_KP_4                           //~7301M~
    #define       VK_NUMPAD5    GDK_KP_5                           //~7301M~
    #define       VK_NUMPAD6    GDK_KP_6                           //~7301M~
    #define       VK_NUMPAD7    GDK_KP_7                           //~7301M~
    #define       VK_NUMPAD8    GDK_KP_8                           //~7301M~
    #define       VK_NUMPAD9    GDK_KP_9                           //~7301M~
    #define       VK_MULTIPLY   GDK_KP_Multiply                    //~7301M~
    #define       VK_ADD        GDK_KP_Add                         //~7301M~
    #define       VK_SUBTRACT   GDK_KP_Subtract                    //~7301M~
    #define       VK_DECIMAL    GDK_KP_Decimal                     //~7301M~
    #define       VK_DIVIDE     GDK_KP_Divide                      //~7301M~
    #define       VK_SEPARATOR  GDK_KP_Enter                       //~7301M~
#endif                                                             //~7301M~
static  UKNAMTBL Suknamt[]={
                           {VK_F1            ,"F1"            },
                           {VK_F2            ,"F2"            },
                           {VK_F3            ,"F3"            },
                           {VK_F4            ,"F4"            },
                           {VK_F5            ,"F5"            },
                           {VK_F6            ,"F6"            },
                           {VK_F7            ,"F7"            },
                           {VK_F8            ,"F8"            },
                           {VK_F9            ,"F9"            },
                           {VK_F10           ,"F10"           },
                           {VK_F11           ,"F11"           },
                           {VK_F12           ,"F12"           },
                           {VK_HOME          ,"Home"          },
                           {VK_END           ,"End"           },
                           {VK_INSERT        ,"Insert"        },
                           {VK_DELETE        ,"Delete"        },
                           {VK_PRIOR         ,"PageUp"        },
                           {VK_NEXT          ,"PageDown"      },
                           {VK_UP            ,"Up"            },
                           {VK_DOWN          ,"Down"          },
                           {VK_LEFT          ,"Left"          },
                           {VK_RIGHT         ,"Right"         },
                           {VK_ESCAPE        ,"Esc"           },
                           {VK_BACK          ,"BackSpace"     },
                           {VK_TAB           ,"Tab"           },
                           {VK_RETURN        ,"Enter"         },
                           {VK_NUMPAD0       ,"P0"            },
                           {VK_NUMPAD1       ,"P1"            },
                           {VK_NUMPAD2       ,"P2"            },
                           {VK_NUMPAD3       ,"P3"            },
                           {VK_NUMPAD4       ,"P4"            },
                           {VK_NUMPAD5       ,"P5"            },
                           {VK_NUMPAD6       ,"P6"            },
                           {VK_NUMPAD7       ,"P7"            },
                           {VK_NUMPAD8       ,"P8"            },
                           {VK_NUMPAD9       ,"P9"            },
                           {VK_MULTIPLY      ,"P*"            },
                           {VK_ADD           ,"P+"            },
                           {VK_SUBTRACT      ,"P-"            },
                           {VK_DECIMAL       ,"P."            },
                           {VK_DIVIDE        ,"P/"            },
                           {VK_SEPARATOR     ,"KP_Enter"      },   //~7301R~
                           {0                ,""              } //terminator
                         };
#ifdef _WINDOWS                                                    //~7228I~
	#define XE_MAPT_MAXENT 256                                     //~7228I~
#else                                                              //~7228I~
	#define XE_MAPT_MAXENT 512 //1st half 1s for FFxx,2nd half is for char key//~7228I~
#endif                                                             //~7228I~
static  UKMAPTBL Sukmapt[XE_MAPT_MAXENT];	//vertulakey is not dulicated width char key//~7228I~
static char *Smapfile;                                             //~7228I~
#ifdef DEBUG                                                       //~7228I~
    char Sdebugbuff[1024];                                         //~7228I~
    #define DEBUGLOG(set) {set;dputs(Sdebugbuff);}                 //~7228R~
#else                                                              //~7228I~
    #define DEBUGLOG(set)                                          //~7228I~
#endif                                                             //~7228I~
//**********************************************************************
#ifndef _WINDOWS                                                   //~7228I~
//*******************************************************          //~7228I~
//*memicmp                                                         //~7228I~
//*parm1:source1                                                   //~7228I~
//*parm2:source2                                                   //~7228I~
//*parm3:len                                                       //~7228I~
//*ret  :result  0:match,<0,or >0-                                 //~7228I~
//*******************************************************          //~7228I~
int memicmp(void *Psrc1,void *Psrc2,unsigned int Plen)             //~7228I~
{                                                                  //~7228I~
    char *pc1,*pc2;                                                //~7228I~
//*******************                                              //~7228I~
    for(pc1=Psrc1,pc2=Psrc2;Plen>0;Plen--,pc1++,pc2++)             //~7228I~
        if (tolower(*pc1)!=tolower(*pc2))                          //~7228I~
            return (int)tolower(*pc1)-(int)tolower(*pc2);          //~7228I~
    return 0;                                                      //~7228I~
}//memicmp                                                         //~7228I~
#endif                                                             //~7228I~
//******************************************************
//* err msg(max 10 printf parm)
//******************************************************
int xeputty_errmsg(char *Pemsg,...)
{
	unsigned long *parg;
    char msgbuff[4095];
//****************************
	parg=(unsigned long*)(void*)((&Pemsg)+1);
    sprintf(msgbuff,Pemsg,
	        *(parg+0),*(parg+1),*(parg+2),*(parg+3),*(parg+4),
            *(parg+5),*(parg+6),*(parg+7),*(parg+8),*(parg+9));
#ifdef TESTMAIN
    printf("%s\n",msgbuff);
#else
	#ifdef _WINDOWS                                                //~7228I~
	    MessageBox(NULL,msgbuff,NULL,MB_OK);                       //~7228R~
    #else                                                          //~7228I~
	    printf("%s\n",msgbuff);                                    //~7228I~
    #endif                                                         //~7228I~
#endif
	return 0;
}//xeputty_errmsg
//**********************************************************************
//* get escstring
//**********************************************************************
int xeputty_getstr(int Plineno,char *Poutbuff,int Poutmaxlen,char *Pinpstr,int Pinplen)
{
	char *pci,*pco,*pcoe,*pcie;
    int errsw,len,ch;                                              //~7227R~
//************************
	pco=Poutbuff;
	pcoe=pco+Poutmaxlen;
    pci=Pinpstr;
    pcie=Pinpstr+Pinplen;
    errsw=0;
	for (;pci<pcie && pco<pcoe;)
    {
//printf("pci=%s\n",pci);
    	ch=*pci++;
    	if (ch=='^')
        {
        	if (pci==pcie)
            {
            	errsw=1;
            	break;
            }
            ch=*pci++;
            ch=toupper(ch);
//printf("^c=%x\n",ch);
            if (ch>0x40 && ch<0x5f)
            	*pco++=ch-0x40;
            else
            {
            	errsw=1;
            	break;
            }
        }
        else
    	if (ch=='\\')
        {
        	if (pci==pcie)
            {
            	errsw=1;
            	break;
            }
            ch=*pci++;
            ch=tolower(ch);
//printf("after \\=%x\n",ch);
            if (ch=='\\')
            	*pco++='\\';
            else
            if (ch=='^')
            	*pco++='^';
            else
            if (ch=='x')
            {
	        	if (pci+1>=pcie)
    	        {
        	    	errsw=1;
            		break;
            	}
                sscanf(pci,"%02x",&ch);
                *pco++=(char)ch;
                pci+=2;
            }
        }
        else
        	*pco++=ch;
    }
    if (errsw)
    {
    	xeputty_errmsg("%s:Line %3d:Esc string(%*.*s) format err",Smapfile,Plineno,Pinplen,Pinplen,Pinpstr);//~7228R~
        return -1;                                                 //~7227R~
    }
    if (pci<pcie && pco>=pcoe)
    {
    	xeputty_errmsg("%s:Line %3d:Esc string length err(max:%d) %*.*s",Smapfile,Plineno,XE_MAX_ESCSTRLEN,Pinplen,Pinplen,Pinpstr);//~7228R~
        return -1;                                                 //~7227I~
    }
    *pco=0;
    len=(int)((unsigned long)pco-(unsigned long)Poutbuff);         //~7228R~
    return len;                                                    //~7227R~
}//xeputty_getstr
//**********************************************************************
//* user key data output
//* rc:1 found,0:not found
//**********************************************************************
int xeputty_mapinit(char *Pmapfile)
{
    PUKNAMTBL puknt;
    PUKMAPTBL pukmt;
    int ii,rc=0,modx,errsw;
	int foundsw,keynmlen,strll;
    FILE *fh;
    char buff[512],*pc,*keynm,*keynme,*str,*stre;
    int applysw=0,keyupsw;                                         //~7228R~
    int  lineno=0,len,vkey,ch;                                     //~7228R~
    char *pfnm,*penv=0;                                            //~7301R~
#ifdef _WINDOWS                                                    //~7228I~
#else                                                              //~7228I~
    char fpath[512];                                               //~7301R~
#endif                                                             //~7228I~
//************************
    pfnm=Pmapfile;                                                 //~7301I~
    if (!pfnm)                                                     //~7301I~
    {                                                              //~7301I~
    	penv=getenv(XE_MAP_ENVVAR);                                //~7301R~
        if (penv && !*penv)                                        //~7301I~
        	penv=0;                                                //~7301I~
        pfnm=penv;                                                 //~7301I~
    	if (!pfnm)                                                 //~7301I~
			pfnm=XE_MAP_FILENAME;                                  //~7301I~
	}                                                              //~7301I~
#ifdef _WINDOWS                                                    //~7228R~
#else                                                              //~7228M~
    if (*pfnm=='~') //homedir                                      //~7301R~
    {                                                              //~7228I~
        pc=getenv("HOME");                                         //~7228I~
        if (pc)                                                    //~7228I~
            strcpy(fpath,pc);                                      //~7228I~
        else                                                       //~7228I~
            *fpath=0;                                              //~7228I~
        strcat(fpath,pfnm+1);                                      //~7301R~
    	pfnm=fpath;                                                //~7301I~
    }                                                              //~7228I~
    if (Pmapfile)                                                  //~7301I~
    	printf("# xeputty:Parameter key mapping file=%s.\n",pfnm);   //to console//+7301R~
    else                                                           //~7301I~
    if (penv)                                                      //~7301I~
    	printf("# xeputty:By env-var %s,key mapping file=%s.\n",XE_MAP_ENVVAR,pfnm);   //to console//+7301R~
    else                                                           //~7301I~
    	printf("# xeputty:By default,key mapping file=%s.\nIt may be configured by env-var %s\n",pfnm,XE_MAP_ENVVAR);   //to console//+7301R~
#endif                                                             //~7228I~
    Smapfile=pfnm;                                                 //~7301R~
    if (!(fh=fopen(pfnm,"r")))  //open input fail                  //~7228R~
    {
        xeputty_errmsg("key mapping file(%s) open err",pfnm);      //~7228R~
        return 4;
    }
    rc=0;
    while (fgets(buff,sizeof(buff),fh))
    {
//printf("line=%s\n",buff);                                        //~7228R~
        len=strlen(buff);
        if (len && *(buff+len-1)=='\n')
        	*(buff+(--len))=0;
        if (len && *(buff+len-1)=='\r')
        	*(buff+(--len))=0;
    	lineno++;
        pc=buff+strspn(buff," \t");
        if (*pc=='#'||*pc=='!'||!*pc)
        	continue;
        if (*pc=='[')	//termname section
        {
            pc++;
        	if (!memicmp(pc,XE_MAP_SECTION_PUTTY,sizeof(XE_MAP_SECTION_PUTTY)-1)//~7301R~
        	||  !memicmp(pc,XE_MAP_SECTION_COMMON,sizeof(XE_MAP_SECTION_COMMON)-1))//~7301I~
                applysw=1;
            else
            {                                                      //~7228I~
                applysw=0;
            }                                                      //~7228I~
            continue;	//section hdr
        }
        if (!applysw)
        	continue;
    	for (;;)
        {
        	errsw=1;
            if (!(pc=strstr(buff,XE_MAP_LINEHDR)))
            {
                xeputty_errmsg("%s:Line %3d:line format err:line-id \"%s\" is not found: %s",Smapfile,lineno,XE_MAP_LINEHDR,buff);//~7228R~
                break;
            }
            keynm=pc+sizeof(XE_MAP_LINEHDR)-1;
            keynm+=strspn(keynm," \t");
//*modifier
			if (*keynm==XE_MODID_KEYUP)                            //~7228I~
            {                                                      //~7228I~
            	keyupsw=1;                                         //~7228I~
                keynm++;                                           //~7228I~
            }                                                      //~7228I~
            else                                                   //~7228I~
            	keyupsw=0;                                         //~7228I~
            modx=0;
            if (*(keynm+1)=='+' && *keynm!='P') //modifier specified("P+" is num key "+")
            {
                for (ii=XE_MODID_MAX-1;ii>0;ii--)//longest match   //~7228R~
                {
                    len=strlen(Smodidt[ii]);
                    if (!memcmp(keynm,Smodidt[ii],(unsigned)len))  //~7228R~
                        break;
                }
            	if (!ii)	//unmatch
            	{
                	xeputty_errmsg("%s:Line %3d:Shift modifier err: %s",Smapfile,lineno,buff);//~7228R~
                	break;
            	}
                modx=ii;
                keynm+=len;
  		        keynm+=strspn(keynm," \t");
//printf("modid=%d\n",modx);                                       //~7228R~
            }
//*keyname
            keynme=strpbrk(keynm," \t,=");
            if (!keynme)
            {
                xeputty_errmsg("%s:Line %3d:line format err:no string found: %s",Smapfile,lineno,buff);//~7228R~
                break;
            }
            keynmlen=(int)((unsigned long)keynme-(unsigned long)keynm);
            if (keynmlen==1)	//charkey
            {
            	ch=*keynm;
                ch=toupper(ch);                                    //~7228R~
                if (modx<=XE_MODID_SHIFT)
	            {
    	            xeputty_errmsg("%s:Line %3d:Ctl or Alt modifier required for char key: %s",Smapfile,lineno,buff);//~7228R~
        	        break;
            	}
//              if (ch<0x20 || ch>=0x80)                           //~7228R~
//              {                                                  //~7228R~
//  	            xeputty_errmsg("%s:Line %3d:Invalid char key(%*.*s)",Smapfile,lineno,keynmlen,keynmlen,keynm);//~7228R~
//      	        break;                                         //~7228R~
//          	}                                                  //~7228R~
                vkey=ch;                                           //~7228R~
                foundsw=2;
            }
            else
            {
                foundsw=0;
                for (puknt=Suknamt;puknt->UKNTvkey;puknt++)
                {
                    if (keynmlen==(int)strlen(puknt->UKNTkeyname)
                    &&  !memicmp(puknt->UKNTkeyname,keynm,keynmlen))
                    {
                        foundsw=1;
                        break;
                    }
                }
                if (!foundsw)
                {
                    xeputty_errmsg("%s:Line %3d:keyname (%.*s) is invalid: %s",Smapfile,lineno,keynmlen,keynm,buff);//~7228R~
                    break;
                }
	            vkey=puknt->UKNTvkey;                              //~7228I~
DEBUGLOG(sprintf(Sdebugbuff,"prefined key vkey=%x,name=%s\n",vkey,puknt->UKNTkeyname));//~7301I~
            }
        	pc=strchr(keynme,'=');
            if (!pc)
            {
                xeputty_errmsg("%s:Line %3d:line format err:no string found: %s",Smapfile,lineno,buff);//~7228R~
                break;
            }
            pc++;
            pc+=strspn(pc," \t");
            str=pc;
            stre=strpbrk(str," #\t,");
            if (stre)
                strll=(int)((unsigned long)stre-(unsigned long)str);
            else
                strll=(int)strlen(str);
            if (!strll)	//null
            {
                errsw=0;
            	break;		//ignore
            }
#ifdef _WINDOWS                                                    //~7228I~
            pukmt=Sukmapt+(vkey&0xff);                             //~7228R~
#else                                                              //~7228I~
			if (foundsw==2)	//char key                             //~7228I~
    	        pukmt=Sukmapt+vkey+XE_MAPT_MAXENT/2;	//2nd half by upper case//~7228I~
            else                                                   //~7228I~
    	        pukmt=Sukmapt+(vkey&0xff);  	//GDK_xx is FFxx   //~7228I~
#endif                                                             //~7228I~
            pukmt->UKMTvkey=vkey;                                  //~7228R~
            if (foundsw==2)                                        //~7228I~
				pukmt->UKMTflag|=UKMTF_CHARKEY;  //not predefined numonic key name//~7228I~
            if (keyupsw)                                           //~7228I~
				pukmt->UKMTflag|=UKMTF_KEYUP;    //send when keyup event//~7228I~
            pc=pukmt->UKMTescstr[modx];
            if (*pc)
            {
                xeputty_errmsg("%s:Line %3d:keyname (%s%.*s) is duplicated: %s",Smapfile,lineno,Smodidt[modx],keynmlen,keynm,buff);//~7228R~
                break;
            }
            if ((len=xeputty_getstr(lineno,pc,XE_MAX_ESCSTRLEN,str,strll))<=0)//~7227R~
            	break;
//printf("getstr=%s\n",pc);                                        //~7228R~
            pukmt->UKMTescstrlen[modx]=len;                        //~7227I~
DEBUGLOG(sprintf(Sdebugbuff,"mapfile vkey=%x,modx=%d,str=%s\n",pukmt->UKMTvkey,modx,pukmt->UKMTescstr[modx]));//~7301R~
            errsw=0;
            break;
        }//err break loop
        rc+=errsw;                                                 //~7227M~
#ifdef TESTMAIN                                                    //~7227I~
#else                                                              //~7227I~
	#ifdef _WINDOWS                                                //~7228I~
        if (errsw)	    //issue only onec popup err msg            //~7228R~
        	break;
    #endif                                                         //~7228I~
#endif                                                             //~7227I~
    }//while                                                       //~7228R~
    fclose(fh);                                                    //~7228I~
    return rc;
}//xeputty_mapinit
#ifdef _WINDOWS                                                    //~7228I~
//**********************************************************************//~7227I~
//* translation by parameter file                                  //~7227R~
//* rc: 0:pass to puTTY,-1:pass to DefWindowProc,len=string length to be send//~7227I~
//**********************************************************************//~7227I~
static int xeputty_TranslateKey(unsigned message, WPARAM wParam, LPARAM lParam,//~7228R~
			unsigned char *output)                                 //~7227I~
{                                                                  //~7227I~
	static int Sinitsw=0;                                          //~7227I~
    char *pescstr;                                                 //~7227I~
    PUKMAPTBL pukmt;                                               //~7227I~
    int modall,modx,len,rc,vkey;                                   //~7227R~
//************************                                         //~7227I~
DEBUGLOG(sprintf(Sdebugbuff,"translatekey message=%x,wparam=%x,lparm=%x\n",message,wParam,lParam))//~7228R~
	if (!Sinitsw)                                                  //~7227I~
    {                                                              //~7227I~
		rc=xeputty_mapinit(0);                                     //~7301R~
        if (rc)                                                    //~7227I~
        	Sinitsw=-1;                                            //~7227I~
        else                                                       //~7227I~
        	Sinitsw=1;                                             //~7227I~
    }                                                              //~7227I~
    if (Sinitsw<0)                                                 //~7227I~
    	return 0;                                                  //~7227I~
    vkey=wParam;                                                   //~7227I~
    if (vkey>=256)                                                 //~7228I~
        return 0;                                                  //~7228I~
    pukmt=Sukmapt+vkey;                                            //~7228R~
    if (!pukmt->UKMTvkey)	//no definition from parm file         //~7227I~
        return 0;                                                  //~7227I~
//get shift status                                                 //~7227I~
	modall=0;                                                      //~7227R~
    if (GetKeyState(VK_SHIFT) & 0x8000)     //shift key down       //~7227I~
    	modall|=0x01;                                              //~7227I~
    if (GetKeyState(VK_CONTROL) & 0x8000)   //ctl key down         //~7227I~
    	modall|=0x02;                                              //~7227I~
    if (GetKeyState(VK_MENU) & 0x8000)      //alt ket down         //~7227I~
    	modall|=0x04;                                              //~7227I~
DEBUGLOG(sprintf(Sdebugbuff,"translatekey shiftstatus=%x\n",modall))//~7228I~
    modx=Smodidxtb[modall];                                        //~7227I~
    pescstr=pukmt->UKMTescstr[modx];                               //~7227R~
DEBUGLOG(sprintf(Sdebugbuff,"translatekey modx=%d,escstr=%s\n",modx,pescstr))//~7228I~
    len=pukmt->UKMTescstrlen[modx];                                //~7227R~
    if (!len)                                                      //~7227I~
    	return 0;	//no parm definition                           //~7227I~
    if (pukmt->UKMTflag & UKMTF_KEYUP)     //msg by key up         //~7228I~
    {                                                              //~7228I~
	    if (message==WM_KEYDOWN||message==WM_SYSKEYDOWN)           //~7228R~
	    	return -1;								//process key up,keydown is not pass to puTTY//~7228R~
    }                                                              //~7228I~
    else                                    //msg by keydown       //~7228I~
    {                                                              //~7228I~
	    if (message==WM_KEYUP||message==WM_SYSKEYUP)               //~7228I~
	    	return -1;								//process key down,keyup is not pass to puTTY//~7228I~
    }                                                              //~7228I~
    memcpy(output,pescstr,(unsigned)(len+1));                      //~7228R~
DEBUGLOG(sprintf(Sdebugbuff,"translatekey len=%d,outstr=%s\n",len,output))//~7228I~
	return len;                                                    //~7227I~
}//xe_TranslateKey                                                 //~7227I~
#else	//LNX                                                      //~7228I~
//**********************************************************************//~7228I~
//* translation by parameter file                                  //~7228I~
//* rc: 0:pass to puTTY,-1:pass to DefWindowProc,len=string length to be send//~7228I~
//**********************************************************************//~7228I~
int xeputty_TranslateKey(GtkWidget *widget, GdkEventKey *event,char *output)//~7228I~
{                                                                  //~7228I~
	static int Sinitsw=0;                                          //~7228I~
    char *pescstr;                                                 //~7228I~
    PUKMAPTBL pukmt;                                               //~7228I~
    int modall,modx,len,rc,vkey;                                   //~7228I~
//************************                                         //~7228I~
DEBUGLOG(sprintf(Sdebugbuff,"translatekey Type=x%x,State=x%x,keyval=x%x\n",event->type,event->state,event->keyval));//~7228R~
	if (!Sinitsw)                                                  //~7228I~
    {                                                              //~7228I~
		rc=xeputty_mapinit(0);                                     //~7301R~
        if (rc)                                                    //~7228I~
        {                                                          //~7301I~
        	Sinitsw=-1;                                            //~7228I~
            printf("keymapping function is in-activated\n");       //~7301R~
        }                                                          //~7301I~
        else                                                       //~7228I~
        {                                                          //~7301I~
        	Sinitsw=1;                                             //~7228I~
            printf("keymapping function is activated\n");          //~7301R~
        }                                                          //~7301I~
    }                                                              //~7228I~
    if (Sinitsw<0)                                                 //~7228I~
    	return 0;                                                  //~7228I~
    vkey=event->keyval;                                            //~7228I~
	if (vkey & 0xff00)		//virtual key	                       //~7228I~
	    pukmt=Sukmapt+(vkey&0xff);                                 //~7228R~
    else                                                           //~7228I~
	    pukmt=Sukmapt+toupper(vkey)+XE_MAPT_MAXENT/2;	//map table index is by upper case char//~7228R~
    if (!pukmt->UKMTvkey)	//no definition from parm file         //~7228I~
        return 0;                                                  //~7228I~
//get shift status                                                 //~7228I~
	modall=0;                                                      //~7228I~
    if (event->state & GDK_SHIFT_MASK)     //shift key down        //~7228I~
    	modall|=0x01;                                              //~7228I~
    if (event->state & GDK_CONTROL_MASK)   //ctl key down          //~7228I~
    	modall|=0x02;                                              //~7228I~
    if (event->state & GDK_MOD1_MASK)      //alt ket down          //~7228I~
    	modall|=0x04;                                              //~7228I~
DEBUGLOG(sprintf(Sdebugbuff,"translatekey shiftstatus=%x\n",modall))//~7228I~
    modx=Smodidxtb[modall];                                        //~7228I~
    pescstr=pukmt->UKMTescstr[modx];                               //~7228I~
DEBUGLOG(sprintf(Sdebugbuff,"translatekey modx=%d,escstr=%s\n",modx,pescstr))//~7228I~
    len=pukmt->UKMTescstrlen[modx];                                //~7228I~
    if (!len)                                                      //~7228I~
    	return 0;	//no parm definition                           //~7228I~
    if (pukmt->UKMTflag & UKMTF_KEYUP)     //msg by key up         //~7228I~
    {                                                              //~7228I~
	    if (event->type==GDK_KEY_PRESS)                            //~7228I~
	    	return -1;								//process key up,keydown is not pass to puTTY//~7228I~
    }                                                              //~7228I~
    else                                    //msg by keydown       //~7228I~
    {                                                              //~7228I~
	    if (event->type==GDK_KEY_RELEASE)                          //~7228I~
	    	return -1;								//process key down,keyup is not pass to puTTY//~7228I~
    }                                                              //~7228I~
    memcpy(output,pescstr,(unsigned)(len+1));                      //~7228I~
DEBUGLOG(sprintf(Sdebugbuff,"translatekey len=%d,outstr=%s\n",len,output))//~7228I~
	return len;                                                    //~7228I~
}//xeputty_TranslateKey                                            //~7228I~
#endif	//!_WINDOWS                                                //~7228R~
#ifdef TESTMAIN
//**********************************************************************
//* print esc seq string
//**********************************************************************
int printstr(char *Pstr)
{
	char *pc,ch;
//************************
	for (pc=Pstr;ch=*pc,ch;pc++)
    {
    	if (ch<0x20)
        {
        	ch+=0x40;
            ch=tolower(ch);
        	printf("^%c",ch);
        }
        else
    	if (ch=='^')
        	printf("\\^");
        else
    	if (ch=='\\')
        	printf("\\\\");
        else
    	if (ch<0x7f)
        	printf("%c",ch);
        else
        	printf("\\x%02x",ch);
    }
    return 0;
}//printttkey
//**********************************************************************
//* print default string for teraterm
//*
//**********************************************************************
int printmap(void)
{
	int ii,jj;
    char *pc,keyup;                                                //~7228R~
    PUKNAMTBL puknt;
    PUKMAPTBL pukmt;
    char editkey[32];                                              //~7301I~
//************************
	printf("### keymapping table print ###\n");
	printf("[%s]\n",XE_MAP_SECTION_PUTTY);
//funckey
    for (puknt=Suknamt;puknt->UKNTvkey;puknt++)
    {
    	pukmt=Sukmapt+(puknt->UKNTvkey & 0xff);                    //~7228R~
    	for (ii=0;ii<XE_MODID_MAX;ii++)
        {
        	pc=pukmt->UKMTescstr[ii];
        	if (!ii || *pc)
            {
            	if (pukmt->UKMTflag & UKMTF_KEYUP)                 //~7228I~
                	keyup=XE_MODID_KEYUP;                          //~7228I~
                else                                               //~7228I~
                	keyup=' ';                                     //~7228I~
//			    printf("%s%c%-6s%-10s=",XE_MAP_LINEHDR,keyup,Smodidt[ii],puknt->UKNTkeyname);//~7301R~
  			    sprintf(editkey,"%s%s",Smodidt[ii],puknt->UKNTkeyname);//~7301R~
  			    printf("%s%c%-16s=",XE_MAP_LINEHDR,keyup,editkey); //~7301R~
                if (*pc)
			    	printstr(pc);
                printf("\n");
            }
        }

    }
//charkey
    for (pukmt=Sukmapt,jj=0;jj<XE_MAPT_MAXENT;pukmt++,jj++)        //~7228R~
    {
		if (!(pukmt->UKMTflag & UKMTF_CHARKEY))  //not predefined numonic key name//~7228I~
        	continue;                                              //~7228I~
    	for (ii=0;ii<XE_MODID_MAX;ii++)
        {
        	pc=pukmt->UKMTescstr[ii];
        	if (*pc)
            {
            	if (pukmt->UKMTflag & UKMTF_KEYUP)                 //~7228I~
                	keyup=XE_MODID_KEYUP;                          //~7228I~
                else                                               //~7228I~
                	keyup=' ';                                     //~7228I~
//  		    printf("%s%c%-6s%c         =",XE_MAP_LINEHDR,keyup,Smodidt[ii],pukmt->UKMTvkey);//~7301R~
  		    	sprintf(editkey,"%s%c",Smodidt[ii],pukmt->UKMTvkey);//~7301R~
    		    printf("%s%c%-16s=",XE_MAP_LINEHDR,keyup,editkey); //~7301R~
			    printstr(pc);
                printf("\n");
            }
        }
    }
	printf("### end of [%s] ###\n",XE_MAP_SECTION_PUTTY);
    return 0;
}//printttkey
//*********************************************************************
//*main
//*********************************************************************
int main(int parmc,char *parmp[])
{
	char *mapfnm;
    int ii;
//*************************
  	if (parmc<2) //no parm
  	{
    	printf("%s:%s:format check keymapping file for puTTY\n",XE_PGMID,XE_VER);
    	printf("usage:  %s mapping-filename\n",XE_PGMID);
    	printf("  mapping-file line format. (copy to %s when apply to puTTY)\n",XE_MAP_FILENAME);//~7227R~
    	printf("    [%s]   (This is required header line. [%s] is also OK)\n",XE_MAP_SECTION_PUTTY,XE_MAP_SECTION_COMMON);//~7301I~
		printf("    %s[up]mod keyname=string\n",XE_MAP_LINEHDR);   //~7228R~
		printf("        up     :specify \"%c\" if send string at keyup event\n",XE_MODID_KEYUP);//~7228R~
		printf("        mod    :");                                //~7228R~
        for (ii=1;ii<XE_MODID_MAX;ii++)
        {
            printf("%s  ",Smodidt[ii]);
        }
		printf("(optional)\n");
    	printf("        kayname:valid id is printed by \"%s %c\".\n",XE_PGMID,XE_MAP_NULLFILE);//~7228R~
    	printf("        string :specify using \\xhh(hex-decimal) or \"^[\"(0x1b) \"^a\"(0x01).\n");//~7228R~
		printf("ex) %s %-6s%-10s=%s\n",XE_MAP_LINEHDR,Smodidt[1],Suknamt[0].UKNTkeyname,"^[1~");//~7228R~
		printf("    %s %-6s%-10s=%s\n",XE_MAP_LINEHDR,Smodidt[0],Suknamt[1].UKNTkeyname,"\\x1b\\x32A\\^\\\\^x    # 0x1b32415e5c18");//~7228R~
		printf("    %s%c%-6s%-10s=%s\n",XE_MAP_LINEHDR,XE_MODID_KEYUP,Smodidt[6],"a","^[13~              # send string at KeyUp event");//~7228R~
    	printf("(\"#\" is start of comment. The line with no string is ignored.)\n");//~7227M~
    	exit(4);
  	}
    mapfnm=parmp[1];
	printf("### keymapping file=%s ###\n",mapfnm);
    if (*mapfnm!=XE_MAP_NULLFILE)
		xeputty_mapinit(mapfnm);
    printmap();
  	return 0;
}//end main
#endif
