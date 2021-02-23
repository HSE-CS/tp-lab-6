//// Copyright 2021 Dmitry Vargin
#include <iostream>

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

int main() {
    /*
    Project *project1 = new Project(1, 12312312);
    Project *project2 = new Project(2, 44556);
    std::vector<Project *>projects = {project1, project2};

    Employee *employee = new SeniorManager(1, "Dima", "Python", projects);
    employee->printInfo();
    */

    std::vector<Employee*> staff = readData("data1.txt");
    for (Employee *em : staff) {
        // std::cout << em->calc() << std::endl;
        em->printInfo();
        // std::cout << em->getId() << std::endl;
    }
    return 0;
}
