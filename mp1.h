// mp1.h : main header file for the MP1 application
//

#if !defined(AFX_MP1_H__49B10261_3E1E_48CB_B2B9_9A7D3EA4626C__INCLUDED_)
#define AFX_MP1_H__49B10261_3E1E_48CB_B2B9_9A7D3EA4626C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMp1App:
// See mp1.cpp for the implementation of this class
//

class CMp1App : public CWinApp
{
public:
	CMp1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMp1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMp1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP1_H__49B10261_3E1E_48CB_B2B9_9A7D3EA4626C__INCLUDED_)
