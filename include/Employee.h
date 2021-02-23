// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum Positions {
  PERSONAL,
  DRIVER,
  CLEANER,
  TESTER,
  ENGINEER,
  PROGRAMMER,
  TEAMLEADER,
  PROJECTMANAGER,
  SENIORMANAGER
};
class Employee {
protected:
  unsigned int id;
  std::string name;
  double payment;
  int worktime;
  int position;
public:
  Employee(unsigned int id, std::string name,
           int worktime, int position);
  void setWorkTime(int worktime);
  virtual void calc() = 0;
  virtual void printInfo() = 0;
  std::string getName() const;
  double getPay() const;
  int getWorktime() const;
};


#endif  // INCLUDE_EMPLOYEE_H_



