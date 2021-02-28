// Copyright 2021 Ksuvot
#include <Personal.h>

int Personal::getSalary() {
  return this->salary;
}

void Personal::setSalary(int salary) {
  this->salary = salary;
}

int Personal::calcBase(int salary, int worktime) {
  return salary * worktime;
}

int Personal::calcBonus() {
  return 10;
}

void Personal::calc() {
  setPayment(calcBase(getPayment(), getWorktime())
  + calcBonus());
}

void Cleaner::calc() {
  setPayment(calcBase(getSalary(), getWorktime()));
}


int Driver::calcBonus() {
  return 100;
}

void Driver::calc() {
  setPayment(calcBase(getSalary(),
                      getWorktime()) + calcBonus());
}
