================================================================================
              MFC ���̺귯�� : [!output PROJECT_NAME] ������Ʈ ����
================================================================================

���� ���α׷� �����縦 ����Ͽ� [!output PROJECT_NAME] ���� ���α׷��� ����ϴ�. �� ���� 
���α׷������� �⺻���� MFC ��� ����� ���� ���α׷� �ۼ� ����� �����մϴ�.

�� ���Ͽ��� [!output PROJECT_NAME] ���� ���α׷��� �����ϴ� �� ���Ͽ� ���� ���䰡 ���ԵǾ�
�ֽ��ϴ�.

[!output PROJECT_NAME].vcproj
    ���� ���α׷� �����縦 ����Ͽ� ������ VC++ ������Ʈ�� �� ������Ʈ �����Դϴ�.
    �� ���Ͽ��� ������ ������ Visual C++ ���� ���� �� ���� ���α׷� �����翡�� ������ �÷���,
    ����, ������Ʈ ��� ���� ������ ���Ե˴ϴ�.

[!output APP_HEADER]
    ���� ���α׷��� �� ��� �����Դϴ�. �� ���Ͽ��� �ٸ� ������Ʈ�� ���õ� Resource.h�� ����
    Ư�� ����� ���ԵǸ� [!output APP_CLASS] ���� ���α׷� Ŭ������ ����˴ϴ�.

[!output APP_IMPL]
    [!output APP_CLASS] ���� ���α׷� Ŭ������ �����ϴ� �� ���� ���α׷��� �ҽ� �����Դϴ�.

[!output PROJECT_NAME].rc
    ���α׷����� ����ϴ� ��� Microsoft Windows ���ҽ��� ������ �����Դϴ�.
    �� ���Ͽ��� RES ���� ���͸��� ����� ������, ��Ʈ�� �� Ŀ���� ���ԵǸ�
    Microsoft Visual C++���� ���� �� ������ ������ ���� �ֽ��ϴ�. ������� ������Ʈ
    ���ҽ��� [!output LCID]�� ��� �ֽ��ϴ�.

res\[!output SAFE_PROJECT_NAME].ico
    ���� ���α׷��� ���������� ���Ǵ� ������ �����Դϴ�.
    �� �������� �� ���ҽ� ������ [!output PROJECT_NAME].rc�� ���Ե˴ϴ�.

res\[!output SAFE_PROJECT_NAME].rc2
    Microsoft Visual C++���� ������ �� ���� ���ҽ��� ���Ե� �����Դϴ�.
    ���ҽ� �����⿡�� ������ �� ���� ��� ���ҽ��� �� ���Ͽ� ���ԵǾ� �ֽ��ϴ�.
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    �����ӿ�ũ���� ������ ��� ������ ���� �ִ� .REG ���� �����Դϴ�.
    [!if APP_TYPE_DLG]
    �� ������ ���� ���α׷��� �����.REG ���Ϸ� ����� �� �ֽ��ϴ�.
[!else]
    �� ������ ���� ���α׷��� �����.REG ���Ϸ� ����ϰų�, �����ϰ� �⺻ 
    RegisterShellFileTypes ��Ͽ� �����ϴ�.
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    ���� ���α׷��� ���� ���̺귯���� ���� IDL(�������̽� ���� ���) �ҽ� �ڵ尡
    ���Ե� �����Դϴ�.
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

�� ������ â�� �ش�Ǵ� �����Դϴ�.
[!if PROJECT_STYLE_EXPLORER]
    Windows Ž���� ��Ÿ��: ������Ʈ�� �� ���� ���������� �������� Windows Ž����
    ������ �������̽��� ���Ե˴ϴ�.
[!else]
    ������Ʈ�� ǥ�� MFC �������̽��� ���Ե˴ϴ�.
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    [!output MAIN_FRAME_CLASS] ������ Ŭ������ �����ϴ� �����Դϴ�.
[!if APP_TYPE_MDI]
    ������ Ŭ������ CMDIFrameWnd���� �Ļ��Ǹ� ��� MDI ������ ����� �����մϴ�.
