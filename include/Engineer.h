//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include "Personal.h"
#include "Project.h"
#include "Project.h"
#include <string>

class Project;

class Engineer: public Personal, public ProjectBudget {
 protected:
    Project* linkToProject;
    unsigned additionalHours;
 public:
    Engineer(unsigned id, const std::string& name);
    Project* getProjectLink();
    void setProject(Project* link);
    unsigned calcBudgetPart() override;
    unsigned calcBonus() final;
    void calc() override;
};


#endif  //  INCLUDE_ENGINEER_H_
