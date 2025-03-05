// [!output SERVER_ITEM_IMPL] : [!output SERVER_ITEM_CLASS] ���ʵ��
//

#include "stdafx.h"
#include "[!output APP_HEADER]"

#include "[!output DOC_HEADER]"
#include "[!output SERVER_ITEM_HEADER]"
[!if CONTAINER_SERVER]
#include "[!output CONTAINER_ITEM_HEADER]"
[!endif]

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// [!output SERVER_ITEM_CLASS] ʵ��

IMPLEMENT_DYNAMIC([!output SERVER_ITEM_CLASS], [!output SERVER_ITEM_BASE_CLASS])

[!output SERVER_ITEM_CLASS]::[!output SERVER_ITEM_CLASS]([!output DOC_CLASS]* pContainerDoc)
	: [!output SERVER_ITEM_BASE_CLASS](pContainerDoc, TRUE)
{
	// TODO: �ڴ˴����һ���Թ������
	//(�罫���Ӽ������ʽ��ӵ��������Դ��)
}

[!output SERVER_ITEM_CLASS]::~[!output SERVER_ITEM_CLASS]()
{
	// TODO: �ڴ˴�����������
}

void [!output SERVER_ITEM_CLASS]::Serialize(CArchive& ar)
{
	// ���������Ƶ��������У�
	//  ���ܽ����� [!output SERVER_ITEM_CLASS]::Serialize�������
	//  ͨ�� OLE �ص� OnGetClipboardData ���Զ�ִ�С�����Ƕ���Ĭ�����Ϊ���ĵ��� Serialize 
	//  ������ί�С����֧�����ӣ������ֻ�����л�
	//  �ĵ���һ���֡�

	if (!IsLinkedItem())
	{
		[!output DOC_CLASS]* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (pDoc)
			pDoc->Serialize(ar);
	}
}

BOOL [!output SERVER_ITEM_CLASS]::OnGetExtent(DVASPECT dwDrawAspect, CSize& rSize)
{
	// �����������Ƶ�Ӧ�ó���ֻ�Ի����������
	//  ������д������ϣ��֧���������棬��
	//   DVASPECT_THUMBNAIL (ͨ����д OnDrawEx)����Ӧ�޸� OnGetExtent �Ĵ�ʵ��
	//  �Դ���
	//�������档

	if (dwDrawAspect != DVASPECT_CONTENT)
		return [!output SERVER_ITEM_BASE_CLASS]::OnGetExtent(dwDrawAspect, rSize);

	// ���� [!output SERVER_ITEM_CLASS]::OnGetExtent �Ա���������� HIMETRIC ��Ԫ�л�ȡ��Χ��
	//  �˴���Ĭ��ʵ��
	//  ֻ���ص�Ԫ��Ӳ�������֡�

	// TODO: �滻�������С

	rSize = CSize(3000, 3000);   // 3000 x 3000 HIMETRIC ��Ԫ

	return TRUE;
}

BOOL [!output SERVER_ITEM_CLASS]::OnDraw(CDC* pDC, CSize& rSize)
{
	if (!pDC)
		return FALSE;

	// ���ʹ�� rSize���򽫴��Ƴ�
	UNREFERENCED_PARAMETER(rSize);

	// TODO: ����ӳ��ģʽ�ͷ�Χ
	//  (�˷�Χͨ����� OnGetExtent ���صĴ�С��ͬ)
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowOrg(0,0);
	pDC->SetWindowExt(3000, 3000);

	// TODO: �ڴ˴���ӻ��ƴ��롣Ҳ������� HIMETRIC ��Χ��
	//  ���л��ƶ�����ͼԪ�ļ��豸������(pDC)�н��С�

[!if CONTAINER_SERVER]
	// TODO: ͬʱ����Ƕ�� [!output CONTAINER_ITEM_CLASS] ����

[!endif]
[!if CONTAINER_SERVER]
	// ���´��뽫������λ�û��Ƶ�һ���

	// TODO: ��������Ļ��ƴ���󣬽��Ƴ��˴���

	[!output DOC_CLASS]* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return FALSE;

	POSITION pos = pDoc->GetStartPosition();
	[!output CONTAINER_ITEM_CLASS]* pItem = DYNAMIC_DOWNCAST([!output CONTAINER_ITEM_CLASS], pDoc->GetNextClientItem(pos));
	if (pItem != NULL)
		pItem->Draw(pDC, CRect(10, 10, 1010, 1010));
[!endif]
	return TRUE;
}


// [!output SERVER_ITEM_CLASS] ���

#ifdef _DEBUG
void [!output SERVER_ITEM_CLASS]::AssertValid() const
{
	[!output SERVER_ITEM_BASE_CLASS]::AssertValid();
}

void [!output SERVER_ITEM_CLASS]::Dump(CDumpContext& dc) const
{
	[!output SERVER_ITEM_BASE_CLASS]::Dump(dc);
}
#endif

