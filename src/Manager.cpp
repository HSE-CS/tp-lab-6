// Copyright NikDemoShow 2021
#include"Manager.h"
void ProjectManager::printInfo() {
  Employee::printInfo();
  unsigned int setw1{10}, setw2{15};
  std::cout << "|" << std::setw(setw1 + setw2) << "Projects:"
            << "|" << std::endl;
  std::cout << "|" << std::setw(setw1) << "ID" << std::setw(setw2) << "Budget"
            << "|" << std::endl;
  for (Project* p : this->projects) {
    std::cout << "|" << std::setw(setw1) << p->getId() << std::setw(setw2)
              << p->getBudget() << "|" << std::endl;
  }
  std::cout << "+-------------------------+" << std::endl;
}
unsigned int ProjectManager::calcBudgetPart(const double part, const unsigned int budget) { return part*budget; }
unsigned int ProjectManager::calcHeads() { return this->subord * headsToMoney; }
unsigned int ProjectManager::calcProAdditions() { return 0; }
void ProjectManager::calc() {
  this->payment = this->calcHeads();
  for (Project* p : this->projects) {
    this->payment += this->calcBudgetPart(this->part, p->getBudget());
  }
}
