#include <iostream>
class A
{
public:
    virtual std::string getName() const { return "A"; }
};
class B : public A
{
public:
    virtual std::string getName() const { return "B"; }
};
class C : public B
{
public:
    virtual std::string getName() const { return "C"; }
};
class D : public C
{
public:
    virtual std::string getName() const { return "D"; }
};

int main()
{
    C c;
    A& rBase{ c };
    std::cout << "rBase is a " << rBase.getName() << '\n';
    return 0;
}