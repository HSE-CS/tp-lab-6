// Copyright 2021 Ryzhova Irina

#include "Personal.h"

Personal::Personal(int payment, std::string name,
                   std::string position, int id, int salary)
                   : Employee(payment, name, position, id) {
  this->salary = salary;
}

int Personal::getSalary() {
  return salary;
}

void Personal::setSalary(int salary) {
  this->salary = salary;
}

int Personal::calc() {
  setSalary(calcBase(getPayment(), getWorktime()));
  return getSalary();
}

int Personal::calcBonus() {
  return 0;
}

int Personal::calcBase(int salary, int worktime) {
  return salary * worktime;
}

void Personal::printInfo() {
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "ID : " << getId() << std::endl;
  std::cout << "Name : " << getName() << std::endl;
  std::cout << "Position : " << getPosition() << std::endl;
  std::cout << "Work time : " << getWorktime() << std::endl;
  std::cout << "Payment : " << getPayment() << std::endl;
  std::cout << "Salary : " << getSalary() << std::endl;
}

Driver::Driver(int payment, std::string name,
               std::string position, int id, int salary)
               : Personal(payment, name, position, id, salary) {}

int Driver::calc() {
  setSalary(calcBase(getPayment(), getWorktime()) + calcBonus());
  return getSalary();
}

int Driver::calcBonus() {
  if (getWorktime() > 48)
    return 1000;
  return 0;
}

Cleaner::Cleaner(int payment, std::string name,
                 std::string position, int id, int salary)
                 : Personal(payment, name, position, id, salary) {}
