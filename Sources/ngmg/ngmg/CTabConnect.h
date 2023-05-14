#pragma once
#include "afxdialogex.h"
#include "MyCStatic.h"


// CTabConnect dialog

class CTabConnect : public CDialogEx
{
	DECLARE_DYNAMIC(CTabConnect)

public:
	CTabConnect(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTabConnect();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABCONNECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_ComboConnect1;
	CComboBox m_ComboConnect2;
	CComboBox m_ComboConnect3;
	CComboBox m_ComboConnect4;
	CComboBox m_ComboConnect5;
	CComboBox m_ComboConnect6;
	CString m_EditConnect1;
	CString m_EditConnect2;
	CString m_EditConnect3;
	CEdit m_EditConnectControl1;
	CEdit m_EditConnectControl2;
	CEdit m_EditConnectControl3;
	afx_msg void OnCbnSelchangeComboconnect1();
	CButton m_ButtonControl1;
	afx_msg void OnBnClickedButton1();
	MyCStatic m_StaticControl1;
	CString m_StringState1;

	CComboBox m_ComboConnect21;
	CComboBox m_ComboConnect22;
	CComboBox m_ComboConnect23;
	CComboBox m_ComboConnect24;
	CComboBox m_ComboConnect25;
	CComboBox m_ComboConnect26;
	CString m_EditConnect21;
	CString m_EditConnect22;
	CString m_EditConnect23;
	CEdit m_EditConnectControl21;
	CEdit m_EditConnectControl22;
	CEdit m_EditConnectControl23;
	afx_msg void OnCbnSelchangeComboconnect2();
	CButton m_ButtonControl2;
	afx_msg void OnBnClickedButton2();
	MyCStatic m_StaticControl2;
	CString m_StringState2;
};
