//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_

#include "Employee.h"

class Project {
 private:
    unsigned projectID;
    unsigned projectBudget;
    unsigned numberOfMembers;
 public:
    Project(unsigned projectID, unsigned projectBudget);
    unsigned getProjectID();
    unsigned getNumberOfMembers();
    unsigned getProjectBudget();
    void printInfo();
    void addMember();
};

#endif  //  INCLUDE_PROJECT_H_
