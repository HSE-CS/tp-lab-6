// Copyright 2021 Artyom Lavrov


#include <Personal.h>

#include <utility>


int Personal::calcBase(int salary, int workTime) {
    return (salary * workTime);
}

int Personal::GetSalary() const {
    return salary;
}

void Personal::SetSalary(int salary) {
    Personal::salary = salary;
}

void Personal::printInfo() {
}


Driver::Driver(std::string id,
    std::string name,
    POSITION position,
    int salary) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->position = position;
    this->salary = salary;
}

int Driver::calcBonus() {
    if (this->workTime > 40) {
        return (this->workTime - 40) * this->salary;
    }
    else {
        return 0;
    }
}

void Driver::calc() {
    this->payment = calcBase(this->salary, this->workTime) +
        calcBonus();
}


Cleaner::Cleaner(std::string id,
    std::string name,
    POSITION position,
    int salary) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->position = position;
    this->salary = salary;
}

void Cleaner::calc() {
    this->payment = calcBase(this->salary, this->workTime);
}

int Cleaner::calcBonus() {
    return 0;
}
