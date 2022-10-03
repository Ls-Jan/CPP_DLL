
#include <Windows.h>//库的动态链接
#include <tchar.h>//使用宏_T
#include<iostream>


//动态调用库：https://blog.csdn.net/laochu250/article/details/96372240
int main() {
	HINSTANCE  hdll = LoadLibrary(_T("DLLMaker.dll"));//后续使用之前需判空，这里简写 加载动态库
	if (hdll) {
		auto Add =(void(*)(int))GetProcAddress(hdll, "AddData");
		auto Get= (int(*)(int))GetProcAddress(hdll, "GetData");
		auto Set= (bool(*)(int,int))GetProcAddress(hdll, "SetData");
		auto Del= (bool(*)(int))GetProcAddress(hdll, "DelData");
		for (int i = 0; i < 10; ++i)
			Add(i*i);
		Del(4);
		Set(5, 55555555);
		for (int i = 0; i < 9; ++i)
			std::cout<<Get(i)<<std::endl;
	}
	return 0;
}

