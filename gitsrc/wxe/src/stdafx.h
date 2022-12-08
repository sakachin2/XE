//*CID://+vak7R~:                             update#=   21;       //~vak7R~
//vak7:130906 redirect memcpy to memmove when overlaped            //~vak7I~
//            wxe2010\stdafx.h(warning C2732:diffrent linkage option for ustring_memcpy)//~vak7I~
//@@64 120623 64bit                                                //~@@64I~
// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

// Change these values to use different versions
#define WINVER		0x0601
#define _WIN32_WINNT	0x0601
#define _WIN32_IE	0x0700
//#define _RICHEDIT_VER	0x0200  //@@@@2022/11/19                   //~vak7R~
#define _RICHEDIT_VER	0x0500  //@@@@2022/11/19                   //+vak7I~

// This project was generated for VC++ 2005 Express and ATL 3.0 from Platform SDK.
// Comment out this line to build the project with different versions of VC++ and ATL.
//#define _WTL_SUPPORT_SDK_ATL3                                    //~@@64R~

// Support for VS2005 Express & SDK ATL
#ifdef _WTL_SUPPORT_SDK_ATL3
//#define _CRT_SECURE_NO_DEPRECATE  //specify by compile option for ulib/xe//~@@@@R~
  #pragma conform(forScope, off)
  #pragma comment(linker, "/NODEFAULTLIB:atlthunk.lib")
#endif // _WTL_SUPPORT_SDK_ATL3

#include <atlbase.h>

// Support for VS2005 Express & SDK ATL
#ifdef _WTL_SUPPORT_SDK_ATL3
  namespace ATL
  {
	inline void * __stdcall __AllocStdCallThunk()
	{
		return ::HeapAlloc(::GetProcessHeap(), 0, sizeof(_stdcallthunk));
	}

	inline void __stdcall __FreeStdCallThunk(void *p)
	{
		::HeapFree(::GetProcessHeap(), 0, p);
	}
  };
#endif // _WTL_SUPPORT_SDK_ATL3

#include <atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>

#if defined _M_IX86
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
                                                                   //~@@@@R~
                                                                   //~@@@@M~
#include <atlframe.h>                                              //~@@@@M~
#include <atlctrls.h>                                              //~@@@@M~
#include <atldlgs.h>                                               //~@@@@M~
#include <atlctrlw.h>                                              //~@@@@M~
//#include <atlribbon.h>     //atlribbon.h requires Unicode        //~@@@@R~
#include <atlcrack.h>                                              //~@@@@M~
#include <atlgdi.h>                                                //~@@@@M~
#include <atlprint.h>                                              //~@@@@M~
#include <atluser.h> 											//~@@@@R~
#include <atlddx.h>                                                //~@@@@M~
#include <atlmisc.h>                                               //~@@@@M~
                                                                   //~@@@@I~
#include <Windows.h>                                               //~@@@@R~
#include <WinUser.h>                                               //~@@@@R~
#include <ShellAPI.h>                                              //~@@@@R~
#include <Imm.h>                                                   //~@@@@I~
                                                                   //~@@@@I~
#include "mfc.h"                                                   //~@@@@I~
#include <sys/timeb.h>   //for C4627                               //~@@@@I~
//#include "ulib.h"                                                  //~@@64I~//~vak7R~
