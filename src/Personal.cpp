// Copyright 2021 Schenikova

#include "Personal.h"

unsigned int Personal::calcBase() {
    return salary * worktime;
}

void Personal::setSalary(unsigned int salary){
  this->salary = salary;
}

unsigned int Personal::calcBonus(unsigned nighttime, unsigned oversalary) {
    return 0;
}

unsigned int Driver::calcBonus(unsigned nighttime, unsigned oversalary) {
    return nighttime * oversalary;
}

void Driver::calc(){
    payment = calcBase() + calcBonus(nighttime, oversalary);
}

void Cleaner::calc(){
    payment = calcBase();
}
