// Copyright 2021 Tatsenko Alexey
#include <vector>

#include "Factory.h"
#include "Interfaces.h"

int main() {
  Factory fabrica;

  std::vector<Employee*> employment =
      fabrica.make_staff("C:\\Users\\Alexey\\Desktop\\papka\\projects.txt",
                         "C:\\Users\\Alexey\\Desktop\\papka\\staff.txt");
  for (auto& emp : employment) {
    emp->set_work_time(std::rand() % 11 + 1);
  }

  for (auto& emp : employment) {
    emp->calc();
  }

  for (auto& emp : employment) {
    emp->print_info();
  }

  return 0;
}
