
#include <Windows.h>//��Ķ�̬����
#include <tchar.h>//ʹ�ú�_T
#include<iostream>


int main() {
	HINSTANCE  hdll = LoadLibrary(_T("../Debug/MakeDLL_Dynamic.dll"));//���Ӷ�̬�⣬����ʹ��֮ǰ���п�
	if (hdll) {
		auto CreateRandomNums = (void* (*)(int, int))GetProcAddress(hdll, "CreateRandomNums");//����һ�����������
		auto ReleaseArray = (void(*)(void*))GetProcAddress(hdll, "ReleaseArray");//�ͷ���������
		auto At = (int(*)(void*, int))GetProcAddress(hdll, "At");//��ȡ�����i������ֵ

		int count = 30;
		void* array = CreateRandomNums(100, count);
		for (auto i = 0; i < count; ++i)
			printf_s("%.2d:%d\n", i, At(array, i));
		ReleaseArray(array);
	}
	if (hdll)//dll��ʹ��ʱ��Ҫ�����ͷš����Ӧ�ó�����غ�һֱ���ͷŵĻ����黹�Ǿ�̬����dll�Ƚ�ʡ��
		FreeLibrary(hdll);
	return 0;
}

