// Copyright 2021 Danyaev Artem
#pragma once

#include <string>

enum Position { EMPLOYEE, PERSONAL, ENGINEER, CLEANER, DRIVER,
	PROGRAMMER, TESTER, TEAM_LEADER, PROJECT_MANAGER, SENIOR_MANAGER };

class Employee {
 protected:
  unsigned int id;
  std::string name;
  Position position;
  int worktime = 0;
  int payment;

 public:
  Employee(unsigned int id_, const std::string& name_, Position pos);
  void setWorkTime(int t);
  unsigned int getId();
  std::string getName();
  Position getPosition();
  int getWorkTime();
  int getPayment();
  virtual void calc() = 0;
  virtual void printInfo() = 0;
};

class Project{
 private:
  unsigned int id;
  std::string name;
  int budget;

 public:
  int numOfWorkers = 0;
  Project(unsigned int id_, const std::string& name_, int budget_);
  std::string getName();
  int getBudget();
};
