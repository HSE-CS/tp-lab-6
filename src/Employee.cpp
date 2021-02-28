// Copyright 2021 Galex

#include <string>
#include "../include/Employee.h"

int Employee::getId() {
  return this->id;
}
std::string Employee::getName() {
  return this->name;
}
POS Employee::getPosition() {
  return this->position;
}
int Employee::getWorkTime() {
  return this->workTime;
}
double Employee::getPayment() {
  return this->payment;
}
void Employee::setId(int id) {
  this->id = id;
}
void Employee::setName(std::string name) {
  this->name = name;
}
void Employee::setPosition(POS position) {
  this->position = position;
}
void Employee::setWorkTime(int workTime) {
  this->workTime = workTime;
}
void Employee::setPayment(double payment) {
  this->payment = payment;
}
double Employee::getAddPayment() {
  return this->addPayment;
}
void Employee::setAddPayment(double bonus) {
  this->addPayment = bonus;
}
