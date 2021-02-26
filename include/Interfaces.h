// Copyright 2021 JGMax

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 protected:
    virtual int calcBase() = 0;
    virtual int calcBonus() = 0;
};

class ProjectBudget {
 protected:
    virtual int calcBudgetPart() = 0;
    virtual int calcProAdditions() = 0;
};

class Heading {
 protected:
    virtual int calcHeads() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
