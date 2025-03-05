// [!output CONTAINER_ITEM_HEADER] : [!output CONTAINER_ITEM_CLASS] クラスのインターフェイス
//

#pragma once

class [!output DOC_CLASS];
class [!output VIEW_CLASS];

class [!output CONTAINER_ITEM_CLASS] : public [!output CONTAINER_ITEM_BASE_CLASS]
{
	DECLARE_SERIAL([!output CONTAINER_ITEM_CLASS])

// コンストラクタ
public:
[!if RICH_EDIT_VIEW]
	[!output CONTAINER_ITEM_CLASS](REOBJECT* preo = NULL, [!output DOC_CLASS]* pContainer = NULL);
[!else]
	[!output CONTAINER_ITEM_CLASS]([!output DOC_CLASS]* pContainer = NULL);
[!endif]
		// メモ: pContainer を NULL にすると IMPLEMENT_SERIALIZE を行うことができます。
		//  IMPLEMENT_SERIALIZE を行うためにはクラス内に引数のないコンストラクタが必要です。
		//  通常、OLE アイテムは NULL でないドキュメント ポインタで組み込まれています。
		//

// 属性
public:
	[!output DOC_CLASS]* GetDocument()
		{ return reinterpret_cast<[!output DOC_CLASS]*>([!output CONTAINER_ITEM_BASE_CLASS]::GetDocument()); }
	[!output VIEW_CLASS]* GetActiveView()
		{ return reinterpret_cast<[!output VIEW_CLASS]*>([!output CONTAINER_ITEM_BASE_CLASS]::GetActiveView()); }

	public:
[!if !RICH_EDIT_VIEW]
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
[!endif]
	protected:
[!if !RICH_EDIT_VIEW]
[!if !ACTIVE_DOC_CONTAINER]
	virtual void OnGetItemPosition(CRect& rPosition);
[!endif]
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
[!if CONTAINER_SERVER]
	virtual BOOL CanActivate();
[!endif]
[!endif]

// 実装
public:
	~[!output CONTAINER_ITEM_CLASS]();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
[!if !RICH_EDIT_VIEW]
	virtual void Serialize(CArchive& ar);
[!endif]
};

