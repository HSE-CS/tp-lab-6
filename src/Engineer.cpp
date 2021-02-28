// Copyright DB 2021
#include "Engineer.h"

#include <utility>
#include <sstream>
#include <iostream>
#include "Factory.h"

int Engineer::calcBudgetPart(float part, int budget) {
  return project->budget / static_cast<int>(part);
}

void Engineer::printInfo() {
  std::stringbuf str;
  std::ostream stream(&str);
  stream << "Id: " << id << "\nName: " << name
         << "\n Position: " << getPosition() << "\n Project: " << project->name
         << "\n Work time: " << workTime << "\n Salary: " << salary
         << "\n Payment: " << payment << "\n";
  std::cout << str.str() << std::endl;
}

int Tester::calcProAdditions() { 
    return calcBase(salary, workTime) / 10; 
}

void Tester::calc() {
  payment = calcBase(salary, workTime) + calcBudgetPart(part, project->budget) +
            calcProAdditions();
}

int Programmer::calcProAdditions() { 
    return calcBase(salary, workTime) / 10; 
}

void Programmer::calc() {
  payment = calcBase(salary, workTime) + calcBudgetPart(part, project->budget) +
            calcProAdditions();
}

int TeamLeader::calcHeads() { 
    return 150; 
}

void TeamLeader::calc() {
  payment = calcBase(salary, workTime) + calcHeads() +
            calcBudgetPart(part, project->budget) + calcProAdditions();
}