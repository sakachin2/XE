//*CID://+vateR~:                             update#=   14;       //~vateR~
//*************************************************************    //~0513I~
//*xbc.c                                                           //~0513I~
//* basic calc batch                                               //~0513I~
//*************************************************************    //~v101I~
//vate:241125 xfc1.30 text mode read detect 0x1a as EOF. need open not "r" but "rb"//~vateI~
//vash:240317 xbc;supprt ucs4<-->utf16 by ucalc                    //~vashI~
//vas3:230630 ARM;closeall for arm subthread execution             //~vas3I~
//vaf0:170316 xbc v1.6:support 3 operand by "reverse polish notation"//~vaf0I~
//va1J 041228 xbc:v1.5 file input support(-fname,stdin if no filename specification)//~va1JI~
//va1k:040927 xbc:v1.4:help msg update for VnnR option(precision,round)//~va1kI~
//va1h:040822 xbc:v1.4 help update by ucalc change                 //~va1hI~
//va1f:040612 xbc:v1.4 multiply overflow help;use output type u/uz to output dword value)//~va1fI~
//030505 xbc:v1.3 v105 ubc_main parm changed                       //~v105I~
//*011011 xbc v104:uliv changed;v541,v542,v543,v544                //~v102I~
//*011011 xbc v103:helpmsg chng                                    //~v102I~
//*011011 xbc v102:helpmsg chng                                    //~v102I~
//*010407 xbc v101:hex dowrd +,-,*,/,% support                     //~v101I~
//*************************************************************    //~0513I~
#define VERSION  "v1.8"                                            //~va1JR~//~vaf0R~//~vashR~//~vateR~
#define PGMID    "xbc"                                             //~v101R~
//*************************************************************    //~0513I~
#include <time.h>                                                  //~0513I~
#include <stdio.h>                                                 //~0513I~
#include <stddef.h>                                                //~0513I~
#include <stdlib.h>                                                //~0513I~
#include <ctype.h>                                                 //~0513I~
#include <string.h>                                                //~0513I~
                                                                   //~0513I~
#ifdef DOS                                                         //~0513I~
#else                                                              //~0513I~
	#ifdef W32                                                     //~0513I~
	#else                                                          //~0513I~
	#endif                                                         //~0513I~
