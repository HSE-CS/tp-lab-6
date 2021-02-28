#pragma once
#include <string>
class IWorkBaseTime {
 public:
  virtual double calcBase(int salary, int wtime) = 0;
  virtual double calcBonus() = 0;
};

class IProjectBudjet {
  virtual int calcBudjetPart(float part, int budjet) = 0;
  virtual int calcProAdditions() = 0;
};

class IHeading {
  virtual int calcHeads() = 0;
};

class Project {
 private:
  std::string name;
  int budjet;
  int number_of_employee;

 public:
  Project(std::string name, int budjet, int number)
      : name(name), budjet(budjet), number_of_employee(number) {}
  std::string getName() { return name; }
  int getBudjet() { return budjet; }
  int getNumber() { return number_of_employee; }
};
