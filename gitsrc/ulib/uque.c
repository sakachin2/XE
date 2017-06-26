//CID://+v6BxR~:              update#=      2                      //+v6BxR~
//**************************************************
//*ENQ(uenq)/DEQ(udeq)/uqscan/uqfree			*
//**************************************************
//v6Bx:160212 (LNX)compiler warning at suse64                      //+v6BxI~
//v6hh:120623 Compile on VC10x64 (__LP64 is not defined but _M_X64 and _M_AMD64 and long is 4 byte).  defines ULPTR(unsigned long long)//~v6hhI~
//v5nz:081129 add uqhmove(move qhdr)                               //~v5nzI~
//v5bc:040202 add uqufree to use ufree to free                     //~v5bcI~
//v328 000826:LINUX:gcc detected warning:uninitialized var         //~v328I~
//v022:960727:WIN32(CONSOLE api)                                   //~v022I~
//*950114 bug:qcout count down when deq                         //~5114I~
//**************************************************            //~5114I~
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//*************************************************************
#include <ulib.h>                                                  //~v6hhI~
#include <uerr.h>
#include <uque.h>
#include <ualloc.h>                                                //~v5bcI~
//*************************************************************
//*******************************************************
//*dummy for lib(same name as file)						*
//*******************************************************
void uque(void)
{
	return;
}
//*******************************************************
//*uenq
//*   current ptr is set to the new entry	
//*parm1:option  1:enq to first,   2:enq to last,
//*              3:before current, 4:after current
//*parm2:queue addr
//*parm3:entry addr
//*ret  :enq count after enq
//*******************************************************
long uenq(int Popt,PUQUEH Pque,PUQUEE Pentry)
{
	PUQUEE pqe,pqew;
//**********************
	if (!Pentry || !Pque)
		uerrexit("uenq:NULL Queue or NULL Entry parameter.",
				 "uenq:キュ－またはエントリ－パラメータが NULL");
	if (Pentry->UQqhdr)
		uerrexit("uenq:Entry(%08X) already enqued",
				 "uenq:エントリー(%08X)は既にキューされている",
				 Pentry);
	switch (Popt)
	{
	case UQUE_TOP:	//first 
		pqe=Pque->UQtop;								//old top
		Pentry->UQnext=pqe;							//next of new top
		Pentry->UQprev=0;  		                  	//prev of new top

		if(pqe)										//not first time
			pqe->UQprev=Pentry;						//prev of old top
		else										//first time
			Pque->UQend=Pentry;						//also last

		Pque->UQtop=Pentry;     						//new top
		break;
	case UQUE_END:	//last
		pqe=Pque->UQend;								//old last
		Pentry->UQnext=0;  		                  	//next of new last
		Pentry->UQprev=pqe;							//prev of new last

		if (pqe)									//not first time
			pqe->UQnext=Pentry;						//next of old last
		else										//first time
			Pque->UQtop=Pentry;						//also top 

		Pque->UQend=Pentry;     						//new last
		break;
	case UQUE_BEF:		//before current
		pqe=Pque->UQcur;								//old current
		Pentry->UQnext=pqe; 			                //next of new cur
		if (pqe)									//not first time
		{
			if ((pqew=Pentry->UQprev=pqe->UQprev),!pqew)	//prev of new cur//~v022R~
				Pque->UQtop=Pentry;					//new top
			else
				pqew->UQnext=Pentry;					//next of old prev
			pqe->UQprev=Pentry;						//prev of old cur
		}
		else										//first time
			Pque->UQtop=Pque->UQend=Pentry;				//new top and end
		break;
	case UQUE_AFT:		//after  current
		pqe=Pque->UQcur;								//old current
		Pentry->UQprev=pqe; 							//prev of new cur
		if (pqe)									//not first time
		{
			if ((pqew=Pentry->UQnext=pqe->UQnext),!pqew)	//next of new cur//~v022R~
				Pque->UQend=Pentry;					//new last
			else
				pqew->UQprev=Pentry;					//prev of old next
			pqe->UQnext=Pentry;						//next of old cur
		}
		else										//first time
			Pque->UQtop=Pque->UQend=Pentry;				//new top and end
		break;
	default:
		uerrexit("uenq:option parm(%d) err",
				 "uenq オプション(第一)パラメータ: %d の誤り",
				 Popt);
		break;
	}

	Pque->UQcur=Pentry;								//new cur
	Pentry->UQqhdr=Pque;								//enqued id
	return ++Pque->UQctr;  		 					//q count
}//uenq

