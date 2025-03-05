// [!output VIEW_HEADER] : [!output VIEW_CLASS] 类的接口
//


#pragma once

[!if CONTAINER || CONTAINER_SERVER]
class [!output CONTAINER_ITEM_CLASS];
[!endif]
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
class [!output ROWSET_CLASS];
[!endif]

class [!output VIEW_CLASS] : public [!output VIEW_BASE_CLASS]
{
protected: // 仅从序列化创建
	[!output VIEW_CLASS]();
	DECLARE_DYNCREATE([!output VIEW_CLASS])
[!if OLEDB_RECORD_VIEW || FORM_VIEW || ODBC_RECORD_VIEW]

public:
	enum{ IDD = IDD_[!output UPPER_CASE_SAFE_PROJECT_NAME]_FORM };
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	[!output ROWSET_CLASS]* m_pSet;
[!endif]
[!endif]

// 属性
public:
	[!output DOC_CLASS]* GetDocument() const;
[!if CONTAINER || CONTAINER_SERVER]
[!if !RICH_EDIT_VIEW]
	// m_pSelection 将该选定内容保存在当前的 [!output CONTAINER_ITEM_CLASS] 中。
	// 对于许多应用程序，这种成员变量不足以
	//  表示某个选择，例如在不属于 [!output CONTAINER_ITEM_CLASS] 的对象中
	//  选定的一个或多个对象。提供这种选择
	// 机制的目的只是帮助您入门

	// TODO: 用适合于您的应用程序的选择机制替换此选择机制
	[!output CONTAINER_ITEM_CLASS]* m_pSelection;
[!endif]
[!endif]

// 操作
public:

// 重写
	public:
[!if OLEDB_RECORD_VIEW]
	virtual CRowset<>* OnGetRowset();
[!endif]
[!if ODBC_RECORD_VIEW]
	virtual CRecordset* OnGetRecordset();
[!endif]
[!if !TREE_VIEW && !LIST_VIEW && !HTML_VIEW && !HTML_EDITVIEW && !RICH_EDIT_VIEW && !EDIT_VIEW && !FORM_VIEW && !OLEDB_RECORD_VIEW && !ODBC_RECORD_VIEW]
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
[!endif] 
[!if PRINTING]
[!if TREE_VIEW || LIST_VIEW]
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
[!endif]
[!endif]
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
[!if FORM_VIEW || OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
[!endif] 
[!if SCROLL_VIEW || CONTAINER || CONTAINER_SERVER || OLEDB_RECORD_VIEW || TREE_VIEW || LIST_VIEW || FORM_VIEW || HTML_VIEW || ODBC_RECORD_VIEW]
	virtual void OnInitialUpdate(); // 构造后第一次调用
[!endif]
[!if PRINTING]
[!if !HTML_VIEW && !HTML_EDITVIEW]
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
[!endif]
[!if !RICH_EDIT_VIEW && !HTML_VIEW && !HTML_EDITVIEW]
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
[!endif]
[!if FORM_VIEW || ACTIVE_DOC_CONTAINER]
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
[!endif]
[!endif]
[!if CONTAINER || CONTAINER_SERVER]
[!if !RICH_EDIT_VIEW]
	virtual BOOL IsSelected(const CObject* pDocItem) const;// 容器支持
[!endif]
[!endif]

// 实现
public:
	virtual ~[!output VIEW_CLASS]();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
[!if CONTAINER || CONTAINER_SERVER]
	afx_msg void OnDestroy();
[!if !RICH_EDIT_VIEW]
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnFilePrint();
[!endif]
[!endif]
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
	afx_msg void OnCancelEditSrvr();
[!endif]
[!if PROJECT_STYLE_EXPLORER]
[!if LIST_VIEW]
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
[!endif]
[!endif]
[!if ACTIVE_DOC_CONTAINER]
	afx_msg void OnFilePrintPreview();
	afx_msg void OnFilePrintPreviewUIUpdate(CCmdUI* pCmdUI);
[!endif]
[!if HTML_EDITVIEW]
	DECLARE_DHTMLEDITING_CMDMAP([!output VIEW_CLASS])
[!endif]
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // [!output VIEW_IMPL] 的调试版本
inline [!output DOC_CLASS]* [!output VIEW_CLASS]::GetDocument() const
   { return reinterpret_cast<[!output DOC_CLASS]*>(m_pDocument); }
#endif

