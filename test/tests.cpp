// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Engineer.h"
#include "Manager.h"


TEST(test_driver, test1) {
Driver* driver1 = new Driver(0,
                             "Sergo", 500, 2, driver);
int payment = driver1->calc_salary();
EXPECT_EQ(1004, payment);
}
TEST(test_driver2, test2) {
Driver* driver1 = new Driver(0,
                             "Sergo", 1000, 2, driver);
int payment = driver1->calc_salary();
EXPECT_EQ(2004, payment);
}
TEST(test_cleaner, test3) {
Cleaner* cleaner1 = new Cleaner(0,
                                "Sergo", 1000, 2, cleaner);
int payment = cleaner1->calc_salary();
EXPECT_EQ(2000, payment);
}
TEST(test_cleaner2, test4) {
Cleaner* cleaner1 = new Cleaner(0,
                                "Sergo", 1000, 3, cleaner);
int payment = cleaner1->calc_salary();
EXPECT_EQ(3000, payment);
}
TEST(test_cleaner3, test5) {
Cleaner* cleaner1 = new Cleaner(0,
                                "Sergo", 500, 2, cleaner);
int payment = cleaner1->calc_salary();
EXPECT_EQ(1000, payment);
}
TEST(test_tester, test6) {
Project* project1 = new Project(0, 1000, 2);
Tester* tester1 = new Tester(0,
                             "Sergo", 2000, 2, tester, project1);
int payment = tester1->calc_salary();
EXPECT_EQ(4508, payment);
}

TEST(test_tester2, test7) {
Tester* tester2 = new Tester(0,
                             "Sergo", 2000, 2, tester, nullptr);
int payment = tester2->calc_salary();
EXPECT_EQ(4008, payment);
}
TEST(test_programmer, test8) {
Programmer* programmer1 = new Programmer(0,
                                         "Sergo", 1000, 2, programmer, nullptr);
int payment = programmer1->calc_salary();
EXPECT_EQ(2010, payment);
}

TEST(test_programmer2, test9) {
Programmer* programmer1 = new Programmer(0,
                                         "Sergo", 2000, 2, programmer, nullptr);
int payment = programmer1->calc_salary();
EXPECT_EQ(4010, payment);
}

TEST(test_programmer3, test10) {
Project* project1 = new Project(0, 1000, 3);
Programmer* programmer1 = new Programmer(0,
                                         "Sergo", 2000, 2,
                                         programmer, project1);
int payment = programmer1->calc_salary();
EXPECT_EQ(4343, payment);
}

TEST(test_programmer4, test11) {
Project* project1 = new Project(0, 2000, 5);
Programmer* programmer1 = new Programmer(0,
                                         "Sergo", 2000, 3,
                                         programmer, project1);
int payment = programmer1->calc_salary();
EXPECT_EQ(6415, payment);
}

TEST(test_programmer5, test12) {
Project* project1 = new Project(0, 2000, 4);
Programmer* programmer1 = new Programmer(0,
                                         "Sergo", 2000, 3,
                                         programmer, project1);
int payment = programmer1->calc_salary();
EXPECT_EQ(6515, payment);
}

TEST(test_programmer6, test13) {
Project* project1 = new Project(0, 1000, 1);
Programmer* programmer1 = new Programmer(0,
                                         "Sergo", 2000, 2,
                                         programmer, project1);
int payment = programmer1->calc_salary();
EXPECT_EQ(5010, payment);
}
TEST(test_team_leader, test14) {
Project* project1 = new Project(0, 1000, 4);
TeamLeader* teamLeader1 = new TeamLeader(0,
                                         "Sergo", 2000,
                                         2, team_leader, project1);
int payment = teamLeader1->calc_salary();
EXPECT_EQ(4258, payment);
}

TEST(test_pm, test15) {
Project* project1 = new Project(0, 1000, 4);
ProjectManager* projectManager1 = new ProjectManager(0,
                                                     "Sergo", 2000,
                                                     project_manager,
                                                     project1);
int payment = projectManager1->calc_salary();
EXPECT_EQ(650, payment);
}