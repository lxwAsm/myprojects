// skin2Dlg.h : header file
//

#if !defined(AFX_SKIN2DLG_H__32A402B0_DBEC_469E_9A43_84D828509E8E__INCLUDED_)
#define AFX_SKIN2DLG_H__32A402B0_DBEC_469E_9A43_84D828509E8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSkin2Dlg dialog

class CSkin2Dlg : public CDialog
{
// Construction
public:
	CSkin2Dlg(CWnd* pParent = NULL);	// standard constructor
	TCHAR	filepath[MAX_PATH];
// Dialog Data
	//{{AFX_DATA(CSkin2Dlg)
	enum { IDD = IDD_SKIN2_DIALOG };
	CEdit	m_tipfile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkin2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSkin2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKIN2DLG_H__32A402B0_DBEC_469E_9A43_84D828509E8E__INCLUDED_)
