// Copyright 2021 ArinaMonicheva

#include <fstream>
#include "Manager.h"
#include "Personal.h"
#include "Engineer.h"
#include "Factory.h"

int main() {
  time_t* n = NULL;
  unsigned* seed = 0;
  srand(time(n));
  std::ifstream employeesFile("Employees.txt");
  std::ifstream projectsFile("Projects.txt");
  StaffFactory newFactory;
  std::vector<Employee*> employees = 
   newFactory.makeStaff(employeesFile, projectsFile);

  for (auto i : employees) {
    i->updateWorkTime(30 + rand_r(seed) % 60);
    i->calc();
    i->printInfo();
    std::cout << std::endl;
  }

  return 0;
}
