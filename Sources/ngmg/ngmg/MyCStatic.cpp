// MyCStatic.cpp : implementation file
//

#include "pch.h"
#include "MyCStatic.h"


// MyCStatic

IMPLEMENT_DYNAMIC(MyCStatic, CStatic)

MyCStatic::MyCStatic()
{
	isConnected = FALSE;
}

MyCStatic::~MyCStatic()
{
}


BEGIN_MESSAGE_MAP(MyCStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// MyCStatic message handlers




void MyCStatic::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CStatic::OnPaint() for painting messages
	CRect rect;
	GetClientRect(&rect);
	CBrush br(RGB(255*!isConnected + 80 * isConnected, 255 * isConnected + 80 * !isConnected, 80));
	dc.FillRect(rect, &br);
}
