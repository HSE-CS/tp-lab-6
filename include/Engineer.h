// Copyright 2021 Urtyukov Ilya
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Factory.h"
#include "Interfaces.h"
#include "Personal.h"

class Project;

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project* project;
  float part;

 public:
  Engineer(int, const std::string, std::string, int, int, Project*, float);
  void printInfo();
  float getPart();
  int calcBudgetPart(float part, int budget);
};

class Tester : public Engineer {
 public:
  Tester(int, const std::string, std::string, int, int, Project*, float);
  int calcProAdditions();
  int calc();
};

class Programmer : public Engineer {
 public:
  Programmer(int, const std::string, std::string, int, int, Project*, float);
  int calcProAdditions();
  int calc();
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int, const std::string, std::string, int, int, Project*, float);
  int calcHeads();
  int calc();
};

#endif  // INCLUDE_ENGINEER_H_
