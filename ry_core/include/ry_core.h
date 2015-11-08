// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� RY_CORE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// RY_CORE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef RY_CORE_EXPORTS
#define RY_CORE_API __declspec(dllexport)
#else
#define RY_CORE_API __declspec(dllimport)
#endif

typedef enum
{
	RCS_SUCCESS,
	RCS_SRC_ERROR,
	RCS_COMPILER_ERROR
} RYCompileState;

typedef struct
{

} RYCompileParams;

typedef enum
{
	RCFP_FORBBID_ASM = 0x1,
	RCFP_ALL = 0xff
} RYCompileFilterParams;

RYCompileState RYCompileCppToExe(__in RYString srcFile, __in RYString dstFile, __in const RYCompileParams* params = NULL);

bool RYCheckSrcFile(__in RYString srcFile, __in RYCompileFilterParams filter = RCFP_ALL);