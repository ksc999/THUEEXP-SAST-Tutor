# 第二讲：设计模式简介

## 设计模式为什么是必要的？

在面向对象的程序设计中，一段好的程序必须具有以下三个特点：可读性、高效性和可扩展性。其中，我们在前面所介绍关于代码风格的教程中，解决的就是有关可读性的相关问题；而在这一讲中，我们所介绍的设计模式则可以帮助提高程序的可扩展性。这在编写大型程序或多人协作编程中是至关重要的，有助于提高代码编写的效率。



## OOP编程中的三大基本原则

### 原则一：针对接口编程，而非针对实现编程

要想弄明白这一原则的内容，我们首先要明白什么是接口类和实现类。

接口这一概念是由Java继承而来，可以与C++中的抽象类类比。而接口类则是指一个抽象类仅通过纯虚函数向外提供接口的类，通过重载这些虚函数，我们就可以得到实现具体功能的实现类。这一原则中，强调的就是在OOP编程中，我们应当尽量使用接口类而非实现类，这样可以保证未来程序的可扩展性。

两种编程方式的区别可以用以下的示例程序清楚地展现：

```C++
// 针对实现编程
Dog d = new Dog();
d.bark();

//针对接口编程
Animal animal = new Dog();
animal.makesound();
```

我们想实现创建狗的对象并实现狗吠的功能。当采用针对实现的编程原则时，我们必须新建一个具体的Dog类，然后调用bark方法；然而，如果采用针对接口的编程原则，我们就可以利用Dog类的构造函数生成一个Animal对象。由于多态性的保证，当Animal对象调用makesound方法时会自动调用Dog类的方法，从而实现了对bark()函数的调用。

两种方法殊途同归，然而其效用却并不相同。采用前者，虽然代码含义清晰明确，但对于每类动物，即使他们相互之间有很多共同的元素，也必须在他们相应的类中分别加以实现，完全不能代码复用，更重要的是不能反应出这些Animal的共同特征。而采用后者，我们就可以更好地实现代码的重用，并且有助于隔离变化，程序的扩展性和灵活性都要略胜一筹；



### 原则二：开闭原则

这一原则理解起来就较为简单了。所谓开闭原则，指的是代码编写过程中，应当对扩展开放，对修改封闭。这样一来，当需求改变时，我们可以进行代码复用，而不用对原始代码进行改动。

使用这一编程原则可以至少在两个层面上提升代码质量。首先，通过扩展已有代码，可以提供新的行为和功能，以满足对软件的新需求，使得变化中的程序有一定的适应性和灵活性。此外，开闭原则保证了已有的软件模块，特别是最重要的抽象模块不再修改；这就使变化中的软件系统有一定的稳定性和延续性。

为了更好地理解这一原则，我们可以用下面的程序作为例子（可参见OCP.cpp源代码）。假设我们想在Calculator类中完成加减法的运算，我们可能会这么写：

```c++
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
```

然而，现在客户提出了新的需求，计算器需要完成乘除法等新的运算，那么一个尚未经过专业OOP培训的程序员可能会对getompute() 函数进行如下的改动：

```cpp
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
```

这样一来，虽然功能得到了满足，但是由于修改了类的核心代码，违背了开放封闭原则：代码没有对修改封闭。这样一来，当后期要求的功能越来越多时，程序员都需要对类的getompute() 函数进行直接修改，这极大地增加了代码出错的概率。一个符合开放封闭原则的写法则是在Calculator类中定义抽象接口类，并通过子类继承的方式增加新的功能。

```C p
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
```

在这种编程规范下，功能的修改既不需要修改Calculator类的任何代码，实现新功能时又仅需要进行新的类的独立编写并继承在Calculator类下，这将极大方便了程序应对需求变化的情形，也将为多人合作下的代码编写提供了更多的方便。



### 原则三：单一职责原则

为了更好地理解什么是单一职责原则，我们首先来考虑下面这个例子：假设在工厂中，一款产品从无到有需要经过10台机器。作为工厂的管理者，我们是雇佣10名员工，让每个人拿着原材料从第一台操作到第十台比较快；还是让每个机器有一个单独的人专门负责会比较快？我想，答案是显而易见的。

工厂通过流水线式的分工，让每个人仅负责一道工序，效率有了大幅度的提高。当我们类比面向对象设计时，这种原则则被叫做单一职责原则。顾名思义，所谓单一职责原则就是一个类应该只有一个引起其变化的原因。这是一个最简单，最容易理解，但是却最不容易做到的一个设计原则。说的简单一点，就是怎样设计类以及类的方法界定的问题。

例如，我们考虑一个公司的人事管理系统。如果我们将工程师、销售人员、销售经理等等都放在职员类里考虑，其结果将会非常混乱。在这个假设下，职员类里的每个方法（例如：发工资、招投标等）都需要用if else 判断是哪种职员类型，不论从类结构或是代码实现层面上来说都会十分臃肿。更严重的是，任何职员类型，不论哪一种发生需求变化，都会改变职员类，这是我们不愿意看到的。

