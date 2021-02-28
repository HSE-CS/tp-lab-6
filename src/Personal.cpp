// Copyright DB 2021
#include "Personal.h"
#include <sstream>
#include <iostream>

int Personal::calcBase(int salary, int worktime) { 
    return salary * worktime;
}

int Personal::calcBonus() {
    return 0; 
}

void Personal::printInfo() {
  std::stringbuf str;
  std::ostream stream(&str);
  stream << "Id: " << id << "\n Name: " << name
         << "\n Position: " << getPosition() << "\n Work time: " << workTime
         << "\n Salary: " << salary << "\n Payment: " << payment << "\n";
  std::cout << str.str() << std::endl;
}

void Personal::calc() {
    payment = calcBase(salary, workTime) + calcBonus(); 
}

int Driver::calcBonus() { 
    return calcBase(salary, workTime) / 10; 
}

