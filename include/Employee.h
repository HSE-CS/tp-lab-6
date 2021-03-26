// Copyright 2021 by Liza
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Employee {
 private:
int id;
std::string name;
std::string position;
int worktime;
int payment;
 public:
Employee();
Employee(int _id, std::string _name, std::string _position, int _payment);
void setWorkTime(int workt);
int getid();
int getworktime();
int getpayment();
std::string getname();
std::string getposition();
virtual int calc() = 0;
virtual void printInfo() = 0;};
#endif   // INCLUDE_EMPLOYEE_H_
