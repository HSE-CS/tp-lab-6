#include"Manager.h"
#include<iostream>
int ProjectManager::calcHeads() { return this->projects[0]->getNumber() * 1000; }
void ProjectManager::calc() {
  this->setPayment((this->projects[0]->getBudjet() / this->projects[0]->getNumber()) +
                   calcHeads());
}

void SeniorManager::calc() {
  int payment_ = 0;
  for (auto &project : projects) {
    payment_ += project->getBudjet() / project->getNumber();
    payment_ += project->getNumber * 1000;
  }
  this->setPayment(payment_);
}

void ProjectManager::printInfo() {
  std::cout << "ID: " << this->getId() << " "
            << "Name: " << this->getName() << "  "
            << "Position" << this->getPosition() << " ";
  std::cout << "Project:" << this->projects[0]->getName() << std::endl;
  std::cout << "\t"
            << "WorkTime: " << this->getWorkTime() << " "
            << "Payment: " << this->getPayment();
}


void SeniorManager::printInfo() {
  std::cout << "ID: " << this->getId() << " "
            << "Name: " << this->getName() << "  "
            << "Position" << this->getPosition() << " ";
  std::cout << "Projects:"
            << " ";
  for (auto &proj : projects) {
    std::cout << proj->getName() << ", ";
  }
  std::cout << "\t"
            << "WorkTime: " << this->getWorkTime() << " "
            << "Payment: " << this->getPayment();
}
