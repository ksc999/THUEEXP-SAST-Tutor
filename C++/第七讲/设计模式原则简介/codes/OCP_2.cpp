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
		case '*':
			return mA * mB;
			break;
		case '/':
			return mA / mB;
			break;
		default:
			break;
		}
	}
public:
	double mA;
	double mB;
};