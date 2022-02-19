## 第六讲：函数对象、lambda表达式与参数绑定

### 一、函数对象

#### 1、函数对象的定义与特点

**函数对象**是可以实现操作符`()`的任何类型，简单来说，就是指一个重载了括号操作符`()`的类的对象。

这种对象使用起来如同使用一个函数。需要注意的是，重载`()`的函数，必须为该类的成员函数。

与直接函数调用相比，函数对象具有两个主要优点：

- 函数对象可以包含状态；
- 函数对象是一种类型，因此可以用作模板参数。

#### 2、函数对象简单使用示例

###### 例1.1：生成并使用一个简单的函数对象

~~~c++
#include <iostream>
using namespace std;

class Functor {
 public:
    int operator() (int a, int b) {  //重载()操作符，是成员函数
        return a < b;
    }
};

int main() {
    Functor f;      //声明一个函数对象
    int a = 5;
    int b = 7;
    int ans = f(a,b);  //此处f类似一个函数，但实际是在调用重载的()操作符
    cout << ans;    //ans=1
}
~~~

###### 例1.2：函数对象可以包含状态，即存储和传递数据（优点一）

~~~c++
#include <iostream>
using namespace std;
 
class F {
 public:
  F(int val) : data{val} {}
  bool operator() (int x) { return (x > data); }
 private:
  int data;
};
 
void Disp(int a[], int len, F op) {
  for (int i=0; i<len; i++) 
    if (op(a[i])) cout << a[i] << endl;
}
int main() {
  int a[10] = {12, 1, 454, 45, 67, 162, 2, 90, 15, 49}; 
  int b[3] =  {30, 150, 300};
 
  for (int k=0; k<3; k++) 
    Disp(a, 10, F(b[k]));
}

~~~

输出结果：

~~~c++
454          //k=0  打印a中大于30的元素
45
67
162
90           
49            
454          //k=1 打印大于150的元素
162               
454          //k=2 打印大于300的元素

~~~

#### 3、函数对象用于STL中

在C++标准库中，主要使用函数对象作为容器和算法的排序标准。(优点二)

###### 函数对象用于容器中：

STL中容器声明如下：`set`

~~~c++
template <class Key,
    class Traits=less<Key>,
    class Allocator=allocator<Key>>
class set
~~~

第二个模板参数是函数对象 。比如`less<int>`中的重载函数会比较两个`int`类型的参数，如果第一个参数小于第二个，则此函数对象返回true。通过这样一个函数对象便可以实现对容器内的元素排序。

###### 函数对象用于算法中

std::sort 算法默认使用元素类型的 `<` 运算符，但可能我们希望的顺序与<所定义的顺序不同，或者我们要排序的是自己定义的元素类型，此时我们需要向sort函数中传递第三个参数，此参数称为**谓词**。

注：谓词是一个可调用表达式，其返回结果是一个能用作条件的值。其分为**一元谓词**（接受单一参数）、**二元谓词**（两个参数）。接受谓词参数的算法对输入序列的元素调用谓词。

例1.3：在下面的程序中，我们给sort算法传入不同的（二元）谓词，实现特定的排序

~~~c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
bool myfunction (int i,int j) { return (i>j); } //自定义比较函数
 
class myclass {  //重载()的类
 public:
  bool operator() (int i,int j) { return (i>j);}
} myobject;     //自定义一个函数对象myobject
 
int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  // 将该数组的8个元素装入容器
  vector<int> myvector (myints, myints+8);       
  vector<int>::iterator it;    //迭代器，用来访问元素
  // 使用默认的比较函数(operator <)排列前四个元素:
  //(12 32 45 71) 26 80 53 33
  sort (myvector.begin(), myvector.begin()+4);  
 
  // 使用自定义的比较函数排列后四个元素
  // 12 32 45 71 (80 53 33 26)
  sort (myvector.begin()+4, myvector.end(), myfunction);
    
  // 使用三种函数对象排序(效果一样，同operator >)
  //(80 71 53 45 33 32 26 12)
  sort (myvector.begin(), myvector.end(), myobject);        
  sort (myvector.begin(), myvector.end(), myclass());     //myclass是类名，后面要加()
  sort (myvector.begin(), myvector.end(), greater<int>());  //greater<int>是标准库里的类型
 
  cout << "myvector contains:";
  //使用迭代器遍历容器内元素输出
  for (it=myvector.begin(); it!=myvector.end(); ++it)  
    cout << " " << *it;
    
  return 0;
}
//结果：myvector contains: 80 71 53 45 33 32 26 12
~~~

