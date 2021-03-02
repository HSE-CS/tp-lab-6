// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"
#include "string"
#include "Interfaces.h"
#include "Factory.h"

class Engineer : public Personal, ProjectBudget {
 public:
  explicit Engineer(int id, std::string name, std::string position,
    int workTime, int payment, Project* project)
    : Personal(id, name, position, workTime, payment) {
    this->project = project;
  }
  int calc() override;
  int calcBudgetPart(float part, int budget) override;
  int calcProAdditions() override;
  Project* getProject();
  void printInfo();
 private:
  Project* project;
};

class Tester : public Engineer {
 public:
  explicit Tester(int id, std::string name,
    std::string position, int workTime,  int payment,
    Project * project) :
    Engineer(id, name, position, workTime, payment, project) {}
  ~Tester();
  int calcAdditions();
  int calcProAdditions() override;
  int calcBonus() override;
  int calc() override;
  void printInfo();
};

class Programmer : public Engineer {
 public:
  explicit Programmer(int id, std::string name, std::string position,
    int workTime, int payment, Project* project )
    : Engineer(id, name, position, workTime, payment, project) {}
  ~Programmer();
  int calc() override;
  int calcBonus() override;
  int calcProAdditions() override;
  void printInfo() override;
};

class TeamLeader : public Programmer, Heading {
 public:
  explicit TeamLeader(int id, std::string name, std::string position,
    int workTime, int payment, Project* project )
    : Programmer(id, name, position, workTime, payment, project) {}
  ~TeamLeader();
  int calc() override;
  int calcBonus() override;
  int calcHeads() override;
  void printInfo();
};
#endif  //  INCLUDE_ENGINEER_H_
