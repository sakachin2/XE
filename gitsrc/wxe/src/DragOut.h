//*CID://+vbCER~:                             update#=    8;       //+vbCER~
//*******************************************************************************//~@@@@R~
//* drag out file using CF_HDROP data                              //~@@@@I~
//*******************************************************************************//~@@@@I~
//vbCE:160826 (W64)compiler warning                                //+vbCEI~
/*******************************************************************************
 * Copyright 2002, 2003, 2004, 2005, 2006, 2012 Kent Stork
 *
 * dragsrc.cpp is part of Osiva.
 *
 * Osiva is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * Osiva is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * Osiva.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/


///////////////////////////////////////////////////////////////////////////
//
// dragsrc.cpp
//
// Implements the minimum COM necessary to provide a drop source
// using the Win32 API (no MFC.) Provides a single global to 
// initiate the drag: 
//
//    int drag_file_out (const char *filename);
//
//    Returns:
//
//       1 = File copied
//       2 = File moved
//       0 = Cancelled or something like that
//
// Don't forget to OleInitialize (NULL)
//
// A test application is included at the bottom.
// To compile as a test application define TESTING_DRAGSRC and
// add this file to an empty Windows 32 Application project.
//


#include <windows.h>
#include <shlobj.h>       // DROPFILES declaration
#include <crtdbg.h>       // MSVC function: _CrtDumpMemoryLeaks

#include <vector>

using namespace std;

int drag_file_out (const char *filename);


///////////////////////////////////////////////////////////////////////////////
//
// DropSource::
//

class DropSource : public IDropSource {

public:

  DWORD m_dwRef;
  DWORD m_dwButtonCancel;
  DWORD m_dwButtonDrop;

  DropSource();
  
  HRESULT STDMETHODCALLTYPE QueryInterface(
    REFIID riid,
    void **ppvObject
    );  
  
  ULONG STDMETHODCALLTYPE AddRef (void);
  
  ULONG STDMETHODCALLTYPE Release (void);
  
  HRESULT STDMETHODCALLTYPE QueryContinueDrag(
    BOOL fEscapePressed,
    DWORD grfKeyState
    );
  
  HRESULT STDMETHODCALLTYPE GiveFeedback(
    DWORD dwEffect
    );
  
};

      ////////////////////
//////   DropSource
    ///////////////////////////////

DropSource::
DropSource ()
{
  m_dwRef = 0;

  // opposite button cancels drag operation
  m_dwButtonCancel = 0;
  m_dwButtonDrop = 0;
  if (GetKeyState(VK_LBUTTON) < 0)
  {
    m_dwButtonDrop |= MK_LBUTTON;
    m_dwButtonCancel |= MK_RBUTTON;
  }
  else if (GetKeyState(VK_RBUTTON) < 0)
  {
    m_dwButtonDrop |= MK_RBUTTON;
    m_dwButtonCancel |= MK_LBUTTON;
  }  
}

      ////////////////////
//////   DropSource
    ///////////////////////////////

ULONG DropSource::
AddRef() 
{ 
  return ++m_dwRef;
}

      ////////////////////
//////   DropSource
    ///////////////////////////////

ULONG DropSource::
Release() 
{ 
  if (--m_dwRef == 0)
  {
    delete this;
    return 0;
  }
  return m_dwRef;
}

      ////////////////////
//////   DropSource
    ///////////////////////////////

HRESULT DropSource::
QueryInterface(REFIID iid, void FAR* FAR* ppvObj)
{
  if (iid == IID_IUnknown || iid == IID_IDropSource)
  {
    *ppvObj = this;
    AddRef();
    return NOERROR;
  }
  return ResultFromScode(E_NOINTERFACE);
}

      ////////////////////
//////   DropSource
    ///////////////////////////////

HRESULT DropSource::
QueryContinueDrag(BOOL bEscapePressed, DWORD dwKeyState)
{

	if (bEscapePressed || (dwKeyState & m_dwButtonCancel) != 0)
		return DRAGDROP_S_CANCEL;

	if ((dwKeyState & m_dwButtonDrop) == 0)
		return DRAGDROP_S_DROP;

	return S_OK;
}

      ////////////////////
//////   DropSource
    ///////////////////////////////

HRESULT DropSource::
GiveFeedback (DWORD dwEffect)
{
    return DRAGDROP_S_USEDEFAULTCURSORS;
}


///////////////////////////////////////////////////////////////////////////////
//
// EnumFORMATETC::
//

class EnumFORMATETC : public IEnumFORMATETC
{
   private:
     ULONG           m_cRefCount;
     vector<FORMATETC>  m_pFmtEtc;
     int           m_iCur;

   public:
     EnumFORMATETC(const vector<FORMATETC>& ArrFE);
	 EnumFORMATETC(const vector<FORMATETC*>& ArrFE);

     EnumFORMATETC ();
     void add (const FORMATETC &);

     //IUnknown members
     STDMETHOD(QueryInterface)(REFIID, void FAR* FAR*);
     STDMETHOD_(ULONG, AddRef)(void);
     STDMETHOD_(ULONG, Release)(void);

     //IEnumFORMATETC members
     STDMETHOD(Next)(ULONG, LPFORMATETC, ULONG FAR *);
     STDMETHOD(Skip)(ULONG);
     STDMETHOD(Reset)(void);
     STDMETHOD(Clone)(IEnumFORMATETC FAR * FAR*);
};


      ////////////////////
//////   EnumFORMATETC
    ///////////////////////////////

EnumFORMATETC::
EnumFORMATETC(const vector<FORMATETC>& ArrFE):
m_cRefCount(0),m_iCur(0)
{
// for(int i = 0; i < ArrFE.size(); ++i)                           //~@@@@R~
   for(int i = 0; i < (int)ArrFE.size(); ++i)                      //~@@@@I~
		m_pFmtEtc.push_back(ArrFE[i]);
}

EnumFORMATETC::
EnumFORMATETC(const vector<FORMATETC*>& ArrFE):
m_cRefCount(0),m_iCur(0)
{
// for(int i = 0; i < ArrFE.size(); ++i)                           //~@@@@R~
   for(int i = 0; i < (int)ArrFE.size(); ++i)                      //~@@@@I~
		m_pFmtEtc.push_back(*ArrFE[i]);
}

EnumFORMATETC::
EnumFORMATETC():
m_cRefCount(0),m_iCur(0)
{
}

void EnumFORMATETC::
add (const FORMATETC &fmtetc)
{
  m_pFmtEtc.push_back(fmtetc);
}

      ////////////////////
//////   EnumFORMATETC
    ///////////////////////////////

STDMETHODIMP  EnumFORMATETC::
QueryInterface(REFIID refiid, void FAR* FAR* ppv)
{
   *ppv = NULL;
   if (IID_IUnknown==refiid || IID_IEnumFORMATETC==refiid)
             *ppv=this;

    if (*ppv != NULL)
    {
        ((LPUNKNOWN)*ppv)->AddRef();
        return S_OK;
    }
    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) EnumFORMATETC::
AddRef(void)
{
   return ++m_cRefCount;
}

STDMETHODIMP_(ULONG) EnumFORMATETC::
Release(void)
{
   long nTemp = --m_cRefCount;
   if(nTemp == 0)
     delete this;

   return nTemp; 
}

      ////////////////////
//////   EnumFORMATETC
    ///////////////////////////////

STDMETHODIMP EnumFORMATETC::
Next( ULONG celt,LPFORMATETC lpFormatEtc, ULONG FAR *pceltFetched)
{
   if(pceltFetched != NULL)
   	   *pceltFetched=0;
	
   ULONG cReturn = celt;

// if(celt <= 0 || lpFormatEtc == NULL || m_iCur >= m_pFmtEtc.size())//~@@@@R~
   if(celt <= 0 || lpFormatEtc == NULL || m_iCur >= (int)m_pFmtEtc.size())//~@@@@I~
      return S_FALSE;

   if(pceltFetched == NULL && celt != 1) // pceltFetched can be NULL only for 1 item request
      return S_FALSE;

//  while (m_iCur < m_pFmtEtc.size() && cReturn > 0)               //~@@@@R~
    while (m_iCur < (int)m_pFmtEtc.size() && cReturn > 0)          //~@@@@I~
	{
		*lpFormatEtc++ = m_pFmtEtc[m_iCur++];
		--cReturn;
	}
	if (pceltFetched != NULL)
		*pceltFetched = celt - cReturn;

    return (cReturn == 0) ? S_OK : S_FALSE;
}

      ////////////////////
//////   EnumFORMATETC
    ///////////////////////////////
   
STDMETHODIMP EnumFORMATETC::
Skip(ULONG celt)
{
//	if((m_iCur + int(celt)) >= m_pFmtEtc.size())                   //~@@@@R~
  	if((m_iCur + int(celt)) >= (int)m_pFmtEtc.size())              //~@@@@I~
		return S_FALSE;
	m_iCur += celt;
	return S_OK;
}
      ////////////////////
//////   EnumFORMATETC
    ///////////////////////////////

STDMETHODIMP EnumFORMATETC::
Reset(void)
{
   m_iCur = 0;
   return S_OK;
}

      ////////////////////
//////   EnumFORMATETC
    ///////////////////////////////
               
STDMETHODIMP EnumFORMATETC::
Clone(IEnumFORMATETC FAR * FAR*ppCloneEnumFormatEtc)
{
  if(ppCloneEnumFormatEtc == NULL)
      return E_POINTER;
      
  EnumFORMATETC *newEnum = new EnumFORMATETC(m_pFmtEtc);
  if(newEnum ==NULL)
		return E_OUTOFMEMORY;  	
  newEnum->AddRef();
  newEnum->m_iCur = m_iCur;
  *ppCloneEnumFormatEtc = newEnum;
  return S_OK;
}


///////////////////////////////////////////////////////////////////////////////
//
// DataObject::
//

class DataObject : public IDataObject {
    
  DWORD m_dwRef;
  HGLOBAL m_hglobal;

public:

  vector<FORMATETC> m_vfmtetc;

  DataObject();
  ~DataObject();

  HRESULT STDMETHODCALLTYPE QueryInterface(
    REFIID riid,
    void **ppvObject
    );   
  ULONG STDMETHODCALLTYPE AddRef (void);
  ULONG STDMETHODCALLTYPE Release (void);
   
  void set_hglobal (HGLOBAL hglobal);

  HRESULT STDMETHODCALLTYPE GetData(
    FORMATETC * pFormatetc,
    STGMEDIUM * pmedium
    );
    
  HRESULT STDMETHODCALLTYPE GetDataHere(
    FORMATETC * pFormatetc,
    STGMEDIUM * pmedium
    ) { return E_NOTIMPL; }
  
  HRESULT STDMETHODCALLTYPE QueryGetData(
    FORMATETC * pFormatetc
    );
  
  HRESULT STDMETHODCALLTYPE GetCanonicalFormatEtc(
    FORMATETC * pFormatetcIn,
    FORMATETC * pFormatetcOut 
    ){ return E_NOTIMPL; }
  
  HRESULT STDMETHODCALLTYPE SetData(
    FORMATETC * pFormatetc,
    STGMEDIUM * pmedium,
    BOOL fRelease
    ){ return E_NOTIMPL; }
  
  HRESULT STDMETHODCALLTYPE EnumFormatEtc(
    DWORD dwDirection,
    IEnumFORMATETC ** ppenumFormatetc
    );
  
  HRESULT STDMETHODCALLTYPE DAdvise(
    FORMATETC * pFormatetc,
    DWORD advf,
    IAdviseSink * pAdvSink,
    DWORD * pdwConnection 
    ){ return E_NOTIMPL; }
  
  HRESULT STDMETHODCALLTYPE DUnadvise(
    DWORD dwConnection
    ){ return E_NOTIMPL; }
   
  HRESULT STDMETHODCALLTYPE EnumDAdvise(
    IEnumSTATDATA ** ppenumAdvise
    ){ return E_NOTIMPL; }
  
  
};

      ////////////////////
//////   DataObject
    ///////////////////////////////

DataObject::
DataObject ()
{
  m_dwRef = 0;
  m_hglobal = NULL;
}

DataObject::
~DataObject ()
{
  GlobalFree (m_hglobal);
}

      ////////////////////
//////   DataObject
    ///////////////////////////////

ULONG DataObject::
AddRef() 
{ 
  return ++m_dwRef;
}

      ////////////////////
//////   DataObject
    ///////////////////////////////

ULONG DataObject::
Release() 
{ 
  if (--m_dwRef == 0)
  {
    delete this;
    return 0;
  }
  return m_dwRef;
}

      ////////////////////
//////   DataObject
    ///////////////////////////////

HRESULT DataObject::
QueryInterface(REFIID iid, void FAR* FAR* ppvObj)
{
  if (iid == IID_IUnknown || iid == IID_IDataObject)
  {
    *ppvObj = this;
    AddRef();
    return NOERROR;
  }
  return ResultFromScode(E_NOINTERFACE);
}

      ////////////////////
//////   DataObject
    ///////////////////////////////

STDMETHODIMP DataObject::
EnumFormatEtc(
   /* [in] */ DWORD dwDirection,
   /* [out] */ IEnumFORMATETC __RPC_FAR *__RPC_FAR *ppenumFormatEtc)
{ 
	if(ppenumFormatEtc == NULL)
      return E_POINTER;

	*ppenumFormatEtc=NULL;
	switch (dwDirection)
    {
      case DATADIR_GET:
         *ppenumFormatEtc= new EnumFORMATETC (m_vfmtetc);
		 if(*ppenumFormatEtc == NULL)
			 return E_OUTOFMEMORY;
         (*ppenumFormatEtc)->AddRef(); 
         break;
      
	  case DATADIR_SET:
      default:
		 return E_NOTIMPL;
         break;
    }

   return S_OK;
}

      ////////////////////
