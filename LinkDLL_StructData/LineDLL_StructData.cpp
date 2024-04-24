
#include <Windows.h>//��Ķ�̬����
#include <tchar.h>//ʹ�ú�_T
#include<iostream>



struct Point {
	int x;
	int y;
};

struct Rect {
	Point point;
	int w;
	int h;
};


int main() {
	HINSTANCE  hdll = LoadLibrary(_T("../Debug/MakeDLL_StructData.dll"));//���Ӷ�̬�⣬����ʹ��֮ǰ���п�
	if (hdll) {
		auto Create_Rect_Stack = (Rect(*)(int, int, int, int))GetProcAddress(hdll, "Create_Rect_Stack");//����һ�����������
		auto Create_Rect_Heap = (Rect * (*)(int, int, int, int))GetProcAddress(hdll, "Create_Rect_Heap");//�ͷ���������
		auto Get_Intersection_Stack = (Rect(*)(Rect, Rect))GetProcAddress(hdll, "Get_Intersection_Stack");//��ȡ�����i������ֵ
		auto Get_Intersection_Heap = (Rect * (*)(Rect*, Rect*))GetProcAddress(hdll, "Get_Intersection_Heap");//��ȡ�����i������ֵ
		auto Release_Rect_Heap = (void(*)(Rect*))GetProcAddress(hdll, "Release_Rect_Heap");//��ȡ�����i������ֵ

		int x1 = 10;
		int y1 = 10;
		int x2 = 30;
		int y2 = 40;
		int offset = 10;

		printf_s("input: x1=%d, y1=%d, x2=%d, y2=%d, offset=%d\n", x1, y1, x2, y2, offset);
		{
			auto rect1 = Create_Rect_Stack(x1, y1, x2, y2);
			auto rect2 = Create_Rect_Stack(x1+offset, y1 + offset, x2 + offset, y2 + offset);
			auto rect3 = Get_Intersection_Stack(rect1, rect2);
			printf_s("[Stack]\n");
			printf_s("Rect1: point=(%d,%d), w=%d, h=%d\n", rect1.point.x,rect1.point.y,rect1.w,rect1.h);
			printf_s("Rect2: point=(%d,%d), w=%d, h=%d\n", rect2.point.x, rect2.point.y, rect2.w, rect2.h);
			printf_s("Intersection: point=(%d,%d), w=%d, h=%d\n\n", rect3.point.x, rect3.point.y, rect3.w, rect3.h);
		}
		{
			auto pRect1 = Create_Rect_Heap(x1, y1, x2, y2);
			auto pRect2 = Create_Rect_Heap(x1 + offset, y1 + offset, x2 + offset, y2 + offset);
			auto pRect3 = Get_Intersection_Heap(pRect1, pRect2);
			auto& rect1 = *pRect1;
			auto& rect2 = *pRect2;
			auto& rect3 = *pRect3;
			printf_s("[Heap]\n");
			printf_s("Rect1: point=(%d,%d), w=%d, h=%d\n", rect1.point.x,rect1.point.y,rect1.w,rect1.h);
			printf_s("Rect2: point=(%d,%d), w=%d, h=%d\n", rect2.point.x, rect2.point.y, rect2.w, rect2.h);
			printf_s("Intersection: point=(%d,%d), w=%d, h=%d\n\n", rect3.point.x, rect3.point.y, rect3.w, rect3.h);
			Release_Rect_Heap(pRect1);
			Release_Rect_Heap(pRect2);
			Release_Rect_Heap(pRect3);
		}
	}
	if (hdll)//dll��ʹ��ʱ��Ҫ�����ͷš����Ӧ�ó�����غ�һֱ���ͷŵĻ����黹�Ǿ�̬����dll�Ƚ�ʡ��
		FreeLibrary(hdll);
	return 0;
}

