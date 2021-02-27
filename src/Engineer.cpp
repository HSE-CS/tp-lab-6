// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 08.02.2021.
//

#include <Engineer.h>
#include <iostream>

// class Engineer
Engineer::Engineer(id_type id, const std::string& name,
                   unsigned int salary,
                   const Project& p) :

     Personal(id, name, salary),
     _project(p)
  {}

int Engineer::calc_budget_part(float part, int budget) {
  return budget * part;
}

void Engineer::calc() {
  _payment = calc_base(_salary, _worktime)
      + calc_budget_part(0.1, _project._budget);
}
// end class Engineer


// class Tester
Tester::Tester(id_type id,
               const std::string& name,
               unsigned int salary,
               const Project& p) : Engineer(id, name, salary, p)
  { _position = Position::Tester; }

int Tester::calc_pro_additions() {
  return _worktime * (_salary / 100);
}

int Tester::calc_bonus() {
  return 0;
}

void Tester::print_info() {
  std::cout <<  "Position: Tester\n"
                "ID: " << _id << '\n' <<
                "Name: " << _name << '\n' <<
                "Worktime: " << _worktime << '\n' <<
                "Payment: " << _payment << std::endl;
}
// end class Tester


// class Programmer
Programmer::Programmer(id_type id,
                       const std::string& name,
                       unsigned int salary,
                       const Project& p) : Engineer(id, name, salary, p)
  { _position = Position::Programmer; }

int Programmer::calc_pro_additions() {
  return _salary * 10 / _worktime;
}

int Programmer::calc_bonus() {
  return 0;
}

void Programmer::print_info() {
  std::cout <<  "Position: Programmer\n"
                "ID: " << _id << '\n' <<
                "Name: " << _name << '\n' <<
                "Worktime: " << _worktime << '\n' <<
                "Payment: " << _payment << std::endl;
}
// end class Programmer


// class TeamLeader
TeamLeader::TeamLeader(id_type id,
                       const std::string& name,
                       unsigned int salary,
                       const Project& p) : Programmer(id, name, salary, p)
  { _position = Position::TeamLeader; }

int TeamLeader::calc_heads() {
  return _salary * 5;
}

void TeamLeader::calc() {
  _payment = calc_heads()
      + calc_budget_part(0.3, _project._budget)
      + calc_base(_salary, _worktime);
}

void TeamLeader::print_info() {
  Programmer::print_info();
}
// end class TeamLeader
