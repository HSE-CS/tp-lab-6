// Copyright 2021 Lab_6 TiNa
#include "Factory.h"
#include "Employee.h"
#include <iostream>
#include <string>
#include <fstream>

Project::Project(int id, int budget) {
  this->id = id;
  this->budget = budget;
}

std::vector<Personal*> Factory::makeStaff() {
  std::ifstream filein(filename);
  Personal* ffstaff;
  std::vector<Personal*> staff;
  int idf;
  int sal;
  std::string pos;
  std::string name;
  std::string name1;
  std::string name2;
  std::string name3;
  if (filein.is_open()) {
    while (!filein.eof()) {
      filein >> idf;
      filein >> name1;
      filein >> name2;
      filein >> name3;
      name = name1 + " " + name2 + " " + name3;
      filein >> pos;
      filein >> sal;
      staff.push_back(new Personal(idf, name, pos, sal, 0, 0));
    }
  } else {
    std::cout << "FILE ISN'T OPEN" << std::endl;
  }

  return staff;
}