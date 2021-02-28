//  Copyright 2021 GHA created by Klykov Anton

#include "Manager.h"
#include <iostream>
#include <iomanip>

ProjectManager::ProjectManager(int id,
                               std::string name,
                               std::string position,
                               Project* project,
                               float part)
                              : Employee(id, name, position) {
  pm_part = part;
  pm_project = project;
}
int ProjectManager::calcHeads() {
  int awardHeads = 10000;
  return awardHeads;
}
int ProjectManager::calcBudgetPart(float part, int budget) {
  return static_cast<int>(part * static_cast<float>(budget));
}
int ProjectManager::calcProAdditions() {
  return 0;
}
void ProjectManager::calc() {
  int HeadPayment = calcHeads();
  int ProjectPayment = calcBudgetPart(pm_part, pm_project->p_budget);
  m_payment = HeadPayment + ProjectPayment;
}
// ProjectsManager
void ProjectManager::printinfo() {
  std::cout << std::setw(30) << m_name << std::setw(15)
            << m_position << std::setw(10) << m_payment << std::endl;
}
SeniorManager::SeniorManager(int id,
                             std::string name,
                             std::string position,
                             Project* project,
                             float part,
                             std::vector<Project*> projects)
                             : ProjectManager(id,
                                              name,
                                              position,
                                              project,
                                              part) {
  sm_projects = std::move(projects);
}
int SeniorManager::calcHeads() {
  int awardHeads = 50000;
  return awardHeads;
}
int SeniorManager::calcBudgetPart(float part, int budget) {
  return static_cast<int>(part * static_cast<float>(budget));
}
void SeniorManager::calc() {
  int HeadPayment = calcHeads();
  int i{0};
  int ProjectPayment{0};
  for (; i < sm_projects.size(); ++i) {
    ProjectPayment += calcBudgetPart(pm_part, sm_projects[i]->p_budget);
  }
  m_payment = HeadPayment + ProjectPayment;
}
void SeniorManager::printinfo() {
  std::cout << std::setw(30) << m_name << std::setw(15)
            << m_position << std::setw(10) << m_payment << std::endl;
}

