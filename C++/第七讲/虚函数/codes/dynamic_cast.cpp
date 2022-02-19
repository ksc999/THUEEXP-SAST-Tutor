#include<iostream>
using namespace std;

class Base
{
public:
    Base() {};
    virtual void Show() { cout << "This is Base calss"; }
};
class Derived :public Base
{
public:
    Derived() {};
    void Show() { cout << "This is Derived class"; }
};
int main()
{
    //第一种情况
    Base* base = new Derived;
    if (Derived* der = dynamic_cast<Derived*>(base))
    {
        cout << "第一种情况转换成功" << endl;
        der->Show();
        cout << endl;
    }
    //第二种情况
    Base* base1 = new Base;
    if (Derived* der1 = dynamic_cast<Derived*>(base1))
    {
        cout << "第二种情况转换成功" << endl;
        der1->Show();
    }
    else
    {
        cout << "第二种情况转换失败" << endl;
    }

    delete(base);
    delete(base1);
    system("pause");
}