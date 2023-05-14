
// ngmgDlg.h: файл заголовка
//

#pragma once

#include "CTabConnect.h"
#include "CTabMessageView.h"
#include "NGMG_MESSAGE_STRUCT.h"



// Диалоговое окно CngmgDlg
class CngmgDlg : public CDialogEx
{
// Создание
public:
	CngmgDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NGMG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	HMODULE hLib;
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAboutBtnClicked();
	CTabConnect m_TabConnect;
	CTabMessageView m_Tab_UAV_RECEIVED_DECODED_BUFFER;
	CTabMessageView m_Tab_CS_RECEIVED_DECODED_BUFFER;
	CTabMessageView m_Tab_UAV_RECEIVED_NOT_DECODED_BUFFER;
	CTabMessageView m_Tab_CS_RECEIVED_NOT_DECODED_BUFFER;
	CTabMessageView m_Tab_UAV_SENDED_BUFFER;
	CTabMessageView m_Tab_CS_SENDED_BUFFER;


	BOOL isConnectedUAV;
	BOOL isConnectedCS;
	afx_msg void OnTcnSelchangeTabcontrol(NMHDR* pNMHDR, LRESULT* pResult);

	CArray<NGMG_MESSAGE_STRUCT> m_arUAV_RECEIVED_DECODED_BUFFER;
	CArray<NGMG_MESSAGE_STRUCT> m_arCS_RECEIVED_DECODED_BUFFER;
	CArray<NGMG_MESSAGE_STRUCT> m_arUAV_RECEIVED_NOT_DECODED_BUFFER;
	CArray<NGMG_MESSAGE_STRUCT> m_arCS_RECEIVED_NOT_DECODED_BUFFER;
	CArray<NGMG_MESSAGE_STRUCT> m_arUAV_SENDED_BUFFER;
	CArray<NGMG_MESSAGE_STRUCT> m_arCS_SENDED_BUFFER;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
