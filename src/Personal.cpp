// Copyright 2021 Arina Simonova

#include "Personal.h"

Personal::Personal(int _id, std::string _name, std::string _pos, int _workTime,
  int _payment, int _salary)
  : Employee(_id, _name, _pos, _workTime, _payment) {
  salary = _salary;
}

void Personal::SetSalary(int _salary) {
  salary = _salary;
}

int Personal::calcBase(int salary, int wtime) {
  return salary * wtime;
}

int Personal::calcBonus() {
  return 0;
}

int Personal::GetSalary() {
  return salary;
}

void Personal::PrintInfo() {
  std::cout << "id=" + std::to_string(GetId()) + ", name=" + GetName() +
    ", position=" + GetPosition() +
    ", work time=" + std::to_string(GetWorkTime()) +
    ", payment=" + std::to_string(GetPayment()) +
    ", salary=" + std::to_string(salary) << std::endl;
}

int Personal::Calc() {
  SetPayment(calcBase(GetSalary(), GetWorkTime()) + calcBonus());
  return GetPayment();
}

Driver::Driver(int _id, std::string _name, std::string _pos, int _workTime,
  int _payment, int _salary)
  : Personal(_id, _name, _pos, _workTime, _payment, _salary) {}


int Driver::calcBonus() {
  /*
  * в неделе 40 рабочих часов, за остальное доплата
  */
  return GetWorkTime() > 40 ? 20 * (GetWorkTime() - 40) : 0;
}

Cleaner::Cleaner(int _id, std::string _name, std::string _pos,
  int _workTime, int _payment, int _salary)
  : Personal(_id, _name, _pos, _workTime, _payment, _salary) {}
