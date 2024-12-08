//CID://+v5mnR~:                                                   //+v5mnR~
//*************************************************************
//*udpmilb2.c support function which  is not on libc               //~v077R~
//*  malloc/free/realloc
//*************************************************************    //~v077R~
//v5mn:080323 regex GCC support                                    //+v5mnI~
//v261:990703 (GCC) asm err from after V134;size_t included in udpmilib.h//~v261I~
//            but include sequence is invalid in udpmilb2.c        //~v261I~
//v106:971027 (BUG:GCC)sbrk dosenot return continuous memory under win95.//~v106I~
//  2@@@@     Block addr is page boundary -4 at first by the logic in malloc.//~v106R~
//            (req to __sblk to set __what_size_dpmi_think_we_are to page boundary.)//~v106I~
//            Blk in another 64k may be on page boundary if __what_size_app_think_it_is//~v106R~
//            reached to it.                                       //~v106I~
//            Abandon -4 setup logicin malloc.It may return always page boundary.//~v106R~
//            And,dump page should also collect by alloc addr like as os/2.//~v106I~
//v077:970421 add reuse function to malloc/free to 
//            djgpp\src\libc\ansi\stdlib\malloc.c
//            free:chk all free in page if len<=pagesize/2-4(2044).//~v077R~
//                 if all are free entry,enq the page to 2048 size fre-que//~v077R~
//            morecore:if no backet entry for reqlen<=2044,        //~v077R~
//                     chk free 2048 size que and deq a page       //~v077R~
//            (a page always contain same size of entry if len<=2044)//~v077R~
//*************************************************************
//#include <ulib.h>                                                //~v261R~
//*******************************************************
/* Copyright (C) 1994 DJ Delorie, see COPYING.DJ for details */
/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that: (1) source distributions retain this entire copyright
 * notice and comment, and (2) distributions including binaries display
 * the following acknowledgement:  ``This product includes software
 * developed by the University of California, Berkeley and its contributors''
 * in the documentation or other materials provided with the distribution
 * and in all advertising materials mentioning features or use of this
 * software. Neither the name of the University nor the names of its
 * contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * malloc.c (Caltech) 2/21/82
 * Chris Kingsley, kingsley@cit-20.
 *
 * This is a very fast storage allocator.  It allocates blocks of a small 
 * number of different sizes, and keeps free lists of each size.  Blocks that
 * don't exactly fit are passed up to the next larger size.  In this 
 * implementation, the available sizes are 2^n-4 (or 2^n-10) bytes long.
 * This is designed for use in a virtual memory environment.
 */

#include <libc/stubs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//*************************                                        //~v261I~
#include <ulib.h>                                                  //~v261I~
//*************************                                        //~v261I~

#define getpagesize() 4096

/*
 * The overhead on a block is at least 4 bytes.  When free, this space
 * contains a pointer to the next free block, and the bottom two bits must
 * be zero.  When in use, the first byte is set to MAGIC, and the second
 * byte is the size index.  The remaining bytes are for alignment.
 * If range checking is enabled then a second word holds the size of the
 * requested block, less 1, rounded up to a multiple of sizeof(RMAGIC).
 * The order of elements is critical: ov_magic must overlay the low order
 * bits of ov_next, and ov_magic can not be a valid ov_next bit pattern.
 */
union overhead {
  union	overhead *ov_next;	/* when free */
  struct {
    unsigned char	ovu_magic; /* magic number */
    unsigned char	ovu_index; /* bucket # */
#ifdef RCHECK
    unsigned short	ovu_rmagic; /* range magic number */
    unsigned int	ovu_size; /* actual block size */
#endif
  } ovu;
#define	ov_magic	ovu.ovu_magic
#define	ov_index	ovu.ovu_index
#define	ov_rmagic	ovu.ovu_rmagic
#define	ov_size		ovu.ovu_size
};

#define	MAGIC		0xef		/* magic # on accounting info */
#define RMAGIC		0x5555		/* magic # on range info */

#ifdef RCHECK
#define	RSLOP		sizeof (unsigned short)
#else
#define	RSLOP		0
#endif

/*
 * nextf[i] is the pointer to the next free block of size 2^(i+3).  The
 * smallest allocatable block is 8 bytes.  The overhead information
 * precedes the data area returned to the user.
 */
