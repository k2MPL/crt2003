================================================================================
    MFC �{���w : [!output PROJECT_NAME] �M�׷��[
===============================================================================

AppWizard ���z�إߤF [!output PROJECT_NAME] ���ε{���C�����ε{�����u�i��
�ϥ� MFC ����¦�Ϊk�A���]�O�����z�ǲߦp�󼶼g���ε{�����X�o�I�C

�o���ɮץ]�t�c�� [!output PROJECT_NAME] ���ε{�����Ҧ��ɮת��K�n�C

[!output PROJECT_NAME].vcproj
    �o�O�ϥ����ε{�����F�ҫإߪ� VC++ �M�ת��D�M���ɡC���]�t�������ͦ�
    �ɮת� Visual C++ ������T�A�H�ΥH���ε{�����F��������x�B�պA�M�M
    �ץ\�൥������T�C

[!output APP_HEADER]
    �o�O���ε{�����D���Y�ɡC���]�A��L�M�׫��w�����Y (�]�A Resource.h) 
    �M�ŧi [!output APP_CLASS] ���ε{�����O�C

[!output APP_IMPL]
    �o�O�]�t���ε{�����O [!output APP_CLASS] ���D���ε{���ӷ��ɡC

[!output PROJECT_NAME].rc
    �o�O���{���ϥΪ��Ҧ� Microsoft Windows �귽���M��C���]�A�ϥܡB�I�}��
    �H���x�s�b RES �l�ؿ�������СC�z�i�H�b Microsoft Visual C++ �������s
    �覹�ɮסC�M�׸귽��� [!output LCID] ���C

res\[!output SAFE_PROJECT_NAME].ico
    �o�O�ӹϥ��ɡA���Q�����ε{�����ϥܨϥΡC�D�귽�� [!output PROJECT_NAME].rc 
    ���]�t���ϥܡC

res\[!output SAFE_PROJECT_NAME].rc2
    �o���ɮץ]�t���g�� Microsoft Visual C++ �s�誺�ɮסC�z�����N�Ҧ����i��
    �귽�s�边�s�誺�귽��m�b���ɮפ��C
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    �o�O��ܦ��[�c�N���z�]�w���n���]�w�d�Ҫ� .REG �ɡC�z�i�H�N���� .REG �ϥΡC
[!if APP_TYPE_DLG]
    �P���ε{���@�_�ϥΪ��ɮסC
[!else]
    ���ɮ׻P�M�פ@�_�s��άO�R�����ɮסA�M��ϥιw�]�� RegisterShellFileTypes 
    �n���C
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    �o���ɮץ]�t���ε{�����O�{���w�������y�z�y�� (Interface Description Language) 
    ��l�{���X�C
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

����D�ج[����:
[!if PROJECT_STYLE_EXPLORER]
    Windows �ɮ��`�޼˦�: ���M�ױN�|�]�t�@������ Windows �ɮ��`�� (����Ӯج[) 
    �������C
[!else]
    ���M�ױN�]�t�з� MFC �����C
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    �o���ɮץ]�t�ج[���O [!output MAIN_FRAME_CLASS]�A�����O�l�ͦ�
[!if APP_TYPE_MDI]
    CMDIFrameWnd �ñ���Ҧ� MDI �ج[�\��C
[!else]
    CFrameWnd �ñ���Ҧ� SDI �ج[�\��C
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    �o���ɮץ]�t���ج[���O [!output TREE_VIEW_CLASS]�A�����O�l�ͦ�
    CTreeView�C
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    �o���I�}���ɥΩ�إߤu��C���ñƼv���C��l���u��C�M���A�C�O�b 
    [!output MAIN_FRAME_CLASS] ���O���غc�C�Шϥθ귽�s�边�s�覹�u
    ��C�I�}�ϡA�M��b [!output PROJECT_NAME].rc ����s IDR_MAINFRAME TOOLBAR 
    �}�C�H�[�J�u��C���s�C
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    ��z�����A�����ε{���b�t�@�Ӯe�����w�N��B�w����ɡA�o���I�}����
    �Ω�إߤu��C���ñƼv���C���u��C�O�b [!output INPLACE_FRAME_CLASS] 
    ���O���غc�C���F�w�����h�ӫD���A���R�O�~�A���I�}�ϻP res\Toolbar.bmp 
    �����I�}�������C

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

����l�ج[����:

ChildFrm.h, ChildFrm.cpp
    �o���ɮשw�q�M��@ [!output CHILD_FRAME_CLASS] ���O�A�����O�䴩 
    MDI ���ε{�������l�����C

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
AppWizard �إߤ���������˵�:

[!output DOC_HEADER], [!output DOC_IMPL] - �����
    �o���ɮץ]�t�z�� [!output DOC_CLASS] ���O�C�s��o���ɮץH�[�J�S�����
    ��ơA�M���@�ɮ��x�s�M���J (�z�L [!output DOC_CLASS]::Serialize)�C
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    ���N�|���U�C�r��:
        �ɮװ��ɦW:         [!output FILE_EXTENSION]
        �ɮ����� ID:        [!output FILE_TYPE_ID]
        �D�ج[���D: 	    [!output MAIN_FRAME_CAPTION]
        ��������W��:       [!output SAFE_DOC_TYPE_NAME]
        �z�����W��:       [!output FILTER_NAME]
        �ɮ׷s²�u�W��:     [!output FILE_NEW_NAME_SHORT]
        �ɮ��������ɦW:     [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
AppWizard �إ��˵�:
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - ����˵�
    �o���ɮץ]�t�z�� [!output VIEW_CLASS] ���O�C
[!if !DB_VIEW_NO_FILE]
    [!output VIEW_CLASS] ����Ω��˵� [!output DOC_CLASS] ����C
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    �o�O�ӹϥ��ɡA������ [!output DOC_CLASS] ���O�� MDI �l�������ϥܨϥΡC
    ���ϥܥѥD�귽�� [!output PROJECT_NAME].rc �ҤޥΡC
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////

��Ʈw�䴩:

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    �o���ɮץ]�t�z�� [!output ROWSET_CLASS] ���O�C�����O�Ω�s���z�b���F��
    �������ƨӷ��C
[!if DB_VIEW_NO_FILE]
    �N���|�[�J�ǦC�Ƥ䴩�C
[!else]
    �N�[�J�ǦC�Ƥ䴩�C
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

AppWizard �P�ɤ]�إ� OLE �S�w���O�C

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    �o���ɮץ]�t�z�� [!output CONTAINER_ITEM_CLASS] ���O�C�����O�Ω�B�z OLE ����C
    OLE ����q�`�O�� [!output VIEW_CLASS] ���O��ܡA�çǦC�Ƭ� [!output DOC_CLASS] 
    ���O���@�����C
[!if ACTIVE_DOC_CONTAINER]
    �o�ӵ{���]�t�b��ج[���]�t Active ��󪺤䴩�C
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    �o���ɮץ]�t�z�� [!output SERVER_ITEM_CLASS]�C�����O�Ω�s�� [!output DOC_CLASS] 
    ���O�P OLE �t�ΡA�H�ο�ܩʦa���Ѧܱz����󪺳s���C
[!if ACTIVE_DOC_SERVER]
    ���M�פ䴩�إߩM�޲z�{�Τ��C
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    �o���ɮץ]�t�z�� [!output INPLACE_FRAME_CLASS]�C�����O�O�q COleIPFrameWnd �l�͡A
    �åB�b�N��ҰʹL�{������Ҧ����ج[�\��C
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    �o�ӱM�פ䴩�ƦX�ɮסC���ƦX�ɮ׮榡�x�s�]�t�@�Φh�ӦܬY�ɮת� Automation ����
    ���A�åB���\�s���ӧO�����ɮסC
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
AppWizard �إ߹�ܤ�����O�M Automation Proxy ���O:
[!else]
AppWizard �إ߹�ܤ�����O:
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - ��ܤ��
    �o���ɮץ]�t [!output DIALOG_CLASS] ���O�C�����O�w�q���ε{�����D�n��ܤ��
    ���欰�C����ܤ�����d�����i�ϥ� Microsoft Visual C++ �s�誺 
    [!output PROJECT_NAME].rc ���C
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - Automation ����
    �o���ɮץ]�t [!output DIALOG_AUTO_PROXY_CLASS] ���O�C�����O�b��ܤ�����٬� 
    "automation proxy" ���O�A�]�����i�B�zAutomation ����{���ΨӦs����ܤ����
    Automaton ��k���ݩʪ����S�C�o�Ǥ�k�M�ݩʨëD�����۹�ܤ�����S�A�]���b�H
    �j��^����ܤ������¦�� MFC ���ε{�����A�N Automation ����P�ϥΪ̤������}
    �i�����ε{���O����²��M²���C
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

�����䴩:

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    �o���ɮ׬O�ӻ����M���ɡC���]�t�N�����ɽsĶ�� .chm �ɩһݪ���ơC

hlp\[!output PROJECT_NAME].hhc
    �o���ɮ׷|�C�X�����M�ת����e�C

hlp\[!output PROJECT_NAME].hhk
    �o���ɮץ]�t�����D�D�����ޡC

hlp\afxcore.htm
    �o���ɮץ]�t�з� MFC �R�O�M�ù����󪺼зǻ����D�D�C�N�z�ۤv������
    �D�D�[�J�ܦ��ɮסC

[!if PRINTING]
hlp\afxprint.htm
    �o���ɮץ]�t�C�L�R�O�������D�D�C

[!endif]
makehtmlhelp.bat
    �o���ɮ׬O�իبt�νsĶ�����ɮɨϥΡC

hlp\Images\*.gif
    �o�ǬO MFC �{���w�зǩR�O���зǻ����ɥD�D�ҥ������I�}���ɡC

[!else]
hlp\[!output PROJECT_NAME].hpj
    �o���ɮ׬O�����sĶ���إ����ε{���������ɩҨϥΪ������M���ɡC

hlp\*.bmp
    �o�ǬO MFC �{���w�зǩR�O���зǻ����ɥD�D�ҥ������I�}���ɡC

hlp\*.rtf
    �o���ɮץ]�t�з� MFC �R�O�M�ù����󪺼зǻ����D�D�C
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

��L�\��:
[!if ACTIVEX_CONTROLS]

ActiveX ���
    �����ε{���]�t�ϥ� ActiveX ������䴩�C
[!endif]
[!if PRINTING]

�C�L�M�w���C�L�䴩
    Appwizard �w���͵{���X�ǥѩI�s�Ӧ� MFC �{���w CView ���O���������禡�ӳB�z
    �C�L�B�C�L�]�w�M�w���C�L�R�O�C
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]

��Ʈw�䴩
    Appwizard �w���z���{���[�J�򥻼h�Ū���Ʈw�䴩�C�u�]�t�������ɮסC
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]

���j����
    Appwizard �w���z�����ε{�����[�J���j�����䴩�C
[!endif]
[!if MAPI]

MAPI �䴩
    ���ͪ�����]�t�إߡB�ާ@�B�ǿ�M�x�s�l��T���һݭn���{���X�C
[!endif]
[!if SOCKETS]

Windows Sockets
    �����ε{���䴩�b TCP/IP �����W�إ߳q�T�C
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

��L�з��ɮ�:

StdAfx.h, StdAfx.cpp
    �o���ɮץΩ�ظm�W�� [!output PROJECT_NAME].pch ������sĶ���Y�� (PCH)�A
    �H�ΦW�� StdAfx.obj ������sĶ���O�ɡC

Resource.h
    �o�O�зǪ����Y�ɡA���w�q�s�귽 ID�C
    Microsoft Visual C++ �|Ū���ç�s���ɮסC

/////////////////////////////////////////////////////////////////////////////

��L�`�N�ƶ�:

AppWizard �ϥ� "TODO:" �Ӫ�ܱz���ӥ[�J�Φۭq����l�{���X�C
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

�p�G�z�����ε{���b�@�Ϊ� DLL ���ϥ� MFC�A�ӥB�����ε{���ϥλP�@�~�t�Τ��P��
�y���A�z�����q Microsoft Visual C++ CD-ROM �� Win\System �ؿ��U�N�۹�������
�a�y�t�Ƹ귽 MFC70XXX.DLL �ƻs��q���� system �� system32 �ؿ��A�M��N����
�s�R�W�� MFCLOC.DLL ("XXX" �N��y���Y�g�C�Ҧp�AMFC70DEU.DLL �]�t½Ķ���w�媺
�귽)�C�p�G�z�å����榹�B�J�A���ε{�������Y�� UI ���ؤ��N�ϥΧ@�~�t�ΩҥΪ�
�y���C
[!endif]

/////////////////////////////////////////////////////////////////////////////
