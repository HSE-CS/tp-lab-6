// Copyright 2021 Egor Buzanov

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "Engineer.h"
#include "Factory.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

TEST(StaffTest, test1) {
  Driver driver(0, "Proverka", 200);
  EXPECT_EQ(0, driver.getId());
}

TEST(StaffTest, test2) {
  Driver driver(0, "Proverka", 200);
  EXPECT_EQ("Proverka", driver.getName());
}

TEST(StaffTest, test3) {
  Driver driver(0, "Proverka", 200);
  EXPECT_EQ(DRIVER, driver.getPosition());
}

TEST(StaffTest, test4) {
  Driver driver(0, "Proverka", 200);
  driver.setWorktime(30);
  EXPECT_EQ(30, driver.getWorktime());
}

TEST(StaffTest, test5) {
  Driver driver(0, "Proverka", 200);
  driver.setWorktime(30);
  driver.calc();
  EXPECT_EQ(6000, driver.getPayment());
}

TEST(StaffTest, test6) {
  Driver driver(0, "Proverka", 200);
  driver.setWorktime(50);
  driver.calc();
  EXPECT_EQ(15000, driver.getPayment());
}

TEST(StaffTest, test7) {
  Cleaner cleaner(0, "Proverka", 200);
  cleaner.setWorktime(20);
  EXPECT_EQ(4000, cleaner.getPayment());
}

TEST(StaffTest, test8) {
  Cleaner cleaner(0, "Proverka", 200);
  cleaner.setWorktime(30);
  EXPECT_EQ(11000, cleaner.getPayment());
}

TEST(StaffTest, test9) {
  Project *project = new Project(0, 100000);
  Engineer engineer(0, "Proverka", 500, project, 0.5);
  engineer.setWorktime(40);
  engineer.calc();
  EXPECT_EQ(70000, engineer.getPayment());
}

TEST(StaffTest, test10) {
  Project *project = new Project(0, 100000);
  Programmer programmer(0, "Proverka", 500, project, 0.5);
  programmer.setWorktime(40);
  programmer.calc();
  EXPECT_EQ(75000, programmer.getPayment());
}

TEST(StaffTest, test11) {
  Project *project = new Project(0, 100000);
  Tester tester(0, "Proverka", 500, project, 0.5);
  tester.setWorktime(40);
  tester.calc();
  EXPECT_EQ(80000, tester.getPayment());
}

TEST(StaffTest, test12) {
  Project *project = new Project(0, 100000);
  TeamLeader teamleader(0, "Proverka", 500, project, 0.5);
  teamleader.setWorktime(40);
  teamleader.calc();
  EXPECT_EQ(85000, teamleader.getPayment());
}

TEST(StaffTest, test13) {
  Project *project = new Project(0, 100000);
  ProjectManager pr_manager(0, "Proverka", 5, project, 0.5);
  pr_manager.calc();
  EXPECT_EQ(100000, pr_manager.getPayment());
}

TEST(StaffTest, test14) {
  Project *project = new Project(0, 100000);
  std::vector<Project *> projects;
  projects.push_back(project);
  SeniorManager sn_manager(0, "Proverka", 5, projects, 0.5);
  sn_manager.calc();
  EXPECT_EQ(100000, sn_manager.getPayment());
}

TEST(StaffTest, test15) {
  Project *project1 = new Project(0, 100000);
  Project *project2 = new Project(0, 100000);
  std::vector<Project *> projects;
  projects.push_back(project1);
  projects.push_back(project2);
  SeniorManager sn_manager(0, "Proverka", 10, projects, 0.5);
  sn_manager.calc();
  EXPECT_EQ(200000, sn_manager.getPayment());
}
