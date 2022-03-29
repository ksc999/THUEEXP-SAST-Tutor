#include <iostream>
void print() {                         // 全局命名空间
	using std::cout;                   // using declaration
	cout << "1\n";
}
namespace exap
{
	void print() {                      // exap命名空间
		std::cout << "2\n";
	}
	void printnum() {
		print();                        // 自动搜索本命名空间或外层命名空间中的print()函数
		::print();                      // 全局命名空间中的print()函数
	}
	namespace exbp {
		void print() {                  // exbp命名空间
			std::cout << "0\n";
		}
	}
}
int cout() {
	return 108;
}
namespace num {
	int a = 85;
}
int main() {
	exap::printnum();
	using namespace num;              // using directive，申明局部变量与namespace中的原有成员相同时新的声明会掩蔽namespace中的成员
	//using num::a;                   // using declaration，申明局部变量与namespace中的原有成员相同时会报错，因为发生了冲突
	int a = 12;
	//std::cout << num::a;            // 作用域运算符(::)，函数层面上和局部变量上都不会引起歧义
	using std::cout;                  // using declaration，函数层面上不会引起歧义
	cout << a << std::endl;
	cout << num::a << std::endl;
	/*using namespace std;            // using directive，函数层面上会引起歧义，报错
	cout << a; */
	return 0;
}