// Copyright 2021 LongaBonga


#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Project {
 private:
 public:
  Project() {}
  ~Project() {}
  int id;
  int budget;
  std::string name;
};

#endif // INCLUDE_PROJECT_H_
