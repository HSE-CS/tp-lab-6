//// Copyright 2021 Ozhiganova Polina
#include "Employee.h"

Project::Project(std::string id, int budget) {
  this->id = std::move(id);
  this->budget = budget;
}

Employee::Employee(int id, std::string name,
                   std::string position,
                   int payment) {
  this->id = id;
  this->name = std::move(name);
  this->position = std::move(position);
  this->payment = payment;
}

Employee::Employee(int id, const std::string& name,
                   const std::string& position) {
  this->id = id;
  this->name = name;
  this->position = position;
}

Employee::~Employee() {
  this->id = 0;
  this->name = nullptr;
  this->position = nullptr;
  this->payment = 0;
}

Employee::Employee(const Employee & newE) {
  this->id = newE.id;
  this->name = newE.name;
  this->position = newE.position;
  this->worktime = newE.worktime;
  this->payment = newE.payment;
}

void Employee::setWorkTime(int workTime) {
  this->worktime = workTime;
}

void Employee::setSalary(int sal) {
  this->salary = sal;
}

int Employee::getWorkTime() const {
  return this->worktime;
}

int Employee::getPayment() const {
  return this->payment;
}

int Employee::getId() const {
  return this->id;
}

std::string &Employee::getName() {
  return this->name;
}

std::string &Employee::getPosition() {
  return this->position;
}

int Employee::getSalary() const {
  return this->salary;
}
