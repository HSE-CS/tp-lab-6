// Copyright 2021 GN
#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_
#include <string>
#include <vector>
#include "Personal.h"

struct Project {
    std::string id;
    int budget;
};

class Engineer : public ProjectBudget, public Personal {
 private:
    Project* project;

 public:
    explicit Engineer(int id_, std::string name_,
        int salary_, Project* project_)
        : Personal(id_, name_, salary_) {
        project = project_;
    }
    virtual int calcBudgetPart(float part_, int budget_);
    virtual void calc();
    virtual void printInfo();
    Project* getProject();
};

class Programmer : public Engineer {
 private:
    bool bonus = 0;
 public:
    explicit Programmer(int id_, std::string name_,
        int salary_, Project* project_)
        : Engineer(id_, name_, salary_, project_) {
        spec = PROGRAMMER;
    }
    void addBonus() { bonus = 1; }
    virtual int calcProAdditions();
};

class Tester : public Engineer {
 private:
    int errors = 0;

 public:
    explicit Tester(int id_, std::string name_,
        int salary_, Project* project_)
        : Engineer(id_, name_, salary_, project_) {
        spec = TESTER;
    }
    void newError() {
        errors++;
    }
    int getErrorsNumber();
    virtual int calcProAdditions();
};

class TeamLeader : public Programmer, public Heading {
 private:
    int subordinates = 0;

 public:
    explicit TeamLeader(int id_, std::string name_,
        int salary_, Project* project_)
        : Programmer(id_, name_, salary_, project_) {
        spec = TEAMLEADER;
    }
    int getSubordinates();
    virtual int calcHeads();
    virtual void calc();
    virtual int calcProAdditions() { return 0; }
    void addSubordinate() {
        subordinates++;
    }
};

#endif  // INCLUDE_ENGINEER_H_
