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
    EXPECT_EQ(t1.getPayment(), 3000);
}

TEST(Test, test9) {
    Project proj;
    proj.setBudget(3600);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("DSC Meetup #0xfff");
    Programmer p1("DSC Core team 1", 8, &proj, PROGRAMMER, 1);
    Programmer p2("DSC Video Editor", 16, &proj, PROGRAMMER, 3);
    Programmer p3("DSC Company face", 4, &proj, PROGRAMMER, 6);
    std::vector<Employee *> e;
    e.push_back(&p1);
    e.push_back(&p2);
    e.push_back(&p3);
    ProjectManager pm1("DSC Lead", 120, &proj, PROJECTMANAGER, e);
    EXPECT_EQ(pm1.calcHeads(), 3);
}

TEST(Test, test10) {
    Project proj;
    proj.setBudget(3600);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("DSC Meetup #0x1000");
    Project gdgProj;
    gdgProj.setBudget(800000);
    gdgProj.setPid();
    gdgProj.setMemberCountToZero();
    gdgProj.setProjectName("GDG Meeting 2021");
    Programmer p1("CEO", 8, &proj, PROGRAMMER, 1);
    Programmer p2("Programmer speaker", 16, &gdgProj, PROGRAMMER, 3);
    Programmer p3("Manager", 4, &proj, PROGRAMMER, 6);
    std::vector<Employee *> e;
    e.push_back(&p1);
    e.push_back(&p2);
    e.push_back(&p3);
    ProjectManager pm1("GDG Boss", 64, &proj, PROJECTMANAGER, e);
    EXPECT_EQ(pm1.calcHeads(), 2);
}

TEST(Test, test11) {
    Project proj;
    proj.setBudget(10000);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("Yandex");
    Programmer p1("Typical Programmer", 855, &proj, PROGRAMMER, 1);
    p1.calc(24);
    EXPECT_EQ(p1.getPayment(), 24);
}

TEST(Test, test12) {
    Project proj;
    proj.setBudget(10000);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("Rambler");
    Programmer p1("Just a genius", 48, &proj, PROGRAMMER, 10);
    p1.calc(3);
    EXPECT_EQ(p1.getPayment(), 30);
}

TEST(Test, test13) {
    Project proj;
    proj.setBudget(10000);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("Google 2");
    Programmer p1("Lazy zoomer", 3, &proj, PROGRAMMER, 100);
    p1.calc(8);
    EXPECT_EQ(p1.getPayment(), 800);
}

TEST(Test, test14) {
    Project proj;
    proj.setBudget(3600);
    proj.setPid();
    proj.setMemberCountToZero();
    proj.setProjectName("DSC Meetup #0xfff");
    Project pr2;
    pr2.setProjectName("DSC StatUp V.3");
    Programmer p1("DSC Core team 1", 8, &pr2, PROGRAMMER, 1);
    Programmer p2("DSC Video Editor", 16, &proj, PROGRAMMER, 3);
    Programmer p3("DSC Company face", 4, &pr2, PROGRAMMER, 6);
    std::vector<Employee *> e;
    e.push_back(&p1);
    e.push_back(&p2);
    e.push_back(&p3);
    ProjectManager pm1("DSC Lead 20XX", 8, &proj, PROJECTMANAGER, e);
    EXPECT_EQ(pm1.calcHeads(), 1);
}

TEST(Test, test15) {
    Project p1;
    p1.setPid();
    Driver d1("DADYA TOLYA", 1245, &p1, DRIVER, 15);
    d1.calcBonus(10);
    EXPECT_EQ(d1.getPayment(), 150);
}
