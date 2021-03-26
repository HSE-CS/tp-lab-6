// Copyright 2020 Uskova
#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_

#include <string>

class Project {
 private:
  int id;
  std::string name;
  int budget;
  int workers;

 public:
  Project(int, std::string, int);
  int getBudget();
  int getId();
  std::string getName();
  int getWorkers();
  void addWorker();
  float calcPart();
};

#endif  // INCLUDE_PROJECT_H_
