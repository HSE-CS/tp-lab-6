// Copyright 2021 LongaBonga

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

int main() {
  // Driver* emp = new Driver(10, "Vasya", "Driver", 500, 8);
  // int sum = emp->calc();
  // emp->printInfo();

  // Project pr = { 100, "lab # 6", 23490 };
  // Tester* emp = new Tester(10, "Pupkin", "Tester", 1000, 9, &pr, 5);
  // emp->setSalary(1000);
  // int sum = emp->calcProAdditions();
  // std::cout <<sum<< '\n';
  // emp->printInfo();
  std::vector<Project*> projects;
  Project lab = {100, "lab # 6", 1707};
  Project lstm = {100, "LSTM model", 200000};
  projects.push_back(&lab);
  projects.push_back(&lstm);
  ProjectManager* manager = new ProjectManager(
      228, "Ivan Dobryaev", "Project Manager", 2, 80000, 8, projects, 3);

  manager->printInfo();

  std:: cout << lab.name << '\n';
}