### 二、lambda表达式

#### 1、lambda表达式的定义

- **lambda表达式**是一个能够**捕获**作用域中**变量**的未命名**函数对象**。

- 一个lambda表达式表示一个可调用的代码单元，我们也可以理解为一个未命名的内联函数。

注：对于一个对象或者表达式，如果它可以使用`()`运算符，我们称之为是可调用的。即如果e是一个可调用的表达式，我们可以编写代码 `e(args);`其中`args`是一个逗号分隔的一个或多个参数列表）

函数、函数指针、重载了`()`运算符的类、lambda表达式，这四类都是可调用对象。

- lambda表达式具有一个`捕获列表`、一个`参数列表`、一个`返回类型`和一个`函数体`，可以被定义在一个函数的内部。

一个lambda表达式有如下形式：

~~~c++
[capture list] (paramter list) -> return type { funciton body }
~~~

其中，参数列表与返回类型可以忽略，捕获列表与函数体必须有（捕获内容可为空）。

例如下面这个lambda表达式（赋给f）：

~~~c++
auto f=[] { return 26; };
cout << f() ;    //打印26 
~~~

#### 2、传递参数

与一个普通函数类似，调用一个lambda时给定的实参被用来初始化lambda的形参。但是与普通函数不同的是，lambda表达式**不能有默认参数**，调用的实参数目必须与形参数目相同。

例如，我们可以这样编写一个lambda表达式用于两个字符串的比较：

~~~c++
auto f=[] (const string &a, const string &b)
          { return a.size() < b.size();};
~~~

lambda表达式是一个函数对象，上面的`f` 类似于下面这个类的对象：

~~~c++
class ShorterString{
  public:
    bool operator() (const string& a,const string& b) const{
        return a.size() < b.size();
    }   
};
~~~

我们可将其运用在排序算法中（设words是一个string容器）(例2.1)

~~~c++
sort(words.begin(),words.end(),
     [](const string &a, const string &b)
       { return a.size() < b.size();});
//这相当于
sort(words.begin(),words.end(),f);
//也相当于
sort(words.begin(),words.end(),ShorterString());
~~~

#### 3、使用捕获列表

- 捕获内容：**局部非static变量**

- 捕获意义：一个lambda只有在其捕获列表中捕获一个它所在函数中的局部变量，才能在函数体中使用该变量。

注：局部static变量与lambda表达式所在函数之外声明的变量可以直接使用，无需捕获。

~~~c++
[sz](const string &a) {return a.size()>=sz;}; //ok!(设sz是函数内局部变量)
[](const string &a) {return a.size()>=sz;};   //error! （没有捕获sz）
~~~

####  4、捕获与返回

当我们定义一个lambda表达式时，编译器自动生成一个与lambda表达式对应的新的（未命名）类类型。当向一个函数传递一个lambda时，就同时定义了一个新类型与该类型的一个对象。类似的，当用auto定义一个用lambda初始化的变量时（见上上个例子），定义了一个从lambda生成的类型对象。

从lambda生成的类包含了lambda所捕获的变量作为其数据成员，该数据成员在lambda对象创建时被初始化。

类似传递参数，lambda的捕获分为值捕获和引用捕获两种方式，编写时还可以使用简单的隐式捕获方式。

##### 值捕获

类似函数中的值传递，但要注意被捕获的变量的值是在lambda创建时拷贝，而不是调用时拷贝。(例2.2)

~~~c++
void func1()
{
    int t=42; //函数内的局部变量
    //将t拷贝到名为f的可调用对象   值捕获
    //此时传入了值是42，不会随着之后t的改变而改变
    auto f=[t] { return t;};
    t=0;
    auto j=f();     //j=42
}
~~~

