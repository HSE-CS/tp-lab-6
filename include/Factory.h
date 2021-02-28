// Copyright 2021 mkhorosh
#ifndef INCLUDE_FACTORY_H_
#define INCLUDE_FACTORY_H_
#include <string>

class Project {
 public:
  std::string id;
  double budget;
  Project(std::string id, int budget);
};

class Factory {
 public:
  std::string filestaff;
  std::string fileproj;
  Factory(std::string filenamestaff, std::string fileproj);
  void readData();
};

#endif  // INCLUDE_FACTORY_H_
