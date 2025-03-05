// stdafx.h : file di inclusione per file di inclusione del sistema standard
// o file di inclusione specifici del progetto utilizzati di frequente,
// ma modificati di rado.

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Escludere dalle intestazioni Windows gli elementi utilizzati di rado.
#endif

// Modificare le seguenti definizioni se è necessario creare una piattaforma prima di quelle specificate di seguito.
// Fare riferimento a MSDN per le ultime informazioni sui valori corrispondenti per le differenti piattaforme.
#ifndef WINVER				// È consentito l'utilizzo di funzionalità specifiche per Windows 95 e Windows NT 4 o versioni successive.
#define WINVER 0x0400		// Cambiare il valore immettendo quello corretto per Windows 98, Windows 2000 o versione successiva.
#endif

#ifndef _WIN32_WINNT		// È consentito l'utilizzo di funzionalità specifiche per Windows NT 4 o versioni successive.
#define _WIN32_WINNT 0x0400		// Cambiare il valore immettendo quello corretto per Windows 98, Windows 2000 o versione successiva.
#endif						

#ifndef _WIN32_WINDOWS		// È consentito l'utilizzo di funzionalità specifiche per Windows 98 o versioni successive.
#define _WIN32_WINDOWS 0x0410 // Cambiare il valore immettendo quello corretto per Windows Millennium Edition o versione successiva.
#endif

#ifndef _WIN32_IE			// È consentito l'utilizzo di funzionalità specifiche per IE 4.0 o versioni successive.
#define _WIN32_IE 0x0400	// Cambiare il valore immettendo quello corretto per Internet Explorer 5.0 o versione successiva.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// alcuni costruttori CString saranno espliciti.

// disattiva l'operazione delle classi MFC che consiste nel nascondere alcuni comuni messaggi di avviso che vengono spesso ignorati.
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // componenti MFC di base e standard
#include <afxext.h>         // estensioni MFC
[!if APP_TYPE_MTLD && !DOCVIEW]
#include <afxtempl.h>		// classi dell'insieme MFC
[!endif]
[!if TREE_VIEW || LIST_VIEW || PROJECT_STYLE_EXPLORER]
#include <afxcview.h>
[!endif]

[!if CONTAINER || MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
#include <afxole.h>         // classi OLE MFC
[!if CONTAINER || CONTAINER_SERVER]
#include <afxodlgs.h>       // classi di finestre di dialogo OLE MFC
[!endif]
[!endif]

[!if AUTOMATION || ACTIVEX_CONTROLS]
#include <afxdisp.h>        // classi di automazione MFC
[!endif]

[!if ACTIVE_DOC_SERVER]
#include <afxdocob.h>
[!endif]

[!if DB_SUPPORT_HEADER_ONLY || DB_VIEW_NO_FILE]
 // Richiesto supporto minimo per database. Nessuna vista selezionata.
[!endif]
[!if DB_VIEW_WITH_FILE]
 // Selezionato supporto database con vista.
[!endif]

#include <afxdtctl.h>		// Supporto MFC per controlli comuni di Internet Explorer 4
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Supporto MFC per controlli comuni di Windows
#endif // _AFX_NO_AFXCMN_SUPPORT

[!if HTML_VIEW || HTML_EDITVIEW]
#include <afxhtml.h>			// supporto di visualizzazione HTML MFC
[!endif]

[!if SOCKETS]
#include <afxsock.h>		// estensioni socket MFC
[!endif] 

[!if RICH_EDIT_VIEW]
#include <afxrich.h>		// classi rich edit MFC
[!endif] 

[!if ATL_SUPPORT]
#include <atlbase.h>
extern CComModule _Module;
[!endif]

[!if OLEDB]
#include <atlbase.h>
#include <afxoledb.h>
#include <atlplus.h>
[!endif]
[!if DB_SUPPORT_OLEDB && DB_SUPPORT_HEADER_ONLY ]
#include <atlbase.h>
#include <afxoledb.h>
#include <atlplus.h>
[!endif]

[!if ODBC]
#include <afxdb.h>        // ODBC
[!endif]
[!if DB_SUPPORT_ODBC && DB_SUPPORT_HEADER_ONLY ]
#include <afxdb.h>        // ODBC
[!endif]

[!if HTML_DIALOG]
#include <afxdhtml.h>        // Finestre di dialogo HTML
[!endif]

[!if APP_TYPE_DLG]
[!if AUTOMATION]
// Questa macro è identica a IMPLEMENT_OLECREATE, con l'eccezione che passa TRUE
// per il parametro bMultiInstance al costruttore COleObjectFactory.
// Si desidera avviare un'istanza distinta dell'applicazione
// per ciascun proxy di automazione richiesto dai controller di automazione.
#ifndef IMPLEMENT_OLECREATE2
#define IMPLEMENT_OLECREATE2(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), TRUE, _T(external_name)); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } };
#endif // IMPLEMENT_OLECREATE2
[!endif]
[!endif]

