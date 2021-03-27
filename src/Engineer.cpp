// Copyright 2021 asma
#include "Engineer.h"
#include <string>

Engineer::Engineer(int _id, std::string _name, Position _position,
    int _salary, Project* _project, double _part) {
    id = _id;
    name = _name;
    position = _position;
    salary = _salary;
    project = _project;
    part = _part;
    worktime = 0;
    payment = 0;
}

Programmer::Programmer(int _id, std::string _name, Position _position,
    int _salary, Project* _project, double _part) {
    id = _id;
    name = _name;
    position = _position;
    salary = _salary;
    project = _project;
    part = _part;
    worktime = 0;
    payment = 0;
}

Tester::Tester(int _id, std::string _name, Position _position, int _salary,
    Project* _project, double _part) {
    id = _id;
    name = _name;
    position = _position;
    salary = _salary;
    project = _project;
    part = _part;
    worktime = 0;
    payment = 0;
}

TeamLeader::TeamLeader(int _id, std::string _name, Position _position,
    int _salary, Project* _project, double _part) {
    id = _id;
    name = _name;
    position = _position;
    salary = _salary;
    project = _project;
    part = _part;
    worktime = 0;
    payment = 0;
}

int Engineer::CalcBudgetPart() const {
    return part * project->budget;
}

int Engineer::CalcProAdditions() const {
    return 0;
}

void Engineer::Calc() {
    payment = CalcBase(salary, worktime) + CalcBudgetPart();
}

void Programmer::Calc() {
    payment = 1.2 * part * salary + salary;
}

void Tester::Calc() {
    payment = 0.8 * part * salary + salary;
}

int TeamLeader::CalcHeads() const {
    return 10000;
}

void TeamLeader::Calc() {
    payment = CalcHeads() + CalcProAdditions() + CalcBudgetPart() +
        CalcBase(salary, worktime);
}

std::string Engineer::GetPosition() const {
    return "Engineer";
}

std::string Programmer::GetPosition() const {
    return "Programmer";
}

std::string Tester::GetPosition() const {
    return "Tester";
}

std::string TeamLeader::GetPosition() const {
    return "Team Leader";
}
