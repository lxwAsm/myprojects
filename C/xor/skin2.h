// skin2.h : main header file for the SKIN2 application
//

#if !defined(AFX_SKIN2_H__FFA0591D_34E0_42BB_B311_3063B6318167__INCLUDED_)
#define AFX_SKIN2_H__FFA0591D_34E0_42BB_B311_3063B6318167__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSkin2App:
// See skin2.cpp for the implementation of this class
//

class CSkin2App : public CWinApp
{
public:
	CSkin2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkin2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSkin2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKIN2_H__FFA0591D_34E0_42BB_B311_3063B6318167__INCLUDED_)
