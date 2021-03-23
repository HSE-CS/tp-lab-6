// Copyright 2021 Lab_6 TiNa
#include "Employee.h"
#include <iostream>
#include <string>

Employee::Employee(int id, std::string name, std::string position, int worktime,
    int payment) {
  this->id = id;
  this->name = name;
  this->position = position;
  this->worktime = worktime;
  this->payment = payment;
}

int Employee::getId() { return id; }

int Employee::getWorktime() { return worktime; }

int Employee::getPayment() { return payment; }

std::string Employee::getName() { return name; }

std::string Employee::getPosition() { return position; }

void Employee::setId(int id) { this->id = id; }

void Employee::setWorktime(int worktime) { this->worktime = worktime; }

void Employee::setPayment(int payment) { this->payment = payment; }

void Employee::setName(std::string name) { this->name = name; }

void Employee::setPosition(std::string position) { this->position = position; }
