// Copyright 2021 Islam Osmanov

#ifndef TP_LAB_6_INTERFACES_H
#define TP_LAB_6_INTERFACES_H

class ProjectBudget {
 public:
    virtual int calcBudgetPart(double piece, int budget) = 0;
    virtual int calcProAdditions(int bonus) = 0;

};

class WorkBaseTime {
 public:
    virtual int calcBonus(int bonus) = 0;
    virtual int calcBase(int sal, int wtime) = 0;
};

class Project {
private:
    int project_id;
    int budget;
    int workers_num;
public:
    Project(int proj_id, int bud) : project_id(proj_id),
                                    budget(bud){}
    int getBudget() {
        return budget;
    };

    int getId(){
        return project_id;
    };

    void setId(int id) {
        this->project_id = id;
    }

    void setBudget(int money) {
        this->budget = money;
    }

    int getWorkersNum() {
        return workers_num;
    }

    void addWorkers(int workers) {
        workers_num = workers;
    }
};

class Heading {
 public:
    virtual int calcHeads() = 0;
};

#endif //TP_LAB_6_INTERFACES_H
