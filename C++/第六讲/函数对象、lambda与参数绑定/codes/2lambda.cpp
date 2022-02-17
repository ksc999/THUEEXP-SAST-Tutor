//例2.1
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class ShorterString {
  public:
    bool operator() (const string& a, const string& b) const {
        return a.size() < b.size();
    }
};
int main() {
    vector<string>words{ "sdfz","msdj","qhdx","zwjzm" };
    vector<string>::iterator it;

    auto f = [](const string& a, const string& b)
    { return a.size() < b.size(); };

    sort(words.begin(), words.end(),
        [](const string& a, const string& b)
        { return a.size() < b.size(); });
    //这相当于
    sort(words.begin(), words.end(), f);
    //也相当于
    sort(words.begin(), words.end(), ShorterString());
    for (it = words.begin(); it != words.end(); it++)
        cout << *it<<"  ";
    return 0;
}
*/


//例2.2
/*
#include<iostream>
using namespace std;
void func1()
{
    int t = 42; //函数内的局部变量
    //将t拷贝到名为f的可调用对象   值捕获
    //此时传入了值是42，不会随着之后t的改变而改变
    auto f = [t] { return t; };
    t = 0;
    auto j = f();     //j=42
    cout << j<<endl;
}
void func2()
{
    int t = 42; //局部变量
    //将t拷贝到名为f的可调用对象
    //引用捕获，结果会随着之后t的改变而改变
    auto f = [&t] { return t; };
    t = 0;
    auto j = f();     //j=0
    cout << j << endl;
}
int main() {
    func1();
    func2();
    return 0;
}
*/


//例2.3
/*
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
*/

//例2.4
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp(int a, int sz) {    //比较函数，接受两个参数
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
*/

