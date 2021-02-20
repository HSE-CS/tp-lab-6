// Copyright 2021 Arina Simonova

#include "Employee.h"

Employee::Employee(int _id, string _name, string _pos,
  int _workTime, int _payment) {
  id = _id;
  name = _name;
  position = _pos;
  workTime = _workTime;
  payment = _payment;
}

void Employee::SetWorkTime(int _workTime) {
  workTime = _workTime;
}

void Employee::SetPayment(int _payment) {
  payment = _payment;
}

int Employee::GetId() {
  return id;
}

string Employee::GetName() {
  return name;
}

string Employee::GetPosition() {
  return position;
}

int Employee::GetWorkTime() {
  return workTime;
}

int Employee::GetPayment() {
  return payment;
}

