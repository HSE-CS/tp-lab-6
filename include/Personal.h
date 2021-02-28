// Copyright 2020 GHA Test Team
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <string>
#include "Employee.h"
#include "Interfaces.h"


class Personal : public Employee, public WorkBaseTime {
protected:
  int salary = 0;
  void initializeParamsByZero();

public:
  void printInfo() const;
  int calcBase(int salary, int wtime) const;
};


class Cleaner : public Personal {
public:
  Cleaner();
  Cleaner(int id, std::string name, int salary);
  int calcBonus() const;
  void calc();
};

class Driver : public Personal {
public:
  Driver();
  Driver(int id, std::string name, int salary);
  void printInfo() const override;
  int calcBonus() const;
  void calc();
};

#endif  // INCLUDE_PERSONAL_H_
