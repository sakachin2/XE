//*CID://+v525R~:                             update#=  132;       //~v525R~
//***********************************************************
//* XBG     : grep for binary file
//***********************************************************
//v525:030819 force TTERM env(kbd and viol) option                 //~v525I~
//v51Y:030802 (AIX) key option for 7f force to BS/DEL/CHAR for also AIX//~v51YI~
//001115 v1.0: first release
//***********************************************************
//**********************************************/
//*parm  : see ttmaphelp()                          */             //~1123R~
//*return: 0:normal                            */
//*        else error                          */
//**********************************************/
//***********************************************************
#define VER "V1.0"   //version
#define PGMID   "xettmap"                                          //~0B15R~
//*************************************************************
//*************************************************************
#include <time.h>     
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    
#include <string.h>   
#include <unistd.h>                                                //~0B23I~
#include <ucurses.h>                                               //~0B23I~

#include <ulib.h>
#include <uerr.h>
#include <ukbdl.h>                                                 //~v525I~
#include <ukbdaixt.h>                                              //~0B15R~
#include <uunxsub.h>                                               //~0B18I~
#include <uvio.h>                                                  //~0B23I~
#include <uvio2.h>                                                 //~0B23I~
#include <uviol.h>                                                 //~0B23I~
//*********************************************************************
//*********************************************************************
static  int Smodvalue[FKT_MAX_SYM+1]={0,        //add value to plaine keycode modifier key//~0B23R~
                      0x200,                                       //~0B15M~
                      0x400,                                       //~0B15M~
                      0x600,    //shift+ctl for alternative of alt //~0B23R~
                      0x800     //alt                              //~0B23I~
                      };                                           //~0B15M~
static  char *Smodname[FKT_MAX_SYM+1]={"",        //add value to plaine keycode modifier key//~0B23R~
                      "+Shift",                                    //~0B15M~
                      "+Ctrl",                                     //~0B15M~
                      "+Shift+Ctrl",    //shift+ctl for alternative of alt//~0B23R~
                      "+Alt"     //use Alt key                     //~0B23I~
                      };                                           //~0B15M~
