// Copyright 2021 Danyaev Artem
#pragma once
#include <string>
#include "Personal.h"

class Engineer: public Personal, public ProjectBudget {
 protected:
  Project* project;
  int calcBudgetPart(float part, int budget);
  int calcBonus();
  void calc();
 public:
  Engineer(unsigned int id_, const std::string& name_,
	  Position pos, int salary_, Project* project_);
  void printInfo();
};

class Programmer: public Engineer{
 private:
  int calcProAdditions();
 public:
  Programmer(unsigned int id_, const std::string& name_,
	  Position pos, int salary_, Project* project_);
};

class Tester: public Engineer{
 private:
  int calcProAdditions();
 public:
  Tester(unsigned int id_, const std::string& name_,
	  Position pos, int salary_, Project* project_);
};

class TeamLeader: public Programmer, public Heading{
 private:
  int calcHeads();
  void calc();
  int calcProAdditions();
 public:
  TeamLeader(unsigned int id_, const std::string& name_,
	  Position pos, int salary_, Project* project_);
};
