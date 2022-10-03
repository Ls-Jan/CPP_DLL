#include "Data.h"

Data::Data(void *data){
	__data = data;
}

void* Data::data(){
	return __data;
}

