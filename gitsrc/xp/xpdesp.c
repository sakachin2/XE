//*CID://+v9a0R~:                             update#=   89;       //~v9a0R~
//***********************************************************
//* XPRINT : file print utility                                    //~v801R~
//***********************************************************
//v9a0:160418 v9.33 LNX compiler warning                           //~v9a0I~
//v998:160404 v9.32 W64 compiler warning                           //~v998I~
//v97c:131029 chk pagerange of printdialog                         //~v97cI~
//v970:130922 GtkPrint for alternative of Gnomeprint               //~v970I~
//120629 v968 VC2010:LP64 support                                  //~v968R~
//100706 v950 v9.17 64bit compile                                  //~v950R~
//020719 v912 (BUG)despage wkfile is text mode,so EOF(0x1a) cut file for fgets.//~v912I~
//020718 v911 form2p support(ex a42,b4l2). /y2 max col is of a4,b4l2 max col is of b5//~v911I~
//010520 v908 :line feed required  for errmsg                      //~v908I~
//010519 v907 :LINUX support(work filename)                        //~v908I~
//010401 v904 :2 parts print suport for windows printer            //~v904I~
//            (no form parm for windows,auto pich calc by device info)//~v904I~
//981023 v859 :(BUG of v844)output should not to be open when _WIN //~v859I~
//981007 v855 :fistpage formfeed skip option(/Y1)+despage(/Yp) cause 1st page print//~v855I~
//             top of page by x0c miss because 1st page has no x0c //~v855I~
//981006 v850 :display printed pageno when ESC cancel              //~v850I~
//971124 v832 :split xpdesp from xprint                            //~v832I~
//***********************************************************      //~v765I~
#include <time.h>     //v1.1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    //v1.6add
#include <string.h>   //v1.3add
//*************************************************************
#ifdef DOS                           //v3.6a                    //~v743I~
#else                                //v3.6a                    //~v743I~
                                                                //~v743I~
  #ifdef W32                                                       //~v826I~
  #else                                                            //~v826I~
  #endif                                                           //~v826I~
                                                                //~v743I~
#endif                               //v3.6a                    //~v743I~
#ifdef UNX                                                         //~v970I~
    #include <unistd.h>                                            //~v970I~
#endif                                                             //~v970I~
                                                                //~v743I~
#include <ulib.h>	                                            //~v743M~
#include <ustring.h>                                               //~v768I~
#include <uerr.h>                                                  //~v801I~
#include <ufile.h>                                                 //~v807I~
#include <uproc.h>                                                 //~v970I~
#include <utrace.h>                                                //~v970I~
                                                                //~v743I~
//*********************************************************************
#include  "xp.h"                                                //~v74kI~
#include  "xpdesp.h"                                               //~v832I~
#include  "xppf.h"                                                 //~v832I~
#include  "xpsub1.h"                                               //~v850I~
#include  "xplnxp.h"                                               //~v970I~
//*********************************************************************//~v74kI~
       int  despageno=0;       //descending page print page no v5.3a//~v904I~
//*********************************************************************//~v904I~
extern int skip1stff;        //1st formfeed skip option,original   //~v855I~
extern int skip1stff2;       //value of skip1stff only for 1st page//~v855I~
extern int esccmdlen;          //esccmd lenngth     ..v2.9add v3.6rep//~v855I~
extern int  breakpage;         //in xppf.c,page no at ESC hit      //~v850I~
extern int  hdr0linesw;        //in xppf.c,req in header0 put      //~v855I~
extern int  despagesw;       //descending page print sw v5.3a      //~v832I~
extern int  despagecntsw;     //parm to escmsg                     //~v850I~
extern int  dbcsenv;           //dbcs environment sw v4.9a v7.23r  //~v832I~
extern char pgmid[];     //v7.1a v7.23r                            //~v832I~
extern char ver[]; 		    //v7.1a v7.23r                         //~v832I~
extern int Gtrailersw;   //parm to putline2p                       //~v911I~
extern int Gpage2p;    	//page count for form2p                    //~v911I~
extern int prntyp;	//printer type(default ibm5577/ibm5575 etc) av4.5 v6.7r//~v911I~
//**************************************************************** //~v832I~
extern char deswkfnpage[]; //page work file name v5.3a             //~v832I~
extern char deswkfnpos[]; //pos work file name v5.3a               //~v832I~
extern int  pagefsw; 				//page work file use sw v5.8a  //~v832I~
extern char *pagebufft,*pagebuffc;//page work buff v5.8a v7.0r     //~v832I~
extern FPOST *poswkbufft,*poswkbuffc;//position work buff v5.8av7.0r//~v832I~
extern int  poswkfsw;				//position work file use sw v5.8a//~v832I~
//**************************************************************** //~v832I~
static FILE *deswkfhpage=NULL; //page work file handle v5.3a       //~v832I~
static FILE *deswkfhpos=NULL; //pos work file handle v5.3a         //~v832I~
static int  Strailersw=0,Strailerlen=0;                            //~v911R~
#ifdef GTKPRINT                                                    //~v970I~
	typedef struct _GTKDH  //line header                           //~v970R~
    {                                                              //~v970I~
    	int GDHlen;             //big endian for -Mv -fF           //~v970R~
        int GDHrecid;                                              //~v970I~
	    #define RECID_OPENDOC      0x01                            //~v970I~
    	#define RECID_TEXTOUT      0x02                            //~v970I~
    	#define RECID_LINEOUT      0x03                            //~v970R~
    	#define RECID_CLOSEPAGE    0x04                            //~v970I~
    	#define RECID_DATA         0x0f  //for func parm only      //~v970R~
    } GTKDH,*PGTKDH;                                               //~v970I~
