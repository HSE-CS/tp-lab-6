// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_PERSONAL_H
#define INCLUDE_PERSONAL_H


#include <string>
#include "Employee.h"
#include "Interfaces.h"

class Personal: public Employee, public WorkBaseTime {
protected:
    int salary;
    int calcBase() override;
    int calcBonus(int bonus = 0) override;
public:
    Personal( int id, std::string name,
              int workTime, int salary, Positions position);
    void printInfo() override;
    int calc() override;
};


class Driver: public Personal {
private:
    int calcBonus(int bonus = 2) override;
public:
    Driver( int id, const std::string& name,
            int workTime, int salary, Positions position);
    int calc() override;
};

class Cleaner: public Personal {
private:
    int calcBonus(int bonus = 1);

public:
    Cleaner( int id, const std::string& name,
             int workTime, int salary, Positions position);
    int calc() override;
};


#endif // INCLUDE_PERSONAL_H
