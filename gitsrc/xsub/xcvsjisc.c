//*CID://+vateR~:                             update#=   51;       //~vateR~
//***********************************************************
//* convert SJIS(Shift-JIS code(Japanese DBCS code)) constant
//  enclose by double quotation to Octal(\ooo) notation
//    usage  xcvsjisc input [output-dir]
//***********************************************************
//vate:241125 xfc1.30 text mode read detect 0x1a as EOF. need open not "r" but "rb"//~vateI~
//vaa0:160417 Lnx compiler warning                                 //~vaa0I~
//va9q:150529 xcvsjisc v1.3 parm count error(by xuerpck)           //~va9qI~
//va66:120628 (AMD64) VC10(VS2010) LP64 support                    //~va66I~
//va64:120611 avoid C4701 warning(variable may not be uninitialized)//~va64I~
//va3s:080131 xcvsjisc v1.2 output filename parm by not 2nd parm but -o to avoid erroneous override//~v31sI~
//va3r:080129 xcvsjisc:v1.2 option to issue warning if 0x5c is 2nd byte of dbcs//~v31rI~
//va31:070226 xcvsjisc:v1.1:chk output file override inout         //~v31rR~
//                           open fail if input is file            //~v31aI~
//***********************************************************
//***********************************************************
#define VER "V1.4"   //version                                     //~vaa0R~
#define PGMID   "xcvsjisc"
#define RBUFFSZ 4096
//*************************************************************
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*****************************************************************

#ifdef DOS

#else
    #ifdef W32
		#include <dos.h>
    #else
#define INCL_BASE
#include <os2.h>
    #endif
#endif

