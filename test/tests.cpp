// Copyright 2021 Tatsenko Ilya
#include <gtest/gtest.h>

#include"Employee.h"
#include"Engineer.h"
#include"Manager.h"
#include"Personal.h"

TEST(EmployTest, test1) {
  Personal emp(1, "Ilya", "Driver", 8, 30);
  EXPECT_EQ("Ilya", emp.getName());
}

TEST(EmployTest, test2) {
  Cleaner cleaner(1, "xxx", "Cleaner", 9, 13);
  cleaner.setWorkTime(3);
  cleaner.calc();
  EXPECT_EQ(39, cleaner.getPayment());
}

TEST(EmployTest, test3) {
  Driver driver(1, "xxx", "Driver", 9, 13);
  EXPECT_EQ("Driver", driver.getPosition());
}

TEST(EmployTest, test4) {
  Driver driver(1, "xxx", "Driver", 9, 13);
  EXPECT_EQ(9, driver.getWorkTime());
}

TEST(EmployTest, test5) {
  Driver driver(1, "xxx", "Driver", 18, 13);
  driver.calc();
  EXPECT_EQ(273, driver.getPayment());
}

TEST(EmployTest, test6) {
  Project * project = new Project("HSE",300000,1);
  float part = 0.3;
  Programmer prog(1, "Ilya", "Programmer", 9, 99, project, part);
  prog.calc();
  EXPECT_EQ(300 + 9 * 99, prog.getPayment());
}

TEST(EmployTest, test7) {
  Project* project = new Project("HSE", 300000, 1);
  float part = 0.19;
  Tester tester(1, "Ilya", "Programmer", 9, 99, project, part, 3);
  tester.calc();
  EXPECT_EQ(300 + 9 * 99, tester.getPayment());
}

TEST(EmployTest, test8) {
  Project* project = new Project("HSE", 300000, 1);
  EXPECT_EQ("HSE", project->getName());
}

TEST(EmployTest, test9) {
  Project* project = new Project("HSE", 300000, 1);
  EXPECT_EQ(1, project->getNumber());
}

TEST(EmployTest, test10) {
  Project* project = new Project("HSE", 300000, 1);
  EXPECT_EQ(300000, project->getBudjet());
}

TEST(EmployTest, test11) {
  Project* project = new Project("HSE", 300000, 1);
  std::vector<Project*> project_;
  project_.push_back(project);
  ProjectManager manager(1, "Ilya", "ProjectManager", project_, 0);// nomer projecta = 0, not 1;
  manager.calc();
  EXPECT_EQ(1000 + 300000, manager.getPayment());
}

TEST(EmployTest, test12) {
  Project* project = new Project("HSE", 300000, 1);
  std::vector<Project*> project_;
  project_.push_back(project);
  ProjectManager manager(1, "Ilya", "ProjectManager", project_, 1);
  EXPECT_EQ("ProjectManager", manager.getPosition());
}

TEST(EmployTest, test13) {
  Project* project = new Project("HSE", 300000, 1);
  Project* project2 = new Project("NN", 330000, 3);
  Project* project3 = new Project("JJDK", 710442, 9);
  std::vector<Project*> project_;
  project_.push_back(project);
  project_.push_back(project2);
  project_.push_back(project3);
  SeniorManager manager(1, "Ilya", "ProjectManager", project_);
  manager.calc();
  EXPECT_EQ(150000 + 55000 + 39469 + 13000, manager.getPayment());
}

TEST(EmployTest, test14) {
  Project* project_ = new Project("HSE", 300000, 3);
  TeamLeader leader_time(1, "Ilya", "TeamLeader", 3, 33, project_, 0.9);
  leader_time.calc();
  EXPECT_EQ(3 * 33 + 9 * 30000 + 3000, leader_time.getPayment());
}

TEST(EmployTest, test15) {
  std::vector<Project*> project_;
  SeniorManager manager(1, "Ilya", "SeniorManager", project_);
  EXPECT_EQ(1, manager.getId());
}