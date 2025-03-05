================================================================================
              MFC 라이브러리 : [!output PROJECT_NAME] 프로젝트 개요
================================================================================

응용 프로그램 마법사를 사용하여 [!output PROJECT_NAME] 응용 프로그램을 만듭니다. 이 응용 
프로그램에서는 기본적인 MFC 사용 밥법과 응용 프로그램 작성 방법을 설명합니다.

이 파일에는 [!output PROJECT_NAME] 응용 프로그램을 구성하는 각 파일에 대한 개요가 포함되어
있습니다.

[!output PROJECT_NAME].vcproj
    응용 프로그램 마법사를 사용하여 생성된 VC++ 프로젝트의 주 프로젝트 파일입니다.
    이 파일에는 파일을 생성한 Visual C++ 버전 정보 및 응용 프로그램 마법사에서 선택한 플랫폼,
    구성, 프로젝트 기능 등의 정보가 포함됩니다.

[!output APP_HEADER]
    응용 프로그램의 주 헤더 파일입니다. 이 파일에는 다른 프로젝트에 관련된 Resource.h와 같은
    특정 헤더가 포함되며 [!output APP_CLASS] 응용 프로그램 클래스가 선언됩니다.

[!output APP_IMPL]
    [!output APP_CLASS] 응용 프로그램 클래스를 포함하는 주 응용 프로그램의 소스 파일입니다.

[!output PROJECT_NAME].rc
    프로그램에서 사용하는 모든 Microsoft Windows 리소스가 나열된 파일입니다.
    이 파일에는 RES 하위 디렉터리에 저장된 아이콘, 비트맵 및 커서가 포함되며
    Microsoft Visual C++에서 직접 이 파일을 편집할 수도 있습니다. 사용자의 프로젝트
    리소스는 [!output LCID]에 들어 있습니다.

res\[!output SAFE_PROJECT_NAME].ico
    응용 프로그램의 아이콘으로 사용되는 아이콘 파일입니다.
    이 아이콘은 주 리소스 파일인 [!output PROJECT_NAME].rc에 포함됩니다.

res\[!output SAFE_PROJECT_NAME].rc2
    Microsoft Visual C++에서 편집할 수 없는 리소스가 포함된 파일입니다.
    리소스 편집기에서 편집할 수 없는 모든 리소스는 이 파일에 포함되어 있습니다.
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    프레임워크에서 설정할 등록 설정을 보여 주는 .REG 예제 파일입니다.
    [!if APP_TYPE_DLG]
    이 파일을 응용 프로그램에 연결된.REG 파일로 사용할 수 있습니다.
[!else]
    이 파일을 응용 프로그램에 연결된.REG 파일로 사용하거나, 삭제하고 기본 
    RegisterShellFileTypes 등록에 따릅니다.
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    응용 프로그램의 형식 라이브러리에 대한 IDL(인터페이스 정의 언어) 소스 코드가
    포함된 파일입니다.
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

주 프레임 창에 해당되는 내용입니다.
[!if PROJECT_STYLE_EXPLORER]
    Windows 탐색기 스타일: 프로젝트에 두 개의 프레임으로 나누어진 Windows 탐색기
    형식의 인터페이스가 포함됩니다.
[!else]
    프로젝트에 표준 MFC 인터페이스가 포함됩니다.
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    [!output MAIN_FRAME_CLASS] 프레임 클래스를 포함하는 파일입니다.
[!if APP_TYPE_MDI]
    프레임 클래스는 CMDIFrameWnd에서 파생되며 모든 MDI 프레임 기능을 제어합니다.
[!else]
    프레임 클래스는 CFrameWnd에서 파생되며 모든 SDI 프레임 기능을 제어합니다.
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    CTreeView에서 파생된 [!output TREE_VIEW_CLASS] 왼쪽 프레임 클래스를 포함하는
    파일입니다.
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    도구 모음에 바둑판식 이미지를 만들 때 사용되는 비트맵 파일입니다.
    초기 도구 모음 및 상태 표시줄은 [!output MAIN_FRAME_CLASS] 클래스에 구성됩니다.
    리소스 편집기를 사용하여 도구 모음 비트맵을 편집하고 [!output PROJECT_NAME].rc의
    IDR_MAINFRAME TOOLBAR 배열을 업데이트하여 도구 모음 단추에 추가합니다.
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    서버 응용 프로그램이 다른 컨테이너 안에서 내부 활성화되었을 때 도구 모음에
    바둑판식 이미지를 만드는 데 사용되는 비트맵 파일입니다.
    이 도구 모음은 [!output INPLACE_FRAME_CLASS] 클래스에 구성됩니다.
    대부분 서버 명령이라는 점을 제외하면 이 비트맵은 res\Toolbar.bmp의
    비트맵과 유사합니다.

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

