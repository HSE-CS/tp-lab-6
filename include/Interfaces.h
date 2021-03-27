// Copyright 2021 asma
#pragma once
#ifndef INTERFACES_H_
#define INTERFACES_H_


class WorkBaseTime {
 public:
    virtual int CalcBase(int, int) const = 0;
    virtual int CalcBonus() const = 0;
};

class ProjectBudjet {
 public:
    virtual int CalcBudgetPart() const = 0;
    virtual int CalcProAdditions() const = 0;
};

class Heading {
 public:
    virtual int CalcHeads() const = 0;
};

#endif  // INTERFACES_H_
