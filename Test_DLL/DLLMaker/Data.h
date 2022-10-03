#pragma once

class Data{//瞎写的一个类，虽然并没有意义，但写都写了，就这样算了
private:
	void* __data;
public:
	Data(void *data);
public:
	void* data();
	template<typename T>
	T& Get() {
		return *(T*)__data;
	}
};

