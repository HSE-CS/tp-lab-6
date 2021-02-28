#include<iostream>
#include"Employee.h"


Employee::Employee(int id, std::string name, std::string position,
                   int worktime) {
  this->id = id;
  this->name = name;
  this->position = position;
  this->payment = 0;
  this->worktime = worktime;
}

/// void Employee::setWorkTime(int x) { this->worktime = x; }

void Employee::setId(int x) { this->id = x; }
int Employee::getId() { return this->id; }


void Employee::setWorkTime(int x) { this->worktime = x; }
double Employee::getWorkTime() { return this->worktime; }



void Employee::setName(std::string x) { this->name = x; }
std::string Employee::getName() { return this->name; }


void Employee::setPosition(std::string x) { this->position = x; }
std::string Employee::getPosition() { return this->position; }

double Employee::getPayment() { return this->payment; }
void Employee::setPayment(double x) { this->payment = x; }