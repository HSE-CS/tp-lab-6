//// Copyright 2021 Ozhiganova Polina
#include "Manager.h"

int ProjManager::calc() {
  int additionalBonus = calcProAdditions();
  int budgPart = calcBudgetPart(0.3, getProject()->budget);
  int salHead = calcHeads();
  int sal = additionalBonus + budgPart + salHead;
  setSalary(sal);
  return sal;
}

int ProjManager::calcBudgetPart(double part, int budget) {
  return floor(part * budget);
}

int ProjManager::calcProAdditions() {
  int wt = getWorkTime();
  int salHeads = calcHeads();
  if (wt > 40) {  // если работал больше 8 часов в день
    return salHeads * 30 / 100;  // + 30% от heads
  } else {
    return 0;
  }
}

int ProjManager::calcHeads() {
  double headAddings = 0.08;
  return floor(getProject()->budget * headAddings);
}

Project *ProjManager::getProject() {
  return project;
}

void ProjManager::printInfo() {
  int pmId = getId();
  std::string pmName = getName();
  std::string pmPosition = getPosition();
  int pmWorkTime = getWorkTime();
  int pmSalary = getSalary();
  std::string projId = getProject()->id;
  int projBudget = getProject()->budget;
  std::cout << "POSITION:  *** " << pmPosition << " ***" << std::endl;
  std::cout << "ID: " << std::to_string(pmId) << std::endl;
  std::cout << "NAME: " << pmName << std::endl;
  std::cout << "WORK TIME: " << pmWorkTime << std::endl;
  std::cout << "SALARY: " + std::to_string(pmSalary) << std::endl;
  std::cout << "PROJECT:" << std::endl;
  std::cout << "    id: " + projId << std::endl;
  std::cout << "    budget: " + std::to_string(projBudget) << "\n\n";
}

/* SeniorManager */
int SeniorManager::calc() {
  int additionalBonus = calcProAdditions();
  int budgPart = 0;
  for (auto &pr : projects) {
    budgPart += calcBudgetPart(0.3, pr->budget);
  }
  int salHead = calcHeads();
  int sal = additionalBonus + budgPart + salHead;
  setSalary(sal);
  return sal;
}

int SeniorManager::calcBudgetPart(double part, int budget) {
  return floor(part * budget);
}

int SeniorManager::calcProAdditions() {
  int wt = getWorkTime();
  int salHeads = calcHeads();
  if (wt > 40) {  // если работал больше 8 часов в день
    return salHeads * 35 / 100;  // + 35% от heads
  } else {
    return 0;
  }
}

int SeniorManager::calcHeads() {
  double headAddings = 0.1;
  int budgHeads = 0;
  for (auto &pr : projects) {
    budgHeads += floor(pr->budget * headAddings);
  }
  return budgHeads;
}

std::string SeniorManager::getStrProjs() {
  std::string s;
  for (auto &proj : projects) {
    s += "    id: " + proj->id
        + " <-> budget: " + std::to_string(proj->budget) + "\n";
  }
  return s;
}

void SeniorManager::printInfo() {
  int pmId = getId();
  std::string pmName = getName();
  std::string pmPosition = getPosition();
  int pmWorkTime = getWorkTime();
  int pmSalary = getSalary();
  std::cout << "POSITION:  *** " << pmPosition << " ***" << std::endl;
  std::cout << "ID: " << std::to_string(pmId) << std::endl;
  std::cout << "NAME: " << pmName << std::endl;
  std::cout << "WORK TIME: " << pmWorkTime << std::endl;
  std::cout << "SALARY: " + std::to_string(pmSalary) << std::endl;
  std::cout << "PROJECTS:" << std::endl;
  std::cout << getStrProjs() << "\n\n";
}
