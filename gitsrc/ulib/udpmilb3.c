//CID://+v230R~:                                                   //+v230R~
//*************************************************************
//*udpmilb3.c modifyed function of libc               //~v077R~
//*  udpmifindfirst:copyed src\libc\dos\dir\findfirs.c
//*  udpmifindnext :copyed src\libc\dos\dir\findnext.c
//*  then modified to return also alias at same time like as W95
//*************************************************************   
//v230:990320 (BUG:gcc)occured at dos session of os2;hdir addr is 0 when del file//+v230I~
//v193:980920 (BUG of GCC)no patherr msg                           //~v112I~
//            GCC(udpmifindfirst) return errno convert from ax of int 21.//~v112I~
//            but _dos_filen_first return ax.                      //~v112I~
//            udosfindfirst should return errno but udpmifindfirst //~v112I~
//            should return ax like as dos.                        //~v112I~
//            And GCC(doserr_to_errno) set same ENOENT for both ax=2 and 3.//~v112I~
//            so ufstat/udosfindfirst miss return coed set under GCC.//~v112I~
//v112:971103 (BUG)last null is not copyed to dirlist alias        //~v112I~
//v105:971026 (GCC)lfn support
//           -findfirst/findnext lfn support
//*************************************************************    //~v105I~
#include <stdio.h>                                                 //~v105R~
#include <libc/stubs.h>                                            //~v105I~
#include <stdlib.h>                                                //~v105I~
#include <string.h>                                                //~v105I~
#include <errno.h>                                                 //~v105I~
#include <fcntl.h>                                                 //~v105I~
#include <go32.h>                                                  //~v105I~
#include <dpmi.h>                                                  //~v105I~
#include <dir.h>                                                   //~v105I~
#include <libc/dosio.h>                                            //~v105I~
//*************************************************************    //~v105I~
#include <ulib.h>                                                  //~v105M~
#include <ufile.h>                                                 //~v105I~
#include <udpmilb3.h>                                              //~v105I~
#include <ustring.h>                                               //~v112I~
//**********************************************************************//~v105I~
static char Salias[MAXFILENAMEZ_FAT];	//parm between main and sub//~v105R~
static short Shdir;                                                //~v105I~
int udpmifindfirstsub(const char *pathname,struct ffblk *ffblk, int attrib);//~v105R~
int udpmifindnextsub(struct ffblk *ffblk);                         //~v105R~
//**********************************************************************//~v105I~
//!udpmifindfirst over djgpp findfirst                             //~v105I~
// find first:return FILEFINDBUF3 from ffblk and ffblklfn(short name)//~v105I~
// parm1  :file name                                               //~v105I~
// parm2  :HDIR ptr,if no contention,specify 0.for dos specify always 0//~v105I~
// parm3  :search file attribute                                   //~v105I~
// parm4  :found file info                                         //~v105I~
// return :r.c                                                     //~v105I~
//**********************************************************************//~v105I~
unsigned udpmifindfirst(char *Ppfname,HDIR *Pphdir,unsigned int Pattr,//~v105I~
						FILEFINDBUF3 *Ppfstat3)                    //~v105I~
{                                                                  //~v105I~
	struct ffblk *pffblk;                                          //~v105I~
    int rc;                                                        //~v105I~
//*************                                                    //~v105I~
	*Salias=0;                                                     //~v105I~
	Shdir=0;                                                       //~v105I~
	pffblk=(void*)Ppfstat3;                                        //~v105I~
	rc=udpmifindfirstsub(Ppfname,pffblk,(int)Pattr);               //~v105R~
    if (rc)                                                        //~v105I~
    	return rc;                                                 //~v105I~
	if (*Salias)	//lfn support on                               //~v105I~
//  	strncpy(Ppfstat3->achName,Salias,sizeof(Ppfstat3->achName)-1);//~v112R~
    	memcpy(Ppfstat3->achName,Salias,sizeof(Ppfstat3->achName));//~v112I~
    else		//fat                                              //~v105I~
		memcpy(Ppfstat3->achName,Ppfstat3->cFileName,sizeof(Ppfstat3->achName));//~v105R~
  if (Pphdir)   //confirm not null                                 //+v230I~
    *Pphdir=(unsigned long)Shdir;                                  //~v105I~
	return 0;                                                      //~v105I~
}//udpmifindfirst                                                  //~v105I~
//**********************************************************************//~v105I~
//!udpmifindnext over djgpp findnext                               //~v105I~
// find next :return FILEFINDBUF3 from ffblk and ffblklfn(short name)//~v105I~
// parm1  :HDIR specified at findfirst. for dos specify always 0   //~v105I~
// parm2  :found file info                                         //~v105I~
// return :r.c  0:found 4:no more file                             //~v105I~
//**********************************************************************//~v105I~
unsigned udpmifindnext(HDIR Phdir,FILEFINDBUF3 *Ppfstat3)          //~v105R~
{                                                                  //~v105I~
	struct ffblk *pffblk;                                          //~v105I~
    int rc;                                                        //~v105I~
//*************                                                    //~v105I~
	*Salias=0;                                                     //~v105I~
	pffblk=(void*)Ppfstat3;                                        //~v105I~
	Shdir=Phdir;			//parm to sub                          //~v105I~
	rc=udpmifindnextsub(pffblk);                                   //~v105R~
    if (rc)                                                        //~v105I~
    	return rc;                                                 //~v105I~
	if (*Salias)	//lfn support on                               //~v105I~
//  	strncpy(Ppfstat3->achName,Salias,sizeof(Ppfstat3->achName)-1);//~v112R~
    	memcpy(Ppfstat3->achName,Salias,sizeof(Ppfstat3->achName));//~v112I~
    else		//fat                                              //~v105I~
		memcpy(Ppfstat3->achName,Ppfstat3->cFileName,sizeof(Ppfstat3->achName));//~v105R~
	return 0;                                                      //~v105I~
}//udpmifindnext                                                   //~v105I~
//*************************************************************    //~v105I~
//*udpmifindfirstsub                                               //~v112R~
//*************************************************************
/* Copyright (C) 1996 DJ Delorie, see COPYING.DJ for details */
/* Copyright (C) 1995 DJ Delorie, see COPYING.DJ for details */
#include <libc/stubs.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <go32.h>
#include <dpmi.h>
#include <dir.h>
#include <libc/dosio.h>

