/**
 * @file base.cpp
 * @author Zsbyqx2020
 * @brief implementation of all the functions defined in the .h file.
 * @version 0.1
 * @date 2022-01-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "base.h"

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Construct a new Worker object
 *
 * @param wname in "string" type, the worker's name.
 * @param wnum in "int" type, the worker's working number/ID.
 * @param wsa in "double" type, the worker's base salary.
 */
Worker::Worker(string wname, int wnum, double wsa) {
  name_ = wname;
  num_ = wnum;
  base_salary_ = wsa;
}

/**
 * @brief Print the worker's basic information.
 */
void Worker::Print_info() {
  cout << "Basic Information:" << endl
       << setw(22) << setiosflags(ios::left) << "Name" << setw(3) << ":"
       << name_ << endl
       << setw(22) << "ID" << setw(3) << ":" << num_ << endl;
}

/**
 * @brief Construct a new Employee object
 *
 * @param ename in "string" type, the employee's name.
 * @param enum in "int" type, the employee's working number/ID.
 * @param esa in "double" type, the employee's base salary.
 * @param ewh in "double" type, the employee's working hours during a week.
 * @param edep in "string" type, the employee's working department.
 */
Employee::Employee(string emname, int emnum, double esa, double ewh,
                   string edep)
    : Worker(emname, emnum, esa) {
  weekly_working_hours_ = ewh;
  department_ = edep;
}

/**
 * @brief Print the employee's basic information.
 */
void Employee::Print_info() {
  Worker::Print_info();
  cout << setw(22) << setiosflags(ios::left) << "Weekly working hours"
       << setw(3) << ":" << weekly_working_hours_ << endl
       << setw(22) << "Working Department" << setw(3) << ":" << department_
       << endl
       << setw(22) << "Salary" << setw(3) << ":" << Salary() << endl;
}

/**
 * @brief Calculate the salary of the employee.
 *
 * @return double
 */
double Employee::Salary() {
  return base_salary_ * (1 + weekly_working_hours_ / 10);
}

/**
 * @brief Construct a new Administrator object
 *
 * @param aname in "string" type, the admin's name.
 * @param anum in "int" type, the admin's working number/ID.
 * @param asa in "double" type, the admin's base salary.
 * @param aen in "int" type, the number of employees the admin has.
 * @param awy in "int" type, the admin's working years.
 */
Administrator::Administrator(string aname, int anum, double asa, int aen,
                             int awy)
    : Worker(aname, anum, asa) {
  employee_num_ = aen;
  working_years_ = awy;
}

/**
 * @brief Print the admin's basic information.
 */
void Administrator::Print_info() {
  Worker::Print_info();
  cout << setw(22) << setiosflags(ios::left) << "Employee number" << setw(3) << ":" 
       << employee_num_ << endl
       << setw(22) << "Working years" << setw(3) << ":" << working_years_ << endl
       << setw(22) << "Salary" << setw(3) << ":" << Salary() << endl;
}

/**
 * @brief Calculate the salary of the admin.
 *
 * @return double
 */
double Administrator::Salary() {
  return base_salary_ * (1 + employee_num_ / 20 + working_years_ / 10);
}