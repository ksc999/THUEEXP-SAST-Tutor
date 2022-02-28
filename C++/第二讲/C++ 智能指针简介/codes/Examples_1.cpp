#include <iostream>
template <class T>
class SmartPtr {
	T* ptr; 
 public:
	explicit SmartPtr(T* p = NULL) { ptr = p; }
	~SmartPtr() { delete (ptr); }
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }
};

int main(){
	SmartPtr<int> ptr(new int());
	*ptr = 1;
	std::cout << *ptr;
	return 0;
}
