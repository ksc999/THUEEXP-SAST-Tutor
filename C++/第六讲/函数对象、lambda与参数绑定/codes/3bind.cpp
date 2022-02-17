//例3.1
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include<functional>
using namespace std;
using namespace std::placeholders;
bool comp(int a, int sz){    //比较函数，接受两个参数
    return a > sz;
}
int main() {
    int myints[] = { 32,71,12,45,26,80,53,33 };
    // 将该数组的8个元素装入容器
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;    //迭代器，用来访问元素

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

    auto wc3 = find_if(myvector.begin(), myvector.end(), bind(comp, _1, sz));
    //使用迭代器输出大于50的元素
    for (it = wc3; it != myvector.end(); ++it)
        cout << *it << " ";

    return 0;
}
*/


//例3.2
/*
#include <functional>
#include <iostream>
struct Foo {
    void func(int x, int y)
    {
        std::cout << x - y << '\n';
    }
    int data = 10;
};
int main() {
    Foo foo;
    auto f = std::bind(&Foo::func, &foo, 25, std::placeholders::_1);
    f(5); // 20
    return 0;
}
*/


//例3.3
/*
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
        bind(disp, ref(os), _1, cc));
    return 0;
}
*/


