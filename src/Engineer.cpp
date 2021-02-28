//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include "Engineer.h"

// * ENGINEER *

Project* Engineer::getProject() { return project; }

void Engineer::setProjectPart(float part) { this->projectPart = part; }

void Engineer::setProject(Project* project) { this->project = project; }

unsigned Engineer::calcBudgetPart(float part, unsigned budget) {
  return budget * part;
}

unsigned Engineer::calcProAdditions() {
  return 0;
}

unsigned Engineer::calc() {
  this->payment = calcBase(salary, worktime)
  + calcBudgetPart(projectPart, project->getBudget())
  + calcProAdditions();
  return this->payment;
}

// * PROGRAMMER *

unsigned Programmer::calcProAdditions() {
  return aheadCounter * salary * 0.05;
}

void Programmer::setAheadCounter(unsigned newCounter) {
  this->aheadCounter = newCounter;
}

// * TESTER *

unsigned Tester::calcProAdditions() {
  return bugsCounter * salary * 0.01;
}

void Tester::setBugsCounter(unsigned int newCounter) {
  this->bugsCounter = newCounter;
}

// * TEAM LEADER *

unsigned TeamLeader::calc() {
  this->payment = calcBase(salary, worktime)
  + calcBudgetPart(projectPart, project->getBudget())
  + calcHeads();
  return this->payment;
}

unsigned TeamLeader::calcHeads() {
  return project->getMembersNum() * salary * 0.1;
}
