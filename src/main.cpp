// Copyright 2021 Kartseva Masha
#include "Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>

extern std::map<std::string, int> projects;

std::vector<Employee*> createEmployees() {
    system("chcp 65001");
    std::ifstream fin("names.txt");
    std::string buf;
    std::vector<std::string> str;
    std::vector<Employee*> employees;
    while (getline(fin, buf)) {
        str = split(buf, ' ');
        employees.push_back(Factory::createEmployee(str));
    }
    fin.close();
    return employees;
}

void createProjects() {
    system("chcp 65001");
    std::ifstream fin("projects.txt");
    std::string buf;
    std::vector<std::string> str;
    unsigned int tmp;
    while (getline(fin, buf)) {
        str = split(buf, ' ');
        tmp = atoi(str[1].c_str());
        projects[str[0]] = tmp;
    }
}


int main() {
    createProjects();
    std::vector<Employee*> employees = createEmployees();
    float salary, max = 0;
    for (auto emp : employees) {
        emp->setWorkTime(rand() % 10 + 30);
        salary = emp->getPayment();
        if (salary > max) 
            max = salary;
        std::cout << emp->getId() << " " << emp->getName() << " gets " << salary << std::endl;
    }
    std::cout << "Highest payment is " << max << std::endl;
    getchar();
    return 0;
}
