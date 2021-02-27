// Copyright 2021 alexgiving

#include "Project.h"

Project::Project() = default;

Project::Project(size_t _id, size_t _budget) {
  this->setProjectId(_id);
  this->setBudget(_budget);
}

void Project::setProjectId(size_t _id) {
  this->id = _id;
}

void Project::setBudget(size_t _budget) {
  this->budget = _budget;
}

size_t Project::getProjectId() const {
  return this->id;
}

size_t Project::getBudget() const {
  return this->budget;
}

float Project::calcBudgetPart(float _part) const {
  return (_part*this->budget);
}
