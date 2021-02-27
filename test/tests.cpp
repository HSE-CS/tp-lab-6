// Copyright 2021 GN

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"


TEST(TestProgrammer, Test_1) {
  std::string name_ = "Ivanov Ivan";
  Project project_1;
  project_1.id = "project_1";
  project_1.budget = 20000;
  Programmer pr(10, name_, 70000, &project_1);
  EXPECT_EQ(1, pr.getPos());
}

TEST(TestCleaner, Test_2) {
  std::string name_ = "Peter Ivanov";
  Cleaner c(156, name_, 10000);
  EXPECT_EQ(5, c.getPos());
}

TEST(TestProgrammer, Test_3) {
  std::string name_ = "Ivanov Ivan";
  Project project_1;
  project_1.id = "project_1";
  project_1.budget = 20000;
  Programmer pr(10, name_, 100, &project_1);
  pr.setWorkTime(2);
  pr.addBonus();
  pr.calc();
  EXPECT_EQ(10400, pr.getPayment());
}

TEST(TestProgrammer, Test_4) {
  std::string name_ = "Ivanov Ivan";
  Project project_1;
  project_1.id = "project_1";
  project_1.budget = 20000;
  Programmer pr(10, name_, 100, &project_1);
  pr.setWorkTime(2);
  pr.calc();
  EXPECT_EQ(400, pr.getPayment());
}

TEST(TestTester, Test_5) {
  std::string name_ = "Ivanov Ivan";
  Project project_1;
  project_1.id = "project_1";
  project_1.budget = 20000;
  Tester pr(10, name_, 100, &project_1);
  pr.setWorkTime(2);
  pr.calc();
  EXPECT_EQ(400, pr.getPayment());
}

TEST(TestTester, Test_6) {
  std::string name_ = "Ivanov Ivan";
  Project project_1;
  project_1.id = "project_1";
  project_1.budget = 20000;
  Tester pr(10, name_, 100, &project_1);
  pr.setWorkTime(2);
  pr.newError();
  pr.calc();
  EXPECT_EQ(500, pr.getPayment());
}

TEST(TestTeamLeader, Test_7) {
  std::string name_ = "Ivanov Ivan";
  Project project_1;
  project_1.id = "project_1";
  project_1.budget = 20000;
  TeamLeader pr(10, name_, 200, &project_1);
  pr.setWorkTime(2);
  pr.calc();
  EXPECT_EQ(800, pr.getPayment());
}

TEST(TestTeamLeader, Test_8) {
  std::string name_ = "Ivanov Ivan";
  Project project_1;
  project_1.id = "project_1";
  project_1.budget = 20000;
  TeamLeader pr(10, name_, 200, &project_1);
  pr.setWorkTime(2);
  pr.addSubordinate();
  pr.calc();
  EXPECT_EQ(1800, pr.getPayment());
}

TEST(TestProjectManager, Test_9) {
  std::string name_ = "Ivanov Ivan";
  Project project_1;
  project_1.id = "project_1";
  project_1.budget = 2000000;
  ProjectManager pr(10, name_, &project_1);
  pr.setWorkTime(2);
  pr.addSubordinates();
  pr.addSubordinates();
  pr.calc();
  EXPECT_EQ(2090, pr.getPayment());
}

TEST(TestSeniorManager, Test_10) {
  std::string name_ = "Ivanov Ivan";
  Project project_1;
  project_1.id = "project_1";
  project_1.budget = 2000000;
  SeniorManager pr(10, name_, &project_1);
  pr.setWorkTime(2);
  pr.addSubordinates();
  pr.addSubordinates();
  pr.calc();
  EXPECT_EQ(2100, pr.getPayment());
}

TEST(TestCleaner, Test_11) {
  std::string name_ = "Ivan Ivanov";
  Cleaner c(156, name_, 50);
  c.setWorkTime(2);
  c.calc();
  EXPECT_EQ(100, c.getPayment());
}

TEST(TestDriver, Test_12) {
  std::string name_ = "Ivan Ivanov";
  Driver d(156, name_, 60);
  d.setWorkTime(2);
  d.addBonus();
  d.calc();
  EXPECT_EQ(220, d.getPayment());
}
