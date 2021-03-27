// Copyright 2021 by Liza
#include "Employee.h"

void Employee::setWorkTime(int workt) {
this->worktime = workt;}
int Employee::getid() {
return id;}
int Employee::getworktime() {
return worktime;}
int Employee::getpayment() {
return payment;}
std::string Employee::getname() {
return name;}
std::string Employee::getposition() {
return position;}

Employee::Employee() {
id = 0;
name = "";
position = "";
payment = 0;}

Employee::Employee(int _id, std::string _name,
std::string _position, int _payment) {
id = _id;
name = _name;
position = _position;
payment = _payment;}

int Employee::calc() {
return getworktime() * getpayment();}

void Employee::printInfo() {
std::cout << std::setw(16) << getid() << std::setw(16) << getname()
<< std::setw(16) << getposition() << std::setw(16) << getworktime()
<< std::setw(16) << getpayment() << std::endl;}
