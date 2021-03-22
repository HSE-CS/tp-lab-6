// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>
#include "Employee.h"
#include <include/interfaces.h>


class Personal : public Employee, public IWorkBaseTime {
 protected:
    unsigned int salaryPerHour;

    int calcBase(int salary, int wtime) override;

    int calcBonus() override = 0;

 public:
    Personal(unsigned int id, std::string name, Position position,
             unsigned int salaryPerHour);

    void calc() override = 0;

    void printInfo() override;
};

class Driver : public Personal {
 private:
    int nightHours = 0;

    int calcBonus() override;

 public:
    Driver(unsigned int id, std::string name, Position position,
           unsigned int salaryPerHour);

    void setNightHours(int nightHours);

    void calc() override;

    void printInfo() override;
};

class Cleaner : public Personal {
 private:
    int calcBonus() override;

 public:
    Cleaner(unsigned int id, std::string name,
            Position position, unsigned int salaryPerHour);

    void calc() override;
};

#endif  // INCLUDE_PERSONAL_H_
