
// ngmgDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "ngmg.h"
#include "ngmgDlg.h"
#include "afxdialogex.h"

#include <iostream>						// ТЕСТ СТАТИЧНОЙ БИБЛИОТЕКИ // ТЕСТ ДИНАМИЧНОЙ БИБЛИОТЕКИ
#include "..\ngmgLibrary\ngmgLibrary.h" // ТЕСТ СТАТИЧНОЙ БИБЛИОТЕКИ

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef bool (WINAPI* PFN_MyFunction)();

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CngmgDlg



CngmgDlg::CngmgDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NGMG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CngmgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CngmgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CngmgDlg::OnAboutBtnClicked)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABCONTROL, &CngmgDlg::OnTcnSelchangeTabcontrol)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// Обработчики сообщений CngmgDlg

BOOL CngmgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// ТЕСТ СТАТИЧНОЙ БИБЛИОТЕКИ
	int a = 5;				
	int b = 6;				
	int c = Sum(a,b);		

	// ТЕСТ ДИНАМИЧНОЙ БИБЛИОТЕКИ
	HINSTANCE load;
	load = LoadLibrary(L"ngmgDynamicLibrary.dll");
	typedef int (*sum)(int, int);
	sum Sum2;
	Sum2 = (sum)GetProcAddress(load, "Sum");
	int a2 = 10;				
	int b2 = 22;			
	int c2 = Sum2(a2, b2);
	FreeLibrary(load);

	/*
	// TODO: добавьте дополнительную инициализацию
	hLib = LoadLibrary(L"../x64/Debug/ngmgLibrary.dll");

	PFN_MyFunction pfnMyFunction;
	pfnMyFunction = (PFN_MyFunction)GetProcAddress(hLib, "Connect");
	bool aaa= pfnMyFunction();
	*/

	CTabCtrl* pTabCtrl = (CTabCtrl*)GetDlgItem(IDC_TABCONTROL);
	m_TabConnect.Create(IDD_TABCONNECT, pTabCtrl);
	m_Tab_UAV_RECEIVED_NOT_DECODED_BUFFER.Create(IDD_MESSAGE_VIEW, pTabCtrl);
	m_Tab_CS_RECEIVED_NOT_DECODED_BUFFER.Create(IDD_MESSAGE_VIEW, pTabCtrl);
	m_Tab_UAV_RECEIVED_DECODED_BUFFER.Create(IDD_MESSAGE_VIEW, pTabCtrl);
	m_Tab_CS_RECEIVED_DECODED_BUFFER.Create(IDD_MESSAGE_VIEW, pTabCtrl);
	m_Tab_UAV_SENDED_BUFFER.Create(IDD_MESSAGE_VIEW, pTabCtrl);
	m_Tab_CS_SENDED_BUFFER.Create(IDD_MESSAGE_VIEW, pTabCtrl);

	TCITEM item1, item2, item3, item4, item5, item6, item7;
	item1.mask = TCIF_TEXT | TCIF_PARAM;
	item1.lParam = (LPARAM)&m_TabConnect;
	item1.pszText = _T("Подключение");
	pTabCtrl->InsertItem(0, &item1);


	item2.mask = TCIF_TEXT | TCIF_PARAM;
	item2.lParam = (LPARAM)&m_Tab_UAV_RECEIVED_NOT_DECODED_BUFFER;
	item2.pszText = _T("БТС->Не дек.");
	pTabCtrl->InsertItem(1, &item2);

	item3.mask = TCIF_TEXT | TCIF_PARAM;
	item3.lParam = (LPARAM)&m_Tab_CS_RECEIVED_NOT_DECODED_BUFFER;
	item3.pszText = _T("СУ БТС->Не дек.");
	pTabCtrl->InsertItem(2, &item3);

	item4.mask = TCIF_TEXT | TCIF_PARAM;
	item4.lParam = (LPARAM)&m_Tab_UAV_RECEIVED_DECODED_BUFFER;
	item4.pszText = _T("БТС->Дек.");
	pTabCtrl->InsertItem(3, &item4);

	item5.mask = TCIF_TEXT | TCIF_PARAM;
	item5.lParam = (LPARAM)&m_Tab_CS_RECEIVED_DECODED_BUFFER;
	item5.pszText = _T("СУ БТС->Дек.");
	pTabCtrl->InsertItem(4, &item5);

	item6.mask = TCIF_TEXT | TCIF_PARAM;
	item6.lParam = (LPARAM)&m_Tab_UAV_SENDED_BUFFER;
	item6.pszText = _T("->БТС");
	pTabCtrl->InsertItem(5, &item6);

	item7.mask = TCIF_TEXT | TCIF_PARAM;
	item7.lParam = (LPARAM)&m_Tab_CS_SENDED_BUFFER;
	item7.pszText = _T("->СУ БТС");
	pTabCtrl->InsertItem(6, &item7);


	CRect rcItem;
	pTabCtrl->GetItemRect(0, &rcItem);
	m_TabConnect.SetWindowPos(NULL, rcItem.left, rcItem.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);


	CRect rcItem2;
	pTabCtrl->GetItemRect(0, &rcItem2);
	m_Tab_UAV_RECEIVED_NOT_DECODED_BUFFER.SetWindowPos(NULL, rcItem2.left, rcItem2.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	CRect rcItem3;
	pTabCtrl->GetItemRect(0, &rcItem3);
	m_Tab_CS_RECEIVED_NOT_DECODED_BUFFER.SetWindowPos(NULL, rcItem3.left, rcItem3.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	CRect rcItem4;
	pTabCtrl->GetItemRect(0, &rcItem4);
	m_Tab_UAV_RECEIVED_DECODED_BUFFER.SetWindowPos(NULL, rcItem4.left, rcItem4.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	CRect rcItem5;
	pTabCtrl->GetItemRect(0, &rcItem5);
	m_Tab_CS_RECEIVED_DECODED_BUFFER.SetWindowPos(NULL, rcItem5.left, rcItem5.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	CRect rcItem6;
	pTabCtrl->GetItemRect(0, &rcItem6);
	m_Tab_UAV_SENDED_BUFFER.SetWindowPos(NULL, rcItem6.left, rcItem6.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	CRect rcItem7;
	pTabCtrl->GetItemRect(0, &rcItem7);
	m_Tab_CS_SENDED_BUFFER.SetWindowPos(NULL, rcItem7.left, rcItem7.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	m_TabConnect.ShowWindow(SW_SHOW);
	m_Tab_UAV_RECEIVED_NOT_DECODED_BUFFER.ShowWindow(SW_HIDE);
	m_Tab_CS_RECEIVED_NOT_DECODED_BUFFER.ShowWindow(SW_HIDE);
	m_Tab_UAV_RECEIVED_DECODED_BUFFER.ShowWindow(SW_HIDE);
	m_Tab_CS_RECEIVED_DECODED_BUFFER.ShowWindow(SW_HIDE);
	m_Tab_UAV_SENDED_BUFFER.ShowWindow(SW_HIDE);
	m_Tab_CS_SENDED_BUFFER.ShowWindow(SW_HIDE);

	isConnectedUAV = FALSE;
	isConnectedCS = FALSE;

	m_Tab_UAV_RECEIVED_DECODED_BUFFER.m_pMESSAGE_BUFFER = &m_arUAV_RECEIVED_DECODED_BUFFER;
	m_Tab_CS_RECEIVED_DECODED_BUFFER.m_pMESSAGE_BUFFER = &m_arCS_RECEIVED_DECODED_BUFFER;
	m_Tab_UAV_RECEIVED_NOT_DECODED_BUFFER.m_pMESSAGE_BUFFER = &m_arUAV_RECEIVED_NOT_DECODED_BUFFER;
	m_Tab_CS_RECEIVED_NOT_DECODED_BUFFER.m_pMESSAGE_BUFFER = &m_arCS_RECEIVED_NOT_DECODED_BUFFER;
	m_Tab_UAV_SENDED_BUFFER.m_pMESSAGE_BUFFER = &m_arUAV_SENDED_BUFFER;
	m_Tab_CS_SENDED_BUFFER.m_pMESSAGE_BUFFER = &m_arCS_SENDED_BUFFER;

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CngmgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CngmgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CngmgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CngmgDlg::OnAboutBtnClicked()
{
	// TODO: Add your command handler code here
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


void CngmgDlg::OnTcnSelchangeTabcontrol(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	int iTab = ((CTabCtrl*)GetDlgItem(IDC_TABCONTROL))->GetCurSel();

	m_TabConnect.ShowWindow(iTab == 0 ? SW_SHOW : SW_HIDE);
	m_Tab_UAV_RECEIVED_NOT_DECODED_BUFFER.ShowWindow(iTab == 1 ? SW_SHOW : SW_HIDE);
	m_Tab_CS_RECEIVED_NOT_DECODED_BUFFER.ShowWindow(iTab == 2 ? SW_SHOW : SW_HIDE);
	m_Tab_UAV_RECEIVED_DECODED_BUFFER.ShowWindow(iTab == 3 ? SW_SHOW : SW_HIDE);
	m_Tab_CS_RECEIVED_DECODED_BUFFER.ShowWindow(iTab == 4 ? SW_SHOW : SW_HIDE);
	m_Tab_UAV_SENDED_BUFFER.ShowWindow(iTab == 5 ? SW_SHOW : SW_HIDE);
	m_Tab_CS_SENDED_BUFFER.ShowWindow(iTab == 6 ? SW_SHOW : SW_HIDE);
}


void CngmgDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	//CTabCtrl*  pTC = (CTabCtrl*)GetDlgItem(IDC_TABCONTROL);
	/*m_Tab_UAV_RECEIVED_NOT_DECODED_BUFFER.UpdateView(cx, cy);
	m_Tab_CS_RECEIVED_NOT_DECODED_BUFFER.UpdateView(cx, cy);
	m_Tab_UAV_RECEIVED_DECODED_BUFFER.UpdateView(cx, cy);
	m_Tab_CS_RECEIVED_DECODED_BUFFER.UpdateView(cx, cy);
	m_Tab_UAV_SENDED_BUFFER.UpdateView(cx, cy);
	m_Tab_CS_SENDED_BUFFER.UpdateView(cx, cy);*/
}
