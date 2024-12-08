//*CID://+v540R~:                             update#=    7;       //~v540I~
//******************************************************
//v540:020324 (BUG:LNX)linux atol function overflow at 0x7fffffff and return it.//~v540I~
//                     add atol to set max 0xffffffff              //~v540I~
//**************************************************************************
// repl of linux libc
//  atol                                                           //~v540I~
//**************************************************************************
//#include <stdlib.h>                                              //~v540R~
#include <ctype.h>
#include <errno.h>                                                 //+v540I~
#include <limits.h>                                                //~v540I~

//*******************************************************
#include <ulib.h>
//*******************************************************
//*atol
//*allow preceding space
//*if 0verflow return 0xffffffff
//*   max:4294967295,min:-214784483647-1
//*(linux libc max is 0x7fffffff;so expand it to 0xffffffff)
//*parm1:str
//*ret  :long
//*******************************************************
long int atol(unsigned char *Pstr)                                 //~v540R~
{
	int negative,overflow;
  	unsigned long cutoff,cutlim,rc;
  	long longmin=-LONG_MIN;                                        //~v540R~
  	unsigned char ch,*pc;
//*******************
  	pc=Pstr;
  	while (isspace(*pc))
    	++pc;
  	if (!*pc)
    	return 0;
  	if (*pc=='-')
    {
      	negative=1;
      	pc++;
    }
  	else if (*pc=='+')
    {
      	negative = 0;
      	pc++;
    }
  	else
    	negative = 0;

  	cutoff = ULONG_MAX/10;
  	cutlim = ULONG_MAX%10;

  	overflow = 0;
    rc=0;
  	for (;ch=*pc,ch;pc++)
    {
      	if (isdigit(ch))
			ch-='0';
        else
        	break;
      	if (rc>cutoff || (rc==cutoff && ch>cutlim))
        {
			overflow = 1;
            break;
        }
     	else
		{
	  		rc*=10;
	  		rc+=ch;
		}
    }
    if (negative)
  		if (rc>longmin)                                            //~v540R~
    		overflow=1;
  	if (overflow)
    {
      	errno = ERANGE;
      	return ULONG_MAX;
    }
  	if (negative)
        rc=(unsigned long)(-(long)rc);
  	return rc;
}//atol
