// Copyright 2021 Nikita Naumov

#include <gtest/gtest.h>
#include <string>
#include "Personal.h"
#include "Programmer.h"
#include "Manager.h"
#include "Tester.h"
#include "TeamLeader.h"
#include "Project.h"

TEST(Test, test1) {
    Driver driverObj(0, "Name1");
    unsigned expected = driverObj.getPosition();
    EXPECT_EQ(expected, 2);
}
TEST(Test, test2) {
    Driver driverObj(0, "Name1");
    unsigned expected = driverObj.getSalaryPerHour();
    EXPECT_EQ(expected, 0);
}
TEST(Test, test3) {
    Driver driverObj(0, "Name1");
    driverObj.setSalaryPerHour(250);
    driverObj.setWorkTime(10);
    driverObj.calc();
    unsigned expected = driverObj.getPayment();
    EXPECT_EQ(expected, 2500);
}
TEST(Test, test4) {
    Cleaner cleanerObj(0, "Name1");
    cleanerObj.setSalaryPerHour(100);
    cleanerObj.setWorkTime(10);
    unsigned exp = cleanerObj.calcBase(cleanerObj.getSalaryPerHour(),
                                       cleanerObj.getCurrentWorktime());
    EXPECT_EQ(exp, 1000);
}
TEST(Test, test5) {
    Cleaner cleanerObj(0, "Name1");
    cleanerObj.setSalaryPerHour(100);
    cleanerObj.setWorkTime(10);
    cleanerObj.calc();
    EXPECT_EQ(cleanerObj.getPayment(), 1000);

}
TEST(Test, test6) {
    Programmer programmerObj(0, "Name1");
    programmerObj.setWorkTime(100);
    programmerObj.setSalaryPerHour(250);
    Project* exp = programmerObj.getProjectLink();
    EXPECT_EQ(exp, nullptr);
}
TEST(Test, test7) {
    Programmer programmerObj(0, "Name1");
    programmerObj.setWorkTime(100);
    programmerObj.setSalaryPerHour(250);
    Project projectObj(0, 10000);
    programmerObj.setProject(&projectObj);
    EXPECT_EQ(programmerObj.getProjectLink(), &projectObj);
}
TEST(Test, test8) {
    ProjectManager pmObj(0, "Name");
    Programmer progObj(1, "name2");
    Project proj(0, 10000);
    progObj.setProject(&proj);
    pmObj.setProject(&proj);
    EXPECT_EQ(proj.getNumberOfMembers(), 2);
}
TEST(Test, test9) {
    ProjectManager pmObj(0, "Name");
    pmObj.setWorkTime(50);
    EXPECT_EQ(pmObj.getCurrentWorktime(), 50);
}
TEST(Test, test10) {
    SeniorManager senpmObj(0, "Name");
    Project pr1(0, 100);
    Project pr2(1, 101);
    senpmObj.setProject(&pr1);
    senpmObj.setProject(&pr2);
    EXPECT_EQ(senpmObj.getProjQuantity(), 2);
}
TEST(Test, test11) {
    Tester testerObj(0, "Name");
    testerObj.setSalaryPerHour(200);
    testerObj.setWorkTime(100);
    unsigned exp = testerObj.calcBase(testerObj.getSalaryPerHour(),
                                      testerObj.getCurrentWorktime());
    EXPECT_EQ(exp, 20000);
}
TEST(Test, test12) {
    Tester testerObj(0, "name");
    int exp = testerObj.getPosition();
    EXPECT_EQ(exp, 7);
}
TEST(Test, test13) {
    TeamLeader tlObj(0, "Name");
    tlObj.setWorkTime(50);
    tlObj.setSalaryPerHour(300);
    int exp = tlObj.calcBase(tlObj.getSalaryPerHour(),
                             tlObj.getCurrentWorktime());
    EXPECT_EQ(exp, 15000);
}
TEST(Test, test14) {
    TeamLeader tlObj(0, "Name");
    tlObj.setWorkTime(50);
    tlObj.setSalaryPerHour(300);
    Project pr1(0, 1000);
    tlObj.setProject(&pr1);
    EXPECT_EQ(tlObj.getProjectLink(), &pr1);
}
TEST(Test, test15) {
    TeamLeader tlObj(0, "Name");
    Tester testerObj(1, "name1");
    SeniorManager senpmObj(2, "Name2");
    Programmer programmerObj(3, "Name3");
    Project pr1(0, 100000);
    tlObj.setProject(&pr1);
    testerObj.setProject(&pr1);
    senpmObj.setProject(&pr1);
    programmerObj.setProject(&pr1);
    int exp = programmerObj.calcBudgetPart();
    EXPECT_EQ(exp, 25000);
}




