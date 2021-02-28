// Copyright 2021 Islam Osmanov

#include <string>
#include <vector>
#include "Engineer.h"
#include "Personal.h"

Engineer::Engineer(int id,
                   std::string pos,
                   std::string name,
                   int payment,
                   Project *project1) : Personal(id, payment, pos, name) {
    this->project = project1;
}

Tester::Tester(int id,
               std::string pos,
               std::string name,
               int payment,
               Project *project1) : Engineer(id, pos, name, payment, project1) {
    setPosition(pos);
    setSalary(payment);
}

Programmer::Programmer(int id,
                       std::string pos,
                       std::string name,
                       int payment,
                       Project *project1) : Engineer(id, pos, name, payment, project1) {
    setPosition(pos);
    setSalary(payment);
}

TeamLeader::TeamLeader(int id,
                       std::string pos,
                       std::string name,
                       int payment,
                       int programmers,
                       Project *project1) : Programmer(id, pos, 
                                            name, payment, project1) {
    this->programmers_num = programmers;
    setSalary(payment);
}

int Engineer::calcBudgetPart(double piece, int budget) {
    return static_cast<int>(budget / piece);
}

Project* Engineer::getProject() {
    return project;
}

void Engineer::calc() {
    int base = calcBase(getSalary(), getWorkTime());
    int part = calcBudgetPart(15, getProject()->getBudget());
    int sum = base + part + calcProAdditions(20);
    setPayment(sum);
}

void Engineer::printInfo() {
    std::cout << "--------------" << std::endl;
    std::cout << "Id: " << getId() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << getPosition() << " - position" << std::endl;
    std::cout << getPayment() << " - payment" << std::endl;
    std::cout << "--------------" << std::endl;
}

int Tester::getErrorsNum() {
    return mistakes_num;
}

int Tester::calcProAdditions(int bonus) {
    int sum = getErrorsNum() + bonus;
    return sum;
}

void Tester::addErrors() {
    mistakes_num++;
}

int Programmer::calcProAdditions(int bonus) {
    int sum = 0;
    if (getWorkTime() > 40) {
        sum += 5000;
    }
    if (getProject()->getBudget() > 10000) {
        sum += 2000;
    }
    return sum;
}

int TeamLeader::getProgrammers() {
    return programmers_num;
}

int TeamLeader::calcHeads() {
    int sum = getProgrammers() + 500;
    return sum;
}

void TeamLeader::calc() {
    int base = calcBase(getSalary(), getWorkTime());
    int additions = calcProAdditions(20);
    int sum = calcHeads() + base + additions;
    setPayment(sum);
}






