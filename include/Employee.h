//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>
#include <iostream>

enum class Position {
  Programmer, Tester, TeamLeader,
  ProjectManager, SeniorManager,
  Cleaner, Driver
};

class Project {
 private:
  int id;
  unsigned budget;
  unsigned membersNum = 0;

 public:
  Project(int id, unsigned budget);
  int getId();
  unsigned getBudget();
  unsigned getMembersNum();
  void setNewBudget(unsigned newBudget);
  void setMembersNum(unsigned newMembersNum);
  void printInfo();
};

class Employee {
 protected:
  int id;
  std::string name;
  Position position;
  unsigned worktime;
  unsigned payment;

 public:
  Employee(int id, std::string name,
           Position position, unsigned worktime = 0);
  int getId();
  std::string getName() const;
  Position getPosition() const;
  const std::string positionToString(Position position) const;
  unsigned getWorktime() const;
  unsigned getPayment();
  void setWorktime(unsigned time);
  void setPosition(Position position);
  virtual unsigned calc() = 0;
  virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
