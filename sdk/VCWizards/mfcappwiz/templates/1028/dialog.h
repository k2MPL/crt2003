// [!output DIALOG_HEADER] : ���Y�� 
//

#pragma once

[!if AUTOMATION]
class [!output DIALOG_AUTO_PROXY_CLASS];

[!endif]

// [!output DIALOG_CLASS] ��ܤ��
class [!output DIALOG_CLASS] : public [!output DIALOG_BASE_CLASS]
{
[!if AUTOMATION]
	DECLARE_DYNAMIC([!output DIALOG_CLASS]);
	friend class [!output DIALOG_AUTO_PROXY_CLASS];

[!endif]
// �غc
public:
	[!output DIALOG_CLASS](CWnd* pParent = NULL);	// �зǫغc�禡
[!if AUTOMATION]
	virtual ~[!output DIALOG_CLASS]();
[!endif]

// ��ܤ�����
[!if HTML_DIALOG]
	enum { IDD = IDD_[!output UPPER_CASE_SAFE_PROJECT_NAME]_DIALOG, IDH = IDR_HTML_[!output UPPER_CASE_SAFE_PROJECT_NAME]_DIALOG };
[!else]
	enum { IDD = IDD_[!output UPPER_CASE_SAFE_PROJECT_NAME]_DIALOG };
[!endif]

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩

[!if HTML_DIALOG]
	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);
[!if CONTEXT_HELP]
	HRESULT OnButtonHelp(IHTMLElement *pElement);
[!endif]
[!endif]

// �{���X��@
protected:
[!if AUTOMATION]
	[!output DIALOG_AUTO_PROXY_CLASS]* m_pAutoProxy;
[!endif]
	HICON m_hIcon;
[!if AUTOMATION]

	BOOL CanExit();
[!endif]

	// ���ͪ��T�������禡
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
