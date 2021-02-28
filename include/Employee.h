// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include <string>

enum Position {
    PERSONAL,
    ENGINEER,
    CLEANER,
    DRIVER,
    PROGRAMMER,
    TESTER,
    TEAMLEADER,
    PROJECTMANAGER,
    SENIORMANAGER
};

class Employee {
 public:
    void setWorktime(int worktime);
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    int getId();
    std::string getName();
    Position getPosition();
    std::string positionToString();
    int getWorktime();
    int getPayment();
    void setPayment(int payment);
    Employee(int id, std::string name, Position position, int worktime);

 protected:
     int id;
     std::string name;
     Position position;
     int worktime;
     int payment;
};

#endif  // INCLUDE_EMPLOYEE_H_