// Copyright 2021 Arina Simonova

#include "Factory.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
  std::string proj = "projects.txt";
  std::string myStaff = "MyStaff.txt";
  unsigned int seed = 5, *seedp = &seed;
  srand(time(NULL));
  std::vector<Employee *> staff = makeStaff(&myStaff[0], &proj[0]);
  for (int i = 0; i < 50; ++i) {
    staff[i]->SetWorkTime(20 + rand_r(seedp) % 35);
    staff[i]->Calc();
    staff[i]->PrintInfo();
  }
}
