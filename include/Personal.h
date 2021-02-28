// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public WorkBaseTime {
 public:
     void printInfo() override;
     int calcBase(int salary, int wtime) override;
     Personal(int id, std::string name, Position position,
         int worktime, int salary);
 protected:
    int salary;
};

class Driver : public Personal {
 public:
    Driver(int id, std::string name, Position position,
        int worktime, int salary);
    void calc() override;
    int calcBonus() override;
};

class Cleaner : public Personal {
 public:
    Cleaner(int id, std::string name, Position position,
        int worktime, int salary);
    void calc() override;
    int calcBonus() override;
};

#endif  // INCLUDE_PERSONAL_H_