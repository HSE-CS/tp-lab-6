// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

TEST(testEmployee, test1) {
  Project* p = new Project(1, 6);
  Programmer* p = new Programmer(1, "Test", 20, "programmer", 5, p);
  EXPECT_EQ(1, p->getId());
}

TEST(testEmployee, test2) {
  Project* p = new Project(1, 6);
  Programmer* p = new Programmer(1, "Test", 20, "programmer", 5, p);
  EXPECT_EQ("Test", p->getName());
}

TEST(testEmployee, test3) {
  Project* p = new Project(1, 6);
  Programmer* p = new Programmer(1, "Test", 20, "programmer", 5, p);
  EXPECT_EQ(20, p->getSalary());
}

TEST(testEmployee, test4) {
  Project* p = new Project(1, 6);
  Programmer* p = new Programmer(1, "Test", 20, "programmer", 5, p);
  EXPECT_EQ("programmer", p.getPosition());
}

TEST(testEmployee, test5) {
  Project* p = new Project(1, 6);
  Programmer* p = new Programmer(1, "Test", 20, "programmer", 5, p);
  EXPECT_EQ(5, p->getPayment());
}

TEST(testEmployee, test6) {
  Project* p = new Project(1, 6);
  EXPECT_EQ(1, p->getId);
}

TEST(testEmployee, test7) {
  Project* p = new Project(1, 6);
  EXPECT_EQ(1, p->getBudget);
}

TEST(testEmployee, test8) {
  Driver* d = new Driver(10, "Test", "driver", 1, 15);
  EXPECT_EQ(1, d->getId());
}

TEST(testEmployee, test9) {
  Driver* d = new Driver(10, "Test", "driver", 1, 15);
  EXPECT_EQ(0, d->calcBonus());
}

TEST(testEmployee, test10) {
  Driver* d = new Driver(10, "Test", "driver", 1, 15);
  d->setWorktime(50);
  EXPECT_EQ(1000, d->calcBonus());
}

TEST(testEmployee, test11) {
  std::vector<Project*> pr;
  Project* p1 = new Project(0, 42);
  projects.push_back(p1);
  Project* p2 = new Project(2, 35);
  projects.push_back(p2);
  Project* p3 = new Project(5, 23);
  projects.push_back(p3);
  SeniorManager* s = new SeniorManager(1, "Test", "senior manager", 344, pr);
  EXPECT_EQ(1, s->getId());
}

TEST(testEmployee, test12) {
  std::vector<Project*> pr;
  Project* p1 = new Project(0, 42);
  projects.push_back(p1);
  Project* p2 = new Project(2, 35);
  projects.push_back(p2);
  Project* p3 = new Project(5, 23);
  projects.push_back(p3);
  SeniorManager* s = new SeniorManager(1, "Test", "senior manager", 344, pr);
  EXPECT_EQ("Test", s->getName());
}

TEST(testEmployee, test13) {
  std::vector<Project*> pr;
  Project* p1 = new Project(0, 42);
  projects.push_back(p1);
  Project* p2 = new Project(2, 35);
  projects.push_back(p2);
  Project* p3 = new Project(5, 23);
  projects.push_back(p3);
  SeniorManager* s = new SeniorManager(1, "Test", "senior manager", 344, pr);
  EXPECT_EQ("senior manager", s->getPosition());
}

TEST(testEmployee, test14) {
  std::vector<Project*> pr;
  Project* p1 = new Project(0, 42);
  projects.push_back(p1);
  Project* p2 = new Project(2, 35);
  projects.push_back(p2);
  Project* p3 = new Project(5, 23);
  projects.push_back(p3);
  SeniorManager* s = new SeniorManager(1, "Test", "senior manager", 344, pr);
  EXPECT_EQ(344, s->getPayment());
}

TEST(testEmployee, test15) {
  std::vector<Project*> pr;
  Project* p1 = new Project(0, 42);
  projects.push_back(p1);
  Project* p2 = new Project(2, 35);
  projects.push_back(p2);
  Project* p3 = new Project(5, 23);
  projects.push_back(p3);
  SeniorManager* s = new SeniorManager(1, "Test", "senior manager", 344, pr);
  EXPECT_EQ(0, s->getWorktime());
}
