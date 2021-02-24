// Copyright 2021 Igumnova Natasha
#include "Factory.h"

#include <iostream>
#include <string>
#include <fstream>

int main() {
    Factory file("data.txt", "projects.txt");
    std::vector<Employee*> staff = file.makeStaff();
    // ������ ��������
    std::cout << staff[0]->getId() << std::endl;
    for (int i = 0; i < staff.size(); i++) {
        std::cout << staff[i]->getId() << " " << staff[i]->calc() << std::endl;
	}
    // ����� ������ � ��������
    for (Employee* emp : staff) {
        emp->printInfo();
    }
}
