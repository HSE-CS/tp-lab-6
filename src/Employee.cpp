// Copyright 2021 Danyaev Artem
#include "Employee.h"

void Employee::setWorkTime(int t) {
  worktime = t;
}

Employee::Employee(unsigned int id_, const std::string& name_, Position pos)
  : id(id_), name(name_), position(pos) {}

unsigned int Employee::getId() { return id; }
std::string Employee::getName() { return name; }
Position Employee::getPosition() { return position; }
int Employee::getWorkTime() { return worktime; }
int Employee::getPayment() { return payment; }

Project::Project(unsigned int id_, const std::string& name_, int budget_)
  : id(id_), name(name_), budget(budget_) {}

std::string Project::getName() { return name; }
int Project::getBudget() { return budget; }
