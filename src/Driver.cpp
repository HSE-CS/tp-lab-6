//  Copyright 2021 GHA created by Klykov Anton

#include "Driver.h"
#include <random>
#include <iostream>
#include <iomanip>

Driver::Driver(int id, std::string name, std::string position,
               int salary, int km)
    : Personal(id, name, position, salary) {
  kilometers = km;
}
int Driver::calcBonus() {
  std::random_device rd;
  std::mt19937 randomPeopleDeliver(rd());
  int peopleDeliver = static_cast<int>(randomPeopleDeliver() % 5);
  return 100 * peopleDeliver;
}
void Driver::calc() {
  int BasePayment = calcBase(m_salary, m_worktime);
  int BonusPayment = calcBonus();
  m_payment = BasePayment + BonusPayment;
}
void Driver::printinfo() {
  std::cout << std::setw(30) << m_name << std::setw(15)
            << m_position << std::setw(10) << m_payment << std::endl;
}
