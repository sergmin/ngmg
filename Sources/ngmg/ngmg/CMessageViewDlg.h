#pragma once
#include "afxdialogex.h"


// CMessageViewDlg dialog

class CMessageViewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMessageViewDlg)

public:
	CMessageViewDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMessageViewDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_EditMessageView;
	virtual BOOL OnInitDialog();
};
