#pragma once


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

