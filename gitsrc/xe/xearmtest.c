//*CID://+va70R~:                             update#=  110;       //~va70I~
//*************************************************************    //~va70I~
//*xearmtest.c                                                     //~va70I~
//*	android test                                                   //~va70I~
//*************************************************************    //~va70I~
                                                                   //~va70I~
//*************************************************************    //~va70I~
#include <stdlib.h>                                                //~va70I~
#include <stdio.h>                                                 //~va70I~
#include <string.h>                                                //~va70I~
#ifdef AIX                                                         //~va70I~
    #include <ucurses.h>                                           //~va70I~
#endif                                                             //~va70I~
#include <term.h>                                                  //~va70I~
#include <sys/ioctl.h>                                             //~va70I~
#include <linux/vt.h>                                              //~va70I~
#include <linux/kd.h>                                              //~va70I~
#include <fcntl.h>                                                 //~va70I~
//**********************                                           //~va70I~
#include <ulib.h>                                                  //~va70I~
#include <uedit.h>                                                 //~va70I~
#include <ukbdl.h>                                                 //~va70I~
#include <ukbdlnxc.h>                                              //~va70I~
#include <utrace.h>                                                //~va70I~
//*************************************************************    //~va70I~
//*************************************************************    //~va70I~
void xesetkbdopt(int Popt);                                        //~va70I~
//#ifdef AIX                                                       //~va70I~
	void xesettabs(int Pinitsw);                                   //~va70I~
//#endif                                                           //~va70I~
static void sigttou(int signo)                                     //+va70I~
{                                                                  //+va70I~
    printf("SIGTTOU entry\n");                                     //+va70I~
    signal(SIGTTOU,SIG_DFL);                                       //+va70I~
    kill(getpid(),SIGTTOU);                                        //+va70I~
}                                                                  //+va70I~
//*************************************************************    //~va70I~
//default kbd opt                                                  //~va70I~
//*********************************************************************//~va70I~
int main(int argc,char **argp)                                     //~va70I~
{                                                                  //~va70I~
    printf("argc=%d,arg0=%s\n",argc,argp[0]);                      //~va70I~
    UTRACE_INIT("/sdcard/xe.trc",1);                               //~va70R~
    signal(SIGTTOU,sigttou);                                       //+va70I~
    xesettabs(1);                                                  //~va70I~
    xesettabs(0);                                                  //~va70I~
    return 0;                                                      //~va70R~
}//main                                                            //~va70I~
//*********************************************************************//~va70I~
//    sSignalCatcherPid = 0;                                       //~va70I~
                                                                   //~va70I~
//    // create a new console                                      //~va70I~
//    char const * const ttydev = "/dev/tty0";                     //~va70I~
//    int fd = open(ttydev, O_RDWR | O_SYNC);                      //~va70I~
//    if (fd<0) {                                                  //~va70I~
//        LOGE("Can't open %s", ttydev);                           //~va70I~
//        this->consoleFd = -errno;                                //~va70I~
//        return;                                                  //~va70I~
//    }                                                            //~va70I~
                                                                   //~va70I~
//    // to make sure that we are in text mode                     //~va70I~
//    int res = ioctl(fd, KDSETMODE, (void*) KD_TEXT);             //~va70I~
//    if (res<0) {                                                 //~va70I~
//        LOGE("ioctl(%d, KDSETMODE, ...) failed, res %d (%s)",    //~va70I~
//                fd, res, strerror(errno));                       //~va70I~
//    }                                                            //~va70I~
//                                                                 //~va70I~
//    // get the current console                                   //~va70I~
//    struct vt_stat vs;                                           //~va70I~
//    res = ioctl(fd, VT_GETSTATE, &vs);                           //~va70I~
//    if (res<0) {                                                 //~va70I~
//        LOGE("ioctl(%d, VT_GETSTATE, ...) failed, res %d (%s)",  //~va70I~
//                fd, res, strerror(errno));                       //~va70I~
//        this->consoleFd = -errno;                                //~va70I~
//        return;                                                  //~va70I~
//    }                                                            //~va70I~
                                                                   //~va70I~
//    // switch to console 7 (which is what X normaly uses)        //~va70I~
//    int vtnum = 7;                                               //~va70I~
//    do {                                                         //~va70I~
//        res = ioctl(fd, VT_ACTIVATE, (void*)vtnum);              //~va70I~
//    } while(res < 0 && errno == EINTR);                          //~va70I~
//    if (res<0) {                                                 //~va70I~
//        LOGE("ioctl(%d, VT_ACTIVATE, ...) failed, %d (%s) for %d",//~va70I~
//                fd, errno, strerror(errno), vtnum);              //~va70I~
//        this->consoleFd = -errno;                                //~va70I~
//        return;                                                  //~va70I~
//    }                                                            //~va70I~
                                                                   //~va70I~
