// Copyright 2021 TimurZaytsev
//

#include <gtest/gtest.h>

#include <string>

#include "Factory.h"

TEST(lab, test1) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  EXPECT_EQ(10, proger.getId());
}

TEST(lab, test2) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  EXPECT_EQ("Programmer", proger.getPos());
}

TEST(lab, test3) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  EXPECT_EQ("test2", v[1]->getTitle());
}

TEST(lab, test4) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  proger.calc();
  EXPECT_EQ(7200, proger.getPayment());
}

TEST(lab, test5) {
  TeamLeader proger(10, 100, "asd", new Project(10000, "test"), 0.1);
  EXPECT_EQ(0, proger.calcPAditions());
}

TEST(lab, test6) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  proger.setTimeWork(50);
  EXPECT_EQ(50, proger.getWorkTime());
}

TEST(lab, test7) {
  TeamLeader proger(10, 100, "asd", new Project(10000, "test"), 0.6);
  EXPECT_EQ(1200, proger.calcPAditions());
}

TEST(lab, test8) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  ProjectManager proger(10, "asd", "ProjectManager", v, 0.4);
  EXPECT_EQ(400, proger.calcPartOfBudget(0.4, v[0]->getBudget()));
}

TEST(lab, test9) {
  TeamLeader proger(10, 100, "asd", new Project(10000, "test"), 0.6);
  EXPECT_EQ(5000, proger.calcHeads());
}

TEST(lab, test10) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  ProjectManager proger(10, "asd", "ProjectManager", v, 0.4);
  EXPECT_EQ(800, proger.calcPartOfBudget(0.4, v[1]->getBudget()));
}

TEST(lab, test11) {
  Driver d(10, 100, "asd");
  d.setTimeWork(50);
  d.calc();
  EXPECT_EQ(6500, d.getPayment());
}

TEST(lab, test12) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  ProjectManager proger(10, "asd", "ProjectManager", v, 0.4);
  EXPECT_EQ(1200, proger.calcPartOfBudget(0.4, v[2]->getBudget()));
}

TEST(lab, test13) {
  Programmer proger(10, 100, "asd", "Programmer", new Project(10000, "test"),
                    0.6);
  EXPECT_EQ("asd", proger.getName());
}

TEST(lab, test14) {
  std::vector<Project*> v;
  v.push_back(new Project(1000, "test1"));
  v.push_back(new Project(2000, "test2"));
  v.push_back(new Project(3000, "test3"));
  SeniorManager proger(10, "asd", v, 0.5);
  proger.calc();
  EXPECT_EQ(10150, proger.getPayment());
}

TEST(lab, test15) {
  Cleaner c(10, 70, "asd");
  c.setTimeWork(50);
  EXPECT_EQ(910, c.calcBonus());
}
