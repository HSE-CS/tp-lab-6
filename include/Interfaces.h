// Copyright 2021 valvarl

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class IWorkBaseTime {
    virtual int calcBase(int salary, int wtime) = 0;
    virtual int calcBonus() = 0;
};

class IProjectBudget {
    virtual int calcBudgetPart(float part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

class IHeading {
    virtual int calcHeads() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
