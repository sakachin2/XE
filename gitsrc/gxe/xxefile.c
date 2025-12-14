//CID://+vbu0R~:     update#=     47                               //~vbu0R~
//******************************************************************************//~v003I~
//vbu0:201217 Debian10 compiler warning                            //~vbu0I~
//vbdm:171125 (gxe)append "NewFile" for menu:File/New when directory is selected//~vbdmR~
//vbdk:171125 GTK2 GtkFileSelection was dprecated,GtkFileChooser is available from v2.4//~vb7kI~
//vb7v:170128 (gxe:GTK3 BUG)DragDrop hung                          //~vb7vI~
//var8:140127 gtk3 suppott                                         //~var8I~
//vam0:130911 for distro removed gnome-print,use GTKprint          //~vam0I~
//vaf6:120604 (XXE) fildialog(gtkfileselection) display previous selection directory//~vaf6I~
//v76j:070626 (WXEXXE)dnd by paste to utility panel                //~v76jI~
//v76g:070620 utility panel(3.14:grep and 3.12:compare);f5:open dirlist, dlcmd "^":send//~v76gI~
//v68i:060331 (WXEXXE)activate window when dropped                 //~v68iI~
//v686:060323 dnd support by paste(edit:pastev,ins=paste-ins,rep=paste-rep)//~v686I~
//v685:060322 dnd support "file copy into the dir slected" and even in inter-split-screen.//~v685I~
//v63k:050509 (WXE)change mouse csr when dragout in progress       //~v63kI~
//v63h:050504 (WXE)support DragOut                                 //~v63gI~
//v63g:050504 (WXE)DrgFinish required to avoid memory leak         //~v63gI~
//******************************************************************************//~v003I~
//******************************************************************************//~v003I~
#include <stdlib.h>                                                //~var8R~
#include <string.h>                                                //~var8R~
#include <ctype.h>                                                 //~var8R~
#ifndef OPTGTK3                                                    //~var8R~
#include <gnome.h>                                                 //~vXXEI~
#else                                                              //~var8R~
#include <gtk/gtk.h>                                               //~var8R~
#include <gdk/gdkx.h>                                              //~var8R~
#endif                                                             //~var8R~
#ifndef NOPRINT                                                    //~vam0R~
	#ifdef GTKPRINT                                                //~vam0I~
	#else    //!GTKPRINT                                           //~vam0I~
#include <libgnomeprint/gnome-print.h>                             //~vXXEI~
#include <libgnomeprint/gnome-print-job.h>                         //~vXXEI~
	#endif   //!GTKPRINT                                           //~vam0I~
#endif                                                             //~vam0I~
//******************************************************************************//~v003I~
//#include <gnome.h>                                                 //~vXXEI~//~vam0R~
//#include <libgnomeprint/gnome-print.h>                             //~vXXEI~//~vam0R~
//#include <libgnomeprint/gnome-print-job.h>                         //~vXXEI~//~vam0R~
                                                                   //~vXXEI~
#include "callbacks.h"                                             //~vXXEI~
#include "interface.h"                                             //~vXXEI~
#include "support.h"                                               //~vXXEI~
                                                                   //~vXXEI~
#include <ulib.h>                                                  //~vXXEI~
#include <uedit.h>                                                 //~vXXEI~
#include <ustring.h>                                               //~vaf6R~
#include <utrace.h>                                                //~var8I~
#include <ufile.h>                                                 //~vbdmR~
                                                                   //~vXXER~
#include    "gxe.h"                                                //~var8R~
#include    "xxedef.h"                                             //~vXXEI~
#include    "xxefile.h"                                            //~vXXEI~
#include    "xxexei.h"                                             //~vXXEI~
#include    "xxemain.h"                                            //~vXXEI~
#include    "xxecsub.h"                                            //~vXXEI~
#include    "gxedlg.h"                                             //~vXXEI~
#include    "xxeres.h"                                             //~vXXEI~
//#include    "gxe.h"                                              //~var8R~
                                                                   //~vXXEI~
                                                                   //~v63gI~
//*******************************************************************//~vXXEI~
#define FILEDLG_OPEN    1                                          //~vXXEI~
#define FILEDLG_NEW     2                                          //~vXXEI~
#define FILEDLG_SAVEAS  3                                          //~vXXEI~
//*******************************************************************//~vXXEI~
static    GtkWidget *Sfiledlg;                                     //~vXXEI~
static    int       Sdlgmode;	//open.new,saveas                  //~vXXEI~
//static    int       Src_new=0;  //New dialog return rc=new       //~vbdmR~
//*******************************************************************//~vXXEI~
int  xxefile_filesave(char *Pfilename);                            //~vXXER~
int  xxefile_fileopen(char *Pfilename);                            //~vXXER~
int  xxefile_filenew(char *Pfnm);                                  //~vXXER~
void invalidate(void);                                             //~v685I~
void dlgcreate(GtkMenuItem *Pmenuitem,int Poptnew);                //~vXXER~
//*******************************************************************//~vXXEM~
//*wxedoc ***********************************************************//~vXXEM~
//*******************************************************************//~vXXEM~
void gxedoc_construct(void)                                        //~vXXEM~
{                                                                  //~vXXEM~
//    Mcmdid=0;                                                    //~vXXEM~
//    Mpview=0;                                                    //~vXXEM~
//    Mpapp=(CWxeApp*)AfxGetApp();                                 //~vXXEM~
//    Mwxefile.init(this);                                         //~vXXEM~
}                                                                  //~vXXEM~
void gxedoc_init(void)                                             //~vXXEM~
{                                                                  //~vXXEM~
//    Mpview=Ppview;                                               //~vXXEM~
}                                                                  //~vXXEM~
                                                                   //~vXXEM~
