//*CID://+vb30R~:                             update#=  154;       //+vb30R~
//*********************************************************************
//*xesub2.h
//* common routine hdr
//*********************************************************************
//vb30:160411 (LNX)Compiler warning                                //+vb30I~
//vb28:160116 (BUG)display spilit utf8 by lineattr                 //~vb28I~
//va8w:101209 SPLIT/TFLOW:delete so/si when join dbcs string       //~va8wI~
//va8s:101026 (BUG)TFLow:head count for top dbcssplit              //~va8sI~
//va8j:101013 SPLit cmd;dbcs consideration for TAIL cut without SBCS option .//~va8jI~
//va7x:100825 lcmd; no translation option for "=","C","M"          //~va7xI~
//va79:100809 cpeb converter parm support                          //~va79I~
//va53:100419 num setr/seti should chk margin/lrecl overflow       //~va53I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//va3P:100320 utf8 file sort dbcs split option;D[S|I|X] space/include/exclude//~va3PI~
//va20:091125 (UTF8)UTF8 full support(display utf8 also unprintable as locale code)//~va20I~
//va1c:091030_merge GB18030 support                                //~va1cI~
//*********************************************************************
//**************************************************
int xesub_cleardbcssplit(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,UCHAR Prepchar);
#define XESUBCDSO_LEFT         0x01   //left inner boundary
#define XESUBCDSO_RIGHT        0x02   //right inner boundary
#define XESUBCDSO_IFREPBYSPACE 0x04   //dbcs tbl clear if repdata=' '
#define XESUBCDSO_REPDATAONLY  0x08   //no dbcs tbl update,data only
#define XESUBCDSO_GETCTR       0x10   //no data/dbcs tbl update
#define XESUBCDSO_SETERR       0x20   //not clear but set dbcserr
#define XESUBCDSO_RESETERR     0x40   //clear dbcs cv err
#define XESUBCDSO_INCLEFT    0x0100   //for getspan                //~va20I~
#define XESUBCDSO_INCRIGHT   0x0200   //for getspan                //~va20R~
#define XESUBCDSO_EXCLEFT    0x0400   //for getspan                //~va20I~
#define XESUBCDSO_EXCRIGHT   0x0800   //for getspan                //~va20I~
#define XESUBCDSO_REPDBCS  0xff0000   //repdbcs char when spli     //~vb28I~
#define XESUBCDSO_REPDBCSSHIFT   16   //repdbcs char shift ctr     //~vb28R~

#define XESUB_DBCSSPLITCTR_L(pcd,pos) /*left byte count of the pos */ \
		xesub_cleardbcssplit(XESUBCDSO_GETCTR|XESUBCDSO_RIGHT, \
			0/*Pdata*/,pcd,pos,0/*Prepchar*/)
#define XESUB_DBCSSPLITCTR_R(pcd,len) /*right byte count of the pos */ \
		xesub_cleardbcssplit(XESUBCDSO_GETCTR|XESUBCDSO_LEFT, \
			0/*Pdata*/,pcd,len,0/*Prepchar*/)
//**************************************************
int xesub_cleardbcs1(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos,UCHAR Prepch);
#define XESUBCD1O_GETCTR       0x01
#define XESUB_DBCSSPLITCTR(Pdbcs,Plen,Ppos) /*dbcs byte ctr*/ \
		xesub_cleardbcs1(XESUBCD1O_GETCTR,0/*Pdata*/,Pdbcs,Plen,Ppos,0/*Prepch*/)
                                                                   //~va20I~
//**************************************************               //~va53I~
int xesub_imupdate(int Popt,PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,int Ppos,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int *Ppnewlen);//~va53I~
#define XESUBIMUO_INS          0x01                                //~va53I~
#define XESUBIMUO_REP          0x02                                //~va53I~
#define XESUBIMUO_SETDBCSTBL   0x04                                //~va53I~
#define XESUBIMUO_SETNEWLEN    0x08                                //~va53R~
//**************************************************               //~va20I~
#ifdef UTF8UCS2                                                    //~va20I~
//**************************************************               //~va20M~
int xesub_adjustspan(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos1,int Ppos2,int *Pppos1,int *Pppos2);//~va20M~
//**************************************************               //~va20I~
int xesubddmemcmp(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen);//~va20R~
#define XESUBDDSCO_NOCASE    0x01      //case sensitive            //~va20R~
#define XESUBDDSCO_HIGHLOW   0x02      //return not only NOTEQ but GT/LT//~va20I~
#define XESUBDDSCO_EQCHKONLY 0x04      //chk eq or not eq          //~va20I~
#define XESUBDDSCO_BANDL     0x08      //compare ebc and locale    //~va50I~
#define XESUBDDSCO_SPLITMASK 0xff00    //direct opt to utfddcmp    //~va3PI~
//**************************************************               //~va50I~
                                                                   //~va50I~
