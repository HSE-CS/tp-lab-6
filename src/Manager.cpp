// Copyright 2021 Rogov Andrey
#include "Manager.h"
#include <iostream>
void ProjectManager::printInfo() {
    Employee::printInfo();
    std::cout << "PRO_ADDITIONS: " << calcProAdditions() << std::endl
        << "PROJECT_NUM: " << projects.size() << std::endl;
    for (const auto& project : projects) {
        std::cout << "  PROJECT_ID: " << project.id << std::endl
            << "  PROJECT_BUDGET: " << project.budget << std::endl
            << "  PROJECT_STAFF: " << project.staff_num << std::endl;
    }
}
uint32_t ProjectManager::calcHeads() {
    uint32_t heading_sum = 0;
    for (const auto& p : projects) {
        heading_sum += p.staff_num * MANAGER_PER_HEAD;
    }
    return heading_sum;
}

uint32_t ProjectManager::calcBudgetPart(float part, uint32_t budget) {
    return static_cast<uint32_t>(part * static_cast<float>(budget));
}
uint32_t ProjectManager::calcProAdditions() { return MANAGER_PRO_ADDITIONS; }

void ProjectManager::calc() {
    payment = calcHeads() +
        calcBudgetPart(1.0 / static_cast<float>(projects.front().staff_num),
            projects.front().budget) +
        calcProAdditions();
}
void SeniorManager::calc() {
    uint32_t sum = 0;
    for (const auto& p : projects) {
        sum += calcBudgetPart(1.0 / static_cast<float>(p.staff_num), p.budget);
    }
    payment = calcHeads() + sum + calcProAdditions();
}
