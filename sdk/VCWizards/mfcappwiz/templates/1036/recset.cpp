// [!output ROWSET_IMPL] : impl�mentation de la classe [!output ROWSET_CLASS]
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output ROWSET_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// impl�mentation de [!output ROWSET_CLASS]

[!if ODBC]
[!output ROWSET_CLASS_ODBC_IMPL]
[!endif]
