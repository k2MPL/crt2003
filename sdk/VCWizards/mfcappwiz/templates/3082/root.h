// [!output APP_HEADER]: archivo de encabezado principal para la aplicaci�n [!output PROJECT_NAME]
//
#pragma once

#ifndef __AFXWIN_H__
	#error incluye 'stdafx.h' antes de incluir este archivo para PCH
#endif

#include "resource.h"       // S�mbolos principales


// [!output APP_CLASS]:
// Consulte la secci�n [!output APP_IMPL] para obtener informaci�n sobre la implementaci�n de esta clase
//

class [!output APP_CLASS] : public [!output APP_BASE_CLASS]
{
public:
	[!output APP_CLASS]();

[!if APP_TYPE_MTLD]
[!if !DOCVIEW]
	CArray<HWND, HWND> m_aryFrames;
[!else]
protected:
	CMultiDocTemplate* m_pDocTemplate;
[!endif]
public:
[!endif]

// Reemplazos
public:
	virtual BOOL InitInstance();
[!if APP_TYPE_MDI]
[!if !DOCVIEW]
	virtual int ExitInstance();
[!endif]
[!endif]

// Implementaci�n
[!if FULL_SERVER || MINI_SERVER || CONTAINER_SERVER || AUTOMATION]
	COleTemplateServer m_server;
		// Objeto de servidor para la creaci�n de documentos
[!endif]
[!if !DOCVIEW]
[!if !APP_TYPE_SDI]
protected:
	HMENU m_hMDIMenu;
	HACCEL m_hMDIAccel;
[!endif]

public:
[!endif]
	afx_msg void OnAppAbout();
[!if !DOCVIEW]
[!if APP_TYPE_MDI]
	afx_msg void OnFileNew();
[!endif]
[!endif]
[!if APP_TYPE_MTLD]
	afx_msg void OnFileNewFrame();
[!if DOCVIEW]
	afx_msg void OnFileNew();
[!endif]
[!endif]
	DECLARE_MESSAGE_MAP()
};

extern [!output APP_CLASS] theApp;
