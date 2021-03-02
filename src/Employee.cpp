// Copyright 2021 Shirokov Alexander
#include "Employee.h"

Employee::Employee(int id, std::string name, Position position) {
  this->id = id;
  this->name = name;
  this->position = position;
}

int Employee::getId() { return id; }
const std::string& Employee::getName() { return name; }
Position Employee::getPosition() { return position; }
int Employee::getWorkTime() { return workTime; }
int Employee::getPayment() { return payment; }

void Employee::setId(int id) { this->id = id; }
void Employee::setName(std::string name) { this->name = name; }
void Employee::setPos(Position position) { this->position = position; }
void Employee::setWorkTime(int workTime) { this->workTime = workTime; }
void Employee::setPayment(int payment) { this->payment = payment; }
