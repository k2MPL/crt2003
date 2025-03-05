@echo off

REM -- Cr�ez d'abord un fichier de mappage � partir du fichier resource.h g�n�r� par Microsoft Visual C++
echo // MAKEHELP.BAT fichier de mappage g�n�r� pour l'aide. Utilis� par [!output PROJECT_NAME].HHP. >"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Commandes (ID_* et IDM_*) >>"hlp\HTMLDefines.h"
makehm /h ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Invites de commandes (IDP_*) >>"hlp\HTMLDefines.h"
makehm /h IDP_,HIDP_,0x30000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Ressources (IDR_*) >>"hlp\HTMLDefines.h"
makehm /h IDR_,HIDR_,0x20000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Bo�tes de dialogue (IDD_*) >>"hlp\HTMLDefines.h"
makehm /h IDD_,HIDD_,0x20000 resource.h >>"hlp\HTMLDefines.h"
echo. >>"hlp\HTMLDefines.h"
echo // Contr�les frame (IDW_*) >>"hlp\HTMLDefines.h"
makehm /h /a afxhh.h IDW_,HIDW_,0x50000 resource.h >>"hlp\HTMLDefines.h"

REM -- G�n�rez l'aide pour le projet [!output PROJECT_NAME]

echo G�n�ration des fichiers d'aide HTML Win32
start /wait hhc "hlp\[!output PROJECT_NAME_OEM].hhp"
if not exist "hlp\[!output PROJECT_NAME_OEM].chm" goto :Error 
if exist Debug\nul copy "hlp\[!output PROJECT_NAME_OEM].chm" Debug
if exist Release\nul copy "hlp\[!output PROJECT_NAME_OEM].chm" Release
goto :done

:Error 
echo hlp\[!output PROJECT_NAME_OEM].hhp(1) : Erreur : 
echo.

:done 
echo.
