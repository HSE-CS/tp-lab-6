#include "Personal.h"

int Personal::calcBase(int salary, int worktime) {
 return salary * worktime;
}

int Driver::calcBonus() {
 return 2000;
}

void Cleaner::calc() {
 this->payment = this->calcBase(this->salary, this->worktime);
}

void Driver::calc() {
 this->payment = this->calcBase(this->salary, this->worktime) +
     this->calcBonus();
}

void Cleaner::printinfo() {
 std::cout << this->id << "." << this->name << "\n"
  "position: " << "\t" << this->position << "\n"
  "salary: " << "\t" << this->salary << "\n"
  "worktime: " << "\t" << this->worktime << "\n"
  "payment: " << "\t" << this->payment << "\n" << std::endl;
}

void Driver::printinfo() {
 std::cout << this->id << "." << this->name << "\n"
  "position: " << "\t" << this->position << "\n"
  "salary: " << "\t" << this->salary << "\n"
  "worktime: " << "\t" << this->worktime << "\n"
  "payment: " << "\t" << this->payment << "\n" << std::endl;
}

int Cleaner::calcBonus() {
 return 0;
}

