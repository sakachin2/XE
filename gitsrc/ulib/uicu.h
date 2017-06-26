//*CID://+v6c3R~:                             update#=   51;       //~v6c3R~
//******************************************************           //~v5mPI~
//v6c3:120120 u_setDataDirectory is not effective on android3/4?; try udata_setFileAcess//~v6c3I~
//v5nc:081009 (LNX)MinGW compile                                   //~v5ncI~
//v5n2:080824 Linux ICU spoort                                     //~v5n2I~
//v5mP:080805 EBC translation by ICU for 3270                      //~v5mPI~
//******************************************************           //~v5mPI~
//******************************************************           //~v5mPI~
#ifdef WCSUPP                                                      //~v5mPR~
    #ifdef MGW32                                                   //~v5ncI~
	    #include <stdint.h>	//int32_t etc                          //~v5ncI~
    #endif                                                         //~v5ncI~
//  #ifdef W32                                                     //~v5n2R~
	    #include <unicode/ucnv.h>                                  //~v5mPR~
        #ifdef ARM                                                 //+v6c3I~
	    	#include <unicode/udata.h>                             //+v6c3R~
      	#endif                                                     //+v6c3I~
//  #endif                                                         //~v5n2R~
#endif                                                             //~v5mPI~
