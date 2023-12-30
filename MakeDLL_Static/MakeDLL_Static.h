#pragma once




extern "C" _declspec (dllexport) void* CreateRandomNums(int seed, int count);//生成一份随机数数组
extern "C" _declspec (dllexport) void ReleaseArray(void* array);//释放数组数据
extern "C" _declspec (dllexport) int At(void* array, int index);//获取数组第i个数据值




