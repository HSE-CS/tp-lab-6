// Copyright 2021 Islam Osmanov
#include "Personal.h"

Personal::Personal(int id, int salary,
                   std::string position,
                   std::string name) : Employee(id, name, position, salary) {
    setSalary(salary);
}

int Personal::calcBase(int sal, int wtime) {
    int base = sal * wtime;
    return base;
}

void Personal::setSalary(int sal) {
    this->salary = sal;
}

int Personal::getSalary() {
   return this->salary;
}


Driver::Driver(int id, int salary,
               std::string position, std::string name) : Personal(id, salary,
                                                                  position, name){
}


int Driver::calcBonus(int bonus) {
    if(getWorkTime() > 40) {
        return bonus;
    }
    else if (getWorkTime() <= 40) {
        return 0;
    }
}

void Driver::calc() {
    int pay = calcBase(getSalary(), getWorkTime());
    pay += calcBonus(500);
    setPayment(pay);
}

void Driver::printInfo() {
    std::cout << "--------------" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << getPosition() << " - position" << std::endl;
    std::cout << getPayment() << " - payment" << std::endl;
    std::cout << "--------------" << std::endl;
}

Cleaner::Cleaner(int id, int salary,
               std::string position, std::string name) : Personal(id, salary,
                                                                  position, name){
}


int Personal::calcBonus(int bonus){
    return 0;
}

void Cleaner::printInfo() {
    std::cout << "--------------" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << getPosition() << " - position" << std::endl;
    std::cout << getPayment() << " - payment" << std::endl;
    std::cout << "--------------" << std::endl;
}

void Cleaner::calc() {
    int pay = calcBase(getSalary(), getWorkTime());
    setPayment(pay);
}


