//// Copyright 2021 Dmitry Vargin

#include "Personal.h"

int Personal::calcBase(int payment, int wtime) {
    return payment * wtime;
}

int Personal::calcBonus() {
    return 0;
}

int Personal::calc() {
    this->salary = calcBase(
            (int) this->payment,
            this->worktime)
                    + calcBonus();
    return (int) this->salary;
}
void Personal::printInfo() {
    std::cout << "ID: " << std::to_string(getId()) << std::endl;
    std::cout << "NAME: " << getName() << std::endl;
    std::cout << "POSITION: " << getPosition() << std::endl;
    std::cout << "WORK TIME: " << this->getWorktime() << std::endl;

    std::cout << "SALARY: " +
                 std::to_string(getSalary()) << std::endl;
}

int Driver::calcBonus() {
    if (getWorktime() > 50)
        return payment * 1.1;
    else
        return 0;
}
