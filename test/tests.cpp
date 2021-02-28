// Copyright 2021 Ksuvot

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"

TEST(TestDriver, test1) {
  Driver driver1(1, "name", 100);
  EXPECT_EQ(100, driver1.calcBonus());
}

TEST(TestDriver, test2) {
  Driver driver2(1, "name", 100);
  EXPECT_EQ("name", driver2.getName());
}

TEST(TestDriver, test3) {
  Driver driver3(1, "name", 100);
  driver3.setSalary(90);
  EXPECT_EQ(90, driver3.getSalary());
}

TEST(TestDriver, test4) {
  Driver driver4(156, "name", 130);
  driver4.setWorkTime(200);
  driver4.calc();
  EXPECT_EQ(26100, driver4.getPayment());
}

TEST(TestCleaner, test5) {
  Cleaner cleaner1(1, "name", 100);
  EXPECT_EQ(10, cleaner1.calcBonus());
}

TEST(TestCleaner, test6) {
  Cleaner cleaner2(1, "name", 100);
  EXPECT_EQ("name", cleaner2.getName());
}

TEST(TestCleaner, test7) {
  Cleaner cleaner3(1, "name", 100);
  cleaner3.setSalary(90);
  EXPECT_EQ(90, cleaner3.getSalary());
}

TEST(TestCleaner, test8) {
  Cleaner cleaner4(156, "name", 130);
  cleaner4.setWorkTime(200);
  cleaner4.calc();
  EXPECT_EQ(26000, cleaner4.getPayment());
}

TEST(TestProgrammer, test9) {
  Project project;
  project.id = 1;
  project.budget = 120;
  Programmer programmer1(1, "name", 1500, &project);
  EXPECT_EQ(programmer1.getPosition(), programmer);
}

TEST(TestProgrammer, test10) {
  Project project1;
  project1.id = 1;
  project1.budget = 120;
  Programmer programmer2(1, "name", 1500, &project1);
  EXPECT_EQ(programmer2.getProject(), &project1);
}

TEST(TestProgrammer, test11) {
  Project project2;
  project2.id = 1;
  project2.budget = 120;
  Programmer programmer3(1, "name", 1500, &project2);
  programmer3.setWorkTime(168);
  programmer3.calc();
  EXPECT_EQ(programmer3.getPayment(), 1500 * 168 + 15000 + 100);
}