//*******************************************************
//*udeq
//*parm1:option  1:deq from first, 2:deq from last,
//*              5:deq current,    6:deq specified entry
//*		current is set to next if next exist,set to prev if next not exist
//*parm2:queue addr
//*parm3:entry addr(opt=6 only)                                 //~5923R~
//*ret  :dequed entry addr,0 if no entry
//*******************************************************
void *udeq(int Popt,PUQUEH Pque,PUQUEE Pentry)
{
	PUQUEE pqe=0,pqew;                                             //~v328R~
	PUQUEH pqh;
//**********************
	if (Pque)
	{
		if (!Pque->UQtop)						//no entry
			return 0;
	}	
	else
		if (Popt!=UQUE_ENT)
			uerrexit("udeq:NULL Queue parameter.",
				 "udeq:キューパラメータが NULL");
	switch (Popt)
	{
	case UQUE_TOP:	//first 
		pqe=Pque->UQtop;						//old top
		if ((pqew=Pque->UQtop=pqe->UQnext),!pqew)	//new top      //~v022R~
			Pque->UQend=0;					//new end
		else
			pqew->UQprev=0;					//prev of new top
		break;
	case UQUE_END:	//last
		pqe=Pque->UQend;						//old last
		if ((pqew=Pque->UQend=pqe->UQprev),!pqew)	//new top      //~v022R~
			Pque->UQtop=0;					//new end
		else
			pqew->UQnext=0;					//next of new last
		break;
	case UQUE_CUR:	//current
	case UQUE_ENT:	//deq specified entry
 		if (Popt==UQUE_ENT)
		{
			if (!Pentry)
				uerrexit("udeq:NULL Entry parameter.",
						 "udeq:エントリーパラメータが NULL");
			if ((pqh=UGETQHDR(Pentry)),!pqh)	//setqaddr         //~v022R~
				uerrexit("udeq:Not Queued Entry(%08X).",
						 "udeq:エントリーは既にフリーです。(%08X)",
						 Pentry);
	
			if (!Pque)
				Pque=pqh;
			else
				if (Pque!=pqh)
					uerrexit("udeq:Entry(%08X) is not on the queue(%08X).",
							 "udeq:エントリー(%08X)はこのキュー(%08X)上にはあいりませ。",
							 Pentry,Pque);
			pqe=Pentry;
		}
		else
			pqe=Pque->UQcur;						//old current

		if (pqe->UQprev)						//not top
			((PUQUEE)(pqe->UQprev))->UQnext=pqe->UQnext;	//next of old prev
		else
			Pque->UQtop=pqe->UQnext;				//curr next is new top
		if (pqe->UQnext)						//not last
			((PUQUEE)(pqe->UQnext))->UQprev=pqe->UQprev;	//prev of old next
		else
			Pque->UQend=pqe->UQprev;				//curr prev is new last

		break;
	default:
		uerrexit("udeq option parm(%d) err",
				 "udeq:オプション(第一)パラメータ: %d の誤り",
				 Popt);
	}
	if ((Pque->UQcur=pqe->UQnext),!Pque->UQcur)				//curr next is curr if exist//~v022R~
		Pque->UQcur=pqe->UQprev;					//else curr prev is curr
	pqe->UQqhdr=0;								//dequed id
	--Pque->UQctr;  		 					//q count       //~5114I~
	return pqe; 				 				//q entry
}//udeq

//*******************************************************
//*uqscan
//*parm1:option  1:search from first, 2:search from last,
//*              5:search start from current
//*		current is set to checed last
//*parm2:queue addr
//*parm3:compare fonction addr
//*parm4:search key
//*ret  :found entry addr
//*******************************************************
void *uqscan(int Popt,PUQUEH Pque,int (*Ppfunc)(PUQUEE,void*),void *Ppkey)
{
	int rc;                                                        //~v022R~
	PUQUEE pqe=0;                                                  //~v328R~
//**********************
	switch(Popt)
	{
	case UQUE_TOP:
		pqe=Pque->UQtop;
		break;
	case UQUE_END:
		pqe=Pque->UQend;
		break;
	case UQUE_CUR:
		pqe=Pque->UQcur;
		break;
	}//sw by opt

	while(pqe)					//entry exist
	{
		if (Pque!=pqe->UQqhdr)
			uerrexit("uqscan:Que(%08X)-Entry(%08X) is corrupted",
					 "uenq:キュー(%08X)のエントリー(%08X)が壊れている",
					 Pque,pqe);
		Pque->UQcur=pqe;			//latest current
		rc=Ppfunc(pqe,Ppkey);			//compare
		if (!rc)				//found
			break;
		if (rc<0)				//back search
			pqe=pqe->UQprev;	//step back
		else					//foward search	
			pqe=pqe->UQnext;	//step foward
	}
	return pqe;
}//uqscan

