#pragma once
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public IWorkBaseTime {
 protected:
  int salary;

 public:
  Personal(int id, std::string name, std::string position, int worktime,
           int salary)
      : salary(salary), Employee(id, name, position, worktime) {}
  double calcBase(int salary, int wtime) override;
  double calcBonus() override;
  void calc() override;
  void printInfo() override;
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name, std::string position, int worktime,
         int salary)
      : Personal(id, name, position, worktime, salary) {}
  double calcBonus() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name, std::string position, int worktime,
         int salary)
      : Personal(id, name, position, worktime, salary) {}
  double calcBonus() override;
};
