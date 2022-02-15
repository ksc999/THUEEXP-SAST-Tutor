#include <iostream>
using namespace std;
class Student {
 public:
  Student(): stuID(ID++){}
  int getID1() const  { return stuID; } // 非静态成员函数可调用静态、非静态成员变量
  //int getID1() const  { return ID; }
  static int getID2();
private:
  static int ID;       // 此处是声明而非定义
  int stuID;
};
int Student::ID{ 0 };  // 静态成员变量必须在类外和函数外定义（此时如果不赋初值会自动赋初值）（C++17作出了调整，感兴趣可自行查阅有关资料）
int Student::getID2(){ // 静态成员函数只能调用静态成员变量
    return ID++; 
}
/*int Student::getID2(){ 
    return stuID++; 
}*/
int main()
{
    Student Wang;
    Student Li;
    Student Xu;
    cout << Wang.getID1() << '\n';
    cout << Wang.getID2() << '\n';
    cout << Li.getID1() << '\n';
    cout << Li.getID2() << '\n';
    cout << Xu.getID1() << '\n';
    cout << Xu.getID2() << '\n';
    //cout << Student::getID1() << '\n';
    cout << Student::getID2() << '\n'; // 可以通过 类名 直接访问 公有 静态 成员函数
    //cout << Student::stuID << '\n';
    //cout << Student::ID << '\n'; // 可以通过 类名 直接访问 公有 静态 成员变量
    return 0;
}