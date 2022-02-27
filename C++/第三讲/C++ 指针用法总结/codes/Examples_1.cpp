#include <iostream>
int main(){
	int x{ 7 };
	int y{ 3 };
	int* ptr{ &x };

	std::cout << &x << std::endl;
	std::cout << x << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;

	*ptr = 9;

	std::cout << &x << std::endl;
	std::cout << x << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;

	ptr = &y;

	std::cout << &y << std::endl;
	std::cout << y << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;

	std::cout << sizeof(ptr) << std::endl;
	std::cout << sizeof(*ptr) << std::endl;

	return 0;
}