//////   DataObject
    ///////////////////////////////

HRESULT DataObject::
GetData(FORMATETC * pFormatetc, STGMEDIUM * pmedium)
{ 

  if (pFormatetc->cfFormat != CF_HDROP ||
    pFormatetc->tymed != TYMED_HGLOBAL)
    return E_NOTIMPL;

//int so_buff = GlobalSize (m_hglobal);                            //+vbCER~
  int so_buff = (int)GlobalSize (m_hglobal);                       //+vbCEI~
  HGLOBAL hglobal =
	  GlobalAlloc (GMEM_SHARE | GHND | GMEM_ZEROINIT, so_buff);
  char *dp = (char *)GlobalLock (hglobal);
  char *sp = (char *)GlobalLock (m_hglobal);
  memcpy (dp, sp, so_buff);
  GlobalUnlock (sp);
  GlobalUnlock (dp);

  pmedium->hGlobal = hglobal;
  pmedium->tymed = TYMED_HGLOBAL;
  pmedium->pUnkForRelease = NULL;

  return S_OK; 
}

      ////////////////////
//////   DataObject
    ///////////////////////////////

HRESULT DataObject::
QueryGetData(FORMATETC * pFormatetc)
{
  switch (pFormatetc->cfFormat) {
  case CF_HDROP:
    return S_OK;
  default:
    break;
  }
  return E_NOTIMPL;  
}

      ////////////////////
//////   DataObject
    ///////////////////////////////

void DataObject::
set_hglobal (HGLOBAL hglobal)
{
  m_hglobal = hglobal;
}
