//CID://+v105R~:                                                   //~v105I~
//******************************************************           //~v105I~
//*udpmilib.h function lack from libc                              //~v105I~
//*************************************************************    //~v105I~
//v105:971026 (GCC)lfn support                                     //~v105I~
//           -findfirst/findnext lfn support                       //~v105I~
//**********************************************************************//~v105I~
//!udpmifindfirst over djgpp findfirst                             //~v105I~
// find first:return FILEFINDBUF3 from ffblk and ffblklfn(short name)//~v105I~
// parm1  :file name                                               //~v105I~
// parm2  :HDIR ptr,if no contention,specify 0.for dos specify always 0//~v105I~
// parm3  :search file attribute                                   //~v105I~
// parm4  :found file info                                         //~v105I~
// return :r.c                                                     //~v105I~
//**********************************************************************//~v105I~
unsigned udpmifindfirst(char *Ppfname,HDIR *Pphdir,unsigned int Pattr,//~v105I~
						FILEFINDBUF3 *Ppfstat3);                   //~v105I~
//**********************************************************************//~v105I~
//!udpmifindnext over djgpp findnext                               //~v105I~
// find next :return FILEFINDBUF3 from ffblk and ffblklfn(short name)//~v105I~
// parm1  :HDIR specified at findfirst. for dos specify always 0   //~v105I~
// parm2  :found file info                                         //~v105I~
// return :r.c  0:found 4:no more file                             //~v105I~
//**********************************************************************//~v105I~
unsigned udpmifindnext(HDIR Phdir,FILEFINDBUF3 *Ppfstat3);         //+v105R~
