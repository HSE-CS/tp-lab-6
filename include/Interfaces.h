// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_
#include <iostream>
#include <string>
#include <vector>

class WorkBaseTime {
 public:
    virtual int calcBase(int salary, int wtime) = 0;
    virtual int calcBonus() = 0;
};

class ProjectBudget {
 public:
    virtual int calcBudgetPart(float part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

class Heading {
 public:
    virtual int calcHeads() = 0;
};
#endif  // INCLUDE_INTERFACES_H_
