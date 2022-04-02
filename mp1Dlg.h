// mp1Dlg.h : header file
//

#if !defined(AFX_MP1DLG_H__A71B91ED_BE17_46F5_9325_D88C717CEE4D__INCLUDED_)
#define AFX_MP1DLG_H__A71B91ED_BE17_46F5_9325_D88C717CEE4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMp1Dlg dialog
#include "mc.h"

class CMp1Dlg : public CDialog
{
// Construction
public:
	CMp1Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMp1Dlg)
	enum { IDD = IDD_MP1_DIALOG };
	//CString	m_t;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMp1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
private:
	CMyPlayerControl m_c;
	CString m_s;
	CSliderCtrl m_p;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMp1Dlg)
	
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOpenBtn();
	afx_msg void OnPlayBtn();
	afx_msg void OnPauseBtn();
	afx_msg void OnStopBtn();
	afx_msg void OnTimer(UINT nIDEvent);
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MP1DLG_H__A71B91ED_BE17_46F5_9325_D88C717CEE4D__INCLUDED_)
