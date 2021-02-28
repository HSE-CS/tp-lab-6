// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 public:
    virtual unsigned int calcBase(unsigned int _salary,
                                  unsigned int _worktime) = 0;
    virtual unsigned int calcBonus() = 0;
};

class ProjectBudget {
 public:
    virtual unsigned int calcBudgetPart(float _part,
                                        unsigned int _budget) = 0;
    virtual unsigned int calcProAdditions() = 0;
};

class Heading {
 public:
    virtual unsigned int calcHeads() = 0;
};

#endif  //  INCLUDE_INTERFACES_H_
