

import ctypes

class Point(ctypes.Structure):
	_fields_=[
		('x',ctypes.c_int),
		('y',ctypes.c_int),
	]
class Rect(ctypes.Structure):
	_fields_=[
		('point',Point),
		('w',ctypes.c_int),
		('h',ctypes.c_int),
	]

if __name__=='__main__':
	dll_x64='../x64/Debug/MakeDLL_StructData.dll'
	dll_x86='../Debug/MakeDLL_StructData.dll'

	dll=ctypes.CDLL(dll_x64)
	if(dll):
		Create_Rect_Stack=dll.Create_Rect_Stack
		Create_Rect_Stack.argtypes=(ctypes.c_int,ctypes.c_int,ctypes.c_int,ctypes.c_int)
		Create_Rect_Stack.restype=Rect

		Create_Rect_Heap=dll.Create_Rect_Heap
		Create_Rect_Heap.argtypes=(ctypes.c_int,ctypes.c_int,ctypes.c_int,ctypes.c_int)
		Create_Rect_Heap.restype=ctypes.POINTER(Rect)

		Get_Intersection_Stack=dll.Get_Intersection_Stack
		Get_Intersection_Stack.argtypes=(Rect,Rect)
		Get_Intersection_Stack.restype=Rect

		Get_Intersection_Heap=dll.Get_Intersection_Heap
		Get_Intersection_Heap.argtypes=(ctypes.POINTER(Rect),ctypes.POINTER(Rect))
		Get_Intersection_Heap.restype=ctypes.POINTER(Rect)

		Release_Rect_Heap=dll.Release_Rect_Heap
		Release_Rect_Heap.argtypes=(ctypes.POINTER(Rect),)
		Release_Rect_Heap.restype=None


		x1=10
		y1=10
		x2=30
		y2=40
		offset=10

		print(f'input:x1={x1}, y1={y1}, x2={x2}, y2={y2}, offset={offset}')
		if True:
		# if False:
			rect1= Create_Rect_Stack(ctypes.c_int(x1),ctypes.c_int(y1),ctypes.c_int(x2),ctypes.c_int(y2))
			# rect1= Create_Rect_Stack(x1,y1,x2,y2)
			rect2= Create_Rect_Stack(x1+offset, y1 + offset, x2 + offset, y2 + offset)
			rect3= Get_Intersection_Stack(rect1, rect2)
			print("[Stack]")
			print(f"Rect1: point=({rect1.point.x},{rect1.point.y}), w={rect1.w}, h={rect1.h}")
			print(f"Rect2: point=({rect2.point.x},{rect2.point.y}), w={rect2.w}, h={rect2.h}")
			print(f"Intersection: point=({rect3.point.x},{rect3.point.y}), w={rect3.w}, h={rect3.h}\n")
		if True:
		# if False:
			pRect1= Create_Rect_Heap(x1,y1,x2,y2)
			pRect2= Create_Rect_Heap(x1+offset, y1 + offset, x2 + offset, y2 + offset)
			pRect3= Get_Intersection_Heap(pRect1, pRect2)
			rect1=pRect1.contents
			rect2=pRect2.contents
			rect3=pRect3.contents
			rect=Rect(point=Point(x=3,y=4),w=5,h=6)
			print("[Heap]")
			print(f"Rect1: point=({rect1.point.x},{rect1.point.y}), w={rect1.w}, h={rect1.h}")
			print(f"Rect2: point=({rect2.point.x},{rect2.point.y}), w={rect2.w}, h={rect2.h}")
			print(f"Intersection: point=({rect3.point.x},{rect3.point.y}), w={rect3.w}, h={rect3.h}\n")
			Release_Rect_Heap(pRect1)
			Release_Rect_Heap(pRect2)
			Release_Rect_Heap(pRect3)

