/**
 * @file base.h
 * @author Zsbyqx2020
 * @brief defines all the classes and their menber functions
 * @version 0.1
 * @date 2022-01-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <string>

/**
 * @brief The base class.
 * Defines the name, the working ID and the base salary of the workers.
 */
class Worker {
 public:
  /**
   * @brief Construct a new Worker object.
   */
  Worker(std::string, int, double);
  /**
   * @brief Print the basic information of the worker.
   */
  void Print_info();

 protected:
  /**
   * @brief name of the worker in type "string"
   */
  std::string name_;
  /**
   * @brief  working number of the worker in type "int"
   */
  int num_;
  /**
   * @brief base salary of the worker in type "double"
   */
  double base_salary_;
};

/**
 * @brief Subclass of Worker.
 * Defines an employee of the company,
 * with his working hours and Department added.
 */
class Employee : public Worker {
 public:
  /**
   * @brief Construct a new Employee object
   */
  Employee(std::string, int, double, double, std::string);
  /**
   * @brief Print the basic information of the employee.
   */
  void Print_info();
  /**
   * @brief Calculate the employee's salary.
   * @return double
   */
  double Salary();

 private:
  /**
   * @brief The working hours of the employee during one week.
   */
  double weekly_working_hours_;
  /**
   * @brief The department this employee works in.
   */
  std::string department_;
};

class Administrator : public Worker {
 public:
  /**
   * @brief Construct a new Administrator object
   */
  Administrator(std::string, int, double, int, int);
  /**
   * @brief Print the basic information of the administrator.
   */
  void Print_info();
  /**
   * @brief Calculate the employee's salary.
   * @return double
   */
  double Salary();

 private:
  /**
   * @brief The number of employees in the administrator's team.
   */
  int employee_num_;
  /**
   * @brief The working years of the administrator.
   */
  int working_years_;
};