자식 프레임 창에 해당되는 내용입니다.

ChildFrm.h, ChildFrm.cpp
    [!output CHILD_FRAME_CLASS] 클래스를 정의하고 구현하는 파일로서 MDI 응용 프로그램에서
    자식 창을 지원합니다.

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
응용 프로그램 마법사에서 단일 문서 종류 및 단일 뷰를 만듭니다.

[!output DOC_HEADER], [!output DOC_IMPL] - 문서
    [!output DOC_CLASS] 클래스를 포함하는 파일입니다. 이 파일을 편집하여
    특정 문서 데이터를 추가하고 파일을 저장 및 로드합니다
    ([!output DOC_CLASS]::Serialize 사용).
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    이 문서에는 다음 문자열이 포함됩니다.
        파일 확장명:         [!output FILE_EXTENSION]
        파일 형식 ID:        [!output FILE_TYPE_ID]
        주 프레임 캡션:      [!output MAIN_FRAME_CAPTION]
        문서 종류 이름:      [!output SAFE_DOC_TYPE_NAME]
        필터 이름:           [!output FILTER_NAME]
        파일 새 약식 이름:   [!output FILE_NEW_NAME_SHORT]
        파일 형식 정식 이름: [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
응용 프로그램 마법사에서 단일 뷰를 만듭니다.
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - 문서 뷰
    [!output VIEW_CLASS] 클래스를 포함하는 파일입니다.
[!if !DB_VIEW_NO_FILE]
    [!output VIEW_CLASS] 개체를 사용하여 [!output DOC_CLASS] 개체를 볼 수 있습니다.
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    [!output DOC_CLASS] 클래스의 MDI 자식 창의 아이콘으로 사용되는 아이콘 파일입니다.
    이 아이콘은 주 리소스 파일인 [!output PROJECT_NAME].rc에 포함됩니다.
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

데이터베이스 지원:

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    [!output ROWSET_CLASS] 클래스를 포함하는 파일입니다.
    이 클래스는 마법사에서 선택한 데이터 소스를 액세스할 때 사용됩니다.    
[!if DB_VIEW_NO_FILE]
    serialization 지원이 추가되지 않습니다.
[!else]
    Serialization 지원이 추가됩니다.
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

응용 프로그램 마법사에서 OLE에 관련된 클래스를 만들었습니다.

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    [!output CONTAINER_ITEM_CLASS] 클래스를 포함하는 파일입니다. 이 클래스는 OLE 개체를
    조작할 때 사용됩니다. OLE 개체는 일반적으로 [!output VIEW_CLASS] 클래스에 의해
    표시되며 [!output DOC_CLASS] 클래스의 일부로서 serialize됩니다.
[!if ACTIVE_DOC_CONTAINER]
    해당 프레임 안에 액티브 문서를 포함할 수 있는 프로그램입니다.
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    [!output SERVER_ITEM_CLASS] 클래스를 포함하는 파일입니다. 이 클래스는 
    [!output DOC_CLASS] 클래스를 OLE 시스템에 연결하고 옵션으로 문서에
    연결을 제공할 때 사용됩니다.
[!if ACTIVE_DOC_SERVER]
    액티브 문서를 만들고 관리할 수 있는 프로젝트입니다.
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    [!output INPLACE_FRAME_CLASS] 클래스를 포함하는 파일입니다. 이 클래스는
    COleIPFrameWnd에서 파생되어 내부 활성화 동안 모든 프레임 기능을 제어합니다.
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    복합 파일을 지원하는 프로젝트입니다. 복합 파일 형식에서는 여러 개의 자동화
    개체가 하나의 파일에 포함되면서도 각각의 개체로 액세스되는 문서를 저장합니다.
    [!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
응용 프로그램 마법사에서 단일 대화 상자 클래스와 자동화 프록시 클래스를 만듭니다.
[!else]
응용 프로그램 마법사에서는 단일 대화 상자 클래스를 만듭니다.
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - 대화 상자
    [!output DIALOG_CLASS] 클래스를 포함하는 파일입니다.  이 클래스에는 응용 프로그램의
    주 대화 상자에 대한 동작이 정의됩니다. 대화 상자의 템플릿은 [!output PROJECT_NAME].rc에
    있으며 Microsoft Visual C++에서 편집할 수 있습니다.
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - 자동화 개체
    [!output DIALOG_AUTO_PROXY_CLASS] 클래스를 포함하는 파일입니다. 이 클래스는
    자동화 컨트롤러에서 대화 상자에 액세스할 때 사용하는 자동화 메서드 및 속성의
    노출을 관리하므로 대화 상자에 대한 "자동화 프록시" 클래스라고도 합니다.
    모달 대화 상자를 사용하는 MFC 응용 프로그램의 경우에는 자동화 개체를 사용자
    인터페이스와 분리하는 것이 명확하고 간단하므로 자동화 메서드 및 속성은 대화 상자
    클래스에서 직접 노출시키지 않습니다.
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

도움말 지원

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    도움말 프로젝트 파일입니다. 이 파일에는 도움말 파일을 .chm 파일로 컴파일할 때
    필요한 데이터가 포함됩니다.

hlp\[!output PROJECT_NAME].hhc
    도움말 프로젝트의 목차가 나열된 파일입니다.

hlp\[!output PROJECT_NAME].hhk
    도움말 항목의 색인이 포함된 파일입니다.

hlp\afxcore.htm
    표준 MFC 명령과 화면 개체에 대한 표준 도움말 항목이 포함된 파일입니다.
    이 파일에 사용자 고유의 도움말 항목도 추가할 수 있습니다.

[!if PRINTING]
hlp\afxprint.htm
    인쇄 명령에 대한 도움말 항목이 포함된 파일입니다.

[!endif]
makehtmlhelp.bat
    빌드 시스템에서 도움말 파일을 컴파일할 때 사용되는 파일입니다.

hlp\Images\*.gif
    MFC 라이브러리 표준 명령에 대한 표준 도움말 파일 항목에 필요한 비트맵
    파일입니다.

[!else]
hlp\[!output PROJECT_NAME].hpj
    도움말 컴파일러에서 응용 프로그램의 도움말 파일을 만들 때 사용되는
    도움말 프로젝트 파일입니다.

hlp\*.bmp    
    MFC 라이브러리 표준 명령에 대한 표준 도움말 파일 항목에 필요한 비트맵
    파일입니다.

hlp\*.rtf
    표준 MFC 명령 및 화면 개체에 대한 표준 도움말 항목을 포함하는 파일입니다.
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

기타 기능
[!if ACTIVEX_CONTROLS]

ActiveX 컨트롤
    응용 프로그램에서 ActiveX 컨트롤을 사용할 수 있습니다.
[!endif]
[!if PRINTING]

인쇄 및 인쇄 미리보기 지원
    응용 프로그램 마법사에서 MFC 라이브러리의 CView 클래스에 있는 멤버 함수를 호출하여
    인쇄, 인쇄 설정, 인쇄 미리보기 명령을 처리할 수 있는 코드를 생성합니다.
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

데이터베이스 지원
    응용 프로그램 마법사에서 프로그램에 대한 기본적인 데이터베이스 지원을 추가했습니다.
    필요 파일만 포함되어 있습니다.
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

창 분할
    응용 프로그램 마법사에서 응용 프로그램 문서의 분할 창 기능을 추가했습니다.
[!endif]
[!if MAPI]

MAPI 지원
    생성된 프로젝트에는 메일 메시지 작성, 조작, 전송 및 저장에 필요한 코드가 포함됩니다.
[!endif]
[!if SOCKETS]

Windows 소켓
    응용 프로그램에서 TCP/IP 네트워크를 통한 통신 설정을 지원합니다.
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

기타 표준 파일

StdAfx.h, StdAfx.cpp
    미리 컴파일된 헤더 파일(PCH) [!output PROJECT_NAME].pch 및 미리 컴파일된
    형식 파일 StdAfx.obj를 빌드할 때 사용되는 파일입니다.

Resource.h
    새로운 리소스 ID를 정의하는 표준 헤더 파일입니다.
    Microsoft Visual C++에서 이 파일을 읽고 업데이트합니다.

/////////////////////////////////////////////////////////////////////////////

기타 정보

응용 프로그램 마법사에서는 "TODO:"를 사용하여 추가하거나 사용자 지정해야 하는
소스 코드를 나타냅니다.
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

응용 프로그램에서 공유 DLL에 MFC를 사용하고 응용 프로그램의 언어가 운영 체제의
언어와 다른 경우 Microsoft Visual C++ CD-ROM의 Win\System 디렉터리에 있는 
해당 지역의 리소스인 MFC70XXX.DLL을 컴퓨터의 system 또는 system32 디렉터리에 
복사한 다음 MFCLOC.DLL로 이름을 바꾸어야 합니다. "XXX"는 해당 언어를 나타내는
약어입니다. 예를 들어 MFC70DEU.DLL에는 독일어로 변환된 리소스가 포함됩니다.
이런 작업을 하지 않으면 응용 프로그램의 일부 UI 요소가 운영 체제의 언어로
남아 있게 됩니다.
[!endif]

/////////////////////////////////////////////////////////////////////////////
