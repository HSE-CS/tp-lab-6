// Copyright 2021 Sozinov Kirill

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
    virtual int calcBase(int salary, int wtime) = 0;
    virtual int calcBonus() = 0;
};

class ProjectBudget {
    virtual float calcBudgetPart(float part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

class Heading {
    virtual int calcHeads() = 0;
};
#endif  // INCLUDE_INTERFACES_H_