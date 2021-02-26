// Copyright 2021 Smirnov Grigory

#include <gtest/gtest.h>
#include <string>

#include "Factory.h"

TEST(TestCleaner, pos) {
  std::string n = "Glasha";
  Cleaner c(156, n, 130);
  EXPECT_EQ(0, c.getPos());
}

TEST(TestCleaner, calc) {
  std::string n = "Glasha";
  Cleaner c(156, n, 130);
  c.setWorkTime(100);
  c.calc();
  EXPECT_EQ(13000, c.getPayment());
}

TEST(TestDriver, calc) {
  std::string n = "Vasilii";
  Driver d(156, n, 130);
  d.setWorkTime(200);
  d.calc();
  EXPECT_EQ(31000, d.getPayment());
}

TEST(TestDriver, getName) {
  std::string n = "Vasilii";
  Driver d(156, n, 130);
  EXPECT_EQ("Vasilii", d.getName());
}

TEST(TestProgrammer, getPos) {
  Project p;
  p.id = 3030;
  p.budget = 10000;
  std::string n = "Vasilii";
  Programmer d(156, n, 500, &p);
  EXPECT_EQ(d.getPos(), PROGRAMMER);
}

TEST(TestProgrammer, calc) {
  Project p;
  p.id = 3030;
  p.budget = 10000;
  std::string n = "Vasilii";
  Programmer d(156, n, 500, &p);
  d.setWorkTime(200);
  d.calc();
  EXPECT_EQ(d.getPayment(), 500 * 200 + 15000 + 100);
}

TEST(TestProgrammer, getProject) {
  Project p;
  p.id = 3030;
  p.budget = 10000;
  std::string n = "Vasilii";
  Programmer d(156, n, 500, &p);
  EXPECT_EQ(d.getProject(), &p);
}

TEST(TestTester, getPos) {
  Project p;
  p.id = 3030;
  p.budget = 10000;
  std::string n = "Vasilii";
  Tester d(156, n, 500, &p);
  EXPECT_EQ(d.getPos(), TESTER);
}

TEST(TestTester, calc) {
  Project p;
  p.id = 3030;
  p.budget = 10000;
  std::string n = "Vasilii";
  Tester d(156, n, 500, &p);
  d.setWorkTime(200);
  d.incErrorsFound();
  d.incErrorsFound();
  d.incErrorsFound();
  d.calc();
  EXPECT_EQ(d.getPayment(), 500 * 200 + 300 * 3 + 100);
}

TEST(TeamLeader, getPos) {
  Project p;
  p.id = 3030;
  p.budget = 10000;
  std::string n = "Vasilii";
  TeamLeader d(156, n, 500, &p, 10);
  EXPECT_EQ(d.getPos(), TEAMLEADER);
}

TEST(TeamLeader, getName) {
  Project p;
  p.id = 3030;
  p.budget = 10000;
  std::string n = "Vasilii";
  TeamLeader d(156, n, 500, &p, 10);
  EXPECT_EQ(d.getName(), "Vasilii");
}

TEST(TeamLeader, getSubb) {
  Project p;
  p.id = 3030;
  p.budget = 10000;
  std::string n = "Vasilii";
  TeamLeader d(156, n, 500, &p, 10);
  EXPECT_EQ(d.getSubbordinates(), 10);
}

TEST(TeamLeader, calc) {
  Project p;
  p.id = 3030;
  p.budget = 10000;
  std::string n = "Vasilii";
  TeamLeader d(156, n, 800, &p, 10);
  d.setWorkTime(200);
  d.calc();
  EXPECT_EQ(d.getPayment(), 800 * 200 + 15000 + 10 * 1000);
}

