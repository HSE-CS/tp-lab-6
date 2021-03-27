// Copyright 2021 asma
#include <gtest/gtest.h>
#include <string>

#include "Engineer.h"
#include "Employee.h"
#include "Project.h"
#include "Manager.h"
#include "Personal.h"

TEST(EmployeesTest, test1) {
    Project* project = new Project(1, 10000, 0);
    Programmer employee(111, "TestName",
        Position::PROGRAMMER, 10000, project, 0.1);
    employee.SetWorkTime(1);
    employee.Calc();
    EXPECT_EQ(11200, employee.GetPayment());
}

TEST(EmployeesTest, test2) {
    Project* project = new Project(1, 10000, 0);
    Engineer employee(111, "TestName", Position::ENGINEER, 10000, project, 0.1);
    employee.SetWorkTime(1);
    employee.Calc();
    EXPECT_EQ(11000, employee.GetPayment());
}

TEST(EmployeesTest, test3) {
    Project* project = new Project(1, 10000, 0);
    Tester employee(111, "TestName", Position::TESTER, 10000, project, 0.1);
    employee.SetWorkTime(1);
    employee.Calc();
    EXPECT_EQ(10800, employee.GetPayment());
}

TEST(EmployeesTest, test4) {
    Project* project = new Project(1, 10000, 0);
    TeamLeader employee(111, "TestName",
        Position::TEAMLEADER, 10000, project, 0.1);
    employee.SetWorkTime(1);
    employee.Calc();
    EXPECT_EQ(21000, employee.GetPayment());
}

TEST(EmployeesTest, test5) {
    Project* project = new Project(1, 10000, 0);
    ProjectManager employee(111, "TestName",
        Position::PROJECTMANAGER, project, 0.1);
    employee.SetWorkTime(1);
    employee.Calc();
    EXPECT_EQ(6000, employee.GetPayment());
}

TEST(EmployeesTest, test6) {
    Project* project = new Project(1, 10000, 111);
    std::vector<Project*> projects = { project };
    SeniorManager employee(111, "TestName", Position::SENIORMANAGER, projects);
    employee.SetWorkTime(1);
    employee.Calc();
    EXPECT_EQ(6000, employee.GetPayment());
}

TEST(EmployeesTest, test7) {
    Driver employee(111, "TestName", Position::DRIVER, 10000);
    employee.SetWorkTime(1);
    employee.Calc();
    EXPECT_EQ(10100, employee.GetPayment());
}

TEST(EmployeesTest, test8) {
    Cleaner employee(111, "TestName", Position::CLEANER, 10000);
    employee.SetWorkTime(1);
    employee.Calc();
    EXPECT_EQ(10000, employee.GetPayment());
}

TEST(EmployeesTest, test9) {
    Cleaner employee(111, "TestName", Position::CLEANER, 10000);
    EXPECT_EQ(0, employee.GetPayment());
}

TEST(EmployeesTest, test10) {
    Cleaner employee(111, "TestName", Position::CLEANER, 10000);
    EXPECT_EQ(111, employee.GetId());
}
