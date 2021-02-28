// Copyright DB 2021
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include"Employee.h"
#include"Engineer.h"
#include"Manager.h"
class Project {
 public:
  int Id;
  int budget;
  std::string name;
  Project(int Id, std::string name, int budget)
      : Id(Id), name(std::move(name)), budget(budget) {}
};


class Factory {
 public:
  static std::vector<Employee*> makeStaff();
};

#endif  // INCLUDE_FACTORY_H_