//*************************************************************
//*udamt.h                                                         //~8211R~
//*************************************************************
typedef PINSTTBL MAPT,*PMAPT,*GRPT,**PGRPT;                        //~8213R~
typedef struct _GRPPT {                                            //~8213R~
						GRPT   *DAGpgt;                            //~8213R~
                    	int    DAGstart;                           //~8213R~
                    	int    DAGctr;                             //~8213R~
                     } GRPPT,*PGRPPT;                              //~8213R~
typedef struct _MAPPT {                                            //~8213R~
						MAPT   *DAMpmt;                            //~8213R~
                    	int    DAMstart;                           //~8213R~
                    	int    DAMctr;                             //~8213R~
                     } MAPPT,*PMAPPT;                              //~8213R~
//*************************************************************    //~8213I~
#define  MAPGEN(OP)	   &Sid_##OP    //define a ptr                 //~8213R~
//*************************************************************    //~8211I~
int udamy(void);                                                   //~8213R~
