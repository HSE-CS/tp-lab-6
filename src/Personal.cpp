// Copyright 2021 Danyaev Artem
#include "Personal.h"

Personal::Personal(unsigned int id_, std::string& name_, Position pos, int salary_)
    : Employee(id_, name_, pos), salary(salary_) {}

void Personal::printInfo(){
  const char* positions[] = { "EMPLOYEE", "PERSONAL", "ENGINEER", "CLEANER", "DRIVER", "PROGRAMMER", "TESTER", "TEAM_LEADER", "PROJECT_MANAGER", "SENIOR_MANAGER" };
  std::cout << "Id: " << id << " Fio: " << name << std::endl << "Position: " << positions[position] << " Salary: " << salary << std::endl;
  std::cout << "Worktime: " << worktime << " Payment: " << payment << std::endl;
}


int Personal::calcBase(int salary, int wtime){
  return salary*wtime;
}

Driver::Driver(unsigned int id_, std::string &name_, Position pos, int salary_)
    : Personal(id_, name_, pos, salary_) {}

int Driver::calcBonus() {
  return 500;
}

void Driver::calc() {
  payment = calcBase(salary, worktime) + calcBonus();
}

Cleaner::Cleaner(unsigned int id_, std::string &name_, Position pos, int salary_)
    : Personal(id_, name_, pos, salary_) {}

int Cleaner::calcBonus() {
  return 0;
}

void Cleaner::calc() {
  payment = calcBase(salary, worktime) + calcBonus();
}
