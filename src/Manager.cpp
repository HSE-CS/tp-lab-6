// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 08.02.2021.
//

#include <Manager.h>
#include <iostream>

// class ProjectManager
ProjectManager::ProjectManager(id_type id, const std::string& name,
                               const Project& p)  : Employee(id, name),
                                                    _project(p)
  { _position = Position::ProjectManager; }

int ProjectManager::calc_heads() {
  return 10000 * 5;
}

void ProjectManager::calc() {
  _payment = calc_heads();
}

void ProjectManager::print_info() {
  std::cout <<  "Position: Project Manager\n"
                "ID: " << _id << '\n' <<
                "Name: " << _name << '\n' <<
                "Worktime: " << _worktime << '\n' <<
                "Payment: " << _payment << std::endl;
}
// end class ProjectManager


// class SeniorManager
SeniorManager::SeniorManager(id_type id, const std::string& name,
                             std::vector<Project> ps) :
                             ProjectManager(id, name, ps[0]),
                             _projects(ps)
  { _position = Position::SeniorManager; }

void SeniorManager::calc() {
  for (auto& p : _projects) {
    _payment += calc_heads();
  }
}

void SeniorManager::print_info() {
  std::cout <<  "Position: Senior Manager\n"
                "ID: " << _id << '\n' <<
                "Name: " << _name << '\n' <<
                "Worktime: " << _worktime << '\n' <<
                "Payment: " << _payment << std::endl;
}
// end class Senior manager
