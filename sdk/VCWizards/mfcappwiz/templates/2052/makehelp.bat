@echo off
[!if HM_NOTE]

REM -- ��ע�⣺OEM �� ANSI �ַ����Ĳ��
REM -- �ڶ����༭������������ļ�����������ܹ֡�Ϊ��ȷ���������ļ���ȷ���У���Щ�ļ�������ʹ�� ANSI �ַ�����������
REM -- ʹ�� OEM �ַ�����������ںͱ༭���ڿ�֧�� ANSI �ַ�����������ֻ���������������ʾ�����ǲ��õ��� ANSI �ַ�����

[!endif]
REM -- ���ȴ� Microsoft Visual C++ ���ɵ� resource.h ��ӳ���ļ�
echo // MAKEHELP.BAT ���ɵġ�������ӳ���ļ������� [!output PROJECT_NAME].HPJ. >"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ���� (ID_* and IDM_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ��ʾ (IDP_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ��Դ (IDR_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // �Ի��� (IDD_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // ��ܿؼ� (IDW_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
REM -- ������Ŀ���� [!output PROJECT_NAME]

echo �������� Win32 �����ļ�
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
echo hlp\[!output PROJECT_NAME].hpj(1) : ���󣺴��������ļ�ʱ��������

:done
echo.
