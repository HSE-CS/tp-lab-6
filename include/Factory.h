// Copyright DBarinov
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include"Engineer.h"
#include"Manager.h"
class Factory {
 private:
  std::vector<Employee*> staff;
 public:
  std::vector<Employee*> makeStaff(const std::string dir);
};
#endif  // INCLUDE_FACTORY_H_