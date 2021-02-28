// Copyright 2021 MalininDmitry

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

class Employee{
 protected:
    unsigned int id = 0;
    std::string name;
    std::string position;
    unsigned int worktime;
    unsigned int payment = 0;
    unsigned int salary;

 public:
    Employee(int id, std::string name, std::string position,
             unsigned int salary);
    Employee(int id, std::string name, std::string position);
    void setWorkTime(unsigned int worktime);
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    unsigned int getPayment();
    unsigned int getWorktime();
    unsigned int getSalary();
    std::string getPosition();
    std::string getName();
};

#endif  // INCLUDE_EMPLOYEE_H_

