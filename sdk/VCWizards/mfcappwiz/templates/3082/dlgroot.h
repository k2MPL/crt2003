// [!output APP_HEADER]: archivo de encabezado principal para la aplicaci�n PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error incluye 'stdafx.h' antes de incluir este archivo para PCH
#endif

#include "resource.h"		// S�mbolos principales


// [!output APP_CLASS]:
// Consulte la secci�n [!output APP_IMPL] para obtener informaci�n sobre la implementaci�n de esta clase
//

class [!output APP_CLASS] : public [!output APP_BASE_CLASS]
{
public:
	[!output APP_CLASS]();

// Reemplazos
	public:
	virtual BOOL InitInstance();

// Implementaci�n

	DECLARE_MESSAGE_MAP()
};

extern [!output APP_CLASS] theApp;
