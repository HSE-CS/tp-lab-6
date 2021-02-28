// Copyright 27.02.21 DenisKabanov

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum post {  projectManager = 1,  seniorManager,
  engineer,  programmer,  tester,
  teamLeader,  driver,  cleaner
};

class Employee {
 private:
  unsigned int id;
  std::string name;
  int worktime = 0;
  int payment = 0;

 protected:
  post position;

 public:
  explicit Employee(unsigned int id, std::string name);
  void setWorkTime(int worktime);
  void setPayment(int payment);
  int getID();
  std::string getName();
  int getWorkTime();
  int getPayment();
  post getPos();
  virtual void calc() = 0;
  virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
