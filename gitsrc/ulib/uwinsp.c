//CID://+v6hdR~:         update#=      11                          //+v6hdR~
//*************************************************************
//*************************************************************
//v6hd:120616 for VC6:/W4 warning                                  //+v6hdI~
//v190:980802 add member uwinsp.c(windows system programming)
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <io.h>                     //v3.7a
//*************************
#include <windows.h>
//*************************
#include <ulib.h>
#include <uerr.h>
#include <udos.h>
#include <uwinsp.h>
//*************************
//********************************************************************
//*get tib addr(thread information block)
//*parm :none
//*rc   :(void *)tib
//********************************************************************
void *uwinsp_gettib(void)
{
#define FS_TIB   18h
	void *ptib;
//*********************
    __asm{
        	mov eax,fs:[FS_TIB]     ;ptib
            mov ptib,eax
         }
	return ptib;
}//uwinsp_gettib
//********************************************************************
//*get pdb addr(process DB)
//*parm :none
//*rc   :(void *)tib
//********************************************************************
void *uwinsp_getpdb(void)
{
#define TIB_PTHDB   0x50
#define THDB_PPDB95 0x04
#define THDB_PPDB98 0x08
	char *pthdb,*ptib,*ppdb;
//*********************
    ptib=uwinsp_gettib();
    pthdb=UGETPV(char*,ptib+TIB_PTHDB);
    if (udosiswin98())
    	ppdb=UGETPV(char*,pthdb+THDB_PPDB98);
    else
	    ppdb=UGETPV(char*,pthdb+THDB_PPDB95);
	return (void*)ppdb;
}//uwinsp_getpdb
//********************************************************************
//*get handle entry from HANDLE
//*parm :handle
//*rc   :(void *)tib
//********************************************************************
void *uwinsp_gethandelentry(HANDLE Phandle)
{
#define PDB_PEDB       0x40        //environment table
#define PDB_PPHT       0x44        //process handle table
#define EDB_STDIN      0x14        //stdin real handle value saved
#define EDB_STDOUT     0x18        //stdout real handle value saved
#define EDB_STDERR     0x1c        //stdout real handle value saved
	char*ppdb,*ppht,*pedb;
    HANDLE handle;
//*********************
    ppdb=uwinsp_getpdb();
    pedb=UGETPV(char*,ppdb+PDB_PEDB);
    ppht=UGETPV(char*,ppdb+PDB_PPHT);
    handle=Phandle;
//*conv predefined value to real value
	if ((DWORD)handle==STD_INPUT_HANDLE)
        handle=UGETPV(char*,pedb+EDB_STDIN);
    else
        if ((DWORD)handle==STD_OUTPUT_HANDLE)
            handle=UGETPV(char*,pedb+EDB_STDOUT);
        else
            if ((DWORD)handle==STD_ERROR_HANDLE)
                handle=UGETPV(char*,pedb+EDB_STDERR);
            else
                if (handle<=0)
                    return 0;

    if (udosiswin98())				//w98:handle=08(stdin),0c,10,...
	    ppht+=4+((DWORD)handle<<1);		//8 byte entry
    else                            //w95:handle=2(stdin),3,4,...
	    ppht+=4+((DWORD)handle<<3);		//8 byte entry
	return (void*)ppht;
}//uwinsp_gethandelentry
//********************************************************************
//*get handle value from HANDLE
//*parm :handle
//*rc   :handle value
//********************************************************************
void *uwinsp_gethandlevalue(HANDLE Phandle)
{
#define PHTE_HANDLEVALUE 0x04
	char *pphte;
	void *handlevalue;
//*********************
    if (!(pphte=uwinsp_gethandelentry(Phandle)))
    	return 0;
    handlevalue=UGETPV(char*,pphte+PHTE_HANDLEVALUE);	//2nd DWORD
	return handlevalue;
}//uwinsp_gethandlvalue
//********************************************************************
//*get VxD handle
//*parm1:VXD name
//*parm2:output handle area addr
//*rc   :create file err code
//********************************************************************
int uwinsp_getvxdhande(char *Pvxdnm,HANDLE *Pphandle)
{
    HANDLE      handle;
    int ercd;
//*********************
    handle=CreateFile(Pvxdnm,
						 0,
						0,                                         //~v190R~
						NULL,                                      //~v190R~
                        0,                                         //~v190R~
						0,                                         //~v190R~
						NULL);                                     //~v190I~
	*Pphandle=handle;
    if (handle!=INVALID_HANDLE_VALUE)
    	return 0;
    ercd=GetLastError();
    if (ercd==ERROR_NOT_SUPPORTED)
    	uerrmsg("Unable to open VxD(%s),device does not support DeviceIOCTL\n",
				0,
				Pvxdnm);
    else
        uerrapi1("CreateFile",Pvxdnm,ercd);
	return ercd;
}//uwinsp_getvxdhande
//********************************************************************
//*get VxD DDB
//*parm1:VXD id
//*parm2:VXD name
//*parm3:output ddb ptr area
//*rc   :4:not found,8:not avail
//********************************************************************
int uwinsp_getvxdddb(WORD Pvxdid,char *Pvxdnm,void **Pppddb)
{
//VCOND dose not support DeviceIoControl,                          //~v190I~
//CreateFile faile by ERROR_NOT_SUPPORTED                          //~v190I~
//So use vwin32 and search VCOND DDB                               //~v190I~
#define SAMPLE_VXDNM   "vwin32"
#define FILETBL_DDB98  0x04
#define FILETBL_DDB95  0x0c
#define DDB_NEXT       0
#define DDB_VXDID      0x06
#define DDB_VXDNAME    0x0c
#define DDB_PREV       0x3c
	HANDLE handle;
    char *pddb,*pddb0,*filetbl;
    char *vxdfilenm={"\\\\.\\" SAMPLE_VXDNM};                      //~v190R~
    char vxdnm[8];
    int len,rc;
//*********************

	if (rc=uwinsp_getvxdhande(vxdfilenm,&handle),rc)
        return 8;
	if (!(filetbl=uwinsp_gethandlevalue(handle)))
    	return 8;
    if (udosiswin98())				//w98:handle=08(stdin),0c,10,...
		pddb0=UGETPV(char*,filetbl+FILETBL_DDB98);
    else
		pddb0=UGETPV(char*,filetbl+FILETBL_DDB95);
	CloseHandle(handle);                                           //~v190I~
    if (Pvxdnm)
    {
        len=(UINT)strlen(Pvxdnm);
        if (len>8)
            return 8;
        memset(vxdnm,' ',8);
        memcpy(vxdnm,Pvxdnm,(UINT)len);
    }
//forward search
    for (pddb=pddb0;pddb;pddb=UGETPV(char*,pddb+DDB_NEXT))
    {
    	if (Pvxdnm)
        {
        	if (!memicmp(vxdnm,pddb+DDB_VXDNAME,8))
            	break;
		}
        else
        	if (Pvxdid==UGETPV(WORD,pddb+DDB_VXDID))
            	break;
    }
//backward search
	if (!pddb)
        for (pddb=pddb0;pddb;pddb=UGETPV(char*,pddb+DDB_PREV))
        {
            if (Pvxdnm)
            {
                if (!memicmp(vxdnm,pddb+DDB_VXDNAME,8))
                    break;
            }
            else
                if (Pvxdid==UGETPV(WORD,pddb+DDB_VXDID))
                    break;
        }
	if (!pddb)		//not found
    	return 4;
	*Pppddb=pddb;
	return 0;
}//uwinsp_getvxdddb

