//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"
#include "Project.h"
#include "Project.h"

class Project;

class Engineer: public Personal, public ProjectBudget {
 protected:
    Project* linkToProject;
 public:
    Engineer(unsigned id, const std::string& name);
    void setProject(Project* link);
    unsigned calcBudgetPart() override;
    void calc() override;
};


#endif  //  INCLUDE_ENGINEER_H_
