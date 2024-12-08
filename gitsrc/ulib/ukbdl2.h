//*CID://+v6FeR~:                             update#=   69;       //~v6FeR~
//**************************************************************** //~v58eI~
//ukbdl2.h    linux EscString for linux and AIX(telnet from linux) //~v58eI~
//**************************************************************** //~v58eI~
//v6Fe:160918 add debian key string                                //~v6FeI~
//v6F2:160903 (LNX)additional to v6E7,define curses string for keys other S+A+Fxx,S+C+Fxx
//v6Ey:160824 for FindPSx register S+C+F5,S+A+F5                   //~v6EyI~
//v6qh:131214 change terminal type:SCO Esc string by v6q6 as optional//~v5qhI~
//v6q6:131202 (LNX)register FuncKey string according to PuTTY 0.63 //~v5q6I~
//            SCO S+F2:1b[Z is duplicated to S+Tab. Select S+Tab because S+F2 is assigned to Split vertical as default//~v5q6I~
//v5nG:090426 (LNX:SUSE11) add esc seq for S+F1->F4                //~v5nGI~
//v70f:060801 (BUG:WXE/WIN/XXE)C+10key,C+"-",c+"+" is ignored      //~v70fI~
//v5h0:050811 (LNX)FC4(fedora core 4);new gnome-terminal key esc code for Home,End//~v5h0R~
//v58e:030824 (UNX) move key registration to another header file,ukbdl2.h//~v58eI~
//**************************************************************** //~v58eI~
    SETCKTX("\x1bOC"   ,RIGHT ,0)                                  //~v58eM~
    SETCKTX("\x1b[C"   ,RIGHT ,0)                                  //~v58eM~
    SETCKTX("\x1bOD"   ,LEFT  ,0)                                  //~v58eM~
    SETCKTX("\x1b[D"   ,LEFT  ,0)                                  //~v58eM~
    SETCKTX("\x1bOB"   ,DOWN  ,0)                                  //~v58eM~
    SETCKTX("\x1b[B"   ,DOWN  ,0)                                  //~v58eM~
    SETCKTX("\x1bOA"   ,UP    ,0)                                  //~v58eM~
    SETCKTX("\x1b[A"   ,UP    ,0)                                  //~v58eM~
    SETCKTX("\x1b[3~"  ,REMOVE,0)                                  //~v58eM~
    SETCKTX("\x1b[2~"  ,INSERT,0)                                  //~v58eM~
    SETCKTX("\x1b[L"   ,INSERT,0|MODX_SCO) //PuTTY SCO                      //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[1~"  ,FIND  ,0)                                  //~v58eM~
#ifdef LNX                                                         //~v58eI~
    SETCKTX("\x1b[H"   ,FIND  ,0)                                  //~v58eM~
    SETCKTX("\x1bOH"   ,FIND  ,0)    //FC4 gnome terminal(find=home)//~v5h0I~
#else                                                              //~v58eI~
//  SETCKTX("\x1b[H"   ,FIND  ,0)  //registered by setupcktx       //~v58eI~
#endif                                                             //~v58eI~
    SETCKTX("\x1b[4~"  ,SELECT,0)                                  //~v58eM~
    SETCKTX("\x1b[F"   ,SELECT,0)                                  //~v58eM~
#ifdef LNX                                                         //~v5h0I~
    SETCKTX("\x1bOF"   ,SELECT,0)   //FC4 gnome-terminal(Select=End)//~v5h0I~
