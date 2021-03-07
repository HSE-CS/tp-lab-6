// Copyright 2021 Tatsenko Alexey
#include "Employee.h"

Employee::Employee(int id, std::string fi, Position position)
    : id(id), fi(fi), position(position) {
  payment = 0;
  worktime = 0;
}

void Employee::set_id(int id) { this->id = id; }
int Employee::get_id() { return this->id; }

void Employee::set_work_time(int work_time) { this->worktime = work_time; }
int Employee::get_work_time() { return this->worktime; }

void Employee::set_name(std::string call) { this->fi = call; }
std::string Employee::get_name() { return this->fi; }

void Employee::set_position(Position pos) { this->position = pos; }
Position Employee::get_position() { return this->position; }

void Employee::set_payment(double pay) { this->payment = pay; }
int Employee::get_payment() { return this->payment; }

int Employee::get_avatage_time() { return this->avarage_time; }