//********************************************************************
//*get VxD searvice addr
//*parm1:VXD service id
//*parm2:output ddb ptr area
//*rc   :4:not found,8:not avail
//********************************************************************
int uwinsp_getvxdservice(DWORD Pservice,void **Pppfunc)
{
#define DDB_WIN32SVC	0x38
    WORD 	vxdid;
    char 	*pddb;
    char 	*pfunc;
    int 	subid,rc;
//*********************
	vxdid=(WORD)(Pservice>>16);
    subid=(Pservice & 0xffff);
	rc=uwinsp_getvxdddb(vxdid,0,&pddb);//by id not name
    if (rc)
        return rc;
	pfunc=UGETPV(char*,pddb+DDB_WIN32SVC);
    if (UGETPV(WORD,pfunc)<=(WORD)subid)
    	return 4;
	pfunc+=(4+(subid<<3));	//8 byte entry(parmno+func addr)
    *Pppfunc=UGETPV(char*,pfunc+4);
	return 0;
}//uwinsp_getvxdservice(
//********************************************************************
//*get VCOND HDR table
//*		get addr from VCOND service rtn instruction
//*w98:   00380001
//*               8b44240c       mov eax,[esp+0c]
//*               8b0485946432c0 mov eax,[c0326494+eax*4]
//*w95:   00380001
//*               5f,5e,5b       push edi,esi,ebx
//*               e805d040000    call +045d
//*
//*       +045d   ...
//*          +09  8b04854c4432c0 mov eax,[c032444c+eax*4]
//*parm1:output top ptr area
//*rc   :4:not found,8:not avail 12:vcond changed
//********************************************************************
int uwinsp_getvcondtop(void **Pptop)
{
#define VCOND_FUNC1 	0x00380001
#define VCOND_MOVE      0x8b
//w98
#define VCOND_98TOP1      4
#define VCOND_98TOP2      7
//w95
#define VCOND_NEARCALL  0xe8
#define VCOND_95TOP1      3     //near call inst
#define VCOND_95TOP2      4     //near call offset
#define VCOND_95TOP3      9     //move inst
#define VCOND_95TOP4     12     //move inst operand offset
    char 	*pfunc;
    int 	rc;
//*********************
	rc=uwinsp_getvxdservice(VCOND_FUNC1,&pfunc);
    if (rc)
    	return rc;
    if (udosiswin98())
    {
        if (*(pfunc+VCOND_98TOP1)!=VCOND_MOVE)
        {
            uerrmsg("VCOND W98 version changed",0);
            return 12;
        }
        *Pptop=UGETPV(char*,pfunc+VCOND_98TOP2);
    }
    else
    {
        if (*(pfunc+VCOND_95TOP1)!=VCOND_NEARCALL)
        {
            uerrmsg("VCOND W95 version changed",0);
            return 12;
        }
        pfunc+=VCOND_95TOP1+5+UGETPV(DWORD,pfunc+VCOND_95TOP2);
        if (*(pfunc+VCOND_95TOP3)!=VCOND_MOVE)
        {
            uerrmsg("VCOND W95 version changed",0);
            return 12;
        }
        *Pptop=UGETPV(char*,pfunc+VCOND_95TOP4);
    }
	return 0;
}//uwinsp_getvcondtop
//********************************************************************
//*get VCOND event table HDR
//*parm1:console number
//*parm2:output event hdr area
//*rc   :4:not found,8:not avail 12:vcond changed
//********************************************************************
//int uwinsp_geteventhdr(int Pconno,void **Ppevh)                  //+v6hdR~
int uwinsp_geteventhdr(DWORD Pconno,void **Ppevh)                  //+v6hdI~
{
#define CONH_EVENTHDR   8
    char 	*ptop,*conhdr;
    int rc;
//*********************
	if (rc=uwinsp_getvcondtop(&ptop),rc)
    	return rc;
	conhdr=UGETPV(char*,ptop+Pconno*4);
    *Ppevh=UGETPV(char*,conhdr+CONH_EVENTHDR);
	return 0;
}//uwinsp_geteventhdr
//********************************************************************//~v190I~
//*get current console id                                          //~v190I~
//*parm1:get handle                                                //~v190I~
//*parm2:output conid area                                         //~v190I~
//*rc   :4:not found,8:not avail 12:vcond changed                  //~v190I~
//********************************************************************//~v190I~
//int uwinsp_getcurrentconid(HANDLE Phandle,int *Pconid)             //~v190I~//+v6hdR~
int uwinsp_getcurrentconid(HANDLE Phandle,DWORD *Pconid)           //+v6hdI~
{                                                                  //~v190I~
//  int readctr;                                                   //~v190R~//+v6hdR~
    DWORD readctr;                                                 //+v6hdI~
    char *oesp;                                                    //~v190I~
//*********************                                            //~v190I~
	if (!GetNumberOfConsoleInputEvents(Phandle,&readctr))          //~v190I~
        uerrapi1x("GetNumberOfConsoleInputEvents","STD_INPUT",GetLastError());//~v190I~
    __asm {                                                        //~v190I~
            mov   oesp,esp          //stack                        //~v190I~
    }                                                              //~v190I~
    *Pconid=(DWORD)UGETPV(char*,oesp-0x10);                        //~v190I~
    return 0;                                                      //~v190I~
}//uwinsp_getcurrentconid                                          //~v190I~
//********************************************************************
//*get VCOND event table HDR
//*parm1:get handle
//*parm2:output event hdr area
//*rc   :4:not found,8:not avail 12:vcond changed
//********************************************************************
int uwinsp_getcurrenteventhdr(HANDLE Phandle,void **Ppevh)
{
    DWORD conid;                                                   //~v190R~
    int rc;                                                        //~v190I~
//*********************
	uwinsp_getcurrentconid(Phandle,&conid);                        //~v190R~
	if (rc=uwinsp_geteventhdr(conid,Ppevh),rc)                     //~v190R~
    	return rc;
	return 0;
}//uwinsp_getcurrenteventhdr
