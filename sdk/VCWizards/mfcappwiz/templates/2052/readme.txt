================================================================================
    MICROSOFT ������⣺ [!output PROJECT_NAME] ��Ŀ����
===============================================================================

Ӧ�ó�������Ϊ�������˴� [!output PROJECT_NAME] Ӧ�ó��򡣴�Ӧ�ó���
����������ʹ�� Microsoft ������Ļ���֪ʶ��
�����Ǳ�дӦ�ó������㡣

���ļ�������� [!output PROJECT_NAME] Ӧ�ó����ÿ���ļ�������ժҪ��

[!output PROJECT_NAME].vcproj
    ����ʹ�á�Ӧ�ó����򵼡����ɵ� VC++ ��Ŀ������Ŀ�ļ��� 
    �������й������ļ��� Visual C++ �汾����Ϣ���Լ�
    �й��á�Ӧ�ó����򵼡���ѡ���ƽ̨�����ú�
    ��Ŀ���ܵ���Ϣ��

[!output APP_HEADER]
    ����Ӧ�ó������ͷ�ļ���  ����������
    ��Ŀ�ض���ͷ�ļ������� Resource.h����������
    [!output APP_CLASS] Ӧ�ó����ࡣ

[!output APP_IMPL]
    ���ǰ���Ӧ�ó���
    �� [!output APP_CLASS] ����Ӧ�ó���Դ�ļ���

[!output PROJECT_NAME].rc
    ���ǳ���ʹ�õ����� Microsoft Windows ��Դ
    ���б�  �������洢�� RES ��Ŀ¼��
    ��ͼ�ꡢλͼ�͹�ꡣ  ��ֱ���� Microsoft 
    Visual C++ �б༭���ļ��� ��Ŀ��Դ������ [!output LCID] �С�

res\[!output SAFE_PROJECT_NAME].ico
    ����һ��ͼ���ļ�������Ӧ�ó����ͼ�ꡣ  ��
    ͼ�����������Դ�ļ� [!output PROJECT_NAME].rc �С�

res\[!output SAFE_PROJECT_NAME].rc2
    ���ļ��������� Microsoft 
    Visual C++ �༭����Դ�� Ӧ�����в�����
    ��Դ�༭���༭����Դ���ڴ��ļ��С�
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    ����һ�� .REG �ļ�ʾ����������ʾ
    ��ܽ�Ϊ�����õ�ע���������͡�  ���Խ������� .REG
[!if APP_TYPE_DLG]
    �ļ�������Ӧ�ó���һ��ʹ�á�
[!else]
    �ļ�������Ӧ�ó���һ��ʹ�ã���ɴ�ɾ����������
    Ĭ�ϵ� RegisterShellFileTypes ע�ᡣ
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    ���ļ�����Ӧ�ó������Ϳ��
    ���ӿ��������ԡ�Դ���롣
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

��������ܴ��ڣ�
[!if PROJECT_STYLE_EXPLORER]
    Windows ��Դ��������ʽ�� ��Ŀ���������� Windows ��Դ��������
    ���棬���а���������ܡ�
[!else]
    ��Ŀ��������׼�� MFC ���档
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    ��Щ�ļ���������� [!output MAIN_FRAME_CLASS]������������
[!if APP_TYPE_MDI]
    CMDIFrameWnd ���������е� MDI ��ܹ��ܡ�
[!else]
    CFrameWnd ���������е� SDI ��ܹ��ܡ�
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER]��[!output TREE_VIEW_IMPL]
    ��Щ�ļ����������� [!output TREE_VIEW_CLASS]������������
    CTreeView��
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    ��λͼ�ļ����ڴ�����������ƽ��ͼ��
    ��ʼ��������״̬���� [!output MAIN_FRAME_CLASS] 
    ���й��졣 ʹ����Դ�༭���༭�˹�����λͼ����
    ���� [!output PROJECT_NAME].rc �е� IDR_MAINFRAME TOOLBAR ���������
    ��������ť��
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    ��λͼ�ļ�����;���ڣ������������ھ͵ؼ��������Ӧ�ó����
    ������������ƽ��ͼ��
    �� �˹������� [!output INPLACE_FRAME_CLASS] 
    ���й��졣 ��λͼ������ res\Toolbar.bmp 
    �е�λͼ����ͬ�������Ƴ������Ƿ��������

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

�����ӿ�ܴ��ڣ�

