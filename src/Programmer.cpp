//  Copyright 2021 Nikita Naumov

#include "Programmer.h"

Programmer::Programmer(unsigned id, const std::string& name)
            : Engineer(id, name) {
    this->id = id;
    this->name = std::move(name);
    this->additionalHours = std::rand()%101;
    setPosition(4);  //  set Programmer position
    this->worktime = 0;
    this->salaryPerHour = 0;
    this->payment = 0;
    this->linkToProject = nullptr;
}
unsigned Programmer::calcProAdditions() {
    return 2 * salaryPerHour * additionalHours;
}
void Programmer::calc() {
    this->payment = calcBudgetPart() + calcProAdditions()
            + calcBase(this->salaryPerHour, this->worktime);
}
void Programmer::printInfo() {
    std::cout << "Name " << this->name << std::endl;
    std::cout << "Employee's ID " << this->id << std::endl;
    std::cout << "Employee's position " <<
                convertPositionToString() << std::endl;
    std::cout << "Current work time " << this->worktime << std::endl;
    std::cout << "Additional hours " <<
                this->additionalHours << std::endl;
    std::cout << "Salary per hour " << this->salaryPerHour << std::endl;
    std::cout << "Current payment " << this->payment << std::endl;
    std::cout << "Info about related project" << std::endl;
    if (this->linkToProject) {
        std::cout << "Project ID " <<
                    this->linkToProject->getProjectID() << std::endl;
    } else {
        std::cout << "No related project" << std::endl;
    }
}
