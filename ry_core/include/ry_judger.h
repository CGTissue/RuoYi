//////////////////////////////////////////////////////////////////////////
// �˴�������Ǽ�����������ж�һ����ִ�г����Ƿ�����Ҫ��

#pragma once
#include "ry_stdlib.h"

typedef enum RYJudgeState
{
	RYJS_Accepted,					///< �𰸱�����
	RYJS_PresentationError,			///< ������ȷ�ģ����������ʽ������
	RYJS_TimeLimitExceeded,			///< ���г�ʱ
	RYJS_MemoryLimitExceeded,		///< �ڴ�ʹ�ó�������
	RYJS_WrongAnswer,				///< ����Ĵ��Ǵ����
	RYJS_RuntimeError,				///< ����ʱ�����˴���
	RYJS_OutputLimitExceeded,		///< ������ݳ����˹涨������
	RYJS_CompileError,				///< �����ʱ�������˴���
	RYJS_SystemError,				///< ϵͳ�ڲ������˴���
	RYJS_ValidatorError				///< �ύ�ĳ������쳣��Ϊ
} RYJudgeState;

class RYRunResult
{
protected:
	size_t memUsed;
	size_t timeUsed;
	RYReturnCode returnCode;
	RYJudgeState state;
};

interface RYJudger
{
public:
	virtual void SetTimeLimit(size_t timeLimit) = 0;
	virtual size_t GetTimeLimit() = 0;
	virtual void SetMemoryLimit(size_t memoInBytes) = 0;
	virtual size_t GetMemoryLimit() = 0;

	virtual RYRunResult Judge(LPCTSTR runableFileName, LPCTSTR inputFile, LPCTSTR outputFile);
};