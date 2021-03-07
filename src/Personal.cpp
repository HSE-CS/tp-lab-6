// Copyright 2020 Ilya Urtyukov
#include "Interfaces.h"

#include "Employee.h"
#include "Personal.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

Personal::Personal(int a, std::string s, std::string d, int b, int c) 
: Employee(a, s, d, 0, c) {
  salary = b;
}
void Personal::set_salary(int b) {
  salary = b;
}
int Personal::calcBase(int salary, int wtime) {
  return wtime * salary;
}
int Personal::get_salary() {
  return salary;
}
Driver::Driver(int a, std::string s, std::string d, int b, int c) 
: Personal(a, s, d, b, c) {
}
int Driver::calcBonus() {
  return (get_worktime() * get_salary()*0, 2);
}
int Driver::calc() {
  return (calcBase(get_worktime(), get_salary()) + calcBonus());
}
void Driver::printInfo() {
  std::cout << std::endl
            << this->get_id() << " - " << this->get_name() << " - "
            << this->get_position() << "\nSalary = " << this->get_salary()
            << "\nWorktime = " << this->get_worktime()
            << "\nFinal payment = " << this->calc() << std::endl;
}
Cleaner::Cleaner(int a, std::string s, std::string d, int b, int c) 
: Personal(a, s, d, b, c) {
}
int Cleaner::calc() {
    return (calcBase(get_worktime(), get_salary()));
}
void Cleaner::printInfo() {
  std::cout << std::endl
            << this->get_id() << " - " << this->get_name() << " - "
            << this->get_position() << "\nSalary = " << this->get_salary()
            << "\nWorktime = " << this->get_worktime()
            << "\nFinal payment = " << this->calc() << std::endl;
}

