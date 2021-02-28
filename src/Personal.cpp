// Copyright 27.02.21 DenisKabanov

#include "Personal.h"

int Personal::getSalary() {
	return this->salary;
}

int Personal::calcBase(int salary, int worktime) {
  int baseSalary = salary * worktime;
  return baseSalary;
}

int Personal::calcBonus(int bonusCount = 0, int bonusPrice = 0) {
  int bonusSalary = bonusCount * bonusPrice;
  return bonusSalary;
};

void Personal::printInfo() {
  std::cout << "Name: " << getName() << " ID: " << getID()
            << "\nPosition: " << getPos() << " Salary: " << getPayment()
            << std::endl;
}

void Cleaner::calc() {
  setPayment(this->passivesalary + calcBase(getSalary(), getWorkTime()) + calcBonus(0, 0));
}

int Driver::getBonus() {
	return this->bonuses;
}

void Driver::addBonus(int count) {
	this->bonuses += count;
}

int Driver::calcBonus(int bonusCount = 0, int bonusPrice = 1000) {
  int bonusSalary = getBonus() * bonusPrice;
  return bonusSalary;
}

void Driver::calc() {
  setPayment(this->passivesalary + calcBase(getSalary(), getWorkTime()) +
             calcBonus(1, 1000));
}

