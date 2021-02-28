// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Manager.h"


TEST(Test, test1) {
    Project proj;
    proj.setBudget(10000);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("Mark 2");
    Programmer p1("Mark Wolf", 8, &proj, PROGRAMMER, 128000);
    p1.calc(8);
    EXPECT_EQ(p1.getPayment(), 1024000);
}

TEST(Test, test2) {
    Project proj;
    proj.setBudget(1000000);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("Google Testing System 2021");
    Programmer p1("Mark Wolf", 8, &proj, PROGRAMMER, 64);
    Programmer p2("Steve Rambo", 8, &proj, PROGRAMMER, 32);
    std::vector<Employee*> e;
    e.push_back(&p1);
    e.push_back(&p2);
    TeamLeader t1("Van Darkholme", 1, &proj, TEAMLEADER, 128, &e);
    EXPECT_EQ(t1.calcProgrammers(), 2);
}

TEST(Test, test3) {
    Project proj;
    proj.setBudget(1000000);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("Google Testing System 2021");
    Programmer p1("Mark Wolf", 8, &proj, TESTER, 64);
    Programmer p2("Steve Rambo", 8, &proj, TESTER, 32);
    std::vector<Employee*> e;
    e.push_back(&p1);
    e.push_back(&p2);
    TeamLeader t1("Billy Herrington", 1, &proj, TEAMLEADER, 128, &e);
    EXPECT_EQ(t1.calcProgrammers(), 0);
}

TEST(Test, test4) {
    Project p1;
    p1.setPid();
    Driver d1("Dalnoboyshik", 12, &p1, DRIVER, 20);
    d1.calc(3);
    EXPECT_EQ(d1.getPayment(), 60);
}

TEST(Test, test5) {
    Project p1;
    p1.setPid();
    Cleaner d1("Robocleaner", 12, &p1, DRIVER, 150);
    d1.calc(5);
    EXPECT_EQ(d1.getPayment(), 750);
}

TEST(Test, test6) {
    Project p1;
    p1.setPid();
    Driver d1("Dalnoboyshik-1", 12, &p1, DRIVER, 15);
    d1.calcBonus(2);
    EXPECT_EQ(d1.getPayment(), 30);
}

TEST(Test, test7) {
    Project p1;
    p1.setPid();
    Cleaner d1("Robocleaner-v2", 12, &p1, DRIVER, 10);
    d1.calcBonus(10);
    EXPECT_EQ(d1.getPayment(), 100);
}

TEST(Test, test8) {
    Project proj;
    proj.setBudget(10000000);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("HSE Snow Wars");
    Programmer p1("Snowman number one", 8, &proj, PROGRAMMER, 64);
    Programmer p2("Boss of the forest", 16, &proj, PROGRAMMER, 32);
    Programmer p3("Snowball master", 4, &proj, PROGRAMMER, 16);
    std::vector<Employee*> e;
    e.push_back(&p1);
    e.push_back(&p2);
    e.push_back(&p3);
    TeamLeader t1("DED MOROZ", 1, &proj, TEAMLEADER, 128, &e);
    t1.calc();
    EXPECT_EQ(t1.getPayment(), 3);
}

//TEST(Test, test9) {
//    EXPECT_EQ();
//}
//
//TEST(Test, test10) {
//    EXPECT_EQ();
//}
//
//TEST(Test, test11) {
//    EXPECT_EQ();
//}
//
//TEST(Test, test12) {
//    EXPECT_EQ();
//}
//
//TEST(Test, test13) {
//    EXPECT_EQ();
//}
//
//TEST(Test, test14) {
//    EXPECT_EQ();
//}
//
//TEST(Test, test15) {
//    EXPECT_EQ();
//}