此外，我们还可以通过一个具体的代码示例来理解。假设我们要完成俄罗斯方块游戏的编写，里面会涉及到各种各样方块的位置和形状。如果我们不采用单一职责原则而将所有的功能都集成在一个类中，那么这个类就会因为耦合度太高而造成可维护性降低。相反，如果我们对不同类型的方块分开编写，降低了类与类之间的耦合性，那么在编程层面就可以提升效率，具体情形可以参考如下代码：

```cpp
//方块形状类
class Shape
{
public:
	Shape();
	~Shape();
 
	virtual void setShape();
private:
};
 
//"一"形
class Shape1 : public  Shape
{
public:
	Shape1();
	~Shape1();
 
	virtual void setShape();
private:
};
 
//"十"形
class Shape2 : public  Shape
{
public:
	Shape2();
	~Shape2();
 
	virtual void setShape();
private:
};
 
//"L"形
class Shape3 : public  Shape
{
public:
	Shape3();
	~Shape3();
 
	virtual void setShape();
private:
};
 
//"其他"形
class Shape4: public  Shape
{
public:
	Shape4();
	~Shape4();
 
	virtual void setShape();
private:
};
 
//方块位置类
class Place
{
public:
	Place();
	~Place();
 
	void setPlace();		
private:
};
 
//游戏界面类
class GameUI
{
public:
	GameUI();
	~GameUI();
 
	void showViewCcon();		//游戏方块显示
private:
	Shape *mShape;				//形状
	Place *mPlace;				//位置
	int mStartButton;			//开始按钮
	int mEndButton;				//结束按钮
};


```

因此，我们可以总结出，所谓的“单一职责原则”有两层含义：单一职责有两个含义：**一个是避免相同的职责分散到不同的类中，另一个是避免一个类承担太多的职责。**遵循这样的规则进行类和类的方法界定，将会使得类的结构更为清晰，便于在需求改变时对类进行合理的修改和扩展。可以说，单一职责原则既减少了类与类之间的耦合，又提高了类的可复用性，极大的提升了面向对象编程的效率。



## 扩展知识

### 里氏替换原则

里氏替换原则也是OOP的基本原则之一，所强调的是在任何基类可以出现的地方，派生类一定可以出现。因此我们可以说，它是继承复用的基石，只有当派生类可以替换掉基类，软件的功能不受到影响时，基类才能真正被复用，而派生类也能够在基类的基础上增加新的行为。在这一意义上，我们可以说里氏替换原则是对“开闭”原则的补充。而要想规范地遵从里氏替换原则，我们需要做到以下五点：

1. 子类必须完全实现父类的抽象方法，但不能覆盖父类的非抽象方法

2. 子类可以实现自己特有的方法

3. 当子类覆盖或实现父类的方法时，方法的前置条件（即方法的形参）要比父类方法的输入参数更宽松。

4. 当子类的方法实现父类的抽象方法时，方法的后置条件（即方法的返回值）要比父类更严格。

5. 子类的实例可以替代任何父类的实例，但反之不成立

我们可以用下面的代码示例进行说明：

```cpp
#include <iostream>
//鸟
class Bird{
public:
    Bird(){}
    virtual ~Bird(){}
    virtual void Fly() {
        std::cout << "I am  a bird and I am flying" << std::endl;
    }
};
//燕子
class Swallow : public Bird{
public:
    Swallow(){}
    ~Swallow(){}
    void Fly() override {
        std::cout << "I am  a Swallow and I am flying" << std::endl;
    }
};
//大雁
class WildGoose : public Bird{
public:
    WildGoose(){}
    ~WildGoose(){}
    void Fly() override {
        std::cout << "I am  a Wild Goose and I am flying" << std::endl;
    }
};
//模拟鸟的飞行
void Fly(Bird& b){
    b.Fly();
}

int main(int argc,char * argv[]){
    WildGoose goose;
    Swallow s;
    Fly(s);
    Fly(goose);
}
```

在这一段示例代码中，我们看到：定义的全局函数的参数为Bird类的对象，这使得不论我们传入的是燕子还是大雁，程序都能顺利进行。然而，如果将Fly函数改为下面的定义：

```cpp
void Fly(WildGoose& wg){
    wg.Fly();
}
```

那么我们就无法用Fly函数模拟燕子的飞行。根据里氏替换原则，在基类出现的地方都可以用派生类代替，而反之则不行。



### 迪米特法则

与之前介绍的各种原则不同，迪米特法则关注的是的是类之间的耦合性大小。事实上，这一法则并非是程序设计领域中的专属，美国人就在航天系统的设计中同样采用了这一法则。

迪米特法则又叫作最少知识原则，一个类对于其他类知道的越少越好，就是说一个对象应当对其他对象有尽可能少的了解：只和朋友通信，不和陌生人说话。在编程层面，其具有以下几个特点：

1. **如果两个类不直接通信，那么这两个类就不应该发生直接的相互作用**。

2. 在类的结构设计上，每一个类都应该尽量降低成员的访问权限

3. 该法则在适配器模式、解释模式等中有强烈的体现

4. 强调类之间的松耦合，类之间的耦合越弱，越有利于复用


