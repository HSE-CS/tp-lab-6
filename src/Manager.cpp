// Copyright 2021 kostinandrey
#include <iostream>
#include <utility>
#include "Manager.h"
Project_Manager::Project_Manager(int id, std::string name,
                               int work_time, Positions position,
                               Project *project)
        : Employee(id, std::move(name), work_time, position) {
    this->project = project;
}
void Project_Manager::print_info() {
    std::cout << enum_print[this->position] << std::endl;
    std::cout << this->name << std::endl;
    std::cout << "Work time = " << this->work_time << std::endl;
    std::cout << "Payment = " << this->payment << std::endl;
}

int Project_Manager::calc_Heads() {
    return this->project->get_num_of_employees();
}

int Project_Manager::calc_budget_part() {
    if (project) {
        return (*project).get_budget() / project->get_num_of_employees();
    } else {
        return 0;
    }
}

int Project_Manager::calc_salary() {
    return this->payment = calc_pro_additions()+
                           calc_Heads() * calc_budget_part();
}

int Project_Manager::calc_pro_additions(int bonus) {
    return bonus;
}

Senior_Manager::Senior_Manager(int id, const std::string &name,
                               int work_time, Positions position,
                               std::vector<Project *> p)
        : Project_Manager(id, name, work_time, position, p[0]) {
}
int Senior_Manager::calc_salary(){
    int summa = 0;
    for (auto project_ : projects) {
        summa += (1.0 / project_->get_num_of_employees()) *
               project_->get_budget();
    }
    return this->payment = summa;
}
