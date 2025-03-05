// [!output DIALOG_AUTO_PROXY_HEADER]: ヘッダー ファイル
//

#pragma once

class [!output DIALOG_CLASS];


// [!output DIALOG_AUTO_PROXY_CLASS] コマンド ターゲット

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // 動的生成で使用される protected コンストラクタ

// 属性
public:
	[!output DIALOG_CLASS]* m_pDialog;

// 操作
public:

// オーバーライド
	public:
	virtual void OnFinalRelease();

// 実装
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// 生成された、メッセージ割り当て関数

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// 生成された OLE ディスパッチ割り当て関数

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

