//*CID://+v79GR~:                             update#=    3;       //~v79GI~
//**************************************************************************//~v79GI~
//xeshm.h                                                          //+v79GR~
//class to use protect method of StartApp                          //+v79GI~
//**************************************************************************//+v79GI~
//v79G:081014 (SYNH) source-highlight inheritance                  //+v79GI~
//**************************************************************************//~v79GI~
#ifdef __cplusplus
extern "C" {
#endif
//  int xeshm_main(int argc, char **argv);
#ifdef __cplusplus
}
#include "startapp.h"
class xeshm:public StartApp      //protect-->public                //~v79GR~
{
 public:
  xeshm():StartApp(){};
//  virtual ~xeshm();
//****************************************************************
int start(int Pargc,char *Pargv[])
{
    int rc;
//*************************
    rc=StartApp::start(Pargc,Pargv);
    return rc;
};
//****************************************************************
int processFile(char *Pinpfnm,char *Poutfnm,char *Pext)
{
    return StartApp::processFile(Pinpfnm,Poutfnm,Pext);
};

} ;
#endif
