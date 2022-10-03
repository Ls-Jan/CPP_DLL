

//#include "Func.h"//其实并不需要包含这头文件
#include"Data.h"
#include<vector>
using namespace std;

vector<Data>theList;

extern "C" _declspec (dllexport) void AddData(int num) {
	theList.push_back(Data(new int(num)));
}

extern "C" _declspec (dllexport) int GetData(int index) {
	if (0 <= index && index < theList.size())
		return theList[index].Get<int>();
	throw NULL;
}

extern "C" _declspec (dllexport) bool SetData(int index,int num) {
	if (0 <= index && index < theList.size()) {
		theList[index].Get<int>()=num;
		return true;
	}
	return false;
}

extern "C" _declspec (dllexport) bool DelData(int index) {
	if (0 <= index && index < theList.size()) {
		delete theList[index].data();
		theList.erase(theList.begin() + index);
		return true;
	}
	return false;
}
