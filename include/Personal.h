// Copyright 2021 mkhorosh
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include "Employee.h"
#include "Interfaces.h"
#include <string>

class Personal : public Employee, public WorkBaseTime {
 protected:
  int salary;

 public:
  // constructor
  Personal(std::string id, std::string name, Position position,
           int work_time, int payment)
      : Employee(id, name, position, work_time, payment) {}
  // getter
  int getSalary();
  // setters
  int calcBase(int current_salary, int current_work_time) override;
  void calc() override;
  void printInfo() override;
};

class Driver : public Personal {
 public:
  // constructor
  Driver(std::string id, std::string name, Position position,
         int work_time, int payment)
      : Personal(id, name, position, work_time, payment) {}
  // setters
  int calcBase(int current_salary, int current_work_time) override;
  int calcBonus() override;
};

class Cleaner : public Personal {
 public:
  // constructor
  Cleaner(std::string id, std::string name, Position position,
          int work_time, int payment)
      : Personal(id, name, position, work_time, payment) {}
  // setter
  int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_
