// [!output MAIN_FRAME_HEADER] : [!output MAIN_FRAME_CLASS] 類別的介面
//


#pragma once
[!if APP_TYPE_SDI || APP_TYPE_MTLD]
[!if PROJECT_STYLE_EXPLORER]

class [!output VIEW_CLASS];
[!else]
[!if !DOCVIEW]

#include "[!output WND_VIEW_HEADER]"
[!endif]
[!endif]
[!endif] 

[!if APP_TYPE_MDI]
class [!output MAIN_FRAME_CLASS] : public [!output MAIN_FRAME_BASE_CLASS]
{
	DECLARE_DYNAMIC([!output MAIN_FRAME_CLASS])
public:
	[!output MAIN_FRAME_CLASS]();
[!else]
class [!output MAIN_FRAME_CLASS] : public [!output MAIN_FRAME_BASE_CLASS]
{
	
[!if !DOCVIEW]
public:
	[!output MAIN_FRAME_CLASS]();
protected: 
	DECLARE_DYNAMIC([!output MAIN_FRAME_CLASS])
[!else]
protected: // 僅從序列化建立
	[!output MAIN_FRAME_CLASS]();
	DECLARE_DYNCREATE([!output MAIN_FRAME_CLASS])
[!endif]
[!endif]

// 屬性
[!if SPLITTER || PROJECT_STYLE_EXPLORER]
[!if APP_TYPE_SDI || APP_TYPE_MTLD]
protected:
	CSplitterWnd m_wndSplitter;
[!endif]
[!endif]
public:

// 作業
public:

// 覆寫
public:
[!if SPLITTER || PROJECT_STYLE_EXPLORER]
[!if APP_TYPE_SDI || APP_TYPE_MTLD]
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
[!endif] 
[!endif] 
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
[!if !DOCVIEW]
[!if APP_TYPE_SDI]
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
[!endif] 
[!endif]
[!if APP_TYPE_MTLD]
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
[!endif]

// 程式碼實作
public:
	virtual ~[!output MAIN_FRAME_CLASS]();
[!if PROJECT_STYLE_EXPLORER]
[!if APP_TYPE_SDI || APP_TYPE_MTLD]
	[!output VIEW_CLASS]* GetRightPane();
[!endif]
[!endif]
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
[!if DOCKING_TOOLBAR || STATUS_BAR]

protected:  // 控制列內嵌的成員
[!if STATUS_BAR]
	CStatusBar  m_wndStatusBar;
[!endif]
[!if DOCKING_TOOLBAR]
	CToolBar    m_wndToolBar;
[!endif]
[!if TOOLBAR_STYLE_REBAR]
	CReBar      m_wndReBar;
	CDialogBar      m_wndDlgBar;
[!endif]
[!endif]
[!if !DOCVIEW]
[!if APP_TYPE_SDI]
	[!output WND_VIEW_CLASS]    m_wndView;
[!endif] 
[!endif]

// 產生的訊息對應函式
protected:
[!if DOCKING_TOOLBAR || STATUS_BAR]
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
[!else]
[!if APP_TYPE_SDI && !DOCVIEW]
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
[!endif]
[!endif]
[!if !DOCVIEW]
[!if APP_TYPE_SDI]
	afx_msg void OnSetFocus(CWnd *pOldWnd);
[!endif] 
[!endif]
[!if APP_TYPE_MTLD]
	afx_msg void OnFileClose();
[!if !DOCVIEW]
	afx_msg void OnClose();
[!endif]
[!endif]
[!if PROJECT_STYLE_EXPLORER]
[!if APP_TYPE_SDI || APP_TYPE_MTLD]
[!if LIST_VIEW]
	afx_msg void OnUpdateViewStyles(CCmdUI* pCmdUI);
	afx_msg void OnViewStyle(UINT nCommandID);
[!endif]
[!endif]
[!endif]
	DECLARE_MESSAGE_MAP()
};


