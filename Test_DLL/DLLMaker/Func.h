#pragma once

//不知道整啥，整个“增删查改”好了。虽然底层使用的是vector(C++的STL之一)

extern "C" _declspec (dllexport) void AddData(int num);
extern "C" _declspec (dllexport) int GetData(int index);
extern "C" _declspec (dllexport) bool SetData(int index,int num);
extern "C" _declspec (dllexport) bool DelData(int index);



