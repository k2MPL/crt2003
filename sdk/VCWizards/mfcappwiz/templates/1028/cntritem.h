// [!output CONTAINER_ITEM_HEADER] : [!output CONTAINER_ITEM_CLASS] 類別的介面
//

#pragma once

class [!output DOC_CLASS];
class [!output VIEW_CLASS];

class [!output CONTAINER_ITEM_CLASS] : public [!output CONTAINER_ITEM_BASE_CLASS]
{
	DECLARE_SERIAL([!output CONTAINER_ITEM_CLASS])

// 建構函式
public:
[!if RICH_EDIT_VIEW]
	[!output CONTAINER_ITEM_CLASS](REOBJECT* preo = NULL, [!output DOC_CLASS]* pContainer = NULL);
[!else]
	[!output CONTAINER_ITEM_CLASS]([!output DOC_CLASS]* pContainer = NULL);
[!endif]
		// 注意: 允許 pContainer 為 NULL 來啟用 IMPLEMENT_SERIALIZE
		// IMPLEMENT_SERIALIZE 要求有建構函式的類別，且使用零引數。
		// 一般而言，建構 OLE 項目都使用非 NULL 的文件指標。

// 屬性
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

// 程式碼實作
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

