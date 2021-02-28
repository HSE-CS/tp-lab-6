// Copyright 2021
#include "Personal.h"
#include <iostream>
#include <sstream>
#include <string>

double Personal::getSalary() {
    return salary;
}

void Personal::setSalary(double salary) {
    this->salary = salary;
}


double Personal::calcBase(int wtime) {
    return salary * wtime;
}

void Personal::printInfo() {
    std::stringstream stream;
    stream << "Name: " << name
        << ", position: " << position
        << ", workTime: " << worktime
        << ", payment: " << payment
        << ", salary: " << getSalary();
    std::cout << stream.str() << std::endl;
}
