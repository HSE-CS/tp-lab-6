// Copyright 27.02.21 DenisKabanov

#include "Factory.h"

int main() {
  Cleaner employee1(99, "Vova Vilkin", 100);
  employee1.printInfo();
  employee1.setWorkTime(100);
  employee1.calc();
  employee1.printInfo();
  Driver employee2(777, "Boris Britva", 300);
  employee2.setWorkTime(100);
  employee2.addBonus(1);
  employee2.calc();
  employee2.printInfo();
  Project pr1;
  pr1.id = "RosAtom";
  pr1.budget = 100000;
  SeniorManager employee3(1, "Vasya Pupkin", &pr1);
  employee3.printInfo();
  employee3.addSub(3);
  employee3.calc();
  employee3.printInfo();
  Engineer employee4(13, " Dima Belkin", 7500, &pr1);
  employee4.printInfo();
  employee4.setWorkTime(2);
  employee4.calc();
  employee4.printInfo();
  Tester employee5(19, " Ching Chong", 10, &pr1);
  employee5.printInfo();
  employee5.setWorkTime(1000000);
  employee5.setErrors(3);
  employee5.calc();
  employee5.printInfo();
  /*StaffFactory staff[1];
  staff[1].makeStaff();*/
  return 0;
}