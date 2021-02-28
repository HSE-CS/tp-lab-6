// Copyright 27.02.21 DenisKabanov

#include "Engineer.h"
#include "Factory.h"

Project* Engineer::getProject() {
  return this->projects;
}

int Engineer::calcProAdditions(int addCount = 0, int addPrice = 0) {
  int proAdd = addCount * addPrice;
  return proAdd;
}

int Engineer::calcBudgetPart(float Part, int Budget) {
  return static_cast<int>(Part * Budget);
}

void Engineer::calc() {
  setPayment(calcBase(getSalary(), getWorkTime()) +
             calcBudgetPart(0.1, getProject()->budget) + calcProAdditions(0,0));
}

void Engineer::printInfo() {
  std::cout << "Name: " << getName() << " ID: " << getID()
            << " Position: " << getPos()
            << "\nName of projects: " << getProject()->id
            << " Work time: " << getWorkTime() << " Salary: " << getPayment()
            << std::endl;
}

int Programmer::calcProAdditions(int addCount, int addPrice) {
  int proAdd = addCount * addPrice;
  return proAdd;
}

void Programmer::calc() {
  setPayment(calcBase(getSalary(), getWorkTime()) +
             calcBudgetPart(0.1, getProject()->budget) +
             calcProAdditions(1, 1000));
}

void Tester::setErrors(int error) {
  this->errorsCount = error;
}

int Tester::getErrors() {
	return this->errorsCount;
}

int Tester::calcProAdditions(int addCount = 0, int addPrice = 50) {
  int proAdd = getErrors() * addPrice;
	return proAdd;
}

void Tester::calc() {
  setPayment(calcBase(getSalary(), getWorkTime()) +
             calcBudgetPart(0.1, getProject()->budget) +
             calcProAdditions(50));
}

void Tester::printInfo() {
  std::cout << "Name: " << getName() << " ID: " << getID()
            << " Position: " << getPos()
            << "\nName of projects: " << getProject()->id
            << " Work time: " << getWorkTime()
            << " Errors finded: " << getErrors() << " Salary: " << getPayment()
            << std::endl;
}

void TeamLeader::addSub(int count) {
	this->bossOf = this->bossOf + count;
}

int TeamLeader::getSub() {
	return this->bossOf;
}

int TeamLeader::calcHeads(int salaryForSub = 5000) {
  int salaryForHeading = getSub() * salaryForSub;
	return salaryForHeading;
}

int TeamLeader::calcProAdditions(int addCount = 0, int addPrice = 0) {
  int proAdd = addCount * addPrice;
  return proAdd;
}

void TeamLeader::calc() {
  setPayment(calcBase(getSalary(), getWorkTime()) +
             calcBudgetPart(0.4, getProject()->budget) + calcHeads(5000));
}
