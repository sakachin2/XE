//*CID://+v660R~:                             update#=   51;       //~v5mPR~//~v660R~
//******************************************************
//v660:100325 local EBCDIC translation support                     //~v660I~
//v5mP:080805 EBC translation by ICU for 3270                      //~v5mPI~
//v5ei:041023 ebc<-->sjis dbcs support;xe cont line support        //~v5eiI~
//v5eg:041023 ebc<-->sjis dbcs support;sosi isrt/del/rep option support//~v5egI~
//v5ed:041020 ebc<-->sjis dbcs support                             //~v5edR~
//******************************************************
#define  EBCDBCS_Q       0x426f                                    //~v5edI~
#define  UCVEBC2_DUP2    0x0100
#define  UCVEBC2_DUP3    0x0200
//******************************************************
typedef struct _DUPMAPTBL    {
		 USHORT DMebc;                                             //~v5edI~
		 USHORT DMnonkanji;USHORT DMnec;USHORT DMibm;
				} DUPMAPTBL;
typedef struct _JISNEWOLDTBL {
		 USHORT JSTsjisnew;USHORT JSTebc;
				} JISNEWOLDTBL;
typedef struct _EBCMAPTBL {
		 USHORT EMfrom;USHORT EMto;
				} EBCMAPTBL;
//******************************************************           //~v5ecI~
int ucvebc2gettbl(EBCMAPTBL **Ppe2s,int *Ppe2sctr,                 //~v5ecI~
			      EBCMAPTBL **Pps2e,int *Pps2ectr,                 //~v5ecI~
			      DUPMAPTBL **Ppdup,int *Ppdupctr,                 //~v5ecI~
				  JISNEWOLDTBL **Ppjisnewold,int *Ppnewoldctr);    //~v5ecR~
//******************************************************           //~v5ecI~
int ucvebc2_s2e(int Popt,USHORT Psjis);                            //~v5ecI~
int ucvebc2_e2s(int Popt,USHORT Pebc);                             //~v5ecI~
#define UCVEBC2_E2S   0x0100                                       //~v5ecI~
#define UCVEBC2_S2E   0x0200                                       //~v5ecI~
//******************************************************           //~v5ecI~
int ucvebc2_chkprint(int Popt);                                    //~v5ecR~
//******************************************************           //~v5edI~
int ucvebc2_chkprintnewold(int Popt);                              //~v5edI~
//******************************************************           //~v5edI~
int ucvebc2_chkprintdup(int Popt);                                 //~v5edI~
//******************************************************           //~v5edI~
int ucvebc2_stre2s(int Popt,UCHAR *Pinp,UCHAR *Pout,               //~v5edI~
			int Pinplen,int *Pchklen,int *Poutlen,int Prepchar);   //~v5edI~
//******************************************************           //~v5mPI~
int ucvebc2_strs2e(int Popt,UCHAR *Pinp,UCHAR *Pout,               //~v5edI~
			int Pinplen,int *Pchklen,int *Poutlen,int Prepchar);   //~v5edI~
//******************************************************           //~v5mPI~
int ucvebc2_setso(int Popt,UCHAR *Pinp,UCHAR *Pout,                //~v5mPI~
			int Pinplen,int *Poutlen);                             //~v5mPI~
//******************************************************           //~v5mPI~
int ucvebc2_setsi(int Popt,UCHAR *Pinp,UCHAR *Pout,                //~v5mPI~
			int Pinplen,int *Pchklen,int *Poutlen);                //~v5mPI~
#ifdef UTF8EBCD                                                    //~v660I~
//******************************************************           //~v660I~
int ucvebc2_ebc2asc1dbcsJ(int Popt,UCHAR *Pebc,int Prepch,USHORT *Ppsjis);//+v660R~
#endif                                                             //~v660I~
