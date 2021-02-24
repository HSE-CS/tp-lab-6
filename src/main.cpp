// Copyright 2021 Igumnova Natasha
#include "Factory.h"

#include <iostream>
#include <string>
#include <fstream>

int main() {
    Factory file("data.txt", "projects.txt");
    std::vector<Employee*> staff = file.makeStaff();
    // расчет зарплаты
    std::cout << staff[0]->getId() << std::endl;
    for (int i = 0; i < staff.size(); i++) {
        std::cout << staff[i]->getId() << " " << staff[i]->calc() << std::endl;
	}
    // вывод данных о зарплате
    for (Employee* emp : staff) {
        emp->printInfo();
    }
}
