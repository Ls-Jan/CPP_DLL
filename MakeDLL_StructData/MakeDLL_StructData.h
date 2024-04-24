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

extern "C" _declspec (dllexport) Rect Create_Rect_Stack(int x1, int y1, int x2, int y2);
extern "C" _declspec (dllexport) Rect * Create_Rect_Heap(int x1, int y1, int x2, int y2);
extern "C" _declspec (dllexport) Rect Get_Intersection_Stack(Rect a, Rect b);
extern "C" _declspec (dllexport) Rect * Get_Intersection_Heap(Rect * a, Rect * b);
extern "C" _declspec (dllexport) void Release_Rect_Heap(Rect * rect);

Point Intersection(int a1, int a2, int b1, int b2);

