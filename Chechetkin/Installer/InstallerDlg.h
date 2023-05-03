
// InstallerDlg.h : header file
//

#pragma once


// CInstallerDlg dialog
class CInstallerDlg : public CDialogEx
{
// Construction
public:
	CInstallerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_INSTALLER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_dir;
	afx_msg void OnBnClickedChooseDir();
	afx_msg void OnBnClickedInstall();
};
