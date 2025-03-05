// [!output ROWSET_IMPL] : [!output ROWSET_CLASS] 클래스의 구현
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output ROWSET_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output ROWSET_CLASS] 구현

[!if ODBC]
[!output ROWSET_CLASS_ODBC_IMPL]
[!endif]
