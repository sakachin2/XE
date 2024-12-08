//*CID://+vbymR~:                            update#=  538;        //~vbymR~
//*************************************************************
//*xechar13.c                                                     //~v04dR~//~va50R~
//* edcdic file line edit                                          //~va50I~
//*************************************************************
//vbym:230612 ARM;warning by audroidstudio compiler                //~vbymI~
//vaa7:111117 (gcc4.6)Warning:unused-but-set                       //~vaa3I~
//va79:100809 cpeb converter parm support                          //~va79I~
//va50:100324 Raw EBCDIC file support for NFS mount                //~va50I~
//*************************************************************
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifdef DOS
#else
    #ifdef W32                                                     //~v72NI~
    #else                                                          //~v72NI~
        #define INCL_BASE                                          //~v72NR~
        #include <os2.h>                                           //~v72NR~
    #endif                                                         //~v72NI~
#endif
//*******************************************************
#include <ulib.h>                                                  //~va50I~
#include <uerr.h>                                                  //~va50I~
#include <uque.h>                                                  //~va50I~
#include <ualloc.h>                                                //~va50I~
#include <ufile.h>                                                 //~va50I~
#ifdef UTF8SUPPH                                                   //~va50I~
#include <ustring.h>                                               //~va50I~
#include <udbcschk.h>                                              //~va50I~
#include <utf.h>                                                   //~va50I~
#include <ukbd.h>                                                  //~va50I~
#include <ucvext.h>                                                //~va79I~
#include <ucvebc.h>                                                //~va50I~
#include <ucvebc4.h>                                               //~va79I~
#include <utrace.h>                                                //~va50I~
#endif                                                             //~va50I~
                                                                   //~va50I~
