// Copyright 2021 Kuznetsov Mikhail

#include "Engineer.h"

Engineer::Engineer(unsigned int _id, std::string _name,
                   POSITION _position, unsigned int _salary,
                   Project* _project)
  : Personal(_id, _name, _position, _salary), project(_project) {
}

void Engineer::calc() {
  payment = calcBase(salary, worktime) +
  calcBudgetPart(project->calcPart(position), project->budget) +
  calcProAdditions();
}

unsigned int Engineer::calcBudgetPart(float _part,
                                            unsigned int _budget) {
  return static_cast <unsigned int> (_part * _budget);
}

void Engineer::printInfo() {
  std::cout << "-----------------Employee card-----------------\n"
  << "id: " << id << "\nname: " << name
  << "\nposition: " << stringPosition() << "\nworktime: " << worktime
  << "\npayment: " << payment << "\nproject: " << project->id
  << "\n-----------------Employee card-----------------\n";
}

Project* Engineer::getProject() {
  return project;
}

Tester::Tester(unsigned int _id, std::string _name,
           POSITION _position, unsigned int _salary,
           Project* _project)
  : Engineer(_id, _name,
             _position, _salary, _project) {
}

unsigned int Tester::calcProAdditions() {
  unsigned int add = 0;
  add = calcBudgetPart(0.005, project->budget);
  return add;
}

Programmer::Programmer(unsigned int _id, std::string _name,
           POSITION _position, unsigned int _salary,
           Project* _project)
  : Engineer(_id, _name,
             _position, _salary, _project) {
}

unsigned int Programmer::calcProAdditions() {
  unsigned int add = 0;
  unsigned int bonusTime = worktime > 40 ? worktime - 40 : 0;
  float part = bonusTime * 0.002;
  add = calcBudgetPart(part, project->budget);
  return add;
}

TeamLeader::TeamLeader(unsigned int _id, std::string _name,
           POSITION _position, unsigned int _salary,
           Project* _project)
  : Programmer(_id, _name,
             _position, _salary, _project) {
}

unsigned int TeamLeader::calcHeads() {
  unsigned int people = 0;
  people += project->testers + project->programmers;
  return people * 5;
}

void TeamLeader::calc() {
  payment = calcBase(salary, worktime) +
  calcBudgetPart(project->calcPart(position), project->budget) +
  calcProAdditions() + calcHeads();
}
