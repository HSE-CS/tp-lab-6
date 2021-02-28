// Copyright 2021 TimurZaytsev
//

#include <Engineer.h>
#include <iostream>

Engineer::Engineer(id_type id, const std::string& name,
    unsigned int salary,
    const Project& p) :

    Personal(id, name, salary),
    _project(p)
{}

int Engineer::calc_budget_part(float part, int budget) {
    return budget * part;
}

void Engineer::calc() {
    _payment = calc_base(_salary, _timeofwork)
        + calc_budget_part(0.1, _project._budget);
}


Tester::Tester(id_type id,
    const std::string& name,
    unsigned int salary,
    const Project& p) : Engineer(id, name, salary, p){
    _position = Position::Tester;
}

int Tester::calc_pro_additions() {
    return _timeofwork * (_salary / 100);
}

int Tester::calc_bonus() {
    return 0;
}

void Tester::print_info() {
    std::cout << "Position: Tester\n"
        "ID: " << _id << '\n' <<
        "Name: " << _nameof << '\n' <<
        "Worktime: " << _timeofwork << '\n' <<
        "Payment: " << _payment << std::endl;
}


Programmer::Programmer(id_type id,
    const std::string& name,
    unsigned int salary,
    const Project& p) : Engineer(id, name, salary, p){
    _position = Position::Programmer;
}

int Programmer::calc_pro_additions() {
    return _salary * 10 / _timeofwork;
}

int Programmer::calc_bonus() {
    return 0;
}

void Programmer::print_info() {
    std::cout << "Position: Programmer\n"
        "ID: " << _id << '\n' <<
        "Name: " << _nameof << '\n' <<
        "Worktime: " << _timeofwork << '\n' <<
        "Payment: " << _payment << std::endl;
}


// class TeamLeader
TeamLeader::TeamLeader(id_type id,
    const std::string& name,
    unsigned int salary,
    const Project& p) : Programmer(id, name, salary, p){
    _position = Position::TeamLeader;
}

int TeamLeader::calc_heads() {
    return _salary * 5;
}

void TeamLeader::calc() {
    _payment = calc_heads()
        + calc_budget_part(0.3, _project._budget)
        + calc_base(_salary, _timeofwork);
}

void TeamLeader::print_info() {
    Programmer::print_info();
}
