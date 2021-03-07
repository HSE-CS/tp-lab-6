// Copyright 2021 Tatsenko Alexey
#include "Personal.h"
#include"Employee.h"
#include <iostream>

std::string converse_1(Position pos) {
  if (pos == PROGRAMMER)
    return "Programmer";
  else if (pos == TESTER)
    return "Tester";
  else if (pos == DRIVER)
    return "Driver";
  else if (pos == CLEANER)
    return "Cleaner";
  else if (pos == ENGINEER)
    return "Engineer";
  else if (pos == SENIOR_MANAGER)
    return "SeniorManager";
  else if (pos ==  PROJECT_MANAGER)
    return "ProjectManager";
  else if (pos == TEAM_LEADER)
    return "TeamLeader";
}


Personal::Personal(int id, std::string fi, Position pos, int salary)
    : Employee(id, fi, pos) {
  this->salary_per_hour = salary;
}

Driver::Driver(int id, std::string fi, Position position, int salary_per_hour)
    : Personal(id, fi, position, salary_per_hour) {}

Cleaner::Cleaner(int id, std::string fi, Position position, int salary_per_hour)
    : Personal(id, fi, position, salary_per_hour) {}

int Personal::calc_base(int salary_per_hour, int wtime) {
    return salary_per_hour * wtime;
}

int Personal::calc_bonus() {
    return 0;
}

void Personal::calc() {
  this->set_payment(
      this->calc_base(this->salary_per_hour, this->get_work_time()) +
      this->calc_bonus());
}

void Personal::print_info() {
  std::cout << this->get_id() << "  "
            << "name: " << this->get_name() << std::endl
            << "\t" << "position " << converse_1(this->get_position())
            << std::endl;
  std::cout << "\t"
            << "workTime: " << this->get_work_time() << std::endl
            << "\t" << "payment: " << this->get_payment();
  std::cout << std::endl;
}

int Driver::calc_bonus() {
  if (this->get_work_time() > this->get_avatage_time()) {
    return ((this->get_work_time() - this->get_avatage_time()) *
                this->salary_per_hour * 1.5);
  }
}

int Cleaner::calc_bonus() { return 0; }