static int Suerrmsgopt=0;                                          //~0B20R~
static char Slineid[]=TTSTRLINEID2;                                //~0B23R~
static char Slineid2[]="Keycode=";                                 //~0B20R~
static char Slineid3[]=TTSTRLINEID;                                //~0B23R~
static char Spgmver[18];                                           //~0B18I~
static  char *Sshiftidstr[]={"","S+","C+","A+"};                   //~v51YI~
static char Sttstrlineid[]=TTSTRLINEID; //string=                  //~v51YI~
//****************************************************             //~0B15R~
int userkeyproc(int Paltsw,int Pmsgsw);                            //~0B23R~
int strchk(void);                                                  //~0B23R~
void ttmaphelp(void);                                              //~1123R~
int printttkey(PFUNCKEYTBL Ppfkt,int Pmodx,int Pentno);            //~v51YI~
//*********************************************************************
int main(int parmc,char *parmp[])
{
	char *cptr,*fnm=0,ch;       //char ptr work                    //~0B23R~
	int parmno,altsw=0,strchksw=0,msgsw=0; //parm count work       //~0B23R~
	int posparmno=0; //parm count work
//*************************
	sprintf(Spgmver,"%s:%s:",PGMID,VER);                           //~0B18R~
  	uerrmsg_init("",stdout,0);//default color                      //~0B18R~
	uerrexit_init(Spgmver,stdout,0,0,0);//no mapfile,no exit,no exit parm//~0B18R~

  	if (parmc<2) //no parm
  	{
    	ttmaphelp();                                               //~1123R~
    	exit(4);
  	}
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
  		if(*cptr=='-')                                             //~0B18R~
  		{//option
    		ch=*(++cptr);                      //first option byte
    		if (*(++cptr)==':')               // /o:x format
      			cptr++;                         //skip :
    		switch(toupper(ch))       //option
    		{
//**************************
//* help msg      /H*
//**************************
    		case '?':
    		case 'H':
	  			ttmaphelp();                                       //~1123R~
      			exit(4);
      			break;
//**************************                                       //~0B18I~
//* display       /A*                                              //~0B23R~
//**************************                                       //~0B18I~
    		case 'A':                                              //~0B23R~
	  			altsw=1;                                           //~0B23R~
      			break;                                             //~0B18I~
//**************************                                       //~0B23I~
//* display       /A*                                              //~0B23I~
//**************************                                       //~0B23I~
    		case 'K':                                              //~0B23I~
	  			strchksw=1;                                        //~0B23I~
      			break;                                             //~0B23I~
//**************************                                       //~0B23I~
//* display       /S*                                              //~0B23I~
//**************************                                       //~0B23I~
    		case 'S':                                              //~0B23I~
	  			altsw=0;        //use shift+ctrl                   //~0B23I~
      			break;                                             //~0B23I~
//**************************
//* set option     */Y
//**************************
   	 		case 'Y':
	  			while (*cptr)
	  			{
	      			switch (toupper(*cptr))
    	  			{
	      			case '9':   //offset disply for test           //~0B15I~
						Suerrmsgopt=(Suerrmsgopt & ~UERR_FORCE_ENGLISH);//~0B15I~
    					uerrmsg_init(0,stdout,Suerrmsgopt);//msg to stdout//~0B15I~
	        			break;                                     //~0B15I~
	      			case 'D':   //dupchk                           //~0B23I~
						msgsw=1;                                   //~0B23I~
	        			break;                                     //~0B23I~
	      			default:
						uerrexit("\nToggle Set parm(%s) err",
								"\nトグル設定(%s)エラー",
								parmp[parmno]);
	      			}//switch by /Nx
		  			cptr++;
      			}//until strlen
      			break;
//**************************
//* reset option     */N
//**************************
    		case 'N':
	  			while (*cptr)
	  			{
	      			switch (toupper(*cptr))
    	  			{
	      			case '9':   //offset disply for test           //~0B15I~
						Suerrmsgopt=(Suerrmsgopt|UERR_FORCE_ENGLISH);//~0B15I~
    					uerrmsg_init(0,stdout,Suerrmsgopt);//msg to stdout//~0B15I~
	        			break;                                     //~0B15I~
	      			case 'D':   //dupchk                           //~0B23I~
						msgsw=0;                                   //~0B23I~
	        			break;                                     //~0B23I~
	      			default:
						uerrexit("\nToggle Reset parm(%s) err",
									"\nトグル設定解除(%s)エラー",
									parmp[parmno]);
	      			}//switch by /Nx
		  		cptr++;
      			}//until strlen
      			break;
//**************************
//* option err             *
//**************************
    		default:                           //not option
				uerrexit("\nundefined option parm(%s)",
						"\n%s は認識できません",
							parmp[parmno]);
    		}//switch  by first option byte
  		}
  		else
  		{//positional parmno
    		posparmno++;
    		switch (posparmno)
    		{
//**************************
//* keycode map file       *                                       //~0B15R~
//**************************
    		case  1:          //first parm                         //~0B15R~
      			fnm=cptr;                                          //~0B23R~
      			break;
//************************************
    		default:
	 			uerrexit("too many positional parameter(%s)",      //~0B15R~
						"パラメータが多過ぎます(%s)",              //~0B15R~
						cptr);
    		}//switch by parmno
  		}//option or posparm
	}//for all parm
//*****************************
//* main loop                 *
//*****************************
	if (strchksw)                                                  //~0B23I~
    	strchk();                                                  //~0B23I~
    else                                                           //~0B23I~
    {                                                              //~0B23I~
    	if (fnm)                                                   //~0B23I~
//      	ukbdaixt_chngttkey(fnm);                               //~v525R~
        	ukbdaixt_chngttkey(UKBDL_TNTT,fnm);                    //~v525I~
		userkeyproc(altsw,msgsw);                                  //~0B23R~
    }                                                              //~0B23I~
  	return 0;                                                      //~0B15R~
}//end main

