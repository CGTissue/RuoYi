//////////////////////////////////////////////////////////////////////////
// �˴�������Ǳ��������֣���������Դ�������ɿ�ִ�г���

#pragma once
#include "ry_stdlib.h"

typedef enum RYCompilerState
{
	RYCS_Success,			///< ����ɹ�
	RYCS_CompileError,		///< �����ʱ�������������
	RYCS_Uninitialized,		///< ����������û����ȷ��ʼ��
	RYCS_BadFileName,		///< �����ļ��Ҳ�����û��д������ļ���Ȩ��
	RYCS_ParamsError,		///< �趨�ı��������֧��
	RYCS_SystemError		///< δ֪ϵͳ����
} RYCompileState;

typedef enum RYCompilerParams
{
	RYCP_EnableDebug,			///< ���õ�����Ϣ
	RYCP_Optimization,			///< �Դ�������Ż�
	RYCP_Lib,					///< ָ������Ŀ��ļ�
	RYCP_Include,				///< ָ����Ҫ������ͷ�ļ�
	RYCP_EnableWarnings,		///< ָ���Ƿ����������Ϣ
	RYCP_Macro,					///< ָ��Ԥ�����
	RYCP_TreatWarningAsError	///< ָ���Ƿ񽫾�����Ϊ����
};

class RYCompileError
{
protected:
	RYCompileErrorNumber errNum;		///< �����
	RYString errMsg;					///< ������������
	size_t lineNum;						///< ���������к�
	size_t colNum;						///< ���������к�
	RYString fileName;					///< ���������ļ�����

public:
	RYCompileErrorNumber GetErrNum();
	LPCTSTR GetErrMsg();
	size_t GetLineNum();
	size_t GetColNum();
	LPCTSTR GetErrFileName();
};

interface RYCompiler
{
protected:

public:
	virtual bool Compile(LPCTSTR srcFile, LPCTSTR dstFile) = 0;
	virtual RYCompilerState GetLastError() = 0;
	virtual const RYCompileError* GetLastCompileError() = 0;
	virtual bool SetCompileParam(RYCompilerParams param, void* data) = 0;
	virtual void* GetCompileParam(RYCompilerParams param) = 0;

	virtual bool Initialize(LPCTSTR initFile = NULL);
	virtual void CoInitialize();
};
