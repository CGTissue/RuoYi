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

// �����Ǵ� ry_core.dll ������
class RY_CORE_API Cry_core {
public:
	Cry_core(void);
	// TODO:  �ڴ�������ķ�����
};

extern RY_CORE_API int nry_core;

RY_CORE_API int fnry_core(void);
