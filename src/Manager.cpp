// Copyright 2021 ArinaMonicheva

#include "Manager.h"

Project::Project(int id, double budget) {
  this->id = id;
  this->budget = budget;
  this->numOfStaff = 0;
}

int Project::getId() {
  return id;
}

double Project::getBudget() {
  return budget;
}

int Project::getStaffNum() {
  return numOfStaff;
}

void Project::updateStaffNum() {
  numOfStaff++;
}

ProjectManager::ProjectManager(int id, std::string name, std::string position,
 double payment, std::vector <Project*> newProjects) :
  Employee(id, name, position, payment) {
  projects = newProjects;
}

double ProjectManager::getCurrentBudget() {
  return calcHeads() + calc();
}

std::vector <Project*> ProjectManager::getProjects() {
  return projects;
}

double ProjectManager::calcHeads() {  // 10000 for each person under management
  return (projects[0]->getStaffNum() - 1) * 10000.0;  // except himself
}

double ProjectManager::calc() {  // quater of project budget
  return projects[0]->getBudget() * 0.25;
}

void ProjectManager::printInfo() {
  std::string info;
  info = std::to_string(getId()) + " " +
    getName() + "\nPosition: " + getPosition() +
    "\nPayment: " + std::to_string(getPayment()) +
    "\nNext salary: " + std::to_string(getCurrentBudget()) +
    " (current work time: " + std::to_string(getWorkTime()) + ")" +
    "\nCurrent project: " + std::to_string(projects[0]->getId()) + "\n";
  std::cout << info << std::endl;
}

SeniorManager::SeniorManager(int id, std::string name, std::string position,
 double payment, std::vector <Project*> newProjects) :
  ProjectManager(id, name, position, payment, newProjects) {
  numOfProjects = newProjects.size();
}

int SeniorManager::getNumOfProjects() {
  return numOfProjects;
}

void SeniorManager::addNewProject(Project* newProject) {
  for (int i = 0; i < getProjects().size(); i++) {
    if (newProject->getId() == getProjects()[i]->getId()) {
      return;
    }
  }

  getProjects().push_back(newProject);
  numOfProjects++;
}

double SeniorManager::calcHeads() {
  int all = 0;

  for (int i = 0; i < getProjects().size(); i++) {
    all += getProjects()[i]->getStaffNum();
  }

  return all * 10000.0;
}

double SeniorManager::calc() {
  double all = 0;

  for (int i = 0; i < getProjects().size(); i++) {
    all += getProjects()[i]->getBudget();
  }

  return all * 0.25;
}

void SeniorManager::printInfo() {
  std::string info;
  info = std::to_string(getId()) + " " +
    getName() + "\nPosition: " + getPosition() +
    "\nPayment: " + std::to_string(getPayment()) +
    "\nNext salary: " + std::to_string(getCurrentBudget()) +
    " (current work time: " + std::to_string(getWorkTime()) + ")" +
    "\nCurrent projects:\n";
  for (int i = 0; i < numOfProjects; i++) {
    info += " " + std::to_string(getProjects()[i]->getId()) + "\n";
  }
  std::cout << info << std::endl;
}
