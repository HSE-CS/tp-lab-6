// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 27.02.2021.
//
#include "Employee.h"
#include <string>

Employee::Employee(int id, std::string name,
                   int workTime, Positions position) {
  this->id = id;
  this->name = std::move(name);
  this->payment = 0;
  this->position = position;
  this->workTime = workTime;
}

Project::Project(int id, int budget, int amountOfWorkers) {
  this->id = id;
  this->budget = budget;
  this->amountOfWorkers = amountOfWorkers;
}
int Project::getAmountOfWorkers() const {
  return this->amountOfWorkers;
}
int Project::getBudget() const {
  return this->budget;
}