#define	NBUCKETS 30
//static	union overhead *nextf[NBUCKETS];//@@@@                 //~v077R~
static	union overhead *nextf[NBUCKETS+1];	//@@@@ last is free page que//~v077I~

static	int pagesz;			/* page size */
static	int pagebucket;			/* page size bucket */

#ifdef MSTATS
/*
 * nmalloc[i] is the difference between the number of mallocs and frees
 * for a given block size.
 */
static	unsigned int nmalloc[NBUCKETS];
#endif

static void morecore(int bucket);

#if defined(DEBUG) || defined(RCHECK)
#define	ASSERT(p)   if (!(p)) botch(#p)
static void
botch(char *s)
{
  fprintf(stderr, "\r\nassertion botched: %s\r\n", s);
  (void) fflush(stderr);	/* just in case user buffered it */
  *((int *)-1) = 0;		/* force fault; abort will probably fail if malloc's dead */
  abort();
}
#else
#define	ASSERT(p)
#endif
                                                                   //~v077R~
int free_chkpage(union overhead *Pop,int Pbucket);	//@@@@         //~v077R~

void *
malloc(size_t nbytes)
{
  union overhead *op;
  int bucket, n;
  unsigned amt;

  /*
   * First time malloc is called, setup page size and
   * align break pointer so all data will be page aligned.
   */
  if (pagesz == 0) {
    pagesz = n = getpagesize();
    op = (union overhead *)sbrk(0);
//  n = n - sizeof (*op) - ((int)op & (n - 1));  //len upto page boundary -4//2@@@@//~v106R~
    n = n - ((int)op & (n - 1));  //len upto page boundary //2@@@@ //~v106I~
    if (n < 0)
      n += pagesz;
    if (n) {
      if (sbrk(n) == (char *)-1)
	return (NULL);
    }
    bucket = 0;
    amt = 8;
    while (pagesz > amt) {
      amt <<= 1;
      bucket++;
    }
    pagebucket = bucket;
  }
  /*
   * Convert amount of memory requested into closest block size
   * stored in hash buckets which satisfies request.
   * Account for space used per block for accounting.
   */
  if (nbytes <= (n = pagesz - sizeof (*op) - RSLOP)) {
#ifndef RCHECK
    amt = 8;			/* size of first bucket */
    bucket = 0;
#else
    amt = 16;			/* size of first bucket */
    bucket = 1;
#endif
    n = -(sizeof (*op) + RSLOP);
  } else {
    amt = pagesz;
    bucket = pagebucket;
  }
  while (nbytes > amt + n) {
    amt <<= 1;
    if (amt == 0)
      return (NULL);
    bucket++;
  }
  /*
   * If nothing in hash bucket right now,
   * request more memory from the system.
   */
  if ((op = nextf[bucket]) == NULL) {
    morecore(bucket);
    if ((op = nextf[bucket]) == NULL)
      return (NULL);
  }
  /* remove from linked list */
  nextf[bucket] = op->ov_next;
  op->ov_magic = MAGIC;
  op->ov_index = bucket;
#ifdef MSTATS
  nmalloc[bucket]++;
#endif
#ifdef RCHECK
  /*
   * Record allocated size of block and
   * bound space with magic numbers.
   */
  op->ov_size = (nbytes + RSLOP - 1) & ~(RSLOP - 1);
  op->ov_rmagic = RMAGIC;
  *(unsigned short *)((char *)(op + 1) + op->ov_size) = RMAGIC;
#endif
  return ((char *)(op + 1));
}

/*
 * Allocate more memory to the indicated bucket.
 */
static void
morecore(int bucket)
{
  union overhead *op;
  int sz;			/* size of desired block */
  int amt;			/* amount to allocate */
  int nblks;			/* how many blocks we get */

  /*
   * sbrk_size <= 0 only for big, FLUFFY, requests (about
   * 2^30 bytes on a VAX, I think) or for a negative arg.
   */
  sz = 1 << (bucket + 3);
#ifdef DEBUG
  ASSERT(sz > 0);
#else
  if (sz <= 0)
    return;
#endif
  if (sz < pagesz) {
    amt = pagesz;
    nblks = amt / sz;
	if (op=nextf[NBUCKETS],op)		//@@@@ free page exist         //~v077R~
	 	nextf[NBUCKETS]=op->ov_next;	//@@@@ deq                 //~v077R~
  } else {
    amt = sz + pagesz;
    nblks = 1;
    op=0;						//@@@@ force sbrk                  //~v077R~
  }
if(!op)							//@@@@ no free block, force sbrk   //~v077R~
  op = (union overhead *)sbrk(amt);
  /* no more room! */
  if ((int)op == -1)
    return;
  /*
   * Add new memory allocated to that on
   * free list for this hash bucket.
   */
  nextf[bucket] = op;
  while (--nblks > 0) {
    op->ov_next = (union overhead *)((char *)op + sz);
    op = (union overhead *)((char *)op + sz);
  }
  op->ov_next = 0;
}

