# 4.1   Static修饰符

## 4.1.1  基本概念

### Storage Duration（存储持续时间，存储期）

标识符（通俗地讲，就是给变量、函数、类等取的“名字”）的存储持续时间是程序运行时标识符占有内存的方式（在时间层面上）

存储持续时间：

- Automatic Duration ——标识符仅在其所在函数（块）执行时被分配内存，执行结束后便销毁其内存
- Static Duration —— 标识符在程序运行中始终占有内存，即被调用结束后所占内存不会销毁
- Dynamic Duration —— 标识符由程序员请求创建（new、malloc、realloc）和销毁（delete）
- Thread Duration(C++11开始) —— 标识符在线程开始时分配内存，并在线程结束时销毁内存，每个线程拥有它自身的对象实例。

### Scope & Visibility（作用域与可见度）

一个标识符的可见度决定了它在程序的哪些部分可以被引用。进一步定义，一个标识符的作用域就是这段程序中哪些部分可以使用这个标识符。

- Namespace Scope —— 见命名空间
- Class Scope —— 类中声明的名字的作用域开始于其声明点，并包含类的剩余部分和所有函数体（无论其是否定义于类定义外或在该名字的声明之前）
- File Scope —— 具有该作用域的标识符必须声明在代码块和参数列表之外。在编译单元（简单的说，就是一个.c或.cpp文件（源文件）经过预处理器预处理后的内容）中，该标识符可被在其声明或定义点之后的任何位置访问，这样的标识符通常被称为全局的(global)或外部的(external)，作用域为其声明位置到编译文件的末尾
- Function Parameter Scope  —— 具有该作用域的标识符出现在函数的形参列表中。这样的标识符通常被称为局部的(local)，作用域为其声明点到函数的末尾（函数声明末尾或函数体末尾）
- Block Scope —— 具有该作用域的标识符出现在块（复合语句）内的声明。这样的标识符通常被称为局部的(local)，作用域为其声明或定义点到**包含其声明或定义的块**（也包括嵌套在该块中的任何块）的末尾

### Linkage（链接）

在一个大型程序中可能包含着多个编译单元，每个编译单元可能使用了相同的标识符，链接决定了该标识符的所有声明是否针对同一对象

No Linkage —— 标识符只能在它所在的作用域使用，在Block Scope声明的下列标识符无链接：

- 未显式声明为extern的变量（不管有没有static修饰符）
- 局部类和它的成员函数（在函数内的类）
- 在块作用域声明的其他标识符，例如 typedef、枚举类型

未指定为拥有外部、模块 (C++20)或内部链接的名字同样无链接，**这与它的声明所处的作用域无关**



Internal Linkage —— 仅本编译单元可见，其他编译单元不可访问。标识符可在本编译单元中的所有作用域使用，拥有（命名空间作用域）内部链接的实体有：

- 声明为 static 的变量、函数或函数模板、变量模板（C++14）
- 未声明为 extern 且先前未声明为具有外部链接的非 volatile、非模板 (C++14)、非 inline (C++17)的const限定变量（包含 constexpr）
- 匿名联合体(anonymous union)的成员

两个具有相同名字的标识符若至少一个是内部链接，则两者视为相互独立（不会引起命名冲突）



External Linkage —— 其他编译单元可以访问，标识符可在其他编译单元中的作用域使用，拥有（命名空间作用域）外部链接的实体（有**特例**，详见匿名命名空间）有：

- 以上未列出的变量与函数（未声明为 static 的函数，命名空间作用域内未声明为 static 的非 const 变量，和所有声明为 extern 的变量）
- 枚举类型
- 类以及其成员函数、静态数据成员（不论是否 const）、嵌套类及枚举类型，类内作第一次引入(first introduced)的友元函数的名字
- 所有未列于上的模板名（未声明为 static 的函数模板）

在Block Scope作第一次声明(first declared)的下列标识符拥有外部链接

- 声明为 extern 的变量名
- 函数名

需要注意的是，拥有外部链接的标识符如果被声明在头文件并且被多个编译单元包含，可能会出现链接冲突错误（每个包含这个标识符的编译单元都会分配空间，当编译单元链接的时候，连接器就会面对多个相同的名字，无法正常链接到正确的对象而报错）

### 数据的存储类型，存储类说明符

所有的数据都有两种类型，一是常见的数据类型，如int、float等；二是数据的存储类型，下面六个说明符用于表示数据的存储类型。

Auto 或（C++11前）无标识符 —— Automatic Duration

Static —— Static Duration or Thread Duration，Internal Linkage

Extern —— Static Duration or Thread Duration，External Linkage

Register —— Automatic Duration，提示编译器将此对象置于处理器的寄存器，在C++17后弃用

Mutable —— 不影响存储期或链接。在**类的常成员函数**内部，添加mutable说明符的变量可以被修改（详见第五讲 const）

Thread_local —— Thread Duration

