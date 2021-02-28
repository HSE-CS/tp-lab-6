//  Copyright 2021 GHA created by Klykov Anton

#include "Tester.h"
#include <random>
#include <iostream>
#include <iomanip>

Tester::Tester(int id, std::string name, std::string position, 
               int salary, Project *project, float part)
              : Engineer(id, name, position, salary, project, part) {

}
int Tester::calcProAdditions() {
  std::random_device rd;
  std::mt19937 CompleteTaskInDeadline(rd());  // 0 - нет, 1 - да
  bool DoAwardPayment = static_cast<bool>(CompleteTaskInDeadline() % 2);
  if (DoAwardPayment) {
    int award = 5500;
    return award;
  } else {
    return 0;
  }
}
void Tester::calc() {
  int BasePayment = calcBase(m_salary, m_worktime);
  int ProjectBudget = m_project->p_budget;
  int BudgetPartPayment = calcBudgetPart(m_part, ProjectBudget);
  int AdditionalPayment = calcProAdditions();
  m_payment = BasePayment + BudgetPartPayment + AdditionalPayment;
}
void Tester::printinfo() {
  std::cout << std::setw(30) << m_name << std::setw(15) 
            << m_position << std::setw(10) << m_payment << std::endl;
}

