// Copyright 2021 Danyaev Artem
#include "Factory.h"
#include <iostream>

int main() {

    std::vector<Employee*> staff =
        Factory::makeStaff("projects.txt", "employees.txt");

    // присвоение отработанного времени
    for (Employee* emp : staff) {
        emp->setWorkTime(std::rand() % 50);
    }

    // расчет зарплаты
    for (Employee* emp : staff) {
        emp->calc();
    }

    // вывод данных о зарплате
    for (Employee* emp : staff) {
        emp->printInfo();
    }

    return 0;
}
