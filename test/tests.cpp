// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Interfaces.h"


TEST(PesonalTest, test1) {
    std::string name = "Name";
    Cleaner test(1, name, 2, 2,50);
    EXPECT_EQ(1, test.getId());
}

TEST(PesonalTest, test2) {
    std::string name = "Name";
    Cleaner test(1, name, 2, 2, 50);
    EXPECT_EQ(name, test.getName());
}

TEST(PesonalTest, test3) {
    std::string name = "Name";
    Cleaner test(1, name, 2, 2, 50);
    EXPECT_EQ(100, test.getPayment());
}

TEST(PesonalTest, test4) {
    std::string name = "Name";
    Security test(1, name, 20, 3, 100, 3);
    EXPECT_EQ(47000, test.getPayment());
}

TEST(PesonalTest, test5) {
    std::string name = "Name";
    Driver test(1, name, 20, 1, 100);
    std::string work = "DRIVER";
    EXPECT_EQ(work, test.getPosition());
}

TEST(EngineerTest, test6) {
    std::string name = "Name";
    std::string name_proj = "Name_Pr";
    Project proj(1, 100, name_proj);
    Engineer test(1, name, 10, 4, &proj, 100);
    EXPECT_EQ(1100, test.getPayment());
}

TEST(EngineerTest, test7) {
    std::string name = "Name";
    std::string name_proj = "Name_Pr";
    std::string work = "ENGINEER";
    Project proj(1, 100, name_proj);
    Engineer test(1, name, 10, 4, &proj, 100);
    EXPECT_EQ(4, test.getPositionID());
}

TEST(EngineerTest, test8) {
    std::string name = "Name";
    std::string name_proj = "Name_Pr";
    std::string work = "ENGINEER";
    Project proj(1, 100, name_proj);
    Tester test(1, name, 10, 6, &proj, 1000);
    EXPECT_EQ(1000, test.getSalary());
}

TEST(EngineerTest, test9) {
    std::string name = "Name";
    std::string name_proj = "Name_Pr";
    std::string work = "ENGINEER";
    Project proj(1, 100, name_proj);
    Programmer test(1, name, 10, 5, &proj, 1000);
    int res = 0;
    if (test.getPayment() > test.calcBase())
        res = 1;
    EXPECT_EQ(1, res);
}

TEST(EngineerTest, test10) {
    std::string name = "Name";
    std::string name_proj = "Name_Pr";
    std::string work = "ENGINEER";
    Project proj(1, 100, name_proj);
    Programmer test1(1, name, 10, 5, &proj, 1000);
    Programmer test2(2, name, 10, 5, &proj, 1000);
    Programmer test3(3, name, 10, 5, &proj, 1000);
    TeamLeader test4(4, name, 10, 7, &proj, 1000);

    EXPECT_EQ(20000, test4.calcHeads());
}

TEST(ProjectTest, test11) {
    std::string name_proj = "Name_Pr";
    Project proj(1, 100, name_proj);
    EXPECT_EQ(1, proj.getId());
    EXPECT_EQ(100, proj.getBudget());
    EXPECT_EQ(name_proj, proj.getName());
}

TEST(ProjectTest, test12) {
    std::string name_proj = "Name_Pr";
    std::string name = "Name";
    Project proj(1, 100, name_proj);
    Programmer test1(1, name, 10, 5, &proj, 1000);
    Programmer test2(2, name, 10, 5, &proj, 1000);
    Programmer test3(3, name, 10, 5, &proj, 1000);
    EXPECT_EQ(3, proj.getNumWorker());
}

TEST(ProjectTest, test13) {
    std::string name_proj = "Name_Pr";
    std::string name = "Name";
    Project proj(1, 99, name_proj);
    Programmer test1(1, name, 10, 5, &proj, 1000);
    Programmer test2(2, name, 10, 5, &proj, 1000);
    Programmer test3(3, name, 10, 5, &proj, 1000);
    EXPECT_EQ(33, proj.getPart());
}

TEST(ManagerTest, test14) {
    std::string name_proj = "Name_Pr";
    std::string name = "Name";
    Project proj(1, 99, name_proj);
    Programmer test1(1, name, 10, 5, &proj, 1000);
    Programmer test2(2, name, 10, 5, &proj, 1000);
    ProjectManager test3(3, name, 10, 8, &proj);
    EXPECT_EQ(15033, test3.calc());
}

TEST(ManagerTest, test15) {
    std::string name_proj = "Name_Pr";
    std::string name = "Name";
    Project proj(1, 99, name_proj);
    Programmer test1(1, name, 10, 5, &proj, 1000);
    Programmer test2(2, name, 10, 5, &proj, 1000);
    ProjectManager test3(3, name, 10, 8, &proj);
    EXPECT_EQ(1, test3.NumOfProjects());
}

TEST(ManagerTest, test16) {
    std::string name_proj = "Name_Pr";
    std::string name = "Name";
    std::string work = "SENIORMANAGER";
    Project proj1(1, 99, name_proj);
    Project proj2(2, 99, name_proj);
    Project proj3(1, 99, name_proj);
    Programmer test1(1, name, 10, 5, &proj1, 1000);
    Programmer test2(2, name, 10, 5, &proj1, 1000);
    Programmer test3(3, name, 10, 5, &proj2, 1000);
    Programmer test4(4, name, 10, 5, &proj2, 1000);
    Programmer test5(5, name, 10, 5, &proj3, 1000);
    Programmer test6(6, name, 10, 5, &proj3, 1000);
    std::vector <Project*> projects = { &proj1, &proj2, &proj3 };
    SeniorManager test(7, name, 2, 9, &projects);
    EXPECT_EQ(45000 , test.calcHeads());
    EXPECT_EQ(99, test.calcBugetParts());
    EXPECT_EQ(45099, test.calc());
    EXPECT_EQ(3, test.NumOfProjects());
    EXPECT_EQ(work, test.getPosition());
}
