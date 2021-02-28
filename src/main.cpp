// Copyright 2021 mkhorosh
#include <iostream>
#include "Employee.h"
#include "Factory.h"
#include "Personal.h"
#include "Manager.h"
#include "Engineer.h"
#include "Interfaces.h"

int main() {
  std::string ffile = "C:\\Users\\Marina\\CLionProjects\\tp-lab-6\\data\\projects.txt";
  std::string sfile = "C:\\Users\\Marina\\CLionProjects\\tp-lab-6\\data\\staff.txt";
  Factory myCompany(ffile, sfile);
  myCompany.readData();
}
