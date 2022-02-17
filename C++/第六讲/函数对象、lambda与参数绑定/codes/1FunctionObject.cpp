//例1.1
/*
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
    int ans = f(a, b);  //此处f类似一个函数，但实际是在调用重载的()操作符
    cout << ans;
}
*/

//例1.2
/*
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
*/


//例1.3
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction(int i, int j) { return (i > j); } //自定义比较函数

class myclass {  //重载()的类
public:
    bool operator() (int i, int j) { return (i > j); }
} myobject;     //自定义一个函数对象myobject

int main() {
    int myints[] = { 32,71,12,45,26,80,53,33 };
    // 将该数组的8个元素装入容器
    vector<int> myvector(myints, myints + 8);
    vector<int>::iterator it;    //迭代器，用来访问元素
    // 使用默认的比较函数(operator <)排列前四个元素:
    //(12 32 45 71) 26 80 53 33
    sort(myvector.begin(), myvector.begin() + 4);

    // 使用自定义的比较函数排列后四个元素
    // 12 32 45 71 (80 53 33 26)
    sort(myvector.begin() + 4, myvector.end(), myfunction);

    // 使用三种函数对象排序(效果一样，同operator >)
    //(80 71 53 45 33 32 26 12)
    sort(myvector.begin(), myvector.end(), myobject);
    sort(myvector.begin(), myvector.end(), myclass());     //myclass是类名，后面要加()
    sort(myvector.begin(), myvector.end(), greater<int>());  //greater<int>是标准库里的类型

    cout << "myvector contains:";
    //使用迭代器遍历容器内元素输出
    for (it = myvector.begin(); it != myvector.end(); ++it)
        cout << " " << *it;

    return 0;
}
//结果：myvector contains: 80 71 53 45 33 32 26 12
*/