#include "xe.h"                                                    //~va50I~
#include "xescr.h"                                                 //~va50I~
#include "xescr2.h"                                                //~va50I~
#include "xefile.h"                                                //~va50I~
#include "xefile12.h"                                              //~va50I~
#include "xefile22.h"                                              //~va50I~
#include "xefile42.h"                                              //~va50I~
#include "xefile6.h"                                               //~va50I~
#include "xechar.h"                                                //~va50I~
#include "xechar12.h"                                              //~va50I~
#include "xeerr.h"                                                 //~va50I~
#include "xepan.h"                                                 //~va50I~
#include "xesub.h"                                                 //~va50I~
#include "xesub2.h"                                                //~va50I~
#include "xegbl.h"                                                 //~va50I~
#include "xeutf.h"                                                 //~va50I~
#include "xeebc.h"                                                 //~v72NI~//~v777I//~va50I~
#include "xeopt.h"                                                 //~v72NI~//~v777I//~va50I~
#include "xeundo.h"                                                //~v72NI~//~v777I//~va50I~
#include "xelcmd.h"                                                //~v72NI~//~v777I//~va50R~
#include "xelcmd2.h"                                                //~v72NI~//~v777I//~va50R~
//*******************************************************
//*******************************************************       //~v04dI~
//*******************************************************          //~va50I~
#ifdef AAA                                                         //~va50I~
//**************************************************               //~va50M~
//*in margin space availability chk                                //~va50M~
//**************************************************               //~va50M~
int xeebc_marginchk(int Popt,int Pmode,PUFILEH Ppfh,PULINEH Pplh,int Ppos,UCHAR *Pkeyindata,int Pkeyindatalen,int *Ppcutlen)//~va50R~
{                                                                  //~va50M~
	int margin,reslen,reslen2;                                     //~va50R~
    UCHAR *pc,*pc0;                                                //~va50M~
//*********************                                            //~va50M~
    margin=Ppfh->UFHmergin;                                        //~va50M~
    if (Ppos>=margin)                                              //~va50M~
    	return -1;                                                 //~va50M~
    if (Pmode==CHAROPREP)                                          //~va50I~
    {                                                              //~va50I~
    	reslen=Ppos+Pkeyindatalen-margin;                          //~va50I~
        if (reslen<=0)                                             //~va50I~
        	return 0;                                              //~va50I~
	    for (reslen=Pkeyindatalen,pc=Pkeyindata+reslen-1;pc>=Pkeyindata && reslen>0;pc--,reslen--)//~va50I~
        {                                                          //~va50I~
    		if (*pc!=CHAR_EBC_SPACE)                               //~va50I~
        		break;                                             //~va50I~
        }                                                          //~va50I~
    }                                                              //~va50I~
    else	//INSERT                                               //~va50I~
    {                                                              //~va50I~
    	reslen=Pkeyindatalen;                                      //~va50I~
        reslen2=margin-Pplh->ULHlen;                               //~va50I~
    	pc0=Pplh->ULHdata;                                         //~va50I~
    	pc=pc0+margin-1;                                           //~va50I~
        if (reslen2>0)                                             //~va50I~
        {                                                          //~va50I~
        	reslen-=reslen2;                                       //~va50I~
            pc-=reslen2;                                           //~va50R~
        }                                                          //~va50I~
    	for (;pc>=pc0 && reslen>0;pc--,reslen--)                   //~va50I~
        {                                                          //~va50I~
    		if (*pc!=CHAR_EBC_SPACE)                               //~va50I~
        		break;                                             //~va50I~
        }                                                          //~va50I~
        if (reslen>0)                                              //~va50I~
        {                                                          //~va50I~
	   		for (pc=Pkeyindata+Pkeyindatalen-1;pc>=Pkeyindata && reslen>0;pc--,reslen--)//~va50I~
        	{                                                      //~va50I~
    			if (*pc!=CHAR_EBC_SPACE)                           //~va50I~
        			break;                                         //~va50I~
        	}                                                      //~va50I~
        }                                                          //~va50I~
    }                                                              //~va50I~
    return reslen;                                                 //~va50M~
}//xeebc_marginchk                                                 //~va50R~
//**************************************************               //~va50I~
//*xeebcsetobdbcs                                                  //~va50I~
//*set err to dbcs replaced by sbcs except                         //~va50R~
//*return:1:set at left,2:set at right                             //~va50R~
//**************************************************               //~va50I~
int xeebc_setobdbcserr(int Popt,UCHAR *Pdata,UCHAR *Pdbcs,int Pdatalen,int Ppos,int Prangelen)//~va50R~
{                                                                  //~va50I~
    int     rightpos;                                              //~va50I~
    UCHAR   *pcd;                                                  //~va50I~
    int rc=0;                                                      //~va50R~
//*************                                                    //~va50I~
    if (Ppos>0 && Ppos<Pdatalen)    //left boundary on data        //~va50I~
    {                                                              //~va50I~
//*chk dbcs on the left boundary                                   //~va50I~
        pcd=Pdbcs+Ppos;                //split pos                 //~va50I~
        if (UDBCSCHK_DBCS2NDL(*pcd)  //left boundery on the dbcs   //~va50I~
        ||  UDBCSCHK_DBCS1STL(*(pcd-1)))//left boundery on the dbcs//~va50I~
        {                                                          //~va50I~
            *(Pdata+Ppos-1)=CHAR_EBC_SPACE;                        //~va50R~
            *(pcd-1)=UDBCSCHK_HKDBCSERR;                           //~va50I~
            rc|=1;                                                 //~va50I~
        }                                                          //~va50I~
    }//left                                                        //~va50I~
//*                                                                //~va50I~
    if ((rightpos=Ppos+Prangelen)<Pdatalen && rightpos >0)  //data exist on the right//~va50I~
    {                                                              //~va50I~
//*chk dbcs on the right boundary                                  //~va50I~
        if (UDBCSCHK_DBCS2NDL(*(pcd=Pdbcs+rightpos)))//right boundary on the DBCS//~va50I~
        {                                                          //~va50I~
            *(pcd)=UDBCSCHK_HKDBCSERR;                             //~va50I~
            rc|=2;                                                 //~va50I~
        }                                                          //~va50I~
    }//right data exist                                            //~va50I~
    return rc;                                                     //~va50R~
}//xeebc_setobdbcserr                                              //~va50I~
#endif                                                             //~va50M~
//**************************************************
//*char field input process
//*return:0:ok  ,4:buff overflow
//**************************************************
int charfldeditebc(int Pmode,UCHAR *Pbuff,UCHAR *Pdbcs,            //~va50R~
				int Pcurcol,int Pstartcol,int Pendcol,int Pbuffend,
				PUCLIENTWE Ppcw,PULINEH Pplh,                   //~4C27R~//~va50R~
                PULINEH Plcmdplh2,int Pnetlen,int Pnetoomlen)	   //~va50I~
{
	UCHAR *pc,*pcd;                                             //~5506R~
	UCHAR *keyindata;                                           //~4C27I~
    PULINEH plhnext;                                            //~5104I~
    PUFILEH  pfh;                                                  //~v0byR~
	int len,addlen,keyindatalen;                                //~5507R~
	int mergin;                                                    //~v0avR~
    int oomlen=0;	//out of mergin len                            //~v0dhR~
    int spfsw2=0;                                                  //~v0dhR~
    int spfpos;                                                    //~v417I~
    int merginsw;                                                  //~v0dbI~
    int coboffs;                                                   //~v42gI~
    int oomprotsw=0;                                               //~v0eqR~
    int newlen;                                                    //~v0e0I~
    int inmerginsw;                                                //~v0evI~
    int protlen=0;                                                 //~v0ihI~
    int binsw=0;                                                   //~v106I~
    int hexmodesw=0;                                               //~v444I~
    int datapos,hexinpsw;                                          //~v441R~
	int vhexmode,vhexolddata;		//virtical hex display mode    //~v60vI~
    UCHAR vhexnewchar;                                             //~v60vR~
    int rcmc=0;   //marginchk rc(==1:overflow but space only)      //~v71UR~
    int opt;                                                       //~v73gI//~va50R~
//  int hexkbdsw;                                                  //~v778I//~vbymR~
//  int hexkbdgcsw; //hex notation graph char input                //~v79RI//+vbymR~
    int newlen2,addlen2;                                           //~v7a0R
//  int optorg;                                                    //~va3SI~//~vaa7R~
    int hpos,hpose,swcv2ebc;                                       //~va50R~
    int rc3;                                                       //~va50R~
	int keyindatalen_ebc,sosiopt=0,backctr,optsbcs;                //~va50R~
    UCHAR   keyindata_ebc[4];                                      //~va50R~
    UCHAR   keyindata_ebcdbcs[4];                                  //~va50I~
	UCHAR *pc2,*pcd2;                                              //~va50I~
    int handle;                                                    //~va79R~
//****************************
//  optorg=Pmode;                                                  //~va3SI~//~vaa7R~
    Pmode &=0xffff; //vhexmode and ope code                        //~va3SI~
    vhexmode=(int)((UINT)Pmode>>8);                                //~v60vR~
    Pmode&=0xff;	//clear vhexmode parm;mode byte                //~v60vR~
	hexinpsw=0;				//next hex csr position                //~v441R~
//  hexkbdsw=UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBD);                 //~v79RR//~vbymR~
//  hexkbdgcsw=UCBITCHK(Ppcw->UCWflag3,UCWF3HEXKBDGC); //graph char input//~v79RR//+vbymR~
//      hexkbdsw|=hexkbdgcsw;	//do filesetdbcstbl                //~v79RI//~vbymR~
		pfh=UGETPFH(Pplh);                                         //~v0byR~
        handle=pfh->UFHhandle;                                     //~va79I~
		if (UCBITCHK(pfh->UFHflag4,UFHF4BIN))                      //~v106I~
        	binsw=1;	//no tab skip                              //~v106I~
        if (UCBITCHK(pfh->UFHflag5,UFHF5HEX))                      //~v444I~
            hexmodesw=1;                                           //~v444I~
//  	optsbcs=(binsw || !UDBCSCHK_ISDBCSCV())*XEEBCSO_BIN;//converter support DBCS//~va50R~//~va79R~
    	optsbcs=(binsw || !UCVEBCH_HANDLE_ISDBCSCV(handle))*XEEBCSO_BIN;//converter support DBCS//~va79I~
	    if ((vhexmode & USDF2VHEXLINE2)         //csr on lower vhex line//~va3TI~
        &&  (Goptopt3 & GOPT3_VHEXCSRZIGZAG)    //zigzag csr mov mode//~va3TI~
        &&  (Pmode==CHAROPINS)                                     //~va3TI~
        )                                                          //~va3TI~
        	Pmode=CHAROPREP;	//replace lower line hex char      //~va3TI~
            if (Pmode==CHAROPREP||Pmode==CHAROPINS)                //~va50R~
            {                                                      //~va50I~
            	if (vhexmode)                                      //~va50I~
                	swcv2ebc=0;                                    //~va50I~
                else                                               //~va50I~
                {                                                  //~va50I~
	            	swcv2ebc=1;                                    //~va50I~
                    if (hexmodesw)                                 //~va50R~
                    {                                              //~va50I~
                        filegethposrange(pfh,Pplh->ULHlen,&hpos,&hpose);//get hex area range//~va50I~
                        if (Pcurcol>=hpos)	//hex part input       //~va50R~
                            swcv2ebc=0;                            //~va50I~
                    }                                              //~va50I~
                }                                                  //~va50I~
            	if (swcv2ebc)                                      //~va50I~
                {                                                  //~va50R~
                    rc3=xeebc_chargetkbd(0,Ppcw);//translate utf8/local-->ebcdic on Ppcw//~va50R~
                    if (rc3>=4)                                    //~va50R~
                        return 4;                                  //~va50R~
                }                                                  //~va50R~
            }                                                      //~va50I~
    	protlen=pfh->UFHprotlen;                                   //~v0ihI~
		mergin=pfh->UFHmergin;                                     //~v0byI~
		spfpos=pfh->UFHspfpos;                                     //~v417I~
        spfsw2=UCBITCHK(pfh->UFHflag2,UFHF2SPFNUMOK|UFHF2SPFNUMERR);//~v0dhR~
        if (spfsw2)                                                //~v0dhI~
            if (Pendcol>mergin)	//if <=mergin,it is valid spf line //~v0dhI~
              	spfsw2=fileisvalidspfline(pfh,Pplh,0);//no update line spf flag//~v0duR~
        merginsw=UCBITCHK(pfh->UFHflag2,UFHF2MERGIN);              //~v0dbI~
        oomprotsw=!UCBITCHK(pfh->UFHflag3,UFHF3OOMNOPROT);         //~v0eqR~
	keyindata=Ppcw->UCWkeydata;                                 //~4C27I~
	keyindatalen=Ppcw->UCWkeytype;                              //~4C27I~
                                                                   //~va20I~
	pc=Pbuff+Pcurcol;
	pcd=Pdbcs+Pcurcol;
    if (Pmode==CHAROPINS        //insert mode                      //~v09jI~
    &&  Pbuffend==Pstartcol+1   //1byte input fld                  //~v09jI~
    &&  keyindatalen==1)        //1byte input                      //~v09jI~
        Pmode=CHAROPREP;        //accept as rep                    //~v09jI~
	switch(Pmode)
	{
//**********************                                           //~va50I~
//* REP ****************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPREP:	//rep
        if ((Pcurcol+keyindatalen)>=Pbuffend)                   //~v020R~//~va50R~
        {                                                       //~5127I~//~va50R~
            if ((Pcurcol+keyindatalen)>Pbuffend)                //~v020I~//~va50R~
                return charfieldfullerr();                      //~v020R~//~va50R~
            UCBITON(Ppcw->UCWflag,UCWFFIELDFULL);//for func_char//~v020I~//~va50R~
        }                                                       //~5127I~//~va50R~

            if (hexmodesw)                                         //~v444R~
            {                                                      //~v441I~
            	datapos=Pcurcol;                                   //~v441R~
				hexinpsw=filecharhexinput(Ppcw,pfh,Pplh,Pcurcol,&datapos,Pmode);//~v441R~
                if (hexinpsw>=4) 	//err                          //~v441R~
                	return 4;                                      //~v441I~
                if (hexinpsw)		//hex part input               //~v441R~
                {                                                  //~v441I~
    		        if (vhexmode)	//hex display line of vhexmode //~v70nI~
	                	return 4;                                  //~v70nI~
                	Pcurcol=datapos;                               //~v441R~
					pc=Pbuff+Pcurcol;	//pos on data              //~v441I~
					pcd=Pdbcs+Pcurcol;                             //~v441I~
                }                                                  //~v441I~
            }                                                      //~v441I~
            if (vhexmode)	//hex display line of vhexmode         //~v60vI~
            {                                                      //~v60vI~
              	if (Pcurcol>Pendcol)                              //~v60vR~//~v76dI
	            	vhexolddata=-1;	//id of outof range            //~v60vI~
                else                                               //~v60vI~//~v76dI
              	if (Pcurcol==Pendcol)                              //~v60vR~//~v76dI
	            	vhexolddata=0;	//append 1 byte                //~v76dI
                else                                               //~v60vI~
                	vhexolddata=*pc;                               //~v60vR~
				if (filecharhexinput_v(Ppcw,keyindata,keyindatalen,vhexolddata,Pmode,vhexmode,&vhexnewchar))//~va3SI~
                	return 4;                                      //~v60vI~
                keyindatalen=1;                                    //~v60vI~
                keyindata=&vhexnewchar;                            //~v60vR~
            }                                                      //~v60vI~
			sosiopt=xeebc_filesetsosi(XEEBCSO_EXPANDCHK|optsbcs,Pmode,pfh,Pplh,Pcurcol,keyindata,keyindatalen,keyindata_ebc,keyindata_ebcdbcs,&keyindatalen_ebc);//~va50R~
            keyindata=keyindata_ebc;                               //~va50I~
            keyindatalen=keyindatalen_ebc;                         //~va50I~
          if (!hexinpsw)	//not input on hex part                //~v441R~
          {                                                        //~v441I~
			if (Pcurcol>=mergin)                                   //~v0bpI~
            {                                                      //~v0dhI~
              if (oomprotsw)                                       //~v417I~
    			return errprotected();                             //~v417I~
              if (UCBITCHK(pfh->UFHflag7,UFHF7FIXLRECL))           //~v71HI~
			  	if (Pcurcol+keyindatalen>pfh->UFHlrecl)            //~v71HI~
					return charfixlenovererr(pfh->UFHlrecl);                            //~51//~v71HI~
			  if ((Pcurcol+keyindatalen)>MAXLINEDATA)              //~v0e0I~
				return charmaxovererr(MAXLINEDATA);                            //~51//~v0e0I~
			}                                                      //~v0dhI~
            else	//curcol<mergin                                //~v0dhI~
            {                                                      //~v73hI
			if ((Pcurcol+keyindatalen)>mergin)                     //~v0avI~
				return charmaxovererr(mergin);                            //~51//~v0avI~
//            opt=MERGIN_SHORTRECOK;                                 //~v73gI//~va50R~
//            if (vhexmode)                                          //~v73gI//~va50R~
//                opt|=MERGIN_HEX;                                   //~v73gI//~va50R~
//#ifdef UTF8UCS2                                                    //~va22I~//~va50R~
//#else                                                              //~va22I~//~va50R~
//            if (vhexmode) //tab rep case may not occur?//~v73gR  //~va50R~
//#endif                                                             //~va22I~//~va50R~
//                if (filemerginchk(Pplh,Pcurcol,keyindata,keyindata_dddbcs,1,1,//addlen=1,dellen=1//~va20I~//~va50R~
//                    opt,0,0,&oomlen))//opt=addlen=newlen=oomlen=0          //~v0c2R~//~v73gR//~va50R~
//                    return 4;                                      //~v0avI~//~va50R~
            }                                                      //~v73hI
          }//not hex part input                                    //~v441I~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)	//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
                                                                //~5506I~
		if ((len=Pcurcol-Pendcol)>=0)	//out of reclen         //~5507R~
        {                                                          //~v7a0I
 			addlen=keyindatalen;	//after cur col             //~5506I~
            memset(Pbuff+Pendcol,CHAR_EBC_SPACE,(UINT)len); //set before chk tab is replaced//~v7a0I//~va50R~
            memset(Pdbcs+Pendcol,0,(UINT)len);  //result of shorten record//~5507I~//~v7a0I
			newlen2=Pcurcol+addlen;                                //~v7a0I
        }                                                          //~v7a0I
        else                                                    //~5506I~
        {                                                          //~v7a0I
			addlen=max(0,Pcurcol+keyindatalen-Pendcol);         //~5506I~
			newlen2=Pendcol+addlen;                                //~v7a0R
        }                                                          //~v7a0I
//      if (!hexinpsw)    //not input on hex part                    //~v448R~//~va50R~
//      {                                                            //~v73nI//~va50R~
//       if (!vhexmode)   //hex display line of vhexmode             //~v63uR~//~va50R~
//       {                                                           //~v63uR~//~va50R~
//            setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pcurcol,keyindatalen);//~5507R~//~va50R~
//                        //replace opverridden tab/dbcs          //~5506I~//~va50R~
//       }                                                           //~v63uR~//~va50R~
//     }                                                             //~v73nI//~va50R~
////     delpadctr=0;                                                  //~v73hI//~va50R~
//                                                                 //~va50R~
//        if (keyindatalen==2)                                    //~4C27R~//~va50R~
//        {                                                        //~va50R~
//            UMOVSW(pc,keyindata);                               //~4C27R~//~va50R~
//            UMOVSW(pcd,Sdbcsid);                                 //~va50R~
//          if (Pplh && Pcurcol<=Pendcol && Pcurcol && *(pcd-1)==UDBCSCHK_HKDBCSERR)//~v7a6R//~va50R~
////*no HKDBCSERR on dd fmt                                          //~va20I~//~va50R~
////*no HKDBCSERR for ebc file                                     //~va50R~
//            filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,newlen2,FSDT_TABSAVE);//~v448R~//~v7a6I//~va50R~
//        }                                                        //~va50R~
//        else                                                     //~va50R~
//        {                                                        //~va50R~
//            {                                                   //~5507I~//~va50R~
////SBCS                                                           //~va50R~
//                *pc=*keyindata;                                 //~5507R~//~va50R~
//              if (hexinpsw||vhexmode||hexkbdsw      //hex input    //~v7a6I//~va50R~
//              ||  (Pplh && Pcurcol<=Pendcol && Pcurcol && *(pcd-1)==UDBCSCHK_HKDBCSERR)//~v7a6R//~va50R~
//              )                                                    //~v7a6I//~va50R~
//              {                                                    //~v454I~//~va50R~
//                *pcd=0;     //clear TAB attr before filesetdbcstbl with FSDT_TABSAVE//~v73wI//~va50R~
////*no HKDBCSERR on dd fmt                                          //~va20I~//~va50R~
////*no vhexmode for utf8file,hexinpsw=hHexmode is binfile,hexkbdsw(hex input mode) is rejexted on utf8 file//~va20I~//~va50R~
////ebcdic file is out of condition                                //~va50R~
//                filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,newlen2,FSDT_TABSAVE);//~v448R~//~v7a0I//~va50R~
//              }                                                    //~v454I~//~va50R~
//              else                                                 //~v448R~//~va50R~
//              {//not hex,not setdbcs required                      //~va20I~//~va50R~
//                *pcd=0;     //sbcs                              //~5507R~//~va50R~
//              }//not hex                                           //~va20I~//~va50R~
//            }                                                   //~5507I~//~va50R~
//        }                                                        //~va50R~
		Pplh->ULHlen=newlen2;                                      //~va50M~
    	xeebc_filesetsosi(sosiopt,Pmode,pfh,Pplh,Pcurcol,keyindata,keyindatalen,keyindata_ebc,keyindata_ebcdbcs,0/*keyindatalen_ebc*/);//~va50M~
        if (optsbcs           //for bin file no dbcsis on dbcstbl was set//~va50I~
        ||  sosiopt & XEEBCSW_INSSO	//SO inserted step 2 byte to DBCS 2nd byte//~va50I~
        )                                                          //~va50I~
	    	Ppcw->UCWreason=UCWREASON_CSRBYKEYTYPE;	//step by 2 column(for bin file no dbcsis was set)//~va50R~
		break;
//**********************                                           //~va50I~
//* INS ****************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPINS:	//isrt
            if (hexmodesw)                                         //~v444I~
            {                                                      //~v441I~
            	datapos=Pcurcol;                                   //~v441I~
				hexinpsw=filecharhexinput(Ppcw,pfh,Pplh,Pcurcol,&datapos,Pmode);//~v441I~
                if (hexinpsw>=4)                                   //~v441I~
                	return 4;                                      //~v441I~
                if (hexinpsw)		//hex part input               //~v441I~
                {                                                  //~v441I~
                    if (hexinpsw==FCHI_ODDINS)  //ins on 2nd byte  //~v441I~
    					return charfldedit(CHAROPREP|(vhexmode<<8),Pbuff,Pdbcs,//~v70nI~
											Pcurcol,Pstartcol,Pendcol,Pbuffend,//~v441I~
											Ppcw,Pplh);            //~v441I~
    		        if (vhexmode)	//hex display line of vhexmode //~v70nI~
	                	return 4;                                  //~v70nI~
                	Pcurcol=datapos;                               //~v441I~
					pc=Pbuff+Pcurcol;	//pos on data              //~v441I~
					pcd=Pdbcs+Pcurcol;                             //~v441I~
                }                                                  //~v441I~
            }//hex mode                                            //~v441R~
            if (vhexmode)	//hex display line of vhexmode         //~v60vI~
            {                                                      //~v60vI~
            	if (Pcurcol>Pendcol)                              //~v60vR~//~v76dI
	            	vhexolddata=-1;	//id of outof range            //~v60vI~
                else                                               //~v76dI
            	if (Pcurcol==Pendcol)                              //~v60vR~//~v76dI
	            	vhexolddata=0;	//id of outof range            //~v60vI~//~v76dI
                else                                               //~v60vI~
                	vhexolddata=*pc;                               //~v60vR~
    			if (filecharhexinput_v(Ppcw,keyindata,keyindatalen,vhexolddata,Pmode,vhexmode,&vhexnewchar))//~va3SI~
                	return 4;                                      //~v60vI~
                keyindatalen=1;                                    //~v60vI~
                keyindata=&vhexnewchar;                            //~v60vR~
            }                                                      //~v60vI~
			sosiopt=xeebc_filesetsosi(XEEBCSO_EXPANDCHK|optsbcs,Pmode,pfh,Pplh,Pcurcol,keyindata,keyindatalen,keyindata_ebc,keyindata_ebcdbcs,&keyindatalen_ebc);//~va50R~
            keyindata=keyindata_ebc;                               //~va50I~
            keyindatalen=keyindatalen_ebc;                         //~va50I~
		if (Pcurcol<Pendcol)		//isrt inter-char
			len=Pendcol-Pcurcol;
		else							//isrt on null
			len=0;

        if ((Pcurcol+keyindatalen+len)>=Pbuffend)               //~v020R~//~va50R~
        {                                                       //~5127I~//~va50R~
            if ((Pcurcol+keyindatalen+len)>Pbuffend)            //~v067I~//~va50R~
                return charfieldfullerr();                      //~v067R~//~va50R~
            if (!len)                                           //~v067I~//~va50R~
            UCBITON(Ppcw->UCWflag,UCWFFIELDFULL);//for func_char//~v020I~//~va50R~
        }                                                       //~5127I~//~va50R~

          if (!hexinpsw)	//not input on hex part                //~v441R~
          {                                                        //~v441I~
			if (Pcurcol>=mergin)                                   //~v0bpI~
            {                                                      //~v0dhI~
              if (oomprotsw)                                       //~v417I~
    			return errprotected();                             //~v417I~
//#ifdef UTF8UCS2                                                    //~va20I~//~va50R~
//              newlen=filegettabexplen(Pplh,Pcurcol,keyindata,keyindata_dddbcs,keyindatalen,0,Pendcol)+Pendcol;//~va20R~//~va50R~
//#else                                                              //~va20I~//~va50R~
//              newlen=filegettabexplen(Pplh,Pcurcol,keyindata,keyindatalen,0,Pendcol)//dellen=0//~v0e0R~//~va50R~
//                     +Pendcol;                                     //~v0e0I~//~va50R~
//#endif                                                             //~va20I~//~va50R~
              newlen=max(Pcurcol,Pendcol)+keyindatalen;            //~va50M~
              	if (UCBITCHK(pfh->UFHflag7,UFHF7FIXLRECL))         //~v71HR~
			  		if (newlen>pfh->UFHlrecl)                      //~v71HI~
						return charfixlenovererr(pfh->UFHlrecl);                            //~51//~v71HR~
			  if (newlen>MAXLINEDATA)                              //~v0e0I~
				return charmaxovererr(MAXLINEDATA);                            //~51//~v0e0I~
			}                                                      //~v0dhI~
            else	//curcol<mergin                                //~v0dhI~
            {                                                      //~v73hI
    			opt=MERGIN_SHORTRECOK;                             //~v73gR
//                if (vhexmode)                                      //~v73gR//~va50R~
//                    opt|=MERGIN_HEX;                               //~v73gR//~va50R~
//#ifdef UTF8UCS2                                                    //~va20I~//~va50R~
//            if (filemerginchk(Pplh,Pcurcol,keyindata,keyindata_dddbcs,keyindatalen,0,//dellen=0//~va20I~//~va50R~
//#else                                                              //~va20I~//~va50R~
//            if (filemerginchk(Pplh,Pcurcol,keyindata,keyindatalen,0,//dellen=0//~v71UR~//~va50R~
//#endif                                                             //~va20I~//~va50R~
    	      if (filemerginchk(Pplh,Pcurcol,keyindata,keyindata_ebcdbcs,keyindatalen,0/*dellen*/,//~va50I~
    							opt,0,0,&oomlen)) //accept merginover flow is space only for short record//~v71UR~//~v73gR
	    		return 4;                                          //~v0avI~
            }                                                      //~v73hI
            if (oomlen==-1)	//shortrec overflow but tab/space only //~v71UI~
            {	                                                   //~v71UI~
            	oomlen=0;                                          //~v71UI~
                rcmc=1;                                            //~v71UI~
            }                                                      //~v71UI~
          }//not hex part input                                    //~v441I~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
//*********                                                        //~va50I~
//            if (oomlen) //ins in mergin and has oom                //~v0evR~//~va50R~
//                setobtabdbcs(Pbuff,Pdbcs,Pendcol,mergin,0);//left/rigth of mergin//~v0evR~//~va50R~
//        if (len)                                                 //~va50R~
//        {                                                        //~va50R~
//          if (!hexinpsw)    //not input on hex part                //~v448I~//~va50R~
//           if (!vhexmode)   //not input on hex part  of vhex mode              //~v448I~//~v735R//~va50R~
//            setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pcurcol,0);           //~v0c4I~//~va50R~
//                        //replace splitted tab/dbcs                //~v0c4I~//~va50R~
//            memmove(pc+keyindatalen,pc,(UINT)len);//shift to right//~4C27R~//~va50R~
//            memmove(pcd+keyindatalen,pcd,(UINT)len);            //~4C27R~//~va50R~
//        }                                                        //~va50R~
//        addlen=keyindatalen;                                    //~4C27R~//~va50R~

//        if (keyindatalen==2)                                    //~4C27R~//~va50R~
//        {                                                        //~va50R~
//            UMOVSW(pc,keyindata);                               //~4C27R~//~va50R~
//            UMOVSW(pcd,Sdbcsid);                                 //~va50R~
//        }                                                        //~va50R~
//        else                                                     //~va50R~
//        {                                                        //~va50R~
//            {                                                   //~5102I~//~va50R~
//                *pc=*keyindata;                                 //~5102R~//~va50R~
//                *pcd=0;     //sbcs                              //~5102R~//~va50R~
//            }                                                   //~5102I~//~va50R~
//        }                                                        //~va50R~
//        if ((addlen2=Pcurcol-Pendcol)>0)    //out of reclen         //~5507I~//~v7a0I//~va50R~
//        {                                                       //~5507M~//~v7a0I//~va50R~
//            memset(Pbuff+Pendcol,' ',(UINT)addlen2);                //~5507I~//~v7a0I//~va50R~
//            memset(Pdbcs+Pendcol,0,(UINT)addlen2);  //result of shorten record//~5507I~//~v7a0I//~va50R~
//        }                                                       //~5507M~//~v7a0I//~va50R~
//        else                                                       //~v7a0I//~va50R~
//            addlen2=0;                                             //~v7a0I//~va50R~
//            if (oomlen)                                            //~v0evI~//~va50R~
//            {                                                      //~v0evI~//~va50R~
//                Pplh->ULHlen+=addlen;                              //~v0evI~//~va50R~
//                addlen=0;                                          //~v0evI~//~va50R~
//                fileoomshiftback(pfh,Pplh,oomlen,0);                 //~v0evI~//~v74EI//~va50R~
//            }                                                      //~v0evI~//~va50R~
//            if (rcmc==1)    //short record margin overflow only space//~v71UI~//~va50R~
//            {                                                      //~v71UI~//~va50R~
//                Pplh->ULHlen=mergin;                               //~v71UI~//~va50R~
//                addlen=0;                                          //~v71UI~//~va50R~
//            }                                                      //~v71UI~//~va50R~
//            if (hexinpsw||vhexmode||hexkbdsw  //not input on hex part                  //~v448I~//~v7a6I//~va50R~
//            ||  (Pcurcol<=Pendcol && Pcurcol && *(pcd-1)==UDBCSCHK_HKDBCSERR)//~v7a6I//~va50R~
//            )                                                      //~v7a6I//~va50R~
//            {                                                      //~v778I//~va50R~
//                if (!addlen)    //not ulhlen reset                 //~v7a0I//~va50R~
//                    addlen2=0;                                     //~v7a0I//~va50R~
//                else                                               //~v7a0I//~va50R~
//                    addlen2+=addlen;                               //~v7a0I//~va50R~
////*no HKDBCSERR on dd fmt                                          //~va20I~//~va50R~
////*no vhexmode for utf8file,hexinpsw=hHexmode is binfile,hexkbdsw(hex input mode) is rejexted on utf8 file//~va20I~//~va50R~
//                filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen+addlen2,FSDT_TABSAVE);//~v448I~//~v7a0I//~va50R~
//            }                                                      //~v778I//~va50R~
//***********                                                      //~va50M~
        if ((addlen2=Pcurcol-Pendcol)>0)    //out of reclen         //~5507I~//~v7a0I//~va50M~
        {                                                       //~5507M~//~v7a0I//~va50M~
            memset(Pbuff+Pendcol,CHAR_EBC_SPACE,(UINT)addlen2);                //~5507I~//~v7a0I//~va50M~
            memset(Pdbcs+Pendcol,0,(UINT)addlen2);  //result of shorten record//~5507I~//~v7a0I//~va50M~
        }                                                       //~5507M~//~v7a0I//~va50M~
        else                                                       //~v7a0I//~va50M~
        	addlen2=0;                                             //~v7a0I//~va50M~
    	if (oomlen) //Pcurcol is inmargin                          //~va50M~
        {                                                          //~va50M~
        	len=mergin-Pcurcol-keyindatalen;                       //~va50M~
            addlen=0;                                              //~va50M~
        }                                                          //~va50M~
        else                                                       //~va50M~
    	if (rcmc==1)	//short record margin overflow only space  //~va50M~
        {                                                          //~va50M~
        	len=mergin-(Pcurcol+keyindatalen);                     //~va50M~
            addlen=mergin-Pendcol;                                 //~va50M~
        }                                                          //~va50M~
        else                                                       //~va50M~
            addlen=addlen2+keyindatalen;                           //~va50R~
        Pplh->ULHlen+=addlen;                                      //~va50M~
		if (len>0)                                                 //~va50M~
		{                                                          //~va50M~
			memmove(pc+keyindatalen,pc,(UINT)len);//shift to right //~va50M~
			memmove(pcd+keyindatalen,pcd,(UINT)len);               //~va50M~
		}                                                          //~va50M~
    	xeebc_filesetsosi(sosiopt,Pmode,pfh,Pplh,Pcurcol,keyindata,keyindatalen,keyindata_ebc,keyindata_ebcdbcs,0/*keyindatalen?ebc*/);//~va50M~
        if (optsbcs           //for bin file no dbcsis on dbcstbl was set//~va50I~
        ||  sosiopt & XEEBCSW_INSSO	//SO inserted step 2 byte to DBCS 2nd byte//~va50I~
        )                                                          //~va50I~
	    	Ppcw->UCWreason=UCWREASON_CSRBYKEYTYPE;	//step by 2 column(for bin file no dbcsis was set)//~va50I~
		break;
//**********************                                           //~va50I~
//* DEL ****************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPDEL:	//del
	case CHAROPIMJOIN:	//inmergin join                            //~v42gI~
	case CHAROPJOINIGM: //join ignore margin                       //~v42gI~//~v74iI
          	if (Pmode==CHAROPDEL)       //del key                  //~v444I~
            {                                                      //~v70nI~
                if (hexmodesw)                                     //~v444I~
                {                                                  //~v444I~
                    datapos=Pcurcol;                               //~v444I~
                    hexinpsw=filecharhexinput(Ppcw,pfh,Pplh,Pcurcol,&datapos,Pmode);//~v444I~
                    if (hexinpsw>=4)    //protected                //~v444I~
                        return 4;                                  //~v444I~
                    if (hexinpsw)       //hex part input           //~v444I~
                    {                                              //~v444I~
	    		        if (vhexmode)	//hex display line of vhexmode//~v70nI~
		                	return 4;                              //~v70nI~
        				if (datapos==Pendcol)       //del CR       //~v58RR~
                        	return 4;                              //~v58RR~
                        Pcurcol=datapos;                           //~v444I~
                        pc=Pbuff+Pcurcol;   //pos on data          //~v444I~
                        pcd=Pdbcs+Pcurcol;                         //~v444I~
                    }                                              //~v444I~
                }//hex mode                                        //~v444I~
            }                                                      //~v70nI~
          if (!hexinpsw)                                           //~v444I~
          {                                                        //~v444I~
			if (Pcurcol>Pendcol)                                //~5104I~
				return 4;                                       //~5104I~
			if (Pcurcol>=mergin)                                   //~v0c3I~
            {                                                      //~v0dhI~
              if (oomprotsw)                                       //~v417I~
    			return errprotected();                             //~v417I~
			}                                                      //~v0dhI~
            else                                                   //~v0dhI~
            {                                                      //~v73gI
              if (Pmode!=CHAROPIMJOIN)       //spf join ignored num fld//~v42gI~
    		    oomlen=filegetoomlen(pfh,Pplh);  //out of mergin len//~v0esR~
            }                                                      //~v73gI
          }//not hex part del                                      //~v444I~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)	//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
            if (Pmode==CHAROPIMJOIN)       //spf join ignored num fld//~v42gI~
                Pplh->ULHlen=Pendcol;                              //~v42gI~
//           if (!vhexmode)                                          //~v73gI//~va50R~
//            if (oomlen) //ins in mergin and has oom                //~v0evI~//~va50R~
//                setobtabdbcs(Pbuff,Pdbcs,Pendcol,mergin,0);//left/rigth of mergin//~v0evR~//~va50R~
        if (Pplh && Pcurcol==Pendcol)       //del CR               //~v0bpR~
		{                                                       //~5104I~
          if (Plcmdplh2)                                           //~v0i7I~//~va50R~
			plhnext=Plcmdplh2;                                     //~v0i7I~//~va50R~
          else                                                     //~v0i7I~
			plhnext=UGETQNEXT(Pplh);                            //~5104I~
    		addlen=                                                //~v0c8I~
            len=Pnetlen;                    //len without cid      //~v0cdI~//~va50R~
            if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file     //~v42gI~
                coboffs=SPFCOBNUMFLDLEN;                           //~v42gI~
            else                                                   //~v42gI~
                coboffs=0;                                         //~v42gI~
			memcpy(pc,plhnext->ULHdata+coboffs,(UINT)len);         //~v42gR~
			memcpy(pcd,plhnext->ULHdbcs+coboffs,(UINT)len);        //~v42gR~
          	if (Pmode==CHAROPJOINIGM)      //shift back if avail   //~v74iI
        		oomlen=Pnetoomlen;                                 //~v74uI//~va50R~
//#ifdef UTF8SUPPH                                                   //~va1cR~//~va50R~
//            if (UDBCSCHK_ISGB4ENV()  //also fo 2 byte dbcs if gb4 env//~va1cR~//~va50R~
//            &&  pcd>Pplh->ULHdbcs                                  //~va1cR~//~va50R~
//            )                                                      //~va1cR~//~va50R~
//            {                                                      //~v77gI//~va1cR~//~va50R~
//                joinpos=Pcurcol;                                   //~v77gI//~va1cR~//~va50R~
////*ddfmt chk will be done at charjoinsetdbcstbl                    //~va20I~//~va50R~
//                addlen+=charjoinsetdbcstbl(0,Pplh,&joinpos,&len);  //~v77gI//~va1cR~//~va50R~
//                if (!vhexmode)                                     //~va1cR~//~va50R~
//                    if (UDBCSCHK_DBCSNOT1ST(*pcd))//setdbcstbl changed this column to dbcs parts not 1st(conbined to prev column)                        //~v77gR//~va1cR~//~va50R~
//                        Ppcw->UCWreason=UCWREASON_DELEOLGB4;    //csr move to right//~va1cR~//~va50R~
//            }                                                      //~v77gI//~va1cR~//~va50R~
//            else                                                   //~va1cR~//~va50R~
//#endif                                                             //~va1cR~//~va50R~
//            if (pcd>Pplh->ULHdbcs && *(pcd-1)==UDBCSCHK_HKDBCSERR) //~v77gI//~va50R~
//            {                                                      //~v77gI//~va50R~
//                joinpos=Pcurcol;                                   //~v77gI//~va50R~
////*no HKDBCSERR on dd fmt                                          //~va20I~//~va50R~
//                addlen+=charjoinsetdbcstbl(0,Pplh,&joinpos,&len);  //~v77gI//~va50R~
//#ifdef UTF8SUPPH                                                   //~va1qI~//~va50R~
//              if (!vhexmode)                                          //~v73gI//~va12I~//~va50R~
//#endif                                                             //~va1qI~//~va50R~
//#ifdef UTF8SUPPH                                                   //~va1cR~//~va50R~
//                if (UDBCSCHK_DBCSNOT1ST(*pcd))//setdbcstbl changed this column to dbcs parts not 1st(conbined to prev column)                        //~v77gR//~va1cR~//~va50R~
//#else                                                              //~va1cR~//~va50R~
//                if (*pcd==UDBCSCHK_DBCS2ND)                        //~v77gR//~va50R~
//#endif                                                             //~va1cR~//~va50R~
//                    Ppcw->UCWreason=UCWREASON_HEXSTEPDEL;   //func_del_file dose not call filecharcsr(assume csr will not move),so//~v77gR//~va50R~
//            }                                                      //~v77gI//~va50R~
          	if (pcd>Pplh->ULHdbcs)	//not concat to null line      //~va50M~
            {                                                      //~va50M~
//  			xeebc_setdbcstbl(0,Pplh->ULHdata,Pplh->ULHdbcs,Pcurcol+len);//~va50M~//~va79R~
    			xeebc_setdbcstbl(0,handle,Pplh->ULHdata,Pplh->ULHdbcs,Pcurcol+len);//~va79I~
                Pplh->ULHlen=Pcurcol+len;                          //~va50M~
            }                                                      //~va50M~
            if (lcmddel(Ppcw,plhnext,plhnext,1,0,1)==UALLOC_FAILED)//~v057R~
					//1 linedel,no csr move,clear UFHcmdline    //~v057I~
            	return UALLOC_FAILED;                           //~v04dI~
          if (!Plcmdplh2)                                          //~v0i7I~//~va50R~
			UPCTRREQ(pfh);	//end of a shot                        //~v0ceI~
		}                                                       //~5104I~
		else		//not concat line                           //~5104I~
		{                                                       //~5104I~
			backctr=0;                                             //~va50I~
          if (vhexmode)	//not input on hex part                    //~v448I~//~v73uI
          {                                                        //~v73wI
			    keyindatalen=1;  //nodbcs consideration                                //~v448I~//~v73uI
          }                                                        //~v73wI
          else                                                     //~v448I~//~v73uI
          if (hexinpsw)	//not input on hex part                    //~v448I~
			    keyindatalen=1;                                    //~v448I~
          else                                                     //~v448I~
          {                                                        //~v448I~
//#ifdef UTF8UCS2                                                    //~va20I~//~va50R~
//            if (UDBCSCHK_DBCS1STLU(*pcd))   //also ucs dd fmt      //~va20R~//~va50R~
//            {                                                      //~va38I~//~va50R~
//#else                                                              //~va20I~//~va50R~
//            if (*pcd==DBCS1STCHAR)                              //~5104R~//~va50R~
//#endif                                                             //~va20I~//~va50R~
//#ifdef UTF8SUPPH                                                   //~va1cR~//~va50R~
//                keyindatalen=1+xesub_cleardbcssplit(XESUBCDSO_LEFT|XESUBCDSO_GETCTR,0/*data*/,pcd+1,Pendcol-Pcurcol,0/*repct*/);//~va1cR~//~va50R~
//#else                                                              //~va1cR~//~va50R~
//                keyindatalen=2;                                 //~5104R~//~va50R~
//#endif                                                             //~va1cR~//~va50R~
//            }                                                      //~va38I~//~va50R~
//            else                                                //~5104R~//~va50R~
//            {                                                      //~va38I~//~va50R~
//                    keyindatalen=1;                             //~5104R~//~va50R~
//            }                                                      //~va38I~//~va50R~
//            setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pcurcol,keyindatalen);//~v0c4I~//~va50R~
//                        //replace deleted tab/dbcs                 //~v0c4I~//~va50R~
			sosiopt=xeebc_getdbcssplitctr(0,pfh,Pplh,Pcurcol,&keyindatalen,&backctr);//~va50M~
          }//not hexinput                                          //~v448I~
//            len=Pendcol-Pcurcol-keyindatalen;                   //~5104R~//~va50R~
//            memcpy(pc,pc+keyindatalen,(UINT)len);               //~5104R~//~va50R~

//            memcpy(pcd,pcd+keyindatalen,(UINT)len);             //~5104R~//~va50R~
//            addlen=-keyindatalen;                               //~5104R~//~va50R~
	        if (oomlen)                                            //~va50M~
				len=mergin-Pcurcol-keyindatalen+backctr;           //~va50M~
            else                                                   //~va50M~
            {                                                      //~va50M~
				len=Pendcol-Pcurcol-keyindatalen+backctr;          //~va50M~
            }                                                      //~va50M~
            pc2=pc-backctr;                                        //~va50M~
            pcd2=pcd-backctr;                                      //~va50M~
            if (len>0)                                             //~va50M~
            {                                                      //~va50M~
				memcpy(pc2,pc2+keyindatalen,(UINT)len);            //~va50M~
				memcpy(pcd2,pcd2+keyindatalen,(UINT)len);          //~va50M~
            }                                                      //~va50M~
            if (oomlen)                                            //~va50M~
            {	                                                   //~va50M~
				memset(pc2+len,CHAR_EBC_SPACE,(UINT)keyindatalen); //~va50R~
				memset(pcd2+len,0,(UINT)keyindatalen);             //~va50R~
            }                                                      //~va50M~
            else                                                   //~va50M~
            	Pplh->ULHlen-=keyindatalen;                        //~va50M~
            if (!optsbcs)	//always,becausebyte count may changed between SO/SI//~va50M~
//  			xeebc_setdbcstbl(0,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//always,//~va50M~//~va79R~
    			xeebc_setdbcstbl(0,handle,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//always,//~va79I~
		}                                                       //~5104I~
//            if (oomlen)                                            //~v0evI~//~va50R~
//            {                                                      //~v0evI~//~va50R~
//                Pplh->ULHlen+=addlen;                              //~v0evI~//~va50R~
//                addlen=0;                                          //~v0evM~//~va50R~
//                fileoomshiftback(pfh,Pplh,oomlen,0);                 //~v0evI~//~v74EI//~va50R~
//            }                                                      //~v0evI~//~va50R~
//            if (Pcurcol!=Pendcol)       //not del CR               //~v0bpR~//~v7a0I//~va50R~
//                if (hexinpsw  //not input on hex part                  //~v448I~//~v7a0R//~va50R~
//                ||  vhexmode    //hex display line of vhexmode     //~v7a6I//~va50R~
//                ||  (Pcurcol<=Pendcol && Pcurcol && *(pcd-1)==UDBCSCHK_HKDBCSERR)//~v7a6I//~va50R~
//                )                                                  //~v7a6I//~va50R~
//                {                                                  //~v7a6I//~va50R~
////*no HKDBCSERR on dd fmt                                          //~va20I~//~va50R~
////*no vhexmode for utf8file,hexinpsw=hHexmode is binfile,hexkbdsw(hex input mode) is rejexted on utf8 file//~va20I~//~va50R~
//                    filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen+addlen,FSDT_TABSAVE);//~v7a0R//~va50R~
//                }                                                  //~v7a6I//~va50R~
		break;
//**********************                                           //~va50I~
//* EOL ****************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPEEOL:	//erase eof(trunc line)                 //~5111R~
	case CHAROPEEOLIGM:	//erase eof(trunc line;erase also oom)                 //~5111R~//~v74jI
		if (Pcurcol>=Pendcol)
			return 4;
        inmerginsw=0;                                              //~v0dbI~
	     if (Pmode!=CHAROPEEOLIGM)	//erase eof(trunc line)        //~v74jI
         {                                                         //~v74jI
    		if (Pcurcol>=mergin)                                   //~v0eqI~
          		if (oomprotsw)                                     //~v417I~
    			return errprotected();                             //~v417I~
                                                                   //~v0eqI~
          if (!spfpos || oomprotsw)//not spf by n of topline or /mn cmdline option//~v42fR~
          	if (merginsw)                                          //~v0dbI~
	    		if (Pcurcol<mergin && Pendcol>mergin)//data on out of mergin//~v0dbR~
                	inmerginsw=1;                                  //~v0dbI~
         }//not ignore margin                                      //~v74jI
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)	//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
      if (inmerginsw)                                              //~v0dbR~
        keyindatalen=mergin-Pcurcol;                               //~v0dbR~
      else                                                         //~v0dbR~
		keyindatalen=Pendcol-Pcurcol;                           //~4C27R~
//      if (vhexmode                                                //~v76AI//~va3SI~//~va50R~
//      ||  (optorg & CFEO_VHEXLCMDS)   //split lcmd on vhex line    //~va3SI~//~va50R~
//      )                                                            //~va3SI~//~va50R~
//      {                                                            //~v76AI//~va50R~
//          if (inmerginsw)                                              //~v0dbR~//~v76AI//~va50R~
//          {                                                        //~v76AI//~va50R~
//            if (*(pcd+keyindatalen)==DBCS2NDCHAR)                  //~v76AI//~va50R~
////*no vhexmode for utf8file                                        //~va20I~//~va50R~
//                filesetdbcstbl(pc+keyindatalen,pcd+keyindatalen,Pendcol-mergin,FSDT_TABSAVE);//~v76AI//~va50R~
//          }                                                        //~v76AI//~va50R~
//          else                                                     //~v76AI//~va50R~
//#ifdef UTF8SUPPH                                                   //~va1cR~//~va50R~
//            if (Pcurcol>0 && UDBCSCHK_DBCSNOT1ST(*pcd)) //del not 1st//~va1cR~//~va50R~
//            {                                                      //~va1cR~//~va50R~
//                splitdbcsctr=xesub_cleardbcssplit(XESUBCDSO_RIGHT|XESUBCDSO_GETCTR,0/*Pdata*/,Pdbcs,Pcurcol,0/*repch*/);//~va1cR~//~va50R~
////*no vhexmode for utf8file                                        //~va20I~//~va50R~
//                filesetdbcstbl(pc-splitdbcsctr,pcd-splitdbcsctr,splitdbcsctr,0);                    //~v76AR//~va1cR~//~va50R~
//            }                                                      //~va1cR~//~va50R~
//#else                                                              //~va1cR~//~va50R~
//            if (Pcurcol>0 && *pcd==DBCS2NDCHAR)                    //~v76AR//~va50R~
//                filesetdbcstbl(pc-1,pcd-1,1,0);                    //~v76AR//~va50R~
//#endif                                                             //~va1cR~//~va50R~
//      }                                                            //~v76AI//~va50R~
//      else                                                         //~v76AI//~va50R~
//        setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pcurcol,keyindatalen);    //~v0c4I~//~va50R~
//                        //replace deleted tab/dbcs                 //~v0c4I~//~va50R~
//      if (inmerginsw)                                              //~v0dbR~//~va50R~
//        addlen=0;       //clear only,same ulhlen                   //~v0dbI~//~va50R~
//      else                                                         //~v0dbI~//~va50R~
//        addlen=-keyindatalen;                                   //~4C27R~//~va50R~
//            if (inmerginsw)                                        //~v0dbR~//~va50R~
//            {                                                      //~v0dbR~//~va50R~
//                memset(pc,' ',(UINT)keyindatalen);                 //~v0dbR~//~va50R~
//                memset(pcd,0,(UINT)keyindatalen);                  //~v0dbR~//~va50R~
//            }                                                      //~v0dbR~//~va50R~
      	if (inmerginsw)                                            //~va50M~
      	{                                                          //~va50M~
            memset(pc,CHAR_EBC_SPACE,(UINT)keyindatalen);          //~va50M~
            memset(pcd,0,(UINT)keyindatalen);                      //~va50M~
      		addlen=0;		//clear only,same ulhlen               //~va50M~
    	                                                           //~va50M~
		}                                                          //~va50M~
      	else                                                       //~va50M~
			addlen=-keyindatalen;                                  //~va50M~
    	Pplh->ULHlen+=addlen;                                      //~va50M~
        if (!optsbcs)                                              //~va50M~
//  		xeebc_setdbcstbl(0,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~va50M~//~va79R~
    		xeebc_setdbcstbl(0,handle,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~va79I~
		break;
//**********************                                           //~va50I~
//* ETOL ***************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPETOL:	//erase tof(top of line)                //~5102R~
	case CHAROPETOLCOB:	//erase tof(keep cob margin)                //~5102R~//~v74qI
        if (Pplh && Pmode==CHAROPETOLCOB                           //~v74sI
        &&  UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file     //~v42gI~//~v74qI
        	if (Pstartcol==0)                                      //~v74qR
            {                                                      //~v74AI
                if (Pcurcol>SPFCOBNUMFLDLEN)                       //~v74qI
		            Pstartcol=SPFCOBNUMFLDLEN;                           //~v42gI~//~v74qR
                else                                               //~v74qI
                if (Pcurcol==SPFCOBNUMFLDLEN)                      //~v74qI
                    return 0;                                      //~v74qI
                else                                               //~v74qI
                    return 4;                                      //~v74qI
            }                                                      //~v74AI
        if (protlen>Pstartcol)                                     //~v0ihI~
        	Pstartcol=protlen;   //dont clear prot line            //~v0ihI~
		if (Pcurcol<=Pstartcol)//startcol>0 when box cut        //~5506R~
			return 4;                                           //~4C25I~
        inmerginsw=0;                                              //~v0doI~
            if (oomprotsw)                                         //~v0eqI~
                if (Pcurcol>mergin)//clear before cursor           //~v618I~
		   			return errprotected();                         //~v417I~
	            if (merginsw)                                      //~v0doR~
                {                                                  //~v58RI~
    	            if (Pcurcol<=mergin && Pendcol>mergin)//data on out of mergin//~v618I~
                    {                                              //~v74cI
        	            inmerginsw=1;                              //~v0doR~
                        oomlen=Pendcol-mergin;                     //~v74cI
                    }                                              //~v74cI
                    else                                           //~v0doI~
	    	            if (Pcurcol>mergin && Pendcol>mergin)//data on out of mergin//~v0dpR~
                        {                                          //~v0dpI~
                            Ppcw->UCWreason=1;  //parm to func_erasetol_file//~v0dpI~
                            Pstartcol=mergin;	//up to mergin     //~v0doI~
                        }                                          //~v0dpI~
                }                                                  //~v58RI~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
        if (Pcurcol>Pendcol)                                       //~v0doR~
		{                                                       //~4C29I~
			Pcurcol=Pendcol;    	//all cut                   //~4C29I~
			pc=Pbuff+Pendcol;                                   //~4C29I~
			pcd=Pdbcs+Pendcol;                                  //~4C29I~
		}                                                       //~4C29I~
        if (Pstartcol>Pendcol)                                     //~v66gI~
            Pstartcol=Pendcol;                                     //~v66gI~
      if (inmerginsw)                                              //~v0doR~
      {                                                            //~v0dbI~
		addlen=0;                                                  //~v0dbI~
		len=mergin-Pcurcol;                                        //~v0dbI~
      }                                                            //~v0dbI~
      else                                                         //~v0dbI~
      {                                                            //~v0dbI~
		addlen=Pstartcol-Pcurcol;    	//all cut               //~4C29I~
		len=Pendcol-Pcurcol;                                    //~4C29I~
	  }	                                                           //~v0dbI~
//*left/right boundary tab/tbcs replace by space                //~5503I~
//          if (!vhexmode                                           //~v76AI//~va3SR~//~va50R~
//          &&  !(optorg & CFEO_VHEXLCMDS)   //split lcmd on vhex line//~va3SI~//~va50R~
//          )                                                        //~va3SI~//~va50R~
//          {                                                        //~v76AI//~va50R~
//            setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pstartcol,Pcurcol-Pstartcol);//~5503I~//~va50R~
//            if (inmerginsw)                                        //~v0doI~//~v74dI//~va50R~
//                setobtabdbcs(Pbuff,Pdbcs,Pendcol,mergin,0);//both side at the boundary//~v74dI//~va50R~
//          }//!vhex                                                 //~v76AI//~va50R~
			memcpy(Pbuff+Pstartcol,pc,(UINT)len);               //~5503I~
			memcpy(Pdbcs+Pstartcol,pcd,(UINT)len);              //~5503I~
            if (inmerginsw)                                        //~v0doI~
            {                                                      //~v0dbI~
//              memset(Pbuff+Pstartcol+len,' ',(UINT)(mergin-Pstartcol-len));//~v0dpR~//~va50R~
                memset(Pbuff+Pstartcol+len,CHAR_EBC_SPACE,(UINT)(mergin-Pstartcol-len));//~va50M~
                memset(Pdbcs+Pstartcol+len,0,(UINT)(mergin-Pstartcol-len));//~v0dpR~
            }                                                      //~v0dbI~
//            if (vhexmode && len>0)                                 //~v76AI//~va50R~
//            {                                                      //~v76AI//~va50R~
//#ifdef UTF8SUPPH                                                   //~va1cR~//~va50R~
//                if ((Pstartcol>0 && UDBCSCHK_DBCSNOTEND(*(Pdbcs+Pstartcol-1)))//prev is not dbcs last//~va1cR~//~va50R~
//                ||  (Pcurcol<Pendcol && UDBCSCHK_DBCSNOT1ST(*(Pdbcs+Pstartcol)))//current is not dbcs top//~va1cR~//~va50R~
//                ||  (inmerginsw && UDBCSCHK_DBCSNOT1ST(*(Pdbcs+mergin)))//margin line split dbcs//~va1cR~//~va50R~
//#else                                                              //~va1cR~//~va50R~
//                if ((Pstartcol>0 && *(Pdbcs+Pstartcol-1)==DBCS1STCHAR)//~v76AI//~va50R~
//                ||  (Pcurcol<Pendcol && *(Pdbcs+Pstartcol)==DBCS2NDCHAR)//~v76AR//~va50R~
//                ||  (inmerginsw && *(Pdbcs+mergin)==DBCS2NDCHAR)   //~v76AI//~va50R~
//#endif                                                             //~va1cR~//~va50R~
//                   )                                               //~v76AI//~va50R~
////*no vhexmode for utf8file                                        //~va20I~//~va50R~
//                    filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen+addlen,FSDT_TABSAVE);//~v76AI//~va50R~
//            }                                                      //~v76AI//~va50R~
//            pc=Pbuff+Pstartcol;                                 //~5126I~//~va50R~
//            pcd=Pdbcs+Pstartcol;                                //~5126I~//~va50R~
//            Pcurcol=0;//for later ULHlen set logic              //~v03kI~//~va50R~
		Pplh->ULHlen+=addlen;                                      //~va50M~
        if (!optsbcs)                                              //~va50M~
//  		xeebc_setdbcstbl(0,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~va50M~//~va79R~
    		xeebc_setdbcstbl(0,handle,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~va79I~
		break;                                                  //~4C25I~
//**********************                                           //~va50I~
//* CTOL ***************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPCTOL:	//clear tol(top of line)                //~5111I~
	case CHAROPCTOLIM:  //clear tol(ignore margin)                 //~v74eI
        if (protlen>Pstartcol)                                     //~v0ihR~
        	Pstartcol=protlen;   //dont clear prot line            //~v0ihR~
		if (Pcurcol<=Pstartcol)                                 //~5111I~
			return 4;                                           //~5111I~
        if (oomprotsw)                                             //~v0eqI~
            if (Pcurcol>=mergin)//clear before cursor              //~v0eqI~
    			return errprotected();                             //~v417I~
        if (Pmode!=CHAROPCTOLIM) //not ignore margin               //~v74eI
        {                                                          //~v74qI
                if (merginsw)                                      //~v0dwI~
                    if (Pcurcol>mergin && Pendcol>mergin)          //~v0dwI~
                        Pstartcol=mergin;   //clear from mergin    //~v0dwI~
        }                                                          //~v74qI
        else                                                       //~v74qI
        {                                                          //~v74qI
            if (UCBITCHK(pfh->UFHflag5,UFHF5COB))   //cob file     //~v42gI~//~v74qI
        		if (Pstartcol==0)                                  //~v74qI
                	if (Pcurcol>SPFCOBNUMFLDLEN)                   //~v74qI
		            	Pstartcol=SPFCOBNUMFLDLEN;                           //~v42gI~//~v74qI
        }                                                          //~v74qI
        if (Pcurcol>Pendcol)                                    //~5513M~
			Pcurcol=Pendcol;    	//all cut                   //~5513M~
		addlen=0;                                               //~5513M~
		len=Pcurcol-Pstartcol;                                  //~5513M~
			if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)//prepare undo and update process//~v04dR~
            	return UALLOC_FAILED;                           //~v04dI~
//      if (!vhexmode)                                               //~v76AI//~va50R~
//        setobtabdbcs(Pbuff,Pdbcs,Pendcol,Pstartcol,len);           //~v0c4I~//~va50R~
//        memset(Pbuff+Pstartcol,' ',(UINT)len);                  //~5111I~//~va50R~
		memset(Pbuff+Pstartcol,CHAR_EBC_SPACE,(UINT)len);          //~va50M~
		memset(Pdbcs+Pstartcol,0,(UINT)len);                    //~5111I~
//        if (vhexmode && len>0)                                     //~v76AI//~va50R~
//        {                                                          //~v76AI//~va50R~
//#ifdef UTF8SUPPH                                                   //~va1cR~//~va50R~
//            if ((Pstartcol>0 && UDBCSCHK_DBCSNOTEND(*(Pdbcs+Pstartcol-1)))//~va1cR~//~va50R~
//            ||  (Pcurcol<Pendcol && UDBCSCHK_DBCSNOT1ST(*(Pdbcs+Pcurcol)))//~va1cR~//~va50R~
//#else                                                              //~va1cR~//~va50R~
//            if ((Pstartcol>0 && *(Pdbcs+Pstartcol-1)==DBCS1STCHAR) //~v76AI//~va50R~
//            ||  (Pcurcol<Pendcol && *(Pdbcs+Pcurcol)==DBCS2NDCHAR) //~v76AI//~va50R~
//#endif                                                             //~va1cR~//~va50R~
//               )                                                   //~v76AI//~va50R~
////*no vhexmode for utf8file                                        //~va20I~//~va50R~
//                filesetdbcstbl(Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen,FSDT_TABSAVE);//~v76AI//~va50R~
//        }                                                          //~v76AI//~va50R~
        if (!optsbcs)                                              //~va50M~
//  		xeebc_setdbcstbl(0,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~va50M~//~va79R~
    		xeebc_setdbcstbl(0,handle,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~va79I~
		break;                                                  //~5111I~
//**********************                                           //~va50I~
//* MGET ***************                                           //~va50I~
//**********************                                           //~va50I~
	case CHAROPMGET:	//get block                             //~5125I~
		if (undoupdate(Ppcw,Pplh,UUHTREP)==UALLOC_FAILED)//prepare undo and update process//~v04dR~
        	return UALLOC_FAILED;                               //~v04dI~
        	                                                    //~v04dI~
//*erase tol                                                    //~5125I~
		if (Pendcol<=Pstartcol)		//block out of line         //~5125R~
			addlen=-Pendcol;    	//all cut                   //~5125I~
		else                                                    //~5125I~
        {                                                       //~5125I~
			addlen=-Pstartcol;    	//erase tol                 //~5125I~
 	    	if (Pcurcol>Pendcol)        //full line             //~5125R~
				len=Pendcol-Pstartcol;	                        //~5125I~
			else                                                //~5125I~
				len=Pcurcol-Pstartcol;	//over line             //~5125I~
			memcpy(Pbuff,Pbuff+Pstartcol,(UINT)len);            //~5125R~
			memcpy(Pdbcs,Pdbcs+Pstartcol,(UINT)len);            //~5125R~
		}                                                       //~5125I~
//*erase eol                                                    //~5125I~
		Pendcol+=addlen;			//new rec len               //~5125I~
		Pcurcol-=Pstartcol;			//block width               //~5125I~
		if (Pendcol<=Pcurcol)		//block contain full rec    //~5125I~
		{                                                       //~5125I~
//  		memset(Pbuff+Pendcol,' ',(UINT)(len=Pcurcol-Pendcol));//~5506R~//~va50R~
			memset(Pbuff+Pendcol,CHAR_EBC_SPACE,(UINT)(len=Pcurcol-Pendcol));//~va50M~
					//clear for cmd line etc                    //~5506I~
			memset(Pdbcs+Pendcol,0,(UINT)len);//capsave needs   //~v01bI~
			addlen+=len;                                        //~5125I~
		}                                                       //~5125I~
		else            			//over rec                  //~5125I~
			addlen-=(len=Pendcol-Pcurcol);	//cut len           //~5126R~
//        setdbcssplit(Pbuff,Pdbcs,Pcurcol,' ');//inner boundary dbcs//~5506R~//~va50R~
//        Pcurcol=0;//for later ULHlen set logic                  //~5126I~//~va50R~
        Pplh->ULHlen+=addlen;                                      //~va50M~
        if (!optsbcs)                                              //~va50M~
//  		xeebc_setdbcstbl(0,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~va50M~//~va79R~
    		xeebc_setdbcstbl(0,handle,Pplh->ULHdata,Pplh->ULHdbcs,Pplh->ULHlen);//~va79I~
		break;                                                  //~5125I~
	}//switch by mode

	scrclearconfirmmsg();	//clear confirmation msg
	return 0;
}//charfldeditebc                                                  //~va50R~