##### 引用捕获

引用捕获某变量时，实际使用的是引用所绑定的对象。

~~~c++
void func2()
{
    int t=42; //局部变量
    //将t拷贝到名为f的可调用对象
    //引用捕获，结果会随着之后t的改变而改变
    auto f=[&t] { return t;};
    t=0;
    auto j=f();     //j=0
}
~~~

注意: 引用捕获时，必须保证在lambda执行时变量是存在的。并且我们应该尽量减少捕获的数据量。

##### 隐式捕获

由编译器自动判断捕获哪些变量

[=] 表示采用值捕获

[&] 表示采用引用捕获

更多的捕获方式可参见下表：

![](..\imgs\image1.png)

##### 可变lambda

默认情况下，lambda不会改变一个值被拷贝的变量。如果我们希望改变它，需要在参数列表后使用关键字mutable

例2.3：

~~~c++
#include <iostream>
int main() {
  int ammo{ 10 };
  //用lambda定义一个可调用对象shoot
  auto shoot{
    [ammo]() mutable {    //捕获ammo
      --ammo;    //使用mutable后可以更改lambda中ammo的值
      std::cout << "Pew! " << ammo << " shot(s) left.\n";
    }
  };
  //调用两次
  shoot();
  shoot();
  //打印主函数中的ammo
  std::cout << ammo << " shot(s) left";

  return 0;
}
//输出：
//Pew! 9 shot(s) left.
//Pew! 8 shot(s) left.
//10 shot(s) left
~~~

由于是值传递，所以主函数的ammo并没有发生改变。如果改为引用传递，则无需使用mutable，可以直接改变ammo，最后会输出8。

#### 5、返回类型

返回类型可以被忽略，此时，如果函数体只有一个return语句，则系统自动从返回表达式类型来判断返回类型；否则，返回类型为void。

因此，当函数体包含return语句之外的其他语句时，应该指定返回类型。

例如下面的这个lambda表达式：

~~~c++
[](int i) ->int       //指定返回int类型
 { if(i<0) return -i; else return i;};

//示例：lambda用于标准库里的transform算法
transform(v.begin(), v.end(), v.begin(),
         [](int i)->int {if(i<0) return -i; else return i;});
~~~

#### 6、使用小结

lambda表达式允许我们在另一个函数中定义一个匿名函数。嵌套很重要，因为它允许我们避免命名空间命名污染，并定义尽可能靠近使用它的位置的函数。

对于那种只在一两个地方使用的简单操作，lambda表示式是最有用的。

如果捕获列表为空，通常可用函数代替它。

lambda表达式常用在算法的谓词上，这里也体现了lambda捕获列表的优势：根据算法接受一元谓词还是二元谓词，我们传递给算法的谓词必须严格接受一个或两个参数，但有时我们又希望获得更多的参数，便可以通过捕获列表实现。

例2.4：`find_if`算法（只接受一元谓词）：

~~~c++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int sz){    //比较函数，接受两个参数
    return a > sz;
}
int main() {
    int myints[] = { 32,71,12,45,26,80,53,33 };
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;    

    // 使用默认的比较函数(operator <)排列所有元素:
    //12 26 32 33 45 53 71 80 
    sort(myvector.begin(), myvector.end());
    //定义比较标准sz
    int sz = 50;

    //获取一个迭代器wc,指向第一个>sz的元素
    //lambda表达式只接受一个参数，正确
    auto wc = find_if(myvector.begin(), myvector.end(),
        [sz](int a) {return a > sz; });

    //comp函数接受两个参数，不符合find_if的要求，错误
    //auto wc2= find_if(myvector.begin(), myvector.end(),comp);
    
    //使用迭代器输出大于50的元素
    for (it = wc; it != myvector.end(); ++it)
        cout << *it << " ";

    return 0;
}
//输出：53 71 80
~~~

### 三、参数绑定

#### 1、std::bind函数

