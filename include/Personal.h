// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"

//=============================================

class Personal : public Employee, public WorkBaseTime {
 protected:
  uint32_t salary;
  Personal(uint32_t id, std::string& name, uint32_t salary);
  uint32_t calcBase(uint32_t salary, uint32_t worktime);

 public:
  void printInfo();
};

//=============================================

class Cleaner : public Personal {
 private:
  uint32_t calcBonus() { return 0; };

 public:
  Cleaner(uint32_t id, std::string& name, uint32_t salary);
  void calc();
};

//=============================================

class Driver : public Personal {
 private:
  uint32_t calcBonus();

 public:
  Driver(uint32_t id, std::string& name, uint32_t salary);
  void calc();
};

#endif  // INCLUDE_PERSONAL_H_
