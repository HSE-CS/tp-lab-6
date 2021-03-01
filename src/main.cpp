// Copyright 2021 Ryzhova Irina

#include <iostream>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "Factory.h"

int main() {
  std::vector<Project*> pr;
  Project* p1 = new Project(0, 42);
  pr.push_back(p1);
  Project* p2 = new Project(2, 35);
  pr.push_back(p2);
  Project* p3 = new Project(5, 23);
  pr.push_back(p3);
  SeniorManager* s = new SeniorManager(1, "Test", "senior manager", 344, pr);
  return 0;
}
