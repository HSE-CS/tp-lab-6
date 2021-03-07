// Copyright 2020 me

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include<string>
#include "Employee.h"
#include "Interfaces.h"

class Personal: public Employee, public WorkBaseTime {
 private:
  int salary;

 public:
  Personal(unsigned _id, std::string _name, Position _position, int _salary):
      Employee(_id, _name, _position), salary(_salary) {}
  int getSalary();
  int calcBase(int salary, int wtime) override;
  void printInfo() override;
  int calcBonus() override;
};

class Driver: public Personal {
 private:
  int extraWorkTime;

 public:
  Driver(unsigned _id, std::string _name, Position _position, int _salary,
         int extraTime):
      Personal(_id, _name, _position, _salary), extraWorkTime(extraTime) {}
  int calcBonus() override;
  void calc() override;
  void printInfo() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(unsigned _id, std::string _name, Position _position, int _salary)
      : Personal(_id, _name, _position, _salary) {}
  void calc() override;
};

#endif  // INCLUDE_PERSONAL_H_
