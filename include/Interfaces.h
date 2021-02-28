//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class ProjectBudget {
 protected:
    virtual unsigned calcBudgetPart() = 0;
    virtual unsigned calcProAdditions() = 0;
};

class Heading {
 protected:
    virtual unsigned calcHeads() = 0;
};

class WorkBaseTime{
    virtual unsigned calcBase(unsigned salary, unsigned workTime) = 0;
    virtual unsigned calcBonus() = 0;
};

#endif  //  INCLUDE_INTERFACES_H_
