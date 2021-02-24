#include"Engineer.h"
unsigned Engineer::calcBudgetPart(const double part,
  const unsigned int budget) {
  return this->part * this->project->getBudget();
}
void Engineer::printInfo() { 
  Employee::printInfo(); 
  unsigned int setw1{10}, setw2{15};
  std::cout << "|" << std::setw(setw1 + setw2) << "Projects:"
            << "|" << std::endl;
  std::cout << "|" << std::setw(setw1) << "ID" << std::setw(setw2) << "Budget"
            << "|" << std::endl;
  std::cout << "|" << std::setw(setw1) << this->project->getId()
            << std::setw(setw2) << this->project->getBudget() << "|"
            << std::endl;
  std::cout << "+-------------------------+" << std::endl;
}
unsigned int Programmer::calcProAdditions() { return this->proAdd * this->proAddToMoney; }
unsigned int Tester::calcProAdditions() { return this->findError * this->findErrorToMoney; }
void Engineer::calc() {
  this->payment = this->calcProAdditions() + this->calcBase() +
                  this->calcBudgetPart(this->part, this->project->getBudget());
}
void TeamLeader::calc() {
  this->payment = this->calcProAdditions() + this->calcBase() +
                  this->calcBudgetPart(this->part, this->project->getBudget()) +
                  this->calcHeads();
}
unsigned int TeamLeader::calcHeads() { return this->subord * this->headsToMoney; }