// Copyright 2021 Tatsenko Alexey
#include <gtest/gtest.h>
#include <string>
#include"Employee.h"
#include"Engineer.h"
#include"Manager.h"
#include"Personal.h"
#include<vector>

std::string converse_(Position pos) {
  if (pos == PROGRAMMER)
    return "Programmer";
  else if (pos == TESTER)
    return "Tester";
  else if (pos == DRIVER)
    return "Driver";
  else if (pos == CLEANER)
    return "Cleaner";
  else if (pos == ENGINEER)
    return "Engineer";
  else if (pos == SENIOR_MANAGER)
    return "SeniorManager";
  else if (pos == PROJECT_MANAGER)
    return "ProjectManager";
  else if (pos == TEAM_LEADER)
    return "TeamLeader";
}

TEST(TESTS, test1) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Programmer pr(1, name, PROGRAMMER, 30, &project, 0.3);
  EXPECT_EQ("Alex", pr.get_name());
}

TEST(TESTS, test2) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Programmer pr(1, name, PROGRAMMER, 30, &project, 0.3);
  EXPECT_EQ(1, pr.get_id());
}

TEST(TESTS, test3) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Programmer pr(1, name, PROGRAMMER, 30, &project, 0.3);
  EXPECT_EQ(static_cast<float>(0.3), pr.get_part());
}

TEST(TESTS, test4) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Programmer pr(1, name, PROGRAMMER, 30, &project, 0.3);
  EXPECT_EQ("Programmer", converse_(pr.get_position()));
}

TEST(TESTS, test5) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Programmer pr(1, name, PROGRAMMER, 30, &project, 0.3);
  pr.set_work_time(7);
  EXPECT_EQ(3510, pr.get_payment());
}

TEST(TESTS, test6) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Tester pr(1, name, TESTER, 30, &project, 0.3, 3);
  pr.set_work_time(11);
  EXPECT_EQ(810, pr.get_payment());
}

TEST(TESTS, test7) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Tester pr(1, name, TESTER, 30, &project, 0.3, 3);
  EXPECT_EQ("Tester", converse_(pr.get_position()));
}

TEST(TESTS, test8) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Tester pr(1, name, TESTER, 30, &project, 0.3, 3);
  EXPECT_EQ(1, pr.get_id());
}

TEST(TESTS, test9) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Driver dr(1, name, DRIVER, 30);
  dr.set_work_time(11);
  EXPECT_EQ(465, dr.get_payment());
}

TEST(TESTS, test10) {
  Driver dr(1, "Ilya", DRIVER, 30);
  dr.set_work_time(11);
  EXPECT_EQ("Driver", converse_(dr.get_position()));
}

TEST(TESTS, test11) {
  std::string name = "Alex";
  Cleaner cl(1, name, CLEANER, 30);
  EXPECT_EQ("Cleaner", converse_(cl.get_position()));
}

TEST(TESTS, test12) {
  Project project("LALALA", 1000);
  std::string name = "Alex";
  TeamLeader tl(1, name, TEAM_LEADER, 30, &project, 0.3);
  EXPECT_EQ("TeamLeader", converse_(tl.get_position()));
}

TEST(TESTS, test13) {
  std::vector<Project*> projects;
  Project project("LALALA", 1000);
  projects.push_back(&project);
  std::string name = "Alex";
  ProjectManager pt(1, name, PROJECT_MANAGER, projects, "LALALA");
  EXPECT_EQ("ProjectManager", converse_(pt.get_position()));
}

TEST(TESTS, test14) {
  std::vector<Project*> projects;
  Project project("LALALA", 1000);
  projects.push_back(&project);
  std::string name = "Alex";
  SeniorManager pt(1, name, SENIOR_MANAGER, projects);
  EXPECT_EQ("SeniorManager", converse_(pt.get_position()));
}

TEST(TESTS, test15) {
  std::string name = "Alex";
  Project project("LALALA", 1000);
  Tester pr(1, name, TESTER, 30, &project, 0.3, 3);
  pr.set_work_time(11);
  EXPECT_EQ("LALALA", project.get_name());
}
