// [!output ROWSET_HEADER]: interface de la classe [!output ROWSET_CLASS]
//


#pragma once

[!if ODBC]
[!output ROWSET_CLASS_ODBC_DECL]
[!else]
[!output ROWSET_CLASS_CODE]
[!endif]
