// [!output ROWSET_HEADER]: Schnittstelle der Klasse [!output ROWSET_CLASS]
//


#pragma once

[!if ODBC]
[!output ROWSET_CLASS_ODBC_DECL]
[!else]
[!output ROWSET_CLASS_CODE]
[!endif]
