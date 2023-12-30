
#include <Windows.h>//库的动态链接
#include <tchar.h>//使用宏_T
#include<iostream>


int main() {
	HINSTANCE  hdll = LoadLibrary(_T("../Debug/MakeDLL_Dynamic.dll"));//链接动态库，后续使用之前需判空
	if (hdll) {
		auto CreateRandomNums = (void* (*)(int, int))GetProcAddress(hdll, "CreateRandomNums");//生成一份随机数数组
		auto ReleaseArray = (void(*)(void*))GetProcAddress(hdll, "ReleaseArray");//释放数组数据
		auto At = (int(*)(void*, int))GetProcAddress(hdll, "At");//获取数组第i个数据值

		int count = 30;
		void* array = CreateRandomNums(100, count);
		for (auto i = 0; i < count; ++i)
			printf_s("%.2d:%d\n", i, At(array, i));
		ReleaseArray(array);
	}
	if (hdll)//dll不使用时需要将其释放。如果应用程序加载后一直不释放的话建议还是静态链接dll比较省事
		FreeLibrary(hdll);
	return 0;
}

