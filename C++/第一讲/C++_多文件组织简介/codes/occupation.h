#ifndef OCCUPATION_H
#define OCCUPATION_H

class Coder {
 public:
  Coder(int, double);
  int Get_num();
  double Get_month_salary();

 private:
  int num_;
  double month_salary_;
};

#endif