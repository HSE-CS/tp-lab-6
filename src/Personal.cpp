// Copyright 2021 Galex

#include <iostream>
#include <string>
#include "../include/Personal.h"

double Personal::calcBase(double salary, int workTime) {
  return workTime * salary;
}
void Personal::printInfo() {
  std::cout << "ID: " << this->getId() <<
            " Name: " << this->getName() <<
            " Salary: " << this->getSalary() <<
            " Work Time: " << this->getWorkTime() <<
            " Position: " << this->getPosition() <<
            " Payment: " << this->getPayment() << "\n";
}
double Personal::getSalary() {
  return this->salary;
}
void Personal::setSalary(double salary) {
  this->salary = salary;
}
Cleaner::Cleaner(int id, std::string name, double salary) {
  this->setId(id);
  this->setName(name);
  this->setSalary(salary);
  this->setPayment(0);
  this->setPosition(CLEANER);
  this->setWorkTime(0);
}
void Cleaner::calc() {
  this->setPayment(this->getSalary() * this->getWorkTime());
}
double Cleaner::calcBonus() {
  return 0;
}
Driver::Driver(int id, std::string name, double salary) {
  this->setId(id);
  this->setName(name);
  this->setSalary(salary);
  this->setPayment(0);
  this->setPosition(DRIVER);
  this->setWorkTime(0);
  this->numOfNightShifts = 0;
}
void Driver::calc() {
  this->setPayment((this->getSalary() * this->getWorkTime()) + calcBonus());
}
double Driver::calcBonus() {
  return this->getNumOfNightShifts()*1000;
}
void Driver::setNumOfNightShifts(int num) {
  this->numOfNightShifts = num;
}
int Driver::getNumOfNightShifts() {
  return this->numOfNightShifts;
}
