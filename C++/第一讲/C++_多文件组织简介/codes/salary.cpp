#include "salary.h"

#include <iostream>
using namespace std;

double Cou_day_salary(double month_salary) {
  double day_salary = month_salary / 30;
  return day_salary;
}

double Cou_year_salary(double month_salary) {
  double year_salary = month_salary * 12;
  return year_salary;
}