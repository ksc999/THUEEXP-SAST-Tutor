#include <stdio.h>
#include <iostream>
 
//计算器类
class Calculator
{
public:
	Calculator()
	{
 
	}
	~Calculator() {};
 
	double getompute(char c)
	{
		switch (c)
		{
		case '+':
			return mA + mB;
			break;
		case '-':
			return mA - mB;
			break;
		default:
			break;
		}
	}
public:
	double mA;
	double mB;
};
 
//客户端
int main(void)
{
	Calculator calculator;
 
	while (true)
	{
		std::cout << "请输入数字：";
		std::cin >> calculator.mA;
		std::cout << "请输入数字：";
		std::cin >> calculator.mB;
		std::cout << "进行计算：";
		char c = '0';
		std::cin >> c;
		
		std::cout << "计算结果：" << calculator.getompute(c) << std::endl;
	}
 
	return 0;
}