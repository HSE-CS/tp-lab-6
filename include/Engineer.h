// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>

#include "Personal.h"

//=============================================

class Engineer : public Personal, public ProjectBudget {
 protected:
  project_t* project;
  Engineer(uint32_t id, const std::string& name, uint32_t salary, project_t*);
  uint32_t calcBudgetPart(double part, uint32_t budget);
  uint32_t calcBonus();

 public:
  virtual void calc();
  void printInfo();
};

//=============================================

class Programmer : public Engineer {
 protected:
  uint32_t calcProAdditions();

 public:
  Programmer(uint32_t id, const std::string& name, uint32_t salary, project_t*);
};

//=============================================

class Tester : public Engineer {
 private:
  uint32_t calcProAdditions();

 public:
  Tester(uint32_t id, const std::string& name, uint32_t salary, project_t*);
};

//=============================================

class TeamLeader : public Programmer, public Heading {
 private:
  uint32_t calcHeads();

 public:
  TeamLeader(uint32_t id, const std::string& name, uint32_t salary, project_t*);
  void calc();
};

#endif  // INCLUDE_ENGINEER_H_