#ifdef UTF8EBCD	  //raw ebcdic file support                        //~va50I~
//  int xesubebcmemcmp(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen);//~va50I~//~va79R~
    int xesubebcmemcmp(int Popt,int Phandle,UCHAR *Pdata1,UCHAR *Pdbcs1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen);//~va79R~
	#define XESUB_memcmp  XESUB_DDMEMCMP                           //~va50I~
//  #define XESUB_memcmp_ebcdd(swebc,swutf,opt,pc1,pcd1,pc2,pcd2,len)//~va79R~
//  	(   (swebc) ? xesubebcmemcmp(opt,pc1,pcd1,pc2,pcd2,len)    //~va79R~
//               : XESUB_memcmp(swutf,opt,pc1,pcd1,pc2,pcd2,len)   //~va79R~
//      )                                                          //~va50I~//~va79R~
	#define XESUB_memcmp_ebcdd(swebc,swutf,handle,opt,pc1,pcd1,pc2,pcd2,len) \
		(   (swebc) ? xesubebcmemcmp(opt,handle,pc1,pcd1,pc2,pcd2,len) \
                 : XESUB_memcmp(swutf,opt,pc1,pcd1,pc2,pcd2,len) \
        )                                                          //~va79I~
#endif //UTF8EBCD raw ebcdic file support                          //~va50I~
                                                                   //~va50I~
//#define XESUB_DDMEMCMP(sw,opt,pc1,pcd1,pc2,pcd2,len)             //+vb30R~
//        (   (sw) ? xesubddmemcmp(opt,(pc1),(pcd1),(pc2),(pcd2),(len))//+vb30R~
//                 : memcmp((pc1),(pc2),(UINT)(len))               //+vb30R~
//        )                                                          //~va20I~//+vb30R~
#define XESUB_DDMEMCMP(sw,opt,pc1,pcd1,pc2,pcd2,len) \
        (   (sw) ? xesubddmemcmp(opt,(pc1),(pcd1),(pc2),(pcd2),(int)(len)) \
                 : memcmp((pc1),(pc2),(size_t)(len)) \
        )                                                          //+vb30I~
#define XESUB_memcmpeq  XESUB_DDMEMCMPEQ                           //~va20R~
#define XESUB_DDMEMCMPEQ(sw,pc1,pcd1,pc2,pcd2,len) /*for eqchk string*/\
		XESUB_DDMEMCMP(sw,XESUBDDSCO_EQCHKONLY,pc1,pcd1,pc2,pcd2,len)//~va20R~
#define XESUB_DDMEMCMPEQA(sw,pc1,pcd1,pc2,len) /*for eqchk ascii string*/\
		XESUB_DDMEMCMP(sw,XESUBDDSCO_EQCHKONLY,pc1,pcd1,pc2,0/*dbcs2*/,len)//~va20R~
#define XESUB_memicmp(sw,pc1,pcd1,pc2,pcd2,len) /*for eqchk ascii string*/\
		XESUB_DDMEMCMP(sw,XESUBDDSCO_EQCHKONLY|XESUBDDSCO_NOCASE,pc1,pcd1,pc2,pcd2,len)//~va20I~
//#define XESUB_EBCUTF8_memcmpeq_bandl(swebc,swu8,pc1,pcd1,pc2,pcd2,len)//~va79R~
//		UWHICH(swebc,                                              //~va79R~
//				xesubebcmemcmp(XESUBDDSCO_BANDL|XESUBDDSCO_EQCHKONLY,pc1,pcd1,pc2,pcd2,len),//~va79R~
//				XESUB_memcmpeq(swu8,pc1,pcd1,pc2,pcd2,len)         //~va79R~
//             )                                                     //~va50I~//~va79R~
#define XESUB_EBCUTF8_memcmpeq_bandl(swebc,swu8,handle,pc1,pcd1,pc2,pcd2,len) \
		UWHICH(swebc, \
				xesubebcmemcmp(XESUBDDSCO_BANDL|XESUBDDSCO_EQCHKONLY,handle,pc1,pcd1,pc2,pcd2,len), \
				XESUB_memcmpeq(swu8,pc1,pcd1,pc2,pcd2,len) \
             )                                                     //~va79I~