#endif                                                             //~v5h0I~
    SETCKTX("\x1b[5~"  ,PGUP  ,0)                                  //~v58eM~
    SETCKTX("\x1b[I"   ,PGUP  ,0|MODX_SCO) //PuTTY SCO                      //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[6~"  ,PGDN  ,0)                                  //~v58eM~
    SETCKTX("\x1b[G"   ,PGDN  ,0|MODX_SCO) //PuTTY SCO                      //~v5q6I~//~v5qhR~
    SETCKTX("\x1bOP"   ,F1    ,0)                                  //~v58eM~
    SETCKTX("\x1bOQ"   ,F2    ,0)                                  //~v58eM~
    SETCKTX("\x1bOR"   ,F3    ,0)                                  //~v58eM~
    SETCKTX("\x1bOS"   ,F4    ,0)                                  //~v58eM~
    SETCKTX("\x1bOT"   ,F5    ,0)    //PuTTY vt100                 //~v5q6I~
    SETCKTX("\x1bOU"   ,F6    ,0)    //PuTTY vt100                 //~v5q6I~
    SETCKTX("\x1bOV"   ,F7    ,0)    //PuTTY vt100                 //~v5q6I~
    SETCKTX("\x1bOW"   ,F8    ,0)    //PuTTY vt100                 //~v5q6I~
    SETCKTX("\x1bOX"   ,F9    ,0)    //PuTTY vt100                 //~v5q6I~
    SETCKTX("\x1bOY"   ,F10   ,0)    //PuTTY vt100                 //~v5q6I~
    SETCKTX("\x1bOZ"   ,F11   ,0)    //PuTTY vt100                 //~v5q6I~
    SETCKTX("\x1bO["   ,F12   ,0)    //PuTTY vt100                 //~v5q6I~
                                                                   //~v5q6I~
    SETCKTX("\x1b[[A"  ,F1    ,0)                                  //~v58eM~
    SETCKTX("\x1b[[B"  ,F2    ,0)                                  //~v58eM~
    SETCKTX("\x1b[[C"  ,F3    ,0)                                  //~v58eM~
    SETCKTX("\x1b[[D"  ,F4    ,0)                                  //~v58eM~
    SETCKTX("\x1b[[E"  ,F5    ,0)                                  //~v58eM~
                                                                   //~v5q6I~
    SETCKTX("\x1b[11~" ,F1    ,0)                                  //~v58eM~
    SETCKTX("\x1b[12~" ,F2    ,0)                                  //~v58eM~
    SETCKTX("\x1b[13~" ,F3    ,0)                                  //~v58eM~
    SETCKTX("\x1b[14~" ,F4    ,0)                                  //~v58eM~
    SETCKTX("\x1b[15~" ,F5    ,0)                                  //~v58eM~
    SETCKTX("\x1b[17~" ,F6    ,0)                                  //~v58eM~
    SETCKTX("\x1b[18~" ,F7    ,0)                                  //~v58eM~
    SETCKTX("\x1b[19~" ,F8    ,0)                                  //~v58eM~
    SETCKTX("\x1b[20~" ,F9    ,0)                                  //~v58eM~
    SETCKTX("\x1b[21~" ,F10   ,0)                                  //~v58eM~
    SETCKTX("\x1b[23~" ,F11   ,0)                                  //~v58eM~
    SETCKTX("\x1b[24~" ,F12   ,0)                                  //~v58eM~
                                                                   //~v5q6I~
    SETCKTX("\x1b[M"   ,F1    ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[N"   ,F2    ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[O"   ,F3    ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[P"   ,F4    ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[Q"   ,F5    ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[R"   ,F6    ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[S"   ,F7    ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[T"   ,F8    ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[U"   ,F9    ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[V"   ,F10   ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[W"   ,F11   ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
    SETCKTX("\x1b[X"   ,F12   ,0|MODX_SCO)    //PuTTY SCO                   //~v5q6I~//~v5qhR~
#ifdef LNX                                                         //~v70fI~
    SETCKTX("\x1b[E"   ,P5    ,0)   //Center                       //~v70fI~
#endif                                                             //~v70fI~
//shift                                                            //~v58eM~
//  SETCKTX("\x1b[Z"     ,TAB   ,MODX_SHIFT)                       //~v58eM~//~v5qhR~
    SETCKTX("\x1b[Z"     ,TAB   ,MODX_SHIFT|MODX_ZT)               //~v5qhI~
    SETCKTX("\x1b[2C"    ,RIGHT ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[2D"    ,LEFT  ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[2B"    ,DOWN  ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[2A"    ,UP    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[1;2C"  ,RIGHT ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[1;2D"  ,LEFT  ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[1;2B"  ,DOWN  ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[1;2A"  ,UP    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[3;2~"  ,REMOVE,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[2;2~"  ,INSERT,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[2H"    ,FIND  ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[2F"    ,SELECT,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[1;2H"  ,FIND  ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[1;2F"  ,SELECT,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[5;2~"  ,PGUP  ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[6;2~"  ,PGDN  ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1bO2P"    ,F1    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1bO2Q"    ,F2    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1bO2R"    ,F3    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1bO2S"    ,F4    ,MODX_SHIFT)                       //~v58eM~
//*debian                                                          //~v6FeM~
    SETCKTX("\x1b[1;2P"  ,F1    ,MODX_SHIFT)                       //~v6FeM~
    SETCKTX("\x1b[1;2Q"  ,F2    ,MODX_SHIFT)                       //~v6FeM~
    SETCKTX("\x1b[1;2R"  ,F3    ,MODX_SHIFT)                       //~v6FeM~
    SETCKTX("\x1b[1;2S"  ,F4    ,MODX_SHIFT)                       //~v6FeM~
                                                                   //~v6FeI~
    SETCKTX("\x1bO1;2P"  ,F1    ,MODX_SHIFT)                       //~v5nGI~
    SETCKTX("\x1bO1;2Q"  ,F2    ,MODX_SHIFT)                       //~v5nGI~
    SETCKTX("\x1bO1;2R"  ,F3    ,MODX_SHIFT)                       //~v5nGI~
    SETCKTX("\x1bO1;2S"  ,F4    ,MODX_SHIFT)                       //~v5nGI~
    SETCKTX("\x1b[15;2~" ,F5    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[17;2~" ,F6    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[18;2~" ,F7    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[19;2~" ,F8    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[20;2~" ,F9    ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[21;2~" ,F10   ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[23;2~" ,F11   ,MODX_SHIFT)                       //~v58eM~
    SETCKTX("\x1b[24;2~" ,F12   ,MODX_SHIFT)                       //~v58eM~
                                                                   //~v5q6I~
    SETCKTX("\x1b[Y"   ,F1    ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[Z"   ,F2    ,MODX_SHIFT|MODX_Z2)     //PuTTY SCO,active by --Z2//~v5qhR~
    SETCKTX("\x1b[a"   ,F3    ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[b"   ,F4    ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[c"   ,F5    ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[d"   ,F6    ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[e"   ,F7    ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[f"   ,F8    ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[g"   ,F9    ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[h"   ,F10   ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[i"   ,F11   ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[j"   ,F12   ,MODX_SHIFT|MODX_SCO)    //PuTTY SCO          //~v5q6M~//~v5qhR~
//ctrl                                                             //~v58eM~
    SETCKTX("\x1b[5C"    ,RIGHT ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[5D"    ,LEFT  ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[5B"    ,DOWN  ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[5A"    ,UP    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[1;5C"  ,RIGHT ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[1;5D"  ,LEFT  ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[1;5B"  ,DOWN  ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[1;5A"  ,UP    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[3;5~"  ,REMOVE,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[2;5~"  ,INSERT,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[5H"    ,FIND  ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[5F"    ,SELECT,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[1;5H"  ,FIND  ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[1;5F"  ,SELECT,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[5;5~"  ,PGUP  ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[6;5~"  ,PGDN  ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1bO5P"    ,F1    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1bO5Q"    ,F2    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1bO5R"    ,F3    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1bO5S"    ,F4    ,MODX_CONTROL)                     //~v58eM~
//*debian                                                          //~v6FeI~
    SETCKTX("\x1b[1;5P"  ,F1    ,MODX_CONTROL)                     //~v6FeI~
    SETCKTX("\x1b[1;5Q"  ,F2    ,MODX_CONTROL)                     //~v6FeI~
    SETCKTX("\x1b[1;5R"  ,F3    ,MODX_CONTROL)                     //~v6FeI~
    SETCKTX("\x1b[1;5S"  ,F4    ,MODX_CONTROL)                     //~v6FeI~
                                                                   //~v6FeI~
    SETCKTX("\x1b[15;5~" ,F5    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[17;5~" ,F6    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[18;5~" ,F7    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[19;5~" ,F8    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[20;5~" ,F9    ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[21;5~" ,F10   ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[23;5~" ,F11   ,MODX_CONTROL)                     //~v58eM~
    SETCKTX("\x1b[24;5~" ,F12   ,MODX_CONTROL)                     //~v58eM~
                                                                   //~v5q6I~
    SETCKTX("\x1b[k"   ,F1    ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[l"   ,F2    ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[m"   ,F3    ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[n"   ,F4    ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[o"   ,F5    ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[p"   ,F6    ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[q"   ,F7    ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[r"   ,F8    ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[s"   ,F9    ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[t"   ,F10   ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[u"   ,F11   ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
    SETCKTX("\x1b[v"   ,F12   ,MODX_CONTROL|MODX_SCO)    //PuTTY SCO        //~v5q6M~//~v5qhR~
//alt                                                              //~v58eM~
    SETCKTX("\x1b[3C"    ,RIGHT ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[3D"    ,LEFT  ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[3B"    ,DOWN  ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[3A"    ,UP    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[1;3C"  ,RIGHT ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[1;3D"  ,LEFT  ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[1;3B"  ,DOWN  ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[1;3A"  ,UP    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[3;3~"  ,REMOVE,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[2;3~"  ,INSERT,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[3H"    ,FIND  ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[3F"    ,SELECT,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[1;3H"  ,FIND  ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[1;3F"  ,SELECT,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[5;3~"  ,PGUP  ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[6;3~"  ,PGDN  ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1bO3P"    ,F1    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1bO3Q"    ,F2    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1bO3R"    ,F3    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1bO3S"    ,F4    ,MODX_ALT)                         //~v58eM~
//*debian                                                          //~v6FeI~
    SETCKTX("\x1b[1;3P"  ,F1    ,MODX_ALT)                         //+v6FeR~
    SETCKTX("\x1b[1;3Q"  ,F2    ,MODX_ALT)                         //+v6FeR~
    SETCKTX("\x1b[1;3R"  ,F3    ,MODX_ALT)                         //+v6FeR~
    SETCKTX("\x1b[1;3S"  ,F4    ,MODX_ALT)                         //+v6FeR~
                                                                   //~v6FeI~
    SETCKTX("\x1b[15;3~" ,F5    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[17;3~" ,F6    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[18;3~" ,F7    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[19;3~" ,F8    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[20;3~" ,F9    ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[21;3~" ,F10   ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[23;3~" ,F11   ,MODX_ALT)                         //~v58eM~
    SETCKTX("\x1b[24;3~" ,F12   ,MODX_ALT)                         //~v58eM~
//S+Ctrl                                                           //~v6EyI~
    SETCKTX("\x1bO1;6P" ,F1    ,MODX_CONTROL|MODX_SHIFT_REPORT)    //~v6F2R~
    SETCKTX("\x1bO1;6Q" ,F2    ,MODX_CONTROL|MODX_SHIFT_REPORT)    //~v6F2R~
    SETCKTX("\x1bO1;6R" ,F3    ,MODX_CONTROL|MODX_SHIFT_REPORT)    //~v6F2R~
    SETCKTX("\x1bO1;6S" ,F4    ,MODX_CONTROL|MODX_SHIFT_REPORT)    //~v6F2R~
//*debian                                                          //~v6FeI~
    SETCKTX("\x1b[1;6P"  ,F1    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6FeI~
    SETCKTX("\x1b[1;6Q"  ,F2    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6FeI~
    SETCKTX("\x1b[1;6R"  ,F3    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6FeI~
    SETCKTX("\x1b[1;6S"  ,F4    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6FeI~
                                                                   //~v6FeI~
    SETCKTX("\x1b[15;6~" ,F5    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6EyR~
    SETCKTX("\x1b[17;6~" ,F6    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[18;6~" ,F7    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[19;6~" ,F8    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[20;6~" ,F9    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[21;6~" ,F10   ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[23;6~" ,F11   ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[24;6~" ,F12   ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[1;6A"  ,UP    ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[1;6B"  ,DOWN  ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[1;6C"  ,RIGHT ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[1;6D"  ,LEFT  ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[3;6~"  ,REMOVE,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
    SETCKTX("\x1b[2;6~"  ,INSERT,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6F2I~
//*debian                                                          //~v6FeI~
    SETCKTX("\x1b[1;6H"  ,FIND  ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6FeI~
    SETCKTX("\x1b[1;6F"  ,SELECT,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6FeI~
    SETCKTX("\x1b[5;6~"  ,PGUP  ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6FeI~
    SETCKTX("\x1b[6;6~"  ,PGDN  ,MODX_CONTROL|MODX_SHIFT_REPORT)   //~v6FeI~
//S+Alt                                                            //~v6EyI~
    SETCKTX("\x1bO1;4P" ,F1    ,MODX_ALT|MODX_SHIFT_REPORT)        //~v6F2R~
    SETCKTX("\x1bO1;4Q" ,F2    ,MODX_ALT|MODX_SHIFT_REPORT)        //~v6F2R~
    SETCKTX("\x1bO1;4R" ,F3    ,MODX_ALT|MODX_SHIFT_REPORT)        //~v6F2R~
    SETCKTX("\x1bO1;4S" ,F4    ,MODX_ALT|MODX_SHIFT_REPORT)        //~v6F2R~
//*debian                                                          //~v6FeI~
    SETCKTX("\x1b[1;4P"  ,F1    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6FeI~
    SETCKTX("\x1b[1;4Q"  ,F2    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6FeI~
    SETCKTX("\x1b[1;4R"  ,F3    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6FeI~
    SETCKTX("\x1b[1;4S"  ,F4    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6FeI~
                                                                   //~v6FeI~
    SETCKTX("\x1b[15;4~" ,F5    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6EyR~
    SETCKTX("\x1b[17;4~" ,F6    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[18;4~" ,F7    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[19;4~" ,F8    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[20;4~" ,F9    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[21;4~" ,F10   ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[23;4~" ,F11   ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[24;4~" ,F12   ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[1;4A"  ,UP    ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[1;4B"  ,DOWN  ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[1;4C"  ,RIGHT ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[1;4D"  ,LEFT  ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[3;4~"  ,REMOVE,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
    SETCKTX("\x1b[2;4~"  ,INSERT,MODX_ALT|MODX_SHIFT_REPORT)       //~v6F2I~
//*debian                                                          //~v6FeI~
    SETCKTX("\x1b[1;4H"  ,FIND  ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6FeI~
    SETCKTX("\x1b[1;4F"  ,SELECT,MODX_ALT|MODX_SHIFT_REPORT)       //~v6FeI~
    SETCKTX("\x1b[5;4~"  ,PGUP  ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6FeI~
    SETCKTX("\x1b[6;4~"  ,PGDN  ,MODX_ALT|MODX_SHIFT_REPORT)       //~v6FeI~
