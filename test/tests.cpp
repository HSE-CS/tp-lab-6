// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

TEST(test_cleaner, test1) {
auto* cleaner = new Cleaner(0,
                                 "Elena Alekseevna", 8, 7000, CLEANER);
int res = cleaner->calc();
EXPECT_EQ(63000, res);
}
TEST(test_cleaner, test2) {
auto* em = new Cleaner(0,
                                 "Elena Alekseevna", 3, 1000, CLEANER);
int res = em->calc();
EXPECT_EQ(4000, res);
}
TEST(test_cleaner, test3) {
auto* em = new Cleaner(0,
                                 "Elena Alekseevna", 1, 500, CLEANER);
int res = em->calc();
EXPECT_EQ(1000, res);
}
TEST(test_driver, test4) {
auto* em = new Driver(0,
                       "Elena Alekseevna", 1, 500, DRIVER);
int res = em->calc();
EXPECT_EQ(1500, res);
}
TEST(test_driver, test5) {
auto* em = new Driver(0,
                       "Elena Alekseevna", 4, 2000, DRIVER);
int res = em->calc();
EXPECT_EQ(12000, res);
}
TEST(test_programmer, test6) {
auto* em = new Programmer(0,
                       "Elena Alekseevna", 5, 500, PROGRAMMER,
                       new Project(1, "Telegram", 5000, 1));
int res = em->calc();
EXPECT_EQ(7500, res);
}
TEST(test_programmer2, test7) {
auto* em = new Programmer(0,
                          "Elena Alekseevna", 3000,
                          2, PROGRAMMER, nullptr);
int res = em->calc();
EXPECT_EQ(6010, res);
}

TEST(test_programmer3, test8) {
auto* em = new Programmer(0,
                          "Elena Alekseevna", 5, 500, PROGRAMMER,
                          new Project(1, "Telegram", 1000, 3));
int res = em->calc();
EXPECT_EQ(4343, res);
}

TEST(test_programmer4, test9) {
auto* em = new Programmer(0,
                          "Elena Alekseevna", 5, 2000, PROGRAMMER,
                          new Project(1, "Telegram", 10000, 3));
int res = em->calc();
EXPECT_EQ(9545, res);
}

TEST(test_programmer5, test10) {
auto* em = new Programmer(0,
                          "Elena Alekseevna", 5, 2000, PROGRAMMER,
                          new Project(1, "Telegram", 10000, 4));
int res = em->calc();
EXPECT_EQ(4343, res);
}

TEST(test_programmer6, test11) {
auto* em = new Programmer(0,
                          "Elena Alekseevna", 8, 5000, PROGRAMMER,
                          new Project(1, "Telegram", 20000, 3));
int res = em->calc();
EXPECT_EQ(4343, res);
}

TEST(test_tester, test12) {
auto* em = new Tester(0,
                          "Elena Alekseevna", 5, 500, TESTER,
                          new Project(1, "Telegram", 1000, 3));
int res = em->calc();
EXPECT_EQ(4343, res);
}

TEST(test_tester2, test13) {
auto* em = new Programmer(0,
                          "Elena Alekseevna", 5, 500, TESTER,
                          nullptr);
int res = em->calc();
EXPECT_EQ(4343, res);
}

TEST(test_team_leader, test14) {
auto* em = new TeamLeader(0,
                          "Elena Alekseevna", 5, 2000, TEAM_LEADER,
                          new Project(1, "Telegram", 10000, 3));
int res = em->calc();
EXPECT_EQ(4343, res);
}

TEST(test_pm, test15) {
std::vector<Project *> ps = {new Project(1, "Telegram", 10000, 3)};
auto* em = new ProjectManager(0,
                          "Elena Alekseevna", 8, PROJECT_MANAGER,
                          ps);
int res = em->calc();
EXPECT_EQ(4343, res);
}