//#define XESUB_EBCUTF8_memcmpeq(swebc,swu8,pc1,pcd1,pc2,pcd2,len) //~va79R~
//		UWHICH(swebc,                                              //~va79R~
//				xesubebcmemcmp(XESUBDDSCO_EQCHKONLY,pc1,pcd1,pc2,pcd2,len),//~va79R~
//				XESUB_memcmpeq(swu8,pc1,pcd1,pc2,pcd2,len)         //~va79R~
//            )                                                     //~va50I~//~va79R~
#define XESUB_EBCUTF8_memcmpeq(swebc,swu8,handle,pc1,pcd1,pc2,pcd2,len) \
		UWHICH(swebc, \
				xesubebcmemcmp(XESUBDDSCO_EQCHKONLY,handle,pc1,pcd1,pc2,pcd2,len), \
				XESUB_memcmpeq(swu8,pc1,pcd1,pc2,pcd2,len) \
             )                                                     //~va79I~
//#define XESUB_EBCUTF8_umemmem_bandl(swebc,swu8,pc1,pcd1,pc2,len1,len2)//~va79R~
//		UWHICH(swebc,                                              //~va79R~
//				xeebc_umemmem_bandl(0,pc1,pcd1,pc2,len1,len2),     //~va79R~
//				(UCHAR *)UTF_umemmem(swu8,pc1,pcd1,pc2,0,len1,len2)//~va79R~
//            )                                                     //~va50I~//~va79R~
#define XESUB_EBCUTF8_umemmem_bandl(swebc,swu8,handle,pc1,pcd1,pc2,len1,len2) \
		UWHICH(swebc, \
				xeebc_umemmem_bandl(0,handle,pc1,pcd1,pc2,len1,len2), \
				(UCHAR *)UTF_umemmem(swu8,pc1,pcd1,pc2,0,len1,len2) \
              )                                                    //~va79I~
                                                                   //~va50I~
#define XESUB_setdbcssplit_reset(swebc,plh,pc,pcd,len,repch) \
		(   (swebc) ? xesub_setdbcssplit(XESUBSDSO_EBC|XESUBSDSO_SETDBCSTBL,plh,pc,pcd,len,repch) \
                    : setdbcssplit(0,pc,pcd,len,repch)        \
        )                                                          //~va50I~
int xesub_setdbcssplit(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,char Prepch);//~va50I~
#define XESUBSDSO_EBCMASK       0xff                               //~va50R~
#define XESUBSDSO_EBC           0x01                               //~va50I~
#define XESUBSDSO_SETDBCSTBL  0x0100                               //~va50I~
#define XESUBSDSO_NOSBCSIFEBC 0x0200        //no SBCS option for EBC file//~va8jI~
#define XESUBSDSO_HALFCUTONLY 0x0400        //set sosi for halfcut  dbcs only//~va8jI~
#define XESUBSDSO_GETSPLITCTR 0x0800        //get counter replaced to space//~va8sI~
#define XESUBSDSO_PREV2ND     0x1000        //left boundary is next of DBCS2ND//~va8wI~
#define XESUBSDSO_HALFCUTONLYL 0x2000       //set sosi for halfcut  dbcs only  on left boundary//~va8wR~
#define XESUBSDSO_HALFCUTONLYR 0x4000       //set sosi for halfcut  dbcs only  on right boundary//~va8wR~
#define XESUBSDSO_NEXT1ST      0x8000       //next of right boundary DBCS1ST//~va8wI~
//**************************************************               //~va8wI~
int xesub_setdbcssplitib(int Popt,PULINEH Pplh,UCHAR *Pdata,UCHAR *Pdbcs,int Plen,int Ppos,char Prepch);//~va8wI~
//**************************************************               //~va20I~
int xesub_memcmpbin(int Popt,UCHAR *Pdata1,UCHAR *Pdbcs1,int Plen1,UCHAR *Pdata2,UCHAR *Pdbcs2,int Plen2,//~va7xR~
					int *Pppos1,int *Pppos2);                      //~va7xI~
#endif                                                             //~va20I~
