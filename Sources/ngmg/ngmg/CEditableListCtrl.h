#pragma once

#define WM_NOTIFY_DESCRIPTION_EDITED WM_APP + 666

// CEditableListCtrl

class CEditableListCtrl : public CListCtrl
{
    DECLARE_DYNAMIC(CEditableListCtrl)
public:
    int GetRowFromPoint(CPoint& point, int* col) const;

    void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    void OnLButtonDown(UINT nFlags, CPoint point);

protected:
    DECLARE_MESSAGE_MAP()
};

#pragma once
