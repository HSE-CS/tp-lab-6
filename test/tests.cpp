// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Personal.h"

TEST(Employee, Constructor) {
  auto *employee = new Personal(1, "Ivan", "SEO of Feminism", 2);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(Driver, Constructor) {
  auto *employee = new Driver(1, "Ivan", "SEO of Feminism", 2);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(Cleaner, Constructor) {
  auto *employee = new Cleaner(1, "Ivan", "SEO of Feminism", 2);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getSalary(), 0);
}

TEST(Employee, ProjectManager) {
  Project *project = new Project(1, 200);
  auto *employee = new ProjectManager(1, "Ivan", "SEO of Feminism", 2, project);
  EXPECT_EQ(employee->getPayment(), 2);
}

TEST(Employee, SeniorManager) {
  Project *project = new Project(1, 400);
  Project *project2 = new Project(2, 400);
  std::vector<Project *> projects;
  projects.push_back(project);
  projects.push_back(project2);
  auto *employee = new SeniorManager(
      1, "Ivan", "SEO of Feminism", 2, project, projects);
  EXPECT_EQ(employee->getPayment(), 2);
  EXPECT_EQ(employee->getProjects().size(), 2);
}