#pragma pack(push)                                                 //~v970I~
#pragma pack(1)                                                    //~v970I~
	typedef struct _GTKOD                                          //~v970I~
    {                                                              //~v970I~
    	int GODhmi;                                                //~v970I~
        int GODvmi;                                                //~v970I~
        char GODfnm[1];                                            //~v970R~
    } GTKOD,*PGTKOD;                                               //~v970I~
#pragma pack(pop)                                                  //~v970I~
#pragma pack(push)                                                 //~v970I~
#pragma pack(1)                                                    //~v970I~
	typedef struct _GTKTO	//textout                              //~v970I~
    {                                                              //~v970I~
    	int     GTOflag;                                           //~v970I~
    	double  GTOxx;                                             //~v970R~
    	double  GTOyy;                                             //~v970R~
        int     GTOlen;                                            //~v970I~
        char    GTOdata[1];                                        //~v970I~
    } GTKTO,*PGTKTO;                                               //~v970R~
#pragma pack(pop)                                                  //~v970I~
	typedef struct _GTKLO	//lineout                              //~v970I~
    {                                                              //~v970I~
    	double GLOxx1;                                             //~v970R~
    	double GLOyy1;                                             //~v970R~
    	double GLOxx2;                                             //~v970R~
    	double GLOyy2;                                             //~v970R~
    } GTKLO,*PGTKLO;                                               //~v970I~
    static char Sgtkdatafnm[_MAX_PATH];                            //~v970I~
    static int Sswgtkdatafnminit,Sgtkmaxlinelen,Sgtkreadlineno;    //~v970R~
    static FILE *Sgtkdatafh;                                       //~v970R~
	static int Sgtkbuffsz,Sgtkpagelineno;                          //~v970I~
	static char *Sgtkbuff;                                         //~v970I~
	static int Sfilepageno;                                        //~v97cI~
	static int Sswopendoc;                                         //~v97cI~
#endif //!GTKPRINT                                                 //~v970I~
#ifdef GTKPRINT                                                    //~v970I~
    void desp_gtkdatawrite(int Precid,void *Paddr,int Plen,int Pdatalen);//~v970R~
    void desp_gtkindexwrite();                                     //~v970I~
