//CID://+v134R~:                                                   //~v134R~
//*************************************************************
//*udpmilib.c support function which  is not on libc               //~v053R~
//*  memicmp,fcloseall,_dos_getvect,_harderr,_hardresume           //~v073I~
//*  memchr                                                        //~v134I~
//*************************************************************    //~v053I~
//v134:971224 (BUG:GCC)libc/ansi/string/memchr function is buggy for dbcs//~v134I~
//            because compare by int(dbcs is minus value).add to udpmilib//~v134I~
//v073:970420 (GCC)_harderr,_hardresume support                    //~v073R~
//v053:970107:gcc version(control by DPMI)                         //~v053R~
//            -gcc do wild card expand if * is included in parm.   //~v053I~
//             copy crt0\ciargs and modify should_expand_wildcards=0;//~v053I~
//*************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>                                                   //~v053R~
#include <errno.h>                                                 //~v053I~
#include <ctype.h>                                                 //~v053I~
#include <libc/file.h>                                             //~v053M~
                                                                   //~v053I~
#include <libc/stubs.h>                                            //~v053I~
#include <io.h>                                                    //~v053I~
#include <unistd.h>                                                //~v053I~
#include <crt0.h>                                                  //~v053I~
#include <go32.h>                                                  //~v053I~
#include <fcntl.h>                                                 //~v053I~
#include <libc/farptrgs.h>                                         //~v053I~
#include <stubinfo.h>                                              //~v053I~
#include <string.h>                                                //~v053M~
#include <dpmi.h>                                                  //~v073I~
#include <libc/unconst.h>   //unconst                              //~v134I~
//*******************************************************
#include <ulib.h>                                                  //~v022R~
//#include <udpmilib.h>                                            //~v073R~
#include <udpmisub.h>                                              //~v053I~
//*******************************************************
static FUNC24 Sfunc24;                                             //~v073R~
static _go32_dpmi_seginfo Soldint24,Scallback;                     //~v073M~
static USHORT 	Sresumeopt;                                        //~v073M~
static char Shardesw;                                              //~v073M~
static int Scloseerr;                                              //~v053I~
//*                                                                //~v053I~
void fcloseallsub(FILE *Pfh);                                      //~v053I~
//*******************************************************          //~v053I~
//*memicmp                                                         //~v053R~
//*parm1:source1                                                   //~v053R~
//*parm2:source2                                                   //~v053R~
//*parm3:len                                                       //~v053R~
//*ret  :result  0:match,<0,or >0-                                 //~v053R~
//*******************************************************          //~v053I~
int memicmp(void *Psrc1,void *Psrc2,unsigned int Plen)             //~v053R~
{                                                                  //~v053I~
    char *pc1,*pc2;                                                //~v053I~
//*******************                                              //~v053I~
    for(pc1=Psrc1,pc2=Psrc2;Plen>0;Plen--,pc1++,pc2++)             //~v053I~
    	if (tolower(*pc1)!=tolower(*pc2))                          //~v053R~
    		return (int)tolower(*pc1)-(int)tolower(*pc2);          //~v053I~
	return 0;                                                      //~v053R~
}//memicmp                                                         //~v053R~
                                                                   //~v053I~
//*******************************************************          //~v053I~
//*fcloseall                                                       //~v053I~
//*parm :none                                                      //~v053I~
//*ret  :errno of first err of fclose                              //~v053I~
//*******************************************************          //~v053I~
int fcloseall(void)                                                //~v053I~
{                                                                  //~v053I~
//*******************                                              //~v053I~
	 Scloseerr=0;                                                  //~v053I~
    _fwalk(fcloseallsub);                                          //~v053I~
    return Scloseerr;                                              //~v053I~
}//fcloseall                                                       //~v053I~
                                                                   //~v053I~
//*******************************************************          //~v053I~
//*fcloseallsub                                                    //~v053I~
//*parm :none                                                      //~v053I~
//*ret  :rc of fclose                                              //~v053I~
//*******************************************************          //~v053I~
void fcloseallsub(FILE *Pfh)                                       //~v053I~
{                                                                  //~v053I~
//*******************                                              //~v053I~
    if (fclose(Pfh))                                               //~v053I~
    	if (!Scloseerr)                                            //~v053I~
	    	Scloseerr=errno;                                       //~v053I~
    return;                                                        //~v053I~
}//fcloseallsub                                                    //~v053I~
                                                                   //~v053I~
