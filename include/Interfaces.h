// Copyright 2021 Tatsenko Alexey
#pragma once
#include <string>
#include<vector>
#include"Employee.h"
class WorkBaseTime {
 public:
  virtual int calc_base(int salary_per_hour, int wtime) = 0;
  virtual int calc_bonus() = 0;
};

class ProjectBudjet {
  virtual int calc_budjet_part(float part, int budjet) = 0;
  virtual int calc_pro_additions() = 0;
};

class Heading {
  virtual int calc_heads() = 0;
};

class Project {
 private:
  std::string fi;
  int budjet;
  std::vector<Employee*> emp;

 public:
  Project(std::string fi, int budjet)
      : fi(fi), budjet(budjet) {}
  std::string get_name() { return fi; }
  int get_budjet() { return budjet; }
  void add_student(Employee* emp) { this->emp.push_back(emp); }
  int get_number_of_emp() { return this->emp.size(); }
};

