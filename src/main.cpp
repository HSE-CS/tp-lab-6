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
  return 0;
}