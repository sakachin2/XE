//CID://+v336R~:                                                   //~v336I~
//******************************************************           //~v336I~
//v337 000917:BUG parm operflow when init_color                    //~v336I~
/***************************************************************************
*                            COPYRIGHT NOTICE                              *
****************************************************************************
*                ncurses is copyright (C) 1992-1995                        *
*                          Zeyd M. Ben-Halim                               *
*                          zmbenhal@netcom.com                             *
*                          Eric S. Raymond                                 *
*                          esr@snark.thyrsus.com                           *
*                                                                          *
*        Permission is hereby granted to reproduce and distribute ncurses  *
*        by any means and for any fee, whether alone or as part of a       *
*        larger distribution, in source or in binary form, PROVIDED        *
*        this notice is included with any such distribution, and is not    *
*        removed from any of its header files. Mention of ncurses in any   *
*        applications linked with it is highly appreciated.                *
*                                                                          *
*        ncurses comes AS IS with no warranty, implied or expressed.       *
*                                                                          *
***************************************************************************/


/*
 *	tparm.c
 *
 */

//#include <curses.priv.h>                                         //~v336R~
//**********************************************************************//+v336I~
//* selected from curses.priv.h ****************************************//+v336I~
#define MODULE_ID(id) /*nothing*/                                  //~v336I~
#include <stdlib.h>                                                //~v336I~
#include <curses.h>                                                //~v336I~
#define max(a,b)	((a) < (b)  ?  (b)  :  (a))                    //+v336I~
//**********************************************************************//+v336I~

#include <string.h>
#include <term.h>

MODULE_ID("$Id: lib_tparm.c,v 1.10 1996/11/16 23:21:24 tom Exp $")

/*
 *	char *
 *	tparm(string, ...)
 *
 *	Substitute the given parameters into the given string by the following
 *	rules (taken from terminfo(5)):
 *
 *	     Cursor addressing and other strings  requiring  parame-
 *	ters in the terminal are described by a parameterized string
 *	capability, with like escapes %x in  it.   For  example,  to
 *	address  the  cursor, the cup capability is given, using two
 *	parameters: the row and column to  address  to.   (Rows  and
 *	columns  are  numbered  from  zero and refer to the physical
 *	screen visible to the user, not to any  unseen  memory.)  If
 *	the terminal has memory relative cursor addressing, that can
 *	be indicated by
 *	
 *	     The parameter mechanism uses  a  stack  and  special  %
 *	codes  to manipulate it.  Typically a sequence will push one
 *	of the parameters onto the stack and then print it  in  some
 *	format.  Often more complex operations are necessary.
 *	
 *	     The % encodings have the following meanings:
 *	
 *	     %%        outputs `%'
 *	     %d        print pop() like %d in printf()
 *	     %2d       print pop() like %2d in printf()
 *	     %02d      print pop() like %02d in printf()
 *	     %3d       print pop() like %3d in printf()
 *	     %03d      print pop() like %03d in printf()
 *	     %2x       print pop() like %2x in printf()
 *	     %02x      print pop() like %02x in printf()
 *	     %3x       print pop() like %3x in printf()
 *	     %03x      print pop() like %03x in printf()
 *	     %c        print pop() like %c in printf()
 *	     %s        print pop() like %s in printf()
 *	
 *	     %p[1-9]   push ith parm
 *	     %P[a-z]   set variable [a-z] to pop()
 *	     %g[a-z]   get variable [a-z] and push it
 *	     %'c'      push char constant c
 *	     %{nn}     push integer constant nn
 *	
 *	     %+ %- %* %/ %m
 *	               arithmetic (%m is mod): push(pop() op pop())
 *	     %& %| %^  bit operations: push(pop() op pop())
 *	     %= %> %<  logical operations: push(pop() op pop())
 *	     %A %O     logical and & or operations for conditionals
 *	     %! %~     unary operations push(op pop())
 *	     %i        add 1 to first two parms (for ANSI terminals)
 *	
 *	     %? expr %t thenpart %e elsepart %;
 *	               if-then-else, %e elsepart is optional.
 *	               else-if's are possible ala Algol 68:
 *	               %? c1 %t b1 %e c2 %t b2 %e c3 %t b3 %e c4 %t b4 %e b5 %;
 *	
 *	For those of the above operators which are binary and not commutative,
 *	the stack works in the usual way, with
 *			%gx %gy %m
 *	resulting in x mod y, not the reverse.
 */

