// Copyright 2021 TimurZaytsev
//

#include "Manager.h"
#include <iostream>



// class ProjectManager
ProjectManager::ProjectManager(id_type id, const std::string& name,
    const Project& p) : Employee(id, name),
    _project(p) {
    _position = Position::ProjectManager;
}

int ProjectManager::calc_heads() {
    return 10000 * 5;
}

void ProjectManager::calc() {
    _payment = calc_heads();
}

void ProjectManager::print_info() {
    std::cout << "Position: Project Manager\n"
        "ID: " << _id << '\n' <<
        "Name: " << _nameof << '\n' <<
        "Worktime: " << _timeofwork << '\n' <<
        "Payment: " << _payment << std::endl;
}


SeniorManager::SeniorManager(id_type id, const std::string& name,
    std::vector<Project> ps) :
    ProjectManager(id, name, ps[0]),
    _projects(ps) {
    _position = Position::SeniorManager;
}

void SeniorManager::calc() {
    for (auto& p : _projects) {
        _payment += calc_heads();
    }
}

void SeniorManager::print_info() {
    std::cout << "Position: Senior Manager\n"
        "ID: " << _id << '\n' <<
        "Name: " << _nameof << '\n' <<
        "Worktime: " << _timeofwork << '\n' <<
        "Payment: " << _payment << std::endl;
}
