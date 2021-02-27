// Copyright 2021 alexgiving

#include "Engineer.h"

#include <utility>

Engineer::Engineer(size_t _id, std::string _name, size_t _worktime,
                   Project* _project, size_t _salary, float _part) {
  this->setId(_id);
  this->setName(std::move(_name));
  this->setWorkTime(_worktime);
  this->setPosition(5);
  this->setSalary(_salary);
  this->setProject(_project);
  this->setPart(_part);
  this->setPayment(this->calc());
}

void Engineer::setProject(Project* _project) {
  this->project = _project;
}

void Engineer::setPart(float _part) {
  this->part = _part;
}

Project* Engineer::getProject() {
  return (this->project);
}

float Engineer::getPart() const {
  return this->part;
}

float Engineer::calc() {
  return (this->calcBase() + this->calcBudgetPart(getPart()));
}

Programmer::Programmer(size_t _id, std::string _name, size_t _worktime,
                       Project* _project, size_t _salary, float _part,
                       bool _deadline) {
  this->setId(_id);
  this->setName(std::move(_name));
  this->setWorkTime(_worktime);
  this->setPosition(3);
  this->setSalary(_salary);
  this->setProject(_project);
  this->setPayment(this->calc());
  this->setDeadline(_deadline);
  this->setPart(_part);
}

void Programmer::setPart(float _part) {
  this->part = _part;
}

void Programmer::setDeadline(bool _deadline) {
  this->deadline = _deadline;
}

void Programmer::setProject(Project* _project) {
  this->project = _project;
}

float Programmer::calc() {
  return (static_cast<float>(this->calcProAdittions()) + this->calcBase()
      + this->calcBudgetPart(this->getPart()));
}

float Programmer::calcProAdittions() {
  if (this->getDeadline())
    return (this->calcBudgetPart(this->getPart() / 5));
  return 0;
}

float Programmer::getPart() const {
  return this->part;
}

bool Programmer::getDeadline() const {
  return this->deadline;
}

Tester::Tester(size_t _id, std::string _name, size_t _worktime,
               Project* _project, size_t _salary, float _part,
               size_t _bugs) {
  this->setId(_id);
  this->setName(std::move(_name));
  this->setWorkTime(_worktime);
  this->setPosition(4);
  this->setSalary(_salary);
  this->setProject(_project);
  this->setPayment(this->calc());
  this->setPart(_part);
  this->setBugs(_bugs);
}

void Tester::setPart(float _part) {
  this->part = _part;
}

void Tester::setProject(Project* _project) {
  this->project = _project;
}

void Tester::setBugs(size_t _bugs) {
  this->bugs = _bugs;
}

float Tester::getPart() const {
  return this->part;
}

size_t Tester::getBugs() const {
  return this->bugs;
}

float Tester::calc() {
  return (static_cast<float>(this->calcProAdittions()) + this->calcBase()
      + this->calcBudgetPart(this->getPart()));
}

unsigned Tester::calcProAdittions() {
  return (this->getBugs() * getSalary()/10);
}

TeamLeader::TeamLeader(size_t _id, std::string _name, size_t _worktime,
                       Project* _project, size_t _salary) {
  this->setId(_id);
  this->setName(std::move(_name));
  this->setWorkTime(_worktime);
  this->setPosition(0);
  this->setSalary(_salary);
  this->setProject(_project);
  this->setPayment(this->calc());
}

void TeamLeader::setProject(Project* _project) {
  this->project = _project;
}

void TeamLeader::setPart(float _part) {
  this->part = _part;
}

float TeamLeader::calc() {
  return (static_cast<float>(this->calcProAdittions()) + this->calcBase() +
      this->calcBudgetPart(getPart()) + TeamLeader::calcHeads());
}

float TeamLeader::getPart() const {
  return this->part;
}
size_t TeamLeader::calcProAdittions() {
  return (TeamLeader::calcHeads() + this->calcBudgetPart(getPart()) / 4);
}
size_t TeamLeader::calcHeads() {
  return 15;
}