#define L_BRACE '{'
#define R_BRACE '}'

#define STACKSIZE	20

typedef union {
	unsigned int	num;
	char	       *str;
} stack_frame;

static  stack_frame	stack[STACKSIZE];
static	int	stack_ptr;
#ifdef TRACE
static char *tname;
#endif /* TRACE */

static char  *out_buff;
static size_t out_size;
static size_t out_used;

static void save_text(char *s)
{
	size_t	want = strlen(s);
	size_t	need = want + out_used + 1;

	if (need > out_size) {
		out_size = need * 2;
		if (out_buff == 0)
			out_buff = malloc(out_size);
		else
			out_buff = realloc(out_buff, out_size);
	}
	(void)strcpy(out_buff + out_used, s);
	out_used += want;
}

static void save_number(const char *fmt, int number)
{
	char temp[80];
	(void)sprintf(temp, fmt, number);
	save_text(temp);
}

static inline void save_char(int c)
{
	static char text[2];
	text[0] = c;
	save_text(text);
}

static inline void npush(int x)
{
	if (stack_ptr < STACKSIZE) {
		stack[stack_ptr].num = x;
        stack_ptr++;
    }
}

static inline int npop(void)
{
	return   (stack_ptr > 0  ?  stack[--stack_ptr].num  :  0);
}

static inline char *spop(void)
{
	return   (stack_ptr > 0  ?  stack[--stack_ptr].str  :  0);
}

