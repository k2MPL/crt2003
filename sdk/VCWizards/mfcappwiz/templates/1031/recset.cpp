// [!output ROWSET_IMPL] : Implementierung der Klasse [!output ROWSET_CLASS]
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output ROWSET_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output ROWSET_CLASS] Implementierung

[!if ODBC]
[!output ROWSET_CLASS_ODBC_IMPL]
[!endif]
