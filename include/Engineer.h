// Copyright 2021 kostinandrey

#ifndef INCLUDE_ENGINEER_H_
#define INCLUDE_ENGINEER_H_

#include <string>
#include "Personal.h"
#include "Interfaces.h"

class Engineer : public Personal, public Project_Budget {
 public:
    Engineer(int id, std::string name,
             int work_time, int salary, Positions position, Project *p);
    int calc_salary() override;
    int calc_budget_part() override;
    void print_info() override;
 protected:
    Project *project;
};
class Programmer : public Engineer {
 public:
    Programmer(int id, std::string name,
               int work_time, int salary, Positions position, Project *pr);
    int calc_salary() override;
    int calc_pro_additions(int bonus = 4) override;
};
class TeamLeader : public Programmer, public Heading {
 public:
    TeamLeader(int id, std::string name,
               int work_time, int salary, Positions position, Project *pr);
    int calc_salary() override;
    int calc_Heads() override;
};
class Tester : public Engineer {
 public:
    Tester(int id, std::string name,
           int work_time, int salary, Positions position, Project *pr);
    int calc_salary() override;
    int calc_pro_additions(int bonus = 4) override;
};

#endif  // INCLUDE_ENGINEER_H_
