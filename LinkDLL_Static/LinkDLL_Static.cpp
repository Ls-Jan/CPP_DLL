#include<iostream>



extern "C" void* CreateRandomNums(int seed, int count);//生成一份随机数数组
extern "C" void ReleaseArray(void* array);//释放数组数据
extern "C" int At(void* array, int index);//获取数组第i个数据值

#pragma comment(lib, "../Debug/MakeDLL_Static.lib")//链接静态库。
//#pragma comment(lib, "../Debug/MakeDLL_Dynamic.lib")//链接动态库，但需要有对应的dll文件
//该语句可移动到其他cpp文件中。
//该语句重复出现也不会影响编译。


#include<stdio.h>
int main() {
	int count = 30;
	void* array = CreateRandomNums(100, count);
	for (auto i = 0; i < count; ++i)
		printf_s("%.2d:%d\n", i, At(array, i));
	ReleaseArray(array);

	return 0;
}



