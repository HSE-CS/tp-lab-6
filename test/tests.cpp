// Copyright 2021 Schenikova

#include <gtest/gtest.h>
#include <string>
#include "Manager.h"
#include "Engineer.h"

TEST(Test, test1) {
  Tester * test = new Tester;
  test->setSalary(500);
  test->setWorkTime(40);
  test->setPro(1000);
  EXPECT_EQ(test->getPayment(), 21000);
}

TEST(Test, test2) {
  Tester * test = new Tester;
  test->setSalary(500);
  test->setWorkTime(40);
  test->setPro(1000);
  EXPECT_EQ(test->calcBase(), 20000);
}

TEST(Test, test3) {
  Cleaner * cl = new Cleaner;
  cl->setSalary(500);
  cl->setWorkTime(40);
  EXPECT_EQ(cl->calcBase(), 20000);
}

TEST(Test, test4) {
  Cleaner * cl = new Cleaner;
  cl->setSalary(500);
  cl->setWorkTime(40);
  EXPECT_EQ(cl->getPayment(), 20000);
}

TEST(Test, test5) {
  Driver * dr = new Driver;
  EXPECT_EQ(dr->calcBonus(4, 1000), 4000);
}

TEST(Test, test6) {
  Driver * dr = new Driver;
  dr->setSalary(500);
  dr->setWorkTime(40);
  EXPECT_EQ(dr->calcBonus(4, 1000) + dr->calcBase(), 24000);
}

TEST(Test, test7) {
  Programmer* prog = new Programmer;
  prog->setPro(2000);
  EXPECT_EQ(prog->calcProAdditions(), 2000);
}

TEST(Test, test8) {
  Tester* test = new Tester;
  test->setPro(1000);
  EXPECT_EQ(test->calcProAdditions(), 1000);
}

TEST(Test, test9) {
  TeamLeader* tm = new TeamLeader;
  std::vector <Programmer> programmers(10);
  tm->setPercent(100);
  EXPECT_EQ(tm->calcHeads(), 1000);
}

TEST(Test, test10) {
  TeamLeader* tm = new TeamLeader;
  std::vector <Programmer> programmers(0);
  tm->setPercent(100);
  EXPECT_EQ(tm->calcHeads(), 0);
}

TEST(Test, test11) {
  Programmer * prog = new Programmer;
  prog->setSalary(500);
  prog->setWorkTime(40);
  prog->setPro(1000);
  EXPECT_EQ(prog->getPayment(), 21000);
}

TEST(Test, test12) {
  ProjectManager * prog = new ProjectManager;
  // prog->setSalary(500);
  // prog->setWorkTime(40);
  // prog->setPro(1000);
  prog->setPercent(500);
  prog->serNum(5);
  EXPECT_EQ(prog->calcHeads(), 2500);
}

TEST(Test, test13) {
  ProjectManager * prog = new ProjectManager;
  prog->setPercent(0);
  prog->serNum(5);
  EXPECT_EQ(prog->calcHeads(), 0);
}

TEST(Test, test14) {
  TeamLeader* tm = new TeamLeader;
  std::vector <Programmer> programmers(5);
  tm->setPercent(100);
  tm->setSalary(1000);
  tm->setWorkTime(40);
  EXPECT_EQ(prog->getPayment(), 40500);
}

TEST(Test, test15) {
  Cleaner * cl = new Cleaner;
  cl->setSalary(1000);
  cl->setWorkTime(40);
  EXPECT_EQ(cl->getPayment(), 40000);
}
