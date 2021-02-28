// Copyright 2021 Schenikova

#include "Manager.h"
#include "Engineer.h"
#include <string>

int main() {
  Programmer * prog = new Programmer;
  prog->setSalary(500);
  prog->setWorkTime(40);
  prog->setPro(1000);
  std::cout << prog->getPayment()<< "\n";
}