#endif                                                             //~0513I~
//*******************************************************          //~0513I~
#include <ulib.h>                                                  //~0513I~
#include <uerr.h>                                                  //~0513I~
#include <uque.h>                                                  //~0513I~
#include <ufile.h>                                                 //~0513I~
#include <ualloc.h>                                                //~0513I~
#include <ucalc.h>                                                 //~0513I~
#include <udbcschk.h>                                              //~0513I~
//**************************************************************** //~0513I~
static	char *Spgmid=PGMID;                                        //~0513R~
//static  int  Sdbcssw;                                            //~v102R~
//**************************************************************** //~0513I~
int xbcfile(UCHAR *Pfnm);                                          //~va1JI~
void help(void);                                                   //~0513I~
//**************************************************************** //~0513I~
// calc body                                                       //~0513I~
//*rc   :0                                                         //~0513I~
//**************************************************************** //~0513I~
int main(int parmc,char *parmp[])                                  //~0513I~
{                                                                  //~0513I~
	int ii,len,rc;                                                 //~0513R~
    UCHAR *cmdstr,*pc,parmno;                                      //~0513R~
    UCHAR *pfnm=0;                                                 //~va1JI~
//*********************************                                //~0513I~
//  uerrmsg_init("",stdout,0);//msg to stdout                      //~0513R~
//  uerrexit_init("",stdout,0,0,0);//stdout only,no pathmsg        //~0513R~
//  Sdbcssw=udbcschkcp();                                          //~v102R~
//special option chk                                               //~0513I~
    for (ii=1,len=parmc,parmno=0;ii<parmc;ii++)                    //~0513R~
    {                                                              //~0513I~
        pc=parmp[ii];                                              //~va1JI~
        if (!memicmp(pc,"/F",2)                                    //~va1JR~
        ||  !memicmp(pc,"-F",2))                                   //~va1JR~
        {                                                          //~va1JI~
        	pfnm=pc+2;	//input filename                           //~va1JI~
        	continue;                                              //~va1JI~
        }                                                          //~va1JI~
        if (!stricmp(parmp[ii],"/N9")                              //~v101R~
        ||  !stricmp(parmp[ii],"-N9"))                             //~v101I~
        {                                                          //~0513I~
//          Sdbcssw=0;                                             //~v102R~
			uerrmsg_init("",stdout,UERR_FORCE_ENGLISH);            //~v101I~
        	continue;                                              //~0513I~
        }                                                          //~0513I~
        if (!stricmp(parmp[ii],"/Y9")                              //~v101R~
        ||  !stricmp(parmp[ii],"-Y9"))                             //~v101I~
        	continue;                                              //~v101I~
        if (!stricmp(parmp[ii],"/H")                               //~v101R~
        ||  !stricmp(parmp[ii],"/?")                               //~v101R~
        ||  !stricmp(parmp[ii],"-H")                               //~v101I~
        ||  !stricmp(parmp[ii],"-?"))                              //~v101I~
        {                                                          //~v101I~
        	help();                                                //~v101I~
        	exit(1);                                               //~v101I~
        }                                                          //~v101I~
        len+=(int)strlen(parmp[ii]);                               //~0513I~
        parmno++;                                                  //~0513I~
    }                                                              //~0513I~
    if (pfnm)                                                      //~va1JI~
    	return xbcfile(pfnm);                                      //~va1JI~
//*                                                                //~0513I~
    if (!parmno)       //no opd                                    //~0513R~
    {                                                              //~0513I~
        help();                                                    //~0513I~
        exit(1);                                                   //~0513I~
    }                                                              //~0513I~
//set cmd string                                                   //~0513I~
    cmdstr=malloc((UINT)len);                                      //~0513M~
    memset(cmdstr,' ',(UINT)len);                                  //~0513M~
    *(cmdstr+len-1)=0;                                             //~0513M~
    for (ii=1,pc=cmdstr;ii<parmc;ii++)                             //~0513R~
    {                                                              //~0513I~
        if (!stricmp(parmp[ii],"/N9"))                             //~0513I~
        	continue;                                              //~0513I~
        len=(int)strlen(parmp[ii]);                                //~0513R~
        memcpy(pc,parmp[ii],(UINT)len);                            //~0513I~
        pc+=(len+1);	//space delm                               //~0513I~
	}                                                              //~0513I~
//repl (/) to </>                                                  //~0513I~
    for(pc=cmdstr;;)                                               //~0513I~
    {                                                              //~0513I~
        pc=strchr(pc,'(');                                         //~0513I~
        if (!pc)                                                   //~0513I~
        	break;                                                 //~0513I~
        *pc++='<';                                                 //~0513I~
    }                                                              //~0513I~
    for(pc=cmdstr;;)                                               //~0513I~
    {                                                              //~0513I~
        pc=strchr(pc,')');                                         //~0513I~
        if (!pc)                                                   //~0513I~
        	break;                                                 //~0513I~
        *pc++='>';                                                 //~0513I~
    }                                                              //~0513I~
    for(pc=cmdstr;;)                                               //~0513I~
    {                                                              //~0513I~
        pc=strchr(pc,'~');                                         //~0513I~
        if (!pc)                                                   //~0513I~
        	break;                                                 //~0513I~
        *pc++='|';                                                 //~0513I~
    }                                                              //~0513I~
//bc                                                               //~0513I~
//  rc=ucalc_bcmain(cmdstr);                                       //~v105R~
    rc=ucalc_bcmain(cmdstr,0);                                     //~v105I~
    if (rc)                                                        //~0513I~
        ubell();                                                   //~0513I~
	ARMXSUB_CLOSE(PGMID);	//close for Arm subthread execution                                          //~v6B1I~//~vas2I~//~vas3R~
    return rc;                                                     //~0513I~
}//main                                                            //~va1JR~
//**************************************************************** //~va1JI~
// input from file                                                 //~va1JR~
//*rc   :0                                                         //~va1JI~
//**************************************************************** //~va1JI~
int xbcfile(UCHAR *Pfnm)                                           //~va1JI~
{                                                                  //~va1JI~
	int rc,rct=0,ii,jj,printsw;                                    //~va1JR~
    int cmdsvno=0,backno,retrievesw,cmdsvmaxno=0;                  //~va1JR~
	FILE *fh;                                                      //~va1JI~
#define MAXRECSZ  256                                              //~va1JI~
#define MAXSVNO    99                                              //~va1JI~
    char cmdch,*pc,*cmdstr,buff[MAXRECSZ+1];                       //~va1JR~
    char cmdsv[MAXSVNO][MAXRECSZ+1];                               //~va1JI~
//***************************                                      //~va1JI~
	if (!*Pfnm)                                                    //~va1JR~
    {                                                              //~va1JI~
    	fh=stdin;                                                  //~va1JI~
        printf("q:exit, r[n]:retrieve, l[n|$] list\n");            //~va1JR~
    }                                                              //~va1JI~
    else                                                           //~va1JI~
    {                                                              //~va1JI~
  	 	fh=fopen(Pfnm,"r");     //accept 0d0a and 0a                                 //~va1JI~//+vateR~
// 	 	fh=fopen(Pfnm,"rb");    //maybe no case of EOF(0x1a) input //+vateR~
        if (!fh)                                                   //~va1JI~
        	return ufilenotfound(Pfnm,8);                          //~va1JI~
    }                                                              //~va1JI~
    for (;;)                                                       //~va1JI~
    {                                                              //~va1JI~
    	if (!fgets(buff,MAXRECSZ,fh))	                           //~va1JR~
        	break;                                                 //~va1JI~
        pc=memchr(buff,'\n',MAXRECSZ);                             //~va1JI~
        if (pc)                                                    //~va1JI~
        	*pc=0;                                                 //~va1JI~
        else                                                       //~va1JI~
        	*(buff+MAXRECSZ)=0;                                    //~va1JI~
		if (*Pfnm)	//not stdin(stdin is echoed)                   //~va1JI~
        	printf(":::: %s\n",buff);                              //~va1JR~
        pc=strchr(buff,'#');//comment                              //~va1JI~
        if (pc)                                                    //~va1JI~
        {                                                          //~va1JI~
        	*pc=0;                                                 //~va1JI~
            if (strspn(buff," \t")==strlen(buff))                  //~va1JI~
            	continue;	//line start by #                      //~va1JI~
        }                                                          //~va1JI~
        cmdstr=buff+strspn(buff," \t");                            //~va1JI~
        cmdch=(char)toupper(*cmdstr);                              //~va1JR~
        if (cmdch=='Q') //quit                                     //~va1JI~
            break;                                                 //~va1JI~
        retrievesw=0;                                              //~va1JI~
        if (cmdch=='R')	//retrieve                                 //~va1JI~
        {                                                          //~va1JI~
        	backno=atoi(cmdstr+1);                                 //~va1JI~
            if (!backno)                                           //~va1JM~
            	backno=1;                                          //~va1JM~
            if (backno>cmdsvmaxno)                                 //~va1JR~
            {                                                      //~va1JI~
            	uerrmsg("now only %d entry saved",0,               //~va1JR~
                		cmdsvmaxno);                               //~va1JR~
                continue;                                          //~va1JI~
            }                                                      //~va1JI~
            backno=cmdsvno-backno;                                 //~va1JI~
            if (backno<0)                                          //~va1JI~
            	backno+=MAXSVNO;                                   //~va1JI~
            strcpy(cmdstr,cmdsv[backno]);                          //~va1JI~
            pc=strstr(cmdstr,":=");                                //~va1JI~
            if (pc)                                                //~va1JI~
            	*pc=0;                                             //~va1JI~
            retrievesw=1;                                          //~va1JI~
        }                                                          //~va1JI~
        else                                                       //~va1JI~
        if (cmdch=='L')	//list                                     //~va1JI~
        {                                                          //~va1JI~
        	printsw=0;                                             //~va1JI~
            if (*(cmdstr+1)==UCALC_VARID) //L$                     //~va1JI~
            {                                                      //~va1JI~
                for (ii=0;ii<UCALC_MAXRESULTNO;ii++)               //~va1JI~
                {                                                  //~va1JI~
                	pc=Gucalc_result[ii];                          //~va1JI~
                    if (*pc)                                       //~va1JI~
                    {                                              //~va1JI~
	                    printf("$%d=%s\n",ii,pc);                  //~va1JI~
                        printsw=1;                                 //~va1JI~
                    }                                              //~va1JI~
                }                                                  //~va1JI~
                if (!printsw)                                      //~va1JI~
                	uerrmsg("No entry to list",0);                 //~va1JI~
            }                                                      //~va1JI~
            else                                                   //~va1JI~
            {                                                      //~va1JI~
                backno=atoi(cmdstr+1);                             //~va1JR~
                if (!backno||backno>cmdsvmaxno)                    //~va1JR~
                    backno=cmdsvmaxno;                             //~va1JR~
                for (ii=0,jj=cmdsvno-1;ii<backno;ii++,jj--)        //~va1JR~
                {                                                  //~va1JR~
                    if (jj<0)                                      //~va1JR~
                    {                                              //~va1JR~
                        if (cmdsvmaxno)                            //~va1JR~
                            jj=cmdsvmaxno-1;                       //~va1JR~
                        else                                       //~va1JR~
                            break;                                 //~va1JR~
                    }                                              //~va1JR~
                    printsw=1;                                     //~va1JI~
                    printf("-%02d: %s\n",ii+1,cmdsv[jj]);          //~va1JR~
                }                                                  //~va1JR~
                if (!printsw)                                      //~va1JI~
                	uerrmsg("No entry to list",0);                 //~va1JI~
            }                                                      //~va1JI~
            continue;                                              //~va1JI~
        }                                                          //~va1JI~
	    rc=ucalc_bcmain(cmdstr,0);                                 //~va1JR~
        rct+=rc;                                                   //~va1JI~
        if (!rc)                                                   //~va1JI~
        {                                                          //~va1JI~
        	if (!retrievesw)                                       //~va1JI~
            {                                                      //~va1JI~
                sprintf(cmdsv[cmdsvno],"%s:=%s",cmdstr,Gucalc_result[0]);//~va1JR~
                cmdsvno++;                                         //~va1JR~
                if (cmdsvmaxno<MAXSVNO)                            //~va1JI~
	                cmdsvmaxno++;	    //filled count             //~va1JI~
                if (cmdsvno>=MAXSVNO)                              //~va1JR~
                    cmdsvno=0;                                     //~va1JR~
            }                                                      //~va1JI~
        }                                                          //~va1JI~
    }                                                              //~va1JI~
	if (*Pfnm)                                                     //~vas3I~
	    fclose(fh);                                                //~vas3I~
    return rct;                                                    //~va1JR~
}//xbcfile                                                         //~va1JI~
//**************************************************************** //~0513I~
// help msg                                                        //~0513I~
//*rc   :0                                                         //~0513I~
//**************************************************************** //~0513I~
void help(void)                                                    //~0513I~
{                                                                  //~0513I~
//************                                                     //~v102I~
#define HELPMSG uerrhelpmsg(stdout,stderr,                         //~v102I~
//************                                                     //~0513I~
HELPMSG                                                            //~v102I~
"%s:%s:==(%c)== Basic Calculator (%s) ==============================\n",//~v102R~
"%s:%s:==(%c)== �ȈՌv�Z�c�[�� (%s) ================================\n",//~v102R~
            Spgmid,VERSION,OSTYPE,__DATE__);                       //~0513R~
                                                                   //~0513I~
