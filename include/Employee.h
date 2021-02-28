// Copyright 2021 mkhorosh
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <string>

enum Position {
  cleaner, driver, tester, programmer, engineer,
  team_Leader, senior_Manager, project_Manager
};

class Employee {  // basic(parent) class for all workers
 protected:
  std::string id;
  std::string name;
  Position position;
  int work_time;  // time worked hours
  int payment;  // sum salary (with bonus)

 public:
  // constructor
  Employee(std::string id, std::string name,
           Position position, int work_time, int payment);
  // getters
  std::string getId() const;
  std::string getName() const;
  Position getPosition() const;
  int getWorkTime() const;
  int getPayment() const;
  // setters
  void setWorkTime(int time);
  virtual void calc() = 0;
  virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
