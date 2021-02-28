//  Copyright 2021 Nikita Naumov

#include "Tester.h"

Tester::Tester(unsigned int id, const std::string& name) : Engineer(id, name) {
    this->id = id;
    this->name = std::move(name);
    setPosition(7);
    this->worktime = 0;
    this->salaryPerHour = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
}
unsigned Tester::calcProAdditions() {
    return 2 * salaryPerHour * worktime;
}
void Tester::calc() {
    this->payment = calcBudgetPart() + calcProAdditions()
            + calcBase(this->salaryPerHour, this->worktime);
}
void Tester::printInfo() {
    std::cout << "Name " << this->name << std::endl;
    std::cout << "Employee's ID " << this->id << std::endl;
    std::cout << "Employee's position " <<
                convertPositionToString() << std::endl;
    std::cout << "Current work time " << this->worktime << std::endl;
    std::cout << "Salary per hour " << this->salaryPerHour << std::endl;
    std::cout << "Current payment " << this->payment << std::endl;
    std::cout << "Info about related project " << std::endl;
    if (this->linkToProject) {
        std::cout << "Project ID " <<
                    this->linkToProject->getProjectID() << std::endl;
    } else {
        std::cout << "No related project" << std::endl;
    }
}