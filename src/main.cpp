// Copyright 2021 FOM
#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

int main() {
    Driver* person_1 = new Driver(345, "Antonina Pavlovna",
        "Driver", 120, 96);
    Cleaner* person_2 = new Cleaner(23, "Polina Ivanovna",
        "Cleaner", 150, 80);
    Project project_test = { 1, "test", 23435454 };
    Tester* person_3 = new Tester(234, "Svetlana Sergeevna",
        "Tester", 230, 150, &project_test, 0.5);
    Programmer* person_4 = new Programmer(24, "Sergei Antonovish",
        "Programer", 230, 170, &project_test, 0.7);
    TeamLeader* person_5 = new TeamLeader(27, "Pavel Petrovish",
        "TeamLeader", 265, 200, &project_test, 1);
    std::vector<Project*> projects_test;
    projects_test.push_back(&project_test);
    ProjectManager* person_6 = new ProjectManager(54, "Robert Igorivish",
        "Project Manager", 1, 300, 180, projects_test);
    SeniorManager* person_7 = new SeniorManager(53, "Anna Germonovna",
        "Senior Manager", 1, 290, 189, projects_test);
    person_1->printInfo();
    person_2->printInfo();
    person_3->printInfo();
    person_4->printInfo();
    person_5->printInfo();
    person_6->printInfo();
    person_7->printInfo();
    person_1->setSalary(453);
    std::cout << person_1->calc() << std::endl;
    std::cout << person_2->calcBonus() << std::endl;
    std::cout << person_3->calcProAdditions() << std::endl;
    std::cout << person_4->getId() << std::endl;
    std::cout << person_5->getName() << std::endl;
    std::cout << person_6->getPosition() << std::endl;
    std::cout << person_7->getWorkTime() << std::endl;
    std::cout << project_test.name << std::endl;
    std::cout << project_test.id << std::endl;
    std::cout << project_test.budget << std::endl;
    return 0;
}
