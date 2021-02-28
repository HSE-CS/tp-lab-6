//  Copyright 2021 GHA created by Klykov Anton

#include "TeamLeader.h"
#include <iostream>
#include <iomanip>

TeamLeader::TeamLeader(int id, std::string name,
                       std::string position, int salary,
                       Project *project, float part,
                       bool Deadline, int people)
    : Programmer(id, name, position, salary, project, part, Deadline) {
  amountPeople = people;
}
int TeamLeader::calcHeads() {
  int HeadingAward = 8000;
  return amountPeople * HeadingAward;
}
void TeamLeader::calc() {
  int BasePayment = calcBase(m_salary, m_worktime);
  int ProjectBudget = m_project->p_budget;
  int BudgetPartPayment = calcBudgetPart(m_part, ProjectBudget);
  int HeadingPayment = calcHeads();
  m_payment = BasePayment + BudgetPartPayment + HeadingPayment;
}
void TeamLeader::printinfo() {
  std::cout << std::setw(30) << m_name << std::setw(15)
            << m_position << std::setw(10) << m_payment << std::endl;
}

