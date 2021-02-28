//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include "Employee.h"

// * PROJECT *

Project::Project(int id, unsigned budget) {
  this->id = id;
  this->budget = budget;
}

int Project::getId() { return id; }

unsigned Project::getBudget() { return budget; }

void Project::setNewBudget(unsigned newBudget) {
  this->budget = newBudget;
}

void Project::setMembersNum(unsigned newMembersNum) {
  this->membersNum = newMembersNum;
}

unsigned Project::getMembersNum() { return membersNum; }

void Project::printInfo() {
  std::cout << "<ID: " << id << "> ";
  std::cout << "<Budget: " << budget << "> ";
  std::cout << "<Members: " << membersNum << ">" << std::endl;
}

// * EMPLOYEE *

const std::string Employee::positionToString
(Position position) const {
  switch (position) {
    case Position::Programmer: return "Programmer";
    case Position::Driver: return "Driver";
    case Position::Cleaner: return "Cleaner";
    case Position::Tester: return "Tester";
    case Position::TeamLeader: return "Team Leader";
    case Position::ProjectManager: return "Project Manager";
    case Position::SeniorManager: return "Senior Manager";
    default: return "[unknown]";
  }
}

Employee::Employee(int id, std::string name,
                   Position position, unsigned worktime) {
  this->id = id;
  this->name = name;
  this->position = position;
  this->worktime = worktime;
}

int Employee::getId() { return this->id; }

std::string Employee::getName() const { return this->name; }

Position Employee::getPosition() const { return this->position; }

unsigned Employee::getWorktime() const { return this->worktime; }

unsigned Employee::getPayment() {
  return calc();
}

void Employee::setWorktime(unsigned time) { this->worktime = time; }

void Employee::setPosition(Position position) { this->position = position; }

void Employee::printInfo() {
  std::cout << name << " (id: " << id << ")" << std::endl;
  std::cout << "<Position: " <<
  positionToString(this->position) << "> ";
  std::cout << "<Worktime: " << worktime << "> ";
  std::cout << "<Payment: " << payment << ">";
  std::cout << std::endl << std::endl;
}
