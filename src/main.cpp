//  Copyright 2021 Nikita Naumov

#include "Personal.h"
#include "Programmer.h"
#include "Manager.h"
#include "Tester.h"
#include "TeamLeader.h"
#include "Project.h"
#include "Factory.h"

void delimiter() {
    std::cout << "==============================================" << std::endl;
}

int main () {
    /*unsigned num = 0;
    ProjectManager managerObj(num, "Name1");
    managerObj.printInfo();
    ++num;
    delimiter();
    Driver driverObj(num, "Name2");
    driverObj.printInfo();
    ++num;
    delimiter();
    Programmer programmerObj(num, "Name4");
    programmerObj.printInfo();
    ++num;
    delimiter();
    Cleaner cleanerObj(num, "Name3");
    cleanerObj.printInfo();
    ++num;
    delimiter();
    Tester testerObj(num, "Name5");
    testerObj.printInfo();
    ++num;
    delimiter();
    TeamLeader teamleadObj(num, "Name6");
    teamleadObj.printInfo();
    ++num;
    delimiter();

    Project projectObj(0, 100000);
    std::cout << projectObj.getProjectID()  << "\t" <<
    projectObj.getNumberOfMembers() << "\t"
    << projectObj.getProjectBudget() << std::endl;

    programmerObj.setProject(&projectObj);
    testerObj.setProject(&projectObj);
    teamleadObj.setProject(&projectObj);
    managerObj.setProject(&projectObj);
    std::cout << "\n\n\n" << std::endl;
    delimiter();
    programmerObj.printInfo();
    delimiter();
    testerObj.printInfo();
    delimiter();
    teamleadObj.printInfo();
    delimiter();
    managerObj.printInfo();
    delimiter();
    projectObj.printInfo();
    delimiter();
    std::cout << "\n\n\n\n\n" << std::endl;
    programmerObj.setSalaryPerHour(200);
    programmerObj.setWorkTime(50);
    programmerObj.calc();
    programmerObj.printInfo();
    delimiter();
    driverObj.setWorkTime(50);
    driverObj.setSalaryPerHour(100);
    driverObj.calc();
    driverObj.printInfo();
    std::cout << programmerObj.calcBudgetPart();
    delimiter();
    managerObj.calcProAdditions();
    managerObj.setWorkTime(50);
    managerObj.calc();
    managerObj.printInfo();
    delimiter();

    cleanerObj.setWorkTime(50);
    cleanerObj.setSalaryPerHour(90);
    std::cout << cleanerObj.getSalaryPerHour();
    cleanerObj.calc();
    std::cout << std::endl;
    cleanerObj.printInfo();
    delimiter();

    SeniorManager seniorManObj(++num, "Name7");
    seniorManObj.printInfo();
    delimiter();
    seniorManObj.setProject(&projectObj);
    seniorManObj.setWorkTime(50);
    seniorManObj.calc();
    seniorManObj.printInfo();
    delimiter();
    projectObj.printInfo();
    delimiter();
    teamleadObj.setWorkTime(100);
    teamleadObj.setSalaryPerHour(220);
    teamleadObj.calc();
    teamleadObj.printInfo();*/
    std::string pathFile;
    std::cout << "Enter path to file" << std::endl;
    std::cin >> pathFile;
    std::vector<Employee*> company;
    company = makeStaffVector(pathFile);
    for (auto emp : company) {
        (*emp).printInfo();
        delimiter();
    }
    for (auto emp : company) {
        emp->setWorkTime(std::rand()%121);
    }
    std::vector<Project*> projectVector;
    for (size_t i = 0; i < 10; ++i) {
        projectVector.push_back(new Project(i,
                           100000+(std::rand()%3000 - 1500)));
    }
    for (size_t i = 0; i < projectVector.size(); ++i){
        projectVector[i]->printInfo();
        delimiter();
    }
    for (auto emp : company) {
        emp->calc();
    }
    /*for (auto emp : company) {
        emp->printInfo();
        delimiter();
    }*/

    return 0;
}