// Copyright 2021 JGMax

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>

enum Position{
    PERSONAL,
    DRIVER,
    CLEANER,
    TESTER,
    ENGINEER,
    PROGRAMMER,
    TEAM_LEADER,
    PROJECT_MANAGER,
    SENIOR_MANAGER
};

class Employee {
 protected:
    int id;
    std::string fullName;
    int workTime;
    double payment;
    Position position;

 public:
    Employee(int id,
             std::string fullName,
             int workTime,
             Position position);
    void setWorkTime(int workTime);
    virtual void calc() = 0;
    virtual void printInfo() = 0;
    std::string getFullName() const;
    int getWorkTime() const;
    double getPayment() const;
    std::string getPosition() const;
    Position getPositionId() const;
    int getId() const;
};

class Project {
 private:
    int id;
    std::string title;
    double budget;
    int workers;
    int heads;
    bool isSucceeded;

 public:
    Project(const int id,
            const std::string title,
            const double budget) {
        this->id = id;
        this->title = title;
        this->budget = budget;
        isSucceeded = false;
        workers = 0;
        heads = 0;
    }

    std::string getTitle() const {
        return title;
    }

    int getId() const {
        return id;
    }

    double getBudget() const {
        return budget;
    }

    bool getStatus() const {
        return isSucceeded;
    }

    int getWorkers() const {
        return workers;
    }

    int getHeads() const {
        return heads;
    }

    void addWorker() {
        workers++;
    }

    void addHead() {
        heads++;
    }

    void closeProject() {
        isSucceeded = true;
    }
};

#endif  // INCLUDE_EMPLOYEE_H_
