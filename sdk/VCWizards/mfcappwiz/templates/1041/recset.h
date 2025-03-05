// [!output ROWSET_HEADER]: [!output ROWSET_CLASS] クラスのインターフェイス
//


#pragma once

[!if ODBC]
[!output ROWSET_CLASS_ODBC_DECL]
[!else]
[!output ROWSET_CLASS_CODE]
[!endif]
