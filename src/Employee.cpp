// Copyright 2021 by mila
#include "Employee.h"

void Employee::setWorkTime(int wtime) {
    this->worktime = wtime;
}

void Employee::calc() {
    payment = worktime*salary;
}

void Employee::printInfo() {
    std::cout << "id : " << this.id << std::endl;
    std::cout << "name : " << this.name << std::endl;
    std::cout << "position : " << this.position << std::endl;
    std::cout << "salary : " << salary << std::endl;
    std::cout << "worktime : " << worktime << std::endl;
    std::cout << "payment : " << payment << std::endl;
};
