//  Copyright Baklanov 2021
#ifndef INCLUDE_Engineer_H
#define INCLUDE_Engineer_H

#include <iostream>
#include <string>
#include "Factory.h"
#include "Personal.h"
#include "Interfaces.h"


class Engineer: public Personal, public ProjectBudget {
protected:
 Project *project;

public:
 void calc() override;
 int calcBudjetPart(float part, int budjet) override;
 Engineer(Project *project, int id_,
     std::string position_, std::string name_,
     int worktime_, int payment_, int salary_) :
  Personal(id_, position_, name_,
      worktime_,
      payment_, salary_),
     project(project) {};
 void printinfo() override;
 int calcBonus() override;
 int calcProAdditions() override;
 void setProject(Project* project) {
  this->project = project;
 };
 Project* getProject() {
  return this->project;
 };
};

class Tester : public Engineer {
public:
 int calcProAdditions() override;
 Tester(Project* project,
     int id_, std::string position_,
     std::string name_,
     int worktime_,
     int payment_,
     int salary_) :
  Engineer(project, id_,
      position_, name_,
      worktime_, payment_,
      salary_) {};
};

class Programmer : public Engineer {
public:
 Programmer(Project* project, int id_,
     std::string position_, std::string name_,
     int worktime_, int payment_,
     int salary_) :
  Engineer(project, id_, position_, name_,
      worktime_, payment_,
      salary_) {};
 int calcProAdditions() override;
};

class TeamLeader :public Programmer, public Heading {
public:
 TeamLeader(Project* project, int id_,
     std::string position_, std::string name_,
     int worktime_, int payment_,
     int salary_) :
  Programmer(project, id_,
      position_, name_,
      worktime_, payment_,
      salary_) {};
 int calcHeads() override;
 void calc() override;
};

#endif  //INCLUDE_Engineer_H