//    do {                                                         //~va70I~
//        res = ioctl(fd, VT_WAITACTIVE, (void*)vtnum);            //~va70I~
//    } while(res < 0 && errno == EINTR);                          //~va70I~
//    if (res<0) {                                                 //~va70I~
//        LOGE("ioctl(%d, VT_WAITACTIVE, ...) failed, %d %d %s for %d",//~va70I~
//                fd, res, errno, strerror(errno), vtnum);         //~va70I~
//        this->consoleFd = -errno;                                //~va70I~
//        return;                                                  //~va70I~
//    }                                                            //~va70I~
                                                                   //~va70I~
//    // open the new console                                      //~va70I~
//    close(fd);                                                   //~va70I~
//    fd = open(ttydev, O_RDWR | O_SYNC);                          //~va70I~
//    if (fd<0) {                                                  //~va70I~
//        LOGE("Can't open new console %s", ttydev);               //~va70I~
//        this->consoleFd = -errno;                                //~va70I~
//        return;                                                  //~va70I~
//    }                                                            //~va70I~
                                                                   //~va70I~
//    /* disable console line buffer, echo, ... */                 //~va70I~
//    struct termios ttyarg;                                       //~va70I~
//    ioctl(fd, TCGETS , &ttyarg);                                 //~va70I~
//    ttyarg.c_iflag = 0;                                          //~va70I~
//    ttyarg.c_lflag = 0;                                          //~va70I~
//    ioctl(fd, TCSETS , &ttyarg);                                 //~va70I~
                                                                   //~va70I~
//    // set up signals so we're notified when the console changes //~va70I~
//    // we can't use SIGUSR1 because it's used by the java-vm     //~va70I~
//    vm.mode = VT_PROCESS;                                        //~va70I~
//    vm.waitv = 0;                                                //~va70I~
//    vm.relsig = SIGUSR2;                                         //~va70I~
//    vm.acqsig = SIGUNUSED;                                       //~va70I~
//    vm.frsig = 0;                                                //~va70I~
                                                                   //~va70I~
//    struct sigaction act;                                        //~va70I~
//    sigemptyset(&act.sa_mask);                                   //~va70I~
//    act.sa_handler = sigHandler;                                 //~va70I~
//    act.sa_flags = 0;                                            //~va70I~
//    sigaction(vm.relsig, &act, NULL);                            //~va70I~
                                                                   //~va70I~
//    sigemptyset(&act.sa_mask);                                   //~va70I~
//    act.sa_handler = sigHandler;                                 //~va70I~
//    act.sa_flags = 0;                                            //~va70I~
//    sigaction(vm.acqsig, &act, NULL);                            //~va70I~
                                                                   //~va70I~
//    sigset_t mask;                                               //~va70I~
//    sigemptyset(&mask);                                          //~va70I~
//    sigaddset(&mask, vm.relsig);                                 //~va70I~
//    sigaddset(&mask, vm.acqsig);                                 //~va70I~
//    sigprocmask(SIG_BLOCK, &mask, NULL);                         //~va70I~
                                                                   //~va70I~
//    // switch to graphic mode                                    //~va70I~
//    res = ioctl(fd, KDSETMODE, (void*)KD_GRAPHICS);              //~va70I~
//    LOGW_IF(res<0,                                               //~va70I~
//            "ioctl(%d, KDSETMODE, KD_GRAPHICS) failed, res %d", fd, res);//~va70I~
                                                                   //~va70I~
