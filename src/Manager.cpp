// Copyright 2021 Ryzhova Irina

#include "Manager.h"

ProjectManager::ProjectManager(int id, std::string name, int payment,
            std::string position, std::vector <Project*> projects)
            : Employee(payment, name, position, id) {
  this->projects = projects;
}

Project* ProjectManager::getProject() {
  return projects[0];
}

int ProjectManager::calc() {
  return calcHeads(getProject()->getCount()) +
         calcBudgetPart(0.25, getProject()->getBudget());
}

int ProjectManager::calcHeads(int count) {
  return count * getPayment();
}

int ProjectManager::calcBudgetPart(float part, int budget) {
  return part * budget;
}

void ProjectManager::printInfo() {
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "ID : " << getId() << std::endl;
  std::cout << "Name : " << getName() << std::endl;
  std::cout << "Position : " << getPosition() << std::endl;
  std::cout << "Work time : " << getWorktime() << std::endl;
  std::cout << "Payment : " << getPayment() << std::endl;
  std::cout << "Salary : " << calc() << std::endl;
  for (auto project : projects) {
    std::cout << "Project id : " << project->getId() << std::endl;
    std::cout << "Project budget : " << project->getBudget() << std::endl;
    std::cout << "Project participants : " << project->getCount() << std::endl;
  }
}

SeniorManager::SeniorManager(int id, std::string name, int payment,
            std::string position, std::vector <Project*> projects)
            : ProjectManager(id, name, payment, position, projects) {}

int SeniorManager::calc() {
  int res = 0;
  for (auto project : projects) {
    res += calcHeads(project->getCount()) +
           calcBudgetPart(0.25, project->getBudget());
  }
  return res;
}
