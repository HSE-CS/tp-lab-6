// Copyright 2021 Ziganshin Nikita

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 public:
    virtual unsigned int calcBase() = 0;
    virtual unsigned int calcBonus() = 0;
};

class ProjectBudget {
    virtual unsigned int calcBudgetPart(float part) = 0;
    virtual unsigned int calcProAdditions() = 0;
};

class Heading {
    virtual unsigned int calcHeads() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
