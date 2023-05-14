// CTabConnect.cpp : implementation file
//

#include "pch.h"
#include "Resource.h"
#include "afxdialogex.h"
#include "CTabConnect.h"
#include "ngmgDlg.h"


// CTabConnect dialog

IMPLEMENT_DYNAMIC(CTabConnect, CDialogEx)

CTabConnect::CTabConnect(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TABCONNECT, pParent)
	, m_EditConnect1(_T(""))
	, m_EditConnect2(_T(""))
	, m_EditConnect3(_T(""))
	, m_EditConnect21(_T(""))
	, m_EditConnect22(_T(""))
	, m_EditConnect23(_T(""))
	, m_StringState1(_T("Не подключено"))
	, m_StringState2(_T("Не подключено"))
{
}

CTabConnect::~CTabConnect()
{
}

void CTabConnect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOCONNECT1, m_ComboConnect1);
	DDX_Control(pDX, IDC_COMBOCONNECT2, m_ComboConnect2);
	DDX_Control(pDX, IDC_COMBOCONNECT3, m_ComboConnect3);
	DDX_Control(pDX, IDC_COMBOCONNECT4, m_ComboConnect4);
	DDX_Control(pDX, IDC_COMBOCONNECT5, m_ComboConnect5);
	DDX_Control(pDX, IDC_COMBOCONNECT6, m_ComboConnect6);
	DDX_Text(pDX, IDC_EDIT1, m_EditConnect1);
	DDX_Control(pDX, IDC_EDIT1, m_EditConnectControl1);
	DDX_Text(pDX, IDC_EDIT2, m_EditConnect2);
	DDX_Text(pDX, IDC_EDIT3, m_EditConnect3);
	DDX_Control(pDX, IDC_EDIT2, m_EditConnectControl2);
	DDX_Control(pDX, IDC_EDIT3, m_EditConnectControl3);
	DDX_Control(pDX, IDC_BUTTON1, m_ButtonControl1);
	DDX_Control(pDX, IDC_STATIC_CONNECT_STATE1, m_StaticControl1);
	DDX_Text(pDX, IDC_EDIT7, m_StringState1);

	DDX_Control(pDX, IDC_COMBOCONNECT7, m_ComboConnect21);
	DDX_Control(pDX, IDC_COMBOCONNECT8, m_ComboConnect22);
	DDX_Control(pDX, IDC_COMBOCONNECT9, m_ComboConnect23);
	DDX_Control(pDX, IDC_COMBOCONNECT10, m_ComboConnect24);
	DDX_Control(pDX, IDC_COMBOCONNECT11, m_ComboConnect25);
	DDX_Control(pDX, IDC_COMBOCONNECT12, m_ComboConnect26);
	DDX_Text(pDX, IDC_EDIT4, m_EditConnect21);
	DDX_Control(pDX, IDC_EDIT4, m_EditConnectControl21);
	DDX_Text(pDX, IDC_EDIT5, m_EditConnect22);
	DDX_Text(pDX, IDC_EDIT6, m_EditConnect23);
	DDX_Control(pDX, IDC_EDIT5, m_EditConnectControl22);
	DDX_Control(pDX, IDC_EDIT6, m_EditConnectControl23);
	DDX_Control(pDX, IDC_BUTTON2, m_ButtonControl2);
	DDX_Control(pDX, IDC_STATIC_CONNECT_STATE2, m_StaticControl2);
	DDX_Text(pDX, IDC_EDIT8, m_StringState2);
}


