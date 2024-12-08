//CID://+v5nzR~:                                                   //~v5bcR~//~v5nzR~
//***************************************************************  //~v327I~
//v5nz:081129 add uque_move(move qhdr)                             //~v5nzI~
//v5bc:040202 add uqufree to use ufree to free                     //~v5bcI~
//v59m:031109 (BUG:compile err)UQFREE macro end with ";"           //~v59mI~
//v327 000820:LINUX support(CRLF)                                  //~v327I~
//***************************************************************  //~v327I~
//* QUE macro ***********************************************
#define UGETQTOP(pqh)   ((void*)(((PUQUEH)(void*)(pqh))->UQtop))
#define UGETQEND(pqh)   ((void*)(((PUQUEH)(void*)(pqh))->UQend))
#define UGETQCUR(pqh)   ((void*)(((PUQUEH)(void*)(pqh))->UQcur))
#define UGETQCTR(pqh)           (((PUQUEH)(void*)(pqh))->UQctr) 
#define UGETQNEXT(pqe)  ((void*)(((PUQUEE)(void*)(pqe))->UQnext))
#define UGETQPREV(pqe)  ((void*)(((PUQUEE)(void*)(pqe))->UQprev))
#define UGETQHDR(pqe)   ((void*)(((PUQUEE)(void*)(pqe))->UQqhdr))
#define UENQ(opt,qh,qe) \
     uenq((opt),((PUQUEH)(PVOID)(qh)),((PUQUEE)(PVOID)(qe)))
#define UDEQ(opt,qh,qe) \
     udeq((opt),((PUQUEH)(PVOID)(qh)),((PUQUEE)(PVOID)(qe)))
#define UQSCAN(opt,qh,func,key) \
     uqscan((opt),((PUQUEH)(PVOID)(qh)),func,key)
#define UQFREE(qh)  \
    uqfree(((PUQUEH)(PVOID)(qh)))                                  //~v59mI~
#define UQUFREE(qh)  \
    uqufree(((PUQUEH)(PVOID)(qh)))                                 //~v5bcI~
//  uqfree(((PUQUEH)(PVOID)(qh)));                                 //~v59mR~
#define UENQCHAIN(qe,qh)    \
    uenqchain(((PUQUEE)(PVOID)(qe)),((PUQUEH)(PVOID)(qh)))
#define UENQENT(opt,qet,qes)    \
    uenqent((opt),((PUQUEE)(PVOID)(qet)),((PUQUEE)(PVOID)(qes)))
//****************************************
#define UQUE_TOP       1
#define UQUE_END       2
#define UQUE_BEF       3
#define UQUE_AFT       4
#define UQUE_CUR       5
#define UQUE_ENT       6
//*uenq/udeq
typedef struct _UQUEH {
                        struct _UQUEE  *UQtop;  //top entry
                        struct _UQUEE  *UQend;  //last entry
                        struct _UQUEE  *UQcur;  //current entry
                        long   UQctr;   //entry count
                      } UQUEH;
typedef UQUEH  *PUQUEH;
#define UQUEHSZ sizeof(UQUEH)
typedef struct _UQUEE {
                        struct _UQUEE *UQnext;  //next entry
                        struct _UQUEE *UQprev;  //previous entry
                        struct _UQUEH *UQqhdr;  //enqued UQUEH addr
                      } UQUEE;
typedef UQUEE  *PUQUEE;
#define UQUEESZ sizeof(UQUEE)
//*******************************************************
long uenq(int Popt,PUQUEH Pque,PUQUEE Pentry);
//*******************************************************
void *udeq(int Popt,PUQUEH Pque,PUQUEE Pentry);
//*******************************************************
void *uqscan(int Popt,PUQUEH Pque,int (*Ppfunc)(PUQUEE,void*),void *Ppkey);
//*******************************************************
long uqfree(UQUEH* Ppqh);
//*******************************************************          //~v5bcI~
long uqufree(UQUEH* Ppqh);                                         //~v5bcI~
//*******************************************************
long uenqchain(PUQUEE Pentry,PUQUEH Pque);
//*******************************************************
long uenqent(int Popt,PUQUEE Ptarget,PUQUEE Psource);
//*******************************************************          //~v5nzI~
int uqhmove(int Popt,PUQUEH Ptarget,PUQUEH Psource);               //+v5nzR~