//  if (Sdbcssw)                                                   //~v102R~
//  {                                                              //~v102R~
HELPMSG                                                            //~va1JI~
"Format1: %s %cf[filename]\n",                                     //~va1JI~
"�`��1: %s %cf[filename]\n",Spgmid,CMDFLAG_PREFIX);                //~va1JR~
HELPMSG                                                            //~va1JI~
"    -filename: file containing format2 string, or stdin if filename missing.\n",//~va1JI~
"    -filename: �`��2�̍s���܂ރt�@�C�����A�t�@�C�������Ȃ��ƕW�����͂�ǂށB\n");//~va1JI~
HELPMSG                                                            //~v102I~
//"Format: %s value1 [ operation value2 ] [/output-type]\n",       //~va1kR~
//"�`��: %s value1 [ operation value2 ] [/output-type]\n",Spgmid); //~va1kR~
//"Format: %s value1 [ operation value2 ] [/output-type] [V[n][R]]\n",//~va1JR~
//"�`��: %s value1 [ operation value2 ] [/output-type] [V[n][R]]\n",Spgmid);//~va1JR~
//"Format2: %s [$n=]value1 [ operation value2 ] [/output-type] [V[n][R]]\n",//~va1JR~//~vaf0R~
//"�`��2: %s [$n=] value1 [ operation value2 ] [/output-type] [V[n][R]]\n",Spgmid);//~va1JR~//~vaf0R~
  "Format2: %s [$n=]value1 [ op value2] [ op value3 ...] [/output-type] [V[n][R]]\n",//~vaf0R~
  "�`��2: %s [$n=] value1 [ op value2 ] [ op value3 ...] [/output-type] [V[n][R]]\n",Spgmid);//~vaf0I~