ChildFrm.h��ChildFrm.cpp
    ��Щ�ļ������ʵ�� [!output CHILD_FRAME_CLASS] �࣬����
    ֧�� MDI Ӧ�ó����е��Ӵ��ڡ�

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
Ӧ�ó����򵼽�����һ���ĵ����ͺ�һ����ͼ��

[!output DOC_HEADER]��[!output DOC_IMPL] - �ĵ�
    ��Щ�ļ����� [!output DOC_CLASS] �ࡣ  �༭��Щ�ļ�
    �����������ĵ����ݲ�ʵ���ļ��ı���ͼ���
    ��ͨ�� [!output DOC_CLASS]::Serialize����
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    ���ĵ������������ַ�����
        �ļ���չ����      [!output FILE_EXTENSION]
        �ļ����� ID��        [!output FILE_TYPE_ID]
        ����ܱ��⣺  [!output MAIN_FRAME_CAPTION]
        �ĵ��������ƣ�       [!output SAFE_DOC_TYPE_NAME]
        ɸѡ�����ƣ�         [!output FILTER_NAME]
        �ļ����¼�ƣ� [!output FILE_NEW_NAME_SHORT]
        �ļ�����ȫ�ƣ� [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
Ӧ�ó����򵼴���һ����ͼ��
[!endif]

[!output VIEW_HEADER]��[!output VIEW_IMPL] - �ĵ���ͼ
    ��Щ�ļ����� [!output VIEW_CLASS] �ࡣ
[!if !DB_VIEW_NO_FILE]
    [!output VIEW_CLASS] �������ڲ鿴 [!output DOC_CLASS] ����
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    ����һ��ͼ���ļ������� 
    [!output DOC_CLASS] �� MDI �Ӵ��ڵ�ͼ�ꡣ  ��ͼ���������
    ��Դ�ļ� [!output PROJECT_NAME].rc �С�
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

���ݿ�֧�֣�

[!output ROWSET_HEADER]��[!output ROWSET_IMPL]
    ��Щ�ļ����� [!output ROWSET_CLASS] �ࡣ  �������ڷ���
    ������ѡ�������Դ��
[!if DB_VIEW_NO_FILE]
    ��������κ����л�֧�֡�
[!else]
    ��������л�֧�֡�
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

Ӧ�ó����򵼻��������ض��� OLE ����

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER]��[!output CONTAINER_ITEM_IMPL]
    ��Щ�ļ����� [!output CONTAINER_ITEM_CLASS] �ࡣ ��������
    ���� OLE ����  OLE ����ͨ���� 
    [!output VIEW_CLASS] ����ʾ�����л�Ϊ [!output DOC_CLASS] ���һ���֡�
[!if ACTIVE_DOC_CONTAINER]
    ����֧�ֽ���ĵ������������ڡ�
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER]��[!output SERVER_ITEM_IMPL]
    ��Щ�ļ����� [!output SERVER_ITEM_CLASS]�� ��������
    �� [!output DOC_CLASS] �����ӵ� OLE ϵͳ��
    ���������ṩ���ĵ������ӡ�
[!if ACTIVE_DOC_SERVER]
    ��Ŀ֧�ִ����͹����ĵ���
[!endif]

[!output INPLACE_FRAME_HEADER]��[!output INPLACE_FRAME_IMPL]
    ��Щ�ļ����� [!output INPLACE_FRAME_CLASS]�� ���������� 
    COleIPFrameWnd ���ھ͵ؼ�������п������еĿ�ܹ��ܡ�
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    ��Ŀ֧�ָ����ļ��� �����ļ���ʽ��
    ����һ�������Զ���������ĵ��洢Ϊһ���ļ����������������
    ���ļ��еĸ�������
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
Ӧ�ó����򵼽�����һ���Ի�������Զ��������ࣺ
[!else]
Ӧ�ó����򵼽�����һ���Ի����ࣺ
[!endif]

