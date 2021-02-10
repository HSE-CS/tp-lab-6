// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_6_SRC_PERSONAL_H_
#define TP_LAB_6_SRC_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include "Factory.h"

class Personal : private Employee, IWorkBaseTime {
 private:
  int salary;
 public:
  int calcBase();
};

class Driver : private Personal {
 public:
  int calcBase();
  int calc();
};

class Cleaner : private Personal {
  int calc();
};


#endif //TP_LAB_6_SRC_PERSONAL_H_
