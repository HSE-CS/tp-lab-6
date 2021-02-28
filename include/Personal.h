//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include <string>
#include <cstring>

class Personal : public Employee, public WorkBaseTime {
 protected:
  int m_salary;

 public:
  Personal(int id, std::string name, std::string position, int salary);
  int calcBase(int salary, int wtime) override;
};

#endif  // INCLUDE_PERSONAL_H_

