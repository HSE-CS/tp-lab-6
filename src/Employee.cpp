//  Copyright 2021 GHA created by Klykov Anton

#include "Employee.h"
#include <random>

Employee::Employee(int id, std::string name, std::string position) {
  m_id = id;
  m_name = name;
  m_position = position;
}
int Employee::getWorkTime() const {
  return m_worktime;
}
int Employee::getPayment() const {
  return m_payment;
}
void Employee::setWorkTime() {
  std::random_device rd;
  std::mt19937 randomWorkTime(rd());
  int worktime = (static_cast<int>(randomWorkTime() % 40) + 20);
  m_worktime = worktime;
}
std::string Employee::getPosition() {
  return m_position;
}

