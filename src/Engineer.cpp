// Copyright 2021 kostinandrey
#include "Engineer.h"

#include <utility>

Engineer::Engineer(int id, std::string name,
                   int work_time, int salary, Positions position, Project *p)
        : Personal(id, std::move(name), work_time, salary, position) {
    this->project = p;
}
int Engineer::calc_budget_part() {
    if (project) {
        return (*project).get_budget() / project->get_num_of_employees();
    } else {
        return 0;
    }
}
int Engineer::calc_salary() {
    return this->payment = calc_budget_part() + calc_base_salary(salary, work_time);
}
void Engineer::print_info() {
    std::cout << enum_print[this->position] << std::endl;
    std::cout << this->name << std::endl;
    std::cout << "Work time = " << this->work_time << std::endl;
    std::cout << "Payment = " << this->payment << std::endl;
}






Programmer::Programmer(int id, std::string name,
                       int work_time, int salary, Positions position, Project *p)
        : Engineer(id, std::move(name), work_time, salary, position, p) {
}
int Programmer::calc_salary() {
    return this->payment = calc_base_salary(salary, work_time) + calc_budget_part() +
            calc_pro_additions();
}
int Programmer::calc_pro_additions(int bonus) {
    return bonus * this->salary;
}

Tester::Tester(int id, std::string name,
               int workTime, int salary, Positions position, Project *pr)
        : Engineer(id, std::move(name), workTime, salary, position, pr) {
}
int Tester::calc_salary() {
    return this->payment =  calc_base_salary(salary, work_time)
            + calc_pro_additions() + calc_budget_part();
}
int Tester::calc_pro_additions(int bonus) {
    return bonus * this->salary;
}

TeamLeader::TeamLeader(int id, std::string name,
                       int work_time, int salary,
                       Positions position, Project *pr)
        : Programmer(id, std::move(name), work_time, salary, position, pr) {}

int TeamLeader::calc_Heads() {
    if (project) {
        return project->get_num_of_employees();
    } else {
        return 0;
    }
}
int TeamLeader::calc_salary() {
    return this->payment = calc_base_salary(salary, work_time)
                           + calc_bonus_salary(calc_Heads()) + calc_budget_part();
}
