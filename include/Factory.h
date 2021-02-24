// Copyright NikDemoShow 2021
#ifndef FACTORY_H_
#define FACTORY_H_
#include<fstream>
#include<sstream>
#include"Engineer.h"
#include"Manager.h"
class Factory {
 private:
  std::vector<Employee*> staff;
 public:
  std::vector<Employee*> makeStaff(const std::string dir);
};
#endif // FACTORY_H_