int
//findfirst(const char *pathname, struct ffblk *ffblk, int attrib) //~v105R~
udpmifindfirstsub(const char *pathname, struct ffblk *ffblk, int attrib)//~v105I~
{
  __dpmi_regs r;
  int pathlen;
  int use_lfn = _USE_LFN;

  if (pathname == 0 || ffblk == 0)
  {
    errno = EACCES;
    return -1;
  }

  pathlen = strlen(pathname) + 1;

  _put_path(pathname);
  if(use_lfn) {

    /* si = 1 indicates DOS style dates, 0 means Win32 type dates.
       DOS style dates are broken in some Win95 betas, build for either.
       Release works with DOS date, it's faster, so use it. */
    #define USEDOSDATE 1
    #if USEDOSDATE == 1
      #define _Win32_to_DOS (long)
    #else
      extern long _Win32_to_DOS(long long WinTime);
    #endif

    r.x.ax = 0x714e;
    r.x.cx = attrib;
    r.x.dx = __tb_offset;
    r.x.ds = __tb_segment;
    r.x.di = __tb_offset + pathlen;
    r.x.es = r.x.ds;
    r.x.si = USEDOSDATE;
    __dpmi_int(0x21, &r);
    if(!(r.x.flags & 1)) {
      struct ffblklfn ffblk32;
      /* Recover results */
      dosmemget(__tb+pathlen, sizeof(struct ffblklfn), &ffblk32);

      ffblk->ff_attrib = (char)ffblk32.fd_attrib;
      *(long *)(&ffblk->ff_ftime) = _Win32_to_DOS(ffblk32.fd_mtime);
      ffblk->ff_fsize = ffblk32.fd_size;
      strcpy(ffblk->ff_name, ffblk32.fd_longname);
      strcpy(ffblk->lfn_magic, "LFN32");

      /* If no wildcards, close the handle */
      if(!strchr(pathname,'*') && !strchr(pathname,'?')) {
        r.x.bx = r.x.ax;
        r.x.ax = 0x71a1;
        __dpmi_int(0x21, &r);
        r.x.ax = 0;
      }
        
      ffblk->lfn_handle = r.x.ax;
      *(long *)(&ffblk->lfn_ctime) = _Win32_to_DOS(ffblk32.fd_ctime);
      *(long *)(&ffblk->lfn_atime) = _Win32_to_DOS(ffblk32.fd_atime);

      Shdir=ffblk->lfn_handle;                         //@@@@ output to main//~v105R~
//    strncpy(Salias,ffblk32.fd_name,sizeof(Salias)-1);//@@@@lfn support//~v112R~
      ustrncpyz(Salias,ffblk32.fd_name,sizeof(Salias));//@@@@lfn support//~v112I~
      return 0;
    }
  } else {

    #define _sizeof_dos_ffblk 44
    /* There will be a _sizeof_dos_ffblk character return value from findfirst 
       in the DTA.  Put the file name before this.  First set the DTA to be 
       transfer buffer. */

    r.x.dx = __tb_offset + pathlen;
    r.x.ds = __tb_segment;
    r.h.ah = 0x1a;
    __dpmi_int(0x21, &r);

    r.h.ah = 0x4e;
    r.x.dx = __tb_offset;
    r.x.ds = __tb_segment;
    r.x.cx = attrib;
    __dpmi_int(0x21, &r);
    if(!(r.x.flags & 1)) {
      /* Recover results */
      dosmemget(__tb+pathlen, _sizeof_dos_ffblk, ffblk);
      return 0;
    }
  }

  errno = __doserr_to_errno(r.x.ax);
//return errno;             //@@@@                                 //~v112R~
  return (int)r.x.ax;                                              //~v112I~
}
//*************************************************************
//*udpmifindnextsub                                                //~v112R~
//*************************************************************
/* Copyright (C) 1995 DJ Delorie, see COPYING.DJ for details */
#include <libc/stubs.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <go32.h>
#include <dpmi.h>
#include <dir.h>
#include <fcntl.h>
#include <libc/dosio.h>

