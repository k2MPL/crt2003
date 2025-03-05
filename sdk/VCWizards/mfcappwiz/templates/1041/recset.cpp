// [!output ROWSET_IMPL] : [!output ROWSET_CLASS] ƒNƒ‰ƒX‚ÌŽÀ‘•
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output ROWSET_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output ROWSET_CLASS] ŽÀ‘•

[!if ODBC]
[!output ROWSET_CLASS_ODBC_IMPL]
[!endif]
