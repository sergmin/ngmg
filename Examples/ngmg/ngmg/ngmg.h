﻿
// ngmg.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CngmgApp:
// Сведения о реализации этого класса: ngmg.cpp
//

class CngmgApp : public CWinApp
{
public:
	CngmgApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CngmgApp theApp;
