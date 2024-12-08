//CID://+vateR~:             update#=   12221                      //~vateR~
//***********************************************************
//* XDEPGEN : >DEP file gen for make/nmake                         //~v1.3R~
//***********************************************************      //~7211I~
//vate:241125 xfc1.30 text mode read detect 0x1a as EOF. need open not "r" but "rb"//~vateI~
//vaa1:160418 Lnx64 compiler warning                               //~vaa1I~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//*050611 xdepgen v134:add -x: for include path of xe              //~v134I~
//*050611 xdepgen v133:-s: wildcard support                        //~v132I~
//*010415 xdepgen v132:LINUX support("/"-->"-")                    //~v132I~
//000926 V1.31 function to skip to include some member             //~v131I~
//000923 V1.3 LINUX support(DBCS \\ in help msg)                   //~v1.3I~
//*v1.3 unix make support                                          //~v1.3I~
//*v1.2 971018 -line count overflow 32768                          //~7A18I~
//*v1.1 970210 -exclude "unistd.h"                                 //~7211I~
//*            -os2.h case insensitive chk                         //~7211I~
//941115 v1.1: new uerrexit_init                                   //~7A18M~
//941115 v1.0: first release                                       //~7A18M~
//***********************************************************      //~7A18M~
//**********************************************/
//*parm  : see help()                          */
//*return: 0:normal                            */
//*        else error                          */
//**********************************************/
//***********************************************************
#define VER "V1.3"   //version                                     //~v1.3R~
#define PGMID   "XDEPGEN"
#define RBUFFSZ 4096
//*************************************************************
#ifdef DOS                           

#else                               
    #ifdef W32                                                     //~v1.3I~
    #else                                                          //~v1.3I~
#define INCL_BASE                     
#include <os2.h>         
    #endif                                                         //~v1.3I~

#endif                               
//*************************************************************
#include <time.h>     
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    
#include <string.h>   

#include <ulib.h>
#include <uerr.h>
#include <ufile.h>
#include <ufile5.h>                                                //~v132I~
#include <ukbd.h>
#ifdef UNX                                                         //~v1.3I~
    #include <ugcclib.h>                                           //~v1.3I~
#endif                                                             //~v1.3I~
//*********************************************************************
#define MAXSKIPMEMBER 100                                          //~v131I~
//*********************************************************************//~v131I~
static char Sline[RBUFFSZ];
static FILE *inputfh=NULL;        //handle
static FILE *outputfh=NULL;       //handle 
static int swconfirm=1;        //confirm when wild card  
static int swsystem=0;       	 //gen for system header
static int multifilesw;
static char *Scurfile;		   //
static int  totfile=0,totlinew=0;//total file count                //~7A18R~
static long totliner=0;//total file count                          //~7A18I~
static int  readcount,writecount;          	//input data read count 
static char *incpathpvt=0,*incpathulib=0,*objpath=0,*addmem=0;
static char *incpathxe=0;                                          //~v134I~
static char *inpfname,*outfname;
#ifdef UNX                                                         //~v131I~
	static int  Sunixsw=1;      //unix type (.o not .obj) default  //~v131I~
