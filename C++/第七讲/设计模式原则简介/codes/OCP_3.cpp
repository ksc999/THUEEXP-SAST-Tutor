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
 
	//抽象接口类，子类实现
	virtual double getompute()
	{
		return 0;
	}
public:
	double mA;
	double mB;
};
 
//除
class Division : public Calculator
{
public:
	virtual double getompute()
	{
		return mA / mB;
	}
};
//乘
class Multiplication : public Calculator
{
public:
	virtual double getompute()
	{
		return mA * mB;
	}
};
//减
class Subtraction : public Calculator
{
public:
	virtual double getompute()
	{
		return mA - mB;
	}
};
//加
class Addition : public Calculator
{
public:
	virtual double getompute()
	{
		return mA + mB;
	}
};
 
//工厂，根据不同的计算方式生产类
Calculator* CreateCalculator(char c)
{
	switch (c)
	{
	case '+':
		return new Addition;
		break;
	case '-':
		return new Subtraction;
		break;
	case '*':
		return new Multiplication;
		break;
	case '/':
		return new Division;
		break;
 
	default:
		return NULL;
		break;
	}
}
 
//客户端
int main(void)
{
	Calculator *calculator = NULL;
 
	calculator = CreateCalculator('-');
 
	calculator->mA = 10;
	calculator->mB = 5;
	std::cout << "计算结果：" << calculator->getompute() << std::endl;
 
	while (true) {};
	return 0;
}

