// Copyright 2021 asma
#include "Personal.h"
#include <string>

Driver::Driver(int _id, std::string _name, Position _position, int _salary) {
    id = _id;
    name = _name;
    position = _position;
    salary = _salary;
    worktime = 0;
    payment = 0;
}

Cleaner::Cleaner(int _id, std::string _name, Position _position, int _salary) {
    id = _id;
    name = _name;
    position = _position;
    salary = _salary;
    worktime = 0;
    payment = 0;
}

int Personal::CalcBase(int sal, int wtime) const {
    return sal * wtime;
}

int Personal::CalcBonus() const {
    return 0;
}

void Personal::PrintInfo() const {
    std::cout << "Name - " << name << '\n';
    std::cout << "Position - " << GetPosition() << '\n';
    std::cout << "Salary - " << salary << '\n';
    std::cout << "Payment - " << payment << '\n';
}

int Driver::CalcBonus() const {
    return worktime * 0.01 * salary;
}

void Driver::Calc() {
    payment = CalcBase(salary, worktime) + CalcBonus();
}

void Cleaner::Calc() {
    payment = CalcBase(salary, worktime);
}

std::string Driver::GetPosition() const {
    return "Driver";
}

std::string Cleaner::GetPosition() const {
    return "Cleaner";
}
