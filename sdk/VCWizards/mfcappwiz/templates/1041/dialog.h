// [!output DIALOG_HEADER] : ヘッダー ファイル
//

#pragma once

[!if AUTOMATION]
class [!output DIALOG_AUTO_PROXY_CLASS];

[!endif]

// [!output DIALOG_CLASS] ダイアログ
class [!output DIALOG_CLASS] : public [!output DIALOG_BASE_CLASS]
{
[!if AUTOMATION]
	DECLARE_DYNAMIC([!output DIALOG_CLASS]);
	friend class [!output DIALOG_AUTO_PROXY_CLASS];

[!endif]
// コンストラクション
public:
	[!output DIALOG_CLASS](CWnd* pParent = NULL);	// 標準コンストラクタ
[!if AUTOMATION]
	virtual ~[!output DIALOG_CLASS]();
[!endif]

// ダイアログ データ
[!if HTML_DIALOG]
	enum { IDD = IDD_[!output UPPER_CASE_SAFE_PROJECT_NAME]_DIALOG, IDH = IDR_HTML_[!output UPPER_CASE_SAFE_PROJECT_NAME]_DIALOG };
[!else]
	enum { IDD = IDD_[!output UPPER_CASE_SAFE_PROJECT_NAME]_DIALOG };
[!endif]

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

[!if HTML_DIALOG]
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);
[!if CONTEXT_HELP]
	HRESULT OnButtonHelp(IHTMLElement *pElement);
[!endif]
[!endif]

// 実装
protected:
[!if AUTOMATION]
	[!output DIALOG_AUTO_PROXY_CLASS]* m_pAutoProxy;
[!endif]
	HICON m_hIcon;
[!if AUTOMATION]

	BOOL CanExit();
[!endif]

	// 生成された、メッセージ割り当て関数
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
