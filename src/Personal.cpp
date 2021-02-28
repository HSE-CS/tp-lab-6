// Copyright 2021 FOM

#include "Interfaces.h"
#include "Employee.h"
#include "Personal.h"
#include <iostream>


int Personal::calcBase(int salary, int wtime) {
    return salary * wtime;
}
int Personal::calcBonus() {
    return 0;
}
int Personal::getSalary() {
    return salary;
}
int Personal::calc() {
    return calcBase(salary, worktime) + calcBonus();
}
void Personal::setSalary(int salary) {
    this->salary = salary;
}
void Personal::printInfo() {
    std::cout << "ID : " << getId() << std::endl;
    std::cout << "Name : " << getName() << std::endl;
    std::cout << "Position : " << getPosition() << std::endl;
    std::cout << "Work time : " << getWorkTime() << std::endl;
    std::cout << "Salary : " << getSalary() << std::endl;
}

int Driver::calcBonus() {
    return (this->getWorkTime() * this->getSalary() * 0.3);
}

