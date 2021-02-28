//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_

#include <cstdlib>

class Project {
 protected:
    int projectID;
    int projectBudget;
    int numberOfMembers;
 public:
    Project(int, int);
    int getNumberOfMembers();
    int getProjectBudget();
};

#endif  //  INCLUDE_PROJECT_H_
