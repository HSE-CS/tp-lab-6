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

ProjectManager::ProjectManager(int _id, string _name, string _pos,
  int _workTime, int _payment, int _salary, Project _myProject)
  : Employee(_id, _name, _pos, _workTime, _payment) {
  myProject.setID(_myProject.GetId());
  myProject.setBudget(_myProject.GetBudget());
}

ProjectManager::ProjectManager(int _id, string _name, string _pos,
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
  cout << "id=" + to_string(GetId()) + ", name=" + GetName() +
    ", position=" + GetPosition() +
    ", work time=" + to_string(GetWorkTime()) +
    ", payment=" + to_string(GetPayment()) +
    ", salary=" + to_string(GetSalary()) +
    ", project id=" + to_string(myProject.GetId()) +
    ", budget=" + to_string(myProject.GetBudget()) << endl;
}

SeniorManager::SeniorManager(int _id, string _name, string _pos,
  int _workTime, int _payment, int _salary, vector<Project> _Projects)
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
  cout << "id=" + to_string(GetId()) + ", name=" + GetName() +
    ", position=" + GetPosition() +
    ", work time=" + to_string(GetWorkTime()) +
    ", payment=" + to_string(GetPayment()) +
    ", salary=" + to_string(GetSalary()) + " projects: ";
  for (i = 0; i < Projects.size(); ++i) {
    cout << "project id=" + to_string(Projects[i].GetId()) +
      ", budget=" + to_string(Projects[i].GetBudget()) << endl;
  }
}