int
//findnext(struct ffblk *ffblk)                                    //~v105R~
udpmifindnextsub(struct ffblk *ffblk)                              //~v105I~
{
  __dpmi_regs r;

  if (ffblk == 0)
  {
    errno = EACCES;
    return -1;
  }

  if(_USE_LFN)
  {
    /* si = 1 indicates DOS style dates, 0 means Win32 type dates.
       DOS style dates are broken in some Win95 betas, build for either.
       Release works with DOS date, it's faster, so use it. */
    #define USEDOSDATE 1
    #if USEDOSDATE == 1
      #define _Win32_to_DOS (long)
    #else
      extern long _Win32_to_DOS(long long WinTime);
    #endif

    ffblk->lfn_handle=Shdir;			//@@@@ parm from main      //~v105I~
                                                                   //~v105I~
    r.x.ax = 0x714f;
    r.x.bx = ffblk->lfn_handle;
    if(!r.x.bx)
    {
      errno = ENMFILE;
      return 1;
    }
    r.x.di = __tb_offset;
    r.x.es = __tb_segment;
    r.x.si = USEDOSDATE;

    __dpmi_int(0x21, &r);
    if (!(r.x.flags & 1))
    {
      struct ffblklfn ffblk32;
      /* Recover results */
      dosmemget(__tb, sizeof(struct ffblklfn), &ffblk32);

      ffblk->ff_attrib = (char)ffblk32.fd_attrib;
      *(long *)&ffblk->ff_ftime = _Win32_to_DOS(ffblk32.fd_mtime);
      ffblk->ff_fsize = ffblk32.fd_size;
      strcpy(ffblk->ff_name, ffblk32.fd_longname);
      *(long *)&ffblk->lfn_ctime = _Win32_to_DOS(ffblk32.fd_ctime);
      *(long *)&ffblk->lfn_atime = _Win32_to_DOS(ffblk32.fd_atime);
                                                                   //~v105I~
//	  strncpy(Salias,ffblk32.fd_name,sizeof(Salias)-1);//@@@@lfn support//~v112R~
  	  ustrncpyz(Salias,ffblk32.fd_name,sizeof(Salias));//@@@@lfn support//~v112I~

      return 0;
    }
    errno = __doserr_to_errno(r.x.ax);
    if (errno == ENMFILE)         /* call FindClose */
    {
      ffblk->lfn_handle = 0;
      r.x.ax = 0x71a1;
      __dpmi_int(0x21, &r);
      if(r.x.flags & 1)
      {
        errno = __doserr_to_errno(r.x.ax);
        return -1;
      }
      return 1;
    }
    return -1;
  }
  else
  {
    #define _sizeof_dos_ffblk 44
    /* The 43 character ff block must be put to the DTA, make the call, then
       recover the ff block. */

    r.x.dx = __tb_offset;
    r.x.ds = __tb_segment;
    r.h.ah = 0x1a;
    __dpmi_int(0x21, &r);

    dosmemput(ffblk, sizeof(struct ffblk), __tb);

    r.h.ah = 0x4f;
    __dpmi_int(0x21, &r);
    if(r.x.flags & 1)
    {
      errno = __doserr_to_errno(r.x.ax);
      return -1;
    }

    /* Recover results */
    dosmemget(__tb, _sizeof_dos_ffblk, ffblk);
    return 0;
  }
}

