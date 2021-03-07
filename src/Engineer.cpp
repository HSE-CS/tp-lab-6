#include "Engineer.h"

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
Engineer::Engineer(int a, const std::string s, std::string d, int b, int c, Project* p, float f) : Personal(a, s, d, b, c) {
  project = p;
  part = f;
}
int Engineer::calcBudgetPart(float part, int budget) {
  return project->budget * this->part;
}

float Engineer::getPart() {
  return part;
}

void Engineer::printInfo() {
  std::cout << std::endl
            << this->get_id() << " - " << this->get_name() << " - "
            << this->get_position() << "\nSalary = " << this->get_salary()
            << "\nWorktime = " << this->get_worktime()
            << "\nFinal payment = " << this->calc() << std::endl;
}
Tester::Tester(int a, const std::string s, std::string d, int b, int c, Project* p, float f) : Engineer(a, s, d, b, c, p, f) {
}
int Tester::calcProAdditions() {
  return calcBase(get_salary(), get_worktime()) / 15;
}

int Tester::calc() {
  payment = calcBase(get_salary(), get_worktime()) +
            calcBudgetPart(part, project->budget) + calcProAdditions();
  return payment;
}
Programmer::Programmer(int a, const std::string s, std::string d, int b, int c, Project* p, float f) : Engineer(a, s, d, b, c, p, f) {
}
int Programmer::calcProAdditions() {
  return calcBase(get_salary(), get_worktime()) / 10;
}

int Programmer::calc() {
  payment = calcBase(get_salary(), get_worktime()) +
            calcBudgetPart(part, project->budget) + calcProAdditions();
  return payment;
}
TeamLeader::TeamLeader(int a, const std::string s, std::string d, int b, int c, Project* p, float f) : Programmer(a, s, d, b, c, p, f) {
}
int TeamLeader::calcHeads() { return 15000; }

int TeamLeader::calc() {
  payment = calcBase(get_salary(), get_worktime()) + calcHeads() +
            calcBudgetPart(part, project->budget) + calcProAdditions();
  return payment;
}

