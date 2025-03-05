// [!output ROWSET_HEADER]: [!output ROWSET_CLASS] 클래스의 인터페이스
//


#pragma once

[!if ODBC]
[!output ROWSET_CLASS_ODBC_DECL]
[!else]
[!output ROWSET_CLASS_CODE]
[!endif]
