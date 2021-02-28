//  Copyright 2021 GHA created by Klykov Anton

#include "Programmer.h"
#include <iostream>
#include <iomanip>

Programmer::Programmer(int id, std::string name, std::string position,
                       int salary, Project *project, float part, int Deadline)
    : Engineer(id, name, position, salary, project, part) {
  p_deadline = Deadline;
}
int Programmer::calcProAdditions() {
  if (p_deadline) {
    int award = 7500;
    return award;
  } else {
    return 0;
  }
}
void Programmer::calc() {
  int BasePayment = calcBase(m_salary, m_worktime);
  int ProjectBudget = m_project->p_budget;
  int BudgetPartPayment = calcBudgetPart(m_part, ProjectBudget);
  int AdditionalPayment = calcProAdditions();
  m_payment = BasePayment + BudgetPartPayment + AdditionalPayment;
}
void Programmer::printinfo() {
  std::cout << std::setw(30) << m_name << std::setw(15)
            << m_position << std::setw(10) << m_payment << std::endl;
}

