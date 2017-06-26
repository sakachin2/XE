//CID://+va30R~:                                                   //~va30R~
//*************************************************************
//061227 va30:xlm v1.1 filesize>4GB support                        //~va30I~
//*XLM.c   list magic(MZ,LX etc)                                   //~v001R~
//*format
//*      xlm   fnm                                                 //~v001R~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>                                                 //~9309I~
#ifdef DOS
#else
  #ifdef W32
    #include <windows.h>
  #else
  #endif
#endif
//********************
#include <ulib.h>
#include <uerr.h>
#include <ualloc.h>
#include <udbcschk.h>
#include <ufile.h>      //ufullpath
#include <udaimage.h>                                              //~9103R~
#include <uda.h>                                                   //~v001I~
#include <uedit.h>                                                 //~v001I~
#include <ucalc2.h>                                                //~va30I~
//********************
#include <xda.h>                                                   //~va30R~
#include <xdaw3.h>                                                 //~va30R~
#include <xdaw4.h>                                                 //~va30R~
//********************
//********************
#define PGM            XLM                                         //~v001R~
#define VERSION        v1.1                                        //~va30R~
                                                                   //~v001I~
#define NEWEXE_EXIST   0x0040 	//x40  MZ exe has new exe ptr      //~9307I~
#define LASTRANGE 0xffffffff	//range up to eof
//********************                                             //~9128I~
static	char Spgmver[16];
static	FILE *Sfh;                                                 //~v001I~
//********************
int xlmexe(UCHAR *Pfnm,USHORT *Ppmagic);                           //~v001R~
void xlmopen(UCHAR *Pfnm);                                         //~v001R~
ULONG xlmread(UCHAR *Pfnm,void *Pbuff,ULONG Poffs,ULONG Plen,UCHAR *Perrmsg);//~v001R~
//*************************************************************
int main(int parmc,char * parmp[])
{
	FILEFINDBUF3 fstat3;                                           //~v006I~
    UCHAR *fnm;                                                    //~v001R~
//  char editwkn[16];                                              //~va30R~
    char editwkn[32];                                              //~va30I~
	int rc;                                                        //~v001M~
    USHORT magic;                                                  //~v001I~
//**********************
#ifdef DPMI					//DPMI version
    putenv("LFN=Y");                 //need for ufileisvfat
	ufileisvfat(ISVFAT_FORCE);      //force vfat
#endif                      //DPMI or not
    if (parmc<2)                                                   //~v001I~
    {                                                              //~v001I~
        printf("xlm:print pagic and size\n");                      //+va30R~
        printf("parm1:filename\n");                                //+va30I~
        exit(8);                                                   //~v001I~
    }                                                              //~v001I~
	fnm=parmp[1];                                                  //~v001R~
	if (ufstat(fnm,&fstat3))                                       //~v001R~
    {                                                              //~v001I~
		printf("%s not found",fnm);                                //~v001R~
        exit(8);                                                   //~v001I~
    }                                                              //~v001I~
//print parm after redirect                                        //~v001I~
	rc=xlmexe(fnm,&magic);                                         //~v001R~
#ifdef LFSSUPP                                                     //~va30I~
    bc_dweditnum64(0/*functype*/,'Z'/*Pconvtype*/,fstat3.cbFile,editwkn);//~va30R~
#else                                                              //~va30I~
    unumedit(fstat3.cbFile,"z,zzz,zzz,zz9",editwkn);               //~v001I~
#endif                                                             //~va30I~
    if (!rc)                                                       //~v001R~
		printf("** magic=%.2s       * %-36s (%s)\n",&magic,fnm,editwkn);//~v001R~
    else                                                           //~v001I~
		printf("** magic=?? x%04X * %-36s (%s)\n",magic,fnm,editwkn);//~v001R~
    return rc;
}//main
//**********************************************************************
//**********************************************************************
int xlmexe(UCHAR *Pfnm,USHORT *Ppmagic)                            //~v001R~
{
    IMAGE_DOS_HEADER dosh;
    ULONG newhdrpos;
    USHORT magic;
    int rc;                                                        //~v001I~
//**********************************
	xlmopen(Pfnm);                                                 //~v001R~
//*dos hdr chk
    xlmread(Pfnm,&dosh,0,2,"EXE signature");   //mz header         //~v001R~
    if (dosh.e_magic!=IMAGE_DOS_SIGNATURE)  //not MZ
        magic=0;						//sign of file disas       //~v008R~
    else                                                           //~v008I~
    {                                                              //~v008I~
        xlmread(Pfnm,&dosh,0,sizeof(dosh),"MZ file hdr");   //mz header//~v001R~
//new hdr
        if (dosh.e_lfarlc!=NEWEXE_EXIST)    //x40                  //~v008R~
            magic=IMAGE_DOS_SIGNATURE; //go through                //~v008R~
        else                                                       //~v008R~
        {                                                          //~v008R~
            newhdrpos=(ULONG)dosh.e_lfanew;   //new exe hdr offset //~v001R~
            if (!newhdrpos)   //new exe hdr offset                 //~v008R~
                uerrexit("No new exe header defined",0);           //~v008R~
            xlmread(Pfnm,&magic,newhdrpos,4,"new exe hdr magic");   //new exe hdr top//~v001R~
        }                                                          //~v008R~
    }//exe hdr found                                               //~v008I~
	switch(magic)
    {
    case (USHORT)IMAGE_NT_SIGNATURE:  //PE00
    case IMAGE_VXD_SIGNATURE:  //LE                                //~9317R~
    case NEMAGIC:  				//NE                               //~9109I~
    case E32MAGIC:  			//LX                               //~9110I~
    case W3MAGIC:  				//W3                               //~9515I~
    case W4MAGIC:  				//W4                               //~9523I~
    case IMAGE_DOS_SIGNATURE:   //MZ                               //~v003I~
        rc=0;                                                      //~v001I~
        break;                                                     //~v001I~
	default:
        rc=4;                                                      //~v001I~
	}
    *Ppmagic=magic;                                                //~v001I~
	return rc;                                                     //~v001R~
}//xlmexe                                                          //~v001R~
//**********************************************************************
//*open input file
//* parm1:cmdparm
//**********************************************************************
void xlmopen(UCHAR *Pfnm)                                          //~v001R~
{
//****************
	if (!(Sfh=fopen(Pfnm,"rb")))                                   //~v001R~
		uerrexit("%s open failed rc=%d",0,
				Pfnm,errno);                                       //~v001R~
    return;
}//xlmopen                                                         //~v001R~
//**********************************************************************
//*read input file
//* parm1:cmdparm
//* parm2:out area
//* parm3:offset
//* parm4:len                                                      //~9103R~
//* parm5:err msg when short len,if 0 return short len             //~9103I~
//* ret  :read len                                                 //~9103I~
//**********************************************************************
ULONG xlmread(UCHAR *Pfnm,void *Pbuff,ULONG Poffs,ULONG Plen,UCHAR *Perrmsg)//~v001R~
{
	ULONG readlen;
    UCHAR *errmsg;                                                 //~9110I~
//****************
    errmsg=Perrmsg;                                                //~va30I~
	if (fseek(Sfh,(LONG)Poffs,SEEK_SET))                           //~v001R~
    	uerrexit("%s seek failed rc=%d,offset=%08lx(%s)\n",0,      //~9110R~
						Pfnm,errno,Poffs,errmsg);                  //~va30R~
    readlen=fread(Pbuff,1,Plen,Sfh);	//read 1 block             //~v001R~
    if (readlen<Plen)
    {                                                              //~9103I~
		if (ferror(Sfh))                                           //~v001R~
        	uerrexit("\n%s read failed rc=%d,pos=%08lx,reqlen=%08lx,read=%08lx(%s)",0,//~9110R~
						Pfnm,errno,Poffs,Plen,readlen,errmsg);     //~v001R~
        if (Perrmsg)                                               //~9103I~
        	uerrexit("%s's size is too short for %s;reqlen=%08lx from +%08lx,readlen=%08lx",0,//~9103I~
    					Pfnm,Perrmsg,Plen,Poffs,readlen);          //~v001R~
    }                                                              //~9103I~
	return readlen;
}//xlmread                                                         //~v001R~
