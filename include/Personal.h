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
    int calcBase(int salary, int wtime) override;
    int calcBonus() override;
};

class Cleaner : public Personal {
public:
    void calc() override;
};

class Driver : public Personal {
public:
    int calcBonus() override;
    void calc() override;
};

#endif //TP_LAB_6_PERSONAL_H
