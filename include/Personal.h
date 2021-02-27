// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include <iostream>

#include "Employee.h"
#include "Interfaces.h"


class Personal : public Emploeey, WorkBaseTime {
 public:
  explicit Personal(int id, std::string name, std::string position,
                    int worktime, int payment)
      : Emploeey(id, name, position, worktime, payment) {}

  int calc() override;
  int calcBase(int p, int wt) override;
  int calcBonus() override;

  void printInfo() override;
};

class Cleaner: public Personal {
 public:
  Cleaner(int id, std::string name, std::string position, int worktime,
          int payment)
      : Personal(id, name, position, worktime, payment) {}
  int calc() override;
  int calcBonus() override;
  void printInfo() override;
};

class Driver: public Personal {
 public:
  Driver(int id, std::string name, std::string position, int worktime,
         int payment)
      : Personal(id, name, position, worktime, payment) {}

  int calc() override;
  int calcBonus() override;
  void printInfo() override;
};

#endif  // INCLUDE_PERSONAL_H_
