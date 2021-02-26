// Copyright 2021 JGMax

#include <iostream>
#include "Personal.h"

Personal::Personal(const int id,
                   const std::string fullName,
                   const int workTime,
                   const Position position,
                   const int salary,
                   const double bonus)
        : Employee(id, fullName, workTime, position) {
    this->salary = salary;
    this->bonus = bonus;
    calc();
}

void Personal::calc() {
    payment = calcBase() + calcBonus();
}

void Personal::printInfo() {
    calc();
    std::cout << this->getFullName() << "\t" << this->getPosition() << std::endl;
    std::cout << "Payment:\t" << this->getPayment() << std::endl;
    std::cout << "WorkTime:\t" << this->getWorkTime() << std::endl;
}

int Personal::calcBase() {
    return salary * workTime;
}

int Personal::calcBonus() {
    return bonus * salary;
}

Driver::Driver(const int id,
               const std::string fullName,
               const int workTime,
               const Position position,
               const int salary,
               const double bonus) : Personal(id,
                                        fullName,
                                        workTime,
                                        position,
                                        salary, bonus) {

}


Cleaner::Cleaner(const int id,
                 const std::string fullName,
                 const int workTime,
                 const Position position,
                 const int salary) : Personal(id,
                                                 fullName,
                                                 workTime,
                                                 position,
                                                 salary) {

}
