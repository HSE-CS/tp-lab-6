// copyright 2021 Toliman

#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_

#include <string>

#include "Employee.h"


class Personal : public WorkBaseTime,
                 public Employee {
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
    explicit Driver(std::string name1,
        int worktime1,
        Project *project1,
        int position1,
        int salary1);

    virtual void calcBonus(int nightHours);

    void calc(int hours);

    virtual void printInfo();

    int getPayment();
};

class Cleaner : public Personal {
 public:
    void calc(int hours);

    virtual void printInfo();

    virtual void calcBonus(int floors);

    int getPayment();

    explicit Cleaner(std::string name1,
        int worktime1,
        Project *project1,
        int position1,
        int salary1);
};


#endif  // INCLUDE_PERSONAL_H_
