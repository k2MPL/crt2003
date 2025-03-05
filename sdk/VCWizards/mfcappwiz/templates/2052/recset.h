// [!output ROWSET_HEADER]: [!output ROWSET_CLASS] 类的接口
//


#pragma once

[!if ODBC]
[!output ROWSET_CLASS_ODBC_DECL]
[!else]
[!output ROWSET_CLASS_CODE]
[!endif]
