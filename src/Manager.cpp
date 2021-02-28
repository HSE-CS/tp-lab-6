// Copyright 2021 Egor Buzanov

#include "Manager.h"

unsigned int ProjectManager::calcHeads() { return subordinates_num * 10000; }

unsigned int ProjectManager::calcBudgetPart(double part, unsigned int budget) {
  return static_cast<unsigned int>(part * budget);
}

void ProjectManager::calc() {
  payment = calcHeads() + calcBudgetPart(part, projects[0]->budget);
}

void SeniorManager::calc() {
  payment = calcHeads();
  for (const auto& project : projects) {
    payment += calcBudgetPart(part, project->budget);
  }
}

ProjectManager::ProjectManager(int _id, std::string _name, int _sub_num,
                               Project* _project, double _part) {
  id = _id;
  name = _name;
  projects.push_back(_project);
  part = _part;
  position = PROJECT_MANAGER;
  worktime = 0;
  payment = 0;
  subordinates_num = _sub_num;
}

SeniorManager::SeniorManager(int _id, std::string _name, int _sub_num,
                             std::vector<Project*>& _projects, double _part) {
  id = _id;
  name = _name;
  part = _part;
  position = PROJECT_MANAGER;
  worktime = 0;
  payment = 0;
  subordinates_num = _sub_num;
  projects = _projects;
}

void ProjectManager::printInfo() {
  std::cout << id << " " << name << " " << position << " " << worktime << " "
            << payment << std::endl;
}
