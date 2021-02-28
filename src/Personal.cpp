// Copyright 2021 Schenikova

#include "Personal.h"

unsigned int Personal::calcBase() {
    return salary * worktime;
}

void Personal::setSalary(unsigned int salary) {
  this->salary = salary;
}

unsigned int Personal::calcBonus(unsigned nighttime, unsigned oversalary) {
    return 0;
}

void Personal::printInfo() {
  std::cout << "\t" << "Id: " << id << '\n';
  std::cout << "\t" << "Name: " << name << '\n';
  std::cout << "\t" << "Position: " << position << '\n';
  std::cout << "\t" << "Work time: " << worktime << '\n';
  std::cout << "\t" << "Payment: " << getPayment() << '\n';
}

unsigned int Driver::calcBonus(unsigned nighttime, unsigned oversalary) {
    return nighttime * oversalary;
}

void Driver::calc() {
    payment = calcBase() + calcBonus(nighttime, oversalary);
}

void Cleaner::calc() {
    payment = calcBase();
}
