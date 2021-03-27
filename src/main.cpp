// Copyright 2021 by Liza
#include "Factory.h"
#include <vector>
#include <locale>
#include <fstream>
#include <sstream>
#include "Factory.h"
#include "Manager.h"
#include "Interfaces.h"
#include "Employee.h"
#include "Personal.h"

int main() {
std::string staffList = "StaffList.txt";
std::string projectsList = "ProjectsList.txt";
std::vector<Employee*> staff = makeStaff(staffList, projectsList);
const std::size_t s = staff.size();
int payments[100] = { 0 };
for (unsigned int i = 0; i < staff.size(); i++) {
std::cin >> payments[i];}
int i = 0;
for (Employee* emp : staff) {
emp->setWorkTime(payments[i]);
i++;}
for (Employee* emp : staff) {
emp->calc();}
for (Employee* emp : staff) {
emp->printInfo();}
return 0;}
