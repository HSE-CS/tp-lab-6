// Copyright 2021 alexgiving

#ifndef INCLUDE_PERSONAL_H
#define INCLUDE_PERSONAL_H

#include "Employee.h"

class Personal : public Employee {
 private:
  size_t salary = 0;    // Payment per hour

 public:
  void setSalary(size_t);
  [[nodiscard]]size_t getSalary() const;
  [[nodiscard]]size_t calcBase() const;
  void printInfo();
};

#endif // INCLUDE_PERSONAL_H