//**********************************************************************
//* user key data output                                           //~0B23R~
//* rc:1 found,0:not found
//**********************************************************************
int userkeyproc(int Paltsw,int Pmsgsw)                             //~0B23R~
{
	PFUNCKEYTBL pfkt,*ppfkt;                                       //~0B18R~
    int ii,modx,pfktno,keycode,userkeyid,userkeyno=0,charcode,scancode;//~0B18R~
	int doskey,rc=0,modx2;                                         //~0B23R~
    int jj;                                                        //~v51YI~
    char *keynm;                                                   //~0B18R~
//************************                                         //~0B15I~
//  unc_setupterm(0);//curses terminfo read                        //~0B23R~
    Gkbdaixt_opt|=GKBAIX_TTERM;    //force teraterm,parm to ukbdaixt_setupckt//~v525R~
	pfktno=ukbdaixt_setupuserkey(&ppfkt,Pmsgsw);//char keyno       //~0B23R~
//output teraterm .cnf file user key definition segment            //~0B15I~
    for (ii=0;ii<pfktno;ii++,ppfkt++)        //keycode             //~0B18R~
    {                                                              //~0B15I~
    	pfkt=*ppfkt;		//ptr tbl                              //~0B18I~
        keycode=pfkt->FKTkeycode;                                  //~0B18I~
        keynm=pfkt->FKTkeyname;                                    //~1308R~
    	for (modx=0;modx<FKT_MAX_SYM;modx++)                       //~0B18R~
        {                                                          //~0B18I~
            doskey=pfkt->FKTdoskey[modx];                          //~0B18R~
            charcode=doskey & 255;                                 //~0B18I~
            scancode=(int)((unsigned)doskey>>8);                   //~0B20R~
            modx2=modx;                                            //~0B23I~
            if (modx2==3 && Paltsw)                                //~0B23I~
            	modx2=4;                                           //~0B23I~
            if (modx)                                              //~0B18R~
                printf(";;#                                      @         %-9s%s\n",//~0B18R~
                        keynm,Smodname[modx2]);                    //~0B23R~
            else                                                   //~0B18R~
                printf(";;#                                      @ %s%-9s,%s%3d\n",//~0B18R~
                        Slineid,keynm,Slineid2,keycode);           //~0B18R~
    		if (!(userkeyid=pfkt->FKTfkassign[modx]))              //~0B23M~
            	continue;                                          //~0B23M~
            for (jj=0;jj<FKT_MAX_STR;jj++)                         //~v51YR~
                if (pfkt->FKTflag[modx][jj]==FKT_TTORGKEY)         //~v51YI~
                    break;                                         //~v51YI~
//          if (userkeyid==FKT_TTUSERKEY)   //teraterm Userxx      //~v51YR~
            if (jj>=FKT_MAX_STR)             //teraterm Userxx     //~v51YI~
            {                                                      //~0B22I~
                userkeyno++;                                       //~0B22I~
//                if (charcode)   //char code+modifier             //~1308R~
//                    printf("User%d=%d,0,$%02X%c%02X%c%02X%c%02X\n",  //$1b$7e$58$00//~1308R~
//                            userkeyno,Smodvalue[modx2]+keycode,  //~1308R~
//                            0x1b,'$',FUNCSTRID,'$',scancode,'$',modx);//~1308R~
//                else                                             //~1308R~
//                    printf("User%d=%d,0,$%02X%c%02X%c%02X%c%02X\n",  //$1b$7e$58$00//~1308R~
//                            userkeyno,Smodvalue[modx2]+keycode,  //~1308R~
//                            0x1b,'$',FUNCSTRID,'$',scancode,'$',charcode);//~1308R~
                printf("User%d=%d,0,$%02X%c%02X%c%02X%c%02X%c%02X\n",  //$1b$7e$58$00//~1308I~
                        userkeyno,Smodvalue[modx2]+keycode,        //~1308I~
                        0x1b,'$',FUNCSTRID,'$',scancode,'$',charcode,'$',modx);//~1308I~
            }                                                      //~0B22I~
            else                                                   //~0B22R~
//  			ukbdaixt_printttkey(pfkt,modx);                    //~v51YR~
    			printttkey(pfkt,modx,jj);                          //~v51YR~
        }//4 shift                                                 //~0B18I~
    }                                                              //~0B15I~
    if (rc)                                                        //~0B18M~
    {                                                              //~0B18I~
    	uerrmsg("map file has some error",0);                      //~0B18I~
    	ubell();                                                   //~0B18M~
    }                                                              //~0B18I~
    return rc;                                                     //~0B18R~
}//userkeyproc                                                     //~0B23R~
//**********************************************************************//~v51YI~
//* print default string for teraterm                              //~v51YI~
//*                                                                //~v51YI~
//**********************************************************************//~v51YI~
int printttkey(PFUNCKEYTBL Ppfkt,int Pmodx,int Pentno)             //~v51YI~
{                                                                  //~v51YI~
	char *typ;                                                     //~v51YI~
    char keynm[32];                                                //~v51YI~
//************************                                         //~v51YI~
//  if (Ppfkt->FKTfkassign[Pmodx]==FKT_TTORGKEY)                   //~v51YI~
    if (Ppfkt->FKTflag[Pmodx][Pentno]==FKT_TTORGKEY)               //~v51YI~
    	typ="ORG";                                                 //~v51YI~
    else                                                           //~v51YI~
    	typ="REP";                                                 //~v51YI~
    sprintf(keynm,"%s%s",Sshiftidstr[Pmodx],Ppfkt->FKTkeyname);    //~v51YI~
	printf(";;#          %s %s%-9.*s=^[%s\n",                      //~v51YI~
                        typ,                                       //~v51YI~
                        Sttstrlineid,                              //~v51YI~
						(int)strlen(keynm),                        //~v51YI~
						keynm,                                     //~v51YI~
//  					Ppfkt->FKTttstring[Pmodx]+1);              //+v525R~
    					Ppfkt->FKTttstring[Pmodx][Pentno]+1);      //+v525I~
    return 0;                                                      //~v51YI~
}//printttkey                                                      //~v51YI~
//**********************************************************************//~0B23I~
//* strchk;display string by key                                   //~0B23I~
//* rc:1 found,0:not found                                         //~0B23I~
//**********************************************************************//~0B23I~
int strchk(void)                                                   //~0B23I~
{                                                                  //~0B23I~
	int len,ii,ch,y,x;                                             //~0B23R~
    char buff[10];                                                 //~0B23R~
    char xbuff[24];                                                //~0B23R~
    char lbuff[81];                                                //~0B23I~
//************************                                         //~0B23I~
//  unc_setupterm(0);//curses terminfo read                        //~0B23R~
//  initscr();                                                     //~0B23R~
    uviol_init(0);                                                 //~0B23R~
    nl();                                                          //~0B23I~
	printw("Press any key,enter 'q' to quit\n");                   //~0B23I~
    refresh();                                                     //~0B23I~
//  keypad(stdscr,FALSE);                                          //~0B23R~
//  raw();                                                         //~0B23R~
//  nonl();                                                        //~0B23R~
//  noecho();                                                      //~0B23R~
	for (;;)                                                       //~0B23I~
    {                                                              //~0B23I~
    	len=read(0,buff,sizeof(buff));                             //~0B23I~
        for (ii=0;ii<len;ii++)                                     //~0B23I~
        	sprintf(xbuff+ii+ii,"%02X",buff[ii]);                  //~0B23R~
        *(xbuff+len+len)=0;                                        //~0B23R~
        memset(lbuff,' ',80);                                      //~0B23I~
        sprintf(lbuff,"%-20s",xbuff);                              //~0B23R~
        for (ii=0;ii<len;ii++)                                     //~0B23I~
        {                                                          //~0B23I~
        	ch=buff[ii];                                           //~0B23I~
        	if (ch<0x20||ch>=0x7f)                                 //~0B23I~
            	ch='.';                                            //~0B23I~
            lbuff[20+ii]=ch;                                       //~0B23R~
        }                                                          //~0B23I~
        lbuff[80]=0;                                               //~0B23I~
        uviogetcurpos(&y,&x);                                      //~0B23R~
        uviowrtcharstr(lbuff,COLS,y,0);                            //~0B23R~
        if (y>=LINES-1)                                            //~0B23R~
        	uvioscrollup(2,0,LINES-1,COLS-1,1," \x00");            //~0B23R~
        else                                                       //~0B23I~
        	y++;                                                   //~0B23I~
        move(y,0);                                                 //~0B23R~
        refresh();                                                 //~0B23I~
        if (len==1 && (ch=='q'||ch=='Q'))                          //~0B23R~
        	break;                                                 //~0B23I~
    }                                                              //~0B23I~
//  endwin();                                                      //~0B23R~
    uviol_term();                                                  //~0B23I~
    return 0;                                                      //~0B23I~
}//strchk                                                          //~0B23I~
//**********************************************************************
//* write help msg  
//**********************************************************************
void ttmaphelp(void)                                               //~1123R~
{
//*******************
	uerrmsg("%s =(%c)==================== %s ============================",0,//~0B23I~
			Spgmver,OSTYPE,__DATE__);                              //~0B23I~
	uerrmsg("Generate [User keys] section data of Tera Term keyboard.cnf file for xe.",//~0B23I~
			"xe用の Tera Term keyboard.cnf ファイル [User keys]セクションデータ生成.");//~0B23I~
	uerrmsg("    Format: %s {-a|-s|-k}",                           //~0B23I~
			"    形式  : %s {-a|-s|-k}",                           //~0B23I~
			PGMID);                                                //~0B23I~
	uerrmsg("      -a  :Use Alt key combination.",                 //~0B23I~
			"      -a  :Altキーとの組あわせを使用する。");         //~0B23I~
	uerrmsg("      -s  :Use Shif+Cntl for alternative of Alt key.",//~0B23I~
			"      -s  :Altキーの代わりにShift+Ctrlキーを使用する。");//~0B23I~
	uerrmsg("      -k  :Display string transfered.",               //~0B23I~
			"      -k  :転送文字列の\x95\\示。");                  //~0B23I~
	uerrmsg("       *Tera Term is terminal emulator by T.Teranishi.",//~0B23I~
			"       *Tera Term は T.Teranishi氏による端末Emulatorです。");//~0B23I~
	uerrmsg("       *xe is another editor(for AIX) on Tera Term.", //~0B23I~
			"       *xe は Tera Term 上で動く １つのEditorです(AIX版)。");//~0B23I~
	uerrmsg("  Keyboard.cnf is keyboard mapping file.",            //~0B23I~
			"  keyboard.cnf は キーボードマッピングを指定するファイルです。");//~0B23I~
	uerrmsg("  Mapping file can be changed(newly loaded) by menu option.",//~0B23I~
			"  マッピングファイルはメニューから再設定できます。"); //~0B23I~
	uerrmsg("  To use xe,set this PGM output to [User keys] section of .cnf file.",//~0B23I~
			"  xeを使用する場合このPGMの出力を[User keys]セクションに設定してください。");//~0B23I~
	uerrmsg("  Tera Term offer the function to transfer any string by a key hit.",//~0B23I~
			"  Tera Termにはキー操作で任意の文字列を転送する機\x94\\があります。");//~0B23R~
	uerrmsg("  For ex,when \"User1=571,0,$1b$7e$54$00\" is coded,",//~0B23I~
			"  例えば、”User1=571,0,$1b$7e$54$00”を 指定すると キーコード 571で");//~0B23I~
	uerrmsg("  by pressing keycode 571,0x1b7e5400 is transfered. 571 is Shift+F1.",//~0B23I~
			"  1b7e5400 が転送されます。571 は Shift+F1です。");   //~0B23I~
	uerrmsg("  Keycode.exe in Tera Term dir is for checking keycode value.",//~0B23I~
			"  キーコード値は Tera Term 付属の keycode.exe で確認してください。");//~0B23I~
	uerrmsg("  Using this function and assigning scancode/charcode to keycodes,",//~0B23I~
			"  xeではユーザーキーにスキャンコード・文字コードを割り当てることにより");//~0B23I~
	uerrmsg("  xe detect key and shift status.",                   //~0B23I~
			"  キーとシフト状況を判別します。");                   //~0B23I~
	uerrmsg("  For the case of charkey(charcode!=0),charcode pos is used for modifierID.",//~0B23R~
	        "  文字キー(文字コード！=0)の場合はその位置をシフト状況に使用します。");//~0B23R~
	uerrmsg("  ModifierID = 01:Shift, 2:Ctrl, 3:Alt.",             //~0B23I~
	        "  シフト状況は 01:Shift, 02:Ctrl, 03:Alt です。");    //~0B23I~
	uerrmsg("  For ex, $1b$7e$0e$01 is Shift+Backspace.",          //~0B23R~
	        "  例えば、$1b$7e$0e$01 は Shift+Backspace です。");   //~0B23R~
	uerrmsg("  For the common use of key operation with other Appl,xe accept the strings",//~0B23I~
			"  xeでは他のApplとキー割り当てをなるべく共通化するために、いくつかのキーは");//~0B23I~
	uerrmsg("  which is originaly generated by Tera Term.",        //~0B23I~
			"  Tera Term が生成する文字列をそのまま使用してキー判別しています。");//~0B23I~
	uerrmsg("  Those are displayed on the \"%s\" line output from this PGM.",//~0B23R~
			"  このPGMの 出力の \"%s\" 行にそれが\x95\\示されます。",//~0B23R~
            	Slineid3);                                         //~0B23R~
	uerrmsg("  Check string output by -k option when key effect is incorrect.",//~0B23I~
			"  キーに誤反応する場合は -k オプションで文字列を確認して、");//~0B23I~
	uerrmsg("  Tell that to xe by parm file.",                     //~0B23I~
			"  xeのコマンドラインパラメータで修正してください。"); //~0B23I~
	uerrmsg("  Userkey max is 99(User1 to User99).It should be sequential one by one.",//~0B23I~
			"  定義できるユーザーキーはUser1からUser99までです。飛番も不可です。");//~0B23I~
	uerrmsg("  Duplicated assign is also protected(error msg when load).",//~0B23I~
			"  また,キーコードの重複割り当ては許されない(Loadの時エラーMSGがでる)ので、");//~0B23I~
	uerrmsg("  So,pre-assignment of Tata Term may be unassigned.", //~0B23I~
			"  ユーザーキーに割り当てると他のセクションの割り当てをはずす必要があります。");//~0B23I~
	uerrmsg("  For ex, Pageup=1353 in [Shortcut keys] sect should be changed to Pageup=off.",//~0B23I~
			"  例えば、[Shortcut keys] セクションの Pageup=1353 を Pageup=off と変更し、");//~0B23I~
	uerrmsg("  Shortcut function of Tera Term is not avail now,",  //~0B23I~
			"  Tera Termの制御をはずし(Tera Termのショートカット機\x94\\は使えなくなります)、");//~0B23I~
	uerrmsg("  But xe can detect the Ctrl+Pageup(keycode=1353) combination.",//~0B23I~
		    "  xeのCtrl+Pageup(keycode=1533)の機\x94\\が有効になるようにします。");//~0B23I~
	uerrmsg("    * refer detail to mainual of Tera Term.",         //~0B23I~
			"    * 詳細はTera Termのマニアルを参照してください。");//~0B23I~
	return;
}//ttmaphelp                                                       //~1123R~
