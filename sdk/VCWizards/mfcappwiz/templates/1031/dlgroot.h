// [!output APP_HEADER] : Hauptheaderdatei f�r die [!output PROJECT_NAME]-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error 'stdafx.h' muss vor dieser Datei in PCH eingeschlossen werden.
#endif

#include "resource.h"		// Hauptsymbole


// [!output APP_CLASS]:
// Siehe [!output APP_IMPL] f�r die Implementierung dieser Klasse
//

class [!output APP_CLASS] : public [!output APP_BASE_CLASS]
{
public:
	[!output APP_CLASS]();

// �berschreibungen
	public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern [!output APP_CLASS] theApp;
