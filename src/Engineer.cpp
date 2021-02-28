//  Copyright 2021 GHA created by Klykov Anton

#include "Engineer.h"
#include <iostream>
#include "iomanip"

Engineer::Engineer(int id, std::string name, std::string position,
                   int salary, Project* project, float part)
                  : Personal(id, name, position, salary) {
  m_project = project;
  m_part = part;
}
int Engineer::calcBonus() {
  return 0;
}
int Engineer::calcBudgetPart(float part, int budget) {
  return static_cast<int>(part * static_cast<float>(budget));
}
int Engineer::calcProAdditions() {
  return 0;
}
void Engineer::calc() {
  int BasePayment = calcBase(m_salary, m_worktime);
  int ProjectBudget = m_project->p_budget;
  int BudgetPartPayment = calcBudgetPart(m_part, ProjectBudget);
  m_payment = BasePayment + BudgetPartPayment;
}
void Engineer::printinfo() {
  std::cout << std::setw(30) << m_name << std::setw(15)
            << m_position << std::setw(10) << m_payment << std::endl;
}

