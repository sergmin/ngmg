// CTabMessageView.cpp : implementation file
//

#include "pch.h"
#include "ngmg.h"
#include "afxdialogex.h"
#include "CTabMessageView.h"


#define MESSAGES_COUNT 100

template <class T>
void ShiftDataUp(CArray<T>* arr)
{
	for (int i  = 0; i < arr->GetCount() - 1; i++){
		arr->GetAt(i) = arr->GetAt(i + 1);
	}
	arr->RemoveAt(arr->GetCount() - 1);
}


// CTabMessageView dialog

IMPLEMENT_DYNAMIC(CTabMessageView, CDialogEx)

CTabMessageView::CTabMessageView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MESSAGE_VIEW, pParent)
{

}

CTabMessageView::~CTabMessageView()
{
}

void CTabMessageView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_EditableList);
}


BEGIN_MESSAGE_MAP(CTabMessageView, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnNMClickList)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnNMDblClickList)
	ON_BN_CLICKED(IDC_BUTTON1, &CTabMessageView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CTabMessageView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CTabMessageView::OnBnClickedButton4)
END_MESSAGE_MAP()


// CTabMessageView message handlers


void CTabMessageView::OnNMClickList(NMHDR* pNMHDR, LRESULT* pResult)
{
	m_EditableList.OnLButtonDown(MK_LBUTTON, InterviewListCursorPosition());
	*pResult = 0;
}

void CTabMessageView::OnNMDblClickList(NMHDR* pNMHDR, LRESULT* pResult)
{
	int uSelectedRow = m_EditableList.GetHotItem();
	int nCount = m_EditableList.GetItemCount();
	m_EditableList.OnLButtonDown(MK_LBUTTON, InterviewListCursorPosition());
	OnBnClickedButton1();

	*pResult = 0;
}


CPoint CTabMessageView::InterviewListCursorPosition() const
{
	DWORD pos = GetMessagePos();
	CPoint pt(LOWORD(pos), HIWORD(pos));
	ScreenToClient(&pt);

	CRect rect;
	CWnd* pWnd = GetDlgItem(IDC_LIST1);
	pWnd->GetWindowRect(&rect);
	ScreenToClient(&rect);

	pt.x -= rect.left;
	pt.y -= rect.top;
	return pt;
}


