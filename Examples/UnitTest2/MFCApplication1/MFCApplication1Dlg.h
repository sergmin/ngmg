
// MFCApplication1Dlg.h: файл заголовка
//

#pragma once
#include "Resource.h"
#include <afxwin.h>


#ifdef ROOTFINDER_EXPORTS
#define ROOTFINDER_API _declspec(dllexport)
#else
#define ROOTFINDER_API _declspec(dllimport)
#endif

// Диалоговое окно CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

class MyClass
{
public:
	int n, k;
	short add_f(short x, short y) {
		return x + y;
	};
};

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pPar = nullptr);
	virtual ~MyDialog();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif 

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()

public:
	CString m_lastMessage;

public:
	afx_msg void OnBattonClicked();
};

/*
class CMyDialog : public CDialogEx
{
public:
	CMyDialog(UINT nID, CWnd* pPar = NULL) : CDialogEx(nID, pPar)
	{
		m_bMessageBoxShown = false;
	}

	enum {IDD = IDD_MFCAPPLICATION1_DIALOG};

protected:
	virtual void DoDataExchange(CDataExchange* pDX) override
	{
		CDialogEx::DoDataExchange(pDX);
	}
	virtual BOOL OnInitDialog() override
	{
		CDialogEx::OnInitDialog();
		return TRUE;
	}
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk()
	{
		MessageBox(_T("Hello World"), _T("MFC Programming"), MB_OK);
		m_bMessageBoxShown = true;
	}
	afx_msg void OnCancel()
	{
		CDialogEx::OnCancel();
		m_bMessageBoxShown = false;
	}

	bool m_bMessageBoxShown;
};

BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyDialog::OnBnClickedOk)
END_MESSAGE_MAP()
*/