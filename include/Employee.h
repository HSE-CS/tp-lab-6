// Copyright 2020 GHA Test Team
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <string>


enum class Position
{
  DRIVER,
  CLEANER,
  TESTER,
  PROGRAMMER,
  TEAM_LEADER,
  PROJECT_MANAGER,
  SENIOR_MANAGER,
};


class Employee {
protected:
  int id = 0;
  std::string name;
  Position position;
  int worktime = 0;
  int payment = 0;

public:
  int getPayment() const;
  void setWorkTime(int work_time);
  std::string getPosition() const;
  virtual void calc() = 0;
  virtual void printInfo() const = 0;
};
#endif  // INCLUDE_ENGINEER_H_
