#include "add.h"
#include "subtract.h"
#include <iostream>
int main()
{
    std::cout << Math::add(7, 9) << '\n';
    std::cout << Math::subtract(52, 9) << '\n';
    return 0;
}