// Copyright 2021 Tatsenko Ilya
#include "Personal.h"
#include <iostream>

double Personal::calcBase(int salary, int wtime) { return (salary * wtime); }
double Personal::calcBonus() { return 0.0; }
void Personal::calc() {
  this->setPayment(this->calcBase(this->salary, this->getWorkTime()) +
                   this->calcBonus());
}

void Personal::printInfo() {
  std::cout << "ID: " << this->getId() << "-> "
            << "Name: " << this->getName() << " ~ "
            << "Position " << this->getPosition() << std::endl;
  std::cout << "\t"
            << "WorkTime: " << this->getWorkTime() << " | "
            << "Payment: " << this->getPayment();
  std::cout << std::endl;
}

double Driver::calcBonus() {
  if (this->getWorkTime() > 8) {
    return ((this->getWorkTime() - 8) * this->salary * 0, 3);
  }
}

double Cleaner::calcBonus() { return 0; }
