@echo off
[!if HM_NOTE]

REM – TENGA EN CUENTA QUE EL JUEGO DE CARACTERES DE OEM ESTABLECE DIFERENCIAS FRENTE AL DE CARACTERES ANSI
REM – Muchos de los siguientes nombres de archivo tienen un aspecto extraño en la mayoría de los editores porque es 
REM – necesario que aparezcan en el juego de caracteres de OEM y no en el de caracteres de ANSI para que los archivos por 
REM – lotes funcionen de forma correcta. La ventana de resultados y la del editor funcionan con el juego de caracteres ANSI.  
REM – Cuando los nombres sólo se ven en la ventana de resultados, se han dejado en el 
REM – juego de caracteres ANSI.

[!endif]
REM – En primer lugar, crear un archivo de asignaciones de resource.h generado de Microsoft Visual C++ 
echo // Archivo MAKEHELP.BAT de asignaciones de Ayuda generado. Utilizado por [!output PROJECT_NAME].HPJ. >"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Comandos (ID_* and IDM_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Indicadores (IDP_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Recursos (IDR_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Cuadros de diálogo (IDD_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
echo. >>"hlp\[!output HM_FILE_OEM].hm"
echo // Controles Frame (IDW_*) >>"hlp\[!output HM_FILE_OEM].hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\[!output HM_FILE_OEM].hm"
REM -- Crear ayuda para el proyecto [!output PROJECT_NAME]

echo Generando archivos de Ayuda Win32 HTML
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
echo hlp\[!output PROJECT_NAME].hpj(1) : error: Se encontró un problema al crear un archivo de ayuda

:done
echo.
