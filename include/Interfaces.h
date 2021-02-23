//// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_INTERFACES_H_
#define INCLUDE_INTERFACES_H_



class Heading {
public:
    virtual int calcHeads() = 0;
};

class ProjectBudget {
public:
    virtual int calcBudgetPart(double part, int budget) = 0;
    virtual int calcProAdditions() = 0;
};

class WorkBaseTime {
public:
    virtual int calcBase(int salary, int worktime) = 0;
    virtual int calcBonus() = 0;
};

class Project {
protected:
    int id;
    double budget;
public:
    Project(int id, double budget) {
        this->id = id;
        this->budget = budget;
    };
    ~Project() = default;;

    void setId(int id) { this->id = id; }
    void setBudget(double budget) { this->budget = budget; }

    int getId() { return this->id; }
    double getBudget() { return this->budget; }
};

#endif  //  INCLUDE_INTERFACES_H_
