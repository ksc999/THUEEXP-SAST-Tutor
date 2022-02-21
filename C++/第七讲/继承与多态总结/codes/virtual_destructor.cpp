#include<iostream>
using namespace std;

class Base{
public:
    Base(){cout<<"Base()"<<endl;}
    ~Base(){cout<<"~Base()"<<endl;} //此处没有virtual标记，教程中将有无virtual标记的情况做了对比，
                                    //可以尝试添加virtual标记观察效果
    virtual void print(){cout<<"virtual Base.print()"<<endl;}
};
class subBase:public Base{
public:
    subBase(){cout<<"subBase()"<<endl;}
    ~subBase(){cout<<"~subBase()"<<endl;}
    virtual void print(){cout<<"virtual subBase.print()"<<endl;}
};
int main()
{
    Base *b=new subBase();
    b->print();
    delete b;
    return 0;
}
