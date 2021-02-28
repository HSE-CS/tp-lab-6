// Copyright 2021 Galex

#include <string>
#include <iostream>
#include "../include/Engineer.h"

void Engineer::setProject(Project *project) {
  this->project = project;
}
void Engineer::calc() {
  double payment = calcBudgetPart(
      1 / (this->project->getNumOfWorkers()), this->project->getBudget())
      + (this->getSalary() * this->getWorkTime())
      + this->getAddPayment();
  this->setPayment(payment);
}
double Engineer::calcBudgetPart(double part, int budget) {
  return part * budget;
}
Project *Engineer::getProject() {
  return project;
}
double Engineer::calcBonus() {
  return 0;
}
void Engineer::printInfo() {
  std::cout << "ID: " << this->getId() <<
            " Name: " << this->getName() <<
            " Salary: " << this->getSalary() <<
            " Work Time: " << this->getWorkTime() <<
            " Position: " << this->getPosition() <<
            " Payment: " << this->getPayment() <<
            " Project: " << this->getProject()->getId() << "\n";
}

Programmer::Programmer(int id, std::string name,
                       double salary, Project *project) {
  this->setId(id);
  this->setName(name);
  this->setSalary(salary);
  this->setPayment(0);
  this->setAddPayment(0);
  this->setPosition(PROGRAMMER);
  this->setWorkTime(0);
  this->setProject(project);
  project->setNumOfWorkers(project->getNumOfWorkers() + 1);
}
void Programmer::calcProAdditions() {
  this->setAddPayment(this->getAddPayment() + 5555);
}
Tester::Tester(int id, std::string name, double salary, Project *project) {
  this->setId(id);
  this->setName(name);
  this->setSalary(salary);
  this->setPayment(0);
  this->setAddPayment(0);
  this->setPosition(TESTER);
  this->setWorkTime(0);
  this->setProject(project);
  this->errorsFound = 0;
  project->setNumOfWorkers(project->getNumOfWorkers() + 1);
}
void Tester::calcProAdditions() {
  this->setAddPayment(this->getAddPayment() + (250 * errorsFound));
}
double TeamLeader::calcHeads() {
  this->setAddPayment(this->getAddPayment() +
      (1456 * this->getProject()->getNumOfWorkers()));
}
TeamLeader::TeamLeader(int id, std::string name,
                       double salary, Project *project) {
  this->setId(id);
  this->setName(name);
  this->setSalary(salary);
  this->setPayment(0);
  this->setAddPayment(0);
  this->setPosition(TEAM_LEADER);
  this->setWorkTime(0);
  this->setProject(project);
  project->setNumOfWorkers(project->getNumOfWorkers() + 1);
}
void TeamLeader::calcProAdditions() {
}
