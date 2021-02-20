// Copyright 2021 Arina Simonova

#include "Factory.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
  string proj = "G:\\GitHubTasks\\tp-lab-6\\projects.txt";
  string myStaff = "G:\\GitHubTasks\\tp-lab-6\\MyStaff.txt";
  srand(time(NULL));
  vector<Employee *> staff = makeStaff(&myStaff[0], &proj[0]);
  for (int i = 0; i < 50; ++i) {
    staff[i]->SetWorkTime(20 + rand_r() % 35);
    staff[i]->Calc();
    staff[i]->PrintInfo();
  }
}
