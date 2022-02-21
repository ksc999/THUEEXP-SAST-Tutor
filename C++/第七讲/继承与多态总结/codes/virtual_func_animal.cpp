#include <iostream>
#include <string>
class Animal
{
protected:
    std::string m_name;
    Animal(const std::string& name) : m_name(name) {}
public:
    virtual std::string speak() const { return "???"; }
};
class Cat : public Animal
{
public:
    Cat(const std::string& name) : Animal(name) {}
    virtual std::string speak() const { return "Meow"; }
};
class Dog : public Animal
{
public:
    Dog(const std::string& name) : Animal(name) {}
    virtual std::string speak() const { return "Woof"; }
};
void report(const Animal& animal)
{
    std::cout << animal.speak() << '\n';
}
int main()
{
    Cat cat{ "Fred" };
    Dog dog{ "Garbo" };
    report(cat);
    report(dog);
    return 0;
}