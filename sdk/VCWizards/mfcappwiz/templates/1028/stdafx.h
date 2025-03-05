// stdafx.h : �зǨt�� Include �ɪ� Include �ɡA
// �άO�g�`�ϥΫo�ܤ��ܧ󪺱M�ױM�� Include �ɮ�

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// �q Windows ���Y�ư����`�ϥΪ�����
#endif

// �p�G�z�������u����������x�A�Эק�U�C�w�q�C
// �Ѧ� MSDN ���o���P���x�����Ȫ��̷s��T�C
#ifndef WINVER				// ���\�ϥ� Windows 95 �P Windows NT 4 (�t) �H�᪩�����S�w�\��C
#define WINVER 0x0400		// �N���ܧ󬰰w�� Windows 98 �M Windows 2000 (�t) �H�᪩���A���ȡC
#endif

#ifndef _WIN32_WINNT		// ���\�ϥ� Windows NT 4 (�t) �H�᪩�����S�w�\��C
#define _WIN32_WINNT 0x0400		// �N���ܧ󬰰w�� Windows 98 �M Windows 2000 (�t) �H�᪩���A���ȡC
#endif						

#ifndef _WIN32_WINDOWS		// ���\�ϥ� Windows 98 (�t) �H�᪩�����S�w�\��C
#define _WIN32_WINDOWS 0x0410 // �N���ܧ󬰰w�� Windows Me (�t) �H�᪩���A���ȡC
#endif

#ifndef _WIN32_IE			// ���\�ϥ� IE 4.0 (�t) �H�᪩�����S�w�\��C
#define _WIN32_IE 0x0400	// �N���ܧ󬰰w�� IE 5.0 (�t) �H�᪩���A���ȡC
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// ���T�w�q������ CString �غc�禡

// ���� MFC ���ä@�Ǳ`���Υi����ĵ�i�T�����\��
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC �֤߻P�зǤ���
#include <afxext.h>         // MFC �X�R�\��
[!if APP_TYPE_MTLD && !DOCVIEW]
#include <afxtempl.h>		// MFC ���X���O
[!endif]
[!if TREE_VIEW || LIST_VIEW || PROJECT_STYLE_EXPLORER]
#include <afxcview.h>
[!endif]

[!if CONTAINER || MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
#include <afxole.h>         // MFC OLE ���O
[!if CONTAINER || CONTAINER_SERVER]
#include <afxodlgs.h>       // MFC OLE ��ܤ�����O
[!endif]
[!endif]

[!if AUTOMATION || ACTIVEX_CONTROLS]
#include <afxdisp.h>        // MFC Automation ���O
[!endif]

[!if ACTIVE_DOC_SERVER]
#include <afxdocob.h>
[!endif]

[!if DB_SUPPORT_HEADER_ONLY || DB_VIEW_NO_FILE]
 // �b���A�����n�D�̤p�� DB �䴩�C�S������˵��C
[!endif]
[!if DB_VIEW_WITH_FILE]
 // �b���A�w�g��ܦ��˵��� DB �䴩�C
[!endif]

#include <afxdtctl.h>		// MFC �䴩�� Internet Explorer 4 �q�α��
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC �䴩�� Windows �q�α��
#endif // _AFX_NO_AFXCMN_SUPPORT

[!if HTML_VIEW || HTML_EDITVIEW]
#include <afxhtml.h>			// MFC HTML �˵��䴩
[!endif]

[!if SOCKETS]
#include <afxsock.h>		// MFC �q�T���X�R�\��
[!endif] 

[!if RICH_EDIT_VIEW]
#include <afxrich.h>		// MFC Rich Edit ���O
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
#include <afxdhtml.h>        // HTML ��ܤ��
[!endif]

[!if APP_TYPE_DLG]
[!if AUTOMATION]
// ���F��� bMultiInstance �Ѽƶǻ� TRUE �� COleObjectFactory �غc�禡�~�A
// �������P IMPLEMENT_OLECREATE �ۦP�C�ڭ̻ݭn�����ε{�������}�������
// �H�� Automation ����ҭn�D�� Automation Proxy ����ҰʡC
#ifndef IMPLEMENT_OLECREATE2
#define IMPLEMENT_OLECREATE2(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF COleObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), TRUE, _T(external_name)); \
	const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } };
#endif // IMPLEMENT_OLECREATE2
[!endif]
[!endif]

