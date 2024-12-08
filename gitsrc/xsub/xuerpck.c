//*CID://+vateR~:                             update#=   16;       //~vateR~
//***********************************************************      //~9411R~
//* XERPCK : chk % is Japnaese/English parm of
//           uerrmsg,uerrexit,uerrmsgcat parameter                 //~9726R~
//       fmt: xerpck dir [/Yv]                                     //~9703I~
//***********************************************************
//vate:241125 xfc1.30 text mode read detect 0x1a as EOF. need open not "r" but "rb"//~vateI~
//va9n:150529 xuerpck v1.4 parm count error(it should be ignored after // comment)//~va9nI~
//va9m:150529 xuerpck v1.4 line buff overoflow,expand to 16384 from 1024//~va9mI~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va3j:080117 xuerpck:v1.3 cpp support                             //~va3jI~
//xuerpck.c *011019 v102 UNX support;PC file eol is 0d0a,0d is read in to buff//~1A19I~
//xuerpck.c *990703 v101 (BUG) fclose(NULL) cause run time err after return under DOS//~9703I~
//***********************************************************
//**********************************************/                  //~9411R~
//*parm  : see help()                          */                  //~9411R~
//*return: 0:normal                            */                  //~9411R~
//*        else error                          */                  //~9411R~
//**********************************************/                  //~9411R~
//***********************************************************      //~9411R~
#define VER "V1.4"   //version                                     //~va3jR~//~va9mR~
//#define PGMID   "XUERPCK"                                        //~va3jR~
#define PGMID   "xuerpck"                                          //~va3jI~
#define RBUFFSZ 4096
//*************************************************************    //~9411R~
//*************************************************************    //~9411R~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*****************************************************************//~9411I~
                                                                   //~9411I~
#ifdef DOS                                                         //+9411R~//~9411M~
                                                                   //+9411M~//~9411M~
#else                                                              //+9411M~//~9411M~
    #ifdef W32                                                     //+9411M~//~v102R~
		#include <dos.h>                                           //~v102I~
    #else                                                          //~v102I~
#define INCL_BASE                                                  //+9411M~//~9411M~
#include <os2.h>                                                   //+9411M~//~9411M~
    #endif                                                         //~v102I~
#endif                                                             //~9411M~

