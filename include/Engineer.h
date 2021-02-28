// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Personal.h"
#include "Interfaces.h"

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project *project;
 public:
  Engineer(int id, std::string name,
           int workTime, int salary, Positions position, Project *p);
  int calc() override;
  int calcBudgetPart() override;
  void printInfo() override;
};
class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name,
             int workTime, int salary, Positions position, Project *pr);
  int calc() override;
  int calcProAdditions(int bonus = 5) override;
};
class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, std::string name,
             int workTime, int salary, Positions position, Project *pr);
  int calcHeads() override;
  int calc() override;
};
class Tester : public Engineer {
 public:
  Tester(int id, std::string name,
         int workTime, int salary, Positions position, Project *pr);
  int calc() override;
  int calcProAdditions(int bonus = 4) override;
};

#endif  // INCLUDE_ENGINEER_H_



