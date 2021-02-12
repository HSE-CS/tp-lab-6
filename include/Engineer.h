// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Factory.h"
#include "Personal.h"
#include "Manager.h"

class Engineer : public Personal, IProjectBudget {
 private:
  Project *project;

 public:
  Engineer(int id,
           const std::string &name,
           const std::string &position,
           int worktime,
           int payment,
           Project *project)
      : Personal(id,
                 name,
                 position,
                 worktime,
                 payment), project(project) {}

  int calcBudgetPart(float part, int budget) override {
    return 0;
  }

  int calcProAdditions() override {
    return 0;
  }

  int calcBase(int salary, int wtime) override {
    return 0;
  }

  int calcBonus() override {
    return 0;
  }

  int calc() override {
    return Personal::calc();
  }

  void printInfo() override {
    Personal::printInfo();
  }
};

class Programmer : public Engineer {
 public:
  int calcBudgetPart(float part, int budget) override {
    return Engineer::calcBudgetPart(part, budget);
  }

  int calcProAdditions() override {
    return Engineer::calcProAdditions();
  }

  int calcBase(int salary, int wtime) override {
    return Engineer::calcBase(salary, wtime);
  }

  int calcBonus() override {
    return Engineer::calcBonus();
  }

  int calc() override {
    return Engineer::calc();
  }

  void printInfo() override {
    Engineer::printInfo();
  }

  int calsProAdditions() {
    return 0;
  }
};

class Tester : public Engineer {
 public:
  int calcBudgetPart(float part, int budget) override {
    return Engineer::calcBudgetPart(part, budget);
  }

  int calcProAdditions() override {
    return Engineer::calcProAdditions();
  }

  int calcBase(int salary, int wtime) override {
    return Engineer::calcBase(salary, wtime);
  }

  int calcBonus() override {
    return Engineer::calcBonus();
  }

  int calc() override {
    return Engineer::calc();
  }

  void printInfo() override {
    Engineer::printInfo();
  }

  int calsProAdditions() {
    return 0;
  }
};

class TeamLeader : public Programmer, IHeading {
 public:
  int calc() override {
    return Programmer::calc();
  }

  void printInfo() override {
    Programmer::printInfo();
  }

  int calcBudgetPart(float part, int budget) override {
    return 0;
  }

  int calcProAdditions() override {
    return 0;
  }

  int calcBase(int salary, int wtime) override {
    return 0;
  }

  int calcBonus() override {
    return 0;
  }

  int calcHeads() override {
    return 0;
  }
};

#endif  // INCLUDE_ENGINEER_H_
