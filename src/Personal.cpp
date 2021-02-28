// Copyright 2021 kostinandrey
#include <utility>
#include "Personal.h"
Personal::Personal(int id, std::string name,
                   int work_time, int salary, Positions position)
        : Employee(id, std::move(name), work_time, position) {
    this->salary = salary;
}

int Personal::calc_base_salary(int salary, int work_time_salary) {
    return salary * work_time_salary;
}

int Personal::calc_bonus_salary(int bonus) {
    return  bonus * this->salary;
}

void Personal::print_info() {
    std::cout << enum_print[this->position] << std::endl;
    std::cout << this->name << std::endl;
    std::cout << "Work time = " << this->work_time << std::endl;
    std::cout << "Payment = " << this->payment << std::endl;
}

Driver::Driver(int id, std::string name,
               int workTime, int salary, Positions position) :
        Personal(id, std::move(name), workTime, salary, position) {
}

int Driver::calc_salary() {
    return this->payment = calc_base_salary(salary, work_time) + calc_bonus_salary();
}
int Driver::calc_bonus_salary(int bonus) {
    return bonus * salary;
}

Cleaner::Cleaner(int id, std::string name,
                 int work_time, int salary, Positions position)
        : Personal(id, std::move(name), work_time, salary, position) {
}
int Cleaner::calc_salary() {
    return this->payment = calc_base_salary(salary, work_time);
}

