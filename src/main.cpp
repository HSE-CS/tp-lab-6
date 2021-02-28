// Copyright 2020 Golovanov

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

int main() {
    Cleaner* pers1 = new Cleaner(1, "Katya", "Cleaner", 450, 10);
    Driver* pers2 = new Driver(2, "Dima", "Driver", 600, 8);
    pers1->printInfo();
    pers2->printInfo();
    Project num1 = { 50, "rabota1", 33444 };
    Tester* pers3 = new Tester(3, "Kadykov", "Tester", 1200, 10, &num1, 6);
    pers3->set_salary(1000);
    size_t sum = pers3->calcProAdditions();
    std::cout << "sum = " << sum << '\n';
    pers3->printInfo();
    std::vector<Project*> projects;
    Project num2 = { 50, "rabota2", 93930 };
    Project num3 = { 50, "raabota3", 3334556 };
    projects.push_back(&num2);
    projects.push_back(&num3);
    ProjectManager* manager = new ProjectManager(
        4, "Rokin Maks", "Project Manager", 2, 100000, 10, projects);
    manager->printInfo();
    std::cout << '\n';
    std::cout << '\n';
    std::cout << manager->calcHeads() << '\n';
    std::cout << manager->calcProAdditions() << '\n';
    std::cout << manager->calc() << '\n';
    std::cout << manager->get_payment() << '\n';
    std::cout << manager->get_position() << '\n';
    std::cout << '\n';
    std::cout << '\n';
    std::cout << num2.name << '\n';
    std::cout << num3.name << '\n';
    std::cout << num3.id << '\n';
    std::cout << num3.budget << '\n';
    std::cout << '\n';
    Driver* pers4 = new Driver(2, "Danil", "Driver", 500, 6);
    std::cout << pers4->get_id() << '\n';
    std::cout << pers4->get_name() << '\n';
    std::cout << pers4->get_position() << '\n';
    std::cout << pers4->get_salary() << '\n';
    std::cout << pers4->get_worktime() << '\n';
    std::cout << pers4->calcBonus() << '\n';
    std::cout << pers4->calc() << '\n';
}
