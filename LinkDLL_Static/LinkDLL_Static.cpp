#include<iostream>



extern "C" void* CreateRandomNums(int seed, int count);//����һ�����������
extern "C" void ReleaseArray(void* array);//�ͷ���������
extern "C" int At(void* array, int index);//��ȡ�����i������ֵ

#pragma comment(lib, "../Debug/MakeDLL_Static.lib")//���Ӿ�̬�⡣
//#pragma comment(lib, "../Debug/MakeDLL_Dynamic.lib")//���Ӷ�̬�⣬����Ҫ�ж�Ӧ��dll�ļ�
//�������ƶ�������cpp�ļ��С�
//������ظ�����Ҳ����Ӱ����롣


#include<stdio.h>
int main() {
	int count = 30;
	void* array = CreateRandomNums(100, count);
	for (auto i = 0; i < count; ++i)
		printf_s("%.2d:%d\n", i, At(array, i));
	ReleaseArray(array);

	return 0;
}



