// [!output DIALOG_AUTO_PROXY_HEADER]: 헤더 파일
//

#pragma once

class [!output DIALOG_CLASS];


// [!output DIALOG_AUTO_PROXY_CLASS] 명령 대상

class [!output DIALOG_AUTO_PROXY_CLASS] : public [!output DIALOG_AUTO_PROXY_BASE_CLASS]
{
	DECLARE_DYNCREATE([!output DIALOG_AUTO_PROXY_CLASS])

	[!output DIALOG_AUTO_PROXY_CLASS]();           // 동적 만들기에 사용되는 protected 생성자

// 특성
public:
	[!output DIALOG_CLASS]* m_pDialog;

// 작업
public:

// 재정의
	public:
	virtual void OnFinalRelease();

// 구현
protected:
	virtual ~[!output DIALOG_AUTO_PROXY_CLASS]();

	// 메시지 맵 함수를 생성했습니다.

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE([!output DIALOG_AUTO_PROXY_CLASS])

	// OLE 디스패치 맵 함수를 생성했습니다.

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

