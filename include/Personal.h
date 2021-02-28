// Copyright DB 2021
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <string>

#include "Employee.h"
#include "Interfaces.h"
class Personal : public Employee, public WorkBaseTime {
 protected:
  int salary;

 public:
  Personal(int id, const std::string &name, Position positon,
           int salary) :
      Employee(id, name, position), salary(salary) {}
  int calcBase(int salary, int worktime) override;
  int calcBonus() override;
  void calc() override;
  void printInfo() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, const std::string &name, Position positon,
          int salary) : 
      Personal(id, name, position, salary){};
};

class Driver : public Personal {
 public:
  Driver(int id, const std::string &name, Position positon,
         int salary) : 
      Personal(id, name, position, salary){};
  int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_