void gxedoc_destroy(void)                                          //~vXXEM~
{                                                                  //~vXXEM~
}                                                                  //~vXXEM~
void gxedoc_Serialize(void)                                        //~vXXEM~
{                                                                  //~vXXEM~
}                                                                  //~vXXEM~
void gxedoc_OnNewDocument 	           (GtkMenuItem     *menuitem, //~vXXEM~
                                        gpointer         user_data)//~vXXEM~
{                                                                  //~vXXEM~
	 dprintf("on_new_activate  \n");                                //~vXXER~
	dlgcreate(menuitem,FILEDLG_NEW);	//1:new                    //~vXXER~
    return;                                                        //~vXXEM~
}                                                                  //~vXXEM~
void gxedoc_OnOpenDocument             (GtkMenuItem     *menuitem, //~vXXER~
                                        gpointer         user_data)//~vXXEI~
{                                                                  //~vXXEM~
//*************************                                        //~vXXEM~
	 dprintf("on_open_activate  \n");                               //~vXXER~
    if (!menuitem)                                                 //~vXXEI~
    {                                                              //~vXXEI~
		uactivate_menuitem(STRID_FILE_OPEN);	//to get menuitem  //~vXXEI~
    	return;                                                    //~vXXEI~
    }                                                              //~vXXEI~
	dlgcreate(menuitem,FILEDLG_OPEN);                              //~vXXER~
    return;                                                        //~vXXEI~
}                                                                  //~vXXEM~
                                                                   //~vXXEM~
void gxedoc_OnSaveDocument(void)                                   //~vXXEM~
{                                                                  //~vXXEM~
	 dprintf("on_save_activate  \n");                               //~vXXER~
//    UTRACEP("Mcmdid %0x\n",Mcmdid);                              //~vXXEM~
//    if (Mcmdid==ID_FILE_SAVE_AS)                                 //~vXXEM~
//        Mwxefile.filesave(lpszPathName);                         //~vXXEM~
//    else                                                         //~vXXEM~
          xxefile_filesave("");      //no filename                 //~vXXER~
////  return CDocument::OnSaveDocument(lpszPathName);              //~vXXEM~
      return;                                                      //~vXXER~
}                                                                  //~vXXEM~
void gxedoc_OnSaveAsDocument            (GtkMenuItem     *menuitem,//~vXXEM~
                                        gpointer         user_data)//~vXXEM~
{                                                                  //~vXXEM~
	 dprintf("on_saveas_ctivate  \n");                              //~vXXER~
	dlgcreate(menuitem,FILEDLG_SAVEAS);                            //~vXXER~
    return;                                                        //~vXXEM~
}                                                                  //~vXXEM~
int gxedoc_OnCmdMsg(void)                                          //~vXXEM~
{                                                                  //~vXXEM~
//    UTRACEP("OnCmdMsg nID=%x,nCode=%d\n",nID,nCode);             //~vXXEM~
//    Mcmdid=nID;     //for distinguish save and save as           //~vXXEM~
//    int rc=CDocument::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);//~vXXEM~
////  int rc2=CommDlgExtendedError();                              //~vXXEM~
//    return rc;                                                   //~vXXEM~
    return 0;                                                      //~vXXEM~
}                                                                  //~vXXEM~
int  gxedoc_ondropfiles(void)                                      //~vXXEM~
{                                                                  //~vXXEM~
//    return                                                       //~vXXEM~
//    Mwxefile.ondropfiles(hDropInfo);                             //~vXXEM~
////  return;                                                      //~vXXEM~
    return 0;                                                      //~vXXEM~
}                                                                  //~vXXEM~
#ifndef XXE                                                        //~vXXEI~
//==============================================================================//~v003I~
//                                                                 //~v003I~
//==============================================================================//~v003I~
extern  "C"                                                        //~v003I~
{                                                                  //~v003I~
}                                                                  //~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
//CWxefile::CWxefile()                                             //~vXXER~
//{                                                                //~vXXER~
//    Mxeinitsw=0;    //xeinit sw                                  //~vXXER~
////  Mswdndinprogress=0;    //dodrag in progress by wxemouse      //~vXXER~
//}                                                                //~vXXER~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
CWxefile::~CWxefile()                                              //~v003R~
{                                                                  //~v003I~
}                                                                  //~v003I~
                                                                   //~vXXEI~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
