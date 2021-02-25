// Copyright 2021 by Bodrov Egor

#include <gtest/gtest.h>
#include <string>

#include "Factory.h"

TEST(laba, test1) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  EXPECT_EQ(10, proger.getId());
}

TEST(laba, test2) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  EXPECT_EQ("asd", proger.getName());
}

TEST(laba, test3) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  EXPECT_EQ("Programmer", proger.getPos());
}

TEST(laba, test4) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  proger.calc();
  EXPECT_EQ(7200, proger.getPayment());
}

TEST(laba, test5) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  proger.setWorkTime(50);
  EXPECT_EQ(50, proger.getWorkTime());
}

TEST(laba, test6) {
  TeamLeader proger(10, 100, "asd", new Project(10000, "test"), 0.6);
  EXPECT_EQ(5000, proger.calcHeads());
}

TEST(laba, test7) {
  TeamLeader proger(10, 100, "asd", new Project(10000, "test"), 0.6);
  EXPECT_EQ(1200, proger.calcProAdditions());
}

TEST(laba, test8) {
  TeamLeader proger(10, 100, "asd", new Project(10000, "test"), 0.1);
  EXPECT_EQ(0, proger.calcProAdditions());
}

TEST(laba, test9) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  ProjectManager proger(10, "asd", "ProjectManager", v, 0.4);
  EXPECT_EQ(400, proger.calcBudgetPart(0.4, v[0]->getBudget()));
}

TEST(laba, test10) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  ProjectManager proger(10, "asd", "ProjectManager", v, 0.4);
  EXPECT_EQ(800, proger.calcBudgetPart(0.4, v[1]->getBudget()));
}

TEST(laba, test11) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  ProjectManager proger(10, "asd", "ProjectManager", v, 0.4);
  EXPECT_EQ(1200, proger.calcBudgetPart(0.4, v[2]->getBudget()));
}

TEST(laba, test12) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  SeniorManager proger(10, "asd", v, 0.5);
  proger.calc();
  EXPECT_EQ(10150, proger.getPayment());
}

TEST(laba, test13) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  EXPECT_EQ("test2", v[1]->getTitle());
}

TEST(laba, test14) {
  Driver d(10, 100, "asd");
  d.setWorkTime(50);
  d.calc();
  EXPECT_EQ(6500, d.getPayment());
}

TEST(laba, test15) {
  Cleaner c(10, 70, "asd");
  c.setWorkTime(50);
  EXPECT_EQ(910, c.calcBonus());
}
