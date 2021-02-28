#ifndef TP_LAB_6_INTERFACES_H
#define TP_LAB_6_INTERFACES_H

#include <string>
#include <vector>

class Employee;

class WorkBaseTime {
public:
    virtual int calcBase(int salary, int wtime) = 0;

    virtual void calcBonus(int times) = 0;
};

class Projectbudget {
public:
    virtual int calcBudgetPart(float part, int budget) = 0;

    virtual int calcProAdditions(int powerOfExtraWork) = 0;
};

class Heading {
    virtual int calcHeads() = 0;
};

static int pid = -1;

class Project {
private:
    int pid;
    int budget;
    int workersCount;
    std::string projectName;
public:
//    explicit Project(int budget1, std::string projectName1) {
//        this->projectName = projectName1;
//        this->workersCount = 0;
//        this->pid = this->getPid();
//        this->budget = budget1;
//    }

    int getPid() {
        ++pid;
        return pid;
    }

    void setPid() {
        this->pid = getPid();
    }

    void setMemberCountToZero() {
        this->workersCount = 0;
    }

    void setBudget(int budget1) {
        this->budget = budget1;
    }

    void setProjectName(std::string pName) {
        this->projectName = pName;
    }

    void addMemberCount() {
        this->workersCount++;
    }

    void subMemberCount() {
        this->workersCount--;
    }

    int getWorkersCount() {
        return this->workersCount;
    };

    std::string getProjectName() {
        return this->projectName;
    };
};

#endif // TP_LAB_6_INTERFACES_H
