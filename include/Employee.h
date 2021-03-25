// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>

enum Positions {
    EMPLOYEE,
    PERSONAL,
    ENGINEER,
    CLEANER,
    DRIVER,
    PROGRAMMER,
    TESTER,
    TEAM_LEADER,
    PROJECT_MANAGER,
    SENIOR_MANAGER };

class Employee {
 protected:
    std::string name;
    Positions position;
    int workTime;
    int payment;
    int id;

 public:
    Employee(int id, std::string name,
             int workTime, Positions position);

    void setWorkTime(int wt);
    virtual int calc() = 0;
    virtual void printInfo() = 0;

    std::vector<std::string> positions = { "EMPLOYEE",
                                "PERSONAL",
                                "ENGINEER",
                                "CLEANER",
                                "DRIVER",
                                "PROGRAMMER",
                                "TESTER",
                                "TEAM_LEADER",
                                "PROJECT_MANAGER",
                                "SENIOR_MANAGER" };
};

class Project {
 private:
    std::string name;
     int budget;
     int countWorkers;
 public:
    Project( int id, std::string name,  int budget,  int countWorkers);
    std::string getName();
     int getBudget() const;
     int getCountWorkers() const;

     int id;
};

#endif  // INCLUDE_EMPLOYEE_H_
