#pragma once


// MyCStatic

class MyCStatic : public CStatic
{
	DECLARE_DYNAMIC(MyCStatic)

public:
	MyCStatic();
	virtual ~MyCStatic();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	BOOL isConnected;
};


