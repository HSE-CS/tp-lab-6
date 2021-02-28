// Copyright 2021 Galex

#include "../include/Project.h"

Project::Project(int id, int budget) {
  this->id = id;
  this->budget = budget;
  this->numOfWorkers = 0;
}
int Project::getId() {
  return this->id;
}
int Project::getBudget() {
  return this->budget;
}
void Project::setId(int id) {
  this->id = id;
}
void Project::setBudget(int budget) {
  this->budget = budget;
}
int Project::getNumOfWorkers() {
  return this->numOfWorkers;
}
void Project::setNumOfWorkers(int num) {
  this->numOfWorkers = num;
}