static inline char *tparam_internal(const char *string, va_list ap)
{
//int	param[9];                                                  //~v336R~
int	param[50];      //overflow when init_color                     //~v336R~
int	popcount;
int	variable[26];
char	len;
int	number;
int	level;
int	x, y;
int	i;
register char	*cp;

	out_used = 0;
	if (string == NULL)
		return NULL;

	/*
	 * Find the highest parameter-number referred to in the format string.
	 * Use this value to limit the number of arguments copied from the
	 * variable-length argument list.
	 */
	for (cp = (char *)string, popcount = number = 0; *cp != '\0'; cp++) {
		if (cp[0] == '%' && cp[1] != '\0') {
			switch (cp[1]) {
			case '%':
				cp++;
				break;
			case 'i':
				if (popcount < 2)
					popcount = 2;
				break;
			case 'p':
				cp++;
				if (cp[1] >= '1' && cp[1] <= '9') {
					int c = cp[1] - '0';
					if (c > popcount)
						popcount = c;
				}
				break;
			case '0': case '1': case '2': case '3': case '4':
			case '5': case '6': case '7': case '8': case '9':
			case 'd': case 'c': case 's':
				++number;
				break;
			}
		}
	}

	for (i = 0; i < max(popcount, number); i++) {
		/*
		 * FIXME: potential loss here if sizeof(int) != sizeof(char *).
		 * A few caps (such as plab_norm) have string-valued parms.
		 */
		param[i] = va_arg(ap, int);
	}

	/*
	 * This is a termcap compatibility hack.  If there are no explicit pop
	 * operations in the string, load the stack in such a way that 
	 * successive pops will grab successive parameters.  That will make
	 * the expansion of (for example) \E[%d;%dH work correctly in termcap
	 * style, which means tparam() will expand termcap strings OK.
	 */
	stack_ptr = 0;
	if (popcount == 0) {
		popcount = number;
		for (i = number - 1; i >= 0; i--)
			npush(param[i]);
	}

#ifdef TRACE
	if (_nc_tracing & TRACE_CALLS) {
		for (i = 0; i < popcount; i++)
			save_number(", %d", param[i]);
		_tracef("%s(\"%s\"%s) called", tname, _nc_visbuf(string), out_buff);
		out_used = 0;
 	}
#endif /* TRACE */

	while (*string) {
		if (*string != '%')
			save_char(*string);
		else {
			string++;
			switch (*string) {
			default:
				break;
			case '%':
				save_char('%');
				break;

			case 'd':
				save_number("%d", npop());
				break;

			case '0':
				string++;
				len = *string;
				if (len == '2'  ||  len == '3')
				{
					++string;
					if (*string == 'd') {
						if (len == '2')
							save_number("%02d", npop());
						else
							save_number("%03d", npop());
					}
					else if (*string == 'x') {
						if (len == '2')
							save_number("%02x", npop());
						else
							save_number("%03x", npop());
					}
				}
				break;

			case '2':
				string++;
				if (*string == 'd') {
					save_number("%2d", npop());
				}
				else if (*string == 'x') {
					save_number("%2x", npop());
				}
				break;

			case '3':
				string++;
				if (*string == 'd') {
					save_number("%3d", npop());
				}
				else if (*string == 'x') {
					save_number("%3x", npop());
				}
				break;

			case 'c':
				save_char(npop());
				break;

			case 's':
				save_text(spop());
				break;

			case 'p':
				string++;
				if (*string >= '1'  &&  *string <= '9')
					npush(param[*string - '1']);
				break;

			case 'P':
				string++;
				if (*string >= 'a'  &&  *string <= 'z')
					variable[*string - 'a'] = npop();
				break;

			case 'g':
				string++;
				if (*string >= 'a'  &&  *string <= 'z')
					npush(variable[*string - 'a']);
				break;

			case '\'':
				string++;
				npush(*string);
				string++;
				break;

			case L_BRACE:
				number = 0;
				string++;
				while (*string >= '0'  &&  *string <= '9') {
					number = number * 10 + *string - '0';
					string++;
				}
				npush(number);
				break;

			case '+':
				npush(npop() + npop());
				break;

			case '-':
				y = npop();
				x = npop();
				npush(x - y);
				break;

			case '*':
				npush(npop() * npop());
				break;

			case '/':
				y = npop();
				x = npop();
				npush(x / y);
				break;

			case 'm':
				y = npop();
				x = npop();
				npush(x % y);
				break;

			case 'A':
				npush(npop() && npop());
				break;

			case 'O':
				npush(npop() || npop());
				break;

			case '&':
				npush(npop() & npop());
				break;

			case '|':
				npush(npop() | npop());
				break;

			case '^':
				npush(npop() ^ npop());
				break;

			case '=':
				y = npop();
				x = npop();
				npush(x == y);
				break;

			case '<':
				y = npop();
				x = npop();
				npush(x < y);
				break;

			case '>':
				y = npop();
				x = npop();
				npush(x > y);
				break;

			case '!':
				npush(! npop());
				break;

			case '~':
				npush(~ npop());
				break;

			case 'i':
				param[0]++;
				param[1]++;
				break;

			case '?':
				break;

			case 't':
				x = npop();
				if (!x) {
					/* scan forward for %e or %; at level zero */
					string++;
					level = 0;
					while (*string) {
						if (*string == '%') {
							string++;
							if (*string == '?')
								level++;
							else if (*string == ';') {
								if (level > 0)
									level--;
								else
									break;
							}
							else if (*string == 'e'  && level == 0)
								break;
						}

						if (*string)
							string++;
					}
				}
				break;

			case 'e':
				/* scan forward for a %; at level zero */
				string++;
				level = 0;
				while (*string) {
					if (*string == '%') {
						string++;
						if (*string == '?')
							level++;
						else if (*string == ';') {
							if (level > 0)
								level--;
							else
								break;
						}
					}

					if (*string)
						string++;
				}
				break;

			case ';':
				break;

			} /* endswitch (*string) */
		} /* endelse (*string == '%') */

		if (*string == '\0')
			break;

		string++;
	} /* endwhile (*string) */

	return(out_buff);
}

char *tparm(const char *string, ...)
{
va_list	ap;
char *result;

	va_start(ap, string);
#ifdef TRACE
	tname = "tparm";
#endif /* TRACE */
	result = tparam_internal(string, ap);
	va_end(ap);
	return result;
}

#ifdef __UNUSED__	/* we never documented this, and it confuses Emacs */
char *tparam(const char *string, char *buffer, int bufsiz, ...)
{
va_list	ap;
char *result = 0;

	va_start(ap, bufsiz);
#ifdef TRACE
	tname = "tparam";
#endif /* TRACE */
	if (tparam_internal(string, ap) != 0
	 && (int)out_used < bufsiz)
	 	result = strcpy(buffer, out_buff);
	va_end(ap);
	return result;
}
#endif /* __UNUSED */
