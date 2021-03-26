// Copyright 2020 Uskova

#include "Employee.h"
#include "Engineer.h"

Engineer::Engineer(int id, std::string name, Position pos, int wtime,
                   int salary, Project* proj)
    : Personal(id, name, pos, wtime, salary) {
  this->project = proj;
}

int Engineer::getSalary() {
    return this->salary;
}

Project* Engineer::getProject() {
    return this->project;
}

int Engineer::calcBudgetPart(float part, int budget) {
    return budget * part;
}

void Engineer::calc() {
  this->payment = calcBudgetPart(this->project->calcPart(),
                                 0.6 * this->project->getBudget()) +
                  calcBase(this->salary, this->worktime) + calcProAdditions();
}

int Engineer::calcBonus() {
    return 0;
}

void Engineer::setProject(Project* pr) {
  this->project = pr;
}

std::string Engineer::getProjectName() {
    return this->project->getName();
}

Programmer::Programmer(int id, std::string name, Position pos, int wtime,
                       int salary, int coef, Project* proj)
    : Engineer(id, name, pos, wtime, salary, proj) {
  this->coef = coef;
}

int Programmer::getCoef() {
    return this->coef;
}

int Programmer::calcProAdditions() {
    return 6000 * this->coef;
}

void Programmer::printinfo() {
  std::cout << std::endl;
  std::cout << "Name: " << getName() << std::endl;
  std::cout << "Id: " << getId() << std::endl;
  std::cout << "Position: " << getStrPosition() << std::endl;
  std::cout << "Progect: " << getProjectName() << std::endl;
  std::cout << "Worktime: " << getWorktime() << std::endl;
  std::cout << "Salary per hour: " << this->salary << std::endl;
  std::cout << "Bonus: " << calcProAdditions() << std::endl;
  std::cout << "Payment: " << getPayment() << std::endl;
  std::cout << std::endl;
}

Tester::Tester(int id, std::string name, Position pos, int wtime, int salary,
               int coef, Project* proj)
    : Engineer(id, name, pos, wtime, salary, proj) {
  this->numFoundMistakes = coef;
}

int Tester::getCoef() {
    return this->numFoundMistakes;
}

int Tester::calcProAdditions() {
    return 800 * this->numFoundMistakes;
}

void Tester::printinfo() {
  std::cout << std::endl;
  std::cout << "Name: " << getName() << std::endl;
  std::cout << "Id: " << getId() << std::endl;
  std::cout << "Position: " << getStrPosition() << std::endl;
  std::cout << "Progect: " << getProjectName() << std::endl;
  std::cout << "Worktime: " << this->worktime << std::endl;
  std::cout << "Salary per hour: " << this->salary << std::endl;
  std::cout << "Bonus: " << calcProAdditions() << std::endl;
  std::cout << "Payment: " << getPayment() << std::endl;
  std::cout << std::endl;
}

TeamLeader::TeamLeader(int id, std::string name, Position pos, int wtime,
                       int salary, Project* proj)
    : Programmer(id, name, pos, wtime, salary, 0, proj) { }

int TeamLeader::calcHeads() {
    return this->project->getWorkers();
}

void TeamLeader::calc() {
  this->payment = (calcHeads() * 2000) +
                  calcBudgetPart(this->project->calcPart(),
                                 this->project->getBudget() * 0.6) +
                  calcBase(this->salary, this->worktime);
}

void TeamLeader::addProject(Project* pr) {
  this->project = pr;
}

void TeamLeader::printinfo() {
  std::cout << std::endl;
  std::cout << "Name: " << getName() << std::endl;
  std::cout << "Id: " << getId() << std::endl;
  std::cout << "Position: " << getStrPosition() << std::endl;
  std::cout << "Progect: " << getProjectName() << std::endl;
  std::cout << "Number of workers in the project: "
            << this->project->getWorkers() << std::endl;
  std::cout << "Worktime: " << this->worktime << std::endl;
  std::cout << "Salary per hour: " << this->salary << std::endl;
  std::cout << "Bonus: " << calcProAdditions() << std::endl;
  std::cout << "Payment: " << getPayment() << std::endl;
  std::cout << std::endl;
}
