// Copyright 2021 by Liza
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include "Employee.h"
#include "Interfaces.h"
#include <string>

class Personal : public Employee {
 private:
int salary;
 public:
Personal(int _id, std::string _name, std::string _position, int _payment);
Personal();
void setsalary(int a) {
salary = a;}
int calc();
int calcBase();
int getsalary();
void printInfo();};

class Driver : public Personal {
 private:
int nightTime = 0;
int nightPayment = 0;
 public:
Driver(int _id, std::string _name, std::string _position, int _payment);
void setnight(int nighttime, int nightpayment) {
nightTime = nighttime;
nightPayment = nightpayment;}
int calcBonus();
int calc();};

class Cleaner : public Personal {
 public:
Cleaner(int _id, std::string _name, std::string _position, int _payment);
int calc();};

class Project {
 private:
int id;
int budget;
 public:
Project() {
id = 0;
budget = 0;}
Project(int id, int budget);
int getId();
int getBudget();
};

#endif  // INCLUDE_PERSONAL_H_
