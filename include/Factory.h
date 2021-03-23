// Copyright 2021 Lab_6 TiNa
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include "Personal.h"
#include <iostream>
#include <string>
#include <vector>

class Project {
 public:
  int id;
  int budget;
  Project(int id, int budget);
};

class Factory {
 protected:
  std::string filename;

 public:
  explicit Factory(std::string filenameIn)
      : filename(filenameIn) {}
  std::vector<Personal*> makeStaff();
};

#endif  // INCLUDE_FACTORY_H_
