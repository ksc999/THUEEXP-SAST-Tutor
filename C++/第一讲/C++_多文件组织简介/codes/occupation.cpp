#include "occupation.h"

#include <iostream>
using namespace std;

Coder::Coder(int wnum, double wsa) {
  num_ = wnum;
  month_salary_ = wsa;
}

int Coder::Get_num() {
  return num_;
}

double Coder::Get_month_salary() {
  return month_salary_;
}