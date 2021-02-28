//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include <vector>
#include "Personal.h"

class Engineer : public Personal, public ProjectBudget {
 protected:
  Project* project;
  float projectPart = 0;
 public:
  Engineer(int id, std::string name, Position position,
           unsigned worktime, unsigned salary, Project* project)
  :Personal(id, name, position, worktime, salary) {
    this->project = project;
  }
  Project* getProject();
  void setProject(Project* project);
  void setProjectPart(float part);
  unsigned calcBudgetPart(float part, unsigned budget) override;
  unsigned calcProAdditions() override;
  unsigned calc() override;
};

class Programmer : public Engineer {
 protected:
  unsigned aheadCounter = 0;
 public:
  Programmer(int id, std::string name, unsigned worktime,
             unsigned salary, Project* project)
  :Engineer(id, name, Position::Programmer, worktime, salary, project) {
    this->project = project;
  }
  unsigned calcProAdditions() override;
  void setAheadCounter(unsigned newCounter);
};

class Tester : public Engineer {
 protected:
  unsigned bugsCounter = 0;
 public:
  Tester(int id, std::string name, unsigned worktime,
         unsigned salary, Project* project)
  :Engineer(id, name, Position::Tester, worktime, salary, project) {
    this->project = project;
  }
  unsigned calcProAdditions() override;
  void setBugsCounter(unsigned newCounter);
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, std::string name, unsigned worktime,
             unsigned salary, Project* project)
  :Programmer(id, name, worktime, salary, project) {
//    this->project = project;
    this->position = Position::TeamLeader;
  }
  unsigned calc() override;
  unsigned calcHeads() override;
};

#endif  // INCLUDE_ENGINEER_H_
