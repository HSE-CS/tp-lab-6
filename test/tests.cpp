// Copyright 2021 Danyaev Artem

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Factory.h"

TEST(tests, test1) {
    std::string s = "Ivan";
    Driver d(1, s, DRIVER, 10);
    EXPECT_EQ(1, d.getId());
}

TEST(tests, test2) {
    std::string s = "Ivan";
    Driver d(1, s, DRIVER, 10);
    EXPECT_EQ("Ivan", d.getName());
}

TEST(tests, test3) {
    std::string s = "Ivan";
    Driver d(1, s, DRIVER, 10);
    EXPECT_EQ(DRIVER, d.getPosition());
}

TEST(tests, test4) {
    std::string s = "Ivan";
    Driver d(1, s, DRIVER, 10);
    d.setWorkTime(10);
    EXPECT_EQ(10, d.getWorkTime());
}

TEST(tests, test4) {
    std::string s = "Ivan";
    Driver d(1, s, DRIVER, 10);
    d.setWorkTime(1);
    d.calc();
    EXPECT_EQ(510, d.getPayment());
}

TEST(tests, test5) {
    std::string s = "Ivan";
    Driver d(1, s, CLEANER, 10);
    d.setWorkTime(1);
    d.calc();
    EXPECT_EQ(10, d.getPayment());
}

TEST(tests, test6) {
    std::string s = "project";
    Project p(1, s, 1000);
    EXPECT_EQ(1000, p.getBudget());
}

TEST(tests, test7) {
    std::string s = "project";
    Project p(1, s, 1000);
    EXPECT_EQ("project", p.getName());
}

TEST(tests, test8) {
    std::string s1 = "project";
    Project *p = new Project(1, s1, 10);
    p->numOfWorkers = 2;
    std::string s2 = "Ivan";
    Tester t(2, s2, TESTER, 100, p);
    t.calc();
    EXPECT_EQ(505, t.getPayment());
}

TEST(tests, test9) {
    std::string s1 = "project";
    Project* p = new Project(1, s1, 10);
    p->numOfWorkers = 2;
    std::string s2 = "Ivan";
    Programmer t(2, s2, PROGRAMMER, 100, p);
    t.calc();
    EXPECT_EQ(1005, t.getPayment());
}

TEST(tests, test10) {
    std::string s1 = "project";
    Project* p = new Project(1, s1, 10);
    p->numOfWorkers = 2;
    std::string s2 = "Ivan";
    TeamLeader t(2, s2, TEAM_LEADER, 100, p);
    t.calc();
    EXPECT_EQ(405, t.getPayment());
}

TEST(tests, test11) {
    std::string s1 = "project";
    Project* p = new Project(1, s1, 10);
    p->numOfWorkers = 2;
    std::string s2 = "Ivan";
    TeamLeader t(2, s2, TEAM_LEADER, 100, p);
    t.setWorkTime(1);
    t.calc();
    EXPECT_EQ(505, t.getPayment());
}

TEST(tests, test12) {
    std::string s1 = "project";
    Project* p = new Project(1, s1, 10);
    p->numOfWorkers = 2;
    std::string s2 = "Ivan";
    ProjectManager t(2, s2, PROJECT_MANAGER, p);
    t.calc();
    EXPECT_EQ(605, t.getPayment());
}

TEST(tests, test13) {
    std::string s1 = "project";
    Project* p = new Project(1, s1, 10);
    p->numOfWorkers = 2;
    std::vector <Project*> v;
    v.push_back(p);
    std::string s2 = "Ivan";
    SeniorManager t(2, s2, SENIOR_MANAGER, v);
    t.calc();
    EXPECT_EQ(405, t.getPayment());
}

TEST(tests, test14) {
    std::string s1 = "project1";
    Project* p1 = new Project(11, s1, 10);
    p1->numOfWorkers = 2;
    std::string s2 = "project2";
    Project* p2 = new Project(12, s2, 20);
    p2->numOfWorkers = 2;
    std::vector <Project*> v;
    v.push_back(p1);
    v.push_back(p2);
    std::string s3 = "Ivan";
    SeniorManager t(2, s3, SENIOR_MANAGER, v);
    t.calc();
    EXPECT_EQ(815, t.getPayment());
}

TEST(tests, test15) {
    std::string s1 = "project1";
    Project* p1 = new Project(11, s1, 10);
    p1->numOfWorkers = 1;
    std::string s2 = "project2";
    Project* p2 = new Project(12, s2, 20);
    p2->numOfWorkers = 1;
    std::vector <Project*> v;
    v.push_back(p1);
    v.push_back(p2);
    std::string s3 = "Ivan";
    SeniorManager t(2, s3, SENIOR_MANAGER, v);
    t.calc();
    EXPECT_EQ(430, t.getPayment());
}
