// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_INTERFACES_H
#define INCLUDE_INTERFACES_H


class WorkBaseTime{
public:
    virtual ~WorkBaseTime() = default;
    virtual int calcBase() = 0;
    virtual int calcBonus(int bonus) = 0;
};


class ProjectBudget{
public:
    virtual ~ProjectBudget() = default;
    virtual int calcBudgetPart() = 0;
    virtual int calcProAdditions() = 0;
};

class Heading{
public:
    virtual ~Heading() = default;
    virtual  int calcHeads() = 0;
};


#endif // INCLUDE_INTERFACES_H
