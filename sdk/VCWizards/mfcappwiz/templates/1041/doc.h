// [!output DOC_HEADER] : [!output DOC_CLASS] �N���X�̃C���^�[�t�F�C�X
//


#pragma once
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
#include "[!output ROWSET_HEADER]"
[!endif]

[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]

class [!output SERVER_ITEM_CLASS];
[!endif]

class [!output DOC_CLASS] : public [!output DOC_BASE_CLASS]
{
protected: // �V���A��������̂ݍ쐬���܂��B
	[!output DOC_CLASS]();
	DECLARE_DYNCREATE([!output DOC_CLASS])

// ����
public:
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
	[!output SERVER_ITEM_CLASS]* GetEmbeddedItem()
		{ return reinterpret_cast<[!output SERVER_ITEM_CLASS]*>([!output DOC_BASE_CLASS]::GetEmbeddedItem()); }
[!endif]
[!if OLEDB_RECORD_VIEW || ODBC_RECORD_VIEW]
	[!output ROWSET_CLASS] [!output ROWSET_CLASS_VARIABLE_NAME];
[!endif]

// ����
public:

// �I�[�o�[���C�h
[!if MINI_SERVER || FULL_SERVER || CONTAINER_SERVER]
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
[!endif]
	public:
	virtual BOOL OnNewDocument();
[!if !DB_VIEW_NO_FILE && !HTML_EDITVIEW]
	virtual void Serialize(CArchive& ar);
[!endif]
[!if RICH_EDIT_VIEW]
	virtual [!output CONTAINER_ITEM_BASE_CLASS]* CreateClientItem(REOBJECT* preo) const;
[!endif]

// ����
public:
	virtual ~[!output DOC_CLASS]();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
[!if ACTIVE_DOC_SERVER]
	virtual CDocObjectServer* GetDocObjectServer(LPOLEDOCUMENTSITE pDocSite);
[!endif]

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
[!if AUTOMATION]

	// �������ꂽ OLE �f�B�X�p�b�`���蓖�Ċ֐�

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
[!endif]
};


