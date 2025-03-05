// [!output INPLACE_FRAME_HEADER] : [!output INPLACE_FRAME_CLASS] 類別的介面
//

#pragma once

class [!output INPLACE_FRAME_CLASS] : public [!output INPLACE_FRAME_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output INPLACE_FRAME_CLASS])
public:
	[!output INPLACE_FRAME_CLASS]();

// 屬性
public:

// 作業
public:

// 覆寫
[!if DOCKING_TOOLBAR]
	public:
	virtual BOOL OnCreateControlBars(CFrameWnd* pWndFrame, CFrameWnd* pWndDoc);
[!endif]
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 程式碼實作
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

// 產生的訊息對應函式
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};

