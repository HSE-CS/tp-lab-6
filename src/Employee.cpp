// Copyright 2020 Uskova

#include "Employee.h"
#include "Factory.h"
#include "Project.h"

Employee::Employee(int id, std::string name, Position position, int worktime) {
  this->id = id;
  this->name = name;
  this->position = position;
  this->worktime = worktime * 4;
  this->payment = 0;
}

Employee::Employee(int id, std::string name, Position position) {
  this->id = id;
  this->name = name;
  this->position = position;
  this->worktime = 0;
  this->payment = 0;
}

int Employee::getId() {
    return this->id;
}

std::string Employee::getName() {
    return this->name;
}

Position Employee::getPosition() {
    return this->position;
}

int Employee::getWorktime() {
    return this->worktime;
}

int Employee::getPayment() {
    return this->payment;
}

void Employee::setWorkTime(int time) {
    this->worktime = time;
}

std::string Employee::getStrPosition() {
  switch (this->position) {
    case Position::Tester:
      return "Tester";
      break;
    case Position::Programmer:
      return "Programmer";
      break;
    case Position::TeamLeader:
      return "TeamLeader";
      break;
    case Position::SeniorManager:
      return "SeniorManager";
      break;
    case Position::ProjectManager:
      return "ProjectManager";
      break;
    case Position::Driver:
      return "Driver";
      break;
    case Position::Cleaner:
      return "Cleaner";
      break;
    default:
      return "Is not a worker";
      break;
  }
}
