// [!output INPLACE_FRAME_HEADER] : [!output INPLACE_FRAME_CLASS] �N���X�̃C���^�[�t�F�C�X
//

#pragma once

class [!output INPLACE_FRAME_CLASS] : public [!output INPLACE_FRAME_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output INPLACE_FRAME_CLASS])
public:
	[!output INPLACE_FRAME_CLASS]();

// ����
public:

// ����
public:

// �I�[�o�[���C�h
[!if DOCKING_TOOLBAR]
	public:
	virtual BOOL OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc);
[!endif]
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ����
public:
	virtual ~[!output INPLACE_FRAME_CLASS]();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
[!if DOCKING_TOOLBAR]
	CToolBar    m_wndToolBar;
[!if TOOLBAR_STYLE_REBAR]
	CDialogBar m_wndDlgBar;
	CReBar m_wndReBar;
[!endif]
[!endif]
	COleDropTarget	m_dropTarget;
	COleResizeBar   m_wndResizeBar;

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};

