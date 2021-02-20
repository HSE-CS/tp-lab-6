// Copyright 2020 GHA Test Team
#include <gtest/gtest.h>
#include <string>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

TEST(Cleaner, make_cleaner) {
  Employee *employee = new Cleaner(0,
              "Katerina Tyulin",
              "cleaner",
              150);
  std::string rez = "Katerina Tyulin";
  EXPECT_EQ(employee->getName(), rez);
}

//TEST(Cleaner, cleaner_getId) {
//Employee *employee = new Cleaner(0,
//                                 "Katerina Tyulin",
//                                 "cleaner",
//                                 150);
//int rez = 0;
//EXPECT_EQ(employee->getId(), rez);
//
////  EXPECT_EQ(employee->getPayment(), 2);
////  EXPECT_EQ(employee->getSalary(), 0);
//}

TEST(Cleaner, cleaner_getSal) {
  Employee *employee = new Cleaner(0,
                                   "Katerina Tyulin",
                                   "cleaner",
                                   150);
  employee->setSalary(12000);
  int rez = 12000;
  EXPECT_EQ(employee->getSalary(), rez);
}

TEST(Cleaner, cleaner_getId) {
  Employee *employee = new Cleaner(0,
                                   "Katerina Tyulin",
                                   "cleaner",
                                   150);
  int rez = 0;
  EXPECT_EQ(employee->getId(), rez);
}

TEST(Cleaner, cleaner_getPos) {
  Employee *employee = new Cleaner(0,
                                   "Katerina Tyulin",
                                   "cleaner",
                                   150);
  std::string rez = "cleaner";
  EXPECT_EQ(employee->getPosition(), rez);
}

TEST(Driver, make_driver) {
  Employee *employee = new Driver(0,
                                   "Paula Gazz",
                                   "driver",
                                   300);
  std::string rez = "Paula Gazz";
  EXPECT_EQ(employee->getName(), rez);
}

TEST(Driver, driver_getPos) {
  Employee *employee = new Driver(0,
                                  "Paula Gazz",
                                  "driver",
                                  300);
  std::string rez = "driver";
  EXPECT_EQ(employee->getPosition(), rez);
}

TEST(Driver, driver_getWorkTime) {
  Employee *employee = new Driver(0,
                                  "Paula Gazz",
                                  "driver",
                                  300);
  employee->setWorkTime(41);
  int rez = 41;
  EXPECT_EQ(employee->getWorkTime(), rez);
}

TEST(Tester, make_tester) {
  Project *proj = new Project("ML", 500000);
  Employee *employee = new Tester(0,
                              "Jacob Hill",
                              "tester",
                              500, proj,
                              30);
  std::string rez = "Jacob Hill";
  EXPECT_EQ(employee->getName(), rez);
}

TEST(Tester, tester_getSal) {
  Project *proj = new Project("ML", 500000);
  Employee *employee = new Tester(0,
                              "Jacob Hill",
                              "tester",
                              500, proj,
                              30);
  int rez = 0;
  EXPECT_EQ(employee->getSalary(), rez);
}

TEST(Programmer, make_programmer) {
  Project *proj = new Project("ML", 500000);
  Employee *employee = new Programmer(0,
                              "Jacob Hill",
                              "programmer",
                              500, proj);
  std::string rez = "Jacob Hill";
  EXPECT_EQ(employee->getName(), rez);
}

TEST(Programmer, programmer_getPayment) {
  Project *proj = new Project("ML", 500000);
  Employee *employee = new Programmer(0,
                                      "Jacob Hill",
                                      "programmer",
                                      500, proj);
  int rez = 500;
  EXPECT_EQ(employee->getPayment(), rez);
}

TEST(Programmer, programmer_getProjId) {
  Project *proj = new Project("ML", 500000);
  Employee *employee = new Programmer(0,
                                      "Jacob Hill",
                                      "programmer",
                                      500, proj);
  std::string rez = "ML";
  EXPECT_EQ(proj->id, rez);
}

TEST(Programmer, programmer_getProjBudget) {
  Project *proj = new Project("ML", 500000);
  Employee *employee = new Programmer(0,
                                      "Jacob Hill",
                                      "programmer",
                                      500, proj);
  int rez = 500000;
  EXPECT_EQ(proj->budget, rez);
}

TEST(TeamLeader, make_TeamLeader) {
  Project *proj = new Project("ML", 500000);
  Employee *employee = new TeamLeader(0,
                                      "Jacob Hill",
                                      "team leader",
                                      1000, proj);
  std::string rez = "Jacob Hill";
  EXPECT_EQ(employee->getName(), rez);
}

TEST(TeamLeader, TeamLeader_getSalary) {
  Project *proj = new Project("ML", 500000);
  Employee *employee = new TeamLeader(0,
                                      "Jacob Hill",
                                      "team leader",
                                      1000, proj);
  employee->setWorkTime(10);
  int sal = employee->getPayment() * employee->getWorkTime();
  employee->setSalary(sal);
  int rez = 100000;
  EXPECT_EQ(employee->getSalary(), rez);
}

TEST(ProjManager, make_ProjManager) {
  Project *proj = new Project("ML", 500000);
  Employee *employee = new ProjManager(0,
                                      "Jacob Hill",
                                      "project manager",
                                      proj);
  std::string rez = "Jacob Hill";
  EXPECT_EQ(employee->getName(), rez);
}

TEST(SeniorManager, make_SeniorManager) {
  Project *proj1 = new Project("DA", 1000000);
  std::vector<Project *> projects;
  projects.push_back(proj1);
  Employee *employee = new SeniorManager(0,
                                         "Jacob Hill",
                                         "senior manager",
                                         projects);
  std::string rez = "Jacob Hill";
  EXPECT_EQ(employee->getName(), rez);
}

TEST(SeniorManager, SeniorManager_projId) {
  Project *proj1 = new Project("DA", 1000000);
  std::vector<Project *> projects;
  projects.push_back(proj1);
  Employee *employee = new SeniorManager(0,
                                         "Jacob Hill",
                                         "senior manager",
                                         projects);
  std::string rez = "DA";
  EXPECT_EQ(projects[0]->id, rez);
}