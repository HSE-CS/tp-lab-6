// Copyright 2021 Kuznetsov Mikhail

#include "Manager.h"

Project::Project(unsigned int _id, unsigned int _budget)
  : id(_id), budget(_budget) {
}

float Project::calcPart(POSITION _position) {
  unsigned int weightSum = 5 * testers
  + 6 * programmers + 10 + 18 + 20;
  //  10 - teamleader, 18 - projectmanager, 20 - seniormanager
  float part;
  switch (_position) {
  case SENIORMANAGER:
    part = static_cast<float> (20.0 / weightSum);
    break;
  case PROJECTMANAGER:
    part = static_cast<float> (18.0 / weightSum);
    break;
  case TEAMLEADER:
    part = static_cast<float> (10.0 / weightSum);
    break;
  case PROGRAMMER:
    part = static_cast<float> (6.0 / weightSum);
    break;
  case TESTER:
    part = static_cast<float> (5.0 / weightSum);
    break;
  default:
    part = 0;
    break;
  }
  return part * 0.8;
}

ProjectManager::ProjectManager(unsigned int _id, std::string _name,
                  POSITION _position, std::vector <Project*> _projects)
  : Employee(_id, _name, _position) {
  projects = _projects;
}

void ProjectManager::calc() {
  for (auto p : projects) {
    payment += calcBudgetPart(p->calcPart(position), p->budget);
  }
  payment += calcProAdditions() + calcHeads();
}

unsigned int ProjectManager::calcHeads() {
  unsigned int people = 0;
  for (auto p : projects) {
    people += p->testers + p->programmers;
  }
  return people * 15;
}

unsigned int ProjectManager::calcBudgetPart(float _part,
                                            unsigned int _budget) {
  return static_cast <unsigned int> (_part * _budget);
}

unsigned int ProjectManager::calcProAdditions() {
  unsigned int add = 0;
  for (auto p : projects)
    add += static_cast <unsigned int> (calcBudgetPart(0.07, p->budget));
  return add;
}

std::vector<Project*> ProjectManager::getProjects() {
  return projects;
}

SeniorManager::SeniorManager(unsigned int _id, std::string _name,
              POSITION _position, std::vector<Project*> _projects)
  : ProjectManager(_id, _name, _position, _projects) {
}


void ProjectManager::printInfo() {
  std::cout << "-----------------Employee card-----------------\n"
  << "id: " << id << "\nname: " << name
  << "\nposition: " << stringPosition() << "\nworktime: " << worktime
  << "\npayment: " << payment << "\nprojects: ";
  for (auto p : projects)  {
    std::cout << p->id << " ";
  }
  std::cout << "\n-----------------Employee card-----------------\n";
}