void
free(void *cp)
{   
  int size;
  union overhead *op;
  if (cp == NULL)
    return;
  op = (union overhead *)((char *)cp - sizeof (union overhead));
#ifdef DEBUG
  ASSERT(op->ov_magic == MAGIC); /* make sure it was in use */
#else
  if (op->ov_magic != MAGIC)
    return;			/* sanity */
#endif
#ifdef RCHECK
  ASSERT(op->ov_rmagic == RMAGIC);
  ASSERT(*(unsigned short *)((char *)(op + 1) + op->ov_size) == RMAGIC);
#endif
  size = op->ov_index;
  ASSERT(size < NBUCKETS);
  op->ov_next = nextf[size];	/* also clobbers ov_magic */
  nextf[size] = op;
#ifdef MSTATS
  nmalloc[size]--;
#endif
  free_chkpage(op,size);  		//@@@@ chk page is filled with free entry//~v077R~
}

void *
realloc(void *cp, size_t nbytes)
{   
  unsigned int onb;
  int i;
  union overhead *op;
  char *res;
  int was_alloced = 0;
#ifdef AAA                                                         //+v5mnR~
 printf("realloc req\n");     //@@@@@                              //~v077R~
  abort();                //@@@@@                                  //~v077R~
#endif                                                             //+v5mnI~
                                                                   //~v077I~
  if (cp == NULL)
    return (malloc(nbytes));
  op = (union overhead *)((char *)cp - sizeof (union overhead));
  if (op->ov_magic == MAGIC)
  {
    was_alloced++;
    i = op->ov_index;
  }
  else
  {
    return 0;
  }
  onb = 1 << (i + 3);
  if (onb < pagesz)
    onb -= sizeof (*op) + RSLOP;
  else
    onb += pagesz - sizeof (*op) - RSLOP;
  /* avoid the copy if same size block */
  if (was_alloced) {
    if (i) {
      i = 1 << (i + 2);
      if (i < pagesz)
	i -= sizeof (*op) + RSLOP;
      else
	i += pagesz - sizeof (*op) - RSLOP;
    }
    if (nbytes <= onb && nbytes > i) {
#ifdef RCHECK
      op->ov_size = (nbytes + RSLOP - 1) & ~(RSLOP - 1);
      *(unsigned short *)((char *)(op + 1) + op->ov_size) = RMAGIC;
#endif
      return(cp);
    }
    else
      free(cp);
  }
  if ((res = malloc(nbytes)) == NULL)
    return (NULL);
  if (cp != res)
    memcpy(res, cp, (nbytes < onb) ? nbytes : onb);
  return (res);
}

#ifdef MSTATS
/*
 * mstats - print out statistics about malloc
 * 
 * Prints two lines of numbers, one showing the length of the free list
 * for each size category, the second showing the number of mallocs -
 * frees for each size category.
 */
_mstats(s)
	char *s;
{
  	int i, j;
  	union overhead *p;
  	int totfree = 0,
  	totused = 0;

  	fprintf(stderr, "Memory allocation statistics %s\nfree:\t", s);
  	for (i = 0; i < NBUCKETS; i++) {
  		for (j = 0, p = nextf[i]; p; p = p->ov_next, j++)
  			;
  		fprintf(stderr, " %d", j);
  		totfree += j * (1 << (i + 3));
  	}
  	fprintf(stderr, "\nused:\t");
  	for (i = 0; i < NBUCKETS; i++) {
  		fprintf(stderr, " %d", nmalloc[i]);
  		totused += nmalloc[i] * (1 << (i + 3));
  	}
  	fprintf(stderr, "\n\tTotal in use: %d, total free: %d\n",
	    totused, totfree);
}
#endif
                                                                   //~v077R~
