================================================================================
    MICROSOFT FOUNDATION CLASS ���C�u���� : [!output PROJECT_NAME] �v���W�F�N�g�̊T�v
===============================================================================



    �A�v���P�[�V���� �E�B�U�[�h���쐬���� [!output PROJECT_NAME] �ɂ� Microsoft 
    Foundation Classes �̊�{�I�Ȏg������������Ă��܂��B�A�v���P�[�V�����쐬�̂ЂȌ^�Ƃ��Ă��g��
    ���������B
    ���̃t�@�C���ɂ� [!output PROJECT_NAME] �A�v���P�[�V�������\�����Ă���e�t�@�C���̊T�v��������
    �܂�Ă��܂��B

[!output PROJECT_NAME].vcproj
    ����̓A�v���P�[�V���� �E�B�U�[�h�Ő������ꂽ VC++ �v���W�F�N�g�̃��C�� �v���W�F�N�g �t�@�C	    ���ł��B�t�@�C�����������ꂽ Visual C++ �̃o�[�W������񂪊܂܂�Ă��܂��B�܂��A�A�v���P�[�V	    ���� �E�B�U�[�h�őI�������v���b�g�t�H�[���A�\������уv���W�F�N�g�@�\�Ɋւ�������܂܂�		    �Ă��܂��B


[!output APP_HEADER]
    ���̃t�@�C���̓A�v���P�[�V�����̒��S�ƂȂ�w�b�_�[ �t�@�C���ł��B���̃t�@�C���ɂ́AResource.h 
    ���܂݁A���̃v���W�F�N�g����̃w�b�_���܂܂�Ă��āA[!output APP_CLASS] �A�v���P�[�V���� �N���X
    �̐錾�����܂��B

[!output APP_IMPL]
    ���̃t�@�C���� [!output APP_CLASS] �A�v���P�[�V�����N���X���܂ރA�v���P�[�V�����̒��S�ƂȂ�\�[
    �X�t�@�C���ł��B

[!output PROJECT_NAME].rc
    ���̃t�@�C���̓v���O�������g�p���� Microsoft Windows �̃��\�[�X��񋓂��܂��B���̃t�@�C���� RES 
    �T�u�f�B���N�g���ɕۑ�����Ă���A�C�R���A�r�b�g�}�b�v�A�J�[�\�����܂݂܂��B���̃t�@�C���́A
    Microsoft Visual C++ �Œ��ڕҏW�\�ł��B�v���W�F�N�g ���\�[�X�� [!output LCID] �ɂ���܂��B

res\[!output SAFE_PROJECT_NAME].ico
    ���̃t�@�C���́A�A�v���P�[�V�����̃A�C�R���Ƃ��Ďg�p�����A�C�R���t�@�C���ł��B���̃A�C�R����
    ���\�[�X �t�@�C�� [!output PROJECT_NAME].rc �ɂ���ăC���N���[�h����܂��B

res\[!output SAFE_PROJECT_NAME].rc2
    ���̃t�@�C���� Microsoft Visual C++ �ɂ���ĕҏW����Ȃ����\�[�X���܂�ł��܂��B���̃t�@�C����
    ���\�[�X �G�f�B�^�ŕҏW����Ȃ����ׂẴ��\�[�X���L�q���Ă��������B
[!if CONTAINER_SERVER || FULL_SERVER || MINI_SERVER || AUTOMATION || HAS_SUFFIX]
[!if !HTML_EDITVIEW]
[!output PROJECT_NAME].reg
    ���̃��W�X�g�� �t�@�C���̓t���[�����[�N�̐ݒ�@���Љ�邽�߂̃T���v�� �t�@�C���ł��B�A�v���P�[
    �V�����Ƌ��� .reg [!if APP_TYPE_DLG] �t�@�C���Ƃ��Ďg�p���܂��B
[!else]
    �A�v���P�[�V�����ƈꏏ�Ɏg�p���邩�A�܂��͍폜���ăf�t�H���g�̓o�^ RegisterShellFileTypes ���g�p
    ���܂��B
[!endif]

[!if AUTOMATION]
[!output PROJECT_NAME].idl
    ���̃t�@�C���̓A�v���P�[�V�����̃^�C�v ���C�u�����p�̃C���^�[�t�F�[�X�L�q����\�[�X �R�[�h���܂�
    �ł��܂��B
[!endif]
[!endif]
[!endif]

[!if !APP_TYPE_DLG]
/////////////////////////////////////////////////////////////////////////////

���C�� �t���[�� �E�B���h�E :
[!if PROJECT_STYLE_EXPLORER]
    Windows Explorer Style: �����̃v���W�F�N�g�́A2 �t���[�������� Windows Explorer �̂悤�ȃC��
    �^�[�t�F�[�X���܂݂܂��B
[!else]
    �v���W�F�N�g�͕W���� MFC �C���^�[�t�F�[�X���܂݂܂��B
[!endif]

[!output MAIN_FRAME_HEADER], [!output MAIN_FRAME_IMPL]
    �����̃t�@�C���́A[!if APP_TYPE_MDI] ����h�������ׂĂ� MDI �t���[���@ �\�𐧌䂷��t���[�� 
    �N���X [!output MAIN_FRAME_CLASS] CMDIFrameWnd ���܂݂܂��B
    
[!else]
    CFrameWnd �ŁA���ׂĂ� MDI �t���[���@�\�𐧌䂵�܂��B
[!endif]
[!if PROJECT_STYLE_EXPLORER]

[!output TREE_VIEW_HEADER], [!output TREE_VIEW_IMPL]
    �����̃t�@�C���� CTreeView ����h���������t���[�� �N���X [!output TREE_VIEW_CLASS] ���܂�
    �܂��B
   
[!endif]

[!if DOCKING_TOOLBAR]
res\Toolbar.bmp
    ���̃r�b�g�}�b�v �t�@�C���̓c�[���o�[�̃C���[�W�Ƃ��Ďg���܂��B
    �c�[���o�[��X�e�[�^�X�o�[�̏����ݒ�� [!output MAIN_FRAME_CLASS] �N���X�ɂ���ăr���h����܂��B
    �c�[���o�[�̃{�^���R���g���[����ǉ����������ɂ̓c�[���o�[�̃r�b�g�}�b�v�����\�[�X�G�f�B�^��
    �ҏW���A[!output PROJECT_NAME].rc �t�@�C������ IDR_MAINFRAME TOOLBAR �z���ύX���Ă��������B
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

res\IToolbar.bmp
    �T�[�o�[ �A�v���P�[�V���������̃R���e�i�Ŗ��߂��ݐ�N�������Ƃ��ɁA���̃r�b�g�}�b�v �t�@�C����
    �c�[���o�[�̃^�C�� �C���[�W�Ƃ��Ďg���܂��B���̃c�[���o�[�� [!output INPLACE_FRAME_CLASS] �N 
    ���X�ɂ���ăr���h����܂��B���̃r�b�g�}�b�v�́A�����̔�T�[�o�[ �R�}���h��������Ă��邱�Ƃ����� 
    �� res\Toolbar.bmp ���̃r�b�g�}�b�v�Ƌ��ʂł��B

[!endif]
[!endif]
[!if APP_TYPE_MDI]
/////////////////////////////////////////////////////////////////////////////

�q�E�B���h�E �t���[�� :

ChildFrm.h, ChildFrm.cpp
    �����̃t�@�C���� [!output CHILD_FRAME_CLASS] �N���X�̒�`�ƃC���v�������e�[�V�������s���܂��B 
    ���̃N���X�� MDI �A�v���P�[�V�����̎q�E�B���h�E���T�|�[�g���邽�߂̂��̂ł��B

[!endif]
/////////////////////////////////////////////////////////////////////////////

[!if DOCVIEW]
[!if !DB_VIEW_NO_FILE]
�A�v���P�[�V���� �E�B�U�[�h�� 1 �̃h�L�������g�^�C�v�� 1 �̃r���[���쐬���܂�:

[!output DOC_HEADER], [!output DOC_IMPL] - �h�L�������g
    �����̃t�@�C���� [!output DOC_CLASS] �N���X���܂݂܂��B���ʂȃh�L�������g �f�[�^��t�������� 
    ��A�t�@�C���̕ۑ��� (via [!output DOC_CLASS]::Serialize) ��ǂݍ��񂾂肷��ɂ́A���̃t�@�C�� 
    ��ҏW���Ă��������B
[!if HAS_SUFFIX && !HTML_EDITVIEW]
    �h�L�������g�ɂ͎��̕����񂪊܂܂�܂� :
        �t�@�C���̊g���q :             [!output FILE_EXTENSION]
        �t�@�C���̎�ނ̎��ʎq :       [!output FILE_TYPE_ID]
        ���C�� �t���[�� �L���v�V���� : [!output MAIN_FRAME_CAPTION]
        �h�L�������g�̎�ނ̖��O :     [!output DOC_TYPE_NAME]
        �t�B���^�� :                   [!output FILTER_NAME]
        �t�@�C���̐V�����Z�����O :     [!output FILE_NEW_NAME_SHORT]
        �t�@�C���̎�ނ̒������O :     [!output FILE_NEW_NAME_LONG]
[!endif]
[!else]
�A�v���P�[�V���� �E�B�U�[�h�� 1 �̃r���[���쐬���܂� :
[!endif]

[!output VIEW_HEADER], [!output VIEW_IMPL] - �h�L�������g�̃r���[
    �����̃t�@�C���� [!output VIEW_CLASS] �N���X���܂݂܂��B
[!if !DB_VIEW_NO_FILE]
    [!output VIEW_CLASS] �I�u�W�F�N�g�� [!output DOC_CLASS] �I�u�W�F�N�g��\�����邽�߂Ɏg�p���� 
    �܂��B
[!endif]

[!if APP_TYPE_MDI]
res\[!output SAFE_PROJECT_NAME]Doc.ico
    ���̃t�@�C���� [!output DOC_CLASS] �N���X�� MDI �q�E�B���h�E�p�A�C�R���Ƃ��Ďg����A�C�R��  
    �t�@�C���ł��B���̃A�C�R���̓��\�[�X�t�@�C�� [!output PROJECT_NAME].rc �ɂ���ăC���N���[�h 
    ����܂��B
[!endif]

[!endif]

[!if DB_VIEW_NO_FILE || DB_VIEW_WITH_FILE]
/////////////////////////////////////////////////////////////////////////////
�f�[�^�x�[�X �T�|�[�g :

[!output ROWSET_HEADER], [!output ROWSET_IMPL]
    �����̃t�@�C���ɂ� [!output ROWSET_CLASS] �N���X���܂܂�Ă��܂��B���̃N���X�̓E�B�U�[�h�� 
    �I�������f�[�^ �\�[�X�ɃA�N�Z�X����̂Ɏg�p����܂��B
[!if DB_VIEW_NO_FILE]
    �V���A�����T�|�[�g�͒ǉ�����܂���B
[!else]
    �V���A�����T�|�[�g���ǉ�����܂����B
[!endif]
[!endif]
[!if CONTAINER || FULL_SERVER || MINI_SERVER || CONTAINER_SERVER]
/////////////////////////////////////////////////////////////////////////////

�A�v���P�[�V���� �E�B�U�[�h�� OLE �ɓ���̃N���X���쐬���܂����B

[!if CONTAINER || CONTAINER_SERVER]
[!output CONTAINER_ITEM_HEADER], [!output CONTAINER_ITEM_IMPL]
    �����̃t�@�C���� [!output CONTAINER_ITEM_CLASS] �N���X���܂݂܂��B���̃N���X�� OLE �I�u�W�F�N 
    �g�̑���Ɏg���܂��BOLE �I�u�W�F�N�g�� [!output VIEW_CLASS] �N���X�ɂ���ĕ\������A 
    [!output DOC_CLASS] �N���X�̈ꕔ���Ƃ��ăV���A��������܂��B
[!if ACTIVE_DOC_CONTAINER]
    ���̃v���O�����́A�t���[�����ŃA�N�e�B�u �h�L�������g�𑀍삷�邽�߂̃T�|�[�g���܂݂܂��B
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

[!output SERVER_ITEM_HEADER], [!output SERVER_ITEM_IMPL]
    �����̃t�@�C���� [!output SERVER_ITEM_CLASS] ���܂݂܂��B���̃N���X�� [!output DOC_CLASS]  
    �N���X�� OLE �V�X�e���ɐڑ����A�K�v�ł���΃h�L�������g�Ƀ����N��ݒ肷�邽�߂Ɏg���܂��B
    
[!if ACTIVE_DOC_SERVER]
    �v���W�F�N�g�̓A�N�e�B�u �h�L�������g���쐬���Ǘ����邽�߂̃T�|�[�g�����܂��B
[!endif]

[!output INPLACE_FRAME_HEADER], [!output INPLACE_FRAME_IMPL]
    �����̃t�@�C���� [!output INPLACE_FRAME_CLASS] �܂݂܂��B���̃N���X�� COleIPFrameWnd ���� 
    �h�����A���ߍ��ݐ�ŋN������Ă���Ԃ��ׂẴt���[���̋@�\�𐧌䂵�܂��B
[!endif]

[!if SUPPORT_COMPOUND_FILES]
    ���̃v���W�F�N�g�͕����t�@�C�����T�|�[�g���܂��B�����t�@�C���t�H�[�}�b�g�́A1 �̃t�@�C���̒� 
    �� 1 �ȏ�̎����I�u�W�F�N�g�����h�L�������g��ۑ����܂��B�܂��t�@�C���̒��̃I�u�W�F�N�g�ɂ� 
    �ʂɃA�N�Z�X���邱�Ƃ��ł��܂��B
[!endif]
[!endif]
[!else]

/////////////////////////////////////////////////////////////////////////////

[!if AUTOMATION]
�A�v���P�[�V���� �E�B�U�[�h�� 1 �̃_�C�A���O �N���X����уI�[�g���[�V���� �v���L�V �N���X���쐬 
    ���܂� :
[!else]
�A�v���P�[�V���� �E�B�U�[�h�� 1 �̃_�C�A���O �N���X���쐬���܂� :
[!endif]

[!output DIALOG_HEADER], [!output DIALOG_IMPL] - the dialog
    T�����̃t�@�C���� [!output DIALOG_CLASS] �N���X���܂݂܂��B���̃N���X�̓A�v���P�[�V������ 
    ���C�� �_�C�A���O�̓�����`���܂��B�_�C�A���O �e���v���[�g�� Microsoft Visual C++ �ŕҏW 
    �\�� [!output PROJECT_NAME].rc �Ɋ܂܂�܂��B
[!if AUTOMATION]

[!output DIALOG_AUTO_PROXY_HEADER], [!output DIALOG_AUTO_PROXY_IMPL] - �I�[�g���[�V���� �I�u�W�F�N�g
    �����̃t�@�C���� [!output DIALOG_AUTO_PROXY_CLASS] �N���X���܂݂܂��B���̃N���X�̓_�C�A���O�p 
    �� "�I�[�g���[�V���� �v���L�V" �N���X�ƌĂ΂�܂��B���R�̓I�[���[�V���� �R���g���[�����_�C�A���O 
    �ɃA�N�Z�X���邽�߂Ɏg�p�\�ȃI�[�g���[�V���� ���\�b�h����уv���p�e�B�̕\�����s�����߂ł��B�� 
    ���̃��\�b�h����уv���p�e�B�̓_�C�A���O �N���X���璼�ڕ\������܂���B����̓_�C�A���O �x�[�X 
    �� MFC �A�v���P�[�V���� ���f���̏ꍇ�A�I�[�g���[�V���� �I�u�W�F�N�g�ƃ��[�U�[ �C���^�[�t�F�C�X�� 
    �ʁX�ɂ��Ă������Ƃ��Ȍ��ŊȒP������ł��B
[!endif]
[!endif]

[!if CONTEXT_HELP]
/////////////////////////////////////////////////////////////////////////////

�w���v �T�|�[�g :

[!if HELPSTYLE_HTML]
hlp\[!output PROJECT_NAME].hhp
    ���̃t�@�C���̓w���v �v���W�F�N�g �t�@�C���ł��B�w���v �t�@�C���� .chm �t�@�C���ɃR���p�C������ 
    �̂ɕK�v�ȃf�[�^���܂�ł��܂�

hlp\[!output PROJECT_NAME].hhc
    ���̃t�@�C���̓w���v �v���W�F�N�g�̃R���e���c�ꗗ��\�����܂��B

hlp\[!output PROJECT_NAME].hhk
    ���̃t�@�C���̓w���v �g�s�b�N�̃C���f�b�N�X���܂݂܂��B

hlp\afxcore.htm
    ���̃t�@�C���͕W���� MFC �R�}���h�Ɖ�ʃI�u�W�F�N�g�p�̕W���w���v �g�s�b�N���܂݂܂��B�C�ӂ� 
    �w���v �g�s�b�N�����̃t�@�C���ɒǉ����Ă��������B

[!if PRINTING]
hlp\afxprint.htm
    ���̃t�@�C���͈���R�}���h�p�̃w���v �g�s�b�N���܂݂܂��B

[!endif]
makehtmlhelp.bat
    ���̃t�@�C���̓w���v �t�@�C�����R���p�C�����邽�߂Ƀr���h �V�X�e���Ŏg�p���܂��B

hlp\Images\*.gif
    �����̃t�@�C���� Microsoft Foundation Class ���C�u�����̕W���R�}���h�� �ւ���W���w���v �t�@ 
    �C���̃g�s�b�N�Ŏg�p����r�b�g�}�b�v �t�@�C���ł��B
[!else]
hlp\[!output PROJECT_NAME].hpj
    ���̃t�@�C���̓w���v �R���p�C�����A�v���P�[�V�����̃w���v �t�@�C�����쐬���邽�߂̃w���v �v�� 
    �W�F�N�g �t�@�C���ł��B

hlp\*.bmp
    �����̃t�@�C���� Microsoft Foundation Class ���C�u�����̕W���R�}���h�Ɋւ���W���w���v �t�@ 
    �C���̃g�s�b�N�Ŏg�p����r�b�g�}�b�v �t�@�C���ł��B

hlp\*.rtf
    �����̃t�@�C���͕W�� MFC �R�}���h�Ɖ�ʃI�u�W�F�N�g�Ɋւ���W���w���v �g�s�b�N���܂�ł��܂��B
[!endif]
[!endif]

[!if ACTIVEX_CONTROLS || PRINTING || SPLITTER || MAPI || SOCKETS]
/////////////////////////////////////////////////////////////////////////////

���̑��̋@�\ :
[!if ACTIVEX_CONTROLS]

ActiveX �R���g���[��
    �A�v���P�[�V������ ActiveX �R���g���[���̎g�p�Ɋւ���T�|�[�g���܂݂܂��B
[!endif]
[!if PRINTING]

����ƈ���v���r���[�̃T�|�[�g
    �A�v���P�[�V���� �E�B�U�[�h�ł� MFC ���C�u�������� CView �N���X�̃����o�֐����Ăяo�����Ƃɂ�� 
    �āA����A����̐ݒ�A�����Ĉ���v���r���[�R�}���h�������ł���悤�R�[�h�������s���܂����B
[!endif]
[!if DB_SUPPORT_HEADER_ONLY && !APP_TYPE_DLG]
�f�[�^�x�[�X �T�|�[�g
    �A�v���P�[�V���� �E�B�U�[�h�Ƀv���O�����̂��ߊ�{�I�ȃ��x���̃f�[�^�x�[�X �T�|�[�g���ǉ������ 
    �����B�K�v�ȃt�@�C���݂̂��܂܂�Ă��܂��B
[!endif]
[!if SPLITTER && !APP_TYPE_DLG]
�����E�B���h�E
    �A�v���P�[�V���� �E�B�U�[�h��The application wizard has added support for �A�v���P�[�V���� �h 
    �L�������g�p�ɕ����E�B���h�E�̃T�|�[�g��ǉ����܂����B
[!endif]
[!if MAPI]

MAPI �T�|�[�g
    �������ꂽ�v���W�F�N�g�ɂ̓��[�� ���b�Z�[�W���쐬�A����A���M�A�����ĕۑ����邽�߂ɕK�v�ȃR�[�h 
    ���܂܂�Ă��܂��B
[!endif]
[!if SOCKETS]

Windows �\�P�b�g 
    �A�v���P�[�V������ TCP/IP �l�b�g���[�N��ʂ����R�~���j�P�[�V�����̊m���̃T�|�[�g�����܂��B
[!endif]

[!endif]
/////////////////////////////////////////////////////////////////////////////

���̑��̕W���t�@�C�� :

StdAfx.h, StdAfx.cpp
    �����̃t�@�C���͊��ɃR���p�C�����ꂽ�w�b�_�[ �t�@�C�� (PCH) [!output PROJECT_NAME].pch ����ɃR�� 
    �p�C�����ꂽ�^�̃t�@�C�� StdAfx.obj ���r���h���邽�߂Ɏg����t�@�C���ł��B

Resource.h
    ���̃t�@�C���͐V�K���\�[�X ID ���`����W���w�b�_�[ �t�@�C���ł��BMicrosoft Visual C++ �͂��� 
    �t�@�C���̓ǂݍ��ƍX�V���s���܂��B

/////////////////////////////////////////////////////////////////////////////

���̑��̒��� :

�A�v���P�[�V���� �E�B�U�[�h�� "TODO:" �Ŏn�܂�R�����g���g�p���āA�ǉ�������J�X�^�C�Y�̕K�v�� 
    �\�[�X �R�[�h�̕����������܂��B
[!if APP_TYPE_MDI || APP_TYPE_SDI || APP_TYPE_DLG || APP_TYPE_MTLD]

�A�v���P�[�V�����ŋ��L DLL ���� MFC ���g�p����ꍇ��A�A�v���P�[�V�������I�y���[�e�B���O �V�X�e���Ō��ݎg�p���Ă��錾��ȊO�̌�����g�p���Ă���ꍇ�́AWin\System �f�B���N�g���ɂ��� Microsoft Visual C++ CD-ROM ����A���[�J���C�Y���ꂽ���\�[�X�ɑΉ����� MFC70XXX.DLL �� system �܂��� system32 �f�B���N�g���ɃR�s�[���āA�t�@�C������ MFCLOC.DLL �ɂ���K�v������܂��B("XXX" �͌���̏ȗ��`�������܂��B�Ⴆ�΁AMFC70JPN.DLL �͓��{��ɖ|�󂳂ꂽ���\�[�X���܂݂܂��B) ���̗�𖳎�����ƃA�v���P�[�V�������̂������� UI �v�f�̓I�y���[�e�B���O �V�X�e���̌���̂܂܎c��܂��B
[!endif]

/////////////////////////////////////////////////////////////////////////////
