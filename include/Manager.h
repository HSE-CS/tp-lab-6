// Copyright 2021 TimurZaytsev
//

#ifndef INCLUDE_MANAGER_H_
#define INCLUDE_MANAGER_H_

#include <vector>
#include <string>
#include "Interfaces.h"
#include "Employee.h"


class ProjectManager : public Employee, public Heading {
 public:
ProjectManager(id_type id, const std::string& name, const Project& p);
~ProjectManager() override = default;
void calc() override;
void print_info() override;
int calc_heads() override;

 private:
Project _project;
};


class SeniorManager final : public ProjectManager {
 public:
SeniorManager(id_type id, const std::string& name, std::vector<Project> ps);

void calc() override;
void print_info() override;

 private:
std::vector<Project> _projects;
};

#endif  // INCLUDE_MANAGER_H_
