//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"

class Personal: public Employee, public WorkBaseTime {
 protected:
  unsigned salary;

 public:
  Personal(int id, std::string name, Position position,
           unsigned worktime, unsigned salary)
  :Employee(id, name, position, worktime) {
    this->salary = salary;
  }
  unsigned getSalary();
  void setSalary(unsigned salary);
  unsigned calc() override;
  unsigned calcBase(unsigned salary, unsigned worktime) override;
  unsigned calcBonus() override;
  void printInfo() override;
};

class Driver : public Personal {
 private:
  unsigned nightHours;
 public:
  Driver(int id, std::string name,
         unsigned worktime, unsigned salary)
  :Personal(id, name, Position::Driver, worktime, salary) {}
  unsigned calcBonus() override;
  void setNightHours(unsigned hours);
  void printInfo() override;
};

class Cleaner: public Personal {
 public:
  Cleaner(int id, std::string name,
          unsigned worktime, unsigned salary)
  :Personal(id, name, Position::Cleaner, worktime, salary) {}
};

#endif  // INCLUDE_PERSONAL_H_
