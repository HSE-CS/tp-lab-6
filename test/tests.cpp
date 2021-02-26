// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

TEST(test, test1) {
    Employee* employee = new Programmer(0,
                                        "mark", 8, PROGRAMMER, 8000, nullptr);
    std::string name = employee->getFullName();
    EXPECT_EQ("mark", name);
}

TEST(test, test2) {
    Employee* employee = new Programmer(0,
                                        "mark", 8, PROGRAMMER, 8000, nullptr);
    int id = employee->getId();
    EXPECT_EQ(0, id);
}

TEST(test, test3) {
    Employee* employee = new Programmer(0,
                                    "mark", 8, PROGRAMMER, 8000, nullptr);
    int time = employee->getWorkTime();
    EXPECT_EQ(8, time);
}

TEST(test, test4) {
    Engineer* employee = new Programmer(0,
                                    "mark", 8, PROGRAMMER, 8000, nullptr);
    int base = employee->calcBase();
    EXPECT_EQ(64000, base);
}

TEST(test, test5) {
    Employee* employee = new Programmer(0,
                                    "mark", 8, PROGRAMMER, 8000, nullptr);
    std::string position = employee->getPosition();
    EXPECT_EQ("Programmer", position);
}

TEST(test, test6) {
    Project* project = new Project(0, "Project", 12345);
    project->closeProject();
    Employee* employee = new Programmer(0,
                                    "mark", 8, PROGRAMMER, 8000, project);
    employee->calc();
    int payment = employee->getPayment();
    EXPECT_EQ(108345, payment);
}

TEST(test, test7) {
    Project* project = new Project(0, "Project", 12345);
    Employee* employee = new Programmer(0,
                                        "mark", 8, PROGRAMMER, 8000, project);
    Employee* employee1 = new Programmer(1,
                                        "max", 8, PROGRAMMER, 7000, project);
    TeamLeader* lead = new TeamLeader(0, "alex", 8, TEAM_LEADER, 7000, project);
    int heads = lead->calcHeads();
    EXPECT_EQ(2, heads);
}

TEST(test, test8) {
    Project* project = new Project(0, "Project", 12345);
    Employee* employee = new Programmer(0,
                                        "mark", 8, PROGRAMMER, 8000, project);
    Employee* employee1 = new Programmer(1,
                                         "max", 8, PROGRAMMER, 7000, project);
    TeamLeader* lead = new TeamLeader(0, "alex", 8, TEAM_LEADER, 7000, project);
    lead->calc();
    int payment = lead->getPayment();
    EXPECT_EQ(60115, heads);
}

TEST(test, test9) {
    Driver* driver = new Driver(0, "mark", 8, DRIVER, 200, 0.5);
    driver->calc();
    int payment = driver->getPayment();
    EXPECT_EQ(1700, heads);
}

TEST(test, test10) {
    Driver* driver = new Driver(0, "mark", 8, DRIVER, 200, 0.5);
    int bonus = driver->calcBonus();
    EXPECT_EQ(100, bonus);
}

TEST(test, test11) {
    Driver* driver = new Driver(0, "mark", 8, DRIVER, 200, 0.5);
    int base = driver->calcBase();
    EXPECT_EQ(1600, base);
}

TEST(test, test12) {
    Cleaner* cleaner = new Cleaner(0, "mark", 8, CLEANER, 200);
    int base = cleaner->calcBase();
    EXPECT_EQ(1600, base);
}

TEST(test, test13) {
    Cleaner* cleaner = new Cleaner(0, "mark", 8, CLEANER, 200);
    cleaner->calc();
    int payment = cleaner->getPayment();
    EXPECT_EQ(1600, payment);
}

TEST(test, test14) {
    Project* project = new Project(0, "Project", 12345);
    Employee* employee = new Programmer(0,
                                        "mark", 8, PROGRAMMER, 8000, project);
    Employee* employee1 = new Programmer(1,
                                         "max", 8, PROGRAMMER, 7000, project);
    TeamLeader* lead = new TeamLeader(0, "alex", 8, TEAM_LEADER, 7000, project);
    ProjectManager* manager = new ProjectManager(0, "ivan",
                                                 12, PROJECT_MANAGER, project);
    manager->calc();
    int payment = manager->getPayment();
    EXPECT_EQ(3178, payment);
}

TEST(test, test15) {
    ProjectManager* manager = new ProjectManager(0, "ivan",
                                                 12, PROJECT_MANAGER, nullptr);
    manager->calc();
    int payment = manager->getPayment();
    EXPECT_EQ(0, payment);
}

TEST(test, test16) {
    Project* project = new Project(0, "Project", 12345);
    Employee* employee = new Programmer(0,
                                        "mark", 8, PROGRAMMER, 8000, project);
    Employee* employee1 = new Programmer(1,
                                         "max", 8, PROGRAMMER, 7000, project);
    TeamLeader* lead = new TeamLeader(0, "alex", 8, TEAM_LEADER, 7000, project);
    ProjectManager* manager = new ProjectManager(0, "ivan",
                                                 12, PROJECT_MANAGER, project);
    int heads = manager->calcHeads();
    EXPECT_EQ(3, heads);
}
