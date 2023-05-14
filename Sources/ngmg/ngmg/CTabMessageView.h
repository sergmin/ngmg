#pragma once
#include "afxdialogex.h"
#include "NGMG_MESSAGE_STRUCT.h"
#include "CEditableListCtrl.h"
#include "CMessageViewDlg.h"


// CTabMessageView dialog

class CTabMessageView : public CDialogEx
{
	DECLARE_DYNAMIC(CTabMessageView)

public:
	CTabMessageView(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTabMessageView();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MESSAGE_VIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	void InitList();
	void OnNMClickList(NMHDR*, LRESULT*);
	void OnNMDblClickList(NMHDR*, LRESULT*);
	CPoint InterviewListCursorPosition() const;
	CArray<NGMG_MESSAGE_STRUCT>* m_pMESSAGE_BUFFER;
	CEditableListCtrl m_EditableList;
	virtual BOOL OnInitDialog();
	void UpdateView(int cx, int cy);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	void UpdateList();
};