#else                                                              //~v131I~
static int  Sunixsw;        //unix type (.o not .obj)              //~v1.3I~
#endif                                                             //~v131I~
static int  Slowersw;		//filename by lower case               //~v1.3I~
static int  Sskipctr;		//skip member counter                  //~v131I~
static char *Sskipmember[MAXSKIPMEMBER];   //skip member counter   //~v131I~
//************
static void fileproc(char *Pfilename,FILE *inputfh);
static FILE *openinput(char*);            //wild card file open
static FILE *openoutput(char *);
static int  getinput(FILE *Pfh);
static void writeline(void* area,unsigned int count,FILE* file);
static int  listgen(char*,PUDIRLIST*);             //create sorted file list
static int  fileconfirm(char *);		//file name confirmation to print
static void help(void);
//*********************************************************************
int main(int parmc,char *parmp[])
{
	char *cptr;         //char ptr work
	char ch;
	int  fctrmax; 
	int  ii;
	int parmno; //parm count work
	int posparmno=0; //parm count work
	PUDIRLIST pudirlist;
	char pgmver[18];
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
#ifdef UNX                                                         //~v132I~
  if(*cptr=='-')                                                   //~v132I~
#else  //!UNX                                                      //~v132I~
  if(*cptr=='/'||*cptr=='-')          
#endif //UNX/!UNX                                                  //~v132I~
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
//* additional for all member /A:
//**************************
    case 'A':
		addmem=cptr;
        break;
//**************************
//* path dir for "xxxx.h"
//**************************
    case 'C':
		incpathpvt=cptr;
        break;
//**************************
//* object path dir
//**************************
    case 'O':
		objpath=cptr;
        break;
//**************************                                       //~v131I~
//* skip member /S:                                                //~v131I~
//**************************                                       //~v131I~
    case 'S':                                                      //~v131I~
    	if (Sskipctr>=MAXSKIPMEMBER)                               //~v131I~
			uerrexit("\nskip member over flow(max is %d)",0,       //~v131I~
						MAXSKIPMEMBER);                            //~v131I~
		Sskipmember[Sskipctr++]=cptr;                              //~v131I~
        break;                                                     //~v131I~
//**************************
//* path dir for <uxxxx.h>
//**************************
    case 'U':
		incpathulib=cptr;
        break;
//**************************                                       //~v134I~
//* path dir for <xexxx.h>                                         //~v134I~
//**************************                                       //~v134I~
    case 'X':                                                      //~v134I~
		incpathxe=cptr;                                            //~v134I~
        break;                                                     //~v134I~
//**************************
//* set option     */Y
//**************************
    case 'Y':
	  while (*cptr)			
	  {						
	      switch (toupper(*cptr))
    	  {             
	      case 'C':           
	        swconfirm=1;
	        break; 
	      case 'L':                                                //~v1.3I~
	        Slowersw=1;                                            //~v1.3I~
	        break;                                                 //~v1.3I~
	      case 'S':           
	        swsystem=1;
	        break; 
	      case 'U':                                                //~v1.3I~
	        Sunixsw=1;                                             //~v1.3I~
	        break;                                                 //~v1.3I~
	      default: 
			uerrexit("\nToggle Set parm(%s) err",                  //~9417R~
						"\nトグル設定(%s)エラー",                  //~9417R~
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
	      case 'C':           
	        swconfirm=0;
	        break; 
	      case 'L':                                                //~v1.3I~
	        Slowersw=0;                                            //~v1.3I~
	        break;                                                 //~v1.3I~
	      case 'S':           
	        swsystem=0;
	        break; 
	      case 'U':                                                //~v1.3I~
	        Sunixsw=0;                                             //~v1.3I~
	        break;                                                 //~v1.3I~
	      default: 
			uerrexit("\nToggle Reset parm(%s) err",                //~9417R~
						"\nトグル設定解除(%s)エラー",              //~9417R~
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
      inpfname=cptr;  
      break;                                 
//**************************
//* output file            *
//**************************
    case 2: // 2nd parm             
      outfname=cptr;
      break;                                 
//************************************
    default:
	 	uerrexit("\ntoo many positional parameter(%s)",
					"\nパラメータが多過ぎます(%s)",
					cptr);
    }//switch by parmno

  }//option or posparm
}//for all parm
//***no pos parm chk
	if (posparmno!=2)
		uerrexit("\nspecify input and output file name.",
    				"\n入力と出力のファイルを指定して下さい");
//**********************************
//* init                           *
//**********************************
	multifilesw=(strpbrk(inpfname,"*?")!=NULL);//nonzero if "*" , "?"
   	fctrmax=listgen(inpfname,&pudirlist);//create file list
	outputfh=openoutput(outfname);//open output

//*****************************
//* main loop                 *
//*****************************
	for (ii=0;ii<fctrmax;ii++,pudirlist++)				
	{															
  		if (!*(Scurfile=pudirlist->name))
			continue;		//confirm reply 'N'
  		inputfh=openinput(Scurfile);
   		fileproc(Scurfile,inputfh);
   		fclose(inputfh);
		totfile++;
	}//all input file spec
	fclose(outputfh);       //close output

 	if (multifilesw)	
		uerrmsg("\nprocess completed;total %d line output total from %d lines out of %d file.",
   				"\n全処理完了;出力合計 %d 行, 入力合計 %ld 行 ( %d ファイル).",//~7A18R~
	  			totlinew,totliner,totfile);
  return 0;

}//end main

//**********************************************************************
//* main process (1 file print)
//**********************************************************************
void fileproc(char *Pfilename,FILE *Pinputfh)
{
static char Sdelmline[]="#################\n";	
static char Sincid[]="#include ";	
static char Scomm1[]="/*";	
static char Scomm2[]="//";	
static char Scomm3[]="*/";	
	char *pc,*pc1,*pc2;
	char libid;
	char outbuff[256];
	UINT len,namelen,len0,lenh=0;                                  //~v1.3R~
	int firstsw=1;
    int  ii;                                                       //~v131I~
//*********
	readcount=writecount=0;
	while(!getinput(Pinputfh))     //until eof
	{
		if (!(pc1=strstr(Sline,Sincid)))
			continue;
		if (pc2=strstr(Sline,Scomm1),pc2)	// "/ *" comment
			if (pc2<pc1)
				if (!(pc2=strstr(Sline,Scomm3)) // "* /" comment
				|| pc2>pc1)
					continue;
		if (pc2=strstr(Sline,Scomm2),pc2)	// "//" comment
			if (pc2<pc1)
				continue;
		if (!(pc2=strpbrk(pc1,"\"<")))
			continue;
		libid=*pc2;
		pc2+=strspn(pc2+1," ")+1;			//include file name pos
		if (!(pc1=strpbrk(pc2,"\"> ")))		//file name end pos
			continue;
//		namelen=(UINT)((ULONG)pc1-(ULONG)pc2);                     //~va66R~
  		namelen=(UINT)((ULPTR)pc1-(ULPTR)pc2);                     //~va66I~
		if (!memicmp(pc2,"os2.h",5))                               //~7211R~
			continue;
		if (!memicmp(pc2,"unistd.h",8))                            //~7211I~
			continue;                                              //~7211I~
		if (libid=='<'	//system file
		&&  *pc2!='u'		//<uxxxx>
		&&  !swsystem)		//no generation for system file
			continue;
//*chk skip member                                                 //~v131I~
		for (ii=0;ii<Sskipctr;ii++)                                //~v131I~
          if (WILDCARD(Sskipmember[ii]))                           //~v132I~
          {                                                        //~v132I~
            if (!ufilewildcomp(UFWC_CASE_DEFAULT,pc2,Sskipmember[ii],0))//~v132I~
                break;                                             //~v132I~
          }                                                        //~v132I~
          else                                                     //~v132I~
          {                                                        //~v132I~
            if (strlen(Sskipmember[ii])==namelen                   //~v131I~
            &&  !memicmp(pc2,Sskipmember[ii],namelen))             //~v131I~
                break;                                             //~v131I~
          }                                                        //~v132I~
		if (ii<Sskipctr)    //matched to skip member parm          //~v131I~
            continue;                                              //~v131I~
//*construct line
		if (firstsw)
		{
			firstsw=0;
//  		writeline(Sdelmline,strlen(Sdelmline),outputfh);       //~vaa1R~
    		writeline(Sdelmline,(unsigned)strlen(Sdelmline),outputfh);//~vaa1I~
			if (objpath)
			{
				strcpy(outbuff,objpath);
//  			len0=strlen(objpath);                              //~vaa1R~
    			len0=(UINT)strlen(objpath);                        //~vaa1I~
			}
			else
				len0=0;
			pc=strpbrk(Pfilename,".");
			if (pc)
			{
				memcpy(outbuff+len0,Pfilename,
//						len=(UINT)((ULONG)pc-(ULONG)Pfilename));   //~va66R~
						len=(UINT)((ULPTR)pc-(ULPTR)Pfilename));   //~va66I~
				*(outbuff+len0+len)=0;
			}
			else
				strcpy(outbuff+len0,Pfilename);
			if (Slowersw)                                          //~v1.3I~
        		strlwr(outbuff+len0);                              //~v1.3I~
        if (Sunixsw)                                               //~v1.3R~
			strcat(outbuff,".o:");                                 //~v1.3I~
        else                                                       //~v1.3I~
			strcat(outbuff,".obj:");
//  		lenh=strlen(outbuff);                                  //~vaa1R~
    		lenh=(UINT)strlen(outbuff);                            //~vaa1I~
			strcat(outbuff,Pfilename);
			if (Slowersw)                                          //~v1.3I~
        		strlwr(outbuff+lenh);                              //~v1.3I~
			strcat(outbuff,"  \\\n");
//  		writeline(outbuff,strlen(outbuff),outputfh);           //~vaa1R~
    		writeline(outbuff,(unsigned)strlen(outbuff),outputfh); //~vaa1I~
		}
		memset(outbuff,' ',lenh);
		*(outbuff+lenh)=0;
		if (libid=='<')	//system file
		{
			if (*pc2=='u')		//<uxxxx>
				if (incpathulib)
					strcat(outbuff,incpathulib);
		}
		else
		  if (*pc2=='x' && *(pc2+1)=='e'		//<xexxxx>         //~v134I~
		  &&  incpathxe)                                           //~v134I~
				strcat(outbuff,incpathxe);                         //~v134I~
          else                                                     //~v134I~
			if (incpathpvt)
				strcat(outbuff,incpathpvt);
//  	len=strlen(outbuff);                                       //~vaa1R~
    	len=(UINT)strlen(outbuff);                                 //~vaa1I~
		memcpy(outbuff+len,pc2,namelen);
		*(outbuff+len+namelen)=0;
		strcat(outbuff+len,"  \\\n");
//  	writeline(outbuff,strlen(outbuff),outputfh);               //~vaa1R~
    	writeline(outbuff,(unsigned)strlen(outbuff),outputfh);     //~vaa1I~
	}//until eof
	if (!firstsw)	//once write
    {                                                              //~v133I~
		if (addmem)
		{
			memset(outbuff,' ',lenh);
			*(outbuff+lenh)=0;
			strcat(outbuff,addmem);//for all member
			strcat(outbuff,"\n");	//for all member
//  		writeline(outbuff,strlen(outbuff),outputfh);//for all member//~vaa1R~
    		writeline(outbuff,(unsigned)strlen(outbuff),outputfh);//for all member//~vaa1I~
		}
		else
			writeline(" \n",2,outputfh);	//for continuation
    }                                                              //~v133I~

	uerrmsg("\n%s processed;%d line read, %dline written.",
			"\n%s 処理完了;%d 行読み込み,%d 行出力",
			Pfilename,readcount,writecount);
   	totliner+=readcount;
   	totlinew+=writecount;
	return;
}//procfile
//**********************************************************************
// create sorted file list			
//**********************************************************************
int listgen(char *Pdirname,PUDIRLIST *Pppudirlist)
{
  	int i;
  	int fctrmax;
  	PUDIRLIST pudirlist;
//***********************
	if (fctrmax=udirlist(Pdirname,0,&pudirlist,'N'),fctrmax<0)
		exit(4);
	*Pppudirlist=pudirlist;
//** confirmation 
	if (swconfirm     //question to operator option
 	&&  multifilesw)	//wild card
		for (i=0;i<fctrmax;i++,pudirlist++)
		{
			if (!fileconfirm(pudirlist->name))	//reply no
				*pudirlist->name=0;			//no process id
		}
  	return fctrmax;
}//listgen
//**********************************************************************
// find and open input file
//**********************************************************************
FILE *openinput(char *Ppfile)    
{
	FILE *fh;
    if (!(fh=fopen(Ppfile,"r")))  //open input fail                //+vateR~
// 	if (!(fh=fopen(Ppfile,"rb")))  //crlf/lf process required      //+vateR~
		uerrexit("\ninput file(%s) open err",
					"\n入力ファイル(%s) のオープンエラー",
						Ppfile);
	return fh;
}//openinput

//**********************************************************************
//* get 1 byte input char		
//**********************************************************************
int getinput(FILE *Pfh)
{
	int len;
//****************
	readcount++;				
	if (!fgets(Sline,RBUFFSZ,Pfh))	//null return if error or eof
    {                                                              //~v133I~
		if (ferror(Pfh))
			uerrexit("\n%s read error",0,Scurfile);
		else
			return 4;
    }                                                              //~v133I~
	len=(int)strlen(Sline);			//read len
	if (*(Sline+len-1)!='\n')
		uerrmsg("\n%s has too long record over %d byte at line %d",0,
				Scurfile,RBUFFSZ-1,readcount);
	return 0;
}//end of getinput

//********************************************************
//*output file open
//*  parm1:file name                                     *
//*  ret  :file handle                                   *
//********************************************************
FILE *openoutput(char *Pfname)
{
	FILE *outputh;
//************************
    if (Sunixsw)                                                   //~v1.3I~
		outputh=fopen(Pfname,"wb");                                //~v1.3I~
    else                                                           //~v1.3I~
		outputh=fopen(Pfname,"w");                                 //~v1.3R~
	if (!outputh)                                                  //~v1.3I~
		uerrexit("\noutput file(%s) open err\n",
					"\n出力ファイル(%s) オープンエラー\n",
					Pfname);//
	return outputh;
}
//**********************************************************************
//* 1 line print if in specified page ***
//**********************************************************************
void writeline(void* area,unsigned int count,FILE* file) 
{
	writecount++;
  	if (count!=fwrite(area,1,count,file))
		uerrexit("\n%s write failed at %d line",
				"\n%s の %d 行目 出力エラー",
				Scurfile,writecount);
  return;
}//end of pline

//**********************************************************************
//*confirm file print yes/no						 
//* parm : file name with path name
//* r.c  : 0:reply No, 1:reply Yes
//**********************************************************************
int  fileconfirm(char *filename)
{
	KBDKEYINFO keyinfo;
static int firstconfirm=1;			//first confirm sw 
    int breaksw=0;                                                 //~v134I~
//******************************
	if (!swconfirm) //question to operator option 
		return 1;   //select

	for (;;)//until y/n reply
 	{
		uerrmsg("\nDo you process %s ?  Enter Y(es) or N(o).",
				"\n%s を処理しますか?  Y(はい) か N(いいえ) を入力して下さい.",
			filename);
       	if (firstconfirm)			//first confirm sw 
		{
			uerrmsg("\n(You may use /Nc option after stopping by Esc key if you want)",
					"\n(煩雑ならば Esc で中断し /Nc オプション で 再実行して下さい)");
           	firstconfirm=0;			//first confirm sw
		}
		fflush(stdout);
		ukbdcharin(&keyinfo,IO_WAIT);
		if (keyinfo.chScan)	//char input
		{
			switch(toupper(keyinfo.chChar))
			{
			case 'Y':
				return 1;
			case 'N':
				uerrmsg("\nprocess bypassed for \"%s\".",
						"\n\"%s\"の処理は取り消されました.",
						filename);
                breaksw=1;                                         //~v134I~
//  	    	return 0;   //unreachable code warning             //~v134R~
    	    	break;                                             //~v134I~
			case 0x1b:
				uerrmsg("\nprocess forced termination.",
						"\nEsc による強制終了.");
		    	exit(4);
				break;
			}//sw by char	
    	}//char input
        if (breaksw)                                               //~v134I~
            break;                                                 //~v134I~
    }//infinite loop
	return 0;
}//fileconfirm


//**********************************************************************
//* write help msg  
//**********************************************************************
void help(void)
{
//*******************
	uerrmsg(".DEP file for (n)make generate utility program (%s).",//~v132R~
			"(n)make のための .DEP ファイル生成ユーティリティー (%s).",//~v132R~
			__DATE__);
	uerrmsg("format: %s in-file [out-file(PRN)] [%coption %c...]", //~v132R~
			" 形式 : %s 入力ファイル 出力ファイル[%cオプション %c...]",//~v132R~
			PGMID,CMDFLAG_PREFIX,CMDFLAG_PREFIX);                  //~v132R~
	uerrmsg("  in-file     :wild card allowed.",                   //~v132R~
			" 入力ファイル : ワイルドカードファイル名指定も可.");  //~v132R~
	uerrmsg("  out-file    :specify output dep file name.",        //~v132R~
			" 出力ファイル : dep file 名を指定する.");             //~v132R~
	uerrmsg("  option      :",                                     //~v132R~
			" オプション   :");                                    //~v132R~
	uerrmsg("  %cA:xxxx     :additional member statement for all file",//~v132R~
			"  %cA:xxxx     :全ファイル対象の追加のメンバー文",    //~v132R~
			CMDFLAG_PREFIX);                                       //~v132I~
	uerrmsg("  %cC:cccc     :current source directory name",       //~v132R~
//  		"  /C:cccc     :現ソースファイルディレクトリー名");    //~v132R~
    		"  %cC:cccc     :現\x83\\ースファイルディレクトリー名",//~v132R~
			CMDFLAG_PREFIX);                                       //~v132I~
	uerrmsg("  %cO:oooo     :object directory name",               //~v132R~
			"  %cO:oooo     :オブジェクトファイルディレクトリー名",//~v132R~
			CMDFLAG_PREFIX);                                       //~v132I~
	uerrmsg("  %cS:ssss     :header file name to be excluded(wildcard avail)",//~v134R~
			"  %cS:ssss     :従属文生成対象外メンバー名(wildcard OK)",//~v134R~
			CMDFLAG_PREFIX);                                       //~v132I~
	uerrmsg("  %cU:ulll     :ULIB file directory name",            //~v132R~
			"  %cU:ulll     :ULIB ディレクトリー名",               //~v132R~
			CMDFLAG_PREFIX);                                       //~v132I~
	uerrmsg("  %cX:xxxx     :XE file directory name",              //~v134I~
			"  %cX:xxxx     :XE ディレクトリー名",                 //~v134I~
			CMDFLAG_PREFIX);                                       //~v134I~
	uerrmsg("  %cY:x %cN:x   :Toggle Set(%cY) or Reset(%cN) option",//~v132R~
			"  %cY:x %cN:x   :トグルスイッチ 設定(%cY)と設定解除(%cN)",//~v132R~
			CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX,CMDFLAG_PREFIX);//~v132I~
	uerrmsg("              :(default is in parethesys)",           //~v132R~
//  		"              :(省略時の値は括弧内に表示)");          //~v132R~
    		"              :(省略時の値は括弧内に\x95\\示)");      //~v132R~
	uerrmsg("     x=C (%cYc):input filename select confirmation",  //~v132R~
			"     x=C (%cYc):入力ファイル選択確認をする/しない",   //~v132R~
			CMDFLAG_PREFIX);                                       //~v132I~
	uerrmsg("     x=L (%cNl):set filename as lower case letter",   //~v132R~
			"     x=L (%cNl):ファイル名を小文字でセット",          //~v132R~
			CMDFLAG_PREFIX);                                       //~v132I~
	uerrmsg("     x=S (%cNs):generate for system header file or not",//~v132R~
			"     x=S (%cNs):システムヘッダーファイルをも生成対象とする/しない",//~v132R~
			CMDFLAG_PREFIX);                                       //~v132I~
	uerrmsg("     x=U (%cNu):output format for UNIX Makefile",     //~v132R~
			"     x=U (%cNu):UNIX Make用のファイル形式で出力",     //~v132R~
			CMDFLAG_PREFIX);                                       //~v132I~
	return;
}//help
