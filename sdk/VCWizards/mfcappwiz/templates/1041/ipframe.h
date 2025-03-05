// [!output INPLACE_FRAME_HEADER] : [!output INPLACE_FRAME_CLASS] クラスのインターフェイス
//

#pragma once

class [!output INPLACE_FRAME_CLASS] : public [!output INPLACE_FRAME_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output INPLACE_FRAME_CLASS])
public:
	[!output INPLACE_FRAME_CLASS]();

// 属性
public:

// 操作
public:

// オーバーライド
[!if DOCKING_TOOLBAR]
	public:
	virtual BOOL OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc);
[!endif]
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 実装
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

// 生成された、メッセージ割り当て関数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};