#include <ulib.h>
#include <uerr.h>
#include <ufile.h>
#include <udbcschk.h>
//+9411M~
//*********************************************************************
static char Sline[RBUFFSZ];
static char *Scurfile;		   //
static char *Sinpfname;
static char *Soutfname=0;
static int  Sallmemboutsw=0,Skatakanasw,Shexsw;
static int  Scheck0x5csw=0,Signcmtsw=0;                            //~v31rR~
//************
int fileproc(FILE *Pinputfh,FILE *Poutputfh,int Pwritesw);
FILE *openfile(char*,char*);            //wild card file open
int  getinput(FILE *Pfh);
void help(void);
int listgen(char *Pdirname,PUDIRLIST *Pppudirlist);
//*********************************************************************
int main(int parmc,char *parmp[])
{
	char *cptr;         //char ptr work
	char ch;
	int  fctrmax;
//	int  ii,rc,jj,pathlen,outpathlen,totfile=0,cvfile=0;           //~v31aR~//~va64R~
  	int  ii,rc,jj,pathlen,outpathlen=0,totfile=0,cvfile=0;         //~va64I~
	int parmno; //parm count work
	int posparmno=0; //parm count work
	PUDIRLIST pudirlist=NULL;                                      //~va64R~
	char pgmver[18];
    char inpfnm[_MAX_PATH];
    char outfnm[_MAX_PATH];
    FILEFINDBUF3 fstat3;
    int dirsw,outdirsw,cvsw=0;                                     //~va64R~
    FILE *inputfh=NULL;        //handle
    FILE *outputfh=NULL;        //handle
//*************************
	sprintf(pgmver,"%s:%s:",PGMID,VER);
  	uerrmsg_init("",stderr,UERR_FORCE_ENGLISH);//default color
	uerrexit_init("",stderr,0,0,0);//no mapfile,no exit,no exit parm

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
#ifdef UNX
  		if(*cptr=='-')
#else
  		if(*cptr=='/'||*cptr=='-')
#endif
  		{//option
    		ch=*(++cptr);                      //first option byte
    		switch(toupper(ch))       //option
    		{
//**************************
//* help msg      /H        *
//**************************
    		case '?':
    		case 'H':
	  			help();
      			exit(4);
      			break;
    		case 'O':                                              //~v31sI~
      			Soutfname=cptr;                                    //~v31sI~
      			break;                                             //~v31sI~
//**************************
//* set option     /Y      *
//**************************
    		case 'Y':
            	cptr++;
	  			while (*cptr)
	 			{
	      			switch (toupper(*cptr))
    	  			{
	      			case 'A':
                        Sallmemboutsw=1;
                        break;
	      			case 'B':                                      //~v31rI~
                        Scheck0x5csw=1;                            //~v31rI~
                        break;                                     //~v31rI~
	      			case 'C':                                      //~v31rI~
                        Signcmtsw=1;                               //~v31rI~
                        break;                                     //~v31rI~
	      			case 'K':
                        Skatakanasw=1;
                        break;
	      			case 'X':
                        Shexsw=1;
                        break;
	      			default:
						uerrexit("\nToggle Set parm(%s) err",0,
								parmp[parmno]);
	      			}//switch by /Nx
		  			cptr++;
      			}//until strlen
      			break;
//**************************
//* reset option     */N
//**************************
    		case 'N':
            	cptr++;
	  			while (*cptr)
	  			{
	      			switch (toupper(*cptr))
    	  			{
	      			case 'A':
                        Sallmemboutsw=0;
                        break;
	      			case 'B':                                      //~v31rI~
                        Scheck0x5csw=0;                            //~v31rI~
                        break;                                     //~v31rI~
	      			case 'C':                                      //~v31rI~
                        Signcmtsw=0;                               //~v31rI~
                        break;                                     //~v31rI~
	      			case 'K':
                        Skatakanasw=0;
                        break;
	      			case 'X':
                        Shexsw=0;
                        break;
	      			default:
						uerrexit("\nToggle Reset parm(%s) err",0,
								parmp[parmno]);
	      			}//switch by /Nx
		  			cptr++;
      			}//until strlen
      			break;
//**************************
//* option err             *
//**************************
    		default:                           //not option
					uerrexit("\nundefined option parm(%s)",0,
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
    		case  2:          //2nd   parm
//    			Soutfname=cptr;        break;                      //~v31sR~
                uerrexit("Too many positional parm,specify output filename by -o",0);//~v31sI~
//************************************
    		default:
	 				uerrexit("\ntoo many positional parameter(%s)",0,
							cptr);
    		}//switch by parmno
  		}//option or posparm
	}//for all parm
//***no pos parm chk
	if (posparmno==0)
		uerrexit("\nspecify input and output file name.",0);
//**********************************
//* init                           *
//**********************************
    if (!ufullpath(inpfnm,Sinpfname,sizeof(inpfnm)))
    	uerrexit("filename fmt err(%s)",0,Sinpfname);
    dirsw=1;
	if (WILDCARD(Sinpfname))
    	pathlen=PATHLEN(inpfnm);
    else
    {
    	if (ROOTDIR(inpfnm))
	    	uerrexit("invalid input filename(%s)",0,Sinpfname);
//  	pathlen=(int)strlen(inpfnm);                               //~v31aR~
        if (ufstat(inpfnm,&fstat3))
            uerrexit("%s not found",0,inpfnm);
        if  (fstat3.attrFile & FILE_DIRECTORY)
        {
  		  	pathlen=(int)strlen(inpfnm);                           //~v31aI~
            *(inpfnm+pathlen++)='\\';
            *(inpfnm+pathlen)=0;
        }
        else
        {                                                          //~v31aI~
	    	pathlen=PATHLEN(inpfnm);                               //~v31aI~
            dirsw=0;
        }                                                          //~v31aI~
	}
    fprintf(stderr,"<==== %s =====\n",inpfnm);
//outputdir
	outdirsw=-1;		//stdout
	if (Soutfname)
    {
    	if (!ufullpath(outfnm,Soutfname,sizeof(outfnm)))
    		uerrexit("filename fmt err(%s)",0,Soutfname);
		if (WILDCARD(Soutfname))
//  		uerrexit("Wildcard(%s) is invalid for output dir",Soutfname);//~va9qR~
    		uerrexit("Wildcard(%s) is invalid for output dir",0,   //~va9qI~
    			Soutfname);                                        //~va9qI~
//  	outpathlen=(int)strlen(outfnm);                            //~v31aR~
    	if (ROOTDIR(outfnm))
	    	uerrexit("invalid output filename(%s)",0,Soutfname);
//      if (ufstat(outfnm,&fstat3))                                //~v31aR~
//          uerrexit("%s not found",0,outfnm);                     //~v31aR~
//      rc=ufstat(outfnm,&fstat3);                                 //~v31aR~//~vaa0R~
        rc=(int)ufstat(outfnm,&fstat3);                            //~vaa0I~
	    fprintf(stderr,"====> %s =====\n",outfnm);
//      if  (fstat3.attrFile & FILE_DIRECTORY)                     //~v31aR~
        if  (!rc && fstat3.attrFile & FILE_DIRECTORY)              //~v31aI~
        {
  		  	outpathlen=(int)strlen(outfnm);                        //~v31aI~
            *(outfnm+outpathlen++)='\\';
            *(outfnm+outpathlen)=0;
            outdirsw=1;
        }
        else
        {                                                          //~v31aI~
            outdirsw=0;
	    	outpathlen=PATHLEN(outfnm);                            //~v31aI~
        }                                                          //~v31aI~
    }
 if (dirsw)                                                        //~v31aI~
   	fctrmax=listgen(inpfnm,&pudirlist);//create file list
 else                                                              //~v31aI~
    fctrmax=1;                                                     //~v31aI~
    if (!outdirsw)
		outputfh=openfile(outfnm,"w");
    else
    if (outdirsw<0)
		outputfh=stdout;
//*****************************
//* main loop                 *
//*****************************
	for (ii=0;ii<fctrmax;ii++,pudirlist++)
	{
      if (dirsw)    //input is dir/widlcard                        //~v31aI~
      {                                                            //~v31aI~
  		if (!*(Scurfile=pudirlist->name))
			continue;		//confirm reply 'N'
        if (!strcmp(Scurfile,"."))
        	continue;
        if (!strcmp(Scurfile,".."))
        	continue;
      }                                                            //~v31aI~
      else                                                         //~v31aI~
        Scurfile=inpfnm+pathlen;                                   //~v31aI~
        totfile++;
	    fprintf(stderr,"%03d=***** %s\n",totfile,Scurfile);
//      if (outdirsw)                                              //~v31aR~
        if (dirsw)                                                 //~v31aI~
			strcpy(inpfnm+pathlen,Scurfile);
        if (ufstat(inpfnm,&fstat3))
        {
            uerrmsg("%s not found",0,inpfnm);
            continue;
        }
        if  (fstat3.attrFile & FILE_DIRECTORY)
        {
            uerrmsg("%s directory",0,inpfnm);
            continue;
        }
        for (jj=Sallmemboutsw;jj<2;jj++)	//1st time chk sjis exist,2nd time write
        {
        	if (jj)		//2nd loop(write output)
                if (outdirsw>0)
                {
                    if (!strcmp(inpfnm,outfnm))                    //~v31aI~
                    {                                              //~v31aI~
			            uerrmsg("output file(%s) is same  input file",0,inpfnm);//~v31aI~
            			continue;                                  //~v31aI~
                    }                                              //~v31aI~
                    strcpy(outfnm+outpathlen,Scurfile);
                    outputfh=openfile(outfnm,"w");
                }
            inputfh=openfile(inpfnm,"r");                          //+vateR~
//          inputfh=openfile(inpfnm,"rb");   crlf/lf process required//+vateR~
            cvsw=fileproc(inputfh,outputfh,jj);
            fclose(inputfh);
        	if (jj)		//2nd loop(write output)
                if (outdirsw>0)
                    fclose(outputfh);
            if (!cvsw)
            	break;
        }
        if (cvsw)
        	cvfile++;
        else
		    fprintf(stderr,"    ***** contains no SJIS code.\n");
	}//all input file spec
    if (!outdirsw)
        fclose(outputfh);
	uerrmsg("\n%s=%c=process completed;%d file converted(total %d file)",0,
	  		pgmver,OSTYPE,cvfile,totfile);
  	return 0;

}//end main
//**********************************************************************
//* main process (1 file process)
//**********************************************************************
int fileproc(FILE *Pinputfh,FILE *Poutputfh,int Pwritesw)
{
    int len,lenw;
//  int cvsw=0,ch1,ch2,dbcssw;                                     //~va64R~
    int cvsw=0,ch1,ch2=0,dbcssw;                                   //~va64I~
	char outbuf[RBUFFSZ*4],*pco,*pc,*pce;
    int lineno=0,cmtsw;                                            //~v31rR~
    char *pc2;                                                     //~v31rI~
//*********
	while((len=getinput(Pinputfh))>0)     //until eof
 	{
    	lineno++;                                                  //~v31rI~
        for (pc=Sline,pco=outbuf,pce=pc+len;pc<pce;)
        {
        	ch1=*pc;
        	if (pc<pce-1 && SJIS1(ch1))
            {
            	ch2=*(pc+1);
                if (Pwritesw)   //write only once                  //~v31sI~
                    if (Scheck0x5csw && ch2=='\\' && *(pc+2)!='\\')//~v31sR~
                    {                                              //~v31sR~
                        cmtsw=0;                                   //~v31sR~
                        if (Signcmtsw)                             //~v31sR~
                        {                                          //~v31sR~
                            pc2=Sline+strspn(Sline," \t");         //~v31sR~
                            if (*pc2=='/' && *(pc2+1)=='/')        //~v31sR~
                                cmtsw=1;                           //~v31sR~
                        }                                          //~v31sR~
                        if (!cmtsw)                                //~v31sR~
                            fprintf(stderr,"\"\\\" Warning:% 5d:%c%c=0x%02x%02x:%s",lineno,ch1,ch2,ch1,ch2,Sline);//~v31sR~
                    }                                              //~v31sR~
	        	dbcssw=SJIS2(ch2);
            }
            else
            	dbcssw=0;
            if (dbcssw)
            {
				if (Shexsw)
	            	pco+=sprintf(pco,"\\x%02x\\x%02x",ch1,ch2);
                else
	            	pco+=sprintf(pco,"\\%03o\\%03o",ch1,ch2);
                pc+=2;
                cvsw=1;
			}
        	else
            {
            	if (Skatakanasw  &&  HANKATA(ch1))
                {
					if (Shexsw)
		            	pco+=sprintf(pco,"\\x%02x",ch1);
        	        else
	        	    	pco+=sprintf(pco,"\\%03o",ch1);
                    pc++;
	                cvsw=1;
                }
                else
            		*pco++=*pc++;
            }
        }
        if (Pwritesw)
        {
//        	lenw=(int)((ULONG)pco-(ULONG)outbuf);                  //~va66R~
        	lenw=(int)((ULPTR)pco-(ULPTR)outbuf);                  //~va66I~
//      	fwrite(outbuf,1,lenw,Poutputfh);                       //~vaa0R~
        	fwrite(outbuf,1,(size_t)lenw,Poutputfh);               //~vaa0I~
        }
	}//until eof
	return cvsw;
}//procfile
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
FILE *openfile(char *Ppfile,char *Popt)
{
	FILE *fh;
//***********************
  	if (!(fh=fopen(Ppfile,Popt)))  //open input fail
		uerrexit("\nfile(%s) open err",0,
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
    *(Sline+RBUFFSZ-1)=0;
	if (!fgets(Sline,RBUFFSZ,Pfh))	//null return if error or eof
    {
		if (ferror(Pfh))
			uerrexit("\n%s read error",0,Scurfile);
		else
			return -1;
    }
	len=(int)strlen(Sline);			//read len
	return len;
}//end of getinput
//**********************************************************************
//* write help msg
//**********************************************************************
void help(void)
{
//*******************
	uerrmsg("%s:%s",0,                                             //~v31rR~
			PGMID,VER);                                            //~v31rI~
	uerrmsg("  convert SJIS(Japanese DoubleByte code) constant to Octal(\\ooo) notation",0);
	uerrmsg("  for English user to edit xe's source.",0);
	uerrmsg("  SJIS-DBCS 1st byte is in the range of 0x81<==>0x9f and 0xe0<==>0xfc.\n",0);
//  uerrmsg("format: %s %coptions input-spec [output-spec]",0,     //~v31sR~
    uerrmsg("format: %s %coptions input-spec [-Ooutput-spec]",0,   //~v31sI~
			PGMID,CMDFLAG_PREFIX);
	uerrmsg("  input-spec  :file,dir or wild card",0);
	uerrmsg("  output-spec :file or dir,output to stdout if this is missing.",0);
	uerrmsg("  options     :  %cYx or %cNx.(CaseInsensitive)",0,
				CMDFLAG_PREFIX,CMDFLAG_PREFIX);
	uerrmsg("      x=A  -output also for the member contains no SJIS code",0);
	uerrmsg("      x=B  -Waring to stderr if detected \"\\\" as 2nd byte of DBCS",0);//~v31rR~
	uerrmsg("      x=K  -convert also HANKAKU-KATAKANA(0xa1<==>0xdf SingleByte code)",0);
	uerrmsg("      x=X  -convert to hex notation(\\xhh)",0);
	uerrmsg("         Warning! hex-decimal-notation may cause err by the following letters.",0);
	uerrmsg("                  because there is no limit on the number of digit",0);
	uerrmsg("                  unlike octal(max 3 digit) notation.",0);
	uerrmsg(" ex) %s %cYa *.c tmpdir",0,
				PGMID,CMDFLAG_PREFIX);
	return;
}//help