#include <ulib.h>
#include <uerr.h>
#include <ufile.h>
//+9411M~
//*********************************************************************
//#define MAXWIDTH 1024                                              //~9417M~//~va64R~//~va9mR~
#define MAXWIDTH 16384                                             //~va9mR~
static char Sbuff[MAXWIDTH];                                       //~9417I~
static int  Slineno;                                               //~9417I~
static int  Serrcnt=0;                                             //~1A19R~
static char Sline[RBUFFSZ];
static FILE *inputfh=NULL;        //handle
//static FILE *outputfh=NULL;       //handle static int swconfirm=1;        //confirm when wild card//~9703R~
static char *Scurfile;		   //
static int  totfile=0;//total file count                           //~9417R~
static long totliner=0;//total file count
//static int  writecount;          	//input data read count        //~1A19R~
static int  Sprintsw;				//verbose @printsw             //~9417R~
static int  Scppsw;			                                       //~va3jI~
static char *Sinpfname;                                            //~9411I~
//************
void fileproc(FILE *Pinputfh);                                     //~1A19R~
FILE *openinput(char*);            //wild card file open
int  getinput(FILE *Pfh);
void help(void);
void puterr(char *Preason);                                        //~9417I~
char *chrsearch(char *Pstr,char Pch);                              //~9417R~
int chrsearch2(char *Pstr,char *Pkey,char **Pfound);               //~9417R~
char *chrsearch3(char *Pstr);                                      //~9417I~
int listgen(char *Pdirname,PUDIRLIST *Pppudirlist);
int countparm(char **Ppstr);                                       //~9417I~
//*********************************************************************
int main(int parmc,char *parmp[])
{
	char *cptr;         //char ptr work
	char ch;
	int  fctrmax;
	int  ii,pathlen;
	int parmno; //parm count work
	int posparmno=0; //parm count work
	PUDIRLIST pudirlist;
	char pgmver[18];
    char inpfnm[_MAX_PATH];
    FILEFINDBUF3 fstat3;                                           //~9417I~
    int dirsw;                                                     //~9417I~
//*************************
	sprintf(pgmver,"%s:%s:",PGMID,VER);
  	uerrmsg_init(pgmver,stdout,0);//default color
	uerrexit_init(pgmver,stdout,0,0,0);//no mapfile,no exit,no exit parm

  	if (parmc<2) //no parm
  	{
    	help();
    	exit(4);
  	}
//*******************************
//* parm process                *
//*******************************
	for (parmno=1;parmno<parmc;parmno++)
	{
  		cptr=parmp[parmno];
#ifdef UNX                                                         //~1A19I~
  		if(*cptr=='-')                                             //~1A19I~
#else                                                              //~1A19I~
  		if(*cptr=='/'||*cptr=='-')
#endif                                                             //~1A19R~
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
	  			help();
      			exit(4);
      			break;
//**************************
//* set option     */Y//**************************
    		case 'Y':
	  			while (*cptr)
	 			{
	      			switch (toupper(*cptr))
    	  			{
	      			case 'P':                                      //~va3jI~
                        Scppsw=1;                                  //~va3jI~
                        break;                                     //~va3jI~
	      			case 'V':                                      //~9411I~
                        Sprintsw=1;                                //~9411I~
                        break;                                     //~9411I~
	      			default:
						uerrexit("\nToggle Set parm(%s) err",      //~9417R~
								"\nトグル設定(%s)エラー",          //~9417R~
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
	      			case 'P':                                      //~va3jI~
                        Scppsw=0;                                  //~va3jI~
                        break;                                     //~va3jI~
	      			case 'V':                                      //~9411I~
                        Sprintsw=0;                                //~9411I~
                        break;                                     //~9411I~
	      			default:
						uerrexit("\nToggle Reset parm(%s) err",    //~9417R~
								"\nトグル設定解除(%s)エラー",      //~9417R~
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
//* input file             *
//**************************
    		case  1:          //first parm
      			Sinpfname=cptr;        break;
//************************************
    		default:
	 				uerrexit("\ntoo many positional parameter(%s)",
							"\nパラメータが多過ぎます(%s)",
							cptr);
    		}//switch by parmno
  		}//option or posparm
	}//for all parm
//***no pos parm chk
	if (posparmno==0)
		uerrexit("\nspecify input and output file name.",
    				"\nディレクトリー名を指定して下さい");
//**********************************
//* init                           *
//**********************************
    if (!ufullpath(inpfnm,Sinpfname,sizeof(inpfnm)))               //~9411I~
    	uerrexit("filename fmt err(%s)",0,Sinpfname);              //~9411I~
    dirsw=1;                                                       //~9417I~
	if (WILDCARD(Sinpfname))                                       //~9411R~
    	pathlen=PATHLEN(inpfnm);                                   //~9411I~
    else                                                           //~9411I~
    {
    	pathlen=(int)strlen(inpfnm);                               //~9411R~
    	if (!ROOTDIR(inpfnm))                                      //~9411R~
        {                                                          //~9417I~
			if (ufstat(inpfnm,&fstat3))                            //~9417I~
	    		uerrexit("%s not found",0,inpfnm);                 //~9417I~
	        if  (fstat3.attrFile & FILE_DIRECTORY)                 //~9417R~
            {                                                      //~9417I~
#ifdef UNX                                                         //~va9nI~
	        	*(inpfnm+pathlen++)='/';                           //~va9nI~
#else                                                              //~va9nI~
	        	*(inpfnm+pathlen++)='\\';                          //~9417R~
#endif                                                             //~va9nI~
              if (Scppsw)                                          //~va3jI~
		    	strcpy(inpfnm+pathlen,"*.cpp");                    //~va3jI~
              else                                                 //~va3jI~
		    	strcpy(inpfnm+pathlen,"*.c");                      //~9417I~
			}                                                      //~9417I~
            else                                                   //~9417I~
                dirsw=0;                                           //~9417I~
		}                                                          //~9417I~
        else                                                       //~9417I~
          if (Scppsw)                                              //~va3jI~
            strcpy(inpfnm+pathlen,"*.cpp");                        //~va3jI~
          else                                                     //~va3jI~
	    	strcpy(inpfnm+pathlen,"*.c");                          //~9417R~
	}
    printf("===== %s =====\n",inpfnm);                           //+9411I~//~9411R~
   	fctrmax=listgen(inpfnm,&pudirlist);//create file list
//*****************************
//* main loop                 *
//*****************************
	for (ii=0;ii<fctrmax;ii++,pudirlist++)
	{
  		if (!*(Scurfile=pudirlist->name))
			continue;		//confirm reply 'N'
        if (dirsw)                                                 //~9417I~
			strcpy(inpfnm+pathlen,Scurfile);                           //+9411I~//~9417R~
  		inputfh=openinput(inpfnm);                                 //~9411R~
	    printf("%03d=***** %s *****\n",ii+1,Scurfile);            //+9411I~//~9417R~
   		fileproc(inputfh);                                         //~9411R~
   		fclose(inputfh);
		totfile++;
	}//all input file spec
//  fclose(outputfh);       //close output                         //~9703R~

	uerrmsg("\n=%c=process completed;total %d line output total from %d lines out of %d file.",//~9703R~
   				"\n=%c=全処理完了;エラー %d 件、入力合計 %ld 行 ( %d ファイル).",//~9703R~
	  			OSTYPE,Serrcnt,totliner,totfile);                  //~9703R~
  	return 0;

}//end main
//**********************************************************************
//* main process (1 file print)
//**********************************************************************
void fileproc(FILE *Pinputfh)                                      //~9411R~
{
static char Sfunc1[]="uerrmsg(";
static char Sfunc2[]="uerrexit(";
static char Sfunc3[]="uerrmsgcat(";
    char result[64];                                               //~9417I~
	char *pc1,*pc2,*pc3;
	int len,caseno,parmnop=0,parmnoj=0,parmnoe=0,endsw,paren;            //~9417R~//~va64R~
    int printsw,lenw,rc,parmsw;                                                   //+9411I~//~9417R~
    int eolsw;                                                     //~va9nI~
//*********
	Slineno=0;                                                     //~9417R~
    *Sbuff=0;                                                      //~9417R~
    len=0;
    caseno=0;
//+9411I~
	while(!getinput(Pinputfh))     //until eof
 	{
        printsw=Sprintsw;                                          //~9411I~
    	if (*Sline=='/' && *(Sline+1)=='/')
        	continue;
		lenw=(int)strlen(Sline);                                   //~va9mI~
        if (len+lenw+1>=MAXWIDTH)                                  //~va9mI~
        {                                                          //~va9mI~
            puterr("concatination too long");                      //~va9mI~
            return;                                                //~va9mI~
        }                                                          //~va9mI~
        strcpy(Sbuff+len,Sline);                                   //~9417R~
//  	if (*(Sline+(lenw=(int)strlen(Sline))-1)=='\\')                 //+9411R~//~9411R~//~va9mR~
    	if (*(Sline+(lenw)-1)=='\\')                               //~va9mI~
        {
//            if (len+lenw>=MAXWIDTH)                                //~9411R~//~va9mR~
//            {                                                      //~9411I~//~va9mR~
//                puterr("concatination too long");                  //~9417R~//~va9mR~
//                return;                                            //~9411I~//~va9mR~
//            }                                                      //~9411I~//~va9mR~
			len+=(lenw-1);                                         //~9411I~
            continue;
		}
        pc3=Sbuff;	//japanese text search                         //~9417R~
        len=0;
        endsw=0;                                                   //~9411I~
        if (!caseno)	//search func
        {
        	parmnop=0;
            if (pc1=strstr(Sbuff,Sfunc1),pc1)                      //~9417R~
                pc2=pc1+sizeof(Sfunc1);
            else
                if (pc1=strstr(Sbuff,Sfunc2),pc1)                  //~9417R~
                    pc2=pc1+sizeof(Sfunc2);
                else
                    if (pc1=strstr(Sbuff,Sfunc3),pc1)              //~9417R~
                        pc2=pc1+sizeof(Sfunc3);
                    else
                        continue;
                                                                   //~9411I~
            if (printsw)                                          //+9411I~//~9411R~
				printf("%05d:%s\n",Slineno,Sbuff);                 //~9417R~
            pc2--;                                                 //~9411I~
            if (!(pc2=chrsearch(pc2,'"')))                         //~9417R~
            {                                                      //~9411I~
                puterr("no top quate of english");                 //~9417R~
                caseno=0;                                          //~9411I~
				continue;                                          //~9411I~
			}                                                      //~9411I~
            pc2++;                                                 //~9417I~
            parmnoe=countparm(&pc2);                               //~9417R~
            if (!*pc2)
            {                                                      //~9411I~
                puterr("no ending quate of english");              //~9417R~
                caseno=0;                                          //~9411I~
				continue;                                          //~9411I~
			}                                                      //~9411I~
            if (!(pc2=chrsearch(pc2+1,',')))                       //~9417R~
            {                                                      //~9411I~
                puterr("no comma between english and japanese");   //~9417R~
                caseno=0;                                          //~9411I~
				continue;                                          //~9411I~
			}                                                      //~9411I~
            caseno=1;   //search japanese just now                 //~9417M~
            if (!(rc=chrsearch2(pc2+1,"0\"",&pc2)))	//notfound     //~9417R~
                continue;                                          //~9417I~
			if (rc<0)		//invalid char                         //~9417R~
            {                                                      //~9417I~
                caseno=0;                                          //~9417I~
                continue;                                          //~9417I~
            }                                                      //~9417I~
            printsw=0;                                             //~9417M~
            pc3=pc2;                                               //~9417R~
		}//search english
        if (caseno==1)	//search japanese
        {
            if (printsw)                                          //+9411I~//~9411R~
				printf("%05d:%s\n",Slineno,Sbuff);                 //~9417R~
            if (chrsearch2(pc3,"0\"",&pc2)!=1)	//err char or EOL  //~9417R~
            {                                                      //~9417I~
	            caseno=0;                                          //~9417I~
                continue;                                          //~9417I~
            }                                                      //~9417I~
            if (*pc2=='0')	//japanese=0                           //~9417R~
            	parmnoj=parmnoe;                                   //~9417I~
            else                                                   //~9417I~
            {                                                      //~9417I~
                pc2++;                                             //~9417R~
                parmnoj=countparm(&pc2);                           //~9417R~
                if (!*pc2)                                         //~9417R~
                {                                                  //~9417R~
                    puterr("no ending quate of japanese");         //~9417R~
                    caseno=0;                                      //~9417R~
                    continue;                                      //~9417R~
                }                                                  //~9417R~
            }                                                      //~9417I~
            pc1=pc2+1;                                             //~9417I~
            rc=chrsearch2(pc1,",)",&pc2);                          //~9417R~
            if (rc<0)                                              //~9417I~
            {                                                      //~9417I~
            	caseno=0;                                          //~9417I~
            	continue;                                          //~9417I~
			}                                                      //~9417I~
            if (!rc)  //not found , )                              //~9417I~
            {                                                      //~9417I~
                caseno=0;                                          //~9417R~
                puterr("no comma after japanese");                 //~9417R~
                continue;                                          //~9417R~
            }                                                      //~9417R~
            else                                                   //~9417R~
            {                                                      //~9417R~
                caseno=2;                                          //~9417R~
                if (*pc2==',')                                     //~9417I~
                	pc2++;                                         //~9417I~
                pc3=pc2;                                           //~9417R~
            }                                                      //~9417R~
            printsw=0;                                             //~9417I~
		}//search japanese                                         //~9411R~
        eolsw=0;                                                   //~va9nI~
        if (caseno==2)		//count parm
        {
			pc2=chrsearch3(pc3);	//search non space             //~9417R~
			if (!pc2)                                              //~9417R~
            	continue;                                          //~9411I~
            if (printsw)                                          //+9411I~//~9411I~
				printf("%05d:%s\n",Slineno,Sbuff);                 //~9417R~
			parmsw=0;                                              //~9417I~
            for (paren=0;*pc2;pc2++)                               //~9411R~
            {
            	endsw=0;
                switch (*pc2)
                {
                case '(':
                    paren++;
                    break;
                case ')':
                    if (paren)
	                    paren--;
					else
                    {                                              //~9417I~
                    	endsw=1;
                        if (parmsw)                                //~9417I~
							parmnop++;                             //~9417I~
                    }                                              //~9417I~
                    break;
                case ',':
                    if (!paren)
                    {                                              //~9417I~
						parmnop++;
                        parmsw=0;                                  //~9417I~
					}                                              //~9417I~
                	break;                                         //~9417I~
                case ' ':                                          //~9417I~
                case '\t':                                         //~9417I~
                	break;                                         //~9417I~
                case '/':                                          //~va9nI~
                    if (*(pc2+1)=='/')                             //~va9nI~
                    	eolsw=1;                                   //~va9nR~
                	break;                                         //~va9nI~
                default:                                           //~9417I~
                    parmsw=1;                                      //~9417I~
                }
                if (endsw)                                         //~9411I~
                	break;                                         //~9411I~
                if (eolsw)                                         //~va9nI~
                	break;                                         //~va9nI~
            }
		}//case2                                                   //~9411R~
        if (!endsw)                                                //~9411I~
        	continue;                                              //~9411I~
		caseno=0;                                                  //~9411I~
        if (parmnoe!=parmnop                                       //~9411I~
        ||  parmnoj!=parmnop)                                  //~9411R~//~9411M~
        {                                                          //~9411I~
            sprintf(result,"(%d-%d-%d) Parm count err",            //~9417I~
        	  		parmnoe,parmnoj,parmnop);                      //~9417I~
  		  	puterr(result);                                        //~9417I~
		}                                                          //~9411I~
        else                                                   //~9411I~//~9411M~
            if (Sprintsw)                                       //~9411I~//~9417R~
	  	     	printf("----- (%d-%d-%d)\n",                   //~9411I~//~9411M~
                		parmnoe,parmnoj,parmnop);                  //~9411I~//~9411M~
	}//until eof
   	totliner+=Slineno;                                             //~9417R~
	return;
}//procfile
//**********************************************************************//~9417I~
// seach char in the range of before //                            //~9417I~
//**********************************************************************//~9417I~
char *chrsearch(char *Pstr,char Pch)                               //~9417R~
{                                                                  //~9417I~
  	char *pc;                                                      //~9417I~
//***********************                                          //~9417I~
 	for (pc=Pstr;*pc;pc++)                                         //~9417I~
    {                                                              //~9417I~
    	if (*pc=='/' && *(pc+1)=='/')                              //~9417R~
        	break;                                                 //~9417I~
        if (*pc==Pch)                                              //~9417R~
        	return pc;                                             //~9417I~
 	}                                                              //~9417I~
    return 0;                                                      //~9417I~
}//chrsearch                                                       //~9417R~
//**********************************************************************//~9417I~
// seach top of japanese string parm                               //~9417I~
// rc:0:EOL,-1:invalid char,1:0/" found                            //~9417I~
//**********************************************************************//~9417I~
int chrsearch2(char *Pstr,char *Pkey,char **Pfound)                //~9417R~
{                                                                  //~9417I~
  	char *pc;                                                      //~9417I~
    int rc=0;                                                      //~9417I~
    char wkmsg[64];                                                //~9417I~
//***********************                                          //~9417I~
 	for (pc=Pstr;*pc;pc++)                                         //~9417I~
    {                                                              //~9417I~
    	if (*pc=='\n' ||(*pc=='/' && *(pc+1)=='/'))                //~9417R~
        	break;                                                 //~9417I~
        if (*pc!=' ' && *pc!='\t')                                 //~9417R~
        {                                                          //~9417I~
        	if (*pc!=*Pkey && *pc!=*(Pkey+1))                      //~9417R~
            {                                                      //~9417I~
            	rc=-1;                                             //~9417I~
            	sprintf(wkmsg,"%c or %c not found",*Pkey,*(Pkey+1));//~9417R~
            	puterr(wkmsg);                                     //~9417I~
			}                                                      //~9417I~
            else                                                   //~9417I~
            	rc=1;                                              //~9417I~
        	break;                                                 //~9417I~
		}                                                          //~9417I~
 	}                                                              //~9417I~
    *Pfound=pc;                                                    //~9417I~
    return rc;                                                     //~9417R~
}//chrsearch2                                                      //~9417I~
//**********************************************************************//~9417I~
// seach non space                                                 //~9417I~
//**********************************************************************//~9417I~
char *chrsearch3(char *Pstr)                                       //~9417I~
{                                                                  //~9417I~
  	char *pc;                                                      //~9417I~
//***********************                                          //~9417I~
 	for (pc=Pstr;*pc;pc++)                                         //~9417I~
    {                                                              //~9417I~
    	if (*pc=='\n' ||(*pc=='/' && *(pc+1)=='/'))                //~9417I~
        	break;                                                 //~9417I~
        if (*pc!=' ' && *pc!='\t')                                 //~9417I~
        	return pc;                                             //~9417I~
 	}                                                              //~9417I~
    return 0;                                                      //~9417I~
}//chrsearch3                                                      //~9417I~
//**********************************************************************//~9417I~
// count %                                                         //~9417I~
// parm:ptr to be searched,on return last chked pos                //~9417I~
//**********************************************************************//~9417I~
int countparm(char **Ppstr)                                        //~9417I~
{                                                                  //~9417I~
	int parmno;                                                    //~9417I~
  	char *pc;                                                      //~9417I~
//***********************                                          //~9417I~
    for (parmno=0,pc=*Ppstr;*pc;pc++)                              //~9417R~
    {                                                              //~9417I~
        if (*pc=='%')                                              //~9417I~
        	if (*(pc+1)=='%')                                      //~9417I~
            	pc++;	//2 up                                     //~9417I~
            else                                                   //~9417I~
            {                                                      //~v102I~
            	parmno++;                                          //~9417I~
                if (*(pc+1)=='*')                                  //~v102I~
                	parmno++;                                      //~v102I~
                else                                               //~v102I~
                if (*(pc+1)=='.' && *(pc+2)=='*')                  //~v102I~
                	parmno++;                                      //~v102I~
            }                                                      //~v102I~
        else                                                       //~9417I~
            if (*pc=='\\') //end of text                           //~9417I~
            {                                                      //~9417I~
            	if (*(pc+1)=='\\' || *(pc+1)=='"')                 //~9417I~
                	pc++;                                          //~9417I~
                    	                                           //~9417I~
			}                                                      //~9417I~
            else                                                   //~9417I~
            	if (*pc=='"')                                      //~9417R~
                	break;                                         //~9417R~
    }                                                              //~9417I~
    *Ppstr=pc;                                                     //~9417I~
    return parmno;                                                 //~9417I~
}//countparm                                                       //~9417I~
//**********************************************************************
// create sorted file list
//**********************************************************************
int listgen(char *Pdirname,PUDIRLIST *Pppudirlist)
{
  	int fctrmax;
  	PUDIRLIST pudirlist;
//***********************
	if (fctrmax=udirlist(Pdirname,0,&pudirlist,'N'),fctrmax<0)
		exit(4);
	*Pppudirlist=pudirlist;
  	return fctrmax;
}//listgen
//**********************************************************************
// find and open input file
//**********************************************************************
FILE *openinput(char *Ppfile)
{
	FILE *fh;
   	if (!(fh=fopen(Ppfile,"r")))  //open input fail                //+vateR~
//  if (!(fh=fopen(Ppfile,"rb")))  //crlf/lf process required      //+vateR~
		uerrexit("\ninput file(%s) open err",
					"\n入力ファイル(%s) のオープンエラー",						Ppfile);
	return fh;
}//openinput

//**********************************************************************
//* get 1 byte input char
//**********************************************************************
int getinput(FILE *Pfh)
{
	int len;
//****************
	Slineno++;                                                     //~9417R~
    *(Sline+RBUFFSZ-1)=0;                                          //~v102I~
	if (!fgets(Sline,RBUFFSZ,Pfh))	//null return if error or eof
    {                                                              //~va9nI~
		if (ferror(Pfh))
			uerrexit("\n%s read error",0,Scurfile);
		else
			return 4;
    }                                                              //~va9nI~
	len=(int)strlen(Sline);			//read len
	if (*(Sline+len-1)!='\n')
    {                                                              //~v102I~
      if (len>=RBUFFSZ-1)                                          //~v102I~
		uerrmsg("\n????? %s has too long record over %d byte at line %d",0,//~9411R~
				Scurfile,RBUFFSZ-1,Slineno);                       //~9417R~
    }                                                              //~v102I~
#ifdef UNX                                                         //~1A19I~
    else                                                           //~v102I~
	  	if (len>1 && *(Sline+len-2)==0x0d) 	//pc file              //~v102R~
      		len--;                                                 //~v102R~
#endif                                                             //~1A19I~
	*(Sline+len-1)=0;
	return 0;
}//end of getinput

////**********************************************************************//~1A19R~
////* 1 line print if in specified page ***                        //~1A19R~
////**********************************************************************//~1A19R~
//void writeline(void* area,unsigned int count,FILE* file)         //~1A19R~
//{                                                                //~1A19R~
//    writecount++;                                                //~1A19R~
//    if (count!=fwrite(area,1,count,file))                        //~1A19R~
//        uerrexit("\n%s write failed at %d line",                 //~1A19R~
//                "\n%s の %d 行目 出力エラー",                    //~1A19R~
//                Scurfile,writecount);                            //~1A19R~
//  return;                                                        //~1A19R~
//}//end of pline                                                  //~1A19R~
//**********************************************************************//~9417I~
//* err detected line output                                       //~9417I~
//**********************************************************************//~9417I~
void puterr(char *Preason)                                         //~9417I~
{                                                                  //~9417I~
//**************                                                   //~9417I~
	Serrcnt++;                                                     //~9417R~
	if (!Sprintsw)                                                 //~9417I~
		printf("%05d:%s\n",Slineno,Sbuff);                         //~9417I~
	uerrmsg("?????:%s: %s\n",0,                                    //~9417R~
			Scurfile,Preason);                                     //~9417R~
	return;                                                        //~9417I~
}//puterr                                                          //~9417I~
//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
//*******************
	uerrmsg("- %s - uerrmsg/uerrexit/uerrmsgcat %% parm count chk.",
	        "- %s - uerrmsg/uerrexit/uerrmsgcat %% パラメータ数チェック",
			__DATE__);
	uerrmsg("format: %s dir-name %coptions",                       //~1A19R~
			" 形式 : %s ディレクトリー名 %cオプション",            //~1A19R~
			PGMID,CMDFLAG_PREFIX);                                 //~1A19R~
	uerrmsg(" dir-name        :wild card allowed",
			" ディレクトリー名:ワイルドカードファイル指定も可.");
	uerrmsg(" options         :",                                  //~9411I~
			" オプション      :");                                 //~9411I~
	uerrmsg("   %cYx or %cNx    :",0,                              //~1A19R~
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);                    //~1A19I~
	uerrmsg("        x=P      :search on .cpp files",              //~va3jI~
			"        x=P      :.cpp をチェックする");              //~va3jI~
	uerrmsg("        x=V      :print also valid line",             //~9411I~
			"        x=V      :正しい行も出力");                   //~9411I~
	return;
}//help