//*******************************************************          //~v053I~
//*_dos_getvect                                                    //~v053I~
//*parm :int no                                                    //~v053I~
//*ret  :seg:offs real mode fa ptr                                 //~v053I~
//*******************************************************          //~v053I~
unsigned long _dos_getvect(int Pintno)                             //~v053I~
{                                                                  //~v053I~
	union REGS	 reg;                                              //~v053I~
	struct SREGS sreg;                                             //~v053I~
//*******************                                              //~v053I~
    reg.h.ah=0x35;				  	//get int vector               //~v053I~
    reg.h.al=Pintno;				  	//get int vector           //~v053I~
    udpmiint86s(0x21,&reg,&reg,&sreg); //ES:BX construct far ptr   //~v053I~
    return (sreg.es<<16)+reg.x.bx;                                 //~v053I~
}//_dos_getvect                                                    //~v053I~
//**************************************************************** //~v073I~
//*setup int 24                                                    //~v073I~
//*p1:dev err                                                      //~v073I~
//*p2:errcode                                                      //~v073I~
//*p3:devhdr ptr(not supported)                                    //~v073I~
//**************************************************************** //~v073I~
void _harderr(FUNC24 Pfunc24)                                      //~v073I~
{                                                                  //~v073I~
static __dpmi_regs Sparmregs;                                      //~v073I~
	int rc;                                                        //~v073I~
    void (uhardewrap)(_go32_dpmi_registers *Preg);                 //~v073I~
//*************                                                    //~v073I~
	Sfunc24=Pfunc24;                                               //~v073I~
	if (Pfunc24)	//set req                                      //~v073I~
    {                                                              //~v073I~
        if (!Shardesw)                                             //~v073I~
        {                                                          //~v073I~
    		Shardesw=1;	//not 1st time                             //~v073I~
    	    _go32_dpmi_get_real_mode_interrupt_vector(0x24,&Soldint24);//~v073I~
//          UTRACED("Soldint",&Soldint24,sizeof(Soldint24));//     //~v073I~
    	}                                                          //~v073I~
        Scallback.pm_offset=(long)uhardewrap;                      //~v073I~
//      UTRACED("Scallback",&Scallback,sizeof(Scallback));//       //~v073I~
    	rc=_go32_dpmi_allocate_real_mode_callback_iret(&Scallback,&Sparmregs);//~v073I~
//      printf("alloc callback rc=%d\n",rc);                       //~v073I~
//      UTRACED("Scallback",&Scallback,sizeof(Scallback));//       //~v073I~
//      UTRACED("Sparmreg",&Sparmregs,sizeof(Sparmregs));//        //~v073I~
        if (!rc)                                                   //~v073I~
        {                                                          //~v073I~
    		Shardesw=2;		//vector changed                       //~v073I~
    		rc=_go32_dpmi_set_real_mode_interrupt_vector(0x24,&Scallback);//~v073I~
//          printf("set int vect rc=%d\n",rc);                     //~v073I~
        }                                                          //~v073I~
    	Sresumeopt=_HARDERR_ABORT;	//default                      //~v073I~
    }                                                              //~v073I~
    else	//reset req                                            //~v073I~
    {                                                              //~v073I~
        if (Shardesw==2)	//previously success                   //~v073I~
        {                                                          //~v073I~
    		rc=_go32_dpmi_set_real_mode_interrupt_vector(0x24,&Soldint24);//~v073I~
//          printf("reset int vect rc=%d\n",rc);                   //~v073I~
    		rc=_go32_dpmi_free_real_mode_callback(&Scallback);     //~v073I~
//          printf("free callback rc=%d\n",rc);                    //~v073I~
        }                                                          //~v073I~
    	Shardesw=0;		//next is 1st time                         //~v073I~
    }                                                              //~v073I~
}//_harderr                                                        //~v073I~
                                                                   //~v073I~
