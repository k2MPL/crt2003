// [!output DIALOG_HEADER] : 头文件
//

#pragma once

[!if AUTOMATION]
class [!output DIALOG_AUTO_PROXY_CLASS];

[!endif]

// [!output DIALOG_CLASS] 对话框
class [!output DIALOG_CLASS] : public [!output DIALOG_BASE_CLASS]
{
[!if AUTOMATION]
	DECLARE_DYNAMIC([!output DIALOG_CLASS]);
	friend class [!output DIALOG_AUTO_PROXY_CLASS];

[!endif]
// 构造
public:
	[!output DIALOG_CLASS](CWnd* pParent = NULL);	// 标准构造函数
[!if AUTOMATION]
	virtual ~[!output DIALOG_CLASS]();
[!endif]

// 对话框数据
[!if HTML_DIALOG]
	enum { IDD = IDD_[!output UPPER_CASE_SAFE_PROJECT_NAME]_DIALOG, IDH = IDR_HTML_[!output UPPER_CASE_SAFE_PROJECT_NAME]_DIALOG };
[!else]
	enum { IDD = IDD_[!output UPPER_CASE_SAFE_PROJECT_NAME]_DIALOG };
[!endif]

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

[!if HTML_DIALOG]
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);
[!if CONTEXT_HELP]
	HRESULT OnButtonHelp(IHTMLElement *pElement);
[!endif]
[!endif]

// 实现
protected:
[!if AUTOMATION]
	[!output DIALOG_AUTO_PROXY_CLASS]* m_pAutoProxy;
[!endif]
	HICON m_hIcon;
[!if AUTOMATION]

	BOOL CanExit();
[!endif]

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
[!if ABOUT_BOX]	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
[!endif]
[!if CONTEXT_HELP && HELPSTYLE_WINHELP]
	afx_msg void OnDestroy();
[!endif]
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
[!if AUTOMATION]
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
[!endif]
	DECLARE_MESSAGE_MAP()
[!if HTML_DIALOG]
	DECLARE_DHTML_EVENT_MAP()
[!endif]
};
