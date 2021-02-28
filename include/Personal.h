//
// Created by Данил on 28.02.2021.
//

#ifndef TP_LAB_6_PERSONAL_H
#define TP_LAB_6_PERSONAL_H

#include "Employee.h"
// #include "Interfaces.h"


class Personal : public WorkBaseTime, public Employee {
protected:
    int salary;
public:
    explicit Personal(std::string name1,
        int worktime1,
        Project *project1,
        int position1,
        int salary1);

    virtual int calcBase(int salary_, int wtime);

    virtual void calcBonus(int times) = 0;
};


class Driver : public Personal {
public:
    // Driver() : Personal(std::__cxx11::string(), 0, nullptr, 0, std::__cxx11::string(), 0, nullptr, 0, 0) {}

    void calcBonus(int nightHours);

    void calc(int hours);

    virtual void printInfo();
};

class Cleaner : public Personal {
    // Cleaner() : Personal(std::__cxx11::string(), 0, nullptr, 0, std::__cxx11::string(), 0, nullptr, 0, 0) {}

    void calc(int hours);

    virtual void printInfo();
};


#endif //TP_LAB_6_PERSONAL_H
