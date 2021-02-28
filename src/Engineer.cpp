// Copyright 2021 Ryzhova Irina

#include "../include/Engineer.h"

Project::Project(int id, double budget) {
  this->id = id;
  this->budget = budget;
}

int Project::getId() {
  return id;
}

double Project::getBudget() {
  return budget;
}

int Project::getCount() {
  return count;
}

void Project::setCount() {
  count += 1;
}

Engineer::Engineer(int id, std::string name, int payment, int salary,
                   std::string position, Project* project)
                   : Personal(payment, name, position, id, salary) {
  this->project = project;
  this->project->setCount();
}

Project* Engineer::getProject() {
  return project;
}

int Engineer::calc() {
  float part = project->getBudget() * 0.5 / project->getCount();
  setSalary(calcBudgetPart(part, project->getBudget()) +
            calcBase(payment, worktime));
  return getSalary();
}

int Engineer::calcBudgetPart(float part, int budget) {
  return part * budget;
}

void Engineer::printInfo() {
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "ID : " << getId() << std::endl;
  std::cout << "Name : " << getName() << std::endl;
  std::cout << "Position : " << getPosition() << std::endl;
  std::cout << "Work time : " << getWorktime() << std::endl;
  std::cout << "Payment : " << getPayment() << std::endl;
  std::cout << "Salary : " << getSalary() << std::endl;
  std::cout << "Project id : " << project->getId() << std::endl;
  std::cout << "Project budget : " << project->getBudget() << std::endl;
  std::cout << "Project participants : " << project->getCount() << std::endl;
}

Programmer::Programmer(int id, std::string name, int salary,
             std::string position, int payment, Project* project)
             : Engineer(id, name, payment, salary, position, project) {}

int Programmer::calc() {
  float part = getProject()->getBudget() * 0.5 / getProject()->getCount();
  setSalary(calcBudgetPart(part, getProject()->getBudget()) +
            calcBase(payment, worktime) + calcProAdditions());
  return getSalary();
}

int Programmer::calcProAdditions() {
  int safedTime = 4;
  return safedTime * payment;
}

Tester::Tester(int id, std::string name, int salary,
             std::string position, int payment, Project* project)
             : Engineer(id, name, payment, salary, position, project) {}

int Tester::calc() {
  float part = getProject()->getBudget() * 0.5 / getProject()->getCount();
  setSalary(calcBudgetPart(part, getProject()->getBudget()) +
            calcBase(payment, worktime) + calcProAdditions());
  return getSalary();
}

int Tester::calcProAdditions() {
  int errors = 140;
  return errors / 10 * payment;
}

TeamLeader::TeamLeader(int id, std::string name, int salary,
             std::string position, int payment, Project* project)
             : Programmer(id, name, salary, position, payment, project) {}

int TeamLeader::calc() {
  float part = getProject()->getBudget() * 0.5 / getProject()->getCount();
  setSalary(calcBudgetPart(part, getProject()->getBudget()) +
            calcBase(payment, worktime) + calcHeads());
  return getSalary();
}

int TeamLeader::calcHeads() {
  return getProject()->getCount() * payment * 0.9;
}
