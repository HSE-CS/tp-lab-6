// Copyright 2020 Golovanov
#include "Interfaces.h"

#include "Employee.h"
#include "Personal.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

void Personal::set_salary(int salary) {
    this->salary = salary;
}
int Personal::calcBase(int time, int salary) {
    return time * salary;
}
int Personal::get_salary() {
    return salary;
}

int Driver::calcBonus() {
    return (this->get_worktime() * this->get_salary() * 0, 2);
}
int Driver::calc() {
    return (this->calcBase(get_worktime(), get_salary()) + this->calcBonus());
}
void Driver::printInfo() {
    std::cout << std::endl
        << this->get_id() << " - " << this->get_name() << " - "
        << this->get_position() << "\nSalary = " << this->get_salary()
        << "\nWorktime = " << this->get_worktime()
        << "\nFinal payment = " << this->calc() << std::endl;
}

int Cleaner::calc() {
    return (this->calcBase(get_worktime(), get_salary()));
}
void Cleaner::printInfo() {
    std::cout << std::endl
        << this->get_id() << " - " << this->get_name() << " - "
        << this->get_position() << "\nSalary = " << this->get_salary()
        << "\nWorktime = " << this->get_worktime()
        << "\nFinal payment = " << this->calc() << std::endl;
}