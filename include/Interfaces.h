// Copyright 2021 by Fatin Maxim
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include <string>

class Project {
 public:
    std::string id;
    int budget;
};

class WorkBaseTime {
 public:
    virtual int calcBase(int salary, int wtime) = 0;
    virtual int calcBonus() = 0;
};

class ProjectBudget {
 public:
    virtual int calcBudgetPart(double part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

class Heading {
 public:
    virtual int calcHeads() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
