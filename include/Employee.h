// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
enum POSITION {
  SENIORMANAGER,
  PROJECTMANAGER,
  TEAMLEADER,
  PROGRAMMER,
  TESTER,
  DRIVER,
  CLEANER,
  UNKNOWN
};

class Employee {
 protected:
    unsigned int id;
    std::string name;
    POSITION position;
    unsigned int worktime = 0;
    unsigned int payment = 0;

 public:
    Employee(unsigned int _id, std::string _name,
             POSITION _position);
    void setWorktime(unsigned int _worktime);
    unsigned int getId();
    std::string getName();
    POSITION getPosition();
    std::string stringPosition();
    unsigned int getWorktime();
    unsigned int getPayment();
    virtual void calc() = 0;
    virtual void printInfo() = 0;
};

POSITION positionByString(std::string _stringPosition);

#endif  // INCLUDE_EMPLOYEE_H_
