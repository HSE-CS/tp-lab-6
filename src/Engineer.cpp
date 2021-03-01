//  Copyright 2021 Kartseva Masha
#include "Engineer.h"
#include <map>

extern std::map<std::string, int> projects;

Engineer::Engineer(std::string name, unsigned int id, 
    float base, std::string position, std::string project, 
    float contribution) : Employee(name, id) {
    this->base = base;
    this->position = position;
    this->project = project;
    this->contribution = contribution;
}

float Engineer::getPaymentbyWorkTime() {
    return worktime * base;
}

float Engineer::getPaymentbyProject() {
    return projects[project] * contribution;
}

Tester::Tester(std::string name, unsigned int id, 
    float base, std::string position, std::string project, 
    float contribution)
    : Engineer(name, id, base, position, project, contribution) {};

float Tester::getPayment() {
    payment = getPaymentbyWorkTime() + getPaymentbyProject();
    return payment;
}

Programmer::Programmer(std::string name, unsigned int id, 
    float base, std::string position, std::string project, 
    float contribution)
    : Engineer(name, id, base, position, project, contribution) {};

float Programmer::getPayment() {
    payment = getPaymentbyWorkTime() + getPaymentbyProject();
    return payment;
}

TeamLeader::TeamLeader(std::string name, unsigned int id,
    float base, std::string position, std::string project, 
    float contribution, unsigned int subordinates)
: Programmer(name, id, base, position, project, contribution) {
    this->subordinates = subordinates;
}

float TeamLeader::getPaymentbyHeading() {
    return subordinates * 1500;
}

float TeamLeader::getPayment() {
    payment = Programmer::getPayment() + getPaymentbyHeading();
    return payment;
}
