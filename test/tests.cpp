// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Employee.h"
#include "../include/Engineer.h"
#include "../include/Factory.h"
#include "../include/Manager.h"
#include "../include/Personal.h"

TEST(Staff, test1) {
  std::string myname = "Ne Daria";
  auto *newbie = new Driver(1, myname, Position(DRIVER), 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBase(newbie->salary, newbie->worktime),
            newbie->worktime * newbie->salary);
}

TEST(Staff, test2) {
  std::string myname = "Ne Daria";
  auto *newbie = new Cleaner(1, myname, Position(CLEANER), 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBase(newbie->salary, newbie->worktime),
            newbie->worktime * newbie->salary);
}

TEST(Staff, test3) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie =
      new Programmer(1, myname, Position(PROGRAMMER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBase(newbie->salary, newbie->worktime),
            newbie->worktime * newbie->salary);
}

TEST(Staff, test4) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie =
      new Programmer(1, myname, Position(PROGRAMMER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcProAdditions(), 1);
}

TEST(Staff, test5) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie =
      new Programmer(1, myname, Position(PROGRAMMER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBonus(), 10);
}

TEST(Staff, test6) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie =
      new Programmer(1, myname, Position(PROGRAMMER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBudgetPart(10, 10000), 1000);
}

TEST(Staff, test7) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie =
      new TeamLeader(1, myname, Position(TEAM_LEADER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcHeads(), 4);
}

TEST(Staff, test8) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie =
      new TeamLeader(1, myname, Position(TEAM_LEADER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcProAdditions(), 1);
}

TEST(Staff, test9) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  auto *newbie = new Tester(1, myname, Position(TESTER), 10, project, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBonus(), 30);
}

TEST(Staff, test10) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  std::vector<Project *> mine;
  mine.push_back(project);
  auto *newbie =
      new ProjectManager(1, myname, Position(PROJECT_MANAGER), mine, 10, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcProAdditions(), 50);
}

TEST(Staff, test11) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  project->team = 10;
  std::vector<Project *> mine;
  mine.push_back(project);
  auto *newbie =
      new ProjectManager(1, myname, Position(PROJECT_MANAGER), mine, 10, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcHeads(), 10 * 1000);
}

TEST(Staff, test12) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  project->team = 10;
  std::vector<Project *> mine;
  mine.push_back(project);
  mine.push_back(project);
  auto *newbie =
      new SeniorManager(1, myname, Position(SENIOR_MANAGER), mine, 10, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcHeads(), 10 * 1000 * 2);
}

TEST(Staff, test13) {
  std::string myname = "Ne Daria";
  std::string name = "Save Cats";
  auto *project = new Project(1, name, 10000);
  project->team = 10;
  std::vector<Project *> mine;
  mine.push_back(project);
  auto *newbie =
      new SeniorManager(1, myname, Position(SENIOR_MANAGER), mine, 10, 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->calcBudgetPart(10, 10000), 1000);
}

TEST(Staff, test14) {
  std::string myname = "Ne Daria";
  auto *newbie = new Driver(1, myname, Position(DRIVER), 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->getId(), 1);
}

TEST(Staff, test15) {
  std::string myname = "Ne Daria";
  auto *newbie = new Driver(1, myname, Position(DRIVER), 10);

  newbie->setWorkTime(10);

  EXPECT_EQ(newbie->getPosition(), 6);
}
