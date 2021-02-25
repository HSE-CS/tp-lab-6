// Copyright 2021 Arina Simonova

#include "Factory.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
  std::string proj = "src/projects.txt";
  std::string myStaff = "src\\MyStaff.txt";
  srand(time(NULL));
  std::vector<Employee *> staff = makeStaff(&myStaff[0], &proj[0]);
  for (int i = 0; i < 50; ++i) {
    staff[i]->SetWorkTime(20 + rand_r() % 35);
    staff[i]->Calc();
    staff[i]->PrintInfo();
  }
}