//*******************************************************
//*uqfree
//*parm1:queue addr
//*ret  :dequed entry count
//*******************************************************
long uqfree(UQUEH* Ppqh)
{
	PUQUEE pqe;
	long ctr;                                                      //~v022R~
//****************************
	ctr=UGETQCTR(Ppqh);
	while(pqe=udeq(UQUE_TOP,Ppqh,0),pqe)	//entry exist
		free(pqe);
	return ctr;
}//uqfree
//*******************************************************          //~v5bcI~
//*uqufree                                                         //~v5bcI~
//*parm1:queue addr                                                //~v5bcI~
//*ret  :dequed entry count                                        //~v5bcI~
//*******************************************************          //~v5bcI~
long uqufree(UQUEH* Ppqh)                                          //~v5bcR~
{                                                                  //~v5bcI~
	PUQUEE pqe;                                                    //~v5bcI~
	long ctr;                                                      //~v5bcI~
//****************************                                     //~v5bcI~
	ctr=UGETQCTR(Ppqh);                                            //~v5bcI~
	while(pqe=udeq(UQUE_TOP,Ppqh,0),pqe)	//entry exist          //~v5bcI~
		ufree(pqe);                                                //~v5bcI~
	return ctr;                                                    //~v5bcI~
}//uqufree                                                         //~v5bcR~
//*******************************************************
//*uenqchain
//*   chained enq(enq full entry on q to after specified another q entry)
//*parm1:target entry
//*parm2:queue addr containing entry chain
//*ret  :added counter
//*******************************************************
long uenqchain(PUQUEE Pentry,PUQUEH Pque)
{
	PUQUEH pque;
	PUQUEE pqef,pqen;
	PUQUEE pqe;                                                    //~v5nzI~
//**********************
	if (!Pentry || !Pque)
		uerrexit("uenqchain:NULL Queue or NULL Entry parameter.",
				 "uenq:キュ－またはエントリ－パラメータが NULL");
	if ((pque=Pentry->UQqhdr),!pque)                               //~v022R~
		uerrexit("uenq:Entry(%08X) is not on any que",
				 "uenq:エントリー(%08X)はキューされていない。",
				 Pentry);
	if ((pqef=UGETQTOP(Pque)),!pqef)	//null entry               //~v022R~
		return 0;

	pqen=UGETQNEXT(Pentry);		//save current next
	Pentry->UQnext=pqef;		//chain top entry
//reset qhdr ptr                                                   //~v5nzI~
    pqe=pqef;                   //source chaind top                //~v5nzI~
	while(pqe)					//entry exist                      //~v5nzI~
	{                                                              //~v5nzI~
		pqe->UQqhdr=pque;    //set target entry's qhdr             //~v5nzI~
		pqe=pqe->UQnext;	//step foward                          //~v5nzI~
	}                                                              //~v5nzI~
                                                                   //~v5nzI~
	((UQUEE*)UGETQEND(Pque))->UQnext=pqen;//chain to last entry
	pque->UQctr+=Pque->UQctr;
	return Pque->UQctr;
}//uenqchain

//*******************************************************
//*uenqent
//*   entry enq after/before specified entry
//*parm1:3:before current, 4:after current
//*parm2:target entry(qued)
//*parm3:source entry(free)
//*ret  :enq counter
//*******************************************************
long uenqent(int Popt,PUQUEE Ptarget,PUQUEE Psource)
{
	PUQUEH pque;
//**********************
	if (!Ptarget || !Psource)
		uerrexit("uenqchain:NULL Entry parameter.",
				 "uenq:エントリ－パラメータが NULL");
	if ((pque=Ptarget->UQqhdr),!pque)                              //~v022R~
		uerrexit("uenq:Entry(%08X) is not on any que",
				 "uenq:エントリー(%08X)はキューされていない。",
				 Ptarget);
	pque->UQcur=Ptarget;	//set curent
	return uenq(Popt,pque,Psource);
}//uenqchain

//*******************************************************          //~v5nzI~
//*uqhmove                                                         //~v5nzI~
// copy quehdr then clear source qhdr                              //~v5nzI~
//*parm1:target qhdr                                               //~v5nzI~
//*parm2:source qhdr                                               //~v5nzI~
//*ret  :entry count                                               //~v5nzI~
//*******************************************************          //~v5nzI~
int uqhmove(int Popt,PUQUEH Ptgt,PUQUEH Psrc)                      //~v5nzI~
{                                                                  //~v5nzI~
	PUQUEE pqe;                                                    //~v5nzI~
//**********************                                           //~v5nzI~
	pqe=UGETQTOP(Psrc);                                            //~v5nzI~
	memcpy(Ptgt,Psrc,UQUEHSZ);                                     //~v5nzI~
	memset(Psrc,0,UQUEHSZ);                                        //~v5nzI~
	while(pqe)					//entry exist                      //~v5nzI~
	{                                                              //~v5nzI~
		pqe->UQqhdr=Ptgt;                                          //~v5nzI~
		pqe=pqe->UQnext;	//step foward                          //~v5nzI~
	}                                                              //~v5nzI~
//	return Ptgt->UQctr;                                            //~v5nzI~//+v6BxR~
  	return (int)(Ptgt->UQctr);                                     //+v6BxI~
}//uqhmove                                                         //~v5nzI~
