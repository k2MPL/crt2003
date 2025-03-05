// [!output CHILD_FRAME_HEADER] : [!output CHILD_FRAME_CLASS] 클래스의 인터페이스
//


#pragma once

[!if PROJECT_STYLE_EXPLORER]
class [!output VIEW_CLASS];
[!endif]
[!if !DOCVIEW]
#include "[!output WND_VIEW_HEADER]"
[!endif]

class [!output CHILD_FRAME_CLASS] : public [!output CHILD_FRAME_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output CHILD_FRAME_CLASS])
public:
	[!output CHILD_FRAME_CLASS]();

// 특성
[!if APP_TYPE_MDI && SPLITTER || PROJECT_STYLE_EXPLORER]
protected:
	CSplitterWnd m_wndSplitter;
[!endif]
public:

// 작업
public:

// 재정의
[!if APP_TYPE_MDI && SPLITTER]
	public:
[!endif]
[!if PROJECT_STYLE_EXPLORER || !CHILD_FRAME_DEFAULT_STYLES || !DOCVIEW]
	public:
[!endif]
[!if APP_TYPE_MDI && SPLITTER]
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
[!else]
[!if PROJECT_STYLE_EXPLORER]
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
[!endif]
[!endif]
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
[!if !DOCVIEW]
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
[!endif]

// 구현
public:
[!if !DOCVIEW]
	// 프레임의 클라이언트 영역에 대한 뷰입니다.
	[!output WND_VIEW_CLASS] m_wndView;
[!endif]
	virtual ~[!output CHILD_FRAME_CLASS]();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

[!if PROJECT_STYLE_EXPLORER]
protected:
	[!output VIEW_CLASS]* GetRightPane();
[!endif]
// 메시지 맵 함수를 생성했습니다.
protected:
[!if !DOCVIEW]
	afx_msg void OnFileClose();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
[!endif]
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
	afx_msg void OnUpdateViewStyles(CCmdUI* pCmdUI);
	afx_msg void OnViewStyle(UINT nCommandID);
[!endif]
[!endif]
	DECLARE_MESSAGE_MAP()
};
