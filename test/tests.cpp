// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Factory.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

TEST(function, test1) {
  Driver driver("1", "Edie Hancock", DRIVER, 100);
  EXPECT_EQ("1", driver.GetId());
}

TEST(function, test2) {
  Driver driver("1", "Edie Hancock", DRIVER, 100);
  EXPECT_EQ("Edie Hancock", driver.GetName());
}

TEST(function, test3) {
  Cleaner cleaner("2", "Alf Reed", CLEANER, 90);
  EXPECT_EQ(CLEANER, cleaner.GetPosition());
}

TEST(function, test4) {
  Programmer programmer("3",
                        "Zoe Welch",
                        PROGRAMMER,
                        120,
                        new Project("EA23PO", 100000));
  EXPECT_EQ(PROGRAMMER, programmer.GetPosition());
}

TEST(function, test5) {
  auto *driver = new Driver("1", "Edie Hancock", DRIVER, 100);
  EXPECT_EQ(DRIVER, driver->GetPosition());
}

TEST(function, test6) {
  auto *driver = new Driver("1", "Edie Hancock", DRIVER, 100);
  driver->SetWorkTime(50);
  driver->calc();
  EXPECT_EQ(6000, driver->GetPayment());
}

TEST(function, test7) {
  auto *cleaner = new Cleaner("2", "Alf Reed", CLEANER, 90);
  cleaner->SetWorkTime(40);
  cleaner->calc();
  EXPECT_EQ(3600, cleaner->GetPayment());
}

TEST(function, test8) {
  auto *programmer = new Programmer("3",
                                    "Zoe Welch",
                                    PROGRAMMER,
                                    120,
                                    new Project("EA23PO", 100000));
  programmer->SetWorkTime(40);
  programmer->calc();
  EXPECT_EQ(14800, programmer->GetPayment());
}

TEST(function, test9) {
  auto *tester = new Tester("4",
                            "Phil Spenser",
                            PROGRAMMER,
                            115,
                            new Project("EA23PO", 100000));
  tester->SetWorkTime(40);
  tester->calc();
  EXPECT_EQ(14600, tester->GetPayment());
}

TEST(function, test10) {
  auto *programmer = new Programmer("3",
                                    "Zoe Welch",
                                    PROGRAMMER,
                                    120,
                                    new Project("EA23PO", 100000));
  programmer->SetWorkTime(40);
  programmer->calc();
  programmer->calcProAdditions();
  EXPECT_EQ(20800, programmer->GetPayment());
}

TEST(function, test11) {
  auto *tester = new Tester("4",
                            "Phil Spenser",
                            PROGRAMMER,
                            115,
                            new Project("EA23PO", 100000));
  tester->SetWorkTime(40);
  tester->calc();
  tester->calcProAdditions();
  EXPECT_EQ(19600, tester->GetPayment());
}

TEST(function, test12) {
  auto *tl = new TeamLeader("5",
                            "Herb Sharp",
                            TEAMLEADER,
                            120,
                            new Project("EA23PO", 100000));
  tl->SetWorkTime(40);
  tl->calc();
  EXPECT_EQ(34800, tl->GetPayment());
}

TEST(function, test13) {
  std::vector<Project *> projects;
  projects.push_back(new Project("R012", 100000));
  auto *projectManager = new ProjectManager("6",
                                            "Winston Robson",
                                            PROJECTMANAGER,
                                            projects);

  EXPECT_EQ("R012", projectManager->GetProjects()[0]->GetId());
}

TEST(function, test14) {
  std::vector<Project *> projects;
  projects.push_back(new Project("R012", 100000));
  projects.push_back(new Project("R014", 100000));
  auto *seniorManager = new SeniorManager("7",
                                           "Benjamin Button",
                                           SENIORMANAGER,
                                           projects);

  EXPECT_EQ("R014", seniorManager->GetProjects()[1]->GetId());
}

TEST(function, test15) {
  std::vector<Project *> projects;
  projects.push_back(new Project("R012", 100000));
  auto *projectManager = new ProjectManager("6",
                                            "Winston Robson",
                                            PROJECTMANAGER,
                                            projects);
  projectManager->calc();
  EXPECT_EQ(20000, projectManager->GetPayment());
}

TEST(function, test16) {
  std::vector<Project *> projects;
  projects.push_back(new Project("R012", 100000));
  projects.push_back(new Project("R014", 100000));
  auto *seniorManager = new SeniorManager("7",
                                          "Benjamin Button",
                                          SENIORMANAGER,
                                          projects);
  seniorManager->calc();
  EXPECT_EQ(100000, seniorManager->GetPayment());
}
