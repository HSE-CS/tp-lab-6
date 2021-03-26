// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <Personal.h>
#include <Manager.h>
#include <Engineer.h>

TEST(testDriver, test1) {
    Driver driver1(0, "Abcd", 200);
    EXPECT_EQ("Abcd", driver1.getName());
}

TEST(testDriver, test2) {
Driver driver1(0, "Abcd", 200);
EXPECT_EQ(0, driver1.getId());
}

TEST(testDriver, test3) {
Driver driver1(0, "Abcd", 200);
EXPECT_EQ(200, driver1.getSalary());
}

TEST(testDriver, test4) {
Driver driver1(0, "Abcd", 200);
driver1.setWorkTime(160);
driver1.calc();
EXPECT_EQ(32000, driver1.getPayment());
}

TEST(testDriver, test5) {
Driver driver1(0, "Abcd", 200);
driver1.setWorkTime(160);
driver1.setAdditionalWorkTime(40);
driver1.calc();
EXPECT_EQ(40000, driver1.getPayment());
}

TEST(testCleaner, test6) {
Cleaner cleaner1(0, "Abcd", 200);
EXPECT_EQ("Abcd", cleaner1.getName());
}

TEST(testCleaner, test7) {
Cleaner cleaner1(0, "Abcd", 200);
EXPECT_EQ(0, cleaner1.getId());
}

TEST(testCleaner, test8) {
Cleaner cleaner1(0, "Abcd", 200);
EXPECT_EQ(200, cleaner1.getSalary());
}

TEST(testCleaner, test9) {
Cleaner cleaner1(0, "Abcd", 200);
cleaner1.setWorkTime(160);
cleaner1.calc();
EXPECT_EQ(32000, cleaner1.getPayment());
}

TEST(testProjectManager, test10) {
    Project project(0, 100000);
ProjectManager projectManager1(0, "Abcd", project);
EXPECT_EQ("Abcd", projectManager1.getName());
}

TEST(testProjectManager, test11) {
Project project(0, 100000);
ProjectManager projectManager1(0, "Abcd", project);
EXPECT_EQ(0, projectManager1.getId());
}

TEST(testProjectManager, test12) {
Project project(0, 100000);
ProjectManager projectManager1(0, "Abcd", project);
EXPECT_EQ(0, projectManager1.getProject().getId());
}

TEST(testProjectManager, test13) {
Project project(0, 100000);
ProjectManager projectManager1(0, "Abcd", project);
EXPECT_EQ(100000, projectManager1.getProject().getBudget());
}

TEST(testProjectManager, test14) {
Project project(0, 100000);
ProjectManager projectManager1(0, "Abcd", project);
projectManager1.calc();
EXPECT_EQ(21000, projectManager1.getPayment());
}

TEST(testSeniorManager, test15) {
Project project(0, 100000);
SeniorManager seniorManager1(0, "Abcd", project);
seniorManager1.calc();
EXPECT_EQ(26000, seniorManager1.getPayment());
}

TEST(testSeniorManager, test17) {
Project project(0, 100000);
SeniorManager seniorManager1(0, "Abcd", project);
EXPECT_EQ(0, seniorManager1.getId());
}

TEST(testSeniorManager, test18) {
Project project(0, 100000);
SeniorManager seniorManager1(0, "Abcd", project);
EXPECT_EQ("Abcd", seniorManager1.getName());
}

TEST(testSeniorManager, test19) {
Project project(0, 100000);
SeniorManager seniorManager1(0, "Abcd", project);
EXPECT_EQ(0, seniorManager1.getProject().getId());
}