BEGIN_MESSAGE_MAP(CTabConnect, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBOCONNECT1, &CTabConnect::OnCbnSelchangeComboconnect1)
	ON_CBN_SELCHANGE(IDC_COMBOCONNECT7, &CTabConnect::OnCbnSelchangeComboconnect2)
	ON_BN_CLICKED(IDC_BUTTON1, &CTabConnect::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTabConnect::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTabConnect message handlers


BOOL CTabConnect::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	m_ComboConnect1.AddString(L"Не выбрано");
	m_ComboConnect1.AddString(L"RS232");
	m_ComboConnect1.AddString(L"UDP");


	m_ComboConnect2.AddString(L"Не выбрано");
	for (size_t i = 1; i <= 12; i++)
	{
		CString str;
		str.Format(L"%d", i);
		m_ComboConnect2.AddString(str);
	}
	m_ComboConnect3.AddString(L"Не выбрано");
	for (size_t i = 4; i <= 8; i++)
	{
		CString str;
		str.Format(L"%d", i);
		m_ComboConnect3.AddString(str);
	}
	m_ComboConnect4.AddString(L"Не выбрано");
	m_ComboConnect4.AddString(L"0");
	m_ComboConnect4.AddString(L"1");

	m_ComboConnect5.AddString(L"Не выбрано");
	m_ComboConnect5.AddString(L"1");
	m_ComboConnect5.AddString(L"1.5");
	m_ComboConnect5.AddString(L"2");
	
	m_ComboConnect6.AddString(L"Не выбрано");
	m_ComboConnect6.AddString(L"нет");
	m_ComboConnect6.AddString(L"аппаратное");
	m_ComboConnect6.AddString(L"Xon/Xoff");

	m_ComboConnect1.SetCurSel(m_ComboConnect1.FindString(0, L"Не выбрано"));
	m_ComboConnect2.SetCurSel(m_ComboConnect2.FindString(0, L"Не выбрано"));
	m_ComboConnect3.SetCurSel(m_ComboConnect3.FindString(0, L"Не выбрано"));
	m_ComboConnect4.SetCurSel(m_ComboConnect4.FindString(0, L"Не выбрано"));
	m_ComboConnect5.SetCurSel(m_ComboConnect5.FindString(0, L"Не выбрано"));
	m_ComboConnect6.SetCurSel(m_ComboConnect6.FindString(0, L"Не выбрано"));

	m_ComboConnect1.UpdateData();
	m_ComboConnect2.UpdateData();
	m_ComboConnect3.UpdateData();
	m_ComboConnect4.UpdateData();
	m_ComboConnect5.UpdateData();
	m_ComboConnect6.UpdateData();


	m_ComboConnect2.EnableWindow(FALSE);
	m_ComboConnect3.EnableWindow(FALSE);
	m_ComboConnect4.EnableWindow(FALSE);
	m_ComboConnect5.EnableWindow(FALSE);
	m_ComboConnect6.EnableWindow(FALSE);

	m_EditConnect1 = "75 - 128000";
	m_EditConnect2 = "0000.0000.0000.0000";
	m_EditConnect3 = "00000";

	m_EditConnectControl1.EnableWindow(FALSE);
	m_EditConnectControl2.EnableWindow(FALSE);
	m_EditConnectControl3.EnableWindow(FALSE);

	m_ButtonControl1.EnableWindow(FALSE);


	/////////////////////////////////////////////////////


	m_ComboConnect21.AddString(L"Не выбрано");
	m_ComboConnect21.AddString(L"RS232");
	m_ComboConnect21.AddString(L"UDP");


	m_ComboConnect22.AddString(L"Не выбрано");
	for (size_t i = 1; i <= 12; i++)
	{
		CString str;
		str.Format(L"%d", i);
		m_ComboConnect22.AddString(str);
	}
	m_ComboConnect23.AddString(L"Не выбрано");
	for (size_t i = 4; i <= 8; i++)
	{
		CString str;
		str.Format(L"%d", i);
		m_ComboConnect23.AddString(str);
	}
	m_ComboConnect24.AddString(L"Не выбрано");
	m_ComboConnect24.AddString(L"0");
	m_ComboConnect24.AddString(L"1");

	m_ComboConnect25.AddString(L"Не выбрано");
	m_ComboConnect25.AddString(L"1");
	m_ComboConnect25.AddString(L"1.5");
	m_ComboConnect25.AddString(L"2");

	m_ComboConnect26.AddString(L"Не выбрано");
	m_ComboConnect26.AddString(L"нет");
	m_ComboConnect26.AddString(L"аппаратное");
	m_ComboConnect26.AddString(L"Xon/Xoff");

	m_ComboConnect21.SetCurSel(m_ComboConnect21.FindString(0, L"Не выбрано"));
	m_ComboConnect22.SetCurSel(m_ComboConnect22.FindString(0, L"Не выбрано"));
	m_ComboConnect23.SetCurSel(m_ComboConnect23.FindString(0, L"Не выбрано"));
	m_ComboConnect24.SetCurSel(m_ComboConnect24.FindString(0, L"Не выбрано"));
	m_ComboConnect25.SetCurSel(m_ComboConnect25.FindString(0, L"Не выбрано"));
	m_ComboConnect26.SetCurSel(m_ComboConnect26.FindString(0, L"Не выбрано"));

	m_ComboConnect21.UpdateData();
	m_ComboConnect22.UpdateData();
	m_ComboConnect23.UpdateData();
	m_ComboConnect24.UpdateData();
	m_ComboConnect25.UpdateData();
	m_ComboConnect26.UpdateData();


	m_ComboConnect22.EnableWindow(FALSE);
	m_ComboConnect23.EnableWindow(FALSE);
	m_ComboConnect24.EnableWindow(FALSE);
	m_ComboConnect25.EnableWindow(FALSE);
	m_ComboConnect26.EnableWindow(FALSE);

	m_EditConnect21 = "75 - 128000";
	m_EditConnect22 = "0000.0000.0000.0000";
	m_EditConnect23 = "00000";

	m_EditConnectControl21.EnableWindow(FALSE);
	m_EditConnectControl22.EnableWindow(FALSE);
	m_EditConnectControl23.EnableWindow(FALSE);

	m_ButtonControl2.EnableWindow(FALSE);

	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CTabConnect::OnCbnSelchangeComboconnect1()
{
	// TODO: Add your control notification handler code here
	CString str;
	m_ComboConnect1.GetLBText(m_ComboConnect1.GetCurSel(), str);
	if (str == L"Не выбрано")
	{
		m_ComboConnect2.EnableWindow(FALSE);
		m_ComboConnect3.EnableWindow(FALSE);
		m_ComboConnect4.EnableWindow(FALSE);
		m_ComboConnect5.EnableWindow(FALSE);
		m_ComboConnect6.EnableWindow(FALSE);

		m_EditConnectControl1.EnableWindow(FALSE);
		m_EditConnectControl2.EnableWindow(FALSE);
		m_EditConnectControl3.EnableWindow(FALSE);

		m_ButtonControl1.EnableWindow(FALSE);
	}
	if (str == L"RS232")
	{
		m_ComboConnect2.EnableWindow(TRUE);
		m_ComboConnect3.EnableWindow(TRUE);
		m_ComboConnect4.EnableWindow(TRUE);
		m_ComboConnect5.EnableWindow(TRUE);
		m_ComboConnect6.EnableWindow(TRUE);

		m_EditConnectControl1.EnableWindow(TRUE);
		m_EditConnectControl2.EnableWindow(FALSE);
		m_EditConnectControl3.EnableWindow(FALSE);

		m_ButtonControl1.EnableWindow(TRUE);
	}
	if(str == L"UDP")
	{
		m_ComboConnect2.EnableWindow(FALSE);
		m_ComboConnect3.EnableWindow(FALSE);
		m_ComboConnect4.EnableWindow(FALSE);
		m_ComboConnect5.EnableWindow(FALSE);
		m_ComboConnect6.EnableWindow(FALSE);

		m_EditConnectControl1.EnableWindow(FALSE);
		m_EditConnectControl2.EnableWindow(TRUE);
		m_EditConnectControl3.EnableWindow(TRUE);

		m_ButtonControl1.EnableWindow(TRUE);
	}
}

void CTabConnect::OnCbnSelchangeComboconnect2()
{
	// TODO: Add your control notification handler code here
	CString str;
	m_ComboConnect21.GetLBText(m_ComboConnect21.GetCurSel(), str);
	if (str == L"Не выбрано")
	{
		m_ComboConnect22.EnableWindow(FALSE);
		m_ComboConnect23.EnableWindow(FALSE);
		m_ComboConnect24.EnableWindow(FALSE);
		m_ComboConnect25.EnableWindow(FALSE);
		m_ComboConnect26.EnableWindow(FALSE);

		m_EditConnectControl21.EnableWindow(FALSE);
		m_EditConnectControl22.EnableWindow(FALSE);
		m_EditConnectControl23.EnableWindow(FALSE);

		m_ButtonControl2.EnableWindow(FALSE);
	}
	if (str == L"RS232")
	{
		m_ComboConnect22.EnableWindow(TRUE);
		m_ComboConnect23.EnableWindow(TRUE);
		m_ComboConnect24.EnableWindow(TRUE);
		m_ComboConnect25.EnableWindow(TRUE);
		m_ComboConnect26.EnableWindow(TRUE);

		m_EditConnectControl21.EnableWindow(TRUE);
		m_EditConnectControl22.EnableWindow(FALSE);
		m_EditConnectControl23.EnableWindow(FALSE);

		m_ButtonControl2.EnableWindow(TRUE);
	}
	if (str == L"UDP")
	{
		m_ComboConnect22.EnableWindow(FALSE);
		m_ComboConnect23.EnableWindow(FALSE);
		m_ComboConnect24.EnableWindow(FALSE);
		m_ComboConnect25.EnableWindow(FALSE);
		m_ComboConnect26.EnableWindow(FALSE);

		m_EditConnectControl21.EnableWindow(FALSE);
		m_EditConnectControl22.EnableWindow(TRUE);
		m_EditConnectControl23.EnableWindow(TRUE);

		m_ButtonControl2.EnableWindow(TRUE);
	}
}

void CTabConnect::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CngmgDlg* pDlg = (CngmgDlg*)GetParentOwner();

	if (pDlg->isConnectedUAV)
	{
		m_ButtonControl1.SetWindowTextW(L"Подключиться");
		m_StringState1 = L"Не подключено";
		m_ComboConnect1.EnableWindow(TRUE);
		OnCbnSelchangeComboconnect1();
	}
	else
	{
		m_ButtonControl1.SetWindowTextW(L"Отключиться");
		m_StringState1 = L"Подключено";
		m_ComboConnect1.EnableWindow(FALSE);
		m_ComboConnect2.EnableWindow(FALSE);
		m_EditConnectControl1.EnableWindow(FALSE);
		m_ComboConnect3.EnableWindow(FALSE);
		m_ComboConnect4.EnableWindow(FALSE);
		m_ComboConnect5.EnableWindow(FALSE);
		m_ComboConnect6.EnableWindow(FALSE);

		m_EditConnectControl2.EnableWindow(FALSE);
		m_EditConnectControl3.EnableWindow(FALSE);


	}
	pDlg->isConnectedUAV = !pDlg->isConnectedUAV;
	m_ButtonControl1.UpdateWindow();
	m_StaticControl1.isConnected = pDlg->isConnectedUAV;
	m_StaticControl1.Invalidate();
	UpdateData(FALSE);
}

