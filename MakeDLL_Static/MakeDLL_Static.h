#pragma once




extern "C" _declspec (dllexport) void* CreateRandomNums(int seed, int count);//����һ�����������
extern "C" _declspec (dllexport) void ReleaseArray(void* array);//�ͷ���������
extern "C" _declspec (dllexport) int At(void* array, int index);//��ȡ�����i������ֵ




