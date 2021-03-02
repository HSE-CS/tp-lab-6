// Copyright 2021 Shirokov Alexander

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"

TEST(staff_test, test1) {
  Programmer programmer(1, 150, "Alex", PROGRAMMER, new Project(30000, "One"),
  0.5);
  EXPECT_EQ(1, programmer.getId());
}

TEST(staff_test, test2) {
  Programmer programmer(1, 150, "Alex", PROGRAMMER, new Project(30000, "One"),
  0.5);
  EXPECT_EQ("Alex", programmer.getName());
}

TEST(staff_test, test3) {
  Tester tester(2, 140, "Ivan", TESTER, new Project(30000, "One"),
  0.3);
  EXPECT_EQ(TESTER, tester.getPosition());
}

TEST(staff_test, test4) {
  Tester tester(2, 140, "Ivan", TESTER, new Project(30000, "One"),
  0.3);
  tester.calc();
    EXPECT_EQ(9500, tester.getPayment());
}

TEST(staff_test, test5) {
  Programmer programmer(1, 150, "Alex", PROGRAMMER, new Project(30000, "One"),
  0.5);
  programmer.setWorkTime(65);
  EXPECT_EQ(65, programmer.getWorkTime());
}

TEST(staff_test, test6) {
  TeamLeader leader(1, 180, "Alex", TEAM_LEADER, new Project(30000, "One"), 0.6);
  EXPECT_EQ(7500, leader.calcHeads());
}

TEST(staff_test, test7) {
  Cleaner cleaner(3, 100, "Oleg", CLEANER);
  cleaner.setWorkTime(45);
  cleaner.calc();
  EXPECT_EQ(4500, cleaner.getPayment());
}

TEST(staff_test, test8) {
  Driver driver(3, 120, "Andrey", DRIVER);
  driver.setWorkTime(70);
  driver.calc();
  EXPECT_EQ(8700, driver.getPayment());
}

TEST(staff_test, test9) {
  std::vector<Project*> proj;
  proj.push_back(new Project(10000, "test1"));
  proj.push_back(new Project(20000, "test2"));
  proj.push_back(new Project(30000, "test3"));
  ProjectManager proger(10, "Ivan", PROJECT_MANAGER, proj, 0.4);
  EXPECT_EQ(8000, proger.calcBudgetPart(0.4, proj[1]->getBudget()));
}

TEST(staff_test, test10) {
  std::vector<Project*> proj;
  proj.push_back(new Project(10000, "test1"));
  proj.push_back(new Project(20000, "test2"));
  proj.push_back(new Project(30000, "test3"));
  ProjectManager proger(10, "Ivan", PROJECT_MANAGER, proj, 0.4);
  EXPECT_EQ(12000, proger.calcBudgetPart(0.4, proj[2]->getBudget()));
}

TEST(staff_test, test11) {
  std::vector<Project*> proj;
  proj.push_back(new Project(1500, "test1"));
  EXPECT_EQ(1500, proj[0]->getBudget());
}

TEST(staff_test, test12) {
  std::vector<Project*> proj;
  proj.push_back(new Project(10000, "test1"));
  proj.push_back(new Project(20000, "test2"));
  proj.push_back(new Project(30000, "test3"));
  SeniorManager senior(55, "Igor", proj, SENIOR_MANAGER, 0.6);
  senior.calc();
  EXPECT_EQ(7500, senior.getPayment());
}

TEST(staff_test, test13) {
  std::vector<Project*> proj;
  proj.push_back(new Project(10000, "test1"));
  proj.push_back(new Project(20000, "test2"));
  proj.push_back(new Project(30000, "test3"));
  EXPECT_EQ("test2", proj[1]->getTitle());
}

TEST(staff_test, test14) {
  Tester tester(2, 140, "Ivan", TESTER, new Project(30000, "One"),
  0.3);
  tester.setWorkTime(50);
  EXPECT_EQ(7000, tester.calcBase(140, tester.getWorkTime()));
}

TEST(staff_test, test15) {
  Cleaner c(10, 70, "Nina", CLEANER);
  c.setWorkTime(50);
  EXPECT_EQ(200, c.calcBonus());
}
