// Copyright 2021 Kris

#include "Factory.h"
#include <vector>
#include "Employee.h"
#include "Personal.h"
#include <locale>
#include "Manager.h"
#include "Interfaces.h"
#include <fstream>
#include <sstream>

int main() {
    std::string staffList = "Staff.txt";
    std::string projectsList = "Projects.txt";
    std::vector<Employee*> staff = makeStaff(staffList, projectsList);
    std::cout << "Ok";
    const std::size_t s = staff.size();
    int payments[100] = { 0 };
    for (unsigned int i = 0; i < staff.size(); i++) {
        std::cin >> payments[i];
    }
    int i = 0;
    for (Employee* emp : staff) {
        emp->setWorkTime(payments[i]);
        i++;
    }
    for (Employee* emp : staff) {
        emp->calc();
    }
    for (Employee* emp : staff) {
        emp->printInfo();
    }
    return 0;
}
