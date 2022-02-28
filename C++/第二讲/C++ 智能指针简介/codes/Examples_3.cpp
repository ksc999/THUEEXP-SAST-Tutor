#include <iostream>
#include <memory> 
class Resource{
 public:
	Resource() { std::cout << "对象生成" << std::endl; }
	~Resource() { std::cout << "对象摧毁" << std::endl; }
};

int main(){
	auto ptr1{ std::make_shared<Resource>() };
	{
		auto ptr2{ ptr1 };
		std::cout << "销毁一个指针" << std::endl;
	}
	std::cout << "销毁另一个指针" << std::endl;
	return 0;
}