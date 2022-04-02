// mp1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "mp1.h"
#include "mp1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CMp1Dlg dialog

CMp1Dlg::CMp1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMp1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMp1Dlg)
	//m_t = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMp1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMp1Dlg)
	DDX_Control(pDX, IDC_PROCESS, m_p);
	//DDX_Text(pDX, IDC_timu, m_t);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMp1Dlg, CDialog)
	//{{AFX_MSG_MAP(CMp1Dlg)
	
	ON_WM_TIMER()
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_BTN, OnOpenBtn)
	ON_BN_CLICKED(IDC_PLAY_BTN, OnPlayBtn)
	ON_BN_CLICKED(IDC_PAUSE_BTN, OnPauseBtn)
	ON_BN_CLICKED(IDC_STOP_BTN, OnStopBtn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMp1Dlg message handlers

BOOL CMp1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	//m_p.SetRange(0,100);
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
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMp1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMp1Dlg::OnPaint() 
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
HCURSOR CMp1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMp1Dlg::OnOpenBtn() 
{
	// TODO: Add your control notification handler code here
	CString strFilter("MP3 Files (*.mp3)I*.mp3||");
	CFileDialog OpenDlg(TRUE,
//���ɴ򿪶Ի���
						NULL,
						NULL,
						OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,strFilter);
	int nFlags =OpenDlg.DoModal(); //ͨ���򿪶Ի���ѡ��MP3�����ļ�
	if (nFlags==IDOK)
	{//�û��������ǡ��򿪡���Ŧ,���ļ�·����������Ա����m_strFileName ����
		m_s=OpenDlg.GetPathName();
		//m_t=OpenDlg.GetPathName();
//��MCI�豸,�����豸�����ѡ�е��ļ�ʹ��
		m_c.Open(m_s);
	}
}

void CMp1Dlg::OnPlayBtn() 
{
	// TODO: Add your control notification handler code here
	//�õ���Ŀ����
	DWORD cdlen = m_c.GetLength(MCI_STATUS_LENGTH);
	m_c.Play();
//���ò���
	m_p.SetRange(0,cdlen);
//���ý�������Χ
	SetTimer(0,100,NULL);
//���ö�ʱ��

}

void CMp1Dlg::OnPauseBtn() 
{
	// TODO: Add your control notification handler code here
	m_c.Pause();
}

void CMp1Dlg::OnStopBtn() 
{
	// TODO: Add your control notification handler code here
	m_c.Stop();
	m_p.SetPos(0);
//���ý�����λ��
	//CDialog::OnTimer(nIDEvent);
	KillTimer(0);
}

void CMp1Dlg::OnTimer(UINT nIDEvent)
{
	DWORD cdf=m_c.GetLength(MCI_STATUS_POSITION);
	m_p.SetPos(cdf);
//���ý�����λ��
	CDialog::OnTimer(nIDEvent);
//��������Timer
}

