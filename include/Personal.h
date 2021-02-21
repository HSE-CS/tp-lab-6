//
// Created by Valera on 20.02.2021.
//

#ifndef TP_LAB_6_PERSONAL_H
#define TP_LAB_6_PERSONAL_H

#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public IWorkBaseTime {
protected:
    int salary;
public:
    Personal(int id, const std::string &name, Position position, int salary);
    int calcBase(int salary, int wtime) override;
    int calcBonus() override;
};

class Cleaner : public Personal {
public:
    Cleaner(int id, const std::string &name, Position position, int salary);
    void calc() override;
};

class Driver : public Personal {
public:
    Driver(int id, const std::string &name, Position position, int salary);
    int calcBonus() override;
    void calc() override;
};

#endif //TP_LAB_6_PERSONAL_H
