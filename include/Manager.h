// Copyright 2021 Smirnov Grigory
#include <vector>
#include "Engineer.h"
#include "Interfaces.h"

class ProjectManager : public Heading, public ProjectBudget {
 private:
  Project& project;

 public:
  virtual int calcHeads();
  virtual void calc();
};

class SeniorManager : public ProjectManager {
 private:
  std::vector<Project*> projects;

 public:
  virtual void calc();
};
