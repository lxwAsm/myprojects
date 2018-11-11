// skin2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "skin2.h"
#include "skin2Dlg.h"
#include "stdio.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using	namespace	std;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkin2Dlg dialog

CSkin2Dlg::CSkin2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSkin2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSkin2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSkin2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSkin2Dlg)
	DDX_Control(pDX, IDC_EDIT1, m_tipfile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSkin2Dlg, CDialog)
	//{{AFX_MSG_MAP(CSkin2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkin2Dlg message handlers

LPWSTR show_char(char *pbyte, int len)
{
	LPWSTR lpw;
	int wlen;
	wlen = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pbyte, len + 1, NULL, 0);
	lpw = new WCHAR[wlen];
	MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pbyte, len + 1, lpw, wlen);

	return lpw;

}
BOOL CSkin2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	//SkinH_Init(m_hInstance);
	TCHAR	path[MAX_PATH]={0};
	GetCurrentDirectory(MAX_PATH,path);
	CString p = path;
	p += _T("\\skinh1.she");
	//MessageBox(path);
	//CString	file = _T("skinh1.she");
	SkinH_AttachEx(p,0);
	AfxGetMainWnd()->SetWindowPos(&CWnd::wndTopMost,0,0,0,0,SWP_NOSIZE | SWP_NOMOVE);
	//-----------------------
	memset(filepath,0,MAX_PATH);
	SetWindowPos(&CWnd::wndTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	//if(SkinH_AttachEx("D:\\vs\\MSDev98\\MyProjects\\skin2\\Debug\\QQ2008.she",NULL))
	//	MessageBoxA(0,"success",NULL);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSkin2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSkin2Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSkin2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSkin2Dlg::OnDropFiles(HDROP hDropInfo) 
{
	// TODO: Add your message handler code here and/or call default
	//char szFilePath[200] = {0}; //保存文件路径 
	DragQueryFile(hDropInfo,0,filepath,sizeof(filepath)); //获取文件路径
	(this->GetDlgItem(IDC_STATIC))->SetWindowText(filepath);
	//m_tipfile.SetWindowText(filepath);
	DragFinish(hDropInfo); 
	//SkinH_AttachEx((char*)show_char(szFilePath,strlen(szFilePath)),0);
	CDialog::OnDropFiles(hDropInfo);
}

void CSkin2Dlg::OnOK() 
{
	
	char	*key = new char[1024];
	memset(key,0,1024);
	GetDlgItemTextA(this->m_hWnd, IDC_EDIT1, key, 1024);
	int		size = strlen(key);
	if(lstrlenW(filepath) &&  size)
	{
		CFile	f(filepath,CFile::modeRead);
		CString		newfile = filepath;
		newfile+=_T(".enc");
		CFile	fenc(newfile, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
		if(!fenc || !f)
		{
			MessageBox(_T("open file failed"));//检测
			return;
		}
		int	size = f.GetLength();
		char	*buffer = new char[size];
		f.Read(buffer,size);
		for (int i = 0; i < size;i++)
		{
			buffer[i] ^= key[(i++) % size];
		}
		fenc.Write(buffer, size);
		f.Close();
		fenc.Close();
		MessageBox(newfile+_T(" encryption success!"));
	
	}else{
		MessageBox(_T("input error"));
	}
	
	delete []key;
	//CDialog::OnOK();
}
