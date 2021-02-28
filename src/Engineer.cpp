// Copyright 2021 Egor Buzanov

#include "Engineer.h"

unsigned int Engineer::calcBudgetPart(double part, unsigned int budget) {
  return static_cast<unsigned int>(part * budget);
}

void Engineer::calc() {
  payment = calcBase() + calcBudgetPart(part, project->budget);
}

void Engineer::printInfo() {
  std::cout << id << " " << name << " " << position << " " << worktime << " "
            << payment << " " << salary << " " << project->id << " " << part
            << std::endl;
}

unsigned int Programmer::calcProAdditions() { return 5000; }

void Programmer::calc() {
  payment =
      calcBase() + calcBudgetPart(part, project->budget) + calcProAdditions();
}

unsigned int Tester::calcProAdditions() { return 10000; }

void Tester::calc() {
  payment =
      calcBase() + calcBudgetPart(part, project->budget) + calcProAdditions();
}

unsigned int TeamLeader::calcHeads() { return 15000; }

void TeamLeader::calc() {
  payment = calcBase() + calcBudgetPart(part, project->budget) + calcHeads();
}

Engineer::Engineer(int _id, std::string _name, int _salary, Project *_project,
                   double _part) {
  id = _id;
  name = _name;
  salary = _salary;
  project = _project;
  part = _part;
  position = ENGINEER;
  worktime = 0;
  payment = 0;
}

Programmer::Programmer(int _id, std::string _name, int _salary,
                       Project *_project, double _part) {
  id = _id;
  name = _name;
  salary = _salary;
  project = _project;
  part = _part;
  position = PROGRAMMER;
  worktime = 0;
  payment = 0;
}

Tester::Tester(int _id, std::string _name, int _salary, Project *_project,
               double _part) {
  id = _id;
  name = _name;
  salary = _salary;
  project = _project;
  part = _part;
  position = TESTER;
  worktime = 0;
  payment = 0;
}

TeamLeader::TeamLeader(int _id, std::string _name, int _salary,
                       Project *_project, double _part) {
  id = _id;
  name = _name;
  salary = _salary;
  project = _project;
  part = _part;
  position = TEAMLEADER;
  worktime = 0;
  payment = 0;
}

Engineer::Engineer() {
  id = 0;
  name = "";
  payment = 0;
  worktime = 0;
  project = nullptr;
}

Programmer::Programmer() {
  id = 0;
  name = "";
  payment = 0;
  worktime = 0;
  project = nullptr;
}

unsigned int Engineer::calcProAdditions() { return 0; }