[!else]
    ������ Ŭ������ CFrameWnd���� �Ļ��Ǹ� ��� SDI ������ ����� �����մϴ�.
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    CTreeView���� �Ļ��� [!output TREE_VIEW_CLASS] ���� ������ Ŭ������ �����ϴ�
    �����Դϴ�.
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    ���� ������ �ٵ��ǽ� �̹����� ���� �� ���Ǵ� ��Ʈ�� �����Դϴ�.
    �ʱ� ���� ���� �� ���� ǥ������ [!output MAIN_FRAME_CLASS] Ŭ������ �����˴ϴ�.
    ���ҽ� �����⸦ ����Ͽ� ���� ���� ��Ʈ���� �����ϰ� [!output PROJECT_NAME].rc��
    IDR_MAINFRAME TOOLBAR �迭�� ������Ʈ�Ͽ� ���� ���� ���߿� �߰��մϴ�.
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    ���� ���� ���α׷��� �ٸ� �����̳� �ȿ��� ���� Ȱ��ȭ�Ǿ��� �� ���� ������
    �ٵ��ǽ� �̹����� ����� �� ���Ǵ� ��Ʈ�� �����Դϴ�.
    �� ���� ������ [!output INPLACE_FRAME_CLASS] Ŭ������ �����˴ϴ�.
    ��κ� ���� ����̶�� ���� �����ϸ� �� ��Ʈ���� res\Toolbar.bmp��
    ��Ʈ�ʰ� �����մϴ�.

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

�ڽ� ������ â�� �ش�Ǵ� �����Դϴ�.

ChildFrm.h, ChildFrm.cpp
    [!output CHILD_FRAME_CLASS] Ŭ������ �����ϰ� �����ϴ� ���Ϸμ� MDI ���� ���α׷�����
    �ڽ� â�� �����մϴ�.

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
���� ���α׷� �����翡�� ���� ���� ���� �� ���� �並 ����ϴ�.