#endif //!GTKPRINT                                                 //~v970I~
//**********************************************************************
//* line write to page work file v5.3a
//**********************************************************************
void deswkfwrite(char *area,int len)
{
	FPOST pos;	//v7.0r
//  fpos_t getpospos;			//v7.0a                            //~v950R~
//  fpos_t *getposposp;			//v7.0a                            //~v950R~
	int wlen;
//*******************
//  getposposp=&getpospos;		//v7.0a                            //~v950R~
	if (!deswkfhpage)	//first time
	{
#ifdef UNX                                                         //~v908I~
#else                                                              //~v908I~
		if (deswkfnpage[strlen(deswkfnpage)-1]!=':')
#endif                                                             //~v908I~
//  		if (deswkfnpage[strlen(deswkfnpage)-1]!='\\')          //~v908R~
    		if (deswkfnpage[strlen(deswkfnpage)-1]!=DIR_SEPC)      //~v908I~
			{
//  			strcat(deswkfnpage,"\\");                          //~v908R~
    			strcat(deswkfnpage,DIR_SEPS);                      //~v908I~
//  			strcat(deswkfnpos,"\\");                           //~v908R~
    			strcat(deswkfnpos,DIR_SEPS);                       //~v908I~
			}
		strcat(deswkfnpage,WKFPAGE);	//file name with dir path
		strcat(deswkfnpos,WKFPOS);		//file name with dir path
#ifdef GTKPRINT                                                    //~v970I~
		strcpy(Sgtkdatafnm,deswkfnpage);	//file name with dir path//~v970I~
#endif //!GTKPRINT                                                 //~v970I~
//  	if (!(deswkfhpage=fopen(deswkfnpage,"w+")))                //~v912R~
    	if (!(deswkfhpage=fopen(deswkfnpage,"wb+")))               //~v912I~
		{
		  if (dbcsenv)	//DBCS mode
  			printf("\n%s:%s:頁降順出力用ワーク(%s)のオープン失敗\n",pgmid,ver,deswkfnpage);//~v908R~
		  else			//SBCS mode
  			printf("\n%s:%s:descendant page output work(%s) open failed\n",pgmid,ver,deswkfnpage);//~v908R~
          uexit(8);                                             //~v742R~
		}
		if (!(deswkfhpos=fopen(deswkfnpos,"wb+"))) //binary file
		{
		  if (dbcsenv)	//DBCS mode 
  			printf("\n%s:%s:頁降順出力用ワーク(%s)のオープン失敗\n",pgmid,ver,deswkfnpos);//~v908R~
		  else			//SBCS mode 
  			printf("\n%s:%s:descendant page output work(%s) open failed\n",pgmid,ver,deswkfnpos);//~v908R~
          uexit(8);                                             //~v742R~
		}
		
	}

//  if (area[0]==FORMFEED)		//top of page                      //~v855R~
    if (hdr0linesw)		//top of page                              //~v855I~
	{
    	if (!despageno)                                            //~v911I~
        	Strailersw=0;	//clear trailer write sw               //~v911I~
		despageno++;
		if (pagefsw)			//page work file use v5.8a
		{						//v7.0a
//			fgetpos(deswkfhpage,&pos);	//get current position on page filev7.0d
//			fgetpos(deswkfhpage,getposposp);	//get current position on page filev7.0a//~v950R~
//  		pos=*((FPOST*)(void*)getposposp);	//v7.0a            //~v950R~
//			pos=ftell(deswkfhpage);	//get current position on page filev7.0a//~v950R~//~v9a0R~
  			pos=(FPOST)ftell(deswkfhpage);	//get current position on page filev7.0a//~v9a0I~
		}						//v7.0a
		else					//page buff use v5.8a
//			pos=(LONG)pagebuffc;		//page top addr v5.8a v6.4r v7.0r//~v968R~
			pos=(ULPTR)pagebuffc;		//page top addr v5.8a v6.4r v7.0r//~v968R~
		if (poswkfsw)				//pos work on file v5.8a
		{							//v5.8a
			wlen=sizeof(pos);
			if ((int)fwrite(&pos,1,(UINT)wlen,deswkfhpos)!=wlen)	//write to position filev7.0r//~v826R~
			{
		  		if (dbcsenv)	//DBCS mode 
  					printf("\n%s:%s:頁降順出力用ワーク(%s) の出力エラー\n",pgmid,ver,deswkfnpos);//~v744R~
		  		else			//SBCS mode
  					printf("\n%s:%s:descendant page output work(%s) write failed\n",pgmid,ver,deswkfnpos);//~v744R~
          		uexit(8);                                       //~v742R~
			}
		}//v5.8a
		else	//v5.8a
			*poswkbuffc++=pos;	//v5.8a
	}
	if (pagefsw)			//page work file use v5.8a
	{//v5.8a
		if (len!=(int)fwrite(area,1,(UINT)len,deswkfhpage))	//write print line to page work v7.0r//~v826R~
		{
			if (dbcsenv)	//DBCS mode 
				printf("\n%s:%s:頁降順出力用ワーク(%s) の出力エラー\n",pgmid,ver,deswkfnpage);//~v744R~
	 		else			//SBCS mode
				printf("\n%s:%s:descendant page output work(%s) write failed\n",pgmid,ver,deswkfnpage);//~v744R~
       		uexit(8);                                           //~v742R~
		}
	}//v5.8a
	else					//page work buff use v5.8a
	{//v5.8a
		memcpy(pagebuffc,area,(UINT)len);		//save to buff v5.8a
		pagebuffc+=len;
	}//v5.8a
    Strailersw=0;   //clear trailer write sw                       //~v911I~
    if (Gtrailersw)		//triler write req                         //~v911I~
    {                                                              //~v911I~
      	Strailersw=1;	//clear trailer write sw                   //~v911I~
        Strailerlen=len;    //to avoid top \n of trailer confused prev line last \n//~v911I~
    }                                                              //~v911I~
//printf("despage save(len=%d)%.*s\n",len,40,area);                //~v912R~
  	return;
}//deswkfwrite
#ifdef GTKPRINT                                                    //~v970I~
//**********************************************************************
//* open work for gtk print                                        //~v970R~
//**********************************************************************
void desp_gtkopenwk()                                              //~v970R~
{
    int pid;                                                       //~v970I~
//*******************
	UTRACEP("desp_gtkopenwk\n");                                   //~v970R~
//	if (!deswkfhpage)	//first time                               //~v970R~
    if (!Sswgtkdatafnminit)                                        //~v970I~
	{
	    Sswgtkdatafnminit=1;                                       //~v970I~
    	pid=getpid();                                              //~v970I~
    	if (*Sgtkdatafnm)	//by despage option                    //~v970I~
        {                                                          //~v970I~
        	sprintf(Sgtkdatafnm,"%s%d",deswkfnpage,pid);           //~v970I~
        }                                                          //~v970I~
        else                                                       //~v970I~
        {                                                          //~v970I~
    		if (deswkfnpage[strlen(deswkfnpage)-1]!=DIR_SEPC)      //~v908I~
			{
//  			strcat(deswkfnpage,DIR_SEPS);                      //~v970R~
//  			strcat(deswkfnpos,DIR_SEPS);                       //~v970R~
        		sprintf(Sgtkdatafnm,"%s/%s%d",deswkfnpage,WKFPAGE,pid);//~v970I~
			}
            else                                                   //~v970I~
			{                                                      //~v970I~
        		sprintf(Sgtkdatafnm,"%s%s%d",deswkfnpage,WKFPAGE,pid);//~v970I~
			}                                                      //~v970I~
//  	strcat(deswkfnpage,WKFPAGE);	//file name with dir path  //~v970R~
//  	strcat(deswkfnpos,WKFPOS);		//file name with dir path  //~v970R~
        }                                                          //~v970I~
    }//filename init                                               //~v970I~
    UTRACEP("desp_gtkopenwk=%s\n",Sgtkdatafnm);                    //~v970R~
//  	if (!(deswkfhpage=fopen(deswkfnpage,"wb+")))               //~v970R~
    	if (!(Sgtkdatafh=fopen(Sgtkdatafnm,"wb+")))                //~v970I~
		{
			uerrexit("print work file(%s) openfailed",             //~v970I~
						"印刷用ワーク(%s)のオープン失敗",          //~v970I~
                        Sgtkdatafnm);                              //~v970I~
		}
}//desp_gtkopenwk                                                  //~v970I~
//**********************************************************************//~v970I~
//* write data to gtk work                                         //~v970I~
//**********************************************************************//~v970I~
void desp_gtkdatawrite(int Precid,void *Parea,int Plen,int Pdatalen)//~v970R~
{                                                                  //~v970R~
	int wlen,swerr,lrecl;                                          //~v970R~
    GTKDH gtkdh;                                                   //~v970I~
//**************************                                       //~v970I~
	UTRACEP("desp_gtkdatawrite recid=%d,len=%d\n",Precid,Plen);    //~v970I~
	swerr=0;                                                       //~v970I~
    if (Precid!=RECID_DATA)                                        //~v970I~
    {                                                              //~v970I~
//		lrecl=Plen+sizeof(GTKDH)+Pdatalen;                         //~v970R~//~v9a0R~
  		lrecl=Plen+(int)sizeof(GTKDH)+Pdatalen;                    //~v9a0I~
		UUL42BESTR(lrecl,(char*)(ULONG)(&(gtkdh.GDHlen)));	//ll:big endian//~v970R~
		gtkdh.GDHrecid=Precid;                                     //~v970R~
	    wlen=(int)fwrite(&gtkdh,1,sizeof(GTKDH),Sgtkdatafh);       //~v970R~
        UTRACED("gtkdatawrite hdr",&gtkdh,sizeof(GTKDH));          //~v970I~
	    if (wlen!=sizeof(GTKDH))                                   //~v970I~
        	swerr=1;                                               //~v970I~
    	if (lrecl>Sgtkmaxlinelen)                                  //~v970R~
	    	Sgtkmaxlinelen=lrecl;                                  //~v970R~
    }                                                              //~v970I~
    if (!swerr && Plen)                                            //~v970R~
    {//v5.8a                                                       //~v970R~
    	wlen=(int)fwrite(Parea,1,(UINT)Plen,Sgtkdatafh);	//write print line to page work v7.0r//~v970I~
        UTRACED("gtkdatawrite data",Parea,Plen);                   //~v970I~
    	if (wlen!=Plen)	//write print line to page work v7.0r      //~v970R~
        	swerr=1;                                               //~v970R~
    }//v5.8a                                                       //~v970R~
	if (swerr)                                                     //~v970I~
    	uerrexit("print work(%s):write failed",                    //~v970I~
                "印刷用ワーク(%s) の出力エラー",                   //~v970I~
                Sgtkdatafnm);                                      //~v970I~
}//desp_gtkdatawrite                                               //~v970R~
//**********************************************************************//~v970I~
//* read work data                                                 //~v970I~
//**********************************************************************//~v970I~
int desp_gtkdataread(int Ppageno,void **Pparea,int *Pplen)         //~v970R~
{                                                                  //~v970I~
	int rlen,swerr,lrecl=0,recid=0;                                //~v970R~
    GTKDH gtkdh;                                                   //~v970I~
//**************************                                       //~v970I~
	UTRACEP("desp_gtkdataread pageno=%d,line=%d\n",Ppageno,Sgtkpagelineno);//~v970R~
    rlen=(int)fread(&gtkdh,1,sizeof(gtkdh),Sgtkdatafh);            //~v970R~
	UTRACED("desp_gtkdataread hdrread",&gtkdh,rlen);               //~v970R~
	swerr=1;                                                       //~v970I~
    if (rlen==sizeof(GTKDH))                                       //~v970I~
    {                                                              //~v970I~
        UTRACED("gtkdataread data",&gtkdh,rlen);                   //~v970I~
	    recid=gtkdh.GDHrecid;                                      //~v970R~
//  	lrecl=UBESTR2UL4((char*)(ULONG)&(gtkdh.GDHlen))-sizeof(GTKDH);//~v970R~//~v9a0R~
    	lrecl=UBESTR2UL4((char*)(ULONG)&(gtkdh.GDHlen))-(int)sizeof(GTKDH);//~v9a0I~
    	if (lrecl>Sgtkbuffsz)                                      //~v970I~
        {                                                          //~v970I~
    		uerrexit("print work(%s):corruped at page=%d,line=%d",0,//~v970I~
                Sgtkdatafnm,Ppageno,Sgtkpagelineno);               //~v970I~
        }                                                          //~v970I~
        if (lrecl)                                                 //~v970I~
        {                                                          //~v970I~
    		rlen=(int)fread(Sgtkbuff,1,(UINT)lrecl,Sgtkdatafh);	//write print line to page work v7.0r//~v970R~
    		if (rlen==lrecl)	//write print line to page work v7.0r//~v970R~
            {                                                      //~v970I~
        		swerr=0;                                           //~v970R~
                UTRACED("gtkdataread data",Sgtkbuff,rlen);         //~v970I~
            }                                                      //~v970I~
        }                                                          //~v970I~
        else                                                       //~v970I~
        	swerr=0;                                               //~v970I~
    }//v5.8a                                                       //~v970I~
	if (swerr)                                                     //~v970I~
    	uerrexit("\nprint work(%s):read failed at page=%d,line=%d",0,//~v970R~
                Sgtkdatafnm,Ppageno+1,Sgtkpagelineno+1);           //~v970R~
    *Pparea=Sgtkbuff;                                              //~v970I~
    if (Pplen)                                                     //~v970I~
    	*Pplen=lrecl;                                              //~v970I~
    return recid;                                                  //~v970I~
}//desp_gtkdataread                                                //~v970I~
#endif //!GTKPRINT                                                 //~v970I~

