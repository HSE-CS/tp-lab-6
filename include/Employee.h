// copyright 2021 Toliman

#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <iostream>

#include "Interfaces.h"

enum Position {
    CLEANER,  // 0
    DRIVER,  // 1
    PROGRAMMER,  // 2
    TESTER,  // 3
    PROJECTMANAGER,  // 4
    SENIORMANAGER,  // 5
    TEAMLEADER,  // 6
};

const char* positionToString[]{
    "Cleaner",
    "Driver",
    "Programmer",
    "Tester",
    "Project Manager",
    "Senior Manager",
    "Team Leader",
};

static int id__ = -1;

class Employee {
 protected:
    int id;
    std::string name;
    int worktime;
    int payment;
    Project *project;
    int position;

 public:
    int getId() {
        ++id__;
        return id__;
    }

    explicit Employee(std::string name1,
                      int worktime1,
                      Project *project1,
                      int position1);

    void setWorkTime(int hours);

    virtual void calc(int hours) = 0;

    virtual void printInfo() = 0;

    Project *getProject();

    int getPosition();

    void setProject(Project *project1) {
        this->project = project1;
    }

    void toStringForm(std::string name1,
        int id1,
        int profession,
        Project *project1) {
        std::string result = "";
        result += std::to_string(id1) + " - " + name1 + " // prof: " +
                  positionToString[profession] + " (project: " +
                  project1->getProjectName() + ")";
        std::cout << result << "\n";
    }
};

#endif  // INCLUDE_EMPLOYEE_H_