[!output DOC_HEADER], [!output DOC_IMPL] - ����
    [!output DOC_CLASS] Ŭ������ �����ϴ� �����Դϴ�. �� ������ �����Ͽ�
    Ư�� ���� �����͸� �߰��ϰ� ������ ���� �� �ε��մϴ�
    ([!output DOC_CLASS]::Serialize ���).
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    �� �������� ���� ���ڿ��� ���Ե˴ϴ�.
        ���� Ȯ���:         [!output FILE_EXTENSION]
        ���� ���� ID:        [!output FILE_TYPE_ID]
        �� ������ ĸ��:      [!output MAIN_FRAME_CAPTION]
        ���� ���� �̸�:      [!output SAFE_DOC_TYPE_NAME]
        ���� �̸�:           [!output FILTER_NAME]
        ���� �� ��� �̸�:   [!output FILE_NEW_NAME_SHORT]
        ���� ���� ���� �̸�: [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
���� ���α׷� �����翡�� ���� �並 ����ϴ�.
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - ���� ��
    [!output VIEW_CLASS] Ŭ������ �����ϴ� �����Դϴ�.
[!if !DB_VIEW_NO_FILE]
    [!output VIEW_CLASS] ��ü�� ����Ͽ� [!output DOC_CLASS] ��ü�� �� �� �ֽ��ϴ�.
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    [!output DOC_CLASS] Ŭ������ MDI �ڽ� â�� ���������� ���Ǵ� ������ �����Դϴ�.
    �� �������� �� ���ҽ� ������ [!output PROJECT_NAME].rc�� ���Ե˴ϴ�.
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

�����ͺ��̽� ����:

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    [!output ROWSET_CLASS] Ŭ������ �����ϴ� �����Դϴ�.
    �� Ŭ������ �����翡�� ������ ������ �ҽ��� �׼����� �� ���˴ϴ�.    
[!if DB_VIEW_NO_FILE]
    serialization ������ �߰����� �ʽ��ϴ�.
[!else]
    Serialization ������ �߰��˴ϴ�.
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

���� ���α׷� �����翡�� OLE�� ���õ� Ŭ������ ��������ϴ�.

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    [!output CONTAINER_ITEM_CLASS] Ŭ������ �����ϴ� �����Դϴ�. �� Ŭ������ OLE ��ü��
    ������ �� ���˴ϴ�. OLE ��ü�� �Ϲ������� [!output VIEW_CLASS] Ŭ������ ����
    ǥ�õǸ� [!output DOC_CLASS] Ŭ������ �Ϻημ� serialize�˴ϴ�.
[!if ACTIVE_DOC_CONTAINER]
    �ش� ������ �ȿ� ��Ƽ�� ������ ������ �� �ִ� ���α׷��Դϴ�.
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    [!output SERVER_ITEM_CLASS] Ŭ������ �����ϴ� �����Դϴ�. �� Ŭ������ 
    [!output DOC_CLASS] Ŭ������ OLE �ý��ۿ� �����ϰ� �ɼ����� ������
    ������ ������ �� ���˴ϴ�.
[!if ACTIVE_DOC_SERVER]
    ��Ƽ�� ������ ����� ������ �� �ִ� ������Ʈ�Դϴ�.
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    [!output INPLACE_FRAME_CLASS] Ŭ������ �����ϴ� �����Դϴ�. �� Ŭ������
    COleIPFrameWnd���� �Ļ��Ǿ� ���� Ȱ��ȭ ���� ��� ������ ����� �����մϴ�.
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    ���� ������ �����ϴ� ������Ʈ�Դϴ�. ���� ���� ���Ŀ����� ���� ���� �ڵ�ȭ
    ��ü�� �ϳ��� ���Ͽ� ���ԵǸ鼭�� ������ ��ü�� �׼����Ǵ� ������ �����մϴ�.
    [!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
���� ���α׷� �����翡�� ���� ��ȭ ���� Ŭ������ �ڵ�ȭ ���Ͻ� Ŭ������ ����ϴ�.
[!else]
���� ���α׷� �����翡���� ���� ��ȭ ���� Ŭ������ ����ϴ�.
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - ��ȭ ����
    [!output DIALOG_CLASS] Ŭ������ �����ϴ� �����Դϴ�.  �� Ŭ�������� ���� ���α׷���
    �� ��ȭ ���ڿ� ���� ������ ���ǵ˴ϴ�. ��ȭ ������ ���ø��� [!output PROJECT_NAME].rc��
    ������ Microsoft Visual C++���� ������ �� �ֽ��ϴ�.
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - �ڵ�ȭ ��ü
    [!output DIALOG_AUTO_PROXY_CLASS] Ŭ������ �����ϴ� �����Դϴ�. �� Ŭ������
    �ڵ�ȭ ��Ʈ�ѷ����� ��ȭ ���ڿ� �׼����� �� ����ϴ� �ڵ�ȭ �޼��� �� �Ӽ���
    ������ �����ϹǷ� ��ȭ ���ڿ� ���� "�ڵ�ȭ ���Ͻ�" Ŭ������� �մϴ�.
    ��� ��ȭ ���ڸ� ����ϴ� MFC ���� ���α׷��� ��쿡�� �ڵ�ȭ ��ü�� �����
    �������̽��� �и��ϴ� ���� ��Ȯ�ϰ� �����ϹǷ� �ڵ�ȭ �޼��� �� �Ӽ��� ��ȭ ����
    Ŭ�������� ���� �����Ű�� �ʽ��ϴ�.
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

���� ����

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    ���� ������Ʈ �����Դϴ�. �� ���Ͽ��� ���� ������ .chm ���Ϸ� �������� ��
    �ʿ��� �����Ͱ� ���Ե˴ϴ�.

hlp\[!output PROJECT_NAME].hhc
    ���� ������Ʈ�� ������ ������ �����Դϴ�.

hlp\[!output PROJECT_NAME].hhk
    ���� �׸��� ������ ���Ե� �����Դϴ�.

hlp\afxcore.htm
    ǥ�� MFC ��ɰ� ȭ�� ��ü�� ���� ǥ�� ���� �׸��� ���Ե� �����Դϴ�.
    �� ���Ͽ� ����� ������ ���� �׸� �߰��� �� �ֽ��ϴ�.

[!if PRINTING]
hlp\afxprint.htm
    �μ� ��ɿ� ���� ���� �׸��� ���Ե� �����Դϴ�.

[!endif]
makehtmlhelp.bat
    ���� �ý��ۿ��� ���� ������ �������� �� ���Ǵ� �����Դϴ�.

hlp\Images\*.gif
    MFC ���̺귯�� ǥ�� ��ɿ� ���� ǥ�� ���� ���� �׸� �ʿ��� ��Ʈ��
    �����Դϴ�.

[!else]
hlp\[!output PROJECT_NAME].hpj
    ���� �����Ϸ����� ���� ���α׷��� ���� ������ ���� �� ���Ǵ�
    ���� ������Ʈ �����Դϴ�.

hlp\*.bmp    
    MFC ���̺귯�� ǥ�� ��ɿ� ���� ǥ�� ���� ���� �׸� �ʿ��� ��Ʈ��
    �����Դϴ�.

hlp\*.rtf
    ǥ�� MFC ��� �� ȭ�� ��ü�� ���� ǥ�� ���� �׸��� �����ϴ� �����Դϴ�.
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

��Ÿ ���
[!if ACTIVEX_CONTROLS]

ActiveX ��Ʈ��
    ���� ���α׷����� ActiveX ��Ʈ���� ����� �� �ֽ��ϴ�.
[!endif]
[!if PRINTING]

�μ� �� �μ� �̸����� ����
    ���� ���α׷� �����翡�� MFC ���̺귯���� CView Ŭ������ �ִ� ��� �Լ��� ȣ���Ͽ�
    �μ�, �μ� ����, �μ� �̸����� ����� ó���� �� �ִ� �ڵ带 �����մϴ�.
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

�����ͺ��̽� ����
    ���� ���α׷� �����翡�� ���α׷��� ���� �⺻���� �����ͺ��̽� ������ �߰��߽��ϴ�.
    �ʿ� ���ϸ� ���ԵǾ� �ֽ��ϴ�.
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

â ����
    ���� ���α׷� �����翡�� ���� ���α׷� ������ ���� â ����� �߰��߽��ϴ�.
[!endif]
[!if MAPI]

MAPI ����
    ������ ������Ʈ���� ���� �޽��� �ۼ�, ����, ���� �� ���忡 �ʿ��� �ڵ尡 ���Ե˴ϴ�.
[!endif]
[!if SOCKETS]

Windows ����
    ���� ���α׷����� TCP/IP ��Ʈ��ũ�� ���� ��� ������ �����մϴ�.
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

��Ÿ ǥ�� ����

StdAfx.h, StdAfx.cpp
    �̸� �����ϵ� ��� ����(PCH) [!output PROJECT_NAME].pch �� �̸� �����ϵ�
    ���� ���� StdAfx.obj�� ������ �� ���Ǵ� �����Դϴ�.

Resource.h
    ���ο� ���ҽ� ID�� �����ϴ� ǥ�� ��� �����Դϴ�.
    Microsoft Visual C++���� �� ������ �а� ������Ʈ�մϴ�.

/////////////////////////////////////////////////////////////////////////////

��Ÿ ����

���� ���α׷� �����翡���� "TODO:"�� ����Ͽ� �߰��ϰų� ����� �����ؾ� �ϴ�
�ҽ� �ڵ带 ��Ÿ���ϴ�.
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

���� ���α׷����� ���� DLL�� MFC�� ����ϰ� ���� ���α׷��� �� � ü����
���� �ٸ� ��� Microsoft Visual C++ CD-ROM�� Win\System ���͸��� �ִ� 
�ش� ������ ���ҽ��� MFC70XXX.DLL�� ��ǻ���� system �Ǵ� system32 ���͸��� 
������ ���� MFCLOC.DLL�� �̸��� �ٲپ�� �մϴ�. "XXX"�� �ش� �� ��Ÿ����
����Դϴ�. ���� ��� MFC70DEU.DLL���� ���Ͼ�� ��ȯ�� ���ҽ��� ���Ե˴ϴ�.
�̷� �۾��� ���� ������ ���� ���α׷��� �Ϻ� UI ��Ұ� � ü���� ����
���� �ְ� �˴ϴ�.
[!endif]

/////////////////////////////////////////////////////////////////////////////
