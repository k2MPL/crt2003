// stdafx.h : Fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets qui sont utilis�s fr�quemment,
// et sont rarement modifi�s

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclure les en-t�tes Windows rarement utilis�s
#endif

// Modifiez les d�finitions suivantes si vous devez cibler une plate-forme avant celles sp�cifi�es ci-dessous.
// Reportez-vous � MSDN pour obtenir les derni�res informations sur les valeurs correspondantes pour les diff�rentes plates-formes.
#ifndef WINVER				// Autorise l'utilisation des fonctionnalit�s sp�cifiques � Windows�95 et Windows NT�4 ou version ult�rieure.
#define WINVER 0x0400		// Attribuez la valeur appropri�e � cet �l�ment pour cibler Windows�98 et Windows�2000 ou version ult�rieure.
#endif

#ifndef _WIN32_WINNT		// Autorise l'utilisation des fonctionnalit�s sp�cifiques � Windows NT�4 ou version ult�rieure.
#define _WIN32_WINNT 0x0400		// Attribuez la valeur appropri�e � cet �l�ment pour cibler Windows�98 et Windows�2000 ou version ult�rieure.
#endif						

#ifndef _WIN32_WINDOWS		// Autorise l'utilisation des fonctionnalit�s sp�cifiques � Windows�98 ou version ult�rieure.
#define _WIN32_WINDOWS 0x0410 // Attribuez la valeur appropri�e � cet �l�ment pour cibler Windows�Me ou version ult�rieure.
#endif

#ifndef _WIN32_IE			// Autorise l'utilisation des fonctionnalit�s sp�cifiques � IE�4.0 ou version ult�rieure.
#define _WIN32_IE 0x0400	// Attribuez la valeur appropri�e � cet �l�ment pour cibler IE�5.0 ou version ult�rieure.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// certains constructeurs CString seront explicites

// d�sactive le masquage MFC de certains messages d'avertissement courants et par ailleurs souvent ignor�s
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // composants MFC principaux et standard
#include <afxext.h>         // extensions MFC
[!if APP_TYPE_MTLD && !DOCVIEW]
#include <afxtempl.h>		// classes de collection MFC
[!endif]
[!if TREE_VIEW || LIST_VIEW || PROJECT_STYLE_EXPLORER]
#include <afxcview.h>
[!endif]

[!if CONTAINER || MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
#include <afxole.h>         // classes OLE MFC
[!if CONTAINER || CONTAINER_SERVER]
#include <afxodlgs.h>       // classes de bo�te de dialogue OLE MFC
[!endif]
[!endif]

[!if AUTOMATION || ACTIVEX_CONTROLS]
#include <afxdisp.h>        // Classes MFC Automation
[!endif]

[!if ACTIVE_DOC_SERVER]
#include <afxdocob.h>
[!endif]

[!if DB_SUPPORT_HEADER_ONLY || DB_VIEW_NO_FILE]
 // Ici, une prise en charge minimale des bases de donn�es est demand�e. Aucune vue n'est s�lectionn�e.
[!endif]
[!if DB_VIEW_WITH_FILE]
 // Ici, une prise en charge des bases de donn�es est s�lectionn�e avec une vue.
[!endif]

#include <afxdtctl.h>		// Prise en charge des MFC pour les contr�les communs Internet Explorer 4
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Prise en charge des MFC pour les contr�les communs Windows
#endif // _AFX_NO_AFXCMN_SUPPORT

[!if HTML_VIEW || HTML_EDITVIEW]
#include <afxhtml.h>			// Prise en charge MFC du mode HTML
[!endif]

[!if SOCKETS]
#include <afxsock.h>		// extensions du socket MFC
[!endif] 

[!if RICH_EDIT_VIEW]
#include <afxrich.h>		// classes RichEdit MFC
[!endif] 

[!if ATL_SUPPORT]
#include <atlbase.h>
extern CComModule _Module;
[!endif]

[!if OLEDB]
#include <atlbase.h>
#include <afxoledb.h>
#include <atlplus.h>
[!endif]
[!if DB_SUPPORT_OLEDB && DB_SUPPORT_HEADER_ONLY ]
#include <atlbase.h>
#include <afxoledb.h>
#include <atlplus.h>
[!endif]

[!if ODBC]
#include <afxdb.h>        // ODBC
[!endif]
[!if DB_SUPPORT_ODBC && DB_SUPPORT_HEADER_ONLY ]
#include <afxdb.h>        // ODBC
[!endif]

[!if HTML_DIALOG]
#include <afxdhtml.h>        // Bo�tes de dialogue HTML
[!endif]

[!if APP_TYPE_DLG]
[!if AUTOMATION]
// Cette macro est semblable � IMPLEMENT_OLECREATE, � la diff�rence qu'elle passe au constructeur COleObjectFactory
// la valeur TRUE pour le param�tre bMultiInstance.
// Une instance distincte de cette application doit �tre d�marr�e pour
// chaque objet proxy Automation demand� par les contr�leurs Automation.
#ifndef IMPLEMENT_OLECREATE2
#define IMPLEMENT_OLECREATE2(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), TRUE, _T(external_name)); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } };
#endif // IMPLEMENT_OLECREATE2
[!endif]
[!endif]

