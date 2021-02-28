// Copyright 2021 kostinandrey
#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_
#include <string>
#include <vector>
#include "Employee.h"
#include "Interfaces.h"
class Project_Manager : public Employee, public Heading, public Project_Budget {
 public:
    Project_Manager(int id, std::string name,
                    int work_time, Positions position, Project *project);
    void print_info() override;
    int calc_budget_part() override;
    int calc_pro_additions(int bonus = 50) override;
    int calc_Heads() override;
    int calc_salary() override;
 protected:
    Project *project = nullptr;

};
class Senior_Manager : public Project_Manager {
 private:
    std::vector<Project *> projects;
 public:
    Senior_Manager(int id, const std::string &name,
                  int work_time, Positions position, std::vector<Project *> pr);
    int calc_salary() override;
};

#endif  // INCLUDE_MANAGER_H_
