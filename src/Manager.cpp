// Copyright 2021 Pavlova D.

#include <Manager.h>

int ProjectManager::calcHeads()  {
return allProjects[0]->team * 1000;
};

int ProjectManager::calcBudgetPart(float _part, int _budget) {
return static_cast<int>(_part * static_cast<float>(_budget));
};

int ProjectManager::calcProAdditions() {
  return 50;
}

void ProjectManager::calc() {
payment =  calcHeads() + calcBudgetPart(part, allProjects[0]->Budget);
};

void ProjectManager::printInfo() {
std::cout<< "id: " << getId() << "\n" << "name: " << getName() << "\nPosition: " << getPosition() << "\nWorktime: " << worktime << "\nPayment: " << payment << std::endl;
}
