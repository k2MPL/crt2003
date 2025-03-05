// [!output ROWSET_IMPL] : [!output ROWSET_CLASS] 類別的實作
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output ROWSET_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output ROWSET_CLASS] 實作

[!if ODBC]
[!output ROWSET_CLASS_ODBC_IMPL]
[!endif]
