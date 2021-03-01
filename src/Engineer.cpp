// Copyright 2021 Tatsenko Ilya
#include"Engineer.h"

float Engineer::getPart() { 
    return this->part;
}

int Engineer::calcBudjetPart(float part, int budjet) { return static_cast<int>(budjet * part); }
int Engineer::calcProAdditions() {
  if (this->part > 0.21) return static_cast<int>(1000 * this->getPart());
  return 0;
}
void Engineer::calc() {
    this->setPayment(
      this->salary * this->getWorkTime() +
      this->calcBudjetPart(this->getPart(), this->project->getBudjet()) +
      this->calcProAdditions());
}


int Tester::calcProAdditions() { return 100 * this->k; }

int Programmer::calcProAdditions() {
  if (this->getWorkTime() < 8) return (this->calcBase(this->salary,((8-this->getWorkTime())*3)));
  return 0;
}

int TeamLeader::calcHeads() { return ((this->project->getNumber()) * 1000); }
void TeamLeader::calc() {
    this->setPayment(
      this->salary * this->getWorkTime() +
      this->calcBudjetPart(this->getPart(), this->project->getBudjet()) +
      this->calcHeads());
}