//    this->prev_vt_num = vs.v_active;                             //~va70I~
//    this->vt_num = vtnum;                                        //~va70I~
//    this->consoleFd = fd;                                        //~va70I~
//*********************************************************************//~va70I~
void testioctl(void)                                               //~va70I~
{                                                                  //~va70I~
    int rc,fd;                                                     //~va70I~
    struct termios tios;                                           //~va70I~
    struct vt_stat vs;                                             //~va70I~
    char *ttydev = "/dev/tty0",*pc;                                //~va70I~
//***************                                                  //~va70I~
    fd = open(ttydev, O_RDWR | O_SYNC);                            //~va70I~
    printf("ioctl open tty0 fd=%d,errno=%d\n",fd,errno);           //~va70I~
                                                                   //~va70I~
    rc = ioctl(fd, VT_GETSTATE, &vs);                              //~va70I~
    printf("ioctl VT_GETSTATE rc=%d,errno=%d\n",rc,errno);         //~va70I~
    UTRACED("VT_GETSTATE vs",&vs,sizeof(vs));                      //~va70I~
                                                                   //~va70I~
    // to make sure that we are in text mode                       //~va70I~
    rc = ioctl(fd, KDSETMODE, (void*) KD_TEXT);                    //~va70I~
    printf("ioctl KDSETMODE rc=%d,errno=%d\n",rc,errno);           //~va70I~
                                                                   //~va70I~
    pc="4444aaaaaa\n";                                             //~va70R~
    write(fd,pc,strlen(pc));                                       //~va70I~
                                                                   //~va70I~
    rc=tcgetattr(fd,&tios);                                        //~va70I~
    fprintf(stderr,"fd=%d,tcgetattr rc=%d,errno=%d\n",fd,rc,errno);//~va70R~
    UTRACED("tcgetattr tios fd=4",&tios,sizeof(tios));             //~va70R~
                                                                   //~va70I~
    tios.c_oflag |= TABDLY;  //tab delay(rep tab by space)         //~va70R~
    rc=tcsetattr(fd,TCSANOW,&tios);                                //~va70R~
    fprintf(stderr,"fd=%d,tcsetattr rc=%d,errno=%d\n",fd,rc,errno);//~va70R~
    UTRACED("tcsetattr tios fd=4",&tios,sizeof(tios));             //~va70R~
                                                                   //~va70I~
    fd=0;                                                          //~va70M~
    rc=tcgetattr(fd,&tios);                                        //~va70I~
    fprintf(stderr,"fd=%d,tcgetattr rc=%d,errno=%d\n",fd,rc,errno);//~va70R~
    UTRACED("tcgetattr tios fd=0",&tios,sizeof(tios));             //~va70R~
                                                                   //~va70I~
//  tios.c_oflag |= TABDLY;  //tab delay(rep tab by space)         //~va70R~
    tios.c_lflag |= ICANON;  //tab delay(rep tab by space)         //~va70M~
    fprintf(stderr,"fd=%d,tcsetattr icanon=%x\n",fd,tios.c_lflag); //~va70I~
    UTRACED("tcsetattr before set icano tios fd=4",&tios,sizeof(tios));//~va70M~
    rc=tcsetattr(fd,TCSANOW,&tios);                                //~va70I~
    fprintf(stderr,"fd=%d,tcsetattr rc=%d,errno=%d\n",fd,rc,errno);//~va70I~
    UTRACED("tcsetattr tios fd=1",&tios,sizeof(tios));             //~va70I~
                                                                   //~va70I~
    rc = ioctl(fd, VT_GETSTATE, &vs);                              //~va70I~
    printf("ioctl VT_GETSTATE fd=0 rc=%d,errno=%d\n",rc,errno);    //~va70R~
    UTRACED("VT_GETSTATE fd=0 vs",&vs,sizeof(vs));                 //~va70R~
                                                                   //~va70I~
    fd=1;                                                          //~va70I~
    pc="1111aaaaaa\n";                                             //~va70I~
    write(fd,pc,strlen(pc));                                       //~va70I~
                                                                   //~va70I~
    rc=tcgetattr(fd,&tios);                                        //~va70I~
    fprintf(stderr,"fd=%d,tcgetattr rc=%d,errno=%d\n",fd,rc,errno);//~va70I~
    UTRACED("tcgetattr tios fd=1",&tios,sizeof(tios));             //~va70I~
                                                                   //~va70I~
    tios.c_oflag |= TABDLY;  //tab delay(rep tab by space)         //~va70I~
    rc=tcsetattr(fd,TCSANOW,&tios);                                //~va70I~
    fprintf(stderr,"fd=%d,tcsetattr rc=%d,errno=%d\n",fd,rc,errno);//~va70R~
    UTRACED("tcsetattr tios fd=1",&tios,sizeof(tios));             //~va70R~
                                                                   //~va70I~
    rc = ioctl(fd, VT_GETSTATE, &vs);                              //~va70I~
    printf("ioctl VT_GETSTATE fd=1 rc=%d,errno=%d\n",rc,errno);    //~va70I~
    UTRACED("VT_GETSTATE fd=1 vs",&vs,sizeof(vs));                 //~va70I~
                                                                   //~va70I~
}                                                                  //~va70I~
//*********************************************************************//~va70I~
//* assign sym to keycode with modifier                            //~va70I~
//*********************************************************************//~va70I~
void xesettabs(int Pinitsw)                                        //~va70I~
{                                                                  //~va70I~
static struct termios Soldtios;                                    //~va70I~
       struct termios newtios;                                     //~va70I~
    int fd=0;   //stdin                                            //~va70I~
//*****************************                                    //~va70I~
	if (Pinitsw)                                                   //~va70I~
    {                                                              //~va70I~
          testioctl();                                             //~va70R~
    printf("ukbdl_tcgetattr\n");                                   //~va70I~
                                                                   //~va70I~
    	ukbdl_tcgetattr(fd,&Soldtios);                             //~va70I~
	    memcpy(&newtios,&Soldtios,sizeof(newtios));                //~va70I~
        newtios.c_oflag |= TABDLY;  //tab delay(rep tab by space)  //~va70I~
    printf("ukbdl_tcsetattr\n");                                   //~va70I~
    	ukbdl_tcsetattr(fd,&newtios);                              //~va70I~
    }                                                              //~va70I~
    else                                                           //~va70I~
    	ukbdl_tcsetattr(fd,&Soldtios);                             //~va70I~
    printf("return         \n");                                   //~va70I~
    return;                                                        //~va70I~
}//xesettabs                                                       //~va70I~
