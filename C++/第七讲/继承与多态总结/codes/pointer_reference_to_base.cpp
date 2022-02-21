#include <iostream>
class Base
{
protected:
    int m_value;
public:
    Base(int value) :m_value(value) {}
    std::string getName() const { return "Base"; }
    int getValue() const { return m_value; }
};
class Derived : public Base
{
public:
    Derived(int value) :Base(value) {}
    std::string getName() const { return "Derived"; }
    int getValueDoubled() const { return m_value * 2; }
};
//这是基类与派生类的定义

int main()
{
    Derived derived{ 5 };
    Base& rBase{ derived };
    Base* pBase{ &derived };//派生类对象生成基类的指针和引用

    std::cout << "derived is a " << derived.getName();
    std::cout << " and has value " << derived.getValue() << '\n';
    std::cout << "rBase is a " << rBase.getName();
    std::cout << " and has value " << rBase.getValue() << '\n';
    std::cout << "pBase is a " << pBase->getName();
    std::cout << " and has value " << pBase->getValue() << '\n';
    return 0;
}