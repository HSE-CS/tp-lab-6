#include "Engineer.h"

#include "headers.h"

int Engineer::calcBudgetPart(float part, int budget) {
  return project->budget / static_cast<int>(part);
}

void Engineer::printInfo() {
  std::cout << "Employee fields: \n";
  std::cout << "\t"
            << "Id: " << getId() << '\n';
  std::cout << "\t"
            << "Name: " << getName() << '\n';
  std::cout << "\t"
            << "Position: " << getPosition() << '\n';
  std::cout << "\t"
            << "Work time: " << getWorktime() << '\n';
  std::cout << "\t"
            << "Salary: " << getSalary() << '\n';
  std::cout << "\t"
            << "Project: " << project->name << '\n';
}

int Tester::calcProAdditions() {
  return calcBase(getSalary(), getWorktime()) / 10;
}

int Tester::calc() {
  payment = calcBase(getSalary(), getWorktime()) +
            calcBudgetPart(part, project->budget) + calcProAdditions();
  return payment;
}

int Programmer::calcProAdditions() {
  return calcBase(getSalary(), getWorktime()) / 10;
}

int Programmer::calc() {
  payment = calcBase(getSalary(), getWorktime()) +
            calcBudgetPart(part, project->budget) + calcProAdditions();
  return payment;
}

int TeamLeader::calcHeads() { return 150; }

int TeamLeader::calc() {
  payment = calcBase(getSalary(), getWorktime()) + calcHeads() +
            calcBudgetPart(part, project->budget) + calcProAdditions();
  return payment;
}