//**************************************************************** //~v073I~
//*interface with user func                                        //~v073I~
//**************************************************************** //~v073I~
void uhardewrap(_go32_dpmi_registers *Preg)                        //~v073I~
{                                                                  //~v073I~
//*************                                                    //~v073I~
//  cprintf("entry uhardewrap");                                   //~v073I~
	Sfunc24(Preg->x.ax,Preg->x.di,0);	//dev hdr not supported    //~v073I~
	Preg->x.ax=Sresumeopt;			//action                       //~v073I~
    if (Sresumeopt==_HARDERR_ABORT)                                //~v073I~
    {                                                              //~v073I~
		_go32_dpmi_set_real_mode_interrupt_vector(0x24,&Soldint24);//~v073I~
    }                                                              //~v073I~
    return;                                                        //~v073I~
}//uhardewrap                                                      //~v073I~
                                                                   //~v073I~
//**************************************************************** //~v073I~
//*set option and return to caller                                 //~v073I~
//(MSC6 may return immediate,but DPMI version not supprt direct return)//~v073I~
//*p1:resume option                                                //~v073I~
//**************************************************************** //~v073I~
void _hardresume(int Popt)                                         //~v073I~
{                                                                  //~v073I~
//*************                                                    //~v073I~
	switch (Popt)                                                  //~v073I~
    {                                                              //~v073I~
    case _HARDERR_ABORT:	//2:program exit                       //~v073I~
    case _HARDERR_FAIL:     //3:stop system call                   //~v073I~
    case _HARDERR_IGNORE:   //0:ignore                             //~v073I~
    case _HARDERR_RETRY:    //1:retry                              //~v073I~
    	Sresumeopt=Popt;                                           //~v073I~
        break;                                                     //~v073I~
    default:                                                       //~v073I~
    	Sresumeopt=_HARDERR_ABORT;                                 //~v073I~
    }                                                              //~v073I~
	return;                                                        //~v073I~
}//_hardresume                                                     //~v073I~
                                                                   //~v073I~
//**************************************************************** //~v073I~
//********copyed from djgpp\src\libc\crt0\c1args.c ************    //~v053R~
//**************************************************************** //~v073I~
/* Copyright (C) 1996 DJ Delorie, see COPYING.DJ for details */    //~v053I~
/* Copyright (C) 1995 DJ Delorie, see COPYING.DJ for details */    //~v053I~
                                                                   //~v053I~
#define ds _my_ds()                                                //~v053I~
                                                                   //~v053I~
