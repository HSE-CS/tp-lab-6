// Copyright 2020 Stanislav Stoianov

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include <iostream>
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
           int payment,
           Project *project)
      : Personal(id,
                 name,
                 position,
                 payment), project(project) {}

  Project *getProject() {
    return project;
  }

  int calc() override {
    return Personal::calc();
  }

  int calcBase(int salary, int wtime) override {
    return salary * wtime;
  }

  int calcBonus() override {
    return getWorktime() > 40
           ? (getWorktime() - 40) * static_cast<int>(getPayment() * 1.5)
           : 0;
  }

  int calcProAdditions() override {
    return calcBonus();
  }

  int calcBudgetPart(float part, int budget) override {
    return static_cast<int>(part * budget);
  }

  void printInfo() override {
    std::cout << "Engineer{id=" + std::to_string(getId()) +
        ", name=" + getName() +
        ", position=" + getPosition() +
        ", payment=" + std::to_string(getPayment()) +
        ", project{id=" + std::to_string(project->getId())
        + ", budget=" + std::to_string(project->getBudget())
        + "} }" << std::endl;
  }
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

  int calc() override {
    return Engineer::calc();
  }

  int calcBase(int salary, int wtime) override {
    return Engineer::calcBase(salary, wtime);
  }

  int calcBonus() override {
    return Engineer::calcBonus();
  }

  int calcBudgetPart(float part, int budget) override {
    return Engineer::calcBudgetPart(part, budget);
  }

  int calcProAdditions() override {
    return Engineer::calcProAdditions();
  }

  void printInfo() override {
    std::cout << "Programmer{id=" + std::to_string(getId()) +
        ", name=" + getName() +
        ", position=" + getPosition() +
        ", payment=" + std::to_string(getPayment()) +
        ", project{id=" + std::to_string(getProject()->getId())
        + ", budget=" + std::to_string(getProject()->getBudget())
        + "} }" << std::endl;
  }
};

class Tester : public Engineer {
 public:
  Tester(int id,
         const std::string &name,
         const std::string &position,
         int payment,
         Project *project)
      : Engineer(id,
                 name,
                 position,
                 payment,
                 project) {}

  int calc() override {
    return Engineer::calc();
  }

  int calcBase(int salary, int wtime) override {
    return Engineer::calcBase(salary, wtime);
  }

  int calcBonus() override {
    return Engineer::calcBonus();
  }

  int calcBudgetPart(float part, int budget) override {
    return Engineer::calcBudgetPart(part, budget);
  }

  int calcProAdditions() override {
    return Engineer::calcProAdditions();
  }

  void printInfo() override {
    std::cout << "Tester{id=" + std::to_string(getId()) +
        ", name=" + getName() +
        ", position=" + getPosition() +
        ", payment=" + std::to_string(getPayment()) +
        ", project{id=" + std::to_string(getProject()->getId())
        + ", budget=" + std::to_string(getProject()->getBudget())
        + "} }" << std::endl;
  }
};

class TeamLeader : public Programmer, IHeading {
 public:
  TeamLeader(int id,
             const std::string &name,
             const std::string &position,
             int payment,
             Project *project)
      : Programmer(id,
                   name,
                   position,
                   payment,
                   project) {}

  int calc() override {
    return Programmer::calc();
  }

  int calcBase(int salary, int wtime) override {
    return Engineer::calcBase(salary, wtime);
  }

  int calcBonus() override {
    return Engineer::calcBonus();
  }

  int calcBudgetPart(float part, int budget) override {
    return Engineer::calcBudgetPart(part, budget);
  }

  int calcProAdditions() override {
    return Engineer::calcProAdditions();
  }

  int calcHeads() override {
    return static_cast<int>(getProject()->getBudget() * 0.01);
  }

  void printInfo() override {
    std::cout << "Team Leader{id=" + std::to_string(getId()) +
        ", name=" + getName() +
        ", position=" + getPosition() +
        ", payment=" + std::to_string(getPayment()) +
        ", project{id=" + std::to_string(getProject()->getId())
        + ", budget=" + std::to_string(getProject()->getBudget())
        + "} }" << std::endl;
  }
};

#endif  // INCLUDE_ENGINEER_H_
