// Copyright 2021 dmitrycvetkov2000
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

class WorkBaseTime {
 public:
    virtual ~WorkBaseTime() = default;

    virtual int calcBase() const = 0;
    virtual int calcBonus() const = 0;
};

class Heading {
 public:
    virtual ~Heading() = default;

    virtual int calcHeads() const = 0;
};

class ProjectBudget {
 public:
    virtual ~ProjectBudget() = default;

    virtual int calcBudget(float part) const = 0;
    virtual int calcProAdditions() const = 0;
};


#endif  // INCLUDE_INTERFACES_H_
