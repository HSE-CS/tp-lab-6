//  Copyright Baklanov 2021
#include <iostream>
#include <string>
#include <random>
#include "Interfaces.h"
#include "Factory.h"
#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"
#include "Employee.h"
#include "Resource.h"

int main() {
    std::string r = "staff.txt";
    std::string w = "output.txt";
    Resource* a = new Resource(r, w);
    std::vector<Employee*> staff;
    std::vector<Project*> Projects;
    staff = makeStaff(a);
    a->readpath = "projects.txt";
    makeStaffForProject(a, Projects, staff);
    for (Employee* emp : staff) {
        emp->setWorkTime(std::rand() % 25 + 5);
    }
    for (Employee* emp : staff) {
        emp->calc();
    }
    for (Employee* emp : staff) {
        emp->printinfo();
    }
}
