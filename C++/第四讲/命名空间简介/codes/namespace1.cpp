#include <iostream> 
// 在这里我们不使用using namespace std
namespace Student {
  int a = 108;
  int b = 100;
  namespace EE{
    double a = 15.05;
    double b = 84.95;
    void involution();
  }
  void EE::involution() {
    std::cout << "touching fish" << std::endl;
  }
  void involution(){
    std::cout << "involution" << std::endl;
  }
}
int main()
{
    std::cout << Student::b << ' ' << Student::EE::b << std::endl;
    //EE::involution();       // 编译不通过，嵌套后必须一层一层引用，除非前面的层已经声明
    using namespace Student;  // 声明命名空间
    std::cout << EE::a << ' ' << a << std::endl;
    EE::involution();
    involution();
    return 0;
}