// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 08.02.2021.
//

#include <Personal.h>
#include <iostream>

// class Personal
Personal::Personal(id_type id, const std::string& name, unsigned int salary) :
    Employee(id, name),
    _salary(salary)
  {}


int Personal::calc_base(int salary, int wt) {
  return salary / 10 * wt / 2;
}
// end class Personal


// class Cleaner
Cleaner::Cleaner(id_type id, const std::string& name, unsigned int salary) :
    Personal(id, name, salary)
    { _position = Position::Cleaner; }

int Cleaner::calc_bonus() {
  return 0;
}

void Cleaner::calc() {
  _payment = calc_base(_salary, _worktime) + calc_bonus();
}

void Cleaner::print_info() {
  std::cout << "Position: Cleaner\n"
               "ID: " << _id << '\n' <<
               "Name: " << _name << '\n' <<
               "Worktime: " << _worktime << '\n' <<
               "Payment: " << _payment << std::endl;
}
// end class Cleaner


// class Driver
Driver::Driver(id_type id, const std::string& name, unsigned int salary) :
    Personal(id, name, salary)
    { _position = Position::Driver; }

int Driver::calc_bonus() {
  return _salary / 100 * _worktime;
}

void Driver::calc() {
  _payment = calc_base(_salary, _worktime) + calc_bonus();
}

void Driver::print_info() {
  std::cout <<  "Position: Driver\n"
                "ID: " << _id << '\n' <<
                "Name: " << _name << '\n' <<
                "Worktime: " << _worktime << '\n' <<
                "Payment: " << _payment << std::endl;
}
// end class Driver