void CTabConnect::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CngmgDlg* pDlg = (CngmgDlg*)GetParentOwner();

	if (pDlg->isConnectedCS)
	{
		m_ButtonControl2.SetWindowTextW(L"Подключиться");
		m_StringState2 = L"Не подключено";
		m_ComboConnect21.EnableWindow(TRUE);
		OnCbnSelchangeComboconnect2();
	}
	else
	{
		m_ButtonControl2.SetWindowTextW(L"Отключиться");
		m_StringState2 = L"Подключено";
		m_ComboConnect21.EnableWindow(FALSE);
		m_ComboConnect22.EnableWindow(FALSE);
		m_EditConnectControl21.EnableWindow(FALSE);
		m_ComboConnect23.EnableWindow(FALSE);
		m_ComboConnect24.EnableWindow(FALSE);
		m_ComboConnect25.EnableWindow(FALSE);
		m_ComboConnect26.EnableWindow(FALSE);

		m_EditConnectControl22.EnableWindow(FALSE);
		m_EditConnectControl23.EnableWindow(FALSE);


	}
	pDlg->isConnectedCS = !pDlg->isConnectedCS;
	m_ButtonControl2.UpdateWindow();
	m_StaticControl2.isConnected = pDlg->isConnectedCS;
	m_StaticControl2.Invalidate();
	UpdateData(FALSE);
}