#pragma once

struct Point {
	int x;
	int y;
};

struct Rect {
	Point point;
	int w;
	int h;
};


//后缀带_Stack的是栈变量相关函数
//后缀带_Heap的是堆变量相关函数
//为什么要弄这两类函数呢，因为想测试“直接返回结构体数据而不是结构体指针到底会不会弹白窗口(程序崩溃)”，结果意料之外的没事

//Create_Rect_XXX生成一个Rect数据
//Get_Intersection_XXX计算两个Rect的重合区域并返回新的Rect数据
//Release_Rect_Heap用于回收堆变量
//dll的数据指针需秉承“打哪来回哪去”的原则，从dll中生成的堆变量必须由dll释放
extern "C" _declspec (dllexport) Rect Create_Rect_Stack(int x1, int y1, int x2, int y2);
extern "C" _declspec (dllexport) Rect * Create_Rect_Heap(int x1, int y1, int x2, int y2);
extern "C" _declspec (dllexport) Rect Get_Intersection_Stack(Rect a, Rect b);
extern "C" _declspec (dllexport) Rect * Get_Intersection_Heap(Rect * a, Rect * b);
extern "C" _declspec (dllexport) void Release_Rect_Heap(Rect * rect);

Point Intersection(int a1, int a2, int b1, int b2);

