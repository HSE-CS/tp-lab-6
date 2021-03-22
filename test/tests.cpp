// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "Personal.h"
#include <Engineer.h>
#include <Factory.h>
#include "Manager.h"

TEST(staff_test, test1) {
Programmer programmer = Programmer(1, "Aax", PROGRAMMER, 500);
EXPECT_EQ(1, programmer.getId());
}

TEST(staff_test, test2) {
Programmer programmer = Programmer(1, "Alex", PROGRAMMER, 500);
EXPECT_EQ("Alex", programmer.getName());
}

TEST(staff_test, test3) {
Programmer programmer = Programmer(1, "Alex", PROGRAMMER, 500);
programmer.setWorkTime(10);
programmer.calc();
EXPECT_EQ(5000, programmer.getPayment());
}

TEST(staff_test, test4) {
Programmer programmer = Programmer(1, "Alex", PROGRAMMER, 500);
programmer.setWorkTime(10);
programmer.setBonus(3000);
programmer.calc();
EXPECT_EQ(8000, programmer.getPayment());
}

TEST(staff_test, test5) {
Driver driver = Driver(1, "Vasya", DRIVER, 300);
driver.setNightHours(10);
driver.setWorkTime(100);
driver.calc();

EXPECT_EQ(36000, driver.getPayment());
}

TEST(project_test, test6) {
Project project = Project(1, "Vzlom Pentagona");
EXPECT_EQ("Vzlom Pentagona", project.getName());
}

TEST(project_test, test7) {
Project project = Project(1, "Vzlom Pentagona");
project.setBudget(1000000);
EXPECT_EQ(1000000, project.getBudget());
}

TEST(project_test, test8) {
Project project = Project(1, "Vzlom Pentagona");
project.setBudget(1000000);
Tester tester = Tester(124, "qowhf", TESTER, 999);
tester.setProject(project);
EXPECT_EQ(1, project.getNumberOfArticipants());
}

TEST(project_test, test9) {
Project project = Project(1, "Vzlom Pentagona");
project.setBudget(1000000);
Tester tester = Tester(124, "qowhf", TESTER, 999);
tester.setProject(project);
EXPECT_EQ("Vzlom Pentagona", tester.getProject().getName());
}

TEST(management_test, test10) {
Project project1 = Project(0, "Project1");
project1.setBudget(100000);
Project project2 = Project(2, "Ne Project");
project1.setBudget(50000);

SeniorManager seniorManager = SeniorManager(1, "Igor", SENIOR_MANAGER);
seniorManager.addProject(project1);
seniorManager.addProject(project2);
seniorManager.setPartOfTheProject(0.1);
seniorManager.calc();
EXPECT_EQ(5000, seniorManager.getPayment());
}

TEST(management_test, test11) {
Project project1 = Project(0, "Project1");
project1.setBudget(100000);
Project project2 = Project(2, "Ne Project");
project1.setBudget(50000);

SeniorManager seniorManager = SeniorManager(1, "Igor", SENIOR_MANAGER);
seniorManager.addProject(project1);
seniorManager.addProject(project2);
seniorManager.setPartOfTheProject(0.1);
seniorManager.calc();

EXPECT_EQ(0.1, seniorManager.getPartOfTheProject());
}

TEST(management_test, test13) {
Project project1 = Project(0, "Project1");
project1.setBudget(100000);
Project project2 = Project(2, "Ne Project");
project1.setBudget(50000);
Tester tester = Tester(2, "Petr", TESTER, 400);
Tester tester2 = Tester(3, "Alex", TESTER, 400);
tester.setProject(project1);
tester.setProject(project2);

SeniorManager seniorManager = SeniorManager(1, "Igor", SENIOR_MANAGER);
seniorManager.addProject(project1);
seniorManager.addProject(project2);
seniorManager.setPartOfTheProject(0.1);
seniorManager.calc();

EXPECT_EQ(7000, seniorManager.getPayment());
}
