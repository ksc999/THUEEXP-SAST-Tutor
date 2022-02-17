#include "occupation.h"
#include "salary.h"

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  Coder cod1 = Coder(111, 3000);
  Coder cod2 = Coder(222, 5000);
  cout << "woker_num:" << cod1.Get_num() 
    <<" year_salary:" << Cou_year_salary(cod1.Get_month_salary()) << endl;
  cout << "woker_num:" << cod2.Get_num() 
    <<" year_salary:" << Cou_year_salary(cod2.Get_month_salary()) << endl;
  system("pause");
  return 0;
}