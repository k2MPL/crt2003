@echo off
[!if HM_NOTE]

REM -- ���ӎ��� : OEM �� ANSI �����Z�b�g�̈Ⴂ
REM -- ANSI �����Z�b�g���g�p����ƁA�قƂ�ǂ̃G�f�B�^�ł́A
REM -- ���L�̂悤�Ƀt�@�C���������ĕ\������܂��B  
REM -- �o�b�` �t�@�C��������ɓ��삷�邽�߂ɂ́AANSI �ł͂Ȃ� OEM �����Z�b�g���g�p���Ă��������B
REM -- �o�͂ƃG�f�B�^ �E�B���h�E�� ANSI �����Z�b�g�œ��삵�܂��B
REM -- �o�̓E�B���h�E�ɂ������O���\�������ꍇ�́AANSI �����Z�b�g�̂܂܂ɂ��Ă���܂��B

[!endif]
REM -- �ŏ��� Microsoft Visual C++ �Ő������� resource.h �Ń}�b�v �t�@�C�����쐬���܂��B
echo // MAKEHELP.BAT �������ꂽ�w���v �}�b�v �t�@�C���ł��B[!output PROJECT_NAME].HPJ �Ŏg�p����܂��B >"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // �R�}���h (ID_* and IDM_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // �\�� (IDP_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ���\�[�X (IDR_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // �_�C�A���O (IDD_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // �t���[�� �R���g���[�� (IDW_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
REM -- �v���W�F�N�g [!output PROJECT_NAME] �̃w���v���쐬���܂��B

echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\[!output PROJECT_NAME_OEM].hpj"
if errorlevel 1 goto :Error
if not exist "hlp\[!output PROJECT_NAME_OEM].hlp" goto :Error
if not exist "hlp\[!output PROJECT_NAME_OEM].cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\[!output PROJECT_NAME_OEM].hlp" Debug
if exist Debug\nul copy "hlp\[!output PROJECT_NAME_OEM].cnt" Debug
if exist Release\nul copy "hlp\[!output PROJECT_NAME_OEM].hlp" Release
if exist Release\nul copy "hlp\[!output PROJECT_NAME_OEM].cnt" Release
echo.
goto :done

:Error
echo hlp\[!output PROJECT_NAME].hpj(1) : �G���[ : �w���v �t�@�C���̍쐬���ɖ�肪�������܂����B

:done
echo.
