// Copyright 2021 Tatsenko Ilya
#include"Manager.h"
#include<iostream>
int ProjectManager::calcHeads() { return this->projects[this->n]->getNumber() * 1000; }
void ProjectManager::calc() {
  this->setPayment((this->projects[this->n]->getBudjet() / this->projects[this->n]->getNumber()) +
                   calcHeads());
}

void SeniorManager::calc() {
  int payment_ = 0;
  for (auto &project : projects) {
    payment_ += (project->getBudjet() / project->getNumber()) * 0.5;
    payment_ += project->getNumber() * 1000;
  }
  this->setPayment(payment_);
}

void ProjectManager::printInfo() {
  std::cout << "ID: " << this->getId() << " => "
            << "Name: " << this->getName() << "  "
            << "Position " << this->getPosition() << " >> ";
  std::cout << "Project: " << this->projects[0]->getName() << std::endl;
  std::cout << "\t"
            //<< "WorkTime: " << this->getWorkTime() << " "
            << "Payment: " << this->getPayment();
  std::cout << std::endl;
}


void SeniorManager::printInfo() {
  std::cout << "ID: " << this->getId() << " "
            << "Name: " << this->getName() << "  "
            << "Position " << this->getPosition() << " >>> ";
  std::cout << "Projects: "
            << " ";
  for (auto &proj : projects) {
    std::cout << proj->getName() << ", ";
  }
  std::cout << std::endl;
  std::cout << "\t"
            //<< "WorkTime: " << this->getWorkTime() << " "
            << "Payment: " << this->getPayment();
  std::cout << std::endl;
}
