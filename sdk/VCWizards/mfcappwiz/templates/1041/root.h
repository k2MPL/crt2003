// [!output APP_HEADER] : [!output PROJECT_NAME] �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error ���̃t�@�C���� PCH �Ɋ܂߂�O�ɁA'stdafx.h' ���܂߂Ă��������B
#endif

#include "resource.h"       // ���C�� �V���{��


// [!output APP_CLASS]:
// ���̃N���X�̎����ɂ��ẮA[!output APP_IMPL] ���Q�Ƃ��Ă��������B
//

class [!output APP_CLASS] : public [!output APP_BASE_CLASS]
{
public:
	[!output APP_CLASS]();

[!if APP_TYPE_MTLD]
[!if !DOCVIEW]
	CArray<HWND, HWND> m_aryFrames;
[!else]
protected:
	CMultiDocTemplate* m_pDocTemplate;
[!endif]
public:
[!endif]

// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();
[!if APP_TYPE_MDI]
[!if !DOCVIEW]
	virtual int ExitInstance();
[!endif]
[!endif]

// ����
[!if FULL_SERVER || MINI_SERVER || CONTAINER_SERVER || AUTOMATION]
	COleTemplateServer m_server;
		// �h�L�������g���쐬���邽�߂̃T�[�o�[ �I�u�W�F�N�g
[!endif]
[!if !DOCVIEW]
[!if !APP_TYPE_SDI]
protected:
	HMENU m_hMDIMenu;
	HACCEL m_hMDIAccel;
[!endif]

public:
[!endif]
	afx_msg void OnAppAbout();
[!if !DOCVIEW]
[!if APP_TYPE_MDI]
	afx_msg void OnFileNew();
[!endif]
[!endif]
[!if APP_TYPE_MTLD]
	afx_msg void OnFileNewFrame();
[!if DOCVIEW]
	afx_msg void OnFileNew();
[!endif]
[!endif]
	DECLARE_MESSAGE_MAP()
};

extern [!output APP_CLASS] theApp;
