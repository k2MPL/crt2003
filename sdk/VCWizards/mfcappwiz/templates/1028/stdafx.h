// stdafx.h : 標準系統 Include 檔的 Include 檔，
// 或是經常使用卻很少變更的專案專用 Include 檔案

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// 從 Windows 標頭排除不常使用的成員
#endif

// 如果您有必須優先選取的平台，請修改下列定義。
// 參考 MSDN 取得不同平台對應值的最新資訊。
#ifndef WINVER				// 允許使用 Windows 95 與 Windows NT 4 (含) 以後版本的特定功能。
#define WINVER 0x0400		// 將它變更為針對 Windows 98 和 Windows 2000 (含) 以後版本適當的值。
#endif

#ifndef _WIN32_WINNT		// 允許使用 Windows NT 4 (含) 以後版本的特定功能。
#define _WIN32_WINNT 0x0400		// 將它變更為針對 Windows 98 和 Windows 2000 (含) 以後版本適當的值。
#endif						

#ifndef _WIN32_WINDOWS		// 允許使用 Windows 98 (含) 以後版本的特定功能。
#define _WIN32_WINDOWS 0x0410 // 將它變更為針對 Windows Me (含) 以後版本適當的值。
#endif

#ifndef _WIN32_IE			// 允許使用 IE 4.0 (含) 以後版本的特定功能。
#define _WIN32_IE 0x0400	// 將它變更為針對 IE 5.0 (含) 以後版本適當的值。
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 明確定義部分的 CString 建構函式

// 關閉 MFC 隱藏一些常見或可忽略警告訊息的功能
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心與標準元件
#include <afxext.h>         // MFC 擴充功能
[!if APP_TYPE_MTLD && !DOCVIEW]
#include <afxtempl.h>		// MFC 集合類別
[!endif]
[!if TREE_VIEW || LIST_VIEW || PROJECT_STYLE_EXPLORER]
#include <afxcview.h>
[!endif]

[!if CONTAINER || MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
#include <afxole.h>         // MFC OLE 類別
[!if CONTAINER || CONTAINER_SERVER]
#include <afxodlgs.h>       // MFC OLE 對話方塊類別
[!endif]
[!endif]

[!if AUTOMATION || ACTIVEX_CONTROLS]
#include <afxdisp.h>        // MFC Automation 類別
[!endif]

[!if ACTIVE_DOC_SERVER]
#include <afxdocob.h>
[!endif]

[!if DB_SUPPORT_HEADER_ONLY || DB_VIEW_NO_FILE]
 // 在此，必須要求最小的 DB 支援。沒有選擇檢視。
[!endif]
[!if DB_VIEW_WITH_FILE]
 // 在此，已經選擇有檢視的 DB 支援。
[!endif]

#include <afxdtctl.h>		// MFC 支援的 Internet Explorer 4 通用控制項
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC 支援的 Windows 通用控制項
#endif // _AFX_NO_AFXCMN_SUPPORT

[!if HTML_VIEW || HTML_EDITVIEW]
#include <afxhtml.h>			// MFC HTML 檢視支援
[!endif]

[!if SOCKETS]
#include <afxsock.h>		// MFC 通訊端擴充功能
[!endif] 

[!if RICH_EDIT_VIEW]
#include <afxrich.h>		// MFC Rich Edit 類別
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
#include <afxdhtml.h>        // HTML 對話方塊
[!endif]

[!if APP_TYPE_DLG]
[!if AUTOMATION]
// 除了其對 bMultiInstance 參數傳遞 TRUE 到 COleObjectFactory 建構函式外，
// 此巨集與 IMPLEMENT_OLECREATE 相同。我們需要此應用程式的分開執行個體
// 以對 Automation 控制器所要求的 Automation Proxy 物件啟動。
#ifndef IMPLEMENT_OLECREATE2
#define IMPLEMENT_OLECREATE2(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), TRUE, _T(external_name)); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } };
#endif // IMPLEMENT_OLECREATE2
[!endif]
[!endif]

