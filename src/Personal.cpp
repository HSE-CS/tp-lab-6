// Copyright 2021 Kuznetsov Mikhail
#include "Personal.h"

Personal::Personal(unsigned int _id, std::string _name,
             POSITION _position, unsigned int _salary)
  : Employee(_id, _name, _position), salary(_salary) {
}

void Personal::calc() {
  payment = calcBase(salary, worktime) + calcBonus();
}

unsigned int Personal::calcBase(unsigned int _salary,
                      unsigned int _worktime) {
  return _salary * _worktime;
}

unsigned int Personal::calcBonus() {
  return 0;
}

void Personal::printInfo() {
  std::cout << "-----------------Employee card-----------------\n"
  << "id: " << id << "\nname: " << name
  << "\nposition: " << stringPosition() << "\nworktime: " << worktime
  << "\npayment: " << payment
  << "\n-----------------Employee card-----------------\n";
}

Driver::Driver(unsigned int _id, std::string _name,
          POSITION _position, unsigned int _salary)
  : Personal(_id, _name, _position, _salary) {
}

unsigned int Driver::calcBonus() {
  unsigned int bonusTime = worktime > 40 ? worktime - 40 : 0;
  return salary * 2 * bonusTime;
}

Cleaner::Cleaner(unsigned int _id, std::string _name,
                 POSITION _position, unsigned int _salary)
  : Personal(_id, _name, _position, _salary) {
}


