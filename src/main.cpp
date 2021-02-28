// Copyright 2020 S. BOR

#include "Engineer.h"
#include "Manager.h"
#include "Factory.h"

int main() {
  Factory a;
  std::vector <Employee *> staff = a.fileRead("input.txt");
  for(Employee * emp : staff) {
    emp->setWorkTime(40);
  }
  for (Employee * emp : staff) {
    emp->calc();
  }
  for (Employee * emp : staff) {
    emp->printInfo();
  }
  return 0;
}
