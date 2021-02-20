//
// Created by Valera on 20.02.2021.
//

#include "../include/Personal.h"

int Personal::calcBase(int _salary, int _wtime) {
    return _salary*_wtime;
}

int Personal::calcBonus() {
    return 0;
}

Personal::Personal(int id, const std::string &name, Position position,
                   int salary) : Employee(id, name, position), salary(salary) {}

void Cleaner::calc() {
    payment =  calcBase(salary, workTime) + calcBonus();
}

void Driver::calc() {

}

int Driver::calcBonus() {
    return Personal::calcBonus();
}
