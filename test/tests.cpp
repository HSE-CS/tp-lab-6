// Copyright 2020 GHA Test Team

#include "gtest/gtest.h"
#include "Factory.h"
#include "Employee.h"
#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"

TEST(TestStaff, Test1) {
    Project pr = { 100, 23490 };
    Tester* emp = new Tester(10, "Igumnova Natasha", "Tester", 8, 550, pr);
    EXPECT_EQ(10, emp->getId());
}

TEST(TestStaff, Test2) {
    Project pr = { 100, 23490 };
    Tester* emp = new Tester(10, "Igumnova Natasha", "Tester", 8, 550, pr);
    EXPECT_EQ("Igumnova Natasha", emp->getName());
}

TEST(TestStaff, Test3) {
    Clener* emp = new Clener(10, "Ivanova Anna", "Clener", 4, 550);
    emp->setWorkTime(3);
    int res = 3 * 550;
    EXPECT_EQ(res, emp->calc());
}

TEST(TestStaff, Test4) {
    Project project = { 10, 40000 };
    std::vector<Project> projects;
    projects.push_back(project);
    ProjectManager* emp = new ProjectManager(11,
        "Ivanov Ilya", "ProjectManager", 5, 440, projects);
    EXPECT_EQ(emp->getWorktime(), 5);
}

TEST(TestStaff, Test5) {
    Project project = { 10, 40000 };
    std::vector<Project> projects;
    projects.push_back(project);
    ProjectManager* emp = new ProjectManager(10,
         "Ivanov Petr", "ProjectManager", 5, 700, projects);
    EXPECT_EQ(emp->getPayment(), 700);
}

TEST(TestStaff, Test6) {
    Project pr = { 100, 23490 };
    Tester* emp = new Tester(10, "Igumnova Natasha", "Tester", 8, 550, pr);
    int bonus = static_cast < int>(8 * 550 * 0.3);
    EXPECT_EQ(bonus, emp->calcBonus());
}

TEST(TestStaff, Test7) {
    Project pr = { 100, 23490 };
    Tester* emp = new Tester(10, "Igumnova Natasha", "Tester", 8, 550, pr);
    int base = 8 * 550;
    EXPECT_EQ(base, emp->calcBase(8, 550));
}

TEST(TestStaff, Test8) {
    Driver* emp = new Driver(10, "Petrov Ivan", "Driver", 4, 550);
    EXPECT_EQ("Driver", emp->getPosition());
}

TEST(TestStaff, Test9) {
    Project pr = { 100, 23490 };
    TeamLeader* emp = new TeamLeader(10,
        "Petrov Ivan", "TeamLeader", 4, 550, pr);
    EXPECT_EQ(23490, emp->getProject().budget);
}

TEST(TestStaff, Test10) {
    Clener* emp = new Clener(10, "Ivanova Anna", "Clener", 4, 550);
    EXPECT_EQ(0, emp->calcBonus());
}
