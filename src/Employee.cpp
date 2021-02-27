// Copyright 2021 Andrey Bakurskii

#include "Employee.h"

Emploeey::Emploeey(int new_id, std::string new_name, std::string new_position,
                   int new_worktime, int new_payment) {
  this->id = new_id;
  this->name = new_name;
  this->position = new_position;
  this->worktime = new_worktime;
  this->payment = new_payment;
}

Emploeey::~Emploeey() {
  this->id = 0;
  this->name = "";
  this->position = "";
  this->worktime = 0;
  this->payment = 0;
}

int Emploeey::getId() { return this->id; }

std::string Emploeey::getName() { return this->name; }

std::string Emploeey::getPosition() { return this->position; }

int Emploeey::getWorktime() { return this->worktime; }

int Emploeey::getPayment() { return this->payment; }

void Emploeey::setWorktime(int time) { this->worktime = time; }