//*******************************************************          //~v077R~
//*chk page for free,if all free enq to backet 2048    @@@@        //~v077R~
//* parm1:overhead ptr                                             //~v077R~
//* parm2:free entry bucket number                                 //~v077R~
//* retrn:0:none is done,1:enqed to bucket 2048                    //~v077R~
//*******************************************************          //~v077R~
	void *Gpnextf=&nextf;       //extern to be reffered            //~v077I~
int free_chkpage(union overhead *Pop,int Pbucket)                  //~v077R~
{                                                                  //~v077R~
	union overhead *op,*op0,*op1,*op2;                             //~v077R~
	union overhead *opend;          //end addr 2@@@@               //~v106I~
    int nblks,sz;                                                  //~v077R~
    int ii;                                                        //~v077I~
#define  MINBLOCKSZ		32                                         //~v077I~
#define  FREEPAGESZ		4096                                       //~v077I~
#define  PAGEMASK      0xfffff000   //page boundary addr //2@@@@   //~v106I~
    int deqctr;                                                    //~v077I~
//*****************                                                //~v077R~
	sz = 1 << (Pbucket + 3);	//boundary size                    //~v077I~
	if (sz>=FREEPAGESZ)			//free page unit is page size      //~v077I~
    	return 0;                                                  //~v077M~
	if (sz<MINBLOCKSZ)			//for performance,chk only >=32,128 entry per  page//~v077I~
    	return 0;                                                  //~v077I~
//  op0=op=(void*)((char*)Pop-(((int)Pop+sizeof(*op)) & (pagesz-1)));	//page boundary//2@@@@//~v106R~
    op0=op=(void*)((int)Pop & PAGEMASK);	//page boundary//2@@@@ //~v106R~
    opend=(void*)((char*)Pop+FREEPAGESZ);			//end addr ch 2@@@@//~v106I~
    nblks = FREEPAGESZ / sz;                                       //~v077R~
//*chk all free                                                    //~v077R~
    for (ii=0;ii<nblks;ii++)                                       //~v077R~
	{                                                              //~v077R~
    	if (op->ov_magic == MAGIC)	//allocated                    //~v077R~
      		return 0;				//do nothing                   //~v077R~
      	op = (union overhead *)((char *)op + sz);                  //~v077R~
    }                                                              //~v077R~
//*confirm all entry is on free que                                //~v077R~
    op1=nextf[Pbucket];		//top entry                            //~v077R~
    op2=(void*)(&nextf[Pbucket]);                                  //~v077R~
    deqctr=0;                                                      //~v077I~
    while (op1)                                                    //~v077R~
    {                                                              //~v077R~
      if (op1>=op0 && op1<opend) //performance up 2@@@@            //~v106I~
      {//2@@@@                                                     //~v106I~
    	op=op0;						//page top                     //~v077I~
        for (ii=0;ii<nblks;ii++)                                   //~v077I~
    	{                                                          //~v077I~
        	if (op==op1)		//                                 //~v077R~
            {                                                      //~v077R~
            	op2->ov_next=op1->ov_next;	//deq middle entry     //~v077R~
				deqctr++;                                          //~v077I~
                op1=op2;    //prev is also prev for next loop      //~v077I~
                break;                                             //~v077I~
			}                                                      //~v077R~
          	op = (union overhead *)((char *)op + sz);              //~v077I~
        }                                                          //~v077R~
      }//in the page 2@@@@                                         //~v106I~
        op2=op1;			//prev entry                           //~v077I~
        op1=op1->ov_next;	//next entry                           //~v077I~
    }                                                              //~v077M~
    if (deqctr!=nblks)		//no magic(free entry) but not on free chain//~v077I~
    {                                                              //~v077I~
  		fprintf(stderr, "\nfree_chkpage detected free page override(%p)\n",//~v077I~
        			op0);                                          //~v077I~
		(void) fflush(stderr);	/* just in case user buffered it *///~v077I~
  		*((int *)-1) = 0;		/* force fault; abort will probably fail if malloc's dead *///~v077I~
  		abort();                                                   //~v077I~
    	return 0;                                                  //~v077I~
	}                                                              //~v077I~
//*enq to free page pool                                           //~v077I~
    op=op0;                                                        //~v077R~
    op->ov_next=nextf[NBUCKETS];	//free page pool               //~v077I~
    nextf[NBUCKETS]=op;                                            //~v077I~
    return 1;                                                      //~v077R~
}//free_chkpage                                                    //~v077R~
