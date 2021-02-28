// Copyright 2021 Bogomazov
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include "../include/Employee.h"
#include "../include/Personal.h"
#include "../include/Factory.h"
#include "../include/Engineer.h"
#include "../include/Manager.h"


enum Position { DRIVER = 1, CLEANER, SECURITY, ENGINEER, PROGRAMMER,
    TESTER, TEAMLEADER, MANAGER, SENIORMANAGER, PROJECTMANAGER };

class WorkBaseTime {
 public:
    virtual int calcBase(int salary, int wtime) = 0;
    virtual int calcBonus() = 0;
};

class Heading {
    virtual int calcHeads() = 0;
};

class ProjectBudget {
    virtual int calcBudgetPart(float part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

#endif  //  INCLUDE_INTERFACES_H_