int  CWxefile::init(CDocument *Ppdoc)                              //~v003R~
{                                                                  //~v003I~
//*********************                                            //~v003I~
     Mpdoc=Ppdoc;                                                  //~v003R~
     return 0;                                                     //~v003I~
}//newfile                                                         //~v003I~
#endif                                                             //~vXXEI~
////===============================================================================//~vbdmR~
////filenew is always called at start by setting at wxe.app on commmandlineinfo//~vbdmR~
////===============================================================================//~vbdmR~
//char *getnewname(char *Pfnm,char *Pfnmdir)                       //~vbdmR~
//{                                                                //~vbdmR~
//    FILEFINDBUF3 ffb3;                                           //~vbdmR~
//    static char Snewname[_MAX_PATH*2];                           //~vbdmR~
////*********************                                          //~vbdmR~
//    memset(Snewname,0,sizeof(Snewname));                         //~vbdmR~
//    if (!Pfnm)                                                   //~vbdmR~
//        strcpy(Snewname,"NewFile");                              //~vbdmR~
//    else                                                         //~vbdmR~
//    if (ufstat(Pfnm,&ffb3)==0                                    //~vbdmR~
//    &&  ffb3.attrFile & FILE_DIRECTORY)                          //~vbdmR~
//        sprintf(Snewname,"%s/NewFile",Pfnm);                     //~vbdmR~
//    else                                                         //~vbdmR~
//    if (!Pfnmdir)                                                //~vbdmR~
//        strcpy(Snewname,"NewFile");                              //~vbdmR~
//    else                                                         //~vbdmR~
//        sprintf(Snewname,"%s/NewFile",Pfnmdir);                  //~vbdmR~
//    return Snewname;                                             //~vbdmR~
//}//getnewname                                                    //~vbdmR~
//===============================================================================//~vb7kI~
void xxefile_dlgOnOK      				(void)                     //~vXXER~
{                                                                  //~vXXEM~
    const gchar *pfnm;                                             //~vXXER~
//    const gchar *pfnmdir=0;                                      //~vbdmR~
    const gchar *pfnmfile=0;                                       //~vbdmI~
    char *pc;                                                      //~vaf6I~
//****************************                                     //~vXXEM~
//  dprintf("gxedlg File onok mainlevel=%d\n",gtk_main_level());   //~vXXER~
#ifndef OPTGTK3                                                    //~var8R~
  #if GTK_CHECK_VERSION(2,4,0)	//GtkFileChooser is available      //~vb7kI~
    pfnm=gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Sfiledlg));//~vb7kI~
    pfnmfile=pfnm;                                                 //~vbdmI~
//    if (Src_new==1)                                              //~vbdmR~
//    {                                                            //~vbdmR~
//      pfnmdir=gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(Sfiledlg));//~vbdmR~
//      pfnm=getnewname((char*)pfnmfile,(char*)pfnmdir);           //~vbdmR~
//    }                                                            //~vbdmR~
  #else                                                            //~vb7kI~
    pfnm=gtk_file_selection_get_filename(GTK_FILE_SELECTION(Sfiledlg));//~vXXER~
    pfnmfile=pfnm;                                                 //~vbdmI~
  #endif                                                           //~vb7kI~
#else                                                              //~var8R~
//    pfnm=gtk_file_chooser_get_current_name(GTK_FILE_CHOOSER(Sfiledlg));//~vbdmI~
    pfnm=gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Sfiledlg));//~var8R~
    pfnmfile=pfnm;                                                 //~vbdmI~
//    if (Src_new==1)                                              //~vbdmR~
//    {                                                            //~vbdmR~
//      pfnmdir=gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(Sfiledlg));//~vbdmR~
//      pfnm=getnewname((char*)pfnmfile,(char*)pfnmdir);           //~vbdmR~
//    }                                                            //~vbdmR~
#endif                                                             //~var8R~
    gtk_widget_destroy(Sfiledlg);                                  //~vXXEM~
    if (!pfnm || !*pfnm)                                           //~vaf6I~
    	return;                                                    //~vaf6I~
    if (!Gfileselectiondir)                                        //~vaf6I~
    {                                                              //~vaf6I~
    	pc=(char*)malloc(_MAX_PATH);                               //~vaf6I~
        if (!pc)                                                   //~vaf6I~
        	return;                                                //~vaf6I~
    	Gfileselectiondir=pc;   //interface.c set filename to fileselection//~vaf6I~
    }                                                              //~vaf6M~
    pc=Gfileselectiondir;                                          //~vaf6I~
    UstrncpyZ(pc,pfnm,_MAX_PATH);                                  //~vaf6R~
    switch(Sdlgmode)                                               //~vXXEI~
    {                                                              //~vXXEI~
    case FILEDLG_OPEN:                                             //~vXXEI~
        xxefile_fileopen((char*)pfnm);                             //~vXXER~
        break;                                                     //~vXXEI~
    case FILEDLG_NEW:                                              //~vXXEI~
        xxefile_filenew((char*)pfnm);                              //~vXXER~
        break;                                                     //~vXXEI~
    case FILEDLG_SAVEAS:                                           //~vXXEI~
        xxefile_filesave((char*)pfnm);                             //~vXXER~
        break;                                                     //~vXXEI~
    }                                                              //~vXXEI~
//#ifndef OPTGTK3                                                    //~var8R~//~vbdmR~
//#else                                                              //~var8R~//~vbdmR~
//  g_free((gpointer)pfnm);                                        //~var8R~//~vbdmR~
//#endif                                                             //~var8R~//~vbdmR~
	if  (pfnmfile)                                                 //~vbdmI~
		g_free((gpointer)pfnmfile);                                //~vbdmI~
//    if  (pfnmdir)                                                //~vbdmR~
//        g_free((gpointer)pfnmdir);                               //~vbdmR~
	return;                                                        //~vXXEM~
}                                                                  //~vXXEM~
                                                                   //~vXXEM~
