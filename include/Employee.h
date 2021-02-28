// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>
class Project {
 private:
  int id;
  int budget;
  int amountOfWorkers;
 public:
  Project(int id, int budget, int amountOfWorkers);
  int getAmountOfWorkers() const;
  int getBudget() const;
};
enum Positions {
  cleaner,
  driver,
  tester,
  programmer,
  team_leader,
  project_manager,
  senior_manager
};
class Employee {
 private:
  int id;
 protected:
  Positions position;
  int payment;
  int workTime;
  std::string name;
  std::vector<std::string>enum_print={"cleaner",
                                      "driver",
                                      "tester",
                                      "programmer",
                                      "team_leader",
                                      "project_manager",
                                      "senior_manager"};
 public:
  Employee(int id, std::string name,
           int workTime, Positions position);

  virtual int calc() = 0;
  virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_



