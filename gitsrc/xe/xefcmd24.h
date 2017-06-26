//*CID://+v77ER~:                             update#=   33;       //+v77ER~
//**************************************************************** //~v13pI~
//*xefcmd24.h                                                      //~v40pR~
//**************************************************************** //~v13pI~
//v77E:080203 FW(C+"["/"]")/IW(A+"["|"]") cmd support              //~v77EI~
//v62f:050314 change matching specification "*= & n "-->"*=Mn"     //~v62fI~
//v62d:050312 matching cmd;find *= col1 col2 & ^* col3 col4        //~v62dI~
//v49b:020623 support *= for not only "(i)x all" but also "(i)find"//~v49bI~
//v498:020617 XX cmd support .a .b                                 //~v498I~
//v40L:010716 add option to "x *= all" of minimum same lineno      //~v40LI~
//v40z:010625 column range support for x =all(same as above)       //~v40zI~
//v40p:010603 add x *= (exclude same as above line)                //~v40pI~
//**************************************************************** //~v13pI~
int fcmdxallsame(PUCLIENTWE Ppcw,PUFILEH Ppfh,int Pcasesw,         //~v40LR~
				SHORT Prange1,SHORT Prange2,int Sminsame);         //~v40LI~
//**************************************************************** //~v498I~
int fcmdgetabplh(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH *Pplhs,PULINEH *Pplhe,int Popt);//~v498I~
                                                                   //~v49bI~
//**************************************************************** //~v49bI~
int fcmdsamesrch(PUCLIENTWE Ppcw,PUFILEH Ppfh,PULINEH Pplh,PULINEH Pplhend,//~v49bR~
					PULINEH *Ppplhs,PULINEH *Ppplhe,               //~v49bI~
        			int Pcasesw,SHORT Prange1,SHORT Prange2,int Pminsame,//~v49bI~
					int Psubcmdid,LONG *Psamelinectr,int Pexcludesw);//~v49bI~
//**************************************************************** //~v62dI~
int fcmdsamematch(PUCLIENTWE Ppcw,PUFILEH Ppfh,PUFILEH Ppfh2,PULINEH Pplh,PULINEH Pplhend,//~v62dI~
        		int Pcasesw,int Pexcludesw,SHORT Prange1,SHORT Prange2,int Pkeypos);//~v62fR~
//**************************************************************** //~v62dI~
//PUFILEH fcmdget2ndpfh(PUCLIENTWE Ppcw);                          //~v62fR~
PUFILEH fcmdget2ndpfh(PUCLIENTWE Ppcw,char *Pparm);                //~v62fI~
//**************************************************************** //~v77EI~
int fcmdsrchword(PUCLIENTWE Ppcw,int Pswcase,int Pdest);           //~v77EI~