HELPMSG                                                            //~v102I~
//"    -value1/2:  [type]digit[.decimal]\n",                       //~va1hR~
//"    -value1/2: [type]digit[.decimal]\n");                       //~va1hR~
//"    -value1/2:  [type]digit[.decimal-fraction]\n",              //~va1JR~
//"    -value1/2: [type]digit[.decimal-fraction]\n");              //~va1JR~
"    -value1/2:  { [type]digit[.decimal-fraction] | $n }\n",       //~va1JI~
"    -value1/2: { [type]digit[.decimal-fraction] | $n }\n");       //~va1JI~
HELPMSG                                                            //~vaf0I~
"    -value3...:  up to 10 operation, calc sequencially left to right.\n",//~vaf0R~
"    -value3...:  �ő�P�O���Z��A���A������E�ɏ��Ɍv�Z����\n");  //~vaf0I~
HELPMSG                                                            //~va1JI~
"       $n  : n=0(latest),1-->9; variable to save and reuse later.\n",//~va1JI~
"       $n  : n=0(�ŋ߂̌���),1-->9; �ۑ��A�Ďg�p�̂��߂̕ϐ����B\n");//~va1JI~
HELPMSG                                                            //~v102I~
//"       type: z:decimal, x:hexadecimal, o:octal, t:hhmmss[.xxx] fmt.\n",//~va1hR~
//"       type: z:10�i��, x:16�i��, o:8�i��, t:hhmmss[.xxx] �`���̎��ԁB\n");//~va1hR~
"       type: z:decimal, -:minus decimal, x:hexadecimal, o:octal, t:hhmmss fmt.\n",//~va1hR~
"       type: z:10�i��, -:����10�i��, x:16�i��, o:8�i��, t:hhmmss �`���̎��ԁB\n");//~va1hR~
HELPMSG                                                            //~v102I~
"       Decimal is up to 19 digit and may contain seperator \",\".\n",//~v102I~
"       10�i���� 19���܂ŁA��؂蕶�� \",\" �������Ă��悢�B\n");  //~v102R~
HELPMSG                                                            //~v102I~
"       If type is ommitted,decimal when all digit is 0 to 9,\n",  //~v102I~
"       ���w��́A�S��10�i���Ȃ�10�i���A�S�Ă�16�i���Ȃ�16�i���A\n");//~v102R~
HELPMSG                                                            //~v102I~
"       x when all is valid hexadecimal digit,t when hh:mm:ss format.\n",//~v102I~
"       hh:mm:ss�`���Ȃ玞�ԁB�����_�ȉ���9���܂�(�A��x �� o �ȊO)�B\n");//~v102R~
HELPMSG                                                            //~v102I~
//"       After decimal point,up to 9 digit is allowed except for x and o.\n",//~va1hR~
"       Up to 9 digit decimal-fraction is allowed except for x and o.\n",//~va1hI~
//"       �_�u�����[�h��16�i�����[�h��\"..\"�ŘA������B�Ⴆ�� abcdef01..23456789�B\n");//~va1hR~
"       �_�u�����[�h16�i���̓��[�h��\"..\"�ŘA������B�Ⴆ�� abcdef01..23456789�B\n");//~va1hI~
HELPMSG                                                            //~v102I~
//"       For double word, concatinate 2 word hex-decimal by \"..\"\n",//~va1hR~
"       For double word hex-decimal, concatinate 2 word hex-decimal by \"..\"\n",//~va1hI~
"    -operation: +,-,*,!,/,%%,   <,>,|,&,^ (!:�ݏ�A<,>:�V�t�g�A^:�r��OR)�B\n");//~v102R~
HELPMSG                                                            //~v102I~
"       like as abcded01..23456789.\n",                            //~v102I~
"       <,>,| �̎��S�̂�\"�ň͂ށB�����͂��ꂼ�� (,),~ �����Ɏg�p��\x94\\�B\n");//~v102R~
HELPMSG                                                            //~v102I~
"    -operation:  +,-,*,!,/,%%,  <,>,|,&,^.(!:power, <,>:shift, ^:exclusive OR.)\n",//~v102I~
"       �V�t�g�A�r�b�g���Z�͎��ԈȊO�ɗL���B�w��̂Ȃ��Ƃ���ϊ����s���B\n");//~v102R~
HELPMSG                                                            //~v102I~
"       Enclose by \" when use <,>,|. Or use (,),~ as alternative of each.\n",//~v102I~
//"       ���ԂƂ��̑��̃^�C�v�ł͑����͕b���Ƃ݂Ȃ��B���ԓ��m�̏揜�Z�͕b��\n");//~va1hR~
"       ���ԂƂ��̑��̃^�C�v�ł͑����͕b���Ƃ݂Ȃ��B\n");          //~va1hI~
HELPMSG                                                            //~v102I~
"       Shift or bit operation is valid except for time. If operation missing\n",//~v102I~
//"       �ϊ����Čv�Z�B\n");                                      //~va1hR~
" ");                                                              //~va1kR~
//HELPMSG                                                          //~va1hR~
//"       base conversion is done. Operand with type!=t is treated as seconds\n",//~va1hR~
//"       �_�u�����[�h�v�Z�� +,-,*,/,%% �̂݃T�|�[�g�B\n");        //~va1hR~
HELPMSG                                                            //~v102I~
//"       when calculated with time operand.Multiply and divide between times is\n",//~va1hR~
"       base conversion is done. \n",                              //~va1hI~
"   -output-type:���ʂ�\x95\\���`���B\n");                         //~va1kR~
HELPMSG                                                            //~v102I~
//"       also by the value of seconds. Decimal fraction for opd2 is supported,\n",//~va1hR~
"",                                                                //~va1kR~
//"       X:16�i���AO:8�i���AD:10�i���AU:��������10�i���AT:hh:mm:ss.xxx �`���̎���\n");//~va1hR~
"       X:16�i���AO:8�i���AD:10�i���AU:��������10�i���AT:hh:mm:ss �`���̎���\n");//~va1hI~
HELPMSG                                                            //~v102I~
//"       and double word calc is for +,-,*,/,%% only\n",          //~va1hR~
"",                                                                //~va1kR~
"       Z:zzz,zz9 �`���̕����t��10�i���AUZ:zzz,zz9 �`���̕�������10�i���B\n");//~v102R~
HELPMSG                                                            //~vashI~
"       S:translation of UCS-4 unicode and its UCS-2 surrogate.\n",//~vashI~
"       S:UCS-4 ���j�R�[�h�Ƃ���UCS-2 �T���Q�[�g\x95\\���Ƃ̕ϊ��B\n");//~vashR~
HELPMSG                                                            //~v102I~
"    -output-type:result display type.\n",                         //~v102I~
"       L:16�i�����[�h(1970�N����̌o�ߕb),���̓_�u�����[�h(HOST-TOD)��������\n");//~v102R~
HELPMSG                                                            //~v102I~
//"       x:hexadecimal, o:octal, d:decimal, u:unsigned decimal,t: hh:mm:ss.xxx\n",//~va1hR~
"       x:hexadecimal, o:octal, d:decimal, u:unsigned decimal,t: hh:mm:ss.\n",//~va1hI~
"       �ϊ��B(HOST-TOD�̓_�u�����[�h�̃r�b�g51���}�C�N���b�ł�)\n");//~v102R~
HELPMSG                                                            //~v102I~
"       z:decimal by zzz,zz9, uz:unsigned decimal by zzz,zz9,\n",  //~v102I~
"       �A��HOST-TOD��2000�N1��1���ȑO��1900�N1��1������̌o�ߕb�ɕϊ� �B\n");//~v102R~
HELPMSG                                                            //~v102I~
"       l(lower L):convert to clock from a word(seconds from 1970)\n",//~v102I~
"       �w��̂Ȃ��Ƃ� value1�̃f�[�^�^�C�v�ɂ��킹��B�A����ϊ��̎���\n");//~v102R~
HELPMSG                                                            //~v102I~
"       or double word(HOST-TOD.In double word bit 51 is unit of micro second).\n",//~v102I~
"       10�i��->16�i��, 8�i��/16�i��->10�i��,����->�b���Z10�i����\x95\\������B\n");//~v102R~
HELPMSG                                                            //~v102I~
"       When HOST-TOD is before 2000/01/01,it is displayed as elapsed second\n",//~v102I~
//"       x �� o �̂Ƃ������_�ȉ���\x95\\������Ȃ��B\n");         //~va1hR~
"       x �� o �̂Ƃ������_�ȉ���\x95\\������Ȃ��A�܂������͖�������B\n");//~va1hI~
HELPMSG                                                            //~v102I~
"       from 1900/01/01.\n",                                       //~v102I~
//" ");                                                            //~va1fR~
//"       ��Z���ʂ͕�����(U/UZ)�̎��_�u�����[�h�A�����łȂ����͌����͖�������B\n");//~va1hR~
" ");                                                              //~va1kR~
HELPMSG                                                            //~v102I~
//"       If ommitted it is from value1 type.But for base conversion,\n",//~va1hR~
"       If output-type ommitted it is from value1 type.But for base conversion,\n",//~va1hI~
" ");                                                              //~va1kR~
HELPMSG                                                            //~v102I~
//"       x for decimal,decimal for octal and hexadecimal,\n",     //~va1hR~
"       x for decimal,decimal for octal and hex and seconds for time.\n",//~va1hI~
" ");                                                              //~va1kR~
//HELPMSG                                                          //~va1hR~
//"       and decimal number of second for type=t.\n",             //~va1hR~
//" ");                                                            //~va1hR~
HELPMSG                                                            //~va1fI~
//"       For word multiply,result is double-word if signed(output type:U/UZ),\n",//~va1hR~
"       For x and o,decimal fraction is not displayed and overflow is ignored.\n",//~va1hR~
" ");                                                              //~va1kR~
//HELPMSG                                                          //~va1hR~
//"       else overflow is ignored.\n",                            //~va1hR~
//" ");                                                            //~va1hR~
HELPMSG                                                            //~va1kI~
"    -VnR:number of output decimal point digit. R:roundup option.\n",//~va1kR~
"  -VnR:�����_�ȉ������BR:�l�̌ܓ��B\n");                          //~va1kR~
HELPMSG                                                            //~v102I~
"  (ex) %s T010100 ; %s xfe0100   ; %s o177 ; %s \"e8ff>\" ; %s e8ff)3\n",//~v102R~
"  (��) %s T010100 ; %s xfe0100   ; %s o177 ; %s \"e8ff>3\" ; %s e8ff)3\n",Spgmid,Spgmid,Spgmid,Spgmid,Spgmid);//~v102M~
HELPMSG                                                            //~v102I~
"       %s T012159.12+t005212.333  ; %s xabcdef+1000\n",            //~v102I~//~vaf0R~
"       %s T012159.12+t005212.333  ; %s xabcdef+1000\n",Spgmid,Spgmid);//~v102R~//~vaf0R~
HELPMSG                                                            //~v102I~
"       %s 12345678..abcdef0/30a2  ; %s 3acf19fe/l\n",              //~v102I~//~vaf0R~
"       %s 12345678..abcdef0/30a2  ; %s 3acf19fe/l\n",Spgmid,Spgmid);//~v102R~//~vaf0R~
HELPMSG                                                            //~va1kI~
"       %s 1234.56*7.89 v2r        ; %s 123.45/6.789 vr\n",         //~va1kR~//~vaf0R~
"       %s 1234.56*7.89 v2r        ; %s 123.45/6.789 vr\n",Spgmid,Spgmid);//~va1kR~//~vaf0R~
HELPMSG                                                            //~vaf0I~
"       %s 200/3.3*35 v2r          ; %s 1+2+3+4+5+6+7+8+9+10\n",   //~vaf0I~
"       %s 200/3.3*35 v2r          ; %s 1+2+3+4+5+6+7+8+9+10\n",Spgmid,Spgmid);//~vaf0I~
HELPMSG                                                            //~vashI~
"       %s x20bb7/s                ; %s d842dfb7/s\n",             //~vashI~
"       %s x20bb7/s                ; %s d842dfb7/s\n",Spgmid,Spgmid);//~vashR~
//  }                                                              //~v102R~
//  else                                                           //~v102R~
//  {                                                              //~v102R~
//  }                                                              //~v102R~
	return;                                                        //~0513I~
}//help                                                            //~0513I~