void xxefile_dlgOnCancel  				(void)                     //~vXXER~
{                                                                  //~vXXEM~
//****************************                                     //~vXXEM~
	 dprintf("gxedlg File cancel\n");                               //~vXXER~
    gtk_widget_destroy(Sfiledlg);                                  //~vXXEM~
	return;                                                        //~vXXEM~
}                                                                  //~vXXEM~
//===============================================================================//~v003I~
//filenew is always called at start by setting at wxe.app on commmandlineinfo//~v003R~
//===============================================================================//~v003I~
int  xxefile_filenew(char *Pfnm)                                   //~vXXER~
{                                                                  //~v003I~
//*********************                                            //~v003I~
    wxe_editcmd("E",Pfnm);                                         //~v003R~
    xxemain_scrinvalidate(0);                                      //~vXXER~
    return 0;                                                      //~v003R~
}//filenew                                                         //~vXXER~
//===============================================================================//~v003I~
//Open                                                             //~v003R~
//===============================================================================//~v003I~
int xxefile_fileopen(char *Pfilename)                              //~vXXER~
{                                                                  //~v003I~
     wxe_editcmd("E",(char *)Pfilename);                           //~v003R~
	 xxemain_scrinvalidate(0);                                     //~vXXER~
     return 0;                                                     //~v003I~
}//fileopen                                                        //~v003R~
//===============================================================================//~v003I~
//Open                                                             //~v003I~
//===============================================================================//~v003I~
int xxefile_filesave(char *Pfilename)                              //~vXXER~
{                                                                  //~v003I~
//*********************                                            //~v003I~
     wxe_editcmd("S",(char *)Pfilename);                           //~v003R~
	 xxemain_scrinvalidate(0);                                     //~vXXEI~
     return 0;                                                     //~v003I~
}//filesave                                                        //~v003I~
//===============================================================================//~v003I~
//                                                                 //~v003I~
//===============================================================================//~v003I~
void invalidate(void)                                              //~v685R~
{                                                                  //~v003I~
//************************                                         //~v003I~
    xxemain_scrinvalidate(0);                                      //~v685I~
    return;                                                        //~v003I~
}//invalidate                                                      //~v003I~
//===============================================================================//~v63gI~
//open dropped file                                                //~v63gR~
//===============================================================================//~v63gI~
void xxefile_ondropfiles(GdkDragContext  *Pcontext,                //~vXXEI~
                         GtkSelectionData *Pseldata,               //~vXXEI~
                         int Px,int Py,                            //~v686R~
                         UINT Ptime)                               //~vXXEI~
{                                                                  //~v003I~
    BOOL rc;                                                       //~v685R~
    int row,col;                                                   //~v686R~
#ifndef OPTGTK3                                                    //~var8R~
    int viewposx,viewposy,vieww,viewh,viewd;                       //~v685I~
#else   //OPTGTK3                                                  //+var8I//~var8R~
    int viewposx,viewposy,vieww,viewh;                             //~var8R~
#endif                                                             //+var8I//~var8R~
//***************************************                          //~v003I~
//  dprintf("%s:%s:ondrop: pos=(%d,%d) protocol=%d,is_source=%d,actions=%d,suggested_action=%d,action=%d\n",//~var8I~//+vbu0R~
//  	UTT,(char*)utimeedit("hh:mm:ss.mil",0));                   //~var8I~//+vbu0R~
#ifndef OPTGTK3                                                    //~var8R~
    dprintf("%s:ondrop: pos=(%d,%d) protocol=%d,is_source=%d,actions=%d,suggested_action=%d,action=%d\n",//~v685R~
    	(char*)utimeedit("hh:mm:ss.mil",0),                        //~vXXEI~
    	Px,Py,                                                     //~v685M~
  		Pcontext->protocol,                                        //~vXXEI~
  		Pcontext->is_source,                                       //~vXXEI~
		  /*GList *targets;  */                                    //~vXXEI~
		Pcontext->actions,                                         //~vXXEI~
		Pcontext->suggested_action,                                //~vXXEI~
		Pcontext->action);                                         //~vXXEI~
#endif                                                             //~var8R~
//    dprintf("ondrop:targetwin=%p,mainwindow=%p,frame=%p\n",      //~v685R~
//        Pcontext->dest_window,Gpview->window,Gpframe->window);   //~v685R~
//    gdk_window_get_position(Pcontext->dest_window,&col,&row);    //~v685R~
//    dprintf("ondrop:get posistion=(y,x)=(%d,%d)\n",row,col);     //~v685R~
//    row=ROW(row);                                                //~v685R~
//    col=COL(col);                                                //~v685R~
//    dprintf("ondrop: get posistion=(row,col)=(%d,%d)\n",row,col);//~v685R~
//    gdk_window_get_origin(Pcontext->dest_window,&col,&row);      //~v685R~
//    dprintf("ondrop: get origin=(y  ,x  )=(%d,%d)\n",row,col);   //~v685R~
//    row=ROW(row);                                                //~v685R~
//    col=COL(col);                                                //~v685R~
//    dprintf("ondrop: get origin=(row,col)=(%d,%d)\n",row,col);   //~v685R~
//    gdk_window_get_origin(Gpview->window,&col,&row);             //~v685R~
//    dprintf("ondrop: get origin of view =(y  ,x  )=(%d,%d)\n",row,col);//~v685R~
//    row=ROW(row);                                                //~v685R~
//    col=COL(col);                                                //~v685R~
//    dprintf("ondrop: get origin of view =(row,col)=(%d,%d)\n",row,col);//~v685R~
//    int buttonmask;                                              //~v685R~
//    gdk_window_get_pointer(Pcontext->dest_window,&col,&row,&buttonmask);//~v685R~
//    dprintf("ondrop: get pointer=(y  ,x  )=(%d,%d)\n",row,col);  //~v685R~
//    row=ROW(row);                                                //~v685R~
//    col=COL(col);                                                //~v685R~
//    dprintf("ondrop: get pointer=(row,col)=(%d,%d)\n",row,col);  //~v685R~
//    int gx,gy,gw,gh,gd;                                          //~v685R~
//    gdk_window_get_geometry(Pcontext->dest_window,&gx,&gy,&gw,&gh,&gd);//~v685R~
//    dprintf("ondrop: dest geometry (x,y)=(%d,%d),(w,h)=(%d,%d),depth=%d\n",gx,gy,gw,gh,gd);//~v685R~
//    gdk_window_get_geometry(Gpview->window,&gx,&gy,&gw,&gh,&gd); //~v685R~
//    dprintf("ondrop: view geometry (x,y)=(%d,%d),(w,h)=(%d,%d),depth=%d\n",gx,gy,gw,gh,gd);//~v685R~
//    gdk_window_get_geometry(Gpframe->window,&gx,&gy,&gw,&gh,&gd);//~v685R~
//    dprintf("ondrop: frame geometry (x,y)=(%d,%d),(w,h)=(%d,%d),depth=%d\n",gx,gy,gw,gh,gd);//~v685R~
//ajust pos on frame window to pos on view window                  //~v685R~
#ifndef OPTGTK3                                                    //~var8R~
    gdk_window_get_geometry(Gpview->window,&viewposx,&viewposy,&vieww,&viewh,&viewd);//~v685I~
#else                                                              //~var8R~
    gdk_window_get_geometry(gtk_widget_get_window(Gpview),&viewposx,&viewposy,&vieww,&viewh);//~var8R~
#endif                                                             //~var8R~
    row=Py-viewposy;                                               //~v685I~
    if (row<0)                                                     //~v685I~
    	row=0;                                                     //~v685I~
    col=Px-viewposx;                                               //~v685I~
    if (col<0)                                                     //~v685I~
    	col=0;                                                     //~v685I~
	row=ROW(row);                                                  //~v685R~
	col=COL(col);                                                  //~v685R~
    dprintf("ondrop: rowcol=(%d,%d)\n",row,col);                   //~v685R~
	rc=xxefile_ondropfilesub(0,Pseldata,0,row,col);                //~v685R~
    dprintf("%s:drag data finish req rc(bool)=%d\n",(char*)utimeedit("HH:MM:SS.MIL",0),rc);//~v685R~//~var8R~
    Mdroprc=rc; //to notify dragend for internal dnd case          //~v685I~
	gtk_drag_finish (Pcontext,rc,FALSE,Ptime);//del FALSE          //~v685R~
    dprintf("%s:drag data finished\n",(char*)utimeedit("HH:MM:SS.MIL",0));//~v685I~
    usetfocus();                                                   //~v68iI~
}//xxefile_ondropfiles                                             //~v686I~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vR~
//===============================================================================//~vb7vR~
//open dropped file by Paste                                       //~vb7vR~
//return drop success id                                           //~vb7vR~
//===============================================================================//~vb7vR~
int xxefile_ondropfiles_Paste(int Popt,void *Ppcwtarget,int Prow,int Pcol)//~vb7vR~
{                                                                  //~vb7vR~
	int rc;                                                        //~vb7vR~
//****************************                                     //~vb7vR~
  	dprintf("%s:entry\n",UTT);                                     //~vb7vR~
	rc=xxefile_ondropfilesub(0,0/*Pseldata*/,Ppcwtarget,Prow,Pcol);//~vb7vR~
    Mdroprc=rc; //to notify dragend for internal dnd case          //~vb7vR~
    if (rc)                                                        //~vb7vR~
		uclipboard_getfileselection_Clear(0);                      //~vb7vR~
    return rc;                                                     //~vb7vR~
}//xxefile_ondropfiles_Paste                                       //~vb7vR~
#endif                                                             //~vb7vR~
//===============================================================================//~v686I~
//open dropped file                                                //~v686I~
//seldata may be null(from xxefile_ondropfile_Paste when not dragdrop but paste)//~vb7vR~
//return drop success id                                           //~v685I~
//===============================================================================//~v686I~
int xxefile_ondropfilesub(int Popt,                                //~v686R~
                         GtkSelectionData *Pseldata,               //~v686I~
                         void *Ppcwtarget,                         //~v685I~
                         int Prow,int Pcol)                        //~v686I~
{                                                                  //~v686I~
	int  rc;                                                       //~v686I~
    char *pc;                                                      //~v686I~
    char *filenames;                                               //~v686I~
    int fileno,ii;                                                 //~v685R~
    int filecopy;                                                  //~v685I~
    char targetdir[_MAX_PATH+1];                                   //~v685I~
    int rc2=TRUE;                                                  //~v685I~
//***************************************                          //~v686I~
#if defined(OPTGTK3) && !defined(YYY)                              //~vb7vR~
  if (Pseldata)                                                    //~vb7vR~
#endif                                                             //~vb7vR~
  {                                                                //~vb7vR~
  	dprintf("%s:format=%d,data=%s,len=%d\n",UTT,                   //~var8I~
		gtk_selection_data_get_format(Pseldata),                   //~var8I~
		gtk_selection_data_get_data(Pseldata),                     //~var8I~
		gtk_selection_data_get_length(Pseldata));                  //~var8I~
    dprintf("%s:selection atom name=%s\n",UTT,                     //~var8I~
			 gdk_atom_name(gtk_selection_data_get_selection(Pseldata)));//~var8I~
    dprintf("%s:target atom name=%s\n",UTT,                        //~var8I~
			 gdk_atom_name(gtk_selection_data_get_target(Pseldata)));//~var8I~
    dprintf("%s:type atom name=%s\n",UTT,                          //~var8I~
			 gdk_atom_name(gtk_selection_data_get_data_type(Pseldata)));//~var8I~
	Gxxestat&=~GXXES_DNDUTIL;                                      //~v76gI~
  }                                                                //~vb7vR~
	filecopy=wxe_dndfilecopychk(DROP_COPYCHKMSG,Mdragedpcw,Ppcwtarget,Prow,Pcol,targetdir);//~v685R~
    dprintf("%s:rc of wxe_dndfilecopychk(filecopy)=%d\n",UTT,filecopy);//~var8I~
  if (filecopy<0)	//drop on dir list failed(target not selected) or not dir//~v685I~
  	rc2=FALSE;                                                     //~v685I~
  else                                                             //~v685I~
  if (filecopy==DROPRC_UTIL)	//drop to utility panel            //~v76gI~
  {                                                                //~v76gI~
	Gxxestat|=GXXES_DNDUTIL;                                       //~v76gI~
	if (!uclipboard_getcopyfilesub(0,Pseldata,&filenames,&fileno,0))//~v76gI~
    {                                                              //~v76gI~
        for (pc=filenames,ii=fileno;ii>0;ii--)                     //~v76gI~
        {                                                          //~v76gI~
    	 	rc=wxe_dndutil(Popt,pc,Prow);                          //~v76jR~
            if (rc)                                                //~v76gI~
                break;                                             //~v76gI~
            pc+=strlen(pc)+1;                                      //~v76gI~
        }                                                          //~v76gI~
        umemfree(filenames);                                       //~v76gI~
    }                                                              //~v76gI~
	rc2=TRUE;	//done                                             //~v76jR~
  }                                                                //~v76gI~
  else                                                             //~v76gI~
  if (filecopy)                                                    //~v685I~
  {                                                                //~v685I~
    if (filepostcopybydndmsg(Popt,Pseldata,targetdir))             //~v685R~
    {                                                              //~var8I~
	    dprintf("%s:rc of filepostcopybydndmsg !=0\n",UTT);      //~var8I~//~vb7vR~
	  	rc2=FALSE;                                                 //~v685R~
    }                                                              //~var8I~
  }                                                                //~v685I~
  else                                                             //~v685I~
  {                                                                //~v685I~
//     dprintf("drag data received selection=%d,target=%d,type=%d,format=%d,data=%s,len=%d\n",//~v686R~
//        (int)(Pseldata->selection),                              //~v686R~
//        (int)(Pseldata->target),                                 //~v686R~
//        (int)(Pseldata->type),                                   //~v686R~
//        Pseldata->format,                                        //~v686R~
//        Pseldata->data,                                          //~v686R~
//        Pseldata->length);                                       //~v686R~
//    dprintf("receive name selection=%s\n",                       //~v686R~
//             gdk_atom_name(Pseldata->selection));                //~v686R~
//    dprintf("receive name target=%s\n",                          //~v686R~
//             gdk_atom_name(Pseldata->target));                   //~v686R~
//    dprintf("receive name type=%s\n",                            //~v686R~
//             gdk_atom_name(Pseldata->type));                     //~v686R~
//    if (Pseldata->length>0 && Pseldata->format==8)               //~v686R~
//    {                                                            //~v686R~
//        dropsuccess=TRUE;                                        //~v686R~
//        pc0=umemalloc(Pseldata->length);                         //~v686R~
//        memcpy(pc0,Pseldata->data,Pseldata->length);             //~v686R~
//        for (pc=pc0;*pc;)                                        //~v686R~
//        {                                                        //~v686R~
//            pce=strchr(pc,'\n');                                 //~v686R~
//            if (!memcmp(pc,TEXTFILEID,TEXTFILEIDLEN))            //~v686R~
//            {                                                    //~v686R~
//                if (pce)                                         //~v686R~
//                {                                                //~v686R~
//                    if (pce>pc && *(pce-1)=='\r')                //~v686R~
//                        *(pce-1)=0;         //0d0a               //~v686R~
//                    else                                         //~v686R~
//                        *pce=0;             //0a                 //~v686R~
//                }                                                //~v686R~
////              pfnm=g_filename_from_uri(pc,&phostname,&perror);    //api may have bug//~v686R~
//                if (uuridecode(pc+TEXTFILEIDLEN,fnm,_MAX_PATH)<0)//~v686R~
//                {                                                //~v686R~
//                    dropsuccess=FALSE;                           //~v686R~
//                    break;                                       //~v686R~
//                }                                                //~v686R~
//                rc=wxe_editcmd("E",fnm);                         //~v686R~
////              g_free(pfnm);                                    //~v686R~
//                if (rc)                                          //~v686R~
//                    break;                                       //~v686R~
//            }                                                    //~v686R~
//            else                                                 //~v686R~
//            {                                                    //~v686R~
//                dropsuccess=FALSE;                               //~v686R~
//                break;                                           //~v686R~
//            }                                                    //~v686R~
//            if (!pce)                                            //~v686R~
//                break;                                           //~v686R~
//            pc=pce+1;                                            //~v686R~
//        }                                                        //~v686R~
//        umemfree(pc0);                                           //~v686R~
//    }                                                            //~v686R~
	if (!uclipboard_getcopyfilesub(0,Pseldata,&filenames,&fileno,0))//~v685R~
    {                                                              //~v686I~
        for (pc=filenames,ii=fileno;ii>0;ii--)                     //~v685R~
        {                                                          //~v686I~
            rc=wxe_editcmd("E",pc);                                //~v686R~
            if (rc)                                                //~v686I~
                break;                                             //~v686I~
            pc+=strlen(pc)+1;                                      //~v686R~
        }                                                          //~v686I~
        umemfree(filenames);                                       //~v686R~
    }                                                              //~v686I~
    else                                                           //~v685I~
    {                                                              //~var8I~
  		rc2=FALSE;                                                 //~v685I~
//      dprintf("%s:rc of uclipboard_getcopyfilesub rc!=0%d\n",UTT);//~vbu0R~
        dprintf("%s:rc of uclipboard_getcopyfilesub rc!=0%d\n",UTT,rc2);//~vbu0I~
    }                                                              //~var8I~
  }                                                                //~v685I~
//	gtk_drag_finish (Pcontext,dropsuccess,FALSE,Ptime);//del FALSE //~v686R~
//    if (!dropsuccess)                                            //~v685R~
//        umsgbox("DragDrop;Unkown data format",MB_OK);            //~v685R~
    xxemain_scrinvalidate(0);                                      //~vXXER~
//	return;                                                        //~v685R~
  	return rc2;                                                    //~v685I~
}//xxefile_ondropfilesub                                             //~vXXER~//~vb7vR~
#ifndef XXE                                                        //~vXXEI~
//===============================================================================//~v63gI~
//1st time drop csr entered                                        //~v63gI~
//===============================================================================//~v63gI~
DROPEFFECT CWxefile::ondragenter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)//~v63gI~
{                                                                  //~v63gI~
//  if (Mswdndinprogress)    //dodrag in progress by wxemouse      //~v63kR~
//  	return DROPEFFECT_NONE;                                    //~v63kR~
    return DROPEFFECT_COPY;                                        //~v63gI~
}                                                                  //~v63gI~
//===============================================================================//~v63gI~
//1st time drop csr entered                                        //~v63gI~
//===============================================================================//~v63gI~
DROPEFFECT CWxefile::ondragover(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)//~v63gI~
{                                                                  //~v63gI~
//  if (Mswdndinprogress)    //dodrag in progress by wxemouse      //~v63kR~
//  	return DROPEFFECT_NONE;                                    //~v63kR~
    return DROPEFFECT_COPY;                                        //~v63gI~
}                                                                  //~v63gI~
#endif                                                             //~vXXEI~
//===============================================================================//~v685I~
//send copy file msg                                               //~v685I~
//===============================================================================//~v685I~
int  filepostcopybydndmsg(int Popt,GtkSelectionData *Pseldata,char *Ptarget)//~v685I~
{                                                                  //~v685I~
    char *msg,*filenames;                                          //~v685R~
    int len,totlen,msglen,fileno;                                  //~v685R~
    long parm2;                                                    //~v685I~
//***************************************                          //~v685I~
	if (uclipboard_getcopyfilesub(0,Pseldata,&filenames,&fileno,&totlen))//~v685R~
    {                                                              //~var8I~
	    dprintf("%s:rc of uclipboard_getcopyfilesub rc!=0\n",UTT);//~var8I~//~vb7vR~
    	return -1;                                                 //~v685I~
    }                                                              //~var8I~
    if (!fileno)                                                   //~v685I~
    {                                                              //~var8I~
	    dprintf("%s:fileno=0 from uclipboard_getcopyfilesub\n",UTT);//~var8I~
    	return -1;                                                 //~v685I~
    }                                                              //~var8I~
    len=strlen(Ptarget)+1;                                         //~v685I~
    msglen=len+totlen;                                             //~v685I~
    msg=(char*)umemalloc(msglen);                                  //~v685I~
    memcpy(msg,Ptarget,len);	//top is target                    //~v685I~
    memcpy(msg+len,filenames,totlen);                              //~v685I~
    umemfree(filenames);                                           //~v685I~
    parm2=(1<<16)|fileno;	//seq & total                          //~v685I~
    parm2|=Popt;                                                   //~v685I~
	dprintf("%s:upostmsg\n",UTT);                                  //~var8I~
	return upostmsg(ID_FILE_DNDCOPY,(ULONG)msg,parm2);             //~v685I~
}//filepostcopybydnd                                               //~v685I~
//===============================================================================//~v685I~
//execute copy by post msg                                         //~v685I~
//===============================================================================//~v685I~
BOOL  filecopybydnd(ULONG Pcmdparm1,ULONG Pcmdparm2)               //~v685R~
{                                                                  //~v685I~
    char *tgt,*src;                                                //~v685I~
    int rc,seq,tot,ii;                                             //~v685I~
    ULONG nextseq,flag;                                            //~v685I~
    int opt=0;                                                     //~v685I~
//***************************************                          //~v685I~
dprintf("@@@@dragdrop postmag enter parm=%lx,%lx\n",Pcmdparm1,Pcmdparm2);//~v685R~
    flag=Pcmdparm2 & DROPFILE_FLAGMASK;                            //~v685I~
    Pcmdparm2 &= ~DROPFILE_FLAGMASK;                               //~v685I~
    if (flag & DROPFILE_REP)                                       //~v685I~
    	opt|=DNDCOPY_REP;                                          //~v685I~
    seq=Pcmdparm2>>16;                                             //~v685I~
    tot=Pcmdparm2&0xffff;                                          //~v685I~
	tgt=(char*)Pcmdparm1;                                          //~v685I~
    src=tgt+strlen(tgt)+1;                                         //~v685I~
    for (ii=seq-1;ii>0;ii--)                                       //~v685I~
    	src+=strlen(src)+1;                                        //~v685I~
dprintf("@@@@dragdrop postmag enter seq=%d of %d s=%s,t=%s\n",seq,tot,src,tgt);//~v685R~
	rc=wxe_dndcopyfile(opt,seq,tot,src,tgt);                       //~v685I~
dprintf("@@@@dragdrop dndcopyfile rc=%d\n",rc);                    //~v685R~
    if (rc==-1||seq==tot)	//cancelled or last                    //~v685I~
	    umemfree((void*)Pcmdparm1);                                //~v685I~
    else                                                           //~v685I~
    {                                                              //~v685I~
    	seq++;                                                     //~v685I~
        nextseq=(seq<<16)|tot;                                     //~v685I~
        nextseq|=flag;                                             //~v685I~
		upostmsg(ID_FILE_DNDCOPY,(ULONG)Pcmdparm1,nextseq);        //~v685I~
    }                                                              //~v685I~
    invalidate();                                                  //~v685I~
	return TRUE;                                                   //~v685R~
}//filecopybydnd                                                   //~v685I~
//***************************************************************************//~vXXEM~
// File                                                            //~vXXEM~
//*mode:1:open/2:new/3:saveas                                      //~var8R~
//***************************************************************************//~vXXEM~
void dlgcreate 				(GtkMenuItem     *Pmenuitem,           //~vXXER~
                                        int              Pdlgmode)//1:new,0:saveas//~vXXER~
{                                                                  //~vXXEM~
  	GtkWidget *framewindow;                                        //~vXXEM~
//****************************                                     //~vXXEM~
	 dprintf("on_file_activate  \n");                               //~vXXER~
  	framewindow = lookup_widget (GTK_WIDGET (Pmenuitem), "framewindow");//~vXXEM~
#ifndef OPTGTK3                                                    //~var8R~
  #if GTK_CHECK_VERSION(2,4,0)	//GtkFileChooser is available      //~vb7kI~
	{                                                              //~vb7kI~
    	int rc;                                                    //~vb7kI~
    //********************                                         //~vb7kI~
	    Sfiledlg=create_fileselection(framewindow,Pdlgmode,&rc);   //~vb7kI~
	    Sdlgmode=Pdlgmode;                                         //~vb7kI~
        if (!rc)	//accept                                       //~vb7kI~
			xxefile_dlgOnOK();                                     //~vb7kI~
//        else                                                     //~vbdmR~
//        if (rc==1)  //New                                        //~vbdmR~
//        {                                                        //~vbdmR~
//            Src_new=1;                                           //~vbdmR~
//            xxefile_dlgOnOK();                                   //~vbdmR~
//            Src_new=0;                                           //~vbdmR~
//        }                                                        //~vbdmR~
        else                                                       //~vb7kI~
			xxefile_dlgOnCancel();                                 //~vb7kI~
    }                                                              //~vb7kI~
  #else                                                            //~vb7kI~
    Sfiledlg = create_fileselection();                             //~vXXEM~
//  gtk_object_set_data (GTK_OBJECT (Sfiledlg), FRAME_WINDOW_KEY, framewindow);//~vXXER~
                                                                   //~vXXEM~
      /* Make sure the dialog doesn't disappear behind the main window. *///~vXXEM~
    gtk_window_set_transient_for (GTK_WINDOW (Sfiledlg),           //~vXXEM~
				    GTK_WINDOW (framewindow));                     //~vXXEM~
  	gtk_widget_show (Sfiledlg);                                    //~vXXEM~
                                                                   //~vXXEM~
  	/* We make sure the dialog is visible. */                      //~vXXEM~
  	gtk_window_present (GTK_WINDOW (Sfiledlg));                    //~vXXEM~
    Sdlgmode=Pdlgmode;                                             //~vXXER~
  #endif	                                                       //~vb7kI~
#else                                                              //~var8R~
	{                                                              //~var8R~
    	int rc;                                                    //~var8R~
    //********************                                         //~var8R~
	    Sfiledlg=create_fileselection(framewindow,Pdlgmode,&rc);   //~var8R~
	    Sdlgmode=Pdlgmode;                                         //~var8R~
        if (!rc)	//accept                                       //~var8R~
			xxefile_dlgOnOK();                                     //~var8R~
        else                                                       //~var8R~
//        if (rc==1)  //New                                        //~vbdmR~
//        {                                                        //~vbdmR~
//            Src_new=1;                                           //~vbdmR~
//            xxefile_dlgOnOK();                                   //~vbdmR~
//            Src_new=0;                                           //~vbdmR~
//        }                                                        //~vbdmR~
//        else                                                     //~vbdmR~
			xxefile_dlgOnCancel();                                 //~var8R~
    }                                                              //~var8R~
#endif                                                             //~var8R~
    return;                                                        //~vXXEM~
}                                                                  //~vXXEM~
