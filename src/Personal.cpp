// Copyright 2020 Konina Tatiana
#include <string>
#include "Personal.h"
int driver_bonus = 5;
Personal::Personal (unsigned int id, std::string name,
                    int worktime, double salary, int position) 
                    : Employee (id, name, worktime, position){
  this->salary = salary;
}

void Personal::calc() {
  this->payment = calcBase() + calcBonus();
}

void Personal::printInfo() {
  std::cout << this->name << " " << this->position << std::endl;
  std::cout << "Current payment = " << this->payment << std::endl;
  std::cout << "Current work time = " << this->worktime <<std::endl;
}

int Personal::calcBase() {
  return this->salary * this->worktime;
}

int Personal::calcBonus(int bonus) {
  return bonus * this->salary;
}

Driver::Driver(unsigned int id, std::string name,
  int worktime, double salary, int position) :
  Personal(id, name, worktime, salary, position) {
  this->bonus = driver_bonus;
}

void Driver::calc() {
  this->payment = calcBase() + calcBonus(this->bonus);
}


Cleaner::Cleaner(unsigned int id, std::string name,
  int worktime, double salary, int position)
  : Personal(id, name, worktime, salary, position) {
}



