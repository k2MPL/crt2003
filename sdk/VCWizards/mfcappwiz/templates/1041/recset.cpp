// [!output ROWSET_IMPL] : [!output ROWSET_CLASS] クラスの実装
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output ROWSET_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output ROWSET_CLASS] 実装

[!if ODBC]
[!output ROWSET_CLASS_ODBC_IMPL]
[!endif]
