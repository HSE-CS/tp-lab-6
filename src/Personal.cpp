// Copyright 2021 MalininDmitry
#include <string>
#include <sstream>
#include <iostream>
#include "Personal.h"
#include "Employee.h"

Personal::Personal(unsigned int id, std::string name,
                   std::string position,
                   unsigned int payment,
                   int salary) : Employee(id,
                                           name,
                                           position,
                                           payment),
                                           salary(salary) {}

int Personal::calcBase(int salary, int wtime) {
    return salary * wtime;
}

int Personal::calcBonus() {
    return 5;
}

void Personal::calc() {
    payment = calcBase(salary, worktime) + calcBonus();
}

void Personal::printInfo() {
    std::cout << "Information : " << std::endl;
    std::cout << "id : " << id << std::endl;
    std::cout << "name : " << name << std::endl;
    std::cout << "position : " << position << std::endl;
    std::cout << "worktime : " << worktime << std::endl;
    std::cout << "salary : " << salary << std::endl;
    std::cout << "payment : " << payment << std::endl;
}

Driver::Driver(unsigned int id, std::string name,
               std::string position, unsigned int payment)
: Personal(id, name, position, 0, payment) {}

Cleaner::Cleaner(unsigned int id, std::string name,
                 std::string position, unsigned int payment)
: Personal(id, name, position, 0, payment) {}
