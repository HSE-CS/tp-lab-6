// Copyright 2021 Kris

#include <gtest/gtest.h>
#include <string>
#include"Factory.h"


TEST(StaffDemo, test1) {
  std::vector<Employee*> staff = makeStaff("Staff.txt", "Projects.txt");
  EXPECT_EQ(15, staff.size());
}

TEST(StaffDemo, test2) {
  Driver d(11, "StepanFomin", "Driver", 250);
  d.setWorkTime(20);
  EXPECT_EQ(d.calc(), 5000);
}

TEST(StaffDemo, test3) {
  Project p = Project(7, 2100000), p2 = Project(12, 1000000);
  std::vector<Project> P{ p, p2 };
  SeniorManager SM(1, "KiraPriti", "SeniorManager", 400, P);
  SM.calc();
  EXPECT_EQ(SM.getsalary(), 1085000);
}
TEST(StaffDemo, test4) {
  Driver d(11, "StepanFomin", "Driver", 250);
  d.setWorkTime(20);
  EXPECT_EQ(d.calcBase(), 5000);
}
TEST(StaffDemo, test5) {
  Driver d(11, "StepanFomin", "Driver", 250);
  d.setWorkTime(15);
  d.setnight(5, 300);
  EXPECT_EQ(d.calcBonus(), 1500);
}
TEST(StaffDemo, test6) {
  Project p(7, 2100000);
  Tester c(4, "MarkTsuk", "Tester", 400, p);
  c.setWorkTime(80);
  c.calc();
  EXPECT_EQ(c.getsalary(),347000);
}
TEST(StaffDemo, test7) {
  Project p(7, 2100000);
  Tester c(4, "MarkTsuk", "Tester", 400, p);
  c.setWorkTime(80);
  c.calc();
  EXPECT_EQ(c.getworktime(),80);
}
TEST(StaffDemo, test8) {
  Cleaner c(13, "OlgaPrivolina", "Cleaner", 200);
  c.setWorkTime(20);
  c.calc();
  EXPECT_EQ(c.getworktime(), 20);
}
TEST(StaffDemo, test9) {
  Cleaner c(13, "OlgaPrivolina", "Cleaner", 200);
  c.setWorkTime(20);
  c.calc();
  EXPECT_EQ(c.getsalary(), 4000);
}
TEST(StaffDemo, test10) {
  Project p(777, 100);
  EXPECT_EQ(100, p.getBudget());
}
TEST(StaffDemo, test11) {
  Project p(777, 100);
  EXPECT_EQ(777, p.getId());
}
TEST(StaffDemo, test12) {
  Driver d(11, "StepanFomin", "Driver", 250);
  d.calc();
  EXPECT_EQ(d.getname(), "StepanFomin");
}
TEST(StaffDemo, test13) {
  Cleaner c(13, "OlgaPrivolina", "Cleaner", 200);
  c.calc();
  EXPECT_EQ(c.getposition(), "Cleaner");
}
TEST(StaffDemo, test14) {
  std::vector<Employee *> staff = makeStaff("", "");
  EXPECT_EQ(0, staff.size());
}

TEST(StaffDemo, test15) {
  Driver d(11, "StepanFomin", "Driver", 250);
  d.setWorkTime(15);
  d.setnight(5, 300);
  EXPECT_EQ(d.calc(), 5250);
}
