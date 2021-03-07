// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Interfaces.h"
#include "Manager.h"
#include "Personal.h"

TEST(TestProgrammer, Test_1) {
  Project proj;
  proj.id = "proj";
  proj.budget = 20000;
  Programmer pr(10, "William Robinson", 70000, &proj);
  EXPECT_EQ(1, pr.getPos());
}

TEST(TestCleaner, Test_2) {
  Cleaner c(156, "Tom Crawford", 10000);
  EXPECT_EQ(5, c.getPos());
}

TEST(TestProgrammer, Test_3) {
  Project proj;
  proj.id = "proj";
  proj.budget = 20000;
  Programmer pr(10, "William Robinson", 100, &proj);
  pr.setWorkTime(2);
  pr.addBonus();
  pr.calc();
  EXPECT_EQ(10400, pr.getPayment());
}

TEST(TestProgrammer, Test_4) {
  Project proj;
  proj.id = "proj";
  proj.budget = 20000;
  Programmer pr(10, "William Robinson", 100, &proj);
  pr.setWorkTime(2);
  pr.calc();
  EXPECT_EQ(400, pr.getPayment());
}

TEST(TestTester, Test_5) {
  Project proj;
  proj.id = "proj";
  proj.budget = 20000;
  Tester pr(10, "William Robinson", 100, &proj);
  pr.setWorkTime(2);
  pr.calc();
  EXPECT_EQ(400, pr.getPayment());
}

TEST(TestTester, Test_6) {
  Project proj;
  proj.id = "proj";
  proj.budget = 20000;
  Tester pr(10, "William Robinson", 100, &proj);
  pr.setWorkTime(2);
  pr.newError();
  pr.calc();
  EXPECT_EQ(500, pr.getPayment());
}

TEST(TestTeamLeader, Test_7) {
  Project proj;
  proj.id = "proj";
  proj.budget = 20000;
  TeamLeader pr(10, "William Robinson", 200, &proj);
  pr.setWorkTime(2);
  pr.calc();
  EXPECT_EQ(800, pr.getPayment());
}

TEST(TestTeamLeader, Test_8) {
  Project proj;
  proj.id = "proj";
  proj.budget = 20000;
  TeamLeader pr(10, "William Robinson", 200, &proj);
  pr.setWorkTime(2);
  pr.addSubordinate();
  pr.calc();
  EXPECT_EQ(1800, pr.getPayment());
}

TEST(TestProjectManager, Test_9) {
  Project proj;
  proj.id = "proj";
  proj.budget = 2000000;
  ProjectManager pr(10, "William Robinson", &proj);
  pr.setWorkTime(2);
  pr.addSubordinates();
  pr.addSubordinates();
  pr.calc();
  EXPECT_EQ(2090, pr.getPayment());
}

TEST(TestSeniorManager, Test_10) {
  Project proj;
  proj.id = "proj";
  proj.budget = 2000000;
  SeniorManager pr(10, "William Robinson", &proj);
  pr.setWorkTime(2);
  pr.addSubordinates();
  pr.addSubordinates();
  pr.calc();
  EXPECT_EQ(2100, pr.getPayment());
}

TEST(TestCleaner, Test_11) {
  Cleaner c(156, "William Robinson", 50);
  c.setWorkTime(2);
  c.calc();
  EXPECT_EQ(100, c.getPayment());
}

TEST(TestDriver, Test_12) {
  Driver d(156, "William Robinson", 60);
  d.setWorkTime(2);
  d.addBonus();
  d.calc();
  EXPECT_EQ(220, d.getPayment());
}
