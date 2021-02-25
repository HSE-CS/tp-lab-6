#include "Personal.h"
#include <string>

std::string PositionString[] = {
    "Driver", "Cleaner"
};

Personal::Personal(int id, std::string name, Position position,
    int salary) : Employee(id, name, position) {
    this->salary = salary;
}

int Personal::calcBase(int salary, int wtime) {
    return wtime * salary;
}

int Personal::calcBonus() {
    return 200;
}

void Personal::printInfo() {
    std::cout << "id " << this->id << std::endl;
    std::cout << "name " << this->name << std::endl;
    std::cout << "position " <<
        PositionString[int(this->position)]<< std::endl;
    std::cout << "work time " << this->worktime << std::endl;
    std::cout << "payment " << this->payment << std::endl;
    std::cout << std::endl;
}

Driver::Driver(int id, std::string name, Position position, int salary) :
    Personal(id, name, position, salary) {};

void Driver::calc() {
    this->payment = calcBonus() + calcBase(this->salary, this->worktime);
}

Cleaner::Cleaner(int id, std::string name, Position position, int salary) :
    Personal(id, name, position, salary) {};

void Cleaner::calc() {
    this->payment = calcBase(this->salary, this->worktime);
}
