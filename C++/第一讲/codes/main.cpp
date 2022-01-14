/**
 * @file main.cpp
 * @author Zsbyqx2020
 * @brief the main program file.
 * @version 0.1
 * @date 2022-01-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <cstring>
#include <iostream>

#include "base.h"
using namespace std;

int main() {
  // generate an employee obj
  Employee emp = Employee("Little Red Hat", 20210103, 3000, 40, "Staff");
  // generate an administrator obj
  Administrator adm = Administrator("Nightfall Duke", 20200109, 4000, 30, 10);
  // test the Print_info() function of both objs.
  emp.Print_info();
  cout << endl;
  adm.Print_info();
  return 0;
}