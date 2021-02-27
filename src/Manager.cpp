// Copyright 2020 Polina Lukicheva

#include "Manager.h"
#include "iostream"

int ProjectManager::calcHeads() {
  return static_cast<int>(getProject().budget * 0.01);
}


Project ProjectManager::getProject()
{

    return Project{ 0, 0 };
  
  return *projects[0];
}

int ProjectManager::calc() {
  return getPayment() * getWorkTime() + calcProAdditions();
}
int ProjectManager::calcBudgetPart(float part, int budget) {
  return part * budget;
}
int ProjectManager::calcProAdditions() {
  /*if (getProject() !)*/
  return ProjectManager::calcBudgetPart(0.2, getProject().budget);
}

void ProjectManager::printInfo() {
  {
    std::cout << "{id=" + std::to_string(getId()) +
      ", name=" + getName() +
      ", position=" + getPosition() +
      ", payment=" + std::to_string(getPayment()) +
      ", salary" + std::to_string(calc()) +
      ", project id " + std::to_string(getProject().id) +
      ", project budget " + std::to_string(getProject().budget) << std::endl;
  }
}
int SeniorManager::calc() {
  return ProjectManager::calc();
}

void SeniorManager::printInfo() {

  std::cout << "id " + std::to_string(getId()) +
    ", name " + getName() + 
    ", position " + getPosition() +
    ", payment " + std::to_string(getPayment()) +
    ", salary " + std::to_string(calc()) << std::endl;
}