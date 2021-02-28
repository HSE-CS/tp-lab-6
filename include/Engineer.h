//
// Created by Данил on 28.02.2021.
//

#ifndef TP_LAB_6_ENGINEER_H
#define TP_LAB_6_ENGINEER_H

#include "Interfaces.h"
#include "Personal.h"

class Engineer : public Project,
                 public Projectbudget,
                 public Personal {
public:
    int calcBudgetPart(float projectPart, int budget);

    explicit Engineer(std::string name1, int worktime1, Project *project1,
                      int position1, int salary1);


    virtual void calc(int hours);
};

class Programmer : public Engineer {
public:
    explicit Programmer(std::string name1, int worktime1, Project *project1, int position1, int salary1);

    virtual int calcProAdditions(int relativePart);

    virtual void printInfo();

    virtual void calc(int hours);

    virtual void calcBonus(int times);
};

class Tester : public Engineer {
public:
    explicit Tester(std::string name1, int worktime1, Project *project1, int position1, int salary1);

    virtual int calcProAdditions(int relativePart);

    virtual void printInfo();

    virtual void calc(int hours);

    virtual void calcBonus(int times);
};


#endif //TP_LAB_6_ENGINEER_H
