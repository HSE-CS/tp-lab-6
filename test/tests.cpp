// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

#include "../include/Employee.h"
#include "../include/Engineer.h"
#include "../include/Factory.h"
#include "../include/Manager.h"
#include "../include/Personal.h"
#include <string>

TEST(Staff, test1) {
  auto *newbie = new Driver(1, (std::string &)"Ne Daria", Position(DRIVER), 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBase(newbie->salary, newbie->worktime),
            newbie->worktime * newbie->salary);
}

TEST(Staff, test2) {
  auto *newbie =
      new Cleaner(1, (std::string &)"Ne Daria", Position(CLEANER), 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBase(newbie->salary, newbie->worktime),
            newbie->worktime * newbie->salary);
}

TEST(Staff, test3) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie = new Programmer(1, (std::string &)"Ne Daria",
                                Position(PROGRAMMER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBase(newbie->salary, newbie->worktime),
            newbie->worktime * newbie->salary);
}

TEST(Staff, test4) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie = new Programmer(1, (std::string &)"Ne Daria",
                                Position(PROGRAMMER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcProAdditions(), 1);
}

TEST(Staff, test5) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie = new Programmer(1, (std::string &)"Ne Daria",
                                Position(PROGRAMMER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBonus(), 10);
}

TEST(Staff, test6) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie = new Programmer(1, (std::string &)"Ne Daria",
                                Position(PROGRAMMER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBudgetPart(10, 10000), 1000);
}

TEST(Staff, test7) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie = new TeamLeader(1, (std::string &)"Ne Daria",
                                Position(TEAM_LEADER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcHeads(), 4);
}

TEST(Staff, test8) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie = new TeamLeader(1, (std::string &)"Ne Daria",
                                Position(TEAM_LEADER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcProAdditions(), 1);
}

TEST(Staff, test9) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie = new Tester(1, (std::string &)"Ne Daria", Position(TESTER), 10,
                            project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBonus(), 30);
}

TEST(Staff, test10) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  std::vector<Project *> mine;
  mine.push_back(project);
  auto *newbie = new ProjectManager(1, (std::string &)"Ne Daria",
                                    Position(PROJECT_MANAGER), mine, 10, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcProAdditions(), 50);
}

TEST(Staff, test11) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  project->team = 10;
  std::vector<Project *> mine;
  mine.push_back(project);
  auto *newbie = new ProjectManager(1, (std::string &)"Ne Daria",
                                    Position(PROJECT_MANAGER), mine, 10, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcHeads(), 10 * 1000);
}

TEST(Staff, test12) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  project->team = 10;
  std::vector<Project *> mine;
  mine.push_back(project);
  mine.push_back(project);
  auto *newbie = new SeniorManager(1, (std::string &)"Ne Daria",
                                   Position(SENIOR_MANAGER), mine, 10, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcHeads(), 10 * 1000 * 2);
}

TEST(Staff, test13) {
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  project->team = 10;
  std::vector<Project *> mine;
  mine.push_back(project);
  auto *newbie = new SeniorManager(1, (std::string &)"Ne Daria",
                                   Position(SENIOR_MANAGER), mine, 10, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBudgetPart(10, 10000), 1000);
}

TEST(Staff, test14) {
  auto *newbie = new Driver(1, (std::string &)"Ne Daria", Position(DRIVER), 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->getId(), 1);
}

TEST(Staff, test15) {
  auto *newbie = new Driver(1, (std::string &)"Ne Daria", Position(DRIVER), 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->getPosition(), 6);
}
