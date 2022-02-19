#include<iostream>
using namespace std;

enum note { middleC, Csharp, Eflat }; //这个枚举类型并不必要
class Instrument
{
public:
	void play(note)const
	{
		cout << "Instrument::play" << endl;
	}
};

class Wind :public Instrument
{
public:
	void play(note)const
	{
		cout << "Wind::play" << endl;
	}
};

void tune(Instrument& i)
{
	i.play(middleC);
}

int main()
{
	Wind flute;
	tune(flute);
}

//运行结果为：Instrument::play。