//**********************************************************************
//* write to output from page work file by page descending order v5.3a
//* parm1:option,0:last close rec,1:write to despwork              //~v859I~
//* parm2:output file handle                                       //~v859I~
//**********************************************************************
void despageout(int Popt,FILE *output)                             //~v859R~
{
	int i;
	int len;
	int len2,len3;                                                 //~v855I~
	FPOST pos,pagetop,lastpos;	//v7.0r
    FPOST evenpagetop=0,evenpagelast=0,eofpos;                     //~v911R~
//  fpos_t getpospos;			//v7.0a                            //~v950R~
//  fpos_t *getposposp;			//v7.0a                            //~v950R~
	char buff[MAXLINEWIDTH];
    char *pc;                                                      //~v855I~
    int hdrskiplen;                                                //~v855I~
    int pageupsw=-1,cpageno;                                       //~v911R~
    int loop2p,sw2p;                                               //~v911R~
    int rc2;                                                       //+v9a0I~
//*********************
//printf("despage out\n");                                         //~v850R~
    breakpage=0;                                                   //~v850M~
    despagecntsw=1;         //parm to escmsg                       //~v850R~
//  getposposp=&getpospos;		//v7.0a                            //~v950R~
//	if (!output)	//last zero size req                           //~v859R~
  	if (!Popt)		//last zero size req                           //~v859I~
	{
		fclose(deswkfhpage);
       	remove(deswkfnpage); //del work file av5.4

		fclose(deswkfhpos);
       	remove(deswkfnpos); //del work file av5.4

		return;
	}
//*desecnding print from page worku
	if (pagefsw)			//page work file use v5.8a
	{						//v7.0a
//		fgetpos(deswkfhpage,&lastpos);	//save last positionv7.0d
//  	fgetpos(deswkfhpage,getposposp);	//get current position on page filev7.0a//~v950R~
//  	lastpos=*((FPOST*)(void*)getposposp);	//v7.0a            //~v950R~
//  	lastpos=ftell(deswkfhpage);	//get current position on page filev7.0a//~v950R~//~v9a0R~
    	lastpos=(FPOST)ftell(deswkfhpage);	//get current position on page filev7.0a//~v9a0I~
	}						//v7.0a
	else					//page buff use v5.8a
//		lastpos=(LONG)pagebuffc;		//page top addr v5.8a v6.4r v7.0r//~v968R~
		lastpos=(ULPTR)pagebuffc;		//page top addr v5.8a v6.4r v7.0r//~v968R~
    eofpos=lastpos;                                                //~v911I~
	if (poswkfsw)			//v5.8a pos work file use
		fseek(deswkfhpos,(FPOST)0,SEEK_SET);	//bposition to top	//v7.0r

	skip1stff2=skip1stff;                                          //~v855I~
    cpageno=despageno+1; //count 2/form                           //v1.1add//~v911R~
	sw2p=UCBITCHK(swsw3,SW3FORM2P) 	//form 2p                      //~v911I~
  		 || (UCBITCHK(swsw3,SW3WIN2P) && prntyp!=PRINTER_WIN); //putline2p call case//~v911I~
	for (i=despageno;i>0;i--)	//all page
	{
//  	breakchk(1);			//chk esc hit already              //~v911R~
    	cpageno--;    	//count 2/form                           //v1.1add//~v911R~
	  	if (sw2p)                                                  //~v911I~
    		pageupsw=cpageno%2; 	//1up/form                     //~v911R~
      if (pageupsw)                                                //~v911I~
      {                                                            //~v911I~
    	breakchk(1);			//chk esc hit already              //~v911I~
        breakpage++;			//page count                       //~v850I~
      }                                                            //~v911I~
		if (poswkfsw)			//v5.8a pos work file use
		{						//v5.8a 
//  		fseek(deswkfhpos,(FPOST)(sizeof(pos)*(i-1)),SEEK_SET);	//pos file posv7.0r//~v9a0R~
    		fseek(deswkfhpos,(long)(sizeof(pos)*((size_t)i-1)),SEEK_SET);	//pos file posv7.0r//~v9a0R~
          rc2=(int)                                                //+v9a0I~
			fread(&pos,sizeof(pos),1,deswkfhpos); //page file page top position
          rc2=rc2;                                                 //+v9a0I~
		}//v5.8a
		else					//pos work buff use v5.8a
			pos=*(--poswkbuffc);	//from buff			v5.8a
		pagetop=pos;
        if (!pageupsw)		//even page of 2p                      //~v911I~
        {                                                          //~v911I~
        	evenpagetop=pagetop;	//save to loop2p change        //~v911I~
        	continue;			//do after oddpage                 //~v911I~
        }                                                          //~v911I~
		if (pagefsw)			//page work file use v5.8a
//  		fseek(deswkfhpage,pagetop,SEEK_SET);	//position to page top//~v998R~
    		fseek(deswkfhpage,(long)pagetop,SEEK_SET);	//position to page top//~v998I~
		else					//page buff use v5.8a
			pagebuffc=(char *)pagetop;		//page top addr v5.8a
        if (evenpagetop)                                           //~v911I~
        {                                                          //~v911I~
            evenpagelast=lastpos;                                  //~v911I~
            lastpos=evenpagetop;                                   //~v911I~
        }                                                          //~v911I~
     for (loop2p=0;loop2p<2;loop2p++)                              //~v911I~
     {                                                             //~v911I~
     	Gpage2p=cpageno+loop2p; //left is odd,right is even        //~v911R~
		hdr0linesw=1;	    	//parm to ufwrte,deswkfwrite,new page timing//~v855I~
        hdrskiplen=1-skip1stff2+esccmdlen;                         //~v855I~
		do
		{
//			breakchk();					//v6.7d
			if (pagefsw)			//page work file use v5.8a
			{//v5.8a
				if (!fgets(buff,sizeof(buff),deswkfhpage))	//null return if error or eof r940527
					break;
				for (len=0;;len++)	//search end of line (for esc cmd contain null)
				{
					len+=(INT)strlen(buff+len);	//v7.0r
					if (buff[len-1]==CRLF)
						break;
				}
			}//v5.8a
			else					//page buff use v5.8a
			{//v5.8a
//				len=(int)min(lastpos-(ULONG)pagebuffc,sizeof(buff));//1 line copy v5.8a v6.4rv7.0r//~v968R~
				len=(int)min(lastpos-(ULPTR)pagebuffc,sizeof(buff));//1 line copy v5.8a v6.4rv7.0r//~v968R~
	           if (!Strailersw || len>Strailerlen) //triler line top \n//~v911I~
                if (len>hdrskiplen)                                //~v855I~
                {                                                  //~v855I~
	                pc=memchr(pagebuffc+hdrskiplen,'\n',(UINT)(len-hdrskiplen));//~v855I~
                	if (pc)                                        //~v855I~
                    {                                              //~v855I~
//		               	len3=(int)((ULONG)pc-(ULONG)pagebuffc);//len up to \n//~v855R~//~v968R~
		               	len3=(int)((ULPTR)pc-(ULPTR)pagebuffc);//len up to \n//~v968R~
                        len2=len-len3;	//residual                 //~v855I~
                        len=len3;                                  //~v855I~
                        while(len2 && *pc=='\n')                   //~v855I~
                        {                                          //~v855I~
                        	pc++;                                  //~v855I~
                            len2--;                                //~v855I~
                            len++;                                 //~v855I~
	           				if (Strailersw && len2<=Strailerlen) //triler line top \n//~v911R~
                            	break;                             //~v911I~
                        }                                          //~v855I~
                    }                                              //~v855I~
				}                                                  //~v855I~
				memcpy(buff,pagebuffc,(UINT)len);//1 line copy v5.8a v7.0r
				pagebuffc+=len;				//next 1 line v5.8a
			}//v5.8a
			if (pagefsw)			//page work file use v5.8a     //~v911I~
			{						//v7.0a                        //~v911I~
//  			fgetpos(deswkfhpage,getposposp);	//get current position on page filev7.0a//~v911I~//~v950R~
//  			pos=*((FPOST*)(void*)getposposp);	//v7.0a        //~v911I~//~v950R~
    			pos=(FPOST)ftell(deswkfhpage);	//get current position on page filev7.0a//~v950R~//~v9a0R~
			}						//v7.0a                        //~v911I~
			else					//page buff use v5.8a          //~v911I~
//  			pos+=len;//next line v5.8a                         //~v911I~//~v9a0R~
    			pos+=(FPOST)len;//next line v5.8a                  //~v9a0I~
            if (pos>=eofpos)	//last line                        //~v911R~
			  	if (sw2p)                                          //~v911R~
		            if (Strailersw)	//trailer written              //~v911R~
	  					Gtrailersw=1;   //parm to putline2p        //~v911I~
			despagesw=0;		//force write to output
//  		pline(buff,1,len,output);                              //~v855R~
    		pline(buff+skip1stff2,1,len-skip1stff2,output);        //~v855I~
    		Gtrailersw=0;                                          //~v911I~
			despagesw=1;		//recov descending write
			hdr0linesw=0;	    	//only 1st line,parm to ufwrte,deswkfwrite,new page timing//~v855I~
            skip1stff2=0;           //for 1st put page(pageno=last) only//~v855I~
            hdrskiplen=0;			//for only 1st line            //~v855I~
//            if (pagefsw)            //page work file use v5.8a   //~v911R~
//            {                       //v7.0a                      //~v911R~
////              fgetpos(deswkfhpage,&pos);  //save last position v7.0d//~v911R~
//                fgetpos(deswkfhpage,getposposp);    //get current position on page filev7.0a//~v911R~
//                pos=*((FPOST*)(void*)getposposp);   //v7.0a      //~v911R~
//            }                       //v7.0a                      //~v911R~
//            else                    //page buff use v5.8a        //~v911R~
//                pos+=len;//next line v5.8a                       //~v911R~
		} while(pos<lastpos);
	  	if (!evenpagetop)			//not 2p                       //~v911I~
        	break;                                                 //~v911I~
        lastpos=evenpagelast;                                      //~v911I~
      }//loop2p                                                    //~v911I~

		lastpos=pagetop;	//previous page end pos
	}

	despageno=0;
	fseek(deswkfhpage,(FPOST)0,SEEK_SET);	//position to topv7.0r
	fseek(deswkfhpos,(FPOST)0,SEEK_SET);	//position to topv7.0r
  	return;
}//despageout
#ifdef GTKPRINT
//**********************************************************************//~v970I~
void desp_gtkflush_opendoc(PGTKOD Ppgtkod)                         //~v970R~
{                                                                  //~v970I~
    int vmi,hmi;                                                   //~v970I~
    char *fnm;                                                     //~v970I~
//**********************************                               //~v970I~
    hmi=Ppgtkod->GODhmi;                                           //~v970R~
    vmi=Ppgtkod->GODvmi;                                           //~v970R~
    fnm=Ppgtkod->GODfnm;                                           //~v970R~
    lnx_opendoc2printer(hmi,vmi,fnm);                              //~v970R~
    lnx_newpage_flush();  //color                                  //~v970I~
    Sswopendoc=1;                                                  //~v97cI~
}//desp_gtkflush_opendoc                                           //~v970I~
//**********************************************************************
//* from drawpage callback                                         //~v970R~
//* write to output from page work file                            //~v970I~
//**********************************************************************
void desp_gtkflushpage(int Ppageno)                                //~v970R~
{
	PGTKOD pgtkod;                                                 //~v970I~
	PGTKTO pgtkto;                                                 //~v970I~
	PGTKLO pgtklo;                                                 //~v970I~
    void *prec;                                                    //~v970I~
    char *putf8;                                                   //~v970R~
    int lrecl,recid,len;                                           //~v970R~
    double xx,yy,xx2,yy2;                                          //~v970R~
//*********************
	UTRACEP("desp_gtk_flushpage page=%d,Sfilepageno=%d\n",Ppageno,Sfilepageno);   //~v970R~//~v97cR~
//   if (Ppageno)   	//not 1st page;for 1st page, newpage from opendoc//~v970I~//~v97cR~
     if (Sfilepageno==Ppageno && Sswopendoc)   	//pageno dose not always start by 0 if used dilog pagerange//~v97cI~
	    lnx_newpage_flush();  //color                              //~v970R~
    Sgtkpagelineno=0;                                              //~v970R~
    for (;;)                                                       //~v970R~
    {                                                              //~v970I~
		recid=desp_gtkdataread(Ppageno,&prec,&lrecl);              //~v970I~
        if (recid==RECID_CLOSEPAGE)                                //~v970I~
        {                                                          //~v97cI~
          if (Sfilepageno==Ppageno)                                //~v97cI~
          {                                                        //~v97cI~
		    Sfilepageno++;	//not same as Ppageno if pagerange used by gtkdialog//~v97cI~
        	break;                                                 //~v970I~
          }                                                        //~v97cI~
          else                                                     //~v97cI~
		    Sfilepageno++;	//not same as Ppageno if pagerange used by gtkdialog//~v97cI~
        }                                                          //~v97cI~
        switch(recid)                                              //~v970I~
        {                                                          //~v970I~
        case RECID_OPENDOC:                                        //~v970I~
        	pgtkod=(PGTKOD)prec;                                   //~v970I~
			desp_gtkflush_opendoc(pgtkod);                         //~v970R~
            break;                                                 //~v970I~
        case RECID_TEXTOUT:                                        //~v970I~
          	if (Sfilepageno!=Ppageno)                              //~v97cI~
            	break;                                             //~v97cI~
        	pgtkto=(PGTKTO)prec;                                   //~v970I~
            xx=pgtkto->GTOxx;                                      //~v970R~
            yy=pgtkto->GTOyy;                                      //~v970R~
            len=pgtkto->GTOlen;                                    //~v970R~
            putf8=pgtkto->GTOdata;                                 //~v970R~
			lnx_textout2printer(pgtkto->GTOflag,xx,yy,putf8,len);  //~v970R~
	    	Sgtkpagelineno++;                                      //~v970R~
            break;                                                 //~v970I~
        case RECID_LINEOUT:                                        //~v970I~
          	if (Sfilepageno!=Ppageno)                              //~v97cI~
            	break;                                             //~v97cI~
        	pgtklo=(PGTKLO)prec;                                   //~v970R~
            xx=pgtklo->GLOxx1;                                     //~v970R~
            yy=pgtklo->GLOyy1;                                     //~v970R~
            xx2=pgtklo->GLOxx2;                                    //~v970R~
            yy2=pgtklo->GLOyy2;                                    //~v970R~
			lnx_lineout2printer(xx,yy,xx2,yy2);                    //~v970R~
        }                                                          //~v970I~
    }                                                              //~v970I~
}//desp_gtkflushpage                                               //~v970R~
#endif //!GTKPRINT
#ifdef GTKPRINT                                                    //~v970I~
//==================================================================//~v970I~
//=from lxn_opendoc at phase2                                      //~v970I~
//==================================================================//~v970I~
void desp_gtkopendoc(int Phmi,int Pvmi,char *Pdocname)             //~v970I~
{                                                                  //~v970I~
    PGTKOD pgtkod;                                                 //~v970R~
    char docdata[_MAX_PATH+sizeof(GTKOD)];                         //~v970I~
    int len;                                                       //~v970I~
//*******************                                              //~v970I~
	UTRACEP("desp_gtkopndoc,docname=%s,hmi=%d,vmi=%d\n",Pdocname,Phmi,Pvmi);//~v970R~
    desp_gtkopenwk();                                              //~v970R~
    Sgtkmaxlinelen=0;                                              //~v970I~
    pgtkod=(PGTKOD)(ULPTR)docdata;                                 //~v970I~
    pgtkod->GODhmi=Phmi;                                           //~v970R~
    pgtkod->GODvmi=Pvmi;                                           //~v970R~
    strcpy(pgtkod->GODfnm,Pdocname);                               //~v970I~
//  len=sizeof(GTKOD)+strlen(Pdocname);                            //~v970R~//~v9a0R~
    len=(int)(sizeof(GTKOD)+strlen(Pdocname));                     //~v9a0I~
	UTRACEP("desp_gtkopndoc,sizeofGtkod=%d\n",sizeof(GTKOD));      //~v970I~
    desp_gtkdatawrite(RECID_OPENDOC,pgtkod,len,0/*datalen*/);      //~v970R~
}//desp_gtkopendoc                                                 //~v970I~
//==================================================================//~v970I~
//=from end_print callback                                         //~v970R~
//==================================================================//~v970I~
void desp_gtkclosedoc()                                            //~v970I~
{                                                                  //~v970I~
//*******************                                              //~v970I~
	UTRACEP("desp_gtkclosedoc\n");                                 //~v970I~
    if (Sgtkdatafh)                                                //~v970I~
    {                                                              //~v970I~
		fclose(Sgtkdatafh);                                        //~v970I~
        Sgtkdatafh=NULL;                                           //~v970R~
       	remove(Sgtkdatafnm);                                       //~v970I~
    }                                                              //~v970I~
}//desp_gtkclosedoc                                                //~v970I~
//==================================================================//~v970I~
//=from lnx_textout at phase2                                      //~v970R~
//==================================================================//~v970I~
void desp_gtktextout(int Pflag,double Pxx,double Pyy,char *Pbuff,int Plen)//~v970R~
{                                                                  //~v970I~
	GTKTO gtkpo;                                                   //~v970I~
//*******************                                              //~v970I~
	UTRACEP("desp_gtktextout flag=%x,xx=%lf,yy=%lf,len=%d\n",Pflag,Pxx,Pyy,Plen);//~v970R~
    gtkpo.GTOflag=Pflag;                                           //~v970I~
    gtkpo.GTOxx=Pxx;                                               //~v970I~
    gtkpo.GTOyy=Pyy;                                               //~v970I~
    gtkpo.GTOlen=Plen;                                             //~v970I~
    desp_gtkdatawrite(RECID_TEXTOUT,&gtkpo,sizeof(gtkpo)-sizeof(gtkpo.GTOdata),Plen);//~v970R~
    desp_gtkdatawrite(RECID_DATA,Pbuff,Plen,0/*add len*/);         //~v970R~
}//desp_gtkputline                                                 //~v970I~
//==================================================================//~v970I~
//=from lnx_lineout at phase2                                      //~v970I~
//==================================================================//~v970I~
void desp_gtklineout(double Pxx1,double Pyy1,double Pxx2,double Pyy2)//~v970I~
{                                                                  //~v970I~
	GTKLO gtklo;                                                   //~v970I~
//*******************                                              //~v970I~
	UTRACEP("desp_gtklineout xx1=%lf,yy1=%lf,xx2=%lf,yy2=%lf",Pxx1,Pyy1,Pxx2,Pyy2);//~v970I~
    gtklo.GLOxx1=Pxx1;                                             //~v970R~
    gtklo.GLOyy1=Pyy1;                                             //~v970R~
    gtklo.GLOxx2=Pxx2;                                             //~v970R~
    gtklo.GLOyy2=Pyy2;                                             //~v970R~
    desp_gtkdatawrite(RECID_LINEOUT,&gtklo,sizeof(gtklo),0/*addln*/);//~v970I~
}//desp_gtkputline                                                 //~v970I~
//==================================================================//~v970I~
//=from lnx_putline at phase2                                      //~v970I~
//==================================================================//~v970I~
void desp_gtknewpage()                                             //~v970I~
{                                                                  //~v970I~
//*******************                                              //~v970I~
	UTRACEP("desp_gtknewpage\n");                                  //~v970I~
}//desp_gtknewpage                                                 //~v970I~
//==================================================================//~v970I~
//=from lnx_closepage at phase2                                    //~v970I~
//==================================================================//~v970I~
void desp_gtkclosepage()                                           //~v970I~
{                                                                  //~v970I~
//*******************                                              //~v970I~
	UTRACEP("desp_gtkclosepage\n");                                //~v970I~
    desp_gtkdatawrite(RECID_CLOSEPAGE,"",0,0);                     //~v970R~
}//desp_gtkclosepage                                               //~v970R~
//==================================================================//~v970I~
//=from begin_print callback                                       //~v970I~
//==================================================================//~v970I~
void desp_gtkbeginprint(int Ppageno)                               //~v970I~
{                                                                  //~v970I~
	UTRACEP("desp_gtkbeginprint\n");                               //~v970I~
	fseek(Sgtkdatafh,(FPOST)0,SEEK_SET);	                       //~v970I~
    if (Sgtkbuff)                                                  //~v970I~
    	free(Sgtkbuff);                                            //~v970R~
	Sgtkreadlineno=0;                                              //~v970I~
    Sfilepageno=0;                                                 //~v97cI~
    Sswopendoc=0;                                                  //~v97cI~
    Sgtkbuffsz=Sgtkmaxlinelen;                                     //~v970R~
//  Sgtkbuff=malloc(Sgtkbuffsz);                                   //~v970I~//~v9a0R~
    Sgtkbuff=malloc((size_t)Sgtkbuffsz);                           //~v9a0I~
}//desp_gtkbeginprint                                              //~v970R~
//==================================================================//~v970I~
//=from draw_page callback                                         //~v970I~
//==================================================================//~v970I~
void desp_gtkdrawpage(int Ppageno)                                 //~v970I~
{                                                                  //~v970I~
//*******************                                              //~v970I~
	desp_gtkflushpage(Ppageno);                                    //~v970R~
}//desp_gtkdrawpage                                                //~v970I~
#endif //!GTKPRINT                                                 //~v970I~
