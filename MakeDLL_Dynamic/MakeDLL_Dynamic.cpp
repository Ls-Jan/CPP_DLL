

//#include "MakeDLL_Dynamic.h"//其实并不需要包含这头文件
#include<vector>
#include<random>

extern "C" _declspec (dllexport) void* CreateRandomNums(int seed, int count) {
	srand(seed);
	std::vector<int>* array = new std::vector<int>();
	for (auto i = 0; i < count; ++i) {
		array->push_back(rand());
	}
	return array;
}

extern "C" _declspec (dllexport) void ReleaseArray(void* array) {
	delete (std::vector<int>*)array;
}

extern "C" _declspec (dllexport) int At(void* array, int index) {
	return ((std::vector<int>*)array)->at(index);
}


