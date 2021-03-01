// Copyright 2020 Polina Lukicheva

#include <iostream>
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"
int main() {
  std::vector<Employee*> employeers = readData("file.csv");
  for (auto e : employeers) {
    e->calc();
    e->printInfo();
  }
  Project* pr = new Project{ 12214, 100000 };
  Programmer* emp = new Programmer (1,
    "Lukyanov Michail Igorevich", "driver", 40, 500, pr);
  std::cout << emp->calcProAdditions();
  return 0;
}
