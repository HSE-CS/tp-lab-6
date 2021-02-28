// Copyright 2021 Kuznetsov Mikhail

#include "Manager.h"

Project::Project(unsigned int _id, unsigned int _budget)
  : id(_id), budget(_budget) {
}

float Project::calcPart(POSITION _position) {
  unsigned int weightSum = 5 * testers
  + 6 * programmers + 10 + 9 + 10;
  //  10 - teamleader, 9 - projectmanager, 10 - seniormanager
  float part;
  switch (_position) {
	case SENIORMANAGER:
		part = static_cast<float> (12.0 / weightSum);
		break;
	case PROJECTMANAGER:
		part = static_cast<float> (9.0 / weightSum);
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
  return people * 45;
}

unsigned int ProjectManager::calcBudgetPart(float _part,
                                            unsigned int _budget) {
  return static_cast <unsigned int> (_part * _budget);
}

unsigned int ProjectManager::calcProAdditions() {
  unsigned int add = 0;
  for (auto p : projects)
    add += calcBudgetPart(0.3, p->budget);
  return add;
}

SeniorManager::SeniorManager(unsigned int _id, std::string _name,
              POSITION _position, std::vector<Project*> _projects)
  : ProjectManager(_id, _name, _position, _projects) {
}


void ProjectManager::printInfo() {
  std::cout << "-----------------Employee card-----------------\n"
  << "id: " << id << "\nname: " << name
  << "\nposition: " << stringPosition() << "\nworktime: " << worktime
  << "\npayment: " << payment
  << "\n-----------------Employee card-----------------\n";
}

