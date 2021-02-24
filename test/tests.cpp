// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

#include <string>

#include "Employee.h"
#include "Engineer.h"
#include "Factory.h"
#include "Manager.h"
#include "Personal.h"

TEST(TestStaff, Test_1_id) {
  Driver* emp = new Driver(42, "Vasya", "Driver", 500, 8);
  EXPECT_EQ(42, emp->getId());
}

TEST(TestStaff, Test_2_name) {
  Driver* emp = new Driver(42, "Vasya", "Driver", 500, 8);
  EXPECT_EQ("Vasya", emp->getName());
}

TEST(TestStaff, Test_3_position) {
  Driver* emp = new Driver(42, "Vasya", "Driver", 500, 8);
  EXPECT_EQ("Driver", emp->getPosition());
}

TEST(TestStaff, Test_4_salary) {
  Driver* emp = new Driver(42, "Vasya", "Driver", 500, 8);
  EXPECT_EQ(500, emp->getSalary());
}

TEST(TestStaff, Test_5_worktime) {
  Driver* emp = new Driver(42, "Vasya", "Driver", 500, 8);
  EXPECT_EQ(8, emp->getWorktime());
}

TEST(TestStaff, Test_6_payment) {
  Driver* emp = new Driver(42, "Vasya", "Driver", 500, 8);
  int sum = emp->calc();
  EXPECT_EQ(4000, emp->getPayment());
}

TEST(TestStaff, Test_7_project_name) {
  Project project = {6, "tp-lab # 6", 1707};
  EXPECT_EQ("tp-lab # 6", project.name);
}

TEST(TestStaff, Test_8_project_id) {
  Project project = {6, "tp-lab # 6", 1707};
  EXPECT_EQ(6, project.id);
}

TEST(TestStaff, Test_9_project_budget) {
  Project project = {6, "tp-lab # 6", 1707};
  EXPECT_EQ(1707, project.budget);
}

TEST(TestStaff, Test_10_calcBase) {
  Project pr = {100, "lab # 6", 100000};
  Tester* emp = new Tester(10, "Pupkin", "Tester", 1000, 9, &pr, 5);
  emp->setSalary(1000);
  int sum = emp->calcBase(emp->getPayment(), emp->getWorktime());
  EXPECT_EQ(9000, sum);
}

TEST(TestStaff, Test_11_calcBudgetPart) {
  Project pr = {100, "lab # 6", 100000};
  Tester* emp = new Tester(10, "Pupkin", "Tester", 1000, 9, &pr, 10);
  emp->setSalary(1000);
  int sum = emp->calcBudgetPart(emp->getPart(), pr.budget);
  EXPECT_EQ(100000 / 10, sum);
}

TEST(TestStaff, Test_12_calcProAdditions) {
  Project pr = {100, "lab # 6", 100000};
  Tester* emp = new Tester(10, "Pupkin", "Tester", 1000, 9, &pr, 10);
  emp->setSalary(1000);
  int sum = emp->calcProAdditions();
  EXPECT_EQ(1000 * 9 / 15, sum);
}

TEST(TestStaff, Test_13_calc) {
  Project pr = {100, "lab # 6", 100000};
  Tester* emp = new Tester(10, "Pupkin", "Tester", 1000, 9, &pr, 10);
  emp->setSalary(1000);
  int sum = emp->calc();
  EXPECT_EQ(9000 + 100000 / 10 + 1000 * 9 / 15, sum);
}

TEST(TestStaff, Test_14_ProjectManager_calcHeads) {
  std::vector<Project*> projects;
  Project lab = {100, "lab # 6", 1707};
  Project lstm = {101, "LSTM model", 200000};
  projects.push_back(&lab);
  projects.push_back(&lstm);
  ProjectManager* manager = new ProjectManager(
      228, "Ivan Dobryaev", "Project Manager", 2, 80000, 8, projects, 3);

  EXPECT_EQ(100000, manager->calcHeads());
}

TEST(TestStaff, Test_15_ProjectManager_calcProAdditions) {
  std::vector<Project*> projects;
  Project lab = {100, "lab # 6", 1707};
  Project lstm = {101, "LSTM model", 200000};
  projects.push_back(&lab);
  projects.push_back(&lstm);
  ProjectManager* manager = new ProjectManager(
      228, "Ivan Dobryaev", "Project Manager", 2, 80000, 8, projects, 3);

  EXPECT_EQ(1707 * 0.05 + 200000 * 0.05, manager->calcProAdditions());
}
