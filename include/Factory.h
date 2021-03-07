// Copyright 2021 Tatsenko Alexey
#include<vector>
#include<string>
#include"Employee.h"

class Factory {
 private:
  std::vector<Employee*> staff;

 public:
  std::vector<Employee*> make_staff(std::string f1,
                                   std::string f2);
};
