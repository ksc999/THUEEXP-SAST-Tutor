/* 与1.cpp放在同一解决方案中运行！！！
0. 不作任何改动，运行；
1. 1.cpp语句前加上static修饰符，去掉2.cpp中的“extern”，运行；
2. 将函数show前的static去掉，运行，若报错直接进行下一步；
3. 再将2.cpp中函数名改为show1，运行，若报错直接进行下一步；
4. 再将2.cpp中的注释取消，运行。 */
#include<iostream>
using namespace std;
extern int counter;
// void show();
void show() {
    cout << "hello World!" << endl;
    cout << counter << endl;
}
int main() {
    show();
    return 0;
}