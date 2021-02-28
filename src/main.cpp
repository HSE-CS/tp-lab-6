// Copyright 2021 Bogomazov
#include <iostream>
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"


int main() {
    Cleaner* person_f = new Cleaner(23, "First Name",
        "Cleaner", 100, 50);
    Project test_project = { 1, "Test project", 9999999 };
    Driver* person_s = new Driver(300, "Second Name",
        "Driver", 150, 100);
    Tester* person_th = new Tester(250, "Third Name",
        "Tester", 250, 125, &test_project, 0.2);
    Programmer* person_f = new Programmer(35, "Fourth Name",
        "Programer", 1000, 200, &test_project, 0.5);
    TeamLeader* person_fi = new TeamLeader(27, "Fifth Name",
        "TeamLeader", 2500, 500, &test_project, 1);
    person_f->printInfo();
    person_s->printInfo();
    person_th->printInfo();
    person_f->printInfo();
    person_fi->printInfo();
    person_f->setSalary(13);

    std::cout << test_project.name << std::endl;
    std::cout << test_project.id << std::endl;
    std::cout << test_project.budget << std::endl;

    std::cout << person_f->calc() << std::endl;
    std::cout << person_s->calcBonus() << std::endl;
    std::cout << person_th->calcProAdditions() << std::endl;
    std::cout << person_f->getId() << std::endl;
    std::cout << person_fi->getName() << std::endl;
    return 0;
}