static void *                                                      //~v053I~
c1xmalloc(size_t s)                                                //~v053I~
{                                                                  //~v053I~
  void *q = malloc(s);                                             //~v053I~
  if (q == 0)                                                      //~v053I~
  {                                                                //~v053I~
#define err(x) _write(STDERR_FILENO, x, sizeof(x)-1)               //~v053I~
    err("No memory to gather arguments\r\n");                      //~v053I~
    _exit(1);                                                      //~v053I~
  }                                                                //~v053I~
  return q;                                                        //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static int                                                         //~v053I~
far_strlen(int selector, int linear_addr)                          //~v053I~
{                                                                  //~v053I~
  int save=linear_addr;                                            //~v053I~
  _farsetsel(selector);                                            //~v053I~
  while (_farnspeekb(linear_addr))                                 //~v053I~
    linear_addr++;                                                 //~v053I~
  return linear_addr - save;                                       //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static int                                                         //~v053I~
atohex(char *s)                                                    //~v053I~
{                                                                  //~v053I~
  int rv = 0;                                                      //~v053I~
  while (*s)                                                       //~v053I~
  {                                                                //~v053I~
    int v = *s - '0';                                              //~v053I~
    if (v > 9)                                                     //~v053I~
      v -= 7;                                                      //~v053I~
    v &= 15; /* in case it's lower case */                         //~v053I~
    rv = rv*16 + v;                                                //~v053I~
    s++;                                                           //~v053I~
  }                                                                //~v053I~
  return rv;                                                       //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
typedef struct Arg {                                               //~v053I~
  char *arg;                                                       //~v053I~
  char **arg_globbed;                                              //~v053I~
  struct ArgList *arg_file;                                        //~v053I~
  struct Arg *next;                                                //~v053I~
  int was_quoted;                                                  //~v053I~
} Arg;                                                             //~v053I~
                                                                   //~v053I~
typedef struct ArgList {                                           //~v053I~
  int argc;                                                        //~v053I~
  Arg **argv;                                                      //~v053I~
} ArgList;                                                         //~v053I~
                                                                   //~v053I~
static Arg *new_arg(void)                                          //~v053I~
{                                                                  //~v053I~
  Arg *a = (Arg *)c1xmalloc(sizeof(Arg));                          //~v053I~
  memset(a, 0, sizeof(Arg));                                       //~v053I~
  return a;                                                        //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static void delete_arglist(ArgList *al);                           //~v053I~
                                                                   //~v053I~
static void                                                        //~v053I~
delete_arg(Arg *a)                                                 //~v053I~
{                                                                  //~v053I~
  if (a->arg) free(a->arg);                                        //~v053I~
  if (a->arg_globbed)                                              //~v053I~
  {                                                                //~v053I~
    int i;                                                         //~v053I~
    for (i=0; a->arg_globbed[i]; i++)                              //~v053I~
      free(a->arg_globbed[i]);                                     //~v053I~
    free(a->arg_globbed);                                          //~v053I~
  }                                                                //~v053I~
  if (a->arg_file)                                                 //~v053I~
    delete_arglist(a->arg_file);                                   //~v053I~
  free(a);                                                         //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static ArgList *                                                   //~v053I~
new_arglist(int count)                                             //~v053I~
{                                                                  //~v053I~
  ArgList *al = (ArgList *)c1xmalloc(sizeof(ArgList));             //~v053I~
  al->argc = count;                                                //~v053I~
  al->argv = (Arg **)c1xmalloc((count+1)*sizeof(Arg *));           //~v053I~
  memset(al->argv, 0, (count+1)*sizeof(Arg *));                    //~v053I~
  return al;                                                       //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static void                                                        //~v053I~
delete_arglist(ArgList *al)                                        //~v053I~
{                                                                  //~v053I~
  int i;                                                           //~v053I~
  for (i=0; i<al->argc; i++)                                       //~v053I~
    delete_arg(al->argv[i]);                                       //~v053I~
  free(al->argv);                                                  //~v053I~
  free(al);                                                        //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static char *                                                      //~v053I~
parse_arg(char *bp, char *last, size_t *len, int *was_quoted)      //~v053I~
{                                                                  //~v053I~
  char *ep = bp, *epp = bp;                                        //~v053I~
  int quote=0;                                                     //~v053I~
                                                                   //~v053I~
  while ((quote || !isspace(*ep)) && ep < last)                    //~v053I~
  {                                                                //~v053I~
    if (quote && *ep == quote)                                     //~v053I~
    {                                                              //~v053I~
      quote = 0;                                                   //~v053I~
      ep++;                                                        //~v053I~
    }                                                              //~v053I~
    else if (!quote && (*ep == '\'' || *ep == '"'))                //~v053I~
    {                                                              //~v053I~
      quote = *ep;                                                 //~v053I~
      ep++;                                                        //~v053I~
    }                                                              //~v053I~
    else if (*ep == '\\' && strchr("'\"", ep[1]) && ep < last-1)   //~v053I~
    {                                                              //~v053I~
      ep++;                                                        //~v053I~
      *epp++ = *ep++;                                              //~v053I~
      /* *was_quoted = 1;  - This makes no sense. */               //~v053I~
    }                                                              //~v053I~
    else                                                           //~v053I~
    {                                                              //~v053I~
      if (quote && (strchr("[?*", *ep) || strncmp(ep, "...", 3) == 0))//~v053I~
	*was_quoted = 1;                                               //~v053I~
      *epp++ = *ep++;                                              //~v053I~
    }                                                              //~v053I~
  }                                                                //~v053I~
                                                                   //~v053I~
  *len = epp - bp;                                                 //~v053I~
  return ep;                                                       //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static ArgList *                                                   //~v053I~
parse_bytes(char *bytes, int length)                               //~v053I~
{                                                                  //~v053I~
  int largc, i;                                                    //~v053I~
  Arg *a, **anext, *afirst;                                        //~v053I~
  ArgList *al;                                                     //~v053I~
  char *bp=bytes, *ep, *last=bytes+length;                         //~v053I~
                                                                   //~v053I~
  anext = &afirst;                                                 //~v053I~
  largc = 0;                                                       //~v053I~
  while (bp<last)                                                  //~v053I~
  {                                                                //~v053I~
    size_t arg_len;                                                //~v053I~
    while (isspace(*bp) && bp < last)                              //~v053I~
      bp++;                                                        //~v053I~
    if (bp == last)                                                //~v053I~
      break;                                                       //~v053I~
    *anext = a = new_arg();                                        //~v053I~
    ep = parse_arg(bp, last, &arg_len, &(a->was_quoted));          //~v053I~
    anext = &(a->next);                                            //~v053I~
    largc++;                                                       //~v053I~
    a->arg = (char *)c1xmalloc(arg_len+1);                         //~v053I~
    memcpy(a->arg, bp, arg_len);                                   //~v053I~
    a->arg[arg_len] = 0;                                           //~v053I~
    bp = ep+1;                                                     //~v053I~
  }                                                                //~v053I~
  al = new_arglist(largc);                                         //~v053I~
  for (i=0, a=afirst; i<largc; i++, a=a->next)                     //~v053I~
    al->argv[i] = a;                                               //~v053I~
  return al;                                                       //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static int                                                         //~v053I~
count_args(ArgList *al)                                            //~v053I~
{                                                                  //~v053I~
  int i, r=0;                                                      //~v053I~
  for (i=0; i<al->argc; i++)                                       //~v053I~
  {                                                                //~v053I~
    int j;                                                         //~v053I~
    if (al->argv[i]->arg_globbed)                                  //~v053I~
    {                                                              //~v053I~
      for (j=0; al->argv[i]->arg_globbed[j]; j++);                 //~v053I~
      r += j;                                                      //~v053I~
    }                                                              //~v053I~
    else if (al->argv[i]->arg_file)                                //~v053I~
    {                                                              //~v053I~
      r += count_args(al->argv[i]->arg_file);                      //~v053I~
    }                                                              //~v053I~
    else                                                           //~v053I~
    {                                                              //~v053I~
      r++;                                                         //~v053I~
    }                                                              //~v053I~
  }                                                                //~v053I~
  return r;                                                        //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static char **                                                     //~v053I~
fill_args(char **largv, ArgList *al)                               //~v053I~
{                                                                  //~v053I~
  int i;                                                           //~v053I~
  for (i=0; i<al->argc; i++)                                       //~v053I~
  {                                                                //~v053I~
    int j;                                                         //~v053I~
    if (al->argv[i]->arg_globbed)                                  //~v053I~
    {                                                              //~v053I~
      for (j=0; al->argv[i]->arg_globbed[j]; j++)                  //~v053I~
      {                                                            //~v053I~
        *largv++ = al->argv[i]->arg_globbed[j];                    //~v053I~
        al->argv[i]->arg_globbed[j] = 0;                           //~v053I~
      }                                                            //~v053I~
    }                                                              //~v053I~
    else if (al->argv[i]->arg_file)                                //~v053I~
    {                                                              //~v053I~
      largv = fill_args(largv, al->argv[i]->arg_file);             //~v053I~
    }                                                              //~v053I~
    else                                                           //~v053I~
    {                                                              //~v053I~
      *largv++ = al->argv[i]->arg;                                 //~v053I~
      al->argv[i]->arg = 0;                                        //~v053I~
    }                                                              //~v053I~
  }                                                                //~v053I~
  return largv;                                                    //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static void                                                        //~v053I~
expand_response_files(ArgList *al)                                 //~v053I~
{                                                                  //~v053I~
  int i, f;                                                        //~v053I~
  for (i=0; i<al->argc; i++)                                       //~v053I~
  {                                                                //~v053I~
    if (! al->argv[i]->was_quoted && al->argv[i]->arg[0] == '@')   //~v053I~
      if ((f = _open(al->argv[i]->arg+1, O_RDONLY)) >= 0)          //~v053I~
      {                                                            //~v053I~
	char *bytes;                                                   //~v053I~
	int len, st_size;                                              //~v053I~
	st_size = lseek(f, 0L, SEEK_END);                              //~v053I~
	lseek(f, 0L, SEEK_SET);                                        //~v053I~
        bytes = (char *)alloca(st_size);                           //~v053I~
        len = _read(f, bytes, st_size);                            //~v053I~
        _close(f);                                                 //~v053I~
        al->argv[i]->arg_file = parse_bytes(bytes, len);           //~v053I~
        expand_response_files(al->argv[i]->arg_file);              //~v053I~
      }                                                            //~v053I~
  }                                                                //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
static void                                                        //~v053I~
expand_wildcards(ArgList *al)                                      //~v053I~
{                                                                  //~v053I~
  int i;                                                           //~v053I~
  for (i=0; i<al->argc; i++)                                       //~v053I~
  {                                                                //~v053I~
    if (al->argv[i]->arg_file)                                     //~v053I~
      expand_wildcards(al->argv[i]->arg_file);                     //~v053I~
    else if (!(al->argv[i]->was_quoted))                           //~v053I~
    {                                                              //~v053I~
      al->argv[i]->arg_globbed = __crt0_glob_function(al->argv[i]->arg);//~v053I~
    }                                                              //~v053I~
  }                                                                //~v053I~
}                                                                  //~v053I~
                                                                   //~v053I~
extern char __PROXY[]; /* defined on crt0/crt1.c */                //~v053I~
extern size_t __PROXY_LEN;                                         //~v053I~
                                                                   //~v053I~
void                                                               //~v053I~
__crt0_setup_arguments(void)                                       //~v053I~
{                                                                  //~v053I~
  ArgList *arglist;                                                //~v053I~
  char *argv0;                                                     //~v053I~
  int prepend_argv0 = 1;                                           //~v053I~
//int should_expand_wildcards = 1;            //   default expand  //~v053I~
  int should_expand_wildcards = 0;            //   default no expand//~v053I~
  char *proxy_v = 0;                                               //~v053I~
                                                                   //~v053I~
  /*                                                               //~v053I~
  ** first, figure out what to pass for argv[0]                    //~v053I~
  */                                                               //~v053I~
  {                                                                //~v053I~
    int i;                                                         //~v053I~
    char *ap, *ls, *fc;                                            //~v053I~
/*    char newbase[14]; */                                         //~v053I~
                                                                   //~v053I~
    if (_crt0_startup_flags & _CRT0_FLAG_DROP_DRIVE_SPECIFIER)     //~v053I~
      if (__dos_argv0[1] == ':')                                   //~v053I~
        __dos_argv0 += 2;                                          //~v053I~
                                                                   //~v053I~
    ls = __dos_argv0;                                              //~v053I~
    for (ap=__dos_argv0; *ap; ap++)                                //~v053I~
      if (*ap == ':' || *ap == '\\' || *ap == '/')                 //~v053I~
        ls = ap + 1;                                               //~v053I~
    fc = ls;                                                       //~v053I~
#if 0                                                              //~v053I~
    /* We never do this!  Only the stub uses this field */         //~v053I~
    if (_stubinfo->basename[0])                                    //~v053I~
    {                                                              //~v053I~
      for (i=0; i<8 && _stubinfo->basename[i]; i++)                //~v053I~
	newbase[i] = _stubinfo->basename[i];                           //~v053I~
      newbase[i++] = '.';                                          //~v053I~
      newbase[i++] = 'E';                                          //~v053I~
      newbase[i++] = 'X';                                          //~v053I~
      newbase[i++] = 'E';                                          //~v053I~
      newbase[i++] = 0;                                            //~v053I~
      fc = newbase;                                                //~v053I~
    }                                                              //~v053I~
#endif                                                             //~v053I~
    if (_stubinfo->argv0[0])                                       //~v053I~
    {                                                              //~v053I~
      fc = _stubinfo->argv0;                                       //~v053I~
    }                                                              //~v053I~
    argv0 = (char *)calloc(1, ls-__dos_argv0+strlen(fc)+1);        //~v053I~
    if (ls == __dos_argv0)                                         //~v053I~
      strncpy(argv0, fc, 16);                                      //~v053I~
    else                                                           //~v053I~
    {                                                              //~v053I~
      strncpy(argv0, __dos_argv0, ls-__dos_argv0);                 //~v053I~
      strncat(argv0, fc, 16);                                      //~v053I~
    }                                                              //~v053I~
    for (i=0; (fc == _stubinfo->argv0)?(i<ls-__dos_argv0):(argv0[i]); i++)//~v053I~
    {                                                              //~v053I~
      if (!(_crt0_startup_flags & _CRT0_FLAG_USE_DOS_SLASHES))     //~v053I~
        if (argv0[i] == '\\')                                      //~v053I~
          argv0[i] = '/';                                          //~v053I~
      if (!(_crt0_startup_flags & _CRT0_FLAG_PRESERVE_UPPER_CASE)) //~v053I~
        if (isupper(argv0[i]))                                     //~v053I~
          argv0[i] = tolower(argv0[i]);                            //~v053I~
    }                                                              //~v053I~
    if (_crt0_startup_flags & _CRT0_FLAG_DROP_EXE_SUFFIX)          //~v053I~
    {                                                              //~v053I~
      char *sp = argv0 + strlen(argv0) - 4;                        //~v053I~
      if (sp[0] == '.'                                             //~v053I~
	  && (sp[1] == 'e' || sp[1] == 'E')                            //~v053I~
	  && (sp[2] == 'x' || sp[2] == 'X')                            //~v053I~
	  && (sp[3] == 'e' || sp[3] == 'E'))                           //~v053I~
        *sp = 0;                                                   //~v053I~
    }                                                              //~v053I~
  }                                                                //~v053I~
                                                                   //~v053I~
  /*                                                               //~v053I~
  ** Next, scan dos's command line.                                //~v053I~
  */                                                               //~v053I~
  {                                                                //~v053I~
    char doscmd[128];                                              //~v053I~
    movedata(_stubinfo->psp_selector, 128, ds, (int)doscmd, 128);  //~v053I~
    arglist = parse_bytes(doscmd+1, doscmd[0] & 0x7f);             //~v053I~
  }                                                                //~v053I~
                                                                   //~v053I~
  /*                                                               //~v053I~
  ** Check for !proxy.                                             //~v053I~
  **                                                               //~v053I~
  ** If there is " !proxy" (note the leading blank!) in the environ,//~v053I~
  ** use it instead of what DOS command line tells.  This is the method//~v053I~
  ** v2.01 and later uses to pass long command lines from `system';//~v053I~
  ** these should be passed through wildcard expansion unless quoted.//~v053I~
  */                                                               //~v053I~
  if ((proxy_v = getenv(__PROXY)))                                 //~v053I~
  {                                                                //~v053I~
    char proxy_line[50];	/* need only 34 */                     //~v053I~
    size_t plen = strlen(proxy_v);                                 //~v053I~
    strncpy(proxy_line, __PROXY, __PROXY_LEN + 1); /* copy " !proxy" *///~v053I~
    proxy_line[__PROXY_LEN] = ' ';                                 //~v053I~
    strncpy(proxy_line + __PROXY_LEN+1, proxy_v, plen+1); /* copy value *///~v053I~
    delete_arglist(arglist);                                       //~v053I~
    arglist = parse_bytes(proxy_line, plen+__PROXY_LEN+1);         //~v053I~
  }                                                                //~v053I~
  if (arglist->argc > 3 && strcmp(arglist->argv[0]->arg, __PROXY+1) == 0)//~v053I~
  {                                                                //~v053I~
    int argv_seg, argv_ofs, i;                                     //~v053I~
    unsigned short *rm_argv;                                       //~v053I~
    __crt0_argc = atohex(arglist->argv[1]->arg);                   //~v053I~
    argv_seg = atohex(arglist->argv[2]->arg);                      //~v053I~
    argv_ofs = atohex(arglist->argv[3]->arg);                      //~v053I~
    delete_arglist(arglist);                                       //~v053I~
                                                                   //~v053I~
    rm_argv = (unsigned short *)alloca(__crt0_argc*sizeof(unsigned short));//~v053I~
    movedata(_dos_ds, argv_seg*16+argv_ofs, ds, (int)rm_argv, __crt0_argc*sizeof(unsigned short));//~v053I~
                                                                   //~v053I~
    arglist = new_arglist(__crt0_argc);                            //~v053I~
    if (proxy_v)                                                   //~v053I~
      should_expand_wildcards = 1;                                 //~v053I~
    else                                                           //~v053I~
      should_expand_wildcards = 0;                                 //~v053I~
                                                                   //~v053I~
                                                                   //~v053I~
    for (i=0; i<__crt0_argc; i++)                                  //~v053I~
    {                                                              //~v053I~
      int al = far_strlen(_dos_ds, argv_seg*16 + rm_argv[i]);      //~v053I~
      arglist->argv[i] = new_arg();                                //~v053I~
      arglist->argv[i]->arg = (char *)c1xmalloc(al+1);             //~v053I~
      movedata(_dos_ds, argv_seg*16 + rm_argv[i], ds, (int)(arglist->argv[i]->arg), al+1);//~v053I~
      if (proxy_v)                                                 //~v053I~
      {                                                            //~v053I~
	size_t ln;                                                     //~v053I~
	char *lastc = arglist->argv[i]->arg + al;                      //~v053I~
	parse_arg(arglist->argv[i]->arg, lastc,                        //~v053I~
		  &ln, &(arglist->argv[i]->was_quoted));                   //~v053I~
	arglist->argv[i]->arg[ln] = '\0';                              //~v053I~
      }                                                            //~v053I~
    }                                                              //~v053I~
    prepend_argv0 = 0;                                             //~v053I~
  }                                                                //~v053I~
#if 0                                                              //~v053I~
  /* This method will break under DPMI 1.0, because descriptor     //~v053I~
     tables are private to a process there.  Disabled.  */         //~v053I~
  else if (arglist->argc > 3 && strcmp(arglist->argv[0]->arg, "!proxy2") == 0)//~v053I~
  {                                                                //~v053I~
    int argv_sel, argv_ofs, i;                                     //~v053I~
    unsigned long *pm_argv;                                        //~v053I~
    __crt0_argc = atohex(arglist->argv[1]->arg);                   //~v053I~
    argv_sel = atohex(arglist->argv[2]->arg);                      //~v053I~
    argv_ofs = atohex(arglist->argv[3]->arg);                      //~v053I~
    delete_arglist(arglist);                                       //~v053I~
                                                                   //~v053I~
    pm_argv = (unsigned long *)alloca(__crt0_argc*sizeof(unsigned long));//~v053I~
    movedata(argv_sel, argv_ofs, ds, (int)pm_argv, __crt0_argc*sizeof(unsigned long));//~v053I~
                                                                   //~v053I~
    arglist = new_arglist(__crt0_argc);                            //~v053I~
                                                                   //~v053I~
    for (i=0; i<__crt0_argc; i++)                                  //~v053I~
    {                                                              //~v053I~
      int al = far_strlen(argv_sel, pm_argv[i]);                   //~v053I~
      arglist->argv[i] = new_arg();                                //~v053I~
      arglist->argv[i]->arg = (char *)c1xmalloc(al+1);             //~v053I~
      movedata(argv_sel, pm_argv[i], ds, (int)(arglist->argv[i]->arg), al+1);//~v053I~
    }                                                              //~v053I~
    prepend_argv0 = 0;                                             //~v053I~
    should_expand_wildcards = 0;                                   //~v053I~
  }                                                                //~v053I~
#endif                                                             //~v053I~
                                                                   //~v053I~
  /*                                                               //~v053I~
  **  Now, expand response files                                   //~v053I~
  */                                                               //~v053I~
  if (!(_crt0_startup_flags & _CRT0_FLAG_DISALLOW_RESPONSE_FILES)) //~v053I~
    expand_response_files(arglist);                                //~v053I~
                                                                   //~v053I~
  /*                                                               //~v053I~
  **  Now, expand wildcards                                        //~v053I~
  */                                                               //~v053I~
                                                                   //~v053I~
  if (should_expand_wildcards)                                     //~v053I~
    expand_wildcards(arglist);                                     //~v053I~
                                                                   //~v053I~
  __crt0_argc = prepend_argv0 + count_args(arglist);               //~v053I~
  __crt0_argv = (char **)c1xmalloc((__crt0_argc+1) * sizeof(char *));//~v053I~
  if (prepend_argv0)                                               //~v053I~
    __crt0_argv[0] = argv0;                                        //~v053I~
  *fill_args(__crt0_argv+prepend_argv0, arglist) = 0;              //~v053I~
}                                                                  //~v053I~
//**************************************************************** //~v134I~
//********copyed from djgpp\src\libc\ansi\string\memchr.c *****    //~v134I~
//**************************************************************** //~v134I~
void *memchr(const void *s, int c, size_t n)                       //+v134R~
{                                                                  //~v134I~
  unsigned char cc = c;              //@@@@add                     //~v134I~
  if (n)                                                           //~v134I~
  {                                                                //~v134I~
//  const char *p = s;               //@@@@del                     //~v134I~
    const unsigned char *p = s;      //@@@@add                     //~v134I~
    do {                                                           //~v134I~
//    if (*p++ == c)                 //@@@@del                     //~v134I~
      if (*p++ == cc)                //@@@@add                     //~v134I~
	return unconst(p-1, void *);                                   //~v134I~
    } while (--n != 0);                                            //~v134I~
  }                                                                //~v134I~
  return 0;                                                        //~v134I~
}                                                                  //~v134I~
