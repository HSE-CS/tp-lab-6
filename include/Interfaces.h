// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class IWorkBaseTime {
 public:
    virtual void setSalary(double salary) = 0;
    virtual double getSalary() = 0;
    virtual double calcBase(double payment, int time) = 0;
    virtual double calcBonus() = 0;
};

class IProjectBudget {
 public:
    virtual double calcBudgetPart(double part, double budget) = 0;
    virtual double calcProAdditions() = 0;
};

class IHeading {
 public:
    virtual double calcHeads() = 0;
};

#endif  // INCLUDE_INTERFACES_H_
