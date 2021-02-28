// Copyright 2021 Kuznetsov Mikhail
#include "Employee.h"

Employee::Employee(unsigned int _id, std::string _name,
             POSITION _position) {
  id = _id;
  name = _name;
  position = _position;
}

void Employee::setWorktime(unsigned int _worktime) {
  worktime = _worktime;
}

unsigned int Employee::getId() {
  return id;
}

std::string Employee::getName() {
  return name;
}

POSITION Employee::getPosition() {
  return position;
}

std::string Employee::stringPosition() {
  std::string positionToString;
  switch (position) {
  case SENIORMANAGER:
    positionToString = "Senior manager";
    break;
  case PROJECTMANAGER:
    positionToString = "Project manager";
    break;
  case TEAMLEADER:
    positionToString = "Team leader";
    break;
  case PROGRAMMER:
    positionToString = "Programmer";
    break;
  case TESTER:
    positionToString = "Tester";
    break;
  case DRIVER:
    positionToString = "Driver";
    break;
  case CLEANER:
    positionToString = "Cleaner";
    break;
  default:
    positionToString = "Unknown";
    break;
  }
  return positionToString;
}

POSITION positionByString(std::string _stringPosition) {
  POSITION result;
  while (_stringPosition.back() == ' ' || _stringPosition.back() == '\n') {
    _stringPosition.pop_back();
  }
  if (_stringPosition == "Senior manager") {
    result = POSITION::SENIORMANAGER;
  } else if (_stringPosition == "Project manager") {
    result = PROJECTMANAGER;
  } else if (_stringPosition == "Team leader") {
    result = TEAMLEADER;
  } else if (_stringPosition == "Programmer") {
    result = PROGRAMMER;
  } else if (_stringPosition == "Tester") {
    result = TESTER;
  } else if (_stringPosition == "Driver") {
    result = DRIVER;
  } else if (_stringPosition == "Cleaner") {
    result = CLEANER;
  } else {
    result = UNKNOWN;
  }
  return result;
}

unsigned int Employee::getWorktime() {
  return worktime;
}

unsigned int Employee::getPayment() {
  return payment;
}
