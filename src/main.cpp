// Copyright 2020 Konina Tatiana
#include <iostream>
#include "Personal.h"
#include "Project.h"
#include "Engineer.h"
#include "Manager.h"
#include "Factory.h"
int main() {
  std::vector<Employee*> staff = read_data("data.csv");
  for (auto em : staff) {
    em->calc();
    em->printInfo();
  }
  return 0;
}




