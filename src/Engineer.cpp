// Copyright 2021 soda
#include "Interfaces.h"

#include "Employee.h"
#include "Engineer.h"
#include <iostream>

Engineer::Engineer() {
    std::string name = "";
    this->setId(0);
    this->setName(name);
    this->setWorkTime(0);
    this->setPosition(0);
    this->setSalary(0);
    this->setProject(nullptr);
    this->setPayment(0);
}

Engineer::Engineer(size_t id, std::string name, size_t worktime,
    size_t position, Project* proj, size_t salary) {

    this->setId(id);
    this->setName(name);
    this->setWorkTime(worktime);
    this->setPosition(position);
    this->setSalary(salary);
    this->setProject(proj);
    proj->hireWorker(this);
    this->setPayment(this->calc());
}

size_t Engineer::calc() {
    return (this->calcBase() + this->calcBugetPart());
}

void Engineer::setProject(Project* proj) {
    this->project = proj;
}

void Engineer::setSalary(size_t salary) {
    this->salary = salary;
}

size_t Engineer::getSalary() {
    return salary;
}

size_t Engineer::calcBase() {
    return (this->getWorktime() * this->getSalary());
}

size_t Engineer::calcBugetPart() {
    return (this->project->getPart());
}

std::string Engineer::getProjectName() {
    return (this->project->getName());
}

Project* Engineer::getProj() {
    return (this->project);
}

void Engineer::printInfo() {
    std::cout << std::endl << this->getId() << ". " << this->getName()
        << " - "
        << this->getPosition() << "\nSalary = " << this->getSalary()
        << "; Worktime = " << this->getWorktime() << "; Project and part: "
        << "'" <<this->getProjectName() << "'" << " = "
        << this->calcBugetPart()
        << "; Final payment = " << this->getPayment() << std::endl;
}

Programmer::Programmer() {
    std::string name = "";
    this->setId(0);
    this->setName(name);
    this->setWorkTime(0);
    this->setPosition(0);
    this->setSalary(0);
    this->setProject(nullptr);
    this->setPayment(0);
}

Programmer::Programmer(size_t id, std::string name, size_t worktime,
    size_t position, Project* proj, size_t salary) {

    this->setId(id);
    this->setName(name);
    this->setWorkTime(worktime);
    this->setPosition(position);
    this->setSalary(salary);
    this->setProject(proj);
    proj->hireWorker(this);
    this->setPayment(this->calc());
}

size_t Programmer::calc() {
    return (this->calcProAdittions() + this->calcBase()
        + this->calcBugetPart());
}

size_t Programmer::calcProAdittions() {
    return rand() % 30000;
}

void Programmer::printInfo() {
    std::cout << std::endl << this->getId() << ". " << this->getName()
        << " - "
        << this->getPosition() << "\nSalary = " << this->getSalary()
        << "; Worktime = " << this->getWorktime() << "; Project and part: "
        << "'" << this->getProjectName() << "'" << " = "
        << this->calcBugetPart()
        << "; Final payment = " << this->getPayment() << std::endl;
}

Tester::Tester(size_t id, std::string name, size_t worktime,
    size_t position, Project* proj, size_t salary) {

    this->setId(id);
    this->setName(name);
    this->setWorkTime(worktime);
    this->setPosition(position);
    this->setSalary(salary);
    this->setProject(proj);
    proj->hireWorker(this);
    this->setPayment(this->calc());
}

size_t Tester::calc() {
    return (this->calcProAdittions() + this->calcBase()
        + this->calcBugetPart());
}

size_t Tester::calcProAdittions() {
    return rand() % 25000;
}

void Tester::printInfo() {
    std::cout << std::endl << this->getId() << ". " << this->getName()
        << " - "
        << this->getPosition() << "\nSalary = " << this->getSalary()
        << "; Worktime = " << this->getWorktime() << "; Project and part: "
        << "'" << this->getProjectName() << "'" << " = "
        << this->calcBugetPart()
        << "; Final payment = " << this->getPayment() << std::endl;
}

TeamLeader::TeamLeader(size_t id, std::string name, size_t worktime,
    size_t position, Project* proj, size_t salary) {

    this->setId(id);
    this->setName(name);
    this->setWorkTime(worktime);
    this->setPosition(position);
    this->setSalary(salary);
    this->setProject(proj);
    proj->hireWorker(this);
    this->setPayment(this->calc());
}

size_t TeamLeader::calcHeads() {
    return (this->getProj()->getNumWorker() * 5000);
}

size_t TeamLeader::calcProAdittions() {
    return rand() % 50000;
}

size_t TeamLeader::calc() {
    return (this->calcProAdittions() + this->calcBase() +
        this->calcBugetPart() + this->calcHeads());
}

void TeamLeader::printInfo() {
    std::cout << std::endl << this->getId() << ". " << this->getName()
        << " - "
        << this->getPosition() << "\nSalary = " << this->getSalary()
        << "; Worktime = " << this->getWorktime() << "; Project and part: "
        << "'" << this->getProjectName() << "'" << " = "
        << this->calcBugetPart()
        << "; Final payment = " << this->getPayment() << std::endl;
}