[!output DIALOG_HEADER]��[!output DIALOG_IMPL] - �Ի���
    ��Щ�ļ����� [!output DIALOG_CLASS] �ࡣ  ���ඨ��
    Ӧ�ó������Ի������Ϊ��  �˶Ի����ģ������� 
    [!output PROJECT_NAME].rc �У������ļ������� Microsoft Visual C++ �н��б༭��
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER]��[!output DIALOG_AUTO_PROXY_IMPL] - �Զ�������
    ��Щ�ļ����� [!output DIALOG_AUTO_PROXY_CLASS] �ࡣ  �����Ϊ�Ի����
    ���Զ��������࣬��Ϊ��
    ���𹫿��Զ������������������ʶԻ����
    �Զ������������ԡ�  ��Щ����
    �����Բ�ֱ�ӴӶԻ����๫������Ϊ
    �ڻ�����ģʽ�Ի���� MFC Ӧ�ó����У��������Ը�����͸����׵�
    ʹ�Զ����������û�����ֿ���
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

����֧�֣�

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    ���ļ��ǰ�����Ŀ�ļ��� �������������ļ�����Ϊ 
    .chm �ļ���������ݡ�

hlp\[!output PROJECT_NAME].hhc
    ���ļ��г�������Ŀ�����ݡ�

hlp\[!output PROJECT_NAME].hhk
    ���ļ��������������������

hlp\afxcore.htm
    ���ļ�������׼ MFC 
    �������Ļ����ı�׼�������⡣ �����Լ��İ���������ӵ����ļ��С�

[!if PRINTING]
hlp\afxprint.htm
    ���ļ��������ڴ�ӡ����İ������⡣

[!endif]
makehtmlhelp.bat
    ���ļ�������ϵͳ������������ļ���

hlp\Images\*.gif
    ��Щ�� Microsoft ��������׼����ı�׼�����ļ�����
    �����λͼ�ļ���

[!else]
hlp\[!output PROJECT_NAME].hpj
    ���ļ��ǰ�����������������
    Ӧ�ó���İ����ļ��İ�����Ŀ�ļ���

hlp\*.bmp
    ��Щ�� Microsoft ��������׼����ı�׼�����ļ�����
    �����λͼ�ļ���

hlp\*.rtf
    ��Щ�ļ�������׼ MFC 
    �������Ļ����ı�׼�������⡣
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

�������ܣ�
[!if ACTIVEX_CONTROLS]

ActiveX �ؼ�
    Ӧ�ó���֧��ʹ�� ActiveX �ؼ���
[!endif]
[!if PRINTING]

��ӡ֧�ֺʹ�ӡԤ��֧��
    Ӧ�ó�������������һЩ���룬ͨ���� MFC ����� CView ���еĳ�Ա������
    �����ӡ����ӡ���úʹ�ӡԤ�����
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

���ݿ�֧��
    Ӧ�ó���������˶Գ���Ļ������ݿ�֧�֡� ֻ������
    ������ļ���
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

��ִ���
    Ӧ�ó���������˶�Ӧ�ó����ĵ��Ĵ��ڲ��֧�֡�
[!endif]
[!if MAPI]

MAPI ֧��
    ���ɵ���Ŀ��������������������
    �ʹ洢�ʼ�����Ĵ��롣
[!endif]
[!if SOCKETS]

Windows �׽���
    Ӧ�ó���֧���� TCP/IP �����Ͻ���ͨѶ��
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

������׼�ļ���

StdAfx.h��StdAfx.cpp
    ��Щ�ļ�����������Ϊ [!output PROJECT_NAME].pch ��Ԥ����ͷ�ļ� (PCH)
    ����Ϊ StdAfx.obj ��Ԥ���������ļ���

Resource.h
    ���Ǳ�׼ͷ�ļ�������������Դ ID��
    Microsoft Visual C++ ����ȡ�����´��ļ���

/////////////////////////////////////////////////////////////////////////////

����˵����

Ӧ�ó�����ʹ�á�TODO:�� ��ָʾ
Ӧ��ӻ��Զ����Դ���벿�֡�
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

���Ӧ�ó����ڹ��� DLL ��ʹ�� MFC����Ӧ�ó���ʹ�õ����Բ���
����ϵͳ�ĵ�ǰ���ԣ�����Ҫ�� Microsoft Visual C++ ������ 
Win\System Ŀ¼�½���Ӧ�ı��ػ���Դ MFC70XXX.DLL 
���Ƶ�������� system �� system32 Ŀ¼�£�
������������Ϊ MFCLOC.DLL��  ����XXX������
������д��  ���磬MFC70DEU.DLL ���������
�������Դ����  �������������Ӧ�ó����ĳЩ UI Ԫ��
������Ϊ����ϵͳ�����ԡ�
[!endif]

/////////////////////////////////////////////////////////////////////////////
