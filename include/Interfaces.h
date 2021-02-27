// Copyright [2021] <Roman Balayan>

#pragma once

#include <string>

enum class Position {
    Programmer,
    Tester,
    TeamLeader,
    ProjectManager,
    SeniorManager,
    Cleaner,
    Driver
};

class Project {
 public:
    explicit Project(unsigned int id,
        unsigned int budget,
        std::string title)
        : id(id)
        , budget(budget)
        , title(title) {

    }
    unsigned int id;
    unsigned int budget;
    std::string title;
};

class IProjectBudget {
 protected:
    virtual int calcBudgetPart(float part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

class IWorkBaseTime {
 protected:
    virtual int calcBase(int salary, int wtime) = 0;
    virtual int calcBonus() = 0;
};

class IHeading {
 protected:
    virtual int calcHeads() = 0;
};
