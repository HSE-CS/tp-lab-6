// Copyright 2021 alexgiving

#include "Manager.h"

ProjectManager::ProjectManager() = default;

ProjectManager::ProjectManager(size_t _id, std::string _name,
                               size_t _worktime, Project* _project,
                               size_t _heads) {
  this->setId(_id);
  this->setName(std::move(_name));
  this->setWorkTime(_worktime);
  this->setPosition(2);
  this->projects = new std::vector<Project*>;
  this->setProject(_project);
  this->calcHeads(_heads);
  this->setPayment(getHeads() * 50);
}

void ProjectManager::setPart(float _part) {
  this->part = _part;
}

void ProjectManager::setProject(Project* _project) {
  this->projects->push_back(_project);
}

void ProjectManager::calcHeads(size_t _heads) {
  this->heads = _heads;
}

float ProjectManager::getPart() const {
  return this->part;
}

size_t ProjectManager::getHeads() const {
  return this->heads;
}

std::vector<Project*>* ProjectManager::getProjects() {
  return this->projects;
}

float ProjectManager::calcPM() {
  return (getPart() * getBudget() + getPayment());
}

SeniorManager::SeniorManager() = default;

SeniorManager::SeniorManager(size_t _id, std::string _name, size_t _worktime,
                             std::vector<Project*>* _projects) {
  this->setId(_id);
  this->setName(std::move(_name));
  this->setWorkTime(_worktime);
  this->setPosition(1);
  for (auto project : *_projects)
    this->setProject(project);
  this->setPayment(this->calc());
}

size_t SeniorManager::calc() {
  return (this->getHeads() * 50);
}
