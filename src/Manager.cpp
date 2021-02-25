// Copyright 2021 Arina Simonova

#include "..\include\Manager.h"

void Project::setID(int _id) {
  id = _id;
}

void Project::setBudget(int _budget) {
  budget = _budget;
}

Project::Project() {
  id = -1;
  budget = -1;
}

Project::Project(int _id, int _budget) {
  id = _id;
  budget = _budget;
}

int Project::GetId() {
  return id;
}

int Project::GetBudget() {
  return budget;
}

ProjectManager::ProjectManager(int _id, std::string _name, std::string _pos,
  int _workTime, int _payment, int _salary, Project _myProject)
  : Employee(_id, _name, _pos, _workTime, _payment) {
  myProject.setID(_myProject.GetId());
  myProject.setBudget(_myProject.GetBudget());
}

ProjectManager::ProjectManager(int _id, std::string _name, std::string _pos,
  int _workTime, int _payment, int _salary)
  : Employee(_id, _name, _pos, _workTime, _payment) {}

int ProjectManager::CalcBidgetPart(float part, int budget) {
  return static_cast<int>(part * budget);
}

int ProjectManager::calcProAdditions() {
  return CalcBidgetPart(0.15, myProject.GetBudget());
}

int ProjectManager::calcHeads() {
  return CalcBidgetPart(0.05, myProject.GetBudget());
}

int ProjectManager::GetSalary() {
  return 0;
}

int ProjectManager::Calc() {
  SetPayment(calcHeads() + calcProAdditions());
  return GetPayment();
}

void ProjectManager::PrintInfo() {
  std::cout << "id=" + std::to_string(GetId()) + ", name=" + GetName() +
    ", position=" + GetPosition() +
    ", work time=" + std::to_string(GetWorkTime()) +
    ", payment=" + std::to_string(GetPayment()) +
    ", salary=" + std::to_string(GetSalary()) +
    ", project id=" + std::to_string(myProject.GetId()) +
    ", budget=" + std::to_string(myProject.GetBudget()) << std::endl;
}

SeniorManager::SeniorManager(int _id, std::string _name, std::string _pos,
  int _workTime, int _payment, int _salary, std::vector<Project> _Projects)
  : ProjectManager(_id, _name, _pos, _workTime, _payment, _salary) {
  Projects = _Projects;
}

int SeniorManager::calcHeads() {
  int i, res = i = 0;
  for (i; i < Projects.size(); ++i)
    res += CalcBidgetPart(0.1, Projects[i].GetBudget());
  return res;
}

int SeniorManager::calcProAdditions() {
  int i, res = i = 0;
  for (i; i < Projects.size(); ++i) {
    res += CalcBidgetPart(0.2, Projects[i].GetBudget());
  }
  return res;
}

void SeniorManager::PrintInfo() {
  int i;
  std::cout << "id=" + std::to_string(GetId()) + ", name=" + GetName() +
    ", position=" + GetPosition() +
    ", work time=" + std::to_string(GetWorkTime()) +
    ", payment=" + std::to_string(GetPayment()) +
    ", salary=" + std::to_string(GetSalary()) + " projects: ";
  for (i = 0; i < Projects.size(); ++i) {
    std::cout << "project id=" + std::to_string(Projects[i].GetId()) +
      ", budget=" + std::to_string(Projects[i].GetBudget()) << std::endl;
  }
}