**声明中只能出现一个存储类说明符**，但 thread_local 可以与 static 或 extern 结合（此时仍为Thread Duration，改变Linkage）

## 4.1.2  类外作用

### 改变局部变量的存储持续时间

在函数中，对某变量添加static修饰符，改变了该变量的存储持续时间（从Automatic Duration到Static Duration），特点有

- 若不赋初值，则自动赋初值为0（非静态局部变量必须赋初值!!!）
- 只赋一次初值，语法上表现为第一次执行到该语句时赋初值
- 下一次调用的值是上一次调用结束时的值

**static只改变了变量的storage duration，不改变scope!!!**

请运行**zoo.cpp**，观察有关结果

```c++
#include<iostream>
using namespace std;
int generateID() {
    static int ID = 1;             // 可改成 "static int ID;" 再次运行
    return ID++;
}
void Dog() {
    cout << "There is a puppy! Its ID is " << generateID() << endl;
}
void Cat() {
    cout << "Here is a kitty! Its ID is " << generateID() << endl;
}
int main() {
    Dog();
    Cat();
    for (int i = 0; i < 5; i++) {
        cout << generateID() << endl;
    }
    return 0;
}
```



### 使全局变量获得内部链接属性

全局变量本身具有静态生命周期，若不赋初值，则自动赋初值为0；在C或C++中，全局变量只能声明、初始化，而不能在函数外赋值

```c++
# include...
int a;              // 全局变量的声明，自动赋初值为0
int b = 8;        // 全局变量的初始化
int c;
c = 10;           // 编译不通过，不可在函数外对全局变量赋值（具体原因可自行查阅资料）
....
```

全局变量原本为外部链接属性，可以在多个编译单元中使用，添加static修饰符后，变为内部链接属性，其他编译单元不可见

请同时将**1.cpp**与**2.cpp**放在一起运行，再继续按提示逐步观察运行结果

## 4.1.3  类内作用

### 静态成员变量

在定义一个类后并实例化一个类对象时，每个对象都会得到该类所有（非静态）成员变量的“副本”（人手一个，相互独立）。但使用了 static 关键字可以使类的成员变量成为静态的成员变量。静态成员变量的特点如下：

- 静态成员变量属于整个类所有，它的生命期不依赖于任何对象
- 静态成员变量由类的所有对象共享，同一个类的不同对象访问的静态成员是同一个
- 可以通过类名直接访问公有静态成员变量，也可以通过对象名访问公有静态成员变量

### 静态成员函数

当静态成员变量为私有时，若想访问则必须通过函数来实现。此时，如果使用普通成员函数，则需要先实例化一个对象才可以使用该函数，针对此种情况，产生了静态成员函数。静态成员函数的特点如下：

- 静态成员函数属于整个类所有，没有this指针
- 静态成员函数只能直接访问静态成员变量和静态成员函数
- 可以通过类名直接访问类的公有静态成员函数，也可以通过对象名访问类的公有静态成员函数

**引入静态成员变量（函数）便于使同一个类产生的不同对象之间产生联系**

请运行**mem_fun.cpp**，观察运行结果

```c++
#include <iostream>
using namespace std;
class Student {
 public:
  Student(): stuID(ID++){}
  int getID1() const  { return stuID; }   // 非静态成员函数可调用静态、非静态成员变量
  //int getID1() const  { return ID; }
  static int getID2();
private:
  static int ID;                                     // 此处是声明而非定义
  int stuID;
};
int Student::ID{ 0 };                           // 静态成员变量必须在类外和函数外定义（此时如果不赋初值会自动赋初值）（C++17作出了调整，感兴趣可自
                                                         // 行查阅有关资料）
int Student::getID2(){                       // 静态成员函数只能调用静态成员变量
    return ID++; 
}
/*int Student::getID2(){ 
    return stuID++; 
}*/
int main()
{
    Student Wang;
    Student Li;
    Student Xu;
    cout << Wang.getID1() << '\n';
    cout << Wang.getID2() << '\n';
    cout << Li.getID1() << '\n';
    cout << Li.getID2() << '\n';
    cout << Xu.getID1() << '\n';
    cout << Xu.getID2() << '\n';
    //cout << Student::getID1() << '\n';
    cout << Student::getID2() << '\n';                       // 可以通过 类名 直接访问 公有 静态 成员函数
    //cout << Student::stuID << '\n';
    //cout << Student::ID << '\n';                              // 可以通过 类名 直接访问 公有 静态 成员变量
    return 0;
}
```

## 编者注

由于篇幅所限，编者只是将static修饰符最浅显的部分进行了介绍，对于很多概念细节，仍需大家自行查阅相关资料加以了解

tutorial中的相关文件均在codes文件夹中，读者可自行运行查看结果，鼓励大家在此基础上再进行研究（包括修改代码运行来加深理解）

由于编者水平有限，本份教程难免有疏漏之处，还望读者批评指出

