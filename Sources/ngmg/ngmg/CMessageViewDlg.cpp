// CMessageViewDlg.cpp : implementation file
//

#include "pch.h"
#include "ngmg.h"
#include "afxdialogex.h"
#include "CMessageViewDlg.h"


// CMessageViewDlg dialog

IMPLEMENT_DYNAMIC(CMessageViewDlg, CDialogEx)

CMessageViewDlg::CMessageViewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_EditMessageView(_T(""))
{

}

CMessageViewDlg::~CMessageViewDlg()
{
}

void CMessageViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_EditMessageView);
}


BEGIN_MESSAGE_MAP(CMessageViewDlg, CDialogEx)
END_MESSAGE_MAP()


// CMessageViewDlg message handlers


BOOL CMessageViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
