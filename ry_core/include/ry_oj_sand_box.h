#pragma once
#include "ry_stdlib.h"

class RYOjSandBox
{
private:
	bool bDebugProcRuning;	///< �����Ե��ӽ���׼������ʱ�ᷢ��һ�� EXCEPTION_BREAKPOINT �쳣��
							//	 �ñ������ڼ�¼�ӽ����Ƿ��Ѿ���ʼ������

protected:
	HANDLE hStdInput;		///< �ӽ��̵ı�׼����˿ڣ�ֻ��д
	HANDLE hStdOutput;		///< �ӽ��̵ı�׼����˿ڣ�ֻ�ɶ�
	HANDLE hStdError;		///< �ӽ��̵ı�׼���������ֻ�ɶ�

public:
	virtual void RunProcessInSandBox(LPCTSTR procName);

	virtual DWORD OnExceptionOccur(LPDEBUG_EVENT event);
	virtual DWORD OnCreateProcess(LPDEBUG_EVENT event);
	virtual DWORD OnCreateThread(LPDEBUG_EVENT event);
	virtual DWORD OnExitProcess(LPDEBUG_EVENT event);
	virtual DWORD OnExitThread(LPDEBUG_EVENT event);
	virtual DWORD OnUnloadDll(LPDEBUG_EVENT event);
	virtual DWORD OnLoadDll(LPDEBUG_EVENT event);
	virtual DWORD OnOutputDebugString(LPDEBUG_EVENT event);

protected:
	virtual DWORD ProcessDebugEvents(LPDEBUG_EVENT event);
};