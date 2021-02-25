// Copyright 2021 by Bodrov Egor
#include "Employee.h"

Employee::Employee(int id, std::string name, std::string pos)
    : id {id},
      name {std::move(name)}, pos{std::move(pos)} {}

void Employee::setId(int id) { this->id = id; }
 
void Employee::setWorkTime(int worktime) { this->worktime = worktime; }

void Employee::setPayment(int payment) { this->payment = payment; }

void Employee::setName(std::string name) {
    this->name = std::move(name);
}

void Employee::setPos(std::string pos) {
    this->pos = std::move(pos);
}

int Employee::getId() { return this->id; }

int Employee::getWorkTime() { return this->worktime; }

int Employee::getPayment() { return this->payment; }

const std::string& Employee::getName() { return this->name; }

const std::string& Employee::getPos() { return this->pos; }
