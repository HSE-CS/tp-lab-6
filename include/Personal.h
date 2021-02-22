// Copyright 2021 VadMack

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
class Personal : public Employee, public WorkBaseTime {
 protected:
  int salary;

 public:
  int calcBase(int salary, int workTime) override;
  void printInfo() override;
  int GetSalary() const;
  void SetSalary(int salary);
};

class Driver : public Personal {
 public:
  Driver(std::string id, std::string name, POSITION position, int salary);

  int calcBonus() override;
  void calc() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(std::string id, std::string name, POSITION position, int salary);
  int calcBonus() override;
  void calc() override;
};

#endif // INCLUDE_PERSONAL_H_