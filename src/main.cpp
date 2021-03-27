// Copyright 2021 asma
#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "Project.h"
#include "Personal.h"
#include "Engineer.h"
#include "Factory.h"

int main() {
    StaffFactory reader("Employees.txt", "Projects.txt");
    auto emp_vec = reader.ReadEmployees();
    for (auto employee : emp_vec) {
        employee->SetWorkTime(8);
    }
    int i = 1;
    for (auto employee : emp_vec) {
        std::cout << "Worker #" << i++ << '\n';
        employee->Calc();
        employee->PrintInfo();
        std::cout << "------------" << '\n' << '\n';
    }
    return 0;
}
