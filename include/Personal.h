// Copyright 2021 Sozinov Kirill

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include "Employee.h"
#include "Interfaces.h"
#include <string>

class Personal : public Employee, public WorkBaseTime {
 protected:
     int salary;
 public:
     Personal(int _id, std::string _name, std::string _position, int
         _salary);
     int calcBase(int salary, int wtime) override;
     int calcBonus() override;
     void calc() override;
     void printInfo() override;
};

class Cleaner : public Personal {
 public:
     Cleaner(int _id, std::string _name, std::string _position, int
         _salary);
};

class Driver : public Personal {
 public:
    Driver(int _id, std::string _name, std::string _position, int
        _salary);
    int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_
