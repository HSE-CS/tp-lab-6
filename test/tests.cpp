// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include "Employee.h"

TEST(test_cleaner, test1) {
    Cleaner employee(1, "Igor", Position::DRIVER, 20);
    employee.setWorkTime(20);
    std::string name = employee.getName();
    EXPECT_EQ("Igor", name);
}

TEST(test_cleaner, test2) {
    Cleaner employee(1, "Igor", Position::DRIVER, 20);
    employee.setWorkTime(20);
    int position = int(employee.getPosition());
    EXPECT_EQ(position, 1);
}

TEST(test_cleaner, test3) {
    Cleaner employee(1, "Igor", Position::DRIVER, 20);
    employee.setWorkTime(20);
    int time =  employee.getWorktime();
    EXPECT_EQ(time, 20);
}

TEST(test_cleaner, test4) {
    Cleaner employee(1, "Igor", Position::DRIVER, 20);
    employee.setWorkTime(20);
    int payment =  employee.getPayment();
    EXPECT_EQ(payment, 600);
}

TEST(test_manager, test5) {
    ProjectManager employee(1, "Ivan", Position::PROJECT_MANAGER, 30);
    employee.setWorkTime(20);
    int payment =  employee.getPayment();
    EXPECT_EQ(payment, 69000);
}

TEST(test_manager, test6) {
    ProjectManager employee(1, "Ivan", Position::PROJECT_MANAGER, 30);
    employee.setWorkTime(20);
    std::string name  =  employee.getName();
    EXPECT_EQ(name, "Ivan");
}

TEST(test_manager, test7) {
    ProjectManager employee(1, "Ivan", Position::PROJECT_MANAGER, 30);
    employee.setWorkTime(20);
    int time =  employee.getWorktime();
    EXPECT_EQ(time, 20);
}

TEST(test_manager, test8) {
    ProjectManager employee(1, "Ivan", Position::PROJECT_MANAGER, 30);
    employee.setWorkTime(20);
    int position =  int(employee.getPosition());
    EXPECT_EQ(position, 2);
}

TEST(test_lead, test9) {
    TeamLead employee(1, "Max", Position::TEAM_LEAD,"name of project", 1200);
    employee.setWorkTime(10);
    int position =  int(employee.getPosition());
    EXPECT_EQ(position, 7);
}

TEST(test_lead, test10) {
    TeamLead employee(1, "Max", Position::TEAM_LEAD,"name of project", 1200);
    employee.setWorkTime(10);
    std::string name =  employee.getName();
    EXPECT_EQ(name, "Max");
}

TEST(test_lead, test11) {
    TeamLead employee(1, "Max", Position::TEAM_LEAD,"name of project", 1200);
    employee.setWorkTime(10);
    int time =  employee.getWorktime();
    EXPECT_EQ(time, 10);
}

TEST(test_lead, test12) {
    TeamLead employee(1, "Max", Position::TEAM_LEAD,"name of project", 1200);
    employee.setWorkTime(10);
    int payment =  employee.getPayment();
    EXPECT_EQ(payment, 137000);
}

TEST(test_enginer, test13) {
    Engineer employee(1, "Denis", Position::ENGINEER,"name of project", 800);
    employee.setWorkTime(10);
    int payment =  employee.getPayment();
    EXPECT_EQ(payment, 18000);
}

TEST(test_enginer, test14) {
    Engineer employee(1, "Denis", Position::ENGINEER,"name of project", 800);
    employee.setWorkTime(10);
    int time =  employee.getWorktime();
    EXPECT_EQ(time, 10);
}

TEST(test_enginer, test15) {
    Engineer employee(1, "Denis", Position::ENGINEER,"name of project", 800);
    employee.setWorkTime(10);
    int position =  int(employee.getPosition());
    EXPECT_EQ(position, 4);
}
