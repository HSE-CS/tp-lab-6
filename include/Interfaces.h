//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include <string>
#include <vector>

class WorkBaseTime {
 public:
    virtual unsigned calcBase(unsigned salary, unsigned worktime) = 0;
    virtual unsigned calcBonus() = 0;
};

class ProjectBudget {
 public:
    virtual unsigned calcBudgetPart(float part, unsigned budget) = 0;
    virtual unsigned calcProAdditions() = 0;
};

class Heading {
 public:
    virtual unsigned calcHeads() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
