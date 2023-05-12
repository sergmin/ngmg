
// InstallerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Installer.h"
#include "InstallerDlg.h"
#include "afxdialogex.h"
#include <string>
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CInstallerDlg dialog



CInstallerDlg::CInstallerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInstallerDlg::IDD, pParent)
	, m_dir(_T(""))
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CInstallerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DIR_EDIT, m_dir);
}

BEGIN_MESSAGE_MAP(CInstallerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHOOSE_DIR, &CInstallerDlg::OnBnClickedChooseDir)
	ON_BN_CLICKED(IDC_INSTALL, &CInstallerDlg::OnBnClickedInstall)
END_MESSAGE_MAP()


// CInstallerDlg message handlers

BOOL CInstallerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CInstallerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

		CPaintDC dc(this);
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
	
		HBITMAP bitmap = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(MAVLINK_BMP));
		dcMem.SelectObject(bitmap);
		
		dc.TransparentBlt(100,10, 300, 60, &dcMem, 0, 0, 400, 74,RGB(255,255,255));
		CDialogEx::OnPaint();

	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CInstallerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CInstallerDlg::OnBnClickedChooseDir()
{
	// TODO: Add your control notification handler code here

	CFolderPickerDialog dlgDir;
	dlgDir.DoModal();
	m_dir = dlgDir.GetPathName();
	UpdateData(FALSE);
	HBITMAP bitmap = LoadBitmap(NULL, MAKEINTRESOURCE(UNN_BMP));
	
}



void CInstallerDlg::OnBnClickedInstall()
{

	const int ynBoxRes = MessageBox(L"Установить программу в: " + m_dir + "?", L"Внимание!", MB_YESNOCANCEL | MB_ICONQUESTION);

	switch (ynBoxRes)
	{
	case IDYES:
		break;
	case IDNO:
		return;
		break;
	case IDCANCEL:
		return;
		break;
	}

	std::string result;
	CString CSPath = m_dir;
	// Из примера
	//HRSRC hRes = FindResource(GCM(), MAKEINTRESOURCE(DEMO_FILE), MAKEINTRESOURCE(CUSTOMFILE));
	//HGLOBAL hData = LoadResource(GCM(), hRes);
	//DWORD hSize = SizeofResource(GCM(), hRes);

	HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(EXEFILE), MAKEINTRESOURCE(EXEFILETYPE));
	HGLOBAL hData = LoadResource(NULL, hRes);
	DWORD hSize = SizeofResource(NULL, hRes);

	char* hFinal = (char*)LockResource(hData);
	result.assign(hFinal, hSize);
	auto lastch = m_dir[m_dir.GetLength()-1];
	if (lastch != _T('\\'))
	{
		CSPath += "\\";
	}
	CSPath += L"application.exe";

	std::fstream appFile(CSPath, std::ios::out | std::ios::binary);
	appFile << result;
	appFile.close();

	CSPath = m_dir;
	hRes = FindResource(NULL, MAKEINTRESOURCE(DLLFILE), MAKEINTRESOURCE(DLLFILETYPE));
	hData = LoadResource(NULL, hRes);
	hSize = SizeofResource(NULL, hRes);

	hFinal = (char*)LockResource(hData);
	result.assign(hFinal, hSize);
	lastch = m_dir[m_dir.GetLength() - 1];
	if (lastch != _T('\\'))
	{
		CSPath += "\\";
	}
	CSPath += L"module.dll";

	std::fstream dllFile(CSPath, std::ios::out | std::ios::binary);
	dllFile << result;
	dllFile.close();

	MessageBox(L"Установка завершена.", L"Внимание!", MB_ICONINFORMATION);
}
