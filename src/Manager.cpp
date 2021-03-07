// Copyright 2021 Tatsenko Ilya
#include "Manager.h"
#include <iostream>
#include<vector>

std::string converse_3(Position pos) {
  if (pos == PROGRAMMER)
    return "Programmer";
  else if (pos == TESTER)
    return "Tester";
  else if (pos == DRIVER)
    return "Driver";
  else if (pos == CLEANER)
    return "Cleaner";
  else if (pos == ENGINEER)
    return "Engineer";
  else if (pos == SENIOR_MANAGER)
    return "SeniorManager";
  else if (pos == PROJECT_MANAGER)
    return "ProjectManager";
  else if (pos == TEAM_LEADER)
    return "TeamLeader";
}

ProjectManager::ProjectManager(int id, std::string fi, Position position,
                               std::vector<Project *> project, std::string name)
    : name(name), Employee(id, fi, position) {
  projects = project;
}

Project *ProjectManager::get_project() {
  for (auto &proj : this->projects) {
    if (proj->get_name() == this->name) return proj;
  }
}
int ProjectManager::calc_heads() {
  return this->get_project()->get_number_of_emp() * 1000;
}
void ProjectManager::calc() {
  this->set_payment((this->get_project()->get_budjet() /
                     this->get_project()->get_number_of_emp()) +
                    calc_heads());
}

SeniorManager::SeniorManager(int id, std::string fi, Position position,
                             std::vector<Project *> projects)
    : ProjectManager(id, fi, position, projects) {
  this->projects = projects;
}

void SeniorManager::calc() {
  int sum = 0;
  for (auto &project : projects) {
    sum += (project->get_budjet() / project->get_number_of_emp()) * 0.5 +
           (project->get_number_of_emp() * 1000);
  }

  this->set_payment(sum);
}

void ProjectManager::print_info() {
  std::cout << this->get_id() << "  "
            << "name: " << this->get_name() << std::endl
            << "\t"
            << "position " << converse_3(this->get_position()) << std::endl;
  std::cout << "\t"
            << "project: " << this->get_project()->get_name() << std::endl;
  std::cout << "\t"
            << "payment: " << this->get_payment();
  std::cout << std::endl;
}

void SeniorManager::print_info() {
  std::cout << this->get_id() << "  "
            << "name: " << this->get_name() << std::endl
            << "\t"
            << "position " << converse_3(this->get_position()) << std::endl;
  std::cout << "\t"
            << "projects: "
            << " ";
  for (auto &proj : projects) {
    std::cout << proj->get_name() << ", ";
  }
  std::cout << std::endl;
  std::cout << "\t"
            //<< "WorkTime: " << this->get_work_time() << " "
            << "payment: " << this->get_payment();
  std::cout << std::endl;
}
