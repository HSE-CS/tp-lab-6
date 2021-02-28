// copyright 2021 Toliman

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>

#include "Interfaces.h"
#include "Personal.h"

class Engineer : public Project,
                 public Projectbudget,
                 public Personal {
 public:
    int calcBudgetPart(float projectPart, int budget);

    explicit Engineer(std::string name1,
        int worktime1, Project *project1,
        int position1,
        int salary1);

    virtual void calc(int hours);
};

class Programmer : public Engineer {
 public:
    explicit Programmer(std::string name1,
        int worktime1,
        Project *project1,
        int position1,
        int salary1);

    virtual int calcProAdditions(int relativePart);

    virtual void printInfo();

    virtual void calc(int hours);

    virtual void calcBonus(int times);

    virtual int getPayment();
};

class Tester : public Engineer {
 public:
    explicit Tester(std::string name1,
        int worktime1,
        Project *project1,
        int position1,
        int salary1);

    virtual int calcProAdditions(int relativePart);

    virtual void printInfo();

    virtual void calc(int hours);

    virtual void calcBonus(int times);
};


#endif  // INCLUDE_ENGINEER_H_
