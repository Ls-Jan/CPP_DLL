#include "MakeDLL_StructData.h"
#include<utility>

Rect Create_Rect_Stack(int x1, int y1, int x2, int y2) {
	Rect rect;
	if (x1 > x2)
		std::swap(x1, x2);
	if (y1 > y2)
		std::swap(y1, y2);
	rect.point.x = x1;
	rect.point.y = y1;
	rect.w = x2 - x1 + 1;
	rect.h = y2 - y1 + 1;
	return rect;
}

Rect* Create_Rect_Heap(int x1, int y1, int x2, int y2) {
	Rect* rect = new Rect(Create_Rect_Stack(x1, y1, x2, y2));
	return rect;
}

void Release_Rect_Heap(Rect* rect) {
	delete rect;
}

Rect Get_Intersection_Stack(Rect a, Rect b) {
	Rect rect;
	Point rst1=Intersection(a.point.x,a.point.x+a.w,b.point.x,b.point.x+b.w);
	Point rst2=Intersection(a.point.y,a.point.y +a.h,b.point.y,b.point.y +b.h);
	rect.point.x = rst1.x;
	rect.point.y = rst2.x;
	rect.w = rst1.y-rst1.x;
	rect.h = rst2.y-rst2.x;
	return rect;
}

Rect* Get_Intersection_Heap(Rect* a, Rect* b) {
	Rect* rect = new Rect(Get_Intersection_Stack(*a, *b));
	return rect;
}

Point Intersection(int a1, int a2, int b1, int b2) {
	int temp = 0;
	Point rst;
	if (a1 > a2)
		std::swap(a1, a2);
	if (b1 > b2)
		std::swap(b1, b2);
	if (a1 < b1) {
		temp = std::max(b1, a2);
		temp = std::min(b2, temp);
		rst.x = b1;
		rst.y = temp;
	}
	else {
		temp = std::max(a1, b2);
		temp = std::min(a2, temp);
		rst.x = a1;
		rst.y = temp;
	}
	return rst;
}