在上面的例子中，传递给`find_if`的可调用对象必须接受单一参数，自定义的comp函数就不适用了，但我们可以使用**bind**函数（定义在头文件`functional`中），来用comp函数取代lambda表达式。

调用`bind`的一般形式如下：

~~~c++
auto newCallable = bind(Callable, arg_list);
~~~

可以将 bind 函数看作一个通用的函数适配器，它接受一个可调用对象`Callable`，生成一个新的可调用对象`newCallable`来 "适应" 原对象的参数列表。

`arg_list `是一个逗号分隔的参数列表，当我们调用`newCallable `时，`newCallable` 会调用 `Callable`，并传递给它 `arg_list` 中的参数。

`arg_list` 中的参数可能包含形如 `_n` 的名字，其中 `n` 是一个整数。这些参数是 "占位符"，表示 `newCallable` 的参数，它们占据了传递给 `newCallable `的参数的 "位置"。数值 `n` 表示 生成的可调用对象中参数的位置：`_1` 为 `newCallable` 的第一个参数，`_2` 为第二个参数，依此类推。

`_n` 都定义在命名空间 `placeholders` 中，且此命名空间又定义在命名空间 `std` 中。因此使用`bind`与`_n`之前应该声明：

~~~c++
#include<functional>
using namespace std;
using namespace std::placeholders;
~~~

#### 2、bind的使用

作为一个简单的例子，我们将使用`bind`生成一个调用上一个例子中的`comp`函数的对象，如下所示

~~~c++
auto comp1 = bind(comp, _1, 50);
//comp1是一个可调用对象，接受一个int参数（_1处）
//并用此参数与50调用comp函数
~~~

之前用lambda表达式写的wc可以更换为：（例3.1）

~~~c++
auto wc = find_if(myvector.begin(), myvector.end(),
                  bind(comp, _1, sz));
~~~

这便将`comp`的第二个参数绑定到了`sz`的值（50），只接受一个参数，满足了`find_if`的要求。

##### 调整参数顺序

如前文所示，我们可以用`bind`修正参数的值，也可以重新安排参数的顺序，获得更多新的函数。

例如，`f`是一个有5个参数的可调用对象，我们生成一个新可调用对象`g`，只有两个参数，用两个占位符表示

~~~c++
auto g=bind(f, a, b, _2, c, _1);
~~~

如此，a、b、c分别与`f`的第1、2、4个参数绑定起来，`g`的第1、2个参数分别与`f`的第5、3个参数绑定。

即，调用g(x, y)，就是调用f(a, b, y, c, x)

##### 绑定成员函数

除了绑定普通函数，`bind`还可以绑定成员函数，这时，第一个参数表示对象的成员函数的指针，第二个参数表示对象的地址，后面是参数列表。

例3.2：

~~~c++
struct Foo {
    void func(int x, int y)
    {
        std::cout << x-y << '\n';
    }
    int data = 10;
};
int main() {
    Foo foo;
    auto f = std::bind(&Foo::func, &foo, 25, std::placeholders::_1);
    f(5); // 20
}
~~~

##### 绑定引用参数

默认情况下， `bind` 的那些不是占位符的参数被拷贝到 `bind` 返回的可调用对象中。但是， 与 lambda 类似，有时对有些绑定的参数我们希望以**引用方式传递**， 或是要绑定参数的类型无法拷贝。这时，我们必须使用标准库**`ref`函数**(头文件`functional`中）。

例3.3：输出流对象`os`无法拷贝时，用`ref`返回引用

~~~c++
#include <iostream>
#include <algorithm>
#include <vector>
#include<functional>
using namespace std;
using namespace std::placeholders;

ostream& disp(ostream& os, const int a, char c) {
    return os << a << c;
}

int main() {
    int myints[] = { 32,71,12,45,26,80,53,33 };
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;
    sort(myvector.begin(), myvector.end());

    char cc = '*';
    ostream &os = cout;
    for_each(myvector.begin(), myvector.end(),
        bind(disp, ref(os), _1, cc));   //使用ref返回引用
    return 0;
}
//输出：12*26*32*33*45*53*71*80*
~~~



