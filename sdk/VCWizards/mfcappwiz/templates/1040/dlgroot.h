// [!output APP_HEADER] : file di intestazione principale per l'applicazione PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error: inclusione di "stdafx.h" prima dell'inclusione di questo file per PCH
#endif

#include "resource.h"		// simboli principali


// [!output APP_CLASS]:
// Per l'implementazione di questa classe, vedere [!output APP_IMPL].
//

class [!output APP_CLASS] : public [!output APP_BASE_CLASS]
{
public:
	[!output APP_CLASS]();

// Sostituzioni
	public:
	virtual BOOL InitInstance();

// Implementazione

	DECLARE_MESSAGE_MAP()
};

extern [!output APP_CLASS] theApp;
