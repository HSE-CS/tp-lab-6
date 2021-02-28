// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Manager.h"
#include "Engineer.h"

TEST(PersonalTest, test1) {
  Cleaner* emp = new Cleaner;
  emp->setWorkTime(30);
  emp->setSalary(100);
  EXPECT_EQ(emp->calcBase(), 3000);
}

TEST(PersonalTest, test2) {
  Cleaner* emp = new Cleaner;
  emp->setWorkTime(30);
  emp->setSalary(100);
  EXPECT_EQ(emp->getPayment(), 3000);
}

TEST(PersonalTest, test3) {
  Driver* emp = new Driver;
  EXPECT_EQ(emp->calcBonus(10, 100), 1000);
}

TEST(PersonalTest, test4) {
  Cleaner* emp = new Cleaner;
  EXPECT_EQ(emp->calcBonus(10, 100), 0);
}

TEST(PersonalTest, test5) {
  Driver* emp = new Driver;
  emp->setWorkTime(30);
  emp->setSalary(100);
  EXPECT_EQ(emp->getPayment(), 3050);
}

TEST(PersonalTest, test6) {
  Programmer* emp = new Programmer;
  EXPECT_EQ(emp->calcProAdditions(), 500);
}

TEST(PersonalTest, test7) {
  Tester* emp = new Tester;
  EXPECT_EQ(emp->calcProAdditions(), 300);
}

TEST(PersonalTest, test8) {
  Programmer* emp = new Programmer;
  emp->setWorkTime(30);
  emp->setSalary(100);
  EXPECT_EQ(emp->getPayment(), 3500);
}

TEST(PersonalTest, test9) {
  Tester* emp = new Tester
  emp->setWorkTime(30);
  emp->setSalary(100);
  EXPECT_EQ(emp->getPayment(), 3300);
}

TEST(PersonalTest, test10) {
  TeamLeader* emp = new TeamLeader;
  EXPECT_EQ(emp->calcHeads(5), 500);
}

TEST(PersonalTest, test11) {
  TeamLeader* emp = new TeamLeader;
  emp->setWorkTime(30);
  emp->setSalary(100);
  EXPECT_EQ(emp->getPayment(), 4000);
}

TEST(PersonalTest, test12) {
  ProjectManager* emp = new ProjectManager;
  EXPECT_EQ(emp->calcProAdditions(), 0);
}

TEST(PersonalTest, test13) {
  Driver* emp = new Driver;
  EXPECT_EQ(emp->calcBonus(10, 100), 1000);
}

TEST(PersonalTest, test14) {
  Cleaner* emp = new Cleaner;
  EXPECT_EQ(emp->calcBonus(10, 100), 0);
}

TEST(PersonalTest, test15) {
  Driver* emp = new Driver;
  emp->setWorkTime(30);
  emp->setSalary(100);
  EXPECT_EQ(emp->getPayment(), 3050);
}
