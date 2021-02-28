// Copyright 2020 Golovanov
#include "Manager.h"

#include <cmath>
#include <fstream>
#include <string>

#include "Engineer.h"

int ProjectManager::calcHeads() { return 1000; }
int ProjectManager::calcProAdditions() { return calcHeads(); }
int ProjectManager::calc() {
    return get_payment() * get_worktime() + calcProAdditions() + calcHeads();
}

int ProjectManager::calcBudgetPart(float part, int budget) {
    return budget * part;
}
void ProjectManager::printInfo() {
    std::cout << std::endl
        << this->get_id() << " - " << this->get_name() << " - "
        << this->get_position() << "\nWorktime = " << this->get_worktime()
        << "\nFinal payment = " << this->calc() << std::endl;
}
int SeniorManager::calc() { return ProjectManager::calc(); }
void SeniorManager::printInfo() {
    std::cout << std::endl
        << this->get_id() << " - " << this->get_name() << " - "
        << this->get_position() << "\nWorktime = " << this->get_worktime()
        << "\nFinal payment = " << this->calc() << std::endl;
}
