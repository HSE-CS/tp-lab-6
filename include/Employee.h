// Copyright 2021 soda
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <vector>
#include <string>
//#include "Interfaces.h"


class Employee {
 private:
     size_t id;
     std::string name;
     size_t worktime;
     size_t payment;
     size_t position;

 public:
     Employee(size_t id, std::string name, size_t worktime,
         size_t position, size_t payment) :
         id(id), name(name), worktime(worktime),
         position(position), payment(payment) {}

     //void setWorkTime(size_t);
     //void setPayment(size_t);

     size_t getWorktime();
     size_t getPayment();
     size_t getId();
     std::string& getName();
     size_t getPositionID();
     std::string getPosition();
     //virtual void calc() = 0;
     //virtual void printInfo() = 0;
};

#endif  // INCLUDE_EMPLOYEE_H_
