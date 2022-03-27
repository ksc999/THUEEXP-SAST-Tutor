# 4.2  Namespace

## 4.2.1  命名冲突(Naming collisions) 与 命名空间简介

### 命名冲突与解决

正如前面提到过的，一个程序中可能包含多个编译单元，不同编译单元之间可能出现了相同的标识符。在编译时，这不会出现问题，而在链接时，如果链接器无法找到一个方式将两个重名的标识符区分开以引入程序，那么就会产生错误，也就是命名冲突。在大型软件开发过程中，这种事更是无法避免。为此C++提出了Namespace（命名空间）概念。

命名空间为在其中声明的名称提供了一个作用域区域（称为**命名空间作用域** ）——在命名空间内声明的任何名称都不会被误认为是其他作用域中的相同名称，在一个命名空间内，所有名称都必须是唯一的（否则会导致命名冲突）。 

### 全局命名空间 

在C++中，任何未在**类、函数或特定命名空间**中定义的名称都被视为隐式定义的命名空间的一部分，这被称为全局命名空间（也叫全局作用域）

只有声明和定义语句可以出现在全局命名空间中，其他类型的语句（例如表达式语句）不能放在全局命名空间中（全局变量的初始化例外）

```c++
# include...
// 全局命名空间
int a;              // 全局变量的声明，自动赋初值为0
int b = 8;        // 全局变量的初始化
int c;
c = 10;           // 表达式，编译不通过
....
```

### 标准命名空间（std）

为了避免命名冲突，考虑版本兼容性，C++ 将标准库中的所有功能都移到了名为“std”（标准的缩写）的命名空间中，我们一般使用的cout，准确说法应该是”标准命名空间中的cout

## 4.2.2 命名空间

### 命名空间的定义

命名空间的基本格式

```c++
namespace identifier
{
    entities;
}
```

举个例子

```cpp
namespace example
{
    int a = 5;
    double b = 3.1415926;
    void show() {} // do something ...
    class Point {}  // var and fun
}
```

### 嵌套命名空间

命名空间支持嵌套

请运行**namespace1.cpp**，观察运行结果

```c++
#include <iostream> 
// 在这里我们不使用using namespace std
namespace Student {
  int a = 108;
  int b = 100;
  namespace EE{
    double a = 15.05;
    double b = 84.95;
    void involution();
  }
  void EE::involution() {
    std::cout << "touching fish" << std::endl;
  }
  void involution(){
    std::cout << "involution" << std::endl;
  }
}
int main()
{
    std::cout << Student::b << ' ' << Student::EE::b << std::endl;
    //EE::involution();                                 // 编译不通过，嵌套后必须一层一层引用，除非前面的层已经声明
    using namespace Student;                  // 声明命名空间
    std::cout << EE::a << ' ' << a << std::endl;
    EE::involution();
    involution();
    return 0;
}
```

### 命名空间别名

如果出现了多层嵌套，或者命名空间的名字过长，可以使用别名

请运行**aliases.cpp**，观察运行结果

```c++
#include<iostream>
namespace Tsinghua {
    namespace EE {
        namespace Sophomore {
            double GPA = 4.0;
        }
    }
}
namespace not_me = Tsinghua::EE::Sophomore;
int main() {
    std::cout << not_me::GPA << std::endl;
    return 0;
}
```

### 匿名命名空间

从C++11开始，引入了匿名命名空间的概念，此后在C++的标准中，建议使用匿名命名空间间定义编译单元内部的全局变量，替代static

匿名命名空间的定义

```c++
namespace {
    int a;
    double b;
}
```

这等价于

```c++
namespace unknown {
    int a;
    double b;
}
using namespace unknown;
```

生成的命名空间名未知（程序员也不知道）

一般的命名空间具有外部链接属性，可是因为**不知道这个匿名命名空间生成的具体名字(unknown)**，所以其他编译单元无法访问该匿名命名空间中的标识符，这些标识符仅用于本编译单元，即它们都具有Internal Linkage

进一步，所有在匿名命名空间或匿名命名空间内的命名空间中声明的名字，即使显式声明为 extern，也拥有Internal Linkage

### 多文件中的命名空间

在多个位置（跨多个文件或同一文件中的多个位置）声明命名空间块是合法的，命名空间内的所有声明都被视为命名空间的整体。

同一命名空间可在多个文件中使用

请一起运行**add.h**、**subtract.h**（声明），**math.cpp**（函数具体实现）和**main.cpp**，观察运行结果

## 4.2.3 命名空间中标识符的调用

调用命名空间中的标识符，方法有三种：

### 使用作用域运算符(::)

只允许单次访问

如果使用了命名空间内的标识符并且没有提供范围解析，编译器将首先尝试在同一命名空间中找到匹配的声明。如果没有找到匹配的标识符，编译器将依次检查外层的命名空间（即包含该命名空间的命名空间）以查看是否找到匹配项，最后检查全局命名空间。 

### Using declaration（声明）

在后面使用中即可直接访问该成员

申明局部变量与namespace中的原有成员相同时会报错，因为发生了冲突

调用函数与namespace中的原有成员相同时不会报错，仍调用namespace中的函数

### Using directive（指令）

可以访问整个namespace

申明局部变量与namespace中的原有成员相同时不会报错，新的声明会掩蔽namespace中的成员

调用函数与namespace中的原有成员相同时会报错，无法区分

请运行**namespace2.cpp**，观察运行结果

```c++
#include <iostream>
void print() {                            // 全局命名空间
	using std::cout;                   // using declaration
	cout << "1\n";
}
namespace exap
{
	void print() {                       // exap命名空间
		std::cout << "2\n";
	}
	void printnum() {
		print();                           // 自动搜索本命名空间或外层命名空间中的print()函数
		::print();                         // 全局命名空间中的print()函数
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
	using namespace num;         // using directive，申明局部变量与namespace中的原有成员相同时新的声明会掩蔽namespace中的成员
	//using num::a;                      // using declaration，申明局部变量与namespace中的原有成员相同时会报错，因为发生了冲突
	int a = 12;
	//std::cout << num::a;            // 作用域运算符(::)，函数层面上和局部变量上都不会引起歧义
	using std::cout;                     // using declaration，函数层面上不会引起歧义
	cout << a << std::endl;
	cout << num::a << std::endl;
	/*using namespace std;        // using directive，函数层面上会引起歧义，报错
	cout << a; */
	return 0;
}
```

## 编者注

由于篇幅所限，编者只是将namespace相关知识中最浅显的部分进行了介绍，对于很多概念细节，仍需大家自行查阅相关资料加以了解

tutorial中的相关文件均在codes文件夹中，读者可自行运行查看结果，鼓励大家在此基础上再进行研究（包括修改代码运行来加深理解）

由于编者水平有限，本份教程难免有疏漏之处，还望读者批评指出

