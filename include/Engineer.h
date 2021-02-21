//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <string>
#include <vector>
#include "Factory.h"
#include "Personal.h"
#include "Manager.h"

class Engineer : public Personal, ProjectBudget {
 public:
  explicit Engineer(int id,
                    const std::string &name,
                    const std::string &position,
                    int payment,
                    Project *project)
      : Personal(id, name, position, payment),
        project(project) {}
  /* Salary calculations */
  int calc() override;
  int calcBonus() override;
  int calcBase(int sl, int wt) override;
  int calcBudgetPart(double part, int budget) override;
  int calcProAdditions() override;
  /* Getters */
  Project *getProject();
  /* Print */
  void printInfo() override;

 private:
  Project *project;
};

class Tester : public Engineer {
 public:
  explicit Tester(int id,
                  const std::string &name,
                  const std::string &position,
                  int payment,
                  Project *project, int mistakes)
      : Engineer(id, name, position,
                 payment, project) {}
  /* Salary calculations */
  int calc() override;
  int calcBonus() override;
  int calcBase(int sl, int wt) override;
  int calcBudgetPart(double part, int budget) override;
  int calcProAdditions() override;
  /* Print */
  void printInfo() override;

 private:
  int mistakes = 0;
};

class Programmer : public Engineer {
 public:
  Programmer(int id,
             const std::string &name,
             const std::string &position,
             int payment,
             Project *project)
      : Engineer(id,
                 name,
                 position,
                 payment,
                 project) {}
  /* Salary calculations */
  int calc() override;
  int calcBonus() override;
  int calcBase(int salary, int wtime) override;
  int calcBudgetPart(double part, int budget) override;
  int calcProAdditions() override;
  /* Print */
  void printInfo() override;
};

class TeamLeader : public Programmer, Heading {
 public:
  TeamLeader(int id,
             const std::string &name,
             const std::string &position,
             int payment, Project *project)
      : Programmer(id, name, position,
                   payment, project) {}
  /* Salary calculations */
  int calc() override;
  int calcBonus() override;
  int calcBase(int salary, int wtime) override;
  int calcBudgetPart(double part, int budget) override;
  int calcProAdditions() override;
  int calcHeads() override;
  /* Print */
  void printInfo() override;
};

#endif  //  INCLUDE_ENGINEER_H_
