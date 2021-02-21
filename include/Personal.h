//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include "Interfaces.h"
#include "Employee.h"

class Personal : public Employee, WorkBaseTime {
 public:
  explicit Personal(int id,
                    const std::string &name,
                    const std::string &position,
                    int payment)
                    : Employee(id, name, position, payment) {}
  /* Salary calculations */
  int calc() override;
  int calcBonus() override;
  int calcBase(int sl, int wt) override;
  /* Print */
  void printInfo() override;
};

class Driver : public Personal {
 public:
  explicit Driver(int id,
                  const std::string &name,
                  const std::string &position,
                  int payment)
      : Personal(id, name, position, payment) {}
  /* Salary calculations */
  int calc() override;
  int calcBonus() override;
  int calcBase(int sl, int wt) override;
  /* Print */
  void printInfo() override;
};

class Cleaner : public Personal {
 public:
  explicit Cleaner(int id,
                   const std::string &name,
                   const std::string &position,
                   int payment)
      : Personal(id, name, position, payment) {}
  /* Salary calculations */
  int calc() override;
  int calcBonus() override;
  int calcBase(int sl, int wt) override;
  /* Print */
  void printInfo() override;
};

#endif  //  INCLUDE_PERSONAL_H_
