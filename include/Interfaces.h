// Copyright 2021 soda
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include "Employee.h"
#include "Personal.h"
#include "Factory.h"
#include "Engineer.h"

enum Position { DRIVER = 1, CLEANER, SECURITY, PROGRAMMER, TESTER, TEAMLEADER };

class WorkBaseTime {
public:
    size_t virtual calcBase() = 0;
    size_t virtual calcBonus() = 0;
};

class Heading {
    size_t virtual calcHeads() = 0;
};

class ProjectBudger {
    size_t virtual calcBudgetPart(float part, int budget) = 0;
    size_t virtual calcProAdditions() = 0;
};

#endif  // INCLUDE_INTERFACES_H_