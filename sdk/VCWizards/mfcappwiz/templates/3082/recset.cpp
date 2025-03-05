// [!output ROWSET_IMPL]: implementación de la clase [!output ROWSET_CLASS]
//

#include "stdafx.h"
#include "[!output APP_HEADER]"
#include "[!output ROWSET_HEADER]"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Implementación de [!output ROWSET_CLASS]

[!if ODBC]
[!output ROWSET_CLASS_ODBC_IMPL]
[!endif]
