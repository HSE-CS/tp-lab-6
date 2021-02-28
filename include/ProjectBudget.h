// Copyright 2021
#ifndef INCLUDE_PROJECTBUDGET_H_
#define INCLUDE_PROJECTBUDGET_H_

class ProjectBudget {
    virtual double calcBudgetPart(double part, double budget) = 0;
    virtual double calcProAdditions() = 0;
};
#endif  // INCLUDE_PROJECTBUDGET_H_
