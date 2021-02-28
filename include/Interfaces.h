// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class ProjectBudget {
 public:
    virtual int calcBudgetPart(float part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

class WorkBaseTime {
 public:
    virtual int calcBase(int salary, int worktime) = 0;
    virtual int calcBonus() = 0;
};

class Heading {
 public:
    virtual int calcHeads() = 0;
};

#endif   // INCLUDE_INTERFACES_H_
