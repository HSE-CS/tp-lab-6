// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_

#include <string>
#include <utility>

class WorkBaseTime {
 public:
    virtual int calcBase(int salary, int wtime) = 0;

    virtual int calcBonus() = 0;
};

class Heading {
 public:
    virtual int calcHeads() = 0;
};

class ProjectBudget {
 public:
    virtual int calcBudgetPart(float part, int budget) = 0;

    virtual int calcProAdditions() = 0;
};

class Project {
 protected:
    std::string id;
    int budget;
 public:
    Project(std::string id, int budget) {
        this->id = std::move(id);
        this->budget = budget;
    }

    void setId(std::string id) {
        this->id = std::move(id);
    }

    void setBudget(int budget) {
        this->budget = budget;
    }

    std::string getId() {
        return this->id;
    }

    int getBudget() {
        return this->budget;
    }
};


#endif  // INCLUDE_INTERFACES_H_
