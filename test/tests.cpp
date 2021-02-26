// Copyright 2020 GHA Test Team
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"

TEST(test, test1) {
    Personal* employee = new Cleaner(0,
        "Norma O'Brien", "cleaner", 800);
    EXPECT_EQ("Norma O'Brien", employee->getName());
}
TEST(test, test2) {
    Personal* employee = new Cleaner(0,
        "Norma O'Brien", "cleaner", 800);
    employee->setWorktime(32);
    EXPECT_EQ(36, employee->getWorktime());
}
TEST(test, test3) {
    Personal* employee = new Cleaner(0,
        "Norma O'Brien", "cleaner", 800);
    employee->setWorktime(32);
    employee->calc();
    EXPECT_EQ(employee->getSalary(), 56320);
}
TEST(test, test4) {
    Personal* employee = new Cleaner(0,
        "Norma O'Brien", "cleaner", 800);
    EXPECT_EQ(employee->getId(), 0);
}
TEST(test, test5) {
    Personal* employee = new Driver(0,
        "Darren Goodwin", "driver", 900);
    EXPECT_EQ("Darren Goodwin", employee->getName());
}
TEST(test, test6) {
    Personal* employee = new Driver(0,
        "Darren Goodwin", "driver", 900);
    employee->setWorktime(40);
    employee->calc();
    EXPECT_EQ(employee->getSalary(), 36000);
}

TEST(test, test7) {
    Project* project = new Project(0, 1000);
    Personal* employee = new Programmer(0,
        "Emmie Massey", "programmer", 1000, project);
    EXPECT_EQ("Emmie Massey", employee->getName());
}


TEST(test, test8) {
    Project* project = new Project(0, 1000);
    Personal* employee = new Programmer(0,
        "Emmie Massey", "programmer", 1000, project);
    employee->setWorktime(40);
    employee->calc();
    EXPECT_EQ(employee->getSalary(), 40040);
}
TEST(test, test9) {
    Project* project = new Project(0, 1000);
    Personal* employee = new Programmer(0,
        "Emmie Massey", "programmer", 1000, project);
    employee->setWorktime(45);
    employee->calc();
    EXPECT_EQ(employee->getSalary(), 180040);
}

TEST(test, test10) {
    Project* project = new Project(0, 1000);
    Personal* employee = new Tester(0,
        "Merlin Lott", "tester", 1000, project);
    EXPECT_EQ(employee->getPosition(), "tester");
}

TEST(test, test11) {
    Project* project = new Project(0, 1000);
    Tester* employee = new Tester(0,
        "Merlin Lott", "tester", 1000, project);
    employee->setMistakes(5);
    employee->setWorktime(40);
    employee->calc();
    EXPECT_EQ(employee->getSalary(), 40030);
}
TEST(test, test12) {
    std::vector<Project*> projects;
    Project* pr = new Project(0, 10000);
    projects.push_back(pr);
    Project* pr2 = new Project(0, 20000);
    projects.push_back(pr2);
    Project* pr3 = new Project(0, 50000);
    projects.push_back(pr3);
    SeniorManager* employee = new SeniorManager(0,
        "Nick Schmitt", "senior manager", 1000, projects);
    employee->setWorktime(40);
    employee->calc();
    EXPECT_EQ(employee->getSalary(), 24000);
}
TEST(test, test13) {
    Project* project = new Project(0, 1000);
    Personal* employee = new Tester(0,
        "Merlin Lott", "tester", 1000, project);
    EXPECT_EQ(employee->getName(), "Merlin Lott");
}

TEST(test, test14) {
    std::vector<Project*> projects;
    Project* pr = new Project(0, 10000);
    projects.push_back(pr);
    Project* pr2 = new Project(0, 20000);
    projects.push_back(pr2);
    Project* pr3 = new Project(0, 50000);
    projects.push_back(pr3);
    SeniorManager* employee = new SeniorManager(0,
        "Nick Schmitt", "senior manager", 1000, projects);
    EXPECT_EQ(employee->getPosition(), "senior manager");
}

TEST(test, test15) {
    std::vector<Project*> projects;
    Project* pr = new Project(0, 10000);
    projects.push_back(pr);
    Project* pr2 = new Project(0, 20000);
    projects.push_back(pr2);
    Project* pr3 = new Project(0, 50000);
    projects.push_back(pr3);
    SeniorManager* employee = new SeniorManager(0,
        "Nick Schmitt", "senior manager", 1000, projects);
    employee->setWorktime(40);
    EXPECT_EQ(employee->getWorktime(), 40);
}