void CTabMessageView::InitList()
{
	LVCOLUMN lvColumn;
	int nCol;
	m_EditableList.DeleteAllItems();
	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_LEFT;
	lvColumn.cx = 26;
	lvColumn.pszText = _T("№");
	nCol = m_EditableList.InsertColumn(0, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Дата приема");
	m_EditableList.InsertColumn(1, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Время приема");
	m_EditableList.InsertColumn(2, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Тип порта п.");
	m_EditableList.InsertColumn(3, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Порт приема");
	m_EditableList.InsertColumn(4, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Дата отпр.");
	m_EditableList.InsertColumn(5, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Время отпр.");
	m_EditableList.InsertColumn(6, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Тип порта о.");
	m_EditableList.InsertColumn(7, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Порт отпр.");
	m_EditableList.InsertColumn(8, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("MAVLING флаг");
	m_EditableList.InsertColumn(9, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Флаг к. суммы");
	m_EditableList.InsertColumn(9, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Вер. протокола");
	m_EditableList.InsertColumn(10, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Длина пол. наг.");
	m_EditableList.InsertColumn(11, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Знач. сч. пак.");
	m_EditableList.InsertColumn(12, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("ID системы");
	m_EditableList.InsertColumn(13, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("ID комп.");
	m_EditableList.InsertColumn(14, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("ID сообщ.");
	m_EditableList.InsertColumn(15, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Данные");
	m_EditableList.InsertColumn(16, &lvColumn);

	lvColumn.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 80;
	lvColumn.pszText = _T("Контр. сум.");
	m_EditableList.InsertColumn(17, &lvColumn);

	m_EditableList.SetExtendedStyle(m_EditableList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EDITLABELS);
}

BOOL CTabMessageView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	InitList();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CTabMessageView::UpdateView(int cx, int cy)
{
	if (::IsWindow(GetSafeHwnd())){
		SetWindowPos(0, 0, 0, cx, cy, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
		if (::IsWindow(m_EditableList.GetSafeHwnd())){
			m_EditableList.SetWindowPos(0, 0, 0, cx, cy- 110, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
		}
		UpdateWindow();
	}
}


void CTabMessageView::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	POSITION pos = m_EditableList.GetFirstSelectedItemPosition();
	if (pos != NULL){
		while (pos){
			int count = m_pMESSAGE_BUFFER->GetCount() - m_EditableList.GetNextSelectedItem(pos) - 1;
			auto msg = &m_pMESSAGE_BUFFER->GetAt(count);
			CString str;
			str = L"Дата получения сооб.: " + msg->RECEIVED_DATE + L"\r\n" +
				L"Время получения сооб.: " + msg->RECEIVED_TIME + L"\r\n" +
				L"Тип порта приема: " + msg->PORT_TYPE_IN + L"\r\n" +
				L"Порта приема: " + msg->PORT_IN + L"\r\n" +
				L"Дата отправки сооб.: " + msg->SEND_DATE + L"\r\n" +
				L"Время отправки сооб.: " + msg->SEND_TIME + L"\r\n" +
				L"Тип порта отпр.: " + msg->PORT_TYPE_OUT + L"\r\n" +
				L"Порт отпр.: " + msg->PORT_OUT + L"\r\n" +
				L"Флаг MAVLINK: " + msg->MAVLINK_FLAG + L"\r\n" +
				L"Флаг конт. суммы: " + msg->CONTROL_SUM_FLAG + L"\r\n" +
				L"Версия протокола: " + msg->PROTOCOL_VER + L"\r\n" +
				L"Значение полезной нагр.: " + msg->PAYLOAD_LENGTH + L"\r\n" +
				L"Значение послед. пакетов: " + msg->PACKET_SEQUENCE + L"\r\n" +
				L"ID системы: " + msg->SYSTEM_ID + L"\r\n" +
				L"ID компонента: " + msg->COMPONENT_ID + L"\r\n" +
				L"ID сообщения: " + msg->MESSAGE_ID + L"\r\n" +
				L"Данные: " + msg->DATA + L"\r\n" +
				L"Контрольная сумма: " + msg->CONTROL_SUM;
			CMessageViewDlg dlg;
			dlg.m_EditMessageView = str;
			dlg.DoModal();
		}
	}
}


void CTabMessageView::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	int count = m_pMESSAGE_BUFFER->GetCount() + 1;
	int l_iItem;
	CString str;
	NGMG_MESSAGE_STRUCT mes;
	mes.RECEIVED_DATE.Format(L"П дата %d", count);
	mes.RECEIVED_TIME.Format(L"П вр %d", count);
	mes.PORT_TYPE_IN.Format(L"П тип п %d", count);
	mes.PORT_IN.Format(L"П порт %d", count);

	mes.SEND_DATE.Format(L"Пр дата %d", count);
	mes.SEND_TIME.Format(L"Пр вр %d", count);
	mes.PORT_TYPE_OUT.Format(L"Пр тип п %d", count);
	mes.PORT_OUT.Format(L"Пр порт %d", count);

	mes.MAVLINK_FLAG.Format(L"ML фл %d", count);
	mes.CONTROL_SUM_FLAG.Format(L"Ктр.с.флаг %d", count);
	mes.PROTOCOL_VER.Format(L"Вер %d", count);
	mes.PAYLOAD_LENGTH.Format(L"Дл пол наг %d", count);
	mes.PACKET_SEQUENCE.Format(L"Зн пак %d", count);
	mes.SYSTEM_ID.Format(L"ID с %d", count);
	mes.COMPONENT_ID.Format(L"ID к %d", count);
	mes.MESSAGE_ID.Format(L"ID со %d", count);
	mes.DATA.Format(L"Данные %d", count);
	mes.CONTROL_SUM.Format(L"Ктр сум %d", count);

	m_pMESSAGE_BUFFER->Add(mes);
	if (m_pMESSAGE_BUFFER->GetCount() > MESSAGES_COUNT) {
		ShiftDataUp(m_pMESSAGE_BUFFER);
	}
	UpdateList();
}


void CTabMessageView::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	m_pMESSAGE_BUFFER->RemoveAll();
	m_EditableList.DeleteAllItems();
}

void CTabMessageView::UpdateList()
{
	m_EditableList.DeleteAllItems();
	CString str;
	for (int count = 0; count < m_pMESSAGE_BUFFER->GetCount(); count++)
	{
		str.Format(L"%d", count+1);
		auto mes = &m_pMESSAGE_BUFFER->GetAt(count);
		int l_iItem = m_EditableList.InsertItem(LVIF_TEXT | LVIF_STATE, 0, str, 0, LVIS_SELECTED, 0, 0);
		m_EditableList.SetItemText(l_iItem, 1, mes->RECEIVED_DATE);
		m_EditableList.SetItemText(l_iItem, 2, mes->RECEIVED_TIME);
		m_EditableList.SetItemText(l_iItem, 3, mes->PORT_TYPE_IN);
		m_EditableList.SetItemText(l_iItem, 4, mes->PORT_IN);
		m_EditableList.SetItemText(l_iItem, 5, mes->SEND_DATE);
		m_EditableList.SetItemText(l_iItem, 6, mes->SEND_TIME);
		m_EditableList.SetItemText(l_iItem, 7, mes->PORT_TYPE_OUT);
		m_EditableList.SetItemText(l_iItem, 8, mes->PORT_OUT);
		m_EditableList.SetItemText(l_iItem, 9, mes->MAVLINK_FLAG);
		m_EditableList.SetItemText(l_iItem, 10, mes->CONTROL_SUM_FLAG);
		m_EditableList.SetItemText(l_iItem, 11, mes->PROTOCOL_VER);
		m_EditableList.SetItemText(l_iItem, 12, mes->PAYLOAD_LENGTH);
		m_EditableList.SetItemText(l_iItem, 13, mes->PACKET_SEQUENCE);
		m_EditableList.SetItemText(l_iItem, 14, mes->SYSTEM_ID);
		m_EditableList.SetItemText(l_iItem, 15, mes->COMPONENT_ID);
		m_EditableList.SetItemText(l_iItem, 16, mes->MESSAGE_ID);
		m_EditableList.SetItemText(l_iItem, 17, mes->DATA);
		m_EditableList.SetItemText(l_iItem, 18, mes->CONTROL_SUM);
	}
}