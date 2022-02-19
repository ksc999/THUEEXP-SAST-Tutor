#include"constants.h"

#include<iostream>
using namespace std;

class rectangle { //定义一个矩形类
 public:
  rectangle(double l, double w) : length(l), width(w) {} //构造函数
  double length; //长
  double width; //宽
  double get_area() /*注意此处的const*/ const { return length * width; } //求矩形的面积
  bool operator < (const rectangle& r) { //比较两个矩形面积的大小
	return get_area() < r.get_area();
  }
};
int main() {
  //const变量
  const int a = 10; //静态绑定
  int b;
  cin >> b;
  const int c = b; //动态绑定
  //a++; //常量不能修改
  //c++;
  char txt0[10];
  char txt1[a];
  //char txt2[b];
  //char txt3[c]; //运行时绑定的常量不能作为数组大小


  //const作为函数参数
  void func(const int* p);

  //类中的const
  const rectangle re(6, 7); //构造一个常对象
  re.get_area(); //可以调用常成员函数
  //re.length = 2; //不能修改常对象的数据

  rectangle a(2, 5), b(3, 4); //构造两个矩形
  if (a < b) cout << "矩形a的面积小于b" << endl;


  //多文件下的const
  cout << "please enter the radius:";
  double r;
  cin >> r;
  cout << "the area of the circle is: " << constants::pi * r * r << endl;

  return 0;
}
void func(const int* p) {
  int a = *p;
  //*p = a++; //不能修改
}