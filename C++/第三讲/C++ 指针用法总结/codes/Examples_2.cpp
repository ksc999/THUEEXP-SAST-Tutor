#include <iostream>
void add(int a, int b)
{
    std::cout << "加和为 " << a + b;
}
void sub(int a, int b)
{
    std::cout << "相差为 " << a - b;
}
void mul(int a, int b)
{
    std::cout << "相乘为" << a * b;
}
void fun1() {
    std::cout << "Fun1";
}
void fun2() {
    std::cout << "Fun2";
}
void funx(void (*fun)()){
    fun();
}

int main()
{

    //关于函数指针数组的主程序部分

    /*
    void (*fun_ptr_arr[])(int, int) = { add, sub, mul };
    int x, a = 1, b = 2;

    std::cout << "请选择: 输入0让两数相加, 输入1让两数相减，输入2让两数相乘\n";
    std::cin >> x;

    if (x > 2) 
        return 0;
    (*fun_ptr_arr[x])(a, b);
    return 0;
    */

    //关于函数指针作为参数传递的主程序部分

    /*
    funx(fun1);
    funx(fun2);
    return 0